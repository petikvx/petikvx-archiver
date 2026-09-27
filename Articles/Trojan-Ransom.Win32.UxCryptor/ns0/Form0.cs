using System;
using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Windows.Forms;
using Microsoft.VisualBasic.ApplicationServices;

namespace ns0;

[GeneratedCode("MyTemplate", "11.0.0.0")]
[EditorBrowsable(EditorBrowsableState.Never)]
internal class Form0 : WindowsFormsApplicationBase
{
	[EditorBrowsable(EditorBrowsableState.Advanced)]
	[STAThread]
	internal static void Main(string[] args)
	{
		Application.SetCompatibleTextRenderingDefault(WindowsFormsApplicationBase.UseCompatibleTextRendering);
		((WindowsFormsApplicationBase)Class1.Form0_0).Run(args);
	}

	public Form0()
		: base((AuthenticationMode)0)
	{
		((WindowsFormsApplicationBase)this).IsSingleInstance = true;
		((WindowsFormsApplicationBase)this).EnableVisualStyles = false;
		((WindowsFormsApplicationBase)this).SaveMySettingsOnExit = false;
		((WindowsFormsApplicationBase)this).ShutdownStyle = (ShutdownMode)0;
	}

	protected override void OnCreateMainForm()
	{
		((WindowsFormsApplicationBase)this).MainForm = (Form)(object)Class1.MyForms_0.loader;
	}
}
