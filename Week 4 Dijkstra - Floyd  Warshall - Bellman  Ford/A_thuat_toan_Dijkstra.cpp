
#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

vector<pair<int,int>> ke[105]; 
int dist[105];

void dijkstra ( int u )
{
    dist[u] = 0;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
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

int main ()
{
    fast
    test
    {
        int v , e;
        cin >> v >> e;
        for ( int i = 1 ; i <= v ; i++ )
        {
            ke[i].clear();
        }
        fill(dist , dist + 105 , 1e9 );
        while (e--)
        {
            int x , y , z;
            cin >> x >> y >> z;
            ke[x].push_back({y , z});
            ke[y].push_back({x , z});
        }
        int u;
        cin >> u;
        dijkstra(u);
        for ( int i = 1 ; i <= v ; i++ )
        {
            if ( dist[i] == 1e9 ) dist[i] = -1;
        }
        for ( int i = 1 ; i <= v ; i++ )
        {
            cout << dist[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}