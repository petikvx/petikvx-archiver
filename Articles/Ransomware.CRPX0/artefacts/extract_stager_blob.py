#!/usr/bin/env python3
"""Defensive re-extraction of CRPx0 standalone EXE embedded Stage-3 PE (index.dll)."""
from pathlib import Path
import struct, argparse, hashlib

def va2off(data, va, imgbase, secs):
    rva = va - imgbase
    for name, sva, vsz, raw, rsz in secs:
        if sva <= rva < sva + max(vsz, rsz):
            return raw + (rva - sva)
    raise ValueError(hex(va))

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('sample')
    ap.add_argument('-o', '--out', default='index.dll.decrypted')
    args = ap.parse_args()
    data = Path(args.sample).read_bytes()
    e = struct.unpack_from('<I', data, 0x3C)[0]
    nsec = struct.unpack_from('<H', data, e + 6)[0]
    opt = struct.unpack_from('<H', data, e + 20)[0]
    imgbase = struct.unpack_from('<I', data, e + 24 + 28)[0]
    soff = e + 24 + opt
    secs = []
    for _ in range(nsec):
        name = data[soff:soff+8].split(b'\0', 1)[0].decode()
        vsize, va, rsize, raw = struct.unpack_from('<IIII', data, soff + 8)
        secs.append((name, va, vsize, raw, rsize))
        soff += 40
    # nNumberOfBytesToWrite sits 0x20 bytes before k1 (align 20h) in this build
    length = struct.unpack_from('<I', data, va2off(data, 0x7B3820, imgbase, secs))[0]
    if length < 0x100000 or length > 0x500000:
        length = 0x3B0800
    blob = bytearray(data[va2off(data, 0x403020, imgbase, secs):][:length])
    k1 = bytearray(data[va2off(data, 0x7B3840, imgbase, secs):][:64])
    k2 = bytearray(data[va2off(data, 0x7B3880, imgbase, secs):][:64])
    ko1 = data[va2off(data, 0x7B38C0, imgbase, secs)]
    ko2 = data[va2off(data, 0x7B38C1, imgbase, secs)]
    for i in range(64):
        k1[i] ^= ko1
        k2[i] ^= ko2
    for j in range(length):
        b = blob[j]
        b ^= k2[j & 0x3F]
        b = ((b << 7) | (b >> 1)) & 0xFF  # ROR 1
        b = (~b) & 0xFF
        b ^= k1[j & 0x3F]
        blob[j] = b
    Path(args.out).write_bytes(blob)
    print(f'wrote {args.out} len={length} sha256={hashlib.sha256(blob).hexdigest()} MZ={blob[:2]==b"MZ"}')

if __name__ == '__main__':
    main()
