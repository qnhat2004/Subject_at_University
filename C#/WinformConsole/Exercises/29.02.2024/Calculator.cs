using System;
using System.Collections.Generic;

class Calculator
{
    public static void Table_Control()
    {
        Console.WriteLine("** Tro choi tinh nhanh **");
        Console.WriteLine("**  +: tinh phep cong  **");
        Console.WriteLine("**  -: tinh phep tru   **");
        Console.WriteLine("**  *: tinh phep nhan  **");
        Console.WriteLine("**  /: tinh phep chia  **");
        Console.WriteLine("*************************");
    }
    
    public static void Input(out int a, out int b, out char tt)
    {
        Console.WriteLine("nhap 2 so va toan tu:");
        Console.Write("a = ");
        a = Convert.ToInt32(Console.ReadLine());
        Console.Write("b = ");
        b = Convert.ToInt32(Console.ReadLine());
        Console.Write("tt = ");
        tt = Convert.ToChar(Console.ReadLine());
    }

    static KeyValuePair<double, bool> Calculate(int a, int b, char tt)
    {
        double ans = 0;
        bool check = true;
        switch (tt)
        {
            case '+':
                ans = a + b;
                break;
            case '-':
                ans = a - b;
                break;
            case '*':
                ans = a * b;
                break;
            case '/':
                ans = (double) a / b;
                break;
            default:
                check = false;
                break;
        }

        return new KeyValuePair<double, bool>(ans, check);
    }
    
    public static void Output(int a, int b, char tt)
    {
        if (Calculate(a, b, tt).Value == false)
        {
            Console.WriteLine("Ban nhap sai toan tu!");
        }
        else
        {
            double ans = Calculate(a, b, tt).Key;
            Console.WriteLine("{0} {1} {2} = {3}", a, tt, b, ans);
        }
    }
}

class Program
{
    static void Main()
    {
        int a, b;
        char tt;
        char option = 'y';
        
        while (option != 'n')
        {
            Calculator.Table_Control();
            Calculator.Input(out a, out b, out tt);
            Calculator.Output(a, b, tt);
            Console.Write("ban co muon lam nua khong? (y/n): ");
            option = Console.ReadKey().KeyChar;
        }
    }
}
