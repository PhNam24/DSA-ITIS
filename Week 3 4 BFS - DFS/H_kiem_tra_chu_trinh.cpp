#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int bfsch ( int x , vector<int> a[105])
{
    int check[105] = {};
    int parent[105] = {};
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        check[tmp] = 1;
        for ( int i : a[tmp] )
        {
            if ( check[i] == 0 )
            {
                q.push(i);
                check[i] = 1;
                parent[i] = tmp;
            }
            else if ( i == x ) return 1;
        }
    }
    return 0;
}

int bfsvh ( int x , vector<int> a[105])
{
    int check[105] = {};
    int parent[105] = {};
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        check[tmp] = 1;
        for ( int i : a[tmp] )
        {
            if ( check[i] == 0 )
            {
                q.push(i);
                check[i] = 1;
                parent[i] = tmp;
            }
            else if ( i != parent[tmp] ) return 1;
        }
    }
    return 0;
}

int main ()
{
    fast
    test
    {
        int v , e;
        cin >> v >> e;
        vector<int> vh[105] , ch[105];
        while (e--)
        {
            int x , y;
            cin >> x >> y;
            vh[x].push_back(y);
            vh[y].push_back(x);
            ch[x].push_back(y);
        }
        int check = 0;
        for ( int i = 1 ; i <= v ; i++ )
        {
            if (bfsch(i , ch))
            {
                cout << 2;
                check = 1;
                break;
            }
        }
        if ( check == 0 )
        {
            for ( int i = 1 ; i <= v ; i++ )
            {
                if (bfsvh(i , vh))
                {
                    cout << 1;
                    check = 2;
                    break;
                }
            }
        }
        if (check == 0) cout << 0;
        cout << '\n';
    }
    return 0;
}