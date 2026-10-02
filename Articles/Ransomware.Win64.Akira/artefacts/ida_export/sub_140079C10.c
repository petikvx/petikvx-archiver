void sub_140079C10()
{
  unsigned __int64 i; // r9
  DWORD v1; // eax
  HANDLE v2; // rax
  void *v3; // rbx
  _BYTE v4[16]; // [rsp+21h] [rbp-4Fh] BYREF
  char v5[13]; // [rsp+31h] [rbp-3Fh] BYREF
  char v6[29]; // [rsp+3Eh] [rbp-32h] BYREF
  char v7[10]; // [rsp+5Bh] [rbp-15h] BYREF
  _BYTE v8[8]; // [rsp+65h] [rbp-Bh] BYREF

  if ( CoInitializeEx(pvReserved: nullptr, dwCoInit: 0) >= 0 )
  {
    v4[0] = 13;
    v4[1] = 51;
    v4[2] = 1;
    v4[3] = 50;
    v4[4] = 64;
    v4[5] = 26;
    v4[6] = 63;
    v4[7] = 50;
    v4[8] = 38;
    v4[9] = 38;
    v4[10] = 108;
    v4[11] = 50;
    v4[12] = 90;
    v4[13] = 50;
    v4[14] = 5;
    v4[15] = 19;
    strcpy(v5, "H3");
    v5[3] = 0;
    v5[4] = 75;
    v5[5] = 89;
    v5[6] = 88;
    v5[7] = 5;
    v5[8] = 56;
    v5[9] = 47;
    v5[10] = 50;
    v5[11] = 115;
    v5[12] = 19;
    strcpy(v6, "J");
    v6[2] = 25;
    v6[3] = 124;
    v6[4] = 37;
    v6[5] = 114;
    v6[6] = 50;
    v6[7] = 126;
    v6[8] = 115;
    v6[9] = 5;
    v6[10] = 74;
    v6[11] = 25;
    v6[12] = 89;
    v6[13] = 45;
    v6[14] = 83;
    v6[15] = 24;
    v6[16] = 99;
    v6[17] = 63;
    v6[18] = 75;
    v6[19] = 88;
    v6[20] = 51;
    v6[21] = 1;
    v6[22] = 126;
    v6[23] = 51;
    v6[24] = 13;
    v6[25] = 52;
    v6[26] = 5;
    v6[27] = 65;
    v6[28] = 5;
    strcpy(v7, "\n2");
    v7[3] = 51;
    v7[4] = 39;
    v7[5] = 50;
    v7[6] = 19;
    strcpy(&v7[7], "J");
    v7[9] = 25;
    qmemcpy(v8, "|%r2~s8N", sizeof(v8));
    for ( i = 0; i < 0x4C; ++i )
      v4[i] = (10 * ((unsigned __int8)v4[i] - 78) % 127 + 127) % 127;
    v1 = sub_1400794B0(a1: v4);
    if ( v1 != 0 )
    {
      v2 = OpenProcess(dwDesiredAccess: 0x100000u, bInheritHandle: false, dwProcessId: v1);
      v3 = v2;
      if ( v2 != nullptr )
      {
        WaitForSingleObject(hHandle: v2, dwMilliseconds: 0x3A98u);
        CloseHandle(hObject: v3);
      }
    }
    CoUninitialize();
  }
}