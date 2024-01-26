- `using`: Giống như import trong python và include trong c++, dùng để import các thư viện có sẵn trong C#.
- `namespace`: Trong 1 namespace chứa rất nhiều class, struct, interface,... `namespace` giống như 1 thư mục, các class, struct, interface,... giống như các file trong thư mục đó.

---

```csharp
using System;                               // Thư viện 
// using System.Collections.Generic;
// using System.ComponentModel;            
// using System.Data;
// using System.Drawing;                    // Do trong phần này chưa dùng đến các thư viện này nên có thể bỏ nó đi
// using System.Linq;
// using System.Text;
// using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1 // Trong 1 namespace có nhiều lớp (có thể có hàng nghìn lớp), namespace giống như 1 thư mục, các lớp giống như file
{
	public partial class Form1 : Form // Form1 kế thừa Form, parital: hợp 2 file lại
	{
		public Form1() // Constructor 
		{
			InitializeComponent(); // Khởi tạo thành phần
			TextBox x = new TextBox();

		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}

		private void button1_Click(object sender, EventArgs e)      // Khi click vào button thì sẽ chạy hàm này
		{
			Console.WriteLine("Hello World");
		}

		private void button2_Click(object sender, EventArgs e)
		{

		}
	}
}

```