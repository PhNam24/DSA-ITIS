#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)

using namespace std;

int root[65] = {};
int Size[65] = {};
long long ans = 0;

long long Pow ( int a , int b )
{
    long long res = 1;
    while(b--) res *= a;
    return res;
}

int findRoot ( int u )
{
    if ( root[u] == u ) return u;
    return root[u] = findRoot(root[u]);
}

void Union ( int x , int y )
{
    int rootX = findRoot(x) , rootY = findRoot(y);
    if ( rootX != rootY )
    {
        if ( Size[rootX] < Size[rootY] ) swap (Size[rootX] , Size[rootY]);
        root[rootY] = root[x];
        Size[rootX] += Size[rootY];
        Size[rootY] = 0;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        for ( int i = 0 ; i < 65 ; i++ )
        {
            root[i] = i;
            Size[i] = 1;
        }
        ans = 0;
        int n , m;
        cin >> n >> m;
        while(m--)
        {
            int x , y;
            cin >> x >> y;
            Union(x , y);
        }
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( Size[i] > 1 ) ans += Size[i] - 1;
        }
        cout << Pow(2 , ans);
        cout << '\n';
    }
    return 0;
}