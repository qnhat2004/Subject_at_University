#include <bits/stdc++.h>   
using namespace std;

// Hill-climbing algorithm

/* input:
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
    
typedef pair<char, int> node;

class compare
{
    public:
        bool operator () (const node &a, const node &b)
        {
            return a.second < b.second;
        }
};

bool dfs(char from, char to, map<char, vector<char>> &adj, map<char, int> &h)
{
    map<char, bool> visited;
    visited[from] = true;

    stack<char> st;
    st.push(from);

    priority_queue<node, vector<node>, compare> pq;
    pq.push({from, from});

    while (st.size())
    {
        char cur = st.top(); st.pop();

        if (cur == to) return true;

        for (auto &i : adj[cur])
        {
            if (!visited[i])
            {
                pq.push({i, h[i]});
            }
            
        }
        while (pq.size())
        {
            char next = pq.top().first;
            pq.pop();
            visited[next] = true;
            st.push(next);
        }
    }
    
    return false;
}

int main()
{
    int n, m;
    cout << "Number of vertexs and edges: "; cin >> n >> m;

    cout << "Edges list:\n";
    map<char, vector<char>> adj;

    for (int i = 0; i < m; ++i)
    {
        char a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    

    char from, to;
    cout << "Start, end: "; cin >> from >> to;

    cout << "Heuristic:\n";
    map<char, int> h; // heuristic
    for (auto &i : adj) cin >> h[i.first];
        
    cout << "Result: " << (dfs(from, to, adj, h) ? "Found\n" : "Not found\n") << endl;
}
