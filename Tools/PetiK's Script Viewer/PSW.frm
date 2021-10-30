VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "PetiK's Script Viewer"
   ClientHeight    =   7650
   ClientLeft      =   150
   ClientTop       =   720
   ClientWidth     =   13530
   Icon            =   "PSW.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   7650
   ScaleWidth      =   13530
   StartUpPosition =   3  'Windows Default
   Begin VB.ComboBox stylevbsf 
      Height          =   315
      ItemData        =   "PSW.frx":08CA
      Left            =   2280
      List            =   "PSW.frx":08DA
      TabIndex        =   4
      Text            =   "Style"
      Top             =   840
      Width           =   1935
   End
   Begin VB.ComboBox sizevbsf 
      Height          =   315
      ItemData        =   "PSW.frx":0907
      Left            =   360
      List            =   "PSW.frx":0917
      TabIndex        =   3
      Text            =   "Size"
      Top             =   840
      Width           =   1575
   End
   Begin MSComDlg.CommonDialog CMD 
      Left            =   12600
      Top             =   120
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.TextBox vbsf 
      Height          =   6015
      Left            =   120
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   1
      Top             =   1320
      Width           =   13215
   End
   Begin VB.Label ffname 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   1200
      TabIndex        =   2
      Top             =   360
      Width           =   11055
   End
   Begin VB.Label Label1 
      Caption         =   "File Name :"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   360
      Width           =   1095
   End
   Begin VB.Menu Fichier 
      Caption         =   "&File"
      Begin VB.Menu Nouveau 
         Caption         =   "&New"
         Shortcut        =   ^N
      End
      Begin VB.Menu Ouvrir 
         Caption         =   "&Open"
         Shortcut        =   ^O
      End
      Begin VB.Menu Sauve 
         Caption         =   "&Save"
         Shortcut        =   ^S
      End
      Begin VB.Menu SauveC 
         Caption         =   "Sa&ve As"
      End
      Begin VB.Menu Ferme 
         Caption         =   "&Close"
         Shortcut        =   ^F
      End
   End
   Begin VB.Menu about 
      Caption         =   "&About Script Viewer"
   End
   Begin VB.Menu QuitterTout 
      Caption         =   "&QUIT Script Viewer"
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub about_Click()
MsgBox "PetiK's Script Viewer" & vbCrLf & _
        "Coded by PetiK - © 2002 - France", vbInformation, "About"

End Sub

Private Sub Ferme_Click()
oh = MsgBox("Save this current file ?", vbExclamation + vbYesNoCancel, "Script Viewer")
If oh = 6 Then Call Sauve_Click
If oh = 7 Then
ffname.Caption = ""
vbsf.Text = ""
End If
End Sub

Private Sub Nouveau_Click()
On Error Resume Next
ffname.Caption = ""
vbsf.Text = ""
End Sub

Private Sub Ouvrir_Click()
On Error Resume Next
CMD.DialogTitle = "Open a Script File..."
CMD.CancelError = True
CMD.Filter = "VBS File (*.VBS)|*.VBS|HTM/HTML File (*.HTM,*.HTML)|*.HTM;*.HTML|All File (*.*)|*.*"
CMD.FilterIndex = 1
CMD.InitDir = CurDir("")
CMD.ShowOpen
If Len(CMD.FileName) <> 0 Then
ffname.Caption = CMD.FileName
Set fso = CreateObject("Scripting.FileSystemObject")
Set fle = fso.OpenTextFile(CMD.FileName, 1)
allfle = fle.ReadAll
fle.Close
vbsf.Text = allfle
End If
End Sub

Private Sub QuitterTout_Click()
oh = MsgBox("Save this file", vbExclamation + vbYesNoCancel, "Script Viewer")
If oh = 6 Then
Call Sauve_Click
End
End If
If oh = 7 Then
End
End If
End Sub

Private Sub Sauve_Click()
On Error Resume Next
If Len(ffname.Caption) = 0 Then
CMD.DialogTitle = "Save a Script File..."
CMD.CancelError = True
CMD.Filter = "VBS File (*.vbs)|*.vbs|HTM/HTML File (*.htm,*.html)|*.htm;*.html|All File (*.*)|*.*"
CMD.FilterIndex = 1
CMD.InitDir = CurDir("")
CMD.ShowSave
If Len(CMD.FileName) <> 0 Then
Open CMD.FileName For Output As #1
Print #1, vbsf.Text
Close #1
ffname.Caption = CMD.FileName
End If
Else
Open ffname.Caption For Output As #1
Print #1, vbsf.Text
Close #1
End If
End Sub

Private Sub SauveC_Click()
On Error Resume Next
CMD.DialogTitle = "Save a Script File..."
CMD.CancelError = True
CMD.Filter = "VBS File (*.vbs)|*.vbs|HTM/HTML File (*.htm,*.html)|*.htm;*.html|All File (*.*)|*.*"
CMD.FilterIndex = 1
CMD.InitDir = CurDir("")
CMD.ShowSave
If Len(CMD.FileName) <> 0 Then
Open CMD.FileName For Output As #1
Print #1, vbsf.Text
Close #1
ffname.Caption = CMD.FileName
End If
End Sub

Private Sub sizevbsf_Click()
If sizevbsf.Text = "8" Then vbsf.FontSize = 8
If sizevbsf.Text = "10" Then vbsf.FontSize = 10
If sizevbsf.Text = "12" Then vbsf.FontSize = 12
If sizevbsf.Text = "14" Then vbsf.FontSize = 14
End Sub


Private Sub stylevbsf_Click()
If stylevbsf.Text = "Standard" Then
vbsf.FontBold = False
vbsf.FontItalic = False
End If
If stylevbsf.Text = "Bold" Then
vbsf.FontBold = True
vbsf.FontItalic = False
End If
If stylevbsf.Text = "Italic" Then
vbsf.FontBold = False
vbsf.FontItalic = True
End If
If stylevbsf.Text = "Bold and Italic" Then
vbsf.FontBold = True
vbsf.FontItalic = True
End If
End Sub
