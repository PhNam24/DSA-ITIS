#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    long long d;
    cin >> n >> d;
    long long a[n + 5];
    a[1] = a[n] = 0;
    for ( int i = 2; i < n; i++ )
    {
        cin >> a[i];
    }
    int m = n;
    vector<pair<int,int>> v;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    long long w[205][205];
    for ( int i = 0; i < v.size(); i++ )
    {
        for ( int j = 0; j < v.size(); j++ )
        {
            long long tmp = (long long)(abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second)) * d;
            w[i + 1][j + 1] = tmp - a[j + 1];
        }
        w[i + 1][i + 1] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
    cout << w[1][n];
    return 0;
}