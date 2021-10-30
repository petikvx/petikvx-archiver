; ..\LIB\SHELL32.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CheckEscapesA PROTO :DWORD,:DWORD
CheckEscapes equ <CheckEscapesA>

DoEnvironmentSubstA PROTO :DWORD,:DWORD
DoEnvironmentSubst equ <DoEnvironmentSubstA>

DragAcceptFiles PROTO :DWORD,:DWORD
DragFinish PROTO :DWORD
DragQueryFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DragQueryFile equ <DragQueryFileA>

DragQueryPoint PROTO :DWORD,:DWORD
DuplicateIcon PROTO :DWORD,:DWORD
ExtractAssociatedIconA PROTO :DWORD,:DWORD,:DWORD
ExtractAssociatedIcon equ <ExtractAssociatedIconA>

ExtractAssociatedIconExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ExtractAssociatedIconEx equ <ExtractAssociatedIconExA>

ExtractIconA PROTO :DWORD,:DWORD,:DWORD
ExtractIcon equ <ExtractIconA>

ExtractIconExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExtractIconEx equ <ExtractIconExA>

ExtractIconResInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExtractIconResInfo equ <ExtractIconResInfoA>

FindExeDlgProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
FindExecutableA PROTO :DWORD,:DWORD,:DWORD
FindExecutable equ <FindExecutableA>

FreeIconList PROTO :DWORD,:DWORD
InternalExtractIconListA PROTO :DWORD,:DWORD,:DWORD
InternalExtractIconList equ <InternalExtractIconListA>

RealShellExecuteA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RealShellExecute equ <RealShellExecuteA>

RealShellExecuteExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RealShellExecuteEx equ <RealShellExecuteExA>

RegenerateUserEnvironment PROTO :DWORD,:DWORD
SHAddToRecentDocs PROTO :DWORD,:DWORD
SHAppBarMessage PROTO :DWORD,:DWORD
SHBrowseForFolderA PROTO :DWORD
SHBrowseForFolder equ <SHBrowseForFolderA>

SHChangeNotify PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHEmptyRecycleBinA PROTO :DWORD,:DWORD,:DWORD
SHEmptyRecycleBin equ <SHEmptyRecycleBinA>

SHFileOperationA PROTO :DWORD
SHFileOperation equ <SHFileOperationA>

SHFormatDrive PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHFreeNameMappings PROTO :DWORD
SHGetDataFromIDListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetDataFromIDList equ <SHGetDataFromIDListA>

SHGetDesktopFolder PROTO :DWORD
SHGetDiskFreeSpaceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHGetDiskFreeSpace equ <SHGetDiskFreeSpaceA>

SHGetFileInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetFileInfo equ <SHGetFileInfoA>

SHGetInstanceExplorer PROTO :DWORD
SHGetMalloc PROTO :DWORD
SHGetNewLinkInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetPathFromIDListA PROTO :DWORD,:DWORD
SHGetPathFromIDList equ <SHGetPathFromIDListA>

SHGetSettings PROTO :DWORD,:DWORD
SHGetSpecialFolderLocation PROTO :DWORD,:DWORD,:DWORD
SHGetSpecialFolderPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHGetSpecialFolderPath equ <SHGetSpecialFolderPathA>

SHInvokePrinterCommandA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHInvokePrinterCommand equ <SHInvokePrinterCommandA>

SHLoadInProc PROTO :DWORD
SHQueryRecycleBinA PROTO :DWORD,:DWORD
SHQueryRecycleBin equ <SHQueryRecycleBinA>

SHUpdateRecycleBinIcon PROTO
SheChangeDirA PROTO :DWORD
SheChangeDir equ <SheChangeDirA>

SheChangeDirExA PROTO :DWORD
SheChangeDirEx equ <SheChangeDirExA>

SheFullPathA PROTO :DWORD,:DWORD,:DWORD
SheFullPath equ <SheFullPathA>

SheGetCurDrive PROTO
SheGetDirA PROTO :DWORD,:DWORD
SheGetDir equ <SheGetDirA>

SheRemoveQuotesA PROTO :DWORD
SheRemoveQuotes equ <SheRemoveQuotesA>

SheSetCurDrive PROTO :DWORD
SheShortenPathA PROTO :DWORD,:DWORD
SheShortenPath equ <SheShortenPathA>

ShellAboutA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ShellAbout equ <ShellAboutA>

ShellExecuteA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ShellExecute equ <ShellExecuteA>

ShellExecuteExA PROTO :DWORD
ShellExecuteEx equ <ShellExecuteExA>

ShellHookProc PROTO :DWORD,:DWORD,:DWORD
Shell_NotifyIconA PROTO :DWORD,:DWORD
Shell_NotifyIcon equ <Shell_NotifyIconA>

StrChrA PROTO :DWORD,:DWORD
StrChr equ <StrChrA>

StrChrIA PROTO :DWORD,:DWORD
StrChrI equ <StrChrIA>

StrCmpNA PROTO :DWORD,:DWORD,:DWORD
StrCmpN equ <StrCmpNA>

StrCmpNIA PROTO :DWORD,:DWORD,:DWORD
StrCmpNI equ <StrCmpNIA>

StrCpyNA PROTO :DWORD,:DWORD,:DWORD
StrCpyN equ <StrCpyNA>

StrNCmpA PROTO :DWORD,:DWORD,:DWORD
StrNCmp equ <StrNCmpA>

StrNCmpIA PROTO :DWORD,:DWORD,:DWORD
StrNCmpI equ <StrNCmpIA>

StrNCpyA PROTO :DWORD,:DWORD,:DWORD
StrNCpy equ <StrNCpyA>

StrRChrA PROTO :DWORD,:DWORD,:DWORD
StrRChr equ <StrRChrA>

StrRChrIA PROTO :DWORD,:DWORD,:DWORD
StrRChrI equ <StrRChrIA>

StrRStrA PROTO :DWORD,:DWORD,:DWORD
StrRStr equ <StrRStrA>

StrRStrIA PROTO :DWORD,:DWORD,:DWORD
StrRStrI equ <StrRStrIA>

StrStrA PROTO :DWORD,:DWORD
StrStr equ <StrStrA>

StrStrIA PROTO :DWORD,:DWORD
StrStrI equ <StrStrIA>

WOWShellExecute PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

