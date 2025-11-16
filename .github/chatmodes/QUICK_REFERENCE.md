# Quick Reference Guide - Malware Analysis Chat Modes

## Which Chat Mode Should I Use?

### 🎯 By Malware Type

| Malware Type | Recommended Chat Mode | Reason |
|--------------|---------------------|---------|
| **DOS Virus (.com, .exe)** | `analyze-malware-asm-expert` | Assembly/machine code analysis |
| **Boot Sector Virus** | `analyze-malware-asm-expert` | Low-level x86 assembly |
| **Windows PE Binary (native)** | `analyze-malware-asm-expert` | Compiled binary analysis |
| **.NET Executable (.exe, .dll)** | `analyze-malware-dotnet-expert` | Managed code decompilation |
| **C# Malware** | `analyze-malware-dotnet-expert` | .NET framework analysis |
| **VB.NET Malware** | `analyze-malware-dotnet-expert` | .NET managed code |
| **Obfuscated .NET** | `analyze-malware-dotnet-expert` | ConfuserEx, .NET Reactor |
| **Batch Script (.bat, .cmd)** | `analyze-malware-script-expert` | CMD scripting analysis |
| **VBScript (.vbs, .vbe)** | `analyze-malware-script-expert` | WSH scripting analysis |
| **PowerShell (.ps1)** | `analyze-malware-script-expert` | PowerShell cmdlet analysis |
| **JavaScript (.js, .jse)** | `analyze-malware-script-expert` | JS/ActiveX analysis |
| **HTA/WSF files** | `analyze-malware-script-expert` | Hybrid script analysis |
| **Office Macros (VBA)** | `analyze-malware-script-expert` | Similar to VBScript |
| **Python/PHP/Perl malware** | `analyze-malware-v4` | High-level scripting |

### 🎯 By Analysis Goal

| Goal | Best Chat Mode |
|------|---------------|
| Academic research paper | `analyze-malware-asm-expert` or `analyze-malware-script-expert` |
| Security conference talk | `analyze-malware-asm-expert` or `analyze-malware-script-expert` |
| Incident response report | `analyze-malware-script-expert` (for scripts) or `v4` |
| Quick threat assessment | `analyze-malware-v4` |
| YARA rule creation | `analyze-malware-asm-expert` or `analyze-malware-script-expert` |
| Deobfuscate scripts | `analyze-malware-script-expert` |
| Legacy DOS malware | `analyze-malware-asm-expert` |

### 🎯 By File Extension

```bash
.asm, .s          → analyze-malware-asm-expert
.com, .exe (DOS)  → analyze-malware-asm-expert
.exe (native PE)  → analyze-malware-asm-expert
.exe (.NET)       → analyze-malware-dotnet-expert (check for mscoree.dll)
.dll (.NET)       → analyze-malware-dotnet-expert
.cs, .vb, .fs     → analyze-malware-dotnet-expert (source code)
.bat, .cmd        → analyze-malware-script-expert
.vbs, .vbe        → analyze-malware-script-expert
.ps1, .psm1       → analyze-malware-script-expert
.js, .jse         → analyze-malware-script-expert
.wsf, .hta        → analyze-malware-script-expert
.py, .php, .pl    → analyze-malware-v4
```

**How to identify .NET executables:**
- Look for "mscoree.dll" import in PE headers
- Check for .NET metadata in file
- Use `file` command: should show ".NET assembly"

## Quick Start Commands

### Assembly Malware
```
@workspace /chatmode analyze-malware-asm-expert
Analyze the DOS virus at /path/to/virus.asm
```

### .NET Malware
```
@workspace /chatmode analyze-malware-dotnet-expert
Analyze the .NET executable at /path/to/malware.exe
```

### Script Malware
```
@workspace /chatmode analyze-malware-script-expert
Analyze the PowerShell script at /path/to/malware.ps1
```

### General Analysis
```
@workspace /chatmode analyze-malware-v4
Analyze this malware code: [paste code]
```

## Common Scenarios

### Scenario 1: Obfuscated PowerShell Script
**Problem:** You have a base64-encoded PowerShell one-liner from a phishing email

**Solution:**
```
@workspace /chatmode analyze-malware-script-expert
Decode and analyze this PowerShell command:
powershell -enc <base64_string>
```

**Why:** Script-expert mode includes complete deobfuscation capabilities

---

### Scenario 2: Old DOS COM File
**Problem:** You need to reverse engineer a 1990s DOS virus

**Solution:**
```
@workspace /chatmode analyze-malware-asm-expert
Analyze the COM file at /path/to/virus.com
Focus on: infection mechanism, payload, and stealth techniques
```

**Why:** ASM-expert mode specializes in low-level assembly analysis

