# Trojan-DDoS.Win32.StormAttack.a — Detailed analysis

Language: English | French version: [README.md](README.md)

**Sample (local file):** `2026-08-25_7c44cb81bd2a164922500b2cdaa12f35_elex_remcos_wannacry`  
**Family:** StormAttack / “Storm ddos” (dropper + payload DLL, China ~2010)  
**File tag:** `elex_remcos_wannacry` — **misleading** (neither Remcos nor WannaCry)  
**Sources:** PE + Hex-Rays (`artefacts/ida_export/`) + live **x32dbg** (WoW64) session  

> **Defensive / IR** analysis only. No host execution outside the analyst’s already-open debugger.  
> Live session: intentional stop on the first `MessageBoxA` — **Active Setup persistence not continued**.

---

## 0. Debugger ↔ code summary

| Observation | Confirmation |
|-------------|--------------|
| `remcos` / `wannacry` tag | **Red herring** — strings + logic = “Storm ddos” installer |
| Startup MessageBox | Live: `MessageBoxA(NULL, "123", "123", 0)` from `WinMain` |
| Embedded mode | `dword_404120 = 3` → **Active Setup** branch |
| Drop `StormServer.dll` | PE resource type `DLL` / id `101` / lang `2052` (zh-CN) |
| `LoadLibraryA` injection | `CreateProcess` (IE/notepad/calc) + `VirtualAllocEx` / `WriteProcessMemory` / `CreateRemoteThread` |
| DDoS payload | Extracted DLL is **hollow** (~5.5% non-zero bytes, **no usable code**) |
| Cleartext C2/targets in DLL | `192.168.1.2`, `192.168.1.244` + HTTP GET templates (legacy / incomplete build) |

**One-liner:** this binary is a **multi-mode installer** (Windows service, Active Setup, injection) for a “Storm” DDoS bot family; **in this exact sample**, the resource DLL is a near-empty PE (strings + IAT, code zeroed), so the advertised DDoS effect cannot run as-is.

---

## 1. PE / entry point

### What is this for? (non-expert)

The file you open is **not** the network attack engine. It is mainly an **installer** that:

1. shows a small dialog box,
2. picks an install recipe from an integer stored in `.data`,
3. extracts a DLL from its resources,
4. tries to load that DLL into a legitimate process (often Internet Explorer).

### PE triage (dropper)

| Field | Value |
|-------|--------|
| Type | PE32 GUI i386 |
| SHA256 | `5bb61248f62945cd4933f00375c77eb094d22c55e33d6e57bbcf2127c19727b5` |
| SHA1 | `119973bb38a7c3546f5cbcba2ac01b11f2076907` |
| MD5 | `7c44cb81bd2a164922500b2cdaa12f35` |
| Size | 61440 bytes |
| ImageBase | `0x400000` |
| EP RVA | `0x2674` → VA `0x402674` (CRT `start` → `WinMain`) |
| TimeDateStamp | `0x4C540F4E` → **2010-07-31 11:55:58 UTC** |
| Linker / libs | MSVC 6.00, MFC 4.2, MSVCRT / MSVCP60 |
| Sections | `.ax` (code), `.rdata`, `.data`, `.rsrc` — no packer (low entropy) |
| Overlay | none |

### Live x32dbg session

| Item | Observed value |
|------|----------------|
| Host | x32dbg MCP `192.168.1.162:9095` (32-bit / WoW64) |
| PID | `3812` |
| ImagePath | `C:\Users\petik\Desktop\2026-08-25_7c44cb81bd2a164922500b2cdaa12f35_elex_remcos_wannacry` |
| ImageBase | `0x400000` (PEB) |
| Initial pause | EP `0x402674` (CRT `push ebp`) |
| BP + run | pause at `WinMain` `0x401CB0` (label set) |
| Next | pause at `user32!MessageBoxA` — stack text/caption → `0x4042C8` = **`"123"`** |
| Live config | `dword_404120 = 3`, `ServiceName = "Storm ddos Server"` |

The process was **left paused** on that `MessageBoxA`: dialog not dismissed, so `sub_401900` (Active Setup) was not entered during the agent analysis.

---

## 2. Init & state machine (`WinMain` @ `0x401CB0`)

### What is this for?

At startup the malware reads a **small switch** in its own image (`dword_404120`) to choose **which install recipe** to run. This is not a command-line argument: the value is **patched into the binary** (or into a mutated copy).

### Embedded config (`.data`)

