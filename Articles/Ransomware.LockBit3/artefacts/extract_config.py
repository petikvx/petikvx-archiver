#!/usr/bin/env python3
"""Decrypt LockBit 3.0 config / GPO / icon blobs (defensive IR).

Algorithm (Northwave / static RE):
  8-byte seed at VA 0x426000
  64-bit multiply PRNG (immediates from aPLib stub XOR 0x30)
  XOR keystream (byte-swapped 8-byte blocks)
  aPLib decompress
"""
from __future__ import annotations

import argparse
import os
import struct
from io import BytesIO

VAR1, VAR2, VAR3, VAR4 = 0x5851F42D, 0x4C957F2D, 0xF767814F, 0x14057B7E


class APLib:
    def __init__(self, source: bytes, strict: bool = False):
        self.source = BytesIO(source)
        self.destination = bytearray()
        self.tag = 0
        self.bitcount = 0
        self.strict = strict

    def getbit(self) -> int:
        self.bitcount -= 1
        if self.bitcount < 0:
            b = self.source.read(1)
            if not b:
                raise EOFError("truncated")
            self.tag = b[0]
            self.bitcount = 7
        bit = (self.tag >> 7) & 1
        self.tag = (self.tag << 1) & 0xFF
        return bit

    def getgamma(self) -> int:
        result = 1
        while True:
            result = (result << 1) + self.getbit()
            if not self.getbit():
                break
        return result

    def depack(self) -> bytes:
        r0 = -1
        lwm = 0
        done = False
        try:
            first = self.source.read(1)
            if not first:
                return b""
            self.destination += first
            while not done:
                if self.getbit():
                    if self.getbit():
                        if self.getbit():
                            offs = 0
                            for _ in range(4):
                                offs = (offs << 1) + self.getbit()
                            if offs:
                                self.destination.append(self.destination[-offs])
                            else:
                                self.destination.append(0)
                            lwm = 0
                        else:
                            b = self.source.read(1)
                            if not b:
                                break
                            offs = b[0]
                            length = 2 + (offs & 1)
                            offs >>= 1
                            if offs:
                                for _ in range(length):
                                    self.destination.append(self.destination[-offs])
                            else:
                                done = True
                            r0 = offs
                            lwm = 1
                    else:
                        offs = self.getgamma()
                        if lwm == 0 and offs == 2:
                            offs = r0
                            length = self.getgamma()
                            for _ in range(length):
                                self.destination.append(self.destination[-offs])
                        else:
                            if lwm == 0:
                                offs -= 3
                            else:
                                offs -= 2
                            offs <<= 8
                            b = self.source.read(1)
                            if not b:
                                break
                            offs += b[0]
                            length = self.getgamma()
                            if offs >= 32000:
                                length += 1
                            if offs >= 1280:
                                length += 1
                            if offs < 128:
                                length += 2
                            for _ in range(length):
                                self.destination.append(self.destination[-offs])
                            r0 = offs
                        lwm = 1
                else:
                    b = self.source.read(1)
                    if not b:
                        break
                    self.destination += b
                    lwm = 0
        except (EOFError, IndexError, TypeError):
            if self.strict:
                raise
        return bytes(self.destination)


def aplib_decompress(data: bytes) -> bytes:
    return APLib(data, strict=False).depack()


def _algo(v1, v2, k1, k2):
    v1 &= 0xFFFFFFFF
    v2 &= 0xFFFFFFFF
    k1 &= 0xFFFFFFFF
    k2 &= 0xFFFFFFFF
    if (v1 | k2) == 0:
        tmp = k1 * v2
        return tmp & 0xFFFFFFFF, (tmp >> 32) & 0xFFFFFFFF
    tmp = k2 * v2
    tmp_eax = tmp & 0xFFFFFFFF
    tmp = k1 * v1
    tmp_eax = (tmp_eax + (tmp & 0xFFFFFFFF)) & 0xFFFFFFFF
    tmp = k1 * v2
    return tmp & 0xFFFFFFFF, ((tmp >> 32) + tmp_eax) & 0xFFFFFFFF


def make_keystream(static1: int, static2: int, n: int) -> bytes:
    state1, state2 = static1, static2
    out = bytearray()
    for _ in range((n + 7) // 8):
        t_eax, t_edx = _algo(VAR1, VAR2, state1, state2)
        t_eax = t_eax + VAR3
        t_edx = t_edx + VAR4
        if t_eax > 0xFFFFFFFF:
            t_edx += 1
        state1 = t_eax & 0xFFFFFFFF
        state2 = t_edx & 0xFFFFFFFF
        x, y = _algo(state2, state1, static1, static2)
        out.extend(
            (
                (x >> 0) & 0xFF,
                (y >> 8) & 0xFF,
                (x >> 8) & 0xFF,
                (y >> 0) & 0xFF,
                (x >> 16) & 0xFF,
                (y >> 24) & 0xFF,
                (x >> 24) & 0xFF,
                (y >> 16) & 0xFF,
            )
        )
    return bytes(out[:n])


def decrypt_aplib(blob: bytes, static1: int, static2: int) -> bytes:
    ks = make_keystream(static1, static2, len(blob))
    xored = bytes(a ^ b for a, b in zip(blob, ks))
    return aplib_decompress(xored)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("sample")
    ap.add_argument("-o", "--outdir", default=".")
    args = ap.parse_args()
    data = open(args.sample, "rb").read()
    # seed @ VA 0x426000 = start of .pdata (RAW 0x22E00)
    seed_off = 0x22E00
    cfg_off = 0x22E0C
    seed = data[seed_off : seed_off + 8]
    size = struct.unpack_from("<I", data, cfg_off - 4)[0]
    blob = data[cfg_off : cfg_off + size]
    s1, s2 = struct.unpack("<II", seed)
    os.makedirs(args.outdir, exist_ok=True)
    open(os.path.join(args.outdir, "config_key.bin"), "wb").write(seed)
    open(os.path.join(args.outdir, "config_enc.bin"), "wb").write(blob)
    dec = decrypt_aplib(blob, s1, s2)
    open(os.path.join(args.outdir, "config_dec.bin"), "wb").write(dec)
    print("seed", seed.hex(), "enc", len(blob), "dec", len(dec))


if __name__ == "__main__":
    main()
