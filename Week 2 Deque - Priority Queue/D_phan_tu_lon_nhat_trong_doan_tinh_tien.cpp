#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    int n , k;
    cin >> n >> k;
    int a[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
    } 
    vector<int> res;
    int m = -1e9;
    deque<int> dq; 
    for ( int i = 0 ; i < k ; i++ )
    {
        while ( !dq.empty() && a[i] > a[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    res.push_back(a[dq.front()]);
    for ( int i = k ; i < n ; i++ )
    {
        if ( dq.front() <= i - k ) dq.pop_front();
        while ( !dq.empty() && a[i] > a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        res.push_back(a[dq.front()]);
    }
    for ( int i : res ) cout << i <<  " ";
    return 0;
}