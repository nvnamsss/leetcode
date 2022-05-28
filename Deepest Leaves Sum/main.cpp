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
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            int sum = 0;
            for (int i = 0; i < count; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            ans = sum;
        }

        return ans;
    }
};