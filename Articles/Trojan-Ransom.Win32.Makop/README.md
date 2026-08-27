# Trojan-Ransom.Win32.Makop (Elex) — Analyse détaillée

Langue : Français | English version: [README_EN.md](README_EN.md)

**Sample (fichier local) :** `2026-08-21_1d71f0bef3fba293a0d43bffb6941f21_elex_makop`  
**Famille :** Makop / Core (variante « elex ») — ransomware Windows offline (clé RSA embarquée)  
**Dossier article :** `Trojan-Ransom.Win32.Makop` (ancien id sandbox : `260821-jx7zhaaq7w_pw_infected`)  
**Sources :** PE + **Hex-Rays 9.4** (`artefacts/ida_export/…i64.c`, 92 fonctions) + déchiffrement AES table `.ndata` + confirmation **x32dbg** (mutex)  
**Packing :** **non packé** (code MSVC 2005 lisible) ; blob chiffré de chaînes dans `.ndata` uniquement

> Analyse **défensive / IR** uniquement. Le binaire n’a **pas** été laissé tourner jusqu’au walk de chiffrement sur l’hôte ; seul le chemin d’init jusqu’à `CreateMutexA` a été observé sous x32dbg.

---

## 0. Synthèse

| Observation | Confirmation code / artefacts |
|-------------|-------------------------------|
| Famille Makop (extension `.makop`, note `readme-warning.txt`) | Chaînes AES id **0**, **6**, **8** |
| Email opérateur `netback@inboxhub.net` (+ `translog@420blaze.it` dans la note) | id **1** / corps note id **8** |
| Mutex fixe `m23071644` | id **29** ; **lu en clair** à `CreateMutexA` (heap `0x4B2000`) sous x32dbg |
| ID victime 8 hex + rename `.[ID].[email].makop` | CRC32(`ProductId` + `-%08X` serial) → format id **24** |
| AES-256 fichier + wrap RSA-1024 | `CryptEncrypt` + pubkey blob id **10** |
| Anti-VSS via `cmd` (vssadmin / wbadmin / wmic) | id **9** → `sub_406850` |
| Persistance `HKCU\...\Run` | id **28** → `sub_4043F0` |
| Beacon HTTP `iplogger.org/1aWsr7` | id **41**–**43** → `sub_4048F0` |
| Pas de wallpaper / `SystemParametersInfo` | Absent de ce build |

**Verdict packing :** DIE = VC++ 14.00 / Linker 8.00 ; UPX = not packed ; Hex-Rays décompile tout le `.text`. La section `.ndata` (entropie ≈ **7.95**) est une **table de chaînes AES**, pas un stub UPX/ASPack.

---

## 1. PE / point d’entrée

| Champ | Valeur |
|-------|--------|
| Type | PE32 GUI, i386, 4 sections, **36352** o, pas d’overlay |
| EP | RVA `0x5750` → VA **`0x405750`** (`start`) |
| ImageBase | `0x00400000` |
| TimeDateStamp | `0x5F7AD0CC` → **2020-10-05 07:52:44 UTC** |
| DIE | Microsoft Visual C/C++ 14.00.50727 (VS 2005) |
| Sections | `.text` / `.rdata` / `.data` (BSS RawSize 0) / **`.ndata`** |

### Hashes

| Algo | Valeur |
|------|--------|
| MD5 | `1d71f0bef3fba293a0d43bffb6941f21` |
| SHA1 | `60096b25d6865258e24cd313fabfff821af7a228` |
| SHA256 | `d86cacc391d3a515870a28dec4b2f33e90ae000848a23d32f488a0ae96e82262` |

### Flow `start` @ `0x405750`

```c
// start @ 0x405750
byte_409003 = sub_4065C0();          // process elevated ?
byte_409002 = (sub_406540() == 2);   // argv : mode "n<pid>" (réinject token)
ctx = HeapAlloc(...);
sub_4057C0(ctx);                     // CryptAcquireContext + table .ndata + dynapi
sub_405C10(...);                     // locale check → mutex → worker encrypt
sub_405A00();                        // cleanup heap / crypto
ExitProcess(0);
```

