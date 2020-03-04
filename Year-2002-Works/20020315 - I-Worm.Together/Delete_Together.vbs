On Error Resume Next
MsgBox "This freeware will help you to delete the I-Worm.Together",vbinformation,"Remove Petik Tool (I-Worm.Together)"
Set ws=CreateObject("WScript.Shell")
Set fso=CreateObject("Scripting.FileSystemObject")
Set win=fso.GetSpecialFolder(0)
Set sys=fso.GetSpecialFolder(1)

ws.RegDelete ("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Encode Base64")
fso.DeleteFile(sys&"\eBase64.exe")
fso.DeleteFile(sys&"\eBase.vbs")
fso.DeleteFile(sys&"\together.ini")

