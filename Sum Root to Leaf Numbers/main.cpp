#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int recursive(TreeNode *root, int v)
    {
        if (!root)
        {
            return 0;
        }
        if (!root->left && !root->right)
        {
            return v * 10 + root->val;
        }

        return recursive(root->left, v * 10 + root->val) + recursive(root->right, v * 10 + root->val);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        return recursive(root, 0);
    }
};