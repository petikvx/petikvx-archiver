RSA-2048 public key (authors) — defensive extraction

Source: Base64 Microsoft PUBLICKEYBLOB at VA ~0x140014190 (aBgiaaackaabsu0)
Loaded via CryptStringToBinaryA(CRYPT_STRING_BASE64) + CryptImportKey in sub_1400086F0.

Files:
- rsa_pubkey_b64.txt — raw Base64 as in binary
- rsa_pubkey_msblob.bin — decoded PUBLICKEYBLOB (276 bytes)
- rsa_pubkey.pem / rsa_pubkey.der — SubjectPublicKeyInfo

SHA256(DER)=9f68d527e2bc4955bbc803e128d7fb95b136d5ebfb37e8928d176f361122d858
bitlen=2048 e=65537

Private key slot byte_1400143B0 is empty/zeros in this sample → no author private key.
Pubkey alone cannot decrypt victim files.
