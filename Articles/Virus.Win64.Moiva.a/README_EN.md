# Virus.Win64.Moiva.a — infected `software_reporter_tool.exe` (Chrome Software Reporter Tool)

Language: English | French version: [README.md](README.md)

**Local sample:** `software_reporter_tool.exe`  
**Family:** Virus.Win64.Moiva (Kaspersky) — PE64 file infector; **common AV aliases: Win64.Expiro.***  
**Legitimate host:** Google **Software Reporter Tool** (`chrome_cleaner`, version **107.294.200**)  
**Sources:** PE (static triage) + `.reloc` body decryption + **x64dbg** session (MCP)

> **Defensive / IR** analysis only. The binary was not launched from the agent host; the x64dbg session was already opened by the analyst.

---

## 0. Summary (code ↔ live)

| Observation | Confirmation |
|-------------|--------------|
| Google Chrome Cleaner name / metadata | Version Info: *Software Reporter Tool* 107.294.200, Copyright Google 2015 |
| Moiva / Expiro detection | Parasitic infection of last section `.reloc` (RWX) + CRT hook |
| “Packed with Yano” (YARA) | **False positive** — strings live in `.rsrc` (ESET / signature catalog); see §2.4 |
| Startup control | `start` → `__scrt_common_main_seh` calls **`loc_140F02000`** (virus stub) instead of a CRT helper |
| ~560–580 KB virus body | After real reloc table + padding: high-entropy blob, decrypted in `0x400` blocks |
| x64dbg | Image `0x140000000`, Desktop path, host TLS callbacks then EP `0x140257720` |

**IR takeaway:** this is not a from-scratch fake Reporter Tool — it is a **real Google binary that was infected**. Any PE touched on the machine may share the same marks. Hunt for PE files whose `.reloc` is **executable + writable**, lack `DYNAMIC_BASE`, and have a zeroed BaseReloc data directory.

---

## 1. PE triage / entry point

### 1.1 Identity

| Field | Value |
|-------|--------|
| Type | **PE32+** GUI, machine `AMD64` (`0x8664`) |
| Size | **15,636,992** bytes (no overlay beyond last section) |
| ImageBase | `0x140000000` |
| AddressOfEntryPoint | RVA **`0x257720`** → VA **`0x140257720`** (`start`) |
| TimeDateStamp | `0x636305DE` → **2022-11-03 00:05:50 UTC** |
| Subsystem | WINDOWS_GUI |
| DllCharacteristics | `0x8120` = `HIGH_ENTROPY_VA \| NX_COMPAT \| TERMINAL_SERVER_AWARE` — **no `DYNAMIC_BASE` (ASLR off)** |
| Base Relocation DD | **RVA=0, Size=0** (cleared) |
| CLR DD | 0 (native, not .NET) |
| Authenticode | absent / invalid (Security DD empty) |
| Sections | 14 (Chromium profile: `.text`, `.rdata`, `.pdata`, `.00cfg`, `.gxfg`, …, **`.rsrc` ~11.6 MB**, **`.reloc`**) |

### 1.2 Hashes

| Algo | Value |
|------|--------|
| MD5 | `4fc5a1955aecc2187718cdbe1962fb88` |
| SHA1 | `94ff809e381b40b8c7f51a0197d95573ff7e410d` |
| SHA256 | `9e3e4c146d9a45099c57b7a038b870fceeba8ab44f43bece994622a02cc77834` |

### 1.3 Version Info (host)

| Key | Value |
|-----|--------|
| CompanyName | Google |
| FileDescription | Software Reporter Tool |
| FileVersion / ProductVersion | **107.294.200** |
| OriginalFilename | software_reporter_tool.exe |
| LegalCopyright | Copyright 2015 Google Inc. All Rights Reserved. |

PDB (CodeView): `...\out\Release_x64\software_reporter_…` — Chromium chrome_cleaner build.

### 1.4 Entry chain (host + virus)

```c
// start @ 0x140257720
_security_init_cookie();
return __scrt_common_main_seh();

// __scrt_common_main_seh @ 0x1402575AC
// First CRT call HIJACKED to the Moiva stub:
if ( (unsigned __int8) loc_140F02000(1) == 0 ) {
    _scrt_fastfail(7);   // stub must return non-zero or process aborts
    ...
}
// … initterm, then WinMain (chrome_cleaner) @ 0x14001DBE4
```

