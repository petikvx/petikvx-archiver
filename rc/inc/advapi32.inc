; ..\LIB\ADVAPI32.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

AbortSystemShutdownA PROTO :DWORD
AbortSystemShutdown equ <AbortSystemShutdownA>

AccessCheck PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessCheckAndAuditAlarmA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessCheckAndAuditAlarm equ <AccessCheckAndAuditAlarmA>

AccessCheckByType PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessCheckByTypeAndAuditAlarmA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessCheckByTypeAndAuditAlarm equ <AccessCheckByTypeAndAuditAlarmA>

AccessCheckByTypeResultList PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessCheckByTypeResultListAndAuditAlarmA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessCheckByTypeResultListAndAuditAlarm equ <AccessCheckByTypeResultListAndAuditAlarmA>

AddAccessAllowedAce PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddAccessAllowedAceEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAccessAllowedObjectAce PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAccessDeniedAce PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddAccessDeniedAceEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAccessDeniedObjectAce PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAce PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAuditAccessAce PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAuditAccessAceEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddAuditAccessObjectAce PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AdjustTokenGroups PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AdjustTokenPrivileges PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AllocateAndInitializeSid PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AllocateLocallyUniqueId PROTO :DWORD
AreAllAccessesGranted PROTO :DWORD,:DWORD
AreAnyAccessesGranted PROTO :DWORD,:DWORD
BackupEventLogA PROTO :DWORD,:DWORD
BackupEventLog equ <BackupEventLogA>

BuildExplicitAccessWithNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BuildExplicitAccessWithName equ <BuildExplicitAccessWithNameA>

BuildImpersonateExplicitAccessWithNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BuildImpersonateExplicitAccessWithName equ <BuildImpersonateExplicitAccessWithNameA>

BuildImpersonateTrusteeA PROTO :DWORD,:DWORD
BuildImpersonateTrustee equ <BuildImpersonateTrusteeA>

BuildSecurityDescriptorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BuildSecurityDescriptor equ <BuildSecurityDescriptorA>

BuildTrusteeWithNameA PROTO :DWORD,:DWORD
BuildTrusteeWithName equ <BuildTrusteeWithNameA>

BuildTrusteeWithSidA PROTO :DWORD,:DWORD
BuildTrusteeWithSid equ <BuildTrusteeWithSidA>

CancelOverlappedAccess PROTO :DWORD
ChangeServiceConfig2A PROTO :DWORD,:DWORD,:DWORD
ChangeServiceConfig2 equ <ChangeServiceConfig2A>

ChangeServiceConfigA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ChangeServiceConfig equ <ChangeServiceConfigA>

ClearEventLogA PROTO :DWORD,:DWORD
ClearEventLog equ <ClearEventLogA>

CloseEventLog PROTO :DWORD
CloseRaw PROTO :DWORD
CloseServiceHandle PROTO :DWORD
ControlService PROTO :DWORD,:DWORD,:DWORD
ConvertAccessToSecurityDescriptorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ConvertAccessToSecurityDescriptor equ <ConvertAccessToSecurityDescriptorA>

ConvertSecurityDescriptorToAccessA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ConvertSecurityDescriptorToAccess equ <ConvertSecurityDescriptorToAccessA>

ConvertSecurityDescriptorToAccessNamedA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ConvertSecurityDescriptorToAccessNamed equ <ConvertSecurityDescriptorToAccessNamedA>

ConvertToAutoInheritPrivateObjectSecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CopySid PROTO :DWORD,:DWORD,:DWORD
CreatePrivateObjectSecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreatePrivateObjectSecurityEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateProcessAsUserA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateProcessAsUser equ <CreateProcessAsUserA>

CreateRestrictedToken PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateServiceA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateService equ <CreateServiceA>

CryptAcquireContextA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptAcquireContext equ <CryptAcquireContextA>

CryptContextAddRef PROTO :DWORD,:DWORD,:DWORD
CryptCreateHash PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptDecrypt PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptDeriveKey PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptDestroyHash PROTO :DWORD
CryptDestroyKey PROTO :DWORD
CryptDuplicateHash PROTO :DWORD,:DWORD,:DWORD,:DWORD
CryptDuplicateKey PROTO :DWORD,:DWORD,:DWORD,:DWORD
CryptEncrypt PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptEnumProviderTypesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptEnumProviderTypes equ <CryptEnumProviderTypesA>

