#!/usr/bin/env python3
"""Re-extract the Umbra PE overlay config (RBMU / !DNE trailer). Defensive / IR only."""
from __future__ import annotations

import argparse
import struct
from pathlib import Path

MAGIC_HEAD = b"RBMU"
MAGIC_TAIL = b"!DNE"


def extract(pe: bytes) -> bytes:
    if len(pe) < 12 or pe[-4:] != MAGIC_TAIL or pe[-12:-8] != MAGIC_HEAD:
        raise ValueError("no RBMU / !DNE trailer")
    size = struct.unpack_from("<I", pe, len(pe) - 8)[0]
    off = len(pe) - 12 - size
    if off < 0 or size != len(pe) - 12 - off:
        raise ValueError(f"bad config size {size}")
    return pe[off : off + size]


def parse_config(cfg: bytes) -> dict:
    if len(cfg) < 301:
        raise ValueError(f"config blob too small: {len(cfg)}")
    key = cfg[:272]
    flags = cfg[272:301]
    i = 301
    strings = []
    while i + 4 <= len(cfg):
        n = struct.unpack_from("<I", cfg, i)[0]
        i += 4
        if n == 0:
            strings.append("")
            continue
        if i + n > len(cfg):
            raise ValueError(f"string overflow at {i:#x} n={n}")
        strings.append(cfg[i : i + n].decode("utf-8"))
        i += n
    names = [
        "extension",
        "skip_dirs",
        "skip_files",
        "skip_ext",
        "empty_1",
        "kill_proc",
        "kill_svc",
        "empty_2",
        "empty_3",
        "note",
    ]
    fields = {names[k] if k < len(names) else f"str_{k}": s for k, s in enumerate(strings)}
    return {"key_blob": key, "flags": flags, "fields": fields}


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("pe")
    ap.add_argument("-o", "--outdir", default=".")
    args = ap.parse_args()
    pe = Path(args.pe).read_bytes()
    out = Path(args.outdir)
    out.mkdir(parents=True, exist_ok=True)
    cfg = extract(pe)
    (out / "config_blob.bin").write_bytes(cfg)
    parsed = parse_config(cfg)
    (out / "key_blob_272.bin").write_bytes(parsed["key_blob"])
    note = parsed["fields"].get("note", "")
    (out / "ransom_note.txt").write_text(note, encoding="utf-8")
    print(f"config {len(cfg)} bytes")
    print(f"flags {parsed['flags'].hex()}")
    for k, v in parsed["fields"].items():
        preview = v.replace("\n", " / ")[:80]
        print(f"  {k}: {len(v)} {preview!r}")


if __name__ == "__main__":
    main()
