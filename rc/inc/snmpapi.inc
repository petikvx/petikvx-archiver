; ..\LIB\SNMPAPI.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SnmpSvcAddrIsIpx PROTO :DWORD,:DWORD,:DWORD
SnmpSvcAddrToSocket PROTO :DWORD,:DWORD
SnmpSvcGetEnterpriseOID PROTO
SnmpSvcGetUptime PROTO
SnmpSvcInitUptime PROTO
SnmpSvcSetLogLevel PROTO :DWORD
SnmpSvcSetLogType PROTO :DWORD
SnmpUtilAsnAnyCpy PROTO :DWORD,:DWORD
SnmpUtilAsnAnyFree PROTO :DWORD
SnmpUtilIdsToA PROTO :DWORD,:DWORD
SnmpUtilIdsTo equ <SnmpUtilIdsToA>

SnmpUtilMemAlloc PROTO :DWORD
SnmpUtilMemFree PROTO :DWORD
SnmpUtilMemReAlloc PROTO :DWORD,:DWORD
SnmpUtilOctetsCmp PROTO :DWORD,:DWORD
SnmpUtilOctetsCpy PROTO :DWORD,:DWORD
SnmpUtilOctetsFree PROTO :DWORD
SnmpUtilOctetsNCmp PROTO :DWORD,:DWORD,:DWORD
SnmpUtilOidAppend PROTO :DWORD,:DWORD
SnmpUtilOidCmp PROTO :DWORD,:DWORD
SnmpUtilOidCpy PROTO :DWORD,:DWORD
SnmpUtilOidFree PROTO :DWORD
SnmpUtilOidNCmp PROTO :DWORD,:DWORD,:DWORD
SnmpUtilOidToA PROTO :DWORD
SnmpUtilOidTo equ <SnmpUtilOidToA>

SnmpUtilPrintAsnAny PROTO :DWORD
SnmpUtilPrintOid PROTO :DWORD
SnmpUtilVarBindCpy PROTO :DWORD,:DWORD
SnmpUtilVarBindFree PROTO :DWORD
SnmpUtilVarBindListCpy PROTO :DWORD,:DWORD
SnmpUtilVarBindListFree PROTO :DWORD

