config_dec.bin [0:128] : 96 bytes of key material + 32 zero bytes.
Used as RSA-1024-sized slot (LockBit 3 wrap) / session material.

First 8 bytes (hex) feed the "DECRYPTION ID" printer (sub_406EAC, %02X x8)
plus 8 random bytes (rdrand/rdtsc LCG).

No author private key is in the sample. This material cannot decrypt victim files.

seed / PRNG (VA 0x426000, file 0x22E00):
  d4 db b3 e6 c3 ac 24 0b
