; ..\LIB\MSWSOCK.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

AcceptEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumProtocolsA PROTO :DWORD,:DWORD,:DWORD
EnumProtocols equ <EnumProtocolsA>

GetAcceptExSockaddrs PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAddressByNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAddressByName equ <GetAddressByNameA>

GetNameByTypeA PROTO :DWORD,:DWORD,:DWORD
GetNameByType equ <GetNameByTypeA>

GetServiceA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetService equ <GetServiceA>

GetTypeByNameA PROTO :DWORD,:DWORD
GetTypeByName equ <GetTypeByNameA>

MigrateWinsockConfiguration PROTO :DWORD,:DWORD,:DWORD
NPLoadNameSpaces PROTO :DWORD,:DWORD,:DWORD
SetServiceA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetService equ <SetServiceA>

TransmitFile PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WSARecvEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
dn_expand PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
getnetbyname PROTO :DWORD
inet_network PROTO :DWORD
rcmd PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
rexec PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
rresvport PROTO :DWORD
s_perror PROTO :DWORD,:DWORD
sethostname PROTO :DWORD,:DWORD

