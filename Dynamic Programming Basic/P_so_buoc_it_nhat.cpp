#include<bits/stdc++.h>
#define test int t; cin >> t; while(t--)
using namespace std;

int min ( int a, int b, int c )
{
    return min(min(a, b), c);
}
int main ()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   	test
   	{
   		string s , s1;
		cin >> s >> s1;
		int n = s.size(), m = s1.size();
		int dp[n + 1][m + 1];
		for ( int i = 0; i <= n ; i++ ) dp[i][0] = i;
		for ( int i = 0; i <= m ; i++ ) dp[0][i] = i;
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= m; j++ )
			{
				if ( s[i - 1] == s1[j - 1] ) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1);
			}
		}
		cout << dp[n][m];   
		cout << '\n';
	}
	return 0;
}