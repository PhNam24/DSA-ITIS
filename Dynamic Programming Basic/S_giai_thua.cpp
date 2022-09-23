#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int m = 1000033;
ll a[m + 5], b[m + 5];
ll Pow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = Pow(a, b / 2);
    tmp = (tmp * tmp) % m;
    if (b % 2 == 1)
        return (tmp * a) % m;
    return tmp;
}
ll Fermat(ll a)
{
    return Pow(a, m - 2);
}
void Set()
{
    a[0] = 1;
    b[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        a[i] = (a[i - 1] * i) % m;
        b[i] = (b[i - 1] * a[i]) % m;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Set();
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        if (r >= m)
            cout << 0;
        else
            cout << Pow(b[r] * Fermat(b[l - 1]), k);
        cout << "\n";
    }
}