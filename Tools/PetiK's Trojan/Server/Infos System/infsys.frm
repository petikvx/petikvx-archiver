VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "System tools 1.0 - Start"
   ClientHeight    =   6735
   ClientLeft      =   975
   ClientTop       =   2190
   ClientWidth     =   13230
   Icon            =   "infsys.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   6735
   ScaleWidth      =   13230
   Begin VB.CommandButton butexit 
      Caption         =   "Exit Windows"
      Height          =   375
      Left            =   240
      TabIndex        =   10
      Top             =   2760
      Visible         =   0   'False
      Width           =   1815
   End
   Begin VB.CommandButton butreboot 
      Caption         =   "Reboot System"
      Height          =   375
      Left            =   240
      TabIndex        =   9
      Top             =   2280
      Visible         =   0   'False
      Width           =   1815
   End
   Begin VB.ListBox lstpro 
      BackColor       =   &H80000008&
      ForeColor       =   &H0000FF00&
      Height          =   3765
      ItemData        =   "infsys.frx":030A
      Left            =   9600
      List            =   "infsys.frx":030C
      Sorted          =   -1  'True
      TabIndex        =   6
      Top             =   240
      Width           =   3375
   End
   Begin MSComDlg.CommonDialog CMD 
      Left            =   3120
      Top             =   0
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton butsaveinf 
      Caption         =   "Save Informations"
      Height          =   375
      Left            =   240
      TabIndex        =   5
      Top             =   3960
      Width           =   1815
   End
   Begin VB.CommandButton butclr 
      Caption         =   "CLEAR"
      Height          =   375
      Left            =   240
      TabIndex        =   4
      Top             =   4440
      Width           =   1815
   End
   Begin VB.TextBox sztxt 
      BackColor       =   &H80000008&
      BeginProperty Font 
         Name            =   "Courier New"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FF00&
      Height          =   6375
      Left            =   2400
      Locked          =   -1  'True
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   3
      Top             =   240
      Width           =   6975
   End
   Begin VB.CommandButton butclose 
      Caption         =   "CLOSE"
      Height          =   375
      Left            =   1200
      TabIndex        =   2
      Top             =   1560
      Visible         =   0   'False
      Width           =   855
   End
   Begin VB.CommandButton butopen 
      Caption         =   "OPEN"
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Top             =   1560
      Visible         =   0   'False
      Width           =   855
   End
   Begin VB.ListBox lstaction 
      Height          =   645
      ItemData        =   "infsys.frx":030E
      Left            =   240
      List            =   "infsys.frx":0324
      Sorted          =   -1  'True
      TabIndex        =   0
      Top             =   600
      Width           =   1815
   End
   Begin VB.Label Label1 
      Caption         =   "Choose heading :"
      Height          =   255
      Left            =   240
      TabIndex        =   8
      Top             =   240
      Width           =   1815
   End
   Begin VB.Label lblcount 
      Caption         =   "0 Process Found"
      Height          =   255
      Left            =   9600
      TabIndex        =   7
      Top             =   4080
      Width           =   1815
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Sub CloseHandle Lib "kernel32" (ByVal hPass As Long)
Private Declare Function CreateToolhelp32Snapshot Lib "kernel32" (ByVal lFlags As Long, ByVal lProcessID As Long) As Long
Private Declare Function DeleteFile Lib "kernel32" Alias "DeleteFileA" (ByVal lpFileName As String) As Long
Private Declare Function ExitWindowsEx Lib "user32" (ByVal uFlags As Long, ByVal dwReserved As Long) As Long
Private Declare Function GetComputerName Lib "kernel32" Alias "GetComputerNameA" (ByVal lpBuffer As String, nSize As Long) As Long
Private Declare Function GetDiskFreeSpaceEx Lib "kernel32" Alias "GetDiskFreeSpaceExA" (ByVal lpRootPathName As String, lpFreeBytesAvailableToCaller As Currency, lpTotalNumberOfBytes As Currency, lpTotalNumberOfFreeBytes As Currency) As Long
Private Declare Function GetOpenFileName Lib "comdlg32.dll" Alias "GetOpenFileNameA" (pOpenfilename As OPENFILENAME) As Long
Private Declare Function GetUserName Lib "advapi32.dll" Alias "GetUserNameA" (ByVal lpBuffer As String, nSize As Long) As Long
Private Declare Function GetSaveFileName Lib "comdlg32.dll" Alias "GetSaveFileNameA" (pOpenfilename As OPENFILENAME) As Long
Private Declare Function GetSystemDirectory Lib "kernel32" Alias "GetSystemDirectoryA" (ByVal lpBuffer As String, ByVal nSize As Long) As Long
Private Declare Sub GetSystemInfo Lib "kernel32" (lpSystemInfo As SYSTEM_INFO)
Private Declare Function GetTempPath Lib "kernel32" Alias "GetTempPathA" (ByVal nBufferLength As Long, ByVal lpBuffer As String) As Long
Private Declare Function GetTickCount& Lib "kernel32" ()
Private Declare Function GetVersionEx Lib "kernel32" Alias "GetVersionExA" (lpVersionInformation As OSVERSIONINFO) As Long
Private Declare Function GetWindowsDirectory Lib "kernel32" Alias "GetWindowsDirectoryA" (ByVal lpBuffer As String, ByVal nSize As Long) As Long
Private Declare Sub GlobalMemoryStatus Lib "kernel32" (lpBuffer As MEMORYSTATUS)
Private Declare Function InternetGetConnectedState Lib "wininet.dll" (ByRef lpdwFlags As Long, ByVal dwReserved As Long) As Long
Private Declare Function mciSendString Lib "winmm.dll" Alias "mciSendStringA" (ByVal lpstrCommand As String, ByVal lpstrReturnString As String, ByVal uReturnLength As Long, ByVal hwndCallback As Long) As Long
Private Declare Function Process32First Lib "kernel32" (ByVal hSnapShot As Long, uProcess As PROCESSENTRY32) As Long
Private Declare Function Process32Next Lib "kernel32" (ByVal hSnapShot As Long, uProcess As PROCESSENTRY32) As Long
Public sysDir As String
Public winDir As String
Public tmpDir As String
Private Type OSVERSIONINFO
    dwOSVersionInfoSize As Long
    dwMajorVersion As Long
    dwMinorVersion As Long
    dwBuildNumber As Long
    dwPlatformId As Long
    szCSDVersion As String * 128
