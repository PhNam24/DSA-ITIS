#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

int main ()
{
    fast
    test
    {
        int n , m;
        cin >> n >> m;
        int a[505][505];
        int d[505][505] = {};
        vector<pair<int,int>> v;queue<pair<int,int>> q;
        for ( int i = 0 ; i < n ; i++ )
        {
            for ( int j = 0 ; j < m ; j++ )
            {
                cin >> a[i][j];
                if (a[i][j] == 1) q.push({i , j});
            }
        }
        int I[4] = { -1 , 0 , 0 , 1 };
        int J[4] = { 0 , -1 , 1 , 0 };
        while(!q.empty())
        {
            pair<int,int> tmp = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; i++ )
            {
                int i1 = tmp.first + I[i];
                int j1 = tmp.second + J[i];
                if ( i1 >= 0 && i1 < n && j1 >= 0 && j1 <= m && a[i1][j1] == 0 )
                {
                    d[i1][j1] = d[tmp.first][tmp.second] + 1;
                    q.push({i1 , j1});
                    a[i1][j1] = 1;
                }
            }
        }
        for ( int i = 0 ; i < n ; i++ )
        {
            for ( int j = 0 ; j < m ; j++ )
            {
                cout << d[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}