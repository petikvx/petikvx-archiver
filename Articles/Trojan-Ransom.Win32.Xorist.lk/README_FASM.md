# Trojan-Ransom.Win32.Xorist.lk - Version FASM

## ⚠️ AVERTISSEMENT IMPORTANT

Ce code est fourni **UNIQUEMENT À DES FINS ÉDUCATIVES** pour l'étude de la sécurité informatique et des malwares. L'utilisation de ce code à des fins malveillantes est **ILLÉGALE** et peut entraîner des poursuites pénales.

**NE PAS COMPILER OU EXÉCUTER CE CODE SUR DES SYSTÈMES DE PRODUCTION**

## Description

Ce document présente une réécriture du ransomware Xorist.lk pour l'assembleur FASM (Flat Assembler), avec une structure plus claire et des commentaires en français pour faciliter la compréhension.

### Hash du fichier original
- **SHA256**: `AFBD82DE1C80C8508B0CB6376E248393CC04B5276680C604D7DF1E56FB93CD26`
- **MD5**: `3359DFF8C8B3855E8CF980539E7FB300`

## Améliorations par rapport au code IDA

### 1. **Structure claire pour FASM**
- En-têtes et directives FASM appropriées
- Sections bien définies (`.data`, `.text`, `.idata`, `.rsrc`)
- Format PE GUI correct

### 2. **Nomenclature compréhensible**
- Remplacement des noms générés par IDA (`sub_401000`, `loc_401034`, etc.)
- Noms de fonctions descriptifs en français/anglais
- Variables avec des noms explicites

### 3. **Commentaires détaillés**
- Explication de chaque fonction majeure
- Documentation des algorithmes utilisés
- Notes sur le comportement du malware

### 4. **Organisation logique**
```
├── Section des données
│   ├── Configuration
│   ├── Messages et textes
│   ├── Buffers et variables
│   └── Structures
├── Section du code
│   ├── Point d'entrée (start)
│   ├── Initialisation
│   ├── Génération de clés
│   ├── Création de notes de rançon
│   ├── Modification du fond d'écran
│   ├── Énumération des fichiers
│   └── Chiffrement/Déchiffrement
└── Section des imports
    └── DLLs Windows (kernel32, user32, etc.)
```

## Fonctionnalités principales

### 1. **Initialisation**
```asm
initialize_program:
    - Générer clé de chiffrement avec RDTSC
    - Configurer le mode d'erreur
    - Obtenir le handle du tas
```

### 2. **Génération de clé aléatoire**
```asm
generate_encryption_key:
    - Utilise l'instruction RDTSC (Time Stamp Counter)
    - Génère 16 octets aléatoires
    - Stocke dans encryption_key
```

### 3. **Création de la note de rançon**
```asm
create_ransom_note_in_startup:
    - Récupère le dossier de démarrage (CSIDL_STARTUP)
    - Crée "HOW TO DECRYPT FILES.txt"
    - Écrit le message de rançon
```

### 4. **Changement du fond d'écran**
```asm
change_desktop_wallpaper:
    - Extrait une image depuis les ressources
    - Génère un nom de fichier temporaire aléatoire
    - Définit comme fond d'écran avec SystemParametersInfoA
```

### 5. **Énumération des fichiers**
```asm
start_file_encryption:
    - Parcourt tous les lecteurs logiques (A: à Z:)
    - Recherche récursivement dans les dossiers
    - Applique le chiffrement aux fichiers ciblés
```

### 6. **Algorithme de chiffrement**
```asm
simple_xor_cipher:
    - Chiffrement XOR simple
    - Utilise une clé dérivée du nom de fichier
    - Rotation de la clé pour chaque octet
```

## Compilation avec FASM

```bash
# Installation de FASM (Linux)
wget https://flatassembler.net/fasm-1.73.30.tgz
tar -xzf fasm-1.73.30.tgz
cd fasm

# Compilation
./fasm Xorist_FASM.asm Xorist.exe
```

### Prérequis
- FASM 1.73 ou supérieur
- Fichier `win32ax.inc` (inclus avec FASM)
- Environnement Windows ou Wine pour l'exécution

## Analyse technique

### APIs Windows utilisées

#### Kernel32.dll
- `CreateFileA` - Ouvrir/créer des fichiers
- `ReadFile/WriteFile` - Lecture/écriture
- `GetLogicalDrives` - Énumérer les lecteurs
- `FindFirstFileA/FindNextFileA` - Recherche de fichiers
- `MoveFileA` - Renommer les fichiers chiffrés

#### User32.dll
- `MessageBoxA` - Afficher les messages
- `SystemParametersInfoA` - Changer le fond d'écran
- `PeekMessageA` - Traiter les messages Windows

#### Shell32.dll
- `SHGetSpecialFolderPathA` - Obtenir les dossiers spéciaux

#### Shlwapi.dll
- `PathAddBackslashA` - Manipuler les chemins
- `PathFindExtensionA` - Trouver les extensions
- `PathMatchSpecA` - Comparer avec des motifs

### Techniques de chiffrement

Le ransomware utilise un chiffrement XOR simple avec les caractéristiques suivantes :

