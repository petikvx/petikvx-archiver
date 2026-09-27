using System;
using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Configuration;
using System.Runtime.CompilerServices;
using System.Threading;
using Microsoft.VisualBasic.ApplicationServices;
using Microsoft.VisualBasic.CompilerServices;
using ns0;

namespace NET.My;

[EditorBrowsable(EditorBrowsableState.Advanced)]
[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "17.2.0.0")]
[CompilerGenerated]
internal sealed class MySettings : ApplicationSettingsBase
{
	[CompilerGenerated]
	private static class _003C_003EO
	{
		public static ShutdownEventHandler _003C0_003E__AutoSaveSettings;
	}

	private static MySettings defaultInstance;

	private static bool addedHandler;

	private static object addedHandlerLockObject;

	public static MySettings Default
	{
		get
		{
			//IL_0039: Unknown result type (might be due to invalid IL or missing references)
			//IL_003e: Unknown result type (might be due to invalid IL or missing references)
			//IL_0044: Expected O, but got Unknown
			if (!addedHandler)
			{
				object obj = addedHandlerLockObject;
				ObjectFlowControl.CheckForSyncLockOnValueType(obj);
				bool lockTaken = false;
				try
				{
					Monitor.Enter(obj, ref lockTaken);
					if (!addedHandler)
					{
						Form0 form0_ = Class1.Form0_0;
						object obj2 = _003C_003EO._003C0_003E__AutoSaveSettings;
						if (obj2 == null)
						{
							ShutdownEventHandler val = AutoSaveSettings;
							_003C_003EO._003C0_003E__AutoSaveSettings = val;
							obj2 = (object)val;
						}
						((WindowsFormsApplicationBase)form0_).Shutdown += (ShutdownEventHandler)obj2;
						addedHandler = true;
					}
				}
				finally
				{
					if (lockTaken)
					{
						Monitor.Exit(obj);
					}
				}
			}
			return defaultInstance;
		}
	}

	static MySettings()
	{
		defaultInstance = (MySettings)(object)SettingsBase.Synchronized((SettingsBase)(object)new MySettings());
		addedHandlerLockObject = RuntimeHelpers.GetObjectValue(new object());
	}

	[EditorBrowsable(EditorBrowsableState.Advanced)]
	private static void AutoSaveSettings(object sender, EventArgs e)
	{
		if (((WindowsFormsApplicationBase)Class1.Form0_0).SaveMySettingsOnExit)
		{
			((SettingsBase)MySettingsProperty.Settings).Save();
		}
	}
}
