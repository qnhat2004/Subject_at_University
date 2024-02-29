using System;

class Date
{
    int d, m, y;
    static int[] Day_of_Month = new int[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    public Date()
    {
        d = y = m = 0;
    }

    public Date(int d, int m, int y) 
    {
        this.d = d;
        this.m = m;
        this.y = y;
    }

    public void Input()
    {
        Console.Write("Nhap ngay: ");
        d = Convert.ToInt32(Console.ReadLine());
        Console.Write("Nhap thang: ");
        m = Convert.ToInt32(Console.ReadLine());
        Console.Write("Nhap nam: ");
        y = Convert.ToInt32(Console.ReadLine());
    }

    public bool Is_Leap_Year() 
    {
        return (y % 100 == 0 && y % 400 == 0 || y % 4 == 0);
    }

    public bool Check_Date()
    {
        // Normally, February has 28 days
        return (d <= Day_of_Month[m - 1]);
    }

    public Date Next_Day()
    {
        if (Is_Leap_Year()) Day_of_Month[1] = 29; // Leap year, February has 29 days
        Date New_date = this;
        if (New_date.d == 12 && New_date.m == 12)
        {
            New_date = new Date(1, 1, New_date.y + 1);
        }
        else
        {
            d++;
            if (d > Day_of_Month[m - 1])
            {
                d = 1;
                m++;
            }
        }
        return New_date;
    }

    public void Output()
    {
        Console.Write("Ngay {0}/{1}/{2} ", d, m, y);
        if (Check_Date())
        {
            Console.WriteLine("la ngay hop le");
            Date New_Date = Next_Day();
            Console.WriteLine("Ngay tiep theo la: {0}/{1}/{2}", New_Date.d, New_Date.m, New_Date.y);
        }
        else
            Console.WriteLine("la ngay khong hop le");
    }
}

class Program
{
    static void Main()
    {
        Date date = new Date();
        date.Input();
        date.Output();
    }
}
