#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    TreeNode *root;

    TreeNode *BinarySearch(int value)
    {
        TreeNode node = *root;

        while (node.val != value)
        {
            if (value > node.val)
            {
                node = *node.right;
            }
            else
            {
                node = *node.left;
            }

            if (&node == NULL)
            {
                break;
            }
        }

        return &node;
    }

    int Underlying(TreeNode *node)
    {
        int sum = 0;

        if (node == NULL)
            return sum;

        sum += node->val;

        sum += Underlying(node->left);
        sum += Underlying(node->right);

        return sum;
    }

    int Solve(TreeNode *node, int L, int R)
    {
        int sum = 0;

        if (node == NULL)
            return 0;

        if (node->val >= L && node->val <= R)
        {
            sum += node->val;
            sum += Solve(node->right, L, R);
            sum += Solve(node->left, L, R);
        }
        else
        {
            if (node->val > R)
            {
                sum += Solve(node->left, L, R);
            }

            if (node->val < L)
            {
                sum += Solve(node->right, L, R);
            }
        }

        return sum;
    }

public:
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        this->root = root;

        return Solve(root, L, R);
    }
};