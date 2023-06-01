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
    void dfs(vector<vector<int>>& result, TreeNode *node, int level) {
        if (!node) {
            return;
        }
        if (result.size() == level) {
            result.push_back(vector<int>{});
        }

        result[level].push_back(node->val);
        dfs(result, node->left, level + 1);
        dfs(result, node->right, level + 1);
    }
    
    vector<vector<int>> recursive(TreeNode* root) {
        vector<vector<int>> result;;
        dfs(result, root, 0);
        return result;
    }
    vector<vector<int>> iterative(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            int count = q.size();
            vector<int> sub;
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                sub.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(sub);
        }
        return ans;
    }
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        return iterative(root);
    }
};