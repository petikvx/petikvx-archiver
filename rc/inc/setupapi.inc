; ..\LIB\SETUPAPI.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

AcquireSCMLock PROTO :DWORD,:DWORD
AddMiniIconToList PROTO :DWORD,:DWORD
AddTagToGroupOrderListEntry PROTO :DWORD,:DWORD,:DWORD
AppendStringToMultiSz PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AssertFail PROTO :DWORD,:DWORD,:DWORD
CaptureAndConvertAnsiArg PROTO :DWORD,:DWORD
CaptureStringArg PROTO :DWORD,:DWORD
CenterWindowRelativeToParent PROTO :DWORD
ConcatenatePaths PROTO :DWORD,:DWORD,:DWORD,:DWORD
DelayedMove PROTO :DWORD,:DWORD
DelimStringToMultiSz PROTO :DWORD,:DWORD,:DWORD
DestroyTextFileReadBuffer PROTO :DWORD
DoInstallActionWithParams PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DoesUserHavePrivilege PROTO :DWORD
DuplicateString PROTO :DWORD
EnablePrivilege PROTO :DWORD,:DWORD
ExtensionPropSheetPageProc PROTO :DWORD,:DWORD,:DWORD
FileExists PROTO :DWORD,:DWORD
FreeStringArray PROTO :DWORD,:DWORD
GetNewInfName PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetSetFileTimestamp PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetVersionInfoFromImage PROTO :DWORD,:DWORD,:DWORD
InfIsFromOemLocation PROTO :DWORD,:DWORD
InstallHinfSectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
InstallHinfSection equ <InstallHinfSectionA>

InstallStop PROTO :DWORD
IsUserAdmin PROTO
LookUpStringInTable PROTO :DWORD,:DWORD,:DWORD
MemoryInitialize PROTO :DWORD
MultiByteToUnicode PROTO :DWORD,:DWORD
MultiSzFromSearchControl PROTO :DWORD,:DWORD,:DWORD,:DWORD
MyFree PROTO :DWORD
MyGetFileTitle PROTO :DWORD
MyMalloc PROTO :DWORD
MyRealloc PROTO :DWORD,:DWORD
OpenAndMapFileForRead PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OutOfMemory PROTO :DWORD
QueryMultiSzValueToArray PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueryRegistryValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReadAsciiOrUnicodeTextFile PROTO :DWORD,:DWORD
RegistryDelnode PROTO :DWORD,:DWORD
RetreiveFileSecurity PROTO :DWORD,:DWORD
RetrieveServiceConfig PROTO :DWORD,:DWORD
SearchForInfFile PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetArrayToMultiSzValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAddInstallSectionToDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAddInstallSectionToDiskSpaceList equ <SetupAddInstallSectionToDiskSpaceListA>

SetupAddSectionToDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAddSectionToDiskSpaceList equ <SetupAddSectionToDiskSpaceListA>

SetupAddToDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAddToDiskSpaceList equ <SetupAddToDiskSpaceListA>

SetupAddToSourceListA PROTO :DWORD,:DWORD
SetupAddToSourceList equ <SetupAddToSourceListA>

SetupAdjustDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAdjustDiskSpaceList equ <SetupAdjustDiskSpaceListA>

SetupCancelTemporarySourceList PROTO
SetupCloseFileQueue PROTO :DWORD
SetupCloseInfFile PROTO :DWORD
SetupCloseLog PROTO
SetupCommitFileQueueA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupCommitFileQueue equ <SetupCommitFileQueueA>

SetupCopyErrorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupCopyError equ <SetupCopyErrorA>

SetupCopyOEMInfA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupCopyOEMInf equ <SetupCopyOEMInfA>

SetupCreateDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD
SetupCreateDiskSpaceList equ <SetupCreateDiskSpaceListA>

SetupDecompressOrCopyFileA PROTO :DWORD,:DWORD,:DWORD
SetupDecompressOrCopyFile equ <SetupDecompressOrCopyFileA>

SetupDefaultQueueCallbackA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDefaultQueueCallback equ <SetupDefaultQueueCallbackA>

SetupDeleteErrorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDeleteError equ <SetupDeleteErrorA>

