; ..\LIB\WINTRUST.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

OssX509SpcIndirectDataContentDecode PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OssX509SpcIndirectDataContentEncode PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WinLoadTrustProvider PROTO :DWORD
WinSubmitCertificate PROTO :DWORD
WinTrustProviderClientInitialize PROTO :DWORD,:DWORD,:DWORD,:DWORD
WinVerifyTrust PROTO :DWORD,:DWORD,:DWORD

