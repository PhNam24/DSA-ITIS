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
        string ans;
        stack<int> st;
        for ( int i = 0 ; i <= s.size() ; i++ )
        {
            st.push(i + 1);
            if ( i == s.size() || s[i] == 'T' )
            {
                while(!st.empty())
                {
                    ans.push_back(st.top() + '0');
                    st.pop();
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}