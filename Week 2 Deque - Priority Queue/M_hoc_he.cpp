#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

bool cmp ( pair<int,int> a , pair<int,int> b )
{
    if ( b.second != a.second ) return b.second > a.second;
     return b.first > a.first;
}

int main ()
{
    fast
    int n;
    cin >> n;
    int a[n] , b[n];
    vector<pair<int,int> > v;
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
    }
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> b[i];
    }
    for ( int i = 0 ; i < n ; i++ )
    {
        if (a[i] <= b[i]) v.push_back({a[i] , b[i]});
    }
    priority_queue<int , vector<int> , greater<int>> pq;
    sort(v.begin() , v.end() , cmp);
    int t = 0;
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        t += v[i].first;
        if ( t <= v[i].second ) pq.push(v[i].first);
        
    }
    cout << pq.size();
    return 0;
}