#include <bits/stdc++.h>
#define test      \
    int t;        \
    cin >> t;     \
    cin.ignore(); \
    while (t--)
#define endl '\n'
#define ll long long
#define node Node *

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void addFront(node &a, int val)
{
    if (a)
    {
        node tmp = new Node(val);
        tmp->next = a;
        a = tmp;
    }
    else
        a = new Node(val);
}

void addBack(node &list, int val)
{
    if (list)
    {
        node tmp = list;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = new Node(val);
    } 
    else list = new Node(val);
}

void print ( node list )
{
    while(list != NULL)
    {
        cout << list->val << " ";
        list = list -> next;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    node list = NULL;
    while (q--)
    {
        int tv;
        cin >> tv;
        if ( tv == 1 )
        {
            int x;
            cin >> x;
            addBack(list, x);
        }
        else 
        if ( tv == 2 ) 
        {
            int x;
            cin >> x;
            addFront(list, x);
        }
        else if ( tv == 3 ) if (list) print(list);
    }
    return 0;
}