---

### Scenario 3: VBScript Email Worm
**Problem:** You have a .vbs file that spreads via Outlook

**Solution:**
```
@workspace /chatmode analyze-malware-script-expert
Analyze the VBScript worm at /path/to/worm.vbs
Focus on: COM objects used, propagation method, and persistence
```

**Why:** Script-expert mode understands WSH, COM objects, and VBScript APIs

---

### Scenario 4: Batch File Dropper
**Problem:** You have a .bat file that downloads and executes malware

**Solution:**
```
@workspace /chatmode analyze-malware-script-expert
Analyze the batch dropper at /path/to/dropper.bat
```

**Why:** Script-expert mode can trace batch commands, downloads, and execution chains

---

### Scenario 5: Obfuscated .NET RAT
**Problem:** You have a .NET executable that appears obfuscated (ConfuserEx)

**Solution:**
```
@workspace /chatmode analyze-malware-dotnet-expert
Analyze this obfuscated .NET malware at /path/to/rat.exe
Focus on: deobfuscation, C2 protocol, and persistence mechanism
```

**Why:** DotNet-expert mode specializes in .NET decompilation, obfuscator detection, and managed code analysis

---

### Scenario 6: Agent Tesla Keylogger
**Problem:** You suspect a .NET info stealer (Agent Tesla variant)

**Solution:**
```
@workspace /chatmode analyze-malware-dotnet-expert
Analyze this suspected Agent Tesla sample at /path/to/sample.exe
Focus on: keylogging methods, data exfiltration, and anti-analysis techniques
```

**Why:** DotNet-expert mode knows common .NET malware families and their patterns

---

## Feature Matrix

| Feature | asm-expert | dotnet-expert | script-expert | v4 |
|---------|-----------|---------------|--------------|-----|
| **Input Types** |
| Assembly source | ✅ Primary | ❌ | ❌ | ❌ |
| Machine code | ✅ Primary | ❌ | ❌ | ❌ |
| .NET assemblies | ❌ | ✅ Primary | ❌ | ❌ |
| C#/VB.NET | ❌ | ✅ Primary | ❌ | ❌ |
| Batch scripts | ❌ | ❌ | ✅ Primary | ✅ Limited |
| VBScript | ❌ | ❌ | ✅ Primary | ✅ Limited |
| PowerShell | ❌ | ❌ | ✅ Primary | ✅ Limited |
| JavaScript | ❌ | ❌ | ✅ Primary | ✅ Limited |
| Python/PHP | ❌ | ❌ | ❌ | ✅ Primary |
| **Analysis Features** |
| Instruction-level | ✅ x86/x64 | ✅ IL/MSIL | ❌ | ❌ |
| Decompilation | ❌ | ✅ dnSpy/ILSpy | ❌ | ❌ |
| Deobfuscation | ❌ | ✅ ConfuserEx | ✅ Complete | ✅ Basic |
| P/Invoke analysis | ❌ | ✅ Detailed | ❌ | ❌ |
| COM object analysis | ❌ | ✅ | ✅ | ✅ |
| API call tracing | ✅ Low-level | ✅ .NET APIs | ✅ High-level | ✅ |
| Reflection analysis | ❌ | ✅ Detailed | ❌ | ❌ |
| MITRE ATT&CK | ✅ | ✅ | ✅ | ❌ |
| YARA rules | ✅ Binary | ✅ .NET | ✅ Script | ❌ |
| **Output** |
| Length | 2500-4000w | 2500-4000w | 2500-4000w | 1000-1200w |
| Detail level | Expert | Expert | Expert | Professional |
| Code excerpts | 5-8 | 5-8 | 5-8 | 3-5 |

## Tips for Best Results

### For Assembly Analysis
- Provide the full source code if available
- Mention target architecture (x86, x64, ARM)
- Specify DOS/Windows/Linux context
- Include any known virus names or families

### For .NET Analysis
- Provide the .exe or .dll file
- Mention if obfuscation is suspected
- Note any behavioral observations (keylogging, network activity)
- Include .NET framework version if known
- Specify which decompiler to prioritize (dnSpy, ILSpy)

### For Script Analysis
- Include the complete script (deobfuscated if you can)
- Mention execution context (user rights, OS version)
- Provide any network indicators observed
- Include related files if multi-stage

### For All Analyses
- Be specific about what you want to focus on
- Mention any time constraints (quick vs comprehensive)
- Specify output format needs (report, presentation, etc.)
- Include threat intelligence context if available

## Support

For issues or improvements to these chat modes:
1. Check the full documentation in `README.md`
2. Review example analyses in the `/Articles` directory
3. Submit feedback via GitHub issues

---

Last Updated: November 16, 2025
