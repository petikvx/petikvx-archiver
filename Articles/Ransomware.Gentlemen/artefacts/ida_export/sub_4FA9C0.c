__int64 __fastcall sub_4FA9C0()
{
  __int64 v0; // rbx
  __int64 v1; // r14
  __int64 result; // rax
  __int64 v3; // rdx
  __int64 v4; // rcx
  __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rcx
  _BYTE *v9; // rax
  __int64 v10; // rdi
  __int64 v11; // rdx
  _QWORD *v12; // r11
  __int64 v13; // [rsp+18h] [rbp-40h]
  __int64 v14; // [rsp+20h] [rbp-38h]
  __int128 v15; // [rsp+28h] [rbp-30h]
  _QWORD v16[4]; // [rsp+38h] [rbp-20h] BYREF

  if ( (unsigned __int64)v16 <= *(_QWORD *)(v1 + 16) )
    sub_470660();
  result = sub_4B4D40();
  if ( v4 == 0 )
  {
    *((_QWORD *)&v15 + 1) = result;
    v14 = runtime_concatstring4(a1: result, a2: v0, a3: v3, a4: 49, a5: "\" >nul 2>&1\r\n", a6: 13);
    *(_QWORD *)&v15 = runtime_concatstring2(a1: ".bat", a2: 4, a3: v5, a4: v0);
    v6 = runtime_stringtoslicebyte();
    sub_4B5DC0(a1: v14, a2: v8, a3: v7, a4: v6, a5: 384);
    v16[1] = 2;
    v16[0] = "/C";
    *(_OWORD *)&v16[2] = v15;
    v13 = sub_4CDE40(a1: 2, a2: 2, a3: v15, a4: v16);
    v9 = (_BYTE *)runtime_newobject();
    *v9 = 1;
    v11 = v13;
    if ( dword_70D560 != 0 )
    {
      v9 = (_BYTE *)sub_4725A0(a1: v10);
      *v12 = v9;
      v12[1] = *(_QWORD *)(v11 + 152);
    }
    *(_QWORD *)(v11 + 152) = v9;
    return sub_4CF280();
  }
  return result;
}