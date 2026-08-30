# AGENTS.md — analyse malware défensive (Articles / virusshare)

Instructions pour un agent qui reverse / documente des samples (VirusShare, dumps, ransomware, etc.).

**Références de qualité (à égaler, pas à copier aveuglément) :**

| Dossier | Ce qu’il illustre le mieux |
|---------|----------------------------|
| `DarkRace Ransomware/` | Config XOR, overlay Conti, bat reconstruit, § crypto **ligne à ligne** |
| `Trojan-Ransom.Win32.Spora.a/` | Hex-Rays croisé, blobs AES extraits, ID / `.KEY` / footer **expliqués pour non-experts** + code net |
| `Trojan.Win32.Diztakun.arpg/` | Scareware .NET/WPF : décompil C#, bat reconstruit, chaîne multi-étages **lisible non-expert** |
| `Trojan.Win32.Cosmu.bwts/` | Packer ASPack + Hex-Rays, faux ransomware XOR, script IR de recovery |
| `Ransomware.babuk-btcware/` | Schémas Mermaid (flux + crypto), footer live x64dbg, **§13 livrables compact** (libellés courts) |

Tous ont `README.md` + `README_EN.md` bilingues.

---

## Mission

Analyse **défensive / IR / recherche** uniquement :

1. Identifier le sample (hashes, type PE/ELF, sections, imports)
2. Croiser **binaire** + **décompil Hex-Rays / IDA** (fichier `.c` si présent — le demander si absent et utile)
3. Optionnel : enrichir avec rapport **Any.RUN** (URL fournie) + screenshots
4. Produire un rapport bilingue + artefacts extraits (config, clés pub, scripts, note…)
5. **Stop** : livrer en local. **Ne pas** exécuter le malware hors sandbox tierce. **Ne pas** `git commit` / `git push` sauf demande explicite.

**Interdit :** améliorer le malware, aider au déploiement, écrire un encryptor/decryptor offensif, fournir une clé privée absente du sample, exécuter le binaire sur la machine hôte.

---

## Contexte workspace

- **Racine Articles** = dossier parent de **ce** `AGENTS.md` (ne pas hardcoder `Downloads/` vs `Documents/` : vérifier avec `pwd` / chemin réel du workspace).
- Samples bruts typiques : `…/virusshare/` (ou chemin fourni par l’utilisateur).
- Chaque famille / sample a **son propre sous-dossier**. Travailler **dedans** (ne pas mélanger avec DarkRace / Spora / un autre sample).
- S’il n’y a qu’un PE à la racine Articles : créer un sous-dossier (famille ou SHA256 court), y placer le sample, y écrire les livrables. **Ne pas** créer de doublon si le sample est déjà dans un sous-dossier dédié.
- Mettre à jour `Articles/README.md` (section Malware Analysis) quand un **nouvel** article est livré, sauf si l’utilisateur dit le contraire.

---

## Workflow type

### 0. Inventaire

```bash
ls -la
file <sample>
sha256sum <sample>   # aussi md5 / sha1
```

Repérer : binaire (natif vs CLR/`mscoree` vs **PyInstaller**/`MEI`/`pyiboot`), décompil, URL Any.RUN, notes / configs déjà là.  
**Pas d’exécution** locale du malware (`wine` sur le sample, `./`, sandbox hôte non demandée).  
- PE **natif** → §2 (`idat` + Hex-Rays)  
- PE **.NET** → §2a (`dotnet ilspycmd … -p -o source`)  
- PE **PyInstaller** → §2b (`pyinstxtractor` + `pycdc`)  
- Si déjà **actif dans x64dbg/x32dbg** (MCP) → §2c en parallèle (approfondir + enrichir le rapport en cours)

### 1. Triage binaire (statique)

- PE/ELF : machine, sections, EP, TimeDateStamp, overlay
- Imports (parser Python OK)
- Strings ASCII + Unicode (mutex, note, onion, cmd, crypto API…)
- Packer / haute entropie — le noter

### 2. Export IDA / Hex-Rays (obligatoire si PE natif analysable)

Installer / chemin : **`~/ida-pro-9.4`**. Script batch déjà fourni :

`~/ida-pro-9.4/scripts/export_asm_c.py`