`sub_405A00` n’est **pas** le moteur de rançon : c’est le **destructeur** (free) appelé après `sub_405C10`. Le vrai travail est `sub_4044F0` (boucle) via `sub_405C10` → `sub_407000` (mutex) → `sub_4044F0`.

### Modes CLI (`sub_406540`)

| Argv | Effet |
|------|--------|
| (aucun / autre) | Mode normal |
| `n%u` | Mode « réseau / token » : `byte_409002=1`, PID parent dans `dword_419010` |
| `e…` | Flag secondaire (retour 1) |

---

## 2. Init — crypto contexte, table `.ndata`, mutex

### 2.1 À quoi ça sert ?

Makop ne laisse presque **aucune** chaîne en clair dans le PE (pas d’email, pas de note, pas de mutex visibles au `strings`). Tout est dans `.ndata`, chiffré avec une clé AES-256 **en dur**. Au démarrage, `sub_4027F0` pointe le contexte crypto sur `unk_41B000` (= VA de `.ndata`), puis `sub_402AC0(id)` déchiffre la chaîne demandée.

### 2.2 Clé AES des chaînes — `sub_402980`

PLAINTEXTKEYBLOB AES-256, CBC, IV = 0 (défaut CryptoAPI) :

```
a91da6d2 be9a4ce8 d66176a3 063c2b43
dd2d3c24 d66a095f 48d5cf03 caca70bc
```

Fichier : [`artefacts/aes_strings_key.txt`](artefacts/aes_strings_key.txt)  
Script de re-extraction : [`artefacts/extract_makop_strings.py`](artefacts/extract_makop_strings.py)  
Dump complet : [`artefacts/decrypted_strings.txt`](artefacts/decrypted_strings.txt)

### 2.3 Table `.ndata` @ VA `0x41B000`

En-tête : `count=0x2B` (43 entrées), puis enregistrements `{id:u16, start:u16, end:u16, plen:u16}`, payload AES collé derrière.

`sub_402AC0` : cherche `id`, copie `[start,end)`, `CryptDecrypt`, retourne `plen` octets utiles.

### 2.4 Mutex — `sub_407000`

```c
name = decrypt_string(29);   // "m23071644"
CreateMutexA(NULL, TRUE, name);
if (GetLastError() == ERROR_ALREADY_EXISTS) return true; // déjà lancé → abort chemin
```

**x32dbg :** à l’entrée de `kernel32!CreateMutexA`, `lpName` → `m23071644` (heap `0x4B2000`).

### 2.5 Pubkey RSA-1024 — id **10**

PUBLICKEYBLOB (`RSA1`, e=`65537`) exportée en PEM :

[`artefacts/rsa_public_key.pem`](artefacts/rsa_public_key.pem)

> Pubkey seule ≠ déchiffrement victimes. La clé privée RSA reste chez les opérateurs.

---

## 3. Effets collatéraux

| Effet | Détail | Code |
|-------|--------|------|
| Persistance Run | `HKCU\SOFTWARE\Microsoft\Windows\CurrentVersion\Run` valeur `"1"` = chemin quoté du malware | id **28**, `sub_4043F0` / `sub_404370` |
| Note par dossier | `readme-warning.txt` (+ titre interne `YOUR_FILES_ARE_ENCRYPTED`) | id **6**/**7**/**8**, `sub_407170` |
| Desktop / CSIDL_DESKTOP | `SHGetSpecialFolderPathW(..., 0, ...)` → drop note Bureau | `sub_406640` |
| Beacon | HTTPS `iplogger.org` path `/1aWsr7` port **443** (stats taille chiffrée) | `sub_4048F0` |
| Wallpaper | **Absent** de ce sample | — |

---

## 4. Élévation / UAC / token

