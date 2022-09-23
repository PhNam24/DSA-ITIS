#include <bits/stdc++.h>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;
vector<int> ke[105];
int check[105] = {};
int parent[105] = {};
set<int> s;
int num[105] = {} ;
int low[105] = {} ;
int cnt = 1;

void dfs( int u )
{
    int cnt_child = 0;
    check[u] = 1;
    low[u] = num[u] = cnt++;
    for ( int i : ke[u] )
    {
        if ( i == parent[u] ) continue;
        if ( check[i] == 0 )
        { 
            parent[i] = u;
            cnt_child++;
            dfs(i);
            low[u] = min(low[u] , low[i]);
            if ( low[i] >= num[u] && parent[u] != 0)
            {
                s.insert(u);
            }
        }
        else low[u] = min(low[u] , num[i]);
    }
    if (parent[u] == 0 && cnt_child > 1) s.insert(u);
}

int main()
{
    fast
    test
    {
        int v , e;
        cin >> v >> e;
        for ( int i = 0 ; i < 105 ; i++ )
        {
            ke[i].clear();
            check[i] = 0;
            parent[i] = 0;
            low[i] = 0;
            num[i] = 0;
        }
        cnt = 1;
        s.clear();
        while(e--)
        {
            int x , y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        dfs(1);
        if (s.size()) for ( int i : s ) cout << i << " ";
        else cout << -1;
        cout << '\n';
    }
    return 0;
}