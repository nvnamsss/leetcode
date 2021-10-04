/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
    TreeNode* result;
    int count;
public:
    int recursive(TreeNode* node,TreeNode *p, TreeNode *q) {
        if (node == NULL) return 0;

        int l = recursive(node->left, p, q);
        int r = recursive(node->right, p, q);

        if (l == 1 && r == 1) {
            result = node;
            return 0;
        } 

        if (l + r == 1) {
            if (node->val == p->val || node->val == q->val) {
                result = node;
                return 0;
            }
            return 1;
        }

        if (node->val == p->val || node->val == q->val) {
            return 1;
        }

        return 0;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        count = 0;
        result = NULL;
        recursive(root, p, q);
        return result;
    }
};

TreeNode* example1() {
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node1 = new TreeNode(5);
    TreeNode* root = new TreeNode(3);
    node3->left = new TreeNode(7);
    node3->right = new TreeNode(4);
    node2->left = new TreeNode(0);
    node2->right = new TreeNode(8);
    node1->left = new TreeNode(6);
    node1->right = node3;
    root->left = node1;
    root->right = node2;

    return root;    
}

int main() {
    Solution s;
    TreeNode* root = example1();
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);
    s.lowestCommonAncestor(root, p, q);
    return 0;
}

