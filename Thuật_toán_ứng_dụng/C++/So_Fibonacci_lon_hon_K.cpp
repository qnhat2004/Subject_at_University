#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll k;
    cin >> k;
    
    if (k < 0) {
        cout << 0;
        return;
    }

    ll a = 0, b = 1;
    while (a <= k) {
        b += a;
        a = b - a;
    }
    cout << a << endl;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }
}
