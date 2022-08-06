#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n , tong = 0;
vector<pair<int,int>> v;
int a[30];

void dq( int start = 0 , int sum =0 )
{
    if ( start == n ) return;
    v.push_back({sum , tong - sum});
    for ( int i = start ; i < n ; i++ )
    {
        dq( i + 1 , sum + a[i]);
    }
}

int main ()
{
    fast
    cin >> n;
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
        tong += a[i];
    }
    dq();
    int m = 1e9;
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        if ( m > abs(v[i].second - v[i].first) ) m = abs(v[i].second - v[i].first);
    }
    for ( pair<int,int> i : v )
    {
        if ( abs(i.second - i.first) == m ) 
        {
            if ( i.first > i.second ) cout << i.first << " " << i.second;
            else cout << i.second << " " << i.first;
            break;
        }
    }
    return 0;
}