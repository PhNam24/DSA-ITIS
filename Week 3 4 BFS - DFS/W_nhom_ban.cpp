#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<int> ke[105];
int visited[105] = {};
int ans = -1;
int cnt = 0;

void dfs ( int u )
{
    visited[u] = 1;
    cnt++;
    for ( int i : ke[u] )
    {
        if (visited[i] == 0)
        {
            dfs(i);
        } 
    }
    ans = max( ans , cnt );
}

int main ()
{
    fast
    test
    {
        for ( int i = 0 ; i < 105 ; i++ )
        {
            ke[i].clear();
            visited[i] = 0;
        }
        ans = -1;
        cnt = 0;
        int v , e;
        cin >> v >> e;
        while (e--)
        {
            int x , y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        for ( int i = 1 ; i <= v ; i++ )
        {
            dfs(i);
            cnt = 0;
        }
        cout << ans;
        cout << '\n';
    }
    return 0;
}