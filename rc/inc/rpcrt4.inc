; ..\LIB\RPCRT4.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CStdStubBuffer_AddRef PROTO :DWORD
CStdStubBuffer_Connect PROTO :DWORD,:DWORD
CStdStubBuffer_CountRefs PROTO :DWORD
CStdStubBuffer_DebugServerQueryInterface PROTO :DWORD,:DWORD
CStdStubBuffer_DebugServerRelease PROTO :DWORD,:DWORD
CStdStubBuffer_Disconnect PROTO :DWORD
CStdStubBuffer_Invoke PROTO :DWORD,:DWORD,:DWORD
CStdStubBuffer_IsIIDSupported PROTO :DWORD,:DWORD
CStdStubBuffer_QueryInterface PROTO :DWORD,:DWORD,:DWORD
DceErrorInqTextA PROTO :DWORD,:DWORD
DceErrorInqText equ <DceErrorInqTextA>

GlobalMutexClear PROTO
GlobalMutexRequest PROTO
IUnknown_AddRef_Proxy PROTO :DWORD
IUnknown_QueryInterface_Proxy PROTO :DWORD,:DWORD,:DWORD
IUnknown_Release_Proxy PROTO :DWORD
I_RpcAbortAsyncCall PROTO :DWORD,:DWORD
I_RpcAllocate PROTO :DWORD
I_RpcAsyncAbortCall PROTO :DWORD,:DWORD
I_RpcAsyncSendReceive PROTO :DWORD,:DWORD,:DWORD
I_RpcAsyncSetHandle PROTO :DWORD,:DWORD
I_RpcBindingCopy PROTO :DWORD,:DWORD
I_RpcBindingInqDynamicEndpointA PROTO :DWORD,:DWORD
I_RpcBindingInqDynamicEndpoint equ <I_RpcBindingInqDynamicEndpointA>

I_RpcBindingInqTransportType PROTO :DWORD,:DWORD
I_RpcBindingIsClientLocal PROTO :DWORD,:DWORD
I_RpcBindingSetAsync PROTO :DWORD,:DWORD
I_RpcClearMutex PROTO :DWORD
I_RpcConnectionInqSockBuffSize PROTO :DWORD,:DWORD
I_RpcConnectionSetSockBuffSize PROTO :DWORD,:DWORD
I_RpcDeleteMutex PROTO :DWORD
I_RpcFree PROTO :DWORD
I_RpcFreeBuffer PROTO :DWORD
I_RpcFreePipeBuffer PROTO :DWORD
I_RpcGetAssociationContext PROTO :DWORD,:DWORD
I_RpcGetBuffer PROTO :DWORD
I_RpcGetCurrentCallHandle PROTO
I_RpcGetServerContextList PROTO :DWORD
I_RpcGetThreadWindowHandle PROTO :DWORD
I_RpcIfInqTransferSyntaxes PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_RpcMapWin32Status PROTO :DWORD
I_RpcMonitorAssociation PROTO :DWORD,:DWORD,:DWORD
I_RpcNsBindingSetEntryNameA PROTO :DWORD,:DWORD,:DWORD
I_RpcNsBindingSetEntryName equ <I_RpcNsBindingSetEntryNameA>

