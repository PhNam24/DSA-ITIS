#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    int n , k;
    cin >> n >> k;
    int ans = INT32_MIN;
    pair<int,int> a[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i].first >> a[i].second;
    }
    cout << ans;
    return 0;
}