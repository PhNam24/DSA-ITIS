#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

struct diem
{
    int x , y;
};


int main ()
{
    fast
    int n , k;
    cin >> n >> k;
    diem a[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i].x >> a[i].y;
    }
    deque<diem> dq;
    int ans = INT32_MIN; 
    int tmp;    
    for ( int i = 0 ; i < n ; i++ )
    {
        dq.push_front(a[i]);
        while(!dq.empty() && abs(a[i].x - dq.front().x) <= k)
        {
            tmp = a[i].y + dq.front().y + abs(a[i].x - dq.front().x);
            ans = max (ans , tmp);
            dq.pop_front(); 
        }
    }
    cout << ans;
    return 0;
}