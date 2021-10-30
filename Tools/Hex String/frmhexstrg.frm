VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00000000&
   Caption         =   "Hex Conversion"
   ClientHeight    =   6465
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   10575
   LinkTopic       =   "Form1"
   ScaleHeight     =   6465
   ScaleWidth      =   10575
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "CLEAR"
      Height          =   375
      Left            =   9360
      TabIndex        =   7
      Top             =   6000
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "CONVERSION"
      Enabled         =   0   'False
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1095
      Left            =   7200
      TabIndex        =   6
      Top             =   480
      Width           =   2895
   End
   Begin VB.TextBox szhexs 
      BeginProperty Font 
         Name            =   "Courier New"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3975
      Left            =   240
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   5
      Top             =   1920
      Width           =   10095
   End
   Begin VB.TextBox szOut 
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
      Left            =   240
      TabIndex        =   4
      Top             =   1200
      Width           =   4815
   End
   Begin VB.CommandButton Command1 
      Caption         =   "BROWSE"
      Height          =   375
      Left            =   5280
      TabIndex        =   2
      Top             =   480
      Width           =   1095
   End
   Begin VB.TextBox szIn 
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
      Left            =   240
      Locked          =   -1  'True
      TabIndex        =   1
      Top             =   480
      Width           =   4815
   End
   Begin VB.Label Label2 
      BackColor       =   &H00000000&
      Caption         =   "Output File :"
      ForeColor       =   &H0000FFFF&
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   960
      Width           =   1095
   End
   Begin VB.Label Label1 
      BackColor       =   &H00000000&
      Caption         =   "Input File :"
      ForeColor       =   &H0000FFFF&
      Height          =   255
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function GetOpenFileName Lib "comdlg32.dll" Alias "GetOpenFileNameA" (pOpenfilename As OPENFILENAME) As Long
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


Private Sub Command1_Click()
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
OFName.lpstrTitle = "Choice a file to convert..."
OFName.flags = 0

If GetOpenFileName(OFName) Then
szIn.Text = Trim$(OFName.lpstrFile)
Command2.Enabled = True
End If


End Sub

Private Sub Command2_Click()
Dim lngbufferlen
Dim bbyte As Byte
Dim hexstring As String

If Len(szOut.Text) = 0 Then
MsgBox "Output File forgotten !", vbCritical, "ERROR"

Else


virh = ""
Randomize (Timer)
For I = 1 To 4
virh = virh & Chr(Int(Rnd(1) * 26) + 97)
Next I

read = ""
Randomize (Timer)
For I = 1 To 4
read = read & Chr(Int(Rnd(1) * 26) + 97)
Next I

dec = ""
Randomize (Timer)
For I = 1 To 6
dec = dec & Chr(Int(Rnd(1) * 26) + 97)
Next I

hexad = ""
Randomize (Timer)
For I = 1 To 5
hexad = hexad & Chr(Int(Rnd(1) * 26) + 97)
Next I

octe = ""
Randomize (Timer)
For I = 1 To 4
octe = octe & Chr(Int(Rnd(1) * 26) + 97)
Next I

Open szIn.Text For Binary As #1
DoEvents
Do While Not EOF(1)
DoEvents
Get #1, , bbyte
e = Hex(bbyte)
If Len(e) = 1 Then e = "0" & Hex(bbyte)
hexstring = hexstring & e
Loop
Close #1

vbs = "On Error Resume Next" & vbCrLf & _
        "Set fso=CreateObject(""Scripting.FileSystemObject"")" & vbCrLf & vbCrLf & _
        virh & "=""" & hexstring & """" & vbCrLf & vbCrLf
        
vbs2 = read & "=" & dec & "(" & virh & ")" & vbCrLf & _
        "Set r=fso.CreateTextFile(""" & szOut.Text & """,2)" & vbCrLf & _
        "r.Write " & read & vbCrLf & _
        "r.Close" & vbCrLf & vbCrLf
        
vbs3 = "Function " & dec & "(" & octe & ")" & vbCrLf & _
        "On Error Resume Next" & vbCrLf & _
        "For " & hexad & "=1 to Len(" & octe & ") Step 2" & vbCrLf & _
        dec & "=" & dec & " & Chr(""&h"" & Mid(" & octe & ", " & hexad & ", 2))" & vbCrLf & _
        "Next" & vbCrLf & _
        "End Function"

szhexs.Text = vbs & vbs2 & vbs3

End If
End Sub

Private Sub Command3_Click()
szOut.Text = ""
szIn.Text = ""
szhexs.Text = ""
Command2.Enabled = False
End Sub