End Type
Private Type MEMORYSTATUS
        dwLength As Long
        dwMemoryLoad As Long
        dwTotalPhys As Long
        dwAvailPhys As Long
        dwTotalPageFile As Long
        dwAvailPageFile As Long
        dwTotalVirtual As Long
        dwAvailVirtual As Long
End Type
Private Type SYSTEM_INFO
    dwOemID As Long
    dwPageSize As Long
    lpMinimumApplicationAddress As Long
    lpMaximumApplicationAddress As Long
    dwActiveProcessorMask As Long
    dwNumberOrfProcessors As Long
    dwProcessorType As Long
    dwAllocationGranularity As Long
    dwReserved As Long
End Type
Const TH32CS_SNAPHEAPLIST = &H1
Const TH32CS_SNAPPROCESS = &H2
Const TH32CS_SNAPTHREAD = &H4
Const TH32CS_SNAPMODULE = &H8
Const TH32CS_SNAPALL = (TH32CS_SNAPHEAPLIST Or TH32CS_SNAPPROCESS Or TH32CS_SNAPTHREAD Or TH32CS_SNAPMODULE)
Const TH32CS_INHERIT = &H80000000
Const MAX_PATH As Integer = 260
Private Type PROCESSENTRY32
    dwSize As Long
    cntUsage As Long
    th32ProcessID As Long
    th32DefaultHeapID As Long
    th32ModuleID As Long
    cntThreads As Long
    th32ParentProcessID As Long
    pcPriClassBase As Long
    dwFlags As Long
    szExeFile As String * MAX_PATH
End Type
Private Const INTERNET_CONNECTION_CONFIGURED = &H40
Private Const INTERNET_CONNECTION_LAN = &H2
Private Const INTERNET_CONNECTION_MODEM = &H1
Private Const INTERNET_CONNECTION_OFFLINE = &H20
Private Const INTERNET_CONNECTION_PROXY = &H4
Private Const INTERNET_RAS_INSTALLED = &H10
Private Enum COMPUTER_NAME_FORMAT
    ComputerNameNetBIOS
    ComputerNameDnsHostname
    ComputerNameDnsDomain
    ComputerNameDnsFullyQualified
    ComputerNamePhysicalNetBIOS
    ComputerNamePhysicalDnsHostname
    ComputerNamePhysicalDnsDomain
    ComputerNamePhysicalDnsFullyQualified
    ComputerNameMax
