; ..\LIB\VERSION.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

GetFileVersionInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetFileVersionInfo equ <GetFileVersionInfoA>

GetFileVersionInfoSizeA PROTO :DWORD,:DWORD
GetFileVersionInfoSize equ <GetFileVersionInfoSizeA>

VerFindFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
VerFindFile equ <VerFindFileA>

VerInstallFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
VerInstallFile equ <VerInstallFileA>

VerLanguageNameA PROTO :DWORD,:DWORD,:DWORD
VerLanguageName equ <VerLanguageNameA>

VerQueryValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD
VerQueryValue equ <VerQueryValueA>

VerQueryValueIndexA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
VerQueryValueIndex equ <VerQueryValueIndexA>


