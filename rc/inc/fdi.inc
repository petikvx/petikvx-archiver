; ..\LIB\FDI.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~

Arith_Close PROTO
Arith_Decode_Bits PROTO :DWORD
Arith_Init PROTO
CSUMCompute PROTO :DWORD,:DWORD,:DWORD
DComp_Close PROTO
DComp_DecompressBlock PROTO :DWORD,:DWORD,:DWORD,:DWORD
DComp_Init PROTO :DWORD
DComp_Reset PROTO
DComp_Ring_Close PROTO
DComp_Ring_Init PROTO
DComp_Ring_Load PROTO :DWORD,:DWORD
DComp_Ring_Reset PROTO
ErfSetCodes PROTO :DWORD,:DWORD,:DWORD
FDIGetDataBlock PROTO :DWORD
FDIGetFile PROTO :DWORD
FDIReadCFDATAEntry PROTO :DWORD,:DWORD
FDIReadCFFILEEntry PROTO :DWORD
FDIReadPSZ PROTO :DWORD,:DWORD,:DWORD
GetCount PROTO :DWORD
HuftBuild PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InflateBlock PROTO :DWORD
InflateCodes PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InflateDynamic PROTO :DWORD
InflateFixed PROTO :DWORD
InflateStored PROTO :DWORD,:DWORD
InitFixed PROTO :DWORD
InitFolder PROTO :DWORD,:DWORD
Internal_Literal PROTO :DWORD
Internal_Match PROTO :DWORD,:DWORD
LoginCabinet PROTO :DWORD,:DWORD,:DWORD,:DWORD
Lz_Bump PROTO :DWORD
Lz_Close PROTO
Lz_Init PROTO :DWORD
Lz_NextToken PROTO
MDICreateDecompressionGlobal PROTO :DWORD
MDIDecompressGlobal PROTO :DWORD,:DWORD
MDIDestroyDecompressionGlobal PROTO :DWORD
MDIResetDecompressionGlobal PROTO :DWORD
NFMDestroyContext PROTO :DWORD,:DWORD
NFMInitializeContext PROTO :DWORD
NFM_Decompress PROTO :DWORD,:DWORD
NFM_Prepare PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
Remove_Symbol PROTO :DWORD,:DWORD
Ring_Literal PROTO :DWORD
Ring_Match PROTO :DWORD,:DWORD
Rtl_Free PROTO :DWORD
Rtl_Malloc PROTO :DWORD
SeekFolder PROTO :DWORD,:DWORD
SetDecompressionType PROTO :DWORD,:DWORD
SwitchToNewCab PROTO :DWORD
doCabinetInfoNotify PROTO :DWORD

