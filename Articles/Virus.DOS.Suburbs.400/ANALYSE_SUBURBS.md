# Analyse complète - Virus.DOS.Suburbs.400

## Fichiers générés

- `suburbs_annotated.asm` : désassemblage propre et fortement commenté
- `suburbs.yara` : règle YARA de détection
- `analyze_3bytes_mechanism.py` : démonstration du mécanisme des 3 octets

---

## 1. Vue d'ensemble

- **Famille** : Suburbs
- **Taille** : 400 octets de code viral (0x190)
- **Cible** : Fichiers .COM uniquement (ignore les EXE MZ/ZM)
- **Comportement** : Résident (TSR) + infector par préfixe + append
- **Signature auteur** : `[VD/SLAM]`
- **Nom interne** : `Suburbs`

Aucun payload destructif n'est présent. Le virus se contente de se propager.

---

## 2. Mécanisme exact de stockage des 3 octets (le plus important)

C'est la partie la plus intéressante du virus.

### Étapes pendant l'infection (dans le handler INT 21h)

1. Lit les 3 premiers octets de la victime dans un buffer (`ds:017Bh`).
2. Chiffre ces 3 octets avec :
   - `xor byte [017Bh], 21h`
   - `xor byte [017Ch], 85h`
   - `xor byte [017Dh], 2Dh`
3. Écrit **tout le corps viral de 400 octets** à la fin du fichier (y compris les 3 octets chiffrés qui se trouvent maintenant à l'intérieur du virus à l'offset relatif `0x17B`).
4. Écrit au début du fichier : `E9 <taille_originale - 3>`

### Étapes à l'exécution (dans la victime)

Quand le programme infecté est lancé :

- Le virus prend le contrôle.
- Il s'installe en mémoire (segment `0020h`).
- Dans la routine `install_tsr` (et avant de rendre la main) :
  - Il calcule l'adresse des 3 octets chiffrés stockés dans son corps :
    ```asm
    mov si, ds:[0101h]
    add si, 027Eh          ; pointe vers les octets originaux chiffrés
    ```
  - Il les déchiffre (mêmes clés XOR).
  - Il les copie vers `0100h` :
    ```asm
    mov di, 0100h
    mov cx, 3
    rep movsb
    ```
  - Il fait `push 100h ; ret` → le code hôte original reprend la main proprement.

### Pourquoi cette technique ?

- Le virus n'a pas besoin de stocker les octets originaux dans un fichier séparé ou à un autre endroit.
- Ils voyagent **à l'intérieur du virus lui-même**.
- Cela rend l'analyse un peu plus difficile car les octets varient d'une infection à l'autre (polymorphisme léger sur les 3 premiers octets).

---

## 3. Points clés du code

| Offset (corps) | Rôle |
|----------------|------|
| `000h`         | Entrée + jumps |
| `003h-010h`    | Zone chiffrée / padding |
| `011h`         | Handler INT 24h dummy (`mov al,3; iret`) |
| `017Bh`        | Buffer temporaire + emplacement des 3 octets originaux chiffrés |
| `0191h-0193h`  | Construction du `E9 xx xx` |
| `0FCh`         | `jmp far` vers INT 21h original (adresse patchée) |
| `101h`         | Routine d'installation TSR |
| `27Eh` (rel)   | Offset calculé pour retrouver les 3 octets à déchiffrer |

---

## 4. Techniques utilisées

- Résident en mémoire basse (segment 20h)
- Hook sélectif sur `INT 21h / 4Bh` seulement
- Suppression temporaire des erreurs via `INT 24h`
- Restauration parfaite des timestamps et attributs
- Auto-chiffrement léger (XOR sur données critiques)
- Auto-patch du jmp far pour chaîner vers le handler original
- Stockage des données hôtes à l'intérieur du virus

---

## 5. Détection

Utilise la règle YARA fournie (`suburbs.yara`).

Patterns forts :
- La chaîne "Suburbs"
- Les 3 XOR successifs sur les octets hôtes
- L'écriture de exactement 0x190 octets
- La construction E9 + delta
- Les hooks INT 21h / INT 24h + tests MZ/ZM

---

## 6. Fichiers dans ce dossier

```
suburbs/
├── Virus.DOS.Suburbs.400-...          # binaire original
├── Virus.DOS.Suburbs.400-....asm      # désassemblage IDA brut
├── suburbs_annotated.asm              # version propre + commentaires
├── suburbs.yara                       # règle de détection
├── analyze_3bytes_mechanism.py        # démonstration du mécanisme
└── ANALYSE_SUBURBS.md                 # ce fichier
```

---

*Analyse réalisée le 2026-06-27*
