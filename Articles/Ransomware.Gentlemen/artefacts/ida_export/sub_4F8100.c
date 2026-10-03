bool __fastcall sub_4F8100()
{
  __int64 v0; // r14
  __int64 v1; // rax
  __int64 v2; // rcx
  __int64 v4; // rax
  __int64 v5; // rdx
  __int64 v6; // rsi
  __int64 v7; // [rsp+20h] [rbp-20h]
  __int64 v8; // [rsp+28h] [rbp-18h]
  _UNKNOWN *retaddr; // [rsp+48h] [rbp+8h] BYREF

  if ( (unsigned __int64)&retaddr <= *(_QWORD *)(v0 + 16) )
    sub_470660();
  v1 = sub_4B7720();
  if ( v2 != 0 )
    return false;
  v8 = v1;
  if ( (*(__int64 (**)(void))(v1 + 56))() < 10 )
    return false;
  if ( (*(__int64 (**)(void))(v8 + 56))() < 32 )
    v4 = (*(__int64 (**)(void))(v8 + 56))();
  else
    v4 = 32;
  v7 = v4;
  sub_4B5800();
  runtime_makeslice();
  sub_4B4FA0(a1: v7);
  runtime_slicebytetostring();
  return sub_408860(a1: 9, a2: v6, a3: v5, a4: "GENTLEMEN") >= 0;
}