SetupDestroyDiskSpaceList PROTO :DWORD
SetupDiAskForOEMDisk PROTO :DWORD,:DWORD
SetupDiBuildClassInfoList PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiBuildClassInfoListExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiBuildClassInfoListEx equ <SetupDiBuildClassInfoListExA>

SetupDiBuildDriverInfoList PROTO :DWORD,:DWORD,:DWORD
SetupDiCallClassInstaller PROTO :DWORD,:DWORD,:DWORD
SetupDiCancelDriverInfoSearch PROTO :DWORD
SetupDiChangeState PROTO :DWORD,:DWORD
SetupDiClassGuidsFromNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiClassGuidsFromName equ <SetupDiClassGuidsFromNameA>

SetupDiClassGuidsFromNameExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiClassGuidsFromNameEx equ <SetupDiClassGuidsFromNameExA>

SetupDiClassNameFromGuidA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiClassNameFromGuid equ <SetupDiClassNameFromGuidA>

SetupDiClassNameFromGuidExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiClassNameFromGuidEx equ <SetupDiClassNameFromGuidExA>

SetupDiCreateDevRegKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDevRegKey equ <SetupDiCreateDevRegKeyA>

SetupDiCreateDeviceInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInfo equ <SetupDiCreateDeviceInfoA>

SetupDiCreateDeviceInfoList PROTO :DWORD,:DWORD
SetupDiCreateDeviceInfoListExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInfoListEx equ <SetupDiCreateDeviceInfoListExA>

SetupDiCreateDeviceInterfaceA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInterface equ <SetupDiCreateDeviceInterfaceA>

SetupDiCreateDeviceInterfaceRegKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInterfaceRegKey equ <SetupDiCreateDeviceInterfaceRegKeyA>

SetupDiDeleteDevRegKey PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiDeleteDeviceInfo PROTO :DWORD,:DWORD
SetupDiDeleteDeviceInterfaceData PROTO :DWORD,:DWORD
SetupDiDeleteDeviceInterfaceRegKey PROTO :DWORD,:DWORD,:DWORD
SetupDiDestroyClassImageList PROTO :DWORD
SetupDiDestroyDeviceInfoList PROTO :DWORD
SetupDiDestroyDriverInfoList PROTO :DWORD,:DWORD,:DWORD
SetupDiDrawMiniIcon PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiEnumDeviceInfo PROTO :DWORD,:DWORD,:DWORD
SetupDiEnumDeviceInterfaces PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiEnumDriverInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiEnumDriverInfo equ <SetupDiEnumDriverInfoA>

SetupDiGetActualSectionToInstallA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetActualSectionToInstall equ <SetupDiGetActualSectionToInstallA>

SetupDiGetClassBitmapIndex PROTO :DWORD,:DWORD
SetupDiGetClassDescriptionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDescription equ <SetupDiGetClassDescriptionA>

SetupDiGetClassDescriptionExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDescriptionEx equ <SetupDiGetClassDescriptionExA>

SetupDiGetClassDevPropertySheetsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDevPropertySheets equ <SetupDiGetClassDevPropertySheetsA>

SetupDiGetClassDevsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDevs equ <SetupDiGetClassDevsA>

SetupDiGetClassDevsExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDevsEx equ <SetupDiGetClassDevsExA>

SetupDiGetClassImageIndex PROTO :DWORD,:DWORD,:DWORD
SetupDiGetClassImageList PROTO :DWORD
SetupDiGetClassImageListExA PROTO :DWORD,:DWORD,:DWORD
SetupDiGetClassImageListEx equ <SetupDiGetClassImageListExA>

SetupDiGetClassInstallParamsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassInstallParams equ <SetupDiGetClassInstallParamsA>

SetupDiGetDeviceInfoListClass PROTO :DWORD,:DWORD
SetupDiGetDeviceInfoListDetailA PROTO :DWORD,:DWORD
SetupDiGetDeviceInfoListDetail equ <SetupDiGetDeviceInfoListDetailA>

SetupDiGetDeviceInstallParamsA PROTO :DWORD,:DWORD,:DWORD
SetupDiGetDeviceInstallParams equ <SetupDiGetDeviceInstallParamsA>

