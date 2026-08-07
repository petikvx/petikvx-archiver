# Analyse Précise : Virus.BAT.Vir94.com (BATVIR '94)

> **Note** : Les fichiers `.asm` générés par IDA Pro sont disponibles dans ce dossier :
> - `Virus.BAT.Vir94.com-0cbf5b184108695b22aa0ed5f41a463665eeafa353880ac487ca6b4310d23bf5.asm`
> - `Virus.BAT.Vir94.com-cbe2e214736ffc82a5d1a37bf1808ae677d73167af6f6f93b890892264ff6160.asm`
>
> Ces désassemblages ont été utilisés pour affiner cette analyse.



**Nom** : BATVIR '94  
**Auteur** : Stormbringer [P/S]  
**Année** : 1994  
**Type** : Virus hybride Batch + COM (infector de fichiers .BAT)  
**Taille du code viral** : 386 octets (COM)  
**Fichiers analysés** (dossier courant) :
- `Virus.BAT.Vir94.com-0cbf5b184108695b22aa0ed5f41a463665eeafa353880ac487ca6b4310d23bf5` (458 octets)
- `Virus.BAT.Vir94.com-cbe2e214736ffc82a5d1a37bf1808ae677d73167af6f6f93b890892264ff6160` (457 octets)

---

## 1. Structure générale du fichier

Le fichier est **hybride** :

| Offset (approx) | Contenu                          | Rôle |
|-----------------|----------------------------------|------|
| 0x000 - 0x185   | Code machine COM (386 octets)   | Le vrai virus |
| ~0x186+         | Texte Batch (`@echo off ...`)   | Dropper via DEBUG |

Quand le fichier est renommé `.com` et exécuté → il agit comme un virus COM.  
Quand il est exécuté comme `.bat` (ou après infection) → la partie batch recrée le virus via `debug`.

---

## 2. Flux d'exécution (quand lancé en .COM)

```asm
start:
    mov  ah, 4Eh          ; FindFirst
    mov  dx, 0235h        ; "*.bat"
    int  21h
    jb   exit

main_loop:
    ... ouvrir le fichier
    ... récupérer date/heure
    cmp  dh, 80h
    jae  deja_infecte
    ... encoder et append le virus
    ... marquer comme infecté (dh += 0xC8)
    ... passer au suivant (FindNext)
```

### Étapes détaillées

