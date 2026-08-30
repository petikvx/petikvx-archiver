#!/usr/bin/env python3
"""Decode the wordlist-encoded EnCase/OemHwUpd.sys embedded in the Huntress EDR killer."""
from __future__ import annotations
import argparse
import hashlib
from pathlib import Path

EXPECTED_DRIVER_SHA256 = "3111f4d7d4fac55103453c4c8adb742def007b96b7c8ed265347df97137fbee0"
EXPECTED_KILLER_SHA256 = "6a6aaeed4a6bbe82a08d197f5d40c2592a461175f181e0440e0ff45d5fb60939"


def extract_wordlist(data: bytes) -> list[str]:
    off = data.find(b"about\x00")
    if off < 0:
        raise SystemExit("wordlist start 'about\\0' not found")
    words: list[str] = []
    i = off
    while len(words) < 256 and i < len(data):
        if data[i] == 0:
            i += 1
            continue
        end = data.find(b"\x00", i)
        if end < 0:
            break
        w = data[i:end]
        if not w or not all(32 <= b < 127 for b in w):
            break
        words.append(w.decode("ascii"))
        i = end + 1
    if len(words) != 256:
        raise SystemExit(f"expected 256 words, got {len(words)}")
    if words[0] != "about" or words[77] != "block" or words[90] != "both":
        raise SystemExit(f"unexpected dictionary: {words[0]=} {words[77]=} {words[90]=}")
    return words


def extract_encoded_blob(data: bytes) -> bytes:
    start = data.find(b"block both choice about")
    if start < 0:
        raise SystemExit("encoded payload start not found")
    j = start
    while j < len(data) and data[j] in b"abcdefghijklmnopqrstuvwxyz ":
        j += 1
    return data[start:j]


def decode(blob: bytes, words: list[str]) -> bytes:
    word2b = {w: i for i, w in enumerate(words)}
    out = bytearray()
    for tok in blob.split(b" "):
        if not tok:
            continue
        s = tok.decode("ascii")
        if s not in word2b:
            raise SystemExit(f"unknown word in payload: {s!r}")
        out.append(word2b[s])
    return bytes(out)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("sample", type=Path, help="EDR killer PE (svchost.exe / VirusShare name)")
    ap.add_argument("-o", "--output", type=Path, default=Path("OemHwUpd_decoded.sys"))
    ap.add_argument("--wordlist-out", type=Path, default=None)
    args = ap.parse_args()
    data = args.sample.read_bytes()
    sha = hashlib.sha256(data).hexdigest()
    print(f"sample sha256: {sha}")
    if sha != EXPECTED_KILLER_SHA256:
        print(f"note: differs from Huntress IoC {EXPECTED_KILLER_SHA256}")
    words = extract_wordlist(data)
    blob = extract_encoded_blob(data)
    print(f"wordlist: 256 words; encoded blob: {len(blob)} bytes")
    drv = decode(blob, words)
    print(f"decoded driver: {len(drv)} bytes; header={drv[:4]!r}")
    dsha = hashlib.sha256(drv).hexdigest()
    print(f"driver sha256: {dsha}")
    if dsha != EXPECTED_DRIVER_SHA256:
        print(f"WARNING: differs from Huntress OemHwUpd.sys {EXPECTED_DRIVER_SHA256}")
    args.output.write_bytes(drv)
    print(f"wrote {args.output}")
    if args.wordlist_out:
        args.wordlist_out.write_text("\n".join(f"{i:3d} 0x{i:02X} {w}" for i, w in enumerate(words)) + "\n")
        print(f"wrote {args.wordlist_out}")


if __name__ == "__main__":
    main()
