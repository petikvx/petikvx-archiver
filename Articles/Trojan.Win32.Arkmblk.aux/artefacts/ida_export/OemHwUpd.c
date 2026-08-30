/* Hex-Rays decompilation of OemHwUpd */

// ----- sub_11008 @ 0x11008 -----
char __fastcall sub_11008(__int64 a1, unsigned __int16 *a2)
{
  _WORD *v3; // rdi
  int v4; // ecx
  NTSTATUS v5; // ebx
  struct _UNICODE_STRING DestinationString; // [rsp+60h] [rbp-58h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+70h] [rbp-48h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+80h] [rbp-38h] BYREF
  void *FileHandle; // [rsp+C0h] [rbp+8h] BYREF

  v3 = (_WORD *)(a1 + 1645710);
  FileHandle = nullptr;
  if ( a2 == nullptr )
    return 0;
  if ( *a2 < 2u || *a2 > 0x20Cu )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::IsFileExist(211):");
      DbgPrint("IsFileExist End Zero,Exceed Max length\n");
    }
    return 0;
  }
  v4 = dword_1F128;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::IsFileExist(215):");
    DbgPrint("IsFileExist [%d][%.128ws]\n", *a2, *((_QWORD *)a2 + 1));
    v4 = dword_1F128;
  }
  if ( *(_WORD *)(*((_QWORD *)a2 + 1) + 2LL) != 58 )
  {
    if ( v4 != 0 )
    {
      DbgPrint("END64::IsFileExist(217):");
      DbgPrint("IsFileExist No Colon!\n");
    }
    return 0;
  }
  memset(v3, 0, 0x20Cu);
  *v3 = 92;
  v3[1] = 63;
  v3[2] = 63;
  v3[3] = 92;
  memmove(v3 + 4, *((const void **)a2 + 1), *a2);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::IsFileExist(227):");
    DbgPrint("Full Path [%.128ws]\n", v3);
  }
  RtlInitUnicodeString(&DestinationString, v3);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v5 = ZwCreateFile(&FileHandle, 0x80u, &ObjectAttributes, &IoStatusBlock, nullptr, 0, 1u, 1u, 0, nullptr, 0);
  if ( v5 < 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::IsFileExist(234):");
      DbgPrint("IsFileExist End NO [%8.8X]\n", v5);
    }
    return 0;
  }
  ZwClose(FileHandle);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::IsFileExist(238):");
    DbgPrint("IsFileExist End YES\n");
  }
  return 1;
}


// ----- sub_11224 @ 0x11224 -----
__int64 __fastcall sub_11224(__int64 a1)
{
  _QWORD *v2; // rdi
  char *v3; // rbx
  __int64 i; // r12
  __int64 v5; // r12
  __int16 j; // r13
  __int16 *v7; // r14
  NTSTATUS v8; // edi
  int v9; // edi
  NTSTATUS NameString; // r14d
  int v11; // eax
  ULONG ReturnLength[2]; // [rsp+70h] [rbp-98h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+78h] [rbp-90h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+88h] [rbp-80h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+98h] [rbp-70h] BYREF
  PVOID VirtualAddress; // [rsp+120h] [rbp+18h] BYREF
  void *FileHandle; // [rsp+128h] [rbp+20h] BYREF

  *(_BYTE *)(a1 + 1645176) = 1;
  v2 = (_QWORD *)(a1 + 1631344);
  v3 = (char *)(a1 + 1631552);
  for ( i = 26; i != 0; --i )
  {
    memset(v3, 0, 0x20Cu);
    *v2++ = 0;
    v3 += 524;
  }
  v5 = 2;
  for ( j = 67; (unsigned __int16)j <= 0x5Au; ++j )
  {
    v7 = (__int16 *)(a1 + 8 * v5 + 1631344);
    *v7 = j;
    *(_WORD *)(a1 + 8 * v5 + 1631346) = 58;
    *(_WORD *)(a1 + 8 * v5 + 1631348) = 0;
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::InitDrVolume(258):");
      DbgPrint("Finding [%ws] Volume\n", a1 + 8 * v5 + 1631344);
    }
    FileHandle = nullptr;
    *(_QWORD *)(a1 + 1646774) = 0x73006F0044005CLL;
    *(_QWORD *)(a1 + 1646782) = 0x69007600650044LL;
    *(_QWORD *)(a1 + 1646790) = 0x5C007300650063LL;
    *(_QWORD *)(a1 + 1646798) = *(_QWORD *)v7;
    RtlInitUnicodeString(&DestinationString, (PCWSTR)(a1 + 1646774));
    ObjectAttributes.Length = 48;
    ObjectAttributes.RootDirectory = nullptr;
    ObjectAttributes.Attributes = 0;
    ObjectAttributes.ObjectName = &DestinationString;
    ObjectAttributes.SecurityDescriptor = nullptr;
    ObjectAttributes.SecurityQualityOfService = nullptr;
    v8 = ZwCreateFile(&FileHandle, 0x80000000, &ObjectAttributes, &IoStatusBlock, nullptr, 0, 1u, 1u, 0, nullptr, 0);
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::InitDrVolume(272):");
      DbgPrint("[%ws] [%8.8X]\n", a1 + 1646774, (unsigned int)v8);
    }
    if ( v8 != -1073741772 && v8 != 0 )
    {
      *(_WORD *)(a1 + 8 * v5 + 1631348) = 92;
      *(_QWORD *)(a1 + 1646774) = 0x73006F0044005CLL;
      *(_QWORD *)(a1 + 1646782) = 0x69007600650044LL;
      *(_QWORD *)(a1 + 1646790) = 0x5C007300650063LL;
      *(_QWORD *)(a1 + 1646798) = *(_QWORD *)v7;
      RtlInitUnicodeString(&DestinationString, (PCWSTR)(a1 + 1646774));
      ObjectAttributes.Length = 48;
      ObjectAttributes.RootDirectory = nullptr;
      ObjectAttributes.Attributes = 0;
      ObjectAttributes.ObjectName = &DestinationString;
      ObjectAttributes.SecurityDescriptor = nullptr;
      ObjectAttributes.SecurityQualityOfService = nullptr;
      v8 = ZwCreateFile(&FileHandle, 0x80000000, &ObjectAttributes, &IoStatusBlock, nullptr, 0, 1u, 1u, 0, nullptr, 0);
    }
    if ( v8 >= 0 )
    {
      v9 = qword_1F560(FileHandle, 0, IoFileObjectType, 0, &VirtualAddress, 0);
      if ( v9 >= 0 )
      {
        if ( MmIsAddressValid(VirtualAddress) == 0 )
          goto LABEL_18;
        if ( *((__int16 *)VirtualAddress + 1) < 40 )
        {
          if ( dword_1F128 != 0 )
          {
            DbgPrint("END64::InitDrVolume(295):");
            DbgPrint(
              "fileObj Type [%d] Size[%d]<[%d]\n",
              *(__int16 *)VirtualAddress,
              *((__int16 *)VirtualAddress + 1),
              216);
          }
LABEL_18:
          ObfDereferenceObject(VirtualAddress);
          v9 = -1073741816;
        }
      }
      if ( v9 >= 0 )
      {
        if ( dword_1F128 != 0 )
        {
          DbgPrint("END64::InitDrVolume(312):");
          DbgPrint("fileObj Type [%d] Size[%d]\n", *(__int16 *)VirtualAddress, *((__int16 *)VirtualAddress + 1));
        }
        if ( *(_WORD *)VirtualAddress == 5 && *((_BYTE *)VirtualAddress + 73) != 0 )
        {
          ObfDereferenceObject(VirtualAddress);
          v9 = -1073741816;
        }
      }
      if ( v9 >= 0 && MmIsAddressValid(*((PVOID *)VirtualAddress + 1)) != 0 )
      {
        NameString = ObQueryNameString(
                       *((PVOID *)VirtualAddress + 1),
                       (POBJECT_NAME_INFORMATION)(a1 + 1645710),
                       0x104u,
                       ReturnLength);
        if ( NameString >= 0 && *(_QWORD *)ReturnLength != 0 )
        {
          if ( *(_WORD *)(a1 + 1645710) != 0 && *(_QWORD *)(a1 + 1645718) != 0 )
          {
            if ( dword_1F128 != 0 )
            {
              DbgPrint("END64::InitDrVolume(324):");
              DbgPrint(
                "[%ws] [%3d][%ws] Updated\n",
                a1 + 8 * v5 + 1631344,
                *(unsigned __int16 *)(a1 + 1645710),
                *(_QWORD *)(a1 + 1645718));
            }
            if ( *(_WORD *)(a1 + 1645710) <= 0x20Cu )
              v11 = *(unsigned __int16 *)(a1 + 1645710);
            else
              v11 = 524;
            memmove((void *)(524 * v5 + a1 + 1631552), *(const void **)(a1 + 1645718), v11);
          }
          else if ( dword_1F128 != 0 )
          {
            DbgPrint("END64::InitDrVolume(328):");
            DbgPrint("ObQueryNameString Failed![%8.8X]\n", NameString);
          }
        }
        ObfDereferenceObject(VirtualAddress);
      }
      else if ( dword_1F128 != 0 )
      {
        DbgPrint("END64::InitDrVolume(333):");
        DbgPrint("ObReferenceObjectByHandle Failed![%8.8X]\n", v9);
      }
      ZwClose(FileHandle);
    }
    ++v5;
  }
  return 0;
}


// ----- sub_11794 @ 0x11794 -----
__int64 __fastcall sub_11794(__int64 a1, unsigned __int64 *a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // rbx
  unsigned __int64 i; // rdi
  _BYTE v9[16]; // [rsp+20h] [rbp-48h] BYREF

  v3 = 0;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::EnumSysPids(349):");
    DbgPrint("maxPid[%8.8I64X]\n", a3);
  }
  if ( a3 >= 0x4E1C )
    a3 = 19996;
  memset(a2, 0, 8 * a3);
  for ( i = 4; i < 0x4E1C; ++i )
  {
    if ( v3 >= a3 )
      break;
    if ( sub_15ABC(a1, i, v9) != 0 )
    {
      *a2++ = i;
      if ( dword_1F128 != 0 )
      {
        DbgPrint("END64::EnumSysPids(357):");
        DbgPrint("SysPid[%8.8X]\n", i);
      }
      if ( ++v3 >= a3 )
        break;
    }
  }
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::EnumSysPids(362):");
    DbgPrint("nPid[%8.8I64X]\n", v3);
  }
  return 8 * v3;
}


// ----- sub_118AC @ 0x118ac -----
__int64 __fastcall sub_118AC(__int64 a1, const void *a2, size_t a3)
{
  __int64 v5; // rbx
  char *i; // rdi

  v5 = 2;
  for ( i = (char *)(a1 + 1632600); memcmp(i, a2, a3) != 0; i += 524 )
  {
    if ( (unsigned __int64)++v5 >= 0x1A )
      return -1;
  }
  return v5;
}


// ----- sub_1191C @ 0x1191c -----
unsigned __int64 __fastcall sub_1191C(__int64 a1, void *a2, char *a3, char a4, unsigned __int64 a5)
{
  char *v6; // rsi
  unsigned __int64 v9; // r13
  const char *v10; // r8
  void *v11; // r12
  NTSTATUS v13; // edi
  unsigned __int64 v14; // r14
  NTSTATUS v15; // edi
  PVOID *v16; // rcx
  int v17; // eax
  char v18; // cl
  __int64 v19; // rcx
  unsigned __int16 *v20; // r12
  __int64 v21; // rdi
  __int64 v22; // rdi
  __int64 v23; // rdi
  char *v24; // rcx
  unsigned __int16 *v25; // rax
  __int64 v26; // r13
  _WORD *v27; // r12
  __int64 v28; // r11
  __int64 v29; // r12
  _WORD *v30; // rdx
  PVOID v31; // rcx
  __int64 v32; // rcx
  PVOID *v33; // r12
  char v34; // di
  __int64 v35; // rdi
  __int64 v36; // rdi
  PULONG ReturnLength; // [rsp+20h] [rbp-1E8h]
  __int64 v38; // [rsp+30h] [rbp-1D8h]
  PVOID Object; // [rsp+48h] [rbp-1C0h] BYREF
  char v41; // [rsp+50h] [rbp-1B8h]
  __int64 v42; // [rsp+58h] [rbp-1B0h]
  __int64 v43; // [rsp+60h] [rbp-1A8h]
  void *Dst; // [rsp+68h] [rbp-1A0h]
  __int64 i; // [rsp+70h] [rbp-198h] BYREF
  PEPROCESS Process; // [rsp+78h] [rbp-190h] BYREF
  ULONG v47[2]; // [rsp+80h] [rbp-188h] BYREF
  void *v48; // [rsp+88h] [rbp-180h]
  char *v49; // [rsp+90h] [rbp-178h]
  __int64 v50; // [rsp+98h] [rbp-170h]
  void *v51; // [rsp+A0h] [rbp-168h]
  char *v52; // [rsp+A8h] [rbp-160h]
  __int64 v53; // [rsp+B0h] [rbp-158h]
  char ObjectInformation[256]; // [rsp+C0h] [rbp-148h] BYREF

  v6 = a3;
  Dst = a3;
  v42 = a1;
  v53 = a1;
  v51 = a2;
  v52 = a3;
  v41 = a4;
  v9 = 0;
  v43 = 0;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::GetFileHandles2(396):");
    v10 = (const char *)qword_196F0;
    if ( a4 != 0 )
      v10 = "Yes";
    DbgPrint("GetFileHandles2- Pid[%8.8X] Name[%s]\n", (_DWORD)a2, v10);
  }
  v11 = *(void **)((char *)IoGetCurrentProcess() + qword_1F130);
  v48 = v11;
  if ( a4 != 0 )
  {
    v49 = v6;
    memset(v6, 0, 534 * a5);
  }
  else
  {
    v6 = nullptr;
    v49 = nullptr;
    memset(Dst, 0, 8 * a5);
  }
  if ( v11 != a2 && ((int)sub_1575C(a2, &i) < 0 || i != 259) )
    return 0;
  if ( v11 == a2 )
  {
    v13 = 0;
    Process = IoGetCurrentProcess();
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::GetFileHandles2(420):");
      DbgPrint(
        "GetFileHandles2==PID[%8.8X] eProcess[%8.8X] is Current Process==========\n",
        (_DWORD)a2,
        (_DWORD)Process);
    }
  }
  else
  {
    v13 = PsLookupProcessByProcessId(a2, &Process);
  }
  if ( v13 >= 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::GetFileHandles2(427):");
      DbgPrint("PID[%8.8X] eProcess[%8.8X]\n", (_DWORD)a2, (_DWORD)Process);
    }
    if ( v11 != a2 )
    {
      KeAttachProcess(Process);
      if ( dword_1F128 != 0 )
      {
        DbgPrint("END64::GetFileHandles2(430):");
        DbgPrint("Attached to PID[%8.8X] Process!\n", (_DWORD)a2);
      }
    }
    if ( *(_BYTE *)(a1 + 1645176) == 0 )
      sub_11224(a1);
    v14 = 4;
    for ( i = 4; ; i = v14 )
    {
      if ( v14 >= 0x1000 )
      {
LABEL_224:
        if ( v11 != a2 )
        {
          KeDetachProcess();
          if ( dword_1F128 != 0 )
          {
            DbgPrint("END64::GetFileHandles2(717):");
            DbgPrint("Detached from PID[%8.8X] Process!\n", (_DWORD)a2);
          }
        }
        goto LABEL_229;
      }
      if ( v9 >= a5 )
      {
        if ( dword_1F128 != 0 )
        {
          DbgPrint("END64::GetFileHandles2(436):");
          DbgPrint("Exceed Max Storage...Stopped[%d]!\n", a5);
        }
        goto LABEL_224;
      }
      memset((void *)(v42 + 1646774), 0, 0x20Cu);
      *(_QWORD *)v47 = 262;
      v15 = 0;
      if ( v11 == a2 )
      {
        v15 = ZwQueryObject((HANDLE)v14, ObjectBasicInformation, ObjectInformation, 0x100u, nullptr);
        if ( v15 != -1073741816 )
          v15 = 0;
      }
      if ( v15 >= 0 )
        v15 = qword_1F560(v14, 0, IoFileObjectType, 0, &Object, 0);
      if ( v15 >= 0 )
      {
        if ( dword_1F128 != 0 )
        {
          DbgPrint("END64::GetFileHandles2(460):");
          DbgPrint("fileObj Type [%d] Size[%d]==[%d]\n", *(__int16 *)Object, *((__int16 *)Object + 1), 216);
        }
        if ( (unsigned __int8)sub_15A34(Object) == 0
          || *((__int16 *)Object + 1) < 40
          || *(_WORD *)Object == 5 && *((_BYTE *)Object + 73) != 0 )
        {
          ObfDereferenceObject(Object);
          v15 = -1073741816;
        }
      }
      if ( v15 >= 0 )
        break;
LABEL_223:
      v14 += 4LL;
    }
    if ( MmIsAddressValid(Object) == 0 || MmIsAddressValid(*((PVOID *)Object + 1)) == 0 )
      goto LABEL_221;
    if ( MmIsAddressValid(*((PVOID *)Object + 1)) != 0 && MmIsAddressValid(Object) != 0 )
    {
      v16 = (PVOID *)Object;
      if ( *(_WORD *)Object != 5 )
        goto LABEL_166;
      if ( MmIsAddressValid((char *)Object + 88) != 0 && MmIsAddressValid((char *)Object + 88) != 0 )
      {
        v16 = (PVOID *)Object;
        if ( *((_WORD *)Object + 44) == 0 || *((_WORD *)Object + 44) >= 0x106u || (*((_BYTE *)Object + 88) & 1) != 0 )
          goto LABEL_166;
        if ( MmIsAddressValid(*((PVOID *)Object + 12)) != 0 )
        {
          v16 = (PVOID *)Object;
          if ( (*((_QWORD *)Object + 12) & 0xFFFFF00000000000uLL) == 0 )
            goto LABEL_166;
          if ( MmIsAddressValid((char *)Object + 2) != 0 )
          {
            v16 = (PVOID *)Object;
            if ( *((_WORD *)Object + 1) != 0 )
            {
              if ( MmIsAddressValid(*((PVOID *)Object + 2)) != 0 )
              {
                v17 = dword_1F128;
                if ( dword_1F128 != 0 )
                {
                  DbgPrint("END64::GetFileHandles2(485):");
                  LODWORD(ReturnLength) = *((unsigned __int16 *)Object + 44);
                  DbgPrint(
                    "File(vpb)Handle[%8.8X]-Flags[%8.8X][%3.3X] Len[%d][%.128ws]\n",
                    v14,
                    *((unsigned int *)Object + 20),
                    *((_DWORD *)Object + 20) & 0x100,
                    ReturnLength,
                    *((_QWORD *)Object + 12));
                  v17 = dword_1F128;
                }
                if ( v17 != 0 )
                {
                  DbgPrint("END64::GetFileHandles2(487):");
                  DbgPrint(
                    "[%d] [%ws]\n",
                    *(unsigned __int16 *)(*((_QWORD *)Object + 2) + 6LL),
                    *((_QWORD *)Object + 2) + 32LL);
                }
                v18 = a4;
              }
              else
              {
                if ( dword_1F128 != 0 )
                {
                  DbgPrint("END64::GetFileHandles2(492):");
                  LODWORD(ReturnLength) = *((unsigned __int16 *)Object + 44);
                  DbgPrint(
                    "File(   )Handle[%8.8X]-Flags[%8.8X][%3.3X] Len[%d][%.128ws]\n",
                    v14,
                    *((unsigned int *)Object + 20),
                    *((_DWORD *)Object + 20) & 0x100,
                    ReturnLength,
                    *((_QWORD *)Object + 12));
                }
                if ( MmIsAddressValid(*(PVOID *)(*((_QWORD *)Object + 1) + 8LL)) != 0 )
                {
                  v19 = *(_QWORD *)(*((_QWORD *)Object + 1) + 8LL);
                  if ( (v19 & 0xFFFFF00000000000uLL) != 0 )
                  {
                    if ( MmIsAddressValid((PVOID)(v19 + 56)) != 0 )
                      v20 = (unsigned __int16 *)(*(_QWORD *)(*((_QWORD *)Object + 1) + 8LL) + 56LL);
                    else
                      v20 = nullptr;
                    if ( v20 != nullptr )
                    {
                      if ( MmIsAddressValid(v20) != 0 )
                      {
                        if ( MmIsAddressValid(v20) != 0 )
                        {
                          if ( *v20 != 0 )
                          {
                            if ( *v20 >= 0x106u )
                            {
                              v18 = a4;
                            }
                            else if ( (*(_BYTE *)v20 & 1) != 0 )
                            {
                              v18 = a4;
                            }
                            else if ( MmIsAddressValid(*((PVOID *)v20 + 1)) != 0 )
                            {
                              if ( a4 != 0 )
                              {
                                v21 = 534 * v9;
                                *(_QWORD *)&v6[v21] = v14;
                                *(_WORD *)&v6[v21 + 8] = 2 - (*((_QWORD *)Object + 2) != 0);
                                memset(&v6[534 * v9 + 10 + 2 * ((unsigned __int64)*v20 >> 1)], 0, 524 - *v20);
                                memmove(&v6[534 * v9 + 10], *((const void **)v20 + 1), *v20);
                                if ( *(_WORD *)&v6[534 * v9 + 12] == 68
                                  && *(_WORD *)&v6[v21 + 14] == 114
                                  && *(_WORD *)&v6[v21 + 16] == 105
                                  && *(_WORD *)&v6[v21 + 18] == 118
                                  && *(_WORD *)&v6[v21 + 20] == 101
                                  && *(_WORD *)&v6[v21 + 22] == 114
                                  && *(_WORD *)&v6[v21 + 24] == 92 )
                                {
                                  *(_WORD *)&v6[v21 + 12] = 68;
                                  *(_WORD *)&v6[v21 + 14] = 101;
                                  *(_WORD *)&v6[v21 + 16] = 118;
                                  *(_WORD *)&v6[v21 + 18] = 105;
                                  *(_WORD *)&v6[v21 + 20] = 99;
                                  *(_WORD *)&v6[v21 + 22] = 101;
                                  if ( *(_WORD *)&v6[v21 + 26] == 84
                                    && *(_WORD *)&v6[v21 + 28] == 99
                                    && *(_WORD *)&v6[v21 + 30] == 112
                                    && *(_WORD *)&v6[v21 + 32] == 105
                                    && *(_WORD *)&v6[v21 + 34] == 112 )
                                  {
                                    *(_WORD *)&v6[v21 + 26] = 82;
                                    *(_WORD *)&v6[v21 + 28] = 97;
                                    *(_WORD *)&v6[v21 + 30] = 119;
                                    *(_WORD *)&v6[v21 + 32] = 73;
                                    *(_WORD *)&v6[v21 + 34] = 112;
                                    *(_WORD *)&v6[v21 + 36] = 92;
                                  }
                                  if ( dword_1F128 != 0 )
                                  {
                                    DbgPrint("END64::GetFileHandles2(540):");
                                    DbgPrint(
                                      "File Handle11[%8.8X]-Len[%d] [%.128ws]\n",
                                      v14,
                                      *v20,
                                      *((_QWORD *)v20 + 1));
                                  }
                                  *(_WORD *)&v6[v21 + 8] = 2;
                                }
                                else
                                {
                                  *(_WORD *)&v6[v21 + 8] = 1;
                                }
                              }
                              else
                              {
                                *((_QWORD *)Dst + v9) = v14;
                              }
                              if ( dword_1F128 != 0 )
                              {
                                DbgPrint("END64::GetFileHandles2(548):");
                                DbgPrint(
                                  "File Handle2[%8.8X]-OF[%8.8X] Len[%d] [%.128ws]\n",
                                  v14,
                                  *((unsigned int *)Object + 20),
                                  *v20,
                                  *((_QWORD *)v20 + 1));
                              }
                              if ( MmIsAddressValid(*((PVOID *)Object + 3)) != 0 )
                              {
                                v22 = *((_QWORD *)Object + 3);
                                if ( MmIsAddressValid((PVOID)(v22 - 4)) != 0 )
                                {
                                  if ( dword_1F128 != 0 )
                                  {
                                    DbgPrint("END64::GetFileHandles2(555):");
                                    DbgPrint("ObjectType=[%3.3s]\n", (const char *)(v22 - 4));
                                  }
                                  if ( *(_BYTE *)(v22 - 4) == 84
                                    && *(_BYTE *)(v22 - 3) == 67
                                    && *(_BYTE *)(v22 - 2) == 80 )
                                  {
                                    v18 = a4;
                                  }
                                  else
                                  {
                                    v18 = a4;
                                    if ( a4 != 0 )
                                      *(_WORD *)&v6[534 * v9 + 8] = 1;
                                  }
                                }
                                else
                                {
                                  v18 = a4;
                                }
                              }
                              else
                              {
                                v18 = a4;
                              }
                            }
                            else
                            {
                              v18 = a4;
                            }
                          }
                          else
                          {
                            v18 = a4;
                          }
                        }
                        else
                        {
                          v18 = a4;
                        }
                      }
                      else
                      {
                        v18 = a4;
                      }
                    }
                    else
                    {
                      v18 = a4;
                    }
                  }
                  else
                  {
                    v18 = a4;
                  }
                }
                else
                {
                  v18 = a4;
                }
              }
              if ( v18 != 0 )
              {
                v23 = 534 * v9;
                *(_QWORD *)&v6[534 * v9] = v14;
                if ( *((char *)Object + 80) >= 0 )
                {
                  if ( *(_WORD *)&v6[v23 + 8] == 2 )
                  {
                    v24 = &v6[v23 + 36];
                    if ( *(_WORD *)v24 == 92 )
                      memmove(v24, *((const void **)Object + 12), *((unsigned __int16 *)Object + 44));
                    else
                      memmove(&v6[v23 + 32], *((const void **)Object + 12), *((unsigned __int16 *)Object + 44));
                  }
                  else
                  {
                    *(_WORD *)&v6[v23 + 8] = 1;
                    if ( MmIsAddressValid(*((PVOID *)Object + 1)) != 0 && MmIsAddressValid(*((PVOID *)Object + 2)) != 0 )
                    {
                      v25 = (unsigned __int16 *)Object;
                      if ( *((_QWORD *)Object + 2) != 0 )
                      {
                        v26 = v42;
                        if ( ObQueryNameString(
                               *((PVOID *)Object + 1),
                               (POBJECT_NAME_INFORMATION)(v42 + 1645710),
                               0x104u,
                               v47) < 0 )
                        {
                          v9 = v43;
                        }
                        else if ( *(_QWORD *)v47 != 0 )
                        {
                          if ( *(_WORD *)(v26 + 1645710) != 0 )
                          {
                            if ( *(_QWORD *)(v26 + 1645718) != 0 )
                            {
                              if ( dword_1F128 != 0 )
                              {
                                DbgPrint("END64::GetFileHandles2(588):");
                                DbgPrint("FileHanle Objectname [%wZ]\n", v26 + 1645710);
                              }
                              v27 = *(_WORD **)(v26 + 1645718);
                              v28 = sub_118AC(v26, v27, *(unsigned __int16 *)(v26 + 1645710));
                              v50 = v28;
                              if ( v28 == -1 )
                              {
                                if ( v27[1] == 68 )
                                {
                                  if ( v27[2] == 101 )
                                  {
                                    if ( v27[3] == 118 )
                                    {
                                      if ( v27[4] == 105 )
                                      {
                                        if ( v27[5] == 99 )
                                        {
                                          if ( v27[6] == 101 )
                                          {
                                            v29 = v26;
                                            sub_11224(v26);
                                            v28 = sub_118AC(
                                                    v26,
                                                    *(const void **)(v26 + 1645718),
                                                    *(unsigned __int16 *)(v26 + 1645710));
                                            v50 = v28;
                                          }
                                          else
                                          {
                                            v29 = v26;
                                          }
                                        }
                                        else
                                        {
                                          v29 = v26;
                                        }
                                      }
                                      else
                                      {
                                        v29 = v26;
                                      }
                                    }
                                    else
                                    {
                                      v29 = v26;
                                    }
                                  }
                                  else
                                  {
                                    v29 = v26;
                                  }
                                }
                                else
                                {
                                  v29 = v26;
                                }
                              }
                              else
                              {
                                v29 = v26;
                              }
                              if ( v28 == -1 )
                              {
                                memmove(
                                  &v6[v23 + 10],
                                  *((const void **)Object + 12),
                                  *((unsigned __int16 *)Object + 44));
                                v9 = v43;
                              }
                              else
                              {
                                *(_DWORD *)&v6[v23 + 10] = *(_DWORD *)(v29 + 8 * v28 + 1631344);
                                *(_WORD *)&v6[v23 + 14] = *(_WORD *)(v29 + 8 * v28 + 1631348);
                                v30 = *((_WORD **)Object + 12);
                                if ( *v30 == 92 )
                                  memmove(&v6[v23 + 14], v30, *((unsigned __int16 *)Object + 44));
                                else
                                  memmove(&v6[v23 + 16], v30, *((unsigned __int16 *)Object + 44));
                                v9 = v43;
                              }
                            }
                            else
                            {
                              v9 = v43;
                            }
                          }
                          else
                          {
                            v9 = v43;
                          }
                        }
                        else
                        {
                          v9 = v43;
                        }
                        goto LABEL_164;
                      }
                    }
                    else
                    {
                      v25 = (unsigned __int16 *)Object;
                    }
                    memset(&v6[534 * v9 + 10 + 2 * ((unsigned __int64)v25[44] >> 1)], 0, 262 - v25[44]);
                    memmove(&v6[v23 + 10], *((const void **)Object + 12), *((unsigned __int16 *)Object + 44));
                  }
                }
                else
                {
                  *(_WORD *)&v6[v23 + 8] = 3;
                  memmove(&v6[v23 + 10], L"\\Device\\NamedPipe", 0x22u);
                  memmove(&v6[v23 + 44], *((const void **)Object + 12), *((unsigned __int16 *)Object + 44));
                }
              }
              else
              {
                *((_QWORD *)Dst + v9) = v14;
              }
LABEL_164:
              v43 = ++v9;
              ObfDereferenceObject(Object);
LABEL_222:
              v11 = v48;
              goto LABEL_223;
            }
            goto LABEL_166;
          }
        }
      }
    }
    v16 = (PVOID *)Object;