Sur le binaire **à analyser** (souvent l’**unpacked** si UPX/ASPack déjà retiré) :

```bash
export TVHEADLESS=1
IDA=~/ida-pro-9.4
SAMPLE="/chemin/vers/sample-unpacked.exe"
OUT="$(dirname "$SAMPLE")/artefacts/ida_export"
mkdir -p "$OUT"

"$IDA/idat" -A \
  "-S$IDA/scripts/export_asm_c.py --outdir $OUT --prefix $(basename "$SAMPLE")" \
  "$SAMPLE"

# Par défaut : ne pas conserver les bases IDA (lourdes, non livrables)
rm -f "$SAMPLE".i64 "$SAMPLE".id0 "$SAMPLE".id1 "$SAMPLE".id2 \
      "$SAMPLE".nam "$SAMPLE".til "$SAMPLE".idb 2>/dev/null || true
find "$(dirname "$SAMPLE")" -maxdepth 2 \( -name '*.i64' -o -name '*.id0' -o -name '*.id1' \
  -o -name '*.id2' -o -name '*.nam' -o -name '*.til' \) -delete 2>/dev/null || true
```

Sorties attendues dans `artefacts/ida_export/` :

| Fichier | Contenu |
|---------|---------|
| `*.c` | Hex-Rays **toutes** les fonctions |
| `*.asm` | Listing assembleur |
| `*.lst` | Listing désassemblage |

- **Par défaut : supprimer les `.i64`** (et sidecars IDA `.id0`/`.id1`/`.id2`/`.nam`/`.til`/`.idb`) après l’export Hex-Rays — **ne pas** les livrer ni les laisser traîner dans le dossier sample. Les livrables IDA restent `artefacts/ida_export/*.{c,asm,lst}`.  
- Ne garder un `.i64` que si l’utilisateur le demande explicitement (session IDA interactive en cours).  
- PE32 : `idat` + decompiler x86 (`hexx64` côté IDA 9 gère aussi le 32-bit).  
- Lier ces fichiers dans les README (sources + tableau livrables §6.1).  
- Ensuite seulement : croiser le `.c` avec le triage (§2d). Si le sample est déjà actif sous x64dbg/x32dbg → §2c en parallèle.

### 2a. Décompil .NET (obligatoire si assembly CLR / WPF / etc.)

Pas besoin d’IDA : utiliser **`ilspycmd`** (dotnet tool) :

```bash
mkdir -p source
dotnet ilspycmd "$SAMPLE" -p -o source
```

- `-p` : projet / sources (fichiers `.cs` + `.csproj`)  
- Sortie typique : `source/` (ou `analysis/decompiled/` si on aligne sur Diztakun)  
- Lier le dossier dans les README ; citer les classes / méthodes nettes (ex. `MainWindow.WorkWorkWorkWork`).

### 2b. PyInstaller / Python frozen (obligatoire si détecté)

Indices : DIE `PyInstaller`, strings `MEI`, `pyiboot`, `PYZ-00.pyz`, `PyInstaller:`.

Outils locaux :

| Outil | Chemin |
|-------|--------|
| Extracteur | `~/petikvx-ressources/work/pyinstxtractor.py` (copie aussi dans `~/sandbox/python/`) |
| Décompil bytecode | `~/sandbox/python/pycdc.x86_64` (+ `pycdas.x86_64` pour disasm) |

**Minimum viable :**

```bash
SAMPLE="/chemin/vers/malware.exe"
WORKDIR="$(dirname "$SAMPLE")"
cd "$WORKDIR"
python3 ~/petikvx-ressources/work/pyinstxtractor.py "$(basename "$SAMPLE")"
EXT="$(ls -d "$WORKDIR"/*_extracted 2>/dev/null | head -1)"
mkdir -p "$WORKDIR/source_py"
PYCDC=~/sandbox/python/pycdc.x86_64
# Décompiler entrypoint + modules métier (*.pyc / PYZ) ; ignorer échecs non bloquants
for f in "$EXT"/*.pyc "$EXT"/PYZ.pyz_extracted/*.pyc ; do
  [ -f "$f" ] || continue
  "$PYCDC" "$f" > "$WORKDIR/source_py/$(basename "$f" .pyc).py" 2>/dev/null || true
done
```

