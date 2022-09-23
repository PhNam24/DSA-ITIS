#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)

using namespace std;

int mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        int n, m;
        cin >> n >> m;
        int a[n + 5][m + 5], dp[n + 5][m + 5];
        for ( int  i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= m; j++ )
            {
                cin >> a[i][j];
                dp[i][j] = 0;
            }
        }
        dp[1][1] = 1;
        for ( int  i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= m; j++ )
            {
                if ( a[i][j] == 0 )
                {
                    (dp[i+1][j] += dp[i][j]) %= mod;
                    (dp[i][j+1] += dp[i][j]) %= mod;
                }
            }
        }
        cout << dp[n][m];
        cout << '\n';
    }
    return 0;
}