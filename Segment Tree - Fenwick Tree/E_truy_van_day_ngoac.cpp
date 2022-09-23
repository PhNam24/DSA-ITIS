#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

string s;

struct node
{
	long long len, open, close;
	/*
		len : độ dài đoạn ngoặc đúng dài nhất trong node đang xét
		open : số dấu '(' sau khi xoá hết dãy ngoặc đúng có độ dài len trong đoạn
		close : số dấu ')' sau khi xoá hết dãy ngoặc đúng có độ dài len trong đoạn
	*/
}st[4000005];

node operator + (const node &left, node &right)
{
	node res;
	int tmp = min(left.open, right.close);
	res.len = left.len + right.len + tmp;
	res.open = left.open + right.open - tmp;
	res.close = left.close + right.close - tmp;
	return res; 
}

void buildTree (int idx, int l, int r)
{
	if ( l == r ) 
	{
		if ( s[l - 1] == '(' ) st[idx] = (node){0, 1, 0};
		else st[idx] = (node){0, 0, 1};
		return;
	}
	int mid = (l + r) / 2;
	buildTree(idx * 2, l, mid);
	buildTree(idx * 2 + 1, mid + 1, r);
	st[idx] = st[idx * 2] + st[idx * 2 + 1];
}

node getNode (int idx, int x, int y, int l, int r)
{
	if ( x > r || y < l ) return (node){0, 0, 0};
	if ( l >= x && r <= y ) return st[idx];
	int mid = ( l + r ) / 2;
	node left = getNode(idx * 2, x, y, l, mid);
	node right = getNode(idx * 2 + 1, x, y, mid + 1, r);
	return left + right;
}

int main ()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin >> s;
	s = '*' + s;
	buildTree(1, 1, s.size());
	int q;
	cin >> q;
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		node res = getNode(1, x + 1, y + 1, 1, s.size());
		cout << res.len * 2 << endl; 
	}
	return 0;
}
