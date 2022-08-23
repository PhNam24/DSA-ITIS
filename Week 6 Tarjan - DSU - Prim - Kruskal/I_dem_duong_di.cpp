#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

struct DSU
{
    int Root[1005], Size[1005];
    
    DSU()
    {
        for(int i = 1; i <= 1000; ++i)
        {
            Root[i] = i;
            Size[i] = 1;
        }
    }
    
    int findRoot(int u)
    {
        if(u == Root[u])
            return u;
        return Root[u] = findRoot(Root[u]);
    }
    
    void Union(int x, int y)
    {
        int rootX = findRoot(x), rootY = findRoot(y);
        if(rootX != rootY)
        {
            if(Size[rootX] < Size[rootY])
                swap(rootX, rootY);
            Size[rootX] += Size[rootY];
            Root[rootY] = rootX;
        }
    }
};

int main ()
{
    fast
    int n , m;
    cin >> n >> m;
    DSU a[m+5];
    int mx = -1;
    while (m--)
    {
        int x , y , z;
        cin >> x >> y >> z;
        a[z].Union(x , y);
        mx = max(mx ,z);
    }
    test
    {
        int x , y;
        cin >> x >> y;
        int res = 0;
        for ( int i = 1 ; i <= mx ; i++ )
        {
            if ( a[i].findRoot(x) == a[i].findRoot(y) ) res++;
        }
        cout << res << '\n';
    }
    return 0;
}