; ..\LIB\LZ32.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~

CopyLZFile PROTO :DWORD,:DWORD
GetExpandedNameA PROTO :DWORD,:DWORD
GetExpandedName equ <GetExpandedNameA>

LZClose PROTO :DWORD
LZCopy PROTO :DWORD,:DWORD
LZDone PROTO
LZInit PROTO :DWORD
LZOpenFileA PROTO :DWORD,:DWORD,:DWORD
LZOpenFile equ <LZOpenFileA>

LZRead PROTO :DWORD,:DWORD,:DWORD
LZSeek PROTO :DWORD,:DWORD,:DWORD
LZStart PROTO

