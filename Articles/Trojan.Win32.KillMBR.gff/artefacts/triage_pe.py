#!/usr/bin/env python3
"""Defensive PE triage: imports, strings, resources, interesting blobs."""
from __future__ import annotations

import hashlib
import math
import os
import re
import struct
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SAMPLE = ROOT / "sample_unpacked.exe"
OUT = Path(__file__).resolve().parent


def entropy(b: bytes) -> float:
    if not b:
        return 0.0
    c = Counter(b)
    n = len(b)
    return -sum((v / n) * math.log2(v / n) for v in c.values())


def rva_to_off(sections, rva: int) -> int | None:
    for va, vsz, roff, rsz in sections:
        if va <= rva < va + max(vsz, rsz):
            return roff + (rva - va)
    return None


def parse_pe(data: bytes):
    e_lfanew = struct.unpack_from("<I", data, 0x3C)[0]
    coff = e_lfanew + 4
    machine, nsec, ts, _, _, optsz, chars = struct.unpack_from("<HHIIIHH", data, coff)
    opt = coff + 20
    magic = struct.unpack_from("<H", data, opt)[0]
    assert magic == 0x10B
    ep = struct.unpack_from("<I", data, opt + 16)[0]
    imgbase = struct.unpack_from("<I", data, opt + 28)[0]
    dd_off = opt + 96
    sec_off = opt + optsz
    sections = []
    for i in range(nsec):
        name = data[sec_off + i * 40 : sec_off + i * 40 + 8].split(b"\x00")[0]
        vsz, va, rsz, roff = struct.unpack_from("<IIII", data, sec_off + i * 40 + 8)
        sections.append((va, vsz, roff, rsz, name))
    secs_simple = [(va, vsz, roff, rsz) for va, vsz, roff, rsz, _ in sections]
    return {
        "e_lfanew": e_lfanew,
        "machine": machine,
        "nsec": nsec,
        "ts": ts,
        "chars": chars,
        "ep": ep,
        "imgbase": imgbase,
        "dd_off": dd_off,
        "sections": sections,
        "secs_simple": secs_simple,
        "opt": opt,
    }


def parse_imports(data, pe):
    dd_off = pe["dd_off"]
    imp_rva, imp_sz = struct.unpack_from("<II", data, dd_off + 8)
    off = rva_to_off(pe["secs_simple"], imp_rva)
    imports = []
    while True:
        orig, tdstamp, chain, name_rva, first = struct.unpack_from("<IIIII", data, off)
        if orig == 0 and name_rva == 0:
            break
        name_off = rva_to_off(pe["secs_simple"], name_rva)
        dll = data[name_off:].split(b"\x00", 1)[0].decode("ascii", "replace")
        thunk_rva = orig or first
        funcs = []
        t_off = rva_to_off(pe["secs_simple"], thunk_rva)
        while True:
            thunk = struct.unpack_from("<I", data, t_off)[0]
            if thunk == 0:
                break
            if thunk & 0x80000000:
                funcs.append(f"ord_{thunk & 0xFFFF}")
            else:
                hint_off = rva_to_off(pe["secs_simple"], thunk)
                hint = struct.unpack_from("<H", data, hint_off)[0]
                fname = data[hint_off + 2 :].split(b"\x00", 1)[0].decode("ascii", "replace")
                funcs.append(fname)
            t_off += 4
        imports.append((dll, funcs))
        off += 20
    return imports


def walk_resources(data, pe, rva, res_va, level=0, path=()):
    off = rva_to_off(pe["secs_simple"], rva)
    if off is None:
        return []
    n_named, n_id = struct.unpack_from("<HH", data, off + 12)
    entries = []
    base = off + 16
    for i in range(n_named + n_id):
        name, offset = struct.unpack_from("<II", data, base + i * 8)
        ident = name & 0x7FFFFFFF
        if name & 0x80000000:
            soff = rva_to_off(pe["secs_simple"], res_va + ident)
            if soff is None:
                label = f"name_{ident:x}"
            else:
                nlen = struct.unpack_from("<H", data, soff)[0]
                label = data[soff + 2 : soff + 2 + nlen * 2].decode("utf-16le", "replace")
        else:
            label = ident
        child = offset & 0x7FFFFFFF
        child_rva = res_va + child
        if offset & 0x80000000:
            entries.extend(walk_resources(data, pe, child_rva, res_va, level + 1, path + (label,)))
        else:
            doff = rva_to_off(pe["secs_simple"], child_rva)
            data_rva, size, codepage, _ = struct.unpack_from("<IIII", data, doff)
            foff = rva_to_off(pe["secs_simple"], data_rva)
            blob = data[foff : foff + size] if foff is not None else b""
            entries.append((path + (label,), data_rva, size, codepage, foff, blob))
    return entries


def extract_strings(data: bytes):
    ascii_s = [m.group().decode("ascii") for m in re.finditer(rb"[\x20-\x7e]{5,}", data)]
    uni = []
    for m in re.finditer(rb"(?:[\x20-\x7e]\x00){5,}", data):
        try:
            uni.append(m.group().decode("utf-16le"))
        except Exception:
            pass
    return ascii_s, uni


