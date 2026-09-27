using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using Microsoft.VisualBasic;
using Microsoft.VisualBasic.ApplicationServices;
using Microsoft.VisualBasic.CompilerServices;

namespace ns0;

[StandardModule]
[HideModuleName]
[GeneratedCode("MyTemplate", "11.0.0.0")]
internal sealed class Class1
{
	[EditorBrowsable(EditorBrowsableState.Never)]
	[MyGroupCollection("System.Windows.Forms.Form", "Create__Instance__", "Dispose__Instance__", "My.MyProject.Forms")]
	internal sealed class MyForms
	{
		[ThreadStatic]
		private static Hashtable hashtable_0;

		[EditorBrowsable(EditorBrowsableState.Never)]
		public GForm2 gform2_0;

		[EditorBrowsable(EditorBrowsableState.Never)]
		public GForm0 gform0_0;

		[EditorBrowsable(EditorBrowsableState.Never)]
		public GForm1 gform1_0;

		public GForm2 _o_program
		{
			get
			{
				gform2_0 = smethod_0(gform2_0);
				return gform2_0;
			}
			set
			{
				if (value != gform2_0)
				{
					if (value != null)
					{
						throw new ArgumentException("Property can only be set to Nothing");
					}
					method_0(ref gform2_0);
				}
			}
		}

		public GForm0 empty
		{
			get
			{
				gform0_0 = smethod_0(gform0_0);
				return gform0_0;
			}
			set
			{
				if (value != gform0_0)
				{
					if (value != null)
					{
						throw new ArgumentException("Property can only be set to Nothing");
					}
					method_0(ref gform0_0);
				}
			}
		}

		public GForm1 loader
		{
			get
			{
				gform1_0 = smethod_0(gform1_0);
				return gform1_0;
			}
			set
			{
				if (value != gform1_0)
				{
					if (value != null)
					{
						throw new ArgumentException("Property can only be set to Nothing");
					}
					method_0(ref gform1_0);
				}
			}
		}

		private static T smethod_0<T>(T gparam_0) where T : Form, new()
		{
			if (gparam_0 == null || ((Control)(object)gparam_0).IsDisposed)
			{
				if (hashtable_0 != null)
				{
					if (hashtable_0.ContainsKey(typeof(T)))
					{
						throw new InvalidOperationException(Utils.GetResourceString("WinForms_RecursiveFormCreate", new string[0]));
					}
				}
				else
				{
					hashtable_0 = new Hashtable();
				}
				hashtable_0.Add(typeof(T), null);
				TargetInvocationException ex2 = null;
				try
				{
					return new T();
				}
				catch (TargetInvocationException ex3) when (((Func<bool>)delegate
				{
					// Could not convert BlockContainer to single expression
					TargetInvocationException ex4 = ex3;
					return ((Func<bool>)delegate
					{
						TargetInvocationException ex5 = ex4;
						return ((Func<bool>)delegate
						{
							ex2 = ex5;
							return ((Func<bool>)delegate
							{
								ProjectData.SetProjectError((Exception)ex2);
								return ex2.InnerException != null;
							})();
						})();
					})();
				}).Invoke())
				{
					throw new InvalidOperationException(Utils.GetResourceString("WinForms_SeeInnerException", new string[1] { ex2.InnerException.Message }), ex2.InnerException);
				}
				finally
				{
					hashtable_0.Remove(typeof(T));
				}
			}
			return gparam_0;
		}

		private void method_0<T>(ref T gparam_0) where T : Form
		{
			((Component)gparam_0/*cast due to .constrained prefix*/).Dispose();
			gparam_0 = default(T);
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public MyForms()
		{
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public override bool Equals(object obj)
		{
			return base.Equals(RuntimeHelpers.GetObjectValue(obj));
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public override int GetHashCode()
		{
			return base.GetHashCode();
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		internal Type method_1()
		{
			return typeof(MyForms);
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public override string ToString()
		{
			return base.ToString();
		}
	}

	[EditorBrowsable(EditorBrowsableState.Never)]
	[MyGroupCollection("System.Web.Services.Protocols.SoapHttpClientProtocol", "Create__Instance__", "Dispose__Instance__", "")]
	internal sealed class MyWebServices
	{
		[EditorBrowsable(EditorBrowsableState.Never)]
		public override bool Equals(object obj)
		{
			return base.Equals(RuntimeHelpers.GetObjectValue(obj));
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public override int GetHashCode()
		{
			return base.GetHashCode();
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		internal Type method_0()
		{
			return typeof(MyWebServices);
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public override string ToString()
		{
			return base.ToString();
		}

		private static T smethod_0<T>(T gparam_0) where T : new()
		{
			if (gparam_0 == null)
			{
				return new T();
			}
			return gparam_0;
		}

		private void method_1<T>(ref T gparam_0)
		{
			gparam_0 = default(T);
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public MyWebServices()
		{
		}
	}

	[EditorBrowsable(EditorBrowsableState.Never)]
	[ComVisible(false)]
	internal sealed class ThreadSafeObjectProvider<T> where T : new()
	{
		[ThreadStatic]
		[CompilerGenerated]
		private static T gparam_0;

		internal static object object_0;

		[SpecialName]
		internal T method_0()
		{
			if (gparam_0 == null)
			{
				gparam_0 = new T();
			}
			return gparam_0;
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		public ThreadSafeObjectProvider()
		{
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

	private static readonly ThreadSafeObjectProvider<Class0> threadSafeObjectProvider_0;

	private static readonly ThreadSafeObjectProvider<Form0> threadSafeObjectProvider_1;

	private static readonly ThreadSafeObjectProvider<User> threadSafeObjectProvider_2;

	private static ThreadSafeObjectProvider<MyForms> threadSafeObjectProvider_3;

	private static readonly ThreadSafeObjectProvider<MyWebServices> threadSafeObjectProvider_4;

	[HelpKeyword("My.Computer")]
	internal static Class0 Class0_0 => threadSafeObjectProvider_0.method_0();

	[HelpKeyword("My.Application")]
	internal static Form0 Form0_0 => threadSafeObjectProvider_1.method_0();

	[HelpKeyword("My.User")]
	internal static User User_0 => threadSafeObjectProvider_2.method_0();

	[HelpKeyword("My.Forms")]
	internal static MyForms MyForms_0 => threadSafeObjectProvider_3.method_0();

	[HelpKeyword("My.WebServices")]
	internal static MyWebServices MyWebServices_0 => threadSafeObjectProvider_4.method_0();

	static Class1()
	{
		threadSafeObjectProvider_0 = new ThreadSafeObjectProvider<Class0>();
		threadSafeObjectProvider_1 = new ThreadSafeObjectProvider<Form0>();
		threadSafeObjectProvider_2 = new ThreadSafeObjectProvider<User>();
		threadSafeObjectProvider_3 = new ThreadSafeObjectProvider<MyForms>();
		threadSafeObjectProvider_4 = new ThreadSafeObjectProvider<MyWebServices>();
	}
}
