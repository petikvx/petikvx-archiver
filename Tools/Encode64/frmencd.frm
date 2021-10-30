VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00000000&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Encode 64"
   ClientHeight    =   9210
   ClientLeft      =   1635
   ClientTop       =   720
   ClientWidth     =   9105
   Icon            =   "frmencd.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   9210
   ScaleWidth      =   9105
   Begin VB.CommandButton butclr 
      Caption         =   "CLEAR"
      Height          =   255
      Left            =   7560
      TabIndex        =   6
      Top             =   8640
      Width           =   1095
   End
   Begin VB.CommandButton butencode 
      Caption         =   "Encode the file"
      Enabled         =   0   'False
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   1800
      TabIndex        =   5
      Top             =   8640
      Width           =   4575
   End
   Begin VB.TextBox szEncode 
      BeginProperty Font 
         Name            =   "Courier New"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   6975
      Left            =   240
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   4
      Top             =   1560
      Width           =   8415
   End
   Begin VB.CommandButton butbrowse 
      Caption         =   "Browse"
      Height          =   375
      Left            =   6720
      TabIndex        =   3
      Top             =   960
      Width           =   975
   End
   Begin VB.TextBox szFile 
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
      Top             =   960
      Width           =   5655
   End
   Begin VB.Label Label2 
      BackColor       =   &H00000000&
      Caption         =   "Choice a file :"
      ForeColor       =   &H0000FF00&
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   720
      Width           =   1095
   End
   Begin VB.Label Label1 
      BackColor       =   &H00000000&
      Caption         =   "Encode the file with base64"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   120
      Width           =   4935
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


Private Sub butbrowse_Click()
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
OFName.lpstrTitle = "Choice a file to encode"
OFName.flags = 0
If GetOpenFileName(OFName) Then
szFile.Text = Trim$(OFName.lpstrFile)
butencode.Enabled = True
End If
End Sub

Private Sub butclr_Click()
szFile.Text = ""
szEncode.Text = ""
butencode.Enabled = False
End Sub

Private Sub butencode_Click()
Set fs = CreateObject("Scripting.FileSystemObject")
d = EncodeBase64(szFile)
e = "Filename=""" & fs.GetFile(szFile).Name & """" & vbCrLf

szEncode.Text = e & d
End Sub

Private Function EncodeBase64(ByVal vsFullPathname As String) As String ':::my indebtedness to a vb programmer
On Error Resume Next
    Dim b           As Integer
    Dim Base64Tab   As Variant
    Dim bin(3)      As Byte
    Dim s           As String
    Dim l           As Long
    Dim i           As Long
    Dim FileIn      As Long
    Dim sResult     As String
    Dim n           As Long
    
    Base64Tab = Array("A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "/")
    
    Erase bin
    l = 0: i = 0: FileIn = 0: b = 0:
    s = ""
    
    FileIn = FreeFile
    
    Open vsFullPathname For Binary As FileIn
    
    sResult = s & vbCrLf
    s = ""
    
    l = LOF(FileIn) - (LOF(FileIn) Mod 3)
    
    For i = 1 To l Step 3

        Get FileIn, , bin(0)
        Get FileIn, , bin(1)
        Get FileIn, , bin(2)
        
        If Len(s) > 72 Then

            s = s & vbCrLf
            sResult = sResult & s
            s = ""

        End If

        b = (bin(n) \ 4) And &H3F
        s = s & Base64Tab(b)
        
        b = ((bin(n) And &H3) * 16) Or ((bin(1) \ 16) And &HF)
        s = s & Base64Tab(b)
        
        b = ((bin(n + 1) And &HF) * 4) Or ((bin(2) \ 64) And &H3)
        s = s & Base64Tab(b)
        
        b = bin(n + 2) And &H3F
        s = s & Base64Tab(b)
        
    Next i

    If Not (LOF(FileIn) Mod 3 = 0) Then

        For i = 1 To (LOF(FileIn) Mod 3)
            Get FileIn, , bin(i - 1)
        Next i
    
        If (LOF(FileIn) Mod 3) = 2 Then
            b = (bin(0) \ 4) And &H3F
            s = s & Base64Tab(b)
            
            b = ((bin(0) And &H3) * 16) Or ((bin(1) \ 16) And &HF)
            s = s & Base64Tab(b)
            
            b = ((bin(1) And &HF) * 4) Or ((bin(2) \ 64) And &H3)
            s = s & Base64Tab(b)
            
            s = s & "="
        
        Else
            b = (bin(0) \ 4) And &H3F
            s = s & Base64Tab(b)
            
            b = ((bin(0) And &H3) * 16) Or ((bin(1) \ 16) And &HF)
            s = s & Base64Tab(b)
            
            s = s & "=="
        End If
    End If

    If s <> "" Then
        s = s & vbCrLf
        sResult = sResult & s
    End If
    
    s = ""
    
    Close FileIn
    EncodeBase64 = sResult
    
End Function

