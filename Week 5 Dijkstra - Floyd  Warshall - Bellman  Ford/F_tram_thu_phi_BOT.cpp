    #include <bits/stdc++.h>
    #define test int t; cin >> t; while (t--)
    #define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    using namespace std;

    int n , m , k , s , t;
    vector<pair<int,int>> ke[1005];
    int dist[1005];
    int cnt[1005] = {};
    int ans = 1e9;

    int dijkstra (int u)
    {
    
        priority_queue<pair<int,int>> pq;
        dist[u] = 0;
        pq.push({0 , u});
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
                        cnt[i.first] = cnt[tmp.second] + 1;
                        pq.push({dist[i.first] , i.first});
                    } 
                    if ( i.first == t && cnt[i.first] <= k ) ans = min(ans, dist[t]);
                }
            }
        }
        if ( ans == 1e9 ) return -1;
        return ans;
    }

    int main ()
    {
        fast
        fill(dist , dist + 1005 , 1e9);
        cin >> n >> m >> k >> s >> t;
        while (m--)
        {
            int x , y , z;
            cin >> x >> y >> z;
            ke[x].push_back({y , z});
        }
        cout << dijkstra(s);
        return 0;
    }