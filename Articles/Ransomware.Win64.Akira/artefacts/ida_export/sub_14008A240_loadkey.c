__int64 __fastcall sub_14008A240(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5)
{
  _BYTE v9[24]; // [rsp+20h] [rbp-38h] BYREF
  int v10; // [rsp+38h] [rbp-20h]

  if ( (unsigned int)sub_14008B990(a1: v9, a2: a4, a3: a5) != 2 )
    return 0;
  if ( a2 != 0 )
    return sub_14008A360(a1, a2, a3, a4: v9);
  return v10 == 4112
      && (unsigned int)sub_14008B820(a1: v9) == 1
      && (unsigned int)sub_14008B860(a1: v9, a2: a1 + 8, a3) != 0
      && (int)sub_140089B20(a1: a1 + 8) > 0
      && (unsigned int)sub_14008B9B0(a1: v9) == 1
      && v10 == 2
      && (unsigned int)sub_14008B860(a1: v9, a2: a1 + 24, a3) != 0
      && (int)sub_140089B20(a1: a1 + 24) > 0
      && (unsigned int)sub_14008B9B0(a1: v9) == 3
      && (unsigned int)sub_14008A090(a1) != 0;
}