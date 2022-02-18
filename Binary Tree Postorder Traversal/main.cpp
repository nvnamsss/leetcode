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
    void recursive(vector<int> &rs, TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        recursive(rs, root->left);
        recursive(rs, root->right);
        rs.push_back(root->val);
    }
    vector<int> postorderTraversalIteratively(TreeNode *root)
    {
        vector<int> rs = vector<int>{};
        stack<TreeNode *> s;
        TreeNode* cur = root;
        s.push(root);

        while (true)
        {
            while (!cur)
            {
                s.push(cur);
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();

            if (s.empty()) {
                break;
            }
            s.pop();
            if (!s.empty() && cur == s.top()) {
                cur = cur->right;
            } else {
                rs.push_back(cur->val);
            }

        }

        return rs;
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> rs = vector<int>{};
        recursive(rs, root);
        // return postorderTraversalIteratively(root);
        return rs;
    }
};