#include <bits/stdc++.h>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define endl '\n'

using namespace std;

long long lazy[4000005], st[4000005] = {}, a[1000005] = {};

void pushDown(int idx)
{
    st[idx * 2] += lazy[idx];
    st[idx * 2 + 1] += lazy[idx];
    lazy[idx * 2] += lazy[idx];
    lazy[idx * 2 + 1] += lazy[idx];
    lazy[idx] = 0;
}

void update(int idx, int l, int r, int lq, int rq, int val)
{
    if (l > rq or r < lq)
        return;
    if (l >= lq and r <= rq)
    {
        st[idx] += val;
        lazy[idx] += val;
        return;
    }
    pushDown(idx);
    int mid = (l + r) / 2;
    update(idx * 2, l, mid, lq, rq, val);
    update(idx * 2 + 1, mid + 1, r, lq, rq, val);
    st[idx] = max(st[idx * 2], st[idx * 2 + 1]);
}

long long getMax(int idx, int l, int r, int lm, int rm)
{
    if (l > rm || r < lm)
        return -1e9 - 1;
    if (lm >= l && rm <= r)
        return st[idx];
    int mid = (lm + rm) / 2;
    pushDown(idx);
    long long maxL = getMax(idx * 2, l, r, lm, mid);
    long long maxR = getMax(idx * 2 + 1, l, r, mid + 1, rm);
    return max(maxL, maxR);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int tv;
        cin >> tv;
        if (tv == 1)
        {
            int x, y, val;
            cin >> x >> y >> val;
            update(1, 1, n, x, y, val);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << getMax(1, x, y, 1, n) << endl;
        }
    }
    cout << endl;
    return 0;
}