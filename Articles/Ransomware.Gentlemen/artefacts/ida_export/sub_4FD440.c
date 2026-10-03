__int64 __fastcall sub_4FD440()
{
  __int64 v0; // r14
  __int64 v2; // [rsp+58h] [rbp-E0h]
  _QWORD v3[2]; // [rsp+78h] [rbp-C0h] BYREF
  const char *v4; // [rsp+88h] [rbp-B0h] BYREF
  _QWORD v5[13]; // [rsp+90h] [rbp-A8h] BYREF
  _QWORD v6[8]; // [rsp+F8h] [rbp-40h] BYREF

  if ( (unsigned __int64)v5 <= *(_QWORD *)(v0 + 16) )
    sub_470660();
  sub_4B4D40();
  if ( qword_6C7F78 == 0 )
    sub_472A00();
  sub_4C83E0(a1: " ", a2: 1, a3: qword_6C7F70, a4: qword_6C7F80 - 1);
  runtime_convTstring();
  v3[0] = &unk_50FEE0;
  v3[1] = runtime_convTstring();
  v2 = fmt_Sprintf();
  v6[1] = 7;
  v6[0] = "/Delete";
  v6[3] = 3;
  v6[2] = "/TN";
  v6[5] = 10;
  v6[4] = "UpdateUser";
  v6[7] = 2;
  v6[6] = "/F";
  sub_4CDE40(a1: 4, a2: 4, a3: "/F", a4: v6);
  sub_4CF220();
  sub_472C06(a1: v3);
  v5[0] = 7;
  v4 = "/Create";
  v5[2] = 3;
  v5[1] = "/SC";
  v5[4] = 7;
  v5[3] = "ONSTART";
  v5[6] = 3;
  v5[5] = "/TN";
  v5[8] = 10;
  v5[7] = "UpdateUser";
  v5[10] = 3;
  v5[9] = "/TR";
  v5[12] = 7;
  v5[11] = v2;
  sub_4CDE40(a1: 7, a2: 7, a3: v2, a4: &v4);
  return sub_4CF220();
}