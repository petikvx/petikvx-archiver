# Trojan-DDoS.Win32.StormAttack.a — Analyse détaillée

Langue : Français | English version: [README_EN.md](README_EN.md)

**Sample (fichier local) :** `2026-08-25_7c44cb81bd2a164922500b2cdaa12f35_elex_remcos_wannacry`  
**Famille :** StormAttack / « Storm ddos » (dropper + payload DLL, Chine ~2010)  
**Tag fichier :** `elex_remcos_wannacry` — **trompeur** (ni Remcos ni WannaCry)  
**Sources :** PE + Hex-Rays (`artefacts/ida_export/`) + session **x32dbg** (WoW64) live  

> Analyse **défensive / IR**. Pas d’exécution hors sandbox / debugger déjà ouvert par l’analyste.  
> Sur cette session live : arrêt volontaire sur le premier `MessageBoxA` — **persistance Active Setup non poursuivie**.

---

## 0. Synthèse sandbox / debugger ↔ code

| Observation | Confirmation |
|-------------|--------------|
| Tag `remcos` / `wannacry` | **Faux ami** — strings + logique = installer « Storm ddos » |
| MessageBox au démarrage | Live : `MessageBoxA(NULL, "123", "123", 0)` depuis `WinMain` |
| Mode embarqué | `dword_404120 = 3` → branche **Active Setup** |
| Drop `StormServer.dll` | Ressource PE `DLL` / id `101` / lang `2052` (zh-CN) |
| Injection `LoadLibraryA` | `CreateProcess` (IE/notepad/calc) + `VirtualAllocEx` / `WriteProcessMemory` / `CreateRemoteThread` |
| Payload DDoS | DLL extraite : **creuse** (≈5,5 % d’octets non nuls, **pas de code** exécutable utile) |
| C2 / cibles en clair dans la DLL | `192.168.1.2`, `192.168.1.244` + templates HTTP GET (héritage / build incomplet) |

**En une phrase :** ce binaire est un **installeur multi-modes** (service Windows, Active Setup, injection) pour une famille de bot DDoS « Storm » ; **dans ce sample précis**, la DLL ressource est un PE quasi vide (strings + IAT, section code à zéro), donc l’effet DDoS attendu ne peut pas se réaliser tel quel.

---

## 1. PE / point d’entrée

### À quoi ça sert ? (non expert)

Le fichier que l’on ouvre n’est **pas** le moteur d’attaque réseau. C’est surtout un **programme d’installation** qui :

1. affiche une petite boîte de dialogue,
2. choisit un mode (service, Active Setup, etc.) selon un entier stocké dans le `.data`,
3. extrait une DLL depuis ses ressources,
4. essaie de la faire charger dans un processus légitime (souvent Internet Explorer).

### Triage PE (dropper)

| Champ | Valeur |
|-------|--------|
| Type | PE32 GUI i386 |
| SHA256 | `5bb61248f62945cd4933f00375c77eb094d22c55e33d6e57bbcf2127c19727b5` |
| SHA1 | `119973bb38a7c3546f5cbcba2ac01b11f2076907` |
| MD5 | `7c44cb81bd2a164922500b2cdaa12f35` |
| Taille | 61440 octets |
| ImageBase | `0x400000` |
| EP RVA | `0x2674` → VA `0x402674` (`start` CRT → `WinMain`) |
| TimeDateStamp | `0x4C540F4E` → **2010-07-31 11:55:58 UTC** |
| Linker / libs | MSVC 6.00, MFC 4.2, MSVCRT / MSVCP60 |
| Sections | `.ax` (code), `.rdata`, `.data`, `.rsrc` — pas de packer (entropie basse) |
| Overlay | aucun |

### Session x32dbg (live)

