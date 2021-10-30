'PetiK's Protect VBS Worm
'On Error Resume Next
ppvwtitle="PetiK's Protect VBS Worm"
MsgBox "PPVBSW 1.0 coded by PetiK - 2002",vbinformation,ppvwtitle
Set fso=CreateObject("Scripting.FileSystemObject")
Set ws=CreateObject("WScript.Shell")

vbsfile=InputBox("Enter the full name of the VBS file:"&VbCrLf&VbCrLf& _
		"To install type ""INSTALL"""&VbCrLf& _
		"To uninstall type ""UNINSTALL""","PetiK's Protect VBS Worm",fso.GetSpecialFolder(0))

If Len(vbsfile)=0 Then
WScript.Quit
End If

If vbsfile="INSTALL" Then
fso.CreateFolder("C:\PPVBSW")
fso.GetFile(WScript.ScriptFullName).Copy("C:\PPVBSW\ProtectVBSWorm.vbs")
Set rm=fso.CreateTextFile("C:\PPVBSW\ReadMe.txt",True,2)
rm.WriteLine "Name : PetiK's Protect VBS Worm (PPVBSW)"
rm.WriteLine "Version : 1.0"
rm.WriteLine "Author : PetiK"
rm.WriteLine "Language : VBS"
rm.WriteLine ""
rm.WriteLine "Comments : To control some suspicious VBS files."
rm.Close
MsgBox "PPVBSW installed on system",vbinformation,ppvwtitle
WScript.Quit
End If

If vbsfile="UNINSTALL" Then
fso.DeleteFile("C:\PPVBSW\ReadMe.txt")
fso.Deletefile("C:\PPVBSW\ProtectVBSWorm.vbs")
fso.DeleteFolder("C:\PPVBSW")
MsgBox "PPVBSW uninstalled from system",vbinformation,ppvwtitle
ws.Run fso.GetSpecialFolder(0)&"\notepad.exe"
WScript.Quit
End If

'Check if the file exists
If not fso.FileExists(vbsfile) Then
MsgBox "This file doesn't exist !",vbcritical,ppvwtitle
WScript.Quit
End If

'Check if it is a VBS file (.vbs)
If right(vbsfile,4) <> ".vbs" Then
MsgBox "This file is not a VBS file (.vbs) !",vbcritical,ppvwtitle
WScript.Quit
End If

Set fl=fso.OpenTextFile(vbsfile,1)
readvbs=fl.ReadAll
fl.Close

numr=""
For i = 1 To 8
randomize(timer)
numr=numr & Chr(int(rnd(1)*9)+48)
Next
Set news=fso.CreateTextFile("ppvbsw_"&numr&".txt",True,8)
news.WriteLine "Name of file : "&vbsfile
news.WriteLine "Size of file : "&Len(readvbs)&" bytes"
news.WriteLine "Date and Time of analysis : "&date&" "&time
news.WriteLine ""

'Check for Regedit
If InStr(readvbs,"CurrentVersion\Run") <> 0 Then
news.WriteLine "Run with regedit (Run) : Yes"
Else
news.WriteLine "Run with regedit (Run) : No"
End If
If InStr(readvbs,"CurrentVersion\RunServices") <> 0 Then
news.WriteLine "Run with regedit (RunServices) : Yes"
Else
news.WriteLine "Run with regedit (RunServices) : No"
End If
news.WriteLine ""

'Check if infect other file
If InStr(readvbs,"GetExtensionName") <> 0 Then
news.WriteLine "Perhaps infects some files : Yes"
Else
news.WriteLine "Perhaps infects some files : No"
End If
news.WriteLine ""

'Check for Outlook
If InStr(readvbs,"Outlook.Application") <> 0 Then
MsgBox "This suspect file uses Outlook to spread",vbcritical,ppvwtitle
news.WriteLine "Spread with Outlook : Yes"
Else
news.WriteLine "Spread with Outlook : No"
End If

'Check for Word
If InStr(readvbs,"Word.Application") <> 0 Then
MsgBox "This suspect file uses Word to infect some files or spread",vbcritical,ppvwtitle
news.WriteLine "Spread or Infect with Word : Yes"
Else
news.WriteLine "Spread or Infect with Word : No"
End If
news.WriteLine ""

'Check for some known VBS worm
news.WriteLine "Possible VBS Worm :"
kworm "Cool Notepad Demo","I-Worm.CoolNotepad"
kworm "I'm proud to say that you are infected by FireburN","I-Worm.FireBurn"
kworm "FRIEND_MESSAGE.TXT.vbs","I-Worm.FriendMess"
kworm "Lee","I-Worm.Lee family"
kworm "ILOVEYOU","I-Worm.Loveletter.A"
kworm "mothersday.vbs","I-Worm.Loveletter.B"
kworm "Very Funny.vbs","I-Worm.Loveletter.C"
kworm "Susitikim shi vakara kavos puodukui...","I-Worm.Loveletter.D"
kworm "Bill Gates is guitly of monopoly. Here is the proof","I-Worm.Monopoly"
kworm "DocXlsMdbBmpMp3TxtJpgGifMovUrlHtmTxt","I-Worm.NewLove"
kworm "US PRESIDENT AND FBI SECRETS =PLEASE VISIT","I-Worm.Plan"
kworm "LIFE_STAGES.TXT.SHS","I-Worm.ScrapWorm"
kworm "TIMOFONICA.TXT.vbs","I-Worm.Timofonica"

news.Close

ws.Run "ppvbsw_"&numr&".txt"

Sub kworm(strg,name)
If InStr(readvbs,strg) <> 0 Then
news.WriteLine name
End If
End Sub