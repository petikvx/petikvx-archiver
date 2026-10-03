__int64 __fastcall sub_4FE0A0()
{
  __int64 v0; // rax
  __int64 *v1; // rbx
  __int64 v2; // r14
  __int64 (**v3)(void); // xmm15_8
  _QWORD *v4; // rax
  __int64 v5; // rdi
  __int64 v6; // rcx
  __int64 *v7; // r11
  _QWORD *v8; // rax
  __int64 v9; // rdi
  __int64 v10; // rcx
  __int64 *v11; // r11
  _QWORD *v12; // rax
  __int64 v13; // rdi
  __int64 v14; // rcx
  __int64 *v15; // r11
  _QWORD *v16; // rax
  __int64 result; // rax
  __int64 v18; // rdx
  _DWORD *v19; // rax
  _QWORD *v20; // rax
  __int64 v21; // rbx
  _DWORD *v22; // rcx
  __int64 v23; // rdx
  __int64 i; // rax
  _WORD *v25; // rax
  __int64 v26; // rdi
  __int64 *v27; // rdx
  unsigned __int64 v28; // r8
  __int64 v29; // r9
  __int64 v30; // rbx
  __int64 v31; // rax
  __int64 v32; // rcx
  __int64 *v33; // r11
  __int64 v34; // rcx
  _QWORD *v35; // r11
  int v36; // [rsp+2h] [rbp-94h]
  __int64 v37; // [rsp+6h] [rbp-90h]
  _QWORD *v38; // [rsp+Eh] [rbp-88h]
  __int64 v39; // [rsp+26h] [rbp-70h]
  _WORD *v40; // [rsp+2Eh] [rbp-68h]
  __int64 v41; // [rsp+36h] [rbp-60h]
  _QWORD v42[3]; // [rsp+3Eh] [rbp-58h] BYREF
  _DWORD *v43; // [rsp+56h] [rbp-40h]
  __int64 v44; // [rsp+5Eh] [rbp-38h]
  _DWORD *v45; // [rsp+66h] [rbp-30h]
  _QWORD *v46; // [rsp+6Eh] [rbp-28h]
  __int64 v47; // [rsp+76h] [rbp-20h]
  _DWORD *v48; // [rsp+7Eh] [rbp-18h]
  _QWORD *v49; // [rsp+86h] [rbp-10h]
  __int64 (**v50)(void); // [rsp+8Eh] [rbp-8h]
  __int64 v51; // [rsp+A6h] [rbp+10h]
  __int64 *v52; // [rsp+AEh] [rbp+18h]

  if ( (unsigned __int64)v42 <= *(_QWORD *)(v2 + 16) )
    sub_470660();
  v50 = v3;
  v51 = v0;
  v52 = v1;
  v39 = runtime_newobject();
  *(_QWORD *)(v39 + 24) = 7;
  *(_QWORD *)(v39 + 16) = "mpr.dll";
  v4 = (_QWORD *)runtime_newobject();
  if ( dword_70D560 != 0 )
  {
    v4 = (_QWORD *)sub_472580(a1: v5);
    v6 = v39;
    *v7 = v39;
  }
  else
  {
    v6 = v39;
  }
  v4[3] = v6;
  v4[2] = 13;
  v4[1] = "WNetOpenEnumW";
  v8 = (_QWORD *)runtime_newobject();
  if ( dword_70D560 != 0 )
  {
    v8 = (_QWORD *)sub_472580(a1: v9);
    v10 = v39;
    *v11 = v39;
  }
  else
  {
    v10 = v39;
  }
  v8[3] = v10;
  v8[2] = 17;
  v8[1] = "WNetEnumResourceW";
  v12 = (_QWORD *)runtime_newobject();
  if ( dword_70D560 != 0 )
  {
    v12 = (_QWORD *)sub_472580(a1: v13);
    v14 = v39;
    *v15 = v39;
  }
  else
  {
    v14 = v39;
  }
  v38 = v12;
  v12[3] = v14;
  v12[2] = 13;
  v12[1] = "WNetCloseEnum";
  v49 = (_QWORD *)runtime_newobject();
  v47 = v51;
  v46 = v49;
  v16 = (_QWORD *)runtime_newobject();
  *v16 = 2;
  v16[1] = 1;
  v16[2] = 0;
  v16[3] = v47;
  v16[4] = v46;
  result = sub_481C00(a1: 5);
  if ( result == 0 )
  {
    v18 = *v49;
    v42[0] = sub_4FE520;
    v42[1] = v38;
    v42[2] = v18;
    v50 = (__int64 (**)(void))v42;
    v41 = runtime_makeslice();
    while ( 1 )
    {
      v48 = (_DWORD *)runtime_newobject();
      *v48 = -1;
      v19 = (_DWORD *)runtime_newobject();
      *v19 = 0x4000;
      v45 = v48;
      v44 = v41;
      v43 = v19;
      v20 = (_QWORD *)runtime_newobject();
      *v20 = *v49;
      v20[1] = v45;
      v20[2] = v44;
      v20[3] = v43;
      v21 = (__int64)v20;
      if ( sub_481C00(a1: 4) != 0 )
        break;
      v22 = v48;
      if ( *v48 == 0 )
        break;
      v23 = v41;
      for ( i = 0; *v22 > (unsigned int)i; i = (unsigned int)(i + 1) )
      {
        v36 = i;
        if ( (*(_DWORD *)(v23 + 48 * i + 12) & 2) != 0 )
        {
          v21 = (__int64)v52;
          sub_4FE0A0();
          LODWORD(i) = v36;
          v22 = v48;
          v23 = v41;
        }
        else if ( *(_QWORD *)(v23 + 48 * i + 24) != 0 )
        {
          v25 = (_WORD *)sub_4FDF80();
          if ( v21 > 2 && *v25 == 23644 )
          {
            v27 = v52;
            v28 = v52[1] + 1;
            v29 = *v52;
            if ( v52[2] < v28 )
            {
              v40 = v25;
              v37 = v21;
              v30 = v52[1] + 1;
              v31 = runtime_growslice(a1: 1, a2: &unk_50FEE0);
              v27 = v52;
              v52[2] = v32;
              if ( dword_70D560 != 0 )
              {
                v31 = sub_4725A0(a1: v26);
                *v33 = v31;
                v33[1] = *v27;
              }
              *v27 = v31;
              v29 = v31;
              v28 = v30;
              v25 = v40;
              v21 = v37;
            }
            v27[1] = v28;
            v34 = 16 * (v28 - 1);
            *(_QWORD *)(v29 + v34 + 8) = v21;
            if ( dword_70D560 != 0 )
            {
              v25 = (_WORD *)sub_4725A0(a1: v26);
              *v35 = v25;
              v35[1] = *(_QWORD *)(v29 + v34);
            }
            *(_QWORD *)(v29 + v34) = v25;
          }
          LODWORD(i) = v36;
          v22 = v48;
          v23 = v41;
        }
      }
    }
    return (*v50)();
  }
  return result;
}