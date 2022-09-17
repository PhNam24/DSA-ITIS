#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int d = 1;
    test
    {
        int n;
        cin >> n;
        int a[n][n], dp[1 << n] = {};
        for ( int i = 0; i < n; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                cin >> a[i][j];
            }
        }   
        /* 
            dp[mask] : độ hạnh phúc lớn nhất tại trạng thái mask của các bạn nữ;
            => KQ : dp[(1 << n) - 1] : độ hp lớn nhất sau khi xét tất cả các bạn nữ
        */
        for ( int mask = 0; mask < (1 << n); mask++ )
        {
            int dem = 0;
            // số bạn nam đã có ngiu
            for ( int i = 0; i < n; i++ )
            {
                if ( (mask & (1 << i)) == 0 ) dem++;
            }
            for ( int i = 0; i < n; i++ )
            {
                if ( (mask & (1 << i)) == 0 ) dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + a[n - dem][i]);
            }
        }
        cout << "Case " << d++ << ": " << dp[(1 << n) - 1];
        cout << endl;
    }
    return 0;
}