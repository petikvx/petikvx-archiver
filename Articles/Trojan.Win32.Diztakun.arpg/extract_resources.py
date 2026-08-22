#!/usr/bin/env python3
"""Defensive re-extraction of Creep.Properties.Resources from Trojan.Win32.Diztakun.arpg (000.exe.bin).

Requires: a prior ILSpy/ilspycmd dump of Creep.Properties.Resources.resx
OR parses managed resources via dnfile + manual BEEFCACE reader for Byte[].

Usage:
  python3 extract_resources.py [--sample 000.exe.bin] [--resx analysis/decompiled/Creep.Properties.Resources.resx] [--outdir analysis/extracted]
"""
from __future__ import annotations

import argparse
import base64
import hashlib
import re
import sys
from pathlib import Path

NAME_MAP = {
    "texticon": "icon.ico",
    "txt": "text.txt",
    "windl": "windl.bat",
    "one": "one.rtf",
    "subox": "rniw.exe",
    "street": "v.mp4",
    "_000": "_000.bin",
}


def extract_from_resx(resx: Path, outdir: Path) -> list[tuple[str, Path, int, str]]:
    text = resx.read_text(encoding="utf-8", errors="replace")
    pattern = re.compile(
        r'<data name="([^"]+)"[^>]*>\s*<value>\s*([A-Za-z0-9+/=\s]+)\s*</value>',
        re.S,
    )
    results = []
    outdir.mkdir(parents=True, exist_ok=True)
    for m in pattern.finditer(text):
        name = m.group(1)
        if name.startswith("."):
            continue
        b64 = re.sub(r"\s+", "", m.group(2))
        if not re.fullmatch(r"[A-Za-z0-9+/=]+", b64):
            continue
        raw = base64.b64decode(b64)
        out_name = NAME_MAP.get(name, f"{name}.bin")
        out = outdir / out_name
        out.write_bytes(raw)
        results.append((name, out, len(raw), hashlib.sha256(raw).hexdigest()))
    return results


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--resx", type=Path, default=Path("analysis/decompiled/Creep.Properties.Resources.resx"))
    ap.add_argument("--outdir", type=Path, default=Path("analysis/extracted"))
    args = ap.parse_args()
    if not args.resx.is_file():
        print(f"Missing {args.resx}; run ilspycmd first.", file=sys.stderr)
        return 1
    rows = extract_from_resx(args.resx, args.outdir)
    for name, path, size, sha in rows:
        print(f"{name:12} -> {path}  size={size}  sha256={sha}")
    print(f"Wrote {len(rows)} resources to {args.outdir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
