#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

int mod = 1e6 + 33;

long long pow( long long a, int b )
{
    long long res = 1;
    while(b--) res *= a;
    return res;
}

long long Pow(long long a, long long n)
{
    if(n == 1) return a;
    long long tmp = pow(a, n/2);
    return (n & 1) ? tmp * tmp * a : tmp * tmp;
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long gt[100033], f[100033];
    gt[1] = 1;
    f[1] = 1;
    for ( long long i = 2; i < 100033; i++ ) (gt[i] = i * gt[i-1]) %= mod;
    for ( long long i = 2; i < 100033; i++ ) (f[i] = gt[i] * f[i-1]) %= mod;
    test
    {
        int l, r, k;
        cin >> l >> r >> k;
        if ( r >= mod ) cout << 0;
        else 
        {
            long long t = (f[r] % mod) * ((pow(f[l-1], mod - 2)) % mod);
        }
        cout << endl;
    }
    return 0;
}