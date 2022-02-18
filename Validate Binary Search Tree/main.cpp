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
    bool recursive(TreeNode* root, TreeNode* lower, TreeNode* upper) {
        if (!root) {
            return true;
        }

        if (lower && root->val <= lower->val) {
            return false;
        }
        if (upper && root->val >= upper->val) {
            return false;
        }

        return recursive(root->left, lower, root) && recursive(root->right, root, upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        return recursive(root, NULL, NULL);
    }
};