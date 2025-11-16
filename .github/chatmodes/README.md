# Malware Analysis Chat Modes

This directory contains specialized chat modes for analyzing malware with varying levels of detail and expertise.

## 📚 Documentation

- **[README.md](README.md)** - This file (complete documentation)
- **[QUICK_REFERENCE.md](QUICK_REFERENCE.md)** - Quick guide to choose the right mode
- **[EXPERT_MODES_COMPARISON.md](EXPERT_MODES_COMPARISON.md)** - Detailed comparison of expert modes

## Available Chat Modes

### 🔬 `analyze-malware-asm-expert.chatmode.md`

**Expert-level assembly malware analysis**

- **Target Audience:** Security researchers, reverse engineers, threat intelligence analysts
- **Output Length:** 2500-4000 words
- **Depth:** Publication-grade technical analysis
- **Code Focus:** Assembly language (x86/x64/ARM), machine code, low-level system calls
- **Features:**
  - In-depth disassembly analysis with instruction-level comments
  - MITRE ATT&CK technique mapping
  - IoC generation (file, behavioral, system-level)
  - YARA rule creation
  - Comprehensive mitigation strategies
  - Memory layout and data structure analysis
  
**Best for:**
- DOS/legacy malware analysis
- Binary reverse engineering
- Assembly language analysis
- Academic research and publications
- Security conference presentations

**Usage:**
```
@workspace /chatmode analyze-malware-asm-expert
Analyze the malware in [file path or directory]
```

---

### � `analyze-malware-dotnet-expert.chatmode.md` (NEW)

**Expert-level .NET malware analysis**

- **Target Audience:** .NET security researchers, reverse engineers, incident responders
- **Output Length:** 2500-4000 words
- **Depth:** Publication-grade technical analysis
- **Code Focus:** C#, VB.NET, F#, IL/MSIL, decompiled managed code
- **Features:**
  - Complete assembly decompilation and analysis
  - Obfuscation detection and reversal (ConfuserEx, .NET Reactor, etc.)
  - P/Invoke and native API interaction documentation
  - Reflection and dynamic loading analysis
  - .NET-specific YARA rules
  - PE metadata and assembly manifest analysis
  - Anti-debugging and anti-VM technique identification
  
**Best for:**
- Modern .NET RATs (Agent Tesla, AsyncRAT, NanoCore)
- .NET stealers and keyloggers
- Ransomware written in C#
- .NET droppers and loaders
- Obfuscated .NET assemblies
- Banking trojans using .NET

**Usage:**
```
@workspace /chatmode analyze-malware-dotnet-expert
Analyze the .NET malware at [file path]
```

---

### �📜 `analyze-malware-script-expert.chatmode.md` (NEW)

**Expert-level script malware analysis**

- **Target Audience:** SOC analysts, incident responders, script malware researchers
- **Output Length:** 2500-4000 words
- **Depth:** Publication-grade technical analysis
- **Code Focus:** Batch (.bat/.cmd), VBScript (.vbs), PowerShell (.ps1), JavaScript (.js), WSF, HTA
- **Features:**
  - Complete deobfuscation of encoded content
  - COM/ActiveX object analysis
  - PowerShell cmdlet and .NET method breakdown
  - Living-off-the-Land binaries (LOLBins) identification
  - Download cradle and fileless execution analysis
  - Script-specific YARA rules
  - Execution policy bypass techniques
  - AMSI bypass detection
  
**Best for:**
- Modern script-based malware (Emotet, ransomware droppers)
- PowerShell Empire/Cobalt Strike scripts
- VBScript worms and macros
- JavaScript downloaders and stagers
- Multi-stage script attacks
- Phishing attachment analysis

**Usage:**
```
@workspace /chatmode analyze-malware-script-expert
Analyze the script malware at [file path]
```

---

### 📝 `analyze-malware-v4.chatmode.md`

**Balanced analysis for modern malware**

- **Target Audience:** Security analysts, SOC teams, incident responders
- **Output Length:** 1000-1200 words
- **Depth:** Professional technical analysis
- **Code Focus:** High-level languages (Python, JavaScript, PowerShell, VBScript)
- **Features:**
  - Source code breakdown with explanations
  - Mitigation and defense strategies
  - Detection and prevention guidelines
  - Safe, inert code examples
  
**Best for:**
- Script-based malware (VBS, JS, PS1)
- Modern malware families (Emotet, Mirai, etc.)
- Quick professional analysis
- Incident response documentation

**Usage:**
```
@workspace /chatmode analyze-malware-v4
Analyze this malware: [paste code or file path]
```

---

### 📊 Previous Versions

- `analyze-malware-v3.chatmode.md` - Earlier iteration
- `analyze-malware-v2.chatmode.md` - Legacy version
- `analyze-malware.chatmode.md` - Original version

These are kept for historical reference but the newer versions are recommended.

---

## Quick Start Guide

### 1. Activate a Chat Mode

In GitHub Copilot Chat, type:
```
@workspace /chatmode analyze-malware-expert
```

### 2. Provide Malware Sample

**Option A - File path:**
```
Analyze the malware at /path/to/malware/sample.asm
```

**Option B - Paste code:**
```
Analyze this malware code:
[paste source code]
```

**Option C - Directory:**
```
Analyze all malware files in /path/to/malware/directory/
```

### 3. Review Output

The analysis will be saved as `README.md` in the same directory as the analyzed malware, or in `Articles/` if no source directory exists.

---

## Output Structure Comparison

