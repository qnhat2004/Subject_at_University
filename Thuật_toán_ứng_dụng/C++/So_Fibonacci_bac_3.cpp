#include <bits/stdc++.h>
using namespace std;

#define show(a) for(auto &i : a) cout << i << ' ';
#define int long long

unordered_map<int, int> m;
int fib(int n)
{
    if(m.find(n) == m.end())
    {
        int r = n % 3;
        int k = n/3;
        if (r == 0) m[n] = fib(2*k);
        else if (r == 1) m[n] = fib(2*k) + fib(2*k+1);
        else m[n] = fib(2*k) + fib(2*k+1) + fib(2*k+2);
    }
    return m[n];
}

int32_t main()
{
    m[0] = 0, m[1] = 1, m[2] = 2;
    int n;
    cout << "Nhap n = "; cin >> n;
    cout << "f(" << n << ") = " << fib(n) << endl;
    return 0;
}
