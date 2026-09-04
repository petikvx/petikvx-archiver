umbra_wallpaper_only.bin — copie innofensive (wallpaper only)

SHA256  03ce22ab21d3668ccdd6d2f36b50cb03c394311262f7b7b526f49974f96fbcb5
MD5     e8eb7022242d9a1ffd0d7b521d516fe7

Any.RUN (wallpaper-only):
  https://app.any.run/tasks/c1d1d846-9b2b-4980-aa7c-154e367393c0/
  Verdict: No threats detected

Le sample original n’est PAS modifié. Premier octet C3 (ret) sur les
routines d’impact ; wallpaper sub_140012350 intact.

  ret : walk, encrypt, WinExec, VSS, kill, self-delete, GUI
  xor eax,eax ; ret : check langue (sinon skip wallpaper)

Charger ce fichier dans x64dbg (pas l’original), F9.
Attendu : %TEMP%\~umbra_wp.bmp + fond UmbraLock, aucun .umbra.
