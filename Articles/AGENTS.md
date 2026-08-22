# AGENTS.md — analyse malware défensive (Articles / virusshare)

Instructions pour un agent qui reverse / documente des samples (VirusShare, dumps, ransomware, etc.).

**Références de qualité (à égaler, pas à copier aveuglément) :**

| Dossier | Ce qu’il illustre le mieux |
|---------|----------------------------|
| `DarkRace Ransomware/` | Config XOR, overlay Conti, bat reconstruit, § crypto **ligne à ligne** |
| `Trojan-Ransom.Win32.Spora.a/` | Hex-Rays croisé, blobs AES extraits, ID / `.KEY` / footer **expliqués pour non-experts** + code net |
| `Trojan.Win32.Diztakun.arpg/` | Scareware .NET/WPF : décompil C#, bat reconstruit, chaîne multi-étages **lisible non-expert** |
| `Trojan.Win32.Cosmu.bwts/` | Packer ASPack + Hex-Rays, faux ransomware XOR, script IR de recovery |

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

- Racines typiques : `/home/petik/Downloads/petikvx-archiver/Articles/` (rapports archivés) et `/home/petik/Downloads/virusshare/` (samples bruts).
- Chaque famille / sample a **son propre sous-dossier**. Travailler **dedans** (ne pas mélanger avec DarkRace / Spora / un autre sample).
- S’il n’y a qu’un PE à la racine : créer un sous-dossier (famille ou SHA256 court), y placer le sample, y écrire les livrables.
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
SAMPLE="/chemin/vers/sample-unpacked.exe"   # ou le .i64 existant
OUT="$(dirname "$SAMPLE")/artefacts/ida_export"
mkdir -p "$OUT"

"$IDA/idat" -A \
  "-S$IDA/scripts/export_asm_c.py --outdir $OUT --prefix $(basename "$SAMPLE")" \
  "$SAMPLE"
```

Sorties attendues dans `artefacts/ida_export/` :

| Fichier | Contenu |
|---------|---------|
| `*.c` | Hex-Rays **toutes** les fonctions |
| `*.asm` | Listing assembleur |
| `*.lst` | Listing désassemblage |

- Réutiliser un `.i64` déjà ouvert si présent (plus rapide).  
- PE32 : `idat` + decompiler x86 (`hexx64` côté IDA 9 gère aussi le 32-bit).  
- Lier ces fichiers dans les README (sources + tableau livrables).  
- Ensuite seulement : croiser le `.c` avec le triage (ci-dessous).

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

```bash
SAMPLE="/chemin/vers/malware.exe"
WORKDIR="$(dirname "$SAMPLE")"
cd "$WORKDIR"

# 1) Extraire l’archive PyInstaller (ne pas « lancer » le malware : lecture du PE seulement)
python3 ~/petikvx-ressources/work/pyinstxtractor.py "$(basename "$SAMPLE")"
# → dossier : <sample.exe>_extracted/

EXT="${SAMPLE}.exe_extracted"
# si le nom du fichier n’a pas .exe : le dossier est "<basename>_extracted"
EXT="$(ls -d "$WORKDIR"/*_extracted 2>/dev/null | head -1)"

# 2) Repérer le point d’entrée (souvent sans extension, ou *.pyc)
#    pyiboot*.pyc / pyi_rth_*.pyc = runtime ; le vrai code = modules + éventuel main sans suffixe
mkdir -p "$WORKDIR/source_py"
ls -la "$EXT"

# 3) Décompiler les .pyc intéressants (entrypoint + modules métier)
PYCDC=~/sandbox/python/pycdc.x86_64
chmod +x "$PYCDC" 2>/dev/null
for f in "$EXT"/*.pyc "$EXT"/PYZ.pyz_extracted/*.pyc ; do
  [ -f "$f" ] || continue
  base=$(basename "$f" .pyc)
  "$PYCDC" "$f" > "$WORKDIR/source_py/${base}.py" 2>/dev/null || true
done

# Parfois le entrypoint n’a pas d’extension : essayer quand même
for f in "$EXT"/* ; do
  [ -f "$f" ] || continue
  case "$f" in *.pyc|*.pyz|*.dll|*.so|*.zip) continue ;; esac
  base=$(basename "$f")
  "$PYCDC" "$f" > "$WORKDIR/source_py/${base}.py" 2>/dev/null || true
done
```

Notes :

- Idéalement **même version majeure de Python** que celle du freeze (sinon unmarshal PYZ peut râler) ; tenter quand même.  
- Si `pycdc` échoue (Python très récent) : noter la limite ; fallback possible `decompyle3` / `uncompyle6` si installés, ou analyse du `.pyc` au bytecode (`pycdas`).  
- Sorties à versionner / lier : `*_extracted/` (brut) + `source_py/*.py` (lisible) dans les README.  
- Chercher ensuite dans le Python : C2, crypto, stealer, droppers, configs (souvent clair ou base64 trivial).

### 2c. Croisement avec le décompil (`.c` / `.cs` / `.py`)

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

---

## Structure de rapport (adapter les titres à la famille)

Numérotation claire ; **ne pas survoler**. Ordre type :

0. Synthèse sandbox ↔ code  
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
13. Fichiers produits  
14. Références + ce qui n’a **pas** été vérifié  

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

---

## Rappels sécurité

- Sample = **malware**. Pas d’exec sur l’hôte.  
- Any.RUN / sandbox tierce = OK si fournie.  
- Pubkey seule ≠ déchiffrement victimes.

---

## Exemple de prompt utilisateur

> Analyse le sample dans `./NomFamille/` (binaire + `.c` IDA). Any.RUN : \<url\>. Qualité Spora/DarkRace ; README FR + EN.

L’agent enchaîne 0→6 sans redemander la méthodo ; ne bloque que sur un choix réel (nom de dossier, tri screenshots).