End Enum
Private Type OPENFILENAME
    lStructSize As Long
    hwndOwner As Long
    hInstance As Long
    lpstrFilter As String
    lpstrCustomFilter As String
    nMaxCustFilter As Long
    nFilterIndex As Long
    lpstrFile As String
    nMaxFile As Long
    lpstrFileTitle As String
    nMaxFileTitle As Long
    lpstrInitialDir As String
    lpstrTitle As String
    flags As Long
    nFileOffset As Integer
    nFileExtension As Integer
    lpstrDefExt As String
    lCustData As Long
    lpfnHook As Long
    lpTemplateName As String
End Type
Dim OFName As OPENFILENAME

Public Function GetComName() As String
Dim sBuff As String
Dim lBufs As Long
Dim lStat As Long
lBufs = 255
sBuff = String$(lBufs, " ")
lStat = GetComputerName(sBuff, lBufs)
GetComName = ""
If lStat <> 0 Then
GetComName = Left(sBuff, lBufs)
End If
End Function

Public Function GetUseName()
Dim llRetu As Long
Dim lsUser As String
Dim lsBuff As String
lsUser = ""
lsBuff = Space$(255)
llRetu = GetUserName(lsBuff, 255)
If llRetu Then
lsUser = Left$(lsBuff, InStr(lsBuff, Chr(0)) - 1)
End If
GetUseName = lsUser
End Function

Private Sub butclose_Click()
Dim op
op = mciSendString("set CDAudio door closed", vbNullString, 0, 0)
End Sub

Private Sub butopen_Click()
Dim op
op = mciSendString("set CDAudio door open", vbNullString, 0, 0)
End Sub

Private Sub butclr_Click()
sztxt.Text = ""
lstpro.Clear
lblcount.Caption = "0 Process Found"
End Sub

Private Sub butexit_Click()
Const EWX_LOGOFF = 0
Const EWX_SHUTDOWN = 1
Const EWX_FORCE = 4
msg = MsgBox("Are you sure to close Windows ?", vbYesNo + vbCritical, "Exit Windows")
If msg = vbYes Then
exitw& = ExitWindowsEx(EWX_LOGOFF Or EWX_FORCE, 0)
End If
End Sub

Private Sub butreboot_Click()
Const EWX_LOGOFF = 0
Const EWX_REBOOT = 2
Const EWX_FORCE = 4
msg = MsgBox("Are you sure to reboot system ?", vbYesNo + vbCritical, "Reboot System")
If msg = vbYes Then
exitw& = ExitWindowsEx(EWX_REBOOT Or EWX_FORCE, 0)
End If
End Sub

Private Sub butsaveinf_Click()
Dim OFName As OPENFILENAME
OFName.lStructSize = Len(OFName)
OFName.hwndOwner = Me.hWnd
OFName.hInstance = App.hInstance
OFName.lpstrFilter = "All Files (*.*)" + Chr$(0) + "*.*" + Chr$(0)
OFName.lpstrFile = Space$(254)
OFName.nMaxFile = 255
OFName.lpstrFileTitle = Space$(254)
OFName.nMaxFileTitle = 255
OFName.lpstrInitialDir = "C:\"
OFName.lpstrTitle = "Save Informations As..."
OFName.flags = 0

If GetSaveFileName(OFName) Then
Open OFName.lpstrFile For Output As #1
Print #1, sztxt.Text
Print #1, ""
Print #1, lstpro.ListCount & " Active Process (" & Date & " " & Time & ")"
For i = 1 To lstpro.ListCount
Print #1, lstpro.List(i)
Next i
Close #1
MsgBox "Informations save in " & OFName.lpstrFile, vbInformation, "System tools"
Else
End If

End Sub
Private Sub lstaction_Click()
On Error Resume Next
Dim opt, fso
Set fso = CreateObject("Scripting.FileSystemObject")
opt = lstaction.Text
If opt = "CD-ROM" Then
Form1.Caption = "System tools 1.0 - " & opt
butopen.Visible = True
butclose.Visible = True
Else
butopen.Visible = False
butclose.Visible = False
End If

