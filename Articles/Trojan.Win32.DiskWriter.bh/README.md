# Trojan.Win32.DiskWriter.bh (MEMZ) — Analyse détaillée

Langue : Français | English version: [README_EN.md](README_EN.md)

**Sample (fichier local) :** `MEMZ.exe.bin`  
**Famille :** MEMZ (trojan destructeur / « joke malware » de Leurak, ~2016 ; ce build PE daté **2018-11-06**)  
**Détection Kaspersky (dossier) :** `Trojan.Win32.DiskWriter.bh`  
**Type :** PE32 GUI natif, **non packé**, manifeste `requireAdministrator`  
**Sources :** binaire + Hex-Rays / IDA 9.4 (`artefacts/ida_export/`, `MEMZ.exe.bin.i64.c`)

> Analyse **défensive / IR**. Aucune exécution du sample sur l’hôte. Pas de reconstructeur de MBR « offensif » : seuls les blobs **tels qu’embarqués** sont extraits pour la documentation.

---

## 0. Synthèse code ↔ comportement

| Observation | Confirmation code |
|-------------|-------------------|
| Sans argument → lance des copies | `start` @ `0x40122D` : 5× `ShellExecuteA(..., "/watchdog")` + `ShellExecuteExA(..., "/main")` |
| `/watchdog` = chien de garde | Thread `sub_40114A` : compte les processus au **même chemin image** ; si le compte **baisse** → vengeance |
| `/main` (ou tout autre arg ≠ `/watchdog`) = destruction | Écriture `\\.\PhysicalDrive0` (64 KiB) + `\note.txt` + 10 payloads écran |
| MBR / début de disque détruit | Stub `byte_4021F8` (0x12F o) + blob `byte_402328` (0x7A0 o) collé à l’offset **510** (`55 AA` + payload boot) |
| « Ne tuez pas le process » | Note + vengeance : 20× MessageBox « MEMZ » puis `NtRaiseHardError` / reboot forcé |
| Pas de rançon / pas de crypto fichiers | `CryptGenRandom` sert uniquement de **PRNG** (`sub_401A37`) |
| Pas de wallpaper BMP/JPG | Aucun `SystemParametersInfo` ; effets = GDI live + bootloader custom (Nyan Cat) |

**En une phrase :** MEMZ s’élève en admin, réécrit le début du disque physique 0 (le PC ne redémarrera plus normalement), affiche une note d’avertissement, puis enchaîne des payloads « joke » (souris, écran, navigateurs…) tout en surveillant ses propres processus — les tuer déclenche BSOD / reboot.

---

## 1. PE / point d’entrée

### À quoi ça sert ? (non expert)

Au lancement, le programme ne commence **pas** directement à casser le disque. Il regarde sa ligne de commande :

1. **Sans argument** → il se relance plusieurs fois en mode « chien de garde », puis une fois en mode « principal », et le processus initial se termine.  
2. **`/watchdog`** → il reste en fond et surveille que personne ne tue les autres copies.  
3. **`/main`** (et tout autre argument) → il fait le gros dégât (disque + effets).

C’est une astuce simple pour avoir **plusieurs processus** avec le même `.exe` : plus difficile à « tout tuer d’un coup » sans déclencher la vengeance.

### PE (triage)

| Champ | Valeur |
|-------|--------|
| SHA256 | `3ff64f10603f0330fa2386ff99471ca789391ace969bd0ec1c1b8ce1b4a6db42` |
| SHA1 | `761168201520c199dba68add3a607922d8d4a86e` |
| MD5 | `a7bcf7ea8e9f3f36ebfb85b823e39d91` |
| Taille | 12 800 octets (0x3200) |
| Machine | PE32 Intel 80386 |
| ImageBase / EP | `0x400000` / RVA `0x122D` → `start` |
| TimeDateStamp | `0x5BE181BC` = **2018-11-06 11:57:48 UTC** |
| Overlay | aucun |
| Packer | non (entropie `.text` ~5.8) |
| Manifest | `requestedExecutionLevel level='requireAdministrator'` → [`artefacts/embedded_manifest.xml`](artefacts/embedded_manifest.xml) |

| Section | VA | Raw size | Entropie (approx.) |
|---------|-----|----------|--------------------|
| `.text` | `0x1000` | `0xC00` | 5.78 |
| `.rdata` | `0x2000` | `0x1C00` | 6.42 |
| `.data` | `0x4000` | `0x200` | 2.32 |
| `.rsrc` | `0x5000` | `0x200` | 4.75 |
| `.reloc` | `0x6000` | `0x200` | 5.91 |

