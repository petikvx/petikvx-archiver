__int64 __fastcall sub_4F9920(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // rax
  __int64 v7; // rbx
  __int64 v8; // r10
  __int64 v9; // r11
  __int64 v10; // r14
  char v11; // al
  char v12; // al
  char v13; // cl
  __int64 v14; // rax
  __int64 v15; // rdx
  char v16; // cl
  __int64 v17; // rax
  __int64 v18; // rdx
  __int64 v19; // rcx
  __int64 v21; // rax
  __int64 v22; // rdx
  __int64 v23; // rcx
  __int128 v24; // [rsp+50h] [rbp-50h] BYREF
  const char *v25; // [rsp+60h] [rbp-40h]
  __int64 v26; // [rsp+68h] [rbp-38h]
  __int128 v27; // [rsp+70h] [rbp-30h]
  __int64 (__gostk *v28)(); // [rsp+80h] [rbp-20h]
  __int64 v29; // [rsp+88h] [rbp-18h]
  __int64 v30; // [rsp+90h] [rbp-10h]
  __int64 v31; // [rsp+98h] [rbp-8h]
  __int128 v32; // [rsp+B0h] [rbp+10h]
  __int64 v33; // [rsp+C0h] [rbp+20h]
  __int64 v34; // [rsp+D0h] [rbp+30h]
  __int64 v36; // [rsp+E8h] [rbp+48h]
  __int64 v37; // [rsp+F0h] [rbp+50h]

  if ( (unsigned __int64)&v24 <= *(_QWORD *)(v10 + 16) )
    sub_470660();
  v37 = v9;
  v36 = v8;
  *((_QWORD *)&v32 + 1) = v7;
  *(_QWORD *)&v32 = v6;
  if ( a4 != 0 )
  {
    v33 = a4;
    v34 = a2;
    (*(void (**)(void))(a4 + 40))();
    if ( (*(unsigned __int8 (**)(void))(v33 + 32))() != 0 )
    {
      v11 = (unsigned __int8)sub_4F7E40() != 0 ? 1 : sub_4F7F00();
      if ( v11 != 0 )
        return qword_6C7EA0;
    }
    if ( (*(unsigned __int8 (**)(void))(v33 + 32))() == 0 )
    {
      v12 = (unsigned __int8)sub_4F7FC0() != 0 ? 1 : sub_4F7F00();
      if ( v12 != 0 )
        return 0;
    }
    v6 = v32;
    a4 = v33;
    a2 = v34;
  }
  if ( a2 != 0 )
  {
    if ( a4 != 0 )
    {
      v13 = (*(__int64 (**)(void))(a4 + 32))();
      v6 = v32;
    }
    else
    {
      v13 = 0;
    }
    if ( v13 != 0 )
    {
      v14 = runtime_convTstring();
      sub_47A480(a1: v14, a2: &unk_5102E0, a3: v15, a4: &unk_50FEE0, a5: &unk_56D188);
      if ( v16 == 0 )
      {
        sub_4F9700();
        v24 = v32;
        v26 = 20;
        v25 = "README-GENTLEMEN.txt";
        sub_4CBA40();
        v17 = runtime_stringtoslicebyte();
        sub_4B5DC0(a1: v36, a2: v19, a3: v18, a4: v17, a5: 420);
        v28 = sub_4F9E00;
        v29 = a6;
        v31 = v37;
        v30 = v36;
        sub_4CB600();
      }
    }
    else
    {
      *(_QWORD *)&v27 = v6;
      *((_QWORD *)&v27 + 1) = v7;
      runtime_chansend1();
    }
    return 0;
  }
  else
  {
    if ( a4 != 0 )
    {
      if ( (*(unsigned __int8 (**)(void))(a4 + 32))() != 0 )
      {
        sub_4CBA40();
        v21 = runtime_stringtoslicebyte();
        sub_4B5DC0(a1: v36, a2: v23, a3: v22, a4: v21, a5: 420);
      }
      else
      {
        v27 = v32;
        runtime_chansend1();
      }
    }
    return 0;
  }
}