#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<pair<char, int>> st;
        int cnt = 0;
        int kq = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (!st.empty() && ((s[i] == ')' && st.top().first == '(') || (s[i] == '}' && st.top().first == '{')))
            {
                st.pop();
                if (!st.empty())
                    kq = max(kq, cnt - st.top().second);
                else
                    kq = cnt;
            }
            else
            {
                if (s[i] == '{')
                    cnt++;
                st.push({s[i], cnt});
            }
        }
        cout<<kq<<"\n";
    }

    return 0;
}
