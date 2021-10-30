; ..\LIB\DDRAW.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~

DDHAL32_VidMemAlloc PROTO :DWORD,:DWORD,:DWORD,:DWORD
DDHAL32_VidMemFree PROTO :DWORD,:DWORD,:DWORD
DDInternalLock PROTO :DWORD,:DWORD
DDInternalUnlock PROTO :DWORD
DSoundHelp PROTO :DWORD,:DWORD,:DWORD
DirectDrawCreate PROTO :DWORD,:DWORD,:DWORD
DirectDrawCreateClipper PROTO :DWORD,:DWORD,:DWORD
DirectDrawEnumerateA PROTO :DWORD,:DWORD
DirectDrawEnumerate equ <DirectDrawEnumerateA>

GetSurfaceFromDC PROTO :DWORD,:DWORD,:DWORD
HeapVidMemAllocAligned PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LateAllocateSurfaceMem PROTO :DWORD,:DWORD,:DWORD,:DWORD
VidMemAlloc PROTO :DWORD,:DWORD,:DWORD
VidMemAmountFree PROTO :DWORD
VidMemFini PROTO :DWORD
VidMemFree PROTO :DWORD,:DWORD
VidMemInit PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
VidMemLargestFree PROTO :DWORD

