; ..\LIB\DSOUND.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DirectSoundCaptureCreate PROTO :DWORD,:DWORD,:DWORD
DirectSoundCaptureEnumerateA PROTO :DWORD,:DWORD
DirectSoundCaptureEnumerate equ <DirectSoundCaptureEnumerateA>

DirectSoundCreate PROTO :DWORD,:DWORD,:DWORD
DirectSoundEnumerateA PROTO :DWORD,:DWORD
DirectSoundEnumerate equ <DirectSoundEnumerateA>


