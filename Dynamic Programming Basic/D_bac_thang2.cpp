#include<bits/stdc++.h>
#define test int t; cin >> t; while(t--)
using namespace std;

int m = 1e9 + 7;

int main ()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   	test
   	{
   		int n, k;
   		cin >> n >> k;
   		long long dp[n + 5] = {};
   		dp[0] = 1;
   		dp[1] = 1;
   		for ( int i = 2; i <= n; i++ )
   		{
   			for ( int j = i - k; j < i; j++ )
			{
				if ( j < 0 ) continue;
			    dp[i] += dp[j];
			    dp[i] = dp[i] % m;
			}
		}
		cout << dp[n];
		cout << '\n';
	}
	return 0;
}