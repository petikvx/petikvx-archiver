using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Reflection.Emit;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;

namespace ns0;

internal class Class11
{
	[StructLayout(LayoutKind.Explicit)]
	public struct Struct1
	{
		[FieldOffset(0)]
		public byte byte_0;

		[FieldOffset(0)]
		public sbyte sbyte_0;

		[FieldOffset(0)]
		public ushort ushort_0;

		[FieldOffset(0)]
		public short short_0;

		[FieldOffset(0)]
		public uint uint_0;

		[FieldOffset(0)]
		public int int_0;
	}

	private class Class24 : Class23
	{
		public Struct1 struct1_0;

		public Enum1 enum1_0;

		internal override void vmethod_10(Class22 class22_0)
		{
			struct1_0 = ((Class24)class22_0).struct1_0;
			enum1_0 = ((Class24)class22_0).enum1_0;
		}

		internal override void vmethod_2(Class22 class22_0)
		{
			vmethod_10(class22_0);
		}

		public Class24(bool bool_0)
		{
			enum4_0 = (Enum4)1;
			if (!bool_0)
			{
				struct1_0.int_0 = 0;
			}
			else
			{
				struct1_0.int_0 = 1;
			}
			enum1_0 = (Enum1)11;
		}

		public Class24(Class24 class24_0)
		{
			enum4_0 = class24_0.enum4_0;
			struct1_0.int_0 = class24_0.struct1_0.int_0;
			enum1_0 = class24_0.enum1_0;
		}

		public override Class23 vmethod_74()
		{
			return new Class24(this);
		}

		public Class24(int int_0)
		{
			enum4_0 = (Enum4)1;
			struct1_0.int_0 = int_0;
			enum1_0 = (Enum1)5;
		}

		public Class24(uint uint_0)
		{
			enum4_0 = (Enum4)1;
			struct1_0.uint_0 = uint_0;
			enum1_0 = (Enum1)6;
		}

		public Class24(int int_0, Enum1 enum1_1)
		{
			enum4_0 = (Enum4)1;
			struct1_0.int_0 = int_0;
			enum1_0 = enum1_1;
		}

		public Class24(uint uint_0, Enum1 enum1_1)
		{
			enum4_0 = (Enum4)1;
			struct1_0.uint_0 = uint_0;
			enum1_0 = enum1_1;
		}

		public override bool vmethod_11()
		{
			switch (enum1_0)
			{
			default:
				return struct1_0.uint_0 == 0;
			case (Enum1)1:
			case (Enum1)3:
			case (Enum1)5:
			case (Enum1)7:
			case (Enum1)11:
			case (Enum1)15:
				return struct1_0.int_0 == 0;
			}
		}

		public override bool vmethod_12()
		{
			return !vmethod_11();
		}

		public override Class22 vmethod_13(Enum1 enum1_1)
		{
			return enum1_1 switch
			{
				(Enum1)1 => vmethod_15(), 
				(Enum1)2 => vmethod_16(), 
				(Enum1)3 => vmethod_17(), 
				(Enum1)4 => vmethod_18(), 
				(Enum1)5 => vmethod_19(), 
				(Enum1)6 => vmethod_20(), 
				(Enum1)11 => vmethod_14(), 
				(Enum1)15 => method_7(), 
				(Enum1)16 => vmethod_74(), 
				_ => throw new Exception(((Enum5)4/*cast due to .constrained prefix*/).ToString()), 
			};
		}

		internal override object vmethod_4(Type type_0)
		{
			if (type_0 != null && type_0.IsByRef)
			{
				type_0 = type_0.GetElementType();
			}
			if (!(type_0 == null) && !(type_0 == typeof(object)))
			{
				if (type_0 == typeof(int))
				{
					return struct1_0.int_0;
				}
				if (!(type_0 == typeof(uint)))
				{
					if (!(type_0 == typeof(short)))
					{
						if (!(type_0 == typeof(ushort)))
						{
							if (type_0 == typeof(byte))
							{
								return struct1_0.byte_0;
							}
							if (!(type_0 == typeof(sbyte)))
							{
								if (!(type_0 == typeof(bool)))
								{
									if (!(type_0 == typeof(long)))
									{
										if (!(type_0 == typeof(ulong)))
										{
											if (type_0 == typeof(char))
											{
												return (char)struct1_0.int_0;
											}
											if (type_0 == typeof(IntPtr))
											{
												return new IntPtr(struct1_0.int_0);
											}
											if (!(type_0 == typeof(UIntPtr)))
											{
												if (!type_0.IsEnum)
												{
													throw new Exception1();
												}
												return method_6(type_0);
											}
											return new UIntPtr(struct1_0.uint_0);
										}
										return (ulong)struct1_0.uint_0;
									}
									return (long)struct1_0.int_0;
								}
								return !vmethod_11();
							}
							return struct1_0.sbyte_0;
						}
						return struct1_0.ushort_0;
					}
					return struct1_0.short_0;
				}
				return struct1_0.uint_0;
			}
			return enum1_0 switch
			{
				(Enum1)1 => struct1_0.sbyte_0, 
				(Enum1)2 => struct1_0.byte_0, 
				(Enum1)3 => struct1_0.short_0, 
				(Enum1)4 => struct1_0.ushort_0, 
				(Enum1)5 => struct1_0.int_0, 
				(Enum1)6 => struct1_0.uint_0, 
				(Enum1)7 => (long)struct1_0.int_0, 
				(Enum1)8 => (ulong)struct1_0.uint_0, 
				(Enum1)11 => vmethod_12(), 
				(Enum1)15 => (char)struct1_0.int_0, 
				_ => struct1_0.int_0, 
			};
		}

		internal object method_6(Type type_0)
		{
			Type underlyingType = Enum.GetUnderlyingType(type_0);
			if (underlyingType == typeof(int))
			{
				return Enum.ToObject(type_0, struct1_0.int_0);
			}
			if (underlyingType == typeof(uint))
			{
				return Enum.ToObject(type_0, struct1_0.uint_0);
			}
			if (!(underlyingType == typeof(short)))
			{
				if (underlyingType == typeof(ushort))
				{
					return Enum.ToObject(type_0, struct1_0.ushort_0);
				}
				if (underlyingType == typeof(byte))
				{
					return Enum.ToObject(type_0, struct1_0.byte_0);
				}
				if (underlyingType == typeof(sbyte))
				{
					return Enum.ToObject(type_0, struct1_0.sbyte_0);
				}
				if (underlyingType == typeof(long))
				{
					return Enum.ToObject(type_0, (long)struct1_0.int_0);
				}
				if (underlyingType == typeof(ulong))
				{
					return Enum.ToObject(type_0, (ulong)struct1_0.uint_0);
				}
				if (underlyingType == typeof(char))
				{
					return Enum.ToObject(type_0, (ushort)struct1_0.int_0);
				}
				return Enum.ToObject(type_0, struct1_0.int_0);
			}
			return Enum.ToObject(type_0, struct1_0.short_0);
		}

		public override Class24 vmethod_14()
		{
			return new Class24((!vmethod_11()) ? 1 : 0);
		}

		internal override bool vmethod_7()
		{
			return vmethod_12();
		}

		public override Class24 vmethod_15()
		{
			return new Class24(struct1_0.sbyte_0, (Enum1)1);
		}

		public Class24 method_7()
		{
			return new Class24(struct1_0.int_0, (Enum1)15);
		}

		public override Class24 vmethod_16()
		{
			return new Class24((uint)struct1_0.byte_0, (Enum1)2);
		}

		public override Class24 vmethod_17()
		{
			return new Class24(struct1_0.short_0, (Enum1)3);
		}

		public override Class24 vmethod_18()
		{
			return new Class24((uint)struct1_0.ushort_0, (Enum1)4);
		}

		public override Class24 vmethod_19()
		{
			return new Class24(struct1_0.int_0, (Enum1)5);
		}

		public override Class24 vmethod_20()
		{
			return new Class24(struct1_0.uint_0, (Enum1)6);
		}

		public override Class25 vmethod_21()
		{
			return new Class25(struct1_0.int_0, (Enum1)7);
		}

		public override Class25 vmethod_22()
		{
			return new Class25((ulong)struct1_0.uint_0, (Enum1)8);
		}

		public override Class24 vmethod_23()
		{
			return vmethod_15();
		}

		public override Class24 vmethod_24()
		{
			return vmethod_17();
		}

		public override Class24 vmethod_25()
		{
			return vmethod_19();
		}

		public override Class25 vmethod_26()
		{
			return vmethod_21();
		}

		public override Class24 vmethod_27()
		{
			return vmethod_16();
		}

		public override Class24 vmethod_28()
		{
			return vmethod_18();
		}

		public override Class24 vmethod_29()
		{
			return vmethod_20();
		}

		public override Class25 vmethod_30()
		{
			return vmethod_22();
		}

		public override Class24 vmethod_31()
		{
			return new Class24(checked((sbyte)struct1_0.int_0), (Enum1)1);
		}

		public override Class24 vmethod_32()
		{
			return new Class24(checked((sbyte)struct1_0.uint_0), (Enum1)1);
		}

		public override Class24 vmethod_33()
		{
			return new Class24(checked((short)struct1_0.int_0), (Enum1)3);
		}

		public override Class24 vmethod_34()
		{
			return new Class24(checked((short)struct1_0.uint_0), (Enum1)3);
		}

		public override Class24 vmethod_35()
		{
			return new Class24(struct1_0.int_0, (Enum1)5);
		}

		public override Class24 vmethod_36()
		{
			return new Class24(checked((int)struct1_0.uint_0), (Enum1)5);
		}

		public override Class25 vmethod_37()
		{
			return new Class25(struct1_0.int_0, (Enum1)7);
		}

		public override Class25 vmethod_38()
		{
			return new Class25(struct1_0.uint_0, (Enum1)7);
		}

		public override Class24 vmethod_39()
		{
			return new Class24(checked((byte)struct1_0.int_0), (Enum1)2);
		}

		public override Class24 vmethod_40()
		{
			return new Class24(checked((byte)struct1_0.uint_0), (Enum1)2);
		}

		public override Class24 vmethod_41()
		{
			return new Class24(checked((ushort)struct1_0.int_0), (Enum1)4);
		}

		public override Class24 vmethod_42()
		{
			return new Class24(checked((ushort)struct1_0.uint_0), (Enum1)4);
		}

		public override Class24 vmethod_43()
		{
			return new Class24(checked((uint)struct1_0.int_0), (Enum1)6);
		}

		public override Class24 vmethod_44()
		{
			return new Class24(struct1_0.uint_0, (Enum1)6);
		}

		public override Class25 vmethod_45()
		{
			return new Class25(checked((ulong)struct1_0.int_0), (Enum1)8);
		}

		public override Class25 vmethod_46()
		{
			return new Class25((ulong)struct1_0.uint_0, (Enum1)8);
		}

		public override Class27 vmethod_47()
		{
			return new Class27(struct1_0.int_0);
		}

		public override Class27 vmethod_48()
		{
			return new Class27((double)struct1_0.int_0);
		}

		public override Class27 vmethod_49()
		{
			return new Class27((double)struct1_0.uint_0);
		}

