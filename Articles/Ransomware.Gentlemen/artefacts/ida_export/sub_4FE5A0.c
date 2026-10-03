__int64 __fastcall sub_4FE5A0()
{
  __int64 v0; // r14
  __int128 v1; // xmm15
  __int64 v2; // rdx
  __int64 v3; // rax
  __int64 v4; // rdi
  __int64 v5; // rbx
  __int64 v6; // rdx
  __int64 v7; // rax
  __int64 v8; // rbx
  __int64 v9; // rax
  __int64 v10; // rdx
  __int64 v11; // rsi
  __int64 v12; // rbx
  __int64 v13; // rax
  __int64 i; // rax
  unsigned int v15; // esi
  __int64 v16; // rcx
  __int64 v17; // rbx
  __int64 v18; // rax
  __int64 v19; // rcx
  __int64 v20; // rbx
  __int64 v21; // rdx
  __int64 v22; // rdx
  __int64 v23; // rsi
  __int64 v24; // rcx
  __int64 v25; // rdi
  unsigned __int64 v26; // rax
  __int64 v27; // rcx
  unsigned __int64 v28; // rdx
  unsigned __int64 v29; // rbx
  __int64 v30; // rdx
  __int64 v31; // r8
  __int64 v32; // rax
  unsigned __int64 v33; // rcx
  unsigned __int64 v34; // rsi
  __int64 v35; // rsi
  _QWORD *v36; // r11
  __int64 *v38; // [rsp+0h] [rbp-250h]
  __int64 v39; // [rsp+10h] [rbp-240h] BYREF
  unsigned __int64 v40; // [rsp+58h] [rbp-1F8h]
  unsigned __int64 v41; // [rsp+60h] [rbp-1F0h]
  __int64 v42; // [rsp+68h] [rbp-1E8h]
  __int64 v43; // [rsp+70h] [rbp-1E0h]
  __int64 v44; // [rsp+78h] [rbp-1D8h]
  unsigned __int64 v45; // [rsp+80h] [rbp-1D0h]
  unsigned __int64 v46; // [rsp+88h] [rbp-1C8h]
  __int64 v47; // [rsp+90h] [rbp-1C0h] BYREF
  __int64 v48; // [rsp+98h] [rbp-1B8h]
  __int64 v49; // [rsp+A0h] [rbp-1B0h]
  __int64 v50; // [rsp+A8h] [rbp-1A8h]
  __int64 v51; // [rsp+B0h] [rbp-1A0h]
  __int64 v52; // [rsp+B8h] [rbp-198h]
  __int64 v53; // [rsp+C0h] [rbp-190h]
  _QWORD v54[24]; // [rsp+C8h] [rbp-188h] BYREF
  __int128 v55; // [rsp+190h] [rbp-C0h]
  __int128 v56; // [rsp+1A0h] [rbp-B0h]
  __int128 v57; // [rsp+1B0h] [rbp-A0h]
  __int64 *v58; // [rsp+1C0h] [rbp-90h]
  _QWORD v59[6]; // [rsp+220h] [rbp-30h] BYREF
  __int64 vars0; // [rsp+250h] [rbp+0h] BYREF

  if ( (unsigned __int64)&v47 <= *(_QWORD *)(v0 + 16) )
    sub_470660();
  v55 = v1;
  v56 = v1;
  v57 = v1;
  *(_OWORD *)v54 = v1;
  v38 = &vars0;
  sub_472BEB(a1: &v54[1]);
  v54[0] = 0x8080808080808080LL;
  *(_QWORD *)&v56 = v54;
  *((_QWORD *)&v55 + 1) = sub_46BBE0();
  v59[1] = 10;
  v59[0] = "-NoProfile";
  v59[3] = 8;
  v59[2] = "-Command";
  v59[5] = 236;
  v59[4] = "$volumes=@();$volumes+=Get-WmiObject -Class Win32_Volume|Where-Object{$_.Name -like '*:\\*'}|Select-Object -E"
           "xpandProperty Name;try{$volumes+=Get-ClusterSharedVolume|ForEach-Object{$_.SharedVolumeInfo.FriendlyVolumeNam"
           "e}}catch{};$volumes";
  sub_4CDE40(a1: 3, a2: 3, a3: v2, a4: v59);
  v3 = sub_4D0BE0();
  if ( v4 == 0 )
  {
    v5 = v3;
    runtime_slicebytetostring();
    v7 = sub_4C8180(a1: 1, a2: 0, a3: v6, a4: "\n", a5: -1);
    while ( v5 > 0 )
    {
      v47 = v5;
      v53 = v7;
      v8 = *(_QWORD *)(v7 + 8);
      v9 = strings_TrimSpace();
      if ( v8 != 0 )
      {
        v44 = v8;
        v51 = v9;
        if ( (unsigned __int8)sub_4033C0() != 0 )
        {
          v12 = v44;
          v13 = v51;
        }
        else
        {
          v12 = v51;
          v13 = runtime_concatstring2(a1: "\\", a2: 1, a3: v10, a4: v44);
        }
        sub_407920(a1: v12, a2: v11, a3: v10, a4: v13);
      }
      v7 = v53 + 16;
      v5 = v47 - 1;
    }
  }
  for ( i = 0; i < 26; i = v47 )
  {
    v15 = (unsigned __int8)aAbcdefghijklmn[i];
    if ( v15 >= 0x80 )
    {
      v15 = runtime_decoderune();
      v16 = 26;
    }
    else
    {
      v16 = i + 1;
    }
    v47 = v16;
    v17 = (int)v15;
    v18 = runtime_intstring();
    v19 = v17;
    v20 = v18;
    v50 = runtime_concatstring2(a1: ":\\", a2: 2, a3: v21, a4: v19);
    v43 = v20;
    sub_4B7660();
    if ( v24 == 0 )
      sub_407920(a1: v43, a2: v23, a3: v22, a4: v50);
  }
  v46 = v55;
  v53 = runtime_makeslice();
  v38 = &vars0;
  sub_472C0B(a1: &v39 + 50);
  sub_414B00();
  v26 = v46;
  v27 = v53;
  v28 = 0;
  while ( v58 != nullptr )
  {
    v29 = v28 + 1;
    v30 = *v58;
    v31 = v58[1];
    if ( v26 < v29 )
    {
      v42 = v58[1];
      v49 = v30;
      v32 = runtime_growslice(a1: 1, a2: &unk_50FEE0);
      v30 = v49;
      v31 = v42;
      v34 = v33;
      v27 = v32;
      v26 = v34;
    }
    v40 = v29;
    v41 = v26;
    v35 = 16 * (v29 - 1);
    *(_QWORD *)(v27 + v35 + 8) = v31;
    if ( dword_70D560 != 0 )
    {
      sub_4725A0(a1: v25);
      *v36 = v30;
      v36[1] = *(_QWORD *)(v27 + v35);
    }
    v48 = v27;
    *(_QWORD *)(v27 + v35) = v30;
    sub_414B60();
    v26 = v41;
    v27 = v48;
    v28 = v40;
  }
  v52 = v27;
  v40 = v28;
  v45 = v26;
  sub_4D3220();
  return v52;
}