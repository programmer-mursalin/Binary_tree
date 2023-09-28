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
void levelorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        cout << p->val << endl;
        if (p->left != NULL)
        {
            q.push(p->left);
        }
        if (p->right != NULL)
        {
            q.push(p->right);
        }
    }
}
void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
void preorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    node *root = input_tree();
    // levelorder(root);
    inorder(root);
    postorder(root);
    preorder(root);
}