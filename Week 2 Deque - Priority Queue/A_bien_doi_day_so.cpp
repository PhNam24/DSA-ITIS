#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;

int main ()
{
  fast
  int n;
  cin >> n;
  int a[n];
  vector<int> b;
  for ( int i = 0 ; i <n ; i++ )
  {
    cin >> a[i];
  }
  deque<int> dq;
  for ( int i = 0 ; i < n ; i++ )
  {
    if( i % 2 != 0 ) dq.push_back(a[i]);
    else dq.push_front(a[i]);
  }
  while(!dq.empty())
  {
    if ( n % 2 != 0 )
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    else 
    {
        cout << dq.back() << " ";
        dq.pop_back();
    }
  }
  return 0;
}