- `sub_4065C0` : elevation token (Vista+) ou `IsUserAnAdmin` (XP).
- Sur OS ≥ Vista, résolution dynamique de `CreateProcessWithTokenW` (id **26**) pour relancer une copie `"%s" n%u` avec le token du shell (`sub_406300`) — typique Makop pour chiffrer le profil utilisateur même depuis une session SYSTEM/service.
- `sub_4042A0` : désactive la virtualisation UAC du token (`TokenVirtualizationEnabled=0`) pour écrire hors VirtualStore.

---

## 5. Anti-recovery

### 5.1 Destruction VSS / catalogues — id **9**

```text
vssadmin delete shadows /all /quiet
wbadmin delete catalog -quiet
wmic shadowcopy delete
exit
```

Exécuté via `ComSpec` + pipes (`sub_406850` / `sub_406BC0`), pas un `.bat` droppé sur disque.

### 5.2 Kill process — id **5** (38 noms)

Liste exhaustive : [`artefacts/kill_procs_list.txt`](artefacts/kill_procs_list.txt)  
(SQL Server, Oracle, Office, mail, Steam, etc. — libérer les handles de fichiers avant chiffrement.)

### 5.3 Ce qui n’est **pas** dans ce build

- Pas de `bcdedit`
- Pas de wallpaper / defacement GDI
- Pas de service Windows dédié

---

## 6. Walk / exclusions / priorités

### 6.0 À quoi ça sert ?

Makop ne se contente pas d’un dossier unique. Il inventorie les **volumes** (USB / disque fixe / lecteur réseau), prépare **deux clés AES par volume**, puis lance **un thread de parcours par volume** qui descend récursivement avec `FindFirstFileW(…\*.*)`, filtre OS / PE / déjà chiffré, chiffre, renomme, et dépose `readme-warning.txt` dès qu’un fichier du dossier a été touché. Les partages non mappés sont cherchés via **WNet**.

### 6.1 Orchestration — `sub_405CC0`

```c
// sub_405CC0 (thread worker encrypt)
sub_401260(lpMem, 1);   // enum A:..Z: types 2/3/4
sub_4015D0(lpMem);      // 2× AES-256 / volume
sub_4016E0(lpMem);      // 2× wrap RSA-1024 / volume
if (first_pass) { sub_4042A0(); sub_406BC0(); }  // UAC virt off + VSS
sub_401930(malware_dir);          // d’abord le dossier du binaire
sub_401B00(lpMem);                // 1 thread / volume (WaitForMultipleObjects)
sub_401930(cache_path_variants);  // chemins caches construits
```

**x32dbg (sandbox) :** premier `sub_402380` sur `C:\Users\petik\Desktop` ; `FindFirstFileW` avec motif  
`C:\Users\petik\Desktop\*.*` (dossier d’où le sample a été lancé).

### 6.2 Enum lecteurs — `sub_401260(lpMem, 1)`

| `GetDriveTypeW` | Valeur | Retenu si `a2=1` |
|-----------------|--------|------------------|
| Removable | 2 | oui |
| Fixed | 3 | oui |
| Remote | 4 | oui |
| CD-ROM / autre | — | non |

Par volume : serial (`GetVolumeInformationW`), ID victime global, type ; ouverture `\\.\X:` + `DeviceIoControl` stockage (optionnel).  
Si `a2=0` (autre chemin) : **uniquement** les lecteurs remote (`type==4`).

### 6.3 Récursion — `StartAddress` → `sub_402380`

```c
// StartAddress @ 0x402790
if (!path_excluded(root))          // sub_4021A0
  sub_402380(ctx, root, len);

// sub_402380 : FindFirstFileW(path + "\\*.*")
for each entry (skip "." / ".."):
  if DIRECTORY:
    if name not in chrome-skip list (id 39): recurse
  else if file_allowed(sub_4022C0):
    ctx[42] = (size <= 1.5MiB);    // seuil id13
    sub_4033C0(ctx, fullpath);     // encrypt + MoveFileW
    if success: n++
if (n > 0) sub_407170(folder);     // drop note
```

