/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:


Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 1000
*/

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
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(height(root->left), height(root->right)) + 1;
    }
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        int node = 1;
        int h = height(root);
        queue<TreeNode*> q;
        queue<TreeNode*> qNext;
        q.push(root);

        for (int i = 2; i < h; i++)
        {
            int count = q.size();
            for (int j = 0; j < count; j++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    qNext.push(node->left);
                }

                if (node->right) {
                    qNext.push(node->right);
                }
            }
            
            node *= 2;

            if (qNext.size() != node) {
                return false;
            }

            swap(q, qNext);
        }

        bool empty = false;
        while (!q.empty()) {
            TreeNode* node = q.front();
            if (!node->left && node->right) {
                return false;
            }

            if (empty && (node->left || node->right)) {
                return false;
            }

            empty = empty | (!node->left || node->right);
        }   
        
        return true;
    }
};