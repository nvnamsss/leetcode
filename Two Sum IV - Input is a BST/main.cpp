
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
    bool recursive(TreeNode* node, set<int>& set, int k) {
        if (!node) {
            return false;
        }
        if (set.find(k - node->val) != set.end()) {
            return true;
        }
        set.insert(node->val);
        return recursive(node->left, set, k) || recursive(node->right, set, k);
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        set<int> set;
        return recursive(root, set, k);
    }
};