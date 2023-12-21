#include <bits/stdc++.h>
using namespace std;

/*
- Liên kết muộn: Runtime, có nghĩa là việc gọi hàm được thực hiện tại thời điểm chạy chương trình
- Liên kết sớm: Compile time, việc gọi hàm được thực hiện tại thời điểm biên dịch chương trình
*/

class Base
{
    public:
        virtual ~Base() { cout << "Destructor of base class\n"; }
        virtual void print() { cout << "print base class\n"; }
        void show() { cout << "show base class\n"; }
};

class derived : public Base
{
    public:
        ~derived() { cout << "Destructor of derived class\n"; }
        void print() { cout << "print derived class\n"; }
        void show() { cout << "show derived class\n"; }
};

int main()
{
    Base* Bptr;
    derived d;
    Bptr = &d;

    // virtual function, binded at runtime - Late binding
    Bptr->print(); // gọi hàm print của derived class

    // non-virtual function, binded at compile time - Early binding
    Bptr->show(); // gọi hàm show của Base class
    return 0;
}
