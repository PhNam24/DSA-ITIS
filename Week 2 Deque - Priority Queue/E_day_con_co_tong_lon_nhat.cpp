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
        deque<int> dq;
        int sum = 0;
        int ans = -1e9;
        for ( int i = 0 ; i < n ; i++ )
        {
            dq.push_front(i);
            sum += a[i];
            while ( !dq.empty() && abs(i - dq.front()) <= k ) 
            {
                ans = max(ans , sum);
                dq.pop_back();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}