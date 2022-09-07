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
   		int n;
   		cin >> n;
   		long long dp[n + 5];
   		dp[1] = 1;
   		dp[2] = 2;
   		dp[3] = 4;
   		for ( int i = 4; i <= n; i++ )
   		{
   			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		
		}
		cout << dp[n];
		cout << '\n';
	}
	return 0;
}