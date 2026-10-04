RURansom crypto (this build) — wiper, keys not stored

Primitive
  RijndaelManaged, KeySize=256, BlockSize=128, CipherMode.CBC
  PKCS7 padding (default)
  Key/IV from Rfc2898DeriveBytes (PBKDF2-HMAC-SHA1)

PBKDF2
  password = UTF-8 of getEncryptedAesKey()[0]
           = Base64(UTF-8(BuildPassword("FullScaleCyberInvasion + " + MachineName)))
  salt     = 8 bytes 36 17 02 35 17 2A 01 05  (artefacts/salt.bin)
  iterations = 512
  Key = 32 bytes, IV = 16 bytes

BuildPassword(str)
  System.Random (TickCount LCG), length-preserving pick-with-replacement
  NOT a KDF. New Random() on every call.

getEncryptedAesKey()
  pw1 = BuildPassword("FullScaleCyberInvasion + " + MachineName)
  pw2 = BuildPassword("RU_Ransom" + UserName + "2022")
  wrapped = AES_Encrypt(UTF8(pw1), UTF8(pw2))
  returns [b64(pw1), b64(pw2), b64(wrapped)]
  wrapped is NEVER written to disk (local var text3 unused)

EncryptFile bugs (this sample)
  1. getEncryptedAesKey() is called THREE times per file (independent RNG)
  2. return [1] assigned to text2 and unused
  3. Path.ChangeExtension(file, ".fs_invade") result discarded — no rename
  4. File.ReadAllText — binary / non-text often throws and is skipped (empty catch)
  5. ciphertext written in-place as Base64 text (original overwritten)

Recovery
  No private key, no RSA wrap, no footer, no per-file key file.
  IR recovery = backups / shadow copies if they still exist (this build does not call vssadmin).
