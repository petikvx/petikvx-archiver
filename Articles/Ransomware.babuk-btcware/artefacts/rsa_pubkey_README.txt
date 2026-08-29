RSA-4096 public key embedded as Microsoft PUBLICKEYBLOB (CALG_RSA_KEYX).
File offset: 0x249F0 (VA 0x1400263F0 approx — label pbData)
Bitlen: 4096, exponent: 65537
PEM: artefacts/rsa_pubkey.pem
Used by CryptImportKey + CryptEncrypt to wrap the per-host Curve25519 private key
(session init sub_140016470). Without the authors' private RSA key, victims cannot
unwrap the session material — pubkey alone is not enough to decrypt.
