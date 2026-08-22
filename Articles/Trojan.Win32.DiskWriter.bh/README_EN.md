# Trojan.Win32.DiskWriter.bh (MEMZ) — Detailed analysis

Language: English | French version: [README.md](README.md)

**Sample (local file):** `MEMZ.exe.bin`  
**Family:** MEMZ (destructive “joke” trojan by Leurak, ~2016; this PE build dated **2018-11-06**)  
**Kaspersky detection (folder name):** `Trojan.Win32.DiskWriter.bh`  
**Type:** Native PE32 GUI, **unpacked**, manifest `requireAdministrator`  
**Sources:** binary + Hex-Rays / IDA 9.4 (`artefacts/ida_export/`, `MEMZ.exe.bin.i64.c`)

> **Defensive / IR** analysis only. The sample was not executed on the host. No offensive MBR “fixer” is provided: only **embedded** blobs are extracted for documentation.

---

## 0. Code ↔ behavior summary

| Observation | Code confirmation |
|-------------|-------------------|
| No args → spawns copies | `start` @ `0x40122D`: 5× `ShellExecuteA(..., "/watchdog")` + `ShellExecuteExA(..., "/main")` |
| `/watchdog` = guardian | Thread `sub_40114A`: counts processes with the **same image path**; if the count **drops** → revenge |
| `/main` (or any arg ≠ `/watchdog`) = destruction | Writes `\\.\PhysicalDrive0` (64 KiB) + `\note.txt` + 10 UI payloads |
| Boot / disk start destroyed | Stub `byte_4021F8` (0x12F bytes) + blob `byte_402328` (0x7A0) pasted at offset **510** (`55 AA` + boot payload) |
| “Don’t kill the process” | Note + revenge: 20× MessageBox caption `MEMZ`, then `NtRaiseHardError` / forced reboot |
| No ransom / no file crypto | `CryptGenRandom` is only a **PRNG** (`sub_401A37`) |
| No BMP/JPG wallpaper | No `SystemParametersInfo`; visuals = live GDI + custom bootloader (Nyan Cat themed) |

**One-liner:** MEMZ elevates to admin, overwrites the start of physical disk 0 (normal boot will fail), shows a warning note, then runs joke UI payloads while watching its own processes — killing them triggers BSOD / reboot.

---

## 1. PE / entry point

### What is this for? (non-expert)

On launch the program does **not** immediately trash the disk. It inspects its command line:

1. **No arguments** → respawn several times as “watchdog”, once as “main”, then the parent exits.  
2. **`/watchdog`** → stay resident and watch that nobody kills the other copies.  
3. **`/main`** (and any other argument) → perform the destructive path (disk + effects).

This is a simple trick to keep **multiple processes** of the same `.exe` alive so that “End task” is harder without triggering revenge.

### PE triage

| Field | Value |
|-------|--------|
| SHA256 | `3ff64f10603f0330fa2386ff99471ca789391ace969bd0ec1c1b8ce1b4a6db42` |
| SHA1 | `761168201520c199dba68add3a607922d8d4a86e` |
| MD5 | `a7bcf7ea8e9f3f36ebfb85b823e39d91` |
| Size | 12,800 bytes (0x3200) |
| Machine | PE32 Intel 80386 |
| ImageBase / EP | `0x400000` / RVA `0x122D` → `start` |
| TimeDateStamp | `0x5BE181BC` = **2018-11-06 11:57:48 UTC** |
| Overlay | none |
| Packer | no (`.text` entropy ~5.8) |
| Manifest | `requestedExecutionLevel level='requireAdministrator'` → [`artefacts/embedded_manifest.xml`](artefacts/embedded_manifest.xml) |

| Section | VA | Raw size | Entropy (approx.) |
|---------|-----|----------|-------------------|
| `.text` | `0x1000` | `0xC00` | 5.78 |
| `.rdata` | `0x2000` | `0x1C00` | 6.42 |
| `.data` | `0x4000` | `0x200` | 2.32 |
| `.rsrc` | `0x5000` | `0x200` | 4.75 |
| `.reloc` | `0x6000` | `0x200` | 5.91 |

