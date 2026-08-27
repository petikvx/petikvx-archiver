#!/usr/bin/env python3
"""Defensive IR helper: parse Makop encrypted-file footer from EOF.

Layout (from EOF, see README §7.7):
  [encrypted content ...]
  [AES-encrypted meta, meta_size bytes, 16-aligned]
  [meta_size : u32 LE]
  [IV : 16 bytes]
  [RSA-1024 wrap of AES key package : 128 bytes]
  [progress : u64 LE]

Usage:
  python3 parse_makop_footer.py path/to/file.[ID].[email].makop
  python3 parse_makop_footer.py path/to/file.makop --dump-dir ./footer_dump
"""
from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path


def parse_footer(data: bytes) -> dict:
    if len(data) < 156:
        raise ValueError(f"file too small ({len(data)} B); need at least 156 B for fixed trailer")

    progress = struct.unpack_from("<Q", data, len(data) - 8)[0]
    rsa_wrap = data[-8 - 128 : -8]
    iv = data[-8 - 128 - 16 : -8 - 128]
    meta_size = struct.unpack_from("<I", data, len(data) - 8 - 128 - 16 - 4)[0]

    fixed = 8 + 128 + 16 + 4
    if meta_size == 0 or meta_size > len(data) - fixed or meta_size % 16:
        raise ValueError(
            f"suspicious meta_size={meta_size} (file={len(data)} B); "
            "not a Makop footer or truncated copy"
        )

    meta_off = len(data) - fixed - meta_size
    meta_enc = data[meta_off : meta_off + meta_size]
    plaintext_prefix = data[:meta_off]

    return {
        "file_size": len(data),
        "meta_size": meta_size,
        "meta_offset": meta_off,
        "meta_enc": meta_enc,
        "iv": iv,
        "rsa_wrap": rsa_wrap,
        "progress": progress,
        "content_plus_pad_len": meta_off,
        "plaintext_prefix": plaintext_prefix,
    }


def main() -> int:
    ap = argparse.ArgumentParser(description="Parse Makop .makop footer (defensive IR)")
    ap.add_argument("path", type=Path, help="encrypted .makop file")
    ap.add_argument(
        "--dump-dir",
        type=Path,
        default=None,
        help="optional directory to write iv.bin / rsa_wrap.bin / meta_enc.bin",
    )
    ap.add_argument("--head", type=int, default=32, help="hex preview length")
    args = ap.parse_args()

    data = args.path.read_bytes()
    try:
        info = parse_footer(data)
    except ValueError as e:
        print(f"ERROR: {e}", file=sys.stderr)
        # still show last 200 bytes for manual triage
        tail = data[-200:]
        print(f"tail({len(tail)}): {tail.hex()}")
        return 1

    print(f"file: {args.path}")
    print(f"size: {info['file_size']} bytes")
    print(f"meta_size: {info['meta_size']} (offset 0x{info['meta_offset']:x})")
    print(f"IV:        {info['iv'].hex()}")
    print(f"RSA wrap:  {info['rsa_wrap'][:16].hex()}... ({len(info['rsa_wrap'])} B)")
    print(f"progress:  {info['progress']} (0x{info['progress']:x})")
    print(f"content+pad before footer: {info['content_plus_pad_len']} B")
    print(f"meta_enc[:{args.head}]: {info['meta_enc'][: args.head].hex()}")

    # Heuristic: small full-encrypted files often have high entropy from byte 0;
    # partial mode may leave a recognizable header (ZIP PK, PDF %PDF, etc.)
    head = info["plaintext_prefix"][:16]
    print(f"file head 16 B: {head.hex()}  ascii={head!r}")

    if args.dump_dir:
        args.dump_dir.mkdir(parents=True, exist_ok=True)
        (args.dump_dir / "iv.bin").write_bytes(info["iv"])
        (args.dump_dir / "rsa_wrap.bin").write_bytes(info["rsa_wrap"])
        (args.dump_dir / "meta_enc.bin").write_bytes(info["meta_enc"])
        (args.dump_dir / "footer_summary.txt").write_text(
            f"source={args.path}\n"
            f"file_size={info['file_size']}\n"
            f"meta_size={info['meta_size']}\n"
            f"meta_offset=0x{info['meta_offset']:x}\n"
            f"iv={info['iv'].hex()}\n"
            f"rsa_wrap={info['rsa_wrap'].hex()}\n"
            f"progress={info['progress']}\n"
            f"head16={head.hex()}\n"
        )
        print(f"dumped to {args.dump_dir}/")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
