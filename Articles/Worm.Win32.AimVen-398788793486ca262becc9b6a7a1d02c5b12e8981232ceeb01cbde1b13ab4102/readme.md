
# 🧬 Malware Analysis - AIMVEN Worm

## Introduction

The malware under analysis is a 32-bit Windows worm identified under several antivirus signatures as a file-infector or generic dropper. The file hash referenced (`398788793486ca262becc9b6a7a1d02c5b12e8981232ceeb01cbde1b13ab4102`) has been detected by multiple engines on [VirusTotal](https://www.virustotal.com/gui/file/398788793486ca262becc9b6a7a1d02c5b12e8981232ceeb01cbde1b13ab4102) with labels such as:

- **W32.Virus.AIMven!tr** (Fortinet)
- **Worm:Win32/AIMCopy** (Microsoft)
- **Win32/Injector.AIM.Variant** (ESET)
- **PE_Infector.AIM.gen** (TrendMicro)

This executable is written in **x86 Assembly using the TASM/TLINK toolchain** targeting the Windows PE32 architecture. It is designed to **self-replicate**, **inject code into PE files**, and **propagate through file system traversal**, mimicking characteristics of classic early 2000s worms, especially those associated with **AIM (AOL Instant Messenger)** spreading tactics.

The malware uses low-level Windows API calls (resolved dynamically via `GetProcAddress`) and directly manipulates Portable Executable (PE) structures to embed a payload and alter execution flow. It also uses **hardcoded file paths** and section names, indicating it may have been tailored for specific environments or legacy systems (e.g., references to `C:\PROGRA~1\AIM95` suggest older Windows platforms such as Windows 95/98/ME).

Its infection mechanism modifies the `.data` section or creates a new `.aim` section, extends the PE image size, and appends a payload that can recursively infect other executables or directories. Despite its dated approach, this worm shows a sophisticated grasp of Windows internals and stealthy persistence techniques.

## General Behavior

Once executed, the worm performs the following actions:

1. Extracts its own filename from the command line.
2. Copies itself to `C:\V.EXE`.
3. Hides the copied file.
4. Opens a predefined target file (`C:\PROGRA~1\AIM95\ICBMFT.OCM`).
5. Injects code into the target file's `.data` section (if present).
6. Appends its own payload at the end of the file.
7. Overwrites the entry point to redirect execution to the malicious payload.

## Technical Analysis

### Function: `start`
```asm
call GetCommandLineA
inc eax
mov esi, eax
mov edi, offset ExistingFileName
; Parses the current process's filename from the command line.
```

### File Copy & Concealment
```asm
push 1
push offset NewFileName
push offset ExistingFileName
call CopyFileA

push 4
push offset NewFileName
call SetFileAttributesA
; Copies the worm to C:\V.EXE and marks it as a hidden system file.
```

### PE Infection Routine
```asm
call CreateFileA
call GetFileSize
call GlobalAlloc
call ReadFile
; Reads the target file into memory for infection.
```

### PE Header Analysis
```asm
cmp word ptr [esi], 5A4Dh ; 'MZ' check
...
cmp dword ptr [esi], 4550h ; 'PE\0\0' check
; Validates the PE format of the file.
```

### Section Modification
```asm
cmp dword ptr [esi], 7461642Eh ; '.data'
jz short infect_section
; Locates the .data section for injection.
```

### Payload Injection
```asm
mov edi, BufferPtr
add edi, FileSize
mov esi, offset payload_start
mov ecx, payload_end - payload_start
rep movsb
; Appends the payload to the end of the file buffer.
```

### Write Changes
```asm
call SetFilePointer
call WriteFile
; Rewrites the infected file with the modified buffer.
```

### Payload: `payload_start`
```asm
pusha
mov edi, [esp+24h]
call [GetFileAttrAddr]
; Checks if the given argument is a file or directory.
```

### Recursive Infection
```asm
call infect_file
; If a directory is found, constructs a path and recursively infects.
```

### Function: `infect_file`
```asm
call [GetFileAttrAddr]
cmp eax, 10h
; Determines whether target is a directory or file.
```

### Function: `sub_infect_section`
```asm
mov esi, BufferPtr
...
mov [esi], HardcodedAddr1
mov [esi+4], HardcodedAddr2
; Injects jump points and saves original code locations.
```

## Techniques Used

### 🧬 PE Infection
- Direct parsing of the PE header and manipulation of its structure.
- Adds a new section with name `.aim` and injects the payload.

### 🪛 Code Injection
- Overwrites the entry point to redirect execution to the payload using hardcoded offsets.

### 🧅 Obfuscation
- The malware uses fixed memory offsets (e.g., `8494h`, `87D2h`) and jumps through manually inserted instructions.
- Hardcoded section names and jumps avoid dynamic detection.

### 🐛 Replication
- Copies itself to `C:\V.EXE` and recursively infects files/directories by checking file attributes.

### 🧩 API Resolution
```asm
call GetProcAddress
mov CopyFileAddr, eax
...
; Resolves Windows APIs at runtime dynamically.
```

### 💾 Stealth
- Uses `SetFileAttributesA` to mark the file as hidden.
- Injects into the `.data` section to avoid creating new sections if possible.

## Conclusion

This worm demonstrates a full cycle of **file infection** with **code injection**, **payload persistence**, and **self-replication**. It dynamically resolves required APIs and operates at a low level by modifying executable headers directly. Its payload structure and recursion allow it to propagate efficiently while hiding itself on disk.

To detect and mitigate this threat:
- Use a memory scanner to catch in-memory PE manipulations.
- Monitor unusual file modifications, especially in `.exe` files and PE headers.
- Block unauthorized usage of `CopyFileA`, `SetFileAttributesA`, and similar API calls.

## Indicators (IOCs)

- **Filename (copied)**: `C:\V.EXE`
- **Target file**: `C:\PROGRA~1\AIM95\ICBMFT.OCM`
- **Section added**: `.aim`
- **Injected function names**:
  - `CopyFileA`
  - `GetFileAttributesA`
  - `GlobalAlloc`
  - `GlobalFree`
- **Hardcoded addresses**:
  - `0x11C12000`
  - `0x11C12038`
