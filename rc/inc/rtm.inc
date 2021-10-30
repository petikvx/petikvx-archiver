; ..\LIB\RTM.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~

RtmAddRoute PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtmBlockConvertRoutesToStatic PROTO :DWORD,:DWORD,:DWORD
RtmBlockDeleteRoutes PROTO :DWORD,:DWORD,:DWORD
RtmBlockSetRouteEnable PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtmCloseEnumerationHandle PROTO :DWORD
RtmCreateEnumerationHandle PROTO :DWORD,:DWORD,:DWORD
RtmCreateRouteTable PROTO :DWORD,:DWORD
RtmDeleteRoute PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtmDeleteRouteTable PROTO :DWORD
RtmDequeueRouteChangeMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtmDeregisterClient PROTO :DWORD
RtmEnumerateGetNextRoute PROTO :DWORD,:DWORD
RtmGetFirstRoute PROTO :DWORD,:DWORD,:DWORD
RtmGetNetworkCount PROTO :DWORD
RtmGetNextRoute PROTO :DWORD,:DWORD,:DWORD
RtmGetRouteAge PROTO :DWORD
RtmIsRoute PROTO :DWORD,:DWORD,:DWORD
RtmRegisterClient PROTO :DWORD,:DWORD,:DWORD,:DWORD

