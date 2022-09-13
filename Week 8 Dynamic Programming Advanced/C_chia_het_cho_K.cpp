#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
    	string n;
    	int k;
    	cin >> n >> k;
    	/*
    		BT : dp[i][r][rSum][rMul][state] : số lượng số có i chữ số mà chia k dư r, tổng chữ số chia k dư rSum, tích chữ số chia k dư rMul với state = {0, 1, 2}
    		=> KQ bài toán sum(i = 1 -> len - 1){dp[i][0][0][0][state = 0 -> 2]} + dp[len][0][0][0][state = 0 -> 1)
    		XĐ Công thức : 
    			+ i = 1
    				xđ state
    				d = 1 -> 9
    				dp[1][d % k][d % k][d % k][state]++
    			+ i > 1
    				i = 1 -> len - 1
    					r = 0 - > k - 1
    						rSum = 0 - > k - 1
    							rMul = 0 - > k - 1
    								state = 0 -> 2
    									d = 0 -> 9
    									newR = (r * 10 + d) % k
										newRSum = (rSum + đ) % k
										newRMul = (rMul * d) % k
										newState
										dp[i+1][newR][newRSum][newRMul][newState] += dp[i][r][rSum][rMul][state]
		*/
		if ( k > 81 ) cout << 0;
		else
		{
		    int dp[15][85][85][85][3] = {};
    		for ( int i = 1; i < 10; i++ )
    		{
    			int state;
    			if ( i < n[0] - '0' ) state = 0;
    			if ( i == n[0] - '0' ) state = 1;
    			if ( i > n[0] - '0') state = 2;
    			dp[1][i % k][i % k][i % k][state]++;
    		}
    		int l = n.length();
    		for ( int i = 1; i < l; i++ )
    		{
    			int tmp = n[i] - '0';
    			for ( int r = 0; r < k; r++ )
    			{
    				for ( int rSum = 0; rSum < k; rSum++ )
    				{
    					for ( int rMul = 0; rMul < k; rMul++ )
    					{
    						for ( int state = 0; state < 3; state++ )
    						{	
								if ( dp[i][r][rSum][rMul][state] == 0 ) continue;
    							for ( int d = 0; d < 10; d++ )
    							{	
    								int newState = state;
    								if ( state == 1 )
    								{
    									if ( d < tmp ) state = 0;
    									if ( d == tmp ) state = 1;
    									if ( d > tmp ) state = 2;
    								}
    								dp[i+1][(r * 10 + d) % k][(rSum + d) % k][(rMul * d) % k][newState] += dp[i][r][rSum][rMul][state];
    							}
    						}
    					}
    				}
    			}
    		}
    		int ans = dp[l][0][0][0][0] + dp[l][0][0][0][1];
    		for ( int i = 1; i < l; i++ )
    		{
    				ans += dp[i][0][0][0][0] + dp[i][0][0][0][1] + dp[i][0][0][0][2];
    		} 
    		cout << ans;
    		}
		cout << endl;
	}
    return 0;
}