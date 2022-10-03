#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'
#define ll long long

using namespace std;

struct Node
{
    int val;
    Node * left;
    Node * right;
    Node ( int val )
    {
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

typedef  Node* binTree;

void buildTree( binTree &root, int n )  
{
    unordered_map<int, binTree> m;
    int par, child;
    char c;
    cin >> par >> child >> c;
    root = new Node(par);
    m[par] = root;
    if ( c == 'L' )
    {
        m[par] -> left = new Node(child);
        m[child] = m[par] -> left;
    }
    else 
    {
        m[par] -> right= new Node(child);
        m[child] = m[par] -> right;
    }
    while(--n)
    {
        cin >> par >> child >> c;
        if ( c == 'L' )
        {
            m[par] -> left = new Node(child);
            m[child] = m[par] -> left;
        }
        else 
        {
            m[par] -> right= new Node(child);
            m[child] = m[par] -> right;
        }
    }
}

int ans = 0;

int countOneChild ( binTree root )
{
    if (!root) return 0;
    if ( root -> left != NULL && root -> right == NULL || root -> right != NULL && root -> left == NULL ) 
        return 1 + countOneChild(root -> left) + countOneChild(root -> right);
    return countOneChild(root -> left) + countOneChild(root -> right);
}

int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    test
    {
        ans = 0;
        int n;
        cin >> n;
        binTree root = NULL;
        buildTree(root, n);
        if ( countOneChild(root) == 0 ) cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}