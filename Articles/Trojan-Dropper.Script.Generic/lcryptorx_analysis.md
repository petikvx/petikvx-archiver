
# Analysis of LCRYPTORX Ransomware

## Introduction

This script, written in **VBScript**, represents a full-fledged ransomware named **LCRYPTORX**. It performs a variety of malicious actions on the target Windows system: disables security mechanisms, achieves persistence via registry and scheduled scripts, encrypts user files, and prevents recovery by deleting backups. It also attempts to **download additional payloads** and blocks access to security websites.

**Language:** VBScript  
**File behavior:** File encryptor, ransomware payload, persistent system infection  
**Target OS:** Windows (including legacy systems)

## General Behavior

The malware exhibits the following general behaviors:

- Elevation of privileges using ShellExecute with 'runas'
- System modification: disables Task Manager, CMD, Regedit, Control Panel, and UAC
- Kills system and antivirus processes
- Encrypts user files recursively across standard folders and USB drives
- Drops ransom note (READMEPLEASE.txt)
- Changes desktop wallpaper via external image
- Downloads and executes further payloads from multiple remote servers
- Persists across reboots via registry keys and hidden files

## Technical Analysis

### Privilege Escalation
Relaunches the script with administrative privileges to bypass User Account Control (UAC).

### System Hardening Bypass
Disables Task Manager, Registry Tools, CMD, and UAC prompts by modifying registry policies.

### Kill System Tools and Antivirus
Kills a list of critical processes such as Taskmgr, CMD, msconfig, regedit.

### Persistence
Registers itself and companion scripts to run at system startup using multiple registry paths.

### Encryption Routine
Combines Caesar cipher (to obfuscate the key) and XOR cipher to encrypt file contents. Encrypted files are renamed with `.lcryx` extension.

### Self-Replication and Anti-Recovery
Writes payload directly to `\.\PhysicalDrive0`, suggesting potential MBR infection or sabotage.

### Delete Backups and Shadow Copies
Executes `vssadmin` and `wbadmin` commands to destroy system restore points and backup catalogs.

### Ransom Note
Creates `READMEPLEASE.txt` with ransom instructions demanding $500 in Bitcoin.

### Download and Execute Remote Files
Downloads additional payloads from hardcoded URLs and executes them.

### Block Access to Security Sites
Modifies `hosts` file to redirect known antivirus and security-related URLs to localhost.

## Techniques Used

### Persistence
- Registry keys in `HKLM` and `HKCU` under Run
- Multiple script files set to run indefinitely
- System file attributes set to hidden, system, and read-only

### Obfuscation
- Random key generation
- Caesar + XOR encryption layers
- Writes to raw disk sectors

### Defense Evasion
- Kills antivirus and system monitoring processes
- Blocks tools like Task Manager, Regedit, Control Panel
- Prevents access to security support websites

### Payload Deployment
- Contacts multiple C2 URLs to retrieve and execute binaries
- Possibly includes additional RATs or malware

### Destruction
- Deletes system backups and restore points
- Destroys files with `.bak`, `.old`, `.backup` extensions

### Coercion
- Wallpaper change
- Repeated alerts and popups
- Ransom note emphasizing urgency

## Conclusion

**LCRYPTORX** is a destructive and persistent ransomware. It combines encryption with system sabotage, multistage persistence, and aggressive user coercion. Its code is deliberately structured to avoid easy remediation, requiring complete system reinstallation in many cases.

## Indicators of Compromise (IOCs)

**File extension:** `.lcryx`  
**Dropped files:** `READMEPLEASE.txt`, `msvcr80.dll.bat`, `systemconfig.exe.vbs`, `advapi32_ext.vbs`  
**Registry keys:**  
- `HKCU\Software\Microsoft\Windows\CurrentVersion\Run\Anti-VirusScript`  
- `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\msvcr80dll`  
- `HKLM\SYSTEM\CurrentControlSet\Control\Keyboard Layout\Scancode Map`  
**Downloaded URLs:**  
- `http://185.172.128.203/TikTok.exe`  
- `http://5.42.64.17/files/setup.exe`  
- `http://cajgtus.com/files/1/build3.exe`  
- `http://103.198.26.173/360/HJC.exe`  
- `http://193.233.132.139/banda/gidro.exe`  
- `http://topgamecheats.dev/fud_new.exe`  
- `http://twizt.net/loadme.exe`  
- `http://163.5.215.125/amady.exe`
