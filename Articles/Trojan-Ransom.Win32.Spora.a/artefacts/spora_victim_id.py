#!/usr/bin/env python3
"""Spora victim ID — clear reference for sub_403C45 (defensive / IR only).

Layout produced by the malware (WCHAR string, no NUL counted below):

  [0..1]  country   GetLocaleInfoW(LOCALE_USER_DEFAULT, LOCALE_SABBREVCTRYNAME)
                    truncated to 2 chars (e.g. US, RU)
  [2..3]  MD5[0]    %02X
  [4]     MD5[1]>>4 %01X
  [5]     '-'
  [6]     MD5[1]&0F %01X
  [7]     MD5[2]>>4 %01X
  [8..]   encoded category counters  "%u|%u|%u|%u|%u|%u"
          with alphabet below, '-' inserted so groups of 5 (see GROUP),
          then pad with 'Y' to fill the last group.

wsprintfW format for the head: L"%s%02X%01X-%01X%01X"
  → e.g. US + 42 + 3 + '-' + 7 + E  =  "US423-7E"   (8 WCHARs)
Then encoder starts at index 8 with group_pos already = 2
  (because "7E" already occupy 2 slots of the current 5-char group).

Example (Any.RUN for this sample):
  US423-7EXZT-ZTZTR-OTRGT-XYYYY
  head = US423-7E
  stats decoded from the rest (ignoring '-' and trailing 'Y') = 10|0|0|23|27|1
"""
from __future__ import annotations

import hashlib
import re
import sys

# Digit / separator → display alphabet (sub_403C45 switch)
ENCODE = {
    "0": "Z",
    "1": "X",
    "2": "R",
    "3": "O",
    "4": "A",
    "5": "H",
    "6": "F",
    "7": "G",
    "8": "E",
    "9": "K",
    "|": "T",
}
DECODE = {v: k for k, v in ENCODE.items()}

GROUP = 5  # insert '-' when group_pos reaches 5
HEAD_LEN = 8  # after L"%s%02X%01X-%01X%01X"
HEAD_GROUP_POS = 2  # "7E"-style tail already consumed 2 of current group


def md5_head(payload: bytes) -> tuple[str, bytes]:
    digest = hashlib.md5(payload).digest()
    # same nibbles as CryptGetHashParam HP_HASHVAL into pbData/v16/v17
    b0, b1, b2 = digest[0], digest[1], digest[2]
    # country is caller-supplied; here we only rebuild the hex fragment
    frag = f"{b0:02X}{(b1 >> 4):01X}-{(b1 & 0xF):01X}{(b2 >> 4):01X}"
    return frag, digest


def encode_stats(counts: list[int], start_group_pos: int = HEAD_GROUP_POS) -> str:
    """Encode six category counters like the malware loop."""
    raw = "|".join(str(c) for c in counts)
    out: list[str] = []
    group_pos = start_group_pos
    for ch in raw:
        if group_pos == GROUP:
            out.append("-")
            group_pos = 0
        mapped = ENCODE.get(ch)
        if mapped is None:
            raise ValueError(f"unexpected char {ch!r} in stats")
        out.append(mapped)
        group_pos += 1
    # pad with 'Y' to complete the last 5-char group (memset32 0x00590059 + odd Y)
    while group_pos < GROUP:
        out.append("Y")
        group_pos += 1
    return "".join(out)


def build_id(country2: str, payload: bytes, counts: list[int]) -> str:
    if len(country2) != 2:
        raise ValueError("country must be 2 chars (malware forces LCData[2]=0)")
    if len(counts) != 6:
        raise ValueError("need 6 category counters")
    frag, _ = md5_head(payload)
    head = f"{country2}{frag}"  # length 8
    assert len(head) == HEAD_LEN
    return head + encode_stats(counts)


def decode_id(victim_id: str) -> dict:
    """Best-effort decode of an observed ID (stats + structural head)."""
    victim_id = victim_id.strip().upper()
    if len(victim_id) < HEAD_LEN:
        raise ValueError("ID too short")
    head = victim_id[:HEAD_LEN]
    country = head[:2]
    # head[2:8] = %02X%01X-%01X%01X
    m = re.fullmatch(r"([0-9A-F]{2})([0-9A-F])-([0-9A-F])([0-9A-F])", head[2:])
    if not m:
        raise ValueError(f"bad head {head!r}")
    md5_b0 = int(m.group(1), 16)
    md5_b1 = (int(m.group(2), 16) << 4) | int(m.group(3), 16)
    md5_b2_hi = int(m.group(4), 16)

    body = victim_id[HEAD_LEN:]
    letters = []
    for ch in body:
        if ch == "-":
            continue
        if ch == "Y":
            break
        if ch not in DECODE:
            raise ValueError(f"unknown alphabet {ch!r}")
        letters.append(DECODE[ch])
    stats = "".join(letters)
    counts = [int(x) for x in stats.split("|")] if stats else []
    return {
        "id": victim_id,
        "country": country,
        "md5_prefix": {"b0": md5_b0, "b1": md5_b1, "b2_hi_nibble": md5_b2_hi},
        "stats_raw": stats,
        "counts": counts,  # cat1..cat6 file counts at infection time
    }


def main(argv: list[str]) -> int:
    if len(argv) == 2 and argv[1] in {"-h", "--help"}:
        print(__doc__)
        print("Usage:")
        print(f"  {argv[0]} decode <ID>")
        print(f"  {argv[0]} demo   # rebuild Any.RUN-like example pieces")
        return 0
    if len(argv) == 3 and argv[1] == "decode":
        info = decode_id(argv[2])
        for k, v in info.items():
            print(f"{k}: {v}")
        return 0
    if len(argv) == 2 and argv[1] == "demo":
        # Reproduce structure of the Any.RUN ID for this sample (stats only;
        # MD5 head depends on full sub_403E11 payload, not reconstructed here).
        observed = "US423-7EXZT-ZTZTR-OTRGT-XYYYY"
        print("observed:", observed)
        print("decoded:", decode_id(observed))
        print("re-encode stats 10|0|0|23|27|1 →", encode_stats([10, 0, 0, 23, 27, 1]))
        print("full if head were US423-7E →", "US423-7E" + encode_stats([10, 0, 0, 23, 27, 1]))
        return 0
    print("try --help", file=sys.stderr)
    return 1


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
