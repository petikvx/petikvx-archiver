; ..\LIB\DSETUP.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DirectXDeviceDriverSetupA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DirectXDeviceDriverSetup equ <DirectXDeviceDriverSetupA>

DirectXLoadString PROTO :DWORD,:DWORD,:DWORD
DirectXRegisterApplicationA PROTO :DWORD,:DWORD
DirectXRegisterApplication equ <DirectXRegisterApplicationA>

DirectXSetupA PROTO :DWORD,:DWORD,:DWORD
DirectXSetup equ <DirectXSetupA>

DirectXSetupCallback PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DirectXSetupGetVersion PROTO :DWORD,:DWORD
DirectXSetupIsJapan PROTO
DirectXSetupIsJapanNec PROTO
DirectXSetupSetCallback PROTO :DWORD
DirectXUnRegisterApplication PROTO :DWORD,:DWORD

