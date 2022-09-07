#include <bits/stdc++.h>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    test
    {
        int n, k;
        cin >> n >> k;
        int dp[n+5][k];
        int a; 
        dp[0][0] = 0;
        for(int i = 1; i < k; i++)
		{
			dp[0][i] = -1e9;
		} 
        for (int i = 1; i <= n; ++i)
        {
            cin >> a;
            a %= k;
            for (int j = 0; j < k; ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j + k - a) % k] + 1);
            }
        } 
        cout << dp[n][0];
        cout << endl;
    }
    return 0;
}