CryptEnumProvidersA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptEnumProviders equ <CryptEnumProvidersA>

CryptExportKey PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGenKey PROTO :DWORD,:DWORD,:DWORD,:DWORD
CryptGenRandom PROTO :DWORD,:DWORD,:DWORD
CryptGetDefaultProviderA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGetDefaultProvider equ <CryptGetDefaultProviderA>

CryptGetHashParam PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGetKeyParam PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGetProvParam PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGetUserKey PROTO :DWORD,:DWORD,:DWORD
CryptHashData PROTO :DWORD,:DWORD,:DWORD,:DWORD
CryptHashSessionKey PROTO :DWORD,:DWORD,:DWORD
CryptImportKey PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptReleaseContext PROTO :DWORD,:DWORD
CryptSetHashParam PROTO :DWORD,:DWORD,:DWORD,:DWORD
CryptSetKeyParam PROTO :DWORD,:DWORD,:DWORD,:DWORD
CryptSetProvParam PROTO :DWORD,:DWORD,:DWORD,:DWORD
CryptSetProviderA PROTO :DWORD,:DWORD
CryptSetProvider equ <CryptSetProviderA>

CryptSetProviderExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CryptSetProviderEx equ <CryptSetProviderExA>

CryptSignHashA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptSignHash equ <CryptSignHashA>

CryptVerifySignatureA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptVerifySignature equ <CryptVerifySignatureA>

DecryptFileA PROTO :DWORD,:DWORD
DecryptFile equ <DecryptFileA>

DeleteAce PROTO :DWORD,:DWORD
DeleteService PROTO :DWORD
DeregisterEventSource PROTO :DWORD
DestroyPrivateObjectSecurity PROTO :DWORD
DuplicateToken PROTO :DWORD,:DWORD,:DWORD
DuplicateTokenEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ElfBackupEventLogFileA PROTO :DWORD,:DWORD
ElfBackupEventLogFile equ <ElfBackupEventLogFileA>

ElfChangeNotify PROTO :DWORD,:DWORD
ElfClearEventLogFileA PROTO :DWORD,:DWORD
ElfClearEventLogFile equ <ElfClearEventLogFileA>

ElfCloseEventLog PROTO :DWORD
ElfDeregisterEventSource PROTO :DWORD
ElfNumberOfRecords PROTO :DWORD,:DWORD
ElfOldestRecord PROTO :DWORD,:DWORD
ElfOpenBackupEventLogA PROTO :DWORD,:DWORD,:DWORD
ElfOpenBackupEventLog equ <ElfOpenBackupEventLogA>

ElfOpenEventLogA PROTO :DWORD,:DWORD,:DWORD
ElfOpenEventLog equ <ElfOpenEventLogA>

ElfReadEventLogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ElfReadEventLog equ <ElfReadEventLogA>

ElfRegisterEventSourceA PROTO :DWORD,:DWORD,:DWORD
ElfRegisterEventSource equ <ElfRegisterEventSourceA>

ElfReportEventA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ElfReportEvent equ <ElfReportEventA>

EncryptFileA PROTO :DWORD
EncryptFile equ <EncryptFileA>

EnumDependentServicesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumDependentServices equ <EnumDependentServicesA>

EnumServicesStatusA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumServicesStatus equ <EnumServicesStatusA>

EqualPrefixSid PROTO :DWORD,:DWORD
EqualSid PROTO :DWORD,:DWORD
FindFirstFreeAce PROTO :DWORD,:DWORD
FreeSid PROTO :DWORD
GetAccessPermissionsForObjectA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAccessPermissionsForObject equ <GetAccessPermissionsForObjectA>

GetAce PROTO :DWORD,:DWORD,:DWORD
GetAclInformation PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetAuditedPermissionsFromAclA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetAuditedPermissionsFromAcl equ <GetAuditedPermissionsFromAclA>

GetCurrentHwProfileA PROTO :DWORD
GetCurrentHwProfile equ <GetCurrentHwProfileA>

GetEffectiveRightsFromAclA PROTO :DWORD,:DWORD,:DWORD
GetEffectiveRightsFromAcl equ <GetEffectiveRightsFromAclA>

