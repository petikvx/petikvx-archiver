SYSTIME     STRUCT
wMonth      WORD ?
wDayOfWeek  WORD ?
wDay        WORD ?
wHour       WORD ?
wMinute     WORD ?
wSecond     WORD ?
wMillisecond    WORD ?
SYSTIME     ENDS

MAX_PATH        equ 260

FILETIME                        STRUC
        FT_dwLowDateTime        DD ?
        FT_dwHighDateTime       DD ?
FILETIME                        ENDS

WIN32_FIND_DATA                 STRUC
        WFD_dwFileAttributes    DD ?
        WFD_ftCreationTime      FILETIME ?
        WFD_ftLastAccessTime    FILETIME ?
        WFD_ftLastWriteTime     FILETIME ?
        WFD_nFileSizeHigh       DD ?
        WFD_nFileSizeLow        DD ?
        WFD_dwReserved0         DD ?
        WFD_dwReserved1         DD ?
        WFD_szFileName          DB MAX_PATH DUP (?)
        WFD_szAlternateFileName DB 13 DUP (?)
                                DB 3 DUP (?)    ; dword padding
WIN32_FIND_DATA                 ENDS


STARTUPINFO     STRUCT
    cb      DWORD   ?
    lpReserved  DWORD   ?
    lpDesktop   DWORD   ?
    lpTitle     DWORD   ?
    dwX     DWORD   ?
    dwY     DWORD   ?
    dwXSize     DWORD   ?
    dwYSize     DWORD   ?
    dwXCountChars   DWORD   ?
    dwYCountChars   DWORD   ?
    dwFillAttribute DWORD   ?
    dwFlags     DWORD   ?
    wShowWindow WORD    ?
    cbReserved2 WORD    ?
    lpReserved2 DWORD   ?
    hStdInput   DWORD   ?
    hStdOutput  DWORD   ?
    hStdError   DWORD   ?
STARTUPINFO     ENDS

PROCESS_INFORMATION STRUCT
    hProcess    DWORD   ?
    hThread     DWORD   ?
    dwProcessId DWORD   ?
    dwThreadId  DWORD   ?
PROCESS_INFORMATION ENDS


Systime     SYSTIME <>
Search      WIN32_FIND_DATA <>
sInfo       STARTUPINFO <>
pInfo       PROCESS_INFORMATION <>
