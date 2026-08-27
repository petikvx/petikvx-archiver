# Stage-2 live dump notes

Source: x64dbg ReadMemory while paused after unpacker return (VA workspace `0x1F00000`).

## Layout (approximate)

| Offset in buffer | Content |
|------------------|---------|
| `+0x00` | PNG magic camouflage |
| `+0x118` | PE64 headers (Machine `0x8664`, Magic `0x20B`) |
| `+0x220` | Section table: `.text` `.rdata` `.data` `.pdata` `.gfids` `.reloc` |
| `+0x400+` | Code (opaque predicates) |
| `+0x1000+` | More code incl. ROR13 hash loop |
| `+0x5B0` | `gs:[0x60]` PEB helper |
| `+0x3C4C` area | `cmp ..., 'MZ'` / PNG / `PE` checks (infection) |

## Registers at VirtualAlloc

| Reg | Value | Meaning |
|-----|-------|---------|
| RCX | 0 | lpAddress |
| RDX | `0xB7A26` | size = blob2×3 |
| R8 | `0x3000` | MEM_COMMIT\|RESERVE |
| R9 | 4 | PAGE_READWRITE |
| RDI | `0x3D362` | blob2 size |
| R14 | `0x140E75400` | body base |
| R15 | `0x4A1A4` → `0x140EBF5A4` | blob2 VA |

Full buffer also dumped on Windows Desktop as `moiva_stage2_buf.bin` / `moiva_layer2_unpacked.bin` (copy into `artefacts/` if needed).
