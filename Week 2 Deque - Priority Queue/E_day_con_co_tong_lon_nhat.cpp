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
        deque<pair<int,int>> dq;
        int ans = -1e9;
        for ( int i = 0 ; i < n ; i++ )
        {
            int tmp = a[i];
            if (!dq.empty())
          {  while (!dq.empty() && i - dq.front().second > k) dq.pop_front();
            tmp = max(a[i] , a[i] + dq.front().first);
            while (!dq.empty() && tmp > dq.back().first) dq.pop_back();}
            ans = max (ans , tmp);
            dq.push_back({tmp , i});
        }
        cout << ans << '\n';
    }
    return 0;
}