def main():
    data = SAMPLE.read_bytes()
    pe = parse_pe(data)
    lines = []
    lines.append(f"file {SAMPLE.name}")
    lines.append(f"size {len(data)}")
    lines.append(f"md5 {hashlib.md5(data).hexdigest()}")
    lines.append(f"sha1 {hashlib.sha1(data).hexdigest()}")
    lines.append(f"sha256 {hashlib.sha256(data).hexdigest()}")
    lines.append(f"EP RVA {pe['ep']:#x} VA {pe['imgbase']+pe['ep']:#x}")
    lines.append(f"ImageBase {pe['imgbase']:#x}")
    lines.append(f"TimeDateStamp {pe['ts']:#x}")
    lines.append("")
    lines.append("=== sections ===")
    for va, vsz, roff, rsz, name in pe["sections"]:
        blob = data[roff : roff + rsz]
        lines.append(
            f"{name.decode():8s} VA={va:#08x} VSz={vsz:#x} raw={roff:#x}+{rsz:#x} ent={entropy(blob):.3f}"
        )
    lines.append("")
    lines.append("=== imports ===")
    imps = parse_imports(data, pe)
    for dll, funcs in imps:
        lines.append(f"[{dll}]")
        for f in funcs:
            lines.append(f"  {f}")
    (OUT / "pe_info.txt").write_text("\n".join(lines) + "\n", encoding="utf-8")
    (OUT / "imports.txt").write_text(
        "\n".join(f"{dll}!{f}" for dll, funcs in imps for f in funcs) + "\n", encoding="utf-8"
    )

    ascii_s, uni = extract_strings(data)
    (OUT / "strings_ascii.txt").write_text("\n".join(ascii_s) + "\n", encoding="utf-8", errors="replace")
    (OUT / "strings_unicode.txt").write_text("\n".join(uni) + "\n", encoding="utf-8", errors="replace")

    kws = [
        "PhysicalDrive",
        "\\\\.\\",
        "MBR",
        "boot",
        "vssadmin",
        "bcdedit",
        "ntdll",
        "NtDeviceIoControl",
        "CreateFile",
        "WriteFile",
        "DeviceIoControl",
        "SeShutdown",
        "SeDebug",
        "AdjustToken",
        "OpenProcessToken",
        "ExitWindows",
        "InitiateSystemShutdown",
        "NtRaiseHardError",
        "MessageBox",
        "cmd.exe",
        "powershell",
        "http",
        "https",
        ".onion",
        "bitcoin",
        "mutex",
        "Global\\",
        "\\\\.\\PhysicalDrive0",
        "\\\\.\\C:",
        "\\\\.\\Harddisk",
        "IOCTL",
        "FSCTL",
        "mbr",
        "disk",
        "format",
        "cipher",
        "Crypt",
        "Ransom",
        "Your files",
        "wallpaper",
        "SystemParametersInfo",
        "SetWindowsHook",
        "ShellExecute",
        "WinExec",
        "URLDownload",
        "InternetOpen",
        "WSAStartup",
        "socket",
        "RegSetValue",
        "RunOnce",
        "CurrentVersion\\Run",
    ]
    hits = []
    low_ascii = "\n".join(ascii_s).lower()
    low_uni = "\n".join(uni).lower()
    for kw in kws:
        a = kw.lower() in low_ascii
        u = kw.lower() in low_uni
        if a or u:
            hits.append(f"{kw}: ascii={a} unicode={u}")
    (OUT / "keyword_hits.txt").write_text("\n".join(hits) + "\n", encoding="utf-8")

    try:
        res_va = [va for va, vsz, roff, rsz, n in pe["sections"] if n == b".rsrc"][0]
        entries = walk_resources(data, pe, res_va, res_va)
    except Exception as e:
        entries = []
        (OUT / "resources_error.txt").write_text(repr(e), encoding="utf-8")
    rsrc_dir = OUT / "rsrc"
    rsrc_dir.mkdir(exist_ok=True)
    rlines = ["path | rva | size | off | magic | entropy"]
    for path, rva, size, cp, foff, blob in entries:
        mag = blob[:8].hex() if blob else ""
        ent = entropy(blob)
        label = "_".join(str(x) for x in path)
        safe = re.sub(r"[^A-Za-z0-9_.-]+", "_", label)[:80]
        ext = "bin"
        if blob[:2] == b"MZ":
            ext = "exe"
        elif blob[:2] == b"BM":
            ext = "bmp"
        elif blob[:3] == b"\xff\xd8\xff":
            ext = "jpg"
        elif blob[:8] == b"\x89PNG\r\n\x1a\n":
            ext = "png"
        elif blob[:4] == b"RIFF":
            ext = "wav"
        elif blob[:4] == b"\x00\x00\x01\x00":
            ext = "ico"
        outp = rsrc_dir / f"{safe}.{ext}"
        if blob:
            outp.write_bytes(blob)
        rlines.append(f"{path} rva={rva:#x} size={size} off={foff} mag={mag} ent={ent:.3f} -> {outp.name}")
    (OUT / "resources.txt").write_text("\n".join(rlines) + "\n", encoding="utf-8")

    # interesting ASCII around disk APIs
    for pat in [
        rb"\\\\.\\PhysicalDrive0",
        rb"\\\\.\\PhysicalDrive",
        rb"\\\\.\\C:",
        rb"PhysicalDrive0",
        rb"NtRaiseHardError",
        rb"SeShutdownPrivilege",
        rb"SeDebugPrivilege",
        rb"ntdll.dll",
        rb"kernel32.dll",
    ]:
        i = 0
        while True:
            j = data.find(pat, i)
            if j < 0:
                break
            print(f"HIT {pat} at fileoff {j:#x} VA? ")
            i = j + 1

    print("wrote artefacts, resources", len(entries), "imports", sum(len(f) for _, f in imps))


if __name__ == "__main__":
    main()
