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
    vector<vector<int>> paths;
    void recursive(TreeNode *node, int target, vector<int> &path)
    {
        if (node == NULL) return;
        path.push_back(node->val);

        if (node->left == NULL && node->right == NULL && node->val == target) {
            paths.push_back(path);
        }

        recursive(node->left, target - node->val, path);
        recursive(node->right, target - node->val, path);

        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        paths = vector<vector<int>>{};
        vector<int> path = vector<int>{};
        recursive(root, targetSum, path);

        return paths;
    }
};

int main() {

}