| Élément | Valeur observée |
|---------|-----------------|
| Machine | x32dbg MCP `192.168.1.162:9095` (processus 32-bit / WoW64) |
| PID | `3812` |
| ImagePath | `C:\Users\petik\Desktop\2026-08-25_7c44cb81bd2a164922500b2cdaa12f35_elex_remcos_wannacry` |
| ImageBase | `0x400000` (PEB) |
| Pause initiale | EP `0x402674` (`push ebp` CRT) |
| BP + run | pause `WinMain` `0x401CB0` (label posé) |
| Ensuite | pause `user32!MessageBoxA` — pile : texte/caption → `0x4042C8` = **`"123"`** |
| Config live | `dword_404120 = 3`, `ServiceName = "Storm ddos Server"` |

Le processus a été **laissé en pause** sur ce `MessageBoxA` : pas de validation de la boîte, donc pas d’entrée dans `sub_401900` (Active Setup) pendant l’analyse agent.

---

## 2. Init & machine d’états (`WinMain` @ `0x401CB0`)

### À quoi ça sert ?

Au démarrage, le malware lit un **petit interrupteur** dans sa mémoire (`dword_404120`) pour savoir **quelle recette d’installation** appliquer. Ce n’est pas un argument de ligne de commande : la valeur est **patchée dans le binaire** (ou dans une copie mutée).

### Config embarquée (`.data`)

| Symbole / VA | Valeur (ce sample) | Rôle |
|--------------|--------------------|------|
| `dword_404120` | **3** | Mode d’installation |
| `byte_404124` | **0** | Répertoire cible : 0 = `GetSystemWindowsDirectoryA` |
| `byte_404125` | **0** | Processus d’injection : 0 = `…\Internet Explorer\iexplore.exe` |
| `0x404128` | `Storm ddos Server` | Nom de service |
| `0x404148` | `Welcome to use storm ddos` | DisplayName / texte marketing |
| `0x4041C8` | `Thank you` | 2ᵉ MessageBox (modes 3/4) |
| `0x4042C8` | `123` | 1ᵉʳ MessageBox (texte **et** titre) |
| `0x404020` | `StormServer.dll` | Nom du payload droppé |

Fiche extraite : [`artefacts/config_dropper.txt`](artefacts/config_dropper.txt).

### Code net — `WinMain`

```c
// WinMain @ 0x401CB0
MessageBoxA(NULL, "123", "123", 0);   // toujours

if (mode == 1) {
  // Si ServiceDLL LanmanServer pointe déjà vers StormServer.dll → exit
  // Sinon: drop ressource → %SystemDir%\StormServer.dll
  //       RegSet ServiceDLL ; inject LoadLibrary ; self-delete
}

switch (mode) {
  case 2: // service « Storm ddos Server »
    if (clé service déjà présente)
      StartServiceCtrlDispatcher(ServiceMain=sub_401510);
    else
      CreateService + StartService ; éventuellement self-delete
    break;
  case 3: // <-- CE SAMPLE
    MessageBoxA(NULL, "Thank you", "Thank you", 0);
    sub_401900();  // Active Setup + copie mutée (mode:=4)
    sub_401390();  // cmd /c del <self>
    break;
  case 4:
    MessageBoxA(...);
    sub_401B90();  // drop DLL + inject seulement
    break;
}
```

### Pourquoi ces modes ?

Les auteurs veulent **plusieurs façons** de survivre au reboot (service SCM, Active Setup au logon, ou simple injection) et de **relancer** une copie déjà installée (mode 4 après mutation Active Setup). Pour l’IR : la valeur `dword_404120` dans le fichier disque dit immédiatement quelle branche sera prise.

---

## 3. Effets collatéraux / persistance

### 3.1 Active Setup — `sub_401900` @ `0x401900` (mode 3)

### À quoi ça sert ?

**Active Setup** est un mécanisme Windows (surtout ancien) qui exécute une commande au logon d’un utilisateur si un composant « installé » a un `stubpath`. Le malware s’enregistre comme un faux composant avec un **GUID** et pointe `stubpath` vers une **copie de lui-même**.

