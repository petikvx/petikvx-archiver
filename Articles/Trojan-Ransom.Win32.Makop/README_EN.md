# Trojan-Ransom.Win32.Makop (Elex) — Detailed analysis

Language: English | French version: [README.md](README.md)

**Sample (local file):** `2026-08-21_1d71f0bef3fba293a0d43bffb6941f21_elex_makop`  
**Family:** Makop / Core (“elex” variant) — offline Windows ransomware (embedded RSA public key)  
**Article folder:** `Trojan-Ransom.Win32.Makop` (former sandbox id: `260821-jx7zhaaq7w_pw_infected`)  
**Sources:** PE + **Hex-Rays 9.4** (`artefacts/ida_export/…i64.c`, 92 functions) + AES decryption of the `.ndata` string table + **x32dbg** confirmation (mutex)  
**Packing:** **not packed** (readable MSVC 2005 code); only an encrypted string blob in `.ndata`

> **Defensive / IR** analysis only. The binary was **not** allowed to run through the encryption walk on the host; only init up to `CreateMutexA` was observed under x32dbg.

---

## 0. Summary

| Observation | Code / artefact confirmation |
|-------------|------------------------------|
| Makop family (`.makop` extension, `readme-warning.txt` note) | AES strings id **0**, **6**, **8** |
| Operator email `netback@inboxhub.net` (+ `translog@420blaze.it` in the note) | id **1** / note body id **8** |
| Fixed mutex `m23071644` | id **29**; **read in clear** at `CreateMutexA` (heap `0x4B2000`) in x32dbg |
| 8-hex victim ID + rename `.[ID].[email].makop` | CRC32(`ProductId` + `-%08X` serial) → format id **24** |
| Per-file AES-256 + RSA-1024 wrap | `CryptEncrypt` + pubkey blob id **10** |
| Anti-VSS via `cmd` (vssadmin / wbadmin / wmic) | id **9** → `sub_406850` |
| Persistence `HKCU\...\Run` | id **28** → `sub_4043F0` |
| HTTP beacon `iplogger.org/1aWsr7` | id **41**–**43** → `sub_4048F0` |
| No wallpaper / `SystemParametersInfo` | Absent from this build |

**Packing verdict:** DIE = VC++ 14.00 / Linker 8.00; UPX = not packed; Hex-Rays decompiles the whole `.text`. The `.ndata` section (entropy ≈ **7.95**) is an **AES string table**, not an UPX/ASPack stub.

---

## 1. PE / entry point

| Field | Value |
|-------|--------|
| Type | PE32 GUI, i386, 4 sections, **36352** bytes, no overlay |
| EP | RVA `0x5750` → VA **`0x405750`** (`start`) |
| ImageBase | `0x00400000` |
| TimeDateStamp | `0x5F7AD0CC` → **2020-10-05 07:52:44 UTC** |
| DIE | Microsoft Visual C/C++ 14.00.50727 (VS 2005) |
| Sections | `.text` / `.rdata` / `.data` (BSS RawSize 0) / **`.ndata`** |

### Hashes

| Algo | Value |
|------|--------|
| MD5 | `1d71f0bef3fba293a0d43bffb6941f21` |
| SHA1 | `60096b25d6865258e24cd313fabfff821af7a228` |
| SHA256 | `d86cacc391d3a515870a28dec4b2f33e90ae000848a23d32f488a0ae96e82262` |

### `start` @ `0x405750` flow

```c
// start @ 0x405750
byte_409003 = sub_4065C0();          // process elevated?
byte_409002 = (sub_406540() == 2);   // argv: "n<pid>" token-reinject mode
ctx = HeapAlloc(...);
sub_4057C0(ctx);                     // CryptAcquireContext + .ndata table + dynapi
sub_405C10(...);                     // locale check → mutex → encrypt worker
sub_405A00();                        // heap / crypto cleanup
ExitProcess(0);
```

`sub_405A00` is **not** the ransomware engine: it is the **destructor** (free) called after `sub_405C10`. Real work is `sub_4044F0` (loop) via `sub_405C10` → `sub_407000` (mutex) → `sub_4044F0`.

### CLI modes (`sub_406540`)

| Argv | Effect |
|------|--------|
| (none / other) | Normal mode |
| `n%u` | “Network / token” mode: `byte_409002=1`, parent PID in `dword_419010` |
| `e…` | Secondary flag (returns 1) |

---

## 2. Init — crypto context, `.ndata` table, mutex

### 2.1 What is this for?

