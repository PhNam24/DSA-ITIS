#include<bits/stdc++.h>
#define test int t; cin >> t; while(t--)
using namespace std;

int m = 1e9 + 7;

int main ()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, v;
   	cin >> n >> v;
   	int x[n + 5], w[n + 5];  
   	int sum = 0;
  	for ( int i = 1; i <= n; i++ )
	{
		cin >> w[i] >> x[i];
		sum += x[i];
	}
	int dp[n+5][sum+5];
	for ( int i = 1; i <= sum; i++ )
	{
	    dp[0][i] = m;
	}	
	int ans = -1;
	dp[1][1] = 0;
	for ( int i = 1; i <= n; i++ )
	{
	    for ( int j = 0; j <= sum; j++ )
	    {
	        if ( x[i] <= j ) dp[i][j] = min(dp[i-1][j], dp[i-1][j-x[i]] + w[i]);
	        else dp[i][j] = dp[i-1][j];
	        if ( dp[i][j] <= v ) ans = max (ans, j);
	    }
	}
	cout << ans;
	return 0;
}