### Notable imports

| DLL | APIs of interest |
|-----|------------------|
| KERNEL32 | `CreateFileA`, `WriteFile`, `CreateThread`, `CreateToolhelp32Snapshot`, `OpenProcess`, `SetPriorityClass` |
| USER32 | MessageBoxes, `SetCursorPos`, `SendInput`, `SetWindowsHookExA`, `EnumWindows`, `ExitWindowsEx`, `DrawIcon` |
| GDI32 | `BitBlt`, `StretchBlt` |
| ADVAPI32 | `CryptAcquireContextA`, `CryptGenRandom`, token privileges |
| SHELL32 | `ShellExecuteA`, `ShellExecuteExA`, `CommandLineToArgvW` |
| WINMM | `PlaySoundA` |
| PSAPI | `GetProcessImageFileNameA` |

`ntdll!RtlAdjustPrivilege` / `NtRaiseHardError` are resolved **dynamically** (`LoadLibraryA` + `GetProcAddress`).

---

## 2. Init — `start` @ `0x40122D`

### 2.1 Launcher branch (argc ≤ 1)

```c
// start @ 0x40122D — cleaned
GetSystemMetrics(SM_CXSCREEN/SM_CYSCREEN); // → dword_4040E4 / dword_4040E8

argv = CommandLineToArgvW(...);
if (argc <= 1) {
    GetModuleFileNameA(NULL, self, 0x2000);
    for (i = 0; i < 5; i++)
        ShellExecuteA(NULL, NULL, self, "/watchdog", NULL, SW_SHOWDEFAULT);
    ShellExecuteExA({ file: self, params: "/main", SEE_MASK_NOCLOSEPROCESS });
    SetPriorityClass(hProcess, HIGH_PRIORITY_CLASS); // 0x80
    ExitProcess(0);
}
```

### What you see

| Item | Detail |
|------|--------|
| 5 watchdogs | Same binary, `/watchdog` |
| 1 main | `/main`, high priority |
| Parent | Exits right after spawn |

### 2.2 `/watchdog` branch

```c
if (lstrcmpW(argv[1], L"/watchdog") == 0) {
    CreateThread(..., sub_40114A, ...);          // monitor
    RegisterClassExA / CreateWindowExA("hax", ...);
    while (GetMessageA(...)) { TranslateMessage; DispatchMessageA; } // forever
}
```

WndProc `sub_401000` (@ `0x401000`) catches `WM_CLOSE` (16) and `WM_QUERYENDSESSION` (22) and runs revenge `sub_401021` instead of a clean exit.

### 2.3 Destructive branch (`/main` and other args)

Any argument other than `/watchdog` falls into the disk-write + payload path (see §3 and §6).

---

## 3. Disk write — DiskWriter core

### What is this for?

Windows boots by reading the **very start** of the disk (MBR / early boot code). MEMZ opens physical disk `\\.\PhysicalDrive0` for read/write and writes **65,536 bytes** built from two embedded blobs. After reboot, firmware runs this pirate stub instead of the Windows bootloader → the machine is unusable without low-level repair.

This is **not** ransomware: there is nothing to “pay”; recovery means disk / image / MBR repair from clean media.

### Cleaned code

```c
// destructive part of start() — ~0x4012xx
h = CreateFileA("\\\\.\\PhysicalDrive0",
                GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE,
                NULL, OPEN_EXISTING, 0, NULL);
if (h == INVALID_HANDLE_VALUE) ExitProcess(2);

buf = LocalAlloc(LPTR, 0x10000);          // 64 KiB zeroed
memcpy(buf, byte_4021F8, 0x12F);         // 303-byte boot stub
memcpy(buf + 510, byte_402328, 0x7A0);   // 55 AA + boot message/graphics

if (!WriteFile(h, buf, 0x10000, &written, NULL)) ExitProcess(3);
CloseHandle(h);
```

