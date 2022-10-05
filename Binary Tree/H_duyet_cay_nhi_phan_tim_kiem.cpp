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
    if ( !root )
    {
        root = new Node(val);
        return;
    } 
    if ( root -> val > val ) buildTree(root -> left, val);
    else buildTree(root -> right, val);
}

void print ( binTree root )
{
    if (root -> left) print(root -> left);
    if (root -> right) print(root -> right);
    cout << root -> val << " ";
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        binTree root = NULL;
        int n;
        cin >> n;
        int a[n];
        for ( int i = 0; i < n; i++ )
        {
            cin >> a[i];
        }
        for ( int i = 0; i < n; i++ )
        {
            buildTree(root, a[i]);
        }
        print(root);
        cout << endl;
    }
    return 0;
}