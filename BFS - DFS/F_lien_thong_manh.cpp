#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;



int bfs ( int x , vector<int> a[105] )
{
    int check[105] = {};
    queue<int> q;
    q.push(x);
    int cnt = 0;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        check[tmp] = 1; 
        cnt++;
        for ( int i : a[tmp] )
        {
            if ( check[i] == 0 )
            {
                q.push(i);
                check[i] = 1; 
            }
        }
    }
    return cnt;
}

int main ()
{
    fast
    test
    {
        int v , e;
        cin >> v >> e;
        vector<int> thuan[105] , nghich[105];
        while (e--)
        {
            int x , y;
            cin >> x >> y;
            thuan[x].push_back(y);
            nghich[y].push_back(x);
        }
        int ans1 = bfs(1 , thuan);
        int ans2 = bfs(1 , nghich);
        if ( ans1 != v ) cout << "NO";
        else if ( ans1 == ans2 ) cout << "YES";
             else cout << "NO";
        cout << '\n';
    }
    return 0;
}