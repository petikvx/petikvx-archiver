# Trojan-Ransom.Win32.Xorist.ln — Analyse détaillée

Langue : Français | English version: [README_EN.md](README_EN.md)

**Sample UPX (fichier packé) :** `…-05d0be6b…7f9a-upx`  
**Cible d’analyse :** `…-unpacked.exe` (**UPX déjà retiré**)  
**Famille :** Xorist / « X0r157 » (ransomware builder open-source style 2012)  
**Détection :** Kaspersky `Trojan-Ransom.Win32.Xorist.ln`  
**Sources :** PE unpacked + **Hex-Rays 9.4** via `~/ida-pro-9.4/idat` → `artefacts/ida_export/` (`.c`/`.asm`/`.lst`) + config builder + sibling `Xorist.lk`  

> Analyse **défensive / IR**. Pas d’exécution hors sandbox tierce.

### En une phrase (non expert)

Petit ransomware **2012** (souvent livré en **UPX**) : il se copie dans `%TEMP%`, se met en persistance, chiffre des fichiers (ici **TEA**), ajoute l’extension **`.EnCiPhErEd`**, laisse `HOW TO DECRYPT FILES.txt`, et affiche une fenêtre « Password ». La note demande **300 ₽ via WebMoney**. Un decryptor public existe pour beaucoup de variantes Xorist (Emsisoft / Kaspersky).

| Ce que ce n’est **pas** | Ce que c’est |
|-------------------------|--------------|
| WannaCry / Conti | Builder Xorist classique (`0p3nSOurc3 X0r157`) |
| Crypto asymétrique RSA | TEA 128-bit (ou XOR 32-bit selon flag) + mot de passe |
| Sample unique orphelin | Quasi-clone de `Xorist.lk` (même code ; config ressource différente) |

---

## 0. Synthèse Hex-Rays ↔ artefacts

| Observation | Confirmation |
|-------------|--------------|
| UPX 3.07 → unpacked 12 KiB | Fichiers `-upx` / `-unpacked.exe` fournis |
| Banner `0p3nSOurc3 X0r157` | `ClassName` UI |
| Note `HOW TO DECRYPT FILES.txt` | `sub_40103A` |
| Persistance `HKLM\...\Run\Alcmeter` | `sub_402422` si `byte_407529==1` |
| Extension `.EnCiPhErEd` | Config builder (`lpSubKey`) |
| Algo **TEA** | `byte_40752C==1` → `sub_40177A` / `sub_4017EC` |
| Mot de passe | MD5 chaîné (`sub_401F15` ×5) vs hash config |
| Self-delete | `ComSpec /c del "…" >> NUL` (`sub_40214B`) |
| Wallpaper | `sub_4010FC` cherche `pussylicker` (BMP) — **pas dans ce PE** (échec silencieux) ; artefact `wallpaper_1x1_placeholder.bmp` |

**Sibling :** `.text` / `.rdata` / `.data` **identiques** à `Trojan-Ransom.Win32.Xorist.lk` (SHA256 `afbd82de…`) ; seuls les **ressources** (mot de passe / note / extension) changent (~840 octets).

---

## 1. Identification (unpacked)

### À quoi ça sert ? (non expert)

On analyse la version **déjà décompressée** : c’est le vrai code. Le `-upx` n’est que l’emballage.

| Champ | Unpacked | UPX (disque) |
|-------|----------|--------------|
| SHA256 | `e034e30ce286d730eb6338ef5626a8e15ba7d6b9a7f1158b2d2883005bae1287` | `05d0be6bbf2ce6d8b29a257629e071836290cf2a83e16641cf08ba5378317f9a` |
| MD5 | `805242256e678b3b8a05aee3a997d0f1` | `33755784b9128aabea98a2d4f0bebb86` |
| Taille | **12288** | 7168 |
| TimeDateStamp | **2012-01-29 18:49:03 UTC** (`0x4F25949F`) | (même image packée) |
| EP | `0x4021D1` (`start`) | stub UPX |
| DIE | PE32 GUI | UPX 3.07 NRV |

Sections unpacked : `.text` / `.rdata` / `.data` / `.rsrc` — pas d’overlay.

---

## 2. Point d’entrée — `start` @ `0x4021D1`

### À quoi ça sert ? (non expert)

Au lancement « première infection », le malware :

1. Charge sa **config** depuis une ressource (extensions, note, flags, hash du mot de passe)  
2. Se **copie** dans `%TEMP%\<nom_aléatoire>.exe`  
3. Pose la **persistance** Run `Alcmeter`  
4. Enregistre l’association shell pour `.EnCiPhErEd`  
5. Parcourt les **lecteurs** et chiffre  
6. Écrit les notes / wallpaper  
7. Se **suicide** via `cmd /c del`

