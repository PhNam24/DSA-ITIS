#include<bits/stdc++.h>
#define test int t; cin >> t; while(t--)
using namespace std;

int main ()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n], dp[n];
    for ( int i = 0; i < n; i++ )
    {
    	cin >> a[i];
    	dp[i] = 1;
	}
	int m = 0;
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < i; j++ )
		{
			if ( a[i] >= a[j] ) dp[i] = max(dp[i], dp[j] + 1);
		}
		m = max(m, dp[i]);
	}
	cout << n - m;
	return 0;
}