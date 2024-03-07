using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
	public partial class frmMain : Form
	{
		public frmMain()
		{
			InitializeComponent();
			txtYourName_Leave(null, null);

		}

		private void textBox1_TextChanged(object sender, EventArgs e)
		{
			
		}

		private void btnClear_Click(object sender, EventArgs e)
		{
			txtYourName.Text = "";
			txtYear.Text = "";
			txtYourName.Focus();
		}

		private void btnShow_Click(object sender, EventArgs e)
		{
			int year;
			bool isYear = int.TryParse(txtYear.Text, out year);
			if (txtYourName.Text == "")
			{
				errorProvider1.SetError(txtYourName, "PLease enter your name");
				txtYourName.Focus();
			}
			else if (txtYear.Text == "")
			{
				errorProvider1.SetError(txtYear, "Please enter your year of birth");
				txtYear.Focus();
			}
			else if (isYear == false)
			{
				errorProvider1.SetError(txtYear, "PLease enter the number");
				txtYear.Focus();
			}
			else
			{
				int age = DateTime.Now.Year - year;
				MessageBox.Show("Hello " + txtYourName.Text + ", you are " + txtYear.Text + " years old\n" + "Current year: " + 2024 + "\nYour birthyear: " + age);
			}
		}

		private void textBox1_TextChanged_1(object sender, EventArgs e)
		{

		}

		private void txtYourName_Leave(object sender, EventArgs e)
		{
			this.txtbox1_yourname.Enabled = true;
		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}

		private void frmMain_FormClosing(object sender, FormClosingEventArgs e)
		{

		}

		private void txtYourName_Leave_1(object sender, EventArgs e)
		{

		}

		private void txtYear_TextChanged(object sender, EventArgs e)
		{

		}

		private void txtYourName_TextChanged(object sender, EventArgs e)
		{

		}

		private void btnExit_Click(object sender, EventArgs e)
		{
			//DialogResult result = MessageBox.Show("Bạn có muốn thoát chương trình không?", "Xác nhận", MessageBoxButtons.YesNo);
			DialogResult result = MessageBox.Show("Do you want to exit the program?", "Confirm", MessageBoxButtons.YesNo);
			if (result == DialogResult.Yes)
			{
				Application.Exit();
			}
		}
	}
}
