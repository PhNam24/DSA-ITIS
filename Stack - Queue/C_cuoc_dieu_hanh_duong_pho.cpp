#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;
int main ()
{
    fast
    int n;
    test
    {
        cin >> n;
        int a[n] , b[n];
        int d = 0;
        for ( int i = 0 ; i < n ; i++ )
        {
            cin >> a[i];
        }
        stack<int> s;
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( a[i] > a[i+1] ) s.push(a[i]);
            else b[d++] = a[i];
        }
        while (!s.empty())
        {
            b[d++] = s.top();
            s.pop();
        }
        int check = 0;
        for ( int i = 1 ; i < d ; i++ )
        {
            if ( b[i] < b[i-1] ) 
            {
                check = 1;
                break;
            }
        }
        if ( check ) cout << "NO";
        else cout << "YES";
        cout << "\n";
    }
  return 0;
}