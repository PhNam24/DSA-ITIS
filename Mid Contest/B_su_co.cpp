#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        string s;
        int k;
        cin >> s >> k;
        deque<char> dq;
        for ( int i = 0; i < s.size(); i++ )
        {
            while(!dq.empty() && s[i] < dq.back() && k > 0)
            {
                dq.pop_back();
                k--;
            }
            dq.push_back(s[i]);
        }
        while(k--) dq.pop_back();
        string ans;
        while(!dq.empty())
        {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        int idx0 = 0;
        while(ans[idx0] == '0') idx0++;
        if ( idx0 == ans.size() ) cout << 0;
        else 
        {
            for ( int i = idx0; i < ans.size(); i++ ) 
            {
                cout << ans[i]; 
            }
        }
        cout << '\n';
    }
    return 0;
}