LABEL_166:
    if ( MmIsAddressValid(v16[1]) != 0
      && MmIsAddressValid((char *)Object + 88) != 0
      && MmIsAddressValid((char *)Object + 88) != 0 )
    {
      v31 = Object;
      if ( *((_WORD *)Object + 44) != 0 || *((_QWORD *)Object + 12) != 0 )
        goto LABEL_220;
      if ( MmIsAddressValid(Object) != 0 )
      {
        v31 = Object;
        if ( *(_WORD *)Object != 5 )
          goto LABEL_220;
        if ( MmIsAddressValid((char *)Object + 2) != 0 )
        {
          v31 = Object;
          if ( *((_WORD *)Object + 1) != 0 )
          {
            if ( MmIsAddressValid(*(PVOID *)(*((_QWORD *)Object + 1) + 8LL)) != 0 )
            {
              v32 = *(_QWORD *)(*((_QWORD *)Object + 1) + 8LL);
              if ( (v32 & 0xFFFFF00000000000uLL) != 0 )
              {
                v33 = MmIsAddressValid((PVOID)(v32 + 56)) != 0
                    ? (PVOID *)(*(_QWORD *)(*((_QWORD *)Object + 1) + 8LL) + 56LL)
                    : nullptr;
                if ( v33 != nullptr
                  && MmIsAddressValid(v33) != 0
                  && MmIsAddressValid(v33) != 0
                  && *(_WORD *)v33 != 0
                  && *(_WORD *)v33 < 0x106u
                  && (*(_BYTE *)v33 & 1) == 0
                  && MmIsAddressValid(v33[1]) != 0 )
                {
                  v34 = a4;
                  if ( a4 != 0 )
                  {
                    v35 = 534 * v9;
                    *(_QWORD *)&v6[v35] = v14;
                    *(_WORD *)&v6[v35 + 8] = 2 - (*((_QWORD *)Object + 2) != 0);
                    memset(
                      &v6[534 * v9 + 10 + 2 * ((unsigned __int64)*(unsigned __int16 *)v33 >> 1)],
                      0,
                      524 - *(unsigned __int16 *)v33);
                    memmove(&v6[534 * v9 + 10], v33[1], *(unsigned __int16 *)v33);
                    if ( *(_WORD *)&v6[534 * v9 + 12] == 68
                      && *(_WORD *)&v6[v35 + 14] == 114
                      && *(_WORD *)&v6[v35 + 16] == 105
                      && *(_WORD *)&v6[v35 + 18] == 118
                      && *(_WORD *)&v6[v35 + 20] == 101
                      && *(_WORD *)&v6[v35 + 22] == 114
                      && *(_WORD *)&v6[v35 + 24] == 92 )
                    {
                      *(_WORD *)&v6[v35 + 12] = 68;
                      *(_WORD *)&v6[v35 + 14] = 101;
                      *(_WORD *)&v6[v35 + 16] = 118;
                      *(_WORD *)&v6[v35 + 18] = 105;
                      *(_WORD *)&v6[v35 + 20] = 99;
                      *(_WORD *)&v6[v35 + 22] = 101;
                      if ( dword_1F128 != 0 )
                      {
                        DbgPrint("END64::GetFileHandles2(668):");
                        DbgPrint("File Handle3[%8.8X]-Len[%d] [%.128ws]\n", v14, *(unsigned __int16 *)v33, v33[1]);
                      }
                      *(_WORD *)&v6[v35 + 8] = 2;
                      v34 = a4;
                    }
                    else
                    {
                      *(_WORD *)&v6[v35 + 8] = 1;
                      v34 = a4;
                    }
                  }
                  else
                  {
                    *((_QWORD *)Dst + v9) = v14;
                  }
                  if ( dword_1F128 != 0 )
                  {
                    DbgPrint("END64::GetFileHandles2(681):");
                    LODWORD(v38) = *(unsigned __int16 *)v33;
                    DbgPrint(
                      "File Handle4[%8.8X]-OF[%8.8X][%3.3X] FsContext[%8.8X] 2[%8.8X] Len[%d] [%.128ws]\n",
                      v14,
                      *((unsigned int *)Object + 20),
                      *((_DWORD *)Object + 20) & 0x100,
                      *((_QWORD *)Object + 3),
                      *((_QWORD *)Object + 4),
                      v38,
                      v33[1]);
                  }
                  if ( v34 != 0 && *(_WORD *)&v6[534 * v9 + 8] == 2 )
                  {
                    if ( MmIsAddressValid(*((PVOID *)Object + 3)) != 0 && *((_QWORD *)Object + 4) == 1 )
                    {
                      v36 = *((_QWORD *)Object + 3);
                      if ( MmIsAddressValid((PVOID)(v36 - 4)) != 0 )
                      {
                        if ( *(_BYTE *)(v36 - 4) == 84 && *(_BYTE *)(v36 - 3) == 67 && *(_BYTE *)(v36 - 2) == 80 )
                        {
                          v43 = ++v9;
                        }
                        else if ( dword_1F128 != 0 )
                        {
                          DbgPrint("END64::GetFileHandles2(692):");
                          DbgPrint("Phantom Handle7[%8.8X]!!!\n", v14);
                        }
                      }
                      else if ( dword_1F128 != 0 )
                      {
                        DbgPrint("END64::GetFileHandles2(694):");
                        DbgPrint("Phantom Handle6[%8.8X]!!!\n", v14);
                      }
                    }
                    else if ( dword_1F128 != 0 )
                    {
                      DbgPrint("END64::GetFileHandles2(696):");
                      DbgPrint("Phantom Handle5[%8.8X]!!!\n", v14);
                    }
                  }
                  else
                  {
                    v43 = ++v9;
                  }
                }
              }
            }
LABEL_221:
            ObfDereferenceObject(Object);
            goto LABEL_222;
          }
LABEL_220:
          ObfDereferenceObject(v31);
          goto LABEL_222;
        }
      }
    }
    v31 = Object;
    goto LABEL_220;
  }
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::GetFileHandles2(721):");
    DbgPrint("PsLookupProcessByProcessId Failed[%8.8X]!\n", v13);
  }
LABEL_229:
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::GetFileHandles2(723):");
    DbgPrint("Total Handle[%d]\n", v9);
  }
  return v9;
}


// ----- sub_129B0 @ 0x129b0 -----
__int64 __fastcall sub_129B0(__int64 a1, void *a2, __int64 *a3, unsigned __int64 a4)
{
  unsigned __int64 v6; // rdi
  __int64 v7; // r13
  bool v8; // r14
  const char *v9; // r8
  void *v10; // r15
  NTSTATUS InformationProcess; // esi
  int v12; // eax
  int v14; // esi
  NTSTATUS v15; // esi
  unsigned __int16 *v16; // rsi
  unsigned __int16 *v17; // r13
  __int64 v18; // rax
  __int64 v19; // rdx
  unsigned __int64 v20; // r8
  __int64 v21; // r10
  _BYTE *v22; // rcx
  _BYTE *v23; // r9
  unsigned __int64 v24; // rdx
  unsigned __int64 v25; // rcx
  unsigned __int8 v26; // al
  size_t v27; // r15
  __int64 v28; // r13
  __int16 v29; // r11
  PEPROCESS Process; // [rsp+40h] [rbp-118h] BYREF
  ULONG ReturnLength[2]; // [rsp+48h] [rbp-110h] BYREF
  __int64 v32; // [rsp+50h] [rbp-108h]
  unsigned __int16 *v33; // [rsp+58h] [rbp-100h]
  __int64 v34; // [rsp+60h] [rbp-F8h]
  void *ProcessHandle; // [rsp+68h] [rbp-F0h] BYREF
  void *v36; // [rsp+70h] [rbp-E8h]
  unsigned __int64 v37; // [rsp+78h] [rbp-E0h]
  _BYTE *v38; // [rsp+80h] [rbp-D8h]
  __int64 v39; // [rsp+88h] [rbp-D0h]
  unsigned __int64 v40; // [rsp+90h] [rbp-C8h]
  unsigned __int16 *v41; // [rsp+98h] [rbp-C0h]
  _BYTE *v42; // [rsp+A0h] [rbp-B8h]
  unsigned __int64 v43; // [rsp+A8h] [rbp-B0h]
  struct _CLIENT_ID ClientId; // [rsp+B0h] [rbp-A8h] BYREF
  _QWORD ProcessInformation[6]; // [rsp+C0h] [rbp-98h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+F0h] [rbp-68h] BYREF

  v37 = a4;
  v32 = a1;
  v6 = 0;
  v7 = 0;
  v39 = 0;
  v8 = a4 == 0;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::GetPidDlls(741):");
    v9 = (const char *)qword_196F0;
    if ( v8 )
      v9 = "Yes";
    DbgPrint("GetPidDlls- Pid[%8.8X] CountOnly[%s]\n", (_DWORD)a2, v9);
  }
  v10 = *(void **)((char *)IoGetCurrentProcess() + qword_1F130);
  v36 = v10;
  if ( !v8 )
    memset(a3, 0, 534 * v37);
  if ( v10 != a2 )
  {
    ClientId.UniqueProcess = a2;
    ClientId.UniqueThread = nullptr;
    ObjectAttributes.Length = 24;
    memset(&ObjectAttributes.RootDirectory, 0, 20);
    ObjectAttributes.SecurityDescriptor = nullptr;
    ObjectAttributes.SecurityQualityOfService = nullptr;
    if ( ZwOpenProcess(&ProcessHandle, 0x40u, &ObjectAttributes, &ClientId) < 0 )
      return 0;
    memset(ProcessInformation, 0, sizeof(ProcessInformation));
    InformationProcess = ZwQueryInformationProcess(
                           ProcessHandle,
                           ProcessBasicInformation,
                           ProcessInformation,
                           0x30u,
                           ReturnLength);
    if ( InformationProcess < 0 )
    {
      if ( dword_1F128 != 0 )
      {
        DbgPrint("END64::GetPidDlls(778):");
        DbgPrint("ZwQueryInformationProcess Failed[%8.8X]\n", InformationProcess);
      }
    }
    else
    {
      v12 = dword_1F128;
      if ( dword_1F128 != 0 )
      {
        DbgPrint("END64::GetPidDlls(768):");
        DbgPrint(
          "PID[%8.8X] ExitStatus[%8.8X] PEB[%8.8X]\n",
          LODWORD(ProcessInformation[4]),
          LODWORD(ProcessInformation[0]),
          LODWORD(ProcessInformation[1]));
        v12 = dword_1F128;
      }
      if ( LODWORD(ProcessInformation[0]) != 259 )
      {
        ZwClose(ProcessHandle);
        return 0;
      }
      v7 = ProcessInformation[1];
      v39 = ProcessInformation[1];
      v14 = ProcessInformation[5];
      if ( v12 != 0 )
      {
        DbgPrint("END64::GetPidDlls(775):");
        DbgPrint("OpenProcess PebBaseAddress[%8.8X] ParentPid[%5X]\n", LODWORD(ProcessInformation[1]), v14);
      }
    }
    ZwClose(ProcessHandle);
  }
  if ( v10 == a2 )
  {
    v15 = 0;
    Process = IoGetCurrentProcess();
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::GetPidDlls(789):");
      DbgPrint("GetPidDlls==PID[%8.8X] eProcess[%8.8X] is Current Process==========\n", (_DWORD)a2, (_DWORD)Process);
    }
  }
  else
  {
    v15 = PsLookupProcessByProcessId(a2, &Process);
  }
  if ( v15 < 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::GetPidDlls(920):");
      DbgPrint("PsLookupProcessByProcessId Failed[%8.8X]!\n", v15);
    }
  }
  else
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::GetPidDlls(796):");
      DbgPrint("PID[%8.8X] eProcess[%8.8X]\n", (_DWORD)a2, (_DWORD)Process);
    }
    if ( v10 != a2 )
    {
      KeAttachProcess(Process);
      if ( dword_1F128 != 0 )
      {
        DbgPrint("END64::GetPidDlls(799):");
        DbgPrint("Attached to PID[%8.8X] Process!\n", (_DWORD)a2);
      }
    }
    if ( v7 != 0 )
    {
      v16 = *(unsigned __int16 **)(*(_QWORD *)(v7 + 24) + 24LL);
      v41 = v16;
      v17 = v16;
      v33 = v16;
      if ( !v8 && MmIsAddressValid(v16) != 0 )
      {
        v18 = sub_14FE8(*((_QWORD *)v16 + 10));
        v20 = v18;
        *(_QWORD *)ReturnLength = v18;
        if ( dword_1F128 != 0 )
        {
          DbgPrint("END64::GetPidDlls(808):", v19, v18);
          DbgPrint("Process[%d] [%.128ws]\n", *(_QWORD *)ReturnLength, *((_QWORD *)v16 + 10));
          v20 = *(_QWORD *)ReturnLength;
        }
        v21 = v32;
        v22 = (_BYTE *)(v32 + 1645177);
        v38 = (_BYTE *)(v32 + 1645177);
        v23 = *((_BYTE **)v16 + 10);
        v42 = v23;
        v24 = 0;
        v43 = 0;
        while ( v24 < v20 )
        {
          *v22++ = *v23;
          v38 = v22;
          v23 += 2;
          v42 = v23;
          v43 = ++v24;
        }
        *v22 = 0;
        v38 = v22 + 1;
        v25 = 0;
        v40 = 0;
        while ( v25 < v20 )
        {
          v26 = *(_BYTE *)(v25 + v21 + 1645177);
          if ( v26 >= 0x41u && v26 <= 0x5Au )
          {
            *(_BYTE *)(v25 + v21 + 1645177) = v26 + 32;
            v20 = *(_QWORD *)ReturnLength;
          }
          v40 = ++v25;
        }
        if ( dword_1F128 != 0 )
        {
          DbgPrint("END64::GetPidDlls(814):");
          DbgPrint("Process [%.128s]\n", (const char *)(v32 + 1645177));
        }
      }
      if ( MmIsAddressValid(v16) != 0 )
      {
        do
        {
          if ( dword_1F128 != 0 )
          {
            DbgPrint("END64::GetPidDlls(864):");
            DbgPrint("[%2d] Module[%.128ws]\n", v6, *((_QWORD *)v16 + 10));
          }
          if ( dword_1F128 != 0 )
          {
            DbgPrint("END64::GetPidDlls(866):");
            DbgPrint(
              "     B[%8.8X] S[%8.8X] eP[%8.8X] F[%8.8X] lC[%3d] I[%8.8X]\n",
              *((_QWORD *)v16 + 6),
              *((_QWORD *)v16 + 8),
              *((_QWORD *)v16 + 7),
              *((_QWORD *)v16 + 13),
              (__int16)v16[56],
              (__int16)v16[57]);
          }
          if ( !v8 && v6 != 0 )
          {
            v27 = 524;
            v28 = 534 * v6;
            *(__int64 *)((char *)a3 + 534 * v6 - 534) = *((_QWORD *)v16 + 8);
            if ( v16[36] >= 0x20CuLL )
            {
              DbgPrint("END64::GetPidDlls(873):");
              DbgPrint("Buffer Overrun condition\n");
            }
            else
            {
              v27 = v16[36];
            }
            memmove((char *)a3 + v28 - 524, *((const void **)v16 + 10), v27);
            v29 = (*((_DWORD *)v16 + 26) & 0x200000) != 0;
            *(_WORD *)((char *)a3 + v28 - 526) = v29;
            if ( v29 != 0 )
            {
              if ( sub_11008(v32, v16 + 36) == 0 )
                *(_WORD *)((char *)a3 + v28 - 526) = 2;
              v17 = v33;
            }
            else
            {
              v17 = v33;
            }
          }
          v34 = ++v6;
          if ( v6 > v37 && !v8 )
            break;
          v16 = *(unsigned __int16 **)v16;
          v41 = v16;
          if ( MmIsAddressValid(v16) == 0 )
            break;
        }
        while ( v17 != *(unsigned __int16 **)v16 );
        if ( v8 )
        {
          v6 += 10LL;
          v34 = v6;
        }
        v10 = v36;
      }
    }
    if ( v10 != a2 )
    {
      KeDetachProcess();
      if ( dword_1F128 != 0 )
      {
        DbgPrint("END64::GetPidDlls(916):");
        DbgPrint("Detached from PID[%8.8X] Process!\n", (_DWORD)a2);
      }
    }
  }
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::GetPidDlls(922):");
    DbgPrint("Total Handle[%d]\n", v6);
  }
  if ( v8 )
    *a3 = (v6 - 1) & -(__int64)(v6 != 0);
  return (v6 - 1) & -(__int64)(v6 != 0);
}


