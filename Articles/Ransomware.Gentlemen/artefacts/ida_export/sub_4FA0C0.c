void __fastcall sub_4FA0C0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned __int8 a5)
{
  __int64 v5; // rbx
  __int64 v6; // r14
  __int128 v7; // xmm15
  __int64 v8; // rdx
  char v9; // cl
  char v10; // al
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rdx
  __int64 v14; // rsi
  __int64 v15; // [rsp-3Eh] [rbp-A0h]
  __int64 v16; // [rsp-36h] [rbp-98h]
  __int64 v17; // [rsp+22h] [rbp-40h]
  __int64 v18; // [rsp+2Ah] [rbp-38h]
  __int128 v19; // [rsp+3Ah] [rbp-28h] BYREF
  _QWORD v20[2]; // [rsp+4Ah] [rbp-18h] BYREF
  void (**v21)(void); // [rsp+5Ah] [rbp-8h]

  if ( (unsigned __int64)&v19 + 8 <= *(_QWORD *)(v6 + 16) )
    sub_470660();
  v20[0] = unknown_libname_94;
  v20[1] = v5 + 32;
  v21 = (void (**)(void))v20;
  v19 = v7;
  while ( (unsigned __int8)runtime_chanrecv2() != 0 )
  {
    v17 = *((_QWORD *)&v19 + 1);
    v18 = v19;
    v19 = v7;
    if ( a5 != 0 )
    {
      v9 = 0;
    }
    else
    {
      runtime_concatstring2(a1: off_6BE190, a2: qword_6BE198, a3: v8, a4: 1);
      if ( (__int64)"." > v17 )
      {
        v10 = 0;
      }
      else
      {
        if ( v17 < (unsigned __int64)"." )
          sub_472A00();
        v10 = sub_4033C0();
      }
      v9 = v10;
    }
    if ( v9 == 0 )
    {
      sub_4F9020(a1: v15, a2: v16);
      if ( v11 == 0 && a5 == 0 )
      {
        v12 = runtime_concatstring3(a1: ".", a2: 1, a3: a5, a4: v17, a5: off_6BE190);
        sub_4B6BA0(a1: v18, a2: v14, a3: v13, a4: v12);
      }
    }
  }
  (*v21)();
}