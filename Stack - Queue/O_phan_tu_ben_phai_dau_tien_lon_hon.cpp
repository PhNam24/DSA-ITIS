#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    test
    {
        int n;
        cin >> n;
        int a[n];
        for ( int i = 0 ; i < n ; i++ )
        {
            cin  >> a[i];
        }
        stack<int> st;
        int res[n];
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( st.empty() ) st.push(i);
            else 
            {
                while ( !st.empty() && a[st.top()] < a[i] )
                {
                    res[st.top()] = a[i];
                    st.pop();
                }   
                st.push(i);
            }
        }
        while (!st.empty())
        {
            res[st.top()] = -1;
            st.pop();
        } 
        for ( int i : res ) cout << i <<  " ";
        cout << '\n';
    }
    return 0;
}