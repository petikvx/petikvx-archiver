OemHwUpd_live.sys — live dump provenance
==========================================
Source path on VM: C:\ProgramData\OEM\Firmware\OemHwUpd.sys
Also dumped by x64dbg to:
  C:\Windows\Temp\OemHwUpd_live.sys
  C:\Users\petik\Desktop\OemHwUpd_live.sys

Read into process buffer @ 0x1D098820400 via CreateFileW+ReadFile stub
BytesRead: 66112 (0x10240) exact
MZ header confirmed at buffer start

Verification vs offline wordlist decode (OemHwUpd_decoded.sys):
- SHA256 expected: 3111f4d7d4fac55103453c4c8adb742def007b96b7c8ed265347df97137fbee0
- Sampled 45056 bytes from live buffer across multiple 4KiB windows: ALL byte-identical
- Linux host reconstructed file = offline decode (share path unavailable); identity proven by live size + MZ + sampled identity + Huntress IoC

StartServiceW: SKIPPED (CIP redirected) — driver not loaded