| IDA blob | RVA / VA | Copied size | Role |
|----------|----------|-------------|------|
| `byte_4021F8` | RVA `0x21F8` | **0x12F** (303) | 16-bit boot stub (`int 13h`, etc.) |
| `byte_402328` | RVA `0x2328` | **0x7A0** (1952) | Starts with `55 AA` (MBR signature at file offset 510) then payload (text “trashed by the MEMZ trojan”, “Nyan Cat…”, graphics) |
| Written buffer | — | **0x10000** | Rebuilt image: [`artefacts/PhysicalDrive0_first_64KiB.bin`](artefacts/PhysicalDrive0_first_64KiB.bin) |

### Artefacts

| File | Content |
|------|---------|
| [`mbr_code_0x12F.bin`](artefacts/mbr_code_0x12F.bin) | Embedded stub |
| [`boot_message_blob_0x7A0.bin`](artefacts/boot_message_blob_0x7A0.bin) | Signature + rest |
| [`boot_payload_ascii_fragments.txt`](artefacts/boot_payload_ascii_fragments.txt) | Readable ASCII fragments |
| [`extract_embedded.py`](artefacts/extract_embedded.py) | Deterministic re-extract |

**IR note:** on a still-running compromised host the disk is already altered **before** the screen gags. Priority: power off / isolate, image, **avoid reboot** if you still need offline volume access.

---

## 4. `\note.txt` + Notepad

### What is this for?

While the Windows session still runs, MEMZ drops a text file at the **root of the current drive** (`\note.txt` → typically `C:\note.txt`) and opens it with Notepad. The text says boot is dead and threatens instant destruction if you kill the trojan — which is **true** (see §5).

```c
h = CreateFileA("\\note.txt", GENERIC_READ|GENERIC_WRITE, ..., CREATE_ALWAYS, ...);
WriteFile(h, note_string, 0xDA, ...);
CloseHandle(h);
ShellExecuteA(NULL, NULL, "notepad", "\\note.txt", NULL, SW_SHOWDEFAULT);
```

Exact text: [`artefacts/note.txt`](artefacts/note.txt)

```
YOUR COMPUTER HAS BEEN FUCKED BY THE MEMZ TROJAN.

Your computer won't boot up again,
so use it as long as you can!

:D

Trying to kill MEMZ will cause your system to be
destroyed instantly, so don't try it :D
```

---

## 5. Elevation, watchdog, revenge

### 5.1 Admin

The manifest forces admin UAC. Writing `\\.\PhysicalDrive0` **fails** without enough rights (`ExitProcess(2)`).

### 5.2 Watchdog — `sub_40114A` @ `0x40114A`

### What is this for?

Several MEMZ copies run. The watchdog counts how many processes share **exactly the same image path**. If that number **decreases** (Task Manager killed an instance), it calls revenge.

```c
// sub_40114A — sketch
self_path = GetProcessImageFileNameA(GetCurrentProcess(), ...);
prev = 0;
for (;;) {
    snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    count = 0;
    for each process {
        path = GetProcessImageFileNameA(OpenProcess(...));
        if (lstrcmpA(self_path, path) == 0) count++;
    }
    if (count < prev)
        sub_401021(...);   // revenge
    prev = count;
    Sleep(10);
}
```

### 5.3 Revenge — `sub_401021` @ `0x401021`

1. Starts **20 threads** `StartAddress` (@ `0x4010FE`): each installs a `WH_CBT` hook then shows `MessageBoxA` with caption **`MEMZ`** and a random text among **20** insulting titles ([`revenge_messagebox_titles.txt`](artefacts/revenge_messagebox_titles.txt)). Hook `fn` (@ `0x4019B5`) **moves** the boxes on screen.  
2. `RtlAdjustPrivilege(19 /*SeShutdownPrivilege*/, TRUE, ...)`  
3. `NtRaiseHardError(0xC0000022, ..., OptionShutdownSystem=6, ...)` → BSOD / hard stop.  
4. Fallback: `AdjustTokenPrivileges(SeShutdownPrivilege)` + `ExitWindowsEx(0x6, 0x10007)` (forced reboot).

**Why:** discourage killing the process “hot”; the disk write already happened — revenge only adds immediate chaos.

---

