#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll Dig(string l)
{
    ll dp[20][15][20][3] = {};
    for(int d = 1; d <= 9; d++)
    {
        int x = l[0] - '0';
        int state;
        // state = 0
        if(d < x)
        {
            state = 0;
        }
        // state = 1
        else if(d == x)
        {
            state = 1;
        }
        // state = 2
        else
        {
            state  = 2;
        }
        dp[1][d][1][state]++;
        for(int num = 1; num <= 9; num++)
        {
            if(num != d)
            {
                ++dp[1][num][0][state];
            }
        }
    }
    ll n = l.size();
    int newState;
    for(int i = 1; i <= n; i++)
    {
        for(int d = 0; d <= 9; d++)
        {
            for(int cnt = 0; cnt <= i ; cnt++)
            {
                for(int state = 0; state < 3; state++)
                {
                    for(int j = 0; j <= 9; j++)
                    {
                        if(state == 1)
                        {
                            int x = l[i] - '0';
                            if(j < x) newState = 0;
                            else if(j == x) newState = 1;
                            else newState = 2;
                        }
                        else newState = state;
                        dp[i + 1][d][cnt + (j == d)][newState] += dp[i][d][cnt][state];
                    }
                }
            }
        }
    }
    ll tmpA = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int d = 1; d <= 9; d++)
        {
            for(int cnt = 1; cnt <= i; cnt++)
            {
                if(i < n)
                {
                    for(int state = 0; state < 3; state++)
                    {
                        tmpA += dp[i][d][cnt][state] * d * cnt;
                    }
                }
                else
                {
                    for(int state = 0; state < 2; state++)
                    {
                        tmpA += dp[n][d][cnt][state] * d * cnt;
                    }
                }
            }
        }
    }
    return tmpA;
}
int main()
{
    faster()
    test()
    {
        ll a, b; cin >> a >> b;
        a--;
        string l = to_string(a), r = to_string(b);
        // dp[i][d][cnt][state]: số lượng số có i chữ số mà có cnt chữ số d ứng với state = 0,1,2
        // + 0: khi số đó nhỏ hơn tiền tố độ dài i của N
	    // + 1: khi số đó bằng tiền tố độ dài i của N
	    // + 2: khi số đó lớn hơn tiền tố độ dài i của N
        
        cout <<  Dig(r) - Dig(l) << endl;
    }
    return 0;
}