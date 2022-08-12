#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

int M = 1e9 + 7;
vector<pair<long long,long long>> ke[1005];
long long dist[1005];
long long dp[1005] = {};

void dijkstra ( int u )
{
    priority_queue<pair<long long , long long> , vector<pair<long long,long long>> , greater<>> pq;
    dist[u] = 0;
    dp[1] = 1;
    pq.push({dist[u] , u});
    while (!pq.empty())
    {
        pair<long long,long long> tmp = pq.top();
        pq.pop();
        if ( tmp.first <= dist[tmp.second] )
        {
            for ( auto i : ke[tmp.second] )
            {
                if ( dist[i.first] > dist[tmp.second] + i.second )
                {
                    dist[i.first] = dist[tmp.second] + i.second;
                    dp[i.first] = dp[tmp.second];
                    pq.push({dist[i.first] , i.first});
                }
                else if ( dist[i.first] == dist[tmp.second] + i.second )
                     dp[i.first] = (dp[tmp.second] + dp[i.first]) % M; 
            }
        }
    }
}

int main ()
{
    fast
    int n , m;
    cin >> n >> m;
    while (m--)
    {
        long long x , y , z;
        cin >> x >> y >> z;
        ke[x].push_back({y , z});
        ke[y].push_back({x , z});
    }
    fill(dist , dist + 1005 , LONG_LONG_MAX);
    dijkstra(1);
    cout << dp[n];
    return 0;
}