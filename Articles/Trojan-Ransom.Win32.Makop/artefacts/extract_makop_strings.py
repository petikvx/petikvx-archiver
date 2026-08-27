#!/usr/bin/env python3
"""Defensive re-extraction of Makop AES-encrypted string table from .ndata."""
import struct, sys
from pathlib import Path
from Crypto.Cipher import AES

KEY = bytes.fromhex("a91da6d2be9a4ce8d66176a3063c2b43dd2d3c24d66a095f48d5cf03caca70bc")

def main(path):
    data = Path(path).read_bytes()
    # PE32: section .ndata RawPtr 0x7400 for this sample; fallback scan header
    ndata = data[0x7400:]
    count, _ = struct.unpack_from("<II", ndata, 0)
    for i in range(count):
        eid, start, end, plen = struct.unpack_from("<HHHH", ndata, 8 + i * 8)
        blob = ndata[start:end]
        pt = AES.new(KEY, AES.MODE_CBC, iv=b"\x00" * 16).decrypt(blob)[:plen]
        if plen >= 4 and pt[1:2] == b"\x00":
            text = pt.decode("utf-16le", "replace").split("\x00")[0]
        else:
            text = pt.split(b"\x00")[0].decode("latin1", "replace")
            if not text.isprintable():
                text = pt.hex()
        print(f"[{eid:3d}] {text}")

if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else "2026-08-21_1d71f0bef3fba293a0d43bffb6941f21_elex_makop")