If opt = "Infos System" Then
Dim ws
Dim strTemp As String
Dim OSInfo As OSVERSIONINFO, PId As String
Dim memoryInfo As MEMORYSTATUS
Dim SInfo As SYSTEM_INFO
Set ws = CreateObject("WScript.Shell")
Form1.Caption = "System tools 1.0 - " & opt
' sys path
sysDir = Space(500)
sysDir = Left(sysDir, GetSystemDirectory(sysDir, Len(sysDir)))
' win path
winDir = Space(500)
winDir = Left(winDir, GetWindowsDirectory(winDir, Len(winDir)))
owner = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOwner")
org = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOrganization")
pi = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductId")
pk = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductKey")
ver = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\Version")
vern = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\VersionNumber")
sp = ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\Main\Start Page")
proc = ws.RegRead("HKLM\HARDWARE\DESCRIPTION\System\CentralProcessor\0\Identifier")
' start system
su = Format(GetTickCount / 60000, "0")
' Disk Space
Dim r As Long, BytesFreeToCalller As Currency, TotalBytes As Currency
Dim TotalFreeBytes As Currency, TotalBytesUsed As Currency
Call GetDiskFreeSpaceEx("C:\", BytesFreeToCalller, TotalBytes, TotalFreeBytes)
dsf = "Total Number Of Bytes:" & Format$(TotalBytes * 10000, "###,###,###,##0") & " bytes" & vbCrLf
dsf = dsf & "Total Free Bytes:" & Format$(TotalFreeBytes * 10000, "###,###,###,##0") & " bytes" & vbCrLf
dsf = dsf & "Total Space Used :" & Format$((TotalBytes - TotalFreeBytes) * 10000, "###,###,###,##0") & " bytes"
' tmp path
tmpDir = String(100, Chr$(0))
GetTempPath 100, tmpDir
tmpDir = Left$(tmpDir, InStr(tmpDir, Chr$(0)) - 1)
'Operating Sys
GetSystemInfo SInfo
OSInfo.dwOSVersionInfoSize = Len(OSInfo)
PId = ""
ret& = GetVersionEx(OSInfo)
If ret& <> 0 Then
Select Case OSInfo.dwPlatformId
        Case 0
            PId = "Windows 32s "
        Case 1
            PId = "Windows 95/98 "
        Case 2
            PId = "Windows NT "
End Select
PId = PId & OSInfo.dwMajorVersion & "." & OSInfo.dwMinorVersion & " ,Build : " & OSInfo.dwPlatformId
End If

GlobalMemoryStatus memoryInfo
tm = Round(memoryInfo.dwTotalPhys / 1043321, 0)

inf = "Infos System :" & vbCrLf & vbCrLf & _
    "Operating System : " & PId & vbCrLf & _
    "Windows Version : " & ver & " " & vern & vbCrLf & _
    "Reg Name : " & owner & vbCrLf & _
    "Reg Organization : " & org & vbCrLf & _
    "User Name : " & GetUseName & vbCrLf & _
    "Computer Name : " & GetComName & vbCrLf & _
    "Id. Number : " & pi & vbCrLf & _
    "Key Number : " & pk & vbCrLf & vbCrLf & _
    "Processor : " & proc & vbCrLf & _
    "Number of procesor :" & Str$(SInfo.dwNumberOrfProcessors) & vbCrLf & _
    "Processor :" & Str$(SInfo.dwProcessorType) & vbCrLf & _
    "Low memory address :" & Str$(SInfo.lpMinimumApplicationAddress) & vbCrLf & _
    "High memory address :" & Str$(SInfo.lpMaximumApplicationAddress) & vbCrLf & _
    "Total Memory : " & tm & " MB" & vbCrLf & _
    "Resolution : " & CStr(Screen.Width / Screen.TwipsPerPixelX) & " X " & CStr(Screen.Height / Screen.TwipsPerPixelY) & vbCrLf & _
    dsf & vbCrLf & vbCrLf & _
    "WinDir : " & winDir & vbCrLf & _
    "SysDir : " & sysDir & vbCrLf & _
    "TmpDir : " & tmpDir & vbCrLf & _
    "IE Page : " & sp & vbCrLf & _
    "Date & Time : " & Date & " " & Time & vbCrLf & _
    "System started " & su & " minutes ago"

sztxt.Text = inf

End If

If opt = "View Process" Then
Form1.Caption = "System tools 1.0 - " & opt
Dim hSnapShot As Long, uProcess As PROCESSENTRY32
lstpro.Clear
hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0&)
uProcess.dwSize = Len(uProcess)
r = Process32First(hSnapShot, uProcess)
Do While r
        lstpro.AddItem uProcess.szExeFile
        'lstpro.AddItem Left$(uProcess.szExeFile, IIf(InStr(1, uProcess.szExeFile, Chr$(0)) > 0, InStr(1, uProcess.szExeFile, Chr$(0)) - 1, 0))
        lblcount.Caption = lstpro.ListCount & " Process Found"
        r = Process32Next(hSnapShot, uProcess)
