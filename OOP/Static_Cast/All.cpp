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

        friend ostream& operator<<(ostream& os, const interger& obj)
        {
            os << obj.x;
            return os;
        }
};

void conversion_operator()
{
    interger obj(3); // Constructor called

    string str = obj; // Đầu tiên chuyển đổi obj từ kiểu interger sang kiểu string dựa vào toán tử chuyển đổi do người dùng định nghĩa, sau đó gán cho biến str

    cout << str << endl;

    // cout << obj.operator string() << endl;  

    string str2 = static_cast<string>(obj); // Chuyển đổi kiểu tường minh - explicit conversion
    cout << str2 << endl;

    obj = static_cast<interger>(30); // đầu tiên chuyển đổi 30 sang kiểu interger bằng cách gọi hàm tạo có tham số, sau đó gán cho obj
    cout << obj << endl;
}

class Base {};
class derived : public Base {};
class privateDerived : private Base {};

void Inheritance()
{
    derived d;
    Base *b1 = (Base*)&d;
    Base *b2 = static_cast<Base*>(&d);

    privateDerived pd;
    // Implicit type cast allowed
    Base *b3 = (Base*)&pd;
    // static_cast not allowed, vì privateDerived kế thừa Base với kiểu private
    // Base *b4 = static_cast<Base*>(&pd);
}

void cast_To_and_From_Void_Pointer()
{
    int i = 10;
    void *v = static_cast<void*>(&i); // from int* to void*
    int *ip = static_cast<int*>(v); // from void* to int*
    cout << *ip << endl; // 10
}

int main()
{
    // Conversion operator
    // Inheritance
    cast_To_and_From_Void_Pointer();
}