Notes :

- Même version majeure de Python que le freeze si possible ; tenter quand même.  
- Si `pycdc` échoue : noter la limite ; fallback `decompyle3` / `uncompyle6` / `pycdas`.  
- Livrer / lier : `*_extracted/` + `source_py/*.py`.  
- Chercher ensuite : C2, crypto, stealer, droppers, configs (souvent clair ou base64 trivial).

### 2c. Debug live x64dbg / x32dbg (si le sample est déjà actif)

Serveurs MCP : `x64dbg`, `x32dbg` (`~/.grok/config.toml`).  
**Ne pas** lancer le malware sur l’hôte agent. En revanche, si l’utilisateur a **déjà** le sample (ou un unpack) ouvert / en cours d’exécution **sous x64dbg/x32dbg** sur la machine de debug :

1. **Vérifier via MCP** que le module / processus actif correspond au sample analysé (nom, chemin, image, ImageBase).
2. **Si actif** — approfondir **immédiatement** l’analyse et le **rapport en cours** (`README.md` / `README_EN.md`) :
   - Registres, pile, mémoire (blobs déchiffrés, config en clair, clés session, buffers note/C2…).
   - Breakpoints / pas-à-pas sur les routines critiques déjà repérées dans le `.c` / `.cs` (crypto, walk, anti-recovery, init).
   - Corréler VA / `sub_XXXX` Hex-Rays ↔ comportement live ; noter ce qui n’est visible qu’au runtime.
   - Intégrer ces faits dans les § concernés (pas un dump debugger orphelin en annexe seule).
   - Extraire les artefacts utiles dans `artefacts/` (ex. `x64dbg_session_*.bin`, `sample_footer_live.bin`, notes `x64dbg_*.txt`).
3. **Si inactif / MCP down** : poursuivre le workflow statique (+ Any.RUN si URL). Ne pas démarrer le sample depuis l’agent.

**Règles pratiques (VM de debug) :**

| Sujet | Règle |
|-------|--------|
| Fichiers de test | **Disque local VM** (`C:\Windows\Temp\…`, `C:\Windows\System32\…`, etc.). **Éviter** Desktop redirigé / dossier partagé / chemin réseau. |
| Création de fichier | Préférer un fichier **déjà présent** sur la VM, ou créé à la main (Notepad). Se méfier de `DumpMemory` MCP (handles / chemins ambigus). |
| Breakpoints | Privilégier **software BP**. Après session sale : `bphwc`, `bplc`, `bpmc` + `DeleteAllBreakpoints`. Se méfier des **HW BP collants**. |
| Portée | Stop avant walk / chiffrement massif sauf demande explicite (« VM OK » ≠ chiffrer tout le disque). |
| Artefacts | Dumps + notes dans `artefacts/` **et** prose dans le § technique concerné. |

x32dbg pour PE32, x64dbg pour PE64. Toute observation live reste **défensive / IR** : documenter, extraire — pas d’aide au déploiement ni de decryptor offensif.

### 2d. Croisement avec le décompil (`.c` / `.cs` / `.py`)

Prioriser (adapter à la famille) :

| Zone | Chercher |
|------|----------|
| Entry | `main` / `WinMain` / `start` / `App.Main` / `__main__` — branches (`/u`, admin…) |
| Init | mutex, decrypt blobs/config, état/reprise, VSS |
| Crypto | clés session, wrap RSA/ECC/TEA/XOR, ID victime, `.KEY`, footer fichier |
| Impact | walk, catégories/ext, rename ou non, note |
| Anti-recovery | `vssadmin`, `wmic`, `bcdedit`, services, logs |
| Cleanup | self-delete, shortcuts worm, reboot, wallpaper |

Expliquer le **pourquoi**. Pour les routines critiques : **code nettoyé** (noms lisibles) + prose « non expert » — voir barre qualité ci-dessous. Ne pas coller le Hex-Rays / ILSpy / bytecode brut illisible.

### 3. Config / blobs embarqués

XOR / AES / overlay : localiser VA + clé, extraire, script de re-extraction, mapper **chaque** champ → comportement.  
Pubkeys → PEM/DER + fiche texte. Listes (ext, whitelist) **exhaustives**.

