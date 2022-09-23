#include <bits/stdc++.h>
#define test long long t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

long long lazy[4000005] = {}, st[4000005] = {}, a[1000005] = {};

void buildTree (long long idx, long long l, long long r)
{
    if ( l == r ) 
    {
        st[idx] = a[l];
        return;
    }
    long long mid = (l + r) / 2;
    buildTree(idx * 2, l, mid);
    buildTree(idx * 2 + 1, mid + 1, r);
    st[idx] = st[idx * 2] + st[idx * 2 + 1];
}

void pushDown(long long  idx, int l, int r, int mid)
{
    st[idx * 2] += lazy[idx] * (mid - l + 1);
    st[idx * 2 + 1] += lazy[idx] * (r - mid);
    lazy[idx * 2] += lazy[idx];
    lazy[idx * 2 + 1] += lazy[idx];
    lazy[idx] = 0;
}

void update(long long  idx, long long  l, long long  r, long long  lq, long long  rq, long long  val)
{
    if (l > rq || r < lq) return;
    if ( l >= lq && r <= rq )
    {
        st[idx] += val * (r - l + 1);
        lazy[idx] += val;
        return;         
    }
    long long  mid = (l + r) / 2;
    pushDown(idx, l, r, mid);
    update(idx * 2, l, mid, lq, rq, val);
    update(idx * 2 + 1, mid + 1, r, lq, rq, val);
    st[idx] = st[idx * 2] + st[idx * 2 + 1];
}

long long getSum (long long idx, long long l, long long r, long long lq, long long rq)
{
    if ( lq > r || rq < l ) return 0;
    if ( l >= lq && r <= rq ) return st[idx];
    long long mid = (l + r) / 2;
    pushDown(idx, l, r, mid);
    long long sumL = getSum(idx * 2, l, mid, lq, rq);
    long long sumR = getSum(idx * 2 + 1, mid + 1, r, lq, rq); 
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
    buildTree(1, 1, n);
    while(q--)
    {
        long long tv;
        cin >> tv;
        if ( tv == 1 )
        {
            long long l, r, val;
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else 
        {
            long long l, r;
            cin >> l >> r;
            cout << getSum(1, 1, n, l, r) << endl;
        }
    }
    cout << endl;
    return 0;
}