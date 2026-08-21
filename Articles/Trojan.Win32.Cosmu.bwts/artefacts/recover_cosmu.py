#!/usr/bin/env python3
"""Defensive recovery for Cosmu/Zombie-transformed files (sub_401340 layout).

IR / research only. Reconstructs the original payload when the file still has:
  [malware PE][56-byte meta][scrambled data][8-byte footer]

Usage:
  python3 recover_cosmu.py suspicious.doc.exe -o restored.doc
  python3 recover_cosmu.py sample.exe --info
"""
from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path


def parse(data: bytes) -> dict:
    if len(data) < 8 + 0x38:
        raise ValueError("file too small")
    pe_size, mark = struct.unpack_from("<II", data, len(data) - 8)
    if mark != len(data):
        raise ValueError(f"footer mark mismatch: dword1={mark} size={len(data)}")
    if pe_size <= 0 or pe_size + 0x38 + 8 > len(data):
        raise ValueError(f"bad pe_size {pe_size}")
    meta = data[pe_size : pe_size + 0x38]
    # basename is a C string in the first part of the 48-byte area
    # Buffer[48] then orig_size, key (fwrite 0x38 = 56 bytes)
    name = meta.split(b"\0", 1)[0].decode("latin-1", errors="replace")
    orig_size, key = struct.unpack_from("<II", meta, 48)
    scrambled = data[pe_size + 0x38 : len(data) - 8]
    return {
        "pe_size": pe_size,
        "orig_size": orig_size,
        "key": key,
        "basename": name,
        "scrambled": scrambled,
        "carrier_exe": key == 0,
    }


def recover_bytes(info: dict) -> bytes:
    key = info["key"]
    orig = info["orig_size"]
    blob = bytearray(info["scrambled"][:orig])  # may be longer if padding; take orig
    if len(blob) < orig:
        raise ValueError(f"payload short: have {len(blob)} need {orig}")
    if key == 0:
        # carrier: plaintext original after meta
        return bytes(blob[:orig])
    # subtract key (inverse of fputc(v29 + byte))
    for i in range(len(blob)):
        blob[i] = (blob[i] - key) & 0xFF
    half = orig // key if key else 0
    # written order was [half..orig) then [0..half)
    second = bytes(blob[: orig - half])
    first = bytes(blob[orig - half : orig])
    return first + second


def main(argv: list[str]) -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("path", type=Path)
    ap.add_argument("-o", "--output", type=Path)
    ap.add_argument("--info", action="store_true")
    args = ap.parse_args(argv)
    data = args.path.read_bytes()
    info = parse(data)
    if args.info:
        print(f"basename : {info['basename']}")
        print(f"pe_size  : {info['pe_size']}")
        print(f"orig_size: {info['orig_size']}")
        print(f"key      : {info['key']} ({'carrier/no-XOR' if info['carrier_exe'] else 'document XOR'})")
        return 0
    out = recover_bytes(info)
    dest = args.output
    if dest is None:
        dest = Path(info["basename"] or "recovered.bin")
    dest.write_bytes(out)
    print(f"wrote {dest} ({len(out)} bytes)")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main(sys.argv[1:]))
    except Exception as e:
        print(f"error: {e}", file=sys.stderr)
        raise SystemExit(1)