| Symbol / VA | Value (this sample) | Role |
|-------------|---------------------|------|
| `dword_404120` | **3** | Install mode |
| `byte_404124` | **0** | Target directory: 0 = `GetSystemWindowsDirectoryA` |
| `byte_404125` | **0** | Injection host: 0 = `…\Internet Explorer\iexplore.exe` |
| `0x404128` | `Storm ddos Server` | Service name |
| `0x404148` | `Welcome to use storm ddos` | DisplayName / marketing text |
| `0x4041C8` | `Thank you` | 2nd MessageBox (modes 3/4) |
| `0x4042C8` | `123` | 1st MessageBox (text **and** caption) |
| `0x404020` | `StormServer.dll` | Dropped payload name |

Extracted sheet: [`artefacts/config_dropper.txt`](artefacts/config_dropper.txt).

### Clean code — `WinMain`

```c
// WinMain @ 0x401CB0
MessageBoxA(NULL, "123", "123", 0);   // always

if (mode == 1) {
  // If LanmanServer ServiceDLL already points at StormServer.dll → exit
  // Else: drop resource → %SystemDir%\StormServer.dll
  //       RegSet ServiceDLL; inject LoadLibrary; self-delete
}

switch (mode) {
  case 2: // "Storm ddos Server" service
    if (service key already present)
      StartServiceCtrlDispatcher(ServiceMain=sub_401510);
    else
      CreateService + StartService; maybe self-delete
    break;
  case 3: // <-- THIS SAMPLE
    MessageBoxA(NULL, "Thank you", "Thank you", 0);
    sub_401900();  // Active Setup + mutated copy (mode:=4)
    sub_401390();  // cmd /c del <self>
    break;
  case 4:
    MessageBoxA(...);
    sub_401B90();  // drop DLL + inject only
    break;
}
```

### Why these modes?

Authors want **several ways** to survive reboot (SCM service, Active Setup at logon, or plain injection) and to **re-run** an already-installed copy (mode 4 after Active Setup mutation). For IR: the on-disk `dword_404120` value immediately tells which branch will run.

---

## 3. Side effects / persistence

### 3.1 Active Setup — `sub_401900` @ `0x401900` (mode 3)

### What is this for?

**Active Setup** is a (mostly legacy) Windows mechanism that runs a command at user logon when an “installed component” has a `stubpath`. The malware registers a fake component with a **GUID** and points `stubpath` at a **copy of itself**.

```c
// sub_401900 (cleaned)
guid = CoCreateGuid();                 // or GUID already present in the build
path = WindowsDir + "\\" + guid + ".exe";
RegCreateKey(HKLM,
  "SOFTWARE\\Microsoft\\Active Setup\\Installed Components\\" + guid);
RegSetValueEx(..., "stubpath", path);

// Mutate a copy of the PE:
copy = read(self);
*(DWORD*)(copy + 0x6A0) = 4;           // force mode 4 on the copy
copy[0x3058] = 4;
strcpy(copy + 0x3078, guid_string);    // embed GUID in the file
write(path, copy);
CreateProcess(path);                   // launch mode-4 copy
```

**GUID already present in this build:** `{B85D5274-6F7B-4154-A7E1-CF9117522E1F}` (also as a string at file offset `0x3078`).

**What IR sees:** key under  
`HKLM\SOFTWARE\Microsoft\Active Setup\Installed Components\{…}`  
value `stubpath` → `C:\Windows\{GUID}.exe` (when `byte_404124==0`).

### 3.2 Windows service — `sub_401FD0` @ `0x401FD0` (mode 2)

- Name: `Storm ddos Server`
- DisplayName: `Welcome to use storm ddos`
- Registry Description: `Thank you`
- Type: own process, start `AUTO`
- `ServiceMain` = `sub_401510`: drop DLL + inject, then mark service STOPPED

### 3.3 `LanmanServer\ServiceDLL` hijack — `sub_401260` @ `0x401260` (mode 1)

```c
// Replace the file-server service DLL
RegOpenKey(HKLM,
  "SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters");
RegSetValueEx("ServiceDLL",
  "%SystemRoot%\\System32\\StormServer.dll");
```

Classic **ServiceDLL hijack**: when the legitimate service starts, Windows loads the attacker DLL.

### 3.4 Self-delete — `sub_401390` @ `0x401390`

Builds `%COMSPEC% /c  del <shortpath> > nul`, starts that process at low priority, restores its own priority — classic installer cleanup.

---

## 4. Elevation / UAC

No dedicated UAC bypass in the dropper Hex-Rays. `HKLM` / `CreateService` / `%SystemRoot%` writes **require** elevated rights. On a modern standard user, much of the persistence fails quietly (`RegCreateKey` / `OpenSCManager` NULL).

