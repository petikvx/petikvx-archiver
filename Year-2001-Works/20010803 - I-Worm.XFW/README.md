# I-Worm.XFW (Extra French Worm) — Technical Analysis (2001)

> Research/education only. This document describes historical malware behavior to aid defenders and archivists. It avoids operational details and redacts hateful strings contained in the original sample.

## Overview

I‑Worm.XFW is a Win9x/WinME/Win2000‑era worm written in 32‑bit assembly (TASM/MASM style) and UPX‑packed in release. It installs itself as `Services.exe` in the Windows System directory, abuses `WIN.INI` persistence, tampers with `WSOCK32.DLL`, self‑replicates across DLL filenames (double‑extension trick), and, when online, drops a VBScript that mass‑mails itself using the Outlook Object Model. A conditional, destructive payload writes a batch file that will wipe the primary drive if the user’s Internet Explorer homepage matches any of several extremist/hate group URLs (redacted below).

Source file: `XFW.asm` (includes `useful.inc` macros)

Approximate timeline: July 10 – August 3, 2001 (per header comments).

## Installation and persistence

- Copy/rename
  - On first run, the worm builds `%WinDir%\System\Services.exe` and copies itself there using `CopyFileA`.
  - On subsequent runs from that path, it switches to “infection” mode (see below).

- WIN.INI autorun (Win9x/ME)
  - Constructs `%WinDir%\WIN.INI` and writes under section `windows`, key `run`, value set to the full path of `Services.exe` via `WritePrivateProfileStringA`.
  - This targets legacy Win9x/ME startup processing. There is no active Run/RunServices registry write in the provided code, despite the comment header claiming “Run Services.”

## Tampering with WSOCK32.DLL

- Backup and patch
  - Resolves `%System%\Wsock32.dll` and creates a backup copy as `%System%\Wsock32.ptk` (fail if exists).
  - Opens the original DLL for read/write mapping and writes the marker string “PetiK” at file offset 0x12 (DOS header area). If already present, it skips.
  - Risks: corrupting `Wsock32.dll` can destabilize or break Winsock on Win9x systems. The sample also drops a help file to instruct restoration (see artifacts).

## Opportunistic spread in System directory (double‑extension)

- When the process is already `%System%\Services.exe`, it iterates `*.dll` files in the current directory (which is expected to be the System directory) and, for each, creates a copy of the worm named like `filename.dll.exe`.
- This “DLL name plus .exe” double‑extension is meant to trick users via familiar DLL basenames appearing as executables.

## Conditional destructive payload (homepage check)

- Reads IE start page from `HKCU\Software\Microsoft\Internet Explorer\Main\Start Page`.
- If the homepage exactly matches any of a hard‑coded set of extremist/hate sites (redacted), it writes a batch file to `C:\Autoexec.bat` that, on next boot, performs a full format of the C: drive without prompting.
- Notes:
  - The batch contents include profanity; this is omitted here.
  - This payload is only triggered on exact string matches of the homepage value.

## Network/Connectivity check

- Dynamically loads `WININET.DLL` and resolves `InternetCheckConnectionA`.
- Loops until the call returns a non‑zero result (i.e., online), then frees the library and shows a message box titled “Internet” with text “You’re connected”.

## Outlook mass‑mail (VBScript dropper)

- Drops `C:\Win.vbs` and executes it via `wscript`:
  - Creates an Outlook Application object.
  - Iterates all address lists and address entries.
  - Creates a mail item per entry, with subject “Xtra game for you” and a short body.
  - Attaches `%System%\Services.exe` using FileSystemObject’s `BuildPath(GetSpecialFolder(1), "Services.exe")` (SpecialFolder 1 = System folder).
  - Sends the message and marks it for deletion after submit.
- Cleanup bug: The native code attempts to delete `C:\Win.vbs` after a delay but calls `DeleteFileA` with an extra push intended for `Sleep`, leaving a stray value on the stack and no actual wait. Deletion still occurs immediately (if the script has already exited) or may fail while the script is running.

## Artifacts and IOCs

