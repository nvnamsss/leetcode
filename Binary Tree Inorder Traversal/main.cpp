#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void recursive(vector<int>& rs, TreeNode* root) {
        if (!root) {
            return;
        }
        recursive(rs, root->left);
        rs.push_back(root->val);
        recursive(rs, root->right);
    }
    vector<int> inorderTraversalIteratively(TreeNode* root) {
        vector<int> rs = vector<int>{};
        stack<TreeNode*> s;
                s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (!node) {
                continue;
            }

            s.push(node->right);
            rs.push_back(node->val);
            s.push(node->left);
        }

        return rs;
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rs = vector<int>{};
        recursive(rs, root);
        // return inorderTraversalIteratively(root);
        return rs;
    }
};