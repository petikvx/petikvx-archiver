; #########################################################################
;
;                      Include file for MASM32.LIB
;
; #########################################################################


; for both --> arg num, buffer
ArgCl PROTO :DWORD,:DWORD   ; GUI mode version
ArgClC PROTO :DWORD,:DWORD  ; console mode version

GetCL PROTO :DWORD,:DWORD

a2dw   PROTO :DWORD
atodw  PROTO :DWORD          ; return value in eax
htodw  PROTO :DWORD          ; return value in eax
dwtoa  PROTO :DWORD,:DWORD   ; value - buffer
dw2a   PROTO :DWORD,:DWORD
dw2hex PROTO :DWORD,:DWORD

FloatToStr	proto	stdcall fpin: QWORD, szDbl: PTR CHAR
StrToFloat	proto	stdcall szIn: PTR BYTE, fpout: PTR DWORD

InString PROTO :DWORD,:DWORD,:DWORD ; StartPos - lpszString - lpszSubStr

lcase PROTO :DWORD          ; address string
ucase PROTO :DWORD          ; address string

ltrim PROTO :DWORD,:DWORD   ; source - dest
rtrim PROTO :DWORD,:DWORD   ; source - dest

lnstr  PROTO :DWORD          ; length in eax
StrLen PROTO :DWORD

revstr PROTO :DWORD,:DWORD

; ---------------------------------------------------------------
; Note that these following 3 procedures are no longer included
; in the library, they have been replaced with later and faster
; procedures. Code written with these procedures is still
; functional by means of the following equates which equates
; them directly to the later procedures.
; ---------------------------------------------------------------

; lstr   PROTO :DWORD,:DWORD,:DWORD    ; source - substring - length
; rstr   PROTO :DWORD,:DWORD,:DWORD    ; source - substring - length
; midstr PROTO :DWORD,:DWORD,:DWORD,:DWORD

szCatStr PROTO :DWORD,:DWORD
szLeft   PROTO :DWORD,:DWORD,:DWORD
szRight  PROTO :DWORD,:DWORD,:DWORD
szMid    PROTO :DWORD,:DWORD,:DWORD,:DWORD

; -----------------------------------------
; Note that the equates MUST be put after
; the procedure names that they equate to.
; -----------------------------------------
lstr equ <szLeft>
rstr equ <szRight>
midstr equ <szMid>
; ******************************

StripRangeI PROTO :DWORD,:DWORD,:BYTE,:BYTE
StripRangeX PROTO :DWORD,:DWORD,:BYTE,:BYTE

MemCopy PROTO :DWORD,:DWORD,:DWORD  ; source - dest - length

GetAppPath PROTO :DWORD     ; buffer has app path
exist PROTO :DWORD
filesize PROTO :DWORD

FrameCtrl PROTO :DWORD,:DWORD,:DWORD,:DWORD
FrameWindow PROTO :DWORD,:DWORD,:DWORD,:DWORD
FrameGrp PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

Frame3D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
line   PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
circle PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

StdOut      PROTO :DWORD
StdIn       PROTO :DWORD,:DWORD
locate      PROTO :DWORD,:DWORD
ClearScreen PROTO


