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
        int n, m;
        cin >> n >> m;
        int a[n + 5][m + 5], dp[n + 5][m + 5];
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= m; j++ )
            {
                cin >> a[i][j];
                dp[i][j] = 0;
            }
        }
        if ( a[1][1] == -1 ) cout << -1;
        else
        {
             dp[1][1] = a[1][1];
            for ( int i = 2; i <= m; i++ )
            {
                if ( a[1][i] == -1 )
                {
                    while(i <= m)
                    {
                        dp[1][i++] = -1e9;
                    }
                }
                else dp[1][i] = dp[1][i-1] + a[1][i];
            }
            for ( int i = 2; i <= n; i++ )
            {
                if ( a[i][1] == -1 )
                {
                    while(i <= n)
                    {
                        dp[i++][1] = -1e9;
                    }
                }
                else dp[i][1] = dp[i-1][1] + a[i][1];
            }
            for( int i = 2; i <= n; i++ )
            {
                for( int j = 2; j <= m; j++ )
                {
                    if(a[i][j] == -1) dp[i][j] = -1e9;
                    else if(dp[i-1][j] == -1e9 && dp[i][j-1] == -1e9) dp[i][j] = -1e9;
                        else dp[i][j] = max(dp[i-1][j] + a[i][j], dp[i][j-1] + a[i][j]);
                }
            }
            if (dp[n][m] >= 0) cout << dp[n][m];
            else cout << -1;
        }
        cout << '\n';
    }
    return 0;
}