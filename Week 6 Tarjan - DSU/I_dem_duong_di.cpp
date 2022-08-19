#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)

using namespace std;

int root[1005] = {};
int Size[1005] = {};


void makeSet ()
{
    for ( int i = 0 ; i < 100005 ; i++ )
    {
        root[i] = i;
        Size[i] = 1;
    }
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
    int n , m;
    cin >> n >> m;
    while (m--)
    {
        int x , y , z;
        cin >> x >> y >> z;
        
    }
    test
    {
        int a , b;
        cin >> a >> b;

        cout << '\n';
    }
    return 0;
}