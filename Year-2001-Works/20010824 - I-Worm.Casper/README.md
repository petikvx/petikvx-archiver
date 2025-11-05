# Dissecting I‑Worm.Casper (2001): Outlook/VBScript harvesting with Simple MAPI send 🛠️🔍

> "This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes."

## Introduction

I‑Worm.Casper is a small Windows worm written in 32‑bit x86 assembly around August 2001. It targets legacy Windows environments (Win9x/ME/2000), installing itself into the Windows directory and persisting via a Run key. Its propagation relies on Microsoft Outlook: a VBScript stage harvests address book entries into a text file, and the native code parses that file and sends messages via Simple MAPI with an executable attachment. The sample also includes an old Win9x “hide from Ctrl+Alt+Del” trick and a cosmetic check for two contemporaneous worms that modified WSOCK32.DLL. Studying its source illuminates how compact assembly worms chained Windows APIs, scripting, and Simple MAPI to spread with minimal dependencies.

## Overview 🔍

- Platforms: Designed for Win9x/ME/2000 era; uses Win9x‑specific RegisterServiceProcess (no‑op on NT‑line).
- Installation: Copies itself to `%WinDir%\MsWinsock32.exe` and registers autorun: `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Winsock32 = %WinDir%\MsWinsock32.exe` via SHLWAPI’s `SHSetValueA`.
- Visibility: Attempts to hide as a “service” on Win9x (pre‑NT tasklist obfuscation).
- WSOCK32 check: Maps `%System%\Wsock32.dll` and shows a message if it appears patched by other worms (Happy/Icecubes); it does not modify the file.
- Email spread: Drops `C:\CasperMail.vbs`, which harvests Outlook addresses into `%WinDir%\CasperEMail.txt` ending with a `#` sentinel. Then the worm parses that file and calls `MAPISendMail` per address, attaching its executable under a benign display name.
- Social lures: Subject “Casper Tool Protect 1.00”; body claims to scan for WSOCK32‑infecting worms.

Key imports and helpers: `InternetGetConnectedState` (WININET) for online gating, `SHSetValueA` (SHLWAPI) for registry, `MAPISendMail` (MAPI32) for email, and `useful.inc` macros for string/argument ergonomics.

## Section 2 – Source Code Analysis 🧩

The assembly is structured into short procedures called from `Main_Worm`. Below we highlight four core routines with brief, inert excerpts and their impact.

### 2.1 Core logic: Win9x hide routine

Purpose: On Win9x, hide the process from the Ctrl+Alt+Del task list using `RegisterServiceProcess` if present.

```asm
; Casper.asm — Hide_Worm (inert excerpt)
Hide_Worm proc
    @pushsz "Kernel32.dll"
    callx GetModuleHandleA          ; resolve module base
    @pushsz "RegisterServiceProcess"
    push  eax
    callx GetProcAddress            ; get API pointer if present
    push  1                         ; RSP(1, pid=0) => hide
    push  0
    call  eax                       ; no effect on NT
    ret
Hide_Worm endp
```

Impact: Purely cosmetic on Win9x; harmless on NT where the function doesn’t exist. Analysts can flag `RegisterServiceProcess` resolution and the specific two‑argument call.

### 2.2 Persistence: file copy and SHSetValueA

Purpose: Copy the running image to `%WinDir%\MsWinsock32.exe` and persist via HKLM Run using SHLWAPI instead of the longer Advapi32 path.

```asm
; Casper.asm — Copy_Worm (persistence excerpt)
mov   edi, offset copy_name
push  edi
push  50
push  edi
callx GetWindowsDirectoryA          ; %WinDir%
; build "\MsWinsock32.exe" into copy_name (via stosd pattern)
; ...
push  8
push  edi                           ; data pointer (REG_SZ)
push  1                             ; REG_SZ
@pushsz "Winsock32"
@pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
push  80000002h                     ; HKLM
callx SHSetValueA
```

Impact: Creates a conventional autorun. Using SHLWAPI `SHSetValueA` is a compact persistence trick often seen in early 2000s samples. IOC: the exact Run value name and path.

### 2.3 Harvest stage: Outlook VBScript builder

Purpose: Drop and execute a VBScript that walks Outlook AddressLists, appending addresses to `%WinDir%\CasperEMail.txt` and writing a trailing `#` to mark end‑of‑list.

