using System;
using System.Text;

namespace Delegate
{
	class Program
	{
		delegate int MyDelegate(string s);
		public static void Main(string[] args)
		{
			Console.OutputEncoding = Encoding.Unicode;

			MyDelegate convertToInt = new MyDelegate(ConvertStringToInt); // ConvertToInt thay mat cho ham ConvertStringToInt
			MyDelegate showString = new MyDelegate(ShowString);
			MyDelegate multicastDelegate = convertToInt + showString; // dau tien, muticastDelegate se thuc hien ConvertToInt, sau do thuc hien showString
			
			string stringNumber = "1234";
			int valueConverted = convertToInt(stringNumber);
			Console.WriteLine("After convert: " + stringNumber);
			
			Console.Write("Multicast delegate: ");
			multicastDelegate(stringNumber); // multicast = convetToInt + showString
			
			multicastDelegate -= showString; // bo di showString trong multicast
			int number = multicastDelegate(stringNumber); // chi con convertToInt
			Console.WriteLine("After remove showString from multicast: " + number);
			
			Console.WriteLine("Test Delegate in parameter: ");
			NhapVaShowTen(showString);
		}

		static int ConvertStringToInt(string stringValue)
		{
			int valueInt = 0;
			Int32.TryParse(stringValue, out valueInt);
			//Console.OutputEncoding = Encoding.Unicode;
			Console.WriteLine("Data type casted successful");
			return valueInt;
		}

		static int ShowString(string stringValue)
		{
			Console.WriteLine(stringValue);
			return 0;
		}

		static void NhapVaShowTen(MyDelegate showTen)
		{
			Console.Write("Moi nhap ten cua ban: ");
			string ten = Console.ReadLine();
			showTen(ten);
		}
	}
}
