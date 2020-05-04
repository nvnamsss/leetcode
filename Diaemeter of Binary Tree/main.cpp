#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int max;
    int goDeep(TreeNode *node)
    {
        if (node == NULL) return 0;
        int left = goDeep(node->left);
        int right = goDeep(node->right);

        if (max < left + right + 1) max = left + right + 1;

        if (left > right) return left + 1;

        return right + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        max = 1;
        goDeep(root);
        return max -1;
    }
};
int main()
{
}