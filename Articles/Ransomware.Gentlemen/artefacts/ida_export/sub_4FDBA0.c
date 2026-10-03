__int64 __fastcall sub_4FDBA0()
{
  __int64 v0; // r14
  const char **v1; // rdx
  __int64 i; // rax
  __int64 v4; // [rsp+38h] [rbp-130h]
  __int64 v5; // [rsp+40h] [rbp-128h]
  const char *v6; // [rsp+48h] [rbp-120h]
  _QWORD v7[6]; // [rsp+50h] [rbp-118h] BYREF
  _QWORD v8[2]; // [rsp+80h] [rbp-E8h] BYREF
  _QWORD v9[14]; // [rsp+90h] [rbp-D8h] BYREF
  _QWORD v10[2]; // [rsp+100h] [rbp-68h] BYREF
  const char *v11; // [rsp+110h] [rbp-58h]
  __int64 v12; // [rsp+118h] [rbp-50h]
  _QWORD v13[8]; // [rsp+120h] [rbp-48h] BYREF
  const char **v14; // [rsp+160h] [rbp-8h]

  if ( (unsigned __int64)v9 <= *(_QWORD *)(v0 + 16) )
    sub_470660();
  v7[1] = 8;
  v7[0] = "fdrespub";
  v7[3] = 7;
  v7[2] = "fdPHost";
  v7[5] = 7;
  v7[4] = "SSDPSRV";
  v8[1] = 8;
  v8[0] = "upnphost";
  v1 = (const char **)v7;
  for ( i = 0; i < 4; i = v5 + 1 )
  {
    v5 = i;
    v14 = v1;
    v6 = *v1;
    v4 = (__int64)v1[1];
    v13[1] = 6;
    v13[0] = "config";
    v13[3] = v4;
    v13[2] = v6;
    v13[5] = 6;
    v13[4] = "start=";
    v13[7] = 4;
    v13[6] = "auto";
    sub_4CDE40(a1: 4, a2: 4, a3: "auto", a4: v13);
    sub_4CF220();
    v10[1] = 5;
    v10[0] = "start";
    v12 = v4;
    v11 = v6;
    sub_4CDE40(a1: 2, a2: 2, a3: v6, a4: v10);
    sub_4CF220();
    v1 = v14 + 2;
  }
  sub_472C06(a1: v8);
  v9[1] = 11;
  v9[0] = "advfirewall";
  v9[3] = 8;
  v9[2] = "firewall";
  v9[5] = 3;
  v9[4] = "set";
  v9[7] = 4;
  v9[6] = "rule";
  v9[9] = 23;
  v9[8] = "group=Network Discovery";
  v9[11] = 3;
  v9[10] = "new";
  v9[13] = 10;
  v9[12] = "enable=Yes";
  sub_4CDE40(a1: 7, a2: 7, a3: "enable=Yes", a4: v9);
  sub_4CF220();
  v10[1] = 8;
  v10[0] = "-Command";
  v12 = 78;
  v11 = "Get-NetFirewallRule -DisplayGroup \"Network Discovery\" | Enable-NetFirewallRule";
  sub_4CDE40(
    a1: 2,
    a2: 2,
    a3: "Get-NetFirewallRule -DisplayGroup \"Network Discovery\" | Enable-NetFirewallRule",
    a4: v10);
  return sub_4CF220();
}