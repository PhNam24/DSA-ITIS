#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

int main ()
{
	fast
	test
	{
		int v ,e;
		cin >> v >> e;
		vector <int> ke[v+5];
		// chuyen tu danh sach canh -> danh sach ke
		while(e--)
		{
			int x , y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		int u;
		cin >> u;
		queue<int> q;
		int check[105] = {};
		q.push(u);
		while (q.size())
		{
			u = q.front();
			q.pop();
			cout << u << " ";
			check[u] = 1;
			for ( int i : ke[u])
			{
				if ( check[i] == 0 ) 
				{
				    q.push(i);
				    check[i] = 1;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}