**What is this for?**  
Instead of overwriting the first ~1 KB of the entry point (classic 2013 Expiro), this variant **hijacks the very first `call` inside the CRT** (`__scrt_common_main_seh`). The viral stub must return a “true” (non-zero) value so the Google host continues — the user still sees a working Software Reporter Tool while the virus has already run.

**x64dbg:** breakpoints on TLS (`0x14016D050`, `0x1401DED30`, `0x140256070`, `0x1401BB4F0`) — **legitimate** CRT callbacks (`cmp edx,3` / init) — then pause at EP `0x140257720`. Image path: `C:\Users\petik\Desktop\software_reporter_tool.exe`.

---

## 2. Moiva infection morphology

### 2.1 What is this for?

A **file virus** (not ransomware) **copies itself into other PEs** on disk. The vehicle is a widely deployed Google tool: each launch runs Moiva first, which can spread, resolve APIs via the PEB, and (depending on the decrypted payload) steal data / maintain access — behavior documented for the **Expiro/Moiva** family.

### 2.2 Transformed `.reloc` section

| Property | Value | Normal vs infected |
|----------|--------|-------------------|
| VA | `0xE72000` | — |
| VirtualSize / RawSize | `0x92000` / `0x91000` | far beyond a normal Chrome reloc table |
| Characteristics | **`0xE2000040`** | **WRITE + EXECUTE + DISCARDABLE** — abnormal for `.reloc` (expected: READ+DISCARDABLE) |
| BaseReloc DataDirectory | **0** | official table cleared; ASLR disabled so ImageBase stays fixed |
| Section start | ~`0x32D4` bytes of real reloc (53 blocks), zeros until `+0x3400` | |
| Virus body | from VA **`0xE75400`** (file `0xE5BE00`), useful size **`0x8C000`** | entropy ~7.9 |

Raw artefact: [`artefacts/reloc_tail.bin`](artefacts/reloc_tail.bin) (580,608 bytes).

### 2.3 Decrypt stub @ `0x140F02000`

**Location:** end of `.reloc`, RVA `0xF02000` (file `0xEE8A00`).

**Clean structure:**

```c
// loc_140F02000 — Moiva stub (called from __scrt_common_main_seh with ecx=1)
push_all_gprs();
rbp = rsp; rsp = align16(rsp - 0x20);

rbx = &virus_body;          // lea rbx, [rip - 0x8CC2A]  → 0x140E75400
rdi = 0;                    // offset into body
push(rbx);                  // save base for after the loop

do {
    // ~256 polymorphic add/sub/xor/not ops
    // on EVERY dword of the 0x400-byte block at rbx
    polymorphic_fixup_block(rbx);   // offsets 0x00..0x3FC

    rdi += 0x400;
    rbx += 0x400;
} while (rdi != 0x8C000);   // 560 blocks → 573,440 bytes

pop(rcx);                   // original base
call 0x140F00D06;           // decrypted entry (body + 0x8B906)

restore_stack_and_gprs();
// AL must be non-zero so CRT does not fastfail
```

The `add/sub/xor/not dword [rbx+imm]` instructions are **polymorphic** (constants differ per sample): that is the modern Expiro/Moiva decryptor fingerprint — **not** a Yano packer.

After the loop: `call` to **`0x140F00D06`** = body + **`0x8B906`** (header field at `+0x14`).

### 2.4 “Yano Obfuscator” — YARA false positive

Rule `INDICATOR_EXE_Packed_Yano` matches because `.rsrc` literally contains `YanoAttribute` and `StripAfterObfuscation`.

**This PE is not Yano-packed:**

- immediate neighbors: `BabelAttribute`, `DotfuscatorAttribute`, `SmartAssembly.Attributes`, `Confuser.Core`, Go strings (`runtime.GOROOT`);
- context: **ESET engine** catalog / signatures embedded in Chrome Cleanup (`chrome_cleaner_internal\eset\…` in source paths);
- binary is **native MSVC** (DIE: VC++ / Chromium), empty CLR directory.

