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

void dfs( int u )
{
    check[u] = 1;
    cout << u << " ";
    for ( int i : ke[u] )
    {
        if ( check[i] == 0 )
        { 
            dfs(i);
        }
    }
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
        }
        while(e--)
        {
            int x , y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int u;
        cin >> u;
        dfs(u);
        cout << '\n';
    }
    return 0;
}