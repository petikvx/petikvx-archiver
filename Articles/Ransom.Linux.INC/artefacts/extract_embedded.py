#!/usr/bin/env python3
"""Re-extract the embedded ransom note and the X25519 public key.

Reads the ELF as data. Does not execute it and does not touch file bodies.
"""
import base64
import hashlib
import pathlib
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
DEFAULT_SAMPLE = ROOT / "86d04474459f2b0df01eb59e37e26a0c5eff5c48b359fb662bf0ea513f0f7d13"
NOTE_PREFIX = b"fn5+fiBJTkMgUmFuc29tIH5+fn4KCi0t"
NOTE_LEN = 0x11DC
KEY_MARK = b"INC-README.txtINC"


def extract(blob: bytes):
    note_at = blob.find(NOTE_PREFIX)
    if note_at < 0:
        raise SystemExit("note base64 prefix not found")
    note = base64.b64decode(blob[note_at : note_at + NOTE_LEN])
    key_at = blob.find(KEY_MARK)
    if key_at < 0:
        raise SystemExit("public key marker not found")
    raw_b64 = blob[key_at + len(KEY_MARK) : key_at + len(KEY_MARK) + 44]
    key = base64.b64decode(raw_b64)
    if len(key) != 32:
        raise SystemExit(f"public key is {len(key)} bytes")
    return note, key


def main():
    sample = pathlib.Path(sys.argv[1]) if len(sys.argv) > 1 else DEFAULT_SAMPLE
    note, key = extract(sample.read_bytes())
    out = pathlib.Path(__file__).resolve().parent
    (out / "INC-README.txt").write_bytes(note)
    (out / "x25519_pubkey.bin").write_bytes(key)
    (out / "x25519_pubkey.hex").write_text(key.hex() + "\n")
    print(f"note {len(note)} sha256 {hashlib.sha256(note).hexdigest()}")
    print(f"x25519 {key.hex()}")


if __name__ == "__main__":
    main()
