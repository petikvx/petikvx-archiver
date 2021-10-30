; ..\LIB\OLEACC.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

AccessibleChildren PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessibleObjectFromEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessibleObjectFromPoint PROTO :DWORD,:DWORD,:DWORD,:DWORD
AccessibleObjectFromWindow PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateStdAccessibleObject PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetRoleTextA PROTO :DWORD,:DWORD,:DWORD
GetRoleText equ <GetRoleTextA>

GetStateTextA PROTO :DWORD,:DWORD,:DWORD
GetStateText equ <GetStateTextA>

LresultFromObject PROTO :DWORD,:DWORD,:DWORD
ObjectFromLresult PROTO :DWORD,:DWORD,:DWORD,:DWORD
WindowFromAccessibleObject PROTO :DWORD,:DWORD

