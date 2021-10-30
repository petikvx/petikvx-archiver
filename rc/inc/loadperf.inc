; ..\LIB\LOADPERF.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DllEntryPoint PROTO :DWORD,:DWORD,:DWORD
LoadPerfCounterTextStringsA PROTO :DWORD,:DWORD
LoadPerfCounterTextStrings equ <LoadPerfCounterTextStringsA>

UnloadPerfCounterTextStringsA PROTO :DWORD,:DWORD
UnloadPerfCounterTextStrings equ <UnloadPerfCounterTextStringsA>


