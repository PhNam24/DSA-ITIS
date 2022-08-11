#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<pair<int,int>> ke[105];
int dist[105];

void dijkstra ( int u )
{
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
    dist[u] = 0;
    pq.push({dist[u] , u});
    while (!pq.empty())
    {
        pair<int,int> tmp = pq.top();
        pq.pop();
        if ( tmp.first <= dist[tmp.second] )
        {
            for ( auto i : ke[tmp.second] )
            {
                if ( dist[i.first] > dist[tmp.second] + i.second )
                {
                    dist[i.first] = dist[tmp.second] + i.second;
                    pq.push({dist[i.first] , i.first});
                }
            }
        }
    }
}

bool cmp ( pair<int,int> a , pair<int,int> b)
{
    if ( a.second != b.second ) return a.second < b.second;
    return a.first > b.first;
}   

int main ()
{
    fast
    int n , m , k;
    cin >> n >> m >> k;
    while(m--)
    {
        int x , y , z;
        cin >> x >> y >> z;
        ke[x].push_back({y , z});
        ke[y].push_back({x , z});
    }
    vector<pair<int,int>> ans; 
    for ( int i = 1 ; i <= n ; i++ )
    {
        fill(dist , dist + 105 , 1e9);
        dijkstra(i);
        int cnt = 0;
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( dist[j] <= k ) cnt++;
        }
        ans.push_back({i , cnt});
    }
    sort(ans.begin() , ans.end() , cmp);
    cout << ans[0].first;
    return 0;
}