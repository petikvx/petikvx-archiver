using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;

namespace ns0;

internal class Class6
{
	private delegate void Delegate1(object o);

	internal class Attribute0 : Attribute
	{
		internal class Class7<T>
		{
			private static object object_0;

			internal static bool smethod_0()
			{
				return object_0 == null;
			}

			internal static object smethod_1()
			{
				return object_0;
			}
		}

		public Attribute0(object object_0)
		{
		}
	}

	internal class Class8
	{
		internal static string smethod_0(string string_0, string string_1)
		{
			byte[] bytes = Encoding.Unicode.GetBytes(string_0);
			byte[] key = new byte[32]
			{
				82, 102, 104, 110, 32, 77, 24, 34, 118, 181,
				51, 17, 18, 51, 12, 109, 10, 32, 77, 24,
				34, 158, 161, 41, 97, 28, 118, 181, 5, 25,
				1, 88
			};
			byte[] iV = smethod_9(Encoding.Unicode.GetBytes(string_1));
			MemoryStream memoryStream = new MemoryStream();
			SymmetricAlgorithm symmetricAlgorithm = smethod_7();
			symmetricAlgorithm.Key = key;
			symmetricAlgorithm.IV = iV;
			CryptoStream cryptoStream = new CryptoStream(memoryStream, symmetricAlgorithm.CreateEncryptor(), CryptoStreamMode.Write);
			cryptoStream.Write(bytes, 0, bytes.Length);
			cryptoStream.Close();
			return Convert.ToBase64String(memoryStream.ToArray());
		}
	}

	[UnmanagedFunctionPointer(CallingConvention.StdCall)]
	internal delegate uint Delegate2(IntPtr classthis, IntPtr comp, IntPtr info, [MarshalAs(UnmanagedType.U4)] uint flags, IntPtr nativeEntry, ref uint nativeSizeOfCode);

	[UnmanagedFunctionPointer(CallingConvention.StdCall)]
	private delegate IntPtr Delegate3();

	internal struct Struct0
	{
		internal bool bool_0;

		internal byte[] byte_0;
	}

	internal class Class9
	{
		private BinaryReader binaryReader_0;

		public Class9(Stream stream_0)
		{
			binaryReader_0 = new BinaryReader(stream_0);
		}

		[SpecialName]
		internal Stream method_0()
		{
			return binaryReader_0.BaseStream;
		}

		internal byte[] method_1(int int_0)
		{
			return binaryReader_0.ReadBytes(int_0);
		}

		internal int method_2(byte[] byte_0, int int_0, int int_1)
		{
			return binaryReader_0.Read(byte_0, int_0, int_1);
		}

		internal int method_3()
		{
			return binaryReader_0.ReadInt32();
		}

		internal void method_4()
		{
			binaryReader_0.Close();
		}
	}

	private delegate IntPtr Delegate4(IntPtr hModule, string lpName, uint lpType);

	[UnmanagedFunctionPointer(CallingConvention.StdCall)]
	private delegate IntPtr Delegate5(IntPtr lpAddress, uint dwSize, uint flAllocationType, uint flProtect);

	[UnmanagedFunctionPointer(CallingConvention.StdCall)]
	private delegate int Delegate6(IntPtr hProcess, IntPtr lpBaseAddress, [In][Out] byte[] buffer, uint size, out IntPtr lpNumberOfBytesWritten);

	[UnmanagedFunctionPointer(CallingConvention.StdCall)]
	private delegate int Delegate7(IntPtr lpAddress, int dwSize, int flNewProtect, ref int lpflOldProtect);

	[UnmanagedFunctionPointer(CallingConvention.StdCall)]
	private delegate IntPtr Delegate8(uint dwDesiredAccess, int bInheritHandle, uint dwProcessId);

	[UnmanagedFunctionPointer(CallingConvention.StdCall)]
	private delegate int Delegate9(IntPtr ptr);

	[Flags]
	private enum Enum0
	{

	}

	private static bool bool_0;

	private static string[] string_0;

	private static int int_0;

	private static Delegate6 delegate6_0;

	private static Delegate7 delegate7_0;

	private static byte[] byte_0;

	private static int int_1;

	private static int int_2;

	private static List<string> list_0;

	private static Delegate4 delegate4_0;

	private static uint[] uint_0;

	private static int int_3;

	[Attribute0(typeof(Attribute0.Class7<object>[]))]
	private static bool bool_1;

	private static Dictionary<int, int> dictionary_0;

	private static byte[] byte_1;

	private static string string_1;

	private static bool bool_2;

	private static object object_0;

	private static bool bool_3;

	private static object object_1;

	private static bool bool_4;

	private static bool bool_5;

	private static Delegate9 delegate9_0;

	internal static Delegate2 delegate2_0;

	private static IntPtr intptr_0;

	internal static Delegate2 delegate2_1;

	private static SortedList sortedList_0;

	private static IntPtr intptr_1;

	private static long long_0;

	private static IntPtr intptr_2;

	private static List<int> list_1;

	private static int int_4;

	internal static object object_2;

	internal static Assembly assembly_0;

	private static bool bool_6;

	private static IntPtr intptr_3;

	internal static Hashtable hashtable_0;

	private static Delegate5 delegate5_0;

	private static Delegate8 delegate8_0;

	private static int[] int_5;

	private static long long_1;

	static Class6()
	{
		bool_5 = false;
		assembly_0 = typeof(Class6).Assembly;
		uint_0 = new uint[64]
		{
			3614090360u, 3905402710u, 606105819u, 3250441966u, 4118548399u, 1200080426u, 2821735955u, 4249261313u, 1770035416u, 2336552879u,
			4294925233u, 2304563134u, 1804603682u, 4254626195u, 2792965006u, 1236535329u, 4129170786u, 3225465664u, 643717713u, 3921069994u,
			3593408605u, 38016083u, 3634488961u, 3889429448u, 568446438u, 3275163606u, 4107603335u, 1163531501u, 2850285829u, 4243563512u,
			1735328473u, 2368359562u, 4294588738u, 2272392833u, 1839030562u, 4259657740u, 2763975236u, 1272893353u, 4139469664u, 3200236656u,
			681279174u, 3936430074u, 3572445317u, 76029189u, 3654602809u, 3873151461u, 530742520u, 3299628645u, 4096336452u, 1126891415u,
			2878612391u, 4237533241u, 1700485571u, 2399980690u, 4293915773u, 2240044497u, 1873313359u, 4264355552u, 2734768916u, 1309151649u,
			4149444226u, 3174756917u, 718787259u, 3951481745u
		};
		bool_4 = false;
		bool_0 = false;
		object_2 = null;
		dictionary_0 = null;
		object_0 = new object();
		int_4 = 0;
		object_1 = new object();
		list_0 = null;
		list_1 = null;
		byte_1 = new byte[0];
		byte_0 = new byte[0];
		intptr_3 = IntPtr.Zero;
		intptr_2 = IntPtr.Zero;
		string_0 = new string[0];
		int_5 = new int[0];
		int_2 = 1;
		bool_3 = false;
		sortedList_0 = new SortedList();
		int_3 = 0;
		long_1 = 0L;
		delegate2_0 = null;
		delegate2_1 = null;
		long_0 = 0L;
		int_1 = 0;
		bool_2 = false;
		bool_6 = false;
		int_0 = 0;
		intptr_1 = IntPtr.Zero;
		bool_1 = false;
		hashtable_0 = new Hashtable();
		delegate4_0 = null;
		delegate5_0 = null;
		delegate6_0 = null;
		delegate7_0 = null;
		delegate8_0 = null;
		delegate9_0 = null;
		intptr_0 = IntPtr.Zero;
		string_1 = Encoding.Unicode.GetString(new byte[8] { 134, 123, 241, 8, 24, 98, 77, 199 });
		try
		{
			RSACryptoServiceProvider.UseMachineKeyStore = true;
		}
		catch
		{
		}
	}

	private void method_0()
	{
	}

