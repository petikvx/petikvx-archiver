using System.Windows.Forms;

namespace Messager;

internal class Messager
{
	private static void Main()
	{
		//IL_0021: Unknown result type (might be due to invalid IL or missing references)
		MessageBoxManager.OK = "run away";
		MessageBoxManager.Register();
		while (true)
		{
			MessageBox.Show("run away", "run away", (MessageBoxButtons)0, (MessageBoxIcon)16);
		}
	}
}
