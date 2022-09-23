/* #include<bits/stdc++.h>
using namespace std;
const int M=1e5+10,p=1e9+7;
int n,ans,mod=1e9+7,b[100] ={},a[100],mul[M];
int pr[M]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67},dp[81][1<<19];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	mul[0]=1;
	for(int i=1;i<=n;i++)mul[i]=(mul[i-1]<<1)%p;
	for(int i=1;i<=70;i++){
		if(a[i]){
			int x=i;
			for(int j=0;j<19;j++){
				while(x%pr[j]==0){
					x/=pr[j];
					b[i]^=(1<<j);
				}
			}
		}
	}
	dp[0][0]=1;
	int t=0;
	for(int i=1;i<=70;i++){
		if(a[i]){
			for(int j=0;j<(1<<19);j++){
				(dp[i][j^b[i]] += 1LL * dp[t][j] * mul[a[i] - 1] % p) %= p;
				(dp[i][j] += 1LL * dp[t][j] * mul[a[i] - 1] % p) %= p;
			}
			t=i;
		}
	}
	printf("%d",(dp[t][0]-1+p)%p);
	return 0;
}
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <time.h>
#include <algorithm>
#define mkp make_pair
#define inf 1000000000
#define MOD 1000000007
#define eps 1e-7

using namespace std;
typedef long long ll;

int n;
int mask[72];
ll f[2][72];
ll dp[2][1 << 20];

bool prime(int x)
{
	for (int i = 2; i*i <= x; i++)
		if (x%i == 0)
			return 0;
	return 1;
}

void init()
{
	for (int i = 0; i < 72; i++)
		f[0][i] = 1;
	int cnt = 0;
	for (int i = 2; i < 72; i++)
	{
		if (!prime(i))
			continue;
		for (int j = 1; j < 72; j++)
		{
			int x = j;
			while (x%i == 0)
			{
				x /= i;
				mask[j] ^= (1 << cnt);
			}
		}
		cnt++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	init();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		f[0][x] = f[1][x] = (f[0][x] + f[1][x]) % MOD;
	}
	dp[0][0] = 1;
	for (int i = 0; i <= 70; i++)
	{
		int nxt = (i + 1) % 2;
		int cur = i % 2;
		for (int msk = 0; msk < (1<<20); msk++)
		{
			dp[nxt][msk^mask[i]] = dp[nxt][msk^mask[i]] + dp[cur][msk] * f[1][i];
			dp[nxt][msk] = dp[nxt][msk] + dp[cur][msk] * f[0][i];
			if (dp[nxt][msk^mask[i]] >= MOD)
				dp[nxt][msk^mask[i]] %= MOD;
			if (dp[nxt][msk] >= MOD)
				dp[nxt][msk] %= MOD;
		}
		for (int msk = 0; msk < (1<<20); msk++)
			dp[cur][msk] = 0;
	}
	cout << (dp[1][0] - 1 + MOD)%MOD << endl;
}