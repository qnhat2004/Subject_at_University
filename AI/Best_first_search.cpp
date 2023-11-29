#include <bits/stdc++.h>
using namespace std;

/* input:
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

// Best First Search
typedef pair<char, int> node;
class compare
{
    public:
        bool operator()(node const &a, node const &b) // Call function (Hàm gọi), 
        {
            return a.second > b.second;
        }
};

int main()
{
    int n, m;
    cin >> n >> m;

    char target; cin >> target;

    vector<vector<char>> adj(n);

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

    priority_queue<node, vector<node>, compare> pq;
    pq.push(make_pair('A', heuristic['A']));
    visited['A'] = true;

    while (pq.size())
    {
        char cur = pq.top().first; pq.pop();
        // cout << cur << ' ' << heuristic[cur] << endl;

        if (cur == target)
        {
            cout << "Found";
            return 0;
        }

        for (auto &next : adj[cur])
        {
            if (!visited[next])
            {
                if (next == target)
                {
                    cout << "Found";
                    return 0;
                }
                visited[next] = true;
                pq.push({next, heuristic[next]});
            }
        }
    }
    cout << "Not found";
}
