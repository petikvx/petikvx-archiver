# Virus.Win64.Moiva.a — `software_reporter_tool.exe` (Chrome Software Reporter Tool infecté)

Langue : Français | English version: [README_EN.md](README_EN.md)

**Sample (fichier local) :** `software_reporter_tool.exe`  
**Famille :** Virus.Win64.Moiva (Kaspersky) — file infector PE64, **alias AV courants : Win64.Expiro.***  
**Hôte légitime :** Google **Software Reporter Tool** (`chrome_cleaner`, version **107.294.200**)  
**Sources :** PE (triage statique) + déchiffrement du corps `.reloc` + session **x64dbg** (MCP)

> Analyse **défensive / IR** uniquement. Le binaire n’a **pas** été lancé depuis l’hôte agent ; la session x64dbg était déjà ouverte par l’analyste.

---

## 0. Synthèse (sandbox code ↔ live)

| Observation | Confirmation |
|-------------|--------------|
| Nom / metadata Google Chrome Cleaner | Version Info : *Software Reporter Tool* 107.294.200, Copyright Google 2015 |
| Détection Moiva / Expiro | Infection parasite de la dernière section `.reloc` (RWX) + hook CRT |
| « Packé Yano » (YARA) | **Faux positif** — chaînes dans `.rsrc` (catalogue ESET / signatures), voir §2.4 |
| Contrôle au démarrage | `start` → `__scrt_common_main_seh` appelle **`loc_140F02000`** (stub virus) au lieu d’un helper CRT |
| Corps viral ~560–580 Ko | Après table reloc réelle + padding : blob haute entropie, déchiffré par blocs de `0x400` |
| x64dbg | Image `0x140000000`, path Desktop, TLS callbacks hôtes puis EP `0x140257720` |

**À retenir pour l’IR :** ce n’est pas un « faux » Software Reporter Tool écrit from scratch : c’est un **vrai binaire Google infecté**. Tout `.exe` touché sur la machine peut l’être de la même façon. Priorité : inventorier les PE avec `.reloc` **exécutable + writable**, `DYNAMIC_BASE` absent, et DataDirectory BaseReloc à 0.

---

## 1. Triage PE / point d’entrée

### 1.1 Identité

| Champ | Valeur |
|-------|--------|
| Type | **PE32+** GUI, machine `AMD64` (`0x8664`) |
| Taille | **15 636 992** octets (pas d’overlay hors dernière section) |
| ImageBase | `0x140000000` |
| AddressOfEntryPoint | RVA **`0x257720`** → VA **`0x140257720`** (`start`) |
| TimeDateStamp | `0x636305DE` → **2022-11-03 00:05:50 UTC** |
| Sous-système | WINDOWS_GUI |
| DllCharacteristics | `0x8120` = `HIGH_ENTROPY_VA \| NX_COMPAT \| TERMINAL_SERVER_AWARE` — **pas de `DYNAMIC_BASE` (ASLR off)** |
| Base Relocation DD | **RVA=0, Size=0** (vidé) |
| CLR DD | 0 (natif, pas .NET) |
| Signature Authenticode | absente / invalide côté Security DD |
| Sections | 14 (profil Chromium : `.text`, `.rdata`, `.pdata`, `.00cfg`, `.gxfg`, `.retplne`, …, **`.rsrc` ~11,6 Mo**, **`.reloc`**) |

### 1.2 Hashes

| Algo | Valeur |
|------|--------|
| MD5 | `4fc5a1955aecc2187718cdbe1962fb88` |
| SHA1 | `94ff809e381b40b8c7f51a0197d95573ff7e410d` |
| SHA256 | `9e3e4c146d9a45099c57b7a038b870fceeba8ab44f43bece994622a02cc77834` |

### 1.3 Version Info (hôte)

| Clé | Valeur |
|-----|--------|
| CompanyName | Google |
| FileDescription | Software Reporter Tool |
| FileVersion / ProductVersion | **107.294.200** |
| OriginalFilename | software_reporter_tool.exe |
| LegalCopyright | Copyright 2015 Google Inc. All Rights Reserved. |

PDB (CodeView) : `...\out\Release_x64\software_reporter_…` — build Chromium chrome_cleaner.

### 1.4 Chaîne d’entrée (hôte + virus)

```c
// start @ 0x140257720
_security_init_cookie();
return __scrt_common_main_seh();

// __scrt_common_main_seh @ 0x1402575AC
// Premier appel CRT DETOURNÉ vers le stub Moiva :
if ( (unsigned __int8) loc_140F02000(1) == 0 ) {
    _scrt_fastfail(7);   // si le stub renvoie 0, le process abort
    ...
}
// … initterm, puis WinMain (chrome_cleaner) @ 0x14001DBE4
```

