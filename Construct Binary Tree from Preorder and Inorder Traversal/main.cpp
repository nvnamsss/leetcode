/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;

        TreeNode* root = new TreeNode(preorder[0]);
        int rootInorder = 0;

        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == preorder[0]) {
                rootInorder = i;
                break;
            }
        }

        vector<int> leftInorder = vector<int>(inorder.begin(), inorder.begin() + rootInorder);
        vector<int> leftPreorder = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + rootInorder);
        vector<int> rightInorder = vector<int>(inorder.begin() + rootInorder + 1, inorder.end());    
        vector<int> rightPreorder = vector<int>(preorder.begin() + rootInorder + 1, preorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};

int main() {
    Solution s;
    vector<int> preorder = vector<int>{3,9,20,15,7};
    vector<int> inorder = vector<int>{9,3,15,20,7};
    s.buildTree(preorder, inorder);
}