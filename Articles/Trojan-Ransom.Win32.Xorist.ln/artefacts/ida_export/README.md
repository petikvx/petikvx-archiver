# IDA batch export (Xorist.ln unpacked)

Generated with:

```bash
export TVHEADLESS=1
IDA=~/ida-pro-9.4
SAMPLE="…-unpacked.exe.i64"   # or the .exe
OUT=artefacts/ida_export
"$IDA/idat" -A \
  "-S$IDA/scripts/export_asm_c.py --outdir $OUT --prefix xorist_ln_unpacked" \
  "$SAMPLE"
```

| File | Role |
|------|------|
| `xorist_ln_unpacked.c` | Hex-Rays all functions |
| `xorist_ln_unpacked.asm` | ASM listing |
| `xorist_ln_unpacked.lst` | Disassembly listing |

See `Articles/AGENTS.md` §2 for the reusable workflow.
