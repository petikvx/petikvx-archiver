; ..\LIB\SHLWAPI.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ChrCmpIA PROTO :DWORD,:DWORD
ChrCmpI equ <ChrCmpIA>

GetMenuPosFromID PROTO :DWORD,:DWORD
HashData PROTO :DWORD,:DWORD,:DWORD,:DWORD
IntlStrEqWorkerA PROTO :DWORD,:DWORD,:DWORD,:DWORD
IntlStrEqWorker equ <IntlStrEqWorkerA>

PathAddBackslashA PROTO :DWORD
PathAddBackslash equ <PathAddBackslashA>

PathAddExtensionA PROTO :DWORD,:DWORD
PathAddExtension equ <PathAddExtensionA>

PathAppendA PROTO :DWORD,:DWORD
PathAppend equ <PathAppendA>

PathBuildRootA PROTO :DWORD,:DWORD
PathBuildRoot equ <PathBuildRootA>

PathCanonicalizeA PROTO :DWORD,:DWORD
PathCanonicalize equ <PathCanonicalizeA>

PathCombineA PROTO :DWORD,:DWORD,:DWORD
PathCombine equ <PathCombineA>

PathCommonPrefixA PROTO :DWORD,:DWORD,:DWORD
PathCommonPrefix equ <PathCommonPrefixA>

PathCompactPathA PROTO :DWORD,:DWORD,:DWORD
PathCompactPath equ <PathCompactPathA>

PathCompactPathExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PathCompactPathEx equ <PathCompactPathExA>

PathCreateFromUrlA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PathCreateFromUrl equ <PathCreateFromUrlA>

PathFileExistsA PROTO :DWORD
PathFileExists equ <PathFileExistsA>

PathFindExtensionA PROTO :DWORD
PathFindExtension equ <PathFindExtensionA>

PathFindFileNameA PROTO :DWORD
PathFindFileName equ <PathFindFileNameA>

PathFindNextComponentA PROTO :DWORD
PathFindNextComponent equ <PathFindNextComponentA>

PathFindOnPathA PROTO :DWORD,:DWORD
PathFindOnPath equ <PathFindOnPathA>

PathGetArgsA PROTO :DWORD
PathGetArgs equ <PathGetArgsA>

PathGetCharTypeA PROTO :DWORD
PathGetCharType equ <PathGetCharTypeA>

PathGetDriveNumberA PROTO :DWORD
PathGetDriveNumber equ <PathGetDriveNumberA>

PathIsContentTypeA PROTO :DWORD,:DWORD
PathIsContentType equ <PathIsContentTypeA>

PathIsDirectoryA PROTO :DWORD
PathIsDirectory equ <PathIsDirectoryA>

PathIsFileSpecA PROTO :DWORD
PathIsFileSpec equ <PathIsFileSpecA>

PathIsPrefixA PROTO :DWORD,:DWORD
PathIsPrefix equ <PathIsPrefixA>

PathIsRelativeA PROTO :DWORD
PathIsRelative equ <PathIsRelativeA>

PathIsRootA PROTO :DWORD
PathIsRoot equ <PathIsRootA>

PathIsSameRootA PROTO :DWORD,:DWORD
PathIsSameRoot equ <PathIsSameRootA>

PathIsSystemFolderA PROTO :DWORD,:DWORD
PathIsSystemFolder equ <PathIsSystemFolderA>

PathIsUNCA PROTO :DWORD
PathIsUNC equ <PathIsUNCA>

PathIsUNCServerA PROTO :DWORD
PathIsUNCServer equ <PathIsUNCServerA>

PathIsUNCServerShareA PROTO :DWORD
PathIsUNCServerShare equ <PathIsUNCServerShareA>

PathIsURLA PROTO :DWORD
PathIsURL equ <PathIsURLA>

PathMakePrettyA PROTO :DWORD
PathMakePretty equ <PathMakePrettyA>

PathMakeSystemFolderA PROTO :DWORD
PathMakeSystemFolder equ <PathMakeSystemFolderA>

PathMatchSpecA PROTO :DWORD,:DWORD
PathMatchSpec equ <PathMatchSpecA>