	internal static byte[] smethod_0(object object_3)
	{
		uint[] array = new uint[16];
		uint num = (uint)((448 - ((Array)object_3).Length * 8 % 512 + 512) % 512);
		if (num == 0)
		{
			num = 512u;
		}
		uint num2 = (uint)(((Array)object_3).Length + num / 8 + 8);
		ulong num3 = (ulong)((Array)object_3).Length * 8uL;
		byte[] array2 = new byte[num2];
		for (int i = 0; i < ((Array)object_3).Length; i++)
		{
			array2[i] = ((byte[])object_3)[i];
		}
		array2[((Array)object_3).Length] |= 128;
		for (int num4 = 8; num4 > 0; num4--)
		{
			array2[num2 - num4] = (byte)((num3 >> (8 - num4) * 8) & 0xFF);
		}
		uint num5 = (uint)(array2.Length * 8) / 32u;
		uint uint_ = 1732584193u;
		uint uint_2 = 4023233417u;
		uint uint_3 = 2562383102u;
		uint uint_4 = 271733878u;
		for (uint num6 = 0u; num6 < num5 / 16; num6++)
		{
			uint num7 = num6 << 6;
			for (uint num8 = 0u; num8 < 61; num8 += 4)
			{
				array[num8 >> 2] = (uint)((array2[num7 + (num8 + 3)] << 24) | (array2[num7 + (num8 + 2)] << 16) | (array2[num7 + (num8 + 1)] << 8) | array2[num7 + num8]);
			}
			uint num9 = uint_;
			uint num10 = uint_2;
			uint num11 = uint_3;
			uint num12 = uint_4;
			smethod_1(ref uint_, uint_2, uint_3, uint_4, 0u, 7, 1u, array);
			smethod_1(ref uint_4, uint_, uint_2, uint_3, 1u, 12, 2u, array);
			smethod_1(ref uint_3, uint_4, uint_, uint_2, 2u, 17, 3u, array);
			smethod_1(ref uint_2, uint_3, uint_4, uint_, 3u, 22, 4u, array);
			smethod_1(ref uint_, uint_2, uint_3, uint_4, 4u, 7, 5u, array);
			smethod_1(ref uint_4, uint_, uint_2, uint_3, 5u, 12, 6u, array);
			smethod_1(ref uint_3, uint_4, uint_, uint_2, 6u, 17, 7u, array);
			smethod_1(ref uint_2, uint_3, uint_4, uint_, 7u, 22, 8u, array);
			smethod_1(ref uint_, uint_2, uint_3, uint_4, 8u, 7, 9u, array);
			smethod_1(ref uint_4, uint_, uint_2, uint_3, 9u, 12, 10u, array);
			smethod_1(ref uint_3, uint_4, uint_, uint_2, 10u, 17, 11u, array);
			smethod_1(ref uint_2, uint_3, uint_4, uint_, 11u, 22, 12u, array);
			smethod_1(ref uint_, uint_2, uint_3, uint_4, 12u, 7, 13u, array);
			smethod_1(ref uint_4, uint_, uint_2, uint_3, 13u, 12, 14u, array);
			smethod_1(ref uint_3, uint_4, uint_, uint_2, 14u, 17, 15u, array);
			smethod_1(ref uint_2, uint_3, uint_4, uint_, 15u, 22, 16u, array);
			smethod_2(ref uint_, uint_2, uint_3, uint_4, 1u, 5, 17u, array);
			smethod_2(ref uint_4, uint_, uint_2, uint_3, 6u, 9, 18u, array);
			smethod_2(ref uint_3, uint_4, uint_, uint_2, 11u, 14, 19u, array);
			smethod_2(ref uint_2, uint_3, uint_4, uint_, 0u, 20, 20u, array);
			smethod_2(ref uint_, uint_2, uint_3, uint_4, 5u, 5, 21u, array);
			smethod_2(ref uint_4, uint_, uint_2, uint_3, 10u, 9, 22u, array);
			smethod_2(ref uint_3, uint_4, uint_, uint_2, 15u, 14, 23u, array);
			smethod_2(ref uint_2, uint_3, uint_4, uint_, 4u, 20, 24u, array);
			smethod_2(ref uint_, uint_2, uint_3, uint_4, 9u, 5, 25u, array);
			smethod_2(ref uint_4, uint_, uint_2, uint_3, 14u, 9, 26u, array);
			smethod_2(ref uint_3, uint_4, uint_, uint_2, 3u, 14, 27u, array);
			smethod_2(ref uint_2, uint_3, uint_4, uint_, 8u, 20, 28u, array);
			smethod_2(ref uint_, uint_2, uint_3, uint_4, 13u, 5, 29u, array);
			smethod_2(ref uint_4, uint_, uint_2, uint_3, 2u, 9, 30u, array);
			smethod_2(ref uint_3, uint_4, uint_, uint_2, 7u, 14, 31u, array);
			smethod_2(ref uint_2, uint_3, uint_4, uint_, 12u, 20, 32u, array);
			smethod_3(ref uint_, uint_2, uint_3, uint_4, 5u, 4, 33u, array);
			smethod_3(ref uint_4, uint_, uint_2, uint_3, 8u, 11, 34u, array);
			smethod_3(ref uint_3, uint_4, uint_, uint_2, 11u, 16, 35u, array);
			smethod_3(ref uint_2, uint_3, uint_4, uint_, 14u, 23, 36u, array);
			smethod_3(ref uint_, uint_2, uint_3, uint_4, 1u, 4, 37u, array);
			smethod_3(ref uint_4, uint_, uint_2, uint_3, 4u, 11, 38u, array);
			smethod_3(ref uint_3, uint_4, uint_, uint_2, 7u, 16, 39u, array);
			smethod_3(ref uint_2, uint_3, uint_4, uint_, 10u, 23, 40u, array);
			smethod_3(ref uint_, uint_2, uint_3, uint_4, 13u, 4, 41u, array);
			smethod_3(ref uint_4, uint_, uint_2, uint_3, 0u, 11, 42u, array);
			smethod_3(ref uint_3, uint_4, uint_, uint_2, 3u, 16, 43u, array);
			smethod_3(ref uint_2, uint_3, uint_4, uint_, 6u, 23, 44u, array);
			smethod_3(ref uint_, uint_2, uint_3, uint_4, 9u, 4, 45u, array);
			smethod_3(ref uint_4, uint_, uint_2, uint_3, 12u, 11, 46u, array);
			smethod_3(ref uint_3, uint_4, uint_, uint_2, 15u, 16, 47u, array);
			smethod_3(ref uint_2, uint_3, uint_4, uint_, 2u, 23, 48u, array);
			smethod_4(ref uint_, uint_2, uint_3, uint_4, 0u, 6, 49u, array);
			smethod_4(ref uint_4, uint_, uint_2, uint_3, 7u, 10, 50u, array);
			smethod_4(ref uint_3, uint_4, uint_, uint_2, 14u, 15, 51u, array);
			smethod_4(ref uint_2, uint_3, uint_4, uint_, 5u, 21, 52u, array);
			smethod_4(ref uint_, uint_2, uint_3, uint_4, 12u, 6, 53u, array);
			smethod_4(ref uint_4, uint_, uint_2, uint_3, 3u, 10, 54u, array);
			smethod_4(ref uint_3, uint_4, uint_, uint_2, 10u, 15, 55u, array);
			smethod_4(ref uint_2, uint_3, uint_4, uint_, 1u, 21, 56u, array);
			smethod_4(ref uint_, uint_2, uint_3, uint_4, 8u, 6, 57u, array);
			smethod_4(ref uint_4, uint_, uint_2, uint_3, 15u, 10, 58u, array);
			smethod_4(ref uint_3, uint_4, uint_, uint_2, 6u, 15, 59u, array);
			smethod_4(ref uint_2, uint_3, uint_4, uint_, 13u, 21, 60u, array);
			smethod_4(ref uint_, uint_2, uint_3, uint_4, 4u, 6, 61u, array);
			smethod_4(ref uint_4, uint_, uint_2, uint_3, 11u, 10, 62u, array);
			smethod_4(ref uint_3, uint_4, uint_, uint_2, 2u, 15, 63u, array);
			smethod_4(ref uint_2, uint_3, uint_4, uint_, 9u, 21, 64u, array);
			uint_ += num9;
			uint_2 += num10;
			uint_3 += num11;
			uint_4 += num12;
		}
		byte[] array3 = new byte[16];
		Array.Copy(BitConverter.GetBytes(uint_), 0, array3, 0, 4);
		Array.Copy(BitConverter.GetBytes(uint_2), 0, array3, 4, 4);
		Array.Copy(BitConverter.GetBytes(uint_3), 0, array3, 8, 4);
		Array.Copy(BitConverter.GetBytes(uint_4), 0, array3, 12, 4);
		return array3;
	}

	private static void smethod_1(ref uint uint_1, uint uint_2, uint uint_3, uint uint_4, uint uint_5, ushort ushort_0, uint uint_6, object object_3)
	{
		uint_1 = uint_2 + smethod_5(uint_1 + ((uint_2 & uint_3) | (~uint_2 & uint_4)) + ((uint[])object_3)[uint_5] + uint_0[uint_6 - 1], ushort_0);
	}

	private static void smethod_2(ref uint uint_1, uint uint_2, uint uint_3, uint uint_4, uint uint_5, ushort ushort_0, uint uint_6, object object_3)
	{
		uint_1 = uint_2 + smethod_5(uint_1 + ((uint_2 & uint_4) | (uint_3 & ~uint_4)) + ((uint[])object_3)[uint_5] + uint_0[uint_6 - 1], ushort_0);
	}

