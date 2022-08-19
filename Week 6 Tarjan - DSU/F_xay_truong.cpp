#include <bits/stdc++.h>
#define test long long t; cin >> t; while (t--)

using namespace std;

long long root[10005] = {};
long long Size[10005] = {};
long long ans = 0;
vector<pair<long long,pair<long long,long long>>> v;

void makeSet ()
{
    for ( long long i = 0 ; i < 10005 ; i++ )
    {
        root[i] = i;
        Size[i] = 1;
    }
}

long long findRoot ( long long u )
{
    if ( root[u] == u ) return u;
    return root[u] = findRoot(root[u]);
}

void Union ( long long x , long long y , long long z )
{
    long long rootX = findRoot(x) , rootY = findRoot(y);
    if ( rootX != rootY )
    {
        if ( Size[rootX] < Size[rootY] ) swap (rootX , rootY);
        root[rootY] = rootX;
        Size[rootX] += Size[rootY];
        Size[rootY] = 0;
        ans += z;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    makeSet();
    long long n , m , c;
    cin >> n >> m >> c;
    while(m--)
    {
        long long x , y , z;
        cin >> x >> y >> z;
        if ( z < c )  v.push_back({z , {x , y}});
    }
    sort(v.begin() , v.end());
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        Union(v[i].second.first , v[i].second.second , v[i].first);
    }
    long long cnt = 0;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( findRoot(i) == i ) cnt++;
    }
    ans += cnt * c;
    cout << ans << " " << cnt;
    return 0;
}