SetupDiGetDeviceInstanceIdA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDeviceInstanceId equ <SetupDiGetDeviceInstanceIdA>

SetupDiGetDeviceInterfaceAlias PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDeviceInterfaceDetailA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDeviceInterfaceDetail equ <SetupDiGetDeviceInterfaceDetailA>

SetupDiGetDeviceRegistryPropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDeviceRegistryProperty equ <SetupDiGetDeviceRegistryPropertyA>

SetupDiGetDriverInfoDetailA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDriverInfoDetail equ <SetupDiGetDriverInfoDetailA>

SetupDiGetDriverInstallParamsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDriverInstallParams equ <SetupDiGetDriverInstallParamsA>

SetupDiGetHwProfileFriendlyNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetHwProfileFriendlyName equ <SetupDiGetHwProfileFriendlyNameA>

SetupDiGetHwProfileFriendlyNameExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetHwProfileFriendlyNameEx equ <SetupDiGetHwProfileFriendlyNameExA>

SetupDiGetHwProfileList PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetHwProfileListExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetHwProfileListEx equ <SetupDiGetHwProfileListExA>

SetupDiGetINFClassA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetINFClass equ <SetupDiGetINFClassA>

SetupDiGetSelectedDevice PROTO :DWORD,:DWORD
SetupDiGetSelectedDriverA PROTO :DWORD,:DWORD,:DWORD
SetupDiGetSelectedDriver equ <SetupDiGetSelectedDriverA>

SetupDiGetWizardPage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiInstallClassA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiInstallClass equ <SetupDiInstallClassA>

SetupDiInstallClassExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiInstallClassEx equ <SetupDiInstallClassExA>

SetupDiInstallDevice PROTO :DWORD,:DWORD
SetupDiInstallDeviceInterfaces PROTO :DWORD,:DWORD
SetupDiInstallDriverFiles PROTO :DWORD,:DWORD
SetupDiLoadClassIcon PROTO :DWORD,:DWORD,:DWORD
SetupDiMoveDuplicateDevice PROTO :DWORD,:DWORD
SetupDiOpenClassRegKey PROTO :DWORD,:DWORD
SetupDiOpenClassRegKeyExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiOpenClassRegKeyEx equ <SetupDiOpenClassRegKeyExA>

SetupDiOpenDevRegKey PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiOpenDeviceInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiOpenDeviceInfo equ <SetupDiOpenDeviceInfoA>

SetupDiOpenDeviceInterfaceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiOpenDeviceInterface equ <SetupDiOpenDeviceInterfaceA>

SetupDiOpenDeviceInterfaceRegKey PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiRegisterCoDeviceInstallers PROTO :DWORD,:DWORD
SetupDiRegisterDeviceInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiRemoveDevice PROTO :DWORD,:DWORD
SetupDiRemoveDeviceInterface PROTO :DWORD,:DWORD
SetupDiSelectBestCompatDrv PROTO :DWORD,:DWORD
SetupDiSelectDevice PROTO :DWORD,:DWORD
SetupDiSelectOEMDrv PROTO :DWORD,:DWORD,:DWORD
SetupDiSetClassInstallParamsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiSetClassInstallParams equ <SetupDiSetClassInstallParamsA>

SetupDiSetDeviceInstallParamsA PROTO :DWORD,:DWORD,:DWORD
SetupDiSetDeviceInstallParams equ <SetupDiSetDeviceInstallParamsA>

SetupDiSetDeviceRegistryPropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiSetDeviceRegistryProperty equ <SetupDiSetDeviceRegistryPropertyA>

SetupDiSetDriverInstallParamsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiSetDriverInstallParams equ <SetupDiSetDriverInstallParamsA>

SetupDiSetSelectedDevice PROTO :DWORD,:DWORD
SetupDiSetSelectedDriverA PROTO :DWORD,:DWORD,:DWORD
SetupDiSetSelectedDriver equ <SetupDiSetSelectedDriverA>

SetupDiUnremoveDevice PROTO :DWORD,:DWORD
SetupDuplicateDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDuplicateDiskSpaceList equ <SetupDuplicateDiskSpaceListA>

SetupFindFirstLineA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupFindFirstLine equ <SetupFindFirstLineA>

