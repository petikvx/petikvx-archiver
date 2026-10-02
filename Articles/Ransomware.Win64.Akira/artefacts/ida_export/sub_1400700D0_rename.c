void sub_1400700D0()
{
  __int64 v0; // rbx
  __int64 v1; // r8
  const CHAR *v2; // r8
  int v3; // eax
  __int64 v4; // rcx
  WCHAR *lpWideCharStr; // rcx
  const CHAR *v6; // r8
  void *v7; // rcx
  CHAR *v8; // rcx
  const CHAR *v9; // r8
  int v10; // eax
  __int64 v11; // rcx
  WCHAR *v12; // rcx
  const CHAR *v13; // r8
  void *v14; // rcx
  CHAR *v15; // rcx
  LPCCH lpMultiByteStr[2]; // [rsp+30h] [rbp-29h] BYREF
  int cbMultiByte[4]; // [rsp+40h] [rbp-19h]
  __int128 v18; // [rsp+50h] [rbp-9h] BYREF
  __m128i si128; // [rsp+60h] [rbp+7h]
  _BYTE v20[16]; // [rsp+78h] [rbp+1Fh] BYREF
  LPWSTR v21[2]; // [rsp+88h] [rbp+2Fh] BYREF
  int cchWideChar[4]; // [rsp+98h] [rbp+3Fh]

  *(_OWORD *)lpMultiByteStr = 0;
  *(_OWORD *)cbMultiByte = 0;
  v0 = -1;
  v1 = -1;
  do
    ++v1;
  while ( aAkira[v1] != 0 );
  sub_1400376B0(a1: lpMultiByteStr, a2: aAkira);
  v2 = (const CHAR *)lpMultiByteStr;
  if ( *(_QWORD *)&cbMultiByte[2] >= 0x10u )
    v2 = lpMultiByteStr[0];
  v3 = MultiByteToWideChar(
         CodePage: 0,
         dwFlags: 0,
         lpMultiByteStr: v2,
         cbMultiByte: cbMultiByte[0],
         lpWideCharStr: nullptr,
         cchWideChar: 0);
  __eh34_enter_wind_state(-1, 0);
  if ( v3 != 0 )
  {
    *(_OWORD *)v21 = 0;
    *(_OWORD *)cchWideChar = 0;
    sub_1400559F0(a1: v21, a2: 0, a3: v3);
    lpWideCharStr = (WCHAR *)v21;
    if ( *(_QWORD *)&cchWideChar[2] >= 8u )
      lpWideCharStr = v21[0];
    v6 = (const CHAR *)lpMultiByteStr;
    if ( *(_QWORD *)&cbMultiByte[2] >= 0x10u )
      v6 = lpMultiByteStr[0];
    MultiByteToWideChar(
      CodePage: 0,
      dwFlags: 0,
      lpMultiByteStr: v6,
      cbMultiByte: cbMultiByte[0],
      lpWideCharStr,
      cchWideChar: cchWideChar[0]);
    v18 = *(_OWORD *)v21;
    si128 = *(__m128i *)cchWideChar;
    *(__m128i *)cchWideChar = _mm_load_si128((const __m128i *)&xmmword_1400E24F0);
    LOWORD(v21[0]) = 0;
  }
  else
  {
    v18 = 0;
    si128 = _mm_load_si128((const __m128i *)&xmmword_1400E24F0);
    LOWORD(v18) = 0;
  }
  __eh34_enter_wind_state(0, 1);
  sub_1400715A0(a1: v4, a2: v20, a3: &v18);
  if ( si128.m128i_i64[1] >= 8uLL )
  {
    v7 = (void *)v18;
    if ( (unsigned __int64)(2 * si128.m128i_i64[1] + 2) >= 0x1000 )
    {
      v7 = *(void **)(v18 - 8);
      if ( (unsigned __int64)(v18 - (_QWORD)v7 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v7);
  }
  if ( *(_QWORD *)&cbMultiByte[2] >= 0x10u )
  {
    v8 = (CHAR *)lpMultiByteStr[0];
    if ( (unsigned __int64)(*(_QWORD *)&cbMultiByte[2] + 1LL) >= 0x1000 )
    {
      v8 = *((CHAR **)lpMultiByteStr[0] - 1);
      if ( (unsigned __int64)(lpMultiByteStr[0] - (LPCCH)v8 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v8);
  }
  *(_OWORD *)lpMultiByteStr = 0;
  *(_OWORD *)cbMultiByte = 0;
  do
    ++v0;
  while ( aArika[v0] != 0 );
  if ( __eh34_unwind(1) )
  {
unwind_state_1:
    unknown_libname_4(a1: &v18);
    __eh34_continue_unwinding(1, 0);
  }
  __eh34_exit_wind_state(1, 0);
  if ( __eh34_unwind(0) )
  {
unwind_state_0:
    sub_1400371B0(a1: lpMultiByteStr);
    __eh34_propagate_exception_into_caller(0, -1);
  }
  __eh34_exit_wind_state(0, -1);
  sub_1400376B0(a1: lpMultiByteStr, a2: aArika);
  v9 = (const CHAR *)lpMultiByteStr;
  if ( *(_QWORD *)&cbMultiByte[2] >= 0x10u )
    v9 = lpMultiByteStr[0];
  v10 = MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: v9,
          cbMultiByte: cbMultiByte[0],
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  __eh34_enter_wind_state(-1, 0);
  if ( v10 != 0 )
  {
    *(_OWORD *)v21 = 0;
    *(_OWORD *)cchWideChar = 0;
    sub_1400559F0(a1: v21, a2: 0, a3: v10);
    v12 = (WCHAR *)v21;
    if ( *(_QWORD *)&cchWideChar[2] >= 8u )
      v12 = v21[0];
    v13 = (const CHAR *)lpMultiByteStr;
    if ( *(_QWORD *)&cbMultiByte[2] >= 0x10u )
      v13 = lpMultiByteStr[0];
    MultiByteToWideChar(
      CodePage: 0,
      dwFlags: 0,
      lpMultiByteStr: v13,
      cbMultiByte: cbMultiByte[0],
      lpWideCharStr: v12,
      cchWideChar: cchWideChar[0]);
    v18 = *(_OWORD *)v21;
    si128 = *(__m128i *)cchWideChar;
    *(__m128i *)cchWideChar = _mm_load_si128((const __m128i *)&xmmword_1400E24F0);
    LOWORD(v21[0]) = 0;
  }
  else
  {
    v18 = 0;
    si128 = _mm_load_si128((const __m128i *)&xmmword_1400E24F0);
    LOWORD(v18) = 0;
  }
  __eh34_enter_wind_state(0, 1);
  sub_1400715A0(a1: v11, a2: v20, a3: &v18);
  if ( si128.m128i_i64[1] >= 8uLL )
  {
    v14 = (void *)v18;
    if ( (unsigned __int64)(2 * si128.m128i_i64[1] + 2) >= 0x1000 )
    {
      v14 = *(void **)(v18 - 8);
      if ( (unsigned __int64)(v18 - (_QWORD)v14 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v14);
  }
  if ( *(_QWORD *)&cbMultiByte[2] >= 0x10u )
  {
    v15 = (CHAR *)lpMultiByteStr[0];
    if ( (unsigned __int64)(*(_QWORD *)&cbMultiByte[2] + 1LL) >= 0x1000 )
    {
      v15 = *((CHAR **)lpMultiByteStr[0] - 1);
      if ( (unsigned __int64)(lpMultiByteStr[0] - (LPCCH)v15 - 8) > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    j_j_free(Block: v15);
  }
  if ( __eh34_unwind(1) )
    goto unwind_state_1;
  __eh34_exit_wind_state(1, 0);
  if ( __eh34_unwind(0) )
    goto unwind_state_0;
  __eh34_exit_wind_state(0, -1);
}