#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        int x , y , p , q;
        cin >> x >> y >> p >> q;
        cout << max(abs(p - x), abs(q - y));
        cout << '\n';
    }
    return 0;
}