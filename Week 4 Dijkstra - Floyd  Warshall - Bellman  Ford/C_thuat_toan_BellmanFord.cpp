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

vector<pair<int, int>> ke[105];
int dist[105];

int main()
{
    fast
        test
    {
        fill(dist, dist + 105, 1e9);
        for (int i = 1; i <= 105; i++)
            ke[i].clear();
        int v, e;
        cin >> v >> e;
        while (e--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            ke[x].push_back({y, z});
        }
        for (int k = 1; k < v; k++)
        {
            for (int i = 1; i <= v; i++)
            {

                for (auto j : ke[i])
                {
                    if (dist[j.first] > dist[i] + j.second)
                    {
                        dist[j.first] = dist[i] + j.second;
                    }
                }
            }
        }
        int check = 0;
        for (int i = 1; i <= v; i++)
        {

            for (auto j : ke[i])
            {
                if (dist[j.first] > dist[i] + j.second)
                {
                    cout << "YES";

                    check = 1;
                    break;
                }
            }
            if (check == 1)
                break;
        }
        if (check == 0)
            cout << "NO";
        cout << '\n';
    }
    return 0;
}