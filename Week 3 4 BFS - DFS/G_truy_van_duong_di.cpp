#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    int v , e;
    cin >> v >> e;
    vector<int> ke[v+5];
    while (e--)
    {
        int x , y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    test
    {
        int check[105] = {};
        int parent[105] = {};
        queue<int> q;
        int x , y;
        cin >> x >> y;
        q.push(x);
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            check[tmp] = 1;
            for ( int i : ke[tmp] )
            {
                if ( check[i] == 0 )
                {
                    check[i] = 1;
                    parent[i] = tmp;
                    q.push(i);
                }
            }
        }
        if ( check[y] == 0 ) cout << "NO";
        else cout << "YES";
        cout << '\n';
    }
    return 0;
}