```c
// sub_401900 (nettoyé)
guid = CoCreateGuid();                 // ou GUID déjà présent dans le build
path = WindowsDir + "\\" + guid + ".exe";
RegCreateKey(HKLM,
  "SOFTWARE\\Microsoft\\Active Setup\\Installed Components\\" + guid);
RegSetValueEx(..., "stubpath", path);

// Mutate une copie du PE :
copy = read(self);
*(DWORD*)(copy + 0x6A0) = 4;           // force mode 4 sur la copie
copy[0x3058] = 4;
strcpy(copy + 0x3078, guid_string);    // ancre GUID dans le fichier
write(path, copy);
CreateProcess(path);                   // lance la copie mode 4
```

**GUID déjà présent dans ce build :** `{B85D5274-6F7B-4154-A7E1-CF9117522E1F}` (aussi visible en string à l’offset fichier `0x3078`).

**Ce qu’on voit (IR) :** clé sous  
`HKLM\SOFTWARE\Microsoft\Active Setup\Installed Components\{…}`  
valeur `stubpath` → `C:\Windows\{GUID}.exe` (si `byte_404124==0`).

### 3.2 Service Windows — `sub_401FD0` @ `0x401FD0` (mode 2)

- Nom : `Storm ddos Server`
- DisplayName : `Welcome to use storm ddos`
- Description registre : `Thank you`
- Type : propre (`SERVICE_WIN32_OWN_PROCESS`), start `AUTO`
- `ServiceMain` = `sub_401510` : drop DLL + inject, puis marque le service STOPPED

### 3.3 Hijack `LanmanServer\ServiceDLL` — `sub_401260` @ `0x401260` (mode 1)

```c
// Remplace la DLL du service serveur de fichiers
RegOpenKey(HKLM,
  "SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters");
RegSetValueEx("ServiceDLL",
  "%SystemRoot%\\System32\\StormServer.dll");
```

Technique classique de **détournement de ServiceDLL** : au démarrage du service légitime, Windows charge la DLL attaquant.

### 3.4 Self-delete — `sub_401390` @ `0x401390`

Construit `%COMSPEC% /c  del <shortpath> > nul`, lance le processus en priorité basse, remonte sa propre priorité — pattern classique pour effacer l’installeur après déploiement.

---

## 4. Élévation / UAC

Pas de bypass UAC dédié dans le Hex-Rays du dropper. Les écritures `HKLM` / `CreateService` / `%SystemRoot%` **exigent** déjà des droits élevés. Sur un compte standard moderne, une grande partie de la persistance échoue silencieusement (`RegCreateKey` / `OpenSCManager` NULL).

Non vérifié en live au-delà du premier MessageBox (session laissée en pause).

---

## 5. Injection — `sub_401150` @ `0x401150`

### À quoi ça sert ?

Au lieu d’exécuter la DLL « toute seule », le malware démarre un **programme Windows connu** (IE, Notepad ou Calc), écrit le **chemin de la DLL** dans la mémoire de ce processus, puis crée un thread distant sur **`LoadLibraryA`**. Résultat : la DLL est chargée **dans** le processus légitime (camouflage grossier).

```c
// sub_401150(path_to_StormServer_dll)
CreateProcessA(iexplore|notepad|calc, SW_HIDE, ...);
remote = VirtualAllocEx(hProcess, strlen(path)+1, MEM_COMMIT, PAGE_READWRITE);
WriteProcessMemory(hProcess, remote, path, ...);
pLoadLibraryA = GetProcAddress(GetModuleHandleA("Kernel32"), "LoadLibraryA");
CreateRemoteThread(hProcess, pLoadLibraryA, remote);
```

Choix du host : `byte_404125` → `sub_4010C0`.

---

## 6. Drop ressource — `sub_402460` @ `0x402460`

```c
hRes = FindResourceA(NULL, MAKEINTRESOURCE(101), "DLL");
buf  = LoadResource / LockResource / SizeofResource;
WriteFile(path /* CString */, buf, size);
```

| Champ ressource | Valeur |
|-----------------|--------|
| Type | `"DLL"` (nommé) |
| ID | `101` |
| Langue | `2052` (zh-CN) |
| Offset fichier | `0x5060` |
| Taille | `39936` |

Script de re-extraction : [`artefacts/extract_stormserver.py`](artefacts/extract_stormserver.py).

---

## 7. Payload `StormServer.dll` — creux / héritage DDoS