**À quoi ça sert ?**  
Au lieu de patcher brutalement les premiers octets de l’EP (style Expiro 2013 avec stub de ~1 Ko écrasé), cette variante **détourne le tout premier `call` du CRT** (`__scrt_common_main_seh`). Le stub viral doit renvoyer une valeur « vraie » (non nulle) pour que l’hôte Google continue normalement — l’utilisateur voit toujours un Software Reporter Tool qui « marche », pendant que le virus a déjà tourné.

**x64dbg :** breakpoints posés sur TLS (`0x14016D050`, `0x1401DED30`, `0x140256070`, `0x1401BB4F0`) — callbacks **légitimes** CRT (`cmp edx,3` / init) — puis pause à l’EP `0x140257720`. Image path : `C:\Users\petik\Desktop\software_reporter_tool.exe`.

---

## 2. Infection Moiva — morphologie

### 2.1 À quoi ça sert ?

Un **virus fichier** (pas un ransomware) se **copie dans d’autres PE** sur le disque. Ici le véhicule est un outil Google répandu : chaque lancement exécute d’abord Moiva, qui peut propager l’infection, résoudre des API via PEB, et (selon payload déchiffré) voler des données / maintenir un accès — comportement documenté pour la famille **Expiro/Moiva** (aliases multi-vendeurs).

### 2.2 Section `.reloc` transformée

| Propriété | Valeur | Normal vs infecté |
|-----------|--------|-------------------|
| VA | `0xE72000` | — |
| VirtualSize / RawSize | `0x92000` / `0x91000` | largement au-delà d’une table reloc Chrome |
| Characteristics | **`0xE2000040`** | **WRITE + EXECUTE + DISCARDABLE** — anormal pour `.reloc` (attendu : READ+DISCARDABLE) |
| BaseReloc DataDirectory | **0** | table officielle vidée ; ASLR désactivé (`DYNAMIC_BASE` clear) pour fixer l’ImageBase |
| Début section | ~`0x32D4` octets de vraie table reloc (53 blocs) puis zéros jusqu’à `+0x3400` | |
| Corps viral | dès VA **`0xE75400`** (file `0xE5BE00`), taille utile **`0x8C000`** | entropie ~7,9 |

Artefact brut : [`artefacts/reloc_tail.bin`](artefacts/reloc_tail.bin) (580 608 o).

### 2.3 Stub de déchiffrement @ `0x140F02000`

**Localisation :** fin de `.reloc`, RVA `0xF02000` (file `0xEE8A00`).

**Code net (structure) :**

```c
// loc_140F02000 — stub Moiva (appelé depuis __scrt_common_main_seh avec ecx=1)
push_all_gprs();
rbp = rsp; rsp = align16(rsp - 0x20);

rbx = &virus_body;          // lea rbx, [rip - 0x8CC2A]  → 0x140E75400
rdi = 0;                    // offset dans le corps
push(rbx);                  // sauve base pour après la boucle

do {
    // ~256 opérations polymorphes add/sub/xor/not
    // sur CHAQUE dword du bloc de 0x400 octets pointé par rbx
    polymorphic_fixup_block(rbx);   // offsets 0x00..0x3FC

    rdi += 0x400;
    rbx += 0x400;
} while (rdi != 0x8C000);   // 560 blocs → 573 440 octets

pop(rcx);                   // base originale
call 0x140F00D06;           // entrée déchiffrée (body + 0x8B906)

restore_stack_and_gprs();
// AL doit être non-nul pour ne pas fastfail le CRT
```

Les instructions `add/sub/xor/not dword [rbx+imm]` sont **polymorphes** (constantes différentes selon l’échantillon) : c’est la « signature » Expiro/Moiva moderne sur le decryptor, pas un packer Yano.

Après la boucle : `call` vers **`0x140F00D06`** = corps + **`0x8B906`** (champ header à `+0x14`).

### 2.4 « Yano Obfuscator » — faux positif YARA

La règle `INDICATOR_EXE_Packed_Yano` matche parce que `.rsrc` contient littéralement `YanoAttribute` et `StripAfterObfuscation`.

**Ce n’est pas un packer de ce PE :**

- voisinage immédiat : `BabelAttribute`, `DotfuscatorAttribute`, `SmartAssembly.Attributes`, `Confuser.Core`, chaînes Go (`runtime.GOROOT`) ;
- contexte : catalogue / signatures du **moteur ESET** embarqué dans Chrome Cleanup (`chrome_cleaner_internal\eset\…` dans les paths source) ;
- le binaire est **MSVC natif** (DIE : VC++ / Chromium), CLR directory vide.