	private static void smethod_3(ref uint uint_1, uint uint_2, uint uint_3, uint uint_4, uint uint_5, ushort ushort_0, uint uint_6, object object_3)
	{
		uint_1 = uint_2 + smethod_5(uint_1 + (uint_2 ^ uint_3 ^ uint_4) + ((uint[])object_3)[uint_5] + uint_0[uint_6 - 1], ushort_0);
	}

	private static void smethod_4(ref uint uint_1, uint uint_2, uint uint_3, uint uint_4, uint uint_5, ushort ushort_0, uint uint_6, object object_3)
	{
		uint_1 = uint_2 + smethod_5(uint_1 + (uint_3 ^ (uint_2 | ~uint_4)) + ((uint[])object_3)[uint_5] + uint_0[uint_6 - 1], ushort_0);
	}

	private static uint smethod_5(uint uint_1, ushort ushort_0)
	{
		return (uint_1 >> 32 - ushort_0) | (uint_1 << (int)ushort_0);
	}

	internal static bool smethod_6()
	{
		if (!bool_4)
		{
			smethod_8();
			bool_4 = true;
		}
		return bool_0;
	}

	internal Class6()
	{
	}

	private void method_1(byte[] byte_2, byte[] byte_3, byte[] byte_4)
	{
		int num = byte_4.Length % 4;
		int num2 = byte_4.Length / 4;
		byte[] array = new byte[byte_4.Length];
		int num3 = byte_2.Length / 4;
		uint num4 = 0u;
		uint num5 = 0u;
		uint num6 = 0u;
		if (num > 0)
		{
			num2++;
		}
		uint num7 = 0u;
		for (int i = 0; i < num2; i++)
		{
			int num8 = i % num3;
			int num9 = i * 4;
			num7 = (uint)(num8 * 4);
			num5 = (uint)((byte_2[num7 + 3] << 24) | (byte_2[num7 + 2] << 16) | (byte_2[num7 + 1] << 8) | byte_2[num7]);
			uint num10 = 255u;
			int num11 = 0;
			if (i == num2 - 1 && num > 0)
			{
				num6 = 0u;
				num4 += num5;
				for (int j = 0; j < num; j++)
				{
					if (j > 0)
					{
						num6 <<= 8;
					}
					num6 |= byte_4[^(1 + j)];
				}
			}
			else
			{
				num4 += num5;
				num7 = (uint)num9;
				num6 = (uint)((byte_4[num7 + 3] << 24) | (byte_4[num7 + 2] << 16) | (byte_4[num7 + 1] << 8) | byte_4[num7]);
			}
			uint num12 = num4;
			num4 = 0u;
			uint num13 = num12;
			num13 ^= num13 << 17;
			num13 += 594440812;
			num13 ^= num13 >> 3;
			num13 += 727323298;
			num13 ^= num13 << 4;
			num13 += 2650447031u;
			num13 = 3206817792u - num13;
			num4 = num12 + (uint)(double)num13;
			if (i == num2 - 1 && num > 0)
			{
				uint num14 = num4 ^ num6;
				for (int k = 0; k < num; k++)
				{
					if (k > 0)
					{
						num10 <<= 8;
						num11 += 8;
					}
					array[num9 + k] = (byte)((num14 & num10) >> num11);
				}
			}
			else
			{
				uint num15 = num4 ^ num6;
				array[num9] = (byte)(num15 & 0xFF);
				array[num9 + 1] = (byte)((num15 & 0xFF00) >> 8);
				array[num9 + 2] = (byte)((num15 & 0xFF0000) >> 16);
				array[num9 + 3] = (byte)((num15 & 0xFF000000u) >> 24);
			}
		}
		byte_1 = array;
	}

	internal static SymmetricAlgorithm smethod_7()
	{
		if (smethod_6())
		{
			return new AesCryptoServiceProvider();
		}
		try
		{
			return new RijndaelManaged();
		}
		catch
		{
			return (SymmetricAlgorithm)Activator.CreateInstance("System.Core, Version=3.5.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089", "System.Security.Cryptography.AesCryptoServiceProvider").Unwrap();
		}
	}

	internal static void smethod_8()
	{
		try
		{
			bool_0 = CryptoConfig.AllowOnlyFipsAlgorithms;
		}
		catch
		{
		}
	}

	internal static byte[] smethod_9(byte[] byte_2)
	{
		if (!smethod_6())
		{
			return new MD5CryptoServiceProvider().ComputeHash(byte_2);
		}
		return smethod_0(byte_2);
	}

	internal static void smethod_10(HashAlgorithm hashAlgorithm_0, Stream stream_0, uint uint_1, byte[] byte_2)
	{
		while (uint_1 != 0)
		{
			int num = ((uint_1 > (uint)byte_2.Length) ? byte_2.Length : ((int)uint_1));
			stream_0.Read(byte_2, 0, num);
			smethod_11(hashAlgorithm_0, byte_2, 0, num);
			uint_1 -= (uint)num;
		}
	}

	internal static void smethod_11(HashAlgorithm hashAlgorithm_0, byte[] byte_2, int int_6, int int_7)
	{
		hashAlgorithm_0.TransformBlock(byte_2, int_6, int_7, byte_2, int_6);
	}

	internal static uint smethod_12(uint uint_1, int int_6, long long_2, BinaryReader binaryReader_0)
	{
		int num = 0;
		uint num3;
		uint num4;
		while (true)
		{
			if (num < int_6)
			{
				binaryReader_0.BaseStream.Position = long_2 + (num * 40 + 8);
				uint num2 = binaryReader_0.ReadUInt32();
				num3 = binaryReader_0.ReadUInt32();
				binaryReader_0.ReadUInt32();
				num4 = binaryReader_0.ReadUInt32();
				if (num3 <= uint_1 && uint_1 < num3 + num2)
				{
					break;
				}
				num++;
				continue;
			}
			return 0u;
		}
		return num4 + uint_1 - num3;
	}

	private static void smethod_13(object object_3, int int_6)
	{
		Class11.smethod_2(0, new object[2] { object_3, int_6 }, null);
	}

	internal static string smethod_14(string string_2)
	{
		"{11111-22222-50001-00000}".Trim();
		byte[] array = Convert.FromBase64String(string_2);
		return Encoding.Unicode.GetString(array, 0, array.Length);
	}

	internal static uint smethod_15(IntPtr intptr_4, IntPtr intptr_5, IntPtr intptr_6, [MarshalAs(UnmanagedType.U4)] uint uint_1, IntPtr intptr_7, ref uint uint_2)
	{
		IntPtr ptr = intptr_6;
		if (bool_5)
		{
			ptr = intptr_5;
		}
		long num = 0L;
		num = ((IntPtr.Size != 4) ? Marshal.ReadInt64(ptr, IntPtr.Size * 2) : Marshal.ReadInt32(ptr, IntPtr.Size * 2));
		object obj = hashtable_0[num];
		if (obj != null)
		{
			Struct0 @struct = (Struct0)obj;
			IntPtr intPtr = Marshal.AllocCoTaskMem(@struct.byte_0.Length);
			Marshal.Copy(@struct.byte_0, 0, intPtr, @struct.byte_0.Length);
			if (@struct.bool_0)
			{
				intptr_7 = intPtr;
				uint_2 = (uint)@struct.byte_0.Length;
				smethod_24(intptr_7, @struct.byte_0.Length, 64, ref int_0);
				return 0u;
			}
			Marshal.WriteIntPtr(ptr, IntPtr.Size * 2, intPtr);
			Marshal.WriteInt32(ptr, IntPtr.Size * 3, @struct.byte_0.Length);
			uint result = 0u;
			if (uint_1 == 216669565 && !bool_1)
			{
				bool_1 = true;
			}
			else
			{
				result = delegate2_0(intptr_4, intptr_5, intptr_6, uint_1, intptr_7, ref uint_2);
			}
			return result;
		}
		return delegate2_0(intptr_4, intptr_5, intptr_6, uint_1, intptr_7, ref uint_2);
	}

	private static int smethod_16()
	{
		return 5;
	}

	private static void smethod_17()
	{
		try
		{
			RSACryptoServiceProvider.UseMachineKeyStore = true;
		}
		catch
		{
		}
	}

	private static Delegate smethod_18(IntPtr intptr_4, Type type_0)
	{
		return (Delegate)typeof(Marshal).GetMethod("GetDelegateForFunctionPointer", new Type[2]
		{
			typeof(IntPtr),
			typeof(Type)
		}).Invoke(null, new object[2] { intptr_4, type_0 });
	}

