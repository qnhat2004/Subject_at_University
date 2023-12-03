#include <bits/stdc++.h>
using namespace std;

typedef pair<char, char> edge;
typedef pair<char, int> node;

const int MAX = 1e5 + 5, min_cost = INT_MAX;

int main()
{
    int n, m;
    cout << "Number of vertices, edges: "; cin >> n >> m;

    map<edge, int> dist; // Độ dài cạnh
    map<char, int> h; // Hàm heuristic
    map<char, vector<char>> adj; // Danh sách kề

    cout << "Edge, distance\n";
    for (int i = 0; i < m; ++i)
    {
        char u, v; cin >> u >> v;
        int distance; cin >> distance; 
        dist[{u, v}] = dist[{v, u}] = distance;
        adj[u].push_back(v); // adj[v].push_back(u);
    }

    cout << "Vertex, heuristic\n";
    for (int i = 0; i < n; ++i)
    {
        char u; int heuristic; cin >> u >> heuristic;
        h[u] = heuristic;
    }

    char from, to;
    cout << "From, to: "; cin >> from >> to;

    priority_queue<node, vector<node>, greater<node>> pq;

    map<char, int> g; // Độ dài đường đi từ đỉnh bắt đầu đến đỉnh hiện tại
    map<char, char> parent; // Đỉnh cha của đỉnh hiện tại
    map<char, bool> visited;
    map<char, int> f; // f = g + h

    pq.push({from, 0});

    while (pq.size())
    {
        char cur = pq.top().first;
        pq.pop();

        if (cur == to)
        {
            cout << "Path: ";
            string path = "";
            while (cur != from)
            {
                path = cur + " " + path;
                cur = parent[cur];
            }
            path = from + path;
            cout << "Path: " << path << ", Cost: " << g[to] << endl;
            return 0;
        }
        for (auto &i : adj[cur])
        {
            if (visited.find(i) == visited.end() || g[cur] + dist[{cur, i}] < g[i])
            {
                g[i] = g[cur] + dist[{cur, i}];
                f[i] = g[i] +h[i];
                pq.push({i, f[i]});
                visited[i] = true;
            }
        }
    }
    cout << "No path\n";
    return 0;
}
