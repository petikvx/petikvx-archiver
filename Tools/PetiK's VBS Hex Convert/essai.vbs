On Error Resume Next

Set fso=CreateObject("Scripting.FileSystemObject")
Set ws=CreateObject("WScript.Shell")
crlf = Chr(13) & Chr(10)

MsgBox "Dossier Windows : " & fso.GetSpecialFolder(0),vbinformation,"Essai"

ws.Run "notepad.exe"
wscript.Sleep 200
ws.SendKeys "Date : " & date & vbLf
ws.SendKeys "Time : " & time & crlf
x = 0
Do Until x=6
num = Int((6 * Rnd) + 1)
If num = 1 Then
mess = "You're infected by my new VBS virus. " & VbLf & "Don't panic, it's not Dangerous" & vbCrlf
ElseIf num = 2 Then mess = "Why do you click unknown file ??" & crlf
ElseIf num = 3 Then mess = "A new creation coded by PetiK/[b8]" & crlf
ElseIf num = 4 Then mess = "Contact an AV support to disinfect your system" & crlf
ElseIf num = 5 Then mess = "Be careful next time" & crlf
ElseIf num = 6 Then mess = "Curiosity is bad" & crlf
End If
For i = 1 to Len(mess)
ws.SendKeys Mid(mess,i,1)
wscript.Sleep 50
Next
x=x+1
Loop
