# Trojan.Win32.Cosmu.bwts (“Zombie”) — Detailed analysis

Language: English | French version: [README.md](README.md)

**Sample (local file):** `2025-12-07_e6d94e245a597a9efc9657bc61ae796a_elex_wannacry`  
**Family:** Cosmu / “Zombie” (Chinese trojan-worm ~2011) — **not** WannaCry  
**Kaspersky:** `Trojan.Win32.Cosmu.bwts`  
**On-disk packer:** ASPack 2.xx — behaviour below from **Hex-Rays 9.4** of the unpacked image (`….c`)  
**Sources:** PE + **`….c`** + GBK strings + Cosmu literature  

> **Defensive / IR** only. No host execution outside a third-party sandbox.

---

## 0. Hex-Rays ↔ behaviour summary

| Observation | Code confirmation |
|-------------|-------------------|
| Filename tag `elex_wannacry` | **Misnomer** — unrelated to WannaCry |
| Drop `\Zombie.exe` | `sub_401800` → `%SystemDir%\Zombie.exe` |
| Chinese MessageBoxes | `sub_401A90` (when `xor_key != 0`) |
| “Encrypts” documents | `sub_401340(..., a3=0)`: additive XOR + **half swap** + PE prepend |
| `.exe` become carriers | `sub_401340(..., a3=1)`: PE + original **plaintext**; XOR key = 0 |
| `.gho` / `.bak` | **deleted** (`DeleteFileA`) |
| Self-delete | `sub_401040`: `%COMSPEC% /c del <self> > nul` |
| First run vs infected file | `WinMain` branches on footer `sub_4012B0` |

**One line:** first run walks every drive and turns files into **fake `.exe`s** that contain a copy of the malware; opening a “encrypted” document shows the Chinese joke; opening a parasitized `.exe` silently restores and runs the original.

---

## 1. Entry — `WinMain` @ `0x401F10`

### What is this for? (non-expert)

At startup the program asks:

> “Am I still the clean malware, or am I already a transformed victim file?”

It checks the **last 8 bytes**. Matching size stamp → **victim/carrier** mode. Otherwise → **infection** mode.

```c
// WinMain @ 0x401F10
GetModuleFileNameA(NULL, self, ...);

if (sub_4012B0(self)) {          // footer present
  if (xor_key != 0)
    sub_401A90(...);            // joke MessageBox
  else
    sub_401800(...);            // drop Zombie.exe + restore original EXE
} else {
  for each drive in GetLogicalDrives()
    sub_401CF0(drive + ":");
  sub_401040();                 // self-delete via cmd
}
```

| Field | Value |
|-------|--------|
| SHA256 | `3b04ee0c12725e4d9d3b3befdef43b9732454a3cb7a03bb6b84f2613f31f47ce` |
| MD5 | `e6d94e245a597a9efc9657bc61ae796a` |
| TimeDateStamp | **2011-03-15** |

---

## 2. “Already infected?” — `sub_4012B0`

```c
fseek(end - 8);
fread(dword0, dword1);
return dword1 == filesize;
```

| Footer field | Role |
|--------------|------|
| `dword0` | size of prepended malware PE (seek target for 56-byte meta) |
| `dword1` | must equal **total file size** |

---

## 3. Infecting a file — `sub_401340` / `sub_401BA0`

### 3.1 Who gets hit? — `sub_401BA0`

```c
if (ext is .exe/.EXE) {
  if (size <= 16 MiB) sub_401340(path, a3=1);  // CARRIER
} else if (ext is .gho/.GHO/.bak/.BAK) {
  DeleteFileA(path);                           // DESTROY
} else {
  if (size <= 32 MiB) sub_401340(path, a3=0);  // DOCUMENT joke
}
Sleep(size / 0xA000);
```

| Type | Action |
|------|--------|
| Documents / other | Become trap `.exe` (joke UI) |
| Executables | Silent droppers / restorers |
| Ghost / backups | Deleted |

### 3.2 Document layout (`a3=0`)

### What is this for?

Not RSA ransomware — Cosmu builds a **fake Windows program**:

1. Prepends **itself**.  
2. Stores original basename + a small key.  
3. Writes content as **second half then first half**, each byte `+= key`.  
4. Renames to **`original.ext.exe`**.

