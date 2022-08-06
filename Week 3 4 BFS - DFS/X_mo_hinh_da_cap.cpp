#include <bits/stdc++.h>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<int> ke[100006];
int visited[100006] = {};
long long val[100006] = {};
long long sum[100006] = {};

void dfs(int u)
{
    visited[u] = 1;
    for (int i : ke[u])
    {
        if (visited[i] == 0)
        {  
            dfs(i);
            val[u] += (val[i] + sum[i]);
        } 
        sum[u] = val[u] + 1;
    }
}

int main()
{
    fast int n;
    cin >> n;
    int a[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
        ke[a[i]].push_back(i + 2);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ke[i].size() == 0)
        val[i] = sum[i] = 1; 
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << val[i] << " ";
    }
    return 0;
}