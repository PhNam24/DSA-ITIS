#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)

using namespace std;

double khoangcach(int a, int b, int c, int d)
{
    double res = sqrt((a - c) * (a - c) + (b - d) * (b - d));
    return res;
}

int root[1004], Size[1004];
 
void makeSet()
{
    for (int i = 0; i < 1004; i++)
    {
        root[i] = i;
        Size[i] = 1;
    }
}
 
int findRoot(int u)
{
    if (root[u] == u)
        return u;
    return root[u] = findRoot(root[u]);
}
 
int Union(int x, int y)
{
    int rX = findRoot(x), rY = findRoot(y);
    if (rX != rY)
    {
        if (Size[rX] < Size[rY])
            swap(rX, rY);
        root[rY] = rX;
        Size[rX] += Size[rY];
        return 1;
    }
    return 0;
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    makeSet();
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    vector<pair<double,pair<int,int>>> kc;
    while(n--)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            kc.push_back({khoangcach(v[i].first, v[i].second, v[j].first, v[j].second),{i + 1 , j + 1}});
        }
    }
    double ans = 0;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        for ( int i = 0 ; i < kc.size() ; i++ )
        {
            if ( kc[i].second.first == x && kc[i].second.second == y ) kc[i].first = 0;
        }
    }
    sort(kc.begin() , kc.end());
    for ( int i = 0 ; i < kc.size() ; i++ )
    {
        if ( Union( kc[i].second.first , kc[i].second.second) ) 
        {
            ans += kc[i].first;
        }
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}