### 3bis. Wallpaper / fond d’écran (obligatoire dès que trouvé)

Dès que le sample **pose ou embarque** un wallpaper (BMP/JPG/PNG ressource, drop `%TEMP%`, `SystemParametersInfoA(SPI_SETDESKWALLPAPER)`, `HKCU\...\Wallpaper`, etc.) :

1. **L’extraire** dans `artefacts/` (ex. `wallpaper.bmp` / `wallpaper.jpg`) — pas seulement le mentionner  
2. Le **lier** dans les README FR + EN (tableau artefacts + § effets collatéraux / defacement)  
3. Si le code cherche une ressource absente (ex. nom `pussylicker` introuvable) : le **dire clairement** + garder tout placeholder trouvé (même 1×1) avec une courte note `wallpaper_README.txt`

Ne pas attendre une demande utilisateur : dès que c’est là, on sort le fichier.

### 4. Any.RUN (si URL)

Verdict, process tree, drops, cmdline ; screenshots → `anyrun_screenshots/` ; corréler sandbox ↔ `sub_XXXX`.

### 5. Artefacts runtime

Note, bat/cmd, IoCs (hashes, mutex, ext, chemins, emails, onion…). Scripts Python de decode/extract quand ça aide la relecture (ex. ID victime Spora).  
**Wallpaper** : voir §3bis — extraction fichier dès que présent.

**Convention de noms (recommandée) sous `artefacts/` :**

| Zone | Exemples |
|------|----------|
| IDA | `artefacts/ida_export/*.{c,asm,lst}` |
| Scripts | `extract_*.py`, `decode_*.py` |
| Crypto | `rsa_pubkey.pem`, `*_README.txt`, `footer_*_layout.txt` |
| Live debug | `x64dbg_*.bin`, `x64dbg_*.txt`, `sample_footer_live.bin` |
| Strings / listes | `strings_ascii.txt`, `services.txt`, `skip_names.txt` |

### 6. Livrables (dossier du sample)

| Fichier | Contenu |
|---------|---------|
| `README.md` | Rapport **français** (structure + barre qualité) |
| `README_EN.md` | **Même** fond en anglais + liens croisés FR/EN en tête |

Selon pertinence : config déchiffrée, `extract_*.py`, pubkey, note HTML/txt, `anyrun_screenshots/README_captures.md`.  
**PE natif :** `artefacts/ida_export/*.{c,asm,lst}` (voir §2).  
**.NET :** `source/` ou `analysis/decompiled/` via `dotnet ilspycmd … -p -o …` (voir §2a).  
**PyInstaller :** `*_extracted/` + `source_py/*.py` via `pyinstxtractor` + `pycdc` (voir §2b).  
**Si wallpaper trouvé :** fichier image dans `artefacts/` + entrée dans le tableau des fichiers produits (FR et EN).

```markdown
Langue : Français | English version: [README_EN.md](README_EN.md)
```

```markdown
Language: English | French version: [README.md](README.md)
```

#### 6.1 Tableau « Fichiers produits » (§13) — format compact (obligatoire)

Les viewers / TUI tronquent souvent les **chemins longs** (`/home/.../artefacts/...`) → affichage coupé avec `…`.  
**Règle :** dans §13 FR **et** EN, utiliser un tableau **compact** à 3 colonnes :

| Groupe | Fichier | Rôle |
|--------|---------|------|

