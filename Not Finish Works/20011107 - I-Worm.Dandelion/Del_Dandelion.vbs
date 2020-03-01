On Error Resume Next
MsgBox "This freeware will help you to delete the I-Worm.Dandelion",vbinformation,"Remove Petik Tool (I-Worm.Dandelion)"
Set ws=CreateObject("WScript.Shell")
Set fso=CreateObject("Scripting.FileSystemObject")
Set win=fso.GetSpecialFolder(0)
Set sys=fso.GetSpecialFolder(1)

ws.RegDelete ("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\MS Explor")
If fso.FileExists(sys&"\Explor.exe") Then
fso.DeleteFile(sys&"\Explor.exe")
End If
If fso.FolderExists(sys&"\Plg_PTK") Then
fso.DeleteFolder(sys&"\Plg_PTK")
End If

MsgBox "Look at the file "&win&"\dandelion.txt"&vbcrlf&"to delete the copies of the worm.",vbinformation,"Remove Petik Tool (I-Worm.Dandelion)"

MsgBox "Your computer is now clean. Have a nice day.",vbinformation,"Remove Petik Tool (I-Worm.Dandelion)"
