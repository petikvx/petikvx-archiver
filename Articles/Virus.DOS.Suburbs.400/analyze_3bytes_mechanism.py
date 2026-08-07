#!/usr/bin/env python3
"""
Démonstration du mécanisme exact de stockage/restauration des 3 octets
originaux de l'hôte dans Virus.DOS.Suburbs.400

Le virus :
1. Lit les 3 premiers octets d'un fichier COM cible.
2. Les chiffre avec XOR 21h / 85h / 2Dh.
3. Écrit ces octets chiffrés À L'INTÉRIEUR de son propre corps viral
   (à l'offset relatif 0x17B) avant d'écrire le virus à la fin du fichier.
4. Quand le virus s'exécute dans la victime :
   - Il déchiffre ces 3 octets (mêmes clés).
   - Il les copie à l'adresse 100h.
   - Il rend la main au programme hôte original.
"""

# Exemple fictif : supposons qu'un fichier COM avait au début :
#   "MOV AX,1234"  ->  B8 34 12   (les 3 premiers octets réels d'un COM)
ORIGINAL_3_BYTES = bytes([0xB8, 0x34, 0x12])   # Exemple typique

KEY1 = 0x21
KEY2 = 0x85
KEY3 = 0x2D

def xor_encrypt_host_bytes(data: bytes) -> bytes:
    """Chiffrement appliqué pendant l'infection (dans le handler)."""
    assert len(data) == 3
    return bytes([
        data[0] ^ KEY1,
        data[1] ^ KEY2,
        data[2] ^ KEY3
    ])

def xor_decrypt_host_bytes(data: bytes) -> bytes:
    """Même opération (XOR est symétrique)."""
    return xor_encrypt_host_bytes(data)

def simulate_infection():
    print("=" * 70)
    print("SIMULATION DU MÉCANISME DE STOCKAGE DES 3 OCTETS (Suburbs.400)")
    print("=" * 70)
    print(f"3 octets originaux de l'hôte (exemple) : {ORIGINAL_3_BYTES.hex(' ')}")

    # 1. Pendant l'infection (handler INT 21h)
    encrypted = xor_encrypt_host_bytes(ORIGINAL_3_BYTES)
    print(f"Après XOR (stockés dans le virus)       : {encrypted.hex(' ')}")

    # Le virus construit son image de 400 octets avec ces octets à l'offset 0x17B
    # Simulons une image virale de 400 octets remplie de zéros
    virus_image = bytearray(0x190)   # 400 octets
    VIRUS_ORIGINAL_BYTES_OFFSET = 0x17B

    # Le virus place les octets chiffrés à cet offset dans son corps
    virus_image[VIRUS_ORIGINAL_BYTES_OFFSET : VIRUS_ORIGINAL_BYTES_OFFSET+3] = encrypted

    print(f"\nDans l'image virale (offset 0x17B)        : "
          f"{virus_image[VIRUS_ORIGINAL_BYTES_OFFSET:VIRUS_ORIGINAL_BYTES_OFFSET+3].hex(' ')}")

    # Le virus écrit cette image à la fin du fichier victime
    # Puis écrit E9 <taille-3> au début du fichier.

    # ------------------------------------------------------------------
    # 2. Quand la victime s'exécute (le virus est préfixé)
    # ------------------------------------------------------------------
    # Le virus s'est installé en mémoire.
    # Pendant l'installation / avant de rendre la main, il fait :

    # a) Localise les 3 octets chiffrés dans sa propre image
    #    (le calcul réel utilise ds:[0101h] + 027Eh)
    #    Pour la simulation on utilise directement l'offset connu.

    encrypted_in_virus = bytes(virus_image[VIRUS_ORIGINAL_BYTES_OFFSET:VIRUS_ORIGINAL_BYTES_OFFSET+3])
    print(f"\nAu runtime, le virus lit à ~0x17B        : {encrypted_in_virus.hex(' ')}")

    # b) Déchiffre avec les mêmes clés
    restored = xor_decrypt_host_bytes(encrypted_in_virus)
    print(f"Après déchiffrement (restauré)            : {restored.hex(' ')}")

    # c) Copie vers 100h
    print(f"\nCes octets sont copiés à l'adresse 100h")
    print(f"puis le virus fait : push 100h ; ret")

    assert restored == ORIGINAL_3_BYTES, "ERREUR : les octets ne correspondent pas !"
    print("\n✓ Succès : l'hôte original est parfaitement restauré.")

    print("=" * 70)
    print("RÉSUMÉ DU MÉCANISME")
    print("=" * 70)
    print("""
- Les 3 octets originaux NE sont PAS stockés dans un buffer séparé.
- Ils sont insérés DEDANS le corps du virus (à l'offset 0x17B relatif).
- Ils sont chiffrés par XOR avant écriture.
- Le même XOR sert aussi à déchiffrer des parties du handler lui-même.
- À l'exécution, le virus restaure ces 3 octets à 0100h avant de
  rendre la main (push 100h / ret).
- Cela permet au virus d'être "overlay" sur le début du COM sans
  perdre le code original.
""")

if __name__ == "__main__":
    simulate_infection()