// ----- sub_1309C @ 0x1309c -----
char __fastcall sub_1309C(__int64 a1, void *a2, _QWORD *a3)
{
  char v5; // bl
  __int64 v6; // rsi
  __int64 *PoolWithTag; // rdi
  void *v8; // rax
  void *ProcessHandle; // [rsp+30h] [rbp-68h] BYREF
  ULONG ReturnLength; // [rsp+38h] [rbp-60h] BYREF
  struct _CLIENT_ID ClientId; // [rsp+40h] [rbp-58h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+50h] [rbp-48h] BYREF
  void *TokenHandle; // [rsp+A8h] [rbp+10h] BYREF
  SIZE_T TokenInformationLength; // [rsp+B8h] [rbp+20h] BYREF

  v5 = 1;
  TokenHandle = nullptr;
  v6 = 0;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::GetPidTokenSid(940):");
    DbgPrint("GetPidTokenSid Pid[%8.8X] Beg\n", (_DWORD)a2);
  }
  ClientId.UniqueProcess = a2;
  ClientId.UniqueThread = nullptr;
  ObjectAttributes.Length = 24;
  memset(&ObjectAttributes.RootDirectory, 0, 20);
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  if ( ZwOpenProcess(&ProcessHandle, 0x40u, &ObjectAttributes, &ClientId) >= 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::GetPidTokenSid(952):");
      DbgPrint("PID[%8.8X]\n", (_DWORD)a2);
    }
    if ( ZwOpenProcessToken(ProcessHandle, 8u, &TokenHandle) != 0 )
    {
      if ( dword_1F128 != 0 )
      {
        DbgPrint("END64::GetPidTokenSid(974):");
        DbgPrint("ZwOpenProcessToken is Failed!\n");
      }
      v5 = 0;
LABEL_22:
      if ( v5 == 0 )
        goto LABEL_24;
      goto LABEL_23;
    }
    ZwQueryInformationToken(TokenHandle, TokenUser, nullptr, 0, (PULONG)&TokenInformationLength);
    PoolWithTag = (__int64 *)ExAllocatePoolWithTag(NonPagedPool, TokenInformationLength, 0x656E6431u);
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::GetPidTokenSid(956):");
      DbgPrint("tBuf[%8.8X] reqLen[%8.8X]\n", (_DWORD)PoolWithTag, TokenInformationLength);
    }
    if ( PoolWithTag != nullptr )
    {
      if ( ZwQueryInformationToken(TokenHandle, TokenUser, PoolWithTag, TokenInformationLength, &ReturnLength) != 0 )
      {
        if ( dword_1F128 != 0 )
        {
          DbgPrint("END64::GetPidTokenSid(963):");
          DbgPrint("ZwQueryInformationToken is Failed!\n");
        }
        v5 = 0;
      }
      else
      {
        v6 = *PoolWithTag;
        if ( dword_1F128 != 0 )
        {
          DbgPrint("END64::GetPidTokenSid(960):");
          DbgPrint("UserSid[%8.8X]!\n", v6);
        }
      }
      ExFreePoolWithTag(PoolWithTag, 0);
      goto LABEL_22;
    }
    if ( dword_1F128 != 0 )
    {
      DbgPrint("END64::GetPidTokenSid(969):");
      DbgPrint("Allocate TokenBuffer is Failed!!\n");
      goto LABEL_22;
    }
  }
LABEL_23:
  v8 = TokenHandle;
  a3[1] = v6;
  *a3 = v8;
LABEL_24:
  if ( dword_1F128 != 0 )
  {
    DbgPrint("END64::GetPidTokenSid(983):");
    DbgPrint("GetPidTokenSid hToken[%8.8X] Sid[%8.8X]End\n", (_DWORD)TokenHandle, v6);
  }
  return v5;
}


// ----- sub_13320 @ 0x13320 -----
void __fastcall sub_13320(_QWORD *a1, unsigned int *a2)
{
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // r12
  __int64 i; // rdi
  __int64 v6; // rax

  v3 = *a1 << 12;
  v4 = a1[1] << 12;
  for ( i = 0; v3 <= v4; ++i )
  {
    ProbeForRead((volatile void *)v3, 1u, 1u);
    v6 = *a2;
    if ( (unsigned int)v6 >= a2[1] )
      break;
    *(_QWORD *)&a2[1026 * v6 + 2] = v3 >> 12;
    memmove(&a2[1026 * *a2 + 4], (const void *)v3, 0x1000u);
    ++*a2;
    v3 += 4096LL;
  }
}


// ----- sub_133F0 @ 0x133f0 -----
__int64 __fastcall sub_133F0(_QWORD *a1, unsigned int *a2)
{
  unsigned __int64 v2; // rbp
  int v6; // eax
  NTSTATUS v7; // eax
  __int64 v8; // r12
  _QWORD *v9; // rsi
  int v10; // ecx
  unsigned __int64 v11; // rsi
  _QWORD *v12; // rbp
  __int64 v13; // [rsp+40h] [rbp+8h] BYREF
  PEPROCESS Process; // [rsp+50h] [rbp+18h] BYREF

  v13 = 0;
  Process = nullptr;
  v2 = 0;
  if ( *a1 == -1 )
    return 3221225711LL;
  v6 = sub_1575C(*a1, &v13);
  if ( v6 < 0 || v13 != 259 )
  {
    if ( dword_1F11C != 0 )
      DbgPrint("Warning: (END64::GetPageDataList) GetProcExitStatus (%X) or exitcode (%X).\n", v6, v13);
    return 3221225712LL;
  }
  v7 = PsLookupProcessByProcessId((HANDLE)*a1, &Process);
  if ( v7 < 0 )
  {
    if ( dword_1F11C != 0 )
      DbgPrint("Warning: (END64::GetPageDataList) PsLookupProcessByProcessId failed 0x%x\n", v7);
    return 3221225712LL;
  }
  v8 = *(_QWORD *)((char *)IoGetCurrentProcess() + qword_1F130);
  if ( v8 != *a1 )
    KeAttachProcess(Process);
  *a2 = 0;
  if ( *((_DWORD *)a1 + 2) != 0 )
  {
    v9 = (_QWORD *)((char *)a1 + 12);
    do
    {
      sub_13320(v9, a2);
      if ( *a2 == a2[1] )
        break;
      ++v2;
      v9 += 2;
    }
    while ( v2 < *((unsigned int *)a1 + 2) );
  }
  v10 = dword_1F118;
  v11 = 0;
  if ( dword_1F118 != 0 )
  {
    DbgPrint("Valid VPNs:\n");
    v10 = dword_1F118;
  }
  if ( *a2 != 0 )
  {
    v12 = a2 + 2;
    do
    {
      if ( v10 != 0 )
      {
        DbgPrint("%-8x ", *v12);
        v10 = dword_1F118;
      }
      if ( (++v11 & 0xF) == 0 && v10 != 0 )
      {
        DbgPrint("\n");
        v10 = dword_1F118;
      }
      v12 += 513;
    }
    while ( v11 < *a2 );
  }
  if ( v10 != 0 )
    DbgPrint("\n\n");
  if ( v8 != *a1 )
    KeDetachProcess();
  return 0;
}


// ----- sub_13590 @ 0x13590 -----
__int64 __fastcall sub_13590(PCWSTR SourceString)
{
  NTSTATUS v2; // eax
  int v3; // ecx
  int v4; // ebx
  unsigned int *PoolWithTag; // rsi
  NTSTATUS v7; // ebx
  int v8; // ebp
  unsigned __int16 v9; // cx
  unsigned __int16 v10; // dx
  __int16 v11; // r8
  unsigned __int16 v12; // r8
  unsigned __int16 v13; // cx
  __int16 v14; // r9
  _WORD *v15; // rbx
  size_t v16; // rdi
  void *KeyHandle; // [rsp+30h] [rbp-2A8h] BYREF
  ULONG ResultLength; // [rsp+38h] [rbp-2A0h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-298h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+50h] [rbp-288h] BYREF
  struct _UNICODE_STRING ValueName; // [rsp+80h] [rbp-258h] BYREF
  WCHAR SourceStringa[16]; // [rsp+90h] [rbp-248h] BYREF
  _WORD Dst[256]; // [rsp+B0h] [rbp-228h] BYREF

  KeyHandle = nullptr;
  wcscpy(SourceStringa, L"ImagePath");
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetDriverName(152):");
    DbgPrint("GetDriverName Beg [%ws]\n", SourceString);
  }
  RtlInitUnicodeString(&DestinationString, SourceString);
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  v2 = ZwOpenKey(&KeyHandle, 1u, &ObjectAttributes);
  v3 = dword_1F128;
  v4 = v2;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetDriverName(156):");
    DbgPrint("RegPath[%ws]\n", DestinationString.Buffer);
    v3 = dword_1F128;
  }
  if ( v4 < 0 )
  {
    if ( v3 != 0 )
    {
      DbgPrint("GetDriverName(158):");
      DbgPrint("RegOpen Failed! [%8.8X]\n", v4);
    }
    return 3221225473LL;
  }
  if ( v3 != 0 )
  {
    DbgPrint("GetDriverName(161):");
    DbgPrint("RegOpen OK!\n");
  }
  PoolWithTag = (unsigned int *)ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x656E6431u);
  if ( PoolWithTag == nullptr )
  {
    ZwClose(KeyHandle);
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetDriverName(166):");
      DbgPrint("ExAllocatePool failed on GetDriverName\n");
    }
    return 3221225473LL;
  }
  ResultLength = 0;
  RtlInitUnicodeString(&ValueName, SourceStringa);
  v7 = ZwQueryValueKey(KeyHandle, &ValueName, KeyValueFullInformation, PoolWithTag, 0xFFu, &ResultLength);
  if ( v7 < 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetDriverName(175):");
      DbgPrint("RegQuery Failed on Open! [%8.8X]\n", v7);
    }
    ExFreePoolWithTag(PoolWithTag, 0);
    return 3221225473LL;
  }
  memset(&::Dst, 0, 0x100u);
  memset(&qword_1F140, 0, 0x100u);
  memset(Dst, 0, 0x100u);
  memmove(Dst, (char *)PoolWithTag + PoolWithTag[2], 0x100u);
  v8 = dword_1F128;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetDriverName(186):");
    DbgPrint("wName[%ws]\n", Dst);
    v8 = dword_1F128;
  }
  v9 = 0;
  v10 = 256;
  do
  {
    v11 = Dst[v9];
    if ( v11 == 0 )
      break;
    if ( v11 == 92 )
      v10 = v9;
    ++v9;
  }
  while ( v9 < 0x100u );
  if ( v10 < 0x100u )
  {
    v12 = v10;
    v13 = 256;
    do
    {
      v14 = Dst[v12];
      if ( v14 == 0 )
        break;
      if ( v14 == 46 )
        v13 = v12;
      ++v12;
    }
    while ( v12 < 0x100u );
    if ( v13 < 0x100u && v13 >= v10 )
    {
      wmemcpy(&::Dst, L"\\Device", 7);
      v15 = &Dst[v10];
      v16 = 2LL * (v13 - v10);
      memmove(&unk_1F35E, v15, v16);
      wmemcpy(&qword_1F140, L"\\DosDevices", 11);
      memmove(&unk_1F156, v15, v16);
    }
  }
  if ( v8 != 0 )
  {
    DbgPrint("GetDriverName(207):");
    DbgPrint("ntDeviceName [%ws]\n", &::Dst);
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetDriverName(208):");
      DbgPrint("dosDeviceName[%ws]\n", &qword_1F140);
    }
  }
  ZwClose(KeyHandle);
  ExFreePoolWithTag(PoolWithTag, 0);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetDriverName(212):");
    DbgPrint("GetDriverName End\n");
  }
  return 0;
}


// ----- sub_139E4 @ 0x139e4 -----
__int64 __fastcall sub_139E4(PDRIVER_OBJECT DriverObject, __int64 a2)
{
  const WCHAR *v5; // rcx
  const WCHAR *v6; // rcx
  const WCHAR *v7; // rcx
  NTSTATUS v8; // edi
  _QWORD *DeviceExtension; // rdi
  NTSTATUS v10; // ebx
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-48h] BYREF
  struct _UNICODE_STRING SystemRoutineName; // [rsp+50h] [rbp-38h] BYREF
  struct _UNICODE_STRING SymbolicLinkName; // [rsp+60h] [rbp-28h] BYREF
  ULONG v14; // [rsp+98h] [rbp+10h] BYREF
  PDEVICE_OBJECT DeviceObject; // [rsp+A0h] [rbp+18h] BYREF

  DeviceObject = nullptr;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("DriverEntry(231):");
    DbgPrint("EnData2008 Compiled on %s at %s\n", "Nov  6 2008", "17:09:46");
    if ( dword_1F128 != 0 )
    {
      DbgPrint("DriverEntry(232):");
      DbgPrint("DriverEntry Beg\n");
      if ( dword_1F128 != 0 )
      {
        DbgPrint("DriverEntry(234):");
        DbgPrint("DriverPath[%ws]\n", *(_QWORD *)(a2 + 8));
      }
    }
  }
  if ( (int)sub_13590(*(PCWSTR *)(a2 + 8)) < 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("DriverEntry(237):");
      DbgPrint("GetDriverName Failed!!!\n");
    }
    return 3221225473LL;
  }
  v5 = *(const WCHAR **)(a2 + 8);
  v14 = 4;
  sub_18CF0(v5, L"ENDTRACE", (ULONG)&v14);
  v6 = *(const WCHAR **)(a2 + 8);
  v14 = 4;
  sub_18CF0(v6, L"VADTRACE", (ULONG)&v14);
  v7 = *(const WCHAR **)(a2 + 8);
  v14 = 4;
  sub_18CF0(v7, L"VADPRINT", (ULONG)&v14);
  RtlInitUnicodeString(&DestinationString, &Dst);
  RtlInitUnicodeString(&SystemRoutineName, L"ObReferenceObjectByHandle");
  qword_1F560 = (__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))MmGetSystemRoutineAddress(&SystemRoutineName);
  if ( qword_1F560 == nullptr )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("DriverEntry(258):");
      DbgPrint("MmGetSystemRoutineAddress failed getting ObReferenceObjectByHandle on DriverEntry\n");
    }
    return 3221225473LL;
  }
  v8 = IoCreateDevice(DriverObject, 0x192928u, &DestinationString, 0x22u, 0, 0, &DeviceObject);
  if ( v8 >= 0 )
  {
    KeInitializeMutex(&Mutex, 0);
    DeviceExtension = DeviceObject->DeviceExtension;
    qword_1F5A8 = (__int64)DeviceObject;
    DeviceExtension[206116] = 0;
    DriverObject->MajorFunction[0] = (PDRIVER_DISPATCH)&sub_13D1C;
    DriverObject->MajorFunction[2] = (PDRIVER_DISPATCH)&sub_13D8C;
    DriverObject->MajorFunction[14] = (PDRIVER_DISPATCH)&sub_14E64;
    qword_1F5A0 = (__int64)DriverObject;
    DriverObject->DriverUnload = (PDRIVER_UNLOAD)sub_13DFC;
    RtlInitUnicodeString(&SymbolicLinkName, &qword_1F140);
    v10 = IoCreateSymbolicLink(&SymbolicLinkName, &DestinationString);
    if ( v10 >= 0 )
    {
      qword_1F130 = 0;
      qword_1F120 = 0;
      qword_1F138 = 0;
      qword_1F110 = 0;
    }
    else
    {
      if ( dword_1F128 != 0 )
      {
        DbgPrint("DriverEntry(283):");
        DbgPrint("Couldn't create symbolic link\n");
      }
      IoDeleteDevice(DeviceObject);
    }
    DeviceExtension[206115] = IoGetCurrentProcess();
    if ( dword_1F128 != 0 )
    {
      DbgPrint("DriverEntry(293):");
      DbgPrint("DriverEntry End[%8.8X]\n", v10);
    }
    return (unsigned int)v10;
  }
  else
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("DriverEntry(264):");
      DbgPrint("Couldn't create the device object\n");
    }
    return (unsigned int)v8;
  }
}


// ----- sub_13D1C @ 0x13d1c -----
__int64 __fastcall sub_13D1C(__int64 a1, IRP *a2)
{
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GSICreate(299):");
    DbgPrint("Create Beg\n");
  }
  a2->IoStatus.Status = 0;
  a2->IoStatus.Information = 0;
  IofCompleteRequest(a2, 0);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GSICreate(303):");
    DbgPrint("Create End\n");
  }
  return 0;
}


// ----- sub_13D8C @ 0x13d8c -----
__int64 __fastcall sub_13D8C(__int64 a1, IRP *a2)
{
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GSIClose(308):");
    DbgPrint("Close Beg\n");
  }
  a2->IoStatus.Status = 0;
  a2->IoStatus.Information = 0;
  IofCompleteRequest(a2, 0);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GSIClose(312):");
    DbgPrint("Close End\n");
  }
  return 0;
}


// ----- sub_13DFC @ 0x13dfc -----
void __fastcall sub_13DFC(__int64 a1)
{
  struct _DEVICE_OBJECT *v1; // rbx
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  v1 = *(struct _DEVICE_OBJECT **)(a1 + 8);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GSIUnloadDriver(323):");
    DbgPrint("Unload Beg\n");
  }
  RtlInitUnicodeString(&DestinationString, &qword_1F140);
  IoDeleteSymbolicLink(&DestinationString);
  if ( v1 != nullptr )
    IoDeleteDevice(v1);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GSIUnloadDriver(329):");
    DbgPrint("Unload End\n");
  }
}


