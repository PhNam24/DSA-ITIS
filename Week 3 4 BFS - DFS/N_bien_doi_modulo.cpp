#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int x , y , n;
long long a[100006];
int M = 1e5;

int bfs ( int u )
{
    int cnt[100006] = {};
    queue<long long> q;
    q.push(u);
    while (!q.empty())
    {
        long long tmp = q.front();
        q.pop();
        for ( int i = 0 ; i < n ; i++ )
        {
            if ((tmp * a[i]) % M == x) continue;
            if ( cnt[(tmp * a[i]) % M] == 0 ) 
            {
                q.push((tmp * a[i]) % M);
                cnt[(tmp * a[i]) % M] = cnt[tmp] + 1;
                if ((tmp * a[i]) % M == y) return cnt[y];
            }
        }
    }
    return -1;
}

int main ()
{
    fast
    cin >> x >> y >> n;
    for ( int i = 0 ; i < n ; i++ ) cin >> a[i]; 
    cout << bfs(x);
    return 0;
}