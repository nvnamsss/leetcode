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
    void recursive(TreeNode *root, int& cur, int& pre) {
        if (!root) return;
        int preLeft = 0;
        int curLeft = 0;
        int preRight = 0;
        int curRight = 0;
        recursive(root->left, curLeft, preLeft);
        recursive(root->right, curRight, preRight);
        
        pre = curLeft + curRight;
        cur = max(preLeft + preRight + root->val, curLeft + curRight);
    }
public:
    int rob(TreeNode *root)
    {
        if (!root) return 0;
        int cur = 0;
        int pre = 0;
        recursive(root, cur, pre);
        // int t = pre;
        // pre = cur;
        // cur = max(cur, t + root->val);

        return cur;
    }
};

int main() {
    Solution s;
    TreeNode* node = new TreeNode(3, new TreeNode(2, NULL, new TreeNode(3)), new TreeNode(3, NULL, new TreeNode(1)));
    s.rob(node);
}