// ----- sub_13E80 @ 0x13e80 -----
__int64 __fastcall sub_13E80(__int64 a1, __int64 a2)
{
  unsigned int *v2; // r14
  __int64 v3; // r13
  int v4; // ecx
  __int64 *v5; // rsi
  SIZE_T CommitSize; // r12
  size_t v7; // rbp
  signed int v9; // ebx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  signed int v16; // eax
  unsigned __int64 v17; // rax
  __int64 v18; // rax
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rsi
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  char v26; // al
  size_t v27; // rbp
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // rbx
  __int64 v31; // rcx
  ULONG_PTR v32; // rax
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // eax
  __int64 v38; // rax
  __int64 v39; // rax
  __int64 v40; // rax
  __int64 v41; // rbx
  __int64 v42; // rax
  size_t v43; // rbp
  __int64 v44; // rax
  __int64 v45; // rdx
  __int64 v46; // rax
  unsigned int v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // eax
  unsigned int v50; // eax
  unsigned int v51; // eax
  int v52; // eax
  void *v53; // rbx
  union _LARGE_INTEGER v54; // rbp
  NTSTATUS v55; // eax
  NTSTATUS v56; // eax
  void *v57; // rcx
  _QWORD *PoolWithTag; // rax
  _QWORD *v59; // r13
  void *v60; // rcx
  _QWORD v62[9]; // [rsp+50h] [rbp-48h] BYREF
  ULONG_PTR MaxCount; // [rsp+A0h] [rbp+8h] BYREF
  PVOID BaseAddress; // [rsp+A8h] [rbp+10h] BYREF
  union _LARGE_INTEGER SectionOffset; // [rsp+B0h] [rbp+18h] BYREF

  v2 = *(unsigned int **)(a2 + 184);
  v3 = *(_QWORD *)(a1 + 64);
  v4 = dword_1F128;
  v5 = *(__int64 **)(a2 + 24);
  CommitSize = v2[4];
  v7 = v2[2];
  v9 = 0;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GSIIoctl64(357):");
    DbgPrint("IOCTL64-64Bit Struc Only\n");
    v4 = dword_1F128;
  }
  v10 = v2[6];
  if ( v10 > 0x22307C )
  {
    if ( v10 <= 0x223098 )
    {
      if ( v10 == 2240664 )
      {
        if ( v4 != 0 )
        {
          DbgPrint("GSIIoctl64(797):");
          DbgPrint("DeviceControl-SCAN-KMEM\n");
        }
        v41 = *v5;
        v42 = sub_175E0(v3, v5, v7 >> 9);
        v43 = v7 >> 9;
        v44 = sub_1704C(v3, v5, v43, v42);
        LOBYTE(v45) = v41;
        v46 = sub_182C0(v3, v45, v5, v43, v44);
        if ( v46 != 0 )
        {
          v18 = v46 << 9;
          v9 = 0;
          goto LABEL_287;
        }
        goto LABEL_108;
      }
      v33 = v10 - 2240640;
      if ( v33 == 0 )
      {
        if ( v4 != 0 )
        {
          DbgPrint("GSIIoctl64(745):");
          DbgPrint("DeviceControl-PidTokenSid\n");
          v4 = dword_1F128;
        }
        if ( CommitSize >= 8 )
        {
          if ( sub_1309C(v3, (void *)*v5, v62) != 0 )
          {
            *v5 = v62[0];
            v5[1] = v62[1];
            *(_QWORD *)(a2 + 56) = 16;
            goto LABEL_288;
          }
          goto LABEL_22;
        }
        if ( v4 == 0 )
          goto LABEL_19;
        DbgPrint("GSIIoctl64(747):");
        goto LABEL_18;
      }
      v34 = v33 - 4;
      if ( v34 != 0 )
      {
        v35 = v34 - 4;
        if ( v35 != 0 )
        {
          v36 = v35 - 4;
          if ( v36 == 0 )
          {
            if ( v4 != 0 )
            {
              DbgPrint("GSIIoctl64(615):");
              DbgPrint("DeviceControl-Get Pid Dlls\n");
              v4 = dword_1F128;
            }
            if ( CommitSize < 8 )
            {
              if ( v4 != 0 )
              {
                DbgPrint("GSIIoctl64(617):");
                DbgPrint("Output Buffer too Small!\n");
              }
              *(_QWORD *)(a2 + 56) = 0;
              v4 = dword_1F128;
            }
            if ( v7 < 0x216 )
            {
              if ( v4 == 0 )
                goto LABEL_19;
              DbgPrint("GSIIoctl64(622):");
              goto LABEL_38;
            }
            v17 = sub_129B0(v3, (void *)*v5, v5, v7 / 0x216);
            goto LABEL_40;
          }
          v37 = v36 - 4;
          if ( v37 != 0 )
          {
            if ( v37 == 4 )
            {
              if ( v4 != 0 )
              {
                DbgPrint("GSIIoctl64(375):");
                DbgPrint("DeviceControl-Set Eproc Off\n");
                v4 = dword_1F128;
              }
              if ( CommitSize >= 0x20 )
              {
                v38 = *v5;
                qword_1F110 = 0;
                qword_1F130 = v38;
                qword_1F120 = v5[1];
                qword_1F138 = v5[2];
                if ( CommitSize >= 0x28 )
                  qword_1F110 = v5[4];
                if ( v4 != 0 )
                {
                  DbgPrint("GSIIoctl64(391):");
                  DbgPrint(
                    "pidOff[%8.8X] flinkOff[%8.8X] imagenameOff[%8.8X] vadRootOff[%8.8X]\n",
                    qword_1F130,
                    qword_1F120,
                    qword_1F138,
                    qword_1F110);
                }
                goto LABEL_22;
              }
              if ( v4 == 0 )
                goto LABEL_19;
              DbgPrint("GSIIoctl64(377):");
              goto LABEL_18;
            }
            goto LABEL_252;
          }
          if ( v4 != 0 )
          {
            DbgPrint("GSIIoctl64(565):");
            DbgPrint("DeviceControl-Get Pid Dll Count\n");
            v4 = dword_1F128;
          }
          if ( CommitSize < 8 )
          {
            if ( v4 != 0 )
            {
              DbgPrint("GSIIoctl64(567):");
              DbgPrint("Output Buffer too Small!\n");
            }
            *(_QWORD *)(a2 + 56) = 0;
            v4 = dword_1F128;
          }
          if ( v7 < 8 )
          {
            if ( v4 == 0 )
              goto LABEL_19;
            DbgPrint("GSIIoctl64(572):");
            goto LABEL_38;
          }
          v39 = sub_129B0(v3, (void *)*v5, v5, 0);
LABEL_160:
          if ( v39 == 0 )
            goto LABEL_252;
          goto LABEL_280;
        }
        if ( v4 != 0 )
        {
          DbgPrint("GSIIoctl64(467):");
          DbgPrint("DeviceControl-GetPortNumber\n");
          v4 = dword_1F128;
        }
        if ( CommitSize < 0x10 )
        {
          if ( v4 == 0 )
            goto LABEL_19;
          DbgPrint("GSIIoctl64(471):");
          goto LABEL_18;
        }
        if ( v7 < 8 )
        {
          if ( v4 == 0 )
            goto LABEL_19;
          DbgPrint("GSIIoctl64(476):");
          goto LABEL_38;
        }
        v40 = sub_15D98(v3, *v5, v5[1]);
      }
      else
      {
        if ( v4 != 0 )
        {
          DbgPrint("GSIIoctl64(443):");
          DbgPrint("DeviceControl-GetDupPidHandle\n");
          v4 = dword_1F128;
        }
        if ( CommitSize < 8 )
        {
          if ( v4 == 0 )
            goto LABEL_19;
          DbgPrint("GSIIoctl64(445):");
          goto LABEL_18;
        }
        if ( v7 < 8 )
        {
          if ( v4 == 0 )
            goto LABEL_19;
          DbgPrint("GSIIoctl64(450):");
          goto LABEL_38;
        }
        v40 = sub_15CCC(*v5);
      }
      if ( v40 != 0 )
      {
        *(_DWORD *)(a2 + 48) = 0;
        *(_QWORD *)(a2 + 56) = 8;
        *v5 = v40;
        goto LABEL_288;
      }
      goto LABEL_252;
    }
    v47 = v10 - 2240668;
    if ( v47 != 0 )
    {
      v48 = v47 - 4;
      if ( v48 != 0 )
      {
        v49 = v48 - 4;
        if ( v49 != 0 )
        {
          v50 = v49 - 28;
          if ( v50 != 0 )
          {
            v51 = v50 - 4;
            if ( v51 != 0 )
            {
              if ( v51 != 4 )
                goto LABEL_252;
              if ( v4 != 0 )
              {
                DbgPrint("GSIIoctl64(590):");
                DbgPrint("DeviceControl-Get EPROCESS\n");
                v4 = dword_1F128;
              }
              if ( CommitSize < 8 )
              {
                if ( v4 != 0 )
                {
                  DbgPrint("GSIIoctl64(592):");
                  DbgPrint("Output Buffer too Small!\n");
                }
                *(_QWORD *)(a2 + 56) = 0;
                v4 = dword_1F128;
              }
              if ( v7 < 8 )
              {
                if ( v4 == 0 )
                  goto LABEL_19;
                DbgPrint("GSIIoctl64(597):");
                goto LABEL_38;
              }
              v39 = sub_18994(v3, *v5, v5);
              goto LABEL_160;
            }
            v52 = dword_1F118;
            if ( dword_1F118 != 0 )
            {
              DbgPrint("DeviceControl-ReadPhyicalMemory\n");
              v52 = dword_1F118;
            }
            if ( CommitSize < 0x14 )
            {
              if ( dword_1F11C != 0 )
                DbgPrint("Error: (GSIIoctl64) Input Buffer too Small! 0x%x\n", CommitSize);
              v9 = -1073741789;
              *(_QWORD *)(a2 + 56) = 20;
              goto LABEL_288;
            }
            CommitSize = *((unsigned int *)v5 + 4);
            if ( (__int64)v7 < (__int64)CommitSize )
            {
              if ( dword_1F11C != 0 )
                DbgPrint("Error: (GSIIoctl64) Output Buffer too Small! 0x%x\n", v7);
              v18 = *((unsigned int *)v5 + 4);
              v9 = -1073741789;
              goto LABEL_287;
            }
            v53 = (void *)*v5;
            if ( *v5 == 0 || v53 == (void *)-1LL )
            {
              DbgPrint("Error: (GSIIoctl64) PhysicalMemory never opened first.\n");
              v9 = -1073741816;
              goto LABEL_22;
            }
            v54.QuadPart = v5[1];
            MaxCount = *((unsigned int *)v5 + 4);
            BaseAddress = nullptr;
            if ( v52 != 0 )
              DbgPrint("Addr[%8I64X] Len[%8I64X]\n", v54.QuadPart, CommitSize);
            BaseAddress = nullptr;
            SectionOffset = v54;
            v55 = ZwMapViewOfSection(
                    v53,
                    (HANDLE)0xFFFFFFFFFFFFFFFFLL,
                    &BaseAddress,
                    0,
                    CommitSize,
                    &SectionOffset,
                    &MaxCount,
                    ViewShare,
                    0,
                    2u);
            v9 = v55;
            if ( v55 < 0 )
              DbgPrint(
                "Error: (MapPhysicalMemory)Could not map view of Addr 0x%I64X Length 0x%X ViewSize 0x%X. (Error 0x%x)\n",
                v54.QuadPart,
                CommitSize,
                MaxCount,
                v55);
            if ( v9 < 0 )
              goto LABEL_22;
            if ( MaxCount < CommitSize )
              CommitSize = MaxCount;
            memmove(v5, BaseAddress, CommitSize);
            v56 = ZwUnmapViewOfSection((HANDLE)0xFFFFFFFFFFFFFFFFLL, BaseAddress);
            if ( v56 < 0 )
              DbgPrint("Error: (UnmapPhysicalMemory) Unable to unmap view 0x%x\n", v56);
LABEL_240:
            *(_QWORD *)(a2 + 56) = CommitSize;
            goto LABEL_288;
          }
          if ( dword_1F118 != 0 )
            DbgPrint("DeviceControl-ClosePhysicalMemory\n");
          if ( CommitSize >= 8 )
          {
            v57 = (void *)*v5;
            if ( *v5 != 0 && v57 != (void *)-1LL )
            {
              ZwClose(v57);
              goto LABEL_22;
            }
            DbgPrint("Error: (GSIIoctl64) PhysicalMemory never opened first.\n");
            goto LABEL_252;
          }
        }
        else
        {
          if ( dword_1F118 != 0 )
            DbgPrint("DeviceControl-OpenPhysicalMemory\n");
          if ( v7 >= 8 )
          {
            MaxCount = 0;
            v9 = sub_18B44(&MaxCount);
            if ( v9 < 0 )
              goto LABEL_288;
            v32 = MaxCount;
            goto LABEL_126;
          }
        }
        if ( dword_1F11C != 0 )
          DbgPrint("Error: (GSIIoctl64) Input Buffer too Small! 0x%x\n", v7);
        v9 = -1073741789;
        *(_QWORD *)(a2 + 56) = 8;
        return (unsigned int)v9;
      }
      if ( dword_1F118 != 0 )
        DbgPrint("DeviceControl-GetPageDataList\n");
      if ( CommitSize >= 0x1C )
      {
        if ( v7 < 0x1010 )
        {
          if ( dword_1F11C != 0 )
            DbgPrint("Error: (GSIIoctl64) Output Buffer too Small! 0x%x\n", v7);
          v9 = -1073741789;
          *(_QWORD *)(a2 + 56) = 4112;
          goto LABEL_288;
        }
        PoolWithTag = ExAllocatePoolWithTag(PagedPool, CommitSize, 0x76616431u);
        v59 = PoolWithTag;
        if ( PoolWithTag != nullptr )
        {
          memmove(PoolWithTag, v5, CommitSize);
          *((_DWORD *)v5 + 1) = ((int)v7 - 8) / 0x1008u;
          v9 = sub_133F0(v59, (unsigned int *)v5);
          if ( v9 >= 0 )
            *(_QWORD *)(a2 + 56) = 4104LL * *(unsigned int *)v5 + 8;
          ExFreePoolWithTag(v59, 0x76616431u);
          goto LABEL_288;
        }
        if ( dword_1F11C != 0 )
          DbgPrint("Error: (GSIIoctl64) Insufficient Buffer \n");
        v9 = -1073741670;
        goto LABEL_240;
      }
      if ( dword_1F11C != 0 )
        DbgPrint("Error: (GSIIoctl64) Input Buffer too Small! 0x%x\n", CommitSize);
    }
    else
    {
      if ( dword_1F118 != 0 )
        DbgPrint("DeviceControl-GetVadList\n");
      if ( CommitSize < 8 )
      {
        if ( dword_1F11C != 0 )
          DbgPrint("Error: (GSIIoctl64) Input Buffer too Small! 0x%x\n", CommitSize);
        v9 = -1073741789;
        goto LABEL_280;
      }
      if ( v7 >= 0x1C )
      {
        v60 = (void *)*v5;
        *((_DWORD *)v5 + 1) = 0;
        *((_DWORD *)v5 + 2) = (unsigned int)(v7 - 12) >> 4;
        v9 = sub_15864(v60);
        if ( v9 < 0 )
          goto LABEL_288;
        v18 = 16LL * *((unsigned int *)v5 + 1) + 12;
        goto LABEL_287;
      }
      if ( dword_1F11C != 0 )
        DbgPrint("Error: (GSIIoctl64) Output Buffer too Small! 0x%x\n", v7);
    }
    v9 = -1073741789;
    *(_QWORD *)(a2 + 56) = 28;
    goto LABEL_288;
  }
  if ( v10 == 2240636 )
  {
    if ( v4 != 0 )
    {
      DbgPrint("GSIIoctl64(678):");
      DbgPrint("DeviceControl-HideProc\n");
      v4 = dword_1F128;
    }
    if ( CommitSize < 8 )
    {
      if ( v4 == 0 )
        goto LABEL_19;
      DbgPrint("GSIIoctl64(680):");
      goto LABEL_18;
    }
    v16 = sub_16A20(v3, *v5);
    goto LABEL_21;
  }
  if ( v10 > 0x223060 )
  {
    v21 = v10 - 2240612;
    if ( v21 != 0 )
    {
      v22 = v21 - 4;
      if ( v22 == 0 )
      {
        if ( v4 != 0 )
        {
          DbgPrint("GSIIoctl64(640):");
          DbgPrint("DeviceControl-PidMemory\n");
          v4 = dword_1F128;
        }
        if ( CommitSize >= 0x18 )
        {
          v30 = v5[2];
          v31 = v30 & -(__int64)((unsigned __int8)sub_16D48(v3, *v5, v5[1], v30, v5) != 0);
          v9 = 0;
          *(_QWORD *)(a2 + 56) = v31;
          goto LABEL_288;
        }
        if ( v4 == 0 )
          goto LABEL_19;
        DbgPrint("GSIIoctl64(642):");
        goto LABEL_18;
      }
      v23 = v22 - 4;
      if ( v23 != 0 )
      {
        v24 = v23 - 4;
        if ( v24 != 0 )
        {
          v25 = v24 - 4;
          if ( v25 != 0 )
          {
            if ( v25 == 4 )
            {
              if ( v4 != 0 )
              {
                DbgPrint("GSIIoctl64(691):");
                DbgPrint("DeviceControl-KillProc\n");
                v4 = dword_1F128;
              }
              if ( CommitSize >= 8 )
              {
                sub_16BA8(v3, *v5);
                goto LABEL_22;
              }
              if ( v4 == 0 )
                goto LABEL_19;
              DbgPrint("GSIIoctl64(693):");
              goto LABEL_18;
            }
            goto LABEL_252;
          }
          if ( v4 != 0 )
          {
            DbgPrint("GSIIoctl64(729):");
            DbgPrint("DeviceControl-DeleteService\n");
            v4 = dword_1F128;
          }
          if ( CommitSize == 0 )
          {
            if ( v4 == 0 )
              goto LABEL_19;
            DbgPrint("GSIIoctl64(731):");
            goto LABEL_18;
          }
          v26 = sub_18420(v3, v5);
        }
        else
        {
          if ( v4 != 0 )
          {
            DbgPrint("GSIIoctl64(713):");
            DbgPrint("DeviceControl-DeleteFile\n");
            v4 = dword_1F128;
          }
          if ( CommitSize == 0 )
          {
            if ( v4 == 0 )
              goto LABEL_19;
            DbgPrint("GSIIoctl64(715):");
            goto LABEL_18;
          }
          v26 = sub_186A0(v3, v5);
        }
        v9 = v26 == 0 ? 0xC000009A : 0;
        goto LABEL_22;
      }
      if ( v4 != 0 )
      {
        DbgPrint("GSIIoctl64(770):");
        DbgPrint("DeviceControl-DriverName\n");
      }
      memset(v5, 0, v7);
      v27 = v7 >> 9;
      v28 = sub_175E0(v3, v5, v27);
      v29 = sub_182C0(v3, 0, v5, v27, v28);
      if ( v29 != 0 )
      {
        v18 = v29 << 9;
        goto LABEL_287;
      }
LABEL_108:
      *(_QWORD *)(a2 + 56) = 0;
      v9 = -1073741670;
      goto LABEL_288;
    }
    if ( v4 != 0 )
    {
      DbgPrint("GSIIoctl64(493):");
      DbgPrint("DeviceControl-FileHandleCount\n");
      v4 = dword_1F128;
    }
    if ( CommitSize < 8 )
    {
      if ( v4 != 0 )
      {
        DbgPrint("GSIIoctl64(495):");
        DbgPrint("Output Buffer too Small!\n");
      }
      *(_QWORD *)(a2 + 56) = 0;
      v4 = dword_1F128;
    }
    if ( v7 < 8 )
    {
      if ( v4 == 0 )
        goto LABEL_19;
      DbgPrint("GSIIoctl64(500):");
      goto LABEL_38;
    }
    v32 = sub_16034(v3, *v5);
    if ( v32 == 0 )
      goto LABEL_252;
LABEL_126:
    *v5 = v32;
    goto LABEL_280;
  }
  if ( v10 != 2240608 )
  {
    v11 = v10 - 2240584;
    if ( v11 != 0 )
    {
      v12 = v11 - 4;
      if ( v12 == 0 )
      {
        if ( v4 != 0 )
        {
          DbgPrint("GSIIoctl64(399):");
          DbgPrint("DeviceControl-PidName\n");
          v4 = dword_1F128;
        }
        if ( CommitSize < 8 )
        {
          if ( v4 == 0 )
            goto LABEL_19;
          DbgPrint("GSIIoctl64(401):");
          goto LABEL_18;
        }
        if ( v7 >= 0x10 )
        {
          if ( sub_15ABC(v3, *v5, v3 + 1648902) != 0 )
          {
            *(_DWORD *)(a2 + 48) = 0;
            *(_QWORD *)(a2 + 56) = 16;
            *(__m128i *)v5 = _mm_loadu_si128((const __m128i *)(v3 + 1648902));
            goto LABEL_288;
          }
          goto LABEL_252;
        }
        if ( v4 == 0 )
          goto LABEL_19;
        DbgPrint("GSIIoctl64(406):");
LABEL_38:
        DbgPrint("Output Buffer too Small!\n");
        goto LABEL_19;
      }
      v13 = v12 - 4;
      if ( v13 == 0 )
      {
        if ( v4 != 0 )
        {
          DbgPrint("GSIIoctl64(517):");
          DbgPrint("DeviceControl-FileHandle\n");
          v4 = dword_1F128;
        }
        if ( CommitSize < 8 )
        {
          if ( v4 != 0 )
          {
            DbgPrint("GSIIoctl64(519):");
            DbgPrint("Output Buffer too Small!\n");
          }
          *(_QWORD *)(a2 + 56) = 0;
          v4 = dword_1F128;
        }
        if ( v7 < 8 )
        {
          if ( v4 == 0 )
            goto LABEL_19;
          DbgPrint("GSIIoctl64(524):");
          goto LABEL_38;
        }
        v19 = sub_1191C(v3, (void *)*v5, (char *)v5, 0, v7 >> 3);
        if ( v19 == 0 )
          goto LABEL_252;
        v18 = 8 * v19;
LABEL_287:
        *(_QWORD *)(a2 + 56) = v18;
        goto LABEL_288;
      }
      v14 = v13 - 4;
      if ( v14 != 0 )
      {
        v15 = v14 - 4;
        if ( v15 != 0 )
        {
          if ( v15 == 4 )
          {
            if ( v4 != 0 )
            {
              DbgPrint("GSIIoctl64(665):");
              DbgPrint("DeviceControl-UnhideProc\n");
              v4 = dword_1F128;
            }
            if ( CommitSize < 8 )
            {
              if ( v4 == 0 )
              {
LABEL_19:
                v9 = -1073741789;
LABEL_22:
                *(_QWORD *)(a2 + 56) = 0;
LABEL_288:
                *(_DWORD *)(a2 + 48) = v9;
                return (unsigned int)v9;
              }
              DbgPrint("GSIIoctl64(667):");
LABEL_18:
              DbgPrint("Input Buffer too Small!\n");
              goto LABEL_19;
            }
            v16 = sub_16798(v3, *v5);
LABEL_21:
            v9 = v16;
            goto LABEL_22;
          }
LABEL_252:
          v9 = -1073741811;
          goto LABEL_22;
        }
        if ( v4 != 0 )
        {
          DbgPrint("GSIIoctl64(360):");
          DbgPrint("DeviceControl-Version\n");
          v4 = dword_1F128;
        }
        if ( v7 < 8 )
        {
          if ( v4 == 0 )
            goto LABEL_19;
          DbgPrint("GSIIoctl64(362):");
          goto LABEL_18;
        }
        *v5 = 312;
LABEL_280:
        *(_QWORD *)(a2 + 56) = 8;
        goto LABEL_288;
      }
      if ( v4 != 0 )
      {
        DbgPrint("GSIIoctl64(540):");
        DbgPrint("DeviceControl-FileHandleName\n");
        v4 = dword_1F128;
      }
      if ( CommitSize < 8 )
      {
        if ( v4 != 0 )
        {
          DbgPrint("GSIIoctl64(542):");
          DbgPrint("Output Buffer too Small!\n");
        }
        *(_QWORD *)(a2 + 56) = 0;
        v4 = dword_1F128;
      }
      if ( v7 < 0x216 )
      {
        if ( v4 == 0 )
          goto LABEL_19;
        DbgPrint("GSIIoctl64(547):");
        goto LABEL_38;
      }
      v17 = sub_1191C(v3, (void *)*v5, (char *)v5, 1, v7 / 0x218);
LABEL_40:
      if ( v17 == 0 )
        goto LABEL_252;
      v18 = 534 * v17;
      goto LABEL_287;
    }
    if ( v4 != 0 )
    {
      DbgPrint("GSIIoctl64(423):");
      DbgPrint("DeviceControl-SysProcInfo Beg\n");
      v4 = dword_1F128;
    }
    if ( v7 >= 8 )
    {
      v20 = sub_11794(v3, (unsigned __int64 *)v5, v7 >> 3);
      if ( v20 != 0 )
      {
        if ( dword_1F128 != 0 )
        {
          DbgPrint("GSIIoctl64(430):");
          DbgPrint("Number of Pids [%d]\n", v20 >> 3);
        }
        *(_QWORD *)(a2 + 56) = v20;
        goto LABEL_75;
      }
      v9 = -1073741811;
    }
    else
    {
      if ( v4 != 0 )
      {
        DbgPrint("GSIIoctl64(425):");
        DbgPrint("Output Buffer too Small! [%8.8X]\n", v7);
      }
      v9 = -1073741789;
    }
    *(_QWORD *)(a2 + 56) = 0;
LABEL_75:
    *(_DWORD *)(a2 + 48) = v9;
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GSIIoctl64(439):");
      DbgPrint("DeviceControl-SysProcInfo End\n");
    }
    return (unsigned int)v9;
  }
  if ( v4 != 0 )
  {
    DbgPrint("GSIIoctl64(705):");
    DbgPrint("DeviceControl-DriverInfo\n");
  }
  *(_QWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  return (unsigned int)v9;
}


// ----- sub_14E64 @ 0x14e64 -----
__int64 __fastcall sub_14E64(__int64 a1, IRP *a2)
{
  NTSTATUS v4; // eax
  unsigned int v5; // edi
  int v6; // ecx
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rsi
  struct _IRP *MasterIrp; // rdi
  unsigned int Length; // ebp

  v4 = KeWaitForSingleObject(&Mutex, UserRequest, 0, 1u, nullptr);
  v5 = v4;
  if ( v4 < 0 )
  {
    DbgPrint("GSIIoctl KeWaitForSingleObject returned %X \n", v4);
    a2->IoStatus.Information = 0;
    goto LABEL_19;
  }
  v6 = dword_1F128;
  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GSIIoctl(995):");
    DbgPrint("IOCTL[%8.8X]!\n", (CurrentStackLocation->Parameters.Read.ByteOffset.LowPart >> 2) & 0xFFF);
    v6 = dword_1F128;
  }
  if ( (CurrentStackLocation->Parameters.Read.ByteOffset.LowPart & 0x3000) != 0x3000 )
  {
    MasterIrp = a2->AssociatedIrp.MasterIrp;
    Length = CurrentStackLocation->Parameters.Read.Length;
    if ( CurrentStackLocation->Parameters.Read.ByteOffset.LowPart == 2236504 )
    {
      if ( v6 != 0 )
      {
        DbgPrint("GSIIoctl(1010):");
        DbgPrint("DeviceControl-Version\n");
        v6 = dword_1F128;
      }
      if ( Length >= 8 )
      {
        *(_QWORD *)&MasterIrp->Type = 312;
        a2->IoStatus.Information = 8;
        v5 = 0;
        goto LABEL_17;
      }
      if ( v6 != 0 )
      {
        DbgPrint("GSIIoctl(1012):");
        DbgPrint("Input Buffer too Small!\n");
      }
      v5 = -1073741789;
    }
    else
    {
      v5 = -1073741811;
    }
    a2->IoStatus.Information = 0;
LABEL_17:
    a2->IoStatus.Status = v5;
    goto LABEL_18;
  }
  sub_13E80(a1, (__int64)a2);
LABEL_18:
  KeReleaseMutex(&Mutex, 0);
LABEL_19:
  a2->IoStatus.Status = v5;
  IofCompleteRequest(a2, 0);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GSIIoctl(1619):");
    DbgPrint("========::DeviceControl End====[%8.8X]==/\\\n", v5);
  }
  return v5;
}


// ----- sub_14FE8 @ 0x14fe8 -----
__int64 __fastcall sub_14FE8(_WORD *a1)
{
  __int64 result; // rax

  for ( result = 0; *a1 != 0; ++result )
    ++a1;
  return result;
}


// ----- sub_15004 @ 0x15004 -----
void __fastcall sub_15004(_QWORD *a1, _QWORD *a2, __int64 a3)
{
  __int64 v3; // rsi
  void *v6; // rcx
  void *v7; // rcx

  v3 = a3 + 1;
  if ( (unsigned __int64)(a3 + 1) <= 0x200 )
  {
    v6 = (void *)a1[3];
    if ( v6 != nullptr && MmIsAddressValid(v6) != 0 )
      sub_15004(a1[3], a2, v3);
    v7 = (void *)a1[4];
    if ( v7 != nullptr && MmIsAddressValid(v7) != 0 )
      sub_15004(a1[4], a2, v3);
    if ( dword_1F118 != 0 )
      DbgPrint("%8x %8x %8x %8x %8x %8x\n", (_DWORD)a1, *a1, a1[1], a1[2], a1[3], a1[4]);
    ++*a2;
  }
  else if ( dword_1F118 != 0 )
  {
    DbgPrint("About to run out kernel stack, STOP!!!\n");
  }
}


// ----- sub_150DC @ 0x150dc -----
void __fastcall sub_150DC(_QWORD *a1, _QWORD *a2, __int64 a3)
{
  __int64 v3; // rsi
  void *v6; // rcx
  void *v7; // rcx

  v3 = a3 + 1;
  if ( (unsigned __int64)(a3 + 1) <= 0x200 )
  {
    v6 = (void *)a1[1];
    if ( v6 != nullptr && MmIsAddressValid(v6) != 0 )
      sub_150DC(a1[1], a2, v3);
    v7 = (void *)a1[2];
    if ( v7 != nullptr && MmIsAddressValid(v7) != 0 )
      sub_150DC(a1[2], a2, v3);
    if ( dword_1F118 != 0 )
      DbgPrint("%8x %8x %8x %8x %8x %8x\n", (_DWORD)a1, a1[3], a1[4], *a1, a1[1], a1[2]);
    ++*a2;
  }
  else if ( dword_1F118 != 0 )
  {
    DbgPrint("About to run out kernel stack, STOP!!!\n");
  }
}


// ----- sub_151B4 @ 0x151b4 -----
void __fastcall sub_151B4(int a1, _QWORD *a2)
{
  __int64 v4; // [rsp+40h] [rbp+18h] BYREF

  v4 = 0;
  if ( dword_1F118 != 0 )
    DbgPrint("VAD      StarVpn  EndVPN   Parent   LeftChild RightChild\n");
  if ( a1 == 4 || a1 == 5 || a1 == 3 )
    sub_150DC(a2, &v4, 0);
  else
    sub_15004(a2, &v4, 0);
  if ( dword_1F118 != 0 )
    DbgPrint("\n\nNumber of VAD Entries = %d\n", v4);
}


// ----- sub_1523C @ 0x1523c -----
void __fastcall sub_1523C(_QWORD *a1, _DWORD *a2, __int64 a3)
{
  __int64 v3; // rsi
  void *v6; // rcx
  void *v7; // rcx
  __int64 v8; // rax

  v3 = a3 + 1;
  if ( (unsigned __int64)(a3 + 1) <= 0x200 )
  {
    v6 = (void *)a1[3];
    if ( v6 != nullptr && MmIsAddressValid(v6) != 0 )
      sub_1523C(a1[3], a2, v3);
    v7 = (void *)a1[4];
    if ( v7 != nullptr && MmIsAddressValid(v7) != 0 )
      sub_1523C(a1[4], a2, v3);
    v8 = (unsigned int)a2[1];
    if ( (unsigned int)v8 < a2[2] )
    {
      *(_QWORD *)&a2[4 * v8 + 3] = *a1;
      *(_QWORD *)&a2[4 * a2[1]++ + 5] = a1[1];
    }
    ++*a2;
  }
  else if ( dword_1F118 != 0 )
  {
    DbgPrint("About to run out kernel stack, STOP!!!\n");
  }
}


