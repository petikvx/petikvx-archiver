; ..\LIB\DPLAYX.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DirectPlayCreate PROTO :DWORD,:DWORD,:DWORD
DirectPlayEnumerateA PROTO :DWORD,:DWORD
DirectPlayEnumerate equ <DirectPlayEnumerateA>

DirectPlayLobbyCreateA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DirectPlayLobbyCreate equ <DirectPlayLobbyCreateA>


