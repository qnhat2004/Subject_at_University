#include <bits/stdc++.h>
using namespace std;

class PS
{
    int t, m;
    public:
        PS(int t, int m)
        {
            this->t = t;
            this->m = m;
        }
        // Cách 1:
        // PS operator + (PS b)
        // {
        //     return PS(this->t * b.m + this->m * b.t, this->m * b.m);
        // }
        void print() { cout << this->t << '/' << this->m; }
        
        // Cách 2:
        friend PS operator + (const PS &a, const PS &b);
        
        // Cách 3: khai báo các thuộc tính về public
};

PS operator + (const PS &a, const PS &b)
{
    return PS(a.t * b.m + a.m * b.t, a.m * b.m);
}

int main()
{
    PS a(2, 3), b(3, 4);
    PS c = a + b;
    c.print();
}
