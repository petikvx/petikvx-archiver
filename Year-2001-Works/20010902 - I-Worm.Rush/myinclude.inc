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
WIN32_FIND_DATA     STRUC
  dwFileAttributes    dd   ?
  ftCreationTime      dd   ?,?
  ftLastAccessTime    dd   ?,?
  ftLastWriteTime     dd   ?,?
  nFileSizeHigh       dd   ?
  nFileSizeLow        dd   ?
  dwReserved0         dd   ?
  dwReserved1         dd   ?
  cFileName           db   MAX_PATH dup(?)
  cAlternateFileName  db   14 dup(?)
WIN32_FIND_DATA     ENDS


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


SystemTime      SYSTIME <>
Search      WIN32_FIND_DATA <>
sInfo       STARTUPINFO <>
pInfo       PROCESS_INFORMATION <>