PathParseIconLocationA PROTO :DWORD
PathParseIconLocation equ <PathParseIconLocationA>

PathQuoteSpacesA PROTO :DWORD
PathQuoteSpaces equ <PathQuoteSpacesA>

PathRelativePathToA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PathRelativePathTo equ <PathRelativePathToA>

PathRemoveArgsA PROTO :DWORD
PathRemoveArgs equ <PathRemoveArgsA>

PathRemoveBackslashA PROTO :DWORD
PathRemoveBackslash equ <PathRemoveBackslashA>

PathRemoveBlanksA PROTO :DWORD
PathRemoveBlanks equ <PathRemoveBlanksA>

PathRemoveExtensionA PROTO :DWORD
PathRemoveExtension equ <PathRemoveExtensionA>

PathRemoveFileSpecA PROTO :DWORD
PathRemoveFileSpec equ <PathRemoveFileSpecA>

PathRenameExtensionA PROTO :DWORD,:DWORD
PathRenameExtension equ <PathRenameExtensionA>

PathSearchAndQualifyA PROTO :DWORD,:DWORD,:DWORD
PathSearchAndQualify equ <PathSearchAndQualifyA>

PathSetDlgItemPathA PROTO :DWORD,:DWORD,:DWORD
PathSetDlgItemPath equ <PathSetDlgItemPathA>

PathSkipRootA PROTO :DWORD
PathSkipRoot equ <PathSkipRootA>

PathStripPathA PROTO :DWORD
PathStripPath equ <PathStripPathA>

PathStripToRootA PROTO :DWORD
PathStripToRoot equ <PathStripToRootA>

PathUnmakeSystemFolderA PROTO :DWORD
PathUnmakeSystemFolder equ <PathUnmakeSystemFolderA>

PathUnquoteSpacesA PROTO :DWORD
PathUnquoteSpaces equ <PathUnquoteSpacesA>

SHCreateShellPalette PROTO :DWORD
SHDeleteEmptyKeyA PROTO :DWORD,:DWORD
SHDeleteEmptyKey equ <SHDeleteEmptyKeyA>

SHDeleteKeyA PROTO :DWORD,:DWORD
SHDeleteKey equ <SHDeleteKeyA>

SHDeleteOrphanKeyA PROTO :DWORD,:DWORD
SHDeleteOrphanKey equ <SHDeleteOrphanKeyA>

SHDeleteValueA PROTO :DWORD,:DWORD,:DWORD
SHDeleteValue equ <SHDeleteValueA>

SHEnumKeyExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHEnumKeyEx equ <SHEnumKeyExA>

SHEnumValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHEnumValue equ <SHEnumValueA>

SHGetInverseCMAP PROTO :DWORD,:DWORD
SHGetValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetValue equ <SHGetValueA>

SHIsLowMemoryMachine PROTO :DWORD
SHOpenRegStreamA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHOpenRegStream equ <SHOpenRegStreamA>

SHQueryInfoKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHQueryInfoKey equ <SHQueryInfoKeyA>

SHQueryValueExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHQueryValueEx equ <SHQueryValueExA>

SHRegCloseUSKey PROTO :DWORD
SHRegCreateUSKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHRegCreateUSKey equ <SHRegCreateUSKeyA>

SHRegDeleteEmptyUSKeyA PROTO :DWORD,:DWORD,:DWORD
SHRegDeleteEmptyUSKey equ <SHRegDeleteEmptyUSKeyA>

SHRegDeleteUSValueA PROTO :DWORD,:DWORD,:DWORD
SHRegDeleteUSValue equ <SHRegDeleteUSValueA>

SHRegEnumUSKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHRegEnumUSKey equ <SHRegEnumUSKeyA>

SHRegEnumUSValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHRegEnumUSValue equ <SHRegEnumUSValueA>

SHRegGetBoolUSValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHRegGetBoolUSValue equ <SHRegGetBoolUSValueA>

SHRegGetUSValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHRegGetUSValue equ <SHRegGetUSValueA>

SHRegOpenUSKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHRegOpenUSKey equ <SHRegOpenUSKeyA>

SHRegQueryInfoUSKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHRegQueryInfoUSKey equ <SHRegQueryInfoUSKeyA>

SHRegQueryUSValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHRegQueryUSValue equ <SHRegQueryUSValueA>

SHRegSetUSValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHRegSetUSValue equ <SHRegSetUSValueA>

SHRegWriteUSValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHRegWriteUSValue equ <SHRegWriteUSValueA>

SHSetValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHSetValue equ <SHSetValueA>

StrCSpnA PROTO :DWORD,:DWORD
StrCSpn equ <StrCSpnA>

StrCSpnIA PROTO :DWORD,:DWORD
StrCSpnI equ <StrCSpnIA>

StrChrA PROTO :DWORD,:DWORD
StrChr equ <StrChrA>

StrChrIA PROTO :DWORD,:DWORD
StrChrI equ <StrChrIA>

StrCmpNA PROTO :DWORD,:DWORD,:DWORD
StrCmpN equ <StrCmpNA>

StrCmpNIA PROTO :DWORD,:DWORD,:DWORD
StrCmpNI equ <StrCmpNIA>

StrDupA PROTO :DWORD
StrDup equ <StrDupA>

StrFormatByteSizeA PROTO :DWORD,:DWORD,:DWORD
StrFormatByteSize equ <StrFormatByteSizeA>

StrFromTimeIntervalA PROTO :DWORD,:DWORD,:DWORD,:DWORD
StrFromTimeInterval equ <StrFromTimeIntervalA>

StrIsIntlEqualA PROTO :DWORD,:DWORD,:DWORD,:DWORD
StrIsIntlEqual equ <StrIsIntlEqualA>

StrNCatA PROTO :DWORD,:DWORD,:DWORD
StrNCat equ <StrNCatA>

StrPBrkA PROTO :DWORD,:DWORD
StrPBrk equ <StrPBrkA>

StrRChrA PROTO :DWORD,:DWORD,:DWORD
StrRChr equ <StrRChrA>

StrRChrIA PROTO :DWORD,:DWORD,:DWORD
StrRChrI equ <StrRChrIA>

StrRStrIA PROTO :DWORD,:DWORD,:DWORD
StrRStrI equ <StrRStrIA>

StrSpnA PROTO :DWORD,:DWORD
StrSpn equ <StrSpnA>

StrStrA PROTO :DWORD,:DWORD
StrStr equ <StrStrA>

StrStrIA PROTO :DWORD,:DWORD
StrStrI equ <StrStrIA>

StrToIntA PROTO :DWORD
StrToInt equ <StrToIntA>

StrToIntExA PROTO :DWORD,:DWORD,:DWORD
StrToIntEx equ <StrToIntExA>

StrTrimA PROTO :DWORD,:DWORD
StrTrim equ <StrTrimA>

UrlApplySchemeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
UrlApplyScheme equ <UrlApplySchemeA>

UrlCanonicalizeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
UrlCanonicalize equ <UrlCanonicalizeA>

UrlCombineA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UrlCombine equ <UrlCombineA>

UrlCompareA PROTO :DWORD,:DWORD,:DWORD
UrlCompare equ <UrlCompareA>

UrlCreateFromPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD
UrlCreateFromPath equ <UrlCreateFromPathA>

UrlEscapeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
UrlEscape equ <UrlEscapeA>

UrlGetLocationA PROTO :DWORD
UrlGetLocation equ <UrlGetLocationA>

UrlGetPartA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UrlGetPart equ <UrlGetPartA>

UrlHashA PROTO :DWORD,:DWORD,:DWORD
UrlHash equ <UrlHashA>

UrlIsA PROTO :DWORD,:DWORD
UrlIs equ <UrlIsA>

UrlIsNoHistoryA PROTO :DWORD
UrlIsNoHistory equ <UrlIsNoHistoryA>

UrlIsOpaqueA PROTO :DWORD
UrlIsOpaque equ <UrlIsOpaqueA>

UrlUnescapeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
UrlUnescape equ <UrlUnescapeA>


