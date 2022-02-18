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
    int ans = 0;
    void recursive(TreeNode* node, int v) {
        if (!node) {
            return;
        }

        v = v << 1;
        v = v + node->val;
        if (!node->left && !node->right){
            ans += v;
            return;
        }

        recursive(node->left, v);
        recursive(node->right, v);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        recursive(root, 0);
        return ans;
    }
    
};

int main() {
    Solution s;
    TreeNode* node = new TreeNode(1, 
    new TreeNode(0, new TreeNode(0), new TreeNode(1)), 
    new TreeNode(1, new TreeNode(0), new TreeNode(1)));
    cout << s.sumRootToLeaf(node) << endl;
}