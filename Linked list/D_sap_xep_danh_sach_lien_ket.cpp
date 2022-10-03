#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'
#define ll long long
#define node Node*

using namespace std;

struct Node 
{
    int val;
    Node *next;
    Node ( int val )
    {
        this -> val = val;
        this -> next = NULL;
    }
};

void add (node &list, int val )
{
    if ( list )
    {
        node tmp = new Node(val);
        tmp -> next = list;
        list = tmp;
    }
    else list = new Node(val);
}

void sort( node &list )
{
    for ( node i = list; i != NULL; i = i -> next )
    {
        for ( node j = i -> next; j != NULL; j = j -> next )
        {
            if ( i -> val > j -> val ) swap(i -> val, j -> val);
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    node list = NULL;
    test
    {
        int x;
        cin >> x;
        add(list, x);
    }
    sort(list);
    while(list != NULL)
    {
        cout << list -> val << " ";
        list = list -> next;
    }
    return 0;
}