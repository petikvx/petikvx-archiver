; ..\LIB\RASAPI32.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DDMGetPhonebookInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasAutodialAddressToNetwork PROTO :DWORD,:DWORD,:DWORD
RasAutodialEntryToNetwork PROTO :DWORD,:DWORD,:DWORD
RasConnectionNotificationA PROTO :DWORD,:DWORD,:DWORD
RasConnectionNotification equ <RasConnectionNotificationA>

RasCreatePhonebookEntryA PROTO :DWORD,:DWORD
RasCreatePhonebookEntry equ <RasCreatePhonebookEntryA>

RasDeleteEntryA PROTO :DWORD,:DWORD
RasDeleteEntry equ <RasDeleteEntryA>

RasDialA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasDial equ <RasDialA>

RasDialWow PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasEditPhonebookEntryA PROTO :DWORD,:DWORD,:DWORD
RasEditPhonebookEntry equ <RasEditPhonebookEntryA>

RasEnumAutodialAddressesA PROTO :DWORD,:DWORD,:DWORD
RasEnumAutodialAddresses equ <RasEnumAutodialAddressesA>

RasEnumConnectionsA PROTO :DWORD,:DWORD,:DWORD
RasEnumConnections equ <RasEnumConnectionsA>

RasEnumConnectionsWow PROTO :DWORD,:DWORD,:DWORD
RasEnumDevicesA PROTO :DWORD,:DWORD,:DWORD
RasEnumDevices equ <RasEnumDevicesA>

RasEnumEntriesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasEnumEntries equ <RasEnumEntriesA>

RasEnumEntriesWow PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetAutodialAddressA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetAutodialAddress equ <RasGetAutodialAddressA>

RasGetAutodialEnableA PROTO :DWORD,:DWORD
RasGetAutodialEnable equ <RasGetAutodialEnableA>

RasGetAutodialParamA PROTO :DWORD,:DWORD,:DWORD
RasGetAutodialParam equ <RasGetAutodialParamA>

RasGetConnectResponse PROTO :DWORD,:DWORD
RasGetConnectStatusA PROTO :DWORD,:DWORD
RasGetConnectStatus equ <RasGetConnectStatusA>

RasGetConnectStatusWow PROTO :DWORD,:DWORD
RasGetCountryInfoA PROTO :DWORD,:DWORD
RasGetCountryInfo equ <RasGetCountryInfoA>

RasGetCredentialsA PROTO :DWORD,:DWORD,:DWORD
RasGetCredentials equ <RasGetCredentialsA>

RasGetEntryDialParamsA PROTO :DWORD,:DWORD,:DWORD
RasGetEntryDialParams equ <RasGetEntryDialParamsA>

RasGetEntryPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetEntryProperties equ <RasGetEntryPropertiesA>

RasGetErrorStringA PROTO :DWORD,:DWORD,:DWORD
RasGetErrorString equ <RasGetErrorStringA>

RasGetErrorStringWow PROTO :DWORD,:DWORD,:DWORD
RasGetHport PROTO :DWORD
RasGetProjectionInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasGetProjectionInfo equ <RasGetProjectionInfoA>

RasGetSubEntryHandleA PROTO :DWORD,:DWORD,:DWORD
RasGetSubEntryHandle equ <RasGetSubEntryHandleA>

RasGetSubEntryPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetSubEntryProperties equ <RasGetSubEntryPropertiesA>

RasHangUpA PROTO :DWORD
RasHangUp equ <RasHangUpA>

RasHangUpWow PROTO :DWORD
RasIsRouterConnection PROTO :DWORD
RasRenameEntryA PROTO :DWORD,:DWORD,:DWORD
RasRenameEntry equ <RasRenameEntryA>

RasSetAutodialAddressA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasSetAutodialAddress equ <RasSetAutodialAddressA>

RasSetAutodialEnableA PROTO :DWORD,:DWORD
RasSetAutodialEnable equ <RasSetAutodialEnableA>

RasSetAutodialParamA PROTO :DWORD,:DWORD,:DWORD
RasSetAutodialParam equ <RasSetAutodialParamA>

RasSetCredentialsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasSetCredentials equ <RasSetCredentialsA>

RasSetEntryDialParamsA PROTO :DWORD,:DWORD,:DWORD
RasSetEntryDialParams equ <RasSetEntryDialParamsA>

RasSetEntryPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasSetEntryProperties equ <RasSetEntryPropertiesA>

RasSetOldPassword PROTO :DWORD,:DWORD
RasSetSubEntryPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasSetSubEntryProperties equ <RasSetSubEntryPropertiesA>

RasValidateEntryNameA PROTO :DWORD,:DWORD
RasValidateEntryName equ <RasValidateEntryNameA>


