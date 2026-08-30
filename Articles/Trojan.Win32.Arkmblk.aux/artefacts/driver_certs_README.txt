Authenticode certificates — OemHwUpd_decoded.sys / EnPortv.sys
======================================================================

LEAF (signer) — Guidance Software, Inc.
  Subject: CN=Guidance Software\, Inc.,OU=Development,OU=Digital ID Class 3 - Microsoft Software Validation v2,O=Guidance Software\, Inc.,L=Pasadena,ST=California,C=US
  Issuer:  CN=VeriSign Class 3 Code Signing 2004 CA,OU=Terms of use at https://www.verisign.com/rpa (c)04,OU=VeriSign Trust Network,O=VeriSign\, Inc.,C=US
  Serial:  4f97f8f029bb92115e173ac1b62a8193
  Valid:   2006-12-15 00:00:00+00:00 -> 2010-01-31 23:59:59+00:00
  SHA1:    5c8561da9b14914806c8ee8595fdec811210198d
  SHA256:  2c51210219e06e446fac1cd3ab147d8efccb51e9daafdc9b4123c923ec6be977
  File:    driver_cert_4.pem

Also in PKCS#7: VeriSign timestamping + Class 3 CS 2004 +
Microsoft Code Verification Root cross-cert (driver_cert_0..3.pem).

IR: expired 2010-01-31 but often still loadable if timestamped
(pre-2015 cross-sign exception) unless VDB / HVCI / WDAC blocks the hash.
