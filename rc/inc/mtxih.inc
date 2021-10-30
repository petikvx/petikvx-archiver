; ..\LIB\MTXIH.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~

NdrClearOutParameters PROTO :DWORD,:DWORD,:DWORD
NdrDllGetClassObject PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrDllRegisterProxy PROTO :DWORD,:DWORD,:DWORD
NdrDllUnregisterProxy PROTO :DWORD,:DWORD,:DWORD
NdrStubForwardingFunction PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcStringFreeA PROTO :DWORD
RpcStringFree equ <RpcStringFreeA>

UuidFromStringA PROTO :DWORD,:DWORD
UuidFromString equ <UuidFromStringA>

UuidToStringA PROTO :DWORD,:DWORD
UuidToString equ <UuidToStringA>


