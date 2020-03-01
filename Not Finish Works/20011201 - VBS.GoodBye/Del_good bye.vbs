On Error Resume Next
MsgBox "This freeware will help you to delete the VBS.GoodBye",vbinformation,"Remove PetiK Tool (VBS.GoodBye)"
Set ws=CreateObject("WScript.Shell")
Set fso=CreateObject("Scripting.FileSystemObject")
Set win=fso.GetSpecialFolder(0)
Set sys=fso.GetSpecialFolder(1)

If fso.FileExists(sys&"\Cmmon32.vbs") Then
MsgBox "You're infected by VBS.GoodBye",vbcritical,"Remove PetiK Tool (VBS.GoodBye)"
ws.RegDelete ("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\MS Cmmon32")
start=ws.RegRead ("HKEY_USERS\.DEFAULT\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders\Startup")

fso.DeleteFile(sys&"\Cmmon32.vbs")
fso.DeleteFile(win&"\New_Prog.exe")
fso.DeleteFolder(sys&"\Plg_PTK")

' For Worm.MaloTeyA
fso.DeleteFile(win&"\RUNW32.EXE")
fso.DeleteFile(sys&"\MSVA.EXE")
fso.DeleteFile(start&"\VARegistered.htm")
Else
MsgBox "Your computer is not infected by VBS.GoodBye",vbinformation,"Remove PetiK Tool (VBS.GoodBye)"
WScript.Quit
End If


MsgBox "Your computer is now clean. Have a nice day.",vbinformation,"Remove PetiK Tool (VBS.GoodBye)"
