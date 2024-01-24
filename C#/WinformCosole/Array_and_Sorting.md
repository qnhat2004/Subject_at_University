# Mảng và sắp xếp mảng trong C#
## Mảng:
### Khai báo mảng:
`int[] arr = new int[10];`
### Khai báo mảng có giá trị ban đầu:
`int[] arr = new int[]{1, 2, 3, 4};` <br\>
hoặc: <br\>
`int[] arr = {1, 2, 3, 4};` <br\>
Nếu mảng có n phần tử với n được nhập từ bàn phím: 
`int[] arr = new int[n];`
# Sắp xếp mảng:
`Array.Sort(arr);`

---
```cs
using System;

namespace HelloC_ {
    class Program {
        static void Main() {
            int n = Convert.ToInt32(Console.ReadLine());
            int[] arr = new int[n];
            for (int i = 0; i < arr.Length; ++i)
                arr[i] = Convert.ToInt32(Console.ReadLine());
            Array.Sort(arr);
            foreach (int i in arr) 
                Console.Write(i + " ");
        }
    }
}
```