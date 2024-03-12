```csharp
using System.Text;

using Mynamespace;

public class TestMethod
{
    public class demostring
    {
        public void Method()
        {
            String s = "day la string"; // string pool chua co chuoi nay -> tao chuoi moi
            String s2 = "day la string"; // kiem tra xem string pool da co chuoi nay chua, neu co thi dung lai 
            Console.WriteLine(ReferenceEquals(s, s2));
            s2 += "noi chuoi";
            string s3 = s;
            Console.WriteLine(ReferenceEquals(s, s2));
            GC.Collect();
        }

        static void Main()
        {
            demostring d = new demostring();
            d.Method();
        }
    }
}
```