#include <bits/stdc++.h>
using namespace std;

/* Giả sử cho danh sách cạnh 1-4, 2-3,... ta phải chuyển danh sách cạnh thành danh sách kề*/

int main()
{
    int n, m; // Sổ đỉnh, số cạnh
    cin >> n >> m;

    vector<int> adj[n + 1]; // Adjacecy list: danh sách kề

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v; // Lần lươt nhập cạnh u-v
        adj[u].push_back(v);
        adj[v].push_back(u); // Nếu đồ thị có hướng tức là u->v, ta chỉ được thêm v vào danh sách kề của u chứ không có dòng này
    }
    
    stack<int> st;
    st.push(1);

    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    while (q.size())
    {
        int curr = q.top();
        cout << curr << " ";
        q.pop();

        for (int v : adj(curr)) // Duyệt các đỉnh kề với curr
        {
            if (!visited[v]) // Nếu v chưa được thăm
            {
                q.push(v);
                visited[v] = true; // Đánh dấu là v đã được thăm
            }
        }
    }   
    
    return 0;
}
1
