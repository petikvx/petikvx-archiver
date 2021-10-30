; ..\LIB\WEBPOST.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

WpBindToSiteA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WpBindToSite equ <WpBindToSiteA>

WpCreateSiteA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WpCreateSite equ <WpCreateSiteA>

WpDeleteSiteA PROTO :DWORD
WpDeleteSite equ <WpDeleteSiteA>

WpDoesSiteExistA PROTO :DWORD,:DWORD
WpDoesSiteExist equ <WpDoesSiteExistA>

WpEnumProvidersA PROTO :DWORD,:DWORD,:DWORD
WpEnumProviders equ <WpEnumProvidersA>

WpGetErrorStringA PROTO :DWORD,:DWORD,:DWORD
WpGetErrorString equ <WpGetErrorStringA>

WpListSitesA PROTO :DWORD,:DWORD,:DWORD
WpListSites equ <WpListSitesA>

WpPostA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WpPost equ <WpPostA>


