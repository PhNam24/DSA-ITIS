#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

bool cmp ( pair<int,int> a , pair<int,int> b )
{
  return a.first < b.second;
}

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
        int res[55] = {};
        int d1 = 1;
        vector<pair<int,int>> v;
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
                    v.push_back({vt[d-1] , i + 1});
                    d -= 1;
                }
            }
        }
        sort ( v.begin() , v.end() , cmp);
        if (v.size() == 0 ) cout << -1;
        else cout << v.size();
        cout << "\n";
    }
  return 0;
}