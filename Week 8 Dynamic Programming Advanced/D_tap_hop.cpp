#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

long long mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        long long n;
        cin >> n;
        long long dp[n + 5][n + 5];
        for ( int i = 0; i <= n; i++ )
        {
            for ( int j = 0; j <= n; j++ )
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for ( int i = 0; i <= n; i++ )
        {
            for ( int j = 0; j <= n; j++ )
            {
                (dp[i+1][j] += (j * dp[i][j]) % mod) %= mod;
                (dp[i+1][j+1] += dp[i][j] % mod) %= mod;
            }
        }
        long long ans = 0;
        for ( int i = 1; i <= n; i++ )
        {
            (ans += dp[n][i] % mod) %= mod;
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}