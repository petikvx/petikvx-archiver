Wallpaper: generated at runtime, not an embedded resource.

SetWallpaper() in KerRansom.cs:
- Bitmap 1920x1080, black background
- White Arial Bold ~160pt: "OPS..."
- White Arial ~32pt: "Don't reboot your pc or your files will delete."
- Saved as %TEMP%\wall.bmp
- SystemParametersInfo(SPI_SETDESKWALLPAPER=20, SPIF_UPDATEINIFILE|SPIF_SENDCHANGE=3)
- HKCU\Control Panel\Desktop Wallpaper / WallpaperStyle=10 / TileWallpaper=0

wallpaper.bmp in this folder is a reconstruction (same text, same size) for documentation.
The live file on a victim is created only after execution.
