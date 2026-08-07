rule Virus_BAT_Vir94_Stormbringer_1994
{
    meta:
        description = "BATVIR '94 - Stormbringer [P/S] hybrid BAT/COM virus (1994)"
        author = "Analyse statique"
        date = "2026-06-27"
        family = "Vir94"

    strings:
        $author     = "[BATVIR] '94 (c) Stormbringer [P/S]"
        $bat1       = "gqecho e0100" ascii
        $bat2       = "gqecho e02B8" ascii
        $debug      = "debug<batvir.94"
        $del        = "del batvir.94"
        $ctty       = "ctty con"
        $mask       = "*.bat" ascii

        // Partie COM - FindFirst + infection
        $findfirst  = { B4 4E BA ?? ?? CD 21 }
        $gettime    = { B8 00 57 CD 21 }
        $settime    = { B8 01 57 CD 21 }

    condition:
        (uint16(0) == 0x4EB4 or uint16(0) == 0xB44E) and   // start of COM code
        filesize < 600 and
        (
            $author or
            ($bat1 and $debug) or
            ($bat2 and $debug) or
            ($mask and $findfirst)
        )
}