Details: [`artefacts/YANO_FALSE_POSITIVE.txt`](artefacts/YANO_FALSE_POSITIVE.txt).

---

## 3. Decrypted virus body

### 3.1 Extraction

Script: [`artefacts/extract_moiva_body.py`](artefacts/extract_moiva_body.py)  
Output: [`artefacts/moiva_body_decrypted.bin`](artefacts/moiva_body_decrypted.bin)

| Header field (LE dword) | Offset | Value (this sample) | Likely role |
|-------------------------|--------|---------------------|-------------|
| | `+0x00` | `0x46110` | blob #1 size |
| | `+0x04` | `0x3D362` | blob #2 size |
| | `+0x08` | `0x284` | blob #1 offset |
| | `+0x0C` | `0x49F54` | code / meta region |
| | `+0x10` | `0x4A1A4` | blob #2 offset |
| entry | `+0x14` | **`0x8B906`** | entry after decrypt stub |
| size | `+0x18` | **`0x8C000`** | size processed by the loop |

Decrypted body SHA256: `d0e1295a32c89396885749c5b5e074068d5f274a39c6b016d5b429252fc5b30f`

### 3.2 Embedded blobs

| File | Range | Size | Entropy | Note |
|------|-------|------|---------|------|
| [`moiva_blob1.bin`](artefacts/moiva_blob1.bin) | `+0x284` … | 286,992 | ~7.45 | leading `…PNG…`-like marker (not a valid PNG / no IEND) — still compressed/encrypted (layer 2) |
| [`moiva_blob2.bin`](artefacts/moiva_blob2.bin) | `+0x4A1A4` … | 250,722 | ~7.41 | second architecture / second stage (classic Expiro dual x86/x64 layout) |

### 3.3 Post-decrypt code (obfuscation)

- Recurring opaque predicates: `je X` / `jne X` to the **same** target (disguised unconditional branch).
- API resolution via **PEB**:

```c
// excerpt @ VA 0x140EFCAAF (body + 0x876AF)
rax = __readgsqword(0x60);   // PEB
rax = *(rax + 0x18);         // Ldr
r9  = *(rax + 0x20);         // InMemoryOrderModuleList
// then walk modules / exports (hash or compare)
```

PEB sites in the body: `+0x87696`, `+0x876AF`, `+0x87F24`, …

Cleartext API strings are rare (dynamic resolve) — expected for Expiro.

### 3.4 Runtime x64dbg — decrypt + layer 2 (confirmed)

Live session (ImageBase `0x140000000`, Desktop sample):

1. **Stub** `0x140F02000` → loop → `call 0x140F00D06` with **RCX = `0x140E75400`** (body base). In-memory header matches static decrypt.
2. **Caution:** a software BP on `0x140F00D06` *before* decrypt corrupts that dword (the loop mutates the INT3). Use a hardware BP *after* decrypt, or restore from the static body.
3. **VirtualAlloc** @ `0x140F00E55`:
   - size **`0x3D362 × 3 = 0xB7A26`**, flags `0x3000` / `PAGE_READWRITE`
   - allocated buffer **`0x1F00000`**
   - `RDI=0x3D362`, `R15→blob2` (`0x140EBF5A4`)
4. **Unpacker** `body+0x8ACA6`: pre-copies blob2 (without 3-byte prefix) with PNG magic, rebuilds a **PE64** in the workspace:
   - Machine `0x8664`, Optional Magic `0x20B`
   - sections `.text` `.rdata` `.data` `.pdata` `.gfids` `.reloc`
   - code with opaque predicates + **ROR13** hashing (`rol …, 13`) + PEB `gs:[0x60]`
   - infection helpers that test **`MZ` / `PE` / PNG signature** on targets
5. Return to host CRT / `WinMain`: `CreateFileW` on  
   `%LOCALAPPDATA%\Google\Software Reporter Tool\software_reporter_tool.log` (legitimate chrome_cleaner, retaddr `0x14010C2D9`).

Details: [`artefacts/moiva_live_notes.txt`](artefacts/moiva_live_notes.txt), [`artefacts/STAGE2_LIVE.md`](artefacts/STAGE2_LIVE.md), [`artefacts/moiva_main_flow.txt`](artefacts/moiva_main_flow.txt).

