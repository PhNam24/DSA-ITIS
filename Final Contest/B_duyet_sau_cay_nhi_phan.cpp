#include <bits/stdc++.h>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define endl '\n'
#define ll long long

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

typedef Node *binTree;

void buildTree(binTree &root, int n, int a[])
{
    queue<binTree> q;
    int idx = 1;
    root = new Node(a[0]);
    q.push(root);
    while(!q.empty())
    {
        binTree tmp = q.front();
        q.pop();
        if ( idx < n ) 
        {
            tmp -> left = new Node(a[idx]);
            q.push(tmp -> left);
            idx++;
        }
        if ( idx < n ) 
        {
            tmp -> right = new Node(a[idx]);
            q.push(tmp -> right);
            idx++;
        }
    }
}

void print(binTree root)
{
    if (root->left) print(root->left);
    if (root->right) print(root->right);
    if (root) cout << root->val << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    test
    {
        int n;
        cin >> n;
        int a[n];
        for (int &i : a) cin >> i;
        binTree root = NULL;
        buildTree(root, n, a);
        print(root);
        cout << endl;
    }
    return 0;
}