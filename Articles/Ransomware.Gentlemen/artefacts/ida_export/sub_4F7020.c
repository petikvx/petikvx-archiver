__int64 __fastcall sub_4F7020(_QWORD *a1, __int64 a2)
{
  __int64 v2; // rax
  __int64 v3; // r10
  __int64 v4; // r11
  __int64 v5; // r14
  __int128 v6; // xmm15
  __int64 v7; // rdx
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 result; // rax
  _QWORD v11[2]; // [rsp+40h] [rbp-150h] BYREF
  __int128 v12; // [rsp+50h] [rbp-140h]
  _QWORD v13[5]; // [rsp+60h] [rbp-130h] BYREF
  _QWORD v14[3]; // [rsp+88h] [rbp-108h] BYREF
  __int128 v15; // [rsp+A0h] [rbp-F0h]
  _QWORD v16[3]; // [rsp+B0h] [rbp-E0h] BYREF
  __int128 v17; // [rsp+C8h] [rbp-C8h]
  __int64 v18; // [rsp+D8h] [rbp-B8h]
  __int64 v19; // [rsp+E0h] [rbp-B0h]
  _QWORD v20[3]; // [rsp+E8h] [rbp-A8h] BYREF
  __int128 v21; // [rsp+100h] [rbp-90h]
  _QWORD v22[3]; // [rsp+110h] [rbp-80h] BYREF
  __int128 v23; // [rsp+128h] [rbp-68h]
  _QWORD v24[3]; // [rsp+138h] [rbp-58h] BYREF
  __int128 v25; // [rsp+150h] [rbp-40h]
  _QWORD v26[3]; // [rsp+160h] [rbp-30h] BYREF
  __int128 v27; // [rsp+178h] [rbp-18h]
  __int64 v28; // [rsp+188h] [rbp-8h]
  __int64 v29; // [rsp+1A0h] [rbp+10h]
  __int64 v30; // [rsp+1D8h] [rbp+48h]
  __int64 v31; // [rsp+1E0h] [rbp+50h]

  if ( (unsigned __int64)&v13[4] <= *(_QWORD *)(v5 + 16) )
    sub_470660();
  v29 = v2;
  *(_OWORD *)v11 = v6;
  v12 = v6;
  if ( a1 != v11 )
  {
    v31 = v4;
    v30 = v3;
    sub_4732E0();
    v3 = v30;
    v4 = v31;
  }
  LOBYTE(v11[0]) &= 0xF8u;
  v7 = HIBYTE(v12) & 0x7F | 0x40u;
  HIBYTE(v12) = HIBYTE(v12) & 0x3F | 0x40;
  v16[0] = v6;
  *(_OWORD *)&v16[1] = v6;
  v17 = v6;
  v22[0] = v6;
  *(_OWORD *)&v22[1] = v6;
  v23 = v6;
  v13[0] = v6;
  *(_OWORD *)&v13[1] = v6;
  *(_OWORD *)&v13[3] = v6;
  v26[0] = v6;
  *(_OWORD *)&v26[1] = v6;
  v27 = v6;
  v14[0] = v6;
  *(_OWORD *)&v14[1] = v6;
  v15 = v6;
  v24[0] = v6;
  *(_OWORD *)&v24[1] = v6;
  v25 = v6;
  v20[0] = v6;
  *(_OWORD *)&v20[1] = v6;
  v21 = v6;
  sub_4F6300(a1: v4, a2, a3: v7, a4: v3);
  qmemcpy(v22, off_6BE188, sizeof(v22));
  v23 = *(_OWORD *)((char *)off_6BE188 + 24);
  qmemcpy(v26, v16, sizeof(v26));
  v27 = v17;
  qmemcpy(v14, off_6BE188, sizeof(v14));
  v15 = *(_OWORD *)((char *)off_6BE188 + 24);
  v8 = 254;
  v9 = 0;
  while ( v8 >= 0 )
  {
    if ( (unsigned __int64)(v8 >> 3) >= 0x20 )
      sub_472940();
    v18 = v8;
    v28 = (*((_BYTE *)v11 + (v8 >> 3)) >> (v8 & 7)) & 1;
    v19 = v28 ^ v9;
    crypto_internal_edwards25519_field__ptr_Element_Swap();
    crypto_internal_edwards25519_field__ptr_Element_Swap();
    sub_4F59E0();
    sub_4F59E0();
    crypto_internal_edwards25519_field__ptr_Element_Add();
    crypto_internal_edwards25519_field__ptr_Element_Add();
    --v18;
    sub_4F6740(a1: (__int64)v14, a2: (__int64)v24, a3: (__int64)v22);
    sub_4F6740(a1: (__int64)v13, a2: (__int64)v13, a3: (__int64)v20);
    sub_4F6980(a1: (__int64)v24, a2: (__int64)v20);
    sub_4F6980(a1: (__int64)v20, a2: (__int64)v22);
    crypto_internal_edwards25519_field__ptr_Element_Add();
    sub_4F59E0();
    sub_4F6740(a1: (__int64)v22, a2: (__int64)v20, a3: (__int64)v24);
    sub_4F59E0();
    sub_4F6980(a1: (__int64)v13, a2: (__int64)v13);
    sub_4F65C0();
    sub_4F6980(a1: (__int64)v26, a2: (__int64)v26);
    crypto_internal_edwards25519_field__ptr_Element_Add();
    sub_4F6740(a1: (__int64)v14, a2: (__int64)v16, a3: (__int64)v13);
    sub_4F6740(a1: (__int64)v13, a2: (__int64)v20, a3: (__int64)v24);
    v8 = v18;
    v9 = v28;
  }
  v19 = v9;
  crypto_internal_edwards25519_field__ptr_Element_Swap();
  crypto_internal_edwards25519_field__ptr_Element_Swap();
  sub_4F5A80();
  sub_4F6740(a1: (__int64)v22, a2: (__int64)v22, a3: (__int64)v13);
  result = sub_4F63E0();
  if ( result != v29 )
    return sub_4732E0();
  return result;
}