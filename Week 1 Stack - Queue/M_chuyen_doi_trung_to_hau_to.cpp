#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

int ut ( char c )
{
    if ( c == '(' ) return 0;
    if ( c == '+' || c == '-' ) return 1;
    if ( c == '*' || c == '/' ) return 2;
    return 3;
}

int main ()
{
    fast
    test
    {
        string s;
        cin >> s;
        string res;
        stack<char> st;
        for ( int i = 0 ; i < s.size() ; i++ )
        {
        if (isdigit(s[i])) res.push_back(s[i]);
        else
        {
            if ( s[i] == '(' ) st.push(s[i]);
            else  if ( s[i] == ')' )
                {
                    while (st.top() != '(')
                    {
                        res.push_back(st.top());
                        st.pop();
                    }
                    st.pop();
                }
                else 
                {
                    while ( !st.empty() && ut(s[i]) <= ut(st.top()) )
                    {
                        res.push_back(st.top());
                        st.pop();
                    }
                    st.push(s[i]);
                }
        }
        }
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        cout << res;
        cout << '\n';
    }
  return 0;
}