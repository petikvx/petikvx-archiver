# Trojan.Win32.Cosmu.bwts (« Zombie ») — Analyse détaillée

Langue : Français | English version: [README_EN.md](README_EN.md)

**Sample (fichier local) :** `2025-12-07_e6d94e245a597a9efc9657bc61ae796a_elex_wannacry`  
**Famille :** Cosmu / « Zombie » (trojan-worm chinois ~2011) — **pas** WannaCry  
**Détection Kaspersky :** `Trojan.Win32.Cosmu.bwts`  
**Packer (fichier disque) :** ASPack 2.xx — analyse ci-dessous sur **Hex-Rays 9.4** du binaire unpacké (`….c`)  
**Sources :** PE + **`….c`** + strings GBK + littérature Cosmu  

> Analyse **défensive / IR**. Pas d’exécution hors sandbox tierce.

---

## 0. Synthèse Hex-Rays ↔ comportement

| Observation | Confirmation code |
|-------------|-------------------|
| Tag fichier `elex_wannacry` | **Trompeur** — rien à voir avec WannaCry |
| Drop `\Zombie.exe` | `sub_401800` → `%SystemDir%\Zombie.exe` |
| MessageBox chinoises | `sub_401A90` (si `xor_key != 0`) |
| « Chiffre » les documents | `sub_401340(..., a3=0)` : XOR + **demi-fichiers inversés** + greffe du PE |
| Les `.exe` deviennent porteurs | `sub_401340(..., a3=1)` : PE + original **en clair** ; clé XOR = 0 |
| `.gho` / `.bak` | **supprimés** (`DeleteFileA`) — destructif |
| Self-delete | `sub_401040` : `%COMSPEC% /c del <self> > nul` |
| Premier lancement vs fichier « infecté » | `WinMain` branche sur footer `sub_4012B0` |

**En une phrase :** au premier run, le malware parcourt tous les lecteurs, transforme les fichiers en **faux `.exe`** qui contiennent une copie de lui-même ; relancer un document « chiffré » affiche la blague chinoise ; relancer un `.exe` parasitée restaure et exécute l’original en silence.

---

## 1. Point d’entrée — `WinMain` @ `0x401F10`

### À quoi ça sert ? (non expert)

Au démarrage, le programme se pose une seule question :

> « Est-ce que **je** suis déjà un fichier victime transformé, ou suis-je encore le malware « propre » ? »

Il regarde les **8 derniers octets**. Si la marque de taille colle → mode **victime / porteur**. Sinon → mode **infection**.

```c
// WinMain @ 0x401F10
GetModuleFileNameA(NULL, self, ...);

if (sub_4012B0(self)) {          // footer présent : fichier déjà "Zombifié"
  // lire meta (56 o) + footer
  if (xor_key != 0)
    sub_401A90(...);            // MessageBox blague (documents)
  else
    sub_401800(...);            // extraire Zombie.exe + restaurer .exe original
} else {
  // premier run : infecter la machine
  for (letter = 'A'; letter <= 'Z'; ++letter)
    if (drive_bit_set)
      sub_401CF0(drive + ":"); // walk récursif
  sub_401040();                 // se supprimer via cmd
}
```

### PE (rappel)

| Champ | Valeur |
|-------|--------|
| SHA256 | `3b04ee0c12725e4d9d3b3befdef43b9732454a3cb7a03bb6b84f2613f31f47ce` |
| MD5 | `e6d94e245a597a9efc9657bc61ae796a` |
| TimeDateStamp | **2011-03-15** |
| Packer disque | ASPack (EP stub) ; logique métier dans le `.c` unpacké |

---

## 2. Marqueur « déjà infecté » — `sub_4012B0`

### À quoi ça sert ?

Sans renommer avec une extension bizarre type `.wncry`, Spora-style, Cosmu doit quand même savoir « ce fichier a déjà été traité ». Il colle un **pied de page de 8 octets** et le vérifie ainsi :

```c
// sub_4012B0
f = fopen(path, "rb");
size = file_size(path);
fseek(f, size - 8, SEEK_SET);
fread(buf, 8, 1, f);          // dword0, dword1
return (dword1 == size);      // oui → infecté
```

| Champ footer | Rôle |
|--------------|------|
| `dword0` | taille du PE malware greffé (offset où commence la meta 56 o) |
| `dword1` | doit valoir **la taille totale du fichier** (marque) |

---