```c
key = 5166 + (rand() % 8);   // 5166..5173
out = path + ".tmp";
copy self PE → out;
fwrite(basename || orig_size || key, 0x38);
half = orig_size / key;
append (bytes[half..] each + key);
append (bytes[0..half) each + key);
fwrite({pe_size, pe_size + orig_size + 64}, 8);
DeleteFile(path); rename(out → path + ".exe");
```

```text
[ malware PE ][ meta 56 ][ XOR+reordered data ][ footer 8 ]
name: report.doc.exe
```

See [`artefacts/file_format.txt`](artefacts/file_format.txt).

### 3.3 EXE carrier (`a3=1`)

Same PE+meta, but `key = 0` and original bytes copied **unmodified** → `WinMain` calls `sub_401800` (no MessageBox).

---

## 4. Double-click paths

### 4.1 Joke — `sub_401A90`

```c
MessageBoxA(NULL, chinese_text, "_", MB_ICONEXCLAMATION);
```

No Bitcoin, no TOR, no RSA `.KEY` — pure **theatre** ([`artefacts/ui_strings_zh.txt`](artefacts/ui_strings_zh.txt)).

### 4.2 Silent carrier — `sub_401800`

```c
zombie = GetSystemDirectory() + "\\Zombie.exe";
write first pe_size bytes → zombie (HIDDEN);
_beginthread(run_then_delete_zombie);
extract original to "_basename", CreateProcess, wait, DeleteFile;
```

---

## 5. Drive walk — `sub_401CF0`

Recursive `*.*` with `CFileFind`; skip paths containing `WINDOWS` / `WINNT`; files → `sub_401BA0`.

---

## 6. Self-delete — `sub_401040`

`ShellExecuteExA` → `%COMSPEC%` with `/c del <shortpath> > nul`, priority tweaks, `SHChangeNotify`.

---

## 7. Timeline

```text
t0  Clean malware run
t1  Walk all drives; delete bak/gho; infect ≤32MiB files / ≤16MiB exes
t2  Documents → *.exe (PE+XOR); Exes → PE+plaintext original
t3  cmd deletes initial binary
---
u0  User opens report.doc.exe → Chinese MessageBox
v0  User runs parasitized exe → drop Zombie.exe + restore original
```

---

## 8. IoCs

| Type | Value |
|------|--------|
| SHA256 | `3b04ee0c12725e4d9d3b3befdef43b9732454a3cb7a03bb6b84f2613f31f47ce` |
| Drop | `%SystemDir%\Zombie.exe` (hidden) |
| Victim names | `*.*.exe` / `*_*.exe` |
| Footer | 8 bytes, `dword1 == filesize` |
| XOR key | `5166..5173` |
| UI | MessageBox caption `"_"` |
| Cmd | `/c del … > nul` |

---

## 9. ATT&CK

| Technique | ID | Evidence |
|-----------|-----|----------|
| User Execution | T1204.002 | GUI PE / `.doc.exe` |
| Masquerading | T1036 | `wannacry` tag; `*.doc.exe` |
| Hidden Files | T1564.001 | hidden `Zombie.exe` |
| File Deletion | T1070.004 | self-del + bak/gho wipe |
| Data Encrypted for Impact | T1486 | weak XOR+reorder |
| System Binary Proxy | T1218 | `cmd` via COMSPEC |
| Removable / all drives | T1091 | `GetLogicalDrives` walk |

---

## 10. Defensive recovery idea

Crypto is **reversible without paying**: parse footer/meta, subtract `key`, un-swap halves, write `orig_size` bytes under the stored basename. Method only — no offensive kit shipped here.

---

## 11. Produced files

| File | Role |
|------|------|
| `README.md` / `README_EN.md` | FR / EN report |
| `….c` | Hex-Rays 9.4 |
| `artefacts/*` | UI, format, hashes |

---

## 12. References

- Local Hex-Rays `….c`  
- Kaspersky `Trojan.Win32.Cosmu.bwts`  
- Microsoft `Worm:Win32/Cosmu.C`  

**Not verified:** live dynamic run / Any.RUN for this SHA256.
