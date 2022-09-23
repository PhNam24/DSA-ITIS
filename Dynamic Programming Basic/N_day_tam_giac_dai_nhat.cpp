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
        int a[n], dp1[n], dp2[n];
        for ( int i = 0; i < n; i++ )
        {
            cin >> a[i];
            dp1[i] = dp2[i] = 1;
        }
        for ( int i = 1; i < n; i++ )
        {
            if ( a[i] > a[i-1] ) dp1[i]= dp1[i-1] + 1;
        }
        for ( int i = n - 1; i > 0; i-- )
        {
            if ( a[i] < a[i-1] ) dp2[i-1] = dp2[i] + 1;
        }
        int ans = -1;
        for ( int i = 0; i < n; i++ )
        {
           ans = max(ans, dp1[i] + dp2[i]);
        }
        cout << ans - 1;
        cout << '\n';
    }
	return 0;
}