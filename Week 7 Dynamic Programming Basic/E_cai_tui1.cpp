#include<bits/stdc++.h>
#define test int t; cin >> t; while(t--)
using namespace std;

int m = 1e9 + 7;

int main ()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int,int>> v;
    v.push_back({0, 0});
   	test
   	{
   		int n, v;
   		cin >> n >> v;
   		int x[n], w[n];
   		for ( int i = 0; i < n; i++ )
		{
			cin >> w[i] >> x[i];
		}
		int dp[v + 5] = {};
		for ( int i = 0; i < n; i++ )
		{
			for ( int j = v; j >= w[i]; j-- )
			{
				dp[j] = max(dp[j], dp[j-w[i]] + x[i]);
			}
		}
		cout << dp[v];
		cout << '\n';
	}
	return 0;
}