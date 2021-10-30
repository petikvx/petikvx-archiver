; ..\LIB\MSCMS.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~

AssociateColorProfileWithDeviceA PROTO :DWORD,:DWORD,:DWORD
AssociateColorProfileWithDevice equ <AssociateColorProfileWithDeviceA>

CheckBitmapBits PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CheckColors PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CloseColorProfile PROTO :DWORD
CreateColorTransformA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateColorTransform equ <CreateColorTransformA>

CreateDeviceLinkProfile PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateMultiProfileTransform PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateProfileFromLogColorSpaceA PROTO :DWORD,:DWORD
CreateProfileFromLogColorSpace equ <CreateProfileFromLogColorSpaceA>

DeleteColorTransform PROTO :DWORD
DisassociateColorProfileFromDeviceA PROTO :DWORD,:DWORD,:DWORD
DisassociateColorProfileFromDevice equ <DisassociateColorProfileFromDeviceA>

DllEntryPoint PROTO :DWORD,:DWORD,:DWORD
EnumColorProfilesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumColorProfiles equ <EnumColorProfilesA>

EnumerateMonitors PROTO :DWORD,:DWORD,:DWORD
GenerateCopyFilePaths PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetCMMInfo PROTO :DWORD,:DWORD
GetColorDirectoryA PROTO :DWORD,:DWORD,:DWORD
GetColorDirectory equ <GetColorDirectoryA>

GetColorProfileElement PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetColorProfileElementTag PROTO :DWORD,:DWORD,:DWORD
GetColorProfileFromHandle PROTO :DWORD,:DWORD,:DWORD
GetColorProfileHeader PROTO :DWORD,:DWORD
GetCountColorProfileElements PROTO :DWORD,:DWORD
GetPS2ColorRenderingDictionary PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPS2ColorRenderingIntent PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetPS2ColorSpaceArray PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetStandardColorSpaceProfileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetStandardColorSpaceProfile equ <GetStandardColorSpaceProfileA>

InstallColorProfileA PROTO :DWORD,:DWORD
InstallColorProfile equ <InstallColorProfileA>

IsColorProfileTagPresent PROTO :DWORD,:DWORD,:DWORD
IsColorProfileValid PROTO :DWORD,:DWORD
OpenColorProfileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
OpenColorProfile equ <OpenColorProfileA>

RegisterCMMA PROTO :DWORD,:DWORD,:DWORD
RegisterCMM equ <RegisterCMMA>

SelectCMM PROTO :DWORD
SetColorProfileElement PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetColorProfileElementReference PROTO :DWORD,:DWORD,:DWORD
SetColorProfileElementSize PROTO :DWORD,:DWORD,:DWORD
SetColorProfileHeader PROTO :DWORD,:DWORD
SetStandardColorSpaceProfileA PROTO :DWORD,:DWORD,:DWORD
SetStandardColorSpaceProfile equ <SetStandardColorSpaceProfileA>

SpoolerCopyFileEvent PROTO :DWORD,:DWORD,:DWORD
TranslateBitmapBits PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TranslateColors PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UninstallColorProfileA PROTO :DWORD,:DWORD,:DWORD
UninstallColorProfile equ <UninstallColorProfileA>

UnregisterCMMA PROTO :DWORD,:DWORD
UnregisterCMM equ <UnregisterCMMA>


