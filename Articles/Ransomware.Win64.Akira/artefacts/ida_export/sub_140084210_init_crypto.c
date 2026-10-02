__int64 __fastcall sub_140084210(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  int v6; // r15d
  __int64 result; // rax
  void *v9; // rax
  int v10; // esi
  int v11; // edi
  void *v12; // rax

  v6 = a2;
  if ( a2 == 0 )
    return 4294967294LL;
  if ( a3 == 0 )
    return 0xFFFFFFFFLL;
  if ( *(_QWORD *)(a1 + 32) != 0 || *(_QWORD *)(a1 + 24) != 0 || *(_BYTE *)(a1 + 3) != 0 || *(_BYTE *)(a1 + 2) != 0 )
    return 4294967293LL;
  v9 = operator new(Size: 0x28u);
  *(_QWORD *)(a1 + 24) = v9;
  v10 = (int)v9;
  if ( v9 != nullptr )
  {
    sub_14008A060(a1: v9);
    v11 = 0;
    if ( a4 != 0 )
      goto LABEL_13;
    v12 = operator new(Size: 0x68u);
    *(_QWORD *)(a1 + 32) = v12;
    v11 = (int)v12;
    if ( v12 != nullptr )
    {
      sub_14008A0F0(a1: v12);
LABEL_13:
      if ( (unsigned int)sub_14008A240(a1: v10, a2: v11, a3: 0, a4: v6, a5: a3) != 1 )
        return 4294967293LL;
      *(_BYTE *)(a1 + 2) = 1;
      if ( a4 == 0 )
      {
        *(_BYTE *)(a1 + 3) = 1;
        return 0;
      }
      result = sub_140084360(a1);
      if ( (_DWORD)result == 0 )
        return 0;
      return result;
    }
  }
  return 4294967289LL;
}