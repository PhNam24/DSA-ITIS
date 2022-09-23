#include <bits/stdc++.h>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
    fast int n, s;
    cin >> n;
    int a[n];
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    long long ans = -1;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        dq.push_front(a[i]);
        sum += dq.front();
        if ( sum == s )
        {
            ans = max (ans , (long long)dq.size());
            sum -= dq.back();
            dq.pop_back();
        }   
        else while ( !dq.empty() && sum > s )
        {
            sum -= dq.back();
            dq.pop_back();
        }
        if ( sum == s )
        {
            ans = max (ans , (long long)dq.size());
            sum -= dq.back();
            dq.pop_back();
        }   
    }
    cout << ans;
    return 0;
}