### À quoi ça sert ? (ce que la famille *voulait*)

Les strings restantes décrivent un **bot DDoS** type « Storm » :

- bannière `Storm ddos DNS` / `Strom attack` (faute d’orthographe),
- format de beacon `STORM:%d|%s|%s|%s|%s`,
- fingerprint OS (`Win7` … `WinNT`), RAM, CPU MHz,
- templates HTTP GET (UA IE6 / MyIE / faux Firefox), `Accept-Language: zh-cn`,
- IPs littérales `192.168.1.2` et `192.168.1.244`,
- hooks de persistance dupliqués (`ServiceDLL`, Active Setup, `URLDownloadToFileA`, `WSOCK32`).

### Ce qu’on voit dans *ce* fichier

| Métrique | Valeur |
|----------|--------|
| SHA256 | `0df2765cead245e3a89f9fafbbe5eb42ec7d41386a6c6dc235827539171335fd` |
| MD5 | `0a6b158119d530da50346424fe8b2096` |
| TimeDateStamp | 2010-07-31 11:50:40 UTC |
| ImageBase (header) | `0x10000000` |
| Sections | `.data` (R/W, **pas X** à l’origine), `.rsrc`, `.reloc` |
| Octets non nuls | **2200 / 39936 (5,5 %)** |
| Prologues `push ebp; mov ebp,esp` | **0** |
| Table d’export | vide (`NumberOfFunctions = 0`) |
| Hex-Rays | aucune fonction métier récupérable |

**Conclusion IR :** la ressource est un **PE « hollow »** — en-têtes + IAT + **strings** d’un ancien StormServer, mais **code métier absent / mis à zéro**. Un `LoadLibrary` de cette image ne peut pas livrer la capacité DDoS annoncée. Soit build corrompu / incomplet, soit stub volontairement vidé tout en gardant des indicateurs (noms, HTTP, IPs lab).

Fichiers : [`artefacts/StormServer.dll`](artefacts/StormServer.dll), tentative d’export IDA : [`artefacts/ida_export/StormServer.c`](artefacts/ida_export/StormServer.c) (vide de logique).

---

## 8. Note / UI

Pas de note de rançon. Uniquement des `MessageBoxA` :

| Moment | Texte |
|--------|-------|
| Toujours en tête de `WinMain` | `"123"` / `"123"` |
| Modes 3 et 4 | `"Thank you"` / `"Thank you"` |

Pas de wallpaper / pas de defacement graphique dans ce sample.

---

## 9. Timeline typique (mode 3 — ce sample)

1. Démarrage CRT `0x402674` → `WinMain`
2. `MessageBoxA("123")` ← **pause live ici**
3. *(si l’utilisateur clique OK)* second MessageBox `"Thank you"`
4. `sub_401900` : clé Active Setup + écriture `{GUID}.exe` muté en mode 4 + `CreateProcess`
5. `sub_401390` : suppression de l’installeur via `cmd /c del`
6. Au prochain logon / run de la copie mode 4 : drop + injection de la DLL creuse

---

## 10. IoCs

### Hashes

| Objet | MD5 | SHA256 |
|-------|-----|--------|
| Dropper | `7c44cb81bd2a164922500b2cdaa12f35` | `5bb61248f62945cd4933f00375c77eb094d22c55e33d6e57bbcf2127c19727b5` |
| StormServer.dll (ressource) | `0a6b158119d530da50346424fe8b2096` | `0df2765cead245e3a89f9fafbbe5eb42ec7d41386a6c6dc235827539171335fd` |

### Fichiers / chemins

- `%SystemRoot%\StormServer.dll` ou `%SystemRoot%\System32\StormServer.dll` (selon mode / `byte_404124`)
- `%SystemRoot%\{GUID}.exe` (Active Setup, mode 3)
- Copie sous répertoire système avec attributs `HIDDEN|SYSTEM` (mode service)

### Registre

