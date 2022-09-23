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
        int cnt = 0;
        stack<char> st;
        if ( s[s.size() - 1] == '(' )
        {
             s[s.size() - 1] = ')';
             cnt++;
        }
        for ( int i = 0 ; i < s.size() ; i++ )
        {
            if ( st.empty() && s[i] == ')' ) 
            {
                s[i] = '(';
                cnt++;
            }
            if ( s[i] == '(' ) st.push(s[i]);
            else st.pop();
        }
        cout << cnt + st.size() / 2 << '\n';
    }
    return 0;
}