		public override Class26 vmethod_50()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_26().struct2_0.long_0);
			}
			return new Class26(vmethod_25().struct1_0.int_0);
		}

		public override Class26 vmethod_51()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_30().struct2_0.ulong_0);
			}
			return new Class26((ulong)vmethod_29().struct1_0.uint_0);
		}

		public override Class26 vmethod_52()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_37().struct2_0.long_0);
			}
			return new Class26(vmethod_35().struct1_0.int_0);
		}

		public override Class26 vmethod_53()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_45().struct2_0.ulong_0);
			}
			return new Class26((ulong)vmethod_43().struct1_0.uint_0);
		}

		public override Class26 vmethod_54()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_38().struct2_0.long_0);
			}
			return new Class26(vmethod_36().struct1_0.int_0);
		}

		public override Class26 vmethod_55()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_46().struct2_0.ulong_0);
			}
			return new Class26((ulong)vmethod_44().struct1_0.uint_0);
		}

		public override Class22 vmethod_56()
		{
			switch (enum1_0)
			{
			default:
				return new Class24((int)(0L - (long)struct1_0.uint_0));
			case (Enum1)1:
			case (Enum1)3:
			case (Enum1)5:
			case (Enum1)11:
			case (Enum1)15:
				return new Class24(-struct1_0.int_0);
			}
		}

		public override Class22 vmethod_57(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					return ((Class26)class22_0).vmethod_57(this);
				}
				throw new Exception1();
			}
			return new Class24(struct1_0.int_0 + ((Class24)class22_0).struct1_0.int_0);
		}

		public override Class22 vmethod_58(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				return ((Class26)class22_0).vmethod_58(this);
			}
			return new Class24(checked(struct1_0.int_0 + ((Class24)class22_0).struct1_0.int_0));
		}

		public override Class22 vmethod_59(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					return ((Class26)class22_0).vmethod_59(this);
				}
				throw new Exception1();
			}
			return new Class24(checked(struct1_0.uint_0 + ((Class24)class22_0).struct1_0.uint_0));
		}

		public override Class22 vmethod_60(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				return new Class24(struct1_0.int_0 - ((Class24)class22_0).struct1_0.int_0);
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			return ((Class26)class22_0).method_8(this);
		}

		public override Class22 vmethod_61(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					return ((Class26)class22_0).method_9(this);
				}
				throw new Exception1();
			}
			return new Class24(checked(struct1_0.int_0 - ((Class24)class22_0).struct1_0.int_0));
		}

		public override Class22 vmethod_62(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				return ((Class26)class22_0).method_10(this);
			}
			return new Class24(checked(struct1_0.uint_0 - ((Class24)class22_0).struct1_0.uint_0));
		}

		public override Class22 vmethod_63(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				return new Class24(struct1_0.int_0 * ((Class24)class22_0).struct1_0.int_0);
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			return ((Class26)class22_0).vmethod_63(this);
		}

		public override Class22 vmethod_64(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				return new Class24(checked(struct1_0.int_0 * ((Class24)class22_0).struct1_0.int_0));
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			return ((Class26)class22_0).vmethod_64(this);
		}

		public override Class22 vmethod_65(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				return ((Class26)class22_0).vmethod_65(this);
			}
			return new Class24(checked(struct1_0.uint_0 * ((Class24)class22_0).struct1_0.uint_0));
		}

		public override Class22 vmethod_66(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					return ((Class26)class22_0).method_11(this);
				}
				throw new Exception1();
			}
			return new Class24(struct1_0.int_0 / ((Class24)class22_0).struct1_0.int_0);
		}

		public override Class22 vmethod_67(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				return new Class24(struct1_0.uint_0 / ((Class24)class22_0).struct1_0.uint_0);
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			return ((Class26)class22_0).method_12(this);
		}

		public override Class22 vmethod_68(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				return new Class24(struct1_0.int_0 % ((Class24)class22_0).struct1_0.int_0);
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			return ((Class26)class22_0).method_13(this);
		}

		public override Class22 vmethod_69(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					return ((Class26)class22_0).method_14(this);
				}
				throw new Exception1();
			}
			return new Class24(struct1_0.uint_0 % ((Class24)class22_0).struct1_0.uint_0);
		}

		public override Class22 vmethod_70(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				return new Class24(struct1_0.int_0 & ((Class24)class22_0).struct1_0.int_0);
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			return ((Class26)class22_0).vmethod_70(this);
		}

		public override Class22 vmethod_71(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					return ((Class26)class22_0).vmethod_71(this);
				}
				throw new Exception1();
			}
			return new Class24(struct1_0.int_0 | ((Class24)class22_0).struct1_0.int_0);
		}

		public override Class22 vmethod_72()
		{
			return new Class24(~struct1_0.int_0);
		}

		public override Class22 vmethod_73(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					return ((Class26)class22_0).vmethod_73(this);
				}
				throw new Exception1();
			}
			return new Class24(struct1_0.int_0 ^ ((Class24)class22_0).struct1_0.int_0);
		}

		public override Class22 vmethod_75(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				return ((Class26)class22_0).method_17(this);
			}
			return new Class24(struct1_0.int_0 << ((Class24)class22_0).struct1_0.int_0);
		}

		public override Class22 vmethod_76(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				return new Class24(struct1_0.int_0 >> ((Class24)class22_0).struct1_0.int_0);
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			return ((Class26)class22_0).method_16(this);
		}

		public override Class22 vmethod_77(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				return new Class24(struct1_0.uint_0 >> ((Class24)class22_0).struct1_0.int_0);
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			return ((Class26)class22_0).method_15(this);
		}

		public override string ToString()
		{
			switch (enum1_0)
			{
			default:
				return struct1_0.uint_0.ToString();
			case (Enum1)1:
			case (Enum1)3:
			case (Enum1)5:
			case (Enum1)11:
				return struct1_0.int_0.ToString();
			}
		}

		internal override Class22 vmethod_8()
		{
			return this;
		}

		internal override bool vmethod_9()
		{
			return true;
		}

		internal override bool vmethod_5(Class22 class22_0)
		{
			if (!class22_0.method_0())
			{
				if (class22_0.vmethod_0())
				{
					return ((Class28)class22_0).vmethod_5(this);
				}
				Class22 @class = class22_0.vmethod_8();
				if (@class.vmethod_9())
				{
					if (@class.method_3())
					{
						return false;
					}
					if (!@class.method_1())
					{
						return ((Class26)@class).vmethod_5(this);
					}
					return struct1_0.int_0 == ((Class24)@class).struct1_0.int_0;
				}
				return false;
			}
			return ((Class34)class22_0).vmethod_5(this);
		}

		private static Class23 smethod_4(Class22 class22_0)
		{
			Class23 @class = class22_0 as Class23;
			if (@class == null && class22_0.vmethod_0())
			{
				@class = class22_0.vmethod_8() as Class23;
			}
			return @class;
		}

		internal override bool vmethod_6(Class22 class22_0)
		{
			if (!class22_0.method_0())
			{
				if (class22_0.vmethod_0())
				{
					return ((Class28)class22_0).vmethod_6(this);
				}
				Class22 @class = class22_0.vmethod_8();
				if (@class.vmethod_9())
				{
					if (!@class.method_3())
					{
						if (@class.method_1())
						{
							return struct1_0.uint_0 != ((Class24)@class).struct1_0.uint_0;
						}
						return ((Class26)@class).vmethod_6(this);
					}
					return false;
				}
				return false;
			}
			return false;
		}

		public override bool vmethod_78(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				return ((Class26)class22_0).vmethod_82(this);
			}
			return struct1_0.int_0 >= ((Class24)class22_0).struct1_0.int_0;
		}

		public override bool vmethod_79(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				return ((Class26)class22_0).vmethod_83(this);
			}
			return struct1_0.uint_0 >= ((Class24)class22_0).struct1_0.uint_0;
		}

		public override bool vmethod_80(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					return ((Class26)class22_0).vmethod_84(this);
				}
				throw new Exception1();
			}
			return struct1_0.int_0 > ((Class24)class22_0).struct1_0.int_0;
		}

		public override bool vmethod_81(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				return ((Class26)class22_0).vmethod_85(this);
			}
			return struct1_0.uint_0 > ((Class24)class22_0).struct1_0.uint_0;
		}

		public override bool vmethod_82(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				return ((Class26)class22_0).vmethod_78(this);
			}
			return struct1_0.int_0 <= ((Class24)class22_0).struct1_0.int_0;
		}

		public override bool vmethod_83(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				return struct1_0.uint_0 <= ((Class24)class22_0).struct1_0.uint_0;
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			return ((Class26)class22_0).vmethod_79(this);
		}

		public override bool vmethod_84(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				return struct1_0.int_0 < ((Class24)class22_0).struct1_0.int_0;
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			return ((Class26)class22_0).vmethod_80(this);
		}

		public override bool vmethod_85(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					return ((Class26)class22_0).vmethod_81(this);
				}
				throw new Exception1();
			}
			return struct1_0.uint_0 < ((Class24)class22_0).struct1_0.uint_0;
		}
	}

	[StructLayout(LayoutKind.Explicit)]
	private struct Struct2
	{
		[FieldOffset(0)]
		public byte byte_0;

		[FieldOffset(0)]
		public sbyte sbyte_0;

		[FieldOffset(0)]
		public ushort ushort_0;

		[FieldOffset(0)]
		public short short_0;

		[FieldOffset(0)]
		public uint uint_0;

		[FieldOffset(0)]
		public int int_0;

		[FieldOffset(0)]
		public ulong ulong_0;

		[FieldOffset(0)]
		public long long_0;
	}

	private class Class25 : Class23
	{
		public Struct2 struct2_0;

		public Enum1 enum1_0;

		internal override void vmethod_10(Class22 class22_0)
		{
			struct2_0 = ((Class25)class22_0).struct2_0;
			enum1_0 = ((Class25)class22_0).enum1_0;
		}

		internal override void vmethod_2(Class22 class22_0)
		{
			vmethod_10(class22_0);
		}

		public Class25(long long_0)
		{
			enum4_0 = (Enum4)2;
			struct2_0.long_0 = long_0;
			enum1_0 = (Enum1)7;
		}

		public Class25(Class25 class25_0)
		{
			enum4_0 = class25_0.enum4_0;
			struct2_0.long_0 = class25_0.struct2_0.long_0;
			enum1_0 = class25_0.enum1_0;
		}

		public override Class23 vmethod_74()
		{
			return new Class25(this);
		}

		public Class25(long long_0, Enum1 enum1_1)
		{
			enum4_0 = (Enum4)2;
			struct2_0.long_0 = long_0;
			enum1_0 = enum1_1;
		}

		public Class25(ulong ulong_0)
		{
			enum4_0 = (Enum4)2;
			struct2_0.ulong_0 = ulong_0;
			enum1_0 = (Enum1)8;
		}

		public Class25(ulong ulong_0, Enum1 enum1_1)
		{
			enum4_0 = (Enum4)2;
			struct2_0.ulong_0 = ulong_0;
			enum1_0 = enum1_1;
		}

		public override bool vmethod_11()
		{
			if (enum1_0 == (Enum1)7)
			{
				return struct2_0.long_0 == 0;
			}
			return struct2_0.ulong_0 == 0;
		}

		public override bool vmethod_12()
		{
			return !vmethod_11();
		}

		public override Class22 vmethod_13(Enum1 enum1_1)
		{
			return enum1_1 switch
			{
				(Enum1)1 => vmethod_15(), 
				(Enum1)2 => vmethod_16(), 
				(Enum1)3 => vmethod_17(), 
				(Enum1)4 => vmethod_18(), 
				(Enum1)5 => vmethod_19(), 
				(Enum1)6 => vmethod_20(), 
				(Enum1)7 => vmethod_21(), 
				(Enum1)8 => vmethod_22(), 
				(Enum1)11 => vmethod_14(), 
				(Enum1)15 => method_7(), 
				(Enum1)16 => vmethod_74(), 
				_ => throw new Exception(((Enum5)4/*cast due to .constrained prefix*/).ToString()), 
			};
		}

		internal override object vmethod_4(Type type_0)
		{
			if (type_0 != null && type_0.IsByRef)
			{
				type_0 = type_0.GetElementType();
			}
			if (!(type_0 == null) && !(type_0 == typeof(object)))
			{
				if (type_0 == typeof(int))
				{
					return struct2_0.int_0;
				}
				if (!(type_0 == typeof(uint)))
				{
					if (!(type_0 == typeof(short)))
					{
						if (!(type_0 == typeof(ushort)))
						{
							if (!(type_0 == typeof(byte)))
							{
								if (!(type_0 == typeof(sbyte)))
								{
									if (!(type_0 == typeof(bool)))
									{
										if (!(type_0 == typeof(long)))
										{
											if (!(type_0 == typeof(ulong)))
											{
												if (type_0 == typeof(char))
												{
													return (char)struct2_0.long_0;
												}
												if (!type_0.IsEnum)
												{
													throw new Exception1();
												}
												return method_6(type_0);
											}
											return struct2_0.ulong_0;
										}
										return struct2_0.long_0;
									}
									return !vmethod_11();
								}
								return struct2_0.sbyte_0;
							}
							return struct2_0.byte_0;
						}
						return struct2_0.ushort_0;
					}
					return struct2_0.short_0;
				}
				return struct2_0.uint_0;
			}
			return enum1_0 switch
			{
				(Enum1)1 => struct2_0.sbyte_0, 
				(Enum1)2 => struct2_0.byte_0, 
				(Enum1)3 => struct2_0.short_0, 
				(Enum1)4 => struct2_0.ushort_0, 
				(Enum1)5 => struct2_0.int_0, 
				(Enum1)6 => struct2_0.uint_0, 
				(Enum1)7 => struct2_0.long_0, 
				(Enum1)8 => struct2_0.ulong_0, 
				(Enum1)11 => vmethod_12(), 
				(Enum1)15 => (char)struct2_0.int_0, 
				_ => struct2_0.long_0, 
			};
		}

		internal object method_6(Type type_0)
		{
			Type underlyingType = Enum.GetUnderlyingType(type_0);
			if (!(underlyingType == typeof(int)))
			{
				if (!(underlyingType == typeof(uint)))
				{
					if (!(underlyingType == typeof(short)))
					{
						if (underlyingType == typeof(ushort))
						{
							return Enum.ToObject(type_0, struct2_0.ushort_0);
						}
						if (!(underlyingType == typeof(byte)))
						{
							if (!(underlyingType == typeof(sbyte)))
							{
								if (!(underlyingType == typeof(long)))
								{
									if (!(underlyingType == typeof(ulong)))
									{
										if (!(underlyingType == typeof(char)))
										{
											return Enum.ToObject(type_0, struct2_0.long_0);
										}
										return Enum.ToObject(type_0, (ushort)struct2_0.int_0);
									}
									return Enum.ToObject(type_0, struct2_0.ulong_0);
								}
								return Enum.ToObject(type_0, struct2_0.long_0);
							}
							return Enum.ToObject(type_0, struct2_0.sbyte_0);
						}
						return Enum.ToObject(type_0, struct2_0.byte_0);
					}
					return Enum.ToObject(type_0, struct2_0.short_0);
				}
				return Enum.ToObject(type_0, struct2_0.uint_0);
			}
			return Enum.ToObject(type_0, struct2_0.int_0);
		}

		public override Class24 vmethod_14()
		{
			return new Class24((!vmethod_11()) ? 1 : 0);
		}

		internal override bool vmethod_7()
		{
			return vmethod_12();
		}

		public Class24 method_7()
		{
			return new Class24(struct2_0.sbyte_0, (Enum1)15);
		}

		public override Class24 vmethod_15()
		{
			return new Class24(struct2_0.sbyte_0, (Enum1)1);
		}

		public override Class24 vmethod_16()
		{
			return new Class24((uint)struct2_0.byte_0, (Enum1)2);
		}

		public override Class24 vmethod_17()
		{
			return new Class24(struct2_0.short_0, (Enum1)3);
		}

		public override Class24 vmethod_18()
		{
			return new Class24((uint)struct2_0.ushort_0, (Enum1)4);
		}

		public override Class24 vmethod_19()
		{
			return new Class24(struct2_0.int_0, (Enum1)5);
		}

		public override Class24 vmethod_20()
		{
			return new Class24(struct2_0.uint_0, (Enum1)6);
		}

		public override Class25 vmethod_21()
		{
			return new Class25(struct2_0.long_0, (Enum1)7);
		}

		public override Class25 vmethod_22()
		{
			return new Class25(struct2_0.ulong_0, (Enum1)8);
		}

		public override Class24 vmethod_23()
		{
			return vmethod_15();
		}

		public override Class24 vmethod_24()
		{
			return vmethod_17();
		}

		public override Class24 vmethod_25()
		{
			return vmethod_19();
		}

		public override Class25 vmethod_26()
		{
			return vmethod_21();
		}

		public override Class24 vmethod_27()
		{
			return vmethod_16();
		}

		public override Class24 vmethod_28()
		{
			return vmethod_18();
		}

		public override Class24 vmethod_29()
		{
			return vmethod_20();
		}

		public override Class25 vmethod_30()
		{
			return vmethod_22();
		}

		public override Class24 vmethod_31()
		{
			return new Class24(checked((sbyte)struct2_0.long_0), (Enum1)1);
		}

		public override Class24 vmethod_32()
		{
			return new Class24(checked((sbyte)struct2_0.ulong_0), (Enum1)1);
		}

		public override Class24 vmethod_33()
		{
			return new Class24(checked((short)struct2_0.long_0), (Enum1)3);
		}

		public override Class24 vmethod_34()
		{
			return new Class24(checked((short)struct2_0.ulong_0), (Enum1)3);
		}

		public override Class24 vmethod_35()
		{
			return new Class24(checked((int)struct2_0.long_0), (Enum1)5);
		}

		public override Class24 vmethod_36()
		{
			return new Class24(checked((int)struct2_0.ulong_0), (Enum1)5);
		}

		public override Class25 vmethod_37()
		{
			return new Class25(struct2_0.long_0, (Enum1)7);
		}

		public override Class25 vmethod_38()
		{
			return new Class25(checked((long)struct2_0.ulong_0), (Enum1)7);
		}

		public override Class24 vmethod_39()
		{
			return new Class24(checked((byte)struct2_0.long_0), (Enum1)2);
		}

		public override Class24 vmethod_40()
		{
			return new Class24(checked((byte)struct2_0.ulong_0), (Enum1)2);
		}

		public override Class24 vmethod_41()
		{
			return new Class24(checked((ushort)struct2_0.long_0), (Enum1)4);
		}

		public override Class24 vmethod_42()
		{
			return new Class24(checked((ushort)struct2_0.ulong_0), (Enum1)4);
		}

		public override Class24 vmethod_43()
		{
			return new Class24(checked((uint)struct2_0.long_0), (Enum1)6);
		}

		public override Class24 vmethod_44()
		{
			return new Class24(checked((uint)struct2_0.ulong_0), (Enum1)6);
		}

		public override Class25 vmethod_45()
		{
			return new Class25(checked((ulong)struct2_0.long_0), (Enum1)8);
		}

		public override Class25 vmethod_46()
		{
			return new Class25(struct2_0.ulong_0, (Enum1)8);
		}

		public override Class27 vmethod_47()
		{
			return new Class27(struct2_0.long_0);
		}

		public override Class27 vmethod_48()
		{
			return new Class27((double)struct2_0.long_0);
		}

		public override Class27 vmethod_49()
		{
			return new Class27((double)struct2_0.ulong_0);
		}

		public override Class26 vmethod_50()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_26().struct2_0.long_0);
			}
			return new Class26(vmethod_25().struct1_0.int_0);
		}

		public override Class26 vmethod_51()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_30().struct2_0.ulong_0);
			}
			return new Class26((ulong)vmethod_29().struct1_0.uint_0);
		}

		public override Class26 vmethod_52()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_37().struct2_0.long_0);
			}
			return new Class26(vmethod_35().struct1_0.int_0);
		}

		public override Class26 vmethod_53()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_45().struct2_0.ulong_0);
			}
			return new Class26((ulong)vmethod_43().struct1_0.uint_0);
		}

		public override Class26 vmethod_54()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_38().struct2_0.long_0);
			}
			return new Class26(vmethod_36().struct1_0.int_0);
		}

		public override Class26 vmethod_55()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(struct2_0.ulong_0);
			}
			return new Class26((ulong)checked((uint)struct2_0.ulong_0));
		}

		public override Class22 vmethod_56()
		{
			return new Class25(-struct2_0.long_0);
		}

		public override Class22 vmethod_57(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(struct2_0.long_0 + ((Class25)class22_0).struct2_0.long_0);
		}

		public override Class22 vmethod_58(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(checked(struct2_0.long_0 + ((Class25)class22_0).struct2_0.long_0));
		}

		public override Class22 vmethod_59(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(checked(struct2_0.ulong_0 + ((Class25)class22_0).struct2_0.ulong_0));
		}

		public override Class22 vmethod_60(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(struct2_0.long_0 - ((Class25)class22_0).struct2_0.long_0);
		}

		public override Class22 vmethod_61(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(checked(struct2_0.long_0 - ((Class25)class22_0).struct2_0.long_0));
		}

		public override Class22 vmethod_62(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(checked(struct2_0.ulong_0 - ((Class25)class22_0).struct2_0.ulong_0));
		}

		public override Class22 vmethod_63(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(struct2_0.long_0 * ((Class25)class22_0).struct2_0.long_0);
		}

		public override Class22 vmethod_64(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(checked(struct2_0.long_0 * ((Class25)class22_0).struct2_0.long_0));
		}

		public override Class22 vmethod_65(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(checked(struct2_0.ulong_0 * ((Class25)class22_0).struct2_0.ulong_0));
		}

		public override Class22 vmethod_66(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(struct2_0.long_0 / ((Class25)class22_0).struct2_0.long_0);
		}

		public override Class22 vmethod_67(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(struct2_0.ulong_0 / ((Class25)class22_0).struct2_0.ulong_0);
		}

		public override Class22 vmethod_68(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(struct2_0.long_0 % ((Class25)class22_0).struct2_0.long_0);
		}

		public override Class22 vmethod_69(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(struct2_0.ulong_0 % ((Class25)class22_0).struct2_0.ulong_0);
		}

		public override Class22 vmethod_70(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(struct2_0.long_0 & ((Class25)class22_0).struct2_0.long_0);
		}

		public override Class22 vmethod_71(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(struct2_0.long_0 | ((Class25)class22_0).struct2_0.long_0);
		}

		public override Class22 vmethod_72()
		{
			return new Class25(~struct2_0.long_0);
		}

		public override Class22 vmethod_73(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return new Class25(struct2_0.long_0 ^ ((Class25)class22_0).struct2_0.long_0);
		}

		public override Class22 vmethod_75(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				if (!class22_0.vmethod_3())
				{
					throw new Exception1();
				}
				return new Class25(struct2_0.long_0 << ((Class23)class22_0).vmethod_19().struct1_0.int_0);
			}
			return new Class25(struct2_0.long_0 << ((Class25)class22_0).struct2_0.int_0);
		}

		public override Class22 vmethod_76(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_3())
			{
				return new Class25(struct2_0.long_0 >> ((Class25)class22_0).struct2_0.int_0);
			}
			if (!class22_0.vmethod_3())
			{
				throw new Exception1();
			}
			return new Class25(struct2_0.long_0 >> ((Class23)class22_0).vmethod_19().struct1_0.int_0);
		}

		public override Class22 vmethod_77(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				if (class22_0.vmethod_3())
				{
					return new Class25(struct2_0.ulong_0 >> ((Class23)class22_0).vmethod_19().struct1_0.int_0);
				}
				throw new Exception1();
			}
			return new Class25(struct2_0.ulong_0 >> ((Class25)class22_0).struct2_0.int_0);
		}

		public override string ToString()
		{
			if (enum1_0 == (Enum1)7)
			{
				return struct2_0.long_0.ToString();
			}
			return struct2_0.ulong_0.ToString();
		}

		internal override Class22 vmethod_8()
		{
			return this;
		}

		internal override bool vmethod_9()
		{
			return true;
		}

		internal override bool vmethod_5(Class22 class22_0)
		{
			if (class22_0.method_0())
			{
				return ((Class34)class22_0).vmethod_5(this);
			}
			if (class22_0.vmethod_0())
			{
				return ((Class28)class22_0).vmethod_5(this);
			}
			Class22 @class = class22_0.vmethod_8();
			if (!@class.method_3())
			{
				return false;
			}
			return struct2_0.long_0 == ((Class25)@class).struct2_0.long_0;
		}

		private static Class23 smethod_4(Class22 class22_0)
		{
			Class23 @class = class22_0 as Class23;
			if (@class == null && class22_0.vmethod_0())
			{
				@class = class22_0.vmethod_8() as Class23;
			}
			return @class;
		}

		internal override bool vmethod_6(Class22 class22_0)
		{
			if (class22_0.method_0())
			{
				return false;
			}
			if (!class22_0.vmethod_0())
			{
				Class22 @class = class22_0.vmethod_8();
				if (@class.method_3())
				{
					return struct2_0.ulong_0 != ((Class25)@class).struct2_0.ulong_0;
				}
				return false;
			}
			return ((Class28)class22_0).vmethod_6(this);
		}

		public override bool vmethod_78(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return struct2_0.long_0 >= ((Class25)class22_0).struct2_0.long_0;
		}

		public override bool vmethod_79(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return struct2_0.ulong_0 >= ((Class25)class22_0).struct2_0.ulong_0;
		}

		public override bool vmethod_80(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return struct2_0.long_0 > ((Class25)class22_0).struct2_0.long_0;
		}

		public override bool vmethod_81(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return struct2_0.ulong_0 > ((Class25)class22_0).struct2_0.ulong_0;
		}

		public override bool vmethod_82(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return struct2_0.long_0 <= ((Class25)class22_0).struct2_0.long_0;
		}

		public override bool vmethod_83(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return struct2_0.ulong_0 <= ((Class25)class22_0).struct2_0.ulong_0;
		}

		public override bool vmethod_84(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return struct2_0.long_0 < ((Class25)class22_0).struct2_0.long_0;
		}

		public override bool vmethod_85(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_3())
			{
				throw new Exception1();
			}
			return struct2_0.ulong_0 < ((Class25)class22_0).struct2_0.ulong_0;
		}
	}

	private class Class26 : Class23
	{
		public object object_0;

		public Enum1 enum1_0;

		internal void method_6(Class22 class22_0)
		{
			if (!class22_0.method_2())
			{
				vmethod_10(class22_0);
				return;
			}
			object_0 = ((Class26)class22_0).object_0;
			enum1_0 = ((Class26)class22_0).enum1_0;
		}

		internal unsafe override void vmethod_10(Class22 class22_0)
		{
			if (!class22_0.method_2())
			{
				object obj = class22_0.vmethod_4(null);
				if (obj == null)
				{
					return;
				}
				IntPtr intPtr = ((IntPtr.Size != 8) ? new IntPtr(((Class24)object_0).struct1_0.int_0) : new IntPtr(((Class25)object_0).struct2_0.long_0));
				Type type = obj.GetType();
				if (type == typeof(string))
				{
					return;
				}
				if (type == typeof(byte))
				{
					*(byte*)(void*)intPtr = (byte)obj;
				}
				else if (type == typeof(sbyte))
				{
					*(sbyte*)(void*)intPtr = (sbyte)obj;
				}
				else if (!(type == typeof(short)))
				{
					if (type == typeof(ushort))
					{
						*(ushort*)(void*)intPtr = (ushort)obj;
					}
					else if (type == typeof(int))
					{
						*(int*)(void*)intPtr = (int)obj;
					}
					else if (type == typeof(uint))
					{
						*(uint*)(void*)intPtr = (uint)obj;
					}
					else if (type == typeof(long))
					{
						*(long*)(void*)intPtr = (long)obj;
					}
					else if (!(type == typeof(ulong)))
					{
						if (!(type == typeof(float)))
						{
							if (!(type == typeof(double)))
							{
								if (!(type == typeof(bool)))
								{
									if (!(type == typeof(IntPtr)))
									{
										if (!(type == typeof(UIntPtr)))
										{
											if (!(type == typeof(char)))
											{
												throw new Exception1();
											}
											*(char*)(void*)intPtr = (char)obj;
										}
										else
										{
											*(UIntPtr*)(void*)intPtr = (UIntPtr)obj;
										}
									}
									else
									{
										*(IntPtr*)(void*)intPtr = (IntPtr)obj;
									}
								}
								else
								{
									*(bool*)(void*)intPtr = (bool)obj;
								}
							}
							else
							{
								*(double*)(void*)intPtr = (double)obj;
							}
						}
						else
						{
							*(float*)(void*)intPtr = (float)obj;
						}
					}
					else
					{
						*(ulong*)(void*)intPtr = (ulong)obj;
					}
				}
				else
				{
					*(short*)(void*)intPtr = (short)obj;
				}
			}
			else if (IntPtr.Size == 8)
			{
				IntPtr intPtr2 = new IntPtr(((Class25)object_0).struct2_0.long_0);
				IntPtr intPtr3 = new IntPtr(((Class25)((Class26)class22_0).object_0).struct2_0.long_0);
				*(long*)(void*)intPtr2 = intPtr3.ToInt64();
			}
			else
			{
				IntPtr intPtr4 = new IntPtr(((Class24)object_0).struct1_0.int_0);
				IntPtr intPtr5 = new IntPtr(((Class24)((Class26)class22_0).object_0).struct1_0.int_0);
				*(int*)(void*)intPtr4 = intPtr5.ToInt32();
			}
		}

		internal override void vmethod_2(Class22 class22_0)
		{
			vmethod_10(class22_0);
		}

		public Class26(IntPtr intptr_0)
		{
			enum4_0 = (Enum4)3;
			if (IntPtr.Size == 8)
			{
				object_0 = new Class25(intptr_0.ToInt64());
				enum1_0 = (Enum1)12;
			}
			else
			{
				object_0 = new Class24(intptr_0.ToInt32());
				enum1_0 = (Enum1)12;
			}
		}

		public Class26(UIntPtr uintptr_0)
		{
			enum4_0 = (Enum4)3;
			if (IntPtr.Size == 8)
			{
				object_0 = new Class25(uintptr_0.ToUInt64());
				enum1_0 = (Enum1)12;
			}
			else
			{
				object_0 = new Class24(uintptr_0.ToUInt32());
				enum1_0 = (Enum1)12;
			}
		}

		public Class26()
		{
			enum4_0 = (Enum4)3;
			if (IntPtr.Size == 8)
			{
				object_0 = new Class25(0L);
				enum1_0 = (Enum1)12;
			}
			else
			{
				object_0 = new Class24(0);
				enum1_0 = (Enum1)12;
			}
		}

		public override Class23 vmethod_74()
		{
			return new Class26
			{
				object_0 = ((Class23)object_0).vmethod_74(),
				enum1_0 = enum1_0
			};
		}

		public Class26(long long_0)
		{
			enum4_0 = (Enum4)3;
			if (IntPtr.Size == 8)
			{
				object_0 = new Class25(long_0);
				enum1_0 = (Enum1)12;
			}
			else
			{
				object_0 = new Class24((int)long_0);
				enum1_0 = (Enum1)12;
			}
		}

		public Class26(long long_0, Enum1 enum1_1)
		{
			enum4_0 = (Enum4)3;
			if (IntPtr.Size == 8)
			{
				object_0 = new Class25(long_0);
				enum1_0 = enum1_1;
			}
			else
			{
				object_0 = new Class24((int)long_0);
				enum1_0 = enum1_1;
			}
		}

		public Class26(ulong ulong_0)
		{
			enum4_0 = (Enum4)4;
			if (IntPtr.Size == 8)
			{
				object_0 = new Class25(ulong_0);
				enum1_0 = (Enum1)13;
			}
			else
			{
				object_0 = new Class24((uint)ulong_0);
				enum1_0 = (Enum1)13;
			}
		}

		public Class26(ulong ulong_0, Enum1 enum1_1)
		{
			enum4_0 = (Enum4)4;
			if (IntPtr.Size == 8)
			{
				object_0 = new Class25(ulong_0);
				enum1_0 = enum1_1;
			}
			else
			{
				object_0 = new Class24((uint)ulong_0);
				enum1_0 = enum1_1;
			}
		}

		public override bool vmethod_11()
		{
			return ((Class23)object_0).vmethod_11();
		}

		public override bool vmethod_12()
		{
			return !vmethod_11();
		}

		internal override bool vmethod_7()
		{
			return vmethod_12();
		}

		internal override bool vmethod_1()
		{
			return true;
		}

		public override Class22 vmethod_13(Enum1 enum1_1)
		{
			return enum1_1 switch
			{
				(Enum1)1 => vmethod_15(), 
				(Enum1)2 => vmethod_16(), 
				(Enum1)3 => vmethod_17(), 
				(Enum1)4 => vmethod_18(), 
				(Enum1)5 => vmethod_19(), 
				(Enum1)6 => vmethod_20(), 
				(Enum1)7 => vmethod_21(), 
				(Enum1)8 => vmethod_22(), 
				(Enum1)11 => vmethod_14(), 
				(Enum1)12 => this, 
				(Enum1)13 => this, 
				(Enum1)16 => vmethod_74(), 
				_ => throw new Exception(((Enum5)4/*cast due to .constrained prefix*/).ToString()), 
			};
		}

		internal IntPtr method_7()
		{
			if (IntPtr.Size == 8)
			{
				return new IntPtr(((Class25)object_0).struct2_0.long_0);
			}
			return new IntPtr(((Class24)object_0).struct1_0.int_0);
		}

		internal override object vmethod_4(Type type_0)
		{
			if (type_0 != null && type_0.IsByRef)
			{
				type_0 = type_0.GetElementType();
			}
			if (type_0 == typeof(IntPtr))
			{
				if (IntPtr.Size == 8)
				{
					return new IntPtr(((Class25)object_0).struct2_0.long_0);
				}
				return new IntPtr(((Class24)object_0).struct1_0.int_0);
			}
			if (!(type_0 == typeof(UIntPtr)))
			{
				if (!(type_0 == null) && !(type_0 == typeof(object)))
				{
					throw new Exception1();
				}
				if (IntPtr.Size == 8)
				{
					if (enum1_0 == (Enum1)12)
					{
						return new IntPtr(((Class25)object_0).struct2_0.long_0);
					}
					return new UIntPtr(((Class25)object_0).struct2_0.ulong_0);
				}
				if (enum1_0 == (Enum1)12)
				{
					return new IntPtr(((Class25)object_0).struct2_0.int_0);
				}
				return new UIntPtr(((Class24)object_0).struct1_0.uint_0);
			}
			if (IntPtr.Size == 8)
			{
				return new UIntPtr(((Class25)object_0).struct2_0.ulong_0);
			}
			return new UIntPtr(((Class24)object_0).struct1_0.uint_0);
		}

		public override Class24 vmethod_14()
		{
			return ((Class23)object_0).vmethod_14();
		}

		public override Class24 vmethod_15()
		{
			return ((Class23)object_0).vmethod_15();
		}

		public override Class24 vmethod_16()
		{
			return ((Class23)object_0).vmethod_16();
		}

		public override Class24 vmethod_17()
		{
			return ((Class23)object_0).vmethod_17();
		}

		public override Class24 vmethod_18()
		{
			return ((Class23)object_0).vmethod_18();
		}

		public override Class24 vmethod_19()
		{
			return ((Class23)object_0).vmethod_19();
		}

		public override Class24 vmethod_20()
		{
			return ((Class23)object_0).vmethod_20();
		}

		public override Class25 vmethod_21()
		{
			return ((Class23)object_0).vmethod_21();
		}

		public override Class25 vmethod_22()
		{
			return ((Class23)object_0).vmethod_22();
		}

		public override Class24 vmethod_23()
		{
			return vmethod_15();
		}

		public override Class24 vmethod_24()
		{
			return vmethod_17();
		}

		public override Class24 vmethod_25()
		{
			return vmethod_19();
		}

		public override Class25 vmethod_26()
		{
			return vmethod_21();
		}

		public override Class24 vmethod_27()
		{
			return vmethod_16();
		}

		public override Class24 vmethod_28()
		{
			return vmethod_18();
		}

		public override Class24 vmethod_29()
		{
			return vmethod_20();
		}

		public override Class25 vmethod_30()
		{
			return vmethod_22();
		}

		public override Class24 vmethod_31()
		{
			return ((Class23)object_0).vmethod_31();
		}

		public override Class24 vmethod_32()
		{
			return ((Class23)object_0).vmethod_32();
		}

		public override Class24 vmethod_33()
		{
			return ((Class23)object_0).vmethod_33();
		}

		public override Class24 vmethod_34()
		{
			return ((Class23)object_0).vmethod_34();
		}

		public override Class24 vmethod_35()
		{
			return ((Class23)object_0).vmethod_35();
		}

		public override Class24 vmethod_36()
		{
			return ((Class23)object_0).vmethod_36();
		}

		public override Class25 vmethod_37()
		{
			return ((Class23)object_0).vmethod_37();
		}

		public override Class25 vmethod_38()
		{
			return ((Class23)object_0).vmethod_38();
		}

		public override Class24 vmethod_39()
		{
			return ((Class23)object_0).vmethod_39();
		}

		public override Class24 vmethod_40()
		{
			return ((Class23)object_0).vmethod_40();
		}

		public override Class24 vmethod_41()
		{
			return ((Class23)object_0).vmethod_41();
		}

		public override Class24 vmethod_42()
		{
			return ((Class23)object_0).vmethod_42();
		}

		public override Class24 vmethod_43()
		{
			return ((Class23)object_0).vmethod_43();
		}

		public override Class24 vmethod_44()
		{
			return ((Class23)object_0).vmethod_44();
		}

		public override Class25 vmethod_45()
		{
			return ((Class23)object_0).vmethod_45();
		}

		public override Class25 vmethod_46()
		{
			return ((Class23)object_0).vmethod_46();
		}

		public override Class27 vmethod_47()
		{
			return ((Class23)object_0).vmethod_47();
		}

		public override Class27 vmethod_48()
		{
			return ((Class23)object_0).vmethod_48();
		}

		public override Class27 vmethod_49()
		{
			return ((Class23)object_0).vmethod_49();
		}

		public override Class26 vmethod_50()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_26().struct2_0.long_0);
			}
			return new Class26(vmethod_25().struct1_0.int_0);
		}

		public override Class26 vmethod_51()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_30().struct2_0.ulong_0);
			}
			return new Class26((ulong)vmethod_29().struct1_0.uint_0);
		}

		public override Class26 vmethod_52()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_37().struct2_0.long_0);
			}
			return new Class26(vmethod_35().struct1_0.int_0);
		}

		public override Class26 vmethod_53()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_45().struct2_0.ulong_0);
			}
			return new Class26((ulong)vmethod_43().struct1_0.uint_0);
		}

		public override Class26 vmethod_54()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_38().struct2_0.long_0);
			}
			return new Class26(vmethod_36().struct1_0.int_0);
		}

		public override Class26 vmethod_55()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_46().struct2_0.ulong_0);
			}
			return new Class26((ulong)vmethod_44().struct1_0.uint_0);
		}

		public override Class22 vmethod_56()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(-((Class25)object_0).struct2_0.long_0);
			}
			return new Class26(-((Class24)object_0).struct1_0.int_0);
		}

		public override Class22 vmethod_57(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return new Class26(vmethod_21().struct2_0.long_0 + ((Class26)class22_0).vmethod_21().struct2_0.long_0);
					}
					return new Class26(vmethod_19().struct1_0.int_0 + ((Class26)class22_0).vmethod_19().struct1_0.int_0);
				}
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_21().struct2_0.long_0 + ((Class24)class22_0).vmethod_21().struct2_0.long_0);
			}
			return new Class26(vmethod_19().struct1_0.int_0 + ((Class24)class22_0).struct1_0.int_0);
		}

		public override Class22 vmethod_58(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			checked
			{
				if (!class22_0.method_1())
				{
					if (class22_0.method_2())
					{
						if (IntPtr.Size == 8)
						{
							return new Class26(vmethod_21().struct2_0.long_0 + ((Class26)class22_0).vmethod_21().struct2_0.long_0);
						}
						return new Class26(vmethod_19().struct1_0.int_0 + ((Class26)class22_0).vmethod_19().struct1_0.int_0);
					}
					throw new Exception1();
				}
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 + ((Class24)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 + ((Class24)class22_0).struct1_0.int_0);
			}
		}

		public override Class22 vmethod_59(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			checked
			{
				if (class22_0.method_1())
				{
					if (IntPtr.Size == 8)
					{
						return new Class26(vmethod_21().struct2_0.ulong_0 + ((Class24)class22_0).struct1_0.uint_0);
					}
					return new Class26(vmethod_19().struct1_0.uint_0 + ((Class24)class22_0).struct1_0.uint_0);
				}
			}
			if (class22_0.method_2())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(checked(vmethod_21().struct2_0.ulong_0 + ((Class26)class22_0).vmethod_21().struct2_0.ulong_0));
				}
				return new Class26((ulong)checked(vmethod_19().struct1_0.uint_0 + ((Class26)class22_0).vmethod_19().struct1_0.uint_0));
			}
			throw new Exception1();
		}

		public override Class22 vmethod_60(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return new Class26(vmethod_21().struct2_0.long_0 - ((Class26)class22_0).vmethod_21().struct2_0.long_0);
					}
					return new Class26(vmethod_19().struct1_0.int_0 - ((Class26)class22_0).vmethod_19().struct1_0.int_0);
				}
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_21().struct2_0.long_0 - ((Class24)class22_0).vmethod_21().struct2_0.long_0);
			}
			return new Class26(vmethod_19().struct1_0.int_0 - ((Class24)class22_0).struct1_0.int_0);
		}

		public Class22 method_8(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				if (IntPtr.Size == 8)
				{
					return new Class26(((Class26)class22_0).vmethod_21().struct2_0.long_0 - vmethod_21().struct2_0.long_0);
				}
				return new Class26(((Class26)class22_0).vmethod_19().struct1_0.int_0 - vmethod_19().struct1_0.int_0);
			}
			if (IntPtr.Size == 8)
			{
				return new Class26(((Class24)class22_0).vmethod_21().struct2_0.long_0 - vmethod_21().struct2_0.long_0);
			}
			return new Class26(((Class24)class22_0).struct1_0.int_0 - vmethod_19().struct1_0.int_0);
		}

		public override Class22 vmethod_61(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			checked
			{
				if (!class22_0.method_1())
				{
					if (class22_0.method_2())
					{
						if (IntPtr.Size == 8)
						{
							return new Class26(vmethod_21().struct2_0.long_0 - ((Class26)class22_0).vmethod_21().struct2_0.long_0);
						}
						return new Class26(vmethod_19().struct1_0.int_0 - ((Class26)class22_0).vmethod_19().struct1_0.int_0);
					}
					throw new Exception1();
				}
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 - ((Class24)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 - ((Class24)class22_0).struct1_0.int_0);
			}
		}

		public Class22 method_9(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			checked
			{
				if (class22_0.method_1())
				{
					if (IntPtr.Size == 8)
					{
						return new Class26(((Class24)class22_0).vmethod_21().struct2_0.long_0 - vmethod_21().struct2_0.long_0);
					}
					return new Class26(((Class24)class22_0).struct1_0.int_0 - vmethod_19().struct1_0.int_0);
				}
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return new Class26(((Class26)class22_0).vmethod_21().struct2_0.long_0 - vmethod_21().struct2_0.long_0);
					}
					return new Class26(((Class26)class22_0).vmethod_19().struct1_0.int_0 - vmethod_19().struct1_0.int_0);
				}
				throw new Exception1();
			}
		}

		public override Class22 vmethod_62(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return new Class26(checked(vmethod_21().struct2_0.ulong_0 - ((Class26)class22_0).vmethod_21().struct2_0.ulong_0));
					}
					return new Class26((ulong)checked(vmethod_19().struct1_0.uint_0 - ((Class26)class22_0).vmethod_19().struct1_0.uint_0));
				}
				throw new Exception1();
			}
			checked
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.ulong_0 - ((Class24)class22_0).struct1_0.uint_0);
				}
				return new Class26(vmethod_19().struct1_0.uint_0 - ((Class24)class22_0).struct1_0.uint_0);
			}
		}

		public Class22 method_10(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				if (IntPtr.Size == 8)
				{
					return new Class26(checked(((Class26)class22_0).vmethod_21().struct2_0.ulong_0 - vmethod_21().struct2_0.ulong_0));
				}
				return new Class26((ulong)checked(((Class26)class22_0).vmethod_19().struct1_0.uint_0 - vmethod_19().struct1_0.uint_0));
			}
			checked
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(((Class24)class22_0).struct1_0.uint_0 - vmethod_21().struct2_0.ulong_0);
				}
				return new Class26(((Class24)class22_0).struct1_0.uint_0 - vmethod_19().struct1_0.uint_0);
			}
		}

		public override Class22 vmethod_63(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return new Class26(vmethod_21().struct2_0.long_0 * ((Class26)class22_0).vmethod_21().struct2_0.long_0);
					}
					return new Class26(vmethod_19().struct1_0.int_0 * ((Class26)class22_0).vmethod_19().struct1_0.int_0);
				}
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_21().struct2_0.long_0 * ((Class24)class22_0).vmethod_21().struct2_0.long_0);
			}
			return new Class26(vmethod_19().struct1_0.int_0 * ((Class24)class22_0).struct1_0.int_0);
		}

		public override Class22 vmethod_64(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			checked
			{
				if (!class22_0.method_1())
				{
					if (!class22_0.method_2())
					{
						throw new Exception1();
					}
					if (IntPtr.Size == 8)
					{
						return new Class26(vmethod_21().struct2_0.long_0 * ((Class26)class22_0).vmethod_21().struct2_0.long_0);
					}
					return new Class26(vmethod_19().struct1_0.int_0 * ((Class26)class22_0).vmethod_19().struct1_0.int_0);
				}
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 * ((Class24)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 * ((Class24)class22_0).struct1_0.int_0);
			}
		}

		public override Class22 vmethod_65(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			checked
			{
				if (class22_0.method_1())
				{
					if (IntPtr.Size == 8)
					{
						return new Class26(vmethod_21().struct2_0.ulong_0 * ((Class24)class22_0).struct1_0.uint_0);
					}
					return new Class26(vmethod_19().struct1_0.uint_0 * ((Class24)class22_0).struct1_0.uint_0);
				}
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.ulong_0 * ((Class26)class22_0).vmethod_21().struct2_0.ulong_0);
				}
			}
			return new Class26((ulong)checked(vmethod_19().struct1_0.uint_0 * ((Class26)class22_0).vmethod_19().struct1_0.uint_0));
		}

		public override Class22 vmethod_66(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 / ((Class24)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 / ((Class24)class22_0).struct1_0.int_0);
			}
			if (class22_0.method_2())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 / ((Class26)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 / ((Class26)class22_0).vmethod_19().struct1_0.int_0);
			}
			throw new Exception1();
		}

		public Class22 method_11(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				if (IntPtr.Size == 8)
				{
					return new Class26(((Class26)class22_0).vmethod_21().struct2_0.long_0 / vmethod_21().struct2_0.long_0);
				}
				return new Class26(((Class26)class22_0).vmethod_19().struct1_0.int_0 / vmethod_19().struct1_0.int_0);
			}
			if (IntPtr.Size == 8)
			{
				return new Class26(((Class24)class22_0).vmethod_21().struct2_0.long_0 / vmethod_21().struct2_0.long_0);
			}
			return new Class26(((Class24)class22_0).struct1_0.int_0 / vmethod_19().struct1_0.int_0);
		}

		public override Class22 vmethod_67(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.ulong_0 / ((Class24)class22_0).vmethod_21().struct2_0.ulong_0);
				}
				return new Class26(vmethod_19().struct1_0.uint_0 / ((Class24)class22_0).struct1_0.uint_0);
			}
			if (class22_0.method_2())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.ulong_0 / ((Class26)class22_0).vmethod_21().struct2_0.ulong_0);
				}
				return new Class26((ulong)(vmethod_19().struct1_0.uint_0 / ((Class26)class22_0).vmethod_19().struct1_0.uint_0));
			}
			throw new Exception1();
		}

		public Class22 method_12(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				if (IntPtr.Size == 8)
				{
					return new Class26(((Class26)class22_0).vmethod_21().struct2_0.ulong_0 / vmethod_21().struct2_0.ulong_0);
				}
				return new Class26((ulong)(((Class26)class22_0).vmethod_19().struct1_0.uint_0 / vmethod_19().struct1_0.uint_0));
			}
			if (IntPtr.Size == 8)
			{
				return new Class26(((Class24)class22_0).vmethod_21().struct2_0.ulong_0 / vmethod_21().struct2_0.ulong_0);
			}
			return new Class26(((Class24)class22_0).struct1_0.uint_0 / vmethod_19().struct1_0.uint_0);
		}

		public override Class22 vmethod_68(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 % ((Class24)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 % ((Class24)class22_0).struct1_0.int_0);
			}
			if (class22_0.method_2())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 % ((Class26)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 % ((Class26)class22_0).vmethod_19().struct1_0.int_0);
			}
			throw new Exception1();
		}

		public Class22 method_13(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return new Class26(((Class26)class22_0).vmethod_21().struct2_0.long_0 % vmethod_21().struct2_0.long_0);
					}
					return new Class26(((Class26)class22_0).vmethod_19().struct1_0.int_0 % vmethod_19().struct1_0.int_0);
				}
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return new Class26(((Class24)class22_0).vmethod_21().struct2_0.long_0 % vmethod_21().struct2_0.long_0);
			}
			return new Class26(((Class24)class22_0).struct1_0.int_0 % vmethod_19().struct1_0.int_0);
		}

		public override Class22 vmethod_69(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return new Class26(vmethod_21().struct2_0.ulong_0 % ((Class26)class22_0).vmethod_21().struct2_0.ulong_0);
					}
					return new Class26((ulong)(vmethod_19().struct1_0.uint_0 % ((Class26)class22_0).vmethod_19().struct1_0.uint_0));
				}
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_21().struct2_0.ulong_0 % ((Class24)class22_0).vmethod_21().struct2_0.ulong_0);
			}
			return new Class26(vmethod_19().struct1_0.uint_0 % ((Class24)class22_0).struct1_0.uint_0);
		}

		public Class22 method_14(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(((Class24)class22_0).vmethod_21().struct2_0.ulong_0 % vmethod_21().struct2_0.ulong_0);
				}
				return new Class26(((Class24)class22_0).struct1_0.uint_0 % vmethod_19().struct1_0.uint_0);
			}
			if (class22_0.method_2())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(((Class26)class22_0).vmethod_21().struct2_0.ulong_0 % vmethod_21().struct2_0.ulong_0);
				}
				return new Class26((ulong)(((Class26)class22_0).vmethod_19().struct1_0.uint_0 % vmethod_19().struct1_0.uint_0));
			}
			throw new Exception1();
		}

		public override Class22 vmethod_70(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 & ((Class24)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 & ((Class24)class22_0).struct1_0.int_0);
			}
			if (class22_0.method_2())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 & ((Class26)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 & ((Class26)class22_0).vmethod_19().struct1_0.int_0);
			}
			throw new Exception1();
		}

		public override Class22 vmethod_71(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 | ((Class24)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 | ((Class24)class22_0).struct1_0.int_0);
			}
			if (class22_0.method_2())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 | ((Class26)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 | ((Class26)class22_0).vmethod_19().struct1_0.int_0);
			}
			throw new Exception1();
		}

		public override Class22 vmethod_72()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(~vmethod_21().struct2_0.long_0);
			}
			return new Class26(~vmethod_19().struct1_0.int_0);
		}

		public override Class22 vmethod_73(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 ^ ((Class24)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 ^ ((Class24)class22_0).struct1_0.int_0);
			}
			if (class22_0.method_2())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 ^ ((Class26)class22_0).vmethod_21().struct2_0.long_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 ^ ((Class26)class22_0).vmethod_19().struct1_0.int_0);
			}
			throw new Exception1();
		}

		public override Class22 vmethod_75(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 << ((Class26)class22_0).vmethod_21().struct2_0.int_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 << ((Class26)class22_0).vmethod_19().struct1_0.int_0);
			}
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_21().struct2_0.long_0 << ((Class24)class22_0).struct1_0.int_0);
			}
			return new Class26(vmethod_19().struct1_0.int_0 << ((Class24)class22_0).struct1_0.int_0);
		}

		public override Class22 vmethod_76(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				if (IntPtr.Size == 8)
				{
					return new Class26(vmethod_21().struct2_0.long_0 >> ((Class24)class22_0).struct1_0.int_0);
				}
				return new Class26(vmethod_19().struct1_0.int_0 >> ((Class24)class22_0).struct1_0.int_0);
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_21().struct2_0.long_0 >> ((Class26)class22_0).vmethod_21().struct2_0.int_0);
			}
			return new Class26(vmethod_19().struct1_0.int_0 >> ((Class26)class22_0).vmethod_19().struct1_0.int_0);
		}

		public override Class22 vmethod_77(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return new Class26(vmethod_21().struct2_0.ulong_0 >> ((Class26)class22_0).vmethod_21().struct2_0.int_0);
					}
					return new Class26(vmethod_19().struct1_0.uint_0 >> ((Class26)class22_0).vmethod_19().struct1_0.int_0);
				}
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_21().struct2_0.ulong_0 >> ((Class24)class22_0).struct1_0.int_0);
			}
			return new Class26(vmethod_19().struct1_0.uint_0 >> ((Class24)class22_0).struct1_0.int_0);
		}

		public Class22 method_15(Class24 class24_0)
		{
			return new Class26(class24_0.struct1_0.uint_0 >> vmethod_19().struct1_0.int_0);
		}

		public Class22 method_16(Class24 class24_0)
		{
			return new Class26(class24_0.struct1_0.int_0 >> vmethod_21().struct2_0.int_0);
		}

		public Class22 method_17(Class24 class24_0)
		{
			return new Class26(class24_0.struct1_0.int_0 << vmethod_21().struct2_0.int_0);
		}

		public override string ToString()
		{
			return object_0.ToString();
		}

		internal override Class22 vmethod_8()
		{
			return this;
		}

		internal override bool vmethod_9()
		{
			return true;
		}

		internal override bool vmethod_5(Class22 class22_0)
		{
			if (class22_0.method_0())
			{
				return false;
			}
			if (!class22_0.vmethod_0())
			{
				Class22 @class = class22_0.vmethod_8();
				if (!@class.vmethod_9())
				{
					return false;
				}
				if (@class.method_1())
				{
					if (IntPtr.Size == 8)
					{
						return vmethod_21().struct2_0.long_0 == ((Class24)class22_0).vmethod_21().struct2_0.long_0;
					}
					return vmethod_19().struct1_0.int_0 == ((Class24)class22_0).struct1_0.int_0;
				}
				if (@class.method_2())
				{
					_ = IntPtr.Size;
					return vmethod_21().struct2_0.long_0 == ((Class26)class22_0).vmethod_21().struct2_0.long_0;
				}
				return false;
			}
			return ((Class28)class22_0).vmethod_5(this);
		}

		internal override bool vmethod_6(Class22 class22_0)
		{
			if (!class22_0.method_0())
			{
				if (class22_0.vmethod_0())
				{
					return ((Class28)class22_0).vmethod_6(this);
				}
				Class22 @class = class22_0.vmethod_8();
				if (!@class.vmethod_9())
				{
					return false;
				}
				if (@class.method_1())
				{
					if (IntPtr.Size == 8)
					{
						return vmethod_21().struct2_0.ulong_0 != ((Class24)class22_0).vmethod_21().struct2_0.ulong_0;
					}
					return vmethod_19().struct1_0.uint_0 != ((Class24)class22_0).struct1_0.uint_0;
				}
				if (!@class.method_2())
				{
					return false;
				}
				_ = IntPtr.Size;
				return vmethod_21().struct2_0.ulong_0 != ((Class26)class22_0).vmethod_21().struct2_0.ulong_0;
			}
			return false;
		}

		public override bool vmethod_78(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return vmethod_21().struct2_0.long_0 >= ((Class26)class22_0).vmethod_21().struct2_0.long_0;
					}
					return vmethod_19().struct1_0.int_0 >= ((Class26)class22_0).vmethod_19().struct1_0.int_0;
				}
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return vmethod_21().struct2_0.long_0 >= ((Class24)class22_0).vmethod_21().struct2_0.long_0;
			}
			return vmethod_19().struct1_0.int_0 >= ((Class24)class22_0).struct1_0.int_0;
		}

		public override bool vmethod_79(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return vmethod_21().struct2_0.ulong_0 >= ((Class26)class22_0).vmethod_21().struct2_0.ulong_0;
					}
					return vmethod_19().struct1_0.uint_0 >= ((Class26)class22_0).vmethod_19().struct1_0.uint_0;
				}
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return vmethod_21().struct2_0.ulong_0 >= ((Class24)class22_0).vmethod_21().struct2_0.ulong_0;
			}
			return vmethod_19().struct1_0.uint_0 >= ((Class24)class22_0).struct1_0.uint_0;
		}

		public override bool vmethod_80(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return vmethod_21().struct2_0.long_0 > ((Class26)class22_0).vmethod_21().struct2_0.long_0;
					}
					return vmethod_19().struct1_0.int_0 > ((Class26)class22_0).vmethod_19().struct1_0.int_0;
				}
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return vmethod_21().struct2_0.long_0 > ((Class24)class22_0).vmethod_21().struct2_0.long_0;
			}
			return vmethod_19().struct1_0.int_0 > ((Class24)class22_0).struct1_0.int_0;
		}

		public override bool vmethod_81(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				if (IntPtr.Size == 8)
				{
					return vmethod_21().struct2_0.ulong_0 > ((Class24)class22_0).vmethod_21().struct2_0.ulong_0;
				}
				return vmethod_19().struct1_0.uint_0 > ((Class24)class22_0).struct1_0.uint_0;
			}
			if (class22_0.method_2())
			{
				if (IntPtr.Size == 8)
				{
					return vmethod_21().struct2_0.ulong_0 > ((Class26)class22_0).vmethod_21().struct2_0.ulong_0;
				}
				return vmethod_19().struct1_0.uint_0 > ((Class26)class22_0).vmethod_19().struct1_0.uint_0;
			}
			throw new Exception1();
		}

		public override bool vmethod_82(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				if (IntPtr.Size == 8)
				{
					return vmethod_21().struct2_0.long_0 <= ((Class24)class22_0).vmethod_21().struct2_0.long_0;
				}
				return vmethod_19().struct1_0.int_0 <= ((Class24)class22_0).struct1_0.int_0;
			}
			if (!class22_0.method_2())
			{
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return vmethod_21().struct2_0.long_0 <= ((Class26)class22_0).vmethod_21().struct2_0.long_0;
			}
			return vmethod_19().struct1_0.int_0 <= ((Class26)class22_0).vmethod_19().struct1_0.int_0;
		}

		public override bool vmethod_83(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (!class22_0.method_2())
				{
					throw new Exception1();
				}
				if (IntPtr.Size == 8)
				{
					return vmethod_21().struct2_0.ulong_0 <= ((Class26)class22_0).vmethod_21().struct2_0.ulong_0;
				}
				return vmethod_19().struct1_0.uint_0 <= ((Class26)class22_0).vmethod_19().struct1_0.uint_0;
			}
			if (IntPtr.Size == 8)
			{
				return vmethod_21().struct2_0.ulong_0 <= ((Class24)class22_0).vmethod_21().struct2_0.ulong_0;
			}
			return vmethod_19().struct1_0.uint_0 <= ((Class24)class22_0).struct1_0.uint_0;
		}

		public override bool vmethod_84(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (class22_0.method_1())
			{
				if (IntPtr.Size == 8)
				{
					return vmethod_21().struct2_0.long_0 < ((Class24)class22_0).vmethod_21().struct2_0.long_0;
				}
				return vmethod_19().struct1_0.int_0 < ((Class24)class22_0).struct1_0.int_0;
			}
			if (class22_0.method_2())
			{
				if (IntPtr.Size == 8)
				{
					return vmethod_21().struct2_0.long_0 < ((Class26)class22_0).vmethod_21().struct2_0.long_0;
				}
				return vmethod_19().struct1_0.int_0 < ((Class26)class22_0).vmethod_19().struct1_0.int_0;
			}
			throw new Exception1();
		}

		public override bool vmethod_85(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_1())
			{
				if (class22_0.method_2())
				{
					if (IntPtr.Size == 8)
					{
						return vmethod_21().struct2_0.ulong_0 < ((Class26)class22_0).vmethod_21().struct2_0.ulong_0;
					}
					return vmethod_19().struct1_0.uint_0 < ((Class26)class22_0).vmethod_19().struct1_0.uint_0;
				}
				throw new Exception1();
			}
			if (IntPtr.Size == 8)
			{
				return vmethod_21().struct2_0.ulong_0 < ((Class24)class22_0).vmethod_21().struct2_0.ulong_0;
			}
			return vmethod_19().struct1_0.uint_0 < ((Class24)class22_0).struct1_0.uint_0;
		}
	}

	private abstract class Class23 : Class22
	{
		public abstract bool vmethod_11();

		public abstract bool vmethod_12();

		public abstract Class22 vmethod_13(Enum1 enum1_0);

		public abstract Class24 vmethod_14();

		public abstract Class24 vmethod_15();

		public abstract Class24 vmethod_16();

		public abstract Class24 vmethod_17();

		public abstract Class24 vmethod_18();

		public abstract Class24 vmethod_19();

		public abstract Class24 vmethod_20();

		public abstract Class25 vmethod_21();

		public abstract Class25 vmethod_22();

		public abstract Class24 vmethod_23();

		public abstract Class24 vmethod_24();

		public abstract Class24 vmethod_25();

		public abstract Class25 vmethod_26();

		public abstract Class24 vmethod_27();

		public abstract Class24 vmethod_28();

		public abstract Class24 vmethod_29();

		public abstract Class25 vmethod_30();

		public abstract Class24 vmethod_31();

		public abstract Class24 vmethod_32();

		public abstract Class24 vmethod_33();

		public abstract Class24 vmethod_34();

		public abstract Class24 vmethod_35();

		public abstract Class24 vmethod_36();

		public abstract Class25 vmethod_37();

		public abstract Class25 vmethod_38();

		public abstract Class24 vmethod_39();

		public abstract Class24 vmethod_40();

		public abstract Class24 vmethod_41();

		public abstract Class24 vmethod_42();

		public abstract Class24 vmethod_43();

		public abstract Class24 vmethod_44();

		public abstract Class25 vmethod_45();

		public abstract Class25 vmethod_46();

		public abstract Class27 vmethod_47();

		public abstract Class27 vmethod_48();

		public abstract Class27 vmethod_49();

		public abstract Class26 vmethod_50();

		public abstract Class26 vmethod_51();

		public abstract Class26 vmethod_52();

		public abstract Class26 vmethod_53();

		public abstract Class26 vmethod_54();

		public abstract Class26 vmethod_55();

		public abstract Class22 vmethod_56();

		public abstract Class22 vmethod_57(Class22 class22_0);

		public abstract Class22 vmethod_58(Class22 class22_0);

		public abstract Class22 vmethod_59(Class22 class22_0);

		public abstract Class22 vmethod_60(Class22 class22_0);

		public abstract Class22 vmethod_61(Class22 class22_0);

		public abstract Class22 vmethod_62(Class22 class22_0);

		public abstract Class22 vmethod_63(Class22 class22_0);

		public abstract Class22 vmethod_64(Class22 class22_0);

		public abstract Class22 vmethod_65(Class22 class22_0);

		public abstract Class22 vmethod_66(Class22 class22_0);

		public abstract Class22 vmethod_67(Class22 class22_0);

		public abstract Class22 vmethod_68(Class22 class22_0);

		public abstract Class22 vmethod_69(Class22 class22_0);

		public abstract Class22 vmethod_70(Class22 class22_0);

		public abstract Class22 vmethod_71(Class22 class22_0);

		public abstract Class22 vmethod_72();

		public abstract Class22 vmethod_73(Class22 class22_0);

		public abstract Class23 vmethod_74();

		public abstract Class22 vmethod_75(Class22 class22_0);

		public abstract Class22 vmethod_76(Class22 class22_0);

		public abstract Class22 vmethod_77(Class22 class22_0);

		public abstract bool vmethod_78(Class22 class22_0);

		public abstract bool vmethod_79(Class22 class22_0);

		public abstract bool vmethod_80(Class22 class22_0);

		public abstract bool vmethod_81(Class22 class22_0);

		public abstract bool vmethod_82(Class22 class22_0);

		public abstract bool vmethod_83(Class22 class22_0);

		public abstract bool vmethod_84(Class22 class22_0);

		public abstract bool vmethod_85(Class22 class22_0);

		internal override bool vmethod_3()
		{
			return true;
		}
	}

	private class Class27 : Class23
	{
		public double double_0;

		public Enum1 enum1_0;

		internal override void vmethod_10(Class22 class22_0)
		{
			double_0 = ((Class27)class22_0).double_0;
			enum1_0 = ((Class27)class22_0).enum1_0;
		}

		internal override void vmethod_2(Class22 class22_0)
		{
			vmethod_10(class22_0);
		}

		public Class27(double double_1)
		{
			enum4_0 = (Enum4)5;
			enum1_0 = (Enum1)10;
			double_0 = double_1;
		}

		public Class27(Class27 class27_0)
		{
			enum4_0 = class27_0.enum4_0;
			enum1_0 = class27_0.enum1_0;
			double_0 = class27_0.double_0;
		}

		public override Class23 vmethod_74()
		{
			return new Class27(this);
		}

		public Class27(double double_1, Enum1 enum1_1)
		{
			enum4_0 = (Enum4)5;
			double_0 = double_1;
			enum1_0 = enum1_1;
		}

		public Class27(float float_0)
		{
			enum4_0 = (Enum4)5;
			double_0 = float_0;
			enum1_0 = (Enum1)9;
		}

		public Class27(float float_0, Enum1 enum1_1)
		{
			enum4_0 = (Enum4)5;
			double_0 = float_0;
			enum1_0 = enum1_1;
		}

		public override bool vmethod_11()
		{
			return double_0 == 0.0;
		}

		public override bool vmethod_12()
		{
			return !vmethod_11();
		}

		public override string ToString()
		{
			return double_0.ToString();
		}

		public override Class22 vmethod_13(Enum1 enum1_1)
		{
			return enum1_1 switch
			{
				(Enum1)1 => vmethod_15(), 
				(Enum1)2 => vmethod_16(), 
				(Enum1)3 => vmethod_17(), 
				(Enum1)4 => vmethod_18(), 
				(Enum1)5 => vmethod_19(), 
				(Enum1)6 => vmethod_20(), 
				(Enum1)7 => vmethod_21(), 
				(Enum1)8 => vmethod_22(), 
				(Enum1)9 => vmethod_47(), 
				(Enum1)10 => vmethod_48(), 
				(Enum1)11 => vmethod_14(), 
				_ => throw new Exception(((Enum5)4/*cast due to .constrained prefix*/).ToString()), 
			};
		}

		internal override object vmethod_4(Type type_0)
		{
			if (type_0 != null && type_0.IsByRef)
			{
				type_0 = type_0.GetElementType();
			}
			if (!(type_0 == typeof(float)))
			{
				if (type_0 == typeof(double))
				{
					return double_0;
				}
				if ((type_0 == null || type_0 == typeof(object)) && enum1_0 == (Enum1)9)
				{
					return (float)double_0;
				}
				return double_0;
			}
			return (float)double_0;
		}

		public override Class24 vmethod_14()
		{
			return new Class24(vmethod_11() ? 1 : 0);
		}

		internal override bool vmethod_7()
		{
			return vmethod_12();
		}

		public override Class24 vmethod_15()
		{
			return new Class24((sbyte)double_0, (Enum1)1);
		}

		public override Class24 vmethod_16()
		{
			return new Class24((uint)(byte)double_0, (Enum1)2);
		}

		public override Class24 vmethod_17()
		{
			return new Class24((short)double_0, (Enum1)3);
		}

		public override Class24 vmethod_18()
		{
			return new Class24((uint)(ushort)double_0, (Enum1)4);
		}

		public override Class24 vmethod_19()
		{
			return new Class24((int)double_0, (Enum1)5);
		}

		public override Class24 vmethod_20()
		{
			return new Class24((uint)double_0, (Enum1)6);
		}

		public override Class25 vmethod_21()
		{
			return new Class25((long)double_0, (Enum1)7);
		}

		public override Class25 vmethod_22()
		{
			return new Class25((ulong)double_0, (Enum1)8);
		}

		public override Class24 vmethod_23()
		{
			return vmethod_15();
		}

		public override Class24 vmethod_24()
		{
			return vmethod_17();
		}

		public override Class24 vmethod_25()
		{
			return vmethod_19();
		}

		public override Class25 vmethod_26()
		{
			return vmethod_21();
		}

		public override Class24 vmethod_27()
		{
			return vmethod_16();
		}

		public override Class24 vmethod_28()
		{
			return vmethod_18();
		}

		public override Class24 vmethod_29()
		{
			return vmethod_20();
		}

		public override Class25 vmethod_30()
		{
			return vmethod_22();
		}

		public override Class24 vmethod_31()
		{
			return new Class24(checked((sbyte)double_0), (Enum1)1);
		}

		public override Class24 vmethod_32()
		{
			return new Class24(checked((sbyte)double_0), (Enum1)1);
		}

		public override Class24 vmethod_33()
		{
			return new Class24(checked((short)double_0), (Enum1)3);
		}

		public override Class24 vmethod_34()
		{
			return new Class24(checked((short)double_0), (Enum1)3);
		}

		public override Class24 vmethod_35()
		{
			return new Class24(checked((int)double_0), (Enum1)5);
		}

		public override Class24 vmethod_36()
		{
			return new Class24(checked((int)double_0), (Enum1)5);
		}

		public override Class25 vmethod_37()
		{
			return new Class25(checked((long)double_0), (Enum1)7);
		}

		public override Class25 vmethod_38()
		{
			return new Class25(checked((long)double_0), (Enum1)7);
		}

		public override Class24 vmethod_39()
		{
			return new Class24(checked((byte)double_0), (Enum1)2);
		}

		public override Class24 vmethod_40()
		{
			return new Class24(checked((byte)double_0), (Enum1)2);
		}

		public override Class24 vmethod_41()
		{
			return new Class24(checked((ushort)double_0), (Enum1)4);
		}

		public override Class24 vmethod_42()
		{
			return new Class24(checked((ushort)double_0), (Enum1)4);
		}

		public override Class24 vmethod_43()
		{
			return new Class24(checked((uint)double_0), (Enum1)6);
		}

		public override Class24 vmethod_44()
		{
			return new Class24(checked((uint)double_0), (Enum1)6);
		}

		public override Class25 vmethod_45()
		{
			return new Class25(checked((ulong)double_0), (Enum1)8);
		}

		public override Class25 vmethod_46()
		{
			return new Class25(checked((ulong)double_0), (Enum1)8);
		}

		public override Class27 vmethod_47()
		{
			return new Class27((float)double_0, (Enum1)9);
		}

		public override Class27 vmethod_48()
		{
			return new Class27(double_0, (Enum1)10);
		}

		public override Class27 vmethod_49()
		{
			return new Class27(double_0);
		}

		public override Class26 vmethod_50()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_26().struct2_0.long_0);
			}
			return new Class26(vmethod_25().struct1_0.int_0);
		}

		public override Class26 vmethod_51()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_30().struct2_0.ulong_0);
			}
			return new Class26((ulong)vmethod_29().struct1_0.uint_0);
		}

		public override Class26 vmethod_52()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_37().struct2_0.long_0);
			}
			return new Class26(vmethod_35().struct1_0.int_0);
		}

		public override Class26 vmethod_53()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_45().struct2_0.ulong_0);
			}
			return new Class26((ulong)vmethod_43().struct1_0.uint_0);
		}

		public override Class26 vmethod_54()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_38().struct2_0.long_0);
			}
			return new Class26(vmethod_36().struct1_0.int_0);
		}

		public override Class26 vmethod_55()
		{
			if (IntPtr.Size == 8)
			{
				return new Class26(vmethod_46().struct2_0.ulong_0);
			}
			return new Class26((ulong)vmethod_44().struct1_0.uint_0);
		}

		public override Class22 vmethod_56()
		{
			if (enum1_0 == (Enum1)9)
			{
				return new Class27((float)(0.0 - double_0));
			}
			return new Class27(0.0 - double_0);
		}

		public override Class22 vmethod_57(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 + ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_58(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 + ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_59(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 + ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_60(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 - ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_61(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 - ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_62(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 - ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_63(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4() || !class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 * ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_64(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 * ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_65(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 * ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_66(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 / ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_67(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 / ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_68(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 % ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_69(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return new Class27(double_0 % ((Class27)class22_0).double_0);
		}

		public override Class22 vmethod_70(Class22 class22_0)
		{
			throw new Exception1();
		}

		public override Class22 vmethod_71(Class22 class22_0)
		{
			throw new Exception1();
		}

		public override Class22 vmethod_72()
		{
			throw new Exception1();
		}

		public override Class22 vmethod_73(Class22 class22_0)
		{
			throw new Exception1();
		}

		public override Class22 vmethod_75(Class22 class22_0)
		{
			throw new Exception1();
		}

		public override Class22 vmethod_76(Class22 class22_0)
		{
			throw new Exception1();
		}

		public override Class22 vmethod_77(Class22 class22_0)
		{
			throw new Exception1();
		}

		internal override Class22 vmethod_8()
		{
			return this;
		}

		internal override bool vmethod_5(Class22 class22_0)
		{
			if (!class22_0.method_0())
			{
				if (!class22_0.vmethod_0())
				{
					Class22 @class = class22_0.vmethod_8();
					if (!@class.method_4())
					{
						return false;
					}
					return double_0 == ((Class27)@class).double_0;
				}
				return ((Class28)class22_0).vmethod_5(this);
			}
			return false;
		}

		internal override bool vmethod_6(Class22 class22_0)
		{
			if (!class22_0.method_0())
			{
				if (!class22_0.vmethod_0())
				{
					Class22 @class = class22_0.vmethod_8();
					if (!@class.method_4())
					{
						return false;
					}
					return double_0 != ((Class27)@class).double_0;
				}
				return ((Class28)class22_0).vmethod_6(this);
			}
			return false;
		}

		public override bool vmethod_78(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return double_0 >= ((Class27)class22_0).double_0;
		}

		public override bool vmethod_79(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return double_0 >= ((Class27)class22_0).double_0;
		}

		public override bool vmethod_80(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return double_0 > ((Class27)class22_0).double_0;
		}

		public override bool vmethod_81(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return double_0 > ((Class27)class22_0).double_0;
		}

		public override bool vmethod_82(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return double_0 <= ((Class27)class22_0).double_0;
		}

		public override bool vmethod_83(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return double_0 <= ((Class27)class22_0).double_0;
		}

		public override bool vmethod_84(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return double_0 < ((Class27)class22_0).double_0;
		}

		public override bool vmethod_85(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				class22_0 = class22_0.vmethod_8();
			}
			if (!class22_0.method_4())
			{
				throw new Exception1();
			}
			return double_0 < ((Class27)class22_0).double_0;
		}
	}

	internal enum Enum1 : byte
	{

	}

	internal enum Enum2 : byte
	{

	}

	private class Exception0 : Exception
	{
		public Exception0(string string_0)
			: base(string_0)
		{
		}
	}

	private class Exception1 : Exception
	{
		public Exception1()
		{
		}

		public Exception1(string string_0)
			: base(string_0)
		{
		}
	}

	internal class Class12
	{
		internal Enum3 enum3_0 = (Enum3)126;

		internal object object_0;

		public override string ToString()
		{
			object obj = enum3_0;
			if (object_0 == null)
			{
				return obj.ToString();
			}
			return obj.ToString() + "H" + object_0.ToString();
		}
	}

	internal abstract class Class28 : Class22
	{
		public Class28()
		{
		}

		internal override bool vmethod_0()
		{
			return true;
		}

		internal abstract IntPtr vmethod_11();

		internal abstract void vmethod_12(Class22 class22_0);

		internal override bool vmethod_1()
		{
			return true;
		}
	}

	internal class Class29 : Class28
	{
		private Class20 class20_0;

		internal int int_0;

		public Class29(int int_1, Class20 class20_1)
		{
			class20_0 = class20_1;
			int_0 = int_1;
			enum4_0 = (Enum4)7;
		}

		internal override void vmethod_10(Class22 class22_0)
		{
			if (!(class22_0 is Class29))
			{
				Class14 @class = class20_0.class17_0.list_1[int_0];
				if (class22_0 is Class28 && (int)(@class.enum1_0 & (Enum1)226) > 0)
				{
					Class22 class22_1 = (class22_0 as Class28).vmethod_8();
					vmethod_12(class22_1);
				}
				else
				{
					vmethod_12(class22_0);
				}
			}
			else
			{
				class20_0 = ((Class29)class22_0).class20_0;
				int_0 = ((Class29)class22_0).int_0;
			}
		}

		internal override void vmethod_2(Class22 class22_0)
		{
			vmethod_12(class22_0);
		}

		internal override IntPtr vmethod_11()
		{
			throw new NotImplementedException();
		}

		internal override void vmethod_12(Class22 class22_0)
		{
			class20_0.class22_1[int_0] = class22_0;
		}

		internal override object vmethod_4(Type type_0)
		{
			if (class20_0.class22_1[int_0] != null)
			{
				return vmethod_8().vmethod_4(type_0);
			}
			return null;
		}

		internal override Class22 vmethod_8()
		{
			if (class20_0.class22_1[int_0] == null)
			{
				return new Class34(null);
			}
			return class20_0.class22_1[int_0].vmethod_8();
		}

		internal override bool vmethod_9()
		{
			return vmethod_8().vmethod_9();
		}

		internal override bool vmethod_5(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				if (!(class22_0 is Class29))
				{
					return false;
				}
				if (((Class29)class22_0).int_0 == int_0)
				{
					return true;
				}
				return false;
			}
			return false;
		}

		internal override bool vmethod_6(Class22 class22_0)
		{
			if (!class22_0.vmethod_0())
			{
				return true;
			}
			if (class22_0 is Class29)
			{
				if (((Class29)class22_0).int_0 != int_0)
				{
					return true;
				}
				return false;
			}
			return true;
		}

		internal override bool vmethod_7()
		{
			return vmethod_8().vmethod_7();
		}
	}

	internal class Class30 : Class28
	{
		private Array array_0;

		internal int int_0;

		public Class30(int int_1, Array array_1)
		{
			array_0 = array_1;
			int_0 = int_1;
			enum4_0 = (Enum4)7;
		}

		internal override IntPtr vmethod_11()
		{
			throw new NotImplementedException();
		}

		internal override void vmethod_10(Class22 class22_0)
		{
			if (!(class22_0 is Class30))
			{
				vmethod_12(class22_0);
				return;
			}
			array_0 = ((Class30)class22_0).array_0;
			int_0 = ((Class30)class22_0).int_0;
		}

		internal override void vmethod_2(Class22 class22_0)
		{
			vmethod_12(class22_0);
		}

		internal override void vmethod_12(Class22 class22_0)
		{
			array_0.SetValue(class22_0.vmethod_4(null), int_0);
		}

		internal override object vmethod_4(Type type_0)
		{
			return vmethod_8().vmethod_4(type_0);
		}

		internal override Class22 vmethod_8()
		{
			return Class22.smethod_1(array_0.GetType().GetElementType(), array_0.GetValue(int_0));
		}

		internal override bool vmethod_9()
		{
			return vmethod_8().vmethod_9();
		}

		internal override bool vmethod_5(Class22 class22_0)
		{
			if (!class22_0.vmethod_0())
			{
				return false;
			}
			if (!(class22_0 is Class30))
			{
				return false;
			}
			Class30 @class = (Class30)class22_0;
			if (@class.int_0 != int_0)
			{
				return false;
			}
			if (@class.array_0 != array_0)
			{
				return false;
			}
			return true;
		}

		internal override bool vmethod_6(Class22 class22_0)
		{
			if (!class22_0.vmethod_0())
			{
				return true;
			}
			if (!(class22_0 is Class30))
			{
				return true;
			}
			Class30 @class = (Class30)class22_0;
			if (@class.int_0 != int_0)
			{
				return true;
			}
			if (@class.array_0 != array_0)
			{
				return true;
			}
			return false;
		}

		internal override bool vmethod_7()
		{
			return vmethod_8().vmethod_7();
		}
	}

	internal class Class31 : Class28
	{
		internal FieldInfo fieldInfo_0;

		internal object object_0;

		public Class31(FieldInfo fieldInfo_1, object object_1)
		{
			fieldInfo_0 = fieldInfo_1;
			object_0 = object_1;
			enum4_0 = (Enum4)7;
		}

		internal override IntPtr vmethod_11()
		{
			throw new NotImplementedException();
		}

		internal override void vmethod_12(Class22 class22_0)
		{
			if (object_0 != null && object_0 is Class22)
			{
				fieldInfo_0.SetValue(((Class22)object_0).vmethod_4(null), class22_0.vmethod_4(null));
			}
			else
			{
				fieldInfo_0.SetValue(object_0, class22_0.vmethod_4(null));
			}
		}

		internal override void vmethod_10(Class22 class22_0)
		{
			if (class22_0 is Class31)
			{
				fieldInfo_0 = ((Class31)class22_0).fieldInfo_0;
				object_0 = ((Class31)class22_0).object_0;
			}
			else
			{
				vmethod_12(class22_0);
			}
		}

		internal override void vmethod_2(Class22 class22_0)
		{
			vmethod_12(class22_0);
		}

		internal override object vmethod_4(Type type_0)
		{
			return vmethod_8().vmethod_4(type_0);
		}

		internal override Class22 vmethod_8()
		{
			if (object_0 != null && object_0 is Class22)
			{
				return Class22.smethod_1(fieldInfo_0.FieldType, fieldInfo_0.GetValue(((Class22)object_0).vmethod_4(null)));
			}
			return Class22.smethod_1(fieldInfo_0.FieldType, fieldInfo_0.GetValue(object_0));
		}

		internal override bool vmethod_9()
		{
			return vmethod_8().vmethod_9();
		}

		internal override bool vmethod_5(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				if (!(class22_0 is Class31))
				{
					return false;
				}
				Class31 @class = (Class31)class22_0;
				if (!(@class.fieldInfo_0 != fieldInfo_0))
				{
					if (@class.object_0 != object_0)
					{
						return false;
					}
					return true;
				}
				return false;
			}
			return false;
		}

		internal override bool vmethod_6(Class22 class22_0)
		{
			if (!class22_0.vmethod_0())
			{
				return true;
			}
			if (class22_0 is Class31)
			{
				Class31 @class = (Class31)class22_0;
				if (!(@class.fieldInfo_0 != fieldInfo_0))
				{
					if (@class.object_0 != object_0)
					{
						return true;
					}
					return false;
				}
				return true;
			}
			return true;
		}

		internal override bool vmethod_7()
		{
			return vmethod_8().vmethod_7();
		}
	}

	internal class Class32 : Class28
	{
		private Class20 class20_0;

		internal int int_0;

		public Class32(int int_1, Class20 class20_1)
		{
			class20_0 = class20_1;
			int_0 = int_1;
			enum4_0 = (Enum4)7;
		}

		internal override IntPtr vmethod_11()
		{
			throw new NotImplementedException();
		}

		internal override void vmethod_10(Class22 class22_0)
		{
			if (!(class22_0 is Class32))
			{
				vmethod_12(class22_0);
				return;
			}
			class20_0 = ((Class32)class22_0).class20_0;
			int_0 = ((Class32)class22_0).int_0;
		}

		internal override void vmethod_2(Class22 class22_0)
		{
			vmethod_12(class22_0);
		}

		internal override void vmethod_12(Class22 class22_0)
		{
			class20_0.class22_0[int_0] = class22_0;
		}

		internal override object vmethod_4(Type type_0)
		{
			if (class20_0.class22_0[int_0] != null)
			{
				return vmethod_8().vmethod_4(type_0);
			}
			return null;
		}

		internal override Class22 vmethod_8()
		{
			if (class20_0.class22_0[int_0] != null)
			{
				return class20_0.class22_0[int_0].vmethod_8();
			}
			return new Class34(null);
		}

		internal override bool vmethod_9()
		{
			return vmethod_8().vmethod_9();
		}

		internal override bool vmethod_5(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				if (!(class22_0 is Class32))
				{
					return false;
				}
				return ((Class32)class22_0).int_0 == int_0;
			}
			return false;
		}

		internal override bool vmethod_6(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				if (class22_0 is Class32)
				{
					return ((Class32)class22_0).int_0 != int_0;
				}
				return true;
			}
			return true;
		}

		internal override bool vmethod_7()
		{
			return vmethod_8().vmethod_7();
		}
	}

	internal class Class33 : Class28
	{
		private Class22 class22_0;

		private Type type_0;

		public Class33(Class22 class22_1, Type type_1)
		{
			class22_0 = class22_1;
			type_0 = type_1;
			enum4_0 = (Enum4)7;
		}

		internal override IntPtr vmethod_11()
		{
			throw new NotImplementedException();
		}

		internal override void vmethod_10(Class22 class22_1)
		{
			if (!(class22_1 is Class33))
			{
				class22_0.vmethod_10(class22_1);
				return;
			}
			type_0 = ((Class33)class22_1).type_0;
			class22_0 = ((Class33)class22_1).class22_0;
		}

		internal override void vmethod_2(Class22 class22_1)
		{
			vmethod_12(class22_1);
		}

		internal override void vmethod_12(Class22 class22_1)
		{
			class22_0 = class22_1;
		}

		internal override object vmethod_4(Type type_1)
		{
			if (class22_0 == null)
			{
				return new Class34(null);
			}
			if (!(type_1 == null) && !(type_1 == typeof(object)))
			{
				return class22_0.vmethod_4(type_1);
			}
			return class22_0.vmethod_4(type_0);
		}

		internal override Class22 vmethod_8()
		{
			if (class22_0 != null)
			{
				return class22_0.vmethod_8();
			}
			return new Class34(null);
		}

		internal override bool vmethod_9()
		{
			return vmethod_8().vmethod_9();
		}

		internal override bool vmethod_5(Class22 class22_1)
		{
			if (class22_1.vmethod_0())
			{
				if (!(class22_1 is Class33))
				{
					return false;
				}
				Class33 @class = (Class33)class22_1;
				if (@class.type_0 != type_0)
				{
					return false;
				}
				if (class22_0 != null)
				{
					return class22_0.vmethod_5(@class.class22_0);
				}
				if (@class.class22_0 != null)
				{
					return false;
				}
				return true;
			}
			return false;
		}

		internal override bool vmethod_6(Class22 class22_1)
		{
			if (class22_1.vmethod_0())
			{
				if (!(class22_1 is Class33))
				{
					return true;
				}
				Class33 @class = (Class33)class22_1;
				if (!(@class.type_0 != type_0))
				{
					if (class22_0 == null)
					{
						if (@class.class22_0 == null)
						{
							return false;
						}
						return true;
					}
					return class22_0.vmethod_6(@class.class22_0);
				}
				return true;
			}
			return true;
		}

		internal override bool vmethod_7()
		{
			return vmethod_8().vmethod_7();
		}
	}

	internal class Class13
	{
		public int int_0;

		public bool bool_0;

		public Enum1 enum1_0;
	}

	internal class Class14
	{
		public int int_0;

		public Enum1 enum1_0;

		public bool bool_0;

		public Type type_0 = typeof(object);
	}

	internal class Class15
	{
		public int int_0;

		public int int_1;

		public Class16 class16_0;
	}

	internal class Class16
	{
		public int int_0;

		public int int_1;

		public byte byte_0;

		public Type type_0;

		public int int_2;

		public int int_3;
	}

	internal class Class17
	{
		internal object object_0;

		internal List<Class12> list_0;

		internal Class13[] class13_0;

		internal List<Class14> list_1;

		internal List<Class15> list_2;
	}

	private class Class18
	{
		internal object object_0;

		internal int int_0;

		public Class18(FieldInfo fieldInfo_0, int int_1)
		{
			object_0 = fieldInfo_0;
			int_0 = int_1;
		}
	}

	private class Class19
	{
		private List<Class18> list_0 = new List<Class18>();

		private MethodBase methodBase_0;

		public Class19(MethodBase methodBase_1, List<Class18> list_1)
		{
			list_0 = list_1;
			methodBase_0 = methodBase_1;
		}

		public Class19(MethodBase methodBase_1, Class18[] class18_0)
		{
			list_0.AddRange(class18_0);
		}

		public override bool Equals(object obj)
		{
			Class19 @class = obj as Class19;
			if (obj == null)
			{
				return false;
			}
			if (!(methodBase_0 != @class.methodBase_0))
			{
				if (list_0.Count != @class.list_0.Count)
				{
					return false;
				}
				int num = 0;
				while (true)
				{
					if (num < list_0.Count)
					{
						if ((FieldInfo)list_0[num].object_0 != (FieldInfo)@class.list_0[num].object_0)
						{
							break;
						}
						if (list_0[num].int_0 == @class.list_0[num].int_0)
						{
							num++;
							continue;
						}
						return false;
					}
					return true;
				}
				return false;
			}
			return false;
		}

		public override int GetHashCode()
		{
			int num = methodBase_0.GetHashCode();
			foreach (Class18 item in list_0)
			{
				int num2 = item.object_0.GetHashCode() + item.int_0;
				num = (num ^ num2) + num2;
			}
			return num;
		}

		public Class18 method_0(int int_0)
		{
			foreach (Class18 item in list_0)
			{
				if (item.int_0 == int_0)
				{
					return item;
				}
			}
			return null;
		}

		public bool method_1(int int_0)
		{
			foreach (Class18 item in list_0)
			{
				if (item.int_0 == int_0)
				{
					return true;
				}
			}
			return false;
		}
	}

	private delegate object Delegate10(object target, object[] paramters);

	private delegate object Delegate11(object target);

	private delegate void Delegate12(IntPtr a, byte b, int c);

	private delegate void Delegate13(IntPtr s, IntPtr t, uint c);

	internal class Class20
	{
		[Serializable]
		[CompilerGenerated]
		private sealed class Class21
		{
			public static readonly Class21 _003C_003E9;

			public static Comparison<Class15> _003C_003E9__12_0;

			static Class21()
			{
				_003C_003E9 = new Class21();
			}

			internal int method_0(Class15 x, Class15 y)
			{
				return x.class16_0.int_0.CompareTo(y.class16_0.int_0);
			}
		}

		internal Class17 class17_0;

		internal Class22[] class22_0 = new Class22[0];

		internal Class22[] class22_1 = new Class22[0];

		internal Class36 class36_0 = new Class36();

		internal Class22 class22_2;

		internal Exception exception_0;

		internal List<IntPtr> list_0;

		private int int_0;

		private int int_1;

		private int int_2 = -1;

		private object object_0;

		private bool bool_0;

		private bool bool_1;

		private bool bool_2;

		private bool bool_3;

		private static Dictionary<Type, int> dictionary_0;

		private static Dictionary<object, Class22> dictionary_1;

		private static Dictionary<MethodBase, Delegate10> dictionary_2;

		private static Dictionary<MethodBase, Delegate10> dictionary_3;

		private static Dictionary<Class19, Delegate10> dictionary_4;

		private static Dictionary<Class19, Delegate10> dictionary_5;

		private static Dictionary<Class19, Delegate10> dictionary_6;

		private static Dictionary<Type, Delegate11> dictionary_7;

		private static Delegate12 delegate12_0;

		private static Delegate13 delegate13_0;

		internal void method_0()
		{
			bool bool_ = false;
			method_2(ref bool_);
		}

		internal void method_1()
		{
			class36_0.method_1();
			class22_1 = null;
			if (list_0 == null)
			{
				return;
			}
			foreach (IntPtr item in list_0)
			{
				try
				{
					Marshal.FreeHGlobal(item);
				}
				catch
				{
				}
			}
			list_0.Clear();
			list_0 = null;
		}

		internal void method_2(ref bool bool_4)
		{
			while (int_0 > -2)
			{
				if (bool_0)
				{
					bool_0 = false;
					int num = int_1;
					int num2 = int_0;
					method_4(int_1, int_0);
					int_0 = num2;
					int_1 = num;
				}
				if (!bool_2)
				{
					if (!bool_1)
					{
						int_1 = int_0;
						Class12 @class = class17_0.list_0[int_0];
						object_0 = @class.object_0;
						try
						{
							method_7(@class);
						}
						catch (Exception innerException)
						{
							if (innerException is TargetInvocationException)
							{
								TargetInvocationException ex = (TargetInvocationException)innerException;
								if (ex.InnerException != null)
								{
									innerException = ex.InnerException;
								}
							}
							exception_0 = innerException;
							bool_4 = true;
							class36_0.method_1();
							int int_ = int_1;
							Class15 class2 = method_5(int_, innerException);
							List<Class15> list = method_6(int_, bool_4: false);
							List<Class15> list2 = new List<Class15>();
							if (class2 != null)
							{
								list2.Add(class2);
							}
							if (list != null && list.Count > 0)
							{
								list2.AddRange(list);
							}
							list2.Sort((Class15 x, Class15 y) => x.class16_0.int_0.CompareTo(y.class16_0.int_0));
							Class15 class3 = null;
							foreach (Class15 item in list2)
							{
								if (item.class16_0.int_3 != 0)
								{
									class36_0.method_2(new Class34(innerException));
									int_1 = item.class16_0.int_2;
									int_0 = int_1;
									method_0();
									if (bool_3)
									{
										bool_3 = false;
										class3 = item;
										break;
									}
									continue;
								}
								class3 = item;
								break;
							}
							if (class3 == null)
							{
								throw innerException;
							}
							int_2 = class3.class16_0.int_0;
							method_3(int_, class3.class16_0.int_0);
							if (int_2 >= 0)
							{
								class36_0.method_2(new Class34(innerException));
								int_1 = int_2;
								int_0 = int_1;
								int_2 = -1;
								method_0();
							}
							return;
						}
						int_0++;
						continue;
					}
					bool_1 = false;
					return;
				}
				bool_2 = false;
				return;
			}
			class36_0.method_1();
		}

		internal void method_3(int int_3, int int_4)
		{
			if (class17_0.list_2 == null)
			{
				return;
			}
			foreach (Class15 item in class17_0.list_2)
			{
				if ((item.class16_0.int_3 == 4 || item.class16_0.int_3 == 2) && item.class16_0.int_0 >= int_3 && item.class16_0.int_1 <= int_4)
				{
					int_1 = item.class16_0.int_0;
					int_0 = int_1;
					bool bool_ = false;
					method_2(ref bool_);
					if (bool_)
					{
						break;
					}
				}
			}
		}

		internal void method_4(int int_3, int int_4)
		{
			if (class17_0.list_2 == null)
			{
				return;
			}
			foreach (Class15 item in class17_0.list_2)
			{
				if (item.class16_0.int_3 == 2 && item.class16_0.int_0 >= int_3 && item.class16_0.int_1 <= int_4)
				{
					int_1 = item.class16_0.int_0;
					int_0 = int_1;
					bool bool_ = false;
					method_2(ref bool_);
					if (bool_)
					{
						break;
					}
				}
			}
		}

		internal Class15 method_5(int int_3, Exception exception_1)
		{
			Class15 @class = null;
			if (class17_0.list_2 != null)
			{
				foreach (Class15 item in class17_0.list_2)
				{
					if (item.class16_0.int_3 == 0 && (item.class16_0.type_0 == exception_1.GetType() || (item.class16_0.type_0 != null && (item.class16_0.type_0.FullName == exception_1.GetType().FullName || item.class16_0.type_0.FullName == typeof(object).FullName || item.class16_0.type_0.FullName == typeof(Exception).FullName))) && int_3 >= item.int_0 && int_3 <= item.int_1)
					{
						if (@class == null)
						{
							@class = item;
						}
						else if (item.class16_0.int_0 < @class.class16_0.int_0)
						{
							@class = item;
						}
					}
				}
			}
			return @class;
		}

		internal List<Class15> method_6(int int_3, bool bool_4)
		{
			if (class17_0.list_2 == null)
			{
				return null;
			}
			List<Class15> list = new List<Class15>();
			foreach (Class15 item in class17_0.list_2)
			{
				if ((item.class16_0.int_3 & 1) == 1 && int_3 >= item.int_0 && int_3 <= item.int_1)
				{
					list.Add(item);
				}
			}
			if (list.Count == 0)
			{
				return null;
			}
			return list;
		}

		private unsafe void method_7(Class12 class12_0)
		{
			switch (class12_0.enum3_0)
			{
			case (Enum3)0:
			{
				Class22 class61 = class36_0.method_4();
				if (smethod_1(class36_0.method_4()).vmethod_85(class61))
				{
					class36_0.method_2(new Class24(1));
				}
				else
				{
					class36_0.method_2(new Class24(0));
				}
				break;
			}
			case (Enum3)2:
			{
				Class22 class50 = class36_0.method_4();
				Class22 class51 = class36_0.method_4();
				if (class50.vmethod_5(class51))
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			}
			case (Enum3)3:
				bool_3 = (bool)class36_0.method_4().vmethod_4(typeof(bool));
				bool_1 = true;
				break;
			case (Enum3)4:
			{
				Class23 class135 = smethod_1(class36_0.method_4());
				if (class135 != null)
				{
					class36_0.method_2(class135.vmethod_36());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)5:
			{
				int metadataToken15 = (int)object_0;
				Type type6 = typeof(Class11).Module.ResolveType(metadataToken15);
				Class22 class129 = class36_0.method_4();
				object obj14 = class129.vmethod_4(null);
				if (obj14 != null)
				{
					if (type6.IsAssignableFrom(obj14.GetType()))
					{
						class36_0.method_2(class129);
					}
					else
					{
						class36_0.method_2(new Class34(null));
					}
				}
				else
				{
					class36_0.method_2(new Class34(null));
				}
				break;
			}
			case (Enum3)6:
				class36_0.method_2(class36_0.method_3());
				break;
			case (Enum3)7:
			{
				Class22 class33 = class36_0.method_4();
				if (class33.vmethod_3())
				{
					class33 = ((Class23)class33).vmethod_23();
				}
				class36_0.method_4().vmethod_2(class33);
				break;
			}
			case (Enum3)8:
			{
				Class23 class119 = smethod_1(class36_0.method_4());
				if (class119 != null)
				{
					class36_0.method_2(class119.vmethod_41());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)9:
			{
				Class23 class106 = smethod_1(class36_0.method_4());
				if (class106 != null)
				{
					class36_0.method_2(class106.vmethod_29());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)10:
			{
				Class22 class46 = class36_0.method_4();
				if (class46.vmethod_3())
				{
					class46 = ((Class23)class46).vmethod_24();
				}
				class36_0.method_4().vmethod_2(class46);
				break;
			}
			case (Enum3)11:
			{
				Class23 class98 = smethod_1(class36_0.method_4());
				object value12 = ((Array)class36_0.method_4().vmethod_4(null)).GetValue(class98.vmethod_19().struct1_0.int_0);
				class36_0.method_2(Class22.smethod_1(typeof(int), value12));
				break;
			}
			case (Enum3)12:
			{
				Class23 class148 = smethod_1(class36_0.method_4());
				if (class148 != null)
				{
					class36_0.method_2(class148.vmethod_46());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)13:
			{
				Class22 class141 = class36_0.method_4();
				class36_0.method_4().vmethod_2(class141);
				break;
			}
			case (Enum3)14:
			{
				Class22 class96 = smethod_6(class36_0.method_4());
				Class22 class97 = smethod_6(class36_0.method_4());
				if (!class96.vmethod_5(class97))
				{
					class36_0.method_2(new Class24(0));
				}
				else
				{
					class36_0.method_2(new Class24(1));
				}
				break;
			}
			case (Enum3)15:
			{
				Class22 class81 = class36_0.method_4();
				if (smethod_1(class36_0.method_4()).vmethod_84(class81))
				{
					class36_0.method_2(new Class24(1));
				}
				else
				{
					class36_0.method_2(new Class24(0));
				}
				break;
			}
			case (Enum3)16:
			{
				Class23 class47 = smethod_1(class36_0.method_4());
				if (class47 != null)
				{
					class36_0.method_2(class47.vmethod_44());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)17:
			{
				Class23 class21 = smethod_1(class36_0.method_4());
				object value = ((Array)class36_0.method_4().vmethod_4(null)).GetValue(class21.vmethod_19().struct1_0.int_0);
				class36_0.method_2(Class22.smethod_1(typeof(float), value));
				break;
			}
			case (Enum3)18:
			{
				Class22 class9 = class36_0.method_4();
				Class23 class10 = smethod_1(class9);
				Class22 class22_ = class36_0.method_4();
				Class23 class11 = smethod_1(class22_);
				if (class11 != null && class10 != null)
				{
					if (class11.vmethod_81(class9))
					{
						int_0 = (int)object_0 - 1;
					}
				}
				else if (class9.vmethod_6(class22_))
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			}
			case (Enum3)19:
			{
				Class23 class145 = smethod_1(class36_0.method_4());
				if (class145 != null)
				{
					class36_0.method_2(class145.vmethod_49());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)20:
			{
				int metadataToken11 = (int)object_0;
				Type type4 = typeof(Class11).Module.ResolveType(metadataToken11);
				if (class36_0.method_4() is Class28 class86)
				{
					if (type4.IsValueType)
					{
						object obj9 = Activator.CreateInstance(type4);
						class86.vmethod_12(Class22.smethod_1(type4, obj9));
					}
					else
					{
						class86.vmethod_12(new Class34(null));
					}
					break;
				}
				throw new Exception1();
			}
			case (Enum3)21:
			{
				Class23 class78 = smethod_1(class36_0.method_4());
				Class23 class79 = smethod_1(class36_0.method_4());
				if (class79 != null && class78 != null)
				{
					class36_0.method_2(class79.vmethod_69(class78));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)22:
			{
				int metadataToken18 = (int)object_0;
				Type type7 = typeof(Class11).Module.ResolveType(metadataToken18);
				object obj17 = ((class36_0.method_4() as Class28) ?? throw new Exception1()).vmethod_4(type7);
				Class22 class154;
				if (obj17 != null)
				{
					if (type7.IsValueType)
					{
						obj17 = smethod_9(obj17);
					}
					class154 = Class22.smethod_1(type7, obj17);
				}
				else if (!type7.IsValueType)
				{
					class154 = new Class34(null);
				}
				else
				{
					obj17 = Activator.CreateInstance(type7);
					class154 = Class22.smethod_1(type7, obj17);
				}
				class36_0.method_2(class154);
				break;
			}
			case (Enum3)23:
			{
				int metadataToken4 = (int)object_0;
				uint uint_ = (uint)smethod_0(typeof(Class11).Module.ResolveType(metadataToken4));
				class36_0.method_2(new Class24(uint_, (Enum1)6));
				break;
			}
			case (Enum3)24:
				if ((smethod_1(class36_0.method_3()) ?? throw new ArithmeticException(((Enum5)0/*cast due to .constrained prefix*/).ToString())) is Class27 class115)
				{
					if (double.IsNaN(class115.double_0))
					{
						throw new OverflowException(((Enum5)2/*cast due to .constrained prefix*/).ToString());
					}
					if (double.IsInfinity(class115.double_0))
					{
						throw new OverflowException(((Enum5)1/*cast due to .constrained prefix*/).ToString());
					}
				}
				break;
			case (Enum3)25:
				method_12(bool_4: false);
				break;
			case (Enum3)26:
			{
				Class23 class84 = smethod_1(class36_0.method_4());
				Class23 class85 = smethod_1(class36_0.method_4());
				if (class85 != null && class84 != null)
				{
					class36_0.method_2(class85.vmethod_76(class84));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)28:
			{
				IntPtr intPtr9 = Marshal.AllocHGlobal((class36_0.method_4() as Class23).vmethod_19().struct1_0.int_0);
				if (list_0 == null)
				{
					list_0 = new List<IntPtr>();
				}
				list_0.Add(intPtr9);
				class36_0.method_2(new Class26(intPtr9));
				break;
			}
			case (Enum3)31:
			{
				int[] array2 = (int[])object_0;
				Class23 class19 = smethod_1(class36_0.method_4());
				long num2 = class19.vmethod_21().struct2_0.long_0;
				if ((num2 < 0 || class19.method_4()) && IntPtr.Size == 4)
				{
					num2 = (int)num2;
				}
				if (class19.method_1())
				{
					Class24 class20 = (Class24)class19;
					if (class20.enum1_0 == (Enum1)6)
					{
						num2 = class20.struct1_0.uint_0;
					}
				}
				if (num2 < array2.Length && num2 >= 0)
				{
					int_0 = array2[num2] - 1;
				}
				break;
			}
			case (Enum3)32:
			{
				int metadataToken3 = (int)object_0;
				Type elementType = typeof(Class11).Module.ResolveType(metadataToken3);
				Class23 class14 = smethod_1(class36_0.method_4());
				Array array = Array.CreateInstance(elementType, class14.vmethod_19().struct1_0.int_0);
				class36_0.method_2(new Class34(array));
				break;
			}
			case (Enum3)33:
			{
				Class23 class6 = smethod_1(class36_0.method_4());
				Class23 class7 = smethod_1(class36_0.method_4());
				if (class7 != null && class6 != null)
				{
					class36_0.method_2(class7.vmethod_75(class6));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)35:
			{
				Class22 class149 = class36_0.method_4();
				if (smethod_1(class36_0.method_4()).vmethod_80(class149))
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			}
			case (Enum3)37:
			{
				Class22 class126 = class36_0.method_4();
				Class23 class127 = smethod_1(class126);
				Class22 class22_2 = class36_0.method_4();
				Class23 class128 = smethod_1(class22_2);
				if (class128 != null && class127 != null)
				{
					if (!class128.vmethod_81(class126))
					{
						class36_0.method_2(new Class24(0));
					}
					else
					{
						class36_0.method_2(new Class24(1));
					}
				}
				else if (!class126.vmethod_6(class22_2))
				{
					class36_0.method_2(new Class24(0));
				}
				else
				{
					class36_0.method_2(new Class24(1));
				}
				break;
			}
			case (Enum3)38:
			{
				int metadataToken12 = (int)object_0;
				FieldInfo fieldInfo_ = typeof(Class11).Module.ResolveField(metadataToken12);
				class36_0.method_2(new Class31(fieldInfo_, null));
				break;
			}
			case (Enum3)39:
			{
				Class23 class101 = smethod_1(class36_0.method_4());
				if (class101 != null)
				{
					class36_0.method_2(class101.vmethod_35());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)40:
			{
				int metadataToken9 = (int)object_0;
				FieldInfo fieldInfo3 = typeof(Class11).Module.ResolveField(metadataToken9);
				object value7 = class36_0.method_4().vmethod_4(fieldInfo3.FieldType);
				Class22 class62 = class36_0.method_4();
				object obj6 = class62.vmethod_4(null);
				if (obj6 == null)
				{
					Type type2 = fieldInfo3.DeclaringType;
					if (type2.IsByRef)
					{
						type2 = type2.GetElementType();
					}
					if (!type2.IsValueType)
					{
						throw new NullReferenceException();
					}
					obj6 = Activator.CreateInstance(type2);
					if (class62 is Class29)
					{
						((Class28)class62).vmethod_12(Class22.smethod_1(type2, obj6));
					}
				}
				fieldInfo3.SetValue(obj6, value7);
				break;
			}
			case (Enum3)41:
				int_0 = -3;
				if (class36_0.method_0() > 0)
				{
					this.class22_2 = class36_0.method_4();
				}
				break;
			case (Enum3)42:
			{
				int metadataToken8 = (int)object_0;
				FieldInfo fieldInfo2 = typeof(Class11).Module.ResolveField(metadataToken8);
				class36_0.method_2(Class22.smethod_1(fieldInfo2.FieldType, fieldInfo2.GetValue(null)));
				break;
			}
			case (Enum3)43:
				bool_2 = true;
				break;
			case (Enum3)44:
			{
				if (Class11.list_0.Count != 0)
				{
					class36_0.method_2(new Class35(Class11.list_0[(int)object_0]));
					break;
				}
				Module module2 = typeof(Class11).Module;
				class36_0.method_2(new Class35(module2.ResolveString((int)object_0 | 0x70000000)));
				break;
			}
			case (Enum3)45:
			{
				int metadataToken5 = (int)object_0;
				typeof(Class11).Module.ResolveType(metadataToken5);
				Class23 class40 = smethod_1(class36_0.method_4());
				Array array_ = (Array)class36_0.method_4().vmethod_4(null);
				class36_0.method_2(new Class30(class40.vmethod_19().struct1_0.int_0, array_));
				break;
			}
			case (Enum3)46:
			{
				Class23 class37 = smethod_1(class36_0.method_4());
				object value3 = ((Array)class36_0.method_4().vmethod_4(null)).GetValue(class37.vmethod_19().struct1_0.int_0);
				class36_0.method_2(Class22.smethod_1(typeof(byte), value3));
				break;
			}
			case (Enum3)47:
			{
				Class22 class12 = class36_0.method_4();
				Class23 class13 = smethod_1(class12);
				if (class12 != null && class12.vmethod_0() && class13 != null)
				{
					class36_0.method_2(class13.vmethod_25());
					break;
				}
				if (class13 != null && class13.method_2())
				{
					IntPtr intPtr = ((Class26)class13).method_7();
					class36_0.method_2(new Class24(*(int*)(void*)intPtr, (Enum1)5));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)48:
			{
				Class23 class152 = smethod_1(class36_0.method_4());
				Class23 class153 = smethod_1(class36_0.method_4());
				if (class153 != null && class152 != null)
				{
					class36_0.method_2(class153.vmethod_57(class152));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)49:
			{
				Class22 class142 = class36_0.method_4();
				if (class142.vmethod_3())
				{
					class142 = ((Class23)class142).vmethod_50();
				}
				class36_0.method_4().vmethod_2(class142);
				break;
			}
			case (Enum3)50:
			{
				Class23 class143 = smethod_1(class36_0.method_4());
				if (class143 != null)
				{
					class36_0.method_2(class143.vmethod_51());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)52:
			{
				Class23 class133 = smethod_1(class36_0.method_4());
				Class23 class134 = smethod_1(class36_0.method_4());
				if (class134 != null && class133 != null)
				{
					class36_0.method_2(class134.vmethod_67(class133));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)53:
			{
				Class23 class120 = smethod_1(class36_0.method_4());
				Class23 class121 = smethod_1(class36_0.method_4());
				if (class121 != null && class120 != null)
				{
					class36_0.method_2(class121.vmethod_77(class120));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)54:
			{
				Array array3 = (Array)class36_0.method_4().vmethod_4(null);
				class36_0.method_2(new Class24(array3.Length, (Enum1)5));
				break;
			}
			case (Enum3)55:
				int_0 = (int)object_0 - 1;
				bool_0 = true;
				break;
			case (Enum3)56:
				if (class36_0.method_4().vmethod_6(class36_0.method_4()))
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			case (Enum3)57:
			{
				Class23 class102 = class36_0.method_4() as Class23;
				Class23 class103 = class36_0.method_4() as Class23;
				IntPtr intPtr12 = smethod_8(class36_0.method_4());
				if (intPtr12 != IntPtr.Zero)
				{
					byte byte_ = class103.vmethod_16().struct1_0.byte_0;
					uint uint_3 = class102.vmethod_20().struct1_0.uint_0;
					smethod_10(intPtr12, byte_, (int)uint_3);
				}
				break;
			}
			case (Enum3)58:
			{
				Class23 class105 = smethod_1(class36_0.method_4());
				object value13 = ((Array)class36_0.method_4().vmethod_4(null)).GetValue(class105.vmethod_19().struct1_0.int_0);
				class36_0.method_2(Class22.smethod_1(typeof(sbyte), value13));
				break;
			}
			case (Enum3)59:
				class36_0.method_2(((Class23)class36_0.method_4()).vmethod_56());
				break;
			case (Enum3)60:
			{
				Class22 class88 = class36_0.method_4();
				Class23 class89 = smethod_1(class88);
				if (class88 != null && class88.vmethod_0() && class89 != null)
				{
					class36_0.method_2(class89.vmethod_28());
					break;
				}
				if (class89 != null && class89.method_2())
				{
					IntPtr intPtr10 = ((Class26)class89).method_7();
					class36_0.method_2(new Class24(*(ushort*)(void*)intPtr10, (Enum1)4));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)36:
			case (Enum3)62:
			{
				int metadataToken10 = (int)object_0;
				Module module3 = typeof(Class11).Module;
				class36_0.method_2(new Class26(module3.ResolveMethod(metadataToken10).MethodHandle.GetFunctionPointer()));
				break;
			}
			case (Enum3)63:
			{
				Class23 class82 = smethod_1(class36_0.method_4());
				if (class82 != null)
				{
					class36_0.method_2(class82.vmethod_39());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)64:
			{
				Class23 class74 = smethod_1(class36_0.method_4());
				object value10 = ((Array)class36_0.method_4().vmethod_4(null)).GetValue(class74.vmethod_19().struct1_0.int_0);
				class36_0.method_2(Class22.smethod_1(typeof(long), value10));
				break;
			}
			case (Enum3)66:
			{
				Class23 class72 = smethod_1(class36_0.method_4());
				object value9 = ((Array)class36_0.method_4().vmethod_4(null)).GetValue(class72.vmethod_19().struct1_0.int_0);
				class36_0.method_2(Class22.smethod_1(typeof(ushort), value9));
				break;
			}
			case (Enum3)68:
			{
				Class23 class69 = smethod_1(class36_0.method_4());
				object value8 = ((Array)class36_0.method_4().vmethod_4(null)).GetValue(class69.vmethod_19().struct1_0.int_0);
				class36_0.method_2(Class22.smethod_1(typeof(uint), value8));
				break;
			}
			case (Enum3)69:
			{
				Class23 class67 = smethod_1(class36_0.method_4());
				Class23 class68 = smethod_1(class36_0.method_4());
				if (class68 != null && class67 != null)
				{
					class36_0.method_2(class68.vmethod_64(class67));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)71:
				class36_0.method_2(class22_0[(int)object_0]);
				break;
			case (Enum3)72:
				class36_0.method_2(class36_0.method_4().vmethod_8());
				break;
			case (Enum3)73:
			{
				Class23 class57 = smethod_1(class36_0.method_4());
				if (class57 != null)
				{
					class36_0.method_2(class57.vmethod_47());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)74:
			{
				int metadataToken7 = (int)object_0;
				Type type_ = typeof(Class11).Module.ResolveType(metadataToken7);
				Class23 class55 = smethod_1(class36_0.method_4());
				object value6 = ((Array)class36_0.method_4().vmethod_4(null)).GetValue(class55.vmethod_19().struct1_0.int_0);
				class36_0.method_2(Class22.smethod_1(type_, value6));
				break;
			}
			case (Enum3)75:
			{
				Class23 class48 = smethod_1(class36_0.method_4());
				Class23 class49 = smethod_1(class36_0.method_4());
				if (class48 != null && class49 != null)
				{
					class36_0.method_2(class48.vmethod_70(class49));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)76:
				throw exception_0;
			case (Enum3)77:
			{
				int metadataToken6 = (int)object_0;
				FieldInfo fieldInfo = typeof(Class11).Module.ResolveField(metadataToken6);
				object value5 = class36_0.method_4().vmethod_4(fieldInfo.FieldType);
				fieldInfo.SetValue(null, value5);
				break;
			}
			case (Enum3)78:
				class36_0.method_2(new Class29((int)object_0, this));
				break;
			case (Enum3)79:
			{
				Class23 class31 = smethod_1(class36_0.method_4());
				Class23 class32 = smethod_1(class36_0.method_4());
				if (class32 != null && class31 != null)
				{
					class36_0.method_2(class32.vmethod_68(class31));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)80:
			{
				Class23 class23 = smethod_1(class36_0.method_4());
				Class23 class24 = smethod_1(class36_0.method_4());
				if (class24 != null && class23 != null)
				{
					class36_0.method_2(class24.vmethod_66(class23));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)81:
			{
				Class22 value2 = class36_0.method_4();
				object key = class36_0.method_4().vmethod_4(null);
				dictionary_1[key] = value2;
				break;
			}
			case (Enum3)82:
			{
				Class23 class22 = smethod_1(class36_0.method_4());
				if (class22 == null)
				{
					throw new Exception1();
				}
				class36_0.method_2(class22.vmethod_50());
				break;
			}
			case (Enum3)83:
				class36_0.method_2(new Class32((int)object_0, this));
				break;
			case (Enum3)84:
			{
				Class23 class5 = smethod_1(class36_0.method_4());
				if (class5 != null)
				{
					class36_0.method_2(class5.vmethod_72());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)85:
			{
				Class22 class2 = class36_0.method_4();
				if (class2 != null && class2.vmethod_7())
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			}
			case (Enum3)86:
				class36_0.method_2(new Class27((float)object_0));
				break;
			case (Enum3)87:
			{
				Class23 class155 = smethod_1(class36_0.method_4());
				if (class155 == null)
				{
					throw new Exception1();
				}
				class36_0.method_2(class155.vmethod_32());
				break;
			}
			case (Enum3)89:
			{
				Class23 class144 = smethod_1(class36_0.method_4());
				if (class144 == null)
				{
					throw new Exception1();
				}
				class36_0.method_2(class144.vmethod_54());
				break;
			}
			case (Enum3)90:
				class36_0.method_2(new Class27((double)object_0));
				break;
			case (Enum3)91:
			{
				Class23 class139 = smethod_1(class36_0.method_4());
				Class23 class140 = smethod_1(class36_0.method_4());
				if (class140 != null && class139 != null)
				{
					class36_0.method_2(class140.vmethod_65(class139));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)92:
			{
				Class23 class132 = smethod_1(class36_0.method_4());
				if (class132 != null)
				{
					class36_0.method_2(class132.vmethod_30());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)93:
			{
				Class22 class131 = class22_1[(int)object_0];
				class36_0.method_2(class131);
				break;
			}
			case (Enum3)94:
			{
				Class23 class124 = smethod_1(class36_0.method_4());
				Class23 class125 = smethod_1(class36_0.method_4());
				if (class125 != null && class124 != null)
				{
					class36_0.method_2(class125.vmethod_63(class124));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)95:
				class36_0.method_2(new Class34(null));
				break;
			case (Enum3)96:
			{
				Class22 class122 = class36_0.method_4();
				if (smethod_1(class36_0.method_4()).vmethod_78(class122))
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			}
			case (Enum3)97:
			{
				int metadataToken14 = (int)object_0;
				FieldInfo fieldInfo_2 = typeof(Class11).Module.ResolveField(metadataToken14);
				Class22 class123 = class36_0.method_4();
				class123.vmethod_8();
				object object_ = class123.vmethod_4(null);
				class36_0.method_2(new Class31(fieldInfo_2, object_));
				break;
			}
			case (Enum3)98:
			{
				Class23 class113 = smethod_1(class36_0.method_4());
				Class23 class114 = smethod_1(class36_0.method_4());
				if (class113 != null && class114 != null)
				{
					class36_0.method_2(class113.vmethod_73(class114));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)99:
			{
				Class23 class112 = smethod_1(class36_0.method_4());
				if (class112 != null)
				{
					class36_0.method_2(class112.vmethod_23());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)100:
			{
				Class23 class109 = smethod_1(class36_0.method_4());
				if (class109 != null)
				{
					class36_0.method_2(class109.vmethod_26());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)102:
			{
				Class23 class108 = smethod_1(class36_0.method_4());
				Array obj11 = (Array)class36_0.method_4().vmethod_4(null);
				object value14 = obj11.GetValue(class108.vmethod_19().struct1_0.int_0);
				Type elementType3 = obj11.GetType().GetElementType();
				class36_0.method_2(Class22.smethod_1(elementType3, value14));
				break;
			}
			case (Enum3)103:
			{
				Class22 class91 = class36_0.method_4();
				Class23 class92 = smethod_1(class91);
				if (class91 != null && class91.vmethod_0() && class92 != null)
				{
					class36_0.method_2(class92.vmethod_47());
					break;
				}
				if (class92 != null && class92.method_2())
				{
					IntPtr intPtr11 = ((Class26)class92).method_7();
					class36_0.method_2(new Class27(*(float*)(void*)intPtr11, (Enum1)9));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)105:
				class36_0.method_4();
				break;
			case (Enum3)106:
			{
				Class23 class87 = smethod_1(class36_0.method_4());
				if (class87 == null)
				{
					throw new Exception1();
				}
				class36_0.method_2(class87.vmethod_40());
				break;
			}
			case (Enum3)108:
			{
				Class22 class76 = class36_0.method_4();
				Class23 class77 = smethod_1(class76);
				if (class76 != null && class76.vmethod_0() && class77 != null)
				{
					class36_0.method_2(class77.vmethod_27());
					break;
				}
				if (class77 != null && class77.method_2())
				{
					IntPtr intPtr8 = ((Class26)class77).method_7();
					class36_0.method_2(new Class24(*(byte*)(void*)intPtr8, (Enum1)2));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)110:
				class36_0.method_2(new Class25((long)object_0));
				break;
			case (Enum3)111:
			{
				Class23 class71 = smethod_1(class36_0.method_4());
				if (class71 != null)
				{
					class36_0.method_2(class71.vmethod_42());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)112:
			{
				Class22 class66 = class36_0.method_4();
				if (class66 == null || !class66.vmethod_7())
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			}
			case (Enum3)113:
			{
				Class23 class63 = smethod_1(class36_0.method_4());
				Class23 class64 = smethod_1(class36_0.method_4());
				if (class63 != null && class64 != null)
				{
					class36_0.method_2(class63.vmethod_71(class64));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)114:
			{
				Class22 class53 = class36_0.method_4();
				Class23 class54 = smethod_1(class53);
				if (class53 != null && class53.vmethod_0() && class54 != null)
				{
					class36_0.method_2(class54.vmethod_48());
					break;
				}
				if (class54 != null && class54.method_2())
				{
					IntPtr intPtr7 = ((Class26)class54).method_7();
					class36_0.method_2(new Class27(*(double*)(void*)intPtr7, (Enum1)10));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)115:
				throw (Exception)class36_0.method_4().vmethod_4(null);
			case (Enum3)116:
			{
				Class22 class42 = class36_0.method_4();
				Class23 class43 = smethod_1(class42);
				if (class42 != null && class42.vmethod_0() && class43 != null)
				{
					class36_0.method_2(class43.vmethod_29());
					break;
				}
				if (class43 != null && class43.method_2())
				{
					IntPtr intPtr5 = ((Class26)class43).method_7();
					class36_0.method_2(new Class24(*(uint*)(void*)intPtr5, (Enum1)6));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)117:
			{
				Class23 class35 = smethod_1(class36_0.method_4());
				if (class35 == null)
				{
					throw new Exception1();
				}
				class36_0.method_2(class35.vmethod_28());
				break;
			}
			case (Enum3)118:
			{
				Class23 class25 = smethod_1(class36_0.method_4());
				Class23 class26 = smethod_1(class36_0.method_4());
				if (class26 != null && class25 != null)
				{
					class36_0.method_2(class26.vmethod_60(class25));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)119:
			{
				Class23 class27 = smethod_1(class36_0.method_4());
				Class23 class28 = smethod_1(class36_0.method_4());
				if (class28 != null && class27 != null)
				{
					class36_0.method_2(class28.vmethod_59(class27));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)120:
			{
				Class23 class18 = smethod_1(class36_0.method_4());
				if (class18 != null)
				{
					class36_0.method_2(class18.vmethod_48());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)1:
			case (Enum3)121:
			{
				int metadataToken = (int)object_0;
				Type type = typeof(Class11).Module.ResolveType(metadataToken);
				Class22 class3 = class36_0.method_4();
				object obj = class3.vmethod_4(type);
				if (obj != null)
				{
					if (type.IsValueType)
					{
						obj = smethod_9(obj);
					}
					class3 = Class22.smethod_1(type, obj);
				}
				else if (type.IsValueType)
				{
					obj = Activator.CreateInstance(type);
					class3 = Class22.smethod_1(type, obj);
				}
				else
				{
					class3 = new Class34(null);
				}
				((class36_0.method_4() as Class28) ?? throw new Exception1()).vmethod_10(class3);
				break;
			}
			case (Enum3)122:
			{
				Class23 class158 = smethod_1(class36_0.method_4());
				object value16 = ((Array)class36_0.method_4().vmethod_4(null)).GetValue(class158.vmethod_19().struct1_0.int_0);
				class36_0.method_2(Class22.smethod_1(typeof(IntPtr), value16));
				break;
			}
			case (Enum3)123:
			{
				int metadataToken19 = (int)object_0;
				Type type_3 = typeof(Class11).Module.ResolveType(metadataToken19);
				Class22 class156 = class36_0.method_4();
				Class23 class157 = smethod_1(class36_0.method_4());
				((Array)class36_0.method_4().vmethod_4(null)).SetValue(class156.vmethod_4(type_3), class157.vmethod_19().struct1_0.int_0);
				break;
			}
			case (Enum3)124:
			{
				Class23 class150 = smethod_1(class36_0.method_4());
				Class23 class151 = smethod_1(class36_0.method_4());
				if (class151 != null && class150 != null)
				{
					class36_0.method_2(class151.vmethod_58(class150));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)125:
			{
				Class23 class147 = smethod_1(class36_0.method_4());
				if (class147 != null)
				{
					class36_0.method_2(class147.vmethod_53());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)126:
			{
				int metadataToken17 = (int)object_0;
				Type type_2 = typeof(Class11).Module.ResolveType(metadataToken17);
				object obj16 = class36_0.method_4().vmethod_8().vmethod_4(type_2);
				Class22 class146 = Class22.smethod_1(type_2, obj16);
				class36_0.method_2(class146);
				break;
			}
			case (Enum3)128:
			{
				Class22 class137 = class36_0.method_4();
				Class23 class138 = smethod_1(class137);
				if (class137 != null && class137.vmethod_0() && class138 != null)
				{
					class36_0.method_2(class138.vmethod_24());
					break;
				}
				if (class138 != null && class138.method_2())
				{
					IntPtr intPtr14 = ((Class26)class138).method_7();
					class36_0.method_2(new Class24(*(short*)(void*)intPtr14, (Enum1)3));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)129:
			{
				Class23 class136 = smethod_1(class36_0.method_4());
				object value15 = ((Array)class36_0.method_4().vmethod_4(null)).GetValue(class136.vmethod_19().struct1_0.int_0);
				class36_0.method_2(Class22.smethod_1(typeof(short), value15));
				break;
			}
			case (Enum3)130:
			{
				Class22 class130 = class36_0.method_4();
				bool num5 = smethod_1(class36_0.method_4()).vmethod_85(class130);
				if (!num5)
				{
					class36_0.method_2(new Class24(0));
				}
				else
				{
					class36_0.method_2(new Class24(1));
				}
				if (num5)
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			}
			case (Enum3)131:
			{
				int metadataToken16 = (int)object_0;
				FieldInfo fieldInfo4 = typeof(Class11).Module.ResolveField(metadataToken16);
				object obj15 = class36_0.method_4().vmethod_4(null);
				class36_0.method_2(Class22.smethod_1(fieldInfo4.FieldType, fieldInfo4.GetValue(obj15)));
				break;
			}
			case (Enum3)132:
			{
				int metadataToken13 = (int)object_0;
				ConstructorInfo constructorInfo = (ConstructorInfo)typeof(Class11).Module.ResolveMethod(metadataToken13);
				ParameterInfo[] parameters = constructorInfo.GetParameters();
				object[] array4 = new object[parameters.Length];
				Class22[] array5 = new Class22[parameters.Length];
				List<Class18> list = null;
				Class19 class116 = null;
				for (int i = 0; i < parameters.Length; i++)
				{
					Class22 class117 = class36_0.method_4();
					Type type5 = parameters[parameters.Length - 1 - i].ParameterType;
					object obj12 = null;
					bool flag = false;
					if (type5.IsByRef && class117 is Class31 class118)
					{
						if (list == null)
						{
							list = new List<Class18>();
						}
						list.Add(new Class18(class118.fieldInfo_0, i));
						obj12 = class118.object_0;
						if (!(obj12 is Class22))
						{
							flag = true;
						}
						else
						{
							class117 = obj12 as Class22;
						}
					}
					if (!flag)
					{
						if (class117 != null)
						{
							obj12 = class117.vmethod_4(type5);
						}
						if (obj12 == null)
						{
							if (type5.IsByRef)
							{
								type5 = type5.GetElementType();
							}
							if (type5.IsValueType)
							{
								obj12 = Activator.CreateInstance(type5);
								if (class117 is Class29)
								{
									((Class28)class117).vmethod_12(Class22.smethod_1(type5, obj12));
								}
							}
						}
					}
					array5[array4.Length - 1 - i] = class117;
					array4[array4.Length - 1 - i] = obj12;
				}
				Delegate10 @delegate = null;
				if (list != null)
				{
					class116 = new Class19(constructorInfo, list);
					@delegate = smethod_4(constructorInfo, bool_4: true, class116);
				}
				object obj13 = null;
				obj13 = ((@delegate == null) ? constructorInfo.Invoke(array4) : @delegate(null, array4));
				for (int j = 0; j < parameters.Length; j++)
				{
					if (parameters[j].ParameterType.IsByRef && (class116 == null || !class116.method_1(j)))
					{
						if (array5[j].method_2())
						{
							((Class26)array5[j]).method_6(Class22.smethod_1(parameters[j].ParameterType, array4[j]));
						}
						else if (array5[j] is Class29)
						{
							array5[j].vmethod_10(Class22.smethod_1(parameters[j].ParameterType.GetElementType(), array4[j]));
						}
						else
						{
							array5[j].vmethod_10(Class22.smethod_1(parameters[j].ParameterType, array4[j]));
						}
					}
				}
				class36_0.method_2(Class22.smethod_1(constructorInfo.DeclaringType, obj13));
				break;
			}
			case (Enum3)133:
			{
				Class22 class110 = class36_0.method_4();
				Class23 class111 = smethod_1(class110);
				if (class110 != null && class110.vmethod_0() && class111 != null)
				{
					class36_0.method_2(class111.vmethod_26());
					break;
				}
				if (class111 != null && class111.method_2())
				{
					IntPtr intPtr13 = ((Class26)class111).method_7();
					class36_0.method_2(new Class25(*(long*)(void*)intPtr13, (Enum1)7));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)134:
				method_12(bool_4: true);
				break;
			case (Enum3)136:
			{
				Class23 class107 = smethod_1(class36_0.method_4());
				if (class107 != null)
				{
					class36_0.method_2(class107.vmethod_33());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)138:
			{
				Class22 class104 = class36_0.method_4();
				if (class104.vmethod_3())
				{
					class104 = ((Class23)class104).vmethod_48();
				}
				class36_0.method_4().vmethod_2(class104);
				break;
			}
			case (Enum3)140:
				int_0 = (int)object_0 - 1;
				break;
			case (Enum3)141:
			{
				Class23 class99 = smethod_1(class36_0.method_4());
				Class23 class100 = smethod_1(class36_0.method_4());
				if (class100 != null && class99 != null)
				{
					class36_0.method_2(class100.vmethod_62(class99));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)142:
			{
				Class22 class95 = class36_0.method_4();
				if (smethod_1(class36_0.method_4()).vmethod_80(class95))
				{
					class36_0.method_2(new Class24(1));
				}
				else
				{
					class36_0.method_2(new Class24(0));
				}
				break;
			}
			case (Enum3)30:
			case (Enum3)34:
			case (Enum3)51:
			case (Enum3)61:
			case (Enum3)65:
			case (Enum3)104:
			case (Enum3)143:
			case (Enum3)144:
			{
				Class22 class93 = class36_0.method_4();
				Class23 class94 = smethod_1(class36_0.method_4());
				Array obj10 = (Array)class36_0.method_4().vmethod_4(null);
				Type elementType2 = obj10.GetType().GetElementType();
				obj10.SetValue(class93.vmethod_4(elementType2), class94.vmethod_19().struct1_0.int_0);
				break;
			}
			case (Enum3)145:
			{
				Class23 class90 = smethod_1(class36_0.method_4());
				if (class90 != null)
				{
					class36_0.method_2(class90.vmethod_55());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)146:
			{
				Class22 class83 = class36_0.method_4();
				if (class83.vmethod_0())
				{
					object obj8 = class83.vmethod_4(null);
					class83 = ((obj8 != null) ? Class22.smethod_1(obj8.GetType(), obj8) : new Class34(null));
					class36_0.method_2(class83);
					break;
				}
				throw new Exception1();
			}
			case (Enum3)147:
			{
				Class22 class80 = class36_0.method_4();
				if (class80.vmethod_3())
				{
					class80 = ((Class23)class80).vmethod_25();
				}
				class36_0.method_4().vmethod_2(class80);
				break;
			}
			case (Enum3)148:
			{
				object key2 = class36_0.method_4().vmethod_4(null);
				Class22 value11 = null;
				if (dictionary_1.TryGetValue(key2, out value11))
				{
					class36_0.method_2(value11);
				}
				else
				{
					class36_0.method_2(new Class34(null));
				}
				break;
			}
			case (Enum3)149:
			{
				Class23 class75 = smethod_1(class36_0.method_4());
				if (class75 != null)
				{
					class36_0.method_2(class75.vmethod_24());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)150:
			{
				Class23 class73 = smethod_1(class36_0.method_4());
				if (class73 != null)
				{
					class36_0.method_2(class73.vmethod_45());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)151:
			{
				Class23 class70 = smethod_1(class36_0.method_4());
				if (class70 == null)
				{
					throw new Exception1();
				}
				class36_0.method_2(class70.vmethod_37());
				break;
			}
			case (Enum3)27:
			case (Enum3)29:
			case (Enum3)70:
			case (Enum3)88:
			case (Enum3)107:
			case (Enum3)152:
				throw new Exception1();
			case (Enum3)153:
			{
				int num4 = (int)object_0;
				class22_1[num4] = method_8(class36_0.method_4(), class17_0.list_1[num4].enum1_0, class17_0.list_1[num4].bool_0);
				break;
			}
			case (Enum3)154:
			{
				Type type3 = typeof(Class11).Module.ResolveType((int)object_0);
				object obj7 = class36_0.method_4().vmethod_4(type3);
				if (obj7 == null)
				{
					obj7 = Activator.CreateInstance(type3);
				}
				class36_0.method_2(new Class34(Class22.smethod_1(type3, smethod_9(obj7))));
				break;
			}
			case (Enum3)155:
				class36_0.method_2(new Class24((int)object_0));
				break;
			case (Enum3)156:
			{
				Class22 class65 = class36_0.method_4();
				if (class65.vmethod_3())
				{
					class65 = ((Class23)class65).vmethod_47();
				}
				class36_0.method_4().vmethod_2(class65);
				break;
			}
			case (Enum3)157:
			{
				Class23 class59 = smethod_1(class36_0.method_4());
				Class23 class60 = (Class23)class36_0.method_4();
				if (class60 != null && class59 != null)
				{
					class36_0.method_2(class60.vmethod_61(class59));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)158:
			{
				int num3 = (int)object_0;
				if (!((MethodBase)class17_0.object_0).IsStatic)
				{
					class22_0[num3] = method_8(class36_0.method_4(), class17_0.class13_0[num3 - 1].enum1_0);
				}
				else
				{
					class22_0[num3] = method_8(class36_0.method_4(), class17_0.class13_0[num3].enum1_0);
				}
				break;
			}
			case (Enum3)159:
			{
				Class23 class58 = smethod_1(class36_0.method_4());
				if (class58 == null)
				{
					throw new Exception1();
				}
				class36_0.method_2(class58.vmethod_25());
				break;
			}
			case (Enum3)160:
			{
				Class23 class56 = smethod_1(class36_0.method_4());
				if (class56 != null)
				{
					class36_0.method_2(class56.vmethod_31());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)161:
			{
				Class23 class52 = smethod_1(class36_0.method_4());
				if (class52 == null)
				{
					throw new Exception1();
				}
				class36_0.method_2(class52.vmethod_43());
				break;
			}
			case (Enum3)162:
			{
				Class22 class44 = class36_0.method_4();
				Class23 class45 = smethod_1(class44);
				if (class44 != null && class44.vmethod_0() && class45 != null)
				{
					class36_0.method_2(class45.vmethod_23());
					break;
				}
				if (class45 != null && class45.method_2())
				{
					IntPtr intPtr6 = ((Class26)class45).method_7();
					class36_0.method_2(new Class24(*(sbyte*)(void*)intPtr6, (Enum1)1));
					break;
				}
				throw new Exception1();
			}
			case (Enum3)163:
			{
				Class23 class41 = class36_0.method_4() as Class23;
				IntPtr intPtr3 = smethod_8(class36_0.method_4());
				IntPtr intPtr4 = smethod_8(class36_0.method_4());
				if (intPtr3 != IntPtr.Zero && intPtr4 != IntPtr.Zero)
				{
					uint uint_2 = class41.vmethod_20().struct1_0.uint_0;
					smethod_11(intPtr4, intPtr3, uint_2);
				}
				break;
			}
			case (Enum3)164:
			{
				Class22 class39 = class36_0.method_4();
				if (smethod_1(class36_0.method_4()).vmethod_83(class39))
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			}
			case (Enum3)165:
			{
				Class23 class38 = smethod_1(class36_0.method_4());
				object value4 = ((Array)class36_0.method_4().vmethod_4(null)).GetValue(class38.vmethod_19().struct1_0.int_0);
				class36_0.method_2(Class22.smethod_1(typeof(double), value4));
				break;
			}
			case (Enum3)166:
			{
				Class22 class36 = class36_0.method_4();
				if (smethod_1(class36_0.method_4()).vmethod_82(class36))
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			}
			case (Enum3)167:
			{
				Class22 class34 = class36_0.method_4();
				if (smethod_1(class36_0.method_4()).vmethod_79(class34))
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			}
			case (Enum3)168:
			{
				Class23 class30 = smethod_1(class36_0.method_4());
				if (class30 != null)
				{
					class36_0.method_2(class30.vmethod_38());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)169:
			{
				Class22 class29 = class36_0.method_4();
				if (smethod_1(class36_0.method_4()).vmethod_84(class29))
				{
					int_0 = (int)object_0 - 1;
				}
				break;
			}
			case (Enum3)170:
			{
				Class22 class16 = class36_0.method_4();
				Class23 class17 = smethod_1(class16);
				if (class16 != null && class16.vmethod_0() && class17 != null)
				{
					class36_0.method_2(class17.vmethod_50());
					break;
				}
				if (class17 != null && class17.method_2())
				{
					IntPtr intPtr2 = ((Class26)class17).method_7();
					if (IntPtr.Size == 8)
					{
						long long_ = *(long*)(void*)intPtr2;
						class36_0.method_2(new Class26(long_, (Enum1)12));
					}
					else
					{
						int num = *(int*)(void*)intPtr2;
						class36_0.method_2(new Class26(num, (Enum1)12));
					}
					break;
				}
				throw new Exception1();
			}
			case (Enum3)171:
			{
				Class23 class15 = smethod_1(class36_0.method_4());
				if (class15 == null)
				{
					throw new Exception1();
				}
				class36_0.method_2(class15.vmethod_34());
				break;
			}
			case (Enum3)172:
			{
				int metadataToken2 = (int)object_0;
				Module module = typeof(Class11).Module;
				object obj2 = null;
				try
				{
					obj2 = module.ResolveType(metadataToken2);
				}
				catch
				{
					try
					{
						obj2 = module.ResolveMethod(metadataToken2);
					}
					catch
					{
						try
						{
							obj2 = module.ResolveField(metadataToken2);
							goto end_IL_2ea7;
						}
						catch
						{
							obj2 = module.ResolveMember(metadataToken2);
							goto end_IL_2ea7;
						}
						end_IL_2ea7:;
					}
				}
				class36_0.method_2(new Class34(obj2));
				break;
			}
			case (Enum3)173:
			{
				Class23 class8 = smethod_1(class36_0.method_4());
				if (class8 != null)
				{
					class36_0.method_2(class8.vmethod_27());
					break;
				}
				throw new Exception1();
			}
			case (Enum3)174:
			{
				Class23 class4 = smethod_1(class36_0.method_4());
				if (class4 == null)
				{
					throw new Exception1();
				}
				class36_0.method_2(class4.vmethod_52());
				break;
			}
			case (Enum3)175:
			{
				Class22 @class = class36_0.method_4();
				if (@class.vmethod_3())
				{
					@class = ((Class23)@class).vmethod_26();
				}
				class36_0.method_4().vmethod_2(@class);
				break;
			}
			case (Enum3)67:
			case (Enum3)101:
			case (Enum3)109:
			case (Enum3)127:
			case (Enum3)135:
			case (Enum3)137:
			case (Enum3)139:
				break;
			}
		}

		private Class22 method_8(Class22 class22_3, Enum1 enum1_0, bool bool_4 = false)
		{
			if (!bool_4 && class22_3.vmethod_0())
			{
				class22_3 = class22_3.vmethod_8();
			}
			if (!class22_3.method_1())
			{
				if (!class22_3.method_3())
				{
					if (!class22_3.method_4())
					{
						if (!class22_3.method_2())
						{
							return class22_3;
						}
						return ((Class26)class22_3).vmethod_13(enum1_0);
					}
					return ((Class27)class22_3).vmethod_13(enum1_0);
				}
				return ((Class25)class22_3).vmethod_13(enum1_0);
			}
			return ((Class24)class22_3).vmethod_13(enum1_0);
		}

		private Class22 method_9(int int_3)
		{
			return class22_1[int_3];
		}

		private void method_10(int int_3)
		{
			method_11(int_3, class36_0.method_4());
		}

		private static int smethod_0(Type type_0)
		{
			if (dictionary_0 == null)
			{
				dictionary_0 = new Dictionary<Type, int>();
			}
			try
			{
				int value = 0;
				if (!dictionary_0.TryGetValue(type_0, out value))
				{
					DynamicMethod dynamicMethod = new DynamicMethod(string.Empty, typeof(int), Type.EmptyTypes, restrictedSkipVisibility: true);
					ILGenerator iLGenerator = dynamicMethod.GetILGenerator();
					iLGenerator.Emit(OpCodes.Sizeof, type_0);
					iLGenerator.Emit(OpCodes.Ret);
					value = (int)dynamicMethod.Invoke(null, null);
					dictionary_0[type_0] = value;
					return value;
				}
				return value;
			}
			catch
			{
				return 0;
			}
		}

		private void method_11(int int_3, Class22 class22_3)
		{
			class22_1[int_3] = method_8(class22_3, class17_0.list_1[int_3].enum1_0, class17_0.list_1[int_3].bool_0);
		}

		private static Class23 smethod_1(Class22 class22_3)
		{
			Class23 @class = class22_3 as Class23;
			if (@class == null && class22_3.vmethod_0())
			{
				@class = class22_3.vmethod_8() as Class23;
			}
			return @class;
		}

		private void method_12(bool bool_4)
		{
			int metadataToken = (int)object_0;
			MethodBase methodBase = typeof(Class11).Module.ResolveMethod(metadataToken);
			MethodInfo methodInfo = methodBase as MethodInfo;
			ParameterInfo[] parameters = methodBase.GetParameters();
			object[] array = new object[parameters.Length];
			Class22[] array2 = new Class22[parameters.Length];
			List<Class18> list = null;
			Class19 @class = null;
			for (int i = 0; i < parameters.Length; i++)
			{
				Class22 class2 = class36_0.method_4();
				Type type = parameters[parameters.Length - 1 - i].ParameterType;
				object obj = null;
				bool flag = false;
				if (type.IsByRef && class2 is Class31 class3)
				{
					if (list == null)
					{
						list = new List<Class18>();
					}
					list.Add(new Class18(class3.fieldInfo_0, i));
					obj = class3.object_0;
					if (obj is Class22)
					{
						class2 = obj as Class22;
					}
					else
					{
						flag = true;
					}
				}
				if (!flag)
				{
					if (class2 != null)
					{
						obj = class2.vmethod_4(type);
					}
					if (obj == null)
					{
						if (type.IsByRef)
						{
							type = type.GetElementType();
						}
						if (type.IsValueType)
						{
							obj = Activator.CreateInstance(type);
							if (class2 is Class29)
							{
								((Class28)class2).vmethod_12(Class22.smethod_1(type, obj));
							}
						}
					}
				}
				array2[array.Length - 1 - i] = class2;
				array[array.Length - 1 - i] = obj;
			}
			Delegate10 @delegate = null;
			if (list == null)
			{
				if (methodInfo != null && methodInfo.ReturnType.IsByRef)
				{
					@delegate = smethod_2(methodBase, bool_4);
				}
			}
			else
			{
				@class = new Class19(methodBase, list);
				@delegate = smethod_3(methodBase, bool_4, @class);
			}
			object obj2 = null;
			Class22 class4 = null;
			if (!methodBase.IsStatic)
			{
				class4 = class36_0.method_4();
				if (class4 != null)
				{
					obj2 = class4.vmethod_4(methodBase.DeclaringType);
				}
				if (obj2 == null)
				{
					Type type2 = methodBase.DeclaringType;
					if (type2.IsByRef)
					{
						type2 = type2.GetElementType();
					}
					if (!type2.IsValueType)
					{
						throw new NullReferenceException();
					}
					obj2 = Activator.CreateInstance(type2);
					if (class4 is Class29)
					{
						((Class28)class4).vmethod_12(Class22.smethod_1(type2, obj2));
					}
				}
			}
			object obj3 = null;
			obj3 = ((@delegate != null) ? @delegate(obj2, array) : methodBase.Invoke(obj2, array));
			for (int j = 0; j < parameters.Length; j++)
			{
				if (parameters[j].ParameterType.IsByRef && (@class == null || !@class.method_1(j)))
				{
					if (array2[j].method_2())
					{
						((Class26)array2[j]).method_6(Class22.smethod_1(parameters[j].ParameterType, array[j]));
					}
					else if (array2[j] is Class29)
					{
						array2[j].vmethod_10(Class22.smethod_1(parameters[j].ParameterType.GetElementType(), array[j]));
					}
					else
					{
						array2[j].vmethod_10(Class22.smethod_1(parameters[j].ParameterType, array[j]));
					}
				}
			}
			if (methodInfo != null && methodInfo.ReturnType != typeof(void))
			{
				class36_0.method_2(Class22.smethod_1(methodInfo.ReturnType, obj3));
			}
		}

		private static Delegate10 smethod_2(object object_1, bool bool_4)
		{
			Delegate10 value = null;
			if (bool_4)
			{
				if (dictionary_2.TryGetValue((MethodBase)object_1, out value))
				{
					return value;
				}
			}
			else if (dictionary_3.TryGetValue((MethodBase)object_1, out value))
			{
				return value;
			}
			MethodInfo methodInfo = object_1 as MethodInfo;
			DynamicMethod dynamicMethod = new DynamicMethod(string.Empty, typeof(object), new Type[2]
			{
				typeof(object),
				typeof(object[])
			}, restrictedSkipVisibility: true);
			ILGenerator iLGenerator = dynamicMethod.GetILGenerator();
			ParameterInfo[] parameters = ((MethodBase)object_1).GetParameters();
			Type[] array = new Type[parameters.Length];
			for (int i = 0; i < array.Length; i++)
			{
				if (!parameters[i].ParameterType.IsByRef)
				{
					array[i] = parameters[i].ParameterType;
				}
				else
				{
					array[i] = parameters[i].ParameterType.GetElementType();
				}
			}
			int num = array.Length;
			if (((MemberInfo)object_1).DeclaringType.IsValueType)
			{
				num++;
			}
			LocalBuilder[] array2 = new LocalBuilder[num];
			for (int j = 0; j < array.Length; j++)
			{
				array2[j] = iLGenerator.DeclareLocal(array[j]);
			}
			if (((MemberInfo)object_1).DeclaringType.IsValueType)
			{
				array2[^1] = iLGenerator.DeclareLocal(((MemberInfo)object_1).DeclaringType.MakeByRefType());
			}
			for (int k = 0; k < array.Length; k++)
			{
				iLGenerator.Emit(OpCodes.Ldarg_1);
				smethod_5(iLGenerator, k);
				iLGenerator.Emit(OpCodes.Ldelem_Ref);
				if (array[k].IsValueType)
				{
					iLGenerator.Emit(OpCodes.Unbox_Any, array[k]);
				}
				else if (array[k] != typeof(object))
				{
					iLGenerator.Emit(OpCodes.Castclass, array[k]);
				}
				iLGenerator.Emit(OpCodes.Stloc, array2[k]);
			}
			if (!((MethodBase)object_1).IsStatic)
			{
				iLGenerator.Emit(OpCodes.Ldarg_0);
				if (((MemberInfo)object_1).DeclaringType.IsValueType)
				{
					iLGenerator.Emit(OpCodes.Unbox, ((MemberInfo)object_1).DeclaringType);
					iLGenerator.Emit(OpCodes.Stloc, array2[^1]);
					iLGenerator.Emit(OpCodes.Ldloc_S, array2[^1]);
				}
				else
				{
					iLGenerator.Emit(OpCodes.Castclass, ((MemberInfo)object_1).DeclaringType);
				}
			}
			for (int l = 0; l < array.Length; l++)
			{
				if (!parameters[l].ParameterType.IsByRef)
				{
					iLGenerator.Emit(OpCodes.Ldloc, array2[l]);
				}
				else
				{
					iLGenerator.Emit(OpCodes.Ldloca_S, array2[l]);
				}
			}
			if (bool_4)
			{
				if (!(methodInfo != null))
				{
					iLGenerator.Emit(OpCodes.Call, object_1 as ConstructorInfo);
				}
				else
				{
					iLGenerator.EmitCall(OpCodes.Call, methodInfo, null);
				}
			}
			else if (methodInfo != null)
			{
				iLGenerator.EmitCall(OpCodes.Callvirt, methodInfo, null);
			}
			else
			{
				iLGenerator.Emit(OpCodes.Callvirt, object_1 as ConstructorInfo);
			}
			if (!(methodInfo == null) && !(methodInfo.ReturnType == typeof(void)))
			{
				if (!methodInfo.ReturnType.IsByRef)
				{
					if (methodInfo.ReturnType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Box, methodInfo.ReturnType);
					}
				}
				else
				{
					Type elementType = methodInfo.ReturnType.GetElementType();
					if (elementType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Ldobj, elementType);
					}
					else
					{
						iLGenerator.Emit(OpCodes.Ldind_Ref, elementType);
					}
					if (elementType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Box, elementType);
					}
				}
			}
			else
			{
				iLGenerator.Emit(OpCodes.Ldnull);
			}
			for (int m = 0; m < array.Length; m++)
			{
				if (parameters[m].ParameterType.IsByRef)
				{
					iLGenerator.Emit(OpCodes.Ldarg_1);
					smethod_5(iLGenerator, m);
					iLGenerator.Emit(OpCodes.Ldloc, array2[m]);
					if (array2[m].LocalType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Box, array2[m].LocalType);
					}
					iLGenerator.Emit(OpCodes.Stelem_Ref);
				}
			}
			iLGenerator.Emit(OpCodes.Ret);
			Delegate10 @delegate = (Delegate10)dynamicMethod.CreateDelegate(typeof(Delegate10));
			if (!bool_4)
			{
				dictionary_3.Add((MethodBase)object_1, @delegate);
			}
			else
			{
				dictionary_2.Add((MethodBase)object_1, @delegate);
			}
			return @delegate;
		}

		private static Delegate10 smethod_3(object object_1, bool bool_4, Class19 class19_0)
		{
			Delegate10 value = null;
			if (bool_4)
			{
				if (dictionary_4.TryGetValue(class19_0, out value))
				{
					return value;
				}
			}
			else if (dictionary_5.TryGetValue(class19_0, out value))
			{
				return value;
			}
			MethodInfo methodInfo = object_1 as MethodInfo;
			DynamicMethod dynamicMethod = new DynamicMethod(string.Empty, typeof(object), new Type[2]
			{
				typeof(object),
				typeof(object[])
			}, typeof(Class11), skipVisibility: true);
			ILGenerator iLGenerator = dynamicMethod.GetILGenerator();
			ParameterInfo[] parameters = ((MethodBase)object_1).GetParameters();
			Type[] array = new Type[parameters.Length];
			for (int i = 0; i < array.Length; i++)
			{
				if (parameters[i].ParameterType.IsByRef)
				{
					array[i] = parameters[i].ParameterType.GetElementType();
				}
				else
				{
					array[i] = parameters[i].ParameterType;
				}
			}
			int num = array.Length;
			if (((MemberInfo)object_1).DeclaringType.IsValueType)
			{
				num++;
			}
			LocalBuilder[] array2 = new LocalBuilder[num];
			for (int j = 0; j < array.Length; j++)
			{
				if (!class19_0.method_1(j))
				{
					array2[j] = iLGenerator.DeclareLocal(array[j]);
				}
				else
				{
					array2[j] = iLGenerator.DeclareLocal(typeof(object));
				}
			}
			if (((MemberInfo)object_1).DeclaringType.IsValueType)
			{
				array2[^1] = iLGenerator.DeclareLocal(((MemberInfo)object_1).DeclaringType.MakeByRefType());
			}
			for (int k = 0; k < array.Length; k++)
			{
				iLGenerator.Emit(OpCodes.Ldarg_1);
				smethod_5(iLGenerator, k);
				iLGenerator.Emit(OpCodes.Ldelem_Ref);
				if (!class19_0.method_1(k))
				{
					if (array[k].IsValueType)
					{
						iLGenerator.Emit(OpCodes.Unbox_Any, array[k]);
					}
					else if (array[k] != typeof(object))
					{
						iLGenerator.Emit(OpCodes.Castclass, array[k]);
					}
				}
				iLGenerator.Emit(OpCodes.Stloc, array2[k]);
			}
			if (!((MethodBase)object_1).IsStatic)
			{
				iLGenerator.Emit(OpCodes.Ldarg_0);
				if (((MemberInfo)object_1).DeclaringType.IsValueType)
				{
					iLGenerator.Emit(OpCodes.Unbox, ((MemberInfo)object_1).DeclaringType);
					iLGenerator.Emit(OpCodes.Stloc, array2[^1]);
					iLGenerator.Emit(OpCodes.Ldloc_S, array2[^1]);
				}
				else
				{
					iLGenerator.Emit(OpCodes.Castclass, ((MemberInfo)object_1).DeclaringType);
				}
			}
			for (int l = 0; l < array.Length; l++)
			{
				if (class19_0.method_1(l))
				{
					Class18 @class = class19_0.method_0(l);
					if (!((FieldInfo)@class.object_0).IsStatic)
					{
						if (((MemberInfo)@class.object_0).DeclaringType.IsValueType)
						{
							iLGenerator.Emit(OpCodes.Ldloc, array2[l]);
							iLGenerator.Emit(OpCodes.Unbox, ((MemberInfo)@class.object_0).DeclaringType);
							iLGenerator.Emit(OpCodes.Ldflda, (FieldInfo)@class.object_0);
						}
						else
						{
							iLGenerator.Emit(OpCodes.Ldloc, array2[l]);
							iLGenerator.Emit(OpCodes.Castclass, ((MemberInfo)@class.object_0).DeclaringType);
							iLGenerator.Emit(OpCodes.Ldflda, (FieldInfo)@class.object_0);
						}
					}
					else
					{
						iLGenerator.Emit(OpCodes.Ldsflda, (FieldInfo)@class.object_0);
					}
				}
				else if (!parameters[l].ParameterType.IsByRef)
				{
					iLGenerator.Emit(OpCodes.Ldloc, array2[l]);
				}
				else
				{
					iLGenerator.Emit(OpCodes.Ldloca_S, array2[l]);
				}
			}
			if (bool_4)
			{
				if (methodInfo != null)
				{
					iLGenerator.EmitCall(OpCodes.Call, methodInfo, null);
				}
				else
				{
					iLGenerator.Emit(OpCodes.Call, object_1 as ConstructorInfo);
				}
			}
			else if (!(methodInfo != null))
			{
				iLGenerator.Emit(OpCodes.Callvirt, object_1 as ConstructorInfo);
			}
			else
			{
				iLGenerator.EmitCall(OpCodes.Callvirt, methodInfo, null);
			}
			if (!(methodInfo == null) && !(methodInfo.ReturnType == typeof(void)))
			{
				if (!methodInfo.ReturnType.IsByRef)
				{
					if (methodInfo.ReturnType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Box, methodInfo.ReturnType);
					}
				}
				else
				{
					Type elementType = methodInfo.ReturnType.GetElementType();
					if (!elementType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Ldind_Ref, elementType);
					}
					else
					{
						iLGenerator.Emit(OpCodes.Ldobj, elementType);
					}
					if (elementType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Box, elementType);
					}
				}
			}
			else
			{
				iLGenerator.Emit(OpCodes.Ldnull);
			}
			for (int m = 0; m < array.Length; m++)
			{
				if (!parameters[m].ParameterType.IsByRef)
				{
					continue;
				}
				if (!class19_0.method_1(m))
				{
					iLGenerator.Emit(OpCodes.Ldarg_1);
					smethod_5(iLGenerator, m);
					iLGenerator.Emit(OpCodes.Ldloc, array2[m]);
					if (array2[m].LocalType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Box, array2[m].LocalType);
					}
					iLGenerator.Emit(OpCodes.Stelem_Ref);
					continue;
				}
				Class18 class2 = class19_0.method_0(m);
				if (((FieldInfo)class2.object_0).IsStatic)
				{
					iLGenerator.Emit(OpCodes.Ldarg_1);
					smethod_5(iLGenerator, m);
					iLGenerator.Emit(OpCodes.Ldsfld, (FieldInfo)class2.object_0);
					if (((FieldInfo)class2.object_0).FieldType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Box, array2[m].LocalType);
					}
					iLGenerator.Emit(OpCodes.Stelem_Ref);
				}
				else
				{
					iLGenerator.Emit(OpCodes.Ldarg_1);
					smethod_5(iLGenerator, m);
					iLGenerator.Emit(OpCodes.Ldloc, array2[m]);
					if (array2[m].LocalType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Box, array2[m].LocalType);
					}
					iLGenerator.Emit(OpCodes.Stelem_Ref);
				}
			}
			iLGenerator.Emit(OpCodes.Ret);
			Delegate10 @delegate = (Delegate10)dynamicMethod.CreateDelegate(typeof(Delegate10));
			if (bool_4)
			{
				dictionary_4.Add(class19_0, @delegate);
			}
			else
			{
				dictionary_5.Add(class19_0, @delegate);
			}
			return @delegate;
		}

		private static Delegate10 smethod_4(object object_1, bool bool_4, Class19 class19_0)
		{
			Delegate10 value = null;
			if (dictionary_6.TryGetValue(class19_0, out value))
			{
				return value;
			}
			ConstructorInfo constructorInfo = object_1 as ConstructorInfo;
			DynamicMethod dynamicMethod = new DynamicMethod(string.Empty, typeof(object), new Type[2]
			{
				typeof(object),
				typeof(object[])
			}, typeof(Class11), skipVisibility: true);
			ILGenerator iLGenerator = dynamicMethod.GetILGenerator();
			ParameterInfo[] parameters = ((MethodBase)object_1).GetParameters();
			Type[] array = new Type[parameters.Length];
			for (int i = 0; i < array.Length; i++)
			{
				if (!parameters[i].ParameterType.IsByRef)
				{
					array[i] = parameters[i].ParameterType;
				}
				else
				{
					array[i] = parameters[i].ParameterType.GetElementType();
				}
			}
			int num = array.Length;
			if (((MemberInfo)object_1).DeclaringType.IsValueType)
			{
				num++;
			}
			LocalBuilder[] array2 = new LocalBuilder[num];
			for (int j = 0; j < array.Length; j++)
			{
				if (class19_0.method_1(j))
				{
					array2[j] = iLGenerator.DeclareLocal(typeof(object));
				}
				else
				{
					array2[j] = iLGenerator.DeclareLocal(array[j]);
				}
			}
			if (((MemberInfo)object_1).DeclaringType.IsValueType)
			{
				array2[^1] = iLGenerator.DeclareLocal(((MemberInfo)object_1).DeclaringType.MakeByRefType());
			}
			for (int k = 0; k < array.Length; k++)
			{
				iLGenerator.Emit(OpCodes.Ldarg_1);
				smethod_5(iLGenerator, k);
				iLGenerator.Emit(OpCodes.Ldelem_Ref);
				if (!class19_0.method_1(k))
				{
					if (!array[k].IsValueType)
					{
						if (array[k] != typeof(object))
						{
							iLGenerator.Emit(OpCodes.Castclass, array[k]);
						}
					}
					else
					{
						iLGenerator.Emit(OpCodes.Unbox_Any, array[k]);
					}
				}
				iLGenerator.Emit(OpCodes.Stloc, array2[k]);
			}
			for (int l = 0; l < array.Length; l++)
			{
				if (class19_0.method_1(l))
				{
					Class18 @class = class19_0.method_0(l);
					if (((FieldInfo)@class.object_0).IsStatic)
					{
						iLGenerator.Emit(OpCodes.Ldsflda, (FieldInfo)@class.object_0);
					}
					else if (((MemberInfo)@class.object_0).DeclaringType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Ldloc, array2[l]);
						iLGenerator.Emit(OpCodes.Unbox, ((MemberInfo)@class.object_0).DeclaringType);
						iLGenerator.Emit(OpCodes.Ldflda, (FieldInfo)@class.object_0);
					}
					else
					{
						iLGenerator.Emit(OpCodes.Ldloc, array2[l]);
						iLGenerator.Emit(OpCodes.Castclass, ((MemberInfo)@class.object_0).DeclaringType);
						iLGenerator.Emit(OpCodes.Ldflda, (FieldInfo)@class.object_0);
					}
				}
				else if (!parameters[l].ParameterType.IsByRef)
				{
					iLGenerator.Emit(OpCodes.Ldloc, array2[l]);
				}
				else
				{
					iLGenerator.Emit(OpCodes.Ldloca_S, array2[l]);
				}
			}
			iLGenerator.Emit(OpCodes.Newobj, object_1 as ConstructorInfo);
			if (constructorInfo.DeclaringType.IsValueType)
			{
				iLGenerator.Emit(OpCodes.Box, constructorInfo.DeclaringType);
			}
			for (int m = 0; m < array.Length; m++)
			{
				if (!parameters[m].ParameterType.IsByRef)
				{
					continue;
				}
				if (class19_0.method_1(m))
				{
					Class18 class2 = class19_0.method_0(m);
					if (((FieldInfo)class2.object_0).IsStatic)
					{
						iLGenerator.Emit(OpCodes.Ldarg_1);
						smethod_5(iLGenerator, m);
						iLGenerator.Emit(OpCodes.Ldsfld, (FieldInfo)class2.object_0);
						if (((FieldInfo)class2.object_0).FieldType.IsValueType)
						{
							iLGenerator.Emit(OpCodes.Box, array2[m].LocalType);
						}
						iLGenerator.Emit(OpCodes.Stelem_Ref);
					}
					else
					{
						iLGenerator.Emit(OpCodes.Ldarg_1);
						smethod_5(iLGenerator, m);
						iLGenerator.Emit(OpCodes.Ldloc, array2[m]);
						if (array2[m].LocalType.IsValueType)
						{
							iLGenerator.Emit(OpCodes.Box, array2[m].LocalType);
						}
						iLGenerator.Emit(OpCodes.Stelem_Ref);
					}
				}
				else
				{
					iLGenerator.Emit(OpCodes.Ldarg_1);
					smethod_5(iLGenerator, m);
					iLGenerator.Emit(OpCodes.Ldloc, array2[m]);
					if (array2[m].LocalType.IsValueType)
					{
						iLGenerator.Emit(OpCodes.Box, array2[m].LocalType);
					}
					iLGenerator.Emit(OpCodes.Stelem_Ref);
				}
			}
			iLGenerator.Emit(OpCodes.Ret);
			Delegate10 @delegate = (Delegate10)dynamicMethod.CreateDelegate(typeof(Delegate10));
			dictionary_6.Add(class19_0, @delegate);
			return @delegate;
		}

		private static void smethod_5(ILGenerator ilgenerator_0, int int_3)
		{
			switch (int_3)
			{
			case -1:
				ilgenerator_0.Emit(OpCodes.Ldc_I4_M1);
				return;
			case 0:
				ilgenerator_0.Emit(OpCodes.Ldc_I4_0);
				return;
			case 1:
				ilgenerator_0.Emit(OpCodes.Ldc_I4_1);
				return;
			case 2:
				ilgenerator_0.Emit(OpCodes.Ldc_I4_2);
				return;
			case 3:
				ilgenerator_0.Emit(OpCodes.Ldc_I4_3);
				return;
			case 4:
				ilgenerator_0.Emit(OpCodes.Ldc_I4_4);
				return;
			case 5:
				ilgenerator_0.Emit(OpCodes.Ldc_I4_5);
				return;
			case 6:
				ilgenerator_0.Emit(OpCodes.Ldc_I4_6);
				return;
			case 7:
				ilgenerator_0.Emit(OpCodes.Ldc_I4_7);
				return;
			case 8:
				ilgenerator_0.Emit(OpCodes.Ldc_I4_8);
				return;
			}
			if (int_3 > -129 && int_3 < 128)
			{
				ilgenerator_0.Emit(OpCodes.Ldc_I4_S, (sbyte)int_3);
			}
			else
			{
				ilgenerator_0.Emit(OpCodes.Ldc_I4, int_3);
			}
		}

		private static Class22 smethod_6(Class22 class22_3)
		{
			if (class22_3.vmethod_8().method_0())
			{
				object obj = class22_3.vmethod_4(null);
				if (obj != null && obj.GetType().IsEnum)
				{
					Type underlyingType = Enum.GetUnderlyingType(obj.GetType());
					object obj2 = Convert.ChangeType(obj, underlyingType);
					Class22 @class = smethod_7(Class22.smethod_1(underlyingType, obj2));
					if (@class != null)
					{
						return @class as Class23;
					}
				}
			}
			return class22_3;
		}

		private static Class23 smethod_7(Class22 class22_3)
		{
			Class23 @class = class22_3 as Class23;
			if (@class == null && class22_3.vmethod_0())
			{
				@class = class22_3.vmethod_8() as Class23;
			}
			return @class;
		}

		private static IntPtr smethod_8(object object_1)
		{
			if (object_1 == null)
			{
				return IntPtr.Zero;
			}
			if (((Class22)object_1).method_2())
			{
				return ((Class26)object_1).method_7();
			}
			if (((Class22)object_1).vmethod_0())
			{
				Class28 @class = (Class28)object_1;
				try
				{
					return @class.vmethod_11();
				}
				catch
				{
				}
			}
			object obj2 = ((Class22)object_1).vmethod_4(typeof(IntPtr));
			if (obj2 == null || !(obj2.GetType() == typeof(IntPtr)))
			{
				throw new Exception1();
			}
			return (IntPtr)obj2;
		}

		private static object smethod_9(object object_1)
		{
			if (dictionary_7 == null)
			{
				dictionary_7 = new Dictionary<Type, Delegate11>();
			}
			if (object_1 == null)
			{
				return null;
			}
			try
			{
				Type type = object_1.GetType();
				if (dictionary_7.TryGetValue(type, out var value))
				{
					return value(object_1);
				}
				DynamicMethod dynamicMethod = new DynamicMethod(string.Empty, typeof(object), new Type[1] { typeof(object) }, restrictedSkipVisibility: true);
				ILGenerator iLGenerator = dynamicMethod.GetILGenerator();
				iLGenerator.Emit(OpCodes.Ldarg_0);
				iLGenerator.Emit(OpCodes.Unbox_Any, type);
				iLGenerator.Emit(OpCodes.Box, type);
				iLGenerator.Emit(OpCodes.Ret);
				Delegate11 @delegate = (Delegate11)dynamicMethod.CreateDelegate(typeof(Delegate11));
				dictionary_7.Add(type, @delegate);
				return @delegate(object_1);
			}
			catch
			{
				return null;
			}
		}

		private static void smethod_10(IntPtr intptr_0, byte byte_0, int int_3)
		{
			if (delegate12_0 == null)
			{
				DynamicMethod dynamicMethod = new DynamicMethod(string.Empty, typeof(void), new Type[3]
				{
					typeof(IntPtr),
					typeof(byte),
					typeof(int)
				}, typeof(Class11), skipVisibility: true);
				ILGenerator iLGenerator = dynamicMethod.GetILGenerator();
				iLGenerator.Emit(OpCodes.Ldarg_0);
				iLGenerator.Emit(OpCodes.Ldarg_1);
				iLGenerator.Emit(OpCodes.Ldarg_2);
				iLGenerator.Emit(OpCodes.Initblk);
				iLGenerator.Emit(OpCodes.Ret);
				delegate12_0 = (Delegate12)dynamicMethod.CreateDelegate(typeof(Delegate12));
			}
			delegate12_0(intptr_0, byte_0, int_3);
		}

		private static void smethod_11(IntPtr intptr_0, IntPtr intptr_1, uint uint_0)
		{
			if (delegate13_0 == null)
			{
				DynamicMethod dynamicMethod = new DynamicMethod(string.Empty, typeof(void), new Type[3]
				{
					typeof(IntPtr),
					typeof(IntPtr),
					typeof(uint)
				}, typeof(Class11), skipVisibility: true);
				ILGenerator iLGenerator = dynamicMethod.GetILGenerator();
				iLGenerator.Emit(OpCodes.Ldarg_0);
				iLGenerator.Emit(OpCodes.Ldarg_1);
				iLGenerator.Emit(OpCodes.Ldarg_2);
				iLGenerator.Emit(OpCodes.Cpblk);
				iLGenerator.Emit(OpCodes.Ret);
				delegate13_0 = (Delegate13)dynamicMethod.CreateDelegate(typeof(Delegate13));
			}
			delegate13_0(intptr_0, intptr_1, uint_0);
		}

		static Class20()
		{
			dictionary_1 = new Dictionary<object, Class22>();
			dictionary_2 = new Dictionary<MethodBase, Delegate10>();
			dictionary_3 = new Dictionary<MethodBase, Delegate10>();
			dictionary_4 = new Dictionary<Class19, Delegate10>();
			dictionary_5 = new Dictionary<Class19, Delegate10>();
			dictionary_6 = new Dictionary<Class19, Delegate10>();
		}
	}

	internal enum Enum3 : byte
	{

	}

	internal enum Enum4 : byte
	{

	}

	internal abstract class Class22
	{
		internal Enum4 enum4_0;

		public Class22()
		{
		}

		internal bool method_0()
		{
			return enum4_0 == (Enum4)0;
		}

		internal bool method_1()
		{
			return enum4_0 == (Enum4)1;
		}

		internal bool method_2()
		{
			if (enum4_0 != (Enum4)3)
			{
				return enum4_0 == (Enum4)4;
			}
			return true;
		}

		internal bool method_3()
		{
			return enum4_0 == (Enum4)2;
		}

		internal bool method_4()
		{
			return enum4_0 == (Enum4)5;
		}

		internal bool method_5()
		{
			return enum4_0 == (Enum4)6;
		}

		internal virtual bool vmethod_0()
		{
			return false;
		}

		internal virtual bool vmethod_1()
		{
			return false;
		}

		internal abstract void vmethod_2(Class22 class22_0);

		internal virtual bool vmethod_3()
		{
			return false;
		}

		internal Class22(Enum4 enum4_1)
		{
			enum4_0 = enum4_1;
		}

		internal abstract object vmethod_4(Type type_0);

		internal abstract bool vmethod_5(Class22 class22_0);

		internal abstract bool vmethod_6(Class22 class22_0);

		internal abstract bool vmethod_7();

		internal abstract Class22 vmethod_8();

		internal virtual bool vmethod_9()
		{
			return false;
		}

		internal abstract void vmethod_10(Class22 class22_0);

		internal static Enum2 smethod_0(Type type_0)
		{
			Type type = type_0;
			if (type != null)
			{
				if (type.IsByRef)
				{
					type = type.GetElementType();
				}
				if (!(type == typeof(string)))
				{
					if (!(type == typeof(byte)))
					{
						if (type == typeof(sbyte))
						{
							return (Enum2)1;
						}
						if (!(type == typeof(short)))
						{
							if (!(type == typeof(ushort)))
							{
								if (!(type == typeof(int)))
								{
									if (!(type == typeof(uint)))
									{
										if (!(type == typeof(long)))
										{
											if (!(type == typeof(ulong)))
											{
												if (!(type == typeof(float)))
												{
													if (type == typeof(double))
													{
														return (Enum2)10;
													}
													if (type == typeof(bool))
													{
														return (Enum2)11;
													}
													if (!(type == typeof(IntPtr)))
													{
														if (!(type == typeof(UIntPtr)))
														{
															if (!(type == typeof(char)))
															{
																if (!(type == typeof(object)))
																{
																	if (type.IsEnum)
																	{
																		return (Enum2)16;
																	}
																	return (Enum2)17;
																}
																return (Enum2)0;
															}
															return (Enum2)15;
														}
														return (Enum2)13;
													}
													return (Enum2)12;
												}
												return (Enum2)9;
											}
											return (Enum2)8;
										}
										return (Enum2)7;
									}
									return (Enum2)6;
								}
								return (Enum2)5;
							}
							return (Enum2)4;
						}
						return (Enum2)3;
					}
					return (Enum2)2;
				}
				return (Enum2)14;
			}
			return (Enum2)18;
		}

		internal static Class22 smethod_1(Type type_0, object object_0)
		{
			Enum2 @enum = smethod_0(type_0);
			Enum2 enum2 = (Enum2)18;
			if (object_0 != null)
			{
				enum2 = smethod_0(object_0.GetType());
			}
			Class22 @class = null;
			switch (@enum)
			{
			case (Enum2)0:
				@class = ((enum2 != (Enum2)15) ? smethod_2(object_0) : new Class34(object_0));
				goto default;
			case (Enum2)1:
				@class = enum2 switch
				{
					(Enum2)2 => new Class24((sbyte)(byte)object_0, (Enum1)1), 
					(Enum2)1 => new Class24((sbyte)object_0, (Enum1)1), 
					(Enum2)15 => new Class24((sbyte)(char)object_0, (Enum1)1), 
					(Enum2)11 => (!(bool)object_0) ? new Class24(0, (Enum1)1) : new Class24(1, (Enum1)1), 
					_ => throw new InvalidCastException(), 
				};
				goto default;
			case (Enum2)2:
				@class = enum2 switch
				{
					(Enum2)2 => new Class24((byte)object_0, (Enum1)2), 
					(Enum2)1 => new Class24((byte)(sbyte)object_0, (Enum1)2), 
					(Enum2)15 => new Class24((byte)(char)object_0, (Enum1)2), 
					(Enum2)11 => (!(bool)object_0) ? new Class24(0, (Enum1)2) : new Class24(1, (Enum1)2), 
					_ => throw new InvalidCastException(), 
				};
				goto default;
			case (Enum2)3:
				@class = enum2 switch
				{
					(Enum2)15 => new Class24((short)(char)object_0, (Enum1)3), 
					(Enum2)11 => ((bool)object_0) ? new Class24(1, (Enum1)3) : new Class24(0, (Enum1)3), 
					(Enum2)3 => new Class24((short)object_0, (Enum1)3), 
					_ => throw new InvalidCastException(), 
				};
				goto default;
			case (Enum2)4:
				@class = enum2 switch
				{
					(Enum2)15 => new Class24((char)object_0, (Enum1)4), 
					(Enum2)11 => (!(bool)object_0) ? new Class24(0, (Enum1)4) : new Class24(1, (Enum1)4), 
					(Enum2)4 => new Class24((ushort)object_0, (Enum1)4), 
					_ => throw new InvalidCastException(), 
				};
				goto default;
			case (Enum2)5:
				@class = enum2 switch
				{
					(Enum2)15 => new Class24((char)object_0, (Enum1)5), 
					(Enum2)11 => (!(bool)object_0) ? new Class24(0, (Enum1)5) : new Class24(1, (Enum1)5), 
					(Enum2)5 => new Class24((int)object_0, (Enum1)5), 
					_ => throw new InvalidCastException(), 
				};
				goto default;
			case (Enum2)6:
				@class = enum2 switch
				{
					(Enum2)15 => new Class24((uint)(char)object_0, (Enum1)6), 
					(Enum2)11 => ((bool)object_0) ? new Class24(1u, (Enum1)6) : new Class24(0u, (Enum1)6), 
					(Enum2)6 => new Class24((uint)object_0, (Enum1)6), 
					_ => throw new InvalidCastException(), 
				};
				goto default;
			case (Enum2)7:
				@class = enum2 switch
				{
					(Enum2)15 => new Class25((char)object_0, (Enum1)7), 
					(Enum2)11 => ((bool)object_0) ? new Class25(1L, (Enum1)7) : new Class25(0L, (Enum1)7), 
					(Enum2)7 => new Class25((long)object_0, (Enum1)7), 
					_ => throw new InvalidCastException(), 
				};
				goto default;
			case (Enum2)8:
				@class = enum2 switch
				{
					(Enum2)15 => new Class25((ulong)(char)object_0, (Enum1)8), 
					(Enum2)11 => ((bool)object_0) ? new Class25(1uL, (Enum1)8) : new Class25(0uL, (Enum1)8), 
					(Enum2)8 => new Class25((ulong)object_0, (Enum1)8), 
					_ => throw new InvalidCastException(), 
				};
				goto default;
			case (Enum2)9:
				if (enum2 == (Enum2)9)
				{
					@class = new Class27((float)object_0);
					goto default;
				}
				throw new InvalidCastException();
			case (Enum2)10:
				if (enum2 == (Enum2)10)
				{
					@class = new Class27((double)object_0);
					goto default;
				}
				throw new InvalidCastException();
			case (Enum2)11:
				switch (enum2)
				{
				case (Enum2)1:
					@class = new Class24((sbyte)object_0 != 0);
					break;
				case (Enum2)2:
					@class = new Class24((byte)object_0 != 0);
					break;
				case (Enum2)3:
					@class = new Class24((short)object_0 != 0);
					break;
				case (Enum2)4:
					@class = new Class24((ushort)object_0 != 0);
					break;
				case (Enum2)5:
					@class = new Class24((int)object_0 != 0);
					break;
				case (Enum2)6:
					@class = new Class24((uint)object_0 != 0);
					break;
				case (Enum2)7:
					@class = new Class24((long)object_0 != 0);
					break;
				case (Enum2)8:
					@class = new Class24((ulong)object_0 != 0);
					break;
				case (Enum2)11:
					@class = new Class24((bool)object_0);
					break;
				case (Enum2)9:
				case (Enum2)10:
				case (Enum2)12:
				case (Enum2)13:
				case (Enum2)14:
				case (Enum2)15:
				case (Enum2)16:
					throw new InvalidCastException();
				default:
					@class = new Class24(object_0 != null);
					break;
				case (Enum2)18:
					@class = new Class24(bool_0: false);
					break;
				}
				goto default;
			case (Enum2)12:
				if (enum2 == (Enum2)12)
				{
					@class = new Class26((IntPtr)object_0);
					goto default;
				}
				throw new InvalidCastException();
			case (Enum2)13:
				if (enum2 == (Enum2)13)
				{
					@class = new Class26((UIntPtr)object_0);
					goto default;
				}
				throw new InvalidCastException();
			case (Enum2)14:
				@class = new Class35(object_0 as string);
				goto default;
			case (Enum2)15:
				@class = enum2 switch
				{
					(Enum2)15 => new Class24((char)object_0, (Enum1)15), 
					(Enum2)1 => new Class24((sbyte)object_0, (Enum1)15), 
					(Enum2)2 => new Class24((byte)object_0, (Enum1)15), 
					(Enum2)3 => new Class24((short)object_0, (Enum1)15), 
					(Enum2)4 => new Class24((ushort)object_0, (Enum1)15), 
					(Enum2)5 => new Class24((int)object_0, (Enum1)15), 
					(Enum2)6 => new Class24((int)(uint)object_0, (Enum1)15), 
					_ => throw new InvalidCastException(), 
				};
				goto default;
			case (Enum2)16:
			case (Enum2)17:
				@class = smethod_2(object_0);
				goto default;
			default:
				if (type_0.IsByRef)
				{
					@class = new Class33(@class, type_0.GetElementType());
				}
				return @class;
			case (Enum2)18:
				throw new InvalidCastException();
			}
		}

		private static Class22 smethod_2(object object_0)
		{
			if (object_0 != null && object_0.GetType().IsEnum)
			{
				Type underlyingType = Enum.GetUnderlyingType(object_0.GetType());
				object object_1 = Convert.ChangeType(object_0, underlyingType);
				Class22 @class = smethod_3(smethod_1(underlyingType, object_1));
				if (@class != null)
				{
					return @class as Class23;
				}
			}
			return new Class34(object_0);
		}

		private static Class23 smethod_3(Class22 class22_0)
		{
			Class23 @class = class22_0 as Class23;
			if (@class == null && class22_0.vmethod_0())
			{
				@class = class22_0.vmethod_8() as Class23;
			}
			return @class;
		}
	}

	private class Class34 : Class22
	{
		public Class22 class22_0;

		public Type type_0;

		public Class34()
			: this(null)
		{
		}

		internal override void vmethod_10(Class22 class22_1)
		{
			if (class22_1 is Class34)
			{
				class22_0 = ((Class34)class22_1).class22_0;
				type_0 = ((Class34)class22_1).type_0;
			}
			else
			{
				class22_0 = class22_1.vmethod_8();
			}
		}

		internal override void vmethod_2(Class22 class22_1)
		{
			vmethod_10(class22_1);
		}

		public Class34(object object_0)
			: base((Enum4)0)
		{
			class22_0 = (Class22)object_0;
			type_0 = null;
		}

		public Class34(object object_0, Type type_1)
			: base((Enum4)0)
		{
			class22_0 = (Class22)object_0;
			type_0 = type_1;
		}

		public override string ToString()
		{
			if (class22_0 == null)
			{
				return ((Enum5)5/*cast due to .constrained prefix*/).ToString();
			}
			return class22_0.ToString();
		}

		internal override object vmethod_4(Type type_1)
		{
			if (class22_0 != null)
			{
				if (type_1 != null && type_1.IsByRef)
				{
					type_1 = type_1.GetElementType();
				}
				if (class22_0 != null)
				{
					if (!(type_0 != null))
					{
						object obj = class22_0.vmethod_4(type_1);
						if (obj != null && type_1 != null && obj.GetType() != type_1)
						{
							if (type_1 == typeof(RuntimeFieldHandle) && obj is FieldInfo)
							{
								obj = ((FieldInfo)obj).FieldHandle;
							}
							else if (type_1 == typeof(RuntimeTypeHandle) && obj is Type)
							{
								obj = ((Type)obj).TypeHandle;
							}
							else if (type_1 == typeof(RuntimeMethodHandle) && obj is MethodBase)
							{
								obj = ((MethodBase)obj).MethodHandle;
							}
						}
						return obj;
					}
					return class22_0.vmethod_4(type_0);
				}
				object obj2 = class22_0;
				if (obj2 != null && type_1 != null && obj2.GetType() != type_1)
				{
					if (type_1 == typeof(RuntimeFieldHandle) && obj2 is FieldInfo)
					{
						obj2 = ((FieldInfo)obj2).FieldHandle;
					}
					else if (type_1 == typeof(RuntimeTypeHandle) && obj2 is Type)
					{
						obj2 = ((Type)obj2).TypeHandle;
					}
					else if (type_1 == typeof(RuntimeMethodHandle) && obj2 is MethodBase)
					{
						obj2 = ((MethodBase)obj2).MethodHandle;
					}
				}
				return obj2;
			}
			return null;
		}

		internal override bool vmethod_5(Class22 class22_1)
		{
			if (class22_1.vmethod_0())
			{
				return ((Class28)class22_1).vmethod_5(this);
			}
			object obj = vmethod_4(null);
			object obj2 = class22_1.vmethod_4(null);
			return obj == obj2;
		}

		internal override bool vmethod_6(Class22 class22_1)
		{
			if (!class22_1.vmethod_0())
			{
				object obj = vmethod_4(null);
				object obj2 = class22_1.vmethod_4(null);
				return obj != obj2;
			}
			return ((Class28)class22_1).vmethod_6(this);
		}

		internal override Class22 vmethod_8()
		{
			Class22 @class = class22_0;
			if (@class != null)
			{
				return @class.vmethod_8();
			}
			return this;
		}

		internal override bool vmethod_7()
		{
			if (class22_0 != null)
			{
				Class22 @class = class22_0;
				if (@class != null)
				{
					if (@class.vmethod_4(null) == null)
					{
						return false;
					}
					return true;
				}
				return true;
			}
			return false;
		}
	}

	private class Class35 : Class22
	{
		public string string_0;

		public Class35(string string_1)
			: base((Enum4)6)
		{
			string_0 = string_1;
		}

		internal override void vmethod_10(Class22 class22_0)
		{
			string_0 = ((Class35)class22_0).string_0;
		}

		internal override void vmethod_2(Class22 class22_0)
		{
			vmethod_10(class22_0);
		}

		public override string ToString()
		{
			if (string_0 == null)
			{
				return ((Enum5)5/*cast due to .constrained prefix*/).ToString();
			}
			return "*" + string_0 + "*";
		}

		internal override bool vmethod_7()
		{
			return string_0 != null;
		}

		internal override object vmethod_4(Type type_0)
		{
			return string_0;
		}

		internal override bool vmethod_5(Class22 class22_0)
		{
			if (class22_0.vmethod_0())
			{
				return ((Class28)class22_0).vmethod_5(this);
			}
			string text = string_0;
			object obj = class22_0.vmethod_4(null);
			return text == obj;
		}

		internal override bool vmethod_6(Class22 class22_0)
		{
			if (!class22_0.vmethod_0())
			{
				string text = string_0;
				object obj = class22_0.vmethod_4(null);
				return text != obj;
			}
			return ((Class28)class22_0).vmethod_6(this);
		}

		internal override Class22 vmethod_8()
		{
			return this;
		}
	}

	internal class Class36
	{
		private List<Class22> list_0 = new List<Class22>();

		[SpecialName]
		public int method_0()
		{
			return list_0.Count;
		}

		public void method_1()
		{
			list_0.Clear();
		}

		public void method_2(Class22 class22_0)
		{
			list_0.Add(class22_0);
		}

		public Class22 method_3()
		{
			return list_0[list_0.Count - 1];
		}

		public Class22 method_4()
		{
			Class22 result = method_3();
			if (list_0.Count != 0)
			{
				list_0.RemoveAt(list_0.Count - 1);
			}
			return result;
		}
	}

	internal enum Enum5
	{

	}

	[Serializable]
	[CompilerGenerated]
	private sealed class Class37<T>
	{
		public static readonly Class37<T> _003C_003E9;

		public static Comparison<Class15> _003C_003E9__45_0;

		internal static object object_0;

		static Class37()
		{
			_003C_003E9 = new Class37<T>();
		}

		internal int method_0(Class15 x, Class15 y)
		{
			return x.class16_0.int_0.CompareTo(y.class16_0.int_0);
		}

		internal static bool smethod_0()
		{
			return object_0 == null;
		}

		internal static object smethod_1()
		{
			return object_0;
		}
	}

	internal static Class17[] class17_0;

	internal static int[] int_0;

	internal static List<string> list_0;

	private static BinaryReader binaryReader_0;

	private static byte[] byte_0;

	private static bool bool_0;

	private static object object_0;

	private static int int_1;

	internal static object[] smethod_0()
	{
		return new object[1];
	}

	internal static object[] smethod_1<T>(int int_2, object object_1, object object_2, ref T gparam_0)
	{
		lock (object_0)
		{
			if (!bool_0)
			{
				bool_0 = true;
				smethod_4();
			}
		}
		Class17 @class = null;
		if (class17_0[int_2] != null)
		{
			@class = class17_0[int_2];
		}
		else
		{
			binaryReader_0.BaseStream.Position = int_0[int_2];
			@class = new Class17();
			Module module = typeof(Class11).Module;
			int metadataToken = smethod_6(binaryReader_0);
			int num = smethod_6(binaryReader_0);
			int num2 = smethod_6(binaryReader_0);
			int num3 = smethod_6(binaryReader_0);
			@class.object_0 = module.ResolveMethod(metadataToken);
			ParameterInfo[] parameters = ((MethodBase)@class.object_0).GetParameters();
			@class.class13_0 = new Class13[parameters.Length];
			for (int i = 0; i < parameters.Length; i++)
			{
				Type type = parameters[i].ParameterType;
				Class13 class2 = new Class13();
				class2.bool_0 = type.IsByRef;
				class2.int_0 = i;
				@class.class13_0[i] = class2;
				if (type.IsByRef)
				{
					type = type.GetElementType();
				}
				Enum1 @enum = (Enum1)0;
				@enum = ((!(type == typeof(string))) ? ((!(type == typeof(byte))) ? ((type == typeof(sbyte)) ? ((Enum1)1) : ((!(type == typeof(short))) ? ((!(type == typeof(ushort))) ? ((!(type == typeof(int))) ? ((!(type == typeof(uint))) ? ((!(type == typeof(long))) ? ((!(type == typeof(ulong))) ? ((!(type == typeof(float))) ? ((!(type == typeof(double))) ? ((!(type == typeof(bool))) ? ((!(type == typeof(IntPtr))) ? ((!(type == typeof(UIntPtr))) ? ((type == typeof(char)) ? ((Enum1)15) : ((Enum1)0)) : ((Enum1)13)) : ((Enum1)12)) : ((Enum1)11)) : ((Enum1)10)) : ((Enum1)9)) : ((Enum1)8)) : ((Enum1)7)) : ((Enum1)6)) : ((Enum1)5)) : ((Enum1)4)) : ((Enum1)3))) : ((Enum1)2)) : ((Enum1)14));
				class2.enum1_0 = @enum;
			}
			@class.list_1 = new List<Class14>(num);
			for (int j = 0; j < num; j++)
			{
				int num4 = smethod_6(binaryReader_0);
				Class14 class3 = new Class14();
				class3.type_0 = null;
				if (num4 >= 0 && num4 < 50)
				{
					class3.enum1_0 = (Enum1)(num4 & 0x1F);
					class3.bool_0 = (num4 & 0x20) > 0;
				}
				class3.int_0 = j;
				@class.list_1.Add(class3);
			}
			@class.list_2 = new List<Class15>(num2);
			for (int k = 0; k < num2; k++)
			{
				int num5 = smethod_6(binaryReader_0);
				int num6 = smethod_6(binaryReader_0);
				Class15 class4 = new Class15();
				class4.int_0 = num5;
				class4.int_1 = num6;
				Class16 class5 = (class4.class16_0 = new Class16());
				num5 = smethod_6(binaryReader_0);
				num6 = smethod_6(binaryReader_0);
				int num7 = smethod_6(binaryReader_0);
				class5.int_0 = num5;
				class5.int_1 = num6;
				class5.int_3 = num7;
				switch (num7)
				{
				case 0:
					class5.type_0 = module.ResolveType(smethod_6(binaryReader_0));
					break;
				case 1:
					class5.int_2 = smethod_6(binaryReader_0);
					break;
				default:
					smethod_6(binaryReader_0);
					break;
				}
				@class.list_2.Add(class4);
			}
			@class.list_2.Sort((Class15 x, Class15 y) => x.class16_0.int_0.CompareTo(y.class16_0.int_0));
			@class.list_0 = new List<Class12>(num3);
			for (int num8 = 0; num8 < num3; num8++)
			{
				Class12 class6 = new Class12();
				byte b = (byte)(class6.enum3_0 = (Enum3)binaryReader_0.ReadByte());
				if (b < 176)
				{
					int num9 = byte_0[b];
					if (num9 == 0)
					{
						class6.object_0 = null;
					}
					else
					{
						object obj = null;
						switch (num9)
						{
						case 1:
							obj = smethod_6(binaryReader_0);
							break;
						case 2:
							obj = binaryReader_0.ReadInt64();
							break;
						case 3:
							obj = binaryReader_0.ReadSingle();
							break;
						case 4:
							obj = binaryReader_0.ReadDouble();
							break;
						case 5:
						{
							int num10 = smethod_6(binaryReader_0);
							int[] array = new int[num10];
							for (int num11 = 0; num11 < num10; num11++)
							{
								array[num11] = smethod_6(binaryReader_0);
							}
							obj = array;
							break;
						}
						default:
							throw new Exception();
						}
						class6.object_0 = obj;
					}
					@class.list_0.Add(class6);
					continue;
				}
				throw new Exception();
			}
			class17_0[int_2] = @class;
		}
		Class20 class7 = new Class20();
		class7.class17_0 = @class;
		ParameterInfo[] parameters2 = ((MethodBase)@class.object_0).GetParameters();
		bool flag = false;
		int num12 = 0;
		if (@class.object_0 is MethodInfo && ((MethodInfo)@class.object_0).ReturnType != typeof(void))
		{
			flag = true;
		}
		if (((MethodBase)@class.object_0).IsStatic)
		{
			class7.class22_0 = new Class22[parameters2.Length];
			for (int num13 = 0; num13 < parameters2.Length; num13++)
			{
				Type parameterType = parameters2[num13].ParameterType;
				class7.class22_0[num13] = Class22.smethod_1(parameterType, ((object[])object_1)[num13]);
				if (parameterType.IsByRef)
				{
					num12++;
				}
			}
		}
		else
		{
			class7.class22_0 = new Class22[parameters2.Length + 1];
			if (((MemberInfo)@class.object_0).DeclaringType.IsValueType)
			{
				class7.class22_0[0] = new Class33(new Class34(object_2), ((MemberInfo)@class.object_0).DeclaringType);
			}
			else
			{
				class7.class22_0[0] = new Class34(object_2);
			}
			for (int num14 = 0; num14 < parameters2.Length; num14++)
			{
				Type parameterType2 = parameters2[num14].ParameterType;
				if (parameterType2.IsByRef)
				{
					class7.class22_0[num14 + 1] = Class22.smethod_1(parameterType2, ((object[])object_1)[num14]);
					num12++;
				}
				else
				{
					class7.class22_0[num14 + 1] = Class22.smethod_1(parameterType2, ((object[])object_1)[num14]);
				}
			}
		}
		class7.class22_1 = new Class22[@class.list_1.Count];
		for (int num15 = 0; num15 < @class.list_1.Count; num15++)
		{
			Class14 class8 = @class.list_1[num15];
			switch (class8.enum1_0)
			{
			case (Enum1)0:
				class7.class22_1[num15] = null;
				break;
			case (Enum1)7:
			case (Enum1)8:
				class7.class22_1[num15] = new Class25(0L, class8.enum1_0);
				break;
			case (Enum1)9:
			case (Enum1)10:
				class7.class22_1[num15] = new Class27(0.0, class8.enum1_0);
				break;
			case (Enum1)12:
				class7.class22_1[num15] = new Class26(IntPtr.Zero);
				break;
			case (Enum1)13:
				class7.class22_1[num15] = new Class26(UIntPtr.Zero);
				break;
			case (Enum1)14:
				class7.class22_1[num15] = null;
				break;
			case (Enum1)1:
			case (Enum1)2:
			case (Enum1)3:
			case (Enum1)4:
			case (Enum1)5:
			case (Enum1)6:
			case (Enum1)11:
			case (Enum1)15:
				class7.class22_1[num15] = new Class24(0, class8.enum1_0);
				break;
			case (Enum1)16:
				class7.class22_1[num15] = new Class34(null);
				break;
			}
		}
		try
		{
			class7.method_0();
		}
		finally
		{
			class7.method_1();
		}
		int num16 = 0;
		if (flag)
		{
			num16 = 1;
		}
		num16 += num12;
		object[] array2 = new object[num16];
		if (flag)
		{
			array2[0] = null;
		}
		if (@class.object_0 is MethodInfo)
		{
			MethodInfo methodInfo = (MethodInfo)@class.object_0;
			if (methodInfo.ReturnType != typeof(void) && class7.class22_2 != null)
			{
				array2[0] = class7.class22_2.vmethod_4(methodInfo.ReturnType);
			}
		}
		if (num12 > 0)
		{
			int num17 = 0;
			if (flag)
			{
				num17++;
			}
			for (int num18 = 0; num18 < parameters2.Length; num18++)
			{
				Type parameterType3 = parameters2[num18].ParameterType;
				if (!parameterType3.IsByRef)
				{
					continue;
				}
				parameterType3 = parameterType3.GetElementType();
				if (class7.class22_0[num18] != null)
				{
					if (((MethodBase)@class.object_0).IsStatic)
					{
						array2[num17] = class7.class22_0[num18].vmethod_4(parameterType3);
					}
					else
					{
						array2[num17] = class7.class22_0[num18 + 1].vmethod_4(parameterType3);
					}
				}
				else
				{
					array2[num17] = null;
				}
				num17++;
			}
		}
		if (!((MethodBase)@class.object_0).IsStatic && ((MemberInfo)@class.object_0).DeclaringType.IsValueType)
		{
			gparam_0 = (T)class7.class22_0[0].vmethod_4(((MemberInfo)@class.object_0).DeclaringType);
		}
		return array2;
	}

	internal static object[] smethod_2(int int_2, object object_1, object object_2)
	{
		return smethod_1(int_2, object_1, object_2, ref int_1);
	}

	internal static object[] smethod_3<T>(int int_2, object object_1, ref T gparam_0)
	{
		return smethod_1(int_2, object_1, gparam_0, ref gparam_0);
	}

	internal static void smethod_4()
	{
		if (int_0 == null)
		{
			BinaryReader binaryReader = new BinaryReader(typeof(Class11).Assembly.GetManifestResourceStream("p\u008cd\u009f\u009au\u008f\u008et\u008d\u0088jy\u0088\u0086re4.b2v\u009d5d\u0090\u0099b7\u008d\u0094\u008c\u009f8\u0091j\u009c"));
			binaryReader.BaseStream.Position = 0L;
			byte[] byte_ = binaryReader.ReadBytes((int)binaryReader.BaseStream.Length);
			binaryReader.Close();
			smethod_5(byte_);
		}
	}

	internal static void smethod_5(byte[] byte_1)
	{
		binaryReader_0 = new BinaryReader(new MemoryStream(byte_1));
		byte_0 = new byte[255];
		int num = smethod_6(binaryReader_0);
		for (int i = 0; i < num; i++)
		{
			int num2 = binaryReader_0.ReadByte();
			byte_0[num2] = binaryReader_0.ReadByte();
		}
		num = smethod_6(binaryReader_0);
		list_0 = new List<string>(num);
		for (int j = 0; j < num; j++)
		{
			list_0.Add(Encoding.Unicode.GetString(binaryReader_0.ReadBytes(smethod_6(binaryReader_0))));
		}
		num = smethod_6(binaryReader_0);
		class17_0 = new Class17[num];
		int_0 = new int[num];
		for (int k = 0; k < num; k++)
		{
			class17_0[k] = null;
			int_0[k] = smethod_6(binaryReader_0);
		}
		int num3 = (int)binaryReader_0.BaseStream.Position;
		for (int l = 0; l < num; l++)
		{
			int num4 = int_0[l];
			int_0[l] = num3;
			num3 += num4;
		}
	}

	internal static int smethod_6(BinaryReader binaryReader_1)
	{
		bool flag = false;
		uint num = 0u;
		uint num2 = binaryReader_1.ReadByte();
		num = 0 | (num2 & 0x3F);
		if ((num2 & 0x40) != 0)
		{
			flag = true;
		}
		if (num2 < 128)
		{
			if (!flag)
			{
				return (int)num;
			}
			return (int)(~num);
		}
		int num3 = 0;
		while (true)
		{
			uint num4 = binaryReader_1.ReadByte();
			num |= (num4 & 0x7F) << 7 * num3 + 6;
			if (num4 < 128)
			{
				break;
			}
			num3++;
		}
		if (!flag)
		{
			return (int)num;
		}
		return (int)(~num);
	}

	static Class11()
	{
		class17_0 = null;
		int_0 = null;
		bool_0 = false;
		object_0 = 1;
	}
}