	internal unsafe static void smethod_19()
	{
		if (bool_3)
		{
			return;
		}
		bool_3 = true;
		long num = 0L;
		Marshal.ReadIntPtr(new IntPtr(&num), 0);
		Marshal.ReadInt32(new IntPtr(&num), 0);
		Marshal.ReadInt64(new IntPtr(&num), 0);
		Marshal.WriteIntPtr(new IntPtr(&num), 0, IntPtr.Zero);
		Marshal.WriteInt32(new IntPtr(&num), 0, 0);
		Marshal.WriteInt64(new IntPtr(&num), 0, 0L);
		Marshal.Copy(new byte[1], 0, Marshal.AllocCoTaskMem(8), 1);
		smethod_17();
		if (IntPtr.Size == 4 && Type.GetType("System.Reflection.ReflectionContext", throwOnError: false) != null)
		{
			foreach (ProcessModule module in Process.GetCurrentProcess().Modules)
			{
				if (module.ModuleName.ToLower() == "clrjit.dll")
				{
					Version version = new Version(module.FileVersionInfo.ProductMajorPart, module.FileVersionInfo.ProductMinorPart, module.FileVersionInfo.ProductBuildPart, module.FileVersionInfo.ProductPrivatePart);
					Version version2 = new Version(4, 0, 30319, 17020);
					Version version3 = new Version(4, 0, 30319, 17921);
					if (version >= version2 && version < version3)
					{
						bool_5 = true;
						break;
					}
				}
			}
		}
		Class9 @class = new Class9(assembly_0.GetManifestResourceStream("\u0095\u008a1a\u008d3\u008de\u0097v6\u0090\u0092\u0095q\u009dkm.2v\u009digp\u008e\u008c09w2l\u008f\u008aqbt"));
		@class.method_0().Position = 0L;
		byte[] array = @class.method_1((int)@class.method_0().Length);
		byte[] array2 = new byte[32];
		array2[0] = 169;
		array2[0] = 72;
		array2[0] = 145;
		array2[0] = 64;
		array2[0] = 199;
		array2[1] = 168;
		array2[1] = 125;
		array2[1] = 128;
		array2[2] = 85;
		array2[2] = 109;
		array2[2] = 39;
		array2[3] = 92;
		array2[3] = 39;
		array2[3] = 168;
		array2[3] = 226;
		array2[4] = 108;
		array2[4] = 41;
		array2[4] = 215;
		array2[5] = 155;
		array2[5] = 95;
		array2[5] = 253;
		array2[6] = 132;
		array2[6] = 72;
		array2[6] = 122;
		array2[6] = 165;
		array2[6] = 159;
		array2[7] = 146;
		array2[7] = 104;
		array2[7] = 142;
		array2[7] = 156;
		array2[7] = 228;
		array2[8] = 154;
		array2[8] = 168;
		array2[8] = 100;
		array2[8] = 133;
		array2[8] = 86;
		array2[9] = 95;
		array2[9] = 209;
		array2[9] = 129;
		array2[9] = 162;
		array2[9] = 39;
		array2[10] = 125;
		array2[10] = 104;
		array2[10] = 161;
		array2[10] = 172;
		array2[11] = 99;
		array2[11] = 159;
		array2[11] = 210;
		array2[11] = 150;
		array2[11] = 128;
		array2[11] = 137;
		array2[12] = 119;
		array2[12] = 120;
		array2[12] = 98;
		array2[12] = 127;
		array2[12] = 129;
		array2[13] = 196;
		array2[13] = 168;
		array2[13] = 118;
		array2[13] = 130;
		array2[14] = 108;
		array2[14] = 154;
		array2[14] = 35;
		array2[15] = 156;
		array2[15] = 139;
		array2[15] = 140;
		array2[15] = 115;
		array2[15] = 28;
		array2[15] = 4;
		array2[16] = 140;
		array2[16] = 132;
		array2[16] = 172;
		array2[16] = 114;
		array2[16] = 121;
		array2[17] = 160;
		array2[17] = 125;
		array2[17] = 82;
		array2[17] = 117;
		array2[17] = 77;
		array2[17] = 13;
		array2[18] = 135;
		array2[18] = 162;
		array2[18] = 156;
		array2[18] = 174;
		array2[18] = 134;
		array2[18] = 91;
		array2[19] = 132;
		array2[19] = 139;
		array2[19] = 164;
		array2[19] = 172;
		array2[19] = 174;
		array2[20] = 160;
		array2[20] = 118;
		array2[20] = 124;
		array2[20] = 21;
		array2[21] = 198;
		array2[21] = 104;
		array2[21] = 103;
		array2[22] = 98;
		array2[22] = 162;
		array2[22] = 41;
		array2[22] = 130;
		array2[22] = 172;
		array2[22] = 82;
		array2[23] = 141;
		array2[23] = 100;
		array2[23] = 104;
		array2[23] = 68;
		array2[24] = 128;
		array2[24] = 168;
		array2[24] = 110;
		array2[24] = 205;
		array2[25] = 90;
		array2[25] = 94;
		array2[25] = 89;
		array2[25] = 160;
		array2[25] = 57;
		array2[25] = 119;
		array2[26] = 213;
		array2[26] = 105;
		array2[26] = 154;
		array2[26] = 154;
		array2[26] = 55;
		array2[26] = 95;
		array2[27] = 102;
		array2[27] = 169;
		array2[27] = 213;
		array2[28] = 145;
		array2[28] = 133;
		array2[28] = 82;
		array2[29] = 224;
		array2[29] = 93;
		array2[29] = 128;
		array2[29] = 170;
		array2[30] = 129;
		array2[30] = 116;
		array2[30] = 172;
		array2[31] = 68;
		array2[31] = 151;
		array2[31] = 39;
		byte[] array3 = array2;
		byte[] array4 = new byte[16];
		array4[0] = 169;
		array4[0] = 127;
		array4[0] = 88;
		array4[0] = 109;
		array4[0] = 108;
		array4[0] = 13;
		array4[1] = 88;
		array4[1] = 110;
		array4[1] = 41;
		array4[2] = 109;
		array4[2] = 70;
		array4[2] = 39;
		array4[2] = 74;
		array4[3] = 112;
		array4[3] = 90;
		array4[3] = 98;
		array4[4] = 86;
		array4[4] = 116;
		array4[4] = 95;
		array4[4] = 103;
		array4[4] = 104;
		array4[4] = 210;
		array4[5] = 83;
		array4[5] = 165;
		array4[5] = 160;
		array4[5] = 86;
		array4[6] = 104;
		array4[6] = 142;
		array4[6] = 156;
		array4[6] = 39;
		array4[7] = 154;
		array4[7] = 168;
		array4[7] = 122;
		array4[8] = 114;
		array4[8] = 108;
		array4[8] = 121;
		array4[8] = 32;
		array4[9] = 168;
		array4[9] = 85;
		array4[9] = 174;
		array4[10] = 98;
		array4[10] = 125;
		array4[10] = 91;
		array4[10] = 175;
		array4[10] = 156;
		array4[10] = 208;
		array4[11] = 102;
		array4[11] = 218;
		array4[11] = 126;
		array4[11] = 38;
		array4[11] = 210;
		array4[12] = 177;
		array4[12] = 176;
		array4[12] = 125;
		array4[12] = 161;
		array4[12] = 204;
		array4[13] = 96;
		array4[13] = 139;
		array4[13] = 125;
		array4[13] = 103;
		array4[13] = 82;
		array4[13] = 217;
		array4[14] = 143;
		array4[14] = 156;
		array4[14] = 112;
		array4[14] = 121;
		array4[14] = 208;
		array4[15] = 140;
		array4[15] = 115;
		array4[15] = 95;
		array4[15] = 239;
		byte[] array5 = array4;
		Array.Reverse((Array)array5);
		byte[] publicKeyToken = assembly_0.GetName().GetPublicKeyToken();
		if (publicKeyToken != null && publicKeyToken.Length != 0)
		{
			array5[1] = publicKeyToken[0];
			array5[3] = publicKeyToken[1];
			array5[5] = publicKeyToken[2];
			array5[7] = publicKeyToken[3];
			array5[9] = publicKeyToken[4];
			array5[11] = publicKeyToken[5];
			array5[13] = publicKeyToken[6];
			array5[15] = publicKeyToken[7];
			Array.Clear(publicKeyToken, 0, publicKeyToken.Length);
		}
		for (int i = 0; i < array5.Length; i++)
		{
			array3[i] ^= array5[i];
		}
		byte[] array6 = array;
		int num2 = array6.Length % 4;
		int num3 = array6.Length / 4;
		byte[] array7 = new byte[array6.Length];
		int num4 = array3.Length / 4;
		uint num5 = 0u;
		uint num6 = 0u;
		uint num7 = 0u;
		if (num2 > 0)
		{
			num3++;
		}
		uint num8 = 0u;
		for (int j = 0; j < num3; j++)
		{
			int num9 = j % num4;
			int num10 = j * 4;
			num8 = (uint)(num9 * 4);
			num6 = (uint)((array3[num8 + 3] << 24) | (array3[num8 + 2] << 16) | (array3[num8 + 1] << 8) | array3[num8]);
			uint num11 = 255u;
			int num12 = 0;
			if (j == num3 - 1 && num2 > 0)
			{
				num5 += num6;
				num7 = 0u;
				for (int k = 0; k < num2; k++)
				{
					if (k > 0)
					{
						num7 <<= 8;
					}
					num7 |= array6[^(1 + k)];
				}
			}
			else
			{
				num8 = (uint)num10;
				num5 += num6;
				num7 = (uint)((array6[num8 + 3] << 24) | (array6[num8 + 2] << 16) | (array6[num8 + 1] << 8) | array6[num8]);
			}
			num5 = num5;
			uint num13 = num5;
			uint num14 = num5;
			num14 ^= num14 << 17;
			num14 += 594440812;
			num14 ^= num14 >> 3;
			num14 += 727323298;
			num14 ^= num14 << 4;
			num14 += 2650447031u;
			num14 = 3206817792u - num14;
			num5 = num13 + (uint)(double)num14;
			if (j == num3 - 1 && num2 > 0)
			{
				uint num15 = num5 ^ num7;
				for (int l = 0; l < num2; l++)
				{
					if (l > 0)
					{
						num11 <<= 8;
						num12 += 8;
					}
					array7[num10 + l] = (byte)((num15 & num11) >> num12);
				}
			}
			else
			{
				uint num16 = num5 ^ num7;
				array7[num10] = (byte)(num16 & 0xFF);
				array7[num10 + 1] = (byte)((num16 & 0xFF00) >> 8);
				array7[num10 + 2] = (byte)((num16 & 0xFF0000) >> 16);
				array7[num10 + 3] = (byte)((num16 & 0xFF000000u) >> 24);
			}
		}
		byte[] array8 = array7;
		int num17 = array8.Length / 8;
		fixed (byte* ptr = array8)
		{
			for (int m = 0; m < num17; m++)
			{
				*(long*)(ptr + m * 8) ^= 1867892290L;
			}
		}
		@class = new Class9(new MemoryStream(array8));
		@class.method_0().Position = 0L;
		long num18 = Marshal.GetHINSTANCE(assembly_0.GetModules()[0]).ToInt64();
		int int_ = 0;
		int num19 = 0;
		if (assembly_0.Location == null || assembly_0.Location.Length == 0)
		{
			num19 = 7680;
		}
		@class.method_3();
		@class.method_3();
		int num20 = @class.method_3();
		int num21 = @class.method_3();
		if (num21 == 4)
		{
			SymmetricAlgorithm symmetricAlgorithm = smethod_7();
			symmetricAlgorithm.Mode = CipherMode.CBC;
			ICryptoTransform transform = symmetricAlgorithm.CreateDecryptor(array3, array5);
			Array.Clear(array3, 0, array3.Length);
			MemoryStream memoryStream = new MemoryStream();
			CryptoStream cryptoStream = new CryptoStream(memoryStream, transform, CryptoStreamMode.Write);
			cryptoStream.Write(array, 0, array.Length);
			cryptoStream.FlushFinalBlock();
			array8 = memoryStream.ToArray();
			Array.Clear(array5, 0, array5.Length);
			memoryStream.Close();
			cryptoStream.Close();
			@class.method_4();
			num20 = @class.method_3();
			num21 = @class.method_3();
		}
		if (num21 == 1)
		{
			IntPtr zero = IntPtr.Zero;
			zero = smethod_25(56u, 1, (uint)Process.GetCurrentProcess().Id);
			if (IntPtr.Size == 4)
			{
				int_3 = Marshal.GetHINSTANCE(assembly_0.GetModules()[0]).ToInt32();
			}
			long_1 = Marshal.GetHINSTANCE(assembly_0.GetModules()[0]).ToInt64();
			IntPtr intptr_ = IntPtr.Zero;
			for (int n = 0; n < num20; n++)
			{
				IntPtr intPtr = new IntPtr(long_1 + @class.method_3() - num19);
				if (smethod_24(intPtr, 4, 4, ref int_) == 0)
				{
					smethod_24(intPtr, 4, 8, ref int_);
				}
				if (IntPtr.Size == 4)
				{
					smethod_23(zero, intPtr, BitConverter.GetBytes(@class.method_3()), 4u, out intptr_);
				}
				else
				{
					smethod_23(zero, intPtr, BitConverter.GetBytes(@class.method_3()), 4u, out intptr_);
				}
				smethod_24(intPtr, 4, int_, ref int_);
			}
			while (@class.method_0().Position < @class.method_0().Length - 1)
			{
				int num22 = @class.method_3();
				IntPtr intptr_2 = new IntPtr(long_1 + num22 - num19);
				int num23 = @class.method_3();
				if (smethod_24(intptr_2, num23 * 4, 4, ref int_) == 0)
				{
					smethod_24(intptr_2, num23 * 4, 8, ref int_);
				}
				for (int num24 = 0; num24 < num23; num24++)
				{
					Marshal.WriteInt32(new IntPtr(intptr_2.ToInt64() + num24 * 4), @class.method_3());
				}
				smethod_24(intptr_2, num23 * 4, int_, ref int_);
			}
			smethod_26(zero);
			return;
		}
		for (int num25 = 0; num25 < num20; num25++)
		{
			IntPtr intPtr2 = new IntPtr(num18 + @class.method_3() - num19);
			if (smethod_24(intPtr2, 4, 4, ref int_) == 0)
			{
				smethod_24(intPtr2, 4, 8, ref int_);
			}
			Marshal.WriteInt32(intPtr2, @class.method_3());
			smethod_24(intPtr2, 4, int_, ref int_);
		}
		hashtable_0 = new Hashtable(@class.method_3() + 1);
		Struct0 @struct = new Struct0
		{
			byte_0 = new byte[1] { 42 },
			bool_0 = false
		};
		hashtable_0.Add(0L, @struct);
		bool flag = false;
		while (@class.method_0().Position < @class.method_0().Length - 1)
		{
			int num26 = @class.method_3() - num19;
			int num27 = @class.method_3();
			flag = false;
			if (num27 >= 1879048192)
			{
				flag = true;
			}
			int num28 = @class.method_3();
			byte[] array9 = @class.method_1(num28);
			Struct0 struct2 = new Struct0
			{
				byte_0 = array9,
				bool_0 = flag
			};
			hashtable_0.Add(num18 + num26, struct2);
		}
		long_0 = Marshal.GetHINSTANCE(typeof(Class6).Assembly.GetModules()[0]).ToInt64();
		if (IntPtr.Size == 4)
		{
			int_1 = Convert.ToInt32(long_0);
		}
		byte[] bytes = new byte[12]
		{
			109, 115, 99, 111, 114, 106, 105, 116, 46, 100,
			108, 108
		};
		string text = Encoding.UTF8.GetString(bytes);
		IntPtr intPtr3 = LoadLibrary(text);
		if (intPtr3 == IntPtr.Zero)
		{
			bytes = new byte[10] { 99, 108, 114, 106, 105, 116, 46, 100, 108, 108 };
			text = Encoding.UTF8.GetString(bytes);
			intPtr3 = LoadLibrary(text);
		}
		byte[] bytes2 = new byte[6] { 103, 101, 116, 74, 105, 116 };
		string string_ = Encoding.UTF8.GetString(bytes2);
		IntPtr ptr2 = ((Delegate3)smethod_18(GetProcAddress(intPtr3, string_), typeof(Delegate3)))();
		long num29 = 0L;
		num29 = ((IntPtr.Size != 4) ? Marshal.ReadInt64(ptr2) : Marshal.ReadInt32(ptr2));
		Marshal.ReadIntPtr(ptr2, 0);
		delegate2_1 = smethod_15;
		IntPtr zero2 = IntPtr.Zero;
		zero2 = Marshal.GetFunctionPointerForDelegate((Delegate)delegate2_1);
		long num30 = 0L;
		num30 = ((IntPtr.Size != 4) ? Marshal.ReadInt64(new IntPtr(num29)) : Marshal.ReadInt32(new IntPtr(num29)));
		Process currentProcess = Process.GetCurrentProcess();
		try
		{
			foreach (ProcessModule module2 in currentProcess.Modules)
			{
				if (module2.ModuleName == text && (num30 < module2.BaseAddress.ToInt64() || num30 > module2.BaseAddress.ToInt64() + module2.ModuleMemorySize) && typeof(Class6).Assembly.EntryPoint != null)
				{
					return;
				}
			}
		}
		catch
		{
		}
		try
		{
			foreach (ProcessModule module3 in currentProcess.Modules)
			{
				if (module3.BaseAddress.ToInt64() == long_0)
				{
					num19 = 0;
					break;
				}
			}
		}
		catch
		{
		}
		delegate2_0 = null;
		try
		{
			delegate2_0 = (Delegate2)smethod_18(new IntPtr(num30), typeof(Delegate2));
		}
		catch
		{
			try
			{
				Delegate obj4 = smethod_18(new IntPtr(num30), typeof(Delegate2));
				delegate2_0 = (Delegate2)Delegate.CreateDelegate(typeof(Delegate2), obj4.Method);
			}
			catch
			{
			}
		}
		int int_2 = 0;
		if (typeof(Class6).Assembly.EntryPoint != null && typeof(Class6).Assembly.EntryPoint.GetParameters().Length == 2 && typeof(Class6).Assembly.Location != null && typeof(Class6).Assembly.Location.Length > 0)
		{
			return;
		}
		try
		{
			object value = typeof(Class6).Assembly.ManifestModule.ModuleHandle.GetType().GetField("m_ptr", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic).GetValue(typeof(Class6).Assembly.ManifestModule.ModuleHandle);
			if (value is IntPtr)
			{
				intptr_1 = (IntPtr)value;
			}
			if (value.GetType().ToString() == "System.Reflection.RuntimeModule")
			{
				intptr_1 = (IntPtr)value.GetType().GetField("m_pData", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic).GetValue(value);
			}
			MemoryStream memoryStream2 = new MemoryStream();
			memoryStream2.Write(new byte[IntPtr.Size], 0, IntPtr.Size);
			if (IntPtr.Size == 4)
			{
				memoryStream2.Write(BitConverter.GetBytes(intptr_1.ToInt32()), 0, 4);
			}
			else
			{
				memoryStream2.Write(BitConverter.GetBytes(intptr_1.ToInt64()), 0, 8);
			}
			memoryStream2.Write(new byte[IntPtr.Size], 0, IntPtr.Size);
			memoryStream2.Write(new byte[IntPtr.Size], 0, IntPtr.Size);
			memoryStream2.Position = 0L;
			byte[] array10 = memoryStream2.ToArray();
			memoryStream2.Close();
			uint nativeSizeOfCode = 0u;
			fixed (byte* value2 = array10)
			{
				delegate2_1(new IntPtr(value2), new IntPtr(value2), new IntPtr(value2), 216669565u, new IntPtr(value2), ref nativeSizeOfCode);
			}
		}
		catch
		{
		}
		RuntimeHelpers.PrepareDelegate(delegate2_0);
		RuntimeHelpers.PrepareMethod(delegate2_0.Method.MethodHandle);
		RuntimeHelpers.PrepareDelegate(delegate2_1);
		RuntimeHelpers.PrepareMethod(delegate2_1.Method.MethodHandle);
		byte[] array11 = null;
		array11 = ((IntPtr.Size != 4) ? new byte[40]
		{
			72, 184, 0, 0, 0, 0, 0, 0, 0, 0,
			73, 57, 64, 8, 116, 12, 72, 184, 0, 0,
			0, 0, 0, 0, 0, 0, 255, 224, 72, 184,
			0, 0, 0, 0, 0, 0, 0, 0, 255, 224
		} : new byte[30]
		{
			85, 139, 236, 139, 69, 16, 129, 120, 4, 125,
			29, 234, 12, 116, 7, 184, 182, 177, 74, 6,
			235, 5, 184, 182, 146, 64, 12, 93, 255, 224
		});
		IntPtr intPtr4 = smethod_22(IntPtr.Zero, (uint)array11.Length, 4096u, 64u);
		byte[] array12 = array11;
		byte[] array13 = null;
		byte[] array14 = null;
		byte[] array15 = null;
		if (IntPtr.Size == 4)
		{
			array15 = BitConverter.GetBytes(intptr_1.ToInt32());
			array13 = BitConverter.GetBytes(zero2.ToInt32());
			array14 = BitConverter.GetBytes(Convert.ToInt32(num30));
		}
		else
		{
			array15 = BitConverter.GetBytes(intptr_1.ToInt64());
			array13 = BitConverter.GetBytes(zero2.ToInt64());
			array14 = BitConverter.GetBytes(num30);
		}
		if (IntPtr.Size == 4)
		{
			array12[9] = array15[0];
			array12[10] = array15[1];
			array12[11] = array15[2];
			array12[12] = array15[3];
			array12[16] = array14[0];
			array12[17] = array14[1];
			array12[18] = array14[2];
			array12[19] = array14[3];
			array12[23] = array13[0];
			array12[24] = array13[1];
			array12[25] = array13[2];
			array12[26] = array13[3];
		}
		else
		{
			array12[2] = array15[0];
			array12[3] = array15[1];
			array12[4] = array15[2];
			array12[5] = array15[3];
			array12[6] = array15[4];
			array12[7] = array15[5];
			array12[8] = array15[6];
			array12[9] = array15[7];
			array12[18] = array14[0];
			array12[19] = array14[1];
			array12[20] = array14[2];
			array12[21] = array14[3];
			array12[22] = array14[4];
			array12[23] = array14[5];
			array12[24] = array14[6];
			array12[25] = array14[7];
			array12[30] = array13[0];
			array12[31] = array13[1];
			array12[32] = array13[2];
			array12[33] = array13[3];
			array12[34] = array13[4];
			array12[35] = array13[5];
			array12[36] = array13[6];
			array12[37] = array13[7];
		}
		Marshal.Copy(array12, 0, intPtr4, array12.Length);
		bool_2 = false;
		smethod_24(new IntPtr(num29), IntPtr.Size, 64, ref int_2);
		Marshal.WriteIntPtr(new IntPtr(num29), intPtr4);
		smethod_24(new IntPtr(num29), IntPtr.Size, int_2, ref int_2);
	}