Si la copie TEMP existe déjà (relance), il ouvre plutôt l’**UI mot de passe** (mode decrypt).

```c
// start @ 0x4021D1 — schéma
sub_401F87();                    // charge + XOR-decode config ressource
CopyFileA(self → %TEMP%\\<drop>.exe);
if (flag_persist) RegSetValue(HKLM\\...\\Run\\Alcmeter, temp_exe);
sub_402342();                    // HKCR\\.EnCiPhErEd → classe CRYPTED!
byte_406550 = 0;                 // mode ENCRYPT
for each drive in GetLogicalDrives()
  walk + encrypt matching files (sub_4013A8);
sub_401000();                    // notes / fin
ExitProcess(0);
// (branche alternative) : fenêtre Password + message loop
```

---

## 3. Config builder — ressource `FindResourceA(14, BITMAP)`

### À quoi ça sert ? (non expert)

Xorist est un **kit** : l’auteur choisit extension, note, mot de passe, TEA ou XOR. Tout ça est stocké dans une fausse ressource « bitmap », chiffrée par XOR avec les 16 premiers octets.

Script : [`artefacts/extract_config.py`](artefacts/extract_config.py)  
Fiches : [`artefacts/config_readable.txt`](artefacts/config_readable.txt), [`artefacts/ransom_note_config.txt`](artefacts/ransom_note_config.txt)

| Champ | Valeur (ce sample) |
|-------|---------------------|
| Extension | **`.EnCiPhErEd`** |
| Algo | **TEA** (`byte_40752C = 1`), 64 rounds |
| UI | Russe (`byte_40752D = 1`) |
| Persistance Run | **oui** (`Alcmeter`) |
| Note par dossier | **oui** |
| Tentatives mdp | **9** |
| Drop TEMP | `mB3Tew2BDFbEH1s.exe` |
| Hash vérif. mdp | `011137a3f394bab3b273a40037fc29ad` (après chaîne MD5) |

### Note (extrait)

```
Внимание! Все Ваши файлы зашифрованы!
... отправьте 300 руб на номер webmoney R209250562490
У вас есть 9 попыток ввода кода...
```

### Motifs `PathMatchSpec`

La liste décodée ne contient **qu’une** chaîne : `r209250562490` (le purse WebMoney).  
C’est très probablement une **mauvaise config du builder** (au lieu de `*.doc` / `*.*`). Conséquence : le walk a lieu, mais le **filtre** n’aligne presque aucun fichier « normal ». Le reste du ransomware (persistance, UI, TEA, association `.EnCiPhErEd`) reste actif.

---

## 4. Crypto fichier

### À quoi ça sert ? (non expert)

Deux modes selon le flag builder :

- **XOR 32-bit** (`sub_401748`) — faible  
- **TEA** (`sub_4017EC` encrypt / `sub_4018B0` decrypt), constante delta **`0x9E3779B9`** (`1640531527`) — hobbyist, plus costaud que XOR

Clé de session : **RDTSC** (horloge CPU) → 16 octets (`sub_40124F` / buffers `0x406DB9`).  
Par fichier : dérivation avec le **1ᵉʳ caractère du nom** (XOR + rotations) → clé TEA/XOR locale (`0x406585…`).

```c
// dérivation par fichier (sub_4013A8)
seed = PathFindFileNameA(path)[0];
for (i = 0; i < 16; i++) {
  derived[i] = session_key[i] ^ seed;
  seed = ROL(seed, 1);
}
if (byte_40752C)
  TEA_encrypt_buffer(buf, derived);   // 8-byte blocks
else
  XOR_dword_buffer(buf, session);     // repeating 16-byte key as dwords
MoveFileA(path, path + "." + "EnCiPhErEd");
```

| Paramètre config | Valeur |
|------------------|--------|
| `lDistanceToMove` | **127** (lit/écrit à partir de l’offset 127 — en-tête partiellement intact) |
| `nNumberOfBytesToRead` | buffer heap (valeur builder **2050473** — taille allouée / plafond de lecture) |

**IR :** decryptors Xorist publics (Emsisoft, Kaspersky XoristDecryptor) ciblent exactement cette famille ; garder une paire fichier clair/chiffré aide.

---

## 5. Persistance & traces shell

