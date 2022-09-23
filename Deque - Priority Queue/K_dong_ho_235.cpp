#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    vector<long long> v;
    priority_queue<long long , vector<long long> , greater<long long>> q , pq;
    map<long long , int> m; 
    q.push(2);
    q.push(3);
    q.push(5);
    pq.push(2);
    pq.push(3);
    pq.push(5);
    while(1)
    {
        long long tmp = q.top();
        q.pop();
        if ( m[2 * tmp] == 0 )
        {
            q.push(2 * tmp);
            pq.push(2 * tmp);
            m[2 * tmp]++;
        }
        if ( m[3 * tmp] == 0 )
        {
            q.push(3 * tmp);
            pq.push(3 * tmp);
            m[3 * tmp]++;
        }
        if ( m[5 * tmp] == 0 )
        {
            q.push(5 * tmp);
            pq.push(5 * tmp);
            m[5 * tmp]++;
        }
        if (pq.size() == 5500) break;
    }
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    test
    {
        int n;
        cin >> n;
        cout << v[n-1] << '\n';
    }
    return 0;
}