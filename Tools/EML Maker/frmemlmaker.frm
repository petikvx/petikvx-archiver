VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00000000&
   Caption         =   "EML Maker"
   ClientHeight    =   7890
   ClientLeft      =   2040
   ClientTop       =   735
   ClientWidth     =   5955
   ForeColor       =   &H00000000&
   LinkTopic       =   "Form1"
   ScaleHeight     =   7890
   ScaleWidth      =   5955
   Begin VB.CommandButton butgen 
      Caption         =   "Generate the message"
      Height          =   375
      Left            =   1080
      TabIndex        =   12
      Top             =   7200
      Width           =   3495
   End
   Begin VB.CommandButton butsave 
      Caption         =   "BROWSE"
      Height          =   375
      Left            =   4560
      TabIndex        =   11
      Top             =   6600
      Width           =   975
   End
   Begin VB.TextBox szSave 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   285
      Left            =   360
      Locked          =   -1  'True
      TabIndex        =   10
      Top             =   6600
      Width           =   3975
   End
   Begin VB.TextBox Text1 
      Height          =   3015
      Left            =   360
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   8
      Top             =   3000
      Width           =   5175
   End
   Begin VB.CommandButton butatt 
      Caption         =   "BROWSE"
      Height          =   375
      Left            =   4560
      TabIndex        =   6
      Top             =   1920
      Width           =   975
   End
   Begin VB.TextBox szAtt 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   285
      Left            =   360
      Locked          =   -1  'True
      TabIndex        =   5
      Top             =   1920
      Width           =   3975
   End
   Begin VB.TextBox szSubject 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   285
      Left            =   360
      TabIndex        =   3
      Top             =   1200
      Width           =   3975
   End
   Begin VB.TextBox szTo 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   285
      Left            =   360
      TabIndex        =   1
      Top             =   480
      Width           =   3255
   End
   Begin VB.Label Label5 
      BackColor       =   &H00000000&
      Caption         =   "Save the message as :"
      ForeColor       =   &H0000FFFF&
      Height          =   255
      Left            =   360
      TabIndex        =   9
      Top             =   6360
      Width           =   1695
   End
   Begin VB.Label Label4 
      BackColor       =   &H00000000&
      Caption         =   "Body of message :"
      ForeColor       =   &H0000FFFF&
      Height          =   255
      Left            =   360
      TabIndex        =   7
      Top             =   2640
      Width           =   1335
   End
   Begin VB.Label Label3 
      BackColor       =   &H00000000&
      Caption         =   "Attachment :"
      ForeColor       =   &H0000FFFF&
      Height          =   255
      Left            =   360
      TabIndex        =   4
      Top             =   1680
      Width           =   1095
   End
   Begin VB.Label Label2 
      BackColor       =   &H00000000&
      Caption         =   "Subject :"
      ForeColor       =   &H0000FFFF&
      Height          =   255
      Left            =   360
      TabIndex        =   2
      Top             =   960
      Width           =   1215
   End
   Begin VB.Label Label1 
      BackColor       =   &H00000000&
      Caption         =   "To :"
      ForeColor       =   &H0000FFFF&
      Height          =   255
      Left            =   360
      TabIndex        =   0
      Top             =   240
      Width           =   375
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function GetOpenFileName Lib "comdlg32.dll" Alias "GetOpenFileNameA" (pOpenfilename As OPENFILENAME) As Long
Private Declare Function GetSaveFileName Lib "comdlg32.dll" Alias "GetSaveFileNameA" (pOpenfilename As OPENFILENAME) As Long

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

Private Sub butatt_Click()
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
OFName.lpstrTitle = "Add a file..."
OFName.flags = 0
If GetOpenFileName(OFName) Then szAtt.Text = Trim$(OFName.lpstrFile)
End Sub

Private Sub butsave_Click()
Dim OFName As OPENFILENAME
OFName.lStructSize = Len(OFName)
OFName.hwndOwner = Me.hWnd
OFName.hInstance = App.hInstance
OFName.lpstrFilter = "EML Files (*.eml)" + Chr$(0) + "*.eml" + Chr$(0)
OFName.lpstrFile = Space$(254)
OFName.nMaxFile = 255
OFName.lpstrFileTitle = Space$(254)
OFName.nMaxFileTitle = 255
OFName.lpstrInitialDir = "C:\"
OFName.lpstrTitle = "Save EMail As..."
OFName.flags = 0
If GetSaveFileName(OFName) Then
szSave.Text = Trim$(OFName.lpstrFile)
szSave.Text = szSave.Text & ".eml"
End If
End Sub

