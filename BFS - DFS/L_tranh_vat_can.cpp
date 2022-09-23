#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    test
    {
        int n;
        cin >> n;
        char a[505][505];
        for ( int i = 0 ; i < n ; i++ )
        {
            for ( int j = 0 ; j < n ; j++ )
            {
                cin >> a[i][j];
            }
        }
        int x , y , u , v;
        cin >> x >> y >> u >> v;
        queue<pair<int,int>> q;
        int d[505][505] = {};
        q.push({x,y});
        int check = 0;
        while(!q.empty())
        {
            pair<int,int> tmp = q.front();
            q.pop();
            a[tmp.first][tmp.second] = '*';
            int i1 = tmp.first;
            int j1 = tmp.second ; 
            i1 = tmp.first + 1;
            while ( i1 < n && a[i1][j1] != '*' )
            {
                d[i1][j1] = d[tmp.first][tmp.second] + 1;
                if ( i1 == u && j1 == v ) 
                {
                    check = 1;
                    break;
                }
                a[i1][j1] = '*';
                q.push({i1 , j1});
                i1++;
            }
            i1 = tmp.first - 1;
            while ( i1 >= 0 && a[i1][j1] != '*' )
            {
                d[i1][j1] = d[tmp.first][tmp.second] + 1;
                if ( i1 == u && j1 == v ) 
                {
                    check = 1;
                    break;
                }
                a[i1][j1] = '*';
                q.push({i1 , j1});
                i1--;
            }
            i1 = tmp.first;
            j1 = tmp.second + 1;
            while ( j1 < n && a[i1][j1] != '*' )
            {
                d[i1][j1] = d[tmp.first][tmp.second] + 1;
                if ( i1 == u && j1 == v ) 
                {
                    check = 1;
                    break;
                }
                a[i1][j1] = '*';
                q.push({i1 , j1});
                j1++;
            }
            j1 = tmp.second - 1;
            while ( j1 >= 0 && a[i1][j1] != '*' )
            {
                d[i1][j1] = d[tmp.first][tmp.second] + 1;
                if ( i1 == u && j1 == v ) 
                {
                    check = 1;
                    break;
                }
                a[i1][j1] = '*';
                q.push({i1 , j1});
                j1--;
            }
            if ( check == 1 ) break;
        }
        if ( x == u && y == v ) cout << 0;
        else if (d[u][v] != 0) cout << d[u][v];
             else cout << -1;
        cout << '\n';
    }
    return 0;
}