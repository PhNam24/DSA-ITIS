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
        queue<string> q;
        vector<long long> res;
        q.push("4"); 
        res.push_back(4);
        while (1)
        {
            string tmp = q.front();
            q.pop();
            if (tmp.size() == n ) break;
            res.push_back(stoll(tmp + '4'));
            res.push_back(stoll(tmp + '7'));
            q.push(tmp + '4');
            q.push(tmp + '7');
        }
        q = {};
        q.push("7"); 
        res.push_back(7);
        while (1)
        {
            string tmp = q.front();
            q.pop();
            if (tmp.size() == n ) break;
            res.push_back(stoll(tmp + '4'));
            res.push_back(stoll(tmp + '7'));
            q.push(tmp + '4');
            q.push(tmp + '7');
        }
        sort ( res.begin() , res.end());
        cout << res.size() << '\n';
        for ( long long  i : res )
        {
                cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}