1. **Génération de clé**: RDTSC (compteur CPU)
2. **Dérivation**: XOR avec le nom de fichier + rotation
3. **Application**: XOR octet par octet avec rotation de clé

```
Clé initiale: [K0, K1, K2, ..., K15]
Seed: Premier caractère du nom de fichier
Clé dérivée: K'i = Ki XOR (seed ROL i)
Chiffrement: Ci = Pi XOR K'(i mod 16)
```

### Comportement

1. **Au premier lancement**:
   - Génère une clé de chiffrement aléatoire
   - Crée la note de rançon dans le dossier de démarrage
   - Change le fond d'écran
   - Chiffre tous les fichiers avec l'extension cible
   - Affiche un message d'avertissement

2. **Fichiers ciblés**:
   - Tous les fichiers selon la configuration
   - Ignore les fichiers système
   - Ignore sa propre note de rançon
   - Ajoute l'extension `.locked` (configurable)

3. **Après chiffrement**:
   - Préserve les horodatages originaux
   - Renomme les fichiers
   - Affiche les instructions de rançon

## Configuration

Variables modifiables dans la section `.data`:

```asm
config_show_messagebox          db 1    ; Afficher les messages (0/1)
config_create_ransom_note       db 1    ; Créer la note (0/1)
config_use_encryption           db 0    ; Utiliser le chiffrement (0/1)
config_use_custom_extension     db 1    ; Extension personnalisée (0/1)
config_encrypt_mode             db 2    ; Mode: 0=chiffrer, 1=déchiffrer, 2=auto

file_extension                  db ".locked", 0  ; Extension ajoutée
ransom_note_filename           db "HOW TO DECRYPT FILES.txt", 0
```

## Différences avec le code IDA original

| Aspect | Code IDA | Code FASM réécrit |
|--------|----------|-------------------|
| **Lisibilité** | Noms génériques (`sub_401000`) | Noms descriptifs (`initialize_program`) |
| **Structure** | Linéaire, segments bruts | Sections organisées logiquement |
| **Commentaires** | Minimaux | Détaillés en français |
| **Imports** | Références numériques | Imports explicites avec noms |
| **Variables** | Adresses mémoire (`byte_40752B`) | Noms explicites (`config_show_messagebox`) |
| **Syntaxe** | Syntaxe IDA | Syntaxe FASM standard |

## Exemple de fonction: Avant/Après

### Avant (IDA)
```asm
sub_401000 proc near
push    1
push    10h
push    offset pszPath
push    0
call    SHGetSpecialFolderPathA
push    offset pszPath
call    sub_40103A
mov     al, byte_40752B
cmp     al, 1
jnz     short loc_401034
```

### Après (FASM)
```asm
; Créer la note de rançon dans le dossier de démarrage
create_ransom_note_in_startup:
    push    ebp
    mov     ebp, esp
    
    ; Obtenir le dossier de démarrage (Startup)
    invoke  SHGetSpecialFolderPathA, 0, special_folder_path, CSIDL_STARTUP, TRUE
    
    ; Créer le chemin complet vers la note
    invoke  lstrcpyA, full_path, special_folder_path
    invoke  PathAddBackslashA, full_path
    
    ; Vérifier la configuration
    cmp     [config_use_custom_extension], 1
    je      .use_custom_name
```

## Protection et détection

### Signatures
Ce malware est détecté par la plupart des antivirus sous le nom:
- Trojan-Ransom.Win32.Xorist.lk
- Ransom:Win32/Xorist
- W32/Xorist

### Comportements suspects
- Modification du fond d'écran
- Énumération massive de fichiers
- Création de notes de rançon
- Utilisation de RDTSC pour la génération aléatoire
- Renommage massif de fichiers

### Indicateurs de compromission (IOC)
- Fichier: `HOW TO DECRYPT FILES.txt` dans le dossier de démarrage
- Extension: `.locked` ajoutée aux fichiers
- Fond d'écran modifié avec une image de rançon
- Clé de registre potentielle (selon la variante)

## Références

- **Kaspersky**: [Trojan-Ransom.Win32.Xorist](https://threats.kaspersky.com/en/threat/Trojan-Ransom.Win32.Xorist/)
- **FASM**: [Flat Assembler](https://flatassembler.net/)
- **Win32 API**: [Microsoft Documentation](https://docs.microsoft.com/en-us/windows/win32/api/)

## Auteur et licence

- **Analyse originale**: IDA Pro 9.0
- **Réécriture**: Version éducative pour FASM
- **Date**: Janvier 2012 (timestamp original) / Décembre 2025 (réécriture)
- **Licence**: Uniquement à des fins éducatives et de recherche en sécurité

## Avertissement final

⚠️ **Ce code est un MALWARE réel et dangereux**

- Ne compilez pas ce code sans mesures de sécurité appropriées
- Utilisez uniquement dans un environnement isolé (VM, sandbox)
- Ne distribuez pas les binaires compilés
- Respectez les lois locales sur la cybersécurité
- L'auteur décline toute responsabilité pour une utilisation abusive

**Pour l'étude académique uniquement** - Comprendre comment fonctionnent les ransomwares aide à mieux s'en protéger.
