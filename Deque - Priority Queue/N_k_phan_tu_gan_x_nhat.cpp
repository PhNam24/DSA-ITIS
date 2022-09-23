#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    int n , k , x;
    cin >> n >> k >> x;
    int a[n] , b[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
        b[i] = abs(a[i] - x);
    }
    priority_queue<pair<int,int>> pq;
    for ( int i = 0 ; i < k ; i++ )
    {
        pq.push({b[i], i});
    }
    for ( int i = k ; i < n ; i++ )
    {
        if ( b[i] < pq.top().first )
        {
            pq.pop();
            pq.push({b[i] , i});
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(a[pq.top().second]);
        pq.pop();
    }
    sort(ans.begin() , ans.end());
    for ( int i : ans ) cout << i << " ";
    return 0;
}