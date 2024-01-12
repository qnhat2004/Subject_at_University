#include <bits/stdc++.h>
using namespace std;

map<int, bool> visited; // Mảng đánh dấu các đỉnh đã được duyệt
map<int, list<int>> adj; // Adjacency List - Danh sách kề

void addEge(int u, int v) // Thêm cạnh u v vào danh sách kề
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(int u) // Duyệt đỉnh u
{
    cout << u << ' ';
    visited[u] = true; // Đánh dấu là u đã được thăm
    for (int v : adj[u])
        if (!visited[v])
            DFS(v);
}

int main()
{
    addEge(1, 2);
    addEge(1, 3);
    addEge(2, 4);
    addEge(2, 5);
    addEge(3, 6);
    addEge(3, 7);
    addEge(4, 8);
    addEge(5, 8);
    addEge(6, 8);
    addEge(7, 8);
    DFS(1); // Bắt đầu duyệt từ 1
}
1
