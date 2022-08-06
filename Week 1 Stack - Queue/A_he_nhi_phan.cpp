#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

int main ()
{
    fast
    test
    {
        long long n;
        cin >> n;
        stack<int> s;
        while (n > 0)
        {
            s.push(n % 2);
            n = n / 2;
        }
        while ( !s.empty() )
        {
            cout << s.top();
            s.pop();
        }
        cout << "\n";
    }
    return 0;
}