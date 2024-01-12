#include <bits/stdc++.h>
using namespace std;

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
    
    stack<int> st;
    st.push(1);

    vector<bool> visited(n+1, false);
    vector<int> depth(n+1, 0); // Độ sâu của các đỉnh

    int v;
    cin >> v; // Đỉnh cần tìm

    int limit; // Giới hạn độ sâu tìm kiếm
    cin >> limit;

    if (limit < 0) cout << "Not found";
    else
    {
        while (st.size())
        {
            int cur = st.top();
            st.pop();

            if (cur == v)
            {
                cout << "Found";
                return 0;
            }
            for (auto &i : adj[cur])
            {
                if (!visited[i])
                {   
                    depth[i] = depth[cur] + 1;
                    if (depth[i] <= limit)
                    {
                        if (i == v)
                        {
                            cout << "Found";
                            return 0;
                        }
                        st.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
        cout << "Not Found";
    }
    return 0;
}
