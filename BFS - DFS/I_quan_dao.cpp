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
        int a[n][m];
        for ( int i = 0 ; i < n ; i++ )
        {
            for ( int j = 0 ; j < m ; j++ )
            {
                cin >> a[i][j];
            }
        }
        int check[505][505] = {};
        int I[8] = { -1 , -1 , -1 , 0 , 0 , 1 , 1 , 1 };
        int J[8] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 };
        int cnt = 0;
        for ( int i = 0 ; i < n ; i++ )
        {
            for ( int j = 0 ; j < m ; j++ )
            {
                if(a[i][j] == 1)
                {
                    queue<pair<int,int>> q;
                    q.push({i , j});
                    cnt++;
                    a[i][j] = 0;
                    while(!q.empty())
                    {
                        pair<int,int> tmp = q.front();
                        q.pop();
                        for ( int k = 0 ; k < 8 ; k++ )
                        {
                            int i1 = tmp.first + I[k];
                            int j1 = tmp.second + J[k];
                            if ( i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == 1 )
                            {
                                q.push({i1 , j1});
                                a[i1][j1] = 0;
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}