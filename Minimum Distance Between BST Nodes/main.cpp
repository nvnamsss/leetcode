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
    int ans;
    vector<int> nodes;
    TreeNode* prev;
    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        // doing here
        if (prev) {
            ans = min(ans, abs(prev->val - root->val));
        }
        prev = root;
        inorder(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        ans = INT32_MAX;
        inorder(root);
        return ans;
    }
};