- **Groupe** : catégorie courte (`Rapport`, `Sample`, `IDA`, `Note`, `Crypto`, `Listes`, `Live`, `Strings`, `Screenshots`…).  
- **Fichier** : lien Markdown dont le **texte visible = nom court** (basename), et la **cible = chemin relatif** depuis le dossier du sample.  
- **Rôle** : une ligne factuelle, sans chemin absolu.  
- **Pas** de chemins absolus (`/home/petik/...`) dans le libellé du lien.  
- **Pas** de globs morts (`path_excl_*.txt`, `strings_*.txt`) : une ligne **par fichier réel**.  
- Une courte phrase d’intro OK : *« Libellés courts (cliquables) ; chemins sous \`artefacts/\`. »*

**Bon :**

```markdown
| Groupe | Fichier | Rôle |
|--------|---------|------|
| IDA | [FOX_V2_FINAL.c](artefacts/ida_export/FOX_V2_FINAL.c) | Hex-Rays |
| Live | [sample_footer_live.bin](artefacts/sample_footer_live.bin) | Footer `2XOF6202` |
| Listes | [path_excl_windows.txt](artefacts/path_excl_windows.txt) | Excl. Windows |
| Listes | [path_excl_cloud.txt](artefacts/path_excl_cloud.txt) | Excl. cloud |
```

**Mauvais (à éviter) :**

```markdown
| [artefacts/ida_export/FOX_V2_FINAL.c](artefacts/ida_export/FOX_V2_FINAL.c) | … |
| [/home/petik/.../artefacts/foo.bin](/home/petik/.../artefacts/foo.bin) | … |
| [artefacts/path_excl_*.txt](artefacts/path_excl_windows.txt) | … |
```

Référence d’exemple : `Ransomware.babuk-btcware/README.md` §13.

#### 6.2 Checklist fin de livrable (avant de dire « done »)

- [ ] `README.md` + `README_EN.md` — **même** niveau de détail  
- [ ] §13 compact (Groupe \| Fichier \| Rôle) — pas de chemins absolus / globs  
- [ ] Hashes MD5 + SHA1 + SHA256  
- [ ] Export selon type : IDA / `ilspycmd` / pyinst+pycdc  
- [ ] **Bases IDA `.i64` (+ sidecars) effacées** dans le dossier sample (sauf demande contraire)  
- [ ] Listes exhaustives (ext / whitelist / services…) — pas de `…`  
- [ ] Wallpaper extrait **ou** absence explicitement dite  
- [ ] §14 : non-vérifié listé (pas d’exec hôte, pas de privkey absente, etc.)  
- [ ] `Articles/README.md` mis à jour si **nouvel** article  
- [ ] §0 synthèse en **liste empilée** (pas tableau 2 colonnes large)  
- [ ] Si flux non trivial : schémas Mermaid (voir structure 0bis)  
- [ ] Si x64dbg/x32dbg actif : faits live intégrés + artefacts sous `artefacts/`

---

## Structure de rapport (adapter les titres à la famille)

Numérotation claire ; **ne pas survoler**. Ordre type :

0. Synthèse sandbox ↔ code (**liste empilée**, pas un tableau 2 colonnes large — voir ci-dessous)  
0bis. **Schémas** (Mermaid) — si flux non trivial (ransomware, multi-étages, crypto conditionnelle)  
1. PE / point d’entrée (+ machine d’états si reprise)  
2. Init (mutex, blobs, pubkey…) — `2.1`, `2.2`…  
3. Effets collatéraux (registre, shortcuts, icône, **wallpaper extrait**…)  
4. Élévation / UAC  
5. Anti-recovery  
6. Walk / exclusions / catégories (listes complètes)  
7. Crypto — **sous-sections détaillées** (payload, ID, `.KEY`/config, encrypt fichier…)  
8. Note de rançon  
9. Timeline  
10. IoCs  
11. ATT&CK  
12. Captures  
13. Fichiers produits (**format compact** §6.1)  
14. Références + ce qui n’a **pas** été vérifié  

### Schémas Mermaid (recommandé)

Dès que le comportement n’est pas trivial (ransomware, dropper multi-étages, crypto par taille/catégorie) :

| Schéma | Contenu typique |
|--------|-----------------|
| **S1** | Flux global : entry → anti-analyse → init → impact → cleanup |
| **S2** | Opération critique : chiffrement fichier / drop / C2 |
| **S3** | Branches conditionnelles (taille fichier, catégories, états de reprise) |

Les placer tôt (après la synthèse). Référence : `Ransomware.babuk-btcware/README.md` (S1–S4).

### §0 Synthèse — format empilé (obligatoire en TUI / largeur étroite)

Les tableaux **2 colonnes** (Observation | Confirmation) sont souvent **coupés** (`…`) dans les viewers étroits.  
**Préférer une liste empilée** : observation en gras, confirmation **en dessous** (préfixe `→`), liens courts vers artefacts.

```markdown
- **Mutex** `NomDuMutex`
  → `CreateMutexA` dans `start`

