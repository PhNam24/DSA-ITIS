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
        vector<int> res;
        for ( int i = 0 ; i < n ; i++ )
        {
            cin >> a[i];
        }
        stack<int> st;
        int i = 0;
        for ( ; i < n ; i++ )
        { 
            if ( st.empty() || a[st.top()] <= a[i] )
            {
                st.push(i);
            }
            else 
            {
                int idx = st.top();
                st.pop();
                if ( st.empty() ) res.push_back(i * a[idx]);
                else res.push_back((i - st.top() - 1) * a[idx]);
                i--;
            }
        } 
        while (!st.empty())
        {
            int idx = st.top();
            st.pop();
            if ( st.empty() ) res.push_back(i * a[idx]);
            else res.push_back((i - st.top() - 1) * a[idx]);
        }
        sort(res.begin() , res.end());
        cout << res[res.size() - 1] << '\n';
    }
    return 0;
}