I_RpcParseSecurity PROTO :DWORD,:DWORD
I_RpcPauseExecution PROTO :DWORD
I_RpcReallocPipeBuffer PROTO :DWORD,:DWORD
I_RpcReceive PROTO :DWORD,:DWORD
I_RpcRequestMutex PROTO :DWORD
I_RpcSend PROTO :DWORD
I_RpcSendReceive PROTO :DWORD
I_RpcServerAllocateIpPort PROTO :DWORD,:DWORD
I_RpcServerInqTransportType PROTO :DWORD
I_RpcServerRegisterForwardFunction PROTO :DWORD
I_RpcServerStartListening PROTO :DWORD
I_RpcServerStopListening PROTO
I_RpcSetAsyncHandle PROTO :DWORD,:DWORD
I_RpcSetServerContextList PROTO :DWORD,:DWORD
I_RpcSetWMsgEndpoint PROTO :DWORD
I_RpcSsDontSerializeContext PROTO
I_RpcStopMonitorAssociation PROTO :DWORD
I_RpcTransConnectionAllocatePacket PROTO :DWORD,:DWORD
I_RpcTransConnectionFreePacket PROTO :DWORD,:DWORD
I_RpcTransConnectionReallocPacket PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_RpcTransDatagramAllocate PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_RpcTransDatagramAllocate2 PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_RpcTransDatagramFree PROTO :DWORD,:DWORD,:DWORD
I_RpcTransGetReadEvent PROTO
I_RpcTransGetWriteEvent PROTO
I_RpcTransIoCancelled PROTO :DWORD,:DWORD
I_RpcTransPingServer PROTO :DWORD
I_RpcTransProtectThread PROTO
I_RpcTransServerAllocatePacket PROTO :DWORD,:DWORD
I_RpcTransServerFreePacket PROTO :DWORD,:DWORD
I_RpcTransServerNewConnection PROTO :DWORD
I_RpcTransServerReallocPacket PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_RpcTransUnprotectThread PROTO :DWORD
I_RpcWindowProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_UuidCreate PROTO :DWORD
MIDL_wchar_strcpy PROTO :DWORD,:DWORD
MIDL_wchar_strlen PROTO :DWORD
MesBufferHandleReset PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MesDecodeBufferHandleCreate PROTO :DWORD,:DWORD,:DWORD
MesDecodeIncrementalHandleCreate PROTO :DWORD,:DWORD,:DWORD
MesEncodeDynBufferHandleCreate PROTO :DWORD,:DWORD,:DWORD
MesEncodeFixedBufferHandleCreate PROTO :DWORD,:DWORD,:DWORD,:DWORD
MesEncodeIncrementalHandleCreate PROTO :DWORD,:DWORD,:DWORD,:DWORD
MesHandleFree PROTO :DWORD
MesIncrementalHandleReset PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MesInqProcEncodingId PROTO :DWORD,:DWORD,:DWORD
NDRCContextBinding PROTO :DWORD
NDRCContextMarshall PROTO :DWORD,:DWORD
NDRCContextUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NDRSContextMarshall PROTO :DWORD,:DWORD,:DWORD
NDRSContextMarshallEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
NDRSContextUnmarshall PROTO :DWORD,:DWORD
NDRSContextUnmarshallEx PROTO :DWORD,:DWORD,:DWORD
NDRcopy PROTO :DWORD,:DWORD,:DWORD
NdrAllocate PROTO :DWORD,:DWORD
NdrAsyncServerCall PROTO :DWORD
NdrAsyncStubCall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrByteCountPointerBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrByteCountPointerFree PROTO :DWORD,:DWORD,:DWORD
NdrByteCountPointerMarshall PROTO :DWORD,:DWORD,:DWORD
NdrByteCountPointerUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrCStdStubBuffer2_Release PROTO :DWORD,:DWORD
NdrCStdStubBuffer_Release PROTO :DWORD,:DWORD
NdrClearOutParameters PROTO :DWORD,:DWORD,:DWORD
NdrClientContextMarshall PROTO :DWORD,:DWORD,:DWORD
NdrClientContextUnmarshall PROTO :DWORD,:DWORD,:DWORD
NdrClientInitialize PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrClientInitializeNew PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrComplexArrayBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrComplexArrayFree PROTO :DWORD,:DWORD,:DWORD
NdrComplexArrayMarshall PROTO :DWORD,:DWORD,:DWORD
NdrComplexArrayMemorySize PROTO :DWORD,:DWORD
NdrComplexArrayUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrComplexStructBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrComplexStructFree PROTO :DWORD,:DWORD,:DWORD
NdrComplexStructMarshall PROTO :DWORD,:DWORD,:DWORD
NdrComplexStructMemorySize PROTO :DWORD,:DWORD
NdrComplexStructUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantArrayBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrConformantArrayFree PROTO :DWORD,:DWORD,:DWORD
NdrConformantArrayMarshall PROTO :DWORD,:DWORD,:DWORD
NdrConformantArrayMemorySize PROTO :DWORD,:DWORD
NdrConformantArrayUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantStringBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrConformantStringMarshall PROTO :DWORD,:DWORD,:DWORD
NdrConformantStringMemorySize PROTO :DWORD,:DWORD
NdrConformantStringUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantStructBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrConformantStructFree PROTO :DWORD,:DWORD,:DWORD
NdrConformantStructMarshall PROTO :DWORD,:DWORD,:DWORD
NdrConformantStructMemorySize PROTO :DWORD,:DWORD
NdrConformantStructUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantVaryingArrayBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrConformantVaryingArrayFree PROTO :DWORD,:DWORD,:DWORD
NdrConformantVaryingArrayMarshall PROTO :DWORD,:DWORD,:DWORD
NdrConformantVaryingArrayMemorySize PROTO :DWORD,:DWORD
NdrConformantVaryingArrayUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantVaryingStructBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrConformantVaryingStructFree PROTO :DWORD,:DWORD,:DWORD
NdrConformantVaryingStructMarshall PROTO :DWORD,:DWORD,:DWORD
NdrConformantVaryingStructMemorySize PROTO :DWORD,:DWORD
NdrConformantVaryingStructUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrContextHandleSize PROTO :DWORD,:DWORD,:DWORD
NdrConvert PROTO :DWORD,:DWORD
NdrConvert2 PROTO :DWORD,:DWORD,:DWORD
NdrDllCanUnloadNow PROTO :DWORD
NdrDllGetClassObject PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrDllRegisterProxy PROTO :DWORD,:DWORD,:DWORD
NdrDllUnregisterProxy PROTO :DWORD,:DWORD,:DWORD
NdrEncapsulatedUnionBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrEncapsulatedUnionFree PROTO :DWORD,:DWORD,:DWORD
NdrEncapsulatedUnionMarshall PROTO :DWORD,:DWORD,:DWORD
NdrEncapsulatedUnionMemorySize PROTO :DWORD,:DWORD
NdrEncapsulatedUnionUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrFixedArrayBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrFixedArrayFree PROTO :DWORD,:DWORD,:DWORD
NdrFixedArrayMarshall PROTO :DWORD,:DWORD,:DWORD
NdrFixedArrayMemorySize PROTO :DWORD,:DWORD
NdrFixedArrayUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrFreeBuffer PROTO :DWORD
NdrFullPointerFree PROTO :DWORD,:DWORD
NdrFullPointerInsertRefId PROTO :DWORD,:DWORD,:DWORD
NdrFullPointerQueryPointer PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrFullPointerQueryRefId PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrFullPointerXlatFree PROTO :DWORD
NdrFullPointerXlatInit PROTO :DWORD,:DWORD
NdrGetBuffer PROTO :DWORD,:DWORD,:DWORD
NdrGetDcomProtocolVersion PROTO :DWORD,:DWORD
NdrGetPartialBuffer PROTO :DWORD
NdrGetPipeBuffer PROTO :DWORD,:DWORD,:DWORD
NdrHardStructBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrHardStructFree PROTO :DWORD,:DWORD,:DWORD
NdrHardStructMarshall PROTO :DWORD,:DWORD,:DWORD
NdrHardStructMemorySize PROTO :DWORD,:DWORD
NdrHardStructUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrInterfacePointerBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrInterfacePointerFree PROTO :DWORD,:DWORD,:DWORD
NdrInterfacePointerMarshall PROTO :DWORD,:DWORD,:DWORD
NdrInterfacePointerMemorySize PROTO :DWORD,:DWORD
NdrInterfacePointerUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrIsAppDoneWithPipes PROTO :DWORD
NdrMapCommAndFaultStatus PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrMarkNextActivePipe PROTO :DWORD
NdrMesSimpleTypeAlignSize PROTO :DWORD
NdrMesSimpleTypeDecode PROTO :DWORD,:DWORD,:DWORD
NdrMesSimpleTypeEncode PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrMesTypeAlignSize PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrMesTypeDecode PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrMesTypeEncode PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrNonConformantStringBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrNonConformantStringMarshall PROTO :DWORD,:DWORD,:DWORD
NdrNonConformantStringMemorySize PROTO :DWORD,:DWORD
NdrNonConformantStringUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrNonEncapsulatedUnionBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrNonEncapsulatedUnionFree PROTO :DWORD,:DWORD,:DWORD
NdrNonEncapsulatedUnionMarshall PROTO :DWORD,:DWORD,:DWORD
NdrNonEncapsulatedUnionMemorySize PROTO :DWORD,:DWORD
NdrNonEncapsulatedUnionUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrNsGetBuffer PROTO :DWORD,:DWORD,:DWORD
NdrNsSendReceive PROTO :DWORD,:DWORD,:DWORD
NdrOleAllocate PROTO :DWORD
NdrOleFree PROTO :DWORD
NdrPipePull PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrPipePush PROTO :DWORD,:DWORD,:DWORD
NdrPipeSendReceive PROTO :DWORD,:DWORD
NdrPipesDone PROTO :DWORD
NdrPipesInitialize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrPointerBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrPointerFree PROTO :DWORD,:DWORD,:DWORD
NdrPointerMarshall PROTO :DWORD,:DWORD,:DWORD
NdrPointerMemorySize PROTO :DWORD,:DWORD
NdrPointerUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrProxyErrorHandler PROTO :DWORD
NdrProxyFreeBuffer PROTO :DWORD,:DWORD
NdrProxyGetBuffer PROTO :DWORD,:DWORD
NdrProxyInitialize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrProxySendReceive PROTO :DWORD,:DWORD
NdrRpcSmClientAllocate PROTO :DWORD
NdrRpcSmClientFree PROTO :DWORD
NdrRpcSmSetClientToOsf PROTO :DWORD
NdrRpcSsDefaultAllocate PROTO :DWORD
NdrRpcSsDefaultFree PROTO :DWORD
NdrRpcSsDisableAllocate PROTO :DWORD
NdrRpcSsEnableAllocate PROTO :DWORD
NdrSendReceive PROTO :DWORD,:DWORD
NdrServerCall PROTO :DWORD
NdrServerCall2 PROTO :DWORD
NdrServerContextMarshall PROTO :DWORD,:DWORD,:DWORD
NdrServerContextUnmarshall PROTO :DWORD
NdrServerInitialize PROTO :DWORD,:DWORD,:DWORD
NdrServerInitializeMarshall PROTO :DWORD,:DWORD
NdrServerInitializeNew PROTO :DWORD,:DWORD,:DWORD
NdrServerInitializePartial PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrServerInitializeUnmarshall PROTO :DWORD,:DWORD,:DWORD
NdrServerMarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrServerUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrSimpleStructBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrSimpleStructFree PROTO :DWORD,:DWORD,:DWORD
NdrSimpleStructMarshall PROTO :DWORD,:DWORD,:DWORD
NdrSimpleStructMemorySize PROTO :DWORD,:DWORD
NdrSimpleStructUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrSimpleTypeMarshall PROTO :DWORD,:DWORD,:DWORD
NdrSimpleTypeUnmarshall PROTO :DWORD,:DWORD,:DWORD
NdrStubCall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrStubCall2 PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrStubForwardingFunction PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrStubGetBuffer PROTO :DWORD,:DWORD,:DWORD
NdrStubInitialize PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrStubInitializeMarshall PROTO :DWORD,:DWORD,:DWORD
NdrUserMarshalBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrUserMarshalFree PROTO :DWORD,:DWORD,:DWORD
NdrUserMarshalMarshall PROTO :DWORD,:DWORD,:DWORD
NdrUserMarshalMemorySize PROTO :DWORD,:DWORD
NdrUserMarshalSimpleTypeConvert PROTO :DWORD,:DWORD,:DWORD
NdrUserMarshalUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrVaryingArrayBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrVaryingArrayFree PROTO :DWORD,:DWORD,:DWORD
NdrVaryingArrayMarshall PROTO :DWORD,:DWORD,:DWORD
NdrVaryingArrayMemorySize PROTO :DWORD,:DWORD
NdrVaryingArrayUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrXmitOrRepAsBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrXmitOrRepAsFree PROTO :DWORD,:DWORD,:DWORD
NdrXmitOrRepAsMarshall PROTO :DWORD,:DWORD,:DWORD
NdrXmitOrRepAsMemorySize PROTO :DWORD,:DWORD
NdrXmitOrRepAsUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrpSetRpcSsDefaults PROTO :DWORD,:DWORD
RpcAbortAsyncCall PROTO :DWORD,:DWORD
RpcAsyncAbortCall PROTO :DWORD,:DWORD
RpcAsyncCancelCall PROTO :DWORD,:DWORD
RpcAsyncCompleteCall PROTO :DWORD,:DWORD
RpcAsyncGetCallStatus PROTO :DWORD
RpcAsyncInitializeHandle PROTO :DWORD,:DWORD
RpcAsyncRegisterInfo PROTO :DWORD
RpcBindingCopy PROTO :DWORD,:DWORD
RpcBindingFree PROTO :DWORD
RpcBindingFromStringBindingA PROTO :DWORD,:DWORD
RpcBindingFromStringBinding equ <RpcBindingFromStringBindingA>

