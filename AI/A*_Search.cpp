#include <bits/stdc++.h>
using namespace std;

typedef pair<char, char> edge;
typedef pair<char, int> node; // đỉnh và giá trị f = g + h

/* input:
Number of vertices, edges: 8 10
Edge, distance
S A 2
S B 3
A D 3
B D 1
B C 3
D C 1
C E 2
D F 3
E G 1
F G 2
Vertex, heuristic
S 6
A 4
B 4
C 3
D 4
F 1
E 1
G 0
From, to: S G
*/

class compare
{
    public:
        bool operator() (const node &a, const node &b)
        {
            return a.second > b.second;
        }
};

int main()
{
    int n, m;
    cout << "Number of vertices, edges: "; cin >> n >> m;

    map<edge, int> dist; // Độ dài cạnh
    map<char, int> h; // Hàm heuristic
    map<char, int> f; // f = g + h
    map<char, int> g; // Độ dài đường đi từ đỉnh bắt đầu đến đỉnh hiện tại

    map<char, vector<char>> adj; // Danh sách kề

    cout << "Edge, distance\n"; // Cạnh và độ dài cạnh
    for (int i = 0; i < m; ++i)
    {
        char u, v; cin >> u >> v;
        int distance; cin >> distance; 
        dist[{u, v}] = dist[{v, u}] = distance;
        adj[u].push_back(v); // Đồ thị có hướng
        // adj[v].push_back(u);
    }

    cout << "Vertex, heuristic\n";
    for (int i = 0; i < n; ++i)
    {
        char u; int heuristic; cin >> u >> heuristic;
        h[u] = heuristic;
    }

    char from, to;
    cout << "From, to: "; cin >> from >> to;

    priority_queue<node, vector<node>, compare> pq;

    map<char, char> parent; // Đỉnh cha của đỉnh hiện tại
    map<char, bool> visited;
    
    pq.push({from, 0}); // f[from] = 0
    parent[from] = '0';

    while (pq.size())
    {
        char cur = pq.top().first;
        pq.pop();

        if (cur == to) // Tìm thấy thì in ra đường đi và tổng độ dài đường đi, kết thúc chương trình
        {
            vector<char> path;
            while (cur != '0')
            {
                path.push_back(cur);
                cur = parent[cur];
            }
            cout << "Path: ";
            for (int i = path.size() - 1; i >= 0; --i)
                cout << path[i] << " ";
            cout << "\nTotal distance: " << g[to] << "\n";
            return 0;
        }
        for (auto &i : adj[cur])
        {
            if (visited.find(i) == visited.end() || g[cur] + dist[{cur, i}] < g[i])
            {
                g[i] = g[cur] + dist[{cur, i}];
                f[i] = g[i] + h[i];
                pq.push({i, f[i]});
                visited[i] = true;
                parent[i] = cur;
            }
        }
    }
    
    cout << "No path\n";
    return 0;
}