// ----- sub_152FC @ 0x152fc -----
void __fastcall sub_152FC(_QWORD *a1, _DWORD *a2, __int64 a3)
{
  __int64 v3; // rsi
  void *v6; // rcx
  void *v7; // rcx
  __int64 v8; // rax

  v3 = a3 + 1;
  if ( (unsigned __int64)(a3 + 1) <= 0x200 )
  {
    v6 = (void *)a1[1];
    if ( v6 != nullptr && MmIsAddressValid(v6) != 0 )
      sub_152FC(a1[1], a2, v3);
    v7 = (void *)a1[2];
    if ( v7 != nullptr && MmIsAddressValid(v7) != 0 )
      sub_152FC(a1[2], a2, v3);
    v8 = (unsigned int)a2[1];
    if ( (unsigned int)v8 < a2[2] )
    {
      *(_QWORD *)&a2[4 * v8 + 3] = a1[3];
      *(_QWORD *)&a2[4 * a2[1]++ + 5] = a1[4];
    }
    ++*a2;
  }
  else if ( dword_1F118 != 0 )
  {
    DbgPrint("About to run out kernel stack, STOP!!!\n");
  }
}


// ----- sub_153BC @ 0x153bc -----
__int64 __fastcall sub_153BC(__int64 a1, _DWORD *a2)
{
  unsigned int v2; // edi
  int v4; // ebx
  unsigned __int8 CurrentIrql; // r12
  PVOID *v6; // rsi
  _QWORD *v7; // rdx
  _QWORD *v8; // rcx
  _DWORD *v9; // rdx

  v2 = 0;
  v4 = 0;
  CurrentIrql = KeGetCurrentIrql();
  __writecr8(2u);
  switch ( qword_1F110 )
  {
    case 284LL:
      v4 = 2;
      break;
    case 404LL:
      v4 = 1;
      break;
    case 568LL:
    case 600LL:
      v4 = 3;
      break;
    case 896LL:
      v4 = 5;
      break;
    case 920LL:
      v4 = 4;
      break;
    default:
      break;
  }
  v6 = (PVOID *)(qword_1F110 + a1);
  if ( MmIsAddressValid((PVOID)(qword_1F110 + a1)) == 0 || MmIsAddressValid(*v6) == 0 || *v6 == nullptr )
  {
    v2 = -1073741823;
    goto LABEL_26;
  }
  if ( v4 == 5 || v4 == 4 )
    v7 = v6;
  else
    v7 = *v6;
  sub_151B4(v4, v7);
  *a2 = 0;
  a2[1] = 0;
  if ( v4 == 5 || v4 == 4 )
  {
    v9 = a2;
    v8 = v6;
    goto LABEL_24;
  }
  v8 = *v6;
  v9 = a2;
  if ( v4 == 3 )
  {
LABEL_24:
    sub_152FC(v8, v9, 0);
    goto LABEL_26;
  }
  sub_1523C(v8, a2, 0);
LABEL_26:
  __writecr8(CurrentIrql);
  return v2;
}


// ----- sub_154DC @ 0x154dc -----
unsigned __int64 __fastcall sub_154DC(__int64 a1, _DWORD *a2)
{
  unsigned __int64 i; // rsi
  unsigned __int64 result; // rax
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r13
  __int64 v7; // r15
  __int64 v8; // rcx
  __int64 v9; // rax
  __int64 v10; // [rsp+90h] [rbp+8h]
  __int64 v11; // [rsp+A8h] [rbp+20h]

  v10 = a1;
  for ( i = 0; ; ++i )
  {
    result = *(unsigned int *)(a1 + 4);
    if ( i >= result )
      break;
    v5 = *(_QWORD *)(a1 + 16 * i + 12);
    v6 = *(_QWORD *)(a1 + 16 * i + 20);
    if ( dword_1F11C != 0 )
      DbgPrint("\t %8I64X - %-8I64X \n", v5, v6);
    if ( v6 - v5 <= 0xFFFF )
    {
      while ( v5 <= v6 )
      {
        v11 = 0;
        ProbeForRead((volatile void *)(v5 << 12), 1u, 1u);
        v7 = v5;
        v8 = 0;
        if ( v5 == 0 )
          break;
        while ( v5 <= v6 )
        {
          ProbeForRead((volatile void *)(v5 << 12), 1u, 1u);
          v8 = v5;
          v11 = v5++;
        }
        if ( dword_1F11C != 0 )
        {
          DbgPrint("\t\t %8I64X - %-8I64X \n", v7, v8);
          v8 = v11;
        }
        v9 = (unsigned int)a2[1];
        if ( (unsigned int)v9 < a2[2] )
        {
          *(_QWORD *)&a2[4 * v9 + 3] = v7;
          *(_QWORD *)&a2[4 * a2[1]++ + 5] = v8;
        }
        ++*a2;
      }
    }
    else if ( dword_1F11C != 0 )
    {
      DbgPrint("\t\t Unexpected long range for committed lists.\n");
    }
    a1 = v10;
  }
  return result;
}


// ----- sub_1575C @ 0x1575c -----
__int64 __fastcall sub_1575C(unsigned __int64 a1, _QWORD *a2)
{
  NTSTATUS v3; // eax
  NTSTATUS InformationProcess; // ebx
  unsigned __int128 v6; // [rsp+30h] [rbp-78h] BYREF
  struct _OBJECT_ATTRIBUTES v7; // [rsp+40h] [rbp-68h] BYREF
  _DWORD ProcessInformation[14]; // [rsp+70h] [rbp-38h] BYREF
  HANDLE ProcessHandle; // [rsp+B0h] [rbp+8h] BYREF
  __int64 ReturnLength; // [rsp+B8h] [rbp+10h] BYREF

  *a2 = 0;
  ReturnLength = 0;
  ProcessHandle = (HANDLE)-1LL;
  memset(&v7.RootDirectory, 0, 20);
  v7.SecurityDescriptor = nullptr;
  v7.SecurityQualityOfService = nullptr;
  v6 = a1;
  v7.Length = 24;
  v3 = ZwOpenProcess(&ProcessHandle, 0x40u, &v7, (PCLIENT_ID)&v6);
  InformationProcess = v3;
  if ( v3 >= 0 )
  {
    memset(ProcessInformation, 0, 0x30u);
    InformationProcess = ZwQueryInformationProcess(
                           ProcessHandle,
                           ProcessBasicInformation,
                           ProcessInformation,
                           0x30u,
                           (PULONG)&ReturnLength);
    if ( InformationProcess >= 0 )
    {
      ZwClose(ProcessHandle);
      *a2 = ProcessInformation[0];
    }
    else
    {
      ZwClose(ProcessHandle);
      if ( dword_1F118 != 0 )
        DbgPrint("Error: GetProcExitStatus ZwQueryInformationProcess [%8.8X]\n", (unsigned int)InformationProcess);
    }
  }
  else if ( dword_1F118 != 0 )
  {
    DbgPrint("Error: GetProcExitStatus ZwOpenProcess [%8.8X]\n", (unsigned int)v3);
  }
  return (unsigned int)InformationProcess;
}


// ----- sub_15864 @ 0x15864 -----
__int64 __fastcall sub_15864(HANDLE ProcessId, _DWORD *a2)
{
  HANDLE v4; // rbp
  _DWORD *PoolWithTag; // rdi
  int v7; // eax
  NTSTATUS v8; // eax
  int v9; // ebx
  __int64 v10; // rbx
  _DWORD *v11; // rax
  PEPROCESS Process; // [rsp+50h] [rbp+18h] BYREF
  __int64 v13; // [rsp+58h] [rbp+20h] BYREF

  Process = nullptr;
  v13 = 0;
  v4 = nullptr;
  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x1Cu, 0x76616432u);
  if ( PoolWithTag == nullptr )
  {
    if ( dword_1F11C != 0 )
      DbgPrint("Error: (GetCommittedVadList) ExAllocatePoolWithTag1 failed.\n");
    return 3221225626LL;
  }
  v7 = sub_1575C((unsigned __int64)ProcessId, &v13);
  if ( v7 < 0 || v13 != 259 )
  {
    if ( dword_1F11C != 0 )
      DbgPrint("Warning: (GetCommittedVadList) GetProcExitStatus (%X) or exitcode (%X).\n", v7, v13);
    goto LABEL_22;
  }
  PoolWithTag[1] = 0;
  PoolWithTag[2] = 1;
  v8 = PsLookupProcessByProcessId(ProcessId, &Process);
  if ( v8 < 0 )
  {
    if ( dword_1F11C != 0 )
      DbgPrint("Error: (GetCommittedVadList) PsLookupProcessByProcessId failed 0x%x\n", v8);
LABEL_22:
    v9 = -1073741584;
    goto LABEL_23;
  }
  v4 = *(HANDLE *)((char *)IoGetCurrentProcess() + qword_1F130);
  if ( v4 != ProcessId )
    KeAttachProcess(Process);
  v9 = sub_153BC((__int64)Process, PoolWithTag);
  if ( v9 < 0 )
    goto LABEL_23;
  if ( *PoolWithTag <= 1u )
    goto LABEL_19;
  v10 = (unsigned int)(*PoolWithTag + 48);
  ExFreePoolWithTag(PoolWithTag, 0x76616432u);
  v11 = ExAllocatePoolWithTag(NonPagedPool, 16 * v10 + 12, 0x76616432u);
  PoolWithTag = v11;
  if ( v11 == nullptr )
  {
    if ( dword_1F11C != 0 )
      DbgPrint("Error: (GetCommittedVadList) ExAllocatePoolWithTag2 failed.\n");
    v9 = -1073741670;
    goto LABEL_23;
  }
  v11[1] = 0;
  v11[2] = v10;
  v9 = sub_153BC((__int64)Process, v11);
  if ( v9 >= 0 )
  {
LABEL_19:
    sub_154DC((__int64)PoolWithTag, a2);
    v9 = 0;
  }
LABEL_23:
  if ( v4 != ProcessId && Process != nullptr )
    KeDetachProcess();
  if ( PoolWithTag != nullptr )
    ExFreePoolWithTag(PoolWithTag, 0x76616432u);
  return (unsigned int)v9;
}


// ----- sub_15A34 @ 0x15a34 -----
char __fastcall sub_15A34(char *VirtualAddress, __int64 a2)
{
  int v2; // edi
  unsigned __int64 v4; // rsi
  unsigned __int64 v6; // rdi

  v2 = a2;
  v4 = (unsigned __int64)(a2 + 7) >> 3;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("MmIsAddressRangeValid(832):");
    DbgPrint("MmIsAddressRangeValid Addr[%8.8X] Size[%8.8X]\n", (_DWORD)VirtualAddress, v2);
  }
  if ( VirtualAddress == nullptr )
    return 0;
  v6 = 0;
  if ( v4 != 0 )
  {
    while ( MmIsAddressValid(VirtualAddress) != 0 )
    {
      ++v6;
      VirtualAddress += 8;
      if ( v6 >= v4 )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ----- sub_15ABC @ 0x15abc -----
__int64 __fastcall sub_15ABC(__int64 a1, void *a2, __m128i *a3)
{
  __int64 result; // rax
  void *v6; // r13
  NTSTATUS v7; // r12d
  void **v8; // r12
  const __m128i *v9; // r12
  __int64 v10; // rsi
  _QWORD v11[6]; // [rsp+28h] [rbp-30h] BYREF
  PEPROCESS Process; // [rsp+78h] [rbp+20h] BYREF

  v11[0] = 0;
  result = 0;
  a3->m128i_i64[0] = 0;
  a3->m128i_i64[1] = 0;
  if ( qword_1F130 == 0 || qword_1F120 == 0 )
    return result;
  v6 = *(void **)((char *)IoGetCurrentProcess() + qword_1F130);
  v11[1] = v6;
  if ( v6 == a2 )
  {
    v7 = 0;
    Process = IoGetCurrentProcess();
  }
  else
  {
    v7 = PsLookupProcessByProcessId(a2, &Process);
  }
  if ( v7 < 0 )
    return 0;
  if ( a3 == nullptr )
    return 1;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetPidName(871):");
    DbgPrint("PID[%8.8I64X] eProcess[%8.8I64X]\n", a2, Process);
  }
  v8 = (void **)((char *)Process + qword_1F130);
  if ( MmIsAddressValid((char *)Process + qword_1F130) == 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetPidName(878):");
      DbgPrint("Not a valid Address!!!\n");
    }
    return 0;
  }
  if ( *v8 != a2 )
    return 0;
  v9 = (const __m128i *)((char *)Process + qword_1F138);
  if ( MmIsAddressValid((char *)Process + qword_1F138) == 0 )
  {
    a3->m128i_i64[0] = 0;
    a3->m128i_i64[1] = 0;
    return 0;
  }
  *a3 = _mm_loadu_si128(v9);
  if ( v6 == a2 )
    return 1;
  if ( (int)sub_1575C((unsigned __int64)a2, v11) >= 0 )
  {
    v10 = v11[0];
    if ( v11[0] != 259 )
      goto LABEL_23;
    return 1;
  }
  v10 = v11[0];
LABEL_23:
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetPidName(913):");
    DbgPrint("PID[%8.8I64X] is not in Normal State[%8.8I64X]\n", a2, v10);
  }
  return 0;
}


// ----- sub_15CCC @ 0x15ccc -----
void *__fastcall sub_15CCC(void *a1)
{
  struct _CLIENT_ID ClientId; // [rsp+20h] [rbp-48h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+30h] [rbp-38h] BYREF
  void *ProcessHandle; // [rsp+70h] [rbp+8h] BYREF

  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetDupPidHandle(937):");
    DbgPrint("GetDupPidHandle - Pid[%8.8X]\n", (_DWORD)a1);
  }
  if ( *(void **)((char *)IoGetCurrentProcess() + qword_1F130) == a1 )
    return nullptr;
  ClientId.UniqueThread = nullptr;
  memset(&ObjectAttributes.RootDirectory, 0, 20);
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ClientId.UniqueProcess = a1;
  ObjectAttributes.Length = 24;
  if ( ZwOpenProcess(&ProcessHandle, 0x40u, &ObjectAttributes, &ClientId) < 0 )
    return nullptr;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetDupPidHandle(957):");
    DbgPrint("GetDupPidHandle - Pid[%8.8X] Handle[%d]\n", (_DWORD)a1, (_DWORD)ProcessHandle);
  }
  return ProcessHandle;
}


// ----- sub_15D98 @ 0x15d98 -----
__int64 __fastcall sub_15D98(__int64 a1, __int64 a2, void *a3)
{
  unsigned __int16 v5; // bx
  NTSTATUS v6; // eax
  int v7; // ecx
  int v8; // ebp
  const CHAR *v9; // rcx
  NTSTATUS v10; // eax
  int v11; // ecx
  int v12; // ebp
  PIO_STATUS_BLOCK IoStatusBlock; // [rsp+20h] [rbp-C8h]
  struct _KEVENT Event; // [rsp+50h] [rbp-98h] BYREF
  _DWORD OutputBuffer[14]; // [rsp+68h] [rbp-80h] BYREF
  _DWORD InputBuffer[12]; // [rsp+A0h] [rbp-48h] BYREF
  struct _IO_STATUS_BLOCK v18; // [rsp+D0h] [rbp-18h] BYREF

  memset(OutputBuffer, 0, sizeof(OutputBuffer));
  InputBuffer[0] = 0;
  memset(&InputBuffer[2], 0, 0x28u);
  v5 = 0;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetPortNumber(983):");
    DbgPrint("GetPortNumber Beg Pid[%8.8X] pH[%4.4X]\n", a2, (_DWORD)a3);
  }
  KeInitializeEvent(&Event, NotificationEvent, 0);
  InputBuffer[8] = 3;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetPortNumber(988):");
    DbgPrint("ZwDeviceIoControlFile1 Beg\n");
  }
  v6 = ZwDeviceIoControlFile(a3, &Event, nullptr, nullptr, &v18, 0x210012u, InputBuffer, 0x30u, OutputBuffer, 0x38u);
  v7 = dword_1F128;
  v8 = v6;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetPortNumber(999):");
    DbgPrint("ZwDeviceIoControlFile1 End[%8.8X]\n", v8);
    v7 = dword_1F128;
  }
  if ( v8 < 0 )
  {
    KeInitializeEvent(&Event, NotificationEvent, 0);
    InputBuffer[8] = 4;
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetPortNumber(1009):");
      DbgPrint("ZwDeviceIoControlFile2 Beg\n");
    }
    v10 = ZwDeviceIoControlFile(a3, &Event, nullptr, nullptr, &v18, 0x210012u, InputBuffer, 0x30u, OutputBuffer, 0x38u);
    v11 = dword_1F128;
    v12 = v10;
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetPortNumber(1016):");
      DbgPrint("ZwDeviceIoControlFile2 End[%8.8X]\n", v12);
      v11 = dword_1F128;
    }
    if ( v12 < 0 )
    {
      if ( v11 != 0 )
      {
        DbgPrint("GetPortNumber(1022):");
        DbgPrint("Pid2[%8.8Xh] Handle[%8.8X] Failed!!!\n", a2, (_DWORD)a3);
      }
    }
    else
    {
      v5 = __ROL2__(OutputBuffer[3], 8);
      if ( v11 != 0 )
      {
        DbgPrint("GetPortNumber(1019):");
        v9 = "Pid2[%8.8Xh] Handle[%8.8Xh] Port[%4d] State[%d]\n";
        goto LABEL_17;
      }
    }
  }
  else
  {
    v5 = __ROL2__(OutputBuffer[3], 8);
    if ( v7 != 0 )
    {
      DbgPrint("GetPortNumber(1003):");
      v9 = "Pid1[%8.8Xh] Handle[%8.8Xh] Port[%4d] State[%d]\n";
LABEL_17:
      LODWORD(IoStatusBlock) = OutputBuffer[0];
      DbgPrint(v9, a2, a3, v5, IoStatusBlock);
    }
  }
  return v5;
}


// ----- sub_16034 @ 0x16034 -----
__int64 __fastcall sub_16034(__int64 a1, struct _KPROCESS *a2)
{
  __int64 v3; // r13
  struct _KPROCESS *v4; // r14
  NTSTATUS v6; // esi
  unsigned __int64 v7; // r12
  NTSTATUS Object; // esi
  PVOID *v9; // rcx
  PVOID v10; // rcx
  __int64 v11; // rcx
  PVOID *v12; // rsi
  PVOID VirtualAddress; // [rsp+30h] [rbp-178h] BYREF
  __int64 i; // [rsp+38h] [rbp-170h] BYREF
  int v15; // [rsp+40h] [rbp-168h]
  __int64 v16; // [rsp+48h] [rbp-160h]
  PEPROCESS Process[3]; // [rsp+50h] [rbp-158h] BYREF
  __int64 v18; // [rsp+68h] [rbp-140h]
  _BYTE ObjectInformation[256]; // [rsp+70h] [rbp-138h] BYREF

  v18 = a1;
  Process[2] = a2;
  v3 = 0;
  v16 = 0;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetFileHandlesCount2(1044):");
    DbgPrint("GetFilehandlesCount2- Pid[%8.8X]\n", (_DWORD)a2);
  }
  v4 = *(struct _KPROCESS **)((char *)IoGetCurrentProcess() + qword_1F130);
  Process[1] = v4;
  if ( v4 != a2 && ((int)sub_1575C((unsigned __int64)a2, &i) < 0 || i != 259) )
    return 0;
  if ( v4 == a2 )
  {
    v6 = 0;
    Process[0] = IoGetCurrentProcess();
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetFileHandlesCount2(1059):");
      DbgPrint(
        "GetFileHandlesCount2==PID[%8.8X] eProcess[%8.8X] is Current Process==========\n",
        (_DWORD)a2,
        LODWORD(Process[0]));
    }
  }
  else
  {
    v6 = PsLookupProcessByProcessId(a2, Process);
  }
  if ( v6 >= 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetFileHandlesCount2(1066):");
      DbgPrint("PID[%8.8X] eProcess[%8.8X]\n", (_DWORD)a2, LODWORD(Process[0]));
    }
    if ( v4 != a2 )
    {
      KeAttachProcess(Process[0]);
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetFileHandlesCount2(1069):");
        DbgPrint("Attached to PID[%8.8X] Process!\n", (_DWORD)a2);
      }
    }
    v7 = 4;
    for ( i = 4; ; i = v7 )
    {
      if ( v7 >= 0x1000 )
      {
        if ( v4 != a2 )
        {
          KeDetachProcess();
          if ( dword_1F128 != 0 )
          {
            DbgPrint("GetFileHandlesCount2(1178):");
            DbgPrint("Detached from PID[%8.8X] Process!\n", (_DWORD)a2);
          }
        }
        goto LABEL_84;
      }
      memset((void *)(v18 + 1646774), 0, 0x20Cu);
      Object = 0;
      if ( v4 == a2 )
      {
        Object = ZwQueryObject((HANDLE)v7, ObjectBasicInformation, ObjectInformation, 0x100u, nullptr);
        if ( Object != -1073741816 )
          Object = 0;
      }
      if ( Object >= 0 )
        Object = qword_1F560(v7, 0, IoFileObjectType, 0, &VirtualAddress, 0);
      if ( Object >= 0 )
      {
        if ( MmIsAddressValid(VirtualAddress) != 0 )
        {
          if ( *((__int16 *)VirtualAddress + 1) >= 40 )
            goto LABEL_30;
          if ( dword_1F128 != 0 )
          {
            DbgPrint("GetFileHandlesCount2(1096):");
            DbgPrint(
              "fileObj Type [%d] Size[%d]<[%d]\n",
              *(__int16 *)VirtualAddress,
              *((__int16 *)VirtualAddress + 1),
              216);
          }
        }
        ObfDereferenceObject(VirtualAddress);
        Object = -1073741816;
        v15 = -1073741816;
      }
LABEL_30:
      if ( Object < 0 )
        goto LABEL_78;
      if ( MmIsAddressValid(VirtualAddress) == 0 || MmIsAddressValid(*((PVOID *)VirtualAddress + 1)) == 0 )
        goto LABEL_77;
      if ( MmIsAddressValid(*((PVOID *)VirtualAddress + 1)) == 0
        || MmIsAddressValid((char *)VirtualAddress + 88) == 0
        || MmIsAddressValid((char *)VirtualAddress + 88) == 0 )
      {
LABEL_51:
        v9 = (PVOID *)VirtualAddress;
LABEL_52:
        if ( MmIsAddressValid(v9[1]) == 0
          || MmIsAddressValid((char *)VirtualAddress + 88) == 0
          || MmIsAddressValid((char *)VirtualAddress + 88) == 0 )
        {
LABEL_75:
          v10 = VirtualAddress;
LABEL_76:
          ObfDereferenceObject(v10);
          goto LABEL_78;
        }
        v10 = VirtualAddress;
        if ( *((_WORD *)VirtualAddress + 44) != 0 || *((_QWORD *)VirtualAddress + 12) != 0 )
          goto LABEL_76;
        if ( MmIsAddressValid(VirtualAddress) == 0 )
          goto LABEL_75;
        v10 = VirtualAddress;
        if ( *(_WORD *)VirtualAddress != 5 )
          goto LABEL_76;
        if ( MmIsAddressValid((char *)VirtualAddress + 2) == 0 )
          goto LABEL_75;
        v10 = VirtualAddress;
        if ( *((_WORD *)VirtualAddress + 1) == 0 )
          goto LABEL_76;
        if ( MmIsAddressValid(*(PVOID *)(*((_QWORD *)VirtualAddress + 1) + 8LL)) != 0 )
        {
          v11 = *(_QWORD *)(*((_QWORD *)VirtualAddress + 1) + 8LL);
          if ( (v11 & 0xFFFFF00000000000uLL) != 0 )
          {
            v12 = MmIsAddressValid((PVOID)(v11 + 56)) != 0
                ? (PVOID *)(*(_QWORD *)(*((_QWORD *)VirtualAddress + 1) + 8LL) + 56LL)
                : nullptr;
            if ( v12 != nullptr
              && MmIsAddressValid(v12) != 0
              && MmIsAddressValid(v12) != 0
              && *(_WORD *)v12 != 0
              && *(_WORD *)v12 < 0x106u
              && (*(_BYTE *)v12 & 1) == 0
              && MmIsAddressValid(v12[1]) != 0 )
            {
              v16 = ++v3;
            }
          }
        }
LABEL_77:
        ObfDereferenceObject(VirtualAddress);
        goto LABEL_78;
      }
      v9 = (PVOID *)VirtualAddress;
      if ( *((_WORD *)VirtualAddress + 44) == 0
        || *((_WORD *)VirtualAddress + 44) >= 0x106u
        || (*((_BYTE *)VirtualAddress + 88) & 1) != 0 )
      {
        goto LABEL_52;
      }
      if ( MmIsAddressValid(*((PVOID *)VirtualAddress + 12)) == 0 )
        goto LABEL_51;
      v9 = (PVOID *)VirtualAddress;
      if ( (*((_QWORD *)VirtualAddress + 12) & 0xFFFFF00000000000uLL) == 0 )
        goto LABEL_52;
      if ( MmIsAddressValid(VirtualAddress) == 0 )
        goto LABEL_51;
      v9 = (PVOID *)VirtualAddress;
      if ( *(_WORD *)VirtualAddress != 5 )
        goto LABEL_52;
      if ( MmIsAddressValid((char *)VirtualAddress + 2) == 0 )
        goto LABEL_51;
      v9 = (PVOID *)VirtualAddress;
      if ( *((_WORD *)VirtualAddress + 1) == 0 )
        goto LABEL_52;
      if ( MmIsAddressValid(*((PVOID *)VirtualAddress + 2)) != 0 )
      {
        if ( dword_1F128 != 0 )
        {
          DbgPrint("GetFileHandlesCount2(1130):");
          DbgPrint(
            "File Handle[%8.8X]-Flags[%8.8X]Len[%d][%.128ws]\n",
            v7,
            *((unsigned int *)VirtualAddress + 20),
            *((unsigned __int16 *)VirtualAddress + 44),
            *((_QWORD *)VirtualAddress + 12));
        }
      }
      else if ( dword_1F128 != 0 )
      {
        DbgPrint("GetFileHandlesCount2(1134):");
        DbgPrint(
          "File Handle[%8.8X]-Flags[%8.8X] Len[%d][%.128ws]\n",
          v7,
          *((unsigned int *)VirtualAddress + 20),
          *((unsigned __int16 *)VirtualAddress + 44),
          *((_QWORD *)VirtualAddress + 12));
      }
      v16 = ++v3;
      ObfDereferenceObject(VirtualAddress);
LABEL_78:
      v7 += 4LL;
    }
  }
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetFileHandlesCount2(1182):");
    DbgPrint("PsLookupProcessByProcessId Failed[%8.8X]!\n", v6);
  }