## 3. Infection d’un fichier — `sub_401340` / `sub_401BA0`

### 3.1 Qui est touché ? — `sub_401BA0`

```c
ext = derniers 4 caractères du chemin;

if (ext == ".exe" || ext == ".EXE") {
  if (size <= 0xFA0000)        // ≤ 16 MiB
    sub_401340(path, /*a3=*/1); // mode PORTEUR (pas de XOR)
} else if (ext == ".gho"/".GHO" || ext == ".bak"/".BAK") {
  DeleteFileA(path);            // DESTRUCTION pure
} else {
  if (size <= 0x1F40000)        // ≤ 32 MiB
    sub_401340(path, /*a3=*/0); // mode DOCUMENT (XOR + blague)
}
Sleep(size / 0xA000);           // petite pause proportionnelle
```

**En clair :**

| Type | Action | Pourquoi |
|------|--------|----------|
| Documents / autres | Transformés en `.exe` « piégés » | Afficher la blague + forcer un double-clic |
| Exécutables | Deviennent des **droppers** silencieux | Propager `Zombie.exe` + relancer le vrai programme |
| Ghost / backups | **Effacés** | Casser les restaurations Ghost / `.bak` |

### 3.2 Format du fichier transformé (documents, `a3=0`)

### À quoi ça sert ?

Au lieu d’un vrai chiffrement RSA/AES, Cosmu fabrique un **faux programme Windows** :

1. Il met **sa propre copie** au début (comme un virus classique append/prepend).  
2. Il cache le nom d’origine + une petite clé.  
3. Il mélange le contenu (deuxième moitié puis première) en ajoutant une constante à chaque octet (**XOR additif** / `byte + key`).  
4. Il renomme en **`fichier.ext.exe`**.

Quand la victime double-clique, Windows lance… le malware greffé, qui montre la MessageBox.

```c
// sub_401340(path, a3=0) — schéma nettoyé
out = path + ".tmp";
key = 5166 + (rand() % 8);     // 5166..5173

// 1) recopier tout le PE malware dans out
copy_bytes(self_pe → out);

// 2) meta 56 octets = basename[≤48] || orig_size || key
fwrite(meta, 0x38, 1, out);

// 3) payload mélangé :
//    d'abord les octets [size/key .. fin]  chacun += key
//    puis   les octets [0 .. size/key)     chacun += key
half = orig_size / key;
append_xor_range(path, half, orig_size, key);
append_xor_range(path, 0, half, key);

// 4) footer 8 octets
fwrite({ pe_size, pe_size + orig_size + 64 }, 8, 1, out);

DeleteFile(path);
rename(out → path + ".exe");   // collisions → "..._.exe"
```

Schéma :

```text
┌──────────────────┐
│ PE malware       │  ← exécutable au double-clic
├──────────────────┤
│ meta 56 o        │  nom + taille + clé
├──────────────────┤
│ data XOR+reorder │  "chiffrement" jouet
├──────────────────┤
│ footer 8 o       │  marque sub_4012B0
└──────────────────┘
  nom final : document.doc.exe
```

Fiche : [`artefacts/file_format.txt`](artefacts/file_format.txt)

### 3.3 Mode porteur `.exe` (`a3=1`)

Même greffe PE + meta, mais :

- `key = 0` (forcé),
- contenu original copié **sans** `+ key`,
- donc `WinMain` prend la branche `sub_401800` (pas de MessageBox).

---

## 4. Quand on double-clique un fichier piégé

### 4.1 Blague — `sub_401A90` (documents)

Construit le texte (blocs GBK) puis :

```c
MessageBoxA(NULL, text, "_", MB_ICONEXCLAMATION /*0x30*/);
```

Messages (voir [`artefacts/ui_strings_zh.txt`](artefacts/ui_strings_zh.txt)) : *contacte l’auteur*, proverbe du voyou cultivé, *tu as gagné*, etc.

**Important :** ce n’est **pas** un vrai canal de paiement. Pas de Bitcoin, pas de TOR, pas de `.KEY` RSA. C’est du **theatre**.

### 4.2 Porteur silencieux — `sub_401800`

```c
sys = GetSystemDirectoryA();
zombie = sys + "\\Zombie.exe";

// écrire les `pe_size` premiers octets (le malware) vers Zombie.exe
// attribut HIDDEN
_beginthread(StartAddress, ..., zombie);  // CreateProcess(Zombie) puis DeleteFile

// extraire l'original vers "_<basename>" et le lancer (sub_401B30)
// puis le supprimer après WaitForSingleObject
```

