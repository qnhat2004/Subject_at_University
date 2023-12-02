#include <bits/stdc++.h>
using namespace std;

/* input1:
5 5 E
A B
B C
A D
B D
A E
10
20
30
40
50
*/

/* input2:
8 11
S A
S F
S A
F B
A B
A E
B E
E C
B C
B D
D G
C G
S 8
F 4
A 5
B 4
E 3
D 1
C 1
G 0
*/

// Best First Search
typedef pair<char, int> node;
// typedef pair<char, vector<char>> path;

class compare
{
    public:
        bool operator()(node const &a, node const &b) // Call function (Hàm gọi), 
        {
            return a.second > b.second;
        }
};

string getPath(char start, char target, map<char, char> &parent)
{
    string path = "";
    for (char v = target; v != start; v = parent[v]) // Lần ngược lại các đỉnh cha của target để tìm đường đi đã tìm thấy
        path =  v + " " + path;
    path = start + " " + path;
    return path;
}

int main()
{
    int n, m;
    cin >> n >> m;

    char start, target;
    cin >> start >> target;

    map<char, vector<char>> adj;

    for (int i = 0; i < m; ++i)
    {
        char u, v; cin >> u >> v;
        adj[u].push_back(v); // Directed Graph - Đồ thị có hường
        // adj[v].push_back(u); // Undirected Graph - Đồ thị vô hướng
    }

    map<char, int> heuristic; // hàm heauristic của đỉnh i
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

    while (pq.size())
    {
        char cur = pq.top().first; pq.pop();
        // cout << cur << ' ' << heuristic[cur] << endl;

        if (cur == target)
        {
            cout << "Found\n";
            string path = getPath(start, target, parent);
            cout << path << endl;
            return 0;
        }

        for (auto &next : adj[cur])
        {
            if (visited.find(next) == visited.end())
            {
                // if (next == target)
                // {
                //     cout << "Found\n";
                //     string path = getPath(start, target, parent);
                //     cout << path << endl;                           
                //     return 0;
                // }
                visited[next] = true;
                pq.push({next, heuristic[next]});
                parent[next] = cur;
            }
        }
    }
    cout << "Not found";
}
