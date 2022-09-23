#include <bits/stdc++.h>
#define test long long t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

long long st[4000005] = {}, a[1000000];

void BuildTree (long long idx, long long l, long long r)
{
	if ( l == r )
    {
        st[idx] += a[l];
        return;
    }
    long long mid = (l + r) / 2;
    BuildTree(idx * 2, l, mid);
    BuildTree(idx * 2 + 1, mid + 1, r);
    st[idx] = st[idx * 2] + st[idx * 2 + 1];
}

void update (long long idx, long long l, long long r, long long vitri, long long giatri)
{
    if ( vitri < l || vitri > r ) return;
    if ( l == r ) 
    {
        st[idx] += giatri;
        return;
    }
    long long mid = (l + r) / 2;
    update(idx* 2, l, mid, vitri, giatri);
    update(idx * 2 + 1, mid + 1, r, vitri, giatri);
    st[idx] = st[idx * 2] + st[idx * 2 + 1];
}

long long getSum (long long idx, long long l, long long r, long long lm, long long rm)
{
    if ( l > rm || r < lm ) return 0;
    if ( lm >= l && rm <= r ) return st[idx];
    long long mid = (lm + rm) / 2;
    long long sumL = getSum(idx * 2, l, r, lm, mid); 
    long long sumR = getSum(idx * 2 + 1, l, r, mid + 1, rm);
    return sumL + sumR;
}

int main ()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	long long n, q;
	cin >> n >> q;
	for ( long long i = 1; i <= n; i++ )
	{
		cin >> a[i];	
	}
	BuildTree(1, 1, n);
	while(q--)
    {
        long long tv, x, y;
        cin >> tv >> x >> y;
        if ( tv == 1 ) update(1, 1, n, x, y);
        else cout << getSum(1, x, y, 1, n) << endl;
    }
	return 0;
}