	internal static object smethod_20(Assembly assembly_1)
	{
		try
		{
			if (File.Exists(assembly_1.Location))
			{
				return assembly_1.Location;
			}
		}
		catch
		{
		}
		try
		{
			if (File.Exists(assembly_1.GetName().CodeBase.ToString().Replace("file:///", "")))
			{
				return assembly_1.GetName().CodeBase.ToString().Replace("file:///", "");
			}
		}
		catch
		{
		}
		try
		{
			if (File.Exists(assembly_1.GetType().GetProperty("Location").GetValue(assembly_1, new object[0])
				.ToString()))
			{
				return assembly_1.GetType().GetProperty("Location").GetValue(assembly_1, new object[0])
					.ToString();
			}
		}
		catch
		{
		}
		return "";
	}

	[DllImport("kernel32")]
	public static extern IntPtr LoadLibrary(string string_2);

	[DllImport("kernel32", CharSet = CharSet.Ansi)]
	public static extern IntPtr GetProcAddress(IntPtr intptr_4, string string_2);

	private static IntPtr smethod_21(IntPtr intptr_4, string string_2, uint uint_1)
	{
		if (delegate4_0 == null)
		{
			delegate4_0 = (Delegate4)Marshal.GetDelegateForFunctionPointer(GetProcAddress(smethod_27(), "Find ".Trim() + "ResourceA"), typeof(Delegate4));
		}
		return delegate4_0(intptr_4, string_2, uint_1);
	}

