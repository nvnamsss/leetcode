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
    int total = 0;
    int recursive(TreeNode* node) {
        if (!node) return 0;

        int sumLeft = recursive(node->left);
        int sumRight = recursive(node->right);
        total += abs(sumLeft - sumRight);
        return node->val + sumLeft + sumRight;
    }

public:
    int findTilt(TreeNode* root) {
        total = 0;
        recursive(root);        
        return total;
    }
};