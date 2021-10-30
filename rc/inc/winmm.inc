; ..\LIB\WINMM.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~

CloseDriver PROTO :DWORD,:DWORD,:DWORD
DefDriverProc PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DriverCallback PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DrvGetModuleHandle PROTO :DWORD
GetDriverModuleHandle PROTO :DWORD
MigrateAllDrivers PROTO
MigrateMidiUser PROTO
MigrateSoundEvents PROTO
NotifyCallbackData PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OpenDriver PROTO :DWORD,:DWORD,:DWORD
PlaySoundA PROTO :DWORD,:DWORD,:DWORD
PlaySound equ <PlaySoundA>

SendDriverMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
WOW32DriverCallback PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WOW32ResolveMultiMediaHandle PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WOWAppExit PROTO :DWORD
aux32Message PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
auxGetDevCapsA PROTO :DWORD,:DWORD,:DWORD
auxGetDevCaps equ <auxGetDevCapsA>

auxGetNumDevs PROTO
auxGetVolume PROTO :DWORD,:DWORD
auxOutMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
auxSetVolume PROTO :DWORD,:DWORD
joy32Message PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
joyConfigChanged PROTO :DWORD
joyGetDevCapsA PROTO :DWORD,:DWORD,:DWORD
joyGetDevCaps equ <joyGetDevCapsA>

joyGetNumDevs PROTO
joyGetPos PROTO :DWORD,:DWORD
joyGetPosEx PROTO :DWORD,:DWORD
joyGetThreshold PROTO :DWORD,:DWORD
joyReleaseCapture PROTO :DWORD
joySetCapture PROTO :DWORD,:DWORD,:DWORD,:DWORD
joySetThreshold PROTO :DWORD,:DWORD
mci32Message PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mciDriverNotify PROTO :DWORD,:DWORD,:DWORD
mciDriverYield PROTO :DWORD
mciExecute PROTO :DWORD
mciFreeCommandResource PROTO :DWORD
mciGetCreatorTask PROTO :DWORD
mciGetDeviceIDA PROTO :DWORD
mciGetDeviceID equ <mciGetDeviceIDA>

mciGetDeviceIDFromElementIDA PROTO :DWORD,:DWORD
mciGetDeviceIDFromElementID equ <mciGetDeviceIDFromElementIDA>

mciGetDriverData PROTO :DWORD
mciGetErrorStringA PROTO :DWORD,:DWORD,:DWORD
mciGetErrorString equ <mciGetErrorStringA>

mciGetYieldProc PROTO :DWORD,:DWORD
mciLoadCommandResource PROTO :DWORD,:DWORD,:DWORD
mciSendCommandA PROTO :DWORD,:DWORD,:DWORD,:DWORD
mciSendCommand equ <mciSendCommandA>

mciSendStringA PROTO :DWORD,:DWORD,:DWORD,:DWORD
mciSendString equ <mciSendStringA>

mciSetDriverData PROTO :DWORD,:DWORD
mciSetYieldProc PROTO :DWORD,:DWORD,:DWORD
mid32Message PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
midiConnect PROTO :DWORD,:DWORD,:DWORD
midiDisconnect PROTO :DWORD,:DWORD,:DWORD
midiInAddBuffer PROTO :DWORD,:DWORD,:DWORD
midiInClose PROTO :DWORD
midiInGetDevCapsA PROTO :DWORD,:DWORD,:DWORD
midiInGetDevCaps equ <midiInGetDevCapsA>

midiInGetErrorTextA PROTO :DWORD,:DWORD,:DWORD
midiInGetErrorText equ <midiInGetErrorTextA>

midiInGetID PROTO :DWORD,:DWORD
midiInGetNumDevs PROTO
midiInMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
midiInOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
midiInPrepareHeader PROTO :DWORD,:DWORD,:DWORD
midiInReset PROTO :DWORD
midiInStart PROTO :DWORD
midiInStop PROTO :DWORD
midiInUnprepareHeader PROTO :DWORD,:DWORD,:DWORD
midiOutCacheDrumPatches PROTO :DWORD,:DWORD,:DWORD,:DWORD
midiOutCachePatches PROTO :DWORD,:DWORD,:DWORD,:DWORD
midiOutClose PROTO :DWORD
midiOutGetDevCapsA PROTO :DWORD,:DWORD,:DWORD
midiOutGetDevCaps equ <midiOutGetDevCapsA>

midiOutGetErrorTextA PROTO :DWORD,:DWORD,:DWORD
midiOutGetErrorText equ <midiOutGetErrorTextA>

midiOutGetID PROTO :DWORD,:DWORD
midiOutGetNumDevs PROTO
midiOutGetVolume PROTO :DWORD,:DWORD
midiOutLongMsg PROTO :DWORD,:DWORD,:DWORD
midiOutMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
midiOutOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
midiOutPrepareHeader PROTO :DWORD,:DWORD,:DWORD
midiOutReset PROTO :DWORD
midiOutSetVolume PROTO :DWORD,:DWORD
midiOutShortMsg PROTO :DWORD,:DWORD
midiOutUnprepareHeader PROTO :DWORD,:DWORD,:DWORD
midiStreamClose PROTO :DWORD
midiStreamOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
midiStreamOut PROTO :DWORD,:DWORD,:DWORD
midiStreamPause PROTO :DWORD
midiStreamPosition PROTO :DWORD,:DWORD,:DWORD
midiStreamProperty PROTO :DWORD,:DWORD,:DWORD
midiStreamRestart PROTO :DWORD
midiStreamStop PROTO :DWORD
mixerClose PROTO :DWORD
mixerGetControlDetailsA PROTO :DWORD,:DWORD,:DWORD
mixerGetControlDetails equ <mixerGetControlDetailsA>

