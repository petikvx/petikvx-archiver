char __fastcall sub_140042C90(__int64 a1)
{
  __int64 v2; // r8
  const CHAR *v3; // r8
  int v4; // eax
  WCHAR *lpWideCharStr; // rcx
  const CHAR *v6; // r8
  __int64 v7; // rcx
  __int64 v8; // rdx
  void *v9; // rcx
  void *v10; // rcx
  CHAR *v11; // rcx
  void *v12; // rcx
  char result; // al
  __int64 v14; // rbx
  __int64 v15; // r8
  __int64 v16; // rax
  LPCCH lpMultiByteStr[2]; // [rsp+40h] [rbp-1D8h] BYREF
  __m128i cbMultiByte; // [rsp+50h] [rbp-1C8h]
  std::exception *v19; // [rsp+68h] [rbp-1B0h] BYREF
  _QWORD v20[3]; // [rsp+70h] [rbp-1A8h] BYREF
  unsigned __int64 v21; // [rsp+88h] [rbp-190h]
  LPWSTR v22[2]; // [rsp+90h] [rbp-188h] BYREF
  int cchWideChar[4]; // [rsp+A0h] [rbp-178h] BYREF
  __int128 v24; // [rsp+B0h] [rbp-168h] BYREF
  __m128i si128; // [rsp+C0h] [rbp-158h]
  _QWORD v26[4]; // [rsp+D0h] [rbp-148h] BYREF
  _QWORD v27[34]; // [rsp+F0h] [rbp-128h] BYREF

  if ( *(_QWORD *)(a1 + 16) == 0 )
    return 0;
  *(_OWORD *)lpMultiByteStr = 0;
  cbMultiByte = 0;
  v2 = -1;
  do
    ++v2;
  while ( aAkiraReadmeTxt[v2] != 0 );
  sub_1400376B0(a1: lpMultiByteStr, a2: aAkiraReadmeTxt);
  v3 = (const CHAR *)lpMultiByteStr;
  if ( cbMultiByte.m128i_i64[1] >= 0x10uLL )
    v3 = lpMultiByteStr[0];
  v4 = MultiByteToWideChar(
         CodePage: 0,
         dwFlags: 0,
         lpMultiByteStr: v3,
         cbMultiByte: cbMultiByte.m128i_i32[0],
         lpWideCharStr: nullptr,
         cchWideChar: 0);
  __wind
  {
    if ( v4 != 0 )
    {
      *(_OWORD *)v22 = 0;
      *(_OWORD *)cchWideChar = 0;
      sub_1400559F0(a1: v22, a2: 0, a3: v4);
      lpWideCharStr = (WCHAR *)v22;
      if ( *(_QWORD *)&cchWideChar[2] >= 8u )
        lpWideCharStr = v22[0];
      v6 = (const CHAR *)lpMultiByteStr;
      if ( cbMultiByte.m128i_i64[1] >= 0x10uLL )
        v6 = lpMultiByteStr[0];
      MultiByteToWideChar(
        CodePage: 0,
        dwFlags: 0,
        lpMultiByteStr: v6,
        cbMultiByte: cbMultiByte.m128i_i32[0],
        lpWideCharStr,
        cchWideChar: cchWideChar[0]);
      v24 = *(_OWORD *)v22;
      si128 = *(__m128i *)cchWideChar;
      *(__m128i *)cchWideChar = _mm_load_si128((const __m128i *)&xmmword_1400E24F0);
      LOWORD(v22[0]) = 0;
    }
    else
    {
      v24 = 0;
      si128 = _mm_load_si128((const __m128i *)&xmmword_1400E24F0);
      LOWORD(v24) = 0;
    }
    __wind
    {
      v7 = *(_QWORD *)(a1 + 16);
      if ( v7 == 0x7FFFFFFFFFFFFFFELL )
        unknown_libname_3();
      sub_140045BD0(a1: v20, a2: v7, Src: "\\", a4: 1);
      __wind
      {
        sub_1400459B0(a1: v26, a2: v8, a3: v20, a4: &v24);
        if ( v21 >= 8 )
        {
          v9 = (void *)v20[0];
          if ( 2 * v21 + 2 >= 0x1000 )
          {
            v9 = *(void **)(v20[0] - 8LL);
            if ( (unsigned __int64)(v20[0] - (_QWORD)v9 - 8LL) > 0x1F )
              invalid_parameter_noinfo_noreturn();
          }
          j_j_free(Block: v9);
        }
        if ( si128.m128i_i64[1] >= 8uLL )
        {
          v10 = (void *)v24;
          if ( (unsigned __int64)(2 * si128.m128i_i64[1] + 2) >= 0x1000 )
          {
            v10 = *(void **)(v24 - 8);
            if ( (unsigned __int64)(v24 - (_QWORD)v10 - 8) > 0x1F )
              invalid_parameter_noinfo_noreturn();
          }
          j_j_free(Block: v10);
        }
        if ( cbMultiByte.m128i_i64[1] >= 0x10uLL )
        {
          v11 = (CHAR *)lpMultiByteStr[0];
          if ( (unsigned __int64)(cbMultiByte.m128i_i64[1] + 1) >= 0x1000 )
          {
            v11 = *((CHAR **)lpMultiByteStr[0] - 1);
            if ( (unsigned __int64)(lpMultiByteStr[0] - (LPCCH)v11 - 8) > 0x1F )
              invalid_parameter_noinfo_noreturn();
          }
          j_j_free(Block: v11);
        }
        cbMultiByte = _mm_load_si128((const __m128i *)&xmmword_1400E2500);
        LOBYTE(lpMultiByteStr[0]) = 0;
        memset(a1: v27, Val: 0, Size: 0x108u);
      }
      __unwind
      {
        unknown_libname_4(a1: v20);
      }
    }
    __unwind
    {
      unknown_libname_4(a1: &v24);
    }
  }
  __unwind
  {
    sub_1400371B0(a1: lpMultiByteStr);
  }
  __eh34_enter_wind_state(-1, 6);
  try
  {
    sub_140043E80(a1: v27, a2: v26);
    __wind
    {
      sub_140040180(a1: v27, a2: aHiFriendsWhate);
      *(_QWORD *)((char *)v27 + *(int *)(v27[0] + 4LL)) = &std::ofstream::`vftable';
      *(_DWORD *)((char *)&v26[3] + *(int *)(v27[0] + 4LL) + 4) = *(_DWORD *)(v27[0] + 4LL) - 168;
      sub_140044BE0(a1: &v27[1]);
    }
    __unwind
    {
      sub_1400430A0(a1: v27);
    }
    __wind
    {
      *(_QWORD *)((char *)v27 + *(int *)(v27[0] + 4LL)) = &std::ostream::`vftable';
      *(_DWORD *)((char *)&v26[3] + *(int *)(v27[0] + 4LL) + 4) = *(_DWORD *)(v27[0] + 4LL) - 16;
      v27[21] = &std::ios_base::`vftable';
      std::ios_base::_Ios_base_dtor(this: (struct std::ios_base *)&v27[21]);
      if ( v26[3] >= 8u )
      {
        v12 = (void *)v26[0];
        if ( (unsigned __int64)(2LL * v26[3] + 2) >= 0x1000 )
        {
          v12 = *(void **)(v26[0] - 8LL);
          if ( (unsigned __int64)(v26[0] - (_QWORD)v12 - 8LL) > 0x1F )
            invalid_parameter_noinfo_noreturn();
        }
        j_j_free(Block: v12);
      }
      result = 1;
    }
    __unwind
    {
      terminate();
    }
  }
  catch ( std::exception *v19 )
  {
    v14 = (*(__int64 (__fastcall **)(std::exception *))(*(_QWORD *)v19 + 8LL))(a1: v19);
    *(_OWORD *)v22 = 0;
    memset(cchWideChar, 0, sizeof(cchWideChar));
    sub_1400376B0(a1: v22, a2: "Error message file : ");
    __wind
    {
      v15 = -1;
      do
        ++v15;
      while ( *(_BYTE *)(v14 + v15) != 0 );
      v16 = sub_140037430(Src: v22);
      v24 = 0;
      si128 = 0u;
      v24 = *(_OWORD *)v16;
      si128 = *(__m128i *)(v16 + 16);
      *(_QWORD *)(v16 + 16) = 0;
      *(_QWORD *)(v16 + 24) = 15;
      *(_BYTE *)v16 = 0;
    }
    __unwind
    {
      sub_1400371B0(a1: v22);
    }
    __wind
    {
      sub_1400371B0(a1: v22);
      if ( qword_140102188 != 0 )
      {
        sub_140040440(a1: qword_140102188, a2: 2, a3: &v24);
        if ( qword_140102188 != 0 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_140102188 + 24LL))(a1: qword_140102188);
      }
    }
    __unwind
    {
      sub_1400371B0(a1: &v24);
    }
    sub_1400371B0(a1: &v24);
    unknown_libname_4(a1: v26);
    if ( __eh34_unwind(6) )
      goto unwind_state_6;
    __eh34_exit_wind_state(6, -1);
    return 0;
  }
  if ( __eh34_unwind(6) )
  {
unwind_state_6:
    unknown_libname_4(a1: v26);
    __eh34_propagate_exception_into_caller(6, -1);
  }
  __eh34_exit_wind_state(6, -1);
  return result;
}