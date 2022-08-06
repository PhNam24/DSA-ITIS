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
        int vt[55];
        int d = 0;
        for ( int i = 0 ; i < s.size() ; i++ )
        {
            if ( s[i] == '(' )
            {
                vt[d++] = i + 1;
                st.push(s[i]);
            }
            else 
            {
                if ( !st.empty() )
                {
                    st.pop(); 
                    cout << vt[d-1] << " " << i + 1 << "\n";
                    d -= 1;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}