1. **Recherche de cibles**
   - `INT 21h AH=4Eh` (FindFirst) avec masque `*.bat` (stocké à l'offset `0x235`).
   - Boucle avec `AH=4Fh` (FindNext).

2. **Ouverture et vérification**
   - Ouvre le fichier en lecture/écriture (`AH=3D02h`).
   - Récupère date/heure (`AH=5700h`).
   - **Test d'infection** : `cmp dh, 80h`
     - Si `dh >= 0x80` → fichier déjà infecté → on passe au suivant.

3. **Infection**
   - Se positionne à la fin du fichier (`AH=4202h`).
   - Copie son propre corps (depuis `0x100`, longueur `0x1CA`) dans un buffer à `0x2CA`.
   - **Encode le corps en hexadécimal** pour DEBUG (voir section 3).
   - Appelle `append_debug_payload` qui écrit :
     - Un en-tête DEBUG (40h octets à l'offset `0x280`).
     - Les lignes hex (`e0100 XX XX ...`).
     - Les commandes batch (`g`, `w`, etc.).
     - Le footer batch (`gqecho ... debug< ...`).

4. **Marquage et nettoyage**
   - Modifie la date : `add dh, 0xC8` (marqueur d'infection).
   - Restaure date/heure (`AH=5701h`).
   - Ferme le fichier.
   - Passe au fichier suivant.

5. **Fin**
   - Si plus de fichiers → `AH=4C00h` (exit).

---

## 3. Le mécanisme d'encodage (la partie la plus intéressante)

Le virus ne copie pas simplement son code. Il **se convertit lui-même** en format que `DEBUG` peut charger.

D'après le désassemblage IDA :

### Routine d'encodage : `sub_53` (offset 0x153)

```asm
sub_53          proc near
                push    cx
                lodsb
                mov     bx, ax
                mov     cx, 4
                shr     al, cl
                push    ax
                call    sub_76
                stosb
                pop     ax
                shl     al, cl
                sub     bl, al
                xchg    al, bl
                call    sub_76
                stosb
                mov     ax, 20h ; ' '
                stosb
                pop     cx
                loop    sub_53
                stosb
                stosb
                retn
sub_53          endp
```

### Convertisseur de nibble : `sub_76`

```asm
sub_76          proc near
                cmp     al, 0Ah
                jnb     short loc_7D
                add     al, 30h ; '0'
                retn
loc_7D:
                add     al, 37h ; '7'
                retn
sub_76          endp
```

Résultat produit par le virus : lignes du style `e0100 B4 4E BA 35 02 CD 21 ...`

### Écriture du payload : `sub_80` (offset ~0x180)

Cette routine gère l'écriture du script DEBUG complet dans le fichier cible :
- Écrit un en-tête (40h octets)
- Écrit les données hex par blocs (max 3Ch octets)
- Appelle `sub_FA` pour calculer l'adresse pour la commande `eXXXX`
- Écrit les commandes `g` et `w`
- Ajoute le footer batch

### Calcul d'adresse pour DEBUG : `sub_FA`

Cette routine calcule l'offset pour la commande `e` de DEBUG :
```asm
sub_FA          proc near
                ...
                sub     dx, 2CAh
                mov     ax, dx
                mov     cx, 3
                xor     dx, dx
                div     cx
                mov     dx, ax
                add     dx, 100h     ; base + offset
                ...
                call    sub_53       ; encode l'adresse en hex
```

---

### Données embarquées (section data à la fin du COM, d'après IDA)

```
aBat            db '.bat',0
aGqechoE0100Bat db 'gqecho e0100  >>batvir.94',0Dh,0Ah
                db 'debug<batvir.94',0Dh,0Ah
                db 'del batvir.94',0Dh,0Ah
                db 'ctty con',0Dh,0Ah
                db 0Dh,0Ah
                db '@echo off',0Dh,0Ah
                db 'ctty nul',0Dh,0Ah
                db 'rem [BATVIR] ',27h,'94 (c) Stormbringer [P/S]',0Dh,0Ah,0
```

**Important** : Ces chaînes font partie intégrante du code COM (elles sont copiées avec le virus). C'est pourquoi le virus peut s'auto-reproduire à la fois en COM et en BAT.

---

## 4. Écriture du payload (détail de sub_80)

Le code écrit par blocs :
- Écrit l'en-tête DEBUG
- Écrit les lignes hex (max 0x3C octets par ligne)
- Écrit `g` (go) et `w` (write)
- Ajoute le footer batch

---

## 4. Ce qui est écrit dans le fichier .bat cible

À la fin d'un fichier .bat sain, le virus ajoute quelque chose comme :

```
[données binaires du virus encodées]
gqecho e0100  >>batvir.94
debug<batvir.94
del batvir.94
ctty con
```

Quand ce .bat est exécuté :
1. `gqecho` recrée le fichier `batvir.94` avec les commandes DEBUG.
2. `debug < batvir.94` exécute le script et recrée le virus COM.
3. Le virus COM est lancé (ou copié).

---

## 5. Différences entre les deux variants

| Élément              | Variante 1                          | Variante 2                          |
|----------------------|-------------------------------------|-------------------------------------|
| Taille totale        | 458 octets                          | 457 octets                          |
| Commande DEBUG       | `gqecho e0100  >>batvir.94`        | `gqecho e02B8  >>batvir.94`        |
| Quelques octets finaux | Légèrement différents             | Légèrement différents             |
| Code COM principal   | Identique (386 octets)              | Identique                           |

Le cœur du virus (recherche + encodage + append) est **exactement le même**.

---

## 6. Analyse du code COM (points clés)

| Adresse | Instruction / Routine          | Rôle |
|---------|--------------------------------|------|
| 0x100   | `mov ah,4Eh` + `int 21h`      | FindFirst *.bat |
| 0x109   | `mov dx,9Eh`                  | Utilise la DTA pour le nom de fichier |
| 0x113   | `mov ax,5700h`                | Lire date/heure |
| 0x11B   | `cmp dh,80h`                  | Test d'infection |
| 0x120   | `mov ax,4202h`                | Seek to end |
| 0x129-0x175 | Routine d'encodage hex     | Convertit le virus en format DEBUG |
| 0x180   | `write_debug_script`          | Écrit le payload dans le .bat |
| 0x1FA   | Calcul d'adresse pour "eXXXX" | Calcule l'offset pour la commande `e` de DEBUG |
| 0x235   | `*.bat` + `gqecho ...`        | Données (chaînes) |

---

## 7. Technique historique

Ce virus utilise une technique très populaire en 1993-1995 :
- Les fichiers batch sont faciles à éditer.
- `DEBUG` permet de créer des fichiers binaires depuis du texte.
- Le virus s'auto-encode pour pouvoir s'insérer dans des fichiers texte.

C'est un des exemples classiques de **virus de fichiers batch** (batch file infectors).

---

## 8. Indicateurs de détection

- Chaîne visible : `[BATVIR] '94 (c) Stormbringer [P/S]`
- Commandes : `gqecho e01`, `batvir.94`, `debug<batvir.94`
- Comportement : recherche `*.bat`, modification de date avec +0xC8
- Début du code : `B4 4E BA 35 02 CD 21`

## 9. Apport des désassemblages IDA

Les deux fichiers `.asm` générés par IDA dans ce dossier ont permis :

- Confirmation des noms de sous-routines (`sub_53`, `sub_76`, `sub_80`, `sub_FA`)
- Visualisation exacte de la section data embarquée (y compris le texte batch complet qui voyage avec le virus)
- Confirmation des offsets durs (0x235 pour `*.bat`, 0x2CA pour le buffer hex, etc.)
- Meilleure compréhension du layout mémoire (le virus est chargé comme binaire pur de 0000h à ~01CAh)
- Identification précise des différences entre les deux variants (uniquement dans les chaînes DEBUG à la fin)

Ces infos ont été intégrées dans cette analyse et dans la reconstruction `Vir94_BATVIR_Stormbringer.asm`.

---

## Fichiers associés dans ce dossier (Vir94/)

- `Virus.BAT.Vir94.com-....asm` (x2) → Désassemblages IDA originaux
- `Vir94_BATVIR_Stormbringer.asm` → Version source TASM reconstruite (labels alignés sur IDA)
- `Vir94.yara` → Règle de détection
- `Vir94_analyse_precise.md` → Cette analyse
- Binaires originaux

---

*Analyse mise à jour avec les désassemblages IDA générés dans ce dossier (27/06/2026).*
