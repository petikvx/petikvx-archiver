# AGENTS.md — virusshare (analyse malware défensive)

Instructions pour un agent qui reverse / documente des samples dans ce dossier (VirusShare, dumps, ransomware, etc.).

Référence de qualité : dossier `DarkRace Ransomware/` (`README.md` + `README_EN.md`).

---

## Mission

Analyse **défensive / IR / recherche** uniquement :

1. Identifier le sample (hashes, type PE/ELF, sections, imports)
2. Croiser **binaire** + **décompil Hex-Rays / IDA** (fichier `.c` si présent)
3. Optionnel : enrichir avec rapport **Any.RUN** (URL fournie) + screenshots
4. Produire un rapport bilingue + artefacts extraits (config, clés pub, scripts reconstruit…)
5. **Stop** : livrer en local. **Ne pas** exécuter le malware hors sandbox tierce. **Ne pas** `git commit` / `git push` sauf demande explicite.

**Interdit :** améliorer le malware, aider au déploiement, écrire un encryptor/decryptor offensif, fournir une clé privée absente du sample, exécuter le binaire sur la machine hôte.

---

## Contexte workspace

- Racine typique : `/home/petik/Downloads/virusshare/` (ou CWD du sample).
- Chaque famille / sample a souvent **son propre sous-dossier**.
- Si l’utilisateur pointe un dossier : travailler **dedans** (ne pas mélanger avec DarkRace ou un autre sample).
- S’il n’y a que un PE à la racine : créer un sous-dossier nommé d’après la famille ou le SHA256 court, y déplacer/copier le sample, et y écrire les livrables.

---

## Workflow type (playbook « DarkRace »)

### 0. Inventaire

```bash
ls -la
file <sample>
sha256sum <sample>   # aussi md5 / sha1
```

Repérer :

- binaire (PE/ELF, souvent sans extension)
- décompil IDA/Hex-Rays `*.c` (ou exports IDA)
- URL Any.RUN si fournie dans le prompt
- notes / configs déjà extraites

**Pas d’exécution** du sample (`wine`, `./`, double-clic, sandbox locale non demandée).

### 1. Triage binaire (statique)

- PE : machine, sections, EP, TimeDateStamp, overlay (taille fichier − fin dernière section)
- Table d’imports (parser minimal Python OK si pas de `rabin2`)
- Strings ASCII + Unicode : mutex, ransom note, onion, cmd, chemins `ProgramData`, crypto (`CryptGenRandom`, `expand 32-byte`, `rsa_encrypt`…)
- Packer / sections suspectes (high entropy) — le noter

### 2. Croisement avec le décompil `.c`

Prioriser dans l’ordre Conti-like / ransomware générique :

| Zone | Chercher |
|------|----------|
| Entry | `main` / `WinMain` — hide console, enchaînement init |
| Init | mutex single-instance, decrypt config, admin check, VSS cmds |
| Crypto | gen clé session, RSA/ECC wrap, extension fichier, footer |
| Impact | walk threads, encrypt, rename, note `Readme.*` |
| Anti-recovery | `vssadmin`, `wmic shadowcopy`, stop services, clear event logs |
| Cleanup | self-delete, `shutdown`, reboot |

Expliquer le **pourquoi** (pas seulement le quoi). Pour les routines critiques : blocs de code **commentés ligne à ligne** (mode §8 DarkRace).

### 3. Config / blobs embarqués

Si config XOR / XML / JSON chiffrée :

1. Localiser VA / offset + clé (souvent XOR trivial type `0xA9`)
2. Extraire → fichier versionné dans le dossier sample
3. Fournir script de re-extraction (`extract_config.py` ou équivalent)
4. Mapper **chaque champ** → comportement (threads, whitelists, cmd, note, ico…)

Si overlay PE type Conti (`n` hex + `e` + extension) :

- Dumper overlay
- Exporter pubkey PEM/DER + fiche `rsa_public_key.txt`
- Lier extension observée (Any.RUN / rename)

### 4. Any.RUN (si URL)

- Récupérer verdict, tags YARA, process tree, drops, cmdline (`taskkill`, `ping`, `shutdown`…)
- Télécharger screenshots utiles → dossier `anyrun_screenshots/`
- Laisser l’utilisateur trier ; mettre à jour le rapport avec **uniquement** les captures conservées
- Corréler chaque observation sandbox ↔ fonction du `.c`

### 5. Reconstruction d’artefacts runtime

Quand le code les génère :

- Scripts (`1.bat`, cmd VSS…) → fichier complet en clair
- Note de rançon → extraire texte config / strings
- Whitelists → listes **exhaustives** (pas « … »)
- IoCs : hashes, mutex, ext, chemins, emails, onion, Tox, YARA tags

### 6. Livrables (dans le dossier du sample)

Minimum :

| Fichier | Contenu |
|---------|---------|
| `README.md` | Rapport **français** complet (structure ci-dessous) |
| `README_EN.md` | Même rapport en **anglais** + liens croisés FR/EN en tête |

Selon pertinence (comme DarkRace) :

- config déchiffrée (+ version readable si gros base64)
- script d’extraction
- overlay / `rsa_public_key.pem` (+ `.txt`, `.der`)
- script reconstruit (`1.bat`…)
- `anyrun_screenshots/` + petit README des captures gardées

En tête des README :

```markdown
Langue : Français | English version: [README_EN.md](README_EN.md)
```

```markdown
Language: English | French version: [README.md](README.md)
```

---

## Structure de rapport attendue

Numérotation claire ; approfondir section par section (ne pas survoler). S’inspirer de DarkRace :

0. Synthèse sandbox ↔ code (si Any.RUN)
1. Point d’entrée
2. Init (mutex, config, cmds pré-encrypt, crypto setup, overlay/pubkey…) — sous-sections `2.1`, `2.2`…
3. Effets collatéraux init (icône / registre / recycle…)
4. Kill process / bat
5. Stop services
6. Orchestration multi-thread / walk
7. Whitelists / exclusions (listes complètes)
8. Chiffrement fichier (chunks, primitive, rename, note) — **code abondamment commenté**
9. Cleanup / reboot / anti-forensics
10. Timeline
11. IoCs
12. Captures (après tri user)
13. ATT&CK
14. Fichiers produits

Adapter les titres à la famille (pas forcément Conti) : garder le **niveau de détail**.

Quand l’utilisateur dit « détail le §X » : enrichir **ce** § dans les deux README (FR + EN) sans alléger le reste.

---

## Style rédactionnel

- Français d’abord pour `README.md` ; anglais pour `README_EN.md`
- Tableaux pour IoCs, mapping config→comportement, imports notables
- Citations de fonctions `sub_XXXX` + snippets commentés
- Affirmatif et précis ; dire clairement ce qui n’a **pas** été vérifié (ex. pas d’exec locale)
- Pas de jargon inventé ; vocabulaire établi ( Conti, VSS, overlay, footer RSA… )

---

## Rappels sécurité

- Sample = **malware**. Ne pas le lancer sur l’hôte.
- Any.RUN / sandbox tierce = OK si l’utilisateur fournit le rapport.
- Pas d’aide à l’attaque réelle ; decryptor seulement si recherche défensive évidente et matériel public (pubkey seule ≠ déchiffrement victimes).

---

## Exemple de prompt utilisateur attendu

> Analyse le sample dans `./NomFamille/` (binaire + `.c` IDA). Any.RUN : \<url\>. Même méthodo que DarkRace ; README FR + EN.

L’agent enchaîne alors les étapes 0→6 sans redemander la méthodo, et pose des questions seulement si un choix bloque (ex. tri screenshots, nom de dossier).
