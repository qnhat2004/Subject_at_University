#include <bits/stdc++.h>
using namespace std;

bool DPS (int v, int limit, int n, vector<vector<int>> &adj) // Đỉnh cần tìm, giới hạn độ sâu, số đỉnh, danh sách kề
{
    stack<int> st;
    st.push(1);

    vector<bool> visited(n+1, false);
    visited[1] = true;

    vector<int> depth(n+1, 0); // Độ sâu của các đỉnh

    if (limit < 0)
        return false;

    while (st.size())
    {
        int cur = st.top();
        st.pop();

        if (cur == v)  return true;

        for (auto &i : adj[cur])
        {
            if (!visited[i])
            {   
                depth[i] = depth[cur] + 1;

                if (depth[i] <= limit)
                {
                    if (i == v) return true;
                        
                    st.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    /* 1
        \       6      5 
         \      |      | 
          2-----3------4   
    */

    int n = 6; // Số đỉnh
    vector<vector<int>> adj = { {},
                                {2}, 
                                {1, 3},
                                {2, 4, 6},
                                {3, 5},
                                {3},
                                {3}
                            };               

    int v;
    cin >> v; // Đỉnh cần tìm

    int limit; // Giới hạn độ sâu tìm kiếm
    cin >> limit;

    for (int i = 0; i <= limit; ++i)
    {
        if (DPS(v, i, n, adj))
        {
            cout << "Found at depth: " << i;
            return 0;
        }
    }

    cout << "Not found";
    return 0;
}