LABEL_84:
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetFileHandlesCount2(1184):");
    DbgPrint("Total Handle[%d]\n", v3);
  }
  return v3;
}


// ----- sub_166CC @ 0x166cc -----
char __fastcall sub_166CC(__int64 a1)
{
  int v1; // edi
  PEPROCESS CurrentProcess; // rax
  __int64 v4; // rbp
  PEPROCESS v5; // rbx
  __int64 v6; // rax
  bool i; // zf
  _QWORD *v8; // rbx

  v1 = 0;
  if ( qword_1F130 == 0 || qword_1F120 == 0 )
    return 0;
  CurrentProcess = IoGetCurrentProcess();
  v4 = *(_QWORD *)((char *)CurrentProcess + qword_1F130);
  v5 = CurrentProcess;
  v6 = v4;
  for ( i = a1 == v4; !i; i = a1 == v6 )
  {
    if ( v1 >= 1 && v4 == v6 )
      return 0;
    v8 = (_QWORD *)((char *)v5 + qword_1F120);
    if ( MmIsAddressValid(v8) == 0 )
      return 0;
    v5 = (PEPROCESS)(*v8 - qword_1F120);
    if ( MmIsAddressValid(v5) == 0 || MmIsAddressValid((char *)v5 + qword_1F130) == 0 )
      return 0;
    ++v1;
    v6 = *(int *)((char *)v5 + qword_1F130);
  }
  return 1;
}


// ----- sub_16798 @ 0x16798 -----
__int64 __fastcall sub_16798(__int64 a1, void *a2)
{
  NTSTATUS v5; // edi
  PEPROCESS CurrentProcess; // rbp
  unsigned __int8 CurrentIrql; // si
  char *v8; // rbp
  _QWORD *v9; // r12
  PEPROCESS Process; // [rsp+50h] [rbp+18h] BYREF

  if ( qword_1F130 == 0 || qword_1F120 == 0 )
    return 3221225473LL;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("UnhideProc(1237):");
    DbgPrint("UnhideProc Beg-devExt[%8.8X] Pid[%8.8X]\n", a1, (_DWORD)a2);
  }
  if ( a2 != (void *)-1LL && sub_166CC((__int64)a2) != 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("UnhideProc(1239):");
      DbgPrint("UnhideProc End- In ProcList already\n");
    }
    return 3221225473LL;
  }
  v5 = 0;
  if ( a2 == (void *)-1LL )
  {
    CurrentProcess = *(PEPROCESS *)(a1 + 1648920);
    Process = IoGetCurrentProcess();
  }
  else
  {
    CurrentProcess = IoGetCurrentProcess();
    v5 = PsLookupProcessByProcessId(a2, &Process);
    if ( v5 < 0 )
    {
      if ( dword_1F128 != 0 )
      {
        DbgPrint("UnhideProc(1254):");
        DbgPrint("UnhideProc End- Invalid PID\n");
      }
      return 3221225473LL;
    }
  }
  if ( dword_1F128 != 0 )
  {
    DbgPrint("UnhideProc(1258):");
    DbgPrint("PID[%8.8X] eProcess[%8.8X] Sts[%8.8X]\n", (_DWORD)a2, (_DWORD)Process, v5);
  }
  if ( a2 == (void *)-1LL )
  {
    CurrentIrql = (unsigned __int8)Process;
  }
  else
  {
    KeAttachProcess(*(PRKPROCESS *)(a1 + 1648920));
    if ( dword_1F128 != 0 )
    {
      DbgPrint("UnhideProc(1262):");
      DbgPrint("Attached to PID[%8.8X] Process!\n", (_DWORD)a2);
    }
    CurrentIrql = KeGetCurrentIrql();
    __writecr8(2u);
  }
  v8 = (char *)CurrentProcess + qword_1F120;
  v9 = (_QWORD *)((char *)Process + qword_1F120);
  if ( MmIsAddressValid(v8) == 0 )
  {
    if ( a2 != (void *)-1LL )
    {
      __writecr8(CurrentIrql);
      KeDetachProcess();
      if ( dword_1F128 == 0 )
        return 3221225473LL;
      DbgPrint("UnhideProc(1278):");
      DbgPrint("Detached from PID[%8.8X] Process!\n", (_DWORD)a2);
    }
    if ( dword_1F128 != 0 )
    {
      DbgPrint("UnhideProc(1280):");
      DbgPrint("UnhideProc End-Failed!\n");
    }
    return 3221225473LL;
  }
  *v9 = *(_QWORD *)v8;
  v9[1] = *(_QWORD *)(*(_QWORD *)v8 + 8LL);
  *(_QWORD *)(*(_QWORD *)v8 + 8LL) = v9;
  *(_QWORD *)v8 = v9;
  if ( a2 == (void *)-1LL )
    goto LABEL_31;
  __writecr8(CurrentIrql);
  KeDetachProcess();
  if ( dword_1F128 != 0 )
  {
    DbgPrint("UnhideProc(1291):");
    DbgPrint("Detached from PID[%8.8X] Process!\n", (_DWORD)a2);
LABEL_31:
    if ( dword_1F128 != 0 )
    {
      DbgPrint("UnhideProc(1293):");
      DbgPrint("UnhideProc End-[%8.8X]\n", v5);
    }
  }
  return (unsigned int)v5;
}


// ----- sub_16A20 @ 0x16a20 -----
__int64 __fastcall sub_16A20(int a1, void *a2)
{
  NTSTATUS v5; // edi
  _QWORD **v6; // rbx
  PEPROCESS Process; // [rsp+40h] [rbp+18h] BYREF

  if ( dword_1F128 != 0 )
  {
    DbgPrint("HideProc(1305):");
    DbgPrint("HideProc Beg-devExt[%8.8X] Pid[%8.8X]\n", a1, (_DWORD)a2);
  }
  if ( qword_1F130 == 0 || qword_1F120 == 0 )
    return 3221225473LL;
  if ( a2 != (void *)-1LL && sub_166CC((__int64)a2) == 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("HideProc(1311):");
      DbgPrint("HideProc End- Not In ProcList yet!\n");
    }
    return 3221225473LL;
  }
  v5 = 0;
  if ( a2 == (void *)-1LL )
  {
    Process = IoGetCurrentProcess();
  }
  else
  {
    v5 = PsLookupProcessByProcessId(a2, &Process);
    if ( v5 < 0 )
    {
      if ( dword_1F128 != 0 )
      {
        DbgPrint("HideProc(1322):");
        DbgPrint("HideProc End- Invalid PID\n");
      }
      return 3221225473LL;
    }
  }
  if ( dword_1F128 != 0 )
  {
    DbgPrint("HideProc(1325):");
    DbgPrint("PID[%8.8X] eProcess[%8.8X] Sts[%8.8X]\n", (_DWORD)a2, (_DWORD)Process, v5);
  }
  v6 = (_QWORD **)((char *)Process + qword_1F120);
  if ( MmIsAddressValid((char *)Process + qword_1F120) == 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("HideProc(1332):");
      DbgPrint("HideProc End-Failed!\n");
    }
    return 3221225473LL;
  }
  *v6[1] = *v6;
  (*v6)[1] = v6[1];
  if ( dword_1F128 != 0 )
  {
    DbgPrint("HideProc(1339):");
    DbgPrint("HideProc End-[%8.8X]\n", v5);
  }
  return (unsigned int)v5;
}


// ----- sub_16BA8 @ 0x16ba8 -----
__int64 __fastcall sub_16BA8(__int64 a1, void *a2)
{
  NTSTATUS v4; // edi
  struct _CLIENT_ID ClientId; // [rsp+20h] [rbp-48h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+30h] [rbp-38h] BYREF
  void *ProcessHandle; // [rsp+70h] [rbp+8h] BYREF

  if ( dword_1F128 != 0 )
  {
    DbgPrint("KillProc(1351):");
    DbgPrint("KillProc Beg-devExt[%8.8X] Pid[%8.8X]\n", a1, (_DWORD)a2);
  }
  KeAttachProcess(*(PRKPROCESS *)(a1 + 1648920));
  if ( dword_1F128 != 0 )
  {
    DbgPrint("KillProc(1353):");
    DbgPrint("Attached to PID[%8.8X] Process!\n", (_DWORD)a2);
  }
  ClientId.UniqueProcess = a2;
  ClientId.UniqueThread = nullptr;
  ObjectAttributes.Length = 24;
  memset(&ObjectAttributes.RootDirectory, 0, 20);
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v4 = ZwOpenProcess(&ProcessHandle, 0x40u, &ObjectAttributes, &ClientId);
  if ( v4 < 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("KillProc(1374):");
      DbgPrint("OpenProcess Failed on Pid[%8.8X]\n", (_DWORD)a2);
    }
  }
  else
  {
    v4 = ZwTerminateProcess(ProcessHandle, 0);
    if ( v4 < 0 )
    {
      if ( dword_1F128 != 0 )
      {
        DbgPrint("KillProc(1369):");
        DbgPrint("TerminateProcess Failed on Pid[%8.8X]\n", a2);
      }
    }
    else if ( dword_1F128 != 0 )
    {
      DbgPrint("KillProc(1366):");
      DbgPrint("TerminateProcess OK on Pid[%8.8X]\n", a2);
    }
    ZwClose(ProcessHandle);
  }
  KeDetachProcess();
  if ( dword_1F128 != 0 )
  {
    DbgPrint("KillProc(1377):");
    DbgPrint("Detached from PID[%8.8X] Process!\n", (_DWORD)a2);
    if ( dword_1F128 != 0 )
    {
      DbgPrint("KillProc(1379):");
      DbgPrint("KillProc End-[%8.8X]\n", v4);
    }
  }
  return (unsigned int)v4;
}


// ----- sub_16D48 @ 0x16d48 -----
char __fastcall sub_16D48(__int64 a1, struct _KPROCESS *a2, void *a3, size_t a4, void *Dst)
{
  char v8; // si
  struct _KPROCESS *v9; // r12
  NTSTATUS v10; // r13d
  PEPROCESS Process[8]; // [rsp+28h] [rbp-40h] BYREF

  v8 = 0;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetPidMemory(1393):");
    DbgPrint("GetPidMemory Beg\n");
  }
  v9 = *(struct _KPROCESS **)((char *)IoGetCurrentProcess() + qword_1F130);
  Process[1] = v9;
  if ( v9 == a2 )
  {
    v10 = 0;
    Process[0] = IoGetCurrentProcess();
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetPidMemory(1402):");
      DbgPrint(
        "GetPidMemory==PID[%8.8X] eProcess[%8.8X] is Current Process==========\n",
        (_DWORD)a2,
        LODWORD(Process[0]));
    }
  }
  else
  {
    v10 = PsLookupProcessByProcessId(a2, Process);
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetPidMemory(1406):");
      DbgPrint(
        "GetPidMemory==PID[%8.8X] eProcess[%8.8X] ntStatus[%8.8X]is Current Process==========\n",
        (_DWORD)a2,
        LODWORD(Process[0]),
        v10);
    }
  }
  if ( v10 >= 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetPidMemory(1410):");
      DbgPrint("PID[%8.8X] eProcess[%8.8X]\n", (_DWORD)a2, LODWORD(Process[0]));
    }
    if ( v9 != a2 )
    {
      KeAttachProcess(Process[0]);
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetPidMemory(1413):");
        DbgPrint("Attached to PID[%8.8X] Process!\n", (_DWORD)a2);
      }
    }
    if ( sub_15A34((char *)a3, a4) != 0 )
    {
      memmove(Dst, a3, a4);
      v8 = 1;
    }
    else if ( dword_1F128 != 0 )
    {
      DbgPrint("GetPidMemory(1425):");
      DbgPrint("ProcMemory[%8.8X] is Invalid!\n", (_DWORD)a3);
    }
    if ( v9 != a2 )
    {
      KeDetachProcess();
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetPidMemory(1429):");
        DbgPrint("Detached from PID[%8.8X] Process!\n", (_DWORD)a2);
      }
    }
  }
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetPidMemory(1432):");
    DbgPrint("GetPidMemory End\n");
  }
  return v8;
}


// ----- sub_16FA8 @ 0x16fa8 -----
bool __fastcall sub_16FA8(void *Source1)
{
  return RtlCompareMemory(Source1, "Win32k", 6u) != 6
      && RtlCompareMemory(Source1, "PnpManager", 0xAu) != 10
      && RtlCompareMemory(Source1, "ACPI_HAL", 8u) != 8
      && RtlCompareMemory(Source1, "WMIxWDM", 7u) != 7
      && RtlCompareMemory(Source1, qword_1CC30, 3u) != 3;
}


// ----- sub_1704C @ 0x1704c -----
__int64 __fastcall sub_1704C(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rbp
  __int64 v6; // rbx
  __int64 v7; // rsi
  unsigned __int64 v8; // r12
  HANDLE *v9; // rdi
  _QWORD *v10; // r13
  __int64 v11; // rdi
  __int64 v12; // rax
  _BYTE *v13; // rcx
  char *v14; // r8
  unsigned __int64 i; // rdx
  char v16; // al
  __int64 v17; // rax
  int v18; // ebx
  __int64 j; // rax
  __int64 v20; // r11
  _WORD *v21; // r8
  __int64 v22; // r9
  unsigned __int8 *v23; // rcx
  __int16 v24; // ax
  _BYTE *v25; // rbx
  PWSTR Buffer; // rcx
  unsigned __int64 v27; // r11
  unsigned __int64 v28; // rdx
  char v29; // al
  __int64 v30; // rdx
  PWSTR v31; // r8
  unsigned __int64 v32; // r11
  _BYTE *v33; // rcx
  unsigned __int64 v34; // r9
  char v35; // al
  char *v36; // rbp
  __int64 v38; // [rsp+30h] [rbp-298h]
  UNICODE_STRING Source; // [rsp+38h] [rbp-290h] BYREF
  struct _UNICODE_STRING Destination; // [rsp+48h] [rbp-280h] BYREF
  void *KeyHandle; // [rsp+58h] [rbp-270h] BYREF
  void *Dst; // [rsp+60h] [rbp-268h]
  PVOID Object; // [rsp+68h] [rbp-260h] BYREF
  HANDLE *v44; // [rsp+70h] [rbp-258h]
  __int64 v45; // [rsp+78h] [rbp-250h]
  struct _OBJECT_ATTRIBUTES v46; // [rsp+80h] [rbp-248h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+B0h] [rbp-218h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+E0h] [rbp-1E8h] BYREF
  UNICODE_STRING v49; // [rsp+F0h] [rbp-1D8h] BYREF
  UNICODE_STRING String1; // [rsp+100h] [rbp-1C8h] BYREF
  WCHAR SourceString[56]; // [rsp+110h] [rbp-1B8h] BYREF
  _BYTE v52[256]; // [rsp+180h] [rbp-148h] BYREF

  v4 = a2;
  v45 = a2;
  v6 = a4;
  v7 = a4;
  v38 = a4;
  RtlInitUnicodeString(&DestinationString, &qword_1A8D0);
  v8 = 0;
  v9 = (HANDLE *)(a1 + 1648928);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v44 = (HANDLE *)(a1 + 1648928);
  if ( ZwOpenDirectoryObject((PHANDLE)(a1 + 1648928), 1u, &ObjectAttributes) != 0 )
    return v7;
  if ( (unsigned int)qword_1F560(*v9, 0, IoFileObjectType, 0, &Object, 0) != 0 )
    goto LABEL_45;
  RtlInitUnicodeString(&String1, L"Device");
  do
  {
    v10 = (char *)Object + 8 * v8;
    if ( *v10 == 0 )
      goto LABEL_41;
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetObjDeviceInfo(1616):");
      DbgPrint("HashBucket[%02X]\n", v8);
    }
    Dst = (void *)((v7 << 9) + v4 + 256);
    do
    {
      v10 = (_QWORD *)*v10;
      v11 = v10[1];
      if ( RtlCompareUnicodeString(&String1, (PCUNICODE_STRING)(*(_QWORD *)(v11 - 32) + 120LL), 0) != 0 )
        continue;
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetObjDeviceInfo(1632):");
        DbgPrint("Object[%08X] ", v11);
        if ( dword_1F128 != 0 )
        {
          DbgPrint("GetObjDeviceInfo(1633):");
          DbgPrint("Name[%wZ]\n", v11 - 72);
        }
      }
      memset(v52, 0, sizeof(v52));
      v12 = *(_QWORD *)(v11 + 8);
      v13 = v52;
      v14 = *(char **)(v12 + 64);
      for ( i = (unsigned __int64)*(unsigned __int16 *)(v12 + 56) >> 1; i != 0; --i )
      {
        v16 = *v14;
        v14 += 2;
        *v13++ = v16;
      }
      v17 = *(_QWORD *)(v11 + 8);
      *v13 = 0;
      v18 = (*(unsigned __int16 *)(v17 + 56) >> 1) - 1;
      for ( j = v18; j > 0 && v52[j] != 92; --j )
        --v18;
      if ( v18 > 0 )
        ++v18;
      memset((void *)(a1 + 1646774), 0, 0x200u);
      v20 = *(_QWORD *)(v11 + 8);
      v21 = (_WORD *)(a1 + 1646774);
      v22 = (*(unsigned __int16 *)(v20 + 56) >> 1) - v18;
      v23 = &v52[v18];
      if ( *(unsigned __int16 *)(v20 + 56) >> 1 != v18 )
      {
        do
        {
          v24 = *v23++;
          *v21++ = v24;
          --v22;
        }
        while ( v22 != 0 );
      }
      *v21 = 0;
      RtlInitUnicodeString(&Source, (PCWSTR)(a1 + 1646774));
      memmove(SourceString, L"\\REGISTRY\\Machine\\System\\CurrentControlSet\\Services\\", 0x6Au);
      KeyHandle = nullptr;
      RtlInitUnicodeString(&v49, SourceString);
      Destination.Buffer = (PWSTR)(a1 + 1645710);
      Destination.MaximumLength = 512;
      RtlCopyUnicodeString(&Destination, &v49);
      RtlAppendUnicodeStringToString(&Destination, &Source);
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetObjDeviceInfo(1667):");
        DbgPrint("RegFullPath[%wZ]\n", &Destination);
      }
      v46.Length = 48;
      v46.RootDirectory = nullptr;
      v46.ObjectName = &Destination;
      v46.Attributes = 0;
      v46.SecurityDescriptor = nullptr;
      v46.SecurityQualityOfService = nullptr;
      if ( ZwOpenKey(&KeyHandle, 0xF003Fu, &v46) >= 0 )
      {
        ZwClose(KeyHandle);
        v25 = (_BYTE *)(a1 + 1645177);
        memset((void *)(a1 + 1645177), 0, 0x100u);
        Buffer = Source.Buffer;
        v27 = (unsigned __int64)Source.Length >> 1;
        if ( v27 != 0 )
        {
          v28 = (unsigned __int64)Source.Length >> 1;
          do
          {
            v29 = *(_BYTE *)Buffer++;
            *v25++ = v29;
            --v28;
          }
          while ( v28 != 0 );
        }
        *v25 = 0;
        *(_BYTE *)(v27 + a1 + 1645177) = 0;
LABEL_29:
        v6 = v38;
        continue;
      }
      memset((void *)(a1 + 1645177), 0, 0x100u);
      v31 = Source.Buffer;
      v32 = (unsigned __int64)Source.Length >> 1;
      v33 = (_BYTE *)(a1 + 1645177);
      if ( v32 != 0 )
      {
        v34 = (unsigned __int64)Source.Length >> 1;
        do
        {
          v35 = *(_BYTE *)v31++;
          *v33++ = v35;
          --v34;
        }
        while ( v34 != 0 );
      }
      *v33 = 0;
      *(_BYTE *)(v32 + a1 + 1645177) = 0;
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetObjDeviceInfo(1683):", v30, v31);
        DbgPrint("UnKnown Device[%wZ] Driver[%s]\n", v11 - 72, a1 + 1645177);
      }
      if ( !sub_16FA8((void *)(a1 + 1645177)) )
        goto LABEL_29;
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetObjDeviceInfo(1685):");
        DbgPrint("Hidden Entry Name[%s]!!!\n", (const char *)(a1 + 1645177));
      }
      v36 = (char *)Dst;
      memset(Dst, 0, 0xFFu);
      memset(v36 - 256, 0, 0x100u);
      memmove(v36, (const void *)(a1 + 1645177), (unsigned __int64)Source.Length >> 1);
      v36 += 512;
      *(v36 - 257) = 1;
      ++v7;
      v6 = ++v38;
      Dst = v36;
    }
    while ( *v10 != 0 );
    v4 = v45;
LABEL_41:
    ++v8;
  }
  while ( v8 <= 0x24 );
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetObjDeviceInfo(1698):");
    DbgPrint("Total Entry[%d]\n", v6);
  }
  ObfDereferenceObject(Object);
  v9 = v44;
  v7 = v6;
LABEL_45:
  ZwClose(*v9);
  return v7;
}


