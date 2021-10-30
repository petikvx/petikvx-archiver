; ..\LIB\URLMON.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

BindAsyncMoniker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoGetClassObjectFromURL PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoInstall PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoInternetCombineUrl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoInternetCompareUrl PROTO :DWORD,:DWORD,:DWORD
CoInternetCreateSecurityManager PROTO :DWORD,:DWORD,:DWORD
CoInternetCreateZoneManager PROTO :DWORD,:DWORD,:DWORD
CoInternetGetProtocolFlags PROTO :DWORD,:DWORD,:DWORD
CoInternetGetSecurityUrl PROTO :DWORD,:DWORD,:DWORD,:DWORD
CoInternetGetSession PROTO :DWORD,:DWORD,:DWORD
CoInternetParseUrl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoInternetQueryInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CopyBindInfo PROTO :DWORD,:DWORD
CopyStgMedium PROTO :DWORD,:DWORD
CreateAsyncBindCtx PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateAsyncBindCtxEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateBindProtocol PROTO :DWORD,:DWORD
CreateFormatEnumerator PROTO :DWORD,:DWORD,:DWORD
CreateURLMoniker PROTO :DWORD,:DWORD,:DWORD
Extract PROTO :DWORD,:DWORD
FindMediaType PROTO :DWORD,:DWORD
FindMediaTypeClass PROTO :DWORD,:DWORD,:DWORD,:DWORD
FindMimeFromData PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetClassFileOrMime PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetClassURL PROTO :DWORD,:DWORD
GetSoftwareUpdateInfo PROTO :DWORD,:DWORD
HlinkGoBack PROTO :DWORD
HlinkGoForward PROTO :DWORD
HlinkNavigateMoniker PROTO :DWORD,:DWORD
HlinkNavigateString PROTO :DWORD,:DWORD
HlinkSimpleNavigateToMoniker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkSimpleNavigateToString PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IsAsyncMoniker PROTO :DWORD
IsLoggingEnabledA PROTO :DWORD
IsLoggingEnabled equ <IsLoggingEnabledA>

IsValidURL PROTO :DWORD,:DWORD,:DWORD
MkParseDisplayNameEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
NotfDeliverNotification PROTO :DWORD,:DWORD,:DWORD,:DWORD
ObtainUserAgentString PROTO :DWORD,:DWORD,:DWORD
RegisterBindStatusCallback PROTO :DWORD,:DWORD,:DWORD,:DWORD
RegisterFormatEnumerator PROTO :DWORD,:DWORD,:DWORD
RegisterMediaTypeClass PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegisterMediaTypes PROTO :DWORD,:DWORD,:DWORD
ReleaseBindInfo PROTO :DWORD
RevokeBindStatusCallback PROTO :DWORD,:DWORD
RevokeFormatEnumerator PROTO :DWORD,:DWORD
SetSoftwareUpdateAdvertisementState PROTO :DWORD,:DWORD,:DWORD,:DWORD
URLDownloadA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
URLDownload equ <URLDownloadA>

URLDownloadToCacheFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
URLDownloadToCacheFile equ <URLDownloadToCacheFileA>

URLDownloadToFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
URLDownloadToFile equ <URLDownloadToFileA>

URLOpenBlockingStreamA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
URLOpenBlockingStream equ <URLOpenBlockingStreamA>

URLOpenPullStreamA PROTO :DWORD,:DWORD,:DWORD,:DWORD
URLOpenPullStream equ <URLOpenPullStreamA>

URLOpenStreamA PROTO :DWORD,:DWORD,:DWORD,:DWORD
URLOpenStream equ <URLOpenStreamA>

UrlMkBuildVersion PROTO
UrlMkGetSessionOption PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UrlMkSetSessionOption PROTO :DWORD,:DWORD,:DWORD,:DWORD
WriteHitLogging PROTO :DWORD