`StartAddress` → `sub_401B30(zombie, 1)` : lance `Zombie.exe` (qui peut **réinfecter**), attend la fin, efface la copie système.

---

## 5. Walk disques — `sub_401CF0`

```c
// récursif : path\*.*
FindFile / FindNextFile
if (directory && !IsDots) {
  if (path ne contient pas "WINDOWS" ni "WINNT")
    sub_401CF0(subdir);       // descente
} else if (file)
  sub_401BA0(filepath);       // infecte / delete
```

Appelé depuis `WinMain` pour chaque bit de `GetLogicalDrives()` (`A:` … `Z:`).

**Pourquoi éviter WINNT/WINDOWS :** ne pas casser le système au point que la machine ne boot plus (la « blague » resterait invisible).

---

## 6. Self-delete — `sub_401040`

```c
comspec = getenv("COMSPEC");
params  = "/c del " + short_path(self) + " > nul";
ShellExecuteExA(Open, comspec, params, SW_HIDE);
// baisse la priorité du processus malware, monte celle du cmd
SHChangeNotify(...);  // rafraîchir l'icône explorateur
```

---

## 7. Timeline

```text
t0  Lancement malware "propre"
t1  Pour chaque lecteur : walk, delete bak/gho, infecter fichiers ≤32 Mo / exe ≤16 Mo
t2  Documents → *.exe (PE+XOR) ; Exe → PE+payload clair
t3  sub_401040 : cmd efface le binaire initial
---
u0  User double-clique rapport.doc.exe
u1  WinMain voit footer → MessageBox chinoise (théâtre)
---
v0  User lance un .exe parasitée
v1  Drop %System%\Zombie.exe (hidden) + thread infection
v2  Restaure et exécute l'original sous "_nom"
```

---

## 8. IoCs

| Type | Valeur |
|------|--------|
| SHA256 | `3b04ee0c12725e4d9d3b3befdef43b9732454a3cb7a03bb6b84f2613f31f47ce` |
| Drop | `%SystemRoot%\System32\Zombie.exe` (ou SysWOW64) |
| Noms victimes | `*.*.exe` / `*_ .exe` (document devenu exécutable) |
| Footer | 8 o fin de fichier, `dword1 == filesize` |
| Clé XOR | constante `5166..5173` (faible — récupérable) |
| UI | MessageBox caption `"_"` + texte GBK |
| Cmd | `/c del … > nul` via `COMSPEC` |

---

## 9. ATT&CK

| Technique | ID | Preuve |
|-----------|-----|--------|
| User Execution | T1204.002 | PE GUI / `.doc.exe` |
| Masquerading | T1036 | tag `wannacry` ; fichiers `*.doc.exe` |
| Hide Artifacts | T1564.001 | `Zombie.exe` attribut hidden |
| File Deletion | T1070.004 | self-del + delete bak/gho |
| Data Encrypted for Impact | T1486 | XOR+reorder (faible crypto) |
| System Binary Proxy | T1218 | `cmd` via COMSPEC |
| Replication (drives) | T1091 | walk `GetLogicalDrives` |

---

## 10. Déchiffrement défensif (idée)

La « crypto » est **réversible sans payer** :

1. Identifier fichiers avec footer `sub_4012B0`.  
2. Lire `pe_size`, meta (`orig_size`, `key`).  
3. Si `key != 0` : retirer `key` à chaque octet, recombiner les deux moitiés (`half = orig_size/key`).  
4. Écrire `orig_size` octets vers le nom stocké dans la meta.

Pas d’implémentation offensive livrée ici ; la méthode suffit pour un script IR interne.

---

## 11. Fichiers produits

| Fichier | Rôle |
|---------|------|
| `README.md` / `README_EN.md` | Rapport FR / EN |
| `….c` | Hex-Rays 9.4 (16 fonctions) |
| `artefacts/ui_strings_zh.txt` | UI chinoise |
| `artefacts/file_format.txt` | Layout fichier infecté |
| `artefacts/hashes.txt` | Hashes / méta |

---

## 12. Références

- Hex-Rays local `2025-12-07_…_elex_wannacry.c`  
- Kaspersky `Trojan.Win32.Cosmu.bwts`  
- Microsoft `Worm:Win32/Cosmu.C`  

**Non vérifié :** exécution dynamique / Any.RUN pour ce SHA256.
