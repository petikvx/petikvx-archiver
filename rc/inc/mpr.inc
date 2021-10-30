; ..\LIB\MPR.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~

I_MprSaveConn PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MultinetGetConnectionPerformanceA PROTO :DWORD,:DWORD
MultinetGetConnectionPerformance equ <MultinetGetConnectionPerformanceA>

MultinetGetErrorTextA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MultinetGetErrorText equ <MultinetGetErrorTextA>

RestoreConnectionA0 PROTO :DWORD,:DWORD
WNetAddConnection2A PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetAddConnection2 equ <WNetAddConnection2A>

WNetAddConnection3A PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetAddConnection3 equ <WNetAddConnection3A>

WNetAddConnectionA PROTO :DWORD,:DWORD,:DWORD
WNetAddConnection equ <WNetAddConnectionA>

WNetCancelConnection2A PROTO :DWORD,:DWORD,:DWORD
WNetCancelConnection2 equ <WNetCancelConnection2A>

WNetCancelConnectionA PROTO :DWORD,:DWORD
WNetCancelConnection equ <WNetCancelConnectionA>

WNetClearConnections PROTO :DWORD
WNetCloseEnum PROTO :DWORD
WNetConnectionDialog PROTO :DWORD,:DWORD
WNetConnectionDialog1A PROTO :DWORD
WNetConnectionDialog1 equ <WNetConnectionDialog1A>

WNetConnectionDialog2 PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetDirectoryNotifyA PROTO :DWORD,:DWORD,:DWORD
WNetDirectoryNotify equ <WNetDirectoryNotifyA>

WNetDisconnectDialog PROTO :DWORD,:DWORD
WNetDisconnectDialog1A PROTO :DWORD
WNetDisconnectDialog1 equ <WNetDisconnectDialog1A>

WNetDisconnectDialog2 PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetEnumResourceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetEnumResource equ <WNetEnumResourceA>

WNetFMXEditPerm PROTO :DWORD,:DWORD,:DWORD
WNetFMXGetPermCaps PROTO :DWORD
WNetFMXGetPermHelp PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetFormatNetworkNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetFormatNetworkName equ <WNetFormatNetworkNameA>

WNetGetConnection2A PROTO :DWORD,:DWORD,:DWORD
WNetGetConnection2 equ <WNetGetConnection2A>

WNetGetConnection3A PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetGetConnection3 equ <WNetGetConnection3A>

WNetGetConnectionA PROTO :DWORD,:DWORD,:DWORD
WNetGetConnection equ <WNetGetConnectionA>

WNetGetDirectoryTypeA PROTO :DWORD,:DWORD,:DWORD
WNetGetDirectoryType equ <WNetGetDirectoryTypeA>

WNetGetLastErrorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetGetLastError equ <WNetGetLastErrorA>

WNetGetNetworkInformationA PROTO :DWORD,:DWORD
WNetGetNetworkInformation equ <WNetGetNetworkInformationA>

WNetGetPropertyTextA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetGetPropertyText equ <WNetGetPropertyTextA>

WNetGetProviderNameA PROTO :DWORD,:DWORD,:DWORD
WNetGetProviderName equ <WNetGetProviderNameA>

WNetGetProviderTypeA PROTO :DWORD,:DWORD
WNetGetProviderType equ <WNetGetProviderTypeA>

WNetGetResourceInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetGetResourceInformation equ <WNetGetResourceInformationA>

WNetGetResourceParentA PROTO :DWORD,:DWORD,:DWORD
WNetGetResourceParent equ <WNetGetResourceParentA>

WNetGetSearchDialog PROTO :DWORD
WNetGetUniversalNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetGetUniversalName equ <WNetGetUniversalNameA>

WNetGetUserA PROTO :DWORD,:DWORD,:DWORD
WNetGetUser equ <WNetGetUserA>

WNetLogonNotify PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetOpenEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetOpenEnum equ <WNetOpenEnumA>

WNetPasswordChangeNotify PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetPropertyDialogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetPropertyDialog equ <WNetPropertyDialogA>

WNetSetConnectionA PROTO :DWORD,:DWORD,:DWORD
WNetSetConnection equ <WNetSetConnectionA>

WNetSetLastErrorA PROTO :DWORD,:DWORD,:DWORD
WNetSetLastError equ <WNetSetLastErrorA>

WNetSupportGlobalEnum PROTO :DWORD
WNetUseConnectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetUseConnection equ <WNetUseConnectionA>


