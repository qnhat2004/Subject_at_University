class Test
{
    private static List<int> a;

    static void Sieve()
    {
        const int Max = (int)1e6;
        a = Enumerable.Repeat(1, Max + 1).ToList(); 
        // Enumerable.Repeat(1, Max + 1): Phương thức Enumerable.Repeat của .NET tạo ra một chuỗi các phần tử mà mỗi phần tử đều có cùng một giá trị đã cho.
        // Trong trường hợp này, nó tạo ra một chuỗi gồm Max + 1 phần tử, mỗi phần tử đều có giá trị là 1.

        // .ToList(): Phương thức này chuyển đổi chuỗi đã tạo thành một danh sách (List).
        a[0] = a[1] = 0;
        for (int i = 2; i <= double.Sqrt(Max); ++i)
        {
            if (a[i] == 1)
                for (int j = i * i; j <= Max; j += i)
                    a[j] = 0;
        }
    }

    static void Main()
    {
        Sieve();
        int n = Convert.ToInt32(Console.ReadLine());
        if (a[n] == 1) 
            Console.WriteLine(n + " is a prime number");
        else
        {
            Console.WriteLine(n + " is not a prime number");
        }
    }
}