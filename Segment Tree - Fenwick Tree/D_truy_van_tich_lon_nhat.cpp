#include <bits/stdc++.h>
#define test long long t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

long long a[1000005];

struct node
{
	long long max1, max2, max3, min1, min2;
} st[4000005];

void updateMax (long long &max1, long long &max2, long long &max3, long long val)
{
	if ( val >= max1 )
	{
		max3 = max2;
		max2 = max1;
		max1 = val;
	}
	else 
	if ( val >= max2 )
	{
		max3 = max2;
		max2 = val;
	} 
	else if ( val >= max3 ) max3 = val;
}

void updateMin (long long &min1, long long &min2, long long val)
{
	if ( val <= min1 ) 
	{
		min2 = min1;
		min1 = val;
	}
	else if ( val <= min2 ) min2 = val;
}

void buildTree (long long idx, long long l, long long r)
{
	if (l == r) 
	{
		st[idx] = (node){a[l], (long long)-1e9, (long long)-1e9, a[l], (long long)1e9};
		return;
	}
	long long mid = (l + r) / 2;
	buildTree(idx * 2, l, mid);
	buildTree(idx * 2 + 1,mid + 1, r);
	node res = {(long long)-1e9, (long long)-1e9, (long long)-1e9, (long long)1e9, (long long)1e9};
	updateMax(res.max1, res.max2, res.max3, st[idx * 2].max1);
	updateMax(res.max1, res.max2, res.max3, st[idx * 2].max2);
	updateMax(res.max1, res.max2, res.max3, st[idx * 2].max3);
	updateMax(res.max1, res.max2, res.max3, st[idx * 2 + 1].max1);
	updateMax(res.max1, res.max2, res.max3, st[idx * 2 + 1].max2);
	updateMax(res.max1, res.max2, res.max3, st[idx * 2 + 1].max3);
	updateMin(res.min1, res.min2, st[idx * 2].min1);
	updateMin(res.min1, res.min2, st[idx * 2].min2);
	updateMin(res.min1, res.min2, st[idx * 2 + 1].min1);
	updateMin(res.min1, res.min2, st[idx * 2 + 1].min2);
	st[idx] = res;
}

void update(long long idx, long long L, long long R, long long i, long long val)
{
	if ( i < L or i > R ) return;
	if ( L == R and R == i ) 
	{
		st[idx] = (node) {val, (long long)-1e9, (long long)-1e9, val, (long long)1e9};
		return;
	}
	long long mid = (L + R) / 2;
	update(idx * 2, L, mid, i, val);
	update(idx * 2 + 1, mid + 1, R, i, val);
	node res = {(long long)-1e9, (long long)-1e9, (long long)-1e9, (long long)1e9, (long long)1e9};
	updateMax(res.max1, res.max2, res.max3, st[idx * 2].max1);
	updateMax(res.max1, res.max2, res.max3, st[idx * 2].max2);
	updateMax(res.max1, res.max2, res.max3, st[idx * 2].max3);
	updateMax(res.max1, res.max2, res.max3, st[idx * 2 + 1].max1);
	updateMax(res.max1, res.max2, res.max3, st[idx * 2 + 1].max2);
	updateMax(res.max1, res.max2, res.max3, st[idx * 2 + 1].max3);
	updateMin(res.min1, res.min2, st[idx * 2].min1);
	updateMin(res.min1, res.min2, st[idx * 2].min2);
	updateMin(res.min1, res.min2, st[idx * 2 + 1].min1);
	updateMin(res.min1, res.min2, st[idx * 2 + 1].min2);
	st[idx] = res;
}

node getNote(long long idx, long long l, long long r, long long lq, long long rq)
{
	if ( r < lq || l > rq ) return (node){(long long)-1e9, (long long)-1e9, (long long)-1e9, (long long)1e9, (long long)1e9};
	if ( lq <= l && rq >= r ) return st[idx];
	long long mid = (l + r) / 2;
	node left = getNote(idx * 2, l, mid, lq, rq);
	node right = getNote(idx * 2 + 1, mid + 1, r, lq, rq);
	node res = {(long long)-1e9, (long long)-1e9, (long long)-1e9, (long long)1e9, (long long)1e9};
	updateMax(res.max1, res.max2, res.max3, left.max1);
	updateMax(res.max1, res.max2, res.max3, left.max2);
	updateMax(res.max1, res.max2, res.max3, left.max3);
	updateMax(res.max1, res.max2, res.max3, right.max1);
	updateMax(res.max1, res.max2, res.max3, right.max2);
	updateMax(res.max1, res.max2, res.max3, right.max3);
	updateMin(res.min1, res.min2, left.min1);
	updateMin(res.min1, res.min2, left.min2);
	updateMin(res.min1, res.min2, right.min1);
	updateMin(res.min1, res.min2, right.min2);
	return res;
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
	buildTree(1, 1, n);
	while(q--)
	{
		long long tv, x, y;
		cin >> tv >> x >> y;
		if ( tv == 1 ) update(1, 1, n, x, y);
		else 
		{
			node res = getNote(1, 1, n , x, y);
			long long ans = max(res.max1 * res.max2 * res.max3, res.max1 * res.min1 * res.min2); 
			cout << ans << endl;
		}
	}
	return 0;
}


