// Kruskal

#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

vector<pair<int,pair<int,int>>> canh;
stack<pair<int,pair<int,int>>> st;

int root[105] = {};
int Size[105] = {};

void makeSet()
{
    for ( int i = 0 ; i < 105 ; i++ )
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

int Union ( int x , int y )
{
    int rX = findRoot(x) , rY = findRoot(y);
    if ( rX != rY )
    {
        if ( Size[rX] < Size[rY] ) swap(rX , rY);
        root[rY] = rX;
        Size[rX] += Size[rY];
        return 1;
    } 
    return 0;
}

int main ()
{
    fast
    test
    {
        makeSet();
        canh.clear();
        st = {};
        int v , e;
        cin >> v >> e;
        while (e--)
        {
            int x , y , z;
            cin >> x >> y >> z;
            canh.push_back({z , {x , y}});
        }
        int ans = 0;
        sort(canh.begin() , canh.end());
        for ( auto i : canh )
        {
            if ( Union(i.second.first , i.second.second) ) ans += i.first;
        } 
        cout << ans;
        cout << '\n';
    }
    return 0;
}

// Prim

#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

vector<pair<int,int>> ke[105];
int visited[105] = {};
int w[105] = {};
priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;

void Prim ( int u )
{
    w[u] = 0;
    pq.push({w[u] , u});
    while(!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        for ( auto i : ke[tmp.second] )
        {
            if ( i.second < w[i.first] && visited[i.first]   == 0 )
            {
                w[i.first] = i.second;
                pq.push({w[i.first] , i.first});
            }
        }
        visited[tmp.second] = 1;
    }
}

int main ()
{
    fast
    test
    {
        for ( int i = 0 ; i < 105 ; i++ )
        {
            ke[i].clear();
            visited[i] = 0;
            w[i] = 1e9;
        }
        int v , e;
        cin >> v >> e;
        while(e--)
        {
            int x , y , z;
            cin >> x >> y >> z;
            ke[x].push_back({y , z});
            ke[y].push_back({x , z});
        }
        Prim(1);
        int ans = 0;
        for ( int i = 1 ; i <= v ; i++ ) ans += w[i];
        cout << ans;
        cout << '\n';
    }
    return 0;
}