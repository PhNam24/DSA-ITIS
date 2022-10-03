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

void buidTree(binTree &root, int n)
{
    unordered_map<int, binTree> m;
    int par, child;
    char c;
    cin >> par >> child >> c;
    root = new Node(par);
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

void print(binTree root)
{
    queue<binTree> q;
    q.push(root);
    while (!q.empty())
    {
        binTree tmp = q.front();
        cout << tmp->val << " ";
        q.pop();
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    test
    {
        binTree root = NULL;
        int n;
        cin >> n;
        buidTree(root, n);
        print(root);
        cout << endl;
    }
    return 0;
}