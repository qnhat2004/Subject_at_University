#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define show(a) for(auto &i : a) cout << i << ' ';
#define in(a) for(auto &i : a) cin >> i;

void solve()
{
    int n; cin >> n;
    int a[n]; in(a);
    sort(a, a+n, greater<int>());
    int ans = 0, Min = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        ans += 1;
        Min = min(Min - 1, a[i]);
        if (Min == 0) break;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }
    
    return 0;
}
