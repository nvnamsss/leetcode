/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
*/

class Solution {
    bool recursive(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) {
            return true;
        }

        if (!node1 || !node2) {
            return false;
        }

        bool left = recursive(node1->left, node2->right);
        bool right = recursive(node1->right, node2->left);
        return left && right && node1->val == node2->val;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return recursive(root->left, root->right);
    }
};