Not verified live beyond the first MessageBox (session left paused).

---

## 5. Injection — `sub_401150` @ `0x401150`

### What is this for?

Instead of running the DLL “alone”, the malware starts a **known Windows program** (IE, Notepad, or Calc), writes the **DLL path** into that process’s memory, then creates a remote thread on **`LoadLibraryA`**. Result: the DLL is loaded **inside** the legitimate process (crude camouflage).

```c
// sub_401150(path_to_StormServer_dll)
CreateProcessA(iexplore|notepad|calc, SW_HIDE, ...);
remote = VirtualAllocEx(hProcess, strlen(path)+1, MEM_COMMIT, PAGE_READWRITE);
WriteProcessMemory(hProcess, remote, path, ...);
pLoadLibraryA = GetProcAddress(GetModuleHandleA("Kernel32"), "LoadLibraryA");
CreateRemoteThread(hProcess, pLoadLibraryA, remote);
```

Host choice: `byte_404125` → `sub_4010C0`.

---

## 6. Resource drop — `sub_402460` @ `0x402460`

```c
hRes = FindResourceA(NULL, MAKEINTRESOURCE(101), "DLL");
buf  = LoadResource / LockResource / SizeofResource;
WriteFile(path /* CString */, buf, size);
```

| Resource field | Value |
|----------------|-------|
| Type | `"DLL"` (named) |
| ID | `101` |
| Language | `2052` (zh-CN) |
| File offset | `0x5060` |
| Size | `39936` |

Re-extraction script: [`artefacts/extract_stormserver.py`](artefacts/extract_stormserver.py).

---

## 7. Payload `StormServer.dll` — hollow / DDoS leftover

### What the family *intended*

Remaining strings describe a “Storm”-style **DDoS bot**:

- banners `Storm ddos DNS` / `Strom attack` (typo),
- beacon format `STORM:%d|%s|%s|%s|%s`,
- OS fingerprint (`Win7` … `WinNT`), RAM, CPU MHz,
- HTTP GET templates (IE6 / MyIE / fake Firefox UAs), `Accept-Language: zh-cn`,
- literal IPs `192.168.1.2` and `192.168.1.244`,
- duplicated persistence hooks (`ServiceDLL`, Active Setup, `URLDownloadToFileA`, `WSOCK32`).

### What *this* file actually contains

| Metric | Value |
|--------|-------|
| SHA256 | `0df2765cead245e3a89f9fafbbe5eb42ec7d41386a6c6dc235827539171335fd` |
| MD5 | `0a6b158119d530da50346424fe8b2096` |
| TimeDateStamp | 2010-07-31 11:50:40 UTC |
| ImageBase (header) | `0x10000000` |
| Sections | `.data` (R/W, originally **not X**), `.rsrc`, `.reloc` |
| Non-zero bytes | **2200 / 39936 (5.5%)** |
| `push ebp; mov ebp,esp` prologues | **0** |
| Export table | empty (`NumberOfFunctions = 0`) |
| Hex-Rays | no recoverable business logic |

**IR conclusion:** the resource is a **hollow PE** — headers + IAT + **strings** from an older StormServer, but **business code missing / zeroed**. `LoadLibrary` on this image cannot deliver the advertised DDoS capability. Either a corrupt/incomplete build, or a deliberately emptied stub that still carries indicators (names, HTTP, lab IPs).

Files: [`artefacts/StormServer.dll`](artefacts/StormServer.dll), IDA export attempt: [`artefacts/ida_export/StormServer.c`](artefacts/ida_export/StormServer.c) (no logic).

---

## 8. UI / notes

No ransom note. Only `MessageBoxA` dialogs:

| When | Text |
|------|------|
| Always at top of `WinMain` | `"123"` / `"123"` |
| Modes 3 and 4 | `"Thank you"` / `"Thank you"` |

No wallpaper / no graphical defacement in this sample.

---

## 9. Typical timeline (mode 3 — this sample)

1. CRT start `0x402674` → `WinMain`
2. `MessageBoxA("123")` ← **live pause here**
3. *(if the user clicks OK)* second MessageBox `"Thank you"`
4. `sub_401900`: Active Setup key + write mode-4 `{GUID}.exe` + `CreateProcess`
5. `sub_401390`: delete installer via `cmd /c del`
6. On next logon / run of the mode-4 copy: drop + inject the hollow DLL

---

## 10. IoCs

### Hashes