SetupFindNextLine PROTO :DWORD,:DWORD
SetupFindNextMatchLineA PROTO :DWORD,:DWORD,:DWORD
SetupFindNextMatchLine equ <SetupFindNextMatchLineA>

SetupFreeSourceListA PROTO :DWORD,:DWORD
SetupFreeSourceList equ <SetupFreeSourceListA>

SetupGetBinaryField PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetFieldCount PROTO :DWORD
SetupGetFileCompressionInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetFileCompressionInfo equ <SetupGetFileCompressionInfoA>

SetupGetInfFileListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetInfFileList equ <SetupGetInfFileListA>

SetupGetInfInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetInfInformation equ <SetupGetInfInformationA>

SetupGetInfSections PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupGetIntField PROTO :DWORD,:DWORD,:DWORD
SetupGetLineByIndexA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupGetLineByIndex equ <SetupGetLineByIndexA>

SetupGetLineCountA PROTO :DWORD,:DWORD
SetupGetLineCount equ <SetupGetLineCountA>

SetupGetLineTextA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetLineText equ <SetupGetLineTextA>

SetupGetMultiSzFieldA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetMultiSzField equ <SetupGetMultiSzFieldA>

SetupGetSourceFileLocationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetSourceFileLocation equ <SetupGetSourceFileLocationA>

SetupGetSourceFileSizeA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetSourceFileSize equ <SetupGetSourceFileSizeA>

SetupGetSourceInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetSourceInfo equ <SetupGetSourceInfoA>

SetupGetStringFieldA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetStringField equ <SetupGetStringFieldA>

SetupGetTargetPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetTargetPath equ <SetupGetTargetPathA>

SetupInitDefaultQueueCallback PROTO :DWORD
SetupInitDefaultQueueCallbackEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInitializeFileLogA PROTO :DWORD,:DWORD
SetupInitializeFileLog equ <SetupInitializeFileLogA>

SetupInstallFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallFile equ <SetupInstallFileA>

SetupInstallFileExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallFileEx equ <SetupInstallFileExA>

SetupInstallFilesFromInfSectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallFilesFromInfSection equ <SetupInstallFilesFromInfSectionA>

SetupInstallFromInfSectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallFromInfSection equ <SetupInstallFromInfSectionA>

SetupInstallServicesFromInfSectionA PROTO :DWORD,:DWORD,:DWORD
SetupInstallServicesFromInfSection equ <SetupInstallServicesFromInfSectionA>

SetupInstallServicesFromInfSectionExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallServicesFromInfSectionEx equ <SetupInstallServicesFromInfSectionExA>

SetupIterateCabinetA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupIterateCabinet equ <SetupIterateCabinetA>

SetupLogErrorA PROTO :DWORD,:DWORD
SetupLogError equ <SetupLogErrorA>

SetupLogFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupLogFile equ <SetupLogFileA>

SetupOpenAppendInfFileA PROTO :DWORD,:DWORD,:DWORD
SetupOpenAppendInfFile equ <SetupOpenAppendInfFileA>

SetupOpenFileQueue PROTO
SetupOpenInfFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupOpenInfFile equ <SetupOpenInfFileA>

SetupOpenLog PROTO :DWORD
SetupOpenMasterInf PROTO
SetupPromptForDiskA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupPromptForDisk equ <SetupPromptForDiskA>

SetupPromptReboot PROTO :DWORD,:DWORD,:DWORD
SetupQueryDrivesInDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupQueryDrivesInDiskSpaceList equ <SetupQueryDrivesInDiskSpaceListA>

SetupQueryFileLogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueryFileLog equ <SetupQueryFileLogA>

SetupQueryInfFileInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueryInfFileInformation equ <SetupQueryInfFileInformationA>

SetupQueryInfVersionInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueryInfVersionInformation equ <SetupQueryInfVersionInformationA>

SetupQuerySourceListA PROTO :DWORD,:DWORD,:DWORD
SetupQuerySourceList equ <SetupQuerySourceListA>

SetupQuerySpaceRequiredOnDriveA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQuerySpaceRequiredOnDrive equ <SetupQuerySpaceRequiredOnDriveA>

SetupQueueCopyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueCopy equ <SetupQueueCopyA>

SetupQueueCopySectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueCopySection equ <SetupQueueCopySectionA>

SetupQueueDefaultCopyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueDefaultCopy equ <SetupQueueDefaultCopyA>

SetupQueueDeleteA PROTO :DWORD,:DWORD,:DWORD
SetupQueueDelete equ <SetupQueueDeleteA>

SetupQueueDeleteSectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupQueueDeleteSection equ <SetupQueueDeleteSectionA>

SetupQueueRenameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueRename equ <SetupQueueRenameA>

SetupQueueRenameSectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupQueueRenameSection equ <SetupQueueRenameSectionA>

SetupRemoveFileLogEntryA PROTO :DWORD,:DWORD,:DWORD
SetupRemoveFileLogEntry equ <SetupRemoveFileLogEntryA>

SetupRemoveFromDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRemoveFromDiskSpaceList equ <SetupRemoveFromDiskSpaceListA>

SetupRemoveFromSourceListA PROTO :DWORD,:DWORD
SetupRemoveFromSourceList equ <SetupRemoveFromSourceListA>

SetupRemoveInstallSectionFromDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRemoveInstallSectionFromDiskSpaceList equ <SetupRemoveInstallSectionFromDiskSpaceListA>

SetupRemoveSectionFromDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRemoveSectionFromDiskSpaceList equ <SetupRemoveSectionFromDiskSpaceListA>

SetupRenameErrorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRenameError equ <SetupRenameErrorA>

SetupScanFileQueueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupScanFileQueue equ <SetupScanFileQueueA>

SetupSetDirectoryIdA PROTO :DWORD,:DWORD,:DWORD
SetupSetDirectoryId equ <SetupSetDirectoryIdA>

SetupSetDirectoryIdExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupSetDirectoryIdEx equ <SetupSetDirectoryIdExA>

SetupSetPlatformPathOverrideA PROTO :DWORD
SetupSetPlatformPathOverride equ <SetupSetPlatformPathOverrideA>

SetupSetSourceListA PROTO :DWORD,:DWORD,:DWORD
SetupSetSourceList equ <SetupSetSourceListA>

SetupTermDefaultQueueCallback PROTO :DWORD
SetupTerminateFileLog PROTO :DWORD
ShouldDeviceBeExcluded PROTO :DWORD,:DWORD,:DWORD
StampFileSecurity PROTO :DWORD,:DWORD
StringTableAddString PROTO :DWORD,:DWORD,:DWORD
StringTableAddStringEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StringTableDestroy PROTO :DWORD
StringTableDuplicate PROTO :DWORD
StringTableEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StringTableGetExtraData PROTO :DWORD,:DWORD,:DWORD,:DWORD
StringTableInitialize PROTO
StringTableInitializeEx PROTO :DWORD,:DWORD
StringTableLookUpString PROTO :DWORD,:DWORD,:DWORD
StringTableLookUpStringEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StringTableSetExtraData PROTO :DWORD,:DWORD,:DWORD,:DWORD
StringTableStringFromId PROTO :DWORD,:DWORD
StringTableTrim PROTO :DWORD
TakeOwnershipOfFile PROTO :DWORD
UnicodeToMultiByte PROTO :DWORD,:DWORD
UnmapAndCloseFile PROTO :DWORD,:DWORD,:DWORD
pSetupDiGetDeviceInfoContext PROTO :DWORD,:DWORD,:DWORD
pSetupDiSetDeviceInfoContext PROTO :DWORD,:DWORD,:DWORD
pSetupDirectoryIdToPath PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
pSetupGetField PROTO :DWORD,:DWORD
pSetupGetOsLoaderDriveAndPath PROTO :DWORD,:DWORD,:DWORD,:DWORD
pSetupGetVersionDatum PROTO :DWORD,:DWORD
pSetupGuidFromString PROTO :DWORD,:DWORD
pSetupIsGuidNull PROTO :DWORD
pSetupMakeSurePathExists PROTO :DWORD
pSetupSetSystemSourcePath PROTO :DWORD
pSetupStringFromGuid PROTO :DWORD,:DWORD,:DWORD