- `HKLM\SOFTWARE\Microsoft\Active Setup\Installed Components\{B85D5274-6F7B-4154-A7E1-CF9117522E1F}` → `stubpath`
- `HKLM\SYSTEM\CurrentControlSet\Services\Storm ddos Server`
- `HKLM\SYSTEM\CurrentControlSet\Services\LanmanServer\Parameters\ServiceDLL` (si mode 1)

### Réseau (strings payload, non exécutées ici)

- `192.168.1.2`
- `192.168.1.244`
- Motifs HTTP / UA listés §7 ; chaîne `xq1986`

### Mutex / autres

Aucun mutex nommé observé dans le dropper Hex-Rays.

---

## 11. ATT&CK

| ID | Technique | Détail sample |
|----|-----------|---------------|
| T1547.014 | Active Setup | Mode 3 — `stubpath` |
| T1543.003 | Windows Service | Mode 2 — `Storm ddos Server` |
| T1574.001 | DLL Search Order / ServiceDLL hijack | `LanmanServer\Parameters\ServiceDLL` |
| T1055.001 | Dynamic-link Library Injection | `CreateRemoteThread(LoadLibraryA)` |
| T1036 | Masquerading | Hosts `iexplore.exe` / `notepad.exe` / `calc.exe` |
| T1070.004 | File Deletion | `cmd /c del` self |
| T1105 | Ingress Tool Transfer | String `URLDownloadToFileA` dans DLL (code absent) |
| T1498 | Network Denial of Service | Capacité **visée** par la famille ; **non fonctionnelle** dans cette DLL |

---

## 12. Captures / live debug

Pas de captures Any.RUN fournies. Corrélation debugger :

| Étape | Adresse | Note |
|-------|---------|------|
| EP | `0x402674` | CRT `start` |
| `WinMain` | `0x401CB0` | Label MCP : `WinMain StormAttack mode switch` |
| 1ᵉʳ UI | `user32!MessageBoxA` | args → `"123"` |
| BP posés (non atteints) | `0x401900`, `0x402460` | Active Setup / drop ressource |

---

## 13. Fichiers produits

| Fichier | Contenu |
|---------|---------|
| [README.md](README.md) | Rapport FR |
| [README_EN.md](README_EN.md) | Rapport EN |
| [artefacts/stormattack_dropper.exe](artefacts/stormattack_dropper.exe) | Copie du sample |
| [artefacts/StormServer.dll](artefacts/StormServer.dll) | Ressource extraite (hollow) |
| [artefacts/res_DLL_101_2052.bin](artefacts/res_DLL_101_2052.bin) | Même blob (parse ressources) |
| [artefacts/config_dropper.txt](artefacts/config_dropper.txt) | Config `.data` |
| [artefacts/extract_stormserver.py](artefacts/extract_stormserver.py) | Re-extraction défensive |
| [artefacts/ida_export/stormattack_dropper.c](artefacts/ida_export/stormattack_dropper.c) | Hex-Rays dropper |
| [artefacts/ida_export/stormattack_dropper.asm](artefacts/ida_export/stormattack_dropper.asm) / `.lst` | Listings |
| [artefacts/ida_export/StormServer.*](artefacts/ida_export/) | Export DLL (sans logique) |

---

## 14. Références & non-vérifié

**Fait :**

- Triage PE + hashes + DIE (MSVC6 / MFC42)
- Hex-Rays complet du dropper
- Extraction ressource + constat hollow sur la DLL
- Session x32dbg : EP → `WinMain` → `MessageBoxA("123")`, lecture live de `dword_404120`

**Non vérifié / volontairement non fait :**

- Pas d’exécution libre hors debugger ; pas de clic OK au-delà du premier MessageBox (donc pas de création Active Setup / drop observés runtime)
- Pas de trafic réseau (payload sans code)
- Pas de rapport Any.RUN
- Détection AV exacte « StormAttack.a » non recroisée sur VirusTotal dans cette session
- x64dbg (port 9094) injoignable ; analyse live via **x32dbg** uniquement

**Références famille (contexte) :** bots DDoS chinois « Storm » / tools d’attaque HTTP-flood début 2010s — aligné TimeDateStamp 2010-07-31 et UI zh-cn.
