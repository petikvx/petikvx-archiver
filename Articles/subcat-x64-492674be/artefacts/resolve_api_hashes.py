#!/usr/bin/env python3
"""Resolve the API-name hashes used by stage 1 (sub_14006C120 / sub_14006C1D0).

Hash = xxHash32-like (primes 0x1B873593-style constants, seed = 4 bytes at
.rdata VA 0x14006D068 = 80 33 51 2d). Pure static: parses export tables of
system DLLs on the analysis host, never loads or runs anything.
Usage: python -I resolve_api_hashes.py [dll ...]
"""
import struct, sys

SEED = struct.unpack('<I', bytes.fromhex('8033512d'))[0]
M = 0xFFFFFFFF
rol = lambda x, r: ((x << r) | (x >> (32 - r))) & M
ror = lambda x, r: ((x >> r) | (x << (32 - r))) & M
P1, P2, P3, P4 = 458671337, 1759714724, (-1640531535) & M, (-2048144789) & M
P5, P6 = (-1255572915) & M, (-1028477387) & M


def h(name: bytes) -> int:
    n = len(name); i = 0
    if n < 16:
        a = (SEED + 668265263) & M
    else:
        v11 = (SEED + 458671337) & M; v12 = (SEED + 1759714724) & M
        v13 = (SEED + 504141809) & M; v14 = (SEED + 1255572915) & M
        while i <= n - 16:
            w = struct.unpack_from('<4I', name, i); i += 16
            v13 = (P5 * ror((v13 + 1759714724 * w[0]) & M, 19)) & M
            v12 = (P3 * ror((v12 + 458671337 * w[1]) & M, 15)) & M
            v11 = (P4 * ror((v11 - 1640531535 * w[2]) & M, 21)) & M
            v14 = (P6 * ror((v14 - 2048144789 * w[3]) & M, 13)) & M
        a = (ror(v13, 31) + ror(v12, 25) + ror(v11, 20) + ror(v14, 14)) & M
    v17 = (n + a) & M
    while n - i >= 4:
        w = struct.unpack_from('<I', name, i)[0]; i += 4
        v20 = ror((v17 + 458671337 * w) & M, 15)
        t = (P3 * v20) & M
        v19 = ((t ^ ror(t, 25)) - 1028477387) & M
        v17 = v19 ^ (v19 >> 11)
    while i < n:
        v22 = ror((v17 - 2048144789 * name[i]) & M, 21)
        t = (P5 * v22) & M
        v17 = (((t ^ (t >> 9)) + 668265263)) & M
        i += 1
    v23 = (458671337 * (((1759714724 * (v17 ^ (v17 >> 15))) & M) ^ (((1759714724 * (v17 ^ (v17 >> 15))) & M) >> 13))) & M
    t = (P3 * (v23 ^ (v23 >> 17))) & M
    v24 = (P4 * (t ^ (t >> 11))) & M
    t = (P6 * (v24 ^ (v24 >> 14))) & M
    v25 = (668265263 * (t ^ (t >> 12))) & M
    return v25 ^ (v25 >> 16)


def exports(path):
    d = open(path, 'rb').read()
    e = struct.unpack_from('<I', d, 0x3c)[0]
    ns = struct.unpack_from('<H', d, e + 6)[0]
    osz = struct.unpack_from('<H', d, e + 0x14)[0]
    secs = [struct.unpack_from('<4I', d, e + 0x18 + osz + i * 40 + 8) for i in range(ns)]
    def r2o(r):
        for vs, va, rs, rp in secs:
            if va <= r < va + max(vs, rs): return r - va + rp
    er = struct.unpack_from('<I', d, e + 0x18 + 0x70)[0]
    p = r2o(er)
    nn, an = struct.unpack_from('<II', d, p + 24)[0:2] if False else (struct.unpack_from('<I', d, p + 24)[0], 0)
    names = struct.unpack_from('<I', d, p + 32)[0]
    for i in range(nn):
        o = r2o(struct.unpack_from('<I', d, r2o(names) + 4 * i)[0])
        yield d[o:d.index(b'\0', o)]


# hashes called through sub_14006C120 in stage 1 (signed in IDA -> unsigned)
KNOWN = [-1838762466, -1523430869, 519025541, -238389182, -338759673, -1451188569,
         839766254, -354820609, -1843316889, 969583011, 2084682281, 633261396,
         -228599943, -406417383, 1035602057, 1963696304]
TARGET = {k & M: k for k in KNOWN}
dlls = sys.argv[1:] or [r'C:\Windows\System32\kernel32.dll', r'C:\Windows\System32\ntdll.dll',
                        r'C:\Windows\System32\kernelbase.dll']
for dll in dlls:
    for nm in exports(dll):
        v = h(nm)
        if v in TARGET:
            print('%-16s %-28s %#010x (%d)' % (dll.split('\\')[-1], nm.decode(), v, TARGET[v]))
# locale strings checked by sub_14006C400
for s in (b'ru', b'be', b'by', b'RU', b'BY', b'BE', b'kz', b'KZ', b'ua', b'UA', b'uk', b'hy', b'AM', b'az', b'AZ', b'uz', b'UZ'):
    v = h(s)
    if v in TARGET: print('locale string', s.decode(), '->', TARGET[v])