// ----- sub_175E0 @ 0x175e0 -----
__int64 __fastcall sub_175E0(const WCHAR *a1, _BYTE *a2, unsigned __int64 a3)
{
  unsigned __int64 v5; // r12
  _QWORD *v6; // r13
  _BYTE *v7; // r14
  _WORD *v8; // r15
  NTSTATUS v9; // ebx
  unsigned int *PoolWithTag; // rsi
  char *v12; // rbx
  _BYTE *v13; // rcx
  unsigned __int64 v14; // r11
  char *i; // rdx
  char v16; // al
  _BYTE *v17; // r11
  char *v18; // rcx
  __int64 j; // rdx
  char v20; // al
  void *v21; // rcx
  NTSTATUS v22; // ebx
  unsigned int *v23; // r14
  unsigned int *v24; // r13
  unsigned __int16 v25; // cx
  _BYTE *v26; // rsi
  void *v27; // rbp
  __int64 v28; // r8
  WCHAR v29; // bx
  WCHAR *k; // r11
  WCHAR *v31; // r11
  __int64 v32; // rax
  __int64 v33; // r8
  _WORD *m; // rax
  WCHAR *v35; // rax
  __int64 v36; // rcx
  const WCHAR *v37; // rbx
  NTSTATUS v38; // ebx
  char *v39; // rbx
  int v40; // r11d
  unsigned int v41; // eax
  __int64 v42; // rcx
  void *v43; // rbx
  unsigned __int64 v44; // r11
  _BYTE *v45; // rdx
  char *n; // rcx
  char v47; // al
  _BYTE *v48; // r11
  char *v49; // rcx
  __int64 ii; // rdx
  char v51; // al
  void *v52; // rbx
  unsigned __int64 v53; // r11
  _BYTE *v54; // rdx
  char *jj; // rcx
  char v56; // al
  char *v57; // rcx
  __int64 kk; // rdx
  char v59; // al
  char *v60; // rbx
  void *v61; // rdx
  void *v62; // rcx
  char v63; // [rsp+30h] [rbp-1E8h]
  unsigned __int16 v64; // [rsp+32h] [rbp-1E6h]
  void *KeyHandle; // [rsp+38h] [rbp-1E0h] BYREF
  ULONG ResultLength; // [rsp+40h] [rbp-1D8h] BYREF
  void *v67; // [rsp+48h] [rbp-1D0h]
  HANDLE Handle; // [rsp+50h] [rbp-1C8h] BYREF
  void *v69; // [rsp+58h] [rbp-1C0h]
  PCWSTR v70; // [rsp+60h] [rbp-1B8h]
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+68h] [rbp-1B0h] BYREF
  unsigned __int64 v72; // [rsp+98h] [rbp-180h]
  struct _UNICODE_STRING ValueName; // [rsp+A0h] [rbp-178h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+B0h] [rbp-168h] BYREF
  void *Src; // [rsp+C0h] [rbp-158h]
  struct _UNICODE_STRING v76; // [rsp+C8h] [rbp-150h] BYREF
  WCHAR Dst[56]; // [rsp+E0h] [rbp-138h] BYREF
  WCHAR SourceString[64]; // [rsp+150h] [rbp-C8h] BYREF

  v72 = a3;
  memmove(SourceString, L"\\REGISTRY\\Machine\\System\\CurrentControlSet\\Services\\_root_", 0x76u);
  Handle = nullptr;
  KeyHandle = nullptr;
  memmove(Dst, L"\\REGISTRY\\Machine\\System\\CurrentControlSet\\Services", 0x68u);
  v5 = 0;
  v63 = 0;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetRegDriverInfo(1723):");
    DbgPrint("GetRegDriverInfo Beg\n");
  }
  v6 = a1 + 823387;
  v7 = (char *)a1 + 1645177;
  v8 = a1 + 823919;
  Src = (void *)(a1 + 823387);
  v70 = a1 + 822855;
  v69 = (char *)a1 + 1645177;
  RtlInitUnicodeString(&DestinationString, SourceString);
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 0;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v9 = ZwOpenKey(&KeyHandle, 0xF003Fu, &ObjectAttributes);
  if ( v9 >= 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetRegDriverInfo(1737):");
      DbgPrint("RegOpen _root_ OK!\n");
    }
    PoolWithTag = (unsigned int *)ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x656E6431u);
    if ( PoolWithTag == nullptr )
    {
      ZwClose(KeyHandle);
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetRegDriverInfo(1742):");
        DbgPrint("ExAllocatePool failed on GetRegDriverInfo\n");
      }
      return 1;
    }
    ResultLength = 0;
    RtlInitUnicodeString(&ValueName, &qword_1A700);
    if ( ZwQueryValueKey(KeyHandle, &ValueName, KeyValueFullInformation, PoolWithTag, 0x200u, &ResultLength) < 0 )
    {
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetRegDriverInfo(1770):");
        DbgPrint("RegOpen ImagePath Failed!\n");
      }
    }
    else
    {
      v12 = (char *)PoolWithTag + PoolWithTag[2];
      memset(v8, 0, 0x200u);
      memset(v6, 0, 0x200u);
      *v6 = 0x6F006F0072005FLL;
      *((_DWORD *)v6 + 2) = 6226036;
      *((_WORD *)v6 + 6) = 0;
      memmove(v8, v12, PoolWithTag[3]);
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetRegDriverInfo(1757):");
        DbgPrint("=====RegKey[%ws]\n", v6);
        if ( dword_1F128 != 0 )
        {
          DbgPrint("GetRegDriverInfo(1758):");
          DbgPrint("=====Entry [%ws]\n", v8);
        }
      }
      memset(a2, 0, 0x100u);
      v13 = v7;
      v14 = (unsigned __int64)PoolWithTag[3] >> 1;
      for ( i = (char *)v8; v14 != 0; --v14 )
      {
        v16 = *i;
        i += 2;
        *v13++ = v16;
      }
      *v13 = 0;
      memmove(a2, v7, (unsigned __int64)PoolWithTag[3] >> 1);
      v17 = v7;
      v18 = (char *)v6;
      for ( j = 256; j != 0; --j )
      {
        v20 = *v18;
        v18 += 2;
        *v17++ = v20;
      }
      *v17 = 0;
      memmove(a2 + 256, v7, 0xFFu);
      v21 = KeyHandle;
      a2[511] = 0;
      v5 = 1;
      ZwClose(v21);
      KeyHandle = nullptr;
    }
    ExFreePoolWithTag(PoolWithTag, 0);
  }
  else if ( dword_1F128 != 0 )
  {
    DbgPrint("GetRegDriverInfo(1734):");
    DbgPrint("RegOpen _root_ Failed! [%8.8X]\n", v9);
  }
  RtlInitUnicodeString(&DestinationString, Dst);
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 0;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v22 = ZwOpenKey(&Handle, 0xF003Fu, &ObjectAttributes);
  if ( v22 < 0 )
  {
    if ( KeyHandle != nullptr )
      ZwClose(KeyHandle);
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetRegDriverInfo(1781):");
      DbgPrint("RegOpen Failed on GetDriverRegInfo! [%8.8X]\n", v22);
    }
    return 1;
  }
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetRegDriverInfo(1784):");
    DbgPrint("RegOpen OK! on GetDriverRegInfo!\n");
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetRegDriverInfo(1786):");
      DbgPrint("EnumerateValueKey Beg\n");
    }
  }
  v23 = (unsigned int *)ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x656E6431u);
  if ( v23 == nullptr )
  {
    if ( KeyHandle != nullptr )
      ZwClose(KeyHandle);
    ZwClose(Handle);
    if ( dword_1F128 == 0 )
      return 1;
    DbgPrint("GetRegDriverInfo(1793):");
    goto LABEL_37;
  }
  v24 = (unsigned int *)ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x656E6431u);
  if ( v24 == nullptr )
  {
    if ( KeyHandle != nullptr )
      ZwClose(KeyHandle);
    ZwClose(Handle);
    ExFreePoolWithTag(v23, 0);
    if ( dword_1F128 == 0 )
      return 1;
    DbgPrint("GetRegDriverInfo(1803):");
LABEL_37:
    DbgPrint("ExAllocatePool failed on GetDriverRegInfo\n");
    return 1;
  }
  v25 = 0;
  v64 = 0;
  v26 = &a2[512 * v5];
  v27 = Src;
  v67 = v26 + 256;
  do
  {
    ResultLength = 0;
    if ( ZwEnumerateKey(Handle, v25, KeyBasicInformation, v24, 0x200u, &ResultLength) < 0 )
      break;
    memset(v27, 0, 0x200u);
    if ( v23[3] < 0x200 )
      memmove(v27, v23 + 4, v23[3]);
    memset((void *)v70, 0, 0x200u);
    v28 = 0;
    v29 = Dst[0];
    for ( k = Dst; *k != 0; ++v28 )
      ++k;
    memmove((void *)v70, Dst, 2 * v28);
    v31 = Dst;
    v32 = 0;
    if ( v29 != 0 )
    {
      do
      {
        ++v31;
        ++v32;
      }
      while ( *v31 != 0 );
    }
    v33 = 0;
    v70[v32] = 92;
    for ( m = v27; *m != 0; ++v33 )
      ++m;
    v35 = Dst;
    v36 = 0;
    if ( v29 != 0 )
    {
      do
      {
        ++v35;
        ++v36;
      }
      while ( *v35 != 0 );
    }
    v37 = v70;
    memmove((void *)&v70[v36 + 1], v27, 2 * v33);
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetRegDriverInfo(1825):");
      DbgPrint("Enumerate Driver[%-.128ws]\n", v37);
    }
    RtlInitUnicodeString(&v76, v37);
    ObjectAttributes.RootDirectory = nullptr;
    ObjectAttributes.Attributes = 0;
    ObjectAttributes.SecurityDescriptor = nullptr;
    ObjectAttributes.SecurityQualityOfService = nullptr;
    ObjectAttributes.Length = 48;
    ObjectAttributes.ObjectName = &v76;
    v38 = ZwOpenKey(&KeyHandle, 0xF003Fu, &ObjectAttributes);
    if ( v38 < 0 )
    {
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetRegDriverInfo(1885):");
        DbgPrint("RegOpen Failed on [%ws]! [%8.8X]", v27, (unsigned int)v38);
      }
      break;
    }
    RtlInitUnicodeString(&ValueName, &qword_1A700);
    if ( ZwQueryValueKey(KeyHandle, &ValueName, KeyValueFullInformation, v24, 0x200u, &ResultLength) < 0 )
    {
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetRegDriverInfo(1880):");
        DbgPrint("ImagePath Info query Failed!\n");
      }
      goto LABEL_101;
    }
    v39 = (char *)v24 + v24[2];
    memset(v8, 0, 0x200u);
    memmove(v8, v39, v24[3]);
    v40 = dword_1F128;
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetRegDriverInfo(1837):");
      DbgPrint("=====RegKey[%ws]\n", v27);
      v40 = dword_1F128;
      if ( dword_1F128 != 0 )
      {
        DbgPrint("GetRegDriverInfo(1838):");
        DbgPrint("=====Entry [%ws]\n", v8);
        v40 = dword_1F128;
      }
    }
    v41 = v24[3];
    if ( v41 > 8 )
    {
      v42 = (v41 >> 1) - 5;
      if ( *v8 == 34 )
        --v42;
      if ( v8[v42] == 46 )
      {
        if ( (v8[v42 + 1] == 83 || v8[v42 + 1] == 115)
          && (v8[v42 + 2] == 89 || v8[v42 + 2] == 121)
          && (v8[v42 + 3] == 83 || v8[v42 + 3] == 115) )
        {
          if ( v40 != 0 )
          {
            DbgPrint("GetRegDriverInfo(1848):");
            DbgPrint("RegKey   [%ws]\n", v27);
            if ( dword_1F128 != 0 )
            {
              DbgPrint("GetRegDriverInfo(1849):");
              DbgPrint("   Driver[%ws]\n", v8);
            }
          }
          if ( v5 < v72 )
          {
            memset(v26, 0, 0x100u);
            v43 = v69;
            v44 = (unsigned __int64)v24[3] >> 1;
            v45 = v69;
            for ( n = (char *)v8; v44 != 0; --v44 )
            {
              v47 = *n;
              n += 2;
              *v45++ = v47;
            }
            *v45 = 0;
            memmove(v26, v43, (unsigned __int64)v24[3] >> 1);
            v48 = v43;
            v49 = (char *)v27;
            for ( ii = 256; ii != 0; --ii )
            {
              v51 = *v49;
              v49 += 2;
              *v48++ = v51;
            }
            goto LABEL_96;
          }
LABEL_97:
          v60 = (char *)v67;
          v63 = 1;
        }
        else
        {
          if ( v8[v42] != 46
            || v8[v42 + 1] != 69 && v8[v42 + 1] != 101
            || v8[v42 + 2] != 88 && v8[v42 + 2] != 120
            || v8[v42 + 3] != 69 && v8[v42 + 3] != 101 )
          {
            goto LABEL_101;
          }
          if ( v40 != 0 )
          {
            DbgPrint("GetRegDriverInfo(1864):");
            DbgPrint("RegKey   [%ws]\n", v27);
            if ( dword_1F128 != 0 )
            {
              DbgPrint("GetRegDriverInfo(1865):");
              DbgPrint("   EXE   [%ws]\n", v8);
            }
          }
          if ( v5 >= v72 )
            goto LABEL_97;
          memset(v26, 0, 0x100u);
          v52 = v69;
          v53 = (unsigned __int64)v24[3] >> 1;
          v54 = v69;
          for ( jj = (char *)v8; v53 != 0; --v53 )
          {
            v56 = *jj;
            jj += 2;
            *v54++ = v56;
          }
          *v54 = 0;
          memmove(v26, v52, (unsigned __int64)v24[3] >> 1);
          v48 = v52;
          v57 = (char *)v27;
          for ( kk = 256; kk != 0; --kk )
          {
            v59 = *v57;
            v57 += 2;
            *v48++ = v59;
          }
LABEL_96:
          v60 = (char *)v67;
          v61 = v69;
          v62 = v67;
          *v48 = 0;
          memmove(v62, v61, 0xFFu);
          v26[511] = 0;
        }
        ++v5;
        v26 += 512;
        v67 = v60 + 512;
      }
    }
LABEL_101:
    ZwClose(KeyHandle);
    v25 = ++v64;
  }
  while ( v64 < 0x400u );
  ZwClose(Handle);
  ExFreePoolWithTag(v24, 0);
  ExFreePoolWithTag(v23, 0);
  if ( v63 != 0 )
    return 0;
  return v5;
}


// ----- sub_180B4 @ 0x180b4 -----
__int64 __fastcall sub_180B4(__int64 a1, _QWORD *a2)
{
  __int64 **v4; // r12
  __int64 **v5; // rbx
  const wchar_t *v6; // rdx
  unsigned __int64 v7; // r8
  const wchar_t *v8; // rdx
  unsigned __int64 v9; // r8

  *a2 = 0;
  v4 = *(__int64 ***)(qword_1F5A0 + 40);
  v5 = v4;
  while ( 1 )
  {
    *(_QWORD *)(1584LL * *a2 + a1) = v5[6];
    v6 = (const wchar_t *)v5[12];
    if ( v6 != nullptr )
    {
      v7 = *((unsigned __int16 *)v5 + 44);
      if ( v7 >= 0x1FE )
        v7 = 508;
      wcsncpy((wchar_t *)(1584LL * *a2 + a1 + 532), v6, v7 >> 1);
      snprintf((char *)(1584LL * *a2 + a1 + 8), 0xFFu, "%S", (const wchar_t *)(1584LL * *a2 + a1 + 532));
    }
    v8 = (const wchar_t *)v5[10];
    if ( v8 != nullptr )
    {
      v9 = *((unsigned __int16 *)v5 + 36);
      if ( v9 >= 0x200 )
        v9 = 510;
      wcsncpy((wchar_t *)(1584LL * *a2 + a1 + 1056), v8, v9 >> 1);
      snprintf((char *)(1584LL * *a2 + a1 + 270), 0x100u, "%S", (const wchar_t *)(1584LL * *a2 + a1 + 1056));
    }
    if ( ++*a2 >= 0x400u )
      break;
    v5 = (__int64 **)*v5;
    if ( v5 == nullptr || v5 == v4 )
      return 0;
  }
  DbgPrint("Error: (GetDrvInfoFromDrvObj) sInfoCount(%8.8x) >= MAX_ENTRY(%8.8x)\n", *a2, 1024);
  return 0;
}


// ----- sub_18224 @ 0x18224 -----
bool __fastcall sub_18224(char *Str1, char *Str2)
{
  char *v4; // rax
  const char *v5; // rbx
  char *v6; // rax
  const char *v7; // rax

  v4 = strrchr(Str1, 92);
  if ( v4 != nullptr )
    v5 = v4 + 1;
  else
    v5 = Str1;
  v6 = strrchr(Str2, 92);
  if ( v6 != nullptr )
    v7 = v6 + 1;
  else
    v7 = Str2;
  return stricmp(v5, v7) == 0;
}


// ----- sub_182C0 @ 0x182c0 -----
unsigned __int64 __fastcall sub_182C0(__int64 a1, __int64 a2, char *a3, unsigned __int64 a4, unsigned __int64 a5)
{
  unsigned __int64 *v7; // rsi
  unsigned __int64 v8; // r13
  unsigned __int64 v9; // r12
  const wchar_t *v10; // rbx
  char *v11; // r14
  unsigned __int64 v12; // rdi
  char *v13; // rsi
  unsigned __int64 *v15; // [rsp+20h] [rbp-38h]
  char *v16; // [rsp+60h] [rbp+8h]

  memset((void *)(a1 + 264), 0, 0x18C000u);
  v7 = (unsigned __int64 *)(a1 + 1622280);
  v15 = (unsigned __int64 *)(a1 + 1622280);
  sub_180B4(a1 + 264, (_QWORD *)(a1 + 1622280));
  v8 = a5;
  v9 = 0;
  if ( *(_QWORD *)(a1 + 1622280) != 0 )
  {
    v10 = (const wchar_t *)(a1 + 1320);
    v11 = &a3[512 * a5 + 511];
    v16 = v11;
    do
    {
      v12 = 0;
      if ( a5 != 0 )
      {
        v13 = a3;
        while ( !sub_18224((char *)v10 - 786, v13) )
        {
          ++v12;
          v13 += 512;
          if ( v12 >= a5 )
          {
            v7 = v15;
            v11 = v16;
            goto LABEL_8;
          }
        }
        v7 = v15;
      }
      else
      {
LABEL_8:
        if ( *v10 != 0 )
        {
          snprintf(v11 - 255, 0xFFu, "%S", v10 - 262);
          snprintf(v11 - 511, 0x100u, "%S", v10);
          *v11 = 0;
          ++v8;
          v16 = v11 + 512;
          if ( v8 >= a4 )
            return v8;
        }
      }
      v11 = v16;
      ++v9;
      v10 += 792;
    }
    while ( v9 < *v7 );
  }
  return v8;
}


// ----- sub_18420 @ 0x18420 -----
char __fastcall sub_18420(__int64 a1, const char *a2)
{
  _WORD *v4; // rsi
  char *v5; // rdi
  __int64 v6; // rcx
  _WORD *i; // rdx
  __int16 v8; // ax
  __int16 v9; // bx
  _WORD *v10; // r11
  __int64 j; // r8
  _WORD *v12; // r11
  __int64 v13; // rax
  __int64 v14; // r8
  _WORD *k; // rax
  _WORD *v16; // rax
  __int64 v17; // rcx
  NTSTATUS v18; // ebx
  NTSTATUS v20; // ebx
  void *KeyHandle; // [rsp+20h] [rbp-E8h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+28h] [rbp-E0h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+58h] [rbp-B0h] BYREF
  _WORD Dst[56]; // [rsp+70h] [rbp-98h] BYREF

  memmove(Dst, L"\\REGISTRY\\Machine\\System\\CurrentControlSet\\Services", 0x68u);
  KeyHandle = nullptr;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("DeleteService(2084):");
    DbgPrint("DeleteService Beg Key[%s]\n", a2);
  }
  v4 = (_WORD *)(a1 + 1646774);
  v5 = (char *)(a1 + 1647838);
  v6 = 0;
  if ( *a2 != 0 )
  {
    do
      ++v6;
    while ( a2[v6] != 0 );
  }
  for ( i = v4; v6 != 0; --v6 )
  {
    v8 = *(unsigned __int8 *)a2++;
    *i++ = v8;
  }
  *i = 0;
  memset(v5, 0, 0x200u);
  v9 = Dst[0];
  v10 = Dst;
  for ( j = 0; *v10 != 0; ++j )
    ++v10;
  memmove(v5, Dst, 2 * j);
  v12 = Dst;
  v13 = 0;
  if ( v9 != 0 )
  {
    do
    {
      ++v12;
      ++v13;
    }
    while ( *v12 != 0 );
  }
  *(_WORD *)&v5[2 * v13] = 92;
  v14 = 0;
  for ( k = v4; *k != 0; ++v14 )
    ++k;
  v16 = Dst;
  v17 = 0;
  if ( v9 != 0 )
  {
    do
    {
      ++v16;
      ++v17;
    }
    while ( *v16 != 0 );
  }
  memmove(&v5[2 * v17 + 2], v4, 2 * v14);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("DeleteService(2093):");
    DbgPrint("Key[%ws] Path[%ws]\n", v4, v5);
  }
  RtlInitUnicodeString(&DestinationString, (PCWSTR)v5);
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 0;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v18 = ZwOpenKey(&KeyHandle, 0x10000u, &ObjectAttributes);
  if ( v18 < 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("DeleteService(2098):");
      DbgPrint("RegOpen Failed! [%8.8X]\n", v18);
    }
    return 0;
  }
  v20 = ZwDeleteKey(KeyHandle);
  if ( v20 < 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("DeleteService(2104):");
      DbgPrint("RegSet Failed! [%8.8X]\n", v20);
    }
    ZwClose(KeyHandle);
    return 0;
  }
  ZwClose(KeyHandle);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("DeleteService(2110):");
    DbgPrint("DeleteService End Key[%ws]\n", v4);
  }
  return 1;
}


// ----- sub_186A0 @ 0x186a0 -----
char __fastcall sub_186A0(__int64 a1, const char *a2)
{
  _WORD *v4; // rsi
  void *v5; // rdi
  __int64 v6; // rcx
  _WORD *i; // rdx
  __int16 v8; // ax
  _WORD *v9; // r11
  __int64 j; // r8
  NTSTATUS v11; // ebx
  NTSTATUS v13; // ebx
  NTSTATUS v14; // ebx
  NTSTATUS v15; // ebx
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-98h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+70h] [rbp-88h] BYREF
  _BYTE FileInformation[32]; // [rsp+80h] [rbp-78h] BYREF
  int v19; // [rsp+A0h] [rbp-58h]
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+A8h] [rbp-50h] BYREF
  char v21; // [rsp+100h] [rbp+8h] BYREF
  void *FileHandle; // [rsp+108h] [rbp+10h] BYREF

  FileHandle = nullptr;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("DeleteFile(2124):");
    DbgPrint("DeleteFile Beg Key[%s]\n", a2);
  }
  v4 = (_WORD *)(a1 + 1646774);
  v5 = (void *)(a1 + 1647838);
  v6 = 0;
  if ( *a2 != 0 )
  {
    do
      ++v6;
    while ( a2[v6] != 0 );
  }
  for ( i = v4; v6 != 0; --v6 )
  {
    v8 = *(unsigned __int8 *)a2++;
    *i++ = v8;
  }
  *i = 0;
  memset(v5, 0, 0x200u);
  v9 = v4;
  for ( j = 0; *v9 != 0; ++j )
    ++v9;
  memmove(v5, v4, 2 * j);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("DeleteFile(2131):");
    DbgPrint("Full Path[%ws]\n", v5);
  }
  RtlInitUnicodeString(&DestinationString, (PCWSTR)v5);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 0;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v11 = ZwCreateFile(&FileHandle, 0x10180u, &ObjectAttributes, &IoStatusBlock, nullptr, 0, 7u, 1u, 0x1000u, nullptr, 0);
  if ( v11 < 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("DeleteFile(2141):");
      DbgPrint("ZwCreateFile Failed! [%8.8X]\n", v11);
    }
    return 0;
  }
  v13 = ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
  if ( v13 < 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("DeleteFile(2147):");
      DbgPrint("ZwGetFileInformation Basic Failed! [%8.8X]\n", (unsigned int)v13);
    }