| Action | Détail |
|--------|--------|
| Run key | `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run` / `Alcmeter` → `%TEMP%\mB3Tew2BDFbEH1s.exe` |
| Association | `HKCR\.EnCiPhErEd` → classe `MQISXQQKMIDJKVK` / affichage `CRYPTED!` |
| Icône | `DefaultIcon` → bmp droppé en TEMP |
| Open | `shell\open\command` → copie TEMP du malware |
| Wallpaper | Cherche ressource BMP `pussylicker` — **manquante** ici (placeholder 1×1 uniquement) |
| Note | `HOW TO DECRYPT FILES.txt` (et éventuellement variante localisée) |
| Cleanup self | `ShellExecute(ComSpec, /c del "<self>" >> NUL)` |

---

## 6. UI mot de passe

Fenêtre classe `0p3nSOurc3 X0r157, motherfucker!` :

- Champ Password / boutons (RU+EN selon flag)  
- Vérif : 5× `CryptCreateHash(CALG_MD5)` chaînés (`sub_401F15`) puis compare à hash config  
- Trop d’essais → message « data irrevocably broken » + éventuelle casse (`sub_40124F(-1)`)

---

## 7. Timeline

```text
t0  UPX unpack (déjà fait) → PE 12 KiB
t1  start: decode config ressource #14
t2  CopyFile → %TEMP%\mB3Tew2BDFbEH1s.exe + Run\Alcmeter
t3  Register .EnCiPhErEd + wallpaper BMP
t4  Walk drives, TEA sur fichiers matchant PathMatchSpec
t5  Notes HOW TO DECRYPT FILES.txt
t6  Self-delete via cmd
---
u0  Relance / double-clic association → UI Password (9 essais)
```

---

## 8. IoCs

| Type | Valeur |
|------|--------|
| SHA256 UPX | `05d0be6bbf2ce6d8b29a257629e071836290cf2a83e16641cf08ba5378317f9a` |
| SHA256 unpacked | `e034e30ce286d730eb6338ef5626a8e15ba7d6b9a7f1158b2d2883005bae1287` |
| Extension | `.EnCiPhErEd` |
| Note | `HOW TO DECRYPT FILES.txt` |
| Run | `Alcmeter` |
| TEMP | `mB3Tew2BDFbEH1s.exe` |
| WebMoney (note) | `R209250562490` |
| Banner | `0p3nSOurc3 X0r157, motherfucker!` |

---

## 9. ATT&CK

| ID | Technique | Preuve |
|----|-----------|--------|
| T1486 | Data Encrypted for Impact | TEA/XOR + `.EnCiPhErEd` |
| T1547.001 | Registry Run Key | `Alcmeter` |
| T1112 | Modify Registry | HKCR associations / icon |
| T1491.001 | Defacement | wallpaper BMP |
| T1059.003 | Command Shell | `ComSpec /c del` |
| T1027.002 | Software Packing | UPX (fichier `-upx`) |

---

## 10. Remédiation IR (indicative)

1. Isoler ; ne pas entrer de « password » d’attaquant.  
2. Supprimer Run `Alcmeter` + copie `%TEMP%\mB3Tew2BDFbEH1s.exe`.  
3. Nettoyer `HKCR\.EnCiPhErEd` / classe associée.  
4. Tenter **XoristDecryptor** (Emsisoft/Kaspersky) avec paire clair/chiffré si dispo.  
5. Restaurer depuis backup / VSS si encore intacts.

---

## 11. Limites

- Pas d’Any.RUN pour **ce** SHA256.  
- Liste `PathMatchSpec` de **cette** config builder semble aberrante (1 motif = purse WM) — à garder en tête pour l’évaluation d’impact.  
- Hex-Rays fourni sur unpacked ; base IDA `.i64` présente.

---

## 12. Fichiers produits

| Fichier | Rôle |
|---------|------|
| `README.md` / `README_EN.md` | Rapports FR / EN |
| `…-upx` / `…-unpacked.exe` | Packé / cible |
| `…-unpacked.exe.i64` / `.i64.c` | IDB + export GUI |
| `artefacts/ida_export/xorist_ln_unpacked.{c,asm,lst}` | Export batch `idat -S export_asm_c.py` |
| `artefacts/extract_config.py` | Decode config |
| `artefacts/config_readable.txt` | Config lisible |
| `artefacts/ransom_note_config.txt` | Note RU |
| `artefacts/hashes.txt` | Hashes |
| `artefacts/wallpaper_1x1_placeholder.bmp` | Seul BMP (1×1) — `pussylicker` absent |
| `artefacts/wallpaper_README.txt` | Détail wallpaper |
| `artefacts/rsrc_*.bin` | Ressources brutes |

---

## 13. Références

- Sibling local `Trojan-Ransom.Win32.Xorist.lk/` (+ `Xorist_FASM.asm`)  
- Article archive `malware-analyze/2024-03-17-ransomware-xorist.md`  
- Emsisoft Xorist decrypter / Kaspersky XoristDecryptor  
- Malpedia `win.xorist`