### Imports utiles (sélection)

| DLL | APIs remarquables |
|-----|-------------------|
| KERNEL32 | `CreateFileA`, `WriteFile`, `CreateThread`, `CreateToolhelp32Snapshot`, `OpenProcess`, `SetPriorityClass` |
| USER32 | `BitBlt` via GDI, `MessageBoxA/W`, `SetCursorPos`, `SendInput`, `SetWindowsHookExA`, `EnumWindows`, `ExitWindowsEx`, `DrawIcon` |
| GDI32 | `BitBlt`, `StretchBlt` |
| ADVAPI32 | `CryptAcquireContextA`, `CryptGenRandom`, token privileges |
| SHELL32 | `ShellExecuteA`, `ShellExecuteExA`, `CommandLineToArgvW` |
| WINMM | `PlaySoundA` |
| PSAPI | `GetProcessImageFileNameA` |

`ntdll!RtlAdjustPrivilege` / `NtRaiseHardError` sont résolus **dynamiquement** (`LoadLibraryA` + `GetProcAddress`).

---

## 2. Init — `start` @ `0x40122D`

### 2.1 Branche lanceur (argc ≤ 1)

```c
// start @ 0x40122D — schéma nettoyé
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

### Ce qu’on voit

| Élément | Détail |
|---------|--------|
| 5 watchdogs | Même binaire, argument `/watchdog` |
| 1 main | Argument `/main`, priorité haute |
| Processus parent | Quitte immédiatement après le spawn |

### 2.2 Branche `/watchdog`

```c
if (lstrcmpW(argv[1], L"/watchdog") == 0) {
    CreateThread(..., sub_40114A, ...);          // surveillance
    RegisterClassExA / CreateWindowExA("hax", ...); // fenêtre invisible utile au message pump
    while (GetMessageA(...)) { TranslateMessage; DispatchMessageA; } // boucle infinie
}
```

La WndProc `sub_401000` (@ `0x401000`) intercepte `WM_CLOSE` (16) et `WM_QUERYENDSESSION` (22) pour appeler la **vengeance** `sub_401021` au lieu de se laisser fermer tranquillement.

### 2.3 Branche destructive (`/main` et autres args)

Tout argument autre que `/watchdog` tombe dans le chemin disque + payloads (voir §3 et §6).

---

## 3. Écriture disque — cœur DiskWriter

### À quoi ça sert ?

Windows démarre en lisant le **tout début** du disque (MBR / premier secteur, puis code autour). MEMZ ouvre le disque **physique** `\\.\PhysicalDrive0` en lecture/écriture et y pousse **65 536 octets** fabriqués à partir de deux blobs internes. Après reboot, le firmware/BIOS exécute ce code pirate au lieu du chargeur Windows → machine inutilisable sans restauration bas niveau.

Ce n’est **pas** un ransomware : il n’y a rien à « payer » pour récupérer ; il faut une réparation disque / image / MBR depuis un média sain.

### Code net

```c
// portion destructive de start() — VA autour de 0x4012xx
h = CreateFileA("\\\\.\\PhysicalDrive0",
                GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE,
                NULL, OPEN_EXISTING, 0, NULL);
if (h == INVALID_HANDLE_VALUE) ExitProcess(2);

buf = LocalAlloc(LPTR, 0x10000);          // 64 KiB zerofill
memcpy(buf, byte_4021F8, 0x12F);         // stub boot 303 octets
memcpy(buf + 510, byte_402328, 0x7A0);   // 55 AA + message/graphique boot

