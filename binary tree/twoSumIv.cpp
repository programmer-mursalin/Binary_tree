class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &ans)
    {
        // base case
        if (root == NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> ans;
        inorder(root, ans);

        int i = 0, j = ans.size() - 1;
        while (i < j)
        {
            int sum = ans[i] + ans[j];
            if (sum == k)
                return true;
            else if (sum > k)
                j--;
            else
                i++;
        }
        return false;
    }
};
