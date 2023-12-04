#include <bits/stdc++.h>
using namespace std;

class PS
{
    public:
    int t, m;
    public:
        friend ostream &operator << (ostream &out, const PS &a);
        friend iostream &operator >> (istream &in, const PS &a);
};

PS operator + (const PS &a, const PS &b)
{
    return PS(a.t * b.m + a.m * b.t, a.m * b.m);
}

istream &operator >> (istream &in, PS &a)
{
    in >> a.tu >> a.mau;
    return in;
}

ostream &operator << (ostream &out, PS &a)
{
    out << a.t << "/" << a.m;
    return out;
}

int main()
{
    PS a, b;
    cin >> a >> b;
    PS c = a + b;
    std::cout << c;
}
