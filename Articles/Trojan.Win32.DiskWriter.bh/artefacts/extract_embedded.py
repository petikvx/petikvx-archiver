#!/usr/bin/env python3
"""Re-extract MEMZ embedded blobs from MEMZ.exe.bin (defensive / IR only)."""
from __future__ import annotations

import hashlib
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SAMPLE = ROOT / "MEMZ.exe.bin"
OUT = Path(__file__).resolve().parent


def rva_to_off(rva: int) -> int:
    # PE32, sections from this sample (VA, raw ptr)
    secs = [
        (0x1000, 0x0B08, 0x400),
        (0x2000, 0x1B80, 0x1000),
        (0x4000, 0x00F4, 0x2C00),
        (0x5000, 0x01E8, 0x2E00),
        (0x6000, 0x01E8, 0x3000),
    ]
    for va, vsz, ro in secs:
        if va <= rva < va + max(vsz, 0x200):
            return ro + (rva - va)
    raise ValueError(hex(rva))


def main() -> None:
    data = SAMPLE.read_bytes()
    OUT.mkdir(parents=True, exist_ok=True)

    mbr = data[rva_to_off(0x21F8) : rva_to_off(0x21F8) + 0x12F]
    boot_blob = data[rva_to_off(0x2328) : rva_to_off(0x2328) + 0x7A0]
    (OUT / "mbr_code_0x12F.bin").write_bytes(mbr)
    (OUT / "boot_message_blob_0x7A0.bin").write_bytes(boot_blob)

    buf = bytearray(0x10000)
    buf[:0x12F] = mbr
    buf[510 : 510 + 0x7A0] = boot_blob
    (OUT / "PhysicalDrive0_first_64KiB.bin").write_bytes(buf)

    note_off = data.find(b"YOUR COMPUTER HAS BEEN FUCKED BY THE MEMZ TROJAN.")
    (OUT / "note.txt").write_bytes(data[note_off : note_off + 0xDA].rstrip(b"\x00"))

    hashes = (
        f"file: {SAMPLE.name}\n"
        f"size: {len(data)}\n"
        f"md5: {hashlib.md5(data).hexdigest()}\n"
        f"sha1: {hashlib.sha1(data).hexdigest()}\n"
        f"sha256: {hashlib.sha256(data).hexdigest()}\n"
    )
    (OUT / "hashes.txt").write_text(hashes)
    print(hashes)
    print("wrote", OUT)


if __name__ == "__main__":
    main()
