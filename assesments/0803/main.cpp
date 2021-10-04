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
public:
    void recursive(TreeNode *node, int &v)
    {
        if (node == NULL)
            return;
        TreeNode *left = node->left;
        if (left != NULL && left->left == NULL && left->right == NULL)
            v = v + left->val;

        recursive(node->left, v);
        recursive(node->right, v);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        int rs = 0;
        recursive(root, rs);
        return rs;
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int dp1 = cost[0];
        int dp2 = cost[1];
        int dp = min(dp1, dp2);
        for (int i = 2; i < cost.size(); i++)
        {
            dp = min(dp1 + cost[i], dp2 + cost[i]);
            dp1 = dp2;
            dp2 = dp;
        }
        
        return min(dp1,dp2);
    }
};