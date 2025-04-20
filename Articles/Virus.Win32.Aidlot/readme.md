# 🧬 Malware Analysis Report: *Virus.Win32.Aidlot*

## Introduction

This report presents an in-depth analysis of a Windows malware sample known as `Virus.Win32.Aidlot`. The binary is a 32-bit PE executable, disassembled with IDA Pro. Based on the techniques used and structure, this sample appears to be a modular backdoor or bot client.

- **SHA256**: `9C7448159CD16BA85BAB1B198CEBF8B2DD476693E9593B378998D352808715B7`  
  ↳ [VirusTotal Report](https://www.virustotal.com/gui/file/9C7448159CD16BA85BAB1B198CEBF8B2DD476693E9593B378998D352808715B7)
- **Platform**: Windows 32-bit
- **Language**: x86 Assembly (likely compiled with Visual C++)

---

## General Behavior

The malware performs the following operations:

- Ensures single-instance execution using a Global Atom
- Creates synchronization primitives (mutex, event)
- Establishes an IPC mechanism using a Mailslot
- Spawns multiple threads with dynamic dispatch
- Maps memory and writes to files via `CreateFileMappingA`
- Dispatches binary commands received via the mailslot

---

## Technical Analysis

### Function: `InitInstanceAndSetupIPC` (formerly `loc_401000`)
```asm
push    0
call    ExitProcess                ; Exit if running

push    offset String              ; ".aiD properlly running"
call    GlobalFindAtomA            ; Check if Atom exists

call    GetLastError
or      eax, eax
jz      short loc_401000           ; If Atom exists, exit again

push    offset String
call    GlobalAddAtomA             ; Mark instance via Global Atom

; Create an Event object
push    offset Name                ; "e"
push    0                          ; bInitialState
push    0                          ; bManualReset
push    0                          ; lpEventAttributes
call    CreateEventA
mov     ds:hEvent, eax

; Create a named Mutex
push    offset aAidSynchMutex      ; "aid synch mutex"
push    0                          ; bInitialOwner
push    0                          ; lpMutexAttributes
call    CreateMutexA
mov     ds:hHandle, eax

; Create Mailslot "\\.\mailslot\aiD"
push    0                          ; lpSecurityAttributes
push    0FFFFFFFFh                 ; Infinite read timeout
push    258h                       ; Max message size = 600 bytes
push    offset aMailslotAid
call    CreateMailslotA
mov     ds:hFile, eax
```

> Initializes instance guards, event/mutex, and sets up a mailslot-based IPC channel.

---

### Function: `CreateAndDispatchThreads` (formerly `loc_4010F8`)
```asm
push    3                          ; Number of threads
mov     esi, offset off_40203B     ; Pointer to function table

loop_start:
push    offset NumberOfBytesWritten
push    0                          ; dwCreationFlags
push    0                          ; lpParameter
lodsd                              ; EAX ← [ESI], indirect call target
push    eax                        ; Thread function
push    0
push    0
call    CreateThread
dec     [esp+4+var_4]
jnz     short loop_start

push    0FFFFFFFFh
call    Sleep                      ; Infinite sleep
```

> Dynamically dispatches thread execution using indirect pointers (obfuscation). Main thread sleeps indefinitely after.

---

### Function: `MapAndWriteMemoryToFile` (formerly `loc_40149D`)
```asm
; Open file
push    0FFFFFFFFh
push    0
push    0
push    3                          ; OPEN_EXISTING
push    0
push    0
call    CreateFileA

; Create file mapping (size 0x1000)
push    eax                        ; File handle
push    0
push    1000h                      ; Size
push    4                          ; PAGE_READWRITE
push    0
call    CreateFileMappingA

; Map memory view
push    0
push    0
push    2                          ; FILE_MAP_WRITE
push    eax                        ; Mapping handle
call    MapViewOfFile

; Copy data to mapped memory
mov     ecx, 400h                  ; Length
mov     esi, offset data_source
rep movsb                         ; Fast byte-wise copy
```

> Memory-maps a file and copies data into it. Common for stealthy payload delivery without using WriteFile.

---

### Function: `ReceiveAndDispatchMailMessages` (formerly `loc_4012A7`)
```asm
lea     eax, [esp+Buffer]
push    eax
push    400h                       ; Buffer size
push    ds:hFile                   ; Mailslot handle
call    ReadFile

cmp     eax, 0
jz      short loc_4012A7           ; Retry on failure

call    DispatchMessage            ; Call message handler
jmp     short loc_4012A7           ; Loop
```

> Reads messages from mailslot and dispatches them using internal logic. Runs in an infinite loop.

---

### Function: `DispatchCommand` (formerly `loc_40132A`)
```asm
mov     eax, [esp+Buffer]
cmp     eax, 0x41414141            ; "AAAA"
jz      short HandleCommandA

cmp     eax, 0x42424242            ; "BBBB"
jz      short HandleCommandB

jmp     loc_4012A7
```

> Simple command dispatcher using 4-byte magic headers. Used to trigger functions or behaviors by message code.

---

### Function: `CleanupAndExit` (formerly `loc_401449`)
```asm
call    UnmapViewOfFile
call    CloseHandle                ; Mailslot handle
call    CloseHandle                ; Mutex
call    CloseHandle                ; Event
call    GlobalDeleteAtom           ; Remove instance atom
call    ExitProcess
```

> Final cleanup routine that releases all OS handles and removes the instance marker atom.

---

## Techniques Used

### 🔄 Persistence / Execution Guard
- Global Atom used as a stealthy instance marker
- Mutex `aid synch mutex` prevents concurrent executions

### 🎭 Obfuscation
- Indirect threading via `lodsd` and memory table
- Use of API abstraction and minimal static strings

### 📡 Communication
- IPC via named Mailslot (`\.\mailslotiD`)
- Binary command dispatch via message parsing

### 🧼 Cleanup
- All handles and memory mappings are cleaned before exit
- Global markers removed to cover traces

---

## Conclusion

`Virus.Win32.Aidlot` is a lightweight, modular backdoor that uses stealthy inter-process communication and dynamic code execution. It avoids classical persistence but maintains runtime stealth via mutexes and Global Atom. The use of indirect calls and mailslots makes it harder to detect and analyze statically.

> This malware is well-suited for lightweight C2 operations, payload staging, or as a loader component.

---

## Indicators of Compromise (IOCs)

| Type               | Value                                    |
|--------------------|-------------------------------------------|
| SHA256             | `9C7448159CD16BA85BAB1B198CEBF8B2DD476693E9593B378998D352808715B7` |
| Global Atom        | `.aiD properlly running`                  |
| Mutex Name         | `aid synch mutex`                         |
| Mailslot Path      | `\.\mailslotiD`                        |