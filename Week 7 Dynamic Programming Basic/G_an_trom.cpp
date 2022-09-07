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
        int a[n];
        int dp[n] = {};
        for ( int i = 0; i < n; i++ )
        {
            cin >> a[i];
        }
        dp[0] = a[0];
        dp[1] = max(a[0], a[1]);
        for ( int i = 2; i < n; i++ )
        {
            dp[i] = max(dp[i-1], dp[i-2] + a[i]);
        }
        cout << dp[n-1];
        cout << '\n';
    }
	return 0;
}