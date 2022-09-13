#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        string s;
        cin >> s;
        /*
            dp[i][r4][r7][state] : số lượng số có i chữ số mà số chữ số 4 chia cho 4 dư r4, số chữ số 7 chia cho 7 dư r7.
            state : 
                state = 0 khi số đang xét nhỏ hơn tiền tố độ dài i của N
                state = 1 khi số đang xét bằng tiền tố độ dài i của N
                state = 2 khi số đang xét lớn hơn tiền tố độ dài i của N
                ( tiền tố có độ dài i : i chữ số đầu tiên của N )
            => KQ bài toán : dp[len][0][0][1] + dp[len][0][0][1] + sum{i = 1 -> len - 1} (  dp[i][0][0][0 -> 2])
        */
        long long dp[20][4][7][3] = {};
        for ( int i = 1; i < 10; i++ )
        {
            int state;
            if ( i < s[0] - '0' ) state = 0;
            if ( i == s[0] - '0' ) state = 1;
            if ( i > s[0] - '0' ) state = 2;
            dp[1][i == 4][i == 7][state]++;
        }
        int l = s.length();
        for ( int i = 1; i < l; i++ )
        {
            int tmp = s[i] - '0';
            for ( int r4 = 0; r4 < 4; r4++ )
            {
                for ( int r7 = 0; r7 < 7; r7++ )
                {
                    for ( int state = 0; state < 3; state++ )
                    {
                        for ( int d = 0; d < 10; d++ )
                        {
                            /* 
                                newR4 = (r4 + (i == 4)) % 4
                                newr7 = (r7 + (i == 7)) % 7 
                                nếu state != 1 newState = state
                                nếu không:
                                    + newState = 1 khi d = tmp;
                                    + newState = 2 khi d > tmp;
                                    + newState = 0 khi d < tmp;
                            */
                            int newState = state;
                            if ( state == 1 )
                            {
                                if ( d == tmp ) newState = 1;
                                if ( d > tmp ) newState = 2;
                                if ( d < tmp ) newState = 0;
                            }
                           dp[i+1][(r4 + (d == 4)) % 4][(r7 + (d == 7)) % 7 ][newState] += dp[i][r4][r7][state];
                        } 
                    }
                }
            }
        }
        long long ans = 0;
        ans += dp[l][0][0][0] + dp[l][0][0][1];
        for ( int i = 0; i < l; i++ )
        {
            ans += (dp[i][0][0][0] + dp[i][0][0][1] + dp[i][0][0][2]);
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}