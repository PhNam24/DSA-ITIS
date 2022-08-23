#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)

using namespace std;

vector<int> ke[105];
int visited[105] = {};
int num[105] = {};
int low[105] = {};
int cnt = 1 , ans = 0;
stack<int> st;

void Tarjan ( int u )
{
    st.push(u);
    visited[u] = 1;
    num[u] = low[u] = cnt++;
    if ( num[u] == 1e9 ) return; 
    for ( int i : ke[u] )
    {
        if ( visited[i] == 0 )
        {
            Tarjan(i);
            low[u] = min(low[u] , low[i]);
        }
        else low[u] = min(low[u] , num[i]);
    }
    if ( low[u] == num[u] )
    {
        ans++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            num[v] = 1e9;
        } while ( !st.empty() && v != u );
    }
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        for ( int i = 0 ; i < 105 ; i++ )
        {
            ke[i].clear();
            visited[i] = 0;
            num[i] = 0;
            low[i] = 0; 
        }
        cnt = 1;
        int v , e;
        cin >> v >> e;
        while(e--)
        {
            int x , y;
            cin >> x >> y;
            ke[x].push_back(y);
        }
        for ( int i = 1 ; i <= v ; i++ )
        {
            if (!visited[i]) Tarjan(i);
        }
        cout << ans << '\n';
        cout << '\n';
    }
    return 0;
}