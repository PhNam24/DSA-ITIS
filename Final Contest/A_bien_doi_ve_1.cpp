#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'
#define ll long long

using namespace std;

int mod = 1e6 + 7;

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ll f[50005];
    f[0] = 1;
    f[1] = 1;
    f[2] = 1;
    f[3] = 2;
    for ( int i = 4; i < 50005; i++ )
    {
        (f[i] = f[i - 1] + f[i - 2]) %= mod;
    }
    test
    {
        int n;
        cin >> n;
        cout << f[n];
        cout << endl;
    }
    return 0;
}