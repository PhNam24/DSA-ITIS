#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'

using namespace std;

long long mod = 1e9 + 7;

long long Pow(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long c = Pow(a, b / 2);
    c = (c * c) % mod;
    if (b % 2)
        return (a * c) % mod;
    return c;
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        long long n, k;
        cin >> n >> k;
        long long a;
        long long total = 0;
        for ( int i = 1; i <= n; i++ ) 
        {
            cin >> a;
            total += a;
        }
        /*
            dp[i][j] : số cách xếp i bà mẹ vào j bàn
            => tổng số cách xếp các bà mẹ = sum{i = 1 -> k} ( dp[n][i] )
            => KQ bài toán tổng số cách xếp mẹ * con
        */
        long long dp[n + 5][k + 5];
        for ( int i = 0; i <= n; i++ )
        {
            for ( int j = 0; j <= k; j++ )
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for ( int i = 0; i <= n; i++ )
        {
            for ( int j = 0; j <= k; j++ )
            {
                // thêm 1 bà mẹ vào bàn có sẵn
                (dp[i + 1][j] += (j * dp[i][j]) % mod) %= mod;
                // thêm 1 bà mẹ vào bàn mới
                (dp[i + 1][j + 1] += ((k - j) * dp[i][j]) % mod) %= mod;
            }
        }
        long long ans = 0;
        for ( int i = 1; i <= k; i++ )
        {
            (ans += (Pow(k - i + 1, total) * dp[n][i]) % mod) %= mod;
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}