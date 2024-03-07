# readonly and const in C#
- **readonly**: chỉ thay đổi được giá trị trong constructor và khi khởi tạo (gọi là khởi gán)
- **const**: chỉ thay đổi được giá trị khi khởi tạo
- **readonly** và **const** chỉ dùng để khai báo thuộc tính (property) của class

```csharp
using System;

namespace Mynamespace
{
    public readonly struct Mystruct // Neu struct la readonly thi thuoc tinh cung phai la readonly
    {
        public readonly int a = 5;

        public Mystruct()
        {
            // a = 5;
        }
        public readonly void Hello()
        {
            Console.WriteLine("struct");
        }
    };
    internal class Demo
    {
        public static readonly int h;
        public int So; // field - thuoc tinh cua lop 
        public const int a = 5; // Tinh~, Khong doi duoc gia tri cua hang o phuong thuc
        public readonly int r1 = a; // Readonly chi thay doi duoc gia tri khi khai bao hoac trong Constructor
        public readonly int r2;

        public Demo()
        {
            So = 4;
            // a = 4; Error
        }

        public Demo(int So)
        {
            r1 = So;
        }
        public /*readonly*/ void Test()
        {
            const int k = 9;
            // readonly int a =  Error: Khong dung de khai bao bien cuc bo, phuong thuc,... chi dung de khai bao thuoc tinh
            // k;
            int j = 0; // Bien cuc bo
            So = 5;
            // b = 5;
        }
        
        static void Main(string[] args)
        {
            Demo demo = new Demo();
            Console.WriteLine(demo.r1);
        }
    }
}
```