RpcBindingInqAuthClientA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcBindingInqAuthClient equ <RpcBindingInqAuthClientA>

RpcBindingInqAuthInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcBindingInqAuthInfo equ <RpcBindingInqAuthInfoA>

RpcBindingInqAuthInfoExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcBindingInqAuthInfoEx equ <RpcBindingInqAuthInfoExA>

RpcBindingInqObject PROTO :DWORD,:DWORD
RpcBindingInqOption PROTO :DWORD,:DWORD,:DWORD
RpcBindingReset PROTO :DWORD
RpcBindingServerFromClient PROTO :DWORD,:DWORD
RpcBindingSetAuthInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcBindingSetAuthInfo equ <RpcBindingSetAuthInfoA>

RpcBindingSetAuthInfoExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcBindingSetAuthInfoEx equ <RpcBindingSetAuthInfoExA>

RpcBindingSetObject PROTO :DWORD,:DWORD
RpcBindingSetOption PROTO :DWORD,:DWORD,:DWORD
RpcBindingToStringBindingA PROTO :DWORD,:DWORD
RpcBindingToStringBinding equ <RpcBindingToStringBindingA>

RpcBindingVectorFree PROTO :DWORD
RpcCancelAsyncCall PROTO :DWORD,:DWORD
RpcCancelThread PROTO :DWORD
RpcCompleteAsyncCall PROTO :DWORD,:DWORD
RpcEpRegisterA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcEpRegister equ <RpcEpRegisterA>

RpcEpRegisterNoReplaceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcEpRegisterNoReplace equ <RpcEpRegisterNoReplaceA>

RpcEpResolveBinding PROTO :DWORD,:DWORD
RpcEpUnregister PROTO :DWORD,:DWORD,:DWORD
RpcGetAsyncCallStatus PROTO :DWORD
RpcIfIdVectorFree PROTO :DWORD
RpcIfInqId PROTO :DWORD,:DWORD
RpcImpersonateClient PROTO :DWORD
RpcInitializeAsyncHandle PROTO :DWORD,:DWORD
RpcMgmtBindingInqParameter PROTO :DWORD,:DWORD,:DWORD
RpcMgmtBindingSetParameter PROTO :DWORD,:DWORD,:DWORD
RpcMgmtEnableIdleCleanup PROTO
RpcMgmtEpEltInqBegin PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcMgmtEpEltInqDone PROTO :DWORD
RpcMgmtEpEltInqNextA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcMgmtEpEltInqNext equ <RpcMgmtEpEltInqNextA>

RpcMgmtEpUnregister PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcMgmtInqComTimeout PROTO :DWORD,:DWORD
RpcMgmtInqDefaultProtectLevel PROTO :DWORD,:DWORD
RpcMgmtInqIfIds PROTO :DWORD,:DWORD
RpcMgmtInqParameter PROTO :DWORD,:DWORD
RpcMgmtInqServerPrincNameA PROTO :DWORD,:DWORD,:DWORD
RpcMgmtInqServerPrincName equ <RpcMgmtInqServerPrincNameA>

