VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00000000&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "PetiK's Script Encrypt"
   ClientHeight    =   3900
   ClientLeft      =   570
   ClientTop       =   1650
   ClientWidth     =   7230
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3900
   ScaleWidth      =   7230
   Begin VB.TextBox szKey 
      Height          =   285
      Left            =   2160
      MaxLength       =   3
      TabIndex        =   2
      Text            =   "128"
      Top             =   3480
      Width           =   495
   End
   Begin VB.CommandButton butencrypt 
      Caption         =   "Encrypt"
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   3480
      Width           =   1095
   End
   Begin VB.TextBox szVBS 
      Height          =   3255
      Left            =   120
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   0
      Top             =   120
      Width           =   6975
   End
   Begin VB.Label Label1 
      BackColor       =   &H00000000&
      Caption         =   "(Between 100 and 256)"
      ForeColor       =   &H00FFFFFF&
      Height          =   255
      Left            =   2880
      TabIndex        =   3
      Top             =   3480
      Width           =   2415
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub butencrypt_Click()

If szKey.Text > 256 Then
MsgBox "Less than 256", vbCritical, "ERROR"

ElseIf szKey.Text < 100 Then MsgBox "More than 100", vbCritical, "ERROR"

Else

d1 = ""
Randomize (Timer)
d1 = Chr(Int(Rnd(1) * 26) + 65)
d2 = ""
Randomize (Timer)
d2 = Chr(Int(Rnd(1) * 26) + 65)
d3 = ""
Randomize (Timer)
d3 = Chr(Int(Rnd(1) * 26) + 65)

vbsn = ""
Randomize (Timer)
For I = 1 To 4
vbsn = vbsn & Chr(Int(Rnd(1) * 26) + 97)
Next I

e = ""
For I = 1 To Len(szVBS.Text)
f = Chr(Asc(Mid(szVBS.Text, I, 1)) Xor szKey.Text)
e = e & f
'e = e & Hex(f)
Next

vbsc = "On Error Resume Next" & vbCrLf & _
        "Execute " & d1 & "(""" & e & """)" & vbCrLf & _
        "Function " & d1 & "(" & vbsn & ")" & vbCrLf & _
        "For " & d2 & "=1 to Len(" & vbsn & ")" & vbCrLf & _
        d1 & "=" & d1 & " & Chr(Asc(Mid(" & vbsn & "," & d2 & ",1)) Xor " & szKey.Text & ")" & vbCrLf & _
        "Next" & vbCrLf & _
        "End Function"

szVBS.Text = vbsc

End If

End Sub