Détail : [`artefacts/YANO_FALSE_POSITIVE.txt`](artefacts/YANO_FALSE_POSITIVE.txt).

---

## 3. Corps viral déchiffré

### 3.1 Extraction

Script : [`artefacts/extract_moiva_body.py`](artefacts/extract_moiva_body.py)  
Sortie : [`artefacts/moiva_body_decrypted.bin`](artefacts/moiva_body_decrypted.bin)

| Champ header (LE dword) | Offset | Valeur (ce sample) | Rôle probable |
|-------------------------|--------|--------------------|---------------|
| | `+0x00` | `0x46110` | taille blob #1 |
| | `+0x04` | `0x3D362` | taille blob #2 |
| | `+0x08` | `0x284` | offset blob #1 |
| | `+0x0C` | `0x49F54` | zone code / meta |
| | `+0x10` | `0x4A1A4` | offset blob #2 |
| entry | `+0x14` | **`0x8B906`** | entrée après decrypt stub |
| size | `+0x18` | **`0x8C000`** | taille traitée par la boucle |

SHA256 corps déchiffré : `d0e1295a32c89396885749c5b5e074068d5f274a39c6b016d5b429252fc5b30f`

### 3.2 Blobs embarqués

| Fichier | Plage | Taille | Entropie | Note |
|---------|-------|--------|-----------|------|
| [`moiva_blob1.bin`](artefacts/moiva_blob1.bin) | `+0x284` … | 286 992 | ~7,45 | marqueur type `…PNG…` en tête (pas un PNG valide / pas d’IEND) — payload encore compressé/chiffré (couche 2) |
| [`moiva_blob2.bin`](artefacts/moiva_blob2.bin) | `+0x4A1A4` … | 250 722 | ~7,41 | second architecture / second stage (schéma classique Expiro dual x86/x64) |

### 3.3 Code post-decrypt (obfuscation)

- Prédicats opaques récurrents : `je X` / `jne X` vers **la même** cible (branche inconditionnelle déguisée).
- Résolution API via **PEB** :

```c
// extrait @ VA 0x140EFCAAF (body + 0x876AF)
rax = __readgsqword(0x60);   // PEB
rax = *(rax + 0x18);         // Ldr
r9  = *(rax + 0x20);         // InMemoryOrderModuleList
// puis parcours modules / exports (hash ou compare)
```

Sites PEB observés dans le corps : `+0x87696`, `+0x876AF`, `+0x87F24`, …

Les chaînes API en clair sont rares (résolution dynamique) — normal pour Expiro.

### 3.4 Runtime x64dbg — déchiffrement + couche 2 (confirmé)

Session live (ImageBase `0x140000000`, sample Desktop) :

1. **Stub** `0x140F02000` → boucle → `call 0x140F00D06` avec **RCX = `0x140E75400`** (base corps). Header mémoire = decrypt statique.
2. **Attention :** un BP logiciel sur `0x140F00D06` *avant* le decrypt corrompt le dword (la boucle mute l’INT3). Utiliser un BP hardware *après* decrypt, ou restaurer depuis le corps statique.
3. **VirtualAlloc** @ `0x140F00E55` :
   - taille **`0x3D362 × 3 = 0xB7A26`**, flags `0x3000` / `PAGE_READWRITE`
   - buffer alloué **`0x1F00000`**
   - `RDI=0x3D362`, `R15→blob2` (`0x140EBF5A4`)
4. **Unpacker** `body+0x8ACA6` : pré-copie le blob2 (sans préfixe 3 octets) avec magie PNG, reconstruit un **PE64** dans le workspace :
   - Machine `0x8664`, Optional Magic `0x20B`
   - sections `.text` `.rdata` `.data` `.pdata` `.gfids` `.reloc`
   - code avec prédicats opaques + **hash ROR13** (`rol …, 13`) + PEB `gs:[0x60]`
   - routines d’infection qui testent **`MZ` / `PE` / signature PNG** sur les cibles
5. Retour au CRT / `WinMain` hôte : `CreateFileW` sur  
   `%LOCALAPPDATA%\Google\Software Reporter Tool\software_reporter_tool.log` (comportement légitime chrome_cleaner, retaddr `0x14010C2D9`).

Détails : [`artefacts/moiva_live_notes.txt`](artefacts/moiva_live_notes.txt), [`artefacts/STAGE2_LIVE.md`](artefacts/STAGE2_LIVE.md), [`artefacts/moiva_main_flow.txt`](artefacts/moiva_main_flow.txt).

