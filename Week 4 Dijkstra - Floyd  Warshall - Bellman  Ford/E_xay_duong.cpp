#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<pair<int,int>> ke[105];
vector<pair<int,int>> ke1[105];
int dist[105];

void dijkstra ( int u , vector<pair<int,int>> a[105] )
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
        for ( int i = 0 ; i < 105 ; i++ ) ke[i].clear();
        fill(dist , dist + 105 , 1e9);
        while(m--)
        {
            int x , y , z;
            cin >> x >> y >> z;
            ke[x].push_back({y , z});
        }
        dijkstra(s , ke);
        int ans = dist[t];
        while(p--)
        {
            for ( int i = 0 ; i < 105 ; i++ ) ke1[i].clear();
            fill(dist , dist + 105 , 1e9);
            int x , y , z;
            cin >> x >> y >> z;
            for ( int i = 1 ; i <= n ; i++ )
            {
                for ( auto j : ke[i] )
                {
                    ke1[i].push_back(j);
                }
            }
            int check = 0;
            for ( int i = 0 ; i < ke1[x].size() ; i++ )
            {
                if (ke1[x][i].first == y) 
                {
                    ke1[x][i].second = z;
                    check++;
                }
            }
            if ( check == 0 )
            {
                ke1[x].push_back({y , z});
            }
            else check = 0;
            for ( int i = 0 ; i < ke1[y].size() ; i++ )
            {
                if (ke1[y][i].first == x)
                {
                    ke1[y][i].second = z;
                    check++;
                }
            }
            if ( check == 0 )
            {
                ke1[y].push_back({x , z});
            }
            dijkstra(s , ke1);
            ans = min(ans , dist[t]);
        }
        if (ans == 1e9) cout << -1; 
        else cout << ans;
        cout << '\n';
    }
    return 0;
}