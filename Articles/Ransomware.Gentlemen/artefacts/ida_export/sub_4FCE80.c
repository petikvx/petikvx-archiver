__int64 __fastcall sub_4FCE80()
{
  __int64 v0; // r14
  __int64 v1; // rax
  unsigned __int64 v2; // rcx
  __int64 v3; // rdx
  __int64 v4; // rbx
  unsigned int v5; // edi
  __int64 v6; // r8
  __int64 v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rbx
  __int64 v11; // rdx
  __int64 v12; // rdx
  __int64 v13; // rdi
  __int64 v14; // rdx
  __int64 v15; // rdx
  __int64 v16; // rsi
  __int64 v17; // rdx
  __int64 v18; // rsi
  __int64 v19; // rbx
  __int64 v20; // rax
  __int64 v21; // rdi
  __int64 *v22; // r11
  __int64 v24; // [rsp+24h] [rbp-80h]
  unsigned __int64 v25; // [rsp+2Ch] [rbp-78h]
  __int64 v26; // [rsp+34h] [rbp-70h]
  __int64 v27; // [rsp+3Ch] [rbp-68h] BYREF
  __int64 v28; // [rsp+44h] [rbp-60h]
  __int64 v29; // [rsp+4Ch] [rbp-58h]
  __int64 v30; // [rsp+54h] [rbp-50h]
  __int64 v31; // [rsp+5Ch] [rbp-48h]
  _QWORD v32[8]; // [rsp+64h] [rbp-40h] BYREF

  if ( (unsigned __int64)&v27 <= *(_QWORD *)(v0 + 16) )
    sub_470660();
  v1 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  while ( v1 < 26 )
  {
    v25 = v2;
    v24 = v4;
    v29 = v3;
    v5 = (unsigned __int8)aAbcdefghijklmn[v1];
    if ( v5 >= 0x80 )
    {
      v5 = runtime_decoderune();
      v6 = 26;
    }
    else
    {
      v6 = v1 + 1;
    }
    v28 = v6;
    v7 = (int)v5;
    v8 = runtime_intstring();
    v9 = v7;
    v10 = v8;
    v30 = runtime_concatstring2(a1: ":", a2: 1, a3: v11, a4: v9);
    v26 = v10;
    v32[1] = 2;
    v32[0] = "/C";
    v32[3] = 3;
    v32[2] = "net";
    v32[5] = 3;
    v32[4] = "use";
    v32[7] = v10;
    v32[6] = v30;
    sub_4CDE40(a1: 4, a2: 4, a3: v12, a4: v32);
    sub_4D0E00();
    if ( v13 != 0 )
    {
      v14 = 0;
    }
    else
    {
      runtime_slicebytetostring();
      LOBYTE(v14) = sub_408860(a1: 2, a2: v16, a3: v15, a4: "\\\\") >= 0;
    }
    if ( (_BYTE)v14 != 0 )
    {
      v19 = v30;
      v20 = runtime_concatstring2(a1: "\\", a2: 1, a3: v14, a4: v26);
      v17 = v24 + 1;
      v2 = v25;
      if ( v25 < v24 + 1 )
      {
        v31 = v20;
        v27 = v19;
        v18 = runtime_growslice(a1: 1, a2: &unk_50FEE0);
        v17 = v24 + 1;
        v20 = v31;
        v19 = v27;
      }
      else
      {
        v18 = v29;
      }
      v21 = 16 * (v17 - 1);
      *(_QWORD *)(v18 + v21 + 8) = v19;
      if ( dword_70D560 != 0 )
      {
        v20 = sub_4725A0(a1: v21);
        *v22 = v20;
        v22[1] = *(_QWORD *)(v18 + v21);
      }
      *(_QWORD *)(v18 + v21) = v20;
    }
    else
    {
      v17 = v24;
      v2 = v25;
      v18 = v29;
    }
    v1 = v28;
    v4 = v17;
    v3 = v18;
  }
  return v3;
}