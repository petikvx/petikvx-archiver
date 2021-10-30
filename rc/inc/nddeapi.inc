; ..\LIB\NDDEAPI.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

NDdeGetErrorStringA PROTO :DWORD,:DWORD,:DWORD
NDdeGetErrorString equ <NDdeGetErrorStringA>

NDdeGetShareSecurityA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeGetShareSecurity equ <NDdeGetShareSecurityA>

NDdeGetTrustedShareA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeGetTrustedShare equ <NDdeGetTrustedShareA>

NDdeIsValidAppTopicListA PROTO :DWORD
NDdeIsValidAppTopicList equ <NDdeIsValidAppTopicListA>

NDdeIsValidShareNameA PROTO :DWORD
NDdeIsValidShareName equ <NDdeIsValidShareNameA>

NDdeSetShareSecurityA PROTO :DWORD,:DWORD,:DWORD,:DWORD
NDdeSetShareSecurity equ <NDdeSetShareSecurityA>

NDdeSetTrustedShareA PROTO :DWORD,:DWORD,:DWORD
NDdeSetTrustedShare equ <NDdeSetTrustedShareA>

NDdeShareAddA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeShareAdd equ <NDdeShareAddA>

NDdeShareDelA PROTO :DWORD,:DWORD,:DWORD
NDdeShareDel equ <NDdeShareDelA>

NDdeShareEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeShareEnum equ <NDdeShareEnumA>

NDdeShareGetInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeShareGetInfo equ <NDdeShareGetInfoA>

NDdeShareSetInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeShareSetInfo equ <NDdeShareSetInfoA>

NDdeSpecialCommandA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeSpecialCommand equ <NDdeSpecialCommandA>

NDdeTrustedShareEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeTrustedShareEnum equ <NDdeTrustedShareEnumA>


