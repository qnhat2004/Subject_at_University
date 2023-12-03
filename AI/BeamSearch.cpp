#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> node;

class compare
{
    public:
        bool operator()(node const &a, node const &b)
        {
            return a.second > b.second;
        }
};

string getPath(char start, char target, map<char, char> &parent)
{
    string path = "";
    for (char v = target; v != start; v = parent[v])
        path =  v + " " + path;
    path = start + " " + path;
    return path;
}

int main()
{
    int k;
    cout << "Enter k: "; cin >> k;

    int n, m;
    cin >> n >> m;

    char start, target;
    cin >> start >> target;

    map<char, vector<char>> adj;

    for (int i = 0; i < m; ++i)
    {
        char u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    map<char, int> heuristic;
    for (int i = 0; i < n; ++i)
    {
        char v; int hv;
        cin >> v >> hv;
        heuristic[v] = hv;
    }

    map<char, bool> visited;
    map<char, char> parent;

    priority_queue<node, vector<node>, compare> pq;
    pq.push(make_pair(start, heuristic[start]));

    while (pq.size())
    {
        char cur = pq.top().first; pq.pop();

        if (visited[cur]) continue;
        visited[cur] = true;

        if (cur == target)
        {
            cout << "Found\n";
            string path = getPath(start, target, parent);
            cout << path << endl;
            return 0;
        }

        vector<node> next_nodes;
        for (auto &next : adj[cur])
        {
            if (!visited[next])
            {
                next_nodes.push_back({next, heuristic[next]});
                parent[next] = cur;
            }
        }

        sort(next_nodes.begin(), next_nodes.end(), compare());
        for (int i = 0; i < min(k, (int)next_nodes.size()); ++i)
        {
            pq.push(next_nodes[i]);
        }
    }
    cout << "Not found";
}
