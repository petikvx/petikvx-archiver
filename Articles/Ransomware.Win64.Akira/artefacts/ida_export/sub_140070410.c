char sub_140070410()
{
  _DWORD *v0; // rdi
  volatile signed __int32 *v1; // rbx
  char result; // al
  __int64 v3; // rax
  __int64 v4; // rax
  __int64 v5; // rcx
  const std::exception *v6; // [rsp+30h] [rbp-58h] BYREF
  _BYTE v7[32]; // [rsp+38h] [rbp-50h] BYREF
  _BYTE v8[40]; // [rsp+58h] [rbp-30h] BYREF

  try
  {
    v0 = operator new(Size: 0x38u);
    v0[2] = 1;
    v0[3] = 1;
    *(_QWORD *)v0 = &std::_Ref_count_obj2<std::basic_regex<char,std::regex_traits<char>>>::`vftable';
    __wind
    {
      sub_140072E70();
      qword_1401021A8 = (__int64)(v0 + 4);
      v1 = (volatile signed __int32 *)qword_1401021B0;
      qword_1401021B0 = (__int64)v0;
      if ( v1 != nullptr && _InterlockedExchangeAdd(v1 + 2, 0xFFFFFFFF) == 1 )
      {
        (**(void (__fastcall ***)(volatile signed __int32 *))v1)(a1: v1);
        if ( _InterlockedExchangeAdd(v1 + 3, 0xFFFFFFFF) == 1 )
          (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v1 + 8LL))(a1: v1);
      }
      result = 1;
    }
    __unwind
    {
      j_j_free(Block: v0);
    }
  }
  catch ( const std::exception *v6 )
  {
    (*(void (__fastcall **)(const std::exception *))(*(_QWORD *)v6 + 8LL))(a1: v6);
    v3 = sub_14003E680(a1: v8);
    __wind
    {
      v4 = sub_14003E3F0(a1: v7, a2: "init filtering error:", a3: v3);
      __wind
      {
        sub_140039EC0(a1: v5, a2: v4);
      }
      __unwind
      {
        sub_1400371B0(a1: v7);
      }
      sub_1400371B0(a1: v7);
      sub_1400371B0(a1: v8);
    }
    __unwind
    {
      sub_1400371B0(a1: v8);
    }
    return 0;
  }
  return result;
}