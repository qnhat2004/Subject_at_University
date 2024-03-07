namespace WindowsFormsApp2
{
	partial class frmMain
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.txtbox1_yourname = new System.Windows.Forms.TextBox();
			this.btnShow = new System.Windows.Forms.Button();
			this.btnClear = new System.Windows.Forms.Button();
			this.btnExit = new System.Windows.Forms.Button();
			this.txtbx2_yearofbirth = new System.Windows.Forms.TextBox();
			this.txtYourName = new System.Windows.Forms.TextBox();
			this.txtYear = new System.Windows.Forms.TextBox();
			this.errorProvider1 = new System.Windows.Forms.ErrorProvider(this.components);
			this.label1 = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).BeginInit();
			this.SuspendLayout();
			// 
			// txtbox1_yourname
			// 
			this.txtbox1_yourname.BackColor = System.Drawing.SystemColors.Control;
			this.txtbox1_yourname.BorderStyle = System.Windows.Forms.BorderStyle.None;
			this.txtbox1_yourname.Location = new System.Drawing.Point(138, 77);
			this.txtbox1_yourname.Margin = new System.Windows.Forms.Padding(4);
			this.txtbox1_yourname.Name = "txtbox1_yourname";
			this.txtbox1_yourname.Size = new System.Drawing.Size(104, 23);
			this.txtbox1_yourname.TabIndex = 0;
			this.txtbox1_yourname.Text = "Your name";
			// 
			// btnShow
			// 
			this.btnShow.BackColor = System.Drawing.SystemColors.Control;
			this.btnShow.Location = new System.Drawing.Point(138, 211);
			this.btnShow.Margin = new System.Windows.Forms.Padding(4);
			this.btnShow.Name = "btnShow";
			this.btnShow.Size = new System.Drawing.Size(126, 48);
			this.btnShow.TabIndex = 4;
			this.btnShow.Text = "&Show";
			this.btnShow.UseVisualStyleBackColor = false;
			this.btnShow.Click += new System.EventHandler(this.btnShow_Click);
			// 
			// btnClear
			// 
			this.btnClear.BackColor = System.Drawing.SystemColors.Control;
			this.btnClear.Location = new System.Drawing.Point(329, 211);
			this.btnClear.Margin = new System.Windows.Forms.Padding(4);
			this.btnClear.Name = "btnClear";
			this.btnClear.Size = new System.Drawing.Size(126, 48);
			this.btnClear.TabIndex = 5;
			this.btnClear.Text = "&Clear";
			this.btnClear.UseVisualStyleBackColor = false;
			this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
			// 
			// btnExit
			// 
			this.btnExit.BackColor = System.Drawing.SystemColors.Control;
			this.btnExit.Location = new System.Drawing.Point(524, 211);
			this.btnExit.Margin = new System.Windows.Forms.Padding(4);
			this.btnExit.Name = "btnExit";
			this.btnExit.Size = new System.Drawing.Size(126, 48);
			this.btnExit.TabIndex = 6;
			this.btnExit.Text = "E&xit";
			this.btnExit.UseVisualStyleBackColor = false;
			this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
			// 
			// txtbx2_yearofbirth
			// 
			this.txtbx2_yearofbirth.BackColor = System.Drawing.SystemColors.Control;
			this.txtbx2_yearofbirth.BorderStyle = System.Windows.Forms.BorderStyle.None;
			this.txtbx2_yearofbirth.Location = new System.Drawing.Point(138, 141);
			this.txtbx2_yearofbirth.Margin = new System.Windows.Forms.Padding(4);
			this.txtbx2_yearofbirth.Name = "txtbx2_yearofbirth";
			this.txtbx2_yearofbirth.Size = new System.Drawing.Size(104, 23);
			this.txtbx2_yearofbirth.TabIndex = 2;
			this.txtbx2_yearofbirth.Text = "Year of Birth";
			this.txtbx2_yearofbirth.TextChanged += new System.EventHandler(this.textBox1_TextChanged_1);
			// 
			// txtYourName
			// 
			this.txtYourName.Location = new System.Drawing.Point(276, 75);
			this.txtYourName.Margin = new System.Windows.Forms.Padding(4);
			this.txtYourName.Name = "txtYourName";
			this.txtYourName.Size = new System.Drawing.Size(373, 30);
			this.txtYourName.TabIndex = 1;
			this.txtYourName.TextChanged += new System.EventHandler(this.txtYourName_TextChanged);
			this.txtYourName.Leave += new System.EventHandler(this.txtYourName_Leave_1);
			// 
			// txtYear
			// 
			this.txtYear.Location = new System.Drawing.Point(276, 140);
			this.txtYear.Margin = new System.Windows.Forms.Padding(4);
			this.txtYear.Name = "txtYear";
			this.txtYear.Size = new System.Drawing.Size(373, 30);
			this.txtYear.TabIndex = 3;
			this.txtYear.TextChanged += new System.EventHandler(this.txtYear_TextChanged);
			// 
			// errorProvider1
			// 
			this.errorProvider1.ContainerControl = this;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(12, 77);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(0, 23);
			this.label1.TabIndex = 7;
			// 
			// frmMain
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 22F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(812, 395);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.txtYear);
			this.Controls.Add(this.txtYourName);
			this.Controls.Add(this.txtbx2_yearofbirth);
			this.Controls.Add(this.btnExit);
			this.Controls.Add(this.btnClear);
			this.Controls.Add(this.btnShow);
			this.Controls.Add(this.txtbox1_yourname);
			this.Font = new System.Drawing.Font("Tahoma", 11F);
			this.Margin = new System.Windows.Forms.Padding(4);
			this.Name = "frmMain";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "My Name Project";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmMain_FormClosing);
			this.Load += new System.EventHandler(this.Form1_Load);
			((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox txtbox1_yourname;
		private System.Windows.Forms.Button btnShow;
		private System.Windows.Forms.Button btnClear;
		private System.Windows.Forms.Button btnExit;
		private System.Windows.Forms.TextBox txtbx2_yearofbirth;
		private System.Windows.Forms.TextBox txtYear;
		private System.Windows.Forms.TextBox txtYourName;
		private System.Windows.Forms.ErrorProvider errorProvider1;
		private System.Windows.Forms.Label label1;
	}
}