mixerGetDevCapsA PROTO :DWORD,:DWORD,:DWORD
mixerGetDevCaps equ <mixerGetDevCapsA>

mixerGetID PROTO :DWORD,:DWORD,:DWORD
mixerGetLineControlsA PROTO :DWORD,:DWORD,:DWORD
mixerGetLineControls equ <mixerGetLineControlsA>

mixerGetLineInfoA PROTO :DWORD,:DWORD,:DWORD
mixerGetLineInfo equ <mixerGetLineInfoA>

mixerGetNumDevs PROTO
mixerMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
mixerOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mixerSetControlDetails PROTO :DWORD,:DWORD,:DWORD
mmDrvInstall PROTO :DWORD,:DWORD,:DWORD,:DWORD
mmGetCurrentTask PROTO
mmTaskBlock PROTO :DWORD
mmTaskCreate PROTO :DWORD,:DWORD,:DWORD
mmTaskSignal PROTO :DWORD
mmTaskYield PROTO
mmioAdvance PROTO :DWORD,:DWORD,:DWORD
mmioAscend PROTO :DWORD,:DWORD,:DWORD
mmioClose PROTO :DWORD,:DWORD
mmioCreateChunk PROTO :DWORD,:DWORD,:DWORD
mmioDescend PROTO :DWORD,:DWORD,:DWORD,:DWORD
mmioFlush PROTO :DWORD,:DWORD
mmioGetInfo PROTO :DWORD,:DWORD,:DWORD
mmioInstallIOProcA PROTO :DWORD,:DWORD,:DWORD
mmioInstallIOProc equ <mmioInstallIOProcA>

mmioOpenA PROTO :DWORD,:DWORD,:DWORD
mmioOpen equ <mmioOpenA>

mmioRead PROTO :DWORD,:DWORD,:DWORD
mmioRenameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
mmioRename equ <mmioRenameA>

mmioSeek PROTO :DWORD,:DWORD,:DWORD
mmioSendMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
mmioSetBuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD
mmioSetInfo PROTO :DWORD,:DWORD,:DWORD
mmioStringToFOURCCA PROTO :DWORD,:DWORD
mmioStringToFOURCC equ <mmioStringToFOURCCA>

mmioWrite PROTO :DWORD,:DWORD,:DWORD
mmsystemGetVersion PROTO
mod32Message PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mxd32Message PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sndPlaySoundA PROTO :DWORD,:DWORD
sndPlaySound equ <sndPlaySoundA>

tid32Message PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
timeBeginPeriod PROTO :DWORD
timeEndPeriod PROTO :DWORD
timeGetDevCaps PROTO :DWORD,:DWORD
timeGetSystemTime PROTO :DWORD,:DWORD
timeGetTime PROTO
timeKillEvent PROTO :DWORD
timeSetEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
waveInAddBuffer PROTO :DWORD,:DWORD,:DWORD
waveInClose PROTO :DWORD
waveInGetDevCapsA PROTO :DWORD,:DWORD,:DWORD
waveInGetDevCaps equ <waveInGetDevCapsA>

waveInGetErrorTextA PROTO :DWORD,:DWORD,:DWORD
waveInGetErrorText equ <waveInGetErrorTextA>

waveInGetID PROTO :DWORD,:DWORD
waveInGetNumDevs PROTO
waveInGetPosition PROTO :DWORD,:DWORD,:DWORD
waveInMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
waveInOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
waveInPrepareHeader PROTO :DWORD,:DWORD,:DWORD
waveInReset PROTO :DWORD
waveInStart PROTO :DWORD
waveInStop PROTO :DWORD
waveInUnprepareHeader PROTO :DWORD,:DWORD,:DWORD
waveOutBreakLoop PROTO :DWORD
waveOutClose PROTO :DWORD
waveOutGetDevCapsA PROTO :DWORD,:DWORD,:DWORD
waveOutGetDevCaps equ <waveOutGetDevCapsA>

waveOutGetErrorTextA PROTO :DWORD,:DWORD,:DWORD
waveOutGetErrorText equ <waveOutGetErrorTextA>

waveOutGetID PROTO :DWORD,:DWORD
waveOutGetNumDevs PROTO
waveOutGetPitch PROTO :DWORD,:DWORD
waveOutGetPlaybackRate PROTO :DWORD,:DWORD
waveOutGetPosition PROTO :DWORD,:DWORD,:DWORD
waveOutGetVolume PROTO :DWORD,:DWORD
waveOutMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
waveOutOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
waveOutPause PROTO :DWORD
waveOutPrepareHeader PROTO :DWORD,:DWORD,:DWORD
waveOutReset PROTO :DWORD
waveOutRestart PROTO :DWORD
waveOutSetPitch PROTO :DWORD,:DWORD
waveOutSetPlaybackRate PROTO :DWORD,:DWORD
waveOutSetVolume PROTO :DWORD,:DWORD
waveOutUnprepareHeader PROTO :DWORD,:DWORD,:DWORD
waveOutWrite PROTO :DWORD,:DWORD,:DWORD
wid32Message PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
winmmSetDebugLevel PROTO :DWORD
wod32Message PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

