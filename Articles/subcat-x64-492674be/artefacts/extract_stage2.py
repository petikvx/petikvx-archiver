#!/usr/bin/env python3
"""Extract + decrypt the embedded stage-2 PE of subcat-x64-Windows-MSVC.bin.

Defensive/IR use only. The loader's own decrypt routine (sub_140069F50) is
run inside a Unicorn CPU emulator on a mapped copy of the file: nothing of the
sample is executed natively. Layout (from sub_14006C500):
    key     = .data+0x000  (0x80 bytes)          VA 0x140070000
    payload = .data+0x100  (0x3B400 bytes)       VA 0x140070100
    cipher  = sub_140069F50(buf, size, key, 0x80)  (custom stream cipher)
Usage: python -I extract_stage2.py <sample.bin> <out_stage2.bin>
Needs: pip install unicorn
"""
import struct, sys, hashlib
from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UC_PROT_ALL
from unicorn.x86_const import UC_X86_REG_RSP, UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8, UC_X86_REG_R9, UC_X86_REG_RIP

BASE = 0x140000000
FUNC = 0x140069F50
KEY_VA, PAY_VA, PAY_SZ, KEY_SZ = 0x140070000, 0x140070100, 0x3B400, 0x80

d = open(sys.argv[1], 'rb').read()
e = struct.unpack_from('<I', d, 0x3c)[0]
ns = struct.unpack_from('<H', d, e + 6)[0]
osz = struct.unpack_from('<H', d, e + 0x14)[0]
sec = e + 0x18 + osz

mu = Uc(UC_ARCH_X86, UC_MODE_64)
mu.mem_map(BASE, 0x100000 + 0x1000, UC_PROT_ALL)
mu.mem_write(BASE, d[:0x400])
for i in range(ns):
    s = sec + i * 40
    vs, va, rs, rp = struct.unpack_from('<IIII', d, s + 8)
    mu.mem_write(BASE + va, d[rp:rp + rs])

BUF, STACK, RET = 0x20000000, 0x30000000, 0x40000000
mu.mem_map(BUF, 0x40000, UC_PROT_ALL)
mu.mem_map(STACK, 0x20000, UC_PROT_ALL)
mu.mem_map(RET, 0x1000, UC_PROT_ALL)
mu.mem_write(RET, b'\xf4')
mu.mem_write(BUF, bytes(mu.mem_read(PAY_VA, PAY_SZ)))
sp = STACK + 0x10000
mu.mem_write(sp, struct.pack('<Q', RET))
mu.reg_write(UC_X86_REG_RSP, sp)
mu.reg_write(UC_X86_REG_RCX, BUF)
mu.reg_write(UC_X86_REG_RDX, PAY_SZ)
mu.reg_write(UC_X86_REG_R8, KEY_VA)
mu.reg_write(UC_X86_REG_R9, KEY_SZ)
mu.emu_start(FUNC, RET, count=0)
out = bytes(mu.mem_read(BUF, PAY_SZ))
open(sys.argv[2], 'wb').write(out)
print('MZ' if out[:2] == b'MZ' else 'NOT-MZ', out[:16].hex(), len(out))
print('sha256', hashlib.sha256(out).hexdigest())
