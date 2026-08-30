#!/usr/bin/env python3
"""From decrypted Stage-3 PE: XOR-D6 bootstrap at .data+0x260 → zlib ransomware."""
from pathlib import Path
import struct, base64, zlib, hashlib, argparse, re

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('stage3_pe')
    ap.add_argument('--key', type=lambda x: int(x,0), default=0xD6)
    args = ap.parse_args()
    blob = Path(args.stage3_pe).read_bytes()
    e = struct.unpack_from('<I', blob, 0x3C)[0]
    nsec = struct.unpack_from('<H', blob, e+6)[0]
    opt = struct.unpack_from('<H', blob, e+20)[0]
    soff = e+24+opt
    data_raw = None
    for _ in range(nsec):
        name = blob[soff:soff+8].split(b'\0',1)[0].decode()
        vsize,va,rsize,raw = struct.unpack_from('<IIII', blob, soff+8)
        if name == '.data':
            data_raw = raw
        soff += 40
    start = data_raw + 0x260
    dec = bytes(b ^ args.key for b in blob[start:])
    # trim to bootstrap
    text = dec.decode('latin1')
    marker = "v_b1db612b = '"
    a = text.find(marker) + len(marker)
    b = text.find("'\n", a)
    b64 = text[a:b]
    payload = zlib.decompress(base64.b64decode(b64))
    Path('sys_service_payload.py').write_bytes(payload)
    print('payload', len(payload), hashlib.sha256(payload).hexdigest())

if __name__ == '__main__':
    main()
