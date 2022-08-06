#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    int n , c , k;
    cin >> n >> c >> k;
    int a[n] , b[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
    }for ( int i = 0 ; i < n ; i++ )
    {
        cin >> b[i];
    }
    priority_queue<pair<int,int>> pq;
    for ( int i = 0 ; i < n ; i++ )
    {
        pq.push({b[i] , a[i]});
    }
    priority_queue <pair<int,int>> pq1;
    while (k--)
    {
        while (!pq.empty() && c < pq.top().second)
        {
            pq1.push(pq.top());
            pq.pop();
        }
        if (!pq.empty())
        {
            c += pq.top().first;
            pq.pop();
        }
        while (!pq1.empty())
        {
            pq.push(pq1.top());
            pq1.pop();
        }
        if ( pq.size() == 0 ) break;
    }
    cout << c;
    return 0;
}