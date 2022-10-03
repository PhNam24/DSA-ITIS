#include <bits/stdc++.h>
#define test  \
    int t;    \
    cin >> t; \
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

void addFront(node &list, int val)
{
    if (list)
    {
        node tmp = new Node(val);
        tmp->next = list;
        list = tmp;
    }
    else
        list = new Node(val);
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
    else
        list = new Node(val);
}

void delFront(node &list)
{
    if (list)
    {
        node tmp = list;
        list = tmp->next;
    }
}

void delBack(node &list)
{
    if (list)
    {

        if (list->next == NULL)
            list = NULL;
        else
        {
            node tmp = list;
            while (tmp->next->next)
            {
                tmp = tmp -> next;
            }
            tmp->next = NULL;
        }
    }
}

void print(node list)
{
    while (list != NULL)
    {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node list = NULL;
    test
    {
        int tv, val;
        cin >> tv;
        if (tv == 1)
        {
            cin >> val;
            addBack(list, val);
        }
        else if (tv == 2)
        {
            cin >> val;
            addFront(list, val);
        }
        else if (tv == 3)
        {
            delFront(list);
        }
        else if ( tv == 4 )
        {
            delBack(list);
        }
        else if (tv == 5)
        {
            if (list)
            {
                print(list);
            }
        }
    }
    return 0;
}