### 3.5 Remaining limits

- Full file dump of buffer `0x1F00000` (0xB7A26 bytes) from the Windows host → copy into `artefacts/` (`moiva_stage2_buf.bin` already saved on the debug Desktop).
- Exhaustive infection walk (extensions, exclusions) by following stage2 after unpacker return.
- x86 payload (`blob1`) not executed on this PE64 host.

---

## 4. Side effects / wallpaper

- **No wallpaper** set by Moiva on this sample.  
- `SystemParametersInfoW/A` only appear in **`.rsrc`** (catalog). See [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt).

---

## 5. Persistence / runtime artefacts + infection (live + literature)

### 5.1 What is this for?

Once stage2 runs in a worker thread, Moiva/Expiro **drops a local store** (encrypted browser credentials) and a **single-instance mutex**, then may **spread** by patching other `.exe` files (same technique: append + hijack a `call`). The host app (here Software Reporter Tool) keeps working with little user-visible signal.

### 5.2 Observed under x64dbg (this session)

| Artefact | Value |
|----------|--------|
| Store file | `C:\Users\petik\AppData\Roaming\fc36b5aa2a51efca.bin` |
| Access | `CreateFileW` **OPEN_EXISTING** + **GENERIC_READ**, from stage2 RWX (`ret ≈ 0x1BC1EA`), worker thread (not main) |
| Mutex | **`Global\Multiarch.m0yv-fc36b5aa2a51efca-inf`** (`CreateMutexW`, worker TID≈1692, `ret ≈ 0x1C0DE9`) |
| Machine ID | Hex `fc36b5aa2a51efca` **shared** by the `.bin` and the mutex |

These match documented Expiro IoCs (Quick Heal / Trend Micro): `%AppData%\<hex>.bin` + `Global\Multiarch.m0yv-<hex>-inf` (often also `…-b`).

### 5.3 PE infection (mechanism)

| Layer | Evidence |
|--------|----------|
| On **this** sample | First `call` in `__scrt_common_main_seh` → `.reloc` stub; last section **RWX**; ASLR off |
| Stage2 in RAM | Compares **`MZ` / `PE\0\0` / PNG signature** before handling a target |
| Family (literature) | Append to last section; patch a `call` into the body; skip names containing `windefend`, `UIODetect`, `svchost`, `TrustedInstaller`, `ntsvcs`; may spread to mapped network drives |

**`FindFirstFile*(* .exe)` walk** from stage2: **not captured** in the observation window (heavy **host** chrome_cleaner enumeration of Desktop `*.lnk` / IE paths). Conditional BPs were set; leave the session running to catch `.exe` scanning.

Log: [`artefacts/infection_iocs_live.txt`](artefacts/infection_iocs_live.txt).

### 5.4 C2 / theft (literature, network not verified here)

Modern Expiro: browser store in the `.bin`, intermittent C2, backdoor (cmd / plugins). **No network capture** in this session.

---

## 6. Execution timeline (static + live)

1. Windows loader maps the image at `0x140000000` (ASLR off).
2. **Host** Chromium/CRT TLS callbacks (`0x14016D050`, …) — observed under x64dbg.
3. `start` @ `0x140257720` → cookie → `__scrt_common_main_seh`.
4. **`call loc_140F02000(1)`** — decrypt `0x8C000` bytes in `0x400` blocks.
5. `call 0x140F00D06` — virus logic (PEB, infection, payload).
6. Return to CRT → chrome_cleaner `WinMain` if the stub returned success.

---

## 7. IoCs

### 7.1 File

| Type | Value |
|------|--------|
| SHA256 | `9e3e4c146d9a45099c57b7a038b870fceeba8ab44f43bece994622a02cc77834` |
| SHA1 | `94ff809e381b40b8c7f51a0197d95573ff7e410d` |
| MD5 | `4fc5a1955aecc2187718cdbe1962fb88` |
| Decrypted body SHA256 | `d0e1295a32c89396885749c5b5e074068d5f274a39c6b016d5b429252fc5b30f` |

### 7.2 Runtime (this host)

