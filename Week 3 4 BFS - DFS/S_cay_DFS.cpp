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

void dfs( int start )
{
    check[start] = 1;
    for ( int i : ke[start] )
    {
        if ( check[i] == 0 )
        { 
            cout << "(" << start << ", " << i << ")" << " ";
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
            parent[i] = 0;
        }
        while(e--)
        {
            int x , y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        dfs(1);
        cout << '\n';
    }
    return 0;
}