	private static IntPtr smethod_22(IntPtr intptr_4, uint uint_1, uint uint_2, uint uint_3)
	{
		if (delegate5_0 == null)
		{
			delegate5_0 = (Delegate5)Marshal.GetDelegateForFunctionPointer(GetProcAddress(smethod_27(), "Virtual ".Trim() + "Alloc"), typeof(Delegate5));
		}
		return delegate5_0(intptr_4, uint_1, uint_2, uint_3);
	}

	private static int smethod_23(IntPtr intptr_4, IntPtr intptr_5, [In][Out] byte[] byte_2, uint uint_1, out IntPtr intptr_6)
	{
		if (delegate6_0 == null)
		{
			delegate6_0 = (Delegate6)Marshal.GetDelegateForFunctionPointer(GetProcAddress(smethod_27(), "Write ".Trim() + "Process ".Trim() + "Memory"), typeof(Delegate6));
		}
		return delegate6_0(intptr_4, intptr_5, byte_2, uint_1, out intptr_6);
	}

	private static int smethod_24(IntPtr intptr_4, int int_6, int int_7, ref int int_8)
	{
		if (delegate7_0 == null)
		{
			delegate7_0 = (Delegate7)Marshal.GetDelegateForFunctionPointer(GetProcAddress(smethod_27(), "Virtual ".Trim() + "Protect"), typeof(Delegate7));
		}
		return delegate7_0(intptr_4, int_6, int_7, ref int_8);
	}

	private static IntPtr smethod_25(uint uint_1, int int_6, uint uint_2)
	{
		if (delegate8_0 == null)
		{
			delegate8_0 = (Delegate8)Marshal.GetDelegateForFunctionPointer(GetProcAddress(smethod_27(), "Open ".Trim() + "Process"), typeof(Delegate8));
		}
		return delegate8_0(uint_1, int_6, uint_2);
	}