Files and paths (Win9x/WinME/Win2000‑era):
- `%WinDir%\System\Services.exe` (main copy)
- `%WinDir%\System\Wsock32.dll` (modified in‑place; marker “PetiK” at file offset 0x12)
- `%WinDir%\System\Wsock32.ptk` (backup of original)
- `%WinDir%\Tool_PetiK.txt` (restoration instructions)
- `%WinDir%\WIN.INI` modified: `[windows]` `run=<path-to-Services.exe>`
- `%System%\*.dll.exe` (copies of the worm using DLL basename + “.exe”)
- `C:\Win.vbs` (temporary Outlook mass‑mailer)
- `C:\Autoexec.bat` (only if destructive payload condition met; contains a drive‑wipe command)

Registry:
- Reads (but does not set): `HKCU\Software\Microsoft\Internet Explorer\Main\Start Page`

User‑visible text:
- MessageBox: title “Loader Error”; text “This program will be terminated” (shown after DLL tamper sequence)
- MessageBox: title “Internet”; text “You’re connected”

Network/Email:
- Sends email via Outlook OOM to all address book entries; subject “Xtra game for you”; attachment `Services.exe` from System folder. No raw SMTP beacons.

## Code quirks and engineering notes

- The header comment claims a “Run Services” registry value, but the provided code does not write one; persistence relies on `WIN.INI` only.
- The double‑extension builder appends `.exe` to each DLL filename in the System folder. The string logic writes a 4‑byte token for `"EXE."`; on Win9x FAT filesystems, a trailing dot is usually normalized away by the OS, but the result remains an executable with a convincing DLL‑based name.
- `WSOCK32.DLL` is patched at raw offset 0x12; this is within the DOS header and unlikely to affect PE loader logic but is a crude “signature.”
- The VBS cleanup intends a 30‑second delay before deletion but pushes the delay as an argument to `DeleteFileA` instead of calling `Sleep`, slightly corrupting the stack (non‑fatal before `ExitProcess`).
- Uses `useful.inc` macros heavily for string pushing and concatenation; see annex.

## Annex — USEFUL.INC macros seen here

- `@pushsz "..."` — Pushes the address of a null‑terminated string literal onto the stack (macro allocates the bytes inline and ensures trailing `\0`). Used to build API arguments without separately allocating buffers.
- `@pushbytes ...` / `@endsz` — Not used here explicitly, but commonly pair with `@pushsz` in this codebase to compose inline data.
- `@copysz dst, src` — Not present here; general macro to copy string literals or buffers.
- Pattern: stdcall argument order is expressed by a series of `push` instructions (last push is first parameter), then `callx ApiName` resolves and calls the imported procedure declared with `extrn`.

## Defensive guidance (historical context)

- Win9x/ME startup hygiene: Inspect `%WinDir%\WIN.INI` for unexpected entries under `[windows]` `run=` and remove suspicious paths.
- File integrity: Check `%System%\Wsock32.dll` for tampering. If `%System%\Wsock32.ptk` exists, restore the original DLL by replacing the modified one with the backup (or from trusted installation media).
- Outlook OOM: Use modern protections that restrict COM automation of Outlook and disable or restrict Windows Script Host where not needed.
- Email hygiene: Block executable attachments at the mail gateway; quarantine double‑extension names like `*.dll.exe`.
- Endpoint controls: Application allow‑listing and limited user privileges mitigate writes to system directories on NT‑based systems.
- Back up data: The sample contains a conditional, destructive routine; maintain offline backups and verify restore procedures.

## Manual removal (from the sample’s own header, adapted)

Proceed on an offline copy or with recovery media available:
- Delete `%WinDir%\System\Wsock32.dll` (only if you’re about to restore it).
- Rename `%WinDir%\System\Wsock32.ptk` back to `%WinDir%\System\Wsock32.dll`.
- Delete `%WinDir%\System\Services.exe` and any suspicious `*.dll.exe` in the System directory.
- Remove the `run=` value that references `Services.exe` in `%WinDir%\WIN.INI` under `[windows]`.
- Remove `C:\Win.vbs` if present.
- If `C:\Autoexec.bat` was created by the payload, replace it with a safe default or remove malicious lines; do not reboot until cleaned.

## Credits and metadata

- Author string in binary: “I‑Worm.XFW coded by PetiK (c)2001” / “Made in France”.
- Assembler toolchain from comments: `tasm32`, `tlink32`, optional `upx` packing.

---

This analysis was produced from `XFW.asm` within the PetiK archive and focuses on defender‑relevant behavior, IOCs, and quirks. If you want, I can normalize IOC blocks across the other 2001 write‑ups for consistency.
