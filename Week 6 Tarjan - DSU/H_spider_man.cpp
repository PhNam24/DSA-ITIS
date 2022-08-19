#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)

using namespace std;

vector<pair<int,int>> v , tv;
vector<int> ans;
int root[100005] = {};
int Size[100005] = {};
int cnt;

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
        root[rootY] = rootX;
        Size[rootX] += Size[rootY];
        Size[rootY] = 0;
        cnt--;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    makeSet();
    int n , m;
    cin >> n >> m;
    cnt = n;
    while(m--)
    {
        int x , y;
        cin >> x >> y;
        v.push_back({x , y});
    }
    map<int , int> mp;
    test
    {
        int x;
        cin >> x;
        tv.push_back(v[x-1]);
        mp[x-1]++;
    } 
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        if ( mp[i] == 0 ) Union(v[i].first , v[i].second);
    }
    int cnt1 = cnt;
    for ( int i = tv.size() - 1 ; i >= 0 ; i-- )
    {
        Union(tv[i].first , tv[i].second);
        if ( cnt1 > cnt ) ans.push_back(cnt1);
        else ans.push_back(cnt);
        cnt1 = cnt;
    }
    for ( int i = ans.size() - 1 ; i >= 0 ; i-- ) cout << ans[i] << '\n';
    return 0;
}