Chemins longs (≥ `0xFA` chars) : préfixe `\\?\` via id **18** (`\\?\`).

### 6.4 Filtres

**Chemins exclus — `sub_4021A0`** (id **51**, **40**, caches **25**/**37**) :

- `windows` ; `winnt` ; `\system32` ; `\regedit.exe`
- `Users\Public;`
- `…\ProgramData\microsoft\windows\caches` ; `…\Users\All Users\Microsoft\Windows\Caches`

**Fichiers — id **4**** : `boot.ini` ; `bootfont.bin` ; `ntldr` ; `ntdetect.com` ; `io.sys` ; `readme-warning.txt` ; `desktop.ini`

**Extensions — `sub_4022C0` / id **27**** (anti double-encrypt + PE) + attribut **SYSTEM** (`0x4`) :

`makop` ; `CARLOS` ; `shootlock` ; `shootlock2` ; `1recoesufV8Sv6g` ; `1recocr8M4YJskJ7` ; `btc` ; `KJHslgjkjdfg` ; `origami` ; `tomas` ; `RAGA` ; `zbw` ; `fireee` ; `XXX` ; `element` ; `HELP` ; `zes` ; `lockbit` ; **`exe`** ; **`dll`**

Listes : [`artefacts/skip_ext_list.txt`](artefacts/skip_ext_list.txt), [`artefacts/skip_files_list.txt`](artefacts/skip_files_list.txt), [`artefacts/skip_paths_list.txt`](artefacts/skip_paths_list.txt)

**Extensions prioritaires (bases / Office) — id **2**** : [`artefacts/priority_ext_list.txt`](artefacts/priority_ext_list.txt) (43 entrées)

### 6.5 Partages — `sub_405540`

`WNetOpenEnumW` / `WNetEnumResourceW` (thread parallèle `sub_4044E0` / `sub_405DC0`) pour les ressources non déjà vues comme lettres de lecteur.

---

## 7. Crypto

### 7.1 À quoi ça sert ?

Chaque **volume** a deux clés AES-256. Chaque **fichier** est chiffré avec l’une d’elles (elles **alternent** fichier à fichier) + un IV 16 o frais. La clé AES du volume est emballée en **RSA-1024** et collée dans le **footer** avec métadonnées.  
- Fichier **≤ 1,5 MiB** → chiffrement **intégral** (`sub_403600`).  
- Fichier **> 1,5 MiB** → **3 fenêtres** de ≤ 256 KiB (`sub_403C00`) : début, `taille/3`, près de la fin.

Sans la privée RSA des opérateurs : pas de récupération des clés AES.

### 7.2 Constantes taille (`.ndata`)

| id | DWORD LE | Valeur | Rôle |
|----|----------|--------|------|
| **11** | `adad2ba1` | `0xA12BADAD` | magic package wrap |
| **13** | `00001800` | **1,5 MiB** | seuil full / partiel (`ctx+20`) |
| **14** | `00000400` | **256 KiB** | taille fenêtre partielle (`ctx+24`) |
| **15** | `00001000` | **1 MiB** | chunk mode full (`ctx+16`) |

### 7.3 Clés de volume — `sub_4015D0` / `sub_4016E0`

```c
// 2× PLAINTEXTKEYBLOB AES-256 (44 o), clé = CryptGenRandom(32)
vol+32 = blobA;  vol+40 = blobB;

