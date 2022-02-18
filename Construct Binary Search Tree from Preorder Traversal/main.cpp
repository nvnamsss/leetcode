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
    TreeNode* recursive(vector<int>& preorder, int l, int r) {
        if (l > r) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[l]);
        int leftMax = l;
        for (int i = l + 1; i < preorder.size() && preorder[i] < preorder[l]; i++)
        {
            leftMax = i;
        }
        node->left = recursive(preorder, l + 1, leftMax);
        node->right = recursive(preorder, leftMax + 1, r);
        return node;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int k = 0;
        return recursive(preorder, 0, preorder.size() - 1);
    }
};