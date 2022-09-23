#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;
int main ()
{
    fast
    int n;
    cin >> n;
    int m;
    stack<int> s;
    while (n--)
    {
        cin >> m;
        if ( m == 1 )
        {
            int x;
            cin >> x;
            s.push(x);
        }
        if ( m == 2 && !s.empty() ) s.pop();
        if ( m == 3 )
        {
            if ( s.empty() ) cout << "Empty!" << "\n";
            else cout << s.top() << "\n";
        }
    }
    return 0;
}