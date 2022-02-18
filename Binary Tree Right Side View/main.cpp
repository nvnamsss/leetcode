/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> rs = vector<int>{};
        if (!root) return rs;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            bool done = false;
            for (int i = 0; i < count; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (!done)
                {
                    rs.push_back(node->val);
                    done = true;
                }

                if (node->right)
                {
                    q.push(node->right);
                }
                if (node->left)
                {
                    q.push(node->left);
                }
            }
        }
        return rs;
    }
};