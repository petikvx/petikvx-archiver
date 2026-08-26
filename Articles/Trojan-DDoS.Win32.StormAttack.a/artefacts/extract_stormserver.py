#!/usr/bin/env python3
"""Defensive extract: PE resource type DLL / id 101 -> StormServer.dll from StormAttack dropper."""
import argparse, hashlib, pathlib

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("dropper")
    ap.add_argument("-o", "--output", default="StormServer.dll")
    args = ap.parse_args()
    data = pathlib.Path(args.dropper).read_bytes()
    # This family build: resource DLL/101/2052 at file offset 0x5060, size 39936
    out = data[0x5060:0x5060 + 39936]
    if out[:2] != b"MZ":
        raise SystemExit("unexpected layout: no MZ at 0x5060")
    pathlib.Path(args.output).write_bytes(out)
    nz = sum(1 for b in out if b)
    print(args.output)
    print("md5   ", hashlib.md5(out).hexdigest())
    print("sha256", hashlib.sha256(out).hexdigest())
    print("size  ", len(out))
    print(f"nonzero_bytes {nz}/{len(out)} ({100 * nz / len(out):.1f}%)")

if __name__ == "__main__":
    main()