## 6. Screen / “joke” payloads — timeline

### What is this for?

After the note, MEMZ starts **10 loops** (`sub_401A0F`), each calling one effect routine. Start delays live in a `{function, delay_ms}` table in `.rdata` ([`payload_schedule.csv`](artefacts/payload_schedule.csv)).

```c
for (j = 0; j < 10; j++) {
    Sleep(schedule[j].delay_ms);
    CreateThread(..., sub_401A0F, schedule[j].payload_fn, ...);
}
while (1) Sleep(10000);
```

`sub_401A0F` repeatedly calls `payload(stage, iter)` and `Sleep(10)` — the payload’s return value paces the loop.

| # | Delay before start | VA | Effect |
|---|--------------------|----|--------|
| 0 | 30 s | `sub_4014CA` | Opens random URL/app (`ShellExecuteA "open"`) — 34 targets |
| 1 | 30 s | `sub_40153B` | Cursor jitter (`SetCursorPos`) |
| 2 | 20 s | `sub_40176C` | Random keystrokes (`SendInput`) |
| 3 | 50 s | `sub_401667` | System sounds (`PlaySoundA`: Hand / Question / Exclamation) |
| 4 | 30 s | `sub_4015A2` | Invert desktop colors (`BitBlt` ROP `0x330008` NOTSRCCOPY) |
| 5 | 20 s | `sub_4015F8` | MessageBoxW “Still using this computer?” / “lol” + CBT hook |
| 6 | 10 s | `sub_40182D` | Draw error/warning icons under cursor and at random |
| 7 | 40 s | `sub_401656` | `EnumWindows` → reverse control text (`WM_GETTEXT` / `WM_SETTEXT`) |
| 8 | 60 s | `sub_4017B0` | Visual “tunnel” (`StretchBlt` shrink) |
| 9 | 15 s | `sub_401694` | Copy screen rectangles elsewhere (`BitBlt` SRCCOPY) |

### Browser / app spam — `sub_4014CA`

34 entries (full list: [`browser_spam_targets.txt`](artefacts/browser_spam_targets.txt)), mixing:

- absurd / toxic Google `.co.ck` searches (“remove memz”, “virus builder”, …);  
- sites (`clubpenguin`, `pcoptimizerpro`, `softonic`);  
- Windows binaries: `calc`, `notepad`, `cmd`, `write`, `regedit`, `explorer`, `taskmgr`, `msconfig`, `mspaint`, `devmgmt.msc`, `control`, `mmc`.

### PRNG — `sub_401A37`

```c
CryptAcquireContextA(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
CryptGenRandom(hProv, 4, &x);
return x & 0x7FFFFFFF;
```

No file keys, no document encryption.

### Wallpaper

**None.** See [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt). Visual impact is live GDI plus the MEMZ/Nyan Cat bootloader after reboot, not a dropped desktop background image.

---

## 7. Crypto

| Use | Detail |
|-----|--------|
| Victim files | **No** encryption |
| `CryptGenRandom` | Randomness for positions / delays / URL choice only |
| Ransom | **None** (wiper / hoax) |

---

## 8. “Ransom” note

There is no monetary ransom note. The only user-facing note is `\note.txt` (§4) plus the custom bootloader message.

---

## 9. Typical timeline (interactive session)

| t | Event |
|---|-------|
| 0 | Admin UAC; launcher spawns 5× `/watchdog` + 1× `/main` |
| ~0+ | `/main`: 64 KiB write to `PhysicalDrive0` |
| ~0+ | Create `\note.txt` + Notepad |
| +10–60 s | Progressive start of the 10 payloads (table §6) |
| Ongoing | Watchdogs measure instance count |
| On kill | MessageBox spam `MEMZ` → `NtRaiseHardError` / reboot |
| Reboot | MEMZ bootloader (Nyan Cat / “trashed…” message) — Windows does not load normally |

---

## 10. IoCs

### Hashes

| Algo | Value |
|------|--------|
| SHA256 | `3ff64f10603f0330fa2386ff99471ca789391ace969bd0ec1c1b8ce1b4a6db42` |
| SHA1 | `761168201520c199dba68add3a607922d8d4a86e` |
| MD5 | `a7bcf7ea8e9f3f36ebfb85b823e39d91` |

