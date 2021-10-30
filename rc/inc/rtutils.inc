; ..\LIB\RTUTILS.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LogErrorA PROTO :DWORD,:DWORD,:DWORD,:DWORD
LogError equ <LogErrorA>

LogEventA PROTO :DWORD,:DWORD,:DWORD,:DWORD
LogEvent equ <LogEventA>

MprSetupProtocolEnum PROTO :DWORD,:DWORD,:DWORD
MprSetupProtocolFree PROTO :DWORD
QueueWorkItem PROTO :DWORD,:DWORD,:DWORD
RouterAssert PROTO :DWORD,:DWORD,:DWORD,:DWORD
RouterGetErrorStringA PROTO :DWORD,:DWORD
RouterGetErrorString equ <RouterGetErrorStringA>

RouterLogDeregisterA PROTO :DWORD
RouterLogDeregister equ <RouterLogDeregisterA>

RouterLogEventA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterLogEvent equ <RouterLogEventA>

RouterLogEventDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterLogEventData equ <RouterLogEventDataA>

RouterLogEventStringA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterLogEventString equ <RouterLogEventStringA>

RouterLogRegisterA PROTO :DWORD
RouterLogRegister equ <RouterLogRegisterA>

SetIoCompletionProc PROTO :DWORD,:DWORD
TraceDeregisterA PROTO :DWORD
TraceDeregister equ <TraceDeregisterA>

TraceDeregisterExA PROTO :DWORD,:DWORD
TraceDeregisterEx equ <TraceDeregisterExA>

TraceDumpExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TraceDumpEx equ <TraceDumpExA>

TraceGetConsoleA PROTO :DWORD,:DWORD
TraceGetConsole equ <TraceGetConsoleA>

TracePutsExA PROTO :DWORD,:DWORD,:DWORD
TracePutsEx equ <TracePutsExA>

TraceRegisterExA PROTO :DWORD,:DWORD
TraceRegisterEx equ <TraceRegisterExA>

TraceVprintfExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
TraceVprintfEx equ <TraceVprintfExA>


