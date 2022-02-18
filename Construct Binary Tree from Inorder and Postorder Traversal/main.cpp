/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0) return NULL;
        int ii = 0;
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == root->val) {
                ii = i;
                break;
            }
        }
        
        vector<int> inleft = vector<int>(inorder.begin(), inorder.begin() + ii);
        vector<int> inright = vector<int>(inorder.begin() + ii + 1, inorder.end());
        vector<int> postleft = vector<int>(postorder.begin(), postorder.begin() + ii);
        vector<int> postright = vector<int>(postorder.begin() + ii, postorder.end() - 1);
        root->left = buildTree(inleft, postleft);
        root->right = buildTree(inright, postright);

        return root;
    }
};

int main() {
    Solution s;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    s.buildTree(inorder, postorder);
}