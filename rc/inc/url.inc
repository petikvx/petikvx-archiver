; ..\LIB\URL.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~

AddMIMEFileTypesPS PROTO :DWORD,:DWORD
InetIsOffline PROTO :DWORD
MIMEAssociationDialogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MIMEAssociationDialog equ <MIMEAssociationDialogA>

TranslateURLA PROTO :DWORD,:DWORD,:DWORD
TranslateURL equ <TranslateURLA>

URLAssociationDialogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
URLAssociationDialog equ <URLAssociationDialogA>


