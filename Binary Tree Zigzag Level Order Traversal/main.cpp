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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> rs;
        if (!root) return rs;
        deque<TreeNode *> dq;
        bool reverse = false;
        dq.push_back(root);
        while (!dq.empty())
        {
            int count = dq.size();
            rs.push_back({});
            for (int i = 0; i < count; i++)
            {
                TreeNode *node = NULL;
                if (reverse)
                {
                    node = dq.front();
                    dq.pop_front();
                                        if (node->right)
                    {
                        dq.push_back(node->right);
                    }
                    if (node->left)
                    {
                        dq.push_back(node->left);
                    }

                }
                else
                {
                    node = dq.back();
                    dq.pop_back();
                    if (node->left)
                    {
                        dq.push_front(node->left);
                    }
                    if (node->right)
                    {
                        dq.push_front(node->right);
                    }
                }

                rs[rs.size() - 1].push_back(node->val);
                // if (node->left) {
                //     dq.push_back(node->left);
                // }
                // if(node->right) {
                //     dq.push_back(node->right);
                // }
            }

            reverse = !reverse;
        }

        return rs;
    }
};