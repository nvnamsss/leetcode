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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        queue<TreeNode*> q;
        vector<TreeNode*> ans;
        vector<int> deletes = vector<int>(1001, false);

        TreeNode* dummy = new TreeNode(0, root, NULL);
        q.push(dummy);
        for (int i = 0; i < to_delete.size(); i++)
        {
            deletes[to_delete[i]] = true;
        }
        deletes[0] = true;
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                    if (deletes[node->left->val]) {
                        node->left = NULL;
                    }           
                }

                if (node->right) {
                    q.push(node->right);
                    if (deletes[node->right->val]) {
                        node->right = NULL;
                    }
                }

                if (deletes[node->val]) {
                    if (node->left) {
                        ans.push_back(node->left);
                    }
                    if (node->right) {
                        ans.push_back(node->right);
                    }
                }
            }
            
        }

        return ans;
    }
};