#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

long long m = 1e9 + 7;

int main ()
{
    fast
    int n;
    cin >> n;
    int a[n]; 
    priority_queue <long long , vector<long long> , greater<long long>> pq;
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
        pq.push(a[i]);
    }
    long long ans = 0;        
    while ( pq.size() > 1)
    {
        long long res = 0;
        res = (res % m + pq.top() % m) % m;
        pq.pop();
        res = (res % m + pq.top() % m) % m;
        pq.pop();
        pq.push(res);
        ans = (ans % m + res % m) % m;
    }
    cout << ans;
    return 0;
}