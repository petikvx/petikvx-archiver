# Analyse : Virus.BAT.Vir94.com (BATVIR '94)

**Auteurs** : Stormbringer [P/S] - 1994  
**Type** : Virus hybride Batch + COM  
**Taille** : ~386 octets (code COM) + wrapper batch

## Les deux fichiers dans le dossier courant

1. `Virus.BAT.Vir94.com-0cbf5b184108695b22aa0ed5f41a463665eeafa353880ac487ca6b4310d23bf5` (458 octets)
2. `Virus.BAT.Vir94.com-cbe2e214736ffc82a5d1a37bf1808ae677d73167af6f6f93b890892264ff6160` (457 octets)

## Mécanisme d'infection

### Quand le fichier est exécuté comme .COM :

1. Cherche tous les fichiers `*.bat` (INT 21h AH=4Eh / 4Fh)
2. Ouvre le fichier en lecture/écriture
3. Lit la date/heure
4. Vérifie si déjà infecté (`dh >= 0x80` dans la date)
5. Si non infecté :
   - Se positionne à la fin du fichier
   - Encode son propre corps en format hexadécimal DEBUG ("XX " "e0100 ...")
   - Écrit un script DEBUG complet + commandes batch à la fin du .bat
   - Marque le fichier comme infecté (date modifiée +0xC8)
6. Passe au fichier suivant

### Quand le fichier .bat infecté est exécuté :

Le code batch ajouté fait :
```batch
gqecho e0100  >>batvir.94
debug<batvir.94
del batvir.94
ctty con
```

Cela recrée le virus COM via DEBUG, puis le lance.

## Structure du fichier

- Octets 0 → ~385 : Code COM du virus (exécutable directement)
- Octets ~386+   : Texte batch (`@echo off`, `ctty nul`, rem, etc.)

Le code COM contient en interne les chaînes du script DEBUG.

## Techniques notables

- **Auto-encodage** : Le virus se convertit lui-même en format DEBUG (routine `hex_encode` + `to_hex_char`)
- **Marqueur d'infection** : Utilise l'octet haut de la date du fichier
- **Hybride** : Peut tourner à la fois comme COM et produire un BAT infectieux
- **DEBUG dropper** : Technique très répandue en 1994 pour contourner les limitations des batch

## Fichiers générés

- `Vir94_BATVIR_Stormbringer.asm` : Version source TASM reconstruite
- Ce fichier d'analyse

## Pour recompiler

```bash
tasm Vir94_BATVIR_Stormbringer.asm
tlink /t Vir94_BATVIR_Stormbringer.obj
```

Le .COM obtenu devrait avoir le même comportement que les originaux.

## Remarque sur les deux variants

Les deux fichiers sont quasiment identiques. La seule différence notable est dans la chaîne DEBUG :
- Variante 1 : `gqecho e0100  >>batvir.94`
- Variante 2 : `gqecho e02B8  >>batvir.94`

Le code machine principal est le même.
