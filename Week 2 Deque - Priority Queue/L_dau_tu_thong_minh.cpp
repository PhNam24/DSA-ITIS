#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    int n , c , k;
    cin >> n >> c >> k;
    int a[n] , b[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
    }for ( int i = 0 ; i < n ; i++ )
    {
        cin >> b[i];
    }
    map<int , int> m;
    for ( int i = 0 ; i < n ; i++ )
    {
        m.insert({b[i] , a[i]});
    }
    for ( auto i : m )
    {
        cout << i.first << " " << i.second << '\n';
    }
    return 0;
}