#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    int n , k;
    cin >> n >> k;
    int a[n + 5];
    for ( int i = 1 ; i <= n ; i++ )
    {
        cin >> a[i];
    }
    deque<int> dq;
    int dp[n+5] = {};
    dp[1] = a[1];
    dq.push_back(1);
    for ( int i = 2 ; i <= n ; i++ )
    {
        while (!dq.empty() && i - dq.front() > k) dq.pop_front();
        dp[i] = a[i] + dp[dq.front()];
        while (!dq.empty() && dp[i] > dp[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[n];
    return 0;
}