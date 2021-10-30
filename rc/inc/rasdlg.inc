; ..\LIB\RASDLG.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

GetRasDialOutProtocols PROTO
RasAutodialDisableDlgA PROTO :DWORD
RasAutodialDisableDlg equ <RasAutodialDisableDlgA>

RasAutodialQueryDlgA PROTO :DWORD,:DWORD,:DWORD
RasAutodialQueryDlg equ <RasAutodialQueryDlgA>

RasDialDlgA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasDialDlg equ <RasDialDlgA>

RasEntryDlgA PROTO :DWORD,:DWORD,:DWORD
RasEntryDlg equ <RasEntryDlgA>

RasMonitorDlgA PROTO :DWORD,:DWORD
RasMonitorDlg equ <RasMonitorDlgA>

RasPhonebookDlgA PROTO :DWORD,:DWORD,:DWORD
RasPhonebookDlg equ <RasPhonebookDlgA>

RouterEntryDlgA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RouterEntryDlg equ <RouterEntryDlgA>


