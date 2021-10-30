; ..\LIB\NTMSAPI.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

AccessNtmsLibraryDoor PROTO :DWORD,:DWORD,:DWORD
AllocateNtmsMedia PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CancelNtmsLibraryRequest PROTO :DWORD,:DWORD
CancelNtmsOperatorRequest PROTO :DWORD,:DWORD
CleanNtmsDrive PROTO :DWORD,:DWORD
CloseNtmsNotification PROTO :DWORD
CloseNtmsSession PROTO :DWORD
CreateNtmsMediaPoolA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateNtmsMediaPool equ <CreateNtmsMediaPoolA>

DeallocateNtmsMedia PROTO :DWORD,:DWORD,:DWORD
DecommissionNtmsMedia PROTO :DWORD,:DWORD
DeleteNtmsLibrary PROTO :DWORD,:DWORD
DeleteNtmsMedia PROTO :DWORD,:DWORD
DeleteNtmsMediaPool PROTO :DWORD,:DWORD
DisableNtmsObject PROTO :DWORD,:DWORD,:DWORD
DismountNtmsDrive PROTO :DWORD,:DWORD
DismountNtmsMedia PROTO :DWORD,:DWORD,:DWORD,:DWORD
EjectNtmsCleaner PROTO :DWORD,:DWORD,:DWORD,:DWORD
EjectNtmsMedia PROTO :DWORD,:DWORD,:DWORD,:DWORD
EnableNtmsObject PROTO :DWORD,:DWORD,:DWORD
EnumerateNtmsObject PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExportNtmsDatabase PROTO :DWORD
GetNtmsMediaPoolNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetNtmsMediaPoolName equ <GetNtmsMediaPoolNameA>

GetNtmsObjectAttributeA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetNtmsObjectAttribute equ <GetNtmsObjectAttributeA>

GetNtmsObjectInformationA PROTO :DWORD,:DWORD,:DWORD
GetNtmsObjectInformation equ <GetNtmsObjectInformationA>

GetNtmsObjectSecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImportNtmsDatabase PROTO :DWORD
InjectNtmsCleaner PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InjectNtmsMedia PROTO :DWORD,:DWORD,:DWORD,:DWORD
InventoryNtmsLibrary PROTO :DWORD,:DWORD,:DWORD
MountNtmsMedia PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MoveToNtmsMediaPool PROTO :DWORD,:DWORD,:DWORD
OpenNtmsNotification PROTO :DWORD,:DWORD
OpenNtmsSessionA PROTO :DWORD,:DWORD,:DWORD
OpenNtmsSession equ <OpenNtmsSessionA>

ReleaseNtmsCleanerSlot PROTO :DWORD,:DWORD
ReserveNtmsCleanerSlot PROTO :DWORD,:DWORD,:DWORD
SatisfyNtmsOperatorRequest PROTO :DWORD,:DWORD
SetNtmsMediaComplete PROTO :DWORD,:DWORD
SetNtmsObjectAttributeA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetNtmsObjectAttribute equ <SetNtmsObjectAttributeA>

SetNtmsObjectInformationA PROTO :DWORD,:DWORD,:DWORD
SetNtmsObjectInformation equ <SetNtmsObjectInformationA>

SetNtmsObjectSecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SubmitNtmsOperatorRequestA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SubmitNtmsOperatorRequest equ <SubmitNtmsOperatorRequestA>

SwapNtmsMedia PROTO :DWORD,:DWORD,:DWORD
UpdateNtmsOmidInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WaitForNtmsNotification PROTO :DWORD,:DWORD,:DWORD
WaitForNtmsOperatorRequest PROTO :DWORD,:DWORD,:DWORD