- **Note USDT** dans `.data`
  → [ransom_note.txt](artefacts/ransom_note.txt)
```

Référence : `Ransomware.babuk-btcware/README.md` §0.

### §10 IoCs — format tableau (obligatoire)

Éviter les IoCs « en prose ». Utiliser des tableaux copiables (cellules **courtes** ; sinon passer en liste empilée comme §0) :

```markdown
| Type | Valeur |
|------|--------|
| SHA256 | `…` |
| MD5 | `…` |
| Mutex | `…` |
| Note / extension / magic | `…` |
| Chemins / GUIDs / CLI | `…` |
```

Quand l’utilisateur dit « détail le §X » : enrichir **ce** § dans **FR et EN** sans alléger le reste.

---

## Barre qualité rédactionnelle (obligatoire)

Objectif : un lecteur IR **non expert reverse** doit comprendre *ce qu’il voit* ; un reverse doit quand même retrouver les `sub_XXXX`.

### Pour chaque § technique important (surtout crypto / ID / artefacts)

1. **« À quoi ça sert ? »** en tête — 5–15 lignes, analogie OK, vocabulaire simple.  
2. **Code net** ensuite — pseudo-C lisible (pas dump Hex-Rays tel quel) ; citer `sub_XXXX` / VA.  
3. **« Ce qu’on voit »** — tableaux avant/après, Bureau / `%AppData%`, sandbox.  
4. **Exemple concret** si possible (ID Any.RUN, chemin drop, taille footer…).  
5. **Pourquoi** le malware fait ça (pas seulement le quoi) + note IR si utile (quoi collecter).

### Crypto / ransomware (si pertinent)

Exiger explicitement dans le rapport :

- Primitive(s) + wrap (RSA/ECC/…)  
- Footer / magic / taille  
- Rename / extension  
- **Politique taille / partial encrypt** si présente (seuils + schéma)  
- Pubkey extraite (PEM/DER) + phrase claire : **pas de clé privée auteurs dans le sample**

### Style

- FR dans `README.md`, EN dans `README_EN.md` — **même niveau de détail** des deux côtés  
- Tableaux pour IoCs, mappings, listes d’extensions  
- Affirmatif ; écrire explicitement le non-vérifié (pas d’exec locale, pas de privkey auteurs…)  
- Pas de jargon inventé ; termes établis (VSS, overlay, footer, wrap RSA…)  
- Éviter les § qui ne sont que des listes d’API sans prose

### Anti-patterns (à éviter)

- Coller Hex-Rays sans renommer ni expliquer  
- « Il chiffre les fichiers » sans footer / primitive / rename  
- Listes tronquées (`…`) pour whitelists / extensions  
- FR riche / EN résumé (ou l’inverse)  
- Decryptor offensif ou clé privée absente du sample  
- Mentionner un wallpaper / `SPI_SETDESKWALLPAPER` **sans** extraire l’image (ou sans expliquer l’absence)  
- §13 livrables avec **chemins absolus** / libellés trop longs / globs `*` (affichage coupé `…`) — utiliser le **format compact** (§6.1)  
- §0 synthèse en **tableau 2 colonnes large** (tronqué en TUI) — utiliser la **liste empilée**  
- Test encrypt / drops sous x64dbg via **Desktop partagé** alors qu’un chemin **local VM** suffit  

---

## Rappels sécurité

- Sample = **malware**. Pas d’exec sur l’hôte.  
- Any.RUN / sandbox tierce = OK si fournie.  
- Pubkey seule ≠ déchiffrement victimes.  
- Debug live x64dbg/x32dbg = OK seulement si **déjà** lancé par l’utilisateur sur la machine de debug.

---

## Exemple de prompt utilisateur

> Analyse le sample dans `./NomFamille/` (binaire + `.c` IDA). Any.RUN : \<url\>. Qualité Spora/DarkRace ; README FR + EN. Schémas Mermaid si utile ; §13 compact. Si x64dbg actif → corréler live ; fichiers test sur **disque local VM**.

L’agent enchaîne 0→6 (+ checklist §6.2) sans redemander la méthodo ; ne bloque que sur un choix réel (nom de dossier, tri screenshots, portée du walk live).
