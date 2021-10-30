; ..\LIB\ADPTIF.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CreateSocketPort PROTO :DWORD
DeleteSocketPort PROTO :DWORD
FwBindFwInterfaceToAdapter PROTO :DWORD,:DWORD
FwConnectionRequestFailed PROTO :DWORD
FwCreateInterface PROTO :DWORD,:DWORD,:DWORD
FwDeleteInterface PROTO :DWORD
FwDisableFwInterface PROTO :DWORD
FwEnableFwInterface PROTO :DWORD
FwGetInterface PROTO :DWORD,:DWORD,:DWORD
FwGetNotificationResult PROTO :DWORD,:DWORD
FwGetStaticNetbiosNames PROTO :DWORD,:DWORD,:DWORD
FwNotifyConnectionRequest PROTO :DWORD,:DWORD,:DWORD
FwSetInterface PROTO :DWORD,:DWORD
FwSetStaticNetbiosNames PROTO :DWORD,:DWORD,:DWORD
FwStart PROTO :DWORD,:DWORD
FwStop PROTO
FwUnbindFwInterfaceFromAdapter PROTO :DWORD
FwUpdateRouteTable PROTO :DWORD,:DWORD,:DWORD
GetFilters PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxAdjustIoCompletionParams PROTO :DWORD,:DWORD,:DWORD
IpxCreateAdapterConfigurationPort PROTO :DWORD,:DWORD
IpxDeleteAdapterConfigurationPort PROTO :DWORD
IpxGetOverlappedResult PROTO :DWORD,:DWORD,:DWORD,:DWORD
IpxGetQueuedAdapterConfigurationStatus PROTO :DWORD,:DWORD,:DWORD,:DWORD
IpxGetQueuedCompletionStatus PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxPostQueuedCompletionStatus PROTO :DWORD,:DWORD,:DWORD,:DWORD
IpxRecvPacket PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxSendPacket PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxWanCreateAdapterConfigurationPort PROTO :DWORD,:DWORD
IpxWanQueryInactivityTimer PROTO :DWORD,:DWORD,:DWORD
IpxWanSetAdapterConfiguration PROTO :DWORD,:DWORD
ServiceHandler PROTO :DWORD,:DWORD
ServiceMain PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetFilters PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

