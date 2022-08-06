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
		int x , y;
		vector <int> ke[v+5];
		// chuyen tu danh sach canh -> danh sach ke
		while(e--)
		{
			int x , y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		for ( int i = 0 ; i <= v ; i++ )
		{
		    sort(ke[i].begin() , ke[i].end());
		}
		queue<int> q;
		int check[105] = {};
		for ( int i = 1 ; i <= v ; i++ )
		{
		    if(!check[i]) q.push(i);
		    while(!q.empty())
		    {
		        int u = q.front();
		        q.pop();
		        
		            cout << u << " ";
		            check[u] = 1;
		            for ( int j : ke[u] )
		            {
		                if (check[j] == 0)
		                {
		                    
		                    q.push(j);
		                }
		                check[j] = 1;
		            }
		        
		    }
		}
		cout << '\n';
	}
	return 0;
}