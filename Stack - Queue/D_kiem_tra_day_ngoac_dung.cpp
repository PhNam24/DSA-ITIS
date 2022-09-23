#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;
int main ()
{
    fast
    test
    {
        string s;
        cin >> s;
        stack<char> st;
        int check = 1;
        for ( int i = 0 ; i < s.size() ; i++ )
        {
            if ( s[i] == '(' ) st.push(s[i]);
            else 
            {
                if ( !st.empty() ) st.pop();
                else 
                {
                    check = 0;
                    cout << "NO" << "\n";
                    break;
                }
            }
        }
        if ( check )
        {
            if ( st.empty() ) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
    return 0;
}