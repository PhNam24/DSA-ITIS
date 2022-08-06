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
        long long kq , kq1 , kq2;
        stack<long long> st1;
        for ( int i = 0 ; i < res.size() ; i++ )
        {
        if (isdigit(res[i])) st1.push(res[i] - '0');
        else 
        {
            kq1 = st1.top();
            st1.pop();
            kq2 = st1.top();
            st1.pop();
            if ( res[i] == '+' ) kq = kq1 + kq2;
            if ( res[i] == '-' ) kq = kq2 - kq1;
            if ( res[i] == '*' ) kq = kq1 * kq2;
            st1.push(kq);
        }
        }
        cout << st1.top();
        cout << '\n';
  }
  return 0;
}