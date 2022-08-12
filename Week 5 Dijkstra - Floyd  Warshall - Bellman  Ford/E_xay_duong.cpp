#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<pair<int,int>> ke[105];
vector<pair<int,int>> ke1[105];
int distS[105];
int distT[105];

void dijkstra ( int u , vector<pair<int,int>> a[105] , int dist[105] )
{
    fill(dist , dist + 105 , 1e9);
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
    dist[u] = 0;
    pq.push({dist[u] , u});
    while (!pq.empty())
    {       
        pair<int,int> tmp = pq.top();
        pq.pop();
        if ( tmp.first <= dist[tmp.second] )
        {
            for ( auto i : a[tmp.second] )
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

int main ()
{
    fast
    test
    {
        int n , m , p , s , t;
        cin >> n >> m >> p >> s >> t;
        for ( int i = 0 ; i < 105 ; i++ ) 
        {
            ke[i].clear();
            ke1[i].clear();
        }
        while(m--)
        {
            int x , y , z;
            cin >> x >> y >> z;
            ke[x].push_back({y , z});
            ke1[y].push_back({x , z});
        }
        dijkstra(s , ke , distS);
        dijkstra(t , ke1 , distT);
        int ans = distS[t];
        while(p--)
        {
            int x , y , z;
            cin >> x >> y >> z;
            int w = min(distS[x] + distT[y] , distS[y] + distT[x]);
            ans = min(ans , w + z);
        }
        if (ans == 1e9) cout << -1; 
        else cout << ans;
        cout << '\n';
    }
    return 0;
}