| Section | asm-expert | dotnet-expert | script-expert | v4 |
|---------|------------|---------------|---------------|-----|
| Executive Summary | ✅ Detailed | ✅ Detailed + PE info | ✅ Detailed | ❌ Basic |
| Table of Contents | ✅ Full | ✅ Full | ✅ Full | ❌ No ToC |
| Technical Analysis | ✅ 1500-2500w | ✅ 1500-2500w | ✅ 1500-2500w | ✅ 400-500w |
| Code Excerpts | ✅ 5-8 ASM | ✅ 5-8 C#/IL | ✅ 5-8 scripts | ✅ 3-5 |
| Assembly Analysis | ✅ x86/x64 | ✅ IL/MSIL | ❌ N/A | ❌ Limited |
| Decompilation | ❌ N/A | ✅ dnSpy/ILSpy | ❌ N/A | ❌ N/A |
| Deobfuscation | ❌ N/A | ✅ ConfuserEx etc | ✅ Complete | ✅ Basic |
| P/Invoke Analysis | ❌ N/A | ✅ Detailed | ❌ N/A | ❌ N/A |
| MITRE ATT&CK | ✅ Mapped | ✅ Mapped | ✅ Mapped | ❌ No |
| IoC Generation | ✅ Binary | ✅ .NET-specific | ✅ Script | ✅ Basic |
| YARA Rules | ✅ Binary | ✅ .NET | ✅ Script | ❌ No |
| Mitigation | ✅ Detailed | ✅ .NET-focused | ✅ Script defenses | ✅ Brief |

---

## Safety and Ethics

All chat modes enforce strict safety guidelines:

- ✅ **Educational purpose disclaimer** required in all outputs
- ✅ **No working exploits** - all malicious code is neutered
- ✅ **Credential redaction** - no real C2 servers, keys, or credentials
- ✅ **No compilation instructions** for active malware
- ✅ **Safe code examples** with clear safety comments

---

## File Naming and Organization

### Default Behavior
Analysis is saved as `README.md` in the malware's source directory:
```
/malware/sample.asm
/malware/README.md  ← Analysis created here
```

### Alternative Locations
If no clear source directory exists:
```
/Articles/MalwareName_Analysis_YYYY-MM-DD.md
```

### Multiple Files
When analyzing multiple related files:
```
/malware/variant1.asm
/malware/variant2.asm
/malware/README.md  ← Combined analysis
```

---

## Tips for Best Results

### 1. Provide Context
```
Analyze this DOS virus from 1990s. Focus on:
- File infection mechanism
- Payload trigger conditions
- Stealth techniques
```

### 2. Specify Format Preferences
```
Analyze with emphasis on:
- Assembly instruction breakdown
- MITRE ATT&CK mapping
- YARA rule generation
```

### 3. Request Specific Sections
```
Analyze this malware and include:
- Memory layout diagrams
- API call sequences
- Network protocol analysis
```

### 4. Compare Variants
```
Compare and analyze these three malware variants:
- variant_a.asm
- variant_b.asm  
- variant_c.asm
```

---

## Advanced Usage

### Chain Multiple Chat Modes

1. **Quick analysis:**
   ```
   @workspace /chatmode analyze-malware-v4
   Give me a quick overview of this malware
   ```

2. **Deep dive:**
   ```
   @workspace /chatmode analyze-malware-expert
   Now provide comprehensive technical analysis
   ```

### Custom Output Location
```
Analyze this malware and save the analysis to:
/Articles/Special_Reports/APT_Analysis.md
```

### Update Existing Analysis
```
Update the README.md in /malware/sample/ with:
- New IoC section
- YARA rule
- Additional code analysis
```

---

## Contributing

To create a new chat mode:

1. Copy an existing `.chatmode.md` file
2. Modify the `name`, `description`, and `instructions`
3. Test with sample malware
4. Submit PR with:
   - New chatmode file
   - Update to this README
   - Example output

---

## Examples

### Example 1: DOS Virus Analysis

**Input:**
```
@workspace /chatmode analyze-malware-expert
Analyze /virusshare/Virus.DOS.Amz.600.asm
```

**Output:**
- 3500-word comprehensive analysis
- 8 annotated assembly code excerpts
- MITRE ATT&CK: T1083, T1486, T1055
- YARA rule for detection
- File-based, behavioral, and system-level IoCs
- Saved to: `/virusshare/README.md`

### Example 2: JavaScript Malware

**Input:**
```
@workspace /chatmode analyze-malware-v4
Analyze this JavaScript cryptominer [paste code]
```

**Output:**
- 1200-word focused analysis
- 4 code excerpts with explanations
- Detection and prevention strategies
- Saved to: `/Articles/JS_Cryptominer_Analysis.md`

---

## Troubleshooting

### Issue: Analysis too short
**Solution:** Use `analyze-malware-expert` for more comprehensive output

### Issue: Too much assembly detail
**Solution:** Use `analyze-malware-v4` for higher-level analysis

### Issue: Code not analyzed
**Solution:** Ensure file path is correct and file is readable

### Issue: Output in wrong language
**Solution:** All chatmodes enforce English output by design

### Issue: Malicious code still active
**Solution:** Report this immediately - all outputs should be neutered

---

## Resources

- [MITRE ATT&CK Framework](https://attack.mitre.org/)
- [YARA Documentation](https://yara.readthedocs.io/)
- [Malware Analysis Tutorials](https://malwareunicorn.org/)
- [Reverse Engineering Resources](https://github.com/wtsxDev/reverse-engineering)
- [VX Underground](https://vx-underground.org/) - Malware samples and research

---

## License

These chat modes are provided for **educational and defensive security purposes only**.

**DO NOT USE FOR:**
- Creating new malware
- Improving existing malware
- Malicious purposes
- Unauthorized system access

**Acceptable Use:**
- Security research
- Malware analysis training
- Incident response
- Threat intelligence
- Academic study
- Defensive security

---

**Maintained by:** petikvx  
**Last Updated:** 2025-11-11  
**Version:** 1.0
