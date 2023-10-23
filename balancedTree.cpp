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
node *inputtree()
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
        int left;
        cin >> left;
        if (left == -1)
        {
            p->left = NULL;
        }
        else
        {
            p->left = new node(left);
        }
        int right;
        cin >> right;
        if (right == -1)
        {
            p->right = NULL;
        }
        else
        {
            p->right = new node(right);
        }
    }
    return root;
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}
bool isBalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isBalanced(root->left) == false)
    {
        return false;
    }
    if (isBalanced(root->right) == false)
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    node *root = inputtree();
    if (isBalanced(root))
    {
        cout << "Yes";
    }
    else
    {
        cout << "NO";
    }
}