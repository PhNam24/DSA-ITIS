#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for ( int i = 0; i < n; i++ )
        {
            cin >> a[i];
        }
        int dp[n] = {};
        dp[0] = 0;
        dp[1] = abs(a[0] - a[1]);
        for ( int i = 2; i < n; i++ )
        {
            dp[i] = dp[i-1] + abs(a[i] - a[i-1]);
            for ( int j = 2; j <= k; j++ )
            {
                if ( i - j >= 0 ) dp[i] = min(dp[i], dp[i-j] + abs(a[i] - a[i-j]));
            }
        }
        cout << dp[n - 1];
        cout << '\n';
    }
    return 0;
}