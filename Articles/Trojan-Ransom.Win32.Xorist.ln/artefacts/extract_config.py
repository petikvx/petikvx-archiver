#!/usr/bin/env python3
"""Decrypt Xorist builder config from RT_BITMAP name=14 (defensive)."""
from __future__ import annotations
import argparse, struct
from pathlib import Path

def decrypt(blob: bytes) -> bytes:
    key, rest = blob[:16], bytearray(blob[16:])
    ki = 0
    for i in range(len(rest)):
        if ki == 16:
            ki = 0
        rest[i] ^= key[ki]
        ki += 1
    return bytes(rest)

def parse(out: bytes) -> dict:
    p = 0
    def take():
        nonlocal p
        n = struct.unpack_from("<I", out, p)[0]
        p += 4
        b = out[p : p + n]
        p += n
        return b
    ext_block = take()
    c = struct.unpack_from("<I", ext_block, 0)[0]
    pp = 4
    pats = []
    for _ in range(c):
        z = ext_block.find(b"\0", pp)
        pats.append(ext_block[pp:z].decode("latin-1", "replace"))
        pp = z + 1
    note = take().decode("cp1251", "replace")
    extension = take().split(b"\0")[0].decode()
    pwd = out[p : p + 16]; p += 16
    flags = list(out[p : p + 5]); p += 5
    drop = out[p : p + 16].split(b"\0")[0].decode(); p += 16
    cls = out[p : p + 16].split(b"\0")[0].decode(); p += 16
    attempts, tea, off, chunk = struct.unpack_from("<IIII", out, p)
    return dict(patterns=pats, note=note, extension=extension, pwd_hash=pwd.hex(),
                flags=flags, drop=drop, shell_class=cls, attempts=attempts,
                tea_rounds=tea, read_offset=off, chunk=chunk)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("blob", nargs="?", default="rsrc_2_e.bin")
    args = ap.parse_args()
    out = decrypt(Path(args.blob).read_bytes())
    Path("config_decrypted.bin").write_bytes(out)
    info = parse(out)
    for k, v in info.items():
        print(f"{k}: {v if k!='note' else repr(v[:60])+'...'}")

if __name__ == "__main__":
    main()
