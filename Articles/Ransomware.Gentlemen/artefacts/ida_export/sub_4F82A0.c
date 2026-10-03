retval_4F82A0 __gostk sub_4F82A0(__int64 a1, __int64 a2)
{
  __int64 v2; // rcx
  __int64 v3; // rbx
  __int64 v4; // rdi
  __int64 v5; // rsi
  __int64 v6; // r14
  __int128 v7; // xmm15
  __int64 v8; // rbx
  _QWORD v9[4]; // [rsp+88h] [rbp-108h] BYREF
  __int64 v10; // [rsp+188h] [rbp-8h]
  __int64 v11; // [rsp+1A8h] [rbp+18h]
  retval_4F82A0 result; // [rsp+1B0h] [rbp+20h]

  if ( (unsigned __int64)&v9[1] <= *(_QWORD *)(v6 + 16) )
    sub_470660();
  v11 = v3;
  result._r0[0] = v2;
  result._r0[1] = v4;
  result._r0[2] = v5;
  v10 = runtime_makeslice();
  v8 = v10;
  sub_4B5060(a1: v11, a2: 0);
  if ( v8 == 0 )
  {
    v9[1] = *((_QWORD *)&v7 + 1);
    *(_OWORD *)&v9[2] = v7;
    sub_4EFD80();
  }
  return result;
}