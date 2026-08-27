# Procédure sandbox — obtenir 1 fichier `.makop` + footer

Objectif IR : un **petit** fichier chiffré par **ce** sample, pour valider le layout footer (meta / IV / RSA wrap / progress).  
Ne pas le faire hors sandbox. Ne pas viser des données réelles.

## Prérequis

- Sandware isolée (snapshot VM recommandé)
- Sample Makop déjà analysé
- Dossier de travail dédié, ex. `C:\Users\Public\makop_lab\` (évite le Desktop perso si tu peux)

## Méthode A — run simple (recommandée)

1. **Snapshot** la VM.
2. Crée un dossier lab et un fichier **petit** (&lt; 1,5 MiB → mode **full**) :

```bat
mkdir C:\Users\Public\makop_lab
echo MAKOP_FOOTER_TEST_12345> C:\Users\Public\makop_lab\test_makop.txt
```

   Optionnel : un 2ᵉ fichier **> 1,5 MiB** pour le mode partiel (plus tard).

3. Copie le sample **dans** `makop_lab` (ou lance-le avec ce dossier comme cwd — Makop commence souvent par le dossier du binaire).
4. Lance le sample **une fois**, laisse tourner ~30–60 s (assez pour 1 dossier).
5. Vérifie :

```bat
dir C:\Users\Public\makop_lab
```

   Attendu :
   - `test_makop.txt.[XXXXXXXX].[netback@inboxhub.net].makop`
   - `readme-warning.txt`

6. **Copie** le `.makop` hors de la zone chaude (vers l’hôte d’analyse / partage lecture seule), puis **restaure le snapshot**.

7. Parse :

```bash
python3 artefacts/parse_makop_footer.py /chemin/test_makop.txt.*.makop \
  --dump-dir artefacts/footer_sample1
```

## Méthode B — x32dbg contrôlé

Utile si tu veux **un seul** fichier et stopper juste après `MoveFileW`.

1. Snapshot + même `test_makop.txt` dans le dossier du sample.
2. Ouvre le sample dans **x32dbg**.
3. Breakpoints :
   - `kernel32.MoveFileW` (rename après succès crypto)
   - optionnel : `0x403600` (full) / `0x403C00` (partiel)
4. Run jusqu’à `MoveFileW` : lire `lpExistingFileName` / `lpNewFileName` sur la pile.
5. Step over / laisse le rename finir, **Pause**, copie le `.makop`, **ne continue pas** le walk global (ou kill le process).
6. Parse comme en A.

Si le debugger est **LOCKED** / planté dans `ntdll` : **File → Restart** (ou recharger le binaire) plutôt que forcer un état pourri.

## Quoi me renvoyer / déposer dans `artefacts/`

| Élément | Pourquoi |
|---------|----------|
| Le fichier `.makop` (ou au moins les **512 derniers octets**) | Valider footer |
| Sortie de `parse_makop_footer.py` / dossier `footer_sample1/` | IV, wrap, meta_size |
| Nom complet (avec `[ID].[email].makop`) | Corréler ID victime |

Pas besoin de clé privée, ni de decryptor.

## Critères de succès

- `meta_size` multiple de 16, cohérent avec la taille du fichier  
- IV = 16 o, RSA wrap = 128 o exactement  
- `progress` ≈ taille utile du contenu (mode full)  
- Pour un tout petit `.txt`, le **début** du fichier ne doit plus être du texte clair (mode full)
