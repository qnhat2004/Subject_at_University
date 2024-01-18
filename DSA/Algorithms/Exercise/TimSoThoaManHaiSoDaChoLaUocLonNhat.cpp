/* ĐỀ BÀI: cho 2 số a và b, tìm số x thỏa mãn 1 <= a < b < x sao cho a và b là 2 ước lớn nhất của x.

Link bài: https://codeforces.com/contest/1916/problem/B
Link giải: https://codeforces.com/blog/entry/124138?#

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define show(a) for(auto &i : a) cout << i << ' ';
#define in(a) for(auto &i : a) cin >> i;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define en cout << '\n';

void solve()
{
    ll a, b;
    cin >> a >> b;

    // Ta có công thức: a * b = lcm(a, b) * gcd(a, b)

    // Gọi p là ước nguyên tố nhỏ nhất của b, nên p cũng là ước nguyên tố nhỏ nhất của bp
    // vì b là ước lớn nhất của x = bp => b = x/p => x = bp

    // Nếu b không chia hết cho a, ta có: a * b = lcm(a, b) * gcd(a, b). Mà lcm(a, b) = x ==> a * b = x * gcd(a, b) ==> x = a * b / gcd(a, b)
    if (b % a != 0)
    {
        cout << a * b / __gcd(a, b) << '\n';
        return;
    }

    // Nếu b chia hết cho a => a là ước lớn nhất của b => a = b/p -> p = b/a. Ta có x = bp = b * b/a
    ll p = b / a;
    cout << b * p << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
