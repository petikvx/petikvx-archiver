/*
 * YARA rule for Virus.DOS.Suburbs.400
 * Auteur probable : VD/SLAM
 * Nom interne : Suburbs
 *
 * Caractéristiques :
 * - Virus DOS 16-bit résident (TSR)
 * - Infecte uniquement les fichiers COM
 * - Taille du corps viral : 0x190 (400) octets
 * - Signature visible "Suburbs" + "[VD/SLAM]"
 * - Utilise XOR 21h/85h/2Dh pour chiffrer les 3 octets originaux de l'hôte
 * - Hook INT 21h + INT 24h temporaire
 * - Installe dans le segment 0020h
 */

rule Virus_DOS_Suburbs_400
{
    meta:
        description = "Virus.DOS.Suburbs.400 - COM infector résident"
        author = "Analyse statique"
        date = "2026-06-27"
        hash = "f8a5df1cc021080ad734feb3f7543e0b9814740493e8189f2a2543df45efd331"
        family = "Suburbs"
        size_virus = 400

    strings:
        // Signature texte visible
        $name1 = "Suburbs" ascii
        $author = "[VD/SLAM]" ascii

        // Corps viral écrit en une seule fois (400 octets)
        $write_400 = { B4 40 33 D2 B9 90 01 }

        // Construction du JMP d'infection (E9 + delta)
        $build_jmp = { C6 06 91 01 E9 8B C5 2D 03 00 A3 92 01 }

        // Chiffrement XOR des 3 octets originaux de l'hôte
        $xor_host1 = { 80 36 7B 01 21 }
        $xor_host2 = { 80 36 7C 01 85 }
        $xor_host3 = { 80 36 7D 01 2D }

        // Même XOR utilisé pour déchiffrer son propre code + les octets host
        $xor_decrypt = { 80 34 21 80 74 01 85 80 74 02 2D }

        // Test EXE (MZ / ZM) - refuse d'infecter les EXE
        $mz_check1 = { 81 3E 7B 01 4D 5A }
        $mz_check2 = { 81 3E 7B 01 5A 4D }

        // Vérification déjà infecté (présence de E9)
        $e9_check = { 80 3E 92 01 E9 }

        // Installation résidente + hook INT 21h vers segment 20h:0006
        $tsr_install = { B8 20 00 8E C0 B9 90 01 90 F3 A4 }
        $hook_int21  = { 26 C7 05 06 00 B8 20 00 26 89 45 02 }

        // Hook temporaire INT 24h
        $hook_int24 = { B8 24 25 BA 03 00 CD 21 }

        // Sauvegarde et restauration date/heure (stealth)
        $save_time = { B8 00 57 CD 21 52 51 }
        $rest_time = { B8 01 57 59 5A CD 21 }

        // Buffer d'infection et écriture à la fin
        $append_virus = { B8 02 42 33 C9 33 D2 CD 21 8B E8 B4 40 }

    condition:
        uint16(0) == 0x5A4D and  // MZ (même si c'est un dropper)
        filesize < 2000 and
        (
            3 of ($xor_host*) or
            all of ($mz_check*) or
            $name1 or
            $write_400 or
            $build_jmp or
            $tsr_install
        ) and
        (
            $xor_decrypt or
            $hook_int21 or
            $append_virus
        )
}
