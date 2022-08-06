#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    test
    {
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
        queue<int> q;
        int check[105] = {};
        int cnt = 0;
        for ( int i = 1 ; i <= v ; i++ )
        {
            if(check[i] == 0) 
           { 
                cnt++;
                q.push(i);
                while (!q.empty())
                {
                    int tmp = q.front();
                    q.pop();
                    check[tmp] = 1;
                    for ( int i : ke[tmp] )
                    {
                        if ( check[i] == 0 )
                        {
                            q.push(i);
                        }
                        check[i] = 1;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}