#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    int n , x , s;
    cin >> n >> x >> s;
    int a[n] , b[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
    }
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> b[i];
    }
    priority_queue<pair<int,int>> pq , pq1;
    for ( int i = 0 ; i < n ; i++ )
    {
        pq.push({b[i], a[i]});
    }
    if ( x >= s ) 
    {
        cout << 0;
        return 0;
    } 
    int cnt = 0 , t = 0;
    while (s--)
    {
        while (!pq.empty() && x < pq.top().second - t)
        {
            pq1.push(pq.top());
            pq.pop();
        }
        if ( !pq.size() )
        {
            cout << -1;
            return 0;
        }
        if (!pq.empty())
        {
            cnt++;
            x = x - (pq.top().second - t) + pq.top().first;
            s = s - (pq.top().second - t);
            if (x >= s)
            {
                cout << cnt;
                return 0;
            }
            t = pq.top().second;
            pq.pop();
        }
        while (!pq1.empty())
        {
            pq.push(pq1.top());
            pq1.pop();
        }
    }
    if ( cnt == 0 ) cout << -1;
    else cout << cnt;
    return 0;
}