Loop
CloseHandle hSnapShot
End If

If opt = "Script Viewer" Then
Form1.Caption = "System tools 1.0 - " & opt
OFName.lStructSize = Len(OFName)
OFName.hwndOwner = Me.hWnd
OFName.hInstance = App.hInstance
OFName.lpstrFilter = "HTM/HTML Files" + Chr$(0) + "*.htm;*.html" + Chr$(0) + "JS Files" + Chr$(0) + "*.js" + Chr$(0) + "VBS Files" + Chr$(0) + "*.vbs" + Chr$(0) + "Other Files" + Chr$(0) + "*.*" + Chr$(0)
OFName.lpstrFile = Space$(254)
OFName.nMaxFile = 255
OFName.lpstrFileTitle = Space$(254)
OFName.nMaxFileTitle = 255
OFName.lpstrInitialDir = "C:\"
OFName.lpstrTitle = "Open a script file..."
OFName.flags = 0
If GetOpenFileName(OFName) Then
Set scrpt = fso.OpenTextFile(OFName.lpstrFile, 1, True)
allf = scrpt.ReadAll()
scrpt.Close
sztxt.Text = allf
Else
MsgBox "Cancel was pressed"
End If
End If

If opt = "Internet Connection" Then
Dim Reti As Long
Form1.Caption = "System tools 1.0 - " & opt
sztxt.Text = "Internet Connection State :" & vbCrLf & vbCrLf
If InternetGetConnectedState(0&, 0&) = 1 Then
sztxt.Text = sztxt.Text & "System Connected" & vbCrLf
    Else
sztxt.Text = sztxt.Text & "System Not Connected" & vbCrLf
    End If
InternetGetConnectedState Reti, 0&
If (Reti And INTERNET_CONNECTION_CONFIGURED) = INTERNET_CONNECTION_CONFIGURED Then sztxt.Text = sztxt.Text & "Local system has a valid connection to the Internet, but it may or may not be currently connected." & vbCrLf
If (Reti And INTERNET_CONNECTION_LAN) = INTERNET_CONNECTION_LAN Then sztxt.Text = sztxt.Text & "Local system uses a local area network to connect to the Internet." & vbCrLf
If (Reti And INTERNET_CONNECTION_MODEM) = INTERNET_CONNECTION_MODEM Then sztxt.Text = sztxt.Text & "Local system uses a modem to connect to the Internet." & vbCrLf
If (Reti And INTERNET_CONNECTION_OFFLINE) = INTERNET_CONNECTION_OFFLINE Then sztxt.Text = sztxt.Text & "Local system is in offline mode." & vbCrLf
If (Reti And INTERNET_CONNECTION_PROXY) = INTERNET_CONNECTION_PROXY Then sztxt.Text = sztxt.Text & "Local system uses a proxy server to connect to the Internet." & vbCrLf
If (Reti And INTERNET_RAS_INSTALLED) = INTERNET_RAS_INSTALLED Then sztxt.Text = sztxt.Text & "Local system has RAS installed." & vbCrLf
End If

If opt = "Exit Windows" Then
Form1.Caption = "System tools 1.0 - " & opt
butexit.Visible = True
butreboot.Visible = True
Else
butexit.Visible = False
butreboot.Visible = False
End If
End Sub

Private Sub lstpro_DblClick()
MsgBox lstpro.Text, vbInformation, lstpro.ListIndex + 1 & ") " & lstpro.Text
End Sub
