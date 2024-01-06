#include <bits/stdc++.h>
using namespace std;

// new class
class interger
{
    public:
        int x;
    public:
        // constructor
        interger(int x = 0) : x(x)
        {
            cout << "constructor called" << endl;
        }

        operator string() 
        {
            cout << "Conversion operator called\n";
            return std::to_string(x);
        }

        // friend ostream& operator<<(ostream& os, const interger& obj)
        // {
        //     os << obj.x;
        //     return os;
        // }
};

int main()
{
    interger obj(3); // Constructor called

    string str = obj; // Đầu tiên chuyển đổi obj từ kiểu interger sang kiểu string dựa vào toán tử chuyển đổi do người dùng định nghĩa, sau đó gán cho biến str

    cout << str << endl;

    // cout << obj.operator string() << endl;  
}
