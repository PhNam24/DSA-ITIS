#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)

using namespace std;

int n , m;
int a[505][505];

int I[4] = { 0, -1, 0, 1 };
int J[4] = { -1, 0, 1, 0 };

struct cmp
{
    bool operator () (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.first > b.first;
    }
};

int bfs ()
{
    int visited[505][505] = {}; 
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , cmp > pq;
    pq.push({a[0][0], {0, 0}}); 
    visited[0][0] = 1;
    while(!pq.empty())
    {
        pair<int,pair<int,int>> tmp = pq.top();
        pq.pop();
        for ( int i = 0; i < 4; i++ )
        {
            int x = tmp.second.first + I[i];
            int y = tmp.second.second + J[i];
            if ( x == n - 1 && y == m - 1 ) return tmp.first + a[x][y];
            if ( x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == 0 )
            {
                visited[x][y] = 1;
                pq.push({tmp.first + a[x][y], {x, y}});
            }
        }
    }
    return -1;
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        cin >> n >> m;
        for ( int i = 0; i < n; i++ )
        {
            for ( int j = 0; j < m; j++ )
            {
                cin >> a[i][j];
            }
        }
        if ( n == m && n == 1) cout << a[0][0];
        else cout << bfs();
        cout << '\n';
    }
    return 0;
}