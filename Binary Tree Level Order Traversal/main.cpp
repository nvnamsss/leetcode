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
    void recursive(vector<vector<int>>& result, TreeNode *node, int level) {
        if (!node) {
            return;
        }
        if (result.size() == level) {
            result.push_back(vector<int>{});
        }

        result[level].push_back(node->val);
        recursive(result, node->left, level + 1);
        recursive(result, node->right, level + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;;
        recursive(result, root, 0);
    }
};