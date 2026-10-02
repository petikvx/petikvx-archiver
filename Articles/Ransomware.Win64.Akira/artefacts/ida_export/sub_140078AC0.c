void sub_140078AC0()
{
  unsigned int v0; // edi
  __int64 v1; // r8
  __int64 v2; // rbp
  __int64 v3; // rdx
  __int64 v4; // rax
  unsigned __int64 v5; // rcx
  void **v6; // r9
  void *v7; // r10
  __int64 v8; // rax
  unsigned __int64 v9; // r11
  _QWORD *v10; // rax
  unsigned __int16 v11; // dx
  bool v12; // cf
  char v13; // bl
  int v14; // eax
  _DWORD *v15; // r8
  void *Block[2]; // [rsp+30h] [rbp-68h] BYREF
  unsigned __int64 v17; // [rsp+40h] [rbp-58h]
  unsigned __int64 v18; // [rsp+48h] [rbp-50h]
  _BYTE v19[24]; // [rsp+50h] [rbp-48h] BYREF
  PVOID pMemory; // [rsp+68h] [rbp-30h] BYREF
  DWORD v21; // [rsp+70h] [rbp-28h] BYREF

  pMemory = nullptr;
  v21 = 0;
  if ( WTSEnumerateProcessesW(
         hServer: nullptr,
         Reserved: 0,
         Version: 1u,
         ppProcessInfo: (PWTS_PROCESS_INFOW *)&pMemory,
         pCount: &v21) )
  {
    v0 = 0;
    if ( v21 != 0 )
    {
      while ( 1 )
      {
        *(_OWORD *)Block = 0;
        v17 = 0;
        v1 = -1;
        v18 = 0;
        v2 = 24LL * v0;
        v3 = *(_QWORD *)((char *)pMemory + v2 + 8);
        do
          ++v1;
        while ( *(_WORD *)(v3 + 2 * v1) != 0 );
        sub_14003EE60(a1: Block, a2: v3, a3: v1);
        v4 = sub_14005DEA0(a1: &qword_140102158, a2: v19, a3: Block);
        v7 = Block[0];
        v8 = *(_QWORD *)(v4 + 16);
        if ( *(_BYTE *)(v8 + 25) != 0 )
          break;
        v9 = *(_QWORD *)(v8 + 48);
        v10 = (_QWORD *)(v8 + 32);
        if ( v10[3] >= 8u )
          v10 = (_QWORD *)*v10;
        v6 = Block;
        v5 = v17;
        if ( v18 >= 8 )
          v6 = (void **)Block[0];
        if ( v9 < v17 )
          v5 = v9;
        if ( v5 != 0 )
        {
          v6 = (void **)((char *)v6 - (__int64)v10);
          while ( 1 )
          {
            v11 = *(_WORD *)((char *)v10 + (_QWORD)v6);
            v12 = v11 < *(_WORD *)v10;
            if ( v11 != *(_WORD *)v10 )
              break;
            v10 = (_QWORD *)((char *)v10 + 2);
            if ( --v5 == 0 )
              goto LABEL_16;
          }
          v14 = 1;
          if ( v12 )
            v14 = -1;
          if ( v14 < 0 )
            break;
        }
        else
        {
LABEL_16:
          if ( v17 < v9 )
            break;
        }
        v13 = 1;
LABEL_22:
        if ( v18 >= 8 )
        {
          if ( 2 * v18 + 2 >= 0x1000 )
          {
            v7 = *((void **)Block[0] - 1);
            if ( (unsigned __int64)((char *)Block[0] - (char *)v7 - 8) > 0x1F )
              invalid_parameter_noinfo_noreturn();
          }
          j_j_free(Block: v7);
        }
        if ( v13 != 0 )
        {
          v15 = (char *)pMemory + v2 + 4;
          if ( (_QWORD)xmmword_1401021C0 == *((_QWORD *)&xmmword_1401021C0 + 1) )
          {
            sub_140079290(a1: v5, a2: xmmword_1401021C0, a3: v15, a4: v6);
          }
          else
          {
            *(_DWORD *)xmmword_1401021C0 = *v15;
            *(_QWORD *)&xmmword_1401021C0 = xmmword_1401021C0 + 4;
          }
        }
        if ( ++v0 >= v21 )
          goto LABEL_31;
      }
      v13 = 0;
      goto LABEL_22;
    }
  }
LABEL_31:
  if ( pMemory != nullptr )
    WTSFreeMemory(pMemory);
}