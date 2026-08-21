# AGENTS.md — analyse malware défensive (Articles / virusshare)

Instructions pour un agent qui reverse / documente des samples (VirusShare, dumps, ransomware, etc.).

**Références de qualité (à égaler, pas à copier aveuglément) :**

| Dossier | Ce qu’il illustre le mieux |
|---------|----------------------------|
| `DarkRace Ransomware/` | Config XOR, overlay Conti, bat reconstruit, § crypto **ligne à ligne** |
| `Trojan-Ransom.Win32.Spora.a/` | Hex-Rays croisé, blobs AES extraits, ID / `.KEY` / footer **expliqués pour non-experts** + code net |

Les deux ont `README.md` + `README_EN.md` bilingues.

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

Repérer : binaire, `*.c` Hex-Rays, URL Any.RUN, notes / configs déjà là.  
**Pas d’exécution** locale (`wine`, `./`, sandbox hôte non demandée).

### 1. Triage binaire (statique)

- PE/ELF : machine, sections, EP, TimeDateStamp, overlay
- Imports (parser Python OK)
- Strings ASCII + Unicode (mutex, note, onion, cmd, crypto API…)
- Packer / haute entropie — le noter

### 2. Croisement avec le décompil `.c`

Prioriser (adapter à la famille) :

| Zone | Chercher |
|------|----------|
| Entry | `main` / `WinMain` / `start` — branches (`/u`, admin…) |
| Init | mutex, decrypt blobs/config, état/reprise, VSS |
| Crypto | clés session, wrap RSA/ECC, ID victime, `.KEY`, footer fichier |
| Impact | walk, catégories/ext, rename ou non, note |
| Anti-recovery | `vssadmin`, `wmic`, `bcdedit`, services, logs |
| Cleanup | self-delete, shortcuts worm, reboot |

Expliquer le **pourquoi**. Pour les routines critiques : **code nettoyé** (noms lisibles) + prose « non expert » — voir barre qualité ci-dessous. Ne pas coller le Hex-Rays brut illisible.

### 3. Config / blobs embarqués

XOR / AES / overlay : localiser VA + clé, extraire, script de re-extraction, mapper **chaque** champ → comportement.  
Pubkeys → PEM/DER + fiche texte. Listes (ext, whitelist) **exhaustives**.

### 4. Any.RUN (si URL)

Verdict, process tree, drops, cmdline ; screenshots → `anyrun_screenshots/` ; corréler sandbox ↔ `sub_XXXX`.

### 5. Artefacts runtime

Note, bat/cmd, IoCs (hashes, mutex, ext, chemins, emails, onion…). Scripts Python de decode/extract quand ça aide la relecture (ex. ID victime Spora).

### 6. Livrables (dossier du sample)

| Fichier | Contenu |
|---------|---------|
| `README.md` | Rapport **français** (structure + barre qualité) |
| `README_EN.md` | **Même** fond en anglais + liens croisés FR/EN en tête |

Selon pertinence : config déchiffrée, `extract_*.py`, pubkey, note HTML/txt, `anyrun_screenshots/README_captures.md`, export `.c`.

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
3. Effets collatéraux (registre, shortcuts, icône…)  
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

---

## Rappels sécurité

- Sample = **malware**. Pas d’exec sur l’hôte.  
- Any.RUN / sandbox tierce = OK si fournie.  
- Pubkey seule ≠ déchiffrement victimes.

---

## Exemple de prompt utilisateur

> Analyse le sample dans `./NomFamille/` (binaire + `.c` IDA). Any.RUN : \<url\>. Qualité Spora/DarkRace ; README FR + EN.

L’agent enchaîne 0→6 sans redemander la méthodo ; ne bloque que sur un choix réel (nom de dossier, tri screenshots).
