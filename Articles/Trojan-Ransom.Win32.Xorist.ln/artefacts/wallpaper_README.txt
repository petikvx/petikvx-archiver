# Wallpaper extraction (Xorist.ln unpacked)

## Code path (sub_4010FC)
1. Build random 16-char name from RDTSC nibbles + ".bmp"
2. FindResourceA(NULL, "pussylicker", RT_BITMAP /*2*/)
3. Write resource bytes to %TEMP%\<name>.bmp
4. SystemParametersInfoA(SPI_SETDESKWALLPAPER=0x14, ...)

## What is in THIS sample
- String "pussylicker" exists in .data (resource *name* expected by the code).
- PE resource tree has NO named BITMAP "pussylicker".
- Only real BMP present: type IMAGE / id 2000 → **1×1 pixel** placeholder
  → wallpaper_1x1_placeholder.bmp (66 bytes).
- BITMAP id 14 is the **encrypted builder config**, not an image
  (rsrc_2_e.bin / extract_config.py).

## Conclusion
Wallpaper drop **fails silently** on this build (FindResource returns NULL).
No full-size scare wallpaper to extract. Sibling Xorist.lk is the same.
