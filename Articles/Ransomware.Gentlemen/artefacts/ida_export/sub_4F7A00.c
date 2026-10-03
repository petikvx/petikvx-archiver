__int64 __fastcall sub_4F7A00()
{
  __int64 v0; // r14
  __int64 v1; // rdx
  __int64 result; // rax
  _QWORD *v3; // rax
  __int64 v4; // rdi
  __int64 v5; // rcx
  __int64 *v6; // r11
  __int64 v7; // rax
  __int64 v8; // rdi
  _QWORD *v9; // rax
  _UNKNOWN **v10; // rcx
  _UNKNOWN **v11; // [rsp+8h] [rbp-50h]
  __int64 v12; // [rsp+20h] [rbp-38h]
  __int64 v13; // [rsp+50h] [rbp-8h] BYREF

  if ( (unsigned __int64)&v13 <= *(_QWORD *)(v0 + 16) )
    sub_470660();
  sub_4B6E40();
  sub_4CBA40();
  result = sub_4B5DC0(a1: qword_6BE818, a2: qword_6BE820, a3: v1, a4: off_6BE810, a5: 420);
  if ( result == 0 )
  {
    v12 = runtime_newobject();
    *(_QWORD *)(v12 + 24) = 10;
    *(_QWORD *)(v12 + 16) = "user32.dll";
    v3 = (_QWORD *)runtime_newobject();
    if ( dword_70D560 != 0 )
    {
      v3 = (_QWORD *)sub_472580(a1: v4);
      v5 = v12;
      *v6 = v12;
    }
    else
    {
      v5 = v12;
    }
    v3[3] = v5;
    v3[2] = 21;
    v3[1] = "SystemParametersInfoW";
    v7 = sub_4841E0();
    if ( v8 != 0 )
      v7 = 0;
    v13 = v7;
    v9 = (_QWORD *)runtime_newobject();
    *v9 = 20;
    v9[1] = 0;
    v9[2] = v13;
    v9[3] = 3;
    sub_481C00(a1: 4);
    if ( v10 != &off_56A900 )
      return (__int64)v10;
    v11 = v10;
    if ( (unsigned __int8)runtime_ifaceeq() == 0 )
      return (__int64)v11;
    return 0;
  }
  return result;
}