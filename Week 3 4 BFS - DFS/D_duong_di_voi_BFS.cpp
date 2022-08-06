#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    test
    {
        int v , e;
        cin >> v >> e;
        vector<int> ke[v+5];
        while (e--)
        {
            int x , y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int u , y;
        cin >> u >> y;
        int check[105] = {};
        int parent[v+5] ={};
        queue<int> q;
        stack<int> st;
        q.push(u);
        while(!q.empty())
        {
            int tmp = q.front();
            check[tmp] = 1;
            q.pop();
            for ( int i : ke[tmp] ) 
            {
                if ( check[i] == 0 )
                {
                    check[i] = 1;
                    parent[i] = tmp;
                    q.push(i);
                }
            }
        }
        if (check[y] == 0) cout << -1;
        else 
        {
            while (y != u)
            {
                st.push(y);
                y = parent[y];
            }
            st.push(u);
            while ( st.size() > 1 )
            {
                cout << st.top() << " -> ";
                st.pop();
            } 
            cout << st.top();
        }
        cout << '\n';
    }
    return 0;
}   