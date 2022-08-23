#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

int root[10005] = {};
int Size[10005] = {};
int ans;

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
        ans--;
    }
}

int main ()
{
    fast
    test
    {
        for ( int i = 0 ; i < 10005 ; i++ )
        {
            root[i] = i;
            Size[i] = 1;
        }
        int v , e;
        cin >> v >> e;
        ans = v;
        while (e--)
        {
            int x , y;
            cin >> x >> y;
            Union(x , y);
        }
        cout << ans << '\n';
    }
    return 0;
}