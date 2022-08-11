
#include <bits/stdc++.h>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
    fast int v, e;
    cin >> v >> e;
    int w[105][105];
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            w[i][j] = 1e9;
        }
        w[i][i] = 0;
    }
    while (e--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if ( x == y ) continue;
        w[x][y] = w[y][x] = z;
    }
    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
    test
    {
        int x, y;
        cin >> x >> y;
        if ( w[x][y] != 1e9 ) cout << w[x][y];
        else cout << -1;
        cout << '\n';
    }
    return 0;
}