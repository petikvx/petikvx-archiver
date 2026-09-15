KerRansom crypto (defensive notes)

- Primitive: AES-256-CBC, PKCS7, .NET Aes.Create()
- Key: 32 random bytes (RNGCryptoServiceProvider) per run — same key for ALL files
- IV: 16 random bytes, same for ALL files (not unique per file)
- No RSA / ECC wrap
- No footer / magic on ciphertext: the whole original file is replaced by AES ciphertext
- Rename: original deleted, ciphertext written as originalPath + ".ker"
- Full-file encrypt (ReadAllBytes / TransformFinalBlock) — no partial policy

IR: the AES key+IV are stored in plaintext Base64 inside:
  %AppData%\.cache_<xxxxxxxx>\dec.cs
  %AppData%\.cache_<xxxxxxxx>\dec.ps1

There is NO author private key in the sample: recovery depends on those dropped files
and on list.dat, and on NOT rebooting (wipe.bat on RunOnce/Startup).
