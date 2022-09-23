#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

long long lazy[400005] ={}, st[400005] = {}, a[100005];

void buildTree (int idx, int l, int r)
{
    if ( l == r )
    {
        st[idx] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    buildTree(idx * 2, l, mid);
    buildTree(idx * 2 + 1, mid + 1, r);
}

void pushDown(int idx, int l, int r, int mid)
{
    st[idx * 2] += lazy[idx] * (mid - l + 1);
    st[idx * 2 + 1] += lazy[idx] * (r - mid);
    lazy[idx * 2] += lazy[idx];
    lazy[idx * 2 + 1] += lazy[idx];
    lazy[idx] = 0;
}

void update(int idx, int l, int r, int lq, int rq, int val)
{
    if (l > rq || r < lq)
        return;
    if (l >= lq && r <= rq)
    {
        st[idx] += val * (r - l + 1);
        lazy[idx] += val;
        return;
    }
    int mid = (l + r) / 2;
    pushDown(idx, l, r, mid);
    update(idx * 2, l, mid, lq, rq, val);
    update(idx * 2 + 1, mid + 1, r, lq, rq, val);
}

void getIdx (int idx, int l, int r, int i)
{
    if ( i < l || i > r ) return;
    if ( l == r && r == i ) 
    {
        a[i] = st[idx];
        return;
    }
    int mid = (l + r) / 2;
    pushDown(idx, l, r, mid);
    getIdx(idx * 2, l, mid, i);
    getIdx(idx * 2 + 1, mid + 1, r, i);
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
    buildTree(1, 1, n);
    while(q--)
    {
        int tv;
        cin >> tv;
        if ( tv == 1 ) 
        {
            int l, r, val;
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else 
        {
            int i;
            cin >> i;
            getIdx(1, 1, n, i);
            cout << a[i] << endl;
        }
    }
    return 0;
}