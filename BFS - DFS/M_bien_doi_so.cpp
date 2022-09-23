#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

int bfs ( int u )
{
    unordered_map <int,int> m;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        if ( m[tmp-1] == 0 )
        {
            q.push(tmp-1);
            m[tmp-1] = m[tmp] + 1;
            if ( tmp-1 == 1 ) return m[1];
        }
        int sqr = sqrt(tmp);
        for ( int i = 2 ; i <= sqr ; i++ )
        {
            if ( tmp % i == 0 && m[tmp/i] == 0 )
            {
                q.push(tmp/i);
                m[tmp/i] = m[tmp] + 1; 
            }
        }
    }
    return -1;
}

int main ()
{
    fast
    test
    {
        int n;
        cin >> n;
        cout << bfs(n);
        cout << '\n';
    }
    return 0;
}