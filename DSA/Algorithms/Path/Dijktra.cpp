#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define show(a) for(auto &i : a) cout << i << ' ';

/* vd:
    a           b            c
a | 0        |  min(a, b) | min(a, c)
b | min(a,b) |  0         | min(b, c)
c | min(a, c)|  min(b, c) | 0
*/


/*  Định nghĩa:
    W[u, v]: giá trị đường đi trực tiếp từ u -> v
    D[u, v]: giá trị đường đi ngắn nhất từ u -> v
    trace[u, v]: đỉnh trước u trên đường đi ngắn nhất từ u -> v, dùng để truy vết
*/

void init_trace(vector<vector<int>> &trace)
{
    int n = trace.size();
    for (int u = 0; u < n; ++u)
    {
        for (int v = 0; v < n; ++v)
        {
            trace[u][v] = u;
        }
    }        
}

void floyd_warshall(int n, vector<vector<int>> &w, vector<vector<int>> &D, vector<vector<int>> &trace)
{
    // Ban đầu khởi tạo khoảng cách ngắn nhất bằng độ dài đường đi trực tiếp
    D = w; 
    init_trace(trace); // Nếu cần dò đường đi

    for (int k = 0; k < n; ++k) // Duyệt qua tất cả các đỉnh làm đỉnh trung gian
    {
        for (int u = 0; u < n; ++u)   // Duyệt qua tất cả các cặp đỉnh
        {
            for (int v = 0; v < n; ++v)
            {
                if (D[u][v] > D[u][k] + D[k][v]) // Nếu tìm được đỉnh trung gian có đường đi ngắn hơn
                {
                    D[u][v] = D[u][k] + D[k][v];
                    trace[u][v] = trace[k][v];
                }
            }
        }      
    }
}

vector<int> trace_path(vector<vector<int>> &trace, int u, int v)
{
    vector<int> path;
    int cur = v;
    while (cur != u)
    {
        path.push_back(cur+1);
        cur = trace[u][cur];
    }
    path.push_back(u+1);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> w(n+5, vector<int>(n+5));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j) w[i][j] = 0;
            else w[i][j] = INT_MAX;
        }
    }
    
    for (int i = 0; i < m; ++i)
    {
        int u, v, c; cin >> u >> v >> c;
        w[u-1][v-1] = w[v-1][u-1] = c;
    }

    vector<vector<int>> D(n+5, vector<int>(n+5, INT_MAX));
    vector<vector<int>> trace(n+5, vector<int>(n+5));

    floyd_warshall(n, w, D, trace);

    while (k--)
    {
        int a, u, v;
        cin >> a >> u >> v;
        --u, --v;
        
        if (a == 0)
        {
            cout << D[u][v] << '\n';
        }
        else
        {
            vector<int> path = trace_path(trace, u, v);
            cout << path.size() << ' ';
            show(path);
            cout << '\n';
        }
    }
    return 0;
}