GetExplicitEntriesFromAclA PROTO :DWORD,:DWORD,:DWORD
GetExplicitEntriesFromAcl equ <GetExplicitEntriesFromAclA>

GetFileSecurityA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetFileSecurity equ <GetFileSecurityA>

GetKernelObjectSecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetLengthSid PROTO :DWORD
GetMultipleTrusteeA PROTO :DWORD
GetMultipleTrustee equ <GetMultipleTrusteeA>

GetMultipleTrusteeOperationA PROTO :DWORD
GetMultipleTrusteeOperation equ <GetMultipleTrusteeOperationA>

GetNamedSecurityInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetNamedSecurityInfo equ <GetNamedSecurityInfoA>

GetNamedSecurityInfoExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetNamedSecurityInfoEx equ <GetNamedSecurityInfoExA>

GetNumberOfEventLogRecords PROTO :DWORD,:DWORD
GetOldestEventLogRecord PROTO :DWORD,:DWORD
GetOverlappedAccessResults PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetPrivateObjectSecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetSecurityDescriptorControl PROTO :DWORD,:DWORD,:DWORD
GetSecurityDescriptorDacl PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetSecurityDescriptorGroup PROTO :DWORD,:DWORD,:DWORD
GetSecurityDescriptorLength PROTO :DWORD
GetSecurityDescriptorOwner PROTO :DWORD,:DWORD,:DWORD
GetSecurityDescriptorSacl PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetSecurityInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetSecurityInfoExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetSecurityInfoEx equ <GetSecurityInfoExA>

GetServiceDisplayNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetServiceDisplayName equ <GetServiceDisplayNameA>

GetServiceKeyNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetServiceKeyName equ <GetServiceKeyNameA>

GetSidIdentifierAuthority PROTO :DWORD
GetSidLengthRequired PROTO :DWORD
GetSidSubAuthority PROTO :DWORD,:DWORD
GetSidSubAuthorityCount PROTO :DWORD
GetTokenInformation PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetTrusteeNameA PROTO :DWORD
GetTrusteeName equ <GetTrusteeNameA>

GetTrusteeTypeA PROTO :DWORD
GetTrusteeType equ <GetTrusteeTypeA>

GetUserNameA PROTO :DWORD,:DWORD
GetUserName equ <GetUserNameA>

I_ScSetServiceBitsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_ScSetServiceBits equ <I_ScSetServiceBitsA>

ImpersonateLoggedOnUser PROTO :DWORD
ImpersonateNamedPipeClient PROTO :DWORD
ImpersonateSelf PROTO :DWORD
InitializeAcl PROTO :DWORD,:DWORD,:DWORD
InitializeSecurityDescriptor PROTO :DWORD,:DWORD
InitializeSid PROTO :DWORD,:DWORD,:DWORD
InitiateSystemShutdownA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InitiateSystemShutdown equ <InitiateSystemShutdownA>

IsTextUnicode PROTO :DWORD,:DWORD,:DWORD
IsTokenRestricted PROTO :DWORD
IsValidAcl PROTO :DWORD
IsValidSecurityDescriptor PROTO :DWORD
IsValidSid PROTO :DWORD
LockServiceDatabase PROTO :DWORD
LogonUserA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LogonUser equ <LogonUserA>

LookupAccountNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LookupAccountName equ <LookupAccountNameA>

LookupAccountSidA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LookupAccountSid equ <LookupAccountSidA>

LookupPrivilegeDisplayNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LookupPrivilegeDisplayName equ <LookupPrivilegeDisplayNameA>

LookupPrivilegeNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
LookupPrivilegeName equ <LookupPrivilegeNameA>

LookupPrivilegeValueA PROTO :DWORD,:DWORD,:DWORD
LookupPrivilegeValue equ <LookupPrivilegeValueA>

LookupSecurityDescriptorPartsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LookupSecurityDescriptorParts equ <LookupSecurityDescriptorPartsA>

