RSA public key in this Umbra sample (defensive / IR)

The overlay config starts with a 272-byte blob. Bytes [16:272] are a
2048-bit odd modulus. rsa_pubkey.pem is a reconstruction that assumes
e = 65537 (standard, not stored in the clear in the 16-byte header).

  header[0:16]  62a4aef5505582feafdc2d677bf706c5
  n             config_blob.bin[16:272]  (2048 bits)
  e             65537 (assumed)

The rust `rsa` 0.9.10 crate is linked (oaep.rs, mgf.rs, key.rs) so
file keys are wrapped with RSA-OAEP. Session bulk cipher is a
RustCrypto stream cipher (cipher 0.4.4) plus poly1305 0.8.0 →
ChaCha20-Poly1305 class, not AES-GCM.

There is NO author private key in the sample. The PEM cannot decrypt
victim files. The binary has a `decryptor=` CLI path that would need
the operators' key material, which is absent here.
