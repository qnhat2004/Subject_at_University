#include <bits/stdc++.h>
using namespace std;

/* input1:
Vertices, Edges: 10 9
Start, Target: A B
A C
A D
A E
D F
D I
E G
E K
G B
G H
Vertex & Heuristic:
A 20
C 15
D 6
E 7
F 10
I 8
G 5
K 12
B 0
H 3
*/

// Best First Search
typedef pair<char, int> node;
// typedef pair<char, vector<char>> path;

class compare
{
    public:
        bool operator()(node const &a, node const &b) // Call function (Hàm gọi), 
        {
            return a.second < b.second;
        }
};

void getPath(char start, char target, map<char, char> &parent)
{
    vector<char> path;
    char cur = target;
    while (cur != '0')
    {
        path.push_back(cur);
        cur = parent[cur];
    }
    for (int i = path.size() - 1; i >= 0; --i)
        cout << path[i] << ' ';
}

int main()
{
    int n, m;
    cout << "Vertices, Edges: ";
    cin >> n >> m;

    char start, target;
    cout << "Start, Target: ";
    cin >> start >> target;

    map<char, vector<char>> adj;

    cout << "Edges:\n";
    for (int i = 0; i < m; ++i)
    {
        char u, v; cin >> u >> v;
        adj[u].push_back(v); // Directed Graph - Đồ thị có hướng
        // adj[v].push_back(u); // Undirected Graph - Đồ thị vô hướng
    }

    map<char, int> heuristic; // hàm heauristic của đỉnh i
    cout << "Vertex & Heuristic:\n";
    for (int i = 0; i < n; ++i)
    {
        char v; int hv;
        cin >> v >> hv;
        heuristic[v] = hv;
    }

    map<char, bool> visited;
    visited[start] = true;

    priority_queue<node, vector<node>, compare> pq;
    pq.push(make_pair(start, heuristic[start]));

    map<char, char> parent;
    parent[start] = '0';

    while (pq.size())
    {
        char cur = pq.top().first; pq.pop();
        // cout << cur << ' ' << heuristic[cur] << endl;

        if (cur == target)
        {
            cout << "Found\n";
            getPath(start, target, parent);
            return 0;
        }

        for (auto &next : adj[cur])
        {
            if (visited.find(next) == visited.end())
            {
                visited[next] = true;
                pq.push({next, heuristic[next]});
                parent[next] = cur;
            }
        }
    }
    cout << "Not found";
}
