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
        q.push("9"); 
        res.push_back(9);
        while (1)
        {
            string tmp = q.front();
            q.pop();
            if (tmp.size() == 15 ) break;
            res.push_back(stoll(tmp + '0'));
            res.push_back(stoll(tmp + '9'));
            q.push(tmp + '0');
            q.push(tmp + '9');
        }
        for ( long long  i : res )
        {
            if ( i % n == 0 ) 
            {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}