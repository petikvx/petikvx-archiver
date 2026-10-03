retval_4F8760 sub_4F8760()
{
  __int64 v0; // rax
  __int64 v1; // rcx
  __int64 v2; // rbx
  __int64 v3; // rdi
  __int64 v4; // rsi
  __int64 v5; // r14
  __int128 v6; // xmm15
  _QWORD v7[4]; // [rsp+88h] [rbp-188h] BYREF
  retval_4F8760 result; // [rsp+220h] [rbp+10h]

  if ( (unsigned __int64)&v7[1] <= *(_QWORD *)(v5 + 16) )
    sub_470660();
  result._r0[0] = v0;
  result._r0[1] = v2;
  result._r0[3] = v3;
  result._r0[2] = v1;
  result._r0[4] = v4;
  v7[1] = *((_QWORD *)&v6 + 1);
  *(_OWORD *)&v7[2] = v6;
  sub_4EFD80();
  return result;
}