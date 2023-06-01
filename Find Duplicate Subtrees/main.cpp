/*
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.



Example 1:


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:


Input: root = [2,1,1]
Output: [[1]]
Example 3:


Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]


Constraints:

The number of the nodes in the tree will be in the range [1, 5000]
-200 <= Node.val <= 200
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
    int id;
    string recursive(unordered_map<string, int> &m, vector<TreeNode *> &ans, TreeNode *root)
    {
        if (!root)
        {
            return "nil";
        }

        string l = recursive(m, ans, root->left);
        string r = recursive(m, ans, root->right);

        string encode = to_string(root->val) + "-" + l + "-" + r;
        m[encode]++;
        if (m[encode] == 2)
        {
            ans.push_back(root);
        }

        return encode;
    }

    int recursive2(unordered_map<int, int> &m, unordered_map<string, int> &encodes, vector<TreeNode *> &ans, TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int l = recursive2(m, encodes, ans, root->left);
        int r = recursive2(m, encodes, ans, root->right);
        string encode = to_string(root->val) + "-" + to_string(l) + "-" + to_string(r);
        if (!encodes.count(encode))
        {
            encodes.insert({encode, encodes.size() + 1});
        }

        int id = encodes[encode];
        m[id]++;
        if (m[id] == 2)
        {
            ans.push_back(root);
        }

        return id;
    }

    vector<TreeNode *> encoding(TreeNode *root)
    {
        vector<TreeNode *> ans;
        unordered_map<string, int> m;

        recursive(m, ans, root);
        return ans;
    }

    vector<TreeNode *> encodingAndMapping(TreeNode *root)
    {
        vector<TreeNode *> ans;
        unordered_map<int, int> m;
        unordered_map<string, int> encodes;

        recursive2(m, encodes, ans, root);

        return ans;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        return encodingAndMapping(root);
    }
};