RpcMgmtInqStats PROTO :DWORD,:DWORD
RpcMgmtIsServerListening PROTO :DWORD
RpcMgmtSetAuthorizationFn PROTO :DWORD
RpcMgmtSetCancelTimeout PROTO :DWORD
RpcMgmtSetComTimeout PROTO :DWORD,:DWORD
RpcMgmtSetParameter PROTO :DWORD,:DWORD
RpcMgmtSetServerStackSize PROTO :DWORD
RpcMgmtStatsVectorFree PROTO :DWORD
RpcMgmtStopServerListening PROTO :DWORD
RpcMgmtWaitServerListen PROTO
RpcNetworkInqProtseqsA PROTO :DWORD
RpcNetworkInqProtseqs equ <RpcNetworkInqProtseqsA>

RpcNetworkIsProtseqValidA PROTO :DWORD
RpcNetworkIsProtseqValid equ <RpcNetworkIsProtseqValidA>

RpcNsBindingInqEntryNameA PROTO :DWORD,:DWORD,:DWORD
RpcNsBindingInqEntryName equ <RpcNsBindingInqEntryNameA>

RpcObjectInqType PROTO :DWORD,:DWORD
RpcObjectSetInqFn PROTO :DWORD
RpcObjectSetType PROTO :DWORD,:DWORD
RpcProtseqVectorFreeA PROTO :DWORD
RpcProtseqVectorFree equ <RpcProtseqVectorFreeA>

