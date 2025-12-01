# Trojan-Ransom.Win32.Xorist.lk - FASM Version

## ⚠️ IMPORTANT WARNING

This code is provided **FOR EDUCATIONAL PURPOSES ONLY** for the study of computer security and malware. Using this code for malicious purposes is **ILLEGAL** and may result in criminal prosecution.

**DO NOT COMPILE OR EXECUTE THIS CODE ON PRODUCTION SYSTEMS**

## Description

This document presents a rewrite of the Xorist.lk ransomware for FASM (Flat Assembler), with a clearer structure and English comments for easier understanding.

### Original file hash
- **SHA256**: `AFBD82DE1C80C8508B0CB6376E248393CC04B5276680C604D7DF1E56FB93CD26`
- **MD5**: `3359DFF8C8B3855E8CF980539E7FB300`

## Improvements over IDA code

### 1. **Clear FASM structure**
- Proper FASM headers and directives
- Well-defined sections (`.data`, `.text`, `.idata`, `.rsrc`)
- Correct PE GUI format

### 2. **Understandable nomenclature**
- Replacement of IDA-generated names (`sub_401000`, `loc_401034`, etc.)
- Descriptive function names in English
- Variables with explicit names matching original IDA output

### 3. **Detailed comments**
- Explanation of each major function
- Documentation of algorithms used
- Notes on malware behavior

### 4. **Logical organization**
```
├── Data Section
│   ├── Configuration
│   ├── Messages and text
│   ├── Buffers and variables
│   └── Structures
├── Code Section
│   ├── Entry point (start)
│   ├── Initialization
│   ├── Key generation
│   ├── Ransom note creation
│   ├── Wallpaper modification
│   ├── File enumeration
│   └── Encryption/Decryption
└── Import Section
    └── Windows DLLs (kernel32, user32, etc.)
```

## Main features

### 1. **Initialization**
```asm
initialize_program:
    - Generate encryption key with RDTSC
    - Configure error mode
    - Get heap handle
```

### 2. **Random key generation**
```asm
generate_encryption_key:
    - Uses RDTSC instruction (Time Stamp Counter)
    - Generates 16 random bytes
    - Stores in dword_406595
```

### 3. **Ransom note creation**
```asm
create_ransom_note_in_startup:
    - Retrieves startup folder (CSIDL_STARTUP)
    - Creates "HOW TO DECRYPT FILES.txt"
    - Writes ransom message
```

### 4. **Desktop wallpaper change**
```asm
change_desktop_wallpaper:
    - Extracts image from resources
    - Generates random temporary filename
    - Sets as wallpaper with SystemParametersInfoA
```

### 5. **File enumeration**
```asm
start_file_encryption:
    - Traverses all logical drives (A: to Z:)
    - Searches recursively through folders
    - Applies encryption to targeted files
```

### 6. **Encryption algorithm**
```asm
simple_xor_cipher:
    - Simple XOR encryption
    - Uses key derived from filename
    - Key rotation for each byte
```

## Compiling with FASM

```bash
# FASM installation (Linux)
wget https://flatassembler.net/fasm-1.73.30.tgz
tar -xzf fasm-1.73.30.tgz
cd fasm

# Compilation
./fasm Xorist_FASM.asm Xorist.exe
```

### Prerequisites
- FASM 1.73 or higher
- `win32ax.inc` file (included with FASM)
- Windows environment or Wine for execution

## Technical analysis

### Windows APIs used

#### Kernel32.dll
- `CreateFileA` - Open/create files
- `ReadFile/WriteFile` - Read/write operations
- `GetLogicalDrives` - Enumerate drives
- `FindFirstFileA/FindNextFileA` - File search
- `MoveFileA` - Rename encrypted files

#### User32.dll
- `MessageBoxA` - Display messages
- `SystemParametersInfoA` - Change wallpaper
- `PeekMessageA` - Process Windows messages

#### Shell32.dll
- `SHGetSpecialFolderPathA` - Get special folders

#### Shlwapi.dll
- `PathAddBackslashA` - Manipulate paths
- `PathFindExtensionA` - Find extensions
- `PathMatchSpecA` - Match patterns

### Encryption techniques

The ransomware uses simple XOR encryption with the following characteristics:

