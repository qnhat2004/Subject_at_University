#include <bits/stdc++.h>
using namespace std;

#define int long long

// Meet in the middle
int m, n;
vector<int> A, B;
vector<int> a;

void tryX(int i, int sum)
{
    if (sum > m) return;
    if (i == n/2 + 1)
    {
        A.push_back(sum);
        return;
    }
    tryX(i+1, sum);
    tryX(i+1, sum + a[i]);
}

void tryY(int i, int sum)
{
    if (sum > m) return;
    if (i == n)
    {
        B.push_back(sum);
        return;
    }
    tryY(i+1, sum);
    tryY(i+1, sum + a[i]);
}

int32_t main()
{
    cout << "Nhap m = "; cin >> m;
    cout << "Nhap n = "; cin >> n;
    a.resize(n); 
    for (int i = 0; i < n; ++i)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    tryX(0, 0);
    tryY(n/2 + 1, 0);
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());
    int cnt = 0;
    for (int i = 0, j1 = 0, j2 = 0; i < A.size(); ++i)
    {
        while (j1 < B.size() && A[i] + B[j1] <= m) ++j1;
        while (j2 < B.size() && A[i] + B[j2] < m) ++j2;
        cnt += j1 - j2;
    }
    cout << "Co tat ca " << cnt << " cach phan tich." << endl;
    return 0;
}
