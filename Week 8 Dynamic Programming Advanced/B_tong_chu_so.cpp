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
        long long a, b;
        cin >> a >> b;
        a--;
        string s, s1;
        s = to_string(a);
        s1 = to_string(b);
        /*
            dp[i][d][cnt][state] : số lượng số có i chữ số có cnt chữ số d
            state : 
                state = 0 khi số đang xét nhỏ hơn tiền tố độ dài i của N
                state = 1 khi số đang xét bằng tiền tố độ dài i của N
                state = 2 khi số đang xét lớn hơn tiền tố độ dài i của N
                ( tiền tố có độ dài i : i chữ số đầu tiên của N )
            => KQ bài toán : sumDig(R) - sumDig(l - 1) với sumDig(A) là tổng chữ số của các số từ 1 đến A
            => sumDig(A) = sum{i = 1 -> lenA} ((d = 1 -> 9) * dp[i][d][cnt = 0 -> len][state])
        */
        long long dp1[20][10][20][3] = {};
        long long dp2[20][10][20][3] = {};
        for ( int i = 1; i < 10; i++ )
        {
            int state1, state2;
            if ( i < s[0] - '0' ) state1 = 0;
            if ( i == s[0] - '0' ) state1 = 1;
            if ( i > s[0] - '0' ) state1 = 2;
            dp1[1][i][1][state1]++;
            if ( i < s1[0] - '0' ) state2 = 0;
            if ( i == s1[0] - '0' ) state2 = 1;
            if ( i > s1[0] - '0' ) state2 = 2;
            dp2[1][i][1][state2]++;
        }
        int l = s.size(), l1 = s1.size();
        int cnt1 = 0, cnt2 = 0;
        for ( int i = 1; i < l; i++ )
        {
            int tmp = s[i] - '0';
            for ( int d = 1; d < 10; d++ )
            {
                    for ( int state = 0; state < 3; state++ )
                    {
                        for ( int j = 0; j < 10; j++ )
                        {
                            /*
                                nếu state != 1 newState = state
                                nếu không:
                                    + newState = 1 khi d = tmp;
                                    + newState = 2 khi d > tmp;
                                    + newState = 0 khi d < tmp; 
                            */
                            int newState = state;
                            if ( state == 1 )
                            {
                                if ( j == tmp ) newState = 1;
                                if ( j > tmp ) newState = 2;
                                if ( j < tmp ) newState = 0;
                            }
                             dp1[i + 1][d][cnt1 + (j == d)][newState] += dp1[i][d][cnt1][state];
                        }
                    }
                
            }
        }
        for ( int i = 1; i < l1; i++ )
        {
            int tmp = s1[i] - '0';
            for ( int d = 1; d < 10; d++ )
            {
                    for ( int state = 0; state < 3; state++ )
                    {
                        for ( int j = 0; j < 10; j++ )
                        {
                            /*
                                nếu state != 1 newState = state
                                nếu không:
                                    + newState = 1 khi d = tmp;
                                    + newState = 2 khi d > tmp;
                                    + newState = 0 khi d < tmp; 
                            */
                            int newState = state;
                            if ( state == 1 )
                            {
                                if ( j == tmp ) newState = 1;
                                if ( j > tmp ) newState = 2;
                                if ( j < tmp ) newState = 0;
                            }
                             dp2[i + 1][d][cnt2 + (j == d)][newState] += dp2[i][d][cnt2][state];
                        }
                    }
                
            }
        }
        long long ans1 = 0, ans2 = 0;
        for ( int i = 1; i <= l; i++ )
        {
            for ( int d = 1; d < 10; d++ )
            {
                for ( int cnt = 0; cnt <= l; cnt++ )
                {
                    if ( i != l )
                    {
                        for ( int state = 0; i < 3; i++ )
                        {
                            ans1 += cnt * d * dp1[i][d][cnt][state];
                        }
                    }
                    else for ( int state = 0; i < 2; i++ )
                        {
                            ans1 += cnt * d * dp1[i][d][cnt][state];
                        }

                }
            }
        }
        for ( int i = 1; i <= 11; i++ )
        {
            for ( int d = 1; d < 10; d++ )
            {
                for ( int cnt = 0; cnt <= l1; cnt++ )
                {
                    if ( i != l1 )
                    {
                        for ( int state = 0; i < 3; i++ )
                        {
                            ans2 += cnt * d * dp2[i][d][cnt][state];
                        }
                    }
                    else for ( int state = 0; i < 2; i++ )
                        {
                            ans2 += cnt * d * dp2[i][d][cnt][state];
                        }

                }
            }
        }
        cout << ans1 - ans2;
        cout << endl;
    }
    return 0;
}