if (!WriteFile(h, buf, 0x10000, &written, NULL)) ExitProcess(3);
CloseHandle(h);
```

| Blob IDA | RVA / VA | Taille copiée | Rôle |
|----------|----------|---------------|------|
| `byte_4021F8` | RVA `0x21F8` | **0x12F** (303) | Code boot 16-bit (lit secteurs via `int 13h`, etc.) |
| `byte_402328` | RVA `0x2328` | **0x7A0** (1952) | Commence par `55 AA` (signature MBR à l’offset 510) puis payload (texte « trashed by the MEMZ trojan », « Nyan Cat… », graphismes) |
| Buffer écrit | — | **0x10000** | Contenu reconstruit : [`artefacts/PhysicalDrive0_first_64KiB.bin`](artefacts/PhysicalDrive0_first_64KiB.bin) |

### Ce qu’on voit (artefacts)

| Fichier | Contenu |
|---------|---------|
| [`mbr_code_0x12F.bin`](artefacts/mbr_code_0x12F.bin) | Stub tel qu’embarqué |
| [`boot_message_blob_0x7A0.bin`](artefacts/boot_message_blob_0x7A0.bin) | Signature + suite |
| [`boot_payload_ascii_fragments.txt`](artefacts/boot_payload_ascii_fragments.txt) | Fragments ASCII lisibles dans le blob |
| [`extract_embedded.py`](artefacts/extract_embedded.py) | Re-extraction déterministe |

**Note IR :** sur une machine compromise encore « allumée », le disque est déjà altéré **avant** les effets d’écran. Priorité : couper l’alimentation / isoler, imager, **ne pas redémarrer** si l’on veut encore lire le volume via outils offline.

---

## 4. Note `\note.txt` + Notepad

### À quoi ça sert ?

Pendant que la session Windows tourne encore, MEMZ lâche un fichier texte à la **racine du lecteur courant** (`\note.txt` → typiquement `C:\note.txt`) et l’ouvre avec Notepad. Le message explique que le boot est mort et menace de destruction instantanée si on tue le trojan — ce qui est **vrai** (voir §5).

```c
h = CreateFileA("\\note.txt", GENERIC_READ|GENERIC_WRITE, ..., CREATE_ALWAYS, ...);
WriteFile(h, note_string, 0xDA, ...);   // 218 octets côté PE (NUL inclus dans la taille IDA)
CloseHandle(h);
ShellExecuteA(NULL, NULL, "notepad", "\\note.txt", NULL, SW_SHOWDEFAULT);
```

Texte exact (extrait) : [`artefacts/note.txt`](artefacts/note.txt)

```
YOUR COMPUTER HAS BEEN FUCKED BY THE MEMZ TROJAN.

Your computer won't boot up again,
so use it as long as you can!

:D