Makop leaves almost **no** cleartext strings in the PE (no email, note, or mutex in a plain `strings` dump). Everything lives in `.ndata`, encrypted with a **hard-coded** AES-256 key. At startup, `sub_4027F0` points the crypto context at `unk_41B000` (`.ndata` VA), then `sub_402AC0(id)` decrypts the requested string.

### 2.2 String-table AES key — `sub_402980`

PLAINTEXTKEYBLOB AES-256, CBC, IV = 0 (CryptoAPI default):

```
a91da6d2 be9a4ce8 d66176a3 063c2b43
dd2d3c24 d66a095f 48d5cf03 caca70bc
```

File: [`artefacts/aes_strings_key.txt`](artefacts/aes_strings_key.txt)  
Re-extraction script: [`artefacts/extract_makop_strings.py`](artefacts/extract_makop_strings.py)  
Full dump: [`artefacts/decrypted_strings.txt`](artefacts/decrypted_strings.txt)

### 2.3 `.ndata` table @ VA `0x41B000`

Header: `count=0x2B` (43 entries), then records `{id:u16, start:u16, end:u16, plen:u16}`, AES payloads packed after the index.

`sub_402AC0`: find `id`, copy `[start,end)`, `CryptDecrypt`, return `plen` useful bytes.

### 2.4 Mutex — `sub_407000`

```c
name = decrypt_string(29);   // "m23071644"
CreateMutexA(NULL, TRUE, name);
if (GetLastError() == ERROR_ALREADY_EXISTS) return true; // already running → abort path
```

**x32dbg:** at `kernel32!CreateMutexA` entry, `lpName` → `m23071644` (heap `0x4B2000`).

### 2.5 RSA-1024 public key — id **10**

PUBLICKEYBLOB (`RSA1`, e=`65537`) exported as PEM:

[`artefacts/rsa_public_key.pem`](artefacts/rsa_public_key.pem)

> Public key alone ≠ victim decryption. The RSA private key stays with the operators.

---

## 3. Side effects

| Effect | Detail | Code |
|--------|--------|------|
| Run persistence | `HKCU\SOFTWARE\Microsoft\Windows\CurrentVersion\Run` value `"1"` = quoted malware path | id **28**, `sub_4043F0` / `sub_404370` |
| Per-folder note | `readme-warning.txt` (+ internal marker `YOUR_FILES_ARE_ENCRYPTED`) | id **6**/**7**/**8**, `sub_407170` |
| Desktop / CSIDL_DESKTOP | `SHGetSpecialFolderPathW(..., 0, ...)` → drop note on Desktop | `sub_406640` |
| Beacon | HTTPS `iplogger.org` path `/1aWsr7` port **443** (encrypted-size stats) | `sub_4048F0` |
| Wallpaper | **Absent** from this sample | — |

---

## 4. Elevation / UAC / token

- `sub_4065C0`: token elevation (Vista+) or `IsUserAnAdmin` (XP).
- On OS ≥ Vista, dynamically resolves `CreateProcessWithTokenW` (id **26**) to relaunch `"%s" n%u` with the shell token (`sub_406300`) — typical Makop pattern to encrypt the user profile even from a SYSTEM/service session.
- `sub_4042A0`: disables UAC token virtualization (`TokenVirtualizationEnabled=0`) to write outside VirtualStore.

---

## 5. Anti-recovery

### 5.1 VSS / catalog destruction — id **9**

```text
vssadmin delete shadows /all /quiet
wbadmin delete catalog -quiet
wmic shadowcopy delete
exit
```

Run through `ComSpec` + pipes (`sub_406850` / `sub_406BC0`); no `.bat` dropped on disk.

### 5.2 Process kill — id **5** (38 names)

Full list: [`artefacts/kill_procs_list.txt`](artefacts/kill_procs_list.txt)  
(SQL Server, Oracle, Office, mail, Steam, etc. — free file handles before encryption.)

### 5.3 Not in this build

- No `bcdedit`
- No wallpaper / GDI defacement
- No dedicated Windows service

---

## 6. Walk / exclusions / priorities

### 6.0 What is this for?

Makop does not encrypt a single folder only. It inventories **volumes** (USB / fixed / mapped network), prepares **two AES keys per volume**, then starts **one walker thread per volume** that recurses with `FindFirstFileW(…\*.*)`, filters OS / PE / already-encrypted files, encrypts, renames, and drops `readme-warning.txt` once at least one file in the folder was hit. Unmapped shares are discovered via **WNet**.

### 6.1 Orchestration — `sub_405CC0`

