/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.



Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []


Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
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
    int findNode(TreeNode *node, TreeNode *target, vector<int> &ans, int k)
    {
        if (!node)
        {
            return -1;
        }

        if (node->val == target->val)
        {
            collectNode(node, ans, k);
            return 0;
        }

        int left = findNode(node->left, target, ans, k);
        int right = findNode(node->right, target, ans, k);

        if (left == -1 && right == -1)
        {
            return -1;
        }

        if (left != -1)
        {
            left++;
            if (k == left)
            {
                ans.push_back(node->val);
            }
            collectNode(node->right, ans, k - left - 1);
        }
        else
        {
            right++;
            if (k == right)
            {
                ans.push_back(node->val);
            }
            collectNode(node->left, ans, k - right - 1);
        }

        return max(left, right);
    }

    void collectNode(TreeNode *node, vector<int> &ans, int k)
    {
        if (!node || k < 0)
        {
            return;
        }

        if (k == 0)
        {
            ans.push_back(node->val);
            return;
        }

        collectNode(node->left, ans, k - 1);
        collectNode(node->right, ans, k - 1);
    }
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        findNode(root, target, ans, k);
        return ans;
    }
};