// Compile with:
//   gcc -o PetiK_CTF_01.exe petik-ctf-01.c -mwindows -lcrypt32

#include <windows.h>
#include <string.h>
#include <wincrypt.h>

#define IDC_EDIT_USER   101
#define IDC_EDIT_PASS   102
#define IDC_BTN_LOGIN   103

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE: {
        // Username label
        CreateWindow("STATIC", "Username:",
                     WS_VISIBLE | WS_CHILD,
                     20, 20, 80, 20, hwnd, NULL, NULL, NULL);
        // Username edit box (tab stop), width = 290
        CreateWindow("EDIT", "",
                     WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | WS_TABSTOP,
                     110, 20, 290, 20, hwnd, (HMENU)IDC_EDIT_USER, NULL, NULL);

        // Password label
        CreateWindow("STATIC", "Password:",
                     WS_VISIBLE | WS_CHILD,
                     20, 60, 80, 20, hwnd, NULL, NULL, NULL);
        // Password edit box (masked + tab stop), width = 290, limit to 32 chars
        HWND hPass = CreateWindow("EDIT", "",
                     WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_PASSWORD | WS_TABSTOP,
                     110, 60, 290, 20, hwnd, (HMENU)IDC_EDIT_PASS, NULL, NULL);
        SendMessage(hPass, EM_LIMITTEXT, 32, 0);

        // Login button (default + tab stop)
        CreateWindow("BUTTON", "Login",
                     WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_DEFPUSHBUTTON | WS_TABSTOP,
                     110, 100, 80, 25, hwnd, (HMENU)IDC_BTN_LOGIN, NULL, NULL);
        break;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == IDC_BTN_LOGIN) {
            char userbuf[256] = {0};
            char passbuf[64] = {0};

            // Retrieve Username
            GetDlgItemText(hwnd, IDC_EDIT_USER, userbuf, sizeof(userbuf));
            if (userbuf[0] == '\0') {
                MessageBox(hwnd, "Please enter a username.", "Input Required", MB_OK | MB_ICONWARNING);
                break;
            }

            // Retrieve Password
            GetDlgItemText(hwnd, IDC_EDIT_PASS, passbuf, sizeof(passbuf));
            if (passbuf[0] == '\0') {
                MessageBox(hwnd, "Please enter a password.", "Input Required", MB_OK | MB_ICONWARNING);
                break;
            }

            // Compute MD5(username)
            HCRYPTPROV hProv = 0;
            HCRYPTHASH hHash = 0;
            BYTE rgbHash[16];
            DWORD cbHash = sizeof(rgbHash);
            char hexHash[33];
            static const char hexDigits[] = "0123456789abcdef";

            if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT) ||
                !CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash) ||
                !CryptHashData(hHash, (BYTE*)userbuf, (DWORD)strlen(userbuf), 0) ||
                !CryptGetHashParam(hHash, HP_HASHVAL, rgbHash, &cbHash, 0)) {
                MessageBox(hwnd, "CryptoAPI error.", "Error", MB_OK | MB_ICONERROR);
                if (hHash) CryptDestroyHash(hHash);
                if (hProv) CryptReleaseContext(hProv, 0);
                break;
            }

            for (DWORD i = 0; i < cbHash; i++) {
                hexHash[i*2    ] = hexDigits[rgbHash[i] >> 4];
                hexHash[i*2 + 1] = hexDigits[rgbHash[i] & 0x0F];
            }
            hexHash[32] = '\0';

            CryptDestroyHash(hHash);
            CryptReleaseContext(hProv, 0);

            // Compare entered password vs. MD5(username)
            if (strcmp(passbuf, hexHash) == 0) {
                MessageBox(hwnd, "Login successful!", "Success", MB_OK | MB_ICONINFORMATION);
            } else {
                MessageBox(hwnd, "Incorrect password.", "Error", MB_OK | MB_ICONERROR);
            }
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc    = WndProc;
    wc.hInstance      = hInstance;
    wc.lpszClassName  = "LoginWindowClass";
    wc.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);  // white background

    RegisterClass(&wc);

    HWND hwnd = CreateWindow(
        wc.lpszClassName,               // window class name
        "PetiK CTF 1.0 - (c) 2025",     // window title
        WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 480, 200,  // width = 480, height = 200
        NULL, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    // Message loop with IsDialogMessage to handle Tab/Enter
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        if (!IsDialogMessage(hwnd, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}
