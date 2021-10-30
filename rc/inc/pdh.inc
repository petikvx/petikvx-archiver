; ..\LIB\PDH.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~

DLLInit PROTO :DWORD,:DWORD,:DWORD
PdhAddCounterA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhAddCounter equ <PdhAddCounterA>

PdhBrowseCountersA PROTO :DWORD
PdhBrowseCounters equ <PdhBrowseCountersA>

PdhCalculateCounterFromRawValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhCloseLog PROTO :DWORD,:DWORD
PdhCloseQuery PROTO :DWORD
PdhCollectQueryData PROTO :DWORD
PdhCollectQueryDataEx PROTO :DWORD,:DWORD,:DWORD
PdhComputeCounterStatistics PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhConnectMachineA PROTO :DWORD
PdhConnectMachine equ <PdhConnectMachineA>

PdhDecodeWmiPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhDecodeWmiPath equ <PdhDecodeWmiPathA>

PdhEncodeWmiPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhEncodeWmiPath equ <PdhEncodeWmiPathA>

PdhEnumMachinesA PROTO :DWORD,:DWORD,:DWORD
PdhEnumMachines equ <PdhEnumMachinesA>

PdhEnumObjectItemsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhEnumObjectItems equ <PdhEnumObjectItemsA>

PdhEnumObjectsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhEnumObjects equ <PdhEnumObjectsA>

PdhExpandCounterPathA PROTO :DWORD,:DWORD,:DWORD
PdhExpandCounterPath equ <PdhExpandCounterPathA>

PdhFormatFromRawValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhGetCounterInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetCounterInfo equ <PdhGetCounterInfoA>

PdhGetCounterTimeBase PROTO :DWORD,:DWORD
PdhGetDataSourceTimeRangeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetDataSourceTimeRange equ <PdhGetDataSourceTimeRangeA>

PdhGetDefaultPerfCounterA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhGetDefaultPerfCounter equ <PdhGetDefaultPerfCounterA>

PdhGetDefaultPerfObjectA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetDefaultPerfObject equ <PdhGetDefaultPerfObjectA>

PdhGetDllVersion PROTO :DWORD
PdhGetFormattedCounterArrayA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhGetFormattedCounterArray equ <PdhGetFormattedCounterArrayA>

PdhGetFormattedCounterValue PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetLogFileSize PROTO :DWORD,:DWORD
PdhGetRawCounterArrayA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetRawCounterArray equ <PdhGetRawCounterArrayA>

PdhGetRawCounterValue PROTO :DWORD,:DWORD,:DWORD
PdhIsRealTimeQuery PROTO :DWORD
PdhLogServiceCommandA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhLogServiceCommand equ <PdhLogServiceCommandA>

PdhLogServiceControlA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhLogServiceControl equ <PdhLogServiceControlA>

PdhLookupPerfIndexByNameA PROTO :DWORD,:DWORD,:DWORD
PdhLookupPerfIndexByName equ <PdhLookupPerfIndexByNameA>

PdhLookupPerfNameByIndexA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhLookupPerfNameByIndex equ <PdhLookupPerfNameByIndexA>

PdhMakeCounterPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhMakeCounterPath equ <PdhMakeCounterPathA>

PdhOpenLogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhOpenLog equ <PdhOpenLogA>

PdhOpenQueryA PROTO :DWORD,:DWORD,:DWORD
PdhOpenQuery equ <PdhOpenQueryA>

PdhParseCounterPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhParseCounterPath equ <PdhParseCounterPathA>

PdhParseInstanceNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhParseInstanceName equ <PdhParseInstanceNameA>

PdhReadRawLogRecord PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhRemoveCounter PROTO :DWORD
PdhSelectDataSourceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhSelectDataSource equ <PdhSelectDataSourceA>

PdhSetCounterScaleFactor PROTO :DWORD,:DWORD
PdhSetQueryTimeRange PROTO :DWORD,:DWORD
PdhUpdateLogA PROTO :DWORD,:DWORD
PdhUpdateLog equ <PdhUpdateLogA>

PdhValidatePathA PROTO :DWORD
PdhValidatePath equ <PdhValidatePathA>

PdhVbAddCounter PROTO :DWORD,:DWORD,:DWORD
PdhVbCreateCounterPathList PROTO :DWORD,:DWORD
PdhVbGetCounterPathElements PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhVbGetCounterPathFromList PROTO :DWORD,:DWORD,:DWORD
PdhVbGetDoubleCounterValue PROTO :DWORD,:DWORD
PdhVbGetOneCounterPath PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhVbIsGoodStatus PROTO :DWORD
PdhVbOpenQuery PROTO :DWORD

