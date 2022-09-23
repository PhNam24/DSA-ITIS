#include <bits/stdc++.h>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)

using namespace std;

int root[10005] = {};
int Size[10005] = {};

int findRoot(int u)
{
    if (root[u] == u)
        return u;
    return root[u] = findRoot(root[u]);
}

void Union(int x, int y)
{
    int rootX = findRoot(x), rootY = findRoot(y);
    if (rootX != rootY)
    {
        if (Size[rootX] < Size[rootY])
            swap(Size[rootX], Size[rootY]);
        root[rootY] = root[x];
        Size[rootX] += Size[rootY];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 10005; i++)
    {
        root[i] = i;
        Size[i] = 1;
    }
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int tv, x, y;
        cin >> tv >> x >> y;
        if (tv == 1)
            Union(x, y);
        else
        {
            if (findRoot(x) == root[y] || findRoot(y) == root[x])
                cout << "YES";
            else
                cout << "NO";
            cout << '\n';
        }
    }
    return 0;
}