### 3.5 Limites restantes

- Dump fichier complet du buffer `0x1F00000` (0xB7A26 o) depuis la machine Windows → à recopier dans `artefacts/` (`moiva_stage2_buf.bin` déjà sauvé sur le Desktop debug).
- Walk d’infection exhaustif (extensions, exclusions) en suivant le stage2 après le retour unpacker.
- Payload x86 (`blob1`) non exécuté sur cet hôte PE64.

---

## 4. Effets collatéraux / wallpaper

- **Pas de wallpaper** posé par Moiva sur ce sample.  
- `SystemParametersInfoW/A` n’apparaissent que dans **`.rsrc`** (catalogue). Voir [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt).

---

## 5. Persistance / artefacts runtime + infection (live + littérature)

### 5.1 À quoi ça sert ?

Une fois le stage2 démarré dans un thread worker, Moiva/Expiro **pose un magasin local** (credentials navigateur chiffrés) et un **mutex d’unicité**, puis peut **propager** en patchant d’autres `.exe` (même technique : append + détournement d’un `call`). L’utilisateur continue d’utiliser l’appli hôte (ici Software Reporter Tool) sans signal évident.

### 5.2 Observé sous x64dbg (cette session)

| Artefact | Valeur |
|----------|--------|
| Fichier store | `C:\Users\petik\AppData\Roaming\fc36b5aa2a51efca.bin` |
| Accès | `CreateFileW` **OPEN_EXISTING** + **GENERIC_READ**, depuis stage2 RWX (`ret ≈ 0x1BC1EA`), thread worker (pas le main) |
| Mutex | **`Global\Multiarch.m0yv-fc36b5aa2a51efca-inf`** (`CreateMutexW`, worker TID≈1692, `ret ≈ 0x1C0DE9`) |
| ID machine | Hex `fc36b5aa2a51efca` **partagé** entre le `.bin` et le mutex |

Ces deux IoCs collent au schéma documenté Expiro (Quick Heal / Trend Micro) : `%AppData%\<hex>.bin` + `Global\Multiarch.m0yv-<hex>-inf` (et souvent un second `…-b`).

### 5.3 Infection de PE (mécanisme)

| Couche | Preuve |
|--------|--------|
| Sur **ce** sample | Hook du premier `call` de `__scrt_common_main_seh` → stub `.reloc` ; section dernière **RWX** ; ASLR off |
| Stage2 en RAM | Comparaisons **`MZ` / `PE\0\0` / signature PNG** avant traitement d’une cible |
| Famille (littérature) | Append en fin de dernière section ; patch d’un `call` vers le corps ; exclusions de noms contenant `windefend`, `UIODetect`, `svchost`, `TrustedInstaller`, `ntsvcs` ; possible propagation lecteurs réseau |

**Walk `FindFirstFile*(* .exe)`** depuis le stage2 : **non capturé** dans la fenêtre d’observation (beaucoup d’énumérations **hôte** chrome_cleaner sur `*.lnk` Desktop / IE). BP conditionnels posés ; à laisser tourner pour attraper le scan `.exe`.

Journal : [`artefacts/infection_iocs_live.txt`](artefacts/infection_iocs_live.txt).

### 5.4 C2 / vol (littérature, non vérifié réseau ici)

Expiro moderne : store navigateur dans le `.bin`, contact C2 intermittent, backdoor (cmd / plugins). **Pas de capture réseau** dans cette session.

---

## 6. Timeline d’exécution (statique + live)

1. Loader Windows mappe l’image à `0x140000000` (ASLR off).
2. TLS callbacks **hôte** Chromium/CRT (`0x14016D050`, …) — observés sous x64dbg.
3. `start` @ `0x140257720` → cookie → `__scrt_common_main_seh`.
4. **`call loc_140F02000(1)`** — decrypt `0x8C000` octets par blocs `0x400`.
5. `call 0x140F00D06` — logique virus (PEB, infection, payload).
6. Retour au CRT → `WinMain` chrome_cleaner si le stub a renvoyé succès.

---

## 7. IoCs

### 7.1 Fichier

| Type | Valeur |
|------|--------|
| SHA256 | `9e3e4c146d9a45099c57b7a038b870fceeba8ab44f43bece994622a02cc77834` |
| SHA1 | `94ff809e381b40b8c7f51a0197d95573ff7e410d` |
| MD5 | `4fc5a1955aecc2187718cdbe1962fb88` |
| Corps déchiffré SHA256 | `d0e1295a32c89396885749c5b5e074068d5f274a39c6b016d5b429252fc5b30f` |

### 7.2 Runtime (cette machine)

