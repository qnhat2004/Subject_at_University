#include <bits/stdc++.h>
using namespace std;

/* Nạp chồng phương thức và biến-phương thức tĩnh:
- có thể gọi phương thức tĩnh trực tiếp như một hàm mà không cần khởi tạo đối tượng
- biến tĩnh có thể được sử dụng chung cho tất cả các đối tượng của lớp đó
- nạp chồng có thể tái sử dụng hàm cho các kiểu dữ liệu khác nhau, hoặc với số lượng tham số khác nhau */

class Math
{
    public:
        static int abs(int a) { return a < 0 ? -a : a; }
        
        static double abs(double a) { return a < 0 ? -a : a; }
        
        static int max (int a, int b) { return a > b ? a : b; }
        
        static int max(int a, int b, int c) { return Math::max(Math::max(a, b), c); }
};

int main()
{
    cout << Math::abs(-10.5) << endl;
    cout << Math::max(10, 100) << endl;
    cout << Math::max(4, 5, 6) << endl;
}