Trying to kill MEMZ will cause your system to be
destroyed instantly, so don't try it :D
```

---

## 5. Élévation, watchdog et vengeance

### 5.1 Admin

Le manifeste force UAC admin. L’écriture `\\.\PhysicalDrive0` **échoue** sans privilèges suffisants (`ExitProcess(2)`).

### 5.2 Watchdog — `sub_40114A` @ `0x40114A`

### À quoi ça sert ?

Plusieurs copies MEMZ tournent. Le watchdog compte combien de processus ont **exactement le même chemin d’image** que lui. Si ce nombre **diminue** (quelqu’un a tué une instance dans le Gestionnaire des tâches), il appelle la routine de vengeance.

```c
// sub_40114A — schéma
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
        sub_401021(...);   // vengeance
    prev = count;
    Sleep(10);
}
```

### 5.3 Vengeance — `sub_401021` @ `0x401021`

1. Lance **20 threads** `StartAddress` (@ `0x4010FE`) : chacun pose un hook `WH_CBT` puis affiche une `MessageBoxA` caption **`MEMZ`**, texte tiré au hasard parmi **20** titres insultants ([`revenge_messagebox_titles.txt`](artefacts/revenge_messagebox_titles.txt)). Le hook `fn` (@ `0x4019B5`) **déplace** les MessageBox à l’écran.  
2. `RtlAdjustPrivilege(19 /*SeShutdownPrivilege*/, TRUE, ...)`  
3. `NtRaiseHardError(0xC0000022, ..., OptionShutdownSystem=6, ...)` → BSOD / arrêt dur.  
4. Repli : `AdjustTokenPrivileges(SeShutdownPrivilege)` + `ExitWindowsEx(0x6, 0x10007)` (reboot forcé).

**Pourquoi :** décourager l’utilisateur / l’analyste de tuer le process « à chaud » ; la destruction disque est **déjà** faite, la vengeance rajoute le chaos immédiat.

---

## 6. Payloads écran / « joke » — timeline

### À quoi ça sert ?

Après la note, MEMZ ne s’arrête pas : il démarre **10 boucles** (`sub_401A0F`) qui appellent chacune une routine d’effet. Les délais avant démarrage sont dans une table `{fonction, délai_ms}` en `.rdata` (fichier [`payload_schedule.csv`](artefacts/payload_schedule.csv)).

Le lanceur :

```c
for (j = 0; j < 10; j++) {
    Sleep(schedule[j].delay_ms);
    CreateThread(..., sub_401A0F, schedule[j].payload_fn, ...);
}
while (1) Sleep(10000);
```

`sub_401A0F` appelle en boucle `payload(stage, iter)` et `Sleep(10)` — l’entier retourné par le payload sert de compteur interne de rythme.

| # | Délai avant start | VA | Effet |
|---|-------------------|----|-------|
| 0 | 30 s | `sub_4014CA` | Ouvre URL / appli aléatoire (`ShellExecuteA "open"`) — 34 cibles |
| 1 | 30 s | `sub_40153B` | Sacade le curseur (`SetCursorPos`) |
| 2 | 20 s | `sub_40176C` | Frappe des touches aléatoires (`SendInput`) |
| 3 | 50 s | `sub_401667` | Sons système (`PlaySoundA` : Hand / Question / Exclamation) |
| 4 | 30 s | `sub_4015A2` | Inverse les couleurs du bureau (`BitBlt` ROP `0x330008` NOTSRCCOPY) |
| 5 | 20 s | `sub_4015F8` | Thread MessageBoxW « Still using this computer? » / « lol » + hook CBT |
| 6 | 10 s | `sub_40182D` | Dessine icônes (erreur / warning) sous le curseur et au hasard |
| 7 | 40 s | `sub_401656` | `EnumWindows` → inverse le texte des contrôles (`WM_GETTEXT` / `WM_SETTEXT`) |
| 8 | 60 s | `sub_4017B0` | « Tunnel » visuel (`StretchBlt` rétréci) |
| 9 | 15 s | `sub_401694` | Copie des rectangles d’écran ailleurs (`BitBlt` SRCCOPY) |

### Spam navigateur / apps — `sub_4014CA`

34 entrées (liste complète : [`browser_spam_targets.txt`](artefacts/browser_spam_targets.txt)), mélange de :

- recherches Google `.co.ck` absurdes / toxiques (« remove memz », « virus builder », etc.) ;
- sites (`clubpenguin`, `pcoptimizerpro`, `softonic`) ;
- binaires Windows : `calc`, `notepad`, `cmd`, `write`, `regedit`, `explorer`, `taskmgr`, `msconfig`, `mspaint`, `devmgmt.msc`, `control`, `mmc`.

### PRNG — `sub_401A37`

```c
// CryptGenRandom → entier positif 31 bits
CryptAcquireContextA(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
CryptGenRandom(hProv, 4, &x);
return x & 0x7FFFFFFF;
```

Aucune clé de fichier, aucun chiffrement de documents.

### Wallpaper

**Absent.** Voir [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt). L’impact visuel est temps réel (GDI) + écran du bootloader MEMZ/Nyan Cat après reboot, pas un fond d’écran déposé.

---

## 7. Crypto

| Usage | Détail |
|-------|--------|
| Fichiers victimes | **Aucun** chiffrement |
| `CryptGenRandom` | Uniquement aléa pour positions / délais / choix d’URL |
| Rançon | **Aucune** (destructeur / hoax) |

---

## 8. Note de « rançon »

Il n’y a pas de note de rançon monétaire. La seule note utilisateur est `\note.txt` (§4) + le message du bootloader custom.

---

## 9. Timeline typique (session interactive)

| t | Événement |
|---|-----------|
| 0 | UAC admin ; process lanceur spawn 5× `/watchdog` + 1× `/main` |
| ~0+ | `/main` : écriture 64 KiB sur `PhysicalDrive0` |
| ~0+ | Création `\note.txt` + Notepad |
| +10–60 s | Démarrage progressif des 10 payloads (voir table §6) |
| Continu | Watchdogs mesurent le nombre d’instances |
| Si kill | MessageBox spam « MEMZ » → `NtRaiseHardError` / reboot |
| Reboot | Bootloader MEMZ (Nyan Cat / message « trashed… ») — OS Windows non chargé normalement |

---

## 10. IoCs

### Hashes

| Algo | Valeur |
|------|--------|
| SHA256 | `3ff64f10603f0330fa2386ff99471ca789391ace969bd0ec1c1b8ce1b4a6db42` |
| SHA1 | `761168201520c199dba68add3a607922d8d4a86e` |
| MD5 | `a7bcf7ea8e9f3f36ebfb85b823e39d91` |

### Chemins / objets

| IoC | Détail |
|-----|--------|
| `\\.\PhysicalDrive0` | Cible d’écriture destructive |
| `\note.txt` | Note (souvent `C:\note.txt`) |
| Args | `/watchdog`, `/main` |
| Classe fenêtre | `"hax"` |
| Caption MessageBox | `MEMZ` |
| Mutex | **aucun** observé dans ce build |

### Chaînes marquantes

- `YOUR COMPUTER HAS BEEN FUCKED BY THE MEMZ TROJAN.`
- `RtlAdjustPrivilege` / `NtRaiseHardError`
- `Still using this computer?`

---

## 11. ATT&CK (mapping approximatif)

| Technique | ID | Preuve |
|-----------|-----|--------|
| Masquerading / multi-process | — | Plusieurs instances même path |
| Modify Boot Sector / disk | T1542.003 (idéalement) / impact | `CreateFileA` + `WriteFile` sur `PhysicalDrive0` |
| Inhibit System Recovery (pratique) | T1490 (proche) | Boot cassé |
| Screen Capture / Defacement UI | T1491.001 (esprit) | BitBlt / StretchBlt / DrawIcon |
| Input Capture / Synthetic | T1056.001 (partiel) | `SendInput`, curseur |
| Native API | T1106 | `NtRaiseHardError` |
| Signed Binary Proxy (légers) | — | `ShellExecute` notepad / URLs |
| Force shutdown | T1529 | `ExitWindowsEx` / hard error |

---

## 12. Captures

Pas d’URL Any.RUN fournie pour ce dossier → pas de screenshots sandbox dans ce livrable.

---

## 13. Fichiers produits

| Fichier | Rôle |
|---------|------|
| [README.md](README.md) / [README_EN.md](README_EN.md) | Rapports FR / EN |
| `MEMZ.exe.bin` | Sample |
| `MEMZ.exe.bin.i64` / `.i64.c` | Base IDA + Hex-Rays initial |
| [`artefacts/ida_export/MEMZ.exe.bin.{c,asm,lst}`](artefacts/ida_export/) | Export batch IDA 9.4 |
| [`artefacts/note.txt`](artefacts/note.txt) | Note utilisateur |
| [`artefacts/mbr_code_0x12F.bin`](artefacts/mbr_code_0x12F.bin) | Stub boot |
| [`artefacts/boot_message_blob_0x7A0.bin`](artefacts/boot_message_blob_0x7A0.bin) | `55 AA` + suite |
| [`artefacts/PhysicalDrive0_first_64KiB.bin`](artefacts/PhysicalDrive0_first_64KiB.bin) | Image du buffer écrit |
| [`artefacts/payload_schedule.csv`](artefacts/payload_schedule.csv) | Timeline payloads |
| [`artefacts/browser_spam_targets.txt`](artefacts/browser_spam_targets.txt) | 34 cibles ShellExecute |
| [`artefacts/revenge_messagebox_titles.txt`](artefacts/revenge_messagebox_titles.txt) | 20 textes vengeance |
| [`artefacts/embedded_manifest.xml`](artefacts/embedded_manifest.xml) | Manifeste admin |
| [`artefacts/hashes.txt`](artefacts/hashes.txt) | Hashes |
| [`artefacts/extract_embedded.py`](artefacts/extract_embedded.py) | Script de re-extraction |
| [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt) | Absence de wallpaper |

---

## 14. Références et limites

### Références

- Famille publique **MEMZ** (Leurak) — trojan « joke » destructeur largement documenté (comportement MBR + payloads UI).  
- Détection dossier : **Trojan.Win32.DiskWriter.bh** (Kaspersky naming).  
- Analyse locale : Hex-Rays 9.4 sur ce PE 12 800 o.

### Non vérifié ici

- Exécution sandbox / Any.RUN (URL non fournie).  
- Contenu **pixel-perfect** du bootloader après `int 13h` (seul le blob binaire et fragments ASCII sont extraits).  
- Comportement sous Secure Boot / UEFI GPT moderne (le code cible le paradigme MBR `PhysicalDrive0` ; l’effet exact dépend du firmware).  
- Aucune clé privée / decryptor : **non applicable**.

### Rappels sécurité

Sample = malware destructeur. Ne pas exécuter sur machine utile. La « menace de ne pas tuer le process » est réelle pour la session en cours, mais le disque est déjà écrit : la bonne réponse IR est isolation + imagerie, pas négociation avec le trojan.
