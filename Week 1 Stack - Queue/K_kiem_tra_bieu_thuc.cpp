#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main ()
{
    fast
    string s;
    getline(cin , s);
    stack<char> st1 , st2;
    for ( int i = 0 ; i < s.size() ; i++ )
    {
        // if ( s[i] == '(' || s[i] == ')' )
        // {
        //     st1.push(s[i]);
        // }
        if ( !isdigit(s[i]) && s[i] != ' ' ) st2.push(s[i]);
    }
    // while (!st1.empty()) 
    // {
    //     cout << st1.top() << '\n';
    //     st1.pop();  
    // }
    int tmp = 0;
    while (!st2.empty()) 
    {
        if ( st2.top() == ')' ) tmp++;
        if ( st2.top() == '+' || st2.top() == '-' || st2.top() == '*' || st2.top() == '/' ) tmp--;
        st2.pop();  
    }
    return 0;
}