RpcRaiseException PROTO :DWORD
RpcRegisterAsyncInfo PROTO :DWORD
RpcRevertToSelf PROTO
RpcRevertToSelfEx PROTO :DWORD
RpcServerInqBindings PROTO :DWORD
RpcServerInqDefaultPrincNameA PROTO :DWORD,:DWORD
RpcServerInqDefaultPrincName equ <RpcServerInqDefaultPrincNameA>

RpcServerInqIf PROTO :DWORD,:DWORD,:DWORD
RpcServerListen PROTO :DWORD,:DWORD,:DWORD
RpcServerRegisterAuthInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcServerRegisterAuthInfo equ <RpcServerRegisterAuthInfoA>

RpcServerRegisterIf PROTO :DWORD,:DWORD,:DWORD
RpcServerRegisterIfEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcServerTestCancel PROTO :DWORD
RpcServerUnregisterIf PROTO :DWORD,:DWORD,:DWORD
RpcServerUseAllProtseqs PROTO :DWORD,:DWORD
RpcServerUseAllProtseqsEx PROTO :DWORD,:DWORD,:DWORD
RpcServerUseAllProtseqsIf PROTO :DWORD,:DWORD,:DWORD
RpcServerUseAllProtseqsIfEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcServerUseProtseqA PROTO :DWORD,:DWORD,:DWORD
RpcServerUseProtseq equ <RpcServerUseProtseqA>

RpcServerUseProtseqEpA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcServerUseProtseqEp equ <RpcServerUseProtseqEpA>

RpcServerUseProtseqEpExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcServerUseProtseqEpEx equ <RpcServerUseProtseqEpExA>

RpcServerUseProtseqExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcServerUseProtseqEx equ <RpcServerUseProtseqExA>

RpcServerUseProtseqIfA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcServerUseProtseqIf equ <RpcServerUseProtseqIfA>

RpcServerUseProtseqIfExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcServerUseProtseqIfEx equ <RpcServerUseProtseqIfExA>

RpcSmAllocate PROTO :DWORD,:DWORD
RpcSmClientFree PROTO :DWORD
RpcSmDestroyClientContext PROTO :DWORD
RpcSmDisableAllocate PROTO
RpcSmEnableAllocate PROTO
RpcSmFree PROTO :DWORD
RpcSmGetThreadHandle PROTO :DWORD
RpcSmSetClientAllocFree PROTO :DWORD,:DWORD
RpcSmSetThreadHandle PROTO :DWORD
RpcSmSwapClientAllocFree PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcSsAllocate PROTO :DWORD
RpcSsDestroyClientContext PROTO :DWORD
RpcSsDisableAllocate PROTO
RpcSsDontSerializeContext PROTO
RpcSsEnableAllocate PROTO
RpcSsFree PROTO :DWORD
RpcSsGetThreadHandle PROTO
RpcSsSetClientAllocFree PROTO :DWORD,:DWORD
RpcSsSetThreadHandle PROTO :DWORD
RpcSsSwapClientAllocFree PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcStringBindingComposeA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcStringBindingCompose equ <RpcStringBindingComposeA>

RpcStringBindingParseA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcStringBindingParse equ <RpcStringBindingParseA>

RpcStringFreeA PROTO :DWORD
RpcStringFree equ <RpcStringFreeA>

RpcTestCancel PROTO
TowerConstruct PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TowerExplode PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UuidCompare PROTO :DWORD,:DWORD,:DWORD
UuidCreate PROTO :DWORD
UuidCreateNil PROTO :DWORD
UuidEqual PROTO :DWORD,:DWORD,:DWORD
UuidFromStringA PROTO :DWORD,:DWORD
UuidFromString equ <UuidFromStringA>

UuidHash PROTO :DWORD,:DWORD
UuidIsNil PROTO :DWORD,:DWORD
UuidToStringA PROTO :DWORD,:DWORD
UuidToString equ <UuidToStringA>

char_array_from_ndr PROTO :DWORD,:DWORD,:DWORD,:DWORD
char_from_ndr PROTO :DWORD,:DWORD
data_from_ndr PROTO :DWORD,:DWORD,:DWORD,:DWORD
data_into_ndr PROTO :DWORD,:DWORD,:DWORD,:DWORD
data_size_ndr PROTO :DWORD,:DWORD,:DWORD,:DWORD
double_array_from_ndr PROTO :DWORD,:DWORD,:DWORD,:DWORD
double_from_ndr PROTO :DWORD,:DWORD
enum_from_ndr PROTO :DWORD,:DWORD
float_array_from_ndr PROTO :DWORD,:DWORD,:DWORD,:DWORD
float_from_ndr PROTO :DWORD,:DWORD
long_array_from_ndr PROTO :DWORD,:DWORD,:DWORD,:DWORD
long_from_ndr PROTO :DWORD,:DWORD
long_from_ndr_temp PROTO :DWORD,:DWORD,:DWORD
short_array_from_ndr PROTO :DWORD,:DWORD,:DWORD,:DWORD
short_from_ndr PROTO :DWORD,:DWORD
short_from_ndr_temp PROTO :DWORD,:DWORD,:DWORD
tree_into_ndr PROTO :DWORD,:DWORD,:DWORD,:DWORD
tree_peek_ndr PROTO :DWORD,:DWORD,:DWORD,:DWORD
tree_size_ndr PROTO :DWORD,:DWORD,:DWORD,:DWORD

