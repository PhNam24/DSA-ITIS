#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    priority_queue<int , vector<int> , greater<int>> pq;
    int m , x;
    int b[100005] = {};
    test
    {
        cin >> m;
        if ( m == 1 )
        {
            cin >> x;
            b[x]++;
            pq.push(x);
        }
        /* if ( m == 2 )
        {
            cin >> x;
            priority_queue<int , vector<int> , greater<int>> pq1;
            pq1 = pq;
            pq = {};
            int check = 1;
            while (!pq1.empty())
            {
                if ( pq1.top() == x && check == 1 )
                {
                    check = 0;
                }
                else pq.push(pq1.top());
                pq1.pop();
            }
        } */
        if ( m == 2 )
        {
            cin >> x;
            b[x]--;
            if ( pq.top() == x ) pq.pop();
        }
        if ( m == 3 ) 
        {
            for ( int i = 0 ; i < 1e5 ; i++ )
            {
                if (b[i]) 
                {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}