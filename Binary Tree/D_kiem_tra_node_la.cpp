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

void buildTree ( binTree &root, int n )
{
    int par, child;
    char c;
    cin >> par >> child >> c;
    root = new Node(par);
    unordered_map<int, binTree> m;
    m[par] = root;
    if (c == 'L')
    {
        m[par]->left = new Node(child);
        m[child] = m[par]->left;
    }
    else
    {
        m[par]->right = new Node(child);
        m[child] = m[par]->right;
    }
    while (--n)
    {
        cin >> par >> child >> c;
        if (c == 'L')
        {
            m[par]->left = new Node(child);
            m[child] = m[par]->left;
        }
        else
        {
            m[par]->right = new Node(child);
            m[child] = m[par]->right;
        }
    }
}

int check ( binTree root )
{
    int level[100005] = {};
    set<int> s;
    queue<binTree> q;
    q.push(root);
    while (!q.empty())
    {
        binTree tmp = q.front();
        q.pop();
        if (tmp->left)
        {
            q.push(tmp->left);
            level[tmp->left->val] = level[tmp->val] + 1;
        }
        if (tmp->right)
        {           
            q.push(tmp->right);
            level[tmp->right->val] = level[tmp->val] + 1;
        }
        if(tmp->right == NULL && tmp->left == NULL)
        {
            s.insert(level[tmp->val]);
            if(s.size() > 1) return 0;
        }
    }
    return 1;
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
        buildTree(root, n);
        cout << check(root);
        cout << endl;
    }
    return 0;
}