	private static int smethod_26(IntPtr intptr_4)
	{
		if (delegate9_0 == null)
		{
			delegate9_0 = (Delegate9)Marshal.GetDelegateForFunctionPointer(GetProcAddress(smethod_27(), "Close ".Trim() + "Handle"), typeof(Delegate9));
		}
		return delegate9_0(intptr_4);
	}

	[SpecialName]
	private static IntPtr smethod_27()
	{
		if (intptr_0 == IntPtr.Zero)
		{
			intptr_0 = LoadLibrary("kernel ".Trim() + "32.dll");
		}
		return intptr_0;
	}

	private static byte[] smethod_28(string string_2)
	{
		using FileStream fileStream = new FileStream(string_2, FileMode.Open, FileAccess.Read, FileShare.Read);
		int num = 0;
		int num2 = (int)fileStream.Length;
		byte[] array = new byte[num2];
		while (num2 > 0)
		{
			int num3 = fileStream.Read(array, num, num2);
			num += num3;
			num2 -= num3;
		}
		return array;
	}

	internal static byte[] smethod_29(MemoryStream memoryStream_0)
	{
		return memoryStream_0.ToArray();
	}

	private static byte[] smethod_30(byte[] byte_2)
	{
		Stream stream = new MemoryStream();
		SymmetricAlgorithm symmetricAlgorithm = smethod_7();
		symmetricAlgorithm.Key = new byte[32]
		{
			105, 76, 70, 88, 60, 78, 108, 143, 158, 7,
			141, 194, 24, 202, 152, 85, 169, 88, 247, 75,
			115, 106, 121, 73, 15, 11, 240, 98, 59, 69,
			94, 178
		};
		symmetricAlgorithm.IV = new byte[16]
		{
			121, 103, 52, 190, 196, 220, 74, 126, 100, 188,
			95, 128, 47, 51, 100, 173
		};
		CryptoStream cryptoStream = new CryptoStream(stream, symmetricAlgorithm.CreateDecryptor(), CryptoStreamMode.Write);
		cryptoStream.Write(byte_2, 0, byte_2.Length);
		cryptoStream.Close();
		return smethod_29((MemoryStream)stream);
	}

	internal static bool smethod_32(string string_2, string string_3)
	{
		if (string_2 == string_3)
		{
			return true;
		}
		if (string_2 != null && string_3 != null)
		{
			bool flag = false;
			bool flag2 = false;
			int num = 0;
			int num2 = 0;
			if (string_2.StartsWith(string_1))
			{
				flag = true;
				num = (int)(string_2[4] | ((uint)string_2[5] << 8) | ((uint)string_2[6] << 16) | ((uint)string_2[7] << 24));
			}
			if (string_3.StartsWith(string_1))
			{
				flag2 = true;
				num2 = (int)(string_3[4] | ((uint)string_3[5] << 8) | ((uint)string_3[6] << 16) | ((uint)string_3[7] << 24));
			}
			if (!flag && !flag2)
			{
				return false;
			}
			return num == num2;
		}
		return false;
	}

	private byte[] method_2()
	{
		return null;
	}

	private byte[] method_3()
	{
		return null;
	}

	private byte[] method_4()
	{
		_ = "{11111-22222-20001-00001}".Length;
		return new byte[2] { 1, 2 };
	}

	private byte[] method_5()
	{
		_ = "{11111-22222-20001-00002}".Length;
		return new byte[2] { 1, 2 };
	}

	private byte[] method_6()
	{
		return null;
	}

	private byte[] method_7()
	{
		return null;
	}

	internal byte[] method_8()
	{
		_ = "{11111-22222-40001-00001}".Length;
		return new byte[2] { 1, 2 };
	}

	internal byte[] method_9()
	{
		_ = "{11111-22222-40001-00002}".Length;
		return new byte[2] { 1, 2 };
	}

	internal byte[] method_10()
	{
		_ = "{11111-22222-50001-00001}".Length;
		return new byte[2] { 1, 2 };
	}

	internal byte[] method_11()
	{
		_ = "{11111-22222-50001-00002}".Length;
		return new byte[2] { 1, 2 };
	}

	internal static object smethod_33(Class9 class9_0)
	{
		return class9_0.method_0();
	}

	internal static void smethod_34(Stream stream_0, long long_2)
	{
		stream_0.Position = long_2;
	}

	internal static long smethod_35(Stream stream_0)
	{
		return stream_0.Length;
	}

	internal static object smethod_36(Class9 class9_0, int int_6)
	{
		return class9_0.method_1(int_6);
	}

	internal static void smethod_37(Class9 class9_0)
	{
		class9_0.method_4();
	}

	internal static void smethod_38(Array array_0)
	{
		Array.Reverse(array_0);
	}

	internal static object smethod_39(Assembly assembly_1)
	{
		return assembly_1.GetName();
	}

	internal static object smethod_40(AssemblyName assemblyName_0)
	{
		return assemblyName_0.GetPublicKeyToken();
	}

	internal static object smethod_41()
	{
		return smethod_7();
	}

	internal static void smethod_42(SymmetricAlgorithm symmetricAlgorithm_0, CipherMode cipherMode_0)
	{
		symmetricAlgorithm_0.Mode = cipherMode_0;
	}

	internal static object smethod_43(SymmetricAlgorithm symmetricAlgorithm_0, byte[] byte_2, byte[] byte_3)
	{
		return symmetricAlgorithm_0.CreateDecryptor(byte_2, byte_3);
	}

	internal static object smethod_44()
	{
		return new MemoryStream();
	}

	internal static void smethod_45(Stream stream_0, byte[] byte_2, int int_6, int int_7)
	{
		stream_0.Write(byte_2, int_6, int_7);
	}

	internal static void smethod_46(CryptoStream cryptoStream_0)
	{
		cryptoStream_0.FlushFinalBlock();
	}

	internal static object smethod_47(MemoryStream memoryStream_0)
	{
		return smethod_29(memoryStream_0);
	}

	internal static void smethod_48(Stream stream_0)
	{
		stream_0.Close();
	}

	internal static object smethod_49(Assembly assembly_1)
	{
		return assembly_1.EntryPoint;
	}

	internal static bool smethod_50(MethodInfo methodInfo_0, MethodInfo methodInfo_1)
	{
		return methodInfo_0 == methodInfo_1;
	}

	internal static bool smethod_51()
	{
		return true;
	}

	internal static object smethod_52()
	{
		return null;
	}

	private static int Y49()
	{
		return 1;
	}

	internal static IntPtr smethod_53(IntPtr intptr_4, int int_6)
	{
		return Marshal.ReadIntPtr(intptr_4, int_6);
	}

	internal static int smethod_54(IntPtr intptr_4, int int_6)
	{
		return Marshal.ReadInt32(intptr_4, int_6);
	}

	internal static long smethod_55(IntPtr intptr_4, int int_6)
	{
		return Marshal.ReadInt64(intptr_4, int_6);
	}

	internal static void smethod_56(IntPtr intptr_4, int int_6, IntPtr intptr_5)
	{
		Marshal.WriteIntPtr(intptr_4, int_6, intptr_5);
	}

	internal static void smethod_57(IntPtr intptr_4, int int_6, int int_7)
	{
		Marshal.WriteInt32(intptr_4, int_6, int_7);
	}

	internal static void smethod_58(IntPtr intptr_4, int int_6, long long_2)
	{
		Marshal.WriteInt64(intptr_4, int_6, long_2);
	}

	internal static IntPtr smethod_59(int int_6)
	{
		return Marshal.AllocCoTaskMem(int_6);
	}

	internal static void smethod_60(byte[] byte_2, int int_6, IntPtr intptr_4, int int_7)
	{
		Marshal.Copy(byte_2, int_6, intptr_4, int_7);
	}

	internal static void smethod_61()
	{
		smethod_17();
	}

	internal static object smethod_62()
	{
		return Process.GetCurrentProcess();
	}

	internal static object smethod_63(Process process_0)
	{
		return process_0.MainModule;
	}

	internal static IntPtr smethod_64(ProcessModule processModule_0)
	{
		return processModule_0.BaseAddress;
	}

	internal static IntPtr smethod_65(IntPtr intptr_4, string string_2, uint uint_1)
	{
		return smethod_21(intptr_4, string_2, uint_1);
	}

	internal static bool smethod_66(IntPtr intptr_4, IntPtr intptr_5)
	{
		return intptr_4 != intptr_5;
	}

	internal static int smethod_68()
	{
		return IntPtr.Size;
	}

	internal static Type smethod_69(string string_2, bool bool_7)
	{
		return Type.GetType(string_2, bool_7);
	}

	internal static bool smethod_70(Type type_0, Type type_1)
	{
		return type_0 != type_1;
	}

	internal static object smethod_71(Process process_0)
	{
		return process_0.Modules;
	}

