__int64 __fastcall sub_4FEA00()
{
  __int64 v0; // r14
  __int128 v1; // xmm15
  _QWORD *v2; // rax
  __int64 v3; // rdi
  __int64 v4; // rcx
  __int64 *v5; // r11
  _QWORD *v6; // rax
  __int64 v7; // rdi
  __int64 v8; // rcx
  __int64 *v9; // r11
  __int64 v10; // rax
  __int64 v11; // rax
  _QWORD *v12; // rsi
  __int64 v13; // rdi
  _DWORD *v14; // rdi
  __int64 v15; // rax
  unsigned __int64 v16; // rcx
  __int64 v17; // rdx
  __int64 v18; // rbx
  int v20; // r8d
  __int64 v21; // rax
  __int64 v22; // rdi
  __int64 v23; // r8
  __int64 v24; // rsi
  __int64 *v25; // r11
  int v26; // [rsp+2h] [rbp-A4h]
  unsigned __int64 v27; // [rsp+Eh] [rbp-98h]
  _QWORD *v28; // [rsp+1Eh] [rbp-88h]
  __int64 v29; // [rsp+2Eh] [rbp-78h]
  __int64 v30; // [rsp+36h] [rbp-70h]
  __int128 v31; // [rsp+3Eh] [rbp-68h] BYREF
  __int64 v32; // [rsp+4Eh] [rbp-58h]
  __int64 v33; // [rsp+56h] [rbp-50h]
  _QWORD v34[3]; // [rsp+5Eh] [rbp-48h] BYREF
  __int64 v35; // [rsp+76h] [rbp-30h]
  __int64 v36; // [rsp+7Eh] [rbp-28h]
  _QWORD *v37; // [rsp+86h] [rbp-20h]
  __int64 v38; // [rsp+8Eh] [rbp-18h]
  _QWORD *v39; // [rsp+96h] [rbp-10h]
  void (**v40)(void); // [rsp+9Eh] [rbp-8h]

  if ( (unsigned __int64)&v31 <= *(_QWORD *)(v0 + 16) )
    sub_470660();
  v31 = *((unsigned __int64 *)&v1 + 1);
  v40 = (void (**)(void))v1;
  v29 = runtime_newobject();
  *(_QWORD *)(v29 + 24) = 12;
  *(_QWORD *)(v29 + 16) = "Netapi32.dll";
  v2 = (_QWORD *)runtime_newobject();
  if ( dword_70D560 != 0 )
  {
    v2 = (_QWORD *)sub_472580(a1: v3);
    v4 = v29;
    *v5 = v29;
  }
  else
  {
    v4 = v29;
  }
  v2[3] = v4;
  v2[2] = 13;
  v2[1] = "NetServerEnum";
  v6 = (_QWORD *)runtime_newobject();
  if ( dword_70D560 != 0 )
  {
    v6 = (_QWORD *)sub_472580(a1: v7);
    v8 = v29;
    *v9 = v29;
  }
  else
  {
    v8 = v29;
  }
  v28 = v6;
  v6[3] = v8;
  v6[2] = 16;
  v6[1] = "NetApiBufferFree";
  v39 = (_QWORD *)runtime_newobject();
  v38 = runtime_newobject();
  v10 = runtime_newobject();
  v37 = v39;
  v36 = v38;
  v35 = v10;
  v11 = runtime_newobject();
  *(_QWORD *)(v11 + 8) = 100;
  *(_QWORD *)(v11 + 16) = v37;
  *(_QWORD *)(v11 + 24) = 0xFFFFFFFFLL;
  *(_QWORD *)(v11 + 32) = v36;
  *(_QWORD *)(v11 + 40) = v35;
  *(_QWORD *)(v11 + 48) = 30;
  *(_OWORD *)(v11 + 56) = v1;
  if ( sub_481C00(a1: 9) != 0 || (v12 = v39, v13 = *v39, *v39 == 0) )
  {
    v31 = v1;
    return 0;
  }
  else
  {
    v34[0] = sub_4FEDC0;
    v34[1] = v28;
    v34[2] = v13;
    v40 = (void (**)(void))v34;
    v14 = (_DWORD *)v38;
    v15 = 0;
    v16 = 0;
    v17 = 0;
    v18 = 0;
    while ( *v14 > (unsigned int)v15 )
    {
      v20 = v15;
      if ( *(_QWORD *)(*v12 + 16 * v15 + 8) != 0 )
      {
        v32 = v17;
        v26 = v15;
        v27 = v16;
        v21 = syscall_UTF16ToString();
        v23 = v18 + 1;
        v16 = v27;
        if ( v27 < v18 + 1 )
        {
          v33 = v21;
          v17 = runtime_growslice(a1: 1, a2: &unk_50FEE0);
          v23 = v18 + 1;
          v21 = v33;
        }
        else
        {
          v17 = v32;
        }
        v24 = 16 * (v23 - 1);
        *(_QWORD *)(v17 + v24 + 8) = 256;
        if ( dword_70D560 != 0 )
        {
          v21 = sub_4725A0(a1: v22);
          *v25 = v21;
          v25[1] = *(_QWORD *)(v17 + v24);
        }
        *(_QWORD *)(v17 + v24) = v21;
        v12 = v39;
        v14 = (_DWORD *)v38;
        v18 = v23;
        v20 = v26;
      }
      v15 = (unsigned int)(v20 + 1);
    }
    v30 = v17;
    *(_QWORD *)&v31 = v18;
    *((_QWORD *)&v31 + 1) = v16;
    (*v40)();
    return v30;
  }
}