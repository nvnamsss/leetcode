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
    TreeNode* spaceEffectiveRec(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& m, int& p, int l, int r) {
        if (l > r) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[p++]);
        root->left = spaceEffectiveRec(preorder, inorder, m, p, l, m[root->val] - 1);
        root->right = spaceEffectiveRec(preorder, inorder, m, p, m[root->val] + 1, r);
        return root;
    }
    TreeNode* spaceEffective(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        int p = 0;
        return spaceEffectiveRec(preorder, inorder, m, p, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeRecursive(vector<int>& preorder, vector<int>& inorder) {
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
        
        /*
        Preorder gives us the root nodes meanwhile inorder gives us the left nodes
        Let H(i) -> i is a hash function mapping from 
        Let pi denotes the index of root node in preorder and ri denotes the index of perspective node in inorder which is ri = H(pi) in another words
        we always have ri >= pi, thus inorder[pi:ri-1] will be left node and inorder[ri+1:] will be right node
        it works down recursively 
        */
        vector<int> leftInorder = vector<int>(inorder.begin(), inorder.begin() + rootInorder);
        vector<int> leftPreorder = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + rootInorder);
        vector<int> rightInorder = vector<int>(inorder.begin() + rootInorder + 1, inorder.end());    
        vector<int> rightPreorder = vector<int>(preorder.begin() + rootInorder + 1, preorder.end());
        root->left = buildTreeRecursive(leftPreorder, leftInorder);
        root->right = buildTreeRecursive(rightPreorder, rightInorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return spaceEffective(preorder, inorder);
    }
};

int main() {
    Solution s;
    vector<int> preorder = vector<int>{3,9,20,15,7};
    vector<int> inorder = vector<int>{9,3,15,20,7};
    s.buildTree(preorder, inorder);
}