	internal static object smethod_72(ReadOnlyCollectionBase readOnlyCollectionBase_0)
	{
		return readOnlyCollectionBase_0.GetEnumerator();
	}

	internal static object smethod_73(IEnumerator ienumerator_0)
	{
		return ienumerator_0.Current;
	}

	internal static object smethod_74(ProcessModule processModule_0)
	{
		return processModule_0.ModuleName;
	}

	internal static object smethod_75(string string_2)
	{
		return string_2.ToLower();
	}

	internal static bool smethod_76(string string_2, string string_3)
	{
		return string_2 == string_3;
	}

	internal static object smethod_77(ProcessModule processModule_0)
	{
		return processModule_0.FileVersionInfo;
	}

	internal static int smethod_78(FileVersionInfo fileVersionInfo_0)
	{
		return fileVersionInfo_0.ProductMajorPart;
	}

	internal static int smethod_79(FileVersionInfo fileVersionInfo_0)
	{
		return fileVersionInfo_0.ProductMinorPart;
	}

	internal static int smethod_80(FileVersionInfo fileVersionInfo_0)
	{
		return fileVersionInfo_0.ProductBuildPart;
	}

	internal static int smethod_81(FileVersionInfo fileVersionInfo_0)
	{
		return fileVersionInfo_0.ProductPrivatePart;
	}

	internal static bool smethod_82(Version version_0, Version version_1)
	{
		return version_0 >= version_1;
	}

	internal static bool smethod_83(Version version_0, Version version_1)
	{
		return version_0 < version_1;
	}

	internal static bool smethod_84(IEnumerator ienumerator_0)
	{
		return ienumerator_0.MoveNext();
	}

	internal static void smethod_85(IDisposable idisposable_0)
	{
		idisposable_0.Dispose();
	}

	internal static object smethod_86(Assembly assembly_1, string string_2)
	{
		return assembly_1.GetManifestResourceStream(string_2);
	}

	internal static object smethod_87(Class9 class9_0)
	{
		return class9_0.method_0();
	}

	internal static void smethod_88(Stream stream_0, long long_2)
	{
		stream_0.Position = long_2;
	}

	internal static long smethod_89(Stream stream_0)
	{
		return stream_0.Length;
	}

	internal static object smethod_90(Class9 class9_0, int int_6)
	{
		return class9_0.method_1(int_6);
	}

	internal static void smethod_91(Array array_0)
	{
		Array.Reverse(array_0);
	}

	internal static object smethod_92(Assembly assembly_1)
	{
		return assembly_1.GetName();
	}

	internal static object smethod_93(AssemblyName assemblyName_0)
	{
		return assemblyName_0.GetPublicKeyToken();
	}

	internal static void smethod_94(Array array_0, int int_6, int int_7)
	{
		Array.Clear(array_0, int_6, int_7);
	}

	internal static object smethod_95(Assembly assembly_1)
	{
		return assembly_1.GetModules();
	}

	internal static IntPtr smethod_96(Module module_0)
	{
		return Marshal.GetHINSTANCE(module_0);
	}

	internal static object smethod_97(Assembly assembly_1)
	{
		return assembly_1.Location;
	}

	internal static int smethod_98(string string_2)
	{
		return string_2.Length;
	}

	internal static int smethod_99(Class9 class9_0)
	{
		return class9_0.method_3();
	}

	internal static object smethod_100()
	{
		return smethod_7();
	}

	internal static void smethod_101(SymmetricAlgorithm symmetricAlgorithm_0, CipherMode cipherMode_0)
	{
		symmetricAlgorithm_0.Mode = cipherMode_0;
	}

	internal static object smethod_102(SymmetricAlgorithm symmetricAlgorithm_0, byte[] byte_2, byte[] byte_3)
	{
		return symmetricAlgorithm_0.CreateDecryptor(byte_2, byte_3);
	}

	internal static void smethod_103(Stream stream_0, byte[] byte_2, int int_6, int int_7)
	{
		stream_0.Write(byte_2, int_6, int_7);
	}

	internal static void smethod_104(CryptoStream cryptoStream_0)
	{
		cryptoStream_0.FlushFinalBlock();
	}

	internal static object smethod_105(MemoryStream memoryStream_0)
	{
		return memoryStream_0.ToArray();
	}

	internal static void smethod_106(Stream stream_0)
	{
		stream_0.Close();
	}

	internal static void smethod_107(Class9 class9_0)
	{
		class9_0.method_4();
	}

	internal static int smethod_108(Process process_0)
	{
		return process_0.Id;
	}

	internal static IntPtr smethod_109(uint uint_1, int int_6, uint uint_2)
	{
		return smethod_25(uint_1, int_6, uint_2);
	}

	internal static object smethod_110(int int_6)
	{
		return BitConverter.GetBytes(int_6);
	}

	internal static long smethod_111(Stream stream_0)
	{
		return stream_0.Position;
	}

	internal static void smethod_112(IntPtr intptr_4, int int_6)
	{
		Marshal.WriteInt32(intptr_4, int_6);
	}

	internal static int smethod_113(IntPtr intptr_4)
	{
		return smethod_26(intptr_4);
	}

	internal static void smethod_114(Hashtable hashtable_1, object object_3, object object_4)
	{
		hashtable_1.Add(object_3, object_4);
	}

	internal static Type smethod_115(RuntimeTypeHandle runtimeTypeHandle_0)
	{
		return Type.GetTypeFromHandle(runtimeTypeHandle_0);
	}

	internal static int smethod_116(long long_2)
	{
		return Convert.ToInt32(long_2);
	}

	internal static object smethod_117()
	{
		return Encoding.UTF8;
	}

	internal static object smethod_118(Encoding encoding_0, byte[] byte_2)
	{
		return encoding_0.GetString(byte_2);
	}

	internal static bool smethod_119(IntPtr intptr_4, IntPtr intptr_5)
	{
		return intptr_4 == intptr_5;
	}

	internal static object smethod_120(IntPtr intptr_4, Type type_0)
	{
		return smethod_18(intptr_4, type_0);
	}

	internal static int smethod_122(IntPtr intptr_4)
	{
		return Marshal.ReadInt32(intptr_4);
	}

	internal static long smethod_123(IntPtr intptr_4)
	{
		return Marshal.ReadInt64(intptr_4);
	}

	internal static IntPtr smethod_124(Delegate delegate_0)
	{
		return Marshal.GetFunctionPointerForDelegate(delegate_0);
	}

	internal static int smethod_125(ProcessModule processModule_0)
	{
		return processModule_0.ModuleMemorySize;
	}

	internal static object smethod_126(Assembly assembly_1)
	{
		return assembly_1.EntryPoint;
	}

	internal static bool smethod_127(MethodInfo methodInfo_0, MethodInfo methodInfo_1)
	{
		return methodInfo_0 != methodInfo_1;
	}

	internal static object smethod_128(Delegate delegate_0)
	{
		return delegate_0.Method;
	}

	internal static object smethod_129(Type type_0, MethodInfo methodInfo_0)
	{
		return Delegate.CreateDelegate(type_0, methodInfo_0);
	}

	internal static object smethod_130(MethodBase methodBase_0)
	{
		return methodBase_0.GetParameters();
	}

	internal static object smethod_131(Assembly assembly_1)
	{
		return assembly_1.ManifestModule;
	}

	internal static ModuleHandle smethod_132(Module module_0)
	{
		return module_0.ModuleHandle;
	}

	internal static Type smethod_133(object object_3)
	{
		return object_3.GetType();
	}

	internal static object smethod_134(FieldInfo fieldInfo_0, object object_3)
	{
		return fieldInfo_0.GetValue(object_3);
	}

	internal static object smethod_135(long long_2)
	{
		return BitConverter.GetBytes(long_2);
	}

	internal static void smethod_136(Delegate delegate_0)
	{
		RuntimeHelpers.PrepareDelegate(delegate_0);
	}

	internal static RuntimeMethodHandle smethod_137(MethodBase methodBase_0)
	{
		return methodBase_0.MethodHandle;
	}

	internal static void smethod_138(RuntimeMethodHandle runtimeMethodHandle_0)
	{
		RuntimeHelpers.PrepareMethod(runtimeMethodHandle_0);
	}

	internal static void smethod_139(Array array_0, RuntimeFieldHandle runtimeFieldHandle_0)
	{
		RuntimeHelpers.InitializeArray(array_0, runtimeFieldHandle_0);
	}

	internal static IntPtr smethod_140(IntPtr intptr_4, uint uint_1, uint uint_2, uint uint_3)
	{
		return smethod_22(intptr_4, uint_1, uint_2, uint_3);
	}

	internal static void smethod_141(IntPtr intptr_4, IntPtr intptr_5)
	{
		Marshal.WriteIntPtr(intptr_4, intptr_5);
	}

	internal static bool smethod_142()
	{
		return true;
	}

	internal static object smethod_143()
	{
		return null;
	}
}
