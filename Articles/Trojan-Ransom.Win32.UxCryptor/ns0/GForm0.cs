using System;
using System.ComponentModel;
using System.Drawing;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using Microsoft.VisualBasic.CompilerServices;

namespace ns0;

[DesignerGenerated]
public class GForm0 : Form
{
	private IDisposable idisposable_0;

	[CompilerGenerated]
	[AccessedThroughProperty("g1")]
	private Label label_0;

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
			label_0 = value;
		}
	}

	public GForm0()
	{
		//IL_000e: Unknown result type (might be due to invalid IL or missing references)
		//IL_0018: Expected O, but got Unknown
		((Form)this).FormClosing += new FormClosingEventHandler(GForm0_FormClosing);
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
		//IL_0011: Unknown result type (might be due to invalid IL or missing references)
		//IL_001b: Expected O, but got Unknown
		//IL_0044: Unknown result type (might be due to invalid IL or missing references)
		//IL_004e: Expected O, but got Unknown
		//IL_0123: Unknown result type (might be due to invalid IL or missing references)
		//IL_012d: Expected O, but got Unknown
		ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(GForm0));
		g1 = new Label();
		((Control)this).SuspendLayout();
		((Control)g1).Dock = (DockStyle)5;
		((Control)g1).Font = new Font("Lucida Console", 48f, (FontStyle)0, (GraphicsUnit)3, (byte)204);
		((Control)g1).ForeColor = Color.Red;
		((Control)g1).Location = new Point(0, 0);
		((Control)g1).Name = "g1";
		((Control)g1).Size = new Size(874, 408);
		((Control)g1).TabIndex = 1;
		((Control)g1).Text = ":3";
		g1.TextAlign = (ContentAlignment)32;
		((ContainerControl)this).AutoScaleDimensions = new SizeF(6f, 13f);
		((ContainerControl)this).AutoScaleMode = (AutoScaleMode)1;
		((Control)this).BackColor = Color.Black;
		((Form)this).ClientSize = new Size(874, 408);
		((Control)this).Controls.Add((Control)(object)g1);
		((Form)this).FormBorderStyle = (FormBorderStyle)0;
		((Form)this).Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
		((Form)this).MaximizeBox = false;
		((Form)this).MinimizeBox = false;
		((Control)this).Name = "empty";
		((Form)this).ShowIcon = false;
		((Form)this).ShowInTaskbar = false;
		((Form)this).StartPosition = (FormStartPosition)1;
		((Form)this).TopMost = true;
		((Form)this).WindowState = (FormWindowState)2;
		((Control)this).ResumeLayout(false);
	}

	private void GForm0_FormClosing(object sender, FormClosingEventArgs e)
	{
		((CancelEventArgs)(object)e).Cancel = true;
	}
}
