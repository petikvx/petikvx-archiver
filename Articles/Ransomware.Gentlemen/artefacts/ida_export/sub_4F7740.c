__int64 __fastcall sub_4F7740(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rax
  __int64 v6; // rbx
  __int64 v7; // r14
  void *v8; // r9
  __int64 v9; // r10
  __int64 v10; // r11
  __int64 v12; // rcx
  __int64 v13; // rsi
  __int64 v14; // r8
  __int64 v15; // r9
  _QWORD *v16; // rax
  __int64 v17; // rdi
  __int64 v18; // rsi
  void *v19; // rdx
  __int64 v20; // r8
  _QWORD *v21; // r11
  _UNKNOWN **v22; // rcx
  _QWORD *v23; // rax
  _QWORD *v24; // rax
  __int64 v25; // rax
  __int64 v26; // rdi
  __int64 v27; // rdx
  __int64 v29; // [rsp+0h] [rbp-28h]
  __int64 v30; // [rsp+0h] [rbp-28h]
  __int64 v31; // [rsp+8h] [rbp-20h]
  __int64 v32; // [rsp+8h] [rbp-20h]
  __int64 v33; // [rsp+10h] [rbp-18h]
  __int64 v34; // [rsp+10h] [rbp-18h]
  void *v35; // [rsp+20h] [rbp-8h]
  _UNKNOWN *retaddr; // [rsp+30h] [rbp+8h] BYREF
  __int64 v37; // [rsp+38h] [rbp+10h]
  __int64 v38; // [rsp+40h] [rbp+18h]

  if ( (unsigned __int64)&retaddr <= *(_QWORD *)(v7 + 16) )
    sub_470660();
  v37 = v5;
  v38 = v6;
  v35 = off_6BE180;
  if ( byte_70D2C4 != 0 )
  {
    v24 = (_QWORD *)runtime_newobject();
    v24[1] = 63;
    *v24 = "crypto/ecdh: use of X25519 is not allowed in FIPS 140-only mode";
    v19 = v35;
    v22 = &off_56A940;
  }
  else if ( qword_658330 == a5 )
  {
    if ( a2 != 0 )
    {
      if ( a5 != 0 )
      {
        v8 = (void *)runtime_growslice(a1: a5, a2: &unk_50FF60);
        v9 = v12;
        v10 = a5;
      }
      else
      {
        v8 = &unk_70D2A0;
        v9 = 0;
        v10 = 0;
      }
      v31 = v9;
      v29 = v10;
      v33 = (__int64)v8;
      sub_4732E0();
      v13 = v33;
      v14 = v31;
      v15 = v29;
    }
    else
    {
      v13 = 0;
      v14 = 0;
      v15 = 0;
    }
    v32 = v14;
    v30 = v15;
    v34 = v13;
    v16 = (_QWORD *)runtime_newobject();
    *v16 = &off_56AFB8;
    if ( dword_70D560 != 0 )
    {
      v16 = (_QWORD *)sub_4725A0(a1: v17);
      v19 = v35;
      *v21 = v35;
      v20 = v34;
      v21[1] = v34;
    }
    else
    {
      v19 = v35;
      v20 = v34;
    }
    v16[1] = v19;
    v16[3] = v30;
    v16[4] = v32;
    v16[2] = v20;
    v22 = nullptr;
  }
  else
  {
    v23 = (_QWORD *)runtime_newobject();
    v23[1] = 31;
    *v23 = "crypto/ecdh: invalid public key";
    v19 = v35;
    v22 = &off_56A940;
  }
  if ( v22 != nullptr )
    return 0;
  sub_4F6C00(a1, a2: v18, a3: v19, a4);
  if ( v38 != 0 )
    return 0;
  v25 = sub_4F6B20();
  if ( v26 != 0 )
    return 0;
  v27 = v37;
  if ( v25 != v37 )
  {
    sub_4732E0();
    return v37;
  }
  return v27;
}