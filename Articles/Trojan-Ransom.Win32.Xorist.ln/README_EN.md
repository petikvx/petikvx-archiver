# Trojan-Ransom.Win32.Xorist.ln — Detailed analysis

Language: English | French version: [README.md](README.md)

**UPX sample:** `…-05d0be6b…7f9a-upx`  
**Analysis target:** `…-unpacked.exe` (**already decompressed**)  
**Family:** Xorist / “X0r157” (2012-era ransomware builder)  
**Detection:** Kaspersky `Trojan-Ransom.Win32.Xorist.ln`  
**Sources:** unpacked PE + **Hex-Rays 9.4** via `~/ida-pro-9.4/idat` → `artefacts/ida_export/` (`.c`/`.asm`/`.lst`) + builder config + sibling `Xorist.lk`

> **Defensive / IR** only. No host execution outside a third-party sandbox.

### In one sentence (non-expert)

A small **2012** ransomware (often shipped **UPX-packed**): copies itself to `%TEMP%`, persists, encrypts files (here **TEA**), appends **`.EnCiPhErEd`**, drops `HOW TO DECRYPT FILES.txt`, and shows a password window. The note asks for **300 RUB via WebMoney**. Public Xorist decryptors exist for many variants.

| Not this | This |
|----------|------|
| WannaCry / Conti | Classic Xorist builder (`0p3nSOurc3 X0r157`) |
| RSA asymmetric crypto | TEA 128-bit (or XOR) + password |
| Unique orphan sample | Near-clone of `Xorist.lk` (same code; different resource config) |

---

## 0. Hex-Rays ↔ artefacts

| Observation | Confirmation |
|-------------|--------------|
| UPX 3.07 → 12 KiB unpacked | `-upx` / `-unpacked.exe` provided |
| Banner `0p3nSOurc3 X0r157` | UI `ClassName` |
| Note `HOW TO DECRYPT FILES.txt` | `sub_40103A` |
| Persistence `Run\Alcmeter` | `sub_402422` when flag set |
| Extension `.EnCiPhErEd` | Builder config `lpSubKey` |
| **TEA** algorithm | `byte_40752C==1` → `sub_4017EC` |
| Password check | Chained MD5 (`sub_401F15` ×5) |
| Self-delete | `ComSpec /c del` (`sub_40214B`) |

**Sibling:** `.text`/`.rdata`/`.data` **byte-identical** to `Xorist.lk`; only PE **resources** differ.

---

## 1. Identification (unpacked)

| Field | Unpacked | UPX |
|-------|----------|-----|
| SHA256 | `e034e30ce286d730eb6338ef5626a8e15ba7d6b9a7f1158b2d2883005bae1287` | `05d0be6bbf2ce6d8b29a257629e071836290cf2a83e16641cf08ba5378317f9a` |
| MD5 | `805242256e678b3b8a05aee3a997d0f1` | `33755784b9128aabea98a2d4f0bebb86` |
| Size | **12288** | 7168 |
| TimeDateStamp | **2012-01-29 18:49:03 UTC** | — |
| EP | `0x4021D1` | UPX stub |

---

## 2. Entry — `start` @ `0x4021D1`

Load config → copy to `%TEMP%` → optional `Run\Alcmeter` → register `.EnCiPhErEd` → walk drives / encrypt → notes → self-delete.  
If TEMP copy already exists → password UI (decrypt mode).

---

## 3. Builder config (resource name=14, type=BITMAP)

Decoded with [`artefacts/extract_config.py`](artefacts/extract_config.py):

| Field | Value |
|-------|--------|
| Extension | **`.EnCiPhErEd`** |
| Algorithm | **TEA**, 64 rounds |
| UI language | Russian |
| Run persistence | yes (`Alcmeter`) |
| Per-folder note | yes |
| Password attempts | **9** |
| TEMP drop | `mB3Tew2BDFbEH1s.exe` |
| Password hash | `011137a3f394bab3b273a40037fc29ad` |

Ransom note asks **300 RUB** to WebMoney **`R209250562490`**.

**PathMatchSpec list** in this build contains only `r209250562490` (likely **builder misconfiguration** instead of `*.doc` / `*.*`) — mass encryption of normal documents may not fire; other ransomware machinery still runs.

---

## 4. File crypto

- Session key from **RDTSC** (16 bytes)  
- Per-file key: XOR/rotate with first filename character  
- **TEA** encrypt/decrypt (`sub_4017EC` / `sub_4018B0`) when flag set; else dword-XOR  
- Rename: append `.EnCiPhErEd`  
- Read/write from offset **127** (`lDistanceToMove`)

Public **Xorist decryptors** apply to this family.

---

## 5. Persistence & UI traces

`Alcmeter` Run key, `HKCR\.EnCiPhErEd` → `CRYPTED!`, wallpaper attempt (`pussylicker` BMP missing here), `HOW TO DECRYPT FILES.txt`, self-delete via `cmd`.

Password window class: `0p3nSOurc3 X0r157, motherfucker!`.

---

## 6. Timeline

```text
t0  Unpacked PE runs
t1  Decode config resource
t2  %TEMP% copy + Alcmeter
t3  Register extension (+ wallpaper if BMP present)
t4  Drive walk / TEA (filtered by PathMatchSpec)
t5  Notes + self-delete
u0  Password UI on relaunch (9 tries)
```

---

## 7. IoCs

| Type | Value |
|------|--------|
| SHA256 UPX | `05d0be6bbf2ce6d8b29a257629e071836290cf2a83e16641cf08ba5378317f9a` |
| SHA256 unpacked | `e034e30ce286d730eb6338ef5626a8e15ba7d6b9a7f1158b2d2883005bae1287` |
| Extension | `.EnCiPhErEd` |
| Note | `HOW TO DECRYPT FILES.txt` |
| Run | `Alcmeter` |
| WebMoney | `R209250562490` |

---

## 8. ATT&CK

T1486, T1547.001, T1112, T1491.001, T1059.003, T1027.002 (UPX).

---

## 9. IR remediation

Remove `Alcmeter` + TEMP copy; clean `HKCR\.EnCiPhErEd`; try vendor Xorist decryptor; restore from backups.

---

## 10. Limits

No Any.RUN for this hash. PathMatchSpec list looks mis-built. Hex-Rays covers unpacked image.

---

## 11. Produced files

| File | Role |
|------|------|
| `README.md` / `README_EN.md` | Reports |
| `…-upx` / `…-unpacked.exe` | Samples |
| `…i64.c` | Hex-Rays |
| `artefacts/extract_config.py` | Config decode |
| `artefacts/config_readable.txt` | Readable config |
| `artefacts/ransom_note_config.txt` | RU note |
| `artefacts/hashes.txt` | Hashes |
| `artefacts/wallpaper_1x1_placeholder.bmp` | Only BMP in PE (1×1) — not a real wallpaper |
| `artefacts/wallpaper_README.txt` | Wallpaper extraction notes |

---

## 12. References

- Local `Xorist.lk` + `Xorist_FASM.asm`  
- `malware-analyze/2024-03-17-ransomware-xorist.md`  
- Emsisoft / Kaspersky Xorist decryptors  
- Malpedia `win.xorist`
