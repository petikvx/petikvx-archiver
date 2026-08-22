using System.Runtime.InteropServices;
using System.Text;

namespace System.Windows.Forms;

public class MessageBoxManager
{
	private delegate IntPtr HookProc(int nCode, IntPtr wParam, IntPtr lParam);

	private delegate bool EnumChildProc(IntPtr hWnd, IntPtr lParam);

	public struct CWPRETSTRUCT
	{
		public IntPtr lResult;

		public IntPtr lParam;

		public IntPtr wParam;

		public uint message;

		public IntPtr hwnd;
	}

	private const int WH_CALLWNDPROCRET = 12;

	private const int WM_DESTROY = 2;

	private const int WM_INITDIALOG = 272;

	private const int WM_TIMER = 275;

	private const int WM_USER = 1024;

	private const int DM_GETDEFID = 1024;

	private const int MBOK = 1;

	private const int MBCancel = 2;

	private const int MBAbort = 3;

	private const int MBRetry = 4;

	private const int MBIgnore = 5;

	private const int MBYes = 6;

	private const int MBNo = 7;

	private static HookProc hookProc;

	private static EnumChildProc enumProc;

	[ThreadStatic]
	private static IntPtr hHook;

	[ThreadStatic]
	private static int nButton;

	public static string OK;

	public static string Cancel;

	public static string Abort;

	public static string Retry;

	public static string Ignore;

	public static string Yes;

	public static string No;

	[DllImport("user32.dll")]
	private static extern IntPtr SendMessage(IntPtr hWnd, int Msg, IntPtr wParam, IntPtr lParam);

	[DllImport("user32.dll")]
	private static extern IntPtr SetWindowsHookEx(int idHook, HookProc lpfn, IntPtr hInstance, int threadId);

	[DllImport("user32.dll")]
	private static extern int UnhookWindowsHookEx(IntPtr idHook);

	[DllImport("user32.dll")]
	private static extern IntPtr CallNextHookEx(IntPtr idHook, int nCode, IntPtr wParam, IntPtr lParam);

	[DllImport("user32.dll", CharSet = CharSet.Unicode, EntryPoint = "GetWindowTextLengthW")]
	private static extern int GetWindowTextLength(IntPtr hWnd);

	[DllImport("user32.dll", CharSet = CharSet.Unicode, EntryPoint = "GetWindowTextW")]
	private static extern int GetWindowText(IntPtr hWnd, StringBuilder text, int maxLength);

	[DllImport("user32.dll")]
	private static extern int EndDialog(IntPtr hDlg, IntPtr nResult);

	[DllImport("user32.dll")]
	private static extern bool EnumChildWindows(IntPtr hWndParent, EnumChildProc lpEnumFunc, IntPtr lParam);

	[DllImport("user32.dll", CharSet = CharSet.Unicode, EntryPoint = "GetClassNameW")]
	private static extern int GetClassName(IntPtr hWnd, StringBuilder lpClassName, int nMaxCount);

	[DllImport("user32.dll")]
	private static extern int GetDlgCtrlID(IntPtr hwndCtl);

	[DllImport("user32.dll")]
	private static extern IntPtr GetDlgItem(IntPtr hDlg, int nIDDlgItem);

	[DllImport("user32.dll", CharSet = CharSet.Unicode, EntryPoint = "SetWindowTextW")]
	private static extern bool SetWindowText(IntPtr hWnd, string lpString);

	static MessageBoxManager()
	{
		OK = "&OK";
		Cancel = "&Cancel";
		Abort = "&Abort";
		Retry = "&Retry";
		Ignore = "&Ignore";
		Yes = "&Yes";
		No = "&No";
		hookProc = MessageBoxHookProc;
		enumProc = MessageBoxEnumProc;
		hHook = IntPtr.Zero;
	}

	public static void Register()
	{
		if (hHook != IntPtr.Zero)
		{
			throw new NotSupportedException("One hook per thread allowed.");
		}
		hHook = SetWindowsHookEx(12, hookProc, IntPtr.Zero, AppDomain.GetCurrentThreadId());
	}

	public static void Unregister()
	{
		if (hHook != IntPtr.Zero)
		{
			UnhookWindowsHookEx(hHook);
			hHook = IntPtr.Zero;
		}
	}

	private static IntPtr MessageBoxHookProc(int nCode, IntPtr wParam, IntPtr lParam)
	{
		if (nCode < 0)
		{
			return CallNextHookEx(hHook, nCode, wParam, lParam);
		}
		CWPRETSTRUCT cWPRETSTRUCT = (CWPRETSTRUCT)Marshal.PtrToStructure(lParam, typeof(CWPRETSTRUCT));
		IntPtr idHook = hHook;
		if (cWPRETSTRUCT.message == 272)
		{
			int windowTextLength = GetWindowTextLength(cWPRETSTRUCT.hwnd);
			StringBuilder stringBuilder = new StringBuilder(10);
			GetClassName(cWPRETSTRUCT.hwnd, stringBuilder, stringBuilder.Capacity);
			if (stringBuilder.ToString() == "#32770")
			{
				nButton = 0;
				EnumChildWindows(cWPRETSTRUCT.hwnd, enumProc, IntPtr.Zero);
				if (nButton == 1)
				{
					IntPtr dlgItem = GetDlgItem(cWPRETSTRUCT.hwnd, 2);
					if (dlgItem != IntPtr.Zero)
					{
						SetWindowText(dlgItem, OK);
					}
				}
			}
		}
		return CallNextHookEx(idHook, nCode, wParam, lParam);
	}

	private static bool MessageBoxEnumProc(IntPtr hWnd, IntPtr lParam)
	{
		StringBuilder stringBuilder = new StringBuilder(10);
		GetClassName(hWnd, stringBuilder, stringBuilder.Capacity);
		if (stringBuilder.ToString() == "Button")
		{
			switch (GetDlgCtrlID(hWnd))
			{
			case 1:
				SetWindowText(hWnd, OK);
				break;
			case 2:
				SetWindowText(hWnd, Cancel);
				break;
			case 3:
				SetWindowText(hWnd, Abort);
				break;
			case 4:
				SetWindowText(hWnd, Retry);
				break;
			case 5:
				SetWindowText(hWnd, Ignore);
				break;
			case 6:
				SetWindowText(hWnd, Yes);
				break;
			case 7:
				SetWindowText(hWnd, No);
				break;
			}
			nButton++;
		}
		return true;
	}
}