| Type | Valeur |
|------|--------|
| Fichier | `%AppData%\fc36b5aa2a51efca.bin` (= `%UserProfile%\AppData\Roaming\…`) |
| Mutex | `Global\Multiarch.m0yv-fc36b5aa2a51efca-inf` |
| Pattern | `%AppData%\<16 hex>.bin` + `Global\Multiarch.m0yv-<même hex>-inf` (et souvent `-b`) |

### 7.3 Heuristiques PE (chasse)

- Section nommée `.reloc` avec **`IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_MEM_WRITE`**
- DataDirectory **Base Relocation** nulle alors qu’une grosse `.reloc` existe
- `DllCharacteristics` **sans** `IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE`
- `call` depuis `__scrt_common_main_seh` / CRT startup vers une VA dans la dernière section
- Entropie élevée après la vraie table reloc (~offset `+0x3400` dans la section sur ce sample)

### 7.4 Adresses (ImageBase `0x140000000`)

| Symbole | VA |
|---------|-----|
| `start` | `0x140257720` |
| `__scrt_common_main_seh` | `0x1402575AC` |
| Stub decrypt Moiva | `0x140F02000` |
| Body base | `0x140E75400` |
| Entrée post-decrypt | `0x140F00D06` |
| `WinMain` (hôte) | `0x14001DBE4` |

---

## 8. ATT&CK (pertinent)

| ID | Technique | Preuve sur ce sample |
|----|-----------|----------------------|
| T1204.002 | User Execution: Malicious File | Exécution du PE infecté |
| T1036.005 | Match Legitimate Name/Location | Se fait passer pour Software Reporter Tool Google |
| T1027 | Obfuscated Files or Information | Corps `.reloc` chiffré + polymorphe |
| T1140 | Deobfuscate/Decode | Boucle add/sub/xor/not par blocs `0x400` |
| T1106 | Native API | PEB → modules / exports |
| T1059 / T1055 / T1547… | (famille) | Documentés Kaspersky pour Moiva.a — **payload couche 2 non entièrement dumpé ici** |

---

## 9. Fichiers produits

| Fichier | Description |
|---------|-------------|
| [`README.md`](README.md) / [`README_EN.md`](README_EN.md) | Ce rapport |
| [`artefacts/reloc_tail.bin`](artefacts/reloc_tail.bin) | Queue `.reloc` chiffrée |
| [`artefacts/moiva_body_decrypted.bin`](artefacts/moiva_body_decrypted.bin) | Corps après fixups dword |
| [`artefacts/extract_moiva_body.py`](artefacts/extract_moiva_body.py) | Re-extraction / decrypt |
| [`artefacts/moiva_blob1.bin`](artefacts/moiva_blob1.bin) / [`moiva_blob2.bin`](artefacts/moiva_blob2.bin) | Blobs couche 2 |
| [`artefacts/YANO_FALSE_POSITIVE.txt`](artefacts/YANO_FALSE_POSITIVE.txt) | Note YARA Yano |
| [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt) | Absence wallpaper |
| [`artefacts/moiva_main_flow.txt`](artefacts/moiva_main_flow.txt) | Flux main post-decrypt (nettoyé) |
| [`artefacts/moiva_live_notes.txt`](artefacts/moiva_live_notes.txt) | Notes session x64dbg |
| [`artefacts/STAGE2_LIVE.md`](artefacts/STAGE2_LIVE.md) | Layout PE couche 2 en mémoire |
| [`artefacts/infection_iocs_live.txt`](artefacts/infection_iocs_live.txt) | IoCs runtime infection / mutex / .bin |

---

## 10. Références

- Kaspersky : [Virus.Win64.Moiva.a](https://threats.kaspersky.com/en/threat/Virus.Win64.Moiva.a/)
- Alias courants : Win64.Expiro.Gen.* (cf. rapports CAPE / adware-removal sur d’autres hash Moiva)
- Andrea Allievi — *Anatomy of a new 64-bit file infector* (Expiro 2013) : modèle historique section `.vmp0` + XOR (évolué ici vers hook CRT + fixups dword)
- ESET : *Win64/Expiro* cross-platform infector (2013)

### Non vérifié / partiel

- Fichier dump complet du workspace stage2 (présent sur Desktop Windows, pas encore dans le dossier Articles)
- Infection réelle d’autres `.exe` sur le disque (BP `FindFirstFileW` pas encore hit au moment de la pause log)
- Trafic réseau C2 de cette variante précise
- Exécution du blob x86 (`blob1`)

---

*Rapport défensif — pas d’aide à la propagation ni de decryptor offensif au-delà de l’extraction du corps déjà présent dans le sample.*
