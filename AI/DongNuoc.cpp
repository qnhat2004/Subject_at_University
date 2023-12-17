#include <bits/stdc++.h>
using namespace std;

#define show(a) for(auto &i : a) cout << i << ' ';
#define in(a) for(auto &i : a) cin >> i;

int m;
vector<int> Null = {-1, -1, -1};

int cap[3];
vector<int> a(3);
map<vector<int>, vector<vector<int>>> adj;
map<vector<int>, bool> visited;
map<vector<int>, vector<int>> parent;
vector<vector<int>> path;

void show_path(vector<int> End)
{
	vector<int> cur = End;
	while (parent[cur] != Null)
	{
		path.push_back(cur);
		cur = parent[cur];
	}
	path.push_back(a);
	vector<vector<int>>::iterator it;
	for (it = path.end(); it >= path.begin(); --it)
	{
		cout << "-------\n";
		show(*it);
		cout << endl;
	}
}

void generate(vector<int> &cur)
{
	for (int i = 0; i < 3; ++i)
	{
		vector<int> next = cur;
		for (int j = 0; j < 3; ++j)
		{
			if (j != i) // Do tu i sang j
			{
				int nextAmount = min(cap[j] - next[j], next[i]);
				next[j] += nextAmount;
				next[i] -= nextAmount;
				adj[cur].push_back(next); 
			}
		}
	}
}

int bfs(int m)
{
	parent[a] = Null;
    queue<vector<int>> q;
    q.push(a);
    visited[a] = true;

    while (q.size())
    {
        vector<int> cur = q.front(); q.pop();

        if (cur[0] == m)
        {
            show_path(cur);
            return 1;
        }

		generate(cur);
        for (vector<int> &next : adj[cur])
        {
        	if (visited.find(next) == visited.end())
        	{
        		visited[next] = true;
        		q.push(next);
        		parent[next] = cur;
			}
		}
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    in(cap);
    in(a);

    cin >> m;

	cout << bfs(m) << endl;
    return 0;
}
