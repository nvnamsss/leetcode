/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.

*/

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
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    int countNodes(TreeNode *root, int leftDepth, int rightDepth)
    {
        if (!root)
            return 0;
        if (leftDepth == -1)
        {
            TreeNode *left = root->left;
            leftDepth = 0;
            while (left)
            {
                ++leftDepth;
                left = left->left;
            }
        }
        if (rightDepth == -1)
        {
            TreeNode *right = root->right;
            rightDepth = 0;
            while (right)
            {
                ++rightDepth;
                right = right->right;
            }
        }

        if (leftDepth == rightDepth)
            return (2 << leftDepth) - 1;

        return countNodes(root->left, leftDepth - 1, -1) + countNodes(root->right, -1, rightDepth - 1) + 1;
    }
};