#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    test
    {
        int n , k;
        cin >> n >> k;
        int a[n];
        for ( int i = 0 ; i < n ; i++ )
        {
            cin >> a[i];
        }
        int sum[n];
        sum[0] = a[0];
        for ( int i = 1 ; i < n ; i++ )
        {
            sum[i] = sum[i-1] + a[i];
        }
        deque<int> dq;
        int ans = 1e9;
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( sum[i] >= k ) ans = min(ans , i + 1);
            while ( !dq.empty() && sum[i] - sum[dq.front()] >= k )
            {
                ans = min (ans , i - dq.front());
                dq.pop_front();
            }
            while ( !dq.empty() && sum[i] < sum[dq.back()] )
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        if ( ans == 1e9 ) cout << -1;
        else cout << ans;
        cout << '\n';
    }
    return 0;
}