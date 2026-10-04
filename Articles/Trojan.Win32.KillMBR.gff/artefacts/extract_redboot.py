#!/usr/bin/env python3
"""Re-extract AutoIt FileInstall blobs from unpacked RedBoot (defensive)."""
from pathlib import Path
from autoit_ripper import extract

ROOT = Path(__file__).resolve().parents[1]
PE = ROOT / "sample_unpacked.exe"
OUT = Path(__file__).resolve().parent / "payloads"


def main() -> None:
    OUT.mkdir(exist_ok=True)
    data = PE.read_bytes()
    items = extract(data)
    if not items:
        raise SystemExit("autoit_ripper: nothing extracted")
    names = {
        "script.au3": "RedBoot.au3",
        r"C:\Users\Kitty\Desktop\shared2\mbrover.exe": "overwrite.exe",
        r"C:\Users\Kitty\Desktop\assembler.exe": "assembler.exe",
        r"C:\Users\Kitty\Desktop\mbrover\mbr.asm": "boot.asm",
        r"C:\Users\Kitty\Desktop\Myriad\Concept Testing\TMkill.exe": "protect.exe",
    }
    for orig, blob in items:
        dest = OUT / names.get(orig, Path(orig).name)
        dest.write_bytes(blob)
        print(f"{orig} -> {dest.name} ({len(blob)} bytes)")


if __name__ == "__main__":
    main()
