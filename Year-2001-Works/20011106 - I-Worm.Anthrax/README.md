# I‑Worm.Anthrax (aka: I‑Worm.Fi) — Defensive analysis and archival

## Warning and ethics

- This repository contains malicious code for historical/educational analysis. Never deploy it on production systems or on a networked machine.
- Follow applicable laws and your organization’s policies. Offensive use is prohibited.
- The information below supports understanding and defense (IOCs, cleanup), not reproduction.

## Background

- Name: I‑Worm.Anthrax (aka: I‑Worm.Fi)
- Author: “PetiK” (noted in the source header)
- Period: October–November 2001
- Language: Win32 x86 assembly (TASM/WinAPI)
- Reported size (UPX‑packed binary): ~6,144 bytes (from source header)

## High‑level technical overview

- Target platforms: Windows 9x/ME/NT/2000 (uses Win32 APIs, WAB/MAPI, SoftICE detection, etc.).
- Persistence:
  - Self‑copy to `%SystemDirectory%\MsSys32.exe` (e.g., `C:\Windows\System\MsSys32.exe`).
  - Startup key: `HKLM\Software\Microsoft\Windows\CurrentVersion\Run` with value:
    - Name: `Microsoft System`
    - Data: path to `MsSys32.exe`.
- Anti‑analysis / anti‑debug:
  - Checks for a debugger (`IsDebuggerPresent`).
  - Attempts to open SoftICE drivers: `\\.\SICE` (Win9x) and `\\.\NTICE` (NT/2000).
  - “Kill switch” behavior if a debugger is detected.
- User decoy:
  - Displays a MessageBox “Microsoft Windows: You must be connected to run this file…” to mask activity.
- Desktop/disk artefact:
  - Creates `Anthrax_Info.url` pointing to `http://www.anthrax.com` on the Desktop when possible, otherwise `C:\` root.
  - Icon borrowed from `Shell32.dll` (index 23).

### mIRC propagation

- Attempts to write `script.ini` into common locations:
  - `C:\mirc\script.ini`
  - `C:\mirc32\script.ini`
  - `C:\progra~1\mirc\script.ini`
  - `C:\progra~1\mirc32\script.ini`
- The script triggers on `JOIN` and DCC‑sends `MsSys32.exe` to the newcomer.

### Email propagation (via WAB/MAPI)

- Verifies connectivity with `InternetGetConnectedState`.
- Retrieves the Windows Address Book (WAB) path from: `Software\Microsoft\Wab\WAB4\Wab File Name` (queried under HKCU in the code).
- Memory‑maps the WAB and scans for a “SMTP” signature to extract addresses.
- Sends up to 10 emails via MAPI with:
  - Subject: `What is the anthrax ?`
  - Body: `I send you some informations about Anthrax.` + `Click on the attached file.`
  - Spoofed sender: `support@microsoft.com`
  - Attachment: a copy of the worm named `Anthrax_Info.exe`.
- Author’s note (from header): “The worm bugs at the end of it spread WAB” (possible instability at the end of WAB routine).

## Indicators of Compromise (IOCs)

- Files:
  - `%SystemDirectory%\MsSys32.exe`
  - `Anthrax_Info.url` on Desktop or `C:\`
  - `script.ini` created/modified in the mIRC directories above (contains an `on JOIN` handler and a `.dcc send` of the binary)
- Registry:
  - `HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Microsoft System = <path to MsSys32.exe>`
- Notable strings/artefacts (in binary/source):
  - `I‑Worm.Anthrax`, `Coded by PetiK - 2001`
  - Driver names: `\\.\SICE`, `\\.\NTICE`
  - MAPI usage and email lure (subject/body above), attachment `Anthrax_Info.exe`, sender `support@microsoft.com`
- Network/URL:
  - `http://www.anthrax.com` written into `Anthrax_Info.url`.

## Defensive cleanup and remediation

1. Isolate the machine from the network to prevent further spread.
2. Stop the malicious process if running:
   - Identify a process associated with `MsSys32.exe` and terminate it (carefully; preferably from an isolated recovery context).
3. Remove artefacts:
   - File: `MsSys32.exe` in `%SystemDirectory%` (Safe Mode may help).
   - URL file: `Anthrax_Info.url` (Desktop or `C:\`).
   - mIRC: inspect and clean/remove injected sections in `script.ini` or restore a clean backup.
4. Registry cleanup:
   - Delete `Microsoft System` under `HKLM\Software\Microsoft\Windows\CurrentVersion\Run`.
5. System scanning:
   - Run up‑to‑date AV/EDR and antimalware scanners to validate full eradication.
6. Reboot and re‑check the IOCs above.

> Note: The source header mentions a `Delete_Fi.vbs` removal script. Prefer controlled, manual remediation you can verify over running untrusted scripts.

## Lab safety for researchers

- Analyze `Anthrax.asm` only in an isolated VM with no bridged networking and with snapshots.
- Avoid executing the binary; static analysis (reading source/strings) is sufficient for archival.
- Keep read‑only copies of samples and document any changes.