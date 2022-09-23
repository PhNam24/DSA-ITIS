#include<bits/stdc++.h>
#define test int t; cin >> t; while(t--)
using namespace std;

int main ()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   	test
   	{
   		string s , s1;
		cin >> s;
		s1 = s;
		reverse(s1.begin(), s1.end());
		int n = s.size();
		int dp[n + 5][n + 5];
		for ( int i = 0; i <= n; i++ )
		{
			dp[i][0] = dp[0][i]= 0;
		}
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= n; j++ )
			{
				if ( s[i - 1] == s1[j -1] ) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << n - dp[n][n];
		cout << '\n';
	}
	return 0;
}