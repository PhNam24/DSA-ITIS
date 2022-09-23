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
        int n;
        cin >> n;
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
            dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
        }
        cout << dp[n - 1];
        cout << '\n';
    }
    return 0;
}