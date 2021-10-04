/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 8
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
    vector<TreeNode*> recursive(int l, int r) {
        if (l > r) return vector<TreeNode*>{};
        if (l == r) return vector<TreeNode*>{new TreeNode(l)};
        vector<TreeNode*> ans;

        for (int i = l; i <= r + 1; i++)
        {
            vector<TreeNode*> leftNodes = recursive(l, i - 1);
            vector<TreeNode*> rightNodes = recursive(i + 1, r);
            for (auto &&ln : leftNodes)
            {
                for (auto &&rn : rightNodes)
                {
                    TreeNode* root = new TreeNode(i, ln, rn);
                    ans.push_back(root);
                }
            }
                        
        }
        
        return ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return recursive(1, n);
    }
};