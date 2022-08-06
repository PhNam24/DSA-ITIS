#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    test
    {
        string s , t;
        cin >> s >> t;
        pair<int,int> start , end;
        map<char,int> m;
        m.insert({'a',0});
        m.insert({'b',1});
        m.insert({'c',2});
        m.insert({'d',3});
        m.insert({'e',4});
        m.insert({'f',5});
        m.insert({'g',6});
        m.insert({'h',7});
        start.second = m[s[0]];
        start.first = s[1] - '0' - 1;
        end.second = m[t[0]];
        end.first = t[1] - '0' - 1;
        int a[10][10] = {} , d[100][100] = {};
        a[end.first][end.second] = 2;
        int I[8] = { -2 , -1 , 1 , 2 , 2 , 1 , -1 , -2 };
        int J[8] = { -1 , -2 , -2 , -1 , 1 , 2 , 2 , 1 };
        queue<pair<int,int>> q;
        q.push({start.first , start.second});
        int cnt = 0;
        //cout << start.first << " " << start.second << '\n' << end.first << " " << end.second << '\n';
        int check1 = 0;
        while(!q.empty())
        {
            pair<int,int> tmp = q.front();
            q.pop();
            a[tmp.first][tmp.second] = 1;
            for ( int i = 0 ; i < 8 ; i++ )
            {
                int i1 = tmp.first + I[i];
                int j1 = tmp.second + J[i];
                if ( i1 >= 0 && i1 < 8 && j1 >= 0 && j1 < 8 && a[i1][j1] != 1 )
                {
                    d[i1][j1] = d[tmp.first][tmp.second] + 1;
                    if (a[i1][j1] == 2) 
                    {
                        check1 = 1;
                        break;
                    }
                    q.push({i1 , j1});
                    a[i1][j1] = 1;
                }
            }
            if ( check1 == 1 ) break;
        }
        cout << d[end.first][end.second] << '\n';
    }
    return 0;
}