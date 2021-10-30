; ..\LIB\WININET.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CommitUrlCacheEntryA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CommitUrlCacheEntry equ <CommitUrlCacheEntryA>

CreateUrlCacheContainerA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateUrlCacheContainer equ <CreateUrlCacheContainerA>

CreateUrlCacheEntryA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateUrlCacheEntry equ <CreateUrlCacheEntryA>

CreateUrlCacheGroup PROTO :DWORD,:DWORD
DeleteIE3Cache PROTO :DWORD,:DWORD,:DWORD,:DWORD
DeleteUrlCacheContainerA PROTO :DWORD,:DWORD
DeleteUrlCacheContainer equ <DeleteUrlCacheContainerA>

DeleteUrlCacheEntry PROTO :DWORD
DeleteUrlCacheGroup PROTO :DWORD,:DWORD,:DWORD,:DWORD
FindCloseUrlCache PROTO :DWORD
FindFirstUrlCacheContainerA PROTO :DWORD,:DWORD,:DWORD,:DWORD
FindFirstUrlCacheContainer equ <FindFirstUrlCacheContainerA>

FindFirstUrlCacheEntryA PROTO :DWORD,:DWORD,:DWORD
FindFirstUrlCacheEntry equ <FindFirstUrlCacheEntryA>

FindFirstUrlCacheEntryExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FindFirstUrlCacheEntryEx equ <FindFirstUrlCacheEntryExA>

FindNextUrlCacheContainerA PROTO :DWORD,:DWORD,:DWORD
FindNextUrlCacheContainer equ <FindNextUrlCacheContainerA>

FindNextUrlCacheEntryA PROTO :DWORD,:DWORD,:DWORD
FindNextUrlCacheEntry equ <FindNextUrlCacheEntryA>

FindNextUrlCacheEntryExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FindNextUrlCacheEntryEx equ <FindNextUrlCacheEntryExA>

FreeUrlCacheSpaceA PROTO :DWORD,:DWORD,:DWORD
FreeUrlCacheSpace equ <FreeUrlCacheSpaceA>

FtpCreateDirectoryA PROTO :DWORD,:DWORD
FtpCreateDirectory equ <FtpCreateDirectoryA>

FtpDeleteFileA PROTO :DWORD,:DWORD
FtpDeleteFile equ <FtpDeleteFileA>

FtpFindFirstFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FtpFindFirstFile equ <FtpFindFirstFileA>

FtpGetCurrentDirectoryA PROTO :DWORD,:DWORD,:DWORD
FtpGetCurrentDirectory equ <FtpGetCurrentDirectoryA>

FtpGetFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FtpGetFile equ <FtpGetFileA>

FtpOpenFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FtpOpenFile equ <FtpOpenFileA>

FtpPutFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FtpPutFile equ <FtpPutFileA>

FtpRemoveDirectoryA PROTO :DWORD,:DWORD
FtpRemoveDirectory equ <FtpRemoveDirectoryA>

FtpRenameFileA PROTO :DWORD,:DWORD,:DWORD
FtpRenameFile equ <FtpRenameFileA>

FtpSetCurrentDirectoryA PROTO :DWORD,:DWORD
FtpSetCurrentDirectory equ <FtpSetCurrentDirectoryA>

GetUrlCacheConfigInfoA PROTO :DWORD,:DWORD,:DWORD
GetUrlCacheConfigInfo equ <GetUrlCacheConfigInfoA>

GetUrlCacheEntryInfoA PROTO :DWORD,:DWORD,:DWORD
GetUrlCacheEntryInfo equ <GetUrlCacheEntryInfoA>

GetUrlCacheEntryInfoExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetUrlCacheEntryInfoEx equ <GetUrlCacheEntryInfoExA>

GetUrlCacheHeaderData PROTO :DWORD,:DWORD
GopherCreateLocatorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GopherCreateLocator equ <GopherCreateLocatorA>

GopherFindFirstFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GopherFindFirstFile equ <GopherFindFirstFileA>

GopherGetAttributeA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GopherGetAttribute equ <GopherGetAttributeA>

GopherGetLocatorTypeA PROTO :DWORD,:DWORD
GopherGetLocatorType equ <GopherGetLocatorTypeA>

GopherOpenFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GopherOpenFile equ <GopherOpenFileA>

HttpAddRequestHeadersA PROTO :DWORD,:DWORD,:DWORD,:DWORD
HttpAddRequestHeaders equ <HttpAddRequestHeadersA>

HttpEndRequestA PROTO :DWORD,:DWORD,:DWORD,:DWORD
HttpEndRequest equ <HttpEndRequestA>

HttpOpenRequestA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HttpOpenRequest equ <HttpOpenRequestA>

HttpQueryInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HttpQueryInfo equ <HttpQueryInfoA>

HttpSendRequestA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HttpSendRequest equ <HttpSendRequestA>

HttpSendRequestExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HttpSendRequestEx equ <HttpSendRequestExA>

IncrementUrlCacheHeaderData PROTO :DWORD,:DWORD
InternetAttemptConnect PROTO :DWORD
InternetAutodial PROTO :DWORD,:DWORD
InternetAutodialCallback PROTO :DWORD,:DWORD
InternetAutodialHangup PROTO :DWORD
InternetCanonicalizeUrlA PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetCanonicalizeUrl equ <InternetCanonicalizeUrlA>

InternetCheckConnectionA PROTO :DWORD,:DWORD,:DWORD
InternetCheckConnection equ <InternetCheckConnectionA>

InternetCloseHandle PROTO :DWORD
InternetCombineUrlA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternetCombineUrl equ <InternetCombineUrlA>

InternetConfirmZoneCrossing PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetConnectA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternetConnect equ <InternetConnectA>

InternetCrackUrlA PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetCrackUrl equ <InternetCrackUrlA>

InternetCreateUrlA PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetCreateUrl equ <InternetCreateUrlA>

InternetDebugGetLocalTime PROTO :DWORD,:DWORD
InternetDial PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternetErrorDlg PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternetFindNextFileA PROTO :DWORD,:DWORD
InternetFindNextFile equ <InternetFindNextFileA>

InternetGetCertByURL PROTO :DWORD,:DWORD,:DWORD
InternetGetConnectedState PROTO :DWORD,:DWORD
InternetGetCookieA PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetGetCookie equ <InternetGetCookieA>

InternetGetLastResponseInfoA PROTO :DWORD,:DWORD,:DWORD
InternetGetLastResponseInfo equ <InternetGetLastResponseInfoA>

InternetGoOnline PROTO :DWORD,:DWORD,:DWORD
InternetHangUp PROTO :DWORD,:DWORD
InternetLockRequestFile PROTO :DWORD,:DWORD
InternetOpenA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternetOpen equ <InternetOpenA>

InternetOpenUrlA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternetOpenUrl equ <InternetOpenUrlA>

InternetQueryDataAvailable PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetQueryOptionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetQueryOption equ <InternetQueryOptionA>

InternetReadFile PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetReadFileExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetReadFileEx equ <InternetReadFileExA>

InternetSetCookieA PROTO :DWORD,:DWORD,:DWORD
InternetSetCookie equ <InternetSetCookieA>

InternetSetDialState PROTO :DWORD,:DWORD,:DWORD
InternetSetFilePointer PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternetSetOptionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetSetOption equ <InternetSetOptionA>

InternetSetOptionExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternetSetOptionEx equ <InternetSetOptionExA>

InternetSetStatusCallback PROTO :DWORD,:DWORD
InternetShowSecurityInfoByURL PROTO :DWORD,:DWORD
InternetTimeFromSystemTime PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetTimeToSystemTime PROTO :DWORD,:DWORD,:DWORD
InternetUnlockRequestFile PROTO :DWORD
InternetWriteFile PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetWriteFileExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternetWriteFileEx equ <InternetWriteFileExA>

IsHostInProxyBypassList PROTO :DWORD,:DWORD,:DWORD
LoadUrlCacheContent PROTO
ParseX509EncodedCertificateForListBoxEntry PROTO :DWORD,:DWORD,:DWORD,:DWORD
ReadUrlCacheEntryStream PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RetrieveUrlCacheEntryFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RetrieveUrlCacheEntryFile equ <RetrieveUrlCacheEntryFileA>

RetrieveUrlCacheEntryStreamA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RetrieveUrlCacheEntryStream equ <RetrieveUrlCacheEntryStreamA>

RunOnceUrlCache PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetUrlCacheConfigInfoA PROTO :DWORD,:DWORD
SetUrlCacheConfigInfo equ <SetUrlCacheConfigInfoA>

SetUrlCacheEntryGroup PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetUrlCacheEntryInfoA PROTO :DWORD,:DWORD,:DWORD
SetUrlCacheEntryInfo equ <SetUrlCacheEntryInfoA>

SetUrlCacheHeaderData PROTO :DWORD,:DWORD
ShowClientAuthCerts PROTO :DWORD
ShowSecurityInfo PROTO :DWORD,:DWORD
ShowX509EncodedCertificate PROTO :DWORD,:DWORD,:DWORD
UnlockUrlCacheEntryFile PROTO :DWORD,:DWORD
UnlockUrlCacheEntryStream PROTO :DWORD,:DWORD
UpdateUrlCacheContentPath PROTO :DWORD

