; ..\LIB\MSACM32.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

XRegThunkEntry PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmDriverAddA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmDriverAdd equ <acmDriverAddA>

acmDriverClose PROTO :DWORD,:DWORD
acmDriverDetailsA PROTO :DWORD,:DWORD,:DWORD
acmDriverDetails equ <acmDriverDetailsA>

acmDriverEnum PROTO :DWORD,:DWORD,:DWORD
acmDriverID PROTO :DWORD,:DWORD,:DWORD
acmDriverMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
acmDriverOpen PROTO :DWORD,:DWORD,:DWORD
acmDriverPriority PROTO :DWORD,:DWORD,:DWORD
acmDriverRemove PROTO :DWORD,:DWORD
acmFilterChooseA PROTO :DWORD
acmFilterChoose equ <acmFilterChooseA>

acmFilterDetailsA PROTO :DWORD,:DWORD,:DWORD
acmFilterDetails equ <acmFilterDetailsA>

acmFilterEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFilterEnum equ <acmFilterEnumA>

acmFilterTagDetailsA PROTO :DWORD,:DWORD,:DWORD
acmFilterTagDetails equ <acmFilterTagDetailsA>

acmFilterTagEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFilterTagEnum equ <acmFilterTagEnumA>

acmFormatChooseA PROTO :DWORD
acmFormatChoose equ <acmFormatChooseA>

acmFormatDetailsA PROTO :DWORD,:DWORD,:DWORD
acmFormatDetails equ <acmFormatDetailsA>

acmFormatEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFormatEnum equ <acmFormatEnumA>

acmFormatSuggest PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFormatTagDetailsA PROTO :DWORD,:DWORD,:DWORD
acmFormatTagDetails equ <acmFormatTagDetailsA>

acmFormatTagEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFormatTagEnum equ <acmFormatTagEnumA>

acmGetVersion PROTO
acmMessage32 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmMetrics PROTO :DWORD,:DWORD,:DWORD
acmStreamClose PROTO :DWORD,:DWORD
acmStreamConvert PROTO :DWORD,:DWORD,:DWORD
acmStreamMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
acmStreamOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmStreamPrepareHeader PROTO :DWORD,:DWORD,:DWORD
acmStreamReset PROTO :DWORD,:DWORD
acmStreamSize PROTO :DWORD,:DWORD,:DWORD,:DWORD
acmStreamUnprepareHeader PROTO :DWORD,:DWORD,:DWORD

