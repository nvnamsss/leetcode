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
    int recursive(TreeNode* root) {
        if (!root) return 0;

        int left = recursive(root->left);
        int right = recursive(root->right);
        int sum = max(max(left + root->val, right + root->val), root->val);
        ans = max(ans, max(sum, left + right + root->val));
        return sum;
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = INT32_MIN;
        recursive(root);
        return ans;
    }
};


int main() {

}