; ..\LIB\COMDLG32.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ChooseColorA PROTO :DWORD
ChooseColor equ <ChooseColorA>

ChooseFontA PROTO :DWORD
ChooseFont equ <ChooseFontA>

CommDlgExtendedError PROTO
FindTextA PROTO :DWORD
FindText equ <FindTextA>

FormatCharDlgProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetFileTitleA PROTO :DWORD,:DWORD,:DWORD
GetFileTitle equ <GetFileTitleA>

GetOpenFileNameA PROTO :DWORD
GetOpenFileName equ <GetOpenFileNameA>

GetSaveFileNameA PROTO :DWORD
GetSaveFileName equ <GetSaveFileNameA>

LoadAlterBitmap PROTO :DWORD,:DWORD,:DWORD
PageSetupDlgA PROTO :DWORD
PageSetupDlg equ <PageSetupDlgA>

PrintDlgA PROTO :DWORD
PrintDlg equ <PrintDlgA>

ReplaceTextA PROTO :DWORD
ReplaceText equ <ReplaceTextA>

WantArrows PROTO :DWORD,:DWORD,:DWORD,:DWORD
dwLBSubclass PROTO :DWORD,:DWORD,:DWORD,:DWORD
dwOKSubclass PROTO :DWORD,:DWORD,:DWORD,:DWORD

