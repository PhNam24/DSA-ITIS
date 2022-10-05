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

int chieucao ( binTree root )
{
    if ( !root || (root -> left == NULL && root -> right == NULL) ) return 0;
    else 
    {
        return 1 + max(chieucao(root -> left), chieucao(root -> right));
    }
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
        while(n--)
        {
            int val;
            cin >> val;
            buildTree(root, val);
        }
        cout << chieucao(root);
        cout << endl;
    }
    return 0;
}