#include <bits/stdc++.h>
#define test  int t; cin >> t; while (t--)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n], dp[k + 5] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= a[j] && dp[i - a[j]] == 0)
            {
                dp[i] = 1;
                break;
            }
        }
    }
    if (dp[k]) cout << "Kent";  
    else cout << "Bent";
    cout << '\n';
    return 0;
}