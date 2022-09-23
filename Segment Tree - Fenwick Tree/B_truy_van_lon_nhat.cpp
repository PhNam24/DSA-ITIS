#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

int st[4000005] = {}, a[1000000];

void BuildTree (int idx, int l, int r)
{
	if ( l == r )
    {
        st[idx] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    BuildTree(idx * 2, l, mid);
    BuildTree(idx * 2 + 1, mid + 1, r);
    st[idx] = max(st[idx * 2], st[idx * 2 + 1]);
}

int getMax (int idx, int l, int r, int lm, int rm)
{
    if ( l > rm || r < lm ) return -1e9 - 1;
    if ( lm >= l && rm <= r ) return st[idx];
    int mid = (lm + rm) / 2;
    int maxL = getMax(idx * 2, l, r, lm, mid);
    int maxR = getMax(idx * 2 + 1, l, r, mid + 1, rm);
    return max(maxL, maxR);
}

void update (int idx, int l, int r, int vitri, int giatri)
{
    if ( vitri < l || vitri > r ) return;
    if ( l == r ) 
    {
        st[idx] = giatri;
        return;
    }
    int mid = (l + r) / 2;
    update(idx* 2, l, mid, vitri, giatri);
    update(idx * 2 + 1, mid + 1, r, vitri, giatri);
    st[idx] = max(st[idx * 2], st[idx * 2 + 1]);
}

int main ()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];	
	}
	BuildTree(1, 1, n);
	while(q--)
    {
        int tv, x, y;
        cin >> tv >> x >> y;
        if ( tv == 1 ) update(1, 1, n, x, y);
        else cout << getMax(1, x, y, 1, n) << endl;
    }
	return 0;
}