### Paths / objects

| IoC | Detail |
|-----|--------|
| `\\.\PhysicalDrive0` | Destructive write target |
| `\note.txt` | Note (often `C:\note.txt`) |
| Args | `/watchdog`, `/main` |
| Window class | `"hax"` |
| MessageBox caption | `MEMZ` |
| Mutex | **none** observed in this build |

### Marker strings

- `YOUR COMPUTER HAS BEEN FUCKED BY THE MEMZ TROJAN.`
- `RtlAdjustPrivilege` / `NtRaiseHardError`
- `Still using this computer?`

---

## 11. ATT&CK (approximate mapping)

| Technique | ID | Evidence |
|-----------|-----|----------|
| Multi-process same path | — | Several instances |
| Boot / disk modification | T1542.003 (spirit) / impact | `CreateFileA` + `WriteFile` on `PhysicalDrive0` |
| Inhibit recovery (practical) | near T1490 | Broken boot |
| UI defacement | T1491.001 (spirit) | BitBlt / StretchBlt / DrawIcon |
| Synthetic input | partial T1056.001 | `SendInput`, cursor |
| Native API | T1106 | `NtRaiseHardError` |
| Forced shutdown | T1529 | `ExitWindowsEx` / hard error |

---

## 12. Screenshots

No Any.RUN URL was provided for this folder → no sandbox screenshots in this delivery.

---

## 13. Deliverables

| File | Role |
|------|------|
| [README.md](README.md) / [README_EN.md](README_EN.md) | FR / EN reports |
| `MEMZ.exe.bin` | Sample |
| `MEMZ.exe.bin.i64` / `.i64.c` | IDA DB + initial Hex-Rays |
| [`artefacts/ida_export/MEMZ.exe.bin.{c,asm,lst}`](artefacts/ida_export/) | IDA 9.4 batch export |
| [`artefacts/note.txt`](artefacts/note.txt) | User note |
| [`artefacts/mbr_code_0x12F.bin`](artefacts/mbr_code_0x12F.bin) | Boot stub |
| [`artefacts/boot_message_blob_0x7A0.bin`](artefacts/boot_message_blob_0x7A0.bin) | `55 AA` + rest |
| [`artefacts/PhysicalDrive0_first_64KiB.bin`](artefacts/PhysicalDrive0_first_64KiB.bin) | Written buffer image |
| [`artefacts/payload_schedule.csv`](artefacts/payload_schedule.csv) | Payload timeline |
| [`artefacts/browser_spam_targets.txt`](artefacts/browser_spam_targets.txt) | 34 ShellExecute targets |
| [`artefacts/revenge_messagebox_titles.txt`](artefacts/revenge_messagebox_titles.txt) | 20 revenge texts |
| [`artefacts/embedded_manifest.xml`](artefacts/embedded_manifest.xml) | Admin manifest |
| [`artefacts/hashes.txt`](artefacts/hashes.txt) | Hashes |
| [`artefacts/extract_embedded.py`](artefacts/extract_embedded.py) | Re-extract script |
| [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt) | No wallpaper |

---

## 14. References and limits

### References

- Public **MEMZ** family (Leurak) — well-known destructive joke trojan (MBR + UI payloads).  
- Folder detection name: **Trojan.Win32.DiskWriter.bh**.  
- Local analysis: Hex-Rays 9.4 on this 12,800-byte PE.

### Not verified here

- Sandbox / Any.RUN execution (no URL).  
- Pixel-perfect bootloader rendering after `int 13h` (binary blob + ASCII fragments only).  
- Behavior under modern Secure Boot / UEFI GPT (code targets MBR-style `PhysicalDrive0`; exact outcome depends on firmware).  
- Private key / decryptor: **not applicable**.

### Safety

Sample = destructive malware. Do not run on a useful machine. The “don’t kill me” threat is real for the live session, but the disk is already written: proper IR is isolate + image, not negotiating with the trojan.