// package 117 o → CryptEncrypt RSA → 128 o  (sub_4028C0)
// magique id11 | victim_id | serial | drive_type | aes_key[32] | CRC32(48 o)
vol+36 = wrapA;  vol+44 = wrapB;
vol+48 = 1;      // slot : alterne 1 ↔ 2 après chaque fichier
```

**x32dbg :** buffer avant wrap = `AD AD 2B A1 | … | drive_type=3 | clé 32 o | CRC …` puis `CryptEncrypt(..., bufLen=0x80)`.

Détail layout : [`artefacts/rsa_wrap_package_layout.txt`](artefacts/rsa_wrap_package_layout.txt)

Provider : `PROV_RSA_AES` (`0x18`) + `CRYPT_VERIFYCONTEXT` ; algo `CALG_AES_256` (`0x6610`).

### 7.4 Décision full vs partiel — `sub_402380` → `sub_4033C0`

```c
full = (nFileSizeHigh == 0) && (nFileSizeLow <= *(DWORD*)(ctx+20)); // ≤ 1.5 MiB
ctx[42] = full;
Open File R/W; // retry après kill si sharing violation
if (ctx[42]) sub_403600(ctx, path, h);  // FULL
else         sub_403C00(h, path, ctx);  // PARTIAL
MoveFileW(old, new_name);               // format id 24
```

Si attribut lecture seule : clear temporaire (`ctx+43` / `ctx+44`).

### 7.5 Mode FULL — `sub_403600`

1. Pad EOF → multiple de 16 (zéros).  
2. IV = `CryptGenRandom` 16 o (`sub_402850`).  
3. `CryptImportKey(blob_slot)` + `CryptSetKeyParam(KP_IV)`.  
4. Meta (taille d’origine, basename UTF-16, CRC32 poly `0xEDB88320`) → pad 16 → `CryptEncrypt` → Write EOF.  
5. Write `meta_size`(4) + IV(16) + RSA_wrap(128) + progress(8).  
6. Depuis offset 0 : chunks **1 MiB**, `CryptEncrypt(Final=false)`, écriture in-place ; maj progress.  
7. `SetEndOfFile` sur fin footer ; rename.

### 7.6 Mode PARTIEL — `sub_403C00` + `sub_403AC0`

Même footer / IV / wrap. Contenu : **3** appels `sub_403AC0` (fenêtre ≤ **256 KiB**) :

| # | Offset | Longueur max |
|---|--------|--------------|
| 1 | `0` | 256 KiB |
| 2 | `filesize / 3` | 256 KiB |
| 3 | près EOF (`filesize(+pad) − 256 KiB`) | 256 KiB |

Le reste du fichier reste en clair sur disque (gros ISO/VHD souvent « cassés » quand même).

### 7.7 Footer (vue IR, depuis EOF)

| Offset depuis EOF | Taille | Contenu |
|-------------------|--------|---------|
| −8 | 8 | Compteur / offset de progression |
| −8−128 | 128 | Clé AES wrapée RSA-1024 |
| −8−128−16 | 16 | IV AES |
| −8−128−16−4 | 4 | `meta_size` (LE) |
| −(156+meta_size) | `meta_size` | Meta AES (alignée 16) |

### 7.8 ID victime — `sub_406E50` + `sub_406770`

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

Exemple : `rapport.docx.[A1B2C3D4].[netback@inboxhub.net].makop`

---

## 8. Note de rançon

- **Nom fichier :** `readme-warning.txt` (id **6**)
- **Titre / marqueur :** `YOUR_FILES_ARE_ENCRYPTED` (id **7**)
- **Corps :** id **8** — FAQ anglais, paiement Bitcoin, preuve sur 2 petits fichiers non-DB, contacts :

  - `netback@inboxhub.net`
  - `translog@420blaze.it`

Texte reconstruit : [`artefacts/ransom_note_readme-warning.txt`](artefacts/ransom_note_readme-warning.txt)

---

## 9. Timeline d’exécution (ordre logique)

1. `start` — flags admin / CLI  
2. `sub_4057C0` — CSP AES, ancre `.ndata`, dynapi Wow64 / CreateProcessWithTokenW  
3. `sub_405EA0` — charge listes (excl., priorités, kill, chemins), note, email, extension  
4. `sub_407000` — mutex `m23071644`  
5. `sub_4044F0` — Run key ; threads walk ; kill ; VSS ; chiffrement ; note ; beacon IPLogger ; `Sleep(0x7530)` et **boucle**  

---

## 10. IoCs

| Type | Valeur |
|------|--------|
| MD5 | `1d71f0bef3fba293a0d43bffb6941f21` |
| SHA1 | `60096b25d6865258e24cd313fabfff821af7a228` |
| SHA256 | `d86cacc391d3a515870a28dec4b2f33e90ae000848a23d32f488a0ae96e82262` |
| Mutex | `m23071644` |
| Extension | `.makop` (suffixe final) |
| Pattern rename | `*.[XXXXXXXX].[netback@inboxhub.net].makop` |
| Note | `readme-warning.txt` |
| Emails | `netback@inboxhub.net`, `translog@420blaze.it` |
| Run | `HKCU\SOFTWARE\Microsoft\Windows\CurrentVersion\Run` |
| URL | `iplogger.org/1aWsr7` (443) |
| AES strings key | `a91da6d2be9a4ce8d66176a3063c2b43dd2d3c24d66a095f48d5cf03caca70bc` |

Fichier condensé : [`artefacts/iocs.txt`](artefacts/iocs.txt)

---

## 11. ATT&CK (extrait)

| ID | Technique | Preuve |
|----|-----------|--------|
| T1486 | Data Encrypted for Impact | AES + RSA footer, `.makop` |
| T1490 | Inhibit System Recovery | vssadmin / wbadmin / wmic (id 9) |
| T1547.001 | Registry Run Keys | id 28 / `sub_4043F0` |
| T1489 | Service Stop | kill list id 5 |
| T1134 | Access Token Manipulation | `CreateProcessWithTokenW` / `DuplicateTokenEx` |
| T1083 / T1135 | File & Network Share Discovery | drives + WNet* |
| T1071.001 | Web Protocols | WinINet → iplogger.org |
| T1027 | Obfuscated Files or Information | AES string table `.ndata` |

---

## 12. Captures / debug live

| Élément | Statut |
|---------|--------|
| x32dbg | Mutex `m23071644` ; wrap RSA magic `AD AD 2B A1` ; walk `Desktop\*.*` |
| `CryptEncrypt` wrap | Package 117→128 o confirmé (drive_type=3 FIXED) avant walk fichiers |
| `FindFirstFileW` | `C:\Users\petik\Desktop\*.*` (premier dossier = dir du sample) |
| Mode full `sub_403600` | BP posé ; session MCP a flanché avant hit stable — flux confirmé Hex-Rays |
| Any.RUN | URL non fournie pour ce dossier |

---

## 13. Fichiers produits

| Fichier | Rôle |
|---------|------|
| [`README.md`](README.md) / [`README_EN.md`](README_EN.md) | Rapports FR / EN |
| [`artefacts/ida_export/*.c`](artefacts/ida_export/) | Hex-Rays |
| [`artefacts/decrypted_strings.txt`](artefacts/decrypted_strings.txt) | 43 chaînes |
| [`artefacts/extract_makop_strings.py`](artefacts/extract_makop_strings.py) | Re-extract |
| [`artefacts/aes_strings_key.txt`](artefacts/aes_strings_key.txt) | Clé AES table |
| [`artefacts/rsa_public_key.pem`](artefacts/rsa_public_key.pem) | Pubkey RSA-1024 |
| [`artefacts/ransom_note_readme-warning.txt`](artefacts/ransom_note_readme-warning.txt) | Note |
| [`artefacts/*_list.txt`](artefacts/) | Ext / kill / skip |
| [`artefacts/vss_wbadmin_cmds.txt`](artefacts/vss_wbadmin_cmds.txt) | Anti-VSS |
| [`artefacts/iocs.txt`](artefacts/iocs.txt) | IoCs |

---

## 14. Références + non vérifié

- LevelBlue / Stroz Friedberg — *Dissection Of Makop Ransomware Group* (comportement famille : AES-256, RSA, `+README-WARNING+` / `readme-warning`, ID ProductId+serial)  
- ASEC, Cyfirma, write-ups publics Makop / Core  

**Non vérifié ici :**

- Exécution complète du walk / chiffrement réel de fichiers sur l’hôte  
- Contenu exact du beacon posté à IPLogger (besoin run contrôlé sandbox)  
- Présence d’une GUI interactive dans **ce** build (strings stats id 34–36 présentes ; UI GDI non confirmée en live)  
- Clé privée RSA (absente du sample — normal)

---

*Analyse défensive — ne pas exécuter le sample hors sandbox isolée.*