LsaAddAccountRights PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaAddPrivilegesToAccount PROTO :DWORD,:DWORD
LsaClearAuditLog PROTO :DWORD
LsaClose PROTO :DWORD
LsaCreateAccount PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaCreateSecret PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaCreateTrustedDomain PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaCreateTrustedDomainEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaDelete PROTO :DWORD
LsaDeleteTrustedDomain PROTO :DWORD,:DWORD
LsaEnumerateAccountRights PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaEnumerateAccounts PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaEnumerateAccountsWithUserRight PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaEnumeratePrivileges PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaEnumeratePrivilegesOfAccount PROTO :DWORD,:DWORD
LsaEnumerateTrustedDomains PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaEnumerateTrustedDomainsEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaFreeMemory PROTO :DWORD
LsaGetQuotasForAccount PROTO :DWORD,:DWORD
LsaGetSystemAccessAccount PROTO :DWORD,:DWORD
LsaGetUserName PROTO :DWORD,:DWORD
LsaICLookupNames PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaICLookupSids PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaIGetTrustedDomainAuthInfoBlobs PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaISetTrustedDomainAuthInfoBlobs PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaLookupNames PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaLookupPrivilegeDisplayName PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaLookupPrivilegeName PROTO :DWORD,:DWORD,:DWORD
LsaLookupPrivilegeValue PROTO :DWORD,:DWORD,:DWORD
LsaLookupSids PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaNtStatusToWinError PROTO :DWORD
LsaOpenAccount PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaOpenPolicy PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaOpenSecret PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaOpenTrustedDomain PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaQueryDomainInformationPolicy PROTO :DWORD,:DWORD,:DWORD
LsaQueryInfoTrustedDomain PROTO :DWORD,:DWORD,:DWORD
LsaQueryInformationPolicy PROTO :DWORD,:DWORD,:DWORD
LsaQueryLocalInformationPolicy PROTO :DWORD,:DWORD,:DWORD
LsaQuerySecret PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaQuerySecurityObject PROTO :DWORD,:DWORD,:DWORD
LsaQueryTrustedDomainInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaQueryTrustedDomainInfoByName PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaRemoveAccountRights PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaRemovePrivilegesFromAccount PROTO :DWORD,:DWORD,:DWORD
LsaRetrievePrivateData PROTO :DWORD,:DWORD,:DWORD
LsaSetDomainInformationPolicy PROTO :DWORD,:DWORD,:DWORD
LsaSetInformationPolicy PROTO :DWORD,:DWORD,:DWORD
LsaSetInformationTrustedDomain PROTO :DWORD,:DWORD,:DWORD
LsaSetLocalInformationPolicy PROTO :DWORD,:DWORD,:DWORD
LsaSetQuotasForAccount PROTO :DWORD,:DWORD
LsaSetSecret PROTO :DWORD,:DWORD,:DWORD
LsaSetSecurityObject PROTO :DWORD,:DWORD,:DWORD
LsaSetSystemAccessAccount PROTO :DWORD,:DWORD
LsaSetTrustedDomainInfoByName PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaSetTrustedDomainInformation PROTO :DWORD,:DWORD,:DWORD,:DWORD
LsaStorePrivateData PROTO :DWORD,:DWORD,:DWORD
MakeAbsoluteSD PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MakeSelfRelativeSD PROTO :DWORD,:DWORD,:DWORD
MapGenericMask PROTO :DWORD,:DWORD
NotifyBootConfigStatus PROTO :DWORD
NotifyChangeEventLog PROTO :DWORD,:DWORD
ObjectCloseAuditAlarmA PROTO :DWORD,:DWORD,:DWORD
ObjectCloseAuditAlarm equ <ObjectCloseAuditAlarmA>

ObjectDeleteAuditAlarmA PROTO :DWORD,:DWORD,:DWORD
ObjectDeleteAuditAlarm equ <ObjectDeleteAuditAlarmA>

ObjectOpenAuditAlarmA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ObjectOpenAuditAlarm equ <ObjectOpenAuditAlarmA>

ObjectPrivilegeAuditAlarmA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ObjectPrivilegeAuditAlarm equ <ObjectPrivilegeAuditAlarmA>

OpenBackupEventLogA PROTO :DWORD,:DWORD
OpenBackupEventLog equ <OpenBackupEventLogA>

OpenEventLogA PROTO :DWORD,:DWORD
OpenEventLog equ <OpenEventLogA>

OpenProcessToken PROTO :DWORD,:DWORD,:DWORD
OpenRawA PROTO :DWORD,:DWORD,:DWORD
OpenRaw equ <OpenRawA>

OpenSCManagerA PROTO :DWORD,:DWORD,:DWORD
OpenSCManager equ <OpenSCManagerA>

