#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

int root[10005] = {};
int Size[10005] = {};
int ans = -1;

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
        ans = 0;
        int v , e;
        cin >> v >> e;
        while (e--)
        {
            int x , y;
            cin >> x >> y;
            Union(x , y);
        }
        for ( int i = 1 ; i <= v ; i++ )
        {
            ans = max(ans , Size[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}