```vbs
' CasperMail.vbs — harvested addresses list (safe excerpt)
On Error Resume Next
Set Casper = CreateObject("Outlook.Application")
Set L = Casper.GetNameSpace("MAPI")
Set fs = CreateObject("Scripting.FileSystemObject")
Set c = fs.CreateTextFile(fs.GetSpecialFolder(0) & "\CasperEMail.txt")
c.Close
' ... iterate AddressLists/Entries and append P.Address ...
Set c = fs.OpenTextFile(fs.GetSpecialFolder(0) & "\CasperEMail.txt", 8, True)
c.WriteLine "#"     ' sentinel used by native parser
c.Close
```

Impact: No mail is sent from VBScript; it only collects addresses. Creation of `%WinDir%\CasperEMail.txt` is a reliable artifact. Blocking WSH or Outlook OOM would break this stage.

### 2.4 Parser and sender: Simple MAPI per address

Purpose: Wait until connected, parse the address file until `#`, and call `MAPISendMail` per non‑empty line, attaching the executable with a friendly name.

```asm
; Casper.asm — Scan_Mail (inert excerpt)
Scan_Mail:
    xor   edx, edx
    mov   edi, offset m_addr        ; output buffer
    push  edi
p_c: lodsb
    cmp   al, "#"                   ; end marker?
    je    FIN                        ; ExitProcess at end
    cmp   al, 0Dh                   ; newline => finalize
    je    entr1
    stosb                           ; accumulate
    jmp   p_c
entr1:
    xor   al, al
    stosb                           ; NUL‑terminate
    pop   edi
    call  Send_Mail                 ; MAPISendMail(&Message)
    jmp   Scan_Mail
```

Impact: The parser is minimal and stops at the `#` sentinel written by the VBScript. Each address line leads to one Simple MAPI mail. The attachment path is set to the original module path, but the display name is `Casper_Tool.exe`, aiding social engineering.

## Mitigation and Defense Strategies 🛡️

### Detection (Analyst focus)

- Registry IOC: `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Winsock32 = %WinDir%\MsWinsock32.exe`.
- File IOCs:
  - `%WinDir%\MsWinsock32.exe` (copy of the worm)
  - `%WinDir%\CasperEMail.txt` (harvested addresses with a trailing `#`)
  - Temporary `C:\CasperMail.vbs` (may be quickly deleted)
- API and behavior patterns:
  - Dynamic resolution of `RegisterServiceProcess` and `SHSetValueA`.
  - Use of `InternetGetConnectedState` to gate activity until online.
  - `MAPISendMail` with a single attachment and subject “Casper Tool Protect 1.00”.
- Email traits: Subject/body mention “Casper Tool Protect 1.00” and WSOCK32 checks; attachment display name `Casper_Tool.exe`.

### Prevention (Admin focus)

- Harden scripting and Outlook:
  - Restrict Windows Script Host (WSH) execution where unnecessary.
  - Enforce Outlook Object Model Guard and modern client protections to prevent programmatic sends.
- Application control: Allow‑list executables; block untrusted code from `%WinDir%` directories.
- Email gateway policies: Quarantine executable attachments and flag subjects matching the lure; strip double‑extension patterns.
- Least privilege: Prevent writes to Windows directories/Run keys by standard users on NT‑based systems.
- Egress controls: Limit SMTP/MAPI usage to sanctioned clients; monitor for anomalous bursts of outbound mail.

## Conclusion

Casper exemplifies early‑2000s email worms: a small x86 core, simple persistence via HKLM Run, a VBScript harvester, and Simple MAPI for delivery. Its Win9x “hide” routine and WSOCK32 inspection nod to that era’s ecosystem, while SHLWAPI‑based persistence shows compact engineering. Defenders can reliably detect Casper through its Run key, the `%WinDir%\CasperEMail.txt` artifact, API sequences (`RegisterServiceProcess`, `SHSetValueA`, `InternetGetConnectedState`, `MAPISendMail`), and the characteristic email lure. Blocking WSH/OOM automation and enforcing application allow‑listing would largely neutralize this family even on legacy systems.

_Analysis by Copilot — generated via the analyze‑malware Copilot mode._
