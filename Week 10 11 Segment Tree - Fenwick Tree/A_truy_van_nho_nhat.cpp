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
	int mid = (l + r) >> 1;
	BuildTree (idx * 2, l, mid);
	BuildTree (idx * 2 + 1, mid + 1, r);
	st[idx] = min(st[2 * idx], st[idx * 2 + 1]);
}

int getMin (int idx, int l, int r, int L, int R)
{
	if ( l > R || r < L ) return 1e9 + 1;
	if ( L >= l && R <= r ) return st[idx];
	int mid = (L + R) >> 1;
	int minL = getMin(idx * 2, l, r, L, mid);
	int minR = getMin(idx * 2 + 1, l, r, mid + 1, R);
	return min(minL, minR);
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
		int l, r;
		cin >> l >> r;
		cout << getMin(1, l, r, 1, n);
		cout << endl;
	}
	return 0;
}
