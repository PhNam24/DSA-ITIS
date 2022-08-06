#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

long long tong ( long long a , long long b )
{
    long long sum = ( b - a ) * b;
    return sum;
}

int main ()
{
    fast
    int l ,r;
    cin >> l >> r;
    queue<string> q;
    vector<long long> res;
    long long ans = 0;
    q.push("1"); 
    q.push("2"); 
    res.push_back(1);
    res.push_back(2);
    while (1)
    {
        string tmp = q.front();
        q.pop();
        if (tmp.size() == 10 ) break;
        res.push_back(stoll(tmp + '1'));
        res.push_back(stoll(tmp + '2'));
        q.push(tmp + '1');
        q.push(tmp + '2');
    }
    //sort ( res.begin() , res.end() );
    int idxd , idxc;
    for ( int i = 0 ; i < res.size() ; i++ )
    {
        if ( res[i] >= l ) 
        {
            idxd = i;
            break;
        }
    }
    for ( int i = 0 ; i < res.size() ; i++ )
    {
        if ( res[i] >= r ) 
        {
            idxc = i;
            break;
        }
    }
    map<long long , long long> m;
    m.insert({1 , 1});
    for ( int i = 1 ; i < res.size() ; i++ )
    {
        if ( res[i] % 2 == 0 ) m[res[i]] = res[i];
        else m[res[i]] = tong(res[i-1] , res[i]);
    }
    if ( res[idxd] == res[idxc] ) ans = (r - l + 1) * res[idxc];
    else
    {
        for ( int i = idxd + 1 ; i < idxc ; i++ )
        {
            ans += m[res[i]];
        }
        if ( res[idxd] == l ) ans = ans + res[idxd];
        else ans = ans + ( res[idxd] - l + 1) * res[idxd];
        ans = ans + ( r - res[idxc-1] ) * res[idxc];
    }
    //cout << res[idxd] << " " << res[idxc] << '\n';
    cout << ans;
    return 0;
}