```c
// sub_405CC0 (encrypt worker thread)
sub_401260(lpMem, 1);   // enum A:..Z: types 2/3/4
sub_4015D0(lpMem);      // 2× AES-256 per volume
sub_4016E0(lpMem);      // 2× RSA-1024 wraps per volume
if (first_pass) { sub_4042A0(); sub_406BC0(); }  // UAC virt off + VSS
sub_401930(malware_dir);          // first: directory of the binary
sub_401B00(lpMem);                // 1 thread / volume (WaitForMultipleObjects)
sub_401930(cache_path_variants);  // constructed cache paths
```

**x32dbg (sandbox):** first `sub_402380` on `C:\Users\petik\Desktop`; `FindFirstFileW` with pattern  
`C:\Users\petik\Desktop\*.*` (folder from which the sample was launched).

### 6.2 Drive enum — `sub_401260(lpMem, 1)`

| `GetDriveTypeW` | Value | Kept if `a2=1` |
|-----------------|-------|----------------|
| Removable | 2 | yes |
| Fixed | 3 | yes |
| Remote | 4 | yes |
| CD-ROM / other | — | no |

Per volume: serial (`GetVolumeInformationW`), global victim ID, type; optional `\\.\X:` + storage `DeviceIoControl`.  
If `a2=0` (other path): **only** remote drives (`type==4`).

### 6.3 Recursion — `StartAddress` → `sub_402380`

```c
// StartAddress @ 0x402790
if (!path_excluded(root))          // sub_4021A0
  sub_402380(ctx, root, len);

// sub_402380 : FindFirstFileW(path + "\\*.*")
for each entry (skip "." / ".."):
  if DIRECTORY:
    if name not in chrome-skip list (id 39): recurse
  else if file_allowed(sub_4022C0):
    ctx[42] = (size <= 1.5MiB);    // threshold id13
    sub_4033C0(ctx, fullpath);     // encrypt + MoveFileW
    if success: n++
if (n > 0) sub_407170(folder);     // drop note
```

Long paths (≥ `0xFA` chars): `\\?\` prefix via id **18**.

### 6.4 Filters

**Excluded paths — `sub_4021A0`** (id **51**, **40**, caches **25**/**37**):

- `windows` ; `winnt` ; `\system32` ; `\regedit.exe`
- `Users\Public;`
- `…\ProgramData\microsoft\windows\caches` ; `…\Users\All Users\Microsoft\Windows\Caches`

**Files — id **4****: `boot.ini` ; `bootfont.bin` ; `ntldr` ; `ntdetect.com` ; `io.sys` ; `readme-warning.txt` ; `desktop.ini`

**Extensions — `sub_4022C0` / id **27**** (anti double-encrypt + PE) + **SYSTEM** attribute (`0x4`):

`makop` ; `CARLOS` ; `shootlock` ; `shootlock2` ; `1recoesufV8Sv6g` ; `1recocr8M4YJskJ7` ; `btc` ; `KJHslgjkjdfg` ; `origami` ; `tomas` ; `RAGA` ; `zbw` ; `fireee` ; `XXX` ; `element` ; `HELP` ; `zes` ; `lockbit` ; **`exe`** ; **`dll`**

Lists: [`artefacts/skip_ext_list.txt`](artefacts/skip_ext_list.txt), [`artefacts/skip_files_list.txt`](artefacts/skip_files_list.txt), [`artefacts/skip_paths_list.txt`](artefacts/skip_paths_list.txt)

**Priority extensions (DB / Office) — id **2****: [`artefacts/priority_ext_list.txt`](artefacts/priority_ext_list.txt) (43 entries)

### 6.5 Shares — `sub_405540`

`WNetOpenEnumW` / `WNetEnumResourceW` (parallel thread `sub_4044E0` / `sub_405DC0`) for resources not already visible as drive letters.

---

## 7. Crypto

### 7.1 What is this for?

Each **volume** gets two AES-256 keys. Each **file** is encrypted with one of them (they **alternate** file-to-file) plus a fresh 16-byte IV. The volume AES key is wrapped with **RSA-1024** and stored in the **footer** with metadata.  
- File **≤ 1.5 MiB** → **full** encryption (`sub_403600`).  
- File **> 1.5 MiB** → **3 windows** of ≤ 256 KiB (`sub_403C00`): start, `size/3`, near EOF.

Without the operators’ RSA private key: no AES key recovery.

### 7.2 Size constants (`.ndata`)

| id | LE DWORD | Value | Role |
|----|----------|-------|------|
| **11** | `adad2ba1` | `0xA12BADAD` | wrap-package magic |
| **13** | `00001800` | **1.5 MiB** | full / partial threshold (`ctx+20`) |
| **14** | `00000400` | **256 KiB** | partial window size (`ctx+24`) |
| **15** | `00001000` | **1 MiB** | full-mode chunk (`ctx+16`) |

### 7.3 Volume keys — `sub_4015D0` / `sub_4016E0`

```c
// 2× AES-256 PLAINTEXTKEYBLOB (44 B), key = CryptGenRandom(32)
vol+32 = blobA;  vol+40 = blobB;

