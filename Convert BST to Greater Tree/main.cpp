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
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        TreeNode* node = new TreeNode(root->val);
        node->right = convertBST(root->right);
        node->val += sum;
        sum += root->val;
        node->left = convertBST(root->left);
        return node;
    }
};