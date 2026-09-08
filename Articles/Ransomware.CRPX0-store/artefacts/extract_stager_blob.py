#!/usr/bin/env python3
"""Defensive re-extraction of CRPx0 stager embedded Stage-3 PE (store.dll)."""
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
    ap.add_argument('-o', '--out', default='store.dll')
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
    length = struct.unpack_from('<I', data, va2off(data, 0x7B3820, imgbase, secs))[0]
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
        b = ((b << 6) | (b >> 2)) & 0xFF  # ROL 6 (= ROR 2)
        b = (~b) & 0xFF
        b ^= k1[j & 0x3F]
        blob[j] = b
    Path(args.out).write_bytes(blob)
    print(f'wrote {args.out} len={length} ko1=0x{ko1:02x} ko2=0x{ko2:02x} sha256={hashlib.sha256(blob).hexdigest()}')

if __name__ == '__main__':
    main()
