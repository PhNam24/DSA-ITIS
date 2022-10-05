#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'
#define ll long long

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node ( int val )
    {
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

typedef Node* binTree;

void buildTree ( binTree &root, int val )
{
    if (!root)
    {
        root = new Node(val);
        return;
    }
    if ( root -> val > val ) buildTree(root -> left, val);
    else buildTree(root -> right, val);
}

void print ( binTree root )
{
    cout << root -> val << " ";
    if ( root -> left ) print(root -> left);
    if ( root -> right ) print(root -> right);
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        int n;
        cin >> n;
        binTree root = NULL;
        while(n--)
        {
            int val;
            cin >> val;
            buildTree(root, val);
        }
        print(root);
        cout << endl;
    }
    return 0;
}