OpenServiceA PROTO :DWORD,:DWORD,:DWORD
OpenService equ <OpenServiceA>

OpenThreadToken PROTO :DWORD,:DWORD,:DWORD,:DWORD
PrivilegeCheck PROTO :DWORD,:DWORD,:DWORD
PrivilegedServiceAuditAlarmA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PrivilegedServiceAuditAlarm equ <PrivilegedServiceAuditAlarmA>

QueryRecoveryAgentsA PROTO :DWORD,:DWORD,:DWORD
QueryRecoveryAgents equ <QueryRecoveryAgentsA>

QueryServiceConfig2A PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueryServiceConfig2 equ <QueryServiceConfig2A>

QueryServiceConfigA PROTO :DWORD,:DWORD,:DWORD,:DWORD
QueryServiceConfig equ <QueryServiceConfigA>

QueryServiceLockStatusA PROTO :DWORD,:DWORD,:DWORD,:DWORD
QueryServiceLockStatus equ <QueryServiceLockStatusA>

QueryServiceObjectSecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueryServiceStatus PROTO :DWORD,:DWORD
QueryWindows31FilesMigration PROTO :DWORD
ReadEventLogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReadEventLog equ <ReadEventLogA>

ReadRaw PROTO :DWORD,:DWORD,:DWORD
RegCloseKey PROTO :DWORD
RegConnectRegistryA PROTO :DWORD,:DWORD,:DWORD
RegConnectRegistry equ <RegConnectRegistryA>

RegCreateKeyA PROTO :DWORD,:DWORD,:DWORD
RegCreateKey equ <RegCreateKeyA>

RegCreateKeyExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegCreateKeyEx equ <RegCreateKeyExA>

RegDeleteKeyA PROTO :DWORD,:DWORD
RegDeleteKey equ <RegDeleteKeyA>

RegDeleteValueA PROTO :DWORD,:DWORD
RegDeleteValue equ <RegDeleteValueA>

RegEnumKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RegEnumKey equ <RegEnumKeyA>

RegEnumKeyExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegEnumKeyEx equ <RegEnumKeyExA>

RegEnumValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegEnumValue equ <RegEnumValueA>

RegFlushKey PROTO :DWORD
RegGetKeySecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD
RegLoadKeyA PROTO :DWORD,:DWORD,:DWORD
RegLoadKey equ <RegLoadKeyA>

RegNotifyChangeKeyValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegOpenKeyA PROTO :DWORD,:DWORD,:DWORD
RegOpenKey equ <RegOpenKeyA>

RegOpenKeyExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegOpenKeyEx equ <RegOpenKeyExA>

RegOverridePredefKey PROTO :DWORD,:DWORD
RegQueryInfoKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegQueryInfoKey equ <RegQueryInfoKeyA>

RegQueryMultipleValuesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegQueryMultipleValues equ <RegQueryMultipleValuesA>

RegQueryValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RegQueryValue equ <RegQueryValueA>

RegQueryValueExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegQueryValueEx equ <RegQueryValueExA>

RegReplaceKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RegReplaceKey equ <RegReplaceKeyA>

RegRestoreKeyA PROTO :DWORD,:DWORD,:DWORD
RegRestoreKey equ <RegRestoreKeyA>

RegSaveKeyA PROTO :DWORD,:DWORD,:DWORD
RegSaveKey equ <RegSaveKeyA>

RegSetKeySecurity PROTO :DWORD,:DWORD,:DWORD
RegSetValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegSetValue equ <RegSetValueA>

RegSetValueExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegSetValueEx equ <RegSetValueExA>

RegUnLoadKeyA PROTO :DWORD,:DWORD
RegUnLoadKey equ <RegUnLoadKeyA>

RegisterEventSourceA PROTO :DWORD,:DWORD
RegisterEventSource equ <RegisterEventSourceA>

RegisterServiceCtrlHandlerA PROTO :DWORD,:DWORD
RegisterServiceCtrlHandler equ <RegisterServiceCtrlHandlerA>

ReportEventA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReportEvent equ <ReportEventA>

RevertToSelf PROTO
SetAclInformation PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetEntriesInAccessListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetEntriesInAccessList equ <SetEntriesInAccessListA>

SetEntriesInAclA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetEntriesInAcl equ <SetEntriesInAclA>

SetEntriesInAuditListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetEntriesInAuditList equ <SetEntriesInAuditListA>

SetFileSecurityA PROTO :DWORD,:DWORD,:DWORD
SetFileSecurity equ <SetFileSecurityA>

SetKernelObjectSecurity PROTO :DWORD,:DWORD,:DWORD
SetNamedSecurityInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetNamedSecurityInfo equ <SetNamedSecurityInfoA>

SetNamedSecurityInfoExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetNamedSecurityInfoEx equ <SetNamedSecurityInfoExA>

SetPrivateObjectSecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetPrivateObjectSecurityEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetSecurityDescriptorControl PROTO :DWORD,:DWORD,:DWORD
SetSecurityDescriptorDacl PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetSecurityDescriptorGroup PROTO :DWORD,:DWORD,:DWORD
SetSecurityDescriptorOwner PROTO :DWORD,:DWORD,:DWORD
SetSecurityDescriptorSacl PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetSecurityInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetSecurityInfoExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetSecurityInfoEx equ <SetSecurityInfoExA>

SetServiceBits PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetServiceObjectSecurity PROTO :DWORD,:DWORD,:DWORD
SetServiceStatus PROTO :DWORD,:DWORD
SetThreadToken PROTO :DWORD,:DWORD
SetTokenInformation PROTO :DWORD,:DWORD,:DWORD,:DWORD
StartServiceA PROTO :DWORD,:DWORD,:DWORD
StartService equ <StartServiceA>

StartServiceCtrlDispatcherA PROTO :DWORD
StartServiceCtrlDispatcher equ <StartServiceCtrlDispatcherA>

SynchronizeWindows31FilesAndWindowsNTRegistry PROTO :DWORD,:DWORD,:DWORD,:DWORD
SystemFunction001 PROTO :DWORD,:DWORD,:DWORD
SystemFunction002 PROTO :DWORD,:DWORD,:DWORD
SystemFunction003 PROTO :DWORD,:DWORD
SystemFunction004 PROTO :DWORD,:DWORD,:DWORD
SystemFunction005 PROTO :DWORD,:DWORD,:DWORD
SystemFunction006 PROTO :DWORD,:DWORD
SystemFunction007 PROTO :DWORD,:DWORD
SystemFunction008 PROTO :DWORD,:DWORD,:DWORD
SystemFunction009 PROTO :DWORD,:DWORD,:DWORD
SystemFunction010 PROTO :DWORD,:DWORD,:DWORD
SystemFunction011 PROTO :DWORD,:DWORD,:DWORD
SystemFunction012 PROTO :DWORD,:DWORD,:DWORD
SystemFunction013 PROTO :DWORD,:DWORD,:DWORD
SystemFunction014 PROTO :DWORD,:DWORD,:DWORD
SystemFunction015 PROTO :DWORD,:DWORD,:DWORD
SystemFunction016 PROTO :DWORD,:DWORD,:DWORD
SystemFunction017 PROTO :DWORD,:DWORD,:DWORD
SystemFunction018 PROTO :DWORD,:DWORD,:DWORD
SystemFunction019 PROTO :DWORD,:DWORD,:DWORD
SystemFunction020 PROTO :DWORD,:DWORD,:DWORD
SystemFunction021 PROTO :DWORD,:DWORD,:DWORD
SystemFunction022 PROTO :DWORD,:DWORD,:DWORD
SystemFunction023 PROTO :DWORD,:DWORD,:DWORD
SystemFunction024 PROTO :DWORD,:DWORD,:DWORD
SystemFunction025 PROTO :DWORD,:DWORD,:DWORD
SystemFunction026 PROTO :DWORD,:DWORD,:DWORD
SystemFunction027 PROTO :DWORD,:DWORD,:DWORD
SystemFunction028 PROTO :DWORD,:DWORD
SystemFunction029 PROTO :DWORD,:DWORD
SystemFunction030 PROTO :DWORD,:DWORD
SystemFunction031 PROTO :DWORD,:DWORD
SystemFunction032 PROTO :DWORD,:DWORD
SystemFunction033 PROTO :DWORD,:DWORD
TrusteeAccessToObjectA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TrusteeAccessToObject equ <TrusteeAccessToObjectA>

UnlockServiceDatabase PROTO :DWORD
WriteRaw PROTO :DWORD,:DWORD,:DWORD

