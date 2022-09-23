#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

long long lazy[4000005] ={}, st[4000005] = {}, a[1000005];

void pushDown(int idx)
{
    st[idx * 2] += lazy[idx];
    st[idx * 2 + 1] += lazy[idx];
    lazy[idx * 2] += lazy[idx];
    lazy[idx * 2 + 1] += lazy[idx];
    lazy[idx] = 0;
}

void update (int idx, int l, int r, int lq, int rq)
{
    if (l > rq || r < lq)
        return;
    if (l >= lq && r <= rq)
    {
        st[idx]++;
        lazy[idx]++;
        return;
    }
    pushDown(idx);
    int mid = (l + r) / 2;
    update(idx * 2, l, mid, lq, rq);
    update(idx * 2 + 1, mid + 1, r, lq, rq);
}

void solve (int idx, int l, int r)
{
    if ( l == r )
    {
        cout << st[idx] % 2 << " "; 
        return;
    }
    pushDown(idx);
    int mid = (l + r) / 2;
    solve(idx * 2, l, mid);
    solve(idx * 2 + 1, mid + 1, r);
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        update(1, 1, n, x, y);
    }
    solve(1, 1, n);
    return 0;
}