| Object | MD5 | SHA256 |
|--------|-----|--------|
| Dropper | `7c44cb81bd2a164922500b2cdaa12f35` | `5bb61248f62945cd4933f00375c77eb094d22c55e33d6e57bbcf2127c19727b5` |
| StormServer.dll (resource) | `0a6b158119d530da50346424fe8b2096` | `0df2765cead245e3a89f9fafbbe5eb42ec7d41386a6c6dc235827539171335fd` |

### Files / paths

- `%SystemRoot%\StormServer.dll` or `%SystemRoot%\System32\StormServer.dll` (mode / `byte_404124`)
- `%SystemRoot%\{GUID}.exe` (Active Setup, mode 3)
- System-directory copy with `HIDDEN|SYSTEM` attributes (service mode)

### Registry

- `HKLM\SOFTWARE\Microsoft\Active Setup\Installed Components\{B85D5274-6F7B-4154-A7E1-CF9117522E1F}` → `stubpath`
- `HKLM\SYSTEM\CurrentControlSet\Services\Storm ddos Server`
- `HKLM\SYSTEM\CurrentControlSet\Services\LanmanServer\Parameters\ServiceDLL` (mode 1)

### Network (payload strings, not executed here)

- `192.168.1.2`
- `192.168.1.244`
- HTTP / UA patterns in §7; string `xq1986`

### Mutex / other

No named mutex observed in the dropper Hex-Rays.

---

## 11. ATT&CK

| ID | Technique | Sample detail |
|----|-----------|---------------|
| T1547.014 | Active Setup | Mode 3 — `stubpath` |
| T1543.003 | Windows Service | Mode 2 — `Storm ddos Server` |
| T1574.001 | DLL Search Order / ServiceDLL hijack | `LanmanServer\Parameters\ServiceDLL` |
| T1055.001 | Dynamic-link Library Injection | `CreateRemoteThread(LoadLibraryA)` |
| T1036 | Masquerading | Hosts `iexplore.exe` / `notepad.exe` / `calc.exe` |
| T1070.004 | File Deletion | `cmd /c del` self |
| T1105 | Ingress Tool Transfer | `URLDownloadToFileA` string in DLL (code absent) |
| T1498 | Network Denial of Service | Family **intent**; **non-functional** in this DLL |

---

## 12. Captures / live debug

No Any.RUN URL provided. Debugger correlation:

| Step | Address | Note |
|------|---------|------|
| EP | `0x402674` | CRT `start` |
| `WinMain` | `0x401CB0` | MCP label: `WinMain StormAttack mode switch` |
| 1st UI | `user32!MessageBoxA` | args → `"123"` |
| BPs set (not hit) | `0x401900`, `0x402460` | Active Setup / resource drop |

---

## 13. Deliverables

| File | Content |
|------|---------|
| [README.md](README.md) | French report |
| [README_EN.md](README_EN.md) | English report |
| [artefacts/stormattack_dropper.exe](artefacts/stormattack_dropper.exe) | Sample copy |
| [artefacts/StormServer.dll](artefacts/StormServer.dll) | Extracted resource (hollow) |
| [artefacts/res_DLL_101_2052.bin](artefacts/res_DLL_101_2052.bin) | Same blob (resource parse) |
| [artefacts/config_dropper.txt](artefacts/config_dropper.txt) | `.data` config |
| [artefacts/extract_stormserver.py](artefacts/extract_stormserver.py) | Defensive re-extraction |
| [artefacts/ida_export/stormattack_dropper.c](artefacts/ida_export/stormattack_dropper.c) | Dropper Hex-Rays |
| [artefacts/ida_export/stormattack_dropper.asm](artefacts/ida_export/stormattack_dropper.asm) / `.lst` | Listings |
| [artefacts/ida_export/StormServer.*](artefacts/ida_export/) | DLL export (no logic) |

---

## 14. References & not verified

**Done:**

- PE triage + hashes + DIE (MSVC6 / MFC42)
- Full dropper Hex-Rays
- Resource extraction + hollow finding on the DLL
- x32dbg session: EP → `WinMain` → `MessageBoxA("123")`, live read of `dword_404120`

**Not verified / intentionally not done:**

- No free-run outside the debugger; no OK click past the first MessageBox (so no runtime Active Setup / drop observed)
- No network traffic (payload has no code)
- No Any.RUN report
- Exact AV label “StormAttack.a” not re-checked on VirusTotal in this session
- x64dbg (port 9094) unreachable; live analysis via **x32dbg** only

**Family context:** Chinese “Storm” DDoS bots / HTTP-flood tools from the early 2010s — matches TimeDateStamp 2010-07-31 and zh-cn UI strings.
