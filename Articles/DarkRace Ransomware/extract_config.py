#!/usr/bin/env python3
"""Decrypt DarkRace / Conti-style embedded XML config (XOR 0xA9)."""
import argparse
import struct
from pathlib import Path

BLOB_VA = 0x435000
KEY_VA = 0x4295D0
BLOB_LEN = 0x5A45
IMAGE_BASE = 0x400000


def pe_sections(data: bytes):
    e = struct.unpack_from("<I", data, 0x3C)[0]
    numsec = struct.unpack_from("<H", data, e + 6)[0]
    sizeopt = struct.unpack_from("<H", data, e + 20)[0]
    sect = e + 24 + sizeopt
    secs = []
    for i in range(numsec):
        off = sect + i * 40
        va, vsz = struct.unpack_from("<II", data, off + 12)[1], struct.unpack_from("<I", data, off + 8)[0]
        # fix order: SizeOfRawData at +16, PointerToRawData at +20, VirtualSize +8, VirtualAddress +12
        vsz, va, rsz, raw = struct.unpack_from("<IIII", data, off + 8)
        secs.append((va, max(vsz, rsz), raw))
    return secs


def va_to_off(secs, va: int) -> int:
    rva = va - IMAGE_BASE
    for va0, sz, raw in secs:
        if va0 <= rva < va0 + sz:
            return raw + (rva - va0)
    raise ValueError(f"VA not in sections: {va:#x}")


def decrypt(pe: bytes) -> bytes:
    secs = pe_sections(pe)
    blob_off = va_to_off(secs, BLOB_VA)
    key_off = va_to_off(secs, KEY_VA)
    key = pe[key_off : key_off + 16]
    blob = bytearray(pe[blob_off : blob_off + BLOB_LEN])
    for i in range(0, 0x5A40, 16):
        for j in range(16):
            blob[i + j] ^= key[j]
    for i in range(0x5A40, BLOB_LEN):
        blob[i] ^= 0xA9
    last = bytes(blob).rfind(b">")
    return bytes(blob[: last + 1]) if last >= 0 else bytes(blob)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("pe", type=Path)
    ap.add_argument("-o", "--output", type=Path, default=Path("darkrace_config_decrypted.xml"))
    args = ap.parse_args()
    xml = decrypt(args.pe.read_bytes())
    args.output.write_bytes(xml)
    print(f"Wrote {args.output} ({len(xml)} bytes)")


if __name__ == "__main__":
    main()