// 117-byte package → CryptEncrypt RSA → 128 B  (sub_4028C0)
// magic id11 | victim_id | serial | drive_type | aes_key[32] | CRC32(48 B)
vol+36 = wrapA;  vol+44 = wrapB;
vol+48 = 1;      // slot: alternates 1 ↔ 2 after each file
```

**x32dbg:** pre-wrap buffer = `AD AD 2B A1 | … | drive_type=3 | 32-byte key | CRC …` then `CryptEncrypt(..., bufLen=0x80)`.

Layout: [`artefacts/rsa_wrap_package_layout.txt`](artefacts/rsa_wrap_package_layout.txt)

Provider: `PROV_RSA_AES` (`0x18`) + `CRYPT_VERIFYCONTEXT`; algorithm `CALG_AES_256` (`0x6610`).

### 7.4 Full vs partial — `sub_402380` → `sub_4033C0`

```c
full = (nFileSizeHigh == 0) && (nFileSizeLow <= *(DWORD*)(ctx+20)); // ≤ 1.5 MiB
ctx[42] = full;
Open File R/W; // retry after kill on sharing violation
if (ctx[42]) sub_403600(ctx, path, h);  // FULL
else         sub_403C00(h, path, ctx);  // PARTIAL
MoveFileW(old, new_name);               // format id 24
```

If read-only: temporarily clear attribute (`ctx+43` / `ctx+44`).

### 7.5 FULL mode — `sub_403600`

1. Pad EOF → 16-byte multiple (zeros).  
2. IV = `CryptGenRandom` 16 B (`sub_402850`).  
3. `CryptImportKey(blob_slot)` + `CryptSetKeyParam(KP_IV)`.  
4. Meta (original size, UTF-16 basename, CRC32 poly `0xEDB88320`) → pad 16 → `CryptEncrypt` → write EOF.  
5. Write `meta_size`(4) + IV(16) + RSA_wrap(128) + progress(8).  
6. From offset 0: **1 MiB** chunks, `CryptEncrypt(Final=false)`, in-place write; update progress.  
7. `SetEndOfFile` at footer end; rename.

### 7.6 PARTIAL mode — `sub_403C00` + `sub_403AC0`

Same footer / IV / wrap. Content: **3** `sub_403AC0` calls (window ≤ **256 KiB**):

| # | Offset | Max length |
|---|--------|------------|
| 1 | `0` | 256 KiB |
| 2 | `filesize / 3` | 256 KiB |
| 3 | near EOF (`filesize(+pad) − 256 KiB`) | 256 KiB |

Bytes outside those windows stay plaintext on disk (large ISOs/VHDs are often still unusable).

### 7.7 Footer (IR view, from EOF)

| Offset from EOF | Size | Content |
|-----------------|------|---------|
| −8 | 8 | Progress / offset counter |
| −8−128 | 128 | RSA-1024–wrapped AES key |
| −8−128−16 | 16 | AES IV |
| −8−128−16−4 | 4 | `meta_size` (LE) |
| −(156+meta_size) | `meta_size` | AES meta (16-aligned) |

### 7.8 Victim ID — `sub_406E50` + `sub_406770`

```c
ProductId = RegQuery(HKLM\...\CurrentVersion, "ProductId");
serial    = GetVolumeInformationW(%SystemDrive%\);
wsprintfA(buf, "%s-%08X", ProductId, serial);
victim_id = CRC32(buf);   // sub_4041D0
```

### 7.9 Rename — format id **24**

```text
.[%08X].[%s].%s
→ .<victim_id>.[netback@inboxhub.net].makop
```

Example: `report.docx.[A1B2C3D4].[netback@inboxhub.net].makop`

---

## 8. Ransom note

- **Filename:** `readme-warning.txt` (id **6**)
- **Title / marker:** `YOUR_FILES_ARE_ENCRYPTED` (id **7**)
- **Body:** id **8** — English FAQ, Bitcoin payment, proof on 2 small non-DB files, contacts:

  - `netback@inboxhub.net`
  - `translog@420blaze.it`

Reconstructed text: [`artefacts/ransom_note_readme-warning.txt`](artefacts/ransom_note_readme-warning.txt)

---

## 9. Execution timeline (logical order)

1. `start` — admin / CLI flags  
2. `sub_4057C0` — AES CSP, `.ndata` anchor, Wow64 / CreateProcessWithTokenW dynapi  
3. `sub_405EA0` — load lists (excl., priorities, kill, paths), note, email, extension  
4. `sub_407000` — mutex `m23071644`  
5. `sub_4044F0` — Run key; walk threads; kill; VSS; encrypt; note; IPLogger beacon; `Sleep(0x7530)` and **loop**  

---

## 10. IoCs

| Type | Value |
|------|--------|
| MD5 | `1d71f0bef3fba293a0d43bffb6941f21` |
| SHA1 | `60096b25d6865258e24cd313fabfff821af7a228` |
| SHA256 | `d86cacc391d3a515870a28dec4b2f33e90ae000848a23d32f488a0ae96e82262` |
| Mutex | `m23071644` |
| Extension | `.makop` (final suffix) |
| Rename pattern | `*.[XXXXXXXX].[netback@inboxhub.net].makop` |
| Note | `readme-warning.txt` |
| Emails | `netback@inboxhub.net`, `translog@420blaze.it` |
| Run | `HKCU\SOFTWARE\Microsoft\Windows\CurrentVersion\Run` |
| URL | `iplogger.org/1aWsr7` (443) |
| AES strings key | `a91da6d2be9a4ce8d66176a3063c2b43dd2d3c24d66a095f48d5cf03caca70bc` |

Condensed file: [`artefacts/iocs.txt`](artefacts/iocs.txt)

---

## 11. ATT&CK (excerpt)

| ID | Technique | Evidence |
|----|-----------|----------|
| T1486 | Data Encrypted for Impact | AES + RSA footer, `.makop` |
| T1490 | Inhibit System Recovery | vssadmin / wbadmin / wmic (id 9) |
| T1547.001 | Registry Run Keys | id 28 / `sub_4043F0` |
| T1489 | Service Stop | kill list id 5 |
| T1134 | Access Token Manipulation | `CreateProcessWithTokenW` / `DuplicateTokenEx` |
| T1083 / T1135 | File & Network Share Discovery | drives + WNet* |
| T1071.001 | Web Protocols | WinINet → iplogger.org |
| T1027 | Obfuscated Files or Information | AES string table `.ndata` |

---

## 12. Captures / live debug

| Item | Status |
|------|--------|
| x32dbg | Mutex `m23071644`; RSA wrap magic `AD AD 2B A1`; walk `Desktop\*.*` |
| `CryptEncrypt` wrap | 117→128-byte package confirmed (drive_type=3 FIXED) before file walk |
| `FindFirstFileW` | `C:\Users\petik\Desktop\*.*` (first folder = sample dir) |
| Full mode `sub_403600` | BP set; MCP session dropped before a stable hit — flow confirmed in Hex-Rays |
| Any.RUN | No URL provided for this folder |

---

## 13. Deliverables

| File | Role |
|------|------|
| [`README.md`](README.md) / [`README_EN.md`](README_EN.md) | FR / EN reports |
| [`artefacts/ida_export/*.c`](artefacts/ida_export/) | Hex-Rays |
| [`artefacts/decrypted_strings.txt`](artefacts/decrypted_strings.txt) | 43 strings |
| [`artefacts/extract_makop_strings.py`](artefacts/extract_makop_strings.py) | Re-extract |
| [`artefacts/aes_strings_key.txt`](artefacts/aes_strings_key.txt) | Table AES key |
| [`artefacts/rsa_public_key.pem`](artefacts/rsa_public_key.pem) | RSA-1024 pubkey |
| [`artefacts/ransom_note_readme-warning.txt`](artefacts/ransom_note_readme-warning.txt) | Note |
| [`artefacts/*_list.txt`](artefacts/) | Ext / kill / skip |
| [`artefacts/vss_wbadmin_cmds.txt`](artefacts/vss_wbadmin_cmds.txt) | Anti-VSS |
| [`artefacts/iocs.txt`](artefacts/iocs.txt) | IoCs |

---

## 14. References + not verified

- LevelBlue / Stroz Friedberg — *Dissection Of Makop Ransomware Group* (family behavior: AES-256, RSA, `readme-warning` / `+README-WARNING+`, ProductId+serial ID)  
- ASEC, Cyfirma, public Makop / Core write-ups  

**Not verified here:**

- Full walk / real file encryption on the host  
- Exact IPLogger POST body (needs controlled sandbox run)  
- Interactive GUI in **this** build (stats strings id 34–36 present; GDI UI not confirmed live)  
- RSA private key (absent from the sample — expected)

---

*Defensive analysis — do not run the sample outside an isolated sandbox.*
