; ..\LIB\SCRNSAVW.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DefScreenSaverProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
DoChangePw PROTO :DWORD
DoConfigBox PROTO :DWORD
DoPasswordCheck PROTO :DWORD
DoSaverPreview PROTO :DWORD
DoScreenSave PROTO :DWORD
DummyEntry PROTO
GetElapsedTime PROTO :DWORD,:DWORD
HogMachine PROTO :DWORD
InitRealScreenSave PROTO
LoadPwdDLL PROTO
RealScreenSaverProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
RegisterDialogClasses PROTO :DWORD
ScreenSaverChangePassword PROTO :DWORD
ScreenSaverConfigureDialog PROTO :DWORD,:DWORD,:DWORD,:DWORD
UnloadPwdDLL PROTO
WinMain PROTO :DWORD,:DWORD,:DWORD,:DWORD
WinMainN PROTO :DWORD,:DWORD,:DWORD,:DWORD
atoui PROTO :DWORD

