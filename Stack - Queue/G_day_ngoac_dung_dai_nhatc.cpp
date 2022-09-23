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
        stack<int> st;
        st.push(-1);
        int res = 0;
        for ( int i = 0 ; i < s.size() ; i++ )
        {
            if ( s[i] == '(' ) st.push(i);
            else 
            {
                st.pop();
                if ( !st.empty() ) res = max(res , i - st.top());
                else st.push(i);
            }
        }
        if ( res ) cout << res / 2;
        else cout << -1;
        cout << '\n';
    }
    return 0;
}