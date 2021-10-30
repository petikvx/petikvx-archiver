; ..\LIB\IMM32.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~

ImmAssociateContext PROTO :DWORD,:DWORD
ImmAssociateContextEx PROTO :DWORD,:DWORD,:DWORD
ImmConfigureIMEA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmConfigureIME equ <ImmConfigureIMEA>

ImmCreateContext PROTO
ImmCreateIMCC PROTO :DWORD
ImmCreateSoftKeyboard PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmDestroyContext PROTO :DWORD
ImmDestroyIMCC PROTO :DWORD
ImmDestroySoftKeyboard PROTO :DWORD
ImmDisableIME PROTO :DWORD
ImmEnumRegisterWordA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmEnumRegisterWord equ <ImmEnumRegisterWordA>

ImmEscapeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmEscape equ <ImmEscapeA>

ImmGenerateMessage PROTO :DWORD
ImmGetCandidateListA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGetCandidateList equ <ImmGetCandidateListA>

ImmGetCandidateListCountA PROTO :DWORD,:DWORD
ImmGetCandidateListCount equ <ImmGetCandidateListCountA>

ImmGetCandidateWindow PROTO :DWORD,:DWORD,:DWORD
ImmGetCompositionFontA PROTO :DWORD,:DWORD
ImmGetCompositionFont equ <ImmGetCompositionFontA>

ImmGetCompositionStringA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGetCompositionString equ <ImmGetCompositionStringA>

ImmGetCompositionWindow PROTO :DWORD,:DWORD
ImmGetContext PROTO :DWORD
ImmGetConversionListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmGetConversionList equ <ImmGetConversionListA>

ImmGetConversionStatus PROTO :DWORD,:DWORD,:DWORD
ImmGetDefaultIMEWnd PROTO :DWORD
ImmGetDescriptionA PROTO :DWORD,:DWORD,:DWORD
ImmGetDescription equ <ImmGetDescriptionA>

ImmGetGuideLineA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGetGuideLine equ <ImmGetGuideLineA>

ImmGetHotKey PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGetIMCCLockCount PROTO :DWORD
ImmGetIMCCSize PROTO :DWORD
ImmGetIMCLockCount PROTO :DWORD
ImmGetIMEFileNameA PROTO :DWORD,:DWORD,:DWORD
ImmGetIMEFileName equ <ImmGetIMEFileNameA>

ImmGetImeMenuItemsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmGetImeMenuItems equ <ImmGetImeMenuItemsA>

ImmGetOpenStatus PROTO :DWORD
ImmGetProperty PROTO :DWORD,:DWORD
ImmGetRegisterWordStyleA PROTO :DWORD,:DWORD,:DWORD
ImmGetRegisterWordStyle equ <ImmGetRegisterWordStyleA>

ImmGetStatusWindowPos PROTO :DWORD,:DWORD
ImmGetVirtualKey PROTO :DWORD
ImmInstallIMEA PROTO :DWORD,:DWORD
ImmInstallIME equ <ImmInstallIMEA>

ImmIsIME PROTO :DWORD
ImmIsUIMessageA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmIsUIMessage equ <ImmIsUIMessageA>

ImmLockIMC PROTO :DWORD
ImmLockIMCC PROTO :DWORD
ImmNotifyIME PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmReSizeIMCC PROTO :DWORD,:DWORD
ImmRegisterWordA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmRegisterWord equ <ImmRegisterWordA>

ImmReleaseContext PROTO :DWORD,:DWORD
ImmRequestMessageA PROTO :DWORD,:DWORD,:DWORD
ImmRequestMessage equ <ImmRequestMessageA>

ImmSetCandidateWindow PROTO :DWORD,:DWORD
ImmSetCompositionFontA PROTO :DWORD,:DWORD
ImmSetCompositionFont equ <ImmSetCompositionFontA>

ImmSetCompositionStringA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmSetCompositionString equ <ImmSetCompositionStringA>

ImmSetCompositionWindow PROTO :DWORD,:DWORD
ImmSetConversionStatus PROTO :DWORD,:DWORD,:DWORD
ImmSetHotKey PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmSetOpenStatus PROTO :DWORD,:DWORD
ImmSetStatusWindowPos PROTO :DWORD,:DWORD
ImmShowSoftKeyboard PROTO :DWORD,:DWORD
ImmSimulateHotKey PROTO :DWORD,:DWORD
ImmUnlockIMC PROTO :DWORD
ImmUnlockIMCC PROTO :DWORD
ImmUnregisterWordA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmUnregisterWord equ <ImmUnregisterWordA>


