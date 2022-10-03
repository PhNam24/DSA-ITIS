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
    Node (int val)
    {
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

typedef Node* binTree;

void buidTree ( binTree root, int par, int child, char c )
{
    if ( root -> val == par )
    {
        if ( c == 'L' ) root -> left = new Node(child);
        else root -> right = new Node(child);
    }
    if ( root -> left )
        buidTree(root -> left, par, child, c);
    if ( root -> right )
        buidTree(root -> right, par, child, c);
}

void print ( binTree root )
{
    if ( root -> left ) print(root -> left);
    cout << root -> val << " ";
    if ( root -> right ) print(root -> right);
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
        int par, child;
        char c;
        cin >> par >> child >> c;
        root = new Node(par);
        buidTree(root, par, child, c);
        while(--n)
        {
            cin >> par >> child >> c;
            buidTree(root, par, child, c);
        }
        print (root);
        cout << endl;
    }
    return 0;
}