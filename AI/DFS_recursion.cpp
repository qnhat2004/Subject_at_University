#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/* Sử dụng mảng giúp chương trình chạy nhanh hơn nhưng tốn bộ nhớ nếu số lượng đỉnh lớn và đồ thị thưa*/

int n, m; // Số đỉnh, số cạnh

vector<int> adj[1001]; // Adjacency List - Danh sách kề
bool visited[1001]; // Mảng đánh dấu các đỉnh đã được duyệt

void inp() // Đọc danh sách cạnh và chuyển thành danh sách kề
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, false, sizeof(visited)); // Đặt tất cả các phần tử mảng thành false vì chưa đỉnh nào được thăm
}

void dfs(int u) // Duyệt đỉnh u
{
    cout << u << " ";
    visited[u] = true; // Đánh dấu là u đã được thăm
    for (int v : adj[u]) // Duyệt các đỉnh kề với u
        if (!visited[v]) // Nếu v chưa được thăm
            dfs(v); // Duyệt v (đệ quy
}

int main()
{
    inp();
    dfs(1); // Duyệt từ đỉnh 1 đến hết đồ thị
}
1
