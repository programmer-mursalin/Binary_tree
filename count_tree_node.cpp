#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;
    node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
node *input_tree()
{
    int rootValue;
    cin >> rootValue;
    if (rootValue == -1)
    {
        return NULL;
    }
    node *root = new node(rootValue);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        int left, right;
        cin >> left;
        if (left == -1)
        {
            p->left = NULL;
        }
        else
        {
            p->left = new node(left);
            q.push(p->left);
        }
        cin >> right;
        if (right == -1)
        {
            p->right = NULL;
        }
        else
        {
            p->right = new node(right);
            q.push(p->right);
        }
    }
    return root;
}

int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = count(root->left);
    int r = count(root->right);
    return l + r + 1;
}
int main()
{
    node *root = input_tree();
    int re = count(root);
    cout << re << endl;
}