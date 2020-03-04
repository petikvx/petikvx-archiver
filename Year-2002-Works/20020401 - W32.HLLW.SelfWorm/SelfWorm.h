// Main
#define IDM_EXIT    101
#define IDM_STARTUP 102
#define IDM_STOPAV  103

#define IDC_STATIC  106
#define IDM_ABOUTU  109
#define IDM_ABOUT   110


// Spread
#define IDM_VBSSPREAD   201
#define IDM_READMAIL    202
#define IDM_MAILTO  203
#define IDM_MIRC    204

// Payload
#define IDM_FORMAT  301
#define IDM_DISABLE 302
#define IDM_STOP    303
#define IDM_REBOOT  304
#define IDM_CRASH   305

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK Regedit(HWND, UINT, WPARAM, LPARAM);
