#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

struct cmp
{
    bool operator()(const pair<int, int> a, const pair<int, int> b)
    {
        return (a.second < b.second);
    }
};

int main ()
{
    fast
    int n;
    cin >> n;
    int a[n] , b[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
    }
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> b[i];
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>>pq;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq1;
    for ( int i = 0 ; i < n ; i++ )
    {
        pq.push({b[i] , a[i]});
    }
    int t = 0;
    while (!pq.empty())
    {
        while (!pq.empty() && t + pq.top().second > pq.top().first) pq.pop();
        if ( pq.size() == 0 ) 
        {
            cout << pq1.size();
            return 0;
        }
        while (!pq.empty() && t + pq.top().second <= pq.top().first )
        {
            pq1.push(pq.top());
            t += pq.top().second;
            pq.pop();
        }
        while (!pq.empty() && t + pq.top().second > pq.top().first)
        {
            if (pq.top().second > pq1.top().second)
                pq.pop();
            else
            {
                t -= pq1.top().second;
                pq1.pop();
                t += pq.top().second;
                pq1.push(pq.top());
                pq.pop();
            }
        }
    }
    cout << pq1.size();
    return 0;
}