1. **Key generation**: RDTSC (CPU counter)
2. **Derivation**: XOR with filename + rotation
3. **Application**: Byte-by-byte XOR with key rotation

```
Initial key: [K0, K1, K2, ..., K15]
Seed: First character of filename
Derived key: K'i = Ki XOR (seed ROL i)
Encryption: Ci = Pi XOR K'(i mod 16)
```

### Behavior

1. **First execution**:
   - Generates random encryption key
   - Creates ransom note in startup folder
   - Changes desktop wallpaper
   - Encrypts all files with target extension
   - Displays warning message

2. **Targeted files**:
   - All files according to configuration
   - Ignores system files
   - Ignores its own ransom note
   - Adds `.locked` extension (configurable)

3. **After encryption**:
   - Preserves original timestamps
   - Renames files
   - Displays ransom instructions

## Configuration

Modifiable variables in `.data` section:

```asm
byte_40752B                    db 1    ; Show messagebox (0/1)
byte_40752A                    db 1    ; Create ransom note (0/1)
byte_40752C                    db 0    ; Use encryption (0/1)
byte_40752D                    db 1    ; Custom extension (0/1)
byte_406550                    db 2    ; Mode: 0=encrypt, 1=decrypt, 2=auto

lpSubKey                       db ".locked", 0  ; Added extension
aHowToDecryptFi                db "HOW TO DECRYPT FILES.txt", 0
```

## Differences with original IDA code

| Aspect | IDA Code | Rewritten FASM Code |
|--------|----------|---------------------|
| **Readability** | Generic names (`sub_401000`) | Descriptive names (`initialize_program`) |
| **Structure** | Linear, raw segments | Logically organized sections |
| **Comments** | Minimal | Detailed in English |
| **Imports** | Numeric references | Explicit imports with names |
| **Variables** | Memory addresses (`byte_40752B`) | Original IDA names preserved (`byte_40752B`) |
| **Syntax** | IDA syntax | Standard FASM syntax |

## Function example: Before/After

### Before (IDA)
```asm
sub_401000 proc near
push    1
push    10h
push    offset pszPath
push    0
call    SHGetSpecialFolderPathA
push    offset pszPath
call    sub_40103A
mov     al, byte_40752B
cmp     al, 1
jnz     short loc_401034
```

### After (FASM)
```asm
; Create ransom note in startup folder
create_ransom_note_in_startup:
    push    ebp
    mov     ebp, esp
    
    ; Get startup folder path
    invoke  SHGetSpecialFolderPathA, 0, pszPath, CSIDL_STARTUP, TRUE
    
    ; Create full path to the note
    invoke  lstrcpyA, FileName, pszPath
    invoke  PathAddBackslashA, FileName
    
    ; Check configuration
    cmp     [byte_40752D], 1
    je      .use_custom_name
```

## Protection and detection

### Signatures
This malware is detected by most antivirus software as:
- Trojan-Ransom.Win32.Xorist.lk
- Ransom:Win32/Xorist
- W32/Xorist

### Suspicious behaviors
- Wallpaper modification
- Massive file enumeration
- Ransom note creation
- Use of RDTSC for random generation
- Mass file renaming

### Indicators of Compromise (IOC)
- File: `HOW TO DECRYPT FILES.txt` in startup folder
- Extension: `.locked` added to files
- Modified wallpaper with ransom image
- Potential registry key (depending on variant)

## References

- **Kaspersky**: [Trojan-Ransom.Win32.Xorist](https://threats.kaspersky.com/en/threat/Trojan-Ransom.Win32.Xorist/)
- **FASM**: [Flat Assembler](https://flatassembler.net/)
- **Win32 API**: [Microsoft Documentation](https://docs.microsoft.com/en-us/windows/win32/api/)

## Author and license

- **Original analysis**: IDA Pro 9.0
- **Rewrite**: Educational version for FASM
- **Date**: January 2012 (original timestamp) / December 2025 (rewrite)
- **License**: Educational and security research purposes only

## Final warning

⚠️ **This code is REAL and DANGEROUS MALWARE**

- Do not compile this code without proper security measures
- Use only in an isolated environment (VM, sandbox)
- Do not distribute compiled binaries
- Respect local cybersecurity laws
- The author disclaims all responsibility for misuse

**For academic study only** - Understanding how ransomware works helps to better protect against it.