LABEL_18:
    ZwClose(FileHandle);
    return 0;
  }
  v19 = 128;
  v14 = ZwSetInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
  if ( v14 < 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("DeleteFile(2154):");
      DbgPrint("ZwSetFileInformation Basic Failed! [%8.8X]\n", (unsigned int)v14);
    }
    goto LABEL_18;
  }
  v21 = 1;
  v15 = ZwSetInformationFile(FileHandle, &IoStatusBlock, &v21, 1u, FileDispositionInformation);
  if ( v15 < 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("DeleteFile(2162):");
      DbgPrint("ZwSetFileInformation Failed! [%8.8X]\n", (unsigned int)v15);
    }
    goto LABEL_18;
  }
  ZwClose(FileHandle);
  if ( dword_1F128 != 0 )
  {
    DbgPrint("DeleteFile(2168):");
    DbgPrint("DeleteFile End Key[%ws]\n", v4);
  }
  return 1;
}


// ----- sub_18994 @ 0x18994 -----
__int64 __fastcall sub_18994(__int64 a1, void *a2, PEPROCESS *a3)
{
  void *v6; // r13
  NTSTATUS v7; // esi
  void **v8; // rsi
  __int64 v9; // rsi
  PEPROCESS Process; // [rsp+50h] [rbp+18h] BYREF
  __int64 v11; // [rsp+58h] [rbp+20h] BYREF

  v11 = 0;
  *a3 = nullptr;
  if ( qword_1F130 == 0 )
    return 0;
  v6 = *(void **)((char *)IoGetCurrentProcess() + qword_1F130);
  if ( v6 == a2 )
  {
    v7 = 0;
    Process = IoGetCurrentProcess();
  }
  else
  {
    v7 = PsLookupProcessByProcessId(a2, &Process);
  }
  if ( v7 < 0 )
    return 0;
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetPidEproc(2197):");
    DbgPrint("PID[%8.8I64X] eProcess[%8.8I64X]\n", a2, Process);
  }
  v8 = (void **)((char *)Process + qword_1F130);
  if ( MmIsAddressValid((char *)Process + qword_1F130) == 0 )
  {
    if ( dword_1F128 != 0 )
    {
      DbgPrint("GetPidEproc(2204):");
      DbgPrint("Not a valid Address!!!\n");
    }
    return 0;
  }
  if ( *v8 != a2 )
    return 0;
  if ( MmIsAddressValid((char *)Process + qword_1F138) == 0 )
    return 0;
  *a3 = Process;
  if ( v6 == a2 )
    return 1;
  if ( (int)sub_1575C((unsigned __int64)a2, &v11) >= 0 )
  {
    v9 = v11;
    if ( v11 != 259 )
      goto LABEL_21;
    return 1;
  }
  v9 = v11;
LABEL_21:
  if ( dword_1F128 != 0 )
  {
    DbgPrint("GetPidEproc(2229):");
    DbgPrint("PID[%8.8I64X] is not in Normal State[%8.8I64X]\n", a2, v9);
  }
  *a3 = nullptr;
  return 0;
}


// ----- sub_18B44 @ 0x18b44 -----
__int64 __fastcall sub_18B44(void **a1)
{
  NTSTATUS v2; // eax
  unsigned int v3; // ebx
  void *SectionHandle; // [rsp+20h] [rbp-88h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+28h] [rbp-80h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+58h] [rbp-50h] BYREF
  WCHAR SourceString[24]; // [rsp+68h] [rbp-40h] BYREF

  SectionHandle = nullptr;
  memmove(SourceString, L"\\device\\physicalmemory", 0x2Eu);
  RtlInitUnicodeString(&DestinationString, SourceString);
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 64;
  v2 = ZwOpenSection(&SectionHandle, 4u, &ObjectAttributes);
  v3 = v2;
  if ( v2 >= 0 )
    *a1 = SectionHandle;
  else
    DbgPrint("Error: (OpenPhysicalMemory)Could not open \\device\\physicalmemory 0x%x\n", v2);
  return v3;
}


// ----- sub_18C1C @ 0x18c1c -----
__int64 __fastcall sub_18C1C(HANDLE KeyHandle, PCWSTR SourceString, __int64 a3, void *a4, _DWORD *ResultLength)
{
  _DWORD *v5; // rsi
  ULONG Length; // edi
  unsigned int *PoolWithTag; // rbx
  NTSTATUS v12; // edi
  struct _UNICODE_STRING DestinationString; // [rsp+30h] [rbp-28h] BYREF

  v5 = ResultLength;
  Length = *ResultLength + 16;
  PoolWithTag = (unsigned int *)ExAllocatePoolWithTag(PagedPool, Length, 0x61636E65u);
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  RtlInitUnicodeString(&DestinationString, SourceString);
  v12 = ZwQueryValueKey(
          KeyHandle,
          &DestinationString,
          KeyValuePartialInformation,
          PoolWithTag,
          Length,
          (PULONG)&ResultLength);
  if ( v12 >= 0 )
  {
    memmove(a4, PoolWithTag + 3, PoolWithTag[2]);
    *v5 = PoolWithTag[2];
  }
  ExFreePoolWithTag(PoolWithTag, 0x61636E65u);
  return (unsigned int)v12;
}


// ----- sub_18CF0 @ 0x18cf0 -----
__int64 __fastcall sub_18CF0(PCWSTR SourceString, PCWSTR a2, __int64 a3, void *a4, _DWORD *a5)
{
  int v8; // ebx
  void *KeyHandle; // [rsp+30h] [rbp-58h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-50h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+48h] [rbp-40h] BYREF

  DbgPrint("d:\\depot\\trunk\\drivers\\endata\\reg.cpp(37):");
  DbgPrint("regKeyName %ws regValueName %ws regType %d\n", SourceString, a2, 4);
  RtlInitUnicodeString(&DestinationString, SourceString);
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 64;
  v8 = ZwOpenKey(&KeyHandle, 0x20019u, &ObjectAttributes);
  if ( v8 >= 0 )
  {
    v8 = sub_18C1C(KeyHandle, a2, 4, a4, a5);
    ZwClose(KeyHandle);
  }
  return (unsigned int)v8;
}


// ----- __security_check_cookie @ 0x18de0 -----
void __cdecl _security_check_cookie(uintptr_t StackCookie)
{
  __int64 v1; // rcx

  if ( StackCookie != BugCheckParameter2 )
LABEL_4:
    _report_gsfailure(StackCookie);
  v1 = __ROL8__(StackCookie, 16);
  if ( (_WORD)v1 != 0 )
  {
    StackCookie = __ROR8__(v1, 16);
    goto LABEL_4;
  }
}


// ----- __report_gsfailure @ 0x18e08 -----
void __cdecl __noreturn _report_gsfailure(uintptr_t StackCookie)
{
  KeBugCheckEx(0xF7u, StackCookie, BugCheckParameter2, BugCheckParameter3, 0);
}


// ----- PsLookupProcessByProcessId @ 0x18e36 -----
// attributes: thunk
NTSTATUS __stdcall PsLookupProcessByProcessId(HANDLE ProcessId, PEPROCESS *Process)
{
  return __imp_PsLookupProcessByProcessId(ProcessId, Process);
}


// ----- DbgPrint @ 0x18e42 -----
// attributes: thunk
ULONG DbgPrint(PCSTR Format, ...)
{
  return __imp_DbgPrint(Format);
}


// ----- memmove @ 0x18e60 -----
void *__cdecl memmove(void *Dst, const void *Src, size_t MaxCount)
{
  void *v3; // r11
  bool v4; // zf
  bool v5; // cc
  unsigned __int64 v6; // rdx
  size_t v7; // r9
  size_t v8; // r9
  __int64 v10; // rax
  __int64 v11; // r10
  __int64 v12; // r10
  int k; // eax
  int m; // eax
  __int64 v15; // r10
  __int64 v16; // r10
  __int64 v17; // r9
  __int64 v18; // r10
  __int64 v19; // r10
  int *v20; // rcx
  size_t v21; // r9
  size_t v22; // r9
  __int64 v23; // rax
  __int64 v24; // r10
  __int64 v25; // r10
  int i; // eax
  int j; // eax
  __int64 v28; // r10
  __int64 v29; // r10
  __int64 v30; // r9
  __int64 v31; // r10
  __int64 v32; // r10
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h] BYREF

  v3 = Dst;
  v4 = Src == Dst;
  v5 = Src <= Dst;
  v6 = (_BYTE *)Src - (_BYTE *)Dst;
  if ( v5 )
  {
    if ( v4 )
      return v3;
    v20 = (int *)((char *)Dst + MaxCount);
    if ( MaxCount >= 8 )
    {
      if ( ((unsigned __int8)v20 & 7) != 0 )
      {
        if ( ((unsigned __int8)v20 & 1) != 0 )
        {
          v20 = (int *)((char *)v20 - 1);
          --MaxCount;
          *(_BYTE *)v20 = *((_BYTE *)v20 + v6);
        }
        if ( ((unsigned __int8)v20 & 2) != 0 )
        {
          v20 = (int *)((char *)v20 - 2);
          MaxCount -= 2LL;
          *(_WORD *)v20 = *(_WORD *)((char *)v20 + v6);
        }
        if ( ((unsigned __int8)v20 & 4) != 0 )
        {
          --v20;
          MaxCount -= 4LL;
          *v20 = *(int *)((char *)v20 + v6);
        }
      }
      while ( 1 )
      {
        v21 = MaxCount >> 5;
        if ( MaxCount >> 5 == 0 )
          break;
        if ( v21 < 0x800 || v6 > 0xFFFFFFFFFFFFF000uLL )
        {
          do
          {
            v23 = *(_QWORD *)((char *)v20 + v6 - 8);
            v24 = *(_QWORD *)((char *)v20 + v6 - 16);
            v20 -= 8;
            *((_QWORD *)v20 + 3) = v23;
            *((_QWORD *)v20 + 2) = v24;
            v25 = *(_QWORD *)((char *)v20 + v6);
            --v21;
            *((_QWORD *)v20 + 1) = *(_QWORD *)((char *)v20 + v6 + 8);
            *(_QWORD *)v20 = v25;
          }
          while ( v21 != 0 );
          MaxCount &= 0x1Fu;
          break;
        }
        do
        {
          for ( i = 32; i != 0; --i )
          {
            v20 -= 32;
            _mm_prefetch((const char *)v20 + v6, 0);
            _mm_prefetch((const char *)v20 + v6 + 64, 0);
          }
          v20 += 1024;
          for ( j = 64; j != 0; --j )
          {
            v28 = *(_QWORD *)((char *)v20 + v6 - 16);
            _mm_stream_si32(v20 - 2, *(_QWORD *)((char *)v20 + v6 - 8));
            _mm_stream_si32(v20 - 4, v28);
            v29 = *(_QWORD *)((char *)v20 + v6 - 32);
            _mm_stream_si32(v20 - 6, *(_QWORD *)((char *)v20 + v6 - 24));
            _mm_stream_si32(v20 - 8, v29);
            v30 = *(_QWORD *)((char *)v20 + v6 - 40);
            v31 = *(_QWORD *)((char *)v20 + v6 - 48);
            v20 -= 16;
            _mm_stream_si32(v20 + 6, v30);
            _mm_stream_si32(v20 + 4, v31);
            v32 = *(_QWORD *)((char *)v20 + v6);
            _mm_stream_si32(v20 + 2, *(_QWORD *)((char *)v20 + v6 + 8));
            _mm_stream_si32(v20, v32);
          }
          MaxCount -= 4096LL;
        }
        while ( MaxCount >= 0x1000 );
        _InterlockedOr8((volatile signed __int8 *)&retaddr, 0);
      }
      v22 = MaxCount >> 3;
      if ( MaxCount >> 3 != 0 )
      {
        do
        {
          v20 -= 2;
          --v22;
          *(_QWORD *)v20 = *(_QWORD *)((char *)v20 + v6);
        }
        while ( v22 != 0 );
        MaxCount &= 7u;
      }
    }
    if ( MaxCount != 0 )
    {
      do
      {
        v20 = (int *)((char *)v20 - 1);
        --MaxCount;
        *(_BYTE *)v20 = *((_BYTE *)v20 + v6);
      }
      while ( MaxCount != 0 );
      return v3;
    }
    else
    {
      return v3;
    }
  }
  else
  {
    if ( MaxCount >= 8 )
    {
      if ( ((unsigned __int8)Dst & 7) != 0 )
      {
        if ( ((unsigned __int8)Dst & 1) != 0 )
        {
          --MaxCount;
          *(_BYTE *)Dst = *((_BYTE *)Dst + v6);
          Dst = (char *)Dst + 1;
        }
        if ( ((unsigned __int8)Dst & 2) != 0 )
        {
          MaxCount -= 2LL;
          *(_WORD *)Dst = *(_WORD *)((char *)Dst + v6);
          Dst = (char *)Dst + 2;
        }
        if ( ((unsigned __int8)Dst & 4) != 0 )
        {
          MaxCount -= 4LL;
          *(_DWORD *)Dst = *(_DWORD *)((char *)Dst + v6);
          Dst = (char *)Dst + 4;
        }
      }
      while ( 1 )
      {
        v7 = MaxCount >> 5;
        if ( MaxCount >> 5 == 0 )
          break;
        if ( v7 < 0x800 || v6 < 0x1000 )
        {
          do
          {
            v10 = *(_QWORD *)((char *)Dst + v6);
            v11 = *(_QWORD *)((char *)Dst + v6 + 8);
            Dst = (char *)Dst + 32;
            *((_QWORD *)Dst - 4) = v10;
            *((_QWORD *)Dst - 3) = v11;
            v12 = *(_QWORD *)((char *)Dst + v6 - 8);
            --v7;
            *((_QWORD *)Dst - 2) = *(_QWORD *)((char *)Dst + v6 - 16);
            *((_QWORD *)Dst - 1) = v12;
          }
          while ( v7 != 0 );
          MaxCount &= 0x1Fu;
          break;
        }
        do
        {
          for ( k = 32; k != 0; --k )
          {
            _mm_prefetch((const char *)Dst + v6, 0);
            _mm_prefetch((const char *)Dst + v6 + 64, 0);
            Dst = (char *)Dst + 128;
          }
          Dst = (char *)Dst - 4096;
          for ( m = 64; m != 0; --m )
          {
            v15 = *(_QWORD *)((char *)Dst + v6 + 8);
            _mm_stream_si32((int *)Dst, *(_QWORD *)((char *)Dst + v6));
            _mm_stream_si32((int *)Dst + 2, v15);
            v16 = *(_QWORD *)((char *)Dst + v6 + 24);
            _mm_stream_si32((int *)Dst + 4, *(_QWORD *)((char *)Dst + v6 + 16));
            _mm_stream_si32((int *)Dst + 6, v16);
            v17 = *(_QWORD *)((char *)Dst + v6 + 32);
            v18 = *(_QWORD *)((char *)Dst + v6 + 40);
            Dst = (char *)Dst + 64;
            _mm_stream_si32((int *)Dst - 8, v17);
            _mm_stream_si32((int *)Dst - 6, v18);
            v19 = *(_QWORD *)((char *)Dst + v6 - 8);
            _mm_stream_si32((int *)Dst - 4, *(_QWORD *)((char *)Dst + v6 - 16));
            _mm_stream_si32((int *)Dst - 2, v19);
          }
          MaxCount -= 4096LL;
        }
        while ( MaxCount >= 0x1000 );
        _InterlockedOr8((volatile signed __int8 *)&retaddr, 0);
      }
      v8 = MaxCount >> 3;
      if ( MaxCount >> 3 != 0 )
      {
        do
        {
          *(_QWORD *)Dst = *(_QWORD *)((char *)Dst + v6);
          Dst = (char *)Dst + 8;
          --v8;
        }
        while ( v8 != 0 );
        MaxCount &= 7u;
      }
    }
    if ( MaxCount != 0 )
    {
      do
      {
        *(_BYTE *)Dst = *((_BYTE *)Dst + v6);
        Dst = (char *)Dst + 1;
        --MaxCount;
      }
      while ( MaxCount != 0 );
      return v3;
    }
    else
    {
      return v3;
    }
  }
}


// ----- __C_specific_handler @ 0x1919a -----
// attributes: thunk
EXCEPTION_DISPOSITION __cdecl _C_specific_handler(
        struct _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        struct _CONTEXT *ContextRecord,
        struct _DISPATCHER_CONTEXT *DispatcherContext)
{
  return __C_specific_handler(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
}


// ----- memset @ 0x191b0 -----
// local variable allocation has failed, the output may be wrong!
void *__cdecl memset(void *Dst, int Val, size_t Size)
{
  void *result; // rax
  unsigned int v4; // ecx
  size_t v5; // r9
  unsigned __int64 v6; // r9
  size_t v7; // r9
  size_t i; // r9
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h] BYREF

  result = Dst;
  if ( Size >= 8 )
  {
    *(_QWORD *)&Val = 0x101010101010101LL * (unsigned __int8)Val;
    if ( Size >= 0x40 )
    {
      v4 = -(int)Dst & 7;
      if ( v4 != 0 )
      {
        Size -= v4;
        *(_QWORD *)result = *(_QWORD *)&Val;
      }
      Dst = (char *)result + v4;
      v5 = Size;
      Size &= 0x3Fu;
      v6 = v5 >> 6;
      if ( v6 != 0 )
      {
        if ( v6 >= 0x400 )
        {
          do
          {
            _mm_stream_si32((int *)Dst, Val);
            _mm_stream_si32((int *)Dst + 2, Val);
            _mm_stream_si32((int *)Dst + 4, Val);
            Dst = (char *)Dst + 64;
            _mm_stream_si32((int *)Dst - 10, Val);
            _mm_stream_si32((int *)Dst - 8, Val);
            --v6;
            _mm_stream_si32((int *)Dst - 6, Val);
            _mm_stream_si32((int *)Dst - 4, Val);
            _mm_stream_si32((int *)Dst - 2, Val);
          }
          while ( v6 != 0 );
          _InterlockedOr8((volatile signed __int8 *)&retaddr, 0);
        }
        else
        {
          do
          {
            *(_QWORD *)Dst = *(_QWORD *)&Val;
            *((_QWORD *)Dst + 1) = *(_QWORD *)&Val;
            *((_QWORD *)Dst + 2) = *(_QWORD *)&Val;
            Dst = (char *)Dst + 64;
            *((_QWORD *)Dst - 5) = *(_QWORD *)&Val;
            *((_QWORD *)Dst - 4) = *(_QWORD *)&Val;
            --v6;
            *((_QWORD *)Dst - 3) = *(_QWORD *)&Val;
            *((_QWORD *)Dst - 2) = *(_QWORD *)&Val;
            *((_QWORD *)Dst - 1) = *(_QWORD *)&Val;
          }
          while ( v6 != 0 );
        }
      }
    }
    v7 = Size;
    Size &= 7u;
    for ( i = v7 >> 3; i != 0; --i )
    {
      *(_QWORD *)Dst = *(_QWORD *)&Val;
      Dst = (char *)Dst + 8;
    }
  }
  for ( ; Size != 0; --Size )
  {
    *(_BYTE *)Dst = Val;
    Dst = (char *)Dst + 1;
  }
  return result;
}


// ----- memcmp @ 0x192b0 -----
int __cdecl memcmp(const void *Buf1, const void *Buf2, size_t Size)
{
  signed __int64 v3; // rdx
  bool v4; // cf
  size_t v6; // r9
  unsigned __int64 v7; // rax
  size_t v8; // r9

  v3 = (_BYTE *)Buf2 - (_BYTE *)Buf1;
  if ( Size < 8 )
    goto mcmp30;
  for ( ; ((unsigned __int8)Buf1 & 7) != 0; --Size )
  {
    v4 = *(_BYTE *)Buf1 < *((_BYTE *)Buf1 + v3);
    if ( *(_BYTE *)Buf1 != *((_BYTE *)Buf1 + v3) )
      return -v4 - (v4 - 1);
    Buf1 = (char *)Buf1 + 1;
  }
  if ( Size >> 3 == 0 )
  {
mcmp30:
    if ( Size == 0 )
      return 0;
    while ( 1 )
    {
      v4 = *(_BYTE *)Buf1 < *((_BYTE *)Buf1 + v3);
      if ( *(_BYTE *)Buf1 != *((_BYTE *)Buf1 + v3) )
        break;
      Buf1 = (char *)Buf1 + 1;
      if ( --Size == 0 )
        return 0;
    }
    return -v4 - (v4 - 1);
  }
  v6 = Size >> 5;
  if ( Size >> 5 != 0 )
  {
    while ( 1 )
    {
      v7 = *(_QWORD *)Buf1;
      if ( *(_QWORD *)Buf1 != *(_QWORD *)((char *)Buf1 + v3) )
        break;
      v7 = *((_QWORD *)Buf1 + 1);
      if ( v7 != *(_QWORD *)((char *)Buf1 + v3 + 8) )
        goto mcmp_adjust8;
      v7 = *((_QWORD *)Buf1 + 2);
      if ( v7 != *(_QWORD *)((char *)Buf1 + v3 + 16) )
        goto mcmp_adjust16;
      v7 = *((_QWORD *)Buf1 + 3);
      if ( v7 != *(_QWORD *)((char *)Buf1 + v3 + 24) )
      {
        Buf1 = (char *)Buf1 + 8;
mcmp_adjust16:
        Buf1 = (char *)Buf1 + 8;
mcmp_adjust8:
        Buf1 = (char *)Buf1 + 8;
        break;
      }
      Buf1 = (char *)Buf1 + 32;
      if ( --v6 == 0 )
      {
        Size &= 0x1Fu;
        goto mcmp70;
      }
    }
  }
  else
  {
mcmp70:
    v8 = Size >> 3;
    if ( Size >> 3 == 0 )
      goto mcmp30;
    while ( 1 )
    {
      v7 = *(_QWORD *)Buf1;
      if ( *(_QWORD *)Buf1 != *(_QWORD *)((char *)Buf1 + v3) )
        break;
      Buf1 = (char *)Buf1 + 8;
      if ( --v8 == 0 )
      {
        Size &= 7u;
        goto mcmp30;
      }
    }
  }
  v4 = _byteswap_uint64(v7) < _byteswap_uint64(*(_QWORD *)((char *)Buf1 + v3));
  return -v4 - (v4 - 1);
}


// ----- __GSHandlerCheckCommon @ 0x19380 -----
__int64 __fastcall _GSHandlerCheckCommon(__int64 a1, __int64 a2)
{
  __int64 result; // rax
  __int64 v3; // rcx

  result = *(_QWORD *)(a2 + 16);
  v3 = *(_QWORD *)(a2 + 8) + *(unsigned int *)(result + 8);
  if ( (*(_BYTE *)(v3 + 3) & 0xF) != 0 )
    return *(_BYTE *)(v3 + 3) & 0xF0;
  return result;
}


// ----- __GSHandlerCheck @ 0x193ec -----
__int64 __fastcall _GSHandlerCheck(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _GSHandlerCheckCommon(a2, a4);
  return 1;
}


// ----- __GSHandlerCheck_SEH @ 0x19410 -----
__int64 __fastcall _GSHandlerCheck_SEH(
        struct _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        struct _CONTEXT *ContextRecord,
        struct _DISPATCHER_CONTEXT *DispatcherContext)
{
  _DWORD *v8; // rbx
  int v9; // r11d
  unsigned int v10; // edx

  v8 = (char *)DispatcherContext->HandlerData + 16 * *(unsigned int *)DispatcherContext->HandlerData + 4;
  _GSHandlerCheckCommon((__int64)EstablisherFrame, (__int64)DispatcherContext);
  v9 = *v8 & 2;
  v10 = 1;
  if ( (ExceptionRecord->ExceptionFlags & 0x66) == 0 )
    v9 = *v8 & 1;
  if ( v9 != 0 )
    return (unsigned int)_C_specific_handler(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
  return v10;
}


// ----- DriverEntry @ 0x21008 -----
NTSTATUS __stdcall DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
  unsigned __int64 v2; // rax

  v2 = BugCheckParameter2;
  if ( BugCheckParameter2 == 0 || BugCheckParameter2 == 0x2B992DDFA232LL )
  {
    v2 = ((unsigned __int64)&BugCheckParameter2 ^ MEMORY[0xFFFFF78000000320]) & 0xFFFFFFFFFFFFLL;
    if ( v2 == 0 )
      v2 = 0x2B992DDFA232LL;
    BugCheckParameter2 = v2;
  }
  BugCheckParameter3 = ~v2;
  return sub_139E4(DriverObject, (__int64)RegistryPath);
}


