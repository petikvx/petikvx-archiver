#!/usr/bin/env python3
"""Re-extract Spora hardcoded AES-CBC blobs (defensive / IR only).

Hardcoded PLAINTEXTKEYBLOB @ VA 0x4011a8 (file 0x5a8):
  AES-256 key, CBC, IV = 16 zero bytes.

Runtime decrypt helper @ 0x40502e (CryptImportKey + CryptDecrypt), called from 0x40507a:
  VA 0x4011d4 size 0x20   -> sample ID
  VA 0x4011f8 size 0x120  -> RSA-1024 public key (PEM)
  VA 0x401318 size 0x1d80 -> ransom note HTML
  VA 0x403098 size 0x20   -> 32 zero bytes after decrypt (placeholder)
"""
from __future__ import annotations

import argparse
import sys
from pathlib import Path

try:
    from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
except ImportError:
    sys.stderr.write("Need cryptography: pip install cryptography\n")
    sys.exit(1)

AES_KEY = bytes.fromhex(
    "67e8a557a701f60b9c7e7a9833b80b2f30e6afcda8f236e88c7bce10ca4f6977"
)
IV = b"\x00" * 16
IMAGE_BASE = 0x400000
TEXT_VA = 0x1000
TEXT_RAW = 0x400

BLOBS = (
    ("sample_id", 0x4011D4, 0x20),
    ("rsa_pubkey", 0x4011F8, 0x120),
    ("ransom_html", 0x401318, 0x1D80),
    ("blob_403098", 0x403098, 0x20),
)


def va_to_off(va: int) -> int:
    return TEXT_RAW + (va - IMAGE_BASE - TEXT_VA)


def decrypt(ct: bytes) -> bytes:
    if len(ct) % 16:
        raise ValueError(f"ciphertext length {len(ct)} not multiple of 16")
    d = Cipher(algorithms.AES(AES_KEY), modes.CBC(IV)).decryptor()
    pt = d.update(ct) + d.finalize()
    pad = pt[-1]
    if 1 <= pad <= 16 and pt.endswith(bytes([pad]) * pad):
        pt = pt[:-pad]
    return pt


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument(
        "sample",
        nargs="?",
        default="Trojan-Ransom.Win32.Spora.a-7ad9ed23a91643b517e82ad5740d24eca16bcae21cfe1c0da78ee80e0d1d3f02",
    )
    ap.add_argument("-o", "--outdir", default="artefacts")
    args = ap.parse_args()

    data = Path(args.sample).read_bytes()
    out = Path(args.outdir)
    out.mkdir(parents=True, exist_ok=True)

    for name, va, size in BLOBS:
        off = va_to_off(va)
        pt = decrypt(data[off : off + size])
        (out / f"{name}.bin").write_bytes(pt)
        print(f"{name}: VA={va:#x} file={off:#x} size={size:#x} -> {len(pt)} bytes")

        if name == "sample_id":
            sid = pt.split(b"\0", 1)[0].decode("ascii", "replace")
            (out / "sample_id.txt").write_text(sid + "\n", encoding="ascii")
            print(f"  ID={sid}")
        elif name == "rsa_pubkey":
            pem = pt.split(b"\0", 1)[0].decode("ascii", "replace").strip() + "\n"
            (out / "rsa_public_key.pem").write_text(pem, encoding="ascii")
            print(f"  PEM lines={pem.count(chr(10))}")
        elif name == "ransom_html":
            # BOM + HTML
            (out / "ransom_note.html").write_bytes(pt)
            print(f"  HTML title present: {b'Spora' in pt}")

    meta = out / "aes_hardcoded_key.txt"
    meta.write_text(
        "AES-256 key (hex): "
        + AES_KEY.hex()
        + "\nMode: CBC, IV=00*16\nSee extract_aes_blobs.py docstring.\n",
        encoding="ascii",
    )
    print(f"wrote under {out}/")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
