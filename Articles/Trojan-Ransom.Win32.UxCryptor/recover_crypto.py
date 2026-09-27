#!/usr/bin/env python3
"""Restore files written by Trojan-Ransom.Win32.UxCryptor (BIBORAN).

The sample (GForm1.method_13) XORs every byte with 0xAA and saves the
result as ``<original path>.crypto``, then deletes the original. The
inverse is the same XOR. This script only reads paths that already end
with ``.crypto`` and writes the restored name beside them.

It does not encrypt files and it does not walk a disk unless you pass
that directory. Default mode is a dry run: nothing is written until
``--apply``.

Example:
    python3 recover_crypto.py /path/to/Desktop
    python3 recover_crypto.py --apply /path/to/Desktop
    python3 recover_crypto.py --apply --remove-encrypted file.jpg.crypto
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

XOR_KEY = 0xAA
SUFFIX = ".crypto"

# First bytes of a restored file, used only as a sanity check.
KNOWN_HEADERS = (
    (b"\xff\xd8\xff", "jpeg"),
    (b"\x89PNG\r\n\x1a\n", "png"),
    (b"GIF87a", "gif"),
    (b"GIF89a", "gif"),
    (b"%PDF", "pdf"),
    (b"{\\rtf", "rtf"),
    (b"PK\x03\x04", "zip"),
    (b"BM", "bmp"),
    (b"RIFF", "riff"),
    (b"\xd0\xcf\x11\xe0", "ole"),
    (b"MZ", "pe"),
    (b"\xff\xfe", "utf-16-le"),
    (b"\xfe\xff", "utf-16-be"),
    (b"[.ShellClassInfo]", "desktop.ini"),
)


def xor_bytes(data: bytes, key: int = XOR_KEY) -> bytes:
    return bytes(b ^ key for b in data)


def header_label(data: bytes) -> str | None:
    for magic, name in KNOWN_HEADERS:
        if data.startswith(magic):
            return name
    return None


def iter_targets(paths: list[Path]) -> list[Path]:
    found: list[Path] = []
    for path in paths:
        if path.is_file():
            if path.name.lower().endswith(SUFFIX):
                found.append(path)
            else:
                print(f"skip (not {SUFFIX}): {path}", file=sys.stderr)
        elif path.is_dir():
            found.extend(p for p in path.rglob("*") if p.is_file() and p.name.lower().endswith(SUFFIX))
        else:
            print(f"skip (missing): {path}", file=sys.stderr)
    return found


def restored_path(src: Path) -> Path:
    name = src.name
    if name.lower().endswith(SUFFIX):
        name = name[: -len(SUFFIX)]
    return src.with_name(name)


def restore_one(src: Path, apply: bool, remove_encrypted: bool, strict: bool) -> str:
    data = src.read_bytes()
    plain = xor_bytes(data)
    kind = header_label(plain)
    dest = restored_path(src)
    status = kind or "no known header"
    if strict and kind is None:
        return f"skip strict ({status}): {src}"
    if not apply:
        return f"dry-run {status} -> {dest.name} ({len(plain)} bytes) from {src}"
    if dest.exists():
        if remove_encrypted and dest.read_bytes() == plain:
            src.unlink()
            return f"already restored, removed encrypted: {src}"
        return f"skip exists: {dest}"
    dest.write_bytes(plain)
    if remove_encrypted:
        written = dest.read_bytes()
        if written != plain:
            return f"kept encrypted, restore mismatch: {src}"
        src.unlink()
    return f"restored {status}: {dest}"


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("paths", nargs="+", type=Path, help="a .crypto file or a directory to scan")
    parser.add_argument("--apply", action="store_true", help="write restored files (default is a dry run)")
    parser.add_argument(
        "--remove-encrypted",
        action="store_true",
        help="delete the .crypto file after a successful write (requires --apply)",
    )
    parser.add_argument(
        "--strict",
        action="store_true",
        help="skip a file when the restored header is not a known type (jpeg, png, rtf, pdf, zip, …)",
    )
    args = parser.parse_args(argv)
    if args.remove_encrypted and not args.apply:
        parser.error("--remove-encrypted requires --apply")

    targets = iter_targets(args.paths)
    if not targets:
        print("no .crypto files found", file=sys.stderr)
        return 1
    for src in targets:
        try:
            print(restore_one(src, args.apply, args.remove_encrypted, args.strict))
        except OSError as exc:
            print(f"error {src}: {exc}", file=sys.stderr)
            return 1
    if not args.apply:
        print(f"{len(targets)} file(s) listed. Re-run with --apply to write them.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
