; ..\LIB\RPCNS4.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

I_GetDefaultEntrySyntax PROTO
I_RpcNsGetBuffer PROTO :DWORD
I_RpcNsRaiseException PROTO :DWORD,:DWORD
I_RpcNsSendReceive PROTO :DWORD,:DWORD
I_RpcReBindBuffer PROTO :DWORD
RpcIfIdVectorFree PROTO :DWORD
RpcNsBindingExportA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingExport equ <RpcNsBindingExportA>

RpcNsBindingImportBeginA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingImportBegin equ <RpcNsBindingImportBeginA>

RpcNsBindingImportDone PROTO :DWORD
RpcNsBindingImportNext PROTO :DWORD,:DWORD
RpcNsBindingLookupBeginA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingLookupBegin equ <RpcNsBindingLookupBeginA>

RpcNsBindingLookupDone PROTO :DWORD
RpcNsBindingLookupNext PROTO :DWORD,:DWORD
RpcNsBindingSelect PROTO :DWORD,:DWORD
RpcNsBindingUnexportA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingUnexport equ <RpcNsBindingUnexportA>

RpcNsEntryExpandNameA PROTO :DWORD,:DWORD,:DWORD
RpcNsEntryExpandName equ <RpcNsEntryExpandNameA>

RpcNsEntryObjectInqBeginA PROTO :DWORD,:DWORD,:DWORD
RpcNsEntryObjectInqBegin equ <RpcNsEntryObjectInqBeginA>

RpcNsEntryObjectInqDone PROTO :DWORD
RpcNsEntryObjectInqNext PROTO :DWORD,:DWORD
RpcNsGroupDeleteA PROTO :DWORD,:DWORD
RpcNsGroupDelete equ <RpcNsGroupDeleteA>

RpcNsGroupMbrAddA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsGroupMbrAdd equ <RpcNsGroupMbrAddA>

RpcNsGroupMbrInqBeginA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsGroupMbrInqBegin equ <RpcNsGroupMbrInqBeginA>

RpcNsGroupMbrInqDone PROTO :DWORD
RpcNsGroupMbrInqNextA PROTO :DWORD,:DWORD
RpcNsGroupMbrInqNext equ <RpcNsGroupMbrInqNextA>

RpcNsGroupMbrRemoveA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsGroupMbrRemove equ <RpcNsGroupMbrRemoveA>

RpcNsMgmtBindingUnexportA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsMgmtBindingUnexport equ <RpcNsMgmtBindingUnexportA>

RpcNsMgmtEntryCreateA PROTO :DWORD,:DWORD
RpcNsMgmtEntryCreate equ <RpcNsMgmtEntryCreateA>

RpcNsMgmtEntryDeleteA PROTO :DWORD,:DWORD
RpcNsMgmtEntryDelete equ <RpcNsMgmtEntryDeleteA>

RpcNsMgmtEntryInqIfIdsA PROTO :DWORD,:DWORD,:DWORD
RpcNsMgmtEntryInqIfIds equ <RpcNsMgmtEntryInqIfIdsA>

RpcNsMgmtHandleSetExpAge PROTO :DWORD,:DWORD
RpcNsMgmtInqExpAge PROTO :DWORD
RpcNsMgmtSetExpAge PROTO :DWORD
RpcNsProfileDeleteA PROTO :DWORD,:DWORD
RpcNsProfileDelete equ <RpcNsProfileDeleteA>

RpcNsProfileEltAddA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsProfileEltAdd equ <RpcNsProfileEltAddA>

RpcNsProfileEltInqBeginA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsProfileEltInqBegin equ <RpcNsProfileEltInqBeginA>

RpcNsProfileEltInqDone PROTO :DWORD
RpcNsProfileEltInqNextA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsProfileEltInqNext equ <RpcNsProfileEltInqNextA>

RpcNsProfileEltRemoveA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsProfileEltRemove equ <RpcNsProfileEltRemoveA>