| Type | Value |
|------|--------|
| File | `%AppData%\fc36b5aa2a51efca.bin` (= `%UserProfile%\AppData\Roaming\…`) |
| Mutex | `Global\Multiarch.m0yv-fc36b5aa2a51efca-inf` |
| Pattern | `%AppData%\<16 hex>.bin` + `Global\Multiarch.m0yv-<same hex>-inf` (often also `-b`) |

### 7.3 PE heuristics (hunting)

- Section named `.reloc` with **`IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_MEM_WRITE`**
- **Base Relocation** data directory zero while a large `.reloc` exists
- `DllCharacteristics` **without** `IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE`
- `call` from `__scrt_common_main_seh` / CRT startup into the last section
- High entropy after the real reloc table (~section offset `+0x3400` on this sample)

### 7.4 Addresses (ImageBase `0x140000000`)

| Symbol | VA |
|--------|-----|
| `start` | `0x140257720` |
| `__scrt_common_main_seh` | `0x1402575AC` |
| Moiva decrypt stub | `0x140F02000` |
| Body base | `0x140E75400` |
| Post-decrypt entry | `0x140F00D06` |
| `WinMain` (host) | `0x14001DBE4` |

---

## 8. ATT&CK (relevant)

| ID | Technique | Evidence on this sample |
|----|-----------|-------------------------|
| T1204.002 | User Execution: Malicious File | Running the infected PE |
| T1036.005 | Match Legitimate Name/Location | Masquerades as Google Software Reporter Tool |
| T1027 | Obfuscated Files or Information | Encrypted `.reloc` body + polymorphism |
| T1140 | Deobfuscate/Decode | add/sub/xor/not loop per `0x400` block |
| T1106 | Native API | PEB → modules / exports |
| T1059 / T1055 / T1547… | (family) | Documented by Kaspersky for Moiva.a — **layer-2 payload not fully dumped here** |

---

## 9. Deliverables

| File | Description |
|------|-------------|
| [`README.md`](README.md) / [`README_EN.md`](README_EN.md) | This report |
| [`artefacts/reloc_tail.bin`](artefacts/reloc_tail.bin) | Encrypted `.reloc` tail |
| [`artefacts/moiva_body_decrypted.bin`](artefacts/moiva_body_decrypted.bin) | Body after dword fixups |
| [`artefacts/extract_moiva_body.py`](artefacts/extract_moiva_body.py) | Re-extract / decrypt |
| [`artefacts/moiva_blob1.bin`](artefacts/moiva_blob1.bin) / [`moiva_blob2.bin`](artefacts/moiva_blob2.bin) | Layer-2 blobs |
| [`artefacts/YANO_FALSE_POSITIVE.txt`](artefacts/YANO_FALSE_POSITIVE.txt) | YARA Yano note |
| [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt) | No wallpaper |
| [`artefacts/moiva_main_flow.txt`](artefacts/moiva_main_flow.txt) | Cleaned post-decrypt main flow |
| [`artefacts/moiva_live_notes.txt`](artefacts/moiva_live_notes.txt) | x64dbg session notes |
| [`artefacts/STAGE2_LIVE.md`](artefacts/STAGE2_LIVE.md) | In-memory layer-2 PE layout |
| [`artefacts/infection_iocs_live.txt`](artefacts/infection_iocs_live.txt) | Runtime infection / mutex / .bin IoCs |

---

## 10. References

- Kaspersky: [Virus.Win64.Moiva.a](https://threats.kaspersky.com/en/threat/Virus.Win64.Moiva.a/)
- Common aliases: Win64.Expiro.Gen.* (see CAPE / adware-removal reports on other Moiva hashes)
- Andrea Allievi — *Anatomy of a new 64-bit file infector* (Expiro 2013): historical `.vmp0` + XOR model (evolved here to CRT hook + dword fixups)
- ESET: *Win64/Expiro* cross-platform infector (2013)

### Not verified / partial

- Full stage2 workspace dump file (on Windows Desktop, not yet copied into the Articles folder)
- Actual infection of other `.exe` files on disk (`FindFirstFileW` BP not yet hit at log-file pause)
- C2 traffic for this exact variant
- Execution of the x86 blob (`blob